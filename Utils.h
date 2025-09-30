#ifndef UTILS_H
#define UTILS_H

#include "Durak.h"
#include "Hat.h"
#include "Yolcu.h"
//txt dosyalarını aldık
void duraklariOku(const char* dosya, Durak* duraklar, int& durakSayisi);
void hatlariOku(const char* dosya, Hat* hatlar, int& hatSayisi);
void yolculariOku(const char* dosya, Yolcu* yolcular, int& yolcuSayisi);
void mesafeleriOku(const char* dosya, int graph[200][200], int& boyut);

#endif