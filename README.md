# Trie

[![Build](https://github.com/xorz57/Trie/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/Trie/actions/workflows/Build.yml)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=xorz57_Trie)

## Example

```cpp
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
```

## How to Build

#### Linux & macOS

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh

git clone https://github.com/xorz57/Trie.git
cd Trie
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```

#### Windows

```powershell
git clone https://github.com/microsoft/vcpkg.git C:/vcpkg
C:/vcpkg/bootstrap-vcpkg.bat
C:/vcpkg/vcpkg.exe integrate install

git clone https://github.com/xorz57/Trie.git
cd Trie
cmake -B build -DCMAKE_BUILD_TYPE=Release -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build --config Release
ctest --build-config Release
```
