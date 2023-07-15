/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
bool issafe(int n,int row,int col,vector<vector<int>>maze)
{
	if(row>=0&&col>=0&&row<n&&col<n&&maze[row][col])
	{
		return true;
	}
	else return false;
}
void helper(int n,int row,int col,vector<vector<vector<int>>> &ans,vector<vector<int>>maze,vector<vector<int>>&mouse)
{
	
	if(row==n||col==n||row<0||col<0)
	{
		return;
	}
	if(row==n-1&&col==n-1)
	{ 
		  if (issafe(n, row, col, maze))
		{
			mouse[row][col]=1;
			ans.push_back(mouse);
			}
		return;
	}
	int i=row;
	int j=col;
	 if(!mouse[i][j])
		{  if (issafe(n, i, j, maze)) 
		  {
              mouse[i][j]=1;
            helper(n, i+1, j, ans, maze, mouse);
			helper(n, i-1, j, ans, maze, mouse);
			helper(n, i, j-1, ans, maze, mouse);
			helper(n, i, j+1, ans, maze, mouse);
          }
		   mouse[i][j]=0;
		}
		 return;
		  }


int main() {
int n;
cin>>n;
vector<vector<int>> maze(n);
for(int i=0;i<n;i++)
{
    for(int l=0;l<n;l++){
	int k;
	cin>>k;
	maze[i].push_back(k);}
}
if(maze[n-1][n-1]==0||maze[0][0]==0)
{
	return 0;
}
vector<vector<vector<int>>> ans;
vector<vector<int>>mouse(n,vector<int>(n,0));
helper(n,0,0,ans,maze,mouse);
for(auto it:ans)
{
	for(auto r:it)
	{
		for(auto m:r)
		{
			cout<<m<<" ";
		}

	}
	cout<<endl;
}
	return 0;
}
