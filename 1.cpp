#include <unordered_map>
#include <map>
#include <iostream>

int main() {
    std::string id, loc;
    int t;

    std::unordered_map<std::string, std::map<int, std::string>> objects {};

    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> id >> loc >> t;
        objects[id][t] = loc;
    }

    std::cin >> N;
    std::string command, name;
    for (int i = 0; i < N; i++){
        std::cin >> command >> name >> t;
        if (command == "object") {
            auto found_iter = objects.find(name);
            if (found_iter == objects.end()) {
                std::cout << "no data" << std::endl;
                continue;
            }
            auto& time_to_locs = found_iter->second;
            auto time = -1;
            for (const auto& time_to_loc : time_to_locs) {
                if (time_to_loc.first <= t){
                    time = time_to_loc.first;
                    loc = time_to_loc.second;
                } else{
                    break;
                }
            }
            if (time == -1) {
                std::cout << "no data" << std::endl;
                continue;
            } else {
                std::cout << loc << std::endl;
            }
        }

    }


}
