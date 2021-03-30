// without stack: storing reverse of given string
char* reverse(char *S, int len)
{
    char* a = (char*) malloc (len * sizeof(char));
    for (int i=0; i<len; i++) {
        a[i] = S[len-i-1];
    }
    return a;
}

// inplace swapping
// swap the first half with the next half

// using stack
// first push all the characters in a stack then pop one by one and store in a new string(character array)