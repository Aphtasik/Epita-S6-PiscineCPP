
test: test.o 
	g++ -g -Wall -Wextra -pedantic -std=c++20 -lgtest test.cc ../*.cc

check: test
	valgrind ./a.out

clean:
	rm -rf *.o a.out
