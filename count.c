# include <stdio.h>
# include <stdlib.h>

void QuickSort ( int l, /* ^HEAD */
                 int r  /* ^TAIL */ );

int *a;

int main ( void )
{
    int n = 0,
        c = 0, /* Counter */
        tmp = 0;
    FILE *fi = fopen ( "count.in", "r" ),
         *fo = fopen ( "count.out", "w" );
    
    fscanf ( fi, "%d", &n );
    /* Numbers still remain in stdin */
    a = calloc ( n + 1, sizeof ( int ) );
    for ( tmp = 0; tmp < n; tmp++ )
        fscanf ( fi, "%d", &a[tmp] );
    
    a[n] = 0; /* No over run. */
    
    /* Go You! */
    /* Quick Sort */
    QuickSort ( 0, n - 1 );
    
    /* Compare */
    for ( tmp = 1; tmp <= n; tmp++ ) /* Over run? No. */
    {
        if ( a[tmp] == a[tmp - 1] )
            c++;
        else
        {
            /* Print first */
            fprintf ( fo, "%d %d\n", a[tmp - 1], c + 1 ); /* The first number */
            /* c = 0 */
            c = 0;
            /* Go on */
            continue;
        }
    }
    
    fclose ( fi );
    fclose ( fo );
    return 0;
}

void QuickSort ( int l, /* ^HEAD */
                 int r  /* ^TAIL */ )
{
    int temp = 0,
        i = l,
        j = r,
        mid = a[ ( l + r ) / 2 ];
    
    do
    {
        while ( a[i] < mid )
            i++;
        while ( a[j] > mid )
            j--;
        if ( i <= j )
        {
            /* Exchange */
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
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
