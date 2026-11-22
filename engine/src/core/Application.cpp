#include "parafusers/core/Application.h"

#include "parafusers/core/Log.h"

#include <chrono>

namespace pf {

Application::Application(const ApplicationDesc& desc) {
    log::info("Parafusers Engine {}", PARAFUSERS_VERSION_STRING);
    m_window = std::make_unique<Window>(desc.window);
}

Application::~Application() = default;

int Application::run() {
    using Clock = std::chrono::steady_clock;

    onStart();

    auto previous = Clock::now();
    while (m_running) {
        if (!m_window->pollEvents()) {
            m_running = false;
            break;
        }

        const auto now = Clock::now();
        const f32 delta = std::chrono::duration<f32>(now - previous).count();
        previous = now;

        onUpdate(delta);
    }

    onShutdown();
    log::info("Encerrado");
    return 0;
}

} // namespace pf
