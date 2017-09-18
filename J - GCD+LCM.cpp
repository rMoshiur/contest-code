#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
//#define double      long double

int phi[1000005], n = 1000001;
long double lcm[1000005], gcd[1000005];
long double dd = log(10.0);

void sieve()
{
    for( int i = 1; i < n; i++ ) phi[i] = i;
    for( int i = 2; i < n; i++ )
    {
        if( phi[i] == i )
        {
            for( int j = i; j < n; j+=i )
            {
                phi[j]/=i;
                phi[j]*= (i-1);
            }
        }
    }
}

void precal()
{
    for( int i = 1; i < n; i++ )
        lcm[i] = gcd[i] = 0.0;
    for( int i = 2; i < n; i++ )
    {
        for( int j = i+i; j < n; j += i )
        {
            gcd[j] += phi[j/i]*log((double)i)/dd;
        }
    }
    long double temp = 0;
    for( int i = 2; i < n; i++ )
    {
        lcm[i] = ((i-1)*log((double)i)+temp+log( (double)(i-1.0)))/dd - gcd[i];
        temp = temp+log( (double)(i-1.0));

    }
    for( int i = 2; i < n; i++ )
    {
        //what_is(gcd[i]);
        gcd[i] += gcd[i-1];
        lcm[i] += lcm[i-1];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    sieve();
    //for( int i = 1; i < 10; i++ ) cout << phi[i] << " " << endl;
    precal();
    int caseno = 1;
    while(1)
    {
        int l;
        cin >> l;
        if(l==0)
            break;
        intl ans1 = gcd[l]/100.0, ans2 = lcm[l]/100.0;
        //what_is(l);
        cout << "Case " << caseno++ << ": " << ans1+1 << " " << ans2+1 << endl;
    }

    return 0;
}




