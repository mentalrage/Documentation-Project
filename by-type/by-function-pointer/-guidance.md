*** UID:0001T0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Function-Pointer Guidance

Use this folder for function-pointer typedefs, callback signatures, dispatch table entries, and virtual-like callable slots that need type-level documentation.

Good candidates include:

- callback prototypes shared by UI, network, timer, or resource systems;
- table entries whose signature is known from multiple callers;
- function-pointer aliases that likely lived in a common header.

Put concrete table symbols in `../../by-global` when the symbol itself is the focus. Put exact address ranges in `../../by-memory`.
