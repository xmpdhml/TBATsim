include(CTest)

set(ut_build_target "${current_build_target}-UT")

file( GLOB interfacefiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h *.hpp )
file( GLOB srcfiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h *.hpp *.cpp *.c )

add_executable(${ut_build_target} ${srcfiles} ${interfacefiles})

target_link_libraries(
    ${ut_build_target}
	${current_build_target}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

source_group( "Source" FILES ${srcfiles} )
source_group( "Interface" FILES ${interfacefiles} )

add_test(NAME ${ut_build_target} COMMAND ${ut_build_target})

add_custom_command(TARGET ${ut_build_target}
                   POST_BUILD
                   COMMAND ${ut_build_target} -x false)
