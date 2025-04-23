#include<bits/stdc++.h>
using namespace std;

struct boy{
    vector <int> order;
    int iter;
    int l;
};

struct girl{
    vector <int> order;
    int preferred;
};

void match(vector<girl> &girls,  vector<boy> &boys, int b){
    boy &bi=boys[b];
    if(bi.iter==bi.l) return;
    girl &gi=girls[bi.order[bi.iter]];
    if(gi.order[b]==0){
        bi.iter++;
        match(girls, boys, b);
        return;
    }
    if(gi.preferred==-1){
        gi.preferred=b;
        return;
    }
    if(gi.order[b]>=gi.order[gi.preferred]){
        bi.iter++;
        match(girls, boys, b);
        return;
    }
    int bn=gi.preferred;
    gi.preferred=b;
    boys[bn].iter++;
    match(girls, boys, bn);
}

int main()
{
    int n, m, k, x;
    cin>>n>>m;
    vector<girl> girls(m);
    vector<boy> boys(n);
    for(int i=0;i<n;i++){
        cin>>k;
        boys[i].l=k;
        boys[i].iter=0;
        for(int j=0;j<k;j++){
            cin>>x;
            boys[i].order.push_back(x-1);
        }
    }
    for(int i=0;i<m;i++){
        cin>>k;
        girls[i].order=vector<int> (n);
        girls[i].preferred=-1;
        for(int j=0;j<k;j++){
            cin>>x;
            girls[i].order[x-1]=j+1;
        }
    }

    for(int i=0;i<n;i++){
        match(girls, boys, i);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        if(girls[i].preferred!=-1){
            ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<m;i++){
        if(girls[i].preferred!=-1){
            cout<<girls[i].preferred+1<<' '<<i+1<<endl;
        }
    }
    return 0;
}