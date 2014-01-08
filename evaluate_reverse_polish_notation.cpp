#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty()) return 0;

        stack<int> s;
        for (int i = 0, l = tokens.size(); i < l; ++i)
        {
            string t = tokens[i];

            if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                int m = s.top();
                s.pop();
                int n = s.top();
                s.pop();

                if (t == "+") n += m;
                else if (t == "-") n -= m;
                else if (t == "*") n *= m;
                else n /= m;

                s.push(n);
            }
            else
            {
                s.push(atoi(t.c_str()));
            }
        }

        return s.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> v;
    v.push_back("3");
    v.push_back("4");
    v.push_back("+");
    cout << solution.evalRPN(v) << endl;

    v.clear();
    v.push_back("2");
    v.push_back("4");
    v.push_back("+");
    v.push_back("3");
    v.push_back("*");
    cout << solution.evalRPN(v) << endl;

    v.clear();
    v.push_back("0");
    v.push_back("3");
    v.push_back("/");
    cout << solution.evalRPN(v) << endl;
    
    return 0;
}