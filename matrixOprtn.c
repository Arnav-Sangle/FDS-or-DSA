#include <stdio.h>


void getMatrix(int *a_ptr, int m, int n);
void dispMatrix(int *a_ptr, int m, int n);
void addMatrix(int *matA, int *matB, int m, int n);
void multMatrix(int *matA, int *matB, int m, int n);
void saddlePoint(int **arr, int m, int n);



int main() {
	int m=3, n=3;
	int arr[m][n];
	int *a_ptr = &arr[0][0];	

	int m1=3, n1=3;
	int matA[m1][n1];
	int m2=3, n2=3;
	int matB[m2][n2];
	
	getMatrix((int *)matA, m1, n1);		//type casting Double_ptr into Single_ptr
	dispMatrix((int *)matA, m1, n1);

	getMatrix((int *)matB, m2, n2);	
	dispMatrix((int *)matB, m2, n2);	
	
	if(m1 == m2 && n1 == n2) {
		addMatrix((int *)matA, (int *)matB, m1, n1);				
	}
	
	// if(n1 == m2) {
	// 	multMatrix((int *)matA, (int *)matB, m1, n2);				//3x2 * 2x4 = 3x4		m1xn1 * m2xn2 
	// }

	// getMatrix(a_ptr, m, n);
	// dispMatrix(a_ptr, m, n);
	// saddlePoint((arr);			// void func(arr[m][n]) {}	 + 	 func(arr);		works but gives warning
	
	
	return 0;
}





void getMatrix(int *a_ptr, int m, int n) {
	printf("Enter 3x3 matrix:\n");
	for(int i=0; i<m; i++) {
		printf("Row %d: ", i);
		for(int j=0; j<3; j++) {		
			scanf("%d", (a_ptr+((i*3)+j)) );
		}
	}
	printf("\n");
}

void dispMatrix(int *a_ptr, int m, int n) {
	printf("Matrix\n");
	for(int i=0; i<3; i++) {	
		for(int j=0; j<3; j++) {		
			printf("%d ", *(a_ptr+((i*3)+j)) );	//if *p 	then (*(ptr+i)+j)
		}
		printf("\n");
	}
	printf("\n");
}

void addMatrix(int *matA, int *matB, int m, int n) {
	printf("Matrix Addition: \n");
	int sum;
	for(int i=0; i<m; i++) {
		sum = 0;		// initialize/reset value to 0
		for(int j=0; j<n; j++) {
			sum = *(matA+((i*m)+j)) + *(matB+((i*m)+j)) ;
			printf("%d ", sum);
		}
		printf("\n");
	}
}

void saddlePoint(int **arr, int m, int n) {
	int s[2][2];		//solution matrix 	stores location of min and max element
	int max, min;
	
	int i,j,k,flag=0;
	for(i=0; i<m; i++) {
		min = arr[i][0];		//consider 1st element of each row as Min
		for(j=0; j<n; j++) {		//traversing col side-side
			if(min >= arr[i][j]) {
				min = arr[i][j];
				s[0][0] = i;
				s[0][1] = j;			
			}
			
		}
		
		j = s[0][1];		//reinitiating j value as same as that of Min_cold
		max = arr[0][j];	//consider 1st element of Min_Col as Max	
		for(k=0; k<3; k++) {		//traversing row up-down
			if(max <= arr[k][j]) {
				max = arr[k][j];				
				s[1][0] = k;
				s[1][1] = j;
			}
		}
		
		if(min == max) {
			if(s[0][0] == s[1][0] && s[0][1] == s[1][1]) {
				printf("Saddle point found: %d\n", max);
				flag=1;			
				break;
			}
		}		
		else {
			flag = -1;
		}
	}

	if(flag==-1) {
		printf("No saddle point\n");		
	}
}






