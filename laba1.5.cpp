#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double x = 0.8;
    int i = 0;
    int sign =1;
    int p;
    double lg;
    std::cin >> p;
    if (x > (-1) & x <= 1) {
        lg = log(1.0 + x);
        std::cout << std::setprecision(p+1 ) << lg << std::endl;
    }
    int n = 1;
    double u = 0;
    while (int(lg * pow(10, p)) != int(u * pow(10, p))) {
        i++;
        double w = pow(x, n) / n;
        u = u + sign*w;
        sign = -sign;
        n += 1;
    }
    std::cout << std::setprecision(p + 1) << u << std::endl;
return 0;
}