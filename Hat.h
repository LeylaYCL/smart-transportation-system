#ifndef HAT_H
#define HAT_H
//durak mesafelerini hesaplamak için matris kullandım
class Hat {
public:
    int no;
    char ad[50];
    char duraklar[30][50]; 
    int durakSayisi;

    Hat();
};

#endif