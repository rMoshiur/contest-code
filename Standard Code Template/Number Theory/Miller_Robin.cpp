///MILLER-ROBIN O(k*logn)
//determine if a number is prime

int is_prime( long long n )
{
    if( n == 2 )
        return 1;
    if( n % 2 == 0 )
        return 0;
    long long d = n-1;
    while(d%2==0)
    {
        d/=2;
    }
    int test[] = {2,3,5,7,11,13,17,19,23,29};
    for( int i = 0; i < 10; i++ )
    {
        unsigned long long x = test[i]%(n-2), temp = d;
        if(x < 2) x += 2;
        //use mulmod() in exponentiation for n>1e9
        long long a = exponentiation(x,d,n);
        while( temp != n-1 && a != 1 && a != n-1 )
        {
            a = mulmod(a,a,n);
            temp *= 2;
        }
        if( a != n-1 && temp%2==0 )
            return 0;
    }
    return 1;
}
