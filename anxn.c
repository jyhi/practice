/* A practice to calculate T = a0 + a1x^1 + a2x^2 + ... + anx^n */
# include <stdio.h>
# include <stdlib.h>
/* # include <math.h> */

int main ( void )
{
    int n = 0,
        x = 0,
        *a,
        t = 0,
        tmp = 0;
    
    puts ( "n x" );
    scanf ( "%d %d", &n, &x );
    
    a = ( int * ) calloc ( n + 1, sizeof ( int ) );
    printf ( "a[] from 0 to %d\n", n );
    for ( tmp = 0; tmp <= n; tmp++ )
        scanf ( "%d", &a[tmp] );
    
    /* General algorithm
    for ( tmp = n; tmp >= 1; tmp-- )
        t += a[tmp] * pow ( x, tmp );
    t += a[0];
    */
    
    /* Qin Jiushao algorithm, also Horner algorithm, the so-called
     *   Tsin ling lung kae fang, has less computation:
     *   N times plus and N times multiple.
     */
    t = a[n];
    for ( tmp = ( n - 1 ); tmp >= 0; tmp-- )
        t = t * x + a[tmp];
    
    printf ( "%d", t );
    return 0;
}
