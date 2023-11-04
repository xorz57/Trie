/*
	MIT License

	Copyright(c) 2023 George Fotopoulos

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files(the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions :

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

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
