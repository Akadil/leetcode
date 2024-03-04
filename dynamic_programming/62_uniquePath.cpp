class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<int> prevRow (n, 0);
        int*    prevRow = new int[n]();

        for (unsigned int i = 0; i < m; ++i) {
            // vector<int> currRow (n, 0);
            int*    currRow = new int[n]();

            currRow[n - 1] = 1;
            for (int j = n - 2; j >= 0; --j) {
                currRow[j] = currRow[j + 1] + prevRow[j];
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
};