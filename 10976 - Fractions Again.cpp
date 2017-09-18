#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while( scanf("%d", &n) == 1 )
    {
        int px, py, lm = 2*n, a, b, counter = 0, i = 0;
        vector< pair<int,int> > pp;
        for( py = n+1; py <= lm; py++ )
        {
            a = n*py;
            b = py - n;
            if( a % b == 0 )
            {
                px = a/b;
                counter++;
                pp.push_back( make_pair(px,py) );
            }
        }

        printf("%d\n", counter);
        while(counter--)
        {
            printf("1/%d = 1/%d + 1/%d\n",n, pp[i].first, pp[i].second);
            i++;
        }
    }

    return 0;
}
