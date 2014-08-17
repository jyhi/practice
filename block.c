# include <stdio.h>
# include <stdlib.h>

int main ( void )
{
    int  n = 0,
         tmp = 0,
         *blks = NULL;
    FILE *fi = fopen ( "block.in", "r" ),
         *fo = fopen ( "block.out", "w" );
    
    fscanf ( fi, "%d", &n );
    blks = ( int * ) calloc ( n, sizeof ( int ) );
    for ( tmp = 0; tmp < n; tmp++ )
        fscanf ( fi, "%d", &blks[tmp] );
    
    for ( tmp = 0; tmp < n; tmp++ )
    {
        
    
    return 0;
}
