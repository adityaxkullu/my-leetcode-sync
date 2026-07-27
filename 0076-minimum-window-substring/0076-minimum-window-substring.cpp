class Solution {
public:
    bool compare(vector<int> & window, vector<int> & need) {
        for(int i = 0; i < 256; i++) {
            if(window[i] < need[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        int low = 0, start, res = m + 1;
        vector<int> window(256, 0);
        vector<int> need(256, 0);

        for(int i = 0; i < n; i++) {
            need[t[i]]++;
        }

        for(int high = 0; high < m; high++) {
            window[s[high]]++;

            while(compare(window, need)) {
                int len = high - low + 1;

                if(res > len) {
                    res = len;
                    start = low;
                }

                window[s[low]]--;
                low++;
            }
        }

        return s.substr(start, res);


        
    }
};