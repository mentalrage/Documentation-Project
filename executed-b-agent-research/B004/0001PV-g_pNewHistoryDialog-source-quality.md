** TARGET-REPORT-UID:0001PV **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001PV g_pNewHistoryDialog Ownership / Source Closure Research

## Finalized Report / Current Recommendation

- Applied result: [UID:0001PV] `by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md` is exact loader-zero physical evidence at `92/94`, owned by semantic global UID0000RS, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and retained `Nested:0`.
- Sole definition: UID0000RS emits one externally linked `NewHistoryDialogPane *g_pNewHistoryDialog = 0;` definition at position `0` in UID0000LQ `NexusTK/login/NewHistoryDialogPane.cpp`; the physical page emits no duplicate definition.
- Complete source closure: UID000091 emits a fieldless `NewHistoryDialogPane : public DialogPane, public Singleton<NewHistoryDialogPane>` class at position `10`; UID0001A3 emits its constructor plus exact `HandleKeyOrTextEvent(Event *)` and `HandlePointerOrMouseEvent(Event *)` definitions at position `20`.
- Compiler closure: UID0001A8 is the direct Singleton base destructor instantiated for constructor unwind, UID0001AC contains two receiver-adjusting destructor thunks, and UID0001AH is the scalar deleting wrapper. All three are class-owned, false/non-emitting, and formally blank. No explicit NewHistoryDialogPane destructor remains in human source.
- Data closure: exact physical vtable child UID0004VL `by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md` and semantic inventory UID0004VM `by-type/by-vtable/NewHistoryDialogPaneVtables.md` were registered serially. Both are source-declared/compiler-generated, false/non-emitting, and blank.
- Confidence: very strong for bytes, refs, PE loader state, direct Singleton source cause, class layout, method behavior, vtable/RTTI extent, source/compiler split, and one-definition route; high for original private/local lexical spelling and retained-source liveness because symbols and a surviving constructor entry route are absent.
- Current report state: B004 completed the accepted implementation callback, scoped validators, and final waited generated readback at the canonical report path. B004 manually edited no coverage/generated/tracker/audit/supervisor/validator-state/IDA/lifecycle file and performed no execute, move, archive, or report lifecycle action. External report validation/execution/count/path/archive state is supervisor/validator-owned and not asserted by this artifact.

## Supporting Research

- Mandatory live IDA evidence used active NexusTK database `9b0396a3`. Fresh MCP discovery and health checks reported `status:ok`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready, strings ready, and a real bounded target read.
- Current executable: `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- Concrete report search terms were `UID0001PV`, `0001PV`, `0x0069b49c`, `0069b49c`, `g_pNewHistoryDialog`, `NewHistoryDialogPane`, `0x00500410`, `00500410`, `HISTORYN`, `MADEBY`, `Singleton<NewHistoryDialogPane>`, and owner/login/main-menu/source-family terms.
- `tools/leaser/Agents/Older-Research/**` contains three Markdown files; the complete term set produced no direct or incidental target match.
- `tools/leaser/Agents/SpecialReports/**` contains five Markdown files; the complete term set produced no direct or incidental target match.
- Actual project archive root `archived/**` contains no Markdown report and produced no match. No missing or invented `tools/leaser/Agents/archived` root was treated as evidence.
- Active agent research roots were searched. No direct UID0001PV report existed; administrative/shared notes were not treated as target authority.
- Central `executed-b-agent-research/**` was searched and relevant matches were opened:
  - `executed-b-agent-research/B003/0001A3-new-history-dialog-pane-core-source-quality.md`, SHA256 `B5876B49D98A1D0A64869E8956617192A05E390079B656CB6A735CB490373E93`, is the direct core lead. Current evidence preserves its resource/rectangle/padding behavior but supersedes explicit singleton publication, stale input names, raw layer aliasing, and by-value EPF bounds.
  - `executed-b-agent-research/B005/0001AH-0001AJ-NewHistoryStaffsDialogPaneDestructorPair-source-quality.md`, SHA256 `2B4E09FFAF2E2F7766A47F5E38F83F728BB3A3F8152AA9ED994607B0BA59D846`, is the destructor lead. Current RTTI/EBO evidence supersedes its authored NewHistory destructor-clear conclusion.
  - `executed-b-agent-research/B002/00019X-ScrolledTextControlPaneForMadeByCore-source-quality.md`, SHA256 `FBD7C700D3CB3E05EB7F45166174DFDC2B1BF4C2C4877FD600D15BFEF60972BA`, establishes the sole runtime read, strict scroll-end close, and `MADEBY` ownership; live MCP independently reconfirmed that read.
  - `executed-b-agent-research/B002/0002AF-g_pMainUiGraph-source-quality.md`, SHA256 `87CCCE75D2F8158D9DF8591DEB474325AED63888DB3CBC8AE67AE41AD5988ABF`, supports current `g_pMainMenuPane` and overlay-layer separation.
  - `executed-b-agent-research/B014/0001A2-BackStoryDialogPaneCore-source-quality.md`, SHA256 `C70077A28344B5A178372A720ED3A19B73CD971CC7260718E1A26D7D86578CDD`, and `executed-b-agent-research/B001/0001A1-HistoryViewingPaneCore-source-quality.md`, SHA256 `48C74A808DAA9793F4E906A649A5BA880E56F31281B35BCA483E8FDAA3110081`, are adjacent-family controls, not substitutes for target evidence.
- There is no prior direct UID0001PV report. Old reports are evidence-time leads only; current binary, MCP, ordinary docs, generated output, and source routing are authority.

## Target

- Target UID: `0001PV`.
- Target path: `by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md`.
- Queue: validator-owned tracker `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Historical pre-callback metadata: `86/90`, owner/emitter UID0000RS, reconstructable true, blank position/formal C++, `Nested:0`. Current terminal metadata is `92/94`, owner UID0000RS, false, blank emitter/position/formal C++, `Nested:0`.
- Evidence-time ordinary hash: `7F3C7DCEEF7AE8701AEB740161A48B440A850F5B2F6FCC0E2F94CC8048A755F7`, 9,180 bytes / 88 lines.
- Exact live bytes: `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.

## Current Target State

- Implementation and scoped validation are complete across D1-D12. UID0001PV is now `92/94`, owner UID0000RS, false/non-emitting, blank emitter/position/formal C++, and `Nested:0`; all exact zero-byte, virtual-tail, five-ref, adjacency, history, and no-code evidence is retained.
- D9/D10 were registered serially as UID0004VL and UID0004VM. UID0001A8 and UID0001AH were renamed once through validator-aware UID-preserving moves; both old paths are absent and each UID has exactly one ordinary header.
- The source union is now one UID0000RS global definition at position 0, one complete UID000091 class at position 10, and one UID0001A3 constructor-plus-two-callback block at position 20. Compiler Singleton publication/clear, vptr, EH, adjustor, scalar-delete, RTTI, and raw-vtable artifacts remain non-emitting.
- Final B004 waited validator command/header `000000016111`, refreshed `2026-07-21T17:30:34-04:00`, produced `auto-generated/NexusTK/login/NewHistoryDialogPane.cpp` SHA256 `EC6F1F15511B2E582E4724C0D76478D32F8BEA5676DF4BA4FA753B44BA5C6E45`, 2,328 bytes / 75 lines, and `auto-generated/NexusTK/ui/controls/ScrolledTextControlPane.cpp` SHA256 `7F67B24A649984E5E8E157904E7547A544B84BC432C5828773CCC19B885343E2`, 4,822 bytes / 143 lines.
- At command 16111, NewHistoryDialogPane.cpp contains exactly one global definition, one complete class, one constructor, one `HandleKeyOrTextEvent`, and one `HandlePointerOrMouseEvent`; it contains zero explicit destructor, target/compiler/data UID marker, target Empty Emitter Marker, publication/clear, raw ABI body, stale handler/API name, raw layer token, or by-value EPF bounds. ScrolledTextControlPane.cpp contains exactly one `g_pNewHistoryDialog->CloseDialog()` route and zero duplicate global definition.
- At the final B004 readback, external tracker command/header `000000016126`, refreshed `2026-07-21T17:43:11-04:00`, had SHA256 `C35E1A5269721102BE18480DF47D05F2D9DF1E473F04D8AFCCFDC1AF9635224D`, 1,551,132 bytes / 6,274 lines; its UID0001PV row records `92/94`, false, `Nested:0`. This is time-bounded external evidence and later unrelated validator epochs may advance it without changing durable implementation proof. Command 16111 remains the B004 waited generated proof; command 16123 and its prior tracker hash plus commands 15993/15994/15999/16000 are historical checkpoints, not current implementation authority.
- Manual coverage remains supervisor-owned and unapplied. Its current readback and exact real-UID handoff are retained below. B004 manually edited no coverage, generated, tracker, audit, supervisor, validator-state, IDA, lifecycle, queue, lock, or archive file.

## Executive Recommendation

- Applied: UID0001PV is physical evidence only and its source meaning routes to UID0000RS.
- Applied: UID000091 and UID0001A3 now yield one definition, one complete class, one constructor, and two input overrides in dependency order.
- Applied: emitted source omits handwritten Singleton publication/clear, explicit destructor, vptr/EH/delete mechanics, decompiler labels, and stale event APIs.
- Applied: UID0001A8 and UID0001AH have their accepted UID-preserving names, and D9/D10 are registered as UID0004VL/UID0004VM with no provisional token remaining.
- Preserved: scroller consumer, main-menu layer/show dependencies, resource page, adjacent globals, and unrelated read-only children retain their accepted scores, formals, and facts.

## Supervisor Active Recheck

- Assignment scope includes raw/virtual bytes, all five refs, constructor liveness, one-definition ownership, direct Singleton lowering, complete class and methods, compiler support, exact vtable/RTTI data, source placement, score blockers, and manual handoff.
- The four-byte target does not split. The independently bounded `[0x0061daf0,0x0061db8c)` vtable/RTTI cluster requires exact physical and semantic pages.
- Every source-bearing destination has complete destination-ready C++ below. Every intentionally blank destination has a target-specific compiler/data/physical no-code proof.
- No investigable blocker is deferred. Missing original symbols and missing runtime constructor entry cap confidence but do not block a behavior-exact human source form.

## Inference Research Guidance Check

- Direct facts: target bytes, PE section arithmetic, exact xrefs, function extents, instructions, call operands, vtable cells, RTTI descriptors/PMDs, resource addresses, padding, and absence of constructor routes.
- Documentation facts: current UIDs, DialogPane/Event/EventMan/EPF/scroller contracts, MainUiLayerSlots names, main-menu parent, source tree, resource route, generated order, and coverage rows.
- Inferences: original lexical names beyond accepted project contracts, retained linked-source classification, and whether the original initializer token was `0` or `NULL`. The recommendation chooses project-consistent C++03 `0` and caps confidence rather than preserving a blocker.
- Historical docs were revalidated claim by claim. Stale `0xffffffff`, explicit assignment/clear, old handler names, and old raw aliases are rejected rather than inherited.

## Heuristic / Inference Reanalysis And Validation

- Zero versus `0xffffffff`: live bytes plus PE virtual-tail mapping prove zero. The historical `ff ff ff ff` claim cannot describe this executable because the slot has no raw-file mapping.
- Physical versus semantic owner: UID0001PV is one physical four-byte slot. UID0000RS is the semantic global and sole source definition. Emitting both violates one-definition behavior.
- Linkage: a class-external scroller source reads the pointer, so file-local static and private class-static alternatives are rejected. The accepted external global name is already project-wide and type-consistent.
- Direct Singleton base: constructor computes the base at `this+0x26c`, subtracts `0x26c`, and stores the complete object. RTTI independently identifies `Singleton<NewHistoryDialogPane>` PMD `{0x26c,-1,0}`. This is template-base publication, not handwritten assignment.
- Destructor source cause: constructor unwind calls the eleven-byte direct-base destructor; the scalar wrapper clears before `DialogPane::~DialogPane()`, consistent with reverse direct-base teardown. Removing compiler/base mechanics leaves no authored destructor statement, so the highest-probability source omits an explicit destructor declaration and body.
- Class layout: DialogPane occupies `0x26c`; direct empty Singleton begins at one-past offset `+0x26c` and adds no member. EventHandler `+0xa0` and TimerHandler `+0xa4` are inherited through DialogPane, not repeated direct bases.
- Input identity: secondary vtable slots and current base declarations prove `HandlePointerOrMouseEvent(Event *)` and `HandleKeyOrTextEvent(Event *)`. Stale const-reference `OnMouseInput`/`OnKeyInput` names are rejected.
- Event shape: type byte `+0x04`, key byte `+0x08`, and modifiers `+0x10a` map exactly to current `Event::m_type` and `EventPayload::m_key`. Event values `3/6/8` are current enum names, not local constants.
- Close contract: `CloseDialog()` is public on DialogPane specifically because the unrelated made-by scroller invokes it through the global. `Close()` is stale.
- Resource constructor: current EPFImageControlPane accepts `const RectBounds *`; the old by-value `rect` call is compile-incompatible and the applied source uses `&bounds`.
- Layer/show route: `0x0069b36c` is `g_mainUiLayerSlots.overlayPaneLayerContext`; `0x0067aba4` is `g_pMainMenuPane`. They are distinct operands.
- Constructor liveness: ordinary xrefs, absolute VA, RVA, raw dword, rel32 call/jump, and dynamic pointer scans found no route to `0x00500410`. Positive controls found each input/wrapper address in its vtable and the primary vtable in the constructor. Retained linked source with a removed historic launcher is stronger than inventing a caller or classifying authored resource construction as compiler-only.
- Vtable/RTTI: three views, 36 slots total, eight base descriptors, three COLs, and constructor stores are compiler products of the complete declaration. No raw array or explicit RTTI source is warranted.
- Rejected alternatives: physical-page emitter, duplicate definition, static pointer, class static member, explicit Singleton specialization source in this file, authored publish/clear, authored EH helper, authored adjustor thunks, authored scalar wrapper, explicit empty destructor, hand-written vtables, MainMenuPane ownership, scroller ownership, HistoryViewingPane identity, BackStory identity, raw event structs, local event constants, stale `NarrowKeyCode`, stale `Close`, and raw `dword_69B36C`.

## Evidence Standards Used

- Highest weight: current executable bytes, valid bounded MCP, PE arithmetic, decompile/disassembly, exact xrefs, RTTI/PMD, vtable cells, and range hashes.
- Supporting weight: current ordinary docs, accepted project contracts, proposed source tree, current generated output, current manual rows, and independently revalidated executed reports.
- Negative evidence is bounded and reproducible: zero constructor xrefs, zero absolute/RVA/raw/rel32 routes, exactly five target refs, no other writer/read, and no direct prior report.
- Binary facts and accepted project APIs are separated from inferred lexical/source-retention conclusions. Residual lexical uncertainty caps confidence without blocking implementation.

## Evidence Checked

- MCP transport: current streamable endpoint, `idb_list`, `server_health`, bounded `get_bytes`, `xref_query`, lookup, decompile, disassembly, data reads, RTTI, and vtable checks on database `9b0396a3`.
- Fresh MCP health immediately before source closure remained `status:ok`; fresh `xref_query` returned five target refs and zero constructor refs.
- Target and neighbors checked: `0x0069b498-0x0069b4a4`; target is four zeros between UID00029F and UID0001PW.
- Functions checked: constructor `0x00500410`, key handler `0x005005c0`, pointer handler `0x00500610`, Singleton base destructor `0x005023e0`, thunks `0x005024f8/0x00502503`, scalar wrapper `0x00502920`, scroller timer `0x004ff6c0`, DialogPane close/create/show helpers, and EventMan translation helper `0x004a8b10`.
- Data checked: target slot, vtable cluster `0x0061daf0-0x0061db8c`, RTTI `0x0064aa80-0x0064ab48`, resources `HISTORYN.EPF`, `HISTORYN.PAL`, `MADEBY`, main-menu parent, and overlay layer context.
- PE/raw checks: DOS/PE headers, section table, target raw mapping, constructor VA/RVA/raw scans, direct rel32 route scan, and vtable/function-pointer positive controls.
- Current ordinary docs checked: D1-D15 plus Event, EventHandler, EventMan, DialogPane, EPFImageControlPane, MainUiLayerSlots, g_pMainMenuPane, resource and neighboring singleton pages.
- Generated files checked read-only: current NewHistoryDialogPane.cpp baseline and ScrolledTextControlPane.cpp, whose made-by timer contains one `g_pNewHistoryDialog->CloseDialog()` route.
- Manual coverage checked read-only: by-memory, by-global, by-class, by-file, by-resource, and by-type/by-vtable.
- Historical roots and exact matching reports are listed under Supporting Research. No fallback-only or stale-IDB conclusion was used.
- No validator, generated refresh, ordinary edit, coverage edit, tracker edit, IDA mutation, lifecycle command, execute, move, or archive action was performed.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1PV-001 | Target range is exactly `[0x0069b49c,0x0069b4a0)`. | very high | MCP bytes; adjacent pages | D1 | incorporate | applied |
| C1PV-002 | Target bytes are exactly `00 00 00 00`. | very high | valid bounded get_bytes | D1 | incorporate | applied |
| C1PV-003 | Four-byte target hash is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | very high | exact byte hash | D1 | incorporate | applied |
| C1PV-004 | Target is loader-zero `.data` virtual-tail storage with no raw backing. | very high | PE section arithmetic | D1/D2 | incorporate | applied |
| C1PV-005 | Historical `0xffffffff` is stale and must be historicalized. | very high | C1PV-002/004 | D1/D2/manual | reject-stale | excluded-with-reason |
| C1PV-006 | Exact neighbors are UID00029F ending at `0x0069b49c` and UID0001PW starting at `0x0069b4a0`. | very high | current pages/bytes | D1/D15 | incorporate | applied |
| C1PV-007 | Exactly five direct target refs exist. | very high | live xref_query | D1/D2 | incorporate | applied |
| C1PV-008 | `0x004ff6eb` is the sole runtime read and closes the dialog at strict scroll end. | very high | live timer decompile | D1/D2/D13 | incorporate | applied |
| C1PV-009 | `0x00500465/0x0050046c` are compiler Singleton publication/null-fallback writes. | very high | ctor disasm/RTTI | D1/D2/D5 | incorporate | applied |
| C1PV-010 | `0x005023e0` is constructor-EH direct Singleton base destruction. | very high | helper bytes/xref/RTTI | D6/D12 | incorporate | applied |
| C1PV-011 | `0x00502926` is scalar-wrapper direct Singleton base clear. | very high | wrapper disasm/order | D8/D12 | incorporate | applied |
| C1PV-012 | Exact source type is `NewHistoryDialogPane *`. | very high | ctor/vtable/RTTI/consumer | D1-D3 | incorporate | applied |
| C1PV-013 | `g_pNewHistoryDialog` is the strongest project source-facing name. | high | current contracts/family | D1-D3 | incorporate | applied |
| C1PV-014 | The global requires external linkage. | very high | cross-file scroller read | D2-D4 | incorporate | applied |
| C1PV-015 | UID0001PV is false/non-emitting with blank C++. | very high | one-definition policy | D1 | incorporate | applied |
| C1PV-016 | UID0000RS owns the sole typed definition. | very high | semantic route | D2 | incorporate | applied |
| C1PV-017 | Zero initializer spelling is the highest-probability C++03 source form. | high | loader value/project peers | D2 | incorporate | applied |
| C1PV-018 | Emitter order is global 0, class 10, core 20. | high | dependency/source order | D2-D5 | incorporate | applied |
| C1PV-019 | Constructor range is `[0x00500410,0x005005b4)`, hash `EB7F4F7B4421DE11379B354F6FF2AA403369EF8A65E917005411889CC1B1422E`. | very high | exact bytes/function | D5 | incorporate | applied |
| C1PV-020 | Key handler range is `[0x005005c0,0x00500605)`, hash `4BE5543D1CCAA453990BC1CA022BF209D7025FED42F4BB66BD33BABC6574649C`. | very high | exact bytes/function | D5 | incorporate | applied |
| C1PV-021 | Pointer handler range is `[0x00500610,0x00500632)`, hash `BE4FFDE21CA4C27992A30ECC5FC05A961878A7B2F138E51032837F3D9044DF56`. | very high | exact bytes/function | D5 | incorporate | applied |
| C1PV-022 | Complete core range hash is `0289E4573FD4701EBE334B6029869D921F15D581499881209DA8D56084C52D4E`. | very high | exact bytes | D5 | incorporate | applied |
| C1PV-023 | Internal padding is exact 12/11 CC bytes with hashes `A0D08A...30902` and `3682C0...E0943`. | very high | exact bytes | D5/D12 | incorporate | applied |
| C1PV-024 | NewHistoryDialogPane directly derives from DialogPane. | very high | RTTI/ctor | D3/D5/D9/D10 | incorporate | applied |
| C1PV-025 | NewHistoryDialogPane directly derives from Singleton<NewHistoryDialogPane>. | very high | RTTI/ctor adjustment | D3/D5/D6/D8-D10 | incorporate | applied |
| C1PV-026 | Singleton PMD `+0x26c/-1/0` proves one-past empty-base optimization and size `0x26c`. | very high | RTTI/alloc size | D3/D5/D9/D10 | incorporate | applied |
| C1PV-027 | EventHandler `+0xa0` and TimerHandler `+0xa4` are inherited through DialogPane. | very high | RTTI/vptrs | D3/D7/D9/D10 | incorporate | applied |
| C1PV-028 | NewHistoryDialogPane has no authored data members. | very high | size/base coverage/ctor | D3 | incorporate | applied |
| C1PV-029 | Exact vtable/RTTI physical cluster is `[0x0061daf0,0x0061db8c)`, hash `BA7C96EB88036F4D54AC50D72A74A0CA697655B45F4B8F1AAA13256C0EBF9D26`. | very high | exact bytes/boundaries | D9-D11 | create | applied |
| C1PV-030 | Cluster contains primary/secondary/tertiary views with 23/11/2 slots. | very high | dword decode | D9/D10 | incorporate | applied |
| C1PV-031 | RTTI has eight descriptors: class, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, Singleton. | very high | CHD/BCD records | D3/D9/D10 | incorporate | applied |
| C1PV-032 | Three constructor vptr stores are compiler lowering. | very high | ctor/vtable xrefs | D5/D9/D10 | reject-stale | excluded-with-reason |
| C1PV-033 | Constructor publication is implicit Singleton base construction, not authored source. | very high | adjustment/RTTI | D2/D5 | reject-stale | excluded-with-reason |
| C1PV-034 | UID0001A8 is compiler base destruction with blank C++. | very high | 11 bytes/EH-only route | D6 | incorporate | applied |
| C1PV-035 | UID0001AC is two compiler adjustor thunks with blank C++. | very high | exact thunk bytes/vtable refs | D7 | incorporate | applied |
| C1PV-036 | UID0001AH is a compiler scalar deleting wrapper with blank C++. | very high | flags/delete/base teardown | D8 | incorporate | applied |
| C1PV-037 | Human source omits an explicit NewHistoryDialogPane destructor. | high | no authored remainder/symbol | D3/D8 | reject-stale | excluded-with-reason |
| C1PV-038 | Constructor creates full-screen HISTORYN image control at `(0,0)-(1024,768)`. | very high | ctor decompile/literals | D5/D15 | incorporate | applied |
| C1PV-039 | Constructor creates MADEBY scroller at `(614,156)-(950,556)` with interval 30. | very high | ctor decompile | D5/D13/D15 | incorporate | applied |
| C1PV-040 | Constructor sets HISTORYN background frame 0 and mode 1. | very high | exact calls | D5 | incorporate | applied |
| C1PV-041 | Create route uses `g_mainUiLayerSlots.overlayPaneLayerContext`. | high | operand/current support | D5/D14 | incorporate | applied |
| C1PV-042 | Show route uses `g_pMainMenuPane` as the distinct before-pane operand. | very high | operand/current support | D5/D14 | incorporate | applied |
| C1PV-043 | Key callback handles only `kEventKeyDown`. | very high | exact branch/Event contract | D3/D5 | incorporate | applied |
| C1PV-044 | Key translation uses current Event key/modifier payload fields and EventMan API. | very high | offsets/API support | D5 | incorporate | applied |
| C1PV-045 | Enter, Escape, and Space close the dialog; all other keys do not. | very high | exact comparisons | D5 | incorporate | applied |
| C1PV-046 | Pointer callback closes only on left/right button up. | very high | exact comparisons | D3/D5 | incorporate | applied |
| C1PV-047 | Both callbacks always return true. | very high | exact returns | D5 | incorporate | applied |
| C1PV-048 | Made-by timer is a non-null-assumed runtime consumer and remains ScrolledTextControlPane-owned. | very high | live decompile/current docs | D13 | verify-only | already-present |
| C1PV-049 | Constructor has zero inbound IDA xrefs. | very high | live xref_query | D4/D5 | incorporate | applied |
| C1PV-050 | VA/RVA/raw/rel32 scans find no constructor route while vtable positive controls succeed. | very high | bounded PE scan | D4/D5 | incorporate | applied |
| C1PV-051 | Retained linked source with removed launcher is the highest-probability liveness disposition. | high | resources/vtables/methods/no route | D4/D5 | incorporate | applied |
| C1PV-052 | Exact source route is `NexusTK/login/NewHistoryDialogPane.cpp`. | very high | proposed tree/family/resources | D4 | incorporate | applied |
| C1PV-053 | UID0001RF already owns HISTORYN/MADEBY packaging evidence and remains unchanged. | very high | current resource page | D15 | verify-only | already-present |
| C1PV-054 | MainUiLayerSlots, g_pMainMenuPane, MainMenuPane, Event, and control classes are dependencies, not owners. | very high | source boundaries/contracts | D14/D15 | verify-only | already-present |
| C1PV-055 | UID000091 carries one complete fieldless class declaration and extern contract. | very high | compile/source closure | D3 | incorporate | applied |
| C1PV-056 | UID0000RS carries one forward declaration plus the sole global definition. | very high | compile/source closure | D2 | incorporate | applied |
| C1PV-057 | UID0001A3 carries one source-clean constructor and two callback definitions. | very high | exact bodies/contracts | D5 | incorporate | applied |
| C1PV-058 | EPF bounds argument must be `&bounds`, not by-value. | very high | current constructor signature | D5 | reject-stale | excluded-with-reason |
| C1PV-059 | Stale OnKeyInput/OnMouseInput/NarrowKeyCode/Close/raw-layer names must be replaced. | very high | current API contracts | D3/D5 | reject-stale | excluded-with-reason |
| C1PV-060 | Target score/disposition is `92/94`, false, owner UID0000RS, blank emitter/position/C++, Nested 0. | high | all target blockers closed | D1 | incorporate | applied |
| C1PV-061 | Semantic global is `92/94`, owner/emitter UID0000LQ, position 0. | high | type/linkage/definition closure | D2 | incorporate | applied |
| C1PV-062 | Class is `92/94`, owner/emitter UID0000LQ, position 10. | high | complete class/layout closure | D3 | incorporate | applied |
| C1PV-063 | File is `92/93` with complete source/compiler union. | high | source route/liveness cap | D4 | incorporate | applied |
| C1PV-064 | Core is `92/94`, owner/emitter UID0000LQ, position 20. | high | exact source-ready bodies | D5 | incorporate | applied |
| C1PV-065 | D6-D8 are `92/96`, class-owned, false/non-emitting, blank, Nested 0. | very high | exact compiler identities | D6-D8 | incorporate | applied |
| C1PV-066 | D9 physical vtable page is new `92/96`, class-owned, false, blank, Nested 0. | very high | exact bounded compiler data | D9 | create | applied |
| C1PV-067 | D10 semantic vtable inventory is new `92/96`, class-owned, false, blank. | very high | source-declared/generated-binary cause | D10 | create | applied |
| C1PV-068 | UID00025Q remains `86/92`, false, owner NONE, with exact NewHistory child added no-loss. | very high | mixed aggregate boundary | D11 | incorporate | applied |
| C1PV-069 | Ignored padding/helper/thunk/wrapper rows require exact hashes and renamed links only. | very high | current ignored union | D12 | incorporate | applied |
| C1PV-070 | Scroller consumer pages remain verify-only and unchanged. | very high | live/current parity | D13 | verify-only | already-present |
| C1PV-071 | Resource page remains `90/93` and requires no source/score change. | very high | current exact resource union | D15 | verify-only | already-present |
| C1PV-072 | Main-menu/UI/adjacent singleton dependencies remain verify-only. | very high | current exact support | D14/D15 | verify-only | already-present |
| C1PV-073 | by-memory manual rows require literal same-or-greater unions that preserve every current linked fact before adding NewHistory deltas, plus one new physical row without changing the UID0002OV successor. | very high | current row readback/no-loss comparison | manual handoff | incorporate | applied |
| C1PV-074 | by-global UID0000RS manual row requires a literal same-or-greater union preserving C001, the linked UID0000LQ route, saved IDA names, no constructor-start xrefs, and cleanup-helper provenance before adding resolved source facts. | very high | current row readback/no-loss comparison | manual handoff | incorporate | applied |
| C1PV-075 | by-class UID000091 manual row requires a literal same-or-greater union preserving the direct-constructor reachability caveat before adding the complete class contract. | very high | current row readback/no-loss comparison | manual handoff | incorporate | applied |
| C1PV-076 | by-file UID0000LQ manual row requires a literal same-or-greater union preserving the existing route, support, padding, thunk/EH, and direct-constructor reachability facts before adding the complete file union. | very high | current row readback/no-loss comparison | manual handoff | incorporate | applied |
| C1PV-077 | by-vtable manual coverage requires one real-UID row after registration at the exact UID0001Y9/UID0001YA insertion boundary. | very high | current absence/readback and exact anchor comparison | manual handoff | incorporate | applied |
| C1PV-078 | Final generated output contains one global/class/three source definitions and no physical/compiler marker. | very high | emitter policy/formals | final assertions | incorporate | applied |
| C1PV-079 | IDA rename/type recommendations are evidence-only and require no mutation in this assignment. | high | source identity closure | IDA recommendations | verify-only | already-present |
| C1PV-080 | No investigable source, split, ownership, score, or formal blocker remains. | high | full evidence/destination closure | report/checklist | incorporate | applied |

### Terminal Callback Destination Proof

Each terminal ledger row retains its claim-specific binary/source evidence and destination columns above. The following proof index ties every C1PV claim to the current destination validator/readback that independently establishes its terminal state; current hashes and command metadata are recorded under Validator Results and Changed Files.

| Destination/proof | Claim-specific coverage | Terminal proof |
| --- | --- | --- |
| D1 UID0001PV | C1PV-001-C1PV-015, C1PV-060 | Command 16101 applied exact range/zero bytes/virtual-tail/five-ref/adjacency/history/one-definition metadata; command 16111 reconfirmed `92/94`, false, blank emission, and no target marker. |
| D2 UID0000RS | C1PV-004-C1PV-005, C1PV-007, C1PV-009, C1PV-012-C1PV-018, C1PV-033, C1PV-056, C1PV-061 | Command 16102 applied the sole externally linked typed zero definition, compiler-lifetime exclusions, source route, and emitter position 0. |
| D3 UID000091 | C1PV-012, C1PV-024-C1PV-028, C1PV-031, C1PV-037, C1PV-043, C1PV-046, C1PV-055, C1PV-062 | Command 16103 applied the complete fieldless DialogPane/Singleton class, Event virtuals, implicit destructor, EBO/layout evidence, extern contract, and position 10. |
| D4 UID0000LQ | C1PV-014, C1PV-049-C1PV-052, C1PV-063 | Command 16105 applied `92/93` and the no-loss source/compiler/resource/consumer union while retaining the exhausted no-constructor-route caveat. |
| D5 UID0001A3 | C1PV-009, C1PV-018-C1PV-026, C1PV-032-C1PV-033, C1PV-038-C1PV-047, C1PV-049-C1PV-051, C1PV-057-C1PV-059, C1PV-064 | Commands 16106/16107 applied the exact accepted constructor/key/pointer formal, hashes, resources, APIs, compiler exclusions, and corrected MainUiLayerSlots UID at position 20. |
| D6 UID0001A8 | C1PV-010, C1PV-025, C1PV-034, C1PV-065 | Command 16092 completed the one-move UID-preserving rename and applied the exact Singleton base-destructor, `92/96`, false/blank disposition. |
| D7 UID0001AC | C1PV-027, C1PV-035, C1PV-065 | Command 16099 applied the two exact `-0xa0/-0xa4` compiler adjustors, vtable routes, hash, ownership, and blank C++. |
| D8 UID0001AH | C1PV-011, C1PV-025, C1PV-036-C1PV-037, C1PV-065 | Command 16093 completed the one-move UID-preserving rename and applied the exact scalar-wrapper/base/delete-flag no-code proof at `92/96`. |
| D9 UID0004VL | C1PV-024-C1PV-032, C1PV-066 | Commands 16086/16110 serially registered and finalized the exact physical range, 23/11/2 views, RTTI/EBO, hash, boundaries, `Nested:0`, semantic cross-link, and blank C++. |
| D10 UID0004VM | C1PV-024-C1PV-032, C1PV-067 | Command 16090 serially registered the semantic class-owned three-view/eight-descriptor compiler inventory at `92/96` with blank C++. |
| D11 UID00025Q | C1PV-029, C1PV-068 | Command 16108 preserved `86/92`, NONE/FALSE/blank aggregate state and every existing child while adding UID0004VL immediately before UID0002OV. |
| D12 UID0000VN | C1PV-010-C1PV-011, C1PV-023, C1PV-069 | Command 16109 applied the two full padding hashes and exact renamed base/thunk/wrapper evidence without unrelated-row loss. |
| D13 scroller union | C1PV-008, C1PV-039, C1PV-048, C1PV-070 | Current UID00019X/class/file hashes were reread unchanged; command-16111 ScrolledTextControlPane.cpp has exactly one non-null-assumed target close route and no duplicate definition. |
| D14 dependency union | C1PV-041-C1PV-042, C1PV-054, C1PV-072 | MainUiLayerSlots, g_pMainMenuPane, MainMenuPane, DialogPane, Event, EventMan, and EPFImageControlPane were reread unchanged at the hashes under Changed Files/verify-only proof. |
| D15 resource/adjacent union | C1PV-006, C1PV-038-C1PV-039, C1PV-053-C1PV-054, C1PV-071-C1PV-072 | UID0001RF remains `90/93`; UID00029F and UID0001PW remain exact same-level neighbors and all resource payload/caveat facts are unchanged. |
| Manual handoff | C1PV-073-C1PV-077 | All six current manual roots and exact rows/anchors were reread after the later unrelated Staffs coverage epoch; real UIDs 0004VL/0004VM and the complete current Staffs union are present in literal destination-ready text, while NewHistory coverage remains supervisor-owned and unapplied. |
| Generated proof | C1PV-078 | Command 16111 produced the exact one global/class/constructor/key/pointer counts and all target/compiler/data/stale-source negative counts stated under Current Target State and Validator Results. |
| IDA boundary | C1PV-079 | IDA names/types remain evidence-only; no IDA mutation occurred during the callback. |
| Report closure | C1PV-080 | Ten formal blocks compare byte-for-byte equal, all 80 ledger rows are terminal, all 58 checklist rows are checked, no provisional token or implementation blocker remains, and zero leases remain. |

## Positive Evidence Summary

- Live zero bytes and PE virtual-tail mapping establish exact initializer behavior independently.
- Five refs form a closed lifecycle/runtime set: four compiler-lowered writes and one source consumer read.
- Constructor adjustment and RTTI PMD independently prove direct Singleton inheritance and complete-object publication.
- The complete class size is fully explained by DialogPane plus an empty direct base; no opaque field or padding member is needed.
- Exact constructor resources, rectangles, controls, mode, layer, and show parent produce destination-ready human source.
- Secondary vtable slots, Event layout, and DialogPane contracts close both callback names and signatures.
- Three vtable views, eight RTTI descriptors, and exact predecessor/successor boundaries close data ownership and compiler disposition.
- The source tree explicitly routes this class to `login/NewHistoryDialogPane.cpp`; HISTORYN/MADEBY and g_pMainMenuPane reinforce that route.

## IDA MCP Facts

- Database: `9b0396a3`; server health `ok`; imagebase `0x00400000`; analysis, Hex-Rays, and strings ready.
- Target read: four zero bytes; five xrefs; `more:false`/complete result.
- Constructor `sub_500410`: `0x1a4` bytes, no inbound xrefs.
- Key handler `sub_5005C0`: `0x45` bytes. Pointer handler `sub_500610`: `0x22` bytes.
- Singleton base destructor `sub_5023E0`: `0x0b` bytes. Scalar wrapper `sub_502920`: `0x45` bytes.
- Live scroller timer decompile at `0x004ff6c0` reads the target, closes through `0x0049dad0`, repaints, and returns true.
- Primary/secondary/tertiary vtable address points are `0x0061daf4`, `0x0061db54`, and `0x0061db84`; COLs are `0x0064aa80`, `0x0064ab34`, and `0x0064ab48`.

## Function / Child Inventory

| Range | Role | Source/ABI disposition | Hash / key proof |
| --- | --- | --- | --- |
| `[0x00500410,0x005005b4)` | constructor | authored source | `EB7F4F...B1422E` |
| `[0x005005b4,0x005005c0)` | alignment | ignored compiler/linker | 12 CC, `A0D08A...30902` |
| `[0x005005c0,0x00500605)` | HandleKeyOrTextEvent | authored source | `4BE554...4649C` |
| `[0x00500605,0x00500610)` | alignment | ignored compiler/linker | 11 CC, `3682C0...E0943` |
| `[0x00500610,0x00500632)` | HandlePointerOrMouseEvent | authored source | `BE4FFD...44DF56` |
| `[0x005023e0,0x005023eb)` | Singleton base destructor | compiler EH support | `1B4651...245939` |
| `[0x005024f8,0x00502503)` | EventHandler destructor thunk | compiler ABI | receiver `-0xa0` |
| `[0x00502503,0x0050250e)` | TimerHandler destructor thunk | compiler ABI | receiver `-0xa4` |
| `[0x00502920,0x00502965)` | scalar deleting wrapper | compiler ABI | `6C80FD...B9A58C` |
| `[0x0061daf0,0x0061db8c)` | three-view vtable/RTTI data | source-declared/generated binary | `BA7C96...F9D26` |

- UID0001A3 remains the source method cluster; D6/D8 receive UID-preserving title corrections, not new UIDs.
- D9/D10 are the only new pages. Register D9 first, capture its real UID, then D10; no placeholder may survive cross-linking.

## Direct Xref / Caller Inventory

| Ref | Function | Exact role | Source ownership |
| --- | --- | --- | --- |
| `0x004ff6eb` | ScrolledTextControlPaneForMadeBy::OnTimerEvent | sole runtime read, close at strict end | scroller source consumer |
| `0x00500465` | NewHistoryDialogPane constructor | adjusted complete-object publication | compiler Singleton lowering |
| `0x0050046c` | NewHistoryDialogPane constructor | adjusted-null fallback | compiler Singleton lowering |
| `0x005023e0` | Singleton base destructor | constructor-unwind clear | compiler base lowering |
| `0x00502926` | scalar deleting wrapper | reverse-base clear | compiler ABI/base lowering |

- No ordinary xref reaches constructor start `0x00500410`.
- Exact absolute VA/RVA/raw-dword and direct rel32 call/jump scans found no constructor route.
- Positive controls: key handler pointer occurs once at `0x0061db5c`, pointer handler once at `0x0061db58`, scalar wrapper once at `0x0061daf4`, and the primary vtable address occurs in the constructor.

## Documentation Evidence And IDA Status

- Target/global/class/file/core/compiler pages were reread immediately before each accepted edit and again after scoped validation; final hashes are recorded under Changed Files.
- Current Event and DialogPane declarations supply mutable Event-pointer signatures, current event enum names, payload fields, and public CloseDialog.
- Current EPFImageControlPane declaration proves the bounds-pointer correction.
- Current MainUiLayerSlots/g_pMainMenuPane docs prove the two constructor operands are distinct and accepted.
- Current resource page already records one-frame HISTORYN.EPF, HISTORYN.PAL, and MADEBY payload ownership; it is verify-only.
- Command-16111 generated output is the final callback readback. Historical pre-callback command 15999 remains evidence of the corrected source defects, not current authority.
- IDA itself retains `sub_`/`unk_` names. This report uses source-facing descriptive names without mutating the database.

## Ranked Ownership Analysis

1. UID0000RS semantic global in UID0000LQ NewHistoryDialogPane.cpp: strongest. It satisfies external linkage, one definition, source family, all five refs, and generated order.
2. UID000091 class as semantic lifetime/data cause: strong for class declaration, Singleton inheritance, compiler pages, and vtables, but not a second pointer definition.
3. UID0001PV physical storage: exact backing evidence only; rejected as emitter because it duplicates D2.
4. ScrolledTextControlPane source: runtime consumer only; rejected as owner because it never creates, publishes, clears, or declares the class.
5. MainMenuPane/main UI: host/layer/show dependencies only; rejected as owner because resources, methods, RTTI, and source tree are NewHistory-local.
6. HistoryViewingPane/BackStory/ForcedInform families: adjacent thematic/storage controls only; distinct classes, addresses, resources, and source files.

## Source Placement

- Exact source path: `NexusTK/login/NewHistoryDialogPane.cpp` under UID0000LQ.
- `by-project-structure/proposed-source-tree.md` explicitly lists this file and groups it with login/main-menu dialogs.
- HISTORYN.EPF/HISTORYN.PAL/MADEBY, g_pMainMenuPane, and overlay-layer construction are pre-login/menu evidence.
- ScrolledTextControlPane.cpp owns the made-by control implementation and only consumes the extern pointer.
- No broader MainMenuPane.cpp merge, narrower resource-only source, duplicate header translation unit, or generated data source is justified.

## Range / Split / Padding / Reclassification Analysis

- UID0001PV range is exact and indivisible; retain `Nested:0` because predecessor and successor are same-level four-byte global pages.
- UID0001A3 exact method cluster remains `[0x00500410,0x00500632)` and retains `Nested:0`; its two internal CC spans remain ignored padding, not children.
- UID0001A8 exact range remains eleven bytes; its UID-preserving title/path correction to `NewHistoryDialogPaneSingletonBaseDestructor` is complete.
- UID0001AC exact range remains two eleven-byte thunks and needs no split.
- UID0001AH exact range remains the 69-byte scalar wrapper; its UID-preserving title/path correction to `NewHistoryDialogPaneScalarDeletingDestructor` is complete.
- UID0004VL D9 is exact `[0x0061daf0,0x0061db8c)`, immediately before GenderButtonControlPane data. It is physically contained under UID00025Q, semantically owned by UID000091, and uses `Nested:0` to preserve the current sibling level after earlier exact children.
- Current address-sorted hierarchy remains no-loss: UID00025Q is the mixed parent; D9 is an exact sibling child; UID0002OV remains the successor and retains its existing `Nested:4`; later hierarchy deltas remain untouched.
- UID0004VM D10 is the registered semantic by-vtable page with no by-memory nesting field.

## Negative Evidence Summary

- No raw bytes back the target slot; therefore historical raw `ff` is invalid.
- No second runtime read, guard, getter, allocation, direct delete, or writer exists beyond the exact five refs.
- No constructor xref, pointer table entry, VA/RVA/raw dword, or rel32 route survives.
- No unique authored destructor cleanup remains after removing direct-base and deleting-wrapper mechanics.
- No class-local field write exists beyond inherited/control construction.
- No evidence supports OnKeyInput, OnMouseInput, NarrowKeyCode, Close, raw Event references, or local event constants.
- No evidence supports hand-authored vptr stores, EH funclets, adjustor thunks, delete flags, operator delete calls, RTTI arrays, or vtable arrays.
- No evidence supports static/file-local pointer linkage, class-static storage, a second template-member definition, or physical-page emission.
- No direct historical report exists; old direct-core/destructor conclusions are not authority where current evidence contradicts them.

## IDA Rename / Type / Comment Recommendations

- Evidence-time source-facing data type/name: `NewHistoryDialogPane *g_pNewHistoryDialog` at `0x0069b49c`.
- Evidence-time function names: `NewHistoryDialogPane::NewHistoryDialogPane`, `HandleKeyOrTextEvent`, `HandlePointerOrMouseEvent`, compiler Singleton base destructor, two compiler destructor thunks, and scalar deleting wrapper.
- Rename D6 path/title to `NewHistoryDialogPaneSingletonBaseDestructor` and D8 to `NewHistoryDialogPaneScalarDeletingDestructor` only through validator-aware UID-preserving moves after acceptance.
- D9/D10 names are exact descriptive documentation names, not claimed recovered symbols.
- No IDA rename, type, comment, save, or database mutation is requested or authorized.

## First-Draft C++ Recommendation

Destination D1: `by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D2: `by-global/g_pNewHistoryDialog.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewHistoryDialogPane;

NewHistoryDialogPane *g_pNewHistoryDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D3: `by-class/NewHistoryDialogPane.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class NewHistoryDialogPane;
extern NewHistoryDialogPane *g_pNewHistoryDialog;

class NewHistoryDialogPane : public DialogPane,
                             public Singleton<NewHistoryDialogPane>
{
public:
    NewHistoryDialogPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D5: `by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewHistoryDialogPane::NewHistoryDialogPane()
    : DialogPane(L"", -1, true),
      Singleton<NewHistoryDialogPane>()
{
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 1024, 768);
    AddControl(new EPFImageControlPane(L"HISTORYN.EPF", 0, true, &bounds, L"HISTORYN.PAL"));

    InitRectBounds(&bounds, 614, 156, 950, 556);
    AddControl(new ScrolledTextControlPaneForMadeBy(L"MADEBY", &bounds, 30));

    SetBackgroundResource(L"HISTORYN.EPF", 0);
    SetMode(1);

    InitRectBounds(&bounds, 0, 0, 1024, 768);
    OnCreate(&bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(0, g_pMainMenuPane);
}

bool NewHistoryDialogPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const unsigned char key =
            g_pEventMan->TranslateEventKey(event->m_payload.m_key.m_key,
                                           event->m_payload.m_key.m_modifiers);
        if (key == '\r' || key == '\x1b' || key == ' ')
        {
            CloseDialog();
        }
    }

    return true;
}

bool NewHistoryDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp ||
        event->m_type == kEventRightButtonUp)
    {
        CloseDialog();
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D6 after UID-preserving rename: `by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D7: `by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D8 after UID-preserving rename: `by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D9 new physical page: `by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D10 new semantic page: `by-type/by-vtable/NewHistoryDialogPaneVtables.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination D11: `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- These ten blocks are the only first-draft/example C++ in this report.
- D1 and D6-D11 are intentionally blank because exact source causes are D2/D3/D5; no proof comment, marker, pseudo-body, or raw table belongs inside their managed payloads.
- D4 and D12-D15 are prose-only route/support destinations and receive no reconstruction block.
- No third-party import directive applies.

## Final Recommendation

- C1PV-001 through C1PV-080 and D1-D15 are applied or verified without compression; no implementation item remains.
- D9 and D10 were serially registered as UID0004VL and UID0004VM before dependent cross-link validation; no provisional token remains.
- Preserve exact binary facts separately from inferred spellings and retained-source liveness. Do not reintroduce explicit Singleton publication/clear or compiler ABI source.
- Verify-only resource, scroller, main-menu, Event, DialogPane, EPFImageControlPane, and adjacent-global facts were reread and preserved without score/formal changes.

## Recommended Target Doc Changes

- Applied D1 UID0001PV: `92/94`, canonical owner UID0000RS, false, blank emitter/position/formal, `Nested:0`; stale `ff` and authored-lifecycle wording are historicalized in favor of the exact loader-zero/five-ref/one-definition/compiler split.
- The exact path and UID are retained; no target rename or split occurred.
- The Item Summary identifies physical loader-zero singleton storage, sole runtime scroller read, four compiler Singleton writes, semantic UID0000RS owner, and blank physical emission.

## Recommended Support Doc Changes

- Applied D2 UID0000RS: `85/90 -> 92/94`, owner/emitter UID0000LQ, position `0`, exact definition, and full type/linkage/lifetime/one-definition evidence.
- Applied D3 UID000091: `85/86 -> 92/94`, owner/emitter UID0000LQ, position `10`, complete fieldless DialogPane/Singleton class, extern, implicit destructor, and exact vtable/layout/compiler evidence.
- Applied D4 UID0000LQ: `87/87 -> 92/93`, preserving by-file no-formal policy and adding the complete definition/class/method/compiler/data/resource/consumer union and retained-source route.
- Applied D5 UID0001A3: `87/91 -> 92/94`, owner/emitter UID0000LQ, position `20`, Nested 0, exact source bodies, ranges/hashes/padding, and negative route evidence.
- Applied D6 UID0001A8: validator-aware UID-preserving rename to `...NewHistoryDialogPaneSingletonBaseDestructor.md`; `92/96`, owner UID000091, false, blank emitter/position/formal, Nested 0.
- Applied D7 UID0001AC: `92/96`, owner UID000091, false, blank emitter/position/formal, Nested 0, with exact two-thunk bytes/adjustments/vtable refs preserved.
- Applied D8 UID0001AH: validator-aware UID-preserving rename to `...NewHistoryDialogPaneScalarDeletingDestructor.md`; `92/96`, owner UID000091, false, blank emitter/position/formal, Nested 0, exhaustive wrapper proof, and no explicit destructor source.
- Applied D9 UID0004VL: registered first at `92/96`, owner UID000091, false, blank emitter/position/formal, Nested 0, with exact hash, tables, RTTI, slots, boundaries, stores, and no-code proof.
- Applied D10 UID0004VM: registered second at `92/96`, owner UID000091, false, blank emitter/position/formal, with all three views and eight-descriptor hierarchy.
- Applied D11 UID00025Q: preserved `86/92`, owner NONE, false, blank formal, Nested 0, and all unrelated data while adding the exact D9 child/range/boundaries.
- Applied D12 `by-memory/-ignored.md`: preserved all unrelated rows, added both full padding hashes, and updated only the D6/D8 compiler-base/wrapper facts and links.
- Verified D13 UID00019X/scroller class/file/method unchanged: `92/94` source, one non-null-assumed close route, and ownership remain exact.
- Verified D14 MainUiLayerSlots, g_pMainMenuPane, MainMenuPane, DialogPane, Event, EventMan, and EPFImageControlPane unchanged at current scores/formals/dependencies.
- Verified D15 UID0001RF and adjacent singleton pages unchanged, including resource score/payload matrix and neighboring metadata.

## Score And Metadata Recommendation

- D1 `86/90 -> 92/94`: bytes, loader state, all refs, ownership, and no-code disposition are closed.
- D2 `85/90 -> 92/94`: exact type, external linkage, initializer, one definition, owner, and position are closed.
- D3 `85/86 -> 92/94`: direct bases, size, EBO, no fields, virtuals, implicit destructor, and complete declaration are closed.
- D4 `87/87 -> 92/93`: source family and full union are closed; missing original symbols/launcher cap confidence.
- D5 `87/91 -> 92/94`: exact bodies, API names, resources, bounds, dependencies, and compiler exclusions are closed.
- D6-D8 `84/90`, `84/90`, `88/90` -> `92/96`: exact compiler identities and exhaustive blank-C++ causes are closed.
- D9/D10 new `92/96`: exact table/RTTI/range/source-cause proof; confidence remains below perfect because inherited stripped slot spellings are not all original symbols.
- D11 remains `86/92`; it is a mixed index and receives no ownership or score inflation.
- D13-D15 remain current scores because this callback adds only target-specific cross-reference closure.
- No score reaches 100 because original source symbols and constructor launch route do not survive.

## Open Questions With Attempted Resolution

- Why is the constructor unreferenced? Exhausted IDA xrefs, VA/RVA/raw pointers, rel32 routes, startup/factory/menu paths, vtables, resources, and prior reports. Resolution: retained linked source whose historic entry route is absent; this is a confidence cap, not a no-code reason.
- Was the slot initialized to `-1`? Live bytes and PE mapping resolve no; it is loader-zero virtual-tail storage.
- Is publication/clear handwritten? Constructor adjustment, RTTI PMD, unwind helper, and reverse base order resolve no; direct Singleton base causes all four writes.
- Does NewHistoryDialogPane need an explicit destructor? Removing compiler/base work leaves no authored statement. Resolution: implicit virtual destruction through DialogPane; no declaration/body.
- Are handlers old OnKeyInput/OnMouseInput methods? Current EventHandler/DialogPane vtable contracts resolve mutable Event-pointer Handle methods.
- Is `0x0069b36c` the main-menu pointer? No; it is overlay layer context. `0x0067aba4` is g_pMainMenuPane.
- Is EPF bounds by value? No; current complete EPF class declaration requires a pointer.
- Does the vtable need handwritten C++? No; complete class declaration regenerates all tables/RTTI.
- Remaining uncertainty: original local variable spelling and zero-token style only. Neither affects ABI, behavior, ownership, or destination readiness.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Final callback read-only manual snapshots after validator-managed rename-link propagation:
  - `by-memory/-coverage-report.md`: SHA256 `76E56F8433A04EF8DCC8C1ACC0129487F6DE0A05CD61904076817CCBB9D6DB25`, 1,923,748 bytes / 4,488 lines.
  - `by-global/-coverage-report.md`: SHA256 `D603D2725BD43C4B57AB7C2D55592B62032A3DA5D35192F881DF2797306DE65E`, 95,594 bytes / 214 lines.
  - `by-class/-coverage-report.md`: SHA256 `15924F999C3B7DC2FBAA7AA8E9945D5755C6713B8F577023A3134627F72EC958`, 249,734 bytes / 623 lines.
  - `by-file/-coverage-report.md`: SHA256 `F22305818DBE6AAFBF2D1AB7F9BE3697129CCAE8320AB8CC4FF0ACDFEC615420`, 146,676 bytes / 316 lines.
  - `by-type/by-vtable/-coverage-report.md`: SHA256 `0C50580D25877BBE3173001EC012976B93B25F29732BD142E31344737F9D02EE`, 65,593 bytes / 143 lines.
  - `by-resource/-coverage-report.md`: SHA256 `EF28BB82AE827E585B5F85E3F45D590A665C54095C2767CF970820493FA1DD72`, 16,981 bytes / 50 lines.
- These are mutable supervisor-owned snapshots. B004 did not manually edit them. The current external union adds unrelated StaffsDialogPane coverage after B004 validation; the earlier by-memory link-only rename propagation and all older hashes are historical. Every NewHistory score/detail row remains stale/unapplied and requires the literal handoff below.

Replace the current UID0001PV by-memory row in place with:

```text
    - [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) 0x0069b49c-0x0069b4a0 | loader-zero physical singleton slot | g_pNewHistoryDialog physical storage : not_reconstructable : 92% : very-strong : Exact four-byte NewHistoryDialog singleton slot with current PE loader-zeroed pointer storage and SHA256 DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119; five live IDA xrefs preserve the constructor publish/fallback clear, clear-helper/destructor clears, and made-by scrolled-text close read, with no direct static callers for the reviewed paths. The five refs resolve into four compiler-lowered direct-Singleton publication/clear effects and one ScrolledTextControlPaneForMadeBy runtime close read; the historical `0xffffffff` initializer claim is rejected by current raw/virtual mapping, there is no raw initializer, adjacent singleton boundaries are exact, semantic parent/definition is [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), and the physical emitter/formal C++ remains blank.
```

Replace the current UID0001A3 by-memory row in place with:

```text
    - [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) 0x00500410-0x00500632 | class method cluster | NewHistoryDialogPaneCore : reconstructable : 92% : very-strong : Exact history/credits dialog constructor and input-close handlers with HISTORYN resources, MADEBY scrolled text, singleton, main UI context, g_pMainMenuPane show parent, source-ready formal body, padding, and retained indirect-reachability caveat. The completed source union identifies `NewHistoryDialogPane::NewHistoryDialogPane()`, `HandleKeyOrTextEvent(Event *)`, and `HandlePointerOrMouseEvent(Event *)` with DialogPane plus direct Singleton source bases, HISTORYN.EPF/HISTORYN.PAL image and background, exact rectangles and interval 30, mode 1, overlayPaneLayerContext create route, g_pMainMenuPane show route, EventMan key translation, Enter/Escape/Space and left/right-button-up CloseDialog behavior, exact method plus both padding hashes, zero surviving constructor route, and explicit publication/vptr/EH/destructor exclusions.
```

Replace the UID0001A8 row and path in place with:

```text
    - [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md) 0x005023e0-0x005023eb | compiler Singleton base destructor | NewHistoryDialogPaneSingletonBaseDestructor : ignored : 92% : very-strong : Live IDA confirms the exact constructor-unwind helper, singleton-only clear, constructor EH xref, no callees, and no ordinary callers. The completed disposition identifies the exact eleven-byte Singleton<NewHistoryDialogPane> base-destructor instantiation, sole global clear, direct +0x26c RTTI/EBO source cause, hash 1B46511C4232A422C212F7ED4243F8AFDB3EA5A464E6AE8AAC5A176B7C245939, and blank non-emitting formal C++.
```

Replace the UID0001AC row in place with:

```text
    - [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md) 0x005024f8-0x0050250e | compiler destructor adjustor thunks | NewHistoryDialogPaneDestructorThunks : ignored : 92% : very-strong : Live IDA confirms two exact secondary destructor adjustor thunks, vtable refs, deleting-destructor code routes, receiver adjustments, and no ordinary callers. The completed disposition identifies two eleven-byte -0xa0/-0xa4 receiver-adjusting vtable thunks to the NewHistoryDialogPane scalar deleting wrapper [UID:0001AH][NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md), hash DAEF9E9BD05A9D5697905196DEDABB7679B84090DC692D56046256BB9C9D4C1E, primary/secondary/tertiary layout proof, and blank non-emitting formal C++.
```

Replace the UID0001AH row and path in place with:

```text
    - [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md) 0x00502920-0x00502965 | compiler scalar deleting destructor | NewHistoryDialogPaneScalarDeletingDestructor : ignored : 92% : very-strong : Live IDA confirms the exact deleting-destructor extent, singleton clear, base cleanup/delete-flag path, primary vtable ref, thunk code refs, and trailing padding. The completed disposition identifies the exact 69-byte compiler scalar deleting wrapper with implicit direct-Singleton clear, DialogPane teardown, scalar/array delete flags, conditional operator delete, primary plus two adjusted vtable routes, hash 6C80FDD5A65F7F89FEA0139E9349C747DDF4AFA1A4E969B3DF6CA1F8D7B9A58C, no unique authored destructor statement, and blank non-emitting formal C++.
```

Insert the new physical vtable row immediately before current UID0002OV `0x0061db8c` and after all prior address-sorted UID00025Q children, using issued real UID0004VL:

```text
        - [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md) 0x0061daf0-0x0061db8c | compiler vtable/RTTI data | NewHistoryDialogPaneVtableData : not_reconstructable : 92% : very-strong : Exact 156-byte three-view NewHistoryDialogPane vtable cluster owned semantically by [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) and physically nested under [UID:00025Q][MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md), with primary/secondary/tertiary locator bases, 23/11/2 slots, scalar wrapper and -0xa0/-0xa4 adjustors, exact pointer/key overrides, constructor stores, eight-entry DialogPane/Singleton RTTI hierarchy, direct +0x26c EBO, SHA256 BA7C96EB88036F4D54AC50D72A74A0CA697655B45F4B8F1AAA13256C0EBF9D26, exact predecessor boundary and successor [UID:0002OV][GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), and blank non-emitting C++.
```

Leave this exact current UID0002OV successor row unchanged immediately after D9:

```text
        - [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md) 0x0061db8c-0x0061dc30 | vtable-data | GenderButtonControlPaneVtableData : reconstructable : 85% : strong : 2026-06-07 Agent-A002 IDA MCP refresh verified exact `0xa4` range, primary/secondary/tertiary RTTI locators at `0x0061db8c`, `0x0061dbf4`, and `0x0061dc24`, slot spans `25/11/2`, key pane-click slots `0x00500700` and `0x005006d0`, constructor/reset/destructor xrefs, and boundary before `DirectionButtonControlPane`. Left unassigned because candidate parents fail the corrected gate: aggregate `00025Q` is mixed `78/90`, class `00005P` is `80/84`, file `0000NY` is `82/86`, and vtable family `0001YW` is `84/90`.
```

Replace UID00025Q broad row in place with this no-loss union:

```text
    - [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) 0x0061d264-0x0061e5b4 | mixed read-only data index | MainMenuNewUserReadOnlyData : ignored : 86% : very-strong : Exact mixed-owner non-emitting index with current boundaries/resources and exact nested vtable children, including NewUserDialogPane vtable data 0x0061d2ec-0x0061d384 before the LoginDialogPane successor; each exact child carries its own owner and rebuild disposition. Additional exact child facts preserve ScrolledPictureControlPane at 0x0061d88c-0x0061d930, add physically nested StaffsDialogPane vtable data 0x0061d930-0x0061d9cc with semantic owner UID0000DY, and retain HistoryViewingPane as the successor owner beginning at 0x0061d9cc. The NewHistory addition appends exact compiler-only [UID:0004VL][NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md) at 0x0061daf0-0x0061db8c immediately before [UID:0002OV][GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), preserving every pre-existing child, order, owner, and per-child rebuild disposition.
```

Replace UID0000RS by-global row in place with:

```text
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md) : reconstructable : 92% : very-strong : C001 live IDA refresh reconfirmed the current zeroed `0x0069b49c` singleton slot, exact five-reference lifecycle/consumer set, no direct constructor-start xrefs, constructor-context cleanup helper xref, owner/emitter route through [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), and saved IDA names for the constructor, clear helper, and scalar deleting destructor. The historical row left final C++ blocked by indirect menu/constructor reachability, final declaration spelling, and source-quality helper/field names; current target research resolves those source-shape blockers while retaining the no-route caveat and identifies the sole externally linked `NewHistoryDialogPane *g_pNewHistoryDialog = 0;` definition at source position 0 in `NexusTK/login/NewHistoryDialogPane.cpp`, a local forward declaration, exact false loader-zero physical child [UID:0001PV][g_pNewHistoryDialog physical storage](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md), direct `Singleton<NewHistoryDialogPane>` +0x26c RTTI/EBO publication/reverse-clear cause, one class-header extern, no duplicate physical/template/static emitter, and resolved type/linkage/source placement.
```

Replace UID000091 by-class row in place with:

```text
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) : reconstructable : 92% : very-strong : Full-screen main-menu history/credits dialog with live IDA-confirmed constructor/input/destructor support, singleton/vtable/resource operands, `NexusTK/login/` parent attachment, and retained direct-constructor reachability caveat. The no-loss addition supplies a complete fieldless `DialogPane` plus direct `Singleton<NewHistoryDialogPane>` class declaration at exact size 0x26c with constructor, `HandlePointerOrMouseEvent(Event *)`, `HandleKeyOrTextEvent(Event *)`, implicit virtual destruction, sole `g_pNewHistoryDialog` extern contract, exact +0/+0xa0/+0xa4 vtable views, +0x26c EBO/eight-entry RTTI hierarchy, compiler Singleton/unwind/thunk/scalar/vtable exclusions, HISTORYN/MADEBY ownership, and login source route.
```

Replace UID0000LQ by-file row in place with:

```text
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) : reconstructable : 92% : very-strong : `NexusTK/login/NewHistoryDialogPane.cpp` file owner with live IDA-confirmed constructor/input/destructor support, singleton/vtable/resource operands, internal padding split, ignored thunk/EH handling, and retained direct-constructor reachability caveat. The no-loss addition supplies the complete file union with sole zero `g_pNewHistoryDialog` definition, complete fieldless DialogPane/Singleton-derived class and extern contract, source-ready constructor plus key/pointer Event overrides, HISTORYN.EPF/HISTORYN.PAL/MADEBY resources, overlayPaneLayerContext and g_pMainMenuPane dependencies, exact padding, scroller close consumer, and non-emitting Singleton/EH/thunk/scalar/vtable/RTTI physical artifacts without explicit publish/clear/destructor or duplicate source.
```

Insert this row alphabetically in `by-type/by-vtable/-coverage-report.md` using issued real UID0004VM:

```text
- [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md) : ignored : 92% : very-strong : Non-emitting compiler-generated NewHistoryDialogPane primary/secondary/tertiary vtable and RTTI inventory for exact 0x0061daf0-0x0061db8c backing data, with 23/11/2 slots, scalar/adjustor/input-handler cells, constructor stores, eight-entry DialogPane/Singleton hierarchy, direct +0x26c EBO, exact boundaries/hash, and class-declaration regeneration without handwritten tables.
```

D10 inserts after current [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md) at line 95 and before current [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) at line 96; both anchor rows remain unchanged byte-for-byte.

The current UID0001RF resource row is exact and remains unchanged:

```text
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) : reconstructable : 90% : very strong : Main-menu history resources with current IDA literal bytes/xrefs, owner function bounds, viewer versus newer-dialog resource matrix, `HISTORY.*`/`STORY.*`/`HISTORYN.*` branch split, `MADEBY` text-resource ownership, `NPAL4.PAL` viewer-palette caveat, rebuild packaging boundary, current `bint2.dat` payloads for eight-frame `HISTORY.EPF`, five-frame `STORY.EPF`, one-frame `HISTORYN.EPF`, `HISTORYN.PAL`, and `NPAL4.PAL`, `baram.dat` `MADEBY` payload evidence, and executable-literal-only blockers for missing legacy `HISTORY.EPD`/`STORY.EPD` documented.
```

- Exact anchor/order at the final read-only callback checkpoint: UID0001A3 line 2150, UID0001A8 line 2218, UID0001AC line 2224, UID0001AH line 2231, UID00025Q line 4011, and UID0001PV line 4401 are unique replacement rows. Current UID0004VJ is preserved at line 4013; D9 inserts immediately after it and before unique UID0002OV at line 4014, leaving both complete rows unchanged. UID0000RS is unique at by-global line 121, UID000091 at by-class line 348, and UID0000LQ at by-file line 179. D10 inserts exactly after UID0001Y9 at by-vtable line 95 and before UID0001YA at line 96; unrelated UID0004VK at line 123 remains unchanged.
- No-loss recheck result: every proposed replacement above begins with or expressly retains the complete current linked row facts before adding the NewHistory delta. UID0001PV retains no-direct-static-caller evidence; UID0001A8 retains no callees and no ordinary callers; UID0001AC retains deleting-wrapper code routes and no ordinary callers; UID0001AH retains trailing padding; UID00025Q retains NewUserDialogPane before LoginDialogPane, ScrolledPicture bounds, the complete UID0004VJ Staffs child and UID0000DY ownership, HistoryViewing successor, and per-child ownership/rebuild disposition; UID0000RS retains C001, linked UID0000LQ route, saved names, no constructor-start xrefs, and cleanup-helper provenance; UID000091 and UID0000LQ retain the direct-constructor reachability caveat. The resource row is unchanged, D9/D10 are additions rather than replacements, and no other manual handoff action removes an existing fact or Markdown UID link.
- Current coverage contains none of the D9/D10 rows and retains the pre-callback NewHistory scores/detail described above. The serial callback registered real UIDs `0004VL` and `0004VM`; the literal supervisor-owned handoff contains no provisional UID and requires no supervisor-authored syntax or inference.
- Tracker text is validator-owned and receives no manual edit.

## Follow-Up Actions

- All research, source decisions, scores, destinations, formals, no-code proofs, manual handoff text, and callback checks required for UID0001PV are complete in this artifact.
- B004 implementation and scoped/waited validation are complete. D1-D15 and C1PV-001-C1PV-080 have no remaining implementation item.
- Manual coverage remains external supervisor-owned; B004 supplies literal replacement/insertion text but does not apply it.
- Report validation, execution, count, path, move, and archive state are external supervisor/validator-owned and are neither asserted nor performed by B004.

## Confidence

- Recommendation confidence: very strong.
- Target/global/class/core/compiler/data confidence: very strong.
- File/source-liveness confidence: high because no surviving constructor entry route or original symbols exist.
- Remaining uncertainty is lexical and historical-launcher-only; it does not change exact behavior, ABI, source placement, ownership, formal completeness, or generated assertions.

## Validator Results

- Mandatory report-research MCP health and bounded evidence calls succeeded on database `9b0396a3`; no IDA mutation occurred during implementation.
- Historical external commands 15993/15994/15999/16000 remain evidence-time report-only checkpoints and are not current callback authority.

| Command | Timestamp | Scoped destination/result | Warnings and side effects |
| --- | --- | --- | --- |
| `000000016086` | `2026-07-21T17:09:56-04:00` | D9 create/register UID0004VL; exit 0, ok 1 | UID assigned; generated refresh deferred. |
| `000000016090` | `2026-07-21T17:11:42-04:00` | D10 create/register UID0004VM; exit 0, ok 1 | UID assigned; generated refresh deferred. |
| `000000016092` | `2026-07-21T17:13:09-04:00` | D6 final renamed path; exit 0, ok 1 | UID0001A8 path retained uniquely; 236 pre-existing missing-reference warnings; validator-managed reverse links updated, including manual by-memory coverage link text. |
| `000000016093` | `2026-07-21T17:14:21-04:00` | D8 final renamed path; exit 0, ok 1 | UID0001AH path retained uniquely; 236 pre-existing missing-reference warnings; validator-managed reverse links updated, including manual by-memory coverage link text. |
| `000000016099` | `2026-07-21T17:15:32-04:00` | D7 destructor thunks; exit 0, ok 1 | Metadata/formal/reference state applied; generated refresh deferred. |
| `000000016101` | `2026-07-21T17:17:19-04:00` | D1 target; exit 0, ok 1 | `92/94`, false/non-emitting metadata applied; generated refresh deferred. |
| `000000016102` | `2026-07-21T17:18:11-04:00` | D2 semantic global; exit 0, ok 1 | Position 0/global formal registered; generated refresh deferred. |
| `000000016103` | `2026-07-21T17:19:27-04:00` | D3 class; exit 0, ok 1 | Position 10/class formal registered; generated refresh deferred. |
| `000000016105` | `2026-07-21T17:24:31-04:00` | D4 file; exit 0, ok 1 | Completion/confidence and UID links updated; generated refresh deferred. |
| `000000016106` | `2026-07-21T17:26:08-04:00` | D5 core; exit 0, ok 1 | Position 20/formal registered; validator exposed a wrong MainUiLayerSlots UID in new prose. |
| `000000016107` | `2026-07-21T17:26:56-04:00` | D5 bounded UID correction; exit 0, ok 1 | Correct canonical UID0000T6 reference indexed; generated refresh deferred. |
| `000000016108` | `2026-07-21T17:27:45-04:00` | D11 aggregate; exit 0, ok 1 | One pre-existing missing UID00036V warning; D9/D10/class links indexed; generated refresh deferred. |
| `000000016109` | `2026-07-21T17:29:07-04:00` | D12 ignored index; exit 0, ok 1 | 232 pre-existing missing-reference warnings; semantic vtable link indexed; generated refresh deferred. |
| `000000016110` | `2026-07-21T17:29:32-04:00` | D9 final cross-link; exit 0, ok 1 | UID0004VM link indexed; generated refresh deferred. |
| `000000016111` | `2026-07-21T17:30:34-04:00` | Final D1 `--wait-generated`; exit 0, ok 1 | Full registry/generated refresh completed; pre-existing 76 missing-children-marker and 120 no-code-emitter notices plus 13 fallback inserts were reported. |

- Command 16111 generated `NewHistoryDialogPane.cpp` SHA256 `EC6F1F15511B2E582E4724C0D76478D32F8BEA5676DF4BA4FA753B44BA5C6E45`, 2,328 bytes / 75 lines, and `ScrolledTextControlPane.cpp` SHA256 `7F67B24A649984E5E8E157904E7547A544B84BC432C5828773CCC19B885343E2`, 4,822 bytes / 143 lines.
- Positive counts: one `NewHistoryDialogPane *g_pNewHistoryDialog = 0;`, one complete class, one constructor, one `HandleKeyOrTextEvent`, one `HandlePointerOrMouseEvent`, and one scroller `g_pNewHistoryDialog->CloseDialog()` route.
- Negative counts: zero explicit NewHistory destructor; zero UID0001PV/UID0001A8/UID0001AC/UID0001AH/UID0004VL/UID0004VM/UID00025Q marker; zero target Empty Emitter Marker; zero explicit publication/clear, vptr, EH, thunk, flags, operator delete, RTTI, vtable, stale handler/API, raw layer, or by-value EPF-bounds source; zero duplicate scroller global definition.
- All ten managed blocks compare byte-for-byte equal between this report and D1/D2/D3/D5/D6/D7/D8/D9/D10/D11.

## Changed Files

- Renamed once, UID-preserving: `by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md` -> `by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md`; old path absent, unique UID0001A8, current SHA256 `7D414EC65D8854255B39F48E16B53C6371E86ABBA62BF8DFD4FE1569181EE2BB`, 5,680 bytes / 69 lines.
- Renamed once, UID-preserving: `by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md` -> `by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md`; old path absent, unique UID0001AH, current SHA256 `EEF44732E740EA365BA8F6EC35D5359AFD96A66F320CD998509CAB5187D87F95`, 8,499 bytes / 78 lines.
- Created: `by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md`, UID0004VL, SHA256 `47B68A28910A37E86DD157E8D87390FB1DC2ABC0EC9A115EED4283CF15E06C5D`, 10,007 bytes / 102 lines.
- Created: `by-type/by-vtable/NewHistoryDialogPaneVtables.md`, UID0004VM, SHA256 `7EABAE76C1E6E77246F4649D80B0E3B239EEF4DBCA5F8A6D75B738FCC00D021A`, 9,107 bytes / 103 lines.
- Modified D1: `by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md`, SHA256 `40304F9A9611D705CD950CE3629CC4B443F4CC73438CBF7E853739A67921EE9B`, 11,935 bytes / 101 lines.
- Modified D2: `by-global/g_pNewHistoryDialog.md`, SHA256 `7A45F042CAC6DE30DB30B7BD3D47D957DB3F43DA1BDC87647118B6A02CC1C185`, 12,867 bytes / 105 lines.
- Modified D3: `by-class/NewHistoryDialogPane.md`, SHA256 `E3630447DD0CD09835427E01A6A50D20DE68D9442583FBC8F4C5C01E4B563ED5`, 14,640 bytes / 126 lines.
- Modified D4: `by-file/NewHistoryDialogPane.md`, SHA256 `209C84F7ADEA6439CD8C9429AB527415CF1489E78AAC94FECCC7573A2FC4754E`, 15,920 bytes / 113 lines.
- Modified D5: `by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md`, SHA256 `220F50347F495610B118E5DA3FE1D0DFE4CF55A3C20E4623729B5D227699CCC4`, 13,595 bytes / 153 lines.
- Modified D7: `by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md`, SHA256 `758C5DC5FEAA35D943219011C3A2E078B22D4ABDFDC13C714562E8E923537C6D`, 6,349 bytes / 76 lines.
- Modified D11: `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`, SHA256 `7FE064065DB5761AB686F5A16D55D29659F44D22CBA6FB00047968DDC9D5288E`, 34,277 bytes / 189 lines.
- Modified D12: `by-memory/-ignored.md`, SHA256 `ECC80E7B9DCD2B46B7DC811BC1FE9066F4DB6C7B715AF46528DB8F347EADE122`, 1,101,991 bytes / 5,345 lines.
- Verify-only current hashes: UID00019X `982D68700B9325056117F8D84BF2796EB4E579D33E15737CD4E022E777BACCF8`; scroller class `0F697897B1BE3E314798A2DAB587D9E9889DF9F837F19A77F8227815A61DE4B4`; scroller file `4E202C5698F43C3EE55E02059BE72F71329610593B224954CCAAF7C98B7BF019`; MainUiLayerSlots `C85F385AE5DA6CC2C25504AB7A783FA989A07333F21785F11AF8B3BFA84A1635`; g_pMainMenuPane `0AF1AD4EE034672CB71A66EA1375893D942336B735D88C21D84AF6DCCF9EAC5E`; MainMenuPane `520E7A713CF5001E4317C3BE8FCFF09C13D4EA160CBE5537395F6F92C20DB7EA`; DialogPane `7101A93A4EF53CFA1F11529AEF111AA94B13EBC76222ADE546D7B59D6D521DBE`; Event `990F3E969A8A697868C29DE05FD57140502D78B1373C1F3BA0D9056BD2DFB97A`; EventMan `240D2FC1D8124990E9AE1050B774DE099CBBE8A4F3AF5F9FC42E8483A8C72171`; EPFImageControlPane `430C9AFEC07F3565442FB77C9A8A7B5A318F1C73B52D0FB94E41DA03679D2B13`; UID0001RF resource `AE792D8F106C08166A6D066C3ABD2BFE3F8686C194634F7D863C62F069D14421`; UID00029F `3458C073BE9F4316375BD4A951F3A7076B527EDF85A616B6BBE7C07A230F7D9D`; UID0001PW `A3B9AD59878F87E02E15420AC8C1E4757766F4BC3F92211C0D842DAD2C95D3F1`.
- Validator-managed side effects: generated/tracker/stats/reference indexes refreshed; D6/D8 reverse links propagated, including link-only changes in supervisor-owned by-memory coverage. B004 manually edited no coverage, generated, tracker, audit, supervisor, validator-state, IDA, lifecycle, queue, lock, or archive file.
- Report execution/lifecycle: not run, probed, moved, or archived by B004. External report validation/execution/count/path/archive state remains supervisor/validator-owned.
- Leases: one ordinary file at a time only during its immediate edit/validator window; every lease was released immediately. Zero B004 leases remain.

## Implementation Tracking Checklist

Initial report-only pass, callback-verified:
- [x] Supervisor exact-artifact Gate 1 validation completed.
- [x] D1 target metadata, bytes, PE mapping, refs, history, one-definition disposition, and blank formal applied.
- [x] D2 semantic global definition, forward declaration, type, linkage, initializer, position, and full lifecycle evidence applied.
- [x] D3 complete class, direct bases, size/EBO, extern, virtuals, implicit destructor, and compiler child inventory applied.
- [x] D4 file score/source order/full source-compiler-resource-consumer union applied.
- [x] D5 exact constructor/key/pointer formal, ranges, hashes, APIs, resources, bounds, and compiler exclusions applied.
- [x] D6 validator-aware UID0001A8 rename and Singleton base-destructor disposition applied.
- [x] D7 destructor-thunk class-owned compiler disposition applied.
- [x] D8 validator-aware UID0001AH rename and scalar-wrapper disposition applied.
- [x] D9 physical vtable page created and validator-registered first with a real UID.
- [x] D10 semantic vtable page created and validator-registered second with a real UID.
- [x] Real D9 UID `0004VL` replaced the provisional token everywhere after registration.
- [x] Real D10 UID `0004VM` replaced the provisional token everywhere after registration.
- [x] D11 broad read-only aggregate exact NewHistory child added without unrelated loss.
- [x] D12 ignored padding hashes and renamed compiler links updated without unrelated loss.
- [x] D13 scroller consumer reread and preserved without score/formal changes.
- [x] D14 main-menu/UI/Event/DialogPane/EPF dependencies reread and preserved.
- [x] D15 resource and adjacent singleton pages reread and preserved.
- [x] C1PV-001 through C1PV-080 accepted or rejected claim by claim.
- [x] Every accepted target/support fact incorporated at report-level detail.
- [x] Exact score/owner/emitter/reconstructable/position/Nested changes applied.
- [x] All ten exact managed formal blocks applied byte-for-byte.
- [x] No first-draft/example C++ left outside destination managed headers.
- [x] Historical `ff`, explicit publish/clear/destructor, stale handlers, raw layer, by-value bounds, and stale Close preserved only as superseded history.
- [x] Complete positive, negative, rejected-alternative, and constructor-liveness evidence preserved.
- [x] Exact function/range/padding/vtable/RTTI hashes preserved.
- [x] No unauthorized source child, helper body, explicit destructor, raw table, layout field, or target split created.
- [x] One short lease held only for the ordinary file actively edited.
- [x] Each changed ordinary page reread after lease and concurrent content rebased.
- [x] One scoped validator run for every changed ordinary page.
- [x] Every ordinary lease released immediately after its scoped validator.
- [x] Final target validation run with `--wait-generated` after all ordinary leases clear.
- [x] Generated NewHistoryDialogPane.cpp contains one g_pNewHistoryDialog definition.
- [x] Generated NewHistoryDialogPane.cpp contains one complete NewHistoryDialogPane class declaration.
- [x] Generated NewHistoryDialogPane.cpp contains one constructor definition.
- [x] Generated NewHistoryDialogPane.cpp contains one HandleKeyOrTextEvent definition.
- [x] Generated NewHistoryDialogPane.cpp contains one HandlePointerOrMouseEvent definition.
- [x] Generated output contains zero explicit NewHistoryDialogPane destructor definition.
- [x] Generated output contains zero explicit singleton publish/clear, vptr, EH, thunk, delete-flag, operator-delete, RTTI, or vtable source.
- [x] Generated output contains zero OnKeyInput, OnMouseInput, NarrowKeyCode, Close(), local event constants, raw dword_69B36C, or by-value EPF bounds.
- [x] Generated output contains zero UID0001PV/UID0001A8/UID0001AC/UID0001AH/D9/D10/D11 marker or Empty Emitter Marker.
- [x] Generated ScrolledTextControlPane.cpp retains exactly one made-by timer close through g_pNewHistoryDialog with no duplicate definition.
- [x] Exact generated command/header/hash/definition/marker assertions recorded.
- [x] Exact manual supervisor-owned coverage text retained as literal same-or-greater supervisor handoff preserving every current fact and Markdown UID link, updated with real issued UIDs, and confirmed unapplied by B004.
- [x] B004 did not edit manual coverage, generated, tracker, audit, supervisor, validator state, IDA, lifecycle, queue, lock, or archive files.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] Every accepted D1-D15 detail incorporated without compression or unrelated loss.
- [x] Every C1PV ledger row converted from `proposed` to a legal terminal callback state.
- [x] Destination-specific proof recorded for all 80 claims.
- [x] Both new pages registered serially and all links use real issued UIDs.
- [x] Both UID-preserving renames completed once with old paths absent and UIDs unique.
- [x] Every destination formal equals this report exactly.
- [x] All changed ordinary hashes, bytes, lines, commands, timestamps, exits, ok/warnings, and side effects recorded.
- [x] Final generated readback completed and all positive/negative assertions recorded.
- [x] Current manual coverage reread and literal handoff rebased without B004 editing coverage.
- [x] Current-state wording reconciled to durable post-callback truth without lifecycle assertions.
- [x] Remaining unapplied accepted claim, if any, listed with exact blocker.
- [x] Zero B004 leases remain.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000016138","destination_path":"executed-b-agent-research/B004/0001PV-g_pNewHistoryDialog-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001PV-g_pNewHistoryDialog-source-quality.md","timestamp":"2026-07-21T17:55:31-04:00","uid":"0001PV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
