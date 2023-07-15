#include <bits/stdc++.h> 
// HARD PROBLEM ON DYNAMIC PROGRAMMING

// given a 2d grid in whic two ninjas are at position(0,0) and (0,c-1)
/* where r=rows , c= columns has to move in grid such that they have to collect maximum chocolates
which are at each grid , note if one ninja picks chocolate at 1grid then other will get 0 chocolates at that grid 
ninja can move from (i,j) to (i+1,j),(i+1,j+1),(i+1,j-1). */

 // >>>>>memoization
// int helper(int r,int c,vector<vector<int>>& grid,vector<vector<vector<int>>>& mem,int i,int j1,int j2)
// {
//     if(j1>=c||j2>=c||j1<0||j2<0||i>=r)
//     {
//         return 0;
//     }
//     if(mem[i][j1][j2]!=-1)
//     {
        
//         return mem[i][j1][j2];
       
//     }
//     if(i==r-1)
//     {
//         if(j1==j2)
//         {
//             return grid[i][j1];
//         }
//         else{
//             return grid[i][j1]+grid[i][j2];
//         }
//     }
//     vector<int> it={-1,0,1};
    
//     int maxi=-1;
//     if(j1==j2)
//     {
//         for(int l=0;l<3;l++)
//         { 
            
//             for(int j=0;j<3;j++)
//             {
//                 if (maxi < grid[i][j1]+helper(r,c,grid,mem,i+1,j1+it[j],j2+it[l]))
//                 {
//                     maxi =max(maxi,grid[i][j1]+helper(r,c,grid,mem,i+1,j1+it[j],j2+it[l]));
                   
//                 }
//             }
           
//         }
//                 return mem[i][j1][j2] =maxi;
       
//     }
//     else{
//          for(int l=0;l<3;l++)
//         {
            
//             for(int j=0;j<3;j++)
//             {
//              if (maxi < grid[i][j2]+grid[i][j1]+helper(r,c,grid,mem,i+1,j1+it[j],j2+it[l]))
//              {
//                  maxi =max(maxi,grid[i][j2]+grid[i][j1]+helper(r,c,grid,mem,i+1,j1+it[j],j2+it[l]));
                 
//              }
//             }
           
//         }
//         return mem[i][j1][j2]=maxi;
      
//     }
    
// }
// int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> mem(r,vector<vector<int>>(c,vector<int>(c,-1)));
//     return helper(r,c,grid,mem,0,0,c-1);
// }
// >>>>>tabulation
// int maximumChocolates(int r,int c, vector<vector<int>> &grid)
// {
//     vector<vector<vector<int>>> mem(r,vector<vector<int>>(c,vector<int>(c,0)));
//     for(int j1=0;j1<c;j1++)
//     {
//         for(int j2=0;j2<c;j2++)
//         {
//             if(j1==j2)
//             {
//                 mem[r-1][j1][j2]=grid[r-1][j1];
//             }else{
//                 mem[r-1][j1][j2]=grid[r-1][j1]+grid[r-1][j2];
//             }
//         }
//     }
//     for(int i=r-2;i>=0;i--)
//     {
//      for(int j1=0;j1<c;j1++)
//      {
//         for(int j2=0;j2<c;j2++)
//         {
//             int maxi=-9999;
//             for(int a=-1;a<=1;a++)
//             {
//                 for(int b=-1;b<=1;b++)
//                 {
//                    if(a+j1<0||a+j1>=c||b+j2<0||b+j2>=c)
//                    {
//                       maxi=max(maxi,INT_MIN);
//                    }else
//                     {
//                         if(j1==j2)
//                         { 
//                             int ans=maxi;
//                           maxi=max(ans,(grid[i][j1]+mem[i+1][j1+a][j2+b]));
                          
//                         }else{
//                             int ans=maxi;
//                            maxi=max(ans,(grid[i][j1]+grid[i][j2]+mem[i+1][j1+a][j2+b]));
                           
//                         }
//                     }
//                 }

//             }
//             mem[i][j1][j2]=maxi;
//         }

//         }
       
//     }
//      return mem[0][0][c-1];
// }
// >>>>>> space optimization
 int maximumChocolates(int r,int c,vector<vector<int>>& grid)
 {
     vector<vector<int>> prev(c,vector<int>(c));
     for(int i=0;i<c;i++)
     {
         for(int j=0;j<c;j++)
         {
             if(j==i){
             prev[i][j]=grid[r-1][j];}
             else{
                     prev[i][j]=grid[r-1][i]+grid[r-1][j];
                 
             }
         }
     }
     for(int i=r-2;i>=0;i--)
     { vector<vector<int>> cur(c,vector<int>(c,0));
         for(int j1=0;j1<c;j1++)
         {

             for(int j2=0;j2<c;j2++)
             {
                 int maxi=INT_MIN;
                 for(int a=-1;a<=1;a++)
                 {
                     for(int b=-1;b<=1;b++)
                     {
                       if(a+j1>=c||a+j1<0|b+j2>=c||b+j2<0)
                       {
                           continue;
                       }  
                       else{
                           if(j1==j2)
                           {
                               maxi=max(maxi,(grid[i][j1]+prev[j1+a][j2+b]));
                           }
                           else
                           {
                               maxi=max(maxi,(grid[i][j1] + grid[i][j2] +prev[j1+a][j2+b]));
                           }
                       }
                     }
                 }
                 cur[j1][j2]=maxi;
             }

         }
         prev=cur;
     }
     return prev[0][c-1];
 }
int main(){
int r,c;
cin>>r>>c;
vector<vector<int>> grid(r,vector<int>(c));
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
cin>>grid[i][j];
}
}
cout<<maximumChocolates(r,c,grid);
return 0;
}
