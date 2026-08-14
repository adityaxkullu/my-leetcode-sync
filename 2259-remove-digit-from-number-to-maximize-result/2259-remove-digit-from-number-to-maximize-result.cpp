class Solution {
public:
    string removeDigit(string num, char k) {
        int n = num.size();

        stack<int> s;
        int removeIdx = -1;

        for(int i = 0; i < n; i++) {
            if(num[i] == k) {
                if(i + 1 < n && num[i + 1] > k) {
                    removeIdx = i;
                    break;
                }

                removeIdx = i;
            }

            s.push(num[i]);
        }

        string ans;

        for(int i = 0; i < n; i++) {
            if(i != removeIdx) {
                ans.push_back(num[i]);
            }
        }

        return ans;
    
    }
};