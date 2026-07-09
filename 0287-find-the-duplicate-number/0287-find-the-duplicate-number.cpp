class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        for(int i = 1; i < n; i++) {
            if(i != 0 && a[i] == a[i-1]) {
                return a[i];
            }
        }

        return -1;
       


        
    }
};