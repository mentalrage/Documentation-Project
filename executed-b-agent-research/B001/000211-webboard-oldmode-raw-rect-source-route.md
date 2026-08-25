** TARGET-REPORT-UID:000211 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000211 WebBoardDialogOld Mode Rect Helper Source-Route Research

Assignment: `B001-goal2-webboard-oldmode-raw-rect-source-route-000211-20260616`  
Target: [UID:000211] `by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md`  
Report-only scope: no by-* docs, generated/project-level reports, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Final Recommendation

Keep [UID:000211] as one exact reconstructable helper page, but tighten the direct owner from file-level [UID:0000P9] `WebBoardDialog` to class-level [UID:0000G3] `WebBoardDialogOld`.

Recommended target metadata:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000G3
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000G3
RECONSTRUCTION_CPP CODE: blank
```

No split is recommended. The range contains one source-authored stack-cleaning old-dialog rectangle helper plus local compiler switch tables:

```text
0x0046e4c0-0x0046e609  helper body
0x0046e609-0x0046e60c  three-byte internal alignment / NOP
0x0046e60c-0x0046e63c  three local four-entry switch tables
```

The helper has no IDA function object and no external static caller/pointer route, so final C++ remains blocked. It should not be demoted to dead/non-emitting: the body is unique, source-shaped, immediately bracketed by old WebBoard layout/constructor code, and its mode/selector rectangle constants exactly match the old layout refresh behavior.

## Target State

Current metadata:

```text
COMPLETION:82
CONFIDENCE:87
CANONICAL_OWNER:0000P9
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P9
```

Current coverage row:

```text
class helper/switch-table | WebBoardDialogOldModeRectHelper : reconstructable : 82% : strong
```

Current generated memory route is stale after this recommendation because it emits directly through [UID:0000P9]. The recommended route is [UID:0000G3] `WebBoardDialogOld`, which then surfaces through [UID:0000P9] `WebBoardDialog`.

## Evidence Used

Evidence types checked:

- Live IDA MCP session `b001_000211_20260616`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`.
- IDA function lookup, local function inventory, xrefs, byte reads, instruction query, callee/decompilation checks for the neighboring old layout function.
- Direct raw PE parsing and whole-image scans for rel32 calls/jumps, absolute VA pointers, RVA byte patterns, and exact byte uniqueness.
- Existing documentation under `by-memory`, `by-class`, `by-file`, `by-global`, `by-memory/-ignored.md`, and `by-memory/-coverage-report.md`.

No Wave2/Wave3/simroot source was used as evidence.

## Boundary Audit

Live IDA confirms:

| Range / address | IDA state | Recommendation |
| --- | --- | --- |
| `0x0046e2a0-0x0046e4b6` | function `sub_46E2A0`, size `0x216` | existing [UID:0000ZA] old layout refresh |
| `0x0046e4b6-0x0046e4c0` | ten `0xcc` bytes | existing ignored padding row is correct |
| `0x0046e4c0` | no IDA function object | raw helper entry |
| `0x0046e4c0-0x0046e609` | 86 decoded instructions, no function owner | source-authored helper body |
| `0x0046e609-0x0046e60c` | bytes `0f 1f 00` | internal compiler alignment/NOP before tables |
| `0x0046e60c-0x0046e63c` | three `dd offset` blocks | local compiler switch tables |
| `0x0046e63c-0x0046e640` | four `0xcc` bytes | existing ignored padding row is correct |
| `0x0046e640-0x0046e8be` | function `sub_46E640`, size `0x27e` | existing [UID:0000ZB] old constructor |

The helper body ends at `0x0046e606` with `retn 0Ch`; `0x0046e609-0x0046e60c` is not source-bearing logic. The tables begin exactly at `0x0046e60c`. The page's exclusive end at `0x0046e63c` is correct because the next four bytes are `0xcc` padding before the constructor.

## Helper Behavior

IDA instruction query shows:

- `[ebp+8]` is the output rectangle pointer. If null, the helper returns without modifying anything.
- `[ebp+0x10]` is the mode selector. Modes `6`, `4`, and `0` are accepted; other modes return without modifying the output rectangle.
- `[ebp+0x0c]` is the control/slot selector. Selectors `0..3` are accepted; selectors above `3` return without modifying the output rectangle.
- Normal selector cases call `sub_4B78D0` with four coordinate arguments.
- Selector `3` branches to `0x0046e5d3`, which writes zero to all four rectangle fields.
- Return convention is `retn 0Ch`; the helper cleans three stack arguments and does not consume `ecx` as `this`.

Rectangle map:

| Mode | Selector | Role | Rectangle |
| ---: | ---: | --- | --- |
| `0` | `0` | main dialog/display rect | `(162, 134, 862, 634)` |
| `0` | `1` | close button rect | `(318, 468, 381, 492)` |
| `0` | `2` | browser/content rect | `(11, 42, 689, 460)` |
| `0` | `3` | clear/none | `(0, 0, 0, 0)` |
| `4` | `0` | main dialog/display rect | `(303, 101, 721, 667)` |
| `4` | `1` | close button rect | `(318, 468, 381, 492)` |
| `4` | `2` | browser/content rect | `(11, 42, 407, 526)` |
| `4` | `3` | clear/none | `(0, 0, 0, 0)` |
| `6` | `0` | main dialog/display rect | `(112, 84, 912, 684)` |
| `6` | `1` | close button rect | `(368, 568, 431, 592)` |
| `6` | `2` | browser/content rect | `(11, 42, 789, 560)` |
| `6` | `3` | clear/none | `(0, 0, 0, 0)` |

`sub_4B78D0` identity: neighboring decompilation and call conventions show this is the local rectangle setter used throughout the old layout function. Final source name for the type and setter is not resolved; use descriptive `Rect::Set` wording only in documentation.

## Switch Table Audit

IDA xrefs and bytes confirm the three local tables:

| Table | Referenced by | Entries |
| --- | --- | --- |
| `0x0046e60c` | data xref from `0x0046e4f4` | `0x0046e4fb`, `0x0046e512`, `0x0046e52f`, `0x0046e5d3` |
| `0x0046e61c` | data xref from `0x0046e552` | `0x0046e559`, `0x0046e573`, `0x0046e590`, `0x0046e5d3` |
| `0x0046e62c` | data xref from `0x0046e5af` | `0x0046e5b6`, `0x0046e573`, `0x0046e5f2`, `0x0046e5d3` |

These are compiler-generated switch tables for source-level `switch` blocks. They should stay documented on [UID:000211], not become source-authored child pages. In final source, they should be regenerated by normal switch code or equivalent if the compiler chooses to emit tables.

## Liveness Audit

IDA facts:

| Target | Result |
| --- | --- |
| `xrefs_to 0x0046e4c0` | none |
| `xrefs_to 0x0046e609` | none |
| `xrefs_to 0x0046e60c` | one internal table-base reference from `0x0046e4f4` |
| `xrefs_to 0x0046e61c` | one internal table-base reference from `0x0046e552` |
| `xrefs_to 0x0046e62c` | one internal table-base reference from `0x0046e5af` |
| `xrefs_to 0x0046e63c` | none |
| `xrefs_to 0x0046e640` | direct constructor callers at `0x00508ddd` and `0x0051461e` |

Raw PE scan facts:

- Target VA `0x0046e4c0`, RVA `0x0006e4c0`, raw offset `0x0006d8c0`, section `.text`.
- Absolute VA pattern for `0x0046e4c0`: `0` hits.
- RVA pattern for `0x0006e4c0`: `0` hits.
- Absolute VA pattern for `0x0046e63c`: `0` hits.
- Absolute VA pattern for `0x0046e640`: `0` hits in simple dword scan; IDA and rel32 scanning still show the two constructor call xrefs.
- E8/E9 rel32 calls/jumps into `0x0046e4c0-0x0046e63c`: `0` hits.
- Conditional rel32 branches into the target: `5` hits, all internal branches from inside the helper body.
- Absolute VA values into `0x0046e4c0-0x0046e63c`: `15` hits, all inside the target body/table area. They are the three switch table base operands and the twelve table entries.
- RVA byte patterns into the target range: `10` external byte-pattern hits were found, but inspection showed they are incidental instruction bytes/immediates in unrelated code, not IDA xrefs, data pointers, or dispatch tables.
- First 32 target bytes occur once in the PE.

Conclusion: no external static route to the helper entry or body was found. The only real address-taken evidence is internal switch-table machinery.

## Ownership Analysis

### 1. [UID:0000G3] WebBoardDialogOld

Evidence for:

- The helper's mode/control rectangle constants exactly match [UID:0000ZA] `WebBoardDialogOldLayoutRefresh`, which rebuilds the old close button/browser child and applies old dialog bounds.
- The helper is bracketed by old WebBoard layout refresh and old WebBoard constructor ranges.
- [UID:0000ZB] `WebBoardDialogOldConstructor` is live with two direct callers, installs old WebBoard vtables, writes old singleton `0x0067aba0`, and uses `WEBBOARD.EPD` / `WEBBOARD.PAD`.
- [UID:0000G3] already documents this range as the old mode/control rectangle helper, and its parent gate is `88/85`.
- Neighboring old WebBoard raw helpers with no IDA function objects are already modeled in this class/file corridor.

Evidence against:

- The helper has no IDA function object, inbound xrefs, or raw PE entry pointer.
- It does not use `this`; the binary shape is a stack-cleaning three-argument helper, not an ordinary instance `__thiscall` method.

Decision: accept [UID:0000G3] as direct semantic owner, with an explicit static/file-local helper caveat. Emit through the class-to-file route, not as final C++.

### 2. [UID:0000P9] WebBoardDialog file

Evidence for:

- [UID:0000P9] is the correct source module for active and old browser-backed web-board code.
- Current target metadata already routes through [UID:0000P9].
- The helper is stack-only and could be a file-local helper rather than a class method.

Evidence against:

- [UID:0000G3] now clears the direct-parent gate and is a narrower semantic owner for old-variant-only rectangle constants.
- File-level direct ownership loses the old-class source relationship already documented by neighboring pages.

Decision: keep [UID:0000P9] as source module, not direct owner.

### 3. BoardDialogs

Evidence for:

- WebBoardDialog is part of the broader board dialog feature family.

Evidence against:

- [UID:0000P9] is already the narrower WebBoard source module, and [UID:0000G3] is the narrower class owner.

Decision: reject direct BoardDialogs ownership.

### 4. RankingDialog / Ranking Pollution

Evidence for:

- Existing docs mention stale generated output previously placed old WebBoard methods under Ranking.

Evidence against:

- [UID:0000G3], [UID:0000P9], and [UID:0000HT] all identify that as generated owner pollution.
- The helper uses old web-board layout constants and sits between old web-board layout/constructor code. It has no ranking dialog state, vtable, resource, or packet semantics.

Decision: reject Ranking ownership.

### 5. Generic Rect Helper

Evidence for:

- The body only fills a caller-provided rectangle and uses no class fields.

Evidence against:

- The constants are feature-specific old web-board layout constants, not a generic geometry algorithm.
- The body is unique in the PE and has no non-WebBoard route.

Decision: reject generic utility ownership.

### 6. No-owner / non-emitting raw island

Evidence for:

- No IDA function object, xrefs, rel32 route, or pointer route to `0x0046e4c0`.

Evidence against:

- The helper is source-shaped and unique.
- It is semantically tied to adjacent old WebBoard layout code by exact rectangle constants.
- The local switch tables are compiler-generated implementation detail for source-level switches, not standalone binary artifact.
- Existing sibling raw WebBoard helpers are treated as reconstructable with explicit no-xref caveats.

Decision: reject non-emitting classification. Keep reconstructable but leave final C++ blank.

### 7. Compiler artifact only

Evidence for:

- `0x0046e609-0x0046e60c` and `0x0046e60c-0x0046e63c` are compiler-generated alignment/table bytes.

Evidence against:

- `0x0046e4c0-0x0046e609` is handwritten source behavior compiled to code: mode checks, selector checks, rectangle writes, and a clear case.

Decision: reject for the page as a whole. Document compiler tables internally.

## Final C++ Eligibility

Not eligible for final C++.

Resolved:

- Exact body/table/padding boundaries.
- Exact switch-table contents and ownership.
- Exact rectangle constants and selector behavior.
- Source-authored versus compiler-generated partition.
- Ranking pollution rejection.
- WebBoardOld semantic owner/source module route.

Still blocking final C++:

- No static liveness route to `0x0046e4c0`.
- No original helper name.
- No original declaration shape. The binary is stack-cleaning and no-`this`; the source may have been a file-local `__stdcall` helper, a static member with explicit calling convention, or equivalent compiler-specific shape.
- Selector/mode enum names are inferred only from behavior.
- `Rect` type/member names and `sub_4B78D0` final source name are not final.

These blockers justify `85/88` and blank final C++, but not a below-gate score.

## Split Decision

Do not split [UID:000211].

Reasons:

- The tables are referenced only by the helper's own switch instructions.
- The internal NOP/alignment bytes are not an external gap and should not create an ignored row inside a precise source item.
- A separate non-emitting table child would add noise without improving ownership or source reconstruction.

No new UID allocation is needed.

## Exact Supervisor Edits

### Target metadata

Update `by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md`:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000G3
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000G3
```

Keep the filename and title unchanged. Keep final C++ blank.

Add this status note:

```markdown
- Direct owner: [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), as a class-scoped static/file-local old-mode rectangle helper. The binary does not consume `ecx` as `this` and returns with `retn 0Ch`, so do not describe it as an ordinary instance method.
- Source module route: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md).
- Final C++ status: blank because no static caller/pointer route, original helper name, enum names, or calling-convention declaration is proven.
```

Add this B001 evidence note:

```markdown
- 2026-06-16 B001 live IDA/raw PE recheck: IDA still reports no function object at `0x0046e4c0`, `0x0046e609`, `0x0046e60c`, `0x0046e61c`, `0x0046e62c`, or `0x0046e63c`; no xrefs target `0x0046e4c0`; raw PE scanning found no entry VA/RVA pointer, no E8/E9 rel32 route into the target, and no external absolute-VA pointer into the body. The only real address references into the page are the helper's three switch table base operands and twelve local table entries. The `0x0046e609-0x0046e60c` bytes are `0f 1f 00` internal alignment before the local switch tables.
```

### Support docs

`by-class/WebBoardDialogOld.md`

- Replace the method row for `mode/control rect helper` with:

```markdown
| mode/control rect helper | [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) | Class-scoped static/file-local helper that returns old mode/control rectangles for modes `0`, `4`, and `6`; B001 2026-06-16 confirms no IDA function object or external caller/pointer route, so final C++ remains blank. |
```

`by-file/WebBoardDialog.md`

- Update the [UID:000211] evidence sentence to:

```markdown
- B001 live IDA/raw PE recheck on 2026-06-16 confirms [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) as a class-scoped old WebBoard rectangle helper with local compiler switch tables; direct owner/emitter should be [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), with this file as the source module route. No external caller/pointer route to the raw entry was found.
```

`by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`

- Add:

```markdown
- B001 2026-06-16 confirms [UID:000211] carries the same old mode/control rectangle families as this layout helper, but there is still no IDA/static PE call from `sub_46E2A0` to `0x0046e4c0`; treat [UID:000211] as a related class-scoped raw helper, not as a proven callee of this function.
```

No score changes are required for these support docs.

### Ignored ledger

No `by-memory/-ignored.md` change is required.

Do not add an ignored row for `0x0046e609-0x0046e60c`; it is internal alignment inside [UID:000211]. Existing rows for `0x0046e4b6-0x0046e4c0` and `0x0046e63c-0x0046e640` remain valid.

### Coverage row

Replace the current [UID:000211] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md) 0x0046e4c0-0x0046e63c | static class helper/switch-table | WebBoardDialogOldModeRectHelper : reconstructable : 85% : strong : B001 2026-06-16 live IDA/raw PE audit confirms one source-shaped old WebBoard rectangle helper body at `0x0046e4c0-0x0046e609`, internal alignment `0x0046e609-0x0046e60c`, and three local compiler switch tables at `0x0046e60c`, `0x0046e61c`, and `0x0046e62c`; no IDA function object, inbound xrefs, entry VA/RVA pointer, external absolute-VA pointer, or E8/E9 rel32 route to the raw entry/body was found, while the only real address refs into the page are the helper's own switch operands/table entries. The helper writes WebBoardDialogOld mode/control rectangles for modes `0`, `4`, and `6`, calls the rectangle setter `sub_4B78D0`, clears only selector `3`, and otherwise returns without modifying null/invalid inputs. Reroute direct owner/emitter to [UID:0000G3] `WebBoardDialogOld` while keeping [UID:0000P9] `WebBoardDialog` as source module; reject RankingDialog, generic rectangle utility, non-emitting raw island, and separate table-child classifications. Final C++ remains blank pending caller/source-name/calling-convention and field/type/name resolution.
```

### IDA DB normalization

No IDA DB edit is required for this documentation batch.

Optional future normalization, if the supervisor runs a deliberate IDA cleanup pass:

- Define code/function body `0x0046e4c0-0x0046e609`.
- Mark `0x0046e609-0x0046e60c` as alignment/NOP.
- Mark `0x0046e60c-0x0046e63c` as three four-entry dword switch tables.
- Do not include the switch table bytes inside the IDA function extent.

This is optional because the documentation and coverage report can accurately represent the range without mutating the IDB.

## Validation Plan

After supervisor applies edits:

> Executable block R001 was removed from this report and preserved verbatim in [000211-webboard-oldmode-raw-rect-source-route-removed.md](000211-webboard-oldmode-raw-rect-source-route-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- [UID:000211] validates at `85/88` and leaves Low_Completion.
- No new memory gap or overlap appears.
- No UID allocation is needed.
- Generated memory coverage routes [UID:000211] through [UID:0000G3] to [UID:0000P9] instead of directly to [UID:0000P9].

## Work Performed

Created/updated only:

```text
tools/leaser/Agents/Agent-B001/research/000211-webboard-oldmode-raw-rect-source-route.md
```

No by-* docs, generated reports, coverage report, or IDA DB were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000211-webboard-oldmode-raw-rect-source-route.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"000211"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000211-webboard-oldmode-raw-rect-source-route-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000211-webboard-oldmode-raw-rect-source-route.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000211"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
