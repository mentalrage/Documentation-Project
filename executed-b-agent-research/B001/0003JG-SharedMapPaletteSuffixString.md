** TARGET-REPORT-UID:0003JG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003JG **
# B001 Research Report: UID 0003JG - SharedMapPaletteSuffixString

## Final Recommendation

Recommendation: keep `[UID:0003JG] by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md` parentless, reconstructable, and unchanged.

Confidence: 88/100 for the parentless/shared-literal outcome.

The best defensible inference is that `0x0061ea24-0x0061ea30` is an exact UTF-16 `.PAL` suffix literal emitted once in read-only data and shared by material code in both MapPane and WorldMapPane construction/resource-loading paths. It should not be assigned to `MapPane`, `WorldMapPane`, `Palette`, `PaletteLib`, a DAT/resource category, or the mixed split-index parent. No structural split or repair is required for this target.

Recommended supervisor action: no by-* documentation edit and no by-memory coverage-row edit are required. Close the B001-0003JG review as researched, retaining the current blank `AUTOGEN_PARENT_UID`.

If the supervisor wants an explicit no-op closure note, use this placement text in the existing target page's notes only if project policy requires it:

```text
B001 ownership review (2026-06-13): retain parentless status. IDA confirms `.PAL` has material direct xrefs from MapPane `sub_510960` at `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`; no debug/source metadata or narrower semantic owner proves a single source parent.
```

If the supervisor updates coverage status notes externally, keep the current row semantics:

```text
- [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) `0x0061ea24-0x0061ea30` | string-data | `SharedMapPaletteSuffixString` : reconstructable : 87% : very strong : Exact UTF-16 `.PAL` suffix shared by MapPane `sub_510960` refs `0x00510b57`/`0x00511041` and WorldMapPane constructor-family `sub_5C2AC0`; parent blank.
```

No recommended metadata changes:

```yaml
AUTOGEN_PARENT_UID:
AUTOGEN_RECONSTRUCTABLE: "true"
AUTOGEN_COMPLETION: 87
AUTOGEN_CONFIDENCE: 93
```

## Ranked Ownership Outcomes

1. Keep UID 0003JG parentless as a shared source-declared/generated-binary literal.
   - Confidence: 88/100.
   - Reason: the exact literal has direct, material references from both MapPane and WorldMapPane code, with no source/debug metadata proving one source file declared the shared copy. The parent blank is not an absence of analysis; it is the least misleading representation under the ownership rules.

2. Force-assign to existing MapPane file/class ownership.
   - Confidence if forced: 55/100.
   - Best forced existing owner: `by-file/MapPane.md` `[UID:0000L3]`, not `by-class/MapPane.md`.
   - Reason for limited plausibility: two of the three direct xrefs are in MapPane `sub_510960`, and the literal sits in the broader MapPane/world-map string island. Reason rejected: the WorldMapPane constructor-family reference is direct and semantically independent, not a trivial pass-through from MapPane.

3. Force-assign to existing WorldMapPane file/class ownership.
   - Confidence if forced: 43/100.
   - Reason for limited plausibility: `sub_5C2AC0` uses `.PAL` while constructing/loading WorldMapPane resources and then invokes palette-loading behavior. Reason rejected: MapPane has two material direct uses in its own resource-name construction path, and WorldMapPane already has separate constructor-owned resource strings elsewhere.

4. Assign to Palette/PaletteLib.
   - Confidence: 20/100.
   - Reason rejected: palette code consumes completed palette filenames or manages palette slots. This target is a caller-side filename suffix literal used before palette manager ownership begins.

5. Create a new source owner/file/category solely for shared suffix literals.
   - Confidence: 18/100 for this target.
   - Reason rejected: the evidence supports compiler/linker string pooling or shared source-declared literals, not a proven original source module. A future audit may model shared resource suffix literals as a non-source grouping, but that is not necessary or justified for this single target.

6. Assign to the mixed split index `[UID:0003IX] MapWorldPaletteResourceStrings`.
   - Confidence: 10/100.
   - Reason rejected: 0003IX is a non-emitting mixed by-memory index that records adjacent children with different ownership. It is not a direct semantic source parent.

## Scope Control

Assigned target researched: `[UID:0003JG] by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`.

Supporting context only:

- `[UID:0003JI] SharedWorldMap2UpperString`
- `[UID:0003IX] MapWorldPaletteResourceStrings`
- adjacent MapPane-only children `[UID:0003JH]` and `[UID:0003JJ]`

No broader structural repair is recommended. The supporting siblings confirm the existing split strategy rather than undermining it.

## Existing Documentation Review

Target page currently states:

- Range: `0x0061ea24-0x0061ea30`
- Reconstructable: true
- Confidence: 93
- Parent: blank
- Rebuild source type: `source-declared/generated-binary`
- Evidence: UTF-16 `.PAL`, direct xrefs from MapPane `sub_510960` at `0x00510b57` and `0x00511041`, and WorldMapPane constructor-family `sub_5C2AC0` at `0x005c2eae`.

This page is consistent with the live IDA evidence collected during this review.

Coverage currently lists 0003JG as a child row under the mixed string island:

- `by-memory/-coverage-report.md` row for 0003IX: non-reconstructable split index containing 0003JG/0003JH/0003JI/0003JJ.
- `by-memory/-coverage-report.md` row for 0003JG: reconstructable exact `.PAL` suffix, parent blank.
- `auto-generated/-ag-memory-coverage.md` marks 0003JG as unassigned with blank parent.

Those rows are consistent with the ownership inference and should not be repaired by assigning a parent.

## IDA Evidence

IDA database surveyed:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Architecture: x86 32-bit
- Relevant segment: `.rdata`, `0x0060d670-0x0066d000`
- Debug/source metadata search: no RSDS, NB10, PDB path, or source-path evidence found.

Exact bytes at the target:

```text
0x0061ea24: 2e 00 50 00 41 00 4c 00 00 00 00 00
```

IDA string interpretation:

```text
0x0061ea24: L".PAL"
```

The trailing two extra zero bytes are alignment before the next UTF-16 string at `0x0061ea30`. They do not require a separate child item.

Direct xrefs to `0x0061ea24`:

```text
0x00510b57 in sub_510960: push offset aPal ; ".PAL"
0x00511041 in sub_510960: push offset aPal ; ".PAL"
0x005c2eae in sub_5C2AC0: push offset aPal ; ".PAL"
```

The direct xref set is small, exact, and split across two already-modeled code areas:

- `sub_510960` belongs to the MapPane packet/resource-building path.
- `sub_5C2AC0` belongs to the WorldMapPane constructor-family path.

## MapPane Use

Function `sub_510960` has one direct caller from the MapPane dispatcher:

```text
sub_507C90 -> sub_510960 at 0x00507ffa
```

Relevant decompile evidence from `sub_510960`:

```c
wcscpy_s(Destination, 0x100u, (const wchar_t *)(this + 1758));
wcscat_s(Destination, 0x100u, aE);
wcscpy_s(v61, 0x100u, (const wchar_t *)(this + 1758));
wcscat_s(v61, 0x100u, L".PAL");
```

Later in the same function, IDA shows the same construction pattern again:

```c
wcscpy_s(v61, 0x100u, (const wchar_t *)(this + 1758));
wcscat_s(v61, 0x100u, aE);
wcscpy_s(v60, 0x100u, (const wchar_t *)(this + 1758));
wcscat_s(v60, 0x100u, L".PAL");
```

Inference:

- MapPane directly appends `.PAL` while constructing a palette filename from a map/resource base name.
- These are not incidental xrefs from a generic string table scanner.
- They prove MapPane is a real consumer, but not that MapPane is the single declaration owner of the shared emitted literal.

## WorldMapPane Use

Function `sub_5C2AC0` is the WorldMapPane constructor-family function documented under WorldMapPane ownership. It is called from MapPane's object/world-map helper and from another construction path:

```text
sub_511DB0 -> sub_5C2AC0 at 0x005126f9
sub_50F270 -> sub_5C2AC0 at 0x0050f2fa
```

Relevant decompile evidence from `sub_5C2AC0`:

```c
sub_582A90(v15 + 596);
sub_584470(&a3, L".PAL", 4u);
v31 = sub_584540((int)&a3);
v32 = sub_543D70(v31);
*(_DWORD *)(v64 + 456) = v32;
sub_582B70(&a3);
```

Inference:

- WorldMapPane directly uses the same `.PAL` literal to build/load a palette resource.
- The `sub_543D70` call is downstream palette loading; it does not make Palette/PaletteLib the source owner of the literal.
- The WorldMapPane use is inside its constructor/resource initialization path, not merely a MapPane comparison helper.

## Supporting Sibling 0003JI

`[UID:0003JI] SharedWorldMap2UpperString` at `0x0061ea48-0x0061ea50` was checked only as supporting context.

IDA string:

```text
0x0061ea48: L"WM2"
```

Direct xrefs:

```text
0x00512263 in sub_511DB0
0x005c5219 in sub_5C5200
```

`sub_511DB0` is the MapPane object-create/world-map helper. It compares object/map names against `wm`, `WM`, `wm2`, `WM2`, `wm3`, `WM3`, `wm4`, and `WM4`.

`sub_5C5200` is a WorldMapPane helper and directly pushes `L"WM2"` into a string helper while testing world-map regions.

Inference:

- 0003JI independently shows the same modeling pattern: adjacent data can be materially shared between MapPane and WorldMapPane.
- Its parentless status supports the current treatment of 0003JG.
- It does not prove that 0003JG should be repaired or assigned to a broader owner.

## Supporting Container 0003IX

`[UID:0003IX] MapWorldPaletteResourceStrings` covers `0x0061ea24-0x0061ea70` as a non-reconstructable split index.

Live IDA bytes decode to:

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

Direct xref pattern:

```text
0x0061ea24 L".PAL": sub_510960, sub_510960, sub_5C2AC0
0x0061ea30 L"wm":   sub_511DB0
0x0061ea38 L"WM":   sub_511DB0
0x0061ea40 L"wm2":  sub_511DB0
0x0061ea48 L"WM2":  sub_511DB0, sub_5C5200
0x0061ea50 L"wm3":  sub_511DB0
0x0061ea58 L"WM3":  sub_511DB0
0x0061ea60 L"wm4":  sub_511DB0
0x0061ea68 L"WM4":  sub_511DB0
```

Inference:

- The split index is doing useful work: it records one contiguous `.rdata` island whose children do not share a single semantic owner.
- MapPane-only children can be assigned to MapPane; shared children should remain parentless.
- 0003IX itself should remain non-reconstructable and should not become the `AUTOGEN_PARENT_UID` for 0003JG.

## Negative Ownership Evidence

### Against MapPane Assignment

MapPane is the strongest forced existing-owner candidate, but still below the assignment threshold.

Evidence against assignment:

- WorldMapPane `sub_5C2AC0` directly references the exact `.PAL` literal.
- `sub_5C2AC0` is documented under a separate `WorldMapPane.cpp` source model, not as a MapPane-local helper.
- The project structure guidance explicitly keeps `WorldMapPane.cpp` separate even though MapPane creates or triggers it.
- Two MapPane xrefs versus one WorldMapPane xref is a consumer-count fact, not a source-declaration proof.

### Against WorldMapPane Assignment

Evidence against assignment:

- MapPane `sub_510960` has two direct `.PAL` uses in its own packet/resource-loading path.
- MapPane owns adjacent MapPane-only comparison strings, proving the surrounding island is not exclusively WorldMapPane-owned.
- WorldMapPane already has separately modeled constructor-owned resource strings at `[UID:00035I] WorldMapPaneResourceStrings`; 0003JG is outside that local WorldMapPane resource string block.

### Against Palette/PaletteLib Assignment

Evidence against assignment:

- No direct xrefs from PaletteLib ownership functions to `0x0061ea24` were found.
- `sub_543D70` consumes a completed or constructed palette name, but the suffix is appended before that call.
- `by-file/Palette.md` and `by-file/PaletteLib.md` document palette managers, palette filename tables, slot constants, and loading behavior, not caller-owned resource naming literals.
- Assigning 0003JG to Palette/PaletteLib would confuse resource-consumer filename construction with palette-manager implementation.

### Against Resource/DAT Category Assignment

Evidence against assignment:

- The target is a source literal used to construct a resource name, not a packaged resource payload.
- The `.PAL` bytes here are not a palette file and not a DAT archive member.
- Resource names built with the suffix should stay with their caller/source owner when one exists; this suffix has two material caller/source owners.

### Against New Shared Source Owner

A new owner such as `MapWorldPaletteSuffixLiterals` or `SharedResourceSuffixLiterals` would be speculative.

Relevant supporting observation:

- Another nearby/common suffix literal, `.EPF` at `0x0061a44c`, is also shared by FieldMapPane, MapPane, and WorldMapPane construction/resource paths.
- This suggests common resource-suffix reuse or linker pooling, but it does not prove a source file or header that should own all suffix strings.

Reason no new owner is recommended:

- No source path, PDB record, or debug metadata names a shared suffix source module.
- The target can be accurately documented as parentless with direct xref evidence.
- Adding a new owner would create a modeled category broader than the evidence for this assigned item.

## Structural Split Review

The current split is correct:

- 0003JG starts exactly at `0x0061ea24`.
- It includes the UTF-16 `.PAL` text, its null terminator, and two bytes of alignment.
- The next child begins cleanly at `0x0061ea30` with `L"wm"`.
- The parent container 0003IX correctly remains non-emitting because it mixes shared and MapPane-only literals.

No child boundary repair is recommended.

No merge with 0003JI is recommended. `.PAL` and `WM2` have different semantics and different xref sets even though both are shared by MapPane and WorldMapPane evidence.

No promotion of 0003IX to a reconstructable owner is recommended.

## Source-Declaration Inference

No source/debug metadata was found:

```text
RSDS: not found
NB10: not found
PDB/source-path regex: no relevant source ownership hits
```

Raw-byte searches found many `.PAL` substrings throughout `.rdata`, mostly as parts of complete palette filenames. The standalone UTF-16 `.PAL` item immediately preceded by a string terminator/alignment and followed by the `wm` cluster is unique to this location.

Inference:

- The literal is reconstructable as a source-declared/generated-binary item because source code almost certainly used a wide suffix literal or equivalent static string.
- The binary does not preserve enough evidence to prove which source file emitted the single pooled copy.
- Under the B-agent ownership rules, the correct direct-parent action is to leave the parent blank rather than overfit to the most frequent or nearest consumer.

## Recommended Supervisor-Applied Changes

Required changes: none.

Do not edit:

- `by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md`
- `by-memory/0x0061ea24-0x0061ea70.MapWorldPaletteResourceStrings.md`
- `by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`

If a closure marker is needed outside by-* docs, record:

```text
B001-0003JG researched 2026-06-13: parentless status retained; no structural repair; no coverage row change.
```

## Validation Status

No by-* documentation, generated coverage, or coverage reports were edited by this agent. Therefore no documentation validator run was required for this report-only research output.

Created research report only:

```text
tools/leaser/Agents/Agent-B001/research/0003JG-SharedMapPaletteSuffixString.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003JG","source_path":"executed-b-agent-research/B001/0003JG-SharedMapPaletteSuffixString.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
