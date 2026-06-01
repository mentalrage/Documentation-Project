*** UID:0001UE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Error Object Layouts

## Status

- Confidence: strong for observed storage families and field offsets; medium for final source-level member names.
- Current entity kind: recovered object-layout notes for the [UID:0000J5][Error](by-file/Error.md) hierarchy.
- Likely owner header/source: `util/Error.h` / `util/Error.cpp`.
- Evidence basis: IDA MCP decompile/disassembly/xref checks, `simroot_v2` generated class files, and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) on 2026-05-25. `wave3.py` was not executed for this pass.

## Shared Base

All observed error wrappers begin with an `LObject`/vtable pointer at `+0x00`. The base [UID:00004J][Error](by-class/Error.md) table has a pure virtual message-copy slot, so concrete classes supply storage-specific copy or format behavior.

The base cleanup helper at [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) resets the vtable to `Error` and calls the `LObject` destructor path. Current generated output omits this real helper, so use the memory docs rather than generated files as the migration anchor.

## Layout Families

| Family | Classes | Layout hypothesis | Evidence |
| --- | --- | --- | --- |
| Base-only | [UID:00004J][Error](by-class/Error.md) | `+0x00` vtable / `LObject` base only. | Base vtable at `0x00619344`; pure message-copy slot. |
| Stored status code | [UID:0000G7][Win32Error](by-class/Win32Error.md), [UID:00003W][DIError](by-class/DIError.md), [UID:00003L][DDError](by-class/DDError.md), [UID:000045][DSError](by-class/DSError.md), [UID:0000GB][WSAError](by-class/WSAError.md) | `+0x00` vtable, `+0x04` `DWORD`/`HRESULT`/last-error code. | [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md), [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md), and [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md) store `GetLastError`, caller HRESULT, or `WSAGetLastError` at `+0x04`; formatter slots consume that code. |
| Inline wide message | [UID:00004K][ErrorMessage](by-class/ErrorMessage.md), [UID:00004X][FileError](by-class/FileError.md) | `+0x00` vtable, `+0x04` inline wide-character message buffer. `FileError` has a trailing status/flag byte after the buffer in generated output. | [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) both copy from `this + 2` in `wchar_t*` terms, byte offset `+0x04`; [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) formats into that buffer. |
| `SimpleUString` message | [UID:00006Q][InternetError](by-class/InternetError.md), [UID:00006P][InternetConnectionError](by-class/InternetConnectionError.md) | `+0x00` vtable, `+0x04` owned `SimpleUString` message. | [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md) initializes a string subobject at `+0x04`; shared deleting destructor `0x004a69c0` frees owned string storage. |
| Owned heap wide message | [UID:00008V][MyError](by-class/MyError.md), [UID:0000A8][PasswordError](by-class/PasswordError.md) | `+0x00` vtable, `+0x04` owned `wchar_t*` message pointer. | [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) allocates/copies the supplied text into pointer field `+0x04`; `0x004a6860` and `0x004a6a10` free it. `PasswordError` calls `MyError` construction, then installs its own vtable. |

## Source-Layout Impact

These layouts support keeping the concrete wrappers together in `util/Error.cpp` even though their callers live in render, input, audio, network, file/archive, and password-guard code. The split is by storage/formatting strategy, not by feature subsystem.

`PasswordError` is a subclass of the `MyError` storage family. The password-token scanner belongs in [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md), but the concrete exception object belongs with the error hierarchy.

IDA MCP live recheck on 2026-05-26 reconfirmed exact helper boundaries for the base cleanup helper at `0x004a6400-0x004a640b`, [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md), and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md).

## Open Questions

- Whether the inline wide-message buffer is exactly 80 `wchar_t` elements for both `ErrorMessage` and `FileError`, or whether `FileError` is the only class with the generated 80-character buffer plus trailing flag.
- Whether `ErrorMessage` is an original product class or a recovered name for a concrete "inline message" wrapper.
- Final names for the `+0x04` code field across DirectDraw, DirectInput, DirectSound, Win32, and Winsock wrappers.

## Cross-References

- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md)
- [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md)
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md)
- [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md)
- [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)

## Changes

- 2026-05-31 completion/reconstruction metadata and exact constructor links:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank even though the page had substantial layout evidence.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`; layout-family evidence now links to exact constructor pages for `Win32Error`, `DDError`, `FileError`, `WSAError`, `InternetError`, and `MyError`.
  - Summary/evidence: live IDA MCP recheck confirmed the exact constructor sizes, vtable stores, `+0x04` storage roles, representative callers, and vtable data xrefs. Scores remain below `95` because final class/member names and projected constructor records for some sibling wrappers are still unresolved.
