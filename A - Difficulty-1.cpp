#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y, pos;
};

point p;

int dik( point p1, point p2, point p3 )
{
    int x = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*( p3.x - p1.x );
    if( x == 0 ) return 0;
    if( x > 0 ) return 1;
    return -1;
}

bool comp( point a, point b )
{
    if( a.x == b.x && a.y == b.y ) return true;
    int x = dik(p, a, b );
    if( x == 0 )
    {
        if( a.x == b.x )
            return a.y<b.y;
        return a.x<b.x;
    }
    if( x == 1 )
        return true;
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno= 1;
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        int n, c1 = 1, c2;
        scanf("%d", &n);
        point ara[n+1], q, p9, q9;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d %d", &ara[i].x, &ara[i].y);
            ara[i].pos = i;
        }
        if( caseno != 1 )
            printf("\n");
        stack<point> st;
        p = ara[1];
        for( int i = 1; i <= n; i++ )
        {
            if( ara[i].y <= p.y )
            {
                if( ara[i].y < p.y)
                {
                    p = ara[i];
                    c1 = i;
                }
                else
                {
                    if( ara[i].x < p.x )
                    {
                        p = ara[i];
                        c1 = i;
                    }
                }
            }
        }
        ara[c1] = ara[1];
        ara[1] = p;
        if( n > 2 )
            sort( ara+2, ara+n+1, comp );

        st.push(ara[1]);

        //st.push(3);
        if( n == 1 )
        {
            printf("0.00\n");
            printf("1\n");
            continue;
        }
        st.push(ara[2]);
        for( int i = 3; i <= n; i++ )
        {
            while(1)
            {
                point tp = st.top();
                st.pop();
                point tpp = st.top();
                int x = dik(tpp, tp, ara[i] );
                if( x == 1 )
                {
                    st.push(tp);
                    st.push(ara[i]);
                    break;
                }
                if( x == 0 )
                {
                    st.push(ara[i]);
                    break;
                }
            }

        }
        //cout << "ans ";
        vector<int> vec;
        double ans = 0;
        p9 = st.top();
        while( st.size() )
        {
            if( st.size() == 1 )
                q9 = st.top();
            vec.push_back(st.top().pos);
            p = st.top();
            st.pop();
            if( st.size() )
                q = st.top();
            ans += sqrt( (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) );
        }
        int yy = vec.size();
        ans += sqrt( (p9.x-q9.x)*(p9.x-q9.x) + (p9.y-q9.y)*(p9.y-q9.y) );
        printf("%.2lf\n", ans);
        printf("%d", vec[yy-1]);
        for( int i = yy-2; i >= 0; i-- )
        {
            printf(" %d", vec[i]);
        }
        printf("\n");
        caseno++;
    }
    return 0;
}
