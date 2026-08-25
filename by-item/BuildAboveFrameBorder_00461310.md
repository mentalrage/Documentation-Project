*** UID:0000U2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000577 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000577 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BuildAboveFrameBorder()
{
    if (g_useEpfAssets) {
        g_pAboveFrameTop = new AboveFrame(0, 0, 0);
        g_pAboveFrameLeft = new AboveFrame(1, 9, 0);
        g_pAboveFrameRight = new AboveFrame(2, 9, 0x328);
        g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328);
        return;
    }

    g_pLegacyAboveFrameTopLeft = new AboveFrame(0, 0x0c, 0x0e);
    g_pAboveFrameTop = new AboveFrame(1, 0x0c, 0x7d);
    g_pAboveFrameRight = new AboveFrame(2, 0x0c, 0x17a);

    for (int y = 0x5c, i = 0; y != 0x197; y += 0x3f, ++i) {
        g_pLegacyAboveFrameLeftSide[i] = new AboveFrame(3, y + 6, 0x0e);
        g_pLegacyAboveFrameRightSide[i] = new AboveFrame(4, y, 0x1a4);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BuildAboveFrameBorder 0x00461310

## Status

- Confidence: very strong for boundary, branch behavior, constructor/store xrefs, FrameChrome ownership, and one-identity-per-slot source; strong for inferred private spelling.
- Entity kind: free UI chrome helper/factory.
- Likely source module: [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- Parent attachment: [UID:0000JL][FrameChrome](by-file/FrameChrome.md). This is a file-level free helper that builds global frame-border chrome; it is not a member of [UID:000005][AboveFrame](by-class/AboveFrame.md).
- Exact range: `0x00461310-0x004615aa` (`0x29a` / 666 bytes, verified with `tools/int_convert.py`).
- Current IDA label: `BuildAboveFrameBorder` saved on 2026-06-16.

## Behavior

This helper allocates `AboveFrame` objects with `operator_new(0x134)` (`0x134` / 308 bytes, verified with `tools/int_convert.py`), calls the `AboveFrame` constructor, and stores the resulting pointers in the global frame-chrome slot family. Constructor argument order is `frameIndex, top, left`, not `frameIndex, left, top`.

Branch `byte_66DA97 == 1` creates the newer fixed frame set:

| Slot | Constructor arguments | Store site |
| --- | --- | --- |
| `g_pAboveFrameTop` / `0x0067a834` | `(0, 0, 0)` | `0x0046137d` |
| `g_pAboveFrameLeft` / `0x0067a83c` | `(1, 9, 0)` | `0x004613b5` |
| `g_pAboveFrameRight` / `0x0067a838` | `(2, 9, 0x328)` (`0x328` / 808) | `0x004613f0` |
| `g_pDynamicAboveFrame` / `0x0067a840` | `(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` (`0x4f` / 79, `0x328` / 808) | `0x00461428`; allocation-failure path at `0x00461441` stores zero |

The legacy branch creates the bottom/side frame set:

| Slot | Constructor arguments | Store site |
| --- | --- | --- |
| `g_pLegacyAboveFrameTopLeft` / `0x0067a848` | `(0, 0xc, 0xe)` | `0x0046148b` |
| `g_pAboveFrameTop` / `0x0067a834` | `(1, 0xc, 0x7d)` (`0x7d` / 125) | `0x004614c3` |
| `g_pAboveFrameRight` / `0x0067a838` | `(2, 0xc, 0x17a)` (`0x17a` / 378) | `0x004614fe` |
| `g_pLegacyAboveFrameLeftSide[]` / `0x0067a84c` | `(3, y + 6, 0xe)` | loop store at `0x0046154a` |
| `g_pLegacyAboveFrameRightSide[]` / `0x0067a860` | `(4, y, 0x1a4)` (`0x1a4` / 420) | loop store at `0x00461579` |

The legacy loop starts at `y = 0x5c` (`0x5c` / 92), increments by `0x3f` (`0x3f` / 63), and stops when `y == 0x197` (`0x197` / 407), giving five entries in each array.

The accepted names intentionally reuse `g_pAboveFrameTop` and `g_pAboveFrameRight` across the mutually exclusive EPF and legacy writes because each address is one physical source object. The older C++ used separate `TopLeft`/`LegacyLeft` and `TopRight`/`LegacyRight` identifiers for the same addresses; that would require duplicate definitions and is rejected. Allocation failure stores null into each destination exactly as the compiled allocation/constructor lowering does; source-shaped `new` preserves that behavior without adding extra aliases or cleanup.

The backing target [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md) is loader-zero file-static storage, not explicit `0xffffffff` sentinel data. Fixed pointers have no cleanup/read xrefs and remain program-lifetime state. The separate dynamic helper pair owns the only delete/recreate lifecycle.

## Evidence

- 2026-06-12 IDA MCP session `b001_nexustk`: `lookup_funcs 0x00461310` reports `sub_461310`, size `0x29a`, with the next documented helper beginning after the exclusive end boundary.
- 2026-06-12 `analyze_function`/`decompile 0x00461310` show repeated `operator_new(0x134)` calls followed by `AboveFrame::AboveFrame`, branch control on `byte_66DA97`, and the exact constructor argument/store sequence listed above.
- 2026-06-12 IDA MCP reports two direct callers from the map/game-server startup neighborhood at `0x004f7d10`, with call sites at `0x004f802c` and `0x004f8670`.
- 2026-06-12 xrefs confirm nine constructor calls from this function into `AboveFrame::AboveFrame`; the tenth constructor xref in the surrounding chrome island is from the dynamic recreate helper at `0x004615d0`, not from this factory.
- 2026-05-25 IDA xrefs show writes to the [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), including single pointer slots at `0x0067a834`, `0x0067a838`, `0x0067a83c`, `0x0067a840`, `0x0067a848`, and two five-entry pointer arrays starting at `0x0067a84c` and `0x0067a860`.
- 2026-05-26 IDA recheck confirms the function boundary `0x00461310-0x004615aa`, two call sites from `0x004f7d10`, and slot writes at `0x0046137d`, `0x004613b5`, `0x004613f0`, `0x00461428`, `0x00461448`, `0x0046148b`, `0x004614c3`, `0x004614fe`, `0x0046154a`, and `0x00461579`. The tenth `AboveFrame::AboveFrame` xref is from the dynamic recreate helper at `0x004615d0`, not this factory.
- 2026-06-16 C001 live IDA MCP `analyze_function 0x00461310` reconfirmed size `666`, two xrefs from `InitializeMainUiGraph` at `0x004f802c` and `0x004f8670`, only two direct callees (`sub_4610F0` and allocator `sub_4F4AA0`), the `byte_66DA97` branch, the new-mode slot stores, and the five-iteration legacy loop. Dry-run rename accepted `sub_461310 -> BuildAboveFrameBorder`; C001 applied the function label, saved the IDB, and post-save `lookup_funcs` verified the label.
- 2026-07-26 B004 read-only session `5a570ede` found the current function still modeled exactly at `0x00461310-0x004615aa`, size `0x29a`, but with current name `sub_461310`, declaration `int()`, and all four address/function regular/repeatable comment channels absent. A dedicated `BuildAboveFrameBorder` name-index query returned zero collisions. The supervisor Gate 2B recommendation restores the accepted name, `void __cdecl BuildAboveFrameBorder(void)`, and a function-repeatable behavior comment without changing bytes or boundaries.

## Naming Notes And Resolved Heuristics

- The accepted helper name is `BuildAboveFrameBorder`; the IDA label is saved and the body has only the frame-border construction role.
- `byte_66DA97` remains the project-wide EPF/legacy asset mode flag documented elsewhere as [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), so this helper should branch on `g_useEpfAssets`.
- Slot names in the C++ block are source-facing inferences selected after a complete address/geometry/collision audit. The final set is `g_pAboveFrameTop`, `g_pAboveFrameRight`, `g_pAboveFrameLeft`, `g_pDynamicAboveFrame`, `g_pLegacyAboveFrameTopLeft`, `g_pLegacyAboveFrameLeftSide`, and `g_pLegacyAboveFrameRightSide`. Exact private spelling is not recoverable, but raw/duplicate aliases are not permitted in final source.
- The dynamic input is resolved as [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md) field `+0x20`, `m_activeChildIndex`; `dword_67A874 + 0x20` is now only raw decompiler notation.
- B006's Rule 26 recheck keeps the tuple order as `(frameIndex, top, left)`. The old `(frameIndex, left, top)` heuristic is rejected because it would place observed constants such as `0x328` into the vertical coordinate slot, while the constructor stores the second argument into top and the third into left before computing right/bottom from the loaded resource dimensions.
- B007's Rule 26 report was reviewed on 2026-06-21 and adds no stronger replacement for this exact helper body. Its valid factory facts are already represented here: EPF-mode slots `0x0067a834/0x0067a83c/0x0067a838/0x0067a840`, legacy fixed slots and two five-entry arrays, constructor tuple order `(frameIndex, top, left)`, dynamic input from `g_pGeneralPurposePanel->m_activeChildIndex + 5`, FrameChrome file-helper ownership, and provisional source-facing slot names.

## Cross-References

- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:000005][AboveFrame](by-class/AboveFrame.md)
- [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md)
- [UID:0000PN][FrameChromeSlots](by-global/FrameChromeSlots.md)
- [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md)

## UID0000JL Accepted Split Incorporation - 2026-08-25

- Active source route: [UID:000577][AboveFrame](by-file/AboveFrame.md), source position `3`, after the class methods and before the dynamic release/recreate pair. The old FrameChrome route is retained only as historical umbrella evidence.
- Exact function range is `0x00461310-0x004615a9` (`0x29a` bytes). Direct startup calls at `0x004f802c` and `0x004f8670` prove this helper remains live in Main UI initialization.
- The helper performs nine direct `AboveFrame` constructions: four EPF-mode panes, or five source expressions in the legacy branch where the two five-iteration side loops construct ten side pieces. It writes the accepted five scalar slots and two fixed arrays while preserving indexes, coordinates, and active-child-derived dynamic frame selection.
- The formal CPP body remains human-shaped source rather than expanded allocation/decompiler output. Compiler allocation-failure behavior and internal alignment are covered by the compiled function, not emitted as extra helpers.

## Changes

- 2026-08-25 UID0000JL callback: rerouted owner/emitter from UID0000JL to UID000577, assigned source position `3`, and preserved the exact formal builder while adding current startup reachability and split-source placement.

- 2026-07-26 B004 UID0001P1 accepted implementation callback:
  - Changed `87/92 -> 93/95` and replaced every duplicate branch-specific alias with the accepted one-identity-per-physical-slot names.
  - Preserved the exact `0x29a` body, two startup callers, nine constructions, EPF/legacy tuples, five-iteration loop, allocation-failure null stores, constructor order, and direct FrameChrome route. Added loader-zero backing storage, fixed program-lifetime state, current IDA function/comment/collision prestate, and rejection of duplicate aliases without inventing cleanup or changing runtime behavior.

- 2026-06-20 B003 AboveFrame source-quality implementation:
  - Before: `86/91`; final C++ was withheld and the dynamic constructor input was still described as raw `dword_67A874 + 0x20`.
  - Changed to: `87/92`.
  - Summary/evidence: accepted source-quality pass resolves constructor argument order to `frameIndex/top/left`, identifies the dynamic input as `g_pGeneralPurposePanel->m_activeChildIndex + 5`, preserves FrameChrome ownership, and adds first-draft C++ limited to this exact factory body. The slot names in the code block are descriptive/inferred; the constructor arguments, loop bounds, and store topology are IDA-backed.

- 2026-06-20 B006 Rule 26 reconciliation:
  - Score unchanged.
  - Summary/evidence: independently rechecked the constructor tuple semantics and kept the first-draft helper body limited to this exact file-level factory. No ownership or emitter route changed.

- 2026-06-21 B007 Rule 26 report review:
  - Score unchanged.
  - Summary/evidence: B007's factory details were fully reconciled with the existing first-draft helper body and evidence tables. No code change was made because the current C++ already limits emission to this exact factory and keeps slot names descriptive/inferred.

- 2026-06-12 Batch 296 routing/evidence refresh:
  - Before: `80/86`, reconstructable but unassigned, with FrameChrome attachment deferred.
  - After: `85/90`, parent [UID:0000JL][FrameChrome](by-file/FrameChrome.md).
  - Evidence: live IDA MCP session `b001_nexustk` confirms `sub_461310` size `0x29a`, two startup calls from `sub_4F7D10`, nine constructor calls to `AboveFrame::AboveFrame`, branch-specific slot writes, and a five-iteration legacy side-piece loop. [UID:0000JL][FrameChrome](by-file/FrameChrome.md) already clears the direct-parent gate at `86/85`, and this item is a free file-level chrome factory rather than a class member.

- 2026-06-16 C001 safe IDA refresh:
  - Before: `85/90`, with strong behavior evidence but the IDA entry still named `sub_461310`.
  - After: raised to `86/91`, saved the low-risk `BuildAboveFrameBorder` IDA function label, and kept owner/emitter route through [UID:0000JL][FrameChrome](by-file/FrameChrome.md). Superseded on 2026-06-20: final C++ is now present on this child page, and the former raw dynamic input `dword_67A874 + 0x20` is resolved as `g_pGeneralPurposePanel->m_activeChildIndex`.
  - Evidence: IDA MCP `analyze_function`, `rename` dry-run/apply, `idb_save`, and post-save `lookup_funcs` on 2026-06-16.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, and stale generated-source state wording was removed.
  - Before: the frame-border factory was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned source that must be rebuilt, with parent attachment intentionally left blank because [UID:0000JL][FrameChrome](by-file/FrameChrome.md) still records medium confidence for the exact final source split.
  - Evidence: live IDA MCP confirms `sub_461310` at `0x00461310`, size `0x29a`, two direct callers in `sub_4F7D10`, and callees to the allocator at `0x004f4aa0` plus the `AboveFrame` constructor/helper at `0x004610f0`.

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented boundary, behavior, frame-slot writes, callers, and open naming questions but remained unevaluated.
  - After: score reflects documented factory behavior and frame-chrome ownership, with remaining completion limited by final helper/slot names.
  - Evidence: IDA notes confirm repeated `AboveFrame` construction, two startup callers, exact `0x00461310-0x004615aa` boundary, and writes to [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md).
