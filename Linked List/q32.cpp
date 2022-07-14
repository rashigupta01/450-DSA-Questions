// my approach
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    long long res=0;
    long long MOD = 1000000007;
    Node* t1 = l1;
    Node* t2 = l2;
    while (t1) {
        long long temp = 0;
        t2 = l2;
        while (t2) {
            temp = (temp*10 + t1->data*t2->data) % MOD;
            t2 = t2->next;
        }
        res = (res*10 + temp) % MOD;
        t1 = t1->next;
    }
    return res;
}

// simply generate the numbers from linked lists
// return their product and modulo with 10e7