# Nom du fichier exécutable
TARGET = monprogramme

# Compilateur C++
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -g

# Trouver tous les fichiers .cpp dans le répertoire courant
SRC = $(wildcard *.cpp)

# Convertir les fichiers .cpp en .o
OBJ = $(SRC:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Règle pour lier le programme
$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour nettoyer les fichiers générés
clean:
    rm -f $(OBJ) $(TARGET)

# Règle pour les fichiers objets
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $<
