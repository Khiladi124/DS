#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
class edge {
public:
  int weight;
  int dest;

  edge() {}

  edge(int _wgt, int _dest) {
    this->dest = _dest;
    this->weight = _wgt;
  }

  edge operator=(edge const& obj) {
    edge temp;
    temp.dest = obj.dest;
    temp.weight = obj.weight;
    return temp;
  }

  bool operator<(edge const& rhs) const{
    if(weight!=rhs.weight){
    return weight < rhs.weight;}
    else return dest<rhs.dest;
  }
};

void print(int dist[], int v) {
  cout<<"OUTPUT IS->>>"<<endl<<"---------------------------------------------"<<endl;
  for (int i = 0; i < v; i++) {
    std::cout << i << " " << dist[i] << std::endl;
  }
}

void run_dijkstra(std::vector<std::vector<edge>>& graph,  int dist[],
 int v, int e) {
set<edge> st;
  edge temp(0,0);
  st.insert(temp);
  dist[0] = 0;
  while (!st.empty()) {
    edge ver = *st.begin();
    st.erase(st.begin());
   
    for (auto it = graph[ver.dest].begin(); it != graph[ver.dest].end(); 
    ++it) {
      if (dist[(*it).dest] > dist[ver.dest] + (*it).weight) {
        dist[(*it).dest] = dist[ver.dest] + (*it).weight;
        edge e((*it).weight,(*it).dest);
         st.insert(e);
      }
    }
  }
  print(dist, v);
}

void dijkstra(std::vector<std::vector<edge>>& graph, int v, int e)
 {
  int dist[v];
  for(int i=0;i<v;i++)
  {
    dist[i]=INT_MAX;
  }
  run_dijkstra(graph, dist, v, e);
}

void graphbuilding() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<edge>> graph(v);
  for (int i = 0; i < e; i++) {
    int s, d, w;
    std::cin >> s >> d >> w;
    edge e(w, d);
    graph[s].push_back(e);
    e.dest = s;
    graph[d].push_back(e);
  }
  dijkstra(graph, v, e);
}

int main() {
  graphbuilding();
  return 0;
}
