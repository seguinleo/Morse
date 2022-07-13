#ifndef CMORSE_H
#define CMORSE_H
#include <string.h>

class CMorse {
private:
    char* messageClair;
    char* messageCode;
    char tCorrespondance [26] [5];
    bool verifierMessageClair();
    bool verifierMessageCode();
public:
    CMorse();
    ~CMorse();
    char* getMessageClair();
    char* getMessageCode();
    void setMessageClair(char* message);
    void setMessageCode(char* message);
    bool coderMorse();
    bool decoderMorse();
};

#endif // CMORSE_H
