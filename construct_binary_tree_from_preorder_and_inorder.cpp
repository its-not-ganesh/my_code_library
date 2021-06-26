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

int count = 0;
    TreeNode* helper(vector<int>&inorder, vector<int>&preorder, int start, int end, int i, map<int,int> &m)
    {
            if(i > preorder.size() || start > end) return NULL;
        
        struct TreeNode* root = new struct TreeNode;
        int idx = m[preorder[i]];
        root->val = preorder[i];
        count++;
        root->left = helper(inorder, preorder, start, idx-1, count, m);
        root->right = helper(inorder, preorder, idx+1, end, count, m);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> map;
        int n = preorder.size();
        for(int i = 0; i < n; i++)    
        {
            map[inorder[i]] = i;
            // umap[postorder[i]].first = i;
        }
            
        
        return helper(inorder, preorder, 0, n-1, 0, map);
    }
