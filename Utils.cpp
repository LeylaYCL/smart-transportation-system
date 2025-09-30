#include "Utils.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
//durak verilerini okuyup diziye eklemek için
void duraklariOku(const char* dosya, Durak* duraklar, int& durakSayisi) {
    FILE* f = fopen(dosya, "r");
    if (!f) return;

    char satir[100];
    fgets(satir, sizeof(satir), f); 

    durakSayisi = 0;
    while (fgets(satir, sizeof(satir), f)) {
        char* idStr = strtok(satir, ",");
        char* ad = strtok(NULL, "\n");
        if (idStr && ad) {
            duraklar[durakSayisi++] = Durak(atoi(idStr), ad);//durak nesnesini oluşturma içn
        }
    }

    fclose(f);
}

void hatlariOku(const char* dosya, Hat* hatlar, int& hatSayisi) {
    FILE* f = fopen(dosya, "r");
    if (!f) return;

    char satir[1024];
    fgets(satir, sizeof(satir), f); 

    hatSayisi = 0;
    while (fgets(satir, sizeof(satir), f)) {
        char* token = strtok(satir, ",");
        if (!token) continue;
        hatlar[hatSayisi].no = atoi(token);//hat numarası almak için

        token = strtok(NULL, ",");
        if (token) strcpy(hatlar[hatSayisi].ad, token);

        int i = 0;
        while ((token = strtok(NULL, ",\n")) != NULL) {
            strcpy(hatlar[hatSayisi].duraklar[i++], token);
        }
        hatlar[hatSayisi].durakSayisi = i;
        hatSayisi++;
    }

    fclose(f);
}
//yolcu bilgilerini okuyup diziye yüklemek için 
void yolculariOku(const char* dosya, Yolcu* yolcular, int& yolcuSayisi) {
    FILE* f = fopen(dosya, "r");
    if (!f) return;

    char satir[200];
    fgets(satir, sizeof(satir), f); 

    yolcuSayisi = 0;
    while (fgets(satir, sizeof(satir), f)) {
        char* idStr = strtok(satir, ",");
        char* adsoyad = strtok(NULL, ",");
        char* baslangicStr = strtok(NULL, ",");
        char* hedefStr = strtok(NULL, "\n");

        if (idStr && adsoyad && baslangicStr && hedefStr) {
            yolcular[yolcuSayisi].id = atoi(idStr);
            strcpy(yolcular[yolcuSayisi].adSoyad, adsoyad);
            yolcular[yolcuSayisi].baslangic = atoi(baslangicStr);
            yolcular[yolcuSayisi].hedef = atoi(hedefStr);
            yolcuSayisi++;
        }
    }

    fclose(f);
}
//duraklar arasındak mesafe matrisini okuyup matrise eklemek için
void mesafeleriOku(const char* dosya, int graph[200][200], int& boyut) {
    FILE* f = fopen(dosya, "r");
    if (!f) return;

    char satir[5000];
    int row = 0;

    while (fgets(satir, sizeof(satir), f)) {
        int col = 0;
        char* token = strtok(satir, ",\n");
        while (token != NULL) {
            if (strcmp(token, "-") == 0)
                graph[row][col] = -1;
            else
                graph[row][col] = atoi(token);

            token = strtok(NULL, ",\n");
            col++;
        }
        row++;
    }

    boyut = row;
    fclose(f);
}