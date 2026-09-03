class Solution {
public:
    void solve(vector<int> &a, int idx, int sum, int target, vector<int> dairy, vector<vector<int>> &res) {
        int n = a.size();
        if(idx == n) {
            if(sum == target) {
                res.push_back(dairy);
            }

            return;
        }

        solve(a, idx + 1, sum, target, dairy, res);

        if(a[idx] + sum <= target) {
            dairy.push_back(a[idx]);
            sum += a[idx];
            
            solve(a, idx, sum, target, dairy, res);

            dairy.pop_back();
            sum -= a[idx];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>> res;
        vector<int> dairy;

        solve(a, 0, 0, target, dairy, res);

        return res;    
    }
};