//Lab 1 Var 10
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double x;
    int k;
    int i=0;
    std::cin >> x;
    std::cin >> k;
    double s = sin (x) / x, st = 1;
    std::cout << setprecision(k + 1) << s << std::endl;
    double a = 1;


        while (int(s* pow(10,k)) != int(st* pow(10,k))) {
            a *= (-1) * pow(x,2)/(2*i + 3)/(2*i+2);
            i++;
            st = st +  a;
            std::cout << setprecision(k + 1) << st << endl;
        }

    }


