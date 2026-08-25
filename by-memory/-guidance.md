*** UID:0000VM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# By-Memory Guidance

Use `by-memory` for address-range-centered documentation. Filenames should name real executable or data ranges, not arbitrary buckets. Prefer exact function, method, global-data, class aggregate, vtable, or reviewed library-runtime ranges.

Before using completion/confidence scores as the main work queue, keep `-coverage-report.md` focused on full address coverage until every executable/data range has some kind of documentation and no `UNKNOWN` ranges remain.

## Completion And Confidence Scores

Completion is the amount of highly detailed documentation completed for the exact memory item. A `100` completion score means the page has literally everything about that item documented to the level needed for reconstruction: exact bounds, boundary caveats, owner/source placement, behavior, raw code evidence, callers/callees, touched fields/globals/resources, local variables when relevant, nested child ranges or tables, rebuild handling, C++ reconstruction shape where applicable, relationship to surrounding ranges, and resolved or explicitly closed open questions. Do not treat a short behavior summary as high completion just because the main purpose is known.

Confidence is how confident the agent is that the documentation on the page is correct. It applies to every contained claim, including boundaries, ownership, function/method classification, source-file placement, field/global/type names, local-variable and synthetic/generated-name replacements with accurate human names, caller/callee interpretation, internal data flow, packet/resource/table meanings, and the detailed explanation of exactly what the code or data does. Keep confidence lower when a page still relies on generated Wave3/Wave2/simroot names, unverified synthetic names, inferred ownership, incomplete IDA/MCP checks, or unresolved nested subitems.

Score both values against the whole memory item and anything inside it. A page can know the broad purpose of a function or range and still deserve a low score if its nested calls, internal branches, local names, owned data, external references, source placement, or replacement of generated names with accurate human names are incomplete.

For `by-memory`, completion and confidence should be scored against the exact item documented by that page. Aggregate pages can have lower completion even when many child pages are strong, because the aggregate itself still needs detailed nesting, ownership, source-placement, and relationship documentation.

Do not treat `95` or any higher score as an aspirational target, cleanup grade, low-score-queue cleanup marker, or routine sign that a memory page is reconstructable. Rating a memory page at `95+` must not be done lightly. It is a near-final audit state for the whole exact range, and it means extreme range-level documentation has already been completed, all known relevant bytes and supporting data have already been verified, and the page itself records enough evidence for another agent to defend the score without relying on private session context.

Evidence only counts toward a `95+` memory score when it is written into that memory page or clearly linked by stable UID to supporting documentation. Do not use a remembered IDA/MCP check, generated Wave2/Wave3 score, or private session conclusion as justification unless the actual evidence has been recorded.

Before raising any memory item to `95+`, assume the score will be audited as final-source evidence. Every material byte, boundary, dependency, name, call, referenced data item, and ownership claim used by the page must already be verified and recorded in the page itself. If verification is incomplete, only partially recorded, or remembered only from the current session, keep the score below `95`.

For avoidance of doubt: never assign `95+` from inherited confidence, a generated grade, a stale coverage row, or a partial local review. The memory page itself must prove the score through complete, written verification of the exact bytes, boundaries, dependencies, names, contained children, and immediately surrounding ranges.

Do not use `95+` scoring to record progress, effort, or a likely-looking interpretation. It should only be used after a deliberate verification pass proves the exact range is already documented deeply enough for independent review.

Do not assign `95+` because the remaining uncertainty seems unlikely to matter. A `95+` memory score means the agent has already performed and documented the hard verification work: IDA/MCP or byte-level checks, exact start/end and neighboring-boundary checks, callee/dependency checks, generated-name replacement review, source-placement review, and review of all data structures/globals/resources touched by the range.

Treat any `95+` memory score as a formal range audit decision. Before setting either value to `95` or higher, confirm that the page documents the exact range in extreme detail, all available IDA/MCP and byte-level evidence has been checked, all material synthetic/generated names have been resolved or explicitly justified, all relevant calls/data/dependencies have been verified, and all meaningful surrounding-boundary and ownership questions have been closed in the written page. If that work has not been completed and recorded, do not set `95+`.

Keep memory-page completion and confidence below `95` unless every material claim about the exact range has been independently checked and written down. This includes all bytes in the range, start/end boundaries, immediately relevant surrounding ranges, callers/callees, dependencies, owned state, touched globals/fields/resources/tables, nested subranges, source placement, rebuild handling, local/global/type names, and generated-name replacements. If any claim still depends on generated Wave3/Wave2/simroot data, inferred ownership, unresolved neighboring ranges, synthetic names, uncertain callees, incomplete internal behavior, unverified data/state effects, incomplete referenced data, or "probably correct" naming, keep the score below `95`.

Do not move a memory page to `95+` after a narrow improvement, one checked subsection, or because the page is useful, mostly correct, or much improved. Never round up because the remaining unknowns look small or likely non-blocking. If the page still needs another broad IDA/MCP pass, data-flow review, dependency audit, boundary audit, source-placement audit, naming cleanup, or referenced-data verification before it can be treated as near-final range documentation, the correct score is below `95`.

Any memory page scored `95+` for completion or confidence must contain an explicit evidence/audit note defending the rating. Include what IDA/MCP or byte-level checks were performed, how the start/end boundaries and neighboring ranges were verified, which callees/dependencies and referenced data were checked, why ownership and names are no longer tentative, and why any remaining caveats are non-blocking. If the page cannot explain the `95+` rating in its own text, keep the score lower.

When in doubt, cap memory-page completion and confidence at `94` or lower. A `95+` memory score must mean every known relevant byte, dependency, name, boundary, neighboring range, and supporting data item has already been verified and documented, not that later research is expected to confirm the current interpretation.

Do not set either individual metric to `95+` while the paired research burden is still incomplete. A memory page with `95+` completion still needs verified confidence evidence, and a memory page with `95+` confidence still needs specific written documentation for another agent to audit the exact range without relying on the original session.

## Naming

Filename examples:

```text
0x004610f0-0x0046178a.AboveFrame.md
0x005063e0-0x005067bf.RefreshSelectedProfileData.md
```

Temporary uncertain-bound filenames are allowed only when an entity is real but exact start/end bounds are not yet verified. In prose or coverage rows, use `?` for unknown hex nybbles, such as `0x00612???-0x0061????`. Windows filenames cannot safely use `?`, so use `_` in the filename for the same unknown nybbles:

```text
0x00612___-0x0061____.UnboundedVtableOrStringIsland.md
```

Treat uncertain-bound filenames as open/weak range claims, not exact coverage. Replace them with exact address-range filenames once IDA/MCP or manual byte review establishes real bounds, then run the validator in file mode on the renamed file.

Do not create pages for arbitrary broad spans such as `0x00400000-0x00500000` unless the binary itself exposes a meaningful section/range and the page is explicitly a section-level map.

## Page Contents

Each memory page should include:

- covered address range(s), inclusive start and exclusive or observed end when known;
- entity kind and current Wave3/Wave2 owner, such as class, method, global, global-data, or runtime/library exclusion;
- source evidence from `show memory-at`, `inspect memory-range`, `show method`, `show global`, IDA decompilation, xrefs, or trace notes;
- disposition: reconstructable project code, attached to existing class/file, free helper/global, data-only, library/runtime, excluded, or unresolved;
- rebuild handling: whether the range is `source-authored`, `source-declared/generated-binary`, `resource-derived`, `third-party/runtime`, `compiler/linker-generated`, or `unknown`;
- raw code evidence when useful, such as IDA decompilation, relevant disassembly, or generated source/decompiler excerpts that support the analysis;
- reconstructed C++ code as it should exist in the final output only when confidence and completion are high enough for final-source quality. This is lower priority until the owner file, external references, field names, called functions, surrounding ranges, and data dependencies are understood well enough to avoid baking in bad names or structure;
- links to related `../by-class`, `../by-file`, `../by-function`, `../by-global`, `../by-type`, `../by-resource`, and `../by-item` docs when relevant.

For functions and methods, `by-memory` is the canonical full documentation layer. The complete behavior, raw evidence, reconstructed C++ candidate, callers/callees, field/global usage, and confidence should live on the exact memory-range page. Other folders should point back to that page by UID instead of duplicating the method body.

## Function Or Method Page Shape

Suggested function/method pages should include:

- `Address Range`: exact start/end, inclusive/exclusive convention, and any boundary uncertainty;
- `Owner`: class, source-file, subsystem, or unresolved owner hypothesis;
- `Signature`: calling convention, parameters, return value, `this` type, and confidence;
- `Behavior`: concise description of what the function/method does;
- `Raw Code Evidence`: IDA decompilation, relevant disassembly, generated/decompiler excerpt, or exact observations that justify the behavior claim;
- `Reconstructed C++ Candidate`: final-output-style C++ only when confidence is high enough;
- `Callers/Callees`: important xrefs, virtual dispatch, callback use, and unresolved external references;
- `Touched State`: fields, globals, resources, files, packets, tables, or memory layouts used;
- `Confidence And Open Questions`: what is confirmed, what remains speculative, and next verification targets.

## Coverage Rows, Gaps, And Nesting

`by-memory` coverage rows should use exact address ranges as the row key and stay sorted by first address. Display rows should include an entity type/kind after the address range and before the item name when the row is next edited. Use concise types such as `class`, `method`, `function`, `global`, `global-data`, `vtable`, `jump-table`, `runtime`, `third-party`, `padding`, or `unknown`.

Example:

```text
- [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) 0x004063d0-0x0040649b | third-party | LibJpegUtilityHelpers : ignored : 80% : strong : ...
```

Do not batch-rewrite existing rows only to add the type field. Add or correct it opportunistically when a file is already being edited for documentation, coverage, or evidence updates.

When the covered/ignored memory inventory is detailed enough to compare adjacent ranges, insert explicit gap rows between documented ranges. Use `UNKNOWN` for unchecked executable/data spans that have not been manually investigated:

```text
[0x########-0x######## (# bytes) | UNKNOWN] : unknown : 0% : open : Range between adjacent documented by-memory rows; not manually investigated.
```

Use this form only after confirming the span has no meaningful bytes/data to document:

```text
[0x########-0x######## | EMPTY (# bytes)] : ignored : 100% : strong : Confirmed empty/padding range.
```

Do not add broad speculative gap rows without checking section boundaries and neighboring items. `UNKNOWN` rows should be low-to-high address sorted with normal memory rows and should not replace exact pages for real functions, globals, data tables, or ignored third-party/runtime spans. When an `UNKNOWN` row is investigated, replace it with a documented range row or convert it to an `EMPTY` row only after byte/padding verification.

Ranges may overlap when one page documents an aggregate owner, such as a class/module/library span, and other pages document exact functions, helper islands, globals, or subranges inside that aggregate. Display real containment by indenting child rows directly under the parent row instead of flattening every row at the same level. Keep the parent ordered by its start address, then indent children under it in low-to-high address order. Use nesting only for true containment or a clearly documented aggregate/subitem relationship; crossing overlaps that are not containment should stay flat until the ownership boundary is corrected.

Example:

```text
- [0x00410000-0x00411000 | ParentModule] : reconstructable : 60% : medium : Aggregate owner range.
    - [0x00410100-0x00410180 | ChildHelper] : reconstructable : 80% : strong : Exact helper inside the parent range.
    - [0x00410200-0x00410210 | EMPTY (16 bytes)] : ignored : 100% : strong : Confirmed alignment padding inside the parent range.
- [0x00411000-0x00411100 | NextIndependentRange] : reconstructable : 60% : medium : Separate non-overlapping row.
```

## Legacy Wave2 Stage Notes
Legacy Wave2 marker/status instructions were moved to `-legacy-wave2-stage-notes.md` so this guidance file stays focused on current `by-memory` documentation rules.

Treat that note as retained historical/staging context. Current documentation workflow is governed by `../by-structure.md`, this file, and `../tools/validator_README.txt`.

## Reconstruction Autogen

Singular memory pages are eligible for validator autogen metadata when they document code or source declarations that should be rebuilt. Full method/function documentation can live here. If IDA/MCP or direct binary evidence shows the page represents NexusTK-owned source that must be rebuilt, mark `RECONSTRUCTABLE:TRUE` even if the final owner UID, emitter route, or final C++ is not ready yet; the validator reports missing ownership as `no-owner` and missing generated-output routing as `non-emits`. Use `CANONICAL_OWNER` for the direct semantic owner and `EMITTER_UIDS` only when the generated-output route is known well enough to surface to a valid by-file source root.

Do not attach a memory page to a parent or fill `RECONSTRUCTION_CPP CODE` just because rebuild ownership is plausible. Parent methods normally attach to the owning class or source-file page, and free helpers attach to the owning `by-file` page, but only after that relationship is highly verified. Final C++ should be added only when the exact item, its callees/dependencies, surrounding ranges, names, and source placement are sufficiently verified and the item clears the active reconstruction-code gate in `../by-structure.md`: `RECONSTRUCTABLE:TRUE`, one or more confirmed nonblank `EMITTER_UIDS` that surface to valid generated source output without a dead-end, and `(COMPLETION + CONFIDENCE) / 2 > 85`. The separate `95+` scoring rules above still describe rare final-audit scores; they are no longer required before adding reconstruction C++. Keep raw/decompiled code and converted C++ distinct, and use the autogen code block only for final-output-style source that is highly plausible as original mid-2000s C++.
