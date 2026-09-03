class Solution {
public:
    void solve(vector<int> &a, int idx, int sum, int target, vector<int> &diary, vector<vector<int>> &res) {
        int n = a.size();
        if(idx == n) {
            if(sum == target) {
                res.push_back(diary);
            }

            return;
        }
        
        int next = idx + 1;

        while(next < n && a[next] == a[idx]) next++;

        solve(a, next, sum, target, diary, res);

        if(sum + a[idx] <= target) {
            diary.push_back(a[idx]);
            sum += a[idx];

            solve(a, idx + 1, sum, target, diary, res);

            diary.pop_back();
            sum -= a[idx];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<vector<int>> res;
        vector<int> diary;

        sort(a.begin(), a.end());

        solve(a, 0, 0, target, diary, res);

        return res;    
    }
};