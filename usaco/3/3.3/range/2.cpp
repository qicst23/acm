/*
  ID:   aphrodi1
  LANG: C++
  PROG: range
*/

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
#include "/home/Aphrodite/program/acm/topcoder/libs/debug.cpp"
#endif

ifstream fin("range.in");
ofstream fout("range.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; ++i)
        cin >> g[i];
    vector<vector<pair<int, int> > > v(n + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j] == '1')
                v[1].push_back(make_pair(i, j));
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < (int)(v[len - 1]).size(); ++i) {
            int x = v[len - 1][i].first, y = v[len - 1][i].second;
            if (x + len <= n && y + len <= n) {
                bool ok = true;
                for (int j = 0; j < len; ++j)
                    if (g[x + j][y + len - 1] == '0' ||
                        g[x + len - 1][y + j] == '0') {
                        ok = false;
                        break;
                    }
                if (ok) v[len].push_back(make_pair(x, y));
            }
        }
    }
    for (int len = 2; len <= n; ++len)
        if ((int)(v[len]).size() > 0) {
            cout << len << " " << (int)(v[len]).size() << endl;
        } else {
            break;
        }
}
