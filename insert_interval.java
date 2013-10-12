/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<Interval> ret = new ArrayList<Interval> ();
        
        Boolean flag = false;
        int l = newInterval.start, r = newInterval.end;
        for (Interval i : intervals) {
            if (flag) {
                ret.add(new Interval(i.start, i.end));
            } else if (i.end < l) {
                ret.add(new Interval(i.start, i.end));
            } else if (i.start > r) {
                ret.add(new Interval(l, r));
                ret.add(new Interval(i.start, i.end));
                flag = true;
            } else {
                l = Math.min(l, i.start);
                r = Math.max(r, i.end);
            }
        }
        if (!flag) ret.add(new Interval(l, r));
        
        return ret;
    }
}
