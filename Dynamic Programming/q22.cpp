// We have three cases
//  1) Exclude arr[i],  i.e.,  sum[i] = sum[i-1]
//  2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
//  3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 

//      sum[i] = max(sum[i-1], sum[i-2] + arr[i],
//              sum[i-3] + arr[i] + arr[i-1])