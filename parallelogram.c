# include <stdio.h>

int main ( void )
{
    int l = 0, /* Line */
        w = 0, /* Width */
        i = 0,
        tmp = 0; /* Temp */
    
    printf ( "Input the height of parallelogram: " );
    scanf ( "%d", &l );
    printf ( "Input the width of parallelogram: " );
    scanf ( "%d", &w );
    
    for ( i = 1; i <= l; i++ )
    {
        for ( tmp = l; tmp >= i; tmp-- )
            printf ( " " );
        for ( tmp = 1; tmp <= w; tmp++ )
            printf ( "@" );
        printf ( "\n" );
    }
    return 0;
}
