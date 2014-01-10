#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int cnt_max_points = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            int cnt_same = 0, cnt_points = 0;
            unordered_map<string, int> cnt_on_line;

            for (int j = i + 1; j < points.size(); ++j)
            {
                int dx = points[j].x - points[i].x, dy = points[j].y - points[i].y;
                int g = gcd(dx, dy);
                if (g == 0)
                {
                    cnt_same++;
                }
                else
                {
                    dx /= g;
                    dy /= g;
                    cnt_points = max(cnt_points, ++cnt_on_line[to_string(dx) + "," + to_string(dy)]);
                }
            }

            cnt_max_points = max(cnt_max_points, cnt_same + cnt_points + 1);
        }

        return cnt_max_points;
    }
private:
    int gcd(int a, int b)
    {
        return a ? gcd(b % a, a) : b;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    Point p(0, 0);
    vector<Point> v;
    v.push_back(p);
    cout << solution.maxPoints(v) << endl;
    return 0;
}