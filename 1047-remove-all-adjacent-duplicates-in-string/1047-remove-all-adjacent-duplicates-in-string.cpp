class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char> st;
        string res;

        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }

            if(s[i] == st.top()) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }


        return res;
        
    }
};