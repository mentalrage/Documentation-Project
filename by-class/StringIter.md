*** UID:0000E7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../util/StringUtil.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StringIter : public LObject
{
public:
    StringIter(const wchar_t *data, int length);
    StringIter(const wchar_t *data, int length, int position);
    virtual ~StringIter();

    wchar_t PeekCharAtOffset(int offset) const;
    void Advance(int count);
    wchar_t GetNextChar();

private:
    const wchar_t *m_data;
    int m_length;
    int m_position;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StringIter

## UID0000IF Shared-Guard Header Fragment - 2026-08-24

- This class is StringUtil H emitter position `20`. Its formal H is only the unchanged `StringIter : public LObject` declaration; UID0000D9 position `0` already owns the sole guard and complete `LObject.h` include.
- Formal CPP remains the existing StringUtil header include plus namespace-scope child expansion, preserving every retained constructor/destructor/peek/advance/next-character method route and compiler-only deleting-destructor disposition.
- Removing the duplicate guard pair does not change the 16-byte layout, API, owner UID0000OB, score `88/89`, raw-helper liveness decisions, or source placement. Generated proof requires this class once after SimpleUStringVector and before the external empty-string declaration.

## Summary

`StringIter` is an `LObject`-derived iterator over caller-owned UTF-16 string data. It stores `m_data`, `m_length`, and `m_position`, returns the next character or `0` when exhausted, and exposes retained out-of-line helpers for relative peeking and signed position advance.

## Likely Original Placement

- Source: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Proposed path: `util/StringUtil.cpp`
- Confidence: strong for utility-string ownership, live text-helper use, exact 16-byte layout, retained helper bodies, and compiler-generated deleting-destructor policy; medium-high for final standalone-vs-local class split and exact original helper spellings.

## Methods

| Range | Role |
| --- | --- |
| `0x00584d80-0x00584db1` | constructor from data pointer and length, starts at position 0. |
| `0x00584db1-0x00584dc0` | fifteen bytes of `0xcc` padding. |
| `0x00584dc0-0x00584df0` | raw constructor body with explicit start position; IDA currently does not promote it as a function, but raw bytes show a complete retained constructor overload. |
| `0x00584df0-0x00584dfb` | destructor body. |
| `0x00584dfb-0x00584e00` | five bytes of `0xcc` padding. |
| `0x00584e00-0x00584e23` | raw `PeekCharAtOffset(int offset) const` helper, returning zero for negative relative indexes and indexes at/after length. |
| `0x00584e23-0x00584e30` | thirteen bytes of `0xcc` padding; the earlier `0x00584e00-0x00584e28` helper row over-included five padding bytes. |
| `0x00584e30-0x00584e3d` | raw position-advance helper. |
| `0x00584e3d-0x00584e40` | three bytes of `0xcc` padding. |
| `0x00584e40-0x00584e59` | `GetNextChar`. |
| `0x00584e59-0x00584e60` | seven bytes of `0xcc` padding. |
| `0x00584e60-0x00584e9e` | scalar deleting destructor; compiler-generated from the virtual destructor and vtable, not handwritten source. |

## Evidence

- Historical generated source and metadata agree with the IDA-derived layout names `m_data`, `m_length`, and `m_position`; current scoring relies on IDA/raw-PE evidence and linked project docs rather than generated output alone.
- The class layout is 16 bytes: `LObject` base/vtable at `+0x00`, `const wchar_t *m_data` at `+0x04`, `int m_length` at `+0x08`, and `int m_position` at `+0x0c`.
- `GetNextChar` has caller fan-in from text parsing/render helper functions around `0x004ba8b0`, `0x004ba9a0`, `0x004bab70`, and `0x005948a0`.
- The class installs its own vtable and uses `LObject` base construction/destruction.
- [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md) records the full promoted/raw helper inventory, the `0x00584e9e-0x00584ea0` `0xcc` padding, and the 16-byte layout: base/vtable, text pointer, length, and current position.
- Current project documentation assigns the exact memory range to [UID:0000OB][StringUtil](by-file/StringUtil.md), matching the file page's description of `StringIter` as shared client string infrastructure.
- 2026-06-14 A001 IDA MCP refresh on database `b001_0003gy` reconfirmed promoted starts at `0x00584d80` size `0x31`, `0x00584df0` size `0xb`, `0x00584e40` size `0x19`, and `0x00584e60` size `0x3e`; raw helper starts `0x00584dc0`, `0x00584e00`, and `0x00584e30` remain real code bytes but not IDA function objects.
- 2026-06-14 xrefs reconfirm constructor callers at `0x004ba904`, `0x004ba9e5`, `0x004bac55`, and `0x005948de`; `GetNextChar` has twelve direct code refs from the same text parsing/render helpers; the scalar deleting destructor is referenced from the StringIter read-only data slot at `0x0062d5ec`.
- B003 raw route review confirms `0x00584dc0`, `0x00584e00`, and `0x00584e30` have no direct rel32 calls/jumps and no VA/RVA start-pointer hits. They are retained no-xref out-of-line class API bodies, not padding.
- B003 raw route review confirms `0x00584df0` has normal destructor calls at `0x004ba975`, `0x004baa4b`, `0x004baca5`, and `0x0059497a`, plus compiler/EH jmp refs at `0x005ff3c7`, `0x005ff3ea`, `0x005ff40d`, and `0x0060987a`.
- The scalar deleting destructor at `0x00584e60` has no direct code refs and one vtable data ref at `0x0062d5ec`; source should model only `virtual ~StringIter()`.

## Generated Data Caveats

`0x00584dc0`, `0x00584e00`, and `0x00584e30` are emitted/expected as useful helper bodies, but IDA currently promotes only the constructor at `0x00584d80`, destructor at `0x00584df0`, `GetNextChar` at `0x00584e40`, and scalar deleting destructor at `0x00584e60`. Treat the unpromoted starts as retained no-xref out-of-line StringIter API methods inside the exact memory range.

## Autogen Status

Attach this class to [UID:0000OB][StringUtil](by-file/StringUtil.md) as reconstructable utility-string metadata. The by-memory [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md) target should emit method definitions; this class page should carry the final class/API inventory and may emit the class declaration only.

Do not model the scalar deleting destructor as a handwritten source member. It is compiler-generated from `StringIter::~StringIter()` and the vtable.

## Ownership Exclusions

- Keep [UID:0000OB][StringUtil](by-file/StringUtil.md) as the file/emitter route. Current emission remains `NexusTK/util/StringUtil.cpp`.
- Reject [UID:0000OA][StringBase](by-file/StringBase.md) as direct owner: `StringIter` starts after padding, has its own RTTI/vtable, and does not use ref-counted buffer headers, sentinels, pools, or copy-on-write state.
- Reject [UID:0000D9][SimpleUString](by-class/SimpleUString.md) as direct owner: this class iterates caller-owned UTF-16 data and explicit lengths, and is not the 24-byte SSO object or pointer-backed string-handle storage.
- Reject [UID:0000KV][LObject](by-file/LObject.md) as direct owner: `LObject` is only the base class dependency.
- Reject GrafPort and TextEditPane as direct owners: they consume the utility iterator in text measurement/drawing helpers.
- A standalone `StringIter.cpp` remains source-plausible but unproven and not actionable without additional source/project evidence.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page now has the final class/API inventory, class declaration C++, exact method/padding map, corrected peek endpoint, final field names, live route counts, retained no-xref helper policy, vtable-only scalar-deleting-destructor policy, and direct-owner exclusions. Method definitions emit in [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md), not this class page. |
| Confidence `89` | Confidence is very strong for behavior, layout, `StringUtil.cpp` route, live callers, and scalar destructor policy. It remains below 90 because exact original spellings for `PeekCharAtOffset` and `Advance`, plus a possible standalone `StringIter.cpp` split, remain inferred rather than source/PDB-proven. |

## Cross-References

- File: [UID:0000OB][StringUtil](by-file/StringUtil.md)
- Memory: [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md)
- Related: [UID:0000D9][SimpleUString](by-class/SimpleUString.md), [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)

## Changes

- 2026-06-02:
  - Before: scored `74/70`, reconstructability and parent blank.
  - After: scored `78/84`, marked reconstructable, and attached to [UID:0000OB][StringUtil](by-file/StringUtil.md) with C++ blank.
  - Why: the exact memory page and generated coverage already prove full method inventory, layout, raw-helper caveats, and `StringUtil.cpp` ownership.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `78/84`, with stale generated-evidence wording and the exact memory page also below threshold.
  - After: `85/86`, preserving [UID:0000OB][StringUtil](by-file/StringUtil.md) ownership/emission and blank C++ under then-existing gate wording, which is superseded by the 2026-06-19 B003 implementation.
  - Summary/evidence: live IDA MCP reconfirmed promoted/raw helper boundaries, constructor/GetNextChar caller fan-in, scalar-deleting-destructor read-only-data ref, and the refreshed exact memory child [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md).
- 2026-06-19 B003 accepted source-quality implementation:
  - Before: `85/86`, blank C++, stale gate wording, and over-wide peek helper endpoint inherited from the exact memory page.
  - After: `88/89`, with class declaration C++, final field/API inventory, corrected `0x00584e00-0x00584e23` peek body and `0x00584e23-0x00584e30` padding, retained no-xref helper policy, and scalar-deleting-destructor no-code proof.
  - Summary/evidence: B003 route review recorded no rel32 or VA/RVA hits for `0x00584dc0`, `0x00584e00`, and `0x00584e30`; live routes for the two-argument constructor, destructor, and `GetNextChar`; one vtable-only scalar-deleting-destructor ref at `0x0062d5ec`; and direct owner exclusions for `StringBase`, `SimpleUString`, `LObject`, GrafPort, and TextEditPane.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `70`.
- Evidence: the page documents iterator role, likely utility placement, fields, method ranges, caller fan-in, and the generated-data caveat for the projected constructor; completion/confidence stay limited because `0x00584dc0` is not an IDA function and final file split remains only medium confidence.
