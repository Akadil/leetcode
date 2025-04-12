#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefixMatrix = matrix;

        for (unsigned int i = 0; i < matrix.size(); ++i) {
            for (unsigned int j = 0; j < matrix[0].size(); ++j) {
                if (i > 0) 
                    prefixMatrix[i][j] += prefixMatrix[i - 1][j];
                if (j > 0)
                    prefixMatrix[i][j] += prefixMatrix[i][j - 1];
                if (i > 0 && j > 0)
                    prefixMatrix[i][j] -= prefixMatrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        // Print the matrix to test the init
        // for (unsigned int i = 0; i < prefixMatrix.size(); ++i) {
        //     for (unsigned int j = 0; j < prefixMatrix[0].size(); ++j) {
        //         cout << prefixMatrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int sum = prefixMatrix[row2][col2];

        if (row1 != 0)
            sum -= prefixMatrix[row1 - 1][col2];
        if (col1 != 0)
            sum -= prefixMatrix[row2][col1 - 1];
        if (col1 != 0 && row1 != 0)
            sum += prefixMatrix[row1 - 1][col1 - 1];

        return (sum);
    }

private:
    vector<vector<int>> prefixMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */