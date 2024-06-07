# helper script to generate a file that includes all other headers
# used to find duplicate definitions that might be silently ignored
# because they never conflict normally

HEADER=$1
shift
# don't check NintendoSDK, as that contains 4.0.1-only files
for file in $(find $@ -name '*.h')
do
    # ignore Wii-specific files
    # ignore ScopeGuard, as that uses <optional> (C++17)
    if [[ $file == *"cafe"* || $file == *"seadScopeGuard.h" ]]; then continue; fi
    echo "#include \"$file\"" >> $HEADER
done
