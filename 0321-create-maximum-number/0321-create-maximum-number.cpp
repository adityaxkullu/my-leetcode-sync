class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        int remove = nums.size() - k;

        vector<int> st;

        for(int x : nums) {
            while(!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        while(remove > 0) {
            st.pop_back();
            remove--;
        }

        return st;
    }

    bool greaterSuffix(vector<int> &a, int i, vector<int> &b, int j) {
        while(i < a.size() && j < b.size()) {
            if(a[i] > b[j]) return true;
            if(a[i] < b[j]) return false;

            i++;
            j++;
        }

        return i != a.size();
    }

    vector<int> merge(vector<int> &a, vector<int> &b) {
        vector<int> result;

        int i = 0;
        int j = 0;

        while(i < a.size() || j < b.size()) {
            if(j == b.size() || (i < a.size() && greaterSuffix(a, i, b, j))) {
                result.push_back(a[i]);
                i++;
            }else {
                result.push_back(b[j]);
                j++;
            }
        }

        return result;
    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> answer;

        int n = nums1.size();
        int m = nums2.size();

        for(int x = max(0, k - m); x <= min(k, n); x++) {
            int y = k - x;

            vector<int> a = maxSubsequence(nums1, x);
            vector<int> b = maxSubsequence(nums2, y);

            vector<int> candidate = merge(a, b);

            if(answer.empty() || greaterSuffix(candidate, 0, answer, 0)) {
                answer = candidate;
            }
        }

        return answer;    
    }
};