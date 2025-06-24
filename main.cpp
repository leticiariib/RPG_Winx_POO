#include "hub.h"
#include <iostream>

// Para permitir acentos no terminal 
#ifdef _WIN32
#include <windows.h>
#endif
void configurarTerminal() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

int main(){
    configurarTerminal();
    iniciarHubDoJogo();
    return 0; 
}