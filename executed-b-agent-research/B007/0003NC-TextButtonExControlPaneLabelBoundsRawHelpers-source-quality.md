** TARGET-REPORT-UID:0003NC **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003NC **
# 0003NC TextButtonExControlPane Label Bounds Raw Helpers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep UID `0003NC` assigned to [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md), emitted through [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md) and the existing [UID:0000HY][ButtonControlPane](../../../../../by-file/ButtonControlPane.md) source-file route, but repair the half-open range before or during implementation.
- Final disposition: reconstructable source-authored private `TextButtonExControlPane` helper pair. The current owner/emitter route is correct; the source-quality pass finds a concrete endpoint/padding defect and resolves the previous C++ blocker.
- Required action: rename/rerange target from `0x00495aa0-0x00495be2` to `0x00495aa0-0x00495be3`, update internal covered ranges and padding rows, document the raw PE reachability scan, add first-draft C++, update support docs that reference the stale endpoint/path, and leave exact `by-memory/-coverage-report.md` replacement text for supervisor-owned application.
- Confidence: high for behavior, owner, emitter route, field/type/helper interpretations, and range correction; medium-high for exact original helper method spelling because the raw starts remain unreferenced and no original source symbols are present.

## Supporting Research

## Target

- Target UID: `0003NC`
- Target path supplied by supervisor: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md`
- Target path recommended after implementation: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md`
- Source queue/report row: `B007-goal2-text-button-label-bounds-raw-helpers-source-quality-0003NC-20260619`
- Current supervisor classification: source-quality reanalysis for a reconstructable `85/87` raw-helper page.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:87`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000EK`, `EMITTER_UIDS:0000EK`, blank formal C++.
- Recommended scores after implementation: `COMPLETION:88`, `CONFIDENCE:89`, owner/emitter unchanged. Completion rises because the endpoint defect, helper/field names, dependency names, open questions, reachability result, and first-draft C++ become documented. Confidence rises modestly because raw PE evidence validates the behavior and range correction; it remains below final because exact original method names and direct reachability are still not recovered.

## Executive Recommendation

The current semantic ownership is correct: these two raw bodies are `TextButtonExControlPane` label-rectangle helpers, not fitting-room, plain `TextButtonControlPane`, `ImageButtonControlPane`, `TextBoxPane`, GrafPort, RectBounds, or broad aggregate source bodies.

The target's half-open range is not exact. A raw PE/Capstone check against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` shows both `ret imm16` instructions are three bytes:

- first helper ends with `c2 04 00` at `0x00495b4e-0x00495b50`, so the first helper half-open range is `0x00495aa0-0x00495b51`;
- second helper ends with `c2 08 00` at `0x00495be0-0x00495be2`, so the second helper half-open range is `0x00495b60-0x00495be3`;
- the current page's `0x00495b50-0x00495b60` and `0x00495be2-0x00495bf0` padding spans incorrectly include the final zero byte of the preceding `ret imm16`.

The best source-facing helper names are inferred/descriptive:

- `TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect)` for the provider/current-text overload at `0x00495aa0-0x00495b51`;
- `TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect, const wchar_t *text)` for the supplied-text overload at `0x00495b60-0x00495be3`.

The old Wave2/generated owner label `FittingRoomDownloadControlPane` remains rejected as owner pollution. Its `CalculateLabelRect` name for the second body is useful only as a semantic lead; the local class, field, constructor, and address evidence support `TextButtonExControlPane`.

This target is eligible for first-draft C++ under the active gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000EK`, and average score `86`. The no-xref/raw-start fact is not an exact no-code proof. The bodies are source-authored helper methods retained in the object/source unit; leaving C++ blank is no longer justified once field/helper names are documented as inferred.

## Supervisor Active Recheck

The supervisor specifically assigned UID `0003NC` for source-quality reanalysis, raw helper/field/type/global/placeholder naming, caller/reachability and source placement, open-question closure, first-draft C++ or exact no-code proof, exact supervisor-owned coverage row text, and a target/support implementation checklist.

This item does not require a new split into separate pages. It is a coherent two-body helper island inside the TextButtonEx block, and both bodies share direct class owner/source route. The only structural repair needed is a one-byte endpoint/range correction:

- current file/range: `0x00495aa0-0x00495be2`;
- corrected half-open file/range: `0x00495aa0-0x00495be3`.

The range correction is not cosmetic. It moves the final zero byte of the second `ret 8` out of the claimed padding and into the source body. It also changes the first helper's child subrange end and the internal padding start from `0x00495b50` to `0x00495b51`.

No by-* documentation or `by-memory/-coverage-report.md` was edited in this report-only pass.

## Inference Research Guidance Check

Evidence was separated into:

- Direct raw PE fact: bytes and disassembly from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, image base `0x00400000`.
- Existing IDA-backed documentation: target page, [UID:000118][ButtonChoiceControlCore](../../../../../by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md), [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md), [UID:0000HY][ButtonControlPane](../../../../../by-file/ButtonControlPane.md), and support pages for `TextEditPane::CopyWideText`, `GrafPort::GetTextWidth`, `BackPane::GetBounds`, and `RectBounds` geometry helpers.
- Inference: helper method names, exact source spelling, and the retained-unreferenced-helper explanation for the no-xref raw starts.

IDA MCP was attempted during this pass with `initialize` against `http://127.0.0.1:13337/mcp`; the endpoint was not reachable. Therefore fresh live IDA calls were not available in this session. I did not treat prior docs as authority: the raw PE pass independently checked the target bytes, branch/pointer reachability, callee addresses, and the endpoint defect.

## Heuristic / Inference Reanalysis And Validation

### Raw helper role

Issue: current page names the pair generically as provider-text and supplied-text label-bounds helpers, with formal C++ blank.

Evidence checked:

- Raw PE bytes and Capstone disassembly for `0x00495aa0-0x00495be3`.
- Existing target page's MCP-derived facts for `lookup_funcs`, scoped listing, no xrefs, and constructor pairing.
- [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md) constructor/state docs, especially `+0x10c` child lifecycle and the same text-measure/bounds/clamp pattern in `SetState`.
- Old [UID:000118] B003 report, treated as a lead only.

Best inference:

- `0x00495aa0` is the current/provider-text overload: it copies current text out of the `+0x10c` label child and computes a label rectangle.
- `0x00495b60` is the supplied-text overload: it computes the same rectangle for a caller-provided `const wchar_t *`.
- Best source-facing descriptive/original-candidate name: `TextButtonExControlPane::CalculateLabelRect`.

Rejected alternatives:

- `GetTextBounds`: weaker because the body writes a label control rectangle, not only text metrics.
- `SetLabelBounds`: weaker because it only writes the caller-provided `RectBounds`; it does not apply the result to the child pane.
- `TextButtonExControlPaneLabelBoundsRawHelpers`: useful page name, not a source method name.
- `FittingRoomDownloadControlPane::CalculateLabelRect`: owner is contradicted by `TextButtonExControlPane` address neighborhood, vtables, constructor field, and generic control-family source route.

Remaining blocker:

- Exact original spelling is not proven. This caps confidence below final-source audit level but does not block first-draft C++.

### Correct half-open range and padding

Issue: current target range/subranges are off by one byte under the project half-open range convention.

Raw PE validation:

```text
0x00495a95-0x00495aa0: 11 bytes, all cc
0x00495aa0-0x00495b51: provider helper, ret 4 is c2 04 00 at 0x00495b4e-0x00495b50
0x00495b51-0x00495b60: 15 bytes, all cc
0x00495b60-0x00495be3: supplied helper, ret 8 is c2 08 00 at 0x00495be0-0x00495be2
0x00495be3-0x00495bf0: 13 bytes, all cc
```

Best inference:

- Rename/rerange the page to `0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md`.
- Update covered ranges to `0x00495aa0-0x00495b51`, `0x00495b51-0x00495b60`, and `0x00495b60-0x00495be3`.

Rejected alternatives:

- Keep current `0x00495be2` endpoint: contradicted by the three-byte `ret 8`.
- Treat the zero bytes at `0x00495b50` and `0x00495be2` as padding: contradicted by x86 instruction decoding.
- Split into two pages: unnecessary; both bodies have the same owner/source purpose and the island already includes internal padding.

Impact:

- This is a target-doc and coverage-row repair, not an owner change. It should prevent future range tools from misclassifying instruction bytes as padding.

### Field at `this+0x10c`

Issue: current target uses `this+0x10c` / "provider child" wording without a source-quality field/type name.

Evidence checked:

- [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md): constructor allocates a 372-byte child through `0x004f4aa0`, constructs it through `0x00595390`, stores it at `this+0x10c`, sets its rect, shows/hides it, attaches/detaches it, and releases it in teardown/destructor.
- [UID:0002RV][TextBoxPaneConstructor](../../../../../by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md): `0x00595390` is `TextBoxPane::TextBoxPane`, which builds a `TextEditPane` base.
- [UID:0002O9][TextEditPaneCopyWideText](../../../../../by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md): `0x0058e380` copies bounded UTF-16 text from a `TextEditPane`-derived object; caller list includes raw `0x00495aca`.

Best inference:

- Type: `TextBoxPane *` or a `TextEditPane`-derived `TextBoxPane *`.
- Field name: `m_labelTextBox` is the best descriptive source-facing name for this target. `m_textBoxPane` is a safe fallback if the class page wants a less role-specific field name.

Rejected alternatives:

- `TextEditPane *m_textProvider`: type is too broad for constructor evidence; it is acceptable as an inherited-method dependency but not the best field type.
- `m_text`: misleading because the field stores a pane object, not an inline string.
- `this+0x10c` as final wording: should remain as offset evidence, not as the source-facing name.
- `SelectionControlPane::m_selectedValue` or other `+0x10c` meanings from nearby classes: rejected because `+0x10c` is class-local and has different meanings in Selection/Radio/Slider/TextButtonEx contexts.

Impact:

- Field-name closure removes one documented final-C++ blocker. Exact historical member spelling remains inferred, but source-quality behavior supports `m_labelTextBox`.

### Calee/helper placeholders

Issue: target prose still relies on raw helper labels `sub_58E380`, `sub_4BAA70`, `sub_4B8E00`, and `sub_4B7CC0`.

Best-supported interpretations:

| Placeholder | Best-supported source-facing name | Status | Evidence |
| --- | --- | --- | --- |
| `sub_58E380` | `TextEditPane::CopyWideText(wchar_t *outText, int maxChars)` | documented source method | [UID:0002O9] documents bounded UTF-16 copy, seven callers including raw `0x00495aca`; TextBoxPane inherits TextEditPane behavior. |
| `sub_4BAA70` | `GrafPort::GetTextWidth(const wchar_t *text)` | documented source method | [UID:00016C] documents the null-terminated text-width overload at `0x004baa70`; target passes inherited `this` as receiver and a wide string pointer. |
| `sub_4B8E00` | inherited `GetBounds(RectBounds *outBounds) const` | documented exact body as [UID:000161] `BackPane::GetBounds` | Body copies the receiver bounds at `+0x44`; target uses it as an inherited/control-pane bounds accessor. In target C++, use `GetBounds(&controlBounds)` to avoid hard-coding `BackPane::` on a `TextButtonExControlPane` receiver. |
| `sub_4B7CC0` | `IntersectRects(const RectBounds *a, const RectBounds *b, RectBounds *out)` | documented RectBounds geometry helper | [UID:00015S] identifies `0x004b7cc0` as `IntersectRects`; target calls it as `IntersectRects(&controlBounds, outRect, outRect)` for in-place clamping. |
| `@__security_check_cookie@4` / `___security_cookie` | MSVC stack-cookie support | compiler-generated | Present because both raw helpers use security cookies. Do not write explicit source code for it. |
| `sub_495BF0` successor | `ImageButtonControlPane::ImageButtonControlPane` | documented neighboring constructor | Successor starts at `0x00495bf0`; it is a boundary/exclusion, not owner evidence for UID `0003NC`. |

Rejected alternatives:

- Treat `sub_4BAA70` as TextButtonEx-private measurement: contradicted by [UID:00016C] broad GrafPort text-run helper documentation and fan-in.
- Treat `sub_4B8E00` as BackPane-only owner evidence: the exact body is documented through BackPane, but its behavior is an inherited/bounds accessor used by many panes; in this target it is a dependency, not a source owner.
- Treat `sub_4B7CC0` as Region-owned: Region consumes rectangle helpers elsewhere, but [UID:00015S] places this primitive in the RectBounds geometry helper family.

### Caller/reachability

Issue: current target says no xrefs to raw starts and keeps C++ blank pending final reachability review.

Evidence checked:

- Existing target and B003 report: MCP `xrefs_to` found no cross-references to `0x00495aa0` or `0x00495b60`.
- Raw PE scan over the `.text` section: no direct `E8`/`E9`, rel8, or Jcc branch/call references to `0x00495aa0` or `0x00495b60`.
- Raw PE scan over the full file: no exact little-endian VA or RVA occurrences for `0x00495aa0` or `0x00495b60`.
- Neighboring source context: the helpers sit after `TextButtonExControlPane::OnPaint` and before `ImageButtonControlPane::ImageButtonControlPane`, with `0xcc` padding before/after.

Best inference:

- These are retained source-authored private helpers with no proven live direct call route in the current binary. A late-1999 to mid-2000s MSVC build without function-level dead-stripping, or with object-level retention, can retain unreferenced member functions in a translation unit.
- No direct reachability should remain documented as a caveat. It should cap confidence and prevent `95+`, but it is not a no-code proof.

Rejected alternatives:

- Vtable callback: rejected by no VA/RVA pointer hits and no documented vtable cells pointing to these starts.
- Direct call missed by IDA only: raw PE branch scan found none, so ordinary direct calls are also rejected.
- Computed indirect branch/table route: no positive pointer/table evidence; cannot be fully disproven, but no current evidence supports it.
- Compiler padding/data island: rejected by full prologues, stack cookies, valid calls, rectangle writes, and `ret imm16` epilogues.

Impact:

- Reachability question is closed as "no direct branch/pointer route found; likely retained unreferenced private helpers." Formal C++ should be populated as source-authored retained helper code, not suppressed.

### Owner/source placement

Issue: current page already assigns `0000EK` but requests source-quality revalidation.

Best owner:

- [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md).

Evidence:

- First helper reads the `TextButtonExControlPane` label/text child at `this+0x10c`.
- Constructor `0x00495450` stores that child at `+0x10c` after constructing a `TextBoxPane`, and it uses the same label-rectangle concept before the child is installed.
- `SetState` in the same class re-reads provider text, recomputes centered label bounds, applies disabled-state offset, updates the child rect, and invalidates.
- The raw helper island is between `TextButtonExControlPane::OnPaint` and `ImageButtonControlPane` successor code.
- Direct class parent [UID:0000EK] is `86/86`; source-file route [UID:0000HY] is `86/88`.

Rejected owners:

- [UID:0000EJ][TextButtonControlPane]: plain text-button sibling lacks the `TextBoxPane` child at `+0x10c`; its method block precedes TextButtonEx.
- [UID:00006D][ImageButtonControlPane]: successor starts at `0x00495bf0`; these helpers do not access image-button resource/frame state.
- [UID:0000OJ][TextBoxPane] / [UID:0000EO][TextEditPane]: they provide the child object and copy method, but the raw helpers compute TextButtonEx label bounds using the owner receiver.
- [UID:00005V][GrafPort], [UID:0000N2][RectBounds], [UID:00000S][BackPane]: dependency owners only.
- [UID:000118][ButtonChoiceControlCore]: broad non-emitting aggregate/index; exact children carry source ownership.
- Fitting-room/generated owners: rejected as stale caller/owner pollution; no fitting-room state appears.

Source placement:

- Keep through [UID:0000HY][ButtonControlPane](../../../../../by-file/ButtonControlPane.md), projected to `NexusTK/ui/controls/ButtonControlPane.cpp`.
- A future narrower `TextButtonControlPane.cpp` or `ChoiceControlPane.cpp` split remains a file-level question in [UID:0000HY], but current evidence does not justify creating a new `TextButtonExControlPane.cpp` or rerouting UID `0003NC` away from the established class/file path.

## Evidence Standards Used

Evidence types used:

- Raw PE section mapping and Capstone 32-bit x86 disassembly.
- Raw PE branch/pointer scans for direct reachability.
- Existing IDA-backed by-memory and by-class pages for caller/xref facts, function starts, neighboring boundaries, and helper identities.
- Source-family and proposed-source-tree documentation for source placement.
- Negative evidence for rejected owners and no-code/no-xref hypotheses.

The evidence is strong enough for range correction and first-draft C++ because the raw bytes decode cleanly, the behavior is compact, callees are documented, owner-specific field evidence is local to TextButtonEx, and no contradictory source route appears. Confidence remains below final-source level because original helper names and direct live reachability are not recovered.

## Raw PE / IDA Facts

### Local PE Facts From This Pass

Binary checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
MD5:    4247E04E20B65D6414C7238AA8FF5515
SHA256: 9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632
Image base: 0x00400000
.text RVA/raw: RVA 0x001000, raw 0x000400
```

Function/range facts:

| Range | Length | Fact |
| --- | ---: | --- |
| `0x00495a95-0x00495aa0` | 11 | all `0xcc`, padding after `TextButtonExControlPane::OnPaint`. |
| `0x00495aa0-0x00495b51` | 177 | provider/current-text helper body; final instruction `ret 4` at `0x00495b4e` is `c2 04 00`. |
| `0x00495b51-0x00495b60` | 15 | all `0xcc`, internal alignment. |
| `0x00495b60-0x00495be3` | 131 | supplied-text helper body; final instruction `ret 8` at `0x00495be0` is `c2 08 00`. |
| `0x00495be3-0x00495bf0` | 13 | all `0xcc`, padding before `ImageButtonControlPane` constructor. |

Provider helper disassembly highlights:

| Address | Instruction / meaning |
| --- | --- |
| `0x00495aa3` | `sub esp, 0x114`; local 16-byte bounds and 128-wide-char text buffer area. |
| `0x00495aa9` | loads `___security_cookie` at `0x00672f24`; compiler stack-cookie support. |
| `0x00495ac1` | pushes `0x7f`, text buffer, loads `[edi+0x10c]`, calls `0x0058e380`. |
| `0x00495ad8` | calls `0x004baa70` to measure null-terminated text. |
| `0x00495ae9` | calls `0x004b8e00` to copy current bounds. |
| `0x00495af4-0x00495b27` | computes centered label rectangle using text width, control left/right/top/bottom, and 12-pixel height. |
| `0x00495b36` | calls `0x004b7cc0` with `controlBounds`, `outRect`, `outRect` for in-place intersection/clamp. |
| `0x00495b46` | calls security-cookie check `0x005c772f`. |
| `0x00495b4e` | `ret 4`, proving one explicit argument. |

Supplied-text helper disassembly highlights:

| Address | Instruction / meaning |
| --- | --- |
| `0x00495b63` | `sub esp, 0x14`; local 16-byte bounds only. |
| `0x00495b70` | loads caller-supplied text pointer from `[ebp+0x0c]`. |
| `0x00495b7c` | calls `0x004baa70` to measure caller-supplied text. |
| `0x00495b8a` | calls `0x004b8e00` to copy current bounds. |
| `0x00495b92-0x00495bbc` | computes the same label rectangle. |
| `0x00495bc8` | calls `0x004b7cc0` with `controlBounds`, `outRect`, `outRect`. |
| `0x00495bd8` | calls security-cookie check `0x005c772f`. |
| `0x00495be0` | `ret 8`, proving two explicit arguments. |

Raw reachability facts:

- No direct branch/call references to `0x00495aa0` or `0x00495b60` were found in `.text` by scanning `E8`, `E9`, rel8, and Jcc encodings.
- No exact little-endian VA or RVA occurrence for `0x00495aa0` or `0x00495b60` was found in the full file scan.
- This validates and strengthens the existing MCP `xrefs_to` no-reference note.

### Existing IDA-Backed Documentation Facts Revalidated As Leads

- Target page records prior MCP `lookup_funcs` reporting `0x00495aa0` and `0x00495b60` as `Not a function`, and successor `0x00495bf0` as `sub_495BF0`, size `0xb5`.
- Target page records prior MCP `xrefs_to` returning no cross-references to `0x00495aa0` or `0x00495b60`.
- [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md) documents exact constructor/state/text/show/hide/attach/detach/paint methods and the `+0x10c` child lifecycle.
- [UID:0002O9][TextEditPaneCopyWideText](../../../../../by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) documents `0x0058e380` and includes raw `0x00495aca` as a caller.
- [UID:00016C][GrafPortTextRunHelpers](../../../../../by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) documents `0x004baa70` as `GrafPort::GetTextWidth(const wchar_t *text)`.
- [UID:000161][BackPaneGetBounds](../../../../../by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) documents `0x004b8e00` as a one-argument bounds copy from receiver `+0x44`.
- [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) documents `0x004b7cc0` as `IntersectRects`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00495aa0-0x00495b51` | part of `0003NC` / corrected target path | `TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect)` inferred provider/current-text overload | `TRUE` | `0000EK` | recommend `88/89` page score | Source-authored raw body; no direct start refs; first-draft C++ eligible. |
| `0x00495b51-0x00495b60` | internal padding | `int3` alignment | no source body | none | n/a | Corrected from current stale `0x00495b50-0x00495b60`. |
| `0x00495b60-0x00495be3` | part of `0003NC` / corrected target path | `TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect, const wchar_t *text)` inferred supplied-text overload | `TRUE` | `0000EK` | recommend `88/89` page score | Source-authored raw body; no direct start refs; first-draft C++ eligible. |
| `0x00495be3-0x00495bf0` | successor padding | `int3` alignment before ImageButton constructor | no source body | none | n/a | Corrected from current stale `0x00495be2-0x00495bf0`. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00495aa0` | no direct branch/call refs found; no VA/RVA pointer hits found | Raw provider/current-text helper is retained source code with no recovered direct reachability. |
| `0x00495b60` | no direct branch/call refs found; no VA/RVA pointer hits found | Raw supplied-text helper is retained source code with no recovered direct reachability. |
| `0x00495aca -> 0x0058e380` | direct call | Copies current label text from `m_labelTextBox` / `TextBoxPane` via TextEditPane base method. |
| `0x00495ad8 -> 0x004baa70` | direct call | Measures copied current text through inherited GrafPort text-width helper. |
| `0x00495ae9 -> 0x004b8e00` | direct call | Gets current control bounds into local `RectBounds`. |
| `0x00495b36 -> 0x004b7cc0` | direct call | Intersects computed label rect with control bounds in place. |
| `0x00495b7c -> 0x004baa70` | direct call | Measures caller-supplied text. |
| `0x00495b8a -> 0x004b8e00` | direct call | Gets current control bounds. |
| `0x00495bc8 -> 0x004b7cc0` | direct call | Intersects computed label rect with control bounds in place. |
| `0x00495b46`, `0x00495bd8` | direct calls to `0x005c772f` | MSVC stack-cookie checks, not source-level helper calls. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `by-class/TextButtonExControlPane.md` already documents `+0x10c` child lifecycle, TextButtonEx vtable writes, constructor/state/show/hide/attach/detach/paint behavior, and direct class/source-file route.
- `by-file/ButtonControlPane.md` already treats TextButtonEx as part of the generic button/choice-control source-family file, projected to `NexusTK/ui/controls/ButtonControlPane.cpp`.
- `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` already records UID `0003NC` as an exact raw TextButtonEx child under the corrected aggregate.
- `by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md`, `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`, `by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md`, and `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` provide source-quality names for the target's raw callee placeholders.

Existing docs that are stale, incomplete, or contradicted:

- Target filename/range and `Covered Ranges` are off by one byte at both helper endpoints if interpreted as half-open ranges.
- Target padding notes incorrectly count the final `00` byte of `ret imm16` as padding at `0x00495b50` and `0x00495be2`.
- Target C++ blocker is now stale: source-quality names and reachability review are resolved well enough for first-draft C++.
- `by-memory/-coverage-report.md` still has stale ButtonChoice aggregate rows and currently does not show the corrected UID `0003NC` row in the proper nested form. This report provides exact replacement text for the supervisor.
- Project-level unresolved reports still list raw placeholders for this target; after implementation, prose should include source-facing names beside historical addresses/placeholders.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently shows UID `0003NC` as `emits` with owner/emitter `0000EK`, output path `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`, and no formal code.
- `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` contains only the empty-emitter marker for UID `0003NC`.
- These generated files should not be manually edited; validator/project refresh should update them after the target/support implementation callback.

## Ranked Ownership Analysis

### 1. [UID:0000EK] TextButtonExControlPane

- Evidence for: owner-specific `m_labelTextBox`/`+0x10c` child use, TextButtonEx constructor/state pairing, local address block after TextButtonEx `OnPaint`, class page score `86/86`, existing owner/emitter route, and no contradictory dependency ownership.
- Evidence against: raw starts have no direct inbound refs, and exact helper names are inferred.
- Decision: accepted. This is the direct semantic owner and should remain `CANONICAL_OWNER:0000EK`, `EMITTER_UIDS:0000EK`.

### 2. [UID:0000HY] ButtonControlPane source file

- Evidence for: established source-family route for ButtonControlPane, TextButtonEx, ImageButton, RadioGroup, Slider, Selection, and related button/choice controls; projected path `NexusTK/ui/controls/ButtonControlPane.cpp`.
- Evidence against: file page is a source route, not the direct class owner; possible later source split remains open.
- Decision: accepted as emitter/file route through class parent, not as direct owner.

### 3. [UID:0000EJ] TextButtonControlPane / [UID:0000OK] TextButtonControlPane file

- Evidence for: related text-button sibling and adjacent address region.
- Evidence against: target uses TextButtonEx-only `+0x10c` TextBoxPane child; TextButtonControlPane lacks that child; TextButtonEx block and class docs own the local constructor/state/paint range.
- Decision: rejected.

### 4. [UID:00006D] ImageButtonControlPane

- Evidence for: immediate successor begins at `0x00495bf0`.
- Evidence against: target ends before successor padding; no image-button fields/resources used.
- Decision: rejected.

### 5. TextBoxPane / TextEditPane

- Evidence for: the provider/current helper calls a `TextEditPane` method on the `TextBoxPane` child.
- Evidence against: callee/object-service dependency only; label rectangle is computed from TextButtonEx receiver bounds and owned child field.
- Decision: rejected as owner; retained as dependency and type evidence for `m_labelTextBox`.

### 6. GrafPort / BackPane / RectBounds

- Evidence for: target calls documented GrafPort, bounds, and rectangle helper functions.
- Evidence against: these are shared support helpers; target state and source purpose are TextButtonEx-specific.
- Decision: rejected as owners; retained as support dependencies.

### 7. FittingRoom/generated owners

- Evidence for: old by-memory report had `FittingRoomDownloadControlPane` labels and `CalculateLabelRect` for the second body.
- Evidence against: no fitting-room-specific fields, callers, resources, vtables, or source placement; surrounding TextButtonEx constructor/state/paint evidence is stronger.
- Decision: reject owner. Retain `CalculateLabelRect` only as a semantically supported descriptive name lead.

### Proposed new file/grouping

- Proposed owner/name/path: no new owner or file recommended.
- Likely full contents: keep under the existing `ButtonControlPane.cpp` source-family file until broader original-source split evidence changes.
- Candidate related items that belong: UID `0003NA` TextButtonEx raw teardown and UID `0002Y7` TextButtonEx scalar deleting destructor remain class support; they already route through `0000EK`.
- Candidate related items rejected: TextBoxPane/TextEditPane, GrafPort, RectBounds, ImageButton, and FittingRoom are dependencies/consumers or stale leads, not owners.
- Standalone/narrow/broad source-file inference: not standalone; narrow `TextButtonExControlPane` class methods inside the broader `ButtonControlPane.cpp` controls source.

## Negative Evidence Summary

- No direct branch/call or pointer-table evidence reaches `0x00495aa0` or `0x00495b60`.
- No VA/RVA pointer hits for raw starts were found in the file scan.
- No vtable route is documented for either raw body.
- No fitting-room fields, resources, or constructor callers appear in the raw helper bodies.
- Address adjacency to ImageButton is boundary evidence only; the `0x00495be3-0x00495bf0` padding separates the target from the `0x00495bf0` successor.
- `+0x10c` is class-local. It supports TextButtonEx ownership here, but it does not justify importing SelectionControlPane, RadioGroup, or unrelated `+0x10c` field names.

## First-Draft C++ Recommendation

The target is eligible for formal first-draft C++ after the range/filename repair. The C++ should be inserted into UID `0003NC`'s `RECONSTRUCTION_CPP CODE` block during implementation unless the supervisor rejects the range correction or helper naming.

The draft intentionally uses descriptive names where original source spelling is unavailable. It keeps the two binary bodies as two source methods and does not introduce a third emitted helper.

```cpp
void TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect)
{
    wchar_t labelText[128];

    m_labelTextBox->CopyWideText(labelText, 0x7f);

    const short textWidth = GetTextWidth(labelText);

    RectBounds controlBounds;
    GetBounds(&controlBounds);

    outRect->left = (controlBounds.left + controlBounds.right - textWidth) / 2;
    outRect->right = outRect->left + textWidth + 2;
    outRect->top = (controlBounds.top + controlBounds.bottom - 12) / 2;
    outRect->bottom = outRect->top + 12;

    IntersectRects(&controlBounds, outRect, outRect);
}

void TextButtonExControlPane::CalculateLabelRect(RectBounds *outRect, const wchar_t *text)
{
    const short textWidth = GetTextWidth(text);

    RectBounds controlBounds;
    GetBounds(&controlBounds);

    outRect->left = (controlBounds.left + controlBounds.right - textWidth) / 2;
    outRect->right = outRect->left + textWidth + 2;
    outRect->top = (controlBounds.top + controlBounds.bottom - 12) / 2;
    outRect->bottom = outRect->top + 12;

    IntersectRects(&controlBounds, outRect, outRect);
}
```

Code evidence/translation notes:

- `wchar_t labelText[128]` matches a `0x7f` maximum copy plus terminator from `TextEditPane::CopyWideText`; the raw stack frame has enough space for the local text buffer plus local `RectBounds` and cookie.
- `GetTextWidth` is the null-terminated overload at `0x004baa70`.
- `GetBounds` is the inherited receiver bounds copy at `0x004b8e00`; use unqualified/inherited method form in the target C++.
- `IntersectRects(&controlBounds, outRect, outRect)` matches the push order before `0x004b7cc0`.
- Integer `/ 2` matches the MSVC signed divide-by-two idiom `cdq; sub eax, edx; sar eax, 1`.
- Security-cookie setup/check is compiler output and must not be hand-written.

No-code proof status:

- No exact no-code proof exists. No-xref/no-pointer evidence proves lack of recovered direct reachability, not lack of source authorship. The bodies are valid source-shaped helper methods with project-owned callees and class-local state. Formal C++ should not remain blank solely because the raw starts are not referenced.

## Open-Question Closure

Current target open question: "These helpers need source-quality class/field names and final reachability review before emission."

Closure:

- Class name: `TextButtonExControlPane`, confirmed and retained.
- Field name/type: use inferred `TextBoxPane *m_labelTextBox` for `this+0x10c`; `TextEditPane` is the inherited method provider type but not the best field type.
- Helper names: use inferred/descriptive `CalculateLabelRect` overloads; exact original spelling remains unproven but high-probability enough for first-draft C++.
- Dependency names: replace raw placeholders with `TextEditPane::CopyWideText`, `GrafPort::GetTextWidth`, inherited `GetBounds`, and `IntersectRects`, preserving historical raw addresses for audit.
- Reachability: raw PE scan plus existing MCP no-xref facts find no direct branch/call, VA/RVA pointer, or vtable route to raw starts. This remains a documented caveat, not a C++ blocker.
- Range/split: do not split into separate pages; do fix endpoint to `0x00495be3`.
- Score/source-placement/final-C++ impact: recommend `88/89`, owner/emitter unchanged, source route unchanged, C++ populated.

Remaining uncertainty:

- Exact historical method/member spelling is still not proven.
- It remains theoretically possible that an indirect/computed route exists, but no current evidence supports one.
- The broader original file split between `ButtonControlPane.cpp`, `ChoiceControlPane.cpp`, or a text-button-specific source file remains a file-level question, not a blocker for this target.

## Final Recommendation

Exact target changes recommended:

- Rename/rerange:
  - From `by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md`
  - To `by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md`
- Header/title:
  - Change `# 0x00495aa0-0x00495be2 - TextButtonExControlPane Label Bounds Raw Helpers`
  - To `# 0x00495aa0-0x00495be3 - TextButtonExControlPane Label Bounds Raw Helpers`
- Metadata:
  - Change `COMPLETION:85` to `COMPLETION:88`.
  - Change `CONFIDENCE:87` to `CONFIDENCE:89`.
  - Keep `CANONICAL_OWNER:0000EK`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000EK`.
- Covered ranges:
  - `0x00495aa0-0x00495b51` provider/current-text helper.
  - `0x00495b51-0x00495b60` 15-byte `0xcc` padding.
  - `0x00495b60-0x00495be3` supplied-text helper.
- Boundary notes:
  - `0x00495a95-0x00495aa0` remains 11 `0xcc` bytes after `OnPaint`.
  - `0x00495be3-0x00495bf0` is 13 `0xcc` bytes before `ImageButtonControlPane::ImageButtonControlPane`.
  - Add raw PE note that the old `0x00495b50` and `0x00495be2` padding starts each captured the final zero byte of `ret imm16`.
- Raw behavior:
  - Replace raw placeholders with source-facing names while preserving raw addresses for audit.
  - Add `m_labelTextBox` field/type rationale.
  - Add no-direct-branch/no-pointer scan result.
- C++:
  - Insert the first-draft C++ above into the formal reconstruction block.
- Changes section:
  - Add a 2026-06-19 B007 source-quality report entry describing the endpoint correction, helper/field names, raw PE scan, owner/emitter preservation, and first-draft C++ recommendation.

Exact support changes recommended:

- [UID:0000EK][TextButtonExControlPane](../../../../../by-class/TextButtonExControlPane.md):
  - Add method table rows for the corrected raw helper pair.
  - Add/adjust field wording: `this+0x10c` is best documented as inferred `TextBoxPane *m_labelTextBox`, a TextBoxPane/TextEditPane-derived label child.
  - Add evidence that `0x00495aa0` and `0x00495b60` have no direct branch/pointer route but remain source-authored retained class helpers.
  - Recommended score after support update: `COMPLETION:87`, `CONFIDENCE:88` if the class page incorporates the field/helper naming and range correction. Keep owner/emitter unchanged.
- [UID:0000HY][ButtonControlPane](../../../../../by-file/ButtonControlPane.md):
  - Update the proposed contents/owner inventory only if it references stale `0x00495aa0-0x00495be2`; otherwise no score change required.
  - Keep source route `NexusTK/ui/controls/ButtonControlPane.cpp`.
- [UID:000118][ButtonChoiceControlCore](../../../../../by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md):
  - Update child links and boundary table from `0x00495aa0-0x00495be2` to `0x00495aa0-0x00495be3`.
  - Note the corrected internal/post padding if the aggregate keeps detailed child boundary text.
  - Scores can remain `86/90` unless the supervisor wants a stale-row-only correction.
- Generated/project-level files:
  - Do not manually edit. Run validator/refresh after by-* implementation.

Items left no-owner/non-emitting:

- None for UID `0003NC`; owner/emitter stay assigned.
- UID `000118` remains parentless/non-emitting as the broad aggregate index; this report does not change that.

Future work outside this target:

- Broader source split review for `ButtonControlPane.cpp` versus possible later text/choice split remains outside this target.
- Exact original member spellings should be revisited during a full `TextButtonExControlPane` class declaration pass.

## Follow-Up Actions

Supervisor actions:

- Review and accept/reject the range correction and first-draft C++ recommendation.
- If accepted, send B007 an implementation callback using the target/support checklist below.
- Apply or queue the exact `by-memory/-coverage-report.md` replacement text in the supervisor-owned coverage section.

A-agent actions:

- None required before B007 implementation. Later A-agent cleanup can propagate final names if a broader class-layout pass changes `m_labelTextBox` or `CalculateLabelRect`.

B007 future implementation callback actions:

- Lease the target/support by-* docs as required.
- Rename/rerange UID `0003NC` under validator rules.
- Apply the claim-by-claim report details at report-level specificity.
- Run scoped validator commands and report exact outputs.

## Target / Support Implementation Checklist

Use this checklist if the supervisor accepts the report and sends B007 back for implementation.

1. Target rename/range:
   - Lease current target path.
   - Rename `by-memory/0x00495aa0-0x00495be2.TextButtonExControlPaneLabelBoundsRawHelpers.md` to `by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md`.
   - Preserve UID `0003NC`.
   - Update all self-title/range references in the target.
2. Target metadata:
   - Set `COMPLETION:88`, `CONFIDENCE:89`.
   - Keep `CANONICAL_OWNER:0000EK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EK`.
3. Target body:
   - Replace stale subranges with `0x00495aa0-0x00495b51`, `0x00495b51-0x00495b60`, `0x00495b60-0x00495be3`.
   - Add raw PE byte/disassembly evidence for both `ret imm16` endpoint corrections.
   - Add source-facing helper names and dependency names from this report.
   - Add `m_labelTextBox` field/type rationale.
   - Add no direct branch/call and no VA/RVA pointer reachability result.
   - Add first-draft C++ exactly or with only style changes that preserve semantics.
   - Preserve rejected owner alternatives and negative evidence.
4. Support docs:
   - Update `by-class/TextButtonExControlPane.md` with the helper pair and `m_labelTextBox` field/type conclusion; recommended class score `87/88` if incorporated.
   - Update `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` references to corrected UID `0003NC` path/range.
   - Update `by-file/ButtonControlPane.md` only if stale path/range text is present.
   - Do not edit generated files manually.
5. Coverage report:
   - Do not edit `by-memory/-coverage-report.md`.
   - Leave exact replacement row text below for supervisor-owned application.
6. Validation:
   - Run scoped validator file mode on the renamed target.
   - Run scoped validator file mode on each support doc edited.
   - If validator has a rename-specific workflow, use it rather than hand-editing registry state.
   - Report commands, exit code, and `ok` count.

Expected validation commands, adjusted for the final renamed paths:

> Executable block R001 was removed from this report and preserved verbatim in [0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality-removed.md](0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add the `by-file\ButtonControlPane.md` validator command only if that file is edited.

## Exact Supervisor-Owned Coverage Row Text

`by-memory/-coverage-report.md` is stale around the ButtonChoice block. The supervisor should replace/update the UID `0003NC` child row to the following corrected row once the target has been renamed/reranged. Placement: nested under UID `000118` `ButtonChoiceControlCore`, ordered after UID `0003NA` and before the `0x00495bf0` ImageButton/Selection area, or inserted into the supervisor's refreshed replacement block for UID `000118`.

```text
        - [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) 0x00495aa0-0x00495be3 | raw helper island | TextButtonExControlPaneLabelBoundsRawHelpers : reconstructable : 88% : strong : B007 source-quality pass corrects the half-open endpoint to include the final `ret 8` byte; two raw non-function `TextButtonExControlPane::CalculateLabelRect` overloads at `0x00495aa0-0x00495b51` and `0x00495b60-0x00495be3`, internal padding `0x00495b51-0x00495b60`, no direct branch/call or VA/RVA pointer refs to helper starts, current/supplied text measurement through `TextEditPane::CopyWideText` and `GrafPort::GetTextWidth`, inherited bounds fetch `GetBounds`, in-place clamp through `IntersectRects`, inferred `TextBoxPane *m_labelTextBox` at `+0x10c`, first-draft C++ recommended, and owner/emitter route remains [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md).
```

If the supervisor also refreshes the UID `000118` aggregate row, its child mention for UID `0003NC` should use this corrected path/range:

```text
[UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md)
```

Do not use the old `0x00495aa0-0x00495be2` endpoint in any new coverage text after implementation.

## Confidence

- Recommendation confidence: high for owner/emitter, range correction, behavior, dependency naming, and first-draft C++ readiness.
- Score confidence: medium-high. `88/89` is justified after implementation but should not exceed low 90s until direct reachability or original names are recovered.
- Remaining uncertainty: exact original source spelling for `CalculateLabelRect` and `m_labelTextBox`, plus broad source-file split, not behavior or ownership.

## Validator Results

- Commands run for this report-only pass: none.
- Reason: the assignment explicitly forbids editing target/support by-* docs and `by-memory/-coverage-report.md`; only this B007 research report was created.
- Required validation after accepted implementation callback: run the scoped `validator.py --mode file --apply` commands listed in the implementation checklist.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality.md`
- Modified: none outside B007 research.
- Renamed: none in this report-only pass.
- Moved to executed: none.

## Blockers

No blocker remains for source-quality naming, owner/emitter route, reachability disposition, or first-draft C++ recommendation. Implementation is pending supervisor acceptance and a normal B007 implementation callback because this pass was report-only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003NC","source_path":"executed-b-agent-research/B007/0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
