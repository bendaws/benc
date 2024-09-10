all: benc.c benc
	$(CC) benc.c -o build/benc
	echo "Done with target 'all'"

install:
	sudo cp bin/benc /usr/local/bin/benc
	sudo cp bin/benc /usr/local/bin/bc

	echo "Done with target 'install'"