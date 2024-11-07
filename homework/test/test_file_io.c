#include <stdio.h>
#include <stdlib.h>
#include "../inc/file_io.h"

// Test funkcija za `read_numbers`
void test_read_numbers()
{
    int numbers[100];
	int count = read_numbers( "input.txt", numbers, 100 );
    if ( count == -1 )
        fprintf( stderr, "Greška pri čitanju brojeva iz input.txt\n" );
    
    else
        printf( "Uspješno pročitanih brojeva: %d\n", count );
}

// Test funkcija za `write_result`
void test_write_result()
{
    float result = 123.45;

    if ( write_result( "output.txt", result ) == -1 )
        fprintf( stderr, "Greška pri pisanju rezultata u output.txt\n" );
        
    else
        printf( "Rezultat %.2f uspješno zapisan u output.txt\n", result );
}

int main()
{
    printf( "Test za `read_numbers`\n" );
    test_read_numbers();

    printf( "\nTest za `write_result`\n" );
    test_write_result();

    return 0;
}

