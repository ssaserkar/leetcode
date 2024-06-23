class Solution {
public:
    int mySqrt(int n) {
       if (n < 2) {
        return n;
    }
    long int low = 1, high = n;
    while (low <= high) {
        long int mid = (low + high) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
    }
};