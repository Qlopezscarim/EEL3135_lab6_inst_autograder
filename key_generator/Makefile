all: libkey_gen.a
libkey_gen.o: key_generator.cpp
	g++ -c key_generator.cpp -o libkey_gen.o
libkey_gen.a: libkey_gen.o
	ar rcs libkey_gen.a libkey_gen.o
