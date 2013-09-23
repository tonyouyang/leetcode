class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (T.size() > S.size() || T.empty()) return "";
        
        unordered_map<char, int> need;
        unordered_set<char> need_need;
        int min_start = 0, min_end = S.size() - 1;
        string ret;
        
        for (char ch : T)
        {
            need[ch] = need.find(ch) == need.end() ? 1 : need[ch] + 1;
            need_need.insert(ch);
        }
        
        for (int i = 0, j = 0, current_start = 0; i < S.size(); ++i)
        {
            if (need.find(S[i]) != need.end())
            {
                if (--need[S[i]] <= 0 && !need_need.empty()) need_need.erase(S[i]);
                if (++j >= T.size() && need_need.empty())
                {
                    int k = current_start;
                    while (true)
                    {
                        if (need.find(S[k]) != need.end())
                        {
                            if (need[S[k]] == 0) break;
                            need[S[k]]++;
                        }
                        k++;
                    }
                    current_start = k;
                    if (i - current_start < min_end - min_start)
                    {
                        min_end = i;
                        min_start = current_start;
                    }
                }
            }
        }
        
        if (!need_need.empty()) return "";
        
        for (ret = ""; min_start <= min_end; ret += S[min_start++]);
        return ret;
    }
};
