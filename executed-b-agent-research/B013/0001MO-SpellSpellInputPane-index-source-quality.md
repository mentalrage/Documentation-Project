** TARGET-REPORT-UID:0001MO **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001MO SpellSpellInputPane Index Source-Quality Report

Status: FINISHED

## Target

- Assignment id: `B013-goal2-spellspellinputpane-index-source-quality-0001MO-20260619`
- UID: `0001MO`
- Primary by-memory doc: `source-3/project-documentation/by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0001MO-SpellSpellInputPane-index-source-quality.md`
- Exact child pages checked:
  - [UID:0001MN] `source-3/project-documentation/by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md`
  - [UID:0001MP] `source-3/project-documentation/by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md`
  - [UID:0001MQ] `source-3/project-documentation/by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md`
- Support docs checked: [UID:0000DT] `by-class/SpellSpellInputPane.md`, [UID:0000O0] `by-file/SpellInputPanes.md`, [UID:0000ID] `by-file/CommandInputPanes.md`, [UID:0002N7] `by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVftables.md`, [UID:0003HL] `by-class/SpellSpellInputPane__vftable.md`, [UID:0001OR] `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`, and [UID:0003UC] `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`.

No by-* docs, support docs, generated files, or coverage reports were edited.

## Evidence Checked

- Assignment rules: `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, and `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`.
- Current target and child metadata/content. The index is still `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank `EMITTER_UIDS:` and blank C++.
- Child status after the prior child C++ updates:
  - [UID:0001MN] constructor is `86/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000DT], with first-draft constructor C++ populated.
  - [UID:0001MP] key-input override is `86/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000DT], with first-draft key-input C++ populated.
  - [UID:0001MQ] accept override is `87/90`, `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000DT], with first-draft accept C++ populated.
- `by-memory/-coverage-report.md` rows for [UID:0001MO]/[UID:0001MN]/[UID:0001MP]/[UID:0001MQ].
- `auto-generated/-ag-memory-coverage.md`: the three children are `coded` to `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp`; [UID:0001MO] is `not_reconstructable`, owner `NONE`, no output.
- Local validator dry run: `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md --uid-only`; result was ok for UID `0001MO`.
- IDA MCP endpoint probe at `http://127.0.0.1:13337/mcp`; not reachable, so this pass used current docs, exported function facts already integrated in the docs, and a local read-only PE scan.
- Local read-only PE route scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.

## Binary Route And Boundary Recheck

The local PE bytes confirm the current split and prove this index is not a separate code body:

| Span | Role | Size/evidence |
| --- | --- | --- |
| `0x005b6120-0x005b61e7` | `SpellSpellInputPane::SpellSpellInputPane()` | `0xc7` / 199 bytes. Starts with normal prologue/SEH setup. Ends at `8b e5 5d c3`. |
| `0x005b61e7-0x005b61f0` | padding | 9 bytes, all `CC`. |
| `0x005b61f0-0x005b625c` | `SpellSpellInputPane::OnKeyInput(const InputEvent *)` | `0x6c` / 108 bytes. Starts with normal prologue. Ends at `5f 5e 5d c2 04 00`. |
| `0x005b625c-0x005b6260` | padding | 4 bytes, all `CC`. |
| `0x005b6260-0x005b62c8` | `SpellSpellInputPane::OnAccept()` | `0x68` / 104 bytes. Starts with normal prologue. Ends at `5f 5e 8b e5 5d c3`. |
| `0x005b62c8-0x005b62d0` | padding | 8 bytes, all `CC`. |

Vtable/data evidence from the same PE scan:

- `0x00630464 -> 0x005b6260`, the primary-vtable accept slot.
- `0x00630474 -> 0x005b61f0`, the secondary-vtable key/input slot.
- `0x0063041c -> 0x005b7940`, primary vtable starts at the shared scalar deleting destructor entry.
- `0x0063046c -> 0x005b77c8`, secondary vtable starts at an adjustor thunk.
- `0x0063049c -> 0x005b77d3`, tertiary vtable starts at an adjustor thunk; `0x006304a0 -> 0x00544e90`; `0x006304a4 -> 0x00653704` is the next table/locator boundary.
- Absolute refs to `0x0063041c` occur at `0x005a6ac4`, `0x005a9e7a`, and `0x005b6169`.
- Absolute refs to `0x0063046c` occur at `0x005a6ace`, `0x005a9e84`, and `0x005b6173`.
- Absolute refs to `0x0063049c` occur at `0x005a6ad8`, `0x005a9e8e`, and `0x005b617d`.
- There are no file-wide absolute refs to constructor start `0x005b6120`.
- There are no `.text` rel32 call/jmp refs to `0x005b6120`, `0x005b61f0`, or `0x005b6260`; the virtual methods are data/vtable reached.
- The only absolute refs to `0x005b61f0` and `0x005b6260` are the vtable slots at `0x00630474` and `0x00630464`.

This confirms the exact child boundaries and padding already documented. No split, merge, or boundary repair is needed.

## Child Policy And No-Code Proof

[UID:0001MO] should remain a non-emitting grouping index. It covers three independent source-authored methods plus compiler padding, not one function, class declaration, thunk, vtable, or source unit. The exact method children are already the reconstructable units and now carry first-draft C++.

Exact no-code proof for [UID:0001MO]:

- The address span contains three separate function prologues/epilogues separated by all-`CC` padding.
- The key and accept bodies are independently vtable-reached through distinct slots.
- The constructor installs the three vtable bases, but the constructor itself is already represented by [UID:0001MN].
- `auto-generated/-ag-memory-coverage.md` already routes [UID:0001MN]/[UID:0001MP]/[UID:0001MQ] to `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` and leaves [UID:0001MO] as `not_reconstructable`.
- Emitting C++ from the index would duplicate the exact method children and blur the parent/child ownership model.

Recommendation: keep [UID:0001MO] with:

```text
COMPLETION:82
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

The `82/88` score is still appropriate. The page is complete enough for an index: exact child pages, live boundaries, vtable slots/stores, padding spans, source route, and generated-name rejections are documented. It should not be promoted to reconstructable, assigned an owner/emitter, or given aggregate C++ merely because the child methods now pass the code gate.

## Source Route And Ownership

Best source route remains [UID:0000O0] `SpellInputPanes`, likely `NexusTK/ui/dialogs/SpellInputPanes.cpp`.

The exact source-facing class/method layout should be treated as:

```cpp
class SpellSpellInputPane : public CharInputPane {
public:
    SpellSpellInputPane();
    bool OnKeyInput(const InputEvent *event);
    void OnAccept();
};
```

That declaration shape is for class/support documentation only; [UID:0001MO] should not emit it.

Ownership reasoning:

- [UID:0000DT] `SpellSpellInputPane` is the direct owner/emitter for the three method children.
- [UID:0000O0] `SpellInputPanes` is the source file/module route because the constructor builds an available spell-slot prompt, the accept method selects a spell/command slot, and related factories/open helpers store the same `SpellSpellInputPane` vtables.
- [UID:0000ID] `CommandInputPanes` remains inherited/address-neighborhood context only. `SpellSpellInputPane` derives through command-input infrastructure, but the concrete prompt, state access, and accept semantics are spell-domain behavior.
- [UID:0002N7]/[UID:0003HL] vtable docs are compiler/generated support docs, not source-emitting owners.

## Behavior And Helper Reanalysis

Constructor [UID:0001MN]:

- Source-facing name/signature: `SpellSpellInputPane::SpellSpellInputPane()`.
- Base construction route: `CharInputPane(false)`.
- Installs primary/secondary/tertiary vtables at object offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Calls helper `0x005a4310` to build the available spell shortcut/range text.
- Calls language lookup `0x004f0350` with string id `0x24` / decimal `36`.
- Calls CRT `swprintf_s` wrapper `0x0041b9b0`.
- Calls [UID:00018Y] `LineInputPaneSetPromptText` at `0x004f20a0`.
- Best helper direction for `0x005a4310`: `UserPane::BuildSpellSlotLabelString` or `BuildAvailableSpellSlotRangeText`. The decompile/docs show it scans 52 spell slots at stride `0x148`, reads the local-player spell active/learned flag around `+0x13a834 + slot*0x148`, maps slots `1..26` to lowercase letters and `27..52` to uppercase letters, emits ranges with `-`, and null-terminates the output.

Key/input [UID:0001MP]:

- Source-facing name/signature: `bool SpellSpellInputPane::OnKeyInput(const InputEvent *event)`.
- Vtable reachability: secondary slot `0x00630474`.
- Checks the `?` shortcut path: event kind byte `event+0x04 == 8`, narrowed key from `event+0x08`, and mode/fallback byte `event+0x10a == 4`.
- Calls [UID:00015X] `GeneralPurposePanelSwitchActiveTab` at `0x004b8650` with tab `3` and false/0.
- Calls sound helper `0x0057a5c0` to play effect/sample `0x198` / decimal `408` at volume `100`.
- Falls back to `CharInputPane::OnKeyInput` at `0x004f2920`.
- `InputEvent::type`, `InputEvent::keyCode`, `InputEvent::narrowFallback`, and `NarrowInputKey` are good descriptive names, but the final shared event-field symbols remain project-wide open naming work. This is not an index blocker.

Accept [UID:0001MQ]:

- Source-facing name/signature: `void SpellSpellInputPane::OnAccept()`.
- Vtable reachability: primary slot `0x00630464`.
- Requires text length exactly one UTF-16 code unit.
- Calls LineInputPane text length/copy helpers at `0x004f2310` and `0x004f2300`.
- Maps `a`..`z` to slots `1..26` and `A`..`Z` to slots `27..52`; rejects all other characters.
- Calls [UID:0003UC] `0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch`, currently best described as `UseCommandSlot` / `DispatchCommandSlot` on the local player/UserPane/LivingObjectPane path. This method does not directly send a packet.

## Generated Names And Rejected Alternatives

- Reject `SpellManager` and `g_pSpellMan` for this cluster. The evidence points to broad local-player/UserPane state at `dword_67A748`, not a standalone spell manager object. [UID:0001OR] records this storage as a broad local-player/UserPane pointer with many typed views; spell use here is one typed view, not the owning identity.
- Reject treating `0x005a4310` as a current-spell-name getter. Its loop scans the learned/active spell-slot flags and formats available slot letters/ranges.
- Reject placing this index under `CommandInputPanes` as direct owner/emitter. That file remains useful for inherited base and neighboring command-input context only.
- Reject aggregate/index C++ emission. The aggregate has no source-authored body independent of the three exact children.
- Keep `g_pLocalUserPane` as the best current descriptive name in first-draft child C++ until the global naming pass settles a final symbol for `dword_67A748`.
- Keep `BuildAvailableSpellSlotRangeText` or `UserPane::BuildSpellSlotLabelString` as the best current descriptive name for `0x005a4310`. I slightly prefer `UserPane::BuildSpellSlotLabelString` for IDA naming because the helper reads UserPane/local-player spell-slot state, but `BuildAvailableSpellSlotRangeText` is clearer at call sites.
- Keep `LivingObjectPane::UseCommandSlot` or `LivingObjectPane::DispatchCommandSlot` as the best direction for `0x005a4530`. Avoid spell-only names there because the callee is broader than this one spell prompt.

## Open Questions After Reanalysis

These are not blockers for [UID:0001MO], but should remain visible for later final-source polish:

- Final original symbol for `dword_67A748`: current best is local-player/UserPane state pointer, with `g_pLocalUserPane` acceptable in child first-draft C++.
- Final original symbol for `0x005a4310`: current best is `UserPane::BuildSpellSlotLabelString` / `BuildAvailableSpellSlotRangeText`; live symbol evidence is still unavailable.
- Final original symbol for `0x005a4530`: current best is `LivingObjectPane::UseCommandSlot` / `DispatchCommandSlot`; child docs correctly avoid claiming direct packet send from `OnAccept`.
- Final shared `InputEvent` field names for `event+0x04`, `event+0x08`, and `event+0x10a`: current descriptive fields are enough for the child first draft, but should be reconciled with the broader event-layout pass.
- Exact historical source file name is not symbol-proven. `SpellInputPanes.cpp` remains the best route because the file-level support doc owns the spell prompt/input family and the auto-generated route already emits the coded children there.

## Recommended Exact Doc Changes

### Target [UID:0001MO]

No metadata change. Keep `82/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS:`, and blank C++.

Add this note to the target doc history/support section:

```markdown
- 2026-06-19 B013 source-quality recheck: local PE scan against MD5 `4247e04e20b65d6414c7238aa8ff5515` confirms this is still a non-emitting grouping index over exact coded children [UID:0001MN], [UID:0001MP], and [UID:0001MQ]. The scan verifies child boundaries, all-`CC` padding at `0x005b61e7-0x005b61f0`, `0x005b625c-0x005b6260`, and `0x005b62c8-0x005b62d0`, vtable method slots `0x00630474 -> 0x005b61f0` and `0x00630464 -> 0x005b6260`, and vtable-base stores/refs for `0x0063041c`, `0x0063046c`, and `0x0063049c`. Keep this page `RECONSTRUCTABLE:FALSE` with no owner/emitter/C++ because the constructor, key-input override, and accept override are already exact child emitters under `SpellInputPanes`; generated `SpellManager` / `g_pSpellMan` names remain rejected.
```

If the target's reconstruction guidance is refreshed, use this exact replacement/summary text:

```markdown
Do not emit aggregate C++ from this index. The range `0x005b6120-0x005b62c8` contains three separate source methods plus padding, and the reconstructable units are the exact child pages [UID:0001MN], [UID:0001MP], and [UID:0001MQ]. Those children own the method bodies through [UID:0000DT] `SpellSpellInputPane` and route to [UID:0000O0] `SpellInputPanes`. This index should remain an ownership/boundary map only.
```

### Child/support docs

- [UID:0001MN] constructor: no required metadata change. Optional support sync only: note the 2026-06-19 PE scan confirmed no direct rel32/start refs to the constructor and confirmed constructor vtable-base refs at `0x005b6169`, `0x005b6173`, and `0x005b617d`.
- [UID:0001MP] key-input: fix one stale score-table sentence. Replace:

```markdown
| Reconstructable | true | The handler is source-authored class behavior, but final C++ stays blank below the final-source bar. |
```

with:

```markdown
| Reconstructable | true | The handler is source-authored class behavior and now carries first-draft C++; final shared `InputEvent` field names remain inferred below final-audit quality. |
```

- [UID:0001MQ] accept: no required metadata change. Optional support sync only: note the 2026-06-19 PE scan confirmed the only absolute ref to `0x005b6260` is primary vtable slot `0x00630464`.
- [UID:0000DT] `SpellSpellInputPane`: no score change. Optional note: exact method bodies are emitted by [UID:0001MN]/[UID:0001MP]/[UID:0001MQ]; class-level C++ should remain declaration/support-only if it would duplicate children.
- [UID:0000O0] `SpellInputPanes`: no score change. Optional note: [UID:0001MO] was rechecked as a non-emitting index and its coded children remain routed to `SpellInputPanes.cpp`.
- [UID:0000ID] `CommandInputPanes`: no change. Its cross-reference-only treatment for `SpellSpellInputPane` is still correct.
- [UID:0001OR] `g_pCollectionData` / local-player state: no required change. Existing generated `SpellManager` / `g_pSpellMan` rejection remains valid.
- [UID:0002N7]/[UID:0003HL] vtable support docs: no required score or boundary change.

## Coverage-Report Replacement Row

Do not edit `by-memory/-coverage-report.md` directly from this report. If the supervisor accepts the B013 support wording update, use this exact replacement row for [UID:0001MO]:

```markdown
    - [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md) 0x005b6120-0x005b62c8 | grouping index | SpellSpellInputPane : ignored : 82% : strong : B013 2026-06-19 recheck confirms this remains a non-emitted grouping index over coded child methods [UID:0001MN]/[UID:0001MP]/[UID:0001MQ]; PE bytes verify child ranges, all-`CC` padding at `0x005b61e7-0x005b61f0`, `0x005b625c-0x005b6260`, and `0x005b62c8-0x005b62d0`, vtable method slots `0x00630474`/`0x00630464`, constructor/factory/open vtable stores for `0x0063041c`/`0x0063046c`/`0x0063049c`, `SpellInputPanes` placement, and rejection of generated `SpellManager`/`g_pSpellMan`; no aggregate owner/emitter/C++ should be set.
```

No child coverage-row replacement is required. The existing child rows already reflect the accepted first-draft C++ and scores.

## IDA Rename, Type, And Comment Recommendations

Recommended if live IDA becomes available:

- `sub_5B6120`: rename to `SpellSpellInputPane::SpellSpellInputPane`; type as a constructor for `SpellSpellInputPane`. Confidence: high.
- `sub_5B61F0`: rename to `SpellSpellInputPane::OnKeyInput`; type as `bool __thiscall SpellSpellInputPane::OnKeyInput(const InputEvent *event)`, with a note that the vtable slot is on the `+0xa0` adjusted interface/base view. Confidence: high for method identity, medium-high for final event type spelling.
- `sub_5B6260`: rename to `SpellSpellInputPane::OnAccept`; type as `void __thiscall SpellSpellInputPane::OnAccept()`. Confidence: high.
- `sub_5A4310`: rename/comment as `UserPane::BuildSpellSlotLabelString` or `BuildAvailableSpellSlotRangeText`; comment that it scans 52 spell slots at stride `0x148` and emits available shortcut letters/ranges. Confidence: medium-high for behavior, medium for final original spelling.
- `sub_5A4530`: keep/comment as `LivingObjectPane::UseCommandSlot` / `DispatchCommandSlot`; do not rename it to a spell-only manager method. Confidence: medium-high for role, medium for final original spelling.
- `dword_67A748`: comment as the local-player/UserPane state pointer in this context, not `g_pSpellMan`. Confidence: high for rejecting SpellManager, medium-high for `g_pLocalUserPane` descriptive spelling.
- Vtable comments: mark `0x00630464` as accept, `0x00630474` as key/input, and base refs `0x0063041c`/`0x0063046c`/`0x0063049c` as the primary/secondary/tertiary `SpellSpellInputPane` vtables.

## Validation Commands Needed After Implementation

If the supervisor later requests applying the recommended doc/support edits, run:

> Executable block R001 was removed from this report and preserved verbatim in [0001MO-SpellSpellInputPane-index-source-quality-removed.md](0001MO-SpellSpellInputPane-index-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation readiness: ready for supervisor review. This report recommends report-only support/doc cleanup, not aggregate C++ emission.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0001MO-SpellSpellInputPane-index-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001MO"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MO-SpellSpellInputPane-index-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001MO-SpellSpellInputPane-index-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
