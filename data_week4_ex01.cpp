#include "iostream"
#include "math.h"
#include "dm.h"
using namespace std;
const int N = 1510;

int main()
{
    double a[N], n, m;
    double b[N];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - m + 1; i ++) {
        double t = mean_interval(a, i, m);
        b[i] = t;
    }
    
    printf("%.3lf %.3lf\n", sqrt(d_calVar(a, n)), 
            sqrt(d_calVar(b, n - m + 1)));
    
    //print_array_Double(b, n - m + 1);

}