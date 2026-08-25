** TARGET-REPORT-UID:0002X9 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID0002X9 g_pNewUserDialogPane Source-Quality Report

## Finalized Report / Current Recommendation

UID0002X9 is a real one-dword singleton storage target for the older account-registration `NewUserDialogPane` pointer at `0x0069b480-0x0069b484`. The strongest current recommendation is to make the page source-ready as a file-owned singleton declaration emitted through [UID:0000LV][NewUserDialogPane](../../../by-file/NewUserDialogPane.md), while preserving the current byte-layer discrepancy as a confidence cap.

Callback-applied target state:

- `COMPLETION:88`
- `CONFIDENCE:90`
- keep `CANONICAL_OWNER:0000LV`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:0000LV`
- keep blank `EMITTER_POSITION_OPTIONAL`
- change `Nested:4` to `Nested:0`
- insert formal C++:

```cpp
NewUserDialogPane *g_pNewUserDialogPane;
```

The declaration is source-ready because the slot is exact, the owner/emitter route already clears the gate, current MCP confirms the five lifecycle refs, and the PE image check proves the slot lies in `.data` virtual zero-fill rather than raw-backed file bytes. Current MCP `make_signature_for_range` still returns `FF FF FF FF`, so old `0xffffffff` wording should be historicalized as an IDA signature-layer / historical-session discrepancy, not silently deleted.

## Supporting Research

Lifecycle/status: initial report-only research passed supervisor Gate 1 at SHA256 `D936738D41B3604A3D5F34DFC0863F13BEE6546A09AFD99E2FAB1C84FA5F21DE`. The implementation callback was applied on 2026-07-05 to the authorized target/support docs, scoped validators ran, generated output refreshed through validator ownership, and this report now records callback states. B004 did not manually edit generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or run `execute_report` / lifecycle/archive commands.

Docs/reports/generated checked:

- Target: `by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md`.
- Direct support: `by-file/NewUserDialogPane.md`, `by-class/NewUserDialogPane.md`, [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](../../../by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md), and [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](../../../by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md).
- Neighbor/precedent docs: [UID:0002XI][g_pLoginDialogPane](../../../by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md), [UID:0002XL][g_pNewUserMiscDialogPane](../../../by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md), [UID:0002XM][g_pChangePasswordDialogPane](../../../by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md), [UID:0000RE][g_pLoginDialogPane](../../../by-global/g_pLoginDialogPane.md), and [UID:0002X3][g_pNewUserDialogPane2](../../../by-global/g_pNewUserDialogPane2.md).
- Generated/tracker: `auto-generated/NexusTK/login/NewUserDialogPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.
- Prior executed reports opened as precedent/context: B010 UID0002XL, B003 UID0002XM, and B010 UID00019J. They were used as current executed-report leads, not as substitutes for this target's live MCP/PE checks.

MCP/session summary: active IDA MCP session `supervisor_recovery_20260705` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`. `server_health` returned `status: ok`, auto-analysis ready, Hex-Rays ready, strings cache ready. MCP calls were narrow and schema-current: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `get_global_value`, `make_signature_for_range`, `xrefs_to`, `trace_data_flow`, `find_bytes`, `entity_query`, `list_globals`, `disasm`, `search_structs`.

## Target

- Target UID: `0002X9`
- Target path: `by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md`
- Source queue/report row at assignment: `auto-generated/-ag-research-tracker.md` listed `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: not-covered reconstructable by-memory source-quality target.
- Current scores and parent state after callback: target `88/90`; owner/emitter [UID:0000LV][NewUserDialogPane](../../../by-file/NewUserDialogPane.md) is `86/88`; class support [UID:00009D][NewUserDialogPane](../../../by-class/NewUserDialogPane.md) is `86/90`.
- Entity kind: one-dword `.data` singleton pointer slot.
- Current generated state: `auto-generated/NexusTK/login/NewUserDialogPane.cpp` command `000000007333`, refreshed `2026-07-05T19:03:47-04:00`, contains UID0002X9 declaration `NewUserDialogPane *g_pNewUserDialogPane;` instead of an empty marker.

## Current Target State

Current post-callback metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LV`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LV`
- blank `EMITTER_POSITION_OPTIONAL`
- formal C++ block: `NewUserDialogPane *g_pNewUserDialogPane;`
- `Nested:0`

Pre-callback target prose correctly identified the older account-registration `NewUserDialogPane` lifecycle and the five refs at `0x004f9d91`, `0x004f9d98`, `0x004fa0df`, `0x005023f0`, and `0x005029a2`. The callback repaired these stale/incomplete parts:

- Historicalized old `0xffffffff` static-value wording under the current zero-fill / signature-layer discrepancy.
- Replaced current-name wording with operand label `unk_69B480` and missing durable name/global proof.
- Populated the formal C++ block because the current source route, score gate, and exact singleton declaration are strong enough.
- Changed `Nested:4` to `Nested:0`; the four-slot relationship belongs to [UID:00029H][MainMenuAccountDialogSingletons](../../../by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md).

## Heuristic / Inference Reanalysis And Validation

The target is not a method body, raw helper, or aggregate. It is one source-level singleton pointer declaration used by `NewUserDialogPane` lifecycle code. The current owner/emitter route is valid: constructor publish/fallback, cleanup-fragment clear, tiny clear helper, and scalar destructor clear all belong to the `NewUserDialogPane` file/class family. No consumer xrefs were found outside lifecycle cleanup, so a separate by-global support page is not currently required.

Source-facing name: `g_pNewUserDialogPane` is inferred from the dialog class name and existing project singleton naming convention. Current MCP does not recover a durable data symbol for the slot; `list_globals *NewUserDialogPane*` finds RTTI/vtables and `Singleton<NewUserDialogPane>` RTTI, but not a data-slot symbol. The name is still source-quality because adjacent accepted singleton pages use inferred `g_p...` names when original symbols are absent.

Initializer: current MCP has two contradictory byte surfaces. `get_bytes` and `get_global_value` report zero for `0x0069b480`, and a PE section-map read shows RVA `0x29b480` lies in `.data` virtual zero-fill beyond the section's raw-backed bytes. `make_signature_for_range`, however, returns `FF FF FF FF` for the same range and surrounding window. For source reconstruction, the zero-fill evidence is stronger for the source declaration form; the signature result should be preserved as a documented IDA/historical byte discrepancy and confidence cap.

C++ readiness: by-structure allows formal C++ when the target is reconstructable, has a valid emitter chain, and the combined score is greater than 85. UID0002X9 already clears that gate. The declaration only needs an incomplete `NewUserDialogPane` pointer type and the established file route; it does not require resolving full class layout or the final standalone-vs-folded account-dialog source split. The blank C++ marker should be replaced with the exact pointer declaration.

Rejected alternatives:

- Keep blank C++: rejected because the singleton declaration is source-ready. Before callback validation, generated output showed an empty marker only because the block was blank; after validation, UID0002X9 emits the pointer declaration.
- Create a new by-global page for `g_pNewUserDialogPane`: rejected for this pass because the slot has lifecycle-only refs, no external consumer/read matrix, no current IDB data symbol, and the by-memory page can carry the exact declaration through UID0000LV.
- Assign to [UID:00029H] aggregate: rejected because the aggregate spans four different dialog owners and is documented non-emitting.
- Assign to `LoginDialogPane`, `NewUserDialogPane2`, `MainMenuPane`, clear-helper, destructor-helper, or no-owner/non-emitting status: rejected by xref ownership and source-route evidence.

## Evidence Standards Used

Evidence was evaluated in four tiers:

1. Current live MCP facts for session health, function/non-function status, bytes/value reports, xrefs, data-flow, operand labels, pointer-byte searches, and disassembly.
2. Read-only PE section-map evidence to resolve the current MCP byte-tool conflict for source initializer shape.
3. Current by-* docs and generated output as state/route evidence, not as authority when contradicted by current MCP/PE checks.
4. Prior executed B reports as precedent for neighboring singleton declaration shape and byte-conflict handling, not as proof for UID0002X9.

The report preserves direct fact versus inference: the address, refs, no-function status, current missing-symbol state, and disassembly are direct MCP facts; `g_pNewUserDialogPane` and source placement are inferred source-facing conclusions; the formal zero-initialized declaration follows PE zero-fill plus project singleton declaration precedent.

## Evidence Checked

MCP and binary checks performed:

- `idb_list`: active session `supervisor_recovery_20260705`.
- `server_health`: `status: ok`; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; imagebase `0x400000`; auto-analysis, Hex-Rays, and strings ready.
- `lookup_funcs`: `0x0069b480` is not a function; `0x004f9d30` is `sub_4F9D30` size `0x379`; `0x005023f0` is `sub_5023F0` size `0xb`; `0x00502970` is `sub_502970` size `0x71`.
- `get_bytes`: `0x0069b480` size `4` returned four `0x0` bytes; `0x0069b47c` size `28` returned all zero bytes.
- `get_global_value`: `0x0069b480`, `0x0069b484`, `0x0069b488`, and `0x0069b48c` each returned `0x0`.
- `make_signature_for_range`: `0x0069b480-0x0069b484` returned `FF FF FF FF`; `0x0069b480-0x0069b490` and `0x0069b47c-0x0069b498` returned all `FF` bytes. This is retained as a current MCP tool-layer discrepancy.
- PE read-only check on `E:\NTK\Resources\NexusTK\NexusTK.exe`: `.data` `VirtualAddress 0x26d000`, `VirtualSize 0x2fe24`, `PointerToRawData 0x26ac00`, `SizeOfRawData 0xd800`; target RVA `0x29b480` maps into virtual zero-fill beyond the raw-backed portion. This supports a null/zero source declaration despite the signature-layer `FF` result.
- `xrefs_to 0x0069b480`: exactly five refs, `more:false`: `0x004f9d91`, `0x004f9d98`, `0x004fa0df`, `0x005023f0`, `0x005029a2`.
- `trace_data_flow backward 0x0069b480`: current operand name `unk_69B480`; constructor publish `mov dword ptr unk_69B480, eax`; constructor fallback clear; cleanup-fragment clear; helper clear; destructor clear.
- `find_bytes`: absolute VA pattern `80 B4 69 00` returned five hits at `0x004f9d92`, `0x004f9d9a`, `0x004fa0e1`, `0x005023f2`, and `0x005029a4`; RVA pattern `80 B4 29 00` returned zero hits.
- `entity_query`: no `names` or `globals` entries in `0x0069b480-0x0069b490`.
- `list_globals`: `*69B48*` returned no globals; `*NewUserDialogPane*` returned vtables/RTTI for `NewUserDialogPane` and `NewUserDialogPane2`, plus `Singleton<NewUserDialogPane>` RTTI, but no data-slot symbol.
- `disasm 0x004f9d30`: constructor publish/fallback sequence at `0x004f9d7b-0x004f9d98`, vtable stores at `0x004f9db8`, `0x004f9dbe`, and `0x004f9dc8`, and `DLGNEW01.EPF` resource load.
- `disasm 0x004fa0b0`: unregistered cleanup fragment restores the three `NewUserDialogPane` vtables, conditionally closes `unk_69AE08`, clears `unk_69B480`, and tail-jumps to inherited/base cleanup.
- `disasm 0x005023f0`: two-instruction clear helper `mov dword ptr unk_69B480, 0; retn`.
- `disasm 0x00502970`: scalar deleting destructor restores the three vtables, conditionally closes `unk_69AE08`, clears `unk_69B480`, calls inherited/base cleanup, and conditionally frees.
- `xrefs_to 0x004f9d30`, `0x005023f0`, `0x00502970`: constructor currently has no direct xrefs to its entry; clear helper has one xref from constructor SEH/unwind metadata at `0x006016d4`; scalar destructor has adjusted thunk refs at `0x00502514`, `0x0050251f`, and vtable data ref `0x0061d2ec`.
- `search_structs NewUserDialogPane`: no local struct/UDT record.

Docs/reports/generated checked:

- Current target, file/class/aggregate/core docs listed in Supporting Research.
- Neighbor singleton pages UID0002XI, UID0002XL, UID0002XM and by-global pages UID0000RE, UID0002X3.
- Generated `auto-generated/NexusTK/login/NewUserDialogPane.cpp` current marker state.
- Tracker and coverage rows for UID0002X9, UID0000LV, UID00009D, UID0002Q3, UID00029H.
- Executed B010 UID0002XL, B003 UID0002XM, and B010 UID00019J report leads.

Negative checks:

- No current function at target data slot.
- No current durable data symbol/global for `0x0069b480`.
- No RVA pointer-byte route for `0x0029b480`.
- No separate by-global page currently exists for `g_pNewUserDialogPane`.
- No external consumer/read refs beyond the five lifecycle writes/clears.
- No local UDT proving final header or original symbol spelling.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002X9-01 | UID0002X9 is one exact `NewUserDialogPane *` singleton pointer slot at `0x0069b480-0x0069b484`, not code. | High | `lookup_funcs 0x0069b480` not a function; exact one-dword target; xrefs all data refs. | Target Summary / Storage / Evidence. | incorporate | applied |
| C-0002X9-02 | Current source initializer should be null/zero, while old `0xffffffff` wording must be historicalized as byte-layer conflict. | Medium-high | `get_bytes` and `get_global_value` zero; PE `.data` virtual zero-fill; `make_signature_for_range` still returns `FF FF FF FF`. | Target Summary / Evidence / Score Rationale; aggregate support byte note. | historicalize | applied |
| C-0002X9-03 | Formal C++ should be `NewUserDialogPane *g_pNewUserDialogPane;`. | High | Valid owner/emitter route, combined score gate, zero-fill proof, accepted neighboring singleton declaration precedent. | Target `RECONSTRUCTION_CPP CODE`. | incorporate | applied |
| C-0002X9-04 | Target completion should move `85 -> 88`; confidence should remain `90`. | High | Current MCP/PE evidence resolves C++ and stale-byte blockers; confidence capped by missing original symbol, no UDT, and byte-tool discrepancy. | Target metadata / Score Rationale. | incorporate | applied |
| C-0002X9-05 | `Nested:4` should become `Nested:0`. | High | Exact one-slot child contains no subitems; the four-slot relationship belongs to UID00029H aggregate. | Target metadata / Item Summary. | incorporate | applied |
| C-0002X9-06 | Keep `CANONICAL_OWNER:0000LV`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LV`. | High | Constructor/cleanup/helper/destructor refs are NewUserDialogPane lifecycle; file parent clears gate and generated route exists. | Target metadata / Ownership Decision. | already-present | already-present |
| C-0002X9-07 | Current IDA data name is not recovered; use `unk_69B480` as current operand label and `g_pNewUserDialogPane` as inferred source-facing name. | High | `trace_data_flow` name `unk_69B480`; bounded name/global queries empty; no `*69B48*` global. | Target Summary / Evidence / Open Questions. | incorporate | applied |
| C-0002X9-08 | Preserve exact five lifecycle refs and pointer-byte hits. | High | `xrefs_to` five refs; VA byte pattern five hits; RVA pattern zero hits. | Target Evidence / Lifecycle Refs table. | incorporate | applied |
| C-0002X9-09 | Support docs should record UID0002X9 as source-ready singleton declaration through NewUserDialogPane.cpp. | High | Pre-callback generated output had an empty marker; callback validation now routes the target declaration through UID0000LV. | `by-file/NewUserDialogPane.md`, `by-class/NewUserDialogPane.md`. | incorporate | applied |
| C-0002X9-10 | Aggregate UID00029H should remain non-emitting but sync UID0002X9 child row/detail after target update. | High | Aggregate is mixed-owner; child owns exact declaration; current aggregate still lists stale child `85/90` and old byte wording context. | `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`. | incorporate | applied |
| C-0002X9-11 | Do not create a new by-global page for `g_pNewUserDialogPane` in this callback. | Medium-high | No durable IDB symbol, no external consumer/read matrix, and target can emit exact declaration through file owner. | Report/source placement; no by-global file. | not-applicable | excluded-with-reason |
| C-0002X9-12 | Reject ownership by UID00029H aggregate, LoginDialogPane, NewUserDialogPane2, MainMenuPane cleanup, helper/destructor-only code, raw names, or no-owner/non-emitting status. | High | Xref ownership, source route, generated marker, mixed aggregate status, and current support docs. | Target Ownership Decision / Negative Evidence; support prose. | reject-invalid | applied |
| C-0002X9-13 | Generated `NewUserDialogPane.cpp` should refresh away from the UID0002X9 empty marker after validation. | High | Pre-callback generated file showed UID0002X9 empty marker; post-validator generated file now contains the formal declaration. | Report checklist / validator expectations. | incorporate | applied |

## Positive Evidence Summary

- Current MCP confirms `0x0069b480` is not a function and has exactly five direct data refs.
- Refs form a complete lifecycle: constructor publish at `0x004f9d91`, constructor fallback clear at `0x004f9d98`, cleanup-fragment clear at `0x004fa0df`, helper clear at `0x005023f0`, destructor clear at `0x005029a2`.
- Constructor disassembly shows the adjusted-pointer publish pattern: `lea eax, [esi+26Ch]`, test, subtract `0x26c`, store to `unk_69B480`, fallback store zero.
- Cleanup fragment and destructor restore the three `NewUserDialogPane` vtable views, close the active dimmer/global if present, and clear the singleton.
- Absolute VA pointer-byte search has five hits exactly matching the xrefs; RVA pattern has none.
- File/class docs already place the lifecycle in the older account-registration `NewUserDialogPane` route and distinguish it from `NewUserDialogPane2`.
- Current generated output has an empty UID0002X9 marker, proving the route exists and only the formal C++ block is missing.
- PE section-map evidence supports null zero-fill for the source declaration.

## IDA MCP Facts

| Fact | Current evidence |
| --- | --- |
| Session | `supervisor_recovery_20260705`, health `ok`, `NexusTK.exe`, imagebase `0x400000`, analysis/Hex-Rays/strings ready. |
| Target function status | `lookup_funcs 0x0069b480` -> `Not a function`. |
| Target value conflict | `get_bytes`/`get_global_value` -> zero; `make_signature_for_range` -> `FF FF FF FF`. |
| Current operand label | `trace_data_flow` reports `unk_69B480`; bounded name/global queries found no durable symbol. |
| Direct refs | `0x004f9d91`, `0x004f9d98`, `0x004fa0df`, `0x005023f0`, `0x005029a2`; `more:false`. |
| Pointer-byte hits | VA pattern `80 B4 69 00` -> five hits matching ref operands; RVA pattern `80 B4 29 00` -> zero hits. |
| Constructor | `sub_4F9D30`, size `0x379`, stores adjusted pointer or zero and then writes three `NewUserDialogPane` vtables. |
| Cleanup fragment | `0x004fa0b0` has no function object; restores vtables, clears `unk_69B480`, and tail-jumps to inherited/base cleanup. |
| Clear helper | `sub_5023F0`, size `0xb`, exactly clears `unk_69B480` and returns. |
| Destructor | `sub_502970`, size `0x71`, restores vtables, clears `unk_69B480`, runs inherited/base cleanup, and conditionally frees. |
| Type evidence | `search_structs NewUserDialogPane` -> no local struct/UDT record. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069b480-0x0069b484` | UID0002X9 target | Exact older account-registration singleton slot | TRUE | UID0000LV | current `85/90`; recommend `88/90` | Source-ready declaration recommended. |
| `0x004f9d30-0x004fa7a0` | UID0002Q3 | NewUserDialogPane constructor/helper island | TRUE | UID0000LV | `86/90` | Support evidence for lifecycle refs. |
| `0x0069b480-0x0069b490` | UID00029H | Mixed four-slot singleton aggregate | FALSE | NONE | `91/93` | Non-emitting bridge; support row/detail sync recommended. |
| `0x0069b484-0x0069b488` | UID0002XI | LoginDialogPane singleton slot | TRUE | UID0000RE | `86/91` | Neighbor precedent; by-global due broad consumers. |
| `0x0069b488-0x0069b48c` | UID0002XL | NewUserMiscDialogPane singleton slot | TRUE | UID0000LX | `88/90` | Neighbor declaration precedent with null initializer. |
| `0x0069b48c-0x0069b490` | UID0002XM | ChangePasswordDialogPane singleton slot | TRUE | UID0000I3 | `88/90` | Neighbor declaration precedent with byte-conflict note. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f9d91` | data ref inside `sub_4F9D30` | Constructor publishes adjusted `NewUserDialogPane` pointer. |
| `0x004f9d98` | data ref inside `sub_4F9D30` | Constructor fallback clears the singleton. |
| `0x004fa0df` | data ref in unregistered cleanup fragment | Constructor/unwind cleanup clears the singleton after vtable restoration and dimmer cleanup. |
| `0x005023f0` | data ref in `sub_5023F0` | Tiny explicit singleton-clear helper. |
| `0x005029a2` | data ref in `sub_502970` | Scalar deleting destructor clears the singleton. |
| `0x004f9d30` | constructor function entry xrefs currently zero | No extra direct caller evidence from MCP; lifecycle ownership relies on internal constructor behavior and file/class docs. |
| `0x005023f0` | one xref from `0x006016d4` inside constructor SEH/unwind metadata | Helper appears in constructor unwind/lifecycle metadata, not as an independent source owner. |
| `0x00502970` | adjusted thunk refs `0x00502514`, `0x0050251f`, vtable data ref `0x0061d2ec` | Destructor family belongs to `NewUserDialogPane` vtable/lifecycle. |

## Documentation Evidence And IDA Status

Current docs already support the broad owner route:

- Target UID0002X9 identifies `g_pNewUserDialogPane` as the older account-registration singleton and assigns it to UID0000LV.
- UID0002Q3 documents the constructor, cleanup fragment, helper island, vtable slots, and singleton xrefs.
- UID0000LV and UID00009D document the old account-registration dialog and explicitly distinguish it from UID0000LW/UID0002X3 `NewUserDialogPane2`.
- UID00029H documents the four-slot account-dialog cluster as mixed-owner and non-emitting.
- Generated `NewUserDialogPane.cpp` contains UID0002X9 as an empty marker, confirming the source-output route but exposing the blank C++ blocker.

Stale/incomplete documentation state:

- Target static value says `0xffffffff`; current source initializer evidence supports null zero-fill, with `FF` retained only as signature-layer/historical conflict.
- Target current IDA name says `dword_69B480`; current MCP operand label is `unk_69B480`, and no symbol/global entry exists.
- Target `Nested:4` is wrong for an exact one-slot child.
- Support docs do not yet state UID0002X9 is source-ready with formal declaration.

## Ranked Ownership Analysis

### 1. UID0000LV `NewUserDialogPane`

Evidence for: constructor publish/fallback, cleanup-fragment clear, clear helper, destructor clear, class vtables, resource `DLGNEW01.EPF`, and file/class docs all identify the old account-registration `NewUserDialogPane` lifecycle. The by-file page is the generated source root and already emits to `auto-generated/NexusTK/login/NewUserDialogPane.cpp`.

Evidence against: exact original standalone-vs-folded source file split remains unresolved; no local UDT proves final header layout. Those are confidence caps, not owner blockers.

Decision: accepted. Keep `CANONICAL_OWNER:0000LV` and `EMITTER_UIDS:0000LV`.

### 2. New by-global page `g_pNewUserDialogPane`

Evidence for: by-global is a canonical home for singleton pointers, and sibling `g_pLoginDialogPane` / `g_pNewUserDialogPane2` have by-global pages.

Evidence against: current MCP has no durable data symbol, no external consumer/read matrix, and the target by-memory page already owns exact address evidence and can emit through UID0000LV. Sibling UID0002XL and UID0002XM demonstrate that a one-slot lifecycle singleton can emit from the by-memory child through the dialog file owner without adding a duplicate by-global page.

Decision: do not create in this callback. Revisit only if future evidence finds external consumers or a recovered symbol/alias that needs a high-traffic symbol page.

### 3. UID00029H `MainMenuAccountDialogSingletons`

Evidence for: physical containing range and child split context.

Evidence against: it is a mixed-owner non-emitting bridge over NewUserDialogPane, LoginDialogPane, NewUserMiscDialogPane, and ChangePasswordDialogPane. It must not emit a shared declaration block.

Decision: support/index only; update child detail if callback is accepted.

### 4. LoginDialogPane / NewUserDialogPane2 / MainMenuPane / clear helpers / raw global

Evidence for: these are neighboring or cleanup-context pages and source-family relatives.

Evidence against: none of them writes the UID0002X9 lifecycle except as generic cleanup or sibling context. `NewUserDialogPane2` is a separate create-user variant at `0x0069b4a4`; `LoginDialogPane` starts at the next slot `0x0069b484`; MainMenu cleanup reports do not read UID0002X9; clear helper/destructor refs are lifecycle effects, not declaration owners.

Decision: reject as direct owners.

## Source Placement

Recommended placement is `login/NewUserDialogPane.cpp` through [UID:0000LV][NewUserDialogPane](../../../by-file/NewUserDialogPane.md). This matches the constructor/destructor lifecycle and the existing generated source route. The declaration should live with the old account-registration dialog, not with `NewUserDialogPane2`, the mixed aggregate, or a broad account-dialog singleton array.

Remaining placement uncertainty: final original organization may have folded this old account-registration code into `LoginDialogPane.cpp`; the current project already has a valid `NewUserDialogPane.cpp` source root and the singleton route should follow it unless a future file-level consolidation pass changes UID0000LV itself.

## Range / Split / Padding / Reclassification Analysis

The target range is exact and should not be split or widened:

- Target: `0x0069b480-0x0069b484`.
- Previous range: [UID:00029G][StartupLogoBinkPlaybackGlobals](../../../by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md) ends at `0x0069b480`.
- Next sibling: UID0002XI starts at `0x0069b484`.
- Parent bridge UID00029H covers `0x0069b480-0x0069b490` and should remain `RECONSTRUCTABLE:FALSE`.

No padding exists inside the target; it is one dword of singleton pointer storage. Current `Nested:4` belongs to the aggregate relationship, not this exact child, so the target should use `Nested:0`.

## Negative Evidence Summary

- No current IDA/MCP function object exists at `0x0069b480`.
- No durable data global/name exists at `0x0069b480`; the current operand label is `unk_69B480`, not recovered source spelling.
- No RVA pointer-byte route exists for `0x0029b480`.
- No external consumer/read refs were found for this slot, unlike `g_pLoginDialogPane`.
- No local UDT/header record proves the exact original `NewUserDialogPane` declaration.
- `make_signature_for_range` returns `FF FF FF FF`, conflicting with `get_bytes`, `get_global_value`, and PE zero-fill; therefore exact initializer/source spelling remains confidence-capped.
- The mixed aggregate, helper functions, destructor thunks, MainMenu cleanup, LoginDialogPane, and NewUserDialogPane2 are not direct declaration owners.

## IDA Rename / Type / Comment Recommendations

No IDA DB rename, type, or comment edit was requested or performed in this callback. In documentation/source, use:

- source-facing name: `g_pNewUserDialogPane` (inferred, not recovered-original proven);
- current operand label: `unk_69B480`;
- type: `NewUserDialogPane *`;
- initializer/source form: no explicit initializer, relying on static zero-initialization.

Do not rename the IDA database from this pass. The source-quality documentation can use the inferred name without modifying IDA state.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The page is reconstructable, has a nonblank emitter route to a valid by-file source root, and the combined score is greater than 85.

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
NewUserDialogPane *g_pNewUserDialogPane;
```

Reason it preserves behavior: the declaration produces null-initialized global pointer storage for the singleton, matching current `get_bytes`/`get_global_value` and PE zero-fill evidence. Constructor/destructor/helper code publishes or clears the pointer at runtime.

Reason it matches plausible source shape: adjacent dialog singleton declarations use the same project naming style and pointer declaration shape. The complete class layout is not needed for a pointer declaration; an incomplete `NewUserDialogPane` type is enough at declaration point.

Rejected C++ forms:

- `NewUserDialogPane *g_pNewUserDialogPane = (NewUserDialogPane *)-1;`: rejected for current source form because PE zero-fill and value reads prove null initialization, although the IDA signature-layer `FF` conflict should be documented.
- `DWORD dword_69B480;`, `void *unk_69B480;`, or raw address names: rejected as decompiler/IDA-shaped output.
- A shared four-slot array/block in UID00029H: rejected because the aggregate crosses dialog owners.

## Final Recommendation

Implementation callback status: applied on 2026-07-05 after supervisor Gate 1 pass for SHA256 `D936738D41B3604A3D5F34DFC0863F13BEE6546A09AFD99E2FAB1C84FA5F21DE`.

Accepted target and narrow support updates:

1. Target UID0002X9: raise completion to `88`, keep confidence `90`, keep owner/emitter/reconstructable metadata unchanged, change `Nested:4` to `Nested:0`, and insert `NewUserDialogPane *g_pNewUserDialogPane;` into the formal C++ block.
2. Target prose: update current value/name evidence, exact lifecycle refs, MCP session, PE zero-fill resolution, IDA signature-layer `FF` conflict, no-function/no-symbol proof, source placement, rejected alternatives, and score rationale.
3. `by-file/NewUserDialogPane.md` and `by-class/NewUserDialogPane.md`: add narrow prose that UID0002X9 is now source-ready as the old account-registration singleton pointer declaration emitted through UID0000LV.
4. `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`: keep non-emitting aggregate status; update UID0002X9 child detail to reflect `88/90`, source-ready declaration through UID0000LV, current B004 zero-fill evidence, and preserved `FF` signature/session conflict.
5. Do not create or edit a new `by-global/g_pNewUserDialogPane.md`; this was intentionally excluded because the callback scope did not authorize it and the evidence does not require it.

## Recommended Target Doc Changes

Target path: `by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md`

Recommended metadata:

- `COMPLETION:85 -> 88`
- `CONFIDENCE:90` unchanged
- `CANONICAL_OWNER:0000LV` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000LV` unchanged
- blank `EMITTER_POSITION_OPTIONAL` unchanged
- `Nested:4 -> 0`

Recommended formal C++:

```cpp
NewUserDialogPane *g_pNewUserDialogPane;
```

Facts to incorporate at report-level detail:

- Current MCP session `supervisor_recovery_20260705` health and IDB path.
- Exact target range and no-function status.
- `get_bytes`/`get_global_value` zero results, PE `.data` zero-fill proof, and `make_signature_for_range` `FF` conflict.
- Current operand label `unk_69B480`, no durable `names`/`globals` entry, and `g_pNewUserDialogPane` as inferred source-facing spelling.
- Exact five refs and pointer-byte hits.
- Constructor publish/fallback sequence, cleanup fragment, clear helper, destructor clear.
- Rejection of aggregate ownership, new by-global creation, LoginDialogPane/NewUserDialogPane2 ownership, raw names, and blank-C++/no-code treatment.
- Generated empty-marker state and expected generated declaration after validation.

## Recommended Support Doc Changes

Support path: `by-file/NewUserDialogPane.md`

- Add a narrow singleton/source-route note: UID0002X9 is the source-ready old account-registration singleton pointer declaration emitted through this file route as `NewUserDialogPane *g_pNewUserDialogPane;`.
- Preserve file score `86/88`; no broad file score movement is justified by a one-dword singleton update.
- Preserve the standalone-vs-folded `NewUserDialogPane.cpp` / `LoginDialogPane.cpp` caveat as file-level, not a blocker for the exact declaration.

Support path: `by-class/NewUserDialogPane.md`

- Add a narrow class-owned-state note that the class lifecycle publishes/clears UID0002X9 and that the source-facing singleton name is inferred.
- Preserve class score `86/90`; no class-level score movement is required because class field/control names and cleanup-fragment source shape remain unresolved.

Support path: `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`

- Keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter/C++ fields, and mixed-owner bridge status.
- Update the UID0002X9 child row/detail to `88/90`, source-ready declaration through UID0000LV, current B004 `get_bytes`/PE zero-fill evidence, and the `make_signature_for_range` `FF` conflict.
- Preserve B010/B003 session-qualified byte conflict text; do not flatten all slots to one initializer claim.

No support edit recommended:

- `by-global/g_pNewUserDialogPane2.md`: already distinguishes the create-character/alternate `NewUserDialogPane2` singleton and does not need a UID0002X9 edit.
- `by-global/g_pLoginDialogPane.md`: sibling/global precedent only.
- New `by-global/g_pNewUserDialogPane.md`: not recommended for current callback.

## Score And Metadata Recommendation

Current target score/metadata: `85/90`, owner/emitter UID0000LV, reconstructable true, blank C++, `Nested:4`.

Recommended target score/metadata: `88/90`, owner/emitter UID0000LV unchanged, reconstructable true unchanged, formal pointer declaration, `Nested:0`.

Score rationale:

- Completion rises to `88` because the report resolves the blank-C++ blocker, stale current-name wording, stale current initializer wording, nested-count issue, source placement, by-global decision, xref evidence, pointer-byte checks, and generated empty-marker state.
- Confidence stays `90` because the exact address, refs, owner route, and declaration are strong, but exact original symbol spelling is inferred, no local UDT/header exists, final old-account source split remains unresolved, no external consumer read matrix exists, and current MCP byte tools conflict (`get_bytes`/value zero versus signature `FF`).
- Do not raise above `90` until the byte-layer discrepancy is reconciled or the page records a stronger project-wide policy for signature-layer versus zero-fill evidence on virtual `.data` tail slots.

Metadata fields:

- Keep owner/emitter/reconstructable fields unchanged.
- Change `Nested` to `0`.
- Add formal C++ declaration.
- No rename/split/new child.
- No IDA DB rename/type/comment.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / impact |
| --- | --- | --- |
| Is the slot initialized to null or `-1`? | MCP `get_bytes`, `get_global_value`, `make_signature_for_range`; PE section-map read. | Best source recommendation is null/zero declaration because the target RVA is virtual zero-fill and MCP value reads are zero. `FF` signature result remains a documented confidence cap. |
| Is `g_pNewUserDialogPane` an original recovered symbol? | `entity_query`, `list_globals`, `trace_data_flow`, support docs. | No. Use it as inferred source-facing name; current operand label is `unk_69B480`. |
| Is a separate by-global page required? | by-global guidance, sibling global pages, xref fanout, current symbol checks. | No current need. Lifecycle-only refs and no durable symbol make the exact by-memory declaration sufficient. |
| Does unresolved class layout block C++? | class/file docs, by-structure C++ gate, neighbor singleton precedent. | No. A pointer declaration does not require full class layout. |
| Should the target remain blank C++ due old source split caveat? | Generated route, owner file, support docs, neighbor precedents. | No. Source split remains a file-level confidence cap, not a declaration blocker. |
| Is `Nested:4` valid? | Target page, aggregate page, sibling one-slot pages. | No. The exact child has no nested subitems; change to `Nested:0`. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. The tracker and generated coverage rows are validator-owned. If the supervisor accepts this report, update source by-* docs and run scoped validators; do not manually edit `auto-generated/-ag-*` reports or coverage reports.

## Follow-Up Actions

Supervisor Gate 2 should verify the target/support incorporation, scoped validator results, generated source freshness, and report ledger/checklist state. B004 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, or a new by-global page.

## Confidence

Recommendation confidence: high for source-ready singleton declaration and owner/emitter route; medium-high for exact initializer wording due MCP byte-layer conflict; medium-high for exact source symbol spelling because it remains inferred.

No blocker remains for supervisor Gate 2 review from B004's side. The only remaining confidence caps are byte-layer reconciliation, exact original symbol spelling, full class/header layout, and final old-account source file grouping.

## Validator Results

Callback validators were run from `source-3/project-documentation` after the accepted by-* edits:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md --apply --queue-timeout 240` | `000000007331` | `2026-07-05T19:03:29-04:00` | 0 | 1 | Updated completion to `88`; autogen registry changed UID0002X9 from blank to block; generated refresh deferred. |
| `by-file/NewUserDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/NewUserDialogPane.md --apply --queue-timeout 240` | `000000007332` | `2026-07-05T19:03:35-04:00` | 0 | 1 | Validator normalized one UID0002X9 link label and reported deferred generated refresh. |
| `by-class/NewUserDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/NewUserDialogPane.md --apply --queue-timeout 240` | `000000007333` | `2026-07-05T19:03:47-04:00` | 0 | 1 | Validator normalized two UID0002X9 link labels and performed deferred generated refresh. |
| `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md --apply --queue-timeout 240` | `000000007334` | `2026-07-05T19:03:55-04:00` | 0 | 1 | Aggregate support doc validated; generated refresh deferred. |

Generated freshness observation:

- Read-only inspection of `auto-generated/NexusTK/login/NewUserDialogPane.cpp` after validators shows header `validator-command-id: 000000007333`, `validator-refreshed-at: 2026-07-05T19:03:47-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID0002X9 is no longer an empty marker. The generated file contains:

```cpp
// UID:0002X9 | by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md | Completion:88 | Confidence:90
NewUserDialogPane *g_pNewUserDialogPane;
```

- Unrelated UID00009D class and UID0002Q3 core pages remain empty markers in the generated file because their formal C++ blocks are still blank; that is outside this callback.

## Changed Files

Manually edited by B004 during this callback:

- `tools/leaser/Agents/Agent-B004/research/0002X9-g_pNewUserDialogPane-source-quality.md`
- `by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md`
- `by-file/NewUserDialogPane.md`
- `by-class/NewUserDialogPane.md`
- `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`

Validator-owned generated/project side effects observed from the scoped validators:

- `auto-generated/NexusTK/login/NewUserDialogPane.cpp` refreshed and now emits UID0002X9 declaration.
- `project-level/-auto-completion-stats.md` was reported by validator output as updated in the projected path completion section.

Not manually edited by B004:

- generated files
- coverage reports
- validator state
- lifecycle/archive/report execution locations
- supervisor ledgers
- `by-global/g_pNewUserDialogPane.md` or any other by-global page
- unrelated target/support by-* docs
- IDA DB

Leases:

- Acquired immediately before edits: `python .\tools\leaser\leaser.py B004 lease by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md by-file/NewUserDialogPane.md by-class/NewUserDialogPane.md by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`
- Lease result: success for all four files.
- Released immediately after validators: `python .\tools\leaser\leaser.py B004 unlease by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md by-file/NewUserDialogPane.md by-class/NewUserDialogPane.md by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`
- Release result: success for all four files.
- Read-only lease check after release: `tools/leaser/Agents/current_leases.md` reported no active leases.

Report execution: not run. B004 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, report moves, or archive moves.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Gate 1 passed for SHA256 `D936738D41B3604A3D5F34DFC0863F13BEE6546A09AFD99E2FAB1C84FA5F21DE`.
- [x] Target/support docs to update: target `by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md`; support `by-file/NewUserDialogPane.md`, `by-class/NewUserDialogPane.md`, and `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`.
- [x] Current target state and actual evidence checked recorded: initial `85/90`, owner/emitter UID0000LV, blank C++, `Nested:4`, generated empty marker, current MCP facts, PE zero-fill check, support docs, generated/tracker rows, and old report leads.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: report-only rows were `proposed`; callback rows now use `applied`, `already-present`, or `excluded-with-reason`.
- [x] Metadata/score changes to apply: target now has `COMPLETION:88`, `CONFIDENCE:90` unchanged, `Nested:0`, owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched to resolution: blank C++ resolved with formal declaration; by-global creation rejected for current pass; current-name and initializer evidence resolved with documented caps; aggregate/nested issue converted into exact repair.
- [x] Owner/emitter/reconstructable changes to apply or confirm unchanged: UID0000LV owner/emitter and `RECONSTRUCTABLE:TRUE` confirmed unchanged.
- [x] Split/rename/new-child changes to apply or confirm not applicable: no split/rename/new child; no new by-global page created.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: kept `login/NewUserDialogPane.cpp` route; no IDA DB edit; target is one dword, no padding; aggregate remains non-emitting.
- [x] First-draft C++ to apply: `NewUserDialogPane *g_pNewUserDialogPane;` inserted in target formal C++ block.
- [x] Third-party import directive not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP session, bytes/value/signature conflict, PE zero-fill, xrefs, constructor/cleanup/helper/destructor evidence, missing-symbol caveat, generated empty marker, owner/source-placement rationale, rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale `0xffffffff` wording historicalized as byte-layer conflict; raw `dword_`/`unk_` source names rejected; aggregate/by-global/LoginDialogPane/NewUserDialogPane2/MainMenu/helper/no-owner routes rejected.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale where applicable: generated output treated as lead/state only; no stale Wave2/Wave3 source used as authority.
- [x] Open questions closed or documented as evidence-backed unresolved: exact original symbol spelling, byte-layer discrepancy, local UDT/header, and final source split remain confidence caps.
- [x] Validators to run after callback: scoped target validator plus support validators for all three edited support docs ran as command IDs `000000007331` through `000000007334`.
- [x] Generated report refresh expected: `auto-generated/NexusTK/login/NewUserDialogPane.cpp` replaced UID0002X9 empty marker with `NewUserDialogPane *g_pNewUserDialogPane;`; no manual generated/coverage/tracker edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: callback received after Gate 1 pass at SHA256 `D936738D41B3604A3D5F34DFC0863F13BEE6546A09AFD99E2FAB1C84FA5F21DE`.
- [x] All accepted target/support doc details incorporated at report-level detail into the target, file support, class support, and aggregate support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-0002X9-01 through C-0002X9-13 now show callback states.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target is `88/90`, owner/emitter UID0000LV unchanged, `Nested:0`, no split/rename/new child, no new by-global page, formal C++ inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target and aggregate historicalize the `0xffffffff` / `FF FF FF FF` conflict; rejected aggregate/by-global/LoginDialogPane/NewUserDialogPane2/MainMenu/helper/no-owner/raw-name alternatives are recorded.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact symbol spelling, byte-tool discrepancy, local UDT/header, and final old-account source split remain documented confidence caps.
- [x] Validators run and results recorded with command id/timestamp/exit/ok/warnings: command IDs `000000007331`, `000000007332`, `000000007333`, and `000000007334`, each exit `0`, `ok:1`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated source refreshed by deferred command `000000007333`; UID0002X9 emits the declaration. No manual supervisor-owned coverage/tracker text supplied because validator-owned generated files refreshed.
- [x] Remaining unapplied accepted items listed with exact blocker: none. The only accepted exclusion is no new by-global page, recorded as `excluded-with-reason` for C-0002X9-11.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007336","destination_path":"executed-b-agent-research/B004/0002X9-g_pNewUserDialogPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002X9-g_pNewUserDialogPane-source-quality.md","timestamp":"2026-07-05T19:13:35-04:00","uid":"0002X9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
