#include <bits/stdc++.h>
using namespace std;

void pakol( int honnan, int hova, int kozepso, int mennyit ){

    if( mennyit == 0 ){
        return;
    }

    pakol( honnan, kozepso, hova, mennyit -1 );
    cout << honnan << " " << hova << endl;
    pakol( kozepso, hova, honnan, mennyit -1 );

}

int main()
{
    int korongok;
    cin >> korongok;
    cout << (1 << korongok) - 1 << endl;
    pakol(1, 3, 2, korongok);

    return 0;
}
