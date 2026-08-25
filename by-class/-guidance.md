*** UID:0001ZL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Class Guidance

Use `by-class` for reconstructed C++ class ownership, responsibilities, inheritance notes, field summaries, method groups, and evidence that ties methods/globals back to a class.

Class pages should stay at the class level. Put exact executable ranges and full method bodies in `../by-memory`; use `../by-function` only as an optional method/function index back to the owning `by-memory` page.

Prefer canonical class names when evidence is strong. If the current name is still generated or provisional, rename the file when evidence is high enough and run the validator file scan afterward so UID references stay stable.

## Naming

Filenames should be current canonical class names:

```text
AboveFrame.md
Browser.md
RegistryConfig.md
```

Record old/generated names only when they remain useful evidence or search terms for old tool output, traces, IDA labels, Wave3, or `simroot_v2`. Do not keep alias lists just to preserve links; UID references are the durable cross-document identity.

## Page Contents

Each class page should include:

- current class name, plus old/generated names only when they remain useful evidence or search terms;
- likely original source file and header placement;
- method list or method-family summary with address ranges;
- class responsibility, inheritance/interface evidence, owned globals/static data, and closely coupled helper types;
- unresolved naming/layout issues;
- cross-references to likely file docs and memory-range docs.

Class docs should not become a dump of every method body. Keep method inventories and ownership summaries here, point to exact `../by-memory` pages for full method documentation, and use `../by-function` only as an optional name-centric index. Put small unresolved findings in `../by-item`.

## Scoring Discipline

Do not rate a class page at `95+` completion or confidence lightly. Those values mean the class has already had a near-final audit: ownership, source placement, vtables, methods, fields, static data, child pages, neighboring ranges, generated-name replacements, and supporting IDA/MCP or byte-level evidence are all documented with the required specificity for another agent to verify the rating from the page itself. If any major member, dependency, source-placement claim, or contained item still needs research, keep the score below `95`.

## Coverage Report Rows

Use class names as row keys in `-coverage-report.md`, sorted alphabetically. A class is reconstructable when its responsibility, likely source placement, key methods, state ownership, and exact memory evidence are at least partially documented. Put confirmed stale/generated class aliases or non-project class artifacts in `-ignored.md` with evidence instead of leaving them as recurring open work.

## Reconstruction Autogen

Singular class pages are eligible for validator autogen metadata. Mark `RECONSTRUCTABLE:TRUE` only when the page contains or is ready to contain C++ class/declaration code for the rebuilt project. Use `CANONICAL_OWNER` for the direct semantic owner, usually the owning `by-file` UID unless the class is intentionally nested under another documented owner. Use `EMITTER_UIDS` for generated-output routing, usually the same owning file UID or a valid emitter chain that reaches a by-file source root. Put real C++ in the validator-managed `RECONSTRUCTION_CPP CODE:BEGIN/END` block and use `[[CHILDREN]]` where emitted methods, fields, or nested types should be inserted. Do not add emitted class C++ until the active `90/90+` reconstruction-code gate in `../by-structure.md` is satisfied; `95+` remains a rare final-audit score and is not required merely to begin final-quality code entry.
