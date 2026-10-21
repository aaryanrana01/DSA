/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node -> left){
                parent[node -> left] = node;
                q.push(node -> left);
            }

            if(node -> right){
                parent[node -> right] = node;
                q.push(node -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;
        if(root == NULL || target == NULL) return ans;

        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_map<TreeNode*, bool> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int level = 0;

        while(!q.empty()){
            int size = q.size();

            if(level == k) break;

            for(int i=0; i< size; i++){
                TreeNode* node = q.front();
                q.pop();

                // if child exist in the parent map, then there would be chances of parent existing
                if(parent.count(node) && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }

                if(node -> left && !visited[node -> left]){
                    visited[node -> left] = true;
                    q.push(node -> left);
                }

                if(node -> right && !visited[node -> right]){
                    visited[node -> right] = true;
                    q.push(node -> right);
                }
            }

            level++;

        }

        while(!q.empty()){
            int val = q.front() -> val;
            q.pop();

            ans.push_back(val);
        }


        return ans;

    }
};