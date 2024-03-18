#include <iostream>
using namespace std;
extern "C" int procedure(int);

int main() {

	int x;
	cout << "Enter x: ";
	cin >> x;

	cout << "Result by assembler : " << procedure(x) << '\n';
	cout << "Result by c++ : " << (x^5 + 2 * (x^2 - 4) + x) / (x^3) << '\n';

}
