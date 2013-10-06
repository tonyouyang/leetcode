class Solution {
public:
    vector<string> ret;
    bool wordBreak(string s, int start, unordered_set<string> &dict, vector<bool> &miss, string current) {
        bool can_break = false;
        
        for (int i = 1; start + i - 1 < s.size(); ++i)
        {
            string prefix = s.substr(start, i);
            
            if (dict.find(prefix) != dict.end()) {
                if (start + i == s.size()) {
                    ret.push_back(current + prefix);
                    return true;
                }
                else
                {
                    // 0 ... start .... start + i - 1, start + i ... size - 1
                    if (!miss[start + i])
                    {
                        string suffix = s.substr(i + 1);
                        
                        if (wordBreak(s, start + i, dict, miss, current + prefix + " ")) can_break = true;
                        else miss[start + i] = true;
                    }
                }
            }
        }
        
        return can_break;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret.clear();
        vector<bool> miss(s.size(), false);
        wordBreak(s, 0, dict, miss, "");
        return ret;
    }
};
