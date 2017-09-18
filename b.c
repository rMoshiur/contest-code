#include <stdio.h>

int is_pow_of_two( int n )
{
    if( (n&(n-1)) == 0 )
        return 1;
    return 0;
}

int main()
{
    int a;
    scanf("%d", &a);
    if( is_pow_of_two(a) )
        printf("%d is a power of two\n", a);
    else
        printf("%d is not a power of two\n", a);
    return 0;
}
