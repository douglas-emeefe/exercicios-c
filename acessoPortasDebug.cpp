#include <iostream>
#include <windows.h>

int main() {
    HANDLE hLpt1;
    DWORD dwBytesWritten;

    // Abre a porta LPT1
    hLpt1 = CreateFile("LPT1", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hLpt1 == INVALID_HANDLE_VALUE) {
        std::cout << "Erro ao abrir a porta LPT1.\n";
        return 1;
    }

    // Escreve dados na porta paralela
    char data[] = "Hello, world!";
    if (!WriteFile(hLpt1, data, sizeof(data), &dwBytesWritten, NULL)) {
        std::cout << "Erro ao escrever na porta LPT1.\n";
        CloseHandle(hLpt1);
        return 1;
    }

    // Fecha a porta LPT1
    CloseHandle(hLpt1);

    return 0;
}
 







