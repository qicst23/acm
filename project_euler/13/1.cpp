#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string addString(string a, string b)
{
    string result;

    int ai = a.length() - 1;
    int bi = b.length() - 1;

    int carry = 0;
    while ((ai >= 0) || (bi >= 0)) {
	int x = 0;
	int y = 0;
	int z = 0;

	if (ai >= 0) {
	    x = a[ai] - '0';
	}
	if (bi >= 0) {
	    y = b[bi] - '0';
	}
	z = x + y + carry;

	carry = z / 10;
	int m = z % 10;

	result = (char)(m+'0') + result;

	if (ai >= 0) ai--;
	if (bi >= 0) bi--;
    }

    if (carry > 0) {
	result = (char)(carry+'0') + result;
    }

    return result;
}

int main()
{
    string t1 = "923";
    //string t1;
    string t2 = "223";

    cout << addString(t1, t2) << endl;

    string a;
    string b;
    while (cin >> b) {
	a = addString(a, b);
    }

    cout << a << endl;
}
