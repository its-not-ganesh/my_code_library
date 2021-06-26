int count = 0;
    TreeNode* helper(vector<int>&inorder, vector<int>&postorder, int start, int end, int i, unordered_map<int,int>&m)
    {
        // cout << count << endl;
        // int n = postorder.size();
        if(i < 0 || start > end) 
            return NULL;
        TreeNode* root = new TreeNode;
        root->val = postorder[i];
        int idx = m[postorder[i]];
        count--;
        root->right = helper(inorder, postorder, idx+1, end, count, m);
        root->left = helper(inorder, postorder, start, idx-1, count, m);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> umap;
        int n = postorder.size();
        for(int i = 0; i < postorder.size(); i++)    
            umap[inorder[i]] = i;
        count = n-1;
        return helper(inorder, postorder, 0, n-1, count, umap);
    }
