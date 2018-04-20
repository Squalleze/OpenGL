CXX=g++
LD=
CXXFLAGS=-O3 -Wall -std=c++11
CPPFLAGS=
LDFLAGS=
LDLIBS=-lSDL2 -lstdc++ -lGL -lGLEW

build:
	mkdir -p tmp
	rm tmp/*
	$(CXX) $(CXXFLAGS) -c -x c++ -o tmp/Game.o lib/Game.cpp
	$(CXX) $(CXXFLAGS) -c -x c++ -o tmp/main.o main.cpp

	$(CXX) $(CXXFLAGS) -o game.app tmp/*.o $(LDLIBS)
