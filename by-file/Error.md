*** UID:0000J5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Error

## Status

- Confidence: strong for grouping the small error classes in one source module, medium for the password/fatal helper split.
- Proposed module: `NexusTK/util/Error.cpp`
- Current Wave3 files: `class_Error.cpp`, `class_ErrorMessage.cpp`, `class_MyError.cpp`, `class_PasswordError.cpp`, `class_Win32Error.cpp`, `class_DDError.cpp`, `class_DIError.cpp`, `class_DSError.cpp`, `class_FileError.cpp`, `class_WSAError.cpp`, `class_InternetError.cpp`, and `class_InternetConnectionError.cpp`
- Main address docs: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md), [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md), [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md), [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md), [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md), and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- Evidence basis: `simroot_v2` generated source, Wave3 class summaries, and IDA MCP lookup/xref/disassembly checks through 2026-05-25, with a compact IDA MCP boundary recheck on 2026-05-31.

## Hypothesis

The original client likely had one small error hierarchy source pair, probably `Error.h`/`Error.cpp`, rather than one source file per wrapper. The strongest evidence is the compact `0x004a60d0-0x004a6a76` run of Win32, DirectX, file, Winsock, WinINet, base-error, application-error, and destructor/vtable helpers.

The DirectDraw, DirectInput, DirectSound, Winsock, and WinINet wrappers should be referenced by their feature modules, but their implementation belongs with the shared error system. Do not migrate `DDError` into render, `DIError` into input, or `DSError` into audio just because callers originate there.

## Likely Contents

- `Error`, `ErrorMessage`, and scalar deleting destructors for base error objects.
- `MyError` and `PasswordError` for application-owned error text.
- `Win32Error`, `FileError`, and `WSAError` wrappers around last-error APIs.
- `DDError`, `DIError`, and `DSError` wrappers around HRESULT-style DirectX errors.
- `InternetError` and `InternetConnectionError` wrappers around WinINet error text.
- Shared message-formatting helpers and error vtables/type-info records.

## Split Candidates

`SetProtectedPasswordToken` and `ValidateChatInputOrThrowPasswordError` are better treated as [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) until caller review proves they originally lived in `Error.cpp`. `PasswordError` itself belongs in the error hierarchy because part of the class is physically inside the `0x004a67a0+` error wrapper cluster.

`FatalError` may belong in `app/Application.cpp`, `util/Error.cpp`, or a small startup fatal-dialog file. It depends on `g_pApplication`, shows an owner-window message box, posts quit, and deliberately breaks execution. Keep it documented with the password/fatal memory range for now rather than using it as strong evidence that all `0x00465xxx` helpers belong in `util/Error.cpp`.

## Evidence

- Wave3 reports all wrapper classes as separate one-class files, but those files are generated structure, not original source-layout proof.
- IDA MCP confirms real function starts for `Win32Error` (`0x004a60d0`), `DDError` (`0x004a6260`), `FileError` (`0x004a6430`), `WSAError` (`0x004a64a0`), `InternetError` (`0x004a6550`), `InternetConnectionError` (`0x004a6690`), `MyError` (`0x004a67a0`), and the common destructor/name helpers through `0x004a6a70`.
- IDA MCP reports no function at Wave3 projected starts `0x004a61b0`, `0x004a6330`, and `0x004a63e0`; treat those constructor records as data caveats.
- 2026-05-25 IDA recheck confirms those three projected starts still have no function records, direct callers, or data xrefs, though disassembly shows constructor-shaped code. Current generated output emits those bodies anyway, so use them as raw-code evidence only.
- The same recheck found real IDA helpers omitted from generated output at [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) and [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md): a base `Error` cleanup helper and a wide-message copy helper.
- IDA `.rdata` inspection shows exact vtable children [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md) for the contiguous 11-table error run, plus [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md) for the separate [UID:0000A8][PasswordError](by-class/PasswordError.md) vtable. The slot map and storage families are recorded in [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md).
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) is a real `FileError` inline-message copy helper used by the vtable at `0x006193d4`; current active generated output does not expose it as a class method.
- `PasswordError::GetErrorDescriptor` at `0x00467400` returns descriptor data at `0x006125bc`, not the `PasswordError` vtable pointer. Current generated output is misleading here and is tracked as a Wave3 data issue.
- Constructors have caller evidence from app startup, render, input/audio setup, cash-shop/network paths, and socket code, which fits shared utility ownership.
- 2026-05-31 IDA MCP lookup reconfirmed the modeled error-cluster starts used by this page, including `0x004a60d0`, `0x004a6260`, `0x004a6400`, `0x004a6410`, `0x004a6430`, `0x004a6480`, `0x004a64a0`, `0x004a6550`, `0x004a6690`, `0x004a67a0`, and `0x004a6a70`. The vtable addresses `0x00619340` and `0x006125a8` remain data, not functions, which matches the existing type/vtable split.

## Proposed Placement

```text
util/
  Error.h
  Error.cpp
```

Possible adjacent files:

```text
auth/
  PasswordGuard.cpp
app/
  FatalError.cpp       // only if later source-layout evidence separates it from Error/Application
```

## Open Questions

- Whether `ErrorMessage` is a real original class name or a recovered wrapper for the base display virtuals.
- Whether `PasswordError` declaration and virtuals were in `Error.h` while password filtering lived elsewhere.
- Whether `FatalError` was a standalone helper or part of application startup/error handling.
- Whether the DirectInput and DirectSound constructor starts should be recovered from inlined/setup code or removed from Wave3.

## Cross-References

- [UID:00004J][Error](by-class/Error.md)
- [UID:00004K][ErrorMessage](by-class/ErrorMessage.md)
- [UID:00008V][MyError](by-class/MyError.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)
- [UID:00003L][DDError](by-class/DDError.md)
- [UID:00003W][DIError](by-class/DIError.md)
- [UID:000045][DSError](by-class/DSError.md)
- [UID:00004X][FileError](by-class/FileError.md)
- [UID:0000GB][WSAError](by-class/WSAError.md)
- [UID:00006Q][InternetError](by-class/InternetError.md)
- [UID:00006P][InternetConnectionError](by-class/InternetConnectionError.md)
- [UID:0002HJ][0x004a60d0-0x004a60f5.Win32ErrorConstructor](by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md)
- [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md)
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- [UID:0002HM][0x004a64a0-0x004a64c5.WSAErrorConstructor](by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md)
- [UID:0002HN][0x004a6550-0x004a666a.InternetErrorConstructor](by-memory/0x004a6550-0x004a666a.InternetErrorConstructor.md)
- [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)
- [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: shared error hierarchy grouping, likely contents, password/fatal split candidates, IDA function/vtable/layout evidence, projected constructor caveats, proposed placement, open questions, and cross-references are documented; confidence is strong but capped by unresolved `PasswordGuard`/`FatalError` ownership and raw constructor records.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places the shared error hierarchy at `util/Error.cpp`, and the fresh IDA MCP lookup recheck reconfirms the compact error wrapper cluster and vtable/data split while leaving the documented PasswordGuard/FatalError caveats intact.
- 2026-05-31 exact constructor references:
  - What existed before: the page referenced the aggregate error-wrapper range and helper slots, but representative constructors were not split as exact pages.
  - Changed to: cross-references now include exact constructor pages for `Win32Error`, `DDError`, `FileError`, `WSAError`, `InternetError`, and `MyError`.
  - Summary/evidence: live IDA MCP confirmed each constructor's exact function size, vtable store, storage offset, and representative caller/vtable evidence.
