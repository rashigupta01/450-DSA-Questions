// Using auxiliary array 
// Keep an array of indices, sort all the words content (cat -> act), then sort the words along with index array
// now all the anagram words will be together, use the index value to get the original words

// Using map
// 1. key as sorted form of word and value as list of strings (O(nmlogm))
// 2. key as map of frequency of letters in the word (O(mn))

// Using Trie: https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-set-2/
// 1) Create an empty Trie
// 2) One by one take all words of input sequence. Do following for each word
//      …a) Copy the word to a buffer.
//      …b) Sort the buffer
//      …c) Insert the sorted buffer and index of this word to Trie. Each leaf node 
//        of Trie is head of a Index list. The Index list stores index of words in original sequence. 
//        If sorted buffe is already present, we insert index of this word to the index list.
// 3) Traverse Trie. While traversing, if you reach a leaf node, traverse the index list. And print all 
//    words using the index obtained from Index list.