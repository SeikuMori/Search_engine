#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H

#include <vector>
#include <string>

class ConverterJSON {
public:
    std::vector<std::string> GetTextDocuments();
    std::vector<std::string> GetRequests();
    void putAnswers(const std::vector<std::vector<std::pair<int, float>>>& answers);
};

#endif 
