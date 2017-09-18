/*
 * Algorithm : Fast Fourier Transform
 * Order : O( Nlog )
 */
#include<bits/stdc++.h>
using namespace std;

typedef vector<long long> VL;
typedef complex<double> CN;
const double PI = 2*acos( 0.0 );

void FFT( vector<CN> &a, bool invert ){
    long i,j,n = a.size();
    for( i=1,j=0;i<n;i++ ){
		long bit = n >> 1 ;
		for( ;j>=bit;bit>>=1 ) j -= bit ;
		j += bit ;
		if( i < j ) swap( a[i],a[j] );
	}
	long len;
	for( len=2;len<=n;len<<=1 ){
	    double ang = 2*PI / len * ( invert ? -1:1 );
	    CN wlen( cos( ang ) , sin( ang ) );
		for( i=0;i<n;i+=len ){
			CN w( 1 ) ;
			for( j=0;j<len/2;j++ ){
				CN u = a[i+j] , v = a[i+j+len/2]*w;
				a[i+j] = u+v; a[i+j+len/2] = u-v; w *= wlen;
			}
		}
	}
	if( invert ){
	    for( i=0;i<n;i++ ) a[i] /= n;
	}
}

void Multiply( const VL &a, const VL &b, VL &res ){
    vector<CN> fa( a.begin(),a.end() ), fb( b.begin(),b.end() );
	long i,n = 1 ;
	while( n < max( a.size(),b.size()) ) n <<= 1;
	n <<= 1;
	fa.resize( n ),fb.resize( n );
	FFT( fa,false ) , FFT( fb,false );
	for( i=0;i<n;i++ ) fa[i] *= fb[i];
	FFT( fa,true );
	res.resize( n );
	for( i=0;i<n;i++ ) res[i] = long( fa[i].real() + 0.5 );
}


int main()
{
    vector<long long>v1;
    vector<long long>v2;
    v1.push_back(1);
    v1.push_back(43);
    v1.push_back(21);
    v2.push_back(5435);
    v2.push_back(142);
    v2.push_back(1442);
    vector<long long>res;
    Multiply( v1, v2, res );
    for( int i = 0; i < res.size(); i++ )
        cout << res[i] << " ";
}
