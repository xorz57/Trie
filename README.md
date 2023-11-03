<h1 align="center">Trie</h1>

<div align="center">
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_Trie">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=alert_status" alt="Quality Gate Status">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_Trie">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=bugs" alt="Bugs">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_Trie">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=vulnerabilities" alt="Vulnerabilities">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_Trie">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=code_smells" alt="Code Smells">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_Trie">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=coverage" alt="Coverage">
    </a>
    <a href="https://sonarcloud.io/summary/new_code?id=xorz57_Trie">
        <img src="https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=duplicated_lines_density" alt="Duplicated Lines (%)">
    </a>
</div>

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
