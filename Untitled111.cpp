/*
__________           .___
\______   \ ____   __| _/_  _  _______    ____
 |       _// __ \ / __ |\ \/ \/ /\__  \  /    \
 |    |   \  ___// /_/ | \     /  / __ \|   |  \
 |____|_  /\___  >____ |  \/\_/  (____  /___|  /
        \/     \/     \/              \/     \/

handle	: rubabredwan (Codeforces/CodeChef/HackerRank)
task 	: ...............

*/

#include <bits/stdc++.h>

#define READ(x)		freopen(x,"r",stdin)
#define WRITE(x)	freopen(x,"w",stdout)

#define REP(i,n)	for(int i=0;i<n;i++)
#define REPN(i,n)	for(int i=1;i<=n;i++)
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define SET(i,n)	memset(i,n,sizeof(i))

#define MAX			1000020
#define INF			1e9
#define in			insert
#define pb			push_back
#define cl			clear
#define sz			size
#define xx 			first
#define yy	 		second

using namespace std;

typedef long long int 	ll;
typedef vector<int>		vi;
typedef pair<ll,ll>		pii;
typedef double			db;

//template ends here

char a[MAX], b[MAX];
int n1, n2;

string A, B;

int solve(){

    for(int i=0;i<n1;i++){
        if(A[i] < B[i]) return 0;
        else if(A[i] > B[i]) return 2;
    }
    return 1;
}

int main(){
    freopen("input.txt", "r", stdin);
    scanf("%s", a);
    scanf("%s", b);
    n1 = strlen(a);
    n2 = strlen(b);

    A = "";
    B = "";

    REP(i, n1){
        if(a[i] != '0'){
            for(int j=i;j<n1;j++) A += a[j];
            break;
        }
    }

    REP(i, n2){
        if(b[i] != '0'){
            for(int j=i;j<n2;j++) B += b[j];
            break;
        }
    }

    //cout << A << ' ' << B << endl;

    n1 = A.size();
    n2 = B.size();

    if(n1 < n2) printf("<");
    else if(n1 > n2) printf(">");
    else{

        int ret = solve();
        if(ret == 0) printf("<");
        else if(ret == 1) printf("=");
        else printf(">");

    }


	return 0;
}
