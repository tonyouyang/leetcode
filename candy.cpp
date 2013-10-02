class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (ratings.empty()) return 0;
        
        int total_candy = 1;
        
        for (int i = 0, j = 0, prev_end_candy = 1, prev_dir = 1, curr_dir = 0; i < ratings.size(); ++i)
        {
            if (i != ratings.size() - 1)
            {
                if (ratings[i] < ratings[i + 1]) curr_dir = 1;
                else if (ratings[i] > ratings[i + 1]) curr_dir = -1;
                else curr_dir = 0;
            }
            
            if (i == ratings.size() - 1 || prev_dir != curr_dir)
            {
                if (prev_dir == 1)
                {
                    total_candy += (2 + i - j + 1) * (i - j) / 2;
                    prev_end_candy = i - j  + 1;
                }
                else if (prev_dir == -1)
                {
                    total_candy += (1 + i - j) * (i - j) / 2;
                    total_candy += max(0, i - j + 1 - prev_end_candy);
                    prev_end_candy = 1;
                }
                else
                {
                    total_candy += i - j;
                    prev_end_candy = 1;
                }
                
                j = i;
                prev_dir = curr_dir;
            }
        }
        
        return total_candy;
    }
};
