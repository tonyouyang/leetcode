class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int rstart, int rend, int cstart, int cend, int target)
    {
        if (rstart > rend || cstart > cend) return false;
        
        int rmid = rstart + (rend - rstart >> 1);
        if (matrix[rmid][cstart] <= target && target <= matrix[rmid][cend])
        {
            int cmid = cstart + (cend - cstart >> 1);
            if (matrix[rmid][cmid] > target) return searchMatrix(matrix, rmid, rmid, cstart, cmid - 1, target);
            else if (matrix[rmid][cmid] < target) return searchMatrix(matrix, rmid, rmid, cmid + 1, cend, target);
            else return true;
        }
        else if (matrix[rmid][cstart] > target) return searchMatrix(matrix, rstart, rmid - 1, cstart, cend, target);
        else return searchMatrix(matrix, rmid + 1, rend, cstart, cend, target);
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty() || matrix[0].empty()) return false;
        return searchMatrix(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};
