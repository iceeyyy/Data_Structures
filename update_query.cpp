#include <vector>
#include <iostream>

using namespace std;

void buildTree(int i ,int l ,int r,vector<int>& SegmentTree, vector<int>& input){
    if(l==r){
        SegmentTree[i] = input[r];
        return;
    }

    int mid = (l+r)/2;
    buildTree(2*i+1,l,mid,SegmentTree,input);
    buildTree(2*i+2,mid+1,r,SegmentTree,input);

    SegmentTree[i] = SegmentTree[2*i+1] + SegmentTree[2*i+2];
    
}

void updateQuery(int i, int l, int r, vector<int>& SegmentTree, vector<int>& input, int idx, int value) {

    if(l==r){
        SegmentTree[i]=value;
        return;
    }

    int mid=(l+r)/2;

    if(idx<=mid){ //left side 
        updateQuery(2*i+1,l,mid,SegmentTree,input,idx,value);
    }

    updateQuery(2*i+2,mid+1,r,SegmentTree,input,idx,value);

    SegmentTree[i] = SegmentTree[2*i+1] + SegmentTree[2*i+2];
}

int main(){
    vector<int> input = {1,2,56,7};
    int n = input.size();

    vector<int> SegmentTree(2*n+1,0);

    buildTree(0,0,n-1,SegmentTree,input); // i was passing wrong r it was supposed to be n-1

    for(auto it:SegmentTree){
        cout<<it<<" ";
    }
    cout<<"---- Segment Tree Built Successfully"<<endl;

    updateQuery(0,0,n-1,SegmentTree,input,1,40);

    for(auto it:SegmentTree){
        cout<<it<<" ";
    }
    cout<<"---- Updated Segment Tree"<<endl;

    
    return 0;
}