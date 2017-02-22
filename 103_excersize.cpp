class Solution{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        if( root == NULL){
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool LeftToRight = true;
        
        while (!nodesQueue.empty() {
            int size=nodesQueue.size();
            vector<int> row(size);
            for(int i=0; i<size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                
                int index = LeftToRight ? i : size-1-i;
                row[index] = node->val;
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
            LeftToRight = ! LeftToRight;
            result.push_back(row);
        }
        return result;
    }
};