#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std ;

#define PI pair<double,double>
#define MP make_pair
#define PB push_back
#define sign(x) (((x) > 0) - ((x) < 0))

const int MAXM = 1009 ;
const int MAXN = 1009 * 1009 ;

int N , M ;
double x1[MAXM] , yy1[MAXM] , x2[MAXM] , y2[MAXM] ;
vector< pair<PI,int> > CutP[MAXM] ;
int Edge[MAXM][MAXM] ;
PI Point[MAXN] ;
pair<PI,int> sortPoint[MAXN] ;
vector<int> e[MAXN] ;
int side[MAXN] ;
bool used[4] ;

PI operator + (const PI &A , const PI &B) { return MP(A.first+B.first , A.second+B.second) ; }
PI operator - (const PI &A , const PI &B) { return MP(A.first-B.first , A.second-B.second) ; }
PI operator * (const PI &A , const double &B) { return MP(A.first*B , A.second*B) ; }
double operator ^ (const PI &A , const PI &B) { return A.first*B.second - B.first*A.second ; }

PI _inter_ans ;
bool SegmentProperIntersection(PI a1 , PI a2 , PI b1 , PI b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
}
PI GetLineIntersection(PI P , PI v , PI Q , PI w) {
    PI u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
bool Intersection( PI p1 , PI p2 , PI p3 , PI p4 ) {
    PI v = p2-p1 , w = p4-p3 ;
    if ( (v^w) == 0 ) return false ;
    else {
        _inter_ans = GetLineIntersection(p1 , v , p3 , w) ;
        return true ;
    }
    /*
    if ( SegmentProperIntersection(p1,p2,p3,p4) ) {
        _inter_ans = GetLineIntersection(p1 , p2-p1 , p3 , p4-p3) ;
        return true ;
    } else {
        //cout << "False Intersection between (" << p1.first << "," << p1.second << ")-(" << p2.first << "," << p2.second << ") and (" << p3.first << "," << p3.second << ")-(" << p4.first << "," << p4.second << ").\n" ;
        return false ;
    }
    */
}

void Init() {
    cin >> M ;
    N = 0 ;
    for ( int i = 1 ; i <= M ; i ++ ) cin >> x1[i] >> yy1[i] >> x2[i] >> y2[i] ;
    for ( int i = 1 ; i <= M ; i ++ ) CutP[i].clear() ;
    for ( int i = 1 ; i <= M ; i ++ )
        for ( int j = i+1 ; j <= M ; j ++ ) {
            PI its ;
            if ( Intersection( MP(x1[i],yy1[i]) , MP(x2[i],y2[i]) , MP(x1[j],yy1[j]) , MP(x2[j],y2[j]) ) ) {
                its = _inter_ans ;
                CutP[i].PB( MP(its,++N) ) ;
                CutP[j].PB( MP(its,  N) ) ;
                Edge[i][j] = N ;
                Point[N] = its ;
            } else
                Edge[i][j] = -1 ;
        }
    for ( int i = 1 ; i <= N ; i ++ ) e[i].clear() ;
    for ( int i = 1 ; i <= M ; i ++ ) {
        sort( CutP[i].begin() , CutP[i].end() ) ;
        for ( int j = 1 ; j < CutP[i].size() ; j ++ ) {
            e[CutP[i][j-1].second].PB(CutP[i][j].second) ;
            e[CutP[i][j].second].PB(CutP[i][j-1].second) ;
        }
    }
}

void DFS( int x , int col ) {
    side[x] = col ;
    for ( auto it : e[x] ) if ( side[it] == -1 ) DFS( it , 3-col ) ;
}

bool IsBipartiteGraph() {
    for ( int i = 1 ; i <= N ; i ++ ) side[i] = -1 ;
    for ( int i = 1 ; i <= N ; i ++ ) if ( side[i] == -1 ) DFS(i , 1) ;
    for ( int i = 1 ; i <= N ; i ++ )
        for ( auto it : e[i] )
            if ( side[i] == side[it] ) return false ;
    return true ;
}

void Solve() {
    int maxdeg = 0 ;
    for ( int i = 1 ; i <= N ; i ++ ) if ( !e[i].empty() ) if ( e[i].size() > maxdeg ) maxdeg = e[i].size() ;
    if ( maxdeg == 0 ) {
        cout << "1\n" ;
        for ( int i = 1 ; i <= N ; i ++ ) side[i] = 1 ;
    } else if ( IsBipartiteGraph() ) {
        cout << "2\n" ;
    } else {
        cout << "3\n" ;
        for ( int i = 1 ; i <= N ; i ++ ) sortPoint[i] = MP(Point[i] , i) ;
        sort( sortPoint+1 , sortPoint+N+1 ) ;
        for ( int i = 1 ; i <= N ; i ++ ) side[i] = 0 ;
        for ( int i = 1 ; i <= N ; i ++ ) {
            int x = sortPoint[i].second ;
            for ( int j = 1 ; j <= 3 ; j ++ ) used[j] = false ;
            for ( auto it : e[x] ) if ( side[it] != 0 ) used[side[it]] = true ;
            for ( int j = 1 ; j <= 3 ; j ++ ) if ( !used[j] ) {
                side[x] = j ;
                break ;
            }
        }
    }
    
    for ( int i = 1 ; i < M ; i ++ ) {
        for ( int j = i+1 ; j <= M ; j ++ ) {
            if ( Edge[i][j] == -1 ) cout << "-1 " ;
            else                    cout << side[Edge[i][j]] << " " ;
        }
        cout << "\n" ;
    }
}

int main() {
    //freopen("M.in" , "r" , stdin) ;
    //freopen("M.ans", "w" ,stdout) ;
    
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        Init() ;
        Solve() ;
    }
}
