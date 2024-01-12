/***********************************************************-**************************
 
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(i);
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        vector<int> answer;
        int elements = ans.size() - k;
        sort(ans.begin()+elements, ans.end(), cmp);
        for (int i = elements; i < ans.size(); i++) {
            answer.push_back(ans[i][0]);
        }

        return answer;
    }
};

***************************************************************************************/