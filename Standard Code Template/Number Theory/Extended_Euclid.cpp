///EXTENDED EUCLID O(logn)
//computes x, y, gcd(a,b) for the equation "ax + by = gcd(a,b)"

long long g, x, y;
void extendedEuclid( long long a, long long b)
{
    if(b == 0)
    {
        g = a;
        x = 1;
        y = 0;
        return;
    }
    extendedEuclid( b, a%b );
    long long temp = x;
    x = y;
    y = temp - (a/b)*y;
    return;
}
