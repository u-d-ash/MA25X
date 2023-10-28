#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int> > * graph, vector<bool> * vis){
    (*vis)[node] = true;
    cerr << "Visiting node no : " << node << endl;
    for(auto child : (*graph)[node]){
        if(!(*vis)[child]){
            dfs(child, graph, vis);
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    vector < vector<int> > graph(n + 1);
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> vis(n + 1, false);
    dfs(1, &graph, &vis);

}