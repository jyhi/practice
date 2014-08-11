/* A program to output 10 lines' Pascal's triangle.
 * I may improve it to let it output any lines of Pascal's triangle.
 */
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main ( void )
{
    int i = 1, /* line */
        j = 1, /* col */
        yh[11][11], /* array */
        tmp = 0;
    memset ( yh, 0, sizeof ( yh ) );
    
    yh[1][1] = 1;
    for ( i = 2; i <= 10; i++ )
    {
        yh[i][1] = 1;
        yh[i][i] = 1;
        for ( j = 2; j < i; j++ )
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
    }
    
    for ( i = 1; i <= 10; i++ )
    {
        for ( tmp = 1; tmp <= 30 - i * 3; tmp++ )
            printf ( " " );
        for ( j = 1; j <= i; j++ )
            printf ( "%6d", yh[i][j] );
        printf ( "\n" );
    }
    return 0;
}
