*** UID:00003L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Vtable anchor: RTTI `0x00619388`, vtable `0x0061938c`
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`DDError` wraps DirectDraw HRESULT-style failures and formats them using the shared `FormatMessageW` path with DirectDraw-specific display text.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a6260` | `DDError` | Initializes base error state and stores the HRESULT. |
| `0x004a6290` | `FormatErrorMessage` | Formats a DirectDraw error string or raw hex code. |

## Ownership Notes

Although callers are render/DirectDraw-heavy, implementation belongs with [UID:0000J5][Error](by-file/Error.md), not in `render/DirectX.cpp`.

2026-05-26 IDA MCP recheck reports `DDError::DDError` at `0x004a6260` as a real `0x24`-byte function, `FormatErrorMessage` at `0x004a6290` as a real `0xa0`-byte function, and the vtable write/xref to `0x0061938c` at `0x004a6277`.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. C++ stays blank because formatter naming and the shared declaration are not final-source quality yet.

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
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
