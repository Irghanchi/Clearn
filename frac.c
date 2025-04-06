#include <stdio.h>

#define po 50

typedef struct {
	double  x ;
	double y ;
}vec;
void frac();




int main()
{
	vec a = {
		.x = 5 ,
		.y = 6
	};
	printf("a = %f,%f \n" ,a.x,a.y);

	return 0;
}
