#include "parafusers/platform/Window.h"

#include "parafusers/core/Log.h"

#include <SDL3/SDL.h>

#include <stdexcept>

namespace pf {

Window::Window(const WindowDesc& desc) : m_width(desc.width), m_height(desc.height) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error(std::string("Falha ao iniciar SDL: ") + SDL_GetError());
    }

    SDL_WindowFlags flags = SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    if (desc.resizable) {
        flags |= SDL_WINDOW_RESIZABLE;
    }

    m_window = SDL_CreateWindow(desc.title.c_str(), static_cast<int>(desc.width),
                                static_cast<int>(desc.height), flags);
    if (m_window == nullptr) {
        const std::string message = std::string("Falha ao criar janela: ") + SDL_GetError();
        SDL_Quit();
        throw std::runtime_error(message);
    }

    log::info("Janela criada: {}x{}", m_width, m_height);
}

Window::~Window() {
    if (m_window != nullptr) {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

bool Window::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            return false;
        case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
            m_width = static_cast<u32>(event.window.data1);
            m_height = static_cast<u32>(event.window.data2);
            log::trace("Janela redimensionada: {}x{}", m_width, m_height);
            break;
        default:
            break;
        }
    }
    return true;
}

} // namespace pf
