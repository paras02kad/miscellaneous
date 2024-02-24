#include <iostream>
using namespace std;
int main()
{
    int arr[9] = {2, -3, 4, 4, -7, -1, 4, -2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    int ans[n - k + 1];

    for (int i = 0; i < (n - k + 1); i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (arr[i + j] < 0)
            {
                ans[i] = arr[i + j];
                break;
            }
        }
    }

    for (int i = 0; i < n - k + 1; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}