#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s(10, 0);
        vector<int> g(10, 0);
        int x = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])  x++;
            else {
                int ns = secret[i] - '0';
                int ng = guess[i] - '0';

                s[ns]++;
                g[ng]++;
            }
        }

        int y = 0;

        for (int i = 0; i < 10; i++) {
            int temp = min(s[i], g[i]);
            y += temp;
        }

        return to_string(x)+"A"+to_string(y)+"B";
    }
};