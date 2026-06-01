*** UID:0000T5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadIndexedDATSeries

## Status

- Address range: [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md)
- Symbol kind: startup helper function
- Signature hypothesis: `bool __cdecl LoadIndexedDATSeries(const wchar_t* basePath)`
- Likely owner file: [UID:0000HG][Application](by-file/Application.md)
- Current generated evidence: `source-3/simroot_v2/class_Application.meta_old` calls this as `FUN_00467410`; older Wave2 notes imported the symbol as `LoadIndexedDATSeries`.
- Confidence: strong for behavior, callers, source placement, and helper name; medium-high for exact original return type.

## Function Role

`LoadIndexedDATSeries` loads a numbered family of DAT archives during application initialization. Given a prefix such as `DATA/TILE`, it probes `DATA/TILE0.DAT`, `DATA/TILE1.DAT`, and so on, stopping when the next file is absent and requiring each existing file to be accepted by the DAT manager.

The helper is startup policy, not archive parsing. It chooses the numbered-series scan range and failure semantics, then delegates actual archive indexing to [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md).

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-05-25 confirms `0x00467410` as a real function of size `0xdd`, ending half-open at `0x004674ed`.
- IDA MCP `callers` reports 19 call sites, all inside `Application::Initialize`.
- IDA MCP `decompile` shows the `i < 99` loop, `L"%s%d.DAT"` formatting, `_wfopen_s` existence probe, and fatal `"File not found : %s"` path on manager-load failure.
- `simroot_v2` generated application evidence lists calls for many startup resource families such as `DATA/FACEDEC`, `DATA/EMOTION`, `DATA/BODY`, `DATA/TILE`, `DATA/EFX`, `DATA/HAIR`, `DATA/HELMET`, and `DATA/COAT`.
- 2026-05-30 IDA MCP recheck confirms the exact half-open range `0x00467410-0x004674ed`, 19 call sites all inside `Application::Initialize`, and callees for `_wfopen_s`, `_fclose`, fatal error helper `0x00465cb0`, and [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md).
- `simroot_v2/recovered/LoadIndexedDATSeries_00467410.cpp` currently matches the IDA-verified behavior and is useful as a source-shape lead, but the source-level `bool` return should remain a hypothesis because the binary return is the byte value `1`.

## Source Layout Decision

Declare this helper near `Application::Initialize` in `app/Application.cpp`, likely as a file-local helper. Do not fold it into `archive/DATFileMgr.cpp`; the archive manager only provides the load/index API.

## Reconstruction Notes

The source-level helper should scan numbered families with `index < 99`, probe existence with `_wfopen_s(..., L"rb")`, stop at the first absent file, close each successful probe immediately, delegate actual indexing to `g_pDATFileMgr->LoadDATFile(fileName)`, and call the application fatal-error helper with `L"File not found : %s"` if a present file cannot be indexed.

## Cross-References

- [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md)
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `88/92`. Previously this global index page described the helper but had no score; it now records the current IDA MCP boundary/caller/callee recheck and clarifies the source-level return-type caveat.
