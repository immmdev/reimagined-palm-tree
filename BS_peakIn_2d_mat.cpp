#include<bits/stdc++.h>
using namespace std;
// TC O(log(m))

// Finding max element rowNumber
int maxelCol(vector<vector<int>>mat, int n, int m,int column){
    int maxEl=-1;
    int maxIndex=-1;
    for(int i=0; i<n; i++){
        if(mat[i][column]>maxEl){
            maxEl=mat[i][column];
            maxIndex=i;
        }
    }

    return maxIndex;
}

// finding peak elelment bs
vector<int> peak_el(vector<vector<int>>mat, int n, int m){
    int low=0; int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        // mid is column no. remains const get the max element row no.
        int row=maxelCol(mat,n,m,mid);
        // letting that boundries of mat are covered -1
        int left=(mid-1>=0)? mat[row][mid-1] : -1;
        int right=(mid+1<m)? mat[row][mid+1] : -1;
        
        // there can be multiple peak return any of then if get
        if(mat[row][mid]>left && mat[row][mid]>right){
            // return vector {r,c}
            return {row,mid};

        } else if(mat[row][mid]<left){
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    // if not peak then {-1,-1} / false
    return {-1,-1};
}

int main(){
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
        
        // storing vector in ans returned from function;
        vector<int> ans=peak_el(nums,n,m);
        cout<<ans[0]<<","<<ans[1]<<endl;

    }
}