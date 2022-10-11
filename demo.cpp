#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
double maxN , minN ;
int absmax ;
const int N = 2008;
double nums[N],tmp[N];
int n;
double getSD(double avg){
    double sd = 0;
    for (int i = 0; i < n; i++)
    {
        sd += pow(nums[i] * 1.0 - avg, 2);
    }
    sd /= (n - 1) * 1.0;
    sd = sqrt(sd);
    return sd;
}
void mFormat()
{
    for (int i = 0; i < 9; i++)
    {
        printf("%.3lf ", (nums[i] - minN) * 1.0 / (maxN - minN));
    }
    printf("%.3lf\n", (nums[9] - minN) * 1.0 / (maxN - minN));
}

void zFormat()
{
    double avg = 0;
    for (int i = 0; i < n; i++)
        avg += nums[i];
    avg /= (n)*1.0;
    double sd = getSD(avg);
    for (int i = 0; i < 9; i++)
    {
        printf("%.3lf ", (nums[i] - avg) * 1.0 / sd);
    }
    printf("%.3lf\n", (nums[9] - avg) * 1.0 / sd);
}
void decFormat()
{
    int p = 0;
    int _10p = 1;
    while ((int)ceil(absmax) > _10p)
    {
        p++;
        _10p *= 10;
    }
    for (int i = 0; i < 9; i++)
    {
        printf("%.3lf ", nums[i] / _10p * 1.0);
    }
    printf("%.3lf\n", nums[9] / _10p * 1.0);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &nums[i]);
        tmp[i] = nums[i];
    }
    sort(tmp, tmp + n);
    maxN = tmp[n - 1];
    minN = tmp[0];
    if (tmp[n - 1] < 0)
    {
        tmp[n - 1] = -tmp[n - 1];
    }
    if (tmp[0] < 0)
    {
        tmp[0] = -tmp[0];
    }

    absmax = max(abs((int)ceil(tmp[n - 1])), abs((int)ceil(tmp[0])));
    mFormat();
    zFormat();
    decFormat();
    return 0;
}