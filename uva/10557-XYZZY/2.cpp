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
typedef pair< int, int > II;
typedef vector< II > VII;
typedef vector< VII > VVII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define A(x)  (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define RD(i, n) FD(i, n, 0)
#define FSZ(i, a, v)  F(i, a, SZ(v))
#define RSZ(i, v)  R(i, SZ(v))
#define FDSZ(i, a, v) FD(i, SZ(v)-1, a)
#define RDSZ(i, v) RD(i, SZ(v)-1)
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  FA(i, (x).begin(), x)
#define FDA(i, a, x)  for (__typeof((x).rbegin()) i=(x).rbegin(); i!=(a); ++i)
#define RDA(i, x)  FDA(i, (x).rend(), x)
#define P(v, x) (v.find(x) != v.end())
#define PO(v, x) (find(A(v), x) != v.end())
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define MP(a, b)  make_pair(a, b)
#define CAST(x, type) *({ OSS oss; oss << (x); ISS iss(oss.str()); static type _cast_ret; iss >> _cast_ret; &_cast_ret; })
#define pb push_back
#define pf push_front
#define X first
#define Y second

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> inline void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> inline void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


II cyclic(const vector< set<int> >&g, int x, const VI& energy)
{
    VI visited(SZ(g));
    queue<II> q;
    q.push(MP(x, energy[x]));
    while (!q.empty()) {
	II a = q.front();
	q.pop();
	if (!visited[a.X]) {
	    visited[a.X] = 1;
	    RA(i, g[a.X]) {
		if (*i == x) return MP(a.X, a.Y);
		q.push(MP(*i, a.Y+energy[*i]));
	    }
	}
    }
    return MP(-1, 0);
}

void delete_edge(vector< set<int> >&g, int a, int b)
{
    g[a].erase(g[a].find(b));
}

void powerfull(const vector< set<int> >& g, int x, VI& energy)
{
    VI visited(SZ(g));
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
	int a = q.front();
	q.pop();
	if (!visited[a]) {
	    visited[a] = 1;
	    energy[a] = INT_MAX;
	    RA(i, g[a]) q.push(*i);
	}
    }
}

bool adventure_game(vector< set<int> >& g, VI& energy)
{
    // print(energy);
    int n = SZ(g);
    R(i, n) {
	bool flag = true;
	while (flag) {
	    flag = false;
	    II c = cyclic(g, i, energy);
	    int back = c.X;
	    if (back != -1) {
		flag = true;
		delete_edge(g, back, i);
		if (c.Y > 0) powerfull(g, i, energy);
	    }
	}
    }

    // RSZ(i, g) { cout <<i<<" : "; print(g[i]);}

    VLL hp(n, INT_MIN);
    VI visited(n);
    queue< pair<int, LL> > q;
    q.push(MP(0, 100));

    while (!q.empty()) {
	pair<int, LL> x = q.front();
	q.pop();
	int a = x.X;
	LL b = x.Y;
	// cout << a << " " << b << endl;
	if (a == n-1 && b > 0) return true;
	if (!visited[a] || hp[a] < b) {
	    visited[a] = 1;
	    hp[a] = b;
	    RA(i, g[a]) q.push(MP(*i, b+energy[*i]));
	}
    }

    return false;
}

int main()
{
    int n;
    while (cin >> n) {
	if (n == -1) break;
	vector< set<int> > g(n);
	VI energy(n);
	R(i, n) {
	    cin >> energy[i];
	    int m;
	    cin >> m;
	    R(j, m) { int x; cin >> x; x--; g[i].insert(x); }
	}
	bool ret = adventure_game(g, energy);
	if (ret) cout << "winnable" << endl;
	else cout << "hopeless" << endl;
    }
}
