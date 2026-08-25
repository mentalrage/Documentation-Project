** TARGET-REPORT-UID:0001JP **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Research Report: 0001JP/0001JS TextEditPane Formatting and Navigation Source Quality

Assignment: `B001-goal2-texteditpane-format-nav-source-quality-0001JP-0001JS-20260616`

Targets:
- [UID:0001JP] `by-memory/0x00591d60-0x00593a10.TextEditPaneFormattingRuns.md`
- [UID:0001JS] `by-memory/0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md`

Current supervisor state: both rows are `82/86`, `Low_Completion/Low_Both`, after the 2026-06-16 15:23:39 rescore.

## Decision

Both targets are valid TextEditPane source-owned method/helper aggregates, but both current address ranges are stale. Do not split them into many child pages in this pass: the missed bodies are contiguous TextEditPane formatting/navigation helpers, not a separate TextBoxPane, TextFilter, support-object, ScrollPane, or non-emitting compiler island. Do rename/expand both pages, reroute direct ownership from the file page to the TextEditPane class page, refresh the function inventories, and add two tiny ignored padding spans at the new boundaries.

Recommended final state:

| UID | Current range | Recommended range/file | Metadata recommendation |
| --- | --- | --- | --- |
| `0001JP` | `0x00591d60-0x00593a10` | `by-memory/0x00591d60-0x00593c1c.TextEditPaneFormattingRuns.md` | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000EO`, `EMITTER_UIDS:0000EO`, `RECONSTRUCTABLE:TRUE`, final C++ blank |
| `0001JS` | `0x00594040-0x00594e11` | `by-memory/0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md` | `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000EO`, `EMITTER_UIDS:0000EO`, `RECONSTRUCTABLE:TRUE`, final C++ blank |

The score can safely move above `85/85` because the direct owner, emitter route, neighboring boundaries, omitted raw/modeled functions, stale generated-label issue, support-object boundary, and final-C++ blockers were checked. Do not raise higher yet: several raw helper starts still have no direct IDA xrefs/function objects, and source-quality names for the format record/list structs, callback structs, selection fields, and wrap/caret helpers remain inferred rather than source-proven.

## Evidence Checked

Local documentation:
- Target memory pages `0001JP` and `0001JS`.
- `by-class/TextEditPane.md`, `by-file/TextEditPane.md`, `by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md`.
- Neighbor callback pages `0001JQ`, `0001JR`, `0003FC`, `0003FD`.
- Neighbor support pages `0001JT`, `0003M7`, `0002RV`, `0003M8`, `0001JU`.
- `by-project-structure/proposed-source-tree.md`.
- `auto-generated/-ag-memory-coverage.md`, `auto-generated/by-memory-tool-report.md`, `project-level/-auto-completion-stats.md`, and current `by-memory/-coverage-report.md`.

Live IDA MCP:
- Active session `701e9f0c`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, auto-analysis not running.
- `lookup_funcs`, `entity_query`, `xrefs_to`, `analyze_batch`, `decompile`, and `make_signature_for_range` were used on the target corridor.
- `lookup_funcs` confirms IDA does not model several real prologue bodies in these ranges as functions: `0x00591d60`, `0x00591f20`, `0x00592040`, `0x005929a0`, `0x00592ec0`, `0x00593880`, `0x00593b20`, `0x00594190`, `0x005949c0`, `0x00594a30`, and `0x00594e20`.
- The raw byte audit found source-shaped method/helper bodies, not padding, at each of those starts.

## 0001JP Findings

The current `0001JP` page is under-ranged. It stops at `0x00593a10`, but the contiguous TextEditPane formatting/hit-test corridor continues through:

| Range | IDA status | Evidence and role |
| --- | --- | --- |
| `0x00591d60-0x00591ebd` | raw no-function | Source-shaped TextEditPane formatting helper. Starts with a normal prologue; current table endpoint was one byte short. |
| `0x00591ec0-0x00591f1d` | `sub_591EC0`, size `0x5d` | Called by `0x0058dce0` and `0x0058fef0`; calls `0x0058f1b0`; cursor/current-format update family. |
| `0x00591f20-0x00591f54` | raw no-function | Small masked style/format record copy helper. No xrefs to the raw start; keep in aggregate, do not split or ignore. |
| `0x00591f60-0x0059203d` | raw no-function by start lookup | Existing page correctly treats this as range-attribute behavior; byte audit confirms prologue body. |
| `0x00592040-0x0059208e` | raw no-function | Adjacent format-record load/copy helper; current page omitted it. |
| `0x00592090-0x00592436` | `sub_592090`, size `0x3a6` | Called from TextEditPane mutation path; calls `0x0058f1b0` and `0x00592b60`; applies format/style records. |
| `0x00592470-0x005927da` | `sub_592470`, size `0x36a` | Text replacement/range mutation family. |
| `0x005927e0-0x00592993` | `sub_5927E0`, size `0x1b3` | Deletion/range removal family. |
| `0x005929a0-0x00592b5d` | raw no-function | Additional TextEditPane range/style-list helper. No xrefs to raw start; byte audit shows a full prologue/return body. |
| `0x00592b60-0x00592bab` | `sub_592B60`, size `0x4b` | Style-run removal/free helper used by `sub_592090`. |
| `0x00592bb0-0x00592c20` | `sub_592BB0`, size `0x70` | Line lookup from pixel Y. |
| `0x00592c20-0x00592ebc` | `sub_592C20`, size `0x29c` | Initializes text content/run storage. |
| `0x00592ec0-0x00592faa` | raw no-function | Line split/join/width helper; current broad table listed the family but not the raw boundary. |
| `0x00592fb0-0x005931e0` | `sub_592FB0`, size `0x230` | Line/run width and break-update continuation. |
| `0x005931e0-0x0059327f`, `0x00593280-0x005933ba`, `0x00593400-0x00593450`, `0x00593450-0x005934a0` | modeled functions | Character/range index shift and table update helpers. |
| `0x00593500-0x005936d9` | `sub_593500`, size `0x1d9` | Text-run iterator; address-takes callbacks including `0x00593a20`/callback family. |
| `0x005936e0-0x00593875` | `sub_5936E0`, size `0x195` | Text-run/hit-test continuation. |
| `0x00593880-0x00593a11` | raw no-function | Hit-test/x-advance helper. Current page table endpoint was one byte short. |
| `0x00593a20-0x00593b12` | `sub_593A20`, size `0xf2` | Omitted modeled helper. Decompile shows cdecl run-advance/hit-test callback shape: adjusts `a7+4`, checks `a8+0x8c` alignment mode and `a8+0x16a` password/masked mode, calls `0x004ba9a0` on either `L"*"` or text content. Has one data xref from `sub_58F740` at `0x0058f94e`. |
| `0x00593b20-0x00593c1c` | raw no-function | Omitted raw hit-test/selection helper. It has no IDA function object and no direct xrefs to the raw start, but byte audit shows a full prologue body ending `ret 0x1c`; it reads TextEditPane run/layout state and must remain in TextEditPane, not FittingRoom. |
| `0x00593c1c-0x00593c20` | padding | Four `0xcc` bytes before [UID:0001JQ] `0x00593c20`. Add ignored row. |

The current `0x00593b20` stale generated-label caveat needs refinement. The existing docs are right that `0x00593b20` is not an IDA function and has no direct start xrefs, and right that it is not FittingRoom. They are incomplete because the bytes at `0x00593b20` are real TextEditPane code, not an empty generated-label artifact.

## 0001JS Findings

The current `0001JS` page is also under-ranged and under-inventoried. It should continue through the raw method at `0x00594e20-0x00594e5f`, then stop before TextEdit support-object code at `0x00594e60`.

| Range | IDA status | Evidence and role |
| --- | --- | --- |
| `0x00594040-0x00594116` | `sub_594040`, size `0xd6` | Character input handler. Xrefs from `0x0058ebb1` and `0x00590daa`; calls cursor/delete/mutation helpers. |
| `0x00594120-0x00594190` | `sub_594120`, size `0x70` | Delete selected text. |
| `0x00594190-0x005941e3` | raw no-function | Forward-delete helper; byte audit shows real prologue body ending at `ret`; no direct xrefs to raw start. |
| `0x005941f0-0x00594618` | `sub_5941F0`, size `0x428` | Cursor/selection movement. Decompile/callee evidence shows calls to TextEditPane line helpers `0x0058f740`, `0x0058f690`, `0x0058f0d0`, word-boundary helper `0x00594b50`, and width helper `0x004baaa0`. |
| `0x00594618-0x005946b0` | compiler switch table/local data | Byte audit shows 4-byte addresses into `sub_5941F0` (`0x00594240`, `0x00594234`, etc.). This is compiler-owned local data for the move-cursor switch and should stay inside the aggregate, not become a child page or ignored gap. |
| `0x005946b0-0x0059489f` | `sub_5946B0`, size `0x1ef` | Omitted modeled draw/text conversion helper called by `0x00593db0` and raw draw variant `0x0059402d`. Decompile shows password/masking and numeric comma insertion behavior: reads `this+0x16a`, writes `this+0x88`, checks `this+0x173`, uses `wcscpy_s`, `wcslen`, `0x004bab70`, `0x004bab20`, and drawing-state helpers `0x004b95e0`/`0x004b9600`. |
| `0x005948a0-0x005949be` | `sub_5948A0`, size `0x11e` | Wrap line helper. |
| `0x005949c0-0x00594a21` | raw no-function | Omitted wrap/selection width helper. Byte audit shows prologue body ending before padding to `0x00594a30`. |
| `0x00594a30-0x00594b47` | raw no-function | Recalculate wrap positions helper; current page listed this but IDA does not model the raw start. |
| `0x00594b50-0x00594cb0` | `sub_594B50`, size `0x160` | Word-boundary helper. Decompile shows whitespace classification against spaces, tabs, CR, LF over a UTF-16 buffer and fills a two-word output range. Xrefs from `0x0058f9a0`, `0x00590de0`, and `0x005941f0`. |
| `0x00594cb0-0x00594e12` | `sub_594CB0`, size `0x162` | Drag autoscroll helper. Decompile reads `this+0x15c`, `this+0x15a`, viewport/scroll offsets at `+0x110` through `+0x12c`, clamps deltas to `48`, and calls scroll helpers `0x0055e950`, `0x004baaa0`, `0x0055eae0`. |
| `0x00594e12-0x00594e20` | padding | Fourteen `0xcc` bytes after the modeled autoscroll helper. Since the recommended aggregate continues to `0x00594e5f`, this internal alignment does not need its own coverage row. |
| `0x00594e20-0x00594e5f` | raw no-function | Omitted TextEditPane method-shaped body. Byte audit shows `thiscall`-style prologue, reads `this+0x15c`, `this+0x74`, writes `this+0x70`, conditionally passes `this+0x80`, calls `0x004b9640`-family helpers and virtual/global target at `0x0069b3fc`. This is still TextEditPane state/control behavior, not the TextEdit support-object successor. |
| `0x00594e5f-0x00594e60` | padding | One `0xcc` byte before [UID:0003M7] support-object successor `0x00594e60`. Add ignored row. |

The TextEdit/TextBox/TextFilter boundary is clear:
- `0001JS` should own through `0x00594e5f`.
- [UID:0003M7] `0x00594e60-0x00595389` remains the TextEdit support-object successor.
- [UID:0002RV] `0x00595390-0x005954b3` remains TextBoxPane constructor.
- [UID:0003M8] `0x005954c0-0x00595760` remains TextEdit support-object continuation.
- [UID:0001JU] `0x00595760-0x005958fe` remains TextFilter.

## Owner and Route Ranking

1. `TextEditPane` class [UID:0000EO] - recommended direct owner for both target pages. The pages are TextEditPane instance/static helper clusters, not merely file-level free utilities. The class page already passes the gate and documents the relevant fields/ranges.
2. `TextEditPane.cpp` file [UID:0000ON] - recommended emitter route via class-to-file output. The generated source file remains `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`.
3. `TextEditPane` file-only ownership - current state; acceptable historically, but now less precise than class ownership because `0000EO` clears the parent gate.
4. TextEdit support objects/TextEditObject/TextEditScrap - rejected for these targets except successor starting at `0x00594e60`; the omitted `0x00594e20` body still uses TextEditPane fields, not support-object fields.
5. TextBoxPane [UID:0000OJ] - rejected; constructor begins at `0x00595390` and has separate derivative ownership.
6. TextFilter [UID:0000OO] - rejected; singleton/sanitizer begins at `0x00595760`.
7. Scroll/Pane ancestors - rejected as direct owner. Scroll helpers are callees/dependencies only.
8. No-owner/non-emitting - rejected. These are reconstructable TextEditPane-owned code/data aggregates.

## Source-Quality and Final-C++ Eligibility

After the recommended metadata update, both pages mechanically clear the active reconstruction-code route gate: reconstructable, nonblank emitter, and average score above 85. Still do not add final C++ now. The gate is necessary but not sufficient for this corridor.

Resolved blockers:
- Function/range shape: exact omitted modeled and raw bodies identified.
- Raw reachability: no-xref raw starts were checked; they are retained in same coherent aggregate instead of ignored/split.
- Neighbor boundary: callback boundary at `0x00593c20` and support-object boundary at `0x00594e60` are byte-confirmed.
- Source route: class direct owner with file emitter is preferred.
- Stale generated labels: `0x00593b20` is TextEditPane raw code, not FittingRoom, and generated `0x00593d00`/`0x00593f00` remain callback raw-body labels, not file-routing evidence.
- TextBox/TextFilter boundaries: no spill into the target ranges.

Remaining blockers that justify `86/89` rather than a higher score/final C++:
- The original source names for style/format record structs, run-list storage, line/wrap arrays, and callback context structs remain inferred from offsets and behavior.
- Several raw prologue bodies have no IDA function objects and no direct start xrefs; they are source-shaped, but their exact original helper names and source-authored vs compiler-outlined status cannot be proven safely.
- The `sub_5941F0` switch table at `0x00594618-0x005946b0` is compiler-owned local data; final C++ needs the exact enum/action mapping before conversion.
- Field names are role-level only: `+0x134` text/list storage, `+0x138/+0x13c/+0x140` line/run/style/format tables, `+0x144/+0x146` selection/caret words, `+0x15a/+0x15c` selection/autoscroll flags, `+0x16a` masked/password-ish flag, `+0x173` numeric formatting flag, and viewport/scroll offsets around `+0x110-+0x12c`.

## Exact Supervisor Edits

Do not edit IDA DB. Apply only documentation changes below.

### Rename target files

From `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001JP-0001JS-texteditpane-format-nav-source-quality-removed.md](0001JP-0001JS-texteditpane-format-nav-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

### Update `by-memory/0x00591d60-0x00593c1c.TextEditPaneFormattingRuns.md`

Metadata:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000EO
EMITTER_UIDS:0000EO
RECONSTRUCTABLE:TRUE
```

Replace stale range/function discussion with the `0001JP Findings` inventory above. Preserve blank reconstruction C++ and add a note that `0x00593c1c-0x00593c20` is ignored padding.

### Update `by-memory/0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md`

Metadata:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000EO
EMITTER_UIDS:0000EO
RECONSTRUCTABLE:TRUE
```

Replace stale range/function discussion with the `0001JS Findings` inventory above. Preserve blank reconstruction C++ and add a note that `0x00594e5f-0x00594e60` is ignored padding.

### Update support docs

`by-class/TextEditPane.md`:
- Change main address range text from `0x00591d60-0x00594e11` to `0x00591d60-0x00594e5f`.
- Change format row from `0x00591d60-0x00593a10` to `0x00591d60-0x00593c1c`.
- Change input/navigation row/link from `0x00594040-0x00594e11` to `0x00594040-0x00594e5f`.
- Replace the `0x00593b20` generated-label note with: `IDA still has no function object or direct start xrefs at 0x00593b20, but the bytes are a real TextEditPane raw helper body ending at 0x00593c1c; it is not FittingRoom and should stay in the TextEditPane formatting aggregate.`

`by-file/TextEditPane.md`:
- Change main address cluster from `0x00591d60-0x00594e11` to `0x00591d60-0x00594e5f`.
- Update the two target links to the renamed files.
- Update the generated-label caveat exactly as above.
- Add that `0x00594e20-0x00594e5f` is still TextEditPane code and `0x00594e60` is the support-object successor boundary.

`by-project-structure/proposed-source-tree.md`:
- No source-tree route change required. Current `NexusTK/ui/controls/TextEditPane.cpp` placement remains correct.

Generated outputs:
- Do not hand-edit generated files. Running validator/autogen after supervisor edits should update `auto-generated/-ag-memory-coverage.md` from file-owner route `0000ON -> 0000ON` to class-owner route `0000EO -> 0000EO` while still resolving to `auto-generated/NexusTK/ui/controls/TextEditPane.cpp`.

### Update `by-memory/-ignored.md`

Add a new ledger entry near the existing TextEditPane callback padding entry:

```markdown
- `0x00593c1c-0x00593c20` and `0x00594e5f-0x00594e60` - TextEditPane formatting/navigation boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the expanded TextEditPane formatting aggregate and the cdecl measurement callback, and between the expanded TextEditPane navigation aggregate and the TextEdit support-object successor.
  - Evidence: 2026-06-16 B001 live IDA MCP `make_signature_for_range` byte audit reports `0x00593b20-0x00593c1c` as a real raw TextEditPane helper ending in `ret 0x1c`, followed by four `0xcc` bytes at `0x00593c1c-0x00593c20`; the same audit reports `0x00594e20-0x00594e5f` as a real raw TextEditPane helper ending in `ret 0x04`, followed by one `0xcc` byte at `0x00594e5f-0x00594e60`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000EO][TextEditPane](by-class/TextEditPane.md), [UID:0000ON][TextEditPane](by-file/TextEditPane.md), [UID:0001JP][0x00591d60-0x00593c1c.TextEditPaneFormattingRuns](by-memory/0x00591d60-0x00593c1c.TextEditPaneFormattingRuns.md), [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md), [UID:0001JS][0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap](by-memory/0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md), and [UID:0003M7][0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane](by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md).
```

Also replace both old `0001JS` links in the existing TextEditPane callback alignment entry with:

```markdown
[UID:0001JS][0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap](by-memory/0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md)
```

## Exact `by-memory/-coverage-report.md` Pending Rows

Replace the current `0001JP` row with:

```markdown
    - [UID:0001JP][0x00591d60-0x00593c1c.TextEditPaneFormattingRuns](by-memory/0x00591d60-0x00593c1c.TextEditPaneFormattingRuns.md) 0x00591d60-0x00593c1c | method cluster | TextEditPaneFormattingRuns : reconstructable : 86% : strong : B001 2026-06-16 source-quality audit expands the stale formatting-run range through the omitted modeled `0x00593a20-0x00593b12` run-advance helper and raw `0x00593b20-0x00593c1c` TextEditPane helper, records raw/no-function helper pockets at `0x00591d60`, `0x00591f20`, `0x00592040`, `0x005929a0`, `0x00592ec0`, and `0x00593880`, rejects the stale FittingRoom-generated marker route, reroutes direct ownership to TextEditPane class `0000EO` with file emitter output through `TextEditPane.cpp`, and keeps final C++ blank pending exact format/run struct names, callback context names, and raw-helper source names.
```

Insert this ignored row immediately after the new `0001JP` row and before `0001JQ`:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00593c1c-0x00593c20 | padding | TextEditPane formatting aggregate to measurement callback alignment : ignored : 100% : strong : B001 2026-06-16 IDA MCP byte audit shows four `0xcc` bytes after raw TextEditPane helper `0x00593b20-0x00593c1c` and before callback `0x00593c20`.
```

Replace the current `0001JS` row with:

```markdown
    - [UID:0001JS][0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap](by-memory/0x00594040-0x00594e5f.TextEditPaneInputNavigationAndWrap.md) 0x00594040-0x00594e5f | method cluster | TextEditPaneInputNavigationAndWrap : reconstructable : 86% : strong : B001 2026-06-16 source-quality audit expands the stale navigation/wrap range through raw TextEditPane method `0x00594e20-0x00594e5f`, adds omitted modeled renderer `0x005946b0-0x0059489f`, word-boundary helper `0x00594b50-0x00594cb0`, raw forward-delete/wrap helpers `0x00594190`, `0x005949c0`, and `0x00594a30`, records the local `0x00594618-0x005946b0` move-cursor switch table, confirms the TextEdit support-object successor at `0x00594e60`, reroutes direct ownership to TextEditPane class `0000EO` with file emitter output through `TextEditPane.cpp`, and keeps final C++ blank pending exact cursor/selection/wrap field names and raw-helper source names.
```

Insert this ignored row immediately after the new `0001JS` row and before `0001JT`/`0003M7` successor material:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00594e5f-0x00594e60 | padding | TextEditPane navigation aggregate to TextEdit support object alignment : ignored : 100% : strong : B001 2026-06-16 IDA MCP byte audit shows one `0xcc` byte after raw TextEditPane helper `0x00594e20-0x00594e5f` and before TextEdit support-object successor `0x00594e60`.
```

## Validation Commands for Supervisor

Run from `E:\NTK\GhidraBridge\source-3\project-documentation\tools` after applying the supervisor-owned edits:

> Executable block R002 was removed from this report and preserved verbatim in [0001JP-0001JS-texteditpane-format-nav-source-quality-removed.md](0001JP-0001JS-texteditpane-format-nav-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the validator reports stale references to the old target filenames, update those references rather than restoring the old files. The old ranges are under-ranged.

## Completion State

This assignment is complete as report-only work. No by-memory, generated, coverage, IDA DB, or source-tree files were edited by B001. Supervisor-owned pending shared rows are the two target coverage replacements plus two ignored coverage inserts above, and the new `-ignored.md` ledger entry.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001JP-0001JS-texteditpane-format-nav-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001JP"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001JP-0001JS-texteditpane-format-nav-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001JP-0001JS-texteditpane-format-nav-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001JP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
