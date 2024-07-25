#include<bits/stdc++.h>
using namespace std;

// Define the graph as an adjacency list
typedef unordered_map<int, unordered_map<int, int>> Graph;

// Define a custom comporator for the priority queue
class Compare{
    public:
    bool operator()(pair<int,int>& p1, pair<int,int>& p2){
        return p1.second > p2.second;
    }
};

unordered_map<int, int>
dijsktras(const Graph& graph, int source){

    // Initialise the distance with all nodes except the source
    unordered_map<int,int> distances;
    for(const auto& node : graph){
        distances[node.first] = INT_MAX;
    }
    distances[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> pq;
    pq.push({source,0});

    while(!pq.empty()){
        int current_vertex = pq.top().first;
        int current_distance = pq.top().second;
        pq.pop();

        for (const auto& neighbour : graph.at(current_vertex)){
            int neighbour_vertex = neighbour.first;
            int weight = neighbour.second;
            int distance = current_distance + weight;

            if(distance < distances[neighbour_vertex]){
                distances[neighbour_vertex] = distance;
                pq.push({neighbour_vertex, distance});
            }
        }
    }
    return distances;
}

int main(){
    // Sample test cases
    Graph graph = {{0, {{1,4}, {2,1}}}, {1, {{3,1}}}, {2, {{1,2}, {3,5}}}, {3, {}}};

    int source = 0;

    unordered_map<int, int> result = dijsktras(graph, source);

    for(const auto& pair : result){
        cout << pair.first << ":" << pair.second << endl;
    }
    return 0;
}
