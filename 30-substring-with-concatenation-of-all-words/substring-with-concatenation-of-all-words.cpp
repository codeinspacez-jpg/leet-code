#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string, int> mp;

        for (auto w : words) mp[w]++;

        int n = s.size(), len = words[0].size();

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j + len <= n; j += len) {
                string w = s.substr(j, len);

                if (mp.count(w)) {
                    seen[w]++;
                    count++;

                    while (seen[w] > mp[w]) {
                        seen[s.substr(left, len)]--;
                        left += len;
                        count--;
                    }

                    if (count == words.size())
                        ans.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return ans;
    }
};