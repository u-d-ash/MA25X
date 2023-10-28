#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector< vector<int> > * graph, queue<int> * the_queue, vector<bool> * vis, vector< pair<int, int> > * mst){
    if((*the_queue).size() == 0){
        return;
    }
    int the_node = (*the_queue).front();
    cerr << "visiting " << the_node << endl;
    (*the_queue).pop();
    (*vis)[the_node] = true;

    for(auto child : (*graph)[the_node]){
        if(!(*vis)[child]){
            (*mst).push_back(make_pair(the_node, child));
            (*vis)[child] = true;
            (*the_queue).push(child);
        }
    }
    bfs(graph, the_queue, vis, mst);

}

int main(){
    int n, e; //nodes and edges;
    cin >> n >> e;
    vector< vector<int> > graph(n + 1);
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        for(auto child : graph[i]){
            cout << child << " ";
        }
        cout << endl;
    }

    queue<int> the_queue;
    vector<bool> vis(n + 1, false);
    the_queue.push(1);
    vector< pair<int, int> > mst;
    bfs(&graph, &the_queue, &vis, &mst);

   //Printing the minimum spanning tree : 

    for(int i = 0; i < mst.size(); i++){
        cout << mst[i].first << " " << mst[i].second << endl;
    }

}

/*
    Sample TC : 
    
    9 12
    1 2
    1 4
    2 6
    2 5
    2 3
    3 5
    4 6
    5 9
    5 7
    6 7
    6 9
    8 9
*/