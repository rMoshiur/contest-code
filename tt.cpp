/* C++ program to find number of digits in nth
   Fibonacci number */
#include<bits/stdc++.h>
using namespace std;

// This function returns the number of digits
// in nth Fibonacci number after ceiling it
// Formula used (n * log(phi) - (log 5) / 2)
long long numberOfDigits(long long n)
{
    if (n == 1)
        return 1;

    // using phi = 1.6180339887498948
    long double d = (n * log10(1.6180339887498948)) -
                    ((log10(5)) / 2);

    return ceil(d);
}

// Driver program to test the above function
int main()
{

    cout << "Number of Digits in F("
         << 1000 <<") - "
         << numberOfDigits(10000) << "n";

    return 0;
}
