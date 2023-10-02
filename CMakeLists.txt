cmake_minimum_required(VERSION 3.25.2)
project(Hello_World VERSION 0.1.0 LANGUAGES C CXX)

#включает поддержку системы непрерывной интеграции CTest, 
#которая позволяет автоматизировать процесс сборки и тестирования вашего проекта
include(CTest)
enable_testing()

# добавление директори с include файлами
include_directories(H:/boost_1_83_0 ${PROJECT_SOURCE_DIR})
# добавление директори с библиотеками
link_directories(${PROJECT_SOURCE_DIR}/build H:/boost_1_83_0/stage/lib)

#скомпилировать и добавить в проект библиотеку из исходников
#add_library(applib foo.cpp)
#скомпилировать динамическую библиотеку
add_library(sharedlib SHARED  sharedlib.cpp)
#//Линковка программы main с библиотеками
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
