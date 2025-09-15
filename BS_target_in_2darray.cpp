#include<bits/stdc++.h>
using namespace std;
// TC O(log(n*m-1))
// SC O(1)
int main(){
    int t;
    cin >> t;
    while (t--)
    {

        int n, m,target;
        cin >> n >> m>>target;
        vector<vector<int>> nums(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> nums[i][j];
            }
        }
        // we are flating the array in our mind
        int low=0; int high=n*m-1;
        bool ans=false;
        while(low<=high){
            int mid=(low+high)/2;

            int row=mid/m; // how may four have passes in whole nos
            int column=mid%m; // how much remaining after dividing m
    
            if(nums[row][column]==target){
                ans=true;
                break;
            }
            else if(nums[row][column]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }

        cout<<ans<<endl;
    }
}