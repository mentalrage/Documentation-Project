*** UID:0001YB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this vtable is covered by [UID:00009Q][ObjectList](by-class/ObjectList.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ObjectList vtable

## Status

- Entity kind: vtable layout
- Address: `0x00620288`
- Confidence: very strong for the exact three-slot table, complete RTTI chain, direct `LObject` inheritance, constructor/destructor stores, scalar-wrapper liveness, neighboring string/ObjectPane boundaries, class ownership, and source-generated policy.
- Direct owner: [UID:00009Q][ObjectList](by-class/ObjectList.md)
- Source root: [UID:0000M4][ObjectList](by-file/ObjectList.md)
- Exact vtable-data child: [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md)
- Reconstruction note: this vtable page emits only the exact covered-by marker `// Emitted code for this vtable is covered by [UID:00009Q][ObjectList](by-class/ObjectList.md).`; H remains blank. The concrete table is generated from the `ObjectList` class declaration, inherited `LObject` virtual surface, and virtual destructor; do not hand-author a vtable array.

## Slots

IDA MCP memory inspection on 2026-05-24 shows:

| Slot | Address | Target | Notes |
| --- | --- | --- | --- |
| 0 | `0x00620288` | `0x00537290` | [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md), canonical `ObjectList::ScalarDeletingDestructor`; the MSVC wrapper generated from `ObjectList::~ObjectList`, not a handwritten source method. |
| 1 | `0x0062028c` | `0x004f4b10` | inherited `LObject::GetRuntimeClass`. |
| 2 | `0x00620290` | `0x0041b6c0` | inherited `LObject::OnChangeMessage`. |

The preceding dword at `0x00620284` resolves to `??_R4ObjectList@@6B@`. The next dword at `0x00620294` resolves to `??_R4ObjectPane@@6B@`, so the concrete `ObjectList` vtable is the three-slot `LObject`-style surface.

The exact `[0x00620284,0x00620294)` payload is `b4 cc 64 00 90 72 53 00 10 4b 4f 00 c0 b6 41 00`, SHA256 `0185B14135A28B9F2A66A7A9B1CD92708552A7AE4346769D5678477A166DDC2E`. The vtable itself therefore occupies `[0x00620288,0x00620294)` and has no hidden fourth slot.

## Evidence

- `ObjectList::ObjectList` writes `ObjectList::vftable` after constructing the base object.
- `ObjectList` non-lifecycle helpers around `0x00530d00-0x0053728e` are non-virtual direct calls and helper-table dispatch code, not vtable slots.
- The destructor wrapper at `0x00537290` has no direct callers in IDA, consistent with vtable dispatch.
- RTTI names and dwords resolve the complete direct-single-inheritance route: ObjectList COL `0x0064ccb4`, type descriptor `0x0067830c`, class hierarchy descriptor `0x0064ccc8`, base-class array `0x0064ccd8`, ObjectList base descriptor `0x0064cce4`, and inherited LObject base descriptor `0x00640348`. The source-facing declaration is `class ObjectList : public LObject`.
- Constructor store `0x00530f19` and ordinary-destructor restore `0x00531288` are the only vptr stores. The scalar wrapper remains live through slot `0x00620288` despite having no direct `.text` caller.
- The predecessor `[0x0062026c,0x00620284)` is the complete UTF-16 `L"DLGEXC3.EPD"` literal including its terminator. The older isolated `0x00620280 -> 0x44` reading is a dword-sized view into that string, not a separate data object or boundary. The successor `0x00620294` is the ObjectPane COL.

## 2026-06-01 IDA Recheck

- IDA MCP `py_eval` reports `??_7ObjectList@@6B@` at `0x00620288` and reads `0x00620284 -> ??_R4ObjectList@@6B@`, slots `0x00620288-0x00620290`, and `0x00620294 -> ??_R4ObjectPane@@6B@`.
- IDA xrefs to `0x00620288` report vptr stores at `0x00530f19` and `0x00531288`.
- IDA xrefs to `0x00537290` report the vtable data reference at `0x00620288`, confirming slot `0` as the scalar deleting destructor.
- This recheck closes the former boundary caveat and splits exact data page [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md).

## 2026-06-11 Parent-Gate Refresh

- IDA MCP `lookup_funcs` reconfirms `ObjectList::ObjectList` at `0x00530ee0-0x0053125d`, the ordinary destructor at `0x00531260-0x00531473`, and the scalar deleting destructor at `0x00537290-0x005372c8`.
- IDA MCP decompilation shows the constructor writing `ObjectList::vftable` at `0x00530f19`, the ordinary destructor restoring the same vtable at `0x00531288`, and the scalar deleting destructor calling the ordinary destructor before optional delete.
- IDA MCP `xrefs_to` reports only the constructor/destructor vptr stores to `0x00620288`; the only xref to slot target `0x00537290` is the data cell at `0x00620288`.
- IDA MCP `py_eval` historically read `0x00620280 -> 0x44`, `0x00620284 -> ??_R4ObjectList@@6B@`, `0x00620288 -> 0x00537290`, `0x0062028c -> 0x004f4b10`, `0x00620290 -> 0x0041b6c0`, and `0x00620294 -> ??_R4ObjectPane@@6B@`. The `0x44` observation is retained as a literal historical dword read, but current range analysis establishes that address as part of `L"DLGEXC3.EPD"`; only `0x00620284` and `0x00620294` are the relevant table boundaries.
- 2026-06-20 B003 Rule 26 incorporation adds direct PE scan agreement: target VA `0x00537290` appears only in this slot dword, no `.text` rel32 call/jump reaches the wrapper, and the wrapper's only ordinary-destructor call is `0x00537296 -> 0x00531260`. The slot should be regenerated from the class destructor declaration/body, not emitted as hand-authored wrapper source.

## Assignment Gate

The correct direct semantic parent is [UID:00009Q][ObjectList](by-class/ObjectList.md), not the by-file source root, because this table is emitted from the `ObjectList` class declaration. The current `92/94` score is supported by exact bytes/bounds, complete direct-`LObject` RTTI, canonical slot identities, lifecycle stores, scalar-wrapper liveness, source topology, and formal covered-by disposition. `AUTOGEN_PARENT_UID` remains [UID:00009Q][ObjectList](by-class/ObjectList.md), and exact `.rdata` child [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md) follows the same class parent.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md)
- [UID:0001VG][ObjectListLayout](by-type/by-struct/ObjectListLayout.md)

## Changes

### 2026-07-30 B004 - Complete ObjectList Vtable/RTTI Closure

- Raised `85/91` to `92/94` after recording the exact sixteen-byte COL-plus-vtable payload and SHA, the three canonical slots, the complete COL/type/CHD/base-array/base-descriptor chain, direct `LObject` inheritance, constructor/destructor stores, and vtable-only scalar-wrapper liveness.
- Replaced the generic generated-vtable note with the exact covered-by marker `// Emitted code for this vtable is covered by [UID:00009Q][ObjectList](by-class/ObjectList.md).`; H remains intentionally blank. Human source consists of the complete ObjectList class declaration and destructor/method definitions, while the compiler regenerates RTTI, vtable data, and the scalar deleting wrapper.
- Corrected the predecessor boundary: `0x00620280` is inside the complete `L"DLGEXC3.EPD"` string `[0x0062026c,0x00620284)`, not a standalone terminal-byte object. `0x00620294` remains the adjacent ObjectPane COL. Earlier readings are preserved as historical evidence with the superseding range interpretation.
- The accepted data/function name/type/comment mutations remain supervisor-owned. This ordinary documentation callback records their exact handoff and protected boundaries but does not claim IDA mutation.

### 2026-07-01 B008 - Vtable Comment Marker

- What changed: the formal block now emits only `// ObjectList vtable is generated from the class declaration and inherited LObject virtual surface.`
- Why: B008 accepted this as source-declared/generated-binary output. The class declaration, inherited `LObject` virtual surface, and virtual destructor regenerate the vtable; do not hand-author a source vtable array.

### 2026-06-20 - Slot 0 Wrapper Policy Sync

- What changed: slot 0 now links [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) as the MSVC scalar deleting destructor wrapper generated from `ObjectList::~ObjectList`.
- Why: B003's Rule 26 report confirms the target is vtable-only class ABI output with no direct `.text` callers and no independent handwritten source body.

### 2026-05-28 - Non-Virtual Helper Range Expanded

- What existed before: the evidence note only mentioned non-lifecycle helpers around `0x00532530-0x00532f67`.
- What changed: it now covers the broader non-virtual helper surface through `0x0053728e`.
- Why: IDA MCP and manual disassembly classify the formerly unknown span as ObjectList direct-call/helper-table code, not new vtable slots.

### 2026-06-01 - Boundary And Exact Data Split

- What existed before: the page was unevaluated in validator metadata and still carried an open caveat around the adjacent RTTI boundary after slot `2`.
- What changed: the page is marked reconstructable, graded `84/90`, and links the exact `0x00620284-0x00620294` ObjectList vtable-data child.
- Why: IDA MCP `py_eval` and xref checks verify the preceding ObjectList RTTI dword, the three vtable slots, the following ObjectPane RTTI dword, and the ObjectList vptr stores.

### 2026-06-11 - Attached To ObjectList Class Parent

- What existed before: the vtable was locally documented but unassigned because the direct class/file parent chain sat at `84/88` under the strict `85/85` gate.
- What changed: completion/confidence are now `85/91`, `AUTOGEN_PARENT_UID` points to [UID:00009Q][ObjectList](by-class/ObjectList.md), and the owner wording distinguishes the direct class parent from the `NexusTK/map/ObjectList.cpp` source root.
- Why: live IDA MCP reconfirmed the exact RTTI/vtable dwords, neighboring `ObjectPane` boundary, constructor/destructor vptr stores, scalar-deleting-destructor slot reference, and current function boundaries; the refreshed ObjectList class and file pages now clear the parent side of the gate.
