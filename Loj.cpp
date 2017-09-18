#include <bits/stdc++.h>

using namespace std;

const int num = 1000000;


int main()
{
    freopen("input.txt", "r", stdin);
    int t, caseno= 1;
    scanf("%d\n", &t);
    while(t--)
    {
        char str1[num+5];
        char str2[num+5];
        gets(str1);
        int len = strlen(str1);
        for( int  i = 0; i < len ; i++ )
        {
            str2[len-i-1] = str1[i];
        }
        str2[len] = '\0';
        int ara[len], j  = 0, i = 0, temp = -1;
        while( i < len )
        {
            //cout << "yes\n";
            if( str1[i] == str2[j] )
            {
                j++;
                ara[i] = j;
                i++;
                temp = -1;
            }
            /*else if( j == 1 && str1[i] != str2[j] )
            {
                ara[i] = 0;
                j = 0;
                i++;
            }*/
            else if( str1[i] != str2[j] )
            {
                j = ara[j-1];
                if( temp == j )
                {
                    ara[i] = 0;
                    j = 0;
                    i++;
                }
                temp = j;
            }
        }
        printf("Case %d: %d\n",caseno++, 2*len - ara[len-1]);
    }
    return 0;
}
