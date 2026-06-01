*** UID:0001TF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-RTTI Guidance

Use this folder for MSVC RTTI, typeinfo, class hierarchy metadata, and compiler-generated type records when they help reconstruct class ownership.

Good candidates include:

- recovered type descriptors or complete-object locators;
- class hierarchy descriptors that confirm inheritance;
- RTTI evidence that resolves class names, namespaces, or base-class ordering.

Prefer `../by-base` when the page is mainly about the semantic inheritance relationship. Prefer `../by-vtable` when the page is mainly about virtual slot layout.
