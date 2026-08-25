*** UID:0000IX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EditablePaperPane

## Status

- Confidence: strong for the class/module boundary, packet-opened paper behavior, vtable/adjustor evidence, resource dependencies, packet layouts, wrapper disposition, and false-anchor exclusions.
- Source module: `ui/dialogs/EditablePaperPane.cpp`
- Header: `ui/dialogs/EditablePaperPane.h`
- Projected reconstruction path: `NexusTK/ui/dialogs/EditablePaperPane.cpp`
- Main memory range: [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- Type docs: [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- Exact vtable data: [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md)
- Related support docs: [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md), [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md)

## File Role

`EditablePaperPane` is the packet-opened in-game paper document pane. It parses editable and read-only paper packets, builds a tiled `LINE001.EPD` paper frame, embeds a [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md), and serializes edited text back to the server with opcode `0x23`.

Keep this separate from [UID:0000OL][TextDialog](by-file/TextDialog.md). `TextDialog` is the NPC/message free-text dialog family, while `EditablePaperPane` owns item/paper document presentation, paper dimensions, line-break normalization, and the paper save packet.

Keep this separate from [UID:0000OQ][TextPad](by-file/TextPad.md). `TextPad` is a full-screen local text pad/editor with file command prefixes; `EditablePaperPane` is a server-packet paper UI.

## File Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `EditablePaperPane` | `0x00545170-0x00545e3b` | Main paper pane class, packet parsing, control setup, save serialization, draw hooks, and destructor thunks. |
| vtable family | [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md) | Primary dialog view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| paper-open adapters | [UID:000536][0x005128a0-0x005128fd.HandleEditablePaperPacket](by-memory/0x005128a0-0x005128fd.HandleEditablePaperPacket.md), [UID:000537][0x00512900-0x0051295d.HandleReadOnlyPaperPacket](by-memory/0x00512900-0x0051295d.HandleReadOnlyPaperPacket.md) | Exact retained file-static MapPane.cpp children; they allocate `0x280`, construct mode `0` or `1`, return true, and have zero inbound xrefs. They depend on this header but are not owned or emitted by this file. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00545170-0x00545217` | `EditablePaperPane::EditablePaperPane` | Constructs a modal `DialogPane`, installs three vtables, and dispatches mode `0` to editable parsing or mode `1` to read-only parsing. |
| `0x00545220-0x0054524b` | `OnControlCommand(int,int)` | Ignores the notify argument; control `0` saves in editable mode and closes the dialog. |
| `0x00545250-0x0054565b` | `InitializePaperContent` | Normalizes tabs to carriage returns, creates the close/action button and text edit control, sets limits, layout, parent, focus, and slide-open state. |
| `0x00545660-0x00545767` | `ParseEditablePacket` | Reads paper id, parsed-then-cleared reserved/status byte, width, height, text length, and multibyte text; converts to wide text. |
| `0x00545770-0x00545877` | `ParseReadOnlyPacket` | Reads read-only dimensions, centered flag, and text payload; converts to wide text. |
| `0x00545880-0x005459a7` | `SavePaperContent` | Reads text control content, converts carriage returns back to tabs, writes opcode `0x23`, paper id, length, and multibyte text. |
| `0x005459b0-0x00545d46` | `DrawBorder` | Loads `LINE001.EPD` frames `0..7` and tiles the border/corners. |
| `0x00545d50-0x00545dc1` | `DrawBackground` | Loads `LINE001.EPD` frame `8`, deflates the fill rect by the 16-pixel border, clears the overlay flag, and fills the interior. |
| [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) | adjustor thunks | Two real 0xb destructor adjustor thunks forwarding to `0x00545e00` with `this - 160` and `this - 164`. |
| `0x00545e00-0x00545e3b` | scalar deleting destructor | Calls `DialogPane` cleanup and conditionally deletes `this`. |

## Ownership Notes

- `MapPane::HandlePacket` constructs the pane for opcode `0x1b` in editable mode and opcode `0x35` in read-only mode.
- IDA and local PE scans confirm exact retained MapPane adapters UID000536 and UID000537. They allocate `0x280`, construct this class in mode `0` or mode `1`, return true, and have zero inbound xrefs. They are file-static MapPane.cpp children named `HandleEditablePaperPacket` and `HandleReadOnlyPaperPacket`, not `EditablePaperPane` methods; no active route is claimed.
- Recovered disabled row `0x0045004e` is not an `EditablePaperPane` method. IDA places it inside [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md), a binary-search/lower-bound helper with callers in the LodePNG helper island.
- The recovered disabled rows `0x00545ddd` and `0x00545de8` are real compiler adjustor thunks, not missing code; see [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md). The scalar deleting wrapper and both adjustors are compiler output caused by the implicit derived destructor, not handwritten source.
- 2026-05-26 IDA MCP recheck confirms `0x0045004e` is still an interior instruction of the LodePNG lower-bound helper, confirms the `EditablePaperPane` adjustor pair as `this - 0xa0` / `this - 0xa4` wrappers into `0x00545e00`, and confirms `TextPad` owns the only direct caller to `0x00595be0`.
- 2026-05-26 IDA MCP vtable recheck confirms the tertiary table at `0x00621b90` owns only `0x00545de8` and inherited `0x00544e90`; the following dword at `0x00621b98` begins adjacent `LINE001.EPD` string/data, not another paper-pane virtual.
- 2026-06-14 C001 IDA MCP recheck on session `b001_0003gy` confirms the main paper-pane functions and sizes: constructor `0x00545170` size `0xa7`, action/save dispatch `0x00545220` size `0x2b`, setup `0x00545250` size `0x40b`, editable/read-only parsers `0x00545660` and `0x00545770` size `0x107`, save sender `0x00545880` size `0x127`, border draw `0x005459b0` size `0x396`, background draw `0x00545d50` size `0x71`, adjustor thunks `0x00545ddd`/`0x00545de8` size `0xb`, and scalar deleting destructor `0x00545e00` size `0x3b`.
- The same pass confirms `0x00545e3b` is not a function, `0x0045004e` remains inside `sub_450030`, and the uncalled wrapper candidates `0x005128a0` and `0x00512900` are modeled `0x5d`-byte functions with zero xrefs to their own starts.
- `xrefs_to 0x00545170` reports four construction refs: two direct `MapPane` packet sites at `0x00508338`/`0x0050836b` and the two wrapper calls at `0x005128e5`/`0x00512945`. Vtable-head refs remain the constructor stores at `0x005451b7`, `0x005451bd`, and `0x005451c7`; `0x00621b98` is still `LINE001.EPD` data referenced by border/background drawing.
- 2026-06-16 A001 IDA MCP recheck on session `b001_mappane_0001AW_20260616` independently reconfirmed the same method sizes and boundary blockers: no function at `0x00545e3b`; constructor refs at `0x00508338`, `0x0050836b`, `0x005128e5`, and `0x00512945`; zero xrefs to wrapper starts `0x005128a0` and `0x00512900`; constructor vtable stores to `0x00621afc`, `0x00621b60`, and `0x00621b90`; `aLine001Epd` at `0x00621b98`; and `0x0045004e` as an interior address in LodePNG `sub_450030`.
- The same A001 pass checked `search_structs`/`type_query`/`entity_query` for `EditablePaperPane`, `Paper`, and `LINE001`. IDA exposes decorated `EditablePaperPane` vtable/RTTI names and `aLine001Epd`, but no UDT or source-facing paper field names. Historically this left `+0x26d` and wrapper placement open; the 2026-08-16 callback bounded the byte as parsed-then-cleared packet status and placed the exact zero-xref wrappers in MapPane.cpp.

## 2026-08-16 Source Route And Dependencies

- UID000048 owns the complete `EditablePaperPane.h` declaration: direct `DialogPane` inheritance, `PaperOpenMode`, exact virtual/private methods, typed tail, and `sizeof == 0x280` check. Its formal CPP supplies `#include "EditablePaperPane.h"` followed by `[[CHILDREN]]`.
- UID0001EE emits the complete authored definitions into `NexusTK/ui/dialogs/EditablePaperPane.cpp`. Its formal H is intentionally blank because declarations are centralized in UID000048.
- UID0002NC and UID0001XF are compiler-generated non-emitting evidence. UID0001EF is compiler-generated adjustor evidence. None emits raw vtable, RTTI, locator, adjustor, or scalar-wrapper source.
- CPP dependencies are `<string.h>`, `<wchar.h>`, `<windows.h>`, `TextButtonControlPane.h`, `TextEditControlPane.h`, `TextEditPane.h`, `LanguageMan.h`, `BackPane.h`, `Socket.h`, `EPFTileContext.h`, `ResourceLayoutTable.h`, and `MainUiLayerSlots.h`. The H adds only `DialogPane.h`.
- The emitted source preserves exact trusted packet-copy/CP_ACP behavior, signed tile arithmetic, localized ids `95/96`, mode-specific control limits and focus/selectability, overlay creation/show/slide order, save opcode `0x23`, and `LINE001.EPD` frame lookup/order. It uses inherited `GrafPort::m_visibleBounds`; no undeclared geometry member is introduced.
- The generated expectation is one complete class declaration in `EditablePaperPane.h` and exactly the eight authored definition families in `EditablePaperPane.cpp`, with no UID000048/UID0001XF/UID0002NC empty-emitter marker, raw ABI array, duplicate wrapper, or stale static/helper body.

## Score Rationale

Completion/confidence are `94/93`: the file now has a closed class/header owner, complete authored CPP emitter, exact dependencies, compiler-only data/support dispositions, bounded MapPane adapters, and deterministic generated expectations. Descriptive reserved-state naming and retained zero-xref adapters cap confidence without leaving an emitter or source-quality blocker.

## Cross-References

- [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md)
- [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md)
- [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md)
- [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md)
- [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md)
- [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-08-16 B001 implementation callback:
  - Raised `87/88 -> 94/93`; replaced proposal/blocker wording with the implemented UID000048 H and UID0001EE CPP route and exact dependency/generated-output contract.
  - Corrected `OnControlCommand`, implicit-destructor compiler output, target/type no-code ownership, and retained MapPane adapter placement while preserving all packet, resource, ABI, boundary, and historical evidence.

- 2026-06-18 B003 source-quality execution:
  - Before: `COMPLETION:86`, `CONFIDENCE:87`, with wrappers and final paper field/source names still treated as source-quality blockers.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`, with `+0x26d` documented as protocol/reserved status and the two no-route wrappers documented as MapPane-side factory wrappers.
  - Summary/evidence: B003 compared existing IDA-backed pages, prior MapPane wrapper audits, generated leads as secondary evidence, and local PE scans. The file now carries opcode `0x1b`/`0x35` inbound layouts, opcode `0x23` save layout, tab/carriage-return normalization, `LINE001.EPD` frame roles, and first-draft C++ readiness.

- 2026-06-14 C001 confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP session `b001_0003gy` reconfirmed all main method sizes, adjustor thunk/destructor boundaries, vtable-head constructor stores, the `LINE001.EPD` successor/data refs, direct `MapPane` packet construction sites, zero xrefs to the wrapper starts, and the false `0x0045004e` LodePNG ownership exclusion. Confidence stays at `85` because the two uncalled paper-open wrappers still need final source-owner placement.
- 2026-06-16 A001 support refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the same function sizes, constructor caller refs, zero-ref wrapper starts, vtable stores, `aLine001Epd` boundary, stale LodePNG exclusion, and absence of IDA UDT/source-facing paper field names. The support file route remains `NexusTK/ui/dialogs/EditablePaperPane.cpp`; completion stays capped by wrapper and final paper field/source-name blockers.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/dialogs/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page already proposed `ui/dialogs/EditablePaperPane.cpp`.
  - After: set the validator path to `NexusTK/ui/dialogs/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `EditablePaperPane.cpp` under `ui/dialogs`, and live IDA MCP lookup on 2026-06-05 confirms the main constructor anchor at `0x00545170` as a real function of size `0xa7`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: packet-opened paper pane role, function map, vtable/adjustor evidence, false LodePNG ownership exclusion, text-edit/resource dependencies, wrapper caveats, and cross-references are documented; confidence remains below maximum because the tiny uncalled paper-open wrappers still need final source placement.
