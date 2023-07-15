#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool horizontal_checker(vector<string> crossword, string word,int row,int col)
{ 
    
    for(int j=col;j<col+word.size();j++)
    {
        if(j>9)
        {
            return false;
        }
        if(crossword[row][j]=='-'||crossword[row][j]==word[j-col])
        {
        
        }
        else
        return false;
    }
    return true;
}
bool vertical_checker(vector<string> crossword, string word,int row,int col)
{
    for(int j=row;j<row+word.size();j++)
    {
         if(j>9)
        {
            return false;
        }
      if (crossword[j][col] == '-' || crossword[j][col] == word[j - row]) {

      } else
        return false;
    }
    return true;
}
bool solver_helper(vector<string> &crossword,vector<string> wordlist,int l)
{
   if(l==-1)
   {
       return true;
   }
    for(int i=0;i<10;i++)
   {
      for(int j=0;j<10;j++)
    {
        if(horizontal_checker(crossword,wordlist[l],i,j))
        {     
            vector<string> crossword1=crossword;
           for(int m=j;m<j+wordlist[l].length();m++)
          {
               if (m>=10)
                { break;}
              crossword[i][m]=wordlist[l][m-j];
          }
         
           if(solver_helper(crossword,wordlist,l-1))
           {
               
               return true;
           }
           else 
           {
               crossword=crossword1;
           }
        }
      
      if(vertical_checker(crossword,wordlist[l],i,j))
        {  
             vector<string> crossword1=crossword;
           for(int m=i;m<i+wordlist[l].length();m++)
          { 
              if (m>=10)
                { break;}
              crossword[m][j]=wordlist[l][m-i];
          }
         
          if( solver_helper(crossword,wordlist,l-1))
          {
              
              return true;
          }
           else 
           {
               crossword=crossword1;
           }
        }
        
    }
    }
   return false;
}
void solver(vector<string> &crossword,vector<string> wordlist)
{
   int l=wordlist.size();
    if(l>0&&solver_helper(crossword,wordlist,l-1))
    {
        for(int i=0;i<10;i++)
    {
       
        for(int j=0;j<10;j++)
        {
        
            cout<<crossword[i][j];
        }
        cout<<endl;
    }
    }

}
int main(){
   vector<string> crossword(10, string(10, ' '));
    for(int i=0;i<10;i++)
    {
        
            string input;
        cin >> input;
        crossword[i] = input;
        
    }
string words;
cin>>words;
vector<string> wordlist;
int i=0;
while(i != -1){
        i = words.find(";");
        wordlist.push_back(words.substr(0, i));
        words = words.substr(i+1);
    }
solver(crossword,wordlist);
  
    return 0;
}