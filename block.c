# include <stdio.h>

int main ( void )
{
    int n = 0,
        c = 0, /* Counter */
        *blks = NULL,
        s = 0, e = 0, /* Start && end */
        tmp = 0, stmp = 0;
    FILE *fi = fopen ( "block.in", "r" ),
         *fo = fopen ( "block.out", "w" );
    
    fscanf ( fi, "%d", &n );
    blks = ( int * ) calloc ( n, sizeof ( int ) );
    for ( tmp = 0; tmp < n; tmp++ )
        fscanf ( fi, "%d", &blks[tmp] );
    
    do
    {
        for ( tmp = 0; tmp < n; tmp++ )
        {
            if ( blks[tmp] != 0 )
            {
                for ( stmp = tmp; stmp < n; stmp++ )
                {
                    if ( blks[stmp] == 0 )
                        c++;
                }
           }
        }
        if ( blks[n - 1] != 0 )
            c++;
        
        for ( tmp = 0; tmp < n; tmp++ )
            blks[tmp] -= 1;
    } while ( ... );
    
    return 0;
}
