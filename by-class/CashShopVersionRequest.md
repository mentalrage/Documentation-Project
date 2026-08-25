*** UID:00001I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CashShopVersionRequest : public BaseRequest
{
public:
    virtual ~CashShopVersionRequest() {}
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CashShopVersionRequest

## Status

- Confidence: strong for vtable/destructor identity, exact BaseRequest-derived layout, and request-payload behavior; high for the coordinated FileDownloader module route.
- Current reconstruction source module and autogen parent: [UID:0000JC][FileDownloader](by-file/FileDownloader.md), emitter position `1`.
- Historical alias: [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) preserves prior standalone-file evidence with reconstruction path `NONE`.
- Method count: 2
- Evidence basis: live IDA MCP lookup/decompile/xref checks on 2026-06-03.

## Item Summary

- `CashShopVersionRequest` is the compact polymorphic request payload used by the FileDownloader version-check path. [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) allocates it and posts downloader message `10002`; the class owns the payload type, vtable, RTTI, and destructor identity, while the submit helper and HTTP worker remain FileDownloader-owned operations.
- The complete object is exactly `0x10` bytes. Offset `+0x00` is the derived vptr. Offsets `+0x04..+0x0f` are the inherited non-polymorphic [UID:00050F][BaseRequest](by-class/BaseRequest.md) subobject, whose source size is `0x0c`: byte-like `downloadComplete` at base offset `+0x00` followed by alignment, `contentLength` at base offset `+0x04`, and `bytesDownloaded` at base offset `+0x08`. The derived class has no additional data fields.
- The inheritance/layout conclusion is convergent rather than name-only inference. RTTI describes `CashShopVersionRequest` plus `BaseRequest` at PMD `4/-1/0`; the submit helper allocates `0x10` bytes, zeroes complete-object offsets `+4`, `+8`, and `+0xc`, and writes the derived vtable; [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md) restores that same vtable before optional deletion. These independent facts agree on a vptr plus a `0x0c` base and no derived member storage.
- The exact class-owned read-only surface is [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md): hidden complete-object-locator/RTTI dword `0x0060d794` and public vtable slot `0x0060d798 -> 0x0041b5e0`. The scalar-deleting destructor and RTTI/vtable records are compiler-generated consequences of a virtual destructor, not separate handwritten raw-source functions or tables.
- The source cause for the sole virtual slot is the inline virtual destructor in the formal H declaration. The formal header therefore remains `class CashShopVersionRequest : public BaseRequest` with `virtual ~CashShopVersionRequest() {}` and no derived fields. The formal CPP body remains exactly `[[CHILDREN]]`; handwritten source must not duplicate the compiler-generated scalar-deleting wrapper, RTTI, vtable, or complete-object locator.
- The coordinated source route is [UID:0000JC][FileDownloader](by-file/FileDownloader.md), emitter position `1`, with class artifact owner [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md). Receiver evidence supports this placement: live caller `0x0041bdd0` passes `dword_67A738` / [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) to the submit helper, and direct writes to that singleton belong to FileDownloader constructor/destructor paths. The nearby [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) worker is likewise FileDownloader-local rather than a payload-class method.
- Current metadata reflects that disposition: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000JC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC`, and `EMITTER_POSITION_OPTIONAL:1`. Confidence remains below `95` because exact original lexical spellings and the historical physical file boundary are inferred, not because the binary layout, inheritance, virtual-slot cause, behavior, or active source route remain unresolved.
- Rejected historical assumptions are retained rather than erased. Earlier documentation flattened complete-object offsets `+4/+8/+0xc` into direct fields named `state`, `contentLength`, and `bytesDownloaded`; RTTI PMD `+4` and the shared BaseRequest reconstruction supersede that model with inherited `downloadComplete`, `contentLength`, and `bytesDownloaded`. The former standalone [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) source file remains a historical alias with reconstruction path `NONE`; the higher-probability human-written source shape places the small payload declaration with the shared request types and FileDownloader implementation. Raw RTTI/vtable data, the deleting thunk, decompiler temporaries, explicit padding members, and the downloader queue machinery are also rejected as handwritten class source.

## FileDownloader Version Download Context

B001's 2026-06-18 source-quality pass confirmed this class as the small request payload for FileDownloader message `10002`, initially describing `state` at `+0x04`, `contentLength` at `+0x08`, and `bytesDownloaded` at `+0x0c`. The coordinated 2026-08-03 audit resolves those three slots as the inherited [UID:00050F][BaseRequest](by-class/BaseRequest.md) subobject: `downloadComplete`, `contentLength`, and `bytesDownloaded`. [UID:0002TS][0x0041aa00-0x0041ae1c.DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) remains a FileDownloader-local HTTP worker; this class owns the derived payload identity, vtable, and destructor context without adding derived data fields.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 93 | The class has an exact inherited H declaration, `[[CHILDREN]]` CPP route, exact vtable/destructor evidence, exact [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md), documented `0x10` allocation, and coordinated [UID:0000JC][FileDownloader](by-file/FileDownloader.md) source placement. |
| Confidence | 94 | Live RTTI proves the two-base hierarchy and BaseRequest PMD `+4`; allocation, zeroing, vtable write, submit caller, and scalar destructor agree on a `0x10` object with no derived fields. Exact lexical spelling and historical file boundaries remain inferred, keeping the page below `95/95`. |

## Role

Tiny `BaseRequest`-derived request-payload class for cash-shop/fitting-room version checks. The complete object is `0x10` bytes: derived vptr at `+0x00`, inherited non-polymorphic BaseRequest subobject at `+0x04` through `+0x0f`, and no derived data fields. The confirmed class-owned binary surface is the RTTI/vtable at `0x0060d794/0x0060d798` and the scalar deleting destructor at `0x0041b5e0`.

The nearby submit helper at `0x0041b270` allocates a `0x10` byte payload, installs the `CashShopVersionRequest` vtable, initializes the inherited BaseRequest fields, and posts downloader message `10002`. Its source owner is [UID:00004W][FileDownloader](by-class/FileDownloader.md): the live receiver is [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, whose direct writes belong to FileDownloader constructor/destructor paths. The historical `g_pCashShopRequest` spelling remains an alias, not a reason to move the helper into this payload class.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | `0x0060d798` vtable slot points here; body restores the class vtable and conditionally calls delete. |

## Related Submit Helper

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | `SubmitCashShopVersionRequest` / provisional | Allocates the `CashShopVersionRequest` payload and posts downloader message `10002`; live caller `0x0041bdd0` passes `dword_67A738`, so this remains FileDownloader-receiver evidence rather than a class-owned method. |

## Ownership Boundary

| Item | Class handling | Evidence |
| --- | --- | --- |
| `0x10` byte request payload | Class-owned declaration evidence | [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) allocates the payload, installs the `CashShopVersionRequest` vtable, zeroes fields at `+4/+8/+0xc`, and queues message `10002`. |
| `0x0060d794/0x0060d798` RTTI/vtable | Class-owned binary identity; compiler-emitted in the cash-shop/fitting-room rdata island | Exact child [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md) records the RTTI pointer and vtable slot. |
| `0x0041b5e0-0x0041b604` scalar deleting destructor | Class-owned method wrapper | [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md) restores the request vtable and optionally deletes the object. |
| `0x0041b270-0x0041b2c9` submit helper | FileDownloader-owned, payload-related | Receiver/caller evidence routes through `dword_67A738`, whose lifetime is documented with FileDownloader constructor/destructor paths; this class supplies the allocated payload type only. |

## 2026-08-03 B008 BaseRequest And Module Consolidation

- CashShopVersionRequest RTTI records two bases: the derived class at PMD `0/-1/0` and non-polymorphic BaseRequest at PMD `4/-1/0`. This resolves the earlier `state`/three-direct-fields description into an inherited base subobject.
- [UID:00050F][BaseRequest](by-class/BaseRequest.md) has source size `0x0c` and fields `downloadComplete`, `contentLength`, and `bytesDownloaded`. The derived vptr occupies `+0x00`, the base begins at `+0x04`, and the full derived size is exactly `0x10`; no separate CashShopVersionRequest member remains.
- The exact H block now declares `CashShopVersionRequest : public BaseRequest` with an inline virtual destructor. The exact CPP block is `[[CHILDREN]]`; compiler-generated RTTI/vtable and scalar-deleting wrapper data do not become handwritten source.
- Physical and behavioral clustering place the declaration with BaseRequest, CashShopRequest, and FileDownloader in [UID:0000JC][FileDownloader](by-file/FileDownloader.md). [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) remains a detailed historical alias with path `NONE` rather than being pruned.
- The old `state` name and separate CPP placement are preserved as superseded assumptions. The highest-probability human source shape uses the shared `downloadComplete` base field and one coordinated header/source module.

## Related Free Functions

- `0x0041aa00-0x0041ae1b`: `DownloadCashShopVersion_41AA00`.
- `0x0041ae20-0x0041b10b`: `DownloadCashShopCatalog_41AE20`.

These are dispatched by [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and documented with this class/fitting-room path for feature semantics.

## Live IDA Evidence

- 2026-06-03 `lookup_funcs` confirms `0x0041b270-0x0041b2c9`, `0x0041b5e0-0x0041b604`, `0x0041aa00-0x0041ae1c`, `0x0041ae20-0x0041b10c`, `0x0041b110-0x0041b180`, and the fitting-room constructor `0x0041bdd0-0x0041c250`.
- Decompilation of `0x0041b270` allocates `0x10` bytes, writes `CashShopVersionRequest::vftable` at offset `0`, zeroes payload fields at `+4/+8/+0xc`, and calls `sub_596960(this, 10002, payload, 0)`. The allocation-failure path posts message `10002` with a null payload.
- Decompilation of `0x0041bdd0` calls `sub_41B270((void *)dword_67A738)` at `0x0041c21b`, tying the submit request to the FileDownloader-lifetime singleton.
- The vtable data around `0x0060d794` has RTTI `??_R4CashShopVersionRequest@@6B@` followed by slot `0x0060d798 -> 0x0041b5e0`; xrefs to `0x0060d798` come only from the payload constructor helper and the scalar deleting destructor.
- [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md) records the class RTTI pointer and vtable slot as an exact child of the broader [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) island.
- Xrefs to `0x0067a738` include direct writes in `0x0041a670`, `0x0041a6f0`, `0x0041b2f0`, and `0x0041b610`, all FileDownloader constructor/destructor-family paths. Reads from fitting-room code pass the singleton into submit helpers.

## Cross-References

- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:00050F][BaseRequest](by-class/BaseRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md)
- [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md)
- [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md)

## Changes

- 2026-08-03 B008 UID0003FS inheritance/module implementation:
  - Changed `85/89` to `93/94`, owner/emitter from historical alias [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) to coordinated [UID:0000JC][FileDownloader](by-file/FileDownloader.md), and emitter position from blank to `1`.
  - Added the exact BaseRequest-derived H declaration and exact `[[CHILDREN]]` CPP route; documented the `0x10` object as a derived vptr plus `0x0c` BaseRequest subobject with no derived fields.
  - Preserved the former `state` and standalone-file conclusions as dated history and recorded why RTTI PMD `+4`, allocation size, zeroing order, destructor/vtable, and FileDownloader receiver evidence supersede them.

- 2026-06-18 B001 FileDownloader support sync: added the resolved version-request payload fields and clarified the worker-vs-payload ownership split.

- Before: confirmed methods were listed by address only.
- After: the class is attached to [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md), marked reconstructable, and scored higher based on fresh live IDA evidence for vtable, destructor, submit allocation, fitting-room caller, and FileDownloader singleton lifetime.
- Summary/evidence: 2026-06-03 IDA MCP recheck confirms the class-owned destructor/vtable while keeping the `0x0041b270` submit helper source-owner provisional because the receiver is `dword_67A738`.
- 2026-06-07 A004: Completion changed from `78` to `82`; confidence remains `88`.
  - Summary/evidence: synced the class page with the refreshed [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) file boundary, added an ownership-boundary table for the payload, read-only vtable island, scalar destructor, and FileDownloader submit helper, and linked [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md).
  - Remaining blockers: final helper ownership, request/base-class declaration spelling, and payload field names still keep the page below final-source level.
- 2026-06-12 A003 Batch255 vtable split:
  - Before: `82/88`; the class linked only the broad mixed read-only island for its vtable evidence.
  - Changed to: `85/89`; exact [UID:0003FR][0x0060d794-0x0060d79c.CashShopVersionRequestVtableData](by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md) now carries the RTTI/vtable dwords and routes here.
  - Summary/evidence: live IDA MCP dword/xref scan reconfirmed `0x0060d794 -> ??_R4CashShopVersionRequest@@6B@`, `0x0060d798 -> sub_41B5E0`, and vtable refs from the payload setup/destructor. The file parent is raised to the strict gate in the same pass.
