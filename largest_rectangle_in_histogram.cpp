class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<pair<int, int>> s;
        int max_area = 0;
        height.push_back(0);
        
        for (int i = 0, l = height.size(); i != l; ++i)
        {
            if (s.empty() || s.top().first < height[i])
            {
                s.push(pair<int, int> (height[i], i));
            }
            else if (s.top().first > height[i])
            {
                int pos;
                
                while (!s.empty() && s.top().first >= height[i])
                {
                    max_area = max(max_area, s.top().first * (i - s.top().second + (height[i] == s.top().first ? 1 : 0)));
                    pos = s.top().second;
                    s.pop();
                }
                s.push(pair<int, int> (height[i], s.empty() ? 0 : pos));
            }
        }
        
        return max_area;
    }
};
