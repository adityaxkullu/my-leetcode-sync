class Solution {
public:
    string removeDuplicates(string str, int k) {
        int n = str.size();
        stack<pair<char, int>> s;
        string res;

        for(int i = n - 1; i >= 0; i--) {
            int c = str[i];

            if(!s.empty() && s.top().first == c) {
                s.top().second++;

                if(s.top().second == k) {
                    s.pop();
                }
            }else {
                s.push({c, 1});
            }
        }

        while(!s.empty()) {
            int ch = s.top().first;
            int count = s.top().second;

            s.pop();

            for(int i = 0; i < count; i++) {
                res.push_back(ch);
            }
        }

        return res;

       
    }
};