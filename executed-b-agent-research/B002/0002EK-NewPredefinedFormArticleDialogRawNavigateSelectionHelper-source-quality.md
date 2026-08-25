** TARGET-REPORT-UID:0002EK **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002EK NewPredefinedFormArticleDialog Raw Navigate Selection Helper Source-Quality Research

Assignment: `B002-report-0002EK-new-predefined-form-article-dialog-raw-navigate-selection-helper-20260625`

Primary target: [UID:0002EK] `by-memory/0x004781f0-0x00478238.NewPredefinedFormArticleDialogRawNavigateSelectionHelper.md`

Report timestamp: `2026-06-25T04:20:54-04:00`

Report-only constraints observed: no leases taken, no by-* docs edited, no generated/project-level/manual coverage files edited, no validator state/cache touched, no IDA DB edits, and no subagents spawned.

## Executive Recommendation

Update [UID:0002EK] from the stale unresolved-helper state to a source-ready retained class helper:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:000098
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000098
```

Keep the existing UID and target path unless the supervisor explicitly wants filename churn. The page title/role should no longer say the source name is unresolved. The best current source-facing method name is:

```cpp
NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()
```

The raw/no-function/no-route facts remain true, but they are now a score cap and route caveat, not a reason to suppress source-quality C++. The helper is a bounded 72-byte product-code island in the `NewPredefinedFormArticleDialog` class cluster, calls the same shared article-navigation helper used by routed transfer-reply actions, and has the same source role as the accepted `NewArticleDialog::NavigateToPreviousArticleSelection` analogue.

Recommended formal target C++ block:

```cpp
void NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()
{
    DialogInSession *previous = m_session->FindPreviousDialog(this);
    ListPane *list = static_cast<ListPane *>(previous->GetControl(7));
    const unsigned short articleId =
        static_cast<unsigned short>(list->SelectedArticleId());

    SendArticleNavigationRequest(articleId, 0x7fff,
        g_useEpfAssets == 1 ? -0x14 : -0x10);
}
```

This intentionally omits null checks because the raw helper has none. The exact low-level proof is `this+0x270 -> sub_4A1250`, previous dialog control id `7`, selected 16-bit value at list/control payload `+0x14c`, hard limit `0x7fff`, and layout byte `0xec`/`0xf0` represented as signed offsets `-0x14`/`-0x10`.

Do not add aggregate C++ to [UID:0000ZL] `NewPredefinedFormArticleDialog`. The exact child page should own this first-draft method body; the aggregate remains blank because constructor/parser/submit/retained-alert helper declarations are still broader source-quality work.

## Current Target State

The source page currently has:

- `COMPLETION:85`, `CONFIDENCE:90`
- `CANONICAL_OWNER:000098`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000098`
- blank formal C++
- stale item summary saying the 2026-06-10 live MCP retry timed out and reachability/final helper name remain open
- stale covered-range role saying "final source name unresolved"
- stale reconstruction guidance saying "Do not emit reconstructed C++ yet" due unresolved helper name and an old `95+` threshold

The generated tracker and coverage outputs are stale relative to the source header. `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`, and `by-memory/-coverage-report.md` still show or derive from old `76/84` wording. Those are generated/manual coverage contexts only; do not hand-edit them during implementation unless the supervisor explicitly reauthorizes a coverage edit.

## Evidence Checked

Workflow and assignment:

- `tools/leaser/Agents/Agent-B002/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`

Primary and support docs:

- [UID:0002EK] target page
- [UID:000098] `by-class/NewPredefinedFormArticleDialog.md`
- [UID:0000LT] `by-file/NewPredefinedFormArticleDialog.md`
- [UID:0000ZL] `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
- [UID:0002UJ] constructor child, [UID:0002UK] button handler child, and adjacent padding notes
- [UID:00030H] `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md`
- [UID:000132] `by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md`
- [UID:00030K] `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`
- [UID:0002EL] `TransferReplyAlertOnConfirm` and [UID:0000ZN] `TransferReplyPredefinedAlertOnAlertAction`
- `by-global/g_useEpfAssets.md` / memory-global context for `byte_66DA97`
- generated tracker/coverage/C++ artifacts as read-only stale-state context

IDA MCP status and provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path reported by health: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `server_health`: `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready

Current MCP checks:

- `lookup_funcs` reports `0x004781e5`, `0x004781f0`, `0x00478237`, and `0x00478238` as `Not a function`; positive controls are `sub_4777A0` at `0x004777a0`, size `0xa45`, `sub_478240` at `0x00478240`, size `0x62`, `sub_4751C0` at `0x004751c0`, size `0x90`, and `sub_4A1250` at `0x004a1250`, size `0x52`.
- `disasm 0x004781f0` renders `<no function>` but decodes the raw sequence from `push ecx` at `0x004781f0` through `retn` at `0x00478237`, followed by `align 10h` and successor `sub_478240`.
- `get_bytes` confirms `0x004781e5-0x004781f0` is eleven `0xcc` bytes, `0x004781f0-0x00478238` is the 72-byte helper, and `0x00478238-0x00478240` is eight `0xcc` bytes.
- `make_signature_for_range 0x004781f0-0x00478238` with no operand wildcarding returns the exact signature and `unique:true`.
- `xrefs_to 0x004781f0` returns zero xrefs.
- `find_bytes` for raw-start VA `f0 81 47 00` and RVA `f0 81 07 00` returns zero matches.
- `xrefs_to 0x004751c0` returns seven code refs: `0x00473df6`, raw `0x00474d91`, `0x00474dea`, raw `0x004771a2`, raw target call `0x00478232`, `0x00479031`, and `0x004790f1`.
- `xrefs_to 0x004a1250` returns ten refs, including this raw target call at `0x004781f7` and the routed transfer-reply alert calls at `0x00478ff6` and `0x004790b6`.
- `xrefs_to 0x00478240`, `0x00478940`, and `0x004782b0` return sibling vtable/data refs at `0x00614098`, `0x006140ac`, and `0x006140e8`. A current vtable-slice byte dump over `0x00614050-0x006140ef` has no `0x004781f0` dword, so the no-vtable-slot result has positive controls.

Raw disassembly facts:

```asm
004781F0  push    ecx
004781F1  mov     ecx, [ecx+270h]
004781F7  call    sub_4A1250
004781FC  push    7
004781FE  mov     ecx, [eax+1FCh]
00478204  mov     eax, [ecx]
00478206  call    dword ptr [eax+10h]
00478209  mov     eax, [eax]
0047820B  mov     ecx, [eax+108h]
00478211  xor     eax, eax
00478213  cmp     byte_66DA97, 1
0047821A  setnz   al
0047821D  movzx   edx, word ptr [ecx+14Ch]
00478224  lea     eax, ds:0FFFFFFECh[eax*4]
0047822B  push    eax
0047822C  push    7FFFh
00478231  push    edx
00478232  call    sub_4751C0
00478237  retn
```

## Source Names And Semantics

Recommended current names:

| Raw item | Source-facing name or role |
| --- | --- |
| `0x004781f0-0x00478238` | `NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()` |
| `0x004a1250` | `DialogSession::FindPreviousDialog` / `FindPreviousDialog(this)` |
| `0x004751c0` | shared `SendArticleNavigationRequest` helper, opcode `0x3b`, subcommand `2`, two word arguments, one byte/layout argument, length `7` |
| `byte_66DA97` | [UID:0000SW] `g_useEpfAssets`; raw name should be retained only as an IDA alias |
| control id `7` | previous dialog article/list control used to recover the selected article/item id |
| `0x7fff` | article-navigation limit/sentinel, same convention as BoardListDialog's selected-board open packet |
| `-0x14` / `-0x10` | layout/mode byte sent as `0xec` when `g_useEpfAssets == 1`, otherwise `0xf0` |

`NewArticleDialogCore` already carries a first-draft `NewArticleDialog::NavigateToPreviousArticleSelection()` using the same retained previous-selection role. Transfer-reply alert docs use the lower-level `ListPane *list = static_cast<ListPane *>(previous->GetControl(7)); const int articleId = list->SelectedArticleId();` candidate shape. Combining those two precedents gives a bounded and consistent source reconstruction for this target.

## Rejected Alternatives

- Reject treating the raw/no-function status as padding or ignored data. The current unique signature and disassembly prove a coherent product-code helper ending in `retn` with real calls to `0x004a1250` and `0x004751c0`.
- Reject a vtable-dispatched method claim. Current MCP evidence still finds no vtable slot for `0x004781f0`, while sibling routed methods have live slots at `0x00614098`, `0x006140ac`, and `0x006140e8`.
- Reject `CANONICAL_OWNER:NONE` or blank emitter. The helper sits in the exact NewPredefined class cluster, uses that class's `this+0x270` session field, and has a direct semantic parent [UID:000098].
- Reject file-only ownership. [UID:0000LT] is the source-file route, but the exact helper is a class method child owned/emitted through [UID:000098].
- Reject leaving `final source name unresolved`. The best current name is `NavigateToPreviousArticleSelection`, with `SendPreviousDialogSelectionNavigationRequest` retained only as a packet-focused alias in prose if desired.
- Reject old `95+` threshold language. The active standard supports bounded first-draft C++ when the source route, behavior, helper names, and no-route caveats are documented.
- Reject treating stale generated `76/84` rows as current source truth. The target source header is already `85/90`, and this report recommends `88/91` after the current MCP recheck and C++ disposition.

## Score Rationale

Completion should rise from `85` to `88` because the current pass resolves the old live-MCP-timeout caveat, supplies a source-facing helper name, normalizes the helper/global names, preserves but demotes the no-route evidence to a caveat, and provides exact first-draft formal C++.

Confidence should rise from `90` to `91` because active MCP session `80de0a67` reconfirms function inventory, bytes, disassembly, unique signature, xrefs, VA/RVA pointer negatives, and vtable positive/negative controls. It should remain below final confidence because IDA still has no function object, ordinary caller, data pointer, or vtable route for the raw start, and `ListPane::SelectedArticleId()` / inherited control access names remain source-facing reconstructions rather than symbol-proven originals.

## Target Implementation Text

Recommended replacement item summary:

```text
B002 2026-06-25 MCP-backed source-quality recheck resolves the raw island as retained class helper `NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()`: exact 72-byte no-function body between `0xcc` padding bands, `DialogSession::FindPreviousDialog(this)`, previous-dialog control id `7`, selected 16-bit article/list value, `g_useEpfAssets` layout byte, and shared `SendArticleNavigationRequest(..., 0x7fff, ...)`; no caller/vtable/VA/RVA pointer route remains, but that is a score cap rather than a C++ blocker.
```

Recommended covered-range role:

```text
retained `NavigateToPreviousArticleSelection` class helper
```

Recommended reconstruction-guidance replacement:

```text
Emit the bounded first-draft `NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()` method on this exact child page. Preserve the raw/no-function/no-caller/no-vtable/no-pointer caveat and do not create an IDA function or claim a live entry route. The helper is source-shaped class logic because it is bounded by alignment, uses this dialog's session field, and matches the accepted NewArticle/transfer-reply article-navigation pattern.
```

## Support Doc Synchronization

Update only support docs whose current wording contradicts this target disposition:

- `by-class/NewPredefinedFormArticleDialog.md`: change the raw navigation helper row to name `NavigateToPreviousArticleSelection`, add the 2026-06-25 MCP-backed evidence, remove this child from the class-level "retained-helper emission policy" blocker, and fix the stale aggregate score reference from `82/86` to the current aggregate state. The class-level formal C++ may remain blank because the exact child page owns this method body and other class-wide blockers remain.
- `by-file/NewPredefinedFormArticleDialog.md`: add a short source-route note that [UID:0002EK] is now source-named and first-draft C++ ready despite no vtable/caller/pointer route. Do not add aggregate C++; do not edit generated output manually.
- `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`: update the child inventory row and final-C++ blocker prose so this target no longer blocks exact child emission. Keep the aggregate formal C++ blank and keep [UID:0002UR] retained-helper policy caveats separate.
- `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md`: replace the stale "final C++ remains withheld under the 95/95 gate" sentence with current blocker wording limited to constructor-specific dynamic UI/helper/type names. Do not let that old threshold contradict this target's first-draft C++.
- `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md`: remove the stale "child is below the 85 completion gate" wording from the item summary, and update the NewPredefined caller bullet to name `NavigateToPreviousArticleSelection` / source-ready retained helper.

Read-only stale contexts:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`
- `by-memory/-coverage-report.md` and any other `-coverage-report.md`

Those should be refreshed only through validator/supervisor-owned flows, not hand-edited by B002 during report-only work.

## Suggested Validator Plan For Implementation Callback

Run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits. Minimum target command:

> Executable block R001 was removed from this report and preserved verbatim in [0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality-removed.md](0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the same scoped file-validator pattern for each support doc changed by the implementation callback:

> Executable block R002 was removed from this report and preserved verbatim in [0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality-removed.md](0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After validation, verify generated freshness by reading generated headers/markers only. Do not hand-edit generated files or coverage reports.

## Implementation Tracking Checklist

- [x] Lease only the exact target/support by-* files immediately before editing; release leases immediately after the edit/validator batch.
  - Proof: B002 leased the six accepted by-* paths, re-leased after the first lease window expired before the final cleanup/validator batch, then released all six after validators. `tools/leaser/Agents/current_leases.md` readback after release reports `No active leases.`
- [x] Update [UID:0002EK] metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:000098`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000098`.
  - Proof: post-validation target header readback shows `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:000098`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000098`.
- [x] Replace the target item summary with the B002 2026-06-25 MCP-backed source-quality summary from this report, removing the timed-out-MCP/final-name-open wording.
  - Proof: target item summary now names `NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()`, preserves the no caller/vtable/VA/RVA route as a score cap, and the final stale-pattern scan found no matches for the old timeout/final-name-open/high-threshold wording.
- [x] Replace the covered-range proposed role with retained `NavigateToPreviousArticleSelection` class helper wording.
  - Proof: target covered range row now says retained `NavigateToPreviousArticleSelection` class helper.
- [x] Insert the exact formal `NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()` C++ block from this report in the target `RECONSTRUCTION_CPP CODE` block.
  - Proof: target header readback shows the formal block with `FindPreviousDialog(this)`, `GetControl(7)`, `SelectedArticleId()`, and `SendArticleNavigationRequest(articleId, 0x7fff, g_useEpfAssets == 1 ? -0x14 : -0x10)`.
- [x] Update target behavior/evidence/prose to use `g_useEpfAssets`, `DialogSession::FindPreviousDialog`, `SendArticleNavigationRequest`, and `SelectedArticleId` source-facing names while preserving raw aliases `byte_66DA97`, `sub_4A1250`, and `sub_4751C0` as evidence.
  - Proof: target `Behavior`, `Source-Facing Names And Interpretation`, `Evidence`, and `Reconstruction Guidance` now contain the accepted source names and keep raw aliases only for evidence/search.
- [x] Preserve the negative route proof: no IDA function object, zero xrefs to `0x004781f0`, zero VA/RVA pointer-pattern hits, no NewPredefined vtable slot, and positive sibling vtable controls at `0x00614098`, `0x006140ac`, and `0x006140e8`.
  - Proof: target evidence and support pages record the no-function/no-xref/no-pointer/no-vtable result plus sibling vtable positives; this is also reflected in the target item summary and score rationale.
- [x] Remove old `95+` / `95/95` threshold wording from the target and touched support docs; replace it with current by-structure C++/no-code rationale.
  - Proof: final stale-pattern scan over all six changed by-* docs returned no matches for `95+`, `95/95`, old timeout, old unresolved-name, or old no-C++ blocker phrases.
- [x] Update `by-class/NewPredefinedFormArticleDialog.md` only where stale: method row/source notes, current target disposition, stale aggregate score wording, and removal of this target as a class-level retained-helper C++ blocker.
  - Proof: class page method row names `NavigateToPreviousArticleSelection`; evidence/score notes state [UID:0002EK] is `88/91`, emits exact child C++, and preserves no-route proof as a caveat.
- [x] Update `by-file/NewPredefinedFormArticleDialog.md` only where stale: source-route notes for [UID:0002EK] source name/C++ readiness and read-only generated-output caveat.
  - Proof: file page proposed contents and boundary notes now route [UID:0002EK] as source-ready retained `NavigateToPreviousArticleSelection` and say not to hand-edit generated output or add aggregate C++.
- [x] Update `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md` only where stale: child inventory row and final-C++ blocker prose; keep aggregate formal C++ blank.
  - Proof: aggregate page child inventory, IDA evidence, reconstruction notes, final C++ paragraph, data issues, and changes state that exact child [UID:0002EK] emits while aggregate C++ remains blank for separate constructor/parser/packet/alert and `0x00478aa0` blockers.
- [x] Update `by-memory/0x004777a0-0x004781e5.NewPredefinedFormArticleDialogConstructor.md` only if needed to remove the stale `95/95` wording; do not force constructor C++ in this callback.
  - Proof: constructor page now uses current constructor-specific no-code rationale, states old high-threshold wording is superseded, and keeps constructor C++ blank.
- [x] Update `by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md` item summary/NewPredefined caller bullet only where stale or contradictory.
  - Proof: ArticleNavigationHelpers summary, behavior/evidence, parent-candidate bullet, and changes now name the NewPredefined caller as `NavigateToPreviousArticleSelection` while preserving shared helper-island ownership under BoardDialogs.
- [x] Do not edit generated files, project-level files, validator/tool state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Proof: manual edits were limited to the six accepted by-* docs and this report checklist. Generated/projected stats changes were validator-owned side effects from scoped `--apply` runs; no manual coverage, validator state/cache, IDA DB, or coverage-report files were edited.
- [x] Run scoped validators for every changed by-* doc using the suggested commands or equivalent, including a final `--wait-generated` validator run.
  - Proof: all scoped validators exited `0` with `ok: 1`: target final `000000001229` at `2026-06-25T04:37:53-04:00` (`--wait-generated`, generated refresh completed); class `000000001222` at `2026-06-25T04:35:24-04:00`; file `000000001223` at `2026-06-25T04:35:31-04:00`; aggregate `000000001224` at `2026-06-25T04:35:37-04:00`; constructor `000000001225` at `2026-06-25T04:35:42-04:00`; ArticleNavigation final `000000001230` at `2026-06-25T04:38:08-04:00` (`--wait-generated`, generated refresh completed).
- [x] Record validator command ids/timestamps, exit codes, ok counts, and generated-refresh/header freshness in this checklist before final implementation closeout.
  - Proof: command ids/timestamps/exits/ok counts are listed above; final generated refresh marker readback is `validator-command-id: 000000001230`, `validator-refreshed-at: 2026-06-25T04:38:08-04:00`.
- [x] Re-read the target header, item summary, C++ block, and generated `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp` marker/body after validation to confirm metadata, source name, C++ emission, and generated freshness persisted.
  - Proof: post-validation readback confirmed target header metadata, B002 item summary, formal C++ block, and generated body. Generated file begins with [UID:0002EK] `Completion:88 | Confidence:91` and `void NewPredefinedFormArticleDialog::NavigateToPreviousArticleSelection()`.
- [x] If validation reverts the target to old `76/84`, old timeout summary, or blank C++, stop and report `PAUSED_VALIDATOR_METADATA_CONFLICT` with exact command id/timestamp/current header instead of editing generated files, coverage files, or validator state.
  - Proof: not triggered. Final target readback after validator `000000001229` and generated refresh `000000001230` preserved `88/91`, the accepted summary, and nonblank formal C++; no pause condition occurred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality.md","timestamp":"2026-06-25T04:43:30","uid":"0002EK"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002EK-NewPredefinedFormArticleDialogRawNavigateSelectionHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002EK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
