*** UID:0000BQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct RectBounds;

class RankingUserListPane : public ControlPane
{
public:
    explicit RankingUserListPane(const RectBounds *bounds);
    virtual ~RankingUserListPane();

protected:
    virtual void OnPaint();

    [[CHILDREN]]
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingUserListPane

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Confidence: very strong for class identity, owner/source route, method boundaries, vtables, and paint behavior; remaining uncertainty is exact original helper/member spelling, not the class route or data-source model.

## Class Purpose

`RankingUserListPane` draws the current ranking page selected in `RankingDialog`. It is a private `RankingDialog.cpp` control-pane child, constructed from the dialog constructor at `0x0045875f` with control id `8`. It renders the selected category title/count/date fields, column headers, up to ten rank/name/score rows, and the local player's rank/score footer.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingUserListPane` | `0x0045f340-0x0045f377` | Constructs the `ControlPane` base with control id `8` and installs the three class vtable views. |
| `NonDeletingDestructorBody` | `0x0045f380-0x0045f39f` | Reinstalls the three class vtables and calls base `Pane` teardown helper `0x00544580`; currently has no direct xrefs in IDA. |
| `OnPaint` | `0x0045f3a0-0x0045f945` | Draws ranking title, total count, from/to timestamps, row table, and local-player footer. |
| `FormatWide64_45F950` | `0x0045f950-0x0045f97d` | Adjacent fixed 64-wide-character CRT formatting wrapper; all nine callers are inside `OnPaint`, so it remains tracked as ignored helper code. |
| `AdjustorThunks` | `0x0045f97d-0x0045f993` | Destructor adjustor thunks for the secondary and tertiary vtable views. |
| `ScalarDeletingDestructor` | `0x0045f9a0-0x0045f9f5` | Reinstalls vtables, runs base teardown, and conditionally frees through `0x004f4ac0` when the deleting flags request ownership release. |

## Source-Quality Decisions

- 2026-06-18 B005 source-quality pass keeps the canonical owner/emitter as [UID:0000MZ][RankingDialog](by-file/RankingDialog.md). The class is not a `RankingCategoryRecord`/collection object and is not a standalone proven source module; it is a private ranking-dialog child control routed through `RankingDialog.cpp`.
- The source-facing constructor is best modeled as `RankingUserListPane(const RectBounds *bounds)` or the project-standard rectangle typedef. The binary forwards the bounds/layout pointer to the `ControlPane` constructor with control id `8`.
- `OnPaint` is the primary source-authored behavior. It is reached through the primary vtable slot, so the lack of direct callers is expected and should not reduce confidence.
- The non-deleting destructor body, scalar deleting destructor, and secondary/tertiary adjustor thunks are compiler/ABI consequences of the class declaration. Source should declare the virtual destructor and let the compiler regenerate equivalent glue.
- `0x0045f950-0x0045f97d` is a fixed `0x40`-wide-character CRT formatting wrapper used only by this paint body. Final source should use `swprintf_s` or a small local safe-format helper rather than hand-authoring the raw wrapper as a product method.
- Generic draw helpers such as `0x004bacd0`, `0x004b9680`, `0x004b9690`, `0x004b9660`, `0x004b9600`, `0x004b98f0`, and `0x004b7c30` remain common GrafPort/control dependencies, not ranking-owned methods.
- The footer rank and score are `RankingCategoryRecord` fields at `+0x268` and `+0x2ac`; the footer name is read from global local-player name storage through `0x005a2dc0` / `word_69BEE0`, not from the record's `+0x26c` tail.
- The row accessor is [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md). This pane is the sole release caller, but it remains a consumer rather than the method owner: the receiver owns the `std::vector<RankingUserEntry>` member and the method routes through `RankingCategoryRecord`.
- The timestamp values are ordinary standard `tm` objects returned by value from `RankingCategoryRecord::GetStartTime()` and `GetEndTime()`. The compiler's hidden result pointers and the paint body's stack locals are ABI mechanics, not explicit source parameters or a custom `RankingDateTimeParts` API.
- The ranking protocol stores month and full-year values directly in `tm_mon` and `tm_year`; this paint path prints them directly and performs no C-runtime normalization. Preserve that behavior even though it differs from conventional `tm` interpretation.

## OnPaint Source Shape

`OnPaint` initializes a local EPF/tile context and draw region, loads the ranking board/background resource through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744` and `off_60DB5C`, draws the tiled background with `0x004ba6b0(..., off_60DB78)`, and releases the temporary region/object.

The paint body then obtains the selected record from `g_pRankingDialog + 0x26c` through `0x0045ce70`, best named `RankingCategoryCollection::GetSelectedRecord()`. If no record is selected, the method exits after drawing the background. Otherwise it sets text/outline colors, draws the category title at `(30,24)`, and formats `record +0x254` as `"Total : %d"` at `(380,24)`. At `0x0045f4fe` it calls `RankingCategoryRecord::GetStartTime()` and receives the complete 36-byte standard `tm` in the local at `ebp-0xb4`; at `0x0045f56f` it calls `GetEndTime()` into the paired 36-byte local. The `From` and `To` lines at `(30,50)` and `(210,50)` print `tm_mon`, `tm_mday`, `tm_year`, `tm_hour`, `tm_min`, and `tm_sec` directly. They do not inspect `tm_wday`, `tm_yday`, or `tm_isdst`, and they do not subtract one from the month or 1900 from the year.

The row table draws the `Rank`, `Name`, and `Score` headers at x positions `50`, `150`, and `390`, y `78`. The sole call to [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) is at `0x0045f637`. The loop initializes `i = 0`, continues while `i < 10`, and increments by one, so only indexes `0..9` are passed. Each returned pointer is null-checked before the pane draws `row->rank` (`+0x04`), `row->name` (`+0x08`), and `row->score` (`+0x48`) at y values starting at `100` and advancing by `30`.

UID0002K6 itself uses a signed upper-bound-only count check and deliberately has no negative-index guard. This caller contract explains why the release UI is safe without changing that exact binary behavior; the reconstructed accessor must not add an unevidenced lower-bound condition.

After the rows, the method draws a three-pixel separator line at y `384..386` from x `30` to `490`. If `record->localPlayerRank` (`+0x268`) is positive, it draws the footer rank, constructs/copies the global local-player name through `0x005a2dc0` / `word_69BEE0`, destroys the temporary wide-string wrapper, and draws `record->localPlayerScore` (`+0x2ac`).

Future exact by-memory method pages may carry a full source-shaped `RankingUserListPane::OnPaint()` body. This class page intentionally emits only the declaration and `[[CHILDREN]]` marker so method bodies attach through exact by-memory children.

## Local-Player Rank Reset And Paint Contract

Record offset `+0x268` is `int m_localPlayerRank`, not a selected-user index. [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) writes the unavailable sentinel `-1` whenever `RankingDialog` begins a selected-category page request. The initial-page and row-page response parsers repeat that logical reset before optionally loading replacement local-player metadata.

`RankingUserListPane::OnPaint` tests the field as signed and draws the local-player footer only when `m_localPlayerRank > 0`. Therefore both `-1` and `0` suppress the footer, while a positive rank draws the rank together with the global local-player name and record `m_localPlayerScore` at `+0x2ac`. The reserved `+0x26c..+0x2ab` tail remains copied/parser-managed support storage; it is not the name source used by paint.

The reset also calls `m_userEntries.clear()` at source level. It preserves vector capacity and does not modify `m_localPlayerScore` or the reserved footer tail, so the rank sentinel is the explicit visibility guard that prevents stale footer presentation during page reload. Historical selected-user-index wording is retained only as a disproved interpretation: selection belongs to `RankingCategoryCollection::m_selectedCategoryId`, not this record field.

## IDA Evidence

- Live IDA recheck on 2026-06-04 used `NexusTK.exe` at image base `0x00400000` with MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Constructor `0x0045f340-0x0045f377` has one code caller at `0x0045875f` in the `RankingDialog` constructor; it calls `0x004949e0`, then writes vtables `0x00610cd0`, `0x00610d38`, and `0x00610d68`.
- `OnPaint` initializes the EPF tile context (`0x00457a60`), loads the layout resource through `0x004d02f0([UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / dword_67A744, off_60DB5C, ...)`, marks `this+0x70`, paints the background with `0x004ba6b0`, and reads the selected ranking category from `g_pRankingDialog` / `dword_67A7E4 + 0x26c` through `0x0045ce70`.
- The paint body draws the category title, `"Total : %d"`, `"From : %02d/%02d/%04d %02d:%02d:%02d"`, `"To : %02d/%02d/%04d %02d:%02d:%02d"`, and the `Rank`/`Name`/`Score` headers, then loops over ten [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) row lookups from the sole callsite `0x0045f637`.
- Calls at `0x0045f4fe` and `0x0045f56f` consume [UID:0002K3][0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts](by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md) and [UID:0002K4][0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts](by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md) as by-value standard `tm` getters. The two 36-byte locals and hidden result addresses explain the binary call shape without requiring authored output parameters.
- Row rendering formats rank from `row+4`, name from `row+8`, score from `row+72`, draws separator lines with `0x004b9600`/`0x004b98f0`, and draws the local-player footer when category field `+0x268` is positive. The footer name is constructed from `word_69BEE0` through `0x005a2dc0`; the record's copied `+0x26c` tail is not the proven displayed-name source.
- `0x0045f950-0x0045f97d` wraps `__stdio_common_vswprintf_s` with a fixed `0x40` character buffer count and has exactly nine callers, all from `OnPaint`.
- The destructor thunks at `0x0045f97d` and `0x0045f988` subtract `0xa0` and `0xa4` respectively before tail-calling scalar destructor `0x0045f9a0`.

## Evidence Notes

- `RankingDialog` creates this pane from the constructor path at `0x0045875f`; the pane's own constructor passes control id `8` to `ControlPane`.
- IDA confirms `0x0045f950` / `FormatWide64_45F950` is only a fixed `0x40`-wide-character CRT formatting wrapper used by `OnPaint`; it is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), not as ranking-owned handwritten logic.
- `LineTo` helper `0x004b98f0` is a generic drawing helper, not ranking-specific owner code.
- Row labels are now supported by `RankingCategoryRecord` parser/append/layout evidence: `RankingUserEntry` is best modeled as `{ categoryId, rank, wchar_t name[32], score }`, and the record footer name comes from global local-player storage rather than the record tail.
- IDA confirms primary, secondary, and tertiary vtables at `0x00610cd0`, `0x00610d38`, and `0x00610d68`.
- The tertiary table ends after `+0x04`. The following UTF-16 `Total`, `From`, and `To` format strings are label data, not additional virtual slots.
- 2026-08-04 B007 read-only MCP session `9081c1f3-bc94-49a3-a909-a60eafeb0a99` reconfirmed `OnPaint` at `[0x0045f3a0,0x0045f945)`, UID0002K6's sole call at `0x0045f637`, the exact `0..9` loop and null check, and row reads at `+0x04/+0x08/+0x48`. UID0002K6 has no other caller or callee route.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-08-04 B005 UID0002KA local-rank consumer callback:
  - Preserved metadata, declaration-only class emission, row rendering, standard-`tm` consumer evidence, and unrelated paint behavior.
  - Added `m_localPlayerRank = -1` reset semantics, parser replacement flow, the exact signed-positive paint condition, the preserved score/footer/vector-capacity state, and the distinction from collection selection.
  - Retained the old selected-user interpretation only as disproved history.

- 2026-08-04 B007 UID0002K6 caller-contract callback:
  - Preserved metadata at `87/90`, owner/emitter UID0000MZ, declaration-only formal CPP, blank formal H, and all unrelated paint/render/footer conclusions.
  - Added the corrected UID0002K6 endpoint/link, sole callsite `0x0045f637`, exact `i = 0; i < 10; ++i` contract, null check, and row-field reads at `+0x04/+0x08/+0x48`.
  - Documented why the caller's nonnegative indexes do not authorize adding a lower-bound check to the signed upper-bound-only accessor and why caller status does not transfer method ownership from `RankingCategoryRecord`.

- 2026-08-02 B009 UID0002K3 standard-`tm` consumer sync:
  - Preserved class metadata at `87/90`, owner/emitter UID0000MZ, declaration-only formal CPP with `[[CHILDREN]]`, blank formal H, and every unrelated row/footer/rendering fact.
  - Reconciled `OnPaint` with the exact getter calls at `0x0045f4fe` and `0x0045f56f`, paired 36-byte `tm` locals, direct first-six-field formatting, unused trailing fields, and no month/year normalization.
  - Historicalized the former custom `RankingDateTimeParts` interpretation without deleting it as prior evidence; the current source-facing API is `tm GetStartTime() const` / `tm GetEndTime() const`.

- 2026-06-18 B005 source-quality execution:
  - Before: `84/88`, with class identity and paint flow documented but the final C++ block empty and row/footer source names still carrying an unresolved `RankingCategoryRecord` layout caveat.
  - Changed to: `87/90`, preserving [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) as canonical owner/emitter and adding declaration-only first-draft C++ for the private control-pane class.
  - Evidence: B005 revalidated constructor caller `0x0045875f`, control id `8`, vtables `0x00610cd0`/`0x00610d38`/`0x00610d68`, vtable-only `OnPaint`, exact `FormatWide64_45F950`/adjustor-thunk boundaries, row consumers `+0x04/+0x08/+0x48`, record footer rank/score `+0x268/+0x2ac`, and footer-name source through `0x005a2dc0` / `word_69BEE0`.
  - Source-quality result: class declaration C++ is safe; the full paint body should live on a future exact by-memory child or support section, while the CRT wrapper and destructor thunks stay ignored/generated.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: ranking-list paint evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the reference to ranking pane EPF layout loading.
- 2026-06-04: Grading changed from `72/78` to `84/88`; marked reconstructable and attached to parent [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Before: page identified the class and broad paint path but still carried stale recovered-source wording, inclusive method endpoints, no parent attachment, and only aggregate evidence for the score.
  - After: live IDA evidence records exact exclusive method ranges, constructor caller, vtable stores/xrefs, `OnPaint` resource/category/row/footer flow, formatter caller isolation, and destructor thunk behavior.
  - Reasoning: the child page now has direct current-disassembly support for identity and behavior, while the parent `RankingDialog` file is already `82/86`; remaining row-layout naming uncertainty keeps the page below the final C++ threshold.
- 2026-05-30: Grading changed from `0/0` to `72/78`.
  - Before: page documented class purpose, known methods, vtables, and paint/data caveats but remained unevaluated.
  - After: score reflects documented constructor, destructor-shaped body, paint path, destructor thunks, scalar deleting destructor, vtables, and formatter/render-helper ownership caveats.
  - Evidence: ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) records the user-list range, vtable family, and adjacent ignored `FormatWide64_45F950` helper; remaining confidence was limited by helper-name/layout pollution.
