#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Matrix multiplication function
void matrix_multiplication(int size, double** a, double** b, double** result) {
    int i, j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = 0.0;
            for (k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to allocate memory for a matrix
double** allocate_matrix(int size) {
    double** matrix = (double**)malloc(size * sizeof(double*));
    int i;
    for (i = 0; i < size; i++) {
        matrix[i] = (double*)malloc(size * sizeof(double));
    }
    return matrix;
}

// Function to deallocate memory for a matrix
void deallocate_matrix(int size, double** matrix) {
    int i;
    for (i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int size = 1000;
    
    // Allocate memory for matrices
    double** matrix_a = allocate_matrix(size);
    double** matrix_b = allocate_matrix(size);
    double** result = allocate_matrix(size);
    
    // Generate random matrices
    srand(time(NULL));
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix_a[i][j] = (double)rand() / RAND_MAX;
            matrix_b[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // Perform matrix multiplication and measure time
    clock_t start_time = clock();
    matrix_multiplication(size, matrix_a, matrix_b, result);
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("C Matrix Multiplication\n");
    printf("Matrix size: %d x %d\n", size, size);
    printf("Execution time: %.6f seconds\n", execution_time);
    
    // Deallocate memory for matrices
    deallocate_matrix(size, matrix_a);
    deallocate_matrix(size, matrix_b);
    deallocate_matrix(size, result);
    
    return 0;
}
