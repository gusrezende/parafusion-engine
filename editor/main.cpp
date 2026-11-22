// Editor da Parafusers Engine. Os painéis (Dear ImGui) chegam na Fase 3.
#include <parafusers/core/Application.h>
#include <parafusers/core/Log.h>

#include <SDL3/SDL_main.h>

#include <exception>

int main(int, char**) {
    try {
        pf::Application editor({.window = {.title = "Parafusers Editor", .width = 1600, .height = 900}});
        return editor.run();
    } catch (const std::exception& e) {
        pf::log::error("Erro fatal: {}", e.what());
        return 1;
    }
}
