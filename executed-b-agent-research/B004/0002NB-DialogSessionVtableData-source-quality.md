** TARGET-REPORT-UID:0002NB **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0002NB DialogSessionVtableData Source Quality Research

## Finalized Report / Current Recommendation

- Current implementation result: UID0002NB was UID-preservingly renamed and widened from historical path `by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md` to current path `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md`. The added dword at `0x00618d2c` is the primary `DialogSession` complete-object locator pointer and is part of the same compiler-emitted RTTI/vtable cluster.
- Final disposition applied: source-declared/generated-binary compiler data. UID0002NB remains owned by [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md) as its direct type/layout authority; both pages are now `RECONSTRUCTABLE:FALSE`, blank-emitter, blank-position, and blank-formal support pages. Human source remains in the `DialogSession`, `DialogInSession`, and `DialogPane` class declarations, not in handwritten vtable, RTTI, adjustor, or deleting-wrapper arrays.
- Completed callback result: the target range/path correction, complete 18/11/2 and 23/11/2 maps, non-emitting aggregate/type/layout synchronization, protected `DialogSession` fields, complete `DialogInSession` declaration, and four missing `DialogPane` virtual declarations are incorporated at report-level detail.
- Current target score: `93/94`, raised from the historical pre-callback `86/90`.
- Confidence: very strong for bytes, range, RTTI/COLs, table extents, slot targets, inheritance, object offsets, store xrefs, compiler disposition, and source file route; strong for the few source-facing spellings inferred from stripped code.

## Supporting Research

- Mandatory live IDA MCP research used database `64c11373`. A fresh `idb_list` at evidence time returned one active adopted NexusTK session with worker PID `21508`; `server_health` returned `status: ok`, imagebase `0x00400000`, and ready auto-analysis, Hex-Rays, and string cache. The session was healthy when the recorded evidence was collected; this report does not assert indefinite later availability.
- A fresh bounded `lookup_funcs(0x0041d6b0)`, `get_bytes(0x0041d6b0,16)`, and `decompile(0x0041d6b0)` closed the last unresolved secondary-table slot: bytes are `32 C0 C2 04 00`, and the function returns false while popping one `Event *` argument. It is the inherited default `bool HandlePacketEvent(Event *)`, not an unknown dialog helper.
- Required executed support report opened: `executed-b-agent-research/B001/000132-dialogsession-stack-source-quality.md`, SHA256 `318AC9C6B97E198BFAC3257C90EC136D2D47F3E5D667D38E2D749E937B4E1289`, 21,401 bytes, 242 lines. Useful finding: UID000132 is a historical overlapping non-emitting split/index; its source-bearing stack helpers belong to `DialogSession`, while the physical range crosses ScreenDimmer, `DialogInSession`, compiler thunks, and a deleting-wrapper head.
- Required executed support report opened: `executed-b-agent-research/B002/00003U-DialogSession-class-source-quality.md`, SHA256 `B1546383CEE7349288042AF7BFCEFA27AD0106B3532596A803BFA2FFA454D293`, 43,814 bytes, 601 lines. Useful finding: `DialogSession.cpp` is the shared source root, `m_dialogList`/`m_activeDialogIndex` and `DialogInSession *` stack typing are strong, and declaration-level source is appropriate. Current live evidence supersedes its provisional access, `int dialogPaneConfigId`, and incomplete vtable-slot conclusions.
- Central executed-report searches also opened or classified incidental DIBitmap boundary/consumer reports: B001 `000136-DIBitmapDestructorAndAccessors-source-quality.md`, B001 `0001XE-DIBitmapDirectXVtables.md`, and B002 `000313-DIBitmapConstructor-source-quality.md`. They corroborate that `0x00618e50` begins DIBitmap RTTI/vtable data and do not claim UID0002NB ownership.
- `tools/leaser/Agents/Older-Research` was searched with exact UID/address/name terms and the broader `DialogSession`, `DialogInSession`, `DialogPane`, `PaneVtables`, `DialogSessionCore`, and `DialogSessionVtables` family terms. No target or source-family match was found; the one broad `ScrollCollectionPaneVtables` textual hit is unrelated.
- `tools/leaser/Agents/SpecialReports` was searched with the same terms and had no match.
- The actual project archive root `archived` was inspected and contained zero Markdown reports, so it supplied no prior target evidence.
- Active B001-B005 research roots were searched. No current exact-target or overlapping DialogSession vtable report was active when searched.
- Wave2/Wave3 mentions found in current docs and old reports were treated as historical stale evidence only. Current by-* docs, live MCP, raw bytes, xrefs, and generated output are the authority.

## Target

- Target UID: `0002NB`.
- Current target path: `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md`.
- Historical pre-callback path: `by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md`; it is absent after the one-move validator-supported rename.
- Source queue: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Historical report-only tracker snapshot: validator command `000000014141`, refreshed `2026-07-16T14:12:47-04:00`, SHA256 `813BEFB040D7C6C763FF2550B0BBA01EB63D5A6FA0E95C9AC0031513C52AF3EC`, 1,504,898 bytes, 6,119 lines; UID0002NB appeared at line 1622 as `86/90`, average `88.0`, reconstructable `true`, direct report count `0`, old path.
- Terminal-audit tracker snapshot: externally refreshed command `000000014180`, refreshed `2026-07-16T14:38:53-04:00`, SHA256 `8B629F4B4C2169938CF359F89CC51D7EFCD29656510D89C743C5DA2BC86989E9`, 1,505,136 bytes, 6,120 lines; UID0002NB remained at line 3799 as `93/94`, average `93.5`, reconstructable `false`, direct report count `0`, and the corrected path when reread. This evidence-time snapshot does not assert indefinite tracker stability and does not replace B004's final waited generated command `000000014173`.
- Current classification: non-reconstructable source-declared/generated-binary RTTI/vtable support child under UID0001XD.

## Current Target State

- Current UID0002NB metadata: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0001XD`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, blank managed C++, `Nested:0`.
- Current range is `[0x00618d2c,0x00618e50)`, 292 bytes / `0x124`; the historical 288-byte / `0x120` range is retained as pre-callback evidence.
- Current target page contains the complete old/widened hashes, 73-dword payload, six COLs, exact 18/11/2 and 23/11/2 maps, three store triads per class, RTTI hierarchies, negative evidence, rejected alternatives, and the exact DIBitmap successor.
- Current support state:
  - UID0001XD is `92/94`, false/non-emitting, blank formal, with the complete six-view type map.
  - UID000131 is `90/92`, false/non-emitting, blank formal, with the complete helper/ScreenDimmer/compiler/history union.
  - UID0001U5 is `91/94`, false/non-emitting, blank formal, with exact direct bases, inherited facets, fields, types, and alignment.
  - UID00003S is `92/93` with the exact complete `DialogInSession` declaration.
  - UID00003U is `92/93` with `m_dialogList` and `m_activeDialogIndex` protected.
  - UID00003T is `92/94` and preserves the complete class union with exactly the four accepted virtual declarations added.
  - UID0003JA and Pane support now identify primary `+0x1c` / `0x005447a0` as `GetParentPane`, not the historical stale `Repaint` label.
- Current generated `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp`: command/header `000000014173`, refreshed `2026-07-16T14:29:37-04:00`, SHA256 `E9D211508F9070A9F411EE97D6B9874FB3A73624404190744F40A02D35E33EFF`, 1,385 bytes, 49 lines. It contains exactly one complete `DialogSession` class and one complete `DialogInSession` class, zero target-family Empty Emitter Markers, and zero handwritten compiler ABI source.
- Current generated `auto-generated/NexusTK/ui/core/DialogPane.cpp`: command/header `000000014173`, SHA256 `AB7B1F6BB1D81661FF26AA847AFADEB6230FE100D15D88798835E96E63A7EE5F`, 10,608 bytes, 332 lines. It contains exactly one complete `DialogPane` declaration and each accepted virtual declaration exactly once.
- Current manual coverage remains supervisor-owned and stale for the exact rows enumerated below; B004 did not edit it. Current read-only hashes and anchors are recorded in `Exact Manual Supervisor-Owned Coverage Or Tracker Text`.
- Callback implementation and scoped validators are complete. B004 performed no report execution, report probe/count, move, archive, revalidation, or lifecycle command. External supervisor/validator lifecycle state is authoritative outside this artifact and is neither asserted nor directed here.

## Executive Recommendation

- Keep the direct source module [UID:0000IU][DialogSession](by-file/DialogSession.md) and the two source classes `DialogSession` and `DialogInSession` together in `NexusTK/ui/dialogs/DialogSession.cpp`.
- Keep UID0002NB as one coherent two-class compiler-data child rather than splitting six tiny ABI pages. The six tables, six COL pointers, common source route, adjacent constructors/destructors, and shared RTTI hierarchy form one exact compiler cluster.
- Widen left to `0x00618d2c`; keep the exclusive end `0x00618e50`.
- Make UID0002NB, UID0001XD, UID000131, and UID0001U5 non-emitting. They remain documentation/index/type/layout authorities, while classes and exact method children emit source.
- Complete class declarations:
  - `DialogSession`: retain current source union, move `m_dialogList` and `m_activeDialogIndex` to `protected`.
  - `DialogInSession`: add exact `DialogSession *`, `unsigned short`, `unsigned char` constructor signature, virtual destructor, and source-facing tail fields.
  - `DialogPane`: preserve the complete current union and add only the four missing virtual declarations.
- Preserve UID000134 as compiler-only and verify-only.
- Correct Pane primary `+0x1c` to `GetParentPane()` and name all secondary/tertiary slots from the current EventHandler/TimerHandler contracts.

## Supervisor Active Recheck

- The supervisor assigned UID0002NB as a zero-direct-report vtable-data source-disposition target and required fresh live MCP evidence rather than reuse of the B001/B002 support reports.
- Split-first/range repair was required because the current target omits the primary COL pointer at `0x00618d2c`.
- Every source-bearing declaration required to regenerate the six tables is supplied in the seven exact managed destination blocks below.
- No source-bearing method body remains hidden in the data range. Compiler deleting wrappers and adjustor thunks are explicitly excluded from handwritten source.
- No unresolved "future slot investigation" item remains. The only non-original lexical spelling is the descriptive Pane three-argument no-op hook, whose ABI, table position, implementation, and lack of observed overrides are all exact.

## Inference Research Guidance Check

- Binary facts, documentation facts, and source-shape inference are separated throughout this report.
- Existing docs were treated as potentially stale when they used old scores, old Wave3 vtable counts, generic slot labels, feature-polluted types, private access incompatible with current derived source, or a range convention that excluded the first COL pointer.
- Source names were not copied from IDA `sub_*` labels. Exact known names come from current class contracts and exact method children. The one stripped no-op hook is given a conservative descriptive source-facing direction, not claimed as recovered original spelling.
- The compiler-data disposition follows `by-structure.md`: vtables, RTTI, complete-object locators, adjustor thunks, and scalar deleting destructors are generated from source class declarations and ordinary virtual destructors.
- Stale Wave2/Wave3 material was ignored except as explicitly historical evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Resolution |
| --- | --- | --- |
| Target start | The old page starts at the primary table base while all five later table bases have their COL pointer inside the range. The dword at `0x00618d2c` points to DialogSession COL `0x00646794`, has no competing owner, and fills the only four-byte hole before the table. | Widen to `0x00618d2c`; UID-preserving rename. |
| Target end | Dword `0x00618e50 -> 0x006467d0` is the DIBitmap primary COL, and exact DIBitmap child coverage starts there. | Keep exclusive end `0x00618e50`. |
| Six-table extents | COL boundaries and store xrefs prove exact 18/11/2 and 23/11/2 counts. No hidden slot exists between each final entry and the next COL. | Counts are final. |
| `.rdata` role | All target dwords are pointers to COL objects or executable virtual targets; constructors/destructors write the six table bases into object vptrs. | Source-declared/generated-binary compiler data. |
| Ownership | The data spans two classes in one source module. A single class owner would be misleading; the type page already describes both. | Direct type owner UID0001XD; source emitter route remains file UID0000IU through class pages. |
| Reconstructable/emitter | Handwritten table arrays would duplicate compiler output and pollute source. | Target/type/layout/aggregate support pages become false/non-emitting; class declarations emit. |
| Primary `+0x10` | `0x0041d680` is a no-op `retn 0x0c` virtual inherited by Pane classes. No current exact original symbol or derived override was found. | Describe as Pane three-argument state-change extension hook; name direction inferred, ABI exact. |
| Primary `+0x1c` | Live decompile reads the attached `Layer *` and calls exact `Layer::GetParentPane`, contradicting stale `Repaint`. | Correct to `Pane::GetParentPane()`. |
| DialogPane primary tail | Exact bodies at `0x0049f090`, `0x0049f1d0`, `0x0049f2e0`, and `0x0049fc00` prove `OnPaint`, `DrawBackground`, `DrawBorder`, and `SetHoverControl`. | Add missing declarations without changing method bodies. |
| Secondary `+0x10` | `0x0041d6b0` bytes `32 C0 C2 04 00` return false and pop one pointer argument. EventHandler table order makes it `HandlePacketEvent(Event *)`. | Exact inherited false default, blocker closed. |
| Secondary order | Current EventHandler formal fixes `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `HandleImeEvent`, `HandlePacketEvent`, `HandleSystemOrControlEvent`, `HandleType19Event`, then order/pair/acceptance methods. | Apply exact 11-slot order to both classes. |
| Tertiary `+0x04` | `0x00544e90` is the inherited three-int timer callback returning true. | Document as `Pane::OnTimer(int timerId, int arg0, int arg1)`. |
| Direct bases | RTTI CHDs show Pane/DialogPane plus inherited GrafPort/LObject/EventHandler/TimerHandler entries. EventHandler and TimerHandler are facets inherited through Pane, not extra source bases. | Source declarations remain `DialogSession : public Pane` and `DialogInSession : public DialogPane`. |
| DialogInSession config type | Constructor passes the second explicit stack argument to DialogPane's 16-bit config parameter; callers push a dword because of x86 stack ABI. | Use `unsigned short dialogConfigId`, not `int`. |
| DialogInSession field access | Session-family source directly reads `m_dialogType`; derived classes use `m_session`. Inventing getters would require unsupported source APIs and consumer rewrites. | Keep both fields public in the strongest compile-compatible source shape. |
| DialogSession field access | Derived `BulletinSession` source directly accesses `m_activeDialogIndex`; private is source-incompatible. | Move list/index state to `protected`. |
| Source placement | Classes, constructors, destructors, helper island, tables, and file docs all converge on one source route. | `NexusTK/ui/dialogs/DialogSession.cpp`. |
| Handwritten ABI alternatives | Literal arrays, explicit COL objects, vptr writes, adjustor arithmetic, deleting flags, and explicit operator delete wrappers would reproduce compiler products, not human source. | Reject all such formal C++. |

Rejected alternatives:

- Keep old range and describe `0x00618d2c` only in prose: rejected because it leaves a real compiler-data dword uncovered inside UID000254 and makes the target's byte/hash proof incomplete.
- Split each vtable view into a separate by-memory child: rejected because no source owner or behavior boundary differs; it would fragment one coherent compiler cluster without improving source emission.
- Make UID0002NB reconstructable with a no-code comment: rejected because reconstructable/emitter metadata still creates generated Empty Emitter Markers and implies source ownership.
- Make DialogSession inherit EventHandler and TimerHandler directly: rejected by RTTI hierarchy and Pane layout; those facets are inherited through Pane.
- Keep `DialogInSession(..., int dialogPaneConfigId, ...)`: rejected by the exact DialogPane constructor contract and low-word use.
- Keep Pane `+0x1c` as Repaint: rejected by direct decompilation and exact Layer parent lookup.
- Treat `0x0041d6b0` as unknown: rejected by exact five-byte behavior and EventHandler slot order.
- Handwrite scalar deleting destructors or adjustor thunks: rejected as compiler ABI glue.

## Evidence Standards Used

- Direct IDA MCP facts: `idb_list`, `server_health`, bounded function lookup, decompilation, raw bytes, integer/dword reads, RTTI/COL reads, vtable-base stores, and xrefs.
- Binary-boundary facts: target/neighbor hashes, exact little-endian dword map, preceding COL pointer, next DIBitmap COL pointer, and no padding inside the widened range.
- Source-contract facts: current `EventHandler`, `Pane`, `DialogPane`, `DialogSession`, `DialogInSession`, layout, vtable, exact method child, and source-file docs.
- Generated evidence: current `DialogSession.cpp` only as a lead for emitter pollution and class-source compatibility, never as authority over live IDA.
- Old reports: opened after exact UID/address/source-family search and used only as revalidated leads.
- Negative evidence: no independent source/data owner for `0x00618d2c`; no extra slot between COLs; no ordinary calls to compiler wrappers; no evidence for literal source arrays; no evidence for direct EventHandler/TimerHandler bases; no alternate source file; no target report in Older-Research, SpecialReports, active B001-B005, or the empty archive root.
- Confidence cap: original lexical spelling for the no-op Pane hook and exact original access style are not symbol-proven, so confidence remains below absolute certainty despite exact ABI/table proof.

## Evidence Checked

- IDA MCP:
  - fresh `idb_list` and `server_health` for database `64c11373`;
  - exact bytes and SHA inputs for old `[0x00618d30,0x00618e50)` and recommended `[0x00618d2c,0x00618e50)`;
  - all 73 dwords in the widened range;
  - six table-base xref sets;
  - six COL pointers and COL object fields;
  - DialogSession/DialogInSession class hierarchy descriptors and base arrays;
  - constructors/destructors/wrappers/adjustor thunks;
  - exact Pane/DialogPane/EventHandler/TimerHandler slot bodies;
  - bounded `0x0041d6b0` lookup, bytes, and decompilation.
- Current docs:
  - UID0002NB, UID0001XD, UID000254, UID000131, UID000134;
  - UID00003U, UID00003S, UID00003T, UID0000A2, UID00004N;
  - UID0000IU, UID0000IT, UID0000MC;
  - UID0001U5, UID0003JA, UID0003JB;
  - exact Pane/DialogPane method children referenced by the slot map.
- Current generated/tracker:
  - `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp`;
  - `auto-generated/-ag-research-tracker.md`.
- Manual coverage:
  - `by-memory/-coverage-report.md`;
  - `by-class/-coverage-report.md`;
  - `by-file/-coverage-report.md`;
  - `by-type/by-vtable/-coverage-report.md`;
  - `by-type/by-struct/-coverage-report.md`.
- Old-report search terms:
  - `UID0002NB`, `0002NB`;
  - `0x00618d30`, `0x00618e50`, `00618d30`, `00618e50`;
  - `DialogSessionVtableData`, `DialogSessionVtables`, `DialogCoreReadOnlyData`, `DialogSessionCore`;
  - `DialogSession`, `DialogInSession`, `DialogPane`, `PaneVtables`;
  - owner/file terms `0001XD`, `0000IU`, and `DialogSession.cpp`.
- Exact relevant report paths opened and results:
  - B001 UID000132: overlapping stack range is a non-emitting historical index; confirms shared source file and compiler-thunk exclusions.
  - B002 UID00003U: class/source route and field/helper direction are useful; current pass corrects stale access, constructor width, and slot map.
  - Incidental DIBitmap reports: establish successor boundary only.
- Root outcomes:
  - central executed reports: two direct support reports plus incidental DIBitmap boundary reports;
  - Older-Research: no target/source-family report;
  - SpecialReports: no match;
  - `archived`: zero Markdown files;
  - active B001-B005 research: no direct/overlapping target report when searched.
- Failed/skipped check:
  - one broad all-text `insn_query` virtual-call sweep timed out because the query was overbroad. It was replaced by bounded function, bytes, decompile, and xref checks. Subsequent valid IDB-backed calls succeeded, so no evidence gap remains.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C2NB-001 | Old target is exactly 288 bytes / `0x120`, SHA256 `0F0CE78E47E3B6C21C3CED05FC78753943086BF2D3DEA4F5B4A4B8DEF25B8246`. | direct | MCP bytes/hash retained in target history | UID0002NB current target, hash `4D2693...F36B`; validator `14153` | incorporate | applied |
| C2NB-002 | Widened target is exactly 292 bytes / `0x124`, SHA256 `21426F5FF849FCD1E90F22FF8A189FD2090D7C9E73798E0AE16E89CA7622D15D`. | direct | MCP bytes/hash retained in current Range | UID0002NB current target; validator `14153` | incorporate | applied |
| C2NB-003 | `0x00618d2c -> 0x00646794` is DialogSession primary COL; `0x00618e50 -> 0x006467d0` begins DIBitmap. | direct | current boundary/COL sections | UID0002NB and UID000254; validators `14153`, `14155` | incorporate | applied |
| C2NB-004 | Range contains six exact vtable bases at `18d30/18d7c/18dac/18db8/18e18/18e48`. | direct | current six-view map | UID0002NB and UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-005 | Slot extents are exactly DialogSession 18/11/2 and DialogInSession 23/11/2. | direct | complete current maps | UID0002NB and UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-006 | The 73-dword map below is the complete widened byte payload. | direct | complete payload retained verbatim | UID0002NB; validator `14153` | incorporate | applied |
| C2NB-007 | Six COLs identify object offsets 0, `0xa0`, and `0xa4` for each class. | direct | COL/layout sections | UID0002NB, UID0001XD, UID0001U5; validators `14153`, `14154`, `14164` | incorporate | applied |
| C2NB-008 | RTTI base arrays prove direct source bases Pane and DialogPane; EventHandler/TimerHandler are inherited facets. | direct | RTTI and source/compiler split | target/type/class/layout docs; validators `14153`, `14154`, `14158`, `14159`, `14164` | incorporate | applied |
| C2NB-009 | DialogSession constructor, ordinary destructor, and scalar wrapper each store all three table bases. | direct | lifecycle-store inventory | UID0002NB/UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-010 | DialogInSession constructor, ordinary destructor, and scalar wrapper each store all three table bases. | direct | lifecycle-store inventory | UID0002NB/UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-011 | Four secondary/tertiary destructor entries are exact `this-0xa0`/`this-0xa4` adjustor thunks. | direct | thunk disassembly and existing UID000134 content | UID000134 remained `86/90`/blank with bounded cause/link sync; validator `14157` | already-present | already-present |
| C2NB-012 | Scalar deleting destructors and adjustor thunks are compiler output from virtual ordinary destructors. | strong | ABI/store/destructor evidence | target/type/class/file docs; validators `14153`-`14159`, `14165` | incorporate | applied |
| C2NB-013 | All primary table slots have exact source-role maps below. | strong | complete slot maps retained | UID0002NB/UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-014 | `0x0041d680` is an exact three-argument no-op Pane extension virtual; source spelling is descriptive. | strong | bytes/ABI/table inheritance retained | Pane/PaneVtables/Pane file; validators `14166`-`14168` | incorporate | applied |
| C2NB-015 | Primary `+0x1c` / `0x005447a0` is `Pane::GetParentPane()`, not Repaint. | direct | decompile/callee and current support text | stale `Repaint` rejected in UID0000A2/UID0003JA/UID0000MC; validators `14166`-`14168` | reject-stale | applied |
| C2NB-016 | Secondary tables follow the exact EventHandler 11-slot contract. | direct | EventHandler order and complete maps | UID0002NB/UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-017 | DialogInSession secondary `+0x10` / `0x0041d6b0` is inherited false `HandlePacketEvent(Event *)`. | direct | bounded bytes/decompile retained | UID0002NB/UID0001XD; validators `14153`, `14154` | incorporate | applied |
| C2NB-018 | Tertiary `+0x04` / `0x00544e90` is inherited true-return `OnTimer(int,int,int)`. | direct | body/table retained | UID0002NB/UID0001XD and Pane support; validators `14153`, `14154`, `14166`-`14168` | incorporate | applied |
| C2NB-019 | DialogSession source inheritance remains `class DialogSession : public Pane`. | direct | RTTI/constructor/layout | UID00003U exact Destination 5; validator `14158` | incorporate | applied |
| C2NB-020 | DialogInSession source inheritance remains `class DialogInSession : public DialogPane`. | direct | RTTI/constructor/layout | UID00003S exact Destination 6; validator `14159` | incorporate | applied |
| C2NB-021 | `+0xa0/+0xa4` are 160/164-byte secondary/tertiary facets. | direct | COL/thunks/int_convert | UID0001U5 and vtable docs; validators `14154`, `14164` | incorporate | applied |
| C2NB-022 | Both classes belong in `NexusTK/ui/dialogs/DialogSession.cpp`. | strong | source route and generated readback | UID0000IU; validator `14165`; generated command `14173` | incorporate | applied |
| C2NB-023 | UID0002NB needs a UID-preserving rename to the widened `0x00618d2c` path. | direct | boundary proof and path verification | one-move rename complete; old path absent, current path present, one UID header; validator `14153` path update | incorporate | applied |
| C2NB-024 | UID0002NB should be `93/94`, owner UID0001XD, false, blank emitter/position/formal, Nested 0. | strong | current header and compiler disposition | UID0002NB hash `4D2693...F36B`; validator `14153` | incorporate | applied |
| C2NB-025 | UID0001XD should be `92/94`, owner UID0000IU, false, blank emitter/position/formal. | strong | current header and full map | UID0001XD hash `0E30E0...CC1`; validator `14154` | incorporate | applied |
| C2NB-026 | UID000254 remains `87/91`, false/non-emitting; update child path and remove stale four-byte-gap/future-widen language. | strong | current parent boundary and child inventory | UID000254 hash `DE4B27...FEBA`; validator `14155` | incorporate | applied |
| C2NB-027 | UID000131 should be `90/92`, owner UID0000IU, false/non-emitting mixed physical index with blank formal. | strong | current aggregate header/source split | UID000131 hash `09349D...D381`; validator `14156` | incorporate | applied |
| C2NB-028 | UID000134 remains `86/90`, false/non-emitting, blank formal; only support links/details change if validator propagation requires. | direct | current header and thunk proof | UID000134 hash `0C219B...F3A`; validator `14157` | already-present | already-present |
| C2NB-029 | UID00003U should be `92/93`; preserve class union and move list/index fields to protected. | strong | exact formal equality hash `713D68...B307` | UID00003U hash `A6C5F4...3593`; validator `14158` | incorporate | applied |
| C2NB-030 | UID00003S should be `92/93` with `unsigned short dialogConfigId`, byte type, session pointer, and virtual destructor. | strong | exact formal equality hash `C62D6C...BD91` | UID00003S hash `19DB1F...39D5`; validator `14159` | incorporate | applied |
| C2NB-031 | UID00003T should be `92/94` and add only HandleImeEvent, OnPaint, DrawBackground, DrawBorder to the no-loss current class. | strong | exact formal equality hash `4ED478...AC6D` | UID00003T hash `B1B64A...E9F8`; validator `14161`; generated command `14173` | incorporate | applied |
| C2NB-032 | UID0001U5 should be `91/94`, owner UID0000IU, false/non-emitting, blank formal, with exact offsets/types. | strong | current layout header and blank-formal equality | UID0001U5 hash `E8426A...C2E0`; validator `14164` | incorporate | applied |
| C2NB-033 | UID0000IU should be `90/93` and document the complete compiler/source split and corrected class declarations. | strong | current source route/file union | UID0000IU hash `87803E...2594`; validator `14165` | incorporate | applied |
| C2NB-034 | Pane class support should record exact inherited slot roles without broad formal or score inflation. | strong | bounded support rebase | UID0000A2 hash `52DE8A...09C`; validator `14166` | incorporate | applied |
| C2NB-035 | PaneVtables should correct `+0x1c` and fill `+0x04/+0x08/+0x10/+0x44` directions without score/formal change. | strong | exact slot corrections | UID0003JA hash `A1CBCC...1D13`, UID0000MC hash `A2F944...238E`; validators `14167`, `14168` | incorporate | applied |
| C2NB-036 | DialogPaneVtables should record full primary/secondary/tertiary inherited maps without score/formal change. | strong | complete current maps | UID0003JB hash `9E0E1D...F554`; validator `14169` | incorporate | applied |
| C2NB-037 | DialogPane file should record the four added virtual declarations and exact inherited DialogInSession route without score inflation. | strong | file/class/generated route | UID0000IT hash `52B056...F2A5`; validator `14170`; generated command `14173` | incorporate | applied |
| C2NB-038 | No literal vtable, RTTI, COL, hierarchy descriptor, or base-array C++ may be emitted. | direct | four blank formal equality hashes and generated negative scan | no handwritten compiler table source; generated command `14173` | reject-invalid | excluded-with-reason |
| C2NB-039 | No explicit vptr writes, adjustor arithmetic, deletion flags, or scalar-wrapper pseudo-source may be emitted. | direct | ABI/source distinction and generated negative scan | no explicit ABI pseudo-source; generated command `14173` | reject-invalid | excluded-with-reason |
| C2NB-040 | Historical pre-callback DialogSession.cpp had five target-family Empty Emitter Markers; the completed callback removes all five through metadata/class-source changes. | direct | historical command `14140`; current command `14173` | zero UID0002NB/UID0001XD/UID000131/UID0001U5 markers and no UID00003S marker | incorporate | applied |
| C2NB-041 | B001/B002 reports are revalidated support leads, not substitutes for target-specific evidence. | direct | report search/current MCP retained | preserved as historical support throughout target/support docs | historicalize | applied |
| C2NB-042 | Only six table bases have lifecycle code stores; COL cells have data-only links and no independent code owner. | direct | xref sweep retained | UID0002NB/UID0001XD negative evidence; validators `14153`, `14154` | incorporate | applied |
| C2NB-043 | Human source names/types use current class contracts; stripped no-op name remains explicitly inferred/descriptive. | strong | source-family consistency | class/Pane support docs and score caps; validators `14158`, `14159`, `14166`-`14170` | incorporate | applied |
| C2NB-044 | Score increases are bounded by original-name/access-style uncertainty, not unresolved binary behavior. | strong | blocker audit retained | target/support score rationales on all changed pages | incorporate | applied |
| C2NB-045 | Manual by-memory/class/file/vtable/struct rows require the exact replacements below; unchanged rows are explicitly inspected. | direct | post-callback current manual readback | exact supervisor-owned handoff remains pending externally; no manual file edited | incorporate | applied |
| C2NB-046 | Callback used scoped validators and a final waited refresh, changed only accepted ordinary pages plus validator-managed reverse links, and ran no report lifecycle command. | direct | validator/lease/generated inventory | commands `14153`-`14171`, failed transient `14172`, successful waited `14173`; zero leases | incorporate | applied |

## Positive Evidence Summary

- The recommended widened range is fully dense compiler-pointer data: one primary COL pointer plus six vtable bodies and five embedded later COL pointers, ending exactly before DIBitmap.
- Decorated RTTI names identify all six views without heuristic class assignment.
- Constructor/destructor/wrapper stores independently identify all six vtable bases and all three object offsets for each class.
- CHDs and base descriptors identify the exact source inheritance chain and reject direct extra bases.
- Every slot dword resolves to a current class/interface contract or an exact bounded body.
- `0x0041d6b0` direct bytes close the only formerly generic secondary method.
- Current consumers prove source access requirements for `m_activeDialogIndex` and `m_dialogType`.
- Source module, code island, layouts, vtables, and old reports all converge on `DialogSession.cpp`.
- The compiler-data/no-handwritten-table disposition exactly explains why the current Empty Emitter Markers are wrong and how class declarations regenerate the data.

## IDA MCP Facts

- Database at evidence time: `64c11373`, NexusTK.exe.i64, imagebase `0x00400000`, worker PID `21508`.
- Old range:
  - `[0x00618d30,0x00618e50)`;
  - 288 bytes / `0x120` (Verified with MCP `int_convert`);
  - SHA256 `0F0CE78E47E3B6C21C3CED05FC78753943086BF2D3DEA4F5B4A4B8DEF25B8246`;
  - first 16 bytes `00 15 4A 00 10 4B 4F 00 C0 B6 41 00 20 8E 4B 00`;
  - last 16 bytes `70 4E 54 00 80 67 64 00 7A 14 4A 00 90 4E 54 00`.
- Widened range:
  - `[0x00618d2c,0x00618e50)`;
  - 292 bytes / `0x124` (Verified with MCP `int_convert`);
  - SHA256 `21426F5FF849FCD1E90F22FF8A189FD2090D7C9E73798E0AE16E89CA7622D15D`;
  - first 16 bytes `94 67 64 00 00 15 4A 00 10 4B 4F 00 C0 B6 41 00`;
  - last 16 bytes `70 4E 54 00 80 67 64 00 7A 14 4A 00 90 4E 54 00`.
- Exact complete little-endian dword map:

| Address | Value | Meaning |
| --- | --- | --- |
| `0x00618d2c` | `0x00646794` | DialogSession primary COL |
| `0x00618d30` | `0x004a1500` | DS primary +00 scalar deleting destructor |
| `0x00618d34` | `0x004f4b10` | DS primary +04 LObject::GetRuntimeClass |
| `0x00618d38` | `0x0041b6c0` | DS primary +08 LObject::OnChangeMessage |
| `0x00618d3c` | `0x004b8e20` | DS primary +0c GrafPort::UpdateRenderRegion |
| `0x00618d40` | `0x0041d680` | DS primary +10 Pane three-argument no-op hook |
| `0x00618d44` | `0x00544730` | DS primary +14 Pane::Show |
| `0x00618d48` | `0x00544750` | DS primary +18 Pane::Hide |
| `0x00618d4c` | `0x005447a0` | DS primary +1c Pane::GetParentPane |
| `0x00618d50` | `0x00544800` | DS primary +20 Pane::InvalidateRect |
| `0x00618d54` | `0x00544a20` | DS primary +24 Pane::GetDescription |
| `0x00618d58` | `0x00544b80` | DS primary +28 Pane::GetScreenBounds |
| `0x00618d5c` | `0x00544bd0` | DS primary +2c Pane::SetBounds |
| `0x00618d60` | `0x00544c70` | DS primary +30 Pane::AddToLayer |
| `0x00618d64` | `0x00544cb0` | DS primary +34 Pane::InsertInLayer |
| `0x00618d68` | `0x00544ce0` | DS primary +38 Pane::RemoveFromLayer |
| `0x00618d6c` | `0x00544d30` | DS primary +3c Pane::SetPaneOrder |
| `0x00618d70` | `0x00544d70` | DS primary +40 Pane::UnregisterEventHandler |
| `0x00618d74` | `0x0041b6a0` | DS primary +44 Pane::OnPaint default |
| `0x00618d78` | `0x006467a8` | DialogSession secondary COL |
| `0x00618d7c` | `0x004a1485` | DS secondary +00 destructor adjustor |
| `0x00618d80` | `0x00544db0` | DS secondary +04 HandlePointerOrMouseEvent default |
| `0x00618d84` | `0x00544dc0` | DS secondary +08 HandleKeyOrTextEvent default |
| `0x00618d88` | `0x00544dd0` | DS secondary +0c HandleImeEvent default |
| `0x00618d8c` | `0x00544de0` | DS secondary +10 HandlePacketEvent default |
| `0x00618d90` | `0x00544df0` | DS secondary +14 HandleSystemOrControlEvent default |
| `0x00618d94` | `0x00544e00` | DS secondary +18 HandleType19Event default |
| `0x00618d98` | `0x004a89f0` | DS secondary +1c ForwardHandlerOrder |
| `0x00618d9c` | `0x00544e10` | DS secondary +20 GetLocalEventPair |
| `0x00618da0` | `0x00544e30` | DS secondary +24 GetScreenEventPair |
| `0x00618da4` | `0x00544e70` | DS secondary +28 ShouldAcceptEvent const |
| `0x00618da8` | `0x006467bc` | DialogSession tertiary COL |
| `0x00618dac` | `0x004a1490` | DS tertiary +00 destructor adjustor |
| `0x00618db0` | `0x00544e90` | DS tertiary +04 Pane::OnTimer |
| `0x00618db4` | `0x00646758` | DialogInSession primary COL |
| `0x00618db8` | `0x004a14a0` | DIS primary +00 scalar deleting destructor |
| `0x00618dbc` | `0x004f4b10` | DIS primary +04 LObject::GetRuntimeClass |
| `0x00618dc0` | `0x0041b6c0` | DIS primary +08 LObject::OnChangeMessage |
| `0x00618dc4` | `0x004b8e20` | DIS primary +0c GrafPort::UpdateRenderRegion |
| `0x00618dc8` | `0x0041d680` | DIS primary +10 Pane three-argument no-op hook |
| `0x00618dcc` | `0x00544730` | DIS primary +14 Pane::Show |
| `0x00618dd0` | `0x00544750` | DIS primary +18 Pane::Hide |
| `0x00618dd4` | `0x005447a0` | DIS primary +1c Pane::GetParentPane |
| `0x00618dd8` | `0x00544800` | DIS primary +20 Pane::InvalidateRect |
| `0x00618ddc` | `0x00544a20` | DIS primary +24 Pane::GetDescription |
| `0x00618de0` | `0x00544b80` | DIS primary +28 Pane::GetScreenBounds |
| `0x00618de4` | `0x00544bd0` | DIS primary +2c Pane::SetBounds |
| `0x00618de8` | `0x0049dfd0` | DIS primary +30 DialogPane::OnCreate |
| `0x00618dec` | `0x00544cb0` | DIS primary +34 Pane::InsertInLayer |
| `0x00618df0` | `0x0049e1c0` | DIS primary +38 DialogPane::OnDestroy |
| `0x00618df4` | `0x0049e190` | DIS primary +3c DialogPane::OnShow |
| `0x00618df8` | `0x0049e210` | DIS primary +40 DialogPane::OnHide |
| `0x00618dfc` | `0x0049f090` | DIS primary +44 DialogPane::OnPaint |
| `0x00618e00` | `0x0041b6c0` | DIS primary +48 DialogPane::OnControlCommand default |
| `0x00618e04` | `0x0041b6a0` | DIS primary +4c DialogPane::UpdateActionButton default |
| `0x00618e08` | `0x0049f1d0` | DIS primary +50 DialogPane::DrawBackground |
| `0x00618e0c` | `0x0049f2e0` | DIS primary +54 DialogPane::DrawBorder |
| `0x00618e10` | `0x0049fc00` | DIS primary +58 DialogPane::SetHoverControl |
| `0x00618e14` | `0x0064676c` | DialogInSession secondary COL |
| `0x00618e18` | `0x004a146f` | DIS secondary +00 destructor adjustor |
| `0x00618e1c` | `0x0049e240` | DIS secondary +04 DialogPane::HandlePointerOrMouseEvent |
| `0x00618e20` | `0x0049e6e0` | DIS secondary +08 DialogPane::HandleKeyOrTextEvent |
| `0x00618e24` | `0x0049ea60` | DIS secondary +0c DialogPane::HandleImeEvent |
| `0x00618e28` | `0x0041d6b0` | DIS secondary +10 inherited false HandlePacketEvent |
| `0x00618e2c` | `0x00544df0` | DIS secondary +14 HandleSystemOrControlEvent default |
| `0x00618e30` | `0x00544e00` | DIS secondary +18 HandleType19Event default |
| `0x00618e34` | `0x004a89f0` | DIS secondary +1c ForwardHandlerOrder |
| `0x00618e38` | `0x00544e10` | DIS secondary +20 GetLocalEventPair |
| `0x00618e3c` | `0x00544e30` | DIS secondary +24 GetScreenEventPair |
| `0x00618e40` | `0x00544e70` | DIS secondary +28 ShouldAcceptEvent const |
| `0x00618e44` | `0x00646780` | DialogInSession tertiary COL |
| `0x00618e48` | `0x004a147a` | DIS tertiary +00 destructor adjustor |
| `0x00618e4c` | `0x00544e90` | DIS tertiary +04 Pane::OnTimer |

- COL facts:
  - DialogSession COLs `0x00646794`, `0x006467a8`, `0x006467bc`: signature 0, offsets 0/`0xa0`/`0xa4`, cdOffset 0, type descriptor `0x00674c84`, hierarchy `0x0064343c`.
  - DialogInSession COLs `0x00646758`, `0x0064676c`, `0x00646780`: signature 0, offsets 0/`0xa0`/`0xa4`, cdOffset 0, type descriptor `0x00674cf0`, hierarchy `0x00643560`.
  - `0xa0` is 160 and `0xa4` is 164 (Verified with MCP `int_convert`).
- Hierarchy facts:
  - DialogSession CHD attributes 1, six base descriptors: self, Pane, GrafPort, LObject, EventHandler at `+0xa0`, TimerHandler at `+0xa4`.
  - DialogInSession CHD attributes 1, seven base descriptors: self, DialogPane, Pane, GrafPort, LObject, EventHandler at `+0xa0`, TimerHandler at `+0xa4`.
- Xref facts:
  - DialogSession primary/secondary/tertiary stores: constructor `0x004a0dc1/0x004a0dc7/0x004a0dd1`; ordinary destructor `0x004a0e9e/0x004a0ea4/0x004a0eae`; scalar wrapper `0x004a152e/0x004a1534/0x004a153e`.
  - DialogInSession primary/secondary/tertiary stores: constructor `0x004a142d/0x004a1433/0x004a143d`; ordinary destructor `0x004a1450/0x004a1456/0x004a1460`; scalar wrapper `0x004a14a6/0x004a14ac/0x004a14b6`.
  - Each COL object has one data xref from its preceding cell. The target-wide address sweep found lifecycle code stores only to the six vtable bases.
- Constructor/type facts:
  - `DialogInSession` source signature is strongest as `DialogInSession(DialogSession *session, unsigned short dialogConfigId, unsigned char dialogType)`.
  - `+0x26c` is 620 and `+0x270` is 624 (Verified with MCP `int_convert`).

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00618d2c-0x00618e50` | UID0002NB recommended renamed path | Six COL-backed vtable views for two classes | false | UID0001XD | `93/94` | compiler data, blank formal |
| DialogSession vtable type | UID0001XD | Type/layout authority for six views | false | UID0000IU | `92/94` | non-emitting |
| `0x006189dc-0x00618e50` | UID000254 | Mixed read-only parent index | false | none | `87/91` | unchanged score, child link correction |
| `0x004a0d80-0x004a15f8` | UID000131 | Mixed physical source/compiler index | false | UID0000IU | `90/92` | reclassify non-emitting |
| `0x004a146f-0x004a149b` | UID000134 | Four adjustor thunks | false | none | `86/90` | verify-only compiler support |
| `DialogSession` class | UID00003U | Source declaration and helper children | true | UID0000IU | `92/93` | complete no-loss formal |
| `DialogInSession` class | UID00003S | Source declaration for session-bound dialog base | true | UID0000IU | `92/93` | complete formal |
| `DialogPane` class | UID00003T | Base declaration causing inherited primary/secondary slots | true | UID0000IT | `92/94` | add four declarations |
| `DialogSessionLayouts` | UID0001U5 | Non-emitting layout evidence | false | UID0000IU | `91/94` | blank formal |
| `DialogSession.cpp` route | UID0000IU | Shared source file | file | file | `90/93` | source owner |
| Pane support | UID0000A2/UID0003JA/UID0000MC | Inherited primary slots | unchanged | existing | unchanged | bounded fact corrections |
| DialogPane support | UID0000IT/UID0003JB | Inherited primary/secondary slots | unchanged except class score | existing | bounded | no-loss support sync |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00618d30` | stores at `0x004a0dc1`, `0x004a0e9e`, `0x004a152e` | DialogSession primary lifecycle vptr |
| `0x00618d7c` | stores at `0x004a0dc7`, `0x004a0ea4`, `0x004a1534` | DialogSession EventHandler facet |
| `0x00618dac` | stores at `0x004a0dd1`, `0x004a0eae`, `0x004a153e` | DialogSession TimerHandler facet |
| `0x00618db8` | stores at `0x004a142d`, `0x004a1450`, `0x004a14a6` | DialogInSession primary lifecycle vptr |
| `0x00618e18` | stores at `0x004a1433`, `0x004a1456`, `0x004a14ac` | DialogInSession EventHandler facet |
| `0x00618e48` | stores at `0x004a143d`, `0x004a1460`, `0x004a14b6` | DialogInSession TimerHandler facet |
| `0x00646794/a8/bc` | one data xref each from `0x00618d2c/78/da8` | DialogSession COL links |
| `0x00646758/6c/80` | one data xref each from `0x00618db4/e14/e44` | DialogInSession COL links |
| `0x004a1485/0x004a1490` | data cells `0x00618d7c/0x00618dac`; jumps to `0x004a1500` | DialogSession adjustor thunks |
| `0x004a146f/0x004a147a` | data cells `0x00618e18/0x00618e48`; jumps to `0x004a14a0` | DialogInSession adjustor thunks |
| `0x005447a0` | calls Layer parent lookup | exact correction from Repaint to GetParentPane |
| `0x0041d6b0` | inherited by DialogInSession secondary `+0x10` | false HandlePacketEvent default |

## Documentation Evidence And IDA Status

- Historical pre-callback docs correctly established the shared source module, six table bases, three object views, constructor/destructor stores, and DIBitmap successor, but were stale or incomplete on target start/hash, compiler-page emission, slot names, Pane `+0x1c`, the `DialogInSession` formal/config width, `DialogSession` access, and four `DialogPane` declarations.
- Current ordinary docs incorporate all accepted corrections at report-level detail. The only unsynchronized documentation surface is the explicitly supervisor-owned manual coverage rows below.
- Current generated `DialogSession.cpp` command/header `000000014173` proves the source declaration route and the corrected compiler-only exclusions: one class per accepted source class and zero UID0002NB/UID0001XD/UID000131/UID0001U5 markers.
- Current MCP status was healthy when evidence was collected. One overbroad query timeout was replaced with bounded successful calls and did not affect final evidence.
- Historical tracker command `000000014141` recorded the old path, old score, and reconstructable state. B004 waited command `000000014173` first refreshed the corrected state; terminal-audit external tracker command `000000014180` retained the corrected path, `93/94`, reconstructable false, and direct report count zero when reread. B004 did not edit the tracker and does not assert indefinite later tracker stability.

## Ranked Ownership Analysis

### 1. UID0001XD DialogSessionVtables as direct target owner

- Evidence for: exact six-view type page; covers both classes; links source file and layouts; direct semantic authority over compiler tables.
- Evidence against: it must not emit source or literal arrays.
- Decision: retain as canonical owner of UID0002NB, but reclassify both target and type page as false/non-emitting.

### 2. UID0000IU DialogSession source file as source emitter route

- Evidence for: owns both class declarations and code island; all constructors/destructors/helpers, layouts, vtables, and consumers converge on this file.
- Evidence against: a file page is less precise than UID0001XD as direct data-layout owner.
- Decision: retain as owner/emitter of source-bearing class pages and owner of UID0001XD, not direct owner of the raw target.

### 3. Individual class ownership or no owner

- Evidence for individual classes: each owns three views.
- Evidence against: UID0002NB spans both classes in one indivisible compiler cluster; selecting either class alone loses half the range.
- Evidence for no owner: compiler data is not handwritten source.
- Evidence against no owner: UID0001XD is a precise documentation/type authority and owner metadata need not imply source emission.
- Decision: reject individual class and `NONE` as direct target owner; use UID0001XD with blank emitter.

### Proposed new file/grouping, if applicable

- No new source file is needed.
- The recommended renamed target remains one narrow compiler-data child.
- Likely full source contents remain the two classes and exact helper children already routed through `DialogSession.cpp`.
- DIBitmap is rejected from the target and begins exactly at `0x00618e50`.

## Source Placement

- Recommended source placement: `NexusTK/ui/dialogs/DialogSession.cpp`, via [UID:0000IU].
- Recommended declaration placement: `DialogSession` and `DialogInSession` class declarations under the same file route; common inherited declarations remain in `Pane` and `DialogPane`.
- Recommended data handling: compiler emits six vtables, six COLs, class hierarchy descriptors, base descriptors, adjustors, and deleting wrappers.
- Rejected placements:
  - `BulletinSession.cpp`: consumer/derived class, not base owner.
  - `DialogPane.cpp`: owns inherited base slots but not the two derived class declarations.
  - `DIBitmap.cpp`: begins at the exclusive successor boundary.
  - a new `DialogSessionVtables.cpp`: artificial ABI-source file with no human-source support.
- Remaining placement uncertainty: exact historical folder spelling is not symbol-proven, but current project route and all direct documentation support `ui/dialogs`.

## Range / Split / Padding / Reclassification Analysis

- Current range `[0x00618d30,0x00618e50)` omits one required four-byte primary COL pointer.
- Recommended range `[0x00618d2c,0x00618e50)` is exactly 292 bytes and contains:
  - six COL pointer cells;
  - 67 virtual target cells;
  - no padding;
  - no unrelated data.
- Exact view lengths:
  - DialogSession primary: 18 slots, `0x00618d30-0x00618d78`;
  - DialogSession secondary: 11 slots, `0x00618d7c-0x00618da8`;
  - DialogSession tertiary: two slots, `0x00618dac-0x00618db4`;
  - DialogInSession primary: 23 slots, `0x00618db8-0x00618e14`;
  - DialogInSession secondary: 11 slots, `0x00618e18-0x00618e44`;
  - DialogInSession tertiary: two slots, `0x00618e48-0x00618e50`.
- No child creation is recommended. Six per-view children would duplicate one source/type contract and add no source-emission precision.
- UID000254 parent remains unchanged in range and nesting; its stale gap/future-widen wording should be removed.
- UID000131 is reclassified as a non-emitting mixed physical index rather than split further by this target callback.
- UID000134 remains a separate exact compiler-thunk child.

## Negative Evidence Summary

- No code xref independently treats `0x00618d2c` as a separate global; it is only the first COL pointer for the primary table.
- No bytes between table ends and the next COL permit an additional slot.
- No slot points to a purecall handler; default/no-op methods are real inherited bodies.
- No direct source-base evidence supports `DialogSession : Pane, EventHandler, TimerHandler` or `DialogInSession : DialogPane, EventHandler, TimerHandler`.
- No evidence supports handwritten vtable arrays, RTTI objects, COLs, hierarchy descriptors, base descriptors, vptr assignments, deleting flags, or adjustor arithmetic.
- No evidence supports old `Repaint` at Pane `+0x1c`.
- No evidence supports `int` as the source-facing DialogPane config type in DialogInSession.
- No evidence supports keeping class state private when current derived source directly accesses it.
- No exact target report was found in active B001-B005, Older-Research, SpecialReports, or the empty project archive root.
- Incidental DIBitmap reports prove only the successor boundary and do not extend target ownership.

## IDA Rename / Type / Comment Recommendations

- UID-preserving documentation rename:
  - old: `by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md`;
  - new: `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md`.
- Source-facing type recommendations:
  - `DialogInSession(DialogSession *session, unsigned short dialogConfigId, unsigned char dialogType)`;
  - `unsigned char m_dialogType`;
  - `DialogSession *m_session`;
  - `List *m_dialogList`;
  - `unsigned char m_activeDialogIndex`.
- Source-facing virtual recommendations:
  - `DialogPane::HandleImeEvent(Event *)`;
  - `DialogPane::OnPaint()`;
  - `DialogPane::DrawBackground()`;
  - `DialogPane::DrawBorder()`;
  - `Pane::GetParentPane()`;
  - `Pane::OnTimer(int timerId, int arg0, int arg1)`.
- Descriptive-only recommendation:
  - keep `0x0041d680` documented as a Pane three-argument no-op state-change extension hook; do not claim an original recovered name.
- IDA database edits are not requested and were not performed.

## First-Draft C++ Recommendation

Destination 1: recommended renamed UID0002NB. Exact managed block remains blank because the target is compiler data:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 2: UID0001XD `by-type/by-vtable/DialogSessionVtables.md`. Exact managed block remains blank:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 3: UID000131 `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md`. Exact managed block remains blank:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4: UID0001U5 `by-type/by-struct/DialogSessionLayouts.md`. Exact managed block remains blank:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 5: UID00003U `by-class/DialogSession.md`. Preserve the current class union and change only field access:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class List;
class DialogInSession;

class DialogSession : public Pane
{
public:
    DialogSession();
    virtual ~DialogSession();

    void CloseAllDialogs();
    void PushDialog(DialogInSession *dialog);
    void PopCurrentDialog(bool shouldAnimate);
    DialogInSession *FindPreviousDialog(DialogInSession *dialog);
    DialogInSession *GetDialogAtIndex(int index);

private:
    void ActivateNextDialog(bool shouldAnimate);
    int FindDialogIndex(DialogInSession *dialog);

protected:
    List *m_dialogList;
    unsigned char m_activeDialogIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 6: UID00003S `by-class/DialogInSession.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DialogSession;

class DialogInSession : public DialogPane
{
public:
    DialogInSession(DialogSession *session,
                    unsigned short dialogConfigId,
                    unsigned char dialogType);
    virtual ~DialogInSession();

    unsigned char m_dialogType;
    DialogSession *m_session;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 7: UID00003T `by-class/DialogPane.md`. This is the complete current formal with only four accepted virtual declarations added:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DialogPane : public Pane
{
public:
    DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode);
    virtual ~DialogPane();

    virtual void OnCreate(const RectBounds *bounds, int zOrder, Pane *parentPane, Layer *layer);
    virtual void OnShow(Pane *afterPane, Pane *beforePane);
    virtual void OnDestroy();
    virtual void OnHide();
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    int FindControlIndex(const ControlPane *control) const;
    void CloseDialog();

protected:
    void StoreClampRect(const RectBounds *bounds);
    void ClearClampRect();
    void SetTitleText(const wchar_t *title);
    void SetBackgroundResource(const wchar_t *resourceName, short frameIndex);
    void AddControl(unsigned char category, ControlPane *control);
    void AddControl(ControlPane *control);
    void RemoveControl(ControlPane *control);
    void RemoveControl(int controlIndex);
    int GetControlCount() const;
    ControlPane *GetChildControl(int controlIndex) const;

    template <class T>
    T *GetChild(int controlIndex) const
    {
        return static_cast<T *>(GetChildControl(controlIndex));
    }

    virtual void DrawBackground();
    virtual void DrawBorder();
    char HitTestControls(int mouseY, int mouseX, int *outControlId);
    void DispatchInputToControl(Event *event, int controlId);
    void SavePosition();
    void SetFocusedControl(int controlId);
    void SetPendingControl(int controlId);
    virtual void SetHoverControl(int controlId);
    void SetSelectionVisualState(int controlId, unsigned char state);
    void ActivateFocusedControl();
    void ActivatePendingControl();
    void RedrawSelectedControl();

    void SlideOpenVertical();
    void SlideCloseVertical();
    void SlideOpenHorizontal(unsigned char direction);
    void SlideCloseHorizontal(unsigned char direction);
    void SlideShrink(unsigned char direction);
    void SlideExpand(unsigned char direction);

    wchar_t m_title[128];
    unsigned short m_dialogConfigId;
    List *m_controlManager;
    int m_focusedControlId;
    int m_pendingControlId;
    unsigned char m_isTitleDragActive;
    unsigned char m_savedPaneMode;
    int m_dragOriginX;
    int m_dragOriginY;
    int m_activeControlId;
    unsigned char m_pressedControlActive;
    int m_pressedControlId;
    unsigned char m_pressedHitType;
    int m_selectedControlId;
    unsigned char m_selectionVisualState;
    unsigned char m_clampDragToBounds;
    int m_dragClampMinY;
    int m_dragClampMinX;
    int m_dragClampMaxY;
    int m_dragClampMaxX;
    EPFTileContext m_tileContext;
    DialogBackgroundState m_backgroundState;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason the code preserves behavior: virtual declarations regenerate the observed primary/secondary/tertiary tables; ordinary destructors cause compiler deleting wrappers and adjustors; field types/access preserve current consumers.
- Reason it matches plausible historical source: conventional VC6/VC7-era class declarations, simple built-in types, no decompiler temporaries, no ABI arrays, no explicit vptr writes, no modern constructs.
- Exact no-code proof for Destinations 1-4: all contents are compiler data or aggregate/layout documentation already caused by Destinations 5-7 and exact method children. Any nonblank C++ would duplicate source or emit ABI scaffolding.
- Third-party import directive: not applicable; this is NexusTK class/compiler data, not embedded third-party source.

## Final Recommendation

- Applied: UID0002NB now includes `0x00618d2c` while retaining UID, owner UID0001XD, blank position, `Nested:0`, and blank formal.
- Applied: target `86/90 -> 93/94`, `RECONSTRUCTABLE:TRUE -> FALSE`, and emitter blanking.
- Applied: UID0001XD, UID000131, and UID0001U5 are non-emitting support records with the accepted scores.
- Applied: UID00003U, UID00003S, and UID00003T class source exactly matches Destinations 5-7.
- Applied: UID000254, UID000134, UID0000IU, Pane, PaneVtables, Pane file, DialogPaneVtables, and DialogPane file are synchronized at report-level detail without unrelated score or formal inflation.
- Preserved: exact bytes, hashes, table counts, COLs, inheritance, object offsets, slot maps, xrefs, compiler exclusions, historical reports, stale assumptions, rejected alternatives, and DIBitmap boundary.
- No implementation item remains. Broader Pane whole-class formal reconstruction remains outside this callback and is not required for UID0002NB.

## Recommended Target Doc Changes

- Path: UID-preserving rename to `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md`.
- Metadata: `93/94`, owner UID0001XD, reconstructable false, blank emitter, blank position, blank formal, `Nested:0`.
- Item Summary:
  - `Source-declared/generated-binary DialogSession/DialogInSession RTTI and six-view vtable cluster: six COL pointers, exact 18/11/2 and 23/11/2 slot maps, constructor/destructor stores, inherited Pane/DialogPane/EventHandler/TimerHandler contracts, compiler adjustor/deleting-wrapper disposition, and exact DIBitmap successor at 0x00618e50.`
- Replace old range/hash and generic key-slot section with the complete facts in this report.
- Preserve historical 2026-05/06 evidence as historical, but supersede stale start, generic slot names, stricter-gate commentary, and reconstructable/emitter rationale.

## Recommended Support Doc Changes

- `by-type/by-vtable/DialogSessionVtables.md` UID0001XD:
  - `92/94`, owner UID0000IU, false/non-emitting, blank formal;
  - exact six COL-inclusive extents and all slot maps;
  - source declaration/compiler generation rationale;
  - corrected target link/path.
- `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md` UID000254:
  - preserve `87/91`, none, false, blank;
  - replace child path;
  - remove obsolete `0x00618d2c-0x00618d30` gap/future-widen language;
  - preserve all unrelated children and nesting.
- `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md` UID000131:
  - `90/92`, owner UID0000IU, false/non-emitting, blank formal;
  - classify as mixed physical source/compiler index;
  - preserve complete function/helper/ScreenDimmer/history evidence;
  - link exact source classes, compiler thunks, and renamed target.
- `by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md` UID000134:
  - verify current `86/90`, none, false, blank formal;
  - add exact source-destructor cause and updated links only; no score change.
- `by-class/DialogSession.md` UID00003U:
  - `92/93`;
  - install Destination 5;
  - preserve all helper/source/ScreenDimmer evidence;
  - explain protected access from current derived source.
- `by-class/DialogInSession.md` UID00003S:
  - `92/93`;
  - install Destination 6;
  - correct `int` to `unsigned short`;
  - record natural alignment between byte and pointer;
  - preserve wrapper/thunk compiler exclusions.
- `by-class/DialogPane.md` UID00003T:
  - `92/94`;
  - install Destination 7 exactly;
  - add exact vtable/body evidence for four declarations;
  - preserve every current control/list/animation field and method.
- `by-type/by-struct/DialogSessionLayouts.md` UID0001U5:
  - `91/94`, owner UID0000IU, false/non-emitting, blank formal;
  - exact direct bases/facet offsets;
  - exact `unsigned short` config and public tail field direction;
  - corrected source declaration route.
- `by-file/DialogSession.md` UID0000IU:
  - `90/93`;
  - complete two-class source/compiler split, range/path, slots, access/type corrections, and no-handwritten-vtable rule.
- `by-class/Pane.md`, `by-type/by-vtable/PaneVtables.md`, `by-file/Pane.md`:
  - correct `+0x1c` to `GetParentPane`;
  - identify inherited `+0x04/+0x08/+0x10/+0x44` and secondary/tertiary defaults;
  - preserve scores and broad blank Pane formal.
- `by-type/by-vtable/DialogPaneVtables.md`, `by-file/DialogPane.md`:
  - synchronize complete slots and four source declarations;
  - preserve scores/formals except the accepted UID00003T class completion increase.
- Verify-only pages: exact method children, EventHandler, TimerHandler, DIBitmap successor pages, and UID000132 remain unchanged unless validator-managed reverse-link propagation occurs.

## Score And Metadata Recommendation

| UID | Historical pre-callback | Current implemented | Owner | Reconstructable | Emitter | Formal |
| --- | --- | --- | --- | --- | --- | --- |
| 0002NB | `86/90` | `93/94` | 0001XD | false | blank | blank |
| 0001XD | `86/90` | `92/94` | 0000IU | false | blank | blank |
| 000254 | `87/91` | `87/91` unchanged | NONE | false | blank | blank |
| 000131 | `88/90` | `90/92` | 0000IU | false | blank | blank |
| 000134 | `86/90` | `86/90` unchanged | NONE | false | blank | blank |
| 00003U | `90/90` | `92/93` | 0000IU | true | 0000IU | Destination 5 |
| 00003S | `85/88` | `92/93` | 0000IU | true | 0000IU | Destination 6 |
| 00003T | `91/94` | `92/94` | 0000IT | true | 0000IT | Destination 7 |
| 0001U5 | `85/90` | `91/94` | 0000IU | false | blank | blank |
| 0000IU | `88/90` | `90/93` | FILE | file | file | n/a |

Score-improvement attempt:

- Range blocker: resolved by exact widened bytes/hash/COL boundary.
- Slot-count blocker: resolved all 67 virtual entries.
- Generic-name blocker: resolved all inherited method roles; one stripped no-op spelling remains descriptive but ABI-complete.
- Ownership blocker: resolved direct type owner versus source emitter.
- Reconstructable/emitter blocker: resolved compiler-data/no-handwritten-source disposition.
- Inheritance blocker: resolved direct bases and inherited facets through RTTI.
- Signature blocker: resolved DialogInSession config width and field types.
- Source compatibility blocker: resolved member access and missing DialogPane virtuals.
- Source placement blocker: resolved one file route.
- Confidence is not higher because original no-op hook spelling and exact original public/protected style are not symbol-proven. These are lexical/source-style caps, not unresolved behavior.

## Open Questions With Attempted Resolution

| Question | Checks | Resolution |
| --- | --- | --- |
| Should the target include `0x00618d2c`? | Dword, COL, parent gap, adjacent child convention, xrefs | Yes; widen left four bytes. |
| Are 18/11/2 and 23/11/2 exact? | Every dword, every next COL, successor | Yes. |
| Is `0x0041d680` ignorable? | Bytes, ABI, table inheritance, override search | No; real inherited no-op virtual, descriptive name only. |
| Is `0x005447a0` Repaint? | Direct decompile and Layer callee | No; GetParentPane. |
| What is `0x0041d6b0`? | Lookup, bytes, decompile, EventHandler order | False HandlePacketEvent default. |
| Are EventHandler/TimerHandler direct bases? | RTTI base descriptors and Pane layout | No; inherited through Pane. |
| Should vtable/type/layout pages emit? | Generated markers, compiler source mechanism | No. |
| Should DialogInSession config be int? | Base constructor signature and low-word use | No; unsigned short. |
| Should DialogInSession fields be private? | Current direct consumers and no getter evidence | No; public is strongest source-compatible shape. |
| Should DialogSession fields be private? | Derived BulletinSession source use | No; protected. |
| Should six view pages be created? | Shared source/type owner and no behavior split | No. |
| Is another source file plausible? | Code island, current file docs, consumers, reports | No stronger alternative. |
| Can exact original no-op hook spelling be recovered? | Symbols, bodies, vtables, docs, overrides | No symbol survives. Use descriptive inferred direction and cap confidence; behavior/source slot is fully resolved. |

No investigable target blocker remains deferred.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual snapshots reread after ordinary validation and waited generated refresh:

- `by-memory/-coverage-report.md`: SHA256 `8448E762CF0639F2873DC2861F10A8D57C42A900A1AA690F5E0C13D906F07114`, 1,774,499 bytes, 4,253 lines.
- `by-class/-coverage-report.md`: SHA256 `9710D23ADFD1CAF806CAE8DEDE327C69420C38BEF0CDCAD1C181621A9B9B6BFA`, 229,370 bytes, 622 lines.
- `by-file/-coverage-report.md`: SHA256 `0EBB76739F9FBC1AB22D9C04D1E4A070118F9079808E99B6EDFF477FE990D82E`, 131,915 bytes, 316 lines.
- `by-type/by-vtable/-coverage-report.md`: SHA256 `33DF8DBD8FC54EB018659FC2B889DB5C129B65D05B0107EBE1C102B562A3D4C0`, 65,425 bytes, 142 lines.
- `by-type/by-struct/-coverage-report.md`: SHA256 `C31049C3148BFCF7953F5D6821572591F2DFA7C6404FE5680917C52FBB717014`, 57,552 bytes, 137 lines.
- Current readback confirms the exact UID000131/UID000134/UID000254/UID0002NB rows remain stale at lines 1264/1267/3737/3741, UID0001XD remains stale at line 45, UID00003S/UID00003T/UID00003U remain stale at lines 161/162/163, UID0000IU remains stale at line 75, and UID0001U5 remains stale at line 36. The exact replacement text below therefore remains the required no-loss supervisor handoff.

Exact by-memory replacement text:

Replace the UID000131 row near current line 1264 with:

```markdown
    - [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) : ignored : 90% : very-strong : Non-emitting mixed physical index for the DialogSession/DialogInSession code island: exact class and method pages carry human source, UID000134 carries compiler adjustor thunks, ScreenDimmer helpers retain their independent route, and the renamed UID0002NB compiler-data child carries the six-view vtable/RTTI cluster; complete helper, layout, caller, historical, and negative evidence is preserved without duplicate aggregate emission.
```

Replace the UID000134 row near current line 1267 with:

```markdown
    - [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md) : ignored : 86% : very-strong : Exact compiler-generated secondary/tertiary destructor adjustors for DialogInSession and DialogSession; `this-0xa0`/`this-0xa4` thunks forward to the owning scalar deleting wrappers, are regenerated from the ordinary virtual destructors and multiple-inheritance layout, and remain blank/non-emitting with no handwritten ABI source.
```

Replace the UID000254 row near current line 3737 with:

```markdown
    - [UID:000254][0x006189dc-0x00618e50.DialogCoreReadOnlyData](by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md) 0x006189dc-0x00618e50 | mixed-rdata index | DialogCoreReadOnlyData : ignored : 87% : very-strong : Non-emitting dialog read-only-data index over exact DescPane/DialogPane/AlertPane/VersatileAlertPane/ModelessDialogPane/DialogFrameResourceStrings/DialogSession children; renamed UID0002NB now begins at its primary COL pointer `0x00618d2c`, eliminating the stale four-byte gap, and `0x00618e50` remains the exact exclusive DIBitmap successor.
```

Replace the UID0002NB row near current line 3741 with:

```markdown
        - [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) 0x00618d2c-0x00618e50 | vtable-rtti-data | DialogSessionVtableData : ignored : 93% : very-strong : Source-declared/generated-binary DialogSession/DialogInSession compiler cluster with six COL pointers, exact 18/11/2 and 23/11/2 virtual-slot maps, primary/secondary/tertiary offsets `0/+0xa0/+0xa4`, constructor/ordinary-destructor/scalar-wrapper store triads, exact inherited Pane/DialogPane/EventHandler/TimerHandler identities, adjustor/deleting-wrapper exclusions, blank formal/emitter, and exact DIBitmap successor at `0x00618e50`.
```

Exact by-vtable replacement text:

Replace UID0001XD near current line 45 with:

```markdown
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md) : ignored : 92% : very-strong : Non-emitting source-declared/generated-binary type authority for the DialogSession/DialogInSession six-view cluster: exact COL-inclusive extents, 18/11/2 and 23/11/2 slots, object offsets `0/+0xa0/+0xa4`, constructor/destructor store triads, inherited Pane/DialogPane/EventHandler/TimerHandler contracts, compiler adjustor/deleting-wrapper handling, renamed UID0002NB backing data, and class-declaration source route through DialogSession.cpp.
```

PaneVtables and DialogPaneVtables rows were inspected. Their current broad coverage summaries remain same-or-greater after the bounded slot-detail corrections, so no manual row replacement is required for UID0003JA or UID0003JB.

Exact by-class replacement text:

Replace UID00003S near current line 161 with:

```markdown
- [UID:00003S][DialogInSession](by-class/DialogInSession.md) : reconstructable : 92% : very-strong : Complete DialogPane-derived session-dialog base in DialogSession.cpp with exact `DialogSession *`, `unsigned short dialogConfigId`, and `unsigned char dialogType` constructor contract, virtual ordinary destructor, public `m_dialogType`/`m_session` source-compatible tail, `+0x26c/+0x270` layout, three vtable views at `0/+0xa0/+0xa4`, inherited DialogPane/EventHandler/TimerHandler slots, and compiler-only scalar-wrapper/adjustor disposition.
```

Replace UID00003T near current line 162 with:

```markdown
- [UID:00003T][DialogPane](by-class/DialogPane.md) : reconstructable : 92% : very-strong : Complete no-loss 0x26c DialogPane declaration/layout with exact OnCreate/OnShow/OnDestroy/OnHide/OnPaint primary overrides, pointer/key/IME secondary overrides, public OnControlCommand, UpdateActionButton, protected DrawBackground/DrawBorder/SetHoverControl and typed child access, exact SetHoverControl and coordinate-dispatch distinction, control/lifecycle/animation families, compiler-vtable separation, and DialogPane.cpp ownership.
```

Replace UID00003U near current line 163 with:

```markdown
- [UID:00003U][DialogSession](by-class/DialogSession.md) : reconstructable : 92% : very-strong : Complete Pane-derived session container in DialogSession.cpp with virtual ordinary destructor, exact stack/list helper union, `List *m_dialogList` and byte `m_activeDialogIndex` moved to protected for derived-source compatibility, DialogInSession pointer typing, exact three-view vtable route, ScreenDimmer exclusions, compiler deleting-wrapper/adjustor handling, and source declarations that regenerate UID0002NB without handwritten ABI arrays.
```

Pane UID0000A2 row was inspected. Its broad summary remains current after the bounded `GetParentPane` slot correction, so no manual row replacement is required.

Exact by-file replacement text:

Replace UID0000IU near current line 75 with:

```markdown
- [UID:0000IU][DialogSession](by-file/DialogSession.md) : reconstructable : 90% : very-strong : `NexusTK/ui/dialogs/DialogSession.cpp` source root for complete DialogSession and DialogInSession declarations and exact method children; preserves stack/list helpers and ScreenDimmer exclusions, corrects protected/public field access and the 16-bit DialogPane config type, routes the renamed UID0002NB and UID0001XD/UID000131/UID0001U5 as non-emitting compiler/layout support, and relies on ordinary virtual destructors/class declarations to regenerate all six vtables, RTTI/COLs, deleting wrappers, and adjustors.
```

DialogPane and Pane file rows were inspected. Their broad current summaries remain same-or-greater after bounded support synchronization, so no manual replacement is required for UID0000IT or UID0000MC.

Exact by-struct replacement text:

Replace UID0001U5 near current line 36 with:

```markdown
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) : ignored : 91% : very-strong : Non-emitting layout authority for DialogSession and DialogInSession: direct Pane/DialogPane bases, inherited EventHandler/TimerHandler facets at `+0xa0/+0xa4`, protected `List *m_dialogList` at `+0xf8`, byte `m_activeDialogIndex` at `+0xfc`, `unsigned char m_dialogType` at `+0x26c`, aligned `DialogSession *m_session` at `+0x270`, exact constructor/destructor stores, and source declaration route through the two class pages rather than duplicate layout C++.
```

- Placement: preserve existing row ordering and indentation; the renamed UID0002NB row remains the final child under UID000254 before UID000255.
- Reason B004 must not apply directly: manual coverage files are supervisor-owned and explicitly read-only for this assignment.
- Auto-generated tracker: B004 did not hand-edit it. Waited validator command `000000014173` refreshed the target path, `93/94`, and reconstructable-false classification; report count and later lifecycle state remain externally supervisor/validator-owned.

## Follow-Up Actions

- Implementation, scoped validation, lease release, formal equality checks, and waited generated readback are complete.
- Manual coverage remains a supervisor-owned handoff exactly as recorded below; B004 did not edit coverage.
- Report validation, implementation review, manual coverage application, execution, count, path, move, and archive state are external supervisor/validator-owned facts. This artifact neither asserts nor directs those lifecycle outcomes.
- A-agent action: none required.
- B004 target research or implementation follow-up: none; all in-scope source/slot/range blockers and callback items are closed.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; increases are evidence-backed and bounded below absolute certainty.
- Remaining uncertainty:
  - original spelling of the no-op Pane `+0x10` hook;
  - exact original access choice if historical source used friends/getters rather than the simplest public/protected fields.
- Neither uncertainty changes binary behavior, range, owner, emitter, source route, table extents, class signatures, or C++ eligibility.

## Validator Results

- Help-only preflight: `python .\tools\validator.py --help`, command `000000014147`, timestamp `2026-07-16T14:16:55-04:00`, exit `0`. This was not a file validation or lifecycle command and had no intended implementation side effect.
- Scoped validators, each run from `source-3/project-documentation` while the corresponding short lease was active:

| Command | Timestamp | Final path | Exit / ok | Warnings and side effects |
| --- | --- | --- | --- | --- |
| `000000014153` | `2026-07-16T14:19:12-04:00` | `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md` | `0 / 1` | UID0002NB path update, 25 reverse-link updates across seven docs, metadata/reconstructable/emitter/registry updates; 53 pre-existing unrelated `missing_ref_uid` warnings; generated refresh deferred. |
| `000000014154` | `2026-07-16T14:20:20-04:00` | `by-type/by-vtable/DialogSessionVtables.md` | `0 / 1` | UID0001XD true-to-false/emitter-cleared metadata and projected-stat updates; no target-specific warning. |
| `000000014155` | `2026-07-16T14:20:45-04:00` | `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md` | `0 / 1` | Parent boundary/link refresh; 15 pre-existing unrelated missing-UID warnings; no target failure. |
| `000000014156` | `2026-07-16T14:21:38-04:00` | `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md` | `0 / 1` | UID000131 metadata/emitter update and UID000133/UID000134 link insertions; no target-specific warning. |
| `000000014157` | `2026-07-16T14:22:09-04:00` | `by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md` | `0 / 1` | Bounded UID000134 detail/link refresh; no score/formal change and no target-specific warning. |
| `000000014158` | `2026-07-16T14:22:42-04:00` | `by-class/DialogSession.md` | `0 / 1` | UID00003U formal/source hash and registry refresh; no target-specific warning. |
| `000000014159` | `2026-07-16T14:23:20-04:00` | `by-class/DialogInSession.md` | `0 / 1` | UID00003S blank-to-complete formal and registry hash refresh; no target-specific warning. |
| `000000014161` | `2026-07-16T14:23:54-04:00` | `by-class/DialogPane.md` | `0 / 1` | UID00003T complete-union formal/hash refresh; seven pre-existing unrelated missing-UID warnings; no target failure. |
| `000000014164` | `2026-07-16T14:24:38-04:00` | `by-type/by-struct/DialogSessionLayouts.md` | `0 / 1` | UID0001U5 true-to-false/emitter-cleared metadata refresh; no target-specific warning. |
| `000000014165` | `2026-07-16T14:25:35-04:00` | `by-file/DialogSession.md` | `0 / 1` | UID0000IU source-route/hash refresh; no target-specific warning. |
| `000000014166` | `2026-07-16T14:26:04-04:00` | `by-class/Pane.md` | `0 / 1` | Bounded Pane support refresh with score/formal preserved; no target-specific warning. |
| `000000014167` | `2026-07-16T14:26:31-04:00` | `by-type/by-vtable/PaneVtables.md` | `0 / 1` | Exact slot correction; two pre-existing UID0003CA warnings; no target failure. |
| `000000014168` | `2026-07-16T14:26:55-04:00` | `by-file/Pane.md` | `0 / 1` | Bounded file support refresh; two pre-existing UID0003CA warnings; no target failure. |
| `000000014169` | `2026-07-16T14:27:19-04:00` | `by-type/by-vtable/DialogPaneVtables.md` | `0 / 1` | Complete inherited-map refresh; two pre-existing UID0003AW warnings; no target failure. |
| `000000014170` | `2026-07-16T14:27:52-04:00` | `by-file/DialogPane.md` | `0 / 1` | Bounded file/source-route refresh; four pre-existing missing-reference warnings; no target failure. |
| `000000014171` | `2026-07-16T14:28:54-04:00` | `by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md` | `0 / 1` | Mechanical stale reverse-link repair; validator registered the existing UID0003AX path and refreshed its existing metadata/reference index. |

- Final waited validation command:
  - first attempt `000000014172`, timestamp `2026-07-16T14:29:04-04:00`, exit `1`, failed during an unrelated generated-file atomic replace with `PermissionError [WinError 5]` on `auto-generated/NexusTK/login/NewCreateUserDialogPane.cpp`; no B004 manual generated edit occurred;
  - retry `000000014173`, timestamp `2026-07-16T14:29:37-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`;
  - validator-generated side effects included a 5,082-node/4,098-edge registry rebuild, 279 metadata refreshes, tracker/projected-stat refresh, 14 fallback inserts, 84 missing-children warnings, and 148 emitter-has-no-code warnings. These broad warnings were pre-existing/unrelated; no UID0002NB callback assertion failed.
- Generated readback at command/header `000000014173`:
  - `auto-generated/NexusTK/ui/dialogs/DialogSession.cpp`, SHA256 `E9D211508F9070A9F411EE97D6B9874FB3A73624404190744F40A02D35E33EFF`, 1,385 bytes, 49 lines;
  - exactly one `class DialogSession : public Pane` and one `class DialogInSession : public DialogPane`;
  - exact protected DialogSession fields and exact `DialogInSession(DialogSession *, unsigned short, unsigned char)` declaration;
  - zero UID0002NB, UID0001XD, UID000131, UID0001U5, or UID00003S Empty Emitter Markers;
  - zero literal vtable/RTTI/COL/base-array source, zero explicit vptr/adjustor/deleting-wrapper source, and zero duplicate exact method bodies;
  - `auto-generated/NexusTK/ui/core/DialogPane.cpp`, SHA256 `AB7B1F6BB1D81661FF26AA847AFADEB6230FE100D15D88798835E96E63A7EE5F`, 10,608 bytes, 332 lines, contains one complete class and each of `OnPaint`, `HandleImeEvent`, `DrawBackground`, and `DrawBorder` exactly once.
- Formal equality proof, normalized LF SHA256:
  - Destinations 1-4 blank managed blocks: report and destinations all `CA40B93B6569C6F5127EE922903894943A86E38CB071968DB2A2260DC2E3F396`;
  - Destination 5: report and UID00003U both `713D68DB3C3249ECF72E2A877F0AF5B0161509DE729063FE14E78A36C1AFB307`;
  - Destination 6: report and UID00003S both `C62D6C629DCB0C7B12FE912EA974E86AD3190960F3CAF169F4F04EDC00FDBD91`;
  - Destination 7: report and UID00003T both `4ED478674C779036839355FC035F3A0BE0A6325A14774E8402017CCF4F7CAC6D`.
- No report lifecycle, execute, count, probe, revalidation, move, or archive command was run.

## Changed Files

- UID-preserving one-move rename:
  - old path `by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md` is absent;
  - current path `by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md`, UID0002NB unique, SHA256 `4D26931378A6FBDAA4C6F5B0EFE8EC8D205C1A545E693C7C6BC69D07BEB0F36B`, 19,669 bytes, 212 lines.
- Accepted ordinary destinations modified:
  - `by-type/by-vtable/DialogSessionVtables.md`: `0E30E025FA3082E3DCDD5166ED7D636C0206A7FE7EF9AEBA5F7FBB795B675CC1`, 11,840 bytes, 139 lines.
  - `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md`: `DE4B279DB59A94078594DEFC4A5AFFA2309716F1C09893EF0FAD2811D3E3FEBA`, 16,357 bytes, 128 lines.
  - `by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md`: `09349D42D1ED691E8BDA8D0C30733A2BBBBF2499FCC5DF8D0FC746627D59D381`, 19,708 bytes, 135 lines.
  - `by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md`: `0C219B045E9459FAD2A40973974A579E8EDF671BA481A4FD19B686956F2A4F3A`, 5,684 bytes, 68 lines.
  - `by-class/DialogSession.md`: `A6C5F45B9750A890BB4C3B68BD3B093A6A143A82E98A8568C9F9EBB543623593`, 16,712 bytes, 165 lines.
  - `by-class/DialogInSession.md`: `19DB1FDDC822D7D18FABA8E3402C5FB9E9C5D85EC553E53A057940E879B839D5`, 10,845 bytes, 124 lines.
  - `by-class/DialogPane.md`: `B1B64AC696226EE8F84F415979EB31EED63C9BC4C0516D0046A7C2D8A14FE9F8`, 37,430 bytes, 323 lines.
  - `by-type/by-struct/DialogSessionLayouts.md`: `E8426A0A666933BBF1B48E4BAF14564A3FA25CAB4AEDA32984EEFCFBC7A3C2E0`, 14,686 bytes, 127 lines.
  - `by-file/DialogSession.md`: `87803EAE46120B2B01836A939C38FEAFEAA129FD14F99C4383F345E2E5A12594`, 13,263 bytes, 113 lines.
  - `by-class/Pane.md`: `52DE8ABC62527FFA6995C9EB903BF9D3F3D75DA703BA37DA3E21A690FCC5009C`, 19,439 bytes, 150 lines.
  - `by-type/by-vtable/PaneVtables.md`: `A1CBCC1A8387C6267F2FDDCDC768B56C6DFDF997BA3295EF7FF74B78E3791D13`, 11,433 bytes, 116 lines.
  - `by-file/Pane.md`: `A2F944927689914824683D9413F919384807BB7FFDBBA2E4FAA7D37A6855238E`, 22,260 bytes, 160 lines.
  - `by-type/by-vtable/DialogPaneVtables.md`: `9E0E1D0FDF0B92A1081847393C04D6C4DDA42FA3B17D5075A950BD9274D4F554`, 9,499 bytes, 101 lines.
  - `by-file/DialogPane.md`: `52B0569B043C7172D2C5DE32C4C8183C0A8484F2429567A28B9C5C3BC80BF2A5`, 25,190 bytes, 148 lines.
- Validator-managed reverse-link destination:
  - `by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md`: `D9292868E8733DB73F51F798B0BDF9D6F75FE4B6103727D98653152676370EE7`, 4,525 bytes, 67 lines.
- Report modified in place: `tools/leaser/Agents/Agent-B004/research/0002NB-DialogSessionVtableData-source-quality.md`.
- Verify-only method children, EventHandler, TimerHandler, UID000132, DIBitmap pages, and unrelated pages were not manually edited.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle files were not manually edited. Validator-generated refresh side effects are recorded above.
- Every ordinary-file lease was acquired only for its edit/validation window and released immediately. `tools/leaser/Agents/current_leases.md` currently reports zero B004 leases; any unrelated agent lease is outside this callback.
- Report execution was not run. B004 did not run or probe any report lifecycle, move, archive, count, or revalidation command.

## Implementation Tracking Checklist

Research and implementation proof:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `AF8A82901851F50714211B276EB8287C587D73E158A78B99224300E0806B3868` before implementation.
- [x] UID0002NB old path reread immediately before callback.
- [x] UID0002NB UID-preserving rename to `0x00618d2c-0x00618e50` completed once.
- [x] Old UID0002NB path confirmed absent and UID remains unique.
- [x] UID0002NB metadata changed to `93/94`, owner 0001XD, false, blank emitter/position/formal, Nested 0.
- [x] UID0002NB exact old/widened bytes and hashes incorporated.
- [x] UID0002NB complete 73-dword map incorporated.
- [x] UID0002NB six COLs, RTTI hierarchies, and DIBitmap successor incorporated.
- [x] UID0002NB all six store triads and negative xref evidence incorporated.
- [x] UID0002NB exact 18/11/2 and 23/11/2 slot maps incorporated.
- [x] UID0001XD changed to `92/94`, false/non-emitting, blank formal.
- [x] UID000254 current union reread and renamed child path/no-gap wording rebased.
- [x] UID000254 score/metadata and unrelated children preserved.
- [x] UID000131 changed to `90/92`, false/non-emitting mixed index, blank formal.
- [x] UID000131 complete helper/ScreenDimmer/compiler/history evidence preserved.
- [x] UID000134 reread and verified unchanged except bounded link/detail synchronization.
- [x] UID00003U changed to `92/93`.
- [x] UID00003U Destination 5 applied exactly.
- [x] UID00003U all helper/source/ScreenDimmer/unrelated content preserved.
- [x] UID00003S changed to `92/93`.
- [x] UID00003S Destination 6 applied exactly.
- [x] UID00003S constructor width, fields, layout, inheritance, and compiler exclusions incorporated.
- [x] UID00003T changed to `92/94`.
- [x] UID00003T complete current union reread immediately before edit.
- [x] UID00003T Destination 7 applied exactly with only four new declarations.
- [x] UID00003T unrelated control/list/animation/source facts preserved.
- [x] UID0001U5 changed to `91/94`, false/non-emitting, blank formal.
- [x] UID0001U5 exact direct-base/facet/field/type facts incorporated.
- [x] UID0000IU changed to `90/93` with complete source/compiler route.
- [x] Pane class support corrected without score/formal inflation.
- [x] PaneVtables `+0x1c` corrected and inherited/default slots completed without score/formal inflation.
- [x] Pane file support synchronized without score inflation.
- [x] DialogPaneVtables complete slot map synchronized without score/formal inflation.
- [x] DialogPane file four-declaration/source-route facts synchronized without score inflation.
- [x] Exact method children, EventHandler, TimerHandler, UID000132, DIBitmap, and unrelated pages kept verify-only.
- [x] No literal vtable/RTTI/COL/base-array source inserted.
- [x] No explicit vptr/adjustor/deleting-wrapper pseudo-source inserted.
- [x] Historical B001/B002 findings preserved as revalidated leads.
- [x] Stale range, Repaint, private-access, int-config, generic-slot, and reconstructable-emitter assumptions historicalized.
- [x] Rejected six-child split, direct extra bases, new vtable source file, and handwritten ABI alternatives preserved.
- [x] All C2NB-001 through C2NB-046 ledger rows updated with accepted destination proof.
- [x] One short lease acquired only immediately before each ordinary edit.
- [x] Each ordinary destination reread after lease acquisition.
- [x] One scoped validator run per changed ordinary page.
- [x] Every lease released immediately after its edit/validation window.
- [x] No lease remains at callback return.
- [x] Final authorized waited generated refresh completed with command `000000014173`.
- [x] DialogSession.cpp generated assertions all pass.
- [x] DialogPane generated class declaration assertions pass.
- [x] No target-family Empty Emitter Marker remains.
- [x] No duplicate source or compiler-only body appears.
- [x] Exact validator IDs/timestamps/exits/ok/warnings/side effects recorded.
- [x] Exact changed ordinary paths and post-edit hashes recorded.
- [x] Current manual coverage rows reread after ordinary validation.
- [x] Exact supervisor-owned coverage handoff updated for external drift without editing coverage.
- [x] Current generated/tracker provenance reread and time-scoped before callback return.
- [x] This report current-state, ledger, Validator Results, Changed Files, and checklist reconciled to terminal callback truth.
- [x] Third-party import directive confirmed not applicable.
- [x] Wave2/Wave3 artifacts remain rejected as stale.
- [x] No manual coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file manually edited.
- [x] No execute, report probe/count, revalidation, move, or archive command run.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact pre-callback SHA `AF8A82901851F50714211B276EB8287C587D73E158A78B99224300E0806B3868`.
- [x] All seven managed destination blocks applied exactly; normalized formal hashes are recorded in Validator Results.
- [x] All accepted target/support detail incorporated without compression.
- [x] All 46 claims have legal terminal callback states and concrete proof.
- [x] Every metadata/score/owner/emitter/range/path/formal change independently verified.
- [x] Every historical, negative, rejected, and source-placement fact preserved.
- [x] Every scoped validator completed with `exit 0 / ok 1`; the transient unrelated generated collision at `14172` is preserved and the final waited retry `14173` passed.
- [x] Generated source readback proves source classes and compiler exclusions.
- [x] Manual coverage handoff remains exact and supervisor-owned.
- [x] No accepted implementation item remains.
- [x] Zero leases remain.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000014226","destination_path":"executed-b-agent-research/B004/0002NB-DialogSessionVtableData-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002NB-DialogSessionVtableData-source-quality.md","timestamp":"2026-07-16T14:51:20-04:00","uid":"0002NB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
