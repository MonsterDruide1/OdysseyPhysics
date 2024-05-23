configure:
	cmake -G Ninja -B build .

.PHONY: build
build:
	ninja -C build

clean:
	rm -rf build

gdb: build
	gdb -q build/OdysseyPhysics

valgrind: build
	valgrind --leak-check=full --suppressions=valgrind.supp --keep-debuginfo=yes --gen-suppressions=all build/OdysseyPhysics

run: build
	build/OdysseyPhysics
