#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb         long double

char str[400005], ch[400005];
int vec[30005];
int total, c;
map<string, int>mm;
bool flag;
int ans;

void nslice()
{
    int i = 0;
    string temp;

    if( str[0] >= 'a' && str[0] <= 'z' )
        temp += str[0];
    i++;
    while(str[i])
    {
        if( (str[i] >= 'a' && str[i] <= 'z') && (str[i-1] < 'a' || str[i-1] > 'z') )
        {
            if( !temp.empty() )
            {
                if(!flag)
                    mm[temp] = total++;
                if( flag )
                    vec[c++] = mm[temp];
            }
            temp.clear();
        }
        if( str[i] >= 'a' && str[i] <= 'z' )
            temp += str[i];
        i++;
    }
    if( !temp.empty() )
    {
        if(!flag)
            mm[temp] = total++;
        if(flag)
            vec[c++] = mm[temp];
        //vec.pb(mm[temp]);
    }
}

void merge_srt( int s, int e )
{
    if(s==e)
    {
        return;
    }
    int m = (s+e)/2;
    merge_srt(s, m);
    merge_srt(m+1,e);
    int len = e-s+1, i=s, j=m+1;
    int aa[len], x=0;
    //cout << "s " << s << " e " << e << endl;
    //what_is(ans);
    while(x <len)
    {
        if( i > m )
        {
            while(j<=e)
                aa[x++] = vec[j++];
            break;
        }
        if( j > e )
        {
            while(i<=m)
                aa[x++] = vec[i++];
            break;
        }
        if( vec[i] < vec[j] )
        {
            aa[x++] = vec[i++];
        }
        else
        {
            aa[x++] = vec[j++];
            ans += (m-i+1);
        }
    }
    int k = s;
    for( int i = 0; i < len ; i++ )
        vec[k++] = aa[i];
    return;
}


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        total = 1, c = 1;
        int n;
        scanf("%d\n", &n);
        gets(ch);
        gets(str);
        flag = 0;
        nslice();
        strcpy(str, ch);
        flag = 1;
        nslice();
        ans = 0;
        merge_srt(1, c-1);
        printf("%d\n", ans);
    }

    return 0;
}




