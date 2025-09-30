#include "Graph.h"

Graph::Graph() {
    boyut = 0;
    for (int i = 0; i < MAX_DURAK; i++) {
        for (int j = 0; j < MAX_DURAK; j++) {
            mesafe[i][j] = -1;
        }
    }
}
//burdaki boyut atamaları durak mesafeleri için
void Graph::setBoyut(int b) {
    boyut = b;
}

void Graph::baglantiAta(int i, int j, int value) {
    mesafe[i][j] = value;
}

int Graph::getMesafe(int i, int j) {
    return mesafe[i][j];
}

int Graph::getBoyut() {
    return boyut;
}

void Graph::dijkstra(int baslangic, int* uzaklik, int* onceki) {
    bool ziyaret[MAX_DURAK];

    for (int i = 0; i < boyut; i++) {
        uzaklik[i] = INF;
        onceki[i] = -1;
        ziyaret[i] = false;
    }

    uzaklik[baslangic] = 0;

    for (int i = 0; i < boyut; i++) {
        int min = INF, u = -1;

        for (int j = 0; j < boyut; j++) {
            if (!ziyaret[j] && uzaklik[j] < min) {
                min = uzaklik[j];
                u = j;
            }
        }

        if (u == -1) break;

        ziyaret[u] = true;

        for (int v = 0; v < boyut; v++) {
            int mesafeUV = mesafe[u][v];
            if (mesafeUV != -1 && !ziyaret[v]) {
                int alternatif = uzaklik[u] + mesafeUV;
                if (alternatif < uzaklik[v]) {
                    uzaklik[v] = alternatif;
                    onceki[v] = u;
                }
            }
        }
    }
}