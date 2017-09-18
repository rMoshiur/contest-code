#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        bool flag = 1;
        scanf("%d", &n);
        getchar();
        string s;
        int c = 1;
        vector<string> str(n);
        vector<int>vec(n);
        int low = 15, high = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> str[i];
            vec[i] = str[i].size();
            if( vec[i] < low ) low = vec[i];
            if( vec[i] > high ) high = vec[i];
        }
        vector< map<string,int> > ans(11);
        map<string, int>::iterator it;
        //cout << "yes\n";
        for( int i = low; i <= high && flag == 1; i++ )
        {
            for( int j = 0; j < n && flag == 1; j++ )
            {
                s = str[j].substr(0, i);
                it = ans[i].find(s);
                if( it != ans[i].end() && (vec[j] == i || it->second == i) )
                {

                    //cout << s << endl << str[j] <<endl;
                    flag = 0;
                    break;
                }
                ans[i].insert( pair<string,int>(s,vec[j]) );
                c++;
            }
        }
        if( flag == 1 ) printf("Case %d: YES\n", caseno++);
            else
            printf("Case %d: NO\n", caseno++);
    }
    return 0;
}
