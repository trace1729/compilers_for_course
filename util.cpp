#include "iostream"
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

double mean(int a[], int n) {
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