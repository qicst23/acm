/*
  ID:   aphrodi1
  LANG: C++
  PROG: prefix
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

ifstream fin("prefix.in");
ofstream fout("prefix.out");
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

    vector<string> v;
    string s;
    while (cin >> s && s != ".")
        v.push_back(s);
    string tmp;
    s.clear();
    while (cin >> tmp)
        s += tmp;
    vector<int> dp((int)(s).size() + 1);
    dp[0] = 1;
    for (int i = 0; i < (int)(dp).size(); ++i) {
        if (dp[i]) {
            for (int j = 0; j < (int)(v).size(); ++j) {
                int m = (int)(v[j]).size();
                if (i + m < (int)(dp).size() && v[j] == s.substr(i, m))
                    dp[i + m] = 1;
            }
        }
    }
    int res = 0;
    for (int i = (int)(dp).size() - 1; i >= 0; --i)
        if (dp[i]) {
            res = i;
            break;
        }
    cout << res << endl;
}
