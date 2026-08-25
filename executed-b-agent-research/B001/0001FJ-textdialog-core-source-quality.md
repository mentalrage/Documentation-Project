** TARGET-REPORT-UID:0001FJ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001FJ TextDialogCore Source Quality / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: split [UID:0001FJ] into exact constructor/action children, reclassify [UID:0001FJ] as a non-emitting split index, and document the internal switch/padding/raw no-route tail separately.
- Final disposition: [UID:0001FJ] should not remain a reconstructable emitting source page because it mixes two class methods, compiler switch data, padding, and an unmodeled no-xref raw code island.
- Required action: supervisor should create the child pages and support-doc updates below; do not edit `by-memory/-coverage-report.md` until the temporary ban is lifted or supervisor applies the rows.
- Confidence: high for the split/ownership recommendation; medium-high for constructor packet/control source names because two constructor flags and several child-control roles remain below final-C++ quality.

## Supporting Research

## Target
- Target UID: `0001FJ`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00552110-0x005534a0.TextDialogCore.md`
- Assignment: `B001-goal2-textdialog-core-source-quality-0001FJ-20260616`
- Current scores and parent state: `COMPLETION:82`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000OL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OL`.
- Current coverage row issue: `by-memory/-coverage-report.md` still describes the row as `0x00552110-0x00553609` and mentions stale region-selection ownership, even though the page path and target were narrowed to `0x00552110-0x005534a0`.

## Executive Recommendation
- Create source-bearing children:
  - `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`, assumed next UID `0003VQ`, `85/88`, owner/emitter [UID:0000EL].
  - `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`, assumed next UID `0003VR`, `86/90`, owner/emitter [UID:0000EL].
- Create one non-emitting raw/no-route child:
  - `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md`, assumed next UID `0003VS`, `85/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter.
- Add ignored ledger rows for:
  - `0x0055317a-0x00553180` constructor-to-action `0xcc` alignment.
  - `0x00553338-0x00553350` `sub_553180` jump table plus `0xcc` alignment.
  - `0x00553495-0x005534a0` raw-island-to-proxy-callback `0xcc` alignment.
- Reclassify [UID:0001FJ] as a reviewed non-emitting split index: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000EL`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Update [UID:0000EL] `TextDialog`, [UID:0000OL] `TextDialog`, [UID:0001FG] `DialogNavigationPacketHelpers`, and `by-project-structure/proposed-source-tree.md` to remove stale `TextDialog` ownership of `0x005534a0-0x00553609`.

Assumed UIDs are based on a documentation-only scan on 2026-06-16 showing `0003VP` as the highest existing UID. If another agent allocates UIDs first, keep the same filenames/ranges and substitute the validator-assigned UIDs consistently.

## Supervisor Active Recheck
- This was an explicitly assigned report-only B-agent task. I did not edit by-* docs, generated reports, or `by-memory/-coverage-report.md`.
- The assigned item requires split repair before final source-quality work because it currently combines source methods and non-source/no-route tail bytes.
- Every source-bearing child in scope has either a concrete proposed child page and owner/emitter route or a documented blocker. The raw `0x00553350` island was investigated for function status and xrefs before recommending no emission.

## Inference Research Guidance Check
- `by-structure.md` drives the direct-owner recommendation: exact class methods should attach to the narrow class owner [UID:0000EL], not directly to the by-file page [UID:0000OL].
- `inference_research.md` affected the raw-island decision: address adjacency to `TextDialog` is evidence, but no caller/xref route means the no-route island should not be promoted to emitted source.
- Existing documentation was treated as a lead, not authority. IDA MCP confirmed several facts but contradicted the current "local switch/alignment tail" wording because `0x00553350-0x00553495` contains code-like bytes.

## Evidence Standards Used
- IDA MCP session: `a001_goal2_00023O`, `NexusTK.exe`, queried on 2026-06-16.
- Evidence types used: `lookup_funcs`, `analyze_component`, `analyze_function`, `decompile`, `disasm`, `trace_data_flow`, `search_text`, `entity_query`, `make_signature_for_range`, local documentation, generated coverage reports, and `int_convert.py`.
- Size conversions used below were verified with `int_convert.py`: `0x106a` = `4202`, `0x1b8` = `440`, `0x145` = `325`, `0x278` = `632`, and `0x304` = `772`.

## IDA MCP Facts
- `lookup_funcs`:
  - `0x00552110` is `sub_552110`, size `0x106a`, half-open end `0x0055317a`.
  - `0x00553180` is `sub_553180`, size `0x1b8`, half-open end `0x00553338`.
  - `0x00553338` is not a function.
  - `0x005534a0` is `sub_5534A0`, size `0x169`, the already-split Nexonclub proxy callback.
  - `0x00553610` is `sub_553610`, size `0x2ed`, the Nexonclub proxy constructor.
- Constructor facts:
  - `sub_552110` stores TextDialog vtables at `0x00552161`, `0x00552167`, and `0x00552171`.
  - Constructor callers/xrefs are four dispatcher wrappers at `0x0054c8b7`, `0x0054c917`, `0x0054c977`, and `0x0054c9d7`.
  - The wrappers allocate `0x278` bytes and pass packet plus two variant flags: `(1,0)`, `(0,0)`, `(1,1)`, and `(0,1)`.
  - The constructor stores dialog reply fields at `this+0x26c`, `this+0x270`, `this+0x274`, and `this+0x276`; `search_text` found duplicate stores at `0x005521a0`/`0x0055293c`, `0x005521af`/`0x0055294b`, `0x005521ff`/`0x0055299b`, and `0x00552212`/`0x005529ae`.
  - `byte_66DA97` selects the duplicated resource/layout branch. One branch uses `DLGMSG5.EPF`, `DLGMSG5.PAL`, and `DLGMSG6.EPF`; the other uses `DLGMSG5.EPD`, `DLGMSG51.EPD`, and `DLGMSG6.EPD`.
- Action handler facts:
  - `sub_553180` has no ordinary callers but has a vtable data xref at `0x006229a0`, which contains `dd offset sub_553180`.
  - It switches on action values `1..4`.
  - Case `1` reads the child at `this+0x1fc`, calls a virtual method at `+0x10` with argument `6`, copies the text through `sub_498C10`, converts wide text to multibyte, builds opcode `0x3a`, writes `this+0x26c`, `this+0x270`, `this+0x274`, `this+0x276 + 1`, a literal subcommand byte `2`, length, and text bytes, then queues through `dword_67A7EC` / `sub_574BB0`.
  - Cases `2`, `3`, and `4` call `0x0054cc30`, `0x0054ccd0`, and `0x0054cd70` respectively, then close the dialog via `sub_49DAD0`.
- Tail facts:
  - `make_signature_for_range 0x00553170-0x00553180` shows the constructor final epilogue/range-check call through `0x0055317a`, followed by six `0xcc` bytes through `0x00553180`.
  - `trace_data_flow` on `0x00553338` shows `jpt_5531A3` is referenced only by `0x005531a3` inside `sub_553180`.
  - `0x00553338-0x00553348` is the four-entry switch table; `0x00553348-0x00553350` is `0xcc` alignment.
  - `0x00553350` is not an IDA function and has no xrefs in `trace_data_flow`; IDA still renders the first byte as `push ebp`.
  - `make_signature_for_range 0x00553338-0x005534a0` shows a code-like raw island beginning at `0x00553350`. The island has a valid epilogue ending `retn 4` at `0x0055348d-0x00553490`, an out-of-line `___report_rangecheckfailure` call at `0x00553490-0x00553495`, and `0xcc` alignment from `0x00553495-0x005534a0`.
  - `trace_data_flow` on `0x005534a0` confirms the Nexonclub proxy constructor stores `offset sub_5534A0` at `0x00553895`.

## Function / Child Inventory
| Range / Item | Proposed UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00552110-0x0055317a` | `0003VQ` / `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md` | `TextDialog` constructor, packet parse, layout/control construction | TRUE | [UID:0000EL] | `85/88` | Create |
| `0x0055317a-0x00553180` | [UID:0000VN] ignored ledger | Constructor-to-action alignment | FALSE | none | `100/strong` | Add ignored row |
| `0x00553180-0x00553338` | `0003VR` / `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` | vtable-dispatched action handler | TRUE | [UID:0000EL] | `86/90` | Create |
| `0x00553338-0x00553350` | [UID:0000VN] ignored ledger | Action switch table and padding | FALSE | none | `100/strong` | Add ignored row |
| `0x00553350-0x00553495` | `0003VS` / `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` | Code-like no-xref submit-packet clone/raw island | FALSE | NONE | `85/86` | Create non-emitting child |
| `0x00553495-0x005534a0` | [UID:0000VN] ignored ledger | Alignment before proxy callback | FALSE | none | `100/strong` | Add ignored row |
| `0x005534a0-0x00553609` | [UID:0003GL] | Nexonclub proxy reply callback | TRUE | [UID:00009H] | Existing `86/90` | Keep separate |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0054c8b7` | calls `0x00552110`, flags `(1,0)` | TextDialog wrapper variant, allocates `0x278`. |
| `0x0054c917` | calls `0x00552110`, flags `(0,0)` | TextDialog wrapper variant. |
| `0x0054c977` | calls `0x00552110`, flags `(1,1)` | TextDialog wrapper variant. |
| `0x0054c9d7` | calls `0x00552110`, flags `(0,1)` | TextDialog wrapper variant. |
| `0x00622958` | TextDialog primary vtable | Constructor store at `0x00552161`. |
| `0x006229a0` | `dd offset sub_553180` | Action handler vtable slot; no ordinary direct callers expected. |
| `0x005531a3 -> 0x00553338` | switch jump xref | Proves `0x00553338-0x00553348` is `sub_553180` support data. |
| `0x00553350` | no xrefs found | Blocks reconstructable/emitter promotion for the raw code-like island. |
| `0x00553895 -> 0x005534a0` | member-function pointer store | Proves `0x005534a0` belongs to NexonclubProxyDialog callback, not TextDialog. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:0003DC] `TextDialogVtableData` records TextDialog vtable xrefs from constructor stores and supports [UID:0000EL] class ownership.
  - [UID:00023M] `MessageDialogPacketDispatcherAndWrappers` records the four TextDialog wrappers and the separate Nexonclub/head-select wrappers.
  - [UID:0003GL] and [UID:0001FK] prove `0x005534a0-0x00553609` is a Nexonclub proxy callback installed by `0x00553895`.
  - [UID:0001FI] records the HeadSelect end at `0x005520e5` and ignored `0x005520e5-0x00552110` switch/alignment boundary before TextDialog.
- Existing docs that are stale or incomplete:
  - [UID:0001FJ] describes `0x00553338-0x005534a0` as a local switch/alignment tail; IDA bytes show a code-like no-xref island at `0x00553350-0x00553495`.
  - [UID:0000EL] `TextDialog` still lists `0x005534a0-0x00553609` as `SendRegionSelectionPacket` and says Nexonclub reuses the callback target; this contradicts the later split.
  - [UID:0000OL] `TextDialog` still lists `0x00553338-0x005534a0` only as non-source tail and should be updated for the raw no-route island.
  - [UID:0001FG] caller matrix still labels `0x005534a0` as a TextDialog region-selection helper; it should say NexonclubProxyDialog reply callback invalid/empty text fallback.
  - `by-project-structure/proposed-source-tree.md` still says `TextDialog` owns `0x00552110-0x00553609` and "region-selection replies".
  - `by-memory/-coverage-report.md` still has stale `0x00552110-0x00553609` row text.

## Ranked Ownership Analysis

### 1. [UID:0000EL] TextDialog class
- Evidence for: constructor stores TextDialog vtables; action handler is in TextDialog vtable data at `0x006229a0`; both source-bearing methods use `this+0x26c/0x270/0x274/0x276` dialog reply fields and TextDialog child controls; wrappers dispatch directly to the constructor as part of the dialog packet family.
- Evidence against: the broad current page also includes non-source/no-route bytes; [UID:0000EL] itself has stale `0x005534a0` wording that needs cleanup before raising it much.
- Decision: best direct owner for the two real method children and best canonical owner for the non-emitting split index after support cleanup.

### 2. [UID:0000OL] TextDialog file
- Evidence for: file page is the generated source root `NexusTK/ui/dialogs/TextDialog.cpp` and owns the class/source module context.
- Evidence against: by-structure requires direct semantic owners where possible; method bodies should attach to class [UID:0000EL], with the class emitting through file [UID:0000OL].
- Decision: keep as source-file/emitter route through [UID:0000EL], not direct owner for exact method children.

### 3. [UID:0000LA] MessageDialogs / shared dialog packet infrastructure
- Evidence for: the dispatcher/wrapper island creates `TextDialog`, and shared helpers `0x0054cc30-0x0054ce0f` are cross-dialog packet helpers.
- Evidence against: `0x00552110` and `0x00553180` are class-specific constructor/action methods with TextDialog vtables and fields, not dispatcher helpers.
- Decision: reject as direct owner for [UID:0001FJ] children; keep as caller/source-neighbor context.

### 4. [UID:0000JT] HeadSelectDialog
- Evidence for: address adjacency before `0x00552110`.
- Evidence against: HeadSelect `OnAction` ends at `0x005520e5`; ignored switch/alignment covers `0x005520e5-0x00552110`; TextDialog constructor begins with TextDialog vtable stores.
- Decision: rejected.

### 5. [UID:0000LZ] / [UID:00009H] NexonclubProxyDialog
- Evidence for: owns `0x005534a0-0x00553609`; callback body uses the same opcode `0x3a` reply layout and shared helper.
- Evidence against: the TextDialog constructor/action ranges end before `0x005534a0`; `trace_data_flow` proves `0x005534a0` is installed by Nexonclub constructor, not TextDialog.
- Decision: keep Nexonclub callback separate; update stale TextDialog docs to stop calling it TextDialog region-selection source.

### Proposed new file/grouping
- Proposed owner/name/path: no new by-file source root recommended now.
- Likely full contents if created later: a small `DialogPacketHelpers.cpp` or private helper section could own `0x0054cc30-0x0054ce0f` previous/next/current helpers and possibly shared reply serialization concepts used by MessageDialog/MenuQuestion/TextDialog/Nexonclub.
- Candidate related items that belong: [UID:0001FG] only, if the project wants to stop staging it under TextDialog.
- Candidate related items rejected: [UID:0001FJ] constructor/action, [UID:0003GL] Nexonclub callback, and [UID:00023M] dispatcher should stay with their class/file owners.
- Standalone, narrow, or broad source-file inference: narrow helper grouping only; not needed to complete this assignment.

## Negative Evidence Summary
- Checked IDA function list: no function at `0x00553350`, no function at `0x00553338`.
- Checked `trace_data_flow`:
  - `0x00553338` is referenced by the action handler switch.
  - `0x00553350` has no backward xrefs.
  - `0x005534a0` has a method-pointer store from `0x00553895`, proving proxy ownership.
- Checked broad listing search for `553350`: no hit before MCP cancelled at `0x004a1000`; this is incomplete as a whole-image proof, but the scoped xref query already found no IDA xrefs to the raw island entry.
- Checked constructor wrappers: the four callers pass flag combinations into `0x00552110`, not into the raw island.
- Consumer/read xrefs to shared helpers do not prove helper ownership; they only prove [UID:0001FG] must remain shared-aware.

## Exact Metadata Changes Recommended
Target parent:
```text
by-memory/0x00552110-0x005534a0.TextDialogCore.md
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000EL
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:[[[]]]
```

New constructor child:
```text
*** UID:0003VQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

New action child:
```text
*** UID:0003VR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

New raw/no-route child:
```text
*** UID:0003VS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Support score changes after cleanup:
```text
by-class/TextDialog.md: 86/86 -> 87/88
by-file/TextDialog.md: 88/87 -> 89/88
by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md: keep 86/88, keep owner/emitter 0000OL, update stale caller label only.
```

No `95+` recommendation is justified. Constructor packet-struct names, two wrapper flag names, child-control field names, and the raw island reachability remain below final-audit quality.

## Exact Support-Doc Changes Recommended
- [UID:0000EL] `by-class/TextDialog.md`:
  - Replace method map `0x005534a0-0x00553609 SendRegionSelectionPacket` with a note that this is [UID:0003GL] NexonclubProxyDialog.
  - Add method rows for proposed [UID:0003VQ] and [UID:0003VR].
  - Add a non-source/no-route support row for `0x00553338-0x005534a0`.
  - Replace "Neighboring NexonclubProxyDialog reuses the region-selection callback target" with "Neighboring NexonclubProxyDialog owns [UID:0003GL]; TextDialog shares only the opcode `0x3a` field layout/helper concepts."
- [UID:0000OL] `by-file/TextDialog.md`:
  - Replace Function Map constructor range with `0x00552110-0x0055317a`.
  - Replace action range with `0x00553180-0x00553338`.
  - Replace tail row with exact ignored/no-route rows: `0x0055317a-0x00553180`, `0x00553338-0x00553350`, `0x00553350-0x00553495`, `0x00553495-0x005534a0`.
  - Keep [UID:0001FG] as staged helper owner for now but preserve shared-helper caveat.
- [UID:0001FG] `DialogNavigationPacketHelpers`:
  - Change the caller table row `0x005534a0 TextDialog region selection helper` to `0x005534a0 NexonclubProxyDialog reply callback`.
  - State that `0x0054cd70`'s extra caller is proxy invalid/empty callback text fallback, not a TextDialog method.
- `by-project-structure/proposed-source-tree.md`:
  - Replace line saying `TextDialog` owns `0x00552110-0x00553609` and region-selection replies with: `TextDialog` owns the constructor/action source methods at `0x00552110-0x0055317a` and `0x00553180-0x00553338`; the local `0x00553338-0x005534a0` tail is switch data, padding, and a no-route raw island; `0x005534a0-0x00553609` belongs to `NexonclubProxyDialog`.
- `by-memory/-ignored.md`:
  - Add `0x0055317a-0x00553180`, `0x00553338-0x00553350`, and `0x00553495-0x005534a0` to dialog/container boundary ignored entries with the evidence summarized above.

## Exact Pending `by-memory/-coverage-report.md` Replacement Block
Replace the current [UID:0001FJ] row at the existing `0x005520e5` / `0x005534a0` location with:

```text
    - [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md) 0x00552110-0x005534a0 | split-index | TextDialogCore : ignored/non-emitting : 88% : very strong : B001 2026-06-16 source-quality audit reclassifies this broad TextDialog cluster as a non-emitting split index over the exact constructor/action children, internal switch table, alignment, and no-route raw submit-packet island. The real source-bearing children route through [UID:0000EL][TextDialog](by-class/TextDialog.md); parent C++ remains blank.
      - [UID:0003VQ][0x00552110-0x0055317a.TextDialogConstructor](by-memory/0x00552110-0x0055317a.TextDialogConstructor.md) 0x00552110-0x0055317a | class constructor | TextDialogConstructor : reconstructable : 85% : strong : IDA confirms `sub_552110` size `0x106a`, four dispatcher wrapper callers, TextDialog vtable stores, dialog reply field stores at `this+0x26c/0x270/0x274/0x276`, `DLGMSG5`/`DLGMSG51`/`DLGMSG6` resource/layout branches, and child ObjectImage/StaticText/TextEdit/control construction. Final C++ remains blank pending final packet struct, wrapper flag, and child-control field names.
      - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055317a-0x00553180 | alignment padding | TextDialog constructor to action alignment : ignored : 100% : strong : IDA bytes show six `0xcc` bytes after the constructor range-check tail and before `sub_553180`.
      - [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md) 0x00553180-0x00553338 | virtual action handler | TextDialogHandleDialogAction : reconstructable : 86% : very strong : IDA confirms `sub_553180` size `0x1b8`, vtable data xref at `0x006229a0`, action cases `1..4`, typed-text opcode `0x3a` reply serialization through `g_packetSender`, and previous/next/current helper calls. Final C++ remains blank pending final child-control/member names.
      - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553338-0x00553350 | switch table / padding | TextDialog action switch table and alignment : ignored : 100% : strong : `jpt_5531A3` is referenced only by the action switch at `0x005531a3`; `0x00553348-0x00553350` is `0xcc` alignment.
      - [UID:0003VS][0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw](by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md) 0x00553350-0x00553495 | no-route raw code island | TextDialogUnreferencedSubmitPacketRaw : ignored/non-emitting : 85% : strong : IDA has no function at `0x00553350` and no xrefs to the entry; bytes decode as a TextDialog-like opcode `0x3a` submit-packet clone ending with `retn 4` plus range-check tail. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitter unless a live pointer/caller route is found.
      - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00553495-0x005534a0 | alignment padding | raw island to Nexonclub proxy callback alignment : ignored : 100% : strong : IDA bytes show `0xcc` alignment before [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md).
```

## Final-C++ Eligibility
- Proposed [UID:0003VQ] constructor: average score `86.5` and emitter route would satisfy the minimum combined-score/emitter gate, but final C++ should remain blank because packet-struct names, wrapper flag names, local layout objects, and child-control member names are not source-grade.
- Proposed [UID:0003VR] action handler: average score `88` and emitter route would satisfy the minimum gate, but final C++ should remain blank until `this+0x1fc`, `this+0x26c/0x270/0x274/0x276`, and the action/subcommand names are finalized.
- Proposed [UID:0003VS] raw island: not eligible. It has no function record, no xrefs, no owner/emitter, and should not be emitted.
- Parent [UID:0001FJ]: not eligible after reclassification; it is a split index.

## Follow-Up Actions
- Supervisor actions:
  - Apply the split/reclassification if accepted.
  - Allocate actual UIDs and replace assumed `0003VQ`/`0003VR`/`0003VS` if already taken.
  - Apply the exact coverage block above.
- A-agent actions:
  - Improve constructor source names: packet struct, two wrapper flags, dialog mode/resource branch names, and child-control field roles.
  - Improve action handler source names: `this+0x1fc` text-edit child, action enum values, opcode `0x3a` reply struct, and subcommand byte `2`.
  - Correct stale TextDialog/Nexonclub/shared-helper support wording.
- B001 future research actions:
  - If a later whole-image pointer search or runtime trace finds a route to `0x00553350`, reopen [UID:0003VS] for owner/emitter reassessment.
  - Consider a separate shared dialog packet helper source only if [UID:0001FG] remains a blocker after nearby MessageDialog/TextDialog source work.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high. Constructor stays only `85/88` because it is complex and field/control names remain unresolved; action can reach `86/90`; raw island can reach `85/86` only for no-route classification, not for reconstructable source.
- Remaining uncertainty: exact original names for the constructor variant flags, packet struct fields, control-member fields, and the reason the no-xref raw island remains in `.text`.

## Validator Results
- Commands run during research:
  - IDA MCP `lookup_funcs`, `analyze_component`, `analyze_function`, `decompile`, `disasm`, `trace_data_flow`, `search_text`, `entity_query`, and `make_signature_for_range`.
  - `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py` for cited size conversions.
- No documentation validator was run because this was report-only and no by-* files were edited.
- Recommended validation after supervisor applies changes:
> Executable block R001 was removed from this report and preserved verbatim in [0001FJ-textdialog-core-source-quality-removed.md](0001FJ-textdialog-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0001FJ-textdialog-core-source-quality.md`
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001FJ-textdialog-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001FJ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001FJ-textdialog-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001FJ-textdialog-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001FJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
