*** UID:0000T5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LoadIndexedDATSeries

## Status

- Address range: [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md)
- Symbol kind: startup helper function
- Signature hypothesis: `bool __cdecl LoadIndexedDATSeries(const wchar_t* basePath)`
- Likely owner file: [UID:0000HG][Application](by-file/Application.md)
- Confidence: strong for behavior, callers, source placement, and helper name; medium-high for exact original return type.

## Function Role

`LoadIndexedDATSeries` loads a numbered family of DAT archives during application initialization. Given a prefix such as `DATA/TILE`, it probes `DATA/TILE0.DAT`, `DATA/TILE1.DAT`, and so on, stopping when the next file is absent and requiring each existing file to be accepted by the DAT manager.

The helper is startup policy, not archive parsing. It chooses the numbered-series scan range and failure semantics, then delegates actual archive indexing to [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md).

## Evidence Notes

- IDA MCP `lookup_funcs` on 2026-05-25 confirms `0x00467410` as a real function of size `0xdd`, ending half-open at `0x004674ed`.
- IDA MCP `callers` reports 19 call sites, all inside `Application::Initialize`.
- IDA MCP `decompile` shows the `i < 99` loop, `L"%s%d.DAT"` formatting, `_wfopen_s` existence probe, and fatal `"File not found : %s"` path on manager-load failure.
- Application startup evidence lists calls for many startup resource families such as `DATA/FACEDEC`, `DATA/EMOTION`, `DATA/BODY`, `DATA/TILE`, `DATA/EFX`, `DATA/HAIR`, `DATA/HELMET`, and `DATA/COAT`.
- 2026-05-30 IDA MCP recheck confirms the exact half-open range `0x00467410-0x004674ed`, 19 call sites all inside `Application::Initialize`, and callees for `_wfopen_s`, `_fclose`, fatal error helper `0x00465cb0`, and [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md).
- IDA MCP recheck on 2026-06-05 confirmed `sub_467410`, size `0xdd`, 19 startup call sites inside `sub_4639D0`, and the same archive-probe/indexing helper role.
- The source-level `bool` return should remain a hypothesis because the binary return is the byte value `1`.

## Source Layout Decision

Declare this helper near `Application::Initialize` in `app/Application.cpp`, likely as a file-local helper. Do not fold it into `archive/DATFileMgr.cpp`; the archive manager only provides the load/index API.

## Reconstruction Notes

The source-level helper should scan numbered families with `index < 99`, probe existence with `_wfopen_s(..., L"rb")`, stop at the first absent file, close each successful probe immediately, delegate actual indexing to `g_pDATFileMgr->LoadDATFile(fileName)`, and call the application fatal-error helper with `L"File not found : %s"` if a present file cannot be indexed.

## Cross-References

- [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:0000YR][0x00463310-0x004674ed.ApplicationLifecycle](by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md)
- [UID:0001R6][application-startup-dat-archives](by-resource/application-startup-dat-archives.md)
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## 2026-06-29 B013 Duplicate Index Repair

- B013 implements the accepted duplicate/index route repair: this by-global page is now non-emitting while UID0000YX remains the exact by-memory source/no-code decision page.
- Metadata is `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:0000HG`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- This page remains the canonical symbol/index for `LoadIndexedDATSeries`; it must not duplicate UID0000YX's DAT-series behavior marker or any future exact body.

Implementation validator: run `python .\tools\validator.py --mode file --file by-global/LoadIndexedDATSeries.md --apply --queue-timeout 240` from `source-3/project-documentation`.

## Changes

- 2026-05-30: Raised completion/confidence from `0/0` to `88/92`. Previously this global index page described the helper but had no score; it now records the current IDA MCP boundary/caller/callee recheck and clarifies the source-level return-type caveat.
- 2026-06-05: Marked reconstructable and attached to [UID:0000HG][Application](by-file/Application.md) at that time.
  - Reason: live IDA MCP recheck confirmed a source-authored startup helper with all 19 direct callers inside application initialization; archive parsing remains delegated to the DAT manager.
  - B013 supersession: the 2026-06-29 duplicate/index repair above makes this by-global page non-emitting. The exact source/no-code decision now lives on UID0000YX, and this page remains only the canonical symbol/index.
