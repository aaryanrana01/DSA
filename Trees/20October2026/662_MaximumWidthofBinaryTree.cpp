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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        unsigned long long maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});
        while(!q.empty()){
            unsigned long long first, last;
            unsigned long long minInd = q.front().second;
            int size = q.size();
            unsigned long long width;

            for(int i=0; i< size; i++){
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                unsigned long long index = it.second - minInd;

                if(i == 0) first = index;
                if(i == size-1) last = index;

                if(node -> left != NULL) q.push({node -> left, 2*index + 1});
                if(node -> right != NULL) q.push({node -> right, 2*index + 2});
            }

            width = last - first + 1;
            maxWidth = max(maxWidth, width);
        }

        return (int)maxWidth;
    }
};