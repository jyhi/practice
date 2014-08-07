# include <stdio.h>

int main ( void )
{
    int n = 0,
        c = 0, /* Counter */
        i = 0,
        tmp = 0;
    
    scanf ( "%d", &n );
    
    for ( tmp = 1;; tmp++ )
    {
        for ( i = 1, c = 0; i <= tmp; i++ )
        {
            if ( tmp % i == 0 )
                c++;
        }
        
        if ( c == n )
        {
            printf ( "%d", tmp );
            return 0;
        }
    }

    return 0;
}
