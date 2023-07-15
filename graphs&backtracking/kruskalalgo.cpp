#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class edge
{
    public:
    int weight;
    int v1;
    int v2;
   void swap()
    {
        int a=v1;
        this->v1=this->v2;
        this->v2=a;
    }
};
bool compare_w8(const edge& edge1, const edge& edge2)
{
    return edge1.weight <= edge2.weight;
}
void sortgraph(edge *graph,int e)
{

    sort(graph,graph+e,compare_w8);
}
void _parent(int parent[],int v1,int v2,int v)
{
    int _parentv2=parent[v2];
    for(int i=0;i<v;i++)
    {
        if(parent[i]==_parentv2)
        {
            parent[i]=_parentv2;
        }
    }
}
void MST(edge *graph,edge *ans,int ans_index,int g_index,int parent[],int v)
{ 
if(ans_index==v-1)
{
    return;
}
   if( parent[graph[g_index].v1]== parent[graph[g_index].v2])
{
    MST(graph,ans,ans_index,g_index+1,parent,v);
} else
{
 ans[ans_index]=graph[g_index];
 _parent(parent,ans[ans_index].v1,ans[ans_index].v2,v);
 MST(graph,ans,ans_index+1,g_index+1,parent,v);
 }
}
void spanningtree(edge *graph,edge *ans,int parent[],int v)
{
    
    ans[0]=graph[0];
    parent[ans[0].v2]= parent[ans[0].v1];
    // parent[graph[0].v1]= parent[ans[0].v1];
    MST(graph,ans,1,1,parent,v);

}
void kruskal(edge *graph,int v,int e)
{
    int parent[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    sortgraph(graph,e);
    edge *ans=new edge[v-1];
  spanningtree(graph,ans,parent,v);
 sortgraph(ans,v-1);
  for(int i=0;i<v-1;i++)
  {
    if (ans[i].v1 < ans[i].v2) {
      cout << ans[i].v1 <<" "<< ans[i].v2<<" " << ans[i].weight << endl;
    }else
    {
        cout << ans[i].v2 <<" "<< ans[i].v1<<" " << ans[i].weight << endl;
       
    }
  }
  delete [] ans;
}
int main() {
    int v;
    int e;
    cin>>v>>e;
    if(v<2||e<0)
    {
        return 0;
    }
    edge *graph=new edge[e];
    for(int i=0;i<e;i++)
    {
        
        cin>>graph[i].v1>>graph[i].v2>>graph[i].weight;
         if(graph[i].v1>graph[i].v2)
        {
            graph[i].swap();
        }
    }
    kruskal(graph,v,e);
    delete [] graph;
    return 0;
}