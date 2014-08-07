# include <stdio.h>

void move ( int n, char z1, char z2, char z3 );

int main ( void )
{
    int total = 0;
    
    printf ( "Enter the number of disks in Hanoi Tower: " );
    scanf ( "%d", &total );
    move ( total, 'A', 'B', 'C' );
    
    return 0;
}

void move ( int n, char z1, char z2, char z3 )
{
    if ( n == 1 )
        printf ( "%c -> %c\n", z1, z3 );
    else
    {
        move ( n - 1, z1, z3, z2 );
        printf ( "%c -> %c\n", z1, z3 );
        move ( n - 1, z2, z1, z3 );
    }
}
