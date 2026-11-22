#pragma once

#include <format>
#include <string_view>

namespace pf {

enum class LogLevel { Trace, Info, Warn, Error };

namespace log {

void write(LogLevel level, std::string_view message);
void setMinimumLevel(LogLevel level);

template <typename... Args>
void trace(std::format_string<Args...> fmt, Args&&... args) {
    write(LogLevel::Trace, std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void info(std::format_string<Args...> fmt, Args&&... args) {
    write(LogLevel::Info, std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void warn(std::format_string<Args...> fmt, Args&&... args) {
    write(LogLevel::Warn, std::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void error(std::format_string<Args...> fmt, Args&&... args) {
    write(LogLevel::Error, std::format(fmt, std::forward<Args>(args)...));
}

} // namespace log
} // namespace pf
