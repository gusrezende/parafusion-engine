#include "parafusers/core/Log.h"

#include <atomic>
#include <chrono>
#include <cstdio>
#include <mutex>

namespace pf::log {

namespace {

std::atomic<LogLevel> g_minimumLevel{LogLevel::Trace};
std::mutex g_mutex;

const char* levelName(LogLevel level) {
    switch (level) {
    case LogLevel::Trace: return "TRACE";
    case LogLevel::Info: return "INFO ";
    case LogLevel::Warn: return "WARN ";
    case LogLevel::Error: return "ERRO ";
    }
    return "?????";
}

} // namespace

void setMinimumLevel(LogLevel level) {
    g_minimumLevel.store(level);
}

void write(LogLevel level, std::string_view message) {
    if (level < g_minimumLevel.load()) {
        return;
    }

    using namespace std::chrono;
    const auto now = floor<milliseconds>(system_clock::now());
    const std::string line = std::format("[{:%H:%M:%S}] [{}] {}\n", now, levelName(level), message);

    std::lock_guard lock(g_mutex);
    std::FILE* out = level >= LogLevel::Warn ? stderr : stdout;
    std::fputs(line.c_str(), out);
    std::fflush(out);
}

} // namespace pf::log
