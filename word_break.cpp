class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<bool> seg(s.size() + 1, false);
        seg[0] = true;
        
        for (int i = 0; i <= s.size(); ++i)
        {
            if (seg[i])
            {
                for (int j = 1; i + j <= s.size(); ++j)
                {
                    seg[i + j] = seg[i + j] || (dict.find(s.substr(i, j)) != dict.end());
                }
            }
        }
        
        return seg[s.size()];
    }
};
