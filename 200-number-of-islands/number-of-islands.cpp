#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }

    void bfs(int i, int j, vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = '0'; // mark as visited

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < row && ny < col && grid[nx][ny] == '1') {
                    grid[nx][ny] = '0'; // mark as visited
                    que.push({nx, ny});
                }
            }
        }
    }
};
