//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


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

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL)
        return {};
    TreeNode* temp;
    queue<TreeNode*> q;
    queue<TreeNode*> next_q;
    q.push(root);
    vector<int> x;
    int level = 0;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        x.push_back(temp->val);
        if(temp->left != NULL)
            next_q.push(temp->left);

        if(temp->right != NULL)
            next_q.push(temp->right);

        if(q.empty()){
            ans.push_back(x);
            x.clear();
            q = next_q;
            while(!next_q.empty())
                next_q.pop();
        }


        // cout << temp->val << " " << kids << " " << count << endl;
    }

    return ans;
  }
