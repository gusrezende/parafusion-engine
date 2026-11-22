# Parafusers Engine

Engine de jogos 2D e 3D própria, escrita em C++20. A ideia é juntar a ambição gráfica da Unreal com a facilidade de uso da Godot: árvore de nós, cenas reutilizáveis, script leve com hot reload e um editor rápido.

Plano completo de arquitetura e roadmap: [Parafusers Engine: arquitetura e roadmap](https://claude.ai/artifact/6qhYHG6HxwNNWwL8FaY6G8). Resumo em [docs/ARQUITETURA.md](docs/ARQUITETURA.md).

## Estado atual

Fase 0 (Fundação), em andamento. Hoje a engine abre uma janela com SDL3, tem log e o loop principal. Ainda não desenha nada.

## Requisitos (Windows)

- Visual Studio 2022 com a carga de trabalho "Desenvolvimento para desktop com C++"
- CMake 3.25 ou mais novo e Ninja (ambos vêm com o Visual Studio)
- [vcpkg](https://github.com/microsoft/vcpkg), com a variável de ambiente `VCPKG_ROOT` apontando para ele
- [Vulkan SDK](https://vulkan.lunarg.com/) (necessário a partir do renderer)

## Como compilar

Abra o "Developer PowerShell for VS 2022" na pasta do projeto e rode:

```powershell
cmake --preset windows-debug
cmake --build --preset windows-debug
.\build\windows-debug\bin\Sandbox.exe
```

Na primeira configuração o vcpkg baixa e compila as dependências (SDL3), o que leva alguns minutos.

Também dá para abrir a pasta direto no Visual Studio 2022 ou no VS Code com a extensão CMake Tools: os presets aparecem sozinhos.

## Estrutura

| Pasta | Conteúdo |
| --- | --- |
| `engine/` | Biblioteca da engine. Cabeçalhos públicos em `engine/include/parafusers/` |
| `sandbox/` | Programa de testes usado durante o desenvolvimento |
| `editor/` | Editor (os painéis chegam na Fase 3) |
| `cmake/` | Funções auxiliares de CMake |
| `docs/` | Documentação |
