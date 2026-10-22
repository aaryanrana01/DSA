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
    int findHeight(TreeNode* root, bool leftHt){
        int count = 0;

        while(root){
            if(leftHt){
                count++;
                root = root -> left;
            }

            else{
                count++;
                root = root -> right;
            }
        }

        return count;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findHeight(root, true);
        int rh = findHeight(root, false);

        if(lh == rh) return (1<<lh) - 1;

        return 1+ countNodes(root -> left)+ countNodes(root -> right);
    }
};