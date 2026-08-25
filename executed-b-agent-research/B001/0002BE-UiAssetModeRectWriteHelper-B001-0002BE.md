** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BE UiAssetModeRectWriteHelper Ownership Research

Revision: B001-0002BE, 2026-06-12

## Finalized Recommendation

- Target UID/path: [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Recommendation: keep [UID:0002BE] reconstructable, keep `AUTOGEN_PARENT_UID` blank, keep the current filename/range/title, and make no by-* documentation or coverage-report edits.
- Best current source-family inference: retained source-authored UI/resource layout helper, most plausibly MapName-side support code compiled near the `MapNamePane` island, but not safely assignable to `MapNamePane`, `MapPane`, `MiniMap`, `MiniMapButtonPane`, `MainMenuPane`, `RectBounds`, `StartupWindow`, or a new source file with current evidence.
- Split/repair decision: no split is needed. IDA and byte evidence support the exact half-open range `0x005030c0-0x00503104`, with `0xcc` padding before the sibling at `0x00503110`. The existing non-emitting aggregate [UID:00022Z] `UnreferencedUiResourceTextHelpers` remains the correct inventory container.
- Confidence: `92/100` for exact range and behavior, `88/100` for "source-authored project helper, not compiler/runtime/padding", `74/100` for the MapName-side source-family hypothesis, and only `45/100` for assigning a direct source parent today. This does not meet the ownership-assignment threshold.
- Supervisor action: no documentation application is required. If supervisor bookkeeping needs explicit no-op rows, keep the exact current rows listed in "Supervisor-Actionable Rows" below.

## Supporting Research

## Target And Assignment Context

Supervisor assignment B001-0002BE targets [UID:0002BE] `0x005030c0-0x00503104.UiAssetModeRectWriteHelper`, currently `reviewed-85-but-ownership-unknown-under-review`. Prior Batch310 raised the page to `87/91` but left the parent blank because no caller, pointer, branch, table, vtable slot, direct source-owner evidence, or emitting aggregate parent was proven.

This report treated existing documentation as hypotheses and refreshed the critical IDA/PE evidence before deciding whether B001 could infer a source owner or repair the split.

## IDA MCP Evidence

Live IDA MCP session: `b001_nexustk`, database path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.

Function-boundary checks:

| Address | IDA result |
| --- | --- |
| `0x00503060` | not a function |
| `0x005030bc` | not a function |
| `0x005030c0` | not a function |
| `0x00503104` | not a function |
| `0x00503110` | not a function |
| `0x005031e1` | not a function |
| `0x005031f0` | `sub_5031F0`, size `0xd3` |
| `0x00503350` | `sub_503350`, size `0x14f` |
| `0x005034a0` | `sub_5034A0`, size `0xd4` |
| `0x00503580` | `sub_503580`, size `0x9e` |
| `0x00503650` | `sub_503650`, size `0x42` |

Direct xrefs:

- `xrefs_to 0x00503060`: zero.
- `xrefs_to 0x005030c0`: zero.
- `xrefs_to 0x00503110`: zero.
- MapName vtable heads `0x0061e5b4`, `0x0061e600`, and `0x0061e630` have normal constructor/destructor/scalar-destructor store refs from `sub_5031F0`, `sub_5032D0`, and `sub_503840`; those refs do not point to the raw helpers.
- MiniMapButton vtable heads `0x0061e63c`, `0x0061e688`, and `0x0061e6b8` have normal constructor/cleanup/scalar-destructor store refs from `sub_503580`, `sub_503620`, and `sub_503900`; those refs do not point to the raw helpers.

Disassembly of the target range:

```asm
5030c0  push    ebp
5030c1  mov     ebp, esp
5030c3  sub     dword ptr [ebp+8], 1
5030c7  jnz     short loc_503100
5030c9  cmp     byte_66DA97, 1
5030d0  push    10h
5030d2  jnz     short loc_5030EC
5030d4  push    0A6h
5030d9  push    0
5030db  push    0
5030dd  push    dword ptr [ebp+0Ch]
5030e0  call    sub_4B7C50
5030e5  add     esp, 14h
5030e8  pop     ebp
5030e9  retn    8
5030ec  push    0ADh
5030f1  push    0
5030f3  push    0
5030f5  push    dword ptr [ebp+0Ch]
5030f8  call    sub_4B7C50
5030fd  add     esp, 14h
503100  pop     ebp
503101  retn    8
503104  align   10h
```

Behavior confirmed from IDA:

- First argument is decremented in place. Only the adjusted value zero path writes to the second argument.
- `byte_66DA97` selects the width: `0xa6` when current/EPF mode is active, `0xad` otherwise.
- `sub_4B7C50` is the shared `RectBounds` initializer, so the pushed values form `RectBounds(0, 0, 0xa6/0xad, 0x10)`.
- The helper has two `retn 8` exits at `0x005030e9` and `0x00503101`; the non-1 state path returns without writing the caller-provided output rectangle.

Signature and byte-search checks:

- `make_signature_for_range 0x005030c0-0x00503104` returned a unique exact-range signature for the 68-byte helper.
- `make_signature 0x005030c0` returned the unique wildcarded entry signature `55 8B EC 83 6D ? ? 75 ? 80 3D`.
- `find_bytes` found no absolute VA or RVA little-endian pattern for `0x00503060`, `0x005030c0`, or `0x00503110`.
- `find_bytes` found the wildcarded entry pattern only at `0x005030c0`.
- `find_bytes` found the EPF rectangle branch pattern only at `0x005030c9`.
- Scoped `search_text byte_66DA97` over `0x00503000-0x00503200` found only the sibling compare at `0x00503079` and the target compare at `0x005030c9`.

Section-aware PE scan:

- Parsed `NexusTK.exe` PE sections and scanned for absolute VA, RVA, `E8/E9 rel32`, `0F 8x rel32`, and short conditional branch encodings to `0x00503060`, `0x005030c0`, and `0x00503110`.
- Corrected section-mapped result: no hits for all three starts.
- A naive file-offset-to-VA scan briefly produced a false `0x00503110` rel32 hit; it was rejected because PE raw file offsets are not RVAs. The corrected section-aware scan is the evidence used here.

Nearby vtable data:

- Dumped `0x0061e5b4` onward. The MapName/MiniMapButton vtable region contains real slots for known methods such as `0x00503840`, `0x00503350`, `0x005034a0`, `0x0050380b`, `0x00503816`, `0x00503900`, `0x00503650`, `0x00503821`, `0x005036a0`, and `0x0050382c`.
- The same region contains no `0x00503060`, no `0x005030c0`, and no `0x00503110` slot.

## Documentation Evidence Checked

- [UID:0002BE] documents the exact raw helper, score `87/91`, parent blank, unique signatures, two `retn 8` exits, the `g_useEpfAssets` / `byte_66DA97` branch, `sub_4B7C50` rectangle writes, and the MapName-width association. IDA confirms these facts.
- [UID:00022Z] `UnreferencedUiResourceTextHelpers` is a non-emitting split inventory for [UID:0002BD], [UID:0002BE], and [UID:0002BF]. IDA confirms the child ranges and padding. It is not a source-emitting owner and should not be used as an autogen parent.
- [UID:0000L2] `MapNamePane` and [UID:00007P] `MapNamePane` now clear the numeric gate and own the modeled MapName constructor, render, update, cleanup, vtables, singleton, and resource strings beginning at `0x005031f0`. They do not contain direct refs, vtable slots, or table evidence for `0x005030c0`.
- [UID:0001AL] `MapNameAndMiniMapButtonPanes` explicitly warns not to absorb the preceding raw helper cluster into `MapNamePane` or `MiniMapButtonPane` without caller/vtable evidence. The live IDA checks support that warning.
- [UID:0000LE] `MiniMap` and [UID:00008B] `MiniMapButtonPane` own the modeled MiniMapButton constructor/paint/mouse/destructor island. Their vtables and resource strings do not reference the target.
- [UID:00022Y] `MainMenuAnsiTextDialogPacketHelpers` ends at `0x0050305c`; the `0x0050305c-0x00503060` padding boundary and the target behavior argue against merging this helper backward into MainMenu merely by address proximity.
- [UID:0000SW] `g_useEpfAssets` / `byte_66DA97` is a broad rendering/layout mode selector with hundreds of xrefs. Its read inside the target is behavioral evidence, not owner proof.
- [UID:00015S] `RectGeometryHelpers` identifies `sub_4B7C50` as a shared rectangle initializer with broad fan-in. Calling it does not imply `RectBounds` owns the helper.
- [UID:0000TN] `SurfaceRenderCallbackTable` is relevant to sibling [UID:0002BF], not to [UID:0002BE]; the target does not dispatch through `dword_69B3E8`.

## Ranked Ownership Candidates

### 1. Leave parent blank, keep [UID:00022Z] as non-emitting inventory

Recommendation rank: accepted.

Evidence for:

- Exact target behavior is reconstructable and the child clears the documentation gate at `87/91`.
- IDA and section-aware PE scans show no caller, start xref, raw pointer, absolute VA/RVA, relative branch/call, or nearby vtable slot to the target.
- The helper is source-shaped project code, but source ownership is not recoverable from current static evidence.
- [UID:00022Z] already models the three raw helpers as an inventory container without pretending to be a source file.

Evidence against:

- The helper is probably not random orphan code; it pairs strongly with sibling [UID:0002BD] and sits immediately before MapName/MiniMap code.
- Keeping the parent blank leaves useful source-family context unresolved.

Conclusion: best current documentation state. Do not attach an owner until a real code/table/source breadcrumb appears.

Confidence: `86/100`.

### 2. `MapNamePane` / `MapPane.cpp` private MapName-side UI helper

Recommendation rank: strongest semantic/source-family hypothesis, rejected as direct owner today.

Evidence for:

- The target and sibling [UID:0002BD] both choose `RectBounds(0, 0, 0xa6/0xad, 0x10)` from `byte_66DA97`.
- `0xad` is `173`, matching the documented MapName update clamp width in `sub_5034A0`; `0xa6` is a plausible EPF/current narrower variant.
- The raw cluster immediately precedes the modeled MapName constructor at `0x005031f0`.
- Sibling [UID:0002BF] has stronger MapName association through `this + 0x220`, matching the MapName font/resource pointer initialized by `sub_5031F0`.

Evidence against:

- No direct xref, call, table, branch, vtable slot, raw VA/RVA pointer, or source metadata points from MapName/MapPane to `0x005030c0`.
- The target has no `this`, no MapName field access, no `9X11FONT.BIN` access, and no `MAPNAME.EPF` literal.
- Following code is a mixed MapName/MiniMap island; adjacency alone is explicitly unsafe in this region.
- Assigning only the target to MapName would be weaker than assigning sibling [UID:0002BF], and even [UID:0002BF] remains parent-blank because live reachability is unresolved.

Likely contents if future evidence proves this source-family:

- [UID:0002BD] `UiAssetModeRectVirtualDispatchHelper`, [UID:0002BE] `UiAssetModeRectWriteHelper`, and [UID:0002BF] `WideGlyphResourceTextRendererRaw`.
- Potentially private helper code used by `MapNamePane` resource setup/render paths, centered text/glyph rendering, and legacy/current asset layout selection.
- The grouping should still resolve to `NexusTK/map/MapNamePane.cpp` or private code inside `MapPane.cpp`; current evidence does not justify a new independent `.cpp` file.

Conclusion: record as the leading source-family hypothesis, but do not use it as a parent assignment.

Confidence: `74/100` source-family, `45/100` direct owner.

### 3. New `MapNameUiResourceTextHelpers` or similar source/file parent

Recommendation rank: possible future documentation grouping, rejected now.

Evidence for:

- The three-child raw cluster is coherent: two mode-selected rectangle helpers plus one wide-glyph renderer.
- A local static helper group compiled before `MapNamePane` would explain why IDA has source-shaped code with no modeled entry refs.

Evidence against:

- No original source metadata, PDB/linker map, symbol, start xref, or table proves a standalone helper file.
- Existing [UID:00022Z] already provides a non-emitting documentation container without overclaiming source ownership.
- Creating a new source file today would turn a semantic grouping into an asserted source owner.

Conclusion: do not create. If future evidence proves a helper grouping, document it as MapName/MapPane-private unless a separate translation-unit breadcrumb appears.

Confidence: `52/100`.

### 4. `MiniMap` / `MiniMapButtonPane`

Recommendation rank: rejected.

Evidence for:

- The nearby island interleaves MapName and MiniMapButton modeled methods.
- MiniMapButton has resource-mode UI rendering code and vtable data in the same region.

Evidence against:

- Target behavior uses the MapName-width-associated `0xad`/173 and has no `MMAPBUT.EPF`, minimap singleton, MiniMapButton vtable, MiniMapButton resource string, or direct MiniMapButton method evidence.
- Live vtable and xref checks show no target slot or reference.

Conclusion: not defensible.

Confidence: `20/100`.

### 5. `MainMenuPane`

Recommendation rank: rejected.

Evidence for:

- The previous modeled/routed range before the raw helper cluster is MainMenu-related.

Evidence against:

- `0x0050305c-0x00503060` is `0xcc` padding after the MainMenu helper.
- The target's rectangle widths and following sibling evidence point toward UI resource/text helper code near MapName, not login/main-menu packet handling.
- No MainMenu caller/table/source reference reaches `0x005030c0`.

Conclusion: not defensible.

Confidence: `15/100`.

### 6. `RectBounds`

Recommendation rank: rejected.

Evidence for:

- The target calls `sub_4B7C50`, the shared rectangle initializer.

Evidence against:

- `RectBounds` is a generic data-structure initializer with broad fan-in; the caller-owned layout constants and asset-mode branch define this helper, not the callee.

Conclusion: dependency only.

Confidence: `10/100`.

### 7. `StartupWindow` / `g_useEpfAssets`

Recommendation rank: rejected.

Evidence for:

- The target reads `byte_66DA97`, whose canonical documentation is [UID:0000SW] `g_useEpfAssets`.

Evidence against:

- `byte_66DA97` is a broad global mode selector. The writer/owner of the global is not the owner of every layout helper that reads it.
- No StartupWindow function or data structure references the target start.

Conclusion: dependency only.

Confidence: `10/100`.

### 8. Compiler/runtime/padding

Recommendation rank: rejected.

Evidence for:

- IDA does not model the range as a function and there are no refs.

Evidence against:

- The bytes form a coherent MSVC-style helper with frame setup, branches, project globals, project calls, and two calling-convention epilogues.
- It is surrounded by explicit `0xcc` padding and neighboring source-shaped raw helper bodies.

Conclusion: source-authored project helper, not runtime, data, or padding.

Confidence: `5/100` for runtime/padding ownership.

## Disconfirming Evidence Summary

The missing direct-owner facts are not shallow omissions:

- No IDA function object at `0x005030c0`.
- No direct `xrefs_to 0x005030c0`.
- No raw little-endian absolute VA or RVA hits for `0x005030c0`.
- No section-aware PE-level relative call/jump or conditional branch target to `0x005030c0`.
- No nearby MapName/MiniMapButton vtable slot for `0x005030c0`.
- No caller was recovered through sibling helper starts.
- No string/resource literal, object field, singleton, or class vtable access in the target body.
- No debug/source metadata was found in prior B001-style source breadcrumb scans for this binary family, and nothing in this pass revealed one.

These negatives block direct source ownership even though the MapName-side semantic association is real.

## Repair And Validation Details

No by-* files were edited for this report.

No split is recommended:

- Target range starts at a prologue-like byte sequence at `0x005030c0`.
- Target exits at `0x005030e9` or `0x00503101`.
- `0x00503104-0x00503110` is alignment before the next raw helper.
- The current child page and aggregate already represent that split.

Validator dry-run:

_Executable command block removed from the research report; preserved in [0002BE-UiAssetModeRectWriteHelper-B001-0002BE-removed.md](0002BE-UiAssetModeRectWriteHelper-B001-0002BE-removed.md)._

## Supervisor-Actionable Rows

No coverage-report edit is required. Do not manually edit `by-memory/-coverage-report.md` for this B001 result.

If the supervisor wants explicit no-op row text, keep the current `by-memory/-coverage-report.md` child row exactly:

```text
        - [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 confirms no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and blank parent because no caller/table/source owner is proven.
```

Keep the current `auto-generated/-ag-memory-coverage.md` row exactly:

```text
| [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) | unassigned |  |  | no |  | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` |  |
```

Suggested supervisor note update after acceptance:

```text
| `0002BE` | `accepted-no-change` | Agent-B001 | B001-0002BE | `auto-generated/-ag-memory-coverage.md` | 0x005030c0-0x00503104.UiAssetModeRectWriteHelper | `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` | B001 found strongest source-family hypothesis remains retained MapName-side UI/resource layout helper, but live MCP, section-aware PE scan, raw byte searches, vtable bytes, and documentation review still find no caller/table/vtable/source-owner evidence; keep parent blank and preserve current rows. |
```

## Future Evidence That Would Change The Decision

The current no-change recommendation should be revisited only if one of these appears:

- A real call, branch, jump, raw pointer, vtable slot, callback table, or constructor-emitted reference to `0x005030c0`.
- Dynamic trace evidence showing a caller and receiver/source context for the helper.
- A recovered linker map, PDB, source path string, or compiler unit boundary tying the cluster to `MapNamePane.cpp`, `MapPane.cpp`, or a helper file.
- A reconstructed table that contains [UID:0002BD], [UID:0002BE], and [UID:0002BF] together and is itself owned by a gate-clearing source/class page.

Until then, leave [UID:0002BE] parent-blank and keep [UID:00022Z] as the non-emitting raw-helper inventory.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-B001-0002BE.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BE"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BE-UiAssetModeRectWriteHelper-B001-0002BE-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-B001-0002BE.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
