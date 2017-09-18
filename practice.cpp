#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    v = {1,2,3,4,56,87,7,8};
    sort(v.begin(), v.end());
    for( auto x: v )
        cout << x << endl;
        cout << "x" << " \n"[1];
    sort( v.begin(), v.end(), [](int a, int b){ return a > b; } );
    for( auto x: v )
        cout << x << endl;
    return 0;
}
