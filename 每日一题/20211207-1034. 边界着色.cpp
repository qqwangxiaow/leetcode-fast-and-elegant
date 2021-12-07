class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> borders;
        visited[row][col] = true;
        int originColor = grid[row][col];
        dfs(grid, borders, visited, row, col, originColor);
        for (auto & [x, y] : borders) {
            grid[x][y] = color;
        }
        return grid;

    }
    void dfs(vector<vector<int>>& grid, vector<pair<int, int>>& borders, vector<vector<bool>>& visited,int x, int y, int originColor) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> direct{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool isBoder = false;
        for (int i = 0; i < direct.size(); ++i) {
            int dx = x + direct[i][0]; 
            int dy = y + direct[i][1];
            if (!(dx < m && dy < n && dx >= 0 && dy >= 0 && grid[dx][dy] == originColor)){               isBoder = true;
            } else if (!visited[dx][dy]) {
                visited[dx][dy] = true;
                dfs(grid, borders, visited, dx, dy, originColor);
            }
            if (isBoder) {
                borders.emplace_back(make_pair(x, y));
            }
            
        }
    }
};