########################################################################
# Zoe Sarwar (cssc0802), Patrick Perrine (cssc0801)
# CS 570 Summer 2019
# Assignment #1, Player
# Makefile
########################################################################

# Variables

CXX = g++ -pthread

# Targets

player: player.o  
	$(CXX) -o player player.o

player.o: player.cpp player.hpp
	$(CXX) -c player.cpp player.hpp
        
clean:
	rm -rf player
        
########################[ EOF: Makefile ]################################
