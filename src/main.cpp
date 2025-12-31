#include <iostream>
#include <vector>
#include "task.h"

const std::string DATA_FILE = "data/tasks.txt";

int main(int argc, char* argv[]) {
    auto tasks = loadTasks(DATA_FILE);

    if (argc < 2) {
        std::cout << "Uso:\n";
        std::cout << "  ./todo add \"descrição\"\n";
        std::cout << "  ./todo list\n";
        std::cout << "  ./todo done <id>\n";
        return 0;
    }

    std::string command = argv[1];

    if (command == "add" && argc >= 3) {
        addTask(tasks, argv[2]);
        saveTasks(tasks, DATA_FILE);
        std::cout << "Tarefa adicionada.\n";
    }
    else if (command == "list") {
        listTasks(tasks);
    }
    else if (command == "done" && argc >= 3) {
        int id = std::stoi(argv[2]);
        completeTask(tasks, id);
        saveTasks(tasks, DATA_FILE);
    }
    else {
        std::cout << "Comando inválido.\n";
    }

    return 0;
}
