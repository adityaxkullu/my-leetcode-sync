class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int res = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<int, int> m;
            for(int j = i; j < n; j++) {
                if(m.find(s[j]) != m.end()) break;


                m[s[j]]++;
                res = max(res, j - i + 1);    
            }
        }

        return res;
       
    }
};