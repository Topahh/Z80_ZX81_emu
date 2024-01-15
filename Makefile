# Nom du fichier exécutable
TARGET = monprogramme

# Compilateur C++
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -g -Iinclude

# Trouver tous les fichiers .cpp dans le répertoire src et à la racine
SRC = $(wildcard src/*.cpp) $(wildcard *.cpp)

# Convertir les fichiers .cpp en .o dans le répertoire obj
OBJ = $(SRC:%.cpp=obj/%.o)

# Règle pour créer le répertoire obj
obj:
    @mkdir -p obj/src

# Règle par défaut
all: obj $(TARGET)

# Règle pour lier le programme
$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour nettoyer les fichiers générés
clean:
    rm -rf obj $(TARGET)

# Règle pour les fichiers objets
obj/%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@
