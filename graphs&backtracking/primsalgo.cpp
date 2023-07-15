#include <iostream>
#include <vector>
#include <climits>
#include <iterator>
using namespace std;
class node
{
    public:
    int parent;
    int weight=INT32_MAX;
};
class graphnode
{
    public:
    int weight;
    int element;
    
};

void printtree(node * tree,int v)
{

    for(int i=1;i<v;i++)
    {
        if (tree[i].parent<i)
        {cout<<tree[i].parent<<" "<<i<<" "<<tree[i].weight<<endl;}
        else
       { cout<<i<<" "<<tree[i].parent<<" "<<tree[i].weight<<endl;}

    }
}
void explore(vector<graphnode> &graph,node *tree,
int index,int *visited,vector<graphnode> &visit)
{   
   
    for(int i=0;i<graph.size();i++)
    {
        
        if(tree[graph[i].element].weight>graph[i].weight&&
        visited[graph[i].element]==0)
        {
            tree[graph[i].element].parent=index;
            tree[graph[i].element].weight=graph[i].weight;
            graphnode node0;
       node0.element=graph[i].element;
       node0.weight=graph[i].weight;
       visit.push_back(node0);
        }

    }
}
void spantree(vector<vector<graphnode>> &graph,
node *tree,int v,int e)
{
    // bool *visited=new bool[v]{false};
     int *visited=new int[v]{0};
        tree[0].parent=-1;
        tree[0].weight=0;
       vector<graphnode> visit;
    //    graphnode node0;
    //    node0.element=0;
    //    node0.weight=0;
       explore(graph[0],tree,0,visited,visit);
       visited[0]=1;
    //    visited[0]=true;
   
  for(int m=1;m<v;m++) { 
       int wght=INT32_MAX;
    int j;
 for(int i=0;i<visit.size();i++)
 {  
          if(visited[visit[i].element]==0){
       if(wght>visit[i].weight)
       {
           wght=visit[visited[i]].weight;
           j=visit[i].element;
       }
     }
 }
explore(graph[j],tree,j,visited,visit);
     visited[j]=1;
   }
    printtree(tree,v);
    
delete [] visited;
}
int main() {
    int v,e;
    cin>>v>>e;
    node *tree=new node[v];
    vector<vector<graphnode>> graph(v);
    for(int i=0;i<e;i++)
    {
        graphnode gnode1;
        int p;
        cin>>p>>gnode1.element>>gnode1.weight;
        graph[p].push_back(gnode1);
        int temp=p;
        p=gnode1.element;
        gnode1.element=temp;
        graph[p].push_back(gnode1);
        
    }
    spantree(graph,tree,v,e);
    delete [] tree;
    return 0;

}