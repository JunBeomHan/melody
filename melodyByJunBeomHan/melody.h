#ifndef MELODY_H
# define MELODY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


#define MAC_OS 1
#define UBUNTU_OS 2

#define DO        1
#define RE        2
#define MI        3
#define FA        4
#define SOL       5
#define LA        6
#define SI        7
#define DO_OCTAVE 8


void initMelody(const unsigned char OS);
void playMelody(const unsigned short melody);
void melodyCue(const unsigned short melody);
char* getMelodyName(unsigned short melody);

unsigned char my_os;

/**
 * C언어를 사용하여 터미널에서 입력을 처리하기 위해 termios 라이브러리를 사용합니다.
 * termios 라이브러리는 POSIX 시스템에서 터미널 인터페이스를 제어하기 위해 사용되는 라이브러리입니다.
 * 
 * 함수 initTermios는 터미널의 속성을 초기화하는 함수입니다. 인자로 전달된 echo 변수는 입력값을 터미널에 출력할 지 여부를 결정합니다.
 * 
 * struct termios new_termios; 이 변수는 터미널의 속성을 담게 됩니다.
 * 
 * 
 * tcgetattr(0, &new_termios); 그리고 tcgetattr 함수를 사용하여 현재 터미널의 속성을 가져와서 new_termios 변수에 저장합니다.
 * tcgetattr(terminal get attributes)
 * 
 * new_termios.c_lflag &= ~ICANON; new_termios 변수의 c_lflag 필드에서 ICANON 비트를 끄는 작업을 합니다. 이는 터미널을 raw mode로 설정하여 입력한 문자열을 즉시 처리하도록 합니다.
 * 
 * new_termios.c_lflag &= echo ? ECHO : ~ECHO; echo가 참일 경우 new_termios 변수의 c_lflag 필드에서 ECHO 비트를 켜고, 거짓일 경우 ECHO 비트를 끕니다. ECHO 비트가 켜져 있으면 입력한 문자열이 터미널에 출력되도록 합니다.
 * 
 * tcsetattr(0, TCSANOW, &new_termios); 마지막으로 tcsetattr 함수를 사용하여 터미널의 속성을 변경한 후에는 프로그램이 종료될 때 원래의 속성으로 복구되도록 구현해야 합니다.
 * tcsetattr(Terminal Control Set Attribute)
 * 
*/
void initMelody(const unsigned char OS) {
    my_os = OS;
    
}

void playMelody(const unsigned short melody) {
    switch(melody) {
        case DO:
            melodyCue(DO);
            break;
        
        case RE:
            melodyCue(RE);
            break;

        case MI:
            melodyCue(MI);
            break;
        
        case FA:
            melodyCue(FA);
            break;

        case SOL:
            melodyCue(SOL);
            break;


        case LA:
            melodyCue(LA);
            break;

        case SI:
            melodyCue(SI);
            break;

        case DO_OCTAVE:
            melodyCue(DO_OCTAVE);
            break;

    }
}

void melodyCue(const unsigned short melody) {
    char command[30] = {0, };



    if(my_os == MAC_OS) {
        sprintf(command, "afplay ./melody/melodys/%s.wav", getMelodyName(melody));
    } else if(my_os == UBUNTU_OS) {
        sprintf(command, "aplay ./melody/melodys/%s.wav", getMelodyName(melody));
    } else {
        printf("Unknow my_os: %d melody: %s\n", my_os, getMelodyName(melody));
        return;
    }

    system(command);
}

char* getMelodyName(unsigned short melody) {
    switch(melody) {
        case DO:
            return "DO";

        case RE:
            return "RE";

        case MI:
            return "MI";

        case FA:
            return "FA";

        case SOL:
            return "SOL";

        case LA:
            return "LA";

        case SI:
            return "SI";

        case DO_OCTAVE:
            return "DO_OCTAVE";
    }
    return NULL;
}


#endif /*MELODY_H*/