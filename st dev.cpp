#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n, d, s = 0;
    double dd;
    scanf("%d %d %lf", &n, &d, &dd);
    int ara2[n];
    double ara1[n], ara3[n], ii, jj; // median, num, ui
    for(int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d %d", &a, &b, &ara2[i]);
        s+= ara2[i];
        ara1[i] = (b+a)/2.0;
        ii = ara1[i] - dd;
        //cout << ii << endl;
        ii /= (double)d;

        ara3[i] = ii;
        //cout << ara1[i] << "    " <<  ara2[i] << "   " << ara3[i] << endl;
    }
    double s1=0, s2=0;
    for(int i =0; i < n; i++)
    {
        s1 += ara2[i]*ara3[i];
        s2 += ara2[i]*ara3[i]*ara3[i];
    }
    s1 = s1/(double)s;
    s2 = s2/(double)s;
    printf("%lf %lf", d*d*(s2-s1*s1), sqrt(d*d*(s2-s1*s1)));
    return 0;
}
