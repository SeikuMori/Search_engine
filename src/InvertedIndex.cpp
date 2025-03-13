// InvertedIndex.cpp
#include "InvertedIndex.h"
#include <sstream>
#include <thread>
#include <mutex>

void InvertedIndex::UpdateDocumentBase(const std::vector<std::string>& input_docs) {
    docs = input_docs;
    freq_dictionary.clear();

    std::mutex mtx;
    std::vector<std::thread> threads;

    for (size_t doc_id = 0; doc_id < docs.size(); ++doc_id) {
        threads.emplace_back([this, doc_id, &mtx]() {
            std::map<std::string, size_t> word_count;
            std::istringstream stream(docs[doc_id]);
            std::string word;
            while (stream >> word) {
                ++word_count[word];
            }
            // Обновляем общий словарь с синхронизацией
            std::lock_guard<std::mutex> lock(mtx);
            for (const auto& [word, count] : word_count) {
                freq_dictionary[word].push_back({doc_id, count});
            }
        });
    }

    for (auto& t : threads) {
        t.join();
    }
}

