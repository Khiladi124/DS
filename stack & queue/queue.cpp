#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<int> quest,quest2;
cout<<"enter elements"<<" ";
for(int i=0;i<5;i++)
{int m;
    cin>>m;
    quest.push(m);
}
for(int i=0;i<5;i++)
{int m;
   m=quest.top();
   quest2.push(m);
    quest.pop();
   
}
for(int i=0;i<5;i++)
{
    cout<<quest2.top()<<" ";
    quest2.pop();
}
    
    return 0;
}