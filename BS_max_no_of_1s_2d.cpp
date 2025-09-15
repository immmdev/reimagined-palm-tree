#include <bits/stdc++.h>
using namespace std;

// it will return the first ocurance of 1
int upperbnd(vector<int> &a, int x)
{
    int n = a.size();
    int low = 0;
    int high = n - 1;
    int up = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x <= a[mid])
        {
            up = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return up;
}

int main()

{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<vector<int>> nums(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> nums[i][j];
            }
        }
        int maxAnsInd = -1;
        int maxAns = -1;
        for (int i = 0; i < n; i++)
        {
            // we will sub end index to 1st index of 1.
            if (upperbnd(nums[i], 1) != -1)
            {
                int ans;
                ans = m - (upperbnd(nums[i], 1));
                if (ans > maxAns)
                {
                    maxAns = ans;
                    maxAnsInd = i;
                }
            }
        }
        cout << maxAnsInd << endl;
    }
}
