/* This is a program to calculate some expressions like:
 *
 *   1/3-1/2
 *   10/4-2/2
 *   3/2-1/2
 *
 * NOTICE: This is a problem in NOIP2010 FCF.
 * This is an extreme complicated version, for it traverses every expressions and take numbers out.
 * Actually it can be easier, for using fscanf(fi, "%d/%d-%d/%d", ...) is okay.
 */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LENGTH 512

int main ( void )
{
    /* I think these may be a waste of memory... */
    int  n = 0,          /* First line in *fi */
         tmp = 0,        /* 1st temp */
         stmp = 0,       /* 2nd temp */
         ttmp = 0,       /* 3rd temp */
         common = 0,     /* Largest common divisor */
         c = 1,          /* Counter */
         f_or_b = 0,     /* Front or back? ( enum? BOOL? ) */
         sub_pos = 0,    /* Position of the subtraction sign */
         a1 = 0, a2 = 0, /* The 1st fraction: a1 / a2 */
         b1 = 0, b2 = 0, /* The 2nd fraction: b1 / b2 */
         t1 = 0, t2 = 0; /* The sum fraction: t1 / t2 */
    char **expr = NULL;  /* Group to save the expressions */
    FILE *fi = fopen ( "aminusb.in", "r" ),  /* Input file */
         *fo = fopen ( "aminusb.out", "w" ); /* Output file */

    fscanf ( fi, "%d", &n );
    expr = ( char ** ) calloc ( n, sizeof ( char * ) );
    for ( tmp = 0; tmp < n; tmp++ )
        expr[tmp] = ( char * ) calloc ( LENGTH, sizeof ( char ) );
    for ( tmp = 0; tmp < n; tmp++ )
        fscanf ( fi, "%s", expr[tmp] ); /* Oh fsck I should use scanf("%d/%d-%d/%d", ...) */

    /* Go You! */
    /* Traverse from 1st expression to the last */
    for ( tmp = 0; tmp < n; tmp++ )
    {
        /* Traverse from the head of expression to the tail */
        for ( stmp = 0, f_or_b = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0, t1 = 0, t2 = 0; stmp < strlen ( expr[tmp] ); stmp++ )
        {
            if ( expr[tmp][stmp] == '-' )
            {
                f_or_b = 1; /* Enter the back */
                sub_pos = stmp; /* Position of the subtraction sign */
                while ( expr[tmp][stmp - 1] != '/' ) /* a2 */
                {
                    /* Traverse from an opposite direction to get numbers:
                     *         <----
                     *   10000/19683-1000/6561
                     *         ^ a2
                     */
                    a2 += ( ( int ) expr[tmp][stmp - 1] - '0' ) * c;
                    c *= 10;
                    stmp--;
                }
                c = 1;
                stmp = sub_pos; /* Restore the pointer */
            }
            if ( expr[tmp][stmp] == '/' )
            {
                if ( f_or_b == 0 )
                {
                    for ( ttmp = stmp - 1; ttmp >= 0; ttmp-- ) /* a1 */
                    {
                        /* <----
                         * 10000/19683-1000/6561
                         * ^ a1
                         */
                        a1 += ( ( int ) expr[tmp][ttmp] - '0' ) * c;
                        c *= 10;
                    }
                    c = 1;
                }
                else
                {
                    for ( ttmp = stmp - 1; ttmp > sub_pos; ttmp-- ) /* b1 */
                    {
                        /*             <---
                         * 10000/19683-1000/6561
                         *             ^ b1
                         */
                        b1 += ( ( int ) expr[tmp][ttmp] - '0' ) * c;
                        c *= 10;
                    }
                    c = 1;
                }
            }
        }
        while ( expr[tmp][stmp - 1] != '/' ) /* b2 */
        {
            /*                  <---
             * 10000/19683-1000/6561
             *                  ^ b2
             */
            b2 += ( ( int ) expr[tmp][stmp - 1] - '0' ) * c;
            c *= 10;
            stmp--;
        }
        c = 1;

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
            b2 = a2;
        }
        t1 = a1 - b1;
        t2 = a2;

        /* Calculate the largest common divisor */
        if ( t1 < 0 ) /* Numerator is negative */
        {
            t1 = 0 - t1;
            for ( stmp = 1; stmp <= t1; stmp++ )
            {
                if ( ( t1 % stmp == 0 ) && ( t2 % stmp == 0 ) )
                    common = stmp;
            }
            t1 = 0 - t1;
        }
        else
        {
            /* Oh oh I repeat it... */
            for ( stmp = 1; stmp <= t1; stmp++ )
            {
                if ( ( t1 % stmp == 0 ) && ( t2 % stmp == 0 ) )
                    common = stmp;
            }
        }
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
                fprintf ( fo, "%d/%d\n", t1, t2 );
            else
                fprintf ( fo, "0\n" );
        }
        else
            fprintf ( fo, "%d\n", t1 );
    }

    fclose ( fi );
    fclose ( fo );

    return 0;
}
