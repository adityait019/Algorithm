#include<bits/stdc++.h>
using namespace std;
void subSequence(int index,vector<int>&ds,int arr[],int n)
{
    if(index==n)
    {
        for(auto x:ds)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[index]);
    subSequence(index+1,ds,arr,n);
    ds.pop_back();
    subSequence(index+1,ds,arr,n);
    
}
int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int>ds;
    subSequence(0,ds,arr,n);
    return 0;
}


//RECURSION TREE FOR 3,1,2

                             subSequence(0, ds, arr, 3)
                             /                          \
              ds = [3]                                    ds = []
     subSequence(1, ds, arr, 3)                   subSequence(1, ds, arr, 3)
     /                \                            /              \
ds = [3, 1]           ds = [3]                ds = [1]             ds = []
 Subsequence: 3 1     Subsequence: 3          Subsequence: 1
       |                     |                          |
subSequence(2, ds, arr, 3) subSequence(2, ds, arr, 3) subSequence(2, ds, arr, 3)
       |                     |                          |
  ds = [3, 1, 2]      ds = [3, 2]                ds = [2]         
Subsequence: 3 1 2    Subsequence: 3 2           Subsequence: 2
                          |                          |
                 subSequence(3, ds, arr, 3)  subSequence(3, ds, arr, 3)
                          |                          |
                     ds = [3, 1, 2]             ds = [3, 2]
                   Subsequence: 3 1 2          Subsequence: 3 2


//Explaination of function

The provided code is an implementation of a recursive function called `subSequence`. This function generates all possible subsequences of an array `arr` of length `n` and prints them.

Here's a step-by-step explanation of the code:

1. The code starts with the standard C++ include statement `#include<bits/stdc++.h>`, which includes most commonly used C++ standard library headers.

2. The `using namespace std;` statement allows you to use names from the `std` namespace without explicitly specifying the namespace.

3. The `subSequence` function is declared with the following parameters:
   - `index`: It represents the current index of the array being considered.
   - `ds`: It is a reference to a vector of integers used to store the elements of the current subsequence.
   - `arr`: It is the input array.
   - `n`: It is the length of the array.

4. Inside the `subSequence` function, there is a base case check. If the `index` equals `n`, it means the end of the array has been reached. In this case, the elements of the `ds` vector (representing the subsequence) are printed, followed by a newline character, and then the function returns.

5. If the base case is not satisfied, the function proceeds to the next steps. It first pushes the element `arr[index]` to the `ds` vector using the `push_back` function. This represents the inclusion of the current element in the subsequence.

6. After pushing the element, the `subSequence` function is recursively called with `index+1`, which represents the next index to consider. This recursive call generates subsequences that include the current element.

7. Once the recursive call returns, the element `arr[index]` is removed from the `ds` vector using the `pop_back` function. This is done to backtrack and explore other possibilities where the current element is excluded from the subsequence.

8. Finally, after the element is popped, the `subSequence` function is recursively called again with `index+1`. This recursive call generates subsequences that do not include the current element.

9. The `main` function initializes an array `arr` with elements 3, 1, and 2, and sets the length `n` to 3.

10. It also declares an empty vector `ds` to store the subsequences.

11. The `subSequence` function is called from `main` with the initial values `index=0`, `ds` vector, `arr`, and `n`. This starts the generation of all subsequences.

12. After the `subSequence` function returns, the `main` function ends, and the program terminates.

In summary, the code generates all possible subsequences of an array using a recursive approach and prints them.