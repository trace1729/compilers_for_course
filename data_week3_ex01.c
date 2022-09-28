#include <stdio.h>
#include <math.h>

const int N = 2000 + 10;
int a[2010], n;


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

double mean() {
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


int min() {
   int m = a[0];
   for (int i = 0; i < n; i ++) {
    if (a[i] < m) m = a[i];  
   } 
   return m;
}

int max() {
   int m = a[0];
   for (int i = 0; i < n; i ++) {
    if (a[i] > m) m = a[i];  
   } 
   return m;
}

double calRange() {
    return (max() - min()) * 1.0;
}

double calVar() {
    double var = 0.0, me = mean();
    for (int i = 0; i < n; i++) {
        double t = (a[i] - me) * (a[i] - me);
        var += t;
    }
    return var / (n - 1);
}

double calMadMean() {
    double sum = 0.0, me = mean();
    for (int i = 0; i < n; i++) {
        sum += fabs(a[i]*1.0 - me);
    }
    return sum / n;
}
double calMadMiddle() {
    double sum = 0.0, mid = middle(a, n);
    int tt[2010];
    for (int i = 0; i < n; i++) {
        tt[i] = fabs(a[i] - mid);
    }
    sort(tt, n);
    return middle(tt, n);
}

double calQuar() {
    
    int q1, q3;
    int t = n / 4;  // 四分位点
    if (n % 4 == 0) {  // 如果能被4整除
        q1 = a[t - 1];
        q3 = a[n - t];
        return (q3 - q1)*1.0;
    } else {   // 如果不能被四整除 
        return (a[n - t] + a[n - t - 1] - a[t - 1] - a[t]) * 1.0 / 2;
    }
}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n ; i++) scanf("%d", &a[i]);
    sort(a, n);
    //printf("%lf %lf %d %d\n", mean(), middle(), max(), min());
    printf("%.3lf %.3lf %.3lf %.3lf %.3lf\n", calRange(), calVar(), calMadMean(), calMadMiddle(), calQuar());

}