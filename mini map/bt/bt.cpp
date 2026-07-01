#include <iostream>
#include <vector>
#include <string>

using namespace std;

//========================
// Vertex (Địa điểm)
//========================
struct City
{
    int id;
    string name;
};

//========================
// Edge (Con đường)
//========================
struct Edge
{
    int to;
    double distance;
};

//========================
// Graph
//========================
class Graph
{
private:
    vector<City> vertices;
    vector<vector<Edge>> adj;

public:

    // Thêm địa điểm
    void addCity(string name)
    {
        City city;

        city.id = vertices.size();
        city.name = name;

        vertices.push_back(city);

        adj.push_back({});
    }

    // Thêm đường (2 chiều)
    void addRoad(int from, int to, double distance)
    {
        adj[from].push_back({ to, distance });
        adj[to].push_back({ from, distance });
    }

    // In bản đồ
    void printGraph() const
    {
        cout << "\n===== MAP =====\n\n";

        for (int i = 0; i < vertices.size(); i++)
        {
            cout << vertices[i].name << " -> ";

            for (const Edge& edge : adj[i])
            {
                cout << vertices[edge.to].name
                    << " (" << edge.distance << " km)  ";
            }

            cout << endl;
        }
    }

    int size() const
    {
        return vertices.size();
    }

    const vector<Edge>& neighbors(int id) const
    {
        return adj[id];
    }

    string getCityName(int id) const
    {
        return vertices[id].name;
    }
};

//========================
// Main
//========================
int main()
{
    Graph graph;

    // Thêm địa điểm
    graph.addCity("Home");
    graph.addCity("School");
    graph.addCity("Hospital");
    graph.addCity("Airport");
    graph.addCity("Mall");

    // Thêm đường
    graph.addRoad(0, 1, 5);
    graph.addRoad(0, 2, 3);
    graph.addRoad(1, 3, 6);
    graph.addRoad(2, 3, 10);
    graph.addRoad(2, 4, 4);
    graph.addRoad(4, 3, 2);

    // Hiển thị bản đồ
    graph.printGraph();

    return 0;
}