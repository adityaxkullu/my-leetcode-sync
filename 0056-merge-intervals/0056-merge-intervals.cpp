class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<vector<int>> ans;

      int left = intervals[0][0];
      int right = intervals[0][1];
      
      for(int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if(start <= right) {
            right = max(right, end);
        } else {
            ans.push_back({left, right});

            left = start;
            right = end;
        }
      }
      ans.push_back({left, right});
      return ans;
      
          
    }
};