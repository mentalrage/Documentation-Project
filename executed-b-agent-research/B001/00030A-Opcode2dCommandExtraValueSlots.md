** TARGET-REPORT-UID:00030A **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00030A Opcode2dCommandExtraValueSlots Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: [UID:00030A][0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots](../../../../../by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md) is now assigned to [UID:0000P1][UserPane](../../../../../by-file/UserPane.md) as file-level local-player command state, not to the [UID:0000FQ][UserPane](../../../../../by-class/UserPane.md) class page and not to `IconsPane`, `TabPane`, `MapPane`, `Socket`, `g_useEpfAssets`, or the generated one-helper recovered file.
- Final disposition: exact two-dword source-bearing child; no split required. Reclassify from `reviewed-85-but-ownership-unknown-under-review` to assigned shared local-player command state after the supervisor applies the pending coverage-report row.
- Required action: only the `by-memory/-coverage-report.md` row remains supervisor-owned and stale. The target page now has `AUTOGEN_PARENT_UID:0000P1`, `COMPLETION:87`, `CONFIDENCE:89`, and the parent [UID:0000P1] page now records this as file-level command state.
- Confidence: `86/100` for the `UserPane.cpp` file-owner inference; `96/100` for exact storage/boundary/write facts; `94/100` for opcode/send/store behavior. Confidence is not higher because no PDB, linker map, source path, or original symbol name is present.

Do not create a standalone source file named `SendOpcode2DAndStoreExtra_005A4F70.cpp` in project documentation. That file exists in recovered generated output as a Wave2/Wave3 artifact and is useful as behavior evidence, but it is not a good original-source layout model. If the supervisor wants a narrower documentation grouping before or after assignment, create it as a UserPane-owned local-player command helper grouping, not as an independent source root.

## Exact by-memory/-coverage-report.md Replacement Row

Placement: replace only the existing [UID:00030A] row currently between [UID:000309] `g_pChatInputPane` and [UID:00030B] `g_lastFunctionKeyTick` inside the [UID:0002A3] `KeyboardInputCommandStateGlobals` split-map block. Keep the surrounding rows unchanged.

```markdown
        - [UID:00030A][0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots](by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md) 0x0069bf6c-0x0069bf74 | global-data dword pair | Opcode2dCommandExtraValueSlots : reconstructable : 87% : very-strong : Assigned to [UID:0000P1][UserPane](by-file/UserPane.md) as file-level local-player command state, not as a UserPane class field. Live IDA B001-053 confirms exact `0xffffffff` dwords, no tail-byte refs, four write xrefs only, the shared `0x005a4f70` opcode `0x2d` send/store helper, caller fan-in from IconsPane, raw Icons dispatch, TabPane, and MapPane, plus the duplicate `UserPane::OnKeyEvent` inline key-case store. IconsPane/TabPane/MapPane are consumers, `g_packetSender`/`g_useEpfAssets` are dependencies, and the generated one-helper recovered file is not original source-layout proof.
```

## Applied Target / Parent Page Changes

Applied metadata changes for `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md`:

```text
COMPLETION:87
CONFIDENCE:89
RECONSTRUCTABLE:TRUE
AUTOGEN_PARENT_UID:0000P1
```

Applied target-page prose changes:

- Add current IDA evidence that `0x005a4f70` has four code refs: `0x004cf6ef` in `IconsPane::OnMouseEvent`, raw `0x004cf920`, `0x004cfa61` in `TabPane::HandleInputEvent`, and `0x00507721` in `MapPane::OnMouseEvent`.
- Add current IDA evidence that `UserPane::OnKeyEvent` key case `0x73` duplicates the same `{0x2d, 0}` packet send and writes `dword_69BF6C` or `dword_69BF70` from the event extra value.
- Replace the old caveat "Attaching to UserPane would overclaim" with the narrower rule: attaching to the `UserPane` class would overclaim because the dwords are module-scope state, but attaching to the `UserPane` file is the best existing source-owner inference for the shared local-player command helper/state pair.
- Add a follow-up note that an exact helper page for `0x005a4f70-0x005a500f.SendOpcode2DAndStoreExtra` should be created later if the `0x005a4db0-0x005a50a0` action-helper neighborhood is split, but that missing helper page is not a blocker for this data-child assignment because the direct file parent and child both clear `85/85`.

Applied parent-page changes for `by-file/UserPane.md`:

- Add [UID:00030A] to `UserPane.cpp` proposed contents as opcode `0x2d` extra-value state.
- Clarify the `0x005a4930-0x005a5791` boundary note: most of that helper neighborhood remains outside `UserPane`, but [UID:00030A] and a future exact `0x005a4f70-0x005a500f` helper page are a narrow local-player command-state exception.
- Add 2026-06-12 B001-053 evidence and change-log bullets. Parent scores remain `89/85`; this was a scoped ownership anchor, not a full parent rescore.

## Supporting Research

## Target

- Target UID: `00030A`
- Target path: `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md`
- Source queue/report row: `Supervisor_notes.md`, B001-053, row for `reviewed-85-but-ownership-unknown-under-review`
- Current scores and parent state: now `COMPLETION:87`, `CONFIDENCE:89`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000P1`. Before this continuation the page was `85/89` with blank parent.
- Existing coverage row: parent blank because prior research saw a split between old-HUD `IconsPane`/`TabPane` helper calls and `UserPane::OnKeyEvent` inline stores

## Executive Recommendation

Assign the two-dword storage to [UID:0000P1] `UserPane` as file-level local-player command state. This is a source-file assignment, not a class-field assignment. The command state is written only by one shared free helper and by one inline `UserPane::OnKeyEvent` key case. The helper is consumed by old-HUD and map input surfaces, but those callers pass user/object/action context into a local-player command sender; they do not own the declaration or lifetime of the stored state.

No split is needed for the target range:

- `0x0069bf6c` and `0x0069bf70` are both four-byte `.data` dwords initialized to `0xffffffff`.
- The two dwords share the same writers and are selected only by [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) / `byte_66DA97`.
- Byte-tail checks found no refs to `0x0069bf6d-0x0069bf6f` or `0x0069bf71-0x0069bf73`.
- Raw absolute-address pattern search found only the two direct instruction encodings for each address, matching the IDA xref set.

The existing [UID:0002A3][KeyboardInputCommandStateGlobals](../../../../../by-memory/0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md) split map remains correct and parent-blank. It still covers adjacent but unrelated `g_pChatInputPane`, opcode `0x2d` state, and function-key debounce dword. Only the exact [UID:00030A] child should be assigned.

## Supervisor Active Recheck

The B001-053 assignment asked for the ownership/source-layout question to be resolved rather than deferred because perfect source proof is absent. I rechecked the target with live IDA MCP and treated the existing docs as hypotheses.

Result:

- The assigned range itself is not mixed or overbroad.
- No child pages are required before the final recommendation.
- The previously documented caller set was incomplete: live IDA also finds a `MapPane::OnMouseEvent` call to the shared helper at `0x00507721`.
- The stronger interpretation is not "old-HUD versus UserPane"; it is "multiple UI input surfaces call or inline a shared local-player command helper."

## Inference Research Guidance Check

`inference_research.md` requires separating IDA fact, documentation evidence, and inference. Applied here:

- IDA fact: exact storage, initial values, write xrefs, helper body, caller fan-in, duplicated inline UserPane key path, and negative pointer/tail-byte evidence.
- Documentation evidence: `UserPane`, `IconsPane`, `TabPane`, `MapPane`, `SayModeHelpers`, generated recovered helper file, and proposed source-tree pages describe plausible source areas but are not original-source proof.
- Inference: `UserPane.cpp` is the best existing file owner because it is the local-player/user command surface, it already owns broad process-global local-player state such as `g_pCollectionData`, and it contains the only direct inline duplicate write path. The caller panes are consumers of a shared command action.

IDA string scan on the current IDB found no `RSDS`, `NB10`, `.pdb`, `.cpp`, `.cxx`, or `.h` strings. It found only three `NexusTK` URL/update strings. Therefore this report does not claim recovered source-file metadata.

## Evidence Standards Used

- IDA MCP `py_eval`: data item inspection, xrefs, per-byte xrefs, raw absolute-address pattern search, function boundaries, disassembly, decompilation snippets, caller inventories, and source-string breadcrumbs.
- Existing documentation: by-memory target, split-map aggregate, candidate by-file/by-class pages, generated recovered helper output, source-tree page, and coverage rows.
- Negative evidence: no dword-tail references, no additional absolute pointer/table refs to the slot addresses, no data refs to `0x005a4f70`, no PDB/source-path strings, and no constructor/destructor ownership for any consumer pane.

## IDA MCP Facts

Live IDA target:

- Path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`

Data item facts:

| Address | IDA name | Segment | Item size | Initial bytes | Direct xrefs |
| --- | --- | --- | ---: | --- | ---: |
| `0x0069bf6c` | `dword_69BF6C` | `.data` | 4 | `ff ff ff ff` | 2 |
| `0x0069bf70` | `dword_69BF70` | `.data` | 4 | `ff ff ff ff` | 2 |

Per-byte direct xref counts:

| Byte | Xrefs |
| --- | ---: |
| `0x0069bf6c` | 2 |
| `0x0069bf6d` | 0 |
| `0x0069bf6e` | 0 |
| `0x0069bf6f` | 0 |
| `0x0069bf70` | 2 |
| `0x0069bf71` | 0 |
| `0x0069bf72` | 0 |
| `0x0069bf73` | 0 |

Direct writes:

| Slot | Writer | Function | Instruction | Meaning |
| --- | --- | --- | --- | --- |
| `dword_69BF6C` | `0x005a4fba` | `0x005a4f70-0x005a500f` `sub_5A4F70` | `mov dword_69BF6C, eax` | helper stores extra value in EPF/current-layout mode |
| `dword_69BF70` | `0x005a4fff` | `0x005a4f70-0x005a500f` `sub_5A4F70` | `mov dword_69BF70, eax` | helper stores extra value in non-EPF/legacy mode |
| `dword_69BF6C` | `0x005a686f` | `0x005a5bd0-0x005a7422` `UserPane::OnKeyEvent` | `mov dword_69BF6C, esi` | inline key-case duplicate stores event extra value in EPF/current-layout mode |
| `dword_69BF70` | `0x005a68a4` | `0x005a5bd0-0x005a7422` `UserPane::OnKeyEvent` | `mov dword_69BF70, esi` | inline key-case duplicate stores event extra value in non-EPF/legacy mode |

Raw absolute-address scan:

- Little-endian `6C BF 69 00`: 2 hits, both inside the two known write instructions at `0x005a4fbb` and `0x005a6871`.
- Little-endian `70 BF 69 00`: 2 hits, both inside the two known write instructions at `0x005a5000` and `0x005a68a6`.

Helper body:

- IDA function `sub_5A4F70`: `0x005a4f70-0x005a500f`, size `0x9f`.
- Decompilation: builds `{45, 0}` through `sub_575380`, sends 2 bytes through `sub_574BB0((_BYTE *)dword_67A7EC, &Src, 2)`, then writes the caller argument to `dword_69BF6C` if `byte_66DA97 == 1`, otherwise `dword_69BF70`.
- Disassembly confirms opcode `0x2d` / decimal `45`, subtype `0`, [UID:0000Q5][g_packetSender](../../../../../by-global/g_packetSender.md) dependency through `dword_67A7EC`, and [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) slot selection through `byte_66DA97`.

Helper caller facts:

| Call site | Function / owner lead | IDA instruction | Meaning |
| --- | --- | --- | --- |
| `0x004cf6ef` | `IconsPane::OnMouseEvent` / [UID:00006B][IconsPane](../../../../../by-class/IconsPane.md) | `call sub_5A4F70` | old-HUD icon action case `2`, passes `0` |
| `0x004cf920` | raw [UID:00022Q][IconsPaneActionDispatchRawBody](../../../../../by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) | `jmp sub_5A4F70` | unmodeled/raw duplicate action case, passes `0` |
| `0x004cfa61` | `TabPane::HandleInputEvent` / [UID:0000EB][TabPane](../../../../../by-class/TabPane.md) | `call sub_5A4F70` | tab action code `0`, passes event field `+0x10c` |
| `0x00507721` | `MapPane::OnMouseEvent` / [UID:00007Q][MapPane](../../../../../by-class/MapPane.md) | `call sub_5A4F70` | map click/object action path, passes event field `+0x18` |

Inline UserPane facts:

- `UserPane::OnKeyEvent` at `0x005a5bd0-0x005a7422` contains a key-case block for case `0x73`.
- Decompilation around lines 709-727 reads `v44 = *(a2 + 268)`, sends the same `{45, 0}` packet through `sub_574BB0`, then writes `dword_69BF6C = v44` or `dword_69BF70 = v44` based on `byte_66DA97`.
- Disassembly at `0x005a6840-0x005a68ac` exactly matches the helper's send/store structure, with `esi` holding the event extra value.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069bf6c-0x0069bf74` | [UID:00030A] `Opcode2dCommandExtraValueSlots` | paired opcode `0x2d` extra-value slots | yes | [UID:0000P1] `UserPane` file | `87/89` applied | assigned |
| `0x005a4f70-0x005a500f` | no exact by-memory page; currently inside [UID:0001KO] `SayModeHelpers` mixed aggregate | shared `SendOpcode2DAndStoreExtra` free helper | yes | recommended future exact child under `UserPane.cpp` or a UserPane-owned local-player command helper grouping | not scored here | follow-up split, not blocker |
| `0x0069bf68-0x0069bf78` | [UID:0002A3] `KeyboardInputCommandStateGlobals` | mixed split map | no / ignored | none | `87/89` | keep parent blank |

## Documentation Evidence And IDA Status

- [UID:00030A] target page: IDA confirms the existing storage, four writes, helper behavior, and `g_useEpfAssets` split. The page now records the `MapPane::OnMouseEvent` helper caller and the file-level `UserPane` assignment.
- [UID:0002A3] split map: IDA confirms the aggregate is mixed and should remain non-emitting. This report changes only the exact opcode-state child recommendation.
- [UID:0000P1] `UserPane` by-file page: documentation already places `UserPane.cpp` under `NexusTK/ui/panels/`, owns local-player/user display and key-command handling, and clears the parent gate at `89/85`. IDA confirms the inline duplicate write block is inside `UserPane::OnKeyEvent`.
- [UID:0000FQ] `UserPane` class page: useful behavior evidence, but not the direct parent for this target because the target is module-scope dword state, not a class field or vtable artifact.
- [UID:00006B]/[UID:0000JZ] `IconsPane`: IDA confirms it calls the helper, but only as click-action consumer.
- [UID:0000EB]/[UID:0000OF] `TabPane`: IDA confirms it calls the helper, but only as tab-action consumer.
- [UID:00007Q]/[UID:0000L3] `MapPane`: IDA confirms the additional caller at `0x00507721`, but it is a map input consumer of the same local-player command action and does not touch the dwords directly.
- [UID:0000Q5] `g_packetSender`: IDA confirms the send dependency, but `Socket` owns packet-sender lifetime and this target is feature command state, not network sender storage.
- [UID:0000SW] `g_useEpfAssets`: IDA confirms the mode selector dependency, but it is a broad startup/layout flag and not the owner of per-command extra-value slots.
- Generated `source-3/simroot_v2/recovered/SendOpcode2DAndStoreExtra_005A4F70.cpp`: useful behavior lead. It emits both dwords into the one-helper recovered file and records caller notes, but its `recovered/` path, `wave2_import_default_owner` origin, and one-function filename make it generated structure rather than original source layout proof.

## Ranked Ownership Analysis

### 1. [UID:0000P1] `UserPane` by-file / `NexusTK/ui/panels/UserPane.cpp`

Evidence for:

- Direct parent clears gate: [UID:0000P1] is `89/85`.
- The target child already clears gate and should become `87/89` after the additional caller/negative-evidence update.
- `UserPane::OnKeyEvent` contains the only inline duplicate writer of the exact dword pair. This is stronger than consumer-only xrefs from `IconsPane`, `TabPane`, or `MapPane`.
- The semantics are local-player/user-command state: packet opcode `0x2d`, event extra value from keyboard/tab/map paths, and storage in mode-specific slots after the command is sent.
- `UserPane.cpp` already owns broad file-level local-player state by inference, including [UID:0000QK][g_pCollectionData](../../../../../by-global/g_pCollectionData.md), which is consumed by many other modules but lifetime-owned by the user/local-player pane.
- Source-tree context places `UserPane.cpp`, `IconsPane.cpp`, and `TabPane.cpp` as adjacent UI panel modules. A helper in `UserPane.cpp` can reasonably be called by map and old-HUD input surfaces when the operation is a local-player command.

Evidence against:

- `0x005a4f70` is a free `__stdcall` helper, not a `UserPane` method.
- The helper has direct callers from `IconsPane`, raw Icons dispatch, `TabPane`, and `MapPane`.
- The exact helper currently lacks a dedicated by-memory page and sits in a mixed [UID:0001KO] `SayModeHelpers` neighborhood.
- No source metadata proves the literal original declaration file.

Decision: best existing direct owner. Attach to the file page, not the class page. The cross-pane caller fan-in proves the helper is shared; it does not make each caller a better declaration owner.

### 2. New narrow UserPane-owned local-player command helper grouping

Evidence for:

- A narrow grouping would model the free helper plus the two dwords without making them class fields.
- It would give a future exact child page for `0x005a4f70-0x005a500f.SendOpcode2DAndStoreExtra`.
- It can also review nearby action helpers before deciding whether any siblings belong with the same command-helper surface.

Likely contents if created:

- [UID:00030A] `0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots`
- New exact child `0x005a4f70-0x005a500f.SendOpcode2DAndStoreExtra`
- Candidate related helpers for separate review only: `0x005a4db0`, `0x005a4e40`, `0x005a4e70`, `0x005a4f40` because these are small old-HUD/tab mode/action helpers in the same caller family
- Exclude [UID:0002RX] `0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode`, which already has a stronger [UID:0000N9] `SayInputPanes` owner
- Exclude `0x005a5010` and `0x005a50a0` until their non-HUD callers and semantics are separately rechecked

Evidence against:

- No current by-file or source-tree entry exists for this grouping.
- The generated `SendOpcode2DAndStoreExtra_005A4F70.cpp` is a recovered one-helper artifact, not a reliable original `.cpp` name.
- Creating a new file solely for this target would be weaker than using the existing gate-clearing `UserPane.cpp` file owner.

Decision: useful optional subdocument/grouping, not required before assigning `00030A`. If created, keep it under `UserPane.cpp` or describe it as a local-player command helper grouping, not an independent top-level source file.

### 3. [UID:0000FQ] `UserPane` class

Evidence for:

- `UserPane::OnKeyEvent` directly duplicates the send/store block.
- The command state is local-player/user command state.

Evidence against:

- The dwords are `.data` module-scope slots, not object fields.
- `0x005a4f70` is not a member function and has non-UserPane callers.

Decision: reject as direct parent. Use [UID:0000P1] file-level parent instead.

### 4. `IconsPane` / `TabPane` old-HUD parents

Evidence for:

- `IconsPane::OnMouseEvent` and `TabPane::HandleInputEvent` directly call `0x005a4f70`.
- The raw `IconsPaneActionDispatchRawBody` mirrors the same helper call.

Evidence against:

- Neither pane writes the dwords directly except through the shared helper.
- Neither pane owns the mode-specific state or packet sender.
- `MapPane` and `UserPane` also participate, so old-HUD ownership is too narrow.
- `IconsPaneActionDispatchRawBody` remains a raw retained body and is below `85` completion, but it is only a consumer/duplicate dispatch lead and does not block target assignment.

Decision: reject. These panes are callers/consumers.

### 5. [UID:0000L3]/[UID:00007Q] `MapPane`

Evidence for:

- Live IDA adds a direct helper caller at `0x00507721` in `MapPane::OnMouseEvent`.
- The call passes an event/object extra value and is part of map click/object interaction.

Evidence against:

- MapPane does not write the dwords directly.
- The same helper is called by old-HUD panes and duplicated in UserPane key handling.
- The stored state is command-send state, not map coordinate/object storage.

Decision: reject. MapPane is a newly confirmed consumer, not the declaration owner.

### 6. `CommandInputPanes`, `ItemActionInputPanes`, `InputPanes`, or `SayInputPanes`

Evidence for:

- These modules own many command/input prompt panes and packet-send helpers.
- `0x005a4f70` sits near other `0x005a4b60-0x005a5791` action/say helpers.

Evidence against:

- The target's write paths are not in the `0x005b29c0-0x005b7553` command-input pane neighborhood.
- `ItemActionInputPanes` owns a distinct TakeOff shortcut opcode `0x2d` path, but not this two-byte `{0x2d, 0}` helper/state pair.
- [UID:0002RX] `OpenInputPaneForCurrentSayMode` is the say-mode child in this area; `0x005a4f70` is not a say-input dispatcher.
- None of these pages has direct xrefs to the target dwords.

Decision: reject for this target.

### 7. `g_packetSender` / `Socket`, `g_useEpfAssets` / `StartupWindow`, or generated recovered file

Decision: reject.

- `g_packetSender` is the network send dependency; Socket owns its lifetime, not this command-state pair.
- `g_useEpfAssets` chooses which slot is active; it does not own the slots.
- The generated recovered helper file has good behavior notes but is not source-layout evidence.

## Negative Evidence Summary

Checked and rejected:

- Tail-byte refs inside the target dwords: none.
- Extra loaded-segment absolute-address hits for `0x0069bf6c` / `0x0069bf70`: none beyond known write instructions.
- Data refs to `0x005a4f70`: none.
- PDB/source/debug breadcrumbs: no `RSDS`, `NB10`, `.pdb`, `.cpp`, `.cxx`, or `.h` strings.
- Physical adjacency as proof: rejected. The surrounding `0x0069bf68-0x0069bf78` island mixes a chat singleton, opcode state, and function-key debounce dword.
- Consumer-only caller ownership: rejected for `IconsPane`, `TabPane`, and `MapPane`.

## Final Recommendation

Exact changes applied:

- Assigned [UID:00030A] to [UID:0000P1] `UserPane` by-file.
- Set target score to `87/89`.
- Added a scoped [UID:00030A] anchor to [UID:0000P1] `UserPane` by-file without changing the parent score.

Exact changes still recommended:

- Keep [UID:0002A3] `KeyboardInputCommandStateGlobals` parent-blank and non-emitting.
- Do not split [UID:00030A].
- Do not create an independent `SendOpcode2DAndStoreExtra_005A4F70.cpp` by-file page.
- Replace the stale `by-memory/-coverage-report.md` row using the exact row near the top of this report.

Exact future work outside this assignment:

- Create an exact by-memory helper page for `0x005a4f70-0x005a500f.SendOpcode2DAndStoreExtra` if/when the mixed `0x005a4db0-0x005a50a0` helper family is split.
- Refresh [UID:0001KO] `SayModeHelpers` wording so `0x005a4f70` is described as a shared local-player command helper, not as unresolved say-mode ownership.
- Consider adding [UID:00030A] and the future helper child to [UID:0000P1] `UserPane` proposed contents as file-level command helper/state, separate from `UserPane` class fields.

## Follow-Up Actions

Supervisor actions:

- Replace the exact `by-memory/-coverage-report.md` row above. Do not apply it by memory; use the row block from this report.
- Optionally queue an A-agent split for `0x005a4f70-0x005a500f` and nearby action helpers.

A-agent actions:

- No immediate A-agent repair is required for [UID:00030A]. The parent-page anchor has already been applied.
- Do not move the broader [UID:0001KO] mixed helper aggregate wholesale to `UserPane`.

B001 future research actions:

- If a later target covers `0x005a4db0-0x005a50a0`, split the exact helper functions and decide whether `0x005a4db0`, `0x005a4e40`, `0x005a4e70`, and `0x005a4f40` form the same local-player command-helper surface.

## Confidence

- Recommendation confidence: `86/100`.
- Data/storage confidence: `96/100`.
- Behavior confidence: `94/100`.
- Remaining uncertainty: original source declaration file is inferred from binary behavior and source-tree fit, not recovered source metadata. A future exact helper split could either strengthen direct `UserPane.cpp` ownership or justify a narrow UserPane-owned helper grouping.

## Validator Results

Validation commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the leased documentation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00030A-Opcode2dCommandExtraValueSlots-removed.md](00030A-Opcode2dCommandExtraValueSlots-removed.md). The archived block is non-authoritative and must not be executed.

Results:

- Target page validation: `ok: 1`, `completion_update 00030A ... 87`, `autogen_registry_update 00030A ... -> 0000P1`, `reference_index_add 00007Q ...`, and autogen reports unchanged.
- Parent page validation: `ok: 1`, four `uid_link_insert 00030A` annotations inserted, `reference_index_add 00030A by-file/UserPane.md`, and autogen reports unchanged.
- Repeated existing validator noise: `autogen_parent_has_no_code 00000D by-class/Application.md emitting children only` plus many `autogen_cpp_noop` lines for roots without assembled code. These were not target errors.
- Validator-managed side effects included `validator.ini` registry rebuilds and `project-level/-auto-completion-stats.md` projected-path section refreshes.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/00030A-Opcode2dCommandExtraValueSlots.md`
- Modified: `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md`
- Modified: `by-file/UserPane.md`
- Modified: `tools/leaser/Agents/Agent-B001/research/00030A-Opcode2dCommandExtraValueSlots.md`
- Validator-managed side effects: `tools/validator.ini`, `project-level/-auto-completion-stats.md`; autogen coverage reports were reported `noop`.
- Renamed: none
- Moved to executed: none
- Leases used: `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` and `by-file/UserPane.md` leased as `B001` before edits. The later `unlease` command returned `Rejected[No active lease]` for both paths because no active B001 lease remained; the shared current lease report had no B001 entries after the attempt.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00030A-Opcode2dCommandExtraValueSlots.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00030A"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00030A-Opcode2dCommandExtraValueSlots-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00030A-Opcode2dCommandExtraValueSlots.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00030A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
