# include <stdio.h>
# include <stdlib.h>

int main ( void )
{
    int n = 0, tmp = 0;
    
    scanf ( "%d", &n );
    for ( tmp = 0; tmp < n; tmp++ )
    {
        if ( ( tmp % 7 == 0 ) || ( tmp % 10 == 7 ) || ( tmp / 10 == 7 ) )
            continue;
        else
            printf ( "%5d", tmp );
    }
    return 0;
}
