default:
	g++ -c main.cpp;
	g++ -c stacker.cpp;
	g++ main.o stacker.o -o stack;
clean:
	rm main.o;
	rm stacker.o;
