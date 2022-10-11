#include "iostream"
#include "cmath"
#include "dm.h"
using namespace std;
const int N = 1510;

double dot_product(double a[], double b[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += a[i] * b[i];
    return sum;
}

double square_sum(double a[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) sum += a[i] * a[i];
    return sum;
}

double cR(double a[],double b[], int n) {
    double dot = dot_product(a, b, n);
    double fra = square_sum(a, n) * square_sum(b, n);
    return dot / sqrt(fra); 
}

double rR(double a[],double b[], int n) {
    double a_m = d_mean(a, n);
    double b_m = d_mean(b, n);
    double dot = 0.0;
    for (int i = 0; i < n; i++) dot += (a[i] - a_m)* (b[i] - b_m);
    double t1 = 0.0;
    double t2 = 0.0;
    for (int i = 0; i < n; i++) {
        t1 += (a[i] - a_m) * (a[i] - a_m);
        t2 += (b[i] - b_m) * (b[i] - b_m);
    }
    return dot / sqrt(t1 * t2);
}

double jR(double a[],double b[], int n) {
    double dot = dot_product(a, b, n);
    double fra = square_sum(a, n) + square_sum(b, n);
    return dot / (fra - dot); 
}

int main()
{
    double a[N], b[N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    printf("%.3lf %.3lf %.3lf", cR(a, b, n), rR(a, b, n), jR(a, b, n));

}