#include "Durak.h"
#include <cstring>
//durak id lerini çekmek için kullanıldı
Durak::Durak() {
    id = -1;
    strcpy(ad, "");
}

Durak::Durak(int id, const char* adParam) {
    this->id = id;
    strcpy(ad, adParam);
}