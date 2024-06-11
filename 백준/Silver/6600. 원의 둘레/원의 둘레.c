#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846264338327950288

int main() {
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        double a = pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
        double b = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
        double c = pow(pow(x1 - x3, 2) + pow(y1 - y3, 2), 0.5);
        double k = fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        double r = a * b * c / (2 * k);
        printf("%0.2lf\n", r * 2 * M_PI);
    }
}