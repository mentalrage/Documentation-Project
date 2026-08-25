*** UID:00008V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int MyError::FormatErrorMessage(
    wchar_t *destination,
    size_t destinationChars) const
{
    return wcscpy_s(destination, destinationChars, m_messageText);
}

MyError::~MyError()
{
    delete [] m_messageText;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MyError

## Status

- Confidence: very strong for class responsibility, coordinated H ownership, exact constructor/formatter/ordinary-destructor source, owned heap-message layout, and compiler-only scalar wrapper.
- Source module: [UID:0000J5][Error](by-file/Error.md)
- Exact constructor: [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md)
- Destructor/name helper tail: [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)
- Aggregate range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Declaration owner: [UID:00004J][Error](by-class/Error.md) emits the single guarded Error/MyError H block; this page's H channel intentionally stays blank.
- Parent attachment: attached to [UID:0000J5][Error](by-file/Error.md) because the file page is `87/85` and this class page is now `87/90`.
- Evidence basis: existing IDA-backed by-memory constructor/destructor pages, live 2026-06-15 IDA MCP constructor/signature/xref refresh, B004 2026-06-26 MCP session `80de0a67` source-shape recheck, error vtable/layout docs, and the shared `Error.cpp` file page.

## Responsibility

`MyError` is an application-specific error class that owns a dynamically copied wide error message in an array-owned heap pointer field. `PasswordError` derives from it and reuses the inherited message storage before installing its own vtable. B013's 2026-06-28 constructor sync confirms that the derived source constructor is now explicitly represented as `PasswordError::PasswordError(const wchar_t *message) : MyError(message) {}`, so the subclass relationship is no longer a constructor-local blocker for either class.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) | `MyError::MyError(const wchar_t *message)` | Source-ready exact constructor. B004 MCP session `80de0a67` confirms the 0x9d range, shared base setup, `MyError` vtable install, `wcslen`, runtime allocation thunk, pointer store at `+0x04`, `_wcsncpy_s`, explicit terminator, and caller map. The formal C++ block now uses `size_t length`, `new wchar_t[length + 1]`, `wcsncpy_s`, and `m_messageText[length] = L'\0'`. |
| `[0x004a6840,0x004a6858)` | `MyError::FormatErrorMessage` | Exact nine-instruction `wcscpy_s` wrapper returning an int-compatible status from `m_messageText` at `+0x04`; emitted above. |
| `[0x004a6860,0x004a6882)` | `MyError::~MyError` | Exact ordinary source destructor; releases array-owned `m_messageText` and lets compiler/base teardown restore Error/LObject state; emitted above. |
| [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md) | scalar deleting destructor family | The `0x004a6a10` wrapper mirrors `MyError` storage cleanup and optionally deletes `this`; final C++ should coordinate with `0x004a6860` and not emit a second source destructor body from the wrapper. |

## Source Allocation

| Claim | Physical action | Disposition |
| --- | --- | --- |
| `C0000IW-164` | MyError H channel | Intentionally blank; UID00004J supplies the complete declaration once. |
| `C0000IW-165` | Formatter CPP method | Exact `[0x004a6840,0x004a6858)` method emitted above. |
| `C0000IW-166` | Ordinary-destructor CPP method | Exact `[0x004a6860,0x004a6882)` method emitted above. |
| `C0000IW-128` | Scalar-wrapper source | `0x004a6a10` compiler-covered by the ordinary destructor; no duplicate CPP. |

The trailing `[[CHILDREN]]` route emits exact constructor child UID0002HO once. It is required to preserve C0000IW-173 in generated `Error.cpp`; the child retains its own formal payload and blank H disposition.

## Ownership Notes

This is shared application error infrastructure. Keep it with [UID:0000J5][Error](by-file/Error.md), even when callers originate from password validation, map/dialog code, or transport code.

The object layout is the heap-message storage family: vtable at `+0x00`, owned `wchar_t *m_messageText` at `+0x04`. B004 keeps `m_messageText` as the best source-facing inferred member name because it distinguishes this heap pointer family from inline `wchar_t m_message[...]` storage and `SimpleUString m_message` storage. The constructor source shape is array-owned: `MyError::MyError(const wchar_t *message)` computes the wide length, allocates `new wchar_t[length + 1]`, copies with `wcsncpy_s`, and explicitly terminates the buffer. The binary lowers that source allocation through the runtime allocation thunk at `0x005c7790`; no project `MemoryMan` callee is present.

[UID:0000A8][PasswordError](by-class/PasswordError.md) reuses the same message-copy slot and installs a separate vtable. Its constructor [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md) calls this `MyError` constructor with the supplied wide message, then receives the compiler-generated `PasswordError::vftable` store; the accepted formal source is `PasswordError::PasswordError(const wchar_t *message) : MyError(message) {}`. That is subclass/source-route evidence, not a reason to delay the `MyError` constructor C++.

2026-06-19 B013's helper/destructor bounds remain valid; the accepted DirectX support pass closes their source disposition without creating redundant exact-child pages. `[0x004a6840,0x004a6858)` emits `MyError::FormatErrorMessage`, `[0x004a6860,0x004a6882)` emits the ordinary destructor, and scalar wrapper `0x004a6a10` remains compiler ABI support with no second source destructor.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md). UID00004J owns the complete H declaration, this page owns the exact formatter and ordinary destructor CPP, and UID0002HO owns the constructor CPP. The channels now form one complete source route without duplicate declarations or scalar-wrapper bodies.

## Score Rationale

- Completion is `91` because the class now has exact constructor identity, exact formatter/destructor CPP, coordinated blank-H disposition, complete guarded declaration on UID00004J, 0x8 layout, field ownership, PasswordError inheritance, and compiler-only `0x004a6a10` coverage.
- Confidence is `93` because function bounds/disassembly/vtable routes, constructor payload, layout, formal source, and Error H agree. It remains below 95 because `m_messageText` and original hierarchy tokens are inferred without PDB evidence.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000A8][PasswordError](by-class/PasswordError.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md)
- [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md)

## Changes

- 2026-08-14 B004 UID0000IW associated-support implementation:
  - Raised `87/90` to `91/93`; replaced the marker with exact `MyError::FormatErrorMessage` and ordinary `MyError::~MyError` CPP methods.
  - Kept H blank because UID00004J owns the coordinated declaration, added the child insertion point required to emit UID0002HO's exact constructor source once, and closed `0x004a6a10` as compiler-generated from the ordinary destructor with no duplicate CPP.

- 2026-06-28 B013 PasswordError derived-constructor sync:
  - Score unchanged.
  - Added that [UID:0002VJ][0x00467160-0x00467181.PasswordErrorConstructor](by-memory/0x00467160-0x00467181.PasswordErrorConstructor.md) now emits `PasswordError::PasswordError(const wchar_t *message) : MyError(message) {}` through [UID:0000A8][PasswordError](by-class/PasswordError.md) / [UID:0000J5][Error](by-file/Error.md), using this class's already source-ready `MyError(message)` base constructor.
  - Summary/evidence: live MCP session `supervisor_20260628_resume` reconfirmed the `MyError` base-constructor call and compiler-generated derived vtable store. This does not change MyError class-level C++, which still waits on the broader Error hierarchy declaration and adjacent helper/destructor children.

- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: the application error class has clear responsibility, module placement, constructor/destructor/deleting-destructor addresses, layout family, and `PasswordError` relationship documented, but the page is intentionally concise and does not expand every caller path. Evidence: linked `ErrorWrappers` memory range, error hierarchy vtable/layout docs, shared `Error` module, and owned wide-message slot.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: constructor/destructor/layout evidence supports shared `Error.cpp` ownership; password/fatal helpers remain separate ownership caveats.
- 2026-06-06 A004 parent-gate cleanup:
  - Before: the class page was `74/86` while child constructor pages were already attached to it.
  - After: `COMPLETION:82`, exact constructor/destructor-family links, parent-gate wording, by-* evidence basis, and score rationale.
  - Summary/evidence: [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md), [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md), [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md), and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) support the higher completion score. Final C++ remains blank until the source hierarchy declaration is final.
- 2026-06-15 A002 Goal 2 parser/config/error batch:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`.
  - After: `COMPLETION:85`, `CONFIDENCE:88`; owner/emitter unchanged at [UID:0000J5][Error](by-file/Error.md).
  - Summary/evidence: live IDA MCP reconfirmed [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) as a 0x9d constructor with unique signature, base setup, heap-message allocation/copy, five constructor refs, and `0x00619434` constructor/destructor-family vtable xrefs. Final C++ remains blank until allocator naming and the Error.h/PasswordError split are settled.
- 2026-06-17 B002 destructor pairing sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: accepted B002 [UID:0002TV][0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers](by-memory/0x004a68a0-0x004a6a76.ErrorDestructorAndNameHelpers.md) source-quality report clarified that `0x004a6860` is the ordinary source destructor body and `0x004a6a10` is the scalar deleting wrapper. Final source should emit `MyError::~MyError()` once, using `m_messageText` as the current descriptive owned-pointer name until original naming is proven.
- 2026-06-19 B013 child-split sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: B013 confirms the exact-child need for `0x004a6840-0x004a6858` and `0x004a6860-0x004a6882`, keeps `m_messageText` as the current descriptive field name, and preserves the rule that scalar deleting wrappers inform but do not duplicate ordinary destructor source.
- 2026-06-26 B004 MyError constructor source-quality implementation:
  - Before: `COMPLETION:85`, `CONFIDENCE:88`, with class-level autogen text still treating allocator naming and `PasswordError` split as constructor C++ blockers.
  - After: `COMPLETION:87`, `CONFIDENCE:90`; class owner/emitter/reconstructable metadata unchanged and class formal C++ still blank pending the full hierarchy declaration.
  - Summary/evidence: accepted B004 report for [UID:0002HO][0x004a67a0-0x004a683d.MyErrorConstructor](by-memory/0x004a67a0-0x004a683d.MyErrorConstructor.md) used MCP session `80de0a67` to resolve the constructor-local source shape as array-owned `wchar_t *m_messageText`, `new wchar_t[length + 1]`, `_wcsncpy_s`, and explicit termination; records `PasswordError` as subclass/consumer evidence; and keeps `0x004a6840` plus `0x004a6860` as adjacent exact-child caveats rather than blockers for the constructor.
