#include <stdio.h>
#include <stdlib.h> //getchar();    acts to clear keyboard buffer like(\n)
    


int main() {
//USER INPUT MATRIX-------------------------------------------
    int m=-1;
    printf("Input no. of cities: ");    //bcoz no. of src = dest
    scanf("%d", &m);

    int matrix[m][m];

    printf("Enter matrix data:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");

//Display Matrix
    // printf("Matrix:\n");
    // for(int i=0; i<m; i++) {
    //     for(int j=0; j<m; j++) {
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    char stations[m];
    char stationValue = 'A';      //A=65
    for(int i=0; i<m; i++) {
        stations[i] = stationValue++;
        // printf("%c ", stations[i]);
    }
    // printf("\n");
//----------------------------------------------------------------

//HARDCODED MATRIX------------------------------------------------
    // int m=4;
    // int matrix[4][4] = {    {0,0,0,0},      //sparse matrix
    //                         {0,0,4,0},
    //                         {3,0,0,2},
    //                         {0,0,5,0}   
    //                    };
    // char stations[4] = {'A', 'B', 'C', 'D'};
//----------------------------------------------------------------

    printf("OUTPUT MATRIX:\n");
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] != 0) {
                printf("\t%c\t%c\t%d\n", stations[i], stations[j], matrix[i][j]);
            }
        }
    }

    char src, dst, y;
    int srcIndx=-1, dstIndx=-1;     //to avoid segmentation fault when tackling runt time errors
                                        //segmentation fault    --when code attepmts to access restricted area of memory
    
    while(1) {
        printf("\nTo find frequency of trains between train stations (A, B, C, D)\n");
        printf("\tEnter 2 stations: ");
        scanf(" %c %c", &src, &dst);        //must give space btwn each '%c' to clean system_input (keyboard) buffer
        
        for(int i=0; i<m; i++) {
            if(src == stations[i]) {
                srcIndx = i;
            }
            if(dst == stations[i]) {
                dstIndx = i;
            }
        }
        printf("\tFrequency: %d\n", matrix[srcIndx][dstIndx]);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &y);
        if(y=='n') {
            break;
        }
    }

    return 0;
}

