// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool sortMethod(Item a, Item b) {
    double pera = (a.value*1.0)/a.weight;
    double perb = (b.value*1.0)/b.weight;
    if(pera>perb) return true;
    else return false;
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, sortMethod);
    int capacity=0, pos=0;
    double ans=0.0;
    while(capacity<W && pos!=n) {
        if(arr[pos].weight+capacity<=W) {
            capacity += arr[pos].weight;
            ans += arr[pos].value;
        } else {
            ans += ((W-capacity)*(arr[pos].value)*1.0)/arr[pos].weight;
            capacity = W;
        }
        pos++;
    }
    return ans;
}