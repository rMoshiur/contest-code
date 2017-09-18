#include<bits/stdc++.h>

using namespace std;

int ara[1000005];

void process( char *str, int len )
{
    ara[0] = 0;
    int x = 0;
    for( int i = 1; i < len; i++ )
    {
        while( str[i] != str[x] && x!=0 )
        {
            x = ara[x-1];
        }
        ara[i] = x;
        if( str[i] == str[x] )
        {
            x++;
            ara[i]++;
        }
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        char str1[1000005], str2[1000005];
        gets(str1);
        gets(str2);
        int len1 = strlen(str1), len2 = strlen(str2);
        process(str2, len2);
        int j = 0, ans = 0, i = 0;
        while( i < len1 )
        {
            if( j == len2 )
            {
                j = ara[j-1];
                //i++;
                ans++;
            }
            if( str1[i] == str2[j] )
            {
                j++;
                i++;
            }
            else if( str1[i] != str2[j] && i < len1)
            {
                if( j > 0 )
                j = ara[j-1];
                else
                i++;
            }
        }
        if( j == len2 )
            ans++;
        printf("Case %d: %d\n", caseno++, ans);
    }
    return 0;
}
