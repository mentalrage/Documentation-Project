*** UID:0000TQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WideApiDispatchTable

## Status

- Confidence: strong for the concrete `_wfopen` / `_wstat64i32` entries and NT wide-API initializer; medium for final symbol names.
- Address ranges: `0x0069be14-0x0069bed0` for currently confirmed dispatch-pointer storage, with [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) documenting the `SendMessageW` slot that older generated output mislabeled as a browser/transport callback.
- Initializer: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md)
- Likely owner file: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Current generated caveat: `simroot_v2` emits some entries as local-looking `dword_69BE*` globals inside consumer files, but the table is process-wide platform support.

## Role

This is the client-wide Windows API dispatch table. At startup, the initializer calls `GetVersionExA`, keeps an ANSI/string-conversion fallback path, and on NT-family Windows installs wide-character Win32 and CRT entry points into the `0x0069be14+` pointer cluster. Current IDA evidence shows [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) is the `SendMessageW` dispatch slot; the generated browser/transport names are consumer-biased aliases.

The file I/O layer consumes two entries:

| Address | Provisional name | Installed target | Known consumers |
| --- | --- | --- | --- |
| `0x0069be14` | `g_pfnWideOpenFile` / `dword_69BE14` | `_wfopen` | [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) and many direct file-open helpers |
| `0x0069be18` | `g_pfnWideStat` / `dword_69BE18` | `_wstat64i32` | [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) and [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) |

Other confirmed entries include wide `FindWindow`, `CreateFile`, `CreateWindowEx`, `DispatchMessage`, registry APIs, `SetCurrentDirectory`, version APIs, IME APIs, `SendMessageW`, `GetLocaleInfo`, and `SetFileAttributes` pointers.

Timer/threading consumers also use the dispatch table:

| Address | Provisional name | Installed target | Known consumers |
| --- | --- | --- | --- |
| `0x0069be3c` | `g_pfnCreateEventW` / `dword_69BE3C` | `CreateEventW` | [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md), [UID:0000OR][Thread](by-file/Thread.md), socket/browser worker helpers, and MIDI buffer event setup. |

## IDA MCP Evidence

Checked on 2026-05-25 and 2026-05-26:

- `lookup_funcs 0x0041a280` reports `sub_41A280`, size `0x228`.
- `decompile 0x0041a280` calls `GetVersionExA`, assigns `dword_69BE1C = sub_599570`, and when `dwPlatformId == 2` writes the wide API pointer table.
- The same decompilation assigns `dword_69BE14 = _wfopen` at `0x0041a42e` and `dword_69BE18 = _wstat64i32` at `0x0041a438`.
- `disasm 0x0041a280` assigns `CreateEventW` to `dword_69BE3C` at `0x0041a30c`; this is the event-creation dispatch used by [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md).
- `decompile 0x0041a280` assigns `SendMessageW` to `dword_69BEC4` at `0x0041a474`; the slot is documented by [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) because older generated output attached browser/transport aliases to its consumers.
- `xrefs_to 0x0069be18` reports the initializer write at `0x0041a438`, reads from [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) at `0x00582104`, reads from [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) at `0x00582478`, and two raw data refs near the generated `UniAPIInit` region.
- `xrefs_to 0x0069be14` reports the initializer write at `0x0041a42e`, the [UID:0001IT][0x005820d0-0x005821c9.StdioFileOpen](by-memory/0x005820d0-0x005821c9.StdioFileOpen.md) read at `0x00582118`, and many additional direct file-open consumers.
- 2026-05-26 IDA MCP recheck reconfirmed the same initializer writes and consumer pattern. The broad `0x0069be14` xrefs include screenshot file-open paths, profile/config I/O, startup/resource loads, and `StdioFile::Open`, reinforcing platform-table ownership rather than any one consumer module.
- 2026-05-26 current `simroot_v2/class_UniAPIInit.cpp` still emits many table entries as `g_pfn*` global-data declarations with low completeness, while consumer files can still expose raw `dword_69BE*` names.
- 2026-05-26 IDA MCP confirms [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) is the static cleanup wrapper registered by the initializer. It writes the `UniAPIInit` vtable pointer at `0x006702c4` and is not part of the adjacent pool cleanup wrappers.

## Ownership Decision

Keep the dispatch table with [UID:0000ML][PlatformApi](by-file/PlatformApi.md), not with `StdioFile`, `PathUtil`, screenshot/image writers, map loading, startup-logo loading, or audio. Those modules consume specific entries through the platform abstraction; they do not own the process-wide compatibility table.

This table is closely related to [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md), but current IDA evidence says the generated `0x005995b0` initializer boundary is not a real function. Use [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) as the exact code evidence for the table until Wave3 ownership/boundaries are corrected.

## Cross-References

- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md)
- [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md)
- [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md)
- [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:0000MI][PathUtil](by-file/PathUtil.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/82`. Summary/evidence: the page documents table ranges, concrete slots, initializer/decompilation evidence, consumer families, ownership decision, and prior range-split correction; final dispatch symbol names remain provisional.

- 2026-05-28 dispatch range split:
  - What existed before: the table range was described as one continuous `0x0069be14-0x0069bed0` dispatch-pointer cluster.
  - Changed to: the table is documented as `0x0069be14-0x0069bec4` plus `0x0069bec8-0x0069bed0`, with [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) called out as the intervening non-dispatch slot.
  - Summary/evidence: IDA MCP xref audit of the former `0x0069ba3c-0x0069bec4` UNKNOWN row and prior `g_browserControlKeyCallback` review show `0x0069bec4` is browser/transport callback storage, while [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) and [UID:0002A6][0x0069bec8-0x0069bed0.WideApiDispatchTailPointers](by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md) hold the dispatch pointers.
- 2026-06-02 SendMessageW slot correction:
  - What existed before: the page described [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) as an intervening non-dispatch browser/transport callback slot.
  - Changed to: the page now includes it as the `SendMessageW` dispatch slot in the wide API table, while preserving the separate memory page because generated aliases make it a high-risk reference target.
  - Summary/evidence: IDA MCP decompilation of [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) writes `SendMessageW` to `dword_69BEC4` at `0x0041a474`, between `ImmGetCandidateListW` and `GetLocaleInfoW`.
