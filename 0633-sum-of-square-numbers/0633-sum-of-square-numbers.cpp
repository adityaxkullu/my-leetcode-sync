class Solution {
public:
    bool judgeSquareSum(int c) {
      int a = sqrt(c);

      long long left = 0, right = a;

      while(left <= right) {
        long long sum = right * right + left * left;

        if(sum == c) {
            return true;
        }else if (sum < c) {
            left++;
        } else {
            right--;
        }
      }

      return false;

        
    }
};