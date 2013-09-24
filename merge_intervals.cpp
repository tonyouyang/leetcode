/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compare(const Interval &i, const Interval &j)
    {
        return i.start < j.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        if (intervals.empty()) return ret;
        
        sort(intervals.begin(), intervals.end(), compare);
        int l = intervals[0].start, r = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start <= r)
            {
                r = max(r, intervals[i].end);
            }
            else
            {
                ret.push_back(Interval(l, r));
                l = intervals[i].start;
                r = intervals[i].end;
            }
        }
        ret.push_back(Interval(l, r));
        
        return ret;
    }
};
