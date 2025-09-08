add_executable(repl repl.c)

target_compile_options(repl PRIVATE -fPIC)
target_link_libraries(repl PRIVATE sds tokens)
