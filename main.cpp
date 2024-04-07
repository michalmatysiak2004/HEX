#include <stdio.h>
#include <iostream>
#define MAX_SIZE 121
using namespace std;

struct arguments {
    int size=0;
    int pawns=0;
    int red=0;
    int blue=0;
    int command=0;
    bool pole=0;
    char helptab[MAX_SIZE];
    bool ispoleempty=0;
    int counter=0;
    int lines=0;
};

void printresult(int x, struct arguments* a) {
    switch (x) {
        case 1:

            a->size = (a->lines-1)/2;
            cout << a->size << endl;
            break;
        case 2:
            cout << a->pawns << endl;
            break;
        case 3:
            if ((a->red - a->blue) >= 0 && (a->red - a->blue) <= 1) {
                cout << "YES" << endl;
            } else
                cout << "NO" << endl;
            break;
    }
}
void resetparameters(struct arguments* a){
    a->blue = 0;
    a->red = 0;
    a->counter = 0;
    a->ispoleempty = false;
    a->pawns = 0;
    a->lines= 0;
    a->size= 0 ;
}
void functionhandler(char token, struct arguments* a) {
    char ch;

    if (token == 'B') {
        cin >> ch;
        while (ch != 'E') {
            cin >> ch;
        }
        scanf("%c", &ch);
        printresult(1, a);
        resetparameters(a);
    }
    if (token == 'P') {
        cin >> ch;
        while (ch != 'R') {
            cin >> ch;
        }
        printresult(2, a);
        resetparameters(a);
    }
    if (token == 'I') {
        cin >> ch;
        while (ch != 'T') {
            cin >> ch;
        }
        printresult(3, a);
        resetparameters(a);
    }
}

int main() {
    char ch;
    arguments a;
    // Wczytywanie znaków z wejścia
    while (scanf("%c", &ch) == 1) {

        if (ch == '\n') {
            a.lines++;
        } else if (ch == '<')
            a.pole = true;
        else if (ch == '>' && a.ispoleempty == true) {

            a.counter++;
        } else if (ch == '>' && a.ispoleempty == false) {
            a.ispoleempty = true;
            a.pole = false;
        } else if (ch == 'b' || ch == 'r') {
            a.ispoleempty = false;
            a.pawns++;

            if (ch == 'b')
                a.blue++;
            if (ch == 'r')
                a.red++;
            a.counter++;
        } else if (ch == 'B' || ch == 'I' || ch == 'P'){

            functionhandler(ch, &a);
        } else {
        }

    }


    return 0;
}