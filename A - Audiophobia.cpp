#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, w;
};

class comp
{
public:
    bool operator()( node &a, node &b )
    {
        return a.w<b.w;
    }
};

int c, n, h;
vector<int>vec1[105];
vector<int>vec2[105];

int dijkstra( )
{
    priority_queue<node, vector< node >, comp> pq;
    node a, b;
    a.x = n;
    a.w = 0;
    int distance[110];
    for( int  i = 1; i <= c; i++ )
        distance[i] = 1<<30;
    distance[a.x] = 0;
    pq.push( a );
    while( !pq.empty() )
    {
        a = pq.top();
        pq.pop();
        int t = a.x, s;
        s = vec1[t].size();
        for( int i = 0 ; i < s; i++ )
        {
            int v = vec1[t][i];
            int we = vec2[t][i];
            if( distance[t] < distance[v] && we < distance[v] )
            {
                //cout << "yes\n";
                a.x = vec1[t][i];
                distance[a.x] = max(vec2[t][i], distance[t]) ;
                a.w = distance[a.x];
                pq.push(a);
            }
        }
    }
    return distance[h];
}
int main()
{
    freopen("input.txt", "r", stdin);
    int s, q, caseno = 1;
    scanf("%d %d %d", &c, &s, &q);
    while( c != 0 || s != 0 || q != 0 )
    {
        int a1,a2,a3;
        for( int i = 0; i < s; i++ )
        {
            scanf("%d %d %d", &a1, &a2, &a3);
            vec1[a1].push_back(a2);
            vec2[a1].push_back(a3);
            vec1[a2].push_back(a1);
            vec2[a2].push_back(a3);
        }
        if( caseno != 1 )
            printf("\n");
        printf("Case #%d\n", caseno++);
        while(q--)
        {
            scanf("%d %d", &n, &h);
            int ans = dijkstra();
            if( ans != 1<<30 )
                printf("%d\n",ans );
            else
                printf("no path\n");
        }
        for( int i = 0; i < 105; i++ )
        {
            vec1[i].clear();
            vec2[i].clear();
        }
        scanf("%d %d %d", &c, &s, &q);
    }
    return 0;
}
