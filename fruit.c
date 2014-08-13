# include <stdio.h>
# include <stdlib.h>

void QuickSort ( int l, /* ^HEAD */
                 int r  /* ^TAIL */ );

int *a, /* Input  */
    *b; /* Output */

int main ( void )
{
    int  n = 0,
         tmp = 0;
    FILE *fi = fopen ( "fruit.in", "r" ),
         *fo = fopen ( "fruit.out", "w" );
    
    fscanf ( fi, "%d", &n );
    a = calloc ( n, sizeof ( int ) );
    b = calloc ( n, sizeof ( int ) );
    for ( tmp = 0; tmp <= n; tmp++ )
        fscanf ( fi, "%d", &a[tmp] );
    
    /* Go You! */
    /* Quick sort (fsck >_<) */
    QuickSort ( 0, n - 1 );
    
    /* Plus */
    b[0] = a[0] + a[1];
    for ( tmp = 1; tmp <= ( n - 2 ); tmp++ ) /* NOTICE: "n" will be n but not n-1 when over */
        b[tmp] = b[tmp - 1] + a[tmp + 1];
    /* b[n - 1] will be the total */
    for ( tmp = 0; tmp <= ( n - 2 ); tmp++ )
        b[n - 1] += b[tmp];
    
    /* Print ^o^ */
    fprintf ( fo, "%u", b[n - 1] );
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
