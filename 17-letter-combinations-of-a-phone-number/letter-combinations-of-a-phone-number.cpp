class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string temp = "";

        function<void(int)> solve = [&](int index) {

            if (index == digits.size()) {
                ans.push_back(temp);
                return;
            }

            string letters = mp[digits[index] - '0'];

            for (char c : letters) {
                temp.push_back(c);
                solve(index + 1);
                temp.pop_back();
            }
        };

        solve(0);

        return ans;
    }
};