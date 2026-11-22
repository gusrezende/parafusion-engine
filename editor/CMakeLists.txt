# O editor entra na Fase 3. Por enquanto é só um executável que abre uma janela.
add_executable(ParafusersEditor main.cpp)
target_link_libraries(ParafusersEditor PRIVATE Parafusers::Engine)
parafusers_set_warnings(ParafusersEditor)
