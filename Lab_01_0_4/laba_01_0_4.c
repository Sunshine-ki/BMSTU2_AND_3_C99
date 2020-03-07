#include <stdio.h>
#define MAX_BOTTLES 45
#define PENNY 20

int main()
{
    // Инициализация переменных
    double s;
    int sumi = 0;

    // Считывание данных с потока ввода    
    printf("Введите доступную сумму денег: ");
    scanf("%lf", &s);

    // Вычисление количества бутылок
    while (s >= MAX_BOTTLES)
    {
	    sumi += s / MAX_BOTTLES;
	    s = ((int) s / MAX_BOTTLES) * PENNY + (s - ((int) s / MAX_BOTTLES) * MAX_BOTTLES);
    }

    // Вывод
    printf("\nВы можете купить %d бутылок ", sumi);
    return 0;
}
