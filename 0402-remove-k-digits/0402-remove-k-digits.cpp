class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;

        // pushing digits of num in stack in order to minimize the num value
        for(int i = 0; i < n; i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // to handle edge cases like 12345
        while(k > 0) {
            st.pop();
            k--;
        }

        // storing ans value 
        string ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        // to handle removal of leading zeros
        int i = 0;

        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        if(ans.empty()) {
            return "0";
        }

        return ans;

    }
};