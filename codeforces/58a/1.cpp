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
////////////////////////////////////////////////////////////////////////////////


int main()
{
  string s;
  cin>>s;
  string a="hello";
  int cur=-1;
  for (int i=0; i<(int)(a).size(); ++i) {
    cur=s.find(a[i], cur+1);
    if (cur==-1) { cout<<"NO"<<endl; return 0; }
  }
  cout<<"YES"<<endl;
}
