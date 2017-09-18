#include <bits/stdc++.h>

using namespace std;

struct data
{
    int sum;
    int lazy;
};

data tree[1000];
int ara[200];

void build_tree( int cn, int ss, int se )
{
    if( ss==se )
    {
        tree[cn].sum = ara[ss];
        //cout << "----cn----- " << cn << " " << ss << " " << se << endl;
        tree[cn].lazy = 0;
        return;
    }
    int mid = (ss+se)/2;
    build_tree( cn*2, ss, mid );
    build_tree( cn*2 + 1, mid+1, se );
    tree[cn].sum = tree[cn*2].sum + tree[cn*2 + 1].sum;
    tree[cn].lazy = 0;
    return;
}

void update_tree( int cn, int ss, int se, int us, int ue, int nv )
{
    if( se < us || ss>ue )
        return;
    if( ss >= us && se <= ue )
    {
        tree[cn].sum += (se-ss+1)*nv;
        tree[cn].lazy += nv;
        return;
    }
    int mid = (ss+se)/2;
    update_tree( cn*2, ss, mid, us, ue, nv );
    update_tree( cn*2 + 1, mid+1, se, us, ue, nv );
    tree[cn].sum = tree[cn*2].sum + tree[cn*2 + 1].sum + (se-ss+1)*tree[cn].lazy;
    return;
}

int query_tree( int cn, int ss, int se, int qs, int qe, int carry )
{
    if( se<qs || ss>qe )
     {
         //cout << " ss " << ss << "  se  " << se << endl;
         return 0;
     }
    if( ss>=qs && se<=qe )
    {
        int s = tree[cn].sum + (se-ss+1)*carry;
        //cout << " cn " << cn << " treesum " << tree[cn].sum << " carry " << carry << " s " << s << endl; ;
        return s;
    }
    int mid = (ss+se)/2;
    int p1 = query_tree( cn*2, ss, mid, qs, qe, carry + tree[cn].lazy );
    int p2 = query_tree( cn*2 + 1, mid + 1, se, qs, qe, carry + tree[cn].lazy );
    //cout << "p1 " << p1 << " p2 " << p2 << " p1+p2 " << p1+p2<<endl;
    return (p1+p2);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for( int i = 1; i <= n; i++ )
        scanf("%d", &ara[i]);
    build_tree(1,1,n);
    //for( int i = 1; i <= 9; i++ )
        //cout << "   " << tree[i].sum << endl;
    update_tree( 1,1,n,1,n,1 );
    printf("%d\n", query_tree( 1, 1, n, 1, 3, 0 ));
    return 0;
}
