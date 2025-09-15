#include<bits/stdc++.h>
using namespace std;
// Q - finding target elemet in each row separately sorted array
// TC O(n+m)
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

        int row=0; int column=m-1;
        int ans_i=-1;
        int ans_j=-1;
        while(row<n && column>=0){
            if(nums[row][column]==target)  {
                ans_i=row;
                ans_j=column;
            }
            // if target is greater then element then it will not be that row
            else if(nums[row][column]<target){
                row++;
            }
            // if target is less then element then it might be in left side of the elemnt
            else {
                column--;
            }
        }

        cout<<ans_i<<","<<ans_j<<endl;

    }
}