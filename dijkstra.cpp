#include <bits/stdc++.h>
#include "dijkstra.h"
using namespace std;

int minDistance(int dist[], bool sptSet[]) {
    int min1 = INT_MAX, min_index;

    for (int v = 0; v < 40; v++) {
        if (sptSet[v] == false && dist[v] < min1) {
            min1 = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printpath(int parent[], int i, map<int, string> mp) {
    if (parent[i] == -1)
        return;

    printpath(parent, parent[i], mp);
    cout << mp[i] << "\n\n";
}

void printSolution(int dist[], int parent[], int des, map<int, string> mp, int src) {
    for (int i = 0; i < 40; i++) {
        if (i == des) {
            cout << "\nTime Taken: " << dist[i] << " Minutes\n";
            cout << "\nPath taken :\n\n";
            cout << mp[src] << endl << endl;
            printpath(parent, i, mp);
        }
    }
}

void dijkstra(int a[40][40], int src, int des, map<int, string> mp) {
    int dist[40];
    bool sptSet[40];
    int parent[40];
    for (int i = 0; i < 40; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    parent[src] = -1;
    for (int count = 0; count < 40 - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < 40; v++)
            if (!sptSet[v] && a[u][v] > 0 && dist[u] != INT_MAX
                && dist[u] + a[u][v] < dist[v]) {
                dist[v] = dist[u] + a[u][v];
                parent[v] = u;
            }
    }
    printSolution(dist, parent, des, mp, src);
}
