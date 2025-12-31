#include "task.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<Task> loadTasks(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);

    if (!file.is_open())
        return tasks;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Task task;
        std::string completedStr;

        std::getline(ss, line, '|');
        task.id = std::stoi(line);

        std::getline(ss, task.description, '|');
        std::getline(ss, completedStr);

        task.completed = (completedStr == "1");
        tasks.push_back(task);
    }

    return tasks;
}

void saveTasks(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);

    for (const auto& task : tasks) {
        file << task.id << "|"
             << task.description << "|"
             << (task.completed ? "1" : "0") << "\n";
    }
}

void listTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "Nenhuma tarefa encontrada.\n";
        return;
    }

    for (const auto& task : tasks) {
        std::cout << task.id << ". "
                  << (task.completed ? "[x] " : "[ ] ")
                  << task.description << "\n";
    }
}

void addTask(std::vector<Task>& tasks, const std::string& description) {
    int nextId = tasks.empty() ? 1 : tasks.back().id + 1;
    tasks.push_back({nextId, description, false});
}

void completeTask(std::vector<Task>& tasks, int id) {
    for (auto& task : tasks) {
        if (task.id == id) {
            task.completed = true;
            return;
        }
    }

    std::cout << "Tarefa com ID " << id << " não encontrada.\n";
}
