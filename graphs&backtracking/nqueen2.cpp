#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool issafe(int n, int row,int col,vector<string> &board)
{
    int drow=row;
    int dcol=col;
    while(dcol>=0)
    {
        if(board[drow][dcol]=='Q')
        {
            return false;
        }
        dcol--;

    }
    drow=row;
    dcol=col;
    while(dcol>=0&&drow>=0)
    {
        if(board[drow][dcol]=='Q')
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
        if(board[drow][dcol]=='Q')
        {
            return false;
        }
        dcol--;
        drow++;

    }
    return true;

}
void helper(int n,int col,vector<string>&board,vector<vector<string>>&ans)
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
        board[row][col]='Q';
        helper(n,col+1,board,ans);
    }
    board[row][col]='.';
   }
   
   
}
    vector<vector<string>> nQueens(int n) {
        vector<string> board(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                board[i].append(".");
            }
        }
        vector<vector<string>>ans;
        helper(n,0,board,ans);
        return ans;
            }
            void printSolution(vector<vector<string>> &ans)
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
            int main()
            {
    int n;
    cin>>n;
    vector<vector<string>> ans;
    ans=nQueens(n);
    printSolution(ans);
    return 0;
}
