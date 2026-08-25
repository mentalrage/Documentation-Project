** TARGET-REPORT-UID:0003RK **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003RK UserLookPaneParseLookPacket Ownership / Split Research

## Finalized Report / Current Recommendation

- Current implemented disposition: exact child `[0x0059f610,0x005a0626)` remains under [UID:0000FP] `UserLookPane`; its source-facing virtual is `UserLookPane::OnActivate(const unsigned char *packetData)`, while `ParseLookPacket` remains the descriptive document/behavior alias.
- Final disposition: one source-authored, vtable-routed method with no split, merge, compiler-only reclassification, or owner transfer. The normal body ends at `0x005a0621`; the in-function range-check failure call occupies `0x005a0621-0x005a0626` and remains part of the function.
- Callback result: target `86/90 -> 92/93`; all twelve exact managed blocks and all accepted target/support prose, metadata, score, source-route, historical, negative, and no-code dispositions were applied and scoped-validated. The final waited generated refresh completed as command `000000010216`.
- Confidence: very strong for function identity, ABI, range, packet progression, layout, vtable dispatch, helper roles, source owner, and first-draft behavior; strong for descriptive field/method spellings; deliberately below absolute because original PDB names for several display strings and trailing packet bytes are unavailable.

## Supporting Research

### Mandatory live MCP evidence pass

- B005 initialized a fresh streamable-MCP protocol client and checked `idb_list` before target work. At `2026-07-13T14:25:03.2839587-04:00`, the only configured database was `supervisor_nexustk_20260713`, adopted and active on worker PID `2236`, with `is_analyzing:false` and IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Evidence-time `server_health` returned `status:ok`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2,067 strings. This wording records evidence collection and does not assert that the evidence-time protocol session remains alive.
- Bounded `lookup_funcs`, `analyze_function`, `disasm`, instruction-range, bytes, xrefs, callers, callees, vtable dword, string, and function-neighborhood calls all completed against that database. The target's full 1,080-instruction stream was read in bounded pages at offsets 0, 200, 400, 600, 800, and 1,000.
- One local PowerShell helper initially used the automatic `$args` variable incorrectly and produced a tool-level `database required` response; the corrected request succeeded immediately. One unbounded display request returned a deferred-output notice, after which bounded page requests succeeded. Neither was MCP downtime, and neither supplied evidence used without a successful bounded retry. B005 did not start, stop, restart, or mutate MCP/IDA.

### Prior-report search provenance

Exact terms searched: `0003RK`, `UID:0003RK`, `TARGET-REPORT-UID:0003RK`, `0x0059f610`, `0x59f610`, `0059f610`, `UserLookPaneParseLookPacket`, `UserLookPane::ParseLookPacket`, and `sub_59F610`. Discovery terms searched: `UserLookPane`, `MoreInfoPane`, `ProfilePane`, `LegendPane`, `ObjectStatusBlob`, `DecodeJpfImageToTileContext`, `ResourceLayoutRawBuffer`, `EPFTextEditObject`, `OnActivate`, `UserLookPane.cpp`, and `0000FP`.

Search roots actually checked:

- central executed reports: `source-3/project-documentation/executed-b-agent-research/`;
- active reports: every `source-3/project-documentation/tools/leaser/Agents/Agent-B*/research/` directory;
- relevant legacy executed/archived roots: `archived/b-agent-reports-20260623/` and `archived/duplicate-loose-b-agent-reports/`.

Every exact or useful family match opened and classified:

| Report path | Match classification | Current usefulness / stale disposition |
| --- | --- | --- |
| `executed-b-agent-research/B001/0001KK-userlookpane-profile-source-split-audit.md` | Direct range/split support, not a dedicated UID0003RK report | Current for exact child creation, raw local pane bodies, no-route helpers, vtables, and UserLook source grouping; its unresolved target names/body are superseded by this target pass. |
| `executed-b-agent-research/B001/0001Y0-LookPaneVtableFamily-source-quality.md` | Incidental vtable-family support | Current for UserLook/MoreInfo/Profile vtable bases and local class order. |
| `executed-b-agent-research/B002/0001EC-PanelPane-source-quality.md` | Incidental base-class support | Current for PanelPane inheritance and pane contracts. |
| `executed-b-agent-research/B003/0001AS-Pane-core-source-quality.md` | Incidental inherited-slot support | Current for layer/event operations and Pane state separation. |
| `executed-b-agent-research/B004/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md` | Incidental common virtual-contract support | Current proof that the primary `+0x48` contract is `OnActivate(const unsigned char *)`; supersedes target-local `ParseLookPacket` declaration naming. |
| `executed-b-agent-research/B004/00019E-AUTOBUFUnsignedCharConstructor-source-quality.md` | Incidental byte-buffer support | Current concrete `_AUTOBUF<unsigned char>` layout/constructor evidence. |
| `executed-b-agent-research/B004/0002A8-MoreInfoPaneSingletonSlot-source-quality.md` | Incidental local-global support | Current for the source-retained `MoreInfoPane *` alias and its one constructor write. |
| `executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md` | Incidental strong packet-status support | Current exact 68-byte layout, parser names, byte-consumption values, and rejection of stale title/profile aliases. |
| `executed-b-agent-research/B007/000188-AUTOBUFUnsignedCharResize-source-quality.md` | Incidental exact helper support | Current for the two target calls, return type, and `m_data`/`m_count` behavior. |
| `executed-b-agent-research/B009/0000K3-ImageLoaders-empty-emitter-family-source-quality.md` | Incidental image-family support | Current for JPF decode placement and EPFTileContext output behavior. |
| `executed-b-agent-research/B009/0001HB-MemoryManMemmove-source-quality.md` | Incidental copy-helper support | Current for source-facing `memmove` use rather than raw `sub_516220`. |
| `executed-b-agent-research/B010/0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality.md` | Incidental raw-image support | Current for the sole target caller, two-argument `__stdcall` ABI, file-level ResourceLayout ownership, and the unresolved next-row/sentinel blocker that keeps that helper's own block blank. |
| `executed-b-agent-research/B011/0000NL-LegendPane-source-quality.md` | Incidental child-pane support | Current for LegendPane ownership/type; UserLook consumes but does not own LegendPane. |
| `executed-b-agent-research/B013/0002KT-ResourceLayoutRawRecordGetEntryRect-source-quality.md` | Incidental neighboring ResourceLayout support | Current negative proof that the raw rectangle helper does not resolve or replace UID0002KQ. |
| `tools/leaser/Agents/Agent-B005/goal.md` | Active assignment match | Assignment metadata only, not prior research. |

No matching report was found in either archived root. No central or active report contains `TARGET-REPORT-UID:0003RK`. Evidence-based conclusion: there is no prior dedicated target report. B001's aggregate created the exact child, and all other matches are incidental support or broader family research.

## Target

- Target UID: `0003RK`.
- Target path: `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md`.
- Source queue/report row: validator-generated `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, historical assignment score `86/90` and report count zero at assignment time. Current tracker lifecycle remains validator-owned and is not frozen by this report.
- Historical assignment classification: independent report-only source-quality research before Gate 1 acceptance. Supervisor Gate 1 accepted exact report SHA `F588A5E3E72871DA2815FE2000B12B09031F6358722E80BB98095B8045D98EB4`, after which this same-artifact callback was authorized.
- Current implemented scores and parent state: target `92/93`, owner/emitter [UID:0000FP], reconstructable true, blank source-position field, `Nested:0`; class [UID:0000FP] `90/92`; file [UID:0000P0] `90/90`; broad split parent [UID:0001KK] remains `88/90`, false/non-emitting, and blank.

## Current Target State

- Current metadata preserves the exact UID/range, UserLookPane class owner/emitter, reconstructable state, blank position, and relative `Nested:0`; only scores changed to `92/93`.
- Current Item Summary identifies the primary `+0x48` `OnActivate` override and complete status/equipment/portrait/profile/legend population plus overview transition. The page now carries the full schema, exact ABI, complete field map, CFG/boundaries, dependency contracts, negative/history evidence, and exact formal body.
- Current formal C++ is Destination 1 byte-for-byte. `UserLookPaneParseLookPacket` remains useful behavior shorthand while the emitted declaration/body uses the resolved inherited method name `OnActivate`.
- Current target prose retains all ObjectStatusBlob corrections; older title/profile-tail/generic-remap interpretations remain explicitly historical and superseded by UID000179/UID00009S.
- Historical generated baseline: command `000000010069` emitted only `g_pMoreInfoPane` plus empty markers. Current validator-owned `auto-generated/NexusTK/ui/panels/UserLookPane.cpp` was refreshed by command `000000010216` at `2026-07-13T15:33:42-04:00` and inspected read-only. It now emits MoreInfoPane/ProfilePane declarations and exact constructor/key/mouse bodies, the complete `0xddc` UserLookPane declaration, and UID0003RK `OnActivate`; unchanged blank sibling pages remain trace-only markers and excluded aggregate/raw/vtable/compiler items do not emit bodies.
- Current manual coverage audit: `by-memory/-coverage-report.md` has no UID0003RK, UID0003RI, UID0003RM-UID0003RU, UID0003RX-UID0003S2, UID00038S, or UID00038T row; its UID0001KK and UID00026V rows are stale at `84%`/reconstructable and `82%`. `by-class/-coverage-report.md` has stale rows for UID00004H, UID00008Q, UID0000AV, UID0000EO, and UID0000FP. `by-file/-coverage-report.md` has stale UID0000ON and UID0000P0 rows. All three reports were read only, and exact pending supervisor-owned corrections are supplied below.
- Related docs checked include the target, UID0001KK aggregate, UserLookPane class/file, constructor/renderer/mouse/key/action/view children, primary/secondary/tertiary vtables, MoreInfo/Profile classes/raw constructors/stubs/vtables, PanelPane/Pane contracts, ObjectStatusBlob class/parsers/file, PacketBuffer scalar readers, AUTOBUF class/constructor/resize, JPF decoder, ResourceLayout raw helper, EPFTileContext, LegendPane, TextEditPane/TextEditObject/EPFTextEditObject, MemoryMan memmove, and generated UserLookPane output.
- Current callback status: all B005 implementation responsibilities are complete in this same artifact. Twenty-eight ordinary by-* pages were edited and scoped-validated under short released leases; final waited generation completed. No manual coverage, generated, tracker, supervisor, audit, registry, validator-state, or lifecycle file was hand-edited, and no execute/probe/move/archive/lifecycle command was run.

## Executive Recommendation

- Keep direct owner/emitter [UID:0000FP] and file route [UID:0000P0] `NexusTK/ui/panels/UserLookPane.cpp`.
- Rename the source surface to the inherited virtual `OnActivate(const unsigned char *packetData)` while retaining “parse look packet” as behavior documentation and the filename/title unless a later validator-owned rename is explicitly accepted.
- Keep the exact target unsplit. The range is one modeled source-authored function with compiler cleanup/range-check support, not an aggregate or raw-helper container.
- The target and class/support declarations are populated through all twelve explicit destinations. Raw sender helpers, aggregate, vtable/RTTI, read-only data, padding, and ResourceLayout UID0002KQ's unresolved body remain non-emitting for the accepted reasons.
- No target-scoped source-quality blocker remains. Unknown original lexical names for three identity lines, two trailing bytes, and the raw ResourceLayout helper are represented by descriptive names and explicit confidence caps rather than deferred placeholders or `sub_` labels.

## Supervisor Active Recheck

- The supervisor accepted the exact report-only artifact and authorized C01-C37 plus Destinations 1-12 in this same-report callback.
- The target did not require split repair: every normal instruction belongs to one function, the compiler range-check tail is within its modeled extent, and predecessor/successor padding is external.
- Every source-bearing item required by the target has its exact applied destination block below or a verified no-code disposition. No child UID was created. Existing MoreInfo/Profile raw constructors and virtual stubs were updated in place; compiler wrappers and no-route packet senders remain excluded with reason.

## Inference Research Guidance Check

- `by-structure.md` and the project workflow require exact half-open ranges, vtable/caller-based ownership, human source names instead of stripped labels, formal managed blocks for every proposed C++ edit, and preservation of negative/source-shape evidence. Those rules drive the one-function range, `OnActivate` name, file-local inline helper shape, and separate declaration destinations.
- Existing assumptions treated as uncertain included `ParseLookPacket` as the final virtual name, IDA's integer return, generic identity/profile field labels, stale status aliases, MoreInfo/Profile `AlwaysFalse` names, EPF embedded-frame uncertainty, and ResourceLayout singleton preload as possible class-method evidence.
- Direct IDA facts are addresses, instructions, xrefs, bytes, vtable cells, field accesses, and call conventions. Documentation evidence is current accepted by-* class/file/helper state. Source names not symbol-proven are explicitly descriptive or inferred.
- Wave2/Wave3 and `simroot_v2` terms were encountered in current support history. They were not used as authoritative evidence; current IDA, current docs, and accepted executed reports supersede them.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution |
| --- | --- | --- |
| Final method name | Target is primary UserLook vtable cell `0x0062ed14`, relative `+0x48`. Current PanelPane/common panel evidence resolves that inherited slot as `OnActivate(const unsigned char *)`. | Use `UserLookPane::OnActivate`; retain ParseLookPacket only as a descriptive title/alias. |
| ABI/return | ECX is the pane, one stack pointer argument is read, and normal exit is `retn 4`. IDA's inferred integer result comes from return-register residue/tail analysis, not authored return behavior. | Use `void __thiscall` source shape with one `const unsigned char *`. |
| Packet origin | First cursor use starts at `packetData + 1`; no target read consumes byte zero. | Document byte zero as an outer dispatch/subcommand byte already selected by the caller framework. |
| Five leading strings | Five consecutive unsigned-byte ANSI lengths, `MultiByteToWideChar`, destination widths, render consumers, and mouse sender use are exact. Only original lexical labels for lines 1-4 are stripped. | Use descriptive identity-line/header names; use `m_targetUserName` for the fifth string because action dispatch transmits it. |
| Status branch | Tag byte stored at `+0xdc8`; values 0 and 1 call exact full/partial ObjectStatusBlob methods and consume 43/5 bytes. Other values consume zero without rejection. | Preserve the unusual unknown-tag behavior; reject stale title/profile or generic-remap status names. |
| Equipment schema | Fourteen unrolled record reads have a stable BE16 id, palette byte, two byte-length string skips, and six-byte fixed tail. Renderer coordinates and SelfLook selector evidence converge on slot roles. | Use exact packet order and descriptive equipment names; mark semantic spellings inferred where only coordinates/consumers prove them. |
| More-info text | Next converted text goes to `+0x904`, converted length to `+0xb87`; tabs become carriage returns before TextEdit population. | Name `m_moreInfoText` and preserve replacement/selection behavior. |
| Object id/action bytes | UInt32 at `+0xb80` is sent by action opcode `0x4a`; bytes `+0xb84/+0xb85` gate two buttons and `+0xb86` is a portrait fallback frame. | Use `m_targetObjectId`, `m_exchangeActionState`, `m_groupActionState`, and `m_portraitFallbackFrame`. |
| Word at `+0xdd8` | Exact BE16 parse/storage is proven, but no in-family read identifies product semantics. | Use descriptive `m_serverProfileValue`; keep original semantic spelling unresolved and cap confidence without blocking code. |
| Portrait format | Literal four-byte comparison against `JPF`, two AUTOBUF resizes, one JPF decoder call, one raw ResourceLayout helper call, and malformed bytes 6/7 path are exact. | Preserve JPF/raw branches, zeroed stored length, and the resulting no-skip cursor oddity. Do not invent validation. |
| ResourceLayout helper | UID0002KQ is a two-stack-argument free/static helper. Caller preloads `g_pEPFLib`, but callee overwrites ECX. Its own row/sentinel body remains unresolved. | Use a descriptive external file-local API name at the callsite only; do not add a UID0002KQ body or transfer ownership. |
| Profile/legend text | Profile is an 8-bit-length ANSI string. Legend count is BE16; each entry is symbol byte, style/color byte, ANSI text, inline EPF object, CR, and color formatting. | Model exact text/control flow and preserve byte-sized style/color input as a DWORD color payload. |
| TextEdit helper names | Exact callees and current editor docs resolve clear, selection, set/insert, edit-active, format, inline-object insertion, and scrollbar sync behavior. | Add only the three missing declarations needed by this target; preserve the entire existing TextEditPane class block otherwise. |
| MoreInfo/Profile false stubs | Vtable placement resolves `0x005a2340/0x005a23c0` as secondary `OnKeyEvent` and `0x005a2350/0x005a23d0` as primary `OnMouseEvent`. | Replace generic `AlwaysFalse` names with the inherited virtual names and exact false bodies. |
| Raw pane constructors | Complete 30-instruction bodies call the same fixed TextEditPane base constructor and install the class vtables. They have no direct start xrefs but are retained complete source-shaped definitions in the local class island. | Emit source constructors with the exact fixed base arguments; preserve no-xref evidence as liveness/confidence history, not a reason to keep known source definitions blank. |
| EPF inline object | Constructor allocation size is 60 bytes; TextEditObject base is 20 bytes and embedded EPFTileContext is 40 bytes. Vtable slot `+0x0c` is a live derived `OnUpdate` override. | Declare exact inheritance, constructor/destructor/override, and embedded `EPFTileContext m_frame`; retain method-body work outside scope. |
| Final pane transition | Target sets mode one, removes/unregisters all three child panes, then calls ShowMoreInfoView, which selects mode zero and reattaches the overview child. | Preserve this apparently redundant but exact transition sequence. |

Rejected alternatives:

- A standalone `ParseLookPacket` nonvirtual method, integer return, packet-length parameter, or defensive bounds checks are rejected by the vtable, ABI, and complete instruction stream.
- UTF-8, UTF-16-on-wire, null-terminated wire strings, and 16-bit string lengths are rejected; all relevant strings use one-byte byte counts plus ANSI conversion.
- `ObjectStatusBlob::ParseTaggedStatus` is rejected at this callsite because the target itself consumes/stores the tag and dispatches full/partial directly.
- A 13- or 15-slot equipment model is rejected; exactly fourteen complete unrolled records are consumed.
- UserLook ownership of PacketBuffer, ObjectStatusBlob, AUTOBUF, JPF decoder, ResourceLayout helper, TextEditPane, EPFTextEditObject, or LegendPane is rejected. They are dependencies.
- A split at the normal return, exclusion of `0x005a0621-0x005a0626`, or expansion through the external SEH nodes is rejected. IDA's function owns the range-check failure block but only references external compiler handler/cleanup nodes.

## Evidence Standards Used

- Primary evidence: mandatory live IDA MCP function lookup, full paged disassembly, 31-block CFG, Hex-Rays, exact bytes, caller/callee/xref queries, vtable dwords, constructor allocation size, field consumers, adjacent functions, and resource strings.
- Corroboration: current by-memory/class/file/type documentation, accepted executed reports, current generated output read-only, packet-reader contracts, renderer/mouse/key/view consumers, and exact helper bodies.
- Negative evidence: no ordinary code caller, no second target function, no packet-length read, no bounds/error return, no unknown-tag rejection, no direct raw-constructor route, no duplicate target body, no ResourceLayout `this` use, no status/title remap, and no source reason to emit compiler/vtable/padding artifacts.
- The evidence ladder is sufficient for first-draft code because independent packet progression, storage offsets, render consumers, vtables, and helper contracts converge. Only stripped lexical spellings remain inferential.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks: fresh `idb_list` and `server_health`; target/predecessor/successor lookups; full 1,080 instructions; all CFG blocks/returns; target xrefs/callees; vtable cells; five-string conversions; status branches; fourteen record reads; profile/JPF/raw-image/legend paths; EH/rangecheck nodes; exact boundary bytes; MoreInfo/Profile raw constructors/stubs; EPF constructor/vtable/size; TextEdit helper calls; and field consumers in renderer/mouse/key/view methods.
- by-* docs/support checked: all pages enumerated in Current Target State, including current formal blocks and score/history caveats. During callback, every changed destination was re-read immediately before edit, scoped-validated while leased, and rechecked after validator mutation. Generated UserLookPane.cpp and TextEditPane.cpp were inspected read-only after the final waited refresh; generated/tracker/manual-coverage files were never hand-edited.
- Old-report checks: exact terms/roots/results are recorded under Supporting Research. Every matching report was opened and classified as direct range support or incidental support; no prior dedicated target report exists.
- Manual coverage checks: current `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` were searched by every changed UID/name and opened around the matching address/alphabetic positions. The exact missing/stale-row results are recorded in Current Target State and drive the supervisor text section.
- Negative checks: no code xref to target beyond vtable data; no function at exclusive end; no hidden target-internal function start; no packet size argument; no catch/recovery path; no normal return after rangecheck failure; no direct caller to raw local pane constructor starts; no ordinary consumer of trailing byte `+0xb7b` or word `+0xdd8`; and no safe basis to emit UID0002KQ's unresolved raw parser body.
- Callback validation checks: 30 successful validator invocations are recorded below. Every invocation returned exit `0` and `ok:1`; final command `000000010216` completed generated refresh. Early scoped warnings were validator-owned missing-reference/registry gaps on older split pages; most cleared as those in-scope pages registered serially. UID00038S/UID00038T retained an explicit `canonical_owner_unknown`/`emitter_uid_unknown` warning for verify-only UID00038Q absent from `validator.ini`; documents preserved the accepted UID00038Q route, and the final registry rebuild/generated refresh completed successfully.
- Failed/unavailable checks: none remained after bounded retries. No fallback-only evidence was accepted, no accepted claim is blocked, and no lease remains active for B005.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target is exactly `[0x0059f610,0x005a0626)`, 4,118 bytes, one modeled function. | very strong | lookup/bytes/full disassembly | UID0003RK | incorporate | applied |
| C02 | Function has 1,080 instructions, 31 IDA blocks, normal `retn 4`, and in-range rangecheck failure call. | very strong | paged disassembly/CFG | UID0003RK | incorporate | applied |
| C03 | Twelve predecessor `0xcc` bytes and ten successor `0xcc` bytes are external alignment; successor nullstub starts `0x005a0630`. | very strong | bytes/function neighborhood | UID0003RK/UID0001KK | incorporate | applied |
| C04 | Source ABI is virtual `void UserLookPane::OnActivate(const unsigned char *)`; IDA integer return and ParseLookPacket final name are superseded. | very strong ABI; strong name | vtable/base contract/stack cleanup | UID0003RK/UserLook class/vtables | reject-stale | applied |
| C05 | Only inbound target reference is primary UserLook vtable cell `0x0062ed14`, relative `+0x48`. | very strong | xrefs/dword reads | UID0003RK/UserLook vtables | incorporate | applied |
| C06 | Cursor begins at packet byte 1 and consumes five byte-length ANSI strings into exact destination widths. | very strong | complete instruction progression | UID0003RK/UserLook layout | incorporate | applied |
| C07 | Fifth leading string is the target user name; first four remain descriptive identity/header fields. | strong | renderer/mouse sender consumers | target/class history | incorporate | applied |
| C08 | Status byte at `+0xdc8` selects full 43-byte or partial 5-byte ObjectStatus parser; other values consume zero. | very strong | branches/callees/current UID000179 | target/class | incorporate | applied |
| C09 | Fourteen exact equipment records each consume id, palette, two skipped strings, and six fixed bytes. | very strong | unrolled instructions/cursor deltas | target/class | incorporate | applied |
| C10 | Equipment field names/order follow renderer coordinates and accepted SelfLook selector evidence. | strong | cross-consumers | target/class/renderer support | incorporate | applied |
| C11 | More-info text converts ANSI, changes tab to CR, stores converted length, and replaces editor content/selection. | very strong | target calls/field writes | target/class/TextEdit support | incorporate | applied |
| C12 | UInt32 at `+0xb80` is target object id; action/fallback bytes at `+0xb84..+0xb86` have exact consumer roles. | very strong | parser/mouse/render | target/class | incorporate | applied |
| C13 | BE16 `+0xdd8` is exact but semantically unresolved; descriptive `m_serverProfileValue` is the least-overclaiming name. | strong type; medium semantic name | parser/no consumers | target/class/open questions | incorporate | applied |
| C14 | Portrait branch uses `_AUTOBUF<unsigned char>`, JPF decoder, or two-argument raw ResourceLayout helper. | very strong | calls/string/UID000188/UID0002KQ | target/class/support | incorporate | applied |
| C15 | Malformed non-JPF bytes 6/7 zero stored length and therefore prevent cursor skip; no validation return occurs. | very strong | exact branch/cursor use | target/negative evidence | incorporate | applied |
| C16 | Profile text always clears editor and conditionally replaces it; legend always clears and rebuilds entries. | very strong | call sequence | target/class/TextEdit support | incorporate | applied |
| C17 | Legend entry format is symbol byte, color/style byte, byte-length ANSI text, 12x12 EPF object, text+CR, and mask-2 color format. | very strong | loop/calls/local payload | target/EPF/TextEdit support | incorporate | applied |
| C18 | Final bytes map to trailing state and target-name highlight; only highlight has an exact renderer consumer. | strong | parser/render/no-use checks | target/class | incorporate | applied |
| C19 | Target copies parsed state, sets mode 1, removes/unregisters three panes, then calls ShowMoreInfoView. | very strong | final block/callees | target/class/view support | incorporate | applied |
| C20 | No packet-length parameter, defensive bounds checks, unknown-tag reject, or catch block may be added. | very strong | full ABI/CFG/EH | target negative/history | reject-invalid | applied |
| C21 | Target score is `92/93` after callback; owner/emitter/reconstructable/range/blank position/Nested remain unchanged. | strong | blocker closure | UID0003RK metadata | incorporate | applied |
| C22 | UserLookPane exact size is `0xddc` with complete field map and class surface; class becomes `90/92`. | very strong layout; strong names | allocation/field consumers/vtables | UserLook class Destination 2 | incorporate | applied |
| C23 | MoreInfoPane derives TextEditPane and has fixed constructor plus false key/mouse overrides. | very strong | raw constructor/vtables | Destinations 3-6 | incorporate | applied |
| C24 | ProfilePane derives TextEditPane and has the corresponding fixed constructor and false overrides. | very strong | raw constructor/vtables | Destinations 7-10 | incorporate | applied |
| C25 | Raw constructor no-xref history remains material but does not erase complete retained source definitions. | strong | raw bytes/no-route scans/local island | raw constructor history | historicalize | applied |
| C26 | TextEditPane requires ClearText, ApplySelectionFormat, and InsertEmbeddedObject declarations; all existing formal content is preserved. | very strong behavior; strong names | exact callees/current class | TextEditPane Destination 11 | incorporate | applied |
| C27 | EPFTextEditObject is a 60-byte TextEditObject derivative containing a 40-byte EPFTileContext and live OnUpdate override. | very strong layout/vtable | allocation/ctor/vtable/base sizes | EPF class Destination 12 | incorporate | applied |
| C28 | ObjectStatusBlob, AUTOBUF, PacketBuffer, JPF decoder, ResourceLayout helper, LegendPane, and EPFTileContext remain dependency-owned. | very strong | current owner/call graph docs | support verify-only | already-present | already-present |
| C29 | UID0002KQ remains blank because its next-row/sentinel contract is unresolved; no target body should duplicate it. | very strong | current helper report/body | UID0002KQ verify-only | already-present | already-present |
| C30 | Aggregate UID0001KK remains non-emitting `88/90`; exact body belongs only on target/children. | very strong | current split inventory | UID0001KK | already-present | applied |
| C31 | Raw packet senders UID0003RV/UID0003RW remain no-route and are not UserLook class declarations. | very strong | no function/no xref scans | class/file negative support | already-present | already-present |
| C32 | Vtables, RTTI, read-only data, alignment, scalar/adjustor destructors, EH cleanup, and rangecheck mechanics get no source body. | very strong | storage/compiler role | support/no-code disposition | not-applicable | excluded-with-reason |
| C33 | UserLookPane file route remains `NexusTK/ui/panels/UserLookPane.cpp`; file score becomes `90/90`. | strong | local class/function/data island | by-file/UserLookPane | incorporate | applied |
| C34 | MoreInfo/Profile generic `AlwaysFalse` names are stale and become inherited OnKeyEvent/OnMouseEvent names. | very strong | exact vtable placement | stub pages/classes | reject-stale | applied |
| C35 | Old status title/profile-tail and generic-remap aliases remain historical/superseded, not current packet semantics. | very strong | UID000179/current target | target/class history | historicalize | applied |
| C36 | No target duplicate/inlined second body was found; structural helper reuse does not change ownership. | strong | signature/function/caller searches | target negative evidence | incorporate | applied |
| C37 | No IDA mutation, third-party import, child UID allocation, or lifecycle operation applies; manual coverage synchronization does apply, remains supervisor-owned, and has exact pending additions/replacements below. | very strong | current manual coverage reports plus assignment/project policy | coverage section/checklist; supervisor-owned by-memory/by-class/by-file reports | incorporate | applied |

### Callback Verification Notes

| Claim | Callback proof |
| --- | --- |
| C01-C03 | UID0003RK retains exact range/Nested metadata and now documents 4,118 bytes, 1,080 instructions, 31 blocks, in-range rangecheck tail, and external 12/10-byte padding; Destination 1 validated by `000000010135` and final `000000010216`. |
| C04-C05 | Target formal body and UID0000FP class use `void OnActivate(const unsigned char *)`; UID00026V plus generated output preserve sole primary `+0x48` vtable routing. |
| C06-C10 | Target and UID0000FP/UserLook file/renderer pages carry five-string progression, target-name disposition, 43/5-byte status dispatch, fourteen exact records, equipment order, and cross-consumer rationale. |
| C11-C19 | Target body and synchronized UserLook/TextEdit/EPF/view support preserve more-info conversion, object/action/scalar roles, portrait branches, profile/legend flow, trailing fields, final copies, and exact remove/unregister/ShowMoreInfo sequence. Generated lines 237-434 were inspected read-only. |
| C20 | Target negative/history sections retain no packet length, bounds checks, unknown-tag rejection, catch/recovery, or invented validation. Destination 1 preserves zero-consumption and malformed zero-skip behavior. |
| C21 | UID0003RK is `92/93`; owner/emitter UID0000FP, true, blank position, exact range, and `Nested:0` are unchanged. |
| C22 | UID0000FP is `90/92` with exact `0xddc` declaration/size assertion, complete field map, vtable evidence, descriptive-name caps, dependencies, and exclusions; validator `000000010215` returned `ok:1`. |
| C23-C25 | UID00008Q/UID0003RX-RZ are `90/92`, `88/91`, `89/92`, `89/92`; exact inheritance/constructor/key/mouse blocks emit. No-direct-start history remains explicit rather than suppressing retained source. |
| C24-C25 | UID0000AV/UID0003S0-S2 carry the mirrored accepted scores/declarations/bodies, preserve ProfileDialog rejection, and retain raw-start history; validators `000000010148`, `000000010156`, `000000010158`, and `000000010159` returned `ok:1`. |
| C26 | UID0000EO score/route and all prior formal lines remain; exact block comparison showed only `TextEditObject` plus `ClearText`, `ApplySelectionFormat`, and `InsertEmbeddedObject` were added. TextEdit file documents target consumer boundaries. |
| C27 | UID00004H is `89/92` with exact 60-byte declaration, 40-byte `EPFTileContext m_frame`, owner/symbol constructor, destructor, live `OnUpdate`, callers/resources/history, and rejected RectBounds/direct-draw shape. |
| C28-C29 | Dependency pages remain verify-only at existing metadata/formal state. UserLook/TextEdit/target prose records dependency ownership; UID0002KQ remains blank and is called only through the accepted external declaration. |
| C30 | UID0001KK remains `88/90`, false/non-emitting, blank emitter/position/formal block, `Nested:0`; its updated split index routes source only to exact children. |
| C31 | UID0003RV/UID0003RW remained unedited no-route raw helpers and are absent from generated UserLookPane.cpp; class/file/aggregate prose records that they are not class declarations. |
| C32 | Vtable/RTTI/read-only/alignment/compiler/EH/rangecheck storage was intentionally excluded from hand-authored bodies. UID00026V/UID00038S/UID00038T remain blank and compiler-regenerated; generated output contains only expected trace markers for blank routed supports. |
| C33 | UID0000P0 is `90/90`, FILE-owned, path `NexusTK/ui/panels/`; no by-file formal block was added. Validator `000000010166` returned `ok:1`. |
| C34 | MoreInfo/Profile class, stub, vtable, file, aggregate, and read-only pages consistently use inherited `OnKeyEvent`/`OnMouseEvent`; generic AlwaysFalse names survive only in filenames/historical wording. |
| C35 | Target/class/file/aggregate prose retains title/profile-tail/generic-remap claims only as rejected/superseded history and preserves current ObjectStatusBlob/RidableAnimals/NewHuman ownership. |
| C36 | Target negative evidence retains the no-duplicate/no-inline finding; generated output has one UID0003RK body and one UserLook declaration. |
| C37 | No IDA mutation, child allocation, third-party import, manual coverage edit, execute/probe/lifecycle/move/archive command occurred. Exact pending supervisor-owned coverage text below is preserved unchanged; all leases were released. |

## Positive Evidence Summary

- Exact function, bytes, CFG, stack cleanup, and vtable cell converge on one live virtual method.
- Packet cursor movement can be accounted for from byte 1 through the final two bytes without an unexplained gap: five strings, status parser result, fourteen equipment records, more-info string, object/action/profile scalars, portrait payload, profile string, legend count/entries, and trailing flags.
- Independent renderer, mouse, key, and view methods consume the same fields and prove equipment coordinates, name/action roles, portrait mode, and final ShowMoreInfo transition.
- Current ObjectStatusBlob, AUTOBUF, image decoder, ResourceLayout, TextEdit, and EPF support pages independently resolve every called ABI needed by the draft while preserving their separate ownership.
- Strongest inference chain: inherited vtable slot -> exact target body -> exact cursor/storage writes -> cross-method field consumers -> current helper contracts -> local source-file/vtable island. No single stale generated name is required.

## IDA MCP Facts

### Function and boundary facts

- `lookup_funcs` reports predecessor `sub_59F500` at `0x0059f500`, size `0x104`; target `sub_59F610` at `0x0059f610`, size `0x1016`; and successor `nullsub_63` at `0x005a0630`, size one.
- `0x005a0625` is inside the target. `0x005a0626` is not a function. Normal `retn 4` ends at `0x005a0621`; call to compiler rangecheck failure occupies `0x005a0621-0x005a0626`.
- Predecessor return ends at `0x0059f604`; `[0x0059f604,0x0059f610)` is twelve `0xcc` bytes. `[0x005a0626,0x005a0630)` is ten `0xcc` bytes before the one-byte nullstub return.
- `analyze_function` reports 31 blocks, cyclomatic complexity 12, 27 callees, no direct caller, and one data xref at `0x0062ed14`.

### Exact basic-block inventory

| # | Range | Successors / role |
| ---: | --- | --- |
| 1 | `0x0059f610-0x0059f8d0` | `0x0059f8d0`, `0x0059f8f1`; leading strings/status dispatch |
| 2 | `0x0059f8d0-0x0059f8f1` | `0x0059f91c`; full-status branch |
| 3 | `0x0059f8f1-0x0059f8f5` | `0x0059f8f5`, `0x0059f916`; partial-status test |
| 4 | `0x0059f8f5-0x0059f916` | `0x0059f91c`; partial-status branch |
| 5 | `0x0059f916-0x0059f91c` | `0x0059f91c`; unknown tag consumes zero |
| 6 | `0x0059f91c-0x0059fe99` | `0x0059fe99`, `0x0059feba`; equipment and more-info setup |
| 7 | `0x0059fe99-0x0059fea2` | `0x0059fea2`; tab replacement entry |
| 8 | `0x0059fea2-0x0059fea8` | `0x0059fea8`, `0x0059feab`; scan/test |
| 9 | `0x0059fea8-0x0059feab` | `0x0059feab`; tab-to-CR write |
| 10 | `0x0059feab-0x0059feba` | loop to `0x0059fea2` or exit `0x0059feba` |
| 11 | `0x0059feba-0x0059ff91` | `0x0059ff91`, `0x005a005b`; scalar/portrait-length gate |
| 12 | `0x0059ff91-0x0059ffc1` | `0x0059ffc1`, `0x0059fffe`; JPF test |
| 13 | `0x0059ffc1-0x0059fffe` | `0x005a0052`; JPF resize/copy/decode |
| 14 | `0x0059fffe-0x005a002e` | `0x005a002e`, `0x005a0049`; raw resize/copy/header test |
| 15 | `0x005a002e-0x005a0034` | `0x005a0034`, `0x005a0049`; second malformed-byte test |
| 16 | `0x005a0034-0x005a0049` | `0x005a0052`; raw ResourceLayout call |
| 17 | `0x005a0049-0x005a0052` | `0x005a0052`; malformed length zero |
| 18 | `0x005a0052-0x005a005b` | `0x005a005b`; cursor advances by stored length |
| 19 | `0x005a005b-0x005a008f` | `0x005a008f`, `0x005a0130`; profile-length branch |
| 20 | `0x005a008f-0x005a0130` | `0x005a0130`; profile conversion/editor population |
| 21 | `0x005a0130-0x005a0183` | `0x005a0183`, `0x005a033e`; legend-count loop gate |
| 22 | `0x005a0183-0x005a0244` | `0x005a0244`, `0x005a0621`; legend conversion/rangecheck edge |
| 23 | `0x005a0244-0x005a0269` | `0x005a0269`, `0x005a0280`; object allocation branch |
| 24 | `0x005a0269-0x005a0280` | `0x005a0282`; EPF constructor path |
| 25 | `0x005a0280-0x005a0282` | `0x005a0282`; null allocation path |
| 26 | `0x005a0282-0x005a033e` | loop to `0x005a0183` or exit `0x005a033e`; insert/format |
| 27 | `0x005a033e-0x005a0621` | terminal normal state copies, pane transition, return |
| 28 | `0x005a0621-0x005a0626` | terminal type-4 compiler rangecheck call |
| 29 | external `0x0060a2bd-0x0060a2cb` | compiler EH cleanup releases pending EPF allocation |
| 30 | external `0x0060a2cb-0x0060a2f3` | SEH node to C++ frame handler |
| 31 | external `0x005c956c` | compiler CxxFrameHandler node, no source body expansion |

### Vtable and class facts

- UserLook primary vtable starts `0x0062eccc`; target cell is `0x0062ed14`, relative `+0x48`. Primary `+0x44` points to renderer `0x005a0640`.
- Secondary and tertiary UserLook vtables begin `0x0062ed1c` and `0x0062ed4c`. Constructor allocation caller at `0x004b8457` pushes `0xddc`, proving exact class size.
- MoreInfo vtable cells route `0x005a2340` to secondary key-event slot and `0x005a2350` to primary mouse-event slot. Profile equivalents are `0x005a23c0` and `0x005a23d0`.
- MoreInfo/Profile raw constructors each use the fixed TextEditPane argument tuple `145,108,145,108,128,0,0,1,6,IsLegacyAssetMode(),1,0` and install primary/secondary/tertiary local vtables.
- EPFTextEditObject allocation is 60 bytes. Base TextEditObject is 20 bytes; embedded EPFTileContext at `+0x14` is 40 bytes. EPF vtable slot `+0x0c` points to live helper `0x005955a0`.

### Complete target field map

| Offset | Size | Recommended field / exact role |
| --- | ---: | --- |
| `+0x0f8/+0x0fc/+0x100` | 12 | `m_moreInfoPane`, `m_profilePane`, `m_legendPane` pointers |
| `+0x104/+0x304/+0x504` | 512 each | three 256-wide-character identity/display lines |
| `+0x704/+0x804` | 256 each | 128-wide-character header and target-user-name strings |
| `+0x904` | 512 | 256-wide-character more-info text |
| `+0xb04` | 68 | exact `ObjectStatusBlob m_status` |
| `+0xb48..+0xb5e` | 24 | Body, LeftHand, RightHand, Head, RightAccessory, LeftAccessory id/palette pairs |
| `+0xb60/+0xb62/+0xb64/+0xb65` | 6 | FaceAccessory1 and HeadAccessory2 ids then palettes |
| `+0xb66/+0xb68/+0xb6a/+0xb6b` | 6 | LeftSubAccessory and RightSubAccessory ids then palettes |
| `+0xb6c/+0xb6e` | 3 | Necklace id/palette; `+0xb6f` padding |
| `+0xb70/+0xb72` | 3 | Foot id/palette; `+0xb73` padding |
| `+0xb74/+0xb76` | 3 | Coat id/palette; `+0xb77` padding |
| `+0xb78/+0xb7a` | 3 | Mantle id/palette |
| `+0xb7b/+0xb7c` | 2 | trailing profile state; target-name highlight flag |
| `+0xb7d..+0xb7f` | 3 | alignment padding |
| `+0xb80` | 4 | target object id |
| `+0xb84/+0xb85/+0xb86/+0xb87` | 4 | exchange action, group action, portrait fallback frame, converted more-info length |
| `+0xb88/+0xb8a` | 4 | portrait payload length plus two-byte padding |
| `+0xb8c` | 12 | embedded `_AUTOBUF<unsigned char>` |
| `+0xb98/+0xb99` | 2 | converted profile length and padding |
| `+0xb9a` | 512 | profile text; followed by two-byte alignment at `+0xd9a` |
| `+0xd9c` | 40 | portrait `EPFTileContext` |
| `+0xdc4` | 4 | view mode: 0 overview, 1 equipment, 2 profile/portrait, 3 legend |
| `+0xdc8/+0xdc9..+0xdcf` | 8 | status encoding byte plus alignment |
| `+0xdd0/+0xdd4` | 8 | hovered and pressed action indices |
| `+0xdd8/+0xdda` | 4 | server profile word plus final padding to size `0xddc` |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0059f610-0x005a0626` | UID0003RK | target `UserLookPane::OnActivate` | true | UID0000FP | `86/90 -> 92/93` | exact body, Destination 1 |
| UserLookPane class | UID0000FP | class/layout/declarations | true | UID0000P0 | `88/90 -> 90/92` | Destination 2 |
| MoreInfoPane class | UID00008Q | local read-only TextEdit pane | true | UID0000P0 | `86/89 -> 90/92` | Destination 3 |
| `0x005a22e0-0x005a233d` | UID0003RX | retained MoreInfo constructor | true | UID00008Q | `85/89 -> 88/91` | Destination 4 |
| `0x005a2340-0x005a2345` | UID0003RY | MoreInfo key false override | true | UID00008Q | `85/90 -> 89/92` | Destination 5 |
| `0x005a2350-0x005a2355` | UID0003RZ | MoreInfo mouse false override | true | UID00008Q | `85/90 -> 89/92` | Destination 6 |
| ProfilePane class | UID0000AV | local read-only TextEdit pane | true | UID0000P0 | current `85/89 -> 90/92` | Destination 7 |
| `0x005a2360-0x005a23bd` | UID0003S0 | retained Profile constructor | true | UID0000AV | `85/89 -> 88/91` | Destination 8 |
| `0x005a23c0-0x005a23c5` | UID0003S1 | Profile key false override | true | UID0000AV | `85/90 -> 89/92` | Destination 9 |
| `0x005a23d0-0x005a23d5` | UID0003S2 | Profile mouse false override | true | UID0000AV | `85/90 -> 89/92` | Destination 10 |
| TextEditPane class | UID0000EO | editor declarations | true | UID0000ON | unchanged `90/91` | Destination 11 adds only required APIs |
| EPFTextEditObject class | UID00004H | inline symbol object declaration | true | UID0000ON | `86/90 -> 89/92` | Destination 12 |
| `0x0059f260-0x005a2523` | UID0001KK | split/index parent | false | none | unchanged `88/90` | blank aggregate |
| `0x005a2190-0x005a2272`, `0x005a2280-0x005a22da` | UID0003RV/UID0003RW | raw no-route packet senders | true | UID0000P0 | unchanged | blank/no class declarations |
| `0x004d03a0-0x004d04d0` | UID0002KQ | ResourceLayout raw-buffer helper | true | UID0000N5 | unchanged `86/89` | blank due sentinel blocker |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062ed14 -> 0x0059f610` | sole inbound data xref | primary UserLook virtual `+0x48`; live dispatch without ordinary callsite |
| no code xrefs to target | negative caller result | ordinary direct caller absence is expected for virtual activation |
| `0x0059f8dc -> 0x004d1fa0` | ObjectStatus full parser | consumes exactly 43 bytes |
| `0x0059f901 -> 0x004d2640` | ObjectStatus partial parser | consumes exactly 5 bytes |
| `0x0059ffc1`, `0x0059fffe -> 0x004e6ab0` | AUTOBUF resize calls | two portrait-format branches |
| JPF branch -> `0x004d07b0` | JPF decoder | outputs to embedded EPFTileContext |
| `0x005a0042 -> 0x004d03a0` | sole caller of raw ResourceLayout helper | two stack args; UserLook remains consumer only |
| legend allocation -> `0x005954c0` | EPFTextEditObject constructor | source `new` with owner pane and symbol index |
| target final -> `0x005a1cd0` | ShowMoreInfoView | restores overview after packet population |
| target -> `0x0058e320/0x0058f2a0/0x0058fc30/0x0058ea80/0x0058fef0/0x005905f0/0x0055e990` | TextEdit family | clear/select/replace/edit-state/format/inline-object/scrollbar operations |
| renderer/mouse/key/view siblings | field consumers | prove display, action, mode, and child-pane semantics |

## Documentation Evidence And IDA Status

- Current target docs correctly identify the range, owner/emitter, broad packet role, ObjectStatus parser synchronization, and major dependencies. They are incomplete rather than fundamentally misowned.
- Current UserLook class/file docs correctly group constructor, target, renderer/input/view helpers, raw packet senders, local child classes, vtables, static strings, and singleton alias. Their formal class block is blank and their field/method inventory is not compile-complete.
- MoreInfo/Profile docs correctly establish local ownership and vtables but retain generic false-stub names and blank formal blocks. Their historical “no direct raw-constructor route” fact remains true; the conclusion that this alone must suppress a complete retained constructor definition is superseded.
- ObjectStatusBlob and AUTOBUF current docs are authoritative support and require no code change. ResourceLayout UID0002KQ remains intentionally blank for its own target-specific raw-row blocker.
- Generated UserLookPane.cpp confirms the current six empty-emitter problem but is not source evidence for stale names and was not edited.

## Ranked Ownership Analysis

### 1. UserLookPane / UserLookPane.cpp

- Evidence for: target is in the primary UserLook vtable; all field writes are within a `0xddc` UserLook object; constructor/renderer/mouse/key/view methods consume the state; local child panes/vtables/strings are in the same island; current owner/file docs already agree.
- Evidence against: no ordinary code caller and several helpers belong to other modules. These are normal virtual/dependency facts, not ownership conflicts.
- Decision: retain class owner/emitter UID0000FP and file route UID0000P0.

### 2. PanelPane/base panel source

- Evidence for: inherited slot name and activation contract come from PanelPane/common panels.
- Evidence against: base source does not access UserLook fields or contain the target vtable/body; derived override is exact.
- Decision: use base contract for declaration naming only; reject base ownership.

### 3. ObjectStatus/ImageLib/ResourceLayout/TextEdit modules

- Evidence for: target calls their parsers/decoders/editor APIs and embeds their value types.
- Evidence against: each has independent owner/source route; only target coordinates them and owns UI state.
- Decision: dependencies only. Reject caller-to-callee ownership transfer.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use existing `NexusTK/ui/panels/UserLookPane.cpp`.
- Likely full contents: UserLookPane, MoreInfoPane, ProfilePane, their methods, local raw packet helpers, local vtables/read-only strings, and source-retained MoreInfo singleton alias.
- Candidate related items rejected: ObjectStatusBlob parsers, PacketBuffer readers, AUTOBUF template methods, image decoders, ResourceLayout raw helper, TextEdit support objects, and LegendPane source.
- Source-file inference: narrow existing panel implementation, not a broad protocol or image module.

## Source Placement

- Recommended placement: class method and local child classes in `NexusTK/ui/panels/UserLookPane.cpp`; class declaration in UserLookPane's header surface.
- This fits exact constructor/vtable/string/function adjacency, current UID0000P0 route, and generated path.
- Rejected placements: `ObjectStatusBlob.cpp` owns status parsing only; `ResourceLayoutTable.cpp` owns raw layout helper; `ImageLoaders.cpp` owns JPF decode; `TextEditPane.cpp` owns editor/EPF support; a new protocol file would separate one class virtual from all its field consumers.
- Remaining placement uncertainty: exact original header split between UserLookPane and private local child classes is not symbol-proven. Keeping all three declarations in the current UserLookPane source/header family is the narrowest coherent model.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `[0x0059f610,0x005a0626)`, including normal return and compiler rangecheck failure edge.
- No child split: all 1,080 instructions participate in one packet/state method. External EH nodes are compiler metadata/cleanup references, not address-contiguous target children.
- Predecessor ends before twelve alignment bytes; successor begins after ten alignment bytes. Neither padding run belongs in source.
- No merge: predecessor is a separate function and successor is a one-byte nullstub. Broad UID0001KK remains the non-emitting index/container.
- Reclassification: source-authored virtual method, not raw helper, data, aggregate, thunk, inline-only fragment, library routine, or compiler-generated function.

## Negative Evidence Summary

- No ordinary code xref targets `0x0059f610`; only primary vtable data does. This rejects direct-call naming assumptions but proves virtual liveness.
- No packet byte count or end pointer exists. Adding bounds checks, early error returns, or exception handling would change behavior.
- Unknown status tags do not reject or skip a fixed status size. Any default parser call is invalid.
- Non-JPF malformed records zero stored length and then advance by zero. Skipping the original payload length would “fix” an observed behavior and is rejected.
- The raw ResourceLayout helper does not read the caller-preloaded singleton as `this`; it remains a two-argument static/free helper.
- No field consumer resolves the original semantic name of `+0xb7b` or `+0xdd8`. Descriptive names are used and confidence remains capped.
- No direct route was found to the two raw packet senders or raw local-pane constructors. Packet senders remain excluded; complete constructor-shaped local definitions remain retained with the no-route fact preserved.
- No exact duplicate target body, internal secondary start, or reason to split compiler cleanup/rangecheck into source functions was found.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing target name/type: `UserLookPane::OnActivate(const unsigned char *packetData)` returning void.
- Proposed key field types/names: exact map in IDA MCP Facts; identity lines 1-3/header, target user name, target object id, action-state bytes, portrait buffer/context, view mode, status encoding, hover/pressed indices, and descriptive trailing/server-profile fields.
- Proposed local helper names: byte-length ANSI reader/skipper and fixed UserLook equipment-record reader, represented as file-local inline source in Destination 1.
- Proposed support names: MoreInfo/Profile inherited `OnKeyEvent`/`OnMouseEvent`; TextEdit `ClearText`, `ApplySelectionFormat`, `InsertEmbeddedObject`; EPF `m_frame` and `OnUpdate`.
- Intentionally unchanged: IDA database labels. This report-only assignment did not request IDA mutation, and source documentation can carry descriptive names without changing shared analyst state.

## First-Draft C++ Recommendation

- Eligible: target method, UserLookPane class declaration, MoreInfo/Profile class declarations and exact retained constructors/false overrides, TextEditPane declaration synchronization, and EPFTextEditObject declaration.
- Exactly twelve destination-specific managed blocks follow. No other proposed C++ destination exists. All code is contained only in these formal blocks.
- Third-party import: not applicable; all code is NexusTK project source reconstructed from the executable.

### Destination 1 - `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void __stdcall ResourceLayoutRawBufferLookupEntry(
    const unsigned char *buffer,
    EPFTileContext *outContext);

namespace
{
int ReadUserLookText(const unsigned char *packetData,
                     int &offset,
                     wchar_t *text,
                     int capacity)
{
    unsigned char byteCount = packetData[offset++];
    int length = MultiByteToWideChar(CP_ACP,
                                     0,
                                     reinterpret_cast<const char *>(packetData + offset),
                                     byteCount,
                                     text,
                                     capacity - 1);
    text[length] = 0;
    offset += byteCount;
    return length;
}

void SkipUserLookText(const unsigned char *packetData, int &offset)
{
    offset += packetData[offset] + 1;
}

void ReadUserLookEquipmentRecord(const unsigned char *packetData,
                                 int &offset,
                                 unsigned short &itemId,
                                 unsigned char &palette)
{
    itemId = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    palette = packetData[offset++];
    SkipUserLookText(packetData, offset);
    SkipUserLookText(packetData, offset);
    offset += 6;
}
}

void UserLookPane::OnActivate(const unsigned char *packetData)
{
    int offset = 1;
    wchar_t identityLine1[256];
    wchar_t identityLine2[256];
    wchar_t headerText[256];
    wchar_t targetUserName[256];
    ObjectStatusBlob status;

    ReadUserLookText(packetData, offset, identityLine1, 256);
    ReadUserLookText(packetData, offset, identityLine2, 256);
    ReadUserLookText(packetData, offset, m_identityLine3, 256);
    ReadUserLookText(packetData, offset, headerText, 256);
    ReadUserLookText(packetData, offset, targetUserName, 256);

    m_statusEncoding = packetData[offset++];
    int statusLength = 0;
    if (m_statusEncoding == 0)
        statusLength = status.ParseFullStatus(packetData + offset);
    else if (m_statusEncoding == 1)
        statusLength = status.ParsePartialStatus(packetData + offset);
    offset += statusLength;

    unsigned short bodyId, leftHandId, rightHandId, headId;
    unsigned short rightAccessoryId, leftAccessoryId;
    unsigned short faceAccessory1Id, headAccessory2Id;
    unsigned short leftSubAccessoryId, rightSubAccessoryId;
    unsigned short necklaceId, footId, coatId, mantleId;
    unsigned char bodyPalette, leftHandPalette, rightHandPalette, headPalette;
    unsigned char rightAccessoryPalette, leftAccessoryPalette;
    unsigned char faceAccessory1Palette, headAccessory2Palette;
    unsigned char leftSubAccessoryPalette, rightSubAccessoryPalette;
    unsigned char necklacePalette, footPalette, coatPalette, mantlePalette;

    ReadUserLookEquipmentRecord(packetData, offset, bodyId, bodyPalette);
    ReadUserLookEquipmentRecord(packetData, offset, leftHandId, leftHandPalette);
    ReadUserLookEquipmentRecord(packetData, offset, rightHandId, rightHandPalette);
    ReadUserLookEquipmentRecord(packetData, offset, headId, headPalette);
    ReadUserLookEquipmentRecord(packetData, offset, rightAccessoryId, rightAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, leftAccessoryId, leftAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, faceAccessory1Id, faceAccessory1Palette);
    ReadUserLookEquipmentRecord(packetData, offset, headAccessory2Id, headAccessory2Palette);
    ReadUserLookEquipmentRecord(packetData, offset, leftSubAccessoryId, leftSubAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, rightSubAccessoryId, rightSubAccessoryPalette);
    ReadUserLookEquipmentRecord(packetData, offset, necklaceId, necklacePalette);
    ReadUserLookEquipmentRecord(packetData, offset, footId, footPalette);
    ReadUserLookEquipmentRecord(packetData, offset, coatId, coatPalette);
    ReadUserLookEquipmentRecord(packetData, offset, mantleId, mantlePalette);

    m_moreInfoLength = static_cast<unsigned char>(
        ReadUserLookText(packetData, offset, m_moreInfoText, 256));
    for (int i = 0; i < m_moreInfoLength; ++i)
    {
        if (m_moreInfoText[i] == L'\t')
            m_moreInfoText[i] = L'\r';
    }

    m_moreInfoPane->SetSelectionRange(0, 0x7fff);
    m_moreInfoPane->SetText(m_moreInfoText, m_moreInfoLength, 0, 0);
    m_moreInfoPane->SetSelectionRange(0, 0);

    m_targetObjectId = PacketBufferReadUInt32BE(packetData + offset);
    offset += 4;
    m_exchangeActionState = packetData[offset++];
    m_groupActionState = packetData[offset++];
    m_portraitFallbackFrame = packetData[offset++];
    m_serverProfileValue = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;
    m_portraitPayloadLength = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;

    if (m_portraitPayloadLength != 0)
    {
        if (memcmp(packetData + offset, "JPF", 4) == 0)
        {
            unsigned char *portraitData =
                m_portraitBuffer.Resize(m_portraitPayloadLength);
            memmove(portraitData, packetData + offset, m_portraitPayloadLength);
            DecodeJpfImageToTileContext(portraitData,
                                        m_portraitPayloadLength,
                                        &m_portraitImage);
        }
        else
        {
            unsigned char *portraitData =
                m_portraitBuffer.Resize(m_portraitPayloadLength);
            memmove(portraitData, packetData + offset, m_portraitPayloadLength);

            if (portraitData[6] != 0 || portraitData[7] != 0)
                m_portraitPayloadLength = 0;
            else
                ResourceLayoutRawBufferLookupEntry(portraitData, &m_portraitImage);
        }
    }
    offset += m_portraitPayloadLength;

    m_profilePane->ClearText();
    unsigned char profileByteCount = packetData[offset++];
    if (profileByteCount != 0)
    {
        int profileLength = MultiByteToWideChar(
            CP_ACP,
            0,
            reinterpret_cast<const char *>(packetData + offset),
            profileByteCount,
            m_profileText,
            255);
        m_profileText[profileLength] = 0;
        m_profileTextLength = static_cast<unsigned char>(profileLength);
        offset += profileByteCount;

        m_profilePane->SetSelectionRange(0, 0x7fff);
        m_profilePane->SetText(m_profileText, profileLength, 0, 0);
        m_profilePane->SetSelectionRange(0, 0);
    }

    m_legendPane->ClearText();
    m_legendPane->SetEditActiveState(true, false);
    unsigned short legendEntryCount = PacketBufferReadUInt16BE(packetData + offset);
    offset += 2;

    for (unsigned short entry = 0; entry < legendEntryCount; ++entry)
    {
        unsigned char symbolIndex = packetData[offset++];
        unsigned char textColor = packetData[offset++];
        wchar_t legendText[512];
        int legendLength = ReadUserLookText(packetData,
                                            offset,
                                            legendText,
                                            512);
        legendText[legendLength++] = L'\r';
        legendText[legendLength] = 0;

        EPFTextEditObject *symbol =
            new EPFTextEditObject(m_legendPane, symbolIndex);
        m_legendPane->InsertText(L" ", 0);
        m_legendPane->InsertEmbeddedObject(symbol, 12, 12);

        short textStart = m_legendPane->GetTextLength();
        m_legendPane->InsertText(legendText, 0);
        short textEnd = m_legendPane->GetTextLength();

        unsigned int formatData[3] = { 0, textColor, 0 };
        m_legendPane->SetSelectionRange(textStart, textEnd);
        m_legendPane->ApplySelectionFormat(2, formatData);
        m_legendPane->SetSelectionRange(textEnd, textEnd);
    }

    m_legendPane->SetEditActiveState(false, false);
    m_legendPane->SetSelectionRange(0, 0);
    m_legendPane->SyncScrollbars();

    m_trailingProfileState = packetData[offset++];
    m_targetNameHighlighted = packetData[offset++];

    wcscpy_s(m_identityLine1, 256, identityLine1);
    wcscpy_s(m_identityLine2, 256, identityLine2);
    wcscpy_s(m_headerText, 128, headerText);
    wcscpy_s(m_targetUserName, 128, targetUserName);
    m_status = status;

    m_bodyId = bodyId;
    m_bodyPalette = bodyPalette;
    m_leftHandId = leftHandId;
    m_leftHandPalette = leftHandPalette;
    m_rightHandId = rightHandId;
    m_rightHandPalette = rightHandPalette;
    m_headId = headId;
    m_headPalette = headPalette;
    m_rightAccessoryId = rightAccessoryId;
    m_rightAccessoryPalette = rightAccessoryPalette;
    m_leftAccessoryId = leftAccessoryId;
    m_leftAccessoryPalette = leftAccessoryPalette;
    m_faceAccessory1Id = faceAccessory1Id;
    m_faceAccessory1Palette = faceAccessory1Palette;
    m_headAccessory2Id = headAccessory2Id;
    m_headAccessory2Palette = headAccessory2Palette;
    m_leftSubAccessoryId = leftSubAccessoryId;
    m_leftSubAccessoryPalette = leftSubAccessoryPalette;
    m_rightSubAccessoryId = rightSubAccessoryId;
    m_rightSubAccessoryPalette = rightSubAccessoryPalette;
    m_necklaceId = necklaceId;
    m_necklacePalette = necklacePalette;
    m_footId = footId;
    m_footPalette = footPalette;
    m_coatId = coatId;
    m_coatPalette = coatPalette;
    m_mantleId = mantleId;
    m_mantlePalette = mantlePalette;

    m_viewMode = 1;
    m_moreInfoPane->RemoveFromLayer();
    m_moreInfoPane->UnregisterEventHandler();
    m_profilePane->RemoveFromLayer();
    m_profilePane->UnregisterEventHandler();
    m_legendPane->RemoveFromLayer();
    m_legendPane->UnregisterEventHandler();
    ShowMoreInfoView();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - `by-class/UserLookPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MoreInfoPane;
class ProfilePane;
class LegendPane;

class UserLookPane : public PanelPane
{
public:
    UserLookPane();
    virtual ~UserLookPane();

    virtual void OnDraw();
    virtual void OnActivate(const unsigned char *packetData);
    virtual int OnMouseEvent(Event *event);
    virtual int OnKeyEvent(Event *event);

    void GetActionButtonRect(short actionIndex, RectBounds *bounds) const;
    short HitTestActionButton(int x, int y) const;
    void ShowMoreInfoView();
    void ShowProfileView();
    void ShowBioView();
    void ShowLegendView();

private:
    MoreInfoPane *m_moreInfoPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_identityLine3[256];
    wchar_t m_headerText[128];
    wchar_t m_targetUserName[128];
    wchar_t m_moreInfoText[256];
    ObjectStatusBlob m_status;
    unsigned short m_bodyId;
    unsigned char m_bodyPalette;
    unsigned char m_bodyPadding;
    unsigned short m_leftHandId;
    unsigned char m_leftHandPalette;
    unsigned char m_leftHandPadding;
    unsigned short m_rightHandId;
    unsigned char m_rightHandPalette;
    unsigned char m_rightHandPadding;
    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned char m_headPadding;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned char m_rightAccessoryPadding;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned char m_leftAccessoryPadding;
    unsigned short m_faceAccessory1Id;
    unsigned short m_headAccessory2Id;
    unsigned char m_faceAccessory1Palette;
    unsigned char m_headAccessory2Palette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;
    unsigned short m_necklaceId;
    unsigned char m_necklacePalette;
    unsigned char m_necklacePadding;
    unsigned short m_footId;
    unsigned char m_footPalette;
    unsigned char m_footPadding;
    unsigned short m_coatId;
    unsigned char m_coatPalette;
    unsigned char m_coatPadding;
    unsigned short m_mantleId;
    unsigned char m_mantlePalette;
    unsigned char m_trailingProfileState;
    unsigned char m_targetNameHighlighted;
    unsigned char m_paddingB7D[3];
    unsigned int m_targetObjectId;
    unsigned char m_exchangeActionState;
    unsigned char m_groupActionState;
    unsigned char m_portraitFallbackFrame;
    unsigned char m_moreInfoLength;
    unsigned short m_portraitPayloadLength;
    unsigned char m_paddingB8A[2];
    _AUTOBUF<unsigned char> m_portraitBuffer;
    unsigned char m_profileTextLength;
    unsigned char m_paddingB99;
    wchar_t m_profileText[256];
    unsigned char m_paddingD9A[2];
    EPFTileContext m_portraitImage;
    int m_viewMode;
    unsigned char m_statusEncoding;
    unsigned char m_paddingDC9[7];
    int m_hoverActionIndex;
    int m_pressedActionIndex;
    unsigned short m_serverProfileValue;
    unsigned char m_paddingDDA[2];
};

typedef char UserLookPaneSizeMustBeDDC[
    (sizeof(UserLookPane) == 0xddc) ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - `by-class/MoreInfoPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class MoreInfoPane : public TextEditPane
{
public:
    MoreInfoPane();
    virtual ~MoreInfoPane();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual int OnMouseEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - `by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MoreInfoPane::MoreInfoPane()
    : TextEditPane(145,
                   108,
                   145,
                   108,
                   128,
                   0,
                   false,
                   true,
                   6,
                   IsLegacyAssetMode(),
                   true,
                   false)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - `by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int MoreInfoPane::OnKeyEvent(Event *event)
{
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - `by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int MoreInfoPane::OnMouseEvent(Event *event)
{
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - `by-class/ProfilePane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class ProfilePane : public TextEditPane
{
public:
    ProfilePane();
    virtual ~ProfilePane();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual int OnMouseEvent(Event *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - `by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ProfilePane::ProfilePane()
    : TextEditPane(145,
                   108,
                   145,
                   108,
                   128,
                   0,
                   false,
                   true,
                   6,
                   IsLegacyAssetMode(),
                   true,
                   false)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - `by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ProfilePane::OnKeyEvent(Event *event)
{
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 10 - `by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int ProfilePane::OnMouseEvent(Event *event)
{
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 11 - `by-class/TextEditPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class List;
class TextEditObject;
class TextEditScrap;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int maxWidth,
                 int maxHeight,
                 int contentWidth,
                 int contentHeight,
                 int backgroundColor,
                 int scrollColor,
                 char hasHorizontalScrollbar,
                 char hasVerticalScrollbar,
                 unsigned int styleFlags,
                 unsigned short legacyAssetMode,
                 char isReadOnly,
                 char inputMode);
    virtual ~TextEditPane();

    short CopyWideText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &
        GetText(mystr::StringBase<wchar_t,
                mystr::mychar_traits<wchar_t> > &outText) const;
    short GetTextLength() const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);

    void InsertText(const wchar_t *text, int flags);
    void SetText(const wchar_t *text, short length, short selectStart, short selectEnd);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask, const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    unsigned char GetMode() const { return m_mode; }

    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual int OnKeyEvent(Event *event);
    virtual int OnMouseEvent(Event *event);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelection();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    void AutoScrollSelectionToPoint(int x, int y);

private:
    List *m_textStorage;
    List *m_lineTable;
    List *m_styleRuns;
    List *m_formatRecords;
    short m_selectionStart;
    short m_selectionEnd;
    unsigned int m_editorFlags;
    unsigned char m_mouseMode;
    unsigned char m_dirty;
    unsigned char m_maskedText;
    short m_maxLength;
    short m_maxLines;
    unsigned char m_inputState;
    unsigned char m_lineLimitState;
    unsigned char m_formatMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 12 - `by-class/EPFTextEditObject.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TextEditPane;

class EPFTextEditObject : public TextEditObject
{
public:
    EPFTextEditObject(TextEditPane *owner, unsigned char symbolIndex);
    virtual ~EPFTextEditObject();

    virtual void OnUpdate();

private:
    EPFTileContext m_frame;
};

typedef char EPFTextEditObjectSizeMustBe3C[
    (sizeof(EPFTextEditObject) == 0x3c) ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: Destination 1 deliberately keeps unknown-status zero consumption, malformed raw-portrait zero-skip, source-order pane removal, no packet bounds checks, and compiler-natural stack/rangecheck behavior.
- Source shape: repeated packet operations are represented by file-local inline helpers that plausibly produced the unrolled optimized body; raw runtime thunks and `sub_` names are absent.
- Naming convention: project class/method spelling and current accepted PacketBuffer/ObjectStatus/AUTOBUF/EPF APIs are used; unresolved product semantics use descriptive names documented with confidence caps.

## Final Recommendation

- C01-C37 were applied or verified at full report-level detail in the accepted scope. All twelve exact managed destinations are populated, and no other C++ destination was introduced.
- UID0003RK remains exact and unsplit with owner/emitter UID0000FP, reconstructable true, blank position, and `Nested:0`; only its scores changed to `92/93`.
- Class, local-pane, TextEdit, EPF, file, aggregate, child, vtable, and read-only support pages were synchronized as listed while preserving unrelated formal content, metadata, source routes, and independent history.
- The aggregate, raw senders, ResourceLayout raw helper, vtables/read-only data, compiler cleanup/destructors, and padding remain blank/non-emitting for the stated target-specific reasons.
- Exact supervisor-owned manual coverage additions/replacements remain preserved under the dedicated section. B005 did not edit any coverage report.
- Outside scope remains limited to independent reconstruction of UserLook renderer/mouse/key/view helper bodies and recovery of original PDB lexical spellings; neither blocks the implemented target.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md`.
- Applied and verified: exact boundary/instruction/CFG/ABI/vtable evidence, full packet progression, field map, caller/callee relationships, status/equipment/image/profile/legend/text behavior, source placement, historical aliases, negative evidence, and score rationale were incorporated without compression.
- Applied metadata: `86/90 -> 92/93`; UID, range, owner/emitter UID0000FP, reconstructable true, blank position, and `Nested:0` were preserved.
- Applied formal block: Destination 1 exactly. The current Item Summary identifies the primary `+0x48` `OnActivate` override and complete packet/status/equipment/portrait/profile/legend population plus overview transition without repeating generated metadata.
- Manual coverage consequence: UID0003RK still has no current `by-memory/-coverage-report.md` row. The exact pending supervisor-owned addition below remains external to B005's callback edits.

## Recommended Support Doc Changes

- `by-class/UserLookPane.md`: Destination 2, `88/90 -> 90/92`, exact `0xddc` layout/method/vtable/packet evidence, descriptive-name confidence caps, and dependency/negative dispositions were applied and verified.
- `by-file/UserLookPane.md`: `89/88 -> 90/90`; route and inventory were preserved, target OnActivate schema/layout and local-pane source readiness were added, and raw-sender exclusion plus the generated-empty historical baseline remain explicit. No by-file formal block was added.
- `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`: `88/90`, false/non-emitting aggregate status, and blank block were preserved; complete target disposition, exact no-split boundary, and destination ownership were added.
- `by-class/MoreInfoPane.md`, UID0003RX/RY/RZ, and MoreInfo vtable docs: Destinations 3-6 and accepted scores were applied; inherited event names replaced generic current names while no-route constructor history and singleton/local-owner evidence were preserved.
- `by-class/ProfilePane.md`, UID0003S0/S1/S2, and Profile vtable docs: Destinations 7-10 and accepted scores were applied; separation from ProfileDialog remains explicit.
- `by-class/TextEditPane.md`: score, route, and all prior formal lines were preserved; only Destination 11's forward declaration and three methods were added with exact target caller evidence. The by-file TextEditPane page received prose-only dependency synchronization with no score/body change.
- `by-class/EPFTextEditObject.md`: Destination 12, `86/90 -> 89/92`, exact 60-byte/base/frame/vtable/caller evidence, and EPF/EPD plus method-body caveats were applied and preserved.
- UserLook constructor/renderer/mouse/key/action/view children and UserLook vtable/read-only pages received prose-only synchronization for exact fields, the OnActivate slot, target caller/consumer roles, and name confidence. Their existing scores/formal blocks were preserved.
- ObjectStatusBlob class/parser/file, PacketBuffer readers, AUTOBUF class/resize, JPF decoder, ResourceLayout UID0002KQ, EPFTileContext, LegendPane, TextEditObject, MemoryMan copy helper, and globals remained verify-only dependencies with existing owner/scores/formal blocks intact.
- UID0003RV/UID0003RW remain no-route raw helpers and were not added to the class declaration. Compiler scalar/adjustor destructors, EH nodes, vtables/RTTI, strings, and padding remain non-body support.
- Manual coverage consequence: every exact pending by-memory/by-class/by-file replacement/addition for changed rows remains below; rows classified verify-only require no coverage edit.

## Score And Metadata Recommendation

- Target historical baseline: `86/90`, UID0000FP owner/emitter, true, blank position, `Nested:0`.
- Target implemented state: `92/93`, all non-score metadata unchanged.
- Completion rises because every instruction/block, packet field, helper, consumer, class field, source route, and emitting body is resolved. Confidence remains 93 because several original lexical names are descriptive rather than symbol-proven and wire bounds are absent by design.
- Implemented support scores: UserLook class `90/92`; MoreInfo/Profile classes `90/92`; raw constructors `88/91`; false stubs `89/92`; EPF class `89/92`; TextEdit class unchanged `90/91`; UserLook file `90/90`; aggregate unchanged `88/90`.
- UserLook's score remains capped by other large renderer/input method bodies that are separate blank children.
- Score-improvement attempts: method-name blocker resolved through base/vtable inventory; ABI through stack/return; schema through full instruction progression; fields through all consumers/allocation size; status/image/editor dependencies through current exact docs; raw local-pane names through vtable slots; EPF type through exact sizes/vtable. Original PDB spellings and wider sibling bodies remain the only caps.
- No owner, emitter, reconstructable, range, Nested, or new-UID change was made.

## Open Questions With Attempted Resolution

- Original names for identity lines 1-3 and header: renderer positions and widths were exhausted; no symbol/string/caller distinguishes product labels. Resolution: descriptive stable names, no C++ blocker, confidence cap only.
- `+0xdd8` semantic name: parser and all UserLook sibling consumers were checked; no read exists. Resolution: exact unsigned-short type/storage with descriptive `m_serverProfileValue`; no invented gameplay meaning.
- `+0xb7b` semantic name: final parse and all renderer/input consumers checked; only neighboring `+0xb7c` has a direct color consumer. Resolution: `m_trailingProfileState`, explicitly descriptive.
- Raw ResourceLayout helper original name/body: current UID0002KQ and neighboring loaders were rechecked. The two-argument callsite is safe to name descriptively, but its own next-row/sentinel source remains unresolved. Resolution: target calls dependency; UID0002KQ block stays blank and target does not reproduce its body.
- Raw local-pane constructors: no direct raw-start route exists, but complete bodies, vtables, class construction context, and retained local symbols resolve source declarations. Resolution: emit exact source constructors and retain no-route history as confidence evidence.
- No question remains that blocks the target code, owner, range, score, or support declaration plan.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual coverage is applicable and supervisor-owned. B005 read the current reports without editing them. The exact text below is pending external application only after the corresponding accepted callback changes exist; it must not be applied as report-only research state.
- The validator-generated `auto-generated/-ag-research-tracker.md` remains validator-owned and requires no manual row text. This artifact does not freeze its report count or lifecycle state.

### `by-memory/-coverage-report.md`

Placement: under `## Summary`, add this exact historical synchronization line only when the rows below have actually been applied:

```text
- Manual update: 2026-07-13 supervisor synchronized UID0003RK UserLookPane OnActivate source-quality coverage after the accepted B005 callback: the non-emitting UID0001KK aggregate remains 88/90, exact parser/local-pane/vtable rows now reflect their current source or no-code dispositions, and UserLookPane/MoreInfoPane/ProfilePane ownership remains routed through UserLookPane.cpp.
```

Replace the existing UID0001KK row at the `0x0059f260` address position with this exact row:

```text
    - [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) 0x0059f260-0x005a2523 | class-method aggregate | UserLookPaneAndProfilePanes : not_reconstructable : 88% : strong : Non-emitting UserLookPane.cpp split index over exact constructor/destructor/OnActivate/render/input/view/local-pane children; preserves complete UID0003RK packet/layout evidence, raw sender and compiler-glue exclusions, UserPane/LegendPane boundaries, and blank aggregate C++ because exact children own source.
```

Add these exact changed-child rows beneath UID0001KK in address order. The eight-space indentation records the child level established by UID0003RI `Nested:4`; subsequent `Nested:0` rows remain at that level:

```text
        - [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md) 0x0059f260-0x0059f4fd | constructor | UserLookPaneConstructor : reconstructable : 86% : strong : Exact UserLookPane constructor with GeneralPurposePanel caller, 0xddc allocation/layout, UserLookPane/MoreInfoPane/ProfilePane vtable stores, local child construction, LegendPane attachment, MoreInfo singleton alias write, and source route through UserLookPane.cpp; target-derived field names remain descriptive where original symbols are stripped.
        - [UID:0003RK][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) 0x0059f610-0x005a0626 | virtual method | UserLookPaneParseLookPacket : reconstructable : 92% : very-strong : Exact primary-vtable +0x48 UserLookPane::OnActivate override; preserves the 4,118-byte/1,080-instruction/31-block body, byte-length ANSI strings, 43/5-byte ObjectStatus parsing, fourteen equipment records, more-info/profile/legend TextEdit population, JPF/raw portrait branches including malformed zero-skip behavior, final pane transition, boundary padding, and complete human-source C++.
        - [UID:0003RM][0x005a0640-0x005a157d.UserLookPaneRenderUserLook](by-memory/0x005a0640-0x005a157d.UserLookPaneRenderUserLook.md) 0x005a0640-0x005a157d | virtual method | UserLookPaneRenderUserLook : reconstructable : 86% : strong : Vtable-routed UserLook renderer consuming the accepted identity/header/name, ObjectStatus, fourteen equipment-slot, portrait/action/highlight, and view-mode fields; resource/string/action-rectangle evidence and separate shared STATBUT.EPF/LegendPane ownership remain preserved.
        - [UID:0003RN][0x005a1580-0x005a1985.UserLookPaneHandleMouseEvent](by-memory/0x005a1580-0x005a1985.UserLookPaneHandleMouseEvent.md) 0x005a1580-0x005a1985 | virtual method | UserLookPaneHandleMouseEvent : reconstructable : 86% : strong : Vtable-routed mouse handler consuming target object id, target user name, action-state bytes, hover/pressed indices, action-button hit-test/rect helpers, and MoreInfo/Profile/Bio/Legend view switches; raw packet senders remain no-route file-local dependencies.
        - [UID:0003RO][0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent](by-memory/0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md) 0x005a19a0-0x005a1a6f | virtual method | UserLookPaneHandleKeyEvent : reconstructable : 85% : strong : Vtable-routed key handler over the accepted four-value view mode and MoreInfo/Profile/Bio/Legend switch helpers; exact key-enum lexical names remain the documented confidence cap.
        - [UID:0003RP][0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect](by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md) 0x005a1a70-0x005a1b4d | method | UserLookPaneGetActionButtonRect : reconstructable : 86% : strong : Exact UserLookPane action-button rectangle helper with six renderer/mouse call sites, accepted signed action index and RectBounds output declaration, and action-state field consumers synchronized to UID0003RK.
        - [UID:0003RQ][0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton](by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md) 0x005a1b70-0x005a1caf | method | UserLookPaneHitTestActionButton : reconstructable : 86% : strong : Exact signed-short UserLookPane action-button hit test paired with GetActionButtonRect, called twice by the mouse handler, and synchronized with accepted action-state/hover/pressed field roles.
        - [UID:0003RR][0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView](by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md) 0x005a1cd0-0x005a1dee | method | UserLookPaneShowMoreInfoView : reconstructable : 86% : strong : MoreInfo view switch called by OnActivate and input handlers; sets accepted mode 0, reattaches/layouts the MoreInfoPane child, and preserves separate ProfilePane/LegendPane ownership.
        - [UID:0003RS][0x005a1df0-0x005a1f16.UserLookPaneShowProfileView](by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md) 0x005a1df0-0x005a1f16 | method | UserLookPaneShowProfileView : reconstructable : 86% : strong : Profile view switch called from input handlers; uses accepted mode 2 and the ProfilePane child populated by UID0003RK while preserving separation from ProfileDialog.
        - [UID:0003RT][0x005a1f20-0x005a1fe3.UserLookPaneShowBioView](by-memory/0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md) 0x005a1f20-0x005a1fe3 | method | UserLookPaneShowBioView : reconstructable : 85% : strong : Biography/profile-text view switch called from input handlers and synchronized with UID0003RK ProfilePane population; exact original tab spelling remains provisional without changing behavior or ownership.
        - [UID:0003RU][0x005a1ff0-0x005a2188.UserLookPaneShowLegendView](by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md) 0x005a1ff0-0x005a2188 | method | UserLookPaneShowLegendView : reconstructable : 86% : strong : Legend view switch called from input handlers; uses accepted mode 3 and the UID0003RK-populated shared LegendPane child without transferring LegendPane source ownership to UserLookPane.
        - [UID:0003RX][0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor](by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md) 0x005a22e0-0x005a233d | constructor | MoreInfoPaneRawConstructor : reconstructable : 88% : very-strong : Complete retained MoreInfoPane source constructor with exact fixed TextEditPane base arguments and three local vtable stores; no direct raw-start xref remains preserved as confidence/liveness history rather than suppressing the accepted constructor body.
        - [UID:0003RY][0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA](by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md) 0x005a2340-0x005a2345 | virtual method | MoreInfoPaneAlwaysFalseVirtualA : reconstructable : 89% : very-strong : Exact MoreInfoPane::OnKeyEvent override at the inherited secondary vtable slot; ignores Event and returns false, superseding the generic AlwaysFalse source name while preserving the exact six-byte body.
        - [UID:0003RZ][0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB](by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md) 0x005a2350-0x005a2355 | virtual method | MoreInfoPaneAlwaysFalseVirtualB : reconstructable : 89% : very-strong : Exact MoreInfoPane::OnMouseEvent override at the inherited primary vtable slot; ignores Event and returns false, superseding the generic AlwaysFalse2 source name while preserving the exact six-byte body.
        - [UID:0003S0][0x005a2360-0x005a23bd.ProfilePaneRawConstructor](by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md) 0x005a2360-0x005a23bd | constructor | ProfilePaneRawConstructor : reconstructable : 88% : very-strong : Complete retained ProfilePane source constructor with exact fixed TextEditPane base arguments and three local vtable stores; no direct raw-start xref remains preserved as confidence/liveness history and ProfileDialog ownership remains rejected.
        - [UID:0003S1][0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA](by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md) 0x005a23c0-0x005a23c5 | virtual method | ProfilePaneAlwaysFalseVirtualA : reconstructable : 89% : very-strong : Exact ProfilePane::OnKeyEvent override at the inherited secondary vtable slot; ignores Event and returns false, replacing the generic stub name without changing the six-byte body.
        - [UID:0003S2][0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB](by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md) 0x005a23d0-0x005a23d5 | virtual method | ProfilePaneAlwaysFalseVirtualB : reconstructable : 89% : very-strong : Exact ProfilePane::OnMouseEvent override at the inherited primary vtable slot; ignores Event and returns false, replacing the generic stub name without changing the six-byte body.
```

Replace the existing UID00026V row at the `0x0062eccc` address position, then add UID00038S and UID00038T immediately after it in address order:

```text
    - [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md) 0x0062eccc-0x0062ef0c | vtable/string-data | UserLookReadOnlyData : reconstructable : 86% : very-strong : UserLookPane.cpp read-only island with exact UserLookPane/MoreInfoPane/ProfilePane vtable families, primary +0x48 OnActivate route to UID0003RK, corrected local key/mouse override slots, resource-string tail, UserList/UserPane boundaries, and blank data C++ because declarations/resource references regenerate the storage.
    - [UID:00038S][0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData](by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md) 0x0062ed58-0x0062ee0c | vtable-data | MoreInfoPaneVtableData : reconstructable : 88% : very-strong : Exact MoreInfoPane primary/secondary/tertiary vtable data assigned to UserLookPaneFamilyVtables; slots resolve the accepted TextEditPane inheritance plus OnKeyEvent and OnMouseEvent false overrides, and raw data remains non-body source support.
    - [UID:00038T][0x0062ee0c-0x0062eebc.ProfilePaneVtableData](by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md) 0x0062ee0c-0x0062eebc | vtable-data | ProfilePaneVtableData : reconstructable : 88% : very-strong : Exact ProfilePane primary/secondary/tertiary vtable data assigned to UserLookPaneFamilyVtables; slots resolve the accepted TextEditPane inheritance plus OnKeyEvent and OnMouseEvent false overrides, and raw data remains non-body source support.
```

### `by-class/-coverage-report.md`

Placement: under `## Summary`, add this exact line only after the callback rows are current:

```text
- Manual update: 2026-07-13 supervisor synchronized UID0003RK class coverage after the accepted B005 callback: UserLookPane, MoreInfoPane, ProfilePane, and EPFTextEditObject now carry complete accepted declaration/layout surfaces, while TextEditPane preserves its prior class content and adds only the three target-required rich-text APIs.
```

Replace the five existing rows in their current alphabetic positions with exactly:

```text
- [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md) : reconstructable : 89% : very-strong : Exact 0x3c TextEditObject derivative declaration with TextEditPane owner/symbol constructor, live OnUpdate override, embedded 0x28 EPFTileContext frame, constructor/destructor/vtable/resource evidence, UID0003RK legend caller, and preserved EPF/EPD plus method-body caveats.
- [UID:00008Q][MoreInfoPane](by-class/MoreInfoPane.md) : reconstructable : 90% : very-strong : UserLookPane.cpp-local read-only TextEditPane derivative with exact fixed constructor, inherited OnKeyEvent/OnMouseEvent false overrides, complete declaration and child placement, vtable/read-only/singleton evidence, and preserved no-direct-raw-start history.
- [UID:0000AV][ProfilePane](by-class/ProfilePane.md) : reconstructable : 90% : very-strong : UserLookPane.cpp-local read-only TextEditPane derivative with exact fixed constructor, inherited OnKeyEvent/OnMouseEvent false overrides, complete declaration and child placement, vtable/view evidence, and explicit separation from editable ProfileDialog ownership.
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md) : reconstructable : 90% : very-strong : Full accepted TextEditPane declaration preserved without loss and synchronized with UID0003RK through the TextEditObject forward declaration plus ClearText, ApplySelectionFormat, and InsertEmbeddedObject APIs; all prior text/storage/editor, drawing, paste/line-count, viewport, text-area, callback, and field surfaces remain intact.
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md) : reconstructable : 90% : very-strong : Complete 0xddc PanelPane-derived remote-look declaration with constructor/destructor, OnDraw/OnActivate/mouse/key virtuals, action/view helpers, three child pointers, five display strings, exact 68-byte ObjectStatusBlob, fourteen equipment slots, portrait AUTOBUF/EPFTileContext, profile/legend/action/view state, vtable evidence, and descriptive-name confidence caps.
```

### `by-file/-coverage-report.md`

Placement: under `## Summary`, add this exact line only after the callback file pages are current:

```text
- Manual update: 2026-07-13 supervisor synchronized UID0003RK file coverage after the accepted B005 callback: UserLookPane.cpp now records the complete OnActivate packet/layout and local MoreInfoPane/ProfilePane source surfaces, while TextEditPane.cpp records the three consumed rich-text APIs without changing editor/support-object ownership.
```

Replace the two existing rows in their current alphabetic positions with exactly:

```text
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md) : reconstructable : 91% : strong : Rich text editor implementation with current class/support/callback inventory, active-editor/serialization/scrollbar ownership, exact TextEdit support-object split from TextFilter, and UID0003RK dependency synchronization for ClearText, selection formatting, and embedded EPF object insertion; score and source route remain unchanged.
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md) : reconstructable : 90% : strong : NexusTK/ui/panels/UserLookPane.cpp source grouping with complete UserLookPane OnActivate packet schema and 0xddc state layout, local MoreInfoPane/ProfilePane declarations and exact constructor/stub bodies, JPF/raw portrait dependencies, vtables/read-only/global evidence, raw sender/compiler exclusions, and shared LegendPane ownership preserved.
```

### Coverage Verify-Only Rows

- UID0003RV/UID0003RW raw packet senders, UID0003RJ/UID0003RL/UID0003S3/UID0003S4 compiler/destructor support, UID0002A8 MoreInfo singleton storage, UID00038Q/UserLookPaneFamilyVtables, ObjectStatusBlob, PacketBuffer, AUTOBUF, JPF/ImageDecode, ResourceLayout UID0002KQ, EPFTileContext, LegendPane, TextEditObject, MemoryMan, and relevant globals retain their current score/state/description unless the accepted callback actually changes their source pages. They require read-only verification, not speculative coverage replacement text.
- No manual tracker row is supplied. Any validator-generated tracker/report-count change is produced by authorized validation/lifecycle tooling, never by B005 or by manual text from this report.

## Follow-Up Actions

- B005 implementation work is complete: accepted target/support changes, managed blocks, scoped validations, final generated refresh, read-only generated inspection, lease release, and callback-state report reconciliation are all recorded in this artifact.
- Manual coverage application, report execution/archive, and any other lifecycle decision remain supervisor-owned external state. The exact coverage text is preserved above without asserting whether or when external state changes.
- A-agent actions: none. No unrelated B005 target work is part of this lifecycle.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong; `92/93` accurately reflects complete behavior with stripped-name caps.
- Remaining uncertainty: original lexical spellings for three identity lines, one header, two trailing scalars, and one external raw helper. Their types/behavior are exact, and none requires raw offsets or decompiler names in emitted source.

## Validator Results

- Historical report-only phase: no validator was run before Gate 1 because implementation validation was prohibited then.
- Callback command form for each ordinary page: `python validator.py --mode file --file '..\<path>' --apply --no-generated-refresh --queue-timeout 300`, executed from `tools/leaser`. Each page was re-read, leased alone, edited, scoped-validated, and immediately unleased.
- Final authorized command form: target-scoped validation with `--apply --wait-generated --queue-timeout 900`, run only after all ordinary pages had passed scoped validation.

| Command | Timestamp (America/New_York) | Scoped page / purpose | Result |
| --- | --- | --- | --- |
| `000000010135` | `2026-07-13T15:09:17-04:00` | UID0003RK target | exit 0; `ok:1` |
| `000000010136` | `2026-07-13T15:10:39-04:00` | UserLookPane class | exit 0; `ok:1` |
| `000000010137` | `2026-07-13T15:11:33-04:00` | MoreInfoPane class | exit 0; `ok:1` |
| `000000010138` | `2026-07-13T15:12:15-04:00` | MoreInfoPane constructor | exit 0; `ok:1` |
| `000000010139` | `2026-07-13T15:12:59-04:00` | MoreInfoPane OnKeyEvent | exit 0; `ok:1` |
| `000000010140` | `2026-07-13T15:13:53-04:00` | MoreInfoPane OnMouseEvent | exit 0; `ok:1` |
| `000000010148` | `2026-07-13T15:14:48-04:00` | ProfilePane class | exit 0; `ok:1` |
| `000000010156` | `2026-07-13T15:15:41-04:00` | ProfilePane constructor | exit 0; `ok:1` |
| `000000010158` | `2026-07-13T15:16:29-04:00` | ProfilePane OnKeyEvent | exit 0; `ok:1` |
| `000000010159` | `2026-07-13T15:17:17-04:00` | ProfilePane OnMouseEvent | exit 0; `ok:1` |
| `000000010161` | `2026-07-13T15:18:14-04:00` | TextEditPane class | exit 0; `ok:1` |
| `000000010162` | `2026-07-13T15:19:23-04:00` | EPFTextEditObject class | exit 0; `ok:1` |
| `000000010166` | `2026-07-13T15:20:43-04:00` | UserLookPane file | exit 0; `ok:1` |
| `000000010168` | `2026-07-13T15:21:38-04:00` | TextEditPane file | exit 0; `ok:1` |
| `000000010169` | `2026-07-13T15:22:46-04:00` | UserLookPane/Profile aggregate | exit 0; `ok:1` |
| `000000010170` | `2026-07-13T15:23:40-04:00` | UserLookPane constructor | exit 0; `ok:1` |
| `000000010171` | `2026-07-13T15:24:15-04:00` | UserLookPane renderer | exit 0; `ok:1` |
| `000000010172` | `2026-07-13T15:24:51-04:00` | UserLookPane mouse handler | exit 0; `ok:1` |
| `000000010173` | `2026-07-13T15:25:23-04:00` | UserLookPane key handler | exit 0; `ok:1` |
| `000000010179` | `2026-07-13T15:25:54-04:00` | action-button rectangle helper | exit 0; `ok:1` |
| `000000010184` | `2026-07-13T15:26:34-04:00` | action-button hit test | exit 0; `ok:1` |
| `000000010189` | `2026-07-13T15:27:07-04:00` | MoreInfo view helper | exit 0; `ok:1` |
| `000000010195` | `2026-07-13T15:27:44-04:00` | Profile view helper | exit 0; `ok:1` |
| `000000010202` | `2026-07-13T15:28:30-04:00` | Bio view helper | exit 0; `ok:1` |
| `000000010204` | `2026-07-13T15:29:14-04:00` | Legend view helper | exit 0; `ok:1` |
| `000000010206` | `2026-07-13T15:30:14-04:00` | UserLook read-only data | exit 0; `ok:1` |
| `000000010207` | `2026-07-13T15:30:52-04:00` | MoreInfoPane vtable data | exit 0; `ok:1` |
| `000000010208` | `2026-07-13T15:31:46-04:00` | ProfilePane vtable data | exit 0; `ok:1` |
| `000000010215` | `2026-07-13T15:32:58-04:00` | UserLookPane class post-edit recheck | exit 0; `ok:1` |
| `000000010216` | `2026-07-13T15:33:42-04:00` | target final `--wait-generated` refresh | exit 0; `ok:1`; generated refresh complete |

- Validator-owned side effects: scoped validation updated validator registration/projected state and generated documentation as designed; final command `000000010216` rebuilt the 4,707-node/3,828-edge registry, refreshed 280 generated metadata outputs, and regenerated `auto-generated/NexusTK/ui/panels/UserLookPane.cpp`. B005 did not hand-edit validator state, coverage, tracker, or generated output.
- Warning disposition: early scoped runs reported missing-reference/registry gaps for older split pages; these cleared as in-scope pages registered through their own validators. UID00038S/UID00038T reported `canonical_owner_unknown`/`emitter_uid_unknown` for verify-only UID00038Q absent from `validator.ini`; the accepted UID00038Q route was preserved, and the final registry/generated refresh still completed successfully. The final refresh also reported project-wide baseline counts of 199 `autogen_emitter_has_no_code`, 83 missing markers, and 15 fallback insertions; none was introduced as a blocker for this accepted target.
- Generated assertions, checked read-only: `UserLookPane.cpp` bears command `000000010216` and timestamp `2026-07-13T15:33:42-04:00`; source order is MoreInfoPane class/constructor/key/mouse, ProfilePane class/constructor/key/mouse, UserLookPane class, UID0003RK OnActivate, then later UserLook methods. The body includes full/partial status calls, profile clear, EPF inline insertion, mode-one assignment, and ShowMoreInfoView. UID0001KK, UID0003RV, UID0003RW, UID00038R, UID00038S, and UID00038T do not emit source bodies. `TextEditPane.cpp` contains the EPF class/size assertion and the TextEditPane forward declaration plus the three accepted rich-text APIs.
- Lease result: every ordinary page lease was released immediately after its validator. A final lease listing contained no B005 lease.

## Changed Files

- Callback artifact updated: `tools/leaser/Agents/Agent-B005/research/0003RK-UserLookPaneParseLookPacket-source-quality.md` (original report-only research preserved; callback proof/status added).
- Managed destination pages changed: `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md`; `by-class/UserLookPane.md`; `by-class/MoreInfoPane.md`; `by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md`; `by-memory/0x005a2340-0x005a2345.MoreInfoPaneAlwaysFalseVirtualA.md`; `by-memory/0x005a2350-0x005a2355.MoreInfoPaneAlwaysFalseVirtualB.md`; `by-class/ProfilePane.md`; `by-memory/0x005a2360-0x005a23bd.ProfilePaneRawConstructor.md`; `by-memory/0x005a23c0-0x005a23c5.ProfilePaneAlwaysFalseVirtualA.md`; `by-memory/0x005a23d0-0x005a23d5.ProfilePaneAlwaysFalseVirtualB.md`; `by-class/TextEditPane.md`; `by-class/EPFTextEditObject.md`.
- Prose-only support pages changed: `by-file/UserLookPane.md`; `by-file/TextEditPane.md`; `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`; `by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md`; `by-memory/0x005a0640-0x005a157d.UserLookPaneRenderUserLook.md`; `by-memory/0x005a1580-0x005a1985.UserLookPaneHandleMouseEvent.md`; `by-memory/0x005a19a0-0x005a1a6f.UserLookPaneHandleKeyEvent.md`; `by-memory/0x005a1a70-0x005a1b4d.UserLookPaneGetActionButtonRect.md`; `by-memory/0x005a1b70-0x005a1caf.UserLookPaneHitTestActionButton.md`; `by-memory/0x005a1cd0-0x005a1dee.UserLookPaneShowMoreInfoView.md`; `by-memory/0x005a1df0-0x005a1f16.UserLookPaneShowProfileView.md`; `by-memory/0x005a1f20-0x005a1fe3.UserLookPaneShowBioView.md`; `by-memory/0x005a1ff0-0x005a2188.UserLookPaneShowLegendView.md`; `by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md`; `by-memory/0x0062ed58-0x0062ee0c.MoreInfoPaneVtableData.md`; `by-memory/0x0062ee0c-0x0062eebc.ProfilePaneVtableData.md`.
- Verify-only dependency pages: UID00038Q/UserLookPaneFamilyVtables, UID0003RV/UID0003RW raw senders, compiler/destructor/EH supports, ObjectStatusBlob, PacketBuffer, AUTOBUF, JPF/ImageDecode, ResourceLayout UID0002KQ, EPFTileContext, LegendPane, TextEditObject, MemoryMan, and globals listed in C28-C32 were read or cross-checked but not edited.
- Validator-owned outputs changed as validation side effects and were inspected read-only where relevant. No manual `-coverage-report.md`, generated C++, tracker, supervisor, audit, registry, queue, lock, or validator-state edit was made by B005.
- Renamed/moved/archived/deleted: none. `execute_report`, report probe, and lifecycle commands were not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Historical Gate 1 acceptance recorded for exact pre-callback SHA `F588A5E3E72871DA2815FE2000B12B09031F6358722E80BB98095B8045D98EB4`.
- [x] Target/support scope covered UID0003RK, UserLookPane class/file/aggregate and relevant children/vtables, MoreInfo/Profile classes/raw constructors/stubs/vtables, TextEditPane class/file, EPFTextEditObject class, and listed verify-only dependencies.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger contains a legal action and callback verification state for every C01-C37 claim, with separate proof notes.
- [x] Applied scores: target `92/93`, UserLook class `90/92`, UserLook file `90/90`, local-pane/support scores exactly as listed; all other metadata preserved.
- [x] Score-limiting blockers researched to the exact resolutions and confidence caps in this report.
- [x] Owner/emitter/reconstructable changes excluded as unnecessary; all accepted routes preserved.
- [x] No split or new UID was introduced; source-facing method/stub names were synchronized as accepted.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment dispositions were applied or confirmed not applicable.
- [x] All twelve exact first-draft managed blocks were applied byte-for-byte and re-compared after validation.
- [x] Third-party import directive confirmed not applicable; no `third_party_embeds/...` path or import block was added.
- [x] Exact target/support facts were incorporated at report-level detail without compressing schema, layout, evidence, negatives, or historical assumptions.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence were preserved.
- [x] Wave2/Wave3/simroot references remain stale history only and were not used as authority.
- [x] Open questions were closed or retained with exact evidence-backed confidence impact.
- [x] One scoped validator ran for each changed ordinary by-* page under a short one-file lease, followed by immediate release.
- [x] Final authorized waited generated refresh completed; UserLookPane.cpp and TextEditPane.cpp were inspected read-only for accepted declarations, body, source order, and exclusions.
- [x] Exact pending supervisor-owned by-memory/by-class/by-file coverage additions/replacements remain supplied above and were not applied by B005.

Implementation callback pass:
- [x] Supervisor accepted the exact report-only artifact and authorized implementation.
- [x] All accepted target/support document details were incorporated at report-level detail.
- [x] Claim And Incorporation Ledger uses legal callback states and separate destination proof for every accepted claim.
- [x] Metadata, scores, source names, and C++ changes were applied; unchanged owner/emitter/split states and exclusions carry exact reasons.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, and no-code dispositions were preserved.
- [x] Open questions were resolved or documented with evidence-backed confidence impact.
- [x] Validator command IDs, timestamps, exit/ok results, warnings, generated side effects, and lease releases are recorded.
- [x] Final generated refresh completed and relevant outputs were checked read-only; exact manual coverage text remains supervisor-owned external state and tracker state remains validator-owned.
- [x] No accepted callback item is blocked or unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000010271","destination_path":"executed-b-agent-research/B005/0003RK-UserLookPaneParseLookPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003RK-UserLookPaneParseLookPacket-source-quality.md","timestamp":"2026-07-13T15:59:08-04:00","uid":"0003RK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
