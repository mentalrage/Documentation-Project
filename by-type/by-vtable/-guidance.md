*** UID:0001WX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Vtable Guidance

Use this folder for virtual table layout research, virtual slot ordering, deleting destructors, and vtable-to-class ownership.

Good candidates include:

- vtable layouts where slot names are still being recovered;
- classes with multiple vtables or secondary base subobjects;
- evidence tying virtual calls back to an original header declaration.

Use `../../by-global` for the concrete vtable symbol page when the address, initializer, or data ownership is the main topic. Link class behavior through `../../by-class` and exact ranges through `../../by-memory`.
