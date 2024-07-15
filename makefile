.ONESHELL:

reset:
	rmdir build
	mkdir build
	cd build
	cmake -GNinja ..

run:
	ninja -C build
	.\EXECUTABLE.exe 