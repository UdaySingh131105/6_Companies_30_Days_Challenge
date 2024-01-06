#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to print the minimum number following the given pattern
    string printMinNumberForPattern(string S) {
        int n = S.size();
        string result;
        stack<int> stk;

        // Iterate through the pattern and process each character
        for (int i = 0; i <= n; ++i) {
            // Push the current digit onto the stack
            stk.push(i + 1);

            // If 'I' is encountered or end of the pattern,
            // pop the digits from the stack and append to the result
            if (i == n || S[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
    }
};