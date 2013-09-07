// There are two sorted arrays A and B of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

class Solution
{
public:
    int findKthSmallest(int *A, const int m, int *B, const int n, const int k)
    {
        if (!m) return B[k - 1];
        if (!n) return A[k - 1];
        if (k == 1) return min(A[0], B[0]);

        // TODO better division?
        int p = max(m * k / (m + n), 1); // at least 1
        int q = k - p; // at least 1 since k is at least 2

        if (A[p - 1] < B[q - 1])
        {
            return findKthSmallest(A + p, m - p, B, n, k - p);
        }
        else
        {
            return findKthSmallest(A, m, B + q, n - q, k - q);
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return (m + n) & 0x1 ?
               (double)findKthSmallest(A, m, B, n, (m + n + 1) / 2) :
               (double)(findKthSmallest(A, m, B, n, (m + n) / 2) + findKthSmallest(A, m, B, n, (m + n) / 2 + 1)) / 2;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int A[100], B[100], m, n, k;

    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));

    // cin >> m >> n >> k;
    cin >> m >> n;
    for (int i = 0; i < m; ++i)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }

    // cout << solution.findKthSmallest(A, m, B, n, k) << endl;
    cout << solution.findMedianSortedArrays(A, m, B, n) << endl;

    return 0;
}
