#include <bits/stdc++.h>

const std::string filename = "todolist.txt";

std::vector<std::string> loadTasks() {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> tasks;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            tasks.push_back(line);
        }
    }
    return tasks;
}

void saveTasks(const std::vector<std::string>& tasks) {
    std::ofstream file(filename);
    for (const auto& task : tasks) {
        file << task << "\n";
    }
}

int main() {            
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool status;
    std::cout << "Enter true(to run) or false(to exit): ";
    std::cin >> std::boolalpha >> status;
    std::cout << "Status: " << std::boolalpha << status << "\n";
    if (false == status) {
        std::cout << "Exiting the program.\n";
        return 0;
    }

    std::vector<std::string> lists = loadTasks(); // load existing tasks right away

    while (true) {
        std::cout << "\nChoose an option: add / view / remove / quit\n";
        std::string option;
        std::cin >> option;
        std::transform(option.begin(), option.end(), option.begin(), ::tolower);

        if (option == "quit") {
            return 0;
        }

        else if (option == "add") {
            std::cout << "Enter a task: ";
            std::string task;
            std::cin >> task;
            lists.push_back(task);
            saveTasks(lists); // save immediately after adding
            std::cout << "Task added: " << task << "\n";
        }

        else if (option == "view") {
            int taskCount = lists.size();
            std::cout << "Current tasks:\n";
            for (int i = 0; i < taskCount; i++) {
                std::cout << (i + 1) << ".)- " << lists[i] << "\n";
            }
            if (lists.empty()) {
                std::cout << "(No tasks yet)\n";
            }
        }

        else if (option == "remove") {
            std::cout << "Enter the task number to remove: ";
            int taskNumber;
            std::cin >> taskNumber;
            if (taskNumber > 0 && taskNumber <= lists.size()) {
                lists.erase(lists.begin() + taskNumber - 1);
                saveTasks(lists); // save immediately after removing
                std::cout << "Task removed.\n";
            } else {
                std::cout << "Invalid task number.\n";
            }
        }

        else {
            std::cout << "Invalid option. Please type add, view, remove, or quit.\n";
        }
    }

    return 0;
}