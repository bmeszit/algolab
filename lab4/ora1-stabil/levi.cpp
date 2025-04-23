#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
struct edge
{
    int ia, ib;
    int pa, pb;
};
struct graph
{
    vector<edge> e;
    vector<vi> a;
    vector<vi> b;
    vi ma;
    vi mb;
    void propose()
    {
        int na = a.size();
        int nb = b.size();
        ma = vi(na, -1);
        mb = vi(nb, -1);
        vi p(nb, -1);
        vi c(na, 0);
        vi vq(na); iota(vq.begin(), vq.end(), 0);
        for(int vi = 0; vi < vq.size(); ++vi)
        {
            int ia = vq[vi];
            if(c[ia] == a[ia].size())
                continue;
            auto &ee = e[a[ia][c[ia]]];
            ++c[ia];
            int ib = ee.ib;
            int pb = ee.pb;
            if(mb[ib] == -1)
            {
                ma[ia] = ib;
                mb[ib] = ia;
                p[ib] = pb;
            }
            else if(p[ib] > pb)
            {
                vq.push_back(mb[ib]);
                ma[mb[ib]] = -1;
                ma[ia] = ib;
                mb[ib] = ia;
                p[ib] = pb;
            }
            else
            {
                vq.push_back(ia);
            }
        }
    }
};
int main()
{
    int na, nb; cin >> na >> nb;
    graph g;
    g.a.resize(na);
    g.b.resize(nb);

    map<pair<int, int>, pair<int, int>> mp;
    for(int ia = 0; ia < na; ++ia)
    {
        int k; cin >> k;
        for(int ie = 0; ie < k; ++ie)
        {
            int ib; cin >> ib; --ib;
            mp[{ ia, ib }] = { ie, 0 };
        }
    }
    for(int ib = 0; ib < nb; ++ib)
    {
        int k; cin >> k;
        for(int ie = 0; ie < k; ++ie)
        {
            int ia; cin >> ia; --ia;
            mp[{ ia, ib }].second = ie;
        }
    }
    for(auto [iab, pab] : mp)
    {
        edge e = { iab.first, iab.second, pab.first, pab.second };
        g.e.push_back(e);
    }
    sort(g.e.begin(), g.e.end(), [&](const edge &e1, const edge &e2)
    {
        return e1.pa < e2.pa;
    });
    for(int ie = 0; ie < g.e.size(); ++ie)
    {
        auto &e = g.e[ie];
        g.a[e.ia].push_back(ie);
        g.b[e.ib].push_back(ie);
    }

    g.propose();

    int cnt = 0;
    for(int ia = 0; ia < na; ++ia)
        cnt += (g.ma[ia] != -1);
    cout << cnt << "\n";
    for(int ia = 0; ia < na; ++ia)
        if(g.ma[ia] != -1)
            cout << ia + 1 << " " << g.ma[ia] + 1 << "\n";
    cout << flush;
}
