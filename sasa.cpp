#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int>m;
    m.insert( make_pair(1,12) );
    m.insert( make_pair(2, 13) );
    m.insert( make_pair(3, 14) );
    m.insert( make_pair(4, 15) );
    m.insert( make_pair(5, 16) );
    auto a = m.begin();
    cout << a->first << "  " << a->second << endl;
    m.erase(a);
    a = m.begin();
    a+=2;
    cout << a->first << "  " << a->second << endl;
    return 0;
}
