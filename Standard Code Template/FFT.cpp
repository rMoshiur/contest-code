#include<bits/stdc++.h>

using namespace std;

const long double PI = 3.141592653589793238462;
const int MAXSIZE = 1048577;

struct Complex
{
    long double real, imag;
    Complex(long double a = 0 , long double b = 0)
    {
        real = a;
        imag = b;
    }
    Complex operator*( const Complex &c )
    {
        Complex ans( real*c.real - imag*c.imag, real*c.imag+imag*c.real );
        return ans;
    }
    Complex operator+( const Complex &c )
    {
        Complex ans( real+c.real, imag+c.imag );
        return ans;
    }
    Complex operator-( const Complex &c )
    {
        Complex ans( real-c.real, imag-c.imag );
        return ans;
    }
    void print()
    {
        cout << setprecision(6) << fixed << real << " + " << imag << "i" << endl;
    }
};

Complex fa[MAXSIZE], fb[MAXSIZE], tft[MAXSIZE];
int bitRevPer[MAXSIZE];

void fft( Complex a[], int n, bool invert )
{
    int c = 2;
    bitRevPer[0] = 0;
    bitRevPer[1] = 1;
    while(true)
    {
        for( int i = 0; i < c; i++ ) bitRevPer[i] <<= 1;
        int t = c+c;
        for( int i = c; i < t; i++ )  bitRevPer[i] = bitRevPer[i-c]+1;
        c = t;
        if( c >= n ) break;
    }
    for( int i = 0; i < n; i++ ) tft[i] = a[ bitRevPer[i] ];
    for( int i = 0; i < n; i++ ) a[i] = tft[i];

    for( int blocksize = 2; blocksize <= n; blocksize <<= 1 )
    {
        int halfblock = blocksize>>1, blockcnt = n/blocksize;
        long double ang = 2*PI/blocksize;
        if( invert ) ang = -ang;
        Complex w(1), wMul( cos(ang), sin(ang) );

        for( int i = 0; i < halfblock; i++ )
        {
            int ind = 0;
            for( int j = 0; j < blockcnt; j++ )
            {
                tft[i+ind] = a[i+ind] + w*a[i+ind+halfblock];
                tft[i+ind+halfblock] = a[i+ind] - w*a[i+ind+halfblock];
                ind += blocksize;
            }
            w = w*wMul;
        }
        for( int i = 0; i < n; i++ )
        {
            a[i] = tft[i];
            if( invert ) a[i].real/=2;
        }

    }

    //if( invert ) for( int i = 0; i < n; i++ ) a[i].real/= n;
}

int multiply( long long a[], long long b[], long long c[], int sz )
{
    int n = 1;
    for( int i = 0; i < sz; i++ )
    {
        fa[i].real = a[i];
        fb[i].real = b[i];
    }
    while( n <= sz ) n <<= 1;
    n <<= 1;
    fft( fa, n, false );
    fft( fb, n, false );
    for( int i = 0; i < n; i++ ) fa[i] = fa[i]*fb[i];
    fft( fa, n, true );
    for( int i = 0; i < n; i++ )
    {
        c[i] = fa[i].real + 0.5;
    }
    return n;
}

int main()
{
    long long a[100], b[100],  c[100], sz = 20, x = -1;
    for( int i = 1; i <= sz; i+=2 )
    {
        a[(i-1)/2] = i*x;
        b[ (i-1)/2 ] = i*x;
        x *= -1;
    }
    int n = multiply( a, b, c, 10 );
    for( int i = 0; i < n; i++ )
    {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
