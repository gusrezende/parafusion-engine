// Sandbox: programa de testes da engine durante o desenvolvimento.
#include <parafusers/core/Application.h>
#include <parafusers/core/Log.h>

#include <SDL3/SDL_main.h>

#include <exception>

namespace {

class Sandbox final : public pf::Application {
public:
    Sandbox() : pf::Application({.window = {.title = "Parafusers Engine: Sandbox"}}) {}

protected:
    void onStart() override { pf::log::info("Sandbox iniciado. Feche a janela para sair."); }

    void onUpdate(pf::f32 deltaSeconds) override {
        m_elapsed += deltaSeconds;
        ++m_frames;
        if (m_elapsed >= 1.0f) {
            pf::log::trace("{} quadros por segundo", m_frames);
            m_elapsed = 0.0f;
            m_frames = 0;
        }
    }

private:
    pf::f32 m_elapsed = 0.0f;
    pf::u32 m_frames = 0;
};

} // namespace

int main(int, char**) {
    try {
        Sandbox app;
        return app.run();
    } catch (const std::exception& e) {
        pf::log::error("Erro fatal: {}", e.what());
        return 1;
    }
}
