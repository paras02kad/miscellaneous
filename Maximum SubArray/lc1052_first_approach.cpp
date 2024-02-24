
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {

        int n = customers.size();

        //! case - 1

        if (n == 1)
        {
            if (grumpy[0] == 0 && customers[0] != 0)
            {
                return customers[0];
            }
            else if (grumpy[0] == 1 && customers[0] != 0)
            {
                if (minutes == 1)
                    return customers[0];
                else
                    return 0;
            }
        }

        int prevSum_1 = 0;
        int prevSum_2 = 0;

        for (int k = 0; k < minutes; k++)
        {
            prevSum_1 += customers[k];
            prevSum_2 += grumpy[k];
        }

        int sum_1 = 0;
        int sum_2 = 0;

        int ans_1 = prevSum_1;
        int ans_2 = prevSum_2;

        //! case - 2

        if (minutes == n)
        {
            return prevSum_1;
        }

        else
        {
            int i = 1;
            int j = minutes;
            int indx_1 = 0;

            while (j < n)
            {
                sum_1 = prevSum_1 + customers[j] - customers[i - 1];
                if (sum_1 > ans_1)
                {
                    indx_1 = i;
                    ans_1 = sum_1;
                }
                i++;
                j++;
                prevSum_1 = sum_1;
            }

            int indx_2 = 0;
            i = 1;
            j = minutes;
            while (j < n)
            {
                sum_2 = prevSum_2 + grumpy[j] - grumpy[i - 1];

                if (sum_2 > ans_2)
                {
                    indx_2 = i;
                    ans_2 = sum_2;
                }
                i++;
                j++;
                prevSum_2 = sum_2;
            }

            //--------------------------------------------------------------------------------------
            int test = 0;
            for (int i = indx_2; i < minutes + indx_2; i++)
            {
                test += customers[i];
            }
            //--------------------------------------------------------------------------------------

            int ans = 0;
            int indx = 0;


            if (indx_1 == indx_2)
            {
                indx = indx_1;
                ans = prevSum_1;
            }

            else if (test > ans_1)
            {
                indx = indx_2;
                ans = test;
            }

            else
            {
                indx = indx_1;
                ans = ans_1;
            }
            //--------------------------------------------------------------------------------------
        

            for (int i = 0; i < n; i++)
            {
                if (i >= indx && i < (indx + minutes))
                {
                    continue;
                }
                else if (grumpy[i] == 0 && customers[i] != 0)
                {
                    ans += customers[i];
                }
            }
            return ans;
        }
        return 0;
    }
};