class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        unordered_map<string, int> a;
        
        for (int i = 0; i < strs.size(); ++i)
        {
            string k(strs[i]);
            sort(k.begin(), k.end());
            if (a.find(k) == a.end())
            {
                a[k] = i;
            }
            else
            {
                if (a[k] >= 0)
                {
                    ret.push_back(strs[a[k]]);
                    a[k] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        
        return ret;
    }
};
