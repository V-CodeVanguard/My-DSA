class Solution {
public:
    int firstPos(vector<int>& nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;   // Search on the left
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return ans;
    }

    int lastPos(vector<int>& nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;   // Search on the right
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int first = firstPos(nums, target);
        int last = lastPos(nums, target);

        return {first, last};
    }
};