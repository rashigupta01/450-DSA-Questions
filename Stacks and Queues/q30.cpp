// short and nice code : https://ide.geeksforgeeks.org/oYaqmr
// same approach as of mine
int tour(petrolPump p[],int n)
{
   //Your code here
   int start=0,deficit=0;
   int capacity=0;
   
   for(int i=0;i<n;i++)
   {
       capacity+=p[i].petrol-p[i].distance;
       if(capacity<0){
           start=i+1;
           deficit+=capacity;
           capacity=0;
       }
   }
   return(capacity+deficit>0)?start:-1;
}


// My code : (without queue)
class Solution {
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int left[n];
        for (int i=0; i<n; i++) {
            left[i] = p[i].petrol - p[i].distance;
        }
        int start = 0;
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += left[i];
            if (sum<0) {
                sum=0;
                start = i+1;
            }
        }
        if (start == n) return -1;
        int req = 0;
        for (int i=0; i<start; i++) {
            sum+= left[i];
            if (sum<0) return -1;
        }
        return start;
    }
};