#include<iostream>
using namespace std;

int main()

{
    int m = 6;
    int n = ++m + ++m; //+ (++m);
    cout<<"Value of m is : " <<m<<endl;
    cout<<"Value of n is : " <<n<<endl;
    return 0;
}
