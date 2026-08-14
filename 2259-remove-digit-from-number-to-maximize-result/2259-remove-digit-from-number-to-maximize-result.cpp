class Solution {
public:
    string removeDigit(string num, char k) {
        int n = num.size();

        for(int i = 0; i < n - 1; i++) {
            if(num[i] == k && num[i + 1] > k) {
                return num.substr(0, i) + num.substr(i + 1);
            }
        }

        int pos;
        for(int i = n - 1; i >= 0; i--) {
            if(num[i] == k) {
            pos = i;
            break;
            }
        }

        return num.substr(0, pos) + num.substr(pos + 1);
    
    }
};