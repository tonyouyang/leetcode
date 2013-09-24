class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret("");
        
        for (int i = a.size() - 1, j = b.size() - 1, c = 0; i >= 0 || j >= 0 || c != 0; --i, --j)
        {
            int aa = i >= 0 ? a[i] - '0' : 0, bb = j >= 0 ? b[j] - '0' : 0;
            ret += '0' + (aa ^ bb ^ c);
            c = aa + bb + c >= 2 ? 1 : 0;
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};
