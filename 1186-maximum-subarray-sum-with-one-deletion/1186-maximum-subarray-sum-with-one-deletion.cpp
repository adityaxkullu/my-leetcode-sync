class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        int onedelete = INT_MIN, nodelete = a[0], ans = a[0];

        for(int i = 1; i < n; i++) {
            int prevonedelete = onedelete;
            int prevnodelete = nodelete;

            nodelete = max(prevnodelete + a[i], a[i]);

            if(prevonedelete == INT_MIN) {
                onedelete = prevnodelete;
            }else {
                onedelete = max(prevnodelete, prevonedelete + a[i]);
            }
            
            ans = max(ans, max(onedelete, nodelete));
        }

        return ans;
        
    }
};