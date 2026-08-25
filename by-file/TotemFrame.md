*** UID:0000OV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TotemFrame

## Status

- Confidence: very strong for class behavior, direct Pane plus Singleton hierarchy, singleton/resource dependencies, one-definition order, exact resource-string child, and current `ui/panels` placement. Only original lexical spelling and historical header/source grouping remain unavailable.
- Proposed module: `NexusTK/ui/panels/TotemFrame.cpp`.
- Current recovered source: `source-3/simroot_v2/class_TotemFrame.cpp`
- Main address range: [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- Exact resource-string child: [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md)

## File Role

`TotemFrame` is a feature-specific frame pane for the totem/status UI. It directly inherits `Pane` and `Singleton<TotemFrame>`; compiler lowering of the empty Singleton base publishes and clears [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md). Its source body positions a 192-by-288 frame on the right side of the screen, loads `TOTFRAME.EPD`, and renders it using `NPAL7.PAL`. The frame index comes from [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md).

It shares frame-resource concepts with [UID:0000JL][FrameChrome](by-file/FrameChrome.md), but the resource family and callers are totem/status-specific enough that it should remain a separate file unless later evidence shows a shared original `Frame.cpp`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md) | `0x0069b35c` | Sole externally linked `TotemFrame *g_pTotemFrame = 0;` definition, emitted first at source position 10. The physical UID0002VR page is loader-zero backing and does not emit a duplicate. |
| [UID:0000F4][TotemFrame](by-class/TotemFrame.md) | `0x00598cc0-0x00598ecf` | Direct `Pane` plus `Singleton<TotemFrame>` class declaration, emitted after the global at position 20 with one `extern` declaration and method children. |
| [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) | `0x0069b4ec` | Status-pane singleton read by `TotemFrame::OnPaint` to select the totem frame. |
| [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) | string evidence at `0x0062e460` and `0x006152ec` | Totem frame image and palette resources. |
| [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md) | `0x0062e460-0x0062e480` | Class-local `TOTFRAME.EPD` source literal consumed only by `TotemFrame::OnPaint`; assigned to [UID:0000F4][TotemFrame](by-class/TotemFrame.md). |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction and placement | `0x00598cc0-0x00598d9e` | Initializes `Pane(0)` and direct `Singleton<TotemFrame>()`; compiler lowering publishes the complete object through the empty base at `+0xf8`. The source body initializes bounds `435,11,627,299` and attaches/registers the pane. |
| Ordinary cleanup | `0x00598da0-0x00598dc9` | Source destructor body is empty. Implicit `Singleton<TotemFrame>` destruction clears `g_pTotemFrame` before compiler/base output tail-calls `Pane::~Pane`. |
| Rendering | `0x00598dd0-0x00598e3b` | Gets a frame index from `OldUserStatusPane::GetSpiritId` and renders `TOTFRAME.EPD` with shared `NPAL7.PAL`. |
| Constructor EH/unwind support | `0x00598e40-0x00598e4b` | Clears singleton only from constructor-unwind metadata; do not emit as a source helper. |
| Adjustor thunks | `0x00598e4b-0x00598e56`, `0x00598e56-0x00598e61` | Destructor thunks for secondary subobjects at offsets `0xa0` and `0xa4`; compiler-generated. |
| Scalar deleting destructor | `0x00598e70-0x00598ecf` | Compiler wrapper over `TotemFrame::~TotemFrame()` plus optional MemoryMan-backed `operator delete`; do not hand-author. |

## B005 Source-Quality Route

B005's 2026-06-19 source-quality pass correctly routed the direct executable child through [UID:0000F4][TotemFrame](by-class/TotemFrame.md) while this file remains the final source path. The previous blank generated output was a formal-C++ omission on [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md), not evidence against reconstructability. Its handwritten constructor/destructor assignment model is superseded by the direct `Singleton<TotemFrame>` evidence below. Source C++ belongs to the direct-base constructor, empty ordinary destructor, and `OnPaint`; constructor-unwind clear helper, adjustor thunks, scalar deleting destructor, and Singleton lifecycle stores remain compiler output.

The pass validates source-facing helper names and rejected alternatives for the file route: `Pane::~Pane()` at `0x00544580` replaces generated `TextButtonExControlPane` pollution, MemoryMan-backed `operator delete(void*)` at `0x004f4ac0` is not feature-local, `g_pTotemFrame` and `g_pOldUserStatusPane` are the source global names, `OldUserStatusPane::GetSpiritId()` supplies the `TOTFRAME.EPD` frame index, `ResourceLayoutTable::LookupLayoutEntry` loads the resource entry, and shared `RenderTileFrame`/`NPAL7.PAL` are dependencies rather than file-owned payloads.

## One-Definition Source Order

The file emits one definition and one declaration route:

1. [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md), source position 10, emits `class TotemFrame;` followed by `TotemFrame *g_pTotemFrame = 0;`.
2. [UID:0000F4][TotemFrame](by-class/TotemFrame.md), source position 20, emits the complete direct-base class and `extern TotemFrame *g_pTotemFrame;`, followed by its children.
3. [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md) emits the constructor, empty destructor, and `OnPaint` method definitions through the class.
4. [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md) is false/non-emitting loader backing. It contributes evidence but no second definition or covered-by comment.

This order avoids both a duplicate physical-page definition and a class declaration that references an undeclared global.

## Direct Singleton Hierarchy And Lifecycle

- Live RTTI contains seven TotemFrame hierarchy entries and a direct `Singleton<TotemFrame>` base descriptor with PMD `{mdisp=0xf8,pdisp=-1,vdisp=0}` and attributes `0x40`.
- Both construction callers allocate exactly `0xf8` bytes. The Singleton base therefore occupies the one-past `+0xf8` address under MSVC empty-base optimization and adds no stored member.
- Construction initializes `Pane` first and `Singleton<TotemFrame>` second. The compiler-adjusted Singleton constructor publishes complete `this`; the null-adjust branch writes zero.
- Destruction runs in reverse: the implicit Singleton destructor clears the slot before `Pane::~Pane`. Constructor-EH cleanup and the scalar deleting wrapper repeat the same base/compiler responsibility.
- Human source therefore uses `Singleton<TotemFrame>()` in the initializer list and an empty ordinary destructor. Explicit `g_pTotemFrame = this` and `g_pTotemFrame = 0` statements would duplicate base behavior and misrepresent the original source shape.

## Complete Singleton Reference Inventory

The encoded absolute-address search found exactly 11 references to `0x0069b35c`; no RVA or raw-offset pointer representation was found.

| Instruction | Access | File-level role |
| --- | --- | --- |
| `0x004b8698` | read | General-purpose panel switch marks the frame for deletion. |
| `0x004b8768` | read | Second panel-switch path marks the frame for deletion. |
| `0x004b89c6` | read | Alternate panel switch marks the active child for deletion. |
| `0x00504ad2` | read | Map exit invokes the deleting virtual slot with flag `1`. |
| `0x00598d0e` | write | Compiler-lowered Singleton construction publishes complete `this`. |
| `0x00598d15` | write | Constructor adjustment fallback writes zero. |
| `0x00598dba` | write | Implicit Singleton destruction clears before Pane teardown. |
| `0x00598e40` | write | Constructor-EH Singleton destructor clears the slot. |
| `0x00598e90` | write | Scalar deleting wrapper clears through inlined Singleton teardown. |
| `0x005ba7e2` | read | UserStatusPane allocates `0xf8` and constructs on null, otherwise invalidates. |
| `0x005bf90c` | read | OldUserStatusPane performs the same construct-or-invalidate flow. |

## PE Backing And Source Boundary

- Executable SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- `.data` spans RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, and raw pointer `0x26ac00`. Raw-backed VA ends at `0x0067a800`; virtual data ends at `0x0069ce24`.
- The singleton slot is `0x20b5c` bytes beyond the raw-backed end. Its live four zero bytes hash to `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; zero is loader-supplied, not an encoded `0xffffffff` initializer.
- Source-authored file content is the global definition, direct-base class declaration, constructor body, empty destructor, and `OnPaint`. Vtable stores, base-pointer adjustment, Singleton publication/clear instructions, EH helper, adjustor thunks, and scalar deleting wrapper are compiler output.

## Historical Assumptions Superseded

- The former `0xffffffff` initialization claim is retained as history but disproved by PE raw/virtual bounds and live bytes.
- The former Pane-only declaration is retained as history but disproved by direct Singleton RTTI, PMD, allocation size, and construction/destruction order.
- The B005 handwritten singleton assignments are retained as an intermediate reconstruction but superseded by compiler-lowered direct-base behavior.
- The former reconstructable physical-slot route is retained as history but superseded by the sole semantic definition plus false/non-emitting physical backing.
- The exact original filename/header split and lexical symbol spelling are unavailable. `NexusTK/ui/panels/TotemFrame.cpp` and existing project naming are the highest-probability human-source choices; raw IDA names do not enter finalized source.

## Evidence Notes

- IDA MCP reports two direct constructor callers in the `0x005ba4a0` and `0x005bf7c0` old/new status-update feature neighborhoods.
- IDA MCP confirms `TotemFrame::OnPaint` reads `0x0069b4ec` and calls `0x005bdc60`, now documented as `OldUserStatusPane::GetSpiritId`.
- Generated `SpellOneArgInputPane.cpp` checks `g_pTotemFrame` and marks it for deletion, showing cross-feature lifecycle coupling.
- `OnPaint` loads `TOTFRAME.EPD` through `g_pEPFLib` and uses `NPAL7.PAL`.
- IDA confirms omitted cleanup body `0x00598da0`, singleton clear helper `0x00598e40`, and adjustor thunks `0x00598e4b` and `0x00598e56`.
- 2026-05-28 IDA MCP boundary recheck confirms `TotemFrame` code ends at `0x00598ecf`; `0x00598ecf-0x00598ed0` is one `0xcc` alignment byte, then `0x00598ed0` starts [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md).
- 2026-06-12 A003 live IDA MCP session `a001-b276` reconfirmed `TOTFRAME.EPD` at `0x0062e460` with exactly one xref, `0x00598e05`, inside `TotemFrame::OnPaint`; decompilation shows the `OldUserStatusPane::GetSpiritId` result passed as the frame index before drawing with shared `NPAL7.PAL`.
- 2026-06-12 `xrefs_to 0x006152ec` returned ten palette refs, so `NPAL7.PAL` remains a shared old-HUD/status palette dependency instead of TotemFrame-owned private data.
- 2026-06-19 B005 local PE byte audit confirms internal padding at `0x00598d9e-0x00598da0`, `0x00598dc9-0x00598dd0`, `0x00598e3b-0x00598e40`, and `0x00598e61-0x00598e70`. B005 also rechecked the generated-output issue and concluded the prior zero-byte `TotemFrame.cpp` output was caused by blank formal C++ on [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md), not by lack of source reconstructability.

## 2026-06-14 IDA MCP Refresh

- `lookup_funcs` reconfirms constructor `0x00598cc0` size `0xde` / 222 bytes (Verified with `int_convert.py`), cleanup `0x00598da0` size `0x29`, paint `0x00598dd0` size `0x6b` / 107 bytes (Verified with `int_convert.py`), singleton clear `0x00598e40` size `0x0b`, adjustor thunks `0x00598e4b` and `0x00598e56` size `0x0b` each, scalar deleting destructor `0x00598e70` size `0x5f`, non-function boundary `0x00598ecf`, and successor `TransferServerDialogPane` function `0x00598ed0`.
- `xrefs_to 0x00598cc0` still reports the two construction callsites at `0x005ba809` and `0x005bf933`; `xrefs_to 0x00598da0` remains empty, matching cleanup-only/unwind-like use.
- `xrefs_to 0x0069b35c` returns 11 `g_pTotemFrame` lifecycle and consumer refs, including constructor stores, cleanup/destructor clears, the two construction neighborhoods, and external user/status cleanup checks. `xrefs_to 0x0069b4ec` returns nine old-status-pane singleton refs, with the TotemFrame paint read at `0x00598dec`.
- `get_bytes` reconfirms `0x0062e460` as UTF-16 `TOTFRAME.EPD` followed by the successor RTTI boundary, and `0x006152ec` as UTF-16 `NPAL7.PAL`. `xrefs_to` still reports exactly one `TOTFRAME.EPD` ref at `0x00598e05` and ten `NPAL7.PAL` refs, with the TotemFrame palette use at `0x00598e11`.
- `callees` confirms construction uses pane/bounds helpers, paint calls the status-pane frame-index helper `0x005bdc60` plus EPF/GrafPort draw helpers, and scalar deletion calls pane cleanup/delete support. The existing `0xc0`/192 by `0x120`/288 frame dimensions were rechecked with `int_convert.py`.

## Cross-References

- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)
- [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- 2026-05-28 boundary correction:
  - What existed before: file documentation used the memory range `0x00598cc0-0x00598ece`.
  - Changed to: file documentation uses `0x00598cc0-0x00598ecf`, with `0x00598ecf-0x00598ed0` treated as padding.
  - Summary/evidence: IDA MCP reports `sub_598E70` as ending at `0x00598ecf` and shows `0x00598ed0` as the next TransferServerDialogPane function start.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers totem/status frame role, proposed contents, singleton/status-pane dependencies, method families, IDA evidence, resource refs, boundary correction, and cross-references; confidence remains capped by final feature-folder placement.
- 2026-05-31: Assigned validator reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `TotemFrame.cpp` under `ui/panels`; IDA MCP confirms the compact `0x00598cc0-0x00598ecf` TotemFrame range and status-pane/totem ownership.
- 2026-06-12 A003 Batch 295:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`, with resource evidence summarized only through the resource page.
  - After: `COMPLETION:85`, `CONFIDENCE:85`, retaining `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Why: live IDA MCP reconfirmed the sole `TOTFRAME.EPD` source-literal xref from `TotemFrame::OnPaint`, the `OldUserStatusPane::GetSpiritId` frame-index path, shared `NPAL7.PAL` fanout, and the exact [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md) child now assigned through the class parent. Remaining uncertainty is final old-status/totem grouping, not this file's current `ui/panels` ownership.
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `87/88`.
  - Summary/evidence: live IDA MCP reconfirmed exact function boundaries, two constructor callers, `g_pTotemFrame` and `g_pOldUserStatusPane` xref counts, `TOTFRAME.EPD` one-xref ownership, shared `NPAL7.PAL` fanout, successor boundary, and paint callee path through `OldUserStatusPane::GetSpiritId`. No owner/emitter routing changed; final old-status/totem source grouping remains the main blocker to a higher score.
- 2026-06-19 B005 source-quality execution:
  - Score unchanged at `87/88`.
  - Added class-owned direct route guidance for [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md), corrected method-family half-open ranges, and recorded that first-draft source C++ is now ready for the constructor, ordinary destructor, and `OnPaint` on the memory page.
  - Summary/evidence: B005 checked current docs, exported function data, cached vtable data, generated report leads, and local PE bytes after IDA MCP was unavailable. Remaining uncertainty is limited to exact Pane wrapper spellings, spirit-to-frame semantics, and DAT/archive provenance, which are broader support issues rather than blockers for this file route.
- 2026-07-23 B003 direct-Singleton implementation callback:
  - Before: `COMPLETION:87`, `CONFIDENCE:88`; active file prose used a Pane-only/handwritten singleton lifecycle model and did not define the one-definition source order.
  - Changed to: `COMPLETION:92`, `CONFIDENCE:94`, preserving `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`; documented the sole position-10 global definition, position-20 direct-base class declaration, corrected method source, and false/non-emitting physical backing.
  - Summary/evidence: live PE bounds/bytes prove loader-zero initialization; exact operand search closes the 11-reference inventory; direct Singleton RTTI PMD `+0xf8`, seven-entry hierarchy, `0xf8` allocation, constructor/EH order, and reverse destruction resolve lifecycle source shape. Existing resource, caller, boundary, helper-name, and compiler-support evidence remains preserved, while the disproved `0xffffffff`, Pane-only, handwritten-assignment, and reconstructable-physical interpretations are retained as superseded history.
