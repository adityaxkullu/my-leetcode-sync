class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();

        int i = 0, j = i + 1;

        while(j < n) {
            if(a[i] != a[j]) {
                a[i + 1] = a[j];
                i++;
            }
            j++;
        }

        return i + 1;
        
    }
};