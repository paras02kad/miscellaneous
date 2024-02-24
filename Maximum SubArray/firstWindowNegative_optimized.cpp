#include <iostream>
using namespace std;
int main()
{
    int arr[9] = {2, -3, 4, 4, -7, -1, 4, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter K" << endl;
    cin >> k;
    int ans[n - k + 1];

    int p = 0;
    int i = 1;
    int j = k;

    //! finding first negative Element

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            p = i;
            break;
        }
    }

    while (j < n)
    {
        if (p >= i)
            ans[i] = arr[p];

        else
        {
            for (p = i; p <= j; p++)
            {
                if (arr[p] < 0)
                {
                    ans[i] = arr[p];
                    break;
                }
            }
        }

        i++;
        j++;
       
    }

    for (int i = 0; i < (n - k + 1); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}