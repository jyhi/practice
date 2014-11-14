# include <stdio.h>
# include <stdlib.h>

int main ( void )
{
    int  n = 0, na = 0, nb = 0,
         tmp = 0,                 /* TEMP use */
         sa = 0, sb = 0,          /* Score of A & B */
         *pa = NULL, *pb = NULL; /* Player A & B */
    FILE *fi = fopen ( "rps.in" , "r" ),
         *fo = fopen ( "rps.out", "w" );
    
    fscanf ( fi, "%d %d %d", &n, &na, &nb );
    pa = calloc ( na, sizeof ( int ) );
    pb = calloc ( nb, sizeof ( int ) );
    
    for ( tmp = 0; tmp < na; tmp++ )
        fscanf ( fi, "%d", &pa[tmp] ); /* Player A reading */
    for ( tmp = 0; tmp < nb; tmp++ )
        fscanf ( fi, "%d", &pb[tmp] ); /* Player B reading */
    
    /* Go You! */
    for ( tmp = 0; tmp < n; tmp++ )
    {
        
    }
}