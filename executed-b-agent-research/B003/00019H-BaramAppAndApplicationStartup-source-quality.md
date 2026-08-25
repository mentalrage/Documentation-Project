** TARGET-REPORT-UID:00019H **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 00019H BaramAppAndApplicationStartup Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented disposition: [UID:00019H] is now a reviewed, non-emitting mixed-owner split index at `92/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, blank R0 formal C++, and unchanged `Nested:0`.
- Implemented split: validator command `000000012645` serially registered the exact compiler child `by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md` as UID0004R1 before any dependent page was validated. The six pre-existing exact children and four internal alignment spans remain unchanged.
- Implemented child disposition: UID0004R1 is `92/94`, owner `0000PA`, non-reconstructable, non-emitting, blank optional position, blank R1 formal C++, and `Nested:0`; complete WinMain EH source-cause and compiler no-code evidence is installed.
- Callback status: C01-C20, R0/R1, all accepted ordinary destinations, scoped validators, verify-only rereads, and final waited generated checks are complete. No B003 implementation item remains.
- External supervisor manual-coverage application is complete: commands `000000012704` (`by-memory/-coverage-report.md`), `000000012705` (`by-class/-coverage-report.md`), and `000000012706` (`by-file/-coverage-report.md`) each exited `0` with `ok:1`. These were not B003 commands.
- Confidence: very strong for the exact range, full byte partition, child boundaries, compiler/source distinctions, mixed-owner reclassification, no-code disposition, and generated-output effect.

## Supporting Research

- Mandatory live evidence was gathered from IDA MCP database `46dda60b` on 2026-07-15 EDT. The earlier dead session `49ac345c` is historical outage evidence only and is not used for any conclusion in this report.
- Fresh `idb_list` at evidence-collection time `2026-07-15T00:42:52-04:00` returned exactly one NexusTK database, session `46dda60b`, `is_active:true`, worker PID `16644`. `server_health` returned `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and 2,067 cached strings. This records captured health only, not indefinite session availability.
- B003 read the current target, all six existing exact children, [UID:00019G] WinMain, [UID:0002GZ] ApplicationDestructor, [UID:0003P2] BaramAppVtableData, the BaramApp/Application class pages, Application/WinMain file pages, current `Application.cpp`, manual coverage rows, `by-memory/-ignored.md`, `by-structure.md`, and the current workflow/template/score standard.
- Historical-report search used the exact terms `00019H`, `0x004f5f20`, `0x004f66fb`, `BaramAppAndApplicationStartup`, `0x004f66b0`, `ApplicationStartup`, and `ApplicationShutdown` against all fifteen active `tools/leaser/Agents/Agent-B001` through `Agent-B015` `research` roots, central `executed-b-agent-research`, `archived`, `tools/leaser/Agents/Older-Research`, and `tools/leaser/Agents/SpecialReports`.
- All fifteen active research roots, `archived`, `Older-Research`, and `SpecialReports` had zero matches. Central `executed-b-agent-research` had 42 files with at least one broad term; the target-specific reports classified below are the relevant evidence leads. No active competing exact report was found.

| Historical report | Target-specific classification |
| --- | --- |
| B003 `0002PZ-BaramAppConstructorRaw-empty-emitter-source-quality.md` | Current for the 46-byte unpromoted constructor body and exact formal constructor; independently revalidated here. |
| B009 `0002Q0-BaramAppTerminalPaneCallbackFactory-empty-emitter-source-quality.md` | Current for callback wrapper type, `void` source signature, cursor restore, and TerminalPane construction; independently revalidated here. |
| B007 `0002H7-ApplicationStartup-source-quality.md` | Current for `Application::Startup`, source order, callback creation, and compiler-EH exclusions; independently revalidated here. |
| B008 `0002H8-ApplicationShutdown-empty-emitter-source-quality.md` | Current for `Application::Shutdown`, teardown order, and `CleanupResources` tail; independently revalidated here. |
| B014 `0002Q1-BaramAppDeletingDestructorThunk-source-routing.md` | Current for `this -= 4` adjustor-thunk evidence; incomplete for UID00019H because it identified but did not create the exact `0x004f66b0` child. |
| B010 `0002Q2-BaramAppScalarDeletingDestructor-empty-emitter-source-quality.md` | Current for scalar-wrapper ABI, primary/secondary vtable routes, and no handwritten wrapper body; independently revalidated here. |
| B009 `0002GZ-ApplicationDestructor-empty-emitter-source-quality.md` | Current for ordinary `Application::~Application` cleanup and the three call routes, including `0x004f66b0`. |
| B012 `0003P2-BaramAppVtableData-empty-emitter-source-quality.md` | Current for primary/secondary BaramApp vtables, RTTI/COL cells, and callback-vtable source cause. |
| B009 `00019G-WinMain-source-quality.md` | Current for stack `BaramApp` construction and WinMain source; incomplete for the out-of-line EH cleanup target because no exact child was registered. |
| B013 `0000HG-Application-empty-emitter-family-source-quality.md` | Historical implementation is current as evidence that exact children emit, but its recommendation to keep UID00019H `TRUE` with an aggregate marker is superseded by the current reviewed-container rule and complete mixed-owner split. |
| B014 `0002GY-ApplicationConstructor-source-quality.md` | Current base-constructor/layout support only; not a substitute for this target-specific aggregate pass. |
| Other 31 central matches | Dependency/caller/support leads only; no contrary target range, byte partition, ownership, or formal disposition was found. |

## Target

- Target UID: `00019H`.
- Implemented target path: `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Historical pre-callback state: `86/90`, `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`, blank optional position, aggregate comment marker, and `Nested:0`.
- Implemented scores and parent state: `92/94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, blank R0 formal, and `Nested:0`.

## Current Target State

- The implemented target metadata now correctly treats the address-neighborhood page as a non-source mixed index over BaramApp methods, Application methods, one WinMain EH cleanup thunk, compiler destructor products, and padding. The exact range, 2,011-byte hash/partition, four parent-only alignment spans, ownership table, caller graph, source/compiler distinctions, rejected alternatives, and score rationale are present at report-level detail.
- Historical pre-callback state: the target's aggregate comment produced one redundant UID00019H row in `Application.cpp`, and `sub_4F66B0` existed only as broad ignored-ledger prose. That state is superseded.
- Current child state: UID0004R1 is registered at exact range `0x004f66b0-0x004f66b5`, linked from the parent and bounded support pages, and carries exact bytes/hash, sole WinMain EH route, ApplicationDestructor tail target, negative route evidence, no-code proof, and blank R1 formal. Every source-bearing or compiler-bearing byte now has an exact child page.
- Historical pre-supervisor-application state: manual `by-memory/-coverage-report.md` showed UID00019H as `78%` reconstructable, retained stale UID0002PZ/2Q0/2H7/2Q1/2Q2 values, and omitted internal padding plus the exact cleanup-thunk child. Current readback after supervisor commands `000000012704`-`000000012706` confirms the accepted parent/child/padding and bounded support rows are applied across by-memory, by-class, and by-file manual coverage at same-or-greater factual detail.
- Historical B003 callback snapshot: waited command `000000012664` at `2026-07-15T01:25:07-04:00` generated `Application.cpp` SHA256 `0406D1CDA03216E7471580100E5B834C5B5226959B6BA1E1FED133F8AE30FE60` and `WinMain.cpp` SHA256 `65DCFDBA1990F2346D28B1FF3BD11346CE5D401FC072C88BF718CB96BD06923C`. This remains B003's implementation/validator proof and is not relabeled as the latest external epoch.
- Read-only external checkpoint observed for this bounded rebase: validator header `000000012699`, refreshed `2026-07-15T01:54:32-04:00`, produced `Application.cpp` SHA256 `AB554D3AF0F804F53BE5ED25A546F494B444914F5FF7991FC4CC1D490E4DC1EE` and `WinMain.cpp` SHA256 `D1472FCCB9A0B75DDF4AEE0A1AAE27D865A35AF9BE44A044633207C39AA5645A`. Command `000000012699` was not issued by B003; it is an external supervisor/B004-era generated snapshot. At that observed epoch Application has UID0002PZ/2Q0/2H7/2H8/2Q2 once each, UID00019H/0004R1/2Q1 zero, four exact source definitions once each, zero empty markers, and zero raw cleanup-thunk names/addresses. WinMain has one WinMain definition, one stack `BaramApp` construction, zero UID00019H/0004R1 and zero raw thunk names/addresses; its sole empty marker is the unrelated preserved UID00032A helper. Later unrelated header-only epochs do not alter this captured semantic proof.
- Concurrent ordinary-page rebase: `by-memory/-ignored.md` is now SHA256 `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232` because B004 added unrelated UID0003U7 alignment `[0x005a3766,0x005a3770)`. The UID0004R1 entry, exact `e9 bb d2 f6 ff`/SHA256, sole WinMain EH route, no-code disposition, predecessor eleven-byte alignment, and successor three-byte alignment remain unchanged. The target still records all four exact parent-only spans `[0x004f5f4e,0x004f5f50)`, `[0x004f5faf,0x004f5fb0)`, `[0x004f66a5,0x004f66b0)`, and `[0x004f66bd,0x004f66c0)` with their accepted lengths and hashes. B004's added UID0003U7 padding is preserved unrelated concurrent content, not a UID00019H change.
- Related target/support changes and verify-only rereads are enumerated below. Eight ordinary pages were created or modified, each was scoped-validated, and all B003 leases were released.
- Historical B003 artifact path before external supervisor lifecycle: `tools/leaser/Agents/Agent-B003/research/00019H-BaramAppAndApplicationStartup-source-quality.md`. B003 performed the authorized ordinary implementation/validators only and performed no report execute, probe, count, registry, revalidation, move, archive, or other lifecycle command. Current report path/count/acceptance/lifecycle state is external supervisor/validator-owned and is neither asserted nor directed here.

## Executive Recommendation

- UID00019H is implemented as a non-emitting split index. It is not an original source object, declaration, table, class, or coherent emitted range.
- Implemented `CANONICAL_OWNER:NONE`: exact children have three distinct immediate semantic contexts, BaramApp (`00000V`), Application (`00000D`), and WinMain file (`0000PA`). Keeping `0000HG` on the parent would conflate final output route with canonical ownership.
- UID0004R1 is the validator-issued identity for `by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md`; command `000000012645` registered it serially before any dependent support link was edited or validated.
- UID0004R1 is implemented at `92/94`, `CANONICAL_OWNER:0000PA`, `RECONSTRUCTABLE:FALSE`, blank emitters/position/formal, and `Nested:0`. WinMain is the narrow source context because the sole inbound edge is its EH cleanup funclet for the stack `BaramApp` local.
- All six existing children, scores, source blocks, compiler dispositions, owners, emitters, positions, ranges, and names were preserved. No evidence contradicts them.
- Relative nesting is preserved: parent `Nested:0`, first child UID0002PZ `Nested:4`, all later children including UID0004R1 `Nested:0`, and successor UID00019I `Nested:-4`. The new address-sorted row does not change cumulative nesting.

## Supervisor Active Recheck

- The supervisor assigned and accepted the direct source-quality pass over UID00019H after the prior UID00048L lifecycle closed, then authorized this bounded callback.
- Historical pre-callback defect: one real modeled function was represented only by a broad ignored-ledger sentence. The callback resolved that defect by registering UID0004R1 before dependent links and validation.
- Every source-bearing or compiler-bearing byte now has an existing exact child, including issued UID0004R1. The four internal padding spans remain parent-only and are explicitly hashed and listed.
- No exact child or accepted callback destination remains blocked by an unresolved body, owner, source route, type, signature, compiler/source distinction, validator, generated check, or lease.

## Inference Research Guidance Check

- `by-structure.md` requires reviewed mixed-owner convenience ranges whose exact children own the real source to be `RECONSTRUCTABLE:FALSE`; the target meets that rule exactly.
- Existing `TRUE`/aggregate-marker metadata and B013's older marker recommendation were treated as hypotheses, not authority. Fresh range, source-cause, generated-output, and child-completeness evidence rejects them.
- Direct facts are labeled as MCP byte/function/xref/decompile/vtable results. Documentation facts are current UID metadata/formals/generated/manual rows. Inferences are limited to source-facing names, the descriptive new-child title, and late-1990s/2000s source placement.
- Wave2/Wave3-era language was encountered in stale manual coverage and historical docs. It was not used as evidence; current live MCP and current ordinary docs control every recommendation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Resolution / classification |
| --- | --- | --- |
| Aggregate purpose | Full 2,011-byte audit shows two class owners, one file-local WinMain compiler child, two compiler destructor products, and padding. | Mixed-owner address index, not source. Set parent `FALSE`, owner `NONE`, no emitter/formal. |
| Missing executable span | `lookup_funcs` and range query show `sub_4F66B0`, size `0x5`; exact bytes and unique exact pattern prove code, not padding. | Resolved: exact child UID0004R1 is registered and validated. |
| Cleanup-thunk name | Body has no source symbol and only tail-jumps to `Application::~Application`; EH source loads WinMain's stack BaramApp local. | Documentation name `WinMainBaramAppCleanupThunk` is descriptive, not claimed original. No source function name or declaration is emitted. |
| Cleanup owner | Sole xref `0x00600fc6` is in `_WinMain@16` EH chunk and computes the local at `[ebp+var_1A88]`. | Semantic context owner `0000PA` WinMain; reject BaramApp class method and Application file helper ownership. |
| Raw constructor liveness | No IDA function, start xref, or absolute VA/RVA pointer; 17 instructions form a complete constructor and WinMain independently inlines the same construction. | Preserve existing source-ready constructor child and confidence cap. Do not define/rename IDA function. |
| Callback signature | Hex-Rays guesses a pointer return, but decorated `PlainMemberFunctionObject0<void (BaramApp::*)(void),BaramApp>` vtable and wrapper stores prove source `void`. | Preserve `void BaramApp::OpenTerminalPaneAfterStartupLogo()`. Reject decompiler return type. |
| Startup/shutdown source names | Current formals use inferred project names; fresh decompiles and current support pages preserve call order and global roles. | Preserve exact child formals and scores; no aggregate copy. |
| Scalar wrapper | Hidden delete flags, return-this ABI, primary/secondary vtable-only reachability, and calls to ordinary destructor/delete wrapper are compiler lowering. | Preserve existing marker child; reject handwritten scalar-deleting-destructor source. |
| Secondary thunk | Only `sub ecx,4; jmp 0x004f66c0`; sole route is secondary vtable slot. | Preserve `RECONSTRUCTABLE:FALSE`, no emitter/formal. |
| Vtable/RTTI | Primary/secondary COL and slots plus callback wrapper table are compiler output caused by declarations and methods. | Preserve compiler-marker vtable child; no raw arrays. |
| Parent emitter order | Historical pre-callback Application.cpp emitted each source child once while UID00019H contributed only a duplicate aggregate comment. | Implemented: parent route/formal removed; children keep existing routes/order. B003 command `000000012664` and read-only external checkpoint `000000012699` both have zero parent row. |
| Relative nesting | Current cumulative level rises from parent baseline 0 to 4 at first child and returns by successor UID00019I `-4`. | Parent remains 0; new later child is 0; following levels unchanged. |
| Original file split | Application/BaramApp source children currently route through `app/Application.cpp`; WinMain source is `app/WinMain.cpp`. | Preserve child routes. Parent gets no source placement because it is not a source unit. |
| Generated pollution | Historical command `000000012621` had no empty markers but still emitted UID00019H once as a broad marker. | B003 callback command `000000012664` removed that row; external read-only checkpoint `000000012699` independently preserves zero UID00019H/0004R1 rows, exact child source rows once, and zero Application empty markers. |
| IDA mutation | Current generic names are sufficient to preserve searchability; descriptive source-facing documentation resolves the role. | No IDA rename/type/comment mutation requested. |

Rejected alternatives:

- Keep UID00019H `TRUE` with its historical pre-callback marker: rejected because the container itself is not source and exact children already regenerate all source-bearing behavior.
- Keep `CANONICAL_OWNER:0000HG`: rejected because the new exact child is caused by WinMain EH and the parent has no coherent direct source owner.
- Merge `0x004f66b0-0x004f66b5` into UID0002Q1: rejected because the bytes, jump targets, inbound routes, and source causes differ.
- Leave `0x004f66b0` only in `-ignored.md`: rejected because current structure rules require every understood executable child to have a precise by-memory page.
- Emit `void WinMainBaramAppCleanupThunk()` or a destructor call: rejected because the compiler generated the EH funclet/tail thunk from stack-object lifetime; handwritten C++ would encode compiler lowering.
- Move constructor/callback into WinMain: rejected because their exact out-of-line bodies and callback-member type are BaramApp-owned even though WinMain constructs the class.
- Add aggregate `[[CHILDREN]]`: rejected because the parent has no emitter and exact children already route through their class/file chains.
- Hand-author BaramApp vptr stores, deleting flags, RTTI, vtables, EH labels, or tail jumps: rejected as compiler/decompiler artifacts.

## Evidence Standards Used

- Direct evidence: fresh MCP health, function enumeration, bounded bytes, SHA256 hashes derived from MCP-returned bytes, instruction queries, disassembly, decompilation, xrefs, callees, exact-pattern and pointer-pattern searches, vtable integer reads, and IDA names.
- Corroboration: current by-memory/class/file docs, exact formals, manual coverage, ignored ledger, generated Application.cpp, and executed reports used only as leads.
- Negative evidence: no constructor function/start xref/pointer route; no cleanup-thunk VA/RVA pointer; no normal cleanup-thunk caller/callee; no active report; no extra function in the parent range; no vtable route to `0x004f66b0`.
- Evidence ladder: bytes and explicit xrefs outrank decompiler types and historical prose. Decorated type names outrank Hex-Rays' unused-return guess. Source/compiler classification uses call convention, hidden flags, EH-only route, vtable-only route, and exact body shape.
- Confidence remains below final-audit `95` because original filenames, exact callback/member spellings, and raw constructor liveness cannot be proven from the stripped binary. Those caps do not block the split or formal disposition.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: JSON-RPC requests at `00:42:52`, `00:45:22`, `00:46:55`, `00:47:26`, `00:50:13`, `00:50:48`, and `00:51:11` EDT against database `46dda60b`; all valid calls returned `isError:false`.
- Mechanical MCP inventory: 15 boundary lookups; one in-range function enumeration returning six functions; four bounded byte chunks totaling exactly 2,011 bytes; 12 internal subrange hashes; 14 xref queries returning 19 total xrefs; six callee queries; five successful decompiles; raw constructor 17-instruction scan; cleanup/adjustor/scalar disassembly; seven-instruction WinMain EH scan; 18 vtable/callback dword reads; exact-byte and VA/RVA pointer searches.
- Current docs checked: UID00019H; UID0002PZ, 0002Q0, 0002H7, 0002H8, 0002Q1, 0002Q2; UID00019G; UID0002GZ; UID0003P2; BaramApp/Application classes; Application/WinMain files; relevant manual coverage and ignored-ledger rows.
- Generated/tracker checks: read-only Application.cpp hash/header/UID counts; read-only research tracker target row; read-only manual `by-memory`, `by-class`, and `by-file` coverage rows.
- Prior-report checks: exact search terms and 19 roots listed in Supporting Research; 42 central matches classified, with zero active/legacy-root matches.
- Failed/unavailable checks: the earlier `49ac345c` worker was unreachable and work paused before evidence collection. No evidence from that session is used. One client-side malformed JSON-RPC attempt incorrectly serialized PowerShell's reserved `$args`; it was corrected before any valid bounded call and supplies no evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time MCP database `46dda60b` was healthy and ready; dead `49ac345c` is excluded. | Direct | Fresh idb_list/server_health/bounded bytes at `00:42:52`. | UID00019H Evidence; UID0004R1 Evidence | incorporate | applied | Evidence-time health/outage boundary is present on target and child; child command `000000012645` and target command `000000012656` passed. No later availability claim is made. |
| C02 | Parent range is exactly `0x004f5f20-0x004f66fb`, size `0x7db` / 2,011, SHA256 `411D5F4D2A278603ED8C80DCB1F24BFAF429AA14A66D9BD9FAE797BA6AC35B7D`. | Direct | Four MCP byte chunks totaling 2,011 bytes. | UID00019H Range/byte table | incorporate | applied | Target command `000000012656` passed with exact range, both size forms, full hash, and exhaustive partition table. |
| C03 | Predecessor padding is `0x004f5f17-0x004f5f20` nine `cc`; successor padding is `0x004f66fb-0x004f6700` five `cc`; neither belongs to the parent. | Direct | MCP bytes/hashes and boundary lookup. | UID00019H boundary prose; coverage text | incorporate | applied | Target command `000000012656` passed with exact excluded spans/hashes. The report retains the exact historical supervisor handoff; supervisor command `000000012704` applied the reconciled by-memory parent/child/padding rows with exit `0`, `ok:1`. B003 did not edit manual coverage. |
| C04 | The range contains one raw 46-byte constructor plus exactly six modeled functions and no other function starts. | Direct | entity_query total 6; 15 lookup probes; raw instruction scan. | UID00019H inventory | incorporate | applied | Target command `000000012656` passed with raw/modelled distinction and all seven executable bodies in address order. |
| C05 | UID0002PZ remains exact source-ready BaramApp construction with Application base initializer; raw vptr stores are compiler output. | Strong | 17 instructions, no start xref, WinMain corroboration, current formal. | UID00019H child table; BaramApp support | already-present | already-present | Verify-only UID0002PZ reread at SHA256 `6477D0491A086010084035B575BA363B21CB799C6F8330481A9B087FEC03D2E2`; target/BaramApp synchronization preserved its `89/92` source body and compiler exclusions. |
| C06 | UID0002Q0 remains a source `void` BaramApp callback despite Hex-Rays' pointer-return guess. | Direct/strong | Decorated callback vtable, wrapper target/object stores, callback decompile. | UID00019H child table; BaramApp support | already-present | already-present | Verify-only UID0002Q0 reread at SHA256 `E1821C5023DC455C35DAF4EF9CFBFF47CB0A9AE6B94DD797D6248B411AA91152`; target/BaramApp prose preserves the decorated-type override and `void` formal. |
| C07 | UID0002H7 remains exact `Application::Startup`, with wrapper creation at `0x004f63e6-0x004f63fa` and current source order. | Strong | Fresh 120-line decompile, 48 refs, current formal/support. | UID00019H child table; Application file | already-present | already-present | Verify-only UID0002H7 remains SHA256 `01885FE7CFB22BBC19369A60D6881083C90692651C5306B3DB8F78037ACF2926`; historical B003 command `000000012664` and external read-only checkpoint `000000012699` each generate one definition. |
| C08 | UID0002H8 remains exact `Application::Shutdown`, including six layer detach paths and final CleanupResources call. | Strong | Fresh 75-line decompile, current formal/support. | UID00019H child table; Application file | already-present | already-present | Verify-only UID0002H8 remains SHA256 `DF47B7F3528DAF49A10718A0BECB123BB0394C043A6773726B2FA2BCB2EB62F0`; historical B003 command `000000012664` and external read-only checkpoint `000000012699` each generate one definition. |
| C09 | `0x004f66b0-0x004f66b5` is a unique one-instruction compiler EH cleanup thunk, not padding or source. | Direct | Function size 5, bytes/hash, disasm/decompile, exact-pattern uniqueness, sole EH xref. | UID0004R1; UID00019H; ignored ledger; WinMain/ApplicationDestructor support | incorporate | applied | UID0004R1 registration `000000012645`, target `000000012656`, ignored ledger `000000012657`, WinMain memory `000000012659`, WinMain file `000000012660`, ApplicationDestructor `000000012661`, BaramApp `000000012662`, and Application `000000012664` all passed with exact UID/range/hash/route/no-code detail. Read-only rebase confirms those facts remain in externally advanced `by-memory/-ignored.md` SHA256 `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232`; B004's UID0003U7 addition is unrelated. |
| C10 | UID0002Q1 remains separate secondary-view adjustor glue and must not absorb C09. | Direct | Bytes `83 e9 04 e9 03 00 00 00`, secondary vtable-only route. | UID00019H child table | already-present | already-present | Verify-only UID0002Q1 reread at SHA256 `F9CC5E30ABFB17FA06E67150C5D2155AB3B7AC37C7A8F23BB7B26A9852440C92`; target command `000000012656` keeps it separate after UID0004R1. |
| C11 | UID0002Q2 remains compiler scalar-deleting glue covered by BaramApp/Application destructor source relationships. | Direct | Fresh decompile/disassembly, flags, vtable routes, three callees. | UID00019H child table; BaramApp/Application file support | already-present | already-present | Verify-only UID0002Q2 reread at SHA256 `016DCA53FD045A06197831AA0A5CC759F83444312F0455381C56EE2607F5C058`; bounded support commands `000000012661`, `000000012662`, and `000000012664` preserve its covered-by marker and compiler exclusions. |
| C12 | BaramApp primary/secondary/callback vtable cells exactly support the constructor, virtual methods, destructor routes, and source `void` callback type. | Direct | 18 u32 reads, IDA names, xrefs. | UID00019H evidence; BaramApp support | incorporate | applied | Target command `000000012656` and BaramApp command `000000012662` passed with exact table/callback/lifetime relationships; verify-only UID0003P2 remains SHA256 `E54A20A78FA12FBFE645677C0802ACD0D82D7BFF9F837064C432CDC7BA210AFD`. |
| C13 | Caller/xref graph is complete: WinMain calls Startup/Shutdown and owns cleanup EH; Startup stores callback; vtables route virtual methods/destructors. | Direct | 14 xref queries, 19 refs; six callee queries. | UID00019H xref table; support docs | incorporate | applied | Target `000000012656`, WinMain memory/file `000000012659`/`000000012660`, ApplicationDestructor `000000012661`, and BaramApp `000000012662` passed with the complete caller/source-cause graph. |
| C14 | UID00019H is a mixed-owner audit index and must become `RECONSTRUCTABLE:FALSE`, owner `NONE`, no emitter, blank formal. | Strong | Complete partition, by-structure container rule, generated output. | UID00019H metadata/formal/summary | incorporate | applied | Target command `000000012656` passed at `92/94`, owner `NONE`, `FALSE`, blank emitter/position/R0, `Nested:0`, and exact Item Summary. Historical B003 command `000000012664` and external read-only checkpoint `000000012699` each have zero UID00019H rows. |
| C15 | Parent `Nested:0`, first child `+4`, later children `0`, successor UID00019I `-4` preserve the address-sorted relative cumulative level. | Direct | Current rows and ordered insertion location. | UID00019H/new child/coverage prose | incorporate | applied | Commands `000000012645` and `000000012656` passed with UID0004R1 `Nested:0`, parent `0`, preserved first-child `+4`, later-child `0`, and successor `-4` proof. |
| C16 | Source placement is split: Application.cpp for Application/BaramApp children; WinMain.cpp is context for UID0004R1; parent has no source file. | Strong | Existing routes, EH xref, exact owners. | UID00019H Source Placement; Application/WinMain files | incorporate | applied | Target `000000012656`, WinMain `000000012659`/`000000012660`, BaramApp `000000012662`, and Application `000000012664` passed with no parent/child emitter and exact source-cause exclusion; external checkpoint `000000012699` preserves zero parent/child generated rows. |
| C17 | Final Application.cpp methods are unique and marker-free; only the historical UID00019H marker was removed while child definitions remain once. | Direct | Generated SHA/header/count audit. | UID00019H generated expectations; file support | incorporate | applied | Historical B003 waited command `000000012664` produced Application SHA256 `0406D1CDA03216E7471580100E5B834C5B5226959B6BA1E1FED133F8AE30FE60` and WinMain SHA256 `65DCFDBA1990F2346D28B1FF3BD11346CE5D401FC072C88BF718CB96BD06923C`. External read-only checkpoint `000000012699` at `2026-07-15T01:54:32-04:00` produced Application `AB554D3AF0F804F53BE5ED25A546F494B444914F5FF7991FC4CC1D490E4DC1EE` and WinMain `D1472FCCB9A0B75DDF4AEE0A1AAE27D865A35AF9BE44A044633207C39AA5645A`, preserving one each UID0002PZ/2Q0/2H7/2H8/2Q2 and four source definitions, zero UID00019H/0004R1/2Q1, zero Application empty markers, one unrelated WinMain UID00032A marker, and zero raw thunk text. Command `000000012699` was not issued by B003. |
| C18 | Target score improves `86/90 -> 92/94`; UID0004R1 is `92/94`; existing child/support scores remain unchanged. | Strong | Blocker audit and complete evidence closure. | Target/new child score sections; support prose | incorporate | applied | Commands `000000012645` and `000000012656` passed the exact new scores; commands `000000012657` and `000000012659`-`000000012664` preserve all support scores/routes. Rebase hash audit confirms seven destinations unchanged and only `by-memory/-ignored.md` externally advanced through unrelated B004 content. |
| C19 | B013's `TRUE` aggregate-marker conclusion and stale manual rows are superseded; all positive/negative historical child facts remain. | Strong | Current structure rule, MCP, generated/manual audit, report search. | UID00019H history; coverage text | historicalize | applied | Target command `000000012656` historicalized the aggregate marker without deleting old research. The exact handoff remains preserved below as historical evidence; supervisor commands `000000012704`-`000000012706` applied the reconciled manual rows with exit `0`, `ok:1`. B003 edited no manual coverage. B004's later UID0003U7 ignored-ledger addition remains unrelated preserved concurrent content. |
| C20 | Exact supervisor-owned coverage replacements, two formal blocks, callback destinations, validators, generated assertions, and lifecycle boundaries are callback-complete. | Direct | This report's R0/R1, coverage section, checklist. | Report and listed destinations | incorporate | applied | R0/R1 remain byte-for-byte blank managed blocks; all eight ordinary destinations retain scoped-validator proof; historical B003 final waited command is `000000012664`; external read-only checkpoint `000000012699` preserves generated semantics; supervisor coverage validators `000000012704`-`000000012706` passed; all checklist items remain checked; all leases are released; lifecycle wording is external-state neutral. |

## Positive Evidence Summary

- Every one of 2,011 bytes is assigned to a source child, compiler child, or exact parent-only padding span.
- The fresh function inventory exactly matches existing children except for `sub_4F66B0`, making the required split addition bounded and mechanical.
- Decorated vtable names and direct wrapper stores resolve the callback's source class and `void` signature more strongly than Hex-Rays' unused return register.
- WinMain EH instructions at `0x00600fc0` load the stack BaramApp local and jump at `0x00600fc6` to `sub_4F66B0`; the thunk itself only jumps to ordinary Application destruction.
- Existing exact source children already emit once through current class/file routes, proving the aggregate marker is unnecessary.

## IDA MCP Facts

- Health: database `46dda60b`, `status:ok`, analysis/Hex-Rays/strings ready at evidence collection time.
- Parent size/hash: `0x7db` / 2,011 bytes; SHA256 `411D5F4D2A278603ED8C80DCB1F24BFAF429AA14A66D9BD9FAE797BA6AC35B7D`.
- Modeled functions: `0x004f5f50` size `0x5f`; `0x004f5fb0` size `0x4e0`; `0x004f6490` size `0x215`; `0x004f66b0` size `0x5`; `0x004f66b5` size `0x8`; `0x004f66c0` size `0x3b`.
- Raw constructor: `0x004f5f20-0x004f5f4e`, 17 instructions, 46 bytes, SHA256 `F28513D67298E6F222B1B5CEF57207484A48055823FD3B6E38443627F60A6A63`, no IDA function/start xref.
- Internal padding: `0x004f5f4e-0x004f5f50` two `cc`; `0x004f5faf-0x004f5fb0` one `cc`; `0x004f66a5-0x004f66b0` eleven `cc`; `0x004f66bd-0x004f66c0` three `cc`.
- New-child bytes: `e9 bb d2 f6 ff`, SHA256 `0505B9DEE2A5853919270FF7492420AF7218237D70A193234D113A4FD822A222`; exact pattern occurs once; no VA `b0 66 4f 00` or RVA `b0 66 0f 00` pointer hit.
- New-child route: sole xref at WinMain EH `0x00600fc6`; no callees; decompile contains only `sub_463970(this)`.
- Vtable dwords: primary COL `0x0061d114 -> 0x00649fbc`; primary slots `0x0061d118 -> 0x004f66c0`, `0x0061d11c -> 0x004f4b10`, `0x0061d120 -> 0x0041b6c0`, `0x0061d124 -> Startup`, `0x0061d128 -> Shutdown`, `0x0061d12c -> OnActivate`, `0x0061d130 -> OnDeactivate`; secondary COL `0x0061d134 -> 0x0064a014`, slots `0x0061d138 -> 0x004f66b5`, `0x0061d13c -> 0x00465ce0`.
- Callback table: COL `0x0061d234 -> 0x0064a028`; IDA name at `0x0061d238` is `??_7?$PlainMemberFunctionObject0@P8BaramApp@@AEXXZV1@@@6B@`.
- Negative IDA facts: no function/xref at raw constructor start, no extra in-range function, no cleanup-thunk data/vtable pointer, no ordinary cleanup caller, no evidence for aggregate source, no reason to mutate IDA.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f5f20-0x004f66fb` | UID00019H target | Mixed-owner split index | FALSE | NONE | `92/94` | implemented |
| `0x004f5f20-0x004f5f4e` | UID0002PZ | BaramApp constructor source | TRUE | UID00000V | `89/92` | preserve |
| `0x004f5f4e-0x004f5f50` | parent-only | two-byte alignment | FALSE | UID00019H index | reviewed | preserve |
| `0x004f5f50-0x004f5faf` | UID0002Q0 | BaramApp startup-logo callback | TRUE | UID00000V | `90/92` | preserve |
| `0x004f5faf-0x004f5fb0` | parent-only | one-byte alignment | FALSE | UID00019H index | reviewed | preserve |
| `0x004f5fb0-0x004f6490` | UID0002H7 | Application::Startup | TRUE | UID00000D | `90/91` | preserve |
| `0x004f6490-0x004f66a5` | UID0002H8 | Application::Shutdown | TRUE | UID00000D | `90/92` | preserve |
| `0x004f66a5-0x004f66b0` | parent-only | eleven-byte alignment | FALSE | UID00019H index | reviewed | preserve |
| `0x004f66b0-0x004f66b5` | UID0004R1 / `WinMainBaramAppCleanupThunk.md` | WinMain EH cleanup thunk | FALSE | UID0000PA | `92/94` implemented | registered |
| `0x004f66b5-0x004f66bd` | UID0002Q1 | secondary deleting-destructor adjustor | FALSE | UID00000V | `86/92` | preserve |
| `0x004f66bd-0x004f66c0` | parent-only | three-byte alignment | FALSE | UID00019H index | reviewed | preserve |
| `0x004f66c0-0x004f66fb` | UID0002Q2 | scalar deleting destructor compiler wrapper | TRUE with covered-by marker | UID00000V | `88/92` | preserve |

Subrange SHA256 inventory:

| Range | Bytes | SHA256 |
| --- | ---: | --- |
| constructor | 46 | `F28513D67298E6F222B1B5CEF57207484A48055823FD3B6E38443627F60A6A63` |
| callback | 95 | `463BDC7CB0FAC14CCDD4C1AB8A231451066BCE577E4FEBB507D00FB01D500C53` |
| Startup | 1,248 | `92988423401F8713EA9718B607823137C76D9219B7A916819971842E5C8EE340` |
| Shutdown | 533 | `F40A8B0CE1A532AF4DCC0450C24ED68C963A74A1D1FDBD538DF189260108D5DC` |
| WinMain EH cleanup thunk | 5 | `0505B9DEE2A5853919270FF7492420AF7218237D70A193234D113A4FD822A222` |
| adjustor thunk | 8 | `820EF0D78C6A2747C66A9EC837107D7CF1C761DB688C34A4A3725FB0778A5784` |
| scalar deleting destructor | 59 | `F5004BACF5D054695D5E5BA75F7B94D345E1311414923C24E53526D7CC8C91DB` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f5f20` | no xrefs | Raw constructor has no direct entry route. |
| `0x004f5f50` | data store `0x004f63ec` in Startup | Callback target stored in member-function wrapper. |
| `0x004f5fb0` | WinMain call `0x004f5e78`; vtable cell `0x0061d124` | Direct and virtual Startup routes. |
| `0x004f6490` | WinMain call `0x004f5e8e`; vtable cell `0x0061d128` | Direct and virtual Shutdown routes. |
| `0x004f66b0` | WinMain EH jump `0x00600fc6` only | Compiler cleanup of stack BaramApp local. |
| `0x004f66b5` | secondary vtable cell `0x0061d138` only | Compiler adjustor route. |
| `0x004f66c0` | adjustor jump `0x004f66b8`; primary vtable cell `0x0061d118` | Scalar deleting wrapper routes. |
| `0x00463310` | WinMain `0x004f5cca`; raw constructor `0x004f5f33` | Base Application construction. |
| `0x00463970` | WinMain `0x004f5e44`; cleanup thunk `0x004f66b0`; scalar wrapper `0x004f66c6` | Three ordinary Application destruction routes. |
| `0x0061d118` | writes at WinMain `0x004f5ccf` and raw constructor `0x004f5f38` | Primary BaramApp vptr installation. |
| `0x0061d138` | writes at WinMain `0x004f5cd9` and raw constructor `0x004f5f40` | Secondary BaramApp vptr installation. |
| `0x0061d238` | Startup store `0x004f63e6` | Decorated void-member callback wrapper vtable. |

## Documentation Evidence And IDA Status

- Current exact child docs are behaviorally consistent with fresh MCP. Their source blocks, source/compiler splits, and scores were preserved.
- Historical pre-callback UID00019H `TRUE`/Application emitter/aggregate-marker metadata was stale under the current reviewed-container rule. The implemented target is now ownerless, false, non-emitting, and blank-formal.
- Historical pre-callback target text accurately described `0x004f66b0` as code but stopped short of exact child registration; B014 offered an ignored row as a fallback. Current UID0004R1 and the linked ignored-ledger row supersede that fallback with exact registered coverage.
- Historical pre-application manual coverage was stale for the target, five of six existing child scores, WinMain, ApplicationDestructor, BaramApp class, and Application/WinMain file rows. The exact handoff remains below; current readback confirms the supervisor-applied by-memory, by-class, and by-file rows preserve the accepted facts at same-or-greater detail.
- Historical B003 command `000000012664` proves the callback result, and read-only external checkpoint `000000012699` observed at `2026-07-15T01:54:32-04:00` preserves the same semantics: Application Startup, Shutdown, constructor, callback, and scalar marker are present exactly once; UID00019H and UID0004R1 are absent, so the historical parent marker remains removed without compiler-thunk output. The external checkpoint is captured evidence, not an indefinite latest-state assertion.
- No current documentation or IDA fact supports deleting, merging, moving, or rewriting any existing source child.

## Ranked Ownership Analysis

### 1. No canonical owner for UID00019H

- Evidence for: the parent is an address index over BaramApp, Application, WinMain EH, compiler wrappers, and padding; it has no source declaration or emitted range of its own.
- Evidence against: most source children currently end at the Application.cpp root.
- Decision: select `CANONICAL_OWNER:NONE`; output routing is not canonical ownership, and one exact child is WinMain-caused.

### 2. UID0000HG Application file as parent context

- Evidence for: constructor/callback/startup/shutdown/scalar/vtable children currently surface to Application.cpp.
- Evidence against: the parent itself is not a source item, and UID0004R1 belongs to WinMain EH context.
- Decision: reject as target canonical owner; retain as child output/source-family support.

### 3. UID0000PA WinMain for UID0004R1 only

- Evidence for: sole inbound edge is a WinMain EH funclet; it loads WinMain's stack BaramApp local before jumping to the thunk.
- Evidence against: thunk target is ApplicationDestructor and bytes sit in the Application/BaramApp cluster.
- Decision: select as semantic context owner for the non-emitting new child only. Physical adjacency and jump target do not override source cause.

### Proposed new file/grouping, if applicable

- Implemented owner/name/path: UID0000PA context; [UID:0004R1] `by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md`.
- Implemented full contents: exact one-instruction compiler/EH cleanup thunk, sole WinMain EH xref, stack-local source cause, ApplicationDestructor target, bytes/hash, negative pointer/caller/callee evidence, and blank no-code formal.
- Candidate related items that belong: only exact `0x004f66b0-0x004f66b5`.
- Candidate related items rejected: UID0002Q1 adjustor thunk, UID0002Q2 scalar wrapper, ordinary Application destructor body, and WinMain source body.
- Standalone, narrow, or broad source-file inference: narrow exact compiler page; no standalone source file or handwritten helper.

## Source Placement

- `app/Application.cpp`: preserve current routes for Application and BaramApp exact source children and compiler marker children.
- `app/WinMain.cpp`: source context that causes UID0004R1 through stack BaramApp lifetime/EH; the child does not emit source into that file.
- UID00019H: no source file or emitter because it is only a mixed address index.
- Rejected placements: separate `BaramApp.cpp` is unproven and unnecessary for this target; `Application.cpp` ownership for UID0004R1 confuses callee with source cause; `BaramApp` class-method ownership invents a method absent from source.
- Remaining uncertainty: exact historical split between Application.cpp and a possible BaramApp.cpp remains a child/file confidence cap only. It cannot change the parent no-source decision.

## Range / Split / Padding / Reclassification Analysis

- Exact parent range: `[0x004f5f20,0x004f66fb)`, `0x7db` / 2,011 bytes, full-range SHA256 above.
- Exact predecessor: `[0x004f5f17,0x004f5f20)`, nine `cc`, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`.
- Exact successor: `[0x004f66fb,0x004f6700)`, five `cc`, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`.
- Parent-only internal padding: two, one, eleven, and three bytes at the four ranges listed in the inventory. These are not children and do not emit.
- Existing children retained exactly: UID0002PZ, 0002Q0, 0002H7, 0002H8, 0002Q1, and 0002Q2.
- New child implemented: UID0004R1 at `0x004f66b0-0x004f66b5`; serial validator registration command `000000012645` preceded links from every existing page.
- Parent impact: target changed from reconstructable aggregate marker to non-emitting mixed split index. No range rename occurred.
- Relative-delta proof, using the local cumulative level before UID00019H as `0`: target `Nested:0` keeps level 0; UID0002PZ `+4` enters child level 4; UID0002Q0/2H7/2H8/0004R1/2Q1/2Q2 all `0` remain level 4; successor UID00019I `-4` returns to level 0. Inserting a `0` child preserves every following level.

## Negative Evidence Summary

- No IDA function, direct xref, VA pointer, or RVA pointer proves an entry route to `0x004f5f20`; this does not negate the complete constructor body.
- No additional function start exists in the 2,011-byte range beyond the six enumerated starts.
- No data/vtable pointer targets `0x004f66b0`; only the WinMain EH tail jumps there.
- No call or independent state in `sub_4F66B0` supports a source helper. Exact `E9 BB D2 F6 FF` is unique, but generic five-byte jump thunks are compiler patterns, not names.
- No evidence makes `0x004f66b0` padding, part of UID0002Q1, a BaramApp virtual slot, or an Application source method.
- No evidence supports aggregate-level C++, a parent `[[CHILDREN]]`, raw vtable/RTTI arrays, explicit vptr stores, hidden delete flags, or EH helper source.
- Nearby Application.cpp output and majority child routing do not prove canonical ownership of the mixed parent.

## IDA Rename / Type / Comment Recommendations

- Implemented documentation-facing name: `WinMainBaramAppCleanupThunk` for `0x004f66b0`; descriptive, not claimed original.
- Optional IDA comment if a separate IDA-maintenance pass is ever authorized: `WinMain EH cleanup tail for stack BaramApp; jumps to Application::~Application.`
- Do not apply a source prototype beyond compiler-recognition context. A synthetic `void __thiscall` helper would overstate source identity.
- Preserve current IDA names for constructor/callback/startup/shutdown/destructor functions for searchability; source-facing names live in documentation/formals.
- No IDA DB edits are requested or performed by this report.

## First-Draft C++ Recommendation

- Eligible for draft C++: no new executable source body. Existing source-ready children retain their accepted formals unchanged.
- R0, target exact formal replacement:

```text
Destination R0: by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R1, UID0004R1 exact formal block after validator registration:

```text
Destination R1: by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason exact behavior is preserved: exact source children continue to emit; compiler-generated lifetime/destructor machinery is regenerated from WinMain's stack local and class/destructor declarations; parent and new compiler child emit nothing.
- Original-era shape: a normal stack `BaramApp` object in WinMain plus class destructors naturally causes old MSVC EH cleanup thunks. Handwriting the thunk would be less source-faithful.
- Inferred names/types used: only the documentation title `WinMainBaramAppCleanupThunk`; no C++ identifier is introduced.
- Naming style evidence: project docs use role-based PascalCase names for exact compiler helper pages while retaining raw address facts.
- Third-party import directive: not applicable; this is NexusTK/MSVC compiler output, not embedded third-party source.
- Exact no-code proof: target is a non-source index. UID0004R1 is one tail jump reached only from WinMain EH, has no ordinary caller/callee/data route, and is regenerated from stack-object lifetime. UID0002Q1 and UID0002Q2 remain compiler products with their existing no-code/covered-by dispositions.

## Final Recommendation

- Implemented target `92/94`, owner `NONE`, `FALSE`, blank emitters/position/formal, `Nested:0`, exhaustive byte/function/xref/source-route table, and a non-emitting split-index Item Summary.
- UID0004R1 was registered through validator and applies `92/94`, owner `0000PA`, `FALSE`, blank emitters/position/formal, `Nested:0`, exact bytes/hash/EH route/no-code proof.
- All six existing children and four internal padding spans were preserved exactly.
- Bounded support pages were synchronized without changing their existing scores/routes/formals or unrelated concurrent content.
- No report or implementation item remains dependent on unspecified investigation. External supervisor/validator state determines acceptance, coverage application, report path/count/status, execution, move, and archive state; this artifact neither asserts nor directs those states.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`.
- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, R0, `Nested:0`.
- Exact Item Summary: `Non-emitting mixed-owner split index over exact BaramApp constructor/callback, Application startup/shutdown, WinMain EH cleanup thunk, BaramApp destructor wrappers, and four parent-only alignment spans; complete byte/hash/xref/source-route inventory prevents duplicate aggregate output.`
- Applied detail: full range hash/table, function and xref inventories, UID0004R1 link after registration, source placement, relative nesting proof, generated expectations/results, no-code proof, historical report classifications, rejected alternatives, and score rationale.
- Applied history: B013 `TRUE` aggregate-marker implementation is explicitly superseded by current container rules and full split; all child-specific evidence and historical score changes remain.

## Recommended Support Doc Changes

- Registered UID0004R1 serially with R1 and all report-level C09 facts. Exact Item Summary: `Non-emitting compiler-generated WinMain EH cleanup thunk for the stack BaramApp local; exact one-instruction five-byte tail jump to Application::~Application, sole inbound EH edge, no data/pointer route, and no handwritten source body.`
- Updated `by-memory/-ignored.md`: retained the span, replaced broad standalone wording with UID0004R1, fresh bytes/hash, sole WinMain EH xref, no-code replacement source, and exact parent/successor topology.
- Updated `by-memory/0x004f5c80-0x004f5f17.WinMain.md`: added compiler/EH support caused by `BaramApp app(...)`, exact `lea ecx,[ebp+var_1A88]; jmp 0x004f66b0`, and preserved `90/92`, formal WinMain, owner/emitter, range, and unrelated evidence.
- Updated `by-file/WinMain.md`: added the issued non-emitting child to Proposed Contents/Boundary Notes and preserved `89/88`, path, and unrelated content.
- Updated `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`: added exact caller `0x004f66b0` as WinMain stack-BaramApp EH cleanup route and preserved `89/92`, formal marker, owner/emitter, and cleanup-order blockers.
- Updated `by-class/BaramApp.md`: added the compiler lifetime relationship while preserving `86/90`, current class marker/`[[CHILDREN]]`, exact methods, fields, and source split. The callback goal's stale `UID00000C` spelling was not applied; the current validator identity `UID00000V` was preserved.
- Updated `by-file/Application.md`: reclassified UID00019H inventory as a non-emitting mixed index, added exact child boundary and WinMain source-cause exclusion, and preserved `89/92`, source path, child routes, and unrelated content.
- Verify-only rereads found no contradiction and no edits were made to UID0002PZ, UID0002Q0, UID0002H7, UID0002H8, UID0002Q1, UID0002Q2, UID0003P2, Application class, operator new/delete, TerminalPane, ScreenPane, callback template, vtable/RTTI, or generated files.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/90`, owner/emitter `0000HG`, `TRUE`, marker formal, `Nested:0`.
- Implemented target: `92/94`, owner `NONE`, `FALSE`, blank emitter/position/formal, `Nested:0`.
- Implemented UID0004R1: `92/94`, owner `0000PA`, `FALSE`, blank emitter/position/formal, `Nested:0`.
- Reason target not lower: every byte, child, function, xref, source cause, compiler/source distinction, generated effect, support destination, and manual row is resolved.
- Reason target not `95/95`: stripped binary cannot prove exact original file split, source callback spelling, raw constructor liveness, or compiler's original internal thunk label.
- Score-improvement attempt:
  - Aggregate purpose: resolved by current container rule and full partition.
  - Missing child: resolved by serial registration command `000000012645` as UID0004R1.
  - Raw body liveness: exhausted function/xref/pointer/WinMain corroboration routes; preserved as confidence cap.
  - Callback type/name: type resolved by decorated wrapper; name remains accepted inferred spelling, not a parent blocker.
  - Compiler/source products: resolved independently for all three destructor-support ranges.
  - Owner/source placement: resolved as ownerless parent, Application/BaramApp child routes, and WinMain compiler context.
  - Formal C++: resolved as exact blank R0/R1 with existing child formals unchanged.
  - Nesting/order: resolved mechanically without changing following levels.

## Open Questions With Attempted Resolution

- Is `0x004f5f20` live as an independently called constructor? No current route proves it. Checks: IDA function lookup, direct xrefs, absolute VA/RVA patterns, and current WinMain construction. Resolution: preserve existing source-ready body but retain liveness confidence cap; parent split is unaffected.
- Was BaramApp originally in `Application.cpp` or `BaramApp.cpp`? Checks: class/file docs, address locality, generated route, constructor/callback/activation methods, vtable region, and prior reports. Resolution: current Application.cpp route remains strongest; no parent route is needed, so exact historical split cannot create a callback blocker.
- What was the original name of `sub_4F66B0`? Compiler-generated EH thunks generally have no source identifier. Checks: body, sole EH xref, pointer searches, function names, analog cleanup pages. Resolution: descriptive documentation title only; no source name or C++ body.
- Does the aggregate need `[[CHILDREN]]`? Checks: current emitter graph and generated Application.cpp. Resolution: no; exact children already surface through class/file routes, and a false parent cannot emit.
- Does BaramApp need a complete class declaration in this callback? The target does not introduce any class field, virtual, or source method; current exact children already emit through the accepted class marker and `[[CHILDREN]]`. Fresh vtable/layout checks found no contradiction. Resolution: the class formal remained verify-only and only bounded compiler-lifetime prose was added. This is not a target blocker or deferred required code item.
- Remaining uncertainty has no implementation impact beyond confidence caps listed above.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Historical B003-to-supervisor handoff retained verbatim: the following was the exact callback-complete replacement/addition design using real validator-issued UID0004R1 before supervisor application. Current readback confirms the reconciled rows were applied at same-or-greater detail by supervisor commands `000000012704`, `000000012705`, and `000000012706`, all exit `0` / `ok:1`. B003 did not edit manual coverage.

File: `by-memory/-coverage-report.md`. Replace the current UID00019H parent and child block in place, between existing predecessor padding `0x004f5f17-0x004f5f20` and successor padding `0x004f66fb-0x004f6700`, with:

```text
    - [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) 0x004f5f20-0x004f66fb | mixed-owner split index | BaramAppAndApplicationStartup : ignored : 92% : very strong : Non-emitting mixed-owner index over exact BaramApp constructor/callback, Application startup/shutdown, WinMain stack-BaramApp EH cleanup thunk, BaramApp destructor wrappers, and four internal alignment spans; evidence-time MCP database 46dda60b accounts for all 0x7db/2011 bytes with full-range SHA256 411D5F4D2A278603ED8C80DCB1F24BFAF429AA14A66D9BD9FAE797BA6AC35B7D, exact xrefs/source routes, owner NONE, blank emitter/formal, and unchanged relative nesting.
        - [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md) 0x004f5f20-0x004f5f4e | raw constructor | BaramAppConstructorRaw : reconstructable : 89% : very strong : Source-ready out-of-line BaramApp constructor; exact 46-byte body forwards three arguments to Application, compiler-installs primary/secondary BaramApp vptrs, has no promoted function/start xref, and emits an empty derived constructor with Application base initializer.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f5f4e-0x004f5f50 | padding | BaramAppConstructorRaw to BaramAppTerminalPaneCallbackFactory alignment : ignored : 100% : very strong : Two exact 0xcc bytes, SHA256 E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2.
        - [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md) 0x004f5f50-0x004f5faf | callback method | BaramAppTerminalPaneCallbackFactory : reconstructable : 90% : very strong : Source-ready void BaramApp startup-logo completion callback; decorated PlainMemberFunctionObject0 type and Startup wrapper stores prove member/signature, and the body restores cursor visibility then constructs TerminalPane.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f5faf-0x004f5fb0 | padding | BaramAppTerminalPaneCallbackFactory to ApplicationStartup alignment : ignored : 100% : very strong : One exact 0xcc byte, SHA256 1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6.
        - [UID:0002H7][0x004f5fb0-0x004f6490.ApplicationStartup](by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md) 0x004f5fb0-0x004f6490 | class method | ApplicationStartup : reconstructable : 90% : very strong : Exact 0x4e0-byte Application::Startup with WinMain/vtable routes, singleton construction order, screen/layer setup, startup-logo branch, typed BaramApp callback wrapper, TerminalPane fallback, compiler-EH exclusions, and source-ready formal body.
        - [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md) 0x004f6490-0x004f66a5 | class method | ApplicationShutdown : reconstructable : 90% : very strong : Exact 0x215-byte Application::Shutdown with phase/event/IME teardown, six layer detach/destroy order, MainMenu/image-library/singleton cleanup, packet-sender termination, CleanupResources tail, and source-ready formal body.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f66a5-0x004f66b0 | padding | ApplicationShutdown to WinMainBaramAppCleanupThunk alignment : ignored : 100% : very strong : Eleven exact 0xcc bytes, SHA256 3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943.
        - [UID:0004R1][0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk](by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md) 0x004f66b0-0x004f66b5 | compiler/EH cleanup thunk | WinMainBaramAppCleanupThunk : ignored : 92% : very strong : Non-emitting five-byte WinMain EH cleanup tail for the stack BaramApp local; exact bytes e9 bb d2 f6 ff uniquely jump to Application::~Application, sole inbound edge is WinMain EH at 0x00600fc6, no ordinary caller/callee/data pointer exists, owner context is WinMain, and handwritten source is rejected.
        - [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md) 0x004f66b5-0x004f66bd | compiler-generated | BaramAppDeletingDestructorThunk : ignored : 86% : very strong : Non-emitting secondary-base deleting-destructor adjustor; exact bytes sub ecx,4 then jump to 0x004f66c0, sole route is BaramApp secondary vtable slot 0x0061d138, and class layout/destructor source regenerates it.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f66bd-0x004f66c0 | padding | BaramAppDeletingDestructorThunk to BaramAppScalarDeletingDestructor alignment : ignored : 100% : very strong : Three exact 0xcc bytes, SHA256 E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE.
        - [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md) 0x004f66c0-0x004f66fb | compiler deleting wrapper | BaramAppScalarDeletingDestructor : reconstructable : 88% : very strong : Exact 0x3b-byte compiler scalar deleting destructor with primary/secondary vtable reachability, ApplicationDestructor delegation, delete-flag tests, normal-path project delete, guard branch, and formal covered-by marker rather than handwritten ABI source.
```

Also replace these stale support rows with current metadata and bounded descriptions:

```text
    - [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) 0x004f5c80-0x004f5f17 | process entry | WinMain : reconstructable : 90% : very strong : Product WinMain source with CRT-only caller, stack BaramApp construction, minimap/startup-window/update flow, normal Application lifecycle, Error-pointer catch, and exact compiler-EH route 0x00600fc0-0x00600fc6 to the non-emitting WinMainBaramAppCleanupThunk.
        - [UID:0002GZ][0x00463970-0x004639c4.ApplicationDestructor](by-memory/0x00463970-0x004639c4.ApplicationDestructor.md) 0x00463970-0x004639c4 | class destructor | ApplicationDestructor : reconstructable : 89% : very strong : Exact ordinary Application destructor with handle/string/MSGHandler/global cleanup, LObject tail, formal no-code marker because a complete class-layout expression is not established, and callers from WinMain normal cleanup, WinMainBaramAppCleanupThunk, and BaramApp scalar wrapper.
```

File: `by-class/-coverage-report.md`. Replace current UID00000V row:

```text
- [UID:00000V][BaramApp](by-class/BaramApp.md) : reconstructable : 86% : very strong : Game-client Application specialization routed through Application.cpp; source-ready constructor, startup-logo callback, activation/deactivation methods, primary/secondary vtables, scalar/deleting wrappers, and WinMain stack-lifetime EH cleanup relationship are documented, while the class marker/children preserve exact source and compiler-output boundaries without inventing vptr, RTTI, deleting-flag, or EH source.
```

File: `by-file/-coverage-report.md`. Replace current UID0000HG and UID0000PA rows:

```text
- [UID:0000HG][Application](by-file/Application.md) : reconstructable : 89% : very strong : NexusTK application-shell source route for Application and BaramApp exact children; startup/shutdown, constructor/callback, lifecycle, helpers, globals, and compiler-marker products are documented, while UID00019H is a non-emitting mixed index and its WinMain EH cleanup child is excluded from Application source ownership.
- [UID:0000PA][WinMain](by-file/WinMain.md) : reconstructable : 89% : strong : Product entry source in app/WinMain.cpp with exact WinMain formal, update/lifecycle/Error handling, stack BaramApp construction, early-exit KeySpeedMgr helper, and semantic ownership of the non-emitting compiler EH cleanup thunk reached at 0x00600fc6.
```

Historical ownership boundary: B003 did not apply these rows because all `-coverage-report.md` files are supervisor-owned manual state. The supervisor subsequently applied and validated the reconciled rows through commands `000000012704`-`000000012706`; the handoff above remains historical evidence rather than a pending directive.

## Follow-Up Actions

- The bounded callback implementation, serial UID registration, scoped validators, final waited generated verification, and same-report claim/checklist reconciliation are complete. No B003 implementation action remains.
- External supervisor manual-coverage application is complete under commands `000000012704`-`000000012706`. External supervisor/validator state continues to own report acceptance, report path/count/status, execution, move, and archive state; this artifact neither asserts nor directs those remaining lifecycle outcomes.
- B003 performed no report execution, probe, count, registry, revalidation, move, archive, or other lifecycle command and did not manually edit coverage, generated, tracker, audit, supervisor, or validator-state files.
- No separate B003 research target is opened by this report.

## Confidence

- Recommendation confidence: `94/100`, very strong.
- Score confidence: `94/100`; `92/94` follows project precedent for fully audited split indices and compiler cleanup children.
- Remaining uncertainty: original source filenames/member spellings and raw constructor liveness. None changes the exact range, missing child, ownerless parent, no-code formals, source routes, or generated expectation.

## Validator Results

- Every changed/new ordinary page received a scoped `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` validation. UID0004R1 was registered before dependent links. The final Application validation included `--wait-generated`.

| Command ID | Timestamp EDT | Scope | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000012645` | `2026-07-15T01:09:55-04:00` | `by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md` | `0`; UID insert successful | Serial new-file registration issued UID0004R1; one file scanned; validator-owned UID/reference/generated work deferred. All report placeholders were replaced before the next validator. |
| `000000012656` | `2026-07-15T01:13:59-04:00` | `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` | `0`; `ok:1` | Applied parent `92/94`, ownerless/non-emitting split-index metadata, blank R0, exhaustive partition/evidence/history, and UID0004R1 link; generated refresh deferred. |
| `000000012657` | `2026-07-15T01:14:46-04:00` | `by-memory/-ignored.md` | `0`; `ok:1` | Indexed UID0004R1 link and exact ignored/compiler disposition. Reported 279 pre-existing `missing_ref_uid` rows, 269 suppressed; no target error; generated refresh deferred. |
| `000000012659` | `2026-07-15T01:15:50-04:00` | `by-memory/0x004f5c80-0x004f5f17.WinMain.md` | `0`; `ok:1` | Applied bounded stack-BaramApp EH cleanup route. Three pre-existing UID00039R missing-reference warnings remained; new UID references indexed; generated refresh deferred. |
| `000000012660` | `2026-07-15T01:16:32-04:00` | `by-file/WinMain.md` | `0`; `ok:1` | Applied exact child/source-cause boundary support; score/path/unrelated content preserved; generated refresh deferred. |
| `000000012661` | `2026-07-15T01:17:19-04:00` | `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md` | `0`; `ok:1` | Applied exact third caller/EH source-cause proof; score/formal/owner/emitter/cleanup blocker detail preserved; generated refresh deferred. |
| `000000012662` | `2026-07-15T01:19:38-04:00` | `by-class/BaramApp.md` | `0`; `ok:1` | Applied bounded compiler-lifetime support while preserving current UID00000V and class formal. Five pre-existing UID0003P5/0003P6 missing-reference warnings remained; generated refresh deferred. |
| `000000012663` | `2026-07-15T01:21:58-04:00` | `by-file/Application.md --wait-generated` | `0`; `ok:1`; refresh complete | Initial Application support validation/refresh. A B003 post-readback caught two prose-only hash transcription errors before return; they were corrected and superseded by command `000000012664`. Two pre-existing UID0003OY warnings remained. |
| `000000012664` | `2026-07-15T01:25:07-04:00` | `by-file/Application.md --wait-generated` | `0`; `ok:1`; refresh complete | Final scoped/waited validation after exact digest correction. Validator rebuilt its registry/reference index, refreshed generated metadata and C++, and updated validator-owned tracker/stat projections. Two pre-existing UID0003OY warnings remained; no callback-scoped error was reported at that B003 epoch. |

External supervisor manual-coverage validators, not B003 commands:

| Command ID | Scope | Exit / ok | Current-state result |
| --- | --- | --- | --- |
| `000000012704` | `by-memory/-coverage-report.md` | `0`; `ok:1` | Applied the accepted UID00019H mixed-index block, exact children including UID0004R1, four internal padding rows, and bounded UID00019G/UID0002GZ support. Current readback preserves the accepted range, scores, source/compiler distinctions, and no-code dispositions. |
| `000000012705` | `by-class/-coverage-report.md` | `0`; `ok:1` | Applied the BaramApp row with constructor/callback/activation/destructor/vtable/read-only-data and WinMain stack-lifetime EH evidence at same-or-greater detail. |
| `000000012706` | `by-file/-coverage-report.md` | `0`; `ok:1` | Applied the Application and WinMain rows, preserving the owner/source split, UID00019H non-emitting status, UID0004R1 WinMain semantic ownership, and unrelated existing source-family detail. |

- Historical B003 generated snapshot: command `000000012664`, refreshed `2026-07-15T01:25:07-04:00`, foreground generated refresh. It remains the callback's waited-validator proof and produced Application SHA256 `0406D1CDA03216E7471580100E5B834C5B5226959B6BA1E1FED133F8AE30FE60` and WinMain SHA256 `65DCFDBA1990F2346D28B1FF3BD11346CE5D401FC072C88BF718CB96BD06923C`.
- External read-only generated checkpoint observed during this report rebase: command/header `000000012699`, refreshed `2026-07-15T01:54:32-04:00`, foreground generated refresh. This was a supervisor/B004-era validator epoch, not a command issued by B003, and is recorded as a bounded snapshot rather than an indefinite current/latest assertion.
- External-checkpoint `Application.cpp`: SHA256 `AB554D3AF0F804F53BE5ED25A546F494B444914F5FF7991FC4CC1D490E4DC1EE`, 885 lines; UID0002PZ/2Q0/2H7/2H8/2Q2 each once; UID00019H/0004R1/2Q1 zero; `BaramApp::BaramApp`, `BaramApp::OpenTerminalPaneAfterStartupLogo`, `Application::Startup`, and `Application::Shutdown` definitions each once; zero empty markers; zero cleanup-thunk title/address text.
- External-checkpoint `WinMain.cpp`: SHA256 `D1472FCCB9A0B75DDF4AEE0A1AAE27D865A35AF9BE44A044633207C39AA5645A`, 74 lines; one `WinMain` definition and one `BaramApp app(...)`; UID00019H/0004R1 and cleanup-thunk title/address text zero. The one `Empty Emitter Marker` is unchanged verify-only UID00032A `DestroyKeySpeedMgr` support and is unrelated to this callback.
- Rebase destination audit: seven ordinary destination hashes remain byte-identical to the callback snapshot. `by-memory/-ignored.md` alone advanced from historical B003 hash `FE175D085D57DC695E22A8FF83394686CD9CE533268B795FD9C559BD427B8B85` to externally observed hash `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232` after B004 appended unrelated UID0003U7 alignment `[0x005a3766,0x005a3770)`. UID0004R1 and all four UID00019H parent alignment facts remain exact.
- Prior bounded report-only rebase self-audit: all 33 literal `##` headings remained; C01-C20 had 20 rows with zero illegal action/state enums; the checklist had 27 checked and zero unchecked items; placeholder count was zero; report R0/R1 each equaled the corresponding exact managed blank/no-code destination block; and `current_leases.md` had zero B003 rows. Its exact 17-row manual handoff is retained below as historical evidence, while supervisor commands `000000012704`-`000000012706` now prove application. B003 ran no validator, generated refresh, report probe, execute, lifecycle, move, or archive command during either text-only rebase.
- R0/R1 readback: both managed blocks have exact header/BEGIN/END lines and a byte-empty multiline body. Parent and child therefore emit neither marker nor source code.
- Lease proof: each ordinary page was leased only for its own reread/edit/validator and released before the next lease. Application was reacquired only for the bounded digest correction/final validator. Final `current_leases.md` has no B003 row.

## Changed Files

- Created ordinary page: `by-memory/0x004f66b0-0x004f66b5.WinMainBaramAppCleanupThunk.md`, UID0004R1, SHA256 `EC08B116163D46F7D10EAF5B75A26847A010865D18341DE7B1628D098CB14C1F`.
- Modified target: `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`, SHA256 `EEEB9C1693A73103641C12FEB18B28101FDCC7BCCF6F87427DB88FFEE855D2AE`.
- Modified support at B003 callback time: `by-memory/-ignored.md`, historical SHA256 `FE175D085D57DC695E22A8FF83394686CD9CE533268B795FD9C559BD427B8B85`. Externally observed rebase SHA256 is `59D3B77357D6D7B58367A6E26768608E0915B692568B06F64ED6F7599DF49232`; the delta is B004's unrelated UID0003U7 alignment, while UID00019H/UID0004R1 content remains intact.
- Modified support: `by-memory/0x004f5c80-0x004f5f17.WinMain.md`, SHA256 `20A8737CF79BC1D70D1E875C5CE4D9644E46FA413218FE301594115FEDC77085`.
- Modified support: `by-file/WinMain.md`, SHA256 `74FA2A3A0878B94965E6BD55D5D704A8E90345C50ACA9F85BA8F2414EE8EC9CD`.
- Modified support: `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`, SHA256 `1C2F0D6DC591C127377792C1ABB76B9675A14E59543356DD92C90EEF165ACEBB`.
- Modified support: `by-class/BaramApp.md`, SHA256 `D48923168F78C46487B08C61C64CB52B9A767029DF9B62889F6B32C2EA0D073E`.
- Modified support: `by-file/Application.md`, SHA256 `15718649136EE1D2E97A09AC22F077422CFAEB505D97591DA383D0640C239973`.
- Modified same artifact: historical B003 research/implementation-callback path `tools/leaser/Agents/Agent-B003/research/00019H-BaramAppAndApplicationStartup-source-quality.md` before external supervisor lifecycle.
- Renamed ordinary pages: none. UID0004R1 was new-file registered; no existing UID/path was moved.
- Verify-only ordinary pages remained unchanged: UID0002PZ, UID0002Q0, UID0002H7, UID0002H8, UID0002Q1, UID0002Q2, UID0003P2, Application class, operator new/delete, TerminalPane, ScreenPane, callback template, and vtable/RTTI dependencies.
- Restricted manual edits: none. B003 did not manually modify coverage, generated C++, generated reports/tracker, audit/supervisor, validator-state, goal, lifecycle, queue, lock, or archive files. Validator-owned generated/index/stat/tracker side effects are recorded under Validator Results.
- External supervisor changes after B003 callback: `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` were applied/validated by commands `000000012704`, `000000012705`, and `000000012706`, each exit `0`, `ok:1`. These are current external state, not B003 changed files or commands.
- Report execution/lifecycle: B003 ran no execute_report, report probe/count/registry/revalidation, move, archive, or lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted the exact report artifact before implementation authorization.
- [x] Target/support destinations implemented: UID00019H, UID0004R1, by-memory/-ignored.md, UID00019G, UID0002GZ, BaramApp class, Application file, and WinMain file; existing six children and named dependencies remained verify-only.
- [x] Current target state and actual evidence checked are recorded, with pre-callback states explicitly historicalized.
- [x] Claim And Incorporation Ledger C01-C20 uses legal final actions/states and claim-specific destination/validator/generated proof.
- [x] Metadata/scores applied: target `86/90 -> 92/94`; UID0004R1 `92/94`; support scores unchanged.
- [x] Score-limiting blockers were researched to resolution; residual original-name/file/liveness uncertainty remains only as explicit score caps.
- [x] Owner/emitter/reconstructable changes applied: target owner `NONE`, `FALSE`, blank route/formal; UID0004R1 owner `0000PA`, `FALSE`, blank route/formal.
- [x] Exact UID0004R1 was serially registered by command `000000012645`; every placeholder was replaced before dependent validation; no target rename occurred.
- [x] Source placement, exact range/split/padding/reclassification, relative nesting, and no-IDA-mutation conclusions were applied.
- [x] R0/R1 exact managed blank formals and exhaustive no-code proofs were applied and read back.
- [x] Third-party import directive is not applicable because the bytes are NexusTK/MSVC compiler output; both multiline formal bodies remain blank.
- [x] Exact target/support facts were incorporated at report-level detail without dropping concurrent unrelated content.
- [x] Historical/stale assumptions, rejected alternatives, compiler/source distinctions, and positive/negative evidence were preserved.
- [x] Wave2/Wave3 mentions were classified as stale history and were not used as current evidence.
- [x] Open questions are closed or retained only as evidence-backed score caps with no implementation blocker.
- [x] Every changed/new ordinary page passed a scoped validator; historical B003 final waited Application refresh/readback is command `000000012664`. External read-only checkpoint `000000012699` was not run by B003 and preserves the accepted semantics.
- [x] Generated assertions are recorded; the exact supervisor-owned handoff is retained as historical evidence; supervisor commands `000000012704`-`000000012706` applied the reconciled manual rows; B003 did not edit manual coverage.

Implementation callback pass:
- [x] Exact report SHA `C3B7C64441B92A23ACA1638C7EABE97D9D2B45A12F4657EAF377BF1AB4BA3F7D` was accepted by the supervisor for implementation.
- [x] All C01-C20 and accepted target/support details were incorporated at report-level depth.
- [x] Ledger actions/states and implementation proof are terminal and claim-specific.
- [x] Metadata/score/owner/emitter/split/R0/R1 changes are applied; no rename was required; UID0004R1 registration is real and consistent.
- [x] Historical/stale assumptions, rejected alternatives, source/compiler distinctions, and negative evidence are preserved.
- [x] Open questions are resolved or documented as non-blocking evidence-backed uncertainty.
- [x] Validator IDs/timestamps/exits/ok/warnings/side effects and final destination hashes are recorded.
- [x] Final validator-generated Application.cpp/WinMain.cpp refresh and exact count/hash assertions are recorded; manual coverage was not applied by B003 and is now externally applied/validated by supervisor commands `000000012704`-`000000012706`.
- [x] All B003 leases are released; `current_leases.md` has no B003 row.
- [x] Remaining unapplied accepted implementation items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000012710","destination_path":"executed-b-agent-research/B003/00019H-BaramAppAndApplicationStartup-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00019H-BaramAppAndApplicationStartup-source-quality.md","timestamp":"2026-07-15T02:49:17-04:00","uid":"00019H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
