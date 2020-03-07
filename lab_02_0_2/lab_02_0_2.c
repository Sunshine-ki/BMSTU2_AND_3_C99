#include <stdio.h>
#include <math.h>
#define ERROR 1
#define ACUTE_ANGLE 0
#define RECTANGULAR 1
#define OBTUSE 2
#define OK 0

int error(int rc, double x1, double y1, double x2, double y2, double x3, double y3)
{
    if ((rc < 6) || ((x3 - x1) * (y3 - y2) == (x3 - x2) * (y3 - y1)))
        return ERROR;
    else 
        return OK;
}


int triangle(double a, double b, double c)
{
    if (a == sqrt(b * b + c * c) || 
        b == sqrt(a * a + c * c) || 
        c == sqrt(a * a + b * b))
        return RECTANGULAR;
    else if ((a * a > b * b + c * c) || 
        (b * b > a * a + c * c) || 
        (c * c > a * a + b * b))
        return OBTUSE;
    else 
        return ACUTE_ANGLE;
}

int main()
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
    double a, b, c;
    
    int rc;

    printf("Введите координаты вершин: ");
    rc = scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    if (error(rc, x1, y1, x2, y2, x3, y3))
        return ERROR;
    else
    {
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        printf("%d", triangle(a, b, c));
    }

    return OK;
}
