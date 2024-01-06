#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};

        vector<string> map{"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans{""};
        int ptr = 0;
        int n = digits.size();

        while (ptr < n) {
            int digit = digits[ptr] - '0';
            vector<string> temp;
            for (auto str : ans) {
                string newstr = str;
                for (auto s : map[digit]) {
                    newstr = str + s;
                    temp.push_back(newstr);
                }
            }
            ans.clear();
            for (string comb : temp) {
                ans.push_back(comb);
            }
            ptr++;
        }

        return ans;
    }
};