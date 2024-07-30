cmake_minimum_required(VERSION 3.26)

project(test)

# Find ceedling
find_program(CEEDLING_COMMAND ceedling)

if(NOT CEEDLING_COMMAND)
    # Ceedling not found
    message(STATUS "Ceedling not found. Attempting to install...")
    
    # Install ceedling
    execute_process(COMMAND gem install ceedling
                    RESULT_VARIABLE CEEDLING_INSTALL_RESULT
                    OUTPUT_VARIABLE CEEDLING_INSTALL_OUTPUT
                    ERROR_VARIABLE CEEDLING_INSTALL_ERROR)
    
    # Check if installation was successful
    if(CEEDLING_INSTALL_RESULT EQUAL 0)
        message(STATUS "Ceedling installed successfully.")
    else()
        message(FATAL_ERROR "Failed to install Ceedling: ${CEEDLING_INSTALL_ERROR}")
    endif()
else()
    # Get Ruby executable
    find_program(RUBY_EXECUTABLE NAMES ruby)

    if(NOT RUBY_EXECUTABLE)
        message(FATAL_ERROR "Ruby executable not found.")
    endif()

    # Build full ceedling command
    set(CEEDLING_FULL_COMMAND "${RUBY_EXECUTABLE}" "${CEEDLING_COMMAND}")

    # Get Ceedling version
    execute_process(COMMAND ${CEEDLING_FULL_COMMAND} version
                    RESULT_VARIABLE CEEDLING_VERSION_RESULT
                    OUTPUT_VARIABLE CEEDLING_VERSION_OUTPUT
                    ERROR_VARIABLE CEEDLING_VERSION_ERROR)

    if(CEEDLING_VERSION_RESULT EQUAL 0)
        message(STATUS "Found Ceedling: ${CEEDLING_VERSION_OUTPUT}")
    else()
        message(FATAL_ERROR "Failed to get Ceedling version: ${CEEDLING_VERSION_ERROR}")
    endif()
endif()

# ceedling clean
add_custom_target(test-clean
    COMMAND ceedling clobber
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_SOURCE_DIR}/test/test.map
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_SOURCE_DIR}/test/build
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test
    COMMENT "Removing all build artifacts"
)

# ceedling test:all
add_custom_target(test-all
    COMMAND ceedling test:all
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test
    COMMENT "Running all unit tests"
)

# ceedling gcov:all
add_custom_target(test-coverage-report-html
    COMMAND ceedling gcov:all
    COMMAND gcovr -r ${CMAKE_CURRENT_SOURCE_DIR} --html --html-details -o ${CMAKE_CURRENT_SOURCE_DIR}/build/artifacts/gcov/index.html
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/test
    COMMENT "Generating HTML coverage report"
)