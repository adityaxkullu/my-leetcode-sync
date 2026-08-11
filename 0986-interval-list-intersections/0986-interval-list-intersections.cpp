class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> ans;
        int i = 0, j = 0, s, e; 

        while(i < n && j < m) {
            int start1 = a[i][0], end1 = a[i][1];
            int start2 = b[j][0], end2 = b[j][1];

            if(start1 <= start2) {
                if(end1 >= start2) {
                    s = max(start1, start2);
                    e = min(end1, end2);

                    ans.push_back({s, e});
                }
            }else {
                if(end2 >= start1) {
                    s = max(start1, start2);
                    e = min(end1, end2);

                    ans.push_back({s, e}); 
                }
            }

            if(end1 <= end2) {
                i++;
            }else {
                j++;
            }

        }

        return ans;

    }
};