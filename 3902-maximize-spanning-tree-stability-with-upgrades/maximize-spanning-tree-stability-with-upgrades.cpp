class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);

        parent[b]=a;

        if(rankv[a]==rankv[b])
            rankv[a]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, long long x){

        DSU dsu(n);

        int used=0;
        int upgrades=0;

        vector<pair<int,int>> upgradeEdges;

        // must edges
        for(auto &e:edges){

            int u=e[0], v=e[1];
            long long s=e[2];
            int must=e[3];

            if(must==1){

                if(s<x) return false;

                if(!dsu.unite(u,v))
                    return false;

                used++;
            }
        }

        // normal edges
        for(auto &e:edges){

            int u=e[0], v=e[1];
            long long s=e[2];
            int must=e[3];

            if(must==0){

                if(s>=x){

                    if(dsu.unite(u,v))
                        used++;
                }
                else if(2*s>=x){

                    upgradeEdges.push_back({u,v});
                }
            }
        }

        // use upgrades if needed
        for(auto &p:upgradeEdges){

            if(used==n-1) break;

            if(dsu.unite(p.first,p.second)){
                upgrades++;
                used++;
            }
        }

        if(used!=n-1) return false;

        return upgrades<=k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        long long left=0, right=1e12;

        int ans=-1;

        while(left<=right){

            long long mid=(left+right)/2;

            if(can(n,edges,k,mid)){

                ans=mid;
                left=mid+1;
            }
            else{

                right=mid-1;
            }
        }

        return ans;
    }
};