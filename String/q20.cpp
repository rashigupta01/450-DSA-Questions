/*

For each character, store the sequence which should be obtained at its respective position in an array, 
i.e. for Z, store 9999. For Y, store 999. For K, store 55 and so on.

For each character, subtract ASCII value of ‘A’ and obtain the position in the array pointed 
by that character and add the sequence stored in that array to a string.

If the character is a space, store 0

Print the overall sequence.

*/

// refer https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/ for code