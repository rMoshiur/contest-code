#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std ;

#define fo(i,a,b) for ( int i = a ; i <= b ; i ++ )

const int MAXN = 60 ;

int N , M , H[MAXN][MAXN] ;

int main() {
    int Test ; cin >> Test ;
    fo(i,1,Test) {
        cin >> N >> M ;
        fo(i,0,N+1) fo(j,0,M+1) H[i][j] = 0 ;
        fo(i,1,N) fo(j,1,M) cin >> H[i][j] ;
        int ans = 0 ;
        fo(i,1,N) fo(j,1,M) if (H[i][j] > 0) {
            ans += 1 + max(H[i][j]-H[i-1][j],0) + max(H[i][j]-H[i+1][j],0) + max(H[i][j]-H[i][j-1],0) + max(H[i][j]-H[i][j+1],0) ;
        }
        cout << ans << "\n" ;
    }
}

