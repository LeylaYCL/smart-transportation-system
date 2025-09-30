#include <iostream>
#include <windows.h>
#include <cstring>
#include "Utils.h"
#include "Graph.h"
#include "Tree.h"

int main() {
    SetConsoleOutputCP(65001); // türkçe karkterler için

    Durak duraklar[200];
    int durakSayisi = 0;

    Hat hatlar[20];
    int hatSayisi = 0;

    Yolcu yolcular[100];
    int yolcuSayisi = 0;

    int mesafeMatrisi[200][200];
    int boyut = 0;

    Graph graph;
    Tree agac;

    // txt dosyalarını aldık
    duraklariOku("data/durak_listesi.txt", duraklar, durakSayisi);
    hatlariOku("data/hatlar.txt", hatlar, hatSayisi);
    yolculariOku("data/yolcu_listesi.txt", yolcular, yolcuSayisi);
    mesafeleriOku("data/durak_mesafeleri.txt", mesafeMatrisi, boyut);

    graph.setBoyut(boyut);  //durakar arasındaki mesafe için
    for (int i = 0; i < boyut; i++)
        for (int j = 0; j < boyut; j++)
            if (mesafeMatrisi[i][j] != -1)
                graph.baglantiAta(i, j, mesafeMatrisi[i][j]);

    for (int i = 0; i < durakSayisi; i++)
        agac.ekle(duraklar[i]);

    int secim;
    do {
        std::cout << "\n=== AKILLI ULAŞIM SİSTEMİ ===\n";
        std::cout << "1. Tum Hatlari Listele\n";
        std::cout << "2. Yolculuk Planla\n";
        std::cout << "3. Durak Ara\n";
        std::cout << "4. Cikis\n";
        std::cout << "Seciminiz: ";
        std::cin >> secim;

        if (secim == 1) {
            for (int i = 0; i < hatSayisi; i++) {
                std::cout << "Hat No: " << hatlar[i].no << " - " << hatlar[i].ad << " [";
                for (int j = 0; j < hatlar[i].durakSayisi; j++) {
                    std::cout << hatlar[i].duraklar[j];
                    if (j != hatlar[i].durakSayisi - 1) std::cout << ", ";
                }
                std::cout << "]\n";
            }
        }
          //seçimde kullanıcidan girdi almak için
        else if (secim == 2) {
            int baslangicID, hedefID;
            std::cout << "Başlangic Durak ID girin: ";
            std::cin >> baslangicID;

            std::cout << "Hedef Durak ID girin: ";
            std::cin >> hedefID;

            if (baslangicID < 1 || hedefID < 1 || baslangicID > durakSayisi || hedefID > durakSayisi) {
                std::cout << "Gecersiz ID girdiniz!\n";
            } else {
                int uzaklik[200], onceki[200];
                graph.dijkstra(baslangicID - 1, uzaklik, onceki);
                int hedef = hedefID - 1;

                std::cout << "\nToplam Mesafe: " << uzaklik[hedef] << " m\n";
                std::cout << "Guzergah: ";

                int yol[200], index = 0, temp = hedef;
                while (temp != -1) {
                    yol[index++] = temp;
                    temp = onceki[temp];
                }

                for (int i = index - 1; i >= 0; i--) {
                    std::cout << duraklar[yol[i]].ad;
                    if (i != 0) std::cout << " -> ";
                }
                std::cout << "\n";
            }
        }

        else if (secim == 3) {
            int durakID;
            std::cout << "Durak ID girin: ";
            std::cin >> durakID;

            Durak* d = agac.ara(durakID);
            if (d) {
                std::cout << "Durak: " << d->id << " - " << d->ad << "\n";
                std::cout << "Ait Oldugu Hatlar:\n";
                for (int i = 0; i < hatSayisi; i++) {
                    for (int j = 0; j < hatlar[i].durakSayisi; j++) {
                        if (strcmp(hatlar[i].duraklar[j], d->ad) == 0) {
                            std::cout << " - Hat " << hatlar[i].no << ": " << hatlar[i].ad << "\n";
                            break;
                        }
                    }
                }
            } else {
                std::cout << "Durak bulunamadi.\n";
            }
        }

        

    } while (secim != 4);

    return 0;
}