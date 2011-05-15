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
    int ix = v3[i];
    int jx = v4[j];
    int kx = v5[k];
    int ax = v6[a];
    int bx = v7[b];
    int cx = v8[c];

    if (ix==0 || jx==0 || kx==0 ||
	ax==0 || bx==0 || cx==0) {
	return false;
    }

    set<int> s;
    s.insert(ix);
    s.insert(jx);
    s.insert(kx);
    s.insert(ax);
    s.insert(bx);
    s.insert(cx);

    if (s.size() == 6) {
	return true;
    } else {
	return false;
    }
}

bool check2(int i, int j, int k,
	   const vector<int>& v3, const vector<int>& v4, 
	    const vector<int>& v5)
{
    vector<int> v(6);
    v[0] = i;
    v[1] = j;
    v[2] = k;

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
		return true;
	    }
	}
    }
    return false;
}


void findNumber()
{
    vector<int> v3(10000);
    vector<int> v4(10000);
    vector<int> v5(10000);
    vector<int> v6(10000);
    vector<int> v7(10000);
    vector<int> v8(10000);

    for (int i=1000; i<10000; i++) {
	v3[i] = test3(i);
	// if (v3[i]>0) cout << "***"<<i<<"  :  "<<v3[i]<<endl;
	v4[i] = test4(i);
	//if (v4[i]>0) cout << "***"<<i<<"  :  "<<v4[i]<<endl;
	v5[i] = test5(i);
	v6[i] = test6(i);
	v7[i] = test7(i);
	v8[i] = test8(i);
    }
    cout <<"*((*"<<endl;
    for (int i=1000; i<10000; i++) {
	// if (v3[i] == 0) {
	//     continue;
	// }
	//	 cout << "*"<<i<<"  :  "<<v3[i]<<endl;
	for (int j=(i%100)*100; j>=1000 && j<(i%100+1)*100; j++) {
	    //  cout << "**"<<j<<"  :  "<<v4[j]<<endl;
	    // if (v4[j] == 0) {
	    // 	continue;
	    // }
	    //  cout << "**"<<j<<"  :  "<<v4[j]<<endl;
	    for (int k=(j%100)*100; k>=1000 && k<(j%100+1)*100; k++) {
		// if (v5[k] == 0) {
		//     continue;
		// }
		if (k%100 != i/100) {
		     continue;
		 }
		// for (int a=(k%100)*100; a>=1000 && a<(k%100+1)*100; a++) {
		//     if (v6[a] == 0) {
		// 	continue;
		//     }
		//     for (int b=(a%100)*100; b>=1000 && b<(a%100+1)*100; b++) {
		// 	if (v7[b] == 0) {
		// 	    continue;
		// 	}
		// 	for (int c=(b%100)*100; c>=1000 && c<(b%100+1)*100; c++) {
		// 	    if (v8[c] == 0) {
		// 		continue;
		// 	    }

		// 	    set<int> s;
		// 	    s.insert(v3[i]);
		// 	    s.insert(v4[j]);
		// 	    s.insert(v5[k]);
		// 	    s.insert(v6[a]);
		// 	    s.insert(v7[b]);
		// 	    s.insert(v8[c]);
			    
		// 	    if (s.size() == 6) {
		// 	    cout <<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<c<<endl;
		// 		cout << i+j+k+a+b+c << endl;

		// 	    }
		// 	}
		//     }
		//		cout <<"////////////"<<endl;
		if (check2(i,j,k,v3,v4,v5) == true) {
		    cout << i<<" "<<j<<" "<<k<<endl;

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
