# Parafusers Engine

Engine de jogos 2D e 3D em C++20, só Windows. Converse com o dono do projeto em português.

- Arquitetura e roadmap: docs/ARQUITETURA.md
- Build oficial: presets `windows-debug` e `windows-release` (MSVC + vcpkg). A CI compila os dois no windows-latest.
- Fora do Windows dá para checar a compilação com GCC ou Clang passando `-DCMAKE_PREFIX_PATH` para uma SDL3 instalada.
- Siga as convenções de código de docs/ARQUITETURA.md e o .clang-format.
