class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int sign = 1; // Default positive
        long long res = 0; // Use long long for potential overflow handling

        // Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '+') ? 1 : -1;
        }

        // Accumulate numeric characters
        while (i < n && std::isdigit(s[i])) {
            res = res * 10 + (s[i++] - '0');
            
            // Early termination on overflow
            if (res * sign > std::numeric_limits<int>::max()) {
                return std::numeric_limits<int>::max();
            }
            if (res * sign < std::numeric_limits<int>::min()) {
                return std::numeric_limits<int>::min();
            }
        }

        return static_cast<int>(res * sign);
    }
};