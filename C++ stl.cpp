#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);
    vector<string>vec( 5, "i am tanveer");
    stack< int > s1;
    stack< int, vector<int> > s2;   //u can use this kind of initialization if the container ( vector/dequeue ) has pop_back, push_back function
    stack< string, vector<string> > s3(vec); //initiallize with the vector
    stack< int > s4;

    for( int i = 0; i < 5; i++ )
    {
        s1.push(i);   //usage of push
        s2.push(i*i);
    }

    cout << "s1 top---- ";
    cout << s1.top() << " ";  // top element
    printf("%d ", s1.top());  // using printf
    puts("");

    cout << "size of s1 before swapping with s4---- " << s1.size() << endl;

    s1.swap(s4);  // swap s1 and s2

    cout << "size of s1 after swapping with s4---- " << s1.size() << endl;

    cout << "s4 previously empty but after swapping with s1---- ";
    while( s4.size() > 0 ) // chack s2 size (  )
    {
        auto x = s4.top();
        printf("%d ", x);  // top element using printf
        cout << typeid(x).name() << " -> ";
        s4.pop();
    }
    cout << endl;

    cout << "s3---- ";
    while( !s3.empty() )
    {
        auto x = s3.top();
        s3.pop();
        cout << x << endl;
    }

    return 0;
}
