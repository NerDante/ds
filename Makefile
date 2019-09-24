
.PHONY:	build install clean
build:
	mkdir -p build install
	mkdir -p install/bin
	cd ./build && cmake ../ && make

install:
	cp build/test_* install/bin

clean:
	rm -rf build install
