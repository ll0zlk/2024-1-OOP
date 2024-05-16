#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin a >> b >> c;

	if (a > b) {
		int temp = a;
		a = b;
		b = a;
	}
	if (b > c) {
		int temp = b;
		b = c;
		c = temp;
	}
	if (a > b) {
		int temp = a;
		a = b;
		b = a;
	}

	cout << a << b << c << endl;
	return 0;
}