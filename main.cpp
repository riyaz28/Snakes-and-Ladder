#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define twv vector<vector<int>>
#define fo(i,a,n) for(int i=int(a);i<int(n);i++)
#define op(x) cout<<x
#define ip(x) cin>>x
#define si set<int>
#define sc set<char>
#define ss set<string>
#define qqi queue<int>
#define qqc queue<char>
#define sti stack<int>
#define stc stack<char>
#define nl cout<<"\n"
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
using namespace std;

template<typename T>  //we are declaring templates because we are implementing for all node data types

class graph
{
    map<T,list<T>>l;
public:
    void addEdge(T x,T y)
    {
        l[x].pb(y);
    }
    void bfs(T src,T dest)
    { map<T,int>dist;
    map<T,T>parent;
      queue<T>q;
      q.push(src);
      for(auto p:l)       //initially all nodes are set to INT_MAX
      {
          T node=p.first;
          dist[node]=INT_MAX;
      }
      dist[src]=0;
      parent[src]=src;  //parent of src is src itself
      while(!q.empty())
      {
          T node=q.front();
          q.pop();
          for(auto child:l[node])
          {
              if(dist[child]==INT_MAX)   //if node not visited
              {   q.push(child);
                  dist[child]=dist[node]+1;
                  parent[child]=node;
              }
          }

      }
      T temp=dest;
     /* for(auto temp:parent)
      {
          cout<<temp.first<<" "<<temp.second<<" ";
          cout<<endl;
      }*/
      while(temp!=src)   //until temp reaches 0
      {
          cout<<temp<<"<-";
          temp=parent[temp];  //returns to parent node
      }
      cout<<src<<endl;
    cout<<dist[dest];
    }

};
int main()
{
    graph<int>g;
    //board jumps array
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    //add all edges
    for(int i=0;i<=36;i++)
    {for(int dice=1;dice<=6;dice++)
    { int j=i+dice+board[i+dice];
        if(j<=36)
        g.addEdge(i,j);//unidirectional unwieghted graph
    }
    }
    g.addEdge(36,36);  //cause j is atleast 37,above if condition wont satisfy hence we are adding an edge to 36,we are considering 36 exists
    g.bfs(0,36);
    return 0;
}
