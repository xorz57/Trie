# Trie

[![Build](https://github.com/xorz57/Trie/actions/workflows/Build.yml/badge.svg)](https://github.com/xorz57/Trie/actions/workflows/Build.yml)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=xorz57_Trie&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=xorz57_Trie)

## Example

```cpp
#include "Trie/Trie.hpp"

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
