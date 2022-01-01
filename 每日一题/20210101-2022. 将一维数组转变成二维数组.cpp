class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret;
        ret.resize(m);
        for (int i = 0; i < m; ++i) {
            ret[i].resize(n, 0);
        }
        int index = 0;
        if (original.size() < m * n) {
            return {};
        }
        for (int i = 0; i < original.size(); ++i) {
            int row = i / n;
            int col = i % n;
            if (row >= m || col >= n) {
                return {};
            }
            ret[row][col] = original[i];
        }
        return ret;
    }
};



