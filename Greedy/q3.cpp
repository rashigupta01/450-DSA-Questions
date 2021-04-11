    #include<bits/stdc++.h>
using namespace std;

ofstream outfile ("out.txt");

struct node {
    string data;
    int frequency;
    node *left, *right;

    node(string str, int freq) {
        data = str;
        frequency = freq;
        left = NULL;
        right = NULL;
    }
};

// using operator overloading to define the priority condition for priority_queue
class compareFrequency {
    public:
    bool operator() (node *a, node *b) {
        return (a->frequency) > (b->frequency);
    }
};

node* huffman (vector<pair<string,int>> strings){       // O(nlogn)    

    priority_queue <node*, vector<node*>, compareFrequency> pq;     // min heap

    for (auto ele : strings) {      // pushing all the elements in the pq
        node* temp = new node(ele.first, ele.second);
        pq.push(temp);
    }

    while (pq.size()>1) {

        node* a = pq.top();
        pq.pop();
        node* b = pq.top();
        pq.pop();

        node *temp = new node("", a->frequency + b->frequency);
        temp->left = a;
        temp->right = b;

        pq.push(temp);
    }
    
    return pq.top();
}

// method to find the encoding for each element from the huffman tree
void huffmanEncoding (node* root, string encoding = "") {
    
    if (!root->left && !root->right) {
        if (encoding.empty()) {
            outfile << root->data << " -> 0" << endl;
        } else {
            outfile << root->data <<" -> " << encoding <<endl;
        }
        return;
    }

    huffmanEncoding (root->left, encoding+"0");
    huffmanEncoding (root->right, encoding+"1");
}

/* Driver code*/
int main() {

    int t;
    ifstream infile ("in.txt");
    if (!infile) {
        cout<<"Input file is missing";
        return -1;
    }
    infile >> t;

	while(t--) {
	    
        int n;
        infile>>n;
	    vector<pair<string,int>> strings;
	    
	    for (int i = 0; i < n; i++){
            string str;
            int freq;
	        infile >> str >> freq;
	        
	        strings.push_back({str, freq});
	    }
	    
        node* huffmanRoot = huffman(strings);

        huffmanEncoding (huffmanRoot);
        outfile << endl;
	}

	return 0;
}
