** TARGET-REPORT-UID:0003JI **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JI **
# 0003JI SharedWorldMap2UpperString Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep `[UID:0003JI] by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` parentless, reconstructable, and unchanged.
- Final disposition: exact UTF-16 `WM2` source-declared/generated-binary literal shared by material MapPane and WorldMapPane code; no single direct source parent clears the assignment gate.
- Required action: none. Do not edit by-* docs, generated coverage, or `by-memory/-coverage-report.md` for this target.
- Confidence: 87/100 for the no-parent/no-structural-repair recommendation.

The best defensible inference is that the original source likely referenced `L"WM2"` in both the MapPane object-create/world-map packet helper and a WorldMapPane special-region helper, with the compiler/linker emitting or pooling a single read-only literal at `0x0061ea48`. The binary proves real sharing but does not preserve enough source/debug metadata to prove a single declaration owner, a shared source file, or a new modeled source category.

If a supervisor closure note is desired, use this exact text as a no-op review note, not as a required by-* edit:

```text
B001 ownership review (2026-06-13): retain parentless status. IDA confirms uppercase UTF-16 `WM2` at `0x0061ea48` has material direct xrefs from MapPane `sub_511DB0` at `0x00512263` and WorldMapPane helper `sub_5C5200` at `0x005c5219`; no debug/source metadata, owner-only xref pattern, or modeled shared source file proves a single direct parent.
```

If the supervisor updates coverage notes externally, keep the current row semantics:

```text
- [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) 0x0061ea48-0x0061ea50 | string-data | SharedWorldMap2UpperString : reconstructable : 87% : very strong : Exact UTF-16 `WM2` literal shared by MapPane `sub_511DB0` and WorldMapPane helper `sub_5C5200`; parent blank.
```

No metadata changes are recommended:

```yaml
AUTOGEN_PARENT_UID:
AUTOGEN_RECONSTRUCTABLE: "true"
AUTOGEN_COMPLETION: 87
AUTOGEN_CONFIDENCE: 93
```

## Supporting Research

## Target

- Target UID: `0003JI`
- Target path: `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, row for `0003JI` marked `unassigned`.
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review` in `tools/leaser/Agents/Supervisor_notes.md`, work item `B001-0003JI`.
- Current scores and parent state: `COMPLETION:87`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, blank `AUTOGEN_PARENT_UID`.
- Address range: `0x0061ea48-0x0061ea50`.
- Payload: UTF-16 `WM2` plus terminator.
- Rebuild handling: `source-declared/generated-binary`.

## Executive Recommendation

Keep the exact child parent-blank. The item is not an unknown because it lacks research; it is a documented shared literal whose two direct consumers are both meaningful and already modeled under separate source modules.

Do not assign it to MapPane solely because it is adjacent to MapPane-only `wm`/`WM*` comparison literals. Do not assign it to WorldMapPane solely because the second xref is inside a WorldMapPane helper. Do not create a new shared source file for one pooled literal without stronger evidence such as a debug source path, a repeated shared-constant cluster, a header-like xref pattern, or more same-owner children.

The exact condition that would change the recommendation is new evidence proving original declaration ownership: PDB/source metadata, a linker map/object-file boundary, a source header/shared-constant cluster with multiple directly shared map-name literals, or a reconstructed source comparison showing a known original `WM2` declaration outside both consumer files.

## Supervisor Active Recheck

- Supervisor assignment: B001-0003JI, single target `[UID:0003JI] SharedWorldMap2UpperString`.
- Required supporting context: sibling `[UID:0003JG] SharedMapPaletteSuffixString` and split index `[UID:0003IX] MapWorldPaletteResourceStrings`.
- Split repair needed before final report: no.
- Source-bearing child in scope: the assigned exact child already exists, has precise bounds, and is separately documented.
- Direct edits to by-* docs or coverage reports: none performed.

## Inference Research Guidance Check

`by-structure.md` makes `AUTOGEN_PARENT_UID` a direct semantic ownership claim, not an output-routing shortcut. That rule blocks attaching 0003JI to whichever parent is more convenient for generated C++.

`inference_research.md` says address adjacency is weak without debug/source metadata and that string pooling or linker merging can make one emitted literal serve more than one original source reference. That rule is material here: `WM2` is physically adjacent to MapPane-only strings, but direct xrefs prove a separate WorldMapPane use.

Existing documentation was treated as a lead, not authority. Live IDA MCP was used to confirm bytes, decoded strings, xrefs, call chains, decompilation context, raw-byte uniqueness, and absence of debug/source metadata.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health` and `survey_binary` for active IDB and binary context.
- IDA MCP `get_bytes` and `get_string` for exact range content.
- IDA MCP `xrefs_to`, `trace_data_flow`, `insn_query`, `lookup_funcs`, `callees`, and `analyze_component` for access and call-chain evidence.
- IDA MCP `decompile` and `disasm` for the two direct consumer functions.
- IDA MCP `find_bytes` and `find_regex` for uniqueness and negative debug/source metadata checks.
- Existing documentation: target page, split-index page, MapPane/WorldMapPane file and class pages, MapPane packet-handler aggregate, WorldMapPane aggregate/resource pages, Palette/PaletteLib pages, proposed source tree, coverage rows, and supervisor notes.

The evidence is strong for bytes, xrefs, boundaries, and consumer roles. It is intentionally not strong enough for a single direct source parent because the binary has no PDB/source/linker-map metadata and no exclusive owner-only xref cluster.

## IDA MCP Facts

IDA session:

```text
Session: a001_goal2_0002UM
Input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
IDB: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
Image base: 0x00400000
MD5: 4247e04e20b65d6414c7238aa8ff5515
SHA256: 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
Segments: .text 0x00401000-0x0060d000 rx, .rdata 0x0060d670-0x0066d000 r
Hex-Rays ready: true
```

Exact bytes:

```text
0x0061ea48: 57 00 4d 00 32 00 00 00
```

IDA decoded string:

```text
0x0061ea48: L"WM2"
```

Neighboring decoded strings in `[UID:0003IX]`:

```text
0x0061ea24: L".PAL"
0x0061ea30: L"wm"
0x0061ea38: L"WM"
0x0061ea40: L"wm2"
0x0061ea48: L"WM2"
0x0061ea50: L"wm3"
0x0061ea58: L"WM3"
0x0061ea60: L"wm4"
0x0061ea68: L"WM4"
```

Direct xrefs to `0x0061ea48`:

```text
0x00512263 in sub_511DB0: mov ecx, offset aWm2_0 ; "WM2"
0x005c5219 in sub_5C5200: push offset aWm2_0 ; "WM2"
```

Function facts:

```text
sub_511DB0  0x00511db0 size 0x0a8a
sub_5C5200  0x005c5200 size 0x01d0
sub_5C48B0  0x005c48b0 size 0x0320
sub_5C3950  0x005c3950 size 0x04f1
sub_5C2AC0  0x005c2ac0 size 0x07ea
sub_507C90  0x00507c90 size 0x1176
```

Call-chain facts:

```text
sub_507C90 -> sub_511DB0 at 0x00508307
sub_511DB0 -> sub_5C2AC0 at 0x005126f9
sub_5C3950 -> sub_5C48B0 at 0x005c3bd8 and 0x005c3e2b
sub_5C48B0 -> sub_5C5200 at 0x005c4955 and 0x005c4acf
```

`analyze_component` facts:

```text
Shared global 0x0061ea48 aWm2_0 is accessed by sub_511DB0 and sub_5C5200.
sub_511DB0 -> sub_5C2AC0 is an internal edge in the MapPane-to-WorldMapPane creation path.
sub_5C48B0 -> sub_5C5200 is an internal WorldMapPane helper edge.
```

Raw-byte uniqueness checks:

```text
find_bytes "57 00 4D 00 32 00 00 00" -> only 0x0061ea48
find_bytes "77 00 6D 00 32 00 00 00" -> only 0x0061ea40
find_bytes "77 00 6D 00 32 00 00 00 57 00 4D 00 32 00 00 00" -> only 0x0061ea40
```

Debug/source metadata negative checks:

```text
find_bytes "52 53 44 53" (RSDS) -> 0 matches
find_bytes "4E 42 31 30" (NB10) -> 0 matches
find_regex "(?i)(\.pdb|RSDS|NB10|\.cpp|\.cxx|source|MapPane|WorldMapPane)" -> no PDB/source-path hits; only CRT resource text and RTTI names for FieldMapPane/MapPane/WorldMapPane.
```

## MapPane Consumer Evidence

IDA decompilation of `sub_511DB0` shows `WM2` in a wide-string comparison ladder:

```c
v29 = wcscmp(WideCharStr, L"wm2"); /*0x512236*/
if ( !v29 )                         /*0x51225d*/
  goto LABEL_42;
v30 = wcscmp(WideCharStr, L"WM2");  /*0x512276*/
if ( v30 )
{
  v31 = wcscmp(WideCharStr, L"wm3"); /*0x5122b6*/
  ...
}
```

The `wm2` and `WM2` branches share the same coordinate/region setup label:

```c
LABEL_42:
  v13[1] = 89;  /*0x5124d6*/
  *v13 = 220;   /*0x5124dd*/
  v13[3] = 110; /*0x5124e3*/
  v13[2] = 373; /*0x5124ea*/
  ...
```

Interpretation:

- This is a real MapPane-side consumer.
- The function is called by the MapPane dispatcher `sub_507C90`.
- The comparison group maps world-map string identifiers to coordinate/region records before creating or updating WorldMapPane state.
- Adjacent literals `wm`, `WM`, `wm2`, `wm3`, `WM3`, `wm4`, and `WM4` have only `sub_511DB0` xrefs and are correctly modeled as MapPane-only children.
- This evidence makes MapPane the best forced existing parent, but it does not erase the separate direct WorldMapPane helper use.

## WorldMapPane Consumer Evidence

IDA disassembly of `sub_5C5200` shows the exact direct reference:

```asm
0x005c5219: push offset aWm2_0 ; "WM2"
```

IDA decompilation represents that same pushed literal as the argument to a string helper in both display-mode branches:

```c
if ( !sub_5845B0(L"WM2") ) /*0x5c5256*/
{
  ...
}
...
if ( sub_5845B0(L"WM2") )  /*0x5c5319*/
  return 0;
```

`sub_5C5200` is reached only from `sub_5C48B0`:

```text
0x005c48b0 -> 0x005c5200 at 0x005c4955
0x005c48b0 -> 0x005c5200 at 0x005c4acf
```

`sub_5C48B0` is reached from `sub_5C3950`, a documented WorldMapPane draw/render method:

```text
0x005c3950 -> 0x005c48b0 at 0x005c3bd8
0x005c3950 -> 0x005c48b0 at 0x005c3e2b
```

Decompiled `sub_5C48B0` uses `sub_5C5200` to choose alternate marker/region drawing behavior:

```c
if ( !sub_5C5200((float *)this, a2, a3) ) /*0x5c4955*/
{
  result = sub_4E06A0(...);              /*0x5c4988*/
  *(_BYTE *)(this + 656) = 0;            /*0x5c498f*/
  return result;
}
*(_BYTE *)(this + 656) = 1;              /*0x5c49b0*/
```

Interpretation:

- This is a real WorldMapPane-side consumer.
- The WorldMapPane reference is not just MapPane passing packet data into a constructor.
- It is part of WorldMapPane's own special-region/hit-test/render behavior.
- Therefore assigning the exact literal to MapPane would misrepresent a direct WorldMapPane source dependency.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061ea48-0x0061ea50` | `0003JI` / `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` | Uppercase UTF-16 `WM2` literal | true | blank | 87/93 | Keep parentless |
| `0x0061ea24-0x0061ea70` | `0003IX` / `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` | Mixed split index | false | blank | 90/93 | No repair |
| `0x0061ea24-0x0061ea30` | `0003JG` / `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` | Shared `.PAL` suffix context | true | blank | 87/93 | Supporting only |
| `0x0061ea30-0x0061ea48` | `0003JH` / `by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md` | MapPane-only `wm`, `WM`, `wm2` | true | `0000L3` | 88/93 | Confirms split strategy |
| `0x0061ea50-0x0061ea70` | `0003JJ` / `by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md` | MapPane-only `wm3`, `WM3`, `wm4`, `WM4` | true | `0000L3` | 88/93 | Confirms split strategy |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061ea48` | `0x00512263` data xref in `sub_511DB0` | MapPane compares packet/local wide string against `WM2`. |
| `0x0061ea48` | `0x005c5219` data xref in `sub_5C5200` | WorldMapPane helper tests current/string state against `WM2`. |
| `sub_511DB0` | caller `sub_507C90` at `0x00508307` | MapPane dispatcher reaches the object-create/world-map helper. |
| `sub_511DB0` | callee `sub_5C2AC0` at `0x005126f9` | MapPane helper constructs or routes to WorldMapPane. |
| `sub_5C5200` | callers in `sub_5C48B0` at `0x005c4955` and `0x005c4acf` | WorldMapPane local helper calls the `WM2` special-region test. |
| `sub_5C48B0` | caller `sub_5C3950` at `0x005c3bd8` and `0x005c3e2b` | WorldMapPane draw/render path reaches the helper. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md` correctly records exact bytes, decoded `WM2`, two direct xrefs, and blank parent.
- Split-index page `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md` correctly models the range as mixed/non-emitting and routes only MapPane-only children to MapPane.
- `by-file/MapPane.md` and `by-class/MapPane.md` document `sub_511DB0` as MapPane object-create/world-map helper context and explicitly keep shared 0003JI parentless.
- `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` documents `sub_511DB0` as the MapPane bridge into WorldMapPane construction while keeping the construction target separate.
- `by-file/WorldMapPane.md`, `by-class/WorldMapPane.md`, and `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md` document WorldMapPane as a separate `map/WorldMapPane.cpp` implementation with local helper code around `0x005c5200`.
- `by-project-structure/proposed-source-tree.md` explicitly keeps `map/MapPane.cpp` and `map/WorldMapPane.cpp` separate.
- Executed B001 report `research/executed/0003JG-SharedMapPaletteSuffixString.md` is supporting context only. Its `.PAL` outcome is not assumed, but it confirms the same split index can contain shared children that should stay parentless.

Docs that were checked but do not justify reassignment:

- `by-file/Palette.md` and `by-file/PaletteLib.md` own palette-manager code and palette-loading policy, not map-name string identifiers such as `WM2`.
- `by-memory/0x00631490-0x00631528.WorldMapPaneResourceStrings.md` proves constructor-only WorldMapPane resource strings can be assigned to WorldMapPane, but 0003JI is outside that resource block and has a MapPane xref.
- Generated coverage marks 0003JI as unassigned, which is accurate for a confirmed reconstructable item with blank parent.

## Ranked Ownership Analysis

### 1. Keep 0003JI parentless as a shared source-declared/generated-binary literal

- Evidence for:
  - Live IDA confirms one exact UTF-16 `WM2` object at `0x0061ea48`.
  - Direct xrefs are split one-to-one between MapPane `sub_511DB0` and WorldMapPane `sub_5C5200`.
  - Both xrefs are semantically material, not stale strings or incidental table scans.
  - No PDB/source/debug metadata proves a source file.
  - `by-structure.md` requires direct semantic parentage, not convenient output routing.
  - Adjacent child split already separates MapPane-only strings from shared strings.
- Evidence against:
  - Address adjacency and the comparison ladder make MapPane a plausible forced owner.
  - WorldMapPane's use is only one direct xref.
- Decision:
  - Accepted. This is the least misleading source-ownership representation under the current evidence.

### 2. Force assignment to MapPane

- Evidence for:
  - `WM2` sits physically inside the MapPane/world-map comparison cluster.
  - `sub_511DB0` compares `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4`.
  - Adjacent siblings 0003JH and 0003JJ are MapPane-only and assigned to `by-file/MapPane.md` `[UID:0000L3]`.
  - `sub_511DB0` is called directly from the MapPane dispatcher.
- Evidence against:
  - `sub_5C5200` is a direct WorldMapPane helper consumer, reached through WorldMapPane's own `sub_5C48B0` and `sub_5C3950` call chain.
  - Consumer count is equal: one MapPane xref and one WorldMapPane xref.
  - Physical adjacency in `.rdata` is weak because string pooling and linker ordering can place shared or duplicated source literals together.
  - Assigning to MapPane would imply WorldMapPane merely consumes a MapPane-owned constant, but the binary does not prove that source relationship.
- Decision:
  - Rejected as an actual edit. If forced to choose an existing parent despite the evidence gap, MapPane is the best forced candidate at about 54/100 confidence because of the adjacent comparison cluster.

### 3. Force assignment to WorldMapPane

- Evidence for:
  - `sub_5C5200` is a WorldMapPane local helper and directly uses `WM2`.
  - The `WM2` test is part of WorldMapPane special-region/hit-test/render behavior, independent of packet parsing.
  - `WorldMapPane` class and file pages clear the `85/85` gate.
- Evidence against:
  - MapPane has an equally direct xref in `sub_511DB0`.
  - The literal is physically embedded in a mixed map/world-map name comparison cluster whose other source-bearing children are MapPane-owned.
  - WorldMapPane's assigned resource strings live in a separate constructor-only read-only-data block at `0x00631490-0x00631528`.
  - Assigning the shared `WM2` literal to WorldMapPane would orphan the MapPane comparison use from its own nearby literal set.
- Decision:
  - Rejected. Plausible as a consumer, not strong enough as the single declaration owner. Forced confidence: about 48/100.

### 4. Create a new shared source file, header, or grouping

- Proposed owner/name/path considered:
  - `map/WorldMapNameConstants.h`
  - `map/MapWorldStringConstants.cpp`
  - a non-source `SharedWorldMapNameLiterals` grouping
- Likely full contents if it existed:
  - Candidate: 0003JI `WM2`, because it is the only shared world-map-name literal in the current cluster.
  - Rejected for this grouping: 0003JH and 0003JJ, because IDA shows only MapPane refs.
  - Rejected for this grouping: 0003JG `.PAL`, because it is a resource suffix, not a world-map-name literal, and B001 already found no source-owner proof.
  - Rejected for this grouping: 0003IX, because it is a mixed split index, not a source unit.
- Evidence for:
  - A source header or shared string constant could explain a single pooled `WM2` object referenced from two source modules.
- Evidence against:
  - No debug/source metadata names such a header or source file.
  - Only one map-name literal is shared; the surrounding `wm`/`WM*` siblings are MapPane-only.
  - A standalone one-item source file/header would be over-modeled relative to the evidence.
  - Independent `L"WM2"` literals in `MapPane.cpp` and `WorldMapPane.cpp` pooled by the compiler/linker explain the same binary facts.
- Decision:
  - Rejected. Keep as parentless source-declared/generated-binary data rather than creating a speculative source owner.

### 5. Assign to split index 0003IX

- Evidence for:
  - 0003IX physically contains 0003JI and summarizes the mixed string island.
- Evidence against:
  - 0003IX is explicitly non-reconstructable and non-emitting.
  - It contains different ownership outcomes: MapPane-only children, shared `.PAL`, and shared `WM2`.
  - A mixed by-memory container is not a direct source parent.
- Decision:
  - Rejected.

### 6. Assign to Palette, PaletteLib, by-resource, by-type, or by-global

- Evidence for:
  - None strong. `WM2` is a literal identifier that participates in map/world-map logic.
- Evidence against:
  - No Palette/PaletteLib xrefs touch `0x0061ea48`.
  - `WM2` is not a palette filename, DAT payload, resource entry, enum table, global state object, vtable, RTTI record, or type declaration.
  - Existing Palette/PaletteLib docs concern render palette managers and palette filename/slot policy, not world-map identifiers.
- Decision:
  - Rejected.

## Negative Evidence Summary

- No RSDS or NB10 debug record bytes were found.
- No PDB path, source path, `.cpp`, `.cxx`, or linker-map-like string proves source ownership.
- IDA string-cache regex did not find `WM2`; raw byte search is the reliable evidence source for this UTF-16 literal.
- Address adjacency is not enough: adjacent `wm`/`WM*` strings are MapPane-only, while 0003JI has a direct WorldMapPane xref.
- Consumer xrefs prove use, not declaration. Here the xrefs are exactly balanced between two real consumers.
- The shared `.PAL` sibling supports the mixed-range split strategy but does not prove that every shared child has the same original owner.
- A new shared constants owner would need more than one shared literal or explicit source evidence; current evidence supports no such grouping.

## Structural Split Review

No structural repair is required.

- Start boundary is correct: `0x0061ea48` begins `57 00 4d 00 32 00 00 00`.
- End boundary is correct: `0x0061ea50` begins successor `wm3`.
- The previous child `0x0061ea40-0x0061ea48` cleanly contains lowercase `wm2`.
- The successor child `0x0061ea50-0x0061ea70` cleanly contains `wm3`, `WM3`, `wm4`, and `WM4`.
- The parent split index 0003IX should remain non-emitting and parent-blank.

No merge with 0003JH, 0003JJ, or 0003JG is recommended. They differ by semantics and xref sets.

## Final Recommendation

Exact changes applied or recommended:

- Applied: created this research report only.
- Recommended by-* changes: none.
- Recommended coverage-report changes: none.
- Recommended metadata changes: none.

Exact parent assignments recommended:

- Keep `AUTOGEN_PARENT_UID:` blank for 0003JI.
- Do not assign to `[UID:0000L3] MapPane`.
- Do not assign to `[UID:0000PB] WorldMapPane` or `[UID:0000G9] WorldMapPane`.
- Do not assign to `[UID:0003IX] MapWorldPaletteResourceStrings`.

Exact items left unassigned and why:

- `[UID:0003JI]` remains parentless because the exact literal is materially shared by MapPane and WorldMapPane helper code and the binary lacks source-owner evidence strong enough to privilege one consumer or create a new owner.

Future work outside this assignment:

- If a later source-layout audit finds a broader shared map-name constant cluster, revisit 0003JI with that evidence.
- If PDB/linker-map/source provenance is recovered, update ownership based on the direct compilation-unit evidence.

## Follow-Up Actions

Supervisor actions:

- Mark B001-0003JI researched/no-change.
- Leave by-* docs and coverage rows unchanged unless the supervisor wants to add the optional closure note.

A-agent actions:

- None required.

B001 future research actions:

- None for this target. The next ambiguous shared literal should be researched independently rather than inheriting this conclusion.

## Confidence

- Recommendation confidence: 87/100.
- Byte/xref fact confidence: very strong. IDA directly confirms bytes, string value, exact xrefs, and function locations.
- Ownership inference confidence: strong for "do not assign now," medium for original-source explanation because stripped binaries cannot prove whether this was one shared declaration or two pooled source literals.
- Remaining uncertainty: original compilation-unit ownership is not recoverable from the current binary evidence.

## Validator Results

- Commands run: none.
- Results: not applicable. This was a report-only research pass with no by-* documentation or coverage edits.
- Unresolved validator warnings/errors: none introduced by this report.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003JI-SharedWorldMap2UpperString.md`
- Modified: none outside the B001 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JI","source_path":"executed-b-agent-research/B001/0003JI-SharedWorldMap2UpperString.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
