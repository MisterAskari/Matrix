#include <iostream>
using namespace std;

const int MAX_SIZE = 100;


void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& rows, int& cols) {
    do {
        cout << "Enter number of rows (1 to " << MAX_SIZE << "): ";
        cin >> rows;
    } while (rows < 1 || rows > MAX_SIZE);

    do {
        cout << "Enter number of columns (1 to " << MAX_SIZE << "): ";
        cin >> cols;
    } while (cols < 1 || cols > MAX_SIZE);

    cout << "Enter matrix values:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}


void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}


bool multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        cout << "Error: Number of columns in Matrix A must equal number of rows in Matrix B.\n";
        return false;
    }

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true;
}


void sumRows(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
}


void sumColumns(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << sum << endl;
    }
}


int sumMainDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += matrix[i][i];
    }
    return sum;
}


int countZeros(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}


const char* identifyMatrixType(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int upperTriangular = 1; 
    int lowerTriangular = 1; 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i > j && matrix[i][j] != 0) upperTriangular = 0; // 0 means false
            if (i < j && matrix[i][j] != 0) lowerTriangular = 0; // 0 means false
        }
    }
    if (upperTriangular && !lowerTriangular) return "Upper Triangular";
    if (!upperTriangular && lowerTriangular) return "Lower Triangular";
    return "Neither";
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    
    cout << "Input Matrix A:\n";
    inputMatrix(matrixA, rowsA, colsA);

    cout << "Input Matrix B:\n";
    inputMatrix(matrixB, rowsB, colsB);

    
    cout << "Matrix A:\n";
    printMatrix(matrixA, rowsA, colsA);
    cout << "Matrix B:\n";
    printMatrix(matrixB, rowsB, colsB);

    
    cout << "Sum of Matrix A and B:\n";
    addMatrices(matrixA, matrixB, result, rowsA, colsA);
    printMatrix(result, rowsA, colsA);

    
    cout << "Subtraction of Matrix A and B:\n";
    subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
    printMatrix(result, rowsA, colsA);

    
    if (multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB)) {
        cout << "Multiplication of Matrix A and B:\n";
        printMatrix(result, rowsA, colsB);
    }

    
    sumRows(matrixA, rowsA, colsA);

    
    sumColumns(matrixA, rowsA, colsA);

    
    cout << "Sum of main diagonal: " << sumMainDiagonal(matrixA, rowsA) << endl;

    
    cout << "Number of zero elements in the matrix: " << countZeros(matrixA, rowsA, colsA) << endl;

    
    cout << "Matrix type: " << identifyMatrixType(matrixA, rowsA) << endl;

    return 0;
}
