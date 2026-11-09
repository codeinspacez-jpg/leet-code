class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string next = "";
            for (int i = 0, j = 0; i < s.length(); i = j) {
                while (j < s.length() && s[j] == s[i]) j++;
                next += to_string(j - i) + s[i];
            }
            s = next;
        }
        return s;
    }
};