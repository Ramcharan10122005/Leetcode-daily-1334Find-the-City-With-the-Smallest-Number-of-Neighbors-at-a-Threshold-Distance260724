#include <stdio.h>
#include <limits.h>

int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold) {
    int dist[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 0; i < edgesSize; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        dist[u][v] = wt;
        dist[v][u] = wt;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    int cityNo = -1;
    int cityCnt = n;
    for (int city = 0; city < n; ++city) {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; ++adjCity) {
            if (dist[city][adjCity] <= distanceThreshold) {
                cnt++;
            }
        }
        if (cnt <= cityCnt) {
            cityCnt = cnt;
            cityNo = city;
        }
    }
    
    return cityNo;
}
