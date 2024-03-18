#include <iostream>
using namespace std;
extern "C" int procedure1(int);

int main() {

	int x;
	cout << "Enter x: ";
	cin >> x;

	cout << "Result by assembler : " << procedure1(x) << '\n';
	cout << "Result by c++ : " << (x^5 + 2 * (x^2 - 4) + x) / (x^3) << '\n';

}
