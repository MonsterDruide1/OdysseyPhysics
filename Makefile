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
	gdb -q build/OdysseyPhysics

valgrind: build
	valgrind --suppressions=valgrind.supp --keep-debuginfo=yes --gen-suppressions=all --log-file=valgrind.log --soname-synonyms=somalloc=nouserintercepts build/OdysseyPhysics

run: build
	build/OdysseyPhysics

test_fps: build
	build/OdysseyPhysics "SandMeganeExStageMap"
	build/OdysseyPhysics "SandWorldHomeStageMap"
	build/OdysseyPhysics "CityWorldHomeStageMap"
	build/OdysseyPhysics "PeachWorldHomeStageMap"
	build/OdysseyPhysics "SeaWorldHomeStageMap"
	build/OdysseyPhysics "SeaWorldVibrationStageMap"
