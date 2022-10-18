#include <stdio.h>

int main() {

    int m, n;
    printf("Enter No. of rows and columns (m,n): ");
    scanf("%d%d", &m, &n);
    

    int mat_A[m][n];
    int zeroCount=0, nonZero=0;        //no. of zero values in matrix 
    printf("Enter matrix data:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &mat_A[i][j]);

            if(mat_A[i][j] == 0) {
                zeroCount++;
            }
            else {
                nonZero++;
            }
        }
    }


    if(zeroCount > (m*n)/2) {
        printf("It is Sparse Matrix\n");    

        //Triplet representation
        int mat_S[nonZero][3];                
        //Filling table
        int p=0;    //row_no. count for RCV table
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat_A[i][j] != 0) {
                    mat_S[p][0] = i;
                    mat_S[p][1] = j;
                    mat_S[p][2] = mat_A[i][j];
                    p++;    //incrmnt to next row
                }
            }
        }

        //Printing table

        printf("Triplet representation:\n");              //R(row_no.)     C(col_no,)       V(value)
        printf("\tR\tC\tV\n");              //R(row_no.)     C(col_no,)       V(value)
        for(int i=0; i<nonZero; i++) {
            printf("\t%d\t%d\t%d\n", mat_S[i][0], mat_S[i][1], mat_S[i][2]);
        }


    }
    else {
        printf("Not a Sparse Matrix\n");
    }

    return 0;
}