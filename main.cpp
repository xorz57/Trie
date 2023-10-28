#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

template <typename T>
class Trie {
private:
    std::unordered_map<T, std::shared_ptr<Trie>> children;
    bool isEndOfWord = false;

public:
    Trie() = default;

    void Insert(const std::basic_string<T>& word) {
        Trie* current = this;
        for (T character : word) {
            if (current->children.find(character) == current->children.end()) {
                current->children[character] = std::make_shared<Trie>();
            }
            current = current->children[character].get();
        }
        current->isEndOfWord = true;
    }

    bool Search(const std::basic_string<T>& word) {
        Trie* current = this;
        for (T character : word) {
            if (current->children.find(character) == current->children.end()) {
                return false;
            }
            current = current->children[character].get();
        }
        return current->isEndOfWord;
    }

    bool StartsWith(const std::basic_string<T>& prefix) {
        Trie* current = this;
        for (T character : prefix) {
            if (current->children.find(character) == current->children.end()) {
                return false;
            }
            current = current->children[character].get();
        }
        return true;
    }
};

int main() {
    Trie<char> trie;

    trie.Insert("apple");
    trie.Insert("app");

    std::cout << "Search 'apple': " << (trie.Search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'app': " << (trie.Search("app") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'ap': " << (trie.Search("ap") ? "Found" : "Not Found") << std::endl;
    std::cout << "StartsWith 'app': " << (trie.StartsWith("app") ? "Found" : "Not Found") << std::endl;
    std::cout << "StartsWith 'bat': " << (trie.StartsWith("bat") ? "Found" : "Not Found") << std::endl;

    return 0;
}
