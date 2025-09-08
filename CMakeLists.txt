cmake_minimum_required(VERSION 3.15...4.0)

project(LearnC VERSION 1.0
		DESCRIPTION "Personal project used to learn C"
		LANGUAGES C)


#[[ Se the output directory for binaries ]]
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/bin")
	make_directory("${PROJECT_SOURCE_DIR}/bin")
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

#[[ Handle git submodules ]]
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/lib/sds/sds.h")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

add_library(sds lib/sds/sds.h lib/sds/sdsalloc.h lib/sds/sds.c)

add_executable(main main.c)
target_link_libraries(main PUBLIC sds)
