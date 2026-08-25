*** UID:0001XY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000076 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LightObjImageLib Vtable

## UID0001PR Accepted Compiler-Generated Vtable Disposition - 2026-07-21

- This page is exact class-contract evidence owned semantically by [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md), but it is not an independent source emitter. The complete class declaration and virtual method bodies regenerate the table, so `RECONSTRUCTABLE:FALSE`, blank emitter/position, and blank formal C++ are required.
- The primary table remains `[0x0061b750,0x0061b768)`: RTTI locator dword followed by five slots for scalar deleting destructor, inherited LObject runtime/type support, inherited/default `ret 8` no-op, DrawLightMode1, and DrawLightMode2. No slot is omitted or converted into a handwritten array.
- The adjacent `ProtectedArray<LightInfo>` RTTI/vtable pair at `0x0061b748-0x0061b750` belongs to the member/template lifecycle and is excluded from the LightObjImageLib primary table. The NewHumanImageLib RTTI boundary at `0x0061b768` remains exact.
- Constructor/destructor/scalar xrefs to the vptr are compiler-generated stores/restores. They support class and lifetime reconstruction but do not justify source vtable assignments or an ABI wrapper body.
- Historical reconstructable/emitter metadata was a documentation-state convenience before the complete class source existed. It is superseded by this non-emitting compiler/data classification; all slot evidence below remains valid.

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md).
- Exact backing memory page: [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md).
- RTTI pointer: `0x0061b750` -> `0x0064900c`.
- Primary vtable: `0x0061b754`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e65e0` | [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) |
| `+0x04` | `0x004f4b10` | inherited `LObject` runtime/type helper |
| `+0x08` | `0x0041b6c0` | inherited/default no-op virtual / `nullsub_18` |
| `+0x0c` | `0x004dfbb0` | [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) |
| `+0x10` | `0x004dfc60` | [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) |

The table ends before the `NewHumanImageLib` RTTI pointer at `0x0061b768`.

## Adjacent Template Vtable

The `ProtectedArray<LightInfo>` vtable is immediately before this class vtable:

| Address | Slot | Function |
| --- | --- | --- |
| `0x0061b74c` | `+0x00` | `0x004e61b0`, `ProtectedArray<LightInfo>` scalar deleting destructor |

Its RTTI pointer at `0x0061b748` points to `0x006490ac`.

## Evidence

IDA xrefs to `0x0061b754` land at:

- `0x004df83c` in [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md)
- `0x004dfab9` in [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- `0x004e65ec` in the scalar deleting destructor

IDA xrefs to `0x0061b74c` land at:

- `0x004df842` in the constructor
- `0x004dfb14` in the ordinary destructor
- `0x004e5b23` in constructor unwind/cleanup code associated with the constructor
- `0x004e61b9` in the `ProtectedArray<LightInfo>` destructor
- `0x004e664e` in the scalar deleting destructor

Active `class_LightObjImageLib.meta_wave3` currently reports `vtable_count: 0`, so this page is the IDA-confirmed vtable anchor until generated metadata catches up.

IDA MCP live recheck on 2026-06-11 confirms the exact table and neighboring split:

- IDB root is `NexusTK.exe`.
- Dword reads show the adjacent `ProtectedArray<LightInfo>` RTTI/vtable pair at `0x0061b748-0x0061b750`, then `0x0061b750 -> ??_R4LightObjImageLib@@6B@`, `0x0061b754 -> 0x004e65e0`, `0x0061b758 -> 0x004f4b10`, `0x0061b75c -> nullsub_18`, `0x0061b760 -> 0x004dfbb0`, and `0x0061b764 -> 0x004dfc60`.
- `get_func` reports slot target boundaries `0x004e65e0-0x004e669d`, `0x004f4b10-0x004f4b16`, `0x0041b6c0-0x0041b6c3`, `0x004dfbb0-0x004dfc5a`, and `0x004dfc60-0x004dfd0a`.
- Data xrefs to `0x0061b754` remain constructor write `0x004df83c`, ordinary destructor restore `0x004dfab9`, and scalar-deleting-destructor self-reference `0x004e65ec`; no extra slots appear before the `NewHumanImageLib` boundary at `0x0061b768`.

2026-06-20 B001 local PE scan resolved the two inherited slot labels further. `0x004f4b10` disassembles as `mov eax, 0x61cf44; ret`; the returned descriptor points at the `LObject` name block, matching sibling `LObject`-derived vtable docs that treat this as inherited runtime/type support. `0x0041b6c0` disassembles as `ret 8`, so it is an inherited/default no-op virtual rather than a LightObjImageLib-specific unresolved method. Exact central base-interface names remain a wider `LObject`/vtable-family question and should not be solved with Light-specific labels.

## 2026-06-08 Assignment Gate Recheck

Batch 139 split the exact concrete vtable data out of the broader image-library read-only aggregate as [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md). That child records the RTTI pointer, five slot dwords, target function sizes, constructor/raw-destructor/scalar-deleting-destructor xrefs, and the adjacent `ProtectedArray<LightInfo>` and `NewHumanImageLib` boundaries.

The adjacent `ProtectedArray<LightInfo>` vtable at `0x0061b748-0x0061b750` is lifecycle/template support, not part of the `LightObjImageLib` primary vtable. Keeping the exact child at `0x0061b750-0x0061b768` prevents that template pair from being folded into the class vtable declaration.

The direct parent for this type page is [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md), now `86/86`, and the source-file parent below that class is [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md), now `87/85`. The child page is now `88/92`, so the corrected child-and-direct-parent `85/85` gate is satisfied. `AUTOGEN_PARENT_UID` is therefore set to the class page, while the concrete vtable-data child attaches here.

## Cross-References

- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md)
- [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md)
- [UID:0001UX][LightObjImageLibLayout](by-type/by-struct/LightObjImageLibLayout.md)
- [UID:0001UW][LightInfo](by-type/by-struct/LightInfo.md)
- [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md)
- [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md)
- [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md)
- [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md)
- [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md)
- [UID:0000RD][g_pLightObjImageLib](by-global/g_pLightObjImageLib.md)

## Changes

- 2026-06-11 A002 Batch 175 live evidence refresh:
  - What existed before: the vtable page was already assigned at `86/91`, with exact child memory evidence and a corrected class parent from Batch 139.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:92`, plus a new dated live-IDB recheck.
  - Summary/evidence: IDA MCP `py_eval` reconfirmed the `NexusTK.exe` root, adjacent `ProtectedArray<LightInfo>` split, `LightObjImageLib` RTTI/vtable dwords, all five target function boundaries, constructor/destructor/scalar-deleting xrefs to `0x0061b754`, and the `NewHumanImageLib` boundary at `0x0061b768`. Completion remains below final-source quality because inherited/shared slot `0x004f4b10` and final virtual method declarations are not fully named here.
- 2026-06-20 B001 inherited-slot wording:
  - Score unchanged at `88/92`.
  - Summary/evidence: B001 disassembled `0x004f4b10` as a return of the `LObject` descriptor/name block and `0x0041b6c0` as a `ret 8` no-op. The slot labels now use inherited `LObject` runtime/type helper and inherited/default no-op virtual wording, while exact central base-interface names remain outside the LightObjImageLib vtable page.
- 2026-06-08 A007 Batch 139 gate update:
  - What existed before: the vtable page was `82/90`, had no autogen parent, and relied on the broad image-library aggregate plus vtable-slot prose.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, `AUTOGEN_PARENT_UID:000076`, and an exact backing child link to [UID:00031S][0x0061b750-0x0061b768.LightObjImageLibVtableData](by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md).
  - Summary/evidence: Batch 139 exact child evidence records the RTTI/vtable dwords, five target slots, xrefs, and neighboring `ProtectedArray<LightInfo>` / `NewHumanImageLib` boundaries; [UID:000076][LightObjImageLib](by-class/LightObjImageLib.md) and [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) were refreshed enough to satisfy the strict parent gate.
- 2026-05-31 LightObjImageLib split pass:
  - What existed before: metadata scores were `0/0`, and vtable slots pointed to unlinked address labels.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, with exact method child references for the deleting destructor and draw slots.
  - Summary/evidence: IDA MCP verified RTTI/vtable dwords at `0x0061b750-0x0061b768`, xrefs from constructor/destructors, and the adjacent `ProtectedArray<LightInfo>` vtable. Completion remains below near-final because inherited/shared slot `0x004f4b10` and final source declaration shape are not fully documented here.
