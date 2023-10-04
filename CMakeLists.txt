cmake_minimum_required(VERSION 3.25.2)
project(Hello_World VERSION 0.1.0 LANGUAGES C CXX)

#включает поддержку системы непрерывной интеграции CTest, 
#которая позволяет автоматизировать процесс сборки и тестирования вашего проекта
include(CTest)
enable_testing()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
add_test(Test_0, "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}" "0")
add_test(Test_1, "${CMAKE_SOURCE_DIR}/build/${PROJECT_NAME}" "1")

# добавление директори с include файлами
include_directories(H:/boost_1_83_0 ${PROJECT_SOURCE_DIR})
# добавление директори с библиотеками
link_directories(${PROJECT_SOURCE_DIR}/build H:/boost_1_83_0/stage/lib)

#скомпилировать и добавить в проект библиотеку из исходников
#add_library(applib foo.cpp)
#скомпилировать динамическую библиотеку
add_library(sharedlib SHARED  sharedlib.cpp)
#add_library(hello_static STATIC ${LIBHELLO_SRC}) линковка статической библиотеки
#//Линковка программы main с библиотеками sharedlib и libboost_chrono-mgw13-mt-x64-1_83.a
link_libraries(sharedlib libboost_chrono-mgw13-mt-x64-1_83.a) 


#target_link_options()
#target_precompile_headers()

add_executable(Hello_World main.cpp foo.cpp)

#установка флагов компиляции
set(CMAKE_CXX_FLAGS  "-Wall -g")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#включает поддержку системы управления пакетами CPack. 
#CPack позволяет создавать пакеты вашего проекта для различных операционных систем и платформ.
include(CPack)

#Вывод сообщений при иницилизации сборки
#SET(HELLO_FOUND true)
#if(HELLO_FOUND)
#    message("HELLO library  found")
#else(HELLO_FOUND)
#    message(FATAL_ERROR "HELLO library not found")
#endif(HELLO_FOUND)

#добавление подпапки
#add_subdirectory(src)