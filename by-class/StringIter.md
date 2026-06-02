*** UID:0000E7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StringIter

## Summary

`StringIter` is an `LObject`-derived iterator over wide-character string data. It stores a source data pointer, length, and current position, and returns the next character or `0` when exhausted.

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`
- Confidence: strong for utility-string ownership, medium-high for final standalone-vs-local class split.

## Methods

| Range | Role |
| --- | --- |
| `0x00584d80-0x00584db1` | constructor from data pointer and length, starts at position 0. |
| `0x00584dc0-0x00584df0` | raw constructor body with explicit start position; IDA currently does not promote it as a function, but raw bytes show a complete body. |
| `0x00584df0-0x00584dfb` | destructor body. |
| `0x00584e00-0x00584e28` | raw bounded peek helper, returning zero past end. |
| `0x00584e30-0x00584e3d` | raw position-advance helper. |
| `0x00584e40-0x00584e59` | `GetNextChar`. |
| `0x00584e60-0x00584e9e` | scalar deleting destructor. |

## Evidence

- Generated source and metadata agree on fields: `m_data`, `m_length`, and `m_position`.
- `GetNextChar` has caller fan-in from text parsing/render helper functions around `0x004ba8b0`, `0x004ba9a0`, `0x004bab70`, and `0x005948a0`.
- The class installs its own vtable and uses `LObject` base construction/destruction.
- [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md) records the full promoted/raw helper inventory, the `0x00584e9e-0x00584ea0` `0xcc` padding, and the 16-byte layout: base/vtable, text pointer, length, and current position.
- Generated memory coverage assigns the exact memory range to [UID:0000OB][StringUtil](by-file/StringUtil.md), matching the file page's description of `StringIter` as shared client string infrastructure.

## Generated Data Caveats

`0x00584dc0`, `0x00584e00`, and `0x00584e30` are emitted/expected as useful helper bodies, but IDA currently promotes only the constructor at `0x00584d80`, destructor at `0x00584df0`, `GetNextChar` at `0x00584e40`, and scalar deleting destructor at `0x00584e60`. Treat the unpromoted starts as raw helper bodies inside the exact StringIter memory range.

## Autogen Status

Attach this class to [UID:0000OB][StringUtil](by-file/StringUtil.md) as reconstructable utility-string metadata. Leave C++ blank: the range is reconstructable, but final source-level API names for the raw constructor/peek/advance helpers and the original file split are not final-source quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now records utility-string ownership, full promoted/raw method inventory, field layout, caller fan-in, exact memory page, generated assignment, raw-start caveat, and no-code autogen handling. Completion remains capped because final API names and standalone-vs-local source organization are unresolved. |
| Confidence `84` | Confidence is strong for class behavior and `StringUtil.cpp` ownership due to the exact memory page, StringUtil file page, generated coverage assignment, and IDA-backed promoted/raw helper evidence. It is not higher because three helper starts remain raw IDA-missed bodies. |

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Memory: [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- Related: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- 2026-06-02:
  - Before: scored `74/70`, reconstructability and parent blank.
  - After: scored `78/84`, marked reconstructable, and attached to [UID:0000OB][StringUtil](by-file/StringUtil.md) with C++ blank.
  - Why: the exact memory page and generated coverage already prove full method inventory, layout, raw-helper caveats, and `StringUtil.cpp` ownership.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `70`.
- Evidence: the page documents iterator role, likely utility placement, fields, method ranges, caller fan-in, and the generated-data caveat for the projected constructor; completion/confidence stay limited because `0x00584dc0` is not an IDA function and final file split remains only medium confidence.
