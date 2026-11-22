#pragma once

#include "parafusers/core/Types.h"

#include <string>

struct SDL_Window;

namespace pf {

struct WindowDesc {
    std::string title = "Parafusers Engine";
    u32 width = 1280;
    u32 height = 720;
    bool resizable = true;
};

// Janela do sistema operacional. Nesta fase cria a janela SDL3 com suporte a Vulkan,
// mas ainda não há renderer ligado a ela.
class Window {
public:
    explicit Window(const WindowDesc& desc);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    // Processa os eventos pendentes. Devolve false quando o usuário pediu para fechar.
    bool pollEvents();

    u32 width() const { return m_width; }
    u32 height() const { return m_height; }
    SDL_Window* nativeHandle() const { return m_window; }

private:
    SDL_Window* m_window = nullptr;
    u32 m_width = 0;
    u32 m_height = 0;
};

} // namespace pf
