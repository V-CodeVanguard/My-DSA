class Solution
{
public:
    int binarySearch(vector<int>& nums, int s, int e, int target)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return -1;
    }

    int findPivot(vector<int>& nums)
    {
        int n = nums.size();

        // Array is not rotated
        if (nums[0] <= nums[n - 1])
            return n - 1;

        int s = 0, e = n - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (mid < n - 1 && nums[mid] > nums[mid + 1])
                return mid;

            if (nums[mid] >= nums[0])
                s = mid + 1;
            else
                e = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int pivot = findPivot(nums);

        // Search in left sorted part
        if (target >= nums[0] && target <= nums[pivot])
            return binarySearch(nums, 0, pivot, target);

        // Search in right sorted part
        return binarySearch(nums, pivot + 1, n - 1, target);
    }
};