class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3) return target;
        
        sort(num.begin(), num.end());
        int closest = num[0] + num[1] + num[2];
        
        for (int i = 0; i < num.size(); ++i)
        {
            for (int j = i + 1, k = num.size() - 1; j < k; )
            {
                int delta = num[i] + num[j] + num[k] - target;
                if (abs(closest - target) > abs(delta)) closest = target + delta;
                
                if (delta > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        
        return closest;
    }
};
