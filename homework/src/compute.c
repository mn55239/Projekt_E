#include "compute.h"

int compute_sum( const int *numbers, int count )
{
	int sum = 0;
	for ( int i = 0; i <= count - 1; i++ )
		sum += numbers[ i ];
	
	return sum;
}

float compute_average( const int *numbers, int count )
{
	if ( count == 0 ) return 0.0f;
	
	int sum = compute_sum( numbers, count );
	return (float)sum / count;
}

float compute_moving_average( const int *numbers, int count, int window_size )
{
	if ( window_size == 0 || window_size > count ) return 0.0f;
	
	int sum = 0;
	for ( int i = 0; i < window_size; i++ )
		sum += numbers[ i ];
	
	return (float)sum / window_size;
}
