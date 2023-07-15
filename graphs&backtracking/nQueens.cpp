#include <bits/stdc++.h>
using namespace std;
 
// A utility function to print solution
void printSolution(vector<vector<vector<int>>> &ans)
{
    if(ans.size())
   { for (auto it:ans) {
        for (auto v:it)
          { 
            for(auto s:v)
            cout << s;
          }
          cout<<endl;
    }}
    else
    cout<<"no such board";
}
bool issafe(int n, int row,int col,vector<vector<int>>&board)
{
    int drow=row;
    int dcol=col;
    while(dcol>=0)
    {
        if(board[drow][dcol])
        {
            return false;
        }
        dcol--;

    }
    drow=row;
    dcol=col;
    while(dcol>=0&&drow>=0)
    {
        if(board[drow][dcol])
        {
            return false;
        }
        dcol--;
        drow--;

    }
     drow=row;
    dcol=col;
    while(dcol>=0&&drow<n)
    {
        if(board[drow][dcol])
        {
            return false;
        }
        dcol--;
        drow++;

    }
    return true;

}
void helper(int n,int col,vector<vector<int>>&board,vector<vector<vector<int>>>&ans)
{
    if(col>=n)
    {
        ans.push_back(board);
        return;
    }
   for(int row=0;row<n;row++)
   {
    if (issafe(n,row,col,board))
    {
        board[row][col]=1;
        helper(n,col+1,board,ans);
    }
    board[row][col]=0;
   }
   
   
}
vector<vector<vector<int>>> nQueens(int n)
{
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<vector<int>>>ans;
    helper(n,0,board,ans);
return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<vector<int>>> ans;
    ans=nQueens(n);
    printSolution(ans);
    return 0;
}