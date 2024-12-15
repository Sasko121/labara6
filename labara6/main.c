#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функція для обчислення значення підінтегральної функції
double integrand(double x) {
    return 3 * pow(x, 1.0 / 3.0);
}

// Метод трапецій для обчислення інтегралу
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (integrand(a) + integrand(b));
    for (int i = 1; i < n; i++) {
        sum += integrand(a + i * h);
    }
    return h * sum;
}

// Метод парабол (правило Сімпсона)
double parabolic_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = integrand(a) + integrand(b);
    for (int i = 1; i < n; i += 2) {
        sum += 4 * integrand(a + i * h);
    }
    for (int i = 2; i < n; i += 2) {
        sum += 2 * integrand(a + i * h);
    }
    return h / 3 * sum;
}

// Метод прямокутників (ліва і права точка)
double rectangular_rule(double a, double b, int n, int method) {
    double h = (b - a) / n;
    double sum = 0;
    if (method == 0) { // Ліва точка
        for (int i = 0; i < n; i++) {
            sum += integrand(a + i * h);
        }
    }
    else { // Права точка
        for (int i = 1; i <= n; i++) {
            sum += integrand(a + i * h);
        }
    }
    return h * sum;
}

// Метод прямокутників (середня точка)
double midpoint_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += integrand(a + (i + 0.5) * h);
    }
    return h * sum;
}

int main() {
    setlocale(LC_ALL, "RU");
    double a = 0; // Нижня межа
    double b = 8; // Верхня межа
    int n = 1000; // Кількість розбиттів

    // Обчислення інтегралу різними методами
    printf("Метод трапеций: %lf\n", trapezoidal_rule(a, b, n));
    printf("Метод Симпсона: %lf\n", parabolic_rule(a, b, n));
    printf("Метод прямоугольников (левая точка): %lf\n", rectangular_rule(a, b, n, 0));
    printf("Метод прямоугольников (правая точка): %lf\n", rectangular_rule(a, b, n, 1));
    printf("Метод прямоугольников (средняя точка): %lf\n", midpoint_rule(a, b, n));

    return 0;
}
