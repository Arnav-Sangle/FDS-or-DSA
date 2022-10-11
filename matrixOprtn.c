#include <stdio.h>
// https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

void inputMatrix(int *arr, int m, int n);
void dispMatrix(int *arr, int m, int n);
int sumMatrix(int *arr1, int *arr2);
int multMatrix(int *arr1, int *arr2);




int main() {
    int m=3, n=3;
    int matrixA[m][n];  

    inputMatrix(matrixA, m, n);
    dispMatrix(matrixA, m, n);

    int choice;
    do {
        printf("******MENU******\n");
        printf("1. Add matrix\n");
        printf("2. Multiply matrix\n");
        printf("0. EXIT\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                break;
            
            case 2:
                break;
            
            case 0:
                break;
            
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=0);



    return 0;    
}




void inputMatrix(int *arr, int m, int n) {       
    printf("Enter 3x3 Matrix-\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", ((arr + (i * n)) + j) );      //( (arr + (row_no. * total_rows)) + col_no. )   -->    ((arr+i*n)+j)
        }
    }
    pritnf("\n");
}

void dispMatrix(int *arr, int m, int n) {       
    printf("Matrix-\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", ((arr+i*n)+j));
        }
        pritnf("\n");
    }
    pritnf("\n");
}
