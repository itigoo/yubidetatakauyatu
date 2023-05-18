#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define pp pair<ll,ll>
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
#define difine define
constexpr int inf=1000001000;
constexpr ll INF=2e18;
constexpr ll MOD=1000000007;
constexpr ll mod=998244353;
int dx[4]={1,-1,-1,1},dy[4]={1,-1,1,-1};

 
// #include <atcoder/all>
// typedef atcoder::modint1000000007 mint;
// typedef atcoder::modint998244353 mint;

int main() {
    map<vector<int>,int> m;
    map<int,vector<int>> mm;
    vector<int> v(pow(5,4),2);
    vector<vector<int>> e(v.size(),vector<int>(0));
    vector<vector<int>> ee(v.size(),vector<int>(0));
    int now=0;
    rep(i,pow(5,4)){
        int f=i;
        vector<int> a(4,0);
        rep(j,4){
            a[j]=f%5;
            f/=5;
        }
        m[a]=now;
        mm[now]=a;
        now++;
    }
    rep(i,pow(5,4)){
        int f=i;
        vector<int> a(4,0);
        rep(j,4){
            a[j]=f%5;
            f/=5;
        }
        vector<int> b;
        b=a;
        if (b[0]!=0){
            if (b[2]!=0){
                b[2]=(b[2]+b[0])%5;
                swap(b[0],b[2]);
                swap(b[1],b[3]);
                int o=m[b];
                b=a;
                if (find(all(e[i]),o)==e[i].end()) e[i].push_back(o);
                if (find(all(e[o]),i)==e[o].end()) ee[o].push_back(i);
            }
            if (b[3]!=0){
                b[3]=(b[3]+b[0])%5;
                swap(b[0],b[2]);
                swap(b[1],b[3]);
                int o=m[b];
                b=a;
                if (find(all(e[i]),o)==e[i].end()) e[i].push_back(o);
                if (find(all(e[o]),i)==e[o].end()) ee[o].push_back(i);
            }
        }
        if (b[1]!=0){
            if(b[2]!=0){
                b[2]=(b[2]+b[1])%5;
                swap(b[0],b[2]);
                swap(b[1],b[3]);
                int o=m[b];
                b=a;
                if (find(all(e[i]),o)==e[i].end()) e[i].push_back(o);
                if (find(all(e[o]),i)==e[o].end()) ee[o].push_back(i);
            }
            if (b[3]!=0){
                b[3]=(b[3]+b[1])%5;
                swap(b[0],b[2]);
                swap(b[1],b[3]);
                int o=m[b];
                b=a;
                if (find(all(e[i]),o)==e[i].end()) e[i].push_back(o);
                if (find(all(e[o]),i)==e[o].end()) ee[o].push_back(i);
            }
        }
        // int y=b[0]+b[1];
        // for (int j=0;j<=4;j++){
        //     if (y-j>=5 || y-j<0 || j==b[0]) continue;
        //     if (j==0 || y-j==0){
        //         if (b[0]==0 || b[1]==0) continue;
        //     }
        //     b[0]=j;
        //     b[1]=y-j;
        //     swap(b[0],b[2]);
        //     swap(b[1],b[3]);
        //     int o=m[b];
        //     b=a;
        //     if (find(all(e[i]),o)==e[i].end()) e[i].push_back(o);
        //     if (find(all(e[o]),i)==e[o].end()) ee[o].push_back(i);
        // }
    }
    vector<int> sum(pow(5,4),0);
    queue<int> q;
    rep(i,pow(5,4)){
        sum[i]=e[i].size();
        if (sum[i]==0){
            q.push(i);
            int f=i,ff=i;
            f/=25;ff/=125;
            if (f%5==0 && ff%5==0) v[i]=1;
        }
    }
    while(!q.empty()){
        int f=q.front();
        q.pop();
        if (v[f]==2) v[f]=0;
        for (int i:ee[f]){
            if (v[i]!=2) continue;
            if (v[f]==0){
                v[i]=1;
                q.push(i);
            }
            else{
                sum[i]--;
                if (sum[i]==0) q.push(i);
            }
        }
    }
    // int n;
    // cin >> n;
    // for (int i:e[n]){
    //     cout << i << " ";
    //     vector<int> b;
    //     b=mm[i];
    //     rep(j,4) cout << b[j];
    //     cout << " " << v[i] << endl;
    // }
    // rep(i,pow(5,4)){
    //     int f=i;
    //     vector<int> a(4,0);
    //     rep(j,4){
    //         a[j]=f%5;
    //         f/=5;
    //     }
    //     if (i%25==0) cout << endl;
    //     rep(j,4) cout << a[j];
    //     cout << " " << v[i] << " ";
    // }
    // cout << endl;
    int turn = 156;
    while(true){
        vector<int> b;
        b=mm[turn];
        rep(j,4) cout << b[j] << " ";
        cout << endl;
        vector<int> a(4);
        rep(j,4) cin >> a[j];
        swap(a[0],a[2]);
        swap(a[1],a[3]);
        int w=m[a];
        if (find(all(e[turn]),w)==e[turn].end()){
            cout << "不可能な操作です" << endl;
            continue;
        }
        turn = w;
        for (int i:e[turn]){
            if (v[turn]==1){
                if (v[i]==0){
                    turn = i;
                    break;
                }
            }
            else if (v[turn]==2){
                if (v[i]==2){
                    turn = i;
                    break;
                }
            }
            else{
                turn = i;
                break;
            }
        }
    }
}

