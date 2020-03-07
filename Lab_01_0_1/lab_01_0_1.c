#include <stdio.h> 
#include <math.h>

int main() 
{ 
    // Инициальзация переменных 
    double h, a, b; 
    double c, temp;
    double p;


    // Считывание данных из потока ввода
    printf("Введите основания и высоту равнобедренной трапеции: "); 
    scanf("%lf %lf %lf", &a, &b, &h);

    // Расчёт периметра равнобедренной трапеции
    temp = fabs((a - b) * 0.5);
    c = sqrt(temp * temp + h * h);
    p = a + b + 2 * c; 

    // Вывод площади 
    printf("\nПериметр равнобедренной трапеции = %-12.4lf", p); 
    return 0;
}
