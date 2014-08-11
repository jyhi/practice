# include <stdio.h>

void convert ( unsigned long n, unsigned long k, unsigned long s );

int main ( void )
{
    unsigned long n = 0, /* Number to be converted */
                  k = 0, /*  */
                  s = 0;
    
    scanf ( "%lu %lu", &n, &k );
    
    convert ( n, k, s );
    
    return 0;
}

void convert ( unsigned long n, unsigned long k, unsigned long s )
{
    s = n % k;
    if ( n / k != 0 )
        convert ( n / k, k, s );
    printf ( "%lu", s );
}
