#include <iostream>
using namespace std;
extern "C" int procedure(int);

int main() {

	int a;
	cout << "Enter a: ";
	cin >> a;

	cout << "Result by assembler : " << procedure(a) << '\n';
	cout << "Result by c++ : " << a^12 + a^8 + a << '\n';

}
