///EUCLID O(logn)
//computes gcd(a,b)
long long gcd( long long a, long long b )
{
    b == 0? return a: return gcd( b, a%b );
}
