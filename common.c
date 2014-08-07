/* Largest common divisor & Minimum common multiple */
# include <stdio.h>

int lcdiv ( int n, int m, int i );
int mcmul ( int n, int m, int j );

int main ( void )
{
    int n = 0, /* Input 1 */
        m = 0, /* Input 2 */
        i = 0, /* Largest common divisor */
        j = 0; /* Minimum common multiple */
    
    scanf ( "%d %d", &n, &m );
    
    i = lcdiv ( n, m, i );
    j = mcmul ( n, m, j );

    printf ( "Largest common divisor: %d\nMinimum common multiple: %d", i, j );
    return 0;
}

int lcdiv ( int n, int m, int i )
{
    int tmp = 0;
    for ( tmp = 1; tmp <= n; tmp++ )
        if ( ( n % tmp == 0 ) && ( m % tmp == 0 ) )
            i = tmp;
    return i;
}

int mcmul ( int n, int m, int j )
{
    int tmp = 0;
    for ( tmp = n;; tmp++ )
    {
        if ( ( tmp % n == 0 ) && ( tmp % m == 0 ) )
        {
            j = tmp;
            break;
        }
    }
    return j;
}
