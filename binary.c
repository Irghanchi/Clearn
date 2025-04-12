#include <stdio.h>
int binary_search(int arr[],int size , int target){
	int low=0,high= size-1;
	while (low <= high){
		int mid = (low +high)/2;
		if (target==arr[mid]){
			return mid;
		}else if (target > arr[mid]){
			low = mid + 1;
			printf("low = %d \n", arr[low]);
		}else{
			high = mid -1;
			printf("high = %d \n", arr[high]);
		}
	}
	return -1;
}

void shuffle_sort(int arr[],int size)
{
	int k =0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (arr[i] >  arr[j]){
				int arri = arr[i] ;
				arr[i] = arr[j];
				arr[j] = arri;
				k +=1;
			}
		}
	
	}
	printf("%d \n",k);
}
void bubble_sort(int arr[],int size)
{
	for (int i = 0; i < size-1; i++) {
		for (int j = 0; j < i- size-1; j++) {
			if (arr[j] >  arr[j+1]){
				int tmp = arr[j] ;
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	
	}
} 
void print(int arr[],int size){
	for (int i = 0; i <size; i++)
		printf("%d ",arr[i]);
	puts("");
}
void selection_sort(int arr[],int size)
{
	for (int i = 0;i < size;i++) {
		int min = arr[i];
		int index = i;
		for (int j =i; j < size ; j++) {
			if (min > arr[j]){
				min = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = min;
	
	}
}
void insertion_sort(int arr[],int size)
{
	for (int i = 1; i <size; i++) {
		int index = i;
		int tmp = arr[i];
		for (int j=i-1; j>=0 ; j--) {
			if (tmp < arr[j] ){
				index = j;
				arr[j+1] = arr[j];
			}

		
		}
		arr[index] = tmp;
	
	}
}
int factorial(int n){
	if (n == 0)
		return 1;
	else 
		return n*factorial(n-1);
}
			
int main()
{
	/*int size = 10;
	int arr[10] = {4, 1, 3, -5, 5, -9, 20, 9, 8, 7};
	insertion_sort(arr,size);

	for (int i =0; i <size;i++)
		printf("%d ",arr[i]);*/
	int n = 5;
	printf("%d! = %d \n" , n,factorial(n));
	return 0;
}
