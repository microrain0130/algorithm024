// 前序排列
class Solution {
public:
    vector<int> res;

    void _preorder(Node *root) {
        if (root == nullptr) return;
        res.push_back(root->val);

        for(int i = 0; i< root->children.size(); i++) {
            _preorder(root->children[i]);
        }
    }

    vector<int> preorder(Node* root) {
        _preorder(root);
        return res;
    }
};

// 中序排列
class Solution {
public:
    vector<int> res;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};


