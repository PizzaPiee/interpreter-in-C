add_executable(test_lexer test_lexer.c)
target_link_libraries(test_lexer unity sds lexer)
add_test(NAME test_lexer COMMAND test_lexer)
