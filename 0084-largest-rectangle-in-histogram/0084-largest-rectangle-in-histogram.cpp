class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> s;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            while(!s.empty() && h[s.top()] >= h[i]) {
                s.pop();
            }

            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

         while(!s.empty()) {
            s.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && h[s.top()] >= h[i]) {
                s.pop();
            }

            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for(int i = 0; i < n; i++) {
            int x = h[i] * (right[i] - left[i] - 1);
            ans = max(ans, x);
        }

        return ans;

        
    }
};