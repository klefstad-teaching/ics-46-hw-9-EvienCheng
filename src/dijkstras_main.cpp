#include "dijkstras.h"

int main() {

    Graph G;
    file_to_graph("/home/evienc/ICS46/ics-46-hw-9-EvienCheng/src/small.txt", G);

    int source = 0;
    vector<int> previous;
    vector<int> distance = dijkstra_shortest_path(G, source, previous);

    for (int i = 0; i < G.numVertices; ++i) {
        vector<int> path = extract_shortest_path(distance, previous, i);
        print_path(path, distance[i]);
    }
}