*** UID:00004X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// FileError class-level source is covered by [UID:0000J5][Error](by-file/Error.md) and exact children [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md); this page emits no standalone partial declaration while the shared Error.h virtual/destructor policy remains coordinated at the hierarchy level.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FileError : public Error
{
public:
    FileError(const wchar_t *path);
    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t m_message[80];
};

typedef char FileErrorSizeMustBe0xA4[
    sizeof(FileError) == 0xA4 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FileError

## 2026-08-18 Complete Error-Header Declaration

The formal H channel now closes the already-proven `FileError` source shape: concrete `Error` derivation, `FileError(const wchar_t *path)`, the vtable-backed `FormatErrorMessage` override, inline `wchar_t m_message[80]` at `+0x04`, and exact total size `0xA4`. Constructor and message-copy implementations remain on their exact Error-owned children. Archive code only includes `Error.h` and throws this existing type; it does not own or duplicate the class.

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_FileError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact method/support pages: [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md), [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md), and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- Evidence basis: existing generated/source summaries plus live IDA MCP checks through the dedicated 2026-08-10 UID00048A revalidation for the constructor body, unique range signatures, caller refs, vtable data refs, cleanup/copy-helper boundaries, inline-buffer field shape, and the FileError-adjacent cleanup island source-placement decision.
- Formal-source disposition: this class page emits the complete H declaration. Exact constructor and message-copy children emit the bodies; compiler cleanup/scalar-destructor products remain non-authored evidence.

## Responsibility

`FileError` is a concrete error class for file-not-found or file-open failures with a default formatted message template. File/archive code constructs it on stat/open failures, but the implementation belongs to the shared error hierarchy in [UID:0000J5][Error](by-file/Error.md).

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) | `FileError(const wchar_t *path)` | Source-ready exact child. Live IDA/B002 evidence confirms a 0x3f constructor with unique signature, shared base setup, `FileError` vtable install, `_snwprintf_s(m_message, 80, 78, L"File not found : %s", path)` lowering through the CRT wide-format wrapper, and final NUL write at `m_message[79]` / byte offset `+0xa2`. |
| [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) | cleanup island | Exact child for the executable island between the constructor and copy helper. It writes the base `Error` vtable and tail-jumps to inherited cleanup with no direct xrefs or pointer-route hits; it is Error hierarchy destructor/unwind support, not a source-visible FileError method. |
| [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) | `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` | Source-ready exact child. B006 MCP evidence confirms the `0x19` / 25-byte body, `_wcscpy_s` callee, no direct callers, vtable-only liveness at `0x006193e0`, `find_bytes` VA-only slot route, `m_message` source at byte offset `+0x04`, and formal `int` first-draft source returning `wcscpy_s(destination, destinationChars, m_message)`. |
| `0x004a6970` | `ScalarDeletingDestructor` | Base teardown and optional deletion. |

## Ownership Notes

Keep the class in `util/Error.cpp`; file/archive loaders should construct it but should not own the wrapper implementation. IDA xrefs place [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) in the `FileError` vtable message slot at `0x006193e0`, and the constructor writes the `FileError` vtable at `0x004a6445`.

The constructor callers recorded in the exact method page include archive/file paths such as `0x0049c180`, `0x004f53b0`, and `0x005820d0`; these are use-sites, not source ownership evidence. [UID:0000J5][Error](by-file/Error.md) groups the compact `0x004a60d0-0x004a6a76` Win32/DirectX/file/Winsock/WinINet wrapper run as the shared error module.

B002's 2026-06-26 accepted implementation pass resolves the target-local constructor blockers. `path` is the best source-facing argument name because `StdioFile::Open` and DAT/open call sites pass path-like file strings, while the LogoPlayerPane caller passes a formatted file-detail string to the same file-not-found constructor. `ArgList` is only an IDA placeholder; `fileName`, `message`, and `detail` are weaker for the class API. The source field should be modeled as `wchar_t m_message[80]`; exact original spelling is inferred, but the type, capacity, and offset are proven enough for the constructor child to emit formal C++.

B005's 2026-06-27 cleanup-island pass resolves the formerly pending `0x004a6470-0x004a647b` split as [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md). MCP session `80de0a67` confirms `sub_4A6470` size `0x0b`, bytes `c7 01 44 93 61 00 e9 15 e6 04 00`, write to `Error::vftable` at `0x00619344`, tail jump to `sub_4F4A90`, no xrefs/callers, no VA/RVA pointer-route hits, and padding before [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md). Adjacency explains the documentation filename, but the source owner/emitter remains [UID:0000J5][Error](by-file/Error.md) because the island resets the base `Error` vtable and is represented by Error hierarchy destructor/unwind source rather than a FileError product method.

### 2026-08-10 UID00048A Dated Non-Ownership Snapshot

- The dedicated dated B001 snapshot recorded UID00048A as exact independent function `[0x004a6470,0x004a647b)`, with unique bytes `c7 01 44 93 61 00 e9 15 e6 04 00`, one predecessor `0xcc` byte, and five successor `0xcc` bytes. It neither extends the constructor nor overlaps the copy helper.
- The function is a `void __thiscall` implicit-`ecx` cleanup with no explicit arguments or locals. It installs base `Error::vftable` at `0x00619344` and tail-jumps to inherited `LObject_destructor` at `0x004f4a90`; those operations contain no FileError field, message buffer, file API, or product behavior.
- The dated route-check snapshot recorded zero callers, zero incoming start xrefs, zero exclusive-end xrefs, and no VA/RVA pointer hits for the start or end. The exact body occurred once. These session-derived observations are historical evidence unless fresh supervisor attestation and bounded readback later confirm them. The documented source disposition remains retained compiler support with no recovered direct route, not padding and not a source API.
- FileError method identity is affirmatively separated. The constructor is `[0x004a6430,0x004a646f)`, the message virtual is `[0x004a6480,0x004a6499)` and vtable-routed at `0x006193e0`, and the FileError scalar deleting destructor is the distinct `0x004a6970` vtable target. Naming UID00048A `FileError::~FileError` or adding a FileError helper would conflate these separate entities.
- The dated B001 report recommends the descriptive IDA analysis name `FileErrorConstructionErrorCleanupThunk`, with analysis declaration `void __thiscall FileErrorConstructionErrorCleanupThunk(Error *this)`. `FileErrorConstruction` records adjacency/context; the receiver remains `Error *` because the body establishes base Error state and no FileError UDT or FileError-specific operation supports a derived analysis type. The name/type are proposed analysis aids, not current IDA-state claims, and do not belong in final source; fresh supervisor Gate 2B attestation/readback controls any application decision.
- Class metadata and formal source remain unchanged. [UID:00004X] stays owned/emitted through [UID:0000J5][Error](by-file/Error.md), and its class-level marker remains intact; UID00048A stays marker-covered by ordinary Error destructor/unwind source with no standalone CPP body or H declaration.

## Layout And Vtable Notes

| Item | Evidence | Reconstruction Note |
| --- | --- | --- |
| vtable pointer | Constructor writes the `FileError` vtable, with table data documented through [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md). | Keep as a concrete derived error class under `Error.h`/`Error.cpp`. |
| inline message buffer | Constructor formats into `this + 2` in `wchar_t*` terms, i.e. byte offset `+0x04`; copy helper reads the same offset. B013 and B002 confirm the constructor write at `+0xa2` is the final `wchar_t` of `wchar_t m_message[80]`, not a trailing status/flag member. B002 also rechecked the `0x50` buffer count, `0x4e` max count, UTF-16 `L"File not found : %s"` literal, and `m_message[79]` terminator math. | Use `wchar_t m_message[80]` as the current source-facing layout. The original member spelling remains inferred, but `m_message` is now strong enough for the exact constructor child's formal C++. |
| message-output virtual | Vtable data xref at `0x006193e0` targets [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md). B006 decodes the `0x006193d0` vtable row as RTTI `0x00646d60`, destructor `0x004a6970`, runtime `0x004f4b10`, no-op `0x0041b6c0`, message slot `0x004a6480`, and name slot `0x004a6a70`. | Preserve and emit this method from the exact memory child as `int FileError::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const`; the class-level block remains blank because the broader `Error.h` declaration is still inferred. |
| adjacent cleanup island | [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) sits between the constructor and copy helper, writes `0x00619344`, and tail-jumps to inherited cleanup. | Use as boundary/unwind evidence only; do not add a FileError source method. |
| scalar deleting destructor | Listed inside the shared error wrapper cluster at `0x004a6970`. | Treat as compiler/vtable support until the hierarchy-level destructor strategy is reconstructed. |

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. C++ stays blank at the class level until the whole Error hierarchy declaration, shared `+0x0c` virtual method spelling/return, destructor declaration policy, and `Error.h` shape are standardized.

Child memory pages already document this local range: [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md), [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md), and [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md). [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) emits its constructor body; [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) emits only a Rule 28 marker through [UID:0000J5][Error](by-file/Error.md) because it is compiler cleanup/unwind support; [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) now emits the target-local first-draft `FormatErrorMessage` body through this class/file route. The broader class declaration and sibling `+0x0c` method standardization remain hierarchy-level work, not a blocker for this exact method body.

## Score Rationale

The page is scored `87/91` because exact constructor and copy-message child pages now anchor the class behavior, B002 live IDA MCP reconfirms the constructor body, unique signature, four caller refs, literal bytes, cleanup/copy-helper boundaries, and `FileError::vftable` write, B006 live MCP evidence resolves the copy helper into a source-ready `FormatErrorMessage` method, parent ownership is established, caller versus owner boundaries are documented, and the inline-message/vtable layout is tied back to type docs. Completion remains below final-source quality because the final class declaration, full hierarchy header shape, sibling `+0x0c` declarations, and destructor treatment still need a hierarchy-wide reconstruction pass.

2026-06-19 B013 resolves the prior constructor-signature and trailing-field ambiguity enough for documentation: final source should be modeled as `FileError::FileError(const wchar_t *path)` writing into `wchar_t m_message[80]`. 2026-06-26 B002 resolves that target-local constructor body enough for the exact child to emit formal C++; 2026-06-27 B006 resolves the target-local message-output body enough for [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) to emit formal C++. This class page still keeps C++ blank because the full Error hierarchy declaration and destructor policy must be standardized before emitting class-level source.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md)
- [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md)
- [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000JB][File](by-file/File.md)

## Changes

- 2026-06-27 B006 FileErrorCopyMessage implementation:
  - Score unchanged at `87/91`; class-level owner/emitter unchanged at [UID:0000J5][Error](by-file/Error.md); class-level formal C++ remains blank.
  - Summary/evidence: accepted B006 report for [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) raised that exact child to `90/92` and inserted formal first-draft `int FileError::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const`. MCP session `015dfb2d-653b-48c9-8e5a-b136be8afb26` / database `80de0a67` confirms exact `0x19` / 25-byte bounds, `_wcscpy_s` return, no direct callers, vtable slot at `0x006193e0`, `find_bytes` VA-only route, `0x006193d0` vtable decode, constructor store at `0x004a6445`, `m_message[80]` constructor pairing, adjacent cleanup/padding boundaries, and rejection of `CopyErrorMessage`, `GetErrorText`, `void`, target-local `errno_t`, and a formal comment marker for this exact method.
- 2026-06-15 A002 Goal 2 parser/config/error batch:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`.
  - After: `COMPLETION:85`, `CONFIDENCE:89`; owner/emitter unchanged at [UID:0000J5][Error](by-file/Error.md).
  - Summary/evidence: live IDA MCP reconfirmed [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) as a 0x3f constructor with unique signature, base setup, vtable store, inline-message formatting, four constructor refs, and `0x006193d4` vtable data xref. This is enough to clear the parent gate while leaving final C++ blank.
- 2026-06-19 B013 source-quality clarification:
  - Score unchanged at `85/89`.
  - Summary/evidence: B013 local byte review rejects the stale trailing flag/status interpretation. The constructor path argument and final NUL write support `FileError(const wchar_t *path)` with `wchar_t m_message[80]`; exact source member spelling and hierarchy declaration remain open.
- 2026-06-26 B002 FileErrorConstructor implementation:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:91`; owner/emitter unchanged at [UID:0000J5][Error](by-file/Error.md); class-level formal C++ remains blank.
  - Summary/evidence: accepted B002 report for [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) synchronizes this class with live MCP session `80de0a67`: exact constructor range and unique signature, `FileError` vtable store, `L"File not found : %s"` literal bytes, CRT formatting-wrapper role, `wchar_t m_message[80]` with final `m_message[79]` terminator, caller/use-site distinction, cleanup island boundary at `0x004a6470`, and copy-helper/vtable relationship. The exact constructor child now has formal C++; this class page waits on hierarchy-wide declaration work.
- 2026-06-27 B005 cleanup-island implementation:
  - Score unchanged at `87/91`; class-level owner/emitter unchanged at [UID:0000J5][Error](by-file/Error.md); class-level formal C++ remains blank.
  - Summary/evidence: accepted B005 report created [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) as the exact child for the FileError-adjacent cleanup island. MCP session `80de0a67` confirms the modeled `0x0b` function, base `Error` vtable write, inherited cleanup tail jump, no xrefs/callers, no pointer-route hits, bytes/padding, and source placement in Error hierarchy destructor/unwind code rather than a FileError method.
- 2026-08-10 B001 UID00048A dated revalidation snapshot:
  - Score remains `87/91`; owner/emitter and class-level formal source remain unchanged.
  - Added dated snapshot evidence for exact range/bytes/boundaries, ABI, route negatives, unique-body result, constructor/copy-helper/scalar-destructor separation, descriptive IDA name/type disposition, and continued Error.cpp marker-only source route. These observations remain historical unless fresh supervisor attestation/readback confirms them; the documented evidence strengthens the existing non-ownership conclusion without inventing a FileError method.
- 2026-06-07: Raised `COMPLETION` from `74` to `82` and `CONFIDENCE` from `86` to `88`.
  - Before: the class identified the shared error-module owner and the copy helper but did not consolidate the exact constructor page, inline-message layout evidence, child-page attachment state, caller/owner boundary, or score rationale.
  - After: the page links the exact constructor and copy-message method pages, documents the `+0x04` inline wide-message storage, vtable slot `0x006193e0`, constructor caller examples, generated-output omission caveat, autogen child state, and final-C++ blockers.
  - Evidence: [UID:0002HL][0x004a6430-0x004a646f.FileErrorConstructor](by-memory/0x004a6430-0x004a646f.FileErrorConstructor.md) records base setup, vtable write, message formatting, and file/archive caller xrefs; [UID:000140][0x004a6480-0x004a6499.FileErrorCopyMessage](by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md) records the omitted real vtable-slot helper.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: class responsibility, constructor/copy/destructor evidence, vtable slot placement, and file-module ownership are documented; remaining gaps are mostly final source reconstruction and broader error-hierarchy details. Evidence: IDA-confirmed constructor at `0x004a6430`, copy helper `0x004a6480-0x004a6499`, vtable slot note at `0x006193e0`, and `ErrorWrappers` memory page.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: constructor/copy-helper/vtable evidence supports shared `Error.cpp` ownership; archive/file docs remain caller-side evidence only.
