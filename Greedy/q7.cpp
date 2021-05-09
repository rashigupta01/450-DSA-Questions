/*
        Algorithm:
1) Create seperate vectors for different platforms, each platform is independent
 from other and can be solved in the similar manner as of activity selection
2) Sort the train times according to their departure time 
3) Select the first train from the sorted array and print it. 
3) Do following for remaining trains in perticular platform. 
    If the start time of this train is greater than the departure time of previously
    selected train then select this train and print it.
*/