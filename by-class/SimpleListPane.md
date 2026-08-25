*** UID:0000D8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SimpleListPane.h"

#include "../../util/MemoryMan.h"
#include "../core/RectBounds.h"

#include <wchar.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CONTROLS_SIMPLELISTPANE_H
#define NEXUSTK_UI_CONTROLS_SIMPLELISTPANE_H

#include "ListPane.h"

struct RectBounds;

class SimpleListPane : public ListPane
{
public:
    SimpleListPane(int /*unused*/, const RectBounds *bounds);
    virtual ~SimpleListPane();

    void AppendText(const wchar_t *text);
    void InsertText(int index, const wchar_t *text);
    void RemoveText(int index);
    void ReplaceText(int index, const wchar_t *text);
};

#endif // NEXUSTK_UI_CONTROLS_SIMPLELISTPANE_H
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SimpleListPane

## Status

- Confidence: very strong for reusable control ownership, layout parenting, vtable/RTTI ownership, generated-owner-pollution rejection, and complete CPP/H routing.
- Source file: standalone [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) beside [UID:0000KT][ListPane](by-file/ListPane.md).
- Autogen parent: [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md)

## Class Purpose

`SimpleListPane` is a thin `ListPane` subclass for basic list display. It provides a fixed list configuration from caller-supplied rectangle bounds and owns cleanup for heap-backed list-entry buffers stored in the underlying list.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleListPane` | [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md) | Raw constructor-shaped code now formal-constructor ready; preserves the unused first ABI argument as unnamed, reads `RectBounds` fields for width/height, delegates to `ListPane(4, 10, width, height, 1, 1, 1)`, and emits first-draft C++ from the exact memory child. |
| `~SimpleListPane` child aggregate | [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) | Aggregate now emits the `[[CHILDREN]]` insertion marker for the source destructor/helper children. |
| `SimpleListPane::~SimpleListPane` | [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) | Source destructor body; frees each heap-backed copied-text buffer through `GetMemoryMan()->FreeBufferMemory` and lets compiler destructor chaining cover base cleanup. |
| `AppendText` | [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md) | Inferred source-facing helper that appends an allocated copy of a wide string. |
| `InsertText` | [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md) | Inferred source-facing helper that inserts an allocated copy of a wide string at a supplied index. |
| `RemoveText` | [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md) | Inferred source-facing helper that frees copied text then removes one list item. |
| `ReplaceText` | [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) | Inferred source-facing helper that frees/removes an existing entry and reinserts a copied replacement. |
| destructor adjustor thunk | `0x00573c38` | Compiler-generated thunk; adjusts `this` by `-0xa0` before entering the main destructor. |
| destructor adjustor thunk | `0x00573c43` | Compiler-generated thunk; adjusts `this` by `-0xa4` before entering the main destructor. |
| destructor wrapper | [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) | Compiler-generated adjustor/scalar-deleting wrapper support for the source destructor emitted by [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md); no source emitter. |

## Layout Notes

- The object uses the `ListPane` layout as its base and installs secondary vtable pointers at offsets matching the inherited list subobjects.
- The destructor reads the item-list state through the same storage area used by `ListPane` helpers; see [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md).
- IDA confirms no local `SimpleListPane` fields beyond inherited `ListPane` storage; scalar deleting destructor uses object size `0x14c`.
- The exact vtable-data child [UID:0003D5][0x00624c60-0x00624d24.SimpleListPaneVtableData](by-memory/0x00624c60-0x00624d24.SimpleListPaneVtableData.md) begins at the primary COL pointer and covers the primary, secondary, and tertiary views installed by the constructor and restored by the cleanup/destructor bodies.

## 2026-08-14 B009 Whole-Class Completion

This class now owns the complete formal declaration and CPP include/child envelope. The CPP channel includes `SimpleListPane.h`, `MemoryMan.h`, complete `RectBounds`, and `<wchar.h>` before the one `[[CHILDREN]]` route. The guarded H derives from complete `ListPane`, forward-declares `RectBounds`, and declares exactly the constructor, virtual destructor, and four copied-text methods. Child H channels remain blank so declarations occur once.

The six source methods are exact: the constructor derives width/height from `RectBounds` and calls `ListPane(4,10,width,height,1,1,1)`; the destructor frees and clears every copied wide-text slot; `AppendText` and `InsertText` allocate/copy with `wcslen`/`wcscpy_s`; `RemoveText` frees, clears, and removes one item; `ReplaceText` frees/removes before copying and reinserting. Names for the four helpers are descriptive/inferred because the raw starts have no recovered symbols or direct xrefs/pointer hits.

Compiler coverage is separate and non-duplicating: two 11-byte adjusted-view thunks (`this-0xa0`, `this-0xa4`) plus the scalar-deleting destructor emit no source, as do all seven `0xcc` alignment spans. The `0x14c` object has no local fields beyond inherited `ListPane`; vptrs at `+0x00/+0xa0/+0xa4`, list state at `+0x130`, and four-byte `Point` members at `+0x140/+0x144` are inherited layout evidence.

Vtable/RTTI evidence consists of primary COL plus 33 slots, secondary COL plus 11 adjusted slots, tertiary COL plus two adjusted slots, six RTTI graph records, two independently protected type-descriptor header heads, and descriptor-name storage. All are compiler-generated from this virtual declaration; the hard data successor `0x00624d24` and code successor `0x00573d20` belong to `ServerSelectPane`.

Standalone `NexusTK/ui/controls/SimpleListPane.cpp/.h` is final because the coherent class island, dedicated file/class emitter route, required header, and independent generated root outweigh the unproved historical fold into `ListPane.cpp`. The compile chain is `SimpleListPane.h -> ListPane.h -> ../core/ScrollBar.h`; the latter supplies complete `ScrollablePane`, `RectBounds`, and `Point` dependencies. Completion/confidence `94/93` retains the original-helper-name and source-history uncertainty without leaving a source blocker.

## Batch 129 Parent-Gate Audit

This class is the direct owner for [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md). The layout page describes this class's vptr placements and inherited `ListPane` storage, not a reusable file-level helper type. [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) was refreshed to `86/85`, so this class can retain that direct source-root parent under the strict gate.

2026-06-08 live IDA MCP reconfirmed the current evidence boundary: `0x005739a0` is still not modeled as a function, preserving the raw-constructor caveat; `0x00573a00` is the modeled cleanup body (`0x98` bytes); `0x00573c38` and `0x00573c43` are two `0xb` adjustor thunks; and `0x00573c50` is the `0xc5` main destructor. The vtable data refs and written layout evidence identify the primary, secondary, and tertiary vptrs at `+0x00`, `+0xa0`, and `+0xa4`, while the destructor and base cleanup evidence confirms object extent `0x14c`.

2026-06-12 A004 Batch 252 live IDA MCP reconfirmed the constructor raw-body evidence: `0x005739a0` remains not modeled as a function and has no direct start xrefs or little-endian pointer hits, but the exact `0x005739a0-0x005739f6` bytes decode as constructor-shaped code that calls `ListPane::ListPane` at `0x004f3a50`, writes the three `SimpleListPane` vtables at `0x005739d3`, `0x005739db`, and `0x005739e5`, and is bracketed by `0xcc` padding.

## 2026-06-16 A001 Source-Quality Refresh

Fresh read-only IDA MCP session `b001_0001KM_20260616` rechecked the current SimpleListPane evidence. `lookup_funcs` still reports `0x005739a0`, `0x005739f6`, `0x00573aa0`, `0x00573b10`, `0x00573b70`, `0x00573bb0`, and `0x00573d15` as not functions; it reports `0x00573a00` as `sub_573A00` size `0x98`, `0x00573c38` and `0x00573c43` as `0xb` adjustor thunks, and `0x00573c50` as `sub_573C50` size `0xc5`.

Raw reachability was checked again with IDA `xrefs_to` and little-endian address searches. There are still no xrefs or pointer hits for the raw constructor start or the raw append/insert/remove/replace starts. The only direct thunk/destructor code/data refs are the expected vtable refs (`0x00624cec -> 0x00573c38`, `0x00624d1c -> 0x00573c43`, `0x00624c64 -> 0x00573c50`) plus the two thunk code refs into `0x00573c50`.

The same pass reconfirmed the vtable/layout evidence: table-head refs to `0x00624c64`, `0x00624cec`, and `0x00624d1c` come from the raw constructor stores, the `0x00573a00` cleanup body, and the `0x00573c50` scalar deleting destructor. IDA `search_structs` and `type_query` found no local `SimpleListPane` struct/type record, so final member names must continue to inherit from [UID:00007A][ListPane](by-class/ListPane.md) and [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md) rather than from an IDA UDT.

Source-placement and generated-output checks do not prove a different owner. IDA string search found RTTI/type-name strings for `SimpleListPane` and `ClientItemMenuItemList`, but no embedded `SimpleListPane.cpp` or `ListPane.cpp` filename string. Earlier simroot-derived notes are treated only as historical placement hints. The current by-* route emits method bodies from exact children under [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md); validators own the generated `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` refresh.

Final C++ routing is active for this class (`RECONSTRUCTABLE:TRUE`, emitter [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md), and average score above `85`). The class CPP/H channels now supply the exact include/child envelope and guarded declaration, while exact method bodies emit from their by-memory children: constructor [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md), aggregate marker [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md), source destructor [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md), and inferred copied-text helpers [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md). [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) remains compiler-generated destructor support and must not duplicate `~SimpleListPane`.

## 2026-06-28 B001 Destructor/Helper Implementation Callback

Accepted Agent-B001 report `tools/leaser/Agents/Agent-B001/research/000241-SimpleListPaneDestructorAndEntryHelpers-source-quality.md` keeps [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) as the preferred generated root. Live MCP session `b001_000241_20260627` reconfirmed modeled function starts, raw helper non-function starts, no raw-start xrefs/pointer hits, padding, and vtable refs. [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) now emits only a child insertion marker; [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) owns source `SimpleListPane::~SimpleListPane()`; [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) emit inferred `AppendText`, `InsertText`, `RemoveText`, and `ReplaceText`; and [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) is non-emitting compiler-generated adjustor/scalar-deleting wrapper support.

## 2026-06-25 B003 Constructor Implementation Callback

Agent-B003 rechecked the raw constructor through live IDA MCP session `80de0a67` and incorporated the accepted constructor source shape. `lookup_funcs` still reports `0x005739a0` and `0x005739f6` as not functions, and no direct start xrefs or pointer hits were found, so the raw-boundary caveat remains. The exact body nevertheless reads the second explicit argument as a `RectBounds` pointer, computes width from `right - left`, computes height from `bottom - top`, calls the shared `ListPane` constructor with effective source order `4`, `10`, `width`, `height`, `1`, `1`, `1`, writes the three `SimpleListPane` vtables, returns `this`, and exits with `retn 8`.

The constructor child now emits the formal first-draft C++ from its own by-memory page. This does not move the class under [UID:0000KT][ListPane](by-file/ListPane.md) and does not attach it to ServerSelect ownership; `SimpleListPane` remains a reusable controls class rooted through [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md). The first explicit constructor argument remains intentionally unnamed because the binary pops it but never reads `[ebp+0x08]`.

## Evidence Notes

- IDA MCP confirms the destructor and both thunks. It does not currently model the constructor at `0x005739a0` as a function, so the constructor remains raw-boundary evidence.
- The constructor and both thunks remain documented through raw-boundary/vtable evidence rather than ordinary IDA function modeling.
- The active destructor's `ClientItemMenuItemList` base-call name is not reliable ownership evidence. Behavior and address context match the shared `ListPane` destructor family.
- 2026-05-26 recheck: the active/disabled generated split is unchanged, and the thunk pair is now recorded as compiler-generated ignored memory in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-31 IDA pass split `0x00573a00-0x00573c38` into exact destructor and copied-text helper pages, and confirmed the vtable bases `0x00624c64`, `0x00624cec`, and `0x00624d1c`.

## Cross-References

- [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md)
- [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md)
- [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)
- [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md)
- [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md)
- [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:0003D5][0x00624c60-0x00624d24.SimpleListPaneVtableData](by-memory/0x00624c60-0x00624d24.SimpleListPaneVtableData.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `74`.
- Evidence: the page documents the class role, likely ownership, constructor-shaped range, destructor/helper islands, thunk ranges, layout notes, source-materialization caveats, and ignored thunk tracking; confidence remains medium-high because the constructor is raw-boundary evidence and base-call names are polluted.
- Before: this page jumped from the raw constructor directly to the scalar deleting destructor/thunk range, leaving `0x00573a00-0x00573c38` undocumented.
- Changed to: the non-scalar destructor and entry helper island is now documented through [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md).
- Evidence: 2026-05-28 IDA MCP disassembly shows the vtable-restoring destructor at `0x00573a00`, followed by raw wide-string entry helpers at `0x00573aa0`, `0x00573b10`, and `0x00573b70`.
- 2026-05-31: Changed completion/confidence from `80/74` to `84/82`, marked the class reconstructable, and added the exact copied-text helper children.
  - Before: The class page referenced the aggregate helper island but did not list its child helper pages or the current layout/vtable evidence.
  - After: The class page links every current exact `SimpleListPane` child range and records object-size/vtable evidence; later callbacks supply method-level C++ from exact children.
  - Evidence: IDA MCP raw-disassembly split of `0x00573a00-0x00573c38`, destructor decompilation, vtable xrefs, and updated layout page.
- 2026-06-03: Corrected copied-text helper links for the append/insert children.
  - Before: the class page linked the old short ranges `0x00573aa0-0x00573b05` and `0x00573b10-0x00573b6a`, which stopped at the starts of return instructions.
  - After: the class page links `0x00573aa0-0x00573b08` and `0x00573b10-0x00573b6d`.
  - Evidence: IDA MCP raw disassembly shows `retn 4` bytes at `0x00573b05-0x00573b08` and `retn 8` bytes at `0x00573b6a-0x00573b6d`.
- 2026-06-05: Set the autogen parent to [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md).
  - Before: `AUTOGEN_PARENT_UID` was blank, leaving reconstructable SimpleListPane child memory pages unable to resolve to an autogen root.
  - After: the class attaches to the validated `NexusTK/ui/controls/` SimpleListPane file root, with C++ emission governed by exact child pages and later implementation callbacks.
  - Evidence: [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) is the current validated file root and the error rows showed [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) already attached to this class UID.
- 2026-06-08 A002 Batch129 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:82`.
  - After: `COMPLETION:85`, `CONFIDENCE:85`.
  - Evidence: added the direct layout-parent audit for [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md), after [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) was refreshed to `86/85`. Live IDA MCP reconfirmed the raw-constructor caveat, destructor/thunk starts, and destructor evidence supporting the vptr offsets and `0x14c` object extent. Scores remain at the gate because constructor callers and final source split are still unresolved.
- 2026-06-12 A004 Batch 252: Score unchanged at `85/85`.
  - What changed: updated the constructor method row and parent-gate notes for [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md), which now reaches `86/88` and attaches to this direct class parent.
  - Evidence: live IDA MCP reconfirmed the raw constructor body, no function object or direct start refs, the `0x004f3a50` base call, three `SimpleListPane` vtable stores, and surrounding padding. The class score remains capped because the final standalone `SimpleListPane.cpp` versus compact `ListPane.cpp` source split is still not final-audit quality.
- 2026-06-16 A001 source-quality pass: Changed completion/confidence from `85/85` to `87/87`.
  - What changed: added a fresh read-only IDA MCP source-quality refresh for raw constructor/helper reachability, modeled destructor/thunk starts, vtable refs, local type/struct absence, source-filename string absence, generated-output state, and active final-C++ eligibility.
  - Evidence: IDA session `b001_0001KM_20260616` `lookup_funcs`, `xrefs_to`, `find_bytes`, `find_regex`, `search_structs`, `type_query`, `callees`, `decompile`, `get_bytes`, and `insn_query`; local generated-output review available at that time. Owner/emitter routing stayed unchanged, and later implementation callbacks now supply method-level C++ from exact child pages.
- 2026-06-25 B003 implementation callback: Score unchanged at `87/87`.
  - What changed: updated the constructor row and source-quality notes because [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md) now emits formal constructor C++ with `RectBounds`-derived dimensions and the corrected `ListPane(4, 10, width, height, 1, 1, 1)` base call.
  - Evidence: accepted Agent-B003 report `tools/leaser/Agents/Agent-B003/research/0001HP-SimpleListPaneConstructor-source-quality.md` and live IDA MCP session `80de0a67` checks for raw boundary, no direct xrefs/pointer hits, argument reads, `ListPane` call order, vtable stores, and `retn 8`. The class-level score stays unchanged because destructor/helper final-source rewriting and the final standalone-versus-ListPane source split remain broader class/file questions.
- 2026-06-28 B001 implementation callback: Score unchanged at `87/87`.
  - What changed: updated method notes and source-quality text to reflect the accepted destructor/helper implementation route: [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) child marker, [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) source destructor, [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)-[UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) inferred copied-text helpers, and [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) compiler-generated non-emitting support.
  - Evidence: accepted Agent-B001 report and live MCP session `b001_000241_20260627`.
