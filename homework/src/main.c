#include <stdio.h>
#include "file_io.h"
#include "compute.h"

int main()
{
	int n = 100;
	int window_size = 3;
	int numbers[ n ];
	int count = read_numbers( "input.txt", numbers, n );

	if ( count == -1 )
	{
		printf("Error - doslo je do greske prilikom citanja iz datoteke :(");
		return 1;
	}
	
	float zbroj = (float)compute_sum( numbers, count );
	float average = compute_average( numbers, count );
	float moving_average = compute_moving_average( numbers, count, window_size );
		
    write_result("output.txt", zbroj);
    write_result("output.txt", average);
    write_result("output.txt", moving_average);

    // Svi rezultati
    printf( "Zbroj: %.2f, Prosjek: %.2f, Moving Average: %.2f\n", zbroj, average, moving_average );
    

	return 0;
}

