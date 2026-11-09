class Solution {
    void dfs(vector<int>& c, int t, int s, vector<int>& cur, vector<vector<int>>& res) {
        if (t == 0) { res.push_back(cur); return; }
        for (int i = s; i < c.size() && c[i] <= t; ++i) {
            if (i > s && c[i] == c[i - 1]) continue; // Skip duplicates
            cur.push_back(c[i]);
            dfs(c, t - c[i], i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res; vector<int> cur;
        dfs(candidates, target, 0, cur, res);
        return res;
    }
};