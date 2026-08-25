*** UID:0000JA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FieldMapPane

## Status

- Confidence: very strong for the standalone map source route, complete authored and compiler-generated inventory, exact class/entry layouts, method/vtable anchors, helper ownership, dependency contracts, and padding boundaries. The retained raw rectangle helper has no live caller, but its complete source-shaped body and FieldMap-only layout make its source disposition implementation-ready.
- Proposed module folder: `NexusTK/map/`
- Source files: `NexusTK/map/FieldMapPane.cpp` and required sibling `NexusTK/map/FieldMapPane.h`.
- Evidence basis: live IDA MCP checks on 2026-06-04 and 2026-06-14, existing exact memory pages, and `by-project-structure/proposed-source-tree.md`.

## Hypothesis

`FieldMapPane` is a smaller map-related selection/render pane. It initializes field metadata, handles field-entry mouse and keyboard selection, renders selectable field entries with labels, and sends the selected field-map request packet. Its name and behavior are map-domain specific, but it is smaller and more UI-control-like than `MapPane`.

Likely original placement:

```text
map/FieldMapPane.cpp
```

Superseded historical alternative, retained for provenance only:

```text
ui/dialogs/FieldMapPane.cpp
```

## Proposed Contents

| Entity | Current range | Role |
| --- | --- | --- |
| `FieldMapPane` | `0x004b0bb0-0x004b129b` | Field-entry map pane with mouse/keyboard selection and rendering. |
| `BuildFieldMapPath` | `0x004b8220-0x004b8284` | File-local helper that copies the constructor source path stem into `FieldMapPane::m_fieldMapEpfPath[0x80]`; the constructor appends `.EPF` and uppercases the completed path through `CharUpperBuffW`. |

## Method Summary

| Address | Current name | Summary |
| --- | --- | --- |
| `0x004b0bb0` | constructor | Initializes pane state, builds the `.EPF` path, and copies field metadata into the local entry table. |
| `0x004b0d30` | `HandleMouseEvent` | Hit-tests entries and dispatches a field-map request for the clicked entry. |
| `0x004b0e50` | `HandleKeyEvent` | Handles navigation, submit, and cancel actions. |
| `0x004b0fb0` | `RenderFieldEntries` | Renders field entries, selected highlight, and labels. |
| `0x004b1130` | `CalculateFieldItemRect` | Retained private helper that calculates an entry rectangle from label extent, line height, and field-entry center coordinates; formal C++ belongs to UID 000150, but IDA currently has code bytes with no function object or xrefs. |
| `0x004b11a0` | `SendFieldMapRequest` | Builds and sends the `0x3f` field-map request packet from selected-entry fields `requestFieldId`, `requestX`, and `requestY`, then marks the request in flight. |
| `0x004b1242` / `0x004b124d` | adjustor deleting destructors | `-0xa0` / `-0xa4` adjustor wrappers into the scalar deleting destructor. |
| `0x004b1260` | scalar deleting destructor | Runs destructor/base cleanup and conditionally frees storage. |

## Live IDA Evidence

IDA MCP checks on 2026-06-04 confirm:

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Real function map: constructor `0x004b0bb0-0x004b0d2b`, mouse handler `0x004b0d30-0x004b0e50`, key handler `0x004b0e50-0x004b0f1b`, render method `0x004b0fb0-0x004b112a`, request helper `0x004b11a0-0x004b1242`, adjustor thunks `0x004b1242-0x004b124d` and `0x004b124d-0x004b1258`, scalar destructor `0x004b1260-0x004b129b`, and path helper `0x004b8220-0x004b8284`.
- `0x004b1130` remains raw code, not an IDA function: it has no containing function, no current xrefs, and begins with a normal helper-shaped prologue (`55 8b ec 0f bf 45 08 ...`). Keep it documented and emitted from [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) as retained `FieldMapPane::CalculateFieldItemRect` source, but do not claim it is live-called.
- Constructor vtable stores: `0x004b0bf3 -> 0x0061a3c8`, `0x004b0bf9 -> 0x0061a414`, and `0x004b0c03 -> 0x0061a444`.
- Vtable slots: `0x0061a3c8 -> 0x004b1260`, `0x0061a414 -> 0x004b1242`, `0x0061a444 -> 0x004b124d`, `0x0061a40c -> 0x004b0fb0`, `0x0061a418 -> 0x004b0d30`, and `0x0061a41c -> 0x004b0e50`.
- Request helper callers are all FieldMap methods: `0x004b0dfe` in the mouse handler and `0x004b0ea7`/`0x004b0f0e` in the key handler.
- Path helper caller is the constructor at `0x004b0c0d`; `0x004b8220` still ends at `0x004b8284`, followed by `0xcc` padding.
- Boundary padding is confirmed at `0x004b0ba5-0x004b0bb0`, `0x004b129b-0x004b12a0`, and `0x004b8284-0x004b8290`.

## 2026-06-14 C001 IDA MCP Refresh

Current IDA MCP health reports `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. The refreshed checks support a higher file-level score while preserving the raw-rectangle-helper caveat.

- `lookup_funcs` reconfirms modeled starts and sizes: constructor `0x004b0bb0` size `0x17b`, mouse handler `0x004b0d30` size `0x120`, key handler `0x004b0e50` size `0xcb`, render method `0x004b0fb0` size `0x17a`, request helper `0x004b11a0` size `0xa2`, scalar destructor `0x004b1260` size `0x3b`, path helper `0x004b8220` size `0x64`, and unrelated successor `0x004b12a0` size `0x94`.
- `lookup_funcs` still reports `0x004b1130` as not a function, and `xrefs_to 0x004b1130` still returns no refs, so no IDA function-definition change is safe.
- `analyze_component` reconfirms internal edges `0x004b0bb0 -> 0x004b8220`, `0x004b0d30 -> 0x004b11a0`, and `0x004b0e50 -> 0x004b11a0`; the request/path helpers remain FieldMap-local by caller evidence.
- `xrefs_to 0x004b11a0` reconfirms exactly three refs from the mouse/key handlers at `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`; `xrefs_to 0x004b8220` reconfirms the constructor-only ref at `0x004b0c0d`.
- `analyze_function 0x004b11a0` decompiles the request as opcode `0x3f` / decimal `63` (Verified with `int_convert.py`), three 16-bit serialized fields from a `0x94`-byte field-entry record, decimal `7` / hex `0x7` bytes sent (Verified with `int_convert.py`) through `0x00574bb0`, and a request-in-flight byte set afterward.
- `analyze_function 0x004b8220` decompiles the path helper as a wide path-stem copy: scan backward for decimal `46` / hex `0x2e` period (Verified with `int_convert.py`), `memmove` the stem, and write a wide NUL terminator.
- 2026-06-27 B006 implementation callback accepts [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md) as source-ready. Live IDA MCP session `80de0a67` reconfirms the same three FieldMap-only callers, exact `0x004b11a0-0x004b1242` range, boundary bytes against the next adjustor thunk, unique range signature, opcode `0x3f`, seven-byte send, request-in-flight byte, and no direct little-endian pointer-pattern hits for `0x004b11a0`, `0x004b1130`, or `0x004b0bb0`. Packet helper names are resolved through support docs as `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `Socket::QueueAndSendPacket`; `dword_67A7EC` is `g_packetSender`. Entry request fields are `requestFieldId` at `+0x8a`, `requestX` at `+0x90`, and `requestY` at `+0x8c`.
- 2026-06-27 B006 source-quality callback accepts [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) as source-ready retained helper code. Live IDA MCP session `398b87c1` preserves the no-function/no-live-caller facts, exact pre/post padding and `ret 8` boundary, unique concrete range signature, text-helper refs to raw/mouse/render sites, and PE-aware no direct edge/pointer hits. The helper computes `RectBounds` from `m_fieldEntries[entryIndex]`, `centerY`, `centerX`, `label`, `GetTextWidth`, and `GetLineHeight`; mouse/render duplicate the formula inline rather than calling `0x004b1130`.

## Boundary Cautions

- Some neighboring helper names in older notes point at fitting-room or ranking-event classes, but the FieldMap-owned evidence is the vtable/request/path-helper data listed above. `0x004b95e0-0x004b9767` is documented as shared GrafPort draw-state/clip helpers, and `0x004ba9a0-0x004bad66` as [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md). Those shared helpers should not pull the FieldMap module into fitting-room or ranking-event ownership.
- The `FieldMapPane` virtual handlers are entered through an adjusted pane/control subobject; decompilation subtracts `0xa0` from `this` before accessing the real field-entry table and request flag. Preserve the adjustor-subobject note when reconstructing the class layout.
- 2026-06-17 B003 recheck keeps `NexusTK/map/FieldMapPane.cpp` as the best source route. The constructor no-direct-xref issue blocks proving a larger field-dialog module, but not the current file route. The aggregate [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md) can clear `85/90` as source-quality documentation while still leaving formal aggregate C++ blank to avoid duplicate child emission.
- 2026-06-27 B006 resolves the old `0x004b1130` boundary/import blocker for file-level reconstruction. Treat it as exact retained child helper `CalculateFieldItemRect` with first-draft C++ on UID 000150 and a no-live-caller caveat, not as fitting-room code, generic GrafPort/RectBounds code, padding, or a remaining no-code blocker for the child page.
- 2026-06-27 B006 resolves the request-helper packet/helper naming blocker for this file. `SendFieldMapRequest` now emits from its exact by-memory page with source-facing helper names and request fields, so future FieldMapPane file work should not route the helper through `FittingRoomDownloadControlPane` or keep `requestCoordA/requestCoordB` as final packet names.
- B002 2026-06-18 reanalysis makes [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md) source-ready as a file-local `BuildFieldMapPath` helper in `NexusTK/map/FieldMapPane.cpp`. It copies the constructor source path stem into `FieldMapPane::m_fieldMapEpfPath[0x80]`, leaving `.EPF` append and `CharUpperBuffW` uppercasing to the constructor. This rejects moving the helper to `PathUtil.cpp`: the body is path-like, but the only proven caller and only proven destination are FieldMapPane-specific.

## Open Questions

- No ordinary-document blocker remains for standalone `FieldMapPane.cpp`/`.h` reconstruction. The former larger-dialog placement theory is preserved as superseded history because no competing owner, shared private helper, or contiguous dialog family was found.
- Exact original lexical spellings remain inferred. Source-facing names are selected from behavior, subsystem style, field offsets, provider contracts, and current family terminology rather than retaining raw IDA labels.
- `0x004b1130` remains no-live-caller raw code. It is retained as source-authored `CalculateFieldItemRect` because its complete bounded body, normal prologue/`retn 8`, unique signature, FieldMap layout, and duplicated mouse/paint formula establish high-probability source provenance; this does not claim a live caller.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | All seven authored definitions, compiler products, code/data ranges, layouts, dependencies, formal CPP/H destinations, and generated-source expectations are closed. |
| Confidence | 94 | Exact boundaries, vtable slots, caller/callee/data sets, layouts, packet/render behavior, and owner routes agree. Original lexical spellings, constructor registration, and final rebuilt integration remain below final-audit proof. |

## Cross-References

- [UID:00004U][FieldMapPane](by-class/FieldMapPane.md)
- [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md)
- [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md)
- [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md)
- [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md)
- [UID:00025B][0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData](by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md)
- [UID:0003P8][0x0061a3c4-0x0061a44c.FieldMapPaneVtableData](by-memory/0x0061a3c4-0x0061a44c.FieldMapPaneVtableData.md)
- [UID:0003P9][0x0061a44c-0x0061a458.SharedEpfSuffixString](by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md)
- [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md)
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## 2026-08-18 B007 Whole-File Source-Quality Closure

### Complete source inventory and order

The standalone source unit has exactly seven source-authored definitions, emitted in this dependency/source order after the class preamble: constructor `[0x004b0bb0,0x004b0d2b)`, pointer/mouse handler `[0x004b0d30,0x004b0e50)`, key/text handler `[0x004b0e50,0x004b0f1b)`, `OnPaint` `[0x004b0fb0,0x004b112a)`, retained rectangle helper `[0x004b1130,0x004b119d)`, request helper `[0x004b11a0,0x004b1242)`, and static path helper `[0x004b8220,0x004b8284)`. The preamble and complete class declaration emit from [UID:00004U][FieldMapPane](by-class/FieldMapPane.md); four class bodies emit from [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md); the final three helper bodies emit from UIDs `000150`, `000151`, and `00015U`.

The binary additionally contains compiler-only adjustors `[0x004b1242,0x004b124d)` and `[0x004b124d,0x004b1258)`, scalar deleting destructor `[0x004b1260,0x004b129b)`, switch jump table `[0x004b0f1c,0x004b0f30)`, selector table `[0x004b0f30,0x004b0fa6)`, three COL/vtable facets `[0x0061a3c4,0x0061a44c)`, and exact alignment items. These are regenerated from the class/virtual/destructor/switch source and must not be emitted as handwritten arrays or ABI glue.

### Layout and inheritance

`FieldMapPane` derives directly only from `Pane`; the EventHandler and TimerHandler views are inherited facets already embedded by `Pane`, not additional direct bases. `FieldMapEntry` is exactly `0x94` bytes: `Point m_displayPosition` at `+0x00`, `wchar_t m_label[64]` at `+0x08`, `unsigned short m_auxiliaryValue` at `+0x88`, `unsigned short m_requestFieldId` at `+0x8a`, and `Point m_requestPosition` at `+0x8c`. `FieldMapPane` is exactly `0x9600` bytes: `Pane` at `+0x0000`, path buffer at `+0x00f8`, 256 entries at `+0x01f8`, count/index/cancel words at `+0x95f8/+0x95fa/+0x95fc`, request flag at `+0x95fe`, and one byte of tail padding at `+0x95ff`.

Only `OnPaint` is a primary Pane-facet slot (`0x0061a40c`). Pointer/mouse and key/text dispatch are EventHandler-facet slots `0x0061a418` and `0x0061a41c`. TimerHandler contributes only its inherited compiler facet here. The exact three vtable heads are `0x0061a3c8`, `0x0061a414`, and `0x0061a444`, with COL pointers immediately before them.

### Exact behavior and data flow

The constructor builds the source stem through `BuildFieldMapPath`, appends shared use-site literal `L".EPF"`, uppercases the completed path through `g_pfnCharUpperBuffW`, initializes count/selection/cancel/request state, and copies every display position, label, auxiliary word, request field ID, and request position into the fixed entry table.

The pointer handler considers only left-button-down events, walks every entry without an early break, computes each rectangle, and sends for every hit only while `m_requestInFlight` is false. The key handler translates the key before switching: Return sends the selected entry only while no request is in flight; Escape and `0x71` send the cancel entry without that gate; left advances with `(index + 1) % count`; right wraps with `(index + count - 1) % count`; handled navigation invalidates the visible bounds. The binary retains the original zero-count modulo behavior rather than adding a defensive guard.

`OnPaint` obtains EPF layout index zero, blits the layout, then for every entry computes its rectangle, fills selected color `37` or normal color `4` in draw mode `2`, returns to mode `0`, frames in color `0x80`, switches to mode `1`, moves to `(left + 6,bottom - 6)`, and draws the wide label. Shared render dispatches are the typed Surface providers `g_pfnBlitSprite` and `g_pfnFillRect`; FieldMapPane consumes but does not define them.

`SendFieldMapRequest` emits exactly seven bytes: opcode `0x3f`, `m_requestFieldId`, `m_requestPosition.x`, and `m_requestPosition.y`, each multi-byte field in big-endian order, then queues through `g_packetSender` and sets `m_requestInFlight`. `BuildFieldMapPath` is file-local, has the constructor as its sole caller, copies through but excludes the final period when present, copies the whole source when absent, and terminates the destination; suffix append and uppercase remain constructor behavior.

### Dependencies, ownership, and exclusions

Provider contracts remain owned by `Pane`, `Event`, `ImageLib`, `Surface`, `GrafPort`, `PacketBuffer`, `Socket`, and `PlatformApi`. FieldMapPane includes and calls those interfaces but does not duplicate their definitions. The owner graph is FILE UID `0000JA` -> class UID `00004U`, aggregate UID `00014Z`, exact helper UIDs `000150/000151/00015U`, vtable evidence UID `0003P8`, and shared-literal use UID `0003P9`. The mixed `.rdata` parent UID `00025B` remains an index only.

Rejected alternatives are larger-dialog ownership, fitting-room ownership for the request/rectangle helpers, generic GrafPort or RectBounds ownership of the rectangle body, PathUtil ownership of the source-local path helper, direct EventHandler/TimerHandler multiple inheritance, handwritten vtable/RTTI arrays, and dropping the no-xref rectangle body as padding. Earlier notes that treated these as open source blockers are historical and superseded by the exact child/layout/provider evidence above.

The required generated closure is `NexusTK/map/FieldMapPane.cpp` with the class preamble plus all seven definitions and no empty-emitter or raw-label artifacts, `NexusTK/map/FieldMapPane.h` with the complete declarations and size guards, and `NexusTK/platform/PlatformApi.h` with the single `g_pfnCharUpperBuffW` extern declaration.

## Changes

- 2026-08-18 B007 whole-file implementation callback:
  - Raised `88/88` to `93/94` and preserved `NexusTK/map/` plus FILE ownership.
  - Closed the standalone CPP/H route, complete seven-definition inventory, exact class/entry layouts, inherited-facet model, behavior/data flow, provider contracts, compiler-product exclusions, helper source placement, and generated-source expectations.
  - Historicalized the larger-dialog, unresolved-render-global, fitting-room, generic-helper, direct-multiple-inheritance, and no-code raw-helper alternatives instead of deleting their provenance.

- 2026-06-01 reconstruction path and IDA refresh:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the contents table still used the pre-correction `0x004b129a` aggregate end.
  - Changed to: `NexusTK/map/` and aggregate range `0x004b0bb0-0x004b129b`.
  - Summary/evidence: the proposed source tree already lists `map/FieldMapPane.cpp`; IDA MCP rechecked the FieldMap function map, vtable refs, helper callers, constructor path-helper caller, and the still-unmodeled raw rect helper.
- Before: `BuildFieldMapPath_4B8220` was listed as `0x004b8220-0x004b8283`.
- After: `BuildFieldMapPath_4B8220` is listed as `0x004b8220-0x004b8284`.
- Summary/evidence: 2026-05-28 IDA MCP reports `sub_4B8220` size `0x64`, and disassembly shows the final two-byte jump at `0x004b8282-0x004b8283`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: field-map role, proposed source placement, method map, IDA xref/boundary evidence, shared-helper ownership cautions, open rectangle helper question, and path-helper endpoint correction are documented; confidence remains medium-high because standalone map/UI source placement and `0x004b1130` reachability remain open.
- 2026-06-04 live IDA confidence update:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:76`, and older source-label/helper wording.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: live IDA MCP now records the exact modeled function ranges, constructor vtable stores, vtable slots, FieldMap-only request-helper callers, constructor-only path-helper caller, raw `0x004b1130` status, and padding boundaries. Confidence remains below final-source quality because the standalone-vs-larger-dialog source split and the raw rectangle helper are still unresolved.
- 2026-06-14 C001: Raised from `86/84` to `88/88`.
  - Before: the page had strong 2026-06-04 IDA evidence, but confidence was still scored below the written evidence level and the current packet/path helper decompilation was not recorded.
  - After: added current MCP health, refreshed function sizes, request/path caller sets, raw `0x004b1130` no-function/no-ref status, request packet details, and a current score rationale.
  - Evidence: `lookup_funcs`, `xrefs_to`, `analyze_component`, `analyze_function`, and `int_convert.py` reconfirm the map-local method/helper cluster and the remaining raw-helper blocker.
- 2026-06-17 B003 aggregate gate sync:
  - Summary/evidence: recorded that [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md) clears `85/90` after source-quality recheck while formal aggregate C++ remains blank for duplicate-emission and then-pending request-helper source-quality. File score unchanged; the request-helper source-quality issue is superseded by the 2026-06-27 B006 callback below.
- 2026-06-27 B006 implementation callback:
  - Summary/evidence: incorporated accepted [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md) source-quality findings. `SendFieldMapRequest` remains in `NexusTK/map/FieldMapPane.cpp`, now with source-ready helper names `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `Socket::QueueAndSendPacket`, sender global `g_packetSender`, entry fields `requestFieldId/requestX/requestY`, and rejection of the stale fitting-room owner/name. The then-current raw `0x004b1130` file caveat is superseded by the rectangle-helper callback below; standalone-vs-larger-dialog placement remains a broader file-level caveat.
- 2026-06-27 B006 rectangle-helper implementation callback:
  - Summary/evidence: incorporated accepted [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) source-quality findings. `CalculateFieldItemRect` is now an exact retained child helper in `NexusTK/map/FieldMapPane.cpp`, with first-draft C++ on UID 000150, no-live-caller caveat, MCP session `398b87c1` no-function/no-xref evidence, PE no-edge/no-pointer evidence, text-helper xref relationships, and rejection of fitting-room/GrafPort/RectBounds/padding/no-code alternatives. File score unchanged because standalone-vs-larger-dialog placement and constructor reachability remain broader file-level caveats.
