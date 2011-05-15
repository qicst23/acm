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

class IOIString
{ 
public: 
  int countIOIs(vector <string> mask);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"IO?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countIOIs(Arg0)); }
	void test_case_1() { string Arr0[] = {"????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, countIOIs(Arg0)); }
	void test_case_2() { string Arr0[] = {"?II"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countIOIs(Arg0)); }
	void test_case_3() { string Arr0[] = {"I??O??I"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, countIOIs(Arg0)); }
	void test_case_4() { string Arr0[] = {"???I???????O???","???????????O??IO????????I???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 438952513; verify_case(4, Arg1, countIOIs(Arg0)); }

// END CUT HERE
 
}; 
// BEGIN CUT HERE 
////////////////////////////////////////////////////////////////////////////////
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
  IOIString ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

int IOIString :: countIOIs(vector <string> mask)
{
  string s=accumulate((mask).begin(), (mask).end(), string());
  int cnt=0;
  for (int i=0; i<(int)(s).size(); ++i) if (s[i]=='?') cnt++;
  int k=INT_MAX;
  for (int i=0; i<(int)(s).size(); ++i)
    for (int len=1; i+2*len<(int)(s).size(); ++len) {
      if (s[i]=='I' && s[i+len]=='O' && s[i+2*len]=='I') k=0;

      if (s[i]=='I' && s[i+len]=='O' && s[i+2*len]=='?') k=min(k, 1);
      if (s[i]=='I' && s[i+len]=='?' && s[i+2*len]=='I') k=min(k, 1);
      if (s[i]=='?' && s[i+len]=='O' && s[i+2*len]=='I') k=min(k, 1);

      if (s[i]=='I' && s[i+len]=='?' && s[i+2*len]=='?') k=min(k, 2);
      if (s[i]=='?' && s[i+len]=='O' && s[i+2*len]=='?') k=min(k, 2);
      if (s[i]=='?' && s[i+len]=='?' && s[i+2*len]=='I') k=min(k, 2);

      if (s[i]=='?' && s[i+len]=='?' && s[i+2*len]=='?') k=min(k, 3);
    }
  if (k==INT_MAX) return 0;
  cnt-=k;
  int res=1;
  for (int i=0; i<cnt; ++i) res*=2, res%=1000000007;
  return res;
}
