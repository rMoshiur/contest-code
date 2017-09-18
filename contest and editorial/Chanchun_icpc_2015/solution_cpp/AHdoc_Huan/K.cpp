#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
using namespace std ;

#define MP make_pair
#define PB push_back

typedef long long LL ;

const int MAXN = 209 ;
const LL  MAXC = 3000000000 ;
const LL  MOD  = 1000000007 ;

LL Ans ;
LL X1[MAXN] , Y1[MAXN] , X2[MAXN] , Y2[MAXN] , C[MAXN] ;
LL NewX1[MAXN] , NewY1[MAXN] , NewX2[MAXN] , NewY2[MAXN] ;
LL X[MAXN] , Y[MAXN] ;
int Xtot , Ytot ;
set<LL> Xset , Yset ;
map<LL,int> Xlink , Ylink ;
LL Min[MAXN][MAXN] ;
int fa[MAXN*MAXN] ;
int La , Lab[MAXN][MAXN] ;
pair<int,int> RevLab[MAXN*MAXN] ;
int _tot ;
LL MapEdge_i[MAXN][MAXN] , MapEdge_j[MAXN][MAXN] ;
pair< LL , pair<int,int> > Edge[MAXN*MAXN*4] ;

void FindMin(int N) {
    for ( int i = 1 ; i <= Xtot ; i ++ ) for ( int j = 1 ; j <= Ytot ; j ++ ) Min[i][j] = -1 ;
    for ( int i = 1 ; i <= N ; i ++ ) {
        int io = NewX1[i] , ie = NewX2[i] , jo = NewY1[i] , je = NewY2[i] ;
        for ( int j = io + 1 ; j <= ie ; j ++ )
            for ( int k = jo + 1 ; k <= je ; k ++ )
                if ( C[i] > Min[j][k] )
                    Min[j][k] = C[i] ;
    }
}
int findfa( int x ) { return fa[x] = (fa[x] != x ? findfa(fa[x]) : x) ; }
bool Union( int x , int y ) {
    int fx = findfa(x) , fy = findfa(y) ;
    if ( fx != fy ) {
        fa[fx] = fy ;
        return true ;
    } else return false ;
}
void Refresh( int i , int j , int o , LL k ) {
    if ( o == 0 ) if ( k > MapEdge_i[i][j] ) MapEdge_i[i][j] = k ;
    if ( o == 1 ) if ( k > MapEdge_j[i][j] ) MapEdge_j[i][j] = k ;
}
void Solve(int N) {
    Xset.insert(X1[N]) ; Xset.insert(X2[N]) ; Yset.insert(Y1[N]) ; Yset.insert(Y2[N]) ;
    Xtot = Ytot = -1 ; Xlink.clear() ; Ylink.clear() ;
    for ( auto it : Xset ) { X[++Xtot] = it ; Xlink[it] = Xtot ; }
    for ( auto it : Yset ) { Y[++Ytot] = it ; Ylink[it] = Ytot ; }
    for ( int i = 1 ; i <= N ; i ++ ) NewX1[i] = Xlink[X1[i]] , NewY1[i] = Ylink[Y1[i]] , NewX2[i] = Xlink[X2[i]] , NewY2[i] = Ylink[Y2[i]] ;
    FindMin(N) ;
    Ans = 0 ;
    for ( int i = 1 ; i <= Xtot ; i ++ )
        for ( int j = 1 ; j <= Ytot ; j ++ ) {
            if ( Min[i][j] == -1 ) continue ;
            Ans += (((X[i] - X[i-1] - 1) * (Y[j] - Y[j-1] - 1)) % MOD) * Min[i][j] ;
            Ans %= MOD ;
        }
    La = 0 ;
    for ( int i = 1 ; i <= (Xtot+1)*(1+Ytot) ; i ++ ) fa[i] = i ;
    for ( int i = 0 ; i <= Xtot ; i ++ ) for ( int j = 0 ; j <= Ytot ; j ++ ) MapEdge_i[i][j] = -1 , MapEdge_j[i][j] = -1 ;
    for ( int i = 0 ; i <= Xtot ; i ++ ) for ( int j = 0 ; j <= Ytot ; j ++ ) {
        Lab[i][j] = ++ La ; RevLab[La] = MP(i,j) ;
        if ( i > 0 ) {
            if ( j > 0 && Min[i][j] != -1 ) Refresh( i , j , 0 , Min[i][j] ) ;
            if ( j < Ytot && Min[i][j+1] != -1 ) Refresh( i , j , 0 , Min[i][j+1] ) ;
        }
        if ( j > 0 ) {
            if ( i > 0 && Min[i][j] != -1 ) Refresh( i , j , 1 , Min[i][j] ) ;
            if ( i < Xtot && Min[i+1][j] != -1 ) Refresh( i , j , 1 , Min[i+1][j] ) ;
        }
    }
    for ( int i = 1 ; i <= N ; i ++ ) {
        if ( X1[i] == X2[i] ) {
            int j = NewX1[i] ;
            for ( int k = NewY1[i] + 1 ; k <= NewY2[i] ; k ++ ) Refresh( j , k , 1 , C[i] ) ;
        }
        if ( Y1[i] == Y2[i] ) {
            int k = NewY1[i] ;
            for ( int j = NewX1[i] + 1 ; j <= NewX2[i] ; j ++ ) Refresh( j , k , 0 , C[i] ) ;
        }
    }
    _tot = 0 ;
    for ( int i = 0 ; i <= Xtot ; i ++ ) for ( int j = 0 ; j <= Ytot ; j ++ ) {
        if ( MapEdge_i[i][j] != -1 ) {
            Ans += (X[i] - X[i-1] - 1) * MapEdge_i[i][j] ; Ans %= MOD ;
            Edge[_tot++] = MP(MapEdge_i[i][j] , MP(Lab[i-1][j],Lab[i][j])) ;
        }
        if ( MapEdge_j[i][j] != -1 ) {
            Ans += (Y[j] - Y[j-1] - 1) * MapEdge_j[i][j] ; Ans %= MOD ;
            Edge[_tot++] = MP(MapEdge_j[i][j] , MP(Lab[i][j-1],Lab[i][j])) ;
        }
    }
    sort( Edge , Edge+_tot ) ;
    for ( int i = _tot-1 ; i >= 0 ; i -- )
        if ( Union(Edge[i].second.first , Edge[i].second.second) ) {
            Ans += Edge[i].first ;
            Ans %= MOD ;
        }
    cout << Ans % MOD << "\n" ;
}

int main() {
    //freopen("K.in" , "r" , stdin) ;
    //freopen("K_ahdoc.out" , "w" , stdout) ;
    
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        int N ; cin >> N ;
        Xset.clear() ; Yset.clear() ;
        for ( int j = 1 ; j <= N ; j ++ ) {
            cin >> X1[j] >> Y1[j] >> X2[j] >> Y2[j] >> C[j] ;
            Solve(j) ;
        }
    }
}
