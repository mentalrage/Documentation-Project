*** UID:00009B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// NewSystemMessageModifyHeightPane belongs to social/SystemMessagePanes.cpp, but
// class-level source is intentionally withheld here. Current evidence proves the
// constructor, drag/commit handler, paint path, singleton lifecycle, and destructor
// family, including exact vtable child [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md), +248/+256/+260 state, and
// 0x114-byte allocation size. A declaration shell would have to invent the base
// pane/event ABI and member layout, so this marker records disposition only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewSystemMessageModifyHeightPane

## Status

- Confidence: strong for role, singleton/global lifecycle, owner file, exact vtable child, constructor/cleanup/destructor stores, and IDA-backed boundaries; medium-high for final source-level field names.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Vtable/data evidence: [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md), [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md), and [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md)
- Autogen parent: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). This class now clears the strict `85/85` gate and belongs to the system-message pane source family.
- Parent range disposition: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is a non-emitting executable split index. This class page keeps ownership of the constructor, cleanup, drag/resize, paint, clear-helper, and scalar-deleting destructor family listed below.

## Class Purpose

`NewSystemMessageModifyHeightPane` is the drag handle for resizing the newer system-message panel. It reads the saved message-panel height from the config object, tracks drag state, clamps the new height to a 70-175 pixel range, applies a preview rectangle through the owner panel, commits the height on release, and refreshes [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md).

## Ownership And Lifecycle

The class is a child/helper pane in `SystemMessagePanes.cpp`, not a standalone module. The executable range page records the constructor, cleanup, drag, paint, clear-helper, and scalar deleting destructor inside the system-message pane cluster. The read-only data page places the `NewSystemMessageModifyHeightPane` vtables in the newer system-message pane vtable band, and the singleton-slot page records `g_pHeightModifyPane` as the live pointer published by the constructor and by the owning `NewSystemMessagePane` construction path.

Runtime lifecycle summary:

| Phase | Evidence | Notes |
| --- | --- | --- |
| Construction | `0x005881f0-0x005882b4`, plus child construction inside `0x00588560` | Publishes [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md), initializes the resize bounds, and reads the saved height value. |
| Drag/commit | `0x005882f0-0x005884ab` | Tracks mouse press/drag/release state, clamps the height range, writes the preview rectangle, persists the committed height, and refreshes [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md). |
| Paint | `0x00588500-0x0058855b` | Draws the resize grip with `SYSBAR.EPF` and `invenbut.pal`. |
| Cleanup | `0x005882c0`, `0x0058aaa0`, `0x0058acc0-0x0058ad1e` | Clears the singleton slot, restores vtables/tears down pane state, and conditionally frees storage through the scalar deleting destructor. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005881f0-0x005882b4` | constructor | Constructs the pane, stores [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md), loads the saved height from config, and initializes preview bounds. |
| `0x005882c0-0x005882e8` | non-deleting cleanup | Reinstalls vtables, clears `g_pHeightModifyPane`, and calls pane cleanup. Existing partition notes list this as an omitted helper body. |
| `0x005882f0-0x005884ab` | drag handler | Handles press/drag/release events, clamps height, updates preview rect, persists config height, and refreshes `g_pNewSystemMessagePane`. |
| `0x00588500-0x0058855b` | `OnPaint` | Loads `SYSBAR.EPF` and draws the grip using `invenbut.pal`. |
| `0x0058aaa0-0x0058aaaa` | singleton clear helper | Clears `g_pHeightModifyPane`. Existing partition notes list this as an omitted helper body. |
| `0x0058acc0-0x0058ad1e` | scalar deleting destructor | Clears `g_pHeightModifyPane`, tears down pane state, and conditionally deletes storage. |

## Partition Caveats

- Existing generated-export notes place `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560` beside this height pane. The system-message file and class docs treat that as a partition artifact: the constructor belongs to [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md), while this class owns only the height-modify child constructor/handlers/destructors listed above.
- Existing generated-export notes omit the non-deleting cleanup at `0x005882c0` and clear helper at `0x0058aaa0`; both remain class-owned because the system-message range, singleton slot, and global pages document their xrefs and behavior.
- 2026-05-25 IDA recheck: `0x005882c0` reinstalls `NewSystemMessageModifyHeightPane` vtables, clears `g_pHeightModifyPane` at `0x0069bc0c`, and calls shared pane-base cleanup `0x00544580`; `0x0058aaa0` is the standalone singleton-clear helper for the same global.
- IDA `xrefs_to 0x0069bc0c` shows constructor writes at `0x00588239`/`0x00588240`, cleanup/destructor clears at `0x005882da`, `0x0058aaa0`, and `0x0058ace0`, and child construction inside `NewSystemMessagePane` at `0x00588620`/`0x00588627`.
- 2026-06-12 A002 Batch 286 live IDA MCP recheck: [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md) covers only this class, with vtable bases at `0x0062d7b4`, `0x0062d800`, and `0x0062d830`. Store refs land in constructor `0x005881f0`, cleanup `0x005882c0`, nested construction inside `NewSystemMessagePane` at `0x00588560`, and scalar deleting destructor `0x0058acc0`; disassembly confirms singleton writes/clears at `0x0069bc0c` and delete size `0x114` / 276 decimal (Verified with `int_convert.py`).
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync: the parent is now a non-emitting split index, but this class keeps source ownership for `0x005881f0`, `0x005882c0`, `0x005882f0`, `0x00588500`, `0x0058aaa0`, and `0x0058acc0`. The neighboring `0x00588560` constructor remains [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md) despite generated mispartition.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now covers purpose, owning source file, exact method family, lifecycle phases, singleton/data evidence, exact vtable child, generated partition caveats, parent attachment, and no-code rationale. It stays below final-audit level because final field names, exact mouse-event signature, and source-level helper names are still provisional. |
| Confidence | 87 | Live IDA-backed evidence proves the function starts, vtable/read-only-data membership, singleton slot lifecycle, nested construction path, scalar deleting destructor behavior, and owner file. Confidence remains below 95 because final reconstructed declarations are not selected. |

## B011 Declaration-Shell Audit

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` keeps this class source-owned by [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) but resolves the empty emitter with a formal no-code comment. The audit checked constructor `0x005881f0-0x005882b4`, cleanup `0x005882c0-0x005882e8`, drag handler `0x005882f0-0x005884ab`, paint `0x00588500-0x0058855b`, singleton clear helper `0x0058aaa0-0x0058aaaa`, scalar deleting destructor `0x0058acc0-0x0058ad1e`, exact vtable child [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md), singleton slot [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md), and global [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md).

The constructor publishes `g_pHeightModifyPane`, installs three vtable views, reads persisted height, and initializes drag/preview state; cleanup/destructor clear the singleton and restore/tear down pane state. [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md) proves three vtable views at `0x0062d7b4`, `0x0062d800`, and `0x0062d830`, with lifecycle refs from constructor, cleanup, nested construction, and scalar deleting destructor. Offsets `+160/+164` are adjusted vtable views, `+248` is saved height state, `+256` is a drag byte, and `+260` begins preview rect/state; delete size is `0x114` / 276 bytes (Verified with `int_convert.py`). A declaration shell would have to choose the base pane class/interface, event parameter type, rect/member types, and nested owner relationship, while `[[CHILDREN]]` has no exact child method pages to pull in.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md)
- [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md)
- [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md)
- [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md)
- [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md)

## Changes

- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted the formal no-code disposition comment into `RECONSTRUCTION_CPP CODE`.
  - Added declaration-shell audit proof for constructor/cleanup/drag/paint/destructor family, [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md), singleton slot/global evidence, `+248/+256/+260` state, `0x114` allocation size, and the rejected base/event/member ABI shell.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync:
  - Preserved height-pane ownership for `0x005881f0`, `0x005882c0`, `0x005882f0`, `0x00588500`, `0x0058aaa0`, and `0x0058acc0` while recording [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) as a non-emitting split index.
  - Kept the generated mispartition caveat that `0x00588560` belongs to [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md), not this height-pane class, and replaced obsolete final-source-gate wording with current provisional-name rationale.
- Before: completion/confidence metadata were `0/0` despite detailed resize-handle behavior, global ownership, method-map, and generated-data caveat notes.
- Changed to: `COMPLETION:78` and `CONFIDENCE:80`.
- Evidence: the page records drag/clamp/commit behavior, singleton global writes/clears, constructor/destructor/helper ranges, resource use, and IDA xrefs; remaining gaps are final generated-source partition cleanup and body-level C++ reconstruction.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `78/80`, below the 80/80 parent-attachment gate, even though [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x005881f0`, `0x005882c0`, `0x005882f0`, `0x00588500`, `0x0058aaa0`, and `0x0058acc0`.
- 2026-06-07 A001 class evidence refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, and `AUTOGEN_PARENT_UID:0000OE`.
  - Summary/evidence: existing documentation now ties the height pane to `SystemMessagePanes.cpp`, the exact executable range, `NewSystemMessageModifyHeightPane` vtable/data band, and `g_pHeightModifyPane` singleton-slot lifecycle. The page also records lifecycle phases, partition caveats for the neighboring `NewSystemMessagePane` constructor, score rationale, and blank formal C++ because field names, mouse-event signature, and source-level helper names remain provisional.
- 2026-06-12 A002 Batch 286 split/parent-gate repair:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: created exact vtable child [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md); live IDA MCP reconfirmed the three class vtable bases, constructor/cleanup/nested-construction/scalar-delete refs, `g_pHeightModifyPane` writes/clears, and delete size. This clears the direct-parent gate for the exact vtable child while final C++ remains blank.
