#include "iostream"
#include "cmath"
#include "dm.h"

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t; 
            } 
        }
    }
}

void d_sort(double a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                double t = a[i];
                a[i] = a[j];
                a[j] = t; 
            } 
        }
    }
}

double mean(int a[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i ++) {
        sum += a[i];
    }
    return sum /= n;
}

double mean_interval(double a[], int j, int k) {   
    double sum = 0.0;
    for (int i = j; i < j + k; i ++) {
        sum += a[i];
    }
    return sum / k;
}

double d_mean(double a[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i ++) {
        sum += a[i];
    }
    return sum /= n;
}

double middle(int a[], int n) {
    // 0, 1, 2, 3
    if (n & 1) 
        return a[n/2] * 1.0;
    else 
        return (a[n/2] + a[n / 2 + 1]) * 1.0 / 2;
}


int min(int a[], int n) {
   int m = a[0];
   for (int i = 0; i < n; i ++) {
    if (a[i] < m) m = a[i];  
   } 
   return m;
}

int max(int a[], int n) {
   int m = a[0];
   for (int i = 0; i < n; i ++) {
    if (a[i] > m) m = a[i];  
   } 
   return m;
}

double d_min(double a[], int n)
{
    double m = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < m)
            m = a[i];
    }
    return m;
}

double d_max(double a[], int n)
{
    double m = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    return m;
}
double d_abs_max(double a[], int n)
{
    double m = fabs(a[0]);
    for (int i = 0; i < n; i++)
    {
        if (fabs(a[i]) > m)
            m = a[i];
    }
    return m;
}



double calVar(int a[], int n)
{
    double var = 0.0, me = mean(a, n);
    for (int i = 0; i < n; i++)
    {
        double t = (a[i] - me) * (a[i] - me);
        var += t;
    }
    return var / (n - 1);
}

double d_calVar(double a[], int n)
{
    double var = 0.0, me = d_mean(a, n);
    for (int i = 0; i < n; i++)
    {
        double t = (a[i] - me) * (a[i] - me);
        var += t;
    }
    return var / (n - 1);
}

void print_array_Double(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.3lf ", a[i]);
    }
    putchar('\n');
}
