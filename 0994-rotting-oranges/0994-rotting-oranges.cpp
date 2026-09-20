class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;

        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        int fresh = 0, time = 0;
        
        // put all initially rotten oranges into queue 
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -2;
                } else if(grid[i][j] == 1) {
                    fresh++; 
                }
            }
        }
        
        // BFS
        while(!q.empty() && fresh > 0) {
            time++;
            int s = q.size();

            while(s--) {
                pair<int, int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for(int k = 0; k < 4; k++) {
                    int row = r + x[k];
                    int col = c + y[k];

                    if(valid(row, col, m, n) && grid[row][col] == 1) {
                        q.push({row, col});
                        grid[row][col] = -2;
                        fresh--;
                    }
                }
            }
        }

        if(fresh > 0) return -1;

        return time;    
    }
};