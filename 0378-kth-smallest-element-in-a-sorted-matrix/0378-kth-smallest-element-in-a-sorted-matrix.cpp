class Solution {
public:
    int countSmallest(vector<vector<int>> & mat, int n, int m, int guess) {
        int row = n - 1, col = 0, count = 0;

        while(row >= 0 && col < m) {
            if(mat[row][col] <= guess) {
                count += row + 1;
                col++;
            }else {
                row--;
            }
        }

        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        int low = mat[0][0], high = mat[n - 1][m - 1], res = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int ans = countSmallest(mat, n, m, mid);

            if(ans < k) {
                low = mid + 1;
            }else {
                res = mid;
                high = mid - 1;
            }
        }

        return res;
        
    }
};