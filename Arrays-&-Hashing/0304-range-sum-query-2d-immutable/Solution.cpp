class NumMatrix {
public:
    vector<vector<int>> vec;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vec.resize(rows, vector<int>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = matrix[i][j];

                if (i > 0) sum += vec[i - 1][j];
                if (j > 0) sum += vec[i][j - 1];
                if (i > 0 && j > 0) sum -= vec[i - 1][j - 1];

                vec[i][j] = sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = vec[row2][col2];
        if (row1 > 0) sum -= vec[row1 - 1][col2];
        if (col1 > 0) sum -= vec[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) sum += vec[row1 - 1][col1 - 1]; 

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */