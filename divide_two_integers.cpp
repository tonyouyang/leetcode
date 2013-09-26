class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long i = 1, dvs = abs((double) divisor), j = dvs, dvd = abs((double) dividend);
        int k;

        for (long long s = j - 1; dvd > s; s += j, i <<= 1, j <<= 1);

        for (k = 0; dvd >= dvs; i >>= 1, j >>= 1)
        {
            if (dvd >= j)
            {
                k += i;
                dvd -= j;
            }
        }

        return dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0 ? -k : k;
    }
};
