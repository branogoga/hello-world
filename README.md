# C++ 23 Hello World Template

This repository provides a cross-platform starter template for C++ 23 with:

- CMake build configuration
- GTest unit tests
- vcpkg dependency management
- clang-format and clang-tidy
- VS Code integration
- Dev Container support
- GitHub Actions CI matrix for Linux, macOS, and Windows

## Quick start

### Prerequisities

**Windows**
- MSVC Build Tools 2026+
- [CMake 3.3.30+](https://cmake.org/download/)
```
cmake --version
```
- [Ninja build](https://github.com/ninja-build/ninja/releases)
```
ninja --version
```

### Local development

```bash
cmake --preset default
cmake --build --preset default
ctest --test-dir build/default --output-on-failure
```

### With a devcontainer

Open the repository in VS Code and choose "Reopen in Container".

### With vcpkg

Install vcpkg and point CMake at its toolchain file:

```bash
export VCPKG_ROOT=/path/to/vcpkg
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
```
