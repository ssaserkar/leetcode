class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generateParenthesisHelper(n, n, current, result);
        return result;
    }
    
private:
    void generateParenthesisHelper(int left, int right, string& current, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        
        if (left > 0) {
            current.push_back('(');
            generateParenthesisHelper(left - 1, right, current, result);
            current.pop_back(); // Backtrack
        }
        
        if (right > left) {
            current.push_back(')');
            generateParenthesisHelper(left, right - 1, current, result);
            current.pop_back(); // Backtrack
        }
    }
};