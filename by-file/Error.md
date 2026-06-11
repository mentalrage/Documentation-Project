*** UID:0000J5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Error

## Status

- Confidence: strong for grouping the small error classes in one source module; PasswordGuard helpers and B001-011-selected Application fatal-helper ownership are treated as external consumers/adjacent split evidence rather than Error-owned code.
- Proposed module: `NexusTK/util/Error.cpp`
- Current Wave3 files: `class_Error.cpp`, `class_ErrorMessage.cpp`, `class_MyError.cpp`, `class_PasswordError.cpp`, `class_Win32Error.cpp`, `class_DDError.cpp`, `class_DIError.cpp`, `class_DSError.cpp`, `class_FileError.cpp`, `class_WSAError.cpp`, `class_InternetError.cpp`, and `class_InternetConnectionError.cpp`
- Main address docs: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md), [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md), [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md), [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md), [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md), [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md), [UID:0000YS][0x004657d0-0x00467406.PasswordGuardAndFatalError](by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md), [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md), and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
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

B001-011 selects [UID:0000HG][Application](by-file/Application.md) as the direct owner for [UID:0002VI][0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak](by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md). The helper displays a fatal message, but IDA MCP shows it depends on [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md), [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md), `MessageBoxW`, and `PostQuitMessage`, with Application startup/load-failure callers outweighing the four RegistryConfig consumers. Do not use it as evidence that the `0x00465xxx` helpers belong in `util/Error.cpp`.

## Evidence

- Wave3 reports all wrapper classes as separate one-class files, but those files are generated structure, not original source-layout proof.
- IDA MCP confirms real function starts for `Win32Error` (`0x004a60d0`), `DDError` (`0x004a6260`), `FileError` (`0x004a6430`), `WSAError` (`0x004a64a0`), `InternetError` (`0x004a6550`), `InternetConnectionError` (`0x004a6690`), `MyError` (`0x004a67a0`), and the common destructor/name helpers through `0x004a6a70`.
- IDA MCP reports no function at Wave3 projected starts `0x004a61b0`, `0x004a6330`, and `0x004a63e0`; treat those constructor records as data caveats.
- 2026-05-25 IDA recheck confirms those three projected starts still have no function records, direct callers, or data xrefs, though disassembly shows constructor-shaped code. Current generated output emits those bodies anyway, so use them as raw-code evidence only.
- The same recheck found real IDA helpers omitted from generated output at [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) and [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md): a base `Error` cleanup helper and a wide-message copy helper.
- IDA `.rdata` inspection shows exact vtable children [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md) for the contiguous 11-table error run, plus [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md) for the separate [UID:0000A8][PasswordError](by-class/PasswordError.md) vtable. The slot map and storage families are recorded in [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md).
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) is a real `FileError` inline-message copy helper used by the vtable at `0x006193d4`; current active generated output does not expose it as a class method.
- [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md) at `0x00467400` returns descriptor data at `0x006125bc`, not the `PasswordError` vtable pointer. Current generated output is misleading here and is tracked as a Wave3 data issue.
- Constructors have caller evidence from app startup, render, input/audio setup, cash-shop/network paths, and socket code, which fits shared utility ownership.
- 2026-05-31 IDA MCP lookup reconfirmed the modeled error-cluster starts used by this page, including `0x004a60d0`, `0x004a6260`, `0x004a6400`, `0x004a6410`, `0x004a6430`, `0x004a6480`, `0x004a64a0`, `0x004a6550`, `0x004a6690`, `0x004a67a0`, and `0x004a6a70`. The vtable addresses `0x00619340` and `0x006125a8` remain data, not functions, which matches the existing type/vtable split.
- 2026-06-07 Agent-A002 IDA MCP rechecked the `InternetConnectionError` part of the hierarchy for Batch 091. `0x004a6690-0x004a6772` and `0x004a6780-0x004a679e` remain exact modeled functions; the constructor writes vtable `0x0061941c` at `0x004a66da`, calls `InternetGetLastResponseInfoA` at `0x004a6708`, and uses the same string-helper family as the `SimpleUString` message layout. The copy slot calls `0x00584540` and `_wcscpy_s`. The raw constructor caveats at `0x004a61b0`, `0x004a6330`, and `0x004a63e0` were also rechecked and still have no IDA function objects, so confidence only rises to the strict parent gate rather than beyond it.

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
  Application.cpp      // B001-011 keeps FatalErrorDialogAndBreak here unless recovered symbols prove a tiny FatalError.cpp
```

## Open Questions

- Whether `ErrorMessage` is a real original class name or a recovered wrapper for the base display virtuals.
- Whether `PasswordError` declaration and virtuals were in `Error.h` while password filtering lived elsewhere.
- Whether recovered source symbols later prove a separate tiny `FatalError.cpp`; current B001-011 evidence favors Application over Error.
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
- [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md)
- [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md)
- [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: shared error hierarchy grouping, likely contents, password/fatal split candidates, IDA function/vtable/layout evidence, projected constructor caveats, proposed placement, open questions, and cross-references are documented; confidence was strong but capped by then-unresolved `PasswordGuard`/`FatalError` ownership and raw constructor records.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/util/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places the shared error hierarchy at `util/Error.cpp`, and the fresh IDA MCP lookup recheck reconfirms the compact error wrapper cluster and vtable/data split while leaving the documented PasswordGuard/FatalError caveats intact.
- 2026-05-31 exact constructor references:
  - What existed before: the page referenced the aggregate error-wrapper range and helper slots, but representative constructors were not split as exact pages.
  - Changed to: cross-references now include exact constructor pages for `Win32Error`, `DDError`, `FileError`, `WSAError`, `InternetError`, and `MyError`.
  - Summary/evidence: live IDA MCP confirmed each constructor's exact function size, vtable store, storage offset, and representative caller/vtable evidence.

- 2026-06-05 PasswordError exact method split:
  - What existed before: `PasswordError` methods were represented through the mixed password/fatal aggregate and vtable-data page.
  - Changed to: added exact method references [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md), [UID:0002VK][0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor](by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md), and [UID:0002VL][0x00467400-0x00467406.PasswordErrorGetErrorDescriptor](by-memory/0x00467400-0x00467406.PasswordErrorGetErrorDescriptor.md), and raised the file score to `87/84`.
  - Summary/evidence: IDA MCP reverified constructor, scalar deleting destructor, descriptor helper, vtable xrefs, descriptor data, and the split that keeps PasswordGuard helpers outside `util/Error.cpp`.
- 2026-06-07 Agent-A002 Batch 091 parent-gate refresh:
  - Before: `87/84`, direct source-module parent for `InternetConnectionError` but one confidence point below the strict gate.
  - Changed to: `87/85`.
  - Summary/evidence: live IDA MCP rechecked the `InternetConnectionError` constructor/copy functions, vtable store, WinINet response-info call, string-helper/copy-out calls, and the three broader raw-constructor caveats. The parent now clears the class assignment gate; PasswordGuard split questions and raw constructor records keep confidence narrowly capped, while B001-011 later resolved the fatal helper away from Error and into Application.
- 2026-06-10 B001-011 fatal-helper split update:
  - Score unchanged at `87/85`.
  - Updated the split-candidate text so [UID:0002VI][0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak](by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md) is no longer presented as an unresolved Error/Application/tiny-source candidate.
  - Evidence: B001-011 IDA MCP confirmed the fatal helper uses [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md), [UID:0002GN][0x004651d0-0x004651d7.ApplicationGetMainWindowHandle](by-memory/0x004651d0-0x004651d7.ApplicationGetMainWindowHandle.md), `MessageBoxW`, and `PostQuitMessage`, while Error hierarchy constructors/vtable helpers are absent from its body.
