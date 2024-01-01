#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
            // code here
            unordered_map<int, int> mp;
            vector<int> ans;
            
            for (int i = 0; i < n; i++) {
                if (mp[arr[i]]) {
                    ans.push_back(arr[i]);
                }
                mp[arr[i]]++;
            }
            
            int i = 1;
            while (true) {
                if (mp.count(i) == 0) {
                    ans.push_back(i);
                    break;
                }
                i++;
            }
            
            return ans;
        }
};