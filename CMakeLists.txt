cmake_minimum_required(VERSION 3.10) # Spécifiez la version minimale de CMake

project(MonProjet VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Définir le répertoire de sortie pour les exécutables et les fichiers objets
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Récupérer automatiquement tous les fichiers .cpp dans le dossier src
file(GLOB SOURCES "src/*.cpp")

# Ajouter le répertoire src et le fichier Z80.cpp à l'exécutable
add_executable(Z80_emu Z80.cpp ${SOURCES})

# Trouvez des bibliothèques et liez-les si nécessaire
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(MonProjet PRIVATE SomeLibrary)
