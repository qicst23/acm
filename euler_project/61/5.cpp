#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;

int test3(int n)
{
    n *= 8;

    n++;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq--;

    if (sq%2 != 0) {
	return 0;
    }

    int result = sq/2;
    return result;
}

int test4(int n)
{
    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    } else {
	return sq;
    }
}

int test5(int n)
{
    n *= 24;
    n++;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq++;

    if (sq%6 != 0) {
	return 0;
    }

    int result = sq / 6;
    return result;
}

int test6(int n)
{
    n *= 8;
    n++;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq++;

    if (sq%4 != 0) {
	return 0;
    }
    
    int result = sq / 4;
    return result;
}

int test7(int n)
{
    n *= 40;
    n += 9;
    
    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq += 3;

    if (sq%10 != 0) {
	return 0;
    }

    int result = sq / 10;
    return result;
}

int test8(int n)
{
    n *= 12;
    n += 4;

    int sq = sqrt(n);
    if (sq*sq != n) {
	return 0;
    }

    sq += 2;

    if (sq%6 != 0) {
	return 0;
    }

    int result = sq / 6;
    return result;
}

bool check(int i, int j, int k, int a, int b, int c,
	   const vector<int>& v3, const vector<int>& v4, 
	   const vector<int>& v5, const vector<int>& v6,
	   const vector<int>& v7, const vector<int>& v8)
{
    // cout <<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
    vector<int> v(6);
    v[0] = i;
    v[1] = j;
    v[2] = k;
    v[3] = a;
    v[4] = b;
    v[5] = c;

    for (int x1=0; x1<v.size(); x1++) {
	if (v3[v[x1]] == 0) {
	    continue;
	}
	for (int x2=0; x2<v.size(); x2++) {
	    if (v4[v[x2]] == 0) {
		continue;
	    }
	    if (x2 == x1) {
		continue;
	    }
	    for (int x3=0; x3<v.size(); x3++) {
		if (v5[v[x3]] == 0) {
		    continue;
		}
		if ((x3 == x1) || (x3 == x2)) {
		    continue;
		}
		for (int x4=0; x4<v.size(); x4++) {
		    if (v6[v[x4]] == 0) {
			continue;
		    }
		    if (x4==x1 || x4==x2 || x4== x3) {
			continue;
		    }
		    for (int x5=0; x5<v.size(); x5++) {
			if (v7[v[x5]] == 0) {
			    continue;
			}
			if (x5==x1 || x5==x2 || x5==x3 || x5==x4) {
			    continue;
			}
			for (int x6=0; x6<v.size(); x6++) {
			    if (v8[v[x6]] == 0) {
				continue;
			    }
			    if (x6==x1 || x6==x2 || x6==x3 || x6==x4 || x6==x5) {
				continue;
			    }
			    return true;
			}
		    }
		}
	    }
	}
    }
    return false;

}

void findNumber()
{
    map< set<int>, int> mp;

    vector<int> v3(10000);
    vector<int> v4(10000);
    vector<int> v5(10000);
    vector<int> v6(10000);
    vector<int> v7(10000);
    vector<int> v8(10000);

    for (int i=1000; i<10000; i++) {
	v3[i] = test3(i);
	v4[i] = test4(i);
	v5[i] = test5(i);
	v6[i] = test6(i);
	v7[i] = test7(i);
	v8[i] = test8(i);
    }
    cout <<"*((*"<<endl;
    for (int i=10; i<100; i++) {
	for (int j=10; j<100; j++) {
	    if (v3[i*100+j] == 0 && v4[i*100+j] == 0 &&
		v5[i*100+j] == 0 && v6[i*100+j] == 0 &&
		v7[i*100+j] == 0 && v8[i*100+j] == 0) {
		continue;
	    }
	    for (int k=10; k<100; k++) {
		if (v3[j*100+k] == 0 && v4[j*100+k] == 0 &&
		    v5[j*100+k] == 0 && v6[j*100+k] == 0 &&
		    v7[j*100+k] == 0 && v8[j*100+k] == 0) {
		    continue;
		}
		for (int a=10; a<100; a++) {
		    if (v3[k*100+a] == 0 && v4[k*100+a] == 0 &&
			v5[k*100+a] == 0 && v6[k*100+a] == 0 &&
			v7[k*100+a] == 0 && v8[k*100+a] == 0) {
			continue;
		    }
		    for (int b=10; b<100; b++) {
			if (v3[a*100+b] == 0 && v4[a*100+b] == 0 &&
			    v5[a*100+b] == 0 && v6[a*100+b] == 0 &&
			    v7[a*100+b] == 0 && v8[a*100+b] == 0) {
			    continue;
			}
			for (int c=10; c<100; c++) {
			    if (v3[b*100+c] == 0 && v4[b*100+c] == 0 &&
				v5[b*100+c] == 0 && v6[b*100+c] == 0 &&
				v7[b*100+c] == 0 && v8[b*100+c] == 0) {
				continue;
			    }
			    if (v3[c*100+a] == 0 && v4[c*100+a] == 0 &&
				v5[c*100+a] == 0 && v6[c*100+a] == 0 &&
				v7[c*100+a] == 0 && v8[c*100+a] == 0) {
				continue;
			    }
			    if (check(i*100+j,j*100+k,k*100+a,a*100+b,b*100+c,c*100+i,v3,v4,v5,v6,v7,v8)) {
				cout <<i*100+j<<" "<<j*100+k<<" "<<k*100+a<<" "<<a*100+b<<" "<<b*100+c<<" "<<c*100+i<<endl;
				cout << (i*100+j)+(j*100+k)+(k*100+a)+(a*100+b)+(b*100+c)+(c*100+i) << endl;
				return;
			    }
			}
		    }
		}
	    }
	}
    }
}
	    

int main()
{
    cout << test3(4465) << endl;
    cout << test3(5565) << endl;
    cout << test3(8128) << endl;
    cout << test4(8281) << endl;
    cout << test5(2882) << endl;

    findNumber();

}
