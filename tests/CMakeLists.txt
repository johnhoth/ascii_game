# tests/CMakeLists.txt

# Добавляем исполняемый файл для теста Renderer
add_executable(test_renderer test_renderer.cpp)

# Указываем директории с заголовочными файлами
target_include_directories(test_renderer PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Связываем тест с библиотекой основного проекта
target_link_libraries(test_renderer
    ${PROJECT_NAME}_lib
)

# Регистрация теста
add_test(NAME TestRenderer COMMAND test_renderer)
