*** UID:00003L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// DDError class-level source is covered by [UID:0000J5][Error](by-file/Error.md) and exact method children, including [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md); this class page emits no standalone partial declaration until the hierarchy-wide Error.h declaration and DDError formatter child are finalized.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DDError : public Error
{
public:
    explicit DDError(HRESULT result);
    virtual int FormatErrorMessage(wchar_t *buffer,
                                   size_t bufferChars) const;

private:
    HRESULT m_errorCode;
};

typedef char DDErrorSizeMustBe8[
    sizeof(DDError) == 0x8 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DDError

## Status

- Confidence: strong for class responsibility and shared error-module placement.
- Historical generated source lead: `class_DDError.cpp` (context only; current score relies on IDA-backed documentation).
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Exact constructor: [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md)
- Vtable anchor: RTTI `0x00619388`, vtable `0x0061938c`
- Evidence basis: existing IDA-backed by-memory constructor page, the shared `Error.cpp` file page, the error vtable/layout docs, earlier IDA MCP checks, and B003's 2026-06-27 MCP session `80de0a67` source-quality implementation for [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md).

## Responsibility

`DDError` wraps DirectDraw HRESULT-style failures and formats them using the shared `FormatMessageW` path with DirectDraw-specific display text.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md) | `DDError::DDError(HRESULT result)` | Exact source-ready constructor page; B003 MCP session `80de0a67` confirms the `0x24` / 36-byte body (Verified with int_convert.py), `LObject` base setup, supplied DirectDraw `HRESULT result` storage as `HRESULT m_errorCode` at `+0x04`, `DDError` vtable store at `0x004a6277`, single base-setup callee, one explicit argument with `retn 4`, 14 DirectDraw/rendering throw-site callers, and clean padding before the formatter. The exact child now emits formal constructor C++. |
| `0x004a6290-0x004a6330` | format message override | Vtable-only formatter slot; current Hex-Rays shows a DirectDraw message lookup into a stack buffer and a formatted-output fallback that prints the stored HRESULT/status value. Still aggregate-only inside [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md). |

## Ownership Notes

Although callers are render/DirectDraw-heavy, implementation belongs with [UID:0000J5][Error](by-file/Error.md), not in `render/DirectX.cpp`.

2026-05-26 IDA MCP recheck reports `DDError::DDError` at `0x004a6260` as a real `0x24`-byte function, `FormatErrorMessage` at `0x004a6290` as a real `0xa0`-byte function, and the vtable write/xref to `0x0061938c` at `0x004a6277`.

[UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md) maps the `DDError` table at `0x0061938c`, with the shared status-code scalar deleting destructor `0x004a68a0`, formatter slot `0x004a6290`, and common name helper `0x004a6a70`. [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md) places `DDError` in the stored-status-code layout family with the HRESULT/status value at `+0x04`.

2026-06-14 C001 IDA MCP recheck on `a001_goal2_class_batch` confirms the current IDA database is ready and agrees with the documented surface: constructor `0x004a6260` size `0x24`, formatter `0x004a6290` size `0xa0`, status-code scalar deleting destructor `0x004a68a0`, and common name helper `0x004a6a70`. Xrefs still show 14 constructor callers from DirectDraw/rendering code, vtable store to `0x0061938c` at `0x004a6277`, formatter slot xref from `0x00619398`, destructor slot refs from the shared error vtables, and common name-helper refs from the broader error hierarchy. `get_bytes` confirms padding between constructor end `0x004a6284` and formatter start `0x004a6290`.

2026-06-19 B013 keeps `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` as the current best source-facing name/signature for this formatter slot once the hierarchy-wide virtual spelling is standardized. The method remains aggregate-only until an exact child page is created.

2026-06-27 B003 source-quality implementation accepts [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md) as source-ready and emitting. The constructor source is `DDError::DDError(HRESULT result) : m_errorCode(result) {}`. This resolves the constructor-local field/type/source-shape blocker only: raw `this[1]`, `a2`, `sub_4A6260`, `DWORD`, `long`, `m_hresult`, `m_status`, and caller-owned placement are rejected for this constructor, but the class-level formatter and hierarchy declaration remain broader work.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable error-hierarchy metadata. The formal H channel now supplies the complete declaration required by GrafPort's `throw new DDError(result)` path; exact method bodies remain on their Error-owned children.

## 2026-08-22 Declaration Closure

- The source declaration is `DDError : public Error`, with explicit `HRESULT` constructor, virtual wide-buffer formatter, and one `HRESULT m_errorCode` field at `+0x04`.
- The size assertion fixes the established `0x08` layout without inventing padding or duplicating constructor/formatter definitions.
- Exact original formatter parameter names remain inferred; the ABI, virtual role, field type, class owner, and header route are closed.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page records shared `Error.cpp` ownership, exact source-ready constructor child evidence and formal child C++ status, formatter behavior and vtable slot, status-code layout placement, caller-versus-owner boundary, parent attachment, rejected constructor alternatives, and remaining final source blockers. Remaining completion work is splitting `0x004a6290-0x004a6330` to an exact method page and settling the original header/declaration names. |
| Confidence `89` | Confidence is strong for class responsibility, source placement, constructor behavior/source shape, formatter semantics, vtable role, and layout family because the existing docs, 2026-06-14 IDA lookup/xref/decompile/padding checks, and B003's 2026-06-27 MCP session `80de0a67` evidence agree. It remains below final-audit range because the formatter still lacks an exact by-memory child and the final declaration shape is not source-ready. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)

## Changes

- 2026-06-27 B003 DDError constructor source-ready sync:
  - Changed score `86/88 -> 88/89`; owner/emitter remain [UID:0000J5][Error](by-file/Error.md), and class-level C++ remains blank.
  - Summary/evidence: accepted B003 implementation for [UID:0002HK][0x004a6260-0x004a6284.DDErrorConstructor](by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md) synchronizes this class with MCP session `80de0a67`: exact `0x24` / 36-byte constructor, `LObject` base setup, one explicit `HRESULT result` argument with `retn 4`, `HRESULT m_errorCode` at `+0x04`, DDError vtable store at `0x004a6277`, 14 DirectDraw/render caller refs, clean padding before `0x004a6290`, formal child C++, and rejection of raw/decompiler names, caller ownership, and formatter/range merge alternatives. The class-level formatter/declaration work still blocks broad class C++.

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
- 2026-06-14 C001 Goal 2 refresh:
  - Before: score was `80/86`; formatter behavior was described but not backed by a current decompiler/xref pass on this page.
  - After: score is `86/88`; owner/emitter routing remains [UID:0000J5][Error](by-file/Error.md), and C++ remains blank.
  - Summary/evidence: current IDA MCP confirms constructor, formatter, vtable, destructor-slot, common-name-helper, caller, and padding evidence. The formatter remains aggregate-only, so this is a documentation-confidence raise, not a final-source entry.
- 2026-06-19 B013 formatter policy sync:
  - Score unchanged at `86/88`.
  - Summary/evidence: B013 keeps this formatter under the wide-buffer Error hierarchy message virtual and leaves C++ blank until the exact formatter child and final declaration spelling are created.
