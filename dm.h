#ifndef DM_H
#define DM_H

#include "cmath"

void sort(int a[], int n);
void d_sort(double a[], int n);
double mean(int a[], int n);
double mean_interval(double a[], int j, int k);
double d_mean(double a[], int n);
double calVar(int a[], int n);
double d_calVar(double a[], int n);
int max(int a[], int n);
int min(int a[], int n);
double d_max(double a[], int n);
double d_min(double a[], int n);
double d_abs_max(double a[], int n);
void print_array_Double(double a[], int n);
void print_array_Int(int a[], int n);

#endif