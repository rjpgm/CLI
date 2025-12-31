#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

struct Task {
    int id;
    std::string description;
    bool completed;
};

// Funções
std::vector<Task> loadTasks(const std::string& filename);
void saveTasks(const std::vector<Task>& tasks, const std::string& filename);
void listTasks(const std::vector<Task>& tasks);
void addTask(std::vector<Task>& tasks, const std::string& description);
void completeTask(std::vector<Task>& tasks, int id);

#endif
