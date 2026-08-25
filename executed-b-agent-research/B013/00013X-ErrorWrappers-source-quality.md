** TARGET-REPORT-UID:00013X **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013X ErrorWrappers Source-Quality Report

Status: FINISHED

## Recommendation Summary

- Target: [UID:00013X] `source-3/project-documentation/by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/00013X-ErrorWrappers-source-quality.md`.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, blank formal C++.
- Recommended metadata after supervisor implementation: `COMPLETION:87`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000J5`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000J5`, keep `EMITTER_POSITION_OPTIONAL` blank.
- Owner/source route: keep [UID:0000J5] `by-file/Error.md`, projected to `auto-generated/NexusTK/util/Error.cpp` / source-style `util/Error.cpp` plus `Error.h`.
- Formal target C++ recommendation: keep blank on the aggregate. The page clears the active 85/85 route gate after implementation, but the broad range mixes constructors, raw constructor-shaped starts, formatter/copy virtuals, duplicate cleanup helpers, ordinary destructors, scalar deleting destructor ABI wrappers, and a common name helper. Source C++ should be emitted from exact children or a consolidated class/file reconstruction, not from this aggregate.
- Most important implementation change: add `0x004a6470-0x004a647b` to the target range table and create an exact child if the supervisor wants full child coverage. Local PE bytes show a real two-instruction Error base-vtable reset/tail-jump cleanup helper between `FileErrorConstructor` and `FileErrorCopyMessage`; it is currently only implicitly covered by the aggregate.

No by-* docs, generated files, source files, IDA database, or `by-memory/-coverage-report.md` were edited.

## Evidence Checked

- Assignment/rules: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, and `tools/leaser/Agents/Agent-B013/goal.md`.
- Target and support docs: [UID:00013X] `ErrorWrappers`, [UID:0000J5] `Error`, class docs for `Error`, `ErrorMessage`, `Win32Error`, `DDError`, `DIError`, `DSError`, `FileError`, `WSAError`, `InternetError`, `InternetConnectionError`, `MyError`, and `PasswordError`.
- Type/data docs: [UID:0001UE] `ErrorObjectLayouts`, [UID:0001XI] `ErrorHierarchyVtables`, [UID:0002ND] `ErrorHierarchyVtableData`, [UID:0003I4] `ErrorHierarchyMessageStrings`, and [UID:0002NE] `PasswordErrorVtableData`.
- Exact executable child docs: [UID:0002HJ], [UID:0002HK], [UID:00013Y], [UID:00013Z], [UID:0002HL], [UID:000140], [UID:0002HM], [UID:0002HN], [UID:0002HO], and [UID:0002TV].
- Prior accepted B report checked for consistency: `Agent-B002/research/executed/0002TV-error-destructor-name-helpers-source-quality.md`.
- Generated-name comparison: `source-3/simroot_v2/class_Win32Error.cpp`, `class_DDError.cpp`, `class_DIError.cpp`, `class_DSError.cpp`, `class_WSAError.cpp`, `class_InternetError.cpp`, `class_InternetConnectionError.cpp`, `class_MyError.cpp`, `class_Error.cpp`, `class_ErrorMessage.cpp`, `class_FileError.cpp`, and `class_PasswordError.cpp`. These were used only as weak name hints because they preserve known generated-file and signature mistakes.
- Runtime/helper docs: [UID:0000WO] `CrtStdioCommonSprintfGlue` and [UID:000219] `CrtWideVsnprintfWrapper`.
- Reports: `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, and `project-level/-unresolved.md`.
- Validator baseline: `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md --uid-only`; result `ok: 1`.
- IDA MCP probe: `http://127.0.0.1:13337/mcp` timed out in this environment, so no IDA database edits or live MCP claims were made by this pass.
- Local read-only PE evidence: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`; sections `.text 0x00401000-0x0060c4ac`, `.rdata 0x0060d000-0x0066c0be`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2c38`.
- Local Capstone disassembly was used to check exact bytes/instructions for the target range, the `0x004a6470` gap, and direct-call/pointer occurrence scans.

## Current Gate Analysis

The target currently has `RECONSTRUCTABLE:TRUE`, a nonblank `EMITTER_UIDS:0000J5`, and average score `(85 + 86) / 2 = 85.5`, so it already clears the current 85/85 style route gate. The remaining issue is not ownership or reachability. It is source shape:

- The aggregate is a source-module evidence page, not a single source function.
- Several concrete method bodies still lack exact child pages.
- Three constructor-shaped starts are raw bytes with no direct function/start reference evidence.
- The destructor tail includes compiler scalar deleting destructor wrappers that should inform ordinary C++ destructors but should not be pasted as final source wrappers.
- The common Error hierarchy declaration and `+0x0c` virtual spelling still need standardization before final class/file C++ is safe.

Recommended target score after implementation is `87/89`: higher than the minimum gate because this pass resolves the child policy, stale generated-name issues, source-route policy, missing `0x004a6470` helper, and no-code proof; still below final because exact formatter/copy/raw-constructor children remain to be created and original source symbols are not recovered.

## Range Inventory And Split Policy

Use this table to replace or augment the target's current `Covered Range` section.

| Range | Best source-facing role | Child status / recommendation |
| --- | --- | --- |
| `0x004a60d0-0x004a60f5` | `Win32Error::Win32Error()` | Exact child [UID:0002HJ]. |
| `0x004a6100-0x004a61a3` | `Win32Error::FormatErrorMessage(wchar_t *out, size_t outChars)` | Create exact child. Vtable-only message/format slot at `0x00619368`. |
| `0x004a61b0-0x004a61d4` | raw `DIError::DIError(HRESULT result)` constructor-shaped body | Create raw/exact child or document as raw child; do not force IDA rename to a normal function without validation. |
| `0x004a61e0-0x004a625b` | `DIError::FormatErrorMessage(wchar_t *out, size_t outChars)` | Create exact child. |
| `0x004a6260-0x004a6284` | `DDError::DDError(HRESULT result)` | Exact child [UID:0002HK]. |
| `0x004a6290-0x004a6330` | `DDError::FormatErrorMessage(wchar_t *out, size_t outChars)` | Create exact child. |
| `0x004a6330-0x004a6354` | raw `DSError::DSError(HRESULT result)` constructor-shaped body | Create raw/exact child or document as raw child; no direct start refs. |
| `0x004a6360-0x004a63db` | `DSError::FormatErrorMessage(wchar_t *out, size_t outChars)` | Create exact child. |
| `0x004a63e0-0x004a63fc` | raw `ErrorMessage::ErrorMessage()` constructor-shaped body | Create raw/exact child or keep documented on `ErrorMessage`; no direct start refs. |
| `0x004a6400-0x004a640b` | Error base cleanup helper | Exact child [UID:00013Y]. Fold into destructor/unwind source, do not emit a user helper unless needed. |
| `0x004a6410-0x004a6429` | `ErrorMessage` stored-message output helper | Exact child [UID:00013Z]. Source interface should share the common message-output virtual. |
| `0x004a6430-0x004a646f` | `FileError::FileError(const wchar_t *path)` | Exact child [UID:0002HL]. Correct stale trailing-field wording; see FileError note below. |
| `0x004a6470-0x004a647b` | duplicate Error base cleanup helper between `FileError` constructor and copy helper | Missing exact child. Create `FileErrorBaseCleanupHelper` or equivalent file-level helper child. |
| `0x004a6480-0x004a6499` | `FileError` stored-message output helper | Exact child [UID:000140]. |
| `0x004a64a0-0x004a64c5` | `WSAError::WSAError()` | Exact child [UID:0002HM]. |
| `0x004a64d0-0x004a6549` | `WSAError::FormatErrorMessage(wchar_t *out, size_t outChars)` | Create exact child. |
| `0x004a6550-0x004a666a` | `InternetError::InternetError()` | Exact child [UID:0002HN]. |
| `0x004a6670-0x004a668e` | `InternetError` stored-message output helper | Create exact child. Existing docs call it `GetErrorText`; common virtual naming should be standardized. |
| `0x004a6690-0x004a6772` | `InternetConnectionError::InternetConnectionError()` | Create exact child. IDA-modeled real constructor per support docs. |
| `0x004a6780-0x004a679e` | `InternetConnectionError` stored-message output helper | Create exact child. |
| `0x004a67a0-0x004a683d` | `MyError::MyError(const wchar_t *message)` | Exact child [UID:0002HO]. |
| `0x004a6840-0x004a6858` | heap-message output helper used by `MyError` and `PasswordError` | Create exact child. Best source owner route is `MyError`, with `PasswordError` inheriting the message slot. |
| `0x004a6860-0x004a6882` | ordinary non-deleting `MyError::~MyError()` body | Create exact child before final MyError destructor C++; coordinate with [UID:0002TV] `0x004a6a10`. |
| `0x004a68a0-0x004a6a76` | scalar deleting destructor/name-helper cluster | Exact child [UID:0002TV]. Keep formal C++ blank there; use ordinary destructors and `Error::GetErrorName` in class/file C++. |

Local disassembly confirms `0x004a6470` is:

```asm
004a6470  mov     dword ptr [ecx], 0x00619344
004a6476  jmp     0x004f4a90
004a647b  int3
```

It is byte-identical in role to [UID:00013Y] `0x004a6400-0x004a640b`, but it is a separate code island. Direct-call and little-endian pointer scans found no direct refs to `0x004a6470`, matching the no-direct-xref cleanup-helper pattern.

## Raw Constructor Reanalysis

Local direct-reference scans agree with the current docs:

| Raw start | Direct rel32 calls | Full-PE little-endian pointer hits | Supporting evidence |
| --- | ---: | ---: | --- |
| `0x004a61b0` | `0` | `0` | Constructor-shaped bytes store argument to `this+0x04` and vtable `0x00619374` at `0x004a61c7`. |
| `0x004a6330` | `0` | `0` | Constructor-shaped bytes store argument to `this+0x04` and vtable `0x006193a4` at `0x004a6347`. |
| `0x004a63e0` | `0` | `0` | Constructor-shaped bytes call base setup and store vtable `0x006193bc` at `0x004a63ef`. |

These are high-probability real source constructors, but they should remain "raw constructor-shaped starts" unless a validator/IDA pass intentionally creates function records or exact raw child docs. Recommended names if raw child pages are created:

- `DIErrorRawConstructor` or `DIErrorConstructorRaw`, signature `DIError::DIError(HRESULT result)`.
- `DSErrorRawConstructor`, signature `DSError::DSError(HRESULT result)`.
- `ErrorMessageRawConstructor`, signature `ErrorMessage::ErrorMessage()`.

Do not leave them as `sub_` or `0x004a61b0` in support docs without this raw/no-xref explanation.

## Function Names, Signatures, And Fields

Recommended source-facing class constructors:

| Class | Constructor signature | Field/layout at `+0x04` |
| --- | --- | --- |
| `Win32Error` | `Win32Error::Win32Error()` | `DWORD m_errorCode` or `m_lastError`; `m_errorCode` is the lowest-churn choice. |
| `DIError` | `DIError::DIError(HRESULT result)` | `HRESULT m_errorCode` / `m_result`; prefer `m_errorCode` unless DirectX pages standardize on `m_result`. |
| `DDError` | `DDError::DDError(HRESULT result)` | `HRESULT m_errorCode`. |
| `DSError` | `DSError::DSError(HRESULT result)` | `HRESULT m_errorCode`. |
| `ErrorMessage` | `ErrorMessage::ErrorMessage()` | `wchar_t m_message[256]`. |
| `FileError` | `FileError::FileError(const wchar_t *path)` | `wchar_t m_message[80]`; no separate trailing status/flag field is proven. |
| `WSAError` | `WSAError::WSAError()` | `int m_errorCode` from `WSAGetLastError()`. |
| `InternetError` | `InternetError::InternetError()` | `SimpleUString m_message`. |
| `InternetConnectionError` | `InternetConnectionError::InternetConnectionError()` | `SimpleUString m_message`; likely not an in-memory subclass layout of `InternetError`, despite source-family relationship. |
| `MyError` | `MyError::MyError(const wchar_t *message)` | `wchar_t *m_messageText`. |
| `PasswordError` | `PasswordError::PasswordError(const wchar_t *message)` | Inherits `MyError` heap-message storage. |

Recommended virtual names:

- The vtable `+0x10` helper at `0x004a6a70` should stay `Error::GetErrorName`. It returns the shared `L"Error"` label and is not `what()` because message text is produced by the separate `+0x0c` slot.
- `PasswordError::GetErrorDescriptor` is a valid distinct override for the separate PasswordError table because its helper returns descriptor data at `0x006125bc`.
- The vtable `+0x0c` message-output slot needs one C++ source name across the hierarchy. This report recommends standardizing on `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` for final source because the five status-code wrappers truly format, and stored-message classes can implement the same virtual by copying their stored text. If the supervisor keeps the B002 draft's `CopyErrorMessage` name for lowest churn, apply it consistently across all `+0x0c` slots and keep `FormatErrorMessage` only as a per-method behavior description.

Helper/global names:

- `0x0041b9b0`: `CrtStdioCommonVswprintfSWrapper`; final NexusTK source should use normal `swprintf_s` style calls, not emit this CRT wrapper.
- `0x00471110`: `CrtWideVsnprintfWrapper`; final `FileError` source should use `swprintf_s` / `vswprintf_s` style formatting.
- `0x0069be6c`: imported/dispatch `FormatMessageW` pointer; use `FormatMessageW` in source drafts.
- `0x0060d11c`: imported `GetLastError` pointer.
- `0x0060d534`: imported `WSAGetLastError` pointer.
- `0x0069be30`: imported `LoadLibraryW` pointer.
- `0x0060d4a4`: imported `InternetGetLastResponseInfoA` pointer.
- `0x00582b20`, `0x00582d20`, `0x00582c60`, `0x00584540`, `0x00582b70`, and `0x00582b30`: `SimpleUString` construction/assignment/c-string/destructor/release helpers; keep descriptive names in this report until the `StringBase` support pages standardize exact source names.
- `0x005c7790`: allocation wrapper used by `MyError`; docs currently call it `unknown_libname_19`. Source draft can use `new wchar_t[...]` or project allocation wrapper only after allocator pages standardize the name.
- `0x005c7799`: free wrapper used by `MyError::~MyError`; source draft can use `delete[]` or `free` only after allocator-family evidence is reconciled. Current binary uses a CRT/free-like wrapper on the owned pointer.

## Formatter And Copy Behavior

Status-code formatters:

- `Win32Error::FormatErrorMessage` uses `FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM, 0, m_errorCode, 0x400, localBuffer, 0x200, 0)`, then writes either `L"%s : (%d)%s"` with `L"Win32Error"` or fallback `L"%s : 0d%p"`.
- `DIError::FormatErrorMessage` and `DSError::FormatErrorMessage` use the same `FormatMessageW` pattern and the `DirectInputError` / `DirectSoundError` string pairs.
- `DDError::FormatErrorMessage` uses the same local 512-wide buffer and emits either `DirectDrawError: %s  0x%p` or `DirectDrawError: 0x%p`.
- `WSAError::FormatErrorMessage` uses `FormatMessageW` with language `0` and the `WSAError` string pair.

Stored-message output helpers:

- `ErrorMessage` and `FileError` read inline wide buffers at byte offset `+0x04` and call `_wcscpy_s(destination, destinationChars, this + 4)`.
- `InternetError` and `InternetConnectionError` call the `SimpleUString` c-string helper on `this + 4`, then `_wcscpy_s`.
- `MyError` and `PasswordError` copy the owned heap wide pointer stored at `+0x04`.

Generated-name issues rejected:

- Generated `char *` signatures for `DIError`, `DSError`, and `WSAError` formatters are wrong for final source. The literals and formatting path are wide; use `wchar_t *`.
- Generated per-class files are not source-placement proof. Use one `util/Error.cpp` route.
- Generated `class_FileError.cpp` omits the exact `FileErrorCopyMessage` child and incorrectly models the constructor as no-argument. The binary pushes `[ebp+8]` as the path format argument, so the constructor should be `FileError(const wchar_t *path)`.
- Generated `class_PasswordError.cpp` still has known descriptor issues outside this target; keep B005/B002 corrections as authoritative.

## FileError Layout Note

The current `FileErrorConstructor` page has stale language about "terminating a trailing flag/status word after that buffer." Local bytes show:

```asm
004a643f  push    dword ptr [ebp + 8]
004a6442  lea     eax, [esi + 4]
004a6445  mov     dword ptr [esi], 0x006193d4
004a644b  push    0x006126f4
004a6450  push    0x4e
004a6452  push    0x50
004a6454  push    eax
004a6455  call    0x00471110
004a645d  xor     eax, eax
004a645f  mov     word ptr [esi + 0xa2], ax
```

This is not evidence for a separate trailing field. It is a defensive terminator write to the last element of `wchar_t m_message[80]`: byte offset `+0x04 + (79 * 2) = +0xa2`, still inside the `0x0a4` object size. This confirms the B002 layout direction: `FileError` is vptr plus `wchar_t m_message[80]`.

## Owner / Source Placement

Keep all target code under [UID:0000J5] `Error`:

- The range is a contiguous error hierarchy implementation cluster from `Win32Error` through `MyError`.
- Vtable data at `0x00619340-0x00619448` maps every formatter/copy/destructor/name slot back to this same cluster.
- Callers from DirectDraw, DirectInput, DirectSound, socket, WinINet, file/archive, password, and application code are consumers, not owners.
- `PasswordGuard` owns protected-text scanning and throw-site logic; `PasswordError` declaration/virtuals belong to the Error hierarchy.
- `Application` owns fatal dialog/break helpers; do not pull them back into `Error.cpp`.
- CRT wrappers at `0x0041b9b0` and `0x00471110` are runtime glue, not Error-owned source.

## Aggregate No-Code Proof

Do not populate `RECONSTRUCTION_CPP` on [UID:00013X].

Exact proof:

1. The page covers many independent C++ methods, not one source function or one class method.
2. Several methods already have exact children with class owners, while others still need exact children.
3. Three constructor-shaped starts are raw/no-xref and should not be emitted as normal function records without raw-child handling.
4. The destructor tail is already handled by [UID:0002TV], whose accepted B002 policy says scalar deleting destructor ABI wrappers should not be emitted as source-authored C++.
5. The missing `0x004a6470` helper is compiler/unwind cleanup-shaped and should be folded into destructor/constructor cleanup source, not emitted as a named product method.
6. Formal aggregate C++ would duplicate child pages and blur class ownership. Source should be assembled through exact children and/or the [UID:0000J5] file/class hierarchy after declaration names are standardized.

## First-Draft Source Shape

Use this only as review material for exact children or a future `Error.h` / `Error.cpp` pass. Do not paste it into the aggregate target.

```cpp
class Error : public LObject {
public:
    virtual ~Error();
    virtual void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const = 0;
    virtual const wchar_t *GetErrorName() const;
};

class Win32Error : public Error {
public:
    Win32Error();
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    DWORD m_errorCode;
};

class DDError : public Error {
public:
    explicit DDError(HRESULT result);
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    HRESULT m_errorCode;
};

class DIError : public Error {
public:
    explicit DIError(HRESULT result);
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    HRESULT m_errorCode;
};

class DSError : public Error {
public:
    explicit DSError(HRESULT result);
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    HRESULT m_errorCode;
};

class ErrorMessage : public Error {
public:
    ErrorMessage();
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    wchar_t m_message[256];
};

class FileError : public Error {
public:
    explicit FileError(const wchar_t *path);
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    wchar_t m_message[80];
};

class WSAError : public Error {
public:
    WSAError();
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    int m_errorCode;
};

class InternetError : public Error {
public:
    InternetError();
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    SimpleUString m_message;
};

class InternetConnectionError : public Error {
public:
    InternetConnectionError();
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    SimpleUString m_message;
};

class MyError : public Error {
public:
    explicit MyError(const wchar_t *message);
    ~MyError() override;
    void FormatErrorMessage(wchar_t *destination, size_t destinationChars) const override;
private:
    wchar_t *m_messageText;
};

Win32Error::Win32Error()
    : m_errorCode(::GetLastError())
{
}

DDError::DDError(HRESULT result)
    : m_errorCode(result)
{
}

FileError::FileError(const wchar_t *path)
{
    ::swprintf_s(m_message, _countof(m_message), L"File not found : %s", path);
    m_message[_countof(m_message) - 1] = L'\0';
}

MyError::MyError(const wchar_t *message)
{
    const size_t length = ::wcslen(message);
    m_messageText = new wchar_t[length + 1];
    ::wcsncpy_s(m_messageText, length + 1, message, length);
    m_messageText[length] = L'\0';
}

MyError::~MyError()
{
    delete[] m_messageText;
    m_messageText = 0;
}

void MyError::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const
{
    ::wcscpy_s(destination, destinationChars, m_messageText);
}

const wchar_t *Error::GetErrorName() const
{
    return L"Error";
}
```

The allocator/free calls in `MyError` should be reconciled with MemoryMan/CRT wrapper docs before final source. If those docs prove `free` rather than `delete[]`, change the destructor draft accordingly.

## Recommended Target Doc Changes

Update [UID:00013X]:

1. Metadata to `COMPLETION:87`, `CONFIDENCE:89`, owner/emitter unchanged.
2. Add a `2026-06-19 B013 source-quality recheck` evidence bullet covering local PE MD5, Capstone disassembly, direct-call/pointer scans, `0x004a6470`, and generated-name rejection.
3. Replace the range table with the inventory in this report or add rows for all previously aggregate-only bodies.
4. Add `0x004a6470-0x004a647b` between `FileErrorConstructor` and `FileErrorCopyMessage`.
5. Change the aggregate C++ explanation from "deferred" to an exact no-code proof: aggregate is reconstructable and routable but non-emitting by source-shape policy.
6. Add exact child split recommendations for every formatter/copy/raw-constructor/ordinary-destructor body listed above.
7. State the source-facing destructor/name-helper policy from B002: no scalar deleting destructor wrapper C++; ordinary destructors plus `Error::GetErrorName`.

## Recommended Support-Doc Changes

- [UID:0000J5] `Error`: add the missing `0x004a6470` cleanup helper to evidence/split candidates; keep `util/Error.cpp`; list remaining exact child pages needed.
- [UID:0001UE] `ErrorObjectLayouts`: promote the `FileError` conclusion from "no trailing field proven" to "constructor terminates the last wchar_t in `wchar_t[80]`; no separate trailing field is supported."
- [UID:0001XI] and [UID:0002ND]: keep the five-slot vtable shape, but add or cross-link the pending `0x004a6470` cleanup child because the page already mentions the base-vtable store.
- [UID:0002HL] `FileErrorConstructor`: replace "trailing flag/status word" with "writes a final NUL at `m_message[79]` / byte offset `+0xa2`"; correct constructor signature direction to `FileError(const wchar_t *path)`.
- `Win32Error`, `DDError`, `DIError`, `DSError`, and `WSAError` class pages: keep `FormatErrorMessage` as source-facing formatter name; reject generated `char *` signatures for DI/DS/WSA and use `wchar_t *`.
- `InternetError` and `InternetConnectionError`: decide whether to retain local names `GetErrorText` / `CopyErrorMessage` as behavior labels or standardize the virtual slot to `FormatErrorMessage`.
- `MyError` and [UID:0002HO]: create/cross-link exact children for `0x004a6840-0x004a6858` and `0x004a6860-0x004a6882`; final source should emit `MyError::~MyError()` once.
- `wave3_data_issues.md`: add the generated-output issues still relevant here: raw constructor starts, omitted `0x004a6470`, omitted `ErrorMessage`/`FileError` copy helpers, wrong `FileError` constructor signature, and generated `char *` formatter drift.

## IDA Rename / Type / Comment Recommendations

High confidence:

- `sub_4A6100` -> `Win32Error::FormatErrorMessage`.
- `sub_4A61E0` -> `DIError::FormatErrorMessage`.
- `sub_4A6290` -> `DDError::FormatErrorMessage`.
- `sub_4A6360` -> `DSError::FormatErrorMessage`.
- `sub_4A64D0` -> `WSAError::FormatErrorMessage`.
- `sub_4A6670` -> `InternetError::FormatErrorMessage` or `InternetError::CopyErrorMessage` after the common virtual name decision.
- `sub_4A6780` -> `InternetConnectionError::FormatErrorMessage` or `InternetConnectionError::CopyErrorMessage`.
- `sub_4A6840` -> `MyError::FormatErrorMessage` / `MyError::CopyErrorMessage`; note inherited use by `PasswordError`.
- `sub_4A6860` -> `MyError::~MyError` ordinary destructor body.
- `sub_4A6A70` -> `Error::GetErrorName`.

Medium confidence / raw policy:

- `0x004a61b0` -> raw `DIError::DIError(HRESULT)`, not a normal IDA function until intentionally created.
- `0x004a6330` -> raw `DSError::DSError(HRESULT)`, not a normal IDA function until intentionally created.
- `0x004a63e0` -> raw `ErrorMessage::ErrorMessage()`, not a normal IDA function until intentionally created.
- `sub_4A6470` -> `FileErrorBaseCleanupHelper` or `ErrorBaseCleanupHelper_FileError`; comment as duplicate base-vtable reset/tail-jump cleanup, no source-visible method.

Type/comment recommendations:

- Use `wchar_t *destination, size_t destinationChars` for the output-buffer virtual.
- Use `HRESULT` for DirectInput/DirectDraw/DirectSound constructor arguments.
- Use `wchar_t m_message[256]` for `ErrorMessage`, `wchar_t m_message[80]` for `FileError`, `SimpleUString m_message` for WinINet wrappers, and `wchar_t *m_messageText` for `MyError`.
- Comment `0x004a6470` as a real aggregate-covered helper and coverage split candidate.

## Exact Coverage Text

Replace the [UID:00013X] row with:

```text
    - [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md) 0x004a60d0-0x004a6a76 | class-method-cluster | ErrorWrappers : reconstructable : 87% : strong : Attached to Error.cpp; shared error hierarchy implementation aggregate with current 85/85+ route evidence, exact constructor/copy/destructor child pages, vtable/layout/message-string support, source-facing formatter/name/destructor policy, raw constructor starts at 0x004a61b0/0x004a6330/0x004a63e0, newly identified 0x004a6470 base-cleanup child gap, and blank formal C++ because this broad mixed range should emit through exact child methods or the Error hierarchy file/class reconstruction rather than aggregate C++.
```

If the supervisor creates the missing `0x004a6470` exact child, add this nested row after [UID:0002HL] and before [UID:000140], replacing `UID:NEW` and the filename with the assigned UID/path:

```text
        - [UID:NEW][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) 0x004a6470-0x004a647b | helper | FileErrorBaseCleanupHelper : reconstructable : 85% : strong : Two-instruction Error base-vtable reset/tail-jump cleanup helper between FileError constructor and FileError copy-message slot; local PE bytes match the existing 0x004a6400 cleanup-helper shape, address evidence is limited to the base-vtable immediate at 0x004a6472 with no direct call/pointer xrefs, and final source should fold it into destructor/unwind cleanup rather than emit a named product helper.
```

Existing nested rows for [UID:0002HL], [UID:000140], [UID:0002HJ], [UID:0002HK], [UID:00013Y], [UID:0002HM], [UID:0002HN], and [UID:0002HO] appear stale in `by-memory/-coverage-report.md` compared with current by-memory scores. This report does not provide replacement rows for those children because they are outside the requested target, but the supervisor may want to regenerate or sync the coverage report after applying this report.

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00013X-ErrorWrappers-source-quality-removed.md](00013X-ErrorWrappers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If new exact child pages are created, validate each new child with the same `--mode file --apply` command, then regenerate memory coverage/report artifacts with the project's normal supervisor-owned report workflow.

IDA/MCP validation to run when available:

- `lookup_funcs` for every range start in the inventory, especially `0x004a6470`.
- `xrefs_to 0x004a6470`, `xrefs_to 0x00619344`, and `xrefs_to` each formatter/copy slot target.
- `get_bytes 0x004a646f size 0x31` to confirm `0x004a6470-0x004a647b` and padding before `0x004a6480`.
- `decompile` or `disasm` for `0x004a6100`, `0x004a61e0`, `0x004a6290`, `0x004a6360`, `0x004a64d0`, `0x004a6670`, `0x004a6780`, `0x004a6840`, and `0x004a6860`.
- Data dword read of `0x00619340-0x00619448` to ensure the vtable slot map still matches the support docs.

## Implementation Readiness

[UID:00013X] is ready for supervisor implementation as a report-backed documentation update. It should remain a reconstructable, `Error.cpp`-owned, non-emitting aggregate. The exact child split list is the next source-quality path: exact children can receive first-draft source-style C++ one by one after their names/signatures are standardized, while the aggregate stays a route/evidence page.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00013X-ErrorWrappers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00013X"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013X-ErrorWrappers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00013X-ErrorWrappers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
