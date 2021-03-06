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

#define ALL(x)  (x).begin(), (x).end()
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
#define UN(a) sort(ALL(a)), a.erase(unique(ALL(a)), a.end())
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


const long MAX = 10000000;
bitset<MAX> prime(0);

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& prime)
{
    prime.reset();
    prime.flip();
    prime[0] = 0;
    prime[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (prime[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		prime[j] = 0;
     	    }
     	}
    }
}

bool isPrime(LL n)
{
    LL sq = sqrt(n);
    if (n == 2) return true;
    FE(i, 2, sq) if (n%i == 0) return false;
    return true;
}

LL vectorToLL(const VI& v)
{
    LL r = 0;
    RSZ(i, v) r = r*10 + v[i];
    return r;
}

int M(int n, int d, LL& result)
{
    VI v(n, d);
    R(i, n) {
	RSZ(j, v) v[j] = d;
	if (i == 0) {
	    FE(j, 1, 9) {
		v[i] = j;
		LL r = vectorToLL(v);
		if (isPrime(r)) {cout <<"*****"<<r<<endl; result+=r;}
	    }
	} else {
	    FE(j, 0, 9) {
		v[i] = j;
		LL r = vectorToLL(v);
		if (isPrime(r)) {cout <<"*****"<<r<<endl; result+=r;}
	    }
	}
    }
    return 0;
}
	
int M2(int n, int d, LL& result)
{
    VI v(n, d);
    R(i, n) {
	RSZ(j, v) v[j] = d;
	if (i == 0) {
	    FE(j, 1, 9) {
		RSZ(x, v) v[x] = d;
		v[i] = j;
		VI t = v;
		F(i2, i+1, n) FE(k, 0, 9) {
		    v = t;
		    v[i2] = k;
		    LL r = vectorToLL(v);
		    if (isPrime(r)&&v[0]!=0) {cout <<"*------------------****"<<r<<endl;print(v); result += r;}
		}
	    }
	} else {
	    FE(j, 0, 9) {
		RSZ(x, v) v[x] = d;
		v[i] = j;
		VI t = v;
		F(i2, i+1, n) FE(k, 0, 9) {
		    v = t;
		    v[i2] = k;
		    LL r = vectorToLL(v);
		    if (isPrime(r)&&v[0]!=0) {cout <<"*****"<<r<<endl;print(v); result += r;}
		}
	    }
	}
    }
    return 0;
}
	

LL S(int n)
{
    LL a = 1;
    while (n > 1) { a *= 10; n--; }
    LL b = a*10;
    cout <<a<<" "<<b<<endl;

    //    for (LL i=a; i<b; i++);

    return 0;
}

int main()
{
    // findPrime(prime);
    //    LL n = 1111111111LL;
    // LL n = 2222222222LL;
    // cout <<M(10, 5)<<endl;
    // cout <<M2(10, 2)<<endl;
    // cout <<M2(10, 8)<<endl;
    // cout << M2(10, 0) << endl;
    
    // M(10, 0) = 8  M(10, 1) = 10
    // M(10, 2) = 8  M(10, 8) = 8
    // M(10, 3-9) = 9

    LL r = 0LL;
    FE(i, 3, 7) M(10, i, r);
    M(10, 1, r);
    M(10, 9, r);
    M2(10, 0, r);
    M2(10, 2, r);
    M2(10, 8, r);
    cout << r<<endl;

    // cout <<"*********"<<endl;
    // LL r = 0;
    // // cout << M2(10, 0, r)<<endl;
    // M2(4, 0, r);
    // FE(i, 1, 9) M(4, i, r);
    // cout << r<<endl;

    // LL r = 0LL;
    // M2(10, 8, r);

}
