#include <bits/stdc++.h>
using namespace std;

void selection_sort(int n, vector<int>& a){
    for(int i=0; i<n; i++){
        int min_index = i;
        for(int j=i; j<n; j++){
            if(a[j]<a[min_index]){
                min_index = j;
            }
        }
        swap(a[min_index], a[i]);
    }
}

int main()
{
    int n; cin>>n;
    vector<int> a(n); for(auto& ax: a) cin>>ax;
    
    selection_sort(n, a);

    for(auto& ax: a) cout << ax << " ";
    cout << endl;

    return 0;
}
