#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
 
        for (unsigned int i = 0; i < matrix.size(); ++i) {      // Traverse throught the rows
            vector<int> rowVector;

            rowVector.push_back(matrix[i][0]);
            for (unsigned int j = 1; j < matrix[0].size(); ++j) {
                rowVector.push_back(rowVector[j - 1] + matrix[i][j]);
            }
            prefixMatrix.push_back(rowVector);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // Print the matrix to test the init
        for (unsigned int i = 0; i < prefixMatrix.size(); ++i) {
            for (unsigned int j = 0; j < prefixMatrix[0].size(); ++j) {
                cout << prefixMatrix[i][j] << " ";
            }
            cout << endl;
        }
        return (0);
    }

private:
    vector<vector<int>> prefixMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(void) {
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
                                  {1, 0, 3, 0, 5}};

    NumMatrix* obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(2, 1, 4, 3);
    cout << "Sum: " << param_1 << endl;
    return 0;
}