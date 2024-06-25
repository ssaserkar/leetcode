class Solution {
public:
    int myAtoi(string s) {
         int i = 0;
        int n = s.length();
        int positive = 1; // flag for positive/negative sign
        long long res = 0; // long long to handle potential overflow before converting to int

        // Skip leading whitespace
        while (i < n && std::isspace(s[i])) {
            i++;
        }

        // Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            positive = (s[i] == '+') ? 1 : -1;
            i++;
        }

        // Read numeric characters
        while (i < n && std::isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            
            // Check for overflow
            if (res > std::numeric_limits<int>::max()) {
                return (positive == 1) ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            }
            
            i++;
        }

        // Apply sign and return result
        return positive * res;
    }
};