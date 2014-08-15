# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main ( void )
{
    int   t = 0,
          tmp = 0,
          *num = ( int * ) calloc ( 512, sizeof ( int ) );
    char  *expr = ( char * ) calloc ( 512, sizeof ( char ) );
    FILE  *fi = fopen ( "expr.in", "r" ),
          *fo = fopen ( "expr.out", "w" );
    
    fscanf ( fi, "%s", expr );
    
    for ( tmp = 0; tmp < strlen ( expr ); tmp++ )
    {
        if ( ( expr[tmp] >= '0' ) && ( expr[tmp] <= '9' ) )
            num[tmp] = ( int ) expr[tmp] - '0';
    }
    
    for ( tmp = 0; tmp < strlen ( expr ); tmp++ )
    {
        if ( expr[tmp] == '*' )
        {
            num[tmp + 1] = num[tmp - 1] * num[tmp + 1];
            num[tmp - 1] = 0;
        }
    }
    
    for ( tmp = 0; tmp < strlen ( expr ); tmp++ )
    {
        if ( expr[tmp] == '+' )
        {
            num[tmp + 1] = num[tmp - 1] + num[tmp + 1];
            num[tmp - 1] = 0;
        }
    }
    
    for ( tmp = 0; tmp < strlen ( expr ); tmp++ )
        t += num[tmp];
    
    fprintf ( fo, "%d", t );

    fclose ( fi );
    fclose ( fo );
    return 0;
}
