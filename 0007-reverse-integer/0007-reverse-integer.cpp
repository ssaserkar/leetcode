class Solution {
public:
    int reverse(int x) {
        // Constants for 32-bit signed integer range
        const int MY_INT_MAX = std::numeric_limits<int>::max();
        const int MY_INT_MIN = std::numeric_limits<int>::min();
        
        // Extract sign and absolute value
        int sign = (x >= 0) ? 1 : -1;
        long abs_x = labs(static_cast<long>(x)); // Use long to handle potential overflow
        
        // Reverse the digits
        long reversed_x = 0;
        while (abs_x != 0) {
            int digit = abs_x % 10;
            reversed_x = reversed_x * 10 + digit;
            abs_x /= 10;
        }
        
        // Apply sign to reversed result
        reversed_x *= sign;
        
        // Check for 32-bit integer overflow
        if (reversed_x > MY_INT_MAX || reversed_x < MY_INT_MIN) {
            return 0;
        }
        
        return static_cast<int>(reversed_x);
    }
};