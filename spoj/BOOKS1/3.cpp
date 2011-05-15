#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

long long a[505][505];                // leftmost, rightmost
long long dp[505][505];               // rightmost sectors, scribers
int trace[505][505];
int res[505];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        memset(a, 0, sizeof(a));
        // memset(res, 0, sizeof(res));
        memset(dp, 0, sizeof(dp));
        // memset(trace, 0, sizeof(trace));
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            // cin >> a[i][i];
            scanf("%lld", &a[i][i]);
        for (int i = 1; i < n; ++i) {
            a[0][i] = a[0][i - 1] + a[i][i];
            for (int j = 1; j < i; ++j)
                a[j][i] = a[0][i] - a[0][j - 1];
        }
        // for (int i = 0; i < n; ++i)
        //     for (int j = 1; j <= m; ++j) 
        //         dp[i][j] = LLONG_MAX;
        for (int i = 0; i < n; ++i)
            dp[i][0] = LLONG_MAX;

        for (int i = n - 1; i >= 0; --i)
            for (int j = 1; j <= min(m, n - i); ++j) {
                long long aux = LLONG_MAX;
                for (int k = 1; k <= n - i - j + 1; ++k) {
                    long long tmp = max(dp[i + k][j - 1], a[i][i + k - 1]);
                    if (tmp < aux) {
                        aux = tmp;
                        trace[i][j] = k;
                    }
                }
                dp[i][j] = aux;
            }
        // cout << dp[0][m] << endl;
        int start = 0, idx = m, p = 0;
        while (idx != 1) {
            res[p++] = trace[start][idx];
            start += trace[start][idx];
            --idx;
        }
        res[p++] = n - start;
        #ifdef DEBUG
        print(res, p);
        #endif
        int cnt = 0;
        for (int i = 0; i < p; ++i) {
            if (i) printf(" / ");
            for (int j = 0; j < res[i]; ++j) {
                if (j) printf(" ");
                printf("%lld", a[cnt + j][cnt + j]);
            }
            cnt += res[i];
        }
        cout << endl;
    }
}
