*** UID:00004J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Error.h"
#include <wchar.h>

const wchar_t *Error::GetErrorName() const
{
    return L"Error";
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_ERROR_H
#define NEXUSTK_UTIL_ERROR_H

#include "LObject.h"
#include <stddef.h>
#include <windows.h>

class Error : public LObject
{
public:
    virtual ~Error()
    {
    }

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const = 0;
    virtual const wchar_t *GetErrorName() const;
};

class MyError : public Error
{
public:
    MyError(const wchar_t *message);
    virtual ~MyError();

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t *m_messageText;
};

class PasswordError : public MyError
{
public:
    PasswordError(const wchar_t *message);
    virtual const wchar_t *GetErrorName() const;
};

class Win32Error : public Error
{
public:
    Win32Error();
    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    DWORD m_errorCode;
};

typedef char ErrorSizeMustBe0x4[
    sizeof(Error) == 0x4 ? 1 : -1];
typedef char MyErrorSizeMustBe0x8[
    sizeof(MyError) == 0x8 ? 1 : -1];
typedef char PasswordErrorSizeMustBe0x8[
    sizeof(PasswordError) == 0x8 ? 1 : -1];
typedef char Win32ErrorSizeMustBe0x8[
    sizeof(Win32Error) == 0x8 ? 1 : -1];

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Error

## Status

- Confidence: very strong for the DirectX-required Error/MyError declarations, five-slot contract, checked Error scalar-wrapper source cause, GetErrorName body, and x86 layouts; broader sibling declarations remain separately scoped.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Destructor/name helper range: [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- Exact vtable data: [UID:0002ND][0x00619340-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md)
- Source-facing placement: base class declaration and destructor/name support in `NexusTK/util/Error.cpp` / `Error.h`; concrete storage-wrapper construction remains in the same shared hierarchy.
- Reconstructable: true; this page now owns the single coordinated `Error.h` declaration block and exact `Error::GetErrorName` CPP method required by DirectX-associated support.
- PasswordGuard compile closure: the same single guarded H now also declares `PasswordError : public MyError`, its constructor and `GetErrorName` override, and the exact `sizeof(PasswordError) == 0x8` assertion. [UID:0000A8][PasswordError](by-class/PasswordError.md) keeps H blank and expands exact children through CPP.

## Responsibility

`Error` is the base class for exception-like client error objects. It inherits from `LObject` and supplies common destructor/vtable behavior for concrete wrappers.

The source-level hierarchy is compact. [UID:0000J5][Error](by-file/Error.md) groups `Error`, status-code wrappers (`Win32Error`, `DDError`, `DIError`, `DSError`, `WSAError`), inline-message wrappers (`ErrorMessage`, `FileError`), WinINet wrappers (`InternetError`, `InternetConnectionError`), and owned-message `MyError` into one utility module rather than one source file per generated class.

[UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) now provides a concrete source-level `catch (Error *error)` consumer. B009's MCP session `80de0a67` proves WinMain's handler at `0x004f5e95` through EH record `0x0065efd4` and type descriptor `0x00674544` / `??_R0PAVError@@@8`. The handler calls the hierarchy's message-output virtual slot `+0x0c` into a `WCHAR[0x800]` buffer, calls `GetErrorName` / slot `+0x10` for the message-box caption, and deletes the caught pointer through the scalar deleting destructor slot. WinMain locally names slot `+0x0c` as `CopyErrorMessage`; keep the broader hierarchy-wide `FormatErrorMessage`/return-type standardization caveat until the declaration is reconciled.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup island | Current B005 MCP recheck confirms this modeled `0x0b` helper resets to the base `Error` vtable, tail-jumps to inherited cleanup, has no direct xrefs or pointer-route hits, and now carries only a Rule 28 marker comment because source emission is the Error hierarchy destructor/unwind implementation. |
| [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) | duplicate cleanup island | Exact child for the FileError-adjacent base `Error` vtable reset / inherited-cleanup tail-jump island. It is executable Error hierarchy support, not padding and not a source-visible FileError method. |
| [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md) | destructor/name helper cluster | Exact destructor-family map and common name virtual. |
| `0x004a68a0-0x004a68de` | status-code wrapper scalar deleting destructor | Used by `Win32Error`, `DIError`, `DDError`, `DSError`, and `WSAError`; not the base `Error` vtable slot. |
| `[0x004a68e0,0x004a691e)` | `Error` scalar deleting destructor | Exact 62-byte compiler-generated wrapper caused by the inline empty virtual `Error::~Error()` in this H block; no duplicate handwritten CPP. |
| `0x004a69c0-0x004a6a08` | `InternetError`/`InternetConnectionError` scalar deleting destructor | Destroys the `SimpleUString` member at `+0x04` before base teardown. |
| `0x004a6a70-0x004a6a76` | common error name helper | Returns the shared `Error` literal used by the main hierarchy's descriptor/name slot. |

## DirectX Compile Support Closure

This class page is the sole guarded-header owner for the DirectX-required Error/MyError subset. [UID:00008V][MyError](by-class/MyError.md) and [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) keep blank H channels to avoid duplicate declarations.

| Claim | Function/range | Exact disposition |
| --- | --- | --- |
| `C0000IW-162` | Error/MyError declarations | Emit the exact guarded H above, including inline empty virtual Error destructor, pure integer-returning wide formatter, MyError declaration/field, and `0x4`/`0x8` size assertions. |
| `C0000IW-163` | `[0x004a6a70,0x004a6a76)` | Emit only `Error::GetErrorName() const`, returning `L"Error"`, in this CPP channel. |
| `C0000IW-167` | `[0x004a68e0,0x004a691e)` | Compiler-generated Error scalar deleting destructor; 62 bytes, 26 instructions, SHA256 `E8144E5BF8ADF60BD3FE8347E1B3871E3029191871D04A6AFE3B2B4C8BF00B2F`; no separate CPP. |
| `C0000IW-168` | `0x00619344 -> 0x004a68e0` | Sole inbound base-vtable data route; direct code callers are zero. |
| `C0000IW-169` | `0x004a68e6 -> 0x00619344` | Wrapper restores `Error::vftable`. |
| `C0000IW-170` | `0x004a68ec -> 0x004f4a90` | Wrapper calls `LObject_destructor`. |
| `C0000IW-171` | `0x004a68fd -> 0x004f4ac0` | Conditional operator-delete wrapper when flag bit 1 is set and bit 4 is clear. |
| `C0000IW-172` | `0x004a690f -> 0x0041b6a0` | Flag-4 sized-delete path uses `_guard_check_icall_nop` with object size 4. |

The adjacent DirectX-required source-bearing functions are independently owned: UID0002HO preserves the exact MyError constructor; UID00008V emits `[0x004a6840,0x004a6858)` `MyError::FormatErrorMessage` and `[0x004a6860,0x004a6882)` `MyError::~MyError`. The `0x004a6a10` MyError scalar deleting wrapper is compiler-generated from that ordinary destructor and receives no duplicate CPP.

## Vtable And Storage Families

The exact vtable-data page records the shared five-slot interface and the class-specific destructor/descriptor slots:

| Class family | Vtable base | Destructor slot | Descriptor/name slot | Storage model |
| --- | --- | --- | --- | --- |
| `Error` | `0x00619344` | `0x004a68e0` | `0x004a6a70` | Base object with no extra stored message/status field. |
| Status-code wrappers | `0x0061935c`, `0x00619374`, `0x0061938c`, `0x006193a4`, `0x006193ec` | `0x004a68a0` | class-specific formatter or `0x004a6a70` | Stores last-error/HRESULT/WSA status at `+0x04`. |
| Inline-message wrappers | `0x006193bc`, `0x006193d4` | `0x004a6920` or `0x004a6970` | [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) / [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) | Inline or copied message buffer. |
| WinINet wrappers | `0x00619404`, `0x0061941c` | `0x004a69c0` | `0x004a6670` or `0x004a6780` | Owns a `SimpleUString` member at `+0x04`. |
| `MyError` | `0x00619434` | `0x004a6a10` | `0x004a6840` | Owns heap-backed message text. |

The base `Error` vtable at `0x00619344` is the only direct data xref to `0x004a68e0`, which is why the base destructor is now separated from the status-code wrapper destructor at `0x004a68a0`.

## Ownership Notes

The apparent duplicate destructor names are now separated by vtable ownership. The base [UID:00004J][Error](by-class/Error.md) table uses `0x004a68e0`; `0x004a68a0` is a shared status-code wrapper destructor; `0x004a6920` and `0x004a6970` are inline-message wrapper destructors; `0x004a69c0` is the `SimpleUString` storage-family destructor; and `0x004a6a10` is the owned heap-message destructor used by `MyError`.

See [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) for the shared five-slot interface and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) for storage-family notes.

## Source Boundary Notes

- `PasswordError` declaration and virtuals are part of the error hierarchy, but password-token filtering remains with [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) until stronger source-layout evidence moves it.
- B001-011 keeps the fatal dialog/break helper with [UID:0000HG][Application](by-file/Application.md); do not use that application-startup helper as proof that password/fatal helpers belong on the base `Error` page.
- DirectDraw, DirectInput, DirectSound, Winsock, and WinINet callers reference this hierarchy through feature-specific failure paths, but the wrapper implementation still belongs in the shared `Error` utility module.

## 2026-06-03 IDA MCP Recheck

- IDA reports `sub_4A68E0` as `0x004a68e0-0x004a691e`, and the only data xref to that function is the base `Error` vtable at `0x00619344`.
- IDA reports `sub_4A68A0` as `0x004a68a0-0x004a68de`, with data xrefs from the `Win32Error`, `DIError`, `DDError`, `DSError`, and `WSAError` destructor slots.
- The base vtable at `0x00619344` has slot order: `0x004a68e0`, `0x004f4b10`, `nullsub_18`, `__purecall`, and `0x004a6a70`.
- All destructor variants restore or retain the base `Error` vtable before inherited `LObject` cleanup; storage-family destructors add only the member cleanup required by their layout family.

## 2026-06-15 IDA MCP Recheck

- Live IDA MCP session `a003_objectlist_dispatch_20260615` reconfirms `sub_4A6400` size `0xb`, status-code wrapper destructor `sub_4A68A0` size `0x3e`, base `Error` destructor `sub_4A68E0` size `0x3e`, and common name helper `sub_4A6A70` size `0x6`.
- `xrefs_to(0x004a68a0)` returns exactly five status-wrapper destructor slots: `0x0061935c`, `0x00619374`, `0x0061938c`, `0x006193a4`, and `0x006193ec`. `xrefs_to(0x004a68e0)` returns only the base `Error` vtable cell `0x00619344`.
- `xrefs_to(0x004a6a70)` returns 11 descriptor/name vtable cells from `0x00619354` through `0x00619444`, matching the shared hierarchy descriptor slot across base, status-code, inline-message, WinINet, and owned-message wrappers.
- `xrefs_to(0x00619344)` reports base-vtable restore stores from the cleanup helper and destructor-family methods, including `0x004a6400`, `0x004a68a6`, `0x004a68e6`, `0x004a6926`, `0x004a6976`, `0x004a69d0`, and `0x004a6a27`.
- `analyze_component` over `0x004a6400`, `0x004a68a0`, `0x004a68e0`, `0x004a6920`, `0x004a6970`, `0x004a69c0`, `0x004a6a10`, and `0x004a6a70` reports shared global `??_7Error@@6B@` at `0x00619344` accessed by the cleanup helper and all destructor-family methods. `make_signature_for_range(0x004a68a0,0x004a6a76)` returns a unique wildcarded signature for the destructor/name-helper cluster.

## 2026-06-19 B013 Local PE Recheck

- Local Capstone/PE bytes for [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md) prove `0x004a6470-0x004a647b` is a second two-instruction base cleanup island: `mov dword ptr [ecx], 0x00619344` followed by `jmp 0x004f4a90`.
- Direct-call and PE pointer scans found no direct refs to `0x004a6470`, matching the no-route cleanup-helper pattern already documented for [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md).
- This helper should be tracked as Error hierarchy executable support, not padding or a source-visible product method. If a child page is created later, keep final source folded into destructor/unwind cleanup.
- B013 also keeps `Error::GetErrorName` as the best current main-hierarchy `+0x10` spelling and recommends standardizing the `+0x0c` message virtual as a wide-buffer formatter/copy method before any class-level final C++ is emitted.

## 2026-06-27 B005 Cleanup-Island Recheck

B005 MCP session `80de0a67` confirms [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) and [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) are the same source-family pattern: `sub_4A6400` and `sub_4A6470` are modeled `0x0b` functions, each writes `Error::vftable` at `0x00619344`, and each tail-jumps to `sub_4F4A90`. `xrefs_to 0x00619344` reports both cleanup islands plus the destructor-family base-vtable restores; `xrefs_to 0x004f4a90` reports tail jumps at `0x004a6406` and `0x004a6476`; start xrefs and VA/RVA pointer-route scans are negative. The exact byte bodies are `c7 01 44 93 61 00 e9 85 e6 04 00` and `c7 01 44 93 61 00 e9 15 e6 04 00`, with clean padding after both ranges.

Source impact: both exact pages keep [UID:0000J5][Error](by-file/Error.md) owner/emitter routing and use formal Rule 28 marker comments. They are represented by ordinary Error hierarchy destructor/unwind source. The historical blank-class blocker is superseded for the DirectX-required Error/MyError subset by the coordinated H and GetErrorName CPP above; unrelated sibling declaration work remains separately scoped.

## Score Rationale

- Completion is `90` because this page now owns the exact guarded Error/MyError H, exact GetErrorName CPP, five-slot contract, `0x4`/`0x8` assertions, checked `0x004a68e0` hash/source/caller/callee disposition, coordinated MyError methods/constructor route, and no-duplicate wrapper policy.
- Confidence is `92` because fresh accepted function/hash/xref/callee evidence, current layouts/vtables, WinMain contract, exact source blocks, and DirectX complete-type need agree. It remains below 95 because no PDB proves original hierarchy token spelling and broader sibling declarations remain outside this support allocation.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md)
- [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- [UID:0002ND][0x00619340-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00004K][ErrorMessage](by-class/ErrorMessage.md)
- [UID:0000G7][Win32Error](by-class/Win32Error.md)
- [UID:00004X][FileError](by-class/FileError.md)
- [UID:0000GB][WSAError](by-class/WSAError.md)
- [UID:00006Q][InternetError](by-class/InternetError.md)
- [UID:00008V][MyError](by-class/MyError.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)

## Changes

- 2026-08-17 B001 UID0000MG support implementation: score and existing Error/MyError/Win32Error source unchanged; inserted the complete PasswordError declaration before Win32Error and its 0x8 C++98 size assertion before the sole closing `#endif`. This is the single Error.h declaration route required by PasswordGuard; no duplicate PasswordError declaration is emitted by the class child.

- 2026-08-14 B004 UID0000IW associated-support implementation:
  - Raised `86/89` to `90/92`, replaced the historical marker with exact `Error::GetErrorName` CPP, and installed the single complete guarded Error/MyError H declaration.
  - Added inline empty `Error::~Error()` as the source cause for checked `[0x004a68e0,0x004a691e)`, exact 62-byte hash and one-to-one inbound/vtable/teardown/delete/guard routes, plus explicit no-duplicate CPP treatment.
  - Closed the DirectX compile dependency together with UID00008V formatter/destructor and UID0002HO constructor source while preserving unrelated Error sibling ownership and bounded original-token uncertainty.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/78`.
  - Summary/evidence: base error role, cleanup helper, destructor variants, module ownership, vtable/layout cross-references, and duplicate destructor caveat are documented; confidence remains limited until the destructor variants are fully assigned to exact vtable/subtype owners.
- 2026-06-03 destructor-family ownership recheck:
  - Before: destructor variants were documented as duplicate scalar deleting destructors with ownership still caveated, and the class was reconstructable but unparented.
  - Changed to: score is `76/82`, attached to [UID:0000J5][Error](by-file/Error.md), and the destructor/name-helper tail is split to [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md).
  - Summary/evidence: live IDA MCP confirmed the exact function bounds, vtable slot map, and destructor xrefs that prove `0x004a68e0` is the base `Error` destructor while sibling destructor helpers belong to storage-family subclasses.
  - C++ remains blank because final source-level virtual names and surrounding constructor-shaped raw records are not at the 95% reconstruction threshold.
- 2026-06-07 A001 hierarchy refresh:
  - Before: the page still carried stale generated-file wording and did not summarize the exact vtable/storage-family split now present in child docs.
  - After: raised to `82/86`, added source-facing `Error.cpp`/`Error.h` placement, vtable/storage-family table, source-boundary notes, score rationale, and sibling class cross-references.
  - Summary/evidence: [UID:0000J5][Error](by-file/Error.md), [UID:0002ND][0x00619340-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md), [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md), [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md), and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) now agree on shared utility ownership, the base `Error` destructor slot, and subclass storage-family destructor assignments.
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `86/89` with no owner/emitter changes. Live IDA reconfirmed the base cleanup helper, base/status/storage-family destructor sizes, base-only destructor vtable xref, five status-wrapper destructor slot xrefs, 11 common descriptor/name-helper vtable xrefs, shared base-vtable restore pattern, component evidence, and unique destructor/name-helper cluster signature. C++ remains blank because final virtual names, declaration spelling, and raw constructor records are not source-quality.
- 2026-06-19 B013 source-quality sync:
  - Score unchanged at `86/89`.
  - Summary/evidence: B013 adds the duplicate `0x004a6470-0x004a647b` base cleanup island to the class evidence, confirms it writes the `Error` base vtable and tail-jumps to inherited cleanup with no direct route, and keeps class-level C++ blank until final virtual names and declaration shape are standardized.
- 2026-06-27 B005 cleanup-island implementation:
  - Score unchanged at `86/89`.
  - Summary/evidence: B005 MCP session `80de0a67` raises [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) to `88/91`, creates exact sibling [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md), and records the current proof that both modeled `0x0b` cleanup islands write the base `Error` vtable, tail-jump to inherited cleanup, have no direct xrefs/callers or pointer-route hits, and should emit only Rule 28 marker comments while the executable source stays in Error hierarchy destructor/unwind code.
- 2026-06-26 B009 WinMain EH consumer sync:
  - Score unchanged at `86/89`.
  - Added WinMain's `catch (Error *error)` handler as a consumer of the base interface, including EH record `0x0065efd4`, type descriptor `0x00674544`, slot `+0x0c` message-output use, slot `+0x10` caption/name use, and caught-object deletion through slot zero.
