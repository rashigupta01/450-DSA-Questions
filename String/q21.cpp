// if s[i] is close bracket and no open bracket left in stack reverse it and push in stack
// if at the end open brackets are left in stack, reverse half of them
int countRev (string s)
{
    int counter = 0, rev = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '{') {
            counter++;
        } else {
            if (counter) {
                counter--;
            } else {
                rev++;
                counter++;
            }
        }
    }
    if (counter&1) return -1;
    
    return rev + (counter/2);
}