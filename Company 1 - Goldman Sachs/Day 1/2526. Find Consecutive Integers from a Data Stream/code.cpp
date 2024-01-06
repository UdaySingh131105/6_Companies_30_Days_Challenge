#include <bits/stdc++.h>
using namespace std;

class DataStream {
private:
    deque<int> stream;
    unordered_map<int, int> freq;
    int value;
    int k;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (stream.size() == k) {
            int ele = stream.front();
            stream.pop_front();
            freq[ele]--;
            stream.push_back(num);
            freq[num]++;
            return freq[value] == k;
        } else if (stream.size() == k-1) {
            stream.push_back(num);
            freq[num]++;
            return freq[value] == k;
        }

        stream.push_back(num);
        freq[num]++;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */