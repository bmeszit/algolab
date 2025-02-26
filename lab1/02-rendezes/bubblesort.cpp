#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int n, vector<int>& a)
{
    for( int i = n ; i > 0 ; i-- ){
        for( int j = 0 ; j < i - 1 ; j++ ){
            if( a[ j ] > a[ j + 1] ) swap( a[j], a[ j + 1] );
        }
    }
}

int main()
{
    int n; cin>>n;
    vector<int> a(n); for(auto& ax: a) cin>>ax;
    
    bubble_sort(n, a);

    for(auto& ax: a) cout << ax << " ";
    cout << endl;

    return 0;
}
