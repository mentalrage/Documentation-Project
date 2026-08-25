# UID000401 SayToUserMessageInputPane Methods Source Quality
** TARGET-REPORT-UID:000401 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Retain [UID:000401] as the reconstructable class-owned constructor/submit child for legacy `SayToUserMessageInputPane`, raise it from `86/90` to `94/95`, and retain owner/emitter [UID:0000C6].
- Replace the target formal CPP with the exact source-shaped constructor and submit implementation in Section 22. Keep target H blank because the declaration belongs to the class owner.
- Move [UID:0000C6] class declaration from CPP to H, omit an explicit derived destructor declaration so the inherited virtual destructor generates the observed shared/folded compiler wrapper, and retain `[[CHILDREN]]` alone in class CPP.
- Repair [UID:000077] `LineInputPane` H with a distinct inline default `virtual void OnSubmitInput() {}` after `OnNoOpInputPaneSlot()`. Primary `+0x44 -> 0x004f2790` and primary `+0x48 -> 0x0041b6a0` are distinct; UID000401 overrides `+0x48 -> 0x005b1640`.
- Keep sibling [UID:000402] ownerless, non-reconstructable, and non-emitting. Its raw body is source-shaped packet logic, but exhaustive caller, xref, pointer, immediate, and vtable checks found no route.
- Generated/tracker identities below are dated research snapshots and do not establish current shared-artifact state.

## Supporting Research

- Mandatory live MCP was available. Dated snapshot: database `supervisor-uid0004HB-gate2b-20260813T1105Z`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `runtime_attestation` returned `ok:true` at `2026-08-13T12:07:42.892954+00:00`.
- Additive Gate 1 schema recheck at `2026-08-13T14:01:34Z` used read-only canonical session `supervisor-uid00047Q-rollback-20260813T135200Z`; `server_health` returned `status:ok` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Current `declare_type`, `type_inspect`, `type_query`, `rename`, `set_type`, `stack_frame`, `inspect_items`, and `get_comments` schemas were reread before refining A00/A02/A03/A08-A10.
- Same-report Gate 2B repair snapshot: read-only `idb_list` selected canonical session `supervisor-canonical-uid00047Q-retry1-20260813`; `server_health` returned `status:ok`, `idb_path:E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, image base `0x400000`, Hex-Rays ready, and `auto_analysis_ready:false`. The canonical saved IDB was physically read at SHA256 `352C253DBBB4C4F16FF9ED5D60BDF97ABB670A50DDFE5AFC88F343DE569C6095`, `143207449` bytes, last write `2026-08-13T11:38:46.7255901-04:00`.
- Public read-only `runtime_attestation` at `2026-08-13T15:50:53.561906+00:00` returned `schema_version:1`, `ok:true`, and no errors for that exact returned database and canonical path. The canonical route was listener PID `13936` generation `pid:13936;created:134309934982668433`, redirector PID `19248`, worker PID `27608` generation `pid:27608;created:134311088119129090`, listener manifest SHA256 `D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE`, and worker manifest SHA256 `2E883F9025B9811708B812077B7194021F72F741508E32BEEA1A491A59B23C00`. These identifiers are a dated receipt, not permanent session authority.
- The separately accepted B001 UID00047Q closure saved and independently read back the complete `SayToUserMessageInputPane` UDT and constructor A01-A04 state. This report now treats those exact states as stronger already-present evidence and prohibits downgrade, deletion, redeclaration, or constructor remutation.
- The IDA recommendations depend on a fresh canonical-path, database, and runtime binding; every supervisor-owned action/readback must use the exact returned database identifier.
- Direct IDA evidence covers both methods, padding, raw sibling, callers, inline construction, vtables, frames, globals, prompt data, body hashes, xrefs, and types.
- Documentation checked: target, class/file owners, aggregate/helper, caller UID00047Q, prompt/global, LineInputPane/vtable support, prior B001/B013 reports, generated CPP/H, manual coverage, and tracker.
- B001 aggregate evidence is accepted for split/boundaries and helper no-route facts; its historical MCP-unavailable caveat is superseded by this live pass.
- B013 class evidence is accepted for role/layout/vtables/routes. Its CPP-resident class declaration, `0x230` packet, two conversion buffers, silent range returns, and explicit derived destructor are superseded.
- UID00047Q is accepted as caller terminology/lifetime evidence only, not dedicated UID000401 coverage.

## Target

- UID: `000401`.
- Path: `by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md`.
- Assignment-time tracker: `86/90`, combined `88.0`, reconstructable, zero direct/additional report coverage.
- Gate 2A-verified ordinary target snapshot: SHA256 `9D4511D67C5F74811C2C9681114AC911C678C9F9804DD9F4FA4482D1B1F6B626`, `17645` bytes, `172` lines.
- Additional targets: none. Support pages are listed only where target coherence requires a recommendation.

## Current Target State

- Ordinary target metadata is now `COMPLETION:94`, `CONFIDENCE:95`, owner/emitter `0000C6`, reconstructable true, optional position blank, `Nested:0`; the supervisor reported exact hash verification for all ten ordinary destinations.
- Correct split: constructor `0x005b1570-0x005b1631`, fifteen-byte `0xcc` padding `0x005b1631-0x005b1640`, submit `0x005b1640-0x005b1812`.
- Target formal CPP now contains the accepted one-conversion-buffer, 300-byte-packet implementation. The former two-buffer, zero-initialized `0x230` packet, silent-return, and missing scratch-terminator assumptions are retained only as superseded history.
- Stack proves one `WCHAR[256]` input buffer, one reusable `CHAR[256]` conversion buffer, and one contiguous 300-byte packet.
- Target H remains correctly blank. The class owner now carries the declaration in formal H and `[[CHILDREN]]` alone in formal CPP; generated closure remains separately supervisor-owned and is not inferred from the ordinary documents.
- The canonical IDB now contains the complete size-`0x208` UDT and exact constructor name/type/frame/comment from the accepted B001 closure. Only A05-A10 plus protections P01-P04 remain proposed for this report's Gate 2B handoff; no overall Gate 2 or lifecycle completion is claimed.

## Executive Recommendation

- Accept exact target CPP, class H, and LineInputPane H repairs in Section 22.
- Preserve direct method serialization; do not call UID000402.
- Preserve inherited input lifecycle: Enter invokes primary `+0x48`; Escape/Tab/deferred deletion remain in `LineInputPane::HandleKeyOrTextEvent`. Do not invent a local key/cancel method.
- Ordinary documentation changes are B-agent callback scope; IDA, manual coverage, generated files, and report lifecycle remain supervisor-owned.

## Supervisor Active Recheck

- Supervisor verification must independently establish report quality, ordinary-documentation state, canonical IDA state, manual-coverage state, generated-output state, and validator-owned lifecycle state; this report does not establish those states by itself.
- Re-attest canonical IDB dynamically and dynamically reread shared generated/tracker/manual files.
- Recheck A00-A04 against the exact already-present complete UDT and constructor readback below. Any mismatch stops Gate 2B; an exact match authorizes no action and must not be downgraded, deleted, redeclared, renamed, retyped, or recommmented.
- Preserve constructor stack `promptText@0x18/0x2 wchar_t` and `recipientName@0x130/0x4 const wchar_t *` plus all eight other rows exactly. The formerly proposed current-schema stack edit with `kind=stack`, `name=recipientName`, and `ty=const wchar_t *` is historical and must not be repeated against the already-correct frame.
- Recheck A05-A10 as the only remaining proposed submit/vtable/prompt/raw-helper actions, with separate regular and repeatable comment channels.
- Recheck A08-A10 as three independent item/comment prestates with separate regular and repeatable address-comment channels.
- Recommendations and unchecked proposed rows do not confer implementation credit; each row requires an evidence-backed verification state before lifecycle action.

## Inference Research Guidance Check

- Submit zero-direct-caller state was challenged: exact vtable data xref and inherited `+0x48` dispatch prove liveness.
- Constructor single-call state was challenged: inline legacy construction at `0x005b419b-0x005b41f9` corroborates allocation, base construction, three vtables, recipient copy, and prompt.
- Helper liveness was exhausted through raw disassembly, xrefs, VA/RVA pointers, immediates, vtables, siblings, and source shape; no route exists.
- Compiler range instrumentation was separated from developer source.
- Ownership/source placement was checked against metadata, child order, generated CPP/H, family items, and file conventions.

## Heuristic / Inference Reanalysis And Validation

- Constructor identity is implementation-ready: direct caller supplies selected recipient and inline clone independently corroborates every action; object size is `0x208`.
- `m_recipientName[128]` is proven at `+0x108` after exact `LineInputPane` size `0x108` and a `0x80` wchar copy bound.
- `OnSubmitInput` is preferred over historical `OnSubmit` because inherited Enter dispatch calls primary `+0x48` and UID000401 occupies it.
- Base `+0x48` can be inline empty in H: `0x0041b6a0` is one-byte `retn` with folding/runtime/no-op uses, not standalone source.
- Shared `0x005b7af0` deleting wrapper is compiler output. An implicit derived destructor is the narrowest complete source cause.
- Packet is exactly 300 bytes: `Src` + `destination` + 298 following bytes. `MultiByteStr[256]` is reused for both conversions.
- Every prior score blocker now has an exact repair or evidence-backed non-emitting disposition.

## Evidence Standards Used

- Direct IDA fact: functions, ranges, types, frames, comments, bytes/hashes, xrefs, vtables, UDT/global state, decompilation, raw disassembly.
- Documentation fact: metadata, formal channels, history, generated/manual/tracker snapshots, prior reports.
- Inference: lexical names, inline-empty base submit declaration, implicit destructor source cause, local spelling.
- Strong inference requires agreement among ABI, vtable slot, consumer control flow, stack shape, sibling conventions, and ownership.
- Confidence cap reflects unavailable original symbols/source formatting, not unresolved behavior.

## Evidence Checked

- MCP/raw checks: attestation, inspect/decompile/disasm, frames/comments, boundaries, bytes/hashes, xrefs, pointer/immediate signatures, UDTs, caller/inline clone.
- Docs: UID000401, UID0000C6, UID000077, UID0001XS, UID0000N9, UID0001LY, UID000402, UID00047Q, UID0003JQ, UID0000Q5, generated/manual/tracker, B001/B013 reports.
- Negative checks: no direct submit caller; no helper xref/pointer/immediate/vtable; no target-local key/cancel body; no handwritten target destructor.
- No required bounded MCP check failed. Original private symbols/source remain unavailable but do not block reconstruction.
- By-file exhaustive inventory is not applicable; every item in and adjacent to the exact by-memory range is inventoried.

## Claim And Incorporation Ledger
| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C401-001 | 000401 | Preserve exact constructor, padding, and submit half-open boundaries. | exact | IDA functions, returns, padding bytes | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Covered Ranges | already-present | already-present |
| C401-002 | 000401 | Record base call, three vtable stores, recipient copy, prompt format, and prompt setter. | very-high | constructor decompile | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Evidence | incorporate | applied |
| C401-003 | 000401 | Record direct caller 0x0059edf7 and inline legacy construction 0x005b419b-0x005b41f9. | exact | xrefs and caller decompile | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Cross-References | incorporate | applied |
| C401-004 | 000401 | Record submit liveness through sole data xref 0x0062f744 and zero ordinary callers. | exact | xrefs and vtable readback | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Evidence | incorporate | applied |
| C401-005 | 000401 | Record object size 0x208 and recipient array at +0x108 after LineInputPane size 0x108. | very-high | constructor offset and UDT | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Layout | incorporate | applied |
| C401-006 | 000401 | Record length guard, CopyText bound, password validation, and sanitization. | exact | submit decompile | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Packet Shape | incorporate | applied |
| C401-007 | 000401 | Correct locals to one WCHAR[256], one reusable CHAR[256], and one unsigned char[300]. | exact | submit frame and writes | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Packet Shape | incorporate | applied |
| C401-008 | 000401 | Historicalize silent bounds returns and regenerate compiler checks through fixed-array indexing. | very-high | rangecheckfailure branches | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Evidence and Changes | historicalize | applied |
| C401-009 | 000401 | Record inherited Enter submit and inherited Escape, Tab, deletion, and forwarding. | exact | base handler and vtables | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Input Lifecycle | incorporate | applied |
| C401-010 | 000401 | Record implicit derived destructor source cause and compiler-only shared scalar wrapper. | very-high | wrapper and vtables | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Compiler Artifacts | incorporate | applied |
| C401-011 | 000401 | Preserve UID000402 as no-route sibling and reject synthetic helper calls. | exact | exhaustive negative route evidence | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Negative Evidence | reject-stale | applied |
| C401-012 | 000401 | Route CPP through UID0000C6 to SayInputPanes.cpp and declarations to SayInputPanes.h. | very-high | ownership and generated topology | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Source Placement | incorporate | applied |
| C401-013 | 000401 | Raise target score from 86/90 to 94/95. | high | all blockers resolved | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / metadata and Score Rationale | incorporate | applied |
| C401-014 | 000401 | Preserve owner/emitter 0000C6, true reconstructability, Nested 0, and blank optional position. | exact | current metadata and range | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / metadata | already-present | already-present |
| C401-015 | 000401 | Replace target formal CPP with exact Section 22 definitions. | very-high | direct method evidence | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C401-016 | 000401 | Keep target formal H blank because declarations are class-owned. | exact | emitter structure | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / RECONSTRUCTION_H CODE | already-present | already-present |
| C401-017 | 0000C6 | Move complete class declaration to H with constructor, OnSubmitInput, and recipient array. | very-high | class ABI and generated defect | by-class/SayToUserMessageInputPane.md / RECONSTRUCTION_H CODE | incorporate | applied |
| C401-018 | 0000C6 | Replace class CPP declaration with CHILDREN-only route and omit explicit derived destructor. | very-high | implicit destructor and source order | by-class/SayToUserMessageInputPane.md / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C401-019 | 000077 | Add distinct inline default OnSubmitInput after OnNoOpInputPaneSlot in LineInputPane H. | very-high | +0x44/+0x48 distinction | by-class/LineInputPane.md / RECONSTRUCTION_H CODE and Method Map | incorporate | applied |
| C401-020 | 0001XS | Name base +0x48 inline default OnSubmitInput and link matching UID000401 override. | very-high | exact vtable dwords and dispatch | by-type/by-vtable/InputPaneBaseVtableFamily.md / Key Slots and Evidence | incorporate | applied |
| C401-021 | 0000N9 | Correct topology to H class declaration and namespace-scope CPP child definitions. | very-high | generated physical readback | by-file/SayInputPanes.md / Source Layout | incorporate | applied |
| C401-022 | 0001LY | Reconcile aggregate child summary with target source repair and live MCP evidence. | high | dedicated target pass | by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md / Child Inventory and Changes | incorporate | applied |
| C401-023 | 000402 | Add dated hash/no-route recheck; keep 85/89, NONE, false, blank emitter and formals. | exact | raw disassembly and searches | by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md / Evidence and Changes | incorporate | applied |
| C401-024 | 00047Q | Preserve OnItemActivated terminology and legacy branch relationship without dedicated-target credit. | exact | callsite and current doc | by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md / Evidence | already-present | already-present |
| C401-025 | 0003JQ | Add exact prompt refs to direct constructor and inline legacy construction. | exact | prompt xrefs | by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md / Evidence | incorporate | already-present |
| C401-026 | 0000Q5 | Preserve Socket pointer, zero value, exact comment; add target consumer only if absent. | exact | global/type/value/comments | by-global/g_packetSender.md / Consumer Evidence | already-present | applied |
| C401-027 | 0000N9 | Historicalize dated nested-CPP and missing-H generated defects; require coherent refresh. | exact | generated snapshots | by-file/SayInputPanes.md / Generated Readback | historicalize | applied |
| C401-028 | 000401 | Insert exact 94 percent target row in manual by-memory coverage. | high | dedicated report conclusion | by-memory/-coverage-report.md / UID000401 row | incorporate | proposed |
| C401-029 | 0001LY | Replace stale aggregate manual row with current split/live-evidence wording. | high | current metadata and pass | by-memory/-coverage-report.md / UID0001LY row | incorporate | proposed |
| C401-030 | 000402 | Insert ignored non-emitting 85 percent helper manual row. | exact | metadata and no-route proof | by-memory/-coverage-report.md / UID000402 row | incorporate | proposed |
| C401-031 | 0000C6 | Replace stale class manual row with 93 percent header/layout/source wording. | high | class repair and ABI | by-class/-coverage-report.md / UID0000C6 row | incorporate | proposed |
| C401-032 | 0000N9 | Reconcile file manual row with SayInputPanes.cpp/.h topology and target closure. | high | file scope and expectations | by-file/-coverage-report.md / UID0000N9 row | incorporate | proposed |
| C401-033 | 000401 | Require fresh canonical runtime attestation and returned database binding at Gate 2B. | exact | MCP schema and attestation | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Changes | incorporate | applied |
| C401-034 | 0000C6 | Preserve the already-present complete size-520 SayToUserMessageInputPane UDT at ordinal 1025 with base@0 and m_recipientName@0x108; never downgrade or redeclare it. | exact | fresh canonical type readback and accepted B001 saved state | IDA canonical database / complete UDT | already-present | already-present |
| C401-035 | 000401 | Preserve already-present constructor name SayToUserMessageInputPane__Constructor with no rename. | exact | fresh function readback and accepted B001 saved state | IDA 0x005b1570 / function name | already-present | already-present |
| C401-036 | 000401 | Preserve already-present recipientName stack name/type and complete ten-row constructor frame; issue no stack edit. | exact | fresh full-frame readback and accepted B001 saved state | IDA 0x005b1570 / stack frame | already-present | already-present |
| C401-037 | 000401 | Preserve already-present exact constructor thiscall type with class pointer return and const recipient pointer; issue no type edit. | exact | fresh function/frame readback and accepted B001 saved state | IDA 0x005b1570 / function type | already-present | already-present |
| C401-038 | 000401 | Preserve already-present exact accepted constructor function-regular comment and absent other channels; issue no comment edit. | exact | fresh four-channel comment readback and accepted B001 saved state | IDA 0x005b1570 / function comment | already-present | already-present |
| C401-039 | 000401 | Rename 0x005b1640 with name-only rename pure:true to SayToUserMessageInputPane__OnSubmitInput. | very-high | vtable and dispatch | IDA 0x005b1640 / function name | incorporate | proposed |
| C401-040 | 000401 | Set exact void thiscall submit type with class pointer this. | very-high | vtable ABI | IDA 0x005b1640 / function type | incorporate | proposed |
| C401-041 | 000401 | Set exact submit function-regular comment; preserve other channels absent. | high | exact packet body | IDA 0x005b1640 / function comment | incorporate | proposed |
| C401-042 | 000401 | Set regular address comment at 0x0062f744 for primary +0x48 submit route. | exact | cell value | IDA 0x0062f744 / regular address comment | incorporate | proposed |
| C401-043 | 0003JQ | Set regular address comment at 0x00630a20 for shared legacy prompt. | exact | two xrefs | IDA 0x00630a20 / regular address comment | incorporate | proposed |
| C401-044 | 000402 | Set no-route regular address comment at 0x005b1820 without defining/naming/typing it. | exact | exhaustive negative proof | IDA 0x005b1820 / regular address comment | incorporate | proposed |
| C401-045 | 000401 | Protect constructor, submit, padding, and raw-helper exact hashes/boundaries. | exact | bytes and SHA256 | IDA canonical database / protected ranges | incorporate | proposed |
| C401-046 | 000401 | Protect xrefs, three vtables, shared destructor route, and vtable-window hash. | exact | xrefs and dwords | IDA canonical database / protected routes | incorporate | proposed |
| C401-047 | 0000Q5 | Protect g_packetSender name/type/value/comment and absent repeatable channel. | exact | item/global/comment readback | IDA 0x0067a7ec / protected global | incorporate | proposed |
| C401-048 | 000401 | Inventory constructor as source-authored class method with target CPP. | exact | function and source role | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Function Inventory | incorporate | applied |
| C401-049 | 000401 | Inventory submit as source-authored virtual with target CPP. | exact | function, vtable, body | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Function Inventory | incorporate | applied |
| C401-050 | 000401 | Inventory both adjacent all-CC spans as compiler alignment only. | exact | raw bytes | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Covered Ranges | incorporate | applied |
| C401-051 | 000401 | Record no additional report target and independently identify every support page. | exact | assignment scope | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Changes | not-applicable | excluded-with-reason |
| C401-052 | 000401 | Record third-party import as target-specific not applicable. | exact | first-party method cluster | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Source Placement | not-applicable | excluded-with-reason |
| C401-053 | 000401 | Reconcile B001, B013, and UID00047Q claims as accepted, corrected, or lead-only. | high | report and disk review | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Changes | historicalize | applied |
| C401-056 | 000401 | Scoped-validate target after callback and record receipt/hash. | exact | validator workflow | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / validation | incorporate | applied |
| C401-057 | 0000C6 | Scoped-validate class after callback and record receipt/hash. | exact | validator workflow | by-class/SayToUserMessageInputPane.md / validation | incorporate | applied |
| C401-058 | 000077 | Scoped-validate LineInputPane after callback and record receipt/hash. | exact | validator workflow | by-class/LineInputPane.md / validation | incorporate | applied |
| C401-059 | 0001XS | Scoped-validate vtable family after callback and record receipt/hash. | exact | validator workflow | by-type/by-vtable/InputPaneBaseVtableFamily.md / validation | incorporate | applied |
| C401-060 | 0000N9 | Scoped-validate SayInputPanes file page after callback and record receipt/hash. | exact | validator workflow | by-file/SayInputPanes.md / validation | incorporate | applied |
| C401-061 | 0001LY | Scoped-validate aggregate after callback and record receipt/hash. | exact | validator workflow | by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md / validation | incorporate | applied |
| C401-062 | 000402 | Scoped-validate helper after callback and record receipt/hash. | exact | validator workflow | by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md / validation | incorporate | applied |
| C401-063 | 00047Q | Verify caller remains same-or-greater detail; validate only if changed. | exact | current caller and direct call | by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md / verification | already-present | already-present |
| C401-064 | 0003JQ | Scoped-validate prompt page after callback if changed. | exact | validator workflow | by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md / validation | incorporate | already-present |
| C401-065 | 0000Q5 | Verify global page remains same-or-greater detail; validate only if changed. | exact | current global and IDA | by-global/g_packetSender.md / verification | already-present | applied |
| C401-066 | 0000N9 | Supervisor coherently refreshes and rereads generated CPP/H, tracker, and auto coverage. | exact | generated ownership boundary | auto-generated/NexusTK/social/SayInputPanes.cpp and SayInputPanes.h / supervisor readback | incorporate | proposed |

## Positive Evidence Summary

- Both target methods are exact modeled functions with stable boundaries and source-facing class roles.
- Constructor liveness has a direct call and an independent byte/behavior-equivalent inline construction path.
- Submit liveness has a primary-vtable data xref and inherited Enter dispatch through exact slot `+0x48`.
- Layout, recipient field, packet locals, protocol order, validation, sanitizer, conversion, and send path are direct evidence.
- Existing owner/emitter routing is correct; remaining defects are formal/source placement.
- Vtable slot plus inherited dispatch plus exact body plus sibling conventions strongly support `OnSubmitInput` despite absent symbols.

## IDA MCP Facts

- Fresh canonical `0x005b1570`: `SayToUserMessageInputPane__Constructor`, size `0xc1`, type `SayToUserMessageInputPane *__thiscall(SayToUserMessageInputPane *this, const wchar_t *recipientName)`. Function-regular comment is exactly `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName). Copies recipientName into m_recipientName[128] and sets the legacy direct-message prompt "-> %s: ".`; function-repeatable, address-regular, and address-repeatable channels are absent.
- `0x005b1640`: `sub_5B1640`, size `0x1d2`, type `void __thiscall(WCHAR *this)`. All four comment channels absent.
- Padding `0x005b1631-0x005b1640`: fifteen `0xcc` bytes, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`.
- Padding `0x005b1812-0x005b1820`: fourteen `0xcc` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- Constructor body SHA256 `E3564FA5956BB8CA814AE7593653E1086CF2B4D3405D51205BA2C3F8709CA4BB`; submit body SHA256 `91954E6993446B78C61EE1E972C20EC8AE4216DDDF9AB94E33D4C52FD77FC95A`.
- Fresh constructor frame: `var_118@+0x10/4 LineInputPane *`; `var_114@+0x14/4 _DWORD`; `promptText@+0x18/2 wchar_t`; `var_10@+0x118/4 _DWORD`; `var_C@+0x11c/4 _DWORD`; `var_4@+0x124/4 _DWORD`; `__saved_registers@+0x128/4 _DWORD`; `__return_address@+0x12c/4 _UNKNOWN *`; `recipientName@+0x130/4 const wchar_t *`; `arg_4@+0x134/4 _DWORD`.
- Submit frame: `var_434@+0x4/4 MemoryMan *`; `WideCharStr@+0x8/2 WCHAR`; `Src@+0x208/1 _BYTE`; `destination@+0x209/1 unsigned __int8`; `var_22E@+0x20a/1 _BYTE`; `var_22D@+0x20b/1 _BYTE`; `MultiByteStr@+0x334/0x100 CHAR[256]`; `var_4@+0x434/4 _DWORD`; `__saved_registers@+0x438/4 _DWORD`; `__return_address@+0x43c/4 _UNKNOWN *`.
- Xrefs: constructor code xref `0x0059edf7`; submit data xref `0x0062f744` and zero ordinary callers; raw helper zero xrefs.
- Vtables: primary `0x0062f6fc` with submit cell `0x0062f744 -> 0x005b1640`; secondary `0x0062f74c -> 0x005b7820`; tertiary `0x0062f77c -> 0x005b782b`. Combined 136-byte SHA256 `DF86A1948CB1C9D5A748945E4B49442DAAF8E04459C878FFD225222A827A9B84`.
- Prompt `0x00630a20-0x00630a30`: name `aS_2`, type `const wchar_t`, comments absent, refs `0x005b15ea` and `0x005b41d7`.
- `g_packetSender` `0x0067a7ec`: type `Socket *`, value zero, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, exact existing two-line regular comment, repeatable absent.
- Fresh `type_inspect` returns `SayToUserMessageInputPane` as `exists:true`, declaration `SayToUserMessageInputPane`, size `520` (`0x208`), `is_udt:true`, and exactly two members: `base@0x0`, size `264` (`0x108`), type `LineInputPane`; `m_recipientName@0x108`, size `256`, type `wchar_t[128]`. Case-insensitive exact and suffix-family queries each return this sole row at ordinal `1025`, kind `struct`; the current catalog has `1026` rows, with `MapNamePane` still ordinal `1024` and independently present `NewSayToUserMessageInputPane` at ordinal `1026`. The exact UID000401 type is complete, collision-free, evidence-supported, and protected from downgrade or replacement.
- Raw helper `0x005b1820-0x005b1983`: no modeled function at start, SHA256 `EA7FDA9773D8191720516975C3BA348FDF5F4D02F76FA1B29A4F76AD0F1278CE`, no VA/RVA pointer, immediate, xref, or vtable route.
- Item/comment prestates: `0x0062f744` is data head `0x0062f744`, half-open item `0x0062f744-0x0062f748`, width `4`, name absent, type absent, regular address comment absent, repeatable address comment absent; `0x00630a20` is data head `0x00630a20`, half-open item `0x00630a20-0x00630a30`, width `16`, name `aS_2`, type `const wchar_t`, regular address comment absent, repeatable address comment absent; `0x005b1820` is code head `0x005b1820`, half-open item `0x005b1820-0x005b1821`, width `1`, no modeled function, name absent, type absent, regular address comment absent, repeatable address comment absent.
- Base primary `+0x44 -> 0x004f2790`; `+0x48 -> 0x0041b6a0`. The latter is one-instruction `retn` and not a standalone source body.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| 0x005b1570-0x005b1631 | UID000401 | source constructor | yes | UID0000C6 | recommended 94/95 | exact CPP repair |
| 0x005b1631-0x005b1640 | UID000401 | compiler alignment | no source | UID000401 | included | preserve |
| 0x005b1640-0x005b1812 | UID000401 | virtual OnSubmitInput | yes | UID0000C6 | recommended 94/95 | exact CPP repair |
| 0x005b1812-0x005b1820 | boundary | compiler alignment | no source | none | excluded | protect |
| 0x005b1820-0x005b1983 | UID000402 | retained packet helper clone | false | UID0001LY index | 85/89 | ownerless non-emitting |
| 0x005b7af0-0x005b7b2b | shared compiler wrapper | scalar deleting destructor | compiler-covered | declarations | no target code | no body |
| 0x005b7820 and 0x005b782b | shared compiler adjustors | secondary/tertiary destructor thunks | compiler-covered | class ABI | no target code | no body |
| 0x0062f6fc, 0x0062f74c, 0x0062f77c | compiler vtables | three object views | compiler-covered | UID0000C6 H | evidence only | no handwritten tables |

Totals: two source methods, two padding spans, one no-route helper, three compiler destructor/adjustor entities, and three vtable bases. Every item has a source/no-code and ownership disposition.

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| 0x005b1570 | 0x0059edf7 in UserListPane::OnItemActivated | sole direct legacy construction call |
| constructor source shape | 0x005b419b-0x005b41f9 inline branch | independent legacy construction clone |
| 0x005b1640 | data xref 0x0062f744 | primary +0x48 virtual submit route |
| 0x005b1640 | zero ordinary code callers | expected virtual-only dispatch |
| 0x00630a20 | refs 0x005b15ea and 0x005b41d7 | direct and inline prompt uses |
| 0x005b1820 | zero xrefs/pointers/immediates | retained unreachable helper |
| 0x0062f6fc | stores 0x005b15ca and 0x005b41b1 | primary construction |
| 0x0062f74c | stores 0x005b15d0 and 0x005b41bd | secondary construction |
| 0x0062f77c | stores 0x005b15da and 0x005b41c7 | tertiary construction |
| submit callees | TextLength, CopyText, validator, sanitizer, conversion, byte writer, memcpy, sender | complete pipeline |

## Documentation Evidence And IDA Status

- Target broad behavior/boundaries/routing are valid; packet arrays and range behavior are stale.
- Class role/layout/vtables are valid; formal CPP/H placement and destructor declaration are stale.
- LineInputPane H omits primary `+0x48` submit default despite vtable documentation.
- File routing is broadly correct but retains stale standalone/class-in-CPP topology.
- Dated generated command `000000023100` at `2026-08-13T07:10:45-04:00`: `SayInputPanes.cpp` SHA256 `6A963DA7EFCDE0FEA02F70AA6B9E0109CAB04B22D273B674E34BAF6BF72F7EA6`, `16661` bytes, `530` lines, with nested qualified children; `SayInputPanes.h` SHA256 `F1687AACC9ED37F9A9FFD766EF7B8EAC5B8E6C3E5BA15E08EC4FFBDBEFCA9190`, `1235` bytes, `41` lines, without the class.
- Dated tracker command `000000023102` at `2026-08-13T07:33:07-04:00`: SHA256 `AFC0FC1208E74000D4E82B7F076200E25CFAC74E5EBB2411ED1F301BDF49AA95`, `1723370` bytes, `6780` lines; UID000401 line `1688` at 86/90 and zero reports.
- Dated auto memory coverage command `000000023101` shows UID000401 coded through 0000C6 despite invalid topology. Later gates dynamically reread.

## Ranked Ownership Analysis

### 1. SayToUserMessageInputPane / SayInputPanes
- Evidence for: exact vtables, layout, receiver, submit slot, metadata, family placement, generated route.
- Evidence against: original private symbols absent.
- Decision: accepted; definitions UID000401, declaration UID0000C6, emitter UID0000N9.

### 2. LineInputPane declaration support
- Evidence for: Enter dispatch uses `+0x48`; base slot is no-op; derived target overrides same slot.
- Evidence against: `0x0041b6a0` is folded and has no unique source symbol.
- Decision: inline empty H virtual; no standalone body.

### 3. UID000402 utility ownership
- Evidence for: source-shaped protocol-equivalent body.
- Evidence against: no route and stack ABI disproves class method.
- Decision: reject ownership/emission.

### Proposed new file/grouping, if applicable
- None. Existing `SayInputPanes.cpp/.h` is correct.
- Included: UID000401 and UID0000C6 declaration.
- Rejected: UID000402 and compiler wrapper/adjustors/vtables as handwritten source.
- Placement: existing broad social input-pane module.

## Source Placement

- Definitions: `NexusTK/social/SayInputPanes.cpp` via UID000401 under UID0000C6.
- Declaration: `NexusTK/social/SayInputPanes.h` via UID0000C6 H.
- Base inline default: `NexusTK/ui/InputPanes.h` via UID000077 H.
- Compiler artifacts regenerate from declarations.
- Rejected: standalone `class_SayToUserMessageInputPane.cpp`, UID000402 ownership, `UserPane.cpp`, modern pane source, target H duplication.
- Remaining uncertainty is lexical only.

## Range / Split / Padding / Reclassification Analysis

- Preserve target `0x005b1570-0x005b1812` and constructor/padding/submit split.
- Preserve following fourteen-byte padding outside target.
- Keep UID000402 separate at `0x005b1820-0x005b1983`; do not nest or emit.
- Keep UID0001LY as index/container, not duplicate emitter.
- No new child required.

## Negative Evidence Summary

- Submit is not dead: vtable and inherited dispatch prove liveness.
- Proximity does not absorb UID000402: stack ABI and absent route disprove ownership.
- Inline construction is not a direct constructor xref.
- `___report_rangecheckfailure` is instrumentation.
- Shared deleting wrapper/adjustors are compiler output.
- `g_packetSender` is a dependency, and prompt string is shared evidence.
- Generated "coded" state does not prove valid C++ topology.

## IDA Rename / Type / Comment Recommendations

The IDA recommendations are valid only against a fresh `idb_list`, `server_health`, canonical saved-IDB disk identity, and public `runtime_attestation` result that establishes the exact returned database identifier. A00-A04 are preservation-only already-present checks; only A05-A10 remain proposed actions. Any prestate mismatch forbids mutation.

| ID | Entity | Literal current prestate | Proposed declarative action | Protection and expected readback | Confidence |
| --- | --- | --- | --- | --- | --- |
| A00 | local type `SayToUserMessageInputPane` | `type_inspect`: `exists:true`, declaration `SayToUserMessageInputPane`, size `520`, UDT true, two members: `base@0x0/264 LineInputPane`, `m_recipientName@0x108/256 wchar_t[128]`; exact/family query sole exact row ordinal `1025`, kind `struct`; catalog total `1026` | no change; classify already-present from accepted B001 saved closure | preserve the complete UDT, member names/types/offsets/sizes, ordinal, catalog, and all dependencies exactly; never delete, downgrade, forward-redeclare, or replace | exact |
| A01 | function 0x005b1570 | `SayToUserMessageInputPane__Constructor`; size `0xc1`; exact constructor type below | no change; classify already-present | preserve exact name, range, body hash, caller, xrefs, frame, type, and comments | exact |
| A02 | constructor stack at 0x005b1570 | exact ten-row Frame C0 below, including `promptText@0x18/0x2 wchar_t` and `recipientName@0x130/0x4 const wchar_t *` | no change; classify already-present; do not repeat rename or stack `set_type` | exact complete Frame C0; no row/name/offset/size/type delta | exact |
| A03 | function 0x005b1570 | name `SayToUserMessageInputPane__Constructor`; type `SayToUserMessageInputPane *__thiscall(SayToUserMessageInputPane *this, const wchar_t *recipientName)`; exact Frame C0 | no change; classify already-present; do not repeat function `set_type` | preserve exact type, complete frame, body, range, caller, bytes, comments, and xrefs | exact |
| A04 | function 0x005b1570 | exact accepted function-regular comment `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName). Copies recipientName into m_recipientName[128] and sets the legacy direct-message prompt "-> %s: ".`; function-repeatable and both address channels absent | no change; classify already-present; do not recommment | preserve exact regular text and three absent channels | exact |
| A05 | function 0x005b1640 | sub_5B1640; void __thiscall(WCHAR *this); all four comments absent | `rename` name-only with `pure:true` to SayToUserMessageInputPane__OnSubmitInput | range/body/frame/data xref fixed | very-high |
| A06 | function 0x005b1640 | type from A05; exact ten-row frame in Section 13 | `set_type` to void __thiscall SayToUserMessageInputPane__OnSubmitInput(SayToUserMessageInputPane *this) | exact prototype; physical frame unchanged | very-high |
| A07 | function 0x005b1640 | function regular/repeatable and address regular/repeatable absent | `set_function_comments` regular: Validates and sanitizes entered text, serializes opcode 0x19 with one-byte recipient/message lengths into a 300-byte packet, and sends it through g_packetSender. | exact regular; other channels absent | high |
| A08 | data item 0x0062f744 | head `0x0062f744`; range `0x0062f744-0x0062f748`; width `4`; data true/code false; name absent (`name:""`); type absent (`type:""`); value `0x005b1640`; regular address comment absent (`regular:""`); repeatable address comment absent (`repeatable:""`) | `set_address_comments` regular exactly: `SayToUserMessageInputPane primary +0x48 virtual slot -> SayToUserMessageInputPane::OnSubmitInput().` | same head/range/width/kind/value; name and type remain absent; regular equals exact text; repeatable remains absent | exact |
| A09 | string data item 0x00630a20 | head `0x00630a20`; range `0x00630a20-0x00630a30`; width `16`; data true/code false; name `aS_2`; type `const wchar_t`; regular address comment absent (`regular:""`); repeatable address comment absent (`repeatable:""`) | `set_address_comments` regular exactly: `Legacy direct-message prompt format used by SayToUserMessageInputPane construction and the inline legacy construction branch.` | same head/range/width/kind/name/type/bytes/xrefs; regular equals exact text; repeatable remains absent | exact |
| A10 | code item head 0x005b1820 | head `0x005b1820`; range `0x005b1820-0x005b1821`; width `1`; code true/data false; no modeled function; name absent (`name:""`); type absent (`type:""`); regular address comment absent (`regular:""`); repeatable address comment absent (`repeatable:""`) | `set_address_comments` regular exactly: `Retained no-route stack-argument clone of target-message opcode 0x19 serialization; no caller, pointer, immediate, or vtable route proven as of 2026-08-13; leave without a modeled function and non-emitting.` | same code head/range/width/kind/body; no function; name/type remain absent; regular equals exact text; repeatable remains absent | exact |
| P01 | target ranges | fresh hashes: constructor `E3564FA5956BB8CA814AE7593653E1086CF2B4D3405D51205BA2C3F8709CA4BB`; first padding `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; submit `91954E6993446B78C61EE1E972C20EC8AE4216DDDF9AB94E33D4C52FD77FC95A`; second padding `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; helper `EA7FDA9773D8191720516975C3BA348FDF5F4D02F76FA1B29A4F76AD0F1278CE` | no change; proposed protection | boundaries/bytes/hashes fixed | exact |
| P02 | routes | fresh readback: constructor sole xref `0x0059edf7`; submit sole data xref `0x0062f744` and zero ordinary callers; prompt refs `0x005b15ea` and `0x005b41d7`; helper zero xrefs | no change; proposed protection | counts/addresses fixed | exact |
| P03 | vtables | fresh readback: `0x0062f6fc -> 0x005b7af0`, `0x0062f744 -> 0x005b1640`, `0x0062f74c -> 0x005b7820`, `0x0062f77c -> 0x005b782b`; combined 136-byte SHA256 `DF86A1948CB1C9D5A748945E4B49442DAAF8E04459C878FFD225222A827A9B84` | no change; proposed protection | values/stores/routes/hash fixed | exact |
| P04 | g_packetSender | fresh readback: item `0x0067a7ec-0x0067a7f0`, name `g_packetSender`, type `Socket *`, width `4`, value `0`, bytes SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, exact existing two-line regular comment, repeatable absent | no change; proposed protection | every literal state fixed | exact |

### A00 Deterministic Current-State Preservation Handoff

- Exact already-present criterion: fresh `type_inspect` and exact/family `type_query` must reproduce A00 exactly: ordinal `1025`, declaration `SayToUserMessageInputPane`, kind `struct`, size `520`, UDT true, member count `2`, `base@0x0/264 LineInputPane`, and `m_recipientName@0x108/256 wchar_t[128]`. Current catalog total is `1026`; `MapNamePane` remains ordinal `1024`, and `NewSayToUserMessageInputPane` remains ordinal `1026`.
- Exact disposition: A00 is already present from the separately accepted B001 UID00047Q saved closure. Do not call `declare_type`, delete or replace the type, convert it to an incomplete tag, alter either member, renumber it, or normalize its declaration. The former absence/incomplete-tag protocol was valid only for the pre-B001 snapshot and is superseded by this stronger evidence-supported complete UDT.
- Dependency protection: preserve every type row and ordinal, both constructor and submit state except the explicitly proposed A05-A10 deltas, all target/protected bytes, function boundaries, xrefs, vtable cells, globals, and documentation artifacts. Any A00 mismatch is a pre-action stop for A05-A10, not permission to repair A00 in this report's transaction.

### A02/A03 Already-Present Constructor Handoff

A01-A04 are readback-only. The accepted B001 closure already established the constructor name, complete frame, function type, and comment. Do not repeat the historical rename, stack `set_type`, function `set_type`, or comment operation.

| Stage | Exact no-change `stack_frame(0x005b1570)` and constructor readback |
| --- | --- |
| C0 complete frame | `var_118@0x10/0x4 LineInputPane *`; `var_114@0x14/0x4 _DWORD`; `promptText@0x18/0x2 wchar_t`; `var_10@0x118/0x4 _DWORD`; `var_C@0x11c/0x4 _DWORD`; `var_4@0x124/0x4 _DWORD`; `__saved_registers@0x128/0x4 _DWORD`; `__return_address@0x12c/0x4 _UNKNOWN *`; `recipientName@0x130/0x4 const wchar_t *`; `arg_4@0x134/0x4 _DWORD`. |
| C1 function | Name `SayToUserMessageInputPane__Constructor`; type `SayToUserMessageInputPane *__thiscall(SayToUserMessageInputPane *this, const wchar_t *recipientName)`; range `0x005b1570-0x005b1631`; body SHA256 `E3564FA5956BB8CA814AE7593653E1086CF2B4D3405D51205BA2C3F8709CA4BB`; sole code xref `0x0059edf7`. |
| C2 comments | Function regular exactly `SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName). Copies recipientName into m_recipientName[128] and sets the legacy direct-message prompt "-> %s: ".`; function repeatable, address regular, and address repeatable absent. |

- Exact disposition: classify A01-A04 and C401-035 through C401-038 as already present only when every C0-C2 field matches. Any difference stops before A05. Do not issue an inverse or corrective constructor edit in an uncertain live session.
- The prior current-schema selector evidence remains historical proof of how the saved recipient row was established: stack typing used `kind=stack`, `name=recipientName`, and `ty=const wchar_t *`. It is not authorization to repeat that edit against the already-correct frame.

Removed legacy operational and lifecycle-status material is preserved only in [the inert same-stem companion](000401-SayToUserMessageInputPaneMethods-source-quality-removed.md). The companion is non-authoritative and must never be executed or used as evidence.

## First-Draft C++ Recommendation

- UID000401 target CPP replacement:

```cpp
SayToUserMessageInputPane::SayToUserMessageInputPane(const wchar_t *recipientName)
    : LineInputPane(0)
{
    wchar_t prompt[128];

    wcscpy_s(m_recipientName, _countof(m_recipientName), recipientName);
    swprintf_s(prompt, _countof(prompt), L"-> %s: ", m_recipientName);
    SetPromptText(prompt);
}

void SayToUserMessageInputPane::OnSubmitInput()
{
    if (TextLength() > 0) {
        wchar_t messageText[256];
        char convertedText[256];
        unsigned char packet[0x12c];

        CopyText(messageText, 255);
        ValidateChatInputOrThrowPasswordError(messageText);
        SanitizeWideTextForChat(messageText, wcslen(messageText));

        int packetLength = 0;
        PacketBufferWriteUInt8(0x19, packet + packetLength++);

        const unsigned int recipientLength = WideCharToMultiByte(
            CP_ACP, 0, m_recipientName,
            static_cast<int>(wcslen(m_recipientName)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[recipientLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(recipientLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, recipientLength);
        packetLength += recipientLength;

        const unsigned int messageLength = WideCharToMultiByte(
            CP_ACP, 0, messageText,
            static_cast<int>(wcslen(messageText)),
            convertedText, sizeof(convertedText), 0, 0);
        convertedText[messageLength] = '\0';
        PacketBufferWriteUInt8(
            static_cast<unsigned char>(messageLength),
            packet + packetLength++);
        memcpy(packet + packetLength, convertedText, messageLength);
        packetLength += messageLength;

        packet[packetLength] = 0;
        g_packetSender->QueueAndSendPacket(
            packet, static_cast<short>(packetLength));
    }
}
```

- UID000401 target H remains blank.
- UID0000C6 class CPP replacement:

```cpp
[[CHILDREN]]
```

- UID0000C6 class H replacement:

```cpp
class SayToUserMessageInputPane : public LineInputPane
{
public:
    explicit SayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_recipientName[128];
};
```

- UID000077 H replacement:

```cpp
class Event;
class TextBoxPane;
class TextEditPane;
struct InputKeyEvent;
struct RectBounds;

class LineInputPane : public Pane
{
public:
    LineInputPane(const wchar_t *promptText);
    virtual ~LineInputPane();

    void SetPromptText(const wchar_t *promptText);
    void CopyText(wchar_t *buffer, short maxChars) const;
    short TextLength() const;

    virtual void UpdateChildLayout();
    virtual void AttachChildren();
    virtual void ShowChildren();
    virtual bool HitTestEditChild(int x, int y);
    virtual Pane *GetActiveChild();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool ForwardTextEditEvent(InputKeyEvent *event);
    virtual void OnNoOpInputPaneSlot();
    virtual void OnSubmitInput() {}

protected:
    TextBoxPane *m_promptTextPane;
    TextEditPane *m_textEditPane;
    int m_deferredSubmitPending;
    int m_deferSubmitUntilNextEvent;
};
```

- Fixed arrays/indexed writes regenerate checked-range instrumentation; no explicit range-failure call belongs in source.
- `PacketBufferWriteUInt8` remains for opcode and length bytes; `memcpy` represents the recovered MemoryMan wrapper.
- Third-party import: not applicable.

## Final Recommendation

- Target: 94/95, exact CPP, blank H, unchanged ownership/reconstructability.
- Class: H declaration, children-only CPP, implicit destructor cause, recommended 93/94.
- Base/vtable: separate inline default `OnSubmitInput` at `+0x48`; never rename `+0x44`.
- File/aggregate/helper/caller/prompt/global: only exact Section 25 support facts.
- UID000402 and compiler artifacts remain non-emitting.
- IDA: preserve complete UDT A00 and constructor A01-A04 exactly as already present from accepted B001 saved state; apply only still-needed A05-A10 while enforcing P01-P04. This is not a Gate 2 completion claim.
- No source-quality blocker remains; shared-artifact drift is handled dynamically.

## Recommended Target Doc Changes

- Path: `by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md`.
- Set 94/95; preserve owner/emitter 0000C6, true, Nested 0, blank optional position.
- Replace CPP with Section 22 target code; H blank.
- Add frames/hashes/xrefs, inherited lifecycle, instrumentation, implicit destructor, placement, report history.
- Historicalize two buffers, `0x230` packet, zero initialization, silent bounds returns, explicit destructor, and helper-call assumptions.

## Recommended Support Doc Changes

- `by-class/SayToUserMessageInputPane.md`: declaration to H; CPP `[[CHILDREN]]`; omit explicit destructor; add exact evidence; recommend 93/94.
- `by-class/LineInputPane.md`: preserve all content; add inline default `OnSubmitInput()` and document `+0x48`.
- `by-type/by-vtable/InputPaneBaseVtableFamily.md`: name base `+0x48` and link derived UID000401; distinguish `+0x44`.
- `by-file/SayInputPanes.md`: replace standalone/class-in-CPP assumption with CPP definitions and H declaration; add closure expectations.
- `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`: reconcile target correction/live MCP without duplicate source.
- `by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md`: add current hash/negative route evidence; metadata/formals unchanged.
- `by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md`: preserve caller terminology and verify.
- `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`: add exact two-reference relationship.
- `by-global/g_packetSender.md`: preserve singleton state; add consumer only if absent.

## Score And Metadata Recommendation

- Target changed from 86/90 to current 94/95; non-score metadata is unchanged.
- Class changed from 87/90 to current 93/94; owner/emitter 0000N9 is unchanged.
- LineInputPane remains 93/94. Vtable family changed from 88/93 to current 89/94 after final slot identity.
- File stays 89/90; aggregate 88/91; helper 85/89 false/non-emitting.
- Not higher: original private symbols, local spellings, and formatting unavailable; inline/folded source spelling inferred.
- Not lower: behavior, ABI, frames, layout, routes, protocol, compiler artifacts, placement, and formals independently corroborated.
- Blockers resolved: liveness, helper route, packet arrays, CPP/H split, key/cancel path, destructor, range instrumentation.

## Open Questions With Attempted Resolution

- Method spelling: sibling conventions/vtable/dispatch resolve to `OnSubmitInput`; historical `OnSubmit` retained only as alias history.
- Base default source form: one-byte body, folding uses, slot, and overrides resolve to inline empty virtual; no standalone body.
- Destructor: shared wrapper/base destruction and absent body resolve to implicit derived destructor.
- Helper origin: exhaustive routes absent; retain source-shaped but non-emitting clone.
- Exact local names/formatting remain unknowable without original source but do not block reconstruction or scores.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual by-memory snapshot SHA256 `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`: UID000401/402 absent; UID0001LY stale.
- Replace UID0001LY:
  `- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) : ignored/non-emitting : 88% : very-strong : Exact split/index for legacy, modern, group, and clan target-message panes plus three retained no-route packet-helper clones; source emits only through reconstructable class/method children, while helper clones remain ownerless and non-emitting after live MCP and pointer/immediate rechecks.`
- Insert after UID0001LY:
  `- [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md) : reconstructable : 94% : very-strong : Exact legacy direct-message constructor and virtual OnSubmitInput cluster with corrected ranges/padding, direct plus inline construction routes, primary +0x48 dispatch, +0x108 recipient array, exact one-buffer/300-byte opcode 0x19 serializer, compiler range-check disposition, class-owned H route, and no-route helper exclusion.`
  `- [UID:000402][0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA](by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md) : ignored/non-emitting : 85% : very-strong : Complete retained stack-argument opcode 0x19 serializer clone with exact raw body and boundaries but zero caller/xref/VA/RVA/immediate/vtable route; owner NONE, reconstructable false, blank emitter and CPP/H.`
- Manual by-class snapshot SHA256 `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`. Replace UID0000C6:
  `- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md) : reconstructable : 93% : very-strong : Legacy direct-message pane with exact 0x208 layout, +0x108 recipient array, three-view vtables, implicit destructor source cause, H-owned declaration, UID000401 methods, inherited input lifecycle, and opcode 0x19 behavior.`
- Manual by-file snapshot SHA256 `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`. Replace UID0000N9:
  `- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) : reconstructable : 89% : very-strong : Shared social input-pane module whose declarations emit in SayInputPanes.h and method children emit at namespace scope in SayInputPanes.cpp; UID000401 closes the legacy direct-message source shape while no-route helper clones remain non-emitting.`
- B006 must not edit manual coverage; manual coverage editing and validation are supervisor-owned.

## Follow-Up Actions

- Supervisor-owned scope: report-gate decisions; no-change verification of A00-A04; remaining A05-A10 mutation/readback under P01-P04; manual coverage; generated refresh/readback; and lifecycle handling.
- A-agent: none.
- Future B research: none for UID000401; reopen UID000402 only on new route evidence.
- Generated closure: one class declaration in H, namespace-scope target definitions in CPP, no explicit target destructor definition, no UID000402 emission, no placeholder.

## Confidence

- Recommendation: very high.
- Scores: high.
- Remaining uncertainty: original lexical spelling/formatting only.
- MCP: healthy for all required bounded research.

## Validator Results

- Every changed ordinary destination was validated in file mode with `--apply --no-generated-refresh --queue-timeout 240`; every command exited `0`, reported `ok: 1`, and reported `generated_refresh: skipped`.

| Claim | Destination | Command ID | Timestamp | Exit / ok | Post-edit SHA256 | Warnings / validator-owned normalization |
| --- | --- | --- | --- | --- | --- | --- |
| `C401-056` | `by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md` | `000000023126` | `2026-08-13T10:49:51-04:00` | `0 / 1` | `9D4511D67C5F74811C2C9681114AC911C678C9F9804DD9F4FA4482D1B1F6B626` | Missing-reference warnings for independently tracked UID000402 and UID0003JQ; reference/index and projected-statistics maintenance completed. |
| `C401-057` | `by-class/SayToUserMessageInputPane.md` | `000000023127` | `2026-08-13T10:50:48-04:00` | `0 / 1` | `EE539C1206A4A2FF69BAC2934B8C498CA109798672EB8D7C8EB2FA400570E0B0` | Missing-reference warnings for independently tracked UID000402; reference/index and statistics maintenance completed. |
| `C401-058` | `by-class/LineInputPane.md` | `000000023128` | `2026-08-13T10:51:28-04:00` | `0 / 1` | `D4D0EEE1F3762A52A05A870EB60C454EE92C7D1028D68F4695F0C8520B1DA833` | Existing missing child-reference warnings for UIDs 00035Q, 00035T, 00035U, 00035V, 00035W, 00035X, 00035Z, 000360, 00036D, and 00036E; UID000401 reference/index maintenance completed. |
| `C401-059` | `by-type/by-vtable/InputPaneBaseVtableFamily.md` | `000000023129` | `2026-08-13T10:52:17-04:00` | `0 / 1` | `C6DE6F253B8C86A6AE9319AA8F92615B7B3D5EE72876B5973C4ADDB45C7B0681` | UID000401 reference/index maintenance and projected-statistics reconciliation completed. |
| `C401-060` | `by-file/SayInputPanes.md` | `000000023130` | `2026-08-13T10:52:58-04:00` | `0 / 1` | `D6266E10FE5FF85771247CB2FC29433CAE346A2B35B86C2F840F3BDE0D5F8F55` | Missing-reference warnings for independently tracked UIDs 0003JM, 000402, 0003JQ, 000406, and 0003JR; UID000401/000403 reference/index maintenance completed. |
| `C401-061` | `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md` | `000000023131` | `2026-08-13T10:53:43-04:00` | `0 / 1` | `F0DFCEF849232BBF74F8D60795F2F848BB98D6036A8F97567B7D7EFC4F955D78` | Missing-reference warnings for independently tracked UIDs 000402, 000406, 0003JM, 0003JQ, and 0003JR; UID000401/000403 reference/index maintenance completed. |
| `C401-062` | `by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md` | `000000023132` | `2026-08-13T10:54:22-04:00` | `0 / 1` | `A4F137FF86D46F757A62679D32E047D428D2466D124A770814627676BA6A11A0` | UID000402 mapping, status, metadata, reference/index, and projected-statistics maintenance completed. |
| `C401-065` | `by-global/g_packetSender.md` | `000000023133` | `2026-08-13T10:56:23-04:00` | `0 / 1` | `1CB61AA4257031FE824CDBEAE23F81FC80A5D5B27BFF4603A4FEB526348586B6` | UID000401 link normalization and reference/index/statistics maintenance completed; no validator warning. |

- C401-063 was physically reread unchanged at SHA256 `749AD16BA1D7DC88062F20D0A696893E7C12337334E4C0FA93055EE25EA5588B`, `10627` bytes; no validator was required.
- C401-064 was physically reread unchanged at SHA256 `971F47D6DEA8CA36113A4A1D8E811F39F41E01F7617E7FDFB0BDBB4CEBE491E3`, `5274` bytes; no validator was required.
- The supervisor callback reports exact hash verification of all ten ordinary destinations. This same-report repair ran no validator and makes no Gate 2B, generated-closure, manual-coverage, execution, or lifecycle claim.
- Supervisor still owns coherent generated closure and physical CPP/H/tracker/auto-coverage reread. No validator result is inferred from report state; the receipts above are authoritative for ordinary destinations only.

## Changed Files

- Modified ordinary documentation: `by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md`, `by-class/SayToUserMessageInputPane.md`, `by-class/LineInputPane.md`, `by-type/by-vtable/InputPaneBaseVtableFamily.md`, `by-file/SayInputPanes.md`, `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`, `by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md`, and `by-global/g_packetSender.md`.
- Physically verified unchanged: `by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md` and `by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md`.
- Modified report: this existing report only, for implementation receipts and claim-by-claim tracking.
- Same-report Gate 2B repair: only this report changed from pre-repair SHA256 `B1B1F8D3468A845E2F79B687DF8FD0B2917AB0AEFFD6441C81E56F7B6EA832CD`; ordinary destinations were read-only and unchanged during this repair.
- Validator-owned state/index maintenance occurred through the eight accepted scoped `--apply` commands; B006 did not manually edit validator state, project indexes, or the validation audit ledger.
- Intentionally untouched by this repair: all ordinary by-* destinations, all three manual `-coverage-report.md` files, IDA, generated `SayInputPanes.cpp/.h`, tracker, auto coverage, validation audit ledger, and the inert companion.
- Renamed: none.
- Inert companion: preserves only removed operational and lifecycle-status material, is non-authoritative, must never be executed, and is excluded from validator/report lifecycle handling.
- Execution/archive authority remains supervisor-owned and authoritative only from current path plus validator-owned status/history.
## Implementation Tracking Checklist

Report-readiness requirements:
- [x] The exact current report artifact had supervisor Gate 1 PASS 33/33 at SHA256 `D2B69A18658A3559647A990A9CE3FB8CC4D7198E8BD9D50651B089E3E284C86E` before implementation.
- [x] By-file exhaustive inventory is target-specific not applicable; the by-memory target and every in-range/adjacent item were exhaustively inventoried.
- [x] Every source-bearing or compiler-covered item has behavior, ownership/emitter, source placement, CPP/H or no-code, metadata, destination, ledger, and checklist disposition.
- [x] Generated CPP/H were audited and every target-caused declaration/definition/routing defect has an exact formal repair.
- [x] Target/support docs to update are enumerated in Sections 24-25.
- [x] No additional UID is declared; support pages remain independently identified.
- [x] Current target state and evidence are recorded.
- [x] Ledger has a physical destination and verification state for every claim.
- [x] Metadata/score changes are specified.
- [x] Score-limiting blockers were researched to implementation-ready resolution.
- [x] Owner/emitter/reconstructable decisions are explicit.
- [x] Split/range/helper dispositions are exact.
- [x] Source placement and IDA actions/protections are exact.
- [x] The supervisor-owned Gate 2B IDA handoff has complete prestate, action, protection, and expected-readback detail.
- [x] Formal CPP/H payloads and blank/no-code dispositions are complete.
- [x] Third-party import is target-specific not applicable.
- [x] Exact target/support facts are supplied at report-level detail.
- [x] Historical assumptions and negative evidence are preserved.
- [x] No Wave2/Wave3 artifact controls this target.
- [x] Open questions are resolved or evidence-bounded.
- [x] Validators to run are enumerated and ordinary-destination receipts are recorded.
- [x] Manual/generated supervisor closure text is supplied.

Implementation-verification requirements:
- [ ] Remaining supervisor-owned A05-A10 IDA changes require exact Gate 2B action/readback and saved-state proof; A00-A04 are no-change preservation checks only.
- [x] Every accepted ordinary target/support claim has per-destination `applied`, `already-present`, or `excluded-with-reason` proof.
- [x] Formal CPP/H repairs have channel-specific implementation verification.
- [x] Agent-owned documentation edits have explicit implementation-callback authority.
- [x] Every accepted target/support fact is incorporated without loss.
- [x] Every primary/support UID was independently verified against its destination.
- [x] Ledger/checklist states were updated only after physical verification.
- [x] Metadata/score/owner/emitter/split/CPP/H changes were applied or excluded with reason.
- [x] Historical assumptions and negative evidence are preserved.
- [x] Open questions remain resolved.
- [x] Scoped validators were run and recorded for changed ordinary docs.
- [ ] Generated CPP/H/tracker closure remains supervisor-owned.
- [x] Remaining unapplied accepted items identify exact supervisor-owned boundaries.
- [x] Report body remains lifecycle-neutral; execution/archive truth is deferred to current path and validator-owned history.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C401-001 | 000401 | Preserve exact constructor, padding, and submit half-open boundaries. | exact | IDA functions, returns, padding bytes | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Covered Ranges | already-present | already-present |
| [x] | C401-002 | 000401 | Record base call, three vtable stores, recipient copy, prompt format, and prompt setter. | very-high | constructor decompile | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Evidence | incorporate | applied |
| [x] | C401-003 | 000401 | Record direct caller 0x0059edf7 and inline legacy construction 0x005b419b-0x005b41f9. | exact | xrefs and caller decompile | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Cross-References | incorporate | applied |
| [x] | C401-004 | 000401 | Record submit liveness through sole data xref 0x0062f744 and zero ordinary callers. | exact | xrefs and vtable readback | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Evidence | incorporate | applied |
| [x] | C401-005 | 000401 | Record object size 0x208 and recipient array at +0x108 after LineInputPane size 0x108. | very-high | constructor offset and UDT | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Layout | incorporate | applied |
| [x] | C401-006 | 000401 | Record length guard, CopyText bound, password validation, and sanitization. | exact | submit decompile | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Packet Shape | incorporate | applied |
| [x] | C401-007 | 000401 | Correct locals to one WCHAR[256], one reusable CHAR[256], and one unsigned char[300]. | exact | submit frame and writes | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Packet Shape | incorporate | applied |
| [x] | C401-008 | 000401 | Historicalize silent bounds returns and regenerate compiler checks through fixed-array indexing. | very-high | rangecheckfailure branches | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Evidence and Changes | historicalize | applied |
| [x] | C401-009 | 000401 | Record inherited Enter submit and inherited Escape, Tab, deletion, and forwarding. | exact | base handler and vtables | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Input Lifecycle | incorporate | applied |
| [x] | C401-010 | 000401 | Record implicit derived destructor source cause and compiler-only shared scalar wrapper. | very-high | wrapper and vtables | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Compiler Artifacts | incorporate | applied |
| [x] | C401-011 | 000401 | Preserve UID000402 as no-route sibling and reject synthetic helper calls. | exact | exhaustive negative route evidence | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Negative Evidence | reject-stale | applied |
| [x] | C401-012 | 000401 | Route CPP through UID0000C6 to SayInputPanes.cpp and declarations to SayInputPanes.h. | very-high | ownership and generated topology | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Source Placement | incorporate | applied |
| [x] | C401-013 | 000401 | Raise target score from 86/90 to 94/95. | high | all blockers resolved | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / metadata and Score Rationale | incorporate | applied |
| [x] | C401-014 | 000401 | Preserve owner/emitter 0000C6, true reconstructability, Nested 0, and blank optional position. | exact | current metadata and range | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / metadata | already-present | already-present |
| [x] | C401-015 | 000401 | Replace target formal CPP with exact Section 22 definitions. | very-high | direct method evidence | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C401-016 | 000401 | Keep target formal H blank because declarations are class-owned. | exact | emitter structure | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / RECONSTRUCTION_H CODE | already-present | already-present |
| [x] | C401-017 | 0000C6 | Move complete class declaration to H with constructor, OnSubmitInput, and recipient array. | very-high | class ABI and generated defect | by-class/SayToUserMessageInputPane.md / RECONSTRUCTION_H CODE | incorporate | applied |
| [x] | C401-018 | 0000C6 | Replace class CPP declaration with CHILDREN-only route and omit explicit derived destructor. | very-high | implicit destructor and source order | by-class/SayToUserMessageInputPane.md / RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C401-019 | 000077 | Add distinct inline default OnSubmitInput after OnNoOpInputPaneSlot in LineInputPane H. | very-high | +0x44/+0x48 distinction | by-class/LineInputPane.md / RECONSTRUCTION_H CODE and Method Map | incorporate | applied |
| [x] | C401-020 | 0001XS | Name base +0x48 inline default OnSubmitInput and link matching UID000401 override. | very-high | exact vtable dwords and dispatch | by-type/by-vtable/InputPaneBaseVtableFamily.md / Key Slots and Evidence | incorporate | applied |
| [x] | C401-021 | 0000N9 | Correct topology to H class declaration and namespace-scope CPP child definitions. | very-high | generated physical readback | by-file/SayInputPanes.md / Source Layout | incorporate | applied |
| [x] | C401-022 | 0001LY | Reconcile aggregate child summary with target source repair and live MCP evidence. | high | dedicated target pass | by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md / Child Inventory and Changes | incorporate | applied |
| [x] | C401-023 | 000402 | Add dated hash/no-route recheck; keep 85/89, NONE, false, blank emitter and formals. | exact | raw disassembly and searches | by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md / Evidence and Changes | incorporate | applied |
| [x] | C401-024 | 00047Q | Preserve OnItemActivated terminology and legacy branch relationship without dedicated-target credit. | exact | callsite and current doc | by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md / Evidence | already-present | already-present |
| [x] | C401-025 | 0003JQ | Add exact prompt refs to direct constructor and inline legacy construction. | exact | prompt xrefs | by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md / Evidence | incorporate | already-present |
| [x] | C401-026 | 0000Q5 | Preserve Socket pointer, zero value, exact comment; add target consumer only if absent. | exact | global/type/value/comments | by-global/g_packetSender.md / Consumer Evidence | already-present | applied |
| [x] | C401-027 | 0000N9 | Historicalize dated nested-CPP and missing-H generated defects; require coherent refresh. | exact | generated snapshots | by-file/SayInputPanes.md / Generated Readback | historicalize | applied |
| [ ] | C401-028 | 000401 | Insert exact 94 percent target row in manual by-memory coverage. | high | dedicated report conclusion | by-memory/-coverage-report.md / UID000401 row | incorporate | proposed |
| [ ] | C401-029 | 0001LY | Replace stale aggregate manual row with current split/live-evidence wording. | high | current metadata and pass | by-memory/-coverage-report.md / UID0001LY row | incorporate | proposed |
| [ ] | C401-030 | 000402 | Insert ignored non-emitting 85 percent helper manual row. | exact | metadata and no-route proof | by-memory/-coverage-report.md / UID000402 row | incorporate | proposed |
| [ ] | C401-031 | 0000C6 | Replace stale class manual row with 93 percent header/layout/source wording. | high | class repair and ABI | by-class/-coverage-report.md / UID0000C6 row | incorporate | proposed |
| [ ] | C401-032 | 0000N9 | Reconcile file manual row with SayInputPanes.cpp/.h topology and target closure. | high | file scope and expectations | by-file/-coverage-report.md / UID0000N9 row | incorporate | proposed |
| [x] | C401-033 | 000401 | Require fresh canonical runtime attestation and returned database binding at Gate 2B. | exact | MCP schema and attestation | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Changes | incorporate | applied |
| [x] | C401-034 | 0000C6 | Preserve the already-present complete size-520 SayToUserMessageInputPane UDT at ordinal 1025 with base@0 and m_recipientName@0x108; never downgrade or redeclare it. | exact | fresh canonical type readback and accepted B001 saved state | IDA canonical database / complete UDT | already-present | already-present |
| [x] | C401-035 | 000401 | Preserve already-present constructor name SayToUserMessageInputPane__Constructor with no rename. | exact | fresh function readback and accepted B001 saved state | IDA 0x005b1570 / function name | already-present | already-present |
| [x] | C401-036 | 000401 | Preserve already-present recipientName stack name/type and complete ten-row constructor frame; issue no stack edit. | exact | fresh full-frame readback and accepted B001 saved state | IDA 0x005b1570 / stack frame | already-present | already-present |
| [x] | C401-037 | 000401 | Preserve already-present exact constructor thiscall type with class pointer return and const recipient pointer; issue no type edit. | exact | fresh function/frame readback and accepted B001 saved state | IDA 0x005b1570 / function type | already-present | already-present |
| [x] | C401-038 | 000401 | Preserve already-present exact accepted constructor function-regular comment and absent other channels; issue no comment edit. | exact | fresh four-channel comment readback and accepted B001 saved state | IDA 0x005b1570 / function comment | already-present | already-present |
| [ ] | C401-039 | 000401 | Rename 0x005b1640 with name-only rename pure:true to SayToUserMessageInputPane__OnSubmitInput. | very-high | vtable and dispatch | IDA 0x005b1640 / function name | incorporate | proposed |
| [ ] | C401-040 | 000401 | Set exact void thiscall submit type with class pointer this. | very-high | vtable ABI | IDA 0x005b1640 / function type | incorporate | proposed |
| [ ] | C401-041 | 000401 | Set exact submit function-regular comment; preserve other channels absent. | high | exact packet body | IDA 0x005b1640 / function comment | incorporate | proposed |
| [ ] | C401-042 | 000401 | Set regular address comment at 0x0062f744 for primary +0x48 submit route. | exact | cell value | IDA 0x0062f744 / regular address comment | incorporate | proposed |
| [ ] | C401-043 | 0003JQ | Set regular address comment at 0x00630a20 for shared legacy prompt. | exact | two xrefs | IDA 0x00630a20 / regular address comment | incorporate | proposed |
| [ ] | C401-044 | 000402 | Set no-route regular address comment at 0x005b1820 without defining/naming/typing it. | exact | exhaustive negative proof | IDA 0x005b1820 / regular address comment | incorporate | proposed |
| [ ] | C401-045 | 000401 | Protect constructor, submit, padding, and raw-helper exact hashes/boundaries. | exact | bytes and SHA256 | IDA canonical database / protected ranges | incorporate | proposed |
| [ ] | C401-046 | 000401 | Protect xrefs, three vtables, shared destructor route, and vtable-window hash. | exact | xrefs and dwords | IDA canonical database / protected routes | incorporate | proposed |
| [ ] | C401-047 | 0000Q5 | Protect g_packetSender name/type/value/comment and absent repeatable channel. | exact | item/global/comment readback | IDA 0x0067a7ec / protected global | incorporate | proposed |
| [x] | C401-048 | 000401 | Inventory constructor as source-authored class method with target CPP. | exact | function and source role | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Function Inventory | incorporate | applied |
| [x] | C401-049 | 000401 | Inventory submit as source-authored virtual with target CPP. | exact | function, vtable, body | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Function Inventory | incorporate | applied |
| [x] | C401-050 | 000401 | Inventory both adjacent all-CC spans as compiler alignment only. | exact | raw bytes | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Covered Ranges | incorporate | applied |
| [x] | C401-051 | 000401 | Record no additional report target and independently identify every support page. | exact | assignment scope | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Changes | not-applicable | excluded-with-reason |
| [x] | C401-052 | 000401 | Record third-party import as target-specific not applicable. | exact | first-party method cluster | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Source Placement | not-applicable | excluded-with-reason |
| [x] | C401-053 | 000401 | Reconcile B001, B013, and UID00047Q claims as accepted, corrected, or lead-only. | high | report and disk review | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / Changes | historicalize | applied |
| [x] | C401-056 | 000401 | Scoped-validate target after callback and record receipt/hash. | exact | validator workflow | by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md / validation | incorporate | applied |
| [x] | C401-057 | 0000C6 | Scoped-validate class after callback and record receipt/hash. | exact | validator workflow | by-class/SayToUserMessageInputPane.md / validation | incorporate | applied |
| [x] | C401-058 | 000077 | Scoped-validate LineInputPane after callback and record receipt/hash. | exact | validator workflow | by-class/LineInputPane.md / validation | incorporate | applied |
| [x] | C401-059 | 0001XS | Scoped-validate vtable family after callback and record receipt/hash. | exact | validator workflow | by-type/by-vtable/InputPaneBaseVtableFamily.md / validation | incorporate | applied |
| [x] | C401-060 | 0000N9 | Scoped-validate SayInputPanes file page after callback and record receipt/hash. | exact | validator workflow | by-file/SayInputPanes.md / validation | incorporate | applied |
| [x] | C401-061 | 0001LY | Scoped-validate aggregate after callback and record receipt/hash. | exact | validator workflow | by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md / validation | incorporate | applied |
| [x] | C401-062 | 000402 | Scoped-validate helper after callback and record receipt/hash. | exact | validator workflow | by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md / validation | incorporate | applied |
| [x] | C401-063 | 00047Q | Verify caller remains same-or-greater detail; validate only if changed. | exact | current caller and direct call | by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md / verification | already-present | already-present |
| [x] | C401-064 | 0003JQ | Scoped-validate prompt page after callback if changed. | exact | validator workflow | by-memory/0x00630a18-0x00630a44.DirectWhisperPromptFragments.md / validation | incorporate | already-present |
| [x] | C401-065 | 0000Q5 | Verify global page remains same-or-greater detail; validate only if changed. | exact | current global and IDA | by-global/g_packetSender.md / verification | already-present | applied |
| [ ] | C401-066 | 0000N9 | Supervisor coherently refreshes and rereads generated CPP/H, tracker, and auto coverage. | exact | generated ownership boundary | auto-generated/NexusTK/social/SayInputPanes.cpp and SayInputPanes.h / supervisor readback | incorporate | proposed |

READY_FOR_SUPERVISOR_GATE2A_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000023147","destination_path":"executed-b-agent-research/B006/000401-SayToUserMessageInputPaneMethods-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/000401-SayToUserMessageInputPaneMethods-source-quality.md","timestamp":"2026-08-13T12:13:38-04:00","uid":"000401"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
