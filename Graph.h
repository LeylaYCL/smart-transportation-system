#ifndef GRAPH_H
#define GRAPH_H

#define MAX_DURAK 200
#define INF 999999
//burda da duraklar arasındaki mesafeleri bastırmak için kullanıldı 
class Graph {
private:
    int mesafe[MAX_DURAK][MAX_DURAK];
    int boyut;

public:
    Graph();
    void setBoyut(int b);
    void baglantiAta(int i, int j, int value);
    int getMesafe(int i, int j);
    int getBoyut();

    void dijkstra(int baslangic, int* uzaklik, int* onceki);
};

#endif