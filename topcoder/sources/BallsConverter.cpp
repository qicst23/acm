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

class BallsConverter
{ 
public: 
  string theGood(vector <string> convert);
  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AB", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Good"; verify_case(0, Arg1, theGood(Arg0)); }
	void test_case_1() { string Arr0[] = {"BA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bad"; verify_case(1, Arg1, theGood(Arg0)); }
	void test_case_2() { string Arr0[] = {"ACB", "CBA", "BAC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bad"; verify_case(2, Arg1, theGood(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAAA", "ABBB", "ABCC", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Good"; verify_case(3, Arg1, theGood(Arg0)); }
	void test_case_4() { string Arr0[] = {"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA",
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcd",
"ACEGIKMOQSUWYacACEGIKMOQSUWYac",
"ADGJMPSVYbADGJMPSVYbADGJMPSVYb",
"AEIMQUYcCGKOSWaAEIMQUYcCGKOSWa",
"AFKPUZAFKPUZAFKPUZAFKPUZAFKPUZ",
"AGMSYAGMSYAGMSYAGMSYAGMSYAGMSY",
"AHOVcFMTaDKRYBIPWdGNUbELSZCJQX",
"AIQYCKSaEMUcGOWAIQYCKSaEMUcGOW",
"AJSbGPYDMVAJSbGPYDMVAJSbGPYDMV",
"AKUAKUAKUAKUAKUAKUAKUAKUAKUAKU",
"ALWDOZGRcJUBMXEPaHSdKVCNYFQbIT",
"AMYGSAMYGSAMYGSAMYGSAMYGSAMYGS",
"ANaJWFSBObKXGTCPcLYHUDQdMZIVER",
"AOcMaKYIWGUESCQAOcMaKYIWGUESCQ",
"APAPAPAPAPAPAPAPAPAPAPAPAPAPAP",
"AQCSEUGWIYKaMcOAQCSEUGWIYKaMcO",
"AREVIZMdQDUHYLcPCTGXKbOBSFWJaN",
"ASGYMASGYMASGYMASGYMASGYMASGYM",
"ATIbQFYNCVKdSHaPEXMBUJcRGZODWL",
"AUKAUKAUKAUKAUKAUKAUKAUKAUKAUK",
"AVMDYPGbSJAVMDYPGbSJAVMDYPGbSJ",
"AWOGcUMEaSKCYQIAWOGcUMEaSKCYQI",
"AXQJCZSLEbUNGdWPIBYRKDaTMFcVOH",
"AYSMGAYSMGAYSMGAYSMGAYSMGAYSMG",
"AZUPKFAZUPKFAZUPKFAZUPKFAZUPKF",
"AaWSOKGCcYUQMIEAaWSOKGCcYUQMIE",
"AbYVSPMJGDAbYVSPMJGDAbYVSPMJGD",
"AcaYWUSQOMKIGECAcaYWUSQOMKIGEC",
"AdcbaZYXWVUTSRQPONMLKJIHGFEDCB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Good"; verify_case(4, Arg1, theGood(Arg0)); }
	void test_case_5() { string Arr0[] = {"AAAAAFAAAAAAAAAAAAAAAAAXAAAAcAAAAAAAAAAnAAAAAAAvAA",
"ABBBBFBBBBBLBBBBQBBBBBBXYBBBcBBBBBBBBBBnBBBBBBBvwB",
"ABCCCFCCCCCLMCOCQRCCCCCXYCCCcCCCCCCCCCCnCCCCsCCvwC",
"ABCDEFGHDDDLMDODQRSDUVWXYDDbcdDfghDDklDnopDrsDDvwx",
"ABCEEFEEEEELMEOEQRSEUVWXYEEbcEEfEhEEklEnEpEEsEEvwE",
"FFFFFFFFFFFFFFFFFFFFFFFXFFFFcFFFFFFFFFFFFFFFFFFvFF",
"ABCGEFGGGGGLMGOGQRSGUVWXYGGbcGGfGhGGklGnGpGGsGGvwG",
"ABCHEFGHHHHLMHOHQRSHUVWXYHHbcdHfHhHHklHnHpHHsHHvwH",
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx",
"ABCDEFGHJJJLMJOJQRSJUVWXYJJbcdJfghJJklJnopJrsJJvwx",
"ABCDEFGHKJKLMNOPQRSTUVWXYZKbcdefghijklmnopqrsKKvwx",
"ALLLLFLLLLLLLLLLLLLLLLLXLLLLcLLLLLLLLLLnLLLLLLLvwL",
"ABMMMFMMMMMLMMOMQMMMMMMXYMMMcMMMMMMMMMMnMMMMMMMvwM",
"ABCDEFGHNJNLMNOPQRSTUVWXYZNbcdefghijklmnopqrsNNvwx",
"ABOOOFOOOOOLOOOOQOOOOOOXYOOOcOOOOOOOOOOnOOOOOOOvwO",
"ABCDEFGHPJPLMPOPQRSTUVWXYZPbcdPfghiPklmnopPrsPPvwx",
"AQQQQFQQQQQLQQQQQQQQQQQXQQQQcQQQQQQQQQQnQQQQQQQvwQ",
"ABRRRFRRRRRLMRORQRRRRRRXYRRRcRRRRRRRRRRnRRRRRRRvwR",
"ABCSSFSSSSSLMSOSQRSSSSSXYSSScSSSSSSSSSSnSSSSsSSvwS",
"ABCDEFGHTJTLMTOTQRSTUVWXYTTbcdTfghiTklTnopTrsTTvwx",
"ABCUUFUUUUULMUOUQRSUUUWXYUUUcUUUUhUUklUnUUUUsUUvwU",
"ABCVVFVVVVVLMVOVQRSVUVWXYVVbcVVfVhVVklVnVVVVsVVvwV",
"ABCWWFWWWWWLMWOWQRSWWWWXYWWWcWWWWhWWkWWnWWWWsWWvwW",
"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXvXX",
"AYYYYFYYYYYLYYYYQYYYYYYXYYYYcYYYYYYYYYYnYYYYYYYvwY",
"ABCDEFGHZJZLMZOZQRSTUVWXYZZbcdZfghiZklZnopZrsZZvwx",
"ABCDEFGHaJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwx",
"ABCbbFbbbbbLMbObQRSbUbWXYbbbcbbfbhbbklbnbbbbsbbvwb",
"cccccccccccccccccccccccXcccccccccccccccccccccccvcc",
"ABCdEFGddddLMdOdQRSdUVWXYddbcddfdhddkldndpddsddvwd",
"ABCDEFGHeJeLMeOPQRSTUVWXYZebcdefghijklmnoperseevwx",
"ABCffFfffffLMfOfQRSfUfWXYfffcffffhffklfnffffsffvwf",
"ABCgEFGHgggLMgOgQRSgUVWXYggbcdgfghggklgngpggsggvwg",
"ABChhFhhhhhLMhOhQRShhhhXYhhhchhhhhhhkhhnhhhhshhvwh",
"ABCDEFGHiJiLMiOiQRSiUVWXYiibcdifghiiklinopirsiivwx",
"ABCDEFGHjJjLMjOPQRSTUVWXYZjbcdjfghijklmnopjrsjjvwx",
"ABCkkFkkkkkLMkOkQRSkkkkXYkkkckkkkkkkkkknkkkkskkvwk",
"ABCllFlllllLMlOlQRSlllWXYlllcllllhllkllnllllsllvwl",
"ABCDEFGHmJmLMmOmQRSTUVWXYZmbcdmfghimklmnopmrsmmvwx",
"nnnnnFnnnnnnnnnnnnnnnnnXnnnncnnnnnnnnnnnnnnnnnnvnn",
"ABCoEFGHoooLMoOoQRSoUVWXYoobcdofghooklonoporsoovwx",
"ABCppFpppppLMpOpQRSpUVWXYppbcppfphppklpnpppSsppvwp",
"ABCDEFGHqJqLMqOPQRSTUVWXYZqbcdefghijklmnopqrsqqvwx",
"ABCrEFGHrrrLMrOrQRSrUVWXYrrbcdrfghrrklrnrSrrsrrvwx",
"ABsssFsssssLMsOsQRsssssXYssscssssssssssnsssssssvws",
"ABCDEFGHtJKLMNOPQRSTUVWXYZtbcdefghijklmnopqrsttvwx",
"ABCDEFGHuJKLMNOPQRSTUVWXYZubcdefghijklmnopqrstuvwx",
"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
"AwwwwFwwwwwwwwwwwwwwwwwXwwwwcwwwwwwwwwwnwwwwwwwvww",
"ABCxEFGHxxxLMxOxQRSxUVWXYxxbcdxfghxxklxnxpxxsxxvwx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bad"; verify_case(5, Arg1, theGood(Arg0)); }

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
  BallsConverter ___test; 
  ___test.run_test(-1); 
} 
////////////////////////////////////////////////////////////////////////////////
// END CUT HERE 


string BallsConverter :: theGood(vector <string> convert)
{
  int n=(int)(convert).size();
  vector<vector<int> > a(n, vector<int>(n));
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      if (isupper(convert[i][j])) a[i][j]=convert[i][j]-'A';
      else a[i][j]=convert[i][j]-'a'+26;
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      for (int k=0; k<n; ++k) {
	if (a[i][a[j][k]]!=a[a[i][j]][k]) return "Bad";
      }
  return "Good";
	
}
