function(add_commuters_test test_name test_source)
    add_executable(${test_name} ${test_source} ${ARGN})

    target_link_libraries(${test_name} PRIVATE commuters_engine)

    add_test(NAME ${test_name} COMMAND ${test_name})
endfunction()

add_commuters_test(test_test0 test0.cpp)

