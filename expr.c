# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LENGTH 512

# define op_left_assoc( c ) ( c == '+' || c == '-' || c == '/' || c == '*' || c == '%' )
# define is_operator( c )   ( c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=' )
# define is_function( c )   ( c >= 'A' && c <= 'Z' )
# define is_ident( c )      ( ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'z' ) )

int opr_preced ( const char c );

typedef struct /* For operators */
{
    int  top;
    char *a;
} stack;




int main ( void )
{
    stack opr = { 0, NULL }, /* Operators */
          suf = { 0, NULL }; /* Suffix notation */
    char  *s = ( char * ) calloc ( LENGTH, sizeof ( char ) ),    /* Input */
          *outq = ( char * ) calloc ( LENGTH, sizeof ( char ) ); /* Output Queue */
    int   tmp = 0,
          p = 0, /* "Pointer" for *outq  */
          t = 0; /* Total */
    
    puts ( "Input an infix notation:" );
    scanf ( "%s", s );
    opr.a = ( char * ) calloc ( LENGTH, sizeof ( char ) );
    
    /* Go You!*/
    for ( tmp = 0; tmp < strlen ( s ); tmp++ )
    {
        if ( is_ident ( s[tmp] ) )
        {
            outq[p] = s[tmp];
            p++;
        }
        else
        if ( is_operator ( s[tmp] ) )
        {
            if ( is_operator ( opr.a[opr.top] ) && opr_preced ( opr.a[opr.top] ) > s[tmp] )
            {
                /* Pop */
                outq[p] = opr.a[opr.top - 1];
                p++;
                opr.top--;
            }
            else
            {
                opr.a[opr.top] = s[tmp];
                opr.top++;
            }
        }
        /* 先不考虑括号和函数什么的 */
    }
    
    /* Put the operators inside stack into output queue */
    for ( tmp = opr.top; tmp >= 0; tmp-- )
    {
        outq[p] = opr.a[opr.top - 1];
        p++;
        opr.top--;
    }
    
    /* Calculate */
    p = 0;
    suf.a = ( char * ) calloc ( LENGTH, sizeof ( char ) );
    for ( tmp = 0; tmp < strlen ( outq ); tmp++ )
    {
        if ( is_ident ( outq[p] ) )
        {
            /* Push */
            suf.a[suf.top] = outq[p];
            p++;
            suf.top++;
        }
        else
        if ( is_operator ( outq[p] ) )
        {
            /* TODO: God knows whether there are 2 numbers or not... */
            switch ( outq[p] )
            {
                case '+':
                    t = suf.a[suf.top - 1] + suf.a[suf.top - 2];
                    break;
                case '-':
                    break; /* ... */
                case '*':
                    t = suf.a[suf.top - 1] * suf.a[suf.top - 2];
                    break;
                case '/':
                    break; /* ... */
            }
        }
    }
    
    printf ( "%d", t );
    
    return 0;
}

int opr_preced ( const char c )
{
    switch ( c )
    {
        case '!':
            return 4;
        case '*':
        case '/':
        case '%':
            return 3;
        case '+': case '-':
            return 2;
        case '=':
            return 1;
    }
    return 0;
}