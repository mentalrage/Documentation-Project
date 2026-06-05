*** UID:00003W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DIError

## Status

- Confidence: strong for formatter responsibility, shared Error ownership, vtable slots, and raw constructor bytes; medium for normal constructor reachability because IDA still does not model `0x004a61b0` as a function object.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Rebuild handling: source-authored DirectInput error wrapper. Attached to [UID:0000J5][Error](by-file/Error.md); C++ remains blank because the constructor is raw/non-IDA-modeled and the final class declaration is below the reconstruction-code gate.

## Responsibility

`DIError` wraps DirectInput HRESULT-style failures and formats them into readable DirectInput error messages.

In the shared error layout, `DIError` belongs to the stored-status-code family: vtable at `0x00619374`, caller HRESULT stored at byte offset `+0x04`, message/format slot `0x004a61e0`, shared scalar deleting destructor `0x004a68a0`, and shared name/descriptor slot `0x004a6a70`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a61b0-0x004a61d4` | raw constructor | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `0x004a61e0-0x004a625b` | `FormatErrorMessage` | IDA-confirmed function that formats DirectInput errors. |

## Ownership Notes

Use only the confirmed formatter range for source migration until the constructor projection is resolved. The implementation still belongs with shared errors, not `input/InputMan.cpp`.

- 2026-06-05 live IDA MCP reports no function object at `0x004a61b0`; `xrefs_to(0x004a61b0)` is empty and a little-endian pointer-byte search for `0x004a61b0` found no matches.
- Direct disassembly covers `0x004a61b0-0x004a61d4`: the raw constructor calls shared base setup `sub_4F4A80` at `0x004a61ba`, stores the caller HRESULT/status argument at `this+0x04` at `0x004a61c2`, installs `??_7DIError@@6B@` at `0x004a61c7`, and returns with `retn 4`.
- `0x004a61d4-0x004a61e0` is `0xcc` padding before formatter function `sub_4A61E0`.
- Live IDA reports `sub_4A61E0` as a real function at `0x004a61e0-0x004a625b`, referenced from vtable slot `0x00619380`.
- Formatter decompilation uses the stored code at `this+0x04`, calls the DirectInput formatter/import slot `dword_69BE6C`, copies a returned message when present, and falls back to formatting `DI:%08X`.
- Live vtable data confirms RTTI at `0x00619370`, destructor slot `0x00619374 -> sub_4A68A0`, formatter slot `0x00619380 -> sub_4A61E0`, and name/descriptor slot `0x00619384 -> sub_4A6A70`.
- The constructor vtable-store xref is `0x004a61c7 -> 0x00619374`; shared status-code destructor `sub_4A68A0` is also used by `Win32Error`, `DDError`, `DSError`, and `WSAError` vtables, matching the stored-code layout family.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but leave C++ blank. The formatter and vtable/layout evidence are strong; the constructor start and final declaration spelling are not ready for final source.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The page now records DirectInput responsibility, shared Error ownership, exact raw constructor bytes, stored-code layout, formatter function bounds, fallback formatting path, vtable slots, padding boundary, and no-code handling. Completion remains capped because the constructor is not an IDA-modeled function and final field/member names are unresolved. |
| Confidence `86` | The formatter, vtable, layout family, and source owner are strongly supported by live IDA plus the error hierarchy docs. Confidence is still below the reconstruction-code threshold because `0x004a61b0` remains constructor-shaped raw code without function/caller/xref confirmation. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)

## Changes

- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores and stale staging-source wording, with only summarized formatter and raw-constructor evidence.
  - Changed to: scores `82/86`, direct live IDA evidence for the exact raw constructor, formatter range, formatter fallback behavior, vtable slots, no-xref/no-pointer constructor reachability, and padding boundary.
  - Summary/evidence: completion increased because the page now documents the constructor body, stored-code layout, formatter body, and vtable slot map directly. Confidence increased because live IDA confirms exact function/range/vtable evidence while preserving the raw-constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
- 2026-06-02:
  - Before: scored `64/74`, reconstructability and parent blank.
  - After: scored `72/82`, marked reconstructable, and attached to [UID:0000J5][Error](by-file/Error.md) with C++ blank.
  - Why: existing vtable/layout/error-wrapper evidence strongly supports shared `util/Error.cpp` ownership and DirectInput formatter behavior, while the constructor start remains a raw projected boundary.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/74`.
  - Summary/evidence: DirectInput formatter responsibility, shared error-module placement, confirmed formatter range, and raw constructor caveat are documented; confidence remains limited until the constructor boundary is reconciled.
