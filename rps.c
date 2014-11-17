/* rps.c: CCF NOIP 2014 day.1 */
# include <stdio.h>
# include <stdlib.h>

int main ( void )
{
    int  n = 0, na = 0, nb = 0,   /* N, NA, NB */
         tmp = 0,                 /* TEMP use */
         sa = 0, sb = 0,          /* Score of A & B */
         *pa = NULL, *pb = NULL;  /* Cycle of Player A & B */
    /*
    FILE *fi = fopen ( "rps.in" , "r" ),
         *fo = fopen ( "rps.out", "w" );
    */
    
    //fscanf ( fi, "%d %d %d", &n, &na, &nb );
    scanf ( "%d %d %d", &n, &na, &nb );
    pa = calloc ( na, sizeof ( int ) );
    pb = calloc ( nb, sizeof ( int ) );
    
    for ( tmp = 0; tmp < na; tmp++ )
        //fscanf ( fi, "%d", &pa[tmp] ); /* Player A reading */
        scanf ( "%d", &pa[tmp] );
    for ( tmp = 0; tmp < nb; tmp++ )
        //fscanf ( fi, "%d", &pb[tmp] ); /* Player B reading */
        scanf ( "%d", &pb[tmp] );
    
    /* Go You! */
    int a = 0, b = 0; /* Array subscript for pa and pb */
    for ( tmp = 0; tmp < n; a++, b++, tmp++ )
    {
        /* First check if tmp>na or tmp>nb to prevent overflow */
        if ( a >= na )
            a = 0;
        if ( b >= nb )
            b = 0;
        
        if ( pa[a] != pb[b] )
        {
            switch ( pa[a] )
            {
                case 0:
                    if ( ( pb[b] == 2 ) || ( pb[b] == 3 ) ) /* A win */
                        sa += 1;
                    else                                    /* B win */
                        sb += 1;
                    break;
                case 1:
                    if ( ( pb[b] == 0 ) || ( pb[b] == 3 ) ) /* A win */
                        sa += 1;
                    else                                    /* B win */
                        sb += 1;
                    break;
                case 2:
                    if ( ( pb[b] == 1 ) || ( pb[b] == 4 ) ) /* A win */
                        sa += 1;
                    else                                    /* B win */
                        sb += 1;
                    break;
                case 3:
                    if ( ( pb[b] == 2 ) || ( pb[b] == 4 ) ) /* A win */
                        sa += 1;
                    else                                    /* B win */
                        sb += 1;
                    break;
                case 4:
                    if ( ( pb[b] == 0 ) || ( pb[b] == 1 ) ) /* A win */
                        sa += 1;
                    else                                    /* B win */
                        sb += 1;
                    break;
            } /* switch ( pa[a] ) */
        } /* if ( pa[a] != pb[b] ) */
        
        /* No need to do anything if they planish. */
        
    }
    
    /* Output the result */
    //fprintf ( fo, "%d %d", sa, sb );
    printf ( "%d %d", sa, sb );
    /*
    fclose ( fi );
    fclose ( fo );
    */
    return 0;
}
