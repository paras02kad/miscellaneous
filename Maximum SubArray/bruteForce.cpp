#include <bits/stdc++.h>

using namespace std;

void brute_machine(int arr[], int size, int k)
{

    int ans = INT_MIN;
    int maxIndx;

    for (int i = 0; i < (size - k + 1); i++)
    {
        int sum = 0;

        for (int j = 0; j < k; j++)
        {
            sum += arr[i + j];
        }

        if (ans <= sum)
        {
            ans = sum;
            maxIndx = i;
        }
    }
    cout << "Starting indx is "<<maxIndx << endl;
    cout << ans << endl;
    return;
    
}

int main()
{

    int arr[9] = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;

    brute_machine(arr, size, k);

    return 0;
}