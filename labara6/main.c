#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

// ������� ��� ���������� �������� ������������ �������
double integrand(double x) {
    return 3 * pow(x, 1.0 / 3.0);
}

// ����� �������� ��� ���������� ���������
double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (integrand(a) + integrand(b));
    for (int i = 1; i < n; i++) {
        sum += integrand(a + i * h);
    }
    return h * sum;
}

// ����� ������� (������� ѳ������)
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

// ����� ������������ (��� � ����� �����)
double rectangular_rule(double a, double b, int n, int method) {
    double h = (b - a) / n;
    double sum = 0;
    if (method == 0) { // ˳�� �����
        for (int i = 0; i < n; i++) {
            sum += integrand(a + i * h);
        }
    }
    else { // ����� �����
        for (int i = 1; i <= n; i++) {
            sum += integrand(a + i * h);
        }
    }
    return h * sum;
}

// ����� ������������ (������� �����)
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
    double a = 0; // ����� ����
    double b = 8; // ������ ����
    int n = 1000; // ʳ������ ��������

    // ���������� ��������� ������ ��������
    printf("����� ��������: %lf\n", trapezoidal_rule(a, b, n));
    printf("����� ��������: %lf\n", parabolic_rule(a, b, n));
    printf("����� ��������������� (����� �����): %lf\n", rectangular_rule(a, b, n, 0));
    printf("����� ��������������� (������ �����): %lf\n", rectangular_rule(a, b, n, 1));
    printf("����� ��������������� (������� �����): %lf\n", midpoint_rule(a, b, n));

    return 0;
}
