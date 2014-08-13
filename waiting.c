/* A quick sort practice
 * Although there is a C standard function:
 *
 *   void qsort ( void *base, int nelem, int width, int ( *fcmp ) ( const void *, const void * ) );
 *
 * I won't use it for NOIP doesn't allow anybody to use it. (But NOI does)
 */
# include <stdio.h>
# include <stdlib.h>

void QuickSort ( int l, /* ^HEAD */
                 int r  /* ^TAIL */ );

int *w; /* Waiting time */

int main ( void )
{
    int n = 0, /* People */
        tmp = 0;
    
    puts ( "n" );
    scanf ( "%d", &n );
    
    w = calloc ( n, sizeof ( int ) );
    
    printf ( "w[] from 1 to %d\n", n );
    for ( tmp = 0; tmp < n; tmp++ )
        scanf ( "%d", &w[tmp] );
    
    /* Go You! */
    QuickSort ( 0, n - 1 );
    
    /* Output */
    for ( tmp = 0; tmp < n; tmp++ )
        printf ( "%-6d", w[tmp] );
    
    return 0;
    
}

void QuickSort ( int l, /* ^HEAD */
                 int r  /* ^TAIL */ )
{
    int temp = 0,
        i = l,
        j = r,
        mid = w[ ( l + r ) / 2 ];
    
    do
    {
        while ( w[i] < mid )
            i++;
        while ( w[j] > mid )
            j--;
        if ( i <= j )
        {
            /* Exchange */
            temp = w[i];
            w[i] = w[j];
            w[j] = temp;
            /* Move pointers */
            i++;
            j--;
        }
    } while ( i <= j ); /* Until ^HEAD > ^TAIL */
    
    if ( l < j )
        QuickSort ( l, j );
    if ( i < r )
        QuickSort ( i, r );
}
