** TARGET-REPORT-UID:000312 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID000312 ModelessDialogPane Handle Pointer Or Mouse Event Source Quality

## Finalized Report / Current Recommendation

- Retain [UID:000312] as the exact reconstructable `ModelessDialogPane::HandlePointerOrMouseEvent(Event *)` definition for `[0x004a0840,0x004a0c8e)`, owned by [UID:00008K] and emitted through [UID:0000LH].
- Replace the stale `HandleMouseEvent(InputEvent *)` spelling with the project-canonical EventHandler override. The physical entry receives the `EventHandler` secondary view at complete-object offset `+0xa0`; normal C++ source remains an ordinary `ModelessDialogPane` override and contains no manual `this` adjustment.
- Populate the target formal CPP channel with the full source-shaped method below and leave its formal H channel blank. Move the complete class declaration from the class CPP channel to the class H channel; the class CPP channel should contain includes plus `[[CHILDREN]]` only.
- Correct the inherited dialog fields: `+0x20c` is Y, `+0x210` is X, and the clamp order is min-X, min-Y, max-X, max-Y at `+0x22c/+0x230/+0x234/+0x238`.
- Resolve `sub_49DE00` as `DialogPane::SetSelectionVisualState`, `sub_49FE20` as `DialogPane::RefreshActionButtonState`, and the physical `DialogPane_SavePosition` call as a one-argument `SavePosition(const RectBounds *)` ABI whose argument is currently ignored by the callee.
- Preserve the unusual binary behavior: right-button events, unrecognized event types, and the mouse-wheel branch return the untouched local result byte. The most faithful human source is an intentionally uninitialized local `bool handled`; replacing it with `false` changes observable machine behavior.
- Reroute [UID:00039P] from stale Surface ownership to ScreenPane class/file ownership. Live receiver type, global receiver, state offsets, and broad caller set prove `ScreenPane::RenderPresentation()`.
- Ordinary implementation now establishes target score `94/94` from the historical pre-callback `88/90`. Original lexical spellings and compiler-parity build comparison remain confidence caps, but there is no remaining ordinary behavior, range, ownership, field, helper, or source-shape blocker.

## Supporting Research

- Primary evidence is the current target/support documentation plus live IDA MCP readback from report-time session `supervisor-b008-uid0002gb-postsave-verify-20260810`, backed by `NexusTK.exe` at image base `0x400000`.
- Report-time health returned `status:ok`, Hex-Rays ready, string cache ready with 2068 entries, and input module `NexusTK.exe`. `auto_analysis_ready:false` is contextual only: bounded lookup, xref, decompile, bytes, disassembly, frame, UDT, and comment reads succeeded.
- The active MCP session used a supervisor-created post-save verification IDB whose input executable is the same NexusTK client. The session identifier is a dated evidence receipt, not permanent authority; future supervisor mutations must dynamically select and verify a current canonical session.
- The older B015 report `executed-b-agent-research/B015/00008K-ModelessDialogPane-class-source-quality.md`, SHA256 `57B9C10CE1B2017A773022497628CEE397EC2352BB8F5DBBDD1F5E0771C4291A`, was used only as historical lead material. Its useful vtable/boundary evidence was independently rechecked. Its Wave-era labels, X/Y field order, helper labels, default-false interpretation, and absent target formal body are superseded here.
- Pre-callback generated evidence was read, not edited: `auto-generated/NexusTK/ui/core/ModelessDialogPane.cpp`, command metadata `000000021785`, refreshed `2026-08-10T15:09:58-04:00`, SHA256 `AB6C9AADC5AF9E85AA1C0C70975833FE5EED441E8C913323D535CEEB3ABA222F`. Its Empty Emitter Marker and absent matching H are historical pre-callback state. Current coherent generated refresh/readback remains Primary-supervisor-owned and is authoritative only from later validator metadata/output.
- This report is lifecycle-neutral. Its state is authoritative from its current physical location plus validator lifecycle metadata at time of use; this text does not claim execution, archive, or future IDA application.

## Target

- Primary target: [UID:000312] `by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md`.
- Exact physical interval: `[0x004a0840,0x004a0c8e)`, 1102 bytes (`0x44e`).
- Current physical identity: 348 instructions, 53 basic blocks, cyclomatic complexity 27, full-range SHA256 `272B831D54D4AB1957322C400E6909E21A98D9A2A3FC1743CA80EEC3921EEB4C`.
- Current post-callback metadata: `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:00008K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008K`, populated formal CPP, blank formal H.
- Current target SHA256: `6FE39CC4C2888ADC6CD4E7E2FDD15424356DBDD9032AD64E4928959EC144082C`, 16181 bytes, 261 physical lines after scoped validation command `000000021803`.
- Queue reason: reconstructable by-memory item with an Empty Emitter Marker, no dedicated current B report, and a parent file whose emitter coverage is incomplete.

## Current Target State

- Current target records the exact range, secondary-vtable reference `0x00618cac`, complete-object recovery as secondary `this - 0xa0`, DialogPane ownership, event values `0/1/2/3/7`, switch-table exclusion, complete frame, positive/negative evidence, and full source body.
- Historical `HandleMouseEvent(InputEvent *)`, explicit default false, reversed axes/clamps, `UpdateFocusedControl`, zero-argument `SavePosition`, and Surface ownership are retained in explicit superseded sections with correction evidence.
- The class declaration now resides in formal H; class CPP contains the accepted includes plus `[[CHILDREN]]`. The target owns the exact CPP body and keeps formal H blank.
- Coherent generated refresh and physical CPP/H readback remain Primary-supervisor claims C063-C069. No B002 claim asserts that the pre-callback Empty Emitter Marker has already been regenerated away.
- Manual coverage is stale independently of metadata: by-memory coverage line 1312 reports `86%`, class coverage line 333 reports `87%`, file coverage line 170 reports `89%`, struct coverage reports `85%` for UID0001V9, and vtable coverage reports `86%` for UID0001Y6.

## Executive Recommendation

- Direct class owner: [UID:00008K] `ModelessDialogPane`.
- Direct source root: [UID:0000LH] `NexusTK/ui/core/ModelessDialogPane.cpp` with declaration in `ModelessDialogPane.h`.
- Physical entry model: secondary EventHandler view; source model: ordinary virtual override.
- Exact source signature: `bool ModelessDialogPane::HandlePointerOrMouseEvent(Event *event)`.
- Exact target channel: full method definition in target CPP, blank target H.
- Class channel: complete declaration in class H; includes plus `[[CHILDREN]]` in class CPP.
- Vtables and RTTI remain compiler-generated from the declaration and method definitions; UID0001Y6/UID00036P remain non-body emitters and must not hand-emit vtable data.
- Support changes are required because emitting the target against the current declarations would encode incorrect field order, an impossible protected member read, the wrong SavePosition ABI, and the wrong helper name.

## Supervisor Active Recheck

- Report-time MCP `lookup_funcs` freshly returned target `sub_4A0840`, size `0x44e`; `sub_49DE00`, size `0x67`; `DialogPane_SavePosition`, size `0xae`; `sub_49FE20`, size `0x8e`; and `ScreenPane_RenderPresentation`, size `0x237`.
- Fresh decompilation of `0x4a0840` returned the complete switch and every relied-on call. Fresh `xrefs_to` returned one data xref at `0x618cac` and no ordinary code caller.
- The full target body was audited to the machine order, including state assignments before mode changes, Y-before-X clamping, dispatch before presentation, presentation before release-point re-hit-test, virtual command before refresh helper, and the uninitialized result load.
- The accepted implementation callback updated and physically reread all 16 authorized ordinary destinations. IDA remained read-only/unmodified, coverage/generated files were not manually edited, and no report lifecycle command was run.
- Scoped `--no-generated-refresh` validators passed for every edited destination; current command IDs are `000000021803`, `000000021806`, `000000021810-000000021818`, and superseding mirror revalidations `000000021819-000000021823`.
- The target no longer has a substantive “needs investigation” blocker. Remaining uncertainty is limited to historical lexical spelling and future compile/binary comparison.

## Inference Research Guidance Check

- Human-source recovery takes precedence over decompiler spelling. No final C++ identifier retains `sub_`, `dword_`, raw member offsets, `_DWORD`, anonymous `vN` locals, or manual secondary-view casts.
- Runtime replication takes precedence over stylistic cleanup. The report preserves the binary's uninitialized return behavior even though initializing `handled` would be safer conventional code.
- Existing project-wide names are reused where supported: `Event`, `EventType`, `HandlePointerOrMouseEvent`, `RectBounds`, `PointInRect`, `GetChild<ControlPane>`, `SetHoverControl`, `OnControlCommand`, and `g_pScreenPane`.
- Inferred names are selected from behavior and surrounding project style: `m_dragOriginY/X`, `m_dragClampMinX/MinY/MaxX/MaxY`, `IsSelectable`, and `RefreshActionButtonState`.
- Naming consistency is subordinate to exact behavior and human-shaped source, but no contrary original symbol was found that justifies a local alternate style.
- Wave2/Wave3 labels in historical documents are ignored as workflow authority. Their underlying evidence is retained only where independently verified.

## Heuristic / Inference Reanalysis And Validation

- `HandlePointerOrMouseEvent` is not merely a preferred rename. It is the canonical virtual slot spelling in current EventHandler, Pane, DialogPane, and many derived class declarations; the secondary vtable slot proves this function is that override.
- `SetSelectionVisualState` is supported by both writes and side effects: it neutralizes the previous selected child's visual state, stores new id/state, and applies the new state when the id is valid.
- `RefreshActionButtonState` is stronger than historical `UpdateFocusedControl` or `RedrawSelectedControl`: `0x49fe20` never changes focus. It snapshots the focused control's enabled state, invokes virtual `UpdateActionButton`, and invalidates the focused control rectangle only if enabled state changed.
- `IsSelectable` is the best source-facing inline accessor for ControlPane `+0xff`. Interactive controls set it nonzero, passive/static controls clear it, and the target tests it before changing the dialog hover/active control. It is intentionally described as inferred rather than an original symbol.
- `SavePosition(const RectBounds *)` is required by physical calling convention: target materializes a 16-byte bounds object and pushes its address before the call; every callee return is `retn 4`. The callee currently recomputes bounds and does not read the explicit pointer, so the parameter is source-visible but unused in this build.
- `ScreenPane::RenderPresentation` is proven by the receiver `g_pScreenPane`, current ScreenPane type, ScreenPane presentation fields, named sibling callers, and its use after input state changes. Surface is a dependency, not the owning class/file.
- The result local is not a decompiler accident. Cases 4, 5, 6, 7 and default converge on a byte load from stack local `var_29` with no dominating store on those paths.

## Evidence Standards Used

- Exact bytes and exclusive range determine physical ownership.
- Switch-table entries and successor alignment are data/boundary evidence, not source body.
- Vtable slot and constructor stores determine class and secondary-view route.
- Decompile is accepted only where reconciled with instruction order, stack cleanup, UDT offsets, and neighboring docs.
- A source-facing name must account for all callers and side effects, not only the target callsite.
- Negative evidence is recorded without being promoted to proof of absence beyond the bounded executable.
- Score increases require resolved source behavior, owner, emitter, field names, helper names, formal channel placement, and draft C++; merely cataloging blockers is insufficient.

## Evidence Checked

- Live MCP: `idb_list`, `server_health`, `lookup_funcs`, target decompile, xrefs, exact bytes/disassembly, CFG metrics, comments, function types, frame rows, UDTs, helper decompiles, callers, and callee inventories.
- Target and exact parent aggregate; ModelessDialogPane class/file/layout/vtables/vtable-data; Event/EventHandler; Pane/GrafPort; DialogPane class/layout/aggregate/helpers; ControlPane; ScreenPane class/file; Surface file/presentation family.
- Current generated ModelessDialogPane CPP and absence of H; current manual class/file/memory/type coverage rows.
- Historical B015 report only as a lead and contradiction inventory.
- Neighbor boundaries at `0x4a0830`, `0x4a0835`, `0x4a0840`, `0x4a0c8e`, `0x4a0c90`, `0x4a0cb0`, `0x4a0cc6`, and `0x4a0cd0`.

## Claim And Incorporation Ledger

Rows owned by B002 are `applied-verified` only after physical destination reread and the scoped validator receipt recorded below. Primary-supervisor rows remain `proposed`; no B002 row claims generated refresh, manual coverage, IDA mutation/readback, or lifecycle execution.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Actor | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C000312-001 | 000312 | Record exact range, size, 348 instructions, 53 blocks, complexity 27, boundary bytes, and full-range SHA256. | Very high | live bytes/disasm/CFG | target exact binary contract | incorporate | B002 | applied-verified |
| C000312-002 | 000312 | Record the eight-entry switch table at 0x4a0c90 and exclude alignment/table/successor thunks from the target body. | Very high | disasm/data/neighbor lookup | target range analysis | incorporate | B002 | applied-verified |
| C000312-003 | 000312 | Replace HandleMouseEvent/InputEvent with HandlePointerOrMouseEvent/Event and explain the secondary EventHandler view at complete-object +0xa0. | Very high | vtable/EventHandler/decompile | target behavior and ABI | incorporate | B002 | applied-verified |
| C000312-004 | 000312 | Record the complete physical frame and the intentionally uninitialized result byte. | Very high | frame/disasm/decompile | target frame and parity | incorporate | B002 | applied-verified |
| C000312-005 | 000312 | Document exact event-0 title drag, Y-before-X clamp order, and true return. | Very high | target body | target branch inventory | incorporate | B002 | applied-verified |
| C000312-006 | 000312 | Document exact event-0 non-drag hit-test, pressed visual update/reset, dispatch, and false/true returns. | Very high | target body/helpers | target branch inventory | incorporate | B002 | applied-verified |
| C000312-007 | 000312 | Document exact event-1 title hit, bounds check, Y/X capture, mode save/remap, and repeated-down handling. | Very high | target body/Pane | target branch inventory | incorporate | B002 | applied-verified |
| C000312-008 | 000312 | Document exact event-1 control hit, signed rejection, IsSelectable gate, hover update, press capture, visual state, and dispatch. | High | target body/ControlPane | target branch inventory | incorporate | B002 | applied-verified |
| C000312-009 | 000312 | Document exact event-2 id and bounds guards followed by dispatch. | Very high | target body | target branch inventory | incorporate | B002 | applied-verified |
| C000312-010 | 000312 | Document exact event-3 drag release, mode restore, conditional bounds/save call, drag clear, and handled state. | Very high | target/disasm/SavePosition | target branch inventory | incorporate | B002 | applied-verified |
| C000312-011 | 000312 | Document exact event-3 press release, selection reset, dispatch, presentation, re-hit, command, refresh, and true return. | Very high | target/helpers | target branch inventory | incorporate | B002 | applied-verified |
| C000312-012 | 000312 | Preserve event-7 dispatch-without-id-guard and uninitialized wheel/right/default return behavior. | Very high | target CFG/disasm | target parity warning | incorporate | B002 | applied-verified |
| C000312-013 | 000312 | Correct inherited Y/X and min-X/min-Y/max-X/max-Y field mapping throughout target and support prose/formal declarations. | Very high | translated offsets/instruction operands | target/class/layout docs | incorporate | B002 | applied-verified |
| C000312-014 | 000312 | Replace compiler/helper labels with SetSelectionVisualState, SavePosition(const RectBounds *), RefreshActionButtonState, and ScreenPane::RenderPresentation. | High | complete helper bodies/callers | target helper inventory | incorporate | B002 | applied-verified |
| C000312-015 | 000312 | Populate target formal CPP with the complete exact method body and keep target formal H blank. | High | full parity audit | target formal CPP/H | incorporate | B002 | applied-verified |
| C000312-016 | 00008K | Move complete ModelessDialogPane declaration to class H with canonical Event signature; leave includes plus children in class CPP. | High | channel rules/generated output | class formal CPP/H | incorporate | B002 | applied-verified |
| C000312-017 | 00008K | Reconcile class behavior, helper, field, vtable-slot, and historical assumptions without pruning valid history. | High | target/live support evidence | class narrative | incorporate | B002 | applied-verified |
| C000312-018 | 0000LH | Reconcile file method map, generated header/source route, ScreenPane dependency, and source-placement rationale. | High | target/class/generated | file narrative | incorporate | B002 | applied-verified |
| C000312-019 | 00012Z | Update aggregate prose to point to the dedicated complete target analysis while preserving non-emitting aggregate disposition. | High | split children/ranges | aggregate narrative | incorporate | B002 | applied-verified |
| C000312-020 | 0001V9 | Correct translated inherited field mapping and canonical event method name; preserve no-derived-tail conclusion. | Very high | secondary-view translation | Modeless layout | incorporate | B002 | applied-verified |
| C000312-021 | 0001U4 | Correct +20c/+210 and +22c..+238 names in table, declaration mirrors, and history. | Very high | exact target operands | DialogPane layout | incorporate | B002 | applied-verified |
| C000312-022 | 0001Y6 | Rename secondary slot to HandlePointerOrMouseEvent and preserve three-view/source-generated vtable contract. | Very high | vtable dwords/interface | Modeless vtable | incorporate | B002 | applied-verified |
| C000312-023 | 00036P | Rename slot prose to HandlePointerOrMouseEvent and preserve blank generated-binary formal channels. | Very high | vtable child data | vtable-data page | incorporate | B002 | applied-verified |
| C000312-024 | 00003T | Correct DialogPane formal field order, SavePosition signature, RefreshActionButtonState declaration, and supporting behavior. | High | target/helper bodies | DialogPane class | incorporate | B002 | applied-verified |
| C000312-025 | 000038 | Add public inline IsSelectable() const returning m_controlFlags != 0, and make SetVisualState publicly callable so DialogPane source is legal; document both without exposing storage. | High | constructors/target/helper calls | ControlPane class | incorporate | B002 | applied-verified |
| C000312-026 | 0003KN | Populate exact SetSelectionVisualState CPP, keep H blank, and add complete side-effect evidence. | Very high | full helper body/callers | selection helper | incorporate | B002 | applied-verified |
| C000312-027 | 00012R | Add exact 0x49fa60 and 0x49fe20 behavior, ABI, inferred names, and recommendation for dedicated child splits. | High | helper bodies/xrefs/frame | DialogPane aggregate | incorporate | B002 | applied-verified |
| C000312-028 | 0000CB | Make RenderPresentation public and record its broad external caller/ScreenPane ownership evidence without changing its body here. | High | receiver/callers/fields | ScreenPane class | incorporate | B002 | applied-verified |
| C000312-029 | 0000NB | Add UID00039P to ScreenPane source-root inventory and remove the stale Surface route. | High | receiver/source family | ScreenPane file | incorporate | B002 | applied-verified |
| C000312-030 | 00039P | Rename page/title/source role to ScreenPaneRenderPresentation, reroute owner/emitter to 0000CB, preserve exact body evidence, and keep formal body pending its dedicated pass. | High | live type/callers/callees | presentation child | incorporate | B002 | applied-verified |
| C000312-031 | 0000OC | Remove UID00039P as a Surface-owned child while retaining Surface dependencies and historical route as superseded. | High | ownership analysis | Surface file | incorporate | B002 | applied-verified |
| C000312-032 | 000312 | Raise target metadata to 94/94 with owner/emitter unchanged and exact score rationale. | High | completed source-quality analysis | target metadata | incorporate | B002 | applied-verified |
| C000312-033 | 00008K | Set ModelessDialogPane class metadata to 93/94 while preserving owner/emitter 0000LH. | High | resolved class channel/interface defects | by-class/ModelessDialogPane.md metadata | incorporate | B002 | applied-verified |
| C000312-034 | 0000LH | Set ModelessDialogPane file metadata to 92/92 while preserving FILE ownership. | High | complete source/header route | by-file/ModelessDialogPane.md metadata | incorporate | B002 | applied-verified |
| C000312-035 | 00012Z | Preserve aggregate metadata 86/90, owner NONE, blank emitter, and non-reconstructable exact-child index. | Very high | exact split disposition | by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md metadata | already-present | B002 | applied-verified |
| C000312-036 | 0001V9 | Set ModelessDialogPaneLayout metadata to 93/95 with owner/emitter 00008K unchanged. | High | corrected secondary-view layout | by-type/by-struct/ModelessDialogPaneLayout.md metadata | incorporate | B002 | applied-verified |
| C000312-037 | 0001U4 | Set DialogPaneLayout metadata to 94/97 with owner/emitter 00003T unchanged. | High | corrected exact field ordering | by-type/by-struct/DialogPaneLayout.md metadata | incorporate | B002 | applied-verified |
| C000312-038 | 0001Y6 | Set ModelessDialogPaneVtables metadata to 91/95 with owner/emitter 00008K unchanged. | High | exact slot naming/source contract | by-type/by-vtable/ModelessDialogPaneVtables.md metadata | incorporate | B002 | applied-verified |
| C000312-039 | 00036P | Set ModelessDialogPaneVtableData metadata to 91/95 with owner/emitter 0001Y6 unchanged. | High | exact slot naming/compiler disposition | by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md metadata | incorporate | B002 | applied-verified |
| C000312-040 | 0003KN | Set DialogPaneSetSelectionVisualState metadata to 92/95 with owner/emitter 00003T unchanged. | High | complete helper source/semantics | by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md metadata | incorporate | B002 | applied-verified |
| C000312-041 | 00003T | Preserve DialogPane class metadata 93/96 and owner/emitter 0000IT after exact declaration corrections. | Very high | mature class plus bounded corrections | by-class/DialogPane.md metadata | already-present | B002 | applied-verified |
| C000312-042 | 000038 | Preserve ControlPane class metadata 91/93 and owner/emitter 0000IG after bounded access corrections. | High | inferred accessor/public-call legality | by-class/ControlPane.md metadata | already-present | B002 | applied-verified |
| C000312-043 | 00039P | Set presentation child metadata to 90/93 and reroute owner/emitter from 0000OC to 0000CB. | High | ScreenPane receiver/caller/source proof | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md metadata | incorporate | B002 | applied-verified |
| C000312-044 | 0000CB | Preserve ScreenPane class metadata 93/94 and owner/emitter 0000NB after public declaration/routing correction. | Very high | existing mature ScreenPane evidence | by-class/ScreenPane.md metadata | already-present | B002 | applied-verified |
| C000312-045 | 0000NB | Preserve ScreenPane file metadata 93/94 and FILE ownership after adding UID00039P route. | Very high | existing mature source root | by-file/ScreenPane.md metadata | already-present | B002 | applied-verified |
| C000312-046 | 0000OC | Preserve Surface file metadata 90/89 and FILE ownership after removing polluted UID00039P ownership. | High | Surface remains dependency/source family | by-file/Surface.md metadata | already-present | B002 | applied-verified |
| C000312-047 | 000312 | Run scoped no-generated-refresh validation for the edited target page and record command/timestamp/exit/ok receipt. | High | validator contract | by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md validation | incorporate | B002 | applied-verified |
| C000312-048 | 00008K | Run scoped no-generated-refresh validation for the edited ModelessDialogPane class page and record receipt. | High | validator contract | by-class/ModelessDialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-049 | 0000LH | Run scoped no-generated-refresh validation for the edited ModelessDialogPane file page and record receipt. | High | validator contract | by-file/ModelessDialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-050 | 00012Z | Run scoped no-generated-refresh validation for the edited ModelessDialogPane aggregate page and record receipt. | High | validator contract | by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-051 | 0001V9 | Run scoped no-generated-refresh validation for the edited ModelessDialogPaneLayout page and record receipt. | High | validator contract | by-type/by-struct/ModelessDialogPaneLayout.md validation | incorporate | B002 | applied-verified |
| C000312-052 | 0001U4 | Run scoped no-generated-refresh validation for the edited DialogPaneLayout page and record receipt. | High | validator contract | by-type/by-struct/DialogPaneLayout.md validation | incorporate | B002 | applied-verified |
| C000312-053 | 0001Y6 | Run scoped no-generated-refresh validation for the edited ModelessDialogPaneVtables page and record receipt. | High | validator contract | by-type/by-vtable/ModelessDialogPaneVtables.md validation | incorporate | B002 | applied-verified |
| C000312-054 | 00036P | Run scoped no-generated-refresh validation for the edited ModelessDialogPaneVtableData page and record receipt. | High | validator contract | by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md validation | incorporate | B002 | applied-verified |
| C000312-055 | 00003T | Run scoped no-generated-refresh validation for the edited DialogPane class page and record receipt. | High | validator contract | by-class/DialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-056 | 000038 | Run scoped no-generated-refresh validation for the edited ControlPane class page and record receipt. | High | validator contract | by-class/ControlPane.md validation | incorporate | B002 | applied-verified |
| C000312-057 | 0003KN | Run scoped no-generated-refresh validation for the edited selection-helper page and record receipt. | High | validator contract | by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md validation | incorporate | B002 | applied-verified |
| C000312-058 | 00012R | Run scoped no-generated-refresh validation for the edited DialogPane aggregate page and record receipt. | High | validator contract | by-memory/0x0049d8a0-0x0049feae.DialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-059 | 0000CB | Run scoped no-generated-refresh validation for the edited ScreenPane class page and record receipt. | High | validator contract | by-class/ScreenPane.md validation | incorporate | B002 | applied-verified |
| C000312-060 | 0000NB | Run scoped no-generated-refresh validation for the edited ScreenPane file page and record receipt. | High | validator contract | by-file/ScreenPane.md validation | incorporate | B002 | applied-verified |
| C000312-061 | 00039P | Run scoped no-generated-refresh validation for the edited presentation child page and record receipt. | High | validator contract | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md validation | incorporate | B002 | applied-verified |
| C000312-062 | 0000OC | Run scoped no-generated-refresh validation for the edited Surface file page and record receipt. | High | validator contract | by-file/Surface.md validation | incorporate | B002 | applied-verified |
| C000312-063 | 0000LH | Run one supervisor-owned coherent generated refresh and verify current ModelessDialogPane.cpp/H command metadata and source-root routing. | High | validator-generated source contract | auto-generated/NexusTK/ui/core/ModelessDialogPane.cpp and .h | incorporate | Primary supervisor | proposed |
| C000312-064 | 00008K | Verify the generated ModelessDialogPane class declaration occurs exactly once in ModelessDialogPane.h and not in the CPP body. | High | class formal channel contract | generated ModelessDialogPane.h/CPP class readback | incorporate | Primary supervisor | proposed |
| C000312-065 | 000312 | Verify the generated HandlePointerOrMouseEvent definition occurs exactly once in ModelessDialogPane.cpp with no Empty Emitter Marker. | High | target formal CPP contract | generated ModelessDialogPane.cpp target readback | incorporate | Primary supervisor | proposed |
| C000312-066 | 0000IT | Verify generated DialogPane CPP/H contains one selection-helper body and corrected SavePosition/RefreshActionButtonState declarations. | High | DialogPane formal channel contract | generated DialogPane.cpp/H readback | incorporate | Primary supervisor | proposed |
| C000312-067 | 0000IG | Verify generated ControlPane H exposes IsSelectable and SetVisualState legally once while preserving protected storage. | High | ControlPane formal H contract | generated ControlPane.h readback | incorporate | Primary supervisor | proposed |
| C000312-068 | 0000NB | Verify generated ScreenPane H/CPP owns the public RenderPresentation declaration/route after coherent refresh. | High | ScreenPane owner/emitter contract | generated ScreenPane.cpp/H readback | incorporate | Primary supervisor | proposed |
| C000312-069 | 0000OC | Verify generated Surface CPP/H no longer owns or duplicates UID00039P after coherent refresh. | High | negative owner/emitter contract | generated Surface.cpp/H readback | incorporate | Primary supervisor | proposed |
| C000312-070 | 000312 | Preserve target's superseded HandleMouseEvent/InputEvent, reversed axes, stale helpers, default-false, and blank-emitter assumptions with explicit correction reasons. | High | Rule 26/history/current body | target historical assumptions | historicalize | B002 | applied-verified |
| C000312-071 | 00008K | Preserve class-level B015 assumptions and stale CPP-class/blank-H state as dated history while making current conclusions authoritative. | High | historical report/current class | ModelessDialogPane class history | historicalize | B002 | applied-verified |
| C000312-072 | 0000LH | Preserve stale file method/dependency/header-route assumptions as dated history with current generated-route corrections. | High | historical file/current generated | ModelessDialogPane file history | historicalize | B002 | applied-verified |
| C000312-073 | 00012Z | Preserve aggregate-era shallow handler summary as historical child-index evidence, not current dedicated coverage. | High | split history/current child | ModelessDialogPane aggregate history | historicalize | B002 | applied-verified |
| C000312-074 | 0001V9 | Preserve historical translated-field aliases and explain why current Y/X and clamp-axis mapping supersedes them. | Very high | exact operand translation | ModelessDialogPaneLayout history | historicalize | B002 | applied-verified |
| C000312-075 | 0001U4 | Preserve historical DialogPane field-order aliases and explain exact corrected operand mapping. | Very high | exact target operands | DialogPaneLayout history | historicalize | B002 | applied-verified |
| C000312-076 | 0001Y6 | Preserve historical HandleMouseEvent slot spelling and stale Wave-era metadata only as rejected/superseded history. | High | canonical EventHandler interface | ModelessDialogPaneVtables history | historicalize | B002 | applied-verified |
| C000312-077 | 00036P | Preserve historical HandleMouseEvent/vtable labels while making canonical slot naming current. | High | exact vtable data | ModelessDialogPaneVtableData history | historicalize | B002 | applied-verified |
| C000312-078 | 00039P | Preserve historical SurfaceRenderPresentation ownership/name as superseded routing history with ScreenPane proof. | High | live receiver/callers | presentation child history | historicalize | B002 | applied-verified |
| C000312-079 | 0000OC | Preserve Surface's former UID00039P child route as rejected ownership history while retaining real Surface dependencies. | High | ownership reanalysis | Surface file history | historicalize | B002 | applied-verified |
| C000312-080 | 000312 | Replace the exact UID000312 row in by-memory/-coverage-report.md with the Section 28 94% very-strong text. | High | current row plus accepted recommendation | by-memory/-coverage-report.md UID000312 row | incorporate | Primary supervisor | proposed |
| C000312-081 | 00008K | Replace the exact UID00008K row in by-class/-coverage-report.md with the Section 28 93% very-strong text. | High | current row plus accepted recommendation | by-class/-coverage-report.md UID00008K row | incorporate | Primary supervisor | proposed |
| C000312-082 | 0000LH | Replace the exact UID0000LH row in by-file/-coverage-report.md with the Section 28 92% very-strong text. | High | current row plus accepted recommendation | by-file/-coverage-report.md UID0000LH row | incorporate | Primary supervisor | proposed |
| C000312-083 | 0001V9 | Replace the exact UID0001V9 row in by-type/by-struct/-coverage-report.md with the Section 28 93% very-strong text. | High | current row plus accepted recommendation | by-type/by-struct/-coverage-report.md UID0001V9 row | incorporate | Primary supervisor | proposed |
| C000312-084 | 0001Y6 | Replace the exact UID0001Y6 row in by-type/by-vtable/-coverage-report.md with the Section 28 91% very-strong text. | High | current row plus accepted recommendation | by-type/by-vtable/-coverage-report.md UID0001Y6 row | incorporate | Primary supervisor | proposed |
| C000312-085 | 000312 | Apply I000312-01 only with the exact fresh target profile/frame contract: pure rename, return char-to-bool and ECX int-to-EventHandler-pointer deltas, existing Event-pointer stack row preserved, every local/save/return/gap protected, exact comment and full readback. | High | fresh bounded profile/stack_frame/disasm/comments/set_type schema | IDA function 0x004a0840 | incorporate | Primary supervisor | proposed |
| C000312-086 | 0003KN | Apply I000312-02 only with the exact fresh helper frame contract: pure rename, ECX receiver correction, controlId four-byte row, visualState unsigned-byte semantic member inside an unchanged four-byte ABI slot, protected saves/return/padding, exact comment and full readback. | High | fresh bounded profile/stack_frame/disasm/comments/set_type schema | IDA function 0x0049de00 | incorporate | Primary supervisor | proposed |
| C000312-087 | 00012R | Apply I000312-03 as comment-only: preserve current name, no-argument IDA prototype, complete frame, range/body/xrefs and retn 4; document the caller-pushed bounds pointer without issuing nondeterministic set_type while the frame lacks an explicit argument member. | High | fresh bounded profile/stack_frame/disasm/comments and absent argument row | IDA function 0x0049fa60 | incorporate | Primary supervisor | proposed |
| C000312-088 | 00012R | Apply I000312-04 only with the exact fresh helper frame contract: pure rename, return int-to-void and ECX receiver-type deltas only, no stack arguments, all locals/conditional saves/return protected, exact comment and full readback. | High | fresh bounded profile/stack_frame/disasm/comments/set_type schema | IDA function 0x0049fe20 | incorporate | Primary supervisor | proposed |
| C000312-089 | 00039P | Freshly protect I000312-05 as complete no-change state: exact ScreenPane_RenderPresentation name/type/range, every local/save/return/unmodeled/tail frame row, body/xrefs, and all four comment channels; any post-batch difference stops save. | Very high | fresh bounded profile/stack_frame/disasm/comments | IDA function 0x00557140 | already-present | Primary supervisor | proposed |
| C000312-090 | 000312 | Require fresh Gate 2 ordinary, generated, coverage, and IDA verification before supervisor-only execution or archive. | Very high | lifecycle rules | UID000312 report lifecycle | incorporate | Primary supervisor | proposed |

## Positive Evidence Summary

- The exact modeled function and exact documentation interval agree at `0x44e` bytes.
- The only incoming xref is the expected secondary-vtable slot at `0x618cac`; ordinary direct callers are not expected for a virtual event override.
- The function repeatedly converts the physical secondary view to the complete DialogPane with `this - 0xa0`, matching constructor vtable stores and the three-view RTTI family.
- Every accessed member translates into known Pane/DialogPane/ControlPane storage; no derived tail is required.
- Every switch branch is coherent UI behavior and all callees belong to DialogPane, Pane, geometry, ScreenPane, or security-cookie infrastructure.
- The target's `retn 4`, Event UDT, and canonical EventHandler slot prove one explicit `Event *` parameter and bool/byte return.
- The range ends before a two-byte alignment instruction and an eight-entry jump table, establishing a clean source-method boundary.
- The complete formal source below preserves all state transitions and the original uninitialized-result defect without decompiler artifacts.

## IDA MCP Facts

- Historical report-time session: `supervisor-b008-uid0002gb-postsave-verify-20260810`; module `NexusTK.exe`; image base `0x400000`; Hex-Rays ready. This dated session is evidence history, not current execution authority.
- Fresh bounded Gate 1 repair evidence was read on `2026-08-11T08:58:32-04:00` through MCP session `b002-uid000312-frame-readback-20260811`, opened from canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with auto-analysis disabled. `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays and the 2068-entry string cache ready; `auto_analysis_ready:false` was contextual because every bounded read succeeded.
- The canonical IDB remained byte-identical across the read-only pass: 143204669 bytes, SHA256 `A3216A4C54BD224E3633EB90A40C77C708A2BA76692DA142FD81C337FED3AA45` before and after the `2026-08-11T09:03:02-04:00` readback. No IDA mutation or save was issued.
- Target lookup: `sub_4A0840`, `[0x4a0840,0x4a0c8e)`, size `0x44e`.
- Fresh `func_profile` current target prototype is literally `char __thiscall(int this, int)` while the independently read `stack_frame` already names/types the sole stack argument as `event : Event *`. The proposed physical type reconciles both displays as `bool __thiscall ModelessDialogPane_HandlePointerOrMouseEvent(EventHandler *this, Event *event)` without changing the physical stack layout.
- Current target entry comments: address regular absent, address repeatable absent, function regular absent, function repeatable absent.
- The following prior source-role table is retained as a concise behavior summary. The complete literal current and expected frame contracts for I000312-01 through I000312-05, including saved-register and unmodeled physical rows, are authoritative in Section 21.

| Physical location | Width | Source role | Evidence/disposition |
| --- | --- | --- | --- |
| `ecx` on entry | 4 | secondary EventHandler-view `this` | complete ModelessDialogPane is `ecx - 0xa0` |
| `[ebp+0x8]` | 4 | `Event *event` | sole explicit argument; epilogue `retn 4` |
| `[ebp+0x4]` | 4 | return address | protected frame row |
| `[ebp+0x0]` | 4 | saved EBP | protected frame row |
| `[ebp-0x4]` | 4 | security cookie | compiler scaffold, no source local |
| `[ebp-0x14..ebp-0x5]` | 16 | hit-test/visible-bounds `RectBounds bounds` | copied before PointInRect branches |
| `[ebp-0x24..ebp-0x15]` | 16 | drag-release `RectBounds saveBounds` | filled by GetScreenBounds and passed to SavePosition |
| `[ebp-0x28]` | 4 | `int controlId` | HitTestControls output |
| `[ebp-0x29]` | 1 | `bool handled` result byte | intentionally read uninitialized on wheel/right/default paths |
| `[ebp-0x2d]` low byte | 1 active byte | `signed char hitType` scratch | decompiler widened container is not a source `int` |
| `[ebp-0x34]` | 4 | cached `int mouseX` | preserves X across branch/call sequences |
| below local allocation | 12 total | saved EBX/ESI/EDI | compiler-preserved registers, no source locals |

- Exact first 16 bytes: `55 8b ec 83 ec 38 a1 24 2f 67 00 33 c5 89 45 fc`.
- Exact last 16 bytes: `5f 5e 33 cd 5b e8 a7 6a 12 00 8b e5 5d c2 04 00`.
- Xrefs: one data xref at `0x618cac`; no ordinary code xref.
- Event UDT size `0x110`; `m_type +0x4`; pointer payload Y `+0x8`, X `+0xc`.
- ControlPane size `0x108`; `m_controlFlags +0xff`; `m_enabled +0x101`.
- MapRect/RectBounds size 16, ordered left/top/right/bottom in the accepted UDT.
- Direct callees: `DialogPane_HitTestControls`, `PointInRect`, `Pane_SetMode`, `sub_49DE00`, `DialogPane_DispatchInputToControl`, `DialogPane_SavePosition`, `ScreenPane_RenderPresentation`, and `sub_49FE20`, plus security-cookie verification.

## Function / Child Inventory

| Range / item | Role | Source disposition |
| --- | --- | --- |
| `0x004a0830-0x004a0835` | separate `ModelessDialogPane::IsModal` virtual | UID000311 child, not target |
| `0x004a0835-0x004a0840` | eleven `0xcc` alignment bytes | compiler padding, no source |
| `0x004a0840-0x004a0c8e` | complete pointer/mouse-event override | UID000312 CPP method |
| `0x004a0c8e-0x004a0c90` | `66 90` two-byte alignment | compiler padding, no source |
| `0x004a0c90-0x004a0cb0` | eight switch-table dwords | compiler-generated from target switch, outside body |
| `0x004a0cb0-0x004a0cc6` | two VersatileAlertPane adjustor thunks | unrelated protected neighbors |
| `0x004a0cc6-0x004a0cd0` | ten `0xcc` bytes | compiler padding |
| `0x004a0cd0...` | next modeled scalar deleting destructor | unrelated successor |

Switch table: case 0 -> `0x4a0a1f`; case 1 -> `0x4a0878`; case 2 -> `0x4a09c4`; case 3 -> `0x4a0b1f`; cases 4, 5, 6 -> `0x4a0c78`; case 7 -> `0x4a0c3c`.

## Direct Xref / Caller Inventory

| Entity | Route | Meaning |
| --- | --- | --- |
| `0x004a0840` | data xref from `0x00618cac` only | secondary EventHandler virtual slot |
| `0x00618ca8` | table contains adjustor, target, IsModal | exact secondary view |
| constructor `0x004a0760` | stores table base `0x00618ca8` at `0x004a07c4` | class instance installs route |
| `0x0049de00` | 16 code xrefs from 8 caller functions | shared DialogPane selection-state helper |
| `0x0049fa60` | 3 caller functions | shared position persistence helper |
| `0x0049fe20` | 10 callers | shared post-command action-button refresh helper |
| `0x00557140` | 37 xrefs from 24 named callers | broad ScreenPane presentation method, not target-local helper |

No direct branch to the target is negative evidence expected for virtual dispatch. It does not lower reconstructability or source liveness.

## Documentation Evidence And IDA Status

- [UID:00004N] and derived pane docs establish the canonical virtual name `HandlePointerOrMouseEvent(Event *)`.
- [UID:00004L] establishes exact EventType names and numeric values used by the formal draft.
- [UID:00005V]/Pane establish inherited `m_visibleBounds`, `m_origin.y` then `m_origin.x`, and `m_mode`.
- [UID:00003T]/[UID:0001U4] provide the DialogPane member band but currently invert Y/X and clamp axes relative to target operands.
- [UID:000038] proves `m_controlFlags` is protected storage, so an ordinary ModelessDialogPane method cannot legally read it directly; an accessor is required.
- [UID:0003KN] already owns the exact selection helper but is blank formal source and lacks sufficient behavior detail.
- [UID:00039P] currently records presentation behavior but routes it to Surface despite current IDA's ScreenPane receiver type and caller family.
- IDA names/types for target, selection helper, SavePosition, and refresh helper remain source-incomplete. Section 21 supplies exact bounded actions; the B agent did not mutate them.

## Ranked Ownership Analysis

1. [UID:00008K] ModelessDialogPane: conclusive. Exact vtable slot, constructor store, secondary-view adjustment, inherited member use, and neighboring class methods all agree.
2. [UID:00003T] DialogPane: base owner of fields/helpers but not the override. The class-specific vtable slot rejects direct base ownership.
3. [UID:0000LH] ModelessDialogPane file: strong direct source root. Constructor, IsModal, handler, layout, and class declaration form one compact source unit.
4. EventHandler/EventDispatcher: interface/runtime route only. They do not own the derived definition.
5. Surface/ScreenPane: downstream presentation dependency only. Neither owns target bytes.

The canonical target owner/emitter route remains `00008K`; no split or owner change is justified.

## Source Placement

- Header: `NexusTK/ui/core/ModelessDialogPane.h`, complete class declaration emitted by [UID:00008K].
- Source: `NexusTK/ui/core/ModelessDialogPane.cpp`, includes and `[[CHILDREN]]` emitted by [UID:00008K]/[UID:0000LH], exact method body emitted by [UID:000312].
- Declaration order follows current physical/source order: constructor, `IsModal`, then `HandlePointerOrMouseEvent` is acceptable even if vtable declaration order differs; virtual slot order is inherited from EventHandler/DialogPane.
- DialogPane helper declarations remain in `DialogPane.h`; helper definitions remain DialogPane.cpp children.
- ScreenPane presentation declaration/definition belongs to ScreenPane.h/ScreenPane.cpp. Surface remains a callee/dependency family.
- Compiler-generated vtables, RTTI, switch table, adjustor thunks, security cookie, and alignment have no handwritten source bodies.

## Range / Split / Padding / Reclassification Analysis

- Target boundaries are exact and need no split.
- The switch table is outside the target interval and should remain compiler-generated coverage evidence.
- The two-byte `66 90` at `0x4a0c8e` and surrounding `0xcc` runs are alignment, not hidden source.
- Parent aggregate [UID:00012Z] remains non-reconstructable/non-emitting because its exact children own all source; its prose should point to the dedicated analysis.
- [UID:0003KN] is already an exact helper child and needs source population, not another split.
- `0x49fa60` and `0x49fe20` currently exist only inside broad DialogPane aggregate coverage. Dedicated exact child pages are recommended during accepted implementation so each body can eventually emit independently without forcing the aggregate to over-emit.
- UID00039P is an exact existing child and needs owner/source rerouting, not a range change.

## Negative Evidence Summary

- No direct code caller reaches target start. This is consistent with a vtable-only virtual and does not support “dead” or “raw helper” classification.
- No original PDB/source symbol proves final local/member spelling. Project-wide interface names and full behavior provide high-probability source names.
- No current standalone page isolates `0x49fa60` or `0x49fe20`; this is a documentation split deficiency, not unresolved behavior.
- `m_controlFlags` has no out-of-line accessor xref because the proposed source accessor is inline. Constructor values and target use are the positive evidence.
- The SavePosition explicit pointer is not read by the current callee. Stack cleanup and caller push still prove it is physically part of the ABI; removing it would mismatch the call.
- No evidence supports initializing the terminal result. The absence of a dominating store is positive evidence for preserving the bug.
- No evidence supports Surface ownership for `0x557140`; that route is historical source-bucket pollution.

## IDA Rename / Type / Comment Recommendations

These are structured supervisor handoffs, not executable transactions. Fresh bounded read-only MCP evidence was taken from the canonical IDB on `2026-08-11`; the ephemeral session name is a dated evidence receipt only. The current MCP schema binds function renames to `rename` using `batch.func` entries with exact `addr` and `name`, `pure:true`, `allow_overwrite:false`, and collision failure. Function types bind to `set_type` using top-level `database` plus one `edits` row containing only exact `addr` and `signature`. Function-regular comments bind to `set_function_comments` using one `items` row containing exact `addr` and `comment`. No local or stack rename endpoint is part of these actions.

For every accepted type action, the supervisor must read the complete frame immediately before mutation and compare every row immediately afterward. Only the literal deltas below are permitted. Any missing, additional, resized, renamed, retyped, or shifted protected row; any range/body/xref/comment-channel drift; or any different prototype rendering is a hard rollback/stop condition. Physical locations are normalized from the live frame base and prologue/epilogue disassembly; `MCP offset` is the literal value returned by `stack_frame`.

### I000312-01 - Target Event Override

Current entity: function `[0x004a0840,0x004a0c8e)`, name `sub_4A0840`, fresh `func_profile` prototype `char __thiscall(int this, int)`. The live frame independently types its sole stack argument as `event : Event *`. All four entry comment channels are absent.

| Row | MCP offset | Physical location | Literal current name / width / type | Exact expected post-type state | Delta or protection |
| --- | --- | --- | --- | --- | --- |
| Return semantic, not a frame row | n/a | `AL` | unnamed return / `0x1` / `char` | unnamed return / `0x1` / `bool` | permitted return-type delta only |
| Register receiver | register | `ECX` | `this` / `0x4` / `int` | `this` / `0x4` / `EventHandler *` | permitted receiver-type delta only; physical secondary view remains unchanged |
| Saved EDI spill | not emitted as a member | `[ebp-0x44]` | `saved EDI` / `0x4` / register spill | identical | protected; derived from `push edi`/`pop edi` |
| Saved ESI spill | not emitted as a member | `[ebp-0x40]` | `saved ESI` / `0x4` / register spill | identical | protected |
| Saved EBX spill | not emitted as a member | `[ebp-0x3c]` | `saved EBX` / `0x4` / register spill | identical | protected |
| Local | `0x0c` | `[ebp-0x38]` | `mouseY` / `0x4` / `int` | identical | protected |
| Local | `0x10` | `[ebp-0x34]` | `mouseX` / `0x4` / `int` | identical | protected |
| Unmodeled frame bytes | no member head | `[ebp-0x30..ebp-0x2e]` | absent / `0x3` / untyped | identical absent range | protected; no new member allowed |
| Local | `0x17` | `[ebp-0x2d]` | `var_2D` / `0x4` / `_DWORD` | identical | protected |
| Local | `0x1b` | `[ebp-0x29]` | `var_29` / `0x1` / `_BYTE` | identical | protected uninitialized result byte |
| Local | `0x1c` | `[ebp-0x28]` | `outControlId` / `0x4` / `int` | identical | protected |
| Local | `0x20` | `[ebp-0x24]` | `var_24` / `0x1` / `_BYTE` | identical | protected literal current member head |
| Unmodeled frame bytes | no member head | `[ebp-0x23..ebp-0x15]` | absent / `0xf` / untyped | identical absent range | protected; no aggregation or new member allowed |
| Local | `0x30` | `[ebp-0x14]` | `bounds` / `0x10` / `MapRect` | identical | protected |
| Local | `0x40` | `[ebp-0x4]` | `var_4` / `0x4` / `_DWORD` | identical | protected security-cookie row |
| Saved frame pointer | `0x44` | `[ebp+0x0]` | `__saved_registers` / `0x4` / `_DWORD` | identical | protected saved EBP row |
| Return address | `0x48` | `[ebp+0x4]` | `__return_address` / `0x4` / `_UNKNOWN *` | identical | protected |
| Explicit argument | `0x4c` | `[ebp+0x8]` | `event` / `0x4` / `Event *` | identical `event` / `0x4` / `Event *` | protected physical row; the stale profile-only `arg1 : int` display is reconciled to this existing row |

Accepted action: pure rename to `ModelessDialogPane_HandlePointerOrMouseEvent`; set exact signature `bool __thiscall ModelessDialogPane_HandlePointerOrMouseEvent(EventHandler *this, Event *event)`; set function-regular comment to `ModelessDialogPane::HandlePointerOrMouseEvent secondary EventHandler entry (complete object = this - 0xA0); handles title drag/clamp, control hit/press/dispatch/activation, wheel routing, and preserves the original uninitialized return on wheel/right/default paths.` Expected readback is the exact name/signature above, the exact frame table above, unchanged `0x44e` range/body/xrefs, address regular absent, address repeatable absent, the exact new function-regular comment, and function repeatable absent.

### I000312-02 - Selection Visual State Helper

Current entity: function `[0x0049de00,0x0049de67)`, name `sub_49DE00`, prototype `void __thiscall(int this, int, int)`, epilogue `retn 8`; all four entry comment channels are absent.

| Row | MCP offset | Physical location | Literal current name / width / type | Exact expected post-type state | Delta or protection |
| --- | --- | --- | --- | --- | --- |
| Return semantic, not a frame row | n/a | no stack storage | `void` | `void` | protected |
| Register receiver | register | `ECX` | `this` / `0x4` / `int` | `this` / `0x4` / `DialogPane *` | permitted receiver-type delta only |
| Saved EDI spill | not emitted as a member | `[ebp-0x0c]` | `saved EDI` / `0x4` / register spill | identical | protected |
| Saved ESI spill | not emitted as a member | `[ebp-0x08]` | `saved ESI` / `0x4` / register spill | identical | protected |
| Saved EBX spill | not emitted as a member | `[ebp-0x04]` | `saved EBX` / `0x4` / register spill | identical | protected |
| Saved frame pointer | `0x0c` | `[ebp+0x0]` | `__saved_registers` / `0x4` / `_DWORD` | identical | protected saved EBP row |
| Return address | `0x10` | `[ebp+0x4]` | `__return_address` / `0x4` / `_UNKNOWN *` | identical | protected |
| Explicit argument slot 0 | `0x14` | `[ebp+0x8..ebp+0x0b]` | `arg_0` / `0x4` / `_DWORD` | `controlId` / `0x4` / `int` | permitted name/type delta; four-byte slot unchanged |
| Explicit argument slot 1 | `0x18` | `[ebp+0x0c..ebp+0x0f]` | `arg_4` / `0x4` / `_DWORD` | member head `visualState` / semantic width `0x1` / `unsigned __int8`; physical ABI slot remains `0x4` | permitted name/type/member-width delta only; `retn 8` and the four-byte slot are protected |
| Upper bytes of slot 1 | part of physical slot at `0x18` | `[ebp+0x0d..ebp+0x0f]` | no separate member / `0x3` ABI padding | no separate member / `0x3` ABI padding | protected; no extra argument/member may appear |

Accepted action: pure rename to `DialogPane_SetSelectionVisualState`; set exact IDA signature `void __thiscall DialogPane_SetSelectionVisualState(DialogPane *this, int controlId, unsigned __int8 visualState)`; set function-regular comment to `Resets the previous selected child to visual state 10 when needed, stores the new selected control/state, and applies the new state to a valid child.` Source-facing formal C++ may continue to spell the equivalent type `unsigned char`. Expected readback is the exact name/signature and frame contract above, unchanged `0x67` range/body/xrefs and `retn 8`, address regular absent, address repeatable absent, the exact new function-regular comment, and function repeatable absent.

### I000312-03 - Save Position ABI Mismatch

Current entity: function `[0x0049fa60,0x0049fb0e)`, name `DialogPane_SavePosition`, prototype `void __thiscall(DialogPane *this)`. All three physical exits use `retn 4`, and callers push one four-byte bounds pointer, but fresh MCP exposes no argument member after the return-address row. Because the current `set_type` schema does not itself guarantee deterministic creation of that missing frame member, this report removes the prior type mutation. The source-facing documentation remains `SavePosition(const RectBounds *unusedBounds)` from machine ABI evidence; IDA remains conservatively no-argument until a dedicated frame-shaping endpoint can prove the exact member addition.

| Row | MCP offset | Physical location | Literal current name / width / type | Exact expected post-action state | Delta or protection |
| --- | --- | --- | --- | --- | --- |
| Return semantic, not a frame row | n/a | no stack storage | `void` | `void` | protected; no `set_type` action |
| Register receiver | register | `ECX` | `this` / `0x4` / `DialogPane *` | identical | protected |
| Saved ESI spill | not emitted as a member | `[ebp-0x18]` | `saved ESI` / `0x4` / register spill | identical | protected |
| Local | `0x04` | `[ebp-0x14]` | `var_14` / `0x4` / `_DWORD` | identical | protected |
| Local | `0x08` | `[ebp-0x10]` | `var_10` / `0x4` / `_DWORD` | identical | protected |
| Local | `0x0c` | `[ebp-0x0c]` | `var_C` / `0x4` / `_DWORD` | identical | protected |
| Local | `0x10` | `[ebp-0x08]` | `var_8` / `0x4` / `_DWORD` | identical | protected |
| Local | `0x14` | `[ebp-0x04]` | `var_4` / `0x4` / `_DWORD` | identical | protected security-cookie row |
| Saved frame pointer | `0x18` | `[ebp+0x0]` | `__saved_registers` / `0x4` / `_DWORD` | identical | protected saved EBP row |
| Return address | `0x1c` | `[ebp+0x4]` | `__return_address` / `0x4` / `_UNKNOWN *` | identical | protected |
| Physical caller-pushed slot | no current MCP member; expected offset would be `0x20` | `[ebp+0x8..ebp+0x0b]` | absent member / physical width `0x4` / caller evidence indicates `const RectBounds *` | remain absent from IDA frame | protected absence; `retn 4` and caller push are documented, not force-shaped |

Accepted action: keep name, type, and complete frame unchanged; do not call `set_type`. Set only the function-regular comment to `Persists configured dialog position from current screen bounds; callers supply one RectBounds pointer and all exits use retn 4, but the current IDA frame has no explicit argument member and this build does not read the value.` Expected readback is unchanged name `DialogPane_SavePosition`, unchanged prototype `void __thiscall(DialogPane *this)`, exact frame above, exact `retn 4` exits/range/body/xrefs, address regular absent, address repeatable absent, the exact new function-regular comment, and function repeatable absent.

### I000312-04 - Action Button Refresh Helper

Current entity: function `[0x0049fe20,0x0049feae)`, name `sub_49FE20`, prototype `int __thiscall(_DWORD *this)`, no explicit stack argument, plain `retn`; all four entry comment channels are absent.

| Row | MCP offset | Physical location | Literal current name / width / type | Exact expected post-type state | Delta or protection |
| --- | --- | --- | --- | --- | --- |
| Return semantic, not a frame row | n/a | `EAX` currently displayed | `int` / `0x4` | `void` / no return storage contract | permitted return-type delta only; instructions remain unchanged |
| Register receiver | register | `ECX` | `this` / `0x4` / `_DWORD *` | `this` / `0x4` / `DialogPane *` | permitted receiver-type delta only |
| Conditional saved EDI spill | not emitted as a member | `[ebp-0x20]` | `saved EDI` / `0x4` / register spill | identical | protected on the long branch |
| Conditional saved EBX spill | not emitted as a member | `[ebp-0x1c]` | `saved EBX` / `0x4` / register spill | identical | protected on the long branch |
| Saved ESI spill | not emitted as a member | `[ebp-0x18]` | `saved ESI` / `0x4` / register spill | identical | protected on all exits |
| Local | `0x04` | `[ebp-0x14]` | `var_14` / `0x10` / `int[4]` | identical | protected |
| Local | `0x14` | `[ebp-0x04]` | `var_4` / `0x4` / `_DWORD` | identical | protected security-cookie row |
| Saved frame pointer | `0x18` | `[ebp+0x0]` | `__saved_registers` / `0x4` / `_DWORD` | identical | protected saved EBP row |
| Return address | `0x1c` | `[ebp+0x4]` | `__return_address` / `0x4` / `_UNKNOWN *` | identical | protected |
| Explicit stack arguments | none | none; epilogue is plain `retn` | no rows | no rows | protected; no argument may be added |

Accepted action: pure rename to `DialogPane_RefreshActionButtonState`; set exact signature `void __thiscall DialogPane_RefreshActionButtonState(DialogPane *this)`; set function-regular comment to `Calls UpdateActionButton and invalidates the focused control's expanded bounds only when that control's enabled state changes.` Expected readback is the exact name/signature and frame above, unchanged `0x8e` range/body/xrefs/plain `retn`, address regular absent, address repeatable absent, the exact new function-regular comment, and function repeatable absent. No focus-state rename is claimed.

### I000312-05 - ScreenPane Presentation No-Change Protection

Fresh no-change entity: function `[0x00557140,0x00557377)`, name `ScreenPane_RenderPresentation`, prototype `void __thiscall(ScreenPane *this)`, address regular absent, address repeatable absent, function regular `Source-facing ScreenPane presentation pass used by StartPresentation.`, function repeatable absent.

| Row | MCP offset | Physical location | Literal current and required post-batch name / width / type | Protection |
| --- | --- | --- | --- | --- |
| Return semantic, not a frame row | n/a | no stack storage | `void` | no change |
| Register receiver | register | `ECX` | `this` / `0x4` / `ScreenPane *` | no change |
| Saved EDI spill | not emitted as a member | `[ebp-0x6c]` | `saved EDI` / `0x4` / register spill | no change |
| Saved ESI spill | not emitted as a member | `[ebp-0x68]` | `saved ESI` / `0x4` / register spill | no change |
| Saved EBX spill | not emitted as a member | `[ebp-0x64]` | `saved EBX` / `0x4` / register spill | no change |
| Local | `0x10` | `[ebp-0x60]` | `var_60` / `0x4` / `_DWORD` | no change |
| Local | `0x14` | `[ebp-0x5c]` | `var_5C` / `0x4` / `ScreenPane *` | no change |
| Local | `0x18` | `[ebp-0x58]` | `var_58` / `0x4` / `_DWORD` | no change |
| Local | `0x1c` | `[ebp-0x54]` | `Rect` / `0x10` / `struct tagRECT` | no change |
| Local | `0x2c` | `[ebp-0x44]` | `var_44` / `0x14` / `Region` | no change |
| Local | `0x40` | `[ebp-0x30]` | `var_30` / `0x4` / `_DWORD` | no change |
| Local | `0x44` | `[ebp-0x2c]` | `var_2C` / `0x4` / `_DWORD` | no change |
| Local | `0x48` | `[ebp-0x28]` | `var_28` / `0x4` / `_DWORD` | no change |
| Local | `0x4c` | `[ebp-0x24]` | `var_24` / `0x4` / `_DWORD` | no change |
| Local | `0x50` | `[ebp-0x20]` | `rc` / `0x10` / `struct tagRECT` | no change |
| Local | `0x60` | `[ebp-0x10]` | `var_10` / `0x4` / `_DWORD` | no change |
| Local | `0x64` | `[ebp-0x0c]` | `var_C` / `0x4` / `_DWORD` | no change |
| Unmodeled SEH frame bytes | no member head | `[ebp-0x08..ebp-0x05]` | absent / `0x4` / untyped handler storage | protected absent range |
| Local | `0x6c` | `[ebp-0x04]` | `var_4` / `0x4` / `_DWORD` | no change |
| Saved frame pointer | `0x70` | `[ebp+0x0]` | `__saved_registers` / `0x4` / `_DWORD` | no change |
| Return address | `0x74` | `[ebp+0x4]` | `__return_address` / `0x4` / `_UNKNOWN *` | no change |
| Unmodeled caller-stack bytes | no member head | `[ebp+0x08..ebp+0x0b]` | absent / `0x4` / untyped | protected absent range |
| Existing frame tail | `0x7c` | `[ebp+0x0c]` | `arg_4` / `0x4` / `_DWORD` | no change; no source-argument claim is introduced |

Accepted action: no rename, type, frame, or comment mutation. After the accepted batch, freshly read back the exact name, prototype, `0x237` range, complete frame above, body/xrefs, and all four comment channels. Any difference is a hard stop before save.

## First-Draft C++ Recommendation

The following is exact formal target CPP insertion text for [UID:000312]. It is source-shaped C++03-era code, not a report-executable package. Target formal H remains blank.

```text
bool ModelessDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;
    int controlId;
    signed char hitType;
    bool handled;

    switch (event->m_type)
    {
    case kEventCursorMove:
        if (m_isTitleDragActive)
        {
            m_origin.x = m_origin.x - m_dragOriginX + mouseX;
            m_origin.y = m_origin.y - m_dragOriginY + mouseY;

            if (m_clampDragToBounds)
            {
                if (m_origin.y + m_visibleBounds.bottom > m_dragClampMaxY)
                    m_origin.y = m_dragClampMaxY - m_visibleBounds.bottom;
                if (m_origin.y < m_dragClampMinY)
                    m_origin.y = m_dragClampMinY;
                if (m_origin.x + m_visibleBounds.right > m_dragClampMaxX)
                    m_origin.x = m_dragClampMaxX - m_visibleBounds.right;
                if (m_origin.x < m_dragClampMinX)
                    m_origin.x = m_dragClampMinX;
            }
            return true;
        }

        hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (!m_pressedControlActive)
            return false;

        if (controlId == m_pressedControlId && hitType == m_pressedHitType)
            SetSelectionVisualState(controlId, hitType);
        else
            SetSelectionVisualState(-1, 10);

        DispatchInputToControl(event, m_pressedControlId);
        return true;

    case kEventLeftButtonDown:
        hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (hitType == 10)
        {
            if (m_isTitleDragActive)
                return true;
            if (!PointInRect(mouseY, mouseX, &m_visibleBounds))
                return false;

            m_dragOriginX = mouseX;
            m_isTitleDragActive = true;
            m_dragOriginY = mouseY;
            m_savedPaneMode = m_mode;

            if (m_savedPaneMode == 2)
                SetMode(0);
            else if (m_savedPaneMode == 3)
                SetMode(1);
            return true;
        }

        if (m_pressedControlActive || hitType < 0)
            return false;

        if (m_activeControlId != controlId)
        {
            ControlPane *control = GetChild<ControlPane>(controlId);
            if (control->IsSelectable())
                SetHoverControl(controlId);
        }

        m_pressedControlActive = true;
        m_pressedControlId = controlId;
        m_pressedHitType = hitType;
        SetSelectionVisualState(controlId, hitType);
        DispatchInputToControl(event, controlId);
        return true;

    case kEventLeftButtonDoubleClick:
        HitTestControls(mouseY, mouseX, &controlId);
        if (controlId == -1 || !PointInRect(mouseY, mouseX, &m_visibleBounds))
            return false;
        DispatchInputToControl(event, controlId);
        return true;

    case kEventLeftButtonUp:
        handled = false;
        if (m_isTitleDragActive)
        {
            SetMode(m_savedPaneMode);
            if (m_dialogConfigId != 0xffff)
            {
                RectBounds bounds;
                GetScreenBounds(&bounds);
                SavePosition(&bounds);
            }
            m_isTitleDragActive = false;
            handled = true;
        }

        if (!m_pressedControlActive)
            return handled;

        m_pressedControlActive = false;
        SetSelectionVisualState(-1, 10);
        DispatchInputToControl(event, m_pressedControlId);
        g_pScreenPane->RenderPresentation();

        hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (controlId == m_pressedControlId && hitType == m_pressedHitType)
        {
            OnControlCommand(controlId, hitType);
            RefreshActionButtonState();
        }
        return true;

    case kEventMouseWheel:
        if (PointInRect(mouseY, mouseX, &m_visibleBounds))
        {
            HitTestControls(mouseY, mouseX, &controlId);
            DispatchInputToControl(event, controlId);
        }
        break;

    default:
        break;
    }

    return handled;
}
```

The uninitialized `handled` local is intentional binary-parity behavior. Do not “fix” it during implementation without new executable evidence that the original compiler supplied a value elsewhere.

Exact proposed [UID:00008K] formal CPP insertion text:

```text
#include "ModelessDialogPane.h"
#include "ControlPane.h"
#include "Event.h"
#include "ScreenPane.h"

[[CHILDREN]]
```

Exact proposed [UID:00008K] formal H insertion text:

```text
#ifndef NEXUSTK_UI_CORE_MODELESSDIALOGPANE_H
#define NEXUSTK_UI_CORE_MODELESSDIALOGPANE_H

#include "DialogPane.h"

class Event;

class ModelessDialogPane : public DialogPane
{
public:
    ModelessDialogPane(const wchar_t *titleText);
    virtual bool IsModal();
    virtual bool HandlePointerOrMouseEvent(Event *event);
};

#endif
```

Exact proposed [UID:0003KN] formal CPP insertion text:

```text
void DialogPane::SetSelectionVisualState(int controlId, unsigned char visualState)
{
    if (m_selectedControlId != -1 &&
        m_selectedControlId != controlId &&
        m_selectionVisualState != 10)
    {
        GetChild<ControlPane>(m_selectedControlId)->SetVisualState(10);
    }

    m_selectedControlId = controlId;
    m_selectionVisualState = visualState;

    if (controlId != -1)
        GetChild<ControlPane>(controlId)->SetVisualState(visualState);
}
```

Required declaration/support deltas are `void SavePosition(const RectBounds *unusedBounds);`, `void RefreshActionButtonState();`, and public inline `bool ControlPane::IsSelectable() const { return m_controlFlags != 0; }`. `ControlPane::SetVisualState(unsigned char)` must also be public (or DialogPane would require explicit friendship); the ordinary public virtual is the narrower and more probable source shape because unrelated DialogPane code invokes it through `ControlPane *`. The SavePosition and refresh helper bodies should receive dedicated exact child pages rather than being over-emitted by an aggregate.

## Final Recommendation

- The accepted bounded implementation callback is complete for all 72 B002-owned ordinary claims: C000312-001 through C000312-062 and C000312-070 through C000312-079.
- The target and all 15 authorized support destinations now carry the accepted no-loss research, formal CPP/H placement, corrected fields/helpers/source routes, metadata, and explicit superseded history.
- Keep target owner/emitter unchanged at [UID:00008K]/[UID:00008K]; the target is now a populated emitter at `94/94`.
- Primary-supervisor claims C000312-063 through C000312-069 and C000312-080 through C000312-090 remain pending for coherent generated readback, manual coverage, structured IDA work, Gate 2, and lifecycle handling.
- The Primary supervisor must independently verify the ordinary destinations and exact receipts below before applying those remaining claims or executing/archiving the report.

## Recommended Target Doc Changes

- Replace current short behavior summary with a complete branch-by-branch contract including all return paths and ordering.
- Add exact bytes/hash/CFG/frame/xref/vtable/switch-boundary sections.
- Correct source signature, physical-secondary ABI explanation, field table, helper table, and rejected alternatives.
- Insert the exact formal CPP body from Section 22; keep formal H empty.
- Preserve the historical B015/current-old assumptions in a superseded section with reasons: wrong Event naming, reversed axes, stale helpers, default false, and missing code.
- Raise metadata to `COMPLETION:94`, `CONFIDENCE:94`; preserve owner/emitter/reconstructable state.

## Recommended Support Doc Changes

- [UID:00008K] class: move declaration to H, update canonical method/helper/fields, add complete behavior and source route, preserve vtable/no-tail evidence.
- [UID:0000LH] file: update method inventory and generated CPP/H routing; name ScreenPane dependency correctly.
- [UID:00012Z] aggregate: retain non-emitting exact-child index and link this dedicated report outcome.
- [UID:0001V9]/[UID:0001U4]: correct axes and clamp ordering everywhere, including declaration mirrors and historical reconciliation.
- [UID:0001Y6]/[UID:00036P]: update virtual slot name only; keep compiler-generated/no-formal-body disposition.
- [UID:00003T]: correct formal fields, SavePosition parameter, and RefreshActionButtonState declaration; preserve complete class structure.
- [UID:000038]: add the narrow legal inline IsSelectable accessor, move SetVisualState to the public interface so DialogPane calls are legal, and retain the state band as protected storage.
- [UID:0003KN]: add exact source body and helper behavior.
- [UID:00012R]: document both remaining helper bodies and prepare exact child-page splits for `0x49fa60-0x49fb0e` and `0x49fe20-0x49feae`.
- [UID:0000CB]/[UID:0000NB]/[UID:00039P]/[UID:0000OC]: reroute RenderPresentation to ScreenPane and make its declaration externally callable; preserve Surface as implementation dependency/history.

## Score And Metadata Recommendation

| UID | Current | Recommended | Owner/emitter | Rationale |
| --- | --- | --- | --- | --- |
| 000312 target | 94/94 | keep 94/94 | keep 00008K/00008K | implemented exact body, ABI, helpers, fields, formal CPP; historical pre-callback score 88/90 |
| 00008K class | 93/94 | keep 93/94 | keep 0000LH/0000LH | implemented legal H and corrected interface/layout/behavior; historical 89/88 |
| 0000LH file | 92/92 | keep 92/92 | keep FILE | implemented source route and generated contract; historical 89/85 |
| 00012Z aggregate | 86/90 | keep 86/90 | keep NONE/blank | non-emitting child index remains correct |
| 0001V9 layout | 93/95 | keep 93/95 | keep 00008K/00008K | implemented exact secondary translation and corrected axes; historical 88/91 |
| 0001U4 layout | 94/97 | keep 94/97 | keep 00003T/00003T | implemented exact corrected field ordering; historical 92/95 |
| 0001Y6 vtable | 91/95 | keep 91/95 | keep 00008K/00008K | implemented canonical slot name and source route; historical 87/92 |
| 00036P vtable data | 91/95 | keep 91/95 | keep 0001Y6/0001Y6 | implemented exact slot naming with compiler-generated disposition unchanged; historical 87/92 |
| 0003KN helper | 92/95 | keep 92/95 | keep 00003T/00003T | implemented complete source body and semantics; historical 87/90 |
| 00003T DialogPane | 93/96 | keep 93/96 | keep 0000IT/0000IT | exact declaration corrections without broad score churn |
| 000038 ControlPane | 91/93 | keep 91/93 | keep 0000IG/0000IG | bounded legal-access corrections without broad score churn |
| 00039P presentation | 90/93 | keep 90/93 | keep 0000CB/0000CB | ScreenPane owner/source role implemented; historical 86/88 under 0000OC |
| 0000CB/0000NB | 93/94 | keep 93/94 | keep current | implemented route/declaration correction only |
| 0000OC Surface file | 90/89 | keep 90/89 | keep FILE | removed polluted UID00039P child route without changing Surface recovery |

The target is capped below 95 because original lexical spellings are inferred and no final compile/binary comparison has yet proven codegen parity. It is not lower because all binary behavior, source ownership, boundaries, fields, helper semantics, and formal method shape are resolved.

## Open Questions With Attempted Resolution

- Original local/member spellings: no symbols survive. Resolved to project-canonical or highest-probability human names; no raw identifier remains in formal code.
- `m_controlFlags` semantic name: callers/constructors prove an interaction eligibility flag. `IsSelectable` is the best current human spelling and is marked inferred; investigation found no stronger original symbol.
- SavePosition pointer purpose: caller pushes current bounds, callee ignores the pointer and recomputes them. Physical signature is resolved; why this build leaves the argument unused is likely source evolution or optimizer-visible legacy contract.
- Uninitialized return: CFG and stack reads conclusively establish it. It is retained rather than hidden as an open bug.
- `0x557140` source owner: receiver and caller evidence resolve ScreenPane. Full source body is outside this target and remains a dedicated UID00039P quality pass, not a blocker to calling it correctly.
- Original file name: current source cluster and generated root strongly support ModelessDialogPane.cpp/H. No competing owner has equivalent evidence.
- Exact `RefreshActionButtonState` spelling: no symbol survives, but full behavior rejects focus-changing/redraw-selected alternatives. Current name is high probability and implementation-ready.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

After ordinary implementation, replace the current UID000312 by-memory row with:

`        - [UID:000312][0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent](by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md) 0x004a0840-0x004a0c8e | virtual method | ModelessDialogPaneHandlePointerOrMouseEvent : reconstructable : 94% : very-strong : Exact ModelessDialogPane EventHandler-secondary override with complete move/down/double/up/wheel behavior, title drag and Y/X clamp order, pressed/selection/activation routing, position persistence, ScreenPane presentation, preserved uninitialized wheel/right/default return behavior, exact formal CPP, and class-owned emitter route.`

Replace the current UID00008K class row with:

`- [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md) : reconstructable : 93% : very-strong : Complete ModelessDialogPane class declaration in H with exact constructor, IsModal, and HandlePointerOrMouseEvent children; three-view vtable/secondary EventHandler route, inherited DialogPane drag/press/selection/clamp state, corrected Y/X field order, exact target CPP, and ModelessDialogPane.cpp source root.`

Replace the current UID0000LH file row with:

`- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/core ModelessDialogPane.cpp/H source root with complete class header, exact constructor/IsModal/pointer-mouse handler children, generated header/source separation, inherited DialogPane support, vtable-derived secondary dispatch, and no handwritten compiler vtable data.`

Replace UID0001V9's by-struct row with:

`- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) : reconstructable : 93% : very-strong : Exact no-tail ModelessDialogPane layout with three object views, EventHandler secondary this at +0xa0, translated inherited DialogPane state, corrected drag-origin Y/X and min-X/min-Y/max-X/max-Y clamp ordering, and complete pointer/mouse-event field consumers.`

Replace UID0001Y6's by-vtable row with:

`- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md) : reconstructable : 91% : very-strong : Exact three-view ModelessDialogPane vtable family with constructor stores, secondary HandlePointerOrMouseEvent and IsModal slots, two-slot tertiary boundary, direct class route, and source-declared/compiler-generated no-handwritten-vtable disposition.`

No agent may edit these coverage rows. The supervisor should refresh or update only after destination metadata and generated output are verified.

## Follow-Up Actions

1. Primary supervisor independently verifies all 72 applied B002 claims against the exact destination hashes and validator receipts below.
2. Primary supervisor performs C000312-063 through C000312-069: one coherent generated refresh and physical CPP/H route/readback checks.
3. Primary supervisor performs C000312-080 through C000312-084: exact manual coverage-row updates and scoped validation.
4. Primary supervisor applies I000312-01 through I000312-04 and protects I000312-05 with backup/save/fresh-copy readback/catalog discipline for C000312-085 through C000312-089.
5. Primary supervisor performs final Gate 2 and alone handles C000312-090 report execution/archive lifecycle.

## Confidence

- Range/boundaries/hash/CFG: very high.
- Class owner, secondary-view ABI, vtable route: very high.
- Event branch behavior and ordering: very high.
- Field offsets and corrected axes: very high.
- Helper behaviors and physical signatures: very high.
- Source-facing helper/member lexical spellings: high.
- ModelessDialogPane.cpp/H source placement: high.
- Exact final compiler parity: medium-high pending actual build comparison, primarily because the original compiler's handling of the intentionally uninitialized result must be reproduced.

## Validator Results

- Every ordinary destination was validated from `source-3/project-documentation` with scoped `python .\tools\validator.py --mode file --file <relative-path> --apply --no-generated-refresh --queue-timeout 240`.
- Every listed command exited `0` with `ok: 1`; generated refresh was skipped. Superseding commands are authoritative where a mirror received a final follow-up correction.

| UID | Destination | Command | Timestamp (-04:00) | Result |
| --- | --- | --- | --- | --- |
| 000312 | `by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md` | `000000021803` | `2026-08-10T16:19:18` | exit 0, ok 1 |
| 00008K | `by-class/ModelessDialogPane.md` | `000000021819` | `2026-08-10T16:23:38` | exit 0, ok 1 |
| 0000LH | `by-file/ModelessDialogPane.md` | `000000021820` | `2026-08-10T16:23:41` | exit 0, ok 1 |
| 00012Z | `by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md` | `000000021806` | `2026-08-10T16:19:25` | exit 0, ok 1 |
| 0001V9 | `by-type/by-struct/ModelessDialogPaneLayout.md` | `000000021821` | `2026-08-10T16:23:43` | exit 0, ok 1 |
| 0001U4 | `by-type/by-struct/DialogPaneLayout.md` | `000000021822` | `2026-08-10T16:23:45` | exit 0, ok 1 |
| 0001Y6 | `by-type/by-vtable/ModelessDialogPaneVtables.md` | `000000021823` | `2026-08-10T16:23:48` | exit 0, ok 1 |
| 00036P | `by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md` | `000000021810` | `2026-08-10T16:19:36` | exit 0, ok 1 |
| 00003T | `by-class/DialogPane.md` | `000000021811` | `2026-08-10T16:19:38` | exit 0, ok 1 |
| 000038 | `by-class/ControlPane.md` | `000000021812` | `2026-08-10T16:19:41` | exit 0, ok 1 |
| 0003KN | `by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md` | `000000021813` | `2026-08-10T16:19:43` | exit 0, ok 1 |
| 00012R | `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` | `000000021814` | `2026-08-10T16:19:45` | exit 0, ok 1 |
| 0000CB | `by-class/ScreenPane.md` | `000000021815` | `2026-08-10T16:19:48` | exit 0, ok 1 |
| 0000NB | `by-file/ScreenPane.md` | `000000021816` | `2026-08-10T16:19:50` | exit 0, ok 1 |
| 00039P | `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md` | `000000021817` | `2026-08-10T16:19:53` | exit 0, ok 1 |
| 0000OC | `by-file/Surface.md` | `000000021818` | `2026-08-10T16:19:55` | exit 0, ok 1 |

- Validator-owned bookkeeping may update its normal registry/projected-stat state even with generated refresh disabled; B002 made no manual validator-state edit and claims no generated refresh.
- `execute_report`, invalidation, lifecycle, archive, manual coverage, manual generated-file edits, and IDA mutation were not run by B002.

## Changed Files

- The accepted callback edited and physically reread these 16 ordinary destinations; hashes are current after their final scoped validators:

| UID | Destination | SHA256 | Bytes | Lines |
| --- | --- | --- | ---: | ---: |
| 000312 | `by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md` | `6FE39CC4C2888ADC6CD4E7E2FDD15424356DBDD9032AD64E4928959EC144082C` | 16181 | 261 |
| 00008K | `by-class/ModelessDialogPane.md` | `C905AC4505E375FE692033E88A1D02E9DF99929CA11DF20C5FCFCD0932EF1496` | 17786 | 180 |
| 0000LH | `by-file/ModelessDialogPane.md` | `9D44CAB41093B7BAAF1EB5E7405AF5582F8AB18B574777E8E32303C04D9AC3DF` | 13428 | 115 |
| 00012Z | `by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md` | `5838CBA00E82CFDA44881A517D216A7BD5C82D64B715378C28AC8F02298B518B` | 17518 | 144 |
| 0001V9 | `by-type/by-struct/ModelessDialogPaneLayout.md` | `736CCA0CCB290BD656652794A3B9B0CABC019F521A926D077E35675E1762E7BC` | 14792 | 131 |
| 0001U4 | `by-type/by-struct/DialogPaneLayout.md` | `AF2C639745D0A23D659FB4AB97B0E40C70368438B47B9896F73DC3EACAA85A8D` | 26351 | 170 |
| 0001Y6 | `by-type/by-vtable/ModelessDialogPaneVtables.md` | `318ED4B68B7668D5ACB5008B9A5E07D6F93ECC47F30DFF7335241D7F95E011CC` | 13092 | 110 |
| 00036P | `by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md` | `2A15DF69043557F643C165848369229717B36DE73962C6ABBE4DA5CFDE62C58F` | 10768 | 102 |
| 00003T | `by-class/DialogPane.md` | `86BF78FF08827147CBB1FD71849670B21E282DAB54E13FFABF25273265C3D64C` | 43121 | 353 |
| 000038 | `by-class/ControlPane.md` | `E35248CBD9B6A3146EB7C8DD75322B5E3671AD8DF3B66C54C37E7168811ADA7A` | 38471 | 292 |
| 0003KN | `by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md` | `8007E8515FCFC42EAE7701F684B67CC99468FCE5E1E822F52F6A8B03CDDCA961` | 4568 | 67 |
| 00012R | `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` | `3A715C6EF4AA87633A77628ADFB311597F6EA46ED14EA09981705F0C13E20EAB` | 37266 | 216 |
| 0000CB | `by-class/ScreenPane.md` | `8C3C848DBF0F2DCDAF1658C5469B65A7EADE90AF9B0D8777EDCC2B7CD67EA8DA` | 63990 | 413 |
| 0000NB | `by-file/ScreenPane.md` | `34F74022A3CB18FF704350A628E7A7A844E75154944EB978056040DE632D45E0` | 57445 | 274 |
| 00039P | `by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md` | `0FE2B78939B6F5E9FCA165F000BBE46DFDE933F025327AEA71C1C54C5783E2EB` | 7557 | 85 |
| 0000OC | `by-file/Surface.md` | `FA6AA41545C590C34D2633DCB3C03DCE6B4145EEEE842786C5F9C04042C89AA7` | 136592 | 587 |

- No report-authorized child page was created because the accepted ledger assigns the `0x49fa60` and `0x49fe20` behavior to [UID:00012R] and recommends later UID-backed splits rather than claiming new child UIDs here.
- No `-coverage-report.md`, generated/tracker/stats Markdown, audit/catalog, goal, IDA database, lifecycle state, or executed archive was manually edited by B002.

## Implementation Tracking Checklist

B002 rows are `applied-verified` after exact destination reread and scoped validation. Primary-supervisor rows remain `proposed`. This table mirrors Section 11 at full-field detail.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Actor | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C000312-001 | 000312 | Record exact range, size, 348 instructions, 53 blocks, complexity 27, boundary bytes, and full-range SHA256. | Very high | live bytes/disasm/CFG | target exact binary contract | incorporate | B002 | applied-verified |
| C000312-002 | 000312 | Record the eight-entry switch table at 0x4a0c90 and exclude alignment/table/successor thunks from the target body. | Very high | disasm/data/neighbor lookup | target range analysis | incorporate | B002 | applied-verified |
| C000312-003 | 000312 | Replace HandleMouseEvent/InputEvent with HandlePointerOrMouseEvent/Event and explain the secondary EventHandler view at complete-object +0xa0. | Very high | vtable/EventHandler/decompile | target behavior and ABI | incorporate | B002 | applied-verified |
| C000312-004 | 000312 | Record the complete physical frame and the intentionally uninitialized result byte. | Very high | frame/disasm/decompile | target frame and parity | incorporate | B002 | applied-verified |
| C000312-005 | 000312 | Document exact event-0 title drag, Y-before-X clamp order, and true return. | Very high | target body | target branch inventory | incorporate | B002 | applied-verified |
| C000312-006 | 000312 | Document exact event-0 non-drag hit-test, pressed visual update/reset, dispatch, and false/true returns. | Very high | target body/helpers | target branch inventory | incorporate | B002 | applied-verified |
| C000312-007 | 000312 | Document exact event-1 title hit, bounds check, Y/X capture, mode save/remap, and repeated-down handling. | Very high | target body/Pane | target branch inventory | incorporate | B002 | applied-verified |
| C000312-008 | 000312 | Document exact event-1 control hit, signed rejection, IsSelectable gate, hover update, press capture, visual state, and dispatch. | High | target body/ControlPane | target branch inventory | incorporate | B002 | applied-verified |
| C000312-009 | 000312 | Document exact event-2 id and bounds guards followed by dispatch. | Very high | target body | target branch inventory | incorporate | B002 | applied-verified |
| C000312-010 | 000312 | Document exact event-3 drag release, mode restore, conditional bounds/save call, drag clear, and handled state. | Very high | target/disasm/SavePosition | target branch inventory | incorporate | B002 | applied-verified |
| C000312-011 | 000312 | Document exact event-3 press release, selection reset, dispatch, presentation, re-hit, command, refresh, and true return. | Very high | target/helpers | target branch inventory | incorporate | B002 | applied-verified |
| C000312-012 | 000312 | Preserve event-7 dispatch-without-id-guard and uninitialized wheel/right/default return behavior. | Very high | target CFG/disasm | target parity warning | incorporate | B002 | applied-verified |
| C000312-013 | 000312 | Correct inherited Y/X and min-X/min-Y/max-X/max-Y field mapping throughout target and support prose/formal declarations. | Very high | translated offsets/instruction operands | target/class/layout docs | incorporate | B002 | applied-verified |
| C000312-014 | 000312 | Replace compiler/helper labels with SetSelectionVisualState, SavePosition(const RectBounds *), RefreshActionButtonState, and ScreenPane::RenderPresentation. | High | complete helper bodies/callers | target helper inventory | incorporate | B002 | applied-verified |
| C000312-015 | 000312 | Populate target formal CPP with the complete exact method body and keep target formal H blank. | High | full parity audit | target formal CPP/H | incorporate | B002 | applied-verified |
| C000312-016 | 00008K | Move complete ModelessDialogPane declaration to class H with canonical Event signature; leave includes plus children in class CPP. | High | channel rules/generated output | class formal CPP/H | incorporate | B002 | applied-verified |
| C000312-017 | 00008K | Reconcile class behavior, helper, field, vtable-slot, and historical assumptions without pruning valid history. | High | target/live support evidence | class narrative | incorporate | B002 | applied-verified |
| C000312-018 | 0000LH | Reconcile file method map, generated header/source route, ScreenPane dependency, and source-placement rationale. | High | target/class/generated | file narrative | incorporate | B002 | applied-verified |
| C000312-019 | 00012Z | Update aggregate prose to point to the dedicated complete target analysis while preserving non-emitting aggregate disposition. | High | split children/ranges | aggregate narrative | incorporate | B002 | applied-verified |
| C000312-020 | 0001V9 | Correct translated inherited field mapping and canonical event method name; preserve no-derived-tail conclusion. | Very high | secondary-view translation | Modeless layout | incorporate | B002 | applied-verified |
| C000312-021 | 0001U4 | Correct +20c/+210 and +22c..+238 names in table, declaration mirrors, and history. | Very high | exact target operands | DialogPane layout | incorporate | B002 | applied-verified |
| C000312-022 | 0001Y6 | Rename secondary slot to HandlePointerOrMouseEvent and preserve three-view/source-generated vtable contract. | Very high | vtable dwords/interface | Modeless vtable | incorporate | B002 | applied-verified |
| C000312-023 | 00036P | Rename slot prose to HandlePointerOrMouseEvent and preserve blank generated-binary formal channels. | Very high | vtable child data | vtable-data page | incorporate | B002 | applied-verified |
| C000312-024 | 00003T | Correct DialogPane formal field order, SavePosition signature, RefreshActionButtonState declaration, and supporting behavior. | High | target/helper bodies | DialogPane class | incorporate | B002 | applied-verified |
| C000312-025 | 000038 | Add public inline IsSelectable() const returning m_controlFlags != 0, and make SetVisualState publicly callable so DialogPane source is legal; document both without exposing storage. | High | constructors/target/helper calls | ControlPane class | incorporate | B002 | applied-verified |
| C000312-026 | 0003KN | Populate exact SetSelectionVisualState CPP, keep H blank, and add complete side-effect evidence. | Very high | full helper body/callers | selection helper | incorporate | B002 | applied-verified |
| C000312-027 | 00012R | Add exact 0x49fa60 and 0x49fe20 behavior, ABI, inferred names, and recommendation for dedicated child splits. | High | helper bodies/xrefs/frame | DialogPane aggregate | incorporate | B002 | applied-verified |
| C000312-028 | 0000CB | Make RenderPresentation public and record its broad external caller/ScreenPane ownership evidence without changing its body here. | High | receiver/callers/fields | ScreenPane class | incorporate | B002 | applied-verified |
| C000312-029 | 0000NB | Add UID00039P to ScreenPane source-root inventory and remove the stale Surface route. | High | receiver/source family | ScreenPane file | incorporate | B002 | applied-verified |
| C000312-030 | 00039P | Rename page/title/source role to ScreenPaneRenderPresentation, reroute owner/emitter to 0000CB, preserve exact body evidence, and keep formal body pending its dedicated pass. | High | live type/callers/callees | presentation child | incorporate | B002 | applied-verified |
| C000312-031 | 0000OC | Remove UID00039P as a Surface-owned child while retaining Surface dependencies and historical route as superseded. | High | ownership analysis | Surface file | incorporate | B002 | applied-verified |
| C000312-032 | 000312 | Raise target metadata to 94/94 with owner/emitter unchanged and exact score rationale. | High | completed source-quality analysis | target metadata | incorporate | B002 | applied-verified |
| C000312-033 | 00008K | Set ModelessDialogPane class metadata to 93/94 while preserving owner/emitter 0000LH. | High | resolved class channel/interface defects | by-class/ModelessDialogPane.md metadata | incorporate | B002 | applied-verified |
| C000312-034 | 0000LH | Set ModelessDialogPane file metadata to 92/92 while preserving FILE ownership. | High | complete source/header route | by-file/ModelessDialogPane.md metadata | incorporate | B002 | applied-verified |
| C000312-035 | 00012Z | Preserve aggregate metadata 86/90, owner NONE, blank emitter, and non-reconstructable exact-child index. | Very high | exact split disposition | by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md metadata | already-present | B002 | applied-verified |
| C000312-036 | 0001V9 | Set ModelessDialogPaneLayout metadata to 93/95 with owner/emitter 00008K unchanged. | High | corrected secondary-view layout | by-type/by-struct/ModelessDialogPaneLayout.md metadata | incorporate | B002 | applied-verified |
| C000312-037 | 0001U4 | Set DialogPaneLayout metadata to 94/97 with owner/emitter 00003T unchanged. | High | corrected exact field ordering | by-type/by-struct/DialogPaneLayout.md metadata | incorporate | B002 | applied-verified |
| C000312-038 | 0001Y6 | Set ModelessDialogPaneVtables metadata to 91/95 with owner/emitter 00008K unchanged. | High | exact slot naming/source contract | by-type/by-vtable/ModelessDialogPaneVtables.md metadata | incorporate | B002 | applied-verified |
| C000312-039 | 00036P | Set ModelessDialogPaneVtableData metadata to 91/95 with owner/emitter 0001Y6 unchanged. | High | exact slot naming/compiler disposition | by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md metadata | incorporate | B002 | applied-verified |
| C000312-040 | 0003KN | Set DialogPaneSetSelectionVisualState metadata to 92/95 with owner/emitter 00003T unchanged. | High | complete helper source/semantics | by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md metadata | incorporate | B002 | applied-verified |
| C000312-041 | 00003T | Preserve DialogPane class metadata 93/96 and owner/emitter 0000IT after exact declaration corrections. | Very high | mature class plus bounded corrections | by-class/DialogPane.md metadata | already-present | B002 | applied-verified |
| C000312-042 | 000038 | Preserve ControlPane class metadata 91/93 and owner/emitter 0000IG after bounded access corrections. | High | inferred accessor/public-call legality | by-class/ControlPane.md metadata | already-present | B002 | applied-verified |
| C000312-043 | 00039P | Set presentation child metadata to 90/93 and reroute owner/emitter from 0000OC to 0000CB. | High | ScreenPane receiver/caller/source proof | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md metadata | incorporate | B002 | applied-verified |
| C000312-044 | 0000CB | Preserve ScreenPane class metadata 93/94 and owner/emitter 0000NB after public declaration/routing correction. | Very high | existing mature ScreenPane evidence | by-class/ScreenPane.md metadata | already-present | B002 | applied-verified |
| C000312-045 | 0000NB | Preserve ScreenPane file metadata 93/94 and FILE ownership after adding UID00039P route. | Very high | existing mature source root | by-file/ScreenPane.md metadata | already-present | B002 | applied-verified |
| C000312-046 | 0000OC | Preserve Surface file metadata 90/89 and FILE ownership after removing polluted UID00039P ownership. | High | Surface remains dependency/source family | by-file/Surface.md metadata | already-present | B002 | applied-verified |
| C000312-047 | 000312 | Run scoped no-generated-refresh validation for the edited target page and record command/timestamp/exit/ok receipt. | High | validator contract | by-memory/0x004a0840-0x004a0c8e.ModelessDialogPaneHandleMouseEvent.md validation | incorporate | B002 | applied-verified |
| C000312-048 | 00008K | Run scoped no-generated-refresh validation for the edited ModelessDialogPane class page and record receipt. | High | validator contract | by-class/ModelessDialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-049 | 0000LH | Run scoped no-generated-refresh validation for the edited ModelessDialogPane file page and record receipt. | High | validator contract | by-file/ModelessDialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-050 | 00012Z | Run scoped no-generated-refresh validation for the edited ModelessDialogPane aggregate page and record receipt. | High | validator contract | by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-051 | 0001V9 | Run scoped no-generated-refresh validation for the edited ModelessDialogPaneLayout page and record receipt. | High | validator contract | by-type/by-struct/ModelessDialogPaneLayout.md validation | incorporate | B002 | applied-verified |
| C000312-052 | 0001U4 | Run scoped no-generated-refresh validation for the edited DialogPaneLayout page and record receipt. | High | validator contract | by-type/by-struct/DialogPaneLayout.md validation | incorporate | B002 | applied-verified |
| C000312-053 | 0001Y6 | Run scoped no-generated-refresh validation for the edited ModelessDialogPaneVtables page and record receipt. | High | validator contract | by-type/by-vtable/ModelessDialogPaneVtables.md validation | incorporate | B002 | applied-verified |
| C000312-054 | 00036P | Run scoped no-generated-refresh validation for the edited ModelessDialogPaneVtableData page and record receipt. | High | validator contract | by-memory/0x00618c44-0x00618ce0.ModelessDialogPaneVtableData.md validation | incorporate | B002 | applied-verified |
| C000312-055 | 00003T | Run scoped no-generated-refresh validation for the edited DialogPane class page and record receipt. | High | validator contract | by-class/DialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-056 | 000038 | Run scoped no-generated-refresh validation for the edited ControlPane class page and record receipt. | High | validator contract | by-class/ControlPane.md validation | incorporate | B002 | applied-verified |
| C000312-057 | 0003KN | Run scoped no-generated-refresh validation for the edited selection-helper page and record receipt. | High | validator contract | by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md validation | incorporate | B002 | applied-verified |
| C000312-058 | 00012R | Run scoped no-generated-refresh validation for the edited DialogPane aggregate page and record receipt. | High | validator contract | by-memory/0x0049d8a0-0x0049feae.DialogPane.md validation | incorporate | B002 | applied-verified |
| C000312-059 | 0000CB | Run scoped no-generated-refresh validation for the edited ScreenPane class page and record receipt. | High | validator contract | by-class/ScreenPane.md validation | incorporate | B002 | applied-verified |
| C000312-060 | 0000NB | Run scoped no-generated-refresh validation for the edited ScreenPane file page and record receipt. | High | validator contract | by-file/ScreenPane.md validation | incorporate | B002 | applied-verified |
| C000312-061 | 00039P | Run scoped no-generated-refresh validation for the edited presentation child page and record receipt. | High | validator contract | by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md validation | incorporate | B002 | applied-verified |
| C000312-062 | 0000OC | Run scoped no-generated-refresh validation for the edited Surface file page and record receipt. | High | validator contract | by-file/Surface.md validation | incorporate | B002 | applied-verified |
| C000312-063 | 0000LH | Run one supervisor-owned coherent generated refresh and verify current ModelessDialogPane.cpp/H command metadata and source-root routing. | High | validator-generated source contract | auto-generated/NexusTK/ui/core/ModelessDialogPane.cpp and .h | incorporate | Primary supervisor | proposed |
| C000312-064 | 00008K | Verify the generated ModelessDialogPane class declaration occurs exactly once in ModelessDialogPane.h and not in the CPP body. | High | class formal channel contract | generated ModelessDialogPane.h/CPP class readback | incorporate | Primary supervisor | proposed |
| C000312-065 | 000312 | Verify the generated HandlePointerOrMouseEvent definition occurs exactly once in ModelessDialogPane.cpp with no Empty Emitter Marker. | High | target formal CPP contract | generated ModelessDialogPane.cpp target readback | incorporate | Primary supervisor | proposed |
| C000312-066 | 0000IT | Verify generated DialogPane CPP/H contains one selection-helper body and corrected SavePosition/RefreshActionButtonState declarations. | High | DialogPane formal channel contract | generated DialogPane.cpp/H readback | incorporate | Primary supervisor | proposed |
| C000312-067 | 0000IG | Verify generated ControlPane H exposes IsSelectable and SetVisualState legally once while preserving protected storage. | High | ControlPane formal H contract | generated ControlPane.h readback | incorporate | Primary supervisor | proposed |
| C000312-068 | 0000NB | Verify generated ScreenPane H/CPP owns the public RenderPresentation declaration/route after coherent refresh. | High | ScreenPane owner/emitter contract | generated ScreenPane.cpp/H readback | incorporate | Primary supervisor | proposed |
| C000312-069 | 0000OC | Verify generated Surface CPP/H no longer owns or duplicates UID00039P after coherent refresh. | High | negative owner/emitter contract | generated Surface.cpp/H readback | incorporate | Primary supervisor | proposed |
| C000312-070 | 000312 | Preserve target's superseded HandleMouseEvent/InputEvent, reversed axes, stale helpers, default-false, and blank-emitter assumptions with explicit correction reasons. | High | Rule 26/history/current body | target historical assumptions | historicalize | B002 | applied-verified |
| C000312-071 | 00008K | Preserve class-level B015 assumptions and stale CPP-class/blank-H state as dated history while making current conclusions authoritative. | High | historical report/current class | ModelessDialogPane class history | historicalize | B002 | applied-verified |
| C000312-072 | 0000LH | Preserve stale file method/dependency/header-route assumptions as dated history with current generated-route corrections. | High | historical file/current generated | ModelessDialogPane file history | historicalize | B002 | applied-verified |
| C000312-073 | 00012Z | Preserve aggregate-era shallow handler summary as historical child-index evidence, not current dedicated coverage. | High | split history/current child | ModelessDialogPane aggregate history | historicalize | B002 | applied-verified |
| C000312-074 | 0001V9 | Preserve historical translated-field aliases and explain why current Y/X and clamp-axis mapping supersedes them. | Very high | exact operand translation | ModelessDialogPaneLayout history | historicalize | B002 | applied-verified |
| C000312-075 | 0001U4 | Preserve historical DialogPane field-order aliases and explain exact corrected operand mapping. | Very high | exact target operands | DialogPaneLayout history | historicalize | B002 | applied-verified |
| C000312-076 | 0001Y6 | Preserve historical HandleMouseEvent slot spelling and stale Wave-era metadata only as rejected/superseded history. | High | canonical EventHandler interface | ModelessDialogPaneVtables history | historicalize | B002 | applied-verified |
| C000312-077 | 00036P | Preserve historical HandleMouseEvent/vtable labels while making canonical slot naming current. | High | exact vtable data | ModelessDialogPaneVtableData history | historicalize | B002 | applied-verified |
| C000312-078 | 00039P | Preserve historical SurfaceRenderPresentation ownership/name as superseded routing history with ScreenPane proof. | High | live receiver/callers | presentation child history | historicalize | B002 | applied-verified |
| C000312-079 | 0000OC | Preserve Surface's former UID00039P child route as rejected ownership history while retaining real Surface dependencies. | High | ownership reanalysis | Surface file history | historicalize | B002 | applied-verified |
| C000312-080 | 000312 | Replace the exact UID000312 row in by-memory/-coverage-report.md with the Section 28 94% very-strong text. | High | current row plus accepted recommendation | by-memory/-coverage-report.md UID000312 row | incorporate | Primary supervisor | proposed |
| C000312-081 | 00008K | Replace the exact UID00008K row in by-class/-coverage-report.md with the Section 28 93% very-strong text. | High | current row plus accepted recommendation | by-class/-coverage-report.md UID00008K row | incorporate | Primary supervisor | proposed |
| C000312-082 | 0000LH | Replace the exact UID0000LH row in by-file/-coverage-report.md with the Section 28 92% very-strong text. | High | current row plus accepted recommendation | by-file/-coverage-report.md UID0000LH row | incorporate | Primary supervisor | proposed |
| C000312-083 | 0001V9 | Replace the exact UID0001V9 row in by-type/by-struct/-coverage-report.md with the Section 28 93% very-strong text. | High | current row plus accepted recommendation | by-type/by-struct/-coverage-report.md UID0001V9 row | incorporate | Primary supervisor | proposed |
| C000312-084 | 0001Y6 | Replace the exact UID0001Y6 row in by-type/by-vtable/-coverage-report.md with the Section 28 91% very-strong text. | High | current row plus accepted recommendation | by-type/by-vtable/-coverage-report.md UID0001Y6 row | incorporate | Primary supervisor | proposed |
| C000312-085 | 000312 | Apply I000312-01 only with the exact fresh target profile/frame contract: pure rename, return char-to-bool and ECX int-to-EventHandler-pointer deltas, existing Event-pointer stack row preserved, every local/save/return/gap protected, exact comment and full readback. | High | fresh bounded profile/stack_frame/disasm/comments/set_type schema | IDA function 0x004a0840 | incorporate | Primary supervisor | proposed |
| C000312-086 | 0003KN | Apply I000312-02 only with the exact fresh helper frame contract: pure rename, ECX receiver correction, controlId four-byte row, visualState unsigned-byte semantic member inside an unchanged four-byte ABI slot, protected saves/return/padding, exact comment and full readback. | High | fresh bounded profile/stack_frame/disasm/comments/set_type schema | IDA function 0x0049de00 | incorporate | Primary supervisor | proposed |
| C000312-087 | 00012R | Apply I000312-03 as comment-only: preserve current name, no-argument IDA prototype, complete frame, range/body/xrefs and retn 4; document the caller-pushed bounds pointer without issuing nondeterministic set_type while the frame lacks an explicit argument member. | High | fresh bounded profile/stack_frame/disasm/comments and absent argument row | IDA function 0x0049fa60 | incorporate | Primary supervisor | proposed |
| C000312-088 | 00012R | Apply I000312-04 only with the exact fresh helper frame contract: pure rename, return int-to-void and ECX receiver-type deltas only, no stack arguments, all locals/conditional saves/return protected, exact comment and full readback. | High | fresh bounded profile/stack_frame/disasm/comments/set_type schema | IDA function 0x0049fe20 | incorporate | Primary supervisor | proposed |
| C000312-089 | 00039P | Freshly protect I000312-05 as complete no-change state: exact ScreenPane_RenderPresentation name/type/range, every local/save/return/unmodeled/tail frame row, body/xrefs, and all four comment channels; any post-batch difference stops save. | Very high | fresh bounded profile/stack_frame/disasm/comments | IDA function 0x00557140 | already-present | Primary supervisor | proposed |
| C000312-090 | 000312 | Require fresh Gate 2 ordinary, generated, coverage, and IDA verification before supervisor-only execution or archive. | Very high | lifecycle rules | UID000312 report lifecycle | incorporate | Primary supervisor | proposed |

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000021888","destination_path":"executed-b-agent-research/B002/000312-ModelessDialogPaneHandleMouseEvent-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/000312-ModelessDialogPaneHandleMouseEvent-empty-emitter-source-quality.md","timestamp":"2026-08-11T10:17:49-04:00","uid":"000312"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
