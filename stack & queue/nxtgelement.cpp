#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> stk1;
    stack<int> stk2;
    int arr[8];
    for(int i=0;i<8;i++)
    {int m;
    cin>>m;
    arr[i]=m;
    }
for(int i=0;i<8;i++)
{
    for(int j=i+1;j<8;j++)
    {
        if(arr[j]>arr[i])
         {stk1.push(arr[j]);}
         else
          {
            stk1.push(-1);
           }
        break;
    }
}

for(int i=0;i<8;i++)
{int m;
   m=stk1.top();
   stk2.push(m);
    stk1.pop();
}
for(int i=0;i<8;i++)
{
    cout<<stk2.top()<<" ";
    stk2.pop();
}
    return 0;
}