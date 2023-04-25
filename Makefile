CFLAGS = -Wall -Wextra

all: final

final: main.o reader.o 
	echo "linking and produce final app"
	gcc $(CFLAGS) -pthread main.o reader.o -o final

main.o: main.c
	echo "compiling the main file"
	gcc $(CFLAGS) -c main.c

reader.o: src/reader.c
	echo "compiling the reader file"
	gcc $(CFLAGS) -c src/reader.c

logger.o: src/logger.c
	echo "compiling the logger file"
	gcc $(CFLAGS) -c src/logger.c

clean:
	echo "remove everything"
	rm main.o reader.o final