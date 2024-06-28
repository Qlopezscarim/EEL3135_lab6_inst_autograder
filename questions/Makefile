all: libquestions.a
questionslib.o: questions.cpp
	g++ -c questions.cpp -o questionslib.o
libquestions.a: questionslib.o
	ar rcs libquestions.a questionslib.o
