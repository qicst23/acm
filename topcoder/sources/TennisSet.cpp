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

class TennisSet
{ 
public: 
  string firstSet(vector <string> points);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSSSSSSSSSSSSSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2-1"; verify_case(0, Arg1, firstSet(Arg0)); }
	void test_case_1() { string Arr0[] = {"SS","SRSS","RRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2-0"; verify_case(1, Arg1, firstSet(Arg0)); }
	void test_case_2() { string Arr0[] = {"SSSSRRRRSSSSRR","RRSSSSRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR","R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "6-0"; verify_case(2, Arg1, firstSet(Arg0)); }

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
  TennisSet ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 

string TennisSet :: firstSet(vector <string> points)
{
  vector<int> v(2);
  int k=0;
  string s;
  for (int i=0; i<(int)(points).size(); ++i) s+=points[i];
  int p=0, q=0;
  for (int i=0; i<(int)(s).size(); ++i) {
    if (s[i]=='S') {
      p++;
      if (p>=4 && p-q>=2) {
	v[k]++;
	p=0;
	q=0;
	k=1-k;
      }
    } else {
      q++;
      if (q>=4 && q-p>=2) {
	v[1-k]++;
	p=0;
	q=0;
	k=1-k;
      }
    }
    if ((v[0]>=6 && v[0]-v[1]>=2) || (v[1]>=6 && v[1]-v[0]>=2)) break;
  }
  string res=*({stringstream ss; ss<<(v[0]); static string _; ss>>_; &_;})+"-"+*({stringstream ss; ss<<(v[1]); static string _; ss>>_; &_;});
  return res;
}
