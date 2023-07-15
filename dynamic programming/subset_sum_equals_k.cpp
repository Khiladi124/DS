#include <bits/stdc++.h> 
/*we have to return true if the sum of all the element of any subset or subsequence of array arr equals to k */
//  >>>>>>>> MEMOIZATION 
// bool helper(int n,int i,int k,vector<int>& arr,vector<int>& mem)
// {
//     if(k==0)
//     {
//         return true;
//     }
//     if(k<0||i>=n)
//     {
//         return false;
//     }
//     if(mem[k]!=-1)
//     {
//         if(mem[k]==1)
//         {
//             return true;
//         }else
//         {
//             return false;
//         }
//     }
//     int a=int(helper(n,i+1,k-arr[i],arr,mem));
//     int b=int(helper(n,i+1,k,arr,mem));
//     if(a==1||b==1)
//     {
//         mem[k]=1;
//     }
//     else{
//         mem[k]=0;
//     }

//     return bool(mem[k]);

// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//      vector<int> mem(k+1,-1);
//     return helper(n,0,k,arr,mem);
// }
// >>>>>>>>TABULATION ,SPACE OPTIMIZATION
bool subsetSumToK(int n,int k,vector<int> &arr)
{
    if(k==0)
    {
        return true;
    }
    if(k<0||n<=0)
    {
        return false;
    }
   vector<int> ind;
   ind.push_back(0);
    for(int i=0;i<n;i++)
    {
        int m=ind.size();
       for(int j=0;j<m;j++) {
        if(arr[i]+ind[j]<=k)
        {   
            ind.push_back(arr[i]+ind[j]);
            if(arr[i]+ind[j]==k)
            {
                return true;
            }
            
        }
       }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<subsetSumToK(n,k,arr);
    return 0;
}