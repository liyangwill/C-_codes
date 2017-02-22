class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // four indice, start and end in preorder and inorder
        return create(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps>pe){
            return nullptr; //return null TreeNode "nullptr"
        }
        TreeNode* node = new TreeNode(preorder[ps]); //create new TreeNode* node with val=preorder[ps]
        int pos;  // position index of preorder[ds] in inorder/
        // find pos
        for (i = is; i<=ie; i++){
            if(inorder[i]==preorder[ps]){
                pos=i;
                break;
            }
        }
        // DP create left and right TreeNode
        node->left = create(preoder, inorder,ps+1, ps+pos-is is, pos-1);
        node->right = create(preoder, inorder, pe-ie+pos+1, pe, pos+1, ie);
        return node;
    }
};