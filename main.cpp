#include<iostream>

using namespace std;

template<int N>
class DisjointSetUnion{
    // we will make two array for parent and rank
    int *parent=new int[N];
    int *rank=new int[N];

    public:
    DisjointSetUnion(){
        // initially parent of each element is itself and rank of every elemnt is 0
        for(int i=0;i<N;i++){
            parent[i]=i;//so parent of every elem is itself
            rank[i]=0; //rank is 0 for all elem initially
        }
    }

    // now make a find function with path compression
    // path compression means that after first find operation every element which we trversed during dinf now will connected directly to the root so it will make future operation much faster
    // lets make this
    int find(int n){
        if(parent[n]!=n){
            // if n is not parent of itself 
            parent[n]=find(parent[n]); //we will find the parent of n recursively and set n new parent this is called path compression
        }
        // when we find root of n or n is self parent
        return parent[n];
    }

    // now lets make union_set method
    void union_set(int u,int v){
        // first get the ultimate  parent or root of both u and v
        int root_u=find(u);
        int root_v=find(v);
        if(root_u!=root_v){
            // if both doesnt same root so not in same set
            if(rank[root_u]>rank[root_v]){
                // if rank_u is greater
                parent[root_v]=root_u;
            }
            else if(rank[root_v]>rank[root_u]){
                parent[root_u]=root_v; 
            }
            else{
                // both root are of same rank
                // so make any on ethe root and increse the rank
                parent[root_v]=root_u;
                rank[root_u]++;
            }
        }
    }

    // lets make a function to check if a element s in same set or not
    bool isConnected(int u,int v){
        return find(u)==find(v); //of both u and v root are same then they both are in same set
    }
};

int main(){
    DisjointSetUnion<5> dsu; //set of 5 elem

    dsu.union_set(0,2);
    dsu.union_set(1,2);
    dsu.union_set(3,4);

    cout<<"Is 0 and 4 connected "<<dsu.isConnected(0,1)<<endl; //so they are not connected but lets check for 1 and 0
     
    return 0;
}// thanks for watching