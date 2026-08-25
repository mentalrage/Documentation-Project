*** UID:0000PE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Global Guidance

Use `by-global` for process-wide symbols and non-class code/data that need more than a small `by-item` note.

## Scope

This folder covers:

- free functions and helper functions;
- global variables and Wave3 `global-data` records;
- singleton pointers and manager globals;
- vtables, callback tables, jump tables, and function-pointer globals;
- global arrays, resource indexes, and module-scope state;
- static member storage when the exact address or global lifetime is central.

Prefer filenames based on the canonical symbol, such as `g_pPaletteLib.md`, `FatalError.md`, or `AlphaBlendLookupTable.md`. If a name is unknown, include the address or current Wave3 id.

Put source-file ownership hypotheses in `../by-file`, class-static declaration details in `../by-type/by-static-member`, and exact address evidence in `../by-memory`.

## Page Contents

Each global page should include:

- canonical symbol name and aliases/current Wave3 id;
- exact address or address range when known;
- symbol kind, type/signature, owner file hypothesis, and current Wave3/Wave2 ownership;
- lifetime/initialization/shutdown behavior if known;
- xrefs, callers/users, related classes, and source-module evidence;
- unresolved naming, type, or owner questions;
- links to `../by-file`, `../by-class`, `../by-type`, and `../by-memory`.

For the full body of a free/helper function, use the exact `../by-memory` page. `by-global` should focus on symbol ownership, lifetime, users, and source-module placement.

## Scoring Discipline

Do not rate a global page at `95+` completion or confidence lightly. Those values require a near-final audit of the symbol or table: exact address/range, type or signature, lifetime, owner file/class, all known users, touched state, source-placement evidence, generated-name replacements, and relevant `../by-memory` evidence must be verified and recorded in the page. If any material user, initializer, shutdown path, owner, type, or referenced data remains uncertain, keep the score below `95`.

## Coverage Report Rows

Use canonical symbol names as row keys in `-coverage-report.md`, sorted alphabetically. If no canonical name is known yet, include the address or current generated id until evidence supports a rename. Mark ignored globals only after confirming they are compiler/runtime/third-party artifacts, duplicate generated names, or superseded by a better owner; mirror those ignored rows in `-ignored.md`.

## Reconstruction Autogen

Singular global pages are eligible for validator autogen metadata when they contain source-level global, static, singleton, table, vtable, or callback declaration/definition code that should appear in rebuilt C++. Use `CANONICAL_OWNER` for the direct semantic owner: file-local globals usually point to the owning `by-file` UID, while class-owned static storage or vtables should point to the owning class UID only when that ownership is well supported. Use `EMITTER_UIDS` only for generated-output routing, and ensure every emitter chain eventually reaches a valid by-file source root. Add emitted C++ only when the active `90/90+` reconstruction-code gate in `../by-structure.md` is satisfied; `95+` remains a rare final-audit score and is not required merely to begin final-quality code entry.
