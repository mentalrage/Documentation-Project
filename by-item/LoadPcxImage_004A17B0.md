*** UID:0000UZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadPcxImage 0x004A17B0

## Status

- Confidence: strong for behavior, caller family, and ImageLoaders ownership; medium for final original helper name.
- Entity kind: free image-loader helper.
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Exact range: `0x004a17b0-0x004a18a8`
- Signature evidence: `_DWORD *__cdecl sub_4A17B0(HDC hdc, const char *Src, int a3)` in IDA, matching historical `DIBitmap* __cdecl LoadPcxImage(HDC hdc, const char *fileName, int transparentIndex)`.

## Behavior

`LoadPcxImage` converts an ANSI PCX path to the wide-string path format used by the shared file helper, checks whether the resource exists, opens a 0x14-byte file-buffer object, retrieves its raw data pointer and size, closes the file-buffer object, and passes non-null bytes to `CreateDIBitmapFromPcxBuffer`. It returns null when the resource existence check fails or when the opened buffer has no data pointer.

The third argument is forwarded unchanged to `CreateDIBitmapFromPcxBuffer`, where it is used as the transparent palette index for the PCX-to-DIB conversion. Both observed startup callers pass either `-1` or resource-specific transparent values through this wrapper; the function itself does not interpret the value.

## IDA Evidence

IDA MCP recheck on 2026-06-02 confirms `sub_4A17B0` starts at `0x004a17b0`, has size `0xf8`, and ends half-open at `0x004a18a8`. The next function, [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md), begins at `0x004a18b0`; the bytes from `0x004a18a8-0x004a18af` are `0xcc` alignment padding.

The IDA decompile shows this call flow:

| Address | Operation | Notes |
| --- | --- | --- |
| `0x004a17de` | `sub_582730(&localAnsi, Src)` | Builds the temporary ANSI string wrapper from the caller path. |
| `0x004a17f0` | `sub_582830(..., &localWide)` | Converts the path wrapper into the wide-string form used by file helpers. |
| `0x004a180a` | `sub_49C700(widePath)` | [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) existence check; null return path starts here when false. |
| `0x004a1818` | `sub_4F4AA0(20)` | Allocates the 0x14-byte file-buffer/DATFile object. |
| `0x004a1832` | `sub_49C130` | Constructs/initializes the file-buffer object. |
| `0x004a1849` | vtable slot `+0x0c` | Opens/loads the wide path into the file-buffer object. |
| `0x004a1857` | `sub_49C550` | Retrieves the raw byte pointer. |
| `0x004a1860` | vtable slot `+0x1c` | Retrieves the byte count. |
| `0x004a1863` | vtable slot `+0x10` | Closes/releases the loaded file handle state before decode. |
| `0x004a187e` | `sub_4A18B0(hdc, bytes, size, a3)` | Builds the `DIBitmap` from the PCX buffer when bytes are non-null. |
| `0x004a1886` | scalar deleting destructor call | Destroys the temporary file-buffer object. |
| `0x004a188f` | `sub_582B70(&localWide)` | Destroys the converted wide-string wrapper before returning. |

## Caller Evidence

IDA MCP confirms twelve direct code references to `0x004a17b0`: six inside the modeled startup update window procedure and six in the raw notice helper body that IDA does not currently assign to a function.

| PCX literal | String address | Modeled caller ref | Raw helper ref |
| --- | ---: | ---: | ---: |
| `brm_main.pcx` | `0x0062d530` | `0x00581227` | `0x005818f1` |
| `brm_st_a.pcx` | `0x0062d540` | `0x00581237` | `0x00581901` |
| `brm_st_b.pcx` | `0x0062d550` | `0x00581246` | `0x00581911` |
| `brm_st_c.pcx` | `0x0062d560` | `0x00581256` | `0x00581921` |
| `brm_ex_a.pcx` | `0x0062d570` | `0x005812a3` | `0x0058196d` |
| `brm_ex_b.pcx` | `0x0062d580` | `0x005812ba` | `0x00581984` |

The modeled refs belong to IDA function `sub_581100` with size `0x4aa`, documented as `StartupWindow::UpdateCheckWindowProc`. IDA reports `0x005818d0` and the six raw helper refs as `Not a function`; the raw bytes nevertheless start with a normal frame setup (`55 8b ec 53 8b d9`) and end with `c2 04 00` followed by `0xcc` padding, so this is a real unmodeled helper boundary rather than stray data.

The same six PCX string addresses each have one modeled data xref in `sub_581100` and one raw data xref in the `0x005818d0` helper body. That ties both caller clusters to the same startup notice asset set without requiring a generated-source owner.

## Ownership

[UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) is the best parent. The helper owns image resource loading policy: path conversion, DAT/file-buffer access, and handoff to the PCX-to-DIB factory. [UID:0000IV][DIBitmap](by-file/DIBitmap.md) is only the bitmap wrapper constructed downstream, and [UID:0000IN][DATFile](by-file/DATFile.md) / [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) are consumed services rather than the source owner.

The startup window docs should keep caller evidence for the `brm_*.pcx` assets, but they should not claim ownership of this loader. The current parent attachment is therefore `ImageLoaders`, with no reconstructed C++ emitted because final source names for the string/file-buffer helpers remain decompiler-derived.

## Cross-References

- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-02: Raised from `50/75` to `78/84` and attached to [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
  - Added exact IDA boundary/padding evidence, decompile-derived call-flow table, caller/string xref table, and ownership rationale.
  - Left reconstructed C++ blank because the wrapper behavior is clear but the final-source helper names for path conversion and file-buffer object methods are not proven.
- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/75` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented PCX loading behavior, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant code while keeping parent UID and C++ blank because the second raw caller cluster is not yet function-modeled.
  - Evidence: IDA MCP confirms the exact function range, six modeled `StartupWindow` call sites, six additional unmodeled raw references, and callees through file/path/DAT helpers into `CreateDIBitmapFromPcxBuffer`.
