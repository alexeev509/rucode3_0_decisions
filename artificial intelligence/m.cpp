#include <iostream>

using namespace std;

int n=-1, q=-1, x=-1, y=-1;
long double mass[300001];
long double summ[300001];

int main() {
    cout.precision(7);

    cin>>n;
    summ[0] = 0;
    for( int i=1; i<=n;++i){
        cin>>mass[i];
        summ[i]=log(mass[i])+summ[i-1];
    }
    cin>>q;
    for(int i=1;i<=q; ++i){
        cin>>x>>y;
        ++x,++y;
        long  double ans = exp((summ[y]-summ[x-1])/(y-x+1));
        cout<<ans<<endl;
    }


    return 0;
}
