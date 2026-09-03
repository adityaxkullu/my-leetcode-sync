class Solution {
public:
    void solve(int idx, int sum, int k, int target, vector<int> &diary, vector<vector<int>> &res) {
        // idx is not index no but the actual value of number from 1 through 9

        if(idx == 10) {
            if(diary.size() == k && sum == target) {
                res.push_back(diary);
            }

            return;
        }

        solve(idx + 1, sum, k, target, diary, res);

        if(diary.size() < k && sum + idx <= target) {
            diary.push_back(idx);
            sum += idx;

            solve(idx + 1, sum, k, target, diary, res);

            diary.pop_back();
            sum -= idx;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> diary;

        solve(1, 0, k, n, diary, res);

        return res;    
    }
};