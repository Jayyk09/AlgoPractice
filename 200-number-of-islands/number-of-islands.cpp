class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    breathfirst(grid, i ,j);
                    count++;
                }
            }
        }

        return count;
    }

    private:
        void breathfirst(vector<vector<char>>& grid, int i, int j){
            queue<pair<int, int>> que;
            int row = grid.size();
            int col = grid[0].size();

            que.push(make_pair(i,j));

            while(!que.empty()){
                auto [i, j] = que.front();
                que.pop();

                if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0'){
                    continue;
                }

                //mark the place visited
                grid[i][j] = '0';

                breathfirst(grid, i + 1, j);
                breathfirst(grid, i - 1, j);
                breathfirst(grid, i, j + 1);
                breathfirst(grid, i, j - 1);
            }
        }

};