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
        std::queue<TreeNode*> queue;
        queue.push(p);
        queue.push(q);
        
        while (!queue.empty()) {
            TreeNode* nodeP = queue.front();
            queue.pop();
            TreeNode* nodeQ = queue.front();
            queue.pop();
            
            if (nodeP == nullptr && nodeQ == nullptr) {
                continue;
            }
            
            if (nodeP == nullptr || nodeQ == nullptr || nodeP->val != nodeQ->val) {
                return false;
            }
            
            queue.push(nodeP->left);
            queue.push(nodeQ->left);
            queue.push(nodeP->right);
            queue.push(nodeQ->right);
        }
        
        return true;
    }
};