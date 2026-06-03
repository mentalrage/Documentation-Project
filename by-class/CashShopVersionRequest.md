*** UID:00001I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
| Completion | 78 | The class now has a valid file parent, exact vtable/destructor evidence, a documented fitting-room submit call, and explicit FileDownloader ownership caveats. It is not higher because the submit helper is still receiver-owned by the FileDownloader singleton rather than proven as a class method. |
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

## Related Free Functions

- `0x0041aa00-0x0041ae1b`: `DownloadCashShopVersion_41AA00`.
- `0x0041ae20-0x0041b10b`: `DownloadCashShopCatalog_41AE20`.

These are dispatched by [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and documented with this class/fitting-room path for feature semantics.

## Live IDA Evidence

- 2026-06-03 `lookup_funcs` confirms `0x0041b270-0x0041b2c9`, `0x0041b5e0-0x0041b604`, `0x0041aa00-0x0041ae1c`, `0x0041ae20-0x0041b10c`, `0x0041b110-0x0041b180`, and the fitting-room constructor `0x0041bdd0-0x0041c250`.
- Decompilation of `0x0041b270` allocates `0x10` bytes, writes `CashShopVersionRequest::vftable` at offset `0`, zeroes payload fields at `+4/+8/+0xc`, and calls `sub_596960(this, 10002, payload, 0)`. The allocation-failure path posts message `10002` with a null payload.
- Decompilation of `0x0041bdd0` calls `sub_41B270((void *)dword_67A738)` at `0x0041c21b`, tying the submit request to the FileDownloader-lifetime singleton.
- The vtable data around `0x0060d794` has RTTI `??_R4CashShopVersionRequest@@6B@` followed by slot `0x0060d798 -> 0x0041b5e0`; xrefs to `0x0060d798` come only from the payload constructor helper and the scalar deleting destructor.
- Xrefs to `0x0067a738` include direct writes in `0x0041a670`, `0x0041a6f0`, `0x0041b2f0`, and `0x0041b610`, all FileDownloader constructor/destructor-family paths. Reads from fitting-room code pass the singleton into submit helpers.

## Cross-References

- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md)

## Changes

- Before: confirmed methods were listed by address only.
- After: the class is attached to [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md), marked reconstructable, and scored higher based on fresh live IDA evidence for vtable, destructor, submit allocation, fitting-room caller, and FileDownloader singleton lifetime.
- Summary/evidence: 2026-06-03 IDA MCP recheck confirms the class-owned destructor/vtable while keeping the `0x0041b270` submit helper source-owner provisional because the receiver is `dword_67A738`.
