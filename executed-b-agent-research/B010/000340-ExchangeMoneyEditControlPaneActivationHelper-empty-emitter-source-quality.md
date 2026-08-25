# UID000340 ExchangeMoneyEditControlPane Activation Helper Source Quality
** TARGET-REPORT-UID:000340 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Project context: this report supports archival preservation and faithful source reconstruction of the unsupported NexusTK client. Runtime behavior is treated as fixed evidence; source names and structure are inferred into plausible human-written mid-2000s C++ rather than decompiler-shaped output.

## Finalized Report / Current Recommendation

- Callback-applied recommendation: [UID:000340] remains owned and emitted by [UID:00004T]; the incorrect `int OnActivate()` draft is historicalized, and the exact `void ExchangeMoneyEditControlPane::Activate()` override now follows the complete anonymous derived-class declaration in `ExchangeDialog.cpp`.
- Final disposition: reconstructable source, not an empty or no-code item. The method activates/selects the embedded editor and tail-delegates to inherited `ControlPane::Activate()`; EAX is residue, not a source return value.
- Ordinary callback disposition: target, class, sibling digit filter, inherited ControlPane bodies, file inventory, vtable support, scores, C340-017 xref correction, and validator/generated verification are callback-applied. Manual coverage and the IDA names/types/comments listed below remain supervisor-owned occurrence state.
- Current exact claim allocation is 37 checked and 9 unchecked: only supervisor-owned C340-037 through C340-045 remain unchecked/proposed.
- Confidence: very strong for behavior, virtual role, owner, source file, source order, and `void` return; strong for the descriptive class/method spellings because original private-class symbols were stripped.

## Supporting Research

- Fresh read-only IDA MCP evidence came from canonical session `supervisor_uid0000od_rollbackverify_20260817`; `server_health` returned `status:ok`, Hex-Rays and string caches ready, and bounded function/item/xref/byte/type queries succeeded.
- Runtime attestation schema 1 returned `ok:true` at `2026-08-17T19:03:18.717951Z` for canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Listener PID 14320 and worker PID 6532 are ephemeral evidence only and are not lifecycle authority.
- The target's former `Empty Emitter Marker` observation is a dated historical lead. Dated validator command `000000025538` at `2026-08-17T14:45:12-04:00` generated stable `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`, 24,204 bytes, SHA256 `A42CFE93FD9A3D338EEDB0595E516CEACDE0CF58FD57799F203EC9C555D7C277`. It contained UID000340, but the emitted class was incomplete and occurred after constructor use. `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.h` was absent in that read-only snapshot, consistent with this file-local class route. At that dated snapshot the defect was source quality/order/API correctness, not a proven absent stable route.
- Callback command `000000025590` at `2026-08-17T16:44:20-04:00` generated the final accepted source route after stale by-file prose was historicalized: `ExchangeDialog.cpp` is 24,724 bytes, SHA256 `F3D72F46E24462B1E53FA72D09F3E725B1F30F3A0D55043F126AEB1B34BCA898`, and places the private class at line 13 before target and sibling bodies at lines 31 and 38. `ExchangeDialog.h` remains intentionally absent. The former order/API/empty-target defects are dated historical states, not current callback defects.
- Dated research-tracker command `000000025551` showed UID000340 at 87/90 with zero direct/additional reports. Any later queue or generated state must be reread dynamically by the supervisor.
- Fresh supervisor Gate 2B preflight stopped before mutation because the literal persisted target/sibling types and the UID0003N6 inbound-reference total differed from the earlier report. No IDA action or save occurred. The corrected literal prestates and 47-reference Deactivate contract are incorporated below, and the accepted C340-017 callback has now corrected and validated UID0003N6's ordinary-document prose.

## Target

- Target UID: `000340`.
- Additional target UIDs: none. UIDs `00004T`, `000341`, `0003N6`, `0003N7`, `000038`, `0003BK`, and `0000J9` are support destinations, not additional report targets.
- Target path: `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, by-memory / Not-Covered Files - Reconstructable, dated command `000000025551`, score 87/90 and zero reports.
- Current assignment classification: ordinary callback applied for the source-quality and former-empty-emitter repair; manual coverage and IDA remain supervisor-owned.
- Callback-applied scores and parent state: target 94/95, owner/emitter [UID:00004T], reconstructable true, emitter position 10.

## Current Target State

- UID000340 now carries `CANONICAL_OWNER:00004T`, `EMITTER_UIDS:00004T`, position 10, score 94/95, and the exact `void Activate()` body. The former `int OnActivate()` body is retained only as corrected history.
- UID00004T now emits the complete anonymous-namespace class declaration, inheritance, inline constructor, and two overrides at position 5; its H channel remains blank because the class is file-local.
- UID000341 now emits the exact Event-based decimal text-input filter as `HandleKeyOrTextEvent(Event *)` at position 20 and scores 94/95. The `OnKeyEvent(KeyEvent *)`/pseudo-field/`CommitCurrentEditText()` model is historicalized.
- UID0003N6 and UID0003N7 now emit the exact inherited `void Deactivate()` and `void Activate()` bodies at 92/94. UID000038 retains its existing protected declarations/fields and now records the dependency closure without duplicate declarations.
- UID0003N6 lines 89 and 95 now state the exact 47-total inventory: one code xref `0x00580639` plus the 46 retained data refs. Scoped command 000000025705 validated the correction; UID0003N7 remains correct at 48 total.
- UID0003BK records exact derived slot identities at 90/95 without hand-written vtable emission. UID0000J9 records the sole current module pair disposition as generated `ExchangeDialog.cpp` with intentionally absent `ExchangeDialog.h`; class-per-file names are historical only.
- Dated command 000000025590 physically verifies class-before-use order, exactly one target/sibling/base definition, and the accepted source-facing APIs. The unrelated pre-existing `ExchangeDialog::OnKeyEvent(KeyEvent *)` elsewhere in the module is outside this private money-edit class and was not renamed by this assignment.
- Artifact execution/archive status is authoritative only from the current path and validator-owned history/status metadata.

## Executive Recommendation

- The accepted ordinary callback defines the anonymous-namespace `ExchangeMoneyEditControlPane : public TextEditControlPane` before constructor use and emits UID000340/UID000341 as ordered children.
- The callback emits `void Activate()` with `SetEditActiveState(true,true)` followed by `TextEditControlPane::Activate()`, and emits the exact Event-based decimal filter as `bool HandleKeyOrTextEvent(Event *event)`.
- UID0003N6/UID0003N7 now provide the shared `ControlPane::Deactivate()`/`Activate()` definitions required by the target's inherited tail route.
- UID0000J9 remains the sole source-file route; no standalone file, manual generated edit, or private-class header was introduced.

## Supervisor Active Recheck

- The assignment resolved why a formal body had been associated with an empty marker. The dated pre-callback route was structurally and semantically wrong; command 000000025590 verifies the corrected callback output.
- No split is needed for the exact 20-byte function. The support expansion is necessary because correct target source depends on the derived declaration, sibling declaration, and inherited `Activate` implementation.
- Every source-bearing item directly required for this repair has a formal CPP/H or evidence-backed blank-H disposition below.

## Inference Research Guidance Check

- IDA facts, documentation facts, and inference are separated throughout this report. Stripped labels are never treated as source names.
- Existing `OnActivate`, `OnKeyEvent`, `KeyEvent`, and `CommitCurrentEditText` assumptions were rechecked rather than copied forward.
- The vtable-slot match to [UID:0003N7], exact tail jump, ControlPane protected declaration, and state byte behavior make `Activate()` substantially stronger than `OnActivate()`.
- `ExchangeMoneyEditControlPane` remains the best descriptive private-class name because its constructor/vtable/source family and money-only digit filter converge. Original spelling is not symbol-proven.
- Wave2/Wave3 references found in old file prose were ignored as stale reconstruction artifacts; no current override authorizes them as evidence.

## Heuristic / Inference Reanalysis And Validation

- Return type: rejected `int`. The target leaves the helper/tail-call EAX visible, but its slot aligns with protected `virtual void Activate()` and callers consume it through a vtable. Best source model is `void`.
- Method name: rejected `OnActivate`. The exact derived cell `0x0061a2c0` replaces base cell `0x00617aec -> 0x00494c30`, whose state-setting semantics and current H declaration identify `Activate`.
- Parent call: rejected invented `TextEditControlPane::OnActivate()`. The tail target is exact base `ControlPane::Activate()` inherited through TextEditControlPane, so normal C++ syntax remains `TextEditControlPane::Activate()`.
- Class layout: no new fields. Constructor allocation is 0x114, exactly the TextEditControlPane size, and invokes the complete base constructor before replacing three vptrs.
- Source location: `ExchangeDialog.cpp`, anonymous namespace. RTTI is anonymous, constructor/destructor references remain in the ExchangeDialog family, and no independent source cluster exists.
- Source order: class definition must precede constructor use. Child definitions should follow declaration in activation-then-event order, matching source position 10 and 20.
- Event handler: rejected raw `KeyEvent` field model. Exact offsets match `Event::m_type`, `m_payload.m_text.m_length`, and `m_text[0]`; accepted input is forwarded and the wrapper returns true regardless of helper EAX.
- Base state helpers: rejected integer-return decompiler shape. They are virtual `void` state transitions and invalidate `m_visibleBounds` only when the boolean changes.
- Empty-marker cause: rejected permanent no-route/no-code interpretation. The dated stable generator already routes the target; incomplete class/header/source order and stale formal code are the remaining source defects.
- Third-party disposition: not applicable. All affected source is project-owned UI reconstruction, not a vetted `third_party_embeds/...` source import.

## Evidence Standards Used

- Primary evidence: live IDA MCP `lookup_funcs`, `inspect_items`, `analyze_function`, `decompile`, `get_bytes`, `xrefs_to`, directional xref queries, type inspection, and collision lookups.
- Corroboration: vtable cell equality, constructor allocation/base-constructor/vptr stores, exact function boundaries/padding, current by-* metadata/formal blocks, manual coverage, and dated generated CPP.
- Negative evidence: no alternate function at boundaries, no derived-field growth, no independent source route, no source-level need for EAX, and no desired-name collisions.
- Confidence is capped below exact/original because stripped private-class names and rebuilt-binary comparison are unavailable, not because any material behavior/ownership question remains deferred.

## Evidence Checked

- Target `[0x004b0b40,0x004b0b54)`: exact function, decompile, disassembly, 20 bytes, SHA256 `7716AF3C1B380AC669140BA345B0C818CDA83B618CE4A0FFDAED3AA10B5D599B`, frame, comments, xrefs, and both padding boundaries.
- Sibling `[0x004b0b60,0x004b0b96)`: exact 54 bytes, SHA256 `7CD8E716EA21C70C0F479376505C54C9FB4D36218D589EB06C9D0BD9AD7EF207`, event tests, helper call, return behavior, frame, and vtable xref.
- Helpers `0x00498c00`, `0x00498d90`, base transitions `0x00494c10`, `0x00494c30`, derived cells `0x0061a2c0`/`0x0061a2d4`, base cells `0x00617ae8`/`0x00617aec`, primary derived vtable `0x0061a264`, constructor `0x004ac8a0`, and destructor reference `0x004b0a66`.
- Types `TextEditControlPane` size 0x114, `ControlPane` size 0x108, and `Event` size 0x110; current H declarations and field offsets were checked.
- Target/class/sibling/file/base/vtable by-* pages, manual coverage rows, the dated generated CPP and absent-H disposition, tracker row, and related executed-report statements were checked.
- Negative checks: collision lookup for all proposed names; no functions at 0x004b0b31, 0x004b0b54, or 0x004b0b96; no code/data route into target padding; no independent class allocation size.
- Research-phase IDA remained read-only. During the accepted callback B010 edited only the eight authorized ordinary by-* destinations, ran scoped validators plus two owning-page waited refreshes (the second after a final stale-prose correction), and physically reread validator-owned generated output. B010 made no direct IDA, manual coverage, lifecycle, tracker, audit, or generated-file edit; automatic validator side effects are recorded in Section 31.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C340-001 | 000340 | Record exact 20-byte activation behavior and tail delegation. | very-strong | bytes/decompile/hash | UID000340 Behavior | incorporate | applied |
| C340-002 | 000340 | Historicalize integer-return and `OnActivate` interpretation. | very-strong | vtable/base slot/type | UID000340 Historical assumptions | historicalize | applied |
| C340-003 | 000340 | Set source identity to `void ExchangeMoneyEditControlPane::Activate()`. | very-strong | slot 0x61a2c0/base 0x617aec | UID000340 Status/Identity | incorporate | applied |
| C340-004 | 000340 | Replace target formal CPP with exact Activate body; H remains blank. | very-strong | exact instructions/control flow | UID000340 CPP/H | incorporate | applied |
| C340-005 | 000340 | Set emitter position 10 and score 94/95. | strong | class/source order/evidence closure | UID000340 metadata | incorporate | applied |
| C340-006 | 000340 | Preserve exact range, padding, hash, xref, and negative evidence. | very-strong | live bounded MCP | UID000340 Evidence | incorporate | applied |
| C340-007 | 00004T | Document exact 0x114 no-new-field derived layout and anonymous source scope. | very-strong | constructor/type/vtable RTTI | UID00004T Layout/Ownership | incorporate | applied |
| C340-008 | 00004T | Replace forward declaration with full derived class/constructor/override CPP. | strong | constructor contract and slots | UID00004T CPP | incorporate | applied |
| C340-009 | 00004T | Keep H blank because class is file-local; set position 5 and 93/95. | strong | anonymous RTTI/source route | UID00004T H/metadata | incorporate | applied |
| C340-010 | 000341 | Record exact one-character decimal text-input filter behavior. | very-strong | bytes/decompile/Event layout | UID000341 Behavior | incorporate | applied |
| C340-011 | 000341 | Replace formal CPP with `HandleKeyOrTextEvent(Event *)`; H blank. | very-strong | helper/type/event offsets | UID000341 CPP/H | incorporate | applied |
| C340-012 | 000341 | Set position 20 and score 94/95; historicalize raw KeyEvent model. | strong | source order/evidence closure | UID000341 metadata/history | historicalize | applied |
| C340-013 | 0003N6 | Record exact clear-if-set/invalidate behavior. | very-strong | body/xrefs/base vtable | UID0003N6 Behavior | incorporate | applied |
| C340-014 | 0003N6 | Add exact `void ControlPane::Deactivate()` formal CPP; H blank. | very-strong | H declaration/body | UID0003N6 CPP/H | incorporate | applied |
| C340-015 | 0003N7 | Record exact set-if-clear/invalidate behavior. | very-strong | body/xrefs/base vtable | UID0003N7 Behavior | incorporate | applied |
| C340-016 | 0003N7 | Add exact `void ControlPane::Activate()` formal CPP; H blank. | very-strong | H declaration/body | UID0003N7 CPP/H | incorporate | applied |
| C340-017 | 0003N6 | Correct UID0003N6 to 47 total inbound refs (one code plus the 46 listed data refs) while preserving score 92/94. | strong | fresh Gate 2B count and exact set | UID0003N6 metadata/evidence | incorporate | applied |
| C340-018 | 0003N7 | Set score 92/94 and preserve 48 inbound refs. | strong | complete xref inventory | UID0003N7 metadata/evidence | incorporate | applied |
| C340-019 | 000038 | Preserve existing protected Activate/Deactivate declarations and field contract. | very-strong | current formal H | UID000038 dependency note | already-present | already-present |
| C340-020 | 0000J9 | Replace stale class-per-file inventory with dated stable ExchangeDialog.cpp and intentional absent-H disposition. | very-strong | dated generated readback | UID0000J9 Status/history | historicalize | applied |
| C340-021 | 0000J9 | Add complete money-edit class/child/base dependency inventory and set 92/92. | strong | source family/constructor/vtables | UID0000J9 inventory/metadata | incorporate | applied |
| C340-022 | 0003BK | Link exact Activate/digit-filter cells and score 90/95. | very-strong | cell values/xrefs | UID0003BK slot inventory/metadata | incorporate | applied |
| C340-023 | 000340 | Historicalize former empty-marker observation; stable route exists. | very-strong | command 25538 physical readback | UID000340 Status/history | historicalize | applied |
| C340-024 | 0000J9 | Run scoped validators, one waited owner refresh, physical ExchangeDialog.cpp reread, and absent-H verification. | required | workflow contract | callback receipts/report | incorporate | applied |
| C340-025 | 000340 | Preserve rejected names, return model, standalone file, and no-code alternatives. | strong | negative evidence | UID000340 Historical assumptions | incorporate | applied |
| C340-026 | 000340 | Preserve 15-byte lead and 12-byte trail `CC` padding facts. | very-strong | exact bytes/boundaries | UID000340 Range | incorporate | applied |
| C340-027 | 000340 | Link SetEditActiveState and HandleKeyOrTextEvent exact helper contracts. | very-strong | named helper types/comments/callers | UID000340/000341 dependencies | incorporate | applied |
| C340-028 | 00004T | Record allocation 0x114, full base construction, and three vptr writes. | very-strong | constructor decompile | UID00004T Construction | incorporate | applied |
| C340-029 | 0000J9 | Keep sole source placement `NexusTK/ui/dialogs/ExchangeDialog.cpp`. | very-strong | family and generated route | UID0000J9 Source placement | already-present | already-present |
| C340-030 | 000340 | Apply target 94/95 score rationale. | strong | blockers resolved | UID000340 metadata | incorporate | applied |
| C340-031 | 00004T | Apply class 93/95 score rationale. | strong | declaration/layout/children closed | UID00004T metadata | incorporate | applied |
| C340-032 | 000341 | Apply sibling 94/95 score rationale. | strong | exact behavior/source closed | UID000341 metadata | incorporate | applied |
| C340-033 | 0000J9 | Apply file 92/92 score rationale. | strong | route/inventory closure | UID0000J9 metadata | incorporate | applied |
| C340-034 | 0003N6 | Apply Deactivate 92/94 score rationale. | strong | source body and xrefs closed | UID0003N6 metadata | incorporate | applied |
| C340-035 | 0003N7 | Apply Activate 92/94 score rationale. | strong | source body and xrefs closed | UID0003N7 metadata | incorporate | applied |
| C340-036 | 0003BK | Apply vtable 90/95 score rationale. | strong | exact cell/source identities | UID0003BK metadata | incorporate | applied |
| C340-037 | 000340 | Insert exact missing by-memory manual coverage rows for UIDs 000340, 000341, 0003N6, 0003N7, and 0003BK. | strong | manual report absence | by-memory/-coverage-report.md | incorporate | proposed |
| C340-038 | 00004T | Replace stale 82% class manual coverage row. | strong | current class closure | by-class/-coverage-report.md | incorporate | proposed |
| C340-039 | 0000J9 | Replace stale 86% file manual coverage row. | strong | current file closure | by-file/-coverage-report.md | incorporate | proposed |
| C340-040 | 00004T | Supervisor declares exact 0x114 derived UDT and verifies member/size readback. | strong | type/layout/constructor | IDA Gate 2B I01 | incorporate | proposed |
| C340-041 | 000340 | Supervisor applies target rename, void type, and FR in ordered stages. | very-strong | target evidence | IDA Gate 2B I02-I04 | incorporate | proposed |
| C340-042 | 000341 | Supervisor applies sibling rename, bool/Event type, and FR. | very-strong | sibling evidence | IDA Gate 2B I05-I07 | incorporate | proposed |
| C340-043 | 0003N6 | Supervisor applies base Deactivate rename, void type, and FR. | very-strong | base evidence | IDA Gate 2B I08-I10 | incorporate | proposed |
| C340-044 | 0003N7 | Supervisor applies base Activate rename, void type, and FR. | very-strong | base evidence | IDA Gate 2B I11-I13 | incorporate | proposed |
| C340-045 | 000340 | Protect ranges, bytes, frames, xrefs, vtable cells, helpers, and unrelated padding. | very-strong | exact manifests below | IDA Gate 2B P01-P06 | reject-invalid | proposed |
| C340-046 | 000340 | Preserve supervisor-only coverage/IDA/lifecycle boundary; B010 never executes report. | certain | workflow/skill | report lifecycle boundary | not-applicable | already-present |

## Positive Evidence Summary

- The exact target call sequence is `SetEditActiveState(this,1,1)` followed by a tail jump to the base state-setting helper.
- Derived vtable cell `0x0061a2c0 -> 0x004b0b40` occupies the same slot as base `0x00617aec -> 0x00494c30`; ControlPane H already calls that slot `Activate()` and declares `void`.
- Constructor allocation equals the full TextEditControlPane size and adds no fields, supporting a narrow file-local behavior subclass.
- The sibling cell and exact event offsets tie the class to a decimal-only money editor rather than a generic key handler.
- The source family, anonymous RTTI, vptr writes, generated module, and file owner independently converge on `ExchangeDialog.cpp`.

## IDA MCP Facts

- Target `sub_4B0B40`: range `[0x004b0b40,0x004b0b54)`, literal current persisted type `int __thiscall(int *this)`, AR absent, AP absent, FR absent, FP absent; frame is only `__return_address +0x4 size 0x4 _UNKNOWN *`.
- Target exact bytes: `56 6a 01 6a 01 8b f1 e8 b4 80 fe ff 8b ce 5e e9 dc 40 fe ff`; sole inbound xref is data cell `0x0061a2c0`.
- Interior regular comments are `selectAll` at `0x004b0b41` and `active` at `0x004b0b43`; corresponding repeatable comments are absent and must remain unchanged.
- Sibling `sub_4B0B60`: range `[0x004b0b60,0x004b0b96)`, literal current persisted item type `char __thiscall(_DWORD *this, int)`. Separately, its frame remains exactly `{__saved_registers +0x4/0x4 _DWORD; __return_address +0x8/0x4 _UNKNOWN *; event +0xc/0x4 struct Event *}`; the typed `event` frame row does not change or override the raw persisted item prototype. Sole inbound cell is `0x0061a2d4`.
- Helper `0x00498c00` is already `TextEditControlPane_SetEditActiveState` with exact `void __thiscall(TextEditControlPane *,bool,bool)` and FR `Forwards edit-active and select-all state to the owned TextEditPane.`
- Helper `0x00498d90` is already `TextEditControlPane_HandleKeyOrTextEvent` with exact `bool __thiscall(TextEditControlPane *,struct Event *)` and FR `EventHandler override forwarding key/text events to the child editor.`
- Base `0x00494c10` hash `C97D8F364BEB37DCF10C6177A75485635A57C70D4E389ACE3A7BBAE35761F322`; base `0x00494c30` hash `CC2001D3751E1F7D5535F9E6C63305F9CEBDA99FE58184945E9CFCCAB9451847`.
- Target lead padding `[0x004b0b31,0x004b0b40)` is 15 `CC` bytes; trail padding `[0x004b0b54,0x004b0b60)` is 12 `CC` bytes. Neither boundary is a function.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x004b0b40,0x004b0b54)` | UID000340 target | derived Activate override | true | UID00004T | 94/95 | exact formal source callback-applied and generated once |
| `[0x004b0b54,0x004b0b60)` | no page | compiler alignment padding | no source | surrounding binary | n/a | exclude from C++ |
| `[0x004b0b60,0x004b0b96)` | UID000341 | decimal text-input override | true | UID00004T | 94/95 | exact Event-based formal source callback-applied and generated once |
| class size 0x114 | UID00004T | anonymous TextEditControlPane subclass | true | UID0000J9 | 93/95 | complete class CPP callback-applied; H intentionally blank |
| `[0x00494c10,0x00494c2a)` | UID0003N6 | inherited Deactivate | true | UID000038 | 92/94 | exact CPP and 47-total xref prose callback-applied/validated |
| `[0x00494c30,0x00494c4a)` | UID0003N7 | inherited Activate | true | UID000038 | 92/94 | exact CPP callback-applied; declaration already present |
| `[0x0061a260,0x0061a304)` | UID0003BK | RTTI/three-vtable island | metadata | UID00004T | 90/95 | slot identities applied; no hand-written data emitter |
| `ExchangeDialog.cpp` | UID0000J9 | sole compilation-unit route | true | FILE | 92/92 | inventory/history callback-applied and generated verified |

- Inventory closure: two class-specific source methods, one file-local class declaration/constructor, two inherited dependency definitions, one compiler-emitted RTTI/vtable island, and the containing source file. Padding is explicitly excluded.
- No extra class field, global, resource, separate header, third-party item, or standalone source file is required.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061a2c0` | data -> `0x004b0b40` | derived Activate virtual slot |
| `0x004b0b47` | call -> `0x00498c00` | enable/select-all forwarding |
| `0x004b0b4f` | tail -> `0x00494c30` | inherited Activate delegation |
| `0x0061a2d4` | data -> `0x004b0b60` | derived event-filter virtual slot |
| `0x004b0b83` | call -> `0x00498d90` | accepted Event forwarding |
| `0x00617ae8` | data -> `0x00494c10` | base ControlPane Deactivate slot |
| `0x00617aec` | data -> `0x00494c30` | base ControlPane Activate slot |
| `0x004accd3/0x004accd9/0x004acce3` | constructor writes vptrs | derived three-base object construction |
| `0x004b0a66` | destructor-side vtable reference | class lifetime corroboration |

- `0x00494c10` has exactly 47 inbound refs: one code xref `0x00580639` plus 46 data refs `0x60da1c,0x60dd68,0x60e02c,0x60e0d4,0x610764,0x610874,0x610b2c,0x610d28,0x6134a4,0x6137d8,0x6165e8,0x61668c,0x617ae8,0x617b8c,0x617c30,0x617cd4,0x617d7c,0x617e24,0x617ec8,0x617f6c,0x618010,0x6180b4,0x6182a0,0x618344,0x6183e8,0x61848c,0x618530,0x61865c,0x61d518,0x61d5bc,0x61d660,0x61d7a0,0x61d844,0x61d8e8,0x61dbe8,0x61dc8c,0x61ddd4,0x61de78,0x61df1c,0x61f718,0x61f7bc,0x622330,0x6223d4,0x62d23c,0x62d2e0,0x62e9f4`. The address set was already correct; only the former total/data-count prose was wrong.
- `0x00494c30` has 48 inbound refs: code `0x004b0b4f,0x00580640` plus 46 data cells `0x60da20,0x60dd6c,0x60e030,0x60e0d8,0x610768,0x610878,0x610b30,0x610d2c,0x6134a8,0x6137dc,0x6165ec,0x616690,0x617aec,0x617b90,0x617c34,0x617cd8,0x617d80,0x617e28,0x617ecc,0x617f70,0x618014,0x6180b8,0x6182a4,0x618348,0x6183ec,0x618490,0x618534,0x618660,0x61d51c,0x61d5c0,0x61d664,0x61d7a4,0x61d848,0x61d8ec,0x61dbec,0x61dc90,0x61ddd8,0x61de7c,0x61df20,0x61f71c,0x61f7c0,0x622334,0x6223d8,0x62d240,0x62d2e4,0x62e9f8`.

## Documentation Evidence And IDA Status

- [UID:000038] provides the source-facing protected virtual names and required fields. [UID:0003N6]/[UID:0003N7] now provide exact formal bodies plus behavior/xref context.
- UID0003N6 ordinary lines 89 and 95 now match the fresh exact count of 47 total (one code plus 46 data), and C340-017 is applied/checked after command 255705 and physical reread. UID0003N7's 48-total statement is unchanged and correct.
- [UID:00004T] now supplies the complete private class before its children. [UID:000341] and [UID:000340] now carry the accepted source APIs; their stale APIs survive only in historical-assumption prose.
- [UID:0003BK] now records the exact derived slot cells and anonymous RTTI grouping at 90/95.
- Dated command 25538 exposed declaration-order/incomplete-class defects. Callback command 25590 generated the corrected private class and child source in the accepted order after final stale-prose repair.
- Manual coverage lacks UID000340 and contains stale UID00004T/UID0000J9 rows; exact supervisor-owned text is in Section 28.
- Current IDA authority must be established by fresh supervisor Gate 2B readback; the dated B010 session is evidence, not permanent mutable state.

## Ranked Ownership Analysis

### 1. UID00004T ExchangeMoneyEditControlPane

- Evidence for: direct derived vtable cell, constructor vptr writes, exact money-digit sibling, identical 0x114 base-sized allocation, and existing canonical owner.
- Evidence against: original private-class spelling stripped.
- Decision: retain as direct class owner; spelling is high-probability descriptive source reconstruction.

### 2. UID0000J9 ExchangeDialog

- Evidence for: constructor/destructor/source family, anonymous RTTI, generated stable module, and exchange-specific behavior.
- Evidence against: exact original filename is inferred, not symbol-proven.
- Decision: retain as sole source-file owner.

### 3. Standalone money-edit source file or TextEditControlPane base file

- Evidence for: behavior is a specialized editor override.
- Evidence against: no separate source cluster; class is anonymous and constructed only inside ExchangeDialog; vptr/runtime family is local.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Not applicable. The existing `NexusTK/ui/dialogs/ExchangeDialog.cpp` route is correct.

## Source Placement

- Recommended placement: anonymous `ExchangeMoneyEditControlPane` declaration in [UID:00004T] at source position 5, target Activate child position 10, digit-filter child position 20, all in `ExchangeDialog.cpp`.
- This ordering makes the class complete before ExchangeDialog constructor code instantiates it and keeps member definitions adjacent to the private class.
- The class is intentionally absent from generated `ExchangeDialog.h`; its formal H blocks remain blank.
- Rejected placements: standalone class CPP/H, `TextEditControlPane.cpp`, vtable-data source, and direct generated-file editing.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is `[0x004b0b40,0x004b0b54)`; the existing by-memory boundary is correct and needs no split/merge.
- `[0x004b0b31,0x004b0b40)` is 15 bytes of `CC`; `[0x004b0b54,0x004b0b60)` is 12 bytes of `CC`. These are compiler alignment and remain non-emitting.
- Sibling starts exactly at `0x004b0b60` and ends at `0x004b0b96`; it remains a separate child because it is a distinct virtual method.
- Vtable island remains compiler-emitted metadata under [UID:0003BK], not hand-written source.
- Parent/container routes remain UID00004T -> UID0000J9.

## Negative Evidence Summary

- No function starts at the three padding/boundary probes, and no route justifies absorbing padding into source.
- No xref/call pattern supports a source return value from target EAX.
- No symbol or slot evidence supports `OnActivate`, `OnKeyEvent`, `KeyEvent`, or `CommitCurrentEditText`.
- No allocation growth or access beyond inherited layout supports added derived fields.
- No separate file/global/resource route supports a standalone module.
- No current evidence justifies direct vtable-data emission or a third-party import.

## IDA Rename / Type / Comment Recommendations

This is a structured, read-only supervisor handoff. B010 did not apply or save any IDA change. `DB` means the exact supervisor-attested canonical database identifier obtained at Gate 2B; it must not be copied from this dated research session. Every stage is fail-closed: establish the complete literal prestate, collision check, apply exactly one public endpoint action, perform the complete readback, and stop before the next stage on any delta outside the stated poststate. Before each function rename, `lookup_funcs` must show the destination name absent and the supervisor must call the same public `rename` payload once with `dry_run:true`; only a clean dry-run permits the listed `dry_run:false` call. No overwrite, function creation, byte patch, analysis, local/frame edit, address comment, repeatable comment, vtable/data rename, or save is authorized.

### Endpoint bindings and ordered stages

| Stage | Classification | Exact public endpoint action | Immediate required readback |
| --- | --- | --- | --- |
| I01 | incorporate | `declare_type({database:DB,decls:"struct ExchangeMoneyEditControlPane { TextEditControlPane TextEditControlPane_base; };"})` | `type_inspect({database:DB,queries:{name:"ExchangeMoneyEditControlPane",include_members:true,max_members:16}})` returns size 0x114 and sole member `TextEditControlPane_base` at +0x0 size 0x114. |
| I02 | incorporate | `rename({database:DB,batch:{func:[{addr:"0x4b0b40",name:"ExchangeMoneyEditControlPane_Activate"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | lookup, item, function, full comments/frame/range/hash/xrefs/padding/vtable readback; only name changes. |
| I03 | incorporate | one-edit `set_type({database:DB,edits:[{addr:"0x4b0b40",kind:"function",signature:"void __thiscall ExchangeMoneyEditControlPane_Activate(ExchangeMoneyEditControlPane *this)"}]})` | item type, analysis prototype, decompile declaration, complete frame, comments, range/hash/xrefs; only function type may change. |
| I04 | incorporate | `set_function_comments({database:DB,items:[{addr:"0x4b0b40",comment:"Exchange money edit activation override: enables editing with select-all, then delegates to ControlPane activation state and invalidation."}]})` | independent AR/AP/FR/FP readback; only FR changes. |
| I05 | incorporate | `rename({database:DB,batch:{func:[{addr:"0x4b0b60",name:"ExchangeMoneyEditControlPane_HandleKeyOrTextEvent"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | complete sibling readback; only name changes. |
| I06 | incorporate | one-edit `set_type({database:DB,edits:[{addr:"0x4b0b60",kind:"function",signature:"bool __thiscall ExchangeMoneyEditControlPane_HandleKeyOrTextEvent(ExchangeMoneyEditControlPane *this, Event *event)"}]})` | item/prototype/decompile/frame/comments/range/hash/xrefs; only type and corresponding argument presentation may change. |
| I07 | incorporate | `set_function_comments({database:DB,items:[{addr:"0x4b0b60",comment:"Exchange money edit text-input filter: accepts exactly one UTF-16 decimal digit, forwards accepted input to TextEditControlPane, and otherwise returns false."}]})` | independent AR/AP/FR/FP readback; only FR changes. |
| I08 | incorporate | `rename({database:DB,batch:{func:[{addr:"0x494c10",name:"ControlPane_Deactivate"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | complete base-function readback; only name changes. |
| I09 | incorporate | one-edit `set_type({database:DB,edits:[{addr:"0x494c10",kind:"function",signature:"void __thiscall ControlPane_Deactivate(ControlPane *this)"}]})` | item/prototype/decompile/frame/comments/range/hash/all 47 inbound refs (one code plus 46 data); only type may change. |
| I10 | incorporate | `set_function_comments({database:DB,items:[{addr:"0x494c10",comment:"Clears ControlPane active state and invalidates the visible bounds only when the state changes."}]})` | independent AR/AP/FR/FP plus complete frame/range/hash/all 47-inbound readback; only FR changes. |
| I11 | incorporate | `rename({database:DB,batch:{func:[{addr:"0x494c30",name:"ControlPane_Activate"}],pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}})` | complete base-function readback; only name changes. |
| I12 | incorporate | one-edit `set_type({database:DB,edits:[{addr:"0x494c30",kind:"function",signature:"void __thiscall ControlPane_Activate(ControlPane *this)"}]})` | item/prototype/decompile/frame/comments/range/hash/all 48 inbound refs; only type may change. |
| I13 | incorporate | `set_function_comments({database:DB,items:[{addr:"0x494c30",comment:"Sets ControlPane active state and invalidates the visible bounds only when the state changes."}]})` | independent AR/AP/FR/FP readback; only FR changes. |

### Literal prestates, intermediate states, and poststates

| Entity | Literal current prestate | Required final poststate |
| --- | --- | --- |
| I01 UDT | type name `ExchangeMoneyEditControlPane`: absent; declaration: absent; size: absent; members: absent; type comments: not applicable through the public endpoint. `TextEditControlPane` exists at size 0x114. | type exists at size 0x114; exactly one member `TextEditControlPane_base` at +0x0, type `TextEditControlPane`, size 0x114; no extra member or padding delta. |
| I02-I04 target | function `[0x4b0b40,0x4b0b54)`; name `sub_4B0B40`; literal persisted type `int __thiscall(int *this)`; AR absent; AP absent; FR absent; FP absent; frame exactly `__return_address +0x4 size 0x4 _UNKNOWN *`; bytes/hash/xref/padding as P01. | name `ExchangeMoneyEditControlPane_Activate`; type `void __thiscall ExchangeMoneyEditControlPane_Activate(ExchangeMoneyEditControlPane *this)`; AR absent; AP absent; FR exact I04 text; FP absent; identical complete frame/range/bytes/hash/xref/padding and interior comments. |
| I05-I07 sibling | function `[0x4b0b60,0x4b0b96)`; name `sub_4B0B60`; literal persisted item type `char __thiscall(_DWORD *this, int)`; AR absent; AP absent; FR absent; FP absent. Separate frame metadata is exactly `__saved_registers +0x4 size 0x4 _DWORD`, `__return_address +0x8 size 0x4 _UNKNOWN *`, `event +0xc size 0x4 struct Event *`; bytes/hash/xref as P02. | name `ExchangeMoneyEditControlPane_HandleKeyOrTextEvent`; type `bool __thiscall ExchangeMoneyEditControlPane_HandleKeyOrTextEvent(ExchangeMoneyEditControlPane *this, Event *event)`; AR absent; AP absent; FR exact I07 text; FP absent; complete frame retains saved/return rows and an `event` row at +0xc size 4 typed `Event *`; range/bytes/hash/xref/interior comments unchanged. |
| I08-I10 base Deactivate | function `[0x494c10,0x494c2a)`; name `sub_494C10`; type `int __thiscall(_BYTE *this)`; AR absent; AP absent; FR absent; FP absent; frame exactly `__return_address +0x0 size 0x4 _UNKNOWN *`; hash and exact 47-inbound set in Section 15 (one code plus 46 data). | name `ControlPane_Deactivate`; type `void __thiscall ControlPane_Deactivate(ControlPane *this)`; AR absent; AP absent; FR exact I10 text; FP absent; frame/range/hash/all 47 inbound refs unchanged. |
| I11-I13 base Activate | function `[0x494c30,0x494c4a)`; name `sub_494C30`; type `int __thiscall(_BYTE *this)`; AR absent; AP absent; FR absent; FP absent; frame exactly `__return_address +0x0 size 0x4 _UNKNOWN *`; hash and exact 48 inbound set in Section 15. | name `ControlPane_Activate`; type `void __thiscall ControlPane_Activate(ControlPane *this)`; AR absent; AP absent; FR exact I13 text; FP absent; frame/range/hash/all 48 inbound refs unchanged. |

After I01, the UDT readback is the required literal intermediate state before I03 or I06. After each rename, the subsequent type stage prestate is the immediately preceding poststate with only the name changed. After each type stage, the comment stage prestate is the immediately preceding poststate with only name/type changed. Any unexpected persisted prototype, frame row, comment, item boundary, collision, xref, byte, hash, or vtable-cell delta stops the sequence before the dependent action.

### Protected dependencies and rollback scope

| Protection | Exact independently protected state |
| --- | --- |
| P01 target physical model | range `[0x4b0b40,0x4b0b54)`, 20 bytes, SHA256 `7716AF3C1B380AC669140BA345B0C818CDA83B618CE4A0FFDAED3AA10B5D599B`; inbound exact `{0x61a2c0/data}`; lead `[0x4b0b31,0x4b0b40)` exactly 15 `CC`; trail `[0x4b0b54,0x4b0b60)` exactly 12 `CC`; interior AR `0x4b0b41=selectAll`, `0x4b0b43=active`; interior AP absent at both. |
| P02 sibling physical model | range `[0x4b0b60,0x4b0b96)`, 54 bytes, SHA256 `7CD8E716EA21C70C0F479376505C54C9FB4D36218D589EB06C9D0BD9AD7EF207`; inbound exact `{0x61a2d4/data}`; interior AR `0x4b0b82=event`; interior AP absent at that head. |
| P03 vtable cells | `0x61a2c0`: kind data, value `0x4b0b40`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable. `0x61a2d4`: kind data, value `0x4b0b60`, name absent, type absent, AR absent, AP absent, FR not applicable, FP not applicable. `0x617ae8`: data value `0x494c10`; `0x617aec`: data value `0x494c30`; no cell may be renamed, retyped, recommented, or rewritten. The corresponding function dependencies are independently protected at the exact Section 16 inbound sets: `0x494c10` has 47 total (one code plus 46 data), while `0x494c30` has 48 total (two code plus 46 data). |
| P04 helper 0x498c00 | function `[0x498c00,0x498c0f)`, name `TextEditControlPane_SetEditActiveState`, type `void __thiscall(TextEditControlPane *this, bool active, bool selectAll)`, AR absent, AP absent, FR exact existing forwarding text, FP absent, body SHA `C0589B5FA65CE4C5CE681018178E3AFE28B513AC595EFF38F080B204755F1A14`; callers `0x4b0b47,0x545568,0x587d38,0x587faa`. All fields are protected. |
| P05 helper 0x498d90 | function `[0x498d90,0x498da8)`, name `TextEditControlPane_HandleKeyOrTextEvent`, type `bool __thiscall(TextEditControlPane *this, struct Event *event)`, AR absent, AP absent, FR exact existing forwarding text, FP absent, body SHA `BE659DB0C027D6667FB53AF1368317708AE388EE0CF5D52B6F92DAD6BC89A379`; code xref `0x4b0b83`, data xrefs `0x618170,0x618214`. All fields are protected. |
| P06 construction/types | allocation size 0x114 and vptr writes at `0x4accd3,0x4accd9,0x4acce3` remain; `TextEditControlPane` size 0x114, `ControlPane` size 0x108, and `Event` size 0x110 remain; no base type/member/function/data boundary may be changed. |

Collision preflight must show no function/type collision for all five proposed names before I01/I02/I05/I08/I11. Because every action is supervisor-owned, B010 recommends no save policy; the supervisor's Gate 2B transaction/rollback discipline is authoritative outside this report.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. All source-bearing behavior is exact enough for formal blocks.
- [UID:00004T] formal CPP replacement at source position 5; formal H remains exactly blank because this private class is anonymous and must not enter `ExchangeDialog.h`:

```cpp
#include "../controls/TextEditControlPane.h"
#include "../core/Event.h"

namespace
{
class ExchangeMoneyEditControlPane : public TextEditControlPane
{
public:
    ExchangeMoneyEditControlPane(const RectBounds &bounds,
                                 const wchar_t *initialText)
        : TextEditControlPane(initialText, true, 128, 0, &bounds,
                              false, false, false, false, 1.0f, true)
    {
    }

    virtual bool HandleKeyOrTextEvent(Event *event);

protected:
    virtual void Activate();
};
}

[[CHILDREN]]
```

- [UID:000340] formal CPP replacement at source position 10; formal H remains blank because the declaration is in UID00004T:

```cpp
void ExchangeMoneyEditControlPane::Activate()
{
    SetEditActiveState(true, true);
    TextEditControlPane::Activate();
}
```

- [UID:000341] formal CPP replacement at source position 20; formal H remains blank:

```cpp
bool ExchangeMoneyEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type != kEventTextInput ||
        event->m_payload.m_text.m_length != 1)
        return false;

    const wchar_t inputCharacter = event->m_payload.m_text.m_text[0];
    if (inputCharacter < L'0' || inputCharacter > L'9')
        return false;

    TextEditControlPane::HandleKeyOrTextEvent(event);
    return true;
}
```

- [UID:0003N6] formal CPP; formal H remains blank because UID000038 already declares the protected virtual:

```cpp
void ControlPane::Deactivate()
{
    if (m_controlActive)
    {
        m_controlActive = false;
        InvalidateRect(&m_visibleBounds);
    }
}
```

- [UID:0003N7] formal CPP; formal H remains blank for the same reason:

```cpp
void ControlPane::Activate()
{
    if (!m_controlActive)
    {
        m_controlActive = true;
        InvalidateRect(&m_visibleBounds);
    }
}
```

- Runtime preservation: each block follows exact branch/call/tail semantics. The digit wrapper intentionally ignores the inherited helper return and returns true after forwarding.
- Source shape: ordinary inheritance, file-local private class, inline constructor, protected virtual override, named Event fields, and state-transition methods match plausible Visual C++ era source rather than raw offsets.
- Third-party import: not applicable; no `third_party_embeds/` directive is permitted for this project-owned UI source.

## Final Recommendation

- The accepted callbacks applied the target, class, sibling, and two inherited-base formal blocks exactly as supplied and updated metadata, source order, evidence, history, file inventory, and UID0003N6's 47-total xref prose without pruning existing valid detail.
- Retain target owner/emitter UID00004T, class owner/emitter UID0000J9, base owner/emitter UID000038, and vtable owner/emitter UID00004T.
- Keep padding and compiler-emitted vtable data non-emitting. Create no new by-* page or source file.
- The exact manual coverage and IDA handoffs remain supervisor-owned and independently gated. Report execution/archive occurrence remains authoritative only from current path and validator-owned lifecycle metadata.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md`.
- Callback applied the Section 22 target CPP; H remains blank; metadata is `COMPLETION:94`, `CONFIDENCE:95`, `EMITTER_POSITION_OPTIONAL:10`.
- Keep `CANONICAL_OWNER:00004T`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004T`.
- Exact bytes/hash, sole vtable xref, helper/tail behavior, slot proof, padding boundaries, void-return rationale, source placement/order, and support links are callback-applied.
- `OnActivate`, integer return, inherited `OnActivate`, and stable-empty-marker assumptions are historicalized with their former rationale and rejection evidence retained.

## Recommended Support Doc Changes

- `by-class/ExchangeMoneyEditControlPane.md` UID00004T callback-applied the complete anonymous class CPP/constructor/declarations, blank-H proof, layout/constructor/vtable evidence, source position 5, and 93/95.
- `by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md` UID000341 callback-applied exact Event-based CPP, historical raw model, position 20, and 94/95.
- `by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md` UID0003N6 has callback-applied exact CPP, H-already-present proof, 92/94, and command-255705-validated lines 89/95 stating `47 total: one code xref 0x00580639 plus the 46 listed data refs`. `by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md` UID0003N7 remains complete and correct at 48 total refs and 92/94.
- `by-class/ControlPane.md` UID000038 received the dependency/readback note while retaining 91/93 and its existing formal H unchanged.
- `by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md` UID0003BK now links exact cells/method identities at 90/95 while CPP/H remain blank as compiler-emitted data.
- `by-file/ExchangeDialog.md` UID0000J9 historicalizes the stale generated inventory, records the complete money-edit grouping/order/dependency facts, and scores 92/92.

## Score And Metadata Recommendation

- UID000340 is callback-applied at 94/95. Not higher because original private-class spelling and rebuilt-binary comparison remain absent; not lower because behavior/slot/owner/source/CPP are exact.
- UID00004T is callback-applied at 93/95. Layout, constructor, declarations, children, and file locality are closed; original class spelling remains inferred.
- UID000341 is callback-applied at 94/95. Event layout and control flow are exact; original member spelling is inferred from the accepted Event model.
- UID0003N6 and UID0003N7 retain 92/94. Source bodies, slot population, and exact xref totals are closed: UID0003N6 is validated at 47 and UID0003N7 remains correct at 48. Broader original naming proof remains unavailable.
- UID0003BK is callback-applied at 90/95. Exact data is known; compiler-emitted content remains intentionally non-source.
- UID0000J9 is callback-applied at 92/92. File placement and this family close; exact historical filename and whole-module rebuilt-binary comparison remain inferential limits.
- UID000038 remains 91/93 because the required declaration/fields already exist and this assignment changes only dependency prose.
- Metadata owners/emitters/reconstructable states remain unchanged. Positions become class 5, target 10, sibling 20.

## Open Questions With Attempted Resolution

- Was the method `OnActivate` and integer-returning? Resolved no: exact slot alignment and existing base declaration establish `void Activate()`; EAX is implementation residue.
- Was the tail target a TextEditControlPane-specific method? Resolved as inherited `TextEditControlPane::Activate()` source syntax whose implementation is ControlPane's `0x00494c30`.
- Does the class require a header or fields? Resolved no: anonymous RTTI and exact base-sized allocation support a file-local, fieldless subclass.
- Why did empty-emitter reporting persist? Resolved as a historical unstable/generated observation. Dated stable output emits the UID but exposes source-order/incomplete-class/wrong-API defects.
- Is sibling input a generic key event? Resolved no: exact Event offsets and constants make it one-character UTF-16 text input restricted to decimal digits.
- Remaining uncertainty is limited to stripped original private spellings and absent rebuilt-binary comparison. Neither blocks a human source recommendation; both cap scores below 100.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- `by-memory/-coverage-report.md`: UID000340, UID000341, UID0003N6, UID0003N7, and UID0003BK rows were absent in the inspected current file. Insert under their respective owner/range groupings:

`- [UID:000340][0x004b0b40-0x004b0b54 ExchangeMoneyEditControlPane Activation Helper](by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md) 0x004b0b40-0x004b0b54 | method | ExchangeMoneyEditControlPane::Activate : reconstructable : 94% : very-strong : Exact activation override enables edit/select-all state and delegates to inherited ControlPane activation; vtable ownership, source placement, padding, formal source, and dependencies are closed.`

`- [UID:000341][0x004b0b60-0x004b0b96 ExchangeMoneyEditControlPane Digit Key Handler](by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md) 0x004b0b60-0x004b0b96 | method | ExchangeMoneyEditControlPane::HandleKeyOrTextEvent : reconstructable : 94% : very-strong : Exact one-character UTF-16 decimal text-input filter and inherited forwarding behavior with complete Event-based formal source.`

`- [UID:0003N6][0x00494c10-0x00494c2a ControlPane Deactivate](by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md) 0x00494c10-0x00494c2a | method | ControlPane::Deactivate : reconstructable : 92% : very-strong : Clears active state and invalidates inherited visible bounds only on transition; exact base slot and complete inbound reference inventory documented.`

`- [UID:0003N7][0x00494c30-0x00494c4a ControlPane Activate](by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) 0x00494c30-0x00494c4a | method | ControlPane::Activate : reconstructable : 92% : very-strong : Sets active state and invalidates inherited visible bounds only on transition; exact base/derived tail route and complete inbound reference inventory documented.`

`- [UID:0003BK][0x0061a260-0x0061a304 ExchangeMoneyEditControlPane Vtable Data](by-memory/0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md) 0x0061a260-0x0061a304 | vtable/rtti data | ExchangeMoneyEditControlPane compiler metadata : reconstructable : 90% : very-strong : Exact anonymous RTTI and three-vtable island with activation and decimal-event override cell identities; compiler-emitted and intentionally blank formal source.`

- `by-class/-coverage-report.md`: replace the current UID00004T 82% row with:

`- [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md) : reconstructable : 93% : very-strong : Complete file-local 0x114 TextEditControlPane-derived money editor declaration, inline constructor contract, exact Activate and decimal text-input overrides, three-vtable/RTTI ownership, formal source order, and ExchangeDialog.cpp route.`

- `by-file/-coverage-report.md`: replace the current UID0000J9 86% row with:

`- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) : reconstructable : 92% : very-strong : Player exchange dialog compilation unit with complete class/private-control inventory, including the anonymous ExchangeMoneyEditControlPane declaration, exact activation and decimal-event source, inherited ControlPane dependency closure, stable generated module route, packet/control behavior, resources, globals, and compiler metadata.`

- B010 must not apply these manual coverage changes. Validator-owned `auto-generated/-ag-*` files receive no manual row text.

## Follow-Up Actions

- Supervisor: perform fresh exact-artifact Gate 1 and Gate 2A on this callback-complete report and UID0003N6 correction.
- Supervisor: apply C340-037 through C340-039 manual coverage and C340-040 through C340-045 IDA actions/protections only through their respective supervisor gates.
- A-agent actions: none.
- B010 future research: none for this assignment unless a fresh supervisor gate identifies an exact same-report defect; do not start a new target before supervisor disposition.

## Confidence

- Recommendation confidence: 95 for behavior/owner/source route/order and the corrected literal Gate 2B prestates; 92 for exact source-facing private-class spellings.
- Score confidence: strong. The binary and ordinary-document xref sets now agree at 47 for Deactivate and 48 for Activate; C340-017 is checked/applied. Historical-name/rebuilt-binary limits prevent unjustified 100 scores.
- Remaining uncertainty: original private class/method token spelling and exact binary equivalence of future compiled reconstruction only; the UID0003N6 numeric prose repair is deterministic work, not research uncertainty.

## Validator Results

- Scoped callback receipts, all from `source-3/project-documentation`, all exit 0 and `ok:1`: UID000340 command `000000025565` at `2026-08-17T16:25:57-04:00`; UID00004T `000000025570` at `2026-08-17T16:26:54-04:00`; UID000341 `000000025572` at `2026-08-17T16:27:59-04:00`; UID0003N6 `000000025576` at `2026-08-17T16:28:52-04:00`; UID0003N7 `000000025578` at `2026-08-17T16:29:42-04:00`; UID000038 `000000025582` at `2026-08-17T16:30:17-04:00`; UID0003BK `000000025585` at `2026-08-17T16:31:32-04:00`.
- Initial owning waited refresh receipt: `python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240 --wait-generated`, command `000000025589`, timestamp/header refresh `2026-08-17T16:32:25-04:00`, exit 0, `ok:1`. A final by-file stale-prose scan then found active historical labels; after their ordinary-doc correction the same waited command ran as `000000025590` at `2026-08-17T16:44:20-04:00`, exit 0, `ok:1`, `generated_refresh: completed`. Command 25590 is the callback-fresh physical snapshot.
- Command 25590 reported validator-owned side effects: generated metadata/header refreshes, autogen registry rebuild, projected completion-stats update, and research-tracker update. B010 did not edit those generated, registry, stats, or tracker files directly.
- C340-017 scoped receipt: `python .\tools\validator.py --mode file --file by-memory\0x00494c10-0x00494c2a.ControlPaneDeactivate.md --apply --queue-timeout 240`, command `000000025705`, timestamp `2026-08-17T18:23:27-04:00`, exit 0, `ok:1`, generated refresh deferred. Reported side effects were UID0003N7 link insertion/reference-index addition, projected-stats update, and missing-ref warning for pre-existing UID0003J8; B010 did not hand-edit validator-owned state.
- Post-validation physical reread: UID0003N6 is SHA256 `F365232B2772A4A5D230454B6470BCAE1E18DFF6A14474492D34840EE2E9D7D2`, 7,337 bytes, 110 lines. Lines 89/95 each say 47 total; line 95 contains exactly one code address plus 46 data addresses; metadata remains 92/94 and the formal `void ControlPane::Deactivate()` body is unchanged. Deferred generated output subsequently carried command 255705: `ControlPane.cpp` SHA256 `666FB060BA2D9C55F2A5ECFB00B5329AB8B9D89B9489364683283AADD24216C9`, 2,565 bytes, 83 lines, with the exact Deactivate body once at line 62.
- Intermediate known diagnostics were validator registry references, not target-content failures: UID00004T initially reported missing UID0003BK before that page's scoped registration; UID0003N6 initially reported UID0003N7 and pre-existing UID0003J8; UID0003N7 reported pre-existing UID0003J8; UID000038 reported pre-existing UID0003J8/UID0003J9. UID0003BK and UID0003N7 were subsequently registered by their scoped commands; B010 did not edit validator-owned registry state.
- Generated physical readback at command 25590: `NexusTK/ui/dialogs/ExchangeDialog.cpp` is 24,724 bytes, 656 lines, SHA256 `F3D72F46E24462B1E53FA72D09F3E725B1F30F3A0D55043F126AEB1B34BCA898`; private class line 13 precedes target line 31 and sibling line 38, each definition and expected body sequence occurs exactly once, stale money-edit `OnActivate`/`OnKeyEvent`/`KeyEvent`/`CommitCurrentEditText` names are absent, and UID000340 has no empty marker. The sole empty marker in that module is the intentional non-source UID0003BK vtable-data item. The unrelated existing `ExchangeDialog::OnKeyEvent(KeyEvent *)` at lines 452-454 is outside the money-edit class.
- `NexusTK/ui/dialogs/ExchangeDialog.h` is absent as required. Command-25590 `NexusTK/ui/core/ControlPane.cpp` is 2,567 bytes, 83 lines, SHA256 `216BAF5924F789EAE5B8AC145B4FF187155EF12BEF5048A8470C3D084C5F9444`; exact UID0003N6/UID0003N7 definitions occur once at lines 62/72. `ControlPane.h` is 1,547 bytes, 54 lines, SHA256 `AECB390BEC4E07BEE292E09BECC157AAD624339D26B50BFAFB15237DF8C029D7`; protected declarations occur once at lines 37/38.

## Changed Files

- Report updated additively: `tools/leaser/Agents/Agent-B010/research/000340-ExchangeMoneyEditControlPaneActivationHelper-empty-emitter-source-quality.md`.
- Dated callback-time ordinary by-* identities: UID000340 `FBAC5514264380CD6F4EB05917CDE7DD80A90A7C261988C065657ABD32E00ED3` (8,705 bytes, 95 lines); UID00004T `479A58E70F7B5CB20CB06DBF04A081722C0E01ACB7DBAE664AFA5BE95D8BC51E` (20,808 bytes, 144 lines); UID000341 `1F4E011F7DC04259A6C01BACB8D818E4B4606F8AF27E11C83988C4C7EA9F302D` (7,970 bytes, 102 lines); UID0003N6 `B1AE3C16EA6BEF544666F1DEDD0BD115205FEB6543F0728CA9489B7609B6E4F3` (7,155 bytes, 110 lines); UID0003N7 `84A931777F837154E50FF85AE9F0BB96C62D52A5E6592A433A00FBE666333DC1` (8,058 bytes, 114 lines); UID000038 `8E4C7B828FD030C47D087186FA858D037FFEDE72BE1FD611F4ED6A214ACD2507` (40,934 bytes, 277 lines); UID0003BK `9F306056CC6D3AEEACACF3833D2E7972D5CB88BE484E3F19BB9F96B0E89152B2` (11,852 bytes, 132 lines); UID0000J9 `1D1AA03E70989B848E37130C92E03F1F907FAA77C36157D6644BD4E64F63BEFC` (73,628 bytes, 259 lines).
- C340-017 post-validation ordinary identity: UID0003N6 `F365232B2772A4A5D230454B6470BCAE1E18DFF6A14474492D34840EE2E9D7D2` (7,337 bytes, 110 lines); changed active lines are 89 and 95 only, plus validator-inserted UID0003N7 link normalization at line 96.
- Validator-owned generated files changed as a side effect of scoped validation and final command 25590; B010 only read them. No manual coverage, audit, lifecycle, IDA, or other ordinary destination was edited. Validator-owned tracker/stats/registry side effects are recorded above and were not hand-edited.
- Renamed: none.
- Execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. B010 did not invoke any report lifecycle command.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C340-001 | 000340 | Record exact 20-byte activation behavior and tail delegation. | very-strong | bytes/decompile/hash | UID000340 Behavior | incorporate | applied |
| [x] | C340-002 | 000340 | Historicalize integer-return and `OnActivate` interpretation. | very-strong | vtable/base slot/type | UID000340 Historical assumptions | historicalize | applied |
| [x] | C340-003 | 000340 | Set source identity to `void ExchangeMoneyEditControlPane::Activate()`. | very-strong | slot 0x61a2c0/base 0x617aec | UID000340 Status/Identity | incorporate | applied |
| [x] | C340-004 | 000340 | Replace target formal CPP with exact Activate body; H remains blank. | very-strong | exact instructions/control flow | UID000340 CPP/H | incorporate | applied |
| [x] | C340-005 | 000340 | Set emitter position 10 and score 94/95. | strong | class/source order/evidence closure | UID000340 metadata | incorporate | applied |
| [x] | C340-006 | 000340 | Preserve exact range, padding, hash, xref, and negative evidence. | very-strong | live bounded MCP | UID000340 Evidence | incorporate | applied |
| [x] | C340-007 | 00004T | Document exact 0x114 no-new-field derived layout and anonymous source scope. | very-strong | constructor/type/vtable RTTI | UID00004T Layout/Ownership | incorporate | applied |
| [x] | C340-008 | 00004T | Replace forward declaration with full derived class/constructor/override CPP. | strong | constructor contract and slots | UID00004T CPP | incorporate | applied |
| [x] | C340-009 | 00004T | Keep H blank because class is file-local; set position 5 and 93/95. | strong | anonymous RTTI/source route | UID00004T H/metadata | incorporate | applied |
| [x] | C340-010 | 000341 | Record exact one-character decimal text-input filter behavior. | very-strong | bytes/decompile/Event layout | UID000341 Behavior | incorporate | applied |
| [x] | C340-011 | 000341 | Replace formal CPP with `HandleKeyOrTextEvent(Event *)`; H blank. | very-strong | helper/type/event offsets | UID000341 CPP/H | incorporate | applied |
| [x] | C340-012 | 000341 | Set position 20 and score 94/95; historicalize raw KeyEvent model. | strong | source order/evidence closure | UID000341 metadata/history | historicalize | applied |
| [x] | C340-013 | 0003N6 | Record exact clear-if-set/invalidate behavior. | very-strong | body/xrefs/base vtable | UID0003N6 Behavior | incorporate | applied |
| [x] | C340-014 | 0003N6 | Add exact `void ControlPane::Deactivate()` formal CPP; H blank. | very-strong | H declaration/body | UID0003N6 CPP/H | incorporate | applied |
| [x] | C340-015 | 0003N7 | Record exact set-if-clear/invalidate behavior. | very-strong | body/xrefs/base vtable | UID0003N7 Behavior | incorporate | applied |
| [x] | C340-016 | 0003N7 | Add exact `void ControlPane::Activate()` formal CPP; H blank. | very-strong | H declaration/body | UID0003N7 CPP/H | incorporate | applied |
| [x] | C340-017 | 0003N6 | Correct UID0003N6 to 47 total inbound refs (one code plus the 46 listed data refs) while preserving score 92/94. | strong | fresh Gate 2B count and exact set | UID0003N6 metadata/evidence | incorporate | applied |
| [x] | C340-018 | 0003N7 | Set score 92/94 and preserve 48 inbound refs. | strong | complete xref inventory | UID0003N7 metadata/evidence | incorporate | applied |
| [x] | C340-019 | 000038 | Preserve existing protected Activate/Deactivate declarations and field contract. | very-strong | current formal H | UID000038 dependency note | already-present | already-present |
| [x] | C340-020 | 0000J9 | Replace stale class-per-file inventory with dated stable ExchangeDialog.cpp and intentional absent-H disposition. | very-strong | dated generated readback | UID0000J9 Status/history | historicalize | applied |
| [x] | C340-021 | 0000J9 | Add complete money-edit class/child/base dependency inventory and set 92/92. | strong | source family/constructor/vtables | UID0000J9 inventory/metadata | incorporate | applied |
| [x] | C340-022 | 0003BK | Link exact Activate/digit-filter cells and score 90/95. | very-strong | cell values/xrefs | UID0003BK slot inventory/metadata | incorporate | applied |
| [x] | C340-023 | 000340 | Historicalize former empty-marker observation; stable route exists. | very-strong | command 25538 physical readback | UID000340 Status/history | historicalize | applied |
| [x] | C340-024 | 0000J9 | Run scoped validators, one waited owner refresh, physical ExchangeDialog.cpp reread, and absent-H verification. | required | workflow contract | callback receipts/report | incorporate | applied |
| [x] | C340-025 | 000340 | Preserve rejected names, return model, standalone file, and no-code alternatives. | strong | negative evidence | UID000340 Historical assumptions | incorporate | applied |
| [x] | C340-026 | 000340 | Preserve 15-byte lead and 12-byte trail `CC` padding facts. | very-strong | exact bytes/boundaries | UID000340 Range | incorporate | applied |
| [x] | C340-027 | 000340 | Link SetEditActiveState and HandleKeyOrTextEvent exact helper contracts. | very-strong | named helper types/comments/callers | UID000340/000341 dependencies | incorporate | applied |
| [x] | C340-028 | 00004T | Record allocation 0x114, full base construction, and three vptr writes. | very-strong | constructor decompile | UID00004T Construction | incorporate | applied |
| [x] | C340-029 | 0000J9 | Keep sole source placement `NexusTK/ui/dialogs/ExchangeDialog.cpp`. | very-strong | family and generated route | UID0000J9 Source placement | already-present | already-present |
| [x] | C340-030 | 000340 | Apply target 94/95 score rationale. | strong | blockers resolved | UID000340 metadata | incorporate | applied |
| [x] | C340-031 | 00004T | Apply class 93/95 score rationale. | strong | declaration/layout/children closed | UID00004T metadata | incorporate | applied |
| [x] | C340-032 | 000341 | Apply sibling 94/95 score rationale. | strong | exact behavior/source closed | UID000341 metadata | incorporate | applied |
| [x] | C340-033 | 0000J9 | Apply file 92/92 score rationale. | strong | route/inventory closure | UID0000J9 metadata | incorporate | applied |
| [x] | C340-034 | 0003N6 | Apply Deactivate 92/94 score rationale. | strong | source body and xrefs closed | UID0003N6 metadata | incorporate | applied |
| [x] | C340-035 | 0003N7 | Apply Activate 92/94 score rationale. | strong | source body and xrefs closed | UID0003N7 metadata | incorporate | applied |
| [x] | C340-036 | 0003BK | Apply vtable 90/95 score rationale. | strong | exact cell/source identities | UID0003BK metadata | incorporate | applied |
| [ ] | C340-037 | 000340 | Insert exact missing by-memory manual coverage rows for UIDs 000340, 000341, 0003N6, 0003N7, and 0003BK. | strong | manual report absence | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C340-038 | 00004T | Replace stale 82% class manual coverage row. | strong | current class closure | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C340-039 | 0000J9 | Replace stale 86% file manual coverage row. | strong | current file closure | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | C340-040 | 00004T | Supervisor declares exact 0x114 derived UDT and verifies member/size readback. | strong | type/layout/constructor | IDA Gate 2B I01 | incorporate | proposed |
| [ ] | C340-041 | 000340 | Supervisor applies target rename, void type, and FR in ordered stages. | very-strong | target evidence | IDA Gate 2B I02-I04 | incorporate | proposed |
| [ ] | C340-042 | 000341 | Supervisor applies sibling rename, bool/Event type, and FR. | very-strong | sibling evidence | IDA Gate 2B I05-I07 | incorporate | proposed |
| [ ] | C340-043 | 0003N6 | Supervisor applies base Deactivate rename, void type, and FR. | very-strong | base evidence | IDA Gate 2B I08-I10 | incorporate | proposed |
| [ ] | C340-044 | 0003N7 | Supervisor applies base Activate rename, void type, and FR. | very-strong | base evidence | IDA Gate 2B I11-I13 | incorporate | proposed |
| [ ] | C340-045 | 000340 | Protect ranges, bytes, frames, xrefs, vtable cells, helpers, and unrelated padding. | very-strong | exact manifests below | IDA Gate 2B P01-P06 | reject-invalid | proposed |
| [x] | C340-046 | 000340 | Preserve supervisor-only coverage/IDA/lifecycle boundary; B010 never executes report. | certain | workflow/skill | report lifecycle boundary | not-applicable | already-present |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000025746","destination_path":"executed-b-agent-research/B010/000340-ExchangeMoneyEditControlPaneActivationHelper-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/000340-ExchangeMoneyEditControlPaneActivationHelper-empty-emitter-source-quality.md","timestamp":"2026-08-17T19:02:47-04:00","uid":"000340"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
