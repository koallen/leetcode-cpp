/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <algorithm>
 
using namespace std;
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        
        // post order traversal
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        return (((left != 0) && (right != 0)) ? min(left, right) : max(left, right)) + 1;
    }
};
