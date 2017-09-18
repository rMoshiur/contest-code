#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int num = 200000;
int pn = 1;

vector<int> prime;

void sieve()
{
    vector<bool> flag(num+1, 1);
    prime.push_back(2);
    int t = sqrt(num)+5;
    for( int i = 2; i <= num; i+=2 ) flag[i] = 0;
    for( int i = 3; i <= t; i+=2 )
    {
        if( flag[i] == 1 )
        {
            //prime.push_back(i);
            //pn++;
            for( int j = i+i;j<= num; j+=i )
                flag[j] = 0;
        }
    }
    for( int i = 3; i <= num; i+=2 )
    {
        if( flag[i] == 1 )
        {
            prime.push_back(i);
            pn++;
        }
    }
    return;
}

long long power( long long a, long long b )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
        {
            ans *=a;
            ans %= mod;
        }
        b /= 2;
        a *= a;
        a %= mod;
    }
    if( ans < 0 )
        ans += mod;
    return ans;
}


int main()
{
    freopen("input.txt", "r", stdin);
    sieve();
   //cout << power(2, 15) << endl;
    //cout << pn << endl;
    int n, x, c = 0;
    scanf("%d", &n);
    vector<int> vec(num+1, 0);
    vector<int> pw(pn+1, 0);
    //cout << prime[pn-1]<< endl;
    //cout << n << endl;
    for( int i = 0; i < n; i++ )
    {
        scanf("%d", &x);
        vec[x]++;
        //cout << x << endl;
    }
    //cout << x << " " <<  vec[x] <<endl;
    for( int i = 2; i <= num; i++ )
    {
        if( i == prime[c] )
        {
            if( vec[i] > 0 )
            {
                pw[c] = vec[i];
                //cout << pw[c] << " " << vec[i] << endl;
            }
            c++;
            //cout << c << endl;
        }
    };
    long long d = 1, ans = 1, y, z, q = 0, temp = 1;
    vector<int> ara;
    vector<int> fl;
    for( int i = 0; i < pn; i++ )
    {
        if( pw[i] > 0 )
        {
            ara.push_back(pw[i]+1);
            fl.push_back(i);
            q++;
        }
    }
    //cout << d << endl;
    for( int i = 0; i < pn; i++ )
    {
        temp = 1;
        if( pw[i] > 0 )
        {
            /*y = d/(pw[i]+1);
            z = (pw[i]*(pw[i] + 1) )/2;
            //cout << z << endl;
            z *= y;
            //cout << prime[i] << " " << z << endl;
            ans *= power( prime[i], z );*/
            temp *= power(prime[i], (pw[i]*(pw[i]+1))/2 );
            temp %= mod;
            for( int j = 0; j < q; j++ )
            {
                if( fl[j] != i ){
                temp = power(temp, ara[j] );
                temp %= mod;}
            }
            ans *= temp;
            ans %= mod;
        }
    }
    if( ans < 0 ) ans += mod;
    printf("%I64d\n", ans);
    return 0;
}

