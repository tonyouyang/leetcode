class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (path.empty()) return "";
        
        stack<string> dir;
        path += "/";
        string ret("");
        
        for (int i = 1, j = 1; j < path.size(); ++j)
        {
            if (path[j] == '/')
            {
                string s = path.substr(i, j - i);
                if (s == "..")
                {
                    if (!dir.empty()) dir.pop();
                }
                else
                {
                    if (!s.empty() && s != ".") dir.push(s);
                }
                i = j + 1;
            }
        }
        
        if (dir.empty()) return "/";
        
        while (!dir.empty())
        {
            ret = "/" + dir.top() + ret;
            dir.pop();
        }
        
        return ret;
    }
};
