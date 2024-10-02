#include<stdio.h>
#include<stdlib.h>

// Structure that holds sparse matrix elements (row, column, value)
typedef struct {
    int row;
    int col;
    int value;
} adt;

int main()
{
    int r, c, i, j, k = 0, allzeros = 1;  
    adt data[10];  // Array to store sparse matrix representation
    
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);
    
    // Dynamic memory allocation for 2-D array
    int **mat1 = (int**)malloc(r * sizeof(int*));  
    for(i = 0; i < r; i++) {
        mat1[i] = (int*)malloc(c * sizeof(int)); 
    }
    
    // Input matrix values
    printf("Enter the values of the matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &mat1[i][j]);  // Store each element in the matrix
        }
    }
    
    // Check if all elements are zero
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(mat1[i][j] != 0) {
                allzeros = 0;  // Set allzeros to false if any non-zero element is found
                break;
            }
        }
        if(!allzeros) break;
    }

    if(allzeros) {
        printf("All the elements are zero.\n");
    } else {
        // Store the matrix dimensions in data[0] (sparse matrix first row)
        data[0].row = r;
        data[0].col = c;
        
        // Traverse the matrix to find non-zero values and store them
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                if(mat1[i][j] != 0) {  // Check if the matrix element is non-zero
                    data[k+1].row = i;  // Store row index of the non-zero element
                    data[k+1].col = j;  // Store column index of the non-zero element
                    data[k+1].value = mat1[i][j];  // Store the value of the element
                    k++;  // Increment the non-zero element count
                }
            }
        }

        // Store the count of non-zero elements in data[0].value
        data[0].value = k;

        // Sparse matrix representation
        printf("Sparse matrix representation (Row Column Value):\n");
        printf("%d %d %d\n", data[0].row, data[0].col, data[0].value); 
        
        // Print the non-zero elements with their respective row and column
        for(i = 1; i <= k; i++) {
            printf("%d %d %d\n", data[i].row, data[i].col, data[i].value);
        }
    }
    
    // Free the dynamically allocated memory
    for(i = 0; i < r; i++) {
        free(mat1[i]);  // Free each row
    }
    free(mat1);  // Free the array of row pointers

    return 0;
}
