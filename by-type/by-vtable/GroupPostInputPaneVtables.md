*** UID:0003HK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// GroupPostInputPaneVtables is the source-local ABI index for UID0002N6.
// Regenerate all six views through GroupInputPane and PostInputPane; do not
// duplicate fixed vtable, RTTI, scalar-destructor, or adjustor-thunk bytes.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Group And Post Input Pane Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `GroupInputPane` and `PostInputPane` vtable views.
- Direct owner: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
- Exact data page: [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md).
- Split from: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md), which remains a broad non-emitting mixed-owner index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `GroupInputPane` | `0x006300d4-0x0063015c` | `0x006300d4` | `0x00630124` | `0x00630154` | Dispatcher/open/raw-constructor stores at `0x005a66c4`, `0x005a9a66`, and `0x005b541f`. |
| `PostInputPane` | `0x00630160-0x006301e8` | `0x00630160` | `0x006301b0` | `0x006301e0` | Dispatcher/open/constructor stores at `0x005a6718`, `0x005a9aeb`, and `0x005b5677`. |

## Boundary Evidence

- Exact span is `0x006300d4-0x006301e8`, or `0x114` / 276 bytes (Verified with int_convert.py).
- 2026-06-12 live IDA MCP `entity_query` lists six decorated names across the two class groups.
- 2026-06-12 `get_bytes` reads shared input-pane slot bytes at `0x006300d4`, and the `0x006301e8` successor bytes point to the following `ThrowInputPane` RTTI/slot group.
- `GroupInputPane` has a raw/projected constructor caveat, while `PostInputPane` has a real constructor function store at `0x005b5677`; both groups are still local to the same command-input source file.

## Complete Slot Inventory

| View | Exact slots in order | Source-specific slots |
| --- | --- | --- |
| Group primary `0x6300d4-0x630120` | `5b7940, 4f4b10, 41b6c0, 4f2320, 41d680, 544730, 544750, 5447a0, 544800, 544a20, 544b80, 544bd0, 4f2430, 544cb0, 4f24c0, 544d30, 544d70, 4f2790, 5b5440` | final `0x63011c -> GroupInputPane::OnConfirmInput` |
| Group EventHandler `0x630124-0x630150` | `5b77c8, 4f24f0, 4f25a0, 4f2580, 4f2760, 544df0, 544e00, 4a89f0, 544e10, 544e30, 544e70` | inherited `LineInputPane::HandleKeyOrTextEvent`; no Group-specific override |
| Group TimerHandler `0x630154-0x63015c` | `5b77d3, 544e90` | inherited timer default |
| Post primary `0x630160-0x6301ac` | `5b7940, 4f4b10, 41b6c0, 4f2320, 41d680, 544730, 544750, 5447a0, 544800, 544a20, 544b80, 544bd0, 4f2430, 544cb0, 4f24c0, 544d30, 544d70, 4f2790, 5b5770` | final `0x6301a8 -> PostInputPane::OnConfirmInput` |
| Post EventHandler `0x6301b0-0x6301dc` | `5b77c8, 4f24f0, 5b5700, 4f2580, 4f2760, 544df0, 544e00, 4a89f0, 544e10, 544e30, 544e70` | `0x6301b8 -> PostInputPane::HandleKeyOrTextEvent` replaces the inherited `+0x08` route |
| Post TimerHandler `0x6301e0-0x6301e8` | `5b77d3, 544e90` | inherited timer default |

Each address token is the exact slot target without the common `0x` prefix. The exact per-cell address/value/disposition table is retained in [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md); this type page preserves the complete ordered slot signatures rather than hand-authoring those cells as C++.

## Complete RTTI, Layout, And Construction Closure

| Class/view | Locator cell -> COL | PMD offset | Type descriptor / CHD | Base-class array |
| --- | --- | --- | --- | --- |
| Group primary | excluded `0x6300d0 -> 0x653334` | `0` | `0x67a128` `.?AVGroupInputPane@@` / `0x653348` | Group, LineInputPane, Pane, GrafPort, LObject, EventHandler, TimerHandler |
| Group EventHandler | `0x630120 -> 0x653394` | `0xa0` | same TD/CHD | same seven bases |
| Group TimerHandler | `0x630150 -> 0x6533a8` | `0xa4` | same TD/CHD | same seven bases |
| Post primary | `0x63015c -> 0x6533bc` | `0` | `0x67a148` `.?AVPostInputPane@@` / `0x6533d0` | Post, CharInputPane, LineInputPane, Pane, GrafPort, LObject, EventHandler, TimerHandler |
| Post EventHandler | `0x6301ac -> 0x653420` | `0xa0` | same TD/CHD | same eight bases |
| Post TimerHandler | `0x6301dc -> 0x653434` | `0xa4` | same TD/CHD | same eight bases |

- Both complete objects are `0x108` bytes. EventHandler and TimerHandler adjusted views begin at `+0xa0` and `+0xa4`; constructors and methods support no persistent derived fields.
- Each Group head has dispatcher/open/raw-constructor stores at `0x5a66c4/cc/d6`, `0x5a9a66/6c/76`, and `0x5b541f/27/31`. Each Post head has dispatcher/open/modeled-constructor stores at `0x5a6718/1e/28`, `0x5a9aeb/f1/fb`, and `0x5b5677/7d/87`.
- `0x5b7940`, `0x5b77c8`, and `0x5b77d3` are shared compiler deleting-wrapper/adjustor output. They do not justify explicit Group/Post destructors or source-level thunk arrays.
- Group's raw constructor is a complete 64-byte source-authored body with two live inline mirrors despite zero raw-start xrefs/pointers. Post's constructor and class-specific methods are modeled. This difference is an IDA modeling/reachability fact, not a reason to split the vtable family or omit source.

## Source Route And Compiler Disposition

- Direct source owner/emitter remains UID0000ID. `CommandInputPanes.h` carries Group then Post declarations; `CommandInputPanes.cpp` carries their child definitions and compiler-generation markers.
- Stable direct positions are Group class `50`, Post class `60`, exact data page `70`, and this ABI index `80`. Group constructor/submit are child positions `10/20`; the Post method cluster is child `10`.
- No class split is warranted: Post's primary COL pointer at `0x63015c` lies between Group's final view and Post's primary head, so the existing combined exact page is structurally cleaner than an orphan locator.
- Do not emit raw arrays, RTTI objects, deleting wrappers, or adjustor thunks. This page's formal CPP marker records the compiler-owned disposition; its H channel is intentionally blank because declarations live in the class pages.
- The exact historical filename is unproven, but the complete Emotion/Group/Post family and current routed order make `NexusTK/ui/dialogs/CommandInputPanes.h/.cpp` the strongest source reconstruction. Broad UID0001XA/UID00026W remain mixed-owner non-emitting indexes.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). A class parent is too narrow because this page spans both class-generated families and the exact combined data range. The type page emits only the accepted source-local ABI marker through that file owner.

## Score Rationale

Completion `91` and confidence `94` reflect complete ordered slots, all six COL/RTTI graphs, exact PMD/layout closure, full construction-store sets, class-specific virtual ownership, source order, and compiler-generated/no-array disposition. The raw Group constructor is fully proven rather than deferred. Remaining uncertainty is limited to stripped original file spelling and some source access/spelling choices, not the ABI or runtime behavior.

## Cross-References

- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md)

## Changes

- 2026-08-14 Agent-B010 UID0002N6 callback: raised `87/91 -> 91/94`, set position `80`, added the exact source-local ABI marker, complete six-view slot signatures, all COL/RTTI/base graphs, layout/construction closure, compiler/shared-wrapper disposition, stable source route, no-split reasoning, and retained stripped-filename uncertainty.
- 2026-06-12 A004 Batch 313:
  - Created as the source-local `GroupInputPane`/`PostInputPane` by-vtable child of [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
  - Evidence: live IDA MCP confirmed six decorated table names, `0x114` / 276-byte exact span, representative stores for both classes, and the `ThrowInputPane` successor boundary.
