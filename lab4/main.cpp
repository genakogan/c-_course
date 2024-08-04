#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

class CMatrixFun {
private:
    double** matrix;
    int rows;
    int cols;

    void allocateMatrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new double[cols];
        }
    }

    void initializeMatrixRandomly() {
        srand(time(NULL));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = (rand() % 31) - 15; // values between -15 and 15
            }
        }
    }

public:
    // Default constructor
    CMatrixFun() {
        allocateMatrix(1, 1);
        matrix[0][0] = 0;
    }

    // Parameterized constructor
    CMatrixFun(int r, int c) {
        allocateMatrix(r, c);
        initializeMatrixRandomly();
    }

    // Copy constructor
    CMatrixFun(const CMatrixFun& other) {
        allocateMatrix(other.rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // Destructor
    ~CMatrixFun() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Print function
    void Print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << setw(5) << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Set value function
    void SetValue(int row, int column, double newValue) {
        if (row >= 0 && row < rows && column >= 0 && column < cols) {
            matrix[row][column] = newValue;
        } else {
            cout << "Invalid position" << endl;
        }
    }

    // Get value function
    double GetValue(int row, int column) const {
        if (row >= 0 && row < rows && column >= 0 && column < cols) {
            return matrix[row][column];
        } else {
            cout << "Invalid position" << endl;
            exit(1);
        }
    }

    // Transpose function
    void Transpose() {
        double** transposedMatrix = new double*[cols];
        for (int i = 0; i < cols; ++i) {
            transposedMatrix[i] = new double[rows];
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposedMatrix[j][i] = matrix[i][j];
            }
        }

        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = transposedMatrix;
        swap(rows, cols);
    }

    // Add row function
    void AddRow(double* ar, int size_ar) {
        if (size_ar != cols) {
            cout << "Row size does not match matrix column size" << endl;
            return;
        }

        double** newMatrix = new double*[rows + 1];
        for (int i = 0; i < rows; ++i) {
            newMatrix[i] = matrix[i];
        }
        newMatrix[rows] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            newMatrix[rows][j] = ar[j];
        }

        matrix = newMatrix;
        rows++;
    }

    // Remove column function
    void RemoveColumn(int colNumber) {
        if (colNumber < 0 || colNumber >= cols) {
            cout << "Invalid column number" << endl;
            return;
        }

        double** newMatrix = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            newMatrix[i] = new double[cols - 1];
            for (int j = 0, newJ = 0; j < cols; ++j) {
                if (j != colNumber) {
                    newMatrix[i][newJ++] = matrix[i][j];
                }
            }
            delete[] matrix[i];
        }
        delete[] matrix;

        matrix = newMatrix;
        cols--;
    }

    // Get row function
    double* GetRow(int rowNumber) const {
        if (rowNumber < 0 || rowNumber >= rows) {
            cout << "Invalid row number" << endl;
            exit(1);
        }

        double* row = new double[cols];
        for (int j = 0; j < cols; ++j) {
            row[j] = matrix[rowNumber][j];
        }
        return row;
    }

    // Matrix multiplication function
    CMatrixFun Multiply(const CMatrixFun& other) const {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied" << endl;
            exit(1);
        }

        CMatrixFun result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    // Check arithmetic sequence function
    bool CheckArithmeticSequence() const {
        if (rows < 1 || cols < 1) return false;

        vector<double> perimeter;
        for (int j = 0; j < cols; ++j) perimeter.push_back(matrix[0][j]);
        for (int i = 1; i < rows; ++i) perimeter.push_back(matrix[i][cols - 1]);
        for (int j = cols - 2; j >= 0; --j) perimeter.push_back(matrix[rows - 1][j]);
        for (int i = rows - 2; i > 0; --i) perimeter.push_back(matrix[i][0]);

        double diff = perimeter[1] - perimeter[0];
        for (size_t i = 2; i < perimeter.size(); ++i) {
            if (perimeter[i] - perimeter[i - 1] != diff) return false;
        }
        return true;
    }

    // Max relocate function
    CMatrixFun MaxRelocate() const {
        int maxRow = 0, maxCol = 0;
        double maxVal = matrix[0][0];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] > maxVal) {
                    maxVal = matrix[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
        }

        CMatrixFun relocatedMatrix(*this);
        swap(relocatedMatrix.matrix[0][0], relocatedMatrix.matrix[maxRow][maxCol]);

        return relocatedMatrix;
    }
};

// Example usage
int main() {
    CMatrixFun mat1(3, 3);
    mat1.Print();
    cout << endl;

    mat1.SetValue(1, 1, 5.5);
    mat1.Print();
    cout << endl;

    cout << "Value at (1, 1): " << mat1.GetValue(1, 1) << endl;
    cout << endl;

    mat1.Transpose();
    mat1.Print();
    cout << endl;

    double newRow[] = {7.1, 8.2, 9.3};
    mat1.AddRow(newRow, 3);
    mat1.Print();
    cout << endl;

    mat1.RemoveColumn(1);
    mat1.Print();
    cout << endl;

    CMatrixFun mat2(mat1);
    mat2.Print();
    cout << endl;

    CMatrixFun mat3 = mat1.Multiply(mat2);
    mat3.Print();
    cout << endl;

    cout << "Check Arithmetic Sequence: " << (mat1.CheckArithmeticSequence() ? "Yes" : "No") << endl;
    cout << endl;

    CMatrixFun relocatedMatrix = mat1.MaxRelocate();
    relocatedMatrix.Print();
    cout << endl;

    return 0;
}
