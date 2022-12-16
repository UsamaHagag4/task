#include <iostream>
#include <algorithm>
using namespace std;
void Merge( int arr[], int l, int m, int r )
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1], *R = new int[n2];
    for ( i = 0; i < n1; i++ )
        L[i] = arr[l + i];
    for ( j = 0; j < n2; j++ )
        R[j] = arr[m + 1 + j];
    i = j = 0;
    k = l;
    while ( i < n1 && j < n2 )
    {
        if ( L[i] <= R[j] )
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while ( i < n1 )
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while ( j < n2 )
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort( int arr[], int l, int r )
{
    if ( l < r )
    {
        int m = l + ( r - l ) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}
void print( int arr[], int n )
{
    for ( int i = 0; i < n; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = { 31, 41, 59, 26, 41, 58 };
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort( arr, 0, n - 1 );
    print( arr, n );
return 0 ;
}
