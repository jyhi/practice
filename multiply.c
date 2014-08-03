# include <stdio.h>

int main ( void )
{
    int i = 1, /* line */
        j = 1, /* col */
        tmp = 1;
    for ( i = 1; i <= 9; i++ )
    {
        for ( j = i; j <= 9; j++ )
            printf ( "%d*%d=%-2d ", i, j, i * j );
        printf ( "\n" );
        for ( tmp = 1; tmp <= i ; tmp++ )
            printf ( "       " );
    }
    return 0;
}
