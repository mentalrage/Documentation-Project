*** UID:0000LQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NewHistoryDialogPane

## Status

- Confidence: very strong for the complete source/compiler/resource/consumer union and high for retained-source liveness because no direct constructor route survives.
- Proposed module folder: `login/`
- Proposed source file: `login/NewHistoryDialogPane.cpp`
- Proposed header file: `login/NewHistoryDialogPane.h`
- Main class: [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- Core address range: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- Support ranges: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md), [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md), [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md), and [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md).
- Evidence basis: 2026-06-04 live IDA MCP function, xref, vtable, disassembly, string/data, and byte checks.

## File Role

This module should own the full-screen newer history/credits dialog shown over the pre-login main menu. It is a narrow `DialogPane` subclass that composes a `HISTORYN.EPF` background with a `ScrolledTextControlPaneForMadeBy` loaded from the `MADEBY` text resource.

The scrolling text implementation belongs in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). This file only chooses the resources, positions the controls, stores the active singleton, and closes on key or mouse input.

The constructor tail uses the separate `dword_69B36C` main UI layer/context slot when creating the full-screen dialog and [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) when showing it. These are distinct operands at `0x0069b36c` and `0x0067aba4`.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `NewHistoryDialogPane` authored source | `0x00500410-0x005005b4`, `0x005005c0-0x00500605`, `0x00500610-0x00500632` | Constructor plus `HandleKeyOrTextEvent(Event *)` and `HandlePointerOrMouseEvent(Event *)`; no authored destructor is required. |
| `NewHistoryDialogPane` compiler support | `0x005023e0-0x005023eb`, `0x005024f8-0x0050250e`, `0x00502920-0x00502965`, `0x0061daf0-0x0061db8c` | Singleton base destruction, adjustor thunks, scalar deleting wrapper, and three-view vtable/RTTI data; all are non-emitting source artifacts. |
| `g_pNewHistoryDialog` | [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) | Active singleton pointer used by constructor, clear helper, destructor, and `ScrolledTextControlPaneForMadeBy` end-of-scroll close behavior. |
| `ScrolledTextControlPaneForMadeBy` | `0x004ff400-0x004ff7cc`, `0x0050257c`, `0x00502c10` | Reusable credits-scrolling control consumed here, but owned by `ui/controls/ScrolledTextControlPane.cpp`. |

## Source Ownership Split

| Source-level owner | Address | Handling |
| --- | --- | --- |
| `NewHistoryDialogPane` | `0x00500410`, `0x005005c0`, `0x00500610` | Keep as the class constructor and the two Event callbacks in `login/NewHistoryDialogPane.cpp`. The fieldless class directly derives from `DialogPane` and `Singleton<NewHistoryDialogPane>`; its destructor is implicit. |
| constructor unwind cleanup | `0x005023e0` | Keep documented as compiler/unwind singleton-clear glue in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| destructor adjustor thunks | `0x005024f8`, `0x00502503` | Keep documented as compiler adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); both are real vtable targets. |
| scalar deleting wrapper | `0x00502920-0x00502965` | Keep as compiler-generated reverse-base teardown, delete-flag handling, and conditional `operator delete`; do not emit an authored destructor or singleton clear. |
| vtable/RTTI cluster | `0x0061daf0-0x0061db8c` | Keep as source-declared/generated-binary class evidence with 23/11/2 slots and eight RTTI descriptors; do not emit handwritten tables. |

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms `0x00500410` size `0x1a4`, `0x005005c0` size `0x45`, `0x00500610` size `0x22`, `0x005023e0` size `0xb`, `0x005024f8` size `0xb`, `0x00502503` size `0xb`, and `0x00502920` size `0x45`.
- Constructor disassembly writes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), installs the three `NewHistoryDialogPane` vtable pointers at `0x0061daf4`, `0x0061db54`, and `0x0061db84`, allocates the image/text children, loads `HISTORYN.EPF`, sets focus mode, creates the full-screen dialog with `dword_69B36C`, and shows it with [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md).
- String/data checks confirm `HISTORYN.PAL` at `0x0061e4cc`, `HISTORYN.EPF` at `0x0061e4e8`, and the UTF-16LE `MADEBY` resource operand through `off_61E504`.
- `xrefs_to 0x0069b49c` confirms constructor writes, the made-by scrolled-text timer close read at `0x004ff6eb`, singleton clear helper `0x005023e0`, and destructor clear at `0x00502926`.
- `xrefs_to 0x005024f8` and `xrefs_to 0x00502503` show vtable data refs at `0x0061db54` and `0x0061db84`; the thunks jump to `0x00502920` with `this - 0xa0` and `this - 0xa4`.
- The exact vtable/RTTI cluster `[0x0061daf0,0x0061db8c)` has SHA256 `BA7C96EB88036F4D54AC50D72A74A0CA697655B45F4B8F1AAA13256C0EBF9D26`, three address points with 23/11/2 slots, and eight class-hierarchy descriptors covering NewHistoryDialogPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<NewHistoryDialogPane>`.
- Allocation size `0x26c` and Singleton PMD `+0x26c/-1/0` prove a direct empty Singleton base at the one-past offset; EventHandler and TimerHandler views remain inherited at `+0xa0` and `+0xa4`. No authored data member is required.
- Byte checks in [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) split the internal method alignment into `0x005005b4-0x005005c0` and `0x00500605-0x00500610`.
- IDA reports no direct constructor caller in the current database. The source-layout decision is based on live resource/singleton/parent-pane behavior and the established login/main-menu folder in [by-project-structure/proposed-source-tree.md](../by-project-structure/proposed-source-tree.md).

Checked again on 2026-06-14 with live IDA MCP session `a001_goal2_class_batch`:

- `lookup_funcs` reconfirmed the constructor/input/destructor-support family: `0x00500410` size `0x1a4`, `0x005005c0` size `0x45`, `0x00500610` size `0x22`, `0x005023e0` size `0xb`, `0x005024f8`/`0x00502503` size `0xb` each, and `0x00502920` size `0x45`.
- `xrefs_to 0x0069b49c` reconfirmed exactly five singleton lifecycle refs: the made-by scrolled-text timer read at `0x004ff6eb`, constructor writes at `0x00500465`/`0x0050046c`, singleton-clear helper write at `0x005023e0`, and destructor clear at `0x00502926`.
- `xrefs_to` on the three vtable heads reconfirmed constructor stores to `0x0061daf4`, `0x0061db54`, and `0x0061db84`; `xrefs_to 0x00500410` still reports no direct code xrefs to the constructor start.
- `callees` reconfirmed the constructor uses the dialog/base, EPF image-control, made-by scrolled-text, dialog resource, focus, create, and show helper set; the key and mouse handlers both route accepted dismissal input through the same close helper family.
- B003's 2026-06-17 source-quality reanalysis added a raw PE pointer scan: constructor start `0x00500410` has no raw absolute-VA pointer, while the key handler `0x005005c0`, mouse handler `0x00500610`, and scalar deleting destructor `0x00502920` each appear once as vtable pointers. This keeps the missing launcher path as a source-history caveat, not an ownership/emitter blocker.

## Reconstruction Notes

- Keep `0x005023e0` documented as a constructor-unwind singleton-clear helper in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Keep `0x005024f8` and `0x00502503` documented as real compiler adjustor thunks rather than handwritten source methods.
- Keep the scrolled credits control in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), with this file referencing it as a child control.
- The method-body first-draft C++ for [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) is now permitted and lives on that by-memory emitter. Keep this file-level page focused on source placement and ownership until the final class/header declaration shape is audited.
- [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md), [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md), and [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md) are compiler/data evidence with literally blank formal C++. Publication, reverse-base clear, vptr stores, adjustors, flags, delete/free behavior, RTTI, and table bytes must not appear as handwritten source.
- Source order is fixed: [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) at emitter position 0, [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) at position 10, and [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) at position 20.

## Score Rationale

The score is `92/93` because the page now closes the sole typed global, complete fieldless class, exact constructor and Event callbacks, direct Singleton inheritance/EBO, compiler-only destructor/vtable artifacts, resources, scroller consumer, exact source order, and `NexusTK/login/NewHistoryDialogPane.cpp` route. The exact absolute/RVA/raw/rel32 scans still find no surviving constructor entry route, so retained linked source with a removed historical launcher remains the strongest liveness disposition and caps confidence below final provenance certainty without blocking reconstruction.

## Cross-References

- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md)
- [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md)
- [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md)
- [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md)
- [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents file role, singleton, emitted-owner split, IDA function/xref evidence, migration notes, ignored thunk/EH handling, and cross-references; confidence is capped by live reachability and exact original path uncertainty.
- 2026-06-04: Raised the file page from `84/78` to `86/84` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/login/`.
  - Before: the validator-managed projected path was blank, and the page relied on stale migration/output wording instead of a current source-ownership split.
  - After: the page records the login folder, source/support ownership, exact live function sizes, vtable/singleton/resource evidence, internal padding ownership, and retained direct-constructor reachability caveat.
  - Evidence: 2026-06-04 live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, vtable dword reads, string/data checks, and `get_bytes` checks recorded here and in [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md).
- 2026-06-14 C001 Goal 2 file refresh:
  - Before: `86/84`; the class page had a current 2026-06-14 IDA refresh, but the file page did not yet record the current constructor/input/destructor-support verification.
  - After: `87/87`; owner/emitter routing and projected path unchanged.
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reconfirmed the full function-size set, singleton and vtable xrefs, constructor callee family, key/mouse close helpers, and unchanged zero-direct-constructor-xref caveat.
- Historical 2026-06-17 B003 support update: corrected stale show-target wording to separate `dword_69B36C` plus the then-current `g_pMainUiGraph` alias, recorded the raw PE no-pointer result for constructor start `0x00500410`, and clarified that [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) may carry first-draft method C++ while this file page documents source placement. Current show parent is `g_pMainMenuPane`.
- 2026-06-19 B005 destructor source-quality support update: accepted [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md) `88/90` first-draft destructor C++ in `login/NewHistoryDialogPane.cpp`, rejected inherited Boost/TransferReplyAlert labels for `0x0049d9f0` in favor of `DialogPane::~DialogPane()`, and kept constructor cleanup/destructor adjustor helpers non-emitting compiler output.
- 2026-07-21 B004 UID0001PV callback: raised this file to `92/93` and replaced the historical destructor-emitter assumption with the target-specific complete union. Exact wrapper analysis proves that Singleton clear, base teardown, vptr transitions, flags, and conditional delete are compiler lowering with no unique authored destructor statement. The file now routes one global definition, one complete class declaration, and the constructor/key/pointer definitions in positions 0/10/20 while retaining all no-constructor-route, resource, padding, scroller-consumer, and historical evidence.
