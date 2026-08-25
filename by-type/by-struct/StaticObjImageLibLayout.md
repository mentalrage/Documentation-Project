*** UID:0001W9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib Layout

## Status

- Confidence: near-certain for exact size, direct bases, Singleton PMD/EBO placement, field offsets, and owner; source-facing private spellings remain inferred.
- Owner class: [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md).
- Evidence: IDA constructor/destructor/render/bounds decompilation rechecked through Batch 132.
- Assignment: attached to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) after this layout reached `85/88` and the direct class parent is `86/85`.

## Layout

```text
StaticObjImageLib
  +0x00  LObject/vtable
  +0x04  empty Singleton<StaticObjImageLib> base address (EBO overlap)
  +0x04  ArchiveMetadataTable* tileCatalog
  +0x08  TileClassEntry* tileClasses
  +0x0c  StaticObjEntry** staticObjEntries
  +0x10  int staticObjCount
  sizeof 0x14
```

## Notes

- The constructor fills `+0x0c` with `staticObjCount` heap pointers to variable-size [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) records loaded from `SOBJ.TBL`.
- The constructor fills `+0x08` with four-byte [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md) records loaded from `TILEC.TBL` or `TILEC.TBD`.
- `RenderStaticObject` resolves `staticObjEntries[staticObjectId - 1]`, reads its layer count from entry offset `+0x05`, and walks tile ids from entry offset `+0x0c`.
- The ordinary and scalar deleting destructors release the static-object records, tile catalog/cache chain, tile-class table, and [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md).
- B007 accepts `tileCatalog`, `tileClasses`, `staticObjEntries`, and `staticObjCount` as source-facing descriptive names for first-draft C++. These are stronger than raw offsets and good enough for class/method C++ sketches, but they are still not proven original identifiers.
- The `tileClasses` member points to [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md) rows with `tileFrameId`, `allowPaletteFilter`, and `reserved`. The `staticObjEntries` member points to [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) rows with lighting/layer/cache-chain fields.
- RTTI identifies direct bases `LObject` and `Singleton<StaticObjImageLib>`. The Singleton base-class descriptor PMD is `mdisp=+4`, `pdisp=-1`, `vdisp=0`.
- Constructor EH state 1 adjusts ECX from the complete object to `this+4` before tail-jumping to [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md). This independently binds the PMD to the empty base subobject.
- The complete allocation and scalar-delete size are `0x14`, so the Singleton base adds no independent storage. Its address overlaps `tileCatalog` at `+0x04` under empty-base optimization. Do not add a fake base field, hidden pointer, or padding member.
- The ordinary/scalar machine code clears the singleton before `LObject` cleanup because direct bases are destroyed in reverse source order. This clear is lifecycle behavior, not a derived data member.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x004dcf60` confirms the constructor stores the singleton at `0x0069b448`, installs `StaticObjImageLib` vtable at `+0x00`, writes the TILEC archive metadata pointer to `+0x04`, writes the tile-class table pointer to `+0x08`, writes the static-object entry pointer array to `+0x0c`, and keeps the static-object count at `+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x004dd2c0` confirms `RenderStaticObject` resolves entries through `this+0x0c`, checks the object id against `this+0x10`, and uses `this+0x04`/`this+0x08` to resolve frame metadata and tile-class flags.
- 2026-05-31 IDA MCP decompilation of `0x004dd850` confirms bounds lookup uses `this+0x0c` and `this+0x10`.
- 2026-05-31 IDA MCP decompilation of `0x004dd1e0` confirms destructor ownership of the entry array at `+0x0c`, tile catalog/cache at `+0x04`, tile-class table at `+0x08`, and singleton clear at `0x0069b448`.
- 2026-06-08 Batch 132 IDA MCP recheck confirms the constructor at `0x004dcf60` publishes [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md), writes the `StaticObjImageLib` vtable at `+0x00`, opens `SOBJ.TBL`, stores the entry count at `+0x10`, allocates the entry pointer array at `+0x0c`, builds per-entry records with layer count at entry `+0x05`, and initializes `+0x04`/`+0x08` from the `TILEC` resource path.
- The same recheck confirms `RenderStaticObject` at `0x004dd2c0` uses `this+0x0c` for entry pointers, `this+0x10` for the object-id bound, `this+0x04` for frame metadata, and `this+0x08` for tile-class flags; `GetStaticObjectBounds` at `0x004dd850` uses the same entry/count pair to compute local bounds.
- UID000184 RTTI/EH reanalysis decodes the direct Singleton BCD at `0x00648da4` as PMD `+4,-1,0`, matches it to constructor state-1 ECX adjustment, and confirms `0x14` complete-object size through allocation/deleting-wrapper evidence. These facts close the previously undocumented empty-base relationship without changing any derived field offset.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md). This layout page is `92/97`, the direct class parent is `92/96`, and file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) is `90/94`. The relationship is direct: this page records the class's exact complete-object storage, including EBO for its direct Singleton base.

## Score Rationale

- `COMPLETION:92`: the page records exact `0x14` storage, both direct bases, Singleton PMD/EBO overlap, all four derived fields, constructor stores, renderer/bounds use, reverse destruction, dependent records, and parent/source route.
- `CONFIDENCE:97`: constructor, renderer, bounds, destructor, scalar delete size, RTTI hierarchy/PMD, and EH receiver adjustment agree on every offset and the no-fake-member conclusion. Original private member spellings remain inferred but do not weaken the measured layout.

## Historical Superseded Assumptions

- Earlier layout text showed only `LObject` plus derived fields and described singleton clearing generically. It was incomplete rather than wrong about the four derived offsets. UID000184 adds the direct empty Singleton base and proves its `+0x04` EBO overlap.
- A separate hidden Singleton field is rejected: RTTI PMD, adjusted EH receiver, `0x14` allocation, and field accesses all require an empty base sharing the `+0x04` address.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)

## Changes

- 2026-08-11 B005 UID000184 lifecycle implementation: raised `85/88` to `92/97`, preserved owner/emitter UID0000E2 and blank formal channels, and added the direct Singleton base, PMD `+4,-1,0`, EBO overlap, exact `0x14` size, reverse destruction, and no-fake-member proof.

- 2026-06-08 A003 Batch132:
  - Before: `78/86`, parent blank, with good field-offset notes but no strict-gate assignment section.
  - After: `85/88`, `AUTOGEN_PARENT_UID:0000E2`.
  - Evidence: live IDA MCP rechecked constructor, destructor, render, bounds, vtable, and singleton usage. The direct class parent [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) is `86/85` and the file parent [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) is `86/85`, so the corrected child-and-parent gate is met.

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing field-offset notes. Changed to `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, renderer, bounds helper, and destructor field use. The score remains below the final-source threshold because final source field names and all dependent helper/data-table pages are not yet audited to near-final quality.
- 2026-06-21 B007 Rule 26 incorporation:
  - Scores unchanged at `85/88`.
  - Evidence: recorded B007's accepted source-facing field names for the class layout and tied them to the updated `StaticObjEntry` and `TileClassEntry` field conclusions. The names support first-draft C++ but remain descriptive inferences rather than final original spellings.
