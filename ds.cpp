#include<iostream>
#include<vector>
using namespace std;

class disjoint_set{
    
    public:
    vector<int> rank,size,par;
    
    disjoint_set(int n){
        //creating the disjoint data-structure that involves either rank and parent array or size and parent array.
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
    }
    int findpar(int x){
        if(x==par[x]){
            return x;
        }
        return par[x]=findpar(par[x]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u!=ulp_v){
            //smaller rank gets connected to the larger one
            if(rank[ulp_u]<rank[ulp_v]){
                par[ulp_u]=ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                par[ulp_v]=ulp_u;
            }
            else{
                //ranks of ulp_v and ulp_u are equal
                par[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
    }
    
    void unionBySize(int u,int v){
        int ulp_u=findpar(u);
        int ulp_v=findpar(v);
        if(ulp_u!=ulp_v){
            if(size[ulp_u]<size[ulp_v]){
                par[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                //ulp_u is greater than ulp_v or equal
                par[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    }

};
class solution{
    public:
    void solve(){
        int n=10;
        disjoint_set ds(n);
        ds.unionBySize(0,1);
        ds.unionBySize(2,4);
        ds.unionBySize(3,5);
        ds.unionBySize(2,9);
        ds.unionBySize(0,4);
        for(int i=0;i<n;i++){
            cout<<"Parent of "<<i<<" is "<<ds.findpar(i)<<endl;
        }
    }
};
int main(){
    solution s;
    s.solve();
    return 0;
}