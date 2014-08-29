/* aminusb.c revised version 1 (aminusb-1.c)
 * This is a program to calculate some expressions like:
 *
 *   1/3-1/2
 *   10/4-2/2
 *   3/2-1/2
 *
 * NOTICE: This is a problem in NOIP2010 FCF.
 * This is a simple version, for it uses fscanf to take numbers out, and uses Euclidean algorithm to calculate greatest common divisor.
 * See also: aminusb.c ("Extreme complicated version")
 */
# include <stdio.h>
# include <stdlib.h>

void gcd ( unsigned long *output, unsigned long n1, unsigned long n2 );

int main ( void )
{
    int           n = 0;          /* First line in *fi */
    unsigned long common = 0;     /* Largest common divisor */
    FILE *fi = fopen ( "aminusb.in", "r" ),  /* Input file */
         *fo = fopen ( "aminusb.out", "w" ); /* Output file */

    fscanf ( fi, "%d", &n );

    for ( unsigned long tmp = 0, a1 = 0, a2 = 0, /* The 1st fraction: a1 / a2 */
                                 b1 = 0, b2 = 0, /* The 2nd fraction: b1 / b2 */
                                 t1 = 0, t2 = 0; /* The sum fraction: t1 / t2 */
                                 tmp < n; tmp++ )
    {
        /* Input */
        fscanf ( fi, "%lu/%lu-%lu/%lu", &a1, &a2, &b1, &b2 );

        /* Calculate */
        if ( a2 != b2 )
        {
            /*   10000     1000
             *   -----  -  ----
             *   19683 <=> 6561
             *
             * Reduce the fractions to a common if denominators are not the same
             */
            a1 *= b2;
            b1 *= a2;
            a2 *= b2;
            /* b2 = a2; */
        }
        t1 = a1 - b1;
        t2 = a2;

        /* Calculate the greatest common divisor */
        gcd ( &common, t1, t2 );
        
        /* Reduce the sum fraction to its lowest terms */
        if ( common != 0 )
        {
            t1 /= common;
            t2 /= common;
        }

        /* Output. Finally. QAQ */
        if ( ( t1 != t2 ) && ( t2 != 1 ) )
        {
            if ( t1 != 0 )
                fprintf ( fo, "%lu/%lu\n", t1, t2 );
            else
                fprintf ( fo, "0\n" );
        }
        else
            fprintf ( fo, "%lu\n", t1 );
    }

    fclose ( fi );
    fclose ( fo );

    return 0;
}

void gcd ( unsigned long *output, unsigned long n1, unsigned long n2 )
{
    do
    {
        if ( n1 > n2 )
            n1 = n1 - n2;
        else
            n2 = n2 - n1;
    } while ( ( n2 != 0 ) && ( n1 != 0 ) );

    if ( n2 == 0 )
        *output = n1;
    else
        *output = n2;
}