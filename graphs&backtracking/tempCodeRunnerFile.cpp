#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<int>>sudoku,int row,int col,int v)
{
     if(row<9 && col<9 &&row>=0 &&col>=0 )
    {
      
      {
            for(int m=0;m<9;m++)
      { 
          if(m!=col){
          if(v==sudoku[row][m])
          {
              return false;
              
          }
        }
          if(m!=row)
          {
              if(v==sudoku[m][col])
          {

              return false;
          }
          }
      }
           if ( row<3 )
     {
        if(col<3)
        {
          for(int i=0;i<3;i++)
          {
              for(int j=0;j<3;j++)
              {
                  if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                
              }
          }
          return true;


        }
        else if(col>=3 && col <6)
        {
             for(int i=0;i<3;i++)
             {
                 for(int j=3;j<6;j++)
                 {
                       if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                
                 }
             }
              return true;

        }
        else if(col>=6 && col<9)
        {
             for(int i=0;i<3;i++)
             {
                 for(int j=6;j<9;j++)
                 {
                        if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
               

                 }
             }
              return true;

        }
     }
      if ( row>=3 && row<6)
     {
         if(col<3)
        {
          for(int i=3;i<6;i++)
          {
                for(int j=0;j<3;j++)
              {
                  if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                
              }
          }
           return true;

        }
        else if(col>=3 && col <6)
        {
             for(int i=3;i<6;i++)
             {
                  for(int j=3;j<6;j++)
                 {
                       if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                

                 }
             }
              return true;

        }
        else if(col>=6 && col<9)
        {
             for(int i=3;i<6;i++)
             {
                  for(int j=6;j<9;j++)
                 {
                         if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                 
                 }
             }
              return true;

        }

     }
      if ( row>=6 && row<9)
     {
          if(col<3)
        {
          for(int i=6;i<9;i++)
          {
              for(int j=0;j<3;j++)
              {
                     if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                 
              }
          }
           return true;

        }
        else if(col>=3 && col <6)
        {
             for(int i=6;i<9;i++)
          {
               for(int j=3;j<6;j++)
                 {
                        if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
               
                 }
          }
           return true;

        }
        else if(col>=6 && col<9)
        {
             for(int i=6;i<9;i++)
          {
               for (int j = 6; j < 9; j++) 
               {
                      if(i==row && j==col)
                  {
                      continue;
                  }else
                  if(v==sudoku[i][j])
                  {
                      return false;
                  }
                 
               }
             }
              return true;
        }
      }
      }
    }
    return false;

}
bool sudoku_solver(vector<vector<int>> &sudoku,int row,int col)
{
    
    if(sudoku[row][col]==0)
    {
        for(int v=1;v<=9;v++)
        {
            if(issafe(sudoku,row,col,v))
            {
                sudoku[row][col]=v;
                if(col==8 && row==8)
                {
                   
                    return true;
                    
                }
                if(col==8&& row!=8)
                {
                    if (!sudoku_solver(sudoku, row+1, (col + 1) % 9)) {
                      sudoku[row][col] = 0;
                }
                    
                }
               else if(!sudoku_solver(sudoku, row, (col + 1) % 9))
               {
                  sudoku[row][col] = 0;
                }
            }
        }
        if (sudoku[row][col] == 0)
        {
          return false;
        }
    }
    else{
    if(col==8 && row==8)
                { 
                    
                    return true;
                }
                if (col == 8 && row!=8) {
                  if (!sudoku_solver(sudoku, row + 1, (col + 1) % 9)) {
                    return false;
                  }
                } else if (!sudoku_solver(sudoku, row, (col + 1) % 9)) {
                  return false;
                }
                
    }
}
int main()
{
    
     vector<vector<int>> sudoku(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(!issafe(sudoku,i,j,sudoku[i][j])&& sudoku[i][j]!=0)
            {
                cout<<"Sudoku not solvable";
                return 0;
            }
        }
    }
    
   bool flag= sudoku_solver(sudoku,0,0);
    for(auto it:sudoku)
    {
      for (auto v : it) {
        cout << v;
      }
      cout << endl;
    }
    
    return 0;
    }