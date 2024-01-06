#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int i, int k, int n, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (k == 0 && n == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j <= 9; ++j)
        {
            temp.push_back(j);
            solve(j + 1, k - 1, n - j, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, temp, ans);
        return ans;
    }
};