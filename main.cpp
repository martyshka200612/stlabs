// Lab 2 Variant 10

// *a указатель на переменную



#include <iostream>
#include <math.h>

using namespace std;
int main() {
    int n;
    setlocale(LC_ALL, "Rus");
    cout << " Input n: ";
    cin >> n;
    int *a = new int[n]; // создать в массиве n чисел
    for (int i = 0; i < n; i++) {
        cout << "A [" << i + 1 << "]=";// ввод A[1],A[2],...,A[N] с клавиатуры
        cin >> a[i];
    }
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > a[max]) max = i;
        if (a[i] < a[min]) min = i;
    }
    int tmp = a[max];//поменять местами мин и макс
    a[max] = a[min];
    a[min] = tmp;
    for (int i = 0; i < n; i++)// выводит в консоль измененный порядок элементов
    {
        cout << a[i] << " ";
    }

    double mod_min = a[0]; // минимальный модуль
    int index = 0; // индекс минимального модуля

    for (int i = 1; i < n; i++) {
        if (mod_min > abs(a[i])) { //функция возвращает модуль
            mod_min = a[i];
            index = i;
        }
    }

    double mod_sum = 0;// сумма модулей
    for (int i = index + 1; i < n; i++) {
        mod_sum += abs(a[i]);
    }

    printf("Сумма модулей элементов, расположенных после \nминимального по модулю элемента: %lg\n", mod_sum);
    //замена элементов их квадратами
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            a[i] *= a[i];  //возведение в квадрат отрицательных значений
        }
    }
    //сортировка
    double tem;
    printf("Отсортированный массив:\n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                tem = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tem;
            }
        }
    }
    for (int i = 0; i < n; i++)
    { cout<<a[i]<<" ";
        cout<<endl;}

    return 0;
}


