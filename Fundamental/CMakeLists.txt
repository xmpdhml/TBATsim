project(Fundamental)

set(current_build_target "Fundamental")

file(GLOB header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h *.hpp)
file(GLOB source_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h src/*.hpp src/*.cpp src/*.c)

add_library(
    ${current_build_target} SHARED
    ${header_files} ${source_files} ${common_files}
)

target_link_libraries(
	${current_build_target}
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set_property(
    TARGET ${current_build_target}
    PROPERTY FOLDER "${current_build_target}"
)

source_group( "Source" FILES ${source_files} )
source_group( "Interface" FILES ${header_files} )

add_subdirectory(tests)
