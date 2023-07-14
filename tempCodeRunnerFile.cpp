#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cout << "enter number of elements in array:: ";
    cin >> n;
    int *arr = new int[n];
    int *arr2 = new int[n];
    cout << "enter elements:: ";
    for (int i = 0; i < n; i++)
    {
        cin >> n;
    }
    stack<int> s1;
    for (int k = 0; k < 2; k++)
    { 
        int j=0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s1.empty())
            {
                s1.push(arr[i]);
                arr2[j] = -1;
                j++;
            }
            else
            {
                if (arr[i] < s1.top())
                {
                    arr2[j] = s1.top();
                    j++;
                    s1.push(arr[i]);
                }
                else
                {
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
                    if (s1.empty())
                    {
                        arr2[j] = -1;
                        j++;
                        s1.push(arr[i]);
                    }
                    else
                    {
                        arr2[j] = s1.top();
                        j++;
                        s1.push(arr[i]);
                    }
                }
            }
        }
    }
    
    for (int l = n-1; l >= 0; l--)
    {
        cout << arr2[l] << " ";
    }
    delete[] arr;
    delete[] arr2;
    return 0;
}