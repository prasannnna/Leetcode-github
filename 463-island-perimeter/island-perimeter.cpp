class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        queue<pair<int, int>>q;
        q.push({i, j});
        grid[i][j] = -1;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto [r, c] = q.front();
            perimeter += 4;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = dr[i] + r;
                int ny = dc[i] + c;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                   if(grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                    perimeter--;
                   } else if(grid[nx][ny] == -1) {
                        perimeter--;
                   }
                }
            }
        }
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    perimeter = bfs(i, j, grid);
                }
            }
        }
        return perimeter;
    }
};