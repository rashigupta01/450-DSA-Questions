// 1) Store last element in a variable say temp.
// 2) Shift all elements one position ahead.
// 3) Replace first element of array with temp.
void rotate(int arr[], int n)
{
    int temp = arr[n-1];
    for(int i=n-1; i>0; i--) arr[i] = arr[i-1];
    arr[0] = temp;
}