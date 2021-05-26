// If we can survive for the first 7 days then we can survive any number of days. If following conditions satisfy
// -> N>=M 
// -> if (S >= 7) and (6*N) >= (7*M) 
    // then we can survive. 

// No of days we need to buy, D = ceil (total demand / daily supply) 
// but since we can not buy on sunday, final ans = D + floor((D-1)/6) [not sure though, on gfg this point was not menioned]


/*
? https://www.geeksforgeeks.org/survival/
! on gfg it was wrong according to me... following is my reason

We can not buy on seventh day so simply dividing total food demand by daily supply won't work. Let D = ceil (M*S/N) 
then that means we need to buy for D days. But after every 6th day there will be one day on which we can't buy. 
Lets say D=6, then that would be the final ans. But if D=7, final ans should be 8. Similarly for let say
D = 20 = 6 + 6 + 6 + 2, we need to add 3 (consider '+' as sunday), making final ans 23.

So the final answer should be = D + floor ((D-1)/6). Please correct me if i am wrong.
*/