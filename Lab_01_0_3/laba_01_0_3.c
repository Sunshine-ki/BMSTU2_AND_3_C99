#include <stdio.h> 
#define TRANS_TO_M 100
#define CONSTANT_FOR_THE_FORMULA 240

int main() 
{
    // Инициализация переменных
    double h, t, m;
    double normal_weight, mass_index;

    // Считывание данных из потока ввода
    printf("Введите ваш рост (в см) : ");
    scanf("%lf", &h);
    printf("\nВведите длину окружности грудной клетки (в см): ");
    scanf("%lf", &t);
    printf("\nВведите вес (в кг): ");
    scanf("%lf", &m);

    // Расчёт нормального веса и индекса массы тела
    normal_weight = h * t / CONSTANT_FOR_THE_FORMULA;
    h /= TRANS_TO_M;
    mass_index = m / (h * h);
	
    // Вывод результа
    printf("Нормальный вес: %-12.4lf \nИндекс массы: %-12.4lf", normal_weight, mass_index);
    return 0;
}
