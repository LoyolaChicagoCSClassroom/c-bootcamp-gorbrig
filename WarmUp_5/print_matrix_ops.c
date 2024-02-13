#include <stdio.h>

#define Rows 2
#define Cols 2

void addMatrices(int a[Rows][Cols], int b[Rows][Cols], int result[Rows][Cols]);
void multiplyMatrices(int a[Rows][Cols], int b[Rows][Cols], int result[Rows][Cols]);
void printMatrix(int matrix[Rows][Cols]);

int main() {
    int matrix1[Rows][Cols] = {{1, 2}, {3, 4}};
    int matrix2[Rows][Cols] = {{5, 6}, {7, 8}};
    int sum[Rows][Cols];
    int product[Rows][Cols];

    addMatrices(matrix1, matrix2, sum);
    multiplyMatrices(matrix1, matrix2, product);

    printf("Matrix Addition:\n");
    printMatrix(sum);

    printf("Matrix Multiplication:\n");
    printMatrix(product);

    return 0;
}

void addMatrices(int a[Rows][Cols], int b[Rows][Cols], int result[Rows][Cols]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[Rows][Cols], int b[Rows][Cols], int result[Rows][Cols]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < Cols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int matrix[Rows][Cols]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
