#include <bits/stdc++.h>

using namespace std;

void print( int ara[], int k )
{
    for(int i = 0; i < k; i++)
    {
        cout << ara[i] << " " ;
    }
    cout << endl;
    return;
}

void combi( int par[], int temp[], int n, int k, int &cur )
{
    if( k == cur )
    {
        print( temp, k );
        return;
    }

}
