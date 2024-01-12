/*************************************************************

class Solution {
    void convert(TreeNode* root, int parent, unordered_map<int, vector<int>>& list) {
        if (root == nullptr)    return;

        if (parent) {
            list[root->val].push_back(parent);
        }
        if (root->left) {
            list[root->val].push_back(root->left->val);
        }
        if (root->right) {
            list[root->val].push_back(root->right->val);
        }
        convert(root->left, root->val, list);
        convert(root->right, root->val, list);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> list;
        convert(root, 0, list);

        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        int min = 0;

        while (!q.empty()) {
            int level = q.size();
            while (level > 0) {
                int curr = q.front();
                q.pop();

                for (int num : list[curr]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                level--;
            }
            min++;
        }
        return --min;
    }
};
**************************************************************/