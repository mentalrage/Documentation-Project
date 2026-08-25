** TARGET-REPORT-UID:0004AS **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004AS IntegrateMacroEditControlPaneOnHide Ownership / Split Research


## Finalized Report / Current Recommendation

- UID0004AS is a live, source-authored `IntegrateMacroEditControlPane` virtual member. The callback has replaced the historical semantically wrong `OnHide` name/body with source-facing `RemoveFromLayer()` under the same UID and exact `[0x005805c0,0x005805da)` range.
- UID0004AS is now `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md` at `92/94`, with owner/emitter UID00006M, reconstructable true, blank position, `Nested:0`, and Destination 1 byte-for-byte.
- The exact behavior is: if owned `m_textEdit` at `+0x110` is non-null, dispatch its virtual `RemoveFromLayer()` first; then unconditionally invoke `Pane::RemoveFromLayer()` on the containing row. The authored source is `void`, has no explicit return, and does not handwrite the compiler tail jump.
- Adjacent UID0004AR is now the paired `AddToLayer(...)` override, not `OnAttachToParent`. Its validator-authorized canonical page is `by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md` at `92/94`; the evidence-time IDA modeled envelope `[0x00580550,0x005805b3)`, size `0x63` / 99 bytes, remains explicit historical binary provenance rather than a second child.
- The complete UID00006M class declaration now contains the inherited public `AddToLayer`/`RemoveFromLayer` pair while preserving all prior fields and methods. The non-emitting UID0001IK index, UID0003DB vtable evidence, UID0001Y1 type-level vtable evidence, and by-file MacroDialogs prose are synchronized. Pane/TextEditPane/ScrollablePane support remains same-or-greater and verify-only.
- Historical `OnHide`, `ControlPane::OnHide`, `OnAttachToParent`, `Rect`-based attach signature, and generic parent-attachment wording remain useful provenance only when labeled superseded by exact slot and base-family evidence.
- Callback status: B002 applied all accepted C01-C30 work, all six managed blocks, both UID-preserving path/name corrections, and all bounded support synchronization. Seven ordinary pages passed scoped validation, waited generation passed, all leases were released, and B002 made no manual coverage, generated, tracker, audit, supervisor, lifecycle, archive, or IDA edit. Report execution/movement/archive remain supervisor/validator-owned facts rather than assertions by this artifact.
- Post-callback coverage status: the supervisor externally applied and validated all seven accepted manual rows under commands 14676-14679. Current readback is `7/7`, each exact row occurs once, and B002's ordinary implementation/generated proof remains unchanged.

## Supporting Research

- Historical pre-callback target page: `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneOnHide.md`, SHA256 `D774CB01A82D372B1582437238A68E4A85F795C4EB100A1A331744E3927C36AC`, 1,806 bytes / 35 lines. It no longer exists after the UID-preserving path correction.
- Current target page: `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md`, SHA256 `4EA3EB3FCFEDA483AD2358D907F1BD476A6D087CA1DF275224164A9CBF00727C`, 7,628 bytes / 86 lines.
- Historical pre-callback sibling page: `by-memory/0x00580550-0x005805b3.IntegrateMacroEditControlPaneOnAttachToParent.md`, SHA256 `F07679C8C5A8699F33693A471FA067E614C681A4E30B17BAC96632767653FB0E`, 2,361 bytes / 40 lines. It no longer exists after the UID-preserving correction.
- Current sibling page: `by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md`, SHA256 `156A2AE3FD4F09C0F38214734B10CD021CE1937C7962BE01ECDD6B9AD6B341F1`, 7,181 bytes / 84 lines. Its canonical validator endpoints and historical 99-byte IDA envelope are both stated explicitly.
- Current complete class: `by-class/IntegrateMacroEditControlPane.md`, SHA256 `60EED15DA1C9C92986D18B51DA6C52566AA616E9395002A30B5522ECAC0FFA30`, 35,444 bytes / 207 lines, `92/94`, position 30.
- Current split index: `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`, SHA256 `6EFCC82B78802C25BC2052AB4F2014256E3BA25A9173F1ADC4D1971FDB75B41E`, 53,806 bytes / 241 lines, non-emitting `91/93`.
- Current exact vtable data: `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`, SHA256 `7E590CC1290F9BA3D18157F1472BE3854D12E2DFD6E5FD716A5D653CCA69BDD8`, 20,715 bytes / 95 lines.
- Current type vtable family: `by-type/by-vtable/MacroDialogFamilyVtables.md`, SHA256 `6DA2F0E370F041141908488A11AEA9BF5F0BE2D9FAE703EDFBBA269BA5525504`, 40,712 bytes / 191 lines.
- Current source owner: `by-file/MacroDialogs.md`, SHA256 `346D829774A86A071C82FA80071CC664F389911C53F2169FCB750CAC7C768FDC`, 95,897 bytes / 326 lines.
- Same-or-greater base/type support final read: `PaneVtables.md` SHA256 `B8381FCA8BC9F44C3D19CA1112CF54A5BA8D3C2BD465A071D3303D31DB763B82`; `PaneLayout.md` SHA256 `93749A6EEF74D1BBBDCACF0D4BAE1476C086105133C4D0E4A3429D9C928AFE89`; `ControlPane.md` SHA256 `3F2C4D1A118EC77BE1062DDEA6AA5F7D6A0810C924B8072BF76DC6108938508B`; and current `TextEditPane.md` SHA256 `36CFA7951D9C1AE83F1C92EE0B501C42491F7D976F12F78E4F560D7502556FBE`. The earlier TextEditPane SHA `A4315D82...497F3` is an evidence-time pre-concurrent-callback snapshot; current content retains same-or-greater lifecycle declarations.
- Strong lifecycle comparators read: UID0004KO ScrollableControlPaneAddToLayer SHA256 `9DFD38771335C7A52942790A58524094597CF79E167306C966423F42BB37AA5C`; UID0004KP ScrollableControlPaneRemoveFromLayer SHA256 `319C3AED7D1603197B40A274D5B1BE65BA4F4485276FB757723F1A50A30D659F`; UID0004KA TextEditControlPaneLayerLifecycle SHA256 `3242707563C0AB53208F919682C4D59D1DBD1FE4FF02437239C9D28BEF55A296`.
- Historical pre-callback generated checkpoint: `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, command `000000014655`, refreshed `2026-07-19T20:34:36-04:00`, SHA256 `F2F50D8146C821F58331CD22C1AA0C4550694E67B7A02A1C38C95C2A0C97F4BD`, 35,033 bytes / 1,053 lines, with one stale UID0004AR `OnAttachToParent`, one stale UID0004AS `OnHide`, and zero corrected definitions.
- Current waited generated checkpoint: command/header `000000014675`, refreshed `2026-07-19T21:20:04-04:00`, SHA256 `AC80ED55CF38D3544E2E76517DDE1F5096ABBD274E7B87D347B74346CE59409F`, 35,335 bytes / 1,062 lines. Direct readback proves one complete Integrate class, one AddToLayer definition before one RemoveFromLayer definition, zero stale Integrate OnAttachToParent/OnHide declarations or definitions, zero UID0004AR/UID0004AS Empty Emitter Markers, and zero handwritten raw vtable/RTTI arrays, cookie code, tail jumps, or target-specific scalar wrappers.
- Report roots were searched independently; older reports are leads, not substitutes for the live target analysis below.

## Target

- UID: `0004AS`.
- Current path: `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md`.
- Historical pre-callback path: `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneOnHide.md`.
- Exact range: `[0x005805c0,0x005805da)`, 26 bytes.
- Current classification: reconstructable source-authored virtual method, `92/94`, owner/emitter UID00006M, blank position, `Nested:0`.
- Historical pre-callback classification: reconstructable method `86/90` under the `OnHide` heuristic.
- The UID and exact machine range remained stable through the applied semantic rename.

## Current Target State

- Historical pre-callback state: the page emitted a syntactically complete but semantically wrong `OnHide()` body that called `m_textEdit->OnHide()` followed by `ControlPane::OnHide()`.
- Live binary evidence shows UID0004AS is installed at IntegrateMacroEditControlPane primary vtable offset `+0x38`. Pane primary offset `+0x38` is `Pane::RemoveFromLayer`, while Pane `Hide` is offset `+0x18`. The historical `OnHide` name could not be correct and has been superseded.
- The machine body reads only `this+0x110`, conditionally dispatches that child's primary slot `+0x38`, and tail-jumps directly to `0x00544ce0`, the accepted Pane `RemoveFromLayer` body. It does not dispatch hide slot `+0x18` on either object.
- Current class state: the complete declaration contains public `AddToLayer` and `RemoveFromLayer`, preserves all prior fields/methods, closes before `[[CHILDREN]]`, and contains no stale lifecycle declaration.
- Current target/sibling state: Destination 1 and Destination 2 are byte-equal to the report blocks; both pages contain full binary, source-shape, ownership, compiler-exclusion, negative, historical, and score evidence.
- Current generated command `000000014675` proves the corrected pair and class union exactly once with no target empty marker or handwritten ABI leakage.
- B002 implementation, scoped validation, waited generation, report reconciliation, and lease release are complete. Lifecycle path, execution, movement, and archive state remain externally supervisor/validator-owned.
- Manual coverage is externally complete and validated at the command/hash epoch recorded below: four by-memory placements and one each in by-class, by-file, and by-type/by-vtable. This report reconciliation did not edit any coverage file.

## Executive Recommendation

- Retain the applied no-split/no-new-UID route. UID0004AS owns exactly the source method range and now emits `RemoveFromLayer()` through owner/emitter UID00006M.
- Retain UID0004AR as the paired `AddToLayer(...)` member at its validator-authorized canonical path, with the full modeled envelope preserved as provenance.
- Retain the public inherited lifecycle overrides in UID00006M, the complete 0x118 layout, all event/paint/editor methods, and the class closing brace before `[[CHILDREN]]`.
- Retain UID0001IK as non-emitting and both vtable pages as compiler-owned markers with source-facing names/evidence but no handwritten ABI data.
- Retain by-file MacroDialogs as prose-only with no reconstruction metadata.

## Supervisor Active Recheck

- Direct-target duplicate preflight found no dedicated current report for UID0004AS outside this artifact.
- Shared lease ledger and B002 lease ledger were read before edits and again after callback completion. Each ordinary edit used one short B002 lease; all were released immediately after scoped validation, and the final ledger has zero active leases.
- Retained B001/B003/B005 goals explicitly exclude UID0004AS; no active collision was found. Prior MacroDialogs reports are executed support history.
- All seven ordinary destinations were reread after lease acquisition and rebased before the bounded delta was applied. No same-or-greater concurrent MacroDialogs detail was lost.
- The completed delta is limited to the exact lifecycle pair, complete declaration integration, aggregate/vtable synchronization, and source-file prose. Verify-only support was not edited.

## Inference Research Guidance Check

- The initial name was not accepted from documentation. It was tested against exact vtable indices, Pane support, child-class vtables, the direct base target, and adjacent sibling behavior.
- The IDA incidental `char` return was not copied into source. Register liveness and direct tail-call shape were separated from the virtual source declaration.
- Decompiler indexing (`this[68]`) was resolved to the accepted typed field `TextEditPane *m_textEdit` at `+0x110` from the complete class layout, constructor store, destructor ownership, and child call signatures.
- Compiler effects were explicitly separated: the UID0004AS tail jump is optimized lowering of a final base call; UID0004AR's security cookie is generated for its local bounds object. Neither belongs in handwritten source.
- Naming alternatives were ranked rather than guessed. Exact slot equality across Pane and ScrollablePane outweighs weaker lexical `OnHide`/`OnAttachToParent` descriptions.
- No unresolved source-quality blocker remains that would justify blank C++, a no-code disposition, a future report, or a lower score.

## Heuristic / Inference Reanalysis And Validation

1. **Method identity.** Integrate primary slot `+0x38` points to UID0004AS. Pane primary slot `+0x38` points to `0x00544ce0`, and TextEditPane/ScrollablePane slot `+0x38` points to their `RemoveFromLayer` implementation. This is direct family identity, not analogy alone.
2. **Hide rejection.** Integrate primary slot `+0x18` points to inherited `Pane::Hide` at `0x00544750`. A second override called `OnHide` at slot `+0x38` would duplicate the wrong virtual contract and contradict the exact base table.
3. **Child dispatch.** The only conditional call loads the vptr from `m_textEdit` and invokes offset `+0x38`; this is the child's `RemoveFromLayer`, not its hide operation.
4. **Base dispatch.** The final direct jump is exactly `0x00544ce0`, the Pane layer-removal body that performs focus/event cleanup, removes the pane from its Layer, and clears the attachment pointer.
5. **Return type.** No caller consumes a return. The source family declares layer removal as `void`; IDA's AL result is incidental state left by the base helper. Source must not invent a boolean or character return.
6. **Access.** Pane lifecycle methods and strong derived comparators expose `AddToLayer`/`RemoveFromLayer` publicly. No friend-only or protected-only call constraint appears. Public override declarations are the highest-probability original shape.
7. **Sibling identity.** Adjacent Integrate slot `+0x30` points to UID0004AR. Pane slot `+0x30` is `AddToLayer`; UID0004AR first calls `0x00544c70` with four arguments and then attaches the child through its slot `+0x30`. The pair is exact.
8. **Sibling source shape.** UID0004AR obtains the child's bounds into a local `RectBounds`, adds the child at order zero after the containing row, uses `this` as previous pane, and passes the same Layer. Its cookie is compiler-generated around the local.
9. **Field identity.** Constructor `0x0057fd10` allocates/constructs a TextEditPane and stores it at `+0x110`; destructor UID0004AH deletes that pointer. The null guard preserves valid construction/destruction states and must remain.
10. **Source owner.** Both methods are out-of-line members of the complete IntegrateMacroEditControlPane declaration and physically belong to MacroDialogs.cpp. The split index is inventory only.
11. **No split.** Every byte in UID0004AS belongs to the one source method or its compiler tail-call lowering; there is no exact subrange needing a new child.
12. **Score closure.** Exact bytes, CFG, ABI, vtable identity, base/child names, typed field, ownership, call order, access, source placement, and complete C++ are resolved. Only stripped lexical spelling remains inferential, supporting `92/94` rather than symbol-final confidence.

## Evidence Standards Used

- Exact machine bytes and raw PE mapping establish range and integrity.
- IDA function, basic-block, instruction, xref, vtable, decompiler, and callee evidence establish behavior and ABI.
- Current by-memory/by-class/by-file/by-type documents establish accepted names, layouts, ownership, and generation contracts only where they agree with the binary.
- Strong same-slot source-family comparators outrank weak lexical similarity.
- Direct current generated output is used as a defect/readback snapshot, not as proof that stale source names are correct.
- Historical reports are classified as leads and provenance. Every decisive conclusion was independently revalidated.
- Reconstructable source includes authored calls and control flow, while vptr operations, security cookies, tail-jump lowering, RTTI, raw vtables, and deleting wrappers remain compiler-owned.

## Evidence Checked

- Exact old-report search terms: `UID0004AS`, `UID:0004AS`, `0x005805c0`, `0x005805da`, `IntegrateMacroEditControlPaneOnHide`, `IntegrateMacroEditControlPane::OnHide`, `RemoveFromLayer`, `0x00544ce0`, `0x0055ef10`, `UID0004AR`, `0x00580550`, `OnAttachToParent`, `AddToLayer`, `m_textEdit`, and `0x0062d364`.
- Central executed root `executed-b-agent-research/` was searched. Relevant opened reports:
  - `executed-b-agent-research/B001/0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`, SHA256 `C244E59CFAAF12EB893C0203F5CF26D45AE1B24152734713154CBA872A13CCE2`: useful split/boundary provenance, but its CPP-27/CPP-28 attach/hide names are superseded by live slot evidence.
  - `executed-b-agent-research/B003/0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md`, SHA256 `B4AC2DAE09993331B3C5171ED4CC15577E7EFF747D66E17CE5B117C413252908`: useful exact vtable/range evidence, but its attach/hide labels are superseded.
  - `executed-b-agent-research/B002/0004AC-NewMacroEditControlPaneRefresh-source-quality.md`, verified phase artifact SHA256 `E9550745F3247C4FF10EF85AD0FA41182AFA4BD2C8A6EFC96F0210AEAC9E80B4`: current class/file/generated union evidence; not a direct UID0004AS analysis.
  - Executed UID00011H TextEditControlPane lifecycle report SHA256 `F9A14F53...C57DB` and UID0001GL ScrollablePane support report SHA256 `DCA147...94B6F`: strong family comparators; no ownership transfer.
  - Executed B010 UID0004AP, B006 UID0004AI, and B004 UID0004AQ reports: adjacent Integrate helpers only; no direct target report.
- Active retained roots `tools/leaser/Agents/Agent-B001/research`, `Agent-B003/research`, `Agent-B004/research`, and `Agent-B005/research` were searched. No direct UID0004AS report exists; current retained goals do not assign this UID elsewhere.
- Legacy root `tools/leaser/Agents/Older-Research/` was searched: no direct UID0004AS report.
- Root `archived/` was searched: no direct UID0004AS report.
- Current ordinary target, sibling, class, split, exact vtable, type-vtable, source-file, Pane, ControlPane, TextEditPane, ScrollablePane, constructor/destructor, and comparator pages were opened and compared.
- Current manual `by-memory`, `by-class`, `by-file`, and `by-type/by-vtable` coverage reports were opened read-only and compared row by row. The exact current supervisor-owned handoff appears below.
- MacroDialogs.cpp was read at the historical pre-callback command 14655 and again after waited callback command 14675. The first read established stale declarations/definitions; the final read proves the corrected class/pair and absence of target blockers.
- Lease ledgers were opened twice during the evidence pass; no active B002 or shared lease existed. No lease was acquired.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004AS retains UID/range and is renamed from historical OnHide to RemoveFromLayer. | Very high | Integrate/Pane vtable slot +0x38 | D1 current target path/title/formal, SHA `4EA3EB3F...0727C` | incorporate | applied |
| C02 | Target moves `86/90 -> 92/94`; owner/emitter/true/blank-position/Nested 0 remain. | High | resolved blockers and current metadata | D1 metadata, validator 14668/14675 | incorporate | applied |
| C03 | Exact 26 bytes and byte SHA256 are fixed. | Very high | MCP bytes and local PE | D1 evidence/range | incorporate | applied |
| C04 | Target is ten instructions, four blocks, complexity two, with one null branch. | Very high | IDA disassembly/CFG | D1 behavior/CFG | incorporate | applied |
| C05 | Source ABI is public virtual `void __thiscall RemoveFromLayer()` with no stack arguments. | High | slot family, stack, return liveness | D1/D3 declaration; generated 14675 | incorporate | applied |
| C06 | Target boundaries are exact with 13 preceding and 6 following `0xcc` bytes. | Very high | bounded bytes/function lookup | D1 boundary/padding | incorporate | applied |
| C07 | Only target reachability is Integrate primary vtable cell `0x0062d364`; no direct caller exists. | Very high | xrefs and raw PE pointer scan | D1 xref evidence | incorporate | applied |
| C08 | `this+0x110` is owned `TextEditPane *m_textEdit`. | Very high | layout, constructor store, destructor delete | D1/D3/D4/D7 current pages | incorporate | applied |
| C09 | Child primary slot `+0x38` is `TextEditPane::RemoveFromLayer`. | Very high | TextEditPane/ScrollablePane vtables | D1 behavior; D9 final verify-only read | incorporate | applied |
| C10 | Direct tail target `0x00544ce0` is `Pane::RemoveFromLayer`. | Very high | Pane vtable/body/support | D1 behavior; D8 final verify-only read | incorporate | applied |
| C11 | The child null test is authored and must remain. | Very high | exact branch and ownership states | D1 byte-equal formal/generated body | incorporate | applied |
| C12 | Call order is conditional child removal then unconditional Pane base removal. | Very high | exact instruction order | D1 byte-equal formal/generated body | incorporate | applied |
| C13 | Tail jump and incidental AL return are compiler effects, not source-visible operations. | High | final pop/jump and void family contract | D1 compiler disposition | historicalize | applied |
| C14 | Historical OnHide/ControlPane::OnHide wording is invalid, not an alternate accepted name. | Very high | hide is exact slot +0x18 | D1/D3/D4/D7 labeled history | reject-invalid | applied |
| C15 | MacroDialogs.cpp and UID00006M remain source owner/emitter route. | Very high | current generation ownership | D1/D3/D7; generated source route | already-present | already-present |
| C16 | UID0004AR retains UID, uses canonical path `0x00580570-0x005805b9`, preserves modeled envelope provenance, and is renamed to AddToLayer. | Very high | exact adjacent slot +0x30 and callback path contract | D2 current sibling path/title/formal, SHA `156A2AE3...341F1` | incorporate | applied |
| C17 | UID0004AR moves `87/90 -> 92/94` and receives the exact four-argument lifecycle body. | High | complete disassembly/call signature | D2 metadata/formal, validator 14669 | incorporate | applied |
| C18 | UID0004AR local RectBounds and security-cookie distinction are resolved. | Very high | stack/disassembly/comparators | D2 evidence/history | incorporate | applied |
| C19 | UID00006M complete class retains all fields/methods and replaces only the stale lifecycle pair. | Very high | current class union and exact pair | D3 class formal/prose, validator 14670 | incorporate | applied |
| C20 | AddToLayer/RemoveFromLayer declarations are public inherited lifecycle overrides. | High | Pane and comparator declarations | D3 access/source shape; generated class | incorporate | applied |
| C21 | UID0001IK remains `91/93`, owner UID0000KY, non-emitting, blank formal, Nested -4. | Very high | current aggregate contract | D4 split index, validator 14671 | incorporate | applied |
| C22 | UID0003DB remains compiler-vtable source marker and records exact +0x30/+0x38 names. | Very high | current marker/live cells | D5 vtable page, validator 14672 | incorporate | applied |
| C23 | UID0001Y1 remains compiler-vtable source marker and records the same pair. | Very high | current marker/live cells | D6 type vtable page, validator 14673 | incorporate | applied |
| C24 | by-file MacroDialogs receives prose only and no reconstruction metadata. | Very high | by-file guidance/current owner | D7 prose, validator 14674 | incorporate | applied |
| C25 | Pane/ControlPane support already resolves base contract and needs no edit absent drift. | Very high | final current support docs/live slot | D8 verify-only hashes | already-present | already-present |
| C26 | TextEditPane/ScrollablePane support already resolves child contract and needs no edit absent drift. | Very high | final current support/docs/live helper | D9 verify-only hashes | already-present | already-present |
| C27 | Vptr, RTTI, cookies, tail lowering, deleting wrappers, and raw tables remain excluded from source. | Very high | compiler artifact analysis | D1-D7 history/exclusions; generated 14675 | reject-invalid | applied |
| C28 | Generated output contains the corrected lifecycle pair once each with no target empty marker or raw-ABI source. | High | generated final readback | D10 waited command 14675 | incorporate | applied |
| C29 | Seven exact manual coverage placements are supervisor-owned; B002 did not edit them. | Very high | direct final manual row comparison | exact coverage section; externally applied commands 14676-14679 with 7/7 one-row readback | incorporate | applied |
| C30 | No duplicate report/new child/split/lifecycle action was needed; historical reports remain evidence only. | Very high | preflight/range/ownership/final state | report/checklist | reject-stale | applied |

- Terminal ledger count: `27 applied`, `3 already-present`, `0 excluded-with-reason`, and `0 blocked`. Action cells remain within the accepted report vocabulary.

## Positive Evidence Summary

- Exact target bytes encode one typed child load, one null test, one child virtual call at `+0x38`, and one direct base tail call.
- Exact target vtable cell is `0x0062d364`, inside IntegrateMacroEditControlPane's primary table.
- Pane `+0x38` and ScrollablePane/TextEditPane `+0x38` independently resolve the same `RemoveFromLayer` virtual contract.
- Pane hide is demonstrably `+0x18`, eliminating the historical `OnHide` interpretation.
- Constructor and destructor independently identify and own the `TextEditPane *` at `+0x110`.
- The direct base helper performs layer detachment and clears the layer pointer, behavior consistent with removal rather than visibility.
- Adjacent UID0004AR occupies the paired `+0x30` slot and exactly matches `AddToLayer`, including Pane-first attach and child attach using child bounds.
- Strong current ScrollableControlPane and TextEditControlPane declarations use the same public method names and signatures.
- Existing source owner/emitter and class size/layout are already coherent; the correction requires no ownership migration or layout invention.

## IDA MCP Facts

- Evidence-collection-time streamable MCP client session: `2711d5e5-7b4d-4fdf-9817-d4e0cc7996ed`.
- Fresh `idb_list` returned one active NexusTK database `9b0396a3`, worker PID 15732, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Evidence-time `server_health(database=9b0396a3)` returned `ok`; auto-analysis, Hex-Rays, and string cache were ready. This is a time-scoped observation, not a claim of future session availability.
- Input PE: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Target bytes: `56 8b f1 8b 8e 10 01 00 00 85 c9 74 05 8b 01 ff 50 38 8b ce 5e e9 06 47 fc ff`.
- Target byte SHA256: `1834E5E8A1542F624F9C8494113F9EAA8A18CEC625653511490977C19A508F8B`.
- RVA `0x001805c0`; `.text` raw offset `0x0017f9c0`. `.text` RVA `0x1000`, raw `0x400`, raw size `0x20b600`, virtual size `0x20b4ac`.
- Exact signature `56 8B F1 8B 8E ? ? ? ? 85 C9 74 ? 8B 01 FF 50 ? 8B CE 5E E9` is unique in the local PE.
- Modeled target: `sub_5805C0`, size `0x1a`, ten instructions, four blocks, cyclomatic complexity two.
- Exact instruction flow: preserve ESI; copy ECX receiver; load `[ESI+0x110]`; test child; skip if null; load child vptr; call `[vptr+0x38]`; restore containing receiver; restore ESI; tail-jump to `0x00544ce0`.
- No stack arguments, local variables, strings, globals, constants beyond offsets, field writes, allocations, frees, EH, or security cookie exist in UID0004AS.
- Target xrefs: one data xref from `0x0062d364`; no code caller. Local PE pointer scan found absolute target VA once at raw `0x22bd64`, mapping exactly to that vtable cell; no RVA pointer and no direct E8/E9 call were found.
- Predecessor `sub_580550` ends at `0x005805b3`; `[0x005805b3,0x005805c0)` is thirteen `0xcc` bytes. `[0x005805da,0x005805e0)` is six `0xcc` bytes before successor `sub_5805E0`.
- Integrate primary cells: `+0x14 -> 0x00544730` Pane Show; `+0x18 -> 0x00544750` Pane Hide; `+0x30 -> 0x00580550` UID0004AR; `+0x38 -> 0x005805c0` UID0004AS.
- Pane primary cells: `+0x30 -> 0x00544c70` AddToLayer; `+0x38 -> 0x00544ce0` RemoveFromLayer.
- TextEditPane primary cells: `+0x30 -> 0x0055ee10` ScrollablePane AddToLayer; `+0x38 -> 0x0055ef10` ScrollablePane RemoveFromLayer.
- Child remove helper `0x0055ef10` conditionally removes horizontal and vertical scrollbars through slot `+0x38` and tail-jumps to Pane RemoveFromLayer; it has 42 vtable data refs, including the TextEditPane cell.
- Base helper `0x00544ce0` performs focus/event cleanup, conditionally calls Layer removal through the accepted route, and clears the attachment field.
- Adjacent UID0004AR `sub_580550` is 0x63 bytes, 43 instructions, three blocks, complexity two. It calls Pane AddToLayer with four arguments, conditionally obtains child bounds through slot `+0x28`, and calls child AddToLayer through slot `+0x30` with order zero, previous pane `this`, and the same Layer.
- Constructor `0x0057fd10` stores a constructed TextEditPane at `+0x110`; destructor UID0004AH owns/deletes it. These routes close field type and ownership.

## Function / Child Inventory

| UID / range | Current description | Resolved source disposition | Score / position |
| --- | --- | --- | --- |
| UID0001IK `[0x0057f750,0x005807c5)` | MacroEditControlPanes aggregate | non-emitting split/source index; keep blank formal | `91/93`, blank |
| UID0004AQ `[0x00580520,0x0058054c)` | preceding Integrate method | separate source method; unchanged | current verify-only |
| UID0004AR canonical page `[0x00580570,0x005805b9)`, modeled envelope `[0x00580550,0x005805b3)` | historical stale OnAttachToParent | applied source-authored public `AddToLayer` override; UID-preserving rename/path correction | `92/94`, blank |
| padding `[0x005805b3,0x005805c0)` | alignment | 13 compiler/linker `0xcc` bytes | no source |
| UID0004AS `[0x005805c0,0x005805da)` | stale OnHide | source-authored public `RemoveFromLayer` override; UID-preserving rename | `92/94`, blank |
| padding `[0x005805da,0x005805e0)` | alignment | 6 compiler/linker `0xcc` bytes | no source |
| successor `[0x005805e0,...)` | separate Integrate method | separate modeled function; unchanged | current verify-only |
| UID0003DB `.rdata` island | exact macro edit-control vtables | compiler-generated marker; add corrected slot names only | `90/94`, blank |
| UID0001Y1 type vtables | source-facing vtable inventory | compiler-generated marker; add corrected slot names only | `92/94`, blank |

## Direct Xref / Caller Inventory

- UID0004AS has no direct code caller. Its sole exact inbound reference is IntegrateMacroEditControlPane primary vtable cell `0x0062d364`.
- The lack of direct calls is expected for a virtual lifecycle override and is positive, not negative, liveness evidence.
- UID0004AS calls one child virtual target indirectly when `m_textEdit` is non-null, then directly reaches Pane::RemoveFromLayer by tail jump.
- No endpoint xref at `0x005805da` exists, and no reference reaches the padding.
- UID0004AR likewise occupies Integrate primary cell `0x0062d35c`; the layer manager can dispatch it through the virtual base contract.
- Constructor/destructor references to `m_textEdit` are not calls to UID0004AS but establish receiver type and lifetime.
- Generated source must therefore contain the two virtual definitions even though there are no direct source callsites in MacroDialogs.cpp.

## Documentation Evidence And IDA Status

- Evidence-time target documentation called the method `OnHide`; live MCP evidence contradicted that label through exact slot identity. The old spelling remains only as superseded history, while current UID0004AS is `RemoveFromLayer` with complete D1 source and evidence.
- Evidence-time UID0004AR documentation called the paired method `OnAttachToParent`; current UID0004AR is `AddToLayer` with complete D2 source/evidence at canonical validator path `0x00580570-0x005805b9`, while the 99-byte modeled envelope remains historical binary provenance.
- Current UID00006M retains the complete 0x118 ControlPane-derived layout, correct `MacroHotkeyRecord *`, two booleans, natural padding, `TextEditPane *m_textEdit` at `+0x110`, saved state at `+0x114`, and the complete source method union. Its public lifecycle declarations and class/formal placement are applied.
- Current UID0001IK remains non-emitting and now records corrected child paths, names, source behavior, padding, and compiler exclusions.
- Current UID0003DB and UID0001Y1 retain their exact compiler markers and now record the source-facing `+0x30/+0x38` pair without handwritten ABI data.
- Current Pane, ControlPane, TextEditPane, ScrollablePane, and lifecycle comparator docs remain same-or-greater verify-only support; final reread found no target-specific contradiction requiring an edit.
- Historical generated command `000000014655` reproduced the stale pair. Current waited command `000000014675` contains the corrected declarations/definitions exactly once and removes all target-specific stale/empty/ABI blockers.

## Ranked Ownership Analysis

1. **UID00006M IntegrateMacroEditControlPane, accepted.** Both exact ranges are complete-object virtual members in its primary table and operate on its owned `m_textEdit` field.
2. **UID0000KY MacroDialogs, accepted file owner/emitter route.** The class and all exact method children already emit into MacroDialogs.cpp through this source family.
3. **UID0001IK aggregate, semantic inventory only.** It owns no emitted C++; using it as emitter would duplicate child bodies.
4. **Pane/ControlPane, rejected as canonical target owner.** They define the inherited base contract but do not own derived behavior or the `+0x110` child field.
5. **TextEditPane/ScrollablePane, rejected as target owner.** They define child virtual semantics but the Integrate wrapper is independently source-authored.
6. **Compiler/vtable owner, rejected for methods.** Exact class-specific bodies and child/base orchestration are authored source. Only table bytes and tail/cookie lowering are compiler-generated.

## Source Placement

- Physical source file: MacroDialogs.cpp, represented by UID0000KY.
- Header/declaration route: complete UID00006M class declaration, with `Layer` and `RectBounds` forward declarations and public lifecycle overrides.
- Exact method emission: UID0004AR and UID0004AS through UID00006M, retaining blank child positions because address-ordered child registration places AddToLayer before RemoveFromLayer correctly.
- Aggregate route: UID0001IK records exact split, names, ranges, source/compiler distinctions, and padding, but remains non-emitting.
- ABI route: UID0003DB and UID0001Y1 preserve compiler-only vtable markers; no raw table declaration or array is added.
- by-file route: prose only. `by-file/MacroDialogs.md` must not receive a formal reconstruction block.
- No new source file, helper declaration, class, method child, or duplicate report is required.

## Range / Split / Padding / Reclassification Analysis

- UID0004AS range is exact and must not expand to include six trailing `0xcc` bytes or merge with successor `0x005805e0`.
- The initial 26-byte range is one source method. The final direct jump belongs to compiler lowering of its last base call, not a separable thunk child.
- UID0004AR's evidence-time IDA modeled envelope `[0x00580550,0x005805b3)` remains the exact 99-byte binary-analysis scope and does not absorb the thirteen-byte alignment before UID0004AS. Its current validator-authorized document path is `0x00580570-0x005805b9`; that path normalization is not a second function or a rewrite of the binary provenance. Its security-cookie prologue/epilogue is generated around an authored local `RectBounds`; it does not justify a compiler-only classification.
- Both pages received semantic UID-preserving rename/path corrections; no new UID was registered.
- The parent UID0001IK remains the range/split index at `Nested:-4`; both exact methods remain `Nested:0`.
- No padding page, thunk page, wrapper page, or raw-helper page should be added for this correction.

## Negative Evidence Summary

- No target instruction references hide slot `+0x18`.
- No target instruction calls `ControlPane::OnHide`, `Pane::Hide`, or any visibility flag update.
- No target instruction manipulates a parent pointer, rectangle, order, flags, or z-order.
- No target direct caller or string provides an alternate semantic name.
- No source-visible value is consumed; returning IDA's incidental AL would be decompiler-shaped.
- No null failure branch exists beyond skipping child removal; base removal always occurs.
- No field is cleared, freed, or written by UID0004AS.
- No EH, cookie, allocation, free, vptr store, deleting flag, or scalar wrapper exists in UID0004AS.
- No direct report independently reanalyzes this exact range; old aggregate/vtable labels are not duplicate accepted source-quality decisions.
- Generic `Detach`, `OnDetach`, `OnHide`, `RemoveChild`, and `OnAttachToParent` alternatives are weaker than exact current project contract names and are rejected.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_5805C0` to `IntegrateMacroEditControlPane__RemoveFromLayer` with source type `void __thiscall(IntegrateMacroEditControlPane *this)`.
- Rename `sub_580550` to `IntegrateMacroEditControlPane__AddToLayer` with the accepted four-argument source type represented in Destination 2.
- Apply the accepted `IntegrateMacroEditControlPane` type so `[this+0x110]` renders as `TextEditPane *m_textEdit`.
- Name primary vtable cells `+0x30 AddToLayer` and `+0x38 RemoveFromLayer` for Integrate, Pane, and the relevant child family.
- Comment UID0004AS as conditional child layer removal followed by unconditional Pane layer removal; note tail-call lowering and void source return.
- Comment UID0004AR as Pane-first layer attach followed by conditional child attach using child bounds, order zero, previous pane `this`, and the same Layer; note compiler cookie exclusion.
- These are report recommendations only. This pass performed no IDA mutation.

## First-Draft C++ Recommendation

- Eligible for source C++: yes. UID0004AS and UID0004AR are source-authored virtual members with complete behavior-identical source drafts.
- Destinations 3-6 are exact complete declaration/aggregate/compiler-marker blocks required to keep generated source and ABI dispositions coherent.
- All multiline C++ in this report appears only inside the literal destination-specific managed blocks below.

### Destination 1 - UID0004AS target, UID-preserving rename and exact replacement

```text
*** UID:0004AS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IntegrateMacroEditControlPane::RemoveFromLayer()
{
    if (m_textEdit != nullptr)
        m_textEdit->RemoveFromLayer();

    Pane::RemoveFromLayer();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact 26-byte IntegrateMacroEditControlPane layer-removal override at primary slot +0x38; conditionally removes the owned TextEditPane at +0x110 before unconditionally removing the containing row through Pane, with an authored null guard and compiler-only tail-call lowering. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2 - UID0004AR bounded sibling, UID-preserving rename and exact replacement

```text
*** UID:0004AR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IntegrateMacroEditControlPane::AddToLayer(const RectBounds *bounds,
                                                int order,
                                                Pane *previousPane,
                                                Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    if (m_textEdit != nullptr)
    {
        RectBounds editBounds;
        m_textEdit->GetBounds(&editBounds);
        m_textEdit->AddToLayer(&editBounds, 0, this, layer);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact 99-byte IntegrateMacroEditControlPane layer-addition override at primary slot +0x30; attaches the containing row through Pane first, then conditionally obtains the owned TextEditPane bounds and attaches that child at order zero after this row in the same Layer, excluding compiler security-cookie mechanics. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 3 - UID00006M complete no-loss class declaration

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class Pane;
class TextEditPane;
struct MacroHotkeyRecord;
struct Rect;
struct RectBounds;

class IntegrateMacroEditControlPane : public ControlPane
{
public:
    IntegrateMacroEditControlPane(MacroHotkeyRecord *record, const Rect &bounds);
    virtual ~IntegrateMacroEditControlPane();

    bool IsTextEditActive() const;
    void SetMacroData(MacroHotkeyRecord *record);
    void RefreshDisplay();
    void SyncEditControl();

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);

private:
    void EnterTextEditMode();
    void LeaveTextEditMode();

    MacroHotkeyRecord *m_macroData;
    bool m_pendingTextEditForward;
    bool m_editActive;
    TextEditPane *m_textEdit;
    unsigned char m_savedTextEditState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0001IK non-emitting split index, keep formal blank

```text
*** UID:0001IK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting MacroDialogs split inventory for the Spell/New/Integrate MacroEditControlPane island; exact children own source behavior, including UID0004AR AddToLayer and UID0004AS RemoveFromLayer, while destructor glue, vtable thunks, scalar deleting wrappers, security-cookie/tail-call lowering, and padding remain compiler/no-code or parent-only coverage. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:-4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5 - UID0003DB compiler-owned vtable marker, preserve marker and synchronize prose

```text
*** UID:0003DB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0003DB] Compiler-generated MSVC vtable/RTTI data for SpellMacroEditControlPane,
// NewMacroEditControlPane, and IntegrateMacroEditControlPane is covered by the
// MacroDialogs.cpp class declarations and virtual method definitions; do not
// hand-emit raw .rdata vtable bytes.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: MacroDialogs-owned MSVC vtable/RTTI island for Spell/New/Integrate MacroEditControlPane; nine views and locator pointers encode exact class, EventHandler, thunk, destructor, boundary, and Integrate AddToLayer +0x30/RemoveFromLayer +0x38 evidence but are compiler-generated from source declarations. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 6 - UID0001Y1 compiler-owned type-vtable marker, preserve marker and synchronize prose

```text
*** UID:0001Y1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated MSVC RTTI and vtable data for the MacroDialogs class family;
// do not emit handwritten vtable or RTTI arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- Retain applied UID0004AS as source-ready `IntegrateMacroEditControlPane::RemoveFromLayer()` at `92/94` with Destination 1 and its UID-preserving path correction.
- Retain applied UID0004AR as source-ready `IntegrateMacroEditControlPane::AddToLayer(...)` at `92/94` with Destination 2, canonical validator path `0x00580570-0x005805b9`, and labeled 99-byte modeled-envelope provenance.
- Retain Destination 3 as the complete no-loss class declaration with no stale OnHide/OnAttach declaration beside the corrected child bodies.
- Retain UID0001IK non-emitting, UID0003DB/UID0001Y1 compiler-owned, and MacroDialogs by-file prose-only.
- Pane and TextEditPane lifecycle support passed final read-only same-or-greater verification without a B002 edit.
- All ordinary edits were leased, validated, and released serially; waited MacroDialogs generation passed. B002 did not edit generated or manual coverage files by hand.

## Recommended Target Doc Changes

1. Applied validator-supported UID-preserving rename to `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md`.
2. Applied Destination 1 metadata, formal body, Item Summary, and unchanged `Nested:0` exactly.
3. Applied complete report-level evidence: bytes/hash/PE mapping; ten instructions/four-block CFG; thiscall/void ABI; vtable-only liveness; `m_textEdit` type/ownership; exact null branch; child/base slot identity; call order; range/padding; source placement; tail-call compiler exclusion; no caller/string/global/write/EH facts; rejected names; score rationale; and historical stale wording.
4. Preserved unrelated target evidence and validator-added links at same-or-greater detail.

## Recommended Support Doc Changes

1. UID0004AR: applied UID-preserving rename/path correction to `by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md`, retained the `[0x00580550,0x005805b3)` modeled envelope as explicit provenance, installed Destination 2, and added exact body/ABI/local/cookie/vtable/source/history detail.
2. UID00006M class: retained `92/94`, position 30, complete 0x118 layout and all methods; applied Destination 3 and exact lifecycle pair evidence.
3. UID0001IK aggregate: retained `91/93`, owner UID0000KY, reconstructable false, blank emitter/position/formal, `Nested:-4`; applied Destination 4 and synchronized exact canonical/model ranges, names, padding, and compiler distinctions.
4. UID0003DB: retained `90/94` and exact compiler marker; applied Destination 5 and exact Integrate primary `+0x30/+0x38` names, pointers, and compiler ownership.
5. UID0001Y1: retained `92/94` and exact compiler marker; applied Destination 6 and synchronized the source declaration/slot evidence without raw ABI source.
6. `by-file/MacroDialogs.md`: remained prose-only; added the complete lifecycle pair, source ordering, owner/emitter, child ownership, null/order, compiler-exclusion, historical alias, path-provenance, and generated-contract facts without reconstruction metadata.
7. PaneVtables/PaneLayout/ControlPane and TextEditPane/ScrollablePane pages: final read-only verification found same-or-greater support and no concrete target-specific contradiction.
8. UID0004AH constructor/destructor and adjacent Integrate methods: final read-only verification retained same-or-greater ownership/layout evidence unchanged.

## Score And Metadata Recommendation

| Page | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| UID0004AS | `92/94` applied; historical `86/90` | retain `92/94` | exact range/bytes/CFG/vtable/base/child/type/ownership/order/ABI/source/body resolved; only stripped lexical source spelling remains inferential |
| UID0004AR | `92/94` applied; historical `87/90` | retain `92/94` | exact paired slot/signature/body/local/order/source placement resolved; cookie excluded |
| UID00006M | `92/94` | retain `92/94` | current complete layout/source union is strong; lifecycle names are bounded corrections, not a class score expansion |
| UID0001IK | `91/93` | retain `91/93` | non-emitting split inventory remains correct |
| UID0003DB | `90/94` | retain `90/94` | compiler disposition remains exact; applied prose records slot names |
| UID0001Y1 | `92/94` | retain `92/94` | type-level compiler marker remains exact |
| UID0000KY | `92/92` | retain `92/92` | file owner/source route already strong; prose-only synchronization |

- Target completion does not reach 100 because original symbols and source formatting are stripped.
- Confidence reaches 94 because method identity is fixed by three independent exact vtable families plus direct base target behavior.
- Blank child positions remain intentional; current address order already places UID0004AR before UID0004AS within UID00006M.
- Owner/emitter do not change. No new class, child UID, or source file is warranted.

## Open Questions With Attempted Resolution

- **Could the original name have been `DetachFromLayer`?** Exhausted: current Pane, ScrollablePane, TextEditControlPane, and ScrollableControlPane source contracts consistently use `RemoveFromLayer`, and exact target slots align. Rejected.
- **Could UID0004AS be `OnHide` despite slot mismatch?** No. Hide is inherited at exact primary `+0x18`; UID0004AS occupies `+0x38` and calls `+0x38`. Rejected as binary-incompatible.
- **Should the final base call be `ControlPane::RemoveFromLayer`?** Current direct derived comparators and exact target address resolve the implementation to Pane. `ControlPane` does not supply a distinct override. `Pane::RemoveFromLayer()` is the strongest source shape.
- **Should UID0004AR use `Rect` rather than `RectBounds`?** Exact current Pane lifecycle contract and strong comparators use `RectBounds *`; child `GetBounds` writes through an out pointer. `RectBounds` is accepted.
- **Is the child pointer borrowed?** Constructor creates/stores it and destructor deletes it; owned raw pointer is established.
- **Is the target compiler-only because it ends in a jump?** No. Authored null-controlled child orchestration precedes the optimized final base call. Tail lowering alone is compiler-owned, not the method.
- **Does no direct caller mean dead code?** No. Exact primary-vtable reachability is live virtual dispatch evidence.
- **Is a new report or child needed for UID0004AR?** No. It already has a stable UID/range/page and is a bounded same-family dependency; a UID-preserving correction avoids duplicate research inventory.
- No blocker remains open with score or C++ impact.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-application callback-final snapshots (B002 did not edit them):
  - `by-memory/-coverage-report.md`: SHA256 `0C8C5E8EADA3A344E6BEAD174F70A647989421EB0E13B02E31BCFCD058BC181A`, 1,801,763 bytes / 4,299 lines.
  - `by-class/-coverage-report.md`: SHA256 `426E48F6E057A8B85B679F756A236D1A5E97EF253ADDA7AA4AEFB162ABE9E994`, 233,370 bytes / 623 lines.
  - `by-file/-coverage-report.md`: SHA256 `7F09DD456B9014A894A9F2D24304A35A64501C96C8D7A4EEA6A34996C7453B61`, 133,452 bytes / 316 lines.
  - `by-type/by-vtable/-coverage-report.md`: SHA256 `7AFEEB7F9E6E3691C8D7E91A79AA27353A5E832ABAA83835DDD51E73749771C4`, 65,384 bytes / 142 lines.
- Historical pre-application disposition: UID0004AR/UID0004AS were absent, and UID0001IK/UID0003DB/UID00006M/UID0000KY/UID0001Y1 retained pre-callback rows. The exact no-loss handoff below used UID0004AR's callback-authorized canonical path while preserving the accepted Gate 1 row's older `0x00580550-0x005805b3` path only as modeled-envelope history.
- Current externally validated snapshots after supervisor application:
  - `by-memory/-coverage-report.md`: command `000000014676`, exit `0`, `ok:1`, SHA256 `27F745BA31D8487AC6C4837C709EBABCD7B470020E48529D0DA15C06AC9B2D86`, 1,803,594 bytes / 4,301 lines.
  - `by-class/-coverage-report.md`: command `000000014677`, exit `0`, `ok:1`, SHA256 `D9AC33E6C698E781E3F249A0E41D27352341933B5A0738181A957A7AE5A6BC46`, 233,702 bytes / 623 lines.
  - `by-file/-coverage-report.md`: command `000000014678`, exit `0`, `ok:1`, SHA256 `CDF2823366D7DDD40AAFE81712641A40454F6AE7904A35804F92F74E038E7AFE`, 133,664 bytes / 316 lines.
  - `by-type/by-vtable/-coverage-report.md`: command `000000014679`, exit `0`, `ok:1`, SHA256 `249233F6B031CFC104ED0C9CD5678BFDE873E03FBBD9092AD788675032030749`, 65,481 bytes / 142 lines.
- Exact current one-row readback: UID0001IK occurs once at by-memory line 3201; UID0004AR once at line 3220; UID0004AS once at line 3221; UID0003DB once at line 3944; UID00006M once at by-class line 263; UID0000KY once at by-file line 151; and UID0001Y1 once at by-type/by-vtable line 82. Each row is byte-for-byte the accepted text reproduced below.

### by-memory placement 1 - externally applied UID0004AR row at current line 3220

```text
        - [UID:0004AR][0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer](by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md) 0x00580570-0x005805b9 | method | IntegrateMacroEditControlPaneAddToLayer : reconstructable : 92% : very-strong : Exact public IntegrateMacroEditControlPane AddToLayer override at primary slot +0x30; attaches the containing row through Pane first, then conditionally obtains owned TextEditPane bounds and attaches that child at order zero after this row in the same Layer, with exact four-argument ABI, validator-authorized canonical endpoints, preserved evidence-time modeled envelope 0x00580550-0x005805b3 / 99 bytes, null/order semantics, compiler-cookie exclusion, complete source C++, and rejected OnAttachToParent/Rect/flags aliases.
```

### by-memory placement 2 - externally applied UID0004AS row at current line 3221

```text
        - [UID:0004AS][0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer](by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md) 0x005805c0-0x005805da | method | IntegrateMacroEditControlPaneRemoveFromLayer : reconstructable : 92% : very-strong : Exact 26-byte public IntegrateMacroEditControlPane RemoveFromLayer override at primary slot +0x38 with byte SHA256 1834E5E8A1542F624F9C8494113F9EAA8A18CEC625653511490977C19A508F8B, vtable-only liveness, owned TextEditPane +0x110 null guard, child-first then unconditional Pane removal, void source ABI, exact padding, compiler tail-call exclusion, complete source C++, and rejected OnHide/ControlPane::OnHide aliases.
```

### by-memory placement 3 - externally applied UID0001IK row at current line 3201

```text
    - [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md) 0x0057f750-0x005807c5 | split index | MacroEditControlPanes : not_reconstructable : 91% : very strong : Non-emitting MacroDialogs split inventory for Spell/New/Integrate row controls with complete natural 0x110 New and 0x118 Integrate declarations, exact source-child inventories, UID0004AC Refresh and UID0004AK RefreshDisplay own-visible-bounds invalidation through inherited Pane slot +0x20, UID0004AR AddToLayer +0x30 and UID0004AS RemoveFromLayer +0x38 lifecycle pair with owned TextEditPane +0x110 child-before/base-order semantics, TextEditPane-owned editor type, implicit New versus explicit Integrate destructor causes, canonical EventHandler signatures, raw/no-xref helper and exact padding coverage, and compiler-only cookie/tail/teardown/thunk/scalar/vtable separation.
```

### by-memory placement 4 - externally applied UID0003DB row at current line 3944

```text
        - [UID:0003DB][0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData](by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md) 0x0062d1e0-0x0062d3cc | vtable-data | MacroEditControlPaneVtableData : reconstructable : 90% : very strong : Exact Spell/New/Integrate MacroEditControlPane MSVC RTTI/vtable island with nine views, COL/store/thunk evidence, canonical EventHandler secondary slots, exact Integrate primary UID0004AR AddToLayer +0x30 / UID0004AS RemoveFromLayer +0x38 cells, destructor and boundary evidence, Ctrl+%d successor boundary, UID0000KY source route, source-class/method regeneration, and comment-only compiler coverage with no raw arrays.
```

### by-class placement - externally applied UID00006M row at current line 263

```text
- [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md) : reconstructable : 92% : very strong : Complete natural 0x118 ControlPane-derived integrated macro row declaration at position 30 with all fourteen qualified methods, ordered MacroHotkeyRecord/pending/edit/TextEditPane/saved-mode fields, exact UID0004AK public RefreshDisplay member invalidating inherited GrafPort m_visibleBounds through Pane slot +0x20 after the sole IntegrateMacroDialog SetMacroData caller, exact public UID0004AR AddToLayer and UID0004AS RemoveFromLayer lifecycle overrides at primary +0x30/+0x38, owned TextEditPane +0x110 child attach/remove semantics and null/order behavior, complete constructor/destructor/paint/EventHandler/IME/sync/refresh/editor-mode union, primary/secondary/tertiary vtable routes, explicit owned-editor destructor source semantics, compiler cookie/tail/scalar/thunk separation, raw-helper liveness caveats, MacroDialogs ownership, and superseded RequestParentRefresh/m_bounds/OnAttachToParent/OnHide/ControlPane::OnHide aliases.
```

### by-file placement - externally applied UID0000KY row at current line 151

```text
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) : reconstructable : 92% : very strong : Macro dialog/edit-control source family with exact Macro/Spell/New/Integrate split inventories, complete six-position class declarations and source order, canonical command/hover/EventHandler contracts, corrected constructors and TextEditPane type/ownership, exact New shortcut/key/spell-mode storage lifecycle, UID0004AC Refresh and UID0004AK RefreshDisplay own-visible-bounds invalidation through inherited Pane slot +0x20, exact Integrate UID0004AR AddToLayer and UID0004AS RemoveFromLayer public lifecycle pair with child bounds/null/order semantics, registry/profile/runtime storage distinctions, explicit/implicit/source/compiler destructor separation, compiler vtable/cookie/tail coverage, historical stale-name corrections including rejected RequestParentRefresh/m_bounds/OnAttachToParent/OnHide/ControlPane::OnHide aliases, and retained physical-file grouping caveat.
```

### by-type/by-vtable placement - externally applied UID0001Y1 row at current line 82

```text
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) : reconstructable : 92% : very strong : MacroDialogs-owned MSVC vtable/RTTI family with exact dialog/edit-control table bases, COL/store/thunk evidence, canonical Macro/Spell/New/Integrate OnControlCommand +0x48 and inherited/overridden SetHoverControl +0x58 identities, complete Integrate/New edit-control lifecycle/paint/sync and pointer/key/IME declaration routes including Integrate UID0004AR AddToLayer at primary +0x30 and UID0004AS RemoveFromLayer at +0x38, explicit Integrate versus implicit New destructor source causes, source-destructor/scalar-wrapper separation, comment-only compiler coverage, and no handwritten vtable/RTTI arrays.
```

- Exact deletions: none. The supervisor added the previously absent UID0004AR/UID0004AS rows and replaced the five existing rows without loss; current readback is exactly seven rows, each once.
- Pane/ControlPane/TextEditPane/ScrollablePane manual rows were inspected and require no target-specific change because they already document the accepted base/child contract.
- B002 did not edit these files. Supervisor commands 14676-14679 applied and validated the complete handoff; any later coverage or lifecycle state remains supervisor/validator-owned.
- Do not edit `auto-generated/-ag-research-tracker.md`; validator/lifecycle mechanisms own tracker state.

## Follow-Up Actions

- B002's accepted ordinary implementation, destination rereads/rebases, scoped validators, waited generation, generated readback, report reconciliation, and lease release are complete.
- All six managed report blocks are byte-equal to their destination blocks. UID0004AR/UID0004AS use the current canonical paths, while historical names and the broader UID0004AR modeled envelope remain labeled provenance.
- Current generated assertions are satisfied: exactly one complete IntegrateMacroEditControlPane declaration; one UID0004AR AddToLayer definition before one UID0004AS RemoveFromLayer definition; zero stale Integrate `OnAttachToParent`/`OnHide` declarations or definitions; zero target/sibling Empty Emitter Marker; and no handwritten raw vtable/RTTI array, target-specific scalar wrapper, cookie, or tail-jump source.
- The exact seven-row manual coverage handoff is supervisor-owned and externally applied/validated under commands 14676-14679. Final readback proves each accepted row exactly once; B002 did not edit manual coverage.
- Report review, execution, movement, archive, current path, and validator-owned lifecycle history are external facts. B002 never runs or probes report lifecycle commands; this wording remains true across later supervisor actions.

## Confidence

- Overall recommendation confidence: `94/100`.
- Range, bytes, CFG, call order, vtable cell, base helper, child slot, field offset, and ownership: very high.
- Source return/access/signature and method names: high, supported by exact current family contracts but not original symbols.
- Source placement and owner/emitter: very high.
- Remaining uncertainty is limited to original formatting and whether the historical source used an equivalent null spelling. It does not affect behavior, type safety, or destination readiness.

## Validator Results

- Syntax preflight `validator.py --help` received command ID `000000014665`; it performed no file scan, apply, generation, or implementation mutation.
- UID0004AS target/path correction: command `000000014668`, timestamp `2026-07-19T21:08:00-04:00`, exit `0`, `ok:1`. It preserved UID0004AS, applied the path update, recorded `92/94`, rebuilt validator references/registry as validator-owned side effects, updated projected stats, and deferred generated refresh.
- UID0004AR sibling/path correction: command `000000014669`, timestamp `2026-07-19T21:09:17-04:00`, exit `0`, `ok:1`. It preserved UID0004AR, applied the canonical `0x00580570-0x005805b9` path, recorded `92/94`, rebuilt validator references/registry as validator-owned side effects, updated projected stats, and deferred generated refresh.
- UID00006M class: command `000000014670`, timestamp `2026-07-19T21:10:21-04:00`, exit `0`, `ok:1`; projected stats/registry side effects only, generated refresh deferred.
- UID0001IK split index: command `000000014671`, timestamp `2026-07-19T21:11:47-04:00`, exit `0`, `ok:1`; projected stats side effect only, generated refresh deferred.
- UID0003DB exact vtable data: command `000000014672`, timestamp `2026-07-19T21:12:48-04:00`, exit `0`, `ok:1`; one validator-owned reference-index addition plus projected stats, generated refresh deferred.
- UID0001Y1 type vtable family: command `000000014673`, timestamp `2026-07-19T21:13:50-04:00`, exit `0`, `ok:1`; projected stats side effect only, generated refresh deferred.
- UID0000KY by-file prose: command `000000014674`, timestamp `2026-07-19T21:18:03-04:00`, exit `0`, `ok:1`; projected stats side effect only, generated refresh deferred. No by-file reconstruction metadata was added.
- Final target-scoped waited refresh: command/header `000000014675`, timestamp/refreshed `2026-07-19T21:20:04-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`. Validator-owned side effects were registry rebuild, generated metadata refresh, and projected stats. Reported project-wide `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` diagnostics were unrelated existing inventory; no UID0004AR/UID0004AS target-specific warning occurred.
- Current generated `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`: SHA256 `AC80ED55CF38D3544E2E76517DDE1F5096ABBD274E7B87D347B74346CE59409F`, 35,335 bytes / 1,062 lines. It has one complete Integrate class, one public AddToLayer declaration/definition, one public RemoveFromLayer declaration/definition, Add before Remove, zero stale Integrate OnAttachToParent/OnHide declaration/definition, zero UID0004AR/UID0004AS Empty Emitter Markers, zero raw vtable arrays, zero security-cookie source, and no target-specific scalar deleting wrapper. Existing scalar-deleting-destructor text elsewhere in the file is comment-only compiler disposition for unrelated family ABI children.
- All six managed blocks were extracted from the report and current destinations after validation; every destination has exactly one block and each is byte-equal to its report block.
- Mandatory live MCP evidence succeeded on evidence-time database `9b0396a3`; exact health, bytes, function, xref, vtable, helper, and boundary results remain recorded in `IDA MCP Facts`. The callback did not mutate IDA.
- Historical pre-application manual coverage reread retained hashes `0C8C5E8E...181A`, `426E48F6...E994`, `7F09DD45...3B61`, and `7AFEEB7F...71C4`; at that time UID0004AR/UID0004AS were absent and the five existing rows were pre-callback.
- Supervisor by-memory command `000000014676`, by-class `000000014677`, by-file `000000014678`, and by-type/by-vtable `000000014679` each exited `0` with `ok:1`. Current validated hashes are respectively `27F745BA...2D86`, `D9AC33E6...BC46`, `CDF28233...7AFE`, and `249233F6...0749`.
- Current exact coverage readback is `7/7`: UID0001IK line 3201, UID0004AR line 3220, UID0004AS line 3221, UID0003DB line 3944, UID00006M by-class line 263, UID0000KY by-file line 151, and UID0001Y1 by-type/by-vtable line 82, each once with accepted text. These commands were supervisor-run; this reconciliation ran no validator.

## Changed Files

- Same report updated in place: `tools/leaser/Agents/Agent-B002/research/0004AS-IntegrateMacroEditControlPaneOnHide-source-quality.md`; all research, C01-C30 claims, six formal blocks, coverage handoff, and historical provenance remain present.
- Changed ordinary UID0004AS target: `by-memory/0x005805c0-0x005805da.IntegrateMacroEditControlPaneRemoveFromLayer.md`, SHA256 `4EA3EB3FCFEDA483AD2358D907F1BD476A6D087CA1DF275224164A9CBF00727C`, 7,628 bytes / 86 lines. Historical OnHide path is absent.
- Changed ordinary UID0004AR sibling: `by-memory/0x00580570-0x005805b9.IntegrateMacroEditControlPaneAddToLayer.md`, SHA256 `156A2AE3FD4F09C0F38214734B10CD021CE1937C7962BE01ECDD6B9AD6B341F1`, 7,181 bytes / 84 lines. Historical OnAttachToParent path is absent.
- Changed ordinary UID00006M class: `by-class/IntegrateMacroEditControlPane.md`, SHA256 `60EED15DA1C9C92986D18B51DA6C52566AA616E9395002A30B5522ECAC0FFA30`, 35,444 bytes / 207 lines.
- Changed ordinary UID0001IK aggregate: `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`, SHA256 `6EFCC82B78802C25BC2052AB4F2014256E3BA25A9173F1ADC4D1971FDB75B41E`, 53,806 bytes / 241 lines.
- Changed ordinary UID0003DB vtable evidence: `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`, SHA256 `7E590CC1290F9BA3D18157F1472BE3854D12E2DFD6E5FD716A5D653CCA69BDD8`, 20,715 bytes / 95 lines.
- Changed ordinary UID0001Y1 type-vtable evidence: `by-type/by-vtable/MacroDialogFamilyVtables.md`, SHA256 `6DA2F0E370F041141908488A11AEA9BF5F0BE2D9FAE703EDFBBA269BA5525504`, 40,712 bytes / 191 lines.
- Changed ordinary UID0000KY source prose: `by-file/MacroDialogs.md`, SHA256 `346D829774A86A071C82FA80071CC664F389911C53F2169FCB750CAC7C768FDC`, 95,897 bytes / 326 lines; no reconstruction metadata.
- Verify-only support changed by B002: none. Final support hashes and dispositions are recorded in `Supporting Research` and C25-C26.
- Validator-owned generated output refreshed by command 14675; B002 did not manually edit it. After callback completion, supervisor commands 14676-14679 changed only the four manual coverage files to the accepted seven-row union. This reconciliation changed only this report; B002 did not edit ordinary, manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA files.
- Externally changed manual files now read: by-memory SHA `27F745BA31D8487AC6C4837C709EBABCD7B470020E48529D0DA15C06AC9B2D86`; by-class `D9AC33E6C698E781E3F249A0E41D27352341933B5A0738181A957A7AE5A6BC46`; by-file `CDF2823366D7DDD40AAFE81712641A40454F6AE7904A35804F92F74E038E7AFE`; by-type/by-vtable `249233F6B031CFC104ED0C9CD5678BFDE873E03FBBD9092AD788675032030749`. Each contains its accepted row union exactly once.
- Each ordinary page was leased only for its immediate edit/validation and released immediately. Final shared/B002 lease ledger: zero active leases.
- Report lifecycle commands run or probed by B002: none. No legacy-tree artifact was created, moved, deleted, or adopted.

## Implementation Tracking Checklist

Initial report-only evidence and Gate 1 obligations:

- [x] Supervisor Gate 1 audited accepted report SHA `A2684F4E...3AA1` before callback.
- [x] Supervisor confirmed all 33 required H2 headings were present and substantive.
- [x] Confirm provenance is exactly `CHATGPT | 5.6 | xHigh`.
- [x] Confirm target UID/path/range/metadata and UID-preserving rename contract.
- [x] Confirm exact target bytes, byte hash, PE hash, RVA/raw mapping, and unique signature.
- [x] Confirm ten instructions, four blocks, complexity two, thiscall receiver, and no stack args.
- [x] Confirm predecessor/successor boundaries and 13/6-byte padding.
- [x] Confirm sole target xref is Integrate primary vtable cell `0x0062d364`.
- [x] Confirm Integrate Hide remains inherited at primary `+0x18`.
- [x] Confirm target/Pane/TextEditPane slot `+0x38` identity as RemoveFromLayer.
- [x] Confirm `m_textEdit` typed field at `+0x110` and constructor/destructor ownership.
- [x] Confirm child-null, child-first, unconditional-base behavior and void source return.
- [x] Confirm tail jump and incidental AL are compiler-only effects.
- [x] Confirm UID0004AR exact AddToLayer pair, four-argument signature, local bounds, cookie exclusion, and canonical-path/model-envelope distinction.
- [x] Confirm UID00006M complete 0x118 class block loses no current field or method.
- [x] Confirm public access and class closing brace before `[[CHILDREN]]`.
- [x] Confirm UID0001IK stays non-emitting with blank formal.
- [x] Confirm UID0003DB and UID0001Y1 stay compiler-owned markers.
- [x] Confirm by-file MacroDialogs remains prose-only with no reconstruction metadata.
- [x] Confirm Pane/TextEditPane/ScrollablePane support remains same-or-greater.
- [x] Confirm old report roots/search terms/findings and no-direct-report result.
- [x] Confirm all C01-C30 Action cells use only permitted vocabulary.
- [x] Confirm accepted report-only states were `proposed` and terminal callback states are now legal `applied`/`already-present` values.
- [x] Confirm all six formal blocks contain literal `[[[]]]`, BEGIN, and END lines.
- [x] Confirm no multiline C++ exists outside the six formal blocks.
- [x] Confirm supervisor-applied commands 14676-14679 produced all seven exact manual coverage placements once, preserving the current union and canonical paths.
- [x] Confirm no tracker or manual coverage edit is assigned to B002.
- [x] Confirm zero leases and zero prohibited writes/actions before callback.

Implementation callback obligations after supervisor Gate 1:

- [x] Re-read current goal, accepted report hash, all destinations, current reports, generated output, coverage rows, and leases.
- [x] Acquired only the target lease immediately before UID0004AS rename/edit.
- [x] Applied Destination 1 through UID-preserving target rename and preserved unrelated detail.
- [x] Ran/recorded UID0004AS scoped validator 14668 with timestamp/exit/ok/warnings/side effects.
- [x] Released target lease immediately and confirmed zero target lease.
- [x] Acquired only UID0004AR lease immediately before sibling rename/edit.
- [x] Applied Destination 2 through UID-preserving sibling rename/path correction and preserved unrelated detail.
- [x] Ran/recorded UID0004AR scoped validator 14669 and released immediately.
- [x] Leased/reread/rebased UID00006M, applied Destination 3 and report-level evidence, validated 14670, and released.
- [x] Confirmed complete class declaration retains all fields/methods and the public lifecycle pair.
- [x] Leased/reread/rebased UID0001IK, applied Destination 4 and split/history detail, validated 14671, and released.
- [x] Leased/reread/rebased UID0003DB, preserved Destination 5 marker, added slot evidence, validated 14672, and released.
- [x] Leased/reread/rebased UID0001Y1, preserved Destination 6 marker, added slot evidence, validated 14673, and released.
- [x] Leased/reread/rebased by-file MacroDialogs, added prose only, validated 14674, and released.
- [x] Verified Pane/ControlPane/TextEditPane/ScrollablePane and constructor/destructor support read-only; no concrete target-specific drift required an edit.
- [x] Preserved all same-or-greater concurrent MacroDialogs research, code, ownership, scores, and history.
- [x] Replaced every stale current OnHide/OnAttach lifecycle assertion while preserving it as labeled history.
- [x] Terminalized C01-C30 using only legal final verification states and destination proof outside state cells.
- [x] Recorded all changed and verify-only final hashes, leases, validators, warnings, and side effects.
- [x] Confirmed all ordinary leases were released before waited generation.
- [x] Ran authorized target-scoped waited validator 14675 and recorded command metadata.
- [x] Verified one complete Integrate class and exact AddToLayer then RemoveFromLayer source order.
- [x] Verified zero stale Integrate OnAttachToParent/OnHide declarations and definitions.
- [x] Verified zero UID0004AR/UID0004AS Empty Emitter Markers and zero handwritten target ABI source.
- [x] Preserved the exact seven-row supervisor-owned handoff, then read back its external application as `7/7` under commands 14676-14679 without editing coverage.
- [x] Updated Current Target State, ledger, Validator Results, Changed Files, generated proof, and checklist to callback truth.
- [x] Confirmed zero active leases, zero manual restricted-file edits, and zero lifecycle/execute actions before return.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000014680","destination_path":"executed-b-agent-research/B002/0004AS-IntegrateMacroEditControlPaneOnHide-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0004AS-IntegrateMacroEditControlPaneOnHide-source-quality.md","timestamp":"2026-07-19T21:51:01-04:00","uid":"0004AS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
