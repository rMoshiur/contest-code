///DIJKSTRA SHORTEST PATH O(elogv)
//a structure for maintaining priority queue
struct edg
{
    int a, w;
    edg( int x, int y )
    {
        a = x;
        w = y;
    }
    bool operator<( const edg &x )const
    {
        return w > x.w;
    }
};
//s = source, eg = edge list, cost = cost of a edge, path = shortest distance keeper from source
void dijkstra( int s, vector< vector<int> >&eg, vector< vector<int> >&cost, int path[] )
{
    priority_queue<edg>pq;
    pq.push( edg(s,0) );
    path[s] = 0;
    while( !pq.empty()  )
    {
        edg x = pq.top();
        pq.pop();
        if( x.w > path[x.a] )
            continue;
        for( int i = 0; i < eg[x.a].size(); i++ )
        {
            int v = eg[x.a][i], cst = cost[x.a][i];
            if( x.w + cst < path[v] )
            {
                path[v] = x.w + cst;
                pq.push( edg(v,x.w + cst) );
            }
        }
    }
}
