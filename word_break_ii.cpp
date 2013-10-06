class Solution {
public:
    vector<string> ret;
    bool wordBreak(string s, unordered_set<string> &dict, unordered_set<string> &miss, string current) {
        bool can_break = false;
        
        for (int i = 0; i < s.size(); ++i)
        {
            string prefix = s.substr(0, i + 1);
            
            if (dict.find(prefix) != dict.end()) {
                if (i == s.size() - 1) {
                    ret.push_back(current + prefix);
                    return true;
                }
                else
                {
                    string suffix = s.substr(i + 1);
                    
                    if (miss.find(suffix) == miss.end())
                    {
                        if (wordBreak(suffix, dict, miss, current + prefix + " ")) can_break = true;
                        else miss.insert(suffix);
                    }
                }
            }
        }
        
        return can_break;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret.clear();
        unordered_set<string> miss;
        wordBreak(s, dict, miss, "");
        return ret;
    }
};
