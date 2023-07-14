#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> sti;
    // take input
    sti.push(5);
    sti.push(6);
    sti.push(9);
    sti.push(1);
    sti.push(0);
    while(!sti.empty())
    { //printing the top element
        cout<<sti.top()<<" ";
     // pop out the topmost element
        sti.pop();
    }
    return 0;
}