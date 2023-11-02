# Trie

Trie written in C++14

## Example

```cpp
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
```

## How to Build using CMake

```bash
cmake -B build
cmake --build build --config Release
ctest -C Release
```
