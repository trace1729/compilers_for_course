#include <stdio.h>
#include <math.h>
#include "dm.h"

const int N = 2000 + 10;
int a[2010], n;


double calRange() {
    return (max(a, n) - min(a, n)) * 1.0;
}

double calVar() {
    double var = 0.0, me = mean(a, n);
    for (int i = 0; i < n; i++) {
        double t = (a[i] - me) * (a[i] - me);
        var += t;
    }
    return var / (n - 1);
}

double calMadMean() {
    double sum = 0.0, me = mean(a, n);
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