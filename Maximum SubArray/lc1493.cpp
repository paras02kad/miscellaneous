class Solution {
public:
//!approach -1
    int longestSubarray(vector<int>& nums) 
    {

        int flips = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int len;
        int maxLen = INT_MIN;

        while (j < n)
        {
            if (nums[j] == 1)
                j++;

            else
            {
                if (flips < 1)
                {
                    j++;
                    flips++;
                }
                else
                {
                    len = j - i;
                    maxLen = max(len, maxLen);

                    while (nums[i] == 1)
                        i++;

                    i++;
                    j++;
                }
            }
            len = j - i;
            maxLen = max(len, maxLen);
        }
        return maxLen-1;
        
    }

    
    //!approach - 2
};