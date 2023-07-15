#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> BFS(vector<vector<int>> edges,bool* visited,int v,int v1,int v2,vector<int>path)
{ 
    queue<int> q;
 q.push(v1);
 visited[v1]=true;
 while(!q.empty())
 {
     for(auto it:edges[q.front()])
     {
         if(visited[it]==false)
         {
         q.push(it);
         visited[it]=true;}
     }
     path.push_back(q.front());
     if(q.front()==v2)
     {
         return path;
     }
     q.pop();
 }
 if (path.empty()) {
    return path;
}
// for(int i=path.size();i>0;i--)
// {
//     path.pop_back();
// }
vector<int> path2;
return path2 ;
}

int main() {
    int v,e,v1,v2;
    cin>>v>>e;
    vector<vector<int>> edges(v);
    for(int i=0;i<v;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f].push_back(s);
        edges[s].push_back(f);

    }
    bool * visited =new bool[v]{false};
   
    cin>>v1>>v2;
 vector<int> path;
 if(v1==v2)
{
    cout<<v1;
    return 0;
}
if(v1>=v||v2>=v||v<=0||e<=0)
{
    return 0;
}

path=BFS(edges,visited,v,v1,v2,path);
if(path.empty()){return 0;}
for(auto it:path)
{
    cout<<it<<" ";
}
    delete [] visited;
    return 0;
   
}