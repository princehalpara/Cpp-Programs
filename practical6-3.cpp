/* Programmer : Prince Halpara
   Date : 28 April, 2025
   Aim : Merge two sorted arrays into a single sorted array using dynamic memory
*/

#include<iostream>
using namespace std;

int main()
{
    int num1,num2;
    int *arr1 = new int[num1];
    int *arr2 = new int [num2];

    cout<<"Enter the size of the first array: ";
    cin>>num1;

    // Taking the input for the first array
    for(int i=0; i<num1; i++)
    {
        cout<<"Enter the "<<i+1<<" number: ";
        cin>>arr1[i];
    }

    // Taking the input for the second array
    cout<<"Enter the size of the second array array: ";
    cin>>num2;

    for(int i=0; i<num2; i++)
    {
        cout<<"Enter the "<<i+1<<" number: ";
        cin>>arr2[i];
    }

    int *arr = new int[num1 + num2];
    int i=0, j=0, k=0;

    // Copying the elements of both arrays
    while(i<num1 && j<num2)
    {
        if(arr1[i] < arr2[j])
        {
            arr[k++]=arr1[i++];
        }
        else
        {
            arr[k++]=arr2[j++];
        }
    }

    // Copying the remaining array
    while(i<num1)
    {
        arr[k++]=arr1[i++];
    }
    while(j<num2)
    {
        arr[k++]=arr2[j++];
    }

    // Displaying the new array
    cout<<"Displaying the sorted array: "<<endl;
    for(int i=0; i<(num1 + num2); i++)
    {
        cout<<"The "<<i+1<<" number: "<<arr[i]<<endl;
    }

    // Freeing the space by deleting the arrays
    delete[] arr1;
    delete[] arr2;
    delete[] arr;

    cout<<endl;
    cout << "\nPrince Halpara: 24CE038" << endl;

   return 0;
}
