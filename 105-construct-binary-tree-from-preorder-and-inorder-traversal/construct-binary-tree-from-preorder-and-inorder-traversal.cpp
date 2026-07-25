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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        
        // store inorder index
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, 0, inorder.size() - 1, preIndex, inMap);
    }

    TreeNode* build(vector<int>& preorder, int inStart, int inEnd,
                    int& preIndex, unordered_map<int, int>& inMap) {
        
        if (inStart > inEnd) return NULL;

        // pick root from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // split inorder
        int inIndex = inMap[rootVal];

        // build left subtree
        root->left = build(preorder, inStart, inIndex - 1, preIndex, inMap);

        // build right subtree
        root->right = build(preorder, inIndex + 1, inEnd, preIndex, inMap);

        return root;
    }
};