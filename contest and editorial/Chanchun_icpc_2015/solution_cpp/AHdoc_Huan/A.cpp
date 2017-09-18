#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

const LL V[10] = { 1 , 5 , 10 , 20 , 50 , 100 , 200 , 500 , 1000 , 2000 } ;
const LL INF = 100000000 ;

LL C[10] , P , Ans ;

LL minLL(LL n1 , LL n2) { return (n1 < n2 ? n1 : n2) ; }

LL F(LL Q) {
    if ( Q < 0 ) return INF ;
    LL Ans = 0 , tmp ;
    for ( int i = 9 ; i >= 0 ; i -- ) {
        if ( i == 4 || i == 7 ) tmp = 2 * minLL( (LL)(Q / (2*V[i])) , (LL)(C[i] / 2) ) ;
        else                    tmp = minLL( Q / V[i] , C[i] ) ;
        Ans += tmp ;
        Q -= tmp * V[i] ;
    }
    if ( Q == 0 ) return Ans ;
    else return INF ;
}

LL Solve() {
    LL Ret = INF ;
    Ret = minLL(Ret , F(P)) ;
    if ( C[4] > 0 ) {
        C[4] -- ; Ret = minLL(Ret , F(P-50) + 1) ; C[4] ++ ;
    }
    if ( C[7] > 0 ) {
        C[7] -- ; Ret = minLL(Ret , F(P-500) + 1) ; C[7] ++ ;
    }
    if ( C[4] > 0 && C[7] > 0 ) {
        C[4] -- ; C[7] -- ; Ret = minLL(Ret , F(P-550) + 2) ; C[4] ++ ; C[7] ++ ;
    }
    return Ret ;
}

int main() {
    //freopen("A.in" , "r" , stdin) ;
    //freopen("A_ahdoc.out", "w" ,stdout) ;
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        scanf("%I64d" , &P) ; P = -P ;
        for ( int j = 0 ; j < 10 ; j ++ ) { scanf("%I64d" , &C[j]) ; P += C[j] * V[j] ; }
        
        if ( P < 0 ) puts("-1") ;
        else {
            Ans = Solve() ;
            if ( Ans >= INF ) puts("-1") ;
            else printf("%I64d\n" , C[0] + C[1] + C[2] + C[3] + C[4] + C[5] + C[6] + C[7] + C[8] + C[9] - Ans) ;
        }
    }
}
