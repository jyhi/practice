# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void fill ( int l, int c, int n );
void print ( int l, int c, int n );

int a[31][31]; /* Data */

int main ( void )
{
    int l = 0, /* 行指示 line */
        c = 0, /* 列指示 col*/
        n = 0; /* N */

    memset ( a, 0, sizeof ( a ) ); /* Initialize */

    scanf ( "%d", &n );

    fill ( l, c, n );
    print ( l, c, n );

    return 0;
}





void fill ( int l, int c, int n )
{
    int tmp = 2; /* 临时以及顺序数生成 */
    a[1][n] = 1;

    for ( l = 2; l <= n; l++ ) /* 上部分 */
    {
        if ( l % 2 == 0 )
        { /* 逆序 */
            for ( c = n; c >= ( n + 1 - l ); c--, tmp++ )
                a[l][c] = tmp;
        }
        else
        { /* 正序 */
            for ( c = ( n + 1 - l ); c <= n; c++, tmp++ )
                a[l][c] = tmp;
        }
    }

    for ( l = ( n + 1 ); l <= ( 2 * n - 1 ); l++ ) /* 下部分 */
    {
        if ( l % 2 == 0 )
        { /* 逆序 */
            for ( c = n; c >= ( l - n + 1 ); c--, tmp++ )
                a[l][c] = tmp;
        }
        else
        { /* 正序 */
            for ( c = ( l - n + 1 ); c <= n; c++, tmp++ )
                a[l][c] = tmp;
        }
    }
}





void print ( int l, int c, int n )
{
    int tmp = 1; /* 临时以及顺序数生成 */

    for ( l = 1; l <= n; l++ ) /* 上部分 */
    {
        for ( tmp = 1; tmp <= n*3-l*3; tmp++ )
            printf ( " " );
        for ( c = n; c >= ( n - l + 1 ); c-- )
            printf ( "%-6d", a[l][c] );
        printf ( "\n" );
    }
    for ( l = ( n + 1 ); l <= ( 2 * n - 1 ); l++ ) /* 下部分 */
    {
        for ( tmp = 1; tmp <= l*3-n*3; tmp++ )
            printf ( " " );
        for ( c = n; c >= ( l - n + 1 ); c-- )
            printf ( "%-6d", a[l][c] );
        printf ( "\n" );
    }
}
