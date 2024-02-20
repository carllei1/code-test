#include "file_reader.h"

std::vector<std::string> FileReader::read_file(const std::string &file_path) {

    std::ifstream instruction_file;
    std::vector<std::string> instructions;

    instruction_file.open(file_path, std::ios::in);
    if (instruction_file.is_open()) {
        std::string instruction;
        while (getline(instruction_file, instruction)) {
            instructions.push_back(instruction);
        }
        instruction_file.close();
    }

    return instructions;
}
