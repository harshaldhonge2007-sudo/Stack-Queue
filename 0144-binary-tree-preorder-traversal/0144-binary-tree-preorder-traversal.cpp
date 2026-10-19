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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> preorder;
        TreeNode* node = root;

        if (node == nullptr) return preorder;

        st.push(node);

        while (!st.empty()) {
            node = st.top();
            st.pop();

            preorder.push_back(node->val);

            if (node->right != nullptr) {
                st.push(node->right);
            }

            if (node->left != nullptr) {
                st.push(node->left);
            }
        }

        return preorder;
    }
};
