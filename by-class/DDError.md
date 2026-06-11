*** UID:00003L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DDError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Current Wave3 file: `class_DDError.cpp`
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact constructor: [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md)
- Vtable anchor: RTTI `0x00619388`, vtable `0x0061938c`
- Evidence basis: existing IDA-backed by-memory constructor page, the shared `Error.cpp` file page, the error vtable/layout docs, and earlier IDA MCP checks.

## Responsibility

`DDError` wraps DirectDraw HRESULT-style failures and formats them using the shared `FormatMessageW` path with DirectDraw-specific display text.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md) | `DDError` | Exact constructor page; live IDA confirms the `0x24`-byte body, base setup, supplied HRESULT/status storage at `+0x04`, `DDError` vtable store, single base-setup callee, 14 DirectDraw/rendering callers, and clean padding. |
| `0x004a6290` | `FormatErrorMessage` | Formats a DirectDraw error string or raw hex code; still aggregate-only inside [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md). |

## Ownership Notes

Although callers are render/DirectDraw-heavy, implementation belongs with [UID:0000J5][Error](by-file/Error.md), not in `render/DirectX.cpp`.

2026-05-26 IDA MCP recheck reports `DDError::DDError` at `0x004a6260` as a real `0x24`-byte function, `FormatErrorMessage` at `0x004a6290` as a real `0xa0`-byte function, and the vtable write/xref to `0x0061938c` at `0x004a6277`.

[UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) maps the `DDError` table at `0x0061938c`, with the shared status-code scalar deleting destructor `0x004a68a0`, formatter slot `0x004a6290`, and common name helper `0x004a6a70`. [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) places `DDError` in the stored-status-code layout family with the HRESULT/status value at `+0x04`.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. C++ stays blank because formatter naming and the shared declaration are not final-source quality yet.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `80` | The page now records shared `Error.cpp` ownership, exact constructor child evidence, vtable anchor and slot roles, stored-status-code layout placement, caller-versus-owner boundary, parent attachment, and formatter/declaration blockers. Completion remains capped because `0x004a6290` is still aggregate-only and final source names for the DirectDraw formatter/header declaration are not settled. |
| Confidence `86` | Confidence remains strong for class responsibility, source placement, constructor behavior, vtable role, and layout family. It is not raised because the formatter has not yet been split to an exact page and the final declaration shape remains below final-audit quality. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/86`.
  - Summary/evidence: DirectDraw wrapper responsibility, constructor/formatter addresses, vtable anchor, source placement, and IDA recheck evidence are documented; remaining work is mostly final emitted-source detail.
- 2026-06-02 autogen ownership:
  - Before: reconstructable and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000J5][Error](by-file/Error.md), leaving C++ blank.
  - Summary/evidence: strong DirectDraw wrapper evidence supports shared `Error.cpp` ownership while preserving render code as caller-only.
- 2026-06-07 A004 exact-constructor sync:
  - Before: score was `74/86`, and the page still summarized `0x004a6260` without linking the exact constructor child or the newer layout/vtable evidence.
  - After: score is `80/86`, with exact constructor, vtable slot, layout-family, caller/owner, parent-attachment, and score-rationale sections updated.
  - Summary/evidence: [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md), [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md), [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md), and [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) support the completion raise. Confidence stays unchanged because the formatter child remains unsplit.
