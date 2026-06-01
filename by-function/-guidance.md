*** UID:0001ZN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Function Guidance

Use `by-function` as an optional index for standalone functions, methods, callbacks, and helper routines when an additional name-based lookup is useful.

Do not duplicate full method documentation here. The full raw-code notes, C++ rewrite, evidence, call relationships, and memory bounds belong in the corresponding `../by-memory` page. A `by-function` page should point to that memory page and summarize ownership/status only when needed.

Prefer owner-qualified names for methods and clear function names for free functions. Rename generated names when IDA evidence is strong enough, then run the validator file scan to update UID-linked references.

## When To Create

Do not create `by-function` pages for every method by default. Full method/function coverage should come from exact `../by-memory` pages. Create a `by-function` page only when the name-centric index has a clear tracking or navigation purpose, such as rewrite status, overload/disambiguation notes, durable name tracking, or links from many class/file/topic pages.

## Naming

Filename examples:

```text
ClassName.MethodName.md
ClassName.MethodName_00401234.md
FunctionName_00401234.md
```

## Page Contents

Each function page should include:

- canonical function or method name and any unresolved naming issue;
- owner class/file hypothesis;
- UID reference to the exact `../by-memory` documentation page;
- rewrite/reconstruction status if the function is being actively worked;
- brief notes that help locate or disambiguate the function.

Keep raw code evidence and final-output C++ reconstruction in `../by-memory`; keep class summaries in `../by-class`; keep original source placement in `../by-file`.

## Scoring Discipline

Do not rate a function page at `95+` completion or confidence lightly. Those values require a near-final audit of the exact function or method: canonical name, owner, address-range link, signature, behavior, callees, touched state, source placement, generated-name replacements, and supporting `../by-memory` evidence must already be verified and written down. If the exact body, owner, dependencies, or linked memory page still needs deeper review, keep the score below `95`.

## Coverage Report Rows

Use canonical function names or owner-qualified method names as row keys in `-coverage-report.md`, sorted alphabetically. Because this folder is optional, uncovered rows should represent functions that need name-centric tracking, not every function in the binary. The exact body coverage and completion state still belongs to the linked `../by-memory` page.

## Reconstruction Autogen

Singular `by-function` pages are eligible for validator autogen metadata when they contain final C++ for a free function, helper, or method stub that should be assembled into rebuilt source. Prefer keeping the full body in `../by-memory`; use `by-function` autogen only when the name-centric page is the active reconstruction owner. Attach methods to the owning class UID and free helpers to the owning `by-file` UID.
