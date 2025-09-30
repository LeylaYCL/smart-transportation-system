#ifndef DURAK_H
#define DURAK_H
//burda da hem durak id si hemde ad uzunluğu ile dizi oluşturuldu
class Durak {
public:
    int id;
    char ad[50];

    Durak();
    Durak(int id, const char* ad);
};

#endif