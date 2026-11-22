find_package(SDL3 CONFIG REQUIRED)

add_library(ParafusersEngine STATIC
    src/core/Log.cpp
    src/core/Application.cpp
    src/platform/Window.cpp
)
add_library(Parafusers::Engine ALIAS ParafusersEngine)

target_include_directories(ParafusersEngine PUBLIC include)
target_link_libraries(ParafusersEngine PUBLIC SDL3::SDL3)
target_compile_definitions(ParafusersEngine PUBLIC
    PARAFUSERS_VERSION_STRING="${PROJECT_VERSION}"
    $<$<CONFIG:Debug>:PARAFUSERS_DEBUG>
)
parafusers_set_warnings(ParafusersEngine)
