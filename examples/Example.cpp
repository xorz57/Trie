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

#include "Trie/Trie.hpp"

#include <iostream>

int main() {
    trie_t<char> trie;

    trie.insert("apple");
    trie.insert("app");

    if (trie.search("apple")) {
        std::cout << "Search 'apple': True" << std::endl;
    } else {
        std::cout << "Search 'apple': False" << std::endl;
    }

    if (trie.search("app")) {
        std::cout << "Search 'app': True" << std::endl;
    } else {
        std::cout << "Search 'app': False" << std::endl;
    }

    if (trie.search("ap")) {
        std::cout << "Search 'ap': True" << std::endl;
    } else {
        std::cout << "Search 'ap': False" << std::endl;
    }

    if (trie.starts_with("app")) {
        std::cout << "Starts with 'app': True" << std::endl;
    } else {
        std::cout << "Starts with 'app': False" << std::endl;
    }

    if (trie.starts_with("bat")) {
        std::cout << "Starts with 'bat': True" << std::endl;
    } else {
        std::cout << "Starts with 'bat': False" << std::endl;
    }

    return 0;
}
