class Solution {
public:
    void solve(string &digits, int idx, string &curr, vector<string> &res, unordered_map<char, string> &phone) {
        if(idx == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = phone[digits[idx]];

        for(char ch : letters) {
            curr.push_back(ch);
            solve(digits, idx + 1, curr, res, phone);

            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;

        unordered_map<char, string> phone = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string curr;

        solve(digits, 0, curr, res, phone);

        return res;
    }
};