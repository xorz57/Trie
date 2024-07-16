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
class trie_t {
public:
    trie_t() = default;

    void insert(const std::basic_string<T> &word) {
        trie_t *current = this;
        for (T character: word) {
            if (current->m_children.find(character) == current->m_children.end()) {
                current->m_children[character] = std::make_shared<trie_t>();
            }
            current = current->m_children[character].get();
        }
        current->m_is_end_of_word = true;
    }

    bool search(const std::basic_string<T> &word) {
        trie_t *current = this;
        for (T character: word) {
            if (current->m_children.find(character) == current->m_children.end()) {
                return false;
            }
            current = current->m_children[character].get();
        }
        return current->m_is_end_of_word;
    }

    bool starts_with(const std::basic_string<T> &prefix) {
        trie_t *current = this;
        for (T character: prefix) {
            if (current->m_children.find(character) == current->m_children.end()) {
                return false;
            }
            current = current->m_children[character].get();
        }
        return true;
    }

private:
    std::unordered_map<T, std::shared_ptr<trie_t>> m_children;
    bool m_is_end_of_word = false;
};
