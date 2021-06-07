#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

std::string get_name(std::string path, std::string path_and_name) {
    return path_and_name.substr(path.size() + 1);
}

std::vector<int> get_values(std::string name) {
    std::vector<int> values;
    int num = 0;
    bool flag = false; 

    for(size_t i = 0; i < name.size(); i++) {
        if(isdigit(name[i])) {
            num = 10 * num + name[i] - '0';
            flag = true;
        } else if(flag) {
            values.push_back(num);
            flag = false;
            num = 0;
        } else
            flag = false;
    }
    if(flag) values.push_back(num);
    return values;
}

std::string get_name(std::string s) {
    int sz = s.size();
    if(s.substr(sz - 4, 4) == ".cpp")
        s = s.substr(0, sz - 4);
    s[0] = toupper(s[0]);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '_') {
            s[i] = ' ';
            s[i + 1] = toupper(s[i + 1]);
        }
    }
    return s;
}

void process_directory(std::string path, std::string dir) {
    for (const auto & entry : fs::directory_iterator(path + dir)) {
        std::string name = get_name(path + dir, entry.path());
        std::string s = "- [x] [";
        s += get_name(name) + "](";
        s += "code/" + dir + "/" + name;
        s += ")";
        std::cout << s << "\n";
    }
    std::cout << std::endl;
}

int main() {
    std::string cur_path = fs::current_path();

    std::string path = cur_path + "/code";
    for (const auto & entry : fs::directory_iterator(path)) {
        std::string dir = get_name(path, entry.path());
        auto values = get_values(dir);
        std::cout << "**" << get_name(dir) << "**\n\n";
        process_directory(path + "/", dir);
        std::cout << std::endl;
    }
    return 0;
}