/**
 * Delete a node from BST
 * 
 */

class Solution {
public:
        struct TreeNode* Delete(struct TreeNode *root, int data){
                if(root == Null) return root;
                else if(data < root->data) root->left=Delete(root->left, data);
                else if(data > root->data) root->right=Delete(root->right, data);
                else{ //Find the data 
                        if(!root->left && !root->right){ //case 1: no child node, simply delete
                                delete root;
                                root=Null;
                        }
                        else if(!root->left){//case 2: no left child
                                struct TreeNode *temp=root;
                                root = root->left;
                                delete temp;
                        }
                        else{//case 3: two children notes exist, find the min in the right tree
                                struct TreeNode *temp = FindMin(root->right);
                                root->data=temp->data;
                                root->right=Delete(root->right, temp->data);
                        }
                }
                return root;
        }
};