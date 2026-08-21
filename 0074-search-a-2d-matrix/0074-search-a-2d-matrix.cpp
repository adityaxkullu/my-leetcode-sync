class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m * n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if(mat[row][col] == t) {
                return true; 
            }

            if(mat[row][col] > t) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        } 

        return false;
        
    }
};