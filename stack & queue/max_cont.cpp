//2022BCS001 ABHISHEK GANGWAR5
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cout << "enter number of elements in array:: ";
    cin >> n;// size of array
    int *arr = new int[n];//input array
    int *arr2 = new int[n];// output array that is next larger element
    cout << "enter elements:: ";
    for (int i = 0; i < n; i++)
    {
        cin >>arr[i];// entering elements in input array
    }
    stack<int> s1;//initializing a stack s1
    for (int k = 0; k < 2; k++)// we have to go to our array twice so for loop 
    { 
        int j=0;// index of output array
        for (int i = n - 1; i >= 0; i--)//starting from n-1 0r last element of array
        {
            if (s1.empty())// if stack is empty then push element of input array in stack and put -1 in index of output array
            {
                s1.push(arr[i]);
                arr2[j] = -1;
                j++;
            }
            else// if atack is not empty
            {
                if (arr[i] < s1.top())//if current element of input array is less than top of stack then 
                {//put top of stack in output array as it is next larger element
                    arr2[j] = s1.top();
                    j++;
                    s1.push(arr[i]);//and push input array element in stack
                }
                else//if current element of input array is greater than top of stack then it means next element or top of stack is not larger
                
                {//so pop element until you find any element which is greater than current element of input array or array is empty
                    while (arr[i] >= s1.top())
                    {
                        if(s1.empty())
                        {
                            break;
                        }
                        s1.pop();
                         if(s1.empty())
                        {
                            break;
                        }
                    }
                    if (s1.empty())//if stack becomes empty then put -1 in output array and push current element of input array in stack
                    {
                        arr2[j] = -1;
                        j++;
                        s1.push(arr[i]);
                    }
                    else// if stack is not empty
                    {//it means top of stack is greater than element of input array thus put it in output array and push current element of input array in stack
                        arr2[j] = s1.top();
                        j++;
                        s1.push(arr[i]);
                    }
                }
            }
        }
    }
    
    for (int j = n-1; j >= 0; j--)// now print all the elements of output array in reverse order
    {
        cout << arr2[j] << " ";
    }
    delete[] arr;//now delete dynamically alloted arrays
    delete[] arr2;
    return 0;
}