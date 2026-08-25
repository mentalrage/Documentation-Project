# UID0003FA CollectionPane Rectangle Constant Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0003FA **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Primary target: [UID:0003FA][by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md].
- Exact physical disposition: `[0x00624c10,0x00624c20)` is one 16-byte data item whose bytes decode as four little-endian signed 32-bit integers `{6, 14, 161, 62}`. Its SHA256 is `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`.
- Source disposition: the item is a compiler-pooled image of the local POD aggregate initialization `RectBounds rowBounds = { 6, 14, 161, 62 };` in `CollectionPane::OnPaint()`. It is not a standalone global, static member, array, or separately named source object.
- Ownership disposition: canonical owner and emitter are class UID00002X `CollectionPane`, which emits through file UID0000IC `NexusTK/ui/panels/CollectionPane.cpp`. The target uses class position `75`; consuming function UID0003Y6 uses class position `70`.
- Formal target CPP: an exact two-line covered-by marker. Formal target H: blank. The complete consuming method receives dependency-closed formal CPP; its declaration is supplied by the class header route rather than duplicated in the target or method H channel.
- Unified current scores after exact observed B002/B003 overlap reconciliation and the completion callback are target `94/95`, consuming function UID0003Y6 `92/94`, class UID00002X `94/94`, file UID0000IC source-justified `94/94`, UID0001TZ `93/94`, UID000088 `94/94`, UID000089 `94/93`, and direct B003 owner UID0000A1 `92/93`. The broad mixed-range parents remain non-emitting indexes at their current scores.
- IDA handoff: pure public function rename, exact function-regular comment, and exact target address-repeatable comment. No function type, data name, data type, item boundary, stack frame, bytes, or xref mutation is recommended.
- Completion-callback allocation: the exact 125-row twins contain 113 checked/verified rows and 12 unchecked/proposed supervisor-owned coverage/IDA rows. C-FA-033, C-FA-085, C-FA-086, C-FA-108, and C-FA-113..125 are checked only after scoped ordinary validation and physical waited `27/27/0` readback; no unchecked row is represented as implemented or externally executed.

## Supporting Research

- Target, consuming method, class, file, broad range, resource, typed-layout, generated-source, tracker, and manual-coverage pages were read physically from the current project tree.
- Validator commands `24224`, `24301`, `24431`, `24441`, `24506`, `24530`, `24539`, `24682`, `24719`, and `24725` are retained only as dated observations. Repair-time physical observation command `000000024737`, refreshed `2026-08-16T04:45:17-04:00`, found CollectionPane `17/10/7`, PaletteLib `6/6/0` with a complete generated H, and MetaMan `16/16/0` with no generated H. Section 31 records exact repair-time identities without treating that fixed receipt as present or future authority; callback authority is exclusively the latest supervisor-verified waited physical readback.
- Live public IDA MCP supplied current item models, bytes, names, types, all four comment channels, xrefs, unique byte searches, function boundaries, stack frame, vtable cell, decompilation, disassembly, caller/callee profile, and adjacent padding.
- Existing accepted `NewGroupPane::OnPaint()` and `SelfLookPane::OnPaint()` rectangle initializers were used as compiler-pattern controls. They show the same MSVC `movaps` constant-pool load followed by stack-local `RectBounds` storage; the target's established four-int POD layout is represented by exact aggregate initialization.
- UID0001TZ `CollectionPlayerDataLayout` resolves the group-record stride and field meanings. The accepted callback moved its exact structs from CPP to formal H, included `../../util/StringUtil.h` there for by-value `SimpleUString`, and retained `UserPane.h` in the CollectionPane file-root preamble; final generated `UserPane.h` contains all three declarations and generated `UserPane.cpp` contains none. Current UID0003F1 remains `92/95`, emits a non-object covered-by CPP marker through UID0000IC, and reconciles all 14 physical uses; UID0001R8 resolves package ownership.
- Current ordinary owner docs establish complete declaration routes for `g_pEPFLib`/`ImageLib::LookupLayoutEntry` and `g_pfnBlitSprite`/`SurfaceSpriteBlitProc`; repair-time command `000000024737` generated `ImageLib.h` and `Surface.h` confirm them. B003 has already completed the PaletteLib route: UID0000A1 H contains the complete class/helper declaration, UID0000A1 CPP is exactly `[[CHILDREN]]`, UID0000RW H contains the one extern, and UID0000RW CPP retains the sole definition plus children. Repair-time command `000000024737` generated a complete `PaletteLib.h` and children-only `PaletteLib.cpp`; the latest supervisor-verified waited readback controls at callback time.
- MetaMan was the distinct unresolved pre-callback case. The accepted callback moved complete MetaMan and MetaTable declarations to guarded owner H channels, changed both class CPP channels to children-only routes, preserved the sole UID0000RL definition, and generated one complete `MetaMan.h` with one manager extern and no storage definition.
- Current ordinary Palette receipts are UID0000A1 `17D1239951C201147FB3B306B537566338C05F39C238AB3AE466B22A66E85606` (28,347 bytes / 227 lines), UID0000RW `A41479994ECD65A3F7A4B9879DBAB20B0782BEE9FC43C84753BFE73BB8105D29` (13,069/112), and UID0000MB `A27CF695C0C42BB9E56862C786B73D41DE7E12ED6F247C3FD4335C012AE31728` (22,846/174). They physically match the executed B003 route at same-or-greater detail and are verify-only for B008.
- The CollectionPane file-root formal preamble directly includes `ImageLib.h`, `Surface.h`, `PaletteLib.h`, `MetaMan.h`, `MetaTable.h`, and `<cwchar>`. Project precedent UID00009A uses `<cwchar>` for the same unqualified `swprintf_s` and `wcslen` spellings, so no local CRT prototypes or reduced dependency declarations are introduced.
- Wave2 and Wave3 material was explicitly treated as stale, ignored, and not used as evidence, lead authority, source text, score support, or implementation guidance for this report.
- Historical B001 reports for UID0002V2 and UID0001HD were treated as dated evidence only. Fresh IDA and current ordinary pages control every final recommendation.
- Assignment-time B002 peer snapshot SHA256 `6FD8F4D4E2C4758188AD9B9D36801BABD45B5B0054D22C1A34C2BEB68EE594E6`, 141,964 bytes / 1,246 lines / 33 headings, was read in full as requested. Concurrent peer repair then produced observed B002 snapshots `B1E513DD181565223E531AB515806A5153BB68AAC0436EEFF4F462C680A4C370` (148,947/1,165), `4525E757DD23C5E25DE200DC3C6FB0D0067E01284741AE35C6558D0051FA3F5D` (149,760/1,166), and `6F6A336AEC6A54016E0730C4466CACCE68B31537A7F90AA8F83FDA777FD7FB4C` (150,278/1,171), all with 33 headings; each relevant delta and the complete 54-row twin were reread. The overlap semantics remained invariant: eight literals/14 uses, four consumers, CollectionPane2, MetaTable/loader closure, manual/generated contracts, D01-D08/P01-P03, 30 checked/applied plus 24 unchecked/proposed rows, and B003-exclusive PaletteLib at `92/93`. Earlier B003 snapshots `85F0B036...`, `AA6BC42D...`, and `05DF4B4C...` are dated pre-execution evidence. The exact current predecessor artifact is `executed-b-agent-research/B003/0003F8-GroupPaneRectConstant-empty-emitter-source-quality.md`, SHA256 `02E615F37ED6D37F6C6515AE0EACE4DF5384B3EA62B4D7ED655F5FFA7DCAED85`, 186,956 bytes / 1,284 lines; validator command `000000024694` executed it at `2026-08-16T03:06:28-04:00`, and the archived-artifact audit records `ARCHIVED_ARTIFACT_AUDIT_PASSED`. Its Palette ordinary, generated, and manual changes are current predecessor state, not a future callback stage.
- The three-report support set overlaps UID0003Y6, UID00002X, UID0000IC, UID0001TZ, UID000088, UID0000A1, UID0001HD, generated CollectionPane topology, and manual coverage. This report is the explicit reconciliation authority for those shared destinations: it preserves B002's broader closure and higher-score evidence, uses this report's more exact OnPaint stack/string/rectangle source, CollectionPane signatures, direct includes, and `0x0056edc0` IDA ownership, physically verifies the ten completed member bodies/compiler marker/support route, and verifies/preserves B003's already-executed PaletteLib source/score/manual state without a Palette write.

## Target

- UID: `0003FA`.
- Current document: `by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md`.
- Exact range: `[0x00624c10,0x00624c20)`, size `0x10` / 16 bytes.
- Dated pre-callback metadata was completion `85`, confidence `88`, canonical owner `0000IC`, emitter `0000IC`, reconstructable `TRUE`, blank emitter position, blank formal CPP, and blank formal H. Current ordinary metadata is `94/95`, owner/emitter `00002X`, position `75`, exact covered-by CPP, and blank H.
- Repair-time generated observation showed UID0003FA as an Empty Emitter Marker. Final waited physical readback shows one filled UID0003FA covered-by marker and no target empty marker; later callback authority remains the latest supervisor-verified waited physical readback rather than any fixed receipt.
- Required source destination: `NexusTK/ui/panels/CollectionPane.cpp`, through class UID00002X.

## Current Target State

- The dated pre-callback target recognized the four values and a single `movaps` reference but stopped before a source-level disposition. Current ordinary documentation closes that stale stopping point with exact pooled-local provenance and a filled covered-by representation.
- Current IDA data head is `0x00624c10`, current IDA name is `xmmword_624C10`, current type is literal `absent`, address-regular comment is literal `absent`, address-repeatable comment is literal `absent`, and function comment channels are not applicable to the data item.
- Current target bytes are `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00`; loaded-image search finds this exact 16-byte sequence only at `0x00624c10`.
- Sole inbound data xref is the instruction item `[0x0056ee7d,0x0056ee84)` in `sub_56EDC0`: `movaps xmm0, ds:xmmword_624C10`. The instruction bytes are `0F 28 05 10 4C 62 00`, SHA256 `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`, and the exact instruction pattern is unique.
- The loaded value is stored into typed stack local `destinationBounds : RectBounds`, then copied into a row-working rectangle. The loop advances top and bottom by exactly `0x32` / 50 pixels.
- The consuming function is currently `sub_56EDC0`, not a pending unknown behavior: current project evidence and primary vtable slot `+0x44` identify it as `CollectionPane::OnPaint()`.
- The failed artifact's UID00002X H recommendation was partial: it omitted 11 established members and preserved provisional aliases. That partial proposal is historicalized; Section 22 now contains the complete declaration supported by the inventory in Section 16.
- The exact B002 peer artifact is fully reconciled rather than treated as a historical support note. Its lower UID0003Y6 confidence and conflicting OnPaint/local-string forms are superseded by the unified Section 22 body; its higher shared type/service evidence and distinct consumer/MetaTable work are retained. The failed post-callback claim that comment-only child blocks completed source is corrected physically: all ten member bodies, UID00038U compiler-covered marker, direct Event/Config includes, and ScrollCollectionPane friend support are now ordinary state, and waited command `000000025070` physically read back `27/27/0`.

## Executive Recommendation

1. Replace target deferral with exact pooled-local provenance and the covered-by formal CPP marker.
2. Route target ownership/emission through class UID00002X at position `75`, immediately after complete `CollectionPane::OnPaint()` at position `70`.
3. Populate UID0003Y6 with complete dependency-closed `CollectionPane::OnPaint()` CPP using one initialized/reused `EPFTileContext`, its accepted `bounds` field, two exact 128-wide buffers, one reused text `RectBounds`, exact POD row-bounds initialization, and only established `SimpleUString::Assign`, const `Data`/`Length`, and `wcslen` operations; preserve a blank method H channel because UID00002X owns the declaration.
4. Add the exact source-facing UID00002X header preamble and complete 17-member declaration, then move the three UID0001TZ record/view declarations from CPP to H with `../../util/StringUtil.h` visibility and include `UserPane.h` from the OnPaint source block. This makes the collection view complete for both the by-value `UserPane` member and CollectionPane consumer without hand-writing vptrs, adjustors, scalar deleting wrappers, or vtable globals.
5. Keep the complete direct dependency preamble in UID00002X's file-root CPP channel and UID0003Y6 as one body-only child. Preserve the already-complete ImageLib/Surface/PaletteLib declaration routes; current MetaMan, MetaTable, and collection-layout declarations now use normal owner H channels, while singleton definitions remain solely in their global children.
6. Preserve B002's exact 14 literal uses and source-ready `OnActivate`, `LoadCollectionGroupRecords`, and `CollectionPane2::OnPaint` bodies, while replacing B002's conflicting OnPaint body with the unified one-context/two-buffer/two-rectangle/Data-Length body in Section 22.
7. Preserve one score/manual/generated state for every shared destination. Dated command `24868` mechanically observed CollectionPane `27/26/1`, but ten entries contained comment-only placeholders and did not prove source completion. Completion command `000000025070` scoped-validated the accepted ordinary state and physically read back `27/27/0`, all ten definitions once, UID00038U's marker once, and no affected placeholder; later verification still uses the latest supervisor-verified waited physical readback.
8. Keep B002 as direct owner of UID0003F1 and D01-D08/P01-P03. Keep B008 as direct owner of UID0003FA and IDA-FA-01..03, with exclusive mutation ownership at `0x0056edc0`.
9. Never edit overlapping documents concurrently. B003's PaletteLib predecessor state was verified and preserved. This accepted B008 callback applied the unified UID0003FA/SimpleUString/OnPaint/shared payload, including the accepted B002 consumer/type/service breadth; B002 remains direct owner of UID0003F1 and must reread this validated B008 state before any later overlapping write. Any active shared lease or predecessor loss is a hard stop until the supervisor supplies a replacement serialization contract.
10. Reserve unified manual coverage and both disjoint IDA handoffs for the supervisor.

## Supervisor Active Recheck

- Dated 2026-08-15 `idb_list` found session `b002_uid0000hq_rollback_20260815` for canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; it is historical evidence, not current session authority.
- That dated schema-1 runtime attestation succeeded with top-level `ok:true`, worker `ok:true`, and empty errors. Listener attestation was `2026-08-15T12:38:22.491472+00:00`; worker attestation was `2026-08-15T12:38:22.603921+00:00`.
- Dated server health reported module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, strings ready, and the selected worker not analyzing. The health flag `auto_analysis_ready:false` did not prevent any bounded required query; every required item, byte, xref, function, frame, type, disassembly, and decompilation query succeeded.
- The session name is dated evidence, not a fixed future authority. A future supervisor must start with fresh `idb_list` and schema-1 attestation for the then-current canonical path and dynamically selected active session.
- Replacement-goal header closure used a fresh read-only `idb_list` result for active canonical session `supervisor_uid0000li_rollback_20260815` at `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Bounded decompilation/disassembly of `0x0056ec50`, `0x0056ece0`, `0x0056f660`, `0x0056f670`, `0x0056f810`, `0x0056fa90`, `0x0056fad0`, `0x0056fb40`, and `[0x0056fb60,0x0056fc73)` resolved the full source-facing declaration inventory in Section 16.
- This repair used fresh read-only `idb_list` plus schema-1 runtime attestation for active canonical session `supervisor_uid0000li_i13rollback_20260815`, then bounded decompilation of `0x0056edc0`. The exact `0x0056f08f-0x0056f1a7` sequence self-checks the `MetaMan::FindEntry` result, selects its const SSO storage, passes its `+0x10` length to counted assign `0x00421590`, compares length/content with `g_emptySimpleUString`, and assigns the three-character fallback; later draw sites select SSO storage and scan to NUL. This establishes inline const `Data()` and `Length()` accessors complementary to existing `MutableData()` and supports formal `Assign`/`Data`/`Length`/`wcslen` use; it does not establish implicit assignment, `operator==`, or `c_str()`.
- Fresh accepted-callback read-only recheck dynamically selected active canonical session `supervisor_uid0000md_persistverify_20260816` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Schema-1 runtime attestation passed at listener `2026-08-16T09:47:50.263703+00:00` and worker `2026-08-16T09:47:50.372992+00:00`, with top-level/worker `ok:true` and empty errors. Bounded item/function/comment/byte/xref queries reconfirmed function `[0x0056edc0,0x0056f655)` as `sub_56EDC0`, generic type and all comments absent, no `CollectionPane__OnPaint` collision, target `[0x00624c10,0x00624c20)` as untyped `xmmword_624C10` with absent comments and sole xref `0x0056ee7d`, exact instruction/target/vtable/neighbor bytes, and sole vtable inbound reference `0x00624624`. No mutation endpoint was called.
- Fresh Gate-1-repair read-only queries used that same live canonical session and bounded only the ten missing method entities plus UID00038U. They established exact bodies/ranges/hashes for UID0003Y4 `[0x0056ec50,0x0056ecd8)` / `8F64CA132841D3A6CA43FE8AC54426990005BD11E682163D258473623DF828B7`, UID0003Y5 `[0x0056ece0,0x0056edb1)` / `C268A23D6EE4F21071061E107464EFEC25E239D723664547E566EED62BA08595`, UID0003Y7 `[0x0056f660,0x0056f665)` / `CC0E3CB106EB0FDEC984D44A563D98C3DA80700BBB8D2BE4E66EBD54A9919626`, UID0003Y8 `[0x0056f670,0x0056f7f4)` / `FE80F87A59852CBD6763D732F82F18E041E25A8603E0F0C4CD23C8396D659E46`, UID0003YA `[0x0056fa90,0x0056fac8)` / `4159BFCC55EB67812EF049ECD1D5D37F8677132FCFBBE9C01CA4B6CB4A6AD941`, UID0003YB `[0x0056fad0,0x0056fb36)` / `6FD0136ED776B652E82D433230126C00B6E4B65D097737CF7A4BC81B35D9B3D1`, UID0003YC `[0x0056fb40,0x0056fb56)` / `7E8BFD45DD317FA406164C7D286159329CCE2F0D3F2C9957F89B85971058621C`, raw UID0003YD `[0x0056fb60,0x0056fb7a)` / `8655B559C31D576DA41C5913C90C387F465872E52C799D4F9931A1BD63545FEC`, raw UID0003YE `[0x0056fb80,0x0056fbd3)` / `AFBAE6A28FE3F9C66BD0B84EEC55821A1649F6CA59E342B6316BB4641EC78326`, and UID0003YF `[0x0056fbe0,0x0056fc73)` / `C1AB2DDD694BE83C6EE37E78BBFB6D04594A631856FB9C71EBD343DC9DC47E7F`. UID00038U is exactly `[0x006245dc,0x00624668)`, 140 bytes, SHA256 `350D4771A71040BA91657990451D9BC93554133566255ACDE9134DE1A4F61D21`, containing the primary/secondary/tertiary RTTI/COL/vtable views regenerated by the complete class declaration and virtual definitions rather than a source-authored data object.
- No IDA mutation endpoint was called.

## Inference Research Guidance Check

- The target's original lexical local name is stripped, so a human local name must be inferred. `rowBounds` is preferred because the value seeds one row rectangle, the loop advances it per row, and accepted sibling source uses that exact naming pattern.
- Source shape is inferred from compiler lowering, not from constant values alone: unique packed image, sole SIMD load, immediate typed local store, subsequent local copy, and loop-local offsets all agree.
- The inference does not create behavior. Every aggregate field value, field order, row count, step, resource, text format, and collection-data field is tied to direct binary or already accepted typed support evidence.
- No research blocker is delegated to implementation. Unknown original local spelling is non-semantic; the ten formerly deferred bodies and UID00038U source disposition are now explicit formal recommendations, while their physical incorporation remains truthfully proposed.

## Heuristic / Inference Reanalysis And Validation

- Local initializer: very strong. The packed constant is loaded once and copied into a stack `RectBounds` before loop use.
- Temporary initializer: possible compiler-level phrasing but inferior source reconstruction. The working object persists and is mutated across rows, favoring a named local.
- Function-local static object: rejected. There is no address escape, static identity test, or repeated direct access after the one initialization load.
- Class static/member constant: rejected. No member-relative access, symbol family, or cross-method use exists.
- Global standalone object: rejected. One compiler-generated data name and one xref do not establish human global identity; sibling accepted methods lower inline constructors identically.
- Standalone aggregate/array element: rejected. The target is a separate 16-byte compiler pool item with no source identity or index/base computation; the accepted source is a function-local POD aggregate initialization.
- Covered-by marker plus complete use-site source: strongest project representation. It preserves physical provenance, eliminates the empty emitter, and does not duplicate runtime storage.

## Evidence Standards Used

- `very-strong`: exact bytes, item boundaries, hashes, xrefs, instruction semantics, stack type/layout, vtable identity, or accepted formal source with matching compiler pattern.
- `strong`: source-facing ownership, local spelling, source order, or score conclusions supported by convergent binary and project evidence but not original symbols.
- `moderate`: plausible alternatives lacking complete direct support; none is accepted as final source shape.
- Negative claims require bounded searches or structural contradiction, not silence alone.
- Current IDA/public MCP facts outrank old prose; current ordinary project topology controls destinations; generated artifacts are readback evidence only.

## Evidence Checked

- Target UID0003FA and exact parent/sibling item pages.
- Consuming function UID0003Y6 and broad CollectionPane range UID0001HD.
- Class UID00002X, file UID0000IC, mixed read-only parent UID0002V2, current `92/95` resource child UID0003F1 with its 14-use table and covered-by marker, resource support UID0001R8, typed layout UID0001TZ, and UID0000D9/UID0000OB SimpleUString class/header route.
- Accepted rectangle/compiler controls: `NewGroupPane::OnPaint()`, UID0003F9, and adjacent SelfLookPane constants.
- Dated command-`24224`, command-`24301`, command-`24431`, command-`24441`, command-`24506`, command-`24530`, command-`24539`, command-`24682`, command-`24719`, and command-`24725` observations are historical evidence only.
- Repair-time command-`000000024737` observations covered the relevant generated artifacts and remain historical. Accepted-callback final waited command `000000024867` supplied the physical generated readback in Section 31; no fixed generated command is continuing authority. Fresh read-only manual hashes are by-memory `757FCA2B7809B9D4C40821C0CA2B678D63DD80FC7EC042172E10AFA1C28C6D8F`, by-class `0ED3203A14212274B567154A2D1EDD39CFFC57C352D2A7BB499613712EC6C0B6`, by-type/by-struct `688814886F91F27C3B7D276083A66F6EC93CD68AD2795E47E444A899055C747A`, by-global `576277EBD27D51FCC8C052659C776C832F5F8ED9D1047349B3A3E52936B5E58E`, and by-file `85EDBC25316640F2CF8140043B9CFBEEBC74380E533FC4AC024DD99A530C5E91`. The physical UID0001HD row remains stale at `reconstructable : 82% : strong`; Palette UID0000A1/UID0000RW rows remain literal matches to Section 28 and UID0000MB remains same-or-greater no-change.
- Read the entire requested B002 snapshot SHA256 `6FD8F4D4E2C4758188AD9B9D36801BABD45B5B0054D22C1A34C2BEB68EE594E6`, then reread the complete 54-row twin and every changed formal/manual/IDA/generated/provenance section across observed B002 snapshots `B1E513DD...`, `4525E757...`, and `6F6A336A...`. All retain 30 dated applied and 24 proposed rows, the predecessor B008 unified OnPaint/const-accessor/signature payload, D01-D08/P01-P03, and exclusion of PaletteLib from B002 ownership. The exact executed B003 artifact `02E615F3...` was read in full, including C-F8-057/058/064/069/070, validator command `24682` generated receipts, manual closure, command `24694` execution footer, and archived-audit status. Cross-report search terms were `0003F1`, `0003FA`, `CollectionPane::OnPaint`, `00002X`, `0000IC`, `0001TZ`, `MetaMan`, `MetaTable`, `PaletteLib`, `0001HD`, `0x0056edc0`, `CLTINV.EPF`, and `GroupNames`; no moving whole-report hash is a fixed callback authority.
- Wave2/Wave3 files and notes were not used because the current workflow classifies them as stale.
- Live IDA exact item/data/function/frame/type/xref/decompile/disassembly/byte-search evidence described in Sections 6, 13, 14, 15, 19, and 21.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|
| C-FA-001 | 0003FA | The target is exactly `[0x00624c10,0x00624c20)`, size 16, with SHA256 `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`. | very-strong | Live item boundaries and bytes | UID0003FA range/evidence | incorporate | verified |
| C-FA-002 | 0003FA | Current IDA state is name `xmmword_624C10`, type absent, AR absent, AP absent, with FR/FP not applicable. | very-strong | Live item and comment queries | UID0003FA IDA state | incorporate | verified |
| C-FA-003 | 0003FA | Bytes decode as signed int32 `left=6`, `top=14`, `right=161`, `bottom=62`. | very-strong | Byte decoding plus RectBounds UDT | UID0003FA behavior | incorporate | verified |
| C-FA-004 | 0003FA | The exact 16-byte pattern is unique in the loaded image. | very-strong | Live bounded byte search | UID0003FA evidence | incorporate | verified |
| C-FA-005 | 0003FA | The target has exactly one inbound data xref at `0x0056ee7d`. | very-strong | Live xref query | UID0003FA xrefs | incorporate | verified |
| C-FA-006 | 0003Y6 | Xref item `[0x0056ee7d,0x0056ee84)` uniquely executes `movaps xmm0, ds:xmmword_624C10` and has SHA256 `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`. | very-strong | Live disassembly and bytes | UID0003Y6 constant provenance | incorporate | verified |
| C-FA-007 | 0003Y6 | The packed value is stored to typed local `destinationBounds : RectBounds` and copied to the working row rectangle. | very-strong | Stack frame and disassembly | UID0003Y6 local initialization | incorporate | verified |
| C-FA-008 | 0003FA | RectBounds is exactly 16 bytes with int fields at offsets `0,4,8,0xc`. | very-strong | Live type inspection | UID0003FA type interpretation | incorporate | verified |
| C-FA-009 | 0003Y6 | Each rendered row advances rectangle top and bottom by exactly 50 pixels. | very-strong | Instructions at `0x0056f5bf` and `0x0056f5c7` | UID0003Y6 loop geometry | incorporate | verified |
| C-FA-010 | 0003FA | Plausible human source is POD aggregate initialization `RectBounds rowBounds = { 6, 14, 161, 62 };`. | strong | Local use, POD layout, and accepted compiler-pattern controls | UID0003FA formal/source shape | incorporate | verified |
| C-FA-011 | 0003FA | Static, member, global, array-element, and standalone-object source forms are invalid; a function-local POD aggregate is the accepted form. | strong | One local initialization use and no identity/address escape | UID0003FA negative evidence | incorporate | verified |
| C-FA-012 | 0003Y6 | The sole consumer function is `[0x0056edc0,0x0056f655)`, size `0x895`, SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`. | very-strong | Live function and body bytes | UID0003Y6 range/evidence | incorporate | verified |
| C-FA-013 | 0003Y6 | The function has 575 instructions, 64 basic blocks, 17 profiled callees, zero direct code callers, and one vtable data xref. | very-strong | Live function profile and xrefs | UID0003Y6 inventory | incorporate | verified |
| C-FA-014 | 0003Y6 | Vtable cell `0x00624624` identifies the consumer as CollectionPane primary virtual slot `+0x44` / `OnPaint`. | very-strong | Vtable bytes, class table, current docs | UID0003Y6 identity | incorporate | verified |
| C-FA-015 | 0003Y6 | OnPaint initializes EPF state, uses `ITEMINV.PAL` and `CLTINV.EPF`, draws the background, and sets draw/text-background modes. | very-strong | Decompile, strings, call profile | UID0003Y6 formal CPP/behavior | incorporate | verified |
| C-FA-016 | 0003Y6 | First visible group is current scroll position when five rows fit, otherwise `max(snapshot-5,0)`, and at most five valid groups render. | very-strong | Complete control-flow analysis | UID0003Y6 formal CPP/behavior | incorporate | verified |
| C-FA-017 | 0003Y6 | Group records use accepted stride `0x2604` and fields groupType, totalEntries, and collectedEntries from UID0001TZ. | very-strong | Binary offsets plus accepted typed layout | UID0003Y6 dependencies | incorporate | verified |
| C-FA-018 | 0003Y6 | Each row uses `CLTLIST.EPF` frame `completionPercent/100` and palette `CLTLIST.PAL`. | very-strong | Decompile, strings, layout lookup | UID0003Y6 formal CPP/behavior | incorporate | verified |
| C-FA-019 | 0003Y6 | Group name lookup uses table `GroupNames`, decimal groupType key, and exact three-character fallback `\uC548\uB098\uC640`. | very-strong | Exact string bytes and MetaMan flow | UID0003Y6 formal CPP/behavior | incorporate | verified |
| C-FA-020 | 0003Y6 | OnPaint draws name shadow/highlight, percent with exact format `L"%d %%"`, and exact count format `L"%d/%d"`. | very-strong | Exact string bytes and draw sequence | UID0003Y6 formal CPP/behavior | incorporate | verified |
| C-FA-021 | 0003FA | Canonical owner is class UID00002X rather than file UID0000IC. | strong | Local belongs to class method; project class-child convention | UID0003FA metadata | incorporate | verified |
| C-FA-022 | 0003FA | Emitter is UID00002X with position `75`. | strong | Method-local covered-by ordering | UID0003FA metadata | incorporate | verified |
| C-FA-023 | 0003Y6 | OnPaint emits through UID00002X at position `70`. | strong | Class source order and accepted sibling order | UID0003Y6 metadata | incorporate | verified |
| C-FA-024 | 0003FA | Target score is completion `94`, confidence `95`; POD aggregate syntax, the established SimpleUString route, declaration-visible collection structs, and dependency-closed OnPaint includes/owner headers close the source-support blocker for its covered-by route. | strong | Exact target proof plus corrected formal CPP/H/API/dependency closure | UID0003FA metadata | incorporate | verified |
| C-FA-025 | 0003Y6 | OnPaint score is completion `92`, confidence `94` after exact context/buffer/rectangle, string-operation, collection-header, render-service, palette-service, metadata-service, and CRT declaration closure; original lexical names remain inferred. | strong | Complete behavior, live SSO sequence, physical stack shape, exact includes, and complete owner headers | UID0003Y6 metadata | incorporate | verified |
| C-FA-026 | 0003FA | Formal target CPP is the exact two-line covered-by marker in Section 22. | very-strong | No-duplicate use-site representation | UID0003FA formal CPP | incorporate | verified |
| C-FA-027 | 0003FA | Formal target H remains exactly blank. | very-strong | No standalone declaration exists | UID0003FA formal H | incorporate | verified |
| C-FA-028 | 0003Y6 | Formal OnPaint/file-root CPP includes `CollectionPane.h`, `UserPane.h`, `MetaMan.h`, `MetaTable.h`, `ImageLib.h`, `PaletteLib.h`, `Surface.h`, and `<cwchar>`; it uses one initialized `EPFTileContext`, `.bounds`, exact `wchar_t[128]` buffers, one reused text `RectBounds`, POD row-bounds initialization, and only declared `Assign`/const `Data`/`Length` plus `wcslen`. | very-strong | Live stack/SSO sequence plus exact declaration-route audit | UID0003Y6 formal CPP | incorporate | verified |
| C-FA-029 | 0003Y6 | Formal OnPaint H remains blank because UID00002X owns the declaration. | strong | Single class header route | UID0003Y6 formal H | incorporate | verified |
| C-FA-030 | 0003FA | Target prose incorporates exact bytes, hash, xref, local provenance, boundaries, rejected source forms, and generated disposition. | very-strong | Complete report evidence | UID0003FA all relevant sections | incorporate | verified |
| C-FA-031 | 0003Y6 | OnPaint page incorporates complete behavior, local provenance, position, corrected POD/stack/string formal CPP, exact `UserPane.h` and six direct external include routes, dependency-owner links, and `92/94` score. | very-strong | Complete report evidence plus live stack/SSO/header/dependency reconciliation | UID0003Y6 all relevant sections | incorporate | verified |
| C-FA-032 | 00002X | CollectionPane is current `94/94`, owns both B008 routes, and supplies the exact complete file-root CPP preamble plus guarded 17-member H declaration: lifecycle; render-region/layer/paint/activation virtuals; pointer/key/packet handlers; scroll-range, record-load, and scroll-change members; three rectangle helpers; detail dispatch; exact fields; and size guard. | very-strong | B008 signatures/stack evidence plus B002 four-consumer/class closure | UID00002X formal CPP/H plus shared child signature prose | incorporate | verified |
| C-FA-033 | 0000IC | The ten body definitions, UID00038U compiler-covered marker, and support closure are incorporated; file score `94/94` is source-justified and waited command `000000025070` physically proves `27/27/0`, while dated `27/26/1` remains only a mechanical placeholder observation. | very-strong | Fresh ten-body/UID00038U evidence plus waited physical generated readback | UID0000IC source topology and score | incorporate | verified |
| C-FA-034 | 0002V2 | Mixed read-only parent remains non-reconstructable/non-emitting at `88/92` and identifies UID0003FA as a source-local rectangle child. | strong | Exact split child and parent role | UID0002V2 child inventory | incorporate | verified |
| C-FA-035 | 0001HD | Broad CollectionPane range remains non-reconstructable/non-emitting at `88/91` and links dependency-closed OnPaint plus UID0003FA. | strong | Exact method split/index policy | UID0001HD child inventory | incorporate | verified |
| C-FA-036 | 0003F1/0001R8 | Current UID0003F1 is `92/95` with its covered-by route and all 14 uses; B002's direct final target recommendation is `92/94`, while existing UID0001R8 collection UI resource ownership remains correct without an edit. | very-strong | Current UID0003F1 marker/use table, exact B002 recommendation, and UID0001R8 ownership | UID0003F1 current/final score distinction; UID0001R8 no edit | incorporate | verified |
| C-FA-037 | 0000D9 | Inline `const wchar_t *Data() const` and `unsigned int Length() const` are present beside `MutableData()` in the complete SimpleUString H declaration; exact OnPaint SSO selection and `+0x10` counted-copy read establish both read-only accessors, while implicit assignment, `operator==`, and `c_str()` remain rejected. | strong | Live `0x0056f0a2-0x0056f0b2`/draw-site selection plus UID0000D9 layout | UID0000D9 formal H through UID0000OB/StringUtil.h | incorporate | verified |
| C-FA-038 | 0001TZ | Current `93/94` formal state has the exact `CollectionEntryRecord`, `CollectionGroupRecord`, and `CollectionPlayerDataView` declarations in H, includes `../../util/StringUtil.h`, adds exact `0x4c`/`0x2604` guards, and exposes them through `UserPane.h` before CollectionPane consumers; CPP is blank. | very-strong | B008 visibility analysis plus B002 layout/guard closure | UID0001TZ formal CPP/H and score | incorporate | verified |
| C-FA-039 | 0003FA | Target boundaries contain no padding; exact predecessor and successor are separate 16-byte SelfLookPane-owned items. | very-strong | Live item models, bytes, and xrefs | UID0003FA boundary analysis | incorporate | verified |
| C-FA-040 | 0003Y6 | IDA-FA-01 is a pure public rename to `CollectionPane__OnPaint`. | strong | Vtable and complete method identity | Supervisor Gate 2B IDA-FA-01 | incorporate | proposed |
| C-FA-041 | 0003Y6 | IDA-FA-02 adds the exact function-regular behavior comment and preserves FP absent. | strong | Complete behavior reconstruction | Supervisor Gate 2B IDA-FA-02 | incorporate | proposed |
| C-FA-042 | 0003FA | IDA-FA-03 adds the exact address-repeatable pooled-local comment and preserves AR absent. | strong | Exact physical/source provenance | Supervisor Gate 2B IDA-FA-03 | incorporate | proposed |
| C-FA-043 | 0003FA | Function frame, type, bytes, xrefs, vtable cell, target/xref items, neighbors, and padding must remain protected unchanged through the supervisor-owned IDA handoff. | very-strong | Fresh complete prestates | Supervisor Gate 2B protections | already-present | proposed |
| C-FA-044 | 0003FA | Historical waiting/source-deferred prose is retained only as dated superseded history, never current state. | strong | Current blocker closure | Target/support Changes history | historicalize | verified |
| C-FA-045 | 0003FA | Standalone object emission, file-level physical ownership, target data rename/type, function retagging, and boundary redefinition are rejected. | strong | Source-shape and protection analysis | Target negative/recommendation sections | reject-invalid | verified |
| C-FA-046 | 0001HD | Section 28 supplies the exact supervisor-owned replacement for stale manual `reconstructable : 82% : strong`: a no-loss `not_reconstructable : 88% : very-strong` row preserving function-map/raw-constructor/false-stub/resource/vtable/destructor/adjustor/boundary evidence and adding the non-emitting split/index plus dependency-closed OnPaint/UID0003FA child route. | very-strong | Physical current manual row compared with current UID0001HD `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter route, and complete child/evidence inventory | by-memory/-coverage-report.md exact supervisor-owned replacement | incorporate | proposed |
| C-FA-047 | 0003Y6 | Section 28 supplies the exact supervisor-owned OnPaint manual insertion row. | very-strong | Exact function evidence and route | by-memory/-coverage-report.md | incorporate | proposed |
| C-FA-048 | 0003FA | Section 28 supplies the exact supervisor-owned target manual insertion row. | very-strong | Exact target evidence and route | by-memory/-coverage-report.md | incorporate | proposed |
| C-FA-049 | 00002X | Section 28 supplies one unified supervisor-owned `94% : very-strong` class row, including all four prior consumers, ten completed member bodies, UID0003FA local provenance, and UID00038U compiler coverage; ordinary prerequisites are physically satisfied, while manual insertion remains supervisor-owned. | very-strong | Complete merged class/source route plus validated body closure | by-class/-coverage-report.md | incorporate | proposed |
| C-FA-050 | 0000IC | Section 28 supplies one unified supervisor-owned `94% : very-strong` file row, including both pooled-literal and local-rectangle routes plus `27/27/0` topology; ordinary/generated prerequisites are physically satisfied, while manual insertion remains supervisor-owned. | very-strong | Complete merged file/generated route plus waited physical readback | by-file/-coverage-report.md | incorporate | proposed |
| C-FA-051 | 0003FA | Dated command `24868` mechanically read `27/26/1`: ten registered children were nonempty only because their CPP channels held comments and UID00038U was empty. This observation does not prove authored source completion and is not continuing authority. | very-strong | Physical dated generated observation compared with current ordinary formal channels | Validator Results generated observation | already-present | verified |
| C-FA-052 | 0003FA | Coordinated callback receipts record every changed target/support page, no overlapping document was written concurrently, corrective waited owner refresh `24867` followed the discovered signature-marker closure, and physical reread covers `CollectionPane.cpp/.h`, `UserPane.cpp/.h`, `PaletteLib.cpp/.h`, and `MetaMan.cpp/.h`; latest waited readback remains dynamic authority. | very-strong | Three-report sequencing and dynamic generated-authority rule | Coordinated callback Validator Results/readback | incorporate | verified |
| C-FA-053 | 0003FA | Changed Files records this report plus the 26 validated ordinary destinations; peer reports, coverage, generated artifacts, IDA, and lifecycle state were read-only/directly unchanged. | very-strong | Changed-file audit | Changed Files | already-present | verified |
| C-FA-054 | 0003FA | The report has all 33 headings, exact 125-row ledger/checklist parity, 113 checked/12 unchecked allocation, no executable fences, and exactly one terminal execute-readiness workflow marker. | very-strong | Mechanical self-audit | Report hygiene | already-present | verified |
| C-FA-055 | 0003Y6 | The failed artifact's two-include OnPaint preamble is dated incomplete evidence and is superseded by the direct dependency preamble in Section 22. | very-strong | Formal-body symbol-to-header audit | UID0003Y6 history/formal CPP | historicalize | verified |
| C-FA-056 | 0003Y6 | The exact file-root OnPaint preamble directly includes `CollectionPane.h`, `UserPane.h`, `../../metadata/MetaMan.h`, `../../metadata/MetaTable.h`, `../../render/ImageLib.h`, `../../render/PaletteLib.h`, `../../render/Surface.h`, and `<cwchar>`. | very-strong | Exact body dependency inventory | UID0003Y6 formal CPP | incorporate | verified |
| C-FA-057 | 00006E/0000K2 | Current ordinary owner routes declare `ImageLib::LookupLayoutEntry` and `extern ImageLib *g_pEPFLib`; repair-time command-24737 `ImageLib.h` confirms that route, and OnPaint consumes it without an ImageLib edit. | very-strong | Current ordinary route plus repair-time generated observation | UID0003Y6 dependency evidence; UID00006E/0000K2 no edit | already-present | verified |
| C-FA-058 | 0000TN/0000OC | Current ordinary owner routes declare exact `SurfaceSpriteBlitProc` and `extern SurfaceSpriteBlitProc g_pfnBlitSprite`; repair-time command-24737 `Surface.h` confirms that route, and OnPaint consumes it without a Surface edit. | very-strong | Current ordinary route plus repair-time generated observation | UID0003Y6 dependency evidence; UID0000TN/0000OC no edit | already-present | verified |
| C-FA-059 | 0000A1 | Keep current `92/93`; executed B003 state already places the complete `LObject.h`/`Singleton.h`/`List.h`/`Palette.h`/class/helper payload in UID0000A1 H. Repair-time command-24737 `PaletteLib.h` confirms it. Verify and preserve it; B008 performs no PaletteLib write and rejects its dated guard/size-assertion addition. | very-strong | Current ordinary UID0000A1, repair-time generated observation, and executed B003 artifact | B003-owned UID0000A1 formal H and score, verify only | already-present | verified |
| C-FA-060 | 0000A1 | Preserve B003's exact class CPP payload `[[CHILDREN]]`; no include, class, struct, extern, or reduced local declaration is added by UID0000A1 itself. B008 performs no PaletteLib write. | very-strong | Exact B003 direct-owner formal CPP | B003-owned UID0000A1 formal CPP | already-present | verified |
| C-FA-061 | 0000RW | Preserve current UID0000RW CPP `PaletteLib *g_pPaletteLib = 0;` plus `[[CHILDREN]]` and current UID0000RW H `extern PaletteLib *g_pPaletteLib;`; repair-time command `24737` confirms exactly one generated extern and one storage definition. B008 performs no PaletteLib write, and the latest supervisor-verified waited readback controls callback verification. | very-strong | Current UID0000RW formal channels and repair-time generated one-definition observation | B003-owned UID0000RW formal disposition, verify only | already-present | verified |
| C-FA-062 | 000088 | Current `94/94` MetaMan formal H contains the complete accepted declaration, `<map>`, `Singleton.h`, complete `StringUtil.h`, `MetaTable` forward declaration, `extern MetaMan *g_pMetaMan`, and exact `0x14` size guard. | very-strong | B008 dependency audit plus B002 manager/MetaTable closure | UID000088 formal H and score | incorporate | verified |
| C-FA-063 | 000088 | MetaMan class CPP is exactly `#include "MetaMan.h"` plus `[[CHILDREN]]`; no class, extern, or reduced local declaration remains in CPP. | very-strong | Normal single-definition owner route | UID000088 formal CPP | incorporate | verified |
| C-FA-064 | 0000RL | Keep sole `MetaMan *g_pMetaMan = 0;` in the global CPP child, keep its H blank, and expose exactly one extern through UID000088 `MetaMan.h`. | very-strong | Existing global definition and one-declaration rule | UID0000RL formal disposition | incorporate | verified |
| C-FA-065 | 0000A1 | `PaletteLib::GetPaletteByName(const wchar_t *)` and `g_pPaletteLib` are declaration-visible through the current ordinary complete owner H route, which also makes `DLPalette` complete through `Palette.h`; repair-time command-`24737` `PaletteLib.h` confirms it and no Palette edit is required. | very-strong | Current ordinary route plus repair-time generated observation | UID0003Y6 dependency proof; Palette no change | already-present | verified |
| C-FA-066 | 000088 | `MetaMan::FindEntry(const SimpleUString *, const SimpleUString *, unsigned int)` and `g_pMetaMan` are declaration-visible through the complete `MetaMan.h`, which makes `SimpleUString` complete through `StringUtil.h`. | very-strong | Accepted class API and complete owner H route | UID0003Y6 dependency proof | incorporate | verified |
| C-FA-067 | 0003Y6 | `<cwchar>` is the project/MSVC declaration route for unqualified `swprintf_s` and `wcslen`; accepted UID00009A generated source uses the same include and spellings. | strong | Current project formal/generated precedent | UID0003Y6 dependency proof | incorporate | verified |
| C-FA-068 | 0003Y6 | `CollectionPane.h` reaches complete `EPFTileContext` through `PanelPane.h -> Pane.h -> GrafPort.h -> EPFTileContext.h`; `UserPane.h` plus corrected UID0001TZ supplies complete collection records, `PaletteLib.h` supplies complete `DLPalette`, and direct `MetaMan.h`/`MetaTable.h` supply complete manager/table APIs and `SimpleUString`. | very-strong | Physical include-chain and formal-header audit | UID0003Y6 dependency proof | incorporate | verified |
| C-FA-069 | 0003Y6 | Reduced local PaletteLib/MetaMan declarations, duplicate classes, local externs, and hand-written CRT prototypes are invalid and must not be used. | very-strong | Normal owner/header rule and ODR/type-completeness constraints | UID0003Y6 negative evidence | reject-invalid | verified |
| C-FA-070 | 0003FA/0003Y6 | Retain `94/95` and `92/94` only with expanded direct includes, complete service headers, B002's exact seven literal uses, and B008's exact one-context/two-buffer/two-rectangle/Data-Length body; B002's `92/93` confidence and MutableData/const-cast body are superseded for the shared method. | very-strong | Exact cross-report source/score comparison | Target/method score rationale | incorporate | verified |
| C-FA-071 | 0000IC/0000MB/0000LC | Repair-time command `000000024737` observation found CollectionPane `17/10/7`, PaletteLib `6/6/0` with complete H and no CPP-local class, and MetaMan `16/16/0` with class-in-CPP and no H; no fixed command is callback authority. | very-strong | Physical repair-time generated observation | Validator Results baseline | already-present | verified |
| C-FA-072 | 0003FA | Every previously changed ordinary page has an exact scoped receipt; discovery refresh `24849` exposed ten registered signature-only markers and validators `24857`-`24866` made their comment channels mechanically nonempty, while refresh `24867` records hashes/counts but does not prove authored bodies. | very-strong | Exact callback validator history separated from source-quality judgment | Callback Validator Results/readback history | incorporate | verified |
| C-FA-073 | 0000A1 | Current by-class manual UID0000A1 row is literally identical to Section 28's `92% : very-strong` complete-H/children-only-CPP text; no replacement or B008 Palette row is permitted. | very-strong | Literal current by-class row comparison | by-class/-coverage-report.md no change | already-present | verified |
| C-FA-074 | 0000MB | Retain the current `91% : very-strong` PaletteLib file row without replacement; executed B003 required no UID0000MB manual edit and B008 supplies none. | very-strong | Current manual row plus exact B003 coverage scope | by-file/-coverage-report.md no change | already-present | verified |
| C-FA-075 | 0000RW | Current by-global manual UID0000RW row is literally identical to Section 28's `92% : very-strong` sole-definition/owner-header extern text; no replacement or B008 Palette row is permitted. | very-strong | Literal current by-global row comparison | by-global/-coverage-report.md no change | already-present | verified |
| C-FA-076 | 000088 | Section 28 supplies one unified supervisor-owned `94% : very-strong` complete-H/children-only-CPP/size-guard class row. | very-strong | Current row plus cross-report manager/MetaTable closure | by-class/-coverage-report.md | incorporate | proposed |
| C-FA-077 | 0000LC | Section 28 supplies the exact supervisor-owned no-loss MetaMan header/source file-owner replacement. | very-strong | Current manual row plus corrected generated topology | by-file/-coverage-report.md | incorporate | proposed |
| C-FA-078 | 0000RL | Section 28 supplies the exact supervisor-owned replacement for stale `88% : strong` g_pMetaMan: current `89% : very-strong` owner-header extern/sole-definition text. | very-strong | Current ordinary `89/90` plus corrected declaration route | by-global/-coverage-report.md | incorporate | proposed |
| C-FA-079 | 00006E/0000K2/0000TN/0000OC | Existing ImageLib and Surface manual coverage already describes the complete header/global routes used here; no manual replacement is recommended. | very-strong | Current manual coverage and complete generated headers | ImageLib/Surface manual rows no change | already-present | verified |
| C-FA-080 | B002/B003 | Requested B002 `6FD8F4D4E2C4758188AD9B9D36801BABD45B5B0054D22C1A34C2BEB68EE594E6` and observed peers were reread at complete-report/delta depth. Exact executed B003 artifact `02E615F37ED6D37F6C6515AE0EACE4DF5384B3EA62B4D7ED655F5FFA7DCAED85`, 186956/1284, command `24694`, archived-audit passed, was reread in full and its Palette ordinary/generated/manual state physically matched. No moving whole-report hash is fixed callback authority. | very-strong | Physical peer/artifact reads, execution audit, and current row/file comparison | Cross-report evidence inventory | already-present | verified |
| C-FA-081 | 0003F1/0003FA | B002 remains direct owner of UID0003F1; B008 remains direct owner of UID0003FA. Neither report claims the other's target or target-specific marker. | very-strong | Exact target ranges and report identities | Cross-report ownership contract | incorporate | verified |
| C-FA-082 | 0003F1 | Preserve the exact eight-literal/two-alignment/14-use map: `Collections` 4, `GroupNames` 3, `CLTINV.EPF` 2, and `CLTLIST.EPF`, `CLTLIST.PAL`, escaped Korean fallback, `%d %%`, `%d/%d` one each across four methods. | very-strong | B002 exact bytes/xrefs/source-use matrix | Unified CollectionPane source evidence | incorporate | verified |
| C-FA-083 | 0003Y3/0003Y6/0003Y9/0003YG | Preserve all four B002 consumer closures, but use the unified UID0003Y6 body and scores selected here; no consumer detail is dropped merely because UID0003FA has one direct consumer. | very-strong | Full B002 consumer profiles plus B008 targeted OnPaint evidence | Shared method pages and formal source | incorporate | verified |
| C-FA-084 | 0003Y6 | Final OnPaint is `92/94`: B008 controls one initialized context, two exact 128-wide buffers, row/text rectangles, const Data/Length copy, direct includes, and rowBounds provenance; B002 contributes all seven literal uses, escaped Korean source spelling, and full render behavior. | very-strong | Exact stack/SSO/constant evidence plus B002 literal map | UID0003Y6 formal CPP/score | incorporate | verified |
| C-FA-085 | 00002X | Current CollectionPane is `94/94`: it retains `int m_groupCount`, exact guarded `0x10c` H and four-consumer closure, and now contains the ten formal member bodies, direct Event/Config includes, and ScrollCollectionPane friend support. | very-strong | Direct dword write, fresh ten-body evidence, B002 consumer closure, scoped validators, and source-valid access route | UID00002X formal CPP/H/score | incorporate | verified |
| C-FA-086 | 0000IC | Current CollectionPane file is `94/94`: one preamble/child aggregator, complete CollectionPane/CollectionPane2 H routes, all fourteen source-bearing consumer/member bodies, both pooled-data markers, UID0003FA marker, and compiler-covered UID00038U marker, with `27/27/0` and no empty emitter after waited readback. | very-strong | Complete cross-report source/generated inventory plus command-25070 physical readback | UID0000IC topology/score | incorporate | verified |
| C-FA-087 | 0001TZ | Final collection layout is `93/94`, blank CPP and complete H with StringUtil plus exact `0x4c`/`0x2604` guards; this single route serves UserPane, OnActivate, OnPaint, and the loader. | very-strong | Combined visibility/layout evidence | UID0001TZ formal CPP/H/score | incorporate | verified |
| C-FA-088 | 000088 | Final MetaMan is `94/94`, header-plus-children CPP and one guarded complete H with extern and `0x14` guard; B002's higher score is accepted because MetaTable and all four consumers are now closed. | very-strong | Combined owner/header/consumer evidence | UID000088 formal CPP/H/score | incorporate | verified |
| C-FA-089 | 000089 | Preserve B002's MetaTable `94/93` closure: children-only CPP, guarded complete H, accepted RowMap, Rows/IsMaterialized accessors, exact payload fields, and `0x24` guard. | strong | B002 materializer/layout/consumer evidence | UID000089 formal CPP/H/score | incorporate | verified |
| C-FA-090 | 0000A1 | Final PaletteLib remains current `92/93` under executed B003 ownership: UID0000A1 H has the complete class/helper payload, UID0000A1 CPP is children-only, UID0000RW H owns the extern, and UID0000RW CPP owns the sole definition plus children. B008's dated `93/94`/guard/size-assertion proposal is superseded and authorizes no PaletteLib write. | very-strong | Current ordinary/generated/manual state plus executed B003 artifact | B003-owned Palette formal/score state, verify only | already-present | verified |
| C-FA-091 | 0003Y3 | Preserve B002's `93/94` OnActivate body, exact four literal uses, packet-byte record initialization, metadata materialization, scroll refresh, invalidation, and raw-byte-helper exclusion. | very-strong | B002 body hash/profile/vtable/literal evidence | UID0003Y3 formal CPP/score | incorporate | verified |
| C-FA-092 | 0003Y9 | Preserve B002's `92/93` LoadCollectionGroupRecords closure, exact two `Collections` uses, RowMap traversal, `_wtol` field mapping, no collectedFlag write, matching count, and one-pointer member ABI; use const Data/Length instead of const-cast MutableData. | very-strong | B002 body/caller/row evidence plus B008 const API proof | UID0003Y9 formal CPP/score | incorporate | verified |
| C-FA-093 | 00002Y | Preserve B002's CollectionPane2 `94/95` complete PanelPane-derived `0xf8` H route and children-only CPP. | very-strong | Constructor/vtable/base/callback evidence | UID00002Y formal CPP/H/score | incorporate | verified |
| C-FA-094 | 0003YG | Preserve B002's CollectionPane2::OnPaint `94/95` body with one `CLTINV.EPF` use and exact typed `g_pfnBlitSprite` call against `m_visibleBounds`. | very-strong | Exact body/vtable/callback evidence | UID0003YG formal CPP/score | incorporate | verified |
| C-FA-095 | 0003F1 | Preserve B002's direct target recommendation `92/94`, exact four-line no-object marker, blank H, target coverage row, and repeated-expression source placement. | very-strong | Direct B002 target evidence | B002-owned UID0003F1 target/formal/manual route | already-present | verified |
| C-FA-096 | 0001HD | Keep broad index `88/91`, non-reconstructable/non-emitting, and use one merged no-loss row that includes the full function/helper/padding/vtable/destructor/adjustor/boundary inventory, all four literal consumers, and UID0003FA local provenance. | very-strong | Both reports' broad-range evidence | UID0001HD prose/manual row | incorporate | verified |
| C-FA-097 | 0000D9 | Preserve B008's inline const `Data()`/`Length()` additions and use them in both OnPaint and LoadCollectionGroupRecords; B002's const-cast MutableData expressions are superseded. | very-strong | Live SSO/count evidence and merged consumer needs | UID0000D9 H plus merged method bodies | incorporate | verified |
| C-FA-098 | 0003F1 | B002 exclusively owns data-comment D01-D08 at `0x00624a98`, `0x00624ab0`, `0x00624ac8`, `0x00624ae0`, `0x00624af8`, `0x00624b10`, `0x00624b18`, and `0x00624b24`, plus P01-P03; B008 performs none of those actions. | very-strong | Exact B002 Section 21 rows | Supervisor B002 IDA handoff | already-present | verified |
| C-FA-099 | 0003Y6/0003FA | B008 exclusively owns IDA-FA-01..03, including every mutation at function head `0x0056edc0`; B002's consumer investigation supplies source evidence only and authorizes no function mutation. | very-strong | Both reports' explicit IDA exclusions/actions | Supervisor B008 IDA handoff | already-present | verified |
| C-FA-100 | SHARED | No overlapping ordinary document was edited concurrently. B003 predecessor leases were clear, each B008 batch was leased/validated/released serially, and B002 may begin an overlapping write only after rereading the released validated B008 state. | very-strong | Three-report destination inventory and lease discipline | Callback sequencing contract | incorporate | verified |
| C-FA-101 | SHARED | B003 Palette state is verified/preserved and the accepted B008 UID0003FA/SimpleUString/unified OnPaint/shared implementation is physically validated. B002 remains direct UID0003F1 owner and later rereads validated B008 before any overlapping work. | very-strong | Executed predecessor status, direct-owner boundaries, and additive dependency closure | Callback sequencing contract | incorporate | verified |
| C-FA-102 | SHARED | B002 must reread and merge validated B008 ordinary/generated state while preserving executed B003 state before any later shared write. An active shared lease or loss of either predecessor payload is a hard stop until the supervisor supplies a replacement serialization contract. | very-strong | Deterministic no-loss cross-report requirement | Callback sequencing contract | incorporate | verified |
| C-FA-103 | 0000IC/0000MB/0000LC | Repair-time command `000000024737`, refreshed `2026-08-16T04:45:17-04:00`, observed CollectionPane `17/10/7`, PaletteLib `6/6/0` with complete H/no CPP-local class, and MetaMan `16/16/0` with no H; this dated observation is not permanent authority. | very-strong | Physical generated headers/hashes/counts at repair time | Validator Results observation | already-present | verified |
| C-FA-104 | 0000IC | Dated command `24868` mechanically observed `27/26/1`; ten child entries contained comments instead of source bodies and UID00038U remained empty, so the observation is not a source-completion receipt or continuing authority. | very-strong | Physical generated readback compared with ordinary formal channels | CollectionPane generated observation | already-present | verified |
| C-FA-105 | 0001TZ/000088/000089/0000A1 | Coordinated generated readback preserves executed-B003 PaletteLib complete H, children-only class CPP, one extern/one definition, and no duplicate/reduced declaration; it also proves complete UserPane collection layouts and one MetaMan/MetaTable H route with owner CPP children namespace-scoped. The latest supervisor-verified waited readback, not command-24867 or any earlier fixed receipt, controls later verification. | very-strong | Current B003 ordinary state plus completed unified formal topology and ordered ownership | UserPane/MetaMan/PaletteLib generated readback | incorporate | verified |
| C-FA-106 | MANUAL | Section 28 supplies one coordinated disposition per affected UID: current PaletteLib class/global rows compare literally equal and UID0000MB is same-or-greater no-change; B008 owns UID0003FA/support handoffs, and B002 owns UID0003F1/broader handoffs. No later pass duplicates an already-present Palette row. | very-strong | Exact current manual comparison and three-report ownership | Supervisor-owned manual coverage | incorporate | verified |
| C-FA-107 | MANUAL | Every later callback/coverage pass treats an identical predecessor row as already present and never inserts or replaces a competing payload for the same UID. | very-strong | One-row-per-UID three-report reconciliation rule | Supervisor-owned manual coverage sequencing | incorporate | verified |
| C-FA-108 | SCORES | Current shared scores are Y6 `92/94`, 02X `94/94`, 0IC `94/94`, 1TZ `93/94`, 088 `94/94`, 089 `94/93`, direct-owner 0A1 `92/93`, and 1HD `88/91`; 02X/0IC source-readiness is physically supported by the completed ten-body/UID00038U callback and waited `27/27/0` readback. | very-strong | Full overlap comparison plus validated body/compiler-data/generated closure | Score And Metadata Recommendation | incorporate | verified |
| C-FA-109 | 0003Y6 | B002's lower `92/93` score and formal body using const-cast MutableData, one loop-local aggregate text rectangle, and no copied SimpleUString are retained only as dated superseded proposals. | very-strong | Direct formal comparison with B008 stack/SSO evidence | Historicalized cross-report conflict | historicalize | verified |
| C-FA-110 | SHARED | B008's former lower 02X/file/MetaMan scores and isolated `17/13/4` projection, B002's conflicting field/signature/manual/generated variants, B008's dated higher PaletteLib `93/94`/guard/size-assertion proposal, command-24539 no-H baseline, and future-B003-first sequencing are superseded by unified rows and executed B003 `92/93` current state. | very-strong | Exact three-report claim/formal/score/generated/current-status comparison | Historicalized cross-report conflicts | historicalize | verified |
| C-FA-111 | 0003FA | The earlier accepted callback changed this B008 report and 26 exact ordinary destinations; this completion callback changes the same report plus the 14 exact ordinary destinations in Section 32. Peer reports, coverage, IDA, and lifecycle state were read-only/directly unchanged; generated changes were validator-owned side effects only. | very-strong | Changed-file audit | Changed Files | already-present | verified |
| C-FA-112 | 0003FA | The completed post-callback report retains 33 headings, exact 125-row ledger/checklist parity, 113 checked/12 unchecked allocation, no executable fences, lifecycle-neutral prose, and exactly one standalone terminal execute-readiness marker after the checklist. | very-strong | Mechanical final audit | Report hygiene/lifecycle neutrality | incorporate | verified |
| C-FA-113 | 0003Y4 | Current score is `92/94`; formal CPP is the complete `UpdateRenderRegion` body with retained local-bounds initialization, exact child bounds `{right-20,top+27,right-7,bottom-21}`, child SetBounds, Pane base update, and range refresh; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25057 | UID0003Y4 formal CPP/H/score | incorporate | verified |
| C-FA-114 | 0003Y5 | Current score is `93/94`; formal CPP is the complete `UpdateScrollRange` body with group snapshot, signed `0..30000` range/position clamps, exact child-state comparisons/setters, and first-visible write; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25058 | UID0003Y5 formal CPP/H/score | incorporate | verified |
| C-FA-115 | 0003Y7 | Current score is `92/94`; formal CPP is the exact key/text false-return override and formal H is blank/class-owned. | very-strong | Exact five-byte body, EventHandler slot, ordinary readback, and validator 25059 | UID0003Y7 formal CPP/H/score | incorporate | verified |
| C-FA-116 | 0003Y8 | Current score is `93/94`; formal CPP is the complete pointer/mouse body with input-lock gate, wheel clamp/update, configured single/double-click route, exact hit test/detail dispatch, child-local coordinate forwarding/restoration, and result return; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, event/config declarations, ordinary readback, and validator 25060 | UID0003Y8 formal CPP/H/score | incorporate | verified |
| C-FA-117 | 0003YA | Current score is `92/94`; formal CPP is the complete scroll-position callback with unused orientation, unchanged fast return, state synchronization, range refresh, and invalidation; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25061 | UID0003YA formal CPP/H/score | incorporate | verified |
| C-FA-118 | 0003YB | Current score is `92/94`; formal CPP is the complete AddToLayer override with Pane base call, child screen-bounds attachment, and range refresh; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25062 | UID0003YB formal CPP/H/score | incorporate | verified |
| C-FA-119 | 0003YC | Current score is `92/94`; formal CPP is the complete RemoveFromLayer override with child-first then Pane-base detach; formal H is blank/class-owned. | very-strong | Fresh bounded disassembly, exact body hash, ordinary readback, and validator 25063 | UID0003YC formal CPP/H/score | incorporate | verified |
| C-FA-120 | 0003YD | Current score is `90/92`; formal CPP is the complete bounded raw member body that ignores visibleSlot and writes four `-1` fields through InitRectBounds; formal H is blank/class-owned. | very-strong | Exact raw range, `retn 8`, bytes/hash, ordinary readback, and validator 25064 | UID0003YD formal CPP/H/score | incorporate | verified |
| C-FA-121 | 0003YE | Current score is `91/93`; formal CPP is the complete bounded raw member body that emits exact five-row `{6,14+50*n,161,62+50*n}` geometry or four `-1` fields; formal H is blank/class-owned. | very-strong | Exact raw range, unsigned branch, bytes/hash, ordinary readback, and validator 25065 | UID0003YE formal CPP/H/score | incorporate | verified |
| C-FA-122 | 0003YF | Current score is `92/94`; formal CPP is the complete five-slot y/x hit-test loop returning the slot or `-1`; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact hash, ordinary readback, and validator 25066 | UID0003YF formal CPP/H/score | incorporate | verified |
| C-FA-123 | 00038U | Current score is `94/95`; formal CPP is the exact inert compiler-covered marker and formal H is blank: the complete UID00002X virtual declaration and ordinary method definitions regenerate all three RTTI/COL/vtable views, destructor adjustors, and table words; hand-authored data is forbidden. | very-strong | Exact 140-byte model/hash, constructor stores, ordinary readback, and validator 25067 | UID00038U formal CPP/H/score | incorporate | verified |
| C-FA-124 | 00002X/0000CG | The CollectionPane file-root preamble now directly includes `../core/Event.h` and `../../config/Config.h`, and the existing complete ScrollCollectionPane H declaration now contains only the additive `friend class CollectionPane;`, preserving all layout and closing exact event/config names plus direct private child-state reads without invented accessors. | very-strong | Physical ordinary/generated header routes and validators 25068/25069 | UID00002X CPP and UID0000CG H support | incorporate | verified |
| C-FA-125 | 0000IC | Waited owner command `000000025070` physically shows each of the ten method bodies once, UID00038U's compiler-covered marker once, no affected empty/comment-only placeholder, and CollectionPane `27/27/0`; the latest supervisor-verified physical readback controls later verification. | very-strong | Complete formal inventory plus physical generated CPP/H scan | Generated CollectionPane.cpp/.h readback | incorporate | verified |

## Positive Evidence Summary

- Exact target bytes form a valid `RectBounds` in field order, and the live UDT independently confirms the 16-byte four-int layout.
- The target pattern and loading instruction pattern are each unique; target xref count is exactly one.
- The loaded 16 bytes immediately enter a typed stack rectangle and then a row-working rectangle; no target address escapes.
- Accepted sibling rectangle initializers have the same `movaps` constant-pool lowering. The target's four-int POD layout and lack of an established constructor make `RectBounds rowBounds = { 6, 14, 161, 62 };` the evidence-bounded source form.
- Vtable slot, complete function behavior, resources, typed collection data, and loop geometry all converge on `CollectionPane::OnPaint`.
- Current resource support provides the substantive literals. UID0001TZ now provides the exact collection layouts through H with `StringUtil.h`; this is a visibility correction, not a type invention.
- Live stack order proves one `EPFTileContext`, two `RectBounds` objects, and two 128-wide-character arrays. Live string flow proves counted assignment from the source `+0x10` length after const SSO storage selection, empty-value fallback, and NUL-scanned draw access; UID0000D9 therefore adds exact inline const `Data()` and `Length()` accessors complementary to existing `MutableData()`, without introducing an assignment operator, comparison operator, or `c_str()` facade.
- The PanelPane/Pane vtable contract and fresh CollectionPane bodies close every class-H family: primary `+0x0c/+0x30/+0x38/+0x44/+0x48`, EventHandler `+0x04/+0x08/+0x10`, the owner scroll callback, record loader, and three rectangle helpers all have concrete signatures, source-facing names, and formal definitions. UID00038U is recreated by those declarations/definitions and receives no hand-authored table data.
- Direct include and owner-header closure is physically complete: ImageLib and Surface expose the exact render globals/callback signatures; PaletteLib's accepted declaration and global extern remain in H through the executed B003 route; MetaMan and MetaTable now emit full accepted declarations through H; `<cwchar>` supplies the exact CRT names used by the formal body. No reduced local declaration or duplicate type is present.

## IDA MCP Facts

- Fresh accepted-callback read-only identity: session `supervisor_uid0000md_persistverify_20260816`; canonical IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; schema-1 listener/worker attestation `ok:true` with empty errors at `2026-08-16T09:47:50.263703+00:00` / `2026-08-16T09:47:50.372992+00:00`. Earlier session IDs in Section 6 remain dated evidence only.
- Target: item `[0x00624c10,0x00624c20)`, data, size 16, name `xmmword_624C10`, type absent, AR absent, AP absent, FR/FP not applicable.
- Target bytes/hash: `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00`; SHA256 `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`.
- Sole xref instruction: item `[0x0056ee7d,0x0056ee84)`, bytes `0F 28 05 10 4C 62 00`, SHA256 `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`, `movaps xmm0, ds:xmmword_624C10`.
- Consumer: function `[0x0056edc0,0x0056f655)`, size `0x895`, name `sub_56EDC0`, type `void __thiscall(GrafPort *this)`, AR absent, AP absent, FR absent, FP absent, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`.
- Vtable cell: item `[0x00624624,0x00624628)`, bytes `C0 ED 56 00`, SHA256 `1F96B6D9219361704346357879A4CADB0D5C78B3A3F0EA6116013F08DE871297`, name absent, type absent, AR absent, AP absent, sole outbound data xref to `0x0056edc0`.
- `RectBounds`: size 16, `int left @0`, `int top @4`, `int right @8`, `int bottom @0xc`. `CollectionPane` UDT is absent, so no function type mutation is safe in this report.

## Function / Child Inventory

| Entity | Exact range | Current state | Role/disposition |
|---|---|---|---|
| UID0003Y6 consumer | `[0x0056edc0,0x0056f655)` | `sub_56EDC0`, `void __thiscall(GrafPort *this)`, 2,197 bytes | Primary CollectionPane `+0x44` OnPaint; complete source present. |
| Target load | `[0x0056ee7d,0x0056ee84)` | unique `movaps` item | Loads UID0003FA into a typed local rectangle. |
| Target UID0003FA | `[0x00624c10,0x00624c20)` | `xmmword_624C10`, type/comments absent | Compiler-pooled local initializer; covered-by marker. |
| Primary vtable cell | `[0x00624624,0x00624628)` | unnamed/untyped pointer value `0x0056edc0` | Identity anchor; protected. |
| Function predecessor padding | `[0x0056edb1,0x0056edc0)` | 15 bytes `CC`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C` | Exact boundary; protected. |
| Function successor padding | `[0x0056f655,0x0056f660)` | 11 bytes `CC`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943` | Exact boundary; protected. |
| Target predecessor UID0003F9 | `[0x00624c00,0x00624c10)` | `xmmword_624C00`, one SelfLookPane xref | Separate SelfLookPane rectangle; protected. |
| Target successor UID0003FB | `[0x00624c20,0x00624c30)` first item | `xmmword_624C20`, one SelfLookPane xref | Separate SelfLookPane rectangle family; protected. |
| UID0003Y4 | `[0x0056ec50,0x0056ecd8)` | modeled method, 136 bytes, SHA256 `8F64CA132841D3A6CA43FE8AC54426990005BD11E682163D258473623DF828B7` | `UpdateRenderRegion`; exact bounds, child bounds, base update, and range refresh body. |
| UID0003Y5 | `[0x0056ece0,0x0056edb1)` | modeled method, 209 bytes, SHA256 `C268A23D6EE4F21071061E107464EFEC25E239D723664547E566EED62BA08595` | `UpdateScrollRange`; exact group snapshot, signed clamps, child range/position synchronization. |
| UID0003Y7 | `[0x0056f660,0x0056f665)` | modeled five-byte body, SHA256 `CC0E3CB106EB0FDEC984D44A563D98C3DA80700BBB8D2BE4E66EBD54A9919626` | Key/text EventHandler override; ignores event and returns false. |
| UID0003Y8 | `[0x0056f670,0x0056f7f4)` | modeled method, 388 bytes, SHA256 `FE80F87A59852CBD6763D732F82F18E041E25A8603E0F0C4CD23C8396D659E46` | Pointer/mouse handler; lock gate, wheel/click handling, child-coordinate dispatch and restoration. |
| UID0003YA | `[0x0056fa90,0x0056fac8)` | modeled method, 56 bytes, SHA256 `4159BFCC55EB67812EF049ECD1D5D37F8677132FCFBBE9C01CA4B6CB4A6AD941` | Scroll-owner callback; changed-position synchronization and invalidation. |
| UID0003YB | `[0x0056fad0,0x0056fb36)` | modeled method, 102 bytes, SHA256 `6FD0136ED776B652E82D433230126C00B6E4B65D097737CF7A4BC81B35D9B3D1` | Primary layer attach override plus child attach and range refresh. |
| UID0003YC | `[0x0056fb40,0x0056fb56)` | modeled method, 22 bytes, SHA256 `7E8BFD45DD317FA406164C7D286159329CCE2F0D3F2C9957F89B85971058621C` | Child detach followed by Pane detach. |
| UID0003YD | `[0x0056fb60,0x0056fb7a)` | raw bounded member, 26 bytes, SHA256 `8655B559C31D576DA41C5913C90C387F465872E52C799D4F9931A1BD63545FEC` | Writes an all-`-1` invalid rectangle; first slot argument intentionally ignored. |
| UID0003YE | `[0x0056fb80,0x0056fbd3)` | raw bounded member, 83 bytes, SHA256 `AFBAE6A28FE3F9C66BD0B84EEC55821A1649F6CA59E342B6316BB4641EC78326` | Writes exact five-row geometry or an all-`-1` invalid rectangle. |
| UID0003YF | `[0x0056fbe0,0x0056fc73)` | modeled method, 147 bytes, SHA256 `C1AB2DDD694BE83C6EE37E78BBFB6D04594A631856FB9C71EBD343DC9DC47E7F` | Hit-tests five visible row rectangles in project y/x order and returns slot or `-1`. |
| UID00038U | `[0x006245dc,0x00624668)` | compiler data, 140 bytes, SHA256 `350D4771A71040BA91657990451D9BC93554133566255ACDE9134DE1A4F61D21` | Three RTTI/COL/vtable views; compiler-covered marker only, no table words or H declaration. |

- Consumer stack frame, exactly as currently modeled: `var_2C8@0x0c char[4]`; `var_2C4@0x10 _DWORD`; `ArgList@0x14 char[4]`; `var_2BC@0x18 _DWORD`; `var_2B8@0x1c _DWORD`; `var_2B4@0x20 _DWORD`; `var_2B0@0x24 ResourceLayoutTable *`; `var_2AC@0x28 _DWORD`; `var_2A8@0x2c _DWORD`; `var_2A1@0x33 _BYTE`; `outContext@0x34 EPFTileContext size 0x28`; `var_278@0x5c void *`; `var_268@0x6c _DWORD`; `var_264@0x70 _DWORD`; `Block@0x74 void *`; `var_250@0x84 _DWORD`; `var_24C@0x88 _DWORD`; `destinationBounds@0x8c RectBounds size 0x10`; `var_238@0x9c void *`; `var_228@0xac _DWORD`; `var_224@0xb0 _DWORD`; `var_220@0xb4 RectBounds size 0x10`; `Buffer@0xc4 wchar_t size 2`; `var_110@0x1c4 wchar_t size 2`; `var_10@0x2c4 _DWORD`; `var_C@0x2c8 _DWORD`; `var_4@0x2d0 _DWORD`; `__saved_registers@0x2d4 _DWORD`; `__return_address@0x2d8 _UNKNOWN *`; `arg_4@0x2e0 _DWORD`.
- Physical stack-span reconciliation: `outContext` is the sole context at `[ebp-0x2a0,ebp-0x278)` and is explicitly initialized before either lookup; `destinationBounds` is the row rectangle at `[ebp-0x248,ebp-0x238)`; `var_220` is the one reused name/progress/count rectangle at `[ebp-0x220,ebp-0x210)`; `Buffer` spans `[ebp-0x210,ebp-0x110)` and `var_110` spans `[ebp-0x110,ebp-0x10)`, each exactly `0x100` bytes / 128 wide characters despite IDA displaying only the first element as size 2.

## Direct Xref / Caller Inventory

- UID0003FA inbound xrefs: exactly `{0x0056ee7d data}`. Outbound xrefs: none.
- Consumer direct code callers: zero. Inbound data xrefs: exactly `{0x00624624 data}` from the CollectionPane primary vtable.
- Consumer profiled callee set: `0x00457a60 EPFTileContext_Initialize`; `0x00543d70 PaletteLib__GetPaletteByName`; `0x004d02f0 ResourceLayoutTable_LookupLayoutEntry`; `0x004b9690 SetTextBackColor behavior`; profile self artifact `0x0056edc0`; `0x004b9980 GrafPort_RenderTileFrame`; `0x0041b9b0` formatting; `0x00421590 SimpleUString assignment`; `0x00523120 MetaMan_FindEntry`; `0x005c7526 free`; `0x004b9680 GrafPort_SetTextColor`; `0x004b78f0 RectBounds_Offset`; `0x004bad70 DrawTextInRect`; `0x005c772f` security cookie; `0x005cd607` invalid-parameter path; `0x00421310` string helper; `0x005c956c` C++ handler.
- Indirect reachability is through virtual dispatch on CollectionPane primary slot `+0x44`; absence of direct code callers is expected and does not imply dead code.
- The target has no second consumer, helper xref, constructor xref, or address escape.

## Documentation Evidence And IDA Status

- UID0003FA current prose records values, the single SIMD reference, exact local source placement, class ownership/emission, covered-by formal CPP, rejected standalone forms, and final generated disposition.
- UID0003Y6 identifies `CollectionPane::OnPaint`, its major resources, and current complete formal CPP. The stale blank-CPP/CPP-only-layout state is dated history. UID0001TZ emits exact declarations through H after `#include "../../util/StringUtil.h"`; the CollectionPane preamble includes `UserPane.h`, while EPFTileContext H and UID00002X H supply the remaining complete types.
- UID0000D9's accepted public SSO-7 declaration provides `Assign`, `MutableData`, inline `Data() const`, and inline `Length() const`, while rejecting a `c_str` facade, implicit assignment, and `operator==`. Fresh live OnPaint decompilation independently establishes read-only SSO selection and `+0x10` length access from `const SimpleUString *`; the source uses only `Assign`, those accessors, and `wcslen` for the copy/fallback/draw flow.
- UID00002X maps the full class method family and exact `0x10c` field span. Its current declaration supplies every established CollectionPane member exactly once and preserves inherited defaults rather than redeclaring them; Section 22 now adds the ten missing definitions, direct `Event.h`/`Config.h` dependencies, and the exact ScrollCollectionPane friend support required by binary-faithful direct state access.
- Complete declaration inventory and basis:

| Declaration | Address/slot evidence | Resolution |
|---|---|---|
| `CollectionPane()` | `[0x0056e940,0x0056e9e2)`; PanelPane construction and three vptr stores | Source lifecycle constructor, no arguments. |
| `virtual ~CollectionPane()` | raw `[0x0056e9f0,0x0056ea25)` plus scalar wrapper UID00038Z | One source virtual destructor; wrapper/thunks remain compiler-only. |
| `virtual void UpdateRenderRegion(const RectBounds *bounds)` | `0x0056ec50`, primary `+0x0c`; exact Pane family contract | Supersedes provisional by-value/reference spelling. |
| `virtual void AddToLayer(RectBounds *bounds, int order, Pane *previousPane, Layer *layer)` | `0x0056fad0`, primary `+0x30`; live base call consumes all four arguments | Exact inherited name/signature; behavior alias `AttachToLayer` is not a second method. |
| `virtual void RemoveFromLayer()` | `0x0056fb40`, primary `+0x38`; child detach then Pane base call | Exact inherited name; behavior alias `DetachFromLayer` is not a second method. |
| `virtual void OnPaint()` | `0x0056edc0`, primary `+0x44` | Exact consuming virtual. |
| `virtual void OnActivate(const unsigned char *packetData)` | `0x0056ea30`, primary `+0x48`; packet pointer is consumed | Exact PanelPane activation contract; `InitializeCollectionData` remains a behavior alias only. |
| `virtual bool HandlePointerOrMouseEvent(Event *event)` | `0x0056f670`, EventHandler `+0x04`; complete-object recovery is `this-0xa0` | Supersedes provisional `OnInputEvent`/`HandleInput` spelling. |
| `virtual bool HandleKeyOrTextEvent(Event *event)` | five-byte false body `0x0056f660`, EventHandler `+0x08` | Resolves the former `VirtualFalseStubA`/key-text candidate. |
| `virtual bool HandlePacketEvent(Event *event)` | five-byte false body `0x0056f800`, EventHandler `+0x10` | Existing accepted packet-event declaration retained. |
| `void UpdateScrollRange()` | `0x0056ece0`; no stack arguments; five caller families | Exact private range/state synchronizer. |
| `void LoadCollectionGroupRecords(CollectionGroupRecord *group)` | `0x0056f810`; both callers pass one group base at `+0x3ec8` | Exact pointer ABI; unused EDX is decompiler fastcall noise, not a second source argument. |
| `void OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition)` | `0x0056fa90`; `0x005631e5` passes orientation/old/new in the established scroll-owner ABI | All three source arguments retained although orientation is unused. |
| `void SetInvalidGroupSlotRect(unsigned short visibleSlot, RectBounds *outBounds)` | raw `[0x0056fb60,0x0056fb7a)`, `retn 8`; first argument ignored, second receives four `-1` values | Retained non-static member ABI and descriptive source name. |
| `void GetVisibleGroupSlotRect(unsigned short visibleSlot, RectBounds *outBounds)` | raw `[0x0056fb80,0x0056fbd3)`, `retn 8`; unsigned `0..4` test and exact row formula | Retained non-static member ABI and descriptive source name. |
| `short HitTestVisibleGroupSlot(int y, int x)` | `[0x0056fbe0,0x0056fc73)`, `retn 8`; input handler loads complete `this` into ECX and consumes AX as `0..4/0xffff` | Project y/x order and 16-bit result supersede the provisional `(int x, int y)` wording. |
| `void OpenOrRequestGroupDetail(int groupIndex)` | `[0x0056fc80,0x0056fd61)`; sole call at `0x0056f7a7` | Existing accepted detail dispatch declaration retained. |

- Inherited `HandleImeEvent`, system/control, type-19, ordering, offset, acceptance, and timer defaults are not overridden by CollectionPane and therefore remain inherited. Vtables, complete-object locators, adjustors, and scalar deleting wrappers remain compiler output rather than handwritten declarations. UID00038U's three table views are exactly compiler-covered by the complete class declaration and ordinary virtual bodies; its formal CPP is an inert explanatory marker and formal H is blank.
- `LoadCollectionGroupRecords` and `OnScrollPositionChanged` remain public because callers at `0x005147a2` and `0x005631e5` originate outside CollectionPane. `UpdateScrollRange`, the rectangle helpers, and detail dispatch are private in the best source-facing declaration; exact original access labels remain a non-semantic confidence cap.
- UID0000IC owns the `.cpp` family and remains the file destination; class UID00002X is the semantic owner/emitter for method-local physical provenance.
- UID0002V2 and UID0001HD are correctly non-emitting indexes. Their current broad ownership does not override exact-child semantic ownership.
- The ordinary UID0001HD page is currently `88/91`, `RECONSTRUCTABLE:FALSE`, with blank `EMITTER_UIDS`/position and an explicit non-emitting split/index disposition. Its physical manual coverage row still says `reconstructable : 82% : strong`; Section 28 therefore supplies an exact supervisor-owned no-loss replacement rather than preserving that stale row. The replacement uses `very-strong` because the ordinary confidence is `91` and its broad-range boundary finding is explicitly very strong, while retaining the ordinary page's stronger caveats around exact-child source inference in the row detail.
- Current IDA has no `CollectionPane` UDT. The inherited-facet function type therefore remains `void __thiscall(GrafPort *this)` under this report; source-facing C++ may still use `CollectionPane::OnPaint()`.

## Ranked Ownership Analysis

1. UID00002X `CollectionPane` class: strongest. The physical item exists solely to initialize a local in a class virtual method, and project convention routes method-local covered-by constants through the class emitter.
2. UID0000IC `CollectionPane` file: correct physical source file but too broad as canonical semantic owner once the exact class method is known.
3. UID0003Y6 `CollectionPaneOnPaint`: exact semantic consumer, but memory-method pages emit through class owners rather than becoming canonical owners for sibling physical constants.
4. UID0002V2 mixed read-only parent: boundary/index authority only; explicitly non-reconstructable and non-emitting.
5. UID0001HD broad executable parent: split/index authority only; it cannot own data at `0x00624c10` or emit aggregate method code.
- Final: target owner/emitter UID00002X, file destination UID0000IC, method source UID0003Y6.

## Source Placement

- Source root: `NexusTK/ui/panels/CollectionPane.cpp`.
- Class route: UID00002X `CollectionPane`.
- Source order: complete `CollectionPane::OnPaint()` at position `70`; target covered-by marker at position `75`.
- Target formal CPP must not define a symbol. The marker documents that the binary item is reconstructed by the local initializer inside the preceding method body.
- Target formal H and method H remain blank. UID00002X supplies the relevant class declarations once, avoiding duplicate member declarations.
- No placement in `CollectionDialogPane.cpp`, `ScrollCollectionPane.cpp`, a resource file, a global-data file, or a separate constant translation unit is supported.

## Range / Split / Padding / Reclassification Analysis

- Exact target item `[0x00624c10,0x00624c20)` has no internal padding. All 16 bytes are four `RectBounds` fields.
- Exact predecessor `[0x00624c00,0x00624c10)` is `xmmword_624C00`, bytes `0A 00 00 00 0A 00 00 00 0A 00 00 00 3E 00 00 00`, SHA256 `D27BB1CCAFDCBBC3D04DFBF386071F81F4CBE211A09438B9E49FD503ADBDFF3C`, with sole SelfLookPane xref `0x0056771f`.
- Exact successor item `[0x00624c20,0x00624c30)` is `xmmword_624C20`, bytes `3F 00 00 00 79 00 00 00 07 00 00 00 3F 00 00 00`, SHA256 `1A42F1ECC2A5384B1A43BC6E3F9727AB3D9384318B1090B2C764555D1B0CD90A`, with sole SelfLookPane xref `0x005676e8`.
- Broad UID0002V2 ends at `0x00624c60`, not stale `0x00624c64`. Nearby children are UID0003F8 at `0x00624bf0`, UID0003F9 at `0x00624c00`, UID0003FA at `0x00624c10`, and UID0003FB at `0x00624c20-0x00624c60`.
- Reclassification is source-shape only: keep the exact data item/range, but classify its emitted source representation as a method-local covered-by constant rather than a standalone object.

## Negative Evidence Summary

- No second xref, no pointer to the data item, no address escape, no write, and no identity comparison exists.
- No `CollectionPane` UDT exists in current IDA, so a typed `CollectionPane *` signature would depend on a new analysis type outside this report.
- No target-internal padding or split is supported.
- No constructor call exists or is required; the local POD aggregate initialization lowers directly to the pooled SIMD data.
- No header declaration is needed for the physical constant.
- No generated file or generated Markdown was edited directly; no manual coverage edit, IDA mutation, lifecycle action, or archive movement occurred. Scoped ordinary validators and waited generated refreshes are recorded in Section 31.

## IDA Rename / Type / Comment Recommendations

These are inert deterministic supervisor handoff rows. A future supervisor must dynamically select the then-current canonical session with fresh `idb_list` and schema-1 runtime attestation, reread every literal precondition, apply rows in order, and stop on any mismatch. The dated session in Section 6 is evidence only.

### IDA-FA-01

- Classification/dependency: `apply`; ordered stage 1 from a fresh baseline.
- Complete immediate precondition: function entity head `0x0056edc0`, range `[0x0056edc0,0x0056f655)`, size `0x895`, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`; name exactly `sub_56EDC0`; type exactly `void __thiscall(GrafPort *this)`; AR absent; AP absent; FR absent; FP absent; direct code callers empty; inbound data xrefs exactly `{0x00624624}`. Full frame exactly: `var_2C8@0x0c char[4] size4; var_2C4@0x10 _DWORD size4; ArgList@0x14 char[4] size4; var_2BC@0x18 _DWORD size4; var_2B8@0x1c _DWORD size4; var_2B4@0x20 _DWORD size4; var_2B0@0x24 ResourceLayoutTable * size4; var_2AC@0x28 _DWORD size4; var_2A8@0x2c _DWORD size4; var_2A1@0x33 _BYTE size1; outContext@0x34 EPFTileContext size0x28; var_278@0x5c void * size4; var_268@0x6c _DWORD size4; var_264@0x70 _DWORD size4; Block@0x74 void * size4; var_250@0x84 _DWORD size4; var_24C@0x88 _DWORD size4; destinationBounds@0x8c RectBounds size0x10; var_238@0x9c void * size4; var_228@0xac _DWORD size4; var_224@0xb0 _DWORD size4; var_220@0xb4 RectBounds size0x10; Buffer@0xc4 wchar_t size2; var_110@0x1c4 wchar_t size2; var_10@0x2c4 _DWORD size4; var_C@0x2c8 _DWORD size4; var_4@0x2d0 _DWORD size4; __saved_registers@0x2d4 _DWORD size4; __return_address@0x2d8 _UNKNOWN * size4; arg_4@0x2e0 _DWORD size4`. Target-use instruction entity head/range `[0x0056ee7d,0x0056ee84)`, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes `0F 28 05 10 4C 62 00`, SHA256 `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`. Target data entity head/range `[0x00624c10,0x00624c20)`, name `xmmword_624C10`, type absent, AR absent, AP absent, FR/FP not applicable, bytes `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00`, SHA256 `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`, inbound xrefs exactly `{0x0056ee7d}`. Exact and case-insensitive `CollectionPane__OnPaint` collisions are absent.
- Public endpoint/exact value: `rename` with exact fields `database:"<fresh runtime-attested session ID>", batch:{func:{addr:"0x0056edc0",name:"CollectionPane__OnPaint"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`.
- Complete expected readback: function entity head `0x0056edc0`, range `[0x0056edc0,0x0056f655)`, size `0x895`, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`; name exactly `CollectionPane__OnPaint`; type exactly `void __thiscall(GrafPort *this)`; AR absent; AP absent; FR absent; FP absent; direct code callers empty; inbound data xrefs exactly `{0x00624624}`. Full frame exactly: `var_2C8@0x0c char[4] size4; var_2C4@0x10 _DWORD size4; ArgList@0x14 char[4] size4; var_2BC@0x18 _DWORD size4; var_2B8@0x1c _DWORD size4; var_2B4@0x20 _DWORD size4; var_2B0@0x24 ResourceLayoutTable * size4; var_2AC@0x28 _DWORD size4; var_2A8@0x2c _DWORD size4; var_2A1@0x33 _BYTE size1; outContext@0x34 EPFTileContext size0x28; var_278@0x5c void * size4; var_268@0x6c _DWORD size4; var_264@0x70 _DWORD size4; Block@0x74 void * size4; var_250@0x84 _DWORD size4; var_24C@0x88 _DWORD size4; destinationBounds@0x8c RectBounds size0x10; var_238@0x9c void * size4; var_228@0xac _DWORD size4; var_224@0xb0 _DWORD size4; var_220@0xb4 RectBounds size0x10; Buffer@0xc4 wchar_t size2; var_110@0x1c4 wchar_t size2; var_10@0x2c4 _DWORD size4; var_C@0x2c8 _DWORD size4; var_4@0x2d0 _DWORD size4; __saved_registers@0x2d4 _DWORD size4; __return_address@0x2d8 _UNKNOWN * size4; arg_4@0x2e0 _DWORD size4`. Target-use instruction head/range `[0x0056ee7d,0x0056ee84)`, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0F 28 05 10 4C 62 00` / `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`. Target data head/range `[0x00624c10,0x00624c20)`, name `xmmword_624C10`, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00` / `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`, inbound xrefs exactly `{0x0056ee7d}`.
- Protections/hard stops: stop before action if any literal precondition or collision state differs. Stop and discard unsaved work if any expected field differs. Never overwrite a name; do not mutate type, frame, comments, bytes, boundaries, xrefs, vtable cell, neighbors, or padding.

### IDA-FA-02

- Classification/dependency: `apply`; ordered stage 2 only after exact IDA-FA-01 poststate.
- Complete immediate precondition: function entity head `0x0056edc0`, range `[0x0056edc0,0x0056f655)`, size `0x895`, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`; name exactly `CollectionPane__OnPaint`; type exactly `void __thiscall(GrafPort *this)`; AR absent; AP absent; FR absent; FP absent; direct code callers empty; inbound data xrefs exactly `{0x00624624}`. Full frame exactly: `var_2C8@0x0c char[4] size4; var_2C4@0x10 _DWORD size4; ArgList@0x14 char[4] size4; var_2BC@0x18 _DWORD size4; var_2B8@0x1c _DWORD size4; var_2B4@0x20 _DWORD size4; var_2B0@0x24 ResourceLayoutTable * size4; var_2AC@0x28 _DWORD size4; var_2A8@0x2c _DWORD size4; var_2A1@0x33 _BYTE size1; outContext@0x34 EPFTileContext size0x28; var_278@0x5c void * size4; var_268@0x6c _DWORD size4; var_264@0x70 _DWORD size4; Block@0x74 void * size4; var_250@0x84 _DWORD size4; var_24C@0x88 _DWORD size4; destinationBounds@0x8c RectBounds size0x10; var_238@0x9c void * size4; var_228@0xac _DWORD size4; var_224@0xb0 _DWORD size4; var_220@0xb4 RectBounds size0x10; Buffer@0xc4 wchar_t size2; var_110@0x1c4 wchar_t size2; var_10@0x2c4 _DWORD size4; var_C@0x2c8 _DWORD size4; var_4@0x2d0 _DWORD size4; __saved_registers@0x2d4 _DWORD size4; __return_address@0x2d8 _UNKNOWN * size4; arg_4@0x2e0 _DWORD size4`. Target-use instruction entity head/range `[0x0056ee7d,0x0056ee84)`, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0F 28 05 10 4C 62 00` / `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`. Target data entity head/range `[0x00624c10,0x00624c20)`, name `xmmword_624C10`, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00` / `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`, inbound xrefs exactly `{0x0056ee7d}`.
- Public endpoint/exact value: `set_function_comments` with exact fields `database:"<fresh runtime-attested session ID>", items:{addr:"0x0056edc0",comment:"CollectionPane paint override: draws the CLTINV background and up to five CLTLIST rows; local RectBounds {6,14,161,62} seeds row bounds, top/bottom advance by 50, and each row renders GroupNames, percent, and collected/total text from CollectionPlayerDataView."}`.
- Complete expected readback: function entity head `0x0056edc0`, range `[0x0056edc0,0x0056f655)`, size `0x895`, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`; name exactly `CollectionPane__OnPaint`; type exactly `void __thiscall(GrafPort *this)`; AR absent; AP absent; FR exactly `CollectionPane paint override: draws the CLTINV background and up to five CLTLIST rows; local RectBounds {6,14,161,62} seeds row bounds, top/bottom advance by 50, and each row renders GroupNames, percent, and collected/total text from CollectionPlayerDataView.`; FP absent; direct code callers empty; inbound data xrefs exactly `{0x00624624}`. Full frame exactly: `var_2C8@0x0c char[4] size4; var_2C4@0x10 _DWORD size4; ArgList@0x14 char[4] size4; var_2BC@0x18 _DWORD size4; var_2B8@0x1c _DWORD size4; var_2B4@0x20 _DWORD size4; var_2B0@0x24 ResourceLayoutTable * size4; var_2AC@0x28 _DWORD size4; var_2A8@0x2c _DWORD size4; var_2A1@0x33 _BYTE size1; outContext@0x34 EPFTileContext size0x28; var_278@0x5c void * size4; var_268@0x6c _DWORD size4; var_264@0x70 _DWORD size4; Block@0x74 void * size4; var_250@0x84 _DWORD size4; var_24C@0x88 _DWORD size4; destinationBounds@0x8c RectBounds size0x10; var_238@0x9c void * size4; var_228@0xac _DWORD size4; var_224@0xb0 _DWORD size4; var_220@0xb4 RectBounds size0x10; Buffer@0xc4 wchar_t size2; var_110@0x1c4 wchar_t size2; var_10@0x2c4 _DWORD size4; var_C@0x2c8 _DWORD size4; var_4@0x2d0 _DWORD size4; __saved_registers@0x2d4 _DWORD size4; __return_address@0x2d8 _UNKNOWN * size4; arg_4@0x2e0 _DWORD size4`. Target-use instruction head/range `[0x0056ee7d,0x0056ee84)`, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0F 28 05 10 4C 62 00` / `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`. Target data head/range `[0x00624c10,0x00624c20)`, name `xmmword_624C10`, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00` / `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`, inbound xrefs exactly `{0x0056ee7d}`.
- Protections/hard stops: stop if any IDA-FA-01 poststate or other literal precondition differs. Stop and discard unsaved work unless FR is exact, FP remains absent, and every protected field matches. Do not call an address-comment endpoint for this function comment.

### IDA-FA-03

- Classification/dependency: `apply`; ordered stage 3 only after exact IDA-FA-02 poststate.
- Complete immediate precondition: target data entity head `0x00624c10`, range `[0x00624c10,0x00624c20)`, size 16, name `xmmword_624C10`, type absent, AR absent, AP absent, FR/FP not applicable, bytes `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00`, SHA256 `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`, inbound xrefs exactly `{0x0056ee7d}`. Consumer function entity head `0x0056edc0`, range `[0x0056edc0,0x0056f655)`, size `0x895`, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`; name exactly `CollectionPane__OnPaint`; type exactly `void __thiscall(GrafPort *this)`; AR absent; AP absent; FR exactly `CollectionPane paint override: draws the CLTINV background and up to five CLTLIST rows; local RectBounds {6,14,161,62} seeds row bounds, top/bottom advance by 50, and each row renders GroupNames, percent, and collected/total text from CollectionPlayerDataView.`; FP absent; direct code callers empty; inbound data xrefs exactly `{0x00624624}`. Full frame exactly: `var_2C8@0x0c char[4] size4; var_2C4@0x10 _DWORD size4; ArgList@0x14 char[4] size4; var_2BC@0x18 _DWORD size4; var_2B8@0x1c _DWORD size4; var_2B4@0x20 _DWORD size4; var_2B0@0x24 ResourceLayoutTable * size4; var_2AC@0x28 _DWORD size4; var_2A8@0x2c _DWORD size4; var_2A1@0x33 _BYTE size1; outContext@0x34 EPFTileContext size0x28; var_278@0x5c void * size4; var_268@0x6c _DWORD size4; var_264@0x70 _DWORD size4; Block@0x74 void * size4; var_250@0x84 _DWORD size4; var_24C@0x88 _DWORD size4; destinationBounds@0x8c RectBounds size0x10; var_238@0x9c void * size4; var_228@0xac _DWORD size4; var_224@0xb0 _DWORD size4; var_220@0xb4 RectBounds size0x10; Buffer@0xc4 wchar_t size2; var_110@0x1c4 wchar_t size2; var_10@0x2c4 _DWORD size4; var_C@0x2c8 _DWORD size4; var_4@0x2d0 _DWORD size4; __saved_registers@0x2d4 _DWORD size4; __return_address@0x2d8 _UNKNOWN * size4; arg_4@0x2e0 _DWORD size4`. Target-use instruction entity head/range `[0x0056ee7d,0x0056ee84)`, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0F 28 05 10 4C 62 00` / `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`.
- Public endpoint/exact value: `set_address_repeatable_comments` with exact fields `database:"<fresh runtime-attested session ID>", items:{addr:"0x00624c10",comment:"Packed int32 RectBounds {left=6, top=14, right=161, bottom=62}; sole movaps load at 0x0056ee7d seeds CollectionPane::OnPaint row bounds, advanced by 50 pixels per row; source is a use-site local initializer, not a standalone object."}`.
- Complete expected readback: target data entity head `0x00624c10`, range `[0x00624c10,0x00624c20)`, size 16, name `xmmword_624C10`, type absent, AR absent, AP exactly `Packed int32 RectBounds {left=6, top=14, right=161, bottom=62}; sole movaps load at 0x0056ee7d seeds CollectionPane::OnPaint row bounds, advanced by 50 pixels per row; source is a use-site local initializer, not a standalone object.`, FR/FP not applicable, bytes/hash exactly `06 00 00 00 0E 00 00 00 A1 00 00 00 3E 00 00 00` / `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`, inbound xrefs exactly `{0x0056ee7d}`. Consumer function entity head `0x0056edc0`, range `[0x0056edc0,0x0056f655)`, size `0x895`, body SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`; name exactly `CollectionPane__OnPaint`; type exactly `void __thiscall(GrafPort *this)`; AR absent; AP absent; FR exactly `CollectionPane paint override: draws the CLTINV background and up to five CLTLIST rows; local RectBounds {6,14,161,62} seeds row bounds, top/bottom advance by 50, and each row renders GroupNames, percent, and collected/total text from CollectionPlayerDataView.`; FP absent; direct code callers empty; inbound data xrefs exactly `{0x00624624}`. Full frame exactly: `var_2C8@0x0c char[4] size4; var_2C4@0x10 _DWORD size4; ArgList@0x14 char[4] size4; var_2BC@0x18 _DWORD size4; var_2B8@0x1c _DWORD size4; var_2B4@0x20 _DWORD size4; var_2B0@0x24 ResourceLayoutTable * size4; var_2AC@0x28 _DWORD size4; var_2A8@0x2c _DWORD size4; var_2A1@0x33 _BYTE size1; outContext@0x34 EPFTileContext size0x28; var_278@0x5c void * size4; var_268@0x6c _DWORD size4; var_264@0x70 _DWORD size4; Block@0x74 void * size4; var_250@0x84 _DWORD size4; var_24C@0x88 _DWORD size4; destinationBounds@0x8c RectBounds size0x10; var_238@0x9c void * size4; var_228@0xac _DWORD size4; var_224@0xb0 _DWORD size4; var_220@0xb4 RectBounds size0x10; Buffer@0xc4 wchar_t size2; var_110@0x1c4 wchar_t size2; var_10@0x2c4 _DWORD size4; var_C@0x2c8 _DWORD size4; var_4@0x2d0 _DWORD size4; __saved_registers@0x2d4 _DWORD size4; __return_address@0x2d8 _UNKNOWN * size4; arg_4@0x2e0 _DWORD size4`. Target-use instruction head/range `[0x0056ee7d,0x0056ee84)`, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0F 28 05 10 4C 62 00` / `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`.
- Protections/hard stops: stop if any IDA-FA-02 poststate or other literal precondition differs. Stop and discard unsaved work unless AP is exact, AR remains absent, and every protected field matches. Do not rename, type, redefine, merge, split, or resize the target.

### IDA-FA-04

- Classification: `no change recommended`; protected target neighbors.
- Complete current prestate: predecessor entity head/range `[0x00624c00,0x00624c10)`, size 16, name `xmmword_624C00`, type absent, AR absent, AP absent, FR/FP not applicable, bytes `0A 00 00 00 0A 00 00 00 0A 00 00 00 3E 00 00 00`, SHA256 `D27BB1CCAFDCBBC3D04DFBF386071F81F4CBE211A09438B9E49FD503ADBDFF3C`, inbound xrefs exactly `{0x0056771f}`; successor entity head/range `[0x00624c20,0x00624c30)`, size 16, name `xmmword_624C20`, type absent, AR absent, AP absent, FR/FP not applicable, bytes `3F 00 00 00 79 00 00 00 07 00 00 00 3F 00 00 00`, SHA256 `1A42F1ECC2A5384B1A43BC6E3F9727AB3D9384318B1090B2C764555D1B0CD90A`, inbound xrefs exactly `{0x005676e8}`.
- Public endpoint/exact value: no endpoint call.
- Complete expected readback: predecessor head/range `[0x00624c00,0x00624c10)`, size 16, name `xmmword_624C00`, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0A 00 00 00 0A 00 00 00 0A 00 00 00 3E 00 00 00` / `D27BB1CCAFDCBBC3D04DFBF386071F81F4CBE211A09438B9E49FD503ADBDFF3C`, inbound xrefs exactly `{0x0056771f}`; successor head/range `[0x00624c20,0x00624c30)`, size 16, name `xmmword_624C20`, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `3F 00 00 00 79 00 00 00 07 00 00 00 3F 00 00 00` / `1A42F1ECC2A5384B1A43BC6E3F9727AB3D9384318B1090B2C764555D1B0CD90A`, inbound xrefs exactly `{0x005676e8}`.
- Protections/hard stops: any edit is unauthorized. Stop if either prestate differs or target boundaries overlap a neighbor.

### IDA-FA-05

- Classification: `no change recommended`; protected vtable cell, target-use instruction, and function padding.
- Complete current prestate: vtable entity head/range `[0x00624624,0x00624628)`, size 4, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes `C0 ED 56 00`, SHA256 `1F96B6D9219361704346357879A4CADB0D5C78B3A3F0EA6116013F08DE871297`, outbound xrefs exactly `{0x0056edc0}`; target-use instruction entity head/range `[0x0056ee7d,0x0056ee84)`, size 7, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes `0F 28 05 10 4C 62 00`, SHA256 `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`; predecessor padding `[0x0056edb1,0x0056edc0)`, 15 bytes all `CC`, SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; successor padding `[0x0056f655,0x0056f660)`, 11 bytes all `CC`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Public endpoint/exact value: no endpoint call.
- Complete expected readback: vtable head/range `[0x00624624,0x00624628)`, size 4, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `C0 ED 56 00` / `1F96B6D9219361704346357879A4CADB0D5C78B3A3F0EA6116013F08DE871297`, outbound xrefs exactly `{0x0056edc0}`; target-use instruction head/range `[0x0056ee7d,0x0056ee84)`, size 7, name absent, type absent, AR absent, AP absent, FR/FP not applicable, bytes/hash exactly `0F 28 05 10 4C 62 00` / `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`; predecessor padding `[0x0056edb1,0x0056edc0)` remains 15 bytes all `CC` with SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`; successor padding `[0x0056f655,0x0056f660)` remains 11 bytes all `CC` with SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Protections/hard stops: any change is unauthorized. Stop if any boundary, byte, channel, item model, hash, or xref differs.

- Ordered stage contract: stage 1 starts only from the complete literal fresh baseline in IDA-FA-01; stage 2 starts only after complete IDA-FA-01 readback; stage 3 starts only after complete IDA-FA-02 readback. After stage 3, reread the complete literal states of IDA-FA-01 through IDA-FA-05 before any save decision.
- Permitted deltas are only function name `sub_56EDC0 -> CollectionPane__OnPaint`, function FR `absent -> exact IDA-FA-02 text`, and target AP `absent -> exact IDA-FA-03 text`. Every other named field and every byte/xref/range/frame is protected.
- Supporting type declaration: none. `RectBounds` already exists; `CollectionPane` does not. No fixed whole-IDB hash is future authority.

Exact cross-report IDA action inventory. These peer rows remain exclusively B002-owned; they authorize no B008 endpoint call and are disjoint from IDA-FA-01..03 and the B008-exclusive function head `0x0056edc0`.

| B002 row | Exact entity | Endpoint / exact permitted delta | Reconciliation |
|---|---|---|---|
| D01 | `[0x00624a98,0x00624ab0)` `aCollections` | `set_address_repeatable_comments` at `0x00624a98`; AP `absent -> Compiler/linker-pooled UTF-16 L"Collections" metadata-table literal; four use-site refs in CollectionPane::OnActivate and CollectionPane::LoadCollectionGroupRecords; source emits repeated method-local expressions, not a standalone object.` | Preserve B002 action and all D01 bytes, item state, other channels, and four xrefs; B008 performs no mutation. |
| D02 | `[0x00624ab0,0x00624ac6)` `aGroupnames` | `set_address_repeatable_comments` at `0x00624ab0`; AP `absent -> Compiler/linker-pooled UTF-16 L"GroupNames" metadata-table literal; three use-site refs in CollectionPane::OnActivate and CollectionPane::OnPaint; source emits repeated method-local expressions, not a standalone object.` | Preserve B002 action and all D02 bytes, item state, other channels, and three xrefs; B008 performs no mutation. |
| D03 | logical `[0x00624ac8,0x00624ade)` across `aCl_3` and `aTinvEpf` | `set_address_repeatable_comments` at `0x00624ac8`; AP `absent -> Logical UTF-16 L"CLTINV.EPF" resource literal spans current IDA items aCl_3 and aTinvEpf; used by CollectionPane::OnPaint and CollectionPane2::OnPaint; preserve the item split and emit use-site expressions only.` | Preserve B002 action, both physical items, alignments, channels, bytes, and two xrefs; B008 performs no mutation. |
| D04 | logical `[0x00624ae0,0x00624af8)` across `aCl_4` and `aTlistEpf` | `set_address_repeatable_comments` at `0x00624ae0`; AP `absent -> Logical UTF-16 L"CLTLIST.EPF" resource literal spans current IDA items aCl_4 and aTlistEpf; one CollectionPane::OnPaint row-frame lookup; preserve the item split and emit the use-site expression only.` | Preserve B002 action, both physical items, alignment, channels, bytes, and sole xref; B008 performs no mutation. |
| D05 | logical `[0x00624af8,0x00624b10)` across `aCl_5` and `aTlistPal` | `set_address_repeatable_comments` at `0x00624af8`; AP `absent -> Logical UTF-16 L"CLTLIST.PAL" resource literal spans current IDA items aCl_5 and aTlistPal; one CollectionPane::OnPaint row-palette lookup; preserve the item split and emit the use-site expression only.` | Preserve B002 action, both physical items, channels, bytes, and sole xref; B008 performs no mutation. |
| D06 | logical `[0x00624b10,0x00624b18)` across eight raw one-byte heads | `set_address_repeatable_comments` at `0x00624b10`; AP `absent -> UTF-16 L"\xC548\xB098\xC640" three-code-unit missing-GroupNames fallback used only by CollectionPane::OnPaint; raw bytes are a source use-site literal, not a standalone object.` | Preserve B002 action, raw classification, all eight heads, channels, bytes, and sole xref; never make data, merge, split, rename, or type. |
| D07 | logical `[0x00624b18,0x00624b24)` across `aD_19` and suffix item | `set_address_repeatable_comments` at `0x00624b18`; AP `absent -> Logical UTF-16 L"%d %%" completion-percent format spans current IDA head/suffix items; one CollectionPane::OnPaint use; preserve the split and emit the use-site expression only.` | Preserve B002 action, exact spacing/doubled percent, both physical items, channels, bytes, and sole xref; B008 performs no mutation. |
| D08 | logical `[0x00624b24,0x00624b30)` across `aD_20` and `aD_8` | `set_address_repeatable_comments` at `0x00624b24`; AP `absent -> Logical UTF-16 L"%d/%d" collected/total format spans current IDA head/suffix items; one CollectionPane::OnPaint use; preserve the split and emit the use-site expression only.` | Preserve B002 action, both physical items, channels, bytes, target end, and sole xref; B008 performs no mutation. |
| P01 | alignments `[0x00624ac6,0x00624ac8)` and `[0x00624ade,0x00624ae0)` | No endpoint; no change recommended. | Preserve each two-byte `00 00` item, hash, absent channels, and empty xref sets; any delta is a B002 hard stop. |
| P02 | predecessor `[0x00624a84,0x00624a98)` `aGroupEpf` | No endpoint; no change recommended. | Preserve exact existing GROUP.EPF AP, bytes/hash, type, and three xrefs; any delta is a B002 hard stop. |
| P03 | successor `[0x00624b30,0x00624b4a)` `aGroupcolEpf` | No endpoint; no change recommended. | Preserve exact existing GROUPCOL.EPF AP, bytes/hash, type, and sole xref; any delta is a B002 hard stop. |

B002's D01-D08 are independent address-comment-only stages, but its full row-local prestates and readbacks remain mandatory. After each B002 action, reread that row plus all previously touched AP channels; before save, reread D01-D08 and P01-P03 in full. The only B002-permitted deltas are those eight AP channels. No B002 function rename, function type, function comment, target make-data, name, type, split, merge, boundary, byte, or xref delta is authorized.

## First-Draft C++ Recommendation

- Exact formal target `RECONSTRUCTION_CPP CODE`:

```cpp
// Covered by CollectionPane::OnPaint() local rowBounds aggregate initializer:
// RectBounds rowBounds = { 6, 14, 161, 62 };
```

- Exact formal target `RECONSTRUCTION_H CODE`:

```cpp
```

- Exact formal UID0003Y6 `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::OnPaint()
{
    EPFTileContext tileContext;
    tileContext.Initialize();

    SimpleUString groupName;
    wchar_t groupKeyText[128];
    wchar_t valueText[128];

    DLPalette *inventoryPalette =
        g_pPaletteLib->GetPaletteByName(L"ITEMINV.PAL");
    g_pEPFLib->LookupLayoutEntry(L"CLTINV.EPF", 0, &tileContext);
    g_pfnBlitSprite(this, &tileContext, &tileContext.bounds,
                    &m_visibleBounds, 0, inventoryPalette, 0);

    SetDrawMode(1);
    RectBounds rowBounds = { 6, 14, 161, 62 };
    SetTextBackColor(0);

    CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    int firstGroup = static_cast<int>(m_groupCountSnapshot) - 5;
    if (static_cast<int>(m_firstVisibleGroup) + 5 <=
        static_cast<int>(m_groupCountSnapshot))
        firstGroup = m_firstVisibleGroup;
    if (firstGroup < 0)
        firstGroup = 0;

    for (int visibleRow = 0, groupIndex = firstGroup;
         visibleRow < 5 && groupIndex < collectionData.groupCount;
         ++visibleRow, ++groupIndex) {
        const CollectionGroupRecord &group =
            collectionData.groups[groupIndex];
        RectBounds textBounds = rowBounds;
        const int completionPercent =
            100 * group.collectedEntries / group.totalEntries;

        g_pEPFLib->LookupLayoutEntry(
            L"CLTLIST.EPF", completionPercent / 100, &tileContext);
        RenderTileFrame(&tileContext, &tileContext.bounds, &rowBounds,
                        0, L"CLTLIST.PAL", 0);

        textBounds.left = rowBounds.left + 55;
        textBounds.right = rowBounds.left + 155;
        textBounds.top = rowBounds.top + 6;
        textBounds.bottom = rowBounds.top + 20;
        swprintf_s(groupKeyText, 128, L"%d", group.groupType);

        SimpleUString key;
        key.Assign(groupKeyText,
                   static_cast<unsigned int>(wcslen(groupKeyText)));
        SimpleUString tableName;
        tableName.Assign(L"GroupNames", 10);
        const SimpleUString *groupNameEntry =
            g_pMetaMan->FindEntry(&tableName, &key, 0);
        if (&groupName != groupNameEntry) {
            const wchar_t *entryText = groupNameEntry->Data();
            groupName.Assign(
                entryText,
                groupNameEntry->Length());
        }
        if (groupName.Data()[0] == L'\0')
            groupName.Assign(L"\xC548\xB098\xC640", 3);

        const wchar_t *groupNameText = groupName.Data();
        const int groupNameLength = static_cast<int>(wcslen(groupNameText));
        SetTextColor(0x80);
        textBounds.Offset(-1, -1);
        if (completionPercent == 100) {
            for (int pass = 0; pass < 3; ++pass) {
                for (int edge = 0; edge < 4; ++edge) {
                    DrawTextInRect(groupNameText, groupNameLength,
                                   &textBounds);
                    textBounds.Offset(0, 1);
                }
                textBounds.Offset(1, -4);
            }
        }

        textBounds.left = rowBounds.left + 55;
        textBounds.right = rowBounds.left + 155;
        textBounds.top = rowBounds.top + 6;
        textBounds.bottom = rowBounds.top + 20;
        SetTextColor(0x8f);
        DrawTextInRect(groupNameText, groupNameLength, &textBounds);
        textBounds.Offset(1, 0);
        SetTextColor(0x8f);
        DrawTextInRect(groupNameText, groupNameLength, &textBounds);

        textBounds.left = rowBounds.left + 55;
        textBounds.right = rowBounds.left + 155;
        textBounds.top = rowBounds.top + 30;
        textBounds.bottom = rowBounds.top + 44;
        swprintf_s(valueText, 128, L"%d %%", completionPercent);
        SetTextColor(0x8f);
        DrawTextInRect(valueText, wcslen(valueText), &textBounds);
        if (completionPercent == 100) {
            SetTextColor(0x0e);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(1, 0);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(-1, 0);
        }

        swprintf_s(valueText, 128, L"%d/%d",
                   group.collectedEntries, group.totalEntries);
        SetTextColor(0x8f);
        textBounds.left = textBounds.right -
            6 * (static_cast<int>(wcslen(valueText)) + 2);
        DrawTextInRect(valueText, wcslen(valueText), &textBounds);
        if (completionPercent == 100) {
            SetTextColor(0x25);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(1, 0);
            DrawTextInRect(valueText, wcslen(valueText), &textBounds);
            textBounds.Offset(-1, 0);
        }

        rowBounds.top += 50;
        rowBounds.bottom += 50;
    }
}
```

- Exact formal UID0003Y6 `RECONSTRUCTION_H CODE`:

```cpp
```

- Exact preserved B002-owned UID0003F1 `RECONSTRUCTION_CPP CODE`:

```cpp
// [UID:0003F1] No standalone source object is emitted for this pooled literal run.
// Its eight UTF-16 literals are reconstructed at the CollectionPane::OnActivate,
// CollectionPane::OnPaint, CollectionPane::LoadCollectionGroupRecords,
// and CollectionPane2::OnPaint use sites.
```

- Exact B002-owned UID0003F1 `RECONSTRUCTION_H CODE` remains blank:

```cpp
```

- Exact reconciled B002-owned UID0003Y3 `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::OnActivate(const unsigned char *packetData)
{
    CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    if (collectionData.metadataLoaded) {
        UpdateScrollRange();
        InvalidateRect(&m_visibleBounds);
        return;
    }

    {
        SimpleUString tableName;
        tableName.Assign(L"Collections", 11);
        m_collectionsTable = g_pMetaMan->FindTableByName(&tableName);
    }
    if (m_collectionsTable && !m_collectionsTable->IsMaterialized())
        m_collectionsTable->MaterializeRowsIfNeeded(L"Collections");

    {
        SimpleUString tableName;
        tableName.Assign(L"GroupNames", 10);
        m_groupNamesTable = g_pMetaMan->FindTableByName(&tableName);
    }
    if (m_groupNamesTable && !m_groupNamesTable->IsMaterialized())
        m_groupNamesTable->MaterializeRowsIfNeeded(L"GroupNames");

    m_groupCount = packetData[3];
    collectionData.groupCount = static_cast<signed char>(m_groupCount);

    unsigned int packetOffset = 4;
    for (int groupIndex = 0;
         groupIndex < collectionData.groupCount;
         ++groupIndex) {
        CollectionGroupRecord &group = collectionData.groups[groupIndex];
        group.groupType = packetData[packetOffset++];
        group.collectedEntries = packetData[packetOffset++];
        LoadCollectionGroupRecords(&group);
    }

    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
    collectionData.metadataLoaded = 1;
}
```

- Exact UID0003Y3 `RECONSTRUCTION_H CODE` remains blank because UID00002X owns the declaration.

```cpp
```

- Exact reconciled B002-owned UID0003Y9 `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::LoadCollectionGroupRecords(
    CollectionGroupRecord *group)
{
    unsigned char matchingRowCount = 0;
    const MetaTable::RowMap &rows = m_collectionsTable->Rows();

    for (MetaTable::RowMap::const_iterator row = rows.begin();
         row != rows.end(); ++row) {
        const std::vector<SimpleUString> &values = row->second;
        const int groupType = _wtol(values[0].Data());
        if (static_cast<unsigned char>(groupType) != group->groupType)
            continue;

        const int entryIndexValue = _wtol(values[1].Data());
        CollectionEntryRecord &entry =
            group->entries[static_cast<unsigned char>(entryIndexValue)];

        entry.entryName.Assign(row->first.Data(), row->first.Length());

        {
            SimpleUString tableName;
            tableName.Assign(L"Collections", 11);
            const SimpleUString *shortName =
                g_pMetaMan->FindEntry(&tableName, &entry.entryName, 2);
            entry.shortName.Assign(shortName->Data(), shortName->Length());
        }

        {
            SimpleUString tableName;
            tableName.Assign(L"Collections", 11);
            const SimpleUString *description =
                g_pMetaMan->FindEntry(&tableName, &entry.entryName, 3);
            entry.description.Assign(
                description->Data(), description->Length());
        }

        ++matchingRowCount;
    }

    group->totalEntries = matchingRowCount;
}
```

- Exact UID0003Y9 `RECONSTRUCTION_H CODE` remains blank because UID00002X owns the declaration.

```cpp
```

- Exact reconciled B002-owned UID00002Y `RECONSTRUCTION_CPP CODE`:

```cpp
[[CHILDREN]]
```

- Exact reconciled B002-owned UID00002Y `RECONSTRUCTION_H CODE`:

```cpp
#include "../core/PanelPane.h"

class Event;

class CollectionPane2 : public PanelPane
{
public:
    CollectionPane2();
    virtual ~CollectionPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
};

typedef char CollectionPane2SizeMustBe0xF8[
    sizeof(CollectionPane2) == 0xF8 ? 1 : -1];
```

- Exact reconciled B002-owned UID0003YG `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane2::OnPaint()
{
    EPFTileContext context;
    context.Initialize();

    DLPalette *palette =
        g_pPaletteLib->GetPaletteByName(L"ITEMINV.PAL");
    g_pEPFLib->LookupLayoutEntry(L"CLTINV.EPF", 0, &context);
    g_pfnBlitSprite(this, &context, &context.bounds, &m_visibleBounds,
                    0, palette, 0);
}
```

- Exact UID0003YG `RECONSTRUCTION_H CODE` remains blank because UID00002Y owns the declaration.

```cpp
```

- Exact formal UID00002X `RECONSTRUCTION_CPP CODE`:

```cpp
#include "CollectionPane.h"
#include "ScrollCollectionPane.h"
#include "UserPane.h"
#include "../core/Event.h"

#include "../../config/Config.h"
#include "../../metadata/MetaMan.h"
#include "../../metadata/MetaTable.h"
#include "../../render/ImageLib.h"
#include "../../render/PaletteLib.h"
#include "../../render/Surface.h"

#include <cwchar>
#include <stdlib.h>

[[CHILDREN]]
```

- Exact formal UID00002X `RECONSTRUCTION_H CODE`:

```cpp
#pragma once

#include "../core/PanelPane.h"

class Event;
class Layer;
class MetaTable;
class ScrollCollectionPane;
struct CollectionGroupRecord;

class CollectionPane : public PanelPane
{
public:
    CollectionPane();
    virtual ~CollectionPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void AddToLayer(RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *packetData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void LoadCollectionGroupRecords(CollectionGroupRecord *group);
    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition, short newPosition);

private:
    void UpdateScrollRange();
    void SetInvalidGroupSlotRect(unsigned short visibleSlot,
                                 RectBounds *outBounds);
    void GetVisibleGroupSlotRect(unsigned short visibleSlot,
                                 RectBounds *outBounds);
    short HitTestVisibleGroupSlot(int y, int x);
    void OpenOrRequestGroupDetail(int groupIndex);

    int m_groupCount;
    MetaTable *m_collectionsTable;
    MetaTable *m_groupNamesTable;
    signed char m_firstVisibleGroup;
    signed char m_groupCountSnapshot;
    ScrollCollectionPane *m_scrollPane;
};

typedef char CollectionPaneSizeMustBe0x10C[
    sizeof(CollectionPane) == 0x10C ? 1 : -1];
```

- Exact formal UID0003Y4 `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::UpdateRenderRegion(const RectBounds *bounds)
{
    RectBounds localBounds;
    InitRectBounds(&localBounds, 0, 0,
                   bounds->right - bounds->left,
                   bounds->bottom - bounds->top);

    RectBounds scrollBounds;
    InitRectBounds(&scrollBounds,
                   bounds->right - 20,
                   bounds->top + 27,
                   bounds->right - 7,
                   bounds->bottom - 21);
    m_scrollPane->SetBounds(&scrollBounds, 0);
    Pane::UpdateRenderRegion(bounds);
    UpdateScrollRange();
}
```

- Exact formal UID0003Y4 `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003Y5 `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::UpdateScrollRange()
{
    CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    m_groupCountSnapshot = collectionData.groupCount;

    short maxRange =
        static_cast<short>(collectionData.groupCount - 5);
    if (maxRange < 0)
        maxRange = 0;
    else if (maxRange > 30000)
        maxRange = 30000;

    if (m_scrollPane->m_scrollRange != maxRange)
        m_scrollPane->SetMaxRange(maxRange);

    short position = m_firstVisibleGroup;
    if (position < 0)
        position = 0;

    const short lastPosition =
        static_cast<short>(collectionData.groupCount - 5);
    if (position > lastPosition)
        position = lastPosition;

    if (position < 0)
        position = 0;
    else if (position > 30000)
        position = 30000;

    if (m_scrollPane->m_scrollPosition != position)
        m_scrollPane->SetScrollPosition(position);

    m_firstVisibleGroup = static_cast<signed char>(position);
}
```

- Exact formal UID0003Y5 `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003Y7 `RECONSTRUCTION_CPP CODE`:

```cpp
bool CollectionPane::HandleKeyOrTextEvent(Event *event)
{
    (void)event;
    return false;
}
```

- Exact formal UID0003Y7 `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003Y8 `RECONSTRUCTION_CPP CODE`:

```cpp
bool CollectionPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    if (event->m_type == kEventMouseWheel &&
        PointInRect(event->m_payload.m_pointer.m_y,
                    event->m_payload.m_pointer.m_x,
                    &m_visibleBounds)) {
        const short oldPosition = m_scrollPane->m_scrollPosition;
        short newPosition = static_cast<short>(
            oldPosition -
            static_cast<short>(event->m_payload.m_pointer.m_detail));

        if (newPosition < 0)
            newPosition = 0;
        else if (newPosition > m_scrollPane->m_scrollRange)
            newPosition = m_scrollPane->m_scrollRange;

        if (oldPosition != newPosition) {
            m_firstVisibleGroup =
                static_cast<signed char>(newPosition);
            m_scrollPane->SetScrollPosition(newPosition);
            UpdateScrollRange();
            InvalidateRect(&m_visibleBounds);
        }
    } else if ((event->m_type == kEventLeftButtonDown &&
                !g_pConfig->m_doubleClickEnabled) ||
               (event->m_type == kEventLeftButtonDoubleClick &&
                g_pConfig->m_doubleClickEnabled)) {
        const short visibleSlot = HitTestVisibleGroupSlot(
            event->m_payload.m_pointer.m_y,
            event->m_payload.m_pointer.m_x);
        if (static_cast<unsigned short>(visibleSlot) <= 4) {
            const short groupIndex = static_cast<short>(
                m_firstVisibleGroup + visibleSlot);
            if (groupIndex >= 0 &&
                groupIndex <
                    g_pUserPane->GetCollectionData().groupCount &&
                visibleSlot != -1) {
                OpenOrRequestGroupDetail(groupIndex);
            }
        }
    }

    RectBounds scrollBounds;
    m_scrollPane->GetScreenBounds(&scrollBounds);
    event->m_payload.m_pointer.m_x -= scrollBounds.left;
    event->m_payload.m_pointer.m_y -= scrollBounds.top;

    EventHandler *scrollHandler =
        static_cast<EventHandler *>(m_scrollPane);
    const bool handled =
        scrollHandler->HandlePointerOrMouseEvent(event);

    event->m_payload.m_pointer.m_x += scrollBounds.left;
    event->m_payload.m_pointer.m_y += scrollBounds.top;
    return handled;
}
```

- Exact formal UID0003Y8 `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003YA `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::OnScrollPositionChanged(
    unsigned char orientation,
    short oldPosition,
    short newPosition)
{
    (void)orientation;
    if (oldPosition == newPosition)
        return;

    m_firstVisibleGroup = static_cast<signed char>(newPosition);
    m_scrollPane->SetScrollPosition(newPosition);
    UpdateScrollRange();
    InvalidateRect(&m_visibleBounds);
}
```

- Exact formal UID0003YA `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003YB `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::AddToLayer(RectBounds *bounds,
                                int order,
                                Pane *previousPane,
                                Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    RectBounds scrollBounds;
    m_scrollPane->GetScreenBounds(&scrollBounds);
    m_scrollPane->AddToLayer(&scrollBounds, 0, this, layer);
    UpdateScrollRange();
}
```

- Exact formal UID0003YB `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003YC `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::RemoveFromLayer()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}
```

- Exact formal UID0003YC `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003YD `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::SetInvalidGroupSlotRect(
    unsigned short visibleSlot,
    RectBounds *outBounds)
{
    (void)visibleSlot;
    InitRectBounds(outBounds, -1, -1, -1, -1);
}
```

- Exact formal UID0003YD `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003YE `RECONSTRUCTION_CPP CODE`:

```cpp
void CollectionPane::GetVisibleGroupSlotRect(
    unsigned short visibleSlot,
    RectBounds *outBounds)
{
    if (visibleSlot <= 4) {
        const int rowOffset = 50 * visibleSlot;
        InitRectBounds(outBounds, 6, rowOffset + 14,
                       161, rowOffset + 62);
    } else {
        InitRectBounds(outBounds, -1, -1, -1, -1);
    }
}
```

- Exact formal UID0003YE `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact formal UID0003YF `RECONSTRUCTION_CPP CODE`:

```cpp
short CollectionPane::HitTestVisibleGroupSlot(int y, int x)
{
    for (short visibleSlot = 0; visibleSlot <= 4; ++visibleSlot) {
        RectBounds bounds;
        GetVisibleGroupSlotRect(
            static_cast<unsigned short>(visibleSlot), &bounds);
        if (PointInRect(y, x, &bounds))
            return visibleSlot;
    }
    return -1;
}
```

- Exact formal UID0003YF `RECONSTRUCTION_H CODE` is blank because UID00002X owns the one declaration:

```cpp
```

- Exact compiler-covered UID00038U `RECONSTRUCTION_CPP CODE`:

```cpp
// Compiler-covered by CollectionPane's complete virtual declaration and method bodies.
// The compiler emits the three RTTI/COL/vtable views, destructor adjustors, and table words.
// Do not hand-author vtable data or RTTI source.
```

- Exact compiler-covered UID00038U `RECONSTRUCTION_H CODE` is blank because the complete UID00002X declaration recreates the compiler data:

```cpp
```

- Exact additive UID0000CG `ScrollCollectionPane` H support insertion inside the existing complete class declaration's private section; all other UID0000CG H text remains byte-for-byte preserved:

```cpp
friend class CollectionPane;
```

- The friend insertion uses the already-present `class CollectionPane;` forward declaration in the complete ScrollCollectionPane H route. It authorizes only the directly evidenced `m_scrollPosition`/`m_scrollRange` reads in UID0003Y5/Y8 and introduces no field, accessor, storage, or layout change.

- Exact corrected UID0001TZ `RECONSTRUCTION_CPP CODE`:

```cpp
```

- Exact corrected UID0001TZ `RECONSTRUCTION_H CODE`:

```cpp
#include "../../util/StringUtil.h"

struct CollectionEntryRecord
{
    SimpleUString shortName;
    SimpleUString entryName;
    SimpleUString description;
    unsigned char collectedFlag;
    unsigned char reserved[3];
};

struct CollectionGroupRecord
{
    unsigned char loadedFlag;
    unsigned char groupType;
    unsigned char totalEntries;
    unsigned char collectedEntries;
    CollectionEntryRecord entries[128];
};

struct CollectionPlayerDataView
{
    CollectionGroupRecord groups[128];
    signed char groupCount;
    unsigned char metadataLoaded;
};

typedef char CollectionEntryRecordSizeMustBe0x4C[
    sizeof(CollectionEntryRecord) == 0x4C ? 1 : -1];
typedef char CollectionGroupRecordSizeMustBe0x2604[
    sizeof(CollectionGroupRecord) == 0x2604 ? 1 : -1];
```

- Exact corrected UID0000D9 `RECONSTRUCTION_CPP CODE`:

```cpp
```

- Exact corrected UID0000D9 `RECONSTRUCTION_H CODE`:

```cpp
class SimpleUString
{
public:
    SimpleUString();
    ~SimpleUString();

    void Clear();
    SimpleUString& Assign(const wchar_t *source, unsigned int length);
    wchar_t *MutableData()
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }
    const wchar_t *Data() const
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }
    unsigned int Length() const
    {
        return m_length;
    }

private:
    union
    {
        wchar_t m_inlineBuffer[8];
        wchar_t *m_heapBuffer;
    };
    unsigned int m_length;
    unsigned int m_capacity;

    [[CHILDREN]]
};
```

- Exact current already-present UID0000A1 PaletteLib `RECONSTRUCTION_CPP CODE` (verify only; no B008 write):

```cpp
[[CHILDREN]]
```

- Exact current already-present UID0000A1 PaletteLib `RECONSTRUCTION_H CODE` (verify only; no B008 write):

```cpp
#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/List.h"
#include "Palette.h"

struct PaletteLibLoadedEntry
{
    wchar_t *name;
    DLPalette *palette;
};

void __stdcall ApplyPaletteEntryMovesToCollection(List *palettes);

class PaletteLib : public LObject, public Singleton<PaletteLib>
{
public:
    PaletteLib();
    virtual ~PaletteLib();

    int GetScreenPaletteMode() const;
    void SetScreenPaletteMode(int mode);
    DLPalette *GetCurrentPalette();
    DLPalette *GetTextPalette();
    DLPalette *GetPaletteByName(const wchar_t *paletteName);
    DLPalette *GetSlotPalette(int slot, int paletteIndex,
                              int superPaletteIndex);
    void ResetScreenPaletteSlots();
    bool SetPaletteFilterActive(bool active);
    float GetPaletteFilterWeight() const;
    void UpdatePaletteFilterTables(float weight);

private:
    int FindLoadedPaletteIndexByName(const wchar_t *paletteName) const;
    int LoadNamedPalette(const wchar_t *paletteName);
    List *LoadPaletteList(const wchar_t *paletteName);
    void LoadPaletteSet(int slot, const wchar_t *paletteName);

    int m_screenPaletteMode;
    List *m_loadedPalettes;
    DLPalette m_basePalette;
    DLPalette m_filteredBasePalette;
    DLPalette m_textPalette;
    List *m_sourcePaletteSets[25];
    List *m_runtimePaletteSets[25];
    bool m_useFilteredPalettes;
    float m_paletteFilterWeight;
    DLPalette m_superPalettes[7];
    DLPalette m_filteredSuperPalettes[7];
};
```

- Exact current already-present UID0000RW g_pPaletteLib `RECONSTRUCTION_CPP CODE` (verify only; no B008 write):

```cpp
PaletteLib *g_pPaletteLib = 0;

[[CHILDREN]]
```

- Exact current already-present UID0000RW g_pPaletteLib `RECONSTRUCTION_H CODE` (verify only; no B008 write):

```cpp
extern PaletteLib *g_pPaletteLib;
```

- Exact corrected UID000088 MetaMan `RECONSTRUCTION_CPP CODE`:

```cpp
#include "MetaMan.h"

[[CHILDREN]]
```

- Exact corrected UID000088 MetaMan `RECONSTRUCTION_H CODE`:

```cpp
#ifndef NEXUSTK_METADATA_METAMAN_H
#define NEXUSTK_METADATA_METAMAN_H

#include "../util/Singleton.h"
#include "../util/StringUtil.h"

#include <map>

class MetaTable;

class MetaMan : public Singleton<MetaMan>
{
public:
    MetaMan();
    virtual ~MetaMan();

    int LoadMetaDatAndRequestSync();
    bool HandleMetaPacket(const unsigned char *packet);

    unsigned int GetValueCount(const SimpleUString *tableName,
                               const SimpleUString *rowKey);
    const SimpleUString *FindEntry(const SimpleUString *tableName,
                                   const SimpleUString *rowKey,
                                   unsigned int valueIndex);
    bool LoadStatValues(const SimpleUString *tableName,
                        const SimpleUString *rowKey,
                        wchar_t ***outValues,
                        int valueCount);
    MetaTable *FindTableByName(const SimpleUString *tableName);

private:
    typedef std::map<SimpleUString, MetaTable *> TableMap;

    void ClearTables();
    void LoadMetaDat();
    void SaveMetaDatIfDirty();

    TableMap m_tables;
    unsigned int m_pendingTableRequests;
    bool m_synchronized;
    bool m_dirty;
};

extern MetaMan *g_pMetaMan;

typedef char MetaManSizeMustBe0x14[
    sizeof(MetaMan) == 0x14 ? 1 : -1];

#endif
```

- Exact retained UID0000RL g_pMetaMan `RECONSTRUCTION_CPP CODE`:

```cpp
MetaMan *g_pMetaMan = 0;
```

- Exact retained UID0000RL g_pMetaMan `RECONSTRUCTION_H CODE`:

```cpp
```

- Exact reconciled B002-owned UID000089 MetaTable `RECONSTRUCTION_CPP CODE`:

```cpp
[[CHILDREN]]
```

- Exact reconciled B002-owned UID000089 MetaTable `RECONSTRUCTION_H CODE`:

```cpp
#ifndef NEXUSTK_METADATA_METATABLE_H
#define NEXUSTK_METADATA_METATABLE_H

#include <map>
#include <vector>
#include "../util/StringUtil.h"

class MetaTable
{
public:
    typedef std::map<SimpleUString,
                     std::vector<SimpleUString> > RowMap;

    MetaTable();
    virtual ~MetaTable();

    bool DecompressAndValidateData(unsigned int expectedChecksum);
    void MaterializeRowsIfNeeded(const wchar_t *tableNameHint);
    void ResetData();

    const RowMap &Rows() const { return m_rows; }
    bool IsMaterialized() const { return m_isLoaded; }

private:
    unsigned int m_checksum;
    unsigned char *m_keyData;
    unsigned int m_keyDataSize;
    unsigned char *m_valueData;
    unsigned int m_valueDataSize;
    bool m_isLoaded;
    RowMap m_rows;
};

typedef char MetaTableSizeMustBe0x24[
    sizeof(MetaTable) == 0x24 ? 1 : -1];

#endif
```

- Exact reconciled B002 14-use source matrix, owned by method pages rather than emitted as standalone UID0003F1 data:

| Method | Exact expressions / count |
|---|---|
| `CollectionPane::OnActivate` | `L"Collections"` twice; `L"GroupNames"` twice; total 4 |
| `CollectionPane::OnPaint` | `L"GroupNames"`, `L"CLTINV.EPF"`, `L"CLTLIST.EPF"`, `L"CLTLIST.PAL"`, `L"\xC548\xB098\xC640"`, `L"%d %%"`, `L"%d/%d"`; total 7 |
| `CollectionPane::LoadCollectionGroupRecords` | `L"Collections"` twice; total 2 |
| `CollectionPane2::OnPaint` | `L"CLTINV.EPF"` once; total 1 |

- UID00002X owns each CollectionPane declaration once. Its exact `#pragma once` guard and `../core/PanelPane.h` include make `PanelPane`, inherited `Pane`, `RectBounds`, and the virtual contracts complete before the class declaration; `Event`, `Layer`, `MetaTable`, `ScrollCollectionPane`, and `CollectionGroupRecord` are valid pointer/reference-only declarations here. The 17-member inventory matches Section 16, `int m_groupCount` preserves B002's exact dword write, B008's scroll/rectangle signatures control conflicting provisional spellings, natural alignment replaces the former explicit reserve field, and the size guard proves the `0x10c` span. Target and method H channels remain blank. The class CPP channel is now the one complete file-root preamble/`[[CHILDREN]]` aggregator, so all method definitions remain namespace scope without repeated child includes.
- UID0001TZ remains owner/emitter `0000P1` at position `5`; its exact three structs now reside in formal H and formal CPP is blank. The leading `../../util/StringUtil.h` include makes each by-value `SimpleUString` complete before the structs, position `5` makes `CollectionPlayerDataView` complete before UID0000FQ embeds it at position `10`, and UID0003Y6's `#include "UserPane.h"` makes the complete view visible before CollectionPane dereferences it. No duplicate type declaration is present in CollectionPane H.
- UID0000D9 remains owner/emitter `0000OB`, and the complete class H stays in `NexusTK/util/StringUtil.h`. The sole additions are inline `Data() const`, whose capacity-gated heap/inline selection is directly visible at the const `FindEntry` copy and draw sites, and inline `Length() const`, which exposes the exact `+0x10` count passed to `Assign`; neither changes object size or emits an out-of-line body. Existing `MutableData()` remains unchanged, and parser-only `c_str()` plus unevidenced assignment/comparison operators remain rejected.
- UID0000A1 stays `92/93` under exact executed B003 ownership. Current ordinary UID0000A1 H already contains the complete class/helper payload with `LObject.h`, `Singleton.h`, `List.h`, and `Palette.h`; current UID0000A1 CPP is exactly `[[CHILDREN]]`. Current UID0000RW CPP retains the sole `PaletteLib *g_pPaletteLib = 0;` definition plus children, and current UID0000RW H supplies the one extern. Repair-time command `000000024737` physically observed one complete `PaletteLib.h`, no CPP-local class duplicate, one extern, and one storage definition; callback verification uses the latest supervisor-verified waited readback. This is verify-only predecessor state; B008 consumes it and performs no PaletteLib write. The former B008 `93/94`, class-owned extern, include-guard/size-assertion, and header-plus-children class-CPP proposals are dated, superseded evidence.
- UID000088 now emits its complete accepted `0x14` declaration through guarded `NexusTK/metadata/MetaMan.h`. `Singleton.h` makes the base complete, `StringUtil.h` makes the by-value `SimpleUString` map key complete, `<map>` supplies the accepted container, and `MetaTable` remains a pointer-only forward declaration whose full class stays on its child route. Class CPP is only `#include "MetaMan.h"` plus `[[CHILDREN]]`; UID0000RL retains the sole `MetaMan *g_pMetaMan = 0;` definition and blank H while the class header contains exactly one extern.
- UID000089 preserves B002's complete `0x24` MetaTable child route in the same metadata module. Its independently guarded H makes `RowMap`, `Rows()`, `IsMaterialized()`, payload fields, and size invariant visible; its CPP remains children-only. OnActivate and LoadCollectionGroupRecords consume that public source-facing abstraction instead of old-MSVC raw tree helpers.
- `ImageLib.h` declares complete `ImageLib`, `LookupLayoutEntry`, and `extern ImageLib *g_pEPFLib`. `Surface.h` declares the exact seven-argument `SurfaceSpriteBlitProc` and `extern SurfaceSpriteBlitProc g_pfnBlitSprite`. `CollectionPane.h -> PanelPane.h -> Pane.h -> GrafPort.h -> EPFTileContext.h` supplies complete `EPFTileContext`; direct `ImageLib.h`/`Surface.h` includes supply the service and callback declarations. Current PaletteLib/MetaMan/MetaTable headers supply `GetPaletteByName`, `FindEntry`, `Rows`, their globals/types, `DLPalette`, and `SimpleUString`. `<cwchar>` supplies the project/MSVC declarations for unqualified `swprintf_s` and `wcslen`, matching accepted UID00009A source precedent.
- The corrected OnPaint body mirrors the observed stack: one initialized `tileContext` reused for `CLTINV.EPF` and `CLTLIST.EPF`, accepted `tileContext.bounds`, `groupKeyText[128]`, `valueText[128]`, POD aggregate `rowBounds`, and one reused `textBounds`. The exact string flow uses only declared `SimpleUString::Assign`, const `Data`/`Length`, and `wcslen`: it copies a non-self `FindEntry` value with the stored count, tests the known-empty result through its NUL-terminated data, installs exact ASCII source spelling `L"\xC548\xB098\xC640"`, and passes stable NUL-scanned data/length to drawing. Exact direct `rowBounds.top/bottom += 50` updates replace the earlier helper-call spelling because the binary performs direct additions. B002's const-cast MutableData/no-copy body and this report's superseded helper-call increment are historicalized; all seven B002 literal uses remain exact.
- B002's other three consumer bodies remain complete: OnActivate materializes both tables and packet records, LoadCollectionGroupRecords traverses MetaTable rows using the exact value/key/column mapping while now consuming B008's const Data/Length APIs, and CollectionPane2::OnPaint performs its one typed frame-zero blit. These blocks and UID0003F1's exact marker/source-use matrix are part of the coordinated final file topology, not new B008 target ownership.
- Waited registry discovery registered ten source-bearing children that had not appeared in the dated 17-entry topology. Their prior comment-only CPP blocks are historicalized as mechanically nonempty but source-incomplete. The completion callback placed the complete bodies above into UID0003Y4/Y5/Y7/Y8/YA/YB/YC/YD/YE/YF, preserved exact blank class-owned H channels, added the direct Event/Config dependencies and minimal ScrollCollectionPane friend route required for direct child-state reads, and placed only the exact compiler-covered CPP marker in UID00038U. Command `000000025070` physically proves all 27 routed generated blocks filled; table data remains compiler-generated and must never be hand-authored.

## Final Recommendation

- Treat this report as the shared-destination reconciliation authority, executed B003 state as direct PaletteLib authority, and B002 as direct UID0003F1 authority. The accepted B008 callbacks verified/preserved B003's already-present Palette route, applied the unified target/OnPaint/type/service payload, and then physically completed the ten formerly comment-only member emitters plus UID00038U/support closure.
- Do not emit a named object for UID0003FA. Emit the complete OnPaint body and exact covered-by marker through class UID00002X positions `70/75`.
- Keep the data item untyped and named `xmmword_624C10` in IDA; semantic provenance belongs in the exact repeatable comment.
- Keep the function's current generic IDA type because `CollectionPane` UDT is absent. The source-facing member definition remains justified independently by vtable/class evidence.
- Preserve broad parents as non-emitting indexes and resource/layout supports as shared dependencies. Preserve ImageLib and Surface unchanged; use their existing complete headers rather than duplicating declarations.
- Preserve B002's exact target marker, 14-use map, OnActivate, LoadCollectionGroupRecords, CollectionPane2 class/paint, MetaTable, D01-D08, and P01-P03. Preserve B008's rowBounds provenance, OnPaint stack/string/body precision, SimpleUString const APIs, direct dependency closure, and IDA-FA-01..03.
- Preserve the completed ten bodies, two file-root includes, one ScrollCollectionPane friend declaration, and UID00038U compiler-covered marker exactly as physically validated. B002 remains direct owner of UID0003F1 and must reread this released validated state while preserving B003 before any later overlapping write. An active overlapping lease or loss of either predecessor payload is a hard stop pending a replacement supervisor serialization contract.

## Recommended Target Doc Changes

- Current target metadata is `CANONICAL_OWNER:00002X`, `EMITTER_UIDS:00002X`, `EMITTER_POSITION_OPTIONAL:75`, score `94/95`, and `RECONSTRUCTABLE:TRUE`.
- Current formal target CPP is the exact covered-by payload from Section 22 and current target H is blank.
- Current target prose contains the exact bytes/hash, unique-pattern proof, sole xref/instruction proof, typed local flow, row-step behavior, compiler-pattern comparison, source-local disposition, corrected method/header/dependency support closure, rejected alternatives, exact boundaries, class/file route, and generated readback.
- Preserve old waiting language only in dated history labeled superseded by this report.

## Recommended Support Doc Changes

- UID0003Y6 is at position `70` and score `92/94` with the unified body-only child from Section 22: one initialized context, two exact 128-wide buffers, row/text rectangles, direct 50-pixel field updates, all seven B002 literals, copied SimpleUString with const Data/Length, escaped Korean fallback, and exact render flow. Formal H remains blank.
- UID00002X is current `94/94` with the exact ten bodies, direct `Event.h`/`Config.h` includes, existing guarded 17-member H declaration, and UID0000CG friend support. Positions `70/75`, `int m_groupCount`, natural padding, and all existing declarations remain unchanged.
- UID0003Y4/Y5 are current `92/94` and `93/94` with complete `UpdateRenderRegion(const RectBounds *)` and `UpdateScrollRange()` CPP bodies from Section 22. Their H channels remain blank because UID00002X owns both declarations.
- UID0003Y7/Y8 are current `92/94` and `93/94` with complete `HandleKeyOrTextEvent(Event *)` and `HandlePointerOrMouseEvent(Event *)` CPP bodies; `VirtualFalseStubA` and `OnInputEvent` remain dated behavior aliases. Their H channels remain blank/class-owned, and the pointer/mouse definition uses the direct Event/Config includes plus exact ScrollCollectionPane friend support.
- UID0003Y9/YA retain exact `LoadCollectionGroupRecords(CollectionGroupRecord *)` and `OnScrollPositionChanged(unsigned char, short, short)` signatures, including the external caller and unused-orientation evidence. Both complete bodies are present; UID0003YA is current `92/94` with blank H.
- UID0003YB/YC are current `92/94` each with complete exact inherited override bodies for `AddToLayer(RectBounds *, int, Pane *, Layer *)` and `RemoveFromLayer()`; attach/detach remain behavior descriptions and H remains class-owned.
- UID0003YD/YE/YF are current `90/92`, `91/93`, and `92/94` with complete CPP bodies for the two rectangle writers and `short HitTestVisibleGroupSlot(int y, int x)`, preserving unsigned slot range, output-pointer order, project y/x order, exact row formula, and `0xffff` miss result. Their H channels remain blank/class-owned.
- UID00038U is current `94/95` with the exact compiler-covered marker and blank H; its `0x8c` bytes are RTTI/COL/vtable compiler output from the complete UID00002X class and virtual methods, not an authored table object.
- UID0000IC's numerical `94/94` is source-justified by the completed bodies/support/UID00038U marker and command `000000025070` physical `27/27/0` readback. Dated `17/10/7` and `27/26/1` observations remain historical and do not establish current source completion.
- UID0002V2: preserve `88/92`, non-reconstructable/non-emitting status, exact parent end `0x00624c60`, and identify the child source-local route.
- UID0001HD: preserve `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter route, and non-emitting split/index status; link all four pooled-literal consumers plus UID0003FA local closure. Use only the one merged Section 28 no-loss row.
- UID0003F1: current ordinary baseline is `92/95`; B002's direct final target recommendation is `92/94`. Preserve owner/emitter UID0000IC, the non-object covered-by CPP marker, and exact 14-use evidence. B008 makes no UID0003F1 target edit because B002 owns that exact score/formal/manual change.
- UID0001R8 required no ordinary edit. UID0001TZ is `93/94` with blank CPP and declaration-visible H containing `../../util/StringUtil.h`, exact three declarations, and `0x4c`/`0x2604` guards; UID00002X's preamble supplies `UserPane.h`.
- UID0000D9 remains `90/92`, owner/emitter UID0000OB, blank class CPP, and the complete `StringUtil.h` class declaration; inline `Data() const` and `Length() const` now sit beside `MutableData()` using the exact SSO capacity gate and `+0x10` count.
- UID0000A1/UID0000MB/UID0000RW: preserve current direct-owner scores `92/93`, `91/92`, and `92/94` with no ordinary edit. Executed B003 state already places the exact complete PaletteLib declaration in UID0000A1 H, leaves UID0000A1 CPP children-only, places the one extern in UID0000RW H, and preserves the sole definition plus children in UID0000RW CPP. Current class/global manual rows literally equal Section 28 and current UID0000MB is same-or-greater no-change. B008 performs no PaletteLib or Palette manual write.
- UID000088/UID000089 are `94/94` and `94/93`; UID0000LC/UID0000RL remain `92/93` and `89/90`. Current formal channels provide one guarded MetaMan H, one guarded MetaTable H, children-only owner CPP routes, one singleton definition/extern, and no raw-tree/reduced duplicate. Section 28 retains one coordinated supervisor-owned manual payload per UID.
- B002-owned UID0003Y3, UID0003Y9, UID00002Y, and UID0003YG are `93/94`, `92/93`, `94/95`, and `94/95` with the exact Section 22 source. UID0003F1 remains the direct B002 target with current ordinary `92/95`, exact marker, blank H, and B002's distinct final score/coverage handoff preserved in this report.
- UID00006E/UID0000K2 and UID0000TN/UID0000OC: no ordinary or manual edit. Their current complete `ImageLib.h` and `Surface.h` routes already declare `g_pEPFLib`/`LookupLayoutEntry` and `g_pfnBlitSprite`/its exact callback type.

## Score And Metadata Recommendation

| UID | Dated pre-callback / physical state | Physical current / final handoff | Rationale |
|---|---|---|---|
| 0003FA | `85/88`, owner/emitter 0000IC, no position | `94/95`, owner/emitter 00002X, position 75 | Exact POD aggregate source shape, boundaries, provenance, emission, IDA disposition, declared string API use, collection-header visibility, direct external includes, and complete service-owner headers are closed. |
| 0003Y6 | `87/90`, no position, blank CPP/H | `92/94`, emitter 00002X position 70, unified complete body-only CPP, blank H | B008's exact stack/SSO/rowBounds evidence and B002's seven-use/render closure converge; only lexical/access spellings remain inferred. |
| 00002X | `89/90`, blank formal channels | current `94/94`, complete CPP/H route | B002 closes four consumers and exact dword group count; B008 physically incorporated all ten omitted bodies, Event/Config includes, and the source-valid ScrollCollectionPane friend route. |
| 0000IC | `92/93` | current source-justified `94/94`, waited `27/27/0` | Complete headers, all existing consumers, ten completed member bodies, two pooled-data markers, UID0003FA marker, and UID00038U compiler-covered marker are physically present; dated `27/26/1` comment-only topology is historical only. |
| 0003Y4 | `86/90`, comment-only CPP | current `92/94`, complete CPP and blank class-owned H | Exact bounded body, primary slot contract, retained local initializer, child bounds, base update, and range refresh close behavior; lexical local names remain inferred. |
| 0003Y5 | `87/90`, comment-only CPP | current `93/94`, complete CPP and blank class-owned H | Exact group snapshot, signed clamps, child comparisons/setters, and source-valid friend access close the synchronizer. |
| 0003Y7 | `86/91`, comment-only CPP | current `92/94`, complete CPP and blank class-owned H | Exact five-byte EventHandler false-return body leaves only original naming/access confidence caps. |
| 0003Y8 | `87/90`, comment-only CPP | current `93/94`, complete CPP and blank class-owned H | Exact lock/wheel/click/child-dispatch behavior plus Event/Config and friend declaration closure support the full body. |
| 0003YA | `87/90`, comment-only CPP | current `92/94`, complete CPP and blank class-owned H | Exact external callback ABI, unused orientation, transition gate, synchronization, range refresh, and invalidation are closed. |
| 0003YB / 0003YC | `86/90`, `86/90`, comment-only CPP | current `92/94`, `92/94`, complete CPP and blank class-owned H | Exact Pane/child layer ordering and bounded hashes close both inherited overrides. |
| 0003YD / 0003YE / 0003YF | `85/88`, `85/89`, `87/90`, comment-only CPP | current `90/92`, `91/93`, `92/94`, complete CPP and blank class-owned H | Raw boundaries, output order, unsigned slot rule, exact row formula, y/x hit-test order, and miss value are closed; raw-helper lexical/access recovery remains capped. |
| 00038U | `88/92`, blank CPP/H | current `94/95`, compiler-covered CPP marker and blank H | Exact three-view table group, constructor vptr stores, complete virtual declarations/definitions, and compiler-only RTTI/adjustor policy prove no hand-authored table source is required. |
| 0002V2 | `88/92` | unchanged | Mixed read-only parent remains an index. |
| 0001HD | `88/91` | unchanged | Broad executable parent remains a split/index. |
| 0003F1 | `92/95` | direct B002 recommendation `92/94` | Exact target evidence, marker, and 14-use table are complete; confidence 94 preserves B002's erased repeated-expression versus unreferenced-static ambiguity, and B002 owns the score/formal/manual change. |
| 0001TZ | `91/92`, exact structs in CPP | `93/94`, exact guarded structs in H, CPP blank | B002's exact size guards and B008's by-value visibility proof close the source/header route. |
| 0000D9 | `90/92`, no const storage/count accessors | `90/92`, inline `Data() const` and `Length() const` in complete H | Live const SSO selection and counted-copy field read establish both accessors, but the broader class API/split caveat still caps the existing score. |
| 0000A1 / 0000MB / 0000RW | `92/93`, `91/92`, `92/94`; complete class in UID0000A1 H, children-only class CPP, extern in UID0000RW H, sole definition in UID0000RW CPP | unchanged; verify/preserve exact executed B003 route, no B008 write | Current ordinary/generated/manual state already closes declaration visibility at direct-owner detail; B008's dated `93/94`, class-owned extern, guard/size-assertion, and duplicate callback proposals are superseded. |
| 000088 / 000089 / 0000LC / 0000RL | `91/93`, `90/90`, `92/93`, `89/90`; declarations in CPP; H absent | `94/94`, `94/93`, `92/93`, `89/90`; complete guarded manager/table H routes and children-only CPP | Four consumers, accepted MetaTable RowMap/materializer, exact layouts, APIs, globals, and owner topology close the class source; file/global caps remain. |
| 0003Y3 / 0003Y9 | `88/91`, `87/90` | `93/94`, `92/93` | B002's exact OnActivate and loader profiles/bodies plus merged type/API routes close their source; loader naming/access remains the stronger inference cap. |
| 00002Y / 0003YG | `92/94`, `87/91` | `94/95`, `94/95` | Exact constructor/base/vtable/callback evidence and complete frame-zero paint source close the alternate class/method. |
- Target completion is not 100 because original lexical spelling and declaration ordering are stripped.
- Target confidence is not 100 because local naming is source-facing inference, although POD source shape, corrected method stack correspondence, established string operations, valid collection-header route, exact direct includes, and complete PaletteLib/MetaMan owner headers are very strong. The retained `94/95` is justified only by this expanded dependency-closed formal correction.

## Open Questions With Attempted Resolution

- Original local name: symbols are stripped; resolved to `rowBounds` by loop role and accepted sibling source. No behavioral uncertainty remains.
- Local versus temporary: typed persistent stack use and mutation favor a named local; either lexical form lowers equivalently, but named local is the realistic maintainable source.
- Static/member/global possibility: exhausted via xrefs, address-use, symbol-family, write, and cross-method checks; rejected.
- Exact owner: class-vs-file ambiguity resolved by project method-local convention; class UID00002X is semantic owner/emitter, file UID0000IC remains destination.
- Full method feasibility: helper/resource/type blockers were checked against accepted current pages and sibling formals; live decompilation fixes one initialized/reused context, `bounds`, two 128-wide buffers, one reused text rectangle, and the exact SSO copy/empty/data sequence. The corrected source uses the formally added const `Data()`/`Length()` accessors and exact direct render/palette/metadata/CRT headers; it depends on neither speculative compiler coalescing nor undeclared assignment/comparison operators, `c_str()`, local externs, or reduced class declarations.
- Buffer/rectangle shape: resolved directly from contiguous stack spans `[ebp-0x210,ebp-0x110)` and `[ebp-0x110,ebp-0x10)` plus `RectBounds` slots at `[ebp-0x248,ebp-0x238)` and `[ebp-0x220,ebp-0x210)`; two arrays and one scratch rectangle are required.
- Header validity: resolved with exact `#pragma once` and `#include "../core/PanelPane.h"` preamble plus the complete 17-member UID00002X declaration. UID0001TZ emits its exact structs through H after `#include "../../util/StringUtil.h"`, closing the by-value `UserPane.h` member, and the CollectionPane preamble includes `UserPane.h` before dereferencing the view. Executed B003 state supplies the exact complete PaletteLib class/global H route; current generated `MetaMan.h` contains the complete manager/table declarations and extern. Current ImageLib/Surface H routes are complete. The direct `Event.h`/`Config.h` includes and exact UID0000CG friend insertion are physically incorporated, scoped-valid, and present in waited command `000000025070` generated readback.
- Historical aliases: `AttachToLayer`, `DetachFromLayer`, `OnInputEvent`, `VirtualFalseStubA`, and `(int x, int y)` hit-test wording are retained only as behavior/history labels. The formal source uses `AddToLayer`, `RemoveFromLayer`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and project-order `(int y, int x)`.
- Function IDA type: a `CollectionPane` UDT search was negative; resolved as no type action rather than deferred unsafe work.
- External declarations: `g_pEPFLib`/`LookupLayoutEntry` resolve through current `ImageLib.h`; `g_pfnBlitSprite`/`SurfaceSpriteBlitProc` through current `Surface.h`; `g_pPaletteLib`/`GetPaletteByName` through current `PaletteLib.h`; `g_pMetaMan`/`FindEntry` through current `MetaMan.h`; and `swprintf_s`/`wcslen` through `<cwchar>` under the accepted project/MSVC convention. Final waited hashes and one-definition counts are in Section 31.
- Cross-report score/formal conflict: resolved by direct evidence and direct ownership rather than report seniority. B008's stack/SSO/signature/local-constant work controls UID0003Y6 and exact CollectionPane member signatures; B002's complete four-consumer/MetaTable/file work controls the higher shared completion evidence; executed B003 state exclusively controls PaletteLib at unchanged `92/93` with children-only class CPP, complete class H, global-H extern, and sole global-CPP definition. The assignment-time B002 snapshot and B008's former PaletteLib `93/94`/guard/size-assertion proposal remain dated historical evidence only. Final scores and formals are the unified rows in Sections 22 and 27.
- B002 direct ownership: UID0003F1, its exact marker/manual row, and D01-D08/P01-P03 remain B002-owned. B008 direct ownership: UID0003FA, its marker/manual row, and IDA-FA-01..03 remain B008-owned. `0x0056edc0` mutation ownership is exclusively B008; B002 contributes source evidence only.
- Callback ordering: B003 predecessor state was reread and preserved; B008's bounded ordinary callback is complete, scoped-valid, released, and physically read back at waited command `000000025070`. B002 must reread this released validated state and preserve B003 before any later overlapping write. An active overlapping lease or missing predecessor content remains a hard stop rather than a design question.
- Score blockers: invalid RectBounds construction, undeclared string operations, collection-struct visibility, service declarations, MetaTable visibility, four original consumers, cross-report ownership, ten formal member bodies, direct Event/Config includes, the ScrollCollectionPane friend route, and the UID00038U compiler-covered marker are closed by scoped validation and waited `27/27/0` physical readback. Only the twelve supervisor-owned coverage/IDA rows remain proposed; they do not weaken the physically verified class/file source-completion scores.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Fresh physical comparison against the five current manual reports found: UID0001HD present stale; UID0003Y6/UID0003FA/UID0003F1/UID0003Y3/UID0003Y9/UID0003YG absent; UID00002X `82% : strong`, UID00002Y `92% : very-strong`, UID000088 `91% : very-strong`, UID000089 `84% : medium`, UID0001TZ `91% : very-strong`, UID0000IC `92% : very-strong`, UID0000LC `92% : very-strong`, and UID0000RL `88% : strong`, each still requiring the exact payload below. UID0000A1 and UID0000RW are literal equals to their reproduced rows below; UID0000MB is a literal equal to the reproduced current row below. UID00006E/UID0000K2 and UID0000TN/UID0000OC remain same-or-greater no-change dependency rows under C-FA-079. No stale Palette replacement remains in this section.

Current stale by-memory broad-range row, physically present and retained here only to make the correction auditable:

`    - [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) 0x0056e940-0x0056fe75 | class/helper range | CollectionPane : reconstructable : 82% : strong : IDA confirms the CollectionPane/CollectionPane2 function map, raw constructor caveat, corrected false-stub endpoints, render resource xrefs, complete CollectionPane2 vtable island, destructor/adjustor slots, and boundary before SelfLookPane2.`

Exact supervisor-owned no-loss replacement for that stale UID0001HD row:

`    - [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) 0x0056e940-0x0056fe75 | non-emitting class/helper split index | CollectionPane : not_reconstructable : 88% : very-strong : Non-emitting split/index over exact CollectionPane and CollectionPane2 method children with no aggregate emitter; IDA confirms the full function/helper map, raw constructor caveat, corrected false-stub endpoints, render resource xrefs, complete CollectionPane2 vtable island, destructor/adjustor slots, ordinary/scalar/adjustor separation, exact 0xcc boundary padding, and boundary before SelfLookPane2. Exact children own all source through UID0000IC, including four UID0003F1 pooled-literal consumers and UID0003Y6/UID00002X ownership of UID0003FA's local RectBounds reconstruction.`

Exact by-memory OnPaint insertion beneath UID0001HD:

`    - [UID:0003Y6][0x0056edc0-0x0056f655.CollectionPaneOnPaint](by-memory/0x0056edc0-0x0056f655.CollectionPaneOnPaint.md) 0x0056edc0-0x0056f655 | primary paint method | CollectionPane::OnPaint : reconstructable : 92% : very-strong : Exact 2,197-byte primary +0x44 seven-use UID0003F1 consumer with one initialized EPFTileContext, two 128-wide buffers, one row and one reused text RectBounds, CLTINV background, at most five CLTLIST rows, typed CollectionPlayerDataView access, copied GroupNames value or ASCII-spelled L"\xC548\xB098\xC640" fallback through const Data/Length, exact percentage shadows and collected/total text, direct 50-pixel row updates, and UID0003FA local POD aggregate reconstruction without a standalone data object.`

Exact by-memory target insertion immediately after UID0003F9 and before UID0003FB within UID0002V2:

`            - [UID:0003FA][0x00624c10-0x00624c20.CollectionPaneRectConstant](by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md) 0x00624c10-0x00624c20 | source-local packed constant | CollectionPaneRectConstant : reconstructable : 94% : very-strong : Exact unique [6,14,161,62] RectBounds image, sole 0x0056ee7d OnPaint movaps load, 50-pixel row stepping, UID00002X position-75 covered-by route, and use-site local POD aggregate reconstruction without a standalone object.`

Exact by-class replacement:

`- [UID:00002X][CollectionPane](by-class/CollectionPane.md) : reconstructable : 94% : very-strong : Complete 0x10c PanelPane-derived collection summary class with exact int +0xf8 group count, metadata table pointers, scroll bytes/child, complete declarations and bodies for render-region, layer, EventHandler, scroll, record, and rectangle-helper families, direct Event/Config dependencies, source-valid ScrollCollectionPane friendship, four UID0003F1 consumers, unified OnPaint at position 70, UID0003FA source-local row-bounds marker at position 75, typed collection progress rendering, natural padding, and compiler-covered RTTI/vtable data without handwritten tables.`

Exact by-file replacement:

`- [UID:0000IC][CollectionPane](by-file/CollectionPane.md) : reconstructable : 94% : very-strong : NexusTK/ui/panels/CollectionPane.cpp/.h source root with complete CollectionPane and CollectionPane2 declarations, one namespace-scope preamble/child stream, exact typed collection/metadata/render/event/config dependencies, four complete UID0003F1 consumer bodies, ten complete CollectionPane render/input/scroll/layer/rectangle bodies, eight-literal/14-use no-object marker route, unified UID0003Y6 OnPaint plus UID0003FA local row-bounds marker through positions 70/75, UID00038U compiler-covered marker, no duplicate class/body/resource/table object, and waited 27/27/0 generated closure.`

Current by-class UID0000A1 row, reproduced for literal no-change comparison; it is byte-for-byte identical to the current manual row and requires no supervisor write:

`- [UID:0000A1][PaletteLib](by-class/PaletteLib.md) : reconstructable : 92% : very-strong : Complete 0x25c8 LObject plus Singleton<PaletteLib> declaration with +0x04 empty-base PMD/EBO, exact mode/list/three embedded palette/25-pair bank/filter/seven-pair super-palette layout, natural bool-to-float alignment, constructor/destructor/source-versus-compiler lifetime, text-palette accessor semantics, full public/private method declarations including GetPaletteByName, helper declarations, and one external g_pPaletteLib declaration; the entire declaration block is emitted once in PaletteLib.h at UID0000A1 position 10, formal CPP retains children only, and the sole singleton storage definition remains UID0000RW.`

UID0000MB current `91% : very-strong` row is retained without replacement. Executed B003 required no by-file manual change, and the current row already describes the focused H/CPP owner route; B008 supplies no competing payload.

Literal current UID0000MB no-change comparison:

`- [UID:0000MB][PaletteLib](by-file/PaletteLib.md) : reconstructable : 91% : very-strong : Focused NexusTK/render/PaletteLib.h and PaletteLib.cpp source route for the source-ready file-static mutable super-palette filename array at position 5, complete PaletteLib declaration, sole g_pPaletteLib definition, constructor/destructor/accessor/loader family, exact UID0001E8 screen-palette and UID0001E9 filter bodies, class/global/screen-state/filter/storage generated order 10/20/25/30/40, complete 0x25c8 layout and Singleton lifetime; the filename object is an 11-element literal-initialized array followed by two-byte alignment with no header or broad-Palette duplicate, while UID0000MA remains the broader DLPalette/palette-family umbrella and no duplicate recovered facet/storage/compiler wrapper/vtable source is emitted.`

Current by-global UID0000RW row, reproduced for literal no-change comparison; it is byte-for-byte identical to the current manual row and requires no supervisor write:

`- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) : reconstructable : 92% : very-strong : Sole source definition for PaletteLib *g_pPaletteLib at exact storage UID00028T/0x0067a7e0, with zero initializer, complete 83-xref inventory, RTTI-proven LObject and Singleton<PaletteLib> inheritance, +0x04 PMD publication/clear lifetime, 0x25c8 complete object layout, constructor/destructor/EH/scalar/vtable/compiler split, focused UID0000MB PaletteLib.cpp ownership, one compile-visible extern immediately after the complete PaletteLib.h class declaration, and duplicate-storage/declaration rejection.`

Exact no-loss by-class MetaMan replacement:

`- [UID:000088][MetaMan](by-class/MetaMan.md) : reconstructable : 94% : very-strong : Complete guarded MetaMan.h owner declaration for the exact 0x14 MetaMan plus Singleton<MetaMan> class and size guard, preserving the accepted std::map table abstraction, complete SimpleUString key visibility, packet/cache/API surface including FindEntry, pending/synchronized/dirty fields, exactly one g_pMetaMan extern/definition pair, header-plus-children MetaMan.cpp route, complete MetaTable and four CollectionPane consumer closure, compiler vtable/scalar-wrapper policy, and metadata source route.`

Exact no-loss by-file MetaMan replacement:

`- [UID:0000LC][MetaMan](by-file/MetaMan.md) : reconstructable : 92% : very-strong : Metadata manager/table source module with guarded complete MetaMan plus Singleton<MetaMan> declaration and g_pMetaMan extern in MetaMan.h, header-plus-children MetaMan.cpp class route, accepted map/API/cache/packet/helper inventory, exact Meta.dat ownership, sole global child definition, and compiler-generated MetaMan RTTI/vtable child separated from MessageShowPane data.`

Exact no-loss by-global g_pMetaMan replacement, including correction of the stale manual `88% : strong` score to current ordinary `89/90`:

`- [UID:0000RL][g_pMetaMan](by-global/g_pMetaMan.md) : reconstructable : 89% : very-strong : MetaMan singleton pointer with exact storage, saved lifecycle function labels, 24 live xrefs, constructor/destructor/helper/deleting-destructor lifecycle sites, major UI/resource/session consumers, metadata sibling globals, adjacent-slot boundary, owner separation, alias-spelling caveat, exactly one external declaration through guarded MetaMan.h, sole zero-initialized definition in the global CPP child, duplicate declaration/storage rejection, and skipped unsupported data-label mutation documented.`

Exact B002-owned UID0003F1 insertion, preserved byte-for-byte so both reports provide one identical payload:

`        - [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md) 0x00624a98-0x00624b30 | method-use pooled UTF-16 metadata/resource/format literals | CollectionPanePanelResourceStrings : reconstructable : 92% : very-strong : Exact 152-byte run with eight UTF-16 literals, two zero alignments, 14 CollectionPane/CollectionPane2 xrefs, compiler item-split/pooling analysis, and file-owned no-object covered-by source representation through four consuming methods.`

Exact coordinated B002-owned additional replacements/insertions:

`- [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) : reconstructable : 94% : very-strong : Complete 0xf8 PanelPane-derived alternate collection renderer with one exact empty derived constructor, complete header declaration, vtable-routed OnPaint, typed ITEMINV.PAL/CLTINV.EPF frame-zero blit through g_pfnBlitSprite and m_visibleBounds, and file-owned shared-literal topology.`

`- [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) : reconstructable : 93% : very-strong : Complete header-emitted CollectionEntryRecord, CollectionGroupRecord, and CollectionPlayerDataView declarations with exact StringUtil dependency, 0x4c/0x2604 size guards, UserPane embedded-storage route, and unchanged UID0000P1 owner/emitter position 5.`

`- [UID:000089][MetaTable](by-class/MetaTable.md) : reconstructable : 94% : strong : Complete guarded 0x24 virtual metadata-table header with accepted RowMap storage, Rows and IsMaterialized accessors, exact payload fields, namespace-scope child bodies, and CollectionPane loader compatibility.`

`        - [UID:0003Y3][0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData](by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md) 0x0056ea30-0x0056ec44 | primary OnActivate method | CollectionPaneOnActivate : reconstructable : 93% : very-strong : Complete pointer-consuming activation override that resolves and materializes Collections/GroupNames metadata, initializes typed collection records from packet bytes, updates scroll state, invalidates, and accounts for four UID0003F1 literal uses without a raw helper call.`

`        - [UID:0003Y9][0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords](by-memory/0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md) 0x0056f810-0x0056fa8a | metadata loader method | CollectionPaneLoadCollectionGroupRecords : reconstructable : 92% : strong : Complete two-use Collections metadata consumer iterating MetaTable rows, decoding type/index from values 0/1, copying key/columns 2/3 through const Data/Length into exact typed fields, preserving collectedFlag, and writing the matching total.`

`        - [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md) 0x0056fdd0-0x0056fe41 | primary paint method | CollectionPane2OnPaint : reconstructable : 94% : very-strong : Complete ITEMINV.PAL plus pooled CLTINV.EPF frame-zero renderer with one UID0003F1 literal ref and exact typed g_pfnBlitSprite call against inherited m_visibleBounds.`

- The stale UID0001HD row is evidence only and Section 28 supplies its one merged no-loss replacement. Section 28 is the coordinated one-row-per-UID payload set: current PaletteLib UID0000A1/UID0000RW literals compare equal and UID0000MB is same-or-greater, so all three are explicit no-change; B008 owns its target/support handoffs, and B002 owns its target/broader handoffs. Checklist checks verify this exact report text and literal current comparisons; manual-file mutation remains supervisor-owned. C-FA-079 records that current ImageLib and Surface rows need no edit.
- No generated tracker text should be edited manually; tracker changes derive from validated ordinary metadata and generated refresh.

## Follow-Up Actions

1. Preserve the validated ten complete Section 22 bodies, two file-root includes, UID0000CG friend support, and UID00038U compiler-covered marker. Executed B003 state remains exclusive PaletteLib authority, B008 remains direct UID0003FA owner, and B002 remains direct UID0003F1 owner.
2. Current ordinary UID0000A1/UID0000RW, current class/global manual rows, and final generated PaletteLib.cpp/.h match the accepted predecessor route. B008 made no Palette write; later verification uses the latest supervisor-verified waited physical readback.
3. Before any later overlapping write, B002 physically rereads this validated B008 state and preserves B003. An active overlapping lease or missing predecessor payload is a hard stop pending a replacement supervisor serialization contract.
4. Concurrent leases or writes to shared destinations remain forbidden. B008 did not edit PaletteLib or manual coverage; B002 does not treat PaletteLib as its scope.
5. B002 retains D01-D08/P01-P03 for UID0003F1. B008 retains IDA-FA-01..03 and all `0x0056edc0` mutation ownership. All external IDA/coverage handoffs remain supervisor-owned and disjoint.
6. Completion commands `000000025057` through `000000025070` scoped-validated every changed ordinary page; the waited owner refresh physically shows CollectionPane `27/27/0`, all ten definitions once, UID00038U's compiler-covered marker once, and no affected comment-only or empty marker. Palette/MetaMan predecessor routes remain preserve/verify-only.
7. Manual coverage uses the exact coordinated Section 28 payloads once per UID. UID0000A1, UID0000RW, and UID0000MB are already-present no-change rows; later supervisor coverage never duplicates them.
8. Generated authority is always the latest supervisor-verified waited physical readback. Commands `24737`, `24849`, `24867`, `24868`, and completion command `25070` are dated receipts, not permanent authority. UID00038U is resolved as compiler-covered/no-authored-object; remaining unchecked work is only the supervisor-owned coverage/IDA handoff.

## Confidence

- Physical target, boundaries, values, xrefs, and consumer identity: very strong.
- Complete method behavior and exact constants/resources/data fields: very strong.
- Corrected one-context/two-buffer/row-plus-reused-text-rectangle/POD source shape, direct row updates, seven exact pooled literals, established `Assign`/const `Data`/`Length` usage, and `<cwchar>` declaration route: very strong.
- Complete four-consumer/file/class ownership, ten reconstructed and physically emitted member bodies, UID00038U compiler coverage, UID0001TZ/UserPane visibility, MetaTable RowMap route, direct ImageLib/Surface/Event/Config includes, exact B003-owned PaletteLib H route, complete MetaMan H route, and source-valid ScrollCollectionPane friendship: very strong and physically incorporated.
- Source-facing local/member spellings and declaration access: strong, intentionally capped below certainty because symbols are stripped.
- Overall UID0003FA remains `94/95`, UID0003Y6 remains `92/94`, UID00002X is current `94/94`, and UID0000IC is source-justified `94/94` after the completed callback and waited `27/27/0` readback. Remaining confidence caps are erased lexical/access spellings, not unresolved method behavior or compiler-data ownership.

## Validator Results

- Historical original B008 report-only snapshot for validator command `24224`, refreshed `2026-08-15T08:27:59-04:00`: `CollectionPane.cpp` SHA256 `5368174757DDD1BF582CCB40AA2C83B83BF3D5413B8DB2912E5243294D065397`, 3,417 bytes, 89 lines; `CollectionPane.h` SHA256 `AA3B903CA37B32EC6C787E770B279BC11451790AB9E13C93F9289E2FBB56810A`, 856 bytes, 24 lines. This is dated provenance, not callback authority.
- Historical intermediate post-B002 snapshot was validator command `24301`, refreshed `2026-08-15T18:26:55-04:00`: `CollectionPane.cpp` SHA256 `6D60593BEC652AFF4370B1E8698335D2E23AEB8EDEFF8DA3ACFAA16A527D3105`, 4,084 bytes, 101 lines; `CollectionPane.h` SHA256 `8DB3E5C6AA4E9F75A01425EC7A848D2B39972188506CCACAD42F7473BA1804B1`, 856 bytes, 24 lines. This receipt is dated evidence and not callback authority.
- Historical replacement-goal snapshot was validator command `24431`, refreshed `2026-08-15T19:57:54-04:00`: `CollectionPane.cpp` SHA256 `1FE012038D97ACEF827F641C063D4A57CA8DEF027A25729AA778AB861222A401`, 4,084 bytes, 101 physical lines; `CollectionPane.h` SHA256 `144D8C20EF6EE09CF7AA5E7D70B0BB6124F44EAFDE4D140C4C1D80DEB3BAC7AD`, 856 bytes, 24 physical lines. This is dated provenance only.
- Historical audit snapshot was validator command `24441`, refreshed `2026-08-15T20:29:30-04:00`: `CollectionPane.cpp` SHA256 `081D613BDB44448B971587614C75D8E91E842C6BC3C841F9905E73A1844D989A`, 4,084 bytes, 101 physical lines; `CollectionPane.h` SHA256 `5ABA81EE730F6CAA42B1B69DBDE978411072BD0D4DF5003D84E9426FC14A752D`, 856 bytes, 24 physical lines. It is dated provenance only.
- Historical dependency-closure snapshot was command `24506`, refreshed `2026-08-15T22:43:08-04:00`; its exact hashes remain dated evidence only.
- Historical overlap-reconciliation snapshot was command `24530`, refreshed `2026-08-15T23:22:46-04:00`; its exact hashes are dated evidence only.
- Historical executed-B003 predecessor receipt is validator command `000000024682`, refreshed `2026-08-16T01:45:46-04:00`: `CollectionPane.cpp` SHA256 `AED4461D96BA4FC708A4AA65D6436103E568715DF68556D83FF07F04D47F2788`, 4,084 bytes/101 lines; `CollectionPane.h` SHA256 `963F43EE1B856419B94FA3DCABB6FAA92A8ED1B2F701B2B7278F3CCA6F197F31`, 856/24; `UserPane.cpp` SHA256 `365DFC3FF0DEE03D97E4D0006ED8AE5A121DFBEF517DCC664AF0A81F3785AB77`, 87,893/2,672; `UserPane.h` SHA256 `2A0728D6E72C6BF6037A09E331D57F800742FE7B52EC684319E2AB4B59480B15`, 11,646/349; `PaletteLib.cpp` SHA256 `2D26CC0DB312B59884E6915252AB3B24EF670B9B75EC661505E22BAF5E7C4DDC`, 3,633/97; `PaletteLib.h` SHA256 `1D147A50389C0C0FF397E7FB010B4FF71FA41889FD47354CF12A3D18E3542B0C`, 1,951/58; `MetaMan.cpp` SHA256 `CB9210134FD2E86D992EEA5CAEA3020C7881479A4A21B2AAA2BB7A1B87B27867`, 12,391/323; `ImageLib.h` SHA256 `D2C21D8B6D8F8C503F3CE58946E96B213C050AF0EEA7CC329C38331BA1D2A167`, 1,943/68; and `Surface.h` SHA256 `D3811B8FE092E3BA48F26E7954EE5522A2D796B9817EF1FDAC1C99AD615D6DCF`, 3,087/102. This receipt proves B003 execution provenance but is not callback authority.
- Dated command `000000024719` observation, refreshed `2026-08-16T04:18:26-04:00`: `CollectionPane.cpp` SHA256 `8680F657C01FA44F5317A614BCA991CF5B4DF37AA4117866B348B5061428A877`; `CollectionPane.h` `85CCB05954A1212B4DE9CF54EA7DE051E891BCBC5B28792DABEA806386FC54F7`; `UserPane.cpp` `B40F1566CAC48CBD252196DE601164E2AD3829C0C78D2FBE707B0952D3EDDBAC`; `UserPane.h` `DB106B34C38ABBC48C3FF5126AB108AB81B7C1586EE744C854725AE112264C1E`; `PaletteLib.cpp` `F9A6054CC0FBF8E6DC3F354FB1286219A856127935C24229B2C69E6F31CCC33A`; `PaletteLib.h` `FA7F4907BEAF1D5B1029D40651FC433375298C5AD13BCF19D60168834BD31945`; `MetaMan.cpp` `05462B7F7038625075F7737E6A710E63DDDFC3460E6211C49D95156C4ECAECDF`; `ImageLib.h` `69ADFFD3FFAD28689FD6BFF8BACE42F26EE6607A1717F62AC5F6A0CEE06BF908`; `Surface.h` `039DDBA002E13C53E84C9AC891DF18A0EEF990303F3583D5BCD8FB406BB24C9B`. It is dated evidence only.
- Dated supervisor-audit command `000000024725` observation, refreshed `2026-08-16T04:27:15-04:00`: `CollectionPane.cpp` SHA256 `7E6B964D8241A5B85AFF57B858E41F0E2AA9066AE25D9C49D417C47FD62B6016`; `CollectionPane.h` `C995A3109164963EF241AE09053D0F6958D8EC32C2954E06C2DD225A605730BB`; `UserPane.cpp` `D5372F973A58FBDED3132004DEFE8217497B57B2686CCF0F2076F5EFD87E0736`; `UserPane.h` `D5BDC58BC30462312EAC062C9857489733C3A9FFD630E8C7F88341A2B38CF16B`; `PaletteLib.cpp` `60995B679874DE06A01464F84F04001E1F17183E78272442060AE4388A59F290`; `PaletteLib.h` `1611AD20389C1DF53AFBA6806A92684E98A49282A859207F18312E030AB69E49`; `MetaMan.cpp` `242981C7D511EA251BD9AF8B6561FE21C8D363FBCB7D3FCEF6C15D4AB17391B2`; `ImageLib.h` `C2CE1956E2C0D402DC4FB3D801B366C62D8E8DF19BC7B447170B8F23FFAF5EB7`; `Surface.h` `C3BBF70D5E13F7CD6250746B77267DCC0EA80B7BBBD5A18F7A8AAD63600B67A2`. It observed unchanged target topology and is not callback authority.
- Repair-time command `000000024737` observation, refreshed `2026-08-16T04:45:17-04:00`: `CollectionPane.cpp` SHA256 `2769D8FB09C23D87E2E00D0B2E0C64E55E20B525936136806BADC498FCA26E74`, 4,084 bytes/101 lines; `CollectionPane.h` `351BABF06A232D27BEC4F495539C1F93A19B42C8C8845DBE51CE0EEACCF8EE70`, 856/24; `UserPane.cpp` `82365396DC5F607197BB6F2DC8A93F22AB1C638BDB4198B245022D63B8DFF488`, 87,925/2,674; `UserPane.h` `6036E9B8B234FEA620AD17B201F39423F79C31FF75CD55C97CA47F02C05B681E`, 11,646/349; `PaletteLib.cpp` `76EB590FB52A8A99D64BAA08125C54BB084F1DD96EA7D48CB170693269FBF5AC`, 3,633/97; `PaletteLib.h` `122117108D0278107EC0A091059F8BC9EF61814EFE7F556D810A8E59D0BBBFB6`, 1,951/58; `MetaMan.cpp` `7BA0E1FED8A34DF6037E94D0015B1C555AD9C9A1D672BAAA7E07DE4B3EC88470`, 12,391/323; `ImageLib.h` `3B606E9DC90325685551C390D31CEE08A8D04511822F80C23D0A1FB41A73390D`, 1,943/68; and `Surface.h` `5FC68D3F1952E6515B61F619A8898BC92E2CA26D3F44AA86E3CF0E9B82731FE2`, 3,087/102. This is an audit-time observation only; no fixed command is present or future authority.
- Repair-time command-24737 observation found `MetaMan.h` literally absent; command `24539` remains dated pre-B003 evidence only.
- Repair-time command-24737 observation found CollectionPane with 17 routed entries, 10 filled, and 7 empty markers at UIDs `00002X`, `0003Y3`, `0003Y6`, `0003Y9`, `00038U`, `0003YG`, and `0003FA`. UID0003F1 was filled by its covered-by marker.
- Repair-time command-24737 observation found PaletteLib with 6 routed entries, 6 filled, and 0 empty in CPP plus a complete generated H: `PaletteLib.cpp` contained no class declaration, preserved all method children and the sole `PaletteLib *g_pPaletteLib = 0;`; `PaletteLib.h` contained one complete UID0000A1 class/helper declaration and one UID0000RW extern, with no storage definition. Executed-B003 ordinary state remains verify-only for B008.
- Repair-time command-24737 observation found MetaMan CPP with 16 routed entries, 16 filled, 0 empty, one full `class MetaMan` declaration plus MetaTable source, and one `MetaMan *g_pMetaMan = 0;`; H was absent. This observed support shape does not permit reduced declarations.
- Accepted-callback scoped validator receipts follow. Every command ran from exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`, exited `0`, returned `ok:1`, deferred generated refresh unless marked waited, and performed only validator-owned registry/projected-stats bookkeeping plus the stated generated side effect.

| ID / timestamp | Exact command | Diagnostics / generated state / side effects |
|---|---|---|
| `000000024822` / `2026-08-16T05:27:59-04:00` | `python .\tools\validator.py --mode file --file by-class\SimpleUString.md --apply` | Existing `missing_ref_uid 0003GZ`; scoped document accepted; generated deferred. |
| `000000024823` / `2026-08-16T05:28:02-04:00` | `python .\tools\validator.py --mode file --file by-type\by-struct\CollectionPlayerDataLayout.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024824` / `2026-08-16T05:28:04-04:00` | `python .\tools\validator.py --mode file --file by-class\MetaMan.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024825` / `2026-08-16T05:28:06-04:00` | `python .\tools\validator.py --mode file --file by-class\MetaTable.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024826` / `2026-08-16T05:28:09-04:00` | `python .\tools\validator.py --mode file --file by-global\g_pMetaMan.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024827` / `2026-08-16T05:28:11-04:00` | `python .\tools\validator.py --mode file --file by-file\MetaMan.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024828` / `2026-08-16T05:31:20-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00624c10-0x00624c20.CollectionPaneRectConstant.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024829` / `2026-08-16T05:31:22-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056edc0-0x0056f655.CollectionPaneOnPaint.md --apply` | No scope-blocking diagnostic; generated deferred. |
| `000000024830` / `2026-08-16T05:31:24-04:00` | `python .\tools\validator.py --mode file --file by-class\CollectionPane.md --apply` | Initial accepted class pass; generated deferred. |
| `000000024831` / `2026-08-16T05:31:27-04:00` | `python .\tools\validator.py --mode file --file by-file\CollectionPane.md --apply` | Initial accepted owner-page pass; generated deferred. |
| `000000024832` / `2026-08-16T05:33:58-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024833` / `2026-08-16T05:34:01-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024834` / `2026-08-16T05:34:03-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f660-0x0056f665.CollectionPaneFalseStubA.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024835` / `2026-08-16T05:34:05-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024836` / `2026-08-16T05:34:08-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024837` / `2026-08-16T05:34:10-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024838` / `2026-08-16T05:34:12-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024839` / `2026-08-16T05:34:14-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024840` / `2026-08-16T05:34:16-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024841` / `2026-08-16T05:34:19-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md --apply` | Exact signature/prose accepted; generated deferred. |
| `000000024842` / `2026-08-16T05:34:21-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md --apply` | Parent split/index accepted; generated deferred. |
| `000000024843` / `2026-08-16T05:34:23-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056e940-0x0056fe75.CollectionPane.md --apply` | Broad split/index accepted; generated deferred. |
| `000000024844` / `2026-08-16T05:37:37-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md --apply` | Complete OnActivate accepted; generated deferred. |
| `000000024845` / `2026-08-16T05:37:39-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md --apply` | Complete loader accepted; generated deferred. |
| `000000024846` / `2026-08-16T05:37:42-04:00` | `python .\tools\validator.py --mode file --file by-class\CollectionPane2.md --apply` | Complete alternate-class H accepted; generated deferred. |
| `000000024847` / `2026-08-16T05:37:44-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md --apply` | Complete alternate OnPaint accepted; generated deferred. |
| `000000024848` / `2026-08-16T05:38:21-04:00` | `python .\tools\validator.py --mode file --file by-class\CollectionPane.md --apply` | Follow-up direct `MetaTable.h` include accepted; generated deferred. |
| `000000024849` / `2026-08-16T05:38:42-04:00` | `python .\tools\validator.py --mode file --file by-file\CollectionPane.md --apply --wait-generated` | Exit `0`, `ok:1`; generated completed. Project-wide diagnostics included `autogen_children_fallback_insert:6`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:62`, `autogen_header_children_marker_missing:1`, and seven existing owner-page `missing_ref_uid` findings. Physical readback exposed ten newly registered signature-only empty children, requiring the bounded corrective formal dispositions below. |
| `000000024857` / `2026-08-16T05:43:40-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024858` / `2026-08-16T05:43:42-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024859` / `2026-08-16T05:43:44-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f660-0x0056f665.CollectionPaneFalseStubA.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024860` / `2026-08-16T05:43:46-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024861` / `2026-08-16T05:43:49-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024862` / `2026-08-16T05:43:51-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024863` / `2026-08-16T05:43:53-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024864` / `2026-08-16T05:43:56-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md --apply` | Registry `blank -> block`; comment-only non-emitting block mechanically accepted; generated deferred; not source completion. |
| `000000024865` / `2026-08-16T05:43:58-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md --apply` | Registry `blank -> block`; comment-only non-emitting block mechanically accepted; generated deferred; not source completion. |
| `000000024866` / `2026-08-16T05:44:00-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md --apply` | Registry `blank -> block`; comment-only no-body block mechanically accepted; generated deferred; not source completion. |
| `000000024867` / `2026-08-16T05:44:54-04:00` | `python .\tools\validator.py --mode file --file by-file\CollectionPane.md --apply --wait-generated` | Exit `0`, `ok:1`; generated completed. Project-wide diagnostics were `autogen_children_fallback_insert:6`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:62`, `autogen_header_children_marker_missing:1`, `autogen_header_metadata_refresh:142`, `autogen_header_noop:126`, `generated_metadata_refresh:277`, seven existing owner-page `missing_ref_uid`, and one registry rebuild; none invalidated the scoped owner. |
| `000000025057` / `2026-08-16T09:08:59-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025058` / `2026-08-16T09:09:02-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025059` / `2026-08-16T09:09:57-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f660-0x0056f665.CollectionPaneFalseStubA.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025060` / `2026-08-16T09:10:00-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025061` / `2026-08-16T09:11:36-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025062` / `2026-08-16T09:11:38-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025063` / `2026-08-16T09:11:41-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025064` / `2026-08-16T09:12:38-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025065` / `2026-08-16T09:12:40-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025066` / `2026-08-16T09:12:42-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; score/formal registry accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025067` / `2026-08-16T09:14:39-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x006245dc-0x00624668.CollectionPaneVtableData.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; inert marker and `94/95` accepted, generated deferred; pre-existing `missing_ref_uid 00038Z` diagnostic, plus validator-owned registry/projected-stats side effects. |
| `000000025068` / `2026-08-16T09:14:41-04:00` | `python .\tools\validator.py --mode file --file by-class\CollectionPane.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; direct includes, current `94/94`, and complete route accepted, generated deferred; seven pre-existing `0003Y1/0003Y2/00038Z` missing-reference diagnostics, plus validator-owned registry/projected-stats side effects. |
| `000000025069` / `2026-08-16T09:14:43-04:00` | `python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --queue-timeout 240` | Exit `0`, `ok:1`; narrow friend support accepted, generated deferred; validator-owned registry/projected-stats side effects only. |
| `000000025070` / `2026-08-16T09:15:55-04:00` | `python .\tools\validator.py --mode file --file by-file\CollectionPane.md --apply --queue-timeout 240 --wait-generated` | Exit `0`, `ok:1`; generated refresh completed. Project-wide diagnostics were `autogen_children_fallback_insert:6`, `autogen_children_marker_missing:72`, `autogen_emitter_has_no_code:61`, `autogen_header_children_marker_missing:1`, `autogen_header_metadata_refresh:143`, `autogen_header_noop:125`, `generated_metadata_refresh:277`, seven pre-existing owner-page `missing_ref_uid` findings, and one registry rebuild; none invalidated the scoped owner. |

- Final waited physical readback after command `000000024867`: `CollectionPane.cpp` SHA256 `5230AFEBBB93E3E03AB33F305F7566DC121F55377EC0AE6C2A9747B9913D4521`, 14,875 bytes/372 lines; `CollectionPane.h` `56887D4C34D3138EDC6D2429BBA34CFC5BBF2F6356C549EB1F993D26C4F980B8`, 2,564/77; `UserPane.cpp` `1C7741AE9AB353CB993CEE6E3446C90EF9733D9F1AA22C0F7A3EEFCE6C0D12F0`, 87,421/2,651; `UserPane.h` `8FE8D5B2A2CBA9DCAD4BC3DB84F32361538AF87364E248CB8188D4A125E7D888`, 12,518/382; `PaletteLib.cpp` `01247CDB7FFC24A9D7DFE2A3CDE69067C4448521FACF1F1592F9F25DE889F5F8`, 3,633/97; `PaletteLib.h` `D71B4FF3A32CF5833697F8F7CB0469547C99EC8ADB33C666EF195878E956CCF5`, 1,951/58; `MetaMan.cpp` `28F91630B28291A1E305171E42E4FE474A7DCE47A3471DA71D8EF609D8160C8C`, 10,755/262; `MetaMan.h` `B9DEE777914AE304F3CBE07DD5EC5D2DF17F975EF68BD47D28478BE75917C44A`, 2,612/95; `StringUtil.h` `BAE851C4C4FE625E6EF2BE49B9174CD6EBB0874D4BA071E160FCC8D64E369B68`, 1,138/42; `ImageLib.h` `E86B08D1FB332DFEE6321E3BB8EABA33ADC0AF37165CDFDC4D4741A0945160FD`, 1,943/68; `Surface.h` `1D7AD892060F30304D3597059CDB23EE66FC7B205EC91EA2F8310E5A452AFBC2`, 3,087/102. This is a dated callback receipt; later authority is the latest supervisor-verified waited physical readback.
- A subsequent project validator refresh, not run by B008, advanced all generated headers to audit-time observation command `000000024868`, refreshed `2026-08-16T06:02:42-04:00`. Fresh physical identities are: `CollectionPane.cpp` SHA256 `9D5ACEFAD311EC0A9327996AC70F409BF43F3F3326183DE0DEA9DDC8F27409A7`, 14,877 bytes/372 lines; `CollectionPane.h` `4327C0868E2FDCFC9521D83097579758FA98DA0884B5968B18AAC87E3F72662C`, 2,566/77; `UserPane.cpp` `631A84ED60EC7147D0D69DB3BE0E3A9E587471022C6399367FA20D20F078E71B`, 87,421/2,651; `UserPane.h` `6658308D40D962EF09E2C9BAE52AFFCEC45A71E5FD97F2ABA16B6D29EF9EB338`, 12,518/382; `PaletteLib.cpp` `47570E33D003D50CC0973684C645E45BE54E980FA14F3A3986287EE2C167A7D4`, 3,633/97; `PaletteLib.h` `46A12DCB996359423B110CDA61D765141E533C44EB395342B3B2B79CBF79971B`, 1,951/58; `MetaMan.cpp` `B895365FB46EF7ECE4873BF7D5125C1CDBD3AF45DADAB2D68A32E498438937BB`, 10,755/262; `MetaMan.h` `870A5F3FDB1562103E20F2B27729C7874BA9A6BE80B848F3A630C0F51BCC2A16`, 2,612/95; `StringUtil.h` `46DAF3BFF9F1BA5725961E33D71212B45202AF761C2765957CE208ECE17917EE`, 1,138/42; `ImageLib.h` `63214153EA20F1A6B69501DB4ABF61AAC85A7A24BB1FA9D9F45D59BC18738961`, 1,943/68; `Surface.h` `42AF515077C03B3F1F1ABFD62CF4E5A6A35EA8BD69E915057113CAA84D8BCF48`, 3,087/102. This observation supersedes command `24867` only for audit-time physical identity; neither fixed command is continuing authority.
- Dated command-24868 semantics remain exact as an observation: CollectionPane was `27/26/1`; ten newly registered child entries were mechanically nonempty because their CPP channels contained comments, and UID00038U was empty. `CollectionPane.h` contained one complete CollectionPane and one complete CollectionPane2 declaration. `UserPane.h` contained all three collection records while `UserPane.cpp` contained none. Palette had one H class, one H extern, one CPP definition, no CPP-local class, and `6/6/0`. MetaMan had one H manager class, one H MetaTable class, one H extern, one CPP definition, no CPP-local manager class, and `16/16/0`. `StringUtil.h` contained one const `Data()` and one const `Length()` accessor. This receipt proves topology only, not authored completeness, and no generated artifact was edited directly.
- Completion callback physical readback for command `000000025070`: `CollectionPane.cpp` SHA256 `B7C751EDE8538A962915EF038533544729F758738FCB7D5819583772346371D0`, 19,526 bytes/534 lines; `CollectionPane.h` SHA256 `F6E02C6BEFB02356E695640BB0F0C7D3679FC8E9FF25F0FE741ED3B046C12905`, 2,566/77; and `ScrollCollectionPane.h` SHA256 `28A68E2FDE240E0E204AA25AEACC58BAC6B3EF14E796F0C4DC88B64A9C355161`, 2,164/70. All carry command/timestamp metadata `000000025070` / `2026-08-16T09:15:55-04:00`. `CollectionPane.cpp` has exactly 27 unique UID blocks and all 27 are filled; each UID0003Y4/Y5/Y7/Y8/YA/YB/YC/YD/YE/YF definition occurs once; the UID00038U UID line, exact `Compiler-covered by CollectionPane's complete virtual declaration and method bodies.` first comment, and exact `Do not hand-author vtable data or RTTI source.` last comment each occur once; direct Event/Config includes occur once; and the affected placeholder scan returns zero. `CollectionPane.h` retains one complete `0x10c` CollectionPane declaration and complete CollectionPane2 route; `ScrollCollectionPane.h` contains one `friend class CollectionPane;`. This is a dated callback receipt; the latest supervisor-verified waited physical readback controls later verification.
- The completed twins contain 23 `already-present` actions, of which C-FA-043 remains proposed because its protection verification belongs to the supervisor-owned IDA stage. The other 22 already-present rows are checked against current or dated evidence as their wording states; C-FA-051/C-FA-104 explicitly classify the dated mechanical generated observation without treating it as current source closure. No already-present row relies on a fixed generated command as continuing authority.

## Changed Files

- These historical accepted-callback hashes are dated prior-callback identities, not current authority; the current callback before/after table and waited physical readback below control current state:

| Document | SHA256 | Bytes / lines |
|---|---|---|
| `by-class/SimpleUString.md` | `9C70ACD2F2D7FA75FBFF4FBDA73367213DB343D487C79904BBBF045B16B556A9` | `40,860 / 230` |
| `by-type/by-struct/CollectionPlayerDataLayout.md` | `9C21BFB5E2F0E34CE199AAE66503D0B01E1DFBE573081FA762A66B2D539C2145` | `23,679 / 214` |
| `by-class/MetaMan.md` | `24E96B7DFD3B149AD20A56DA334C242F0F4641F9944D8F9000BED9048CBB55A0` | `22,560 / 243` |
| `by-class/MetaTable.md` | `6E8ADB16351E8E235A0FB87DA63AB9A97E5F3A98D282FE9DFCE364AF3A5A4DC0` | `19,698 / 174` |
| `by-global/g_pMetaMan.md` | `4F04CB15294BDFE78C2C2615065614D5DCA44579D022F0B7E4DCEFE0F494481B` | `10,980 / 113` |
| `by-file/MetaMan.md` | `59DDA6DCE2DD82F1C964B8BFACEFF0599C4DA5E7779071FD46A86E5D34324769` | `32,886 / 221` |
| `by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md` | `F10219DBB41F0F46ED0330234C6941F7F5871B1F31CD951F2DAEF1D9F9B552EE` | `5,635 / 62` |
| `by-memory/0x0056edc0-0x0056f655.CollectionPaneOnPaint.md` | `F8CC434023308050EA88CBC016980936F93C03FEC507B31794925F71D87A8AE6` | `10,991 / 179` |
| `by-class/CollectionPane.md` | `FE4EEF06C10087932A6AFBBD2DA93888F1F6F478A0387A4283BE193DA42B96ED` | `25,086 / 209` |
| `by-file/CollectionPane.md` | `6C42EEDA841495883716BE5CB49109D88DDB5319BE085BB54818F96DC2CBDCBD` | `35,030 / 200` |
| `by-memory/0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md` | `BE3AFFB3D5D73C8149939F678BF7904E6385AE72D7ACCE62A02EC2160024B579` | `2,967 / 45` |
| `by-memory/0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md` | `6F90FC485E30D2EBDF54BD93F2AD78761B8162A1E1874AA766CACE9D510F7321` | `2,829 / 45` |
| `by-memory/0x0056f660-0x0056f665.CollectionPaneFalseStubA.md` | `3B187FCF4BC9C03522AED7C7D67C16099E84618BE9ADDEBC8704A80FFCA983DF` | `2,938 / 45` |
| `by-memory/0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md` | `EC1F9B91B2DB8C46D58172A0489CEE2F7006DC703F99CF77709385AB1CE3B399` | `3,347 / 48` |
| `by-memory/0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md` | `34DD3416B49284BC0377A0DD6978AFB1CC046D45AFEC8BB484301AB88F805A98` | `3,076 / 46` |
| `by-memory/0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md` | `5A086305827D900B24E340E121CE5FF2E607AA7612FC032397529575531E0F0F` | `2,755 / 44` |
| `by-memory/0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md` | `32C974ED03D60C6E50E9C64A8E3B74A0214F8248B725AA4D14C153DD969B0669` | `2,627 / 44` |
| `by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md` | `E1623EEF885E106F30B8394951E08D1D00CDA488F156BE0FC05B21667B77CB9A` | `3,195 / 45` |
| `by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md` | `E01B2E286D6EF3B26994016C014DA3980DF588B61C3F41E0242D019977B1AB75` | `2,909 / 45` |
| `by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md` | `06ED9E4046D79D58D77A3FDDFE8E3C5CA057470CB32BCA06DD2D2F90631B28C7` | `2,716 / 44` |
| `by-memory/0x00624788-0x00624c60.LookGroupCollectionResourceStringData.md` | `85A51DF08A632F1F3DD89C6875A171C7C7F5A845FC874281182253213D83ED69` | `36,868 / 247` |
| `by-memory/0x0056e940-0x0056fe75.CollectionPane.md` | `945CAF40E6942DE9FEAD45BC19A21B0F4928BE20446A2F583B9A9AE1D310CF13` | `26,993 / 158` |
| `by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md` | `48F0EABC2063AA21F6F3A756FF705DA72D516D2E2DEE9B18A0917FF2DD9CA88C` | `7,433 / 103` |
| `by-memory/0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md` | `C8A3173CE58268C0E1F8EA253D02DBBA4465937529221AA45C5AA5D12D7304A6` | `5,556 / 89` |
| `by-class/CollectionPane2.md` | `1C5ECF96B5A7EDA6A8A920EDC5C2A3A2524548C6250D757B7CA824002D4275F4` | `30,052 / 188` |
| `by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md` | `2F4B438E39C4737074B76B85F925FDA4CD3EE79978617BD32C025660EB2145F4` | `4,104 / 58` |

- The completion callback changed exactly the following 14 ordinary destinations; each before/after identity was physically read, and this same report was updated additively in place. The report's final self-referential identity is returned externally after stable reread.

| Completion-callback ordinary document | Before SHA256 / bytes / lines | After SHA256 / bytes / lines |
|---|---|---|
| `by-memory/0x0056ec50-0x0056ecd8.CollectionPaneUpdateRenderRegion.md` | `BE3AFFB3D5D73C8149939F678BF7904E6385AE72D7ACCE62A02EC2160024B579` / `2,967` / `45` | `E780C18BD5262A64410AD47221E930C92A2748E19029157817DF79388A39961C` / `4,005` / `63` |
| `by-memory/0x0056ece0-0x0056edb1.CollectionPaneUpdateScrollRange.md` | `6F90FC485E30D2EBDF54BD93F2AD78761B8162A1E1874AA766CACE9D510F7321` / `2,829` / `45` | `A1D7B2368D4CACDF4C93E8662576860CDC639F357BEA602E557CFA046B5694EC` / `4,427` / `82` |
| `by-memory/0x0056f660-0x0056f665.CollectionPaneFalseStubA.md` | `3B187FCF4BC9C03522AED7C7D67C16099E84618BE9ADDEBC8704A80FFCA983DF` / `2,938` / `45` | `4ECF44476C0CDB4FBDF551B0B82FB8F0782308FD36BAB46A202F518A441B44EE` / `3,308` / `50` |
| `by-memory/0x0056f670-0x0056f7f4.CollectionPaneOnInputEvent.md` | `EC1F9B91B2DB8C46D58172A0489CEE2F7006DC703F99CF77709385AB1CE3B399` / `3,347` / `48` | `DBE21FB0E7030283A52CC28C2372EF67B97F0E8EEF6A17641F3B1F0A44484D8C` / `6,339` / `108` |
| `by-memory/0x0056fa90-0x0056fac8.CollectionPaneOnScrollPositionChanged.md` | `34DD3416B49284BC0377A0DD6978AFB1CC046D45AFEC8BB484301AB88F805A98` / `3,076` / `46` | `F4D7575100B826D49F46AEADEB989ED19310386802FAF95048A713557CE4992D` / `3,769` / `60` |
| `by-memory/0x0056fad0-0x0056fb36.CollectionPaneAttachToLayer.md` | `5A086305827D900B24E340E121CE5FF2E607AA7612FC032397529575531E0F0F` / `2,755` / `44` | `32A8A078ADB93218F479FFE9B897F7DE5A162EE357A92A6C36458619707A2A5C` / `3,484` / `56` |
| `by-memory/0x0056fb40-0x0056fb56.CollectionPaneDetachFromLayer.md` | `32C974ED03D60C6E50E9C64A8E3B74A0214F8248B725AA4D14C153DD969B0669` / `2,627` / `44` | `F7336F8AC2C27F48FAE5851397188A1753CBBA545D3AF6D22DB2E7D0B694E258` / `2,983` / `49` |
| `by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md` | `E1623EEF885E106F30B8394951E08D1D00CDA488F156BE0FC05B21667B77CB9A` / `3,195` / `45` | `7D45B309146673BAE721A1C91B9523A06CB10CDE4E33B5C220222CC20F46208C` / `3,719` / `52` |
| `by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md` | `E01B2E286D6EF3B26994016C014DA3980DF588B61C3F41E0242D019977B1AB75` / `2,909` / `45` | `C7FBFD3612662089E8DF93FC114DF41004F6F7E33FB90C9FC3500C9676703475` / `3,609` / `57` |
| `by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md` | `06ED9E4046D79D58D77A3FDDFE8E3C5CA057470CB32BCA06DD2D2F90631B28C7` / `2,716` / `44` | `56D590711AEF74801923C1FA07A0B8DCD04B5101E5876B83E83995A4139C5BCC` / `3,368` / `55` |
| `by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md` | `5CB1F7451FF95FCE5AF089D3195B7A13F458FAE53CE1557E4F4925E6123EA88D` / `8,555` / `88` | `AD7A7C9B8DACC1383C09769FBAF7CD10355ABCFEC614BB925ADAE6D7A5883FCD` / `9,276` / `92` |
| `by-class/CollectionPane.md` | `FE4EEF06C10087932A6AFBBD2DA93888F1F6F478A0387A4283BE193DA42B96ED` / `25,086` / `209` | `0532C91D6D9110085798D151D4624F577D9AB0FAA677E8874A1F5A3DF8246ADC` / `26,765` / `213` |
| `by-class/ScrollCollectionPane.md` | `C87F86A07E4B088183B7B8B2ABBEC60BDF4B38E43A4AA8DF6310368467D65ACA` / `51,631` / `315` | `700FD739129A32D59E6AE0B868F45F82654FD165E456E6B7BB68493D9D5ED3BE` / `52,354` / `319` |
| `by-file/CollectionPane.md` | `6C42EEDA841495883716BE5CB49109D88DDB5319BE085BB54818F96DC2CBDCBD` / `35,030` / `200` | `6DDA2D507C4E1CE70C7C422227B88EAF21D966B214425DCA806FC72427933E12` / `36,357` / `202` |

- Each ordinary document was leased only for its edit/validation batch and released immediately. Manual coverage, peer reports, audit/catalog/goal/notes, lifecycle state, IDA, and unrelated targets were not directly edited. Generated source/Markdown and validator registry/projected-stats changes were validator-owned side effects of the authorized scoped commands, never direct edits.
- Section 31 records all 14 completion-callback validators plus the single waited owner refresh and physical generated reread. The report retains no executable scripting/runbook and contains exactly one standalone terminal workflow marker after the checklist.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|---|---|
| [x] | C-FA-001 | 0003FA | The target is exactly `[0x00624c10,0x00624c20)`, size 16, with SHA256 `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87`. | very-strong | Live item boundaries and bytes | UID0003FA range/evidence | incorporate | verified |
| [x] | C-FA-002 | 0003FA | Current IDA state is name `xmmword_624C10`, type absent, AR absent, AP absent, with FR/FP not applicable. | very-strong | Live item and comment queries | UID0003FA IDA state | incorporate | verified |
| [x] | C-FA-003 | 0003FA | Bytes decode as signed int32 `left=6`, `top=14`, `right=161`, `bottom=62`. | very-strong | Byte decoding plus RectBounds UDT | UID0003FA behavior | incorporate | verified |
| [x] | C-FA-004 | 0003FA | The exact 16-byte pattern is unique in the loaded image. | very-strong | Live bounded byte search | UID0003FA evidence | incorporate | verified |
| [x] | C-FA-005 | 0003FA | The target has exactly one inbound data xref at `0x0056ee7d`. | very-strong | Live xref query | UID0003FA xrefs | incorporate | verified |
| [x] | C-FA-006 | 0003Y6 | Xref item `[0x0056ee7d,0x0056ee84)` uniquely executes `movaps xmm0, ds:xmmword_624C10` and has SHA256 `4D65DC72D47E43605481405DDB103222FC7D9B53016C92F225B8FF74366CACD7`. | very-strong | Live disassembly and bytes | UID0003Y6 constant provenance | incorporate | verified |
| [x] | C-FA-007 | 0003Y6 | The packed value is stored to typed local `destinationBounds : RectBounds` and copied to the working row rectangle. | very-strong | Stack frame and disassembly | UID0003Y6 local initialization | incorporate | verified |
| [x] | C-FA-008 | 0003FA | RectBounds is exactly 16 bytes with int fields at offsets `0,4,8,0xc`. | very-strong | Live type inspection | UID0003FA type interpretation | incorporate | verified |
| [x] | C-FA-009 | 0003Y6 | Each rendered row advances rectangle top and bottom by exactly 50 pixels. | very-strong | Instructions at `0x0056f5bf` and `0x0056f5c7` | UID0003Y6 loop geometry | incorporate | verified |
| [x] | C-FA-010 | 0003FA | Plausible human source is POD aggregate initialization `RectBounds rowBounds = { 6, 14, 161, 62 };`. | strong | Local use, POD layout, and accepted compiler-pattern controls | UID0003FA formal/source shape | incorporate | verified |
| [x] | C-FA-011 | 0003FA | Static, member, global, array-element, and standalone-object source forms are invalid; a function-local POD aggregate is the accepted form. | strong | One local initialization use and no identity/address escape | UID0003FA negative evidence | incorporate | verified |
| [x] | C-FA-012 | 0003Y6 | The sole consumer function is `[0x0056edc0,0x0056f655)`, size `0x895`, SHA256 `E620D25A7EC887E994EE6DB722B184BD4BF99371AFDEB5DF3B762666372639CC`. | very-strong | Live function and body bytes | UID0003Y6 range/evidence | incorporate | verified |
| [x] | C-FA-013 | 0003Y6 | The function has 575 instructions, 64 basic blocks, 17 profiled callees, zero direct code callers, and one vtable data xref. | very-strong | Live function profile and xrefs | UID0003Y6 inventory | incorporate | verified |
| [x] | C-FA-014 | 0003Y6 | Vtable cell `0x00624624` identifies the consumer as CollectionPane primary virtual slot `+0x44` / `OnPaint`. | very-strong | Vtable bytes, class table, current docs | UID0003Y6 identity | incorporate | verified |
| [x] | C-FA-015 | 0003Y6 | OnPaint initializes EPF state, uses `ITEMINV.PAL` and `CLTINV.EPF`, draws the background, and sets draw/text-background modes. | very-strong | Decompile, strings, call profile | UID0003Y6 formal CPP/behavior | incorporate | verified |
| [x] | C-FA-016 | 0003Y6 | First visible group is current scroll position when five rows fit, otherwise `max(snapshot-5,0)`, and at most five valid groups render. | very-strong | Complete control-flow analysis | UID0003Y6 formal CPP/behavior | incorporate | verified |
| [x] | C-FA-017 | 0003Y6 | Group records use accepted stride `0x2604` and fields groupType, totalEntries, and collectedEntries from UID0001TZ. | very-strong | Binary offsets plus accepted typed layout | UID0003Y6 dependencies | incorporate | verified |
| [x] | C-FA-018 | 0003Y6 | Each row uses `CLTLIST.EPF` frame `completionPercent/100` and palette `CLTLIST.PAL`. | very-strong | Decompile, strings, layout lookup | UID0003Y6 formal CPP/behavior | incorporate | verified |
| [x] | C-FA-019 | 0003Y6 | Group name lookup uses table `GroupNames`, decimal groupType key, and exact three-character fallback `\uC548\uB098\uC640`. | very-strong | Exact string bytes and MetaMan flow | UID0003Y6 formal CPP/behavior | incorporate | verified |
| [x] | C-FA-020 | 0003Y6 | OnPaint draws name shadow/highlight, percent with exact format `L"%d %%"`, and exact count format `L"%d/%d"`. | very-strong | Exact string bytes and draw sequence | UID0003Y6 formal CPP/behavior | incorporate | verified |
| [x] | C-FA-021 | 0003FA | Canonical owner is class UID00002X rather than file UID0000IC. | strong | Local belongs to class method; project class-child convention | UID0003FA metadata | incorporate | verified |
| [x] | C-FA-022 | 0003FA | Emitter is UID00002X with position `75`. | strong | Method-local covered-by ordering | UID0003FA metadata | incorporate | verified |
| [x] | C-FA-023 | 0003Y6 | OnPaint emits through UID00002X at position `70`. | strong | Class source order and accepted sibling order | UID0003Y6 metadata | incorporate | verified |
| [x] | C-FA-024 | 0003FA | Target score is completion `94`, confidence `95`; POD aggregate syntax, the established SimpleUString route, declaration-visible collection structs, and dependency-closed OnPaint includes/owner headers close the source-support blocker for its covered-by route. | strong | Exact target proof plus corrected formal CPP/H/API/dependency closure | UID0003FA metadata | incorporate | verified |
| [x] | C-FA-025 | 0003Y6 | OnPaint score is completion `92`, confidence `94` after exact context/buffer/rectangle, string-operation, collection-header, render-service, palette-service, metadata-service, and CRT declaration closure; original lexical names remain inferred. | strong | Complete behavior, live SSO sequence, physical stack shape, exact includes, and complete owner headers | UID0003Y6 metadata | incorporate | verified |
| [x] | C-FA-026 | 0003FA | Formal target CPP is the exact two-line covered-by marker in Section 22. | very-strong | No-duplicate use-site representation | UID0003FA formal CPP | incorporate | verified |
| [x] | C-FA-027 | 0003FA | Formal target H remains exactly blank. | very-strong | No standalone declaration exists | UID0003FA formal H | incorporate | verified |
| [x] | C-FA-028 | 0003Y6 | Formal OnPaint/file-root CPP includes `CollectionPane.h`, `UserPane.h`, `MetaMan.h`, `MetaTable.h`, `ImageLib.h`, `PaletteLib.h`, `Surface.h`, and `<cwchar>`; it uses one initialized `EPFTileContext`, `.bounds`, exact `wchar_t[128]` buffers, one reused text `RectBounds`, POD row-bounds initialization, and only declared `Assign`/const `Data`/`Length` plus `wcslen`. | very-strong | Live stack/SSO sequence plus exact declaration-route audit | UID0003Y6 formal CPP | incorporate | verified |
| [x] | C-FA-029 | 0003Y6 | Formal OnPaint H remains blank because UID00002X owns the declaration. | strong | Single class header route | UID0003Y6 formal H | incorporate | verified |
| [x] | C-FA-030 | 0003FA | Target prose incorporates exact bytes, hash, xref, local provenance, boundaries, rejected source forms, and generated disposition. | very-strong | Complete report evidence | UID0003FA all relevant sections | incorporate | verified |
| [x] | C-FA-031 | 0003Y6 | OnPaint page incorporates complete behavior, local provenance, position, corrected POD/stack/string formal CPP, exact `UserPane.h` and six direct external include routes, dependency-owner links, and `92/94` score. | very-strong | Complete report evidence plus live stack/SSO/header/dependency reconciliation | UID0003Y6 all relevant sections | incorporate | verified |
| [x] | C-FA-032 | 00002X | CollectionPane is current `94/94`, owns both B008 routes, and supplies the exact complete file-root CPP preamble plus guarded 17-member H declaration: lifecycle; render-region/layer/paint/activation virtuals; pointer/key/packet handlers; scroll-range, record-load, and scroll-change members; three rectangle helpers; detail dispatch; exact fields; and size guard. | very-strong | B008 signatures/stack evidence plus B002 four-consumer/class closure | UID00002X formal CPP/H plus shared child signature prose | incorporate | verified |
| [x] | C-FA-033 | 0000IC | The ten body definitions, UID00038U compiler-covered marker, and support closure are incorporated; file score `94/94` is source-justified and waited command `000000025070` physically proves `27/27/0`, while dated `27/26/1` remains only a mechanical placeholder observation. | very-strong | Fresh ten-body/UID00038U evidence plus waited physical generated readback | UID0000IC source topology and score | incorporate | verified |
| [x] | C-FA-034 | 0002V2 | Mixed read-only parent remains non-reconstructable/non-emitting at `88/92` and identifies UID0003FA as a source-local rectangle child. | strong | Exact split child and parent role | UID0002V2 child inventory | incorporate | verified |
| [x] | C-FA-035 | 0001HD | Broad CollectionPane range remains non-reconstructable/non-emitting at `88/91` and links dependency-closed OnPaint plus UID0003FA. | strong | Exact method split/index policy | UID0001HD child inventory | incorporate | verified |
| [x] | C-FA-036 | 0003F1/0001R8 | Current UID0003F1 is `92/95` with its covered-by route and all 14 uses; B002's direct final target recommendation is `92/94`, while existing UID0001R8 collection UI resource ownership remains correct without an edit. | very-strong | Current UID0003F1 marker/use table, exact B002 recommendation, and UID0001R8 ownership | UID0003F1 current/final score distinction; UID0001R8 no edit | incorporate | verified |
| [x] | C-FA-037 | 0000D9 | Inline `const wchar_t *Data() const` and `unsigned int Length() const` are present beside `MutableData()` in the complete SimpleUString H declaration; exact OnPaint SSO selection and `+0x10` counted-copy read establish both read-only accessors, while implicit assignment, `operator==`, and `c_str()` remain rejected. | strong | Live `0x0056f0a2-0x0056f0b2`/draw-site selection plus UID0000D9 layout | UID0000D9 formal H through UID0000OB/StringUtil.h | incorporate | verified |
| [x] | C-FA-038 | 0001TZ | Current `93/94` formal state has the exact `CollectionEntryRecord`, `CollectionGroupRecord`, and `CollectionPlayerDataView` declarations in H, includes `../../util/StringUtil.h`, adds exact `0x4c`/`0x2604` guards, and exposes them through `UserPane.h` before CollectionPane consumers; CPP is blank. | very-strong | B008 visibility analysis plus B002 layout/guard closure | UID0001TZ formal CPP/H and score | incorporate | verified |
| [x] | C-FA-039 | 0003FA | Target boundaries contain no padding; exact predecessor and successor are separate 16-byte SelfLookPane-owned items. | very-strong | Live item models, bytes, and xrefs | UID0003FA boundary analysis | incorporate | verified |
| [ ] | C-FA-040 | 0003Y6 | IDA-FA-01 is a pure public rename to `CollectionPane__OnPaint`. | strong | Vtable and complete method identity | Supervisor Gate 2B IDA-FA-01 | incorporate | proposed |
| [ ] | C-FA-041 | 0003Y6 | IDA-FA-02 adds the exact function-regular behavior comment and preserves FP absent. | strong | Complete behavior reconstruction | Supervisor Gate 2B IDA-FA-02 | incorporate | proposed |
| [ ] | C-FA-042 | 0003FA | IDA-FA-03 adds the exact address-repeatable pooled-local comment and preserves AR absent. | strong | Exact physical/source provenance | Supervisor Gate 2B IDA-FA-03 | incorporate | proposed |
| [ ] | C-FA-043 | 0003FA | Function frame, type, bytes, xrefs, vtable cell, target/xref items, neighbors, and padding must remain protected unchanged through the supervisor-owned IDA handoff. | very-strong | Fresh complete prestates | Supervisor Gate 2B protections | already-present | proposed |
| [x] | C-FA-044 | 0003FA | Historical waiting/source-deferred prose is retained only as dated superseded history, never current state. | strong | Current blocker closure | Target/support Changes history | historicalize | verified |
| [x] | C-FA-045 | 0003FA | Standalone object emission, file-level physical ownership, target data rename/type, function retagging, and boundary redefinition are rejected. | strong | Source-shape and protection analysis | Target negative/recommendation sections | reject-invalid | verified |
| [ ] | C-FA-046 | 0001HD | Section 28 supplies the exact supervisor-owned replacement for stale manual `reconstructable : 82% : strong`: a no-loss `not_reconstructable : 88% : very-strong` row preserving function-map/raw-constructor/false-stub/resource/vtable/destructor/adjustor/boundary evidence and adding the non-emitting split/index plus dependency-closed OnPaint/UID0003FA child route. | very-strong | Physical current manual row compared with current UID0001HD `88/91`, `RECONSTRUCTABLE:FALSE`, blank emitter route, and complete child/evidence inventory | by-memory/-coverage-report.md exact supervisor-owned replacement | incorporate | proposed |
| [ ] | C-FA-047 | 0003Y6 | Section 28 supplies the exact supervisor-owned OnPaint manual insertion row. | very-strong | Exact function evidence and route | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C-FA-048 | 0003FA | Section 28 supplies the exact supervisor-owned target manual insertion row. | very-strong | Exact target evidence and route | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C-FA-049 | 00002X | Section 28 supplies one unified supervisor-owned `94% : very-strong` class row, including all four prior consumers, ten completed member bodies, UID0003FA local provenance, and UID00038U compiler coverage; ordinary prerequisites are physically satisfied, while manual insertion remains supervisor-owned. | very-strong | Complete merged class/source route plus validated body closure | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C-FA-050 | 0000IC | Section 28 supplies one unified supervisor-owned `94% : very-strong` file row, including both pooled-literal and local-rectangle routes plus `27/27/0` topology; ordinary/generated prerequisites are physically satisfied, while manual insertion remains supervisor-owned. | very-strong | Complete merged file/generated route plus waited physical readback | by-file/-coverage-report.md | incorporate | proposed |
| [x] | C-FA-051 | 0003FA | Dated command `24868` mechanically read `27/26/1`: ten registered children were nonempty only because their CPP channels held comments and UID00038U was empty. This observation does not prove authored source completion and is not continuing authority. | very-strong | Physical dated generated observation compared with current ordinary formal channels | Validator Results generated observation | already-present | verified |
| [x] | C-FA-052 | 0003FA | Coordinated callback receipts record every changed target/support page, no overlapping document was written concurrently, corrective waited owner refresh `24867` followed the discovered signature-marker closure, and physical reread covers `CollectionPane.cpp/.h`, `UserPane.cpp/.h`, `PaletteLib.cpp/.h`, and `MetaMan.cpp/.h`; latest waited readback remains dynamic authority. | very-strong | Three-report sequencing and dynamic generated-authority rule | Coordinated callback Validator Results/readback | incorporate | verified |
| [x] | C-FA-053 | 0003FA | Changed Files records this report plus the 26 validated ordinary destinations; peer reports, coverage, generated artifacts, IDA, and lifecycle state were read-only/directly unchanged. | very-strong | Changed-file audit | Changed Files | already-present | verified |
| [x] | C-FA-054 | 0003FA | The report has all 33 headings, exact 125-row ledger/checklist parity, 113 checked/12 unchecked allocation, no executable fences, and exactly one terminal execute-readiness workflow marker. | very-strong | Mechanical self-audit | Report hygiene | already-present | verified |
| [x] | C-FA-055 | 0003Y6 | The failed artifact's two-include OnPaint preamble is dated incomplete evidence and is superseded by the direct dependency preamble in Section 22. | very-strong | Formal-body symbol-to-header audit | UID0003Y6 history/formal CPP | historicalize | verified |
| [x] | C-FA-056 | 0003Y6 | The exact file-root OnPaint preamble directly includes `CollectionPane.h`, `UserPane.h`, `../../metadata/MetaMan.h`, `../../metadata/MetaTable.h`, `../../render/ImageLib.h`, `../../render/PaletteLib.h`, `../../render/Surface.h`, and `<cwchar>`. | very-strong | Exact body dependency inventory | UID0003Y6 formal CPP | incorporate | verified |
| [x] | C-FA-057 | 00006E/0000K2 | Current ordinary owner routes declare `ImageLib::LookupLayoutEntry` and `extern ImageLib *g_pEPFLib`; repair-time command-24737 `ImageLib.h` confirms that route, and OnPaint consumes it without an ImageLib edit. | very-strong | Current ordinary route plus repair-time generated observation | UID0003Y6 dependency evidence; UID00006E/0000K2 no edit | already-present | verified |
| [x] | C-FA-058 | 0000TN/0000OC | Current ordinary owner routes declare exact `SurfaceSpriteBlitProc` and `extern SurfaceSpriteBlitProc g_pfnBlitSprite`; repair-time command-24737 `Surface.h` confirms that route, and OnPaint consumes it without a Surface edit. | very-strong | Current ordinary route plus repair-time generated observation | UID0003Y6 dependency evidence; UID0000TN/0000OC no edit | already-present | verified |
| [x] | C-FA-059 | 0000A1 | Keep current `92/93`; executed B003 state already places the complete `LObject.h`/`Singleton.h`/`List.h`/`Palette.h`/class/helper payload in UID0000A1 H. Repair-time command-24737 `PaletteLib.h` confirms it. Verify and preserve it; B008 performs no PaletteLib write and rejects its dated guard/size-assertion addition. | very-strong | Current ordinary UID0000A1, repair-time generated observation, and executed B003 artifact | B003-owned UID0000A1 formal H and score, verify only | already-present | verified |
| [x] | C-FA-060 | 0000A1 | Preserve B003's exact class CPP payload `[[CHILDREN]]`; no include, class, struct, extern, or reduced local declaration is added by UID0000A1 itself. B008 performs no PaletteLib write. | very-strong | Exact B003 direct-owner formal CPP | B003-owned UID0000A1 formal CPP | already-present | verified |
| [x] | C-FA-061 | 0000RW | Preserve current UID0000RW CPP `PaletteLib *g_pPaletteLib = 0;` plus `[[CHILDREN]]` and current UID0000RW H `extern PaletteLib *g_pPaletteLib;`; repair-time command `24737` confirms exactly one generated extern and one storage definition. B008 performs no PaletteLib write, and the latest supervisor-verified waited readback controls callback verification. | very-strong | Current UID0000RW formal channels and repair-time generated one-definition observation | B003-owned UID0000RW formal disposition, verify only | already-present | verified |
| [x] | C-FA-062 | 000088 | Current `94/94` MetaMan formal H contains the complete accepted declaration, `<map>`, `Singleton.h`, complete `StringUtil.h`, `MetaTable` forward declaration, `extern MetaMan *g_pMetaMan`, and exact `0x14` size guard. | very-strong | B008 dependency audit plus B002 manager/MetaTable closure | UID000088 formal H and score | incorporate | verified |
| [x] | C-FA-063 | 000088 | MetaMan class CPP is exactly `#include "MetaMan.h"` plus `[[CHILDREN]]`; no class, extern, or reduced local declaration remains in CPP. | very-strong | Normal single-definition owner route | UID000088 formal CPP | incorporate | verified |
| [x] | C-FA-064 | 0000RL | Keep sole `MetaMan *g_pMetaMan = 0;` in the global CPP child, keep its H blank, and expose exactly one extern through UID000088 `MetaMan.h`. | very-strong | Existing global definition and one-declaration rule | UID0000RL formal disposition | incorporate | verified |
| [x] | C-FA-065 | 0000A1 | `PaletteLib::GetPaletteByName(const wchar_t *)` and `g_pPaletteLib` are declaration-visible through the current ordinary complete owner H route, which also makes `DLPalette` complete through `Palette.h`; repair-time command-`24737` `PaletteLib.h` confirms it and no Palette edit is required. | very-strong | Current ordinary route plus repair-time generated observation | UID0003Y6 dependency proof; Palette no change | already-present | verified |
| [x] | C-FA-066 | 000088 | `MetaMan::FindEntry(const SimpleUString *, const SimpleUString *, unsigned int)` and `g_pMetaMan` are declaration-visible through the complete `MetaMan.h`, which makes `SimpleUString` complete through `StringUtil.h`. | very-strong | Accepted class API and complete owner H route | UID0003Y6 dependency proof | incorporate | verified |
| [x] | C-FA-067 | 0003Y6 | `<cwchar>` is the project/MSVC declaration route for unqualified `swprintf_s` and `wcslen`; accepted UID00009A generated source uses the same include and spellings. | strong | Current project formal/generated precedent | UID0003Y6 dependency proof | incorporate | verified |
| [x] | C-FA-068 | 0003Y6 | `CollectionPane.h` reaches complete `EPFTileContext` through `PanelPane.h -> Pane.h -> GrafPort.h -> EPFTileContext.h`; `UserPane.h` plus corrected UID0001TZ supplies complete collection records, `PaletteLib.h` supplies complete `DLPalette`, and direct `MetaMan.h`/`MetaTable.h` supply complete manager/table APIs and `SimpleUString`. | very-strong | Physical include-chain and formal-header audit | UID0003Y6 dependency proof | incorporate | verified |
| [x] | C-FA-069 | 0003Y6 | Reduced local PaletteLib/MetaMan declarations, duplicate classes, local externs, and hand-written CRT prototypes are invalid and must not be used. | very-strong | Normal owner/header rule and ODR/type-completeness constraints | UID0003Y6 negative evidence | reject-invalid | verified |
| [x] | C-FA-070 | 0003FA/0003Y6 | Retain `94/95` and `92/94` only with expanded direct includes, complete service headers, B002's exact seven literal uses, and B008's exact one-context/two-buffer/two-rectangle/Data-Length body; B002's `92/93` confidence and MutableData/const-cast body are superseded for the shared method. | very-strong | Exact cross-report source/score comparison | Target/method score rationale | incorporate | verified |
| [x] | C-FA-071 | 0000IC/0000MB/0000LC | Repair-time command `000000024737` observation found CollectionPane `17/10/7`, PaletteLib `6/6/0` with complete H and no CPP-local class, and MetaMan `16/16/0` with class-in-CPP and no H; no fixed command is callback authority. | very-strong | Physical repair-time generated observation | Validator Results baseline | already-present | verified |
| [x] | C-FA-072 | 0003FA | Every previously changed ordinary page has an exact scoped receipt; discovery refresh `24849` exposed ten registered signature-only markers and validators `24857`-`24866` made their comment channels mechanically nonempty, while refresh `24867` records hashes/counts but does not prove authored bodies. | very-strong | Exact callback validator history separated from source-quality judgment | Callback Validator Results/readback history | incorporate | verified |
| [x] | C-FA-073 | 0000A1 | Current by-class manual UID0000A1 row is literally identical to Section 28's `92% : very-strong` complete-H/children-only-CPP text; no replacement or B008 Palette row is permitted. | very-strong | Literal current by-class row comparison | by-class/-coverage-report.md no change | already-present | verified |
| [x] | C-FA-074 | 0000MB | Retain the current `91% : very-strong` PaletteLib file row without replacement; executed B003 required no UID0000MB manual edit and B008 supplies none. | very-strong | Current manual row plus exact B003 coverage scope | by-file/-coverage-report.md no change | already-present | verified |
| [x] | C-FA-075 | 0000RW | Current by-global manual UID0000RW row is literally identical to Section 28's `92% : very-strong` sole-definition/owner-header extern text; no replacement or B008 Palette row is permitted. | very-strong | Literal current by-global row comparison | by-global/-coverage-report.md no change | already-present | verified |
| [ ] | C-FA-076 | 000088 | Section 28 supplies one unified supervisor-owned `94% : very-strong` complete-H/children-only-CPP/size-guard class row. | very-strong | Current row plus cross-report manager/MetaTable closure | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C-FA-077 | 0000LC | Section 28 supplies the exact supervisor-owned no-loss MetaMan header/source file-owner replacement. | very-strong | Current manual row plus corrected generated topology | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | C-FA-078 | 0000RL | Section 28 supplies the exact supervisor-owned replacement for stale `88% : strong` g_pMetaMan: current `89% : very-strong` owner-header extern/sole-definition text. | very-strong | Current ordinary `89/90` plus corrected declaration route | by-global/-coverage-report.md | incorporate | proposed |
| [x] | C-FA-079 | 00006E/0000K2/0000TN/0000OC | Existing ImageLib and Surface manual coverage already describes the complete header/global routes used here; no manual replacement is recommended. | very-strong | Current manual coverage and complete generated headers | ImageLib/Surface manual rows no change | already-present | verified |
| [x] | C-FA-080 | B002/B003 | Requested B002 `6FD8F4D4E2C4758188AD9B9D36801BABD45B5B0054D22C1A34C2BEB68EE594E6` and observed peers were reread at complete-report/delta depth. Exact executed B003 artifact `02E615F37ED6D37F6C6515AE0EACE4DF5384B3EA62B4D7ED655F5FFA7DCAED85`, 186956/1284, command `24694`, archived-audit passed, was reread in full and its Palette ordinary/generated/manual state physically matched. No moving whole-report hash is fixed callback authority. | very-strong | Physical peer/artifact reads, execution audit, and current row/file comparison | Cross-report evidence inventory | already-present | verified |
| [x] | C-FA-081 | 0003F1/0003FA | B002 remains direct owner of UID0003F1; B008 remains direct owner of UID0003FA. Neither report claims the other's target or target-specific marker. | very-strong | Exact target ranges and report identities | Cross-report ownership contract | incorporate | verified |
| [x] | C-FA-082 | 0003F1 | Preserve the exact eight-literal/two-alignment/14-use map: `Collections` 4, `GroupNames` 3, `CLTINV.EPF` 2, and `CLTLIST.EPF`, `CLTLIST.PAL`, escaped Korean fallback, `%d %%`, `%d/%d` one each across four methods. | very-strong | B002 exact bytes/xrefs/source-use matrix | Unified CollectionPane source evidence | incorporate | verified |
| [x] | C-FA-083 | 0003Y3/0003Y6/0003Y9/0003YG | Preserve all four B002 consumer closures, but use the unified UID0003Y6 body and scores selected here; no consumer detail is dropped merely because UID0003FA has one direct consumer. | very-strong | Full B002 consumer profiles plus B008 targeted OnPaint evidence | Shared method pages and formal source | incorporate | verified |
| [x] | C-FA-084 | 0003Y6 | Final OnPaint is `92/94`: B008 controls one initialized context, two exact 128-wide buffers, row/text rectangles, const Data/Length copy, direct includes, and rowBounds provenance; B002 contributes all seven literal uses, escaped Korean source spelling, and full render behavior. | very-strong | Exact stack/SSO/constant evidence plus B002 literal map | UID0003Y6 formal CPP/score | incorporate | verified |
| [x] | C-FA-085 | 00002X | Current CollectionPane is `94/94`: it retains `int m_groupCount`, exact guarded `0x10c` H and four-consumer closure, and now contains the ten formal member bodies, direct Event/Config includes, and ScrollCollectionPane friend support. | very-strong | Direct dword write, fresh ten-body evidence, B002 consumer closure, scoped validators, and source-valid access route | UID00002X formal CPP/H/score | incorporate | verified |
| [x] | C-FA-086 | 0000IC | Current CollectionPane file is `94/94`: one preamble/child aggregator, complete CollectionPane/CollectionPane2 H routes, all fourteen source-bearing consumer/member bodies, both pooled-data markers, UID0003FA marker, and compiler-covered UID00038U marker, with `27/27/0` and no empty emitter after waited readback. | very-strong | Complete cross-report source/generated inventory plus command-25070 physical readback | UID0000IC topology/score | incorporate | verified |
| [x] | C-FA-087 | 0001TZ | Final collection layout is `93/94`, blank CPP and complete H with StringUtil plus exact `0x4c`/`0x2604` guards; this single route serves UserPane, OnActivate, OnPaint, and the loader. | very-strong | Combined visibility/layout evidence | UID0001TZ formal CPP/H/score | incorporate | verified |
| [x] | C-FA-088 | 000088 | Final MetaMan is `94/94`, header-plus-children CPP and one guarded complete H with extern and `0x14` guard; B002's higher score is accepted because MetaTable and all four consumers are now closed. | very-strong | Combined owner/header/consumer evidence | UID000088 formal CPP/H/score | incorporate | verified |
| [x] | C-FA-089 | 000089 | Preserve B002's MetaTable `94/93` closure: children-only CPP, guarded complete H, accepted RowMap, Rows/IsMaterialized accessors, exact payload fields, and `0x24` guard. | strong | B002 materializer/layout/consumer evidence | UID000089 formal CPP/H/score | incorporate | verified |
| [x] | C-FA-090 | 0000A1 | Final PaletteLib remains current `92/93` under executed B003 ownership: UID0000A1 H has the complete class/helper payload, UID0000A1 CPP is children-only, UID0000RW H owns the extern, and UID0000RW CPP owns the sole definition plus children. B008's dated `93/94`/guard/size-assertion proposal is superseded and authorizes no PaletteLib write. | very-strong | Current ordinary/generated/manual state plus executed B003 artifact | B003-owned Palette formal/score state, verify only | already-present | verified |
| [x] | C-FA-091 | 0003Y3 | Preserve B002's `93/94` OnActivate body, exact four literal uses, packet-byte record initialization, metadata materialization, scroll refresh, invalidation, and raw-byte-helper exclusion. | very-strong | B002 body hash/profile/vtable/literal evidence | UID0003Y3 formal CPP/score | incorporate | verified |
| [x] | C-FA-092 | 0003Y9 | Preserve B002's `92/93` LoadCollectionGroupRecords closure, exact two `Collections` uses, RowMap traversal, `_wtol` field mapping, no collectedFlag write, matching count, and one-pointer member ABI; use const Data/Length instead of const-cast MutableData. | very-strong | B002 body/caller/row evidence plus B008 const API proof | UID0003Y9 formal CPP/score | incorporate | verified |
| [x] | C-FA-093 | 00002Y | Preserve B002's CollectionPane2 `94/95` complete PanelPane-derived `0xf8` H route and children-only CPP. | very-strong | Constructor/vtable/base/callback evidence | UID00002Y formal CPP/H/score | incorporate | verified |
| [x] | C-FA-094 | 0003YG | Preserve B002's CollectionPane2::OnPaint `94/95` body with one `CLTINV.EPF` use and exact typed `g_pfnBlitSprite` call against `m_visibleBounds`. | very-strong | Exact body/vtable/callback evidence | UID0003YG formal CPP/score | incorporate | verified |
| [x] | C-FA-095 | 0003F1 | Preserve B002's direct target recommendation `92/94`, exact four-line no-object marker, blank H, target coverage row, and repeated-expression source placement. | very-strong | Direct B002 target evidence | B002-owned UID0003F1 target/formal/manual route | already-present | verified |
| [x] | C-FA-096 | 0001HD | Keep broad index `88/91`, non-reconstructable/non-emitting, and use one merged no-loss row that includes the full function/helper/padding/vtable/destructor/adjustor/boundary inventory, all four literal consumers, and UID0003FA local provenance. | very-strong | Both reports' broad-range evidence | UID0001HD prose/manual row | incorporate | verified |
| [x] | C-FA-097 | 0000D9 | Preserve B008's inline const `Data()`/`Length()` additions and use them in both OnPaint and LoadCollectionGroupRecords; B002's const-cast MutableData expressions are superseded. | very-strong | Live SSO/count evidence and merged consumer needs | UID0000D9 H plus merged method bodies | incorporate | verified |
| [x] | C-FA-098 | 0003F1 | B002 exclusively owns data-comment D01-D08 at `0x00624a98`, `0x00624ab0`, `0x00624ac8`, `0x00624ae0`, `0x00624af8`, `0x00624b10`, `0x00624b18`, and `0x00624b24`, plus P01-P03; B008 performs none of those actions. | very-strong | Exact B002 Section 21 rows | Supervisor B002 IDA handoff | already-present | verified |
| [x] | C-FA-099 | 0003Y6/0003FA | B008 exclusively owns IDA-FA-01..03, including every mutation at function head `0x0056edc0`; B002's consumer investigation supplies source evidence only and authorizes no function mutation. | very-strong | Both reports' explicit IDA exclusions/actions | Supervisor B008 IDA handoff | already-present | verified |
| [x] | C-FA-100 | SHARED | No overlapping ordinary document was edited concurrently. B003 predecessor leases were clear, each B008 batch was leased/validated/released serially, and B002 may begin an overlapping write only after rereading the released validated B008 state. | very-strong | Three-report destination inventory and lease discipline | Callback sequencing contract | incorporate | verified |
| [x] | C-FA-101 | SHARED | B003 Palette state is verified/preserved and the accepted B008 UID0003FA/SimpleUString/unified OnPaint/shared implementation is physically validated. B002 remains direct UID0003F1 owner and later rereads validated B008 before any overlapping work. | very-strong | Executed predecessor status, direct-owner boundaries, and additive dependency closure | Callback sequencing contract | incorporate | verified |
| [x] | C-FA-102 | SHARED | B002 must reread and merge validated B008 ordinary/generated state while preserving executed B003 state before any later shared write. An active shared lease or loss of either predecessor payload is a hard stop until the supervisor supplies a replacement serialization contract. | very-strong | Deterministic no-loss cross-report requirement | Callback sequencing contract | incorporate | verified |
| [x] | C-FA-103 | 0000IC/0000MB/0000LC | Repair-time command `000000024737`, refreshed `2026-08-16T04:45:17-04:00`, observed CollectionPane `17/10/7`, PaletteLib `6/6/0` with complete H/no CPP-local class, and MetaMan `16/16/0` with no H; this dated observation is not permanent authority. | very-strong | Physical generated headers/hashes/counts at repair time | Validator Results observation | already-present | verified |
| [x] | C-FA-104 | 0000IC | Dated command `24868` mechanically observed `27/26/1`; ten child entries contained comments instead of source bodies and UID00038U remained empty, so the observation is not a source-completion receipt or continuing authority. | very-strong | Physical generated readback compared with ordinary formal channels | CollectionPane generated observation | already-present | verified |
| [x] | C-FA-105 | 0001TZ/000088/000089/0000A1 | Coordinated generated readback preserves executed-B003 PaletteLib complete H, children-only class CPP, one extern/one definition, and no duplicate/reduced declaration; it also proves complete UserPane collection layouts and one MetaMan/MetaTable H route with owner CPP children namespace-scoped. The latest supervisor-verified waited readback, not command-24867 or any earlier fixed receipt, controls later verification. | very-strong | Current B003 ordinary state plus completed unified formal topology and ordered ownership | UserPane/MetaMan/PaletteLib generated readback | incorporate | verified |
| [x] | C-FA-106 | MANUAL | Section 28 supplies one coordinated disposition per affected UID: current PaletteLib class/global rows compare literally equal and UID0000MB is same-or-greater no-change; B008 owns UID0003FA/support handoffs, and B002 owns UID0003F1/broader handoffs. No later pass duplicates an already-present Palette row. | very-strong | Exact current manual comparison and three-report ownership | Supervisor-owned manual coverage | incorporate | verified |
| [x] | C-FA-107 | MANUAL | Every later callback/coverage pass treats an identical predecessor row as already present and never inserts or replaces a competing payload for the same UID. | very-strong | One-row-per-UID three-report reconciliation rule | Supervisor-owned manual coverage sequencing | incorporate | verified |
| [x] | C-FA-108 | SCORES | Current shared scores are Y6 `92/94`, 02X `94/94`, 0IC `94/94`, 1TZ `93/94`, 088 `94/94`, 089 `94/93`, direct-owner 0A1 `92/93`, and 1HD `88/91`; 02X/0IC source-readiness is physically supported by the completed ten-body/UID00038U callback and waited `27/27/0` readback. | very-strong | Full overlap comparison plus validated body/compiler-data/generated closure | Score And Metadata Recommendation | incorporate | verified |
| [x] | C-FA-109 | 0003Y6 | B002's lower `92/93` score and formal body using const-cast MutableData, one loop-local aggregate text rectangle, and no copied SimpleUString are retained only as dated superseded proposals. | very-strong | Direct formal comparison with B008 stack/SSO evidence | Historicalized cross-report conflict | historicalize | verified |
| [x] | C-FA-110 | SHARED | B008's former lower 02X/file/MetaMan scores and isolated `17/13/4` projection, B002's conflicting field/signature/manual/generated variants, B008's dated higher PaletteLib `93/94`/guard/size-assertion proposal, command-24539 no-H baseline, and future-B003-first sequencing are superseded by unified rows and executed B003 `92/93` current state. | very-strong | Exact three-report claim/formal/score/generated/current-status comparison | Historicalized cross-report conflicts | historicalize | verified |
| [x] | C-FA-111 | 0003FA | The earlier accepted callback changed this B008 report and 26 exact ordinary destinations; this completion callback changes the same report plus the 14 exact ordinary destinations in Section 32. Peer reports, coverage, IDA, and lifecycle state were read-only/directly unchanged; generated changes were validator-owned side effects only. | very-strong | Changed-file audit | Changed Files | already-present | verified |
| [x] | C-FA-112 | 0003FA | The completed post-callback report retains 33 headings, exact 125-row ledger/checklist parity, 113 checked/12 unchecked allocation, no executable fences, lifecycle-neutral prose, and exactly one standalone terminal execute-readiness marker after the checklist. | very-strong | Mechanical final audit | Report hygiene/lifecycle neutrality | incorporate | verified |
| [x] | C-FA-113 | 0003Y4 | Current score is `92/94`; formal CPP is the complete `UpdateRenderRegion` body with retained local-bounds initialization, exact child bounds `{right-20,top+27,right-7,bottom-21}`, child SetBounds, Pane base update, and range refresh; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25057 | UID0003Y4 formal CPP/H/score | incorporate | verified |
| [x] | C-FA-114 | 0003Y5 | Current score is `93/94`; formal CPP is the complete `UpdateScrollRange` body with group snapshot, signed `0..30000` range/position clamps, exact child-state comparisons/setters, and first-visible write; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25058 | UID0003Y5 formal CPP/H/score | incorporate | verified |
| [x] | C-FA-115 | 0003Y7 | Current score is `92/94`; formal CPP is the exact key/text false-return override and formal H is blank/class-owned. | very-strong | Exact five-byte body, EventHandler slot, ordinary readback, and validator 25059 | UID0003Y7 formal CPP/H/score | incorporate | verified |
| [x] | C-FA-116 | 0003Y8 | Current score is `93/94`; formal CPP is the complete pointer/mouse body with input-lock gate, wheel clamp/update, configured single/double-click route, exact hit test/detail dispatch, child-local coordinate forwarding/restoration, and result return; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, event/config declarations, ordinary readback, and validator 25060 | UID0003Y8 formal CPP/H/score | incorporate | verified |
| [x] | C-FA-117 | 0003YA | Current score is `92/94`; formal CPP is the complete scroll-position callback with unused orientation, unchanged fast return, state synchronization, range refresh, and invalidation; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25061 | UID0003YA formal CPP/H/score | incorporate | verified |
| [x] | C-FA-118 | 0003YB | Current score is `92/94`; formal CPP is the complete AddToLayer override with Pane base call, child screen-bounds attachment, and range refresh; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact body hash, ordinary readback, and validator 25062 | UID0003YB formal CPP/H/score | incorporate | verified |
| [x] | C-FA-119 | 0003YC | Current score is `92/94`; formal CPP is the complete RemoveFromLayer override with child-first then Pane-base detach; formal H is blank/class-owned. | very-strong | Fresh bounded disassembly, exact body hash, ordinary readback, and validator 25063 | UID0003YC formal CPP/H/score | incorporate | verified |
| [x] | C-FA-120 | 0003YD | Current score is `90/92`; formal CPP is the complete bounded raw member body that ignores visibleSlot and writes four `-1` fields through InitRectBounds; formal H is blank/class-owned. | very-strong | Exact raw range, `retn 8`, bytes/hash, ordinary readback, and validator 25064 | UID0003YD formal CPP/H/score | incorporate | verified |
| [x] | C-FA-121 | 0003YE | Current score is `91/93`; formal CPP is the complete bounded raw member body that emits exact five-row `{6,14+50*n,161,62+50*n}` geometry or four `-1` fields; formal H is blank/class-owned. | very-strong | Exact raw range, unsigned branch, bytes/hash, ordinary readback, and validator 25065 | UID0003YE formal CPP/H/score | incorporate | verified |
| [x] | C-FA-122 | 0003YF | Current score is `92/94`; formal CPP is the complete five-slot y/x hit-test loop returning the slot or `-1`; formal H is blank/class-owned. | very-strong | Fresh bounded decompile/disassembly, exact hash, ordinary readback, and validator 25066 | UID0003YF formal CPP/H/score | incorporate | verified |
| [x] | C-FA-123 | 00038U | Current score is `94/95`; formal CPP is the exact inert compiler-covered marker and formal H is blank: the complete UID00002X virtual declaration and ordinary method definitions regenerate all three RTTI/COL/vtable views, destructor adjustors, and table words; hand-authored data is forbidden. | very-strong | Exact 140-byte model/hash, constructor stores, ordinary readback, and validator 25067 | UID00038U formal CPP/H/score | incorporate | verified |
| [x] | C-FA-124 | 00002X/0000CG | The CollectionPane file-root preamble now directly includes `../core/Event.h` and `../../config/Config.h`, and the existing complete ScrollCollectionPane H declaration now contains only the additive `friend class CollectionPane;`, preserving all layout and closing exact event/config names plus direct private child-state reads without invented accessors. | very-strong | Physical ordinary/generated header routes and validators 25068/25069 | UID00002X CPP and UID0000CG H support | incorporate | verified |
| [x] | C-FA-125 | 0000IC | Waited owner command `000000025070` physically shows each of the ten method bodies once, UID00038U's compiler-covered marker once, no affected empty/comment-only placeholder, and CollectionPane `27/27/0`; the latest supervisor-verified physical readback controls later verification. | very-strong | Complete formal inventory plus physical generated CPP/H scan | Generated CollectionPane.cpp/.h readback | incorporate | verified |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000025136","destination_path":"executed-b-agent-research/B008/0003FA-CollectionPaneRectConstant-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0003FA-CollectionPaneRectConstant-empty-emitter-source-quality.md","timestamp":"2026-08-16T10:34:32-04:00","uid":"0003FA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
