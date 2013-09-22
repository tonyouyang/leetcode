class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0) return 0;
        
        map<int, int> m;
        int ret = 1;
        
        for (int i = 0; i < num.size(); ++i)
        {
            if (m.find(num[i]) == m.end())
            {
                m[num[i]] = 1;
                if (m.find(num[i] - 1) != m.end())
                {
                    int l = m[num[i] - 1] + 1;
                    m[num[i]] = l;
                    m[num[i] - m[num[i] - 1]] = l;
                    ret = max(ret, l);
                }
                if (m.find(num[i] + 1) != m.end())
                {
                    int l = m[num[i] + 1] + m[num[i]];
                    m[num[i] - m[num[i]] + 1] = l;
                    m[num[i] + m[num[i] + 1]] = l;
                    ret = max(ret, l);
                }
            }
        }
        
        return ret;
    }
};
