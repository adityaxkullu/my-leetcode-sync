class Solution {
public:
    // set<vector<int>> s;

    void getAllCombination(vector<int>& arr, int target, int idx, vector<vector<int>>& ans,  vector<int>& combin) {
        if(idx == arr.size() || target < 0) {
            return;
        }

        if(target == 0) {
            // if(s.find(combin) == s.end()){
            //     ans.push_back(combin);
            //     s.insert(combin);
            // }
            ans.push_back(combin);
            return;
        }



        combin.push_back(arr[idx]);

        //single
        // getAllCombination(arr, target - arr[idx], idx + 1, ans, combin);

        // multiple
        getAllCombination(arr, target - arr[idx], idx, ans, combin);
        
        // backtracking
        combin.pop_back();

        // exclusion
        getAllCombination(arr, target, idx + 1, ans, combin);


    }
   
    
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        
        getAllCombination(arr, target, 0, ans, combin);

        return ans;
    }
};