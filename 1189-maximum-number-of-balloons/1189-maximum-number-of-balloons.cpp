class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> need;
        unordered_map<char, int> have;
        string s = "balloon";

        for(int i = 0; i < s.size(); i++) {
            need[s[i]]++;
        }

        for(int i = 0; i < text.size(); i++) {
            have[text[i]]++;
        }
        
        int res = INT_MAX;
        for(auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            int times = fhave / fneed;

            res = min(res, times);
        }

        return res;    
    }
};