# UID0000JK FpsPane Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000JK **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Project context: this is a local old-game preservation effort for an unsupported NexusTK client, intended to keep the game runnable through archival compatibility research and faithful source reconstruction.

## Finalized Report / Current Recommendation

- Keep [UID:0000JK] `by-file/FpsPane.md` as the canonical standalone `NexusTK/ui/diagnostics/FpsPane.cpp` compilation unit. The accepted C001-C025 callback now supplies the required generated sibling `FpsPane.h` through formal H-channel content.
- Preserve every source-bearing child routed through UID0000JK. The accepted callback replaced the incorrect constructor, `UpdateFpsLogSession`, and timer callback source shape; generated command `27796` confirms inherited Pane/TimerHandler APIs, `OnTimer`, and the complete class declaration.
- Declare `FpsPane` as `Pane, Singleton<FpsPane>`, define the exact `0x170` layout, publish/clear the singleton through the accepted explicit `Singleton<FpsPane>` specialization pattern, and name `0x004b68b0` as the inherited `TimerHandler::OnTimer` override.
- Keep raw retained helpers `StartLogSession` and `WriteLogSummary` as private source methods despite their absent direct xrefs: their complete bodies, field use, literals, placement, and active inline twins prove source meaning. Preserve the no-route result as liveness evidence, not as a reason to emit raw labels or omit source.
- Keep RTTI, vtables, adjustor thunks, scalar deleting destructor machinery, physical global storage, and literal-data pages compiler-covered or definition-covered rather than hand-emitting binary arrays/wrappers.
- The file and affected support scores are now in the accepted low/mid-90s range. Exact behavior and source structure are substantially resolved, while original lexemes/linkage and the historical compiler's exact inlining decisions remain unrecoverable with certainty.
- Confidence: very strong for ownership, ranges, inheritance, layout, virtual identity, API calls, source order, and corrected behavior; strong for inferred human source spellings.

## Supporting Research

- Current read-only IDA MCP session: `supervisor_uid0004yk_final_20260824_1721`, canonical IDB `E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64`.
- Public `runtime_attestation` at `2026-08-24T17:36:20Z` returned schema `1`, `ok:true`, no errors, listener `127.0.0.1:13337`, PID `3612`, generation `pid:3612;created:134318146704590877`, nonce `7add3955f244134fd8f6863387553ced`, source root `C:\Users\admin\.idapro\idalib-mcp-venv\Lib\site-packages\ida_pro_mcp`, implementation manifest SHA256 `D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE`, active worker endpoint `127.0.0.1:53514`, PID `13592`, parent redirector PID `12952`, generation `pid:13592;created:134320657005157164`, nonce `9b99a5ce4836077cefe0eac6d68084a4`, same source root, worker manifest SHA256 `2E883F9025B9811708B812077B7194021F72F741508E32BEEA1A491A59B23C00`, and exact session/path binding. Listener and worker manifests were sealed independently, not compared for equality. Runtime attestation does not supply disk bytes or SHA256.
- Physical canonical IDB receipt: `143211656` bytes, last-write UTC `2026-08-24T17:21:13Z`, SHA256 `AED88CDF9B4A98E0D2F5BDD71670C74E10F522F3B621DD9AA92ADFBBF6171187`.
- Callback generated receipt: `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`, `7598` bytes, last-write UTC `2026-08-24T19:09:41.4892185Z`, SHA256 `1561B88559204B4080A45DF77A54436C3673068CF411B18CEA82FDEB72656DCC`, validator command id `000000027796`, refreshed `2026-08-24T15:09:23-04:00`.
- Callback generated receipt: `auto-generated/NexusTK/ui/diagnostics/FpsPane.h`, `1412` bytes, last-write UTC `2026-08-24T19:09:41.5432160Z`, SHA256 `0C62504B2B5CB6FE92FF261DFA407515501D5F31062150F76DAB99F38165145A`, validator command id `000000027796`, refreshed `2026-08-24T15:09:23-04:00`.
- Callback dependency receipt: `auto-generated/NexusTK/ui/MainUiGraph.h`, `907` bytes, last-write UTC `2026-08-24T19:09:45.1606140Z`, SHA256 `7925E757BDA57FE1D4DA5466693AC424E84C641F954D815BAEC74CE02E16A971`, validator command id `000000027796`; it contains `class Layer;` and `extern Layer *g_pIMEPaneLayer;`.
- Fresh read-only tracker receipt at `2026-08-24T19:22:59.5456148Z`: `auto-generated/-ag-research-tracker.md`, `1924798` bytes, SHA256 `A103EBFA55CD44132CA2988D2D487427C0FFA46E7D0A056B1E5EE143B2F5F45F`, validator command id `000000027800`, row `19/19/0/100.0%`. Command `27800` was an independent validator refresh, not a B009 edit.
- Current by-file, by-class, by-memory, by-global, by-struct, by-vtable, generated-source, and manual coverage evidence was reread. Older FpsPane report facts were used only where current binary/docs independently reconfirmed them.
- Stale Wave2/Wave3 labels and old `class_ParcelPane.cpp` placement were treated only as historical assumptions. They are not current authority.
- Report execution/archive lifecycle is supervisor-owned and authoritative only from the report's current path and validator-owned status/history metadata. This callback artifact contains exactly one terminal readiness marker, `READY_FOR_SUPERVISOR_EXECUTE`; that marker is not execution or archive proof.

## Target

- Primary target: [UID:0000JK] `by-file/FpsPane.md`.
- Additional target UIDs: none. Support UIDs are affected implementation destinations, not additional report coverage declarations.
- Current source-tracker row at command `27800`: `| [UID:0000JK][FpsPane](by-file/FpsPane.md) | 19 | 19 | 0 | 100.0% | auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp | by-file/FpsPane.md |`.
- Current metadata: completion `94`, confidence `96`, canonical owner `FILE`, proposed path `NexusTK/ui/diagnostics/`. A by-file root has no `RECONSTRUCTABLE`, `EMITTER_UIDS`, or formal CPP/H fields; its 19 routed children carry those states.
- Parent/source root: `FILE`; no higher by-* owner replaces this standalone compilation unit. Direct class child [UID:00005F] owns class source and emits through UID0000JK.
- Lifecycle-neutral state: report execution/archive state is supervisor-owned and authoritative only from this report's current path plus validator-owned status/history metadata. The sole terminal marker records callback readiness only and does not claim execution or archive state.
- Inferred compilation-unit boundary: exact code island `0x004b6410-0x004b6caf`, owned globals at `0x0066da90`, `0x0069b334`, and `0x0069b338`, compiler RTTI/vtables, and adjacent FpsPane diagnostics literals. The coherent method/global/literal cluster and current source route define one `FpsPane.cpp` plus required declarations in `FpsPane.h`.

## Current Target State

- The by-file page now records completion/confidence `94/96`, the diagnostic-overlay source folder, all source-bearing children, three semantic globals, layout/vtable support, generated-data exclusions, corrected APIs, and complete file inventory.
- Exact routed-state totals are now 19 generated children = 19 covered and 0 empty emitters. The complete inventory below additionally records non-emitting split/index UID00015D, false/non-emitting adjustor UID00015K, compiler RTTI records, six alignment gaps, 34 vtable-region dwords, 15 literal items, 3 semantic globals, 3 physical-global children, and 22 direct dependency pages.
- Generated `FpsPane.cpp` now contains seven authored bodies (`FpsPane`, destructor, `UpdateFpsLogSession`, `OnPaint`, `OnTimer`, `StartLogSession`, `WriteLogSummary`), two Singleton specializations, three semantic definitions, and all required compiler/covered comments, with no empty-emitter marker.
- Generated `FpsPane.h` now contains the direct `Pane`/`Singleton<FpsPane>` inheritance, virtuals, methods, complete fields, three extern declarations, and the `0x170` size guard. `MainUiGraph.h` now exports `g_pIMEPaneLayer`.
- The pre-callback defects are resolved: constructor publication is represented by the Singleton specialization and writes `m_hasPendingMotionRegion`; UI/timer calls use inherited APIs; the timer override is `OnTimer`; and compiler/data children use explicit covered-by comments instead of empty emitters.
- The aggregate UID00015D remains a non-emitting split/index parent. Exact child pages own source or compiler-covered dispositions.
- Physical readback is coherent at generated command `27796`: `FpsPane.cpp`/`.h` and `MainUiGraph.h` carry command id `000000027796`, while the independently refreshed tracker command `27800` retains `19/19/0/100.0%`.

## Executive Recommendation

Use UID0000JK as the file root, UID00005F as the class declaration owner, exact method children as CPP body emitters, and the existing by-global pages as one-definition global emitters. Do not merge into ParcelPane, MapPane, ObjectList, or MainUiGraph. C001-C025 now implement this source shape through formal by-* CPP/H channels; generated artifacts remain validator-owned, and C026-C054 remain supervisor-owned.

## Supervisor Active Recheck

- Historical pre-callback assignment constraint: whole-file source-quality began as report-only research with mandatory read-only MCP and no by-* edits before accepted callback. The accepted callback later applied C001-C025 without changing that research provenance.
- Split repair does not require a new master by-memory page. The existing UID00015D split/index and exact children cover the code island without overlap.
- Every discovered source-bearing child now has its complete exact CPP/H payload below. Every compiler-generated/data child has an exact comment-only formal payload or an evidence-backed non-emitting disposition.
- No child remains deferred with only "needs investigation." The previous blockers were actively resolved through current RTTI, slot/callee, offset, xref, byte-boundary, generated-output, and dependency review.

## Inference Research Guidance Check

- Direct IDA facts are kept separate from documentation facts and source-shape inference.
- Raw names such as `sub_4B68B0` and `dword_66DA90`, plus the historical documentation alias `unk_69B334`, are evidence aliases only. Live IDA currently leaves `0x0069B334` unnamed, and final source uses coherent developer-facing names.
- Human-source reconstruction is behavior-first: exact call order, integer signedness, unsafe file behavior, timing, and layout are retained even when safer modern alternatives exist.
- Inferred names follow existing project conventions (`g_p...`, `m_...`, PascalCase methods) unless exact evidence dictates otherwise. Consistency is subordinate to exact behavior and plausible original source shape.
- Stale Wave2/Wave3 material and ParcelPane pollution were ignored as current authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and best conclusion | Disposition |
| --- | --- | --- |
| Direct bases | FpsPane RTTI BCA lists seven transitive entries, while the direct BCDs and PMDs prove direct `Pane` plus EBO `Singleton<FpsPane>` at `+0xf8`. | Declare both direct bases. |
| Singleton stores | Constructor/destructor/scalar paths normalize `this+0xf8` back by `0xf8` before touching `0x0069b334`, matching the accepted Singleton EBO pattern. | Use explicit Singleton specialization; do not hand-code publication in FpsPane ctor/dtor. |
| Constructor byte `+0xf5` | Exact Pane layout maps `+0xf5` to `m_hasPendingMotionRegion`; `m_visible` is `+0xb4`. | Resolved by callback: stale `m_visible = true` was replaced. |
| Callback at `0x004b68b0` | Tertiary FpsPane table is the TimerHandler view and slot `+0x04` is TimerHandler `OnTimer`. | Rename source method to `OnTimer`. |
| `0x004b64a0` UI APIs | Callee `0x004b78d0` writes four bounds dwords; `0x004b64d2` is Pane attachment query; vslots `+0x30/+0x38` are add/remove layer. | Use `RectBounds`, `IsAttachedToLayer`, `AddToLayer`, `RemoveFromLayer`. |
| Timer storage/API | Calls resolve to inherited `TimerHandler::ScheduleTimer` and `RemovePendingTimers`; no embedded timer exists in the exact layout. | Remove invented `m_updateTimer`. |
| Raw helper liveness | No function model, caller xref, VA/RVA/raw-offset pointer hit for three raw starts. Complete source-shaped bodies and active inlined duplicate flows remain exact. | Retain as private methods/retained source implementations; cap confidence only. |
| `+0xfc` field | Exact 4-byte object slot exists between frame counter and float; no in-island read/write was found. | Name conservatively `m_reservedFrameState`, type `unsigned int`, document role as unproven. |
| Counter signedness | Frame conversion follows signed integer conversion; sample/object totals feed unsigned division in summary. | `int m_frameCount`; unsigned sample/object totals. |
| Global linkage | All uses are local but symbols/linkage were not recovered. | Preserve established external definitions; do not invent `static`. |
| Header need | The class has multiple inheritance, virtual overrides, fields, size invariant, and external consumers. | Resolved by callback: required `FpsPane.h` is now generated from formal H content. |
| RTTI physical pages | Exact FpsPane RTTI ranges have no narrow by-memory pages, but source declaration regenerates them. | Prefer exact compiler-data children if validator normal UID creation is approved; never emit raw RTTI arrays. |

Rejected alternatives: `UpdateStatistics` as final virtual name; `m_updateTimer`; `Rect` constructor; `IsVisible`/`Hide`; direct FpsPane-managed singleton global; ParcelPane ownership; MapPane/ObjectList ownership; handwritten vtables/RTTI; raw helper names or decompiler signatures; dropping retained helper source solely because current xrefs are absent.

## Evidence Standards Used

- Highest weight: current bounded MCP function/range queries, disassembly/decompilation, exact xrefs, RTTI descriptors/PMDs, vtable slots, bytes and neighboring starts.
- Corroboration: current by-* metadata/prose, accepted parent API/type docs, generated CPP/H readback, manual coverage rows, and prior report evidence that current checks reproduce.
- Negative evidence: zero xrefs and pointer-pattern hits limits liveness claims but does not override complete body/ownership/source-shape evidence.
- Inference is used for unrecoverable lexemes and historical source factoring, not to alter observed execution behavior.

## Evidence Checked

- `idb_list`, `server_health`, and public `runtime_attestation`: one active exact canonical session; live bounded queries succeeded despite `auto_analysis_ready:false`; runtime and physical-disk receipts are separated above.
- `lookup_funcs` and `inspect_items`: all ten code starts, six modeled functions, four raw code heads, three global heads, all gap heads, all 34 vtable-region dwords, and all RTTI semantic-record boundaries were read literally. Results are itemized below.
- `get_bytes`: exact leading bytes for all ten code starts and all six `0xcc` gaps; exact values `01 00 00 00` at `0x0066da90`, `00 00 00 00` at `0x0069b334`, and `00` at `0x0069b338`.
- `stack_frame`: complete frames for each of the six modeled functions. These frames are reproduced in the IDA prestate table and are protected from mutation.
- `get_comments`: all four function comment channels for each modeled function and both address channels for raw/global items; all are absent. Existing RTTI regular comments `signature` at `0x00647a50` and `reference to RTTI's vftable` at `0x0067628c` were read and protected.
- `xref_query` to every code start, global, key vtable slot/base, and literal: exact typed locations are itemized in Direct Xref / Caller Inventory. Raw starts and the ordinary destructor have zero inbound xrefs; virtual and compiler entries have exact data/code routes.
- `insn_query` over every code range for `call` and `jmp`: one constructor call, destructor tail jump, 27 update calls, 16 paint calls, 6 timer calls, 7 start calls, 12 summary calls, two adjustor tail jumps, and 3 scalar-wrapper calls; all exact sites/callees appear below.
- `entity_query` exact-name collision search: among six proposed function names plus `g_fpsDebugActive`, `g_pFpsPane`, and `g_fpsLogEnabled`, only existing name-index entry `g_fpsLogEnabled` at `0x0069b338` was returned. Therefore only six function renames and the named `dword_66DA90` data rename are expressible/supported.
- Seven one-item `rename` calls with `dry_run:true`, `pure:true`, `allow_overwrite:false`, and `stop_on_error:true` each returned `total:1, ok:1, failed:0`; immediate readback confirmed every raw name/comment/item remained unchanged. No dry-run schema exists for the proposed comment/type endpoints, so none was invoked.
- Documentation read: all 25 target/support destinations enumerated below plus the 22 direct dependency pages, current manual coverage rows, current generated source/header, and exact tracker row.
- Negative checks: no original source symbols, no FpsPane UDT, no direct/raw pointer routes to four raw starts, no discovered use of `+0xfc`, no writer/config route for `g_fpsLogEnabled`, no supported old-name data rename for unnamed `0x0069b334`/`0x0069b338`, and no ParcelPane ownership evidence.
- Historical report-only phase: no validator was run and no IDA mutation/save/manage operation was performed. During the later accepted ordinary callback, scoped validator commands `27767-27795` and waited generated refresh `27796` ran successfully; no IDA mutation/save/manage operation occurred in either phase.

## Claim And Incorporation Ledger

The ledger and final checklist are exact ordered normalized twins. Each row has one destination/action and an explicit actor. C001-C025 are callback-verified and checked; C026-C054 remain proposed, unchecked, and supervisor-owned.

| Claim ID | Actor | Exact destination | Exact one-destination action | Evidence | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | B009 callback | `by-file/FpsPane.md` [UID:0000JK] | Preserve FILE/path; add exhaustive inventory, corrected APIs, exact RTTI/literal/global routes, generated-defect audit, no-route history; set `94/96`. | complete island/docs/generated reconciliation | incorporate | verified 27767/27796 |
| C002 | B009 callback | `by-class/FpsPane.md` [UID:00005F] | Set `94/96`; preserve owner/emitter `0000JK`; insert exact class CPP/H payloads, direct bases, `0x170` layout, virtuals, globals, and Singleton rationale. | RTTI/size/offset/lifecycle evidence | incorporate | verified 27768/27796 |
| C003 | B009 callback | `by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md` [UID:00015C] | Set `93/95`; preserve owner/emitter `00005F`; replace formal CPP with exact constructor payload and correct inherited-field/Singleton prose. | raw body and Pane layout | incorporate | verified 27769/27796 |
| C004 | B009 callback | `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` [UID:00015D] | Set `92/95`; preserve owner `0000JK`, `RECONSTRUCTABLE:FALSE`, blank emitter/CPP/H; add exact 10-code/6-gap split inventory. | complete range closure | incorporate | verified 27770/27796 |
| C005 | B009 callback | `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` [UID:00015E] | Set `93/95`; preserve owner/emitter `00005F`; insert exact empty authored destructor and compiler/base-lifecycle explanation. | body/tail jump/vptr/global refs | incorporate | verified 27771/27796 |
| C006 | B009 callback | `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` [UID:00015F] | Set `94/95`; preserve owner/emitter `00005F`; replace formal CPP with exact `RectBounds`/layer/inherited-timer payload and full call evidence. | 27 calls, fields, globals, literals | incorporate | verified 27772/27796 |
| C007 | B009 callback | `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md` [UID:00015G] | Set `93/95`; preserve owner/emitter `00005F`; retain the exact formal CPP reproduced below and add complete frame/xref/header route. | vtable slot, 16 calls, literal | incorporate | verified 27773/27796 |
| C008 | B009 callback | `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` [UID:00015H] | Set `94/96`; preserve UID/range/owner/emitter; change source-facing title/identity to `FpsPaneOnTimer`, retain old identity historically, replace exact CPP. | TimerHandler vtable/signature/calls | incorporate | verified 27774/27796 |
| C009 | B009 callback | `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` [UID:00015I] | Set `92/94`; preserve owner/emitter `00005F`; retain exact CPP reproduced below and exhaustive zero-route/literal evidence. | complete raw body and active twin | incorporate | verified 27775/27796 |
| C010 | B009 callback | `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` [UID:00015J] | Set `92/94`; preserve owner/emitter `00005F`; retain exact CPP reproduced below and exhaustive zero-route/literal evidence. | complete raw body and active twin | incorporate | verified 27776/27796 |
| C011 | B009 callback | `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md` [UID:00015K] | Set `90/96`; preserve `NONE/FALSE` and blank emitter/CPP/H; document both exact thunks as compiler glue. | two vtable refs and tail jumps | incorporate | verified 27777/27796 |
| C012 | B009 callback | `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` [UID:00015L] | Set `91/96`; preserve owner/emitter `00005F`; retain exact compiler-covered CPP comment and blank H. | primary/thunk refs and flag path | incorporate | verified 27782/27796 |
| C013 | B009 callback | `by-type/by-struct/FpsPaneLayout.md` [UID:0001UO] | Set `94/96`; preserve owner/emitter `00005F`; add normalized direct bases/fields/size and exact class-covered CPP comment; blank H with declaration-owned reason. | complete offset closure | incorporate | verified 27783/27796 |
| C014 | B009 callback | `by-type/by-vtable/FpsPane_vtables.md` [UID:0001XN] | Set `93/96`; preserve owner/emitter `00005F`; correct `OnTimer`, enumerate all views/slots/RTTI, insert exact compiler-covered CPP comment; blank H. | 34 physical dwords and RTTI | incorporate | verified 27784/27796 |
| C015 | B009 callback | `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md` [UID:0002MJ] | Set `93/96`; preserve owner/emitter `00005F`; insert exact compiler-covered CPP comment, complete slot table and boundaries; blank H. | exact bytes/slots/lifecycle stores | incorporate | verified 27785/27796 |
| C016 | B009 callback | `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md` [UID:0003BJ] | Set `93/96`; preserve owner/emitter `0000JK`; populate Item Summary, 15-literal inventory, xrefs, exact source-literal CPP comment; blank H. | exact strings/xrefs/boundaries | incorporate | verified 27786/27796 |
| C017 | B009 callback | `by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md` [UID:00025E] | Set `90/95`; preserve `NONE/FALSE` and blank emitter/CPP/H; retain non-emitting two-child index and strict successor. | exact child partition | incorporate | verified 27787/27796 |
| C018 | B009 callback | `by-global/g_fpsDebugActive.md` [UID:0000PY] | Set `92/94`; preserve owner/emitter `0000JK`; retain exact CPP `int g_fpsDebugActive = 1;`, blank H because declaration is centralized in FpsPane H. | bytes and four refs | incorporate | verified 27788/27796 |
| C019 | B009 callback | `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` [UID:00027E] | Set `92/95`; preserve owner/emitter `0000JK`; retain exact covered-storage CPP comment and blank H. | 4-byte initialized cell | incorporate | verified 27789/27796 |
| C020 | B009 callback | `by-global/g_fpsLogEnabled.md` [UID:0000PZ] | Set `94/96`; preserve owner/emitter `0000JK`; retain exact CPP `bool g_fpsLogEnabled;`, blank H because declaration is centralized in FpsPane H. | one-byte zero fill/four reads | incorporate | verified 27790/27796 |
| C021 | B009 callback | `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` [UID:0002W1] | Set `94/96`; preserve owner/emitter `0000JK`; retain exact covered-storage CPP comment and blank H. | one-byte head/boundary/xrefs | incorporate | verified 27791/27796 |
| C022 | B009 callback | `by-global/g_pFpsPane.md` [UID:0000QZ] | Set `94/96`; preserve owner/emitter `0000JK`; replace CPP with exact `FpsPane *g_pFpsPane = 0;`, blank H because declaration is centralized in FpsPane H. | three lifecycle refs/Singleton EBO | incorporate | verified 27792/27796 |
| C023 | B009 callback | `by-memory/0x0069b334-0x0069b338.g_pFpsPane.md` [UID:0002W0] | Set `94/96`; preserve owner/emitter `0000JK`; insert exact covered-storage CPP comment and blank H, removing its empty emitter. | 4-byte physical cell/three writes | incorporate | verified 27793/27796 |
| C024 | B009 callback | `by-global/g_pIMEPaneLayer.md` [UID:0004VG] | Keep `92/94`, owner/emitter `0000L1`, position `60`; retain CPP definition and insert exact formal H declaration `class Layer; extern Layer *g_pIMEPaneLayer;`. | exact FpsPane consumer and owner route | incorporate | verified 27794/27796 |
| C025 | B009 callback | `by-file/MainUiGraph.md` [UID:0000L1] | Keep `90/92`/FILE; document UID0004VG H ownership and expected `MainUiGraph.h` declaration without transferring FpsPane ownership. | owner metadata/generated absence | incorporate | verified 27795/27796 |
| C026 | supervisor Gate 2B | IDA function `0x004b6470` | Pure rename only to `FpsPane__Destructor` under atomic A01. | current name/type/frame/dry run P02 | incorporate | proposed |
| C027 | supervisor Gate 2B | IDA function `0x004b67b0` | Pure rename only to `FpsPane__OnPaint` under atomic A02. | current name/type/frame/dry run P04 | incorporate | proposed |
| C028 | supervisor Gate 2B | IDA function `0x004b68b0` | Pure rename only to `FpsPane__OnTimer` under atomic A03. | current name/type/frame/dry run P05 | incorporate | proposed |
| C029 | supervisor Gate 2B | IDA function `0x004b6c2b` | Pure rename only to `FpsPane__ScalarDeletingDestructorAdjustorA0` under atomic A04. | current name/type/frame/dry run P08 | incorporate | proposed |
| C030 | supervisor Gate 2B | IDA function `0x004b6c36` | Pure rename only to `FpsPane__ScalarDeletingDestructorAdjustorA4` under atomic A05. | current name/type/frame/dry run P09 | incorporate | proposed |
| C031 | supervisor Gate 2B | IDA function `0x004b6c50` | Pure rename only to `FpsPane__ScalarDeletingDestructor` under atomic A06. | current name/type/frame/dry run P10 | incorporate | proposed |
| C032 | supervisor Gate 2B | IDA data `0x0066da90` | Pure rename only from `dword_66DA90` to `g_fpsDebugActive` under atomic A07. | named 4-byte item/dry run P11 | incorporate | proposed |
| C033 | supervisor Gate 2B | IDA data `0x0066da90` | Set only global type `int` under atomic A08 after rename readback. | 4-byte width/value/xrefs P11 | incorporate | proposed |
| C034 | supervisor Gate 2B | IDA address `0x004b6470` | Set only repeatable address comment under A09. | four comment channels absent P02 | incorporate | proposed |
| C035 | supervisor Gate 2B | IDA address `0x004b67b0` | Set only repeatable address comment under A10. | four comment channels absent P04 | incorporate | proposed |
| C036 | supervisor Gate 2B | IDA address `0x004b68b0` | Set only repeatable address comment under A11. | four comment channels absent P05 | incorporate | proposed |
| C037 | supervisor Gate 2B | IDA address `0x004b6c2b` | Set only repeatable address comment under A12. | four comment channels absent P08 | incorporate | proposed |
| C038 | supervisor Gate 2B | IDA address `0x004b6c36` | Set only repeatable address comment under A13. | four comment channels absent P09 | incorporate | proposed |
| C039 | supervisor Gate 2B | IDA address `0x004b6c50` | Set only repeatable address comment under A14. | four comment channels absent P10 | incorporate | proposed |
| C040 | supervisor Gate 2B | IDA address `0x0066da90` | Set only repeatable address comment under A15. | address comments absent P11 | incorporate | proposed |
| C041 | supervisor Gate 2B | IDA address `0x0069b334` | Set only repeatable address comment under A16; no unsupported rename/item shaping. | unnamed one-byte head/4-byte physical cell P12 | incorporate | proposed |
| C042 | supervisor Gate 2B | IDA address `0x0069b338` | Set only repeatable address comment under A17; no unsupported rename/item shaping. | name-index/item discrepancy and bool P13 | incorporate | proposed |
| C043 | supervisor Gate 2B | IDA raw address `0x004b6410` | Set only repeatable address comment under A18; retain nonfunction. | raw constructor P01 | incorporate | proposed |
| C044 | supervisor Gate 2B | IDA raw address `0x004b64a0` | Set only repeatable address comment under A19; retain nonfunction. | raw update P03 | incorporate | proposed |
| C045 | supervisor Gate 2B | IDA raw address `0x004b69b0` | Set only repeatable address comment under A20; retain nonfunction. | raw start helper P06 | incorporate | proposed |
| C046 | supervisor Gate 2B | IDA raw address `0x004b6ae0` | Set only repeatable address comment under A21; retain nonfunction. | raw summary helper P07 | incorporate | proposed |
| C047 | supervisor | `by-file/-coverage-report.md` | Apply exact UID0000JK replacement text from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| C048 | supervisor | `by-class/-coverage-report.md` | Apply exact UID00005F replacement text from this report after callback metadata validation. | stale 84% row | incorporate | proposed |
| C049 | supervisor | `by-type/by-struct/-coverage-report.md` | Apply exact UID0001UO replacement text from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| C050 | supervisor | `by-type/by-vtable/-coverage-report.md` | Apply exact UID0001XN replacement text from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| C051 | supervisor | `by-global/-coverage-report.md` | Apply exact UID0000PY/0000PZ/0000QZ replacement block from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| C052 | supervisor | `by-memory/-coverage-report.md` | Apply exact code/data/global-storage replacement blocks from this report after callback metadata validation. | current subtree comparison | incorporate | proposed |
| C053 | supervisor | validator/generated outputs | Run every exact scoped command and final `--wait-generated` command below; physically verify expected CPP/H/tracker readbacks. | validator/generator contract | incorporate | proposed |
| C054 | supervisor | report lifecycle | After fresh Gate 1, callback, Gate 2A/2B, coverage, validation and exact archived-artifact audit, own report execution/archive state. | role boundary | incorporate | proposed |

## Positive Evidence Summary

- The code island is contiguous, bounded by exact alignment, and every authored function uses FpsPane fields/globals/literals.
- Three construction/destruction paths write the same three vtable views; RTTI independently identifies Pane, EventHandler, TimerHandler, and Singleton relationships.
- The scalar wrapper's size path proves `sizeof(FpsPane) == 0x170`.
- Direct callees and inherited vtable slots resolve every stale API name in `UpdateFpsLogSession`.
- OnPaint increments the frame count that OnTimer samples/reset; the timer method updates the logging accumulators consumed by WriteLogSummary.
- Global use distributions distinguish initialization (`g_fpsDebugActive`), read-only gate (`g_fpsLogEnabled`), and singleton publication (`g_pFpsPane`).

## IDA MCP Facts

- Authority: public attestation schema `1`, `ok:true`, exact active session/path, listener PID/generation `3612` / `pid:3612;created:134318146704590877`, worker PID/parent/generation `13592/12952` / `pid:13592;created:134320657005157164`, no attestation errors. Physical IDB identity is separately sealed as `143211656` bytes and SHA256 `AED88CDF9B4A98E0D2F5BDD71670C74E10F522F3B621DD9AA92ADFBBF6171187`.
- Modeled functions and literal current types: `0x004b6470` `sub_4B6470`, size `0x29`, `void __thiscall(_DWORD *this)`; `0x004b67b0` `sub_4B67B0`, size `0xfb`, `void __thiscall(int this)`; `0x004b68b0` `sub_4B68B0`, size `0x100`, `char __thiscall(int this,int,int,int)`; `0x004b6c2b`/`0x004b6c36`, size `0x0b`, `_DWORD *__thiscall(_DWORD *this,char)`; `0x004b6c50`, size `0x5f`, `_DWORD *__thiscall(_DWORD *Block,char)`.
- Complete frames: destructor only return-address row `0x0/4`; OnPaint rows `var_34 0x0/0xc __int16[6]`, `var_24 0x10/4`, `outBounds 0x14/0x10 RectBounds`, `var_10 0x24/4`, `var_C 0x28/4`, `var_4 0x30/4`, saved registers `0x34/4`, return address `0x38/4`, `arg_4 0x40/4`; OnTimer rows `visibleBounds 0x4/0x10 MapRect`, `var_4 0x14/4`, saved registers `0x18/4`, return address `0x1c/4`; each adjustor only return address `0x0/4`; scalar rows saved registers `0x4/4`, return address `0x8/4`, `arg_0 0xc/4`.
- Raw code heads: `0x004b6410`, `0x004b64a0`, `0x004b69b0`, `0x004b6ae0` are code items but have no modeled function/name/type. All direct/code/data/immediate and VA/RVA/raw-offset pointer checks found no inbound route.
- Boundaries: constructor ends `0x004b646b` then five `cc`; destructor ends `0x004b6499` then seven; update ends `0x004b67a7` then nine; paint ends `0x004b68ab` then five; start ends `0x004b6adc` then four; adjustors end `0x004b6c41` then fifteen; scalar ends `0x004b6caf`, unrelated code starts `0x004b6cb0`.
- Comment state: all four channels (`regular`, `repeatable`, `function_regular`, `function_repeatable`) are absent for six modeled functions; both address channels are absent for four raw starts and three globals. Existing RTTI regular comments at `0x00647a50` and `0x0067628c` are nonblank and protected.
- Collision/dry-run state: exact-name search returned only pre-existing name-index entry `g_fpsLogEnabled` at `0x0069b338`; seven supported one-item pure rename dry runs each succeeded `1/1` and immediate readback preserved raw names/items/comments. `0x0069b334` and `0x0069b338` have no supported current old-name data rename action, so none is recommended.
- Exact RTTI hierarchy and descriptor records are R01-R12 above. Exact vtable items are V01-V34. Exact global and code xrefs/calls are in the direct inventory; no sampled subset is used.

## Function / Child Inventory

### Code bodies, adjustors, and gaps

| # | Exact half-open range | UID / item | Model and role | Source disposition |
| ---: | --- | --- | --- | --- |
| K01 | `0x004b6410-0x004b646b` | 00015C raw constructor | unmodeled code head; authored constructor | exact CPP in 00015C |
| K02 | `0x004b646b-0x004b6470` | gap G01 | five bytes `cc cc cc cc cc` | no source; protect |
| K03 | `0x004b6470-0x004b6499` | 00015E `sub_4B6470` | modeled size `0x29`; authored empty destructor plus base/compiler effects | exact CPP in 00015E |
| K04 | `0x004b6499-0x004b64a0` | gap G02 | seven `cc` bytes | no source; protect |
| K05 | `0x004b64a0-0x004b67a7` | 00015F raw controller | unmodeled code head; authored `UpdateFpsLogSession` | corrected exact CPP in 00015F |
| K06 | `0x004b67a7-0x004b67b0` | gap G03 | nine `cc` bytes | no source; protect |
| K07 | `0x004b67b0-0x004b68ab` | 00015G `sub_4B67B0` | modeled size `0xfb`; primary virtual `OnPaint` | exact CPP in 00015G |
| K08 | `0x004b68ab-0x004b68b0` | gap G04 | five `cc` bytes | no source; protect |
| K09 | `0x004b68b0-0x004b69b0` | 00015H `sub_4B68B0` | modeled size `0x100`; TimerHandler-adjusted `OnTimer` | corrected exact CPP in 00015H |
| K10 | `0x004b69b0-0x004b6adc` | 00015I raw helper | unmodeled code head; retained authored `StartLogSession` | exact CPP in 00015I |
| K11 | `0x004b6adc-0x004b6ae0` | gap G05 | four `cc` bytes | no source; protect |
| K12 | `0x004b6ae0-0x004b6c2b` | 00015J raw helper | unmodeled code head; retained authored `WriteLogSummary` | exact CPP in 00015J |
| K13 | `0x004b6c2b-0x004b6c36` | 00015K `sub_4B6C2B` | modeled size `0x0b`; `+0xa0` deleting-destructor adjustor | compiler-generated; no formal source |
| K14 | `0x004b6c36-0x004b6c41` | 00015K `sub_4B6C36` | modeled size `0x0b`; `+0xa4` deleting-destructor adjustor | compiler-generated; no formal source |
| K15 | `0x004b6c41-0x004b6c50` | gap G06 | fifteen `cc` bytes | no source; protect |
| K16 | `0x004b6c50-0x004b6caf` | 00015L `sub_4B6C50` | modeled size `0x5f`; scalar deleting destructor | exact compiler-covered CPP comment |

### Semantic globals and physical children

| # | Exact item | Semantic UID / physical UID | Literal current storage | Formal disposition |
| ---: | --- | --- | --- | --- |
| D01 | `0x0066da90-0x0066da94` | 0000PY / 00027E | named `dword_66DA90`, 4-byte data, bytes `01 00 00 00`, blank type | one `int g_fpsDebugActive = 1;` definition plus physical covered comment |
| D02 | `0x0069b334-0x0069b338` | 0000QZ / 0002W0 | four physical zero bytes represented by unnamed one-byte heads, blank type | one `FpsPane *g_pFpsPane = 0;` definition plus physical covered comment |
| D03 | `0x0069b338-0x0069b339` | 0000PZ / 0002W1 | unnamed one-byte item head, type `bool`, name index contains `g_fpsLogEnabled`, byte `00` | one `bool g_fpsLogEnabled;` definition plus physical covered comment |

### Exact vtable-region items

Every 4-byte item in `[0x0061a61c,0x0061a6a4)` is inventoried; the range contains 34 dwords, not three sampled table bases.

| # | Address | Kind | Current value / target | Disposition |
| ---: | --- | --- | --- | --- |
| V01 | `0x0061a61c` | primary RTTI locator | `0x00647a50` `??_R4FpsPane@@6B@` | compiler-generated from declaration |
| V02 | `0x0061a620` | primary slot `+0x00` | `0x004b6c50` scalar wrapper | compiler-generated virtual slot |
| V03 | `0x0061a624` | primary slot `+0x04` | `0x004f4b10` inherited/default | inherited slot |
| V04 | `0x0061a628` | primary slot `+0x08` | `0x0041b6c0` `nullsub_18` | inherited slot |
| V05 | `0x0061a62c` | primary slot `+0x0c` | `0x004b8e20` pane bounds/paint support | inherited slot |
| V06 | `0x0061a630` | primary slot `+0x10` | `0x0041d680` `nullsub_19` | inherited slot |
| V07 | `0x0061a634` | primary slot `+0x14` | `0x00544730` | inherited Pane behavior |
| V08 | `0x0061a638` | primary slot `+0x18` | `0x00544750` | inherited Pane behavior |
| V09 | `0x0061a63c` | primary slot `+0x1c` | `0x005447a0` | inherited Pane behavior |
| V10 | `0x0061a640` | primary slot `+0x20` | `0x00544800` | inherited Pane behavior |
| V11 | `0x0061a644` | primary slot `+0x24` | `0x00544a20` | inherited Pane behavior |
| V12 | `0x0061a648` | primary slot `+0x28` | `0x00544b80` | inherited Pane behavior |
| V13 | `0x0061a64c` | primary slot `+0x2c` | `0x00544bd0` | inherited Pane behavior |
| V14 | `0x0061a650` | primary slot `+0x30` | `0x00544c70` | inherited Pane behavior |
| V15 | `0x0061a654` | primary slot `+0x34` | `0x00544cb0` | inherited Pane behavior |
| V16 | `0x0061a658` | primary slot `+0x38` | `0x00544ce0` | inherited Pane behavior |
| V17 | `0x0061a65c` | primary slot `+0x3c` | `0x00544d30` | inherited Pane behavior |
| V18 | `0x0061a660` | primary slot `+0x40` | `0x00544d70` | inherited Pane behavior |
| V19 | `0x0061a664` | primary slot `+0x44` | `0x004b67b0` FpsPane `OnPaint` | authored virtual body 00015G |
| V20 | `0x0061a668` | secondary RTTI locator | `0x00647b00` `??_R4FpsPane@@6B@_0` | compiler-generated |
| V21 | `0x0061a66c` | secondary slot `+0x00` | `0x004b6c2b` adjustor | compiler-generated |
| V22 | `0x0061a670` | secondary slot `+0x04` | `0x00544db0` | inherited EventHandler behavior |
| V23 | `0x0061a674` | secondary slot `+0x08` | `0x00544dc0` | inherited EventHandler behavior |
| V24 | `0x0061a678` | secondary slot `+0x0c` | `0x00544dd0` | inherited EventHandler behavior |
| V25 | `0x0061a67c` | secondary slot `+0x10` | `0x00544de0` | inherited EventHandler behavior |
| V26 | `0x0061a680` | secondary slot `+0x14` | `0x00544df0` | inherited EventHandler behavior |
| V27 | `0x0061a684` | secondary slot `+0x18` | `0x00544e00` | inherited EventHandler behavior |
| V28 | `0x0061a688` | secondary slot `+0x1c` | `0x004a89f0` | inherited pane/dialog behavior |
| V29 | `0x0061a68c` | secondary slot `+0x20` | `0x00544e10` | inherited EventHandler behavior |
| V30 | `0x0061a690` | secondary slot `+0x24` | `0x00544e30` | inherited EventHandler behavior |
| V31 | `0x0061a694` | secondary slot `+0x28` | `0x00544e70` | inherited EventHandler behavior |
| V32 | `0x0061a698` | tertiary RTTI locator | `0x00647b14` `??_R4FpsPane@@6B@_1` | compiler-generated |
| V33 | `0x0061a69c` | tertiary slot `+0x00` | `0x004b6c36` adjustor | compiler-generated |
| V34 | `0x0061a6a0` | tertiary slot `+0x04` | `0x004b68b0` FpsPane `OnTimer` | authored virtual body 00015H |

### Exact RTTI semantic records

| # | Exact range | Current named head / record | Disposition |
| ---: | --- | --- | --- |
| R01 | `0x00647a50-0x00647a64` | `??_R4FpsPane@@6B@`, primary complete-object locator | compiler-generated; existing `signature` comment protected |
| R02 | `0x00647a64-0x00647a74` | `??_R3FpsPane@@8`, class-hierarchy descriptor | compiler-generated |
| R03 | `0x00647a74-0x00647a94` | `??_R2FpsPane@@8`, seven-entry base-class array | compiler-generated |
| R04 | `0x00647a94-0x00647ab0` | `??_R1A@?0A@EA@FpsPane@@8`, FpsPane base descriptor | compiler-generated |
| R05 | `0x00647ab0-0x00647acc` | `??_R1PI@?0A@EA@?$Singleton@VFpsPane@@@@8`, Singleton direct-base descriptor at PMD `+0xf8` | compiler-generated |
| R06 | `0x00647acc-0x00647adc` | `??_R3?$Singleton@VFpsPane@@@@8`, Singleton hierarchy descriptor | compiler-generated |
| R07 | `0x00647adc-0x00647ae4` | `??_R2?$Singleton@VFpsPane@@@@8`, Singleton base array | compiler-generated |
| R08 | `0x00647ae4-0x00647b00` | `??_R1A@?0A@EA@?$Singleton@VFpsPane@@@@8`, Singleton self descriptor | compiler-generated |
| R09 | `0x00647b00-0x00647b14` | `??_R4FpsPane@@6B@_0`, secondary complete-object locator | compiler-generated |
| R10 | `0x00647b14-0x00647b28` | `??_R4FpsPane@@6B@_1`, tertiary complete-object locator | compiler-generated; successor FrameHandler RTTI starts `0x00647b28` |
| R11 | `0x0067628c-0x006762a4` | `??_R0?AVFpsPane@@@8` plus `.?AVFpsPane@@` text | compiler-generated; existing `reference to RTTI's vftable` comment protected |
| R12 | `0x006762a4-0x006762cc` | `??_R0?AV?$Singleton@VFpsPane@@@@@8` plus type text | compiler-generated; successor descriptor begins `0x006762cc` |

No new RTTI by-memory page is recommended. R01-R12 are fully carried by UID00005F/UID0001XN/UID0002MJ; creating speculative narrow pages would add registry churn without source-bearing content.

### Exact literal/data items

| # | Address | Literal | Exact use disposition |
| ---: | --- | --- | --- |
| L01 | `0x0061a6a4` | `FPSDATA-%d-%d-%d-%d-%d.txt` | refs `0x004b6588`, `0x004b6a60`; embedded in controller/start source |
| L02 | `0x0061a6c0` | `w` | refs `0x004b6595`, `0x004b6a6d`; fopen mode |
| L03 | `0x0061a6c4` | `***NEW_CLIENT***\n` | refs `0x004b65a4`, `0x004b6a7c` |
| L04 | `0x0061a6d8` | CP949 start-time format | refs `0x004b65b5`, `0x004b6a8d` |
| L05 | `0x0061a700` | `a` | refs `0x004b6652`, `0x004b6af4`; append mode |
| L06 | `0x0061a704` | `------------------------\n` | refs `0x004b6667`, `0x004b6b09` |
| L07 | `0x0061a720` | CP949 elapsed-time format ending `%dsec\n` | refs `0x004b6683`, `0x004b6b25` |
| L08 | `0x0061a734` | `minFPS : %5.1f\n` | refs `0x004b66b0`, `0x004b6b52` |
| L09 | `0x0061a744` | `maxFPS : %5.1f\n` | refs `0x004b66d0`, `0x004b6b72` |
| L10 | `0x0061a754` | `aveFPS : %5.1f\n` | refs `0x004b670b`, `0x004b6bad` |
| L11 | `0x0061a764` | `aveLivingObject  : %d\n` | refs `0x004b6727`, `0x004b6bc9` |
| L12 | `0x0061a77c` | `aveBalloonObject : %d\n` | refs `0x004b6743`, `0x004b6be5` |
| L13 | `0x0061a794` | `aveStaticObject  : %d\n` | refs `0x004b675f`, `0x004b6c01` |
| L14 | `0x0061a7ac` | `------------------------\n\n` | refs `0x004b676c`, `0x004b6c0e` |
| L15 | `0x0061a7c8` | UTF-16 `%5.1f FPS` | ref `0x004b67f7`; embedded in OnPaint source; strict end `0x0061a7dc` |

### Complete related by-* page inventory

| # | UID / exact path | Historical pre-callback metadata / formal state | Pre-callback required disposition, fulfilled by C001-C025 |
| ---: | --- | --- | --- |
| P01 | 0000JK `by-file/FpsPane.md` | `89/90`, `FILE`, path `NexusTK/ui/diagnostics/` | fulfilled by C001 |
| P02 | 00005F `by-class/FpsPane.md` | `87/88`, owner/emitter 0000JK, true, CPP/H blank | fulfilled by C002 |
| P03 | 00015C `by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md` | `86/90`, owner/emitter 00005F, true, CPP nonblank/H blank | fulfilled by C003 |
| P04 | 00015D `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` | `88/91`, owner 0000JK, false, emitter/CPP/H blank | fulfilled by C004 |
| P05 | 00015E `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` | `88/91`, owner/emitter 00005F, true, CPP nonblank/H blank | fulfilled by C005 |
| P06 | 00015F `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` | `89/89`, owner/emitter 00005F, true, CPP nonblank/H blank | fulfilled by C006 |
| P07 | 00015G `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md` | `88/91`, owner/emitter 00005F, true, CPP nonblank/H blank | fulfilled by C007 |
| P08 | 00015H `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` | `88/91`, owner/emitter 00005F, true, stale CPP identity/H blank | fulfilled by C008 |
| P09 | 00015I `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` | `88/89`, owner/emitter 00005F, true, CPP nonblank/H blank | fulfilled by C009 |
| P10 | 00015J `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` | `88/89`, owner/emitter 00005F, true, CPP nonblank/H blank | fulfilled by C010 |
| P11 | 00015K `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md` | `86/90`, NONE/FALSE, emitter/CPP/H blank | fulfilled by C011 |
| P12 | 00015L `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` | `86/91`, owner/emitter 00005F, true, comment CPP/H blank | fulfilled by C012 |
| P13 | 0001UO `by-type/by-struct/FpsPaneLayout.md` | `88/90`, owner/emitter 00005F, true, CPP/H blank | fulfilled by C013 |
| P14 | 0001XN `by-type/by-vtable/FpsPane_vtables.md` | `85/90`, owner/emitter 00005F, true, CPP/H blank | fulfilled by C014 |
| P15 | 0002MJ `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md` | `87/92`, owner/emitter 00005F, true, CPP/H blank | fulfilled by C015 |
| P16 | 0003BJ `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md` | `89/92`, owner/emitter 0000JK, true, CPP/H blank/empty summary | fulfilled by C016 |
| P17 | 00025E `by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md` | `86/92`, NONE/FALSE, emitter/CPP/H blank | fulfilled by C017 |
| P18 | 0000PY `by-global/g_fpsDebugActive.md` | `88/89`, owner/emitter 0000JK, true, CPP definition/H blank | fulfilled by C018 |
| P19 | 00027E `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` | `88/90`, owner/emitter 0000JK, true, covered CPP/H blank | fulfilled by C019 |
| P20 | 0000PZ `by-global/g_fpsLogEnabled.md` | `92/93`, owner/emitter 0000JK, true, CPP definition/H blank | fulfilled by C020 |
| P21 | 0002W1 `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` | `92/94`, owner/emitter 0000JK, true, covered CPP/H blank | fulfilled by C021 |
| P22 | 0000QZ `by-global/g_pFpsPane.md` | `87/90`, owner/emitter 0000JK, true, CPP definition/H blank | fulfilled by C022 |
| P23 | 0002W0 `by-memory/0x0069b334-0x0069b338.g_pFpsPane.md` | `88/91`, owner/emitter 0000JK, true, CPP/H blank | fulfilled by C023 |
| P24 | 0004VG `by-global/g_pIMEPaneLayer.md` | `92/94`, owner/emitter 0000L1, true, position 60, CPP definition/H blank | fulfilled by C024 |
| P25 | 0000L1 `by-file/MainUiGraph.md` | `90/92`, FILE | fulfilled by C025 |

### Direct dependency page inventory

| # | UID / path | Dependency role | Change disposition |
| ---: | --- | --- | --- |
| Q01 | 0000A2 `by-class/Pane.md` | direct polymorphic base and inherited fields/APIs | read-only evidence; no change |
| Q02 | 0000MC `by-file/Pane.md` | Pane source owner | read-only evidence; no change |
| Q03 | 0004ZL `by-type/by-template/SingletonTemplate.md` | direct EBO base pattern | read-only evidence; no change |
| Q04 | 0004ZK `by-file/Singleton.md` | Singleton source declarations | read-only evidence; no change |
| Q05 | 0000F0 `by-class/TimerHandler.md` | `OnTimer`, `ScheduleTimer`, `RemovePendingTimers` | read-only evidence; no change |
| Q06 | 0004ZO `by-file/TimerHandler.md` | timer source owner | read-only evidence; no change |
| Q07 | 0000BU `by-class/RectBounds.md` | `SetLTRB` and local bounds type | read-only evidence; no change |
| Q08 | 0000N2 `by-file/RectBounds.md` | bounds source owner | read-only evidence; no change |
| Q09 | 00007Q `by-class/MapPane.md` | visible-tile bounds/object-list member | read-only evidence; no change |
| Q10 | 0000L3 `by-file/MapPane.md` | MapPane source owner | read-only evidence; no change |
| Q11 | 0000PR `by-global/g_activeMapPane.md` | active map singleton consumer | read-only evidence; no change |
| Q12 | 00009Q `by-class/ObjectList.md` | front/back/visible count APIs | read-only evidence; no change |
| Q13 | 0000M4 `by-file/ObjectList.md` | ObjectList source owner | read-only evidence; no change |
| Q14 | 000079 `by-class/List.md` | count-bearing list dependency | read-only evidence; no change |
| Q15 | 0000KS `by-file/List.md` | List source owner | read-only evidence; no change |
| Q16 | 0001WS `by-type/by-template/StringBaseTemplate.md` | wide formatted overlay string | read-only evidence; no change |
| Q17 | 0000OA `by-file/StringBase.md` | string source owner | read-only evidence; no change |
| Q18 | 00005V `by-class/GrafPort.md` | bounds/color/move/text methods | read-only evidence; no change |
| Q19 | 0000JR `by-file/GrafPort.md` | rendering source owner | read-only evidence; no change |
| Q20 | 0000TN `by-global/SurfaceRenderCallbackTable.md` | fill callback at `0x0069b3fc` | read-only evidence; no change |
| Q21 | 0004VG `by-global/g_pIMEPaneLayer.md` | layer-parent global used by update | affected support C024 |
| Q22 | 0000L1 `by-file/MainUiGraph.md` | owner/header route for Q21 | affected support C025 |

Inventory totals: 10 exact code bodies/entries (7 authored, 2 adjustors, 1 scalar wrapper), 6 exact alignment gaps, 3 semantic globals plus 3 physical children, 34 vtable-region dwords, 12 RTTI semantic records, 15 literal items, 25 target/support pages, and 22 direct dependency pages. Every source-bearing item has an exact formal CPP/H destination; every compiler/data item has a comment-only or non-emitting disposition; no sampled remainder or optional unresolved split remains.

## Direct Xref / Caller Inventory

| Item | Exact typed inbound route | Exact outbound calls/jumps or data operation | Result |
| --- | --- | --- | --- |
| raw ctor `0x004b6410` | `xref_query(to,any)` total `0`; code/data/immediate and VA/RVA/raw-offset pointer checks total `0` | call `0x004b641c -> Pane__Constructor`; internal jump `0x004b6430 -> 0x004b6434`; stores primary/secondary/tertiary vptrs at `0x004b643b/41/4b`; writes pointer cell at `0x004b6434` | authored constructor body retained; no live caller claimed |
| destructor `0x004b6470` | total `0` inbound xrefs | vptr stores `0x004b6470 -> 0x0061a620`, `0x004b6476 -> 0x0061a66c`, `0x004b6480 -> 0x0061a69c`; pointer clear `0x004b648a -> 0x0069b334`; tail jump `0x004b6494 -> Pane__Destructor` | authored empty destructor plus compiler/base effects |
| raw update `0x004b64a0` | total `0` inbound xrefs and pointer hits | `0x4b64c1 sub_4B78D0(SetLTRB)`, `64d2 sub_544C50(IsAttachedToLayer)`, `64df timeGetTime`, `6554 GetLocalTime`, `6590 sub_443A00(sprintf_s route)`, `659f fopen_s`, `65ac/65e1 sub_443990(fprintf route)`, `65ec fclose`, `6611 vcall[eax+30h](AddToLayer)`, `662f TimerHandler__ScheduleTimer`, `663a security cookie`, `6662 fopen_s`, `666f sub_443990`, `6677 timeGetTime`, `6698/66b8/66d8/6713/672f/674b/6767/6774 sub_443990`, `677c fclose`, `6788 vcall[eax+38h](RemoveFromLayer)`, `6791 sub_597600(RemovePendingTimers)`, `679c security cookie` | complete authored controller; active inline start/summary flows explain retained helpers |
| OnPaint `0x004b67b0` | one data xref `0x0061a664 -> 0x004b67b0`; no direct code caller | `67fd sub_583280`, `6812 GrafPort_GetBounds`, `681b GrafPort_SetDrawColor`, `6826 call [0x0069b3fc]`, `6833/6860 GrafPort_SetTextColor`, `683e/686b GrafPort_MoveTo`, `6846/6873 sub_584CF0`, `684f/687c sub_584540`, `6857/6884 GrafPort_DrawWideText`, `688c sub_582B70`, `68a2 security cookie` | primary virtual paint override |
| OnTimer `0x004b68b0` | one data xref `0x0061a6a0 -> 0x004b68b0`; no direct code caller | `6939 MapPane_GetClampedVisibleTileBounds`, `6954 sub_532670` front-row bucket, `6965 sub_5326D0` back-row bucket, `697b sub_532610` visible list, `6998 TimerHandler__ScheduleTimer`, `69a5 security cookie` | TimerHandler-adjusted virtual override |
| raw start `0x004b69b0` | total `0` inbound xrefs and pointer hits | `69b7 timeGetTime`, `6a2c GetLocalTime`, `6a68 sub_443A00`, `6a77 fopen_s`, `6a84/6ab9 sub_443990`, `6ac4 fclose` | complete retained private helper; no live caller claimed |
| raw summary `0x004b6ae0` | total `0` inbound xrefs and pointer hits | `6b04 fopen_s`, `6b11 sub_443990`, `6b19 timeGetTime`, `6b3a/6b5a/6b7a/6bb5/6bd1/6bed/6c09/6c16 sub_443990`, `6c1e fclose` | complete retained private helper; no live caller claimed |
| adjustor `0x004b6c2b` | one data xref `0x0061a66c -> 0x004b6c2b` | `0x004b6c31 -> 0x004b6c50` code tail jump after subtracting `0xa0` | compiler-generated secondary adjustor |
| adjustor `0x004b6c36` | one data xref `0x0061a69c -> 0x004b6c36` | `0x004b6c3c -> 0x004b6c50` code tail jump after subtracting `0xa4` | compiler-generated tertiary adjustor |
| scalar wrapper `0x004b6c50` | code xrefs `0x004b6c31`, `0x004b6c3c`; data xref `0x0061a620` | vptr stores `6c56 -> 61a620`, `6c5c -> 61a66c`, `6c66 -> 61a69c`; pointer clear `6c70 -> 69b334`; calls `6c7a Pane__Destructor`, `6c8b NexusTK_operator_delete_wrapper`, `6ca0 guard check` | compiler scalar deleting destructor |
| `0x0066da90` | four data xrefs: `0x004b64e5`, `0x004b65f5`, `0x004b69bd`, `0x004b6acd` | controller/start test and one-shot clears; stored value `1` | `g_fpsDebugActive` semantics |
| `0x0069b334` | three data xrefs: writes `0x004b6434`, `0x004b648a`, `0x004b6c70` | no reads in island; constructor publishes and two teardown paths clear | Singleton backing pointer |
| `0x0069b338` | four data xrefs: reads `0x004b653f`, `0x004b6645`, `0x004b6a17`, `0x004b6ae4` | each is byte truth-test; exhaustive writer/config/pointer search found none | loader-zero default-off bool |
| primary vtable `0x0061a620` | data xrefs from stores `0x004b643b`, `0x004b6470`, `0x004b6c56` | slot points to scalar wrapper | primary view lifecycle |
| secondary vtable `0x0061a66c` | data xrefs from stores `0x004b6441`, `0x004b6476`, `0x004b6c5c` | slot points to `0x004b6c2b` | EventHandler-adjusted view |
| tertiary vtable `0x0061a69c` | data xrefs from stores `0x004b644b`, `0x004b6480`, `0x004b6c66` | slots point to `0x004b6c36` and `0x004b68b0` | TimerHandler-adjusted view |
| literals L01-L15 | exact typed data xrefs are listed individually in the literal inventory; every narrow literal has one or two file-island refs | controller/helper duplicate pairs for L01-L14; OnPaint-only L15 | source expressions, not standalone data definitions |

Initialization/destruction closure is exact: raw constructor installs all three FpsPane views and publishes the singleton; ordinary destructor and scalar wrapper reinstall those views and clear the same singleton; scalar wrapper alone conditionally calls delete. No other constructor/destructor route, global writer, external direct caller, or pointer-table route was found.

## Documentation Evidence And IDA Status

- Historical pre-callback documentation correctly preserved most raw behavior, fields, literals, PE zero-fill proof, source ownership, and compiler-glue exclusions.
- Historical pre-callback defects were the constructor's `m_visible`, final method name `UpdateStatistics`, invented timer member, stale layer APIs, missing header, blank class emission, and empty physical pointer marker. C001-C025 corrected those ordinary documentation/source defects; manual coverage remains supervisor-owned under C047-C052.
- IDA has no FpsPane UDT. Modeled function names remain raw `sub_...`; `0x0066da90` remains named `dword_66DA90`; inspected item heads at `0x0069b334` and `0x0069b338` have blank item names, while the global name index separately reports `g_fpsLogEnabled` at `0x0069b338` and the latter head has type `bool`.
- Current generated command `27796` readback is implementation-complete for the accepted C001-C025 ordinary scope; Gate 2B, manual coverage, and lifecycle work remain outside that scope.

## Ranked Ownership Analysis

### 1. FpsPane diagnostics module

- Evidence for: complete contiguous method island, FpsPane RTTI/vtables, FpsPane-only fields/globals/literals, and the accepted current source tree.
- Evidence against: exact historical folder name is inferred rather than symbol-proven.
- Decision: accepted owner `NexusTK/ui/diagnostics/FpsPane.cpp` plus `FpsPane.h`.

### 2. ParcelPane

- Evidence for: stale imported/generated placement references.
- Evidence against: no parcel behavior or state; direct FPS class/global/string evidence contradicts it.
- Decision: reject as historical pollution.

### 3. MapPane/ObjectList/MainUiGraph

- Evidence for: diagnostic method reads map/object counts and an IME layer pointer.
- Evidence against: consumers do not own the FpsPane class, methods, layout, or globals.
- Decision: dependencies only.

### Proposed new file/grouping, if applicable

- No new source grouping. The callback added the formerly missing generated sibling header through existing formal H emitters.

## Source Placement

- CPP: `NexusTK/ui/diagnostics/FpsPane.cpp`.
- H: `NexusTK/ui/diagnostics/FpsPane.h`.
- Recommended source order: includes; Singleton specialization/global definitions; constructor; destructor; `UpdateFpsLogSession`; `OnPaint`; `OnTimer`; private start helper; private summary helper. Compiler wrappers/vtables/RTTI do not appear as handwritten source.
- `MapPane.h`, `ObjectList.h`, `MainUiGraph.h`, `List.h`, `StringBase.h`, `Pane.h`, `Singleton.h`, `<windows.h>`, `<mmsystem.h>`, and `<stdio.h>` provide the directly used declarations.
- Do not move the unit into `ParcelPane.cpp`, `MapPane.cpp`, `ObjectList.cpp`, or `MainUiGraph.cpp`.

## Range / Split / Padding / Reclassification Analysis

- Exact authored code and compiler-glue child ranges are already split correctly by UID00015C-00015L.
- UID00015D should remain a non-emitting split/index parent; emitting the aggregate would duplicate children.
- Six alignment gaps are exact `0xcc` padding and should remain ignored/no-source.
- Vtable/RTTI physical data is compiler-generated from class declarations. Literal bytes are represented by source literals. Physical global pages are covered by semantic definitions.
- Do not create narrow RTTI pages in this callback. R01-R12 are compiler-generated declaration consequences fully inventoried on UID00005F/UID0001XN/UID0002MJ; adding empty-source pages would not improve source reconstruction.
- Successor boundaries are strict: FrameHandler RTTI begins `0x00647b28`, and the next type descriptor begins `0x006762cc`.

## Negative Evidence Summary

- No direct caller/xref/pointer route proves the raw constructor, session controller, start helper, or summary helper currently execute via a conventional call edge.
- No original symbols prove exact field/helper/global lexemes or linkage.
- No FpsPane UDT exists in current IDA, so speculative full UDT/type mutations are unsafe.
- No code in the file island reads/writes `+0xfc`; assigning a semantic state role would overclaim.
- No writer/config/UI route was found for `g_fpsLogEnabled`; inventing one would change behavior.
- Neighboring ParcelPane metadata and consumer dependencies do not prove source ownership.
- These negatives cap scores but do not block formal reconstruction of behavior proven by complete bodies, RTTI, vtables, offsets, and source-context evidence.

## IDA Rename / Type / Comment Recommendations

All rows are supervisor-owned Gate 2B actions after Gate 1 and documentation callback verification. B009 performed only read-only inspection and validation-only pure rename dry runs. A dry run is proof of current schema/address/name acceptability, not permission to mutate.

### Literal prestate records

Comment notation `A-/AR-/F-/FR-` means address regular absent, address repeatable absent, function regular absent, and function repeatable absent. Every value below was read from the active exact session.

| Prestate | Item/name/type/frame | Boundary, leading bytes, typed inbound xrefs | Four-channel comments |
| --- | --- | --- | --- |
| P01 | raw code head `0x004b6410`, no function/name/type/frame | authored range `[4b6410,4b646b)`; `55 8b ec 51 56 8b f1 6a 01 89 75 fc e8 3f e0 08`; inbound total 0 | `A-/AR-`; function channels N/A |
| P02 | function `sub_4B6470`, size `0x29`, type `void __thiscall(_DWORD *this)`; frame only return address `0x0/4 _UNKNOWN*` | `[4b6470,4b6499)`; `c7 01 20 a6 61 00 c7 81 a0 00 00 00 6c a6 61 00`; inbound total 0 | `A-/AR-/F-/FR-` |
| P03 | raw code head `0x004b64a0`, no function/name/type/frame | `[4b64a0,4b67a7)`; `55 8b ec 83 ec 18 a1 24 2f 67 00 33 c5 89 45 fc`; inbound total 0 | `A-/AR-`; function channels N/A |
| P04 | function `sub_4B67B0`, size `0xfb`, type `void __thiscall(int this)`; frame `var_34 0/0xc __int16[6]`, `var_24 0x10/4`, `outBounds 0x14/0x10 RectBounds`, `var_10 0x24/4`, `var_C 0x28/4`, `var_4 0x30/4`, saved `0x34/4`, return `0x38/4`, `arg_4 0x40/4` | `[4b67b0,4b68ab)`; `55 8b ec 6a ff 68 d8 f0 5f 00 64 a1 00 00 00 00`; data xref `61a664 -> 4b67b0` | `A-/AR-/F-/FR-` |
| P05 | function `sub_4B68B0`, size `0x100`, type `char __thiscall(int this,int,int,int)`; frame `visibleBounds 0x4/0x10 MapRect`, `var_4 0x14/4`, saved `0x18/4`, return `0x1c/4` | `[4b68b0,4b69b0)`; `55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc`; data xref `61a6a0 -> 4b68b0` | `A-/AR-/F-/FR-` |
| P06 | raw code head `0x004b69b0`, no function/name/type/frame | `[4b69b0,4b6adc)`; `55 8b ec 51 57 8b f9 ff 15 0c d5 60 00 83 3d 90`; inbound total 0 | `A-/AR-`; function channels N/A |
| P07 | raw code head `0x004b6ae0`, no function/name/type/frame | `[4b6ae0,4b6c2b)`; `55 8b ec 51 80 3d 38 b3 69 00 00 56 8b f1 0f 84`; inbound total 0 | `A-/AR-`; function channels N/A |
| P08 | function `sub_4B6C2B`, size `0x0b`, type `_DWORD *__thiscall(_DWORD *this,char)`; frame only return `0x0/4` | `[4b6c2b,4b6c36)`; full bytes `81 e9 a0 00 00 00 e9 1a 00 00 00`; data xref `61a66c`, tail xref to scalar | `A-/AR-/F-/FR-` |
| P09 | function `sub_4B6C36`, size `0x0b`, same type/frame as P08 | `[4b6c36,4b6c41)`; full bytes `81 e9 a4 00 00 00 e9 0f 00 00 00`; data xref `61a69c`, tail xref to scalar | `A-/AR-/F-/FR-` |
| P10 | function `sub_4B6C50`, size `0x5f`, type `_DWORD *__thiscall(_DWORD *Block,char)`; frame saved `0x4/4`, return `0x8/4`, `arg_0 0xc/4` | `[4b6c50,4b6caf)`; `55 8b ec 56 8b f1 c7 06 20 a6 61 00 c7 86 a0 00`; code xrefs `4b6c31/4b6c3c`, data xref `61a620` | `A-/AR-/F-/FR-` |
| P11 | data head `[66da90,66da94)`, name `dword_66DA90`, type blank, 4-byte data | bytes `01 00 00 00`; data xrefs `4b64e5/4b65f5/4b69bd/4b6acd` | `A-/AR-`; function channels N/A |
| P12 | physical `[69b334,69b338)`, current inspected head `[69b334,69b335)`, name/type blank, undefined/non-data | bytes `00 00 00 00`; data xrefs `4b6434/4b648a/4b6c70` | `A-/AR-`; function channels N/A |
| P13 | head `[69b338,69b339)`, item name blank, type `bool`, undefined/non-data; name index separately returns `g_fpsLogEnabled` | byte `00`; data xrefs `4b653f/4b6645/4b6a17/4b6ae4`; successor padding starts `69b339` | `A-/AR-`; function channels N/A |

### Atomic persistent-effect rows

The exact public request shown is the future stateful request. `DB` means the exact supervisor-opened transaction session returned at Gate 2B, not this report's read-only session. Each row is one persistent effect.

| Action | Prestate | One persistent effect / exact public MCP request | Dry-run or precheck and immediate current poststate | Expected stateful poststate / hard stop |
| --- | --- | --- | --- | --- |
| A01 | P02 | `rename({database:DB,batch:{func:{addr:"0x4b6470",name:"FpsPane__Destructor"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | one-item dry run `ok 1/1`; immediate lookup still `sub_4B6470`; desired name absent | exact new name only; size/type/frame/comments/xrefs unchanged; stop on collision/delta |
| A02 | P04 | `rename({database:DB,batch:{func:{addr:"0x4b67b0",name:"FpsPane__OnPaint"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | dry run `ok 1/1`; raw name retained; desired absent | exact new name only; preserve all P04 state |
| A03 | P05 | `rename({database:DB,batch:{func:{addr:"0x4b68b0",name:"FpsPane__OnTimer"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | dry run `ok 1/1`; raw name retained; desired absent | exact new name only; preserve all P05 state |
| A04 | P08 | `rename({database:DB,batch:{func:{addr:"0x4b6c2b",name:"FpsPane__ScalarDeletingDestructorAdjustorA0"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | dry run `ok 1/1`; raw name retained; desired absent | exact new name only; preserve thunk bytes/type/frame/xrefs |
| A05 | P09 | `rename({database:DB,batch:{func:{addr:"0x4b6c36",name:"FpsPane__ScalarDeletingDestructorAdjustorA4"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | dry run `ok 1/1`; raw name retained; desired absent | exact new name only; preserve thunk bytes/type/frame/xrefs |
| A06 | P10 | `rename({database:DB,batch:{func:{addr:"0x4b6c50",name:"FpsPane__ScalarDeletingDestructor"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | dry run `ok 1/1`; raw name retained; desired absent | exact new name only; preserve wrapper type/frame/xrefs |
| A07 | P11 | `rename({database:DB,batch:{data:{old:"dword_66DA90",new:"g_fpsDebugActive"},dry_run:false,pure:true,allow_overwrite:false,stop_on_error:true}})` | one-item dry run `ok 1/1`; item still `dword_66DA90`; desired absent | exact new name, same head/width/type/value/xrefs; stop on any mismatch |
| A08 | P11 after A07 | `set_type({database:DB,edits:{addr:"0x0066da90",kind:"global",ty:"int"}})` | endpoint has no dry-run field; no call made; current type remains blank | type exactly `int`, head/end/value/xrefs/name unchanged; stop if item reshapes |
| A09 | P02 after A01 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b6470",comment:"Ordinary FpsPane destructor body; Singleton<FpsPane> clear and vptr/base teardown are compiler/base lifecycle effects."}})` | no dry-run schema; current AR remains absent | exact AR text; A/F/FR and all noncomment state unchanged |
| A10 | P04 after A02 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b67b0",comment:"FpsPane::OnPaint primary virtual; increments the frame counter and draws the two-pass FPS overlay."}})` | no dry-run; AR absent | exact AR text only; preserve P04 frame/type/bounds/xref |
| A11 | P05 after A03 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b68b0",comment:"TimerHandler-adjusted FpsPane::OnTimer(int,int,int); samples FPS/object totals and schedules timer 0 after 1000 ms."}})` | no dry-run; AR absent | exact AR text only; preserve P05 frame/type/bounds/xref |
| A12 | P08 after A04 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b6c2b",comment:"Compiler-generated FpsPane deleting-destructor adjustor for the secondary +0xa0 view."}})` | no dry-run; AR absent | exact AR text only; preserve thunk state |
| A13 | P09 after A05 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b6c36",comment:"Compiler-generated FpsPane deleting-destructor adjustor for the TimerHandler +0xa4 view."}})` | no dry-run; AR absent | exact AR text only; preserve thunk state |
| A14 | P10 after A06 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b6c50",comment:"Compiler-generated FpsPane scalar deleting destructor; handwritten source is virtual ~FpsPane()."}})` | no dry-run; AR absent | exact AR text only; preserve wrapper state |
| A15 | P11 after A07/A08 | `set_address_repeatable_comments({database:DB,items:{addr:"0x0066da90",comment:"FpsPane diagnostics one-shot activation flag, explicitly initialized to 1."}})` | no dry-run; AR absent | exact AR text only; preserve 4-byte int/value/xrefs |
| A16 | P12 | `set_address_repeatable_comments({database:DB,items:{addr:"0x0069b334",comment:"Four-byte Singleton<FpsPane> backing pointer storage at 0x0069b334; source definition is g_pFpsPane."}})` | no dry-run; AR absent | exact AR text only; item heads/name/type/bytes/xrefs unchanged |
| A17 | P13 | `set_address_repeatable_comments({database:DB,items:{addr:"0x0069b338",comment:"Loader-zeroed one-byte FpsPane logging gate; four read-only truth tests and no writer or configuration route."}})` | no dry-run; AR absent | exact AR text only; bool head/name-index/boundary/xrefs unchanged |
| A18 | P01 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b6410",comment:"Raw FpsPane constructor body [0x004b6410,0x004b646b); installs three views and performs Pane/Singleton initialization."}})` | no dry-run; AR absent | exact AR text; remains nonfunction with same bytes/bounds |
| A19 | P03 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b64a0",comment:"Raw FpsPane::UpdateFpsLogSession body [0x004b64a0,0x004b67a7); complete retained method with no current inbound route."}})` | no dry-run; AR absent | exact AR text; remains nonfunction with same bytes/bounds |
| A20 | P06 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b69b0",comment:"Raw retained FpsPane::StartLogSession body [0x004b69b0,0x004b6adc); complete helper with no current inbound route."}})` | no dry-run; AR absent | exact AR text; remains nonfunction with same bytes/bounds |
| A21 | P07 | `set_address_repeatable_comments({database:DB,items:{addr:"0x004b6ae0",comment:"Raw retained FpsPane::WriteLogSummary body [0x004b6ae0,0x004b6c2b); complete helper with no current inbound route."}})` | no dry-run; AR absent | exact AR text; remains nonfunction with same bytes/bounds |

### Separate read-only protections

| Protection | Exact protected state |
| --- | --- |
| T01 | P02 type/frame/bounds/bytes/xrefs and A/F/FR channels; no `set_type`, stack rename, function resize, or function comment. |
| T02 | P04 complete nine-row frame/type/bounds/bytes/xref and A/F/FR channels unchanged. |
| T03 | P05 complete four-row frame/type/bounds/bytes/xref and A/F/FR channels unchanged. |
| T04 | P08 type/single return row/full 11 bytes/vtable xref/tail jump unchanged. |
| T05 | P09 type/single return row/full 11 bytes/vtable xref/tail jump unchanged. |
| T06 | P10 type/three-row frame/bounds/bytes/three inbound xrefs unchanged. |
| T07 | P01 remains a nonfunction; do not create/delete/resize/name/type code. |
| T08 | P03 remains a nonfunction; do not create/delete/resize/name/type code. |
| T09 | P06 remains a nonfunction; do not create/delete/resize/name/type code. |
| T10 | P07 remains a nonfunction; do not create/delete/resize/name/type code. |
| T11 | P12 receives no rename, `make_data`, type, width, or head shaping; current `rename.batch.data` cannot target an unnamed old item. |
| T12 | P13 receives no rename, `make_data`, type, width, or head shaping; preserve the current name-index/item-name discrepancy and one-byte bool. |
| T13 | P11 remains exactly four bytes with value 1 and four xrefs; A08 may add only the `int` type. |
| T14 | Gap `[4b646b,4b6470)` remains five `cc` bytes and no function/data item is created. |
| T15 | Gap `[4b6499,4b64a0)` remains seven `cc` bytes. |
| T16 | Gap `[4b67a7,4b67b0)` remains nine `cc` bytes. |
| T17 | Gap `[4b68ab,4b68b0)` remains five `cc` bytes. |
| T18 | Gap `[4b6adc,4b6ae0)` remains four `cc` bytes. |
| T19 | Gap `[4b6c41,4b6c50)` remains fifteen `cc` bytes; trailing `[4b6caf,4b6cb0)` remains one `cc` byte. |
| T20 | Preserve regular comment `signature` at `0x00647a50`; no RTTI rename/type/comment replacement. |
| T21 | Preserve regular comment `reference to RTTI's vftable` at `0x0067628c`; no RTTI rename/type/comment replacement. |
| T22 | Preserve V01-V34 and R01-R12 byte/item/xref boundaries; no vtable/RTTI array shaping or handwritten-data mutation. |

Gate 2B stop/rollback rule: before each action the supervisor must re-attest the exact transaction session/path, reread the referenced prestate, and repeat the exact collision check. Apply and read back one action at a time. Any schema error, collision, stale prestate, unexpected type/frame/head/boundary/xref/comment delta, or failed exact readback stops the remaining rows. Do not save or replace the canonical IDB after such a failure; discard/rollback the supervisor transaction using the current supervisor procedure and verify the canonical physical hash remains unchanged. Only the supervisor may perform persistence, backup, save, replacement, and rollback.

## First-Draft C++ Recommendation

Formal H insertion for [UID:00005F] `by-class/FpsPane.md`:

```cpp
#ifndef NEXUSTK_UI_DIAGNOSTICS_FPSPANE_H
#define NEXUSTK_UI_DIAGNOSTICS_FPSPANE_H

#include <windows.h>

#include "../core/Pane.h"
#include "../../util/Singleton.h"

class FpsPane : public Pane, public Singleton<FpsPane>
{
public:
    FpsPane();
    virtual ~FpsPane();

    void UpdateFpsLogSession(bool startNew);

protected:
    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void StartLogSession();
    void WriteLogSummary();

    int m_frameCount;
    unsigned int m_reservedFrameState;
    float m_currentFps;
    char m_logFileName[50];
    SYSTEMTIME m_logStartTime;
    DWORD m_logStartTick;
    float m_minFps;
    float m_maxFps;
    unsigned int m_sampleCount;
    double m_totalFps;
    unsigned int m_totalLivingObjects;
    unsigned int m_totalBalloonObjects;
    unsigned int m_totalStaticObjects;
};

extern int g_fpsDebugActive;
extern bool g_fpsLogEnabled;
extern FpsPane *g_pFpsPane;

typedef char FpsPaneSizeMustBe0x170[(sizeof(FpsPane) == 0x170) ? 1 : -1];

#endif
```

Formal class-level CPP insertion for [UID:00005F]:

```cpp
#include "FpsPane.h"

#include "../../map/MapPane.h"
#include "../../map/ObjectList.h"
#include "../../util/List.h"
#include "../../util/StringBase.h"
#include "../MainUiGraph.h"

#include <mmsystem.h>
#include <stdio.h>

template <>
Singleton<FpsPane>::Singleton()
{
    g_pFpsPane = static_cast<FpsPane *>(this);
}

template <>
Singleton<FpsPane>::~Singleton()
{
    g_pFpsPane = 0;
}

[[CHILDREN]]
```

Formal replacement for [UID:00015C]:

```cpp
FpsPane::FpsPane()
    : Pane(1),
      m_currentFps(0.0f)
{
    m_hasPendingMotionRegion = true;
}
```

`m_frameCount` and `m_reservedFrameState` are intentionally absent from the initializer list because current raw constructor bytes do not write `+0xf8` or `+0xfc`. Adding cosmetic initialization would violate byte-equivalent behavior; `UpdateFpsLogSession` initializes the frame counter when a session starts.

Formal replacement for [UID:00015E]:

```cpp
FpsPane::~FpsPane()
{
}
```

Formal replacement for [UID:00015F]:

```cpp
void FpsPane::UpdateFpsLogSession(bool startNew)
{
    RectBounds bounds;
    bounds.SetLTRB(10, 10, 490, 22);

    if (startNew && !IsAttachedToLayer()) {
        StartLogSession();
        AddToLayer(&bounds, 0, 0, g_pIMEPaneLayer);
        m_frameCount = 0;
        ScheduleTimer(0, 1000, 0, 0);
        return;
    }

    WriteLogSummary();
    RemoveFromLayer();
    RemovePendingTimers();
}
```

Exact formal CPP payload for [UID:00015G]:

```cpp
void FpsPane::OnPaint()
{
    ++m_frameCount;

    mystr::StringBase<wchar_t> fpsText(L"%5.1f FPS",
                                       static_cast<double>(m_currentFps));

    RectBounds bounds;
    GetBounds(&bounds);

    SetDrawColor(0);
    FillRect(&bounds);

    SetTextColor(128);
    MoveTo(1, 13);
    DrawWideText(fpsText.c_str(), fpsText.length());

    SetTextColor(14);
    MoveTo(0, 12);
    DrawWideText(fpsText.c_str(), fpsText.length());
}
```

Formal replacement for [UID:00015H], with page/title/source-facing identity changed to `FpsPaneOnTimer`:

```cpp
bool FpsPane::OnTimer(int, int, int)
{
    const float fps = static_cast<float>(m_frameCount);
    m_frameCount = 0;
    m_currentFps = fps;

    if (fps < m_minFps)
        m_minFps = fps;

    if (m_maxFps < fps)
        m_maxFps = fps;

    ++m_sampleCount;
    m_totalFps += fps;

    if (g_activeMapPane != 0) {
        MapRect visibleTiles;
        g_activeMapPane->GetClampedVisibleTileBounds(&visibleTiles);

        ObjectList *objectList = g_activeMapPane->m_objectList;
        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row) {
            m_totalLivingObjects += objectList->GetFrontRowBucket(row)->GetCount();
            m_totalStaticObjects += objectList->GetBackRowBucket(row)->GetCount();
        }

        m_totalBalloonObjects += objectList->GetVisibleObjectList()->GetCount();
    }

    ScheduleTimer(0, 1000, 0, 0);
    return true;
}
```

Exact formal CPP payload for [UID:00015I]:

```cpp
void FpsPane::StartLogSession()
{
    m_logStartTick = timeGetTime();
    m_minFps = 300.0f;
    m_maxFps = 0.0f;
    m_sampleCount = 1;
    m_totalFps = 0.0;
    m_totalLivingObjects = 0;
    m_totalBalloonObjects = 0;
    m_totalStaticObjects = 0;

    if (g_fpsDebugActive != 0) {
        if (g_fpsLogEnabled) {
            FILE *file;

            GetLocalTime(&m_logStartTime);
            sprintf_s(m_logFileName, sizeof(m_logFileName),
                      "FPSDATA-%d-%d-%d-%d-%d.txt",
                      m_logStartTime.wMonth,
                      m_logStartTime.wDay,
                      m_logStartTime.wHour,
                      m_logStartTime.wMinute,
                      m_logStartTime.wSecond);

            fopen_s(&file, m_logFileName, "w");
            fprintf(file, "***NEW_CLIENT***\n");
            fprintf(file,
                    "\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xC0\xDB %d\xBF\xF9 %d\xC0\xCF %d\xBD\xC3 %d\xBA\xD0 %d\xC3\xCA\n\n\n",
                    m_logStartTime.wMonth,
                    m_logStartTime.wDay,
                    m_logStartTime.wHour,
                    m_logStartTime.wMinute,
                    m_logStartTime.wSecond);
            fclose(file);
        }

        g_fpsDebugActive = 0;
    }
}
```

Exact formal CPP payload for [UID:00015J]:

```cpp
void FpsPane::WriteLogSummary()
{
    if (!g_fpsLogEnabled) {
        return;
    }

    FILE *file;
    fopen_s(&file, m_logFileName, "a");

    fprintf(file, "------------------------\n");
    fprintf(file,
            "\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xB0\xA3 : %dsec\n",
            (timeGetTime() - m_logStartTick) / 1000);
    fprintf(file, "minFPS : %5.1f\n", (double)m_minFps);
    fprintf(file, "maxFPS : %5.1f\n", (double)m_maxFps);
    fprintf(file, "aveFPS : %5.1f\n", m_totalFps / (double)m_sampleCount);
    fprintf(file, "aveLivingObject  : %d\n", m_totalLivingObjects / m_sampleCount);
    fprintf(file, "aveBalloonObject : %d\n", m_totalBalloonObjects / m_sampleCount);
    fprintf(file, "aveStaticObject  : %d\n", m_totalStaticObjects / m_sampleCount);
    fprintf(file, "------------------------\n\n");

    fclose(file);
}
```

Exact formal CPP/no-code payloads for the remaining routed children:

| UID / path | Exact CPP payload or no-code proof | Exact H payload/disposition |
| --- | --- | --- |
| 00015D aggregate | blank: non-emitting split/index; K01-K16 are children | blank |
| 00015K adjustors | blank: both bodies are compiler-generated this-adjustor tail jumps | blank |
| 00015L scalar | `// Compiler-generated scalar deleting destructor for FpsPane; source is FpsPane::~FpsPane().` | blank |
| 0001UO layout | `// FpsPane layout is emitted by UID00005F FpsPane class declaration; this support page emits no duplicate type.` | blank; exact declaration is owned by UID00005F H |
| 0001XN vtable | `// FpsPane vtables and RTTI are compiler-generated from the UID00005F class declaration; no raw table is handwritten.` | blank |
| 0002MJ vtable data | `// Exact FpsPane vtable bytes [0x0061a61c,0x0061a6a4) are compiler-generated from UID00005F; this page emits no raw array.` | blank |
| 0003BJ literals | `// Exact diagnostic literals [0x0061a6a4,0x0061a7dc) are embedded by the FpsPane method expressions; this page emits no duplicate array.` | blank |
| 00025E readonly parent | blank: false/non-emitting index over 0002MJ and 0003BJ | blank |

Exact semantic-global and physical-child formal payloads:

```cpp
// UID0000PY
int g_fpsDebugActive = 1;

// UID00027E
// Exact four-byte storage is emitted by UID0000PY g_fpsDebugActive; this by-memory child records bytes/xrefs only and emits no duplicate definition.

// UID0000PZ
bool g_fpsLogEnabled;

// UID0002W1
// Exact one-byte storage is emitted by UID0000PZ g_fpsLogEnabled; this by-memory child records bytes/xrefs only and emits no duplicate definition.

// UID0000QZ
FpsPane *g_pFpsPane = 0;

// UID0002W0
// Exact four-byte storage is emitted by UID0000QZ g_pFpsPane; this by-memory child records bytes/xrefs only and emits no duplicate definition.
```

UID0000PY/0000PZ/0000QZ H blocks remain blank because the three exact `extern` declarations are centralized in UID00005F's formal H payload above. Physical children also keep blank H blocks. This avoids duplicate declarations while ensuring every method compiles before the later-positioned definitions.

Exact support H payload for [UID:0004VG] `by-global/g_pIMEPaneLayer.md`:

```cpp
class Layer;

extern Layer *g_pIMEPaneLayer;
```

Its existing formal CPP remains exactly:

```cpp
class Layer;

Layer *g_pIMEPaneLayer = 0;
```

The class specialization publishes and clears the single UID0000QZ cell; it does not define separate template storage. This follows the accepted current `Singleton.h`/`ConnStatusPane` project pattern.

Formal channel closure for all 19 routed generated children:

| UID | CPP channel | H channel |
| --- | --- | --- |
| 00005F | exact include/Singleton-specialization/`[[CHILDREN]]` block reproduced above | exact complete class/header block reproduced above |
| 00015C | exact constructor block above | blank; declaration is in 00005F H |
| 00015E | exact destructor block above | blank; declaration is in 00005F H |
| 00015F | exact controller block above | blank; declaration is in 00005F H |
| 00015G | exact OnPaint block above | blank; declaration is in 00005F H |
| 00015H | exact OnTimer block above | blank; declaration is in 00005F H |
| 00015I | exact StartLogSession block above | blank; declaration is in 00005F H |
| 00015J | exact WriteLogSummary block above | blank; declaration is in 00005F H |
| 00015L | exact scalar-wrapper covered comment above | blank; destructor declaration is in 00005F H |
| 0000PY | exact int definition above | blank; extern is in 00005F H |
| 0000PZ | exact bool definition above | blank; extern is in 00005F H |
| 0000QZ | exact pointer definition above | blank; extern is in 00005F H |
| 00027E | exact physical-storage covered comment above | blank |
| 0002W1 | exact physical-storage covered comment above | blank |
| 0002W0 | exact physical-storage covered comment above | blank |
| 0001UO | exact class-covered layout comment above | blank; full declaration is in 00005F H |
| 0001XN | exact compiler-covered vtable comment above | blank |
| 0002MJ | exact compiler-covered physical-vtable comment above | blank |
| 0003BJ | exact source-literal covered comment above | blank |

The code preserves observed runtime behavior and uses plausible early/mid-2000s C++ source shape. It deliberately retains unchecked file-open/use behavior, integer division, timer cadence, and CP949 byte literals rather than modernizing them.

## Final Recommendation

- Accept UID0000JK as the complete FpsPane compilation unit.
- The accepted callback populated the class H/CPP channels, corrected constructor/session/timer source, and preserved exact authored helper bodies.
- UID00015H now uses source identity `OnTimer` while retaining its UID/range/history and historical filename slug.
- UID0002W0 now uses a covered-by disposition instead of an empty physical singleton-pointer emitter.
- UID0004VG now supplies the missing `g_pIMEPaneLayer` header declaration through its owning support page.
- Preserve compiler-generated and physical-data children without handwritten arrays/wrappers.
- Apply only the safe IDA rename/comment/type subset in the structured handoff after supervisor acceptance.
- Do not invent a `+0xfc` semantic role, logging setter, static linkage, or raw function boundaries.

## Recommended Target Doc Changes

- C001 applied the direct-base/Singleton result, corrected Pane/TimerHandler API map, generated-output defect audit, complete header requirement, source order, exact RTTI ranges, and resolved no-route treatment to `by-file/FpsPane.md`; current metadata is `94/96` with owner/path retained.
- C008 replaced final source identity `UpdateStatistics` with `OnTimer` while preserving `UpdateStatistics` as a historical/descriptive filename alias.
- C003/C006/C008 replaced stale generated-source claims for constructor/session/timer APIs.
- C001-C025 preserved prior PE zero-fill, literals, helper liveness, ownership rejection, and historical-placement evidence additively.

## Recommended Support Doc Changes

The table below records the applied support-document callback results. C002-C025 have been applied and freshly hashed in `Changed Files`; every row is current completed ordinary state, not pending work.

| UID | Exact path | Exact callback change |
| --- | --- | --- |
| 00005F | `by-class/FpsPane.md` | C002 applied the exact class CPP/H payloads; current `94/96`; owner/emitter 0000JK and true reconstruction preserved. |
| 00015C | `by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md` | C003 applied exact constructor/evidence; current `93/95`; owner/emitter 00005F preserved. |
| 00015D | `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` | C004 applied the complete split/gap inventory; current `92/95`; owner 0000JK, false reconstruction, and blank emitter/CPP/H preserved. |
| 00015E | `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` | C005 applied exact empty-destructor/lifecycle evidence; current `93/95`; owner/emitter 00005F preserved. |
| 00015F | `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` | C006 applied exact controller CPP and 27-call map; current `94/95`; owner/emitter 00005F preserved. |
| 00015G | `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md` | C007 applied exact CPP/frame/xref/header route; current `93/95`; owner/emitter 00005F preserved. |
| 00015H | `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` | C008 applied source-facing `FpsPaneOnTimer` identity and exact CPP while preserving the old title historically; current `94/96`; owner/emitter 00005F preserved. |
| 00015I | `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` | C009 applied exact CPP and no-route evidence; current `92/94`; owner/emitter 00005F preserved. |
| 00015J | `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` | C010 applied exact CPP and no-route evidence; current `92/94`; owner/emitter 00005F preserved. |
| 00015K | `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md` | C011 applied two-thunk compiler proof; current `90/96`; NONE/FALSE/blank emitter/CPP/H preserved. |
| 00015L | `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` | C012 applied exact compiler-covered comment/evidence; current `91/96`; owner/emitter 00005F preserved. |
| 0001UO | `by-type/by-struct/FpsPaneLayout.md` | C013 applied normalized direct bases/offsets/types/size and exact class-covered CPP comment; current `94/96`; owner/emitter 00005F preserved. |
| 0001XN | `by-type/by-vtable/FpsPane_vtables.md` | C014 applied V01-V34/R01-R12, corrected OnTimer slot, and exact CPP comment; current `93/96`; owner/emitter 00005F preserved. |
| 0002MJ | `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md` | C015 applied the full 34-dword inventory/lifecycle stores/bounds and exact CPP comment; current `93/96`; owner/emitter 00005F preserved. |
| 0003BJ | `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md` | C016 applied L01-L15, Item Summary, strict boundaries, and exact CPP comment; current `93/96`; owner/emitter 0000JK preserved. |
| 00025E | `by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md` | C017 applied the complete two-child index and boundaries; current `90/95`; NONE/FALSE/blank emitter/CPP/H preserved. |
| 0000PY | `by-global/g_fpsDebugActive.md` | C018 applied exact definition/evidence; current `92/94`; owner/emitter 0000JK and blank H with centralized-declaration reason preserved. |
| 00027E | `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` | C019 applied exact covered CPP comment/evidence; current `92/95`; owner/emitter 0000JK preserved. |
| 0000PZ | `by-global/g_fpsLogEnabled.md` | C020 applied exact definition/zero-fill/no-writer evidence; current `94/96`; owner/emitter 0000JK and blank H with centralized-declaration reason preserved. |
| 0002W1 | `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` | C021 applied exact covered CPP comment/head/boundary; current `94/96`; owner/emitter 0000JK preserved. |
| 0000QZ | `by-global/g_pFpsPane.md` | C022 applied exact zero-initialized definition/Singleton route; current `94/96`; owner/emitter 0000JK and blank H with centralized-declaration reason preserved. |
| 0002W0 | `by-memory/0x0069b334-0x0069b338.g_pFpsPane.md` | C023 applied exact covered CPP comment/head/xrefs and removed the empty marker; current `94/96`; owner/emitter 0000JK preserved. |
| 0004VG | `by-global/g_pIMEPaneLayer.md` | C024 applied the exact H declaration; current `92/94`, owner/emitter 0000L1, position 60, and CPP definition retained. |
| 0000L1 | `by-file/MainUiGraph.md` | C025 applied header ownership/generated expectation; current `90/92` and FILE state retained. |

No new RTTI child page is required. Preserve R01-R12 at full detail in the existing class/vtable/vtable-data support pages. No generated registry/catalog file may be edited manually.

## Score And Metadata Recommendation

| UID | Historical pre-callback -> accepted current | Canonical owner | Reconstructable | Emitter / position | Exact formal CPP/H disposition |
| --- | --- | --- | --- | --- | --- |
| 0000JK | `89/90 -> 94/96` | `FILE` | field N/A on by-file | child routing | path `NexusTK/ui/diagnostics/` retained; no root formal channels |
| 00005F | `87/88 -> 94/96` | `0000JK` | `TRUE` | `0000JK` / blank | exact class CPP/H payloads applied |
| 00015C | `86/90 -> 93/95` | `00005F` | `TRUE` | `00005F` / blank | exact constructor CPP; H blank |
| 00015D | `88/91 -> 92/95` | `0000JK` | `FALSE` | blank | CPP/H blank non-emitting index |
| 00015E | `88/91 -> 93/95` | `00005F` | `TRUE` | `00005F` / blank | exact empty destructor CPP; H blank |
| 00015F | `89/89 -> 94/95` | `00005F` | `TRUE` | `00005F` / blank | exact corrected controller CPP; H blank |
| 00015G | `88/91 -> 93/95` | `00005F` | `TRUE` | `00005F` / blank | exact OnPaint CPP; H blank |
| 00015H | `88/91 -> 94/96` | `00005F` | `TRUE` | `00005F` / blank | exact OnTimer CPP and source-facing identity; H blank |
| 00015I | `88/89 -> 92/94` | `00005F` | `TRUE` | `00005F` / blank | exact StartLogSession CPP; H blank |
| 00015J | `88/89 -> 92/94` | `00005F` | `TRUE` | `00005F` / blank | exact WriteLogSummary CPP; H blank |
| 00015K | `86/90 -> 90/96` | `NONE` | `FALSE` | blank | CPP/H blank compiler adjustors |
| 00015L | `86/91 -> 91/96` | `00005F` | `TRUE` | `00005F` / blank | exact compiler-covered CPP comment; H blank |
| 0001UO | `88/90 -> 94/96` | `00005F` | `TRUE` | `00005F` / blank | exact class-covered CPP comment; H blank/declaration owned by 00005F |
| 0001XN | `85/90 -> 93/96` | `00005F` | `TRUE` | `00005F` / blank | exact compiler-covered CPP comment; H blank |
| 0002MJ | `87/92 -> 93/96` | `00005F` | `TRUE` | `00005F` / blank | exact compiler-covered CPP comment; H blank |
| 0003BJ | `89/92 -> 93/96` | `0000JK` | `TRUE` | `0000JK` / blank | exact source-literal CPP comment; H blank |
| 00025E | `86/92 -> 90/95` | `NONE` | `FALSE` | blank | CPP/H blank non-emitting index |
| 0000PY | `88/89 -> 92/94` | `0000JK` | `TRUE` | `0000JK` / blank | exact int definition; H blank/declaration centralized in 00005F |
| 00027E | `88/90 -> 92/95` | `0000JK` | `TRUE` | `0000JK` / blank | exact physical covered CPP comment; H blank |
| 0000PZ | `92/93 -> 94/96` | `0000JK` | `TRUE` | `0000JK` / blank | exact bool definition; H blank/declaration centralized in 00005F |
| 0002W1 | `92/94 -> 94/96` | `0000JK` | `TRUE` | `0000JK` / blank | exact physical covered CPP comment; H blank |
| 0000QZ | `87/90 -> 94/96` | `0000JK` | `TRUE` | `0000JK` / blank | exact zero-initialized pointer definition; H blank/declaration centralized in 00005F |
| 0002W0 | `88/91 -> 94/96` | `0000JK` | `TRUE` | `0000JK` / blank | exact physical covered comment applied; H blank |
| 0004VG | `92/94 -> 92/94` | `0000L1` | `TRUE` | `0000L1` / `60` | CPP definition retained; exact H declaration applied |
| 0000L1 | `90/92 -> 90/92` | `FILE` | field N/A on by-file | child routing | UID0004VG H ownership recorded; no root formal channels |

Reason not higher: no original symbols/linkage, no stable FpsPane UDT, no raw-start call/pointer routes, historical inlining cannot be proven, and `+0xfc` has no behavioral use. Reason not lower: exact inheritance, object size, offsets, method bodies, virtual identities, callee APIs, globals, strings, and range boundaries are independently corroborated. Accepted scores remain conservative after callback source/readback and generated H/CPP verification.

## Open Questions With Attempted Resolution

- **Raw-start liveness:** exhaustive direct xref, code/data/immediate, VA, RVA, and raw-offset pointer checks found no route. Resolution: retain exact source-shaped methods with explicit no-route history; do not claim live reachability.
- **Original names:** no symbols survive. Resolution: use coherent FpsPane/Pane/TimerHandler names supported by roles and project conventions; never emit `sub_`, `dword_`, `unk_`, or offset labels.
- **`+0xfc`:** all file-owned code and related docs were searched; no user exists. Resolution: reserve the exact four-byte slot as `m_reservedFrameState` with no semantic claim. Do not initialize it unless exact constructor bytes prove a write.
- **Global linkage:** local usage does not prove `static`. Resolution: retain established external one-definition forms.
- **Singleton/global duplication:** current `Singleton.h` has only protected constructor/destructor declarations and no `m_instance` member; accepted ConnStatusPane source uses explicit specializations that write the independently defined global. Resolution: emit exactly one `FpsPane *g_pFpsPane = 0;` definition and have the two specializations publish/clear that cell. Do not invent template storage or a second pointer.
- **Historical helper factoring:** active controller duplicates helper behavior. Resolution: retain private helper source as the most plausible original factoring while acknowledging compiler/linker retention uncertainty.
- **Exact historical folder:** source symbols do not prove `ui/diagnostics`, but current source tree and subsystem cohesion strongly support it. Resolution: keep current path.
- No question remains as generic future investigation; remaining uncertainty is explicitly bounded and scored.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- `by-file/-coverage-report.md`: replace UID0000JK's row with:

```markdown
- [UID:0000JK][FpsPane](by-file/FpsPane.md) : reconstructable : 94% : very-strong : Complete NexusTK/ui/diagnostics/FpsPane.cpp/.h unit with direct Pane plus Singleton<FpsPane> inheritance, exact 0x170 layout, seven authored bodies, corrected layer and inherited TimerHandler APIs, OnPaint/OnTimer virtual identities, three one-definition globals, retained no-route helper evidence, complete generated CPP/H routing, and compiler-covered vtable/RTTI/thunk/string/physical-data children.
```

- `by-class/-coverage-report.md`: replace UID00005F's stale `84%` row with:

```markdown
- [UID:00005F][FpsPane](by-class/FpsPane.md) : reconstructable : 94% : very-strong : Complete FpsPane declaration with direct Pane plus Singleton<FpsPane> inheritance, exact 0x170 layout, explicit Singleton publication/clear specializations, OnPaint and TimerHandler OnTimer overrides, complete fields and private logging helpers, required generated FpsPane.h, and compiler-covered deleting wrappers/vtables/RTTI.
```

- `by-type/by-struct/-coverage-report.md`: replace UID0001UO's row with:

```markdown
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) : reconstructable : 94% : very-strong : Exact 0x170 FpsPane layout with 0xf8 Pane base, Singleton<FpsPane> EBO, signed frame counter, reserved unreferenced +0xfc slot, current/logging fields through +0x168, exact counter signedness, natural padding, complete class-H declaration ownership, and no invented embedded timer member.
```

- `by-type/by-vtable/-coverage-report.md`: replace UID0001XN's row with:

```markdown
- [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md) : reconstructable : 93% : very-strong : Exact primary, EventHandler-adjusted, and TimerHandler-adjusted FpsPane vtable views with virtual destructor, OnPaint, corrected OnTimer identity, deleting adjustors, lifecycle stores, direct Pane plus Singleton RTTI, strict FPSDATA successor boundary, and declaration-covered compiler-data emission.
```

- `by-global/-coverage-report.md`: replace the three FpsPane rows with:

```markdown
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) : reconstructable : 92% : very-strong : FpsPane diagnostic-session one-shot int with explicit initializer 1, four exact FpsPane uses, source definition in FpsPane.cpp, and UID00027E covered physical storage.
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) : reconstructable : 94% : very-strong : Loader-zeroed one-byte FpsPane logging bool with four read-only truth tests, exhaustive no-writer/config route, one source definition in FpsPane.cpp, and UID0002W1 covered physical storage.
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) : reconstructable : 94% : very-strong : One-definition FpsPane singleton pointer initialized to zero and published/cleared by explicit Singleton<FpsPane> constructor/destructor specializations, with three exact lifecycle refs and UID0002W0 covered physical storage.
```

- `by-memory/-coverage-report.md`: replace the complete existing UID00015D subtree with the following exact block. B009 must not apply it:

```markdown
    - [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) 0x004b6410-0x004b6caf | class-cluster split index | FpsPaneDiagnostics : not_reconstructable : 92% : very-strong : Complete non-emitting split/index for the exact FpsPane diagnostics code island, seven authored source bodies, compiler deleting wrappers/adjustors, six exact padding gaps, direct Pane plus Singleton inheritance, exact 0x170 layout, corrected OnTimer and inherited layer/timer APIs, and child-first CPP/H emission through UID00005F/UID0000JK.
        - [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) 0x004b6410-0x004b646b | raw constructor | FpsPaneConstructorRaw : reconstructable : 93% : very-strong : Exact FpsPane constructor source with Pane(1), Singleton<FpsPane> publication, inherited m_hasPendingMotionRegion set, current-FPS clear, three compiler vptr stores, exact boundary/padding, no invented +0xfc initialization, and formal CPP through UID00005F.
        - [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) 0x004b6470-0x004b6499 | destructor | FpsPaneDestructor : reconstructable : 93% : very-strong : Empty authored virtual FpsPane destructor with exact ordinary-body boundary, Singleton<FpsPane> clear, compiler vptr restoration, Pane base teardown, scalar-wrapper parity, surrounding padding, and formal CPP through UID00005F.
        - [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) 0x004b64a0-0x004b67a7 | raw method | FpsPaneUpdateFpsLogSessionRaw : reconstructable : 94% : very-strong : Exact FpsPane::UpdateFpsLogSession(bool) controller using RectBounds::SetLTRB, IsAttachedToLayer, AddToLayer/RemoveFromLayer, inherited ScheduleTimer/RemovePendingTimers, g_pIMEPaneLayer, retained logging helpers, exact 190-instruction body and no-route evidence, with corrected formal CPP.
        - [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) 0x004b67b0-0x004b68ab | virtual method | FpsPaneOnPaint : reconstructable : 93% : very-strong : Exact FpsPane::OnPaint primary virtual with frame-count increment, current-FPS formatting, inherited bounds fill, two-pass text draw, vtable-only route, exact boundaries, and formal CPP.
        - [UID:00015H][0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics](by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md) 0x004b68b0-0x004b69b0 | TimerHandler override | FpsPaneOnTimer : reconstructable : 94% : very-strong : Exact TimerHandler-adjusted FpsPane::OnTimer(int,int,int) with signed frame sampling/reset, FPS min/max/sample/total updates, MapPane/ObjectList count totals, inherited ScheduleTimer(0,1000,0,0), always-true return, exact tertiary vtable route, and formal CPP.
        - [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSession](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md) 0x004b69b0-0x004b6adc | retained raw helper | FpsPaneStartLogSession : reconstructable : 92% : very-strong : Complete retained private start-log helper with exact field resets, timer tick, timestamp/filename ordering, CP949 header writes, one-shot debug gate, active inline twin, exact boundary/hash evidence, no caller/pointer route preserved as a liveness cap, and formal CPP.
        - [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) 0x004b6ae0-0x004b6c2b | retained raw helper | FpsPaneWriteLogSummary : reconstructable : 92% : very-strong : Complete retained private summary helper with default-off gate, append-mode file open, elapsed/min/max/average FPS and object-count output, unsigned division semantics, active inline twin, exact boundary/hash evidence, no caller/pointer route preserved as a liveness cap, and formal CPP.
        - [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) 0x004b6c2b-0x004b6c41 | compiler thunk | FpsPaneAdjustorThunks : ignored : 90% : very-strong : Exact +0xa0 and +0xa4 deleting-destructor adjustors with vtable-only routes into the scalar wrapper; compiler-generated and non-emitting with no handwritten source.
        - [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) 0x004b6c50-0x004b6caf | compiler destructor wrapper | FpsPaneScalarDeletingDestructor : reconstructable : 91% : very-strong : Exact FpsPane scalar deleting destructor wrapper with three vptr restores, Singleton clear, Pane teardown, optional 0x170-byte delete path, primary/adjustor routes, and class-declaration covered-by source disposition.
```

- In `by-memory/-coverage-report.md`, replace the FpsPane readonly/data rows with:

```markdown
    - [UID:00025E][0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData](by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md) 0x0061a61c-0x0061a7dc | mixed compiler/literal-data index | FpsPaneReadOnlyData : not_reconstructable : 90% : very-strong : Non-emitting parent for exact FpsPane vtables and FPS diagnostic source literals, with strict child boundaries and FrameHandler successor exclusion; declarations/method expressions regenerate all represented data.
        - [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) 0x0061a61c-0x0061a6a4 | compiler vtable data | FpsPaneVtableData : reconstructable : 93% : very-strong : Exact primary, EventHandler, and TimerHandler FpsPane vtable region with RTTI locators, lifecycle stores, deleting adjustors, OnPaint and corrected OnTimer slots, strict FPSDATA boundary, and class-declaration covered-by emission.
        - [UID:0003BJ][0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData](by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md) 0x0061a6a4-0x0061a7dc | source literal data | FpsPaneDiagnosticStringData : reconstructable : 93% : very-strong : Exact FPSDATA filename/header/summary and wide overlay literals with method xrefs and strict boundaries, embedded through FpsPane authored methods with no duplicate raw-array emission.
```

- In `by-memory/-coverage-report.md`, replace UID00027E and UID0002W1 and insert missing UID0002W0 immediately before UID0002W1:

```markdown
    - [UID:00027E][0x0066da90-0x0066da94.g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md) 0x0066da90-0x0066da94 | initialized global flag | g_fpsDebugActive : reconstructable : 92% : very-strong : Exact four-byte FpsPane diagnostics activation int initialized to 1, four direct code refs, strict adjacent boundaries, one source definition through UID0000PY/UID0000JK, and covered physical-storage emission.
    - [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md) 0x0069b334-0x0069b338 | singleton pointer storage | g_pFpsPane : reconstructable : 94% : very-strong : Exact loader-zero four-byte FpsPane singleton pointer with constructor, ordinary-destructor, and scalar-destructor lifecycle refs, explicit Singleton<FpsPane> publication/clear, one definition through UID0000QZ/UID0000JK, and covered physical-storage emission.
    - [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md) 0x0069b338-0x0069b339 | loader-zero global flag storage | g_fpsLogEnabled : reconstructable : 94% : very-strong : Exact one-byte loader-zeroed FpsPane logging bool with four read-only truth tests, no writer/pointer/config route, one source definition through UID0000PZ/UID0000JK, strict padding boundary, and covered physical-storage emission.
```

- The supervisor must reread each exact row against the accepted current page metadata before applying C047-C052 and adjust only when validated metadata differs from these recommendations. B009 must never edit any `-coverage-report.md` file.
- Validator-owned `auto-generated/-ag-*` reports must be refreshed, never manually edited.

## Follow-Up Actions

1. Supervisor performs wholly fresh Gate 1 and Gate 2A audits of this exact repaired artifact and its complete ledger/checklist.
2. C001-C025 ordinary implementation is complete; do not repeat it unless a fresh physical check identifies an exact mismatch.
3. Supervisor applies and verifies C026-C046 under Gate 2B, then owns C047-C054 coverage, validation, and lifecycle actions.
4. Supervisor remains responsible for final report execution/archive state and exact archived-artifact verification.

## Confidence

- Ownership/source placement: `96`.
- Inheritance/vtables/layout/ranges: `96`.
- Method behavior and API correction: `95-97` depending on child.
- Human source spellings/factoring: `90-94`.
- Raw-helper live reachability: low; explicitly not claimed.
- Overall whole-file recommendation: very strong.

## Validator Results

- During the historical report-only phase, no validator ran. During the accepted ordinary callback on `2026-08-24`, B009 ran the following exact scoped commands from `source-3/project-documentation`; each returned exit `0` and `ok:1`. This Gate 2A state-receipt repair did not rerun any validator.

| Order | Exact changed file | Exact scoped command | Callback result |
| ---: | --- | --- | --- |
| 01 | `by-file/FpsPane.md` | `python .\tools\validator.py --mode file --file by-file/FpsPane.md --apply --queue-timeout 240` | command `27767`; exit 0; `ok:1` |
| 02 | `by-class/FpsPane.md` | `python .\tools\validator.py --mode file --file by-class/FpsPane.md --apply --queue-timeout 240` | command `27768`; exit 0; `ok:1` |
| 03 | `by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md --apply --queue-timeout 240` | command `27769`; exit 0; `ok:1` |
| 04 | `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md --apply --queue-timeout 240` | command `27770`; exit 0; `ok:1` |
| 05 | `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md --apply --queue-timeout 240` | command `27771`; exit 0; `ok:1` |
| 06 | `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md --apply --queue-timeout 240` | command `27772`; exit 0; `ok:1` |
| 07 | `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md --apply --queue-timeout 240` | command `27773`; exit 0; `ok:1` |
| 08 | `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md --apply --queue-timeout 240` | command `27774`; exit 0; `ok:1`; UID/path retained, source identity `OnTimer` |
| 09 | `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md --apply --queue-timeout 240` | command `27775`; exit 0; `ok:1` |
| 10 | `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md --apply --queue-timeout 240` | command `27776`; exit 0; `ok:1` |
| 11 | `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md --apply --queue-timeout 240` | command `27777`; exit 0; `ok:1` |
| 12 | `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | command `27782`; exit 0; `ok:1` |
| 13 | `by-type/by-struct/FpsPaneLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/FpsPaneLayout.md --apply --queue-timeout 240` | command `27783`; exit 0; `ok:1` |
| 14 | `by-type/by-vtable/FpsPane_vtables.md` | `python .\tools\validator.py --mode file --file by-type/by-vtable/FpsPane_vtables.md --apply --queue-timeout 240` | command `27784`; exit 0; `ok:1` |
| 15 | `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md --apply --queue-timeout 240` | command `27785`; exit 0; `ok:1` |
| 16 | `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md --apply --queue-timeout 240` | command `27786`; exit 0; `ok:1`; Item Summary retained |
| 17 | `by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md --apply --queue-timeout 240` | command `27787`; exit 0; `ok:1` |
| 18 | `by-global/g_fpsDebugActive.md` | `python .\tools\validator.py --mode file --file by-global/g_fpsDebugActive.md --apply --queue-timeout 240` | command `27788`; exit 0; `ok:1` |
| 19 | `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` | `python .\tools\validator.py --mode file --file by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md --apply --queue-timeout 240` | command `27789`; exit 0; `ok:1` |
| 20 | `by-global/g_fpsLogEnabled.md` | `python .\tools\validator.py --mode file --file by-global/g_fpsLogEnabled.md --apply --queue-timeout 240` | command `27790`; exit 0; `ok:1` |
| 21 | `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md --apply --queue-timeout 240` | command `27791`; exit 0; `ok:1` |
| 22 | `by-global/g_pFpsPane.md` | `python .\tools\validator.py --mode file --file by-global/g_pFpsPane.md --apply --queue-timeout 240` | command `27792`; exit 0; `ok:1` |
| 23 | `by-memory/0x0069b334-0x0069b338.g_pFpsPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069b334-0x0069b338.g_pFpsPane.md --apply --queue-timeout 240` | command `27793`; exit 0; `ok:1` |
| 24 | `by-global/g_pIMEPaneLayer.md` | `python .\tools\validator.py --mode file --file by-global/g_pIMEPaneLayer.md --apply --queue-timeout 240` | command `27794`; exit 0; `ok:1`; H declaration retained |
| 25 | `by-file/MainUiGraph.md` | `python .\tools\validator.py --mode file --file by-file/MainUiGraph.md --apply --queue-timeout 240` | command `27795`; exit 0; `ok:1` |

- After the supervisor applies C047-C052, validate each changed manual coverage file with the same scoped form: `python .\tools\validator.py --mode file --file by-file/-coverage-report.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-type/by-vtable/-coverage-report.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-global/-coverage-report.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240`.
- Final coherent generated refresh command `python .\tools\validator.py --mode file --file by-file/FpsPane.md --apply --wait-generated --queue-timeout 240` completed as command `27796`, exit `0`, `ok:1`, with `generated_refresh: completed` at `2026-08-24T15:09:23-04:00`.
- Physical readback dated `2026-08-24T19:09:41Z`: `FpsPane.cpp` SHA256 `1561B88559204B4080A45DF77A54436C3673068CF411B18CEA82FDEB72656DCC` contains seven authored bodies, two Singleton specializations, three semantic definitions, eight compiler/covered comments, and no empty-emitter marker; the only `UpdateStatistics` text is the retained by-memory filename in a generated provenance comment, while authored source identity is `OnTimer`.
- Physical readback dated `2026-08-24T19:09:41Z`: `FpsPane.h` SHA256 `0C62504B2B5CB6FE92FF261DFA407515501D5F31062150F76DAB99F38165145A` contains exact direct inheritance, methods, fields, three externs, the size guard, and no decompiler label.
- Dependency readback dated `2026-08-24T19:09:45Z`: `MainUiGraph.h` SHA256 `7925E757BDA57FE1D4DA5466693AC424E84C641F954D815BAEC74CE02E16A971` contains `class Layer;` and `extern Layer *g_pIMEPaneLayer;`; B009 did not edit the generated header directly.
- Fresh tracker readback dated `2026-08-24T19:22:59Z`: command `27800`, SHA256 `A103EBFA55CD44132CA2988D2D487427C0FFA46E7D0A056B1E5EE143B2F5F45F`, FpsPane row `19/19/0/100.0%`. This later deferred refresh did not alter the ordinary destination claims.
- Report execution/archive validation is exclusively supervisor-owned.

## Changed Files

- This report was changed additively to record the accepted callback and current Gate 2A receipts: `tools/leaser/Agents/Agent-B009/research/0000JK-FpsPane-file-source-quality.md`. Its final hash is reported after the self-referential content is complete, not embedded here.
- Fresh physical hashes for all 25 ordinary callback destinations were computed read-only on `2026-08-24` after the callback; no destination was edited during this Gate 2A repair:

| Order | Ordinary callback destination | Fresh physical SHA256 |
| ---: | --- | --- |
| 01 | `by-file/FpsPane.md` | `08B62827F96362624594C73B015486287EDE5B8964FA7A1150ADD40FAEA8E3F3` |
| 02 | `by-class/FpsPane.md` | `B9DE38AD31E92C6967E2C8CF51CA59620DA652F1BA482B735B4E029B45A78DDC` |
| 03 | `by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md` | `BBEBCF0D4D9520043E908AD1F2BC8075470F88B95D8AF6716FC586FF362798B5` |
| 04 | `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` | `7B518FF97E8437B5F5A3BA3D95FD91AA06C49D6741AF1C26AEAF3E3C798258CE` |
| 05 | `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` | `E97A560101C2E2F0B9C5EB591E22FAA9039DE6897728F43CABA99E7664A34B13` |
| 06 | `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` | `3F3635B708687BCD54AD15BB0C68DD817F0EEF02DF8E32F307EC3C05F0878FCC` |
| 07 | `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md` | `5D63F7040F96867569557737A7B78F989B2A17058C0D2FDE5C7E3BE3E4AA198A` |
| 08 | `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` | `3B86506068D8736DEEBDF57DAB230C33701D84C64EA3B296CAA7B6CFD6B89EF5` |
| 09 | `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` | `321BBBCEBEB9CE1330E2DBCB64DF29689D5846EBB304E6ACD9FE220F52BA44F0` |
| 10 | `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` | `104851BDA41BC2E23024FD6080D90B12CFEB65F6E0B0FBC751F0FD5BED74A41B` |
| 11 | `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md` | `04E4E20961EAF7D8615D7DF4BC89EC3878768B129CA35A9B921D4B691650E9F9` |
| 12 | `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` | `AE1DEC75DA0615946D61707A7F427F05931D41B3F54C1F670E83B84CD665D8CF` |
| 13 | `by-type/by-struct/FpsPaneLayout.md` | `14CCB2A291D375D3BD1D57696DA6749A729817C33D754CC12F57B70E6732FBD8` |
| 14 | `by-type/by-vtable/FpsPane_vtables.md` | `1B691DD062B18918CCD6310FFE51062F7CEFD072180597BDAF1FAF11EF32730A` |
| 15 | `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md` | `3FEB15651A1EFE99AA6B85B6466E39D1F58BA8B76DA06DE5C1754F0ED7672EBB` |
| 16 | `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md` | `564EE9F63FCB84A8F75D47866FF8D077762143762D917D87F583E6D7101CA99C` |
| 17 | `by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md` | `7FB3E0664D02A94932D94A5012BEE127D4F2294AA4103A9EDEFDD39D4A72DACD` |
| 18 | `by-global/g_fpsDebugActive.md` | `E867B533D2627D139C32E4C87B630428DF3173ABE2619114695955C45EFB31D4` |
| 19 | `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` | `D1AA8B2ECF798FC44042A2C1ED7E934AE74F0629BA0D9F9135A64878D8C2F806` |
| 20 | `by-global/g_fpsLogEnabled.md` | `54B1770B42982B578FFFCB9F768BE48209E6DED144BE15F4CF36D5D9BDD765DE` |
| 21 | `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` | `0B31471B11F2EEB3038B028FF9FC814E8639EF43CCEB80DCBB4C505D75894878` |
| 22 | `by-global/g_pFpsPane.md` | `44652FC17483507D73CEB77D9DACDFD2DC493D3C7A83AC4A92C79BB20CD97610` |
| 23 | `by-memory/0x0069b334-0x0069b338.g_pFpsPane.md` | `A36FE78A0E8210F4FCC85F7C78C86EFC91369D046CE10560C6E18155BCE2743C` |
| 24 | `by-global/g_pIMEPaneLayer.md` | `74561A9671C5B9A7DC8F6CEBD18090F46F8EB459C2895AB1CE0DD8881A2FFC5B` |
| 25 | `by-file/MainUiGraph.md` | `1A737CF4FECD5AF79CD2064A7FB307D75F6FA4FD5012C0A30A46333C0673D960` |

- All 25 physical destination hashes were reverified unchanged at `2026-08-24T19:30:29Z` after the contradiction repair.
- `FpsPane.cpp`, `FpsPane.h`, and `MainUiGraph.h` were produced by validator command `27796` and were physically reread as read-only receipts; B009 never edited generated files directly.
- B009 did not directly edit any coverage report, generated tracker, validation audit, catalog, registry, lifecycle/status-control file, IDB, or process state. Validator side effects and independent validator refreshes remain validator-owned and are distinguished above from B009's 25 ordinary documentation edits.

## Implementation Tracking Checklist

This is the exact ordered normalized twin of C001-C054. C001-C025 are checked because the accepted ordinary implementation callback was physically applied, scoped-validated, generated-refreshed, and reread. C026-C054 remain unchecked and supervisor-owned.

| Done | Claim ID | Actor | Exact destination | Exact one-destination action | Evidence | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | B009 callback | `by-file/FpsPane.md` [UID:0000JK] | Preserve FILE/path; add exhaustive inventory, corrected APIs, exact RTTI/literal/global routes, generated-defect audit, no-route history; set `94/96`. | complete island/docs/generated reconciliation | incorporate | verified 27767/27796 |
| [x] | C002 | B009 callback | `by-class/FpsPane.md` [UID:00005F] | Set `94/96`; preserve owner/emitter `0000JK`; insert exact class CPP/H payloads, direct bases, `0x170` layout, virtuals, globals, and Singleton rationale. | RTTI/size/offset/lifecycle evidence | incorporate | verified 27768/27796 |
| [x] | C003 | B009 callback | `by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md` [UID:00015C] | Set `93/95`; preserve owner/emitter `00005F`; replace formal CPP with exact constructor payload and correct inherited-field/Singleton prose. | raw body and Pane layout | incorporate | verified 27769/27796 |
| [x] | C004 | B009 callback | `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md` [UID:00015D] | Set `92/95`; preserve owner `0000JK`, `RECONSTRUCTABLE:FALSE`, blank emitter/CPP/H; add exact 10-code/6-gap split inventory. | complete range closure | incorporate | verified 27770/27796 |
| [x] | C005 | B009 callback | `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` [UID:00015E] | Set `93/95`; preserve owner/emitter `00005F`; insert exact empty authored destructor and compiler/base-lifecycle explanation. | body/tail jump/vptr/global refs | incorporate | verified 27771/27796 |
| [x] | C006 | B009 callback | `by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md` [UID:00015F] | Set `94/95`; preserve owner/emitter `00005F`; replace formal CPP with exact `RectBounds`/layer/inherited-timer payload and full call evidence. | 27 calls, fields, globals, literals | incorporate | verified 27772/27796 |
| [x] | C007 | B009 callback | `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md` [UID:00015G] | Set `93/95`; preserve owner/emitter `00005F`; retain the exact formal CPP reproduced below and add complete frame/xref/header route. | vtable slot, 16 calls, literal | incorporate | verified 27773/27796 |
| [x] | C008 | B009 callback | `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md` [UID:00015H] | Set `94/96`; preserve UID/range/owner/emitter; change source-facing title/identity to `FpsPaneOnTimer`, retain old identity historically, replace exact CPP. | TimerHandler vtable/signature/calls | incorporate | verified 27774/27796 |
| [x] | C009 | B009 callback | `by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSession.md` [UID:00015I] | Set `92/94`; preserve owner/emitter `00005F`; retain exact CPP reproduced below and exhaustive zero-route/literal evidence. | complete raw body and active twin | incorporate | verified 27775/27796 |
| [x] | C010 | B009 callback | `by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md` [UID:00015J] | Set `92/94`; preserve owner/emitter `00005F`; retain exact CPP reproduced below and exhaustive zero-route/literal evidence. | complete raw body and active twin | incorporate | verified 27776/27796 |
| [x] | C011 | B009 callback | `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md` [UID:00015K] | Set `90/96`; preserve `NONE/FALSE` and blank emitter/CPP/H; document both exact thunks as compiler glue. | two vtable refs and tail jumps | incorporate | verified 27777/27796 |
| [x] | C012 | B009 callback | `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` [UID:00015L] | Set `91/96`; preserve owner/emitter `00005F`; retain exact compiler-covered CPP comment and blank H. | primary/thunk refs and flag path | incorporate | verified 27782/27796 |
| [x] | C013 | B009 callback | `by-type/by-struct/FpsPaneLayout.md` [UID:0001UO] | Set `94/96`; preserve owner/emitter `00005F`; add normalized direct bases/fields/size and exact class-covered CPP comment; blank H with declaration-owned reason. | complete offset closure | incorporate | verified 27783/27796 |
| [x] | C014 | B009 callback | `by-type/by-vtable/FpsPane_vtables.md` [UID:0001XN] | Set `93/96`; preserve owner/emitter `00005F`; correct `OnTimer`, enumerate all views/slots/RTTI, insert exact compiler-covered CPP comment; blank H. | 34 physical dwords and RTTI | incorporate | verified 27784/27796 |
| [x] | C015 | B009 callback | `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md` [UID:0002MJ] | Set `93/96`; preserve owner/emitter `00005F`; insert exact compiler-covered CPP comment, complete slot table and boundaries; blank H. | exact bytes/slots/lifecycle stores | incorporate | verified 27785/27796 |
| [x] | C016 | B009 callback | `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md` [UID:0003BJ] | Set `93/96`; preserve owner/emitter `0000JK`; populate Item Summary, 15-literal inventory, xrefs, exact source-literal CPP comment; blank H. | exact strings/xrefs/boundaries | incorporate | verified 27786/27796 |
| [x] | C017 | B009 callback | `by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md` [UID:00025E] | Set `90/95`; preserve `NONE/FALSE` and blank emitter/CPP/H; retain non-emitting two-child index and strict successor. | exact child partition | incorporate | verified 27787/27796 |
| [x] | C018 | B009 callback | `by-global/g_fpsDebugActive.md` [UID:0000PY] | Set `92/94`; preserve owner/emitter `0000JK`; retain exact CPP `int g_fpsDebugActive = 1;`, blank H because declaration is centralized in FpsPane H. | bytes and four refs | incorporate | verified 27788/27796 |
| [x] | C019 | B009 callback | `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md` [UID:00027E] | Set `92/95`; preserve owner/emitter `0000JK`; retain exact covered-storage CPP comment and blank H. | 4-byte initialized cell | incorporate | verified 27789/27796 |
| [x] | C020 | B009 callback | `by-global/g_fpsLogEnabled.md` [UID:0000PZ] | Set `94/96`; preserve owner/emitter `0000JK`; retain exact CPP `bool g_fpsLogEnabled;`, blank H because declaration is centralized in FpsPane H. | one-byte zero fill/four reads | incorporate | verified 27790/27796 |
| [x] | C021 | B009 callback | `by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md` [UID:0002W1] | Set `94/96`; preserve owner/emitter `0000JK`; retain exact covered-storage CPP comment and blank H. | one-byte head/boundary/xrefs | incorporate | verified 27791/27796 |
| [x] | C022 | B009 callback | `by-global/g_pFpsPane.md` [UID:0000QZ] | Set `94/96`; preserve owner/emitter `0000JK`; replace CPP with exact `FpsPane *g_pFpsPane = 0;`, blank H because declaration is centralized in FpsPane H. | three lifecycle refs/Singleton EBO | incorporate | verified 27792/27796 |
| [x] | C023 | B009 callback | `by-memory/0x0069b334-0x0069b338.g_pFpsPane.md` [UID:0002W0] | Set `94/96`; preserve owner/emitter `0000JK`; insert exact covered-storage CPP comment and blank H, removing its empty emitter. | 4-byte physical cell/three writes | incorporate | verified 27793/27796 |
| [x] | C024 | B009 callback | `by-global/g_pIMEPaneLayer.md` [UID:0004VG] | Keep `92/94`, owner/emitter `0000L1`, position `60`; retain CPP definition and insert exact formal H declaration `class Layer; extern Layer *g_pIMEPaneLayer;`. | exact FpsPane consumer and owner route | incorporate | verified 27794/27796 |
| [x] | C025 | B009 callback | `by-file/MainUiGraph.md` [UID:0000L1] | Keep `90/92`/FILE; document UID0004VG H ownership and expected `MainUiGraph.h` declaration without transferring FpsPane ownership. | owner metadata/generated absence | incorporate | verified 27795/27796 |
| [ ] | C026 | supervisor Gate 2B | IDA function `0x004b6470` | Pure rename only to `FpsPane__Destructor` under atomic A01. | current name/type/frame/dry run P02 | incorporate | proposed |
| [ ] | C027 | supervisor Gate 2B | IDA function `0x004b67b0` | Pure rename only to `FpsPane__OnPaint` under atomic A02. | current name/type/frame/dry run P04 | incorporate | proposed |
| [ ] | C028 | supervisor Gate 2B | IDA function `0x004b68b0` | Pure rename only to `FpsPane__OnTimer` under atomic A03. | current name/type/frame/dry run P05 | incorporate | proposed |
| [ ] | C029 | supervisor Gate 2B | IDA function `0x004b6c2b` | Pure rename only to `FpsPane__ScalarDeletingDestructorAdjustorA0` under atomic A04. | current name/type/frame/dry run P08 | incorporate | proposed |
| [ ] | C030 | supervisor Gate 2B | IDA function `0x004b6c36` | Pure rename only to `FpsPane__ScalarDeletingDestructorAdjustorA4` under atomic A05. | current name/type/frame/dry run P09 | incorporate | proposed |
| [ ] | C031 | supervisor Gate 2B | IDA function `0x004b6c50` | Pure rename only to `FpsPane__ScalarDeletingDestructor` under atomic A06. | current name/type/frame/dry run P10 | incorporate | proposed |
| [ ] | C032 | supervisor Gate 2B | IDA data `0x0066da90` | Pure rename only from `dword_66DA90` to `g_fpsDebugActive` under atomic A07. | named 4-byte item/dry run P11 | incorporate | proposed |
| [ ] | C033 | supervisor Gate 2B | IDA data `0x0066da90` | Set only global type `int` under atomic A08 after rename readback. | 4-byte width/value/xrefs P11 | incorporate | proposed |
| [ ] | C034 | supervisor Gate 2B | IDA address `0x004b6470` | Set only repeatable address comment under A09. | four comment channels absent P02 | incorporate | proposed |
| [ ] | C035 | supervisor Gate 2B | IDA address `0x004b67b0` | Set only repeatable address comment under A10. | four comment channels absent P04 | incorporate | proposed |
| [ ] | C036 | supervisor Gate 2B | IDA address `0x004b68b0` | Set only repeatable address comment under A11. | four comment channels absent P05 | incorporate | proposed |
| [ ] | C037 | supervisor Gate 2B | IDA address `0x004b6c2b` | Set only repeatable address comment under A12. | four comment channels absent P08 | incorporate | proposed |
| [ ] | C038 | supervisor Gate 2B | IDA address `0x004b6c36` | Set only repeatable address comment under A13. | four comment channels absent P09 | incorporate | proposed |
| [ ] | C039 | supervisor Gate 2B | IDA address `0x004b6c50` | Set only repeatable address comment under A14. | four comment channels absent P10 | incorporate | proposed |
| [ ] | C040 | supervisor Gate 2B | IDA address `0x0066da90` | Set only repeatable address comment under A15. | address comments absent P11 | incorporate | proposed |
| [ ] | C041 | supervisor Gate 2B | IDA address `0x0069b334` | Set only repeatable address comment under A16; no unsupported rename/item shaping. | unnamed one-byte head/4-byte physical cell P12 | incorporate | proposed |
| [ ] | C042 | supervisor Gate 2B | IDA address `0x0069b338` | Set only repeatable address comment under A17; no unsupported rename/item shaping. | name-index/item discrepancy and bool P13 | incorporate | proposed |
| [ ] | C043 | supervisor Gate 2B | IDA raw address `0x004b6410` | Set only repeatable address comment under A18; retain nonfunction. | raw constructor P01 | incorporate | proposed |
| [ ] | C044 | supervisor Gate 2B | IDA raw address `0x004b64a0` | Set only repeatable address comment under A19; retain nonfunction. | raw update P03 | incorporate | proposed |
| [ ] | C045 | supervisor Gate 2B | IDA raw address `0x004b69b0` | Set only repeatable address comment under A20; retain nonfunction. | raw start helper P06 | incorporate | proposed |
| [ ] | C046 | supervisor Gate 2B | IDA raw address `0x004b6ae0` | Set only repeatable address comment under A21; retain nonfunction. | raw summary helper P07 | incorporate | proposed |
| [ ] | C047 | supervisor | `by-file/-coverage-report.md` | Apply exact UID0000JK replacement text from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| [ ] | C048 | supervisor | `by-class/-coverage-report.md` | Apply exact UID00005F replacement text from this report after callback metadata validation. | stale 84% row | incorporate | proposed |
| [ ] | C049 | supervisor | `by-type/by-struct/-coverage-report.md` | Apply exact UID0001UO replacement text from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| [ ] | C050 | supervisor | `by-type/by-vtable/-coverage-report.md` | Apply exact UID0001XN replacement text from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| [ ] | C051 | supervisor | `by-global/-coverage-report.md` | Apply exact UID0000PY/0000PZ/0000QZ replacement block from this report after callback metadata validation. | current manual-row comparison | incorporate | proposed |
| [ ] | C052 | supervisor | `by-memory/-coverage-report.md` | Apply exact code/data/global-storage replacement blocks from this report after callback metadata validation. | current subtree comparison | incorporate | proposed |
| [ ] | C053 | supervisor | validator/generated outputs | Run every exact scoped command and final `--wait-generated` command below; physically verify expected CPP/H/tracker readbacks. | validator/generator contract | incorporate | proposed |
| [ ] | C054 | supervisor | report lifecycle | After fresh Gate 1, callback, Gate 2A/2B, coverage, validation and exact archived-artifact audit, own report execution/archive state. | role boundary | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000027822","destination_path":"executed-b-agent-research/B009/0000JK-FpsPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000JK-FpsPane-file-source-quality.md","timestamp":"2026-08-24T16:13:48-04:00","uid":"0000JK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
