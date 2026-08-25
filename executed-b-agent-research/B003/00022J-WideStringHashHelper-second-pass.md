** TARGET-REPORT-UID:00022J **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022J WideStringHashHelper Second-Pass Owner/Emitter Recheck

## Finalized Recommendation

Keep [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) unchanged:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

No coverage-row replacement is recommended. The prior B002 post-migration conclusion remains correct after this independent second pass: the helper is real source-authored code, but no direct source owner, source-use context, table entry, caller, raw VA/RVA pointer, or branch/call route currently proves a valid emitter. Do not route this to `StringUtil` or any adjacent owner solely from the wide-string hash behavior.

Score before: `88/92`. Score after: `88/92`.

This is not an invalid dead/non-emitting reconstructable state under the current owner/emitter model. `RECONSTRUCTABLE:TRUE` is justified because the isolated function body must eventually be reproduced if a valid source root is proven. Blank `EMITTER_UIDS` is justified because no generated C++ is being entered or emitted now and no output route clears the evidence gate. This is an unresolved reconstructable item, not a permanent claim that the code is disposable.

## Target

- Assignment: `B003-00022J-second-pass`
- Target row: [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](../../../../../by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md)
- Current coverage source: `auto-generated/-ag-memory-coverage.md`
- Prior report reviewed: `tools/leaser/Agents/Agent-B002/research/executed/00022J-WideStringHashHelper-post-migration.md`
- Current generated no-owner row: `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, non-emitting/no-owner generated destination

## Evidence Summary

The target is a compact `cdecl` helper over a `const uint16_t *` input. Current IDA MCP records in the target page and prior B002 report show C001 created an exact IDA function at `0x004b81a0-0x004b81eb`, named it `WideStringHashHelper`, and Hex-Rays decompiled it as a `wcslen` plus rolling hash using multiplier `1000003`. The body has no calls, no globals, no object receiver, no memory writes, and no side effects beyond reading the input string.

Boundary evidence is strong:

- Predecessor padding: `0x004b8194-0x004b81a0` is all `0xcc`.
- Function body: `0x004b81a0-0x004b81eb`, size `0x4b`.
- Successor padding: `0x004b81eb-0x004b81f0` is all `0xcc`.
- Adjacent helper contrast is normal: `FileExists` at `0x004b81f0`, `BuildFieldMapPath` at `0x004b8220`, and `RectAnchorAxisAdjustHelper` at `0x004b8290` all have their documented xref surfaces, while this target does not.

The helper behavior is reconstructable. The ownership/emitter route is not.

## IDA MCP Evidence Reviewed

Current project documentation records the following IDA MCP facts for this exact target:

- C001 pre-fix checks found no function at `0x004b81a0`, no xrefs to `0x004b81a0`, and normal references to adjacent helper starts.
- C001 then applied the IDA repair: `define_func 0x004b81a0-0x004b81eb`, rename to `WideStringHashHelper`, and `idb_save`.
- C001 post-fix `lookup_funcs` reports `WideStringHashHelper` at `0x004b81a0`, size `0x4b`.
- Hex-Rays decompile reports the `wcslen(a1)`, seed `*a1 << 7`, loop `v5 ^ (1000003 * v3)`, and final `length ^ hash` shape.
- `xrefs_to`, `callers`, `search code_ref`, `search data_ref`, immediate scans, and raw VA/RVA pointer scans recorded in the target page and B002 report found no direct reference to `0x004b81a0`.
- The `imul edx, 0x0f4243` encoding is unique in `.text`, at `0x004b81d6`.

This second pass did not perform any IDA database mutation. The existing IDA MCP records are sufficient for function identity and are cross-checked below with fresh PE/raw evidence.

## Fresh PE/Raw Evidence

I independently scanned `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

- Image base: `0x00400000`
- Target RVA: `0x000b81a0`
- Target file offset: `0x000b75a0`
- Target section: `.text`
- Target size: `0x4b`
- First bytes: `55 8b ec 56 8b 75 08 8b ce 57 8d 51 02 0f 1f 00`
- Last bytes: `00 33 d0 83 e9 01 79 ed 33 d7 5f 8b c2 5e 5d c3`
- Exact body occurrence count: one, at `0x004b81a0`
- `69 d2 43 42 0f 00` occurrence count: one, at `0x004b81d6`
- `0x0f4243` immediate-byte occurrence count: one, at `0x004b81d8`

Raw reference scan results:

| Scan | Result |
| --- | --- |
| Little-endian VA `0x004b81a0` | 0 hits |
| Little-endian RVA `0x000b81a0` | 0 hits |
| `push 0x004b81a0` | 0 hits |
| Any VA dword in `0x004b81a0-0x004b81eb` | 0 hits |
| Superset rel8/rel32 branch or call to exact start `0x004b81a0` | 0 hits |

The only dword values that numerically decode as RVAs into the body were in `.text` instruction byte streams, not pointer tables:

- `0x004a6d6a => 0x000b81e8`, context `... 52 50 e8 81 0b 00 00 ...`
- `0x0050f577 => 0x000b81b4`, context `... 33 cd e8 b4 81 0b 00 ...`
- `0x0057dc7a => 0x000b81e8`, context `... ff 77 08 e8 81 0b 00 00 ...`

These are opcode/displacement byte coincidences, not data references to this helper. They do not justify an owner or emitter.

Control-flow contrast from the same scan:

- `0x004b81f0` has expected `E8` call hits from `0x0049c87c`, `0x0049c88f`, and `0x004dbcb5`.
- `0x004b8220` has the expected `E8` call hit from `0x004b0c0d`.
- `0x004b8290` has expected `E8` call hits from `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`.
- `0x004b81a0` has no comparable start reference.

This supports the existing conclusion that the no-reference condition is specific to `WideStringHashHelper`, not a scanning failure across the whole neighborhood.

## Dispatch And Reachability Review

Direct xrefs and callers remain absent. I also checked the obvious non-direct leads:

- Raw absolute VA and RVA references: none to the helper start.
- Raw pointer/table evidence: none to the helper start; the only in-range RVA-like dwords are instruction-byte coincidences.
- Relative branches/calls: no possible rel8/rel32 branch/call sequence to the exact helper start in the PE scan.
- Fallthrough from the previous range: blocked by `0xcc` padding from `0x004b8194-0x004b81a0`.
- Fallthrough to the next range: blocked by `0xcc` padding from `0x004b81eb-0x004b81f0`.
- Preceding RectBounds anchor helpers: their internal call surface is to `0x004b8290`, not to `0x004b81a0`.
- Following FileExists and BuildFieldMapPath helpers: both have their own callers and no documented or raw branch path into this body.
- Vtable/table adjacency: no vtable, RTTI, jump table, or data table currently points at this body.

No split or IDA function repair is required. C001 already performed the needed function creation and naming repair, and the current half-open range is clean.

## Documentation Evidence

Current docs reinforce the negative ownership result:

- [StringUtil](../../../../../by-file/StringUtil.md) is the best semantic candidate for a wide-string utility, but it now explicitly excludes `00022J`: wide-string hash semantics alone are not enough without callers, xrefs, raw pointer hits, table references, or source-family artifacts.
- [client_string_handling](../../../../../by-meta/client_string_handling.md) tracks broad string infrastructure, but it does not add a source-use context for this helper.
- [CachedHashTable](../../../../../by-file/CachedHashTable.md) is a separate fixed-entry hash/cache class island around `0x004c6160-0x004c659c`, with no construction caller evidence and no link to this standalone wide-string hash routine.
- [RectBounds](../../../../../by-file/RectBounds.md) owns the adjacent geometry helpers before and after the target, but the docs explicitly treat the hash/file/path helpers as unrelated intervening code.
- [PathUtil](../../../../../by-file/PathUtil.md) owns the successor `FileExists` helper because of its wide-path behavior and cross-subsystem callers; that evidence does not transfer backward to the hash helper.
- [FieldMapPane](../../../../../by-file/FieldMapPane.md) owns `BuildFieldMapPath` through a single constructor call at `0x004b0c0d`; it has no hash-helper use.

## Source-Use And Emitter Inventory

| Candidate emitter | Decision | Reason |
| --- | --- | --- |
| `0000OB` StringUtil | Reject for now | Best semantic family, but docs and raw evidence still lack any caller, source-use context, table pointer, or direct artifact. |
| `0000OA` StringBase | Reject | Target takes raw UTF-16 pointer input and lacks StringBase refcount, pool, sentinel, allocator, or object-layout behavior. |
| `0000HZ` CachedHashTable | Reject | Separate class/vtable/lifecycle island; no evidence that this helper is its hash routine. |
| `0000N2` RectBounds | Reject | Physical neighborhood only; helper is string hash code, not rectangle/layout code, and RectBounds xrefs route around it. |
| `0000MI` PathUtil | Reject | Successor file-existence helper is path utility code; target has no file/path behavior or caller relation. |
| `0000JA` FieldMapPane | Reject | Following path-stem helper has one FieldMapPane constructor caller; target has no constructor, map, or `.EPF` relation. |
| External/library-style utility | No route | The `1000003` recurrence is recognizable, but no source root or emitter can be created from algorithm similarity alone. |

No `EMITTER_UIDS` are justified. This is not a multiple-emitter pooled literal/shared-data case: there are no proven source-use contexts at all, let alone multiple contexts.

## Ownership/Emitter Decision

Keep `CANONICAL_OWNER:NONE`.

Keep `EMITTER_UIDS:` blank.

Rationale:

- Canonical ownership is semantic ownership. The helper has no object receiver, caller family, source-root anchor, table pointer, or source artifact tying it to a specific by-file or by-class owner.
- Emitter routing controls output. No candidate source root currently has a proven use or dependency that would require the helper to be emitted there.
- Routing this to `StringUtil` would overclaim from semantics only and would contradict the current `StringUtil` scope exclusion.
- Routing this to an adjacent file would confuse address locality with ownership.

## Exact Recommended Changes

No metadata/header change is recommended.

Retain the current metadata:

```text
*** UID:00022J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` change is required. If supervisor wants the retained row restated, keep this exact current text:

```text
    - [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md) 0x004b81a0-0x004b81eb | raw-function | WideStringHashHelper : reconstructable : 88% : strong : C001-009 defined the exact raw body as IDA function `WideStringHashHelper` after reconfirming the isolated `0x4b` prologue/body/return range, adjacent `0xcc` padding, `wcslen` plus `1000003` wide-string hash recurrence, no callers/xrefs/raw VA/RVA pointer/table reference, and normal xrefs to adjacent FileExists/BuildFieldMapPath/RectAnchor helpers. Parent remains blank because `StringUtil` is semantic only and no direct owner evidence is proven.
```

## Code-Entry Gate

Do not enter reconstruction C++ for this item now. The target is `88/92`, so completion is below the current `90/90+` code gate, and the required owner/emitter route is absent. The function is behaviorally understood, but source placement is not execution-ready.

## Comparison Against Prior B002 Report

The B002 post-migration report kept `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`. This second pass independently rechecked the live documentation, adjacent function ownership, and PE-level raw references. The new raw scan strengthens but does not change the prior outcome:

- No exact VA/RVA pointer to the helper start.
- No external rel8/rel32 branch/call to the helper start.
- Exact body and `1000003` multiply remain unique.
- Adjacent helpers still have normal xref/caller surfaces.
- Candidate source owners remain semantic or address-local only.

Before/after recommendation: no change, `88/92`.

## Open Risks And Blockers

- A future source-tree import or recovered symbol could prove the original helper belonged to `StringUtil` or a small utility file; current binary evidence does not.
- A future IDA database pass with richer instruction-boundary analysis could inspect the same raw dword coincidences, but current context already shows they are not pointer-table entries.
- If a real indirect call table or source-use context is later found, revisit `EMITTER_UIDS` first. `CANONICAL_OWNER` should remain `NONE` unless the source root is also semantically proven.

## Validation Notes

- Read and followed `Agent-B003/goal.md`.
- Reviewed prior B002 executed report as evidence, not as a binding conclusion.
- Reviewed current target page, current generated coverage rows, `by-structure.md` owner/emitter rules, adjacent memory pages, and candidate owner docs.
- Performed fresh PE/raw scans against `NexusTK.exe`.
- Did not edit `by-memory/-coverage-report.md`.
- Did not edit any by-* file, so no lease was required.

## Changed Files

- `tools/leaser/Agents/Agent-B003/research/00022J-WideStringHashHelper-second-pass.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00022J-WideStringHashHelper-second-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00022J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
