class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int s_row = 0, e_row = m-1, s_col = 0, e_col = n-1;

        vector<int> ans;

        while(s_row <= e_row && s_col <= e_col) {
            for(int j = s_col; j <= e_col; j++) {
                ans.push_back(mat[s_row][j]);
            }

            for(int i = s_row + 1; i <= e_row; i++) {
                ans.push_back(mat[i][e_col]);
            }

            for(int j = e_col - 1; j >= s_col; j--) {
                if(s_row == e_row) {
                    break;
                }
                ans.push_back(mat[e_row][j]);
            }

            for(int i = e_row - 1; i > s_row; i--) {
                if(s_col == e_col) {
                    break;
                }
                ans.push_back(mat[i][s_col]);
            }

            s_row++, s_col++, e_row--, e_col--;
        }

        return ans;
        
    }
};