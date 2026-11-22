add_executable(Sandbox main.cpp)
target_link_libraries(Sandbox PRIVATE Parafusers::Engine)
parafusers_set_warnings(Sandbox)
