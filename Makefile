configure:
	cmake -G Ninja -B build .

.PHONY: build
build:
	ninja -C build

clean:
	rm -rf build

generate:
	rm src/all_headers.cpp || true
	cd src && bash ../generate.sh all_headers.cpp . ../lib/smo/src ../lib/smo/lib/al
	$(MAKE) configure
	$(MAKE) build
	rm src/all_headers.cpp
	

gdb: build
	gdb -q build/OdysseyPhysics

valgrind: build
	valgrind --leak-check=full --suppressions=valgrind.supp --keep-debuginfo=yes --gen-suppressions=all build/OdysseyPhysics

run: build
	build/OdysseyPhysics
