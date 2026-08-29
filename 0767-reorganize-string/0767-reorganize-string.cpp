class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = 0,maxChar;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        if(maxFreq > (n + 1) / 2) return "";

        string res(n, ' ');
        int idx = 0;

        while(freq[maxChar] > 0) {
            res[idx] = char('a' + maxChar);

            idx += 2;
            freq[maxChar]--;
        }

        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                if(idx >= n) idx = 1;

                res[idx] = char('a' + i);
                idx += 2;
                freq[i]--;
            }
        }

        return res;

    }
};