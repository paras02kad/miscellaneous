class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0;
        int j = 0;
        int len = 0;
        int minLen = INT_MAX;
        int n = nums.size();
        int sum = 0;

        while (j < n)
        {
            sum+=nums[j];
            while (sum >= target)
            {
                len = j - i + 1;
                minLen = min(len, minLen);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minLen == INT_MIN)return 0;
        return minLen;
    }
};