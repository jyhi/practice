# include <stdio.h>
/*
int main ( void )
{
    unsigned int n = 0,
                 i = 0,
                 j = 0,
                 tmp = 0;
    
    scanf ( "%d", &n );
    
    for ( i = 2; i <= ( n / 2 ); i++ )
    {
        tmp = i;
        for ( j = i + 1; j <= ( ( n / 2 ) + 1 ); j++ )
        {
            // printf ( "%d + %d\n", tmp, j );
            tmp = tmp + j;
            if ( tmp == n )
            {
                printf ( "%d, %d   ", i, j );
                tmp = 0;
                break;
            }
        }
    }
    return 0;
}*/

int main ( void )
{
    unsigned long n = 0, i = 1, j = 0, tmp = 0;
    scanf ( "%lu", n );
    
    for ( tmp = 2; tmp <= n; tmp++ )
    {
        i = i + tmp;
        if ( n - /* ... */