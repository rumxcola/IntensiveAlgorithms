#pragma once

#include <vector>
#include <unordered_map>
#include <queue>

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::unordered_map<TreeNode*, TreeNode*> parent;
        dfs(root, nullptr, parent);

        std::vector<int> result;
        std::unordered_map<TreeNode*, bool> visited;
        std::queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level == k) {
                for (int i = 0; i < size; ++i) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }

            ++level;
        }

        return result;
    }

private:
    void dfs(TreeNode* node, TreeNode* par, std::unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node)
            return;

        parent[node] = par;
        dfs(node->left, node, parent);
        dfs(node->right, node, parent);
    }
};
