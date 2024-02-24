#include <bits/stdc++.h>

using namespace std;

void optimized(int arr[], int size, int k)
{
    //! Finding previous sum
    int prevSum = 0;
    for (int i = 0; i < k; i++)
    {
        prevSum += arr[i];
    }
//--------------------------------------------------------------------

    //* finding maximum subArray
     int ans = INT_MIN;
    int i = 1;
    int j = k;
    int sum = 0, maxIndx = 0;

    while (j < size)
    {
        sum = prevSum - arr[i - 1] + arr[j];
        //! updating the values of maximum and recording the index of highest subArray
        if (sum > ans)
        {
            ans = sum;
            maxIndx = i;
        }
        i++;
        j++;
        prevSum = sum;
    }

    cout<<maxIndx<<endl;
    cout<<ans<<endl;
}
int main()
{

    int arr[9] = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;

     optimized(arr, size, k);

    return 0;
}