** TARGET-REPORT-UID:0001KN **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001KN UseInventorySlotDispatch Source-Quality Research


## Finalized Report / Current Recommendation

- Completed recommendation: [UID:0001KN] is one source-authored
  `LivingObjectPane::UseInventorySlot(unsigned char slot)` method at `92/93`.
- Final disposition applied: `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`,
  `EMITTER_UIDS:00007B`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0` are retained;
  Destination 1's exact declaration-plus-method block is the target formal C++.
- C01-C30 and Destinations 1-11 were applied during the supervisor-authorized
  implementation callback. Destination 9 changed only UID0001LA linkage from
  file-local to externally shared under the reconstructed two-file split. Destination
  1 emits the exact external declaration immediately before UID0001KN, while
  Destinations 3 and 10 retain the probable final `LivingObjectPane.cpp` include and
  `TargetSelectionInputPanes.h` prototype only as non-emitting source-placement prose.
  The packet body, ABI, owner, position, score, and layout remain intact.
- B002's edits, scoped validators, waited generated verification, and lease releases
  are complete. Any present or future report path, report count, validator acceptance,
  execution, move, or archive state is external validator/supervisor-owned and is not
  asserted by this report.
- Confidence: high for range, bytes, liveness, callers, selector and record semantics,
  all three target-mode outcomes, packet ABI, inlined constructor source operation,
  state/panel interaction, compiler cleanup disposition, method signature, owner, and
  source route. The remaining cap is stripped original spelling, not a behavior or C++
  blocker.

## Supporting Research

- Mandatory live IDA evidence was collected read-only on 2026-07-13 after a fresh
  streamable-MCP initialize, `idb_list`, `server_health`, and bounded target lookup.
  At evidence-collection time the adopted NexusTK database session was `c81909be`;
  health was `ok`, auto-analysis and Hex-Rays were ready, and the string cache was
  ready with 2,067 entries. These are time-scoped observations, not a claim about
  later session availability.
- The evidence IDB was
  `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the input image was
  `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`,
  size 2,679,296 bytes, and SHA256
  `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- The required bounded request resolved `0x005a3e30` as `sub_5A3E30`, size `0x1c3`,
  with no error. Live target bytes are exactly 451 bytes and have SHA256
  `6C3E5BD9820602950C6D560B8B5BE00E284172EBB21425784D06A3E55E67D02F`.
- Live work covered target decompilation/disassembly, prototype, stack frame, bytes,
  boundaries, basic blocks, callees, all incoming xrefs, every modeled caller, the
  raw compact-shortcut caller, pointer-pattern negatives, the out-of-line
  `ItemWhoInputPane` constructor, `SendObjectActionPacket`, and compiler cleanup
  metadata.
- Read-only documentation work covered the target, `LivingObjectPane` class/file and
  local-player split index, `GetInventorySlotAddress`, raw compact-shortcut and
  `ExecuteHotkeyAction` children, all three InventoryPane families, MapPane selected
  object state, GeneralPurposePanel child access, UseInputPane, ItemWho constructor,
  class, state setter, saved-target globals, prompt string, packet helper, active-map,
  UserPane, config, generated LivingObjectPane/TargetSelectionInputPanes output, and
  relevant executed B001/B002/B005/B006/B007/B008/B010/B011/B013/B015 reports.
- Old-report search terms were exactly `UID0001KN`, `UID:0001KN`, `0001KN`,
  `0x005a3e30`, `0x005a3ff3`, `UseInventorySlotDispatch`, `UseInventorySlot`,
  `UseSpellSlot`, `SendObjectActionPacket`, `UID0001LA`, `UID:0001LA`,
  `0x005af580`, `ItemWhoInputPane`, `LivingObjectPane`, `LivingObjectPane.cpp`,
  `UID00007B`, `UID:00007B`, `UID0000KU`, and `UID:0000KU`. Excluding this report,
  the search found no matching active Agent-B report, no legacy
  `research/executed` report, and no report under `archived`; all opened matches were
  central executed reports. The exact paths and individual findings/no-direct-report
  results are recorded under `Evidence Checked`.
- Exact central executed paths opened were
  `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`,
  `B001/0001E1-IntegrateMacroDialog-source-quality.md`,
  `B001/0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md`,
  `B001/0001KM-livingobject-localplayer-source-split-audit.md`,
  `B001/0001MN-0001MP-0001MQ-spellspellinputpane-source-quality.md`,
  `B005/0000KC-ItemActionInputPanes-empty-emitter-family-source-quality.md`,
  `B005/0000OH-TargetSelectionInputPanes-empty-emitter-family-source-quality.md`,
  `B005/0001L8-TargetSelectionInputPanes-source-quality.md`,
  `B006/0001II-SpellInputPaneStateSetFlag-source-quality.md`,
  `B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md`,
  `B007/0000KU-LivingObjectPane-empty-emitter-family-source-quality.md`,
  `B008/0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md`,
  `B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md`,
  `B010/0001ML-ThrowUseEatInputPanes-source-quality.md`,
  `B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md`,
  `B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md`,
  `B013/0001L4-ItemWhoInputPane-source-quality.md`,
  `B013/0002SU-InventoryPane2CoreAndHelpers-source-quality.md`,
  `B013/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md`,
  `B015/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md`,
  `B002/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md`, and
  `B005/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md`;
  every path after the first shares the `executed-b-agent-research/` prefix.
- Source/header-route inspection covered `by-file/TargetSelectionInputPanes.md`,
  `by-file/LivingObjectPane.md`, `by-class/ItemWhoInputPane.md`,
  `by-class/LivingObjectPane.md`, and both generated `.cpp` fragments. The accepted
  target-selection file page already pairs
  `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` with
  `NexusTK/ui/dialogs/TargetSelectionInputPanes.h`; UID0001KN's normal source body
  already needs that header's complete `ItemWhoInputPane` declaration. Therefore the
  highest-probability original-style compile route is one external helper definition,
  one prototype in that existing header, and an include from LivingObjectPane.cpp.
  `by-file/-guidance.md` was also checked: by-file roots are source roots, must not gain
  `RECONSTRUCTABLE`, `EMITTER_UIDS`, or `RECONSTRUCTION_CPP CODE` metadata, and do not
  emit child C++ themselves. Current validator compile visibility must therefore come
  from the declaration placed directly in Destination 1's ordinary child-emitter block;
  the by-file header/include text remains reconstruction-placement prose only.
- During the report-only research pass, no by-* page, generated file, coverage report,
  tracker, supervisor state, validator state, lifecycle state, or IDA database was
  changed, and no lease or validator was used. The later accepted callback changed only
  Destinations 1-11 under short leases, ran their scoped validators and one authorized
  waited generated refresh, and did not run any report execution/lifecycle command or
  manually edit generated/coverage/tracker/supervisor/validator-owned files.

## Target

- Target UID: `0001KN`.
- Target path:
  `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` ->
  `### Not-Covered Files - Reconstructable`, observed as `86/90`, reports `0` when
  assigned. The tracker is read-only and not a destination of this report.
- Assignment history: independent report-only source-quality research followed by the
  supervisor-authorized C01-C30 / Destinations 1-11 implementation callback.
- Applied scores and parent state: target `92/93`; semantic owner/emitter
  [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) at `86/88`; source-file
  ancestor [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) at `89/88`.
  Both parent levels satisfy the attachment gate.

## Current Target State

- Applied metadata is `COMPLETION:92`, `CONFIDENCE:93`,
  `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`, blank
  optional emitter position, and `Nested:0`.
- Owner/emitter routing remains correct. The target is an ordinary thiscall-shaped
  LivingObjectPane local-player method and belongs in the LivingObjectPane source
  family, not in an inventory widget, input pane, MapPane, packet, or compiler module.
- Formal C++ now contains the accepted external declaration followed immediately by
  the one `UseInventorySlot` definition. Waited generated verification found no
  UID0001KN Empty Emitter Marker.
- Former unresolved-name, manual-constructor, seven-modeled-caller, below-gate, and
  unassigned wording is preserved only as labeled historical state. Current target
  text records seven calls in six modeled functions plus one retained raw-body call.
- Packet support retains the cdecl action/object-id ABI, opcode `0x1c`, six sent bytes,
  five call sites, owner UID0000OH, position `21`, and `88/90`. Destination 9 now emits
  the sole non-static definition; Destination 1 supplies the exact generated external
  declaration. Destinations 3 and 10 document probable final header/include placement
  without forbidden by-file formal emission.
- Related docs checked and their destination status are listed under `Recommended
  Support Doc Changes`. MapPane field pages, GeneralPurposePanel accessors,
  `g_activeMapPane`, `g_pUserPane`, saved-target globals, prompt string, ItemWho class,
  and TargetSelection state/global pages are already same-or-greater detail and remain
  read-only verification dependencies.
- B002's research, implementation, validation, generated verification, and lease
  release work is complete. Any present or future validation, execution, report-count,
  path, move, or archive state remains external validator/supervisor-owned and is not
  asserted here.

## Executive Recommendation

- Keep the direct semantic owner and emitter [UID:00007B] `LivingObjectPane`, with
  source-file route [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.
- Use the source-facing method name `UseInventorySlot`, paired with accepted
  `UseCommandSlot`; reject generated `UseSpellSlot`, broad
  `UseInventorySlotDispatch`, packet-helper ownership, and input-pane ownership as
  final source names/placements.
- Use source signature `void LivingObjectPane::UseInventorySlot(unsigned char slot)`.
  The binary uses thiscall receiver, one four-byte-cleaned stack slot whose low byte is
  consumed, and `retn 4`. No caller tests or stores a return; one caller merely allows
  incidental `AL` to reach its own epilogue, while target early exits produce
  incompatible non-Boolean residues.
- Preserve the exact range as one source method. Do not split direct-send branches,
  constructor setup, EH metadata, or alignment into target children.
- The target is `92/93`; all support scores and owner/emitter metadata remain unchanged.
- Destination 1's exact declaration plus body and Destination 9's linkage repair are
  applied. Destinations 3 and 10 contain only non-emitting final-source placement prose. All allocation
  null checks, vtable stores, SEH setup, exception-state writes, allocation cleanup,
  base cleanup, and cookie restoration remain compiler output.

## Supervisor Active Recheck

- Supervisor Gate 1 accepted exact pre-callback report SHA256
  `8FC894611CBBA6D970072733C447F6A4B070CD3D940394DAA4216DE0D9697536`
  and authorized the bounded C01-C30 / Destinations 1-11 callback. The earlier
  report-only restrictions and live-MCP checks remain historical research controls.
- The assigned item does not require split repair or a new child. Its exact existing
  page covers one modeled function and excludes adjacent alignment/raw bodies.
- The only new source-bearing target is UID0001KN. Destinations 1 and 9 are the applied
  validator-emitted compile-visibility correction for an existing support helper;
  Destinations 3 and 10 preserve probable final-source header/include placement as
  prose, not emitters. This is not a duplicate report or new child. Every other
  dependency was either an explicit text-sync destination or proven same-or-greater
  read-only support. No duplicate report, child, or packet body was created.

## Inference Research Guidance Check

- The workflow evidence ladder was applied in order: live bytes/functions first,
  caller/callee and dataflow second, current by-* docs and accepted executed reports
  third, generated source only as an artifact/collision check, and source-shape
  inference last.
- Existing assumptions treated as uncertain included generated `UseSpellSlot`, IDA's
  provisional `char` return, decompiler `Block` parameter/local names, manual
  constructor/vtable setup, the target's old seven-caller wording, `g_pCollectionData`
  aliases, selected-object field spellings, and packet-helper file-local linkage.
- IDA facts, documentation facts, and inference are labeled separately throughout.
  `UseInventorySlot` is a strong project-source inference because accepted formal C++
  in the direct raw caller already calls that exact method name; it is not recovered
  PDB proof.
- Wave2/Wave3 mentions were encountered in broad searches and ignored as stale. No
  Wave artifact, legacy generated owner label, or old queue row was used as primary
  evidence.

## Heuristic / Inference Reanalysis And Validation

### Exact range, bytes, and ABI

- Live lookup fixes the half-open function at `0x005a3e30-0x005a3ff3`, size `0x1c3`.
  The final instruction is `retn 4`; one stack argument is passed in a four-byte slot,
  but the method copies/compares only its low byte.
- The body SHA256 and adjacent bytes independently confirm the range. Eleven `0xcc`
  bytes at `0x005a3e25-0x005a3e30` precede it and thirteen `0xcc` bytes at
  `0x005a3ff3-0x005a4000` follow it. Neither padding run belongs in target source.
- IDA's provisional `char __thiscall(unsigned int *this, void *Block)` is rejected as
  source typing. `this` reaches known LivingObjectPane fields, and the stack argument
  is the one-based slot byte used by every caller.

### Liveness and caller routes

- Live `xref_query` returns exactly eight code xrefs, no pagination remainder: seven
  call sites in six modeled functions and one call in a raw unmodeled retained helper.
- Legacy InventoryPane mouse input, NewInventoryPane mouse input at two sites,
  InventoryPane2 mouse input, MapPane key input, LivingObjectPane macro execution,
  UseInputPane submit, and compact configured shortcut mode zero all route here.
- No absolute-VA or RVA pointer pattern to `0x005a3e30` exists. This negative is
  expected for an ordinary directly-called private/member helper and does not weaken
  the seven live modeled call sites.

### Selector, record, and target modes

- The machine computes `slot - 1` in `AL` and rejects values above `0x33`, exactly the
  unsigned one-based range `1..52`.
- It inlines accepted `GetInventorySlotAddress`: adjusted receiver base `+0x133f08`,
  signed-byte index, stride `0x1fc`, then tests the record pointer and `active` byte
  `+0x00`.
- `targetMode` is the record byte at `+0x1f8`. Value `0` sends immediately to this
  object's inherited `m_objectId` at `+0xfc`. Value `1` sends to MapPane's selected
  living-object id only when `m_selectedObjectActive == 1` and
  `m_selectedObjectPane` is non-null. Failed value-1 selection and every other value
  enter explicit target selection.
- Best source names are accepted project names `LocalInventorySlotRecord`,
  `m_inventorySlots`, `active`, `targetMode`, `m_selectedObjectActive`,
  `m_selectedObjectPane`, and `m_objectId`. Exact original lexical spellings remain a
  confidence cap, not a body blocker.

### Packet helper and linkage

- Both fast paths call the same `int __cdecl` helper at `0x005af580` with argument
  order `(unsigned char action, unsigned int objectId)`; both ignore its integer return.
- The helper writes opcode `0x1c` at packet offset 0, slot/action at 1, object id at
  2..5, scratch zero at 6, and sends exactly 6 bytes. The scratch terminator is not on
  the wire.
- Existing owner [UID:0000OH] and emitter position `21` remain correct. Under the
  current reconstructed source split, however, file-local `static` cannot serve both
  ItemWho methods in TargetSelectionInputPanes.cpp and UID0001KN in
  LivingObjectPane.cpp. The least-invasive compile-coherent repair is external linkage
  for the one existing helper; moving UID0001KN, duplicating or inlining the packet
  body, or creating a second helper would contradict stronger owner/range evidence.
- `by-file/TargetSelectionInputPanes.md` already defines the source-tree pair
  `ui/dialogs/TargetSelectionInputPanes.cpp` and
  `ui/dialogs/TargetSelectionInputPanes.h`; [UID:00006X] `ItemWhoInputPane` already
  routes through that module. Because UID0001KN source constructs `ItemWhoInputPane`,
  `LivingObjectPane.cpp` already needs the target-selection header for the complete
  class declaration. The probable final source is therefore the exact header prototype
  `int SendObjectActionPacket(unsigned char action, unsigned int objectId);` plus
  `#include "../ui/dialogs/TargetSelectionInputPanes.h"` in LivingObjectPane.cpp.
  Current validator output does not materialize by-file header/include prose, so the
  same exact declaration must also appear immediately before the UID0001KN definition
  inside Destination 1's valid ordinary emitter block. A duplicate packet body, new
  protocol header, or moving the LivingObjectPane member definition into the target-
  selection source is less consistent with the existing module and owner evidence.

### ItemWho construction and state interaction

- The explicit-target branch calls `GeneralPurposePanel::GetChildPaneByIndex(3)`, reads
  accepted `ItemWhoInputPaneState::m_active` at `+0xfa`, and returns without allocation
  when already active. There is no source-supported null guard on the returned state
  pointer.
- When inactive, the target requests `0x10c` bytes and contains the complete inlined
  `ItemWhoInputPane(unsigned char itemSlot)` constructor: LineInputPane base
  construction with zero, three ItemWho vtable stores, `Which target?` prompt setup,
  `m_itemSlot` at full-object `+0x108`, saved target selection from
  `s_itemWhoTargetId`/`s_spellWhoTargetId` under `saveTargetOnClose`, active MapPane
  lookup, living/type/suppression checks, local-player fallback, highlight, and final
  saved object id.
- The out-of-line constructor at `0x005aec60-0x005aed3d` has the same ordered source
  operations. The target therefore needs only a normal ItemWho constructor new-expression,
  not manual vtable stores, prompt calls, saved-global writes, or highlight code.
- After construction, the target deliberately fetches child index 3 again and calls
  `ItemWhoInputPaneState::SetInputModeFlag(true)`. Destination 1 preserves that second
  accessor call rather than reusing the pre-construction pointer.

### Allocation, EH, and compiler wrappers

- The nullable allocator call to `0x004f4aa0`, allocation test, constructor inlining,
  vtable writes, and target SEH prologue are ordinary compiler expansion of the source
  new-expression.
- EH cleanup at `0x0060a41f` calls delete wrapper `0x004f4ac0`; cleanup at
  `0x0060a42a` transfers to base cleanup `0x004f2010`; metadata/handler material at
  `0x0060a432` references the target's C++ frame-handler data. These addresses are
  compiler support outside the target range, not source children.
- No handwritten try/catch, explicit delete, vtable assignment, allocation-failure
  branch, scalar-delete wrapper, or EH helper belongs in the formal body.

### Return type and local names

- Seven call sites discard the target result. `UseInputPane::OnSubmitInput` does not
  test/store it; its epilogue can inherit whatever byte remains in `AL`.
- Target invalid-slot exits leave `slot - 1` in `AL`; inactive-record exits can leave a
  pointer low byte; packet paths leave the packet helper result; the already-active
  path leaves the state flag; and the constructed path leaves the setter result.
  These cannot be one meaningful `char` or `bool` contract. Source return is `void`.
- Use local names `record` and `state`. Reject IDA `Block`, `v5`, `v6`, and raw integer
  array types as decompiler artifacts.

### Owner, source route, and rejected alternatives

- `LivingObjectPane` is proved by receiver fields, same-class slot accessor, paired
  `UseCommandSlot`, hotkey methods, and current owner chain. `LivingObjectPane.cpp` is
  the accepted generated/source-tree route.
- InventoryPane/NewInventoryPane/InventoryPane2/MapPane/UseInputPane are callers;
  TargetSelectionInputPanes provides constructor/packet dependencies; UserPane is the
  singleton/adjusted aggregate context. None is direct semantic owner.
- `UseSpellSlot` is rejected because address `0x005a4530` is the command/spell-slot
  method and accepted raw caller source already distinguishes `UseCommandSlot` from
  `UseInventorySlot`.
- `DispatchItemUseSlot` and filename-level `UseInventorySlotDispatch` remain useful
  descriptive aliases but lose to the accepted paired method spelling.

## Evidence Standards Used

- Primary evidence: fresh IDA MCP `idb_list`, `server_health`, `lookup_funcs`,
  `analyze_batch`, `decompile`, `disasm`, `xref_query`, `stack_frame`, `get_bytes`, and
  `find_bytes` against the adopted NexusTK IDB.
- Corroboration: current by-* source-quality pages, accepted formal blocks, class/file
  routes, exact generated output, and executed B-agent research that had already been
  incorporated into current docs.
- Negative evidence: no target VA/RVA pointer hits, no target data/vtable route, no raw
  helper entry xrefs, no out-of-line constructor call, no caller return test/store, and
  no range need for split/extension.
- Binary context is sufficient for behavior and ABI. Stripped private symbols prevent
  original lexical proof, so inferred names are explicit and confidence remains below
  final-source certainty.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: target/function/stack/callees,
  all six modeled callers, raw caller disassembly, xrefs, target pointer patterns,
  exact body and padding bytes, ItemWho constructor, packet helper, and compiler cleanup
  references.
- by-* docs checked: UID0001KN, UID00007B, UID0000KU, UID0001KM, UID0003U9,
  UID0003UA, UID0003UB, UID0003UC, UID00006X, UID00006Y, UID0001IJ, UID0002S1,
  UID0001LA, UID0002AB, UID00015W, UID0000FG, UID0001ML, MapPane selected-object
  support, globals `g_activeMapPane`/`g_pUserPane`/`g_pGeneralPurposePanel`, Registry
  config, prompt, packet sender, and current generated source.
- Old-report search was run across active Agent-B `research`, legacy
  `research/executed`, central `executed-b-agent-research`, and `archived` Markdown.
  The exact term sets were: target UID `UID0001KN|UID:0001KN|0001KN`; target range
  `0x005a3e30|0x005a3ff3`; names
  `UseInventorySlotDispatch|UseInventorySlot|UseSpellSlot`; packet support
  `SendObjectActionPacket|UID0001LA|UID:0001LA|0x005af580`; constructor family
  `ItemWhoInputPane`; owner/source family
  `LivingObjectPane|LivingObjectPane.cpp|UID00007B|UID:00007B|UID0000KU|UID:0000KU`.
- Search disposition: excluding this artifact, 12 active Agent-B report files produced
  zero direct-term matches; no legacy `research/executed` or `archived` report file was
  present; central executed searches produced 11 UID matches, 15 range matches, 13
  target-name matches, 7 packet matches, 20 ItemWho matches, and 145 broad
  LivingObjectPane owner/source matches, with overlap. Broad owner/ItemWho-only hits
  were search leads, not direct-target coverage. No central report has
  `TARGET-REPORT-UID:0001KN`; this remains the first dedicated exact-target report.
- Exact matching central executed reports opened and their relevant result:

| Opened report path | Relevant finding or explicit no-direct-report result |
| --- | --- |
| `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md` | Direct family support: fixes UID00007B/UID0000KU ownership, exact target range, eight direct call sites, inventory/item semantics, and rejection of old `UseSpellSlot`; it deliberately leaves dedicated child C++ unresolved. |
| `executed-b-agent-research/B001/0001E1-IntegrateMacroDialog-source-quality.md` | Incidental address-only macro-state caveat; no UID0001KN body, signature, owner decision, or packet declaration plan. |
| `executed-b-agent-research/B001/0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md` | Direct support for child index 3, `m_active +0xfa`, set-to-true tail, and the UID0001KN allocation guard; no target body report. |
| `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md` | Confirms the exact retained child range, local-player split, and raw internal call at `0x005a3ac6`; no final target C++ or signature. |
| `executed-b-agent-research/B001/0001MN-0001MP-0001MQ-spellspellinputpane-source-quality.md` | `UseSpellSlot` discussion concerns paired command target `0x005a4530`; it supplies no direct UID0001KN coverage and cannot name this inventory target. |
| `executed-b-agent-research/B005/0000KC-ItemActionInputPanes-empty-emitter-family-source-quality.md` | Keeps UseInputPane non-duplicating and routes its live submit through UID0001KN; no direct target reconstruction. |
| `executed-b-agent-research/B005/0000OH-TargetSelectionInputPanes-empty-emitter-family-source-quality.md` | Establishes UID0001LA's exact packet body, owner UID0000OH, position 21, and historical file-local `static`; it predates the cross-file UID0001KN declaration requirement. |
| `executed-b-agent-research/B005/0001L8-TargetSelectionInputPanes-source-quality.md` | Confirms UID0001LA range, padding, callers, and packet-family placement; no UID0001KN body or cross-TU declaration decision. |
| `executed-b-agent-research/B006/0001II-SpellInputPaneStateSetFlag-source-quality.md` | Paired-state evidence confirms UID0001KN uses the item-side setter/guard rather than spell-side state; no target report. |
| `executed-b-agent-research/B006/0003U9-LivingObjectPaneGetInventorySlotAddress-source-quality.md` | Resolves accessor signature, table base/stride, active byte, `targetMode +0x1f8`, and UID00007B/UID0000KU route used by this target. |
| `executed-b-agent-research/B007/0000KU-LivingObjectPane-empty-emitter-family-source-quality.md` | Keeps `NexusTK/map/LivingObjectPane.cpp` as file root and explicitly leaves UID0001KN blank pending a dedicated child audit. |
| `executed-b-agent-research/B008/0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md` | Separates retained no-entry packet helper UID0003NZ from live UID0001KN dispatch and preserves the UseInputPane call; no replacement target body. |
| `executed-b-agent-research/B008/0003UY-LivingObjectPaneRawFacingPacketHelper-source-quality.md` | Uses `0x005a3e30` only as a live route-scan positive control; no direct target analysis. |
| `executed-b-agent-research/B010/0001ML-ThrowUseEatInputPanes-source-quality.md` | Confirms `UseInputPane::OnSubmitInput` maps a validated letter to `1..52` and calls UID0001KN; no target body. |
| `executed-b-agent-research/B010/0003UC-LivingObjectPaneUseCommandSlotDispatch-source-quality.md` | Supplies the accepted paired `UseCommandSlot` spelling, same UID00007B/UID0000KU route, and explicit rejection of `UseSpellSlot` ambiguity for UID0001KN. |
| `executed-b-agent-research/B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md` | Confirms `0x005a3e30` as a caller of child-index accessor `0x004b85f0`; no direct target reconstruction. |
| `executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md` | Resolves ItemWho constructor, prompt, saved target, state, child method bodies, and UID0001LA dependency; broad parent remains non-emitting and does not cover UID0001KN. |
| `executed-b-agent-research/B013/0002SU-InventoryPane2CoreAndHelpers-source-quality.md` | Contains one inventory caller-side `UseInventorySlotDispatch` source lead only; no direct target report. |
| `executed-b-agent-research/B013/0003UA-LivingObjectPaneRawConfigHotkeyHelper-source-quality.md` | Confirms raw call `0x005a3ac6`, UID00007B/UID0000KU route, and accepted formal caller spelling `UseInventorySlot`; it leaves UID0001KN's body to this dedicated pass. |
| `executed-b-agent-research/B015/0003UJ-LivingObjectPaneRawFunctionKeyDebounceHelper-source-quality.md` | Lists UID0001KN only as neighboring positive-control/support evidence; no direct target body. |
| `executed-b-agent-research/B002/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md` | Confirms ItemWho navigation/support and UID0001LA neighbor, but no UID0001KN range, source signature, or declaration decision. |
| `executed-b-agent-research/B005/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md` | Mentions UID0001LA only as predecessor/boundary support; no direct target or linkage coverage. |
- Negative checks performed: target absolute VA `30 3E 5A 00` and RVA
  `30 3E 1A 00` searches returned zero; raw helper start `0x005a3a20` has zero incoming
  xrefs; target has exactly eight code xrefs and no pointer/data route.
- Failed/unavailable/skipped checks: the first local PowerShell HTTP attempt omitted
  `-UseBasicParsing` and failed in the client before producing an MCP result. The same
  fresh initialized session then completed every required IDB call successfully. No
  fallback-only evidence was accepted, and no write-capable IDA operation was used.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target becomes `92/93`; owner/emitter/reconstructable/blank position/Nested stay unchanged. | High | Current metadata plus completed blocker audit. | Destination 1 target header/score/status. | Applied metadata and rationale. | implemented; verified |
| C02 | Exact target is `0x005a3e30-0x005a3ff3`, 451 bytes, body SHA256 `6C3E...D02F`, with 11-byte prepad and 13-byte postpad. | High | Live lookup/get_bytes/hash. | Destinations 1-4 range sections. | Replaced broad boundary wording. | implemented; verified |
| C03 | Source method is `void LivingObjectPane::UseInventorySlot(unsigned char slot)`. | High | thiscall ABI, callers, accepted raw-caller C++, AL audit. | Destinations 1-4, 7-8. | Applied source name/signature. | implemented; verified |
| C04 | Selector validation is exactly one-based `1..52`. | High | `slot-1` unsigned compare to `0x33`; all callers. | Destination 1 behavior/formal block. | Applied. | implemented; verified |
| C05 | Source record access is accepted `GetInventorySlotAddress`, base `+0x133f08`, stride `0x1fc`, `active +0`, `targetMode +0x1f8`. | High | Target bytes/decompile and UID0003U9. | Destinations 1, 2, 4, 5. | Applied/synchronized. | implemented; verified |
| C06 | Target mode 0 sends slot/action plus this object's `m_objectId`. | High | Direct call at `0x005a3e93`; offset `+0xfc`. | Destination 1. | Applied. | implemented; verified |
| C07 | Target mode 1 sends to selected living object only for active flag exactly 1 and non-null pointer. | High | Branch and call at `0x005a3ed2`; MapPane field docs. | Destinations 1-4. | Applied. | implemented; verified |
| C08 | Failed mode 1 and all other target modes open explicit target selection. | High | Target control flow. | Destinations 1-4. | Applied. | implemented; verified |
| C09 | Child index 3 state is fetched and `m_active +0xfa` suppresses duplicate prompt allocation. | High | Calls/read plus UID00015W/UID0001IJ. | Destinations 1, 6, 7. | Applied. | implemented; verified |
| C10 | Allocation plus setup is an inlined source `ItemWhoInputPane(itemSlot)` construction, not manual setup. | High | Exact sequence parity with `0x005aec60`. | Destinations 1, 4, 6. | Applied. | implemented; verified |
| C11 | Prompt is accepted `Which target?`; slot field is `m_itemSlot +0x108`. | High | Prompt xrefs and constructor/class docs. | Destinations 1, 6. | Preserved through constructor call and prose. | implemented; verified |
| C12 | Constructor uses `s_itemWhoTargetId`, optional `s_spellWhoTargetId`, and `saveTargetOnClose`. | High | Live constructor and UID0002AB/config docs. | Destinations 1 and 6; dependency pages read-only. | Recorded as inlined constructor semantics. | implemented; verified |
| C13 | Constructor lookup/fallback/highlight/save sequence is source constructor behavior. | High | Live ctor/target parity and class docs. | Destinations 1 and 6. | Recorded without duplicating body in target. | implemented; verified |
| C14 | State is fetched again after construction and set true. | High | Calls at target tail and UID0001IJ. | Destinations 1, 6, 7. | Applied exact second fetch/call. | implemented; verified |
| C15 | Shared packet ABI is cdecl action/object id, opcode `0x1c`, six bytes sent, scratch byte excluded. | High | Live helper analysis and current formal. | Destinations 1, 9-11. | Preserved exact body/ABI. | implemented; verified |
| C16 | Allocator null test, SEH, vtables, cleanup funclets, cookie, delete/base cleanup are compiler output. | High | Target bytes, EH metadata, ctor parity. | Destinations 1, 4, 6. | Historicalized blocker; emitted no wrappers. | implemented; verified |
| C17 | No semantic target return exists; source is `void`. | High | All caller/result and exit-AL audit. | Destinations 1, 7, 8. | Applied clarification. | implemented; verified |
| C18 | Legacy InventoryPane has one modeled mouse-input route at `0x004eab81`. | High | Live xref/decompile and InventoryPane docs. | Destination 1 caller table. | Applied. | implemented; verified |
| C19 | NewInventoryPane has two modeled mouse-input routes at `0x004ed711` and `0x004ed7fc`. | High | Live xref/disassembly. | Destination 1 caller table. | Applied. | implemented; verified |
| C20 | InventoryPane2 has one modeled mouse route at `0x004ef0e1`. | High | Live xref/decompile and exact child. | Destination 1 caller table. | Applied. | implemented; verified |
| C21 | MapPane keyboard/command input has one route at `0x005070c1`. | High | Live xref/decompile and vtable family. | Destination 1 caller table. | Applied. | implemented; verified |
| C22 | ExecuteHotkeyAction inventory macro mode has one route at `0x005a3ba1`. | High | Live xref/decompile and UID0003UB. | Destinations 1, 2, 4. | Applied. | implemented; verified |
| C23 | UseInputPane submit has one validated-letter route at `0x005b5e51`. | High | Live xref/decompile and Use docs. | Destinations 1 and 8. | Applied; clarified return residue. | implemented; verified |
| C24 | Raw compact shortcut mode zero has one call at `0x005a3ac6`; raw start remains no-entry. | High | Live raw disassembly/xref and UID0003UA. | Destinations 1-4. | Applied exact modeled/raw wording. | implemented; verified |
| C25 | Target has no absolute/RVA pointer/data/vtable route; direct calls prove ordinary method liveness. | High | Live xref/find_bytes. | Destination 1 negative evidence. | Applied. | implemented; verified |
| C26 | Owner/emitter/file remain UID00007B through UID0000KU; consumers/dependencies are rejected owners. | High | Receiver fields, paired method, current route. | Destinations 1-4. | Preserved. | implemented; verified |
| C27 | No split/new child/compiler wrapper/covered marker is warranted. | High | Exact range and source operation. | Destinations 1 and 4. | Preserved one exact source child. | implemented; verified |
| C28 | Reject `UseSpellSlot`, broad dispatch alias as final method, manual constructor, explicit EH/delete, and duplicate packet body. | High | Paired formal C++, ctor parity, helper call. | Destinations 1-11 historical/rejected text. | Applied additively. | implemented; verified |
| C29 | Destination 1 is the only UID0001KN formal C++ block, contains the exact external packet-helper declaration directly before the method definition, and retains the literal managed header lines. | High | All preceding claims, by-file guidance, and workflow format. | Target formal block. | Applied exactly. | implemented; verified |
| C30 | Packet helper linkage must be external under the current two-file route. For current validator output, exact declaration `int SendObjectActionPacket(unsigned char action, unsigned int objectId);` must appear directly before the method in Destination 1's valid UID0001KN emitter block; Destination 9 remains the sole non-static definition. Probable final-source placement in `NexusTK/ui/dialogs/TargetSelectionInputPanes.h` plus the `LivingObjectPane.cpp` include stays non-emitting prose on Destinations 10 and 3 because by-file roots cannot carry formal blocks. All other reviewed dependencies stay score-neutral/same-or-greater. | High | Existing static formal, five live helper calls, by-file guidance, by-file `.cpp`/`.h` pair, ItemWho class route, and LivingObjectPane source route. | Destinations 1, 3, and 9-11. | Added exact declaration, removed only `static`, preserved body/metadata, documented probable placement, and verified one declaration/definition. | implemented; verified |

## Positive Evidence Summary

- Direct facts: exact modeled function, exact bytes/range, eight direct code xrefs, known
  LivingObjectPane receiver fields, two packet calls, selected-object state, complete
  inlined ItemWho constructor, state activation, and compiler EH metadata.
- Corroboration: accepted raw caller already invokes `UseInventorySlot`; paired target
  is accepted `UseCommandSlot`; current slot, MapPane, ItemWho, state, prompt, saved
  global, panel, and packet pages resolve every dependency used in Destination 1.
- Strongest inference chain: one-based slot callers plus LivingObjectPane table access
  prove method role; paired accepted name and raw-caller formal prove source naming;
  byte-for-byte constructor parity reduces the broad machine body to a short human
  source operation; inconsistent AL exits prove `void`.

## IDA MCP Facts

- Function/range facts: `sub_5A3E30`, `0x1c3` bytes, half-open
  `0x005a3e30-0x005a3ff3`, `retn 4`, exact body SHA256 above.
- Data/table/padding facts: inventory table base `+0x133f08`, stride `0x1fc`, active
  byte `+0`, target mode `+0x1f8`; prepad `0x005a3e25-0x005a3e30`; postpad
  `0x005a3ff3-0x005a4000`.
- Xref facts: exactly eight code xrefs at `0x004eab81`, `0x004ed711`,
  `0x004ed7fc`, `0x004ef0e1`, `0x005070c1`, `0x005a3ac6`, `0x005a3ba1`, and
  `0x005b5e51`.
- Vtable/global/type facts: no target vtable route; target reads active MapPane,
  GeneralPurposePanel, config/saved globals through the inlined constructor, UserPane
  object state, and known ItemWho vtables only as compiler constructor expansion.
- Negative IDA facts: no target VA/RVA pointer hit, no raw-helper entry xref, no direct
  call to out-of-line ItemWho constructor, no caller result test/store, and no target
  range extension/split evidence.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a3e30-0x005a3ff3` | UID0001KN target | Source `UseInventorySlot` method. | TRUE | UID00007B | current `86/90`, proposed `92/93` | Exact source-bearing target. |
| `0x005a3a20-0x005a3ad4` | UID0003UA | Retained compact shortcut caller; mode zero calls target. | TRUE | UID00007B | `87/88` | Existing source child; no entry route. |
| `0x005a3870-0x005a3889` | UID0003U9 | Slot-record accessor inlined by target. | TRUE | UID00007B | `88/91` | Existing source child. |
| `0x005aec60-0x005aed3d` | UID0002S1 | Out-of-line ItemWho constructor mirrored inline in target. | TRUE | UID00006X | `88/90` | Existing source child. |
| `0x0057d0a0-0x0057d0b0` | UID0001IJ | ItemWho state setter. | TRUE | UID00006Y | `88/90` | Existing source child. |
| `0x005af580-0x005af5ea` | UID0001LA | Shared object-action packet helper. | TRUE | UID0000OH | `88/90` | Existing source helper; linkage-only sync proposed. |
| `0x0060a41f`, `0x0060a42a`, `0x0060a432` | compiler EH support | Allocation/base cleanup and C++ frame data. | FALSE as target children | compiler/ABI | not applicable | No source child or formal C++. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004eab81` | legacy `InventoryPane::OnMouseInput` | Mouse item activation resolves a slot and dispatches item use; target result ignored. |
| `0x004ed711` | `NewInventoryPane` mouse/input body | First current/double-click item-use route; target result ignored. |
| `0x004ed7fc` | `NewInventoryPane` mouse/input body | Second item-use route under alternate input state; target result ignored. |
| `0x004ef0e1` | `InventoryPane2::OnMouseEvent` | Valid selected slot dispatch; target result ignored and caller returns its own success. |
| `0x005070c1` | MapPane keyboard/command input | Alphabetic key maps to slot then calls target; result ignored. |
| `0x005a3ac6` | raw UID0003UA compact shortcut helper | Mode-zero retained raw path calls inventory slot method; helper start has no entry xref. |
| `0x005a3ba1` | `LivingObjectPane::ExecuteHotkeyAction` | Integrated inventory macro row dispatch; target result ignored. |
| `0x005b5e51` | `UseInputPane::OnSubmitInput` | Valid letter-derived slot dispatch; no test/store of target result, incidental `AL` reaches caller epilogue. |
| `0x005a3e93` | callee `SendObjectActionPacket` | Mode-zero direct send to `m_objectId`. |
| `0x005a3ed2` | callee `SendObjectActionPacket` | Mode-one selected-object direct send. |
| target explicit branch | `ItemWhoInputPane(unsigned char)` inline | Normal new-expression compiles to allocator plus inlined constructor. |
| target tail | `ItemWhoInputPaneState::SetInputModeFlag(true)` | Activates item-target input after second child-index lookup. |

## Documentation Evidence And IDA Status

- Existing docs supporting the conclusion: UID0003UA already emits a call to
  `UseInventorySlot`; UID0003UC proves the paired command method; UID0003U9 closes the
  record layout; UID0002S1 closes constructor/source operation; UID0001IJ closes state;
  UID0001LA closes packet ABI; MapPane and saved-target pages close globals/fields.
- Pre-callback stale/incomplete docs: UID0001KN blank formal and superseded blockers;
  UID00007B/UID0000KU/UID0001KM unresolved/provisional target wording and old caller
  count; UID0001LA/UID0000OH file-local linkage under a different generated file;
  UID0001IJ wording that can be read as a semantic target return rather than machine
  residue.
- Pre-callback generated state: LivingObjectPane.cpp had one UID0001KN Empty Emitter Marker and no
  target definition; TargetSelectionInputPanes.cpp had one static packet helper. These
  are read-only pre-callback observations, not files to edit manually.

## Ranked Ownership Analysis

### 1. LivingObjectPane / LivingObjectPane.cpp

- Evidence for: thiscall receiver; inherited `m_objectId`; local inventory table;
  accepted `GetInventorySlotAddress`, raw shortcut, hotkey, and paired command methods;
  six modeled caller families; current owner/emitter chain.
- Evidence against: the receiver is the adjusted local UserPane singleton in normal
  callers, so the broader class-layout boundary remains historically complex. That
  does not displace exact method ownership.
- Decision: accepted semantic owner/emitter UID00007B and file UID0000KU.

### 2. TargetSelectionInputPanes / ItemWhoInputPane

- Evidence for: explicit target branch constructs ItemWho and calls shared packet/state
  helpers; packet helper also serves ItemWho key/mouse methods.
- Evidence against: no ItemWho receiver is present until fallback construction;
  no-target and selected-target paths never create a pane; slot table and object id are
  LivingObjectPane fields.
- Decision: dependency/support owner only. Keep packet helper there with external
  linkage under the current split.

### 3. InventoryPane families, MapPane, UseInputPane, UserPane, or packet module

- Evidence for: these classes call or supply state to the target; UserPane is the
  singleton/aggregate context.
- Evidence against: none owns the exact receiver method and all lack the complete
  three-route behavior. Packet construction is delegated rather than inlined.
- Decision: rejected as direct target owners.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; retain existing LivingObjectPane.cpp.
- Likely full contents: existing LivingObjectPane exact children, including paired
  slot methods.
- Candidate related items that belong: UID0003U9, UID0003UA, UID0003UB, UID0001KN,
  UID0003UC through their current class/file routes.
- Candidate related items rejected: ItemWho classes and packet helper remain in their
  existing TargetSelectionInputPanes owner; UI callers stay in their own modules.
- Standalone/narrow/broad inference: one narrow ordinary method definition, no new
  source file.

## Source Placement

- Recommended target placement: define `LivingObjectPane::UseInventorySlot` in
  `NexusTK/map/LivingObjectPane.cpp` and declare the method on the reconstructed
  `LivingObjectPane` class/header surface. Keep the sole packet-helper definition in
  `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Current validator-emitted compile route: put exact external declaration
  `int SendObjectActionPacket(unsigned char action, unsigned int objectId);` directly
  before the method definition in UID0001KN's Destination 1 formal block. This emits
  into LivingObjectPane.cpp through the valid child route and requires no by-file
  reconstruction metadata.
- Probable final hand-reconstructed source route: put the same prototype in existing
  paired header `NexusTK/ui/dialogs/TargetSelectionInputPanes.h` and include it from
  `NexusTK/map/LivingObjectPane.cpp` with
  `#include "../ui/dialogs/TargetSelectionInputPanes.h"`. Destinations 10 and 3 record
  these exact lines as source-placement prose only; they are not current formal blocks
  and are not claimed to enter validator output from by-file pages.
- This fits current source-tree and subsystem context because the target directly uses
  LivingObjectPane storage/accessors and sits between same-family local-player hotkey
  and command-slot methods.
- Rejected placements: InventoryPane and UseInputPane are caller-specific; MapPane owns
  selected-object fields only; TargetSelectionInputPanes owns ItemWho and packet
  support only; UserPane is aggregate/lifetime context rather than the accepted exact
  method class.
- Remaining placement uncertainty: original stripped translation-unit boundaries may
  have put the packet helper and local-player methods in one larger source. The current
  project has already chosen two reconstructed files; external helper linkage makes
  that accepted split coherent without changing semantic ownership. The header route
  is higher probability than a LivingObjectPane.cpp-local `extern`, a new protocol
  header, moving the member definition into TargetSelectionInputPanes.cpp, or
  duplicating packet serialization: the target-selection by-file page already names
  the `.h`, and UID0001KN already needs it for `ItemWhoInputPane` construction. The
  direct declaration in Destination 1 is a current generator-compatible visibility
  measure, not evidence that the original source used a `.cpp`-local declaration.

## Range / Split / Padding / Reclassification Analysis

- Exact range is unchanged at `0x005a3e30-0x005a3ff3`; no bytes in the target are
  padding, switch data, or a second source function.
- Alignment immediately before is `0x005a3e25-0x005a3e30` (11 `0xcc` bytes).
  Alignment immediately after is `0x005a3ff3-0x005a4000` (13 `0xcc` bytes).
- Adjacent raw/unmodeled code on either side remains outside UID0001KN. The next modeled
  function starts at `0x005a4060`; this does not authorize absorbing the intervening
  raw bodies or padding.
- EH cleanup/helper addresses in the `0x0060a4xx` area are compiler metadata/funclets
  outside the range, not split children.
- Parent UID0001KM stays a non-emitting mixed split index. UID0001KN remains its own
  exact source-bearing child.

## Negative Evidence Summary

- No absolute VA or RVA pointer to the target was found; no target vtable/data route
  exists. Direct calls are the proven liveness mechanism.
- Raw caller start `0x005a3a20` has no incoming xref; its internal target call is valid
  retained-source evidence but not a live entry route claim.
- No call to out-of-line `ItemWhoInputPane` constructor exists because the compiler
  inlined it; absence of that edge is not absence of a source constructor operation.
- No caller tests/stores target `AL`; one epilogue propagation is incidental and target
  exits disprove a coherent return contract.
- Selected-object reads prove MapPane dependency, not MapPane ownership. UI caller
  xrefs prove consumers, not ownership. Physical adjacency to ItemWho functions does
  not override the receiver/class route.
- Generated `UseSpellSlot`, old below-gate wording, IDA `Block`, explicit manual vtable
  setup, handwritten EH/delete, duplicated packet construction, and a second target
  child are all rejected.

## IDA Rename / Type / Comment Recommendations

- Proposed target name: `LivingObjectPane__UseInventorySlot` or the database's accepted
  C++-qualified equivalent for `LivingObjectPane::UseInventorySlot`.
- Proposed target type: source `void` thiscall method with `LivingObjectPane *` receiver
  and one `unsigned char slot` argument; raw stack cleanup remains `retn 4`.
- Proposed comments: slot range `1..52`; record `active` and `targetMode`; target modes
  `0` direct-self, `1` direct-current-selection when valid, otherwise explicit
  ItemWho selection; constructor/EH sequence is compiler-expanded new-expression.
- Keep accepted MapPane, saved-target, ItemWho, state, panel, and packet names. Do not
  rename compiler cleanup funclets as source methods.
- IDA DB edits were not requested and are unsafe in report-only mode. This section is a
  future recommendation only; no IDA state was written.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Every behavioral, ABI, constructor, helper, ownership,
  and source-operation blocker is resolved to source-ready form.
- Destination 1, exact formal insertion text for UID0001KN:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int SendObjectActionPacket(unsigned char action, unsigned int objectId);

void LivingObjectPane::UseInventorySlot(unsigned char slot)
{
    if (slot == 0 || slot > 52) {
        return;
    }

    LocalInventorySlotRecord *record =
        GetInventorySlotAddress(static_cast<char>(slot));
    if (record == NULL || !record->active) {
        return;
    }

    if (record->targetMode == 0) {
        SendObjectActionPacket(slot, m_objectId);
        return;
    }

    if (record->targetMode == 1 &&
        g_activeMapPane->m_selectedObjectActive == 1 &&
        g_activeMapPane->m_selectedObjectPane != NULL) {
        SendObjectActionPacket(
            slot, g_activeMapPane->m_selectedObjectPane->m_objectId);
        return;
    }

    ItemWhoInputPaneState *state =
        static_cast<ItemWhoInputPaneState *>(
            g_pGeneralPurposePanel->GetChildPaneByIndex(3));
    if (state->m_active) {
        return;
    }

    new ItemWhoInputPane(slot);

    state = static_cast<ItemWhoInputPaneState *>(
        g_pGeneralPurposePanel->GetChildPaneByIndex(3));
    state->SetInputModeFlag(true);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 9, exact formal insertion text for UID0001LA. This preserves every
  existing body line and removes only the incompatible `static` linkage keyword:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int SendObjectActionPacket(unsigned char action, unsigned int objectId)
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x1c, packet);
    PacketBufferWriteUInt8(action, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    packet[6] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 6);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Destination 10 header-reconstruction prose: record exact probable final header line
  `int SendObjectActionPacket(unsigned char action, unsigned int objectId);` in
  `by-file/TargetSelectionInputPanes.md` under `Placement Notes`, with source-tree
  destination `NexusTK/ui/dialogs/TargetSelectionInputPanes.h`, adjacent to ItemWho
  declarations and outside class bodies. This is explicitly not a
  `RECONSTRUCTION_CPP CODE` block or by-file metadata and is not claimed to emit now.
- Destination 3 source-placement prose: record exact probable final source include
  `#include "../ui/dialogs/TargetSelectionInputPanes.h"` in
  `by-file/LivingObjectPane.md`, with source-tree destination the include preamble of
  `NexusTK/map/LivingObjectPane.cpp`. This is explicitly not a
  `RECONSTRUCTION_CPP CODE` block or by-file metadata and is not claimed to emit now.

- The target body preserves behavior because it retains both early sends, exact state
  guard, constructor call, second panel lookup, and activation while expressing the
  compiler-expanded constructor/EH mechanics as their normal source operation.
- The body matches plausible mid-2000s C++: null macros, direct member fields, an
  ordinary new-expression whose value is intentionally unused, existing helper calls,
  and no modern ownership abstraction.
- Inferred source names/types are `UseInventorySlot`, `slot`, `record`, `state`,
  `LocalInventorySlotRecord`, accepted MapPane fields, accepted ItemWho state, and the
  existing packet helper name.
- Current generated compile visibility is complete: Destination 1 emits the exact
  external declaration immediately before its method; Destination 9 supplies the sole
  matching non-static definition. Probable final header/include placement remains in
  Destinations 10 and 3 as non-emitting prose. The same header is the required eventual
  source-tree destination for the complete `ItemWhoInputPane` declaration needed by
  the target's new-expression, so that final placement adds no artificial dependency.
- Coding convention follows accepted `UseCommandSlot`, ItemWho constructor/destructor,
  panel accessor, state setter, packet helper, and generated project style.
- Third-party import directive: not applicable; this is NexusTK-owned source.
- No-code proof: not applicable; the target and bounded packet-linkage support are
  eligible and exact formal blocks are supplied.

## Final Recommendation

- C01-C30 were applied without compression. UID0001KN is `92/93`; its
  owner/emitter/reconstructable/position/Nested metadata is preserved, the former empty
  formal block is Destination 1's exact declaration-plus-method block, and stale
  status/open-question/history text is retained only as labeled history.
- Preserve exact parent assignments: UID0001KN -> UID00007B -> UID0000KU. Keep broad
  UID0001KM non-emitting/NONE/FALSE as a split index.
- Bounded score-neutral support synchronization is complete in Destinations 2-11.
  Destination 9 removed only packet-helper `static`; Destination 1's valid child block supplies the
  current generated declaration. Destinations 10 and 3 document the exact probable
  final header/include placement as prose only and must not receive by-file
  reconstruction metadata or formal blocks. No support helper body, owner, score,
  position, packet field, or sent length changes.
- Leave compiler EH/allocator/delete/base cleanup, alignment, and adjacent raw code
  non-emitting. Create no new child or report.
- Future work outside scope: exact original private/enum/translation-unit spelling if
  source or symbols are later recovered. No such recovery is required for current
  source-ready behavior.

## Recommended Target Doc Changes

Implementation callback result: every Destination 1 item below is applied and verified;
the detailed wording is retained as the accepted destination specification.

- Target path:
  `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`.
- Destination 1 metadata: set `COMPLETION:92`, `CONFIDENCE:93`; retain owner UID00007B,
  reconstructable true, emitter UID00007B, blank position, and Nested 0.
- Destination 1 formal C++: apply the exact managed block under `First-Draft C++
  Recommendation`, including the external packet-helper declaration immediately before
  the method definition, and no other target code.
- Destination 1 Item Summary replacement: describe the source-ready LivingObjectPane
  inventory-slot method, exact `1..52` validation, active slot record, direct-self and
  selected-object packet paths, ItemWho explicit-target path, and compiler-generated
  allocation/EH disposition. Remove superseded unassigned/below-gate language.
- Incorporate C02-C29 at report-level detail: exact bytes/padding/hash, all eight call
  sites grouped into six modeled functions plus one raw body, return-type proof,
  record/mode fields, packet ABI, panel/state interactions, full inlined constructor
  semantics, EH/compiler exclusions, owner/source/split, negative checks, and rejected
  names.
- Historicalize rather than erase old `UseSpellSlot`, seven-modeled-caller,
  constructor-setup-blocked, and below-parent-gate assumptions.

## Recommended Support Doc Changes

Implementation callback result: every bounded Destination 2-11 item below is applied
and verified. Imperative verbs are retained only as the accepted Gate-1 specification,
not as pending B002 work.

- Destination 2, `by-class/LivingObjectPane.md`: add a dedicated UID0001KN source-ready
  method paragraph and method-family row naming `UseInventorySlot`, `void` return,
  `1..52`, slot record fields/modes, all caller families, packet/ItemWho outcomes,
  compiler cleanup disposition, and paired `UseCommandSlot`. Replace old wording that
  leaves the method broad/blank/provisional. Keep class score and blank class-level C++.
- Destination 3, `by-file/LivingObjectPane.md`: replace the stale "keep blank pending"
  UID0001KN row and seven-modeled-caller history with source-ready target details,
  LivingObjectPane.cpp placement, the shared external packet dependency, and exact
  modeled/raw route count. Add source-placement prose that probable final
  `NexusTK/map/LivingObjectPane.cpp` includes
  `#include "../ui/dialogs/TargetSelectionInputPanes.h"` for ItemWho and packet
  declarations. Do not add `RECONSTRUCTABLE`, `EMITTER_UIDS`, or
  `RECONSTRUCTION_CPP CODE` metadata to this by-file root; current generated helper
  visibility comes from Destination 1. Keep file score/path and unrelated source splits.
- Destination 4,
  `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`: replace
  provisional generated-name wording in the UID0001KN row with the accepted source
  name/signature and add exact range/padding, route inventory, mode behavior,
  constructor-source operation, no-split, and compiler-wrapper disposition. Keep this
  broad index NONE/FALSE/non-emitting.
- Destination 5,
  `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`: add that
  UID0001KN inlines this accessor after its one-based guard and resolves `targetMode`
  value 0 as direct-self use, value 1 as selected-object fast path when valid, and all
  remaining/fallback cases as explicit ItemWho targeting. Keep accessor metadata/body.
- Destination 6,
  `by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md`: add current live
  proof that UID0001KN's allocation/setup sequence is the compiler-inlined form of this
  exact source constructor, including prompt/slot/saved-target/lookup/fallback/highlight
  order; record that target source uses a normal new-expression and compiler owns
  null/EH/vtable cleanup. Keep constructor metadata/body.
- Destination 7,
  `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`: preserve the bool
  setter body and machine-observable low-byte return, but clarify that UID0001KN is a
  source `void` method. Its final setter `AL` and UseInputPane epilogue propagation do
  not define a target return contract because all other target exits carry incompatible
  residue. Keep score/owner/body.
- Destination 8, `by-class/UseInputPane.md`: add the exact call site `0x005b5e51`,
  validated one-based letter mapping, and no semantic consumption of UID0001KN return;
  preserve the existing UseInputPane method/class disposition and scores.
- Destination 9,
  `by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md`: apply the exact formal
  block in `First-Draft C++ Recommendation`, changing only linkage from file-local to
  external. Add both UID0001KN call sites and explain the current reconstructed
  cross-file requirement. Keep `88/90`, owner UID0000OH, reconstructable true, emitter
  UID0000OH, position 21, packet layout, ABI, and body.
- Destination 10, `by-file/TargetSelectionInputPanes.md`: replace file-local wording for
  UID0001LA with shared externally linked helper wording under the current reconstructed
  split; keep helper owner and source order. Add UID0001KN as the cross-file consumer;
  under existing `Placement Notes`, retain the exact `.cpp`/`.h` pair and record the
  probable final header prototype
  `int SendObjectActionPacket(unsigned char action, unsigned int objectId);` for
  `NexusTK/ui/dialogs/TargetSelectionInputPanes.h`, outside class bodies. This is
  source-placement prose only: do not add by-file reconstruction metadata or a formal
  block. Preserve file score and every unrelated class/helper decision.
- Destination 11,
  `by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md`: add score-neutral
  aggregate support text that UID0001LA remains owned by this family but is externally
  shared with LivingObjectPane.cpp. Record that current generated visibility comes from
  Destination 1's declaration and probable final source placement is Destination 10's
  header plus Destination 3's include prose. Preserve aggregate no-code/split policy
  and all exact child decisions.
- Verified no-edit support: MapPane class and remove-object child already name
  `m_selectedObjectActive`/`m_selectedObjectPane`; GeneralPurposePanel accessors already
  define child index 3; saved-target/config/prompt/global/ItemWho class pages already
  have same-or-greater facts; no source-tree path change is needed.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter UID00007B,
  reconstructable true, blank position, blank formal C++, Nested 0.
- Applied target: `92/93`, same owner/emitter/reconstructable/position/Nested, with
  Destination 1's formal declaration-plus-method body.
- Completion 92 is justified by exact range/hash/padding, complete caller/callee and
  negative route inventory, exact source signature, all mode branches, accepted fields
  and dependencies, constructor-source reduction, packet ABI/linkage repair, complete
  formal body, and implementation-ready destinations.
- Confidence 93 is justified by live bytes and cross-doc agreement. It is not 94+
  because original private method/local/enum names and original translation-unit
  grouping are stripped; the report chooses the highest-probability compile-coherent
  source shape and labels the inference.
- Score-improvement attempts:
  - Range/padding blocker: resolved by live lookup, raw bytes, exact hash, adjacent
    alignment, and neighbor checks.
  - Liveness/caller blocker: resolved by exhaustive eight-xref inventory, all modeled
    caller decompiles, raw helper disassembly, and VA/RVA negatives.
  - Signature/return blocker: resolved by ABI and caller/exit-AL audit to `void` plus
    `unsigned char`.
  - Record/type blocker: resolved through accepted accessor/layout and target dataflow.
  - Selected-object/global blocker: resolved through MapPane fields and saved-global
    constructor docs.
  - Packet blocker: resolved for current validator output through Destination 1's exact
    pre-method external declaration and Destination 9's sole non-static definition.
    Destinations 10 and 3 preserve the probable final header/include route as
    non-emitting prose under the by-file guidance rule.
  - Constructor/setup blocker: resolved by live byte/order parity with out-of-line ctor.
  - Panel/state blocker: resolved through child accessor and state setter/body.
  - Allocation/EH blocker: resolved as compiler-generated new-expression expansion.
  - Name/owner/source/split blocker: resolved through paired accepted method, raw caller
    formal, receiver fields, parent chain, and external helper linkage under current
    split.
- Support scores remain unchanged. No parent score is a blocker and no support metadata
  reparenting is recommended.

## Open Questions With Attempted Resolution

- Method name: accepted `UseInventorySlot` from direct raw-caller formal and paired
  `UseCommandSlot`; no question remains for current source.
- Return type: accepted `void` after exhaustive caller/result and exit-AL audit; no
  question remains.
- Record modes: behavior is exact for values 0, 1, and fallback/other. Original enum
  token spellings are unavailable; numeric comparisons in Destination 1 are safest.
- Constructor source operation: accepted normal ItemWho new-expression after exact
  live comparison; manual setup/EH is rejected.
- Packet placement/linkage: original TU grouping is stripped. All five helper calls and
  current reconstructed file/header routes were checked. External linkage is the only
  non-duplicating compile-coherent solution that preserves current owner/file choices.
  The accepted current generated route is Destination 1's declaration
  `int SendObjectActionPacket(unsigned char action, unsigned int objectId);`
  immediately before `LivingObjectPane::UseInventorySlot` and Destination 9's sole
  non-static definition in TargetSelectionInputPanes.cpp. Probable final hand-
  reconstructed placement remains Destination 10's TargetSelectionInputPanes.h
  prototype and Destination 3's LivingObjectPane.cpp include, both prose-only because
  by-file roots cannot emit formal blocks. This is no longer an unresolved declaration
  or availability assumption.
- Field/local spellings: current accepted descriptive names are supported and used.
  Original lexical proof would require source/PDB not present in the IDB; this affects
  confidence only and does not justify blank C++.
- No unresolved question blocks score, ownership, source placement, split, or formal
  C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Do not edit the research tracker or manual coverage file for this
  callback. UID0001KN's source `Item Summary`/metadata drive validator-owned generated
  coverage output.
- No supervisor-owned row text is requested from B002.

## Follow-Up Actions

- B002 callback work is complete: C01-C30/Destinations 1-11, all scoped validators,
  waited generated verification, report updates, and lease releases are recorded.
- No A-agent or additional B002 implementation action remains in this artifact.
- Any present or future report validation, report-count, execution, path, move, or
  archive state is external validator/supervisor-owned and is not asserted here.

## Confidence

- Recommendation confidence: high (`93`) for the target source body and owner route.
- Score confidence: high; all named target blockers were investigated to resolution or
  implementation-ready support synchronization.
- Remaining uncertainty: original lexical names and original TU grouping only. The
  selected source shape is behavior-identical and coherent with the current project
  split.

## Validator Results

- Every changed ordinary by-* page was validated once from
  `source-3/project-documentation` with
  `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`.
  Every command exited `0` with `ok: 1`; each generated refresh was deferred until the
  final authorized wait.

| Destination | Command ID | Timestamp | Result / warnings / side effects |
| --- | --- | --- | --- |
| 1 UID0001KN | `000000009529` | `2026-07-13T09:09:59-04:00` | `ok:1`; applied completion/confidence and formal block registry updates; eight pre-existing `missing_ref_uid` warnings for UID0003UA/UID0003U9; generated refresh deferred. |
| 2 LivingObjectPane class | `000000009532` | `2026-07-13T09:10:45-04:00` | `ok:1`; 76 pre-existing missing-reference warnings, one reference-index add; score/formal metadata unchanged; refresh deferred. |
| 3 LivingObjectPane file | `000000009536` | `2026-07-13T09:12:03-04:00` | `ok:1`; 71 pre-existing missing-reference warnings, one reference-index add; no by-file reconstruction metadata; refresh deferred. |
| 4 local-player split index | `000000009538` | `2026-07-13T09:13:53-04:00` | `ok:1`; 92 pre-existing missing-reference warnings, four reference-index adds; aggregate metadata/formal block unchanged; refresh deferred. |
| 5 inventory accessor | `000000009539` | `2026-07-13T09:14:25-04:00` | `ok:1`; validator inserted the standard metadata-header blank and rebuilt its UID/path/owner/autogen registry entries; score/body unchanged; refresh deferred. |
| 6 ItemWho constructor | `000000009541` | `2026-07-13T09:15:03-04:00` | `ok:1`; no warnings beyond projected-stats/no-generated-list no-op; score/body unchanged; refresh deferred. |
| 7 ItemWho state setter | `000000009542` | `2026-07-13T09:15:55-04:00` | `ok:1`; no warnings beyond projected-stats/no-generated-list no-op; bool body unchanged; refresh deferred. |
| 8 UseInputPane class | `000000009544` | `2026-07-13T09:16:47-04:00` | `ok:1`; no warnings beyond projected-stats/no-generated-list no-op; score/formal marker unchanged; refresh deferred. |
| 9 UID0001LA | `000000009546` | `2026-07-13T09:17:56-04:00` | `ok:1`; formal registry hash updated for linkage-only change and one reference-index add; score/body/position unchanged; refresh deferred. |
| 10 TargetSelectionInputPanes file | `000000009548` | `2026-07-13T09:18:54-04:00` | `ok:1`; one reference-index add; no by-file reconstruction metadata; refresh deferred. |
| 11 target-selection split index | `000000009549` | `2026-07-13T09:19:45-04:00` | `ok:1`; one reference-index add; aggregate metadata/formal block unchanged; refresh deferred. |

- Final authorized command:
  `python .\tools\validator.py --mode autogen --apply --wait-generated --lock-timeout 240`.
  Command `000000009551`, timestamp `2026-07-13T09:20:02-04:00`, exited `0` and
  reported `generated_refresh: completed`. Global autogen diagnostics were 14 fallback
  child insertions, 83 preferred-marker warnings, and 205 emitting-parent/no-code
  notices across the repository; none identified UID0001KN or UID0001LA as an error.
- Read-only generated proof after command `000000009551`:
  `auto-generated/NexusTK/map/LivingObjectPane.cpp` contains one exact external
  declaration at line 467 followed immediately by one UID0001KN method at line 469,
  zero UID0001KN Empty Emitter Markers, and zero static helper definitions.
  `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` contains one exact
  non-static UID0001LA definition at line 38, zero matching static definitions, and no
  duplicate prototype/definition. Both by-file destinations contain zero forbidden
  reconstruction metadata lines. No unresolved declaration, duplicate, or static
  packet-helper route remains in generated output.
- Lease proof: the validator-owned `tools/leaser/Agents/current_leases.md` snapshot after
  all edits contains no B002 row. All eleven B002 leases were released immediately
  after their scoped validators.

## Changed Files

- Modified ordinary documentation destinations:
  `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`,
  `by-class/LivingObjectPane.md`, `by-file/LivingObjectPane.md`,
  `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`,
  `by-memory/0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md`,
  `by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md`,
  `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`,
  `by-class/UseInputPane.md`,
  `by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md`,
  `by-file/TargetSelectionInputPanes.md`, and
  `by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md`.
- Updated report artifact:
  `tools/leaser/Agents/Agent-B002/research/0001KN-UseInventorySlotDispatch-source-quality.md`.
- Renamed/created by-* pages: none. New children/reports: none.
- Validator-generated C++ and generated metadata were refreshed only by authorized
  command `000000009551` and inspected read-only. B002 did not manually edit generated,
  coverage, tracker, supervisor, validator-state, lifecycle, or IDA files.
- No `execute_report`, lifecycle probe/action, move, or archive command was run. Any
  current/future report execution or location state is external and not asserted.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact SHA `8FC894611CBBA6D970072733C447F6A4B070CD3D940394DAA4216DE0D9697536` before implementation.
- [x] Target/support destinations 1-11 were re-read and updated exactly as listed.
- [x] Pre-callback target state and actual evidence checked are retained as history.
- [x] Claim And Incorporation Ledger records every C01-C30 claim as implemented and verified.
- [x] UID0001KN changed `86/90` -> `92/93`; all support scores remained unchanged.
- [x] Every score/C++ blocker was researched and resolved; no rare no-code proof was needed.
- [x] UID0001KN owner/emitter UID00007B and reconstructable true were preserved.
- [x] Source name `UseInventorySlot` was applied; no split or new child was created.
- [x] Source placement, exact range/padding, reclassification, and IDA name/type/comment recommendations are documented.
- [x] Destination 1 exact declaration-plus-target body and Destination 9 sole external helper definition are the only managed code changes for this compile route.
- [x] Generated cross-file route has one declaration immediately before UID0001KN and one matching non-static UID0001LA definition.
- [x] Probable final header/source placement is prose-only in Destinations 10 and 3; neither by-file root gained reconstruction metadata/formal blocks.
- [x] Third-party import directive confirmed not applicable; this is NexusTK-owned source.
- [x] C01-C30 and Destinations 1-11 were incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence were preserved and labeled.
- [x] Wave2/Wave3 artifacts were retained only as rejected historical evidence where encountered.
- [x] Open questions were closed or retained only as non-blocking stripped-name/TU uncertainty.
- [x] One scoped validator ran for every changed ordinary by-* page, followed by final waited generated verification.
- [x] Generated refresh was validator-driven only; no manual generated/coverage/tracker edit occurred.
- [x] Generated compile visibility, exact counts, by-file metadata prohibition, and absence of static/duplicate/unresolved routes were verified.

Implementation callback pass:
- [x] Report was accepted by the supervisor for bounded implementation.
- [x] All accepted target/support details were incorporated without compression.
- [x] Every ledger row has destination and final verification state.
- [x] Metadata, score, owner/emitter preservation, no-split decision, source rename, linkage, and C++ changes were applied exactly.
- [x] Destination 1/9 declaration-definition chain and Destination 3/10 prose-only placement were verified and recorded.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence were preserved.
- [x] Open questions were resolved or documented with evidence-backed non-blocking uncertainty.
- [x] Eleven scoped validators and their results are recorded.
- [x] Final waited generated refresh command `000000009551` completed and proof was recorded.
- [x] No accepted implementation item remains unapplied; every B002 lease is released.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000009613","destination_path":"executed-b-agent-research/B002/0001KN-UseInventorySlotDispatch-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001KN-UseInventorySlotDispatch-source-quality.md","timestamp":"2026-07-13T10:01:23-04:00","uid":"0001KN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
