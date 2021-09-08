#include <string>
#include <vector>
#include <fstream>
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

void process_directory(std::string path, std::string dir, std::vector<std::string> &lines) {
    for (const auto & entry : fs::directory_iterator(path + dir)) {
        std::string name = get_name(path + dir, entry.path());
        std::string s = "- [x] [";
        s += get_name(name) + "](";
        s += "code/" + dir + "/" + name;
        s += ")";
        lines.push_back(s + "\n");
    }
    lines.push_back("\n");
}

int main() {
    std::string abs_path = fs::current_path();
    abs_path = abs_path.substr(0, abs_path.size() - 6);
    std::string path = abs_path + "/code";

    std::vector<std::string> lines;

    std::ifstream read_me_first_lines (abs_path + "/README.md");

    if(read_me_first_lines.is_open()) {
        int cnt = 0;
        while(read_me_first_lines.good() and cnt < 35) {
            lines.push_back("");
            getline(read_me_first_lines, lines.back());
            lines.back().push_back('\n');
            cnt++;
        }
        read_me_first_lines.close();
    }

    lines.push_back("\n## On the Contents\n\n");

    for(const auto & entry : fs::directory_iterator(path)) {
        std::string dir = get_name(path, entry.path());
        auto values = get_values(dir);
        lines.push_back( "**" + get_name(dir) + "**\n" );
        process_directory(path + "/", dir, lines);
        lines.push_back("\n");
    }
        
    std::ofstream readme(abs_path + "/README.md");

    if(readme.is_open()) {
        for(auto line : lines)
            readme << line;
        readme.close();
    }

    return 0;
}