class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for(int i = (2 * n - 1); i >= 0; i--) {
            while(!s.empty() && a[s.top()] <= a[i % n]) {
                s.pop();
            }

            if(!s.empty()) {
                ans[i % n] = a[s.top()];
            } 
            s.push(i % n);  
        }

        return ans;
        
    }
};