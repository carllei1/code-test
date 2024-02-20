//  file_reader.h

#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <vector>

class FileReader {
public:

    // Reads the instructions from a file at the given file path and returns them as a vector of strings.
    std::vector<std::string> read_file(const std::string &file_path);

};

#endif /* FILE_READER_H */
