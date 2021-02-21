// 二叉树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // terminal
        if (!root || !p || !q || p == root || q == root) return root;

        // drill down
        TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);

         // process logic in current level
         if (!leftTree && !rightTree) return NULL;
         if (leftTree && rightTree) return root;
         if (!leftTree && rightTree) return rightTree;
         if (leftTree && !rightTree) return leftTree;

        return NULL;
    }
};

// 组合
class Solution {
private:
        void _backtracking(int n, int k, int startIndex, vector<vector<int>>& result, vector<int>& path) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i); // 处理节点
            _backtracking(n, k, i + 1, result, path);
            path.pop_back(); // 回溯，撤销处理的节点
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        _backtracking(n, k, 1, result, path);
        return result;
    }
};

// 从前序与中序遍历序列构造二叉树
class Solution {
private:
    unordered_map<int, int> index;
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        TreeNode* root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }

        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// 全排列
class Solution {
private:
    void backtracking(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        if (first == len) {
            res.emplace_back(output);
            return;
        }

        for (int i = first; i < len; ++i) {
            swap(output[i],output[first]);
            backtracking(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(res, nums, 0, nums.size());
        return res;
    }
};






























