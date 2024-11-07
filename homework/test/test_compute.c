#include <stdio.h>
#include "compute.h"

int test_compute_sum()
{
	int count = 5;
 	int numbers[] = {2, 3, 7, 13, 5};
 	
 	if ( compute_sum( numbers, count ) != 30 )
 		printf( "Greska - racunanje sume\n" );
	else
		count = 0;
	return count;
}

int test_compute_average()
{
	int count = 5;
 	int numbers[] = {2, 3, 7, 13, 5};
 	
 	if ( compute_average( numbers, count ) != 6 )
 		printf( "Greska - racunanje srednje vrijednosti\n" );
	else
		count = 0;
	return count;
}

int test_compute_moving_average()
{
	int count = 5;
 	int numbers[] = {2, 3, 7, 13, 5};
 	int w_size = 3;
 	
 	if ( compute_moving_average( numbers, count, w_size ) != 4 )
 		printf( "Greska - racunanje pokretne srednje vrijednosti\n" );
	else
		count = 0;
	return count;
}

int main()
{
	int a = test_compute_sum();
	int b = test_compute_average();
	int c = test_compute_moving_average();
	
	if (!(  a || b || c ))
		printf( "Svi testovi su prosli. " );
    return 0;
}
