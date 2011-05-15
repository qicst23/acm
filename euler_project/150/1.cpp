#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< LL > VLL;
typedef vector< VLL > VVLL;
typedef vector< double > VD;
typedef vector< string > VS;
typedef istringstream ISS;

#define A(x)  (x).begin(), (x).end()
#define SIZE(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FSZ(i, a, v)  F(i, a, SIZE(v))
#define RSZ(i, v)  R(i, SIZE(v))
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pf push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


int power(int base, int e)
{
    int x = 1;
    R(i, e) x *= base;
    return x;
}

LL minTriangle(const VVLL& vv)
{
    LL result = LLONG_MAX;
    int n = vv.size();

    VVLL p = vv;
    RSZ(i, p) RSZ(j, p[i]) checkmin(result, p[i][j]);

    FE(k, 2, n) {
	RE(i, n-k) {
	    LL x = 0;
	    R(j, k) x += vv[i+k-1][j];
	    p[i][0] += x;
	    checkmin(result, p[i][0]);
	    
	    FSZ(j, 1, p[i]) {
		x = x - vv[i+k-1][j-1] + vv[i+k-1][j+k-1];
		p[i][j] += x;
		checkmin(result, p[i][j]);
	    }
	}
    }

    return result;
}

int main()
{
    LL n = 500500;

    VLL v(n+1);
    //    int arr[1000][1000][1000];
    LL t = 0;
    LL m = power(2, 20);
    LL m2 = power(2, 19);
    FE(i, 1, n) {
	t = (615949*t+797807)%m;
	v[i] = t - m2;
    }
    cout <<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;

    VVLL vv;
    LL sq = sqrt(n*2);
    LL k =1;
    FE(i, 1, sq) {
	VLL tmp(i);
	RSZ(j, tmp) tmp[j] = v[k++];
	vv.pb(tmp);
    }

    // RSZ(i, vv) prLL(vv[i]);
    // cout << vv.size()<<" "<<vv[vv.size()-1].size()<<endl;

    cout << minTriangle(vv)<<endl;
}
