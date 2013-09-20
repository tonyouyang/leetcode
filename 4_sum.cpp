class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (num.size() < 4) return ret;

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 3; ++i)
        {
            for (int j = num.size() - 1; j - i > 2; --j)
            {
                for (int p = i + 1, q = j - 1; p < q; )
                {
                    int sum = num[i] + num[p] + num[q] + num[j];

                    if (sum > target)
                    {
                        q--;
                    }
                    else if (sum < target)
                    {
                        p++;
                    }
                    else
                    {
                        vector<int> quad(4);
                        quad[0] = num[i]; quad[1] = num[p]; quad[2] = num[q]; quad[3] = num[j];
                        ret.push_back(quad);
                        p++;
                        q--;
                        while (p < q && num[p - 1] == num[p]) p++;
                        while (q > p && num[q + 1] == num[q]) q--;
                    }
                }

                while (j - 1 - i > 2 && num[j] == num[j - 1]) j--;
            }

            while (i + 1 < num.size() - 3 && num[i] == num[i + 1]) i++;
        }

        return ret;
    }
};
