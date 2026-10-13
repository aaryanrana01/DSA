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
    int pathSum(TreeNode* root, int &sum){
        if(root == NULL) return 0;

        int lh = pathSum(root -> left, sum);
        if(lh < 0) lh =0;

        int rh = pathSum(root -> right, sum);
        if(rh < 0) rh =0;

        sum = max(sum, lh+rh+root -> val);

        return max(lh, rh) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        pathSum(root, sum);
        return sum;
    }
};