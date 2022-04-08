#include "CMorse.h"
#include <iostream>

using namespace std;

CMorse::CMorse()
{
    messageClair = NULL;
    messageCode = NULL;
    strcpy(tCorrespondance[0], ".-");
    strcpy(tCorrespondance[1], "-...");
    strcpy(tCorrespondance[2], "-.-.");
    strcpy(tCorrespondance[3], "-..");
    strcpy(tCorrespondance[4], ".");
    strcpy(tCorrespondance[5], "..-.");
    strcpy(tCorrespondance[6], "--.");
    strcpy(tCorrespondance[7], "....");
    strcpy(tCorrespondance[8], "..");
    strcpy(tCorrespondance[9], ".---");
    strcpy(tCorrespondance[10], "-.-");
    strcpy(tCorrespondance[11], ".-..");
    strcpy(tCorrespondance[12], "--");
    strcpy(tCorrespondance[13], "-.");
    strcpy(tCorrespondance[14], "---");
    strcpy(tCorrespondance[15], ".--.");
    strcpy(tCorrespondance[16], "--.-");
    strcpy(tCorrespondance[17], ".-.");
    strcpy(tCorrespondance[18], "...");
    strcpy(tCorrespondance[19], "-");
    strcpy(tCorrespondance[20], "..-");
    strcpy(tCorrespondance[21], "...-");
    strcpy(tCorrespondance[22], ".--");
    strcpy(tCorrespondance[23], "-..-");
    strcpy(tCorrespondance[24], "-.--");
    strcpy(tCorrespondance[25], "--..");
}

CMorse::~CMorse() {
}

char* CMorse::getMessageClair() {
    return messageClair;
}

char* CMorse::getMessageCode() {
    return messageCode;
}

void CMorse::setMessageClair(char* message) {
    messageClair = new char[256];
    strcpy(messageClair, message);
}

void CMorse::setMessageCode(char* message) {
    messageCode = new char[256];
    strcpy(messageCode, message);
}

bool CMorse::coderMorse() {
    messageCode = new char[256];
    strcpy(messageCode, " ");
    if (verifierMessageClair() == true) {
        for (short i=0; i<=strlen(messageClair)-1; i++) {
            if (messageClair[i] != ' ') {
                strcat(messageCode, tCorrespondance[messageClair[i] - 'a']);
            }
            else {
                strcat(messageCode, " ");
            }
            strcat(messageCode, " ");
        }
        return true;
    }
    messageCode = "";
    return false;
}

bool CMorse::verifierMessageClair() {
    bool retour = true, boucle = true;
    while (boucle == true) {
        for (short i=0; i<=strlen(messageClair)-1; i++) {
            if ((messageClair[i] >= 'a' && messageClair[i] <= 'z') || (messageClair[i] == ' ')) {
                retour = true;
            }
            else {
                retour = false;
                boucle = false;
            }
        }
        boucle = false;
    }
    return retour;
}

bool CMorse::verifierMessageCode() {
    bool retour = true, boucle = true;
    while (boucle == true) {
        for (short i=0; i<=strlen(messageCode)-1; i++) {
            if ((messageCode[i] >= '.' && messageCode[i] <= '-') || (messageCode[i] == ' ')) {
                retour = true;
            }
            else {
                retour = false;
                boucle = false;
            }
        }
        boucle = false;
    }
    return retour;
}
