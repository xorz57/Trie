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

#include "Trie.hpp"

#include <iostream>

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
