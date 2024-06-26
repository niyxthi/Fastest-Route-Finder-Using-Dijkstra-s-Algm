#include <bits/stdc++.h>
#include "adj_mat.h"
#include "dijkstra.h"
#include "station_mapping.h"
using namespace std;

int main() {
    map<int, string>::iterator itr;
    int src, des, flag = 0;
    cout << "\n\nFINDING THE FASTEST ROUTE THROUGH METRO/RAILWAYS\n";
    cout << "\n------------------------------------------------------------\n\n";
    int graph[40][40] = {};
    adj_mat(graph);
    map<int, string> area;
    mapped(area);
    cout << "\n------------------------------------------------------------\n";
    cout << "\n Enter the boarding station number:";
    cin >> src;
    src = src -1;
    cout << "\n Enter the destination station number:";
    cin >> des;
    des = des - 1;
    cout << "\n------------------------------------------------------------\n\n";
    if (area[src] == "") {
        cout << "Oops! invalid Source";
        return -1;
    }
    if (area[des] == "") {
        cout << "Oops! invalid Destination";
        return -1;
    }
    dijkstra(graph, src, des, area);
    return 0;
}
