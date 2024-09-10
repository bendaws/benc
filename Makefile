all: src/benc.c benc
	cd src
	$(CC) benc.c -o build/benc
	echo "Done with target 'all'"

install: bin/benc
	sudo cp bin/benc /usr/local/bin/benc
	sudo cp bin/benc /usr/local/bin/bc

	echo "Done with target 'install'"

tests: tests/scanning.bc tests/string.bc
	cd tests
	../bin/benc scanning.bc
	../bin/benc string.bc

	echo "Done with target 'tests'"
