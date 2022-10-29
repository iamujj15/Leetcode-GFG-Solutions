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
    bool ck(TreeNode* l, TreeNode* r)
    {
        if (l == nullptr && r == nullptr)
            return true;
        if (l != nullptr && r != nullptr && l->val == r->val && ck(l->left, r->right) && ck(l->right, r->left))
            return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
            return true;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        return ck(l, r);
    }
};