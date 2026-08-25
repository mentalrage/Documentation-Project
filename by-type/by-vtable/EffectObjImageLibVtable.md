*** UID:0001XG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004A | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectObjImageLib Vtable

## Status

- Confidence: very strong for address, RTTI locator, all three slot identities, direct hierarchy, PMD/EBO, adjacent boundaries, and vptr-store xrefs.
- Owner class: [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md).
- Exact memory page: [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md).
- Backing aggregate page: [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md).
- Source disposition: false/non-emitting compiler vtable/RTTI evidence owned by [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). The complete class declaration regenerates the table; this page has an exactly blank formal block and emits no marker or raw table.
- RTTI pointer: `0x0061b720` -> `0x00648df4` (`??_R4EffectObjImageLib@@6B@`).
- Primary vtable: `0x0061b724` (`??_7EffectObjImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e62f0` | compiler scalar deleting destructor generated from `virtual ~EffectObjImageLib()` |
| `+0x04` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| `+0x08` | `0x0041b6c0` | inherited `LObject::OnChangeMessage` default (`nullsub_18`) |

The table ends before the `ProtectedArray<ItemInfo>` RTTI pointer at `0x0061b730` and its vtable at `0x0061b734`.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e62f0` -> `sub_4E62F0`, size `0x166`, scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b714` is the preceding `ProtectedArray<EffectInfo>` vtable.
  - `0x0061b71c` is the preceding `ProtectedArray<EffectPixMapInfo>` vtable.
  - `0x0061b720` dword `0x00648df4` -> `??_R4EffectObjImageLib@@6B@`.
  - `0x0061b724` dword `0x004e62f0` -> `sub_4E62F0`, xrefs from `0x004ddfb0`, `0x004de07d`, and `0x004e6324`.
  - `0x0061b728` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b72c` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b730` dword `0x00648fc4` -> `??_R4?$ProtectedArray@UItemInfo@@@@6B@`, proving the next template-vtable boundary.
- IDA names in the same region include `??_7EffectObjImageLib@@6B@`, `??_R4EffectObjImageLib@@6B@`, and the associated `Singleton<EffectObjImageLib>` RTTI records at `0x00648e44-0x00648e78`.

RTTI hierarchy parsing identifies direct bases `LObject` and `Singleton<EffectObjImageLib>`. The Singleton base descriptor PMD is `+4/-1/0`, proving the EBO-adjusted base that publishes/clears `g_pEffectObjImageLib`; it does not add another virtual table or source slot. Comparison with the documented LObject contract resolves `0x004f4b10` as `LObject::GetRuntimeClass` and `0x0041b6c0` as the inherited default `LObject::OnChangeMessage` implementation.

IDA xrefs to `0x0061b724` land at:

- `0x004ddfb0` in [UID:00017K][0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster](by-memory/0x004ddf60-0x004dec30.EffectObjImageLibLocalMethodCluster.md)
- `0x004de07d` in [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)
- `0x004e6324` in the scalar deleting destructor

Generated `class_EffectObjImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `EffectObjImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

No hand-written vtable source or explanatory marker is emitted here. Source declarations and method bodies attach through the owning class/file and exact `by-memory` method pages; false metadata and the blank block prevent raw-table or proof-comment duplication.

## Parent Rationale

Attach this generated-binary vtable page to [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md). The page describes only the `EffectObjImageLib` primary vtable and RTTI locator, the owner class already clears the `80/80` attachment gate and is attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), and the neighboring template vtables are documented as boundaries rather than part of this class.

## Score Rationale

Completion is `92` because the exact COL/table boundaries, all three slot identities, three lifecycle stores, direct RTTI hierarchy, PMD/EBO relationship, source owner, and blank compiler-generated disposition are closed. Confidence is `95` because the dwords, functions, inherited LObject contract, and direct bases are exact; compiler/linker address equivalence remains outside the source-quality claim.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)

## Changes

- 2026-07-21 B004 UID0001PQ source-quality callback:
  - Raised `85/90` to `92/95`, changed reconstructable true/emitter UID00004A/comment marker to false/blank emitter/exactly blank formal C++, and retained UID00004A as compiler-artifact owner.
  - Resolved all three slots as compiler scalar deleting support, inherited `LObject::GetRuntimeClass`, and inherited default `LObject::OnChangeMessage`; preserved exact dwords, COL, addresses, three vptr stores, and adjacent ProtectedArray boundaries.
  - Added direct `EffectObjImageLib`/`LObject`/`Singleton<EffectObjImageLib>` RTTI hierarchy and Singleton PMD `+4/-1/0` EBO evidence. The complete class declaration is the source carrier; this page emits neither raw dwords nor a marker.

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `84/90`, blank formal block.
  - After: `85/90`, formal source-declared/generated-binary marker attached under [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, RTTI locator/vtable dwords, slot `0x0061b724 -> 0x004e62f0`, inherited/shared slot `0x004f4b10`, `nullsub_18`, and three vptr-store xrefs to reject hand-emitted vtable bytes while preserving generated-binary reconstruction responsibility.

- 2026-06-07 parent attachment update:
  - What existed before: the page had strong RTTI/vtable evidence and an exact memory child, but no autogen parent.
  - Changed to: `COMPLETION:84` and `AUTOGEN_PARENT_UID:00004A`, with an explicit class-parent rationale.
  - Summary/evidence: the vtable page covers only the `EffectObjImageLib` primary vtable at `0x0061b724`; [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md) clears the attachment gate, and the adjacent `ProtectedArray` vtables remain documented as non-owner boundaries.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the exact [UID:0002MK][0x0061b720-0x0061b730.EffectObjImageLibVtableData](by-memory/0x0061b720-0x0061b730.EffectObjImageLibVtableData.md), RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, preceding `ProtectedArray<EffectInfo>` / `ProtectedArray<EffectPixMapInfo>` vtables, and next `ProtectedArray<ItemInfo>` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding EffectObjImageLib method dependencies are not final-audited.
