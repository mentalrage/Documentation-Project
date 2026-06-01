*** UID:00001I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CashShopVersionRequest

## Status

- Confidence: strong for method behavior.
- Current Wave3 file: `class_CashShopVersionRequest.cpp`
- Proposed source module: [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- Method count: 2
- Evidence basis: Wave3 inspection and IDA MCP lookup/xref checks through 2026-05-25.

## Role

Tiny request wrapper for cash-shop/fitting-room version checks. It allocates a request payload, submits request ID `10002`, and is constructed from the fitting-room dialog setup path. The final owner of the submission helper is provisional because the live receiver argument is [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738`, whose lifetime is FileDownloader-owned.

## Confirmed Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) | `SendVersionRequest` | Allocates and dispatches version request payload `10002`; IDA caller is `0x0041bdd0`, passing `dword_67A738`. |
| [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md) | `ScalarDeletingDestructor` | Small destructor/delete wrapper. |

## Related Free Functions

- `0x0041aa00-0x0041ae1b`: `DownloadCashShopVersion_41AA00`.
- `0x0041ae20-0x0041b10b`: `DownloadCashShopCatalog_41AE20`.

These are dispatched by [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and documented with this class/fitting-room path for feature semantics.

## Cross-References

- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0000WJ][0x0041aa00-0x0041b2c8.CashShopVersionAndCatalogDownload](by-memory/0x0041aa00-0x0041b2c8.CashShopVersionAndCatalogDownload.md)
- [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md)
- [UID:0002CN][0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor](by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md)

## Changes

- Before: confirmed methods were listed by address only.
- After: both confirmed methods point to exact `by-memory` pages.
- Summary/evidence: IDA MCP confirmed the submit helper and scalar deleting destructor boundaries; the submit helper remains source-owner provisional because the receiver is `dword_67A738`.
