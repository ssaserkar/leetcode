/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: Check if both trees are empty (null)
        //if p is null and q is null:
        //return true
        bool leftcheck = false, rightcheck = false;
        if(p== NULL && q== NULL) return true;
    
        // Base case: Check if one tree is empty while the other is not
        // if p is null or q is null:
        //    return false
        if(p == NULL || q == NULL) return false;
        // Check if current nodes of both trees have the same value
        // if p.val is not equal to q.val:
        //    return false
        if(p->val != q->val) return false;
        // Recursively check left and right subtrees
        //leftSame := isSameTree(p.left, q.left)
        //rightSame := isSameTree(p.right, q.right)
        leftcheck = isSameTree(p->left, q->left);
        rightcheck = isSameTree(p->right, q->right);
        
        return (leftcheck && rightcheck);
    }
};
