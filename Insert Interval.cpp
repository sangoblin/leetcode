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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> res{newInterval};
        while (!intervals.empty())
        {
            Interval &tmp1 = intervals[0], tmp2 = *res.rbegin();
            res.pop_back();
            if (tmp1.end < tmp2.start)
            {
                res.push_back(tmp1);
                res.push_back(tmp2);
                intervals.erase(intervals.begin());
                continue;
            }
            else if (tmp1.start > tmp2.end)
            {
                res.push_back(tmp2);
                break;
            }
            Interval *tmp3 = new Interval(min(tmp1.start, tmp2.start), max(tmp1.end, tmp2.end));
            res.push_back(*tmp3);
            intervals.erase(intervals.begin());
        }
         while (!intervals.empty())
         {
             Interval &tmp1 = intervals[0];
             res.push_back(tmp1);
             intervals.erase(intervals.begin());
         }
         return res;
    }
};
