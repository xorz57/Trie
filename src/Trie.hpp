#include <memory>
#include <string>
#include <unordered_map>

template<typename T>
class Trie {
private:
    std::unordered_map<T, std::shared_ptr<Trie>> children;
    bool isEndOfWord = false;

public:
    Trie() = default;

    void Insert(const std::basic_string<T> &word) {
        Trie *current = this;
        for (T character: word) {
            if (current->children.find(character) == current->children.end()) {
                current->children[character] = std::make_shared<Trie>();
            }
            current = current->children[character].get();
        }
        current->isEndOfWord = true;
    }

    bool Search(const std::basic_string<T> &word) {
        Trie *current = this;
        for (T character: word) {
            if (current->children.find(character) == current->children.end()) {
                return false;
            }
            current = current->children[character].get();
        }
        return current->isEndOfWord;
    }

    bool StartsWith(const std::basic_string<T> &prefix) {
        Trie *current = this;
        for (T character: prefix) {
            if (current->children.find(character) == current->children.end()) {
                return false;
            }
            current = current->children[character].get();
        }
        return true;
    }
};
