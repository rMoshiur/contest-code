#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x,y, w;
};

int dx[] = { 0, 0 , 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int ara[1005][1005];
int n, m;

class comp{
public:
    bool operator()( node &n1, node &n2 )
    {
        return n1.w>n2.w;
    }
};

int dk()
{
    priority_queue< node, vector<node>, comp > pq;
    node temp, d;
    int ans[n][m];
    bool flag[n][m];
    for( int i = 0; i < n; i++  )
    {
        for( int j = 0; j < m; j++ )
         {
             ans[i][j] = 1<<30;
             flag[i][j] = 0;
         }
    }
    temp.x = 0;
    temp.y = 0;
    temp.w = ara[0][0];
    ans[0][0] = ara[0][0];
    pq.push(temp);
    while( !pq.empty() )
    {
        temp = pq.top();
        pq.pop();
        if( flag[temp.x][temp.y] == 1 )
            continue;
        flag[temp.x][temp.y] = 1;

        for( int i = 0; i < 4; i++ )
        {
            int x1 = temp.x + dx[i];
            int y1 = temp.y + dy[i];

            if( (x1 >= 0 && x1 < n) && (y1 >= 0 && y1 < m) )
            {
                //cout << "x1 " << x1 << " y1  " << y1 << endl;
                if( flag[x1][y1] == 0 && (ans[temp.x][temp.y] + ara[x1][y1] ) < ans[x1][y1]  )
                {
                    d.x = x1;
                    d.y = y1;
                    ans[x1][y1] = ans[temp.x][temp.y] + ara[x1][y1];
                    d.w = ans[x1][y1];
                    pq.push(d);
                }
            }
        }
    }
    return ans[n-1][m-1];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d", &n);
        scanf("%d", &m);
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                scanf("%d", &ara[i][j]);
            }
        }
        int aa = dk();
        printf("%d\n", aa);
    }
    return 0;
}
