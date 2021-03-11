#include <bits/stdc++.h>
using namespace std;

int result = INT_MAX;
vector<int> vect1, vect2;
int total;
int c = 0;

void tug_of_war (vector<int> strength, int pos, int sum, int count, vector<bool> subset) {
    if (count == (strength.size()+1)/2) {
        c++;
        if (c==123) cout<<endl<<"check"<<"   "<<result<<" "<<sum<<" "<<total<<" "<<abs(sum - (total-sum))<<endl;
            for (int i=0; i<subset.size(); i++)
                cout << subset[i]<<","<<strength[i]<<" ";
            cout<<endl;
        if (result > abs(sum - (total-sum))) {
            cout<<result<<endl;
            result = abs(sum - (total-sum));
            vect1.clear();
            vect2.clear();
            for (int i=0; i<subset.size(); i++) {
                if (subset[i]) {
                    vect1.push_back(strength[i]);
                } else {
                    vect2.push_back(strength[i]);
                }
            }
        }
        return;
    }

    if (pos-count > (strength.size()+1)/2) return;
    tug_of_war(strength, pos+1, sum, count, subset);
    subset[pos] = true;
    tug_of_war(strength, pos+1, sum+strength[pos], count+1, subset);
    subset[pos] = false;
}

int main() 
{ 
    vector<int> arr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    // int total = 0;
    total = accumulate(arr.begin(), arr.end(), total);
    vector<bool> subset(arr.size(), false);
    tug_of_war (arr, 0, 0, 0, subset);

    for (int i=0; i<vect1.size(); i++) cout<<vect1[i]<<" ";
    cout<<endl;
    for (int i=0; i<vect2.size(); i++) cout<<vect2[i]<<" ";

    cout<<endl <<endl<<c;
    return 0; 
} 