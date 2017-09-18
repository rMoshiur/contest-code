#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb        long double

int tree[4*30005][3]; // 0=ok, 1=( , 2 = )
char str[30005];

void troyee(int cn)
{
    int temp = min( tree[cn*2][1], tree[cn*2+1][2] );
    //what_is(temp);
    tree[cn][0] = tree[cn*2][0] + tree[cn*2+1][0]+temp;
    tree[cn][1] = tree[cn*2][1] + tree[cn*2+1][1]-temp;
    tree[cn][2] = tree[cn*2][2] + tree[cn*2+1][2]-temp;
}

void init( int cn, int s, int e )
{
    if(s==e)
    {
        tree[cn][0] = tree[cn][1] = tree[cn][2] = 0;
        if(str[s-1] == '(')
            tree[cn][1] = 1;
        else
            tree[cn][2] = 1;
        return;
    }
    int m = (s+e)/2;
    init(cn*2, s, m);
    init(cn*2+1, m+1, e);
    troyee(cn);
}

void update( int cn, int s, int e, int x )
{
    if( s > x || e < x ) return;
    if( s == e && s == x )
    {
        //debug;
        tree[cn][0] = tree[cn][1] = tree[cn][2] = 0;
        if( str[s-1] == '(' )
        {
            str[s-1] = ')';
            tree[cn][2] = 1;
        }
        else
        {
            str[s-1] = '(';
            tree[cn][1] = 1;
        }
        return;
    }
    int m = (s+e)/2;
    update(cn*2, s, m, x);
    update(cn*2+1, m+1, e, x);
    troyee(cn);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t = 10, caseno = 1;
    while(t--)
    {
        int n;
        scanf("%d\n", &n);
        gets(str);
        init(1,1,n);
        int q;
        scanf("%d", &q);
        printf("Test %d:\n", caseno++);
        while(q--)
        {
            int x;
            scanf("%d", &x);
            if( x == 0 )
            {
                //what_is( tree[1][0] );
                if( n%2 == 0 && tree[1][0] == n/2 )
                {
                    printf("YES\n");
                }
                else
                    printf("NO\n");

            }
            else
                update(1,1,n,x);
        }
    }

    return 0;
}




