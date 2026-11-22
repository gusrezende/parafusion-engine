#pragma once

#include "parafusers/core/Types.h"
#include "parafusers/platform/Window.h"

#include <memory>

namespace pf {

struct ApplicationDesc {
    WindowDesc window;
};

// Ponto de entrada de qualquer programa feito com a engine (jogo, sandbox ou editor).
// Subclasses sobrescrevem os ganchos; run() cuida do loop principal.
class Application {
public:
    explicit Application(const ApplicationDesc& desc);
    virtual ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;

    int run();
    void requestQuit() { m_running = false; }

protected:
    virtual void onStart() {}
    virtual void onUpdate(f32 deltaSeconds) { (void)deltaSeconds; }
    virtual void onShutdown() {}

    Window& window() { return *m_window; }

private:
    std::unique_ptr<Window> m_window;
    bool m_running = true;
};

} // namespace pf
