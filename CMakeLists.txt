cmake_minimum_required(VERSION 3.10) # Spécifiez la version minimale de CMake

# Nommez votre projet et spécifiez le langage utilisé
project(MonProjet VERSION 1.0 LANGUAGES CXX)

# Spécifiez la version standard du C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Ajoutez des sous-répertoires si nécessaire
# add_subdirectory(src)

# Définissez les fichiers source
add_executable(Z80_emu Z80.cpp)

# Trouvez des bibliothèques et liez-les si nécessaire
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(MonProjet PRIVATE SomeLibrary)
