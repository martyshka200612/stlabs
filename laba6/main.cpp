#include "class.h"

using namespace std;
int main()
{
    int x, y;
    cout << " Input x: " << endl;
    cin >> x;
    cout << " Input y: " << endl;
    cin >> y;
    ProperFraction a(x, y);

    int v, w;
    cout << " Input v: " << endl;
    cin >> v;
    cout << " Input w: " << endl;
    cin >> w;
    ProperFraction b(v, w);

    cout << "Fraction 1: ";
    a.print();
    cout << endl;

    cout << "Fraction 2: ";
    b.print();
    cout << endl;

    ProperFraction sum = a + b;
    ProperFraction product = a * b;
    ProperFraction quotient = a / b;


    cout << "a + b = ";
    sum.print();
    cout << endl;

    cout << "a * b = ";
    product.print();
    cout << endl;

    cout << "a / b = ";
    quotient.print();
    cout << endl;

    return 0;
}
