configure:
	cmake -G Ninja -B build .

.PHONY: build
build:
	ninja -C build
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
	gdb -q --args build/OdysseyPhysics 0

valgrind: build
	valgrind --suppressions=valgrind.supp --keep-debuginfo=yes --gen-suppressions=all --log-file=valgrind.log --soname-synonyms=somalloc=nouserintercepts build/OdysseyPhysics 0

run: build
	build/OdysseyPhysics 0

test_fps: build
	build/OdysseyPhysics 0 "SandMeganeExStageMap"
	build/OdysseyPhysics 0 "SandWorldHomeStageMap"
	build/OdysseyPhysics 0 "CityWorldHomeStageMap"
	build/OdysseyPhysics 0 "PeachWorldHomeStageMap"
	build/OdysseyPhysics 0 "SeaWorldHomeStageMap"
	build/OdysseyPhysics 0 "SeaWorldVibrationStageMap"
