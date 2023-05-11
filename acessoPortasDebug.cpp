#include <iostream>
#include <windows.h>

//Você deve verificar qual a porta do seu PC está disponivel e substituir no código

int main() {
    HANDLE hLpt1;
    DWORD dwBytesWritten;

    // Abre a porta COM1
    hLpt1 = CreateFile("COM1", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hLpt1 == INVALID_HANDLE_VALUE) {
        std::cout << "Erro ao abrir a porta COM1.\n";
        return 1;
    }

    // Escreve dados na porta paralela
    char data[] = "Hello, world!";
    if (!WriteFile(hLpt1, data, sizeof(data), &dwBytesWritten, NULL)) {
        std::cout << "Erro ao escrever na porta COM1.\n";
        CloseHandle(hLpt1);
        return 1;
    }else{
    	std::cout << data;
	}

    // Fecha a porta COM1
    CloseHandle(hLpt1);

    return 0;
}
 







