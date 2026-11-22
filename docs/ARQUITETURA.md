# Arquitetura (resumo)

O documento completo, com diagramas e justificativas, está em [Parafusers Engine: arquitetura e roadmap](https://claude.ai/artifact/6qhYHG6HxwNNWwL8FaY6G8).

## Decisões

| Tema | Escolha |
| --- | --- |
| Plataforma | Só Windows |
| Tipo de jogo | 3D e 2D |
| Núcleo | C++20, CMake, vcpkg |
| API gráfica | RHI própria, backend Vulkan 1.3, shaders em Slang |
| Script | Luau com hot reload |
| Cena | Árvore de nós (`Node2D` e `Node3D`) sobre ECS (EnTT) |
| Editor | Dear ImGui com docking, no mesmo processo do jogo |
| Física | Jolt (3D) e Box2D (2D) |
| Áudio | miniaudio |
| Janela e input | SDL3 |

## Camadas

De cima para baixo, cada camada só chama a de baixo:

1. Aplicação: editor e jogos
2. Script: Luau, bindings por reflexão, sinais
3. Cena: nós, ECS, serialização, assets
4. Sistemas: render graph, física, áudio, animação
5. RHI: Vulkan
6. Core: memória, jobs, matemática, log, plataforma

## Roadmap do MVP

| Fase | Conteúdo | Portão |
| --- | --- | --- |
| 0. Fundação | Build, janela, input, log, job system, RHI mínima | Cubo texturizado na tela com hot reload de shader |
| 1. Renderer base | Render graph, PBR, glTF, sombras, tonemapping | Sponza a 60 fps numa GPU intermediária |
| 2. Cena e script | Nós sobre EnTT, cenas em texto, Luau | Jogo pequeno feito só em script |
| 3. Editor MVP | Viewport, hierarquia, inspetor, Play/Stop, desfazer | Montar uma fase sem abrir C++ |
| 4. Jogo completo | Física, áudio, animação, 2D, exportação | Dois vertical slices, um 3D e um 2D |
| 5. Gráficos avançados | IBL, TAA, GI, meshlets | Contínuo |

## Convenções de código

- Namespace `pf`, classes em `PascalCase`, funções em `camelCase`, membros com prefixo `m_`
- Sem exceções no caminho crítico (só na inicialização)
- RAII e handles para recursos de GPU
- Formatação com `.clang-format`
