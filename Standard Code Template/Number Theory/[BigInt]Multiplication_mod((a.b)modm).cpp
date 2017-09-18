///MULMOD O(logn)
//determone (a*b)%mod taking into account that a*b might overflow ( here b = 2^b1 + 2^b2 + 2^b3 +.... )

long long mulmod( long long a, long long b, long long mod )
{
    long long x = 0, y = a%mod;
    while( b > 0 )
    {
        if(b&1)
            x = (x+y)%mod;
        y = (y*2)%mod;
        b /= 2;
    }
    return x%mod;
}
