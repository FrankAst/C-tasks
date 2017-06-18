#include <iostream>
#define size 50000 // size of array

using namespace std;

int arr[size];


//this function is adding elements from array to heap.(Heap is like tree, remember it and i love u my baby, You'll pass this).
void heapify (int pos, int n) { // pos - position of root node.
    while (2 * pos + 1 < n) {
       
        int t = 2 * pos +1;
        if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
        {
            t = 2 * pos + 2;
        }
        if (arr[pos] < arr[t]) {
            swap(arr[pos], arr[t]);
            pos = t;
        }
        else break;
       
    }
}

void heap_make(int n)  
{
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(i, n); 
    }
}

void heap_sort(int n)
{
    heap_make(n);

    while(n>0)
    {
        swap(arr[0],arr[n-1]);  //internal function. It works like swapping via adding 3 variable.
        n--;
        heapify(0,n);
    }
}

int main()
{

//adding elements to array
    int n; // number of elements
    cin>>n;
    for(int i = 0; i < n; i ++)
    {
        cin>> arr[i];
    }


    heap_sort(n); // n- size of array


//just printing array after sorting
    for(int i = 0; i < n; i ++)
    {
        cout <<  arr[i]<<endl;
    }
    return 0;
}