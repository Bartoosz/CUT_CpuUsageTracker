CFLAGS = -Wall -Wextra -pthread

all: final

final: main.o reader.o analyzer.o buffer.o
	echo "linking and produce final app"
	gcc $(CFLAGS) main.o reader.o analyzer.o buffer.o -o final

main.o: main.c
	echo "compiling the main file"
	gcc $(CFLAGS) -c main.c

reader.o: src/reader.c
	echo "compiling the reader file"
	gcc $(CFLAGS) -c src/reader.c

analyzer.o: src/analyzer.c
	echo "compiling the analyzer file"
	gcc $(CFLAGS) -c src/analyzer.c

buffer.o: src/buffer.c
	echo "compiling the buffer file"
	gcc $(CFLAGS) -c src/buffer.c

clean:
	echo "remove everything"
	rm main.o reader.o buffer.o analyzer.o final