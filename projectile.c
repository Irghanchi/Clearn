#include <stdio.h>
#include <math.h>

int main(){
	double v,t,r,h,θ;
	char which;
	puts("what you need to find v,t or θ");
	printf("input = ");
	scanf("%s",&which);
	printf("insert r = ");
	scanf("%lf",&r);
	printf("insert h = ");
	scanf("%lf",&h);
	θ = atan(2*h/r);
	v = sqrt(r*9.8/sin(2*θ));
	t = v * sin(θ)/9.8;
	if (which == 118){//v == 118
		printf("v = %lf \n", v);
	}else if (which == 116 ){//116 = t
		printf("t = %lf \n ",t);
	}else if (which == 206){//θ = 206
		printf("θ = %lf° \n",θ*360/(2*M_PI));
	}
	return 0; 
}
