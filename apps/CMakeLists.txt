add_executable(main main.c)

target_compile_options(main PRIVATE -fPIC)
target_link_libraries(main PRIVATE sds tokens)
