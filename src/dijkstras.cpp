#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;
    // cout << source << endl;

    vector<int> distance(n, INF);
    previous.assign(n, -1);
    vector<bool> visited(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({source, 0});
    distance[source] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])continue;
        visited[u] = true;

        for (const Edge &neighbor : G[u])
        {
            int v = neighbor.dst;
            int weight = neighbor.weight;

            if (!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    vector<int> path;
    for (int a = destination; a != -1; a = previous[a])
    {
        path.push_back(a);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << (i + 1 < v.size() ? " " : "");
    }
    cout << "\nTotal cost is " << total << endl;
}
