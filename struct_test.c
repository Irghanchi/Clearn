#include <stdio.h>

int main(){
	int a = 89;
	int b = 90;
	int * pa = &a;
	int * pb = &b;
	pa = pb;
	printf("pa = %p" , pa);
	printf("pb = %p" , pa);
	printf("a = %d" ,a);
	return 0;

}
