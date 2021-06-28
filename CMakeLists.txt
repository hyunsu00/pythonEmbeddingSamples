# CMakeList.txt
cmake_minimum_required (VERSION 2.8)

#
# 프로젝트 이름 지정
project ("pythonEmbeddingSamples")
message(STATUS "\${PROJECT_NAME} = ${PROJECT_NAME}")

option(BUILD_PYTHON_EMBEDDING_SAMPLE01 "Enable building pythonEmbeddingSample01" ON)
option(BUILD_PYTHON_EMBEDDING_SAMPLE02 "Enable building pythonEmbeddingSample02" ON)
option(BUILD_PYTHON_EMBEDDING_SAMPLE03 "Enable building pythonEmbeddingSample03" ON)

if(BUILD_PYTHON_EMBEDDING_SAMPLE01)
    add_subdirectory(pythonEmbeddingSample01)
endif()
if(BUILD_PYTHON_EMBEDDING_SAMPLE02)
    add_subdirectory(pythonEmbeddingSample02)
endif()
if(BUILD_PYTHON_EMBEDDING_SAMPLE03)
    add_subdirectory(pythonEmbeddingSample03)
endif()

set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
install(FILES ${CPACK_RESOURCE_FILE_README} DESTINATION .)
