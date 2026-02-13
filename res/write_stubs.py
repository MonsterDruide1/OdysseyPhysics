import sys
import re

data = sys.stdin.read()

p = re.compile(r"([^:]+):\d+:\(.*\): undefined reference to `([^']+)'")
matches = p.findall(data)

undef_funcs = {}
for m in matches:
    if m[1] not in undef_funcs:
        undef_funcs[m[1]] = set()
    undef_funcs[m[1]].add(m[0])

sorted_funcs = sorted(undef_funcs.keys())

for func in sorted_funcs:
    files = undef_funcs[func]
    print(f"void {func} {{}}")
