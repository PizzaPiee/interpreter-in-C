add_library(tokens tokens.c)
target_include_directories(tokens PUBLIC ../include/)

add_library(lexer lexer.c)
target_include_directories(lexer PUBLIC ../include/)
target_link_libraries(lexer PRIVATE tokens)
