*** UID:00001I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CashShopVersionRequest

## Status

- Confidence: strong for vtable/destructor and request-payload behavior; medium for final submit-helper owner.
- Proposed source module: [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- Autogen parent: [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- Method count: 2
- Evidence basis: live IDA MCP lookup/decompile/xref checks on 2026-06-03.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 82 | The class has a valid file parent, exact vtable/destructor evidence, read-only vtable island coverage, documented payload allocation through the submit helper, the fitting-room caller, and explicit FileDownloader ownership caveats. It is not higher because the submit helper is still receiver-owned by the FileDownloader singleton rather than proven as a class method, and the final request/base-class declaration is not source-quality. |
| Confidence | 88 | Live IDA confirms the `CashShopVersionRequest` RTTI/vtable, the scalar deleting destructor slot, the payload allocation/vtable write, and the only direct submit-helper caller. Confidence remains below final-source level because `0x0041b270` is called on `dword_67A738`, whose writes belong to FileDownloader. |

## Role

Tiny request-payload class for cash-shop/fitting-room version checks. The confirmed class-owned surface is the RTTI/vtable at `0x0060d794/0x0060d798` and the scalar deleting destructor at `0x0041b5e0`.

The nearby submit helper at `0x0041b270` allocates a `0x10` byte payload, installs the `CashShopVersionRequest` vtable, and posts downloader message `10002`. Keep that helper source-owner provisional because the live receiver is [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, whose direct writes belong to FileDownloader constructor/destructor paths.

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
| `0x0060d794/0x0060d798` RTTI/vtable | Class-owned binary identity; compiler-emitted in the cash-shop/fitting-room rdata island | [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md) records the request vtable immediately after the `CashShopVersionRequest` RTTI pointer. |
| `0x0041b5e0-0x0041b604` scalar deleting destructor | Class-owned method wrapper | [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md) restores the request vtable and optionally deletes the object. |
| `0x0041b270-0x0041b2c9` submit helper | Cross-linked, not class-owned yet | Receiver/caller evidence routes through `dword_67A738`, whose lifetime is documented with FileDownloader constructor/destructor paths. |

## Related Free Functions

- `0x0041aa00-0x0041ae1b`: `DownloadCashShopVersion_41AA00`.
- `0x0041ae20-0x0041b10b`: `DownloadCashShopCatalog_41AE20`.

These are dispatched by [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and documented with this class/fitting-room path for feature semantics.

## Live IDA Evidence

- 2026-06-03 `lookup_funcs` confirms `0x0041b270-0x0041b2c9`, `0x0041b5e0-0x0041b604`, `0x0041aa00-0x0041ae1c`, `0x0041ae20-0x0041b10c`, `0x0041b110-0x0041b180`, and the fitting-room constructor `0x0041bdd0-0x0041c250`.
- Decompilation of `0x0041b270` allocates `0x10` bytes, writes `CashShopVersionRequest::vftable` at offset `0`, zeroes payload fields at `+4/+8/+0xc`, and calls `sub_596960(this, 10002, payload, 0)`. The allocation-failure path posts message `10002` with a null payload.
- Decompilation of `0x0041bdd0` calls `sub_41B270((void *)dword_67A738)` at `0x0041c21b`, tying the submit request to the FileDownloader-lifetime singleton.
- The vtable data around `0x0060d794` has RTTI `??_R4CashShopVersionRequest@@6B@` followed by slot `0x0060d798 -> 0x0041b5e0`; xrefs to `0x0060d798` come only from the payload constructor helper and the scalar deleting destructor.
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md) records the vtable entry as the first project-owned item in the broader cash-shop/fitting-room read-only data island.
- Xrefs to `0x0067a738` include direct writes in `0x0041a670`, `0x0041a6f0`, `0x0041b2f0`, and `0x0041b610`, all FileDownloader constructor/destructor-family paths. Reads from fitting-room code pass the singleton into submit helpers.

## Cross-References

- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md)
- [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md)

## Changes

- Before: confirmed methods were listed by address only.
- After: the class is attached to [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md), marked reconstructable, and scored higher based on fresh live IDA evidence for vtable, destructor, submit allocation, fitting-room caller, and FileDownloader singleton lifetime.
- Summary/evidence: 2026-06-03 IDA MCP recheck confirms the class-owned destructor/vtable while keeping the `0x0041b270` submit helper source-owner provisional because the receiver is `dword_67A738`.
- 2026-06-07 A004: Completion changed from `78` to `82`; confidence remains `88`.
  - Summary/evidence: synced the class page with the refreshed [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) file boundary, added an ownership-boundary table for the payload, read-only vtable island, scalar destructor, and FileDownloader submit helper, and linked [UID:00024M][0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md).
  - Remaining blockers: final helper ownership, request/base-class declaration spelling, and payload field names still keep the page below final-source level.
