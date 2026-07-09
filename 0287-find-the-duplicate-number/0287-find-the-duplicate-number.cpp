class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        unordered_set<int> s;

        for(int i = 0; i <= n; i++) {
            if(s.find(a[i]) != s.end()) {
                return a[i];
            }

            s.insert(a[i]);
        }

        return 0;


        
    }
};