class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while(n != 0) {
            int dig = n % 10;
            sum += dig * dig;

            n = n / 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        slow = digitSum(slow);
        fast = digitSum(digitSum(fast));

        while(slow != fast) {
            slow = digitSum(slow);
            fast = digitSum(digitSum(fast));
        }
        
        return slow == 1;    
    }
};