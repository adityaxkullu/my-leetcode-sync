class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();
        unordered_map<int, int> m;

        for(int i = 0 ; i < n ; i++) {
            int complement = target - a[i];

            if(m.find(complement) != m.end()) {
                return{m[complement], i};
            }

            m[a[i]] = i;
        }
        return {};
        
    }
};