# B003 Research Report: UID0000L2 MapNamePane Whole-File Source Quality
** TARGET-REPORT-UID:0000L2 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

Removed legacy request material: [0000L2-MapNamePane-file-source-quality-removed.md](0000L2-MapNamePane-file-source-quality-removed.md). The companion is non-authoritative and must never be executed.

## Finalized Report / Current Recommendation

- Primary target: [UID:0000L2] `by-file/MapNamePane.md`.
- Declared target inventory: [UID:0000L2] `by-file/MapNamePane.md`, role `primary whole-file target`.
- Additional target UIDs: none. Every other UID in this report is a support destination or excluded neighboring item and does not receive independent target credit.
- Current physical target state after the accepted ordinary callback and Gate 2A remediation: completion `94`, confidence `95`, proposed path `NexusTK/map/`, canonical owner `FILE`, SHA256 `8034083E6694E0FBDA66D5E0C4B0DA3200249C6EAD9463589B1A0379AF543B31`, 24,796 bytes. Active line 21 now states unambiguously that `MapNamePane` remains the standalone `NexusTK/map/MapNamePane.cpp/.h` source unit and folding into `MapPane.cpp` is rejected. By-file pages do not support `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, `Nested`, or formal CPP/H metadata; those fields remain target-specific not applicable rather than blank evidence.
- Current recommendation: retain the now-documented standalone `NexusTK/map/MapNamePane.cpp/.h` source route, complete class/header and authored method formals, one global definition, and evidence-backed no-code dispositions for compiler glue, vtables, aggregate indexes, and source literals. Ordinary documentation implementation, authorized coherent generated refresh/readback, and supervisor-owned manual coverage application are complete; IDA and lifecycle work remain supervisor-owned.
- Exact source-bearing inventory: retained private glyph renderer `0x00503110-0x005031e1`; constructor `0x005031f0-0x005032c3`; ordinary destructor `0x005032d0-0x0050334d`; `OnPaint` `0x00503350-0x0050349f`; `HandlePacketEvent` `0x005034a0-0x00503574`; and global definition `g_pMapNamePane` at `0x0069b4b4`. The singleton construction-unwind clear helper, two deleting-destructor adjustor thunks, scalar deleting destructor, three vtables/RTTI, and literal data receive explicit compiler-covered or literal-in-source no-code handling.
- Dated validator command `000000023008` at `2026-08-12T22:25:26-04:00` is a coherent generated-output/readback snapshot, not permanent current authority. At that snapshot, `auto-generated/NexusTK/map/MapNamePane.cpp` was 5,170 bytes/150 lines at SHA256 `3E4DF33841609DED6B1B6CAD744FC56826D3F9DF00B7B2D9B912C514336F6584`, with the include/dependency shell, all five authored methods, both exact UID0003BZ/UID0003IL no-code comments, the singleton definition, and zero empty-emitter markers; `MapNamePane.h` was 1,118 bytes/41 lines at SHA256 `16029F044F645366CEC7FEE5CD76FCA467311BEE260313EA485F3FB555E8E915`, with the complete class/extern declaration. Generated semantics were unchanged at that dated snapshot. Every Gate must physically reread the generated CPP/H before treating those semantics or hashes as current.
- The accepted ordinary implementation callback and both Gate 2A remediation rounds are complete and physically revalidated. Commands `000000022991` and `000000022992` validate the exact standalone-placement and `Pane(1)` destination corrections after edit/release. B003 performed no IDA action, manual coverage edit, direct generated-file edit, or report lifecycle action. Historical validator command `000000022981` at `2026-08-12T20:09:34-04:00` performed the earlier authorized generated refresh; dated command `000000023008` is the later coherent generated/readback snapshot. Tracker truth is separate and lifecycle-sensitive: the supervisor must reread and hash the physical current generated tracker at every Gate and mandatory post-move audit rather than carrying either command's tracker receipt forward.

## Supporting Research

- Dated final-research IDA evidence: session `supervisor-uid000184-retry-20260812` was attested read-only at `2026-08-12T17:32:01.740420+00:00` against canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; listener PID 13936 and the returned worker/session matched at that observation, with no B003 mutation or save. The session and PID are transient historical evidence, not current authority. The earlier report-phase sessions `supervisor-uid00048A-persist-20260812` and `supervisor-uid000184-gate2b-20260812` had already retired and are historical only.
- Dated Gate 2B prestate reconciliation: public `runtime_attestation` at `2026-08-13T04:33:19.550204+00:00` bound canonical session `supervisor-uid0002OW-gate2b-20260813T0115Z` read-only. Its `_DWORD *` I0L2-03 and partial I0L2-10 observations are retained only as superseded historical evidence. No backup, mutation, or save occurred; this session/worker identity is dated evidence rather than permanent authority.
- Latest dated read-only IDA checkpoint: public `runtime_attestation` at `2026-08-13T11:42:43.912038+00:00` bound canonical session `supervisor-uid0004HB-gate2b-20260813T1105Z`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `53B60FCF7C42327C9E03D90A407903D4EFF15510FEE791F2452EF0B2036A05D9`, 143,206,875 bytes, listener PID 13936 and worker PID 2492. Health was `ok`; bounded item/function/type/comment/byte/xref/name-index queries all succeeded despite `auto_analysis_ready:false`. This checkpoint supersedes the affected I0L2-03/I0L2-05/I0L2-09-I0L2-12 prestates below; no mutation or save occurred, and the session/PIDs are dated evidence rather than permanent authority.
- Current by-* pages were reread after callback and scoped validation: UID0000L2, UID00007P, UID0002XC, UID0002XD, UID0002BF, UID0001AK, UID0001AL, UID0003XG-0003XM, UID0003BZ, UID0003IL, UID00044U, UID0000A2, UID00004L, UID00006E, UID00016G, UID0000SW, and their by-file owners.
- Matching prior research checked: executed B001 UID0001AK source-quality report, B001 UID0002BF raw-helper report, B012 UID0002XD singleton report, B015 UID00016G loader report, and related MapPane/MiniMap reports. Their valid facts are retained below; stale scores, stale historical IDA byte assumptions, incomplete formal-header decisions, and report-era generated state are not treated as current authority.
- Dated pre-callback generated source/header audit: `MapNamePane.h`, `Event.h`, and `DATFile.h` were absent; `render/ImageLib.h` contained only `extern bool g_imageLibraryLoadError;`; and `MapNamePane.cpp` contained the global, a shared-resource comment, and two empty markers. The initial scoped callback validators intentionally used `--no-generated-refresh`. During the authorized Gate 2A remediation, commands `000000022979`-`000000022981` corrected the Pane contract and both no-code emitters; historical command `000000022981 --wait-generated` at `2026-08-12T20:09:34-04:00` produced the then-current complete CPP/H readback. Dated command `000000023008` later recorded another coherent generated CPP/H snapshot with unchanged semantics. Neither command nor its tracker hash establishes later tracker truth; the current tracker must be reread physically at each Gate and mandatory post-move audit.
- Manual coverage closure is now physically verified: supervisor commands `000000022993`-`000000022996` applied the Section 28 by-file, by-class, by-global, and by-memory dispositions with exit `0`, `ok:1`, and generated refresh skipped. Section 28 retains the exact accepted handoff text as history; it is no longer a pending B003 request.
- No Wave2/Wave3 output or naming was used. No third-party embed applies: every body is NexusTK project code or compiler/literal support, so no `third_party_embeds/` directive is warranted.

## Target

| Target UID | Exact path | Role | Current score | Current owner/path | Formal metadata |
| --- | --- | --- | --- | --- | --- |
| 0000L2 | `by-file/MapNamePane.md` | Sole primary whole-file target | 94/95 | `CANONICAL_OWNER:FILE`; `NexusTK/map/` | By-file formal/owner-only schema; reconstructable/emitter/position/Nested/CPP/H fields are not applicable |

- Additional target UIDs: none.
- Assignment range is semantic whole-file ownership, not one contiguous binary interval. It includes all MapNamePane-authored definitions and file-level data routed to UID0000L2, plus every support declaration needed for complete generated CPP/H.
- The mixed physical island from `0x005031f0` through `0x0050395f` is not itself a source unit. Exact function starts, vtable identities, globals, resources, and class ownership separate MapNamePane from MiniMapButtonPane.

## Current Target State

- The physical file page now records the complete standalone map-module route, singleton, all authored and compiler-only methods, resources/data, exact gaps, ownership, source order, dependency closure, MiniMap exclusions, rejected alternatives, and historical corrections at `94/95`.
- UID00007P now owns complete guarded CPP/H formals at direct-file position 10; UID0002XC retains the sole global definition at position 20; UID0002BF and UID0003XG-0003XJ contain the accepted exact method CPP at child positions 10/20/30/40/50.
- UID0003XK is now compiler-generated, non-reconstructable, and non-emitting. UID0003XL/UID0003XM remain compiler no-code pages, while vtable/literal/covered-storage pages retain evidence without duplicate source bodies. UID0003BZ and UID0003IL now emit only exact explanatory no-code CPP comments; neither emits a vtable array, literal object, or H declaration.
- Pane, Event, ImageLib, and LoadDatFileBuffer visibility repairs are physically applied in the owning formal channels and documented in their by-file roots. UID0000SW remains the sole asset-mode definition/owner with MapNamePane recorded only as a source-root extern consumer.
- Historical validator command `000000022981` at `2026-08-12T20:09:34-04:00` completed the remediation refresh after both no-code emitter pages were registered. Dated command `000000023008` at `2026-08-12T22:25:26-04:00` recorded a later coherent generated CPP/H snapshot: complete `MapNamePane.cpp/.h` semantics, zero empty-emitter markers, exact UID0003BZ/UID0003IL explanatory comments, no duplicate compiler/literal definitions, and no MiniMap body. That dated generated snapshot remains evidence; current generated files require Gate-time physical reread, while tracker truth always comes from a separate current physical tracker reread/hash.

## Executive Recommendation

1. Retain the callback-completed UID0000L2 standalone `NexusTK/map/MapNamePane.cpp/.h` documentation route and its exact formal source.
2. Preserve UID00007P's complete H declaration and CPP include shell plus children at direct-file position 10.
3. Preserve UID0002XC as the one global definition at direct-file position 20 and UID0002XD as covered-by/no-duplicate storage evidence.
4. Preserve child positions 10/20/30/40/50 for UID0002BF and UID0003XG-UID0003XJ so class material precedes the global definition.
5. Preserve UID0003XK/UID0003XL/UID0003XM compiler no-code dispositions and UID0003BZ/UID0003IL/UID00044U declaration/literal evidence without duplicate source.
6. Preserve the applied Pane/Event/ImageLib/LoadDat header visibility repairs and source-root `extern bool g_useEpfAssets;` consumer route without ownership transfer.
7. Apply or reject the structured IDA actions only through the supervisor after fresh exact-artifact review; B003 remains read-only.

## Supervisor Active Recheck

- An exact-artifact Gate 1 matching this report's current path/hash always precedes independent Gate 2A; current gate truth is authoritative only from the external supervisor audit ledger.
- The accepted ordinary implementation callback reread every destination, preserved later valid drift, used JIT leases, validated each changed ordinary by-* page with generated refresh disabled, physically reread the results, and returned this same report for independent verification.
- Gate 2B remains supervisor-owned: runtime authority, exact current prestate, collision checks, backup/save/persisted readback, rollback/no-save on unlisted delta, and IDA catalog/audit work are external to this report.
- Manual `-coverage-report.md` changes remain supervisor-owned and are complete under commands `000000022993`-`000000022996`; report lifecycle remains supervisor-owned. Current truth is authoritative from physical Gate-time rereads and external supervisor/validator state, not B003 credit. Historical generated receipt `000000022981` and dated coherent generated/readback snapshot `000000023008` receive no direct/manual B003 generated-file edit credit. The latter's tracker SHA is only its dated snapshot; tracker truth must be reread from the current generated tracker at every Gate and mandatory post-move audit.
- B003 manually changed only the authorized ordinary by-* destinations and this same report. No manual coverage file, generated file, IDA database, goal, notes, audit, or lifecycle state was directly edited by B003. The required scoped validators updated validator-owned registry/reference/projected-stat/generated state as recorded in Section 31; those automatic tool side effects are not manual tracker edits.

## Inference Research Guidance Check

- Field/type/global/helper names were inferred from offsets, complete behavior, accepted neighboring style, and shared APIs rather than retaining `sub_`, `unk_`, or decompiler locals.
- Caller/reachability was checked for every authored/compiled function, singleton, vtable slot, and literal. The raw helper's absent inbound route is preserved as confidence-limiting negative evidence, not used to suppress its exact retained body.
- Ownership and source placement were tested against MapPane, MiniMapButtonPane, generic UI/text, and new-file alternatives.
- Exact ranges, internal padding, interleaving, compiler EH cleanup, adjustor thunks, scalar deleting destructor, vtables/RTTI, literals, and storage were classified separately.
- Final C++ is bounded to each exact source-bearing page. Aggregate indexes and compiler-generated items do not emit copied decompiler bodies.
- Source shape uses plausible mid-2000s C++: class inheritance and virtual overrides, constructor initializer, RAII members, explicit global, project allocator, Win32 conversion call, simple loops/rectangles, and compiler-generated ABI material omitted.

## Heuristic / Inference Reanalysis And Validation

### Standalone source file

- Positive evidence: dedicated class/RTTI/vtables, singleton, EPF resource, text buffer, glyph-table lifecycle, constructor callers, virtual paint/update methods, existing source-tree entry, and a complete narrow class family.
- Rejected alternative: fold into `MapPane.cpp`. The only MapPane edge is the external singleton read at `0x00504a43`; a consumer teardown read is weaker than the dedicated class/resource/vtable family.
- Resolution: standalone `NexusTK/map/MapNamePane.cpp/.h` is high probability.

### Private raw glyph helper

- Positive evidence: `this+0x220` is loaded by the constructor from `9X11FONT.BIN`, freed by both destructor lowerings, and consumed here as 99-byte 9x11 glyph records. The body exactly mirrors accepted UserStatusPane numeric glyph helpers: skip spaces/slashes, row formula, 9-pixel advance, and render callback.
- Negative evidence: no modeled IDA function, no inbound xref to start/end, and no VA/RVA/raw pointer hit was found in prior exhaustive checks; the current read-only session still has no xref to the start.
- Resolution: retained private member `DrawNumberGlyphString` with completion/confidence capped below directly called methods. The lack of a live call is not a reason to omit executable bytes or leave the emitter empty.

### Constructor and Singleton lowering

- The binary calls `Pane(this,1)`, publishes the Singleton pointer, installs three vptrs, initializes `EPFTileContext`, clears the first text character, and conditionally loads resources. Human source should use `Pane(1)` and `Singleton<MapNamePane>`; explicit vptr/publication/EH cleanup code is compiler output.
- The source must not initialize `m_mapNameGlyphs` unconditionally: the binary writes `this+0x220` only in the EPF branch. Preserving that historical behavior has higher priority than modern defensive cleanup.

### Destructor family

- `0x005032d0` is the authored ordinary destructor because it releases `m_mapNameGlyphs` through MemoryMan and chains base destruction.
- `0x005037f0` is reached only from constructor EH cleanup and only clears the Singleton slot.
- `0x0050380b`/`0x00503816` adjust secondary/tertiary receivers; `0x00503840` implements delete flags and operator delete. These regenerate from inheritance and `virtual ~MapNamePane()`.

### Packet handler

- The secondary vtable slot, `this-0xa0` adjustment, Event payload offset, opcode 0x15, packet offsets 9/10, 256-byte local, ACP conversion, 128-wide output, width 173 ellipsis, invalidation, and false return establish exact `bool MapNamePane::HandlePacketEvent(Event *)`.
- The 128-result terminator can reach the next member at `+0x1f8`; do not silently clamp to 127. Behavior fidelity requires preserving this original edge.

### Scores

- Every old file-level blocker was actively investigated: raw helper liveness, source split, field names/layout, Event/ImageLib/DATFile visibility, Pane constructor signature, global declaration, compiler wrappers, resource ownership, and generated ordering.
- Remaining uncertainty is limited to original private spelling and whether the retained uncalled helper survived from the same exact source revision. It justifies caps around 93-95, not the current 86/86 or blank source.

## Evidence Standards Used

- Direct evidence: canonical read-only IDA function/data/item/type/comment/xref/byte/decompile/disassembly results.
- Physical documentation evidence: current by-* metadata/formal channels, current generated CPP/H, exact hashes, current manual rows, and matching archived reports.
- Inference: source names, private/public placement, include arrangement, and human source shape. Each inference is tied to direct behavior and project naming conventions.
- Negative evidence: zero xrefs/pointer hits, absent type/name/header, mixed-island neighbors, and rejected owner candidates.
- No generated source, historical report, or decompiler label is treated as sole naming/ownership authority.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed: runtime attestation; all functions in `0x00503100-0x00503960`; item heads at raw helper, eight MapName starts, three vtables, resources, and singleton bytes; comments; stack frames; decompilation of constructor/destructor/paint/packet/scalar wrapper; full raw-helper instruction scan; bytes for MAPNAME.EPF, FRMPART.PAL, 9X11FONT.BIN, ellipsis, global neighborhood, and padding; xrefs for every file-owned function/data item; type layouts for Pane, EPFTileContext, RectBounds, Event, and Surface callback types.
- Latest bounded checkpoint checks additionally compared stored and decompiled declarations, exact name-index aliases, item spans/kinds/types/data flags, all applicable comment channels, bytes, xrefs, tail heads, neighbors, collision searches, and parser-visible types for I0L2-03/I0L2-05/I0L2-09-I0L2-13. It proved `EventHandler` is only a pointer-kind size-four type with no exact resolvable UDT, so the IDA packet-handler recommendation is narrowed to the physical `_WORD *` receiver rather than guessing an `EventHandler *` declaration.
- by-* docs, support docs, old reports, generated reports, and trackers checked: all target/support pages named in Sections 2 and 14; current generated MapNamePane.cpp and required header set; manual coverage; source-tree/MapPane/MiniMap boundary docs; matching executed B reports.
- Negative checks performed: no `MapNamePane` IDA UDT; no `g_pMapNamePane` IDA symbol; only one neighboring name at `0x0069b4b0`; no raw-helper inbound xref; no direct ordinary destructor caller; no direct paint/packet caller beyond vtables; no MapName ownership for eight MiniMapButtonPane functions; no need for a third-party import.
- Failed, unavailable, or intentionally skipped checks and why: a request against historical session `supervisor-uid00048A-persist-20260812`, and later the final attestation refresh against retired `supervisor-uid000184-gate2b-20260812`, returned `Session not found`; neither stale session was accepted as current evidence. Each time, `idb_list` plus fresh `runtime_attestation` selected the live canonical worker; the final `supervisor-uid000184-retry-20260812` reread reconfirmed all eight modeled starts, the complete 81-instruction raw helper, singleton fragments, resource fragments, bytes, and xrefs. Entity string search did not enumerate UTF-16 strings, so exact `get_bytes`, `get_string`, item, and xref evidence was used instead. No IDA mutation/save occurred; validators were prohibited only during the dated report-only phase and were later run during the accepted ordinary callback as recorded in Section 31.
- Whole-file completeness searches performed: all 16 modeled starts in the interleaved island were classified; the retained raw code and every gap were checked; globals, strings, three vtables/RTTI, class/type/layout, callers/callees/xrefs, every related by-* page, generated CPP/H, and matching reports were reconciled. No generic remaining-item bucket is used.

### Physical Support Artifact Receipt

The table below is the dated Gate-1-accepted pre-callback receipt. It remains historical evidence for the exact accepted baseline. Section 31 records dated post-callback and Gate 2A-remediation destination receipts plus separately dated read-only snapshots; none is permanent current authority, so every Gate must physically reread the relevant destinations and generated state.

| Physical artifact | SHA256 | Bytes |
| --- | --- | --- |
| `by-class/MapNamePane.md` | `35D97509E9EEDDE199BC903C5AAB7F707B1D6537342156EBD2C5D6B84DC49E1B` | 20617 |
| `by-global/g_pMapNamePane.md` | `F59B757213654ED7BB5BD0A08F66F26228F19351E30620F07531256ADA373668` | 5206 |
| `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md` | `BF5D6895D65B4BCA9F497696F5B477D1C3FE39514DFA65FB1518E80CE590E926` | 6300 |
| `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | `66F32C2F6D2D607AA598EFA0F45C040AD0B78FAEFED2D8395667102E7C4C6AD2` | 19049 |
| `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md` | `D3E59E736AD616D23B10A0AD2CAEA869A4895CFA6BD96F345FD866CF52046D67` | 4495 |
| `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md` | `BDE53257B33ABAFEF5C8CEC3F5C1C4CB586691001DDCB8CB85121C95E9C6E418` | 3970 |
| `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md` | `14B3505F85FF025000C0BEDC3BB2B0EA6846C26331F282053F38AA6C81DA8B67` | 4568 |
| `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md` | `7E0BEEB670AECEC1E62472C77EDD1C4D4648254F9164F23584B35CF04BA048E8` | 4811 |
| `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md` | `477E8BBD9B1D876BD5299945CA95EC95F1D94BE99790ED6FD755E3427E6E4D07` | 3145 |
| `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md` | `16A5200B3432F409468C0FA273AA95FB360F380BAC26681C41790068D834D301` | 3211 |
| `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md` | `6340597A4615E38B9D262624A05F001A1B4CDEF90B8349E0C7A097D9E0C3A7BE` | 3644 |
| `by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md` | `BEABF8B176E0C835D856F45BD9BBBDACE533890A0A1C1D8B721736DE95B8C6DA` | 3761 |
| `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md` | `9CAF0099CFCFE73DD7B5EF21CAA99997F946397E6196D3D1C0135BD41C23F3E1` | 3605 |
| `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` | `E7BDB6621F2280672C5768C0CDA6B55221AB75225C7968596E381B73E385877A` | 4641 |
| `by-memory/0x005031f0-0x005038fe.MapNamePane.md` | `2BA6498170A8D82B8645B6E0CED7B2DAF39C47A59BD389E8BC2539AD59304FE3` | 15108 |
| `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` | `C6B4F52736ACEA6B2BF57D17F4718AC07BEFCC4B51D2DC35AA3EE23767F18EA7` | 21621 |
| `by-class/Pane.md` | `445E2ACD469248D25C3965B8D6B22A1EC4BC45B803A9AD2672D47E017F54D1A5` | 32062 |
| `by-file/Pane.md` | `5FDB8C631192FEF427FA2BB133491557A487DA22A8AC0D1DF16F27CB65BE49AA` | 25609 |
| `by-class/Event.md` | `8C949A52AAF5D810407FDFFCDFDCE7397DF791E295E9C68D7301A4C4B1C93419` | 25015 |
| `by-file/Event.md` | `7F1D92CA5722925F8A575DEE15262822F6C937B3AE91B8D5A473D3E138BE6E91` | 24662 |
| `by-class/ImageLib.md` | `5CE72DD74DC55D7F0AF8C38CF5F294C1A627106B4BA6B57CB9C41D799880CFF4` | 20992 |
| `by-file/ImageLib.md` | `D240FF206FC3D97CDEF4B922032952F26144E43DD2ADAD1B0B1DD10D2F6E9214` | 28045 |
| `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md` | `2C2C6759727620E2752A4BCDB000A9F66F42321774C3A96E9FB090D60E0D58D5` | 13718 |
| `by-file/DATFile.md` | `50159ABA978A6AAC0B194B842619EDAA6D99B0077647F81524D3AE1D0712393E` | 16137 |
| `by-global/g_useEpfAssets.md` | `09DE791E1AC135DFFA10AE95EAE81814978C018EF606975CA85FE9AD5EEE06C3` | 24532 |
| `auto-generated/NexusTK/render/ImageLib.h` | `17F55471B71E42C0C73F67DB8FCAF355B052246FC17769F18EEBF0FB05F12282` | 453 |
| `auto-generated/NexusTK/render/GrafPort.h` | `5EA5CF7239F8D847C0E7BB81CDE2CD81FA31559EF15CAB50E9605F7434ED1769` | 4906 |
| `auto-generated/NexusTK/render/Surface.h` | `D5A5DA7F86C62051EBDB7E62788363320D75E5E5CD668D42B8C24174939E6391` | 3087 |
| `auto-generated/NexusTK/render/EPFTileContext.h` | `CF2297D5691977B196F01B549851713CDAA80AA8E620A6A36E2D859B69632B7F` | 1185 |
| `auto-generated/NexusTK/util/MemoryMan.h` | `20A4D4E82DA6416AD3139AC73F5A39560E8BBF653D6ED74A50621ADA4FAA82FB` | 966 |
| `auto-generated/NexusTK/ui/core/Pane.h` | `256BD0B9530CCEF1581D9EB78BCBA2A7D32A406DC95466189A0A19D905532577` | 2944 |
| `auto-generated/NexusTK/util/Singleton.h` | `0D034BDCA922A9F5BC6228253E298AC77D49C03FF7ABA4290F5D7CF6B0C641A8` | 558 |
| `auto-generated/NexusTK/ui/core/Event.h` | absent | 0 |
| `auto-generated/NexusTK/archive/DATFile.h` | absent | 0 |

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0L2-001 | 0000L2 | Incorporate the complete whole-file inventory, behavior, boundaries, ownership, source order, exclusions, dependency closure, and generated-state audit. | very-strong | Canonical MCP plus current docs/generated audit in Sections 10-16. | `by-file/MapNamePane.md` all substantive sections | incorporate | applied |
| C0L2-002 | 0000L2 | Retain standalone `NexusTK/map/MapNamePane.cpp/.h`; reject MapPane.cpp, MiniMap, and generic UI ownership. | strong | Physical line 21 now states the standalone route and rejection explicitly; command `000000022991`, SHA `8034083E...543B31`. | `by-file/MapNamePane.md` source placement | incorporate | applied |
| C0L2-003 | 0000L2 | Raise by-file score from 86/86 to 94/95; by-file-only metadata remains FILE and `NexusTK/map/`. | strong | All known blockers investigated; formal whole-file closure supplied. | `by-file/MapNamePane.md` header and score rationale | incorporate | applied |
| C0L2-004 | 0000L2 | Replace stale blank-C++ blocker prose with current implementation-ready CPP/H and dependency state. | very-strong | Dated pre-remediation output had empty markers; historical command `000000022981` first proved closure, and dated command `000000023008` recorded unchanged complete CPP/H with zero markers. Current generated semantics require Gate-time physical reread; tracker truth is separately reread dynamically. | `by-file/MapNamePane.md` status/changes | historicalize | applied |
| C0L2-005 | 0000L2 | UID00007P CPP becomes exact include shell plus `[[CHILDREN]]`; H becomes complete guarded MapNamePane declaration. | strong | Pane 0xf8 plus text 0x100 plus EPF 0x28 plus pointer 4 equals 0x224. | `by-class/MapNamePane.md` formal CPP/H | incorporate | applied |
| C0L2-006 | 0000L2 | Raise UID00007P 86/88 to 94/95; retain owner/emitter 0000L2 and reconstructable true; set direct-file position 10 so its include/class/method material precedes the global definition. | strong | Exact vtables, layout, source methods, and compile-safe source route. | `by-class/MapNamePane.md` metadata/score | incorporate | applied |
| C0L2-007 | 0000L2 | Preserve UID0002XC's one CPP definition and route the extern declaration through MapNamePane.h, not duplicate storage. | very-strong | Six singleton refs and one external MapPane read require non-static linkage. | `by-global/g_pMapNamePane.md` formal/source placement | incorporate | applied |
| C0L2-008 | 0000L2 | Raise UID0002XC 88/91 to 93/95; retain owner/emitter 0000L2 and set direct-file position 20 after UID00007P. | strong | Exact null bytes, xrefs, owner, definition, external linkage, and compile-safe class-before-global order. | `by-global/g_pMapNamePane.md` metadata/score | incorporate | applied |
| C0L2-009 | 0000L2 | Preserve UID0002XD as covered-by global storage, raise 88/91 to 93/95, retain owner/emitter 0002XC and Nested 4. | strong | Four fragmented current heads represent one four-byte pointer and six xrefs. | `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md` | incorporate | applied |
| C0L2-010 | 0000L2 | Emit private `DrawNumberGlyphString` exact body from UID0002BF and set class-child position 10. | strong | Complete 81-instruction body, 0x220 field lifecycle, accepted analogous helpers. | `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` formal CPP | incorporate | applied |
| C0L2-011 | 0000L2 | Raise UID0002BF 87/91 to 92/93; preserve owner/emitter 00007P, reconstructable true, Nested 0. | strong | Exact body/source role; no inbound xref caps confidence. | UID0002BF metadata/score | incorporate | applied |
| C0L2-012 | 0000L2 | Emit exact `MapNamePane::MapNamePane()` body from UID0003XG and set position 20. | very-strong | Two callers, three vptrs, exact fields/resources/branch. | `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md` formal CPP | incorporate | applied |
| C0L2-013 | 0000L2 | Raise UID0003XG 86/90 to 94/95; retain owner/emitter/reconstructable and Nested 8. | very-strong | Exact full-function behavior and direct callers. | UID0003XG metadata/score | incorporate | applied |
| C0L2-014 | 0000L2 | Emit exact ordinary `MapNamePane::~MapNamePane()` from UID0003XH and set position 30. | very-strong | Resource free and base-destructor route; compiler publication/base work excluded. | `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md` formal CPP | incorporate | applied |
| C0L2-015 | 0000L2 | Raise UID0003XH 86/90 to 93/95; retain owner/emitter/reconstructable and Nested 0. | strong | Exact full-function teardown; source cause proven by vtable wrappers. | UID0003XH metadata/score | incorporate | applied |
| C0L2-016 | 0000L2 | Emit exact `MapNamePane::OnPaint()` from UID0003XI and set position 40. | very-strong | Vtable slot and exact EPF/fallback drawing paths. | `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md` formal CPP | incorporate | applied |
| C0L2-017 | 0000L2 | Raise UID0003XI 86/89 to 94/95; retain owner/emitter/reconstructable and Nested 0. | very-strong | Full body, vtable identity, fields, resources, renderer APIs. | UID0003XI metadata/score | incorporate | applied |
| C0L2-018 | 0000L2 | Emit exact `bool MapNamePane::HandlePacketEvent(Event *)` from UID0003XJ and set position 50. | very-strong | Secondary vtable, Event payload, exact packet and conversion behavior. | `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md` formal CPP | incorporate | applied |
| C0L2-019 | 0000L2 | Raise UID0003XJ 87/90 to 94/95; retain owner/emitter/reconstructable and Nested 0. | very-strong | Exact ABI/packet path and vtable route. | UID0003XJ metadata/score | incorporate | applied |
| C0L2-020 | 0000L2 | Reclassify UID0003XK as compiler construction-unwind cleanup: reconstructable false, emitter blank, CPP/H blank, position blank. | very-strong | Sole xref 0x6020b1 from constructor EH path; body only clears Singleton. | `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md` | reject-stale | applied |
| C0L2-021 | 0000L2 | Raise UID0003XK 85/88 to 94/96 while preserving Nested 8 and documenting exact no-code proof. | very-strong | Complete compiler-role proof and exact range. | UID0003XK metadata/score/history | incorporate | applied |
| C0L2-022 | 0000L2 | Keep UID0003XL non-reconstructable/non-emitting; raise 85/90 to 94/97 and preserve both exact thunk adjustments. | very-strong | Vtable-only +0xa0/+0xa4 thunks jump to scalar wrapper. | `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md` | incorporate | applied |
| C0L2-023 | 0000L2 | Keep UID0003XM non-reconstructable/non-emitting; raise 86/90 to 94/96 and preserve delete-flag proof. | very-strong | Primary vtable plus thunk callers and operator-delete flag. | `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md` | incorporate | applied |
| C0L2-024 | 0000L2 | Keep UID0003BZ class-owned evidence with no standalone table/H definition; emit only the exact explanatory no-code CPP comment; raise 87/92 to 94/97. | very-strong | Three decorated vtables and RTTI regenerate from class inheritance/virtuals; command `000000022980` registered the comment-only formal. | `by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md` | incorporate | applied |
| C0L2-025 | 0000L2 | Keep UID0003IL as a constructor-covered literal with no standalone object/H definition; emit only the exact explanatory no-code CPP comment; raise 86/92 to 93/96. | very-strong | Exact UTF-16 bytes and sole constructor xref; historical command `000000022981` registered the comment-only formal, and dated command `000000023008` recorded the exact comment with no empty marker. Current generated state requires Gate-time physical reread. | `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md` | incorporate | applied |
| C0L2-026 | 0000L2 | Remove UID0000L2 from UID00044U emitter list; preserve shared ownerless evidence and other routes; MapName uses literal in OnPaint. | strong | Three consumers and no standalone string object in source. | `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` metadata/formal route | incorporate | applied |
| C0L2-027 | 0000L2 | Keep UID0001AK non-reconstructable/non-emitting split index; raise 88/91 to 94/96 and enumerate all exact children/gaps. | very-strong | Mixed methods/compiler glue/MiniMap holes cannot be one source block. | `by-memory/0x005031f0-0x005038fe.MapNamePane.md` | incorporate | applied |
| C0L2-028 | 0000L2 | Keep UID0001AL ownerless/non-reconstructable/non-emitting with current 86/92; add current complete exclusion inventory only. | very-strong | Sixteen starts split evenly by class families plus padding. | `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` | already-present | already-present |
| C0L2-029 | 0000L2 | Correct Pane H constructor declaration from `Pane()` to `explicit Pane(unsigned char mode)` and record MapNamePane's exact `Pane(1)` initializer; preserve complete layout/API. | very-strong | Generated `MapNamePane.cpp:53`; `by-file/Pane.md` command `000000022979`; corrected `by-class/Pane.md:311` command `000000022992`, SHA `48FB46E5...9330BA`. | `by-class/Pane.md` formal H and `by-file/Pane.md` contract note | incorporate | applied |
| C0L2-030 | 0000L2 | Move complete Event declarations from CPP to guarded Event.h; CPP becomes include plus children without changing behavior/metadata. | very-strong | Dated pre-callback H was absent; historical command `000000022981` first generated the complete header, and dated command `000000023008` recorded it at SHA `7A3257AD...D17A01`. Current generated state requires Gate-time physical reread. | `by-class/Event.md` formal CPP/H and `by-file/Event.md` physical-state note | incorporate | applied |
| C0L2-031 | 0000L2 | Move complete ImageLib declaration from CPP to guarded ImageLib.h; CPP becomes include plus children. | very-strong | Dated pre-callback H lacked the class; historical command `000000022981` first generated the complete header, and dated command `000000023008` recorded it at SHA `F2FE7740...B374D8`. Current generated state requires Gate-time physical reread. | `by-class/ImageLib.md` formal CPP/H and `by-file/ImageLib.md` | incorporate | applied |
| C0L2-032 | 0000L2 | Add exact `LoadDatFileBuffer` prototype to UID00016G H channel and document DATFile.h consumer route. | very-strong | Dated pre-callback H was absent; historical command `000000022981` first generated the exact prototype, and dated command `000000023008` recorded DATFile.h at SHA `1C729CF2...E69FEDA`. Current generated state requires Gate-time physical reread. | `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md` H and `by-file/DATFile.md` | incorporate | applied |
| C0L2-033 | 0000L2 | Use source-root `extern bool g_useEpfAssets;` in MapNamePane.cpp; preserve UID0000SW as sole definition/owner. | strong | Established MapPane convention and broad global with no neutral shared header. | UID00007P CPP shell; `by-global/g_useEpfAssets.md` no-change note | already-present | applied |
| C0L2-034 | 0000L2 | Reject UiAssetModeRect helper adoption and preserve those pages outside MapNamePane. | very-strong | No class-field/vtable/resource/caller ownership edge. | UID0000L2 negative evidence and UID0002BF exclusions | reject-invalid | excluded-with-reason |
| C0L2-035 | 0000L2 | Exclude all eight MiniMapButtonPane modeled starts and their data from MapNamePane source. | very-strong | Independent constructor/global/vtables/helpers and exact starts. | UID0000L2 boundaries; UID0001AK/UID0001AL | reject-invalid | excluded-with-reason |
| C0L2-036 | 0000L2 | IDA: define/name/type/comment the raw helper only after exact raw boundaries, MapNamePane type preconditions, and the complete raw physical frame matrix pass independent supervisor preflight; preserve every protected property and verify the exact expected readback. | strong | I0L2-01 exact 81-instruction prestate, EBP-relative matrix, declarative function/name/type/comment outcomes, and protected-state readbacks. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-037 | 0000L2 | IDA: rename/type/comment the constructor and rename only physical stack row `var_14` to `glyphDataSize` through the dedicated stack-variable action; protect every other frame row. | very-strong | I0L2-02 complete seven-row current/post matrix, four separate comment-channel prestates, exact intended deltas, and expected readbacks. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-038 | 0000L2 | IDA: rename/type/comment ordinary destructor while changing only the current stored ECX receiver type from `Pane *` to `MapNamePane *` after the UDT prerequisite passes and protecting all four physical frame rows. | very-strong | Latest canonical I0L2-03 stored and decompiled declaration is `void __thiscall(Pane *this)`; the earlier `_DWORD *` observation is historical. Three MapNamePane vptr writes, `+0x220` cleanup, singleton clear, `Pane__Destructor`, and the scalar wrapper justify the final derived receiver type. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-039 | 0000L2 | IDA: rename/type/comment OnPaint while changing only the ECX receiver type and preserving `length`, saved-register, and return-address rows. | very-strong | I0L2-04 complete current/post frame and comment-channel matrices plus vtable prestate. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-040 | 0000L2 | IDA: rename/comment the packet handler, narrow its return/argument metadata to `bool` and `Event *`, retain the exact physical `_WORD *` secondary-facet receiver, and rename only the three enumerated frame rows. | very-strong | I0L2-05 complete seven-row matrix; current `EventHandler` is pointer-kind size 4 with no exact UDT, so no `EventHandler *` receiver or declaration action is authorized. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-041 | 0000L2 | IDA: rename/comment construction-unwind clear helper without converting it to source-authored code; protect exact `void sub_5037F0(void)` declaration and one-row frame with no type/frame mutation. | very-strong | I0L2-06 exact declaration/frame/comments plus sole EH xref. | Supervisor Gate 2B IDA handoff | historicalize | proposed |
| C0L2-042 | 0000L2 | IDA: rename/comment two adjustor thunks and replace stale `Block` address comments while protecting each exact `_DWORD *__thiscall (...)(_DWORD *this, char arg1)` declaration and one-row frame. | very-strong | I0L2-07/I0L2-08 exact declarations, frames, comments, and +0xa0/+0xa4 jumps. | Supervisor Gate 2B IDA handoff | historicalize | proposed |
| C0L2-043 | 0000L2 | IDA: rename/comment scalar deleting destructor with deterministic no-change protection for `Pane *__thiscall sub_503840(Pane *Block, char)` and its complete five-row frame. | very-strong | Latest canonical I0L2-09 stored/decompiled declaration, exact frame, wrapper/deletion path, two thunk callers, and primary-vtable route. | Supervisor Gate 2B IDA handoff | historicalize | proposed |
| C0L2-044 | 0000L2 | IDA: materialize/name/type/comment one four-byte `g_pMapNamePane` item from four current one-byte heads whose stored name is blank; never treat Hex-Rays-generated `unk_69B4B4` as a resolvable old name. | very-strong | I0L2-10 exact blank name-index/item prestate, generated-only alias, four heads, types, bytes, refs, comment channels, tail/neighbor protections, and destination collision proof. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-045 | 0000L2 | IDA: consolidate/name/type/comment the fragmented MAPNAME.EPF literal; consume the exact `off_61E6C0`/blank/`aAmeEpf_0` item fragments and name-index alias `aMa_8`, while protecting exact bytes, xref, and neighbors. | very-strong | I0L2-11 exact spans plus stable reads `MA`, `P`, and `AME.EPF`; final readback requires one 24-byte `MAPNAME.EPF` item. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| C0L2-046 | 0000L2 | IDA: preserve FRMPART.PAL shared fragments/alias, bytes/xrefs, and all three vtable bases with no mutation. | very-strong | I0L2-12 protects display names `off_610FA4`/`aMpartPal`, alias `aFr_5`, stable reads `FR`/`MPART.PAL`; I0L2-13 protects exact decorated bases and key slots. | Supervisor Gate 2B IDA handoff | already-present | proposed |
| C0L2-047 | 0000L2 | Provide exact manual by-file coverage replacement for UID0000L2. | strong | Dated supervisor command `000000022993`, exit 0/ok 1/generated skipped, recorded post-command SHA `C3644FB199C7DE965A92AEA8FF02A581833670593B977E18AF5917FC87B6DC8F`. At this report repair, the current physical aggregate is SHA `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`, 169,241 bytes, after unrelated additive coverage work; the exact standalone UID0000L2 94% row remains present once. Future Gate authority requires a fresh physical reread. | `by-file/-coverage-report.md` supervisor-only | incorporate | applied |
| C0L2-048 | 0000L2 | Provide exact manual by-class coverage replacements for UID00007P and support declaration pages. | strong | Dated supervisor command `000000022994`, exit 0/ok 1/generated skipped, recorded post-command SHA `68BBB4638AE94068BCFE822C8CF0538B418A6DFD6F52A211FAC9B504B4C6DEEC`. At this report repair, the current physical aggregate is SHA `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`, 277,113 bytes, after unrelated additive coverage work; the exact UID00007P/UID0000A2/UID00004L/UID00006E rows remain present once each. Future Gate authority requires a fresh physical reread. | `by-class/-coverage-report.md` supervisor-only | incorporate | applied |
| C0L2-049 | 0000L2 | Provide exact manual by-global coverage replacement for UID0002XC. | strong | Supervisor command `000000022995`, exit 0/ok 1/generated skipped; physical SHA `B689A8B2...E91A9A` contains the 93% singleton row. | `by-global/-coverage-report.md` supervisor-only | incorporate | applied |
| C0L2-050 | 0000L2 | Provide exact manual by-memory replacement/insertion rows for raw/helper/method/compiler/vtable/resource/storage inventory. | strong | Dated supervisor command `000000022996`, exit 0/ok 1/generated skipped, recorded post-command SHA `BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C`. Read-only repair snapshot `2026-08-13T07:14:28-04:00`: SHA `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, 2,211,023 bytes/4,936 lines after unrelated accepted UID0004HB supervisor work; all sixteen C0L2 inventory UIDs remain present exactly once. This snapshot is not permanent authority and requires fresh Gate-time physical reread. | `by-memory/-coverage-report.md` supervisor-only | incorporate | applied |
| C0L2-051 | 0000L2 | Preserve UID0001AL manual row except exact current non-reconstructable wording; do not call it reconstructable. | very-strong | Supervisor command `000000022996`; current physical UID0001AL row says `non-reconstructable` and retains ownerless mixed-index evidence. | `by-memory/-coverage-report.md` UID0001AL | reject-stale | applied |
| C0L2-052 | 0000L2 | Correct UID00029X/UID0002XD manual historical 0xffffffff wording to current zero/null storage. | very-strong | Supervisor command `000000022996`; current physical rows state zero/null and retain the former 0xffffffff interpretation only as superseded history. | `by-memory/-coverage-report.md` global cluster rows | reject-stale | applied |
| C0L2-053 | 0000L2 | Validate every changed ordinary by-* destination: initial callback pages use scoped `--no-generated-refresh`; Gate 2A remediation uses historical commands `000000022979`-`000000022981` plus exact follow-up commands `000000022991`-`000000022992`. | very-strong | All ordinary/remediation receipts remain historical in Section 31. Dated command `000000023008` is a later generated/readback snapshot, not permanent tracker authority; the current tracker must be reread and hashed at every Gate and mandatory post-move audit. | Report Validator Results and callback receipts | incorporate | applied |
| C0L2-054 | 0000L2 | Complete one coherent validator-owned generated refresh and physically verify complete MapNamePane.cpp and MapNamePane.h with zero empty-emitter markers. | very-strong | Dated command `000000023008` snapshot: CPP SHA `3E4DF338...F6584`, H SHA `16029F04...E915`; exact methods, comments, class/extern declaration, and zero markers were physically reread with semantics unchanged. Current generated state requires fresh Gate-time physical reread. | Validator-generated `auto-generated/NexusTK/map/MapNamePane.cpp/.h` readback | incorporate | applied |
| C0L2-055 | 0000L2 | Preserve all corrected historical assumptions and rejected alternatives rather than pruning them. | very-strong | Rule 26 no-loss standard. | Every affected target/support history section | incorporate | applied |
| C0L2-057 | 0000L2 | Preserve the shared `L"..."` item `[0x61066c,0x610674)` as exact `HandlePacketEvent` source-use evidence while rejecting a standalone MapName definition, ownership transfer, emitter route, or additional target declaration. | very-strong | Eight exact UTF-16LE bytes, one `const wchar_t[]` item, 23 head xrefs, no interior xrefs, and MapName operand `0x503531` before `GrafPort::FitTextAndAppendSuffix`; the formal CPP already uses the literal. | `by-file/MapNamePane.md` whole-file resource/xref/packet-behavior inventory | incorporate | applied |

## Positive Evidence Summary

- The class identity is direct: three decorated MapNamePane vtables, RTTI/type descriptors, exact vtable slots, three vptr writes, 0x224 scalar-delete guard, and two constructor callers.
- The file identity is direct-to-strong: a cohesive map overlay class, singleton, own EPF resource, map-name text, glyph resource lifecycle, and map-only behavior all route to the documented standalone map path.
- The authored behavior is complete: raw glyph rendering, construction, destruction, paint, and packet update are all bounded and behaviorally reconstructed.
- The dependency chain is closed with current accepted APIs: Pane/GrafPort/EPFTileContext/Surface/MemoryMan are generated; Event/ImageLib/LoadDatFileBuffer declarations exist in source docs and only need correct H-channel placement.
- Strongest inference chain: binary class identity + exact source-bearing bodies + dedicated resources/global + source-tree precedent + independent neighboring MiniMap identity yields a much higher probability of standalone `MapNamePane.cpp/.h` than any competing source shape.

## IDA MCP Facts

- Function/range facts: eight MapName starts are `0x5031f0` size `0xd3`, `0x5032d0` size `0x7d`, `0x503350` size `0x14f`, `0x5034a0` size `0xd4`, `0x5037f0` size `0xb`, `0x50380b` size `0xb`, `0x503816` size `0xb`, and `0x503840` size `0xbe`. Raw code `0x503110-0x5031e1` has 81 instructions, no function object, `retn 0x10` at `0x5031de`, then 15 `0xcc` bytes to the constructor.
- Ordinary-destructor type fact: the older `supervisor-uid0002OW-gate2b-20260813T0115Z` checkpoint reported stored `_DWORD *` and decompiled `Pane *`; that discrepancy is superseded historical evidence. Latest canonical session `supervisor-uid0004HB-gate2b-20260813T1105Z` reads both stored and decompiled declaration at `0x5032d0` as `void __thiscall(Pane *this)`. The proposed final `MapNamePane *` remains justified by writes of decorated MapNamePane vtables at `+0`, `+0xa0`, and `+0xa4`, the unique `+0x220` glyph-buffer cleanup, singleton clear, base-destructor call, and the scalar wrapper's matching teardown plus `0x224` delete-size guard. `MapNamePane` itself remains absent from current IDA, so its exact analysis-only UDT must be declared and read back before the receiver type may change.
- Data/table/padding facts: vtable bases `0x61e5b4`, `0x61e600`, `0x61e630`; MAPNAME.EPF exact UTF-16 bytes at `0x61e6c0`; FRMPART.PAL at `0x610fa4`; 9X11FONT.BIN at `0x61682c`; the ellipsis is one eight-byte `const wchar_t[]` item `[0x61066c,0x610674)` named `asc_61066C`, with exact bytes `2e 00 2e 00 2e 00 00 00`, decoded value `L"..."`, blank regular/repeatable address comments, and 23 xrefs to the head; singleton bytes at `0x69b4b4-0x69b4b8` are zero.
- Xref facts: constructor calls at `0x4f8051` and `0x4f8695`; paint and handler vtable refs at `0x61e5f8` and `0x61e610`; clear helper sole code xref `0x6020b1`; thunks at vtable heads `0x61e600` and `0x61e630`; scalar wrapper from both thunks and `0x61e5b4`; MAPNAME one constructor ref; FRMPART three consumers; singleton six refs.
- Vtable/global/type facts: no current `MapNamePane` UDT and no resolvable `g_pMapNamePane` name. At `0x69b4b4`, the stored item/name-index name is blank; the one-byte head is typed `Pane *`, non-code/non-data, and three more blank one-byte heads follow. `unk_69B4B4` is generated only by Hex-Rays and is not an old name that a data rename can resolve. All four bytes are zero, refs are `6/0/0/0`, all target comment channels are blank, and the protected next head at `0x69b4b8` remains separate and typed `Pane *`. Pane size is `0xf8`, EPFTileContext `0x28`, RectBounds `0x10`, and Event `0x110`. `EventHandler` resolves only as a pointer-kind size-four type; no exact `EventHandler` UDT resolves, so no `EventHandler *` IDA receiver is proposed. `MAPNAME.EPF` is physically fragmented as `[0x61e6c0,0x61e6c4)` display `off_61E6C0`/name-index alias `aMa_8`, blank `[0x61e6c4,0x61e6c8)`, and `[0x61e6c8,0x61e6d8)` `aAmeEpf_0`; stable reads are `MA`, `P`, and `AME.EPF`. `FRMPART.PAL` is fragmented as `[0x610fa4,0x610fa8)` display `off_610FA4`/name-index alias `aFr_5` and `[0x610fa8,0x610fbc)` `aMpartPal`; stable reads are `FR` and `MPART.PAL`.
- Negative IDA facts: all source functions retain `sub_` names; function comments are blank; raw helper has no inbound xref; ordinary destructor has no direct xref; current thunk entry regular comments are the stale literal `Block`; MiniMap starts at `0x503580` and owns eight distinct functions inside the island.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| Semantic source file | UID0000L2 `by-file/MapNamePane.md` | Whole-file owner | By-file N/A | FILE | 86/86 -> 94/95 | Complete report; formal source through children |
| Class/type/header | UID00007P `by-class/MapNamePane.md` | Class, layout, CPP/H shell | TRUE | 0000L2 | 86/88 -> 94/95 | Complete H plus CPP children shell |
| `0x503110-0x5031e1` | UID0002BF raw helper | Private 9x11 glyph renderer | TRUE | 00007P | 87/91 -> 92/93 | Emit exact method; no caller caps confidence |
| `0x5031e1-0x5031f0` | UID0002BF boundary | 15-byte alignment | FALSE | 0002BF | covered | No C++ |
| `0x5031f0-0x5032c3` | UID0003XG | Constructor | TRUE | 00007P | 86/90 -> 94/95 | Emit exact body |
| `0x5032c3-0x5032d0` | UID0001AK parent gap | 13-byte alignment | FALSE | 0001AK | covered | No C++ |
| `0x5032d0-0x50334d` | UID0003XH | Ordinary destructor | TRUE | 00007P | 86/90 -> 93/95 | Emit exact body |
| `0x50334d-0x503350` | UID0001AK parent gap | 3-byte alignment | FALSE | 0001AK | covered | No C++ |
| `0x503350-0x50349f` | UID0003XI | OnPaint | TRUE | 00007P | 86/89 -> 94/95 | Emit exact body |
| `0x50349f-0x5034a0` | UID0001AK parent gap | 1-byte boundary | FALSE | 0001AK | covered | No C++ |
| `0x5034a0-0x503574` | UID0003XJ | HandlePacketEvent | TRUE | 00007P | 87/90 -> 94/95 | Emit exact body |
| `0x503574-0x503580` | UID0001AK parent gap | 12-byte alignment | FALSE | 0001AK | covered | No C++ |
| `0x503580-0x50361e` | MiniMapButtonPane constructor | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x503620-0x503649` | MiniMap cleanup UID0001AM | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x503650-0x503692` | MiniMap paint | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x5036a0-0x5037ed` | MiniMap mouse/event body | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x5037f0-0x5037fb` | UID0003XK | Constructor-unwind Singleton clear | FALSE proposed | 00007P | 85/88 -> 94/96 | Compiler-covered no-code |
| `0x5037fb-0x503800` | UID0001AK gap | Alignment | FALSE | 0001AK | covered | No C++ |
| `0x503800-0x50380b` | MiniMap clear UID00040L | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x50380b-0x503816` | UID0003XL part 1 | EventHandler deleting-dtor adjustor | FALSE | 00007P | 85/90 -> 94/97 | Compiler-covered no-code |
| `0x503816-0x503821` | UID0003XL part 2 | TimerHandler deleting-dtor adjustor | FALSE | 00007P | 85/90 -> 94/97 | Compiler-covered no-code |
| `0x503821-0x50382c` | MiniMap thunk | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x50382c-0x503837` | MiniMap thunk | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x503837-0x503840` | UID0001AK parent gap | Alignment | FALSE | 0001AK | covered | No C++ |
| `0x503840-0x5038fe` | UID0003XM | Scalar deleting destructor | FALSE | 00007P | 86/90 -> 94/96 | Compiler-covered no-code |
| `0x5038fe-0x503900` | UID0001AK boundary | Alignment | FALSE | 0001AK | covered | No C++ |
| `0x503900-0x50395f` | MiniMap scalar deleting destructor | Neighbor exclusion | N/A | 00008B | existing | Exclude |
| `0x61e5b4-0x61e63c` | UID0003BZ | Three vtables/RTTI route | compiler-derived | 00007P | 87/92 -> 94/97 | Declaration-generated; explanatory no-code CPP comment only, no table/H definition |
| `0x61e6c0-0x61e6d8` | UID0003IL | MAPNAME.EPF literal | literal-in-constructor | 00007P | 86/92 -> 93/96 | Explanatory no-code CPP comment only, no standalone object/H definition |
| `0x610fa4-0x610fbc` | UID00044U | Shared FRMPART.PAL literal | source-use only | NONE | 89/93 unchanged | Drop only MapName comment emitter |
| `0x69b4b4-0x69b4b8` | UID0002XC/UID0002XD | External singleton definition/storage | TRUE/covered | 0000L2/0002XC | 88/91 -> 93/95 | One CPP definition, extern in class H |
| `9X11FONT.BIN` at `0x61682c` | shared resource data | Constructor literal | literal-in-constructor | shared | support | No standalone MapName object |
| `0x61066c-0x610674` `L"..."` | shared read-only literal inside UID0003FP/UID0003AS/UID00024R physical containers | `HandlePacketEvent` truncation suffix and 22 other broad UI uses | source-use only | shared; not MapName-owned | support/no score change | Exact callsite literal in formal CPP; no standalone MapName definition, owner transfer, emitter, or additional target UID |
| Pane declaration | UID0000A2 | Complete base and mode ctor | TRUE | 0000MC | 92/94 unchanged | Correct one H declaration |
| Event declaration | UID00004L | Complete packet Event type | TRUE | 0000J6 | 94/95 unchanged | Move exact declaration CPP -> H |
| ImageLib declaration | UID00006E | `g_pEPFLib` and lookup API | TRUE | 0000K2 | 89/90 unchanged | Move exact declaration CPP -> H |
| LoadDatFileBuffer declaration | UID00016G | Glyph resource loader API | TRUE | 0000IN | 88/92 unchanged | Add exact H declaration |

- Total modeled starts in mixed island: 16, of which eight are MapName compiler/source family and eight are MiniMapButtonPane. One additional unmodeled raw MapName helper is retained.
- Source-bearing rows: five MapName member definitions plus one global definition and one class header. Compiler/literal/evidence rows: clear helper, two thunks, scalar wrapper, vtables/RTTI, four resource literals, padding, and storage-covered-by.
- Historical pre-refresh readback was global-only with class/raw empty markers, no methods, and no MapNamePane.h. Historical command `000000022981` at `2026-08-12T20:09:34-04:00` first produced the complete output. Dated command `000000023008` at `2026-08-12T22:25:26-04:00` recorded the complete global plus five methods and complete header, with exact UID0003BZ/UID0003IL explanatory comments, zero empty-emitter markers, no standalone compiler/vtable/resource definition, and no MiniMap body; generated semantics were unchanged at that snapshot. Current generated CPP/H must be physically reread at each Gate, and current tracker truth must be separately reread/hashed at every Gate and mandatory post-move audit.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x503110` raw helper | No inbound xref; internal fallthrough xrefs only; calls EPFTileContext init, InitRectBounds, g_pfnBlitSprite, OffsetRect, security cookie | Retained private exact body, liveness unproven |
| `0x5031f0` constructor | Calls from `MainMenuPane_InitializeMainUiGraph` at `0x4f8051`, `0x4f8695`; calls Pane ctor, EPF init, lookup, LoadDatFileBuffer | Two layout construction sites |
| `0x5032d0` destructor | No direct inbound xref; calls GetMemoryMan, FreeBufferMemory, Pane destructor | Ordinary source destructor reached through compiled destructor family |
| `0x503350` OnPaint | Vtable data xref `0x61e5f8`; calls GetMemoryMan, RenderTileFrame, text APIs, g_pfnFillRect | Virtual paint route |
| `0x5034a0` HandlePacketEvent | Vtable data xref `0x61e610`; calls GetMemoryMan/MemmoveWrapper, MultiByteToWideChar, FitTextAndAppendSuffix, InvalidateRect | Secondary EventHandler virtual |
| `0x5037f0` clear | Sole code xref `0x6020b1` associated with constructor | Construction-unwind Singleton cleanup |
| `0x50380b` thunk | Vtable xref `0x61e600`; jumps to scalar wrapper after -0xa0 | Compiler EventHandler-view destructor thunk |
| `0x503816` thunk | Vtable xref `0x61e630`; jumps to scalar wrapper after -0xa4 | Compiler TimerHandler-view destructor thunk |
| `0x503840` scalar wrapper | Thunk calls at `0x503811`/`0x50381c`; vtable xref `0x61e5b4`; calls delete wrapper | Compiler deleting destructor |
| `0x69b4b4` singleton | Writes `0x50323b`, `0x503242`, `0x50332e`, `0x5037f0`, `0x5038a5`; read `0x504a43` | Publish/clear lifecycle plus external MapPane consumer |
| `0x61e6c0` MAPNAME.EPF | One data xref `0x50328d` | Constructor-owned source literal |
| `0x610fa4` FRMPART.PAL | Refs `0x461683`, `0x503375`, `0x503678` | Shared FrameChrome/MapName/MiniMap palette literal |
| `0x61682c` 9X11FONT.BIN | MapName operand at `0x5032a0` among shared UI consumers | Shared constructor literal, not file-static ownership proof |
| `0x61066c` `L"..."` | 23 head xrefs total; MapName source use is operand `0x503531` in `sub_5034A0`, immediately before the four-argument call at `0x503547` to documented `GrafPort::FitTextAndAppendSuffix`; no interior xrefs at `0x61066d-0x610673` | Shared suffix literal passed by `MapNamePane::HandlePacketEvent(m_mapNameText, 128, L"...", 173)`; source-use evidence only, with no standalone MapName data definition or ownership transfer |
| vtable bases | Constructor/destructor/scalar writes; slots point to paint/handler/thunks/wrapper | Exact inheritance and virtual declaration evidence |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: UID0000L2's standalone route; UID00007P's layout/vtable behavior; exact children UID0003XG-0003XM; UID0002BF raw algorithm; UID0002XC/2XD singleton linkage; UID0001AK/1AL split boundary; UID0003BZ/3IL/44U data; Pane/Event/ImageLib/LoadDat APIs; proposed source tree.
- Ordinary documentation defects repaired by this callback: final-C++ blocked/blank wording, UID0003XK source-helper classification, blank class/method formals, misplaced Event/ImageLib declarations, absent DATFile declaration route, Pane H's no-argument constructor, shared palette emitter routing, and incomplete target/support behavior/history.
- Current IDA handoff in Section 21 is reconciled to the latest dated canonical read-only checkpoint, including the corrected `Pane *` destructor/scalar-wrapper prestates, narrowed `_WORD *` packet-handler receiver, blank stored singleton name, and exact resource aliases/split reads. B003 performed no mutation or save. C0L2-036 through C0L2-046 remain supervisor-owned and proposed until separately verified against a fresh live prestate.
- Dated coherent generated/readback snapshot `000000023008` at `2026-08-12T22:25:26-04:00` recorded: `MapNamePane.cpp` SHA `3E4DF33841609DED6B1B6CAD744FC56826D3F9DF00B7B2D9B912C514336F6584`, 5,170 bytes/150 lines; `MapNamePane.h` SHA `16029F044F645366CEC7FEE5CD76FCA467311BEE260313EA485F3FB555E8E915`, 1,118 bytes/41 lines; `Event.h` SHA `7A3257AD63CAC26E7690D194EE22C1238769D27AC20444F9C3946B0F56D17A01`; `DATFile.h` SHA `1C729CF2E9F8688649D5EAE525F3604C05F444188DB6DFE2705ACBB03E69FEDA`; `ImageLib.h` SHA `F2FE77400C19E5BCF81C4B9CF0C609C717E404B9DC78040A7B0307199EB374D8`; and `Pane.h` SHA `CD291602A94C3C81E6ACBA4F3AFF30123F970B75D495ABD6E2C4505A25340F48`. Physical reread at that time confirmed unchanged generated semantics: both no-code comments and zero empty markers, all five methods and the singleton definition, and the complete class/extern/header dependency surface. The same command recorded tracker SHA `89076FBF0DE4566C1E77546B9FA32D4B6105AEB52888AC30815B98884A082DFD`, 2,048,815 bytes/9,629 lines, but that tracker identity is only a dated snapshot and never permanent current authority. Each Gate and mandatory post-move audit must separately reread current generated CPP/H and reread/hash the live generated tracker. Supervisor commands `000000022993`-`000000022996` separately completed and validated the manual coverage dispositions without B003 editing any coverage file.

## Ranked Ownership Analysis

### 1. Standalone MapNamePane.cpp/.h under UID0000L2

- Evidence for: dedicated class, global, three vtables/RTTI, resource literals, text/glyph state, complete lifecycle, two virtual methods, and existing map source-tree route.
- Evidence against: physical methods are interleaved with MiniMapButtonPane and one raw helper has no inbound xref.
- Decision: accepted. Exact child pages solve interleaving; lack of helper liveness caps only that helper.

### 2. Private MapNamePane implementation folded into MapPane.cpp

- Evidence for: same map UI graph and MapPane reads `g_pMapNamePane` during teardown.
- Evidence against: no constructor/method/vtable ownership edge; dedicated file/class/global/resources already form a narrow source unit.
- Decision: rejected as less probable. Consumer reads do not transfer implementation ownership.

### 3. MiniMap.cpp or generic UI/text module

- Evidence for: adjacent/interleaved MiniMap functions and shared palette/glyph conventions.
- Evidence against: MiniMap has separate singleton/vtables/callers; generic helpers do not own MapName-specific resource, buffer, or packet handler.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new ownership page; materialize sibling `NexusTK/map/MapNamePane.h` through existing UID00007P H channel.
- Likely full contents: complete class declaration, global extern, five member definitions, and one global definition.
- Candidate related items that belong: UID0002BF, UID0003XG-XJ, UID0002XC/2XD, and evidence-only UID0003XK-3XM/3BZ/3IL/44U.
- Candidate related items rejected: UID0002BD/2BE, all MiniMapButtonPane functions/data, and mixed parent aggregates as direct emitters.
- Standalone, narrow, or broad source-file inference: narrow standalone class source/header.

## Source Placement

- Recommended source file/class/global/module placement: `NexusTK/map/MapNamePane.cpp` and `MapNamePane.h`; class UID00007P owns declaration and method child expansion; global UID0002XC owns one external definition.
- Compile-safe direct-file source order: UID00007P class/include/method shell position 10; UID0002XC global definition position 20. Beneath UID00007P, UID0002BF/3XG/3XH/3XI/3XJ retain child positions 10/20/30/40/50. This emits `#include "MapNamePane.h"` and the class-owned method material before `MapNamePane *g_pMapNamePane = NULL;`.
- Why this placement fits: file-local cohesion and current source tree; external MapPane consumer is served by the header extern.
- Rejected placements: MapPane.cpp, MiniMap.cpp, generic control/text, render/ImageLib, DATFile, and a new resource-helper source.
- Remaining placement uncertainty: original project may have placed a private declaration in a broader map header, but current evidence strongly favors the dedicated basename and does not justify losing the existing source root.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: raw helper half-open `503110-5031e1`; constructor `5031f0-5032c3`; destructor `5032d0-50334d`; paint `503350-50349f`; handler `5034a0-503574`; clear `5037f0-5037fb`; thunks `50380b-503821`; scalar wrapper `503840-5038fe`. Padding/gaps are enumerated in Section 14.
- Children/subranges: retain exact existing child pages. Do not emit UID0001AK or UID0001AL. Reclassify only UID0003XK to compiler-covered non-reconstructable.
- Padding/table/data/code distinctions: raw helper is real code despite no function object; CC runs and internal holes remain parent-only padding; vtables/resources/global remain data; MiniMap starts are separate code owners.
- Parent/container impact: UID00007P becomes the only method container; UID0000L2 remains file route; UID0001AK/1AL remain evidence indexes.

## Negative Evidence Summary

- No source symbol recovers the exact private helper or field spellings. Human names are inferred consistently from behavior and accepted project style; raw IDA names are excluded from final C++.
- No inbound route proves the raw glyph helper executes in this build. Its complete retained bytes and class field lifecycle prove source ownership strongly enough to reconstruct it, but not to claim a live paint call.
- No direct destructor xref exists. Vtable/scalar/thunk family and duplicate cleanup establish the ordinary source destructor.
- MapPane's global read does not prove source ownership. MiniMap adjacency does not prove ownership. Shared FRMPART/9X11 literals do not create a standalone MapName resource object.
- The legacy aggregate range does not authorize aggregate C++. It crosses MiniMap code, compiler wrappers, and padding.
- Modern safety improvements such as initializing `m_mapNameGlyphs` outside the EPF branch or clamping conversion length to 127 would change behavior and are rejected.

## IDA Rename / Type / Comment Recommendations

This is a read-only structured handoff. Every mutation is supervisor-owned. The rows below record dated literal prestates, evidence-supported intended state, collision and protection constraints, and expected readback. Runtime authority, mutation, persistence, and recovery remain external supervisor responsibilities; this report contains no transaction program.

### Type Prerequisites

| Type | Current parser-visible state | Required declaration / invariant | Disposition and stop condition |
| --- | --- | --- | --- |
| `Pane` | Present, size `0xf8`; dated generated-H snapshot exposes `explicit Pane(unsigned char mode)`. | Physical base size remains `0xf8`; exact constructor declaration and all existing members remain unchanged. | Protect; stop if size, constructor declaration, or members differ. |
| `EPFTileContext` | Present, size `0x28`. | Retain exact declaration and `RectBounds bounds` at `+0x10`. | Protect; stop on mismatch. |
| `Event` | Present, size `0x110`. | Retain exact current layout; the report changes the declaration channel, not this IDA layout. | Protect; stop on mismatch. |
| `EventHandler` | Name resolves only as a pointer-kind type, size `4`; no exact `EventHandler` UDT resolves through the current public type queries. | No declaration or receiver-type action is authorized. I0L2-05 retains the physical `_WORD *` secondary-facet receiver while applying only evidence-supported `bool` return and `Event *` argument metadata. | Protect/narrow; stop if a fresh preflight differs. Do not manufacture or infer an `EventHandler` UDT during this transaction. |
| `MapNamePane` | Absent. | Declare one analysis-only physical UDT containing `Pane base` at `+0x000`, `wchar_t m_mapNameText[128]` at `+0x0f8`, `EPFTileContext m_mapNameImage` at `+0x1f8`, and `unsigned char *m_mapNameGlyphs` at `+0x220`; exact size `0x224`. | Apply only if absent and prerequisite sizes match. An existing non-identical type is a hard stop. The physical UDT must not replace the human multiple-inheritance declaration in Section 22. |

### Exact Action And Protection Rows

Function names are collision-checked without changing state before application. Every function-name action uses operation `rename` with literal `pure:true`. Occupied frame-row changes use the dedicated stack-variable path, do not use pure mode, and may change only the enumerated rows. Exact function prototypes and comment channels are applied independently. Function-repeatable comments, regular address comments, and repeatable address comments are distinct channels and must be read back separately.

| ID | Exact entity and literal current prestate | Intended state change | Safety constraints and exact expected readback |
| --- | --- | --- | --- |
| I0L2-01 | Raw code `[0x503110,0x5031e1)`: no function object/name/type; 81 instructions; `retn 10h` at `0x5031de`; fourth argument is loaded as one byte then sign-extended; address comments blank; `[0x5031e1,0x5031f0)` is fifteen `0xcc` bytes. | Define exactly `[0x503110,0x5031e1)`; name it `MapNamePane_DrawNumberGlyphString`; apply prototype `void __thiscall MapNamePane_DrawNumberGlyphString(MapNamePane *this, const wchar_t *text, int x, int y, signed char glyphRow)`; set function-repeatable comment `Draws 9x11 numeric glyphs from the MapNamePane glyph buffer; spaces and slashes advance without drawing.` No stack-row change. | Preserve bytes, end, return cleanup, padding, calls, zero inbound xrefs, and the complete physical frame matrix below. Read back the exact function/name/type/comment, blank other comment channels, unchanged bytes/xrefs, and no unlisted frame delta. |
| I0L2-02 | Function `[0x5031f0,0x5032c3)`, name `sub_5031F0`, type `int __thiscall sub_5031F0(int this)`; AR=`absent`, ARep=`absent`, FReg=`absent`, FRep=`absent`; seven-row frame below; `var_14` is loader-size output. | Rename to `MapNamePane_Constructor`; apply prototype `MapNamePane *__thiscall MapNamePane_Constructor(MapNamePane *this)`; rename only `var_14` to `glyphDataSize`; set function-repeatable comment `Constructs the map-name overlay, initializes EPF state and conditionally loads MAPNAME.EPF and 9X11FONT.BIN.` | Preserve EH rows, opaque `arg_4`, vptr writes, Singleton publication, two callers, resource operands, and all unlisted frame fields. Exact readback changes only the function name/prototype, named frame row, and FRep; AR/ARep/FReg remain absent. |
| I0L2-03 | Function `[0x5032d0,0x50334d)`, name `sub_5032D0`; latest stored and decompiled type `void __thiscall(Pane *this)`; AR=`absent`, ARep=`absent`, FReg=`absent`, FRep=`absent`; no direct inbound xref; four-row frame below. The older `_DWORD *` stored-type checkpoint is superseded history. | After the physical UDT passes, rename to `MapNamePane_Destructor`; apply prototype `void __thiscall MapNamePane_Destructor(MapNamePane *this)`; set function-repeatable comment `Source-authored MapNamePane destructor body; releases the optional 9X11 glyph buffer before compiler-generated Singleton/base teardown.` No stack-row change. | Preserve range, current `Pane *` prestate, three vptr writes, `+0x220` release, singleton clear, base-destructor call, zero-direct-xref fact, scalar-wrapper relation, and frame. Exact readback changes only the function name, receiver from `Pane *` to `MapNamePane *`, and FRep; AR/ARep/FReg remain absent. |
| I0L2-04 | Function `[0x503350,0x50349f)`, name `sub_503350`, type `void __thiscall sub_503350(int this)`; AR=`absent`, ARep=`absent`, FReg=`absent`, FRep=`absent`; three-row frame below. | Rename to `MapNamePane_OnPaint`; apply prototype `void __thiscall MapNamePane_OnPaint(MapNamePane *this)`; set function-repeatable comment `Paints the centered map name using MAPNAME.EPF/FRMPART.PAL or the legacy filled-text fallback.` No stack-row change. | Protect vtable ref `0x61e5f8`, unconditional `GetMemoryMan`, both branches, colors, modes, coordinates, and frame. Exact readback changes only the function name/prototype and FRep; AR/ARep/FReg remain absent. |
| I0L2-05 | Function `[0x5034a0,0x503574)`, name `sub_5034A0`, type `char __thiscall sub_5034A0(_WORD *this, int)`; AR=`absent`, ARep=`absent`, FReg=`absent`, FRep=`absent`; physical receiver is the EventHandler facet at primary `+0xa0`; seven-row frame below. `EventHandler` is currently pointer-kind size 4 and has no exact resolvable UDT. | Rename to `MapNamePane_HandlePacketEvent`; apply narrowed prototype `bool __thiscall MapNamePane_HandlePacketEvent(_WORD *eventHandlerThis, Event *event)`; rename only `var_108` to `memoryMan`, `MultiByteStr` to `mapNameBytes`, and `arg_0` to `event`; set function-repeatable comment `Handles opcode 0x15 map-name updates through the EventHandler subobject and always returns false.` Do not declare or apply an `EventHandler *` receiver type. | Preserve the exact `_WORD *` receiver representation, receiver adjustment, packet offsets, 256-byte local, ACP conversion edge, invalidation call, false return, and all frame widths/offsets. Exact readback changes only the function name, return/stack-argument metadata, three listed frame names, and FRep; AR/ARep/FReg remain absent. Stop if `_WORD *`, Event size `0x110`, the seven-row frame, or vtable xref `0x61e610` differs. |
| I0L2-06 | Function `[0x5037f0,0x5037fb)`, name `sub_5037F0`, type `void sub_5037F0(void)`; one return-address row; AR=`absent`, ARep=`absent`, FReg=`absent`, FRep=`absent`; sole xref `0x6020b1`; Hex-Rays body uses generated alias `unk_69B4B4` for the stored-blank singleton head. | Rename to `MapNamePane_ConstructionUnwindClearSingleton`; set function-repeatable comment `Compiler-generated constructor-unwind cleanup for Singleton<MapNamePane>; no standalone source function.` No type/frame change. | Preserve exact ABI/frame/body/xref/compiler classification; do not treat the generated singleton alias as stored state; AR/ARep/FReg remain absent and only FRep changes. |
| I0L2-07 | Function `[0x50380b,0x503816)`, name `sub_50380B`, type `_DWORD *__thiscall sub_50380B(_DWORD *this, char arg1)`; one return-address row; AR=`Block`, ARep=`absent`, FReg=`absent`, FRep=`absent`; body subtracts `0xa0` and jumps `0x503840`. | Rename to `MapNamePane_EventHandler_ScalarDeletingDestructorThunk`; clear the regular address comment; set repeatable address comment `Compiler adjustor thunk: EventHandler view -0xa0 to MapNamePane scalar deleting destructor.` No type/frame change. | Preserve return/calling convention/arguments, frame, bytes, jump, and vtable xref; expected channels are AR=`absent`, exact ARep text, FReg=`absent`, FRep=`absent`. |
| I0L2-08 | Function `[0x503816,0x503821)`, name `sub_503816`, same raw deleting-thunk ABI; one return-address row; AR=`Block`, ARep=`absent`, FReg=`absent`, FRep=`absent`; body subtracts `0xa4` and jumps `0x503840`. | Rename to `MapNamePane_TimerHandler_ScalarDeletingDestructorThunk`; clear the regular address comment; set repeatable address comment `Compiler adjustor thunk: TimerHandler view -0xa4 to MapNamePane scalar deleting destructor.` No type/frame change. | Preserve ABI/frame/bytes/jump/vtable xref; expected channels are AR=`absent`, exact ARep text, FReg=`absent`, FRep=`absent`. |
| I0L2-09 | Function `[0x503840,0x5038fe)`, name `sub_503840`, latest stored/decompiled type `Pane *__thiscall sub_503840(Pane *Block, char)`; exact five-row frame below; AR=`absent`, ARep=`absent`, FReg=`absent`, FRep=`absent`; primary-vtable route and two thunk callers; delete flag and size guard `0x224`. The older `_DWORD *` declaration is superseded history. | Rename to `MapNamePane_ScalarDeletingDestructor`; set function-repeatable comment `Compiler-generated scalar deleting destructor for MapNamePane; source authority is virtual ~MapNamePane().` No type/frame change. | Preserve exact `Pane *` return/receiver ABI, unnamed `char` parameter, frame, delete behavior, size guard, calls, two thunk callers, and primary-vtable slot; AR/ARep/FReg remain absent and only FRep changes. |
| I0L2-10 | `[0x69b4b4,0x69b4b8)` consists of a one-byte head with stored name blank, type `Pane *`, non-code/non-data, plus three separate blank one-byte heads; all four bytes zero; refs `6/0/0/0`; regular/repeatable comments blank; next head `0x69b4b8` is separate `Pane *`; no destination collision. Hex-Rays-generated `unk_69B4B4` is historical display evidence only and is absent from the item/name index. | After UDT and exact span checks, materialize one four-byte data item named `g_pMapNamePane` with parser declaration `MapNamePane *g_pMapNamePane`; set repeatable address comment `Process-wide MapNamePane singleton pointer; null before construction and after destruction.` Keep regular address comment blank. This is creation/materialization plus destination naming, never an old-name rename from `unk_69B4B4`. | Consume exactly `[0x69b4b4,0x69b4b8)`; preserve all four zero bytes, refs `6/0/0/0`, tail resolution, and the `0x69b4b8` neighbor. Stop on parser failure, collision, channel cross-write, span extension, any resolvable old name, or any byte/xref/neighbor delta. Final readback is one four-byte data item `[0x69b4b4,0x69b4b8)`, exact name/type, regular blank, repeatable exact. |
| I0L2-11 | UTF-16 `[0x61e6c0,0x61e6d8)` is split across display `off_61E6C0` with name-index alias `aMa_8`, a blank middle head, and `aAmeEpf_0`; stable reads are `MA`, `P`, and `AME.EPF`; exact bytes decode `MAPNAME.EPF\0`; refs `1/0/0`; comments blank; sole ref `0x50328d`. | Consolidate exactly this span as one parser-visible `const wchar_t kMapNameEpfResourceName[12]`; remove the consumed fragment identities only as a consequence of exact-span materialization; set repeatable address comment `MapNamePane EPF layout resource name used by the constructor.` Keep regular address comment blank. | Preflight must resolve display names, alias `aMa_8`, all three stable reads, exact 24 bytes, one head ref and zero interior refs, destination-name collision absence, and unchanged neighbors. Final readback requires one 24-byte item `[0x61e6c0,0x61e6d8)`, exact name/type, decoded `MAPNAME.EPF`, one unchanged xref, no surviving interior heads/aliases, blank regular comment, exact repeatable comment, and unchanged neighbors. Stop on any mismatch. |
| I0L2-12 | Shared UTF-16 `[0x610fa4,0x610fbc)` is split across display `off_610FA4` with name-index alias `aFr_5` and `aMpartPal`; stable reads are `FR` and `MPART.PAL`; exact bytes decode `FRMPART.PAL\0`; comments blank; refs are exactly `0x461683`, `0x503375`, and `0x503678`. | No change. | Protect both item spans, display names, alias `aFr_5`, stable split reads, types, exact 24 bytes, blank comment channels, all three xrefs, and neighbors; do not consolidate, rename, retype, comment, or duplicate it. |
| I0L2-13 | Vtable/RTTI bases `0x61e5b4` `??_7MapNamePane@@6B@`, `0x61e600` `??_7MapNamePane@@6B@_0`, and `0x61e630` `??_7MapNamePane@@6B@_1` have exact decorated names and slot routes; successor `0x61e63c` begins MiniMap vtable data. Key slots are `0x61e5b4 -> 0x503840`, `0x61e5f8 -> 0x503350`, `0x61e600 -> 0x50380b`, `0x61e610 -> 0x5034a0`, and `0x61e630 -> 0x503816`. | No change. | Protect names, boundaries, RTTI pointers, all slots/xrefs, the five key mappings, and adjacent data including successor `0x61e63c`. They regenerate from the H declaration and receive no synthetic overwrite. |

### I0L2-01 complete raw physical frame matrix

The raw helper has no current function object and therefore no current `stack_frame` result. The pre-state matrix below is instead literal instruction-derived physical state from all 81 decoded instructions. The post-state is the required ABI/physical contract after `define_func` plus the function signature. No I0L2-01 stack-name or stack-type mutation is authorized: semantic source names are recorded for reconstruction, while any automatically generated IDA local spelling is non-authoritative and must not conceal a changed span.

| Row | Exact physical location | Width | Current pre-state | Required post-state | Permitted delta / protection |
| --- | --- | --- | --- | --- | --- |
| Function return | register ABI | 0 | No function type | `void` | Type declaration only |
| Receiver | `ECX`, copied to `EDI` at `0x503129` | 4 | Undeclared receiver | `MapNamePane *this` | Type/name metadata only; instruction unchanged |
| Local `glyphContext` | `[ebp-0x3c,ebp-0x14)` | `0x28` | Unnamed raw local; initialized at `0x50312b`; exact `EPFTileContext` field accesses | Same physical span and `EPFTileContext` semantic role | No stack-row rename/type operation; no span or access delta |
| Local `destinationBounds` | `[ebp-0x14,ebp-0x04)` | `0x10` | Unnamed raw local initialized by `InitRectBounds` at `0x50315f` | Same physical span and `RectBounds` semantic role | No stack-row rename/type operation |
| Local `securityCookie` | `[ebp-0x04,ebp)` | 4 | Security-cookie value written at `0x50311d` | Same physical row, `unsigned int` semantic role | Protected compiler row |
| Saved `EBX` | `[ebp-0x40,ebp-0x3c)` | 4 | Push at `0x503120`, pop at `0x5031d5` | Same saved-register slot | No delta |
| Saved `ESI` | `[ebp-0x44,ebp-0x40)` | 4 | Push at `0x503124`, pop at `0x5031d2` | Same saved-register slot | No delta |
| Saved `EDI` | `[ebp-0x48,ebp-0x44)` | 4 | Push at `0x503128`, pop at `0x5031d1` | Same saved-register slot | No delta |
| Saved `EBP` | `[ebp,ebp+0x04)` | 4 | Prologue `push ebp`; epilogue `pop ebp` | Same saved-frame-pointer row | No delta |
| Return address | `[ebp+0x04,ebp+0x08)` | 4 | Caller return address | Same `_UNKNOWN *` return-address row | No delta |
| Argument 1 | `[ebp+0x08,ebp+0x0c)` | 4 | Undeclared pointer loaded at `0x503125` | `const wchar_t *text` | Argument name/type metadata only |
| Argument 2 | `[ebp+0x0c,ebp+0x10)` | 4 | Undeclared signed coordinate loaded at `0x50314e` | `int x` | Argument name/type metadata only |
| Argument 3 | `[ebp+0x10,ebp+0x14)` | 4 | Undeclared signed coordinate loaded at `0x50314b` | `int y` | Argument name/type metadata only |
| Argument 4 | `[ebp+0x14,ebp+0x18)` | 4 ABI slot; low 1 byte consumed | Low byte loaded at `0x503121` and sign-extended at `0x50317f`; `retn 0x10` proves four stack slots | `signed char glyphRow` in a four-byte caller-cleanup slot | Type/name metadata only; byte load, sign extension, and cleanup unchanged |

### I0L2-02 complete current/post frame matrix

| Row | Current exact state | Required post-state | Permitted delta / protection |
| --- | --- | --- | --- |
| Function ABI | Return `int`; implicit `ECX` argument `this:int` | Return `MapNamePane *`; `ECX` argument `this:MapNamePane *` | Function rename/prototype metadata and exact FRep from I0L2-02 only; AR/ARep/FReg remain absent |
| Display `+0x10` | `var_14`, size `0x4`, type `int` | `glyphDataSize`, size `0x4`, type `int` | Name only through the dedicated stack-variable action; pure function mode is inapplicable |
| Display `+0x14` | `var_10`, size `0x4`, type `Pane *` | Identical | Protected EH row |
| Display `+0x18` | `var_C`, size `0x4`, type `_DWORD` | Identical | Protected EH row |
| Display `+0x20` | `var_4`, size `0x4`, type `_DWORD` | Identical | Protected security/EH row |
| Display `+0x24` | `__saved_registers`, size `0x4`, type `_DWORD` | Identical | Protected saved-register row |
| Display `+0x28` | `__return_address`, size `0x4`, type `_UNKNOWN *` | Identical | Protected return-address row |
| Display `+0x30` | `arg_4`, size `0x4`, type `_DWORD` | Identical; no source argument is inferred from this opaque existing row | Protected row; no delete/rename/type operation |

### I0L2-03 complete current/post frame matrix

| Row | Current exact state | Required post-state | Permitted delta / protection |
| --- | --- | --- | --- |
| Function ABI | Stored/decompiled return `void`; implicit `ECX` argument `this:Pane *`; older `_DWORD *` checkpoint retained only as superseded history | Return `void`; `ECX` argument `this:MapNamePane *` | Function rename, derived receiver type, and exact FRep from I0L2-03 only, after exact UDT/body/frame preconditions pass; AR/ARep/FReg remain absent |
| Display `+0x08` | `var_C`, size `0x4`, type `_DWORD` | Identical | Protected local row |
| Display `+0x14` | `__saved_registers`, size `0x4`, type `_DWORD` | Identical | Protected saved-register row |
| Display `+0x18` | `__return_address`, size `0x4`, type `_UNKNOWN *` | Identical | Protected return-address row |
| Display `+0x20` | `arg_4`, size `0x4`, type `_DWORD` | Identical; no source argument is inferred | Protected row; no delete/rename/type operation |

### I0L2-04 complete current/post frame matrix

| Row | Current exact state | Required post-state | Permitted delta / protection |
| --- | --- | --- | --- |
| Function ABI | Return `void`; implicit `ECX` argument `this:int` | Return `void`; `ECX` argument `this:MapNamePane *` | Function rename/prototype metadata and exact FRep from I0L2-04 only; AR/ARep/FReg remain absent |
| Display `+0x0c` | `length`, size `0x4`, type `int` | Identical | Protected already source-facing local |
| Display `+0x10` | `__saved_registers`, size `0x4`, type `_DWORD` | Identical | Protected saved-register row |
| Display `+0x14` | `__return_address`, size `0x4`, type `_UNKNOWN *` | Identical | Protected return-address row |

### I0L2-05 complete current/post frame matrix

| Row | Current exact state | Required post-state | Permitted delta / protection |
| --- | --- | --- | --- |
| Function ABI | Return `char`; implicit `ECX` argument `this:_WORD *`; unnamed stack argument `int` | Return `bool`; physical `ECX` argument remains `_WORD *` and is named `eventHandlerThis`; stack argument becomes `event:Event *` | Exact return/stack-argument type and source-facing names only; receiver type is protected unchanged because no exact `EventHandler` UDT resolves |
| Display `+0x08` | `var_10C`, size `0x4`, type `_DWORD` | Identical | Protected local row |
| Display `+0x0c` | `var_108`, size `0x4`, type `MemoryMan *` | `memoryMan`, size `0x4`, type `MemoryMan *` | Name only through the dedicated stack-variable action; pure function mode is inapplicable |
| Display `+0x10` | `MultiByteStr`, size `0x100`, type `CHAR[256]` | `mapNameBytes`, size `0x100`, type `CHAR[256]` | Name only through the dedicated stack-variable action; pure function mode is inapplicable |
| Display `+0x110` | `var_4`, size `0x4`, type `_DWORD` | Identical | Protected security row |
| Display `+0x114` | `__saved_registers`, size `0x4`, type `_DWORD` | Identical | Protected saved-register row |
| Display `+0x118` | `__return_address`, size `0x4`, type `_UNKNOWN *` | Identical | Protected return-address row |
| Display `+0x11c` | `arg_0`, size `0x4`, type `_DWORD`; corresponds to the current unnamed `int` stack parameter | `event`, size `0x4`, type `Event *` | Exact name/type change only; physical offset/width protected |

### Non-Runnable Action And Readback Summary

The exact names, prototypes, comments, frame-row deltas, data spans, UDT layout, channel-specific poststates, and protected no-change facts for I0L2-01 through I0L2-13 are stated in the action ledger and complete frame matrices above. A row receives supervisor Gate 2B credit only when its literal prestate and expected final readback match and every listed protection remains unchanged; any unexpected delta leaves that row unverified. Runtime authority, operation ordering, persistence, rollback, and recovery are intentionally absent from this report and remain external supervisor responsibilities. Historical machine-shaped request text formerly in this subsection is preserved only in [0000L2-MapNamePane-file-source-quality-removed.md](0000L2-MapNamePane-file-source-quality-removed.md); it is non-authoritative and must never be executed.


## First-Draft C++ Recommendation

- Eligible for draft C++: UID00007P class CPP/H shell, UID0002XC global definition retained, UID0002BF helper, and UID0003XG-UID0003XJ authored methods. Compiler glue/vtables/literals/covered storage are not independently source-bearing.
- Required direct-file emitter order is UID00007P position 10 followed by UID0002XC position 20. UID00007P emits `#include "MapNamePane.h"`, the remaining include shell, and `[[CHILDREN]]` first; UID0002XC then emits `MapNamePane *g_pMapNamePane = NULL;`, so the generated translation unit has declaration visibility before the definition.
- Third-party import directive: not applicable. This is project-owned NexusTK UI code; no `third_party_embeds/` source corresponds to it.

### UID00007P `by-class/MapNamePane.md` formal CPP replacement

```cpp
#include "MapNamePane.h"

#include "../archive/DATFile.h"
#include "../render/ImageLib.h"
#include "../render/Surface.h"
#include "../ui/core/Event.h"
#include "../util/MemoryMan.h"

#include <windows.h>
#include <wchar.h>

extern bool g_useEpfAssets;

[[CHILDREN]]
```

### UID00007P `by-class/MapNamePane.md` formal H replacement

```cpp
#ifndef NEXUSTK_MAP_MAPNAMEPANE_H
#define NEXUSTK_MAP_MAPNAMEPANE_H

#include "../render/EPFTileContext.h"
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class MapNamePane : public Pane, public Singleton<MapNamePane>
{
public:
    MapNamePane();
    virtual ~MapNamePane();

protected:
    virtual void OnPaint();
    virtual bool HandlePacketEvent(Event *event);

private:
    void DrawNumberGlyphString(
        const wchar_t *text, int x, int y, signed char glyphRow);

    wchar_t m_mapNameText[128];
    EPFTileContext m_mapNameImage;
    unsigned char *m_mapNameGlyphs;
};

extern MapNamePane *g_pMapNamePane;

typedef char MapNamePaneSizeMustBe548[
    sizeof(MapNamePane) == 0x224 ? 1 : -1];

#endif
```

The declaration encodes the direct `Pane` base, empty `Singleton<MapNamePane>` source base, exact virtual slots, exact field offsets/size, and external singleton linkage without exposing compiler deleting-destructor helpers.

### UID0002BF formal CPP insertion

```cpp
void MapNamePane::DrawNumberGlyphString(
    const wchar_t *text, int x, int y, signed char glyphRow)
{
    EPFTileContext glyphContext;
    glyphContext.Initialize();
    glyphContext.rowStridePixels = 9;
    InitRectBounds(&glyphContext.bounds, 0, 0, 9, 11);

    RectBounds destinationBounds;
    InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

    for (const wchar_t *scan = text; *scan != L'\0'; ++scan)
    {
        if (*scan != L' ' && *scan != L'/')
        {
            const int glyphIndex =
                static_cast<int>(*scan) + glyphRow * 10 - 47;
            glyphContext.pixelData = m_mapNameGlyphs + glyphIndex * 99;
            g_pfnBlitSprite(this,
                            &glyphContext,
                            &glyphContext.bounds,
                            &destinationBounds,
                            1, NULL, NULL);
        }

        OffsetRect(&destinationBounds, 9, 0);
    }
}
```

This matches the complete retained body: the local context is initialized, its row stride is fixed at 9, each non-space/non-slash glyph selects one 99-byte record, the Surface callback receives the exact context/source/destination/mode/null-palette/null-options tuple, and the destination advances by 9 after every character. It deliberately does not call the raw-buffer `RenderTileFrame` overload seen in older generated neighboring drafts because current `GrafPort.h` does not declare that overload and the binary calls `g_pfnBlitSprite` directly. UID0002BF H remains blank because the declaration belongs once in UID00007P.

### UID0003XG formal CPP insertion

```cpp
MapNamePane::MapNamePane()
    : Pane(1)
{
    m_mapNameImage.Initialize();
    m_mapNameText[0] = L'\0';

    if (g_useEpfAssets)
    {
        g_pEPFLib->LookupLayoutEntry(
            L"MAPNAME.EPF", 0, &m_mapNameImage);

        int glyphDataSize;
        m_mapNameGlyphs = reinterpret_cast<unsigned char *>(
            LoadDatFileBuffer(L"9X11FONT.BIN", 99, &glyphDataSize));
    }
}
```

The source intentionally does not initialize `m_mapNameGlyphs` on the disabled branch because the binary does not. Compiler Singleton publication, vptr stores, and EH cleanup are excluded. UID0003XG H remains blank because the constructor declaration is in UID00007P.

### UID0003XH formal CPP insertion

```cpp
MapNamePane::~MapNamePane()
{
    if (m_mapNameGlyphs != NULL)
    {
        m_mapNameGlyphs = static_cast<unsigned char *>(
            GetMemoryMan()->FreeBufferMemory(m_mapNameGlyphs));
    }
}
```

The source contains only the authored glyph-buffer release. Compiler vptr restoration, singleton clear, base destruction, and deleting wrappers regenerate from the declaration. UID0003XH H remains blank.

### UID0003XI formal CPP insertion

```cpp
void MapNamePane::OnPaint()
{
    GetMemoryMan();

    const int length = static_cast<unsigned short>(wcslen(m_mapNameText));

    if (g_useEpfAssets)
    {
        RenderTileFrame(&m_mapNameImage,
                        &m_mapNameImage.bounds,
                        &m_mapNameImage.bounds,
                        1, L"FRMPART.PAL", NULL);

        const int x = (m_visibleBounds.left + m_visibleBounds.right) / 2
                    - GetTextWidth(m_mapNameText, length) / 2;
        const int y = (m_visibleBounds.top + m_visibleBounds.bottom) / 2 + 5;
        m_textDrawMode = 1;
        SetTextColor(0x80);
        MoveTo(x + 1, y);
        DrawWideText(m_mapNameText, length);
        MoveTo(x, y);
        DrawWideText(m_mapNameText, length);
    }
    else
    {
        m_drawMode = 0;
        SetDrawColor(0);
        g_pfnFillRect(this, &m_visibleBounds);

        const int x = (m_visibleBounds.left + m_visibleBounds.right) / 2
                    - GetTextWidth(m_mapNameText, length) / 2;
        MoveTo(x, m_visibleBounds.bottom);
        m_textDrawMode = 1;
        SetTextColor(0x8f);
        DrawWideText(m_mapNameText, length);
    }
}
```

The unconditional `GetMemoryMan()` call, render/fallback mode bytes, coordinates, colors, two EPF draws, and one fallback draw are retained exactly. UID0003XI H remains blank.

### UID0003XJ formal CPP insertion

```cpp
bool MapNamePane::HandlePacketEvent(Event *event)
{
    MemoryMan *memoryMan = GetMemoryMan();
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] == 0x15)
    {
        const unsigned char byteCount = packet[9];
        char mapNameBytes[256];
        memoryMan->MemmoveWrapper(mapNameBytes, packet + 10, byteCount);
        mapNameBytes[byteCount] = '\0';

        const unsigned char wideLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, mapNameBytes, byteCount,
                                m_mapNameText, 128));
        m_mapNameText[wideLength] = L'\0';
        FitTextAndAppendSuffix(m_mapNameText, 128, L"...", 173);
        InvalidateRect(&m_visibleBounds);
    }

    return false;
}
```

The source preserves the unconditional allocator lookup, byte offsets, 256-byte stack buffer, ACP conversion, unsigned-byte result narrowing, possible index 128 write, width 173 ellipsis, invalidation, and always-false result. UID0003XJ H remains blank.

### Support formal visibility repairs

- UID0000A2 `by-class/Pane.md`: in the existing complete H block replace only `Pane();` with `explicit Pane(unsigned char mode);`. Do not change the class layout or any other declaration.
- UID00004L `by-class/Event.md`: use the following exact CPP/H payloads. No enum value, payload field, order, or class member may be summarized or omitted during callback.

```cpp
#include "Event.h"

[[CHILDREN]]
```

```cpp
#ifndef NEXUSTK_UI_CORE_EVENT_H
#define NEXUSTK_UI_CORE_EVENT_H

#include "../../util/LObject.h"

enum PaneKeyCode
{
    kPaneKeyEscape = 0x1b,
    kPaneKeyLeft = 0x80,
    kPaneKeyUp = 0x81,
    kPaneKeyRight = 0x82,
    kPaneKeyDown = 0x83,
    kPaneKeyDelete = 0x84,
    kPaneKeyPageUp = 0x93,
    kPaneKeyPageDown = 0x94
};

enum EventModifierFlags
{
    kEventModifierAlt = 0x01,
    kEventModifierControl = 0x02,
    kEventModifierShift = 0x04
};

enum EventType
{
    kEventCursorMove = 0,
    kEventLeftButtonDown = 1,
    kEventLeftButtonDoubleClick = 2,
    kEventLeftButtonUp = 3,
    kEventRightButtonDown = 4,
    kEventRightButtonDoubleClick = 5,
    kEventRightButtonUp = 6,
    kEventMouseWheel = 7,
    kEventKeyDown = 8,
    kEventKeyUp = 9,
    kEventTextInput = 10,
    kEventImeOpenStatus = 11,
    kEventImeCompositionStart = 12,
    kEventImeCompositionResult = 13,
    kEventImeCompositionEnd = 14,
    kEventImeCandidateList = 15,
    kEventImeCandidateClose = 16,
    kEventImeReserved = 17,
    kEventPacket = 18,
    kEventApplicationNotification = 19,
    kEventDispatchSuppressed = 20,
    kEventSystemControl = 21,
    kEventWorkNotification = 22,
    kEventNone = 0xff
};

struct EventPointerPayload
{
    int m_y;
    int m_x;
    unsigned char m_modifiers;
    int m_detail;
    unsigned int m_messageTime;
};

struct EventKeyPayload
{
    unsigned char m_key;
    unsigned char m_reserved;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned int m_messageTime;
};

struct EventTextPayload
{
    unsigned char m_inputCode;
    unsigned char m_length;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned int m_messageTime;
};

struct EventCompositionPayload
{
    unsigned char m_subtype;
    unsigned char m_length;
    wchar_t m_text[128];
    unsigned char m_modifiers;
    unsigned int m_messageTime;
};

struct EventImeResultPayload
{
    unsigned char m_reserved;
    unsigned char m_length;
    wchar_t m_text[129];
    unsigned int m_messageTime;
};

struct EventImeOpenPayload
{
    int m_isOpen;
    unsigned char m_reserved[0x100];
    unsigned int m_messageTime;
};

struct EventCandidatePayload
{
    void *m_candidateList;
    int m_selectedRow;
    unsigned char m_reserved[0xfc];
    unsigned int m_messageTime;
};

struct EventPacketPayload
{
    unsigned char m_packetKind;
    void *m_data;
    unsigned int m_size;
};

struct EventNotificationPayload
{
    unsigned int m_channel;
    LObject *m_payload;
};

union EventPayload
{
    EventPointerPayload m_pointer;
    EventKeyPayload m_key;
    EventTextPayload m_text;
    EventCompositionPayload m_composition;
    EventImeResultPayload m_imeResult;
    EventImeOpenPayload m_imeOpen;
    EventCandidatePayload m_candidate;
    EventPacketPayload m_packet;
    EventNotificationPayload m_notification;
    unsigned char m_raw[0x108];
};

class Event : public LObject
{
public:
    Event();
    virtual ~Event();

    bool IsPointerEvent() const;
    bool IsKeyOrTextEvent() const;
    bool IsImeEvent() const;
    bool IsPacketEvent() const;
    bool IsSystemOrControlEvent() const;

    unsigned char m_type;
    EventPayload m_payload;
};

[[CHILDREN]]

#endif
```

- UID00006E `by-class/ImageLib.md`: use the following exact CPP/H payloads. Existing child output `extern bool g_imageLibraryLoadError;` remains generated through `[[CHILDREN]]` in the H channel.

```cpp
#include "ImageLib.h"

[[CHILDREN]]
```

```cpp
#ifndef NEXUSTK_RENDER_IMAGELIB_H
#define NEXUSTK_RENDER_IMAGELIB_H

#include "../util/LObject.h"

class List;
struct ArchiveMetadataTable;
struct EPFTileContext;
struct FrameDrawRecord;
struct RectBounds;
struct ResourceLayoutEntry;

class ImageLib : public LObject
{
public:
    ImageLib(int cacheLimit, int);
    virtual ~ImageLib();

    int LoadResourceIndex(const wchar_t *resourceName);
    ResourceLayoutEntry *LookupLayoutEntry(
        const wchar_t *resourceName,
        int frameIndex,
        EPFTileContext *tileContext);
    void CopyEntryTileContext(
        const wchar_t *resourceName,
        int frameIndex,
        EPFTileContext *destination);
    RectBounds *GetEntryRect(
        const wchar_t *resourceName,
        int frameIndex,
        RectBounds *bounds);
    void LoadFrameDrawRecord(
        const ArchiveMetadataTable *table,
        int frameIndex,
        FrameDrawRecord *outRecord);
    void GetFrameSize(
        const wchar_t *resourceName,
        unsigned short *width,
        unsigned short *height);
    unsigned short GetEntryCount(const wchar_t *resourceName);

private:
    int FindResourceIndex(const wchar_t *resourceName);

    int m_refCount;
    int m_cacheLimit;
    List *m_pEntryList;
    int m_maxCacheSize;
};

typedef ImageLib ResourceLayoutTable;

extern ImageLib *g_pEPFLib;

typedef char ImageLibSizeMustBe20[
    sizeof(ImageLib) == 0x14 ? 1 : -1];

[[CHILDREN]]

#endif
```

- UID00016G `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md`: retain the current exact CPP body and use this exact H payload:

```cpp
char *__stdcall LoadDatFileBuffer(
    const wchar_t *path, int prefixSize, int *outSize);
```
- UID0002XC retains exact CPP `MapNamePane *g_pMapNamePane = NULL;`; H remains blank because UID00007P owns the single extern declaration.

Behavior fidelity takes priority over modernization. The code uses ordinary Visual C++-era class methods, raw fixed buffers, Win32 ACP conversion, global render callbacks, explicit resource names, and project allocation APIs. Inferred names follow existing project conventions (`g_`, `m_`, PascalCase classes/methods, lower camel locals) and avoid IDA labels. Naming consistency is subordinate to exact behavior and the strongest local source-shape evidence.

## Final Recommendation

- Retain the physically implemented [UID:0000L2] narrow standalone `NexusTK/map/MapNamePane.cpp/.h` source route at `94/95`; by-file `CANONICAL_OWNER:FILE` and path remain unchanged.
- Preserve the complete class/header, five authored method bodies, one global definition, direct-file order UID00007P position 10 before UID0002XC position 20, and child order 10/20/30/40/50.
- Keep UID0001AK/UID0001AL as non-emitting indexes and MiniMapButtonPane entirely excluded. UID0003XK is now compiler-generated/non-reconstructable/non-emitting; UID0003XL/UID0003XM remain compiler no-code pages; vtable/resource/storage pages remain declaration-, literal-, or covered-by evidence without duplicate bodies. UID0003BZ/UID0003IL emit only explanatory no-code comments, never duplicate definitions.
- Preserve the applied Pane/Event/ImageLib/LoadDat visibility repairs. They are required compile/source-route changes and retain every unrelated API/layout/history detail.
- Preserve every historical blocker and rejected alternative already retained in the destinations, including the no-xref helper result, stale 0xffffffff storage claim, mixed-island history, and prior blank-C++ rationale with its dated supersession reason.
- No additional target UID is declared. Support pages receive edits and validation but no report-coverage credit from this artifact.
- No generic future research remains. Original private spellings and raw-helper runtime liveness remain explicitly confidence-limiting, but their best source-facing resolution and formal/no-code disposition are complete.

## Recommended Target Doc Changes

**Target:** `by-file/MapNamePane.md` [UID:0000L2].

Implementation disposition: all seven accepted ordinary target changes below are physically applied in current SHA `8034083E6694E0FBDA66D5E0C4B0DA3200249C6EAD9463589B1A0379AF543B31`; initial command `000000022832` is historical, and follow-up command `000000022991` validates the corrected active standalone-placement sentence.

1. Completion/confidence are `94/95`; `PROPOSED_PATH:NexusTK/map/` and `CANONICAL_OWNER:FILE` are retained. By-file reconstructable/emitter/position/Nested/formal fields remain target-schema not applicable.
2. The complete inventory includes every authored method, compiler helper, vtable/resource/global/storage item, exact gap, and all eight MiniMap exclusions.
3. Resource lifecycle, paint branches, packet format/conversion, global linkage, dependency/header closure, source order, and the conversion-result-128 historical edge are incorporated.
4. Ownership/source-placement reasoning rejects MapPane consumer transfer, MiniMap adjacency transfer, and shared-literal ownership transfer.
5. The former blank-C++ blocker is historicalized and every source-bearing child/support declaration is linked.
6. The generated-state section retains the dated pre-refresh SHA/absent-header evidence and historical command `000000022981` receipt, then records dated command `000000023008` coherent CPP/H and tracker snapshots without treating either as permanent current authority or claiming any direct B003 generated-file edit. Current generated CPP/H and the lifecycle-sensitive tracker are reread separately at every Gate and mandatory post-move audit.
7. The conservative former final-C++ state, broad-range/0xffffffff assumptions, UiAssetModeRect direction, and aggregate-body direction are retained as corrected history.

## Recommended Support Doc Changes

Every row below preserves the dated Gate-1-accepted pre-callback state and the physically implemented current state. `blank` means the field is physically blank, not unknown. `N/A` means that document type does not carry that field. All recommended right-side states are now applied except UID0001AL, which was already present and remained byte-identical.

| Support destination | Dated accepted pre-callback metadata/formal state | Current physical post-callback metadata/formal state | Exact report detail incorporated |
| --- | --- | --- | --- |
| `by-class/MapNamePane.md` UID00007P | `86/88`; owner/emitter `0000L2`; reconstructable true; position blank; CPP/H blank | `94/95`; same owner/emitter/reconstructable; direct-file position `10`; exact Section 22 CPP/H | Complete layout, inheritance, vtable slots, members, compile-safe class/include/method-before-global source order, compiler exclusions, resources, xrefs and generated-header requirement |
| `by-global/g_pMapNamePane.md` UID0002XC | `88/91`; owner/emitter `0000L2`; position blank; CPP definition present; H blank | `93/95`; same owner/emitter; direct-file position `20`; retain exact CPP; H blank | Six xrefs, null initialization, external MapPane consumer, single-definition/extern split, and placement after UID00007P |
| `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md` UID0002XD | `88/91`; owner/emitter `0002XC`; reconstructable true; position blank; covered-by CPP; H blank; Nested `4` | `93/95`; all metadata/formals retained; position blank; Nested `4` | Current four zero bytes/four one-byte heads, six refs, covered-by definition, stale 0xffffffff correction |
| `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` UID0002BF | `87/91`; owner/emitter `00007P`; reconstructable true; position blank; CPP/H blank; Nested `0` | `92/93`; same owner/emitter/reconstructable/Nested; position `10`; exact CPP; H blank | Exact algorithm, bytes/bounds, no-xref evidence, analogous source naming and confidence cap |
| `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md` UID0003XG | `86/90`; owner/emitter `00007P`; reconstructable true; position blank; CPP/H blank; Nested `8` | `94/95`; same owner/emitter/reconstructable/Nested; position `20`; exact CPP; H blank | Full constructor, callers, resources, conditional uninitialized pointer, compiler vptr/Singleton/EH exclusions |
| `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md` UID0003XH | `86/90`; owner/emitter `00007P`; reconstructable true; position blank; CPP/H blank; Nested `0` | `93/95`; same owner/emitter/reconstructable/Nested; position `30`; exact CPP; H blank | Authored MemoryMan release versus compiler teardown family |
| `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md` UID0003XI | `86/89`; owner/emitter `00007P`; reconstructable true; position blank; CPP/H blank; Nested `0` | `94/95`; same owner/emitter/reconstructable/Nested; position `40`; exact CPP; H blank | Both exact paint branches, shared palette literal, unconditional allocator lookup, modes/colors/coordinates |
| `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md` UID0003XJ | `87/90`; owner/emitter `00007P`; reconstructable true; position blank; CPP/H blank; Nested `0` | `94/95`; same owner/emitter/reconstructable/Nested; position `50`; exact CPP; H blank | Secondary-vtable ABI, Event payload/opcode/offsets, ACP conversion edge, ellipsis/invalidation/false return |
| `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md` UID0003XK | `85/88`; owner/emitter `00007P`; reconstructable true; position blank; CPP/H blank; Nested `8` | `94/96`; owner `00007P`; reconstructable false; emitter/position/CPP/H blank; Nested `8` | Sole constructor-EH xref and exact compiler construction-unwind no-code proof |
| `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md` UID0003XL | `85/90`; owner `00007P`; reconstructable false; emitter/position/formals blank; Nested `8` | `94/97`; retain all metadata/formals/Nested | Two exact `-0xa0`/`-0xa4` compiler thunk routes; no source body |
| `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md` UID0003XM | `86/90`; owner `00007P`; reconstructable false; emitter/position/formals blank; Nested `8` | `94/96`; retain all metadata/formals/Nested | Exact delete flag, `0x224` guard, ordinary destructor authority; no source body |
| `by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md` UID0003BZ | `87/92`; owner/emitter `00007P`; reconstructable true; position/formals blank; Nested `8` | `94/97`; retain owner/emitter/reconstructable/blank position/Nested; CPP is the exact explanatory no-code comment; H blank | Three vtables/RTTI regenerate from class declaration; no standalone source table |
| `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md` UID0003IL | `86/92`; owner/emitter `00007P`; reconstructable true; position/formals blank; Nested `0` | `93/96`; retain owner/emitter/reconstructable/blank position/Nested; CPP is the exact explanatory no-code comment; H blank | Exact UTF-16 literal and one constructor xref; constructor-covered source literal |
| `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` UID00044U | `89/93`; owner none; emitters `0000JL,0000L2,0000LE`; reconstructable true; position blank; CPP shared comment; H blank; Nested `0` | score/owner/reconstructable/position/Nested retained; emitters `0000JL,0000LE`; retain shared comment for remaining routes | Three exact consumers; MapName uses literal directly, so its emitter would produce a documentation comment in real source |
| `by-memory/0x005031f0-0x005038fe.MapNamePane.md` UID0001AK | `88/91`; owner `00007P`; reconstructable false; no emitter; position/formals blank; Nested `0` | `94/96`; all metadata/formals retained | Exhaustive child/gap/compiler/source inventory; aggregate C++ remains forbidden |
| `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` UID0001AL | `86/92`; owner none; reconstructable false; no emitter; position/formals blank; Nested `-4` | score and metadata/formals retained | Complete sixteen-function split and exclusion inventory; correct stale manual reconstructable wording only |
| `by-class/Pane.md` UID0000A2 | `92/94`; owner/emitter `0000MC`; reconstructable true; position blank; complete CPP/H with stale `Pane()` H line | score/metadata/CPP retained; H changes only to `explicit Pane(unsigned char mode);` | Constructor ABI/caller evidence and preservation of every existing API/layout line |
| `by-file/Pane.md` UID0000MC | `90/91`; owner FILE; path `NexusTK/ui/core/`; formal fields N/A | score/owner/path retained; contract note names the exact `Pane(1)` MapNamePane initializer | Correct the generated-H constructor note without changing broader Pane source |
| `by-class/Event.md` UID00004L | `94/95`; owner/emitter `0000J6`; reconstructable true; position `10`; complete declaration in CPP; H blank | score/metadata retained; CPP include + children; H exact guarded declaration + children | Preserve all enums/payload variants/size/order/history while correcting declaration channel |
| `by-file/Event.md` UID0000J6 | `91/92`; owner FILE; path `NexusTK/ui/core/`; formal fields N/A | score/owner/path retained | Record self-contained Event.h as physically required and generated through UID00004L |
| `by-class/ImageLib.md` UID00006E | `89/90`; owner/emitter `0000K2`; reconstructable true; position `0`; complete declaration in CPP; H blank | score/metadata retained; CPP include + children; H exact guarded declaration + children | Preserve complete API/facet/layout uncertainty; correct only declaration visibility |
| `by-file/ImageLib.md` UID0000K2 | `91/90`; owner FILE; path `NexusTK/render/`; formal fields N/A | score/owner/path retained | Record current ImageLib.h incompleteness and complete class/API move; preserve child global output |
| `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md` UID00016G | `88/92`; owner/emitter `0000IN`; reconstructable true; position blank; exact CPP; H blank; Nested `0` | score/metadata/CPP/Nested retained; add exact H prototype | Exact stdcall declaration and DATFile.h consumer visibility; no body/name ownership change |
| `by-file/DATFile.md` UID0000IN | `89/92`; owner FILE; path `NexusTK/archive/`; formal fields N/A | score/owner/path retained | Record DATFile.h requirement and UID00016G prototype route |
| `by-global/g_useEpfAssets.md` UID0000SW | `88/90`; existing owner/emitter/source definition retained | no metadata/formal change | Add MapName as an extern consumer only if consumer inventory is maintained; no ownership transfer or duplicate definition |

No by-item, by-type, or by-resource page requires a separate edit: the relevant physical types/resources are already represented by the class/memory/global pages above. UiAssetModeRect pages were inspected and are explicitly excluded rather than edited.

## Score And Metadata Recommendation

| UID | Dated accepted pre-callback | Current physical post-callback | Reason not lower | Reason not higher |
| --- | --- | --- | --- | --- |
| 0000L2 | 86/86 | 94/95 | Complete whole-file inventory, exact source plan, dependencies, boundaries and generated audit | Original source file/header spelling is strongly inferred rather than symbol-proven |
| 00007P | 86/88 | 94/95 | Exact layout/vtables/inheritance/method inventory and complete CPP/H | Some private spellings inferred |
| 0002XC/0002XD | 88/91 each | 93/95 each | Exact bytes, six refs, singleton lifecycle and single definition | Original symbol absent in IDA before supervisor action |
| 0002BF | 87/91 | 92/93 | Complete 81-instruction body and source analogue | No inbound xref or pointer route proves runtime liveness |
| 0003XG | 86/90 | 94/95 | Two callers and exact full body | Private local/field spellings inferred |
| 0003XH | 86/90 | 93/95 | Exact resource teardown and compiler family | No direct caller; source cause inferred from vtable/compiler family |
| 0003XI | 86/89 | 94/95 | Exact vtable route and both complete branches | Original local spelling inferred |
| 0003XJ | 87/90 | 94/95 | Exact vtable, packet, conversion and redraw path | Original packet/local spelling inferred |
| 0003XK | 85/88 TRUE/emitting | 94/96 FALSE/non-emitting | Sole EH xref and exact compiler-only body | No original compiler metadata labels the helper |
| 0003XL | 85/90 | 94/97 | Exact two thunk adjustments and vtables | Compiler-generated, no source body |
| 0003XM | 86/90 | 94/96 | Exact deleting-wrapper behavior | Compiler-generated, no source body |
| 0003BZ | 87/92 | 94/97 | Exact decorated vtables/RTTI/slots | Compiler data, not independently authored source |
| 0003IL | 86/92 | 93/96 | Exact bytes and sole source use | Literal spelling known; source storage form inferred |
| 0001AK | 88/91 | 94/96 | Exhaustive split/index proof | Non-emitting aggregate |
| 0001AL | 86/92 | 86/92 | Current score already reflects mixed evidence index | Non-source aggregate remains ownerless |

Direct-file position metadata is part of this recommendation: UID00007P is position `10`, UID0002XC is position `20`, and the five class children retain positions `10/20/30/40/50` within UID00007P. No score or metadata row may reverse that compile-safe order.

Score-improvement attempts were not stopped at blocker descriptions. Raw liveness received xref/pointer checks and analogue comparison; ownership received three competing-source analyses; shared declarations were traced to physical generated headers and exact owning formal channels; wrapper/source classification used EH/vtable/delete behavior; data ownership used bytes/xrefs/consumers; generated incompleteness was physically read. Remaining caps are narrow evidentiary facts, not deferred investigation.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best current resolution | Remaining impact |
| --- | --- | --- | --- |
| Did the private raw helper execute in this build? | Function object, start/end xrefs, raw pointers, body, field lifecycle, neighboring source analogues | Retained private `DrawNumberGlyphString`; liveness remains unproven but exact ownership/body are source-reconstructable | Caps UID0002BF confidence at 93; does not justify blank C++ |
| What were the exact private member/local spellings? | Offsets, producers/consumers, project naming, accepted neighboring classes | Use `m_mapNameText`, `m_mapNameImage`, `m_mapNameGlyphs`, `glyphDataSize`, `mapNameBytes`; mark inferred | Caps final-audit certainty; raw IDA names are not allowed in finalized source |
| Was the declaration in a dedicated header? | Existing by-file basename/path, external global consumer, generated include conventions, complete class dependency | Generate dedicated `map/MapNamePane.h` | Strong inference; no generic future work |
| Should shared Event/ImageLib declarations stay in CPP? | by-file self-contained-header contracts and physical missing/incomplete generated H | Move exact complete declarations to H, CPP include + children | Closed; preserving CPP-only declarations would make MapName consumer invalid |
| Should compiler helpers emit C++? | EH-only xref, secondary-base adjustments, delete flags, decorated vtables | No. Human virtual destructor/inheritance regenerate them | Closed with exact no-code proof |

There are no unanswered actionable questions. The only residuals are original-spelling and raw-helper-liveness confidence caps whose highest-probability source dispositions are already supplied.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 inspected every current manual row for the primary target and every affected support page. B003 must never edit these collision-prone files. The supervisor applies the following exact rows only after accepted ordinary documentation changes are physically verified.

Historical handoff disposition: the exact requested text below is retained unchanged as the accepted supervisor handoff evidence. The supervisor subsequently completed its semantic dispositions under commands `000000022993`-`000000022996`, preserving later valid additive coverage detail where present. Section 31 preserves those dated command receipts and a separate read-only `2026-08-13T07:14:28-04:00` by-memory snapshot at SHA `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, 2,211,023 bytes/4,936 lines, after unrelated accepted UID0004HB supervisor work. That snapshot is not permanent current authority; every Gate must reread the physical coverage file. No further C0L2-047-C0L2-052 edit is pending from this report.

**`by-file/-coverage-report.md`: replace UID0000L2 row at its existing location with:**

`- [UID:0000L2][MapNamePane](by-file/MapNamePane.md) : reconstructable : 94% : very-strong : Complete standalone NexusTK/map/ MapNamePane.cpp/.h unit with one singleton definition, exact 0x224 Pane/Singleton class layout, retained raw 9x11 glyph renderer, constructor/destructor/OnPaint/packet-handler source bodies, compiler-only EH/thunk/scalar/vtable exclusions, exact MiniMap split, resource/global ownership, complete header/dependency closure, and generated CPP/H verification contract.`

**`by-class/-coverage-report.md`: replace the four existing rows with:**

`- [UID:00007P][MapNamePane](by-class/MapNamePane.md) : reconstructable : 94% : very-strong : Exact 0x224 Pane plus empty Singleton class with m_mapNameText[128], EPFTileContext, glyph-buffer pointer, complete guarded H declaration, CPP child shell, one global extern, five authored methods, three vtables, and compiler-only destructor-family exclusions.`

`- [UID:0000A2][Pane](by-class/Pane.md) : reconstructable : 92% : very-strong : Base UI Pane emitted as a complete header declaration with exact mode-taking explicit Pane(unsigned char) constructor, 18-slot primary virtual surface through +0x44 OnPaint, secondary EventHandler and tertiary TimerHandler contracts, bounds/origin/mode state, source-ready children, and compiler exclusions.`

`- [UID:00004L][Event](by-class/Event.md) : reconstructable : 94% : very-strong : Self-contained ui/core/Event.h declaration with exact LObject base include, 0x110 Event object, 0x108 payload union, complete EventType/key/modifier enums, pointer/key/text/IME/packet/notification variants, exact source field order, and CPP child implementation route.`

`- [UID:00006E][ImageLib](by-class/ImageLib.md) : reconstructable : 89% : very-strong : Self-contained render/ImageLib.h declaration with exact LObject base, list-backed 0x14 layout, complete non-virtual resource lookup API, ResourceLayoutTable typedef facet, g_pEPFLib extern, child-generated load-error global, lifecycle children, and preserved original-facet-spelling confidence cap.`

**`by-global/-coverage-report.md`: replace UID0002XC row with:**

`- [UID:0002XC][g_pMapNamePane](by-global/g_pMapNamePane.md) : reconstructable : 93% : very-strong : One external MapNamePane singleton definition initialized to NULL, exact four-byte storage child [UID:0002XD], six live publish/clear/consumer xrefs, class-header extern declaration, direct-file source position 20 after [UID:00007P], and no duplicate storage emission.`

**`by-memory/-coverage-report.md`: replace existing UID0002BF, UID0001AK, UID0001AL, UID00016G, UID00029X, and UID0002XD rows with:**

`        - [UID:0002BF][0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw](by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md) 0x00503110-0x005031e1 | method | MapNamePane::DrawNumberGlyphString : reconstructable : 92% : strong : Exact retained 81-instruction 9x11 glyph renderer with space/slash skip, nine-pixel advance, glyph-row formula, m_mapNameGlyphs source, source-ready C++, exact retn/padding boundary, accepted source analogue, and preserved no-inbound-xref confidence cap.`

`    - [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md) 0x005031f0-0x0050395f | class aggregate | MapNameAndMiniMapButtonPanes : non-reconstructable : 86% : very-strong : Ownerless mixed evidence index containing eight MapNamePane and eight MiniMapButtonPane modeled starts plus exact gaps; no single parent/emitter or aggregate C++ is valid.`

`    - [UID:0001AK][0x005031f0-0x005038fe.MapNamePane](by-memory/0x005031f0-0x005038fe.MapNamePane.md) : non-reconstructable : 94% : very-strong : Non-emitting exact MapNamePane split index over constructor, destructor, OnPaint, packet handler, compiler EH clear, two adjustor thunks, scalar deleting destructor, every padding gap, and interleaved MiniMap exclusions; source is emitted only by exact children through UID00007P.`

`    - [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) : reconstructable : 88% : very-strong : DAT-backed allocated file-buffer loader with exact stdcall CPP body and DATFile.h prototype, prefix zero-fill, payload read, allocator contract, ten callers, and covered alias exclusions.`

`    - [UID:00029X][0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals](by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md) 0x0069b4b4-0x0069b4c8 | mixed global-data cluster | MapNameMiniMapAndGameServerGlobals : non-reconstructable : 88% : strong : Parentless mixed-owner map UI singleton and game-server cluster split into exact four-byte children; current bytes are zero/null rather than the superseded historical 0xffffffff claim, and direct children carry owner/emitter routes.`

`        - [UID:0002XD][0x0069b4b4-0x0069b4b8.g_pMapNamePane](by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md) 0x0069b4b4-0x0069b4b8 | global pointer | g_pMapNamePane : reconstructable : 93% : very-strong : Exact four-byte null MapNamePane singleton storage, six publish/clear/consumer xrefs, one source definition owned by UID0002XC, covered-by formal route, and current fragmented-head IDA repair contract.`

**Insert the following exact child/data rows in address order beneath the UID0001AK/UID0001AL MapName family:**

`        - [UID:0003XG][0x005031f0-0x005032c3.MapNamePaneConstructor](by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md) 0x005031f0-0x005032c3 | constructor | MapNamePane::MapNamePane : reconstructable : 94% : very-strong : Exact Pane(1), Singleton publication/vptr lowering, EPFTileContext initialization, empty text, conditional MAPNAME.EPF lookup and 9X11FONT.BIN load, two callers, source-ready C++, and compiler-EH exclusion.`

`        - [UID:0003XH][0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor](by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md) 0x005032d0-0x0050334d | destructor | MapNamePane::~MapNamePane : reconstructable : 93% : very-strong : Exact source-authored optional glyph-buffer release through MemoryMan with compiler vptr/Singleton/base teardown excluded and source-ready C++.`

`        - [UID:0003XI][0x00503350-0x0050349f.MapNamePaneOnPaint](by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md) 0x00503350-0x0050349f | method | MapNamePane::OnPaint : reconstructable : 94% : very-strong : Exact vtable paint route with unconditional allocator lookup, MAPNAME.EPF/FRMPART.PAL centered double-draw path, fallback fill/text path, modes/colors/coordinates, and source-ready C++.`

`        - [UID:0003XJ][0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket](by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md) 0x005034a0-0x00503574 | method | MapNamePane::HandlePacketEvent : reconstructable : 94% : very-strong : Exact secondary-vtable Event handler for opcode 0x15, packet bytes 9/10, 256-byte copy, CP_ACP conversion, preserved length-128 terminator edge, 173-pixel ellipsis, invalidation, and false return.`

`        - [UID:0003XK][0x005037f0-0x005037fb.MapNamePaneClearSingleton](by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md) 0x005037f0-0x005037fb | compiler helper | MapNamePane constructor-unwind Singleton clear : non-reconstructable : 94% : very-strong : Exact 11-byte compiler EH cleanup with sole constructor cleanup xref; no standalone source body/emitter.`

`        - [UID:0003XL][0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks](by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md) 0x0050380b-0x00503821 | compiler thunks | MapNamePane deleting-destructor adjustors : non-reconstructable : 94% : very-strong : Exact EventHandler -0xa0 and TimerHandler -0xa4 adjustor jumps to the scalar deleting destructor; declaration-generated with no source body.`

`        - [UID:0003XM][0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor](by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md) 0x00503840-0x005038fe | compiler wrapper | MapNamePane scalar deleting destructor : non-reconstructable : 94% : very-strong : Exact primary-vtable deleting wrapper with 0x224 size guard, ordinary destructor call and conditional operator delete; declaration-generated with no source body.`

`    - [UID:0003BZ][0x0061e5b4-0x0061e63c.MapNamePaneVtableData](by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md) 0x0061e5b4-0x0061e63c | vtable/RTTI data | MapNamePane three-vtable family : reconstructable : 94% : very-strong : Exact decorated primary/EventHandler/TimerHandler vtables, RTTI, slot targets, vptr xrefs, and neighboring boundaries; regenerated by class inheritance/virtual declarations with blank standalone C++.`

`    - [UID:0003IL][0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString](by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md) 0x0061e6c0-0x0061e6d8 | UTF-16 literal | MAPNAME.EPF : reconstructable : 93% : very-strong : Exact constructor-only resource literal bytes/xref covered by MapNamePane constructor source with no standalone definition.`

UID00044U's existing manual row is absent. Insert in address order at `0x00610fa4`: `    - [UID:00044U][0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString](by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md) 0x00610fa4-0x00610fbc | UTF-16 literal | FRMPART.PAL shared palette name : reconstructable : 89% : very-strong : Exact shared literal with three FrameChrome/MapName/MiniMap consumers; MapName uses the literal directly and is not a standalone comment emitter, while the remaining evidence routes are preserved.`

Reason B003 did not apply these rows: every `-coverage-report.md` file is supervisor-only shared state. The completed coverage edits and validation commands are credited only to the supervisor. Generated `auto-generated/-ag-*` trackers are validator-owned and receive no manual text here.

## Follow-Up Actions

- Supervisor: perform a fresh exact-artifact Gate 1 on this post-callback report, then independent claim-by-claim Gate 2A against the current destination hashes and validator receipts.
- Ordinary B003 callback is complete: 25 initial changed by-* destinations were JIT-leased, updated, scoped-validated with generated refresh disabled, physically reread, and released; UID0001AL was verified already present and byte-identical. Gate 2A remediation subsequently corrected/revalidated `by-file/Pane.md`, UID0003BZ, UID0003IL, `by-file/MapNamePane.md`, and `by-class/Pane.md` under the receipts below.
- Dated supervisor Gate 2B preflight on canonical session `supervisor-uid0002OW-gate2b-20260813T0115Z` failed closed before backup, mutation, or save because its I0L2-03 `_DWORD *`/decompiler-`Pane *` split and partial I0L2-10 display-state model required reconciliation. Latest dated canonical read-only checkpoint `supervisor-uid0004HB-gate2b-20260813T1105Z` supersedes those affected prestates: I0L2-03 is stored/decompiled `Pane *`; I0L2-05 retains `_WORD *` because no exact EventHandler UDT resolves; I0L2-09 is `Pane *`; I0L2-10 has a blank stored name and generated-only `unk_69B4B4`; I0L2-11/I0L2-12 expose aliases `aMa_8`/`aFr_5` and stable split reads. Neither checkpoint performed backup, mutation, or save.
- Supervisor Gate 2B: after fresh exact-artifact Gate 1, independently apply or reject I0L2-01-I0L2-13 using fresh authority/current prestates and external backup/save/persisted-readback controls. I0L2-03 must match current `Pane *`; I0L2-05 must match `_WORD *`, Event size `0x110`, and unresolved EventHandler UDT; I0L2-09 must match current `Pane *`; I0L2-10 must match blank stored name/generated-only alias; and I0L2-11/I0L2-12 must match their exact aliases, stable reads, spans, bytes, xrefs, comments, and neighbors before any action.
- Supervisor: Section 28 manual coverage dispositions are complete under commands `000000022993`-`000000022996`. During independent Gate 2A, physically reread the then-current MapNamePane.cpp/MapNamePane.h/support headers and separately reread/hash the live generated tracker; repeat both at the mandatory post-move audit. Dated command `000000023008` is only the `2026-08-12T22:25:26-04:00` coherent generated/tracker snapshot, and historical command `000000022981` is only the earlier remediation receipt. Gate-time readback must confirm that no empty marker, missing member, duplicate compiler body, MiniMap body, documentation-only palette comment, or stale manual row exists.
- A-agent actions: none. C-agent actions: none. B003 future research: none unless the supervisor returns exact Gate 1 or Gate 2A defects.
- Report execution/archive state is never inferred from this prose; current path and validator-owned status/history metadata remain authoritative.

## Confidence

- Recommendation confidence: very strong for the physically implemented class/file/global ownership, complete inventory, compiler/source split, formal method behavior, source order, and header dependencies; strong for exact private names and dedicated-header source shape.
- Score confidence: strong. The physical `94/95` file score reflects complete ordinary source-quality closure while retaining a meaningful cap for unproved original spellings and raw-helper liveness.
- Remaining uncertainty: only original private spellings and runtime reachability of retained raw `0x503110`; neither leaves an implementation decision unanswered.

## Validator Results

- The initial callback validated 25 changed ordinary destinations from `source-3/project-documentation` with the scoped file command form `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --no-generated-refresh`; all exited `0` with `ok:1`. The first Gate 2A remediation validated `by-file/Pane.md` with command `000000022979`, UID0003BZ with command `000000022980`, and UID0003IL with historical command `000000022981 --wait-generated` at `2026-08-12T20:09:34-04:00`; all exited `0` with `ok:1`, and the last command completed the then-current validator-owned refresh. The follow-up Gate 2A remediation validated `by-file/MapNamePane.md` with `000000022991` and `by-class/Pane.md` with `000000022992`, both exit `0`, `ok:1`, and generated refresh skipped. Dated validator command `000000023008` at `2026-08-12T22:25:26-04:00` recorded the later coherent generated CPP/H and tracker snapshots below; it is not permanent current authority. Current generated CPP/H requires physical Gate-time reread, and lifecycle-sensitive tracker truth requires a separate physical reread/hash at every Gate and mandatory post-move audit. Validator-owned projected statistics, registry/reference state, generated CPP/H, and generated reports were updated only as reported side effects. Listed missing-reference warnings pre-existed in destination documentation and did not invalidate the scoped file. Every ordinary hash in the following table is the dated identity tied to its listed validator receipt, not a claim of permanent current identity.

| Destination | Command / timestamp | Result and warnings | Dated post-validation receipt SHA256 |
| --- | --- | --- | --- |
| `by-file/MapNamePane.md` | historical `000000022832`; remediation `000000022991`, `2026-08-12T21:52:47-04:00` | exit 0; ok 1; 3 `missing_ref_uid` for UID0003C1; standalone-placement line corrected; generated skipped | `8034083E6694E0FBDA66D5E0C4B0DA3200249C6EAD9463589B1A0379AF543B31` |
| `by-class/MapNamePane.md` | `000000022833`; `2026-08-12T15:23:58-04:00` | exit 0; ok 1; 22 `missing_ref_uid`; generated skipped | `B6D3BB44C56B24151BD50F4FBAA923E82CCD53C36841F90ADEEB0F3A22764BDF` |
| `by-global/g_pMapNamePane.md` | `000000022834`; `2026-08-12T15:24:50-04:00` | exit 0; ok 1; generated skipped | `241F22FA3FC1FC5444E90C54E6A688367B93D67FE39314C1ACEF3F0F6B18940E` |
| `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md` | `000000022835`; `2026-08-12T15:25:37-04:00` | exit 0; ok 1; generated skipped | `EB2DC3DC61CFD6DAFED822B90BCAD5AB3CF3E925FC455E7A0FA2DB4A79FB5815` |
| `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` | `000000022836`; `2026-08-12T15:27:05-04:00` | exit 0; ok 1; generated skipped | `09924E122B131C4686D8E422DE0A5AD5F74282C2E6D4529F38E58014BA93F4CC` |
| `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md` | `000000022837`; `2026-08-12T15:28:01-04:00` | exit 0; ok 1; 2 `missing_ref_uid` for UID0003IL; generated skipped | `3C92960E0BF09C49E4901E054C423E9C283DEE41E2F74236E21937FB8A567F9D` |
| `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md` | `000000022838`; `2026-08-12T15:28:51-04:00` | exit 0; ok 1; 2 `missing_ref_uid` for UID0003XM; generated skipped | `CD3316419C7F7FD42D85D9BD42A39110FF0502EBC757906D7D33707490FD3713` |
| `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md` | `000000022839`; `2026-08-12T15:29:42-04:00` | exit 0; ok 1; generated skipped | `66D5F9A363F38E01906B736F99376CFAFDE76AF9075DA40D01CBE93C6E6E020C` |
| `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md` | `000000022840`; `2026-08-12T15:30:44-04:00` | exit 0; ok 1; generated skipped | `5E384B693D1C9A0792D77D5831E5810F2ADE5A8CFA868458A411BBD307BDB322` |
| `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md` | `000000022841`; `2026-08-12T15:31:43-04:00` | exit 0; ok 1; generated skipped | `14B5C775D566590D85EF43D74F500010819EDA0D2EC9FE9E14C0560ECC6973EC` |
| `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md` | `000000022842`; `2026-08-12T15:32:19-04:00` | exit 0; ok 1; 2 `missing_ref_uid` for UID0003XM; generated skipped | `09810D4E8AA09EDE3E53C06487309058997E117501C3C8A7BF16E8F1B31928EF` |
| `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md` | `000000022843`; `2026-08-12T15:35:59-04:00` | exit 0; ok 1; generated skipped | `E60FE8F4F3C80A3A7CC9C903AE288C35C33BA44215159E0BD1DE49B5061501D9` |
| `by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md` | historical `000000022844`; remediation `000000022980`, `2026-08-12T20:09:27-04:00` | exit 0; ok 1; comment-only CPP registered; generated skipped for ordered refresh | `0D0EE4C70AB6E73533F89237EA52494E4ADC237AC73D54319E8DF0EF95DF3971` |
| `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md` | historical `000000022845`; historical remediation `000000022981`, `2026-08-12T20:09:34-04:00` | exit 0; ok 1; 4 `missing_ref_uid` for UID0003C1; comment-only CPP registered; generated completed for that dated receipt | `B582FD96D578D9D761A60986016A3F06CF93099667A89DFF362E889FFE2BD6F1` |
| `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` | `000000022846`; `2026-08-12T15:36:07-04:00` | exit 0; ok 1; generated skipped | `2D3676BCF7EA75AECC64B7BDC7BD31BBF73A378BADEAC371A2B098593C01E136` |
| `by-memory/0x005031f0-0x005038fe.MapNamePane.md` | `000000022847`; `2026-08-12T15:36:09-04:00` | exit 0; ok 1; generated skipped | `86A152C8A0D526953A3147BBCBCF7FA5C4F7DB66B34440698BB392CADB345763` |
| `by-class/Pane.md` | historical `000000022848`; remediation `000000022992`, `2026-08-12T21:52:54-04:00` | exit 0; ok 1; exact `Pane(1)` statement; generated skipped | `48FB46E50E864A9F179BE287BE1A1DA2AB190F967CDC87F5D3CB82CE279330BA` |
| `by-file/Pane.md` | historical `000000022849`; remediation `000000022979`, `2026-08-12T20:08:21-04:00` | exit 0; ok 1; exact `Pane(1)` note; generated skipped | `98CEF76E8AB5BA9FE6E05B30D1F59810D56FA26FD777584506FF11DC17EDE2DA` |
| `by-class/Event.md` | `000000022850`; `2026-08-12T15:40:16-04:00` | exit 0; ok 1; generated skipped | `6D93F1910E7DC777E87E1C92B7C92023D3808BDFD4A8BE74CBC5C9F2F1D2D162` |
| `by-file/Event.md` | `000000022851`; `2026-08-12T15:40:18-04:00` | exit 0; ok 1; 2 `missing_ref_uid` for UID0003LV; generated skipped | `8BE23BC4CFB1E97554494B0CEE18A63D75492EEBB7EE946CAB1074A4D4BFE700` |
| `by-class/ImageLib.md` | `000000022852`; `2026-08-12T15:41:15-04:00` | exit 0; ok 1; generated skipped | `E00A14094E80869B01CD21A0EB3DC57198E0D6FB9345AED62B315EC3653C3B41` |
| `by-file/ImageLib.md` | `000000022853`; `2026-08-12T15:41:18-04:00` | exit 0; ok 1; generated skipped | `8069CF0F180F95C02FCB80B31B3C0BED2FB967D44E8F08C32D73E9EBBA859F04` |
| `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md` | `000000022854`; `2026-08-12T15:41:54-04:00` | exit 0; ok 1; generated skipped | `867D95B71C6CB025DD625A7A4E937376A80C5DA6534E072918E9430A2B976F9A` |
| `by-file/DATFile.md` | `000000022855`; `2026-08-12T15:41:57-04:00` | exit 0; ok 1; 4 `missing_ref_uid` for UID0003B7; generated skipped | `7951F8761E607BA1C0BB0084935F1F6AD61E42FC9B77377FF5DD7E3299576BB1` |
| `by-global/g_useEpfAssets.md` | `000000022857`; `2026-08-12T15:42:36-04:00` | exit 0; ok 1; generated skipped | `30EC0C5BCB8EBF47D4B4AF3BDA0ABD491C2F3418E15B6FA8771F0C7BD37844B5` |

- Separate read-only currentness-repair snapshot, not permanent authority: at `2026-08-13T07:14:28-04:00`, `by-global/g_useEpfAssets.md` was SHA `648999EA0538B6AFEDD2B8912C6618C327DCF4A234024CEA7B06462C73982D39`, 27,258 bytes/198 lines. The dated command `000000022857` identity above remains historical receipt evidence; every Gate must physically reread the destination.

- Already-present destination: `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` remained byte-identical at SHA `C6B4F52736ACEA6B2BF57D17F4718AC07BEFCC4B51D2DC35AA3EE23767F18EA7`, 21,621 bytes, with the complete sixteen-start owner/exclusion and padding inventory; no lease, edit, or validator was required.
- Historical generated readback from command `000000022981` at `2026-08-12T20:09:34-04:00` recorded the first complete output and is retained only as a dated receipt. Dated coherent generated/readback snapshot from command `000000023008` at `2026-08-12T22:25:26-04:00`: `MapNamePane.cpp` SHA `3E4DF33841609DED6B1B6CAD744FC56826D3F9DF00B7B2D9B912C514336F6584`, 5,170 bytes/150 lines, zero empty markers, exact UID0003BZ comment at line 144 and UID0003IL comment at line 147; `MapNamePane.h` SHA `16029F044F645366CEC7FEE5CD76FCA467311BEE260313EA485F3FB555E8E915`, 1,118 bytes/41 lines; `Event.h` SHA `7A3257AD63CAC26E7690D194EE22C1238769D27AC20444F9C3946B0F56D17A01`; `DATFile.h` SHA `1C729CF2E9F8688649D5EAE525F3604C05F444188DB6DFE2705ACBB03E69FEDA`; `ImageLib.h` SHA `F2FE77400C19E5BCF81C4B9CF0C609C717E404B9DC78040A7B0307199EB374D8`; and `Pane.h` SHA `CD291602A94C3C81E6ACBA4F3AFF30123F970B75D495ABD6E2C4505A25340F48`. Physical reread at that snapshot verified unchanged generated semantics: all five authored methods, the singleton definition, both exact no-code comments, zero empty markers, and the complete class/extern declaration. The same dated command recorded `auto-generated/-ag-research-tracker.md` SHA `89076FBF0DE4566C1E77546B9FA32D4B6105AEB52888AC30815B98884A082DFD`, 2,048,815 bytes/9,629 lines. That tracker identity is historical snapshot evidence only; every Gate and mandatory post-move audit must reread/hash the physical current tracker rather than reuse it.

- Supervisor-owned manual coverage closure, recorded without B003 edit or command credit:

| Coverage destination | Supervisor command | Result | Dated receipt or read-only repair snapshot; not permanent authority |
| --- | --- | --- | --- |
| `by-file/-coverage-report.md` | dated `000000022993` | exit 0; ok 1; generated refresh intentionally skipped; dated post-command SHA `C3644FB199C7DE965A92AEA8FF02A581833670593B977E18AF5917FC87B6DC8F` | At this report repair: `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`, 169,241 bytes; exact UID0000L2 row unchanged once after unrelated additive work; reread dynamically at every Gate |
| `by-class/-coverage-report.md` | dated `000000022994` | exit 0; ok 1; generated refresh intentionally skipped; dated post-command SHA `68BBB4638AE94068BCFE822C8CF0538B418A6DFD6F52A211FAC9B504B4C6DEEC` | At this report repair: `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`, 277,113 bytes; exact UID00007P/UID0000A2/UID00004L/UID00006E rows unchanged once each after unrelated additive work; reread dynamically at every Gate |
| `by-global/-coverage-report.md` | `000000022995` | exit 0; ok 1; generated refresh intentionally skipped | `B689A8B252FB7D24C3CADEF6F410636BB4A3EE81D5AEBEB9D96F130700E91A9A` |
| `by-memory/-coverage-report.md` | dated `000000022996` | exit 0; ok 1; generated refresh intentionally skipped; dated post-command SHA `BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C` | Read-only snapshot `2026-08-13T07:14:28-04:00`: `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, 2,211,023 bytes/4,936 lines after unrelated accepted UID0004HB supervisor work; all sixteen C0L2 inventory UIDs remain present exactly once; reread dynamically at every Gate |

## Changed Files

- Created during the initial report-only phase: this same `tools/leaser/Agents/Agent-B003/research/0000L2-MapNamePane-file-source-quality.md` report.
- Modified and physically revalidated during the accepted callback: `by-file/MapNamePane.md`; `by-class/MapNamePane.md`; `by-global/g_pMapNamePane.md`; `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md`; `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`; `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md`; `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md`; `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md`; `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md`; `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md`; `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md`; `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md`; `by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md`; `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md`; `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md`; `by-memory/0x005031f0-0x005038fe.MapNamePane.md`; `by-class/Pane.md`; `by-file/Pane.md`; `by-class/Event.md`; `by-file/Event.md`; `by-class/ImageLib.md`; `by-file/ImageLib.md`; `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md`; `by-file/DATFile.md`; and `by-global/g_useEpfAssets.md`. Gate 2A remediation then changed and revalidated `by-file/Pane.md`, UID0003BZ, UID0003IL, `by-file/MapNamePane.md`, and `by-class/Pane.md`.
- Verified already present and unchanged: `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md`.
- Renamed/moved: none.
- IDA/MCP mutations or saves: none by B003; all use was read-only.
- Coverage/generated/audit/goal/notes/lifecycle files: no B003 manual edits. Historical command `000000022981` performed the earlier authorized validator-owned refresh; dated command `000000023008` recorded the later coherent generated CPP/H and tracker snapshots in Section 31. Neither snapshot is permanent current authority: each Gate physically rereads generated CPP/H and independently rereads/hashes the lifecycle-sensitive current tracker, with both repeated after report movement. B003 did not edit those files directly. The supervisor subsequently applied and validated the four manual coverage destinations under commands `000000022993`-`000000022996`; those edits and commands are not B003 credit. No audit, goal, notes, or lifecycle file was edited by B003.
- Direct-file implementation physically applied: UID00007P position 10 followed by UID0002XC position 20; child positions are 10/20/30/40/50.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. B003 did not run `execute_report`, a lifecycle command, or manual movement.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0L2-001 | 0000L2 | Incorporate the complete whole-file inventory, behavior, boundaries, ownership, source order, exclusions, dependency closure, and generated-state audit. | very-strong | Canonical MCP plus current docs/generated audit in Sections 10-16. | `by-file/MapNamePane.md` all substantive sections | incorporate | applied |
| [x] | C0L2-002 | 0000L2 | Retain standalone `NexusTK/map/MapNamePane.cpp/.h`; reject MapPane.cpp, MiniMap, and generic UI ownership. | strong | Physical line 21 now states the standalone route and rejection explicitly; command `000000022991`, SHA `8034083E...543B31`. | `by-file/MapNamePane.md` source placement | incorporate | applied |
| [x] | C0L2-003 | 0000L2 | Raise by-file score from 86/86 to 94/95; by-file-only metadata remains FILE and `NexusTK/map/`. | strong | All known blockers investigated; formal whole-file closure supplied. | `by-file/MapNamePane.md` header and score rationale | incorporate | applied |
| [x] | C0L2-004 | 0000L2 | Replace stale blank-C++ blocker prose with current implementation-ready CPP/H and dependency state. | very-strong | Dated pre-remediation output had empty markers; historical command `000000022981` first proved closure, and dated command `000000023008` recorded unchanged complete CPP/H with zero markers. Current generated semantics require Gate-time physical reread; tracker truth is separately reread dynamically. | `by-file/MapNamePane.md` status/changes | historicalize | applied |
| [x] | C0L2-005 | 0000L2 | UID00007P CPP becomes exact include shell plus `[[CHILDREN]]`; H becomes complete guarded MapNamePane declaration. | strong | Pane 0xf8 plus text 0x100 plus EPF 0x28 plus pointer 4 equals 0x224. | `by-class/MapNamePane.md` formal CPP/H | incorporate | applied |
| [x] | C0L2-006 | 0000L2 | Raise UID00007P 86/88 to 94/95; retain owner/emitter 0000L2 and reconstructable true; set direct-file position 10 so its include/class/method material precedes the global definition. | strong | Exact vtables, layout, source methods, and compile-safe source route. | `by-class/MapNamePane.md` metadata/score | incorporate | applied |
| [x] | C0L2-007 | 0000L2 | Preserve UID0002XC's one CPP definition and route the extern declaration through MapNamePane.h, not duplicate storage. | very-strong | Six singleton refs and one external MapPane read require non-static linkage. | `by-global/g_pMapNamePane.md` formal/source placement | incorporate | applied |
| [x] | C0L2-008 | 0000L2 | Raise UID0002XC 88/91 to 93/95; retain owner/emitter 0000L2 and set direct-file position 20 after UID00007P. | strong | Exact null bytes, xrefs, owner, definition, external linkage, and compile-safe class-before-global order. | `by-global/g_pMapNamePane.md` metadata/score | incorporate | applied |
| [x] | C0L2-009 | 0000L2 | Preserve UID0002XD as covered-by global storage, raise 88/91 to 93/95, retain owner/emitter 0002XC and Nested 4. | strong | Four fragmented current heads represent one four-byte pointer and six xrefs. | `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md` | incorporate | applied |
| [x] | C0L2-010 | 0000L2 | Emit private `DrawNumberGlyphString` exact body from UID0002BF and set class-child position 10. | strong | Complete 81-instruction body, 0x220 field lifecycle, accepted analogous helpers. | `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md` formal CPP | incorporate | applied |
| [x] | C0L2-011 | 0000L2 | Raise UID0002BF 87/91 to 92/93; preserve owner/emitter 00007P, reconstructable true, Nested 0. | strong | Exact body/source role; no inbound xref caps confidence. | UID0002BF metadata/score | incorporate | applied |
| [x] | C0L2-012 | 0000L2 | Emit exact `MapNamePane::MapNamePane()` body from UID0003XG and set position 20. | very-strong | Two callers, three vptrs, exact fields/resources/branch. | `by-memory/0x005031f0-0x005032c3.MapNamePaneConstructor.md` formal CPP | incorporate | applied |
| [x] | C0L2-013 | 0000L2 | Raise UID0003XG 86/90 to 94/95; retain owner/emitter/reconstructable and Nested 8. | very-strong | Exact full-function behavior and direct callers. | UID0003XG metadata/score | incorporate | applied |
| [x] | C0L2-014 | 0000L2 | Emit exact ordinary `MapNamePane::~MapNamePane()` from UID0003XH and set position 30. | very-strong | Resource free and base-destructor route; compiler publication/base work excluded. | `by-memory/0x005032d0-0x0050334d.MapNamePaneNonDeletingDestructor.md` formal CPP | incorporate | applied |
| [x] | C0L2-015 | 0000L2 | Raise UID0003XH 86/90 to 93/95; retain owner/emitter/reconstructable and Nested 0. | strong | Exact full-function teardown; source cause proven by vtable wrappers. | UID0003XH metadata/score | incorporate | applied |
| [x] | C0L2-016 | 0000L2 | Emit exact `MapNamePane::OnPaint()` from UID0003XI and set position 40. | very-strong | Vtable slot and exact EPF/fallback drawing paths. | `by-memory/0x00503350-0x0050349f.MapNamePaneOnPaint.md` formal CPP | incorporate | applied |
| [x] | C0L2-017 | 0000L2 | Raise UID0003XI 86/89 to 94/95; retain owner/emitter/reconstructable and Nested 0. | very-strong | Full body, vtable identity, fields, resources, renderer APIs. | UID0003XI metadata/score | incorporate | applied |
| [x] | C0L2-018 | 0000L2 | Emit exact `bool MapNamePane::HandlePacketEvent(Event *)` from UID0003XJ and set position 50. | very-strong | Secondary vtable, Event payload, exact packet and conversion behavior. | `by-memory/0x005034a0-0x00503574.MapNamePaneHandleMapNameUpdatePacket.md` formal CPP | incorporate | applied |
| [x] | C0L2-019 | 0000L2 | Raise UID0003XJ 87/90 to 94/95; retain owner/emitter/reconstructable and Nested 0. | very-strong | Exact ABI/packet path and vtable route. | UID0003XJ metadata/score | incorporate | applied |
| [x] | C0L2-020 | 0000L2 | Reclassify UID0003XK as compiler construction-unwind cleanup: reconstructable false, emitter blank, CPP/H blank, position blank. | very-strong | Sole xref 0x6020b1 from constructor EH path; body only clears Singleton. | `by-memory/0x005037f0-0x005037fb.MapNamePaneClearSingleton.md` | reject-stale | applied |
| [x] | C0L2-021 | 0000L2 | Raise UID0003XK 85/88 to 94/96 while preserving Nested 8 and documenting exact no-code proof. | very-strong | Complete compiler-role proof and exact range. | UID0003XK metadata/score/history | incorporate | applied |
| [x] | C0L2-022 | 0000L2 | Keep UID0003XL non-reconstructable/non-emitting; raise 85/90 to 94/97 and preserve both exact thunk adjustments. | very-strong | Vtable-only +0xa0/+0xa4 thunks jump to scalar wrapper. | `by-memory/0x0050380b-0x00503821.MapNamePaneDestructorAdjustorThunks.md` | incorporate | applied |
| [x] | C0L2-023 | 0000L2 | Keep UID0003XM non-reconstructable/non-emitting; raise 86/90 to 94/96 and preserve delete-flag proof. | very-strong | Primary vtable plus thunk callers and operator-delete flag. | `by-memory/0x00503840-0x005038fe.MapNamePaneScalarDeletingDestructor.md` | incorporate | applied |
| [x] | C0L2-024 | 0000L2 | Keep UID0003BZ class-owned evidence with no standalone table/H definition; emit only the exact explanatory no-code CPP comment; raise 87/92 to 94/97. | very-strong | Three decorated vtables and RTTI regenerate from class inheritance/virtuals; command `000000022980` registered the comment-only formal. | `by-memory/0x0061e5b4-0x0061e63c.MapNamePaneVtableData.md` | incorporate | applied |
| [x] | C0L2-025 | 0000L2 | Keep UID0003IL as a constructor-covered literal with no standalone object/H definition; emit only the exact explanatory no-code CPP comment; raise 86/92 to 93/96. | very-strong | Exact UTF-16 bytes and sole constructor xref; historical command `000000022981` registered the comment-only formal, and dated command `000000023008` recorded the exact comment with no empty marker. Current generated state requires Gate-time physical reread. | `by-memory/0x0061e6c0-0x0061e6d8.MapNamePaneEpfResourceString.md` | incorporate | applied |
| [x] | C0L2-026 | 0000L2 | Remove UID0000L2 from UID00044U emitter list; preserve shared ownerless evidence and other routes; MapName uses literal in OnPaint. | strong | Three consumers and no standalone string object in source. | `by-memory/0x00610fa4-0x00610fbc.SharedFramePartPaletteResourceString.md` metadata/formal route | incorporate | applied |
| [x] | C0L2-027 | 0000L2 | Keep UID0001AK non-reconstructable/non-emitting split index; raise 88/91 to 94/96 and enumerate all exact children/gaps. | very-strong | Mixed methods/compiler glue/MiniMap holes cannot be one source block. | `by-memory/0x005031f0-0x005038fe.MapNamePane.md` | incorporate | applied |
| [x] | C0L2-028 | 0000L2 | Keep UID0001AL ownerless/non-reconstructable/non-emitting with current 86/92; add current complete exclusion inventory only. | very-strong | Sixteen starts split evenly by class families plus padding. | `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md` | already-present | already-present |
| [x] | C0L2-029 | 0000L2 | Correct Pane H constructor declaration from `Pane()` to `explicit Pane(unsigned char mode)` and record MapNamePane's exact `Pane(1)` initializer; preserve complete layout/API. | very-strong | Generated `MapNamePane.cpp:53`; `by-file/Pane.md` command `000000022979`; corrected `by-class/Pane.md:311` command `000000022992`, SHA `48FB46E5...9330BA`. | `by-class/Pane.md` formal H and `by-file/Pane.md` contract note | incorporate | applied |
| [x] | C0L2-030 | 0000L2 | Move complete Event declarations from CPP to guarded Event.h; CPP becomes include plus children without changing behavior/metadata. | very-strong | Dated pre-callback H was absent; historical command `000000022981` first generated the complete header, and dated command `000000023008` recorded it at SHA `7A3257AD...D17A01`. Current generated state requires Gate-time physical reread. | `by-class/Event.md` formal CPP/H and `by-file/Event.md` physical-state note | incorporate | applied |
| [x] | C0L2-031 | 0000L2 | Move complete ImageLib declaration from CPP to guarded ImageLib.h; CPP becomes include plus children. | very-strong | Dated pre-callback H lacked the class; historical command `000000022981` first generated the complete header, and dated command `000000023008` recorded it at SHA `F2FE7740...B374D8`. Current generated state requires Gate-time physical reread. | `by-class/ImageLib.md` formal CPP/H and `by-file/ImageLib.md` | incorporate | applied |
| [x] | C0L2-032 | 0000L2 | Add exact `LoadDatFileBuffer` prototype to UID00016G H channel and document DATFile.h consumer route. | very-strong | Dated pre-callback H was absent; historical command `000000022981` first generated the exact prototype, and dated command `000000023008` recorded DATFile.h at SHA `1C729CF2...E69FEDA`. Current generated state requires Gate-time physical reread. | `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md` H and `by-file/DATFile.md` | incorporate | applied |
| [x] | C0L2-033 | 0000L2 | Use source-root `extern bool g_useEpfAssets;` in MapNamePane.cpp; preserve UID0000SW as sole definition/owner. | strong | Established MapPane convention and broad global with no neutral shared header. | UID00007P CPP shell; `by-global/g_useEpfAssets.md` no-change note | already-present | applied |
| [x] | C0L2-034 | 0000L2 | Reject UiAssetModeRect helper adoption and preserve those pages outside MapNamePane. | very-strong | No class-field/vtable/resource/caller ownership edge. | UID0000L2 negative evidence and UID0002BF exclusions | reject-invalid | excluded-with-reason |
| [x] | C0L2-035 | 0000L2 | Exclude all eight MiniMapButtonPane modeled starts and their data from MapNamePane source. | very-strong | Independent constructor/global/vtables/helpers and exact starts. | UID0000L2 boundaries; UID0001AK/UID0001AL | reject-invalid | excluded-with-reason |
| [ ] | C0L2-036 | 0000L2 | IDA: define/name/type/comment the raw helper only after exact raw boundaries, MapNamePane type preconditions, and the complete raw physical frame matrix pass independent supervisor preflight; preserve every protected property and verify the exact expected readback. | strong | I0L2-01 exact 81-instruction prestate, EBP-relative matrix, declarative function/name/type/comment outcomes, and protected-state readbacks. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-037 | 0000L2 | IDA: rename/type/comment the constructor and rename only physical stack row `var_14` to `glyphDataSize` through the dedicated stack-variable action; protect every other frame row. | very-strong | I0L2-02 complete seven-row current/post matrix, four separate comment-channel prestates, exact intended deltas, and expected readbacks. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-038 | 0000L2 | IDA: rename/type/comment ordinary destructor while changing only the current stored ECX receiver type from `Pane *` to `MapNamePane *` after the UDT prerequisite passes and protecting all four physical frame rows. | very-strong | Latest canonical I0L2-03 stored and decompiled declaration is `void __thiscall(Pane *this)`; the earlier `_DWORD *` observation is historical. Three MapNamePane vptr writes, `+0x220` cleanup, singleton clear, `Pane__Destructor`, and the scalar wrapper justify the final derived receiver type. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-039 | 0000L2 | IDA: rename/type/comment OnPaint while changing only the ECX receiver type and preserving `length`, saved-register, and return-address rows. | very-strong | I0L2-04 complete current/post frame and comment-channel matrices plus vtable prestate. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-040 | 0000L2 | IDA: rename/comment the packet handler, narrow its return/argument metadata to `bool` and `Event *`, retain the exact physical `_WORD *` secondary-facet receiver, and rename only the three enumerated frame rows. | very-strong | I0L2-05 complete seven-row matrix; current `EventHandler` is pointer-kind size 4 with no exact UDT, so no `EventHandler *` receiver or declaration action is authorized. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-041 | 0000L2 | IDA: rename/comment construction-unwind clear helper without converting it to source-authored code; protect exact `void sub_5037F0(void)` declaration and one-row frame with no type/frame mutation. | very-strong | I0L2-06 exact declaration/frame/comments plus sole EH xref. | Supervisor Gate 2B IDA handoff | historicalize | proposed |
| [ ] | C0L2-042 | 0000L2 | IDA: rename/comment two adjustor thunks and replace stale `Block` address comments while protecting each exact `_DWORD *__thiscall (...)(_DWORD *this, char arg1)` declaration and one-row frame. | very-strong | I0L2-07/I0L2-08 exact declarations, frames, comments, and +0xa0/+0xa4 jumps. | Supervisor Gate 2B IDA handoff | historicalize | proposed |
| [ ] | C0L2-043 | 0000L2 | IDA: rename/comment scalar deleting destructor with deterministic no-change protection for `Pane *__thiscall sub_503840(Pane *Block, char)` and its complete five-row frame. | very-strong | Latest canonical I0L2-09 stored/decompiled declaration, exact frame, wrapper/deletion path, two thunk callers, and primary-vtable route. | Supervisor Gate 2B IDA handoff | historicalize | proposed |
| [ ] | C0L2-044 | 0000L2 | IDA: materialize/name/type/comment one four-byte `g_pMapNamePane` item from four current one-byte heads whose stored name is blank; never treat Hex-Rays-generated `unk_69B4B4` as a resolvable old name. | very-strong | I0L2-10 exact blank name-index/item prestate, generated-only alias, four heads, types, bytes, refs, comment channels, tail/neighbor protections, and destination collision proof. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-045 | 0000L2 | IDA: consolidate/name/type/comment the fragmented MAPNAME.EPF literal; consume the exact `off_61E6C0`/blank/`aAmeEpf_0` item fragments and name-index alias `aMa_8`, while protecting exact bytes, xref, and neighbors. | very-strong | I0L2-11 exact spans plus stable reads `MA`, `P`, and `AME.EPF`; final readback requires one 24-byte `MAPNAME.EPF` item. | Supervisor Gate 2B IDA handoff | incorporate | proposed |
| [ ] | C0L2-046 | 0000L2 | IDA: preserve FRMPART.PAL shared fragments/alias, bytes/xrefs, and all three vtable bases with no mutation. | very-strong | I0L2-12 protects display names `off_610FA4`/`aMpartPal`, alias `aFr_5`, stable reads `FR`/`MPART.PAL`; I0L2-13 protects exact decorated bases and key slots. | Supervisor Gate 2B IDA handoff | already-present | proposed |
| [x] | C0L2-047 | 0000L2 | Provide exact manual by-file coverage replacement for UID0000L2. | strong | Dated supervisor command `000000022993`, exit 0/ok 1/generated skipped, recorded post-command SHA `C3644FB199C7DE965A92AEA8FF02A581833670593B977E18AF5917FC87B6DC8F`. At this report repair, the current physical aggregate is SHA `02A44EDBAAA596D59ECE589D05E6BF57553C3DCA5AD7EAE0E1369C567344E756`, 169,241 bytes, after unrelated additive coverage work; the exact standalone UID0000L2 94% row remains present once. Future Gate authority requires a fresh physical reread. | `by-file/-coverage-report.md` supervisor-only | incorporate | applied |
| [x] | C0L2-048 | 0000L2 | Provide exact manual by-class coverage replacements for UID00007P and support declaration pages. | strong | Dated supervisor command `000000022994`, exit 0/ok 1/generated skipped, recorded post-command SHA `68BBB4638AE94068BCFE822C8CF0538B418A6DFD6F52A211FAC9B504B4C6DEEC`. At this report repair, the current physical aggregate is SHA `FF87AEF9714FF85284A51ACDB1ADC7171395DD926C44D78260A7CF8074A232E0`, 277,113 bytes, after unrelated additive coverage work; the exact UID00007P/UID0000A2/UID00004L/UID00006E rows remain present once each. Future Gate authority requires a fresh physical reread. | `by-class/-coverage-report.md` supervisor-only | incorporate | applied |
| [x] | C0L2-049 | 0000L2 | Provide exact manual by-global coverage replacement for UID0002XC. | strong | Supervisor command `000000022995`, exit 0/ok 1/generated skipped; physical SHA `B689A8B2...E91A9A` contains the 93% singleton row. | `by-global/-coverage-report.md` supervisor-only | incorporate | applied |
| [x] | C0L2-050 | 0000L2 | Provide exact manual by-memory replacement/insertion rows for raw/helper/method/compiler/vtable/resource/storage inventory. | strong | Dated supervisor command `000000022996`, exit 0/ok 1/generated skipped, recorded post-command SHA `BD69D1C1B92DD2840D1D91DA909725366B9538051472A91D25DF1EB884E98F1C`. Read-only repair snapshot `2026-08-13T07:14:28-04:00`: SHA `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, 2,211,023 bytes/4,936 lines after unrelated accepted UID0004HB supervisor work; all sixteen C0L2 inventory UIDs remain present exactly once. This snapshot is not permanent authority and requires fresh Gate-time physical reread. | `by-memory/-coverage-report.md` supervisor-only | incorporate | applied |
| [x] | C0L2-051 | 0000L2 | Preserve UID0001AL manual row except exact current non-reconstructable wording; do not call it reconstructable. | very-strong | Supervisor command `000000022996`; current physical UID0001AL row says `non-reconstructable` and retains ownerless mixed-index evidence. | `by-memory/-coverage-report.md` UID0001AL | reject-stale | applied |
| [x] | C0L2-052 | 0000L2 | Correct UID00029X/UID0002XD manual historical 0xffffffff wording to current zero/null storage. | very-strong | Supervisor command `000000022996`; current physical rows state zero/null and retain the former 0xffffffff interpretation only as superseded history. | `by-memory/-coverage-report.md` global cluster rows | reject-stale | applied |
| [x] | C0L2-053 | 0000L2 | Validate every changed ordinary by-* destination: initial callback pages use scoped `--no-generated-refresh`; Gate 2A remediation uses historical commands `000000022979`-`000000022981` plus exact follow-up commands `000000022991`-`000000022992`. | very-strong | All ordinary/remediation receipts remain historical in Section 31. Dated command `000000023008` is a later generated/readback snapshot, not permanent tracker authority; the current tracker must be reread and hashed at every Gate and mandatory post-move audit. | Report Validator Results and callback receipts | incorporate | applied |
| [x] | C0L2-054 | 0000L2 | Complete one coherent validator-owned generated refresh and physically verify complete MapNamePane.cpp and MapNamePane.h with zero empty-emitter markers. | very-strong | Dated command `000000023008` snapshot: CPP SHA `3E4DF338...F6584`, H SHA `16029F04...E915`; exact methods, comments, class/extern declaration, and zero markers were physically reread with semantics unchanged. Current generated state requires fresh Gate-time physical reread. | Validator-generated `auto-generated/NexusTK/map/MapNamePane.cpp/.h` readback | incorporate | applied |
| [x] | C0L2-055 | 0000L2 | Preserve all corrected historical assumptions and rejected alternatives rather than pruning them. | very-strong | Rule 26 no-loss standard. | Every affected target/support history section | incorporate | applied |
| [x] | C0L2-057 | 0000L2 | Preserve the shared `L"..."` item `[0x61066c,0x610674)` as exact `HandlePacketEvent` source-use evidence while rejecting a standalone MapName definition, ownership transfer, emitter route, or additional target declaration. | very-strong | Eight exact UTF-16LE bytes, one `const wchar_t[]` item, 23 head xrefs, no interior xrefs, and MapName operand `0x503531` before `GrafPort::FitTextAndAppendSuffix`; the formal CPP already uses the literal. | `by-file/MapNamePane.md` whole-file resource/xref/packet-behavior inventory | incorporate | applied |

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact pre-callback SHA `D09FEDD8579E1ED8EEBAA937D801DBA6B6A804D5C9AFBD880ECE3B61B5EFB34C` at `33/33` before implementation.
- [x] For a by-file target, exhaustive whole-file inventory completed and reconciled against IDA, all related by-* pages, generated output, and matching reports; every function and every other code/data/type/resource/range item has an evidence-backed disposition rather than a sampled-subset or generic future-work entry.
- [x] For a by-file target, every file-owned inventory item has explicit behavior/role, ownership/emitter/source placement, CPP/H or no-code, metadata/score, destination doc, Claim And Incorporation Ledger, and Implementation Tracking Checklist coverage as applicable; excluded candidates have evidence-backed reasons.
- [x] For a by-file target, current generated `.cpp`/`.h` audited against the inventory and every missing/incomplete function, code path, data definition, declaration/type/include/forward declaration, child route/order defect, empty marker, and required-but-missing header has an exact formal CPP/H repair or evidence-backed no-code disposition.
- [x] Target/support docs to update are exhaustively enumerated in Sections 24-25.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable because additional target UIDs are explicitly none.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every claim.
- [x] Metadata/score changes to apply are exact in Sections 24-26.
- [x] Score-limiting blockers researched to resolution or a narrow evidence-backed confidence cap after all reasonable current routes were exhausted.
- [x] Owner/emitter/reconstructable changes to apply are exact in Section 25.
- [x] Split/rename/new-child changes to apply: no new child page; exact reclassification and exclusions are recorded, with direct-file UID00007P position 10 before UID0002XC position 20 and child positions 10/20/30/40/50.
- [x] Source-placement, compile-safe emitter order, range/split/padding/reclassification, shared-ellipsis source-use, and exact IDA rename/type/comment/frame handoffs are represented completely in the report; I0L2-03 protects current stored/decompiled `Pane *`, I0L2-05 retains `_WORD *` because no exact EventHandler UDT resolves, I0L2-09 protects current `Pane *`, I0L2-10 distinguishes the blank stored name from generated-only `unk_69B4B4`, and I0L2-11/I0L2-12 preserve aliases `aMa_8`/`aFr_5` plus stable split reads, while all mutation remains supervisor-owned.
- [ ] Supervisor Gate 2B IDA handoff lists every exact address/entity, pre-state, proposed action, supporting type, safety constraint, and expected readback; this remains unchecked for the supervisor to apply/verify.
- [x] First-draft CPP/H text or exact no-standalone-code proof is complete for every inventoried item, including the shared `L"..."` literal represented only by its exact `HandlePacketEvent` source use.
- [x] Third-party import directive is target-specifically not applicable; no `third_party_embeds/` path applies.
- [x] Exact target/support doc facts to incorporate are supplied at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Wave2/Wave3 evidence was ignored as stale; none was used.
- [x] Open questions are resolved or narrowed to evidence-backed nonblocking confidence caps.
- [x] Validators to run are enumerated without running them in report-only phase.
- [x] Generated refresh/readback expectations and exact manual supervisor-owned coverage text are supplied.

Implementation callback pass:
- [ ] Supervisor-owned IDA changes remain supervisor-owned and were not applied by B003.
- [x] For a by-file target, all accepted ordinary whole-file inventory claims incorporated and physically reread across every destination.
- [x] Every accepted ordinary formal CPP/H/declaration/routing repair applied; Gate 2A remediation added exact no-code comments for UID0003BZ/UID0003IL, historical command `000000022981` completed the earlier refresh, and dated command `000000023008` recorded unchanged generated CPP/H semantics under C0L2-054. Gate-time physical reread determines current generated state.
- [x] Report accepted by supervisor for implementation at the exact pre-callback SHA recorded above.
- [x] All accepted ordinary target/support doc details incorporated at report-level detail.
- [x] Sole primary UID0000L2 and every support destination verified independently against its ledger and physical document; additional target UIDs remain none.
- [x] Claim And Incorporation Ledger updated with final ordinary destination and canonical verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/CPP/H changes applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions remain resolved or narrowed to evidence-backed nonblocking confidence caps.
- [x] Twenty-five initial scoped validators ran with generated refresh disabled; the first three Gate 2A-remediation validators ran under historical commands `000000022979`-`000000022981`, with the last completing the then-current generated refresh; follow-up validators `000000022991`-`000000022992` corrected and verified C002/C029 with generated refresh disabled. Dated command `000000023008` records the later coherent generated/tracker snapshot; current generated CPP/H and tracker are reread separately at each Gate and mandatory post-move audit. UID0001AL remained already present without edit.
- [x] Generated CPP/H refresh/readback is complete under C0L2-054. Supervisor-owned manual coverage application is complete under C0L2-047..052 and commands `000000022993`-`000000022996`; no coverage edit or command is attributed to B003.
- [x] No ordinary accepted item remains unapplied; only the eleven concrete supervisor-owned IDA rows C0L2-036..C0L2-046 remain unchecked by role.
- [x] Report body is lifecycle-neutral: current execution/archive truth is deferred to current path and validator-owned status/history metadata.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000023118","destination_path":"executed-b-agent-research/B003/0000L2-MapNamePane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000L2-MapNamePane-file-source-quality.md","timestamp":"2026-08-13T09:32:39-04:00","uid":"0000L2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
