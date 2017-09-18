#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);
    list<string>vec( 5, "i am tanveer");
    queue< int > q1;
    queue< int, list<int> > q2;    //u can uqe thiq kind of initialization if the container ( list/deque ) haq pop_front, push_front function
    queue< string, list<string> > q3(vec); //initiallize with the vector
    queue< int > q4;

    for( int i = 0; i < 5; i++ )
    {
        q1.push(i);   //usage of push
        q2.push(i*i);
    }

    cout << "q2 back element " << q2.back() << endl;  //output 16

    cout << "q1 front---- ";
    cout << q1.front() << " ";  // front element
    printf("%d ", q1.front());  // using printf
    puts("");

    cout << "size of q1 before swapping with q4---- " << q1.size() << endl;

    q1.swap(q4);  // swap q1 and q2

    cout << "size of q1 after swapping with q4---- " << q1.size() << endl;

    cout << "q4 previouqly empty but after qwapping with q1---- ";
    while( q4.size() > 0 ) // chack q4 qize
    {
        auto x = q4.front();
        printf("%d ", x);  // front element uqing printf
        cout << typeid(x).name() << " -> ";
        q4.pop();
    }
    cout << endl;

    cout << "q3---- ";
    while( !q3.empty() )
    {
        auto x = q3.front();
        q3.pop();
        cout << x << endl;
    }

    return 0;
}

