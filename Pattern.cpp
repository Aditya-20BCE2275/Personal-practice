class Solution
{
public:
    string longestPalindrome(string s)
    {
        // if(s.length() == 1)return s;
        unordered_map<char, int> ump;
        string ans = "";
        ans += s[0];
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (auto x : s[i])
            {
                j = ump[s[i]];
                string t = s.substr(j, i - j + 1);
                string te = t;
                reverse(t.begin(), t.end());
                if (te == t && t.length() > ans.length())
                {
                    ans = t;
                }
            }
            else
            {
                ump[s[i]] = i;
            }
        }
        return ans;
    }
};