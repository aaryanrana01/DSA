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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // col, row, node
        map<int, map<int, multiset<int> >> nodes;

        // node, col, row
        queue<pair <TreeNode*, pair< int, int> >> q;

        q.push({root, {0,0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int col = front.second.first;
            int row = front.second.second;

            nodes[col][row].insert(node -> val);

            if(node -> left != NULL) q.push({node->left, {col-1, row+1}});

            if(node -> right != NULL) q.push({node->right, {col+1, row+1}});

        }

        vector<vector<int>> ans;
        for(auto& colPair: nodes){
            vector<int> col;

            for(auto& rowPair: colPair.second){

                for(auto&value: rowPair.second){
                    col.push_back(value);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};