*** UID:0001RV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Type Guidance

Use `by-type` for C/C++ declarations and layout decisions that are not primarily class ownership or source-file grouping. This folder covers Wave3 type-like entity kinds and their reconstruction notes.

## Subfolders

- `by-struct`: named structs and recovered POD layouts.
- `by-union`: named unions and overlapping storage layouts.
- `by-enum`: enums and enum values.
- `by-alias`: typedefs, using aliases, and function-pointer aliases.
- `by-namespace`: namespace and logical scope reconstruction.
- `by-template`: template parameter and template-use evidence.
- `by-macro`: macros, compile-time constants, and preprocessor decisions.
- `by-include`: include ownership and dependency decisions.
- `by-forward-declare`: forward declaration decisions.
- `by-packing`: `#pragma pack` and packing-policy notes.
- `by-alignment`: alignment requirements and alignas-style evidence.
- `by-bitfield`: packed flag fields, bitmask layouts, and bit-level storage evidence.
- `by-base`: inheritance/base relationship evidence when it needs more discussion than the class page.
- `by-field`: high-value field-layout notes only. Do not create one page per derived Wave3 field row.
- `by-static-member`: class static data members and class-scoped global declarations.
- `by-vtable`: virtual table layouts, slot ownership, and virtual dispatch reconstruction.
- `by-rtti`: MSVC RTTI/typeinfo and class hierarchy metadata.
- `by-function-pointer`: callback signatures, dispatch entry types, and function-pointer aliases.
- `by-calling-convention`: ABI, stack cleanup, hidden argument, and prototype evidence.
- `by-constant`: named constants, magic values, flags, and sentinels not yet represented as enums or macros.

## Naming

Prefer canonical C/C++ entity names where known, such as `ItemInfo.md`, `BrowserMessageId.md`, or `ArchiveReadFn.md`. For uncertain names, include the address or current Wave3 id in the filename.

Every page should link back to the owning `by-file` and `by-class` docs when applicable. Put exact executable/data address evidence in `by-memory`, and put source-module grouping decisions in `by-file`.

## Page Contents

Each type page should include:

- current Wave3 entity kind and id/name;
- likely owner header/source module;
- declaration hypothesis and confidence;
- layout, size, values, offsets, or dependency evidence as applicable;
- links to owning `../by-file`, `../by-class`, `../by-global`, and exact `../by-memory` evidence.

Use `by-field` only for high-value layout questions or heavily cross-referenced offsets. Wave3 has many derived field rows, so routine field rows should remain in class/struct docs rather than becoming one page per field.

Use `by-vtable` and `by-function-pointer` for type/layout reconstruction. Use `../by-global` for the concrete vtable, callback table, jump table, or global data symbol when the address and data ownership are the main subject.

## Scoring Discipline

Do not rate a type page at `95+` completion or confidence lightly. Those values mean the declaration, layout, ABI behavior, owner header/source placement, consumers, generated-name replacements, and supporting IDA/MCP or byte-level evidence have already been audited and written into the page with the required specificity for another agent to verify the score. If any field, value, slot, signature, owner, dependency, source placement, or related memory evidence still needs research, keep the score below `95`.

## Coverage Report Rows

Use canonical type names as row keys in `-coverage-report.md`, sorted alphabetically within the relevant type/subtype scope. If the name is provisional, include the address, current Wave3 id, or owning class/file in the row until evidence supports a rename. Type pages are reconstructable when they capture source-level declarations or ABI/layout facts needed by rebuilt C++ headers; compiler-only metadata such as RTTI records should be marked ignored unless it proves a source declaration, inheritance relationship, or layout decision.

## Reconstruction Autogen

Singular type pages are eligible for validator autogen metadata when they contain source-level C++ declarations that should be assembled into a generated `.cpp` draft. Use `CANONICAL_OWNER` for semantic ownership: nested/private types usually point to the owning class UID when supported, while file-level helper types usually point to the owning `by-file` UID. Use `EMITTER_UIDS` for generated-output routing and make sure the emitter chain reaches a valid by-file source root before adding emitted C++. Add emitted C++ only when the active `90/90+` reconstruction-code gate in `../by-structure.md` is satisfied; `95+` remains a rare final-audit score and is not required merely to begin final-quality code entry. Subtype guidance files and other `-xxx.md` support pages are excluded from autogen metadata.
