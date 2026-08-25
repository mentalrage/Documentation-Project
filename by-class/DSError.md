*** UID:000045 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DSError class-level source is covered by [UID:0000J5][Error](by-file/Error.md); the raw constructor-shaped start at 0x004a6330 has no current IDA function or xref route, so this class page emits no standalone declaration/body until the raw constructor and DSError formatter are split or standardized.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DSError

## Status

- Confidence: strong for formatter responsibility and vtable placement; medium-high for the raw constructor boundary.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x006193a0`, vtable `0x006193a4`
- Evidence basis: live IDA MCP disassembly/decompilation checks on 2026-06-05.

## Responsibility

`DSError` wraps DirectSound HRESULT-style failures and formats them as `DirectSoundError` messages.

In the shared error layout, `DSError` belongs to the stored-status-code family: vtable at `0x006193a4`, caller HRESULT stored at byte offset `+0x04`, message/format slot `0x004a6360`, shared scalar deleting destructor `0x004a68a0`, and shared name/descriptor slot `0x004a6a70`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6330` | `DSError` | Raw constructor-shaped bytes; IDA does not model a function at this address. |
| `0x004a6360` | `FormatErrorMessage` | IDA-confirmed `0x7b`-byte function that formats DirectSound error text or a raw code fallback. |

## Ownership Notes

Use the formatter as the confirmed migration anchor. Do not move this class into `audio/SoundManager.cpp` solely because DirectSound callers use it.

- Live IDA reports no function record at `0x004a6330`, no xrefs to that raw start, and no little-endian pointer-byte matches for `30 63 4a 00`.
- Direct disassembly covers `0x004a6330-0x004a6354`: the raw constructor calls shared base setup `sub_4F4A80` at `0x004a633a`, stores the caller HRESULT/status argument at `this+0x04` at `0x004a6342`, installs `??_7DSError@@6B@` at `0x004a6347`, and returns with `retn 4`.
- The bytes after the raw constructor are `0xcc` padding through `0x004a6360`, where IDA starts `sub_4A6360`.
- Live IDA reports `sub_4A6360` as a real function at `0x004a6360-0x004a63db`, referenced from vtable slot `0x006193b0`.
- Formatter disassembly calls `dword_69BE6C` with `FormatMessageW`-shaped arguments: flag `0x1000`, stored code from `this+0x04`, language `0x400`, a 512-wide-character stack buffer, and null arguments. If text is returned it formats `DirectSoundError: %s`; otherwise it falls back to `DirectSoundError: 0x%p`.
- 2026-06-19 B013 rejects the stale generated `char *` formatter signature for final source. The formatter participates in the Error hierarchy's wide-buffer message virtual and should be modeled as `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` or the project-wide equivalent once the hierarchy spelling is standardized.
- Live vtable data confirms RTTI at `0x006193a0`, destructor slot `0x006193a4 -> sub_4A68A0`, shared base slot `0x006193a8 -> sub_4F4B10`, no-op slot `0x006193ac -> nullsub_18`, formatter slot `0x006193b0 -> sub_4A6360`, and name/descriptor slot `0x006193b4 -> sub_4A6A70`.
- The constructor vtable-store xref is `0x004a6347 -> 0x006193a4`; shared status-code destructor `sub_4A68A0` is also used by `Win32Error`, `DIError`, `DDError`, and `WSAError` vtables, matching the stored-code layout family.
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms `0x004a6330` as `Not a function`, `sub_4A6360` size `0x7b`, shared status-code destructor `sub_4A68A0` size `0x3e`, and shared name helper `sub_4A6A70` size `0x6`.
- Current xrefs still show no references to the raw constructor start `0x004a6330`; the formatter remains vtable-data referenced at `0x006193b0`, the raw constructor's vtable store remains `0x004a6347 -> 0x006193a4`, and `sub_4A68A0` has exactly the five status-wrapper destructor-slot xrefs at `0x0061935c`, `0x00619374`, `0x0061938c`, `0x006193a4`, and `0x006193ec`.
- `analyze_component` over `0x004a6360`, `0x004a68a0`, and `0x004a6a70` reports stable formatter/destructor/name-helper sizes and no internal call-graph edge, matching the vtable-dispatched wrapper model. `make_signature_for_range(0x004a6330,0x004a63db)` returns a unique wildcarded signature for the raw constructor plus formatter span.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but leave C++ blank. The formatter and vtable/layout evidence are strong; the constructor start and final declaration spelling are not ready for final C++.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page records DirectSound responsibility, shared error-module ownership, stored-code layout, raw constructor instructions, formatter range/behavior, vtable slots, constructor-store xref, status-wrapper destructor fanout, unique raw-constructor/formatter signature, and no-code autogen handling. Completion remains capped because the constructor is not split as an IDA-modeled function page and final field/member names are unresolved. |
| Confidence `88` | The formatter, vtable, layout family, string evidence, signature, and source owner are live-IDA supported. Confidence is not higher because `0x004a6330` remains constructor-shaped raw code without an IDA function record or caller/xref confirmation. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619340-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md)

## Changes

- 2026-06-05:
  - Before: scored `72/82`, with only a high-level raw-constructor caveat and stale external-source wording.
  - After: scored `82/86`, removed stale source references, and kept reconstruction C++ blank.
  - Why: live IDA evidence now records the raw constructor bytes, lack of constructor function/xrefs/pointer matches, `sub_4A6360` range and vtable xref, exact vtable slot targets, `0x004a6347` constructor vtable-store xref, formatter strings, and `FormatMessageW`-shaped call arguments. The score remains below final-source quality because the constructor is still not an IDA-modeled function and final member names are unresolved.
- 2026-06-02:
  - Before: scored `64/74`, reconstructability and parent blank.
  - After: scored `72/82`, marked reconstructable, and attached to [UID:0000J5][Error](by-file/Error.md) with C++ blank.
  - Why: existing vtable/layout/error-wrapper evidence strongly supports shared `util/Error.cpp` ownership and DirectSound formatter behavior, while the constructor start remains a raw projected boundary.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/74`.
  - Summary/evidence: DirectSound formatter responsibility, shared error-module placement, confirmed formatter range, and raw constructor caveat are documented; confidence remains limited until the constructor boundary is reconciled.
- 2026-06-15 A002 Goal 2 by-class refresh:
  - Changed to: scores `85/88`, with no owner/emitter changes.
  - Summary/evidence: live IDA reconfirmed the raw constructor remains non-modeled/no-xref, the formatter and shared destructor/name-helper sizes, vtable-only formatter anchor, raw constructor vtable store, five-class status-wrapper destructor fanout, component shape, and unique raw constructor plus formatter signature. C++ remains blank because constructor reachability and final declaration/member names are not source-quality.
- 2026-06-19 B013 signature sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: B013 keeps the raw constructor no-route policy and rejects generated `char *` formatter output; final source should use the Error hierarchy's wide-buffer message virtual for this formatter.
