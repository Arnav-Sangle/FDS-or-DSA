#include <stdio.h>
#include <stdlib.h>


void getArr(int *arr, int n);
void putArr(int *arr, int n);

void bubble_sort(int *arr, int n);
void combine_arr(int *arr1, int *arr2, int n1, int n2, int *comb);

void set_intrsctn(int *arr, int n);
void set_union(int *arr, int n);
void set_cmplmnt(int *comb, int n);





int main() {
	int n1;
	printf("Enter No. of elements in Universal set U: ");
	scanf("%d", &n1);	
	int U[n1];
	printf("Enter Data of Universal set U: ");
	getArr(U, n1);
	printf("\n");
	
	int n2;
	printf("Enter No. of elements in set A: ");
	scanf("%d", &n2);	
	int A[n2];
	printf("Enter Data of set A: ");
	getArr(A, n2);
	printf("\n");
	
	int n3;
	printf("Enter No. of elements in set B: ");
	scanf("%d", &n3);	
	int B[n3];
	printf("Enter Data of set B: ");
	getArr(B, n3);
	printf("\n");
	
	
	int choice;
	do {
		printf("MENU\n");
		printf("1. Set Union\n");
		printf("2. Set Intersection\n");
		printf("3. Set Complement\n");
		printf("0. EXIT\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		int comb[50], c;
		char set_name;
		switch(choice) {
			case 1:
				combine_arr(A, B, n2, n3, comb);
				c = n2+n3;
				bubble_sort(comb, c);
				set_union(comb, c);
				getchar(); getchar();
				break;

			case 2:
				combine_arr(A, B, n2, n3, comb);
				c = n2+n3;
				bubble_sort(comb, c);
				set_intrsctn(comb, c);
				getchar(); getchar();
				break;

			case 3:
				printf("Enter set name (A/B): ");
				scanf(" %c", &set_name);
				
				if(set_name == 'A') {
					combine_arr(U, A, n1, n2, comb);
					c = n1+n2;
					bubble_sort(comb, c);
					printf("~A = ");
					set_cmplmnt(comb, c);
					getchar(); getchar(); 
				}
				else {
					combine_arr(U, B, n1, n3, comb);
					c = n1+n3;
					bubble_sort(comb, c);
					printf("~B = ");
					set_cmplmnt(comb, c);
					getchar(); getchar();
				}
				break;

			case 0:
				printf("Exit successfully!\n");
				break;

			default:
				printf("Invalid choice, please enter again!\n");
				getchar(); getchar();
		}
	
	} while(choice != 0);

	return 0;
}





void getArr(int *arr, int n) {
	int count=0;
	for(int i=0; i<n; i++) {
		scanf("%d", (arr+i));
	}
}

void putArr(int *arr, int n) {
	for(int i=0; i<n; i++) {
		printf("%d ", *(arr+i));
	}
	printf("\n");
}

void bubble_sort(int *arr, int n) {
	int flag=0, temp;
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
				if(arr[j] > arr[j+1]) {
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					flag++;			
				}		
		}
	if(flag == 0)
		break;		
	}
}

void combine_arr(int *arr1, int *arr2, int n1, int n2, int *comb) {
	for(int i=0; i<n1; i++) {
		comb[i] = arr1[i];
	}
	int k=0;
	for(int i=n1; i<n1+n2; i++) {
		comb[i] = arr2[k];
		k++;
	} 
}

void set_union(int *arr, int n) {	//U
	int count=0;
	for(int i=0; i<n; i++) {
		if(arr[i] != arr[i+1]) {
			arr[count]=arr[i];
			count++;
		}   			
	}

	printf("A U B = ");
	putArr(arr, count);
}

void set_intrsctn(int *arr, int n) {	//∩
	int count=0;
	for(int i=0; i<n; i++) {
		if(arr[i] == arr[i+1]) {
			arr[count]=arr[i];
			count++;
		}   			
	}

	printf("A ∩ B = ");
	putArr(arr, count);
}

void set_cmplmnt(int *comb, int n) {
	int count=0;
	for(int i=0; i<n; i++) {
		if(comb[i] == comb[i+1]) {
			i++;
		}
		else {
			comb[count] = comb[i];
			count++;
		}
	}

	putArr(comb, count);
}

