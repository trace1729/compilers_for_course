#include "iostream"
#include "algorithm"
using namespace std;

int n, p, a[2010];

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n ; i++) cin >> a[i];
    sort(a, a + n);
    double rate =  p * 1.0 / 100;
    int num = (int)(n * rate / 2), sum = 0;
    int *s = a + num, *e = a + n - num;
    while (s < e) {
        sum += *s;
        s++;
    }
    printf("%.3lf\n", sum * 1.0 / (n - num*2));
    return 0;
}