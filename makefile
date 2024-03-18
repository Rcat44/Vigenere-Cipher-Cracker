# Reese Myers
# CPSC 1070: 010
# 04/09/2023

# Note: Compiles with -O3 optimizations

# compile is the default command. It runs the date and parking commands before
# compiling the driver file and linking it to all of the object code files
# The resulting executable file is named battle.out
compile:
	make queue
	make cipher
	make advanced
	g++ Project3.cpp Queue.o Cipher.o CipherAdvanced.o -O3 -o encryption.out -Wall
# The queue command is used to compile only Queue.cpp
queue:
	g++ Queue.cpp -O3 -c -Wall
# The cipher command is used to compile only Cipher.cpp
cipher:
	g++ Cipher.cpp -O3 -c -Wall
# The advanced command is used to compile only CipherAdvanced.cpp
advanced:
	g++ CipherAdvanced.cpp -O3 -c -Wall
# The run Command runs encryption.out
run:
	./encryption.out
# The clean command removes all .out files
clean:
	rm *.out
