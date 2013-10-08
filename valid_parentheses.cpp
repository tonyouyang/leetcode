class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<char> p;
        
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[') p.push(c);
            else if (p.empty()) return false;
            else if (p.top() == '(' && c != ')' || p.top() == '{' && c != '}' || p.top() == '[' && c != ']') return false;
            else p.pop();
        }
        
        return p.empty();
    }
};
