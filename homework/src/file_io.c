#include <stdio.h>
#include "file_io.h"

int read_numbers( const char *filename, int *numbers, int max_count )
{
    FILE *file = fopen(filename, "r");
    if ( !file )
    {
        perror("Greška pri otvaranju datoteke");
        return -1;  // Vraća -1 u slučaju greške
    }

    int count = 0;
    while ( count < max_count && fscanf( file, "%d", &numbers[count] ) == 1 )
        count++;

    if ( ferror( file ) )
    {
        perror( "Greška pri čitanju datoteke" );
        fclose( file );
        return -1;
    }

    fclose( file );
    return count;
}


int write_result( const char *filename, float result )
{
    FILE *file = fopen( filename, "a" );
    if ( !file ) {
        perror( "Greška pri otvaranju datoteke" );
        return -1;
    }

    if ( fprintf( file, "%f\n", result ) < 0 )
    {
        perror( "Greška pri pisanju u datoteku" );
        fclose( file );
        return -1;
    }
    
    fclose( file );
    return 0;
}

