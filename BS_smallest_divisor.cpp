#include <bits/stdc++.h>
using namespace std;

int req_sum(vector<int>a,int num){
    int n=a.size();
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=ceil((double)a[i]/num);
    }
    return sum;
}

// tc o(log(max)*n)
// sc o(1)

int min_d(vector<int>a,int thersold){
    int max_el=*max_element(a.begin(),a.end());
    int low=1;
    int high=max_el;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(req_sum(a,mid)<=thersold){
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }

    }

    return ans;
}

int main()
{
    int n,t;
    cin >> n>>t;
    vector<int> f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }

    cout<<min_d(f,t)<<endl;

    return 0;
}