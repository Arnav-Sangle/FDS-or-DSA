#include <stdio.h>

void getSparse(int m, int n, int arr[m][n], int *z, int *nz);
int checkSparse(int z, int m, int n);
void getTriplet(int nz, int (*mat_S)[3], int m, int n, int mat_A[m][n]);
void putTriplet(int nz, int (*mat_S)[3]);





int main() {

    int m, n;
    printf("Enter No. of rows and columns (m,n): ");
    scanf("%d%d", &m, &n);

    printf("Enter Matrix-A\n");
    int mat_A[m][n];
    int z_A=0, nz_A=0;        //z = zeroCount = no. of zero values in matrix           nz = nonZeroCount = no. of non_zero values in matrix 
    //Input sparse matrix
    getSparse(m , n, mat_A, &z_A, &nz_A);
    printf("\n");

    printf("Enter Matrix-B\n");
    int mat_B[m][n];
    int z_B=0, nz_B=0;        //z = zeroCount = no. of zero values in matrix           nz = nonZeroCount = no. of non_zero values in matrix 
    //Input sparse matrix
    getSparse(m, n, mat_B, &z_B, &nz_B);
    printf("\n");

    int flag = checkSparse(z_A, m, n) + checkSparse(z_B, m, n);
    
    if(flag > 0) {
        //Triplet representation
        int mat_SA[nz_A][3];                
        //Filling table
        getTriplet(nz_A, mat_SA, m, n, mat_A);
        //Printing table
        printf("Sparse Matrix A-\n");
        putTriplet(nz_A, mat_SA);
        printf("\n");

        //Triplet representation
        int mat_SB[nz_B][3];                
        //Filling table
        getTriplet(nz_B, mat_SB, m, n, mat_B);
        //Printing table
        printf("Sparse Matrix B-\n");
        putTriplet(nz_B, mat_SB);
        printf("\n");


        printf("Sum of sparse matrix-\n");
        int nz_C = nz_A + nz_B;     //max no. of Rows that can be created if all each non_zero elmnt have different index positn 
        int mat_C[nz_C][3];
        // addSparse(mat_C, nz_A, nz_B, mat_A, mat_B);

        int p=0, q=0, r=0;  //counter for each matrix SA, SB, C
        while(p != nz_A && q != nz_B) {
            printf("Inside while\n");
            //check Row indx
            if(mat_SA[p][0] == mat_SB[q][0]) {
                //check Col indx
                if(mat_SA[p][1] == mat_SB[q][1]) {
                    mat_C[r][0] = mat_SA[p][0]; 
                    mat_C[r][1] = mat_SA[p][1];
                    mat_C[r][2] = mat_SA[p][2] + mat_SB[q][2];   
                    // printf("COL_same R:%d, C:%d, V:%d\n", mat_C[r][0], mat_C[r][1], mat_C[r][2]);
                    p++;    q++;    r++;
                    // printf("COL_same p=%d, q=%d, r=%d\n", p, q, r);
                }
                else if(mat_SA[p][1] < mat_SB[q][1]) {
                    mat_C[r][0] = mat_SA[p][0]; 
                    mat_C[r][1] = mat_SA[p][1];
                    mat_C[r][2] = mat_SA[p][2];   
                    // printf("C-p\n");
                    // printf("COL_diff R:%d, C:%d, V:%d\n", mat_C[r][0], mat_C[r][1], mat_C[r][2]);
                    p++;    r++;        //incrmnt only p,r
                    // printf("COL_diff p=%d, q=%d, r=%d\n", p, q, r);
                }
                else {
                    mat_C[r][0] = mat_SB[p][0]; 
                    mat_C[r][1] = mat_SB[p][1];
                    mat_C[r][2] = mat_SB[p][2];   
                    // printf("C-q\n");
                    // printf("COL_diff R:%d, C:%d, V:%d\n", mat_C[r][0], mat_C[r][1], mat_C[r][2]);
                    q++;    r++;        //incrmnt only q,r
                    // printf("COL_diff p=%d, q=%d, r=%d\n", p, q, r);
                }
            }
            else if(mat_SA[p][0] < mat_SB[q][0]) {
                mat_C[r][0] = mat_SA[p][0]; 
                mat_C[r][1] = mat_SA[p][1];
                mat_C[r][2] = mat_SA[p][2];   
                // printf("R-p\n");
                // printf("ROW_diff R:%d, C:%d, V:%d\n", mat_C[r][0], mat_C[r][1], mat_C[r][2]);
                p++;    r++;
                // printf("ROW_diff p=%d, q=%d, r=%d\n", p, q, r);
            }
            else {
                mat_C[r][0] = mat_SB[p][0]; 
                mat_C[r][1] = mat_SB[p][1];
                mat_C[r][2] = mat_SB[p][2];   
                // printf("R-q\n");
                // printf("ROW_diff R:%d, C:%d, V:%d\n", mat_C[r][0], mat_C[r][1], mat_C[r][2]);
                q++;    r++;
                // printf("ROW_diff p=%d, q=%d, r=%d\n", p, q, r);
            }
        }
        putTriplet(r, mat_C);
    }

    return 0;
}





//Function Definition--------------------------------------------------
void getSparse(int m, int n, int arr[m][n], int *z, int *nz) {
    printf("Enter matrix data:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);

            if(arr[i][j] == 0) {
                (*z)++;         //*ptr++ icrmnts ptr addrs       ++ > * ('>' higher precedence)
            }
            else {
                (*nz)++;
            }
        }
    }
}

int checkSparse(int z, int m, int n) {
    if(z > (m*n)/2) {
        printf("It is Sparse Matrix\n");
        return 1;
    }    
    else {
        printf("Not a Sparse Matrix\n");
        return -1;
    }
}

void getTriplet(int nz, int (*mat_S)[3], int m, int n, int mat_A[m][n]) {
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
}

void putTriplet(int nz, int (*mat_S)[3]) {
    //Printing table
    printf("Triplet representation:\n");              //R(row_no.)     C(col_no,)       V(value)
    printf("\tR\tC\tV\n");              //R(row_no.)     C(col_no,)       V(value)
    for(int i=0; i<nz; i++) {
        printf("\t%d\t%d\t%d\n", mat_S[i][0], mat_S[i][1], mat_S[i][2]);
    }
}

























//ROUGH---------------------------------------------------
//Using pointer approach, but why Error?

// int *temp, *t, p=0, q=0, r=0;  

// while(p != nz_A && q != nz_B) {
//     printf("Inside while\n");
//     //check Row indx
//     if(mat_SA[p][0] == mat_SB[q][0]) {
//         //check Col indx
//         if(mat_SA[p][1] == mat_SB[q][1]) {
//             mat_C[r][0] = mat_SA[p][0]; 
//             mat_C[r][1] = mat_SA[p][1];
//             mat_C[r][2] = mat_SA[p][2] + mat_SB[q][2];   //?
//             printf("COL_same R:%d, C:%d, V:%d\n", mat_C[r][0], mat_C[r][1], mat_C[r][2]);
//             p++;    q++;    r++;
//             printf("COL_same p=%d, q=%d, r=%d\n", p, q, r);

//         }
//         else {
//             if(mat_SA[p][1] < mat_SB[q][1]) {
//                 temp = &mat_SA[p][0];
//                 t = &p;
//                 printf("p\n");                        
//             }
//             else {
//                 temp = &mat_SB[q][0];
//                 t = &q;
//                 printf("q\n");
//             }
//             mat_C[r][0] = *(temp+((*t)*3+0)); 
//             mat_C[r][1] = *(temp+((*t)*3+1));
//             mat_C[r][2] = *(temp+((*t)*3+2));
//             printf("COL_diff R:%d, C:%d, V:%d\n", *(temp+((*t)*3+0)), *(temp+((*t)*3+1)), *(temp+((*t)*3+2)));
//             (*t)++;     r++;
//             printf("COL_diff t=%d, r=%d\n", *t, r);
//         }
//     }
//     else {
//         if(mat_SA[p][0] < mat_SB[q][0]) {
//             temp = &mat_SA[p][0];
//             t = &p;
//         }
//         else {
//             temp = &mat_SB[q][0];
//             t = &q;
//         }
//         mat_C[r][0] = *(temp+(((*t)*3+0)*4)); 
//         mat_C[r][1] = *(temp+((*t)*3+1));
//         mat_C[r][2] = *(temp+((*t)*3+2)*4);
//         printf("ROW_diff R:%d, C:%d, V:%d\n", *(temp+((*t)*3+0)), *(temp+((*t)*3+1)), *(temp+((*t)*3+2)));
//         (*t)++;     r++;
//         printf("ROW_diff t=%d, r=%d\n", *t, r);
//     }
// }

// // nz_C = r;
// putTriplet(r, mat_C);