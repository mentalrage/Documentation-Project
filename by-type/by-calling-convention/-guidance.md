*** UID:0001SA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Calling-Convention Guidance

Use this folder for ABI and signature questions that materially affect reconstruction.

Good candidates include:

- unresolved `__thiscall`, `__cdecl`, `__stdcall`, or callback calling conventions;
- functions where stack cleanup, varargs, hidden return pointers, or register arguments are important evidence;
- helper groups where the same prototype appears through several call sites.

Keep ordinary function behavior documentation in `../../by-item` or the owning `../../by-file` page. Link exact disassembly/decompiler evidence through `../../by-memory`.
