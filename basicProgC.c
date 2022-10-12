#include<stdio.h>

void digitSum() {
	int n;	
	printf("Enter a number: ");	
	scanf("%d",&n);
	
	int sum=0, temp_num;
	while(n!=0) {
		temp_num = n%10;
		n /= 10;
		sum+=temp_num;
	}
	
	
	printf("Sum of digits of number: %d\n", sum);
}



void leapYr() {
	int n;	
	printf("Enter any year: ");	
	scanf("%d",&n);
	
	if(n%4 == 0 && n%100 != 0) {
		printf("It is a leap year\n");
	}
	else if(n%100 == 0 && n%400 == 0) {
		printf("It is a leap year\n");
	}
	else
		printf("It is NOT a leap year\n");
}



void arraySum() {
	int n;		
	printf("Enter number of elements: ");
	scanf("%d",&n);

	int arr[n];
	int sum = 0;
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		if(i%2 == 0) {
			sum += arr[i]; 
		}	
	}
	
	printf("Sum of even digits of array: %d\n", sum);
	
}


void arrayMax() {
	int n;		
	printf("Enter number of elements: ");
	scanf("%d",&n);

	int arr[n];
	int max = 0;
	printf("Enter array elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		if(max <= arr[i]) {
			max = arr[i]; 
		}	
	}
	
	printf("Max element of array: %d\n", max);
	
}


void twoArraySum() {
	int n;		
	printf("Enter number of elements: ");
	scanf("%d",&n);

	int arr1[n];
	printf("Enter array-1 elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr1[i]);	
	}
	
	int arr2[n];
	printf("Enter array-2 elements: ");
	for(int i=0; i<n; i++) {
		scanf("%d",&arr2[i]);	
	}
	
	int arr3[n];
	printf("Sum of 2 arrays: ");
	for(int i=0; i<n; i++) {
		arr3[i] = arr1[i] + arr2[i];
		printf("%d ",arr3[i]);	
	}
	printf("\n");

}


int main() {
	//digitSum();	
	//leapYr();
	//arraySum();
	//arrayMax();
	twoArraySum();
	
	return 0;
}
