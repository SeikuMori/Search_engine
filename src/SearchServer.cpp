#include "SearchServer.h"
#include <map>
#include <algorithm>
#include <sstream>

SearchServer::SearchServer(InvertedIndex& idx) : _index(idx) {}

std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& queries_input) {
    std::vector<std::vector<RelativeIndex>> result;
    for (const auto& query : queries_input) {
        std::map<size_t, float> doc_relevance;
        std::istringstream stream(query);
        std::string word;
        while (stream >> word) {
            auto word_count = _index.GetWordCount(word);
            for (const auto& entry : word_count) {
                doc_relevance[entry.doc_id] += entry.count;
            }
        }

        std::vector<RelativeIndex> ranked_docs;
        float max_relevance = 0.0f;
        for (const auto& [doc_id, relevance] : doc_relevance) {
            max_relevance = std::max(max_relevance, relevance);
        }
        for (const auto& [doc_id, relevance] : doc_relevance) {
            ranked_docs.push_back({doc_id, relevance / max_relevance});
        }

        std::sort(ranked_docs.begin(), ranked_docs.end(), [](const RelativeIndex& a, const RelativeIndex& b) {
            return b.rank < a.rank;
        });
        result.push_back(ranked_docs);
    }
    return result;
}

bool RelativeIndex::operator==(const RelativeIndex& other) const {
    return doc_id == other.doc_id && rank == other.rank;
}
