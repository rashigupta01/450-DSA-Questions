/*
The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in remaining rows, 
we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the 
element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has
appeared m-1 times before. 

https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
*/