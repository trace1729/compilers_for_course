#include "iostream"
#include "cmath"
#include "dm.h"
using namespace std;
const int N = 2010;

void min_max_norm(double a[], int n) {
    double maxx = d_max(a, n);
    double minn = d_min(a, n);

    double b[n];
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] - minn) / (maxx - minn);
    }

    d_sort(b, n);
    print_array_Double(b, 10);

}

void z_score_norm(double a[], int n) {
    double mea = d_mean(a, n);
    double delta = sqrt(d_calVar(a, n));
    double b[N];
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] - mea) / delta;
    }
    d_sort(b, n);
    print_array_Double(b, 10);
}

int get_digit(int num) {
    if (num == 0) return 0;
    return get_digit(num / 10) + 1;
}

void dot_norm(double a[], int n) {

    double maxx = d_abs_max(a, n);
    int digit = get_digit((int)ceill(maxx));
    double factor = pow(10, digit);
    double b[N];
    for (int i = 0; i < n; i++) {
        b[i] = a[i] / factor;
    }

    d_sort(b, n);
    print_array_Double(b, 10);
}

int main()
{
    double a[N], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    min_max_norm(a, n);
    z_score_norm(a, n);
    dot_norm(a, n);
    printf("%d", get_digit(9999));

}