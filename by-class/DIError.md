*** UID:00003W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DIError class-level source is covered by [UID:0000J5][Error](by-file/Error.md); the raw constructor-shaped start at 0x004a61b0 has no current IDA function or xref route, so this class page emits no standalone declaration/body until the raw constructor and DIError formatter are split or standardized.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

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
- 2026-06-19 B013 rejects the stale generated `char *` formatter signature for final source. The formatter participates in the Error hierarchy's wide-buffer message virtual and should be modeled as `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` or the project-wide equivalent once the hierarchy spelling is standardized.
- Live vtable data confirms RTTI at `0x00619370`, destructor slot `0x00619374 -> sub_4A68A0`, formatter slot `0x00619380 -> sub_4A61E0`, and name/descriptor slot `0x00619384 -> sub_4A6A70`.
- The constructor vtable-store xref is `0x004a61c7 -> 0x00619374`; shared status-code destructor `sub_4A68A0` is also used by `Win32Error`, `DDError`, `DSError`, and `WSAError` vtables, matching the stored-code layout family.
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms `0x004a61b0` as `Not a function`, `sub_4A61E0` size `0x7b`, shared status-code destructor `sub_4A68A0` size `0x3e`, and shared name helper `sub_4A6A70` size `0x6`.
- Current xrefs still show no references to the raw constructor start `0x004a61b0`; the formatter remains vtable-data referenced at `0x00619380`, the raw constructor's vtable store remains `0x004a61c7 -> 0x00619374`, and `sub_4A68A0` has exactly the five status-wrapper destructor-slot xrefs at `0x0061935c`, `0x00619374`, `0x0061938c`, `0x006193a4`, and `0x006193ec`.
- `analyze_component` over `0x004a61e0`, `0x004a68a0`, and `0x004a6a70` reports stable formatter/destructor/name-helper sizes and no internal call-graph edge, matching the vtable-dispatched wrapper model. `make_signature_for_range(0x004a61b0,0x004a625b)` returns a unique wildcarded signature for the raw constructor plus formatter span.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but leave C++ blank. The formatter and vtable/layout evidence are strong; the constructor start and final declaration spelling are not ready for final source.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page now records DirectInput responsibility, shared Error ownership, exact raw constructor bytes, stored-code layout, formatter function bounds, fallback formatting path, vtable slots, padding boundary, status-wrapper destructor fanout, unique raw-constructor/formatter signature, and no-code handling. Completion remains capped because the constructor is not an IDA-modeled function and final field/member names are unresolved. |
| Confidence `88` | The formatter, vtable, layout family, signature, and source owner are strongly supported by live IDA plus the error hierarchy docs. Confidence is still capped because `0x004a61b0` remains constructor-shaped raw code without function/caller/xref confirmation. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619340-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md)

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
- 2026-06-15 A002 Goal 2 by-class refresh:
  - Changed to: scores `85/88`, with no owner/emitter changes.
  - Summary/evidence: live IDA reconfirmed the raw constructor remains non-modeled/no-xref, the formatter and shared destructor/name-helper sizes, vtable-only formatter anchor, raw constructor vtable store, five-class status-wrapper destructor fanout, component shape, and unique raw constructor plus formatter signature. C++ remains blank because constructor reachability and final declaration/member names are not source-quality.
- 2026-06-19 B013 signature sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: B013 keeps the raw constructor no-route policy and rejects generated `char *` formatter output; final source should use the Error hierarchy's wide-buffer message virtual for this formatter.
