/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isLeaf(Node* node){
        return (node -> left == NULL) && (node -> right == NULL);
    }
    
    void addLeftBoundaryElements(Node* root, vector<int> &result){
        Node* curr = root -> left;
        
        while(curr != NULL){
            if( !isLeaf(curr) ) result.push_back(curr -> data);
            
            if(curr -> left != NULL) curr = curr -> left;
            else curr = curr -> right;
        }
    }
    
    void addLeafNodes(Node* root, vector<int> &result){
        if(root == NULL) return;
        
        if( isLeaf(root) ){
            result.push_back(root -> data);
            return;
        }
        addLeafNodes(root -> left, result);
        addLeafNodes(root -> right, result);
    }
    
    void addRightBoundaryElements(Node* root, vector<int> & result){
        Node* curr = root -> right;
        vector<int> temp;
        
        while(curr != NULL){
            if( !isLeaf(curr) ) temp.push_back( curr -> data);
            
            if(curr -> right != NULL) curr = curr -> right;
            else curr = curr -> left;
        }
        
        for(int i = temp.size()-1; i>= 0; i--){
            result.push_back(temp[i]);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> result;
        
        if(root == NULL) return result;
        
        if( !isLeaf(root) ) result.push_back(root -> data);
        
        else{
            result.push_back(root -> data);
            return result;
        }
        
        addLeftBoundaryElements(root, result);
        addLeafNodes(root, result);
        addRightBoundaryElements(root, result);
        
        
        return result;
        
        
    }
};