class Solution {
public:

    bool helper(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid] < target) low = mid+1;
            else high = mid -1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 1.find the row
        // 2.find in the row
        // finding in the row
        int n = matrix.size();//rows
        int m = matrix[0].size();//cols

        int low = 0;
        int high = n-1;

        while(low<=high)
        {
            int mid = low+(high - low)/2;
            if(matrix[mid][m-1]>=target)
            {
                // check if in that row
                if(matrix[mid][0]<=target)
                {
                    // do binary search here
                    return helper(matrix[mid],target);
                }
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return false;
    }
};
