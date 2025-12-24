#include <iostream>
#include <vector>
#include "task.h"

int main(int argc, char* argv[]) {
    std::vector<Task> tasks;

    std::cout << "Todo CLI iniciado com sucesso!\n";
    std::cout << "Argumentos recebidos: " << argc - 1 << "\n";

    return 0;
}
