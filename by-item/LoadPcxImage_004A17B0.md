*** UID:0000UZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadPcxImage 0x004A17B0

## Status

- Confidence: strong for behavior and caller family.
- Entity kind: free image-loader helper.
- Current Wave3 owner file: `source-3/simroot_v2/recovered/LoadPcxImage_004A17B0.cpp`
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Exact range: `0x004a17b0-0x004a18a8`

## Behavior

`LoadPcxImage` converts an ANSI PCX path to the wide-string path format used by the shared file helper, checks whether the resource exists, opens a 0x14-byte file-buffer object, retrieves its raw data pointer and size, and passes the bytes to `CreateDIBitmapFromPcxBuffer`.

IDA MCP confirms six direct call sites inside `StartupWindow::UpdateCheckWindowProc` at `0x00581100`, covering `brm_main.pcx`, `brm_st_a.pcx`, `brm_st_b.pcx`, `brm_st_c.pcx`, `brm_ex_a.pcx`, and `brm_ex_b.pcx`. Wave3/Ghidra also reports a projected caller at `0x005818d0`, but IDA reports no function at that address; see `wave3_data_issues.md`.

IDA MCP recheck on 2026-05-31 confirms `sub_4A17B0` starts at `0x004a17b0`, ends half-open at `0x004a18a8`, calls the path/file helpers, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), DATFile helpers, [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md), and a cleanup helper. It also sees six raw code references at `0x005818f1` through `0x00581984` that are not assigned to an IDA function, matching the existing caller-boundary caveat.

## Cross-References

- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/75` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented PCX loading behavior, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant code while keeping parent UID and C++ blank because the second raw caller cluster is not yet function-modeled.
  - Evidence: IDA MCP confirms the exact function range, six modeled `StartupWindow` call sites, six additional unmodeled raw references, and callees through file/path/DAT helpers into `CreateDIBitmapFromPcxBuffer`.
