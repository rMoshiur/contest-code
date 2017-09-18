#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        unsigned long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define endl        "\n"


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl t;
    cin >> t;
    while(t--)
    {
        intl r,c,ara[3], flag = 0;
        cin >> r >> c >> ara[0] >> ara[1] >> ara[2];
        intl temp1= ara[0]+ara[1]+ara[2];
        intl temp2= r*c;
        //what_is(temp1);
        //what_is(temp2);
        if(  temp1 != temp2 )
        {
            cout << "No\n";
            continue;
        }
        intl rr = r, cc = c;
        if( ara[0]%r == 0 || ara[0]%c == 0 )
        {
            if( ara[0]%r == 0 )
            {
                c = c - ara[0]/r;
                if( (ara[1]%r == 0 && ara[2]%r == 0) || ( ara[1]%c == 0 && ara[2]%c == 0 ) )
                {
                    flag = 1;
                }
            }
            c = cc;
            r = rr;
            if( ara[0]%c == 0 )
            {
                r = r - ara[0]/c;
                if( (ara[1]%r == 0 && ara[2]%r == 0) || ( ara[1]%c == 0 && ara[2]%c == 0 ) )
                {
                    flag = 1;
                }
            }
        }
        r = rr;
        c = cc;
        if( ara[1]%r == 0 || ara[1]%c == 0 )
        {
            if( ara[1]%r == 0 )
            {
                c = c - ara[1]/r;
                if( (ara[0]%r == 0 && ara[2]%r == 0) || ( ara[0]%c == 0 && ara[2]%c == 0 ) )
                {
                    flag = 1;
                }
            }
            c = cc;
            r = rr;
            if( ara[1]%c == 0 )
            {
                r = r - ara[1]/c;
                if( (ara[0]%r == 0 && ara[2]%r == 0) || ( ara[0]%c == 0 && ara[2]%c == 0 ) )
                {
                    flag = 1;
                }
            }

        }
        r = rr;
        c = cc;
        if( ara[2]%r == 0 || ara[2]%c == 0 )
        {
            if( ara[2]%r == 0 )
            {
                c = c - ara[2]/r;
                if( (ara[1]%r == 0 && ara[0]%r == 0) || ( ara[1]%c == 0 && ara[0]%c == 0 ) )
                {
                    flag = 1;
                }
            }
            r = rr;
            c = cc;
            if( ara[2]%c == 0 )
            {
                r = r - ara[2]/c;
                if( (ara[1]%r == 0 && ara[0]%r == 0) || ( ara[1]%c == 0 && ara[0]%c == 0 ) )
                {
                    flag = 1;
                }
            }

        }

        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}


