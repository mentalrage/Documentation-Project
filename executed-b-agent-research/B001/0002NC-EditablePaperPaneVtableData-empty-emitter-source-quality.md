# 0002NC EditablePaperPane Vtable Data Empty-Emitter Source-Quality Research
** TARGET-REPORT-UID:0002NC **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

Project context: this report supports local preservation and behaviorally faithful source reconstruction of the unsupported NexusTK client.

## Finalized Report / Current Recommendation

- Correct [UID:0002NC] from assignment range `[0x00621afc,0x00621b98)` to the complete compiler-emitted island `[0x00621af8,0x00621b98)`. The omitted dword at `0x00621af8` is the primary complete-object RTTI locator predecessor; [UID:0002OG] ends exactly there and already excludes it from PanelPane.
- Preserve one 160-byte, 40-dword, gap-free island: primary locator plus 24 slots, secondary locator plus 11 slots, tertiary locator plus 2 slots. `LINE001.EPD` starts at `0x00621b98` and is the exact successor boundary, not a fourth table item.
- Make the vtable-data target and [UID:0001XF] compiler-generated, non-reconstructable, class-owned evidence with blank emitters. Emit no handwritten arrays, locator pointers, vptr stores, deleting wrappers, or adjustor thunks.
- Move the direct canonical owner/emitter to [UID:000048] EditablePaperPane. Supply the complete `DialogPane`-derived declaration there, source-ready method definitions through [UID:0001EE], and the stable `NexusTK/ui/dialogs/EditablePaperPane.cpp/.h` route through [UID:0000IX].
- Correct the primary `+0x48` override to `OnControlCommand(int controlIndex, int notifyCode)`; preserve `InitializePaperContent` as the new protected primary `+0x5c` virtual. Source inherits EventHandler and TimerHandler only through Pane/DialogPane.
- Resolve the retained wrappers at `0x005128a0` and `0x00512900` as file-static `MapPane.cpp` packet adapters for editable and read-only construction. Their zero-inbound-xref state is a retained liveness caveat, not a source blocker.
- Recommended scores are target `94/96`, vtable type `94/96`, class `94/94`, file `94/93`, method aggregate `94/93`, and adjustor support `92/96`.
- The accepted ordinary implementation is complete and physically verified. Exactly 52 claim twins are checked; only C41-C46 remain unchecked because the six IDA recommendations are supervisor-owned Gate 2B work. Manual coverage text is supplied as an exact supervisor handoff without editing coverage, and lifecycle authority remains external to the ordinary report body.

## Supporting Research

- Fresh read-only IDA evidence was collected on 2026-08-16. Before each later MCP group, `idb_list` was enumerated and the then-current active session was used instead of a cached session identifier.
- Bulk target audit session: `supervisor_uid000480_i01rollback_20260816`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19856`. A later fresh `idb_list` enumerated replacement session `supervisor_uid0000li_i37rollback2_20260816`, worker PID `13544`; bounded constructor decompilation and `server_health` again succeeded there. The latest report-time health receipt was `status:ok`, imagebase `0x400000`, module `NexusTK.exe`, Hex-Rays ready, strings cache not ready, and `auto_analysis_ready:false`. Successful bounded queries establish usable MCP despite the two non-ready cache/analysis flags.
- Canonical IDB disk snapshot: SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, 143,208,000 bytes, observed last-write `2026-08-16T00:11:53.0765079-04:00`. B001 made no IDA mutation, backup, save, or process-control request.
- One whole-image text search was too broad and timed out while the listener remained present. B001 stopped broad querying, waited for the supervisor-owned listener, re-enumerated sessions, and repeated all material facts with bounded queries on the final active session. The recovered bounded results, not the timeout, support this report.
- Assignment-time target: SHA256 `B5C80747D0D53E6A23A77E8D74CA258B6927887CD967ACFDF563A39980A633F8`, 8,971 bytes / 103 physical lines, score `88/92`, owner/emitter [UID:0001XF], reconstructable true, blank formal CPP/H.
- Dated generated snapshot: `auto-generated/NexusTK/ui/dialogs/EditablePaperPane.cpp`, validator command `000000024635`, refreshed `2026-08-16T01:16:54-04:00`, SHA256 `1B1599983D16B437EA63A6641B3150AFC03BFF89EFDA0C2503D1B9846BF186DF`, 8,243 bytes / 264 newline-terminated physical lines. It contains three empty-emitter markers for UID000048, UID0001XF, and UID0002NC; no generated H exists. This is a dated pre-callback observation, not continuing authority after validator activity.
- Duplicate searches found no matching primary or additional UID declaration in active agent research or executed B-agent research. The research tracker snapshot showed zero reports for the target; no additional target UID is declared here.

## Target

- Assignment-time target: [UID:0002NC] `by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md`.
- Implemented same-UID destination: `by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md`; the old path is absent after scoped validation.
- Current implemented metadata: `COMPLETION:94`, `CONFIDENCE:96`, `CANONICAL_OWNER:000048`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, comment-only formal CPP, blank formal H, `Nested:0`.
- Correct entity kind: compiler-generated three-view vtable/RTTI island. It is exact class evidence but has no independent human-written storage definition.
- Correct binary identity: `[0x00621af8,0x00621b98)`, 160 bytes, SHA256 `333CABA0EA935B111622DCA266CB46993EABE7CC33EF674E29F5CA909C9DE468`.

## Current Target State

- Historical pre-callback prose correctly identified the three table heads, constructor stores, adjustor thunks, short tertiary table, and `LINE001.EPD` boundary, but began four bytes late and omitted the primary complete-object locator pointer. The implemented target now begins at `0x00621af8` and preserves that extraction error explicitly as history.
- Historical pre-callback target/type metadata routed compiler output through a reconstructable blank emitter. UID0002NC and UID0001XF are now non-reconstructable compiler evidence owned by UID000048, with blank emitters and comment-only no-code formal CPP dispositions.
- UID000048 now owns the complete class CPP/H; UID0001EE owns the complete corrected definitions while its H remains blank; UID0000IX records the complete file route. ScrollPane/ScrollablePane and ControlPane expose the exact support APIs from Section 22. At callback readback, generated EditablePaperPane CPP/H was complete; that receipt is not continuing generated authority.
- Historical method source uses `OnDialogAction(int)`, initializes fields the binary leaves untouched, clips trusted packet lengths, centers text from cached conversion count, adds null/length guards absent from the binary, and calls undeclared placeholder facades. Those statements remain useful history but are not the final recommendation.
- Historical wrapper prose left `0x005128a0` and `0x00512900` uncertain. They are now exact children [UID:000536] and [UID:000537], retained file-static MapPane adapters with complete bodies, blank H, preserved zero-inbound liveness evidence, and exact excluded padding.
- The current report path and validator-owned status/history metadata are authoritative for lifecycle state. The ordinary report body makes no current execute/archive assertion.

## Executive Recommendation

- Preserve the implemented same-UID path at `0x00621af8`; retain UID0002NC and the old 156-byte hash as explicitly corrected historical extraction scope.
- Preserve UID0002NC and UID0001XF as `RECONSTRUCTABLE:FALSE`, direct class owner UID000048, blank emitter, blank H, and comment-only formal CPP no-code markers; the dated callback generated readback contained no target/class/type empty-emitter marker. Gate 2A and later lifecycle actions must establish the latest generated state by fresh physical reread.
- Preserve UID000048's exact class CPP preamble and complete H declaration, UID0001EE's complete Section 22 CPP with blank H, the exact ScrollPane/ScrollablePane and ControlPane support APIs, and UID0000IX's report-level file route.
- Preserve UID0001EF as non-emitting compiler adjustor evidence. Do not hand-author an ordinary destructor unless later independent evidence proves one existed; the implicit derived destructor is sufficient to generate scalar/deleting/adjustor support.
- Preserve exact by-memory children UID000536 and UID000537 for the two retained MapPane adapters. UID000536 emits the direct relative `EditablePaperPane.h` include once before the adjacent definitions; each child H remains blank because its definition is file-static. They are support destinations, not additional report targets.
- Apply the four semantic address-repeatable comments and two pure wrapper renames in Section 21 only through supervisor Gate 2B. No target name/type/table mutation is proposed.

## Supervisor Active Recheck

- The assignment specifically required the three-view island, RTTI predecessors, complete slots, constructor stores, adjustors, resource boundary, ownership/emitter route, declaration/inheritance/interface closure, compiler/source disposition, complete CPP/H or no-code routing, and affected support pages.
- Fresh MCP disproved only the old start boundary and several source interpretations; it confirmed the remainder of the physical three-view layout. Valid prior detail is retained and contradicted assumptions are historicalized.
- Every locator, table cell, function target, constructor store, successor string reference, wrapper byte range, and desired-name collision was checked. No unresolved binary question requires fallback research; assigned adapter UIDs 000536/000537 now replace every pre-assignment template.
- The accepted ordinary by-* destinations were changed and scoped-validated. Coverage, generated output, tracker/audit/lifecycle files, and IDA were not directly edited; generated refreshes are validator-owned side effects recorded below.

## Inference Research Guidance Check

- Direct facts: addresses, bytes, hashes, item boundaries/types/names, comments, xrefs, function ranges, stack frames, constructor writes, RTTI COL/CHD/base descriptors, decompilation, and disassembly.
- Documentation facts: current by-* metadata, formal channels, source tree, accepted base declarations, dated callback generated snapshots, coverage rows, and dated B003 history. Generated authority for a later gate must be reread dynamically.
- Inference supplies human lexical names, access labels, retained-wrapper file-static placement, the descriptive `m_reservedPaperState` spelling, and whether a compiler-expanded operation came from a small inline source helper.
- Runtime equivalence outranks cosmetic source cleanup. Trusted packet lengths, signed tile dimensions, parsed-then-cleared status bytes, exact selection/control state, and range-check lowering are preserved.
- Human source shape outranks analyzer shape. Vptr stores, COLs, vtables, scalar deleting wrappers, adjustor thunks, security cookies, EH state, and range-check helpers are compiler output.
- No raw `sub_*`, `dword_*`, `_DWORD`, offset arithmetic, decompiler aliases, or post-C++03-only convenience constructs remain in the final source recommendation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and alternatives | Best-supported resolution |
| --- | --- | --- |
| Target start | Predecessor UID0002OG ends at `0x621af8`; dword `0x621af8 -> 0x64db30`; COL offset zero and same EditablePaperPane type/CHD as the two later locators. | Correct same UID to `[0x621af8,0x621b98)`; old `0x621afc` start was an extraction error. |
| Direct owner | All three views are emitted by one class declaration; type page is descriptive support, not source owner. | UID000048 is direct owner; UID0001XF and UID0002NC are compiler evidence. |
| Inheritance | RTTI lists EditablePaperPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler; secondary/tertiary PMDs are `+0xa0/+0xa4`. Pane already derives through those facets. | Source is only `class EditablePaperPane : public DialogPane`; do not redundantly inherit EventHandler or TimerHandler. |
| Primary `+0x48` | DialogPane's exact slot is `OnControlCommand(int,int)`; target body compares first argument with zero and ignores the second. | `void OnControlCommand(int controlIndex, int notifyCode)`, not `OnDialogAction(int)`. |
| Primary `+0x5c` | Base has no implementation at this extension slot; constructor calls the target through virtual `+0x5c` after either parser. | New protected virtual `InitializePaperContent(wchar_t *)`. |
| Field tail | Exact reads/writes close `+0x26c..+0x27c`; complete class audit finds no access to `+0x274`; scalar allocation is `0x280`. | Typed fields with natural padding and one four-byte descriptive reserved member at `+0x274`; no byte-array tail. |
| Conversion count | Parsers store a 16-bit conversion result at `+0x270`; centered setup calls `wcslen(text)` and computes `8*length). | Retain stored `short m_textLength` as observed state but do not use it for centering. |
| Packet safety | Binary trusts packet lengths and compiler inserts range-check failures around local arrays. | Preserve exact trusted copy/convert behavior; reject source-added clipping and early-return guards. |
| Destruction | `0x545e00` is scalar deleting support; `0x545ddd/0x545de8` adjust `this` then jump to it. No class-specific cleanup exists. | Implicit derived destructor; no handwritten scalar or adjustor bodies. |
| Wrappers | Two exact 93-byte functions allocate `0x280`, pass mode 0/1, always return true, have no inbound xrefs, and sit among MapPane packet adapters. | Retained file-static `MapPane.cpp` packet adapters, not EditablePaperPane members and not dead padding. |
| LINE001 successor | `0x621b98` is a 24-byte `const wchar_t` item with nine drawing references. | Exact boundary resource literal, not a tertiary slot or address-table continuation. |

Rejected alternatives:

- Keep `[0x621afc,0x621b98)`: rejected because it excludes the primary RTTI locator while claiming a complete vtable island.
- Emit literal vtable arrays/COL pointers: rejected because normal MSVC class declarations and virtual definitions generate them.
- Direct EventHandler/TimerHandler bases or explicit vptr members: rejected by existing Pane inheritance and RTTI PMDs.
- `OnDialogAction(int)`: rejected by the exact inherited two-argument slot and `retn 8) ABI.
- Center from `m_textLength`: rejected by direct `wcslen(text)` in `0x545250`.
- Initialize all tail fields in the constructor: rejected because the binary stores only `m_paperMode` before parser dispatch.
- Clip malformed packet lengths, null-check the editor, or reject failed conversions: rejected as behavioral additions absent from the preserved binary.
- Put wrapper bodies in EditablePaperPane.cpp: rejected by physical MapPane adapter locality and their packet-handler signature.

## Evidence Standards Used

- Certain: exact raw bytes/hashes, item boundaries, constructor data stores, COL/CHD/PMD records, table-cell targets, direct xrefs, and successor item state.
- Very strong: complete function bodies, base declaration slot order, allocation size, adjustor arithmetic, parser/save packet layouts, and resource frame usage.
- Strong: human source names/access, file-static wrapper placement, and descriptive reserved-member spelling, each supported by multiple independent binary/project patterns.
- Negative evidence is bounded and explicit: zero wrapper inbound refs, zero function records in data, no extra table cells, no class use of `+0x274`, no direct redundant interface base, and no separate source-owned vtable data.
- Original PDB/source lexical symbols and exact original private spellings are unavailable. Scores remain below proof-level 95 completion for source documents where those losses matter.

## Evidence Checked

- MCP tools: fresh `idb_list`, `server_health`, `lookup_funcs`, `inspect_items`, `get_bytes`, `find_bytes`, `get_comments`, `xref_query`, `stack_frame`, `decompile`, `disasm`, and bounded entity/type lookups.
- Data: every dword from `0x00621af8` through `0x00621b94`, successor `[0x00621b98,0x00621bb0)`, COLs `0x0064db30/0x0064db90/0x0064dba4`, CHD `0x0064db44`, seven base descriptors, and unique byte signatures at all three views.
- Code: constructor `0x00545170`, action `0x00545220`, setup `0x00545250`, parsers `0x00545660/0x00545770`, save `0x00545880`, border `0x005459b0`, background `0x00545d50`, adjustors `0x00545ddd/0x00545de8`, scalar wrapper `0x00545e00`, adapters `0x005128a0/0x00512900`, and MapPane direct construction sites.
- Support: DialogPane, Pane, GrafPort, ControlPane, TextEditControlPane, TextEditPane, ScrollablePane, TextButtonControlPane, EPFTileContext/resource interfaces, PacketBuffer/Socket, MainUiLayerSlots, target/type/class/file/aggregate/adjustor docs, predecessor Panel vtable target, MapPane class/file/aggregate, manual coverage rows, generated output, tracker, and archived B003 source-quality report.
- Name-collision queries found no existing `HandleEditablePaperPacket` or `HandleReadOnlyPaperPacket` entity.
- B001 performed no IDA mutation/save, coverage edit, generated direct edit, report execution, or lifecycle operation. The accepted ordinary callback used only the serial scoped validators recorded in Section 31; their generated refreshes were validator-owned side effects.

## Claim And Incorporation Ledger

Post-implementation allocation: 52 checked / 6 unchecked. C41-C46 alone remain `proposed` for supervisor-owned Gate 2B; the checklist is the exact eight-field twin after removing `Done`.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0002NC | Correct the same-UID range/path to `[0x00621af8,0x00621b98)`, 160 bytes, SHA256 `333CABA0EA935B111622DCA266CB46993EABE7CC33EF674E29F5CA909C9DE468`. | Certain | Raw bytes, predecessor fence, primary COL. | UID0002NC metadata/title/identity | reject-stale | applied |
| C02 | 0002NC | Preserve the historical 156-byte `[0x00621afc,0x00621b98)` SHA256 `3B9E0C4EEC08188E6877D61073E2735ED36C8E5AE0F54BDEB4CEF9657F23E4EA` as corrected extraction history. | Certain | Independent old-scope hash. | UID0002NC Changes/history | historicalize | applied |
| C03 | 0002NC | Record 40 contiguous four-byte data items with zero gaps or padding inside the corrected island. | Certain | Complete item/byte inventory. | UID0002NC Range/Item Inventory | incorporate | applied |
| C04 | 0002NC | Record primary locator `[0x621af8,0x621afc)` -> `0x64db30`, SHA256 `AEF765BAEC4BC6D8A19960E93A8D8917EF8C23972D6A8DD2299187263595EEDC`. | Certain | Bytes/COL/xref. | UID0002NC Primary View | incorporate | applied |
| C05 | 0002NC | Record primary table `[0x621afc,0x621b5c)`, 24 slots, SHA256 `AB38EDEC91491E7792EA370EE3E56AEC8A26CC26DA2CC25CC58FBD455734150B`. | Certain | Raw hash and 24-cell map. | UID0002NC Primary View | incorporate | applied |
| C06 | 0002NC | Record secondary locator/table hashes, 11 slots, object offset `+0xa0`, and constructor store `0x5451bd`. | Certain | COL, bytes, xrefs, adjustor. | UID0002NC Secondary View | incorporate | applied |
| C07 | 0002NC | Record tertiary locator/table hashes, 2 slots, object offset `+0xa4`, and constructor store `0x5451c7`. | Certain | COL, bytes, xrefs, adjustor. | UID0002NC Tertiary View | incorporate | applied |
| C08 | 0002NC | Preserve the complete 24-slot primary target/name/role inventory. | Certain | Every cell and target queried. | UID0002NC Slot Inventory | incorporate | applied |
| C09 | 0002NC | Preserve the complete 11-slot secondary target/name/role inventory. | Certain | Every cell and target queried. | UID0002NC Slot Inventory | incorporate | applied |
| C10 | 0002NC | Preserve the complete 2-slot tertiary target/name/role inventory. | Certain | Every cell and target queried. | UID0002NC Slot Inventory | incorporate | applied |
| C11 | 0002NC | Record LINE001.EPD `[0x621b98,0x621bb0)`, 24 bytes, SHA256 `360677F05A5B7E5FA705801995CF7DB126D43A42CA18269252F1F5695605B3F2`, as exact successor. | Certain | Item/type/hash/nine refs. | UID0002NC Boundary | incorporate | applied |
| C12 | 0001XF | Record three COLs, CHD attributes 1, seven bases, and PMDs `0/+0xa0/+0xa4`. | Certain | Complete RTTI records. | UID0001XF RTTI/Layout | incorporate | applied |
| C13 | 000048 | Declare only direct `DialogPane` inheritance; EventHandler/TimerHandler remain inherited through Pane. | Certain | RTTI and accepted base H. | UID000048 formal H/inheritance | reject-stale | applied |
| C14 | 000048 | Correct primary `+0x48` to `OnControlCommand(int,int)`; second argument is ignored. | Certain | Base slot and target ABI/body. | UID000048 method map/formal H | reject-stale | applied |
| C15 | 000048 | Declare protected virtual `InitializePaperContent(wchar_t *)` at new primary `+0x5c`. | Very strong | Slot/body/constructor virtual call. | UID000048 method map/formal H | incorporate | applied |
| C16 | 000048 | Preserve exact `0x280` layout and typed tail at `+0x26c..+0x27c` with natural padding. | Very strong | Complete accesses/allocation/RTTI. | UID000048 Layout/formal H | incorporate | applied |
| C17 | 000048 | Represent `+0x274` as descriptive four-byte `m_reservedPaperState`, uninitialized and unreferenced by this class. | Strong | Exhaustive class access audit. | UID000048 Layout/negative evidence | incorporate | applied |
| C18 | 0001EE | Preserve constructor base `DialogPane(L"",7,true)`, initialize only mode, and dispatch mode 0/1 parsers. | Very strong | Exact constructor body. | UID0001EE formal CPP/behavior | reject-stale | applied |
| C19 | 0001EE | Preserve editable packet bytes `1/2/3/4`, BE length at `5`, text at `7`, signed tile dimensions, and parsed-then-cleared status. | Certain | Parser body. | UID0001EE parser/formal CPP | incorporate | applied |
| C20 | 0001EE | Preserve read-only packet bytes `1/2/3/4`, BE length at `5`, text at `7`, centered byte, and parsed-then-cleared status. | Certain | Parser body. | UID0001EE parser/formal CPP | incorporate | applied |
| C21 | 0001EE | Preserve exact trusted-copy/CP_ACP conversion behavior without source-added clipping or early returns. | Very strong | Parser assembly/range lowering. | UID0001EE parser/history/formal CPP | reject-stale | applied |
| C22 | 0001EE | Preserve setup geometry, signed tile arithmetic, localized ids 95/96, control limits, focus/pending state, overlay create/show, and slide-open order. | Very strong | Complete setup decompile. | UID0001EE setup/formal CPP | incorporate | applied |
| C23 | 0001EE | Center read-only text from `wcslen(text)`, not cached `m_textLength`. | Certain | Direct setup call/math. | UID0001EE setup/history | reject-stale | applied |
| C24 | 0001EE | Preserve save opcode `0x23`, paper id, BE byte length, CR-to-tab normalization, exact conversion length, and send length `+4`. | Certain | Save body/callees. | UID0001EE save/formal CPP | incorporate | applied |
| C25 | 0001EE | Remove unsupported editor-null, conversion-failure, and packet-length early-return guards while preserving compiler range-failure semantics. | Very strong | Complete binary control flow. | UID0001EE formal CPP/history | reject-invalid | applied |
| C26 | 0001EE | Preserve LINE001 frames lookup order `0,1,2,7,3,6,5,4`, 16-pixel four-edge do-loops, corners, and frame 8 inset fill. | Certain | Draw bodies and nine literal refs. | UID0001EE draw/formal CPP | incorporate | applied |
| C27 | 000048 | Use an implicit derived destructor; scalar deleting wrapper and two adjustors remain compiler output. | Certain | No class cleanup; exact wrappers. | UID000048 H/destructor disposition | reject-stale | applied |
| C28 | 0002NC | Make target compiler-generated/non-reconstructable, owner UID000048, blank emitter/H, comment-only formal CPP no-code marker. | Certain | Class declaration is source cause. | UID0002NC metadata/formal CPP | incorporate | applied |
| C29 | 0001XF | Make vtable type compiler-generated/non-reconstructable, owner UID000048, blank emitter/H, comment-only formal CPP no-code marker. | Certain | Same class-generated storage. | UID0001XF metadata/formal CPP | incorporate | applied |
| C30 | 000048 | Emit CPP preamble include plus CHILDREN and complete class H from Section 22. | Very strong | Closed source surface/layout. | UID000048 formal CPP/H | incorporate | applied |
| C31 | 0001EE | Replace stale aggregate formal CPP with the complete corrected source in Section 22. | Very strong | Complete live method audit. | UID0001EE formal CPP | incorporate | applied |
| C32 | 0000IX | Preserve `NexusTK/ui/dialogs/EditablePaperPane.cpp/.h` and add full report-level source, dependency, generated, and history detail. | Strong | Dedicated class/resources/tree. | UID0000IX file page | incorporate | applied |
| C33 | 000263 | Correct parent aggregate target range, class-source closure, and compiler/source split without emitting duplicate code. | Certain | Parent inventory and corrected child. | UID000263 parent aggregate | incorporate | applied |
| C34 | 0001EF | Preserve exact adjustor thunks `this-0xa0`/`this-0xa4` as non-emitting compiler support. | Certain | Exact 11-byte bodies/xrefs. | UID0001EF support page | already-present | already-present |
| C35 | 0002OG | Preserve PanelPane predecessor end `0x621af8` and explicit EditablePaperPane locator exclusion. | Certain | Existing exact boundary plus bytes. | UID0002OG boundary cross-reference | already-present | already-present |
| C36 | 0001AW | Resolve `[0x5128a0,0x5128fd)` as [UID:000536] file-static editable packet adapter with one direct `../ui/dialogs/EditablePaperPane.h` include declaration-covering both siblings, exact hash `7ACA6F2E453503F0EAB9296F0169A9D354AED76D606891BAB5706A8F4CA66EEF`. | Strong | Exact body/locality/mode/zero refs. | UID000536 exact child; UID0001AW aggregate | incorporate | applied |
| C37 | 0001AW | Resolve `[0x512900,0x51295d)` as [UID:000537] file-static read-only packet adapter declaration-covered by UID000536's direct include, exact hash `D11423704E51BF3D23A0C60E786B96050BA3C818EC76BE4BED7360264377D4A1`. | Strong | Exact body/locality/mode/zero refs. | UID000537 exact child; UID0001AW aggregate | incorporate | applied |
| C38 | 0000L3 | Add both retained adapters to MapPane.cpp source/file inventory without claiming active inbound routes; preserve documentation/address order while recording the dated callback generated emitter topology as a non-authoritative receipt. | Strong | Neighbor adapter precedent/locality. | UID0000L3 MapPane file | incorporate | applied |
| C39 | 0002NC | Reject `0x0045004e` as a vtable slot; retain it as UTF-16 interior-byte pollution and LodePNG code address coincidence. | Certain | Successor type/bytes and LodePNG boundary. | UID0002NC historical correction | reject-invalid | applied |
| C40 | 0001EE | Historicalize stale `OnDialogAction`, field-zeroing, clipped packet, cached-length centering, and placeholder-helper source. | Certain | Live ABI/body contradictions. | UID0001EE/UID000048/UID0000IX history | historicalize | applied |
| C41 | 0002NC | Stage I01 Classification apply through schema-complete `set_address_comments` for the primary-locator regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/xrefs. | Supervisor Gate 2B I01 | incorporate | proposed |
| C42 | 0002NC | Stage I02 Classification apply through schema-complete `set_address_comments` for the secondary-facet regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/xrefs. | Supervisor Gate 2B I02 | incorporate | proposed |
| C43 | 0002NC | Stage I03 Classification apply through schema-complete `set_address_comments` for the tertiary-facet regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/xrefs. | Supervisor Gate 2B I03 | incorporate | proposed |
| C44 | 0002NC | Stage I04 Classification apply through schema-complete `set_address_comments` for the LINE001-boundary regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/nine refs. | Supervisor Gate 2B I04 | incorporate | proposed |
| C45 | 0001AW | Stage I05 Classification apply through schema-complete pure `rename` to `HandleEditablePaperPacket`, with exact frame/type/comment/byte/xref protection and fail-closed readback. | Strong | Complete wrapper prestate/noncollision. | Supervisor Gate 2B I05 | incorporate | proposed |
| C46 | 0001AW | Stage I06 Classification apply through schema-complete pure `rename` to `HandleReadOnlyPaperPacket`, with exact frame/type/comment/byte/xref protection and fail-closed readback. | Strong | Complete wrapper prestate/noncollision. | Supervisor Gate 2B I06 | incorporate | proposed |
| C47 | 0002NC | Raise target `88/92 -> 94/96` after corrected range, complete inventory, no-code route, and source closure. | Very strong | All target blockers resolved. | UID0002NC metadata/score | incorporate | applied |
| C48 | 0001XF | Raise vtable type `86/90 -> 94/96` after complete RTTI/layout and compiler disposition. | Very strong | Complete three-view proof. | UID0001XF metadata/score | incorporate | applied |
| C49 | 000048 | Raise class `87/88 -> 94/94` with complete H/source route and lexical caps. | Strong | Complete class/layout/behavior. | UID000048 metadata/score | incorporate | applied |
| C50 | 0000IX | Raise file `87/88 -> 94/93` with closed contents and wrapper boundary. | Strong | Complete file inventory/source placement. | UID0000IX metadata/score | incorporate | applied |
| C51 | 0001EE | Raise method aggregate `87/88 -> 94/93` with complete corrected source. | Strong | All bodies and dependencies resolved. | UID0001EE metadata/score | incorporate | applied |
| C52 | 0001EF | Raise adjustor support `85/90 -> 92/96` while remaining non-emitting. | Very strong | Exact bytes/arithmetic/source cause. | UID0001EF metadata/score | incorporate | applied |
| C53 | 0002NC | Supply the complete current-versus-proposed manual coverage audit for UID000263, UID0001AW, UID0000L3, UID00007Q, UID0000CM, UID00042X, UID0000CF, UID0001GL, UID0000NF, UID000038, and UID0000IG, plus target/type/class/file/method/adjustor rows; supply exact assigned adapter rows UID000536/UID000537 and dependent aggregate/file replacements, with no pre-assignment token remaining. | Certain | Current manual rows physically read; absent UID00042X row checked exactly. | Section 28; exact coverage roots/positions | incorporate | applied |
| C54 | 0002NC | Scoped-validate every changed ordinary page serially, then physically reread generated EditablePaperPane, MapPane, ScrollBar, ControlPane, and GrafPort CPP/H for complete definitions/declarations, no target/class/type marker, no duplicate adapter, and declared identifiers. | Certain | Validator/emitter workflow. | Validator/generated callback plan | incorporate | applied |
| C55 | 0002NC | Preserve generated commands 24635, 24719, 24721, and 24722 and their hashes only as dated callback receipts; later generated authority requires a dynamic physical reread. | Certain | Physical generated readback. | UID0000IX/report receipts | historicalize | applied |
| C56 | 0000CF | Apply the exact Section 22 formal support chain: UID0000CM H gains inline `SetScrollStyle(unsigned char)` after `SetSkinIndex`; UID00042X documents that inline source cause; UID0000CF H gains `void SetScrollbarsVisible(bool visible);` after `SetSkinIndex`; and UID0001GL CPP replaces only the `[0x0055e840,0x0055e897)` no-code row with the complete two-child body immediately after `SetSkinIndex`, with no new include. | Very strong | Exact `0x55e840` compare/write/invalidate lowering, UID00042X raw clone, and sole target caller. | Section 22 formal UID0000CM H / UID0000CF H / UID0001GL CPP blocks; UID00042X disposition | incorporate | applied |
| C57 | 000038 | Apply the exact Section 22 UID000038 formal H insertion `void SetSelectable(bool selectable) { m_controlFlags = selectable ? 1 : 0; }` immediately after `IsSelectable()`; keep ControlPane CPP blank for this API because it is inline, add no include/storage/slot, and preserve UID0000IG ownership. | Strong | Direct child byte write, protected layout, and inline lowering. | Section 22 formal UID000038 H block; UID0000IG header route | incorporate | applied |
| C58 | 0002NC | Report has 33 exact headings, 58/58 ledger/checklist parity, only formal C++ fences, lifecycle-neutral post-implementation prose, and exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker. | Certain | Mechanical report audit. | Report structure | already-present | already-present |

## Positive Evidence Summary

- The corrected 160-byte island has a unique whole-island hash and unique local byte signatures for all three views.
- Constructor stores land exactly on the three table heads at object offsets `0`, `0xa0`, and `0xa4`; locator PMDs independently match those offsets.
- The full primary/secondary/tertiary table shapes match DialogPane/Pane inheritance and the two adjustor constants exactly.
- `LINE001.EPD` is both the successor data boundary and the sole paper-frame resource consumed by DrawBorder/DrawBackground.
- The complete class code closes packet parsing, setup, save, rendering, layout, interfaces, wrapper placement, and compiler/source separation.
- The source recommendation regenerates the vtable island through ordinary C++ virtual declarations and definitions, eliminating the empty emitter without inventing raw ABI data.

## IDA MCP Facts

Corrected subrange identities:

| Range | Bytes / items | SHA256 | Meaning |
| --- | --- | --- | --- |
| `0x621af8-0x621afc` | 4 / 1 dword | `AEF765BAEC4BC6D8A19960E93A8D8917EF8C23972D6A8DD2299187263595EEDC` | Primary COL pointer `0x64db30`. |
| `0x621afc-0x621b5c` | 96 / 24 dwords | `AB38EDEC91491E7792EA370EE3E56AEC8A26CC26DA2CC25CC58FBD455734150B` | Primary table. |
| `0x621b5c-0x621b60` | 4 / 1 dword | `387BE1D3E56EC83CAD2314167D2DB5720E31AE95D088092801B1693E0FCC6987` | Secondary COL pointer `0x64db90`. |
| `0x621b60-0x621b8c` | 44 / 11 dwords | `2F88477641D49F006E4290F2A23D88860287716E28E989299DF2B1889BC3651E` | EventHandler facet. |
| `0x621b8c-0x621b90` | 4 / 1 dword | `3727895F9B862132DCA8520382B14A2D137C93CAEF3C6E81DFF7EE6EBB5041A9` | Tertiary COL pointer `0x64dba4`. |
| `0x621b90-0x621b98` | 8 / 2 dwords | `CC945B208F8E596075076F41FE2AD6EB2D9A68F5A91434048B0AEE9649AE2F2D` | TimerHandler facet. |
| `0x621b98-0x621bb0` | 24 / 1 wchar item | `360677F05A5B7E5FA705801995CF7DB126D43A42CA18269252F1F5695605B3F2` | `LINE001.EPD` successor. |

- Item state: every island cell is four-byte data with blank type. Only table heads are named: `??_7EditablePaperPane@@6B@` at `0x621afc`, suffix `_0` at `0x621b60`, and suffix `_1` at `0x621b90`. Locator cells are unnamed. All four comment channels are blank at every island head.
- `0x621b98` is named `aLine001Epd`, type `const wchar_t`, 24 bytes. Its address regular/repeatable comments are blank; function regular/repeatable channels are independently not applicable.
- None of `0x621af8`, `0x621afc`, `0x621b5c`, `0x621b60`, `0x621b8c`, `0x621b90`, or `0x621b98` is a function.
- COLs share type descriptor `0x6786a8` and CHD `0x64db44`; offsets are `0`, `0xa0`, `0xa4`. CHD attributes are 1 with seven bases: EditablePaperPane, DialogPane, Pane, GrafPort, LObject, EventHandler at `mdisp 0xa0`, TimerHandler at `mdisp 0xa4`.
- Constructor `[0x545170,0x545217)` calls `DialogPane(L"",7,1)`, writes mode at `+0x278`, stores table heads at `0x5451b7/0x5451bd/0x5451c7`, then dispatches mode 0 to `0x545660` and mode 1 to `0x545770`.
- `0x545ddd` and `0x545de8` are 11-byte adjustors subtracting `0xa0` and `0xa4` before the scalar deleting wrapper at `0x545e00`.
- The IDA session remained read-only. No proposed action in this report was executed.

## Function / Child Inventory

Complete table inventory:

| View/cell | Target | Current function / source role |
| --- | --- | --- |
| primary locator `0x621af8` | `0x64db30` | Complete-object COL, offset 0. |
| primary `+0x00` `0x621afc` | `0x545e00` | Scalar deleting destructor, compiler output. |
| primary `+0x04` | `0x4f4b10` | `LObject::GetRuntimeClass`. |
| primary `+0x08` | `0x41b6c0` | `LObject::OnChangeMessage`. |
| primary `+0x0c` | `0x4b8e20` | `Pane::UpdateRenderRegion`. |
| primary `+0x10` | `0x41d680` | `Pane::DrawOnTarget`. |
| primary `+0x14` | `0x544730` | `Pane::Show`. |
| primary `+0x18` | `0x544750` | `Pane::Hide`. |
| primary `+0x1c` | `0x5447a0` | `Pane::GetParentPane`. |
| primary `+0x20` | `0x544800` | `Pane::InvalidateRect`. |
| primary `+0x24` | `0x544a20` | `Pane::GetDescription`. |
| primary `+0x28` | `0x544b80` | `Pane::GetScreenBounds`. |
| primary `+0x2c` | `0x544bd0` | `Pane::SetBounds`. |
| primary `+0x30` | `0x49dfd0` | `DialogPane::OnCreate`. |
| primary `+0x34` | `0x544cb0` | `Pane::InsertInLayer`. |
| primary `+0x38` | `0x49e1c0` | `DialogPane::OnDestroy`. |
| primary `+0x3c` | `0x49e190` | `DialogPane::OnShow`. |
| primary `+0x40` | `0x49e210` | `DialogPane::OnHide`. |
| primary `+0x44` | `0x49f090` | `DialogPane::OnPaint`. |
| primary `+0x48` | `0x545220` | `EditablePaperPane::OnControlCommand(int,int)`. |
| primary `+0x4c` | `0x41b6a0` | Inherited empty `DialogPane::UpdateActionButton`. |
| primary `+0x50` | `0x545d50` | `EditablePaperPane::DrawBackground`. |
| primary `+0x54` | `0x5459b0` | `EditablePaperPane::DrawBorder`. |
| primary `+0x58` | `0x49fc00` | `DialogPane::SetHoverControl`. |
| primary `+0x5c` | `0x545250` | `EditablePaperPane::InitializePaperContent`. |
| secondary locator `0x621b5c` | `0x64db90` | EventHandler-facet COL, offset `0xa0`. |
| secondary `+0x00` `0x621b60` | `0x545ddd` | Deleting-destructor adjustor, `this-0xa0`. |
| secondary `+0x04` | `0x49e240` | `DialogPane::HandlePointerOrMouseEvent`. |
| secondary `+0x08` | `0x49e6e0` | `DialogPane::HandleKeyOrTextEvent`. |
| secondary `+0x0c` | `0x49ea60` | `DialogPane::HandleImeEvent`. |
| secondary `+0x10` | `0x41d6b0` | Inherited false `Pane::HandlePacketEvent`. |
| secondary `+0x14` | `0x544df0` | `Pane::HandleSystemOrControlEvent`. |
| secondary `+0x18` | `0x544e00` | `Pane::HandleType19Event`. |
| secondary `+0x1c` | `0x4a89f0` | `EventHandler::ForwardHandlerOrder`. |
| secondary `+0x20` | `0x544e10` | `Pane::GetLocalOffset`. |
| secondary `+0x24` | `0x544e30` | `Pane::GetScreenOffset`. |
| secondary `+0x28` | `0x544e70` | `Pane::ShouldAcceptEvent`. |
| tertiary locator `0x621b8c` | `0x64dba4` | TimerHandler-facet COL, offset `0xa4`. |
| tertiary `+0x00` `0x621b90` | `0x545de8` | Deleting-destructor adjustor, `this-0xa4`. |
| tertiary `+0x04` `0x621b94` | `0x544e90` | Inherited `Pane::OnTimer`. |
| successor `0x621b98` | `LINE001.EPD` | Resource data, not a slot. |

Authored/retained source inventory:

| Range | Size | Source disposition |
| --- | --- | --- |
| `0x545170-0x545217` | `0xa7` | EditablePaperPane constructor. |
| `0x545220-0x54524b` | `0x2b` | OnControlCommand. |
| `0x545250-0x54565b` | `0x40b` | InitializePaperContent. |
| `0x545660-0x545767` | `0x107` | ParseEditablePacket. |
| `0x545770-0x545877` | `0x107` | ParseReadOnlyPacket. |
| `0x545880-0x5459a7` | `0x127` | SavePaperContent. |
| `0x5459b0-0x545d46` | `0x396` | DrawBorder. |
| `0x545d50-0x545dc1` | `0x71` | DrawBackground. |
| `0x545ddd-0x545df3` | 22 | Two compiler adjustors, no source body. |
| `0x545e00-0x545e3b` | `0x3b` | Compiler scalar deleting wrapper, implicit destructor cause. |
| `0x5128a0-0x5128fd` | `0x5d` | Retained file-static editable MapPane adapter. |
| `0x512900-0x51295d` | `0x5d` | Retained file-static read-only MapPane adapter. |

No additional source-owned global, static storage, raw vtable array, import, resource object, or standalone literal definition belongs to EditablePaperPane.cpp. `LINE001.EPD` remains a pooled literal/resource dependency.

## Direct Xref / Caller Inventory

- Locator cells have one outbound data edge each to their COL and no inbound reference except the table-head constructor stores described below; ordinary table cells have one outbound data edge to their function.
- Primary head `0x621afc`: inbound constructor store at `0x5451b7`; outbound data edge to `0x545e00`.
- Secondary head `0x621b60`: inbound constructor store at `0x5451bd`; outbound data edge to `0x545ddd`.
- Tertiary head `0x621b90`: inbound constructor store at `0x5451c7`; outbound data edge to `0x545de8`.
- No table cell has a code xref. The physical slot-to-target edges are data xrefs; source liveness comes from constructor-installed dynamic dispatch.
- `LINE001.EPD` has exactly nine inbound data refs: `0x545a2d, 0x545a3f, 0x545a54, 0x545a69, 0x545a7e, 0x545a93, 0x545aa8, 0x545abd` in DrawBorder and `0x545d7a` in DrawBackground.
- Constructor `0x545170` has four direct callsites: active MapPane packet dispatch at `0x508338` and `0x50836b`, plus retained adapters at `0x5128e5` and `0x512945`.
- Adapter `0x5128a0`: zero inbound xrefs; exactly two direct callees, operator new and `0x545170`; allocation `0x280`, mode 0, unconditional true result.
- Adapter `0x512900`: zero inbound xrefs; exactly two direct callees, operator new and `0x545170`; allocation `0x280`, mode 1, unconditional true result.
- Neighbor `HandlePursuitMessageDialogPacket` at `0x512840` has the same retained bool-stdcall packet-adapter source shape, corroborating MapPane.cpp placement without inventing an inbound route.

## Documentation Evidence And IDA Status

- UID0002NC, UID0001XF, UID000048, UID0000IX, UID0001EE, UID0001EF, UID000263, UID0002OG, UID0001AW, UID0000L3, UID000536, UID000537, and all ScrollBar/ControlPane support destinations were read at their complete material metadata/formal/evidence anchors after implementation.
- Current accepted base declarations establish DialogPane's primary virtual order through `OnControlCommand`, `UpdateActionButton`, `DrawBackground`, `DrawBorder`, and `SetHoverControl`; Pane supplies EventHandler and TimerHandler facets.
- Current TextEditControlPane/TextEditPane support establishes the 11-argument constructor, max length/line setters, edit-active state, text insertion, selection, and text read. ScrollablePane `0x55e840` supplies the exact scrollbar visibility behavior.
- Archived B003 research remains valuable for packet/resource/module identification. Fresh MCP supersedes its start range, action signature, centering source, constructor initialization, packet guards, and wrapper uncertainty.
- Historical pre-callback generated output emitted stale UID0001EE source, UID000048/UID0001XF/UID0002NC markers, and no H. At callback readback, validator-owned generated output contained one complete EditablePaperPane declaration, eight exact definitions, no target/class/type empty marker, and complete support/API routes; Section 31 records the dated identities and counts. The latest generated authority must be established dynamically by physical reread at Gate 2A or any later lifecycle action.
- IDA remains unchanged. Existing decorated table names are retained; comments and wrapper renames are recommendations only.

## Ranked Ownership Analysis

| Rank | Candidate | Resolution |
| --- | --- | --- |
| 1 | [UID:000048] EditablePaperPane | Direct class owner. One declaration generates all three views and owns every target-specific virtual. |
| 2 | [UID:0001XF] EditablePaperPaneVtables | Required semantic/layout support, but not source owner or emitter. |
| 3 | [UID:0000IX] EditablePaperPane file | Compilation-unit route for class declaration/method definitions; not direct owner of compiler data metadata. |
| 4 | [UID:0001EE] method aggregate | Source-body emitter for authored methods; not owner of vtable storage. |
| 5 | DialogPane/Pane | Base declarations explain inherited slots and facets; dependency owners only. |
| 6 | MapPane | Active constructor caller and owner of retained packet adapters; not owner of class/vtable island. |
| Rejected | No owner / raw data / resource owner | Contradicted by decorated RTTI, constructor stores, virtual bodies, and complete class declaration. |

Implemented canonical route: UID0002NC -> class UID000048 -> file UID0000IX. UID0001XF remains a class-owned type support page with no emitter. This mirrors established compiler-vtable treatment and removes the circular blank-emitter route through the type page.

## Source Placement

- Class source: `NexusTK/ui/dialogs/EditablePaperPane.cpp`.
- Class declaration: `NexusTK/ui/dialogs/EditablePaperPane.h`.
- Class CPP order: include/preamble through UID000048, then UID0001EE authored definitions in address/source dependency order.
- Compiler data: no source file body. Vtable/COL/RTTI and adjustors/scalar wrapper arise from the H declaration, virtual definitions, and implicit destructor.
- Retained packet adapters: `NexusTK/map/MapPane.cpp`, as file-static definitions on exact children UID000536/UID000537 near the existing packet-adapter family. UID000536 emits `#include "../ui/dialogs/EditablePaperPane.h"` once before both bodies so every used class/enum identifier is declared; class ownership does not move.
- `LINE001.EPD`: pooled resource literal consumed from EditablePaperPane.cpp; no standalone writable data definition.
- Text edit, scrolling, language, packet, socket, EPF, geometry, BackPane, and MainUiLayerSlots remain dependency owners in their established modules.

## Range / Split / Padding / Reclassification Analysis

- Required rename: old `0x00621afc-0x00621b98` path -> corrected `0x00621af8-0x00621b98` path, same UID.
- The four-byte prefix `0x621af8-0x621afc` must be absorbed into UID0002NC. It cannot remain orphaned and does not belong to predecessor UID0002OG.
- Internal composition is exact: locator, 24 cells, locator, 11 cells, locator, 2 cells. There is no alignment or padding inside the 160-byte target.
- The exclusive end remains `0x621b98`. The 24-byte wchar item through `0x621bb0` is not absorbed.
- Current old-scope body hash is preserved in history; corrected full-scope hash becomes authoritative for the renamed target.
- UID0001XF and UID0002NC change classification from reconstructable empty emitters to non-reconstructable compiler evidence. This is not loss of reconstructability: source responsibility moves to the complete class H and method CPP.
- Exact adapter child ranges exclude their three-byte `0xcc` successors. Each padding span has SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE` and remains parent/aggregate alignment evidence, not source.

## Negative Evidence Summary

- No fourth EditablePaperPane view or slot exists after `0x621b94`.
- No internal target padding, undefined byte, overlapping item, function item, typed dword, or comment exists in the corrected island.
- No direct source-owned vtable/COL/RTTI array is justified.
- No class-specific ordinary destructor cleanup exists.
- No direct EventHandler or TimerHandler base declaration is justified.
- No source read of `m_reservedPaperState +0x274` exists in the complete class island.
- No setup use of stored `m_textLength +0x270` exists; centered width uses `wcslen`.
- No packet clipping, editor-null branch, conversion-failure branch, or defensive send-length return exists.
- No inbound xref or pointer route to either retained adapter was found; that fact is preserved and not converted into an active-dispatch claim.
- No duplicate report, additional-target declaration, IDA change, generated direct edit, coverage edit, or lifecycle action occurred. Ordinary edits and scoped validator activity are exactly enumerated in Sections 31-32.

## IDA Rename / Type / Comment Recommendations

Channel abbreviations: AR = address regular, AP = address repeatable, FR = function regular, FP = function repeatable. These are supervisor-only proposed actions with `Classification: apply`. Their deterministic execution order is exactly I01, I02, I03, I04, I05, I06. Before each request, reread that stage's complete literal prestate and every earlier stage's poststate; do not issue a later request after any mismatch.

Fresh read-only runtime-attestation snapshot for this Gate 1 repair: attested `ok:true` at `2026-08-16T10:11:36.066725+00:00`, database `supervisor_uid0000md_persistverify_20260816`, canonical path `e:\ntk\resources\nexustk\nexustk.exe.i64`. This exact session binding is dated evidence, not permanent authority. Immediately before Gate 2B, the supervisor must freshly enumerate and attest runtime state; a rotated or mismatched session requires a new schema-complete binding before mutation.

**I01 - primary locator semantic comment**

- Classification: apply.
- Evidence / confidence: certain; fresh runtime-attested `inspect_items`, `get_comments`, `get_bytes`, and `xref_query` independently matched the exact item, channels, bytes, and sole outbound data edge.
- Schema-complete request: `set_address_comments` with `{"database":"supervisor_uid0000md_persistverify_20260816","items":{"addr":"0x00621af8","comment":"EditablePaperPane vtable/RTTI island begins here: primary DialogPane view, inherited EventHandler facet at +0xa0, and inherited TimerHandler facet at +0xa4; exact range [0x00621af8,0x00621b98)."}}`.
- Literal prestate: exact data item `[0x00621af8,0x00621afc)`; size `0x4` / 4; name absent; type absent; data true; code false; bytes `30 db 64 00`; SHA256 `AEF765BAEC4BC6D8A19960E93A8D8917EF8C23972D6A8DD2299187263595EEDC`; AR absent; AP absent; FR independently not applicable; FP independently not applicable; zero inbound xrefs; one outbound data xref `0x00621af8 -> 0x0064db30`; zero code xrefs.
- Protected fields / expected poststate: preserve exact item `[0x00621af8,0x00621afc)`, size, name absent, type absent, data/code classification, bytes/hash, all boundaries and xrefs; AR becomes exactly the request text; AP remains absent; FR remains independently not applicable; FP remains independently not applicable. No other island item or channel may change.
- Immediate readback: require one mutation result for `0x00621af8` with no error, then reread the item, all four comment channels, bytes/hash, and both-direction xrefs before I02.
- Hard stop: if any literal prestate, occupied AR destination, mutation response, or immediate poststate differs, perform no further mutation and do not save the IDB.

**I02 - secondary facet semantic comment**

- Classification: apply.
- Evidence / confidence: certain; fresh runtime-attested item/comment/byte/xref reads matched the decorated head, exact four-byte item, absent type, and constructor/adjustor data edges.
- Schema-complete request: `set_address_comments` with `{"database":"supervisor_uid0000md_persistverify_20260816","items":{"addr":"0x00621b60","comment":"EditablePaperPane EventHandler facet at complete-object +0xa0: 11 slots [0x00621b60,0x00621b8c); slot 0 is the this-0xa0 deleting-destructor adjustor."}}`.
- Literal prestate: exact data item `[0x00621b60,0x00621b64)`; size `0x4` / 4; exact current name `??_7EditablePaperPane@@6B@_0`; type absent; data true; code false; bytes `dd 5d 54 00`; SHA256 `C637078810587D4E9A4C68B09A80D46C9B306693C20EA98CBC36FA1434C5ACE8`; AR absent; AP absent; FR independently not applicable; FP independently not applicable; inbound data xref `0x005451bd -> 0x00621b60`; outbound data xref `0x00621b60 -> 0x00545ddd`; zero code xrefs.
- Protected fields / expected poststate: preserve exact item `[0x00621b60,0x00621b64)`, size, exact name, type absent, data/code classification, bytes/hash, all boundaries and xrefs; AR becomes exactly the request text; AP remains absent; FR remains independently not applicable; FP remains independently not applicable. All other 39 island dwords and successor data remain unchanged.
- Immediate readback: require one mutation result for `0x00621b60` with no error, then reread the item, all four comment channels, bytes/hash, both-direction xrefs, and the still-exact I01 poststate before I03.
- Hard stop: if any literal prestate, occupied AR destination, earlier-stage poststate, mutation response, or immediate poststate differs, perform no further mutation and do not save the IDB.

**I03 - tertiary facet semantic comment**

- Classification: apply.
- Evidence / confidence: certain; fresh runtime-attested item/comment/byte/xref reads matched the decorated head, exact four-byte item, absent type, and constructor/adjustor data edges.
- Schema-complete request: `set_address_comments` with `{"database":"supervisor_uid0000md_persistverify_20260816","items":{"addr":"0x00621b90","comment":"EditablePaperPane TimerHandler facet at complete-object +0xa4: 2 slots [0x00621b90,0x00621b98); slot 0 is the this-0xa4 deleting-destructor adjustor and slot 1 is inherited Pane::OnTimer."}}`.
- Literal prestate: exact data item `[0x00621b90,0x00621b94)`; size `0x4` / 4; exact current name `??_7EditablePaperPane@@6B@_1`; type absent; data true; code false; bytes `e8 5d 54 00`; SHA256 `A8EA1003DE740710D094F6450C75A9D5EE93A03412FF0597E3FC1A9B6B12690E`; AR absent; AP absent; FR independently not applicable; FP independently not applicable; inbound data xref `0x005451c7 -> 0x00621b90`; outbound data xref `0x00621b90 -> 0x00545de8`; zero code xrefs.
- Protected fields / expected poststate: preserve exact item `[0x00621b90,0x00621b94)`, size, exact name, type absent, data/code classification, bytes/hash, all boundaries and xrefs; AR becomes exactly the request text; AP remains absent; FR remains independently not applicable; FP remains independently not applicable. No table extension or other island change is permitted.
- Immediate readback: require one mutation result for `0x00621b90` with no error, then reread the item, all four comment channels, bytes/hash, both-direction xrefs, and the still-exact I01-I02 poststates before I04.
- Hard stop: if any literal prestate, occupied AR destination, earlier-stage poststate, mutation response, or immediate poststate differs, perform no further mutation and do not save the IDB.

**I04 - successor boundary semantic comment**

- Classification: apply.
- Evidence / confidence: certain; fresh runtime-attested item/comment/byte/xref reads matched every literal item field and all nine inbound drawing references.
- Schema-complete request: `set_address_comments` with `{"database":"supervisor_uid0000md_persistverify_20260816","items":{"addr":"0x00621b98","comment":"Boundary: UTF-16 LINE001.EPD starts here; it is resource data referenced by EditablePaperPane drawing code, not a fourth vtable item."}}`.
- Literal prestate: exact data item `[0x00621b98,0x00621bb0)`; head `0x00621b98`; end `0x00621bb0`; size `0x18` / 24; exact current name `aLine001Epd`; exact current type `const wchar_t`; data true; code false; not a function; bytes `4c 00 49 00 4e 00 45 00 30 00 30 00 31 00 2e 00 45 00 50 00 44 00 00 00`; SHA256 `360677F05A5B7E5FA705801995CF7DB126D43A42CA18269252F1F5695605B3F2`; AR absent; AP absent; FR independently not applicable; FP independently not applicable; nine inbound data xrefs `0x00545a2d, 0x00545a3f, 0x00545a54, 0x00545a69, 0x00545a7e, 0x00545a93, 0x00545aa8, 0x00545abd, 0x00545d7a`; zero outbound xrefs; zero code xrefs.
- Protected fields / expected poststate: preserve exact item `[0x00621b98,0x00621bb0)`, head/end, size, exact name/type, data/code/function classification, bytes/hash, all nine inbound xrefs, zero outbound/code xrefs, and the preceding eight-byte tertiary table; AR becomes exactly the request text; AP remains absent; FR remains independently not applicable; FP remains independently not applicable.
- Immediate readback: require one mutation result for `0x00621b98` with no error, then reread every literal item field above, all four comment channels, bytes/hash, all xrefs, and the still-exact I01-I03 poststates before I05.
- Hard stop: if any literal prestate, occupied AR destination, earlier-stage poststate, mutation response, or immediate poststate differs, perform no further mutation and do not save the IDB.

**I05 - editable adapter pure rename**

- Classification: apply.
- Evidence / confidence: strong; fresh runtime-attested function lookup, desired-name noncollision lookup, comments, frame, bytes, profile, and xrefs matched the protected function state. The semantic name remains inferred because no inbound route or original private symbol survives.
- Schema-complete request: `rename` with `{"database":"supervisor_uid0000md_persistverify_20260816","batch":{"func":{"addr":"0x005128a0","name":"HandleEditablePaperPacket"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: exact function `[0x005128a0,0x005128fd)`; size `0x5d` / 93; exact current name `___std_parallel_algorithms_hw_threads@0_1`; prototype `char __stdcall(int a1)`; body bytes `558bec6aff683d2d600064a1000000005051a1242f670033c5508d45f464a3000000006880020000e8d321feff83c4048945f0c745fc0000000085c0740c6a00ff75088bc8e886280300b0018b4df464890d00000000598be55dc20400`; SHA256 `7ACA6F2E453503F0EAB9296F0169A9D354AED76D606891BAB5706A8F4CA66EEF`; AR absent; AP absent; FR absent; FP absent; zero external inbound xrefs; no data xref; desired name `HandleEditablePaperPacket` absent/noncolliding.
- Complete seven-row frame prestate: `Block@0x4/0x4/void *`; `var_C@0x8/0x4/_DWORD`; `var_4@0x10/0x4/_DWORD`; `__saved_registers@0x14/0x4/_DWORD`; `__return_address@0x18/0x4/_UNKNOWN *`; `arg_0@0x1c/0x4/_DWORD`; `arg_4@0x20/0x4/_DWORD`; zero additional rows.
- Protected calls and lowering: preserve source-semantic calls to `NexusTK_operator_new` at `0x004f4aa0` and constructor `0x00545170`, plus existing compiler/EH/security references to the function entry, `0x004f4ac0`, `0x005c772f`, and `0x005c956c`; no call/reference/body change is permitted.
- Protected fields / expected poststate: only the function name changes to exactly `HandleEditablePaperPacket`; preserve prototype, all seven frame rows and zero-row count, all comment channels absent, range/size/body bytes/hash, xrefs, calls/references, and function/data/code classification. `pure:true` forbids function-directory or decompiler-refresh side effects.
- Immediate readback: require rename summary `total:1`, `ok:1`, `failed:0`, `stopped:false`, one function result at `0x005128a0` with exact new name and no error; then rerun name/address lookup, collision lookup, comments, frame, bytes/hash, profile, xrefs, and the still-exact I01-I04 poststates before I06.
- Hard stop: if any literal prestate, desired-name collision, earlier-stage poststate, mutation response, or immediate poststate differs, perform no further mutation and do not save the IDB.

**I06 - read-only adapter pure rename**

- Classification: apply.
- Evidence / confidence: strong; fresh runtime-attested function lookup, desired-name noncollision lookup, comments, frame, bytes, profile, and xrefs matched the protected function state. The semantic name remains inferred because no inbound route or original private symbol survives.
- Schema-complete request: `rename` with `{"database":"supervisor_uid0000md_persistverify_20260816","batch":{"func":{"addr":"0x00512900","name":"HandleReadOnlyPaperPacket"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: exact function `[0x00512900,0x0051295d)`; size `0x5d` / 93; exact current name `sub_512900`; prototype `char __stdcall(int a1)`; body bytes `558bec6aff68632d600064a1000000005051a1242f670033c5508d45f464a3000000006880020000e87321feff83c4048945f0c745fc0000000085c0740c6a01ff75088bc8e826280300b0018b4df464890d00000000598be55dc20400`; SHA256 `D11423704E51BF3D23A0C60E786B96050BA3C818EC76BE4BED7360264377D4A1`; AR absent; AP absent; FR absent; FP absent; zero external inbound xrefs; no data xref; desired name `HandleReadOnlyPaperPacket` absent/noncolliding.
- Complete seven-row frame prestate: `Block@0x4/0x4/void *`; `var_C@0x8/0x4/_DWORD`; `var_4@0x10/0x4/_DWORD`; `__saved_registers@0x14/0x4/_DWORD`; `__return_address@0x18/0x4/_UNKNOWN *`; `arg_0@0x1c/0x4/_DWORD`; `arg_4@0x20/0x4/_DWORD`; zero additional rows.
- Protected calls and lowering: preserve source-semantic calls to `NexusTK_operator_new` at `0x004f4aa0` and constructor `0x00545170`, plus existing compiler/EH/security references to the function entry, `0x004f4ac0`, `0x005c772f`, and `0x005c956c`; no call/reference/body change is permitted.
- Protected fields / expected poststate: only the function name changes to exactly `HandleReadOnlyPaperPacket`; preserve prototype, all seven frame rows and zero-row count, all comment channels absent, range/size/body bytes/hash, xrefs, calls/references, and function/data/code classification. `pure:true` forbids function-directory or decompiler-refresh side effects.
- Immediate readback: require rename summary `total:1`, `ok:1`, `failed:0`, `stopped:false`, one function result at `0x00512900` with exact new name and no error; then rerun name/address lookup, collision lookup, comments, frame, bytes/hash, profile, xrefs, and the still-exact I01-I05 poststates.
- Hard stop: if any literal prestate, desired-name collision, earlier-stage poststate, mutation response, or immediate poststate differs, perform no further mutation and do not save the IDB.

Endpoint summary and final readback: execute exactly I01 -> I02 -> I03 -> I04 -> I05 -> I06. I01-I04 each bind one AR-only change through schema-complete `set_address_comments`; I05-I06 each bind one function-name-only change through schema-complete `rename` with `pure:true`, `allow_overwrite:false`, `dry_run:false`, and `stop_on_error:true`. After I06, perform one complete final reread of all six entities, all item/function names and types, all four comment channels, both complete seven-row frames, ranges, sizes, bytes/hashes, classifications, calls, boundaries, and xrefs. Success requires that the only differences from the six literal prestates are four exact regular address comments at `0x00621af8/0x00621b60/0x00621b90/0x00621b98` and two exact function names at `0x005128a0/0x00512900`; AP, FR, FP, types, frames, bytes, boundaries, xrefs, calls, and all other names remain unchanged. Any mismatch at any point is a hard stop requiring no further mutation and no save; an IDB save is permitted only after the complete final reread passes and remains supervisor-owned.

## First-Draft C++ Recommendation

Formal target CPP for UID0002NC; target H remains blank:

```cpp
// Compiler-generated EditablePaperPane vtables, COL pointers, and RTTI.
// Human source is the EditablePaperPane class declaration and virtual definitions.
```

Formal vtable-type CPP for UID0001XF; type H remains blank:

```cpp
// Compiler-generated EditablePaperPane three-view vtable/RTTI layout.
// No handwritten vtable arrays, locator pointers, or adjustor entries.
```

Formal class CPP for UID000048:

```cpp
#include "EditablePaperPane.h"

[[CHILDREN]]
```

Formal complete class H for UID000048:

```cpp
#pragma once

#include "DialogPane.h"

enum PaperOpenMode
{
    kPaperOpenEditable = 0,
    kPaperOpenReadOnly = 1
};

class EditablePaperPane : public DialogPane
{
public:
    EditablePaperPane(const unsigned char *packet, PaperOpenMode mode);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void DrawBackground();
    virtual void DrawBorder();
    virtual void InitializePaperContent(wchar_t *text);

private:
    void ParseEditablePacket(const unsigned char *packet);
    void ParseReadOnlyPacket(const unsigned char *packet);
    void SavePaperContent();

    unsigned char m_paperId;
    unsigned char m_packetStatusByte;
    signed char m_widthTiles;
    signed char m_heightTiles;
    short m_textLength;
    int m_reservedPaperState;
    PaperOpenMode m_paperMode;
    unsigned char m_centerText;
};

typedef char EditablePaperPaneSizeMustBe640[
    sizeof(EditablePaperPane) == 0x280 ? 1 : -1];
```

Formal complete method CPP for UID0001EE:

```cpp
#include "EditablePaperPane.h"

#include <string.h>
#include <wchar.h>
#include <windows.h>

#include "../controls/TextButtonControlPane.h"
#include "../controls/TextEditControlPane.h"
#include "../controls/TextEditPane.h"
#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ResourceLayoutTable.h"
#include "../core/MainUiLayerSlots.h"

namespace
{
const int kPaperTileSize = 16;
const int kPaperLineHeight = 12;
const int kPaperTextCapacity = 8000;
const int kPaperPacketCapacity = 32000;
const unsigned char kSavePaperOpcode = 0x23;
const wchar_t kPaperResource[] = L"LINE001.EPD";

unsigned short ReadPaperLength(const unsigned char *packet)
{
    return static_cast<unsigned short>(
        (static_cast<unsigned short>(packet[5]) << 8) | packet[6]);
}

void NormalizePaperText(wchar_t *text, wchar_t from, wchar_t to)
{
    const int length = static_cast<int>(wcslen(text));
    for (int index = 0; index < length; ++index) {
        if (text[index] == from)
            text[index] = to;
    }
}
}

EditablePaperPane::EditablePaperPane(const unsigned char *packet,
                                     PaperOpenMode mode)
    : DialogPane(L"", 7, true),
      m_paperMode(mode)
{
    if (mode == kPaperOpenEditable) {
        ParseEditablePacket(packet);
    } else if (mode == kPaperOpenReadOnly) {
        ParseReadOnlyPacket(packet);
    }
}

void EditablePaperPane::OnControlCommand(int controlIndex,
                                         int /*notifyCode*/)
{
    if (controlIndex != 0)
        return;

    if (m_paperMode == kPaperOpenEditable)
        SavePaperContent();

    CloseDialog();
}

void EditablePaperPane::ParseEditablePacket(const unsigned char *packet)
{
    char narrowText[kPaperTextCapacity];
    wchar_t wideText[kPaperTextCapacity];

    m_paperId = packet[1];
    m_packetStatusByte = packet[2];
    m_widthTiles = static_cast<signed char>(packet[3]);
    m_heightTiles = static_cast<signed char>(packet[4]);

    const unsigned short byteCount = ReadPaperLength(packet);
    memcpy(narrowText, packet + 7, byteCount);
    narrowText[byteCount] = 0;

    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, narrowText, byteCount, wideText, kPaperTextCapacity);
    wideText[wideCount] = 0;
    m_textLength = static_cast<short>(wideCount);

    m_packetStatusByte = 0;
    InitializePaperContent(wideText);
}

void EditablePaperPane::ParseReadOnlyPacket(const unsigned char *packet)
{
    char narrowText[kPaperTextCapacity];
    wchar_t wideText[kPaperTextCapacity];

    m_packetStatusByte = packet[1];
    m_widthTiles = static_cast<signed char>(packet[2]);
    m_heightTiles = static_cast<signed char>(packet[3]);
    m_centerText = packet[4];

    const unsigned short byteCount = ReadPaperLength(packet);
    memcpy(narrowText, packet + 7, byteCount);
    narrowText[byteCount] = 0;

    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, narrowText, byteCount, wideText, kPaperTextCapacity);
    wideText[wideCount] = 0;
    m_textLength = static_cast<short>(wideCount);

    m_packetStatusByte = 0;
    InitializePaperContent(wideText);
}

void EditablePaperPane::InitializePaperContent(wchar_t *text)
{
    NormalizePaperText(text, L'\t', L'\r');

    const short paneWidth =
        static_cast<short>((m_widthTiles + 2) * kPaperTileSize);
    const short paneHeight =
        static_cast<short>((m_heightTiles + 3) * kPaperTileSize);

    RectBounds bounds;
    InitRectBounds(&bounds, -200, -200, -140, -180);
    AddControl(new TextButtonControlPane(
        g_pLanguageMan->GetLocalizedString(
            m_paperMode == kPaperOpenEditable ? 95 : 96),
        &bounds));

    if (m_paperMode == kPaperOpenReadOnly && m_centerText != 0) {
        const short textWidth =
            static_cast<short>(8 * static_cast<short>(wcslen(text)));
        const short left = static_cast<short>((paneWidth - textWidth) / 2);
        const short top = static_cast<short>((paneHeight - kPaperLineHeight) / 2);
        InitRectBounds(&bounds, left, top,
                       static_cast<short>(left + textWidth),
                       static_cast<short>(top + kPaperLineHeight));
    } else {
        InitRectBounds(&bounds,
                       kPaperTileSize,
                       kPaperTileSize,
                       static_cast<short>(paneWidth - kPaperTileSize),
                       static_cast<short>((m_heightTiles + 1) *
                                          kPaperTileSize));
    }

    bounds.bottom = static_cast<short>(
        bounds.top +
        kPaperLineHeight *
            ((bounds.bottom - bounds.top - 1) / kPaperLineHeight));

    TextEditControlPane *editor =
        new TextEditControlPane(L"", true, 128, 143, &bounds,
                                false, true, false, false, 1.0f, false);
    AddControl(editor);
    editor->GetTextEditPane()->SetScrollbarsVisible(false);
    editor->SetHandlesEnterKey(true);

    if (m_paperMode == kPaperOpenEditable) {
        editor->SetMaxLines(42);
        editor->SetMaxLength(250);
        editor->GetTextEditPane()->InsertTextRange(
            text, static_cast<short>(wcslen(text)), NULL, NULL);
        SetHoverControl(1);
        editor->GetTextEditPane()->SetSelectionRange(0, 0);
    } else {
        editor->SetMaxLines(2000);
        editor->SetMaxLength(30000);
        editor->SetEditActiveState(false, false);
        editor->GetTextEditPane()->InsertTextRange(
            text, static_cast<short>(wcslen(text)), NULL, NULL);
        editor->GetTextEditPane()->SetSelectionRange(0, 0);
        editor->SetSelectable(false);
        SetHoverControl(0);
    }

    SetPendingControl(0);
    if (m_paperMode == kPaperOpenReadOnly)
        SetFocusedControl(0);

    InitRectBounds(&bounds,
                   320 - paneWidth / 2,
                   240 - paneHeight / 2,
                   320 + paneWidth / 2,
                   240 + paneHeight / 2);
    OnCreate(&bounds, 0, NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

void EditablePaperPane::SavePaperContent()
{
    wchar_t wideText[kPaperTextCapacity];
    char narrowText[kPaperTextCapacity];
    unsigned char packet[kPaperPacketCapacity];

    TextEditControlPane *editor = GetChild<TextEditControlPane>(1);
    const short wideCount = editor->ReadText(
        wideText, static_cast<short>(kPaperTextCapacity));

    for (short index = 0; index < wideCount; ++index) {
        if (wideText[index] == L'\r')
            wideText[index] = L'\t';
    }

    packet[0] = kSavePaperOpcode;
    packet[1] = m_paperId;

    const int byteCount = WideCharToMultiByte(
        CP_ACP, 0, wideText, wideCount,
        narrowText, kPaperTextCapacity, NULL, NULL);
    narrowText[byteCount] = 0;
    packet[2] = static_cast<unsigned char>(byteCount >> 8);
    packet[3] = static_cast<unsigned char>(byteCount);
    memcpy(packet + 4, narrowText, byteCount);

    const unsigned int packetLength =
        static_cast<unsigned int>(byteCount + 4);
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}

void EditablePaperPane::DrawBorder()
{
    EPFTileContext frames[8];
    const int frameOrder[8] = { 0, 1, 2, 7, 3, 6, 5, 4 };
    for (int index = 0; index < 8; ++index) {
        frames[index].Initialize();
        g_pEPFLib->LookupLayoutEntry(
            kPaperResource, frameOrder[index], &frames[index]);
    }

    RectBounds sourceBounds;
    RectBounds originBounds;
    RectBounds destinationBounds;
    InitRectBounds(&sourceBounds, 0, 0, 16, 16);
    InitRectBounds(&originBounds, 0, 0, 16, 16);

    const int width = m_visibleBounds.right - m_visibleBounds.left;
    const int height = m_visibleBounds.bottom - m_visibleBounds.top;

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16, 0);
    do {
        RenderTileFrame(&frames[1], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 16, 0);
    } while (destinationBounds.right < originBounds.left + width - 1);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 16, height - 16);
    do {
        RenderTileFrame(&frames[6], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 16, 0);
    } while (destinationBounds.right < originBounds.left + width - 1);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0, 16);
    do {
        RenderTileFrame(&frames[3], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 0, 16);
    } while (destinationBounds.bottom < originBounds.top + height - 1);

    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, width - 16, 16);
    do {
        RenderTileFrame(&frames[4], &sourceBounds, &destinationBounds,
                        1, NULL, NULL);
        OffsetRect(&destinationBounds, 0, 16);
    } while (destinationBounds.bottom < originBounds.top + height - 1);

    destinationBounds = originBounds;
    RenderTileFrame(&frames[0], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, width - 16, 0);
    RenderTileFrame(&frames[2], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, 0, height - 16);
    RenderTileFrame(&frames[5], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
    destinationBounds = originBounds;
    OffsetRect(&destinationBounds, width - 16, height - 16);
    RenderTileFrame(&frames[7], &sourceBounds, &destinationBounds,
                    1, NULL, NULL);
}

void EditablePaperPane::DrawBackground()
{
    EPFTileContext frame;
    frame.Initialize();
    g_pEPFLib->LookupLayoutEntry(kPaperResource, 8, &frame);

    RectBounds bounds = m_visibleBounds;
    InsetRect(&bounds, kPaperTileSize, kPaperTileSize);
    m_drawMode = 0;
    DrawTiledBackground(&bounds, &frame, NULL);
}
```

UID0001EE formal H disposition: keep `RECONSTRUCTION_H` blank. The complete EditablePaperPane declaration, including every method declared for the UID0001EE definitions above, is centralized in [UID:000048] `by-class/EditablePaperPane.md` formal H. Duplicating any declaration on UID0001EE would create a second class/header authority.

Formal retained MapPane adapter CPP for exact children [UID:000536] and [UID:000537]. The direct include was added after the first generated readback proved MapPane.cpp otherwise had no declaration for `EditablePaperPane` or `PaperOpenMode`:

```cpp
#include "../ui/dialogs/EditablePaperPane.h"

static bool __stdcall HandleEditablePaperPacket(const unsigned char *packet)
{
    new EditablePaperPane(packet, kPaperOpenEditable);
    return true;
}

static bool __stdcall HandleReadOnlyPaperPacket(const unsigned char *packet)
{
    new EditablePaperPane(packet, kPaperOpenReadOnly);
    return true;
}
```

- [UID:000536] `[0x005128a0,0x005128fd)` formal H disposition: blank, because `HandleEditablePaperPacket` is a file-static `MapPane.cpp` CPP definition and has no header declaration. Its formal CPP owns the single direct include that declaration-covers both adjacent adapters.
- [UID:000537] `[0x00512900,0x0051295d)` formal H disposition: blank, because `HandleReadOnlyPaperPacket` is a file-static `MapPane.cpp` CPP definition and has no header declaration.
- Validator-assigned identifiers 000536/000537 are reconciled into every formal-child, support, manual-coverage, ledger, and checklist reference in this report.

Formal ScrollPane H dependency insertion for [UID:0000CM] `by-class/ScrollPane.md`, `RECONSTRUCTION_H`, immediately after `void SetSkinIndex(unsigned short skinIndex);` and before `bool IsScrollThumbVisible();`:

```cpp
    void SetScrollStyle(unsigned char scrollStyle)
    {
        if (m_scrollStyle == scrollStyle)
            return;

        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_visibleBounds);
    }
```

This inline definition is the source-safe cause of the exact UID00042X compare/write/invalidate lowering and of the two inlined copies in `0x0055e840`. It uses inherited public `Pane::InvalidateRect`, inherited protected `GrafPort::m_visibleBounds`, and existing private `ScrollPane::m_scrollStyle`; it requires no include beyond the existing `ScrollBar.h` dependency chain and adds no field, virtual slot, or out-of-line declaration. `SetScrollStyle` remains an inferred source-facing spelling and a confidence cap. UID00042X therefore keeps blank formal H and no separate authored CPP body; its current comment-only marker must be historicalized to describe the retained unreferenced out-of-line compiler copy of this inline API rather than an unresolved callable placeholder.

Formal ScrollablePane H insertion for [UID:0000CF] `by-class/ScrollablePane.md`, `RECONSTRUCTION_H`, immediately after `void SetSkinIndex(unsigned short skinIndex);` and before `void SetScrollTargetValue(short targetPosition, char axis);`:

```cpp
    void SetScrollbarsVisible(bool visible);
```

Formal ScrollablePane CPP replacement for [UID:0001GL] `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`, `RECONSTRUCTION_CPP`: replace only the existing `[0x0055e840,0x0055e897)` no-code comment, immediately after `ScrollablePane::SetSkinIndex` and before the `[0x0055e8a0,0x0055e8c7)` disposition, with this complete body:

```cpp
void ScrollablePane::SetScrollbarsVisible(bool visible)
{
    if (m_horizontalScrollPane != 0) {
        m_horizontalScrollPane->SetScrollStyle(
            static_cast<unsigned char>(visible));
    }

    if (m_verticalScrollPane != 0) {
        m_verticalScrollPane->SetScrollStyle(
            static_cast<unsigned char>(visible));
    }
}
```

The body preserves the exact horizontal-then-vertical order, null checks, changed-value checks, one-byte stores at each child `+0xfa`, and virtual `InvalidateRect` calls with each child inherited bounds at `+0x44`. Inlining the formal dependency above yields the complete `0x0055e840` body without raw offsets or undeclared facades. It adds no include: UID0001GL already emits through UID0000CF/UID0000NF with `#include "ScrollBar.h"`, where ScrollPane precedes ScrollablePane. No other UID0001GL no-code disposition changes.

Formal ControlPane H insertion for [UID:000038] `by-class/ControlPane.md`, `RECONSTRUCTION_H`, immediately after `bool IsSelectable() const { return m_controlFlags != 0; }` and before `bool IgnoresHitTesting() const;`:

```cpp
    void SetSelectable(bool selectable)
    {
        m_controlFlags = selectable ? 1 : 0;
    }
```

UID000038 CPP disposition for this API: blank, because the complete setter is inline in formal H. The insertion uses the existing protected `m_controlFlags`, adds no include, storage, padding, virtual slot, or out-of-line symbol, preserves the `0x108` layout, and emits through [UID:0000IG] `by-file/ControlPane.md` at existing class position 10.

## Final Recommendation

- Preserve the implemented range correction, compiler no-code disposition, direct class owner, complete slot/RTTI map, full source declaration, corrected method source, adapter placement, exact support API blocks, score changes, coverage handoff, and six supervisor IDA recommendations as one coordinated package. Ordinary incorporation and generated declaration closure are complete; I01-I06 remain supervisor-owned Gate 2B dispositions.
- Do not retain the current blank-emitter route or old `0x621afc` start.
- Coverage, IDA mutation/save, report execution, and archive movement remain supervisor-owned dispositions. Their state is authoritative only from current external artifacts and validator-owned lifecycle metadata.

## Recommended Target Doc Changes

- Rename the same UID0002NC file to `0x00621af8-0x00621b98.EditablePaperPaneVtableData.md`.
- Set `COMPLETION:94`, `CONFIDENCE:96`, `CANONICAL_OWNER:000048`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank position, comment-only no-code formal CPP, blank H, and retain `Nested:0`.
- Replace the range identity with the corrected 160-byte hash and add exact subrange hashes, all 40 dwords, all 37 slots, all three COL/RTTI records, constructor stores, comments/item state, xrefs, successor string, and source/compiler disposition.
- Historicalize the old 156-byte hash, old type-page owner/emitter, `0x0045004e` pollution, and old reconstructable empty-emitter policy without deleting their chronology.

## Recommended Support Doc Changes

- UID0001XF: complete three-view layout/RTTI, compiler no-code formal, direct class owner, non-reconstructable, `94/96`.
- UID000048: complete CPP/H, direct DialogPane inheritance, exact virtual order, fields/layout, implicit destructor, score `94/94`.
- UID0001EE `by-memory/0x00545170-0x00545e3b.EditablePaperPane.md`: replace `RECONSTRUCTION_CPP` with the complete Section 22 block at its existing aggregate position; preserve exact ranges/hashes/packet/resource/compiler history; keep `RECONSTRUCTION_H` blank because UID000048 owns all declarations; score `94/93`. Dependencies remain `EditablePaperPane.h`, `TextEditControlPane.h`/`TextEditPane.h`, ScrollBar declarations, ControlPane declarations, EPFTileContext/resource helpers, PacketBuffer/Socket sender, MainUiLayerSlots, Win32 conversion, C string/wide-string operations, and compiler range/security lowering; no raw helper facade or duplicate declaration is added.
- UID0000IX: full file inventory, source route, dependency/header expectations, wrapper boundary, generated expectations, score `94/93`.
- UID000263: corrected target range, class-source closure, no duplicate emission; score unchanged.
- UID0001EF: preserve exact compiler adjustors/no-code and raise to `92/96`.
- UID0002OG: verify-only boundary preservation; no score or formal change.
- UID0001AW `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`: exact retained adapter children UID000536 and UID000537 are present in address order, with complete hashes, three-byte successor-padding fences, exact frames, zero-inbound route caveats, allocation/constructor behavior, and every unrelated packet/helper row preserved. Its aggregate CPP remains blank because exact children emit.
- UID0000L3 `by-file/MapPane.md`: both file-static CPP children are incorporated in documentation/address order after UID0004SN and before UID0003TQ, with no H declarations, no direct MapPane member claims, no active inbound-route claim, no class-layout change, and no pruning of the broad existing MapPane union. UID000536 emits the one required direct `../ui/dialogs/EditablePaperPane.h` include. The dated callback generated snapshot placed the file-static trio after the class-emitted UID0003TQ body while preserving UID0004SN -> UID000536 -> UID000537 local order; later generated topology requires dynamic reread. Score stays unchanged.
- UID00007Q `by-class/MapPane.md`: no formal or coverage-row change. The adapters are file-static and therefore do not enter the MapPane class declaration, layout, method union, or H source position; preserve the exact current row quoted in Section 28.
- UID0000CM `by-class/ScrollPane.md`: in formal H, insert the complete inline `SetScrollStyle(unsigned char)` block after `SetSkinIndex` and before `IsScrollThumbVisible`; no include/layout/vtable change. UID00042X `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` keeps blank H and no standalone authored CPP, but historicalizes the unresolved-placeholder wording in favor of the exact retained out-of-line inline-copy disposition. Preserve its bytes, zero-route facts, padding, owner/emitter, and `86/88` score.
- UID0000CF `by-class/ScrollablePane.md`: insert only `void SetScrollbarsVisible(bool visible);` in formal H after `SetSkinIndex`; preserve the complete `0x130` declaration, all existing members/virtuals, blank source position, owner UID0000NF, and score. UID0001GL `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`: replace only the `0x0055e840-0x0055e897` no-code comment with the complete Section 22 CPP body immediately after `SetSkinIndex`; preserve all other method/no-code rows, exact boundaries/padding/xrefs/history, and score. UID0000NF `by-file/ScrollBar.md`: record the new ordinary definition/declaration route and inline dependency with existing `ScrollBar.h`/Pane/RectBounds dependencies and no score inflation.
- UID000038 `by-class/ControlPane.md`: insert only the exact inline `SetSelectable(bool)` block after `IsSelectable`, keep its CPP contribution blank, and preserve protected storage, complete `0x108` layout, source position 10, every existing virtual/method, and score. UID0000IG `by-file/ControlPane.md`: record the header-only API route; no CPP child, include, storage, position, or score change.
- Related EPF/resource, TextEdit, DialogPane, Pane, PacketBuffer, Socket, BackPane, MainUiLayerSlots, and LodePNG pages are dependency/verify-only unless an exact stale target statement is encountered during callback reread.

## Score And Metadata Recommendation

| UID | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| 0002NC | `88/92`, reconstructable, owner/emitter 0001XF | `94/96`, false, owner 000048, blank emitter | Exact corrected range/hash/items/slots/RTTI/boundary and no-code cause. |
| 0001XF | `86/90`, reconstructable | `94/96`, false, owner 000048, blank emitter | Complete three-view compiler layout and class route. |
| 000048 | `87/88` | `94/94` | Complete class H/layout/virtual/source closure; lexical caps remain. |
| 0000IX | `87/88` | `94/93` | Complete file contents/source/header/wrapper boundary. |
| 0001EE | `87/88` | `94/93` | All source behaviors and blockers resolved; private names remain inferred. |
| 0001EF | `85/90` | `92/96` | Exact two-thunk binary/compiler disposition. |
| 000263 | `86/94` | unchanged | Parent inventory prose only. |
| 0002OG | `94/96` | unchanged | Exact predecessor boundary already present. |
| 0001AW / 0000L3 | current scores | unchanged | Bounded adapter incorporation does not complete broad MapPane further. |

Completion below 95 on source documents reflects lost original lexical spellings, retained adapter liveness uncertainty, and descriptive reserved/control API names. Target/type confidence reaches 96 because physical/compiler identity is exact.

## Open Questions With Attempted Resolution

| Question | Attempts | Resolution |
| --- | --- | --- |
| Is `0x621af8` predecessor padding or target data? | Predecessor doc, bytes, xref, COL, RTTI PMD, table signature. | Resolved target primary locator; range must expand. |
| Are secondary/tertiary direct bases? | CHD/PMDs plus accepted Pane H. | Resolved inherited facets through Pane; no direct bases. |
| What is `0x545220`? | Base vtable order, `retn 8`, argument compare, siblings. | Resolved OnControlCommand(int,int). |
| Is `+0x270` used for centering? | Full setup decompile and class access scan. | Resolved no; setup calls wcslen. |
| What is `+0x274`? | Every class body/access queried. | No semantic read/write exists; exact four-byte source reservation is the honest representation and a score cap, not a blocker. |
| Are malformed lengths clipped? | Parser/save control-flow and range-helper audit. | Resolved no source clipping; compiler range failure only. |
| Where do wrappers belong? | Exact bytes, calls, zero refs, neighbor adapter, locality, signatures. | Resolved retained file-static MapPane.cpp adapters with explicit no-route caveat. |
| Should vtable pages emit code? | Compiler ABI comparison and class declaration closure. | Resolved no handwritten storage; comment-only formal markers prevent empty emitters. |
| Does source need an explicit destructor? | Scalar/adjustor/class cleanup audit. | Resolved implicit derived destructor; no authored body. |
| Is MCP evidence usable after the timeout? | Listener recovery, fresh idb_list, new active session, repeated bounded queries. | Resolved yes; all material facts were re-established live. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Coverage was not edited by B001. The following current rows were physically read on 2026-08-16. `Current` quotations are literal manual-row state; `Replacement` text is the exact supervisor-owned payload. Adapter identifiers are now permanent validator-assigned UIDs, not templates.

- `by-memory/-coverage-report.md`, UID0002NC current literal row in the vtable-data address band:
  >         - [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md) 0x00621afc-0x00621b98 | vtable-data | EditablePaperPaneVtableData : reconstructable : 88% : strong : 2026-06-07 A010 Batch013 live IDA raised doc to 88/92; reconfirmed the three EditablePaperPane vtable bases, constructor store xrefs, `LINE001.EPD` boundary, and post-vtable string-byte pollution; assigned to [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md) after child 88/92 and parent 86/90 pass the corrected gate.
  Replacement at the same address position:
  `        - [UID:0002NC][0x00621af8-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md) 0x00621af8-0x00621b98 | compiler-generated vtable/RTTI data | EditablePaperPaneVtableData : not_reconstructable : 94% : exact : Complete 160-byte three-view EditablePaperPane compiler island with primary RTTI predecessor, 24/11/2 slots, COL offsets 0/+0xa0/+0xa4, seven-base RTTI, constructor stores, adjustor routes, LINE001.EPD successor boundary, direct class ownership, and no handwritten vtable/COL source.`
- `by-type/by-vtable/-coverage-report.md`, UID0001XF current literal row:
  > - [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md) : reconstructable : 86% : strong : IDA-confirmed three-view `EditablePaperPane` vtable cluster now attached to [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md), with exact [UID:0002NC][0x00621afc-0x00621b98.EditablePaperPaneVtableData](by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md) child, constructor-store xrefs, key slots, adjustor thunks, and `LINE001.EPD` string/data boundary.
  Replacement at the same UID position:
  `- [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md) : not_reconstructable : 94% : exact : Complete class-generated EditablePaperPane primary DialogPane, inherited EventHandler +0xa0, and inherited TimerHandler +0xa4 views with 24/11/2 slots, exact RTTI PMDs, constructor stores, implicit-destructor adjustors, direct UID000048 ownership, and blank emitter/no raw-array source.`
- `by-class/-coverage-report.md`, UID000048 current literal row:
  > - [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md) : reconstructable : 84% : strong : - Confidence: strong for behavior, layout, method families, packet behavior, and core ownership.
  Replacement at the same UID position:
  `- [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md) : reconstructable : 94% : very-strong : Complete 0x280 DialogPane-derived paper dialog declaration with exact OnControlCommand/DrawBackground/DrawBorder/InitializePaperContent virtual surface, typed +0x26c..+0x27c tail, natural padding, implicit destructor, editable/read-only packet behavior, LINE001.EPD rendering, direct three-view vtable ownership, and complete source/header route.`
- `by-file/-coverage-report.md`, UID0000IX current literal row:
  > - [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) : reconstructable : 86% : strong : Packet-opened paper pane module with function map, vtable/adjustor evidence, false LodePNG ownership exclusion, text-edit/resource dependencies, wrapper caveats, and cross-references documented.
  Replacement at the same UID position:
  `- [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) : reconstructable : 94% : very-strong : NexusTK/ui/dialogs EditablePaperPane.cpp/.h source root with complete class declaration, constructor/action/setup/parsers/save/draw definitions, exact packet layouts and trusted-buffer behavior, LINE001.EPD frame mapping, compiler-vtable exclusions, MapPane adapter boundary, and no remaining target/class/type empty-emitter marker.`
- `by-memory/-coverage-report.md`, UID0001EE current literal row at `0x00545170`:
  >     - [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md) 0x00545170-0x00545e3b | class-method aggregate | EditablePaperPane : reconstructable : 84% : strong : Packet-opened paper document dialog class aggregate with editable/read-only parsers, common content/control setup, save opcode `0x23` serializer, `LINE001.EPD` border/background renderers, scalar-deleting destructor, child adjustor thunk exclusion, exact vtable-data boundary, class parent attachment, final-C++ gate, and unresolved `+0x26d`/wrapper-placement caveats documented.
  Replacement at the same address position:
  `    - [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md) 0x00545170-0x00545e3b | class-method aggregate | EditablePaperPane : reconstructable : 94% : very-strong : Source-ready constructor, two-argument OnControlCommand, setup, editable/read-only parsers, save serializer, LINE001.EPD border/background renderers, exact 0x280 tail layout, trusted packet semantics, implicit destructor/compiler split, complete CPP route, and resolved wrapper boundary.`
- `by-memory/-coverage-report.md`, UID0001EF current literal row at `0x00545ddd`:
  >     - [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) : ignored : 80% : strong : - Confidence: strong for thunk identities and destructor target.
  Replacement at the same address position:
  `        - [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) 0x00545ddd-0x00545df3 | compiler adjustor thunks | EditablePaperPaneAdjustorThunks : not_reconstructable : 92% : exact : Exact 11-byte this-0xa0 and this-0xa4 deleting-destructor adjustors into 0x00545e00, generated by the implicit derived destructor and three-view class declaration with no handwritten thunk source.`

Complete required current-row comparison and support/adapter handoff:

- UID000263, `by-memory/-coverage-report.md`, current literal row at address `0x006219e8`:
  >     - [UID:000263][0x006219e8-0x00621db8.PaneParcelReadOnlyData](by-memory/0x006219e8-0x00621db8.PaneParcelReadOnlyData.md) 0x006219e8-0x00621db8 | vtable/string-data | PaneParcelReadOnlyData : ignored : 86% : very-strong : Non-emitting mixed-owner read-only-data index whose exact children carry Pane, PanelPane, EditablePaperPane, ParcelIconPane, ParcelPane, FlyingParcelPane, and resource-string ownership; B002 reconfirms the PanelPane child [0x00621a6c,0x00621af8) and exact Pane/EditablePaperPane fences without assigning the mixed aggregate to one source owner.
  Replacement at the same row position:
  `    - [UID:000263][0x006219e8-0x00621db8.PaneParcelReadOnlyData](by-memory/0x006219e8-0x00621db8.PaneParcelReadOnlyData.md) 0x006219e8-0x00621db8 | vtable/string-data | PaneParcelReadOnlyData : ignored : 86% : very-strong : Non-emitting mixed-owner read-only-data index whose exact children carry Pane, PanelPane, EditablePaperPane, ParcelIconPane, ParcelPane, FlyingParcelPane, and resource-string ownership; the corrected EditablePaperPane child is [0x00621af8,0x00621b98), begins with its primary RTTI locator, is compiler-generated through UID000048, and emits no duplicate handwritten vtable source; the PanelPane child still ends exactly at 0x00621af8.`
- UID0001AW, `by-memory/-coverage-report.md`, current literal row at address `0x0050e4c0`:
  >     - [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | packet-handler split index | MapPanePacketHandlers : not_reconstructable : 86% : very-strong : Non-emitting MapPane packet-handler split/container with exact source-bearing children, including source-ready UID0003TI/UID0003TJ static-object creation and region reconciliation, source-ready UID0003TW shared status-overlay helper plus UID0003TX opcode-0x33 ObjectStatusBlob/name/ObjectInfo/status-refresh handling, source-ready UID0003TK opcode-0x15 map/effect-state parsing, source-ready UID0003TL opcode-0x06 map-info/tile-region parsing, source-ready UID0003TO opcode-0x29 trusted object/effect routing, source-ready UID0003TP opcode-0x2e world-map packet parsing/legacy coordinate overrides/WorldMapPane installation, source-ready UID0003TQ opcode-0x13 action-combat processing with exact UID0004SJ Bow setter, UID0004SK Damage constructor, UID0004SL UserPane movement tick, and UID0004SM UserPane group predicate support, retained file-local UID0004SN Pursuit message-dialog packet adapter with explicit zero-inbound-route history, source-ready UID0003TS opcode-0x19 SoundObject/zone-music/MIDI routing with exact framed records, zone/fallback/volume fields, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion, and source-ready UID0003TT opcode-0x1d object-status handling with exact full/partial ObjectStatusBlob, object-info byte, counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle, item refresh through UID0003HS, unsafe trusted-buffer behavior, and unconditional success; preserves every unrelated packet/helper disposition, live opcode-0x67 TimerPane flow, retained zero-route raw duplicates, exact padding, MapPane parsing ownership, compiler/runtime exclusions, and blank aggregate C++. Source-ready UID0003TY opcode-0x03 transition handling adds exact BE32 address/BE16 port/byte-length token parsing, zero-endpoint dialog handling, distinct socket-status/registry fallbacks, preserved uninitialized install-key endpoint behavior, opcode-0x10 send framing, local-player timer cancellation, and six independently owned helper dependencies without changing aggregate ownership or emission.
  Exact replacement: preserve that complete current row verbatim and append `The index also routes validator-assigned children UID000536 at [0x005128a0,0x005128fd) and UID000537 at [0x00512900,0x0051295d) as retained file-static MapPane.cpp adapters; both allocate 0x280-byte EditablePaperPane objects in modes 0/1, always return true, preserve zero-inbound-route liveness caps, and exclude their exact three-byte successor padding.`
- UID0000L3, `by-file/-coverage-report.md`, current literal row at UID order:
  > - [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children route and the full current cross-agent effect/HitBar/static-object/map-state/map-info/object-move/object-info/action-combat union, including UID0003TI/UID0003TJ, UID0003TK, UID0003TL, UID0003TO, UID0003TQ with exact UID0004SJ-UID0004SM owner-file calls, UID0003TW/UID0003TX and corrected UID0002QN behavior; preserves source-ready UID0003TP opcode-0x2e trusted world-map parsing, exact whole-name legacy coordinate overrides, WorldMapPane/Layer installation, cleanup and true return, plus retained file-local UID0004SN Pursuit packet adapter with zero-route history and MessageDialogs creator/member boundary; preserves source-ready UID0003TS opcode-0x19 SoundObject/zone-music/MIDI routing with exact framed records, corrected zone/fallback/volume fields and replay contract, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion; and adds source-ready UID0003TT opcode-0x1d object-status handling in exact source order after UID0003TS with full/partial ObjectStatusBlob, object-info byte, counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle and ItemObjectPane UID0003HS dependency. All unrelated source families remain present; WorldMapPane, MessageDialogs, Layer, ScreenPane, PacketBuffer, MemoryMan, TimerMgr, SoundObjectPane, ObjectList, MidiPlayer, and SoundManager remain dependency/source owners; unsafe trusted-buffer behavior is retained; and compiler/runtime lowering plus by-file formal metadata remain excluded. UID0003TY directly consumes the exact SOFTWARE\\Nexon\\Kingdom of the Winds registry-root literal, so MapPane.cpp is the second source emitter for ownerless UID0003FV pooled data without a RegistryConfig-static dependency, target-owned array, duplicate root declaration, class-ownership change, or by-file formal change. The callback adds source-ready UID0003TY opcode-0x03 map-transition handling with exact trusted packet layout, zero-endpoint dialog branch, distinct socket/registry paths, preserved uninitialized install-key fallback, opcode-0x10 framing, timer cancellation, and six cross-file helper calls without changing unrelated source families or file-root metadata. UID0002SR source closure additionally places private MapRefreshDimmer class position 1 and exact constructor/HandlePacketEvent/OnTimer positions 2-4 in MapPane.cpp, preserving ScreenDimmer(3,g_pScreenPane), timer 0/2000, opcode 0x22 delete-before-FinishVisibleObjectRefresh behavior, implicit destructor/compiler-only ABI boundaries, and the complete pre-existing MapPane union without pruning. UID0003ZT source closure adds exact HandleSystemOrControlEvent(Event *) after the packet dispatcher and before OnTimerEvent, canonical Event::m_type/kEventWorkNotification handling, queued-state drain through inherited TimerHandler and Pane::ReleaseMouseCapture, ConnectionClosedDialog construction, consistent inherited TimerHandler source shape across all affected emitted MapPane children, complete MapPoint placement in MapPane.h, UserPane-typed +0x418 state, self-contained Event.h/LObject.h, Pane/EventHandler/TimerHandler, ObjectStatusBlob/UserPane/InputBlocker/LivingObjectPane/ObjectList, Win32, PacketBuffer/Socket, AlertPanes/ReconnectDialog, and exact global extern routes without changing unrelated source order or ownership.
  Exact replacement: preserve that complete current row verbatim and append `Validator-assigned UID000536 HandleEditablePaperPacket and UID000537 HandleReadOnlyPaperPacket are file-static MapPane.cpp children in documentation/address order after UID0004SN and before UID0003TQ; UID000536 emits the one direct EditablePaperPane.h include needed by both definitions, both have blank H and exact zero-inbound-route history, and they construct EditablePaperPane in modes 0/1 without changing MapPane class layout or member declarations.` File score stays `92`.
- UID00007Q, `by-class/-coverage-report.md`, current literal row and exact no-change proof:
  > - [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era MapPane declaration emitter at position 0 with exact 0x910 layout and current method union, preserving source-ready effect/HitBar/static-object UID0003TI/UID0003TJ work, opcode-0x15 UID0003TK map/effect-state parsing, opcode-0x06 UID0003TL map-info/tile-region parsing, opcode-0x29 UID0003TO object/effect routing, opcode-0x33 UID0003TX object-info handling with UID0003TW status-overlay helper and corrected by-value UID0002QN factory, source-ready opcode-0x13 UID0003TQ action-combat processing with exact UID0004SJ/UID0004SK/UID0004SL/UID0004SM owner-file dependencies, source-ready opcode-0x2e UID0003TP HandleObjectWorldMapCreationPacket trusted parsing with a local std::vector<bool> directed graph, exact whole-name legacy world-map coordinate overrides, WorldMapPane/Layer installation, cleanup and true return, source-ready opcode-0x19 UID0003TS HandleAnimationSoundPacket with SoundObject/zone-music/MIDI subtypes, exact framed records, corrected m_zoneMusicId/m_zoneMusicFallbackTrackIndex/m_zoneMusicVolumeScale fields, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion, and source-ready opcode-0x1d UID0003TT HandleObjectStatusPacket with exact full/partial ObjectStatusBlob, object-info/counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle and UID0003HS item update route; exact file-local UID0004SN Pursuit adapter remains MapPane.cpp-owned while creator/member implementation stays MessageDialogs-owned, and all unrelated methods/fields, class closure, size guard, children, unsafe trusted-buffer behavior, and compiler ABI exclusions remain preserved. The callback adds the private UID0003TY HandleMapTransitionPacket declaration with exact transition-token/socket/registry/dialog/timer behavior and six independently owned helper dependencies while preserving the complete class union. UID0003ZT closure replaces the stale raw notify signature with HandleSystemOrControlEvent(Event *), removes the invented RefreshQueuedMapState helper, retains canonical bool m_queuedMapStateRefresh, uses inherited TimerHandler and Pane::ReleaseMouseCapture source shape, source-types +0x418 as UserPane *, emits complete MapPoint before MapPane, and adds a dependency-closed package for Event/LObject, Pane/EventHandler/TimerHandler, ObjectStatusBlob, UserPane/InputBlocker, LivingObjectPane, ObjectList, Win32 input, PacketBuffer, Socket/g_packetSender, AlertPanes, ReconnectDialog, and g_useEpfAssets while preserving exact 0x910 layout, unrelated declarations, class closure, size guard, and children.
  No replacement is proposed because both new adapters are file-static CPP definitions; they add no class method, H declaration, field, position, size, owner, emitter, score, or confidence change.
- UID0000CM, `by-class/-coverage-report.md`, current literal row:
  > - [UID:0000CM][ScrollPane](by-class/ScrollPane.md) : reconstructable : 87% : strong : Generic Pane-derived ScrollPane source route with exact 0x110 tail layout, coherent one-byte ScrollPanePart typedef/typed constants and accepted constructor/state/draw/input/timer/geometry members, Y-first seven-method input/geometry split, direct method children, formal header C++, no unsupported source size assertion, and explicit exclusion of the no-route +0xfa raw setter from invented callable APIs; unrelated whole-class audit remains outside this bounded target.
  Replacement at the same UID position:
  `- [UID:0000CM][ScrollPane](by-class/ScrollPane.md) : reconstructable : 87% : strong : Generic Pane-derived ScrollPane source route with exact 0x110 tail layout, coherent one-byte ScrollPanePart typedef/typed constants and accepted constructor/state/draw/input/timer/geometry members, Y-first seven-method input/geometry split, direct method children, formal header C++, and exact inline SetScrollStyle(unsigned char) compare/write/invalidate source cause for m_scrollStyle +0xfa; UID00042X remains the zero-inbound retained out-of-line compiler copy, no unsupported size assertion is added, and unrelated whole-class audit remains outside this bounded target.`
- UID00042X, `by-memory/-coverage-report.md`: exact current search proof is zero matching `[UID:00042X]` rows. Insert in address order under UID0001GH after UID00042W and before UID000432:
  `        - [UID:00042X][0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) 0x0055c2e0-0x0055c304 | retained inline out-of-line copy | ScrollPaneByteStateSetterRaw : reconstructable : 86% : strong : Exact no-inbound compare/write/invalidate copy of inline ScrollPane::SetScrollStyle(unsigned char), updating m_scrollStyle +0xfa only on change and invalidating inherited m_visibleBounds through slot +0x20; blank H/no standalone authored CPP, exact padding, zero pointer route, and lexical confidence cap remain preserved.`
- UID0000CF, `by-class/-coverage-report.md`, current literal row:
  > - [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) : reconstructable : 92% : very-strong : Complete ScrollablePane declaration with exact two-flag constructor, scrollbar pointers and integer state, horizontal/vertical flags at +0x10c/+0x10d, RectBounds at +0x110/+0x120, size 0x130, scroll virtual contracts, and ScrollBar CPP/H route.
  Replacement at the same UID position:
  `- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) : reconstructable : 93% : very-strong : Complete ScrollablePane declaration with exact two-flag constructor, scrollbar pointers and integer state, horizontal/vertical flags at +0x10c/+0x10d, RectBounds at +0x110/+0x120, size 0x130, scroll virtual contracts, exact SetScrollbarsVisible(bool) declaration and two-child source route through UID0001GL/inline ScrollPane::SetScrollStyle, and complete ScrollBar CPP/H ownership without new storage or slots.`
- UID0001GL, `by-memory/-coverage-report.md`, current literal row:
  >     - [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) 0x0055e660-0x0055f44f | method cluster | ScrollablePaneCore : reconstructable : 88% : very-strong : Complete ScrollablePane source/evidence cluster with exact constructor/destructor/layout/input/update/helper boundaries, selected-child GetScrollMax/GetScrollPosition and ApplyScrollPosition contracts, inferred SetSkinIndex(unsigned short) propagation to both child m_scrollSkinIndex fields, source-facing +0x100 horizontal offset/+0x104 vertical offset/+0x108 inset fields, viewport recompute use, wrapper/vtable/compiler exclusions, and derived-family consumers including LegendPane, UserLookPane, and ChattingPane.
  Replacement at the same address position:
  `    - [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) 0x0055e660-0x0055f44f | method cluster | ScrollablePaneCore : reconstructable : 88% : very-strong : Complete ScrollablePane source/evidence cluster with exact constructor/destructor/layout/input/update/helper boundaries, selected-child GetScrollMax/GetScrollPosition and ApplyScrollPosition contracts, inferred SetSkinIndex(unsigned short) propagation, source-ready SetScrollbarsVisible(bool) at [0x0055e840,0x0055e897) with horizontal-then-vertical null/changed-value/store/invalidate behavior, source-facing +0x100 horizontal offset/+0x104 vertical offset/+0x108 inset fields, viewport recompute use, wrapper/vtable/compiler exclusions, and derived-family consumers including EditablePaperPane, LegendPane, UserLookPane, and ChattingPane.`
- UID0000NF, `by-file/-coverage-report.md`, current literal row:
  > - [UID:0000NF][ScrollBar](by-file/ScrollBar.md) : reconstructable : 91% : very-strong : Generic ScrollPane/ScrollWidget/ScrollablePane source family assembled through complete `ScrollBar.h` and `ScrollBar.cpp` child markers with Pane/RectBounds dependencies, exact class/method/layout/constant/compiler routes, no literal empty-child placeholder, and historical CScrollBarBackPane placement rejected by its exclusive NewOptionPane volume-control ownership.
  Replacement at the same UID position:
  `- [UID:0000NF][ScrollBar](by-file/ScrollBar.md) : reconstructable : 93% : very-strong : Generic ScrollPane/ScrollWidget/ScrollablePane source family assembled through complete ScrollBar.h and ScrollBar.cpp child markers with Pane/RectBounds dependencies, exact class/method/layout/constant/compiler routes, inline ScrollPane::SetScrollStyle(unsigned char), source-ready ScrollablePane::SetScrollbarsVisible(bool) at 0x0055e840, no new include/storage/slot, no literal empty-child placeholder, and historical CScrollBarBackPane placement rejected by its exclusive NewOptionPane volume-control ownership.`
- UID000038, `by-class/-coverage-report.md`, current literal row:
  > - [UID:000038][ControlPane](by-class/ControlPane.md) : reconstructable : 91% : very-strong : Complete 0x108 Pane-derived control base declaration with exact ControlPane(unsigned char,const RectBounds *) constructor, inline empty virtual destructor, exact primary slot order through byte-return HitTestPart, public enable/disable/hit-testing API plus inline IsEnabled direct-read accessor for inherited +0x101 state, protected state virtuals, exact protected +0xf8..+0x104 range/control/state layout including bool m_handlesEnterKey at +0x100 and inline SetHandlesEnterKey, exact DialogPane Enter-routing semantics, natural tail alignment, complete child routing, NewUserDialogPane2 edge-button consumer, and compiler vtable/thunk/wrapper exclusions at source position 10.
  Replacement at the same UID position:
  `- [UID:000038][ControlPane](by-class/ControlPane.md) : reconstructable : 91% : very-strong : Complete 0x108 Pane-derived control base declaration with exact ControlPane(unsigned char,const RectBounds *) constructor, inline empty virtual destructor, exact primary slot order through byte-return HitTestPart, public enable/disable/hit-testing API, inline IsEnabled/IsSelectable accessors, exact inline SetSelectable(bool) write to protected m_controlFlags, protected state virtuals, exact protected +0xf8..+0x104 range/control/state layout including bool m_handlesEnterKey at +0x100 and inline SetHandlesEnterKey, exact DialogPane Enter-routing semantics, natural tail alignment, complete child routing, EditablePaperPane read-only editor and NewUserDialogPane2 consumers, and compiler vtable/thunk/wrapper exclusions at source position 10.`
- UID0000IG, `by-file/-coverage-report.md`, current literal row:
  > - [UID:0000IG][ControlPane](by-file/ControlPane.md) : reconstructable : 90% : very-strong : Base UI control module under NexusTK/ui/core/ with the complete 0x108 ControlPane declaration before qualified definitions, exact RectBounds constructor, protected +0xf8..+0x104 state band, exact primary virtual order through byte-return HitTestPart, enable/disable/hit-testing methods, inline IsEnabled accessor for direct inherited +0x101 reads including NewUserDialogPane2 shape-edge gating, broad derived-control caller fanout, and compiler vtable/adjustor/deleting-wrapper exclusions. Fresh B004 FittingRoom source-closure audit records `NexusTK/ui/core/ControlPane.h` as the exact companion header for the complete [UID:000038][ControlPane](by-class/ControlPane.md) declaration consumed by [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md); existing `ControlPane.cpp` ownership and all prior control-family evidence remain unchanged.
  Replacement at the same UID position:
  `- [UID:0000IG][ControlPane](by-file/ControlPane.md) : reconstructable : 90% : very-strong : Base UI control module under NexusTK/ui/core/ with the complete 0x108 ControlPane declaration before qualified definitions, exact RectBounds constructor, protected +0xf8..+0x104 state band, exact primary virtual order through byte-return HitTestPart, enable/disable/hit-testing methods, inline IsEnabled/IsSelectable accessors and header-only SetSelectable(bool) state write used by EditablePaperPane, broad derived-control caller fanout, and compiler vtable/adjustor/deleting-wrapper exclusions; the setter adds no CPP child, include, field, slot, or score change, and all prior ControlPane.h ownership/evidence remains unchanged.`

Exact assigned adapter child insertion payloads:

- `by-memory/-coverage-report.md`, after UID0004SN and its `[0x0051289f,0x005128a0)` padding row, before the first adapter's `[0x005128fd,0x00512900)` successor-padding row:
  `        - [UID:000536][0x005128a0-0x005128fd.HandleEditablePaperPacket](by-memory/0x005128a0-0x005128fd.HandleEditablePaperPacket.md) 0x005128a0-0x005128fd | retained file-static packet adapter | HandleEditablePaperPacket : reconstructable : 92% : very-strong : Exact zero-inbound MapPane.cpp adapter that emits one direct EditablePaperPane.h include for both paper adapters, allocates 0x280 bytes, constructs EditablePaperPane in editable mode 0, always returns true, preserves the no-route caveat, has blank formal H, and excludes three-byte successor padding.`
- `by-memory/-coverage-report.md`, after the `[0x005128fd,0x00512900)` padding row and before the second adapter's `[0x0051295d,0x00512960)` successor-padding row/UID0003TQ:
  `        - [UID:000537][0x00512900-0x0051295d.HandleReadOnlyPaperPacket](by-memory/0x00512900-0x0051295d.HandleReadOnlyPaperPacket.md) 0x00512900-0x0051295d | retained file-static packet adapter | HandleReadOnlyPaperPacket : reconstructable : 92% : very-strong : Exact zero-inbound MapPane.cpp adapter declaration-covered by UID000536's direct include, allocating 0x280 bytes, constructing EditablePaperPane in read-only mode 1, always returning true, preserving the no-route caveat, retaining blank formal H, and excluding three-byte successor padding.`

UID000536 and UID000537 were assigned by scoped validator commands 24703 and 24704. The two exact child rows and dependent UID0001AW/UID0000L3 payloads above are ready for supervisor-owned manual coverage reconciliation; no pre-assignment token remains in this report.

Tracker regeneration is validator/supervisor-owned. No manual tracker row is proposed.

## Follow-Up Actions

- Fresh Gate 1/Gate 2A review uses this exact post-implementation artifact, its 33 sections, 58-row twin, source fences, range correction, complete inventories, endpoint contracts, exact formal support blocks, assigned adapter identities, receipts, and lifecycle-neutral role statements.
- B001 completed the accepted ordinary destinations without loss, serially scoped-validated each changed page, released every lease, reconciled assigned UIDs 000536/000537 throughout this report, and physically verified generated output at callback completion. That readback is a dated receipt, not continuing authority.
- The supervisor owns manual coverage reconciliation and all six IDA Gate 2B decisions. IDA actions, if accepted, must be applied in I01-I06 order with immediate full readback and no save unless the supervisor's transaction requires one.
- The callback completion readback recorded one complete EditablePaperPane source definition set, one complete H declaration, one definition per adapter, one direct declaration include, no duplicate adapter, no UID000048/UID0001XF/UID0002NC empty marker, and no raw vtable arrays. It is a dated receipt only; Gate 2A and every later lifecycle action must dynamically reread the latest validator-owned generated artifacts and metadata.
- Execution, archive movement, and subsequent assignment authority are supervisor/lifecycle concerns derived only from current path and validator-owned status/history metadata.

## Confidence

- Target physical range/items/hashes/slots/RTTI/boundary: exact, `96`.
- Class ABI, inheritance, constructor stores, action signature, compiler/source split: exact to very strong, `94-96`.
- Method behavior, packet layouts, setup/save/rendering: very strong, `93-95`.
- File placement and retained adapter placement: strong, `92-93`.
- Remaining uncertainty is lexical only: original private member names, exact inline setter spelling, and retained wrapper original symbols/liveness. These do not block runtime-equivalent source or ownership.

## Validator Results

All commands below ran serially during the implementation callback with exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`; the validator reported canonical root `C:\FastStorage\NTK_Sources\source-3\project-documentation`. Every scoped command exited `0`, returned `ok: 1`, and reported `generated_refresh: deferred`. These commands and all associated generated hashes are dated callback receipts, not continuing authority. No report validator, lifecycle command, or `execute_report` variant was run.

| Command ID / timestamp | Exact single-line command | Result and literal diagnostics |
| --- | --- | --- |
| `000000024696` / `2026-08-16T03:59:12-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00621af8-0x00621b98.EditablePaperPaneVtableData.md --apply --queue-timeout 240` | exit 0; ok 1; pre-existing `missing_ref_uid` warnings (18) plus `autogen_value_invalid emitter_inactive_has_data`; the dated callback generated readback recorded resolution of the target-specific empty-emitter condition. |
| `000000024697` / `2026-08-16T04:00:04-04:00` | `python .\tools\validator.py --mode file --file by-type\by-vtable\EditablePaperPaneVtables.md --apply --queue-timeout 240` | exit 0; ok 1; literal target warning `autogen_value_invalid emitter_inactive_has_data`; the dated callback generated readback recorded no UID0001XF marker. |
| `000000024698` / `2026-08-16T04:01:04-04:00` | `python .\tools\validator.py --mode file --file by-class\EditablePaperPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. Initial class pass before assigned adapter cross-links. |
| `000000024699` / `2026-08-16T04:05:58-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00545170-0x00545e3b.EditablePaperPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. Initial method-source pass before assigned adapter cross-links. |
| `000000024700` / `2026-08-16T04:06:59-04:00` | `python .\tools\validator.py --mode file --file by-file\EditablePaperPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. Initial owning-file pass before assigned adapter cross-links. |
| `000000024701` / `2026-08-16T04:07:39-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x006219e8-0x00621db8.PaneParcelReadOnlyData.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024702` / `2026-08-16T04:08:34-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024703` / `2026-08-16T04:10:18-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005128a0-0x005128fd.HandleEditablePaperPacket.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error; validator assigned exact UID000536. |
| `000000024704` / `2026-08-16T04:11:21-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00512900-0x0051295d.HandleReadOnlyPaperPacket.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error; validator assigned exact UID000537. |
| `000000024705` / `2026-08-16T04:12:04-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0050e4c0-0x00514920.MapPanePacketHandlers.md --apply --queue-timeout 240` | exit 0; ok 1; 15 pre-existing `missing_ref_uid` warnings; no adapter-target error. |
| `000000024706` / `2026-08-16T04:12:54-04:00` | `python .\tools\validator.py --mode file --file by-file\MapPane.md --apply --queue-timeout 240` | exit 0; ok 1; 42 pre-existing `missing_ref_uid` warnings; no adapter-target error. |
| `000000024707` / `2026-08-16T04:14:00-04:00` | `python .\tools\validator.py --mode file --file by-class\ScrollPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024708` / `2026-08-16T04:14:47-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024709` / `2026-08-16T04:15:23-04:00` | `python .\tools\validator.py --mode file --file by-class\ScrollablePane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024711` / `2026-08-16T04:16:03-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x0055e660-0x0055f44f.ScrollablePaneCore.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024713` / `2026-08-16T04:16:31-04:00` | `python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error. |
| `000000024714` / `2026-08-16T04:17:08-04:00` | `python .\tools\validator.py --mode file --file by-class\ControlPane.md --apply --queue-timeout 240` | exit 0; ok 1; 16 pre-existing `missing_ref_uid` warnings; no SetSelectable target error. |
| `000000024716` / `2026-08-16T04:17:42-04:00` | `python .\tools\validator.py --mode file --file by-file\ControlPane.md --apply --queue-timeout 240` | exit 0; ok 1; 13 pre-existing `missing_ref_uid` warnings; no SetSelectable target error. |
| `000000024718` / `2026-08-16T04:18:21-04:00` | `python .\tools\validator.py --mode file --file by-class\EditablePaperPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error; final class pass added UID000536/UID000537 references. |
| `000000024720` / `2026-08-16T04:18:51-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x00545170-0x00545e3b.EditablePaperPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error; final method pass added assigned adapter references. |
| `000000024721` / `2026-08-16T04:19:42-04:00` | `python .\tools\validator.py --mode file --file by-file\EditablePaperPane.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error; final owning-file pass and current EditablePaperPane generated refresh. |
| `000000024722` / `2026-08-16T04:24:37-04:00` | `python .\tools\validator.py --mode file --file by-memory\0x005128a0-0x005128fd.HandleEditablePaperPacket.md --apply --queue-timeout 240` | exit 0; ok 1; no warning/error; final post-readback include correction and dated callback MapPane generated snapshot. |

Validator-owned generated-refresh command `000000024719` at `2026-08-16T04:18:26-04:00` is not presented as a B001 scoped command. Commands 24719, 24721, and 24722 and every hash below are dated callback snapshots only: 24719 covered the callback ScrollBar/ControlPane/GrafPort readback, 24721 the callback EditablePaperPane readback, and 24722 the callback MapPane readback. Gate 2A and later lifecycle actions must dynamically reread the latest generated metadata and files.

Dated callback generated readback:

- `auto-generated/NexusTK/ui/dialogs/EditablePaperPane.cpp`: command 24721, SHA256 `F11B877A3E156E75095E25F40E46B16049D9595D64009BBDB2B55DECD2ED5B32`, 10,805 bytes / 311 physical lines. The callback snapshot recorded exactly one constructor and one each of OnControlCommand, ParseEditablePacket, ParseReadOnlyPacket, InitializePaperContent, SavePaperContent, DrawBorder, and DrawBackground at lines `52/64/76/99/122/200/233/301`; `m_visibleBounds` had 11 CPP uses; no UID0001XF/UID0002NC or empty-emitter marker was present.
- `auto-generated/NexusTK/ui/dialogs/EditablePaperPane.h`: command 24721, SHA256 `417D4CCAD2AC77ED22879D91D8B987C89E10DDEB8AB954CBEA5BC6301933D5A4`, 1,343 bytes / 46 lines. The callback snapshot contained one `PaperOpenMode`, one class, the exact constructor/action/setup declarations, complete fields, and size guard.
- `auto-generated/NexusTK/map/MapPane.cpp`: command 24722, SHA256 `8AB7B90291F5874D9B939FC61AF0DAFC2A41612E568EE2720D2ECD9539E53A28`, 160,062 bytes / 4,792 lines. The callback snapshot contained one direct `../ui/dialogs/EditablePaperPane.h` include at line 4686, one UID000536 definition at 4688, and one UID000537 definition at 4695; each constructor mode occurred once, and no stale static-array body was present. UID0004SN was immediately before the pair; class-owned UID0003TQ was earlier under the pre-existing emitter topology, so documentation/address order and that dated generated owner topology are explicitly distinguished.
- `auto-generated/NexusTK/map/MapPane.h`: command 24722, SHA256 `08A27E67D59A47001855B65B764110ADCAF25E3475D25F59435C34823BE59203`, 13,208 bytes / 378 lines; the callback snapshot emitted no adapter declaration, as required for file-static definitions.
- `auto-generated/NexusTK/ui/core/ScrollBar.cpp`: command 24719, SHA256 `9557F1610F61BA877374D3652C8FFA484618E9DC16809EA95028D371AD02FBCA`, 30,575 bytes / 929 lines; the callback snapshot contained exactly one `ScrollablePane::SetScrollbarsVisible(bool)` at line 827, with horizontal then vertical calls.
- `auto-generated/NexusTK/ui/core/ScrollBar.h`: command 24719, SHA256 `07F0EFBDB9B4C6BFF66445424E0A5084480A35998104CF674027EE2168DABF06`, 3,877 bytes / 112 lines; the callback snapshot contained exactly one inline `SetScrollStyle(unsigned char)` at line 30 and one `SetScrollbarsVisible(bool)` declaration at line 84.
- `auto-generated/NexusTK/ui/core/ControlPane.cpp`: command 24719, SHA256 `AB74706FC4D4ECE2A15053BE56CFADE9137D78C577E3B9A6F31BD9BCE9DE1D1B`, 2,065 bytes / 63 lines; the callback snapshot contained no out-of-line SetSelectable body.
- `auto-generated/NexusTK/ui/core/ControlPane.h`: command 24719, SHA256 `5D6DD07A2007A4DCCAB1819C799F54899595EDDC65073852D718A4BFE2A95210`, 1,547 bytes / 54 lines; the callback snapshot contained exactly one inline `SetSelectable(bool)` at line 25 and declared `m_controlFlags` at line 48.
- `auto-generated/NexusTK/render/GrafPort.h`: command 24719, SHA256 `8305C6AE1F0D41B53055E71C80BFA30DC6AF3433F84CB06DA2681A2C6BBBCA1B`, 5,066 bytes / 124 lines; the callback snapshot declared inherited `RectBounds m_visibleBounds` at line 102. Every identifier introduced by this callback was declared at that dated readback; later generated authority requires dynamic reread.

## Changed Files

The accepted implementation changed the following ordinary destinations. Hashes, byte sizes, and physical line counts are final post-validator identities; generated files changed only as validator-owned side effects and are listed in Section 31 rather than as direct edits.

| Destination | Final SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-memory/0x00621af8-0x00621b98.EditablePaperPaneVtableData.md` | `D021ED3BCE70F3347423B255DFED9FDC04C30259C8DF35CB7C0D88E6AB613569` | 14,849 / 174 |
| `by-type/by-vtable/EditablePaperPaneVtables.md` | `FA0600FF9900906D4D966D7CA01B20C581EF85C968E83AA3FF83FDFE45C8BABA` | 11,116 / 110 |
| `by-class/EditablePaperPane.md` | `79054697F243908B3EA043999797422A25D6C51F3A561DBA4474B3D9FE7EC099` | 16,019 / 182 |
| `by-memory/0x00545170-0x00545e3b.EditablePaperPane.md` | `808EEEC60B66098CEFA6B5861B69B08B317B425F6797B704626EC7F561B9CD2D` | 26,790 / 433 |
| `by-file/EditablePaperPane.md` | `9564BF9F6AA593BED12A1F3EFD8E3A67289567EF3121A11BC2DAF4E1C28BC29D` | 15,120 / 118 |
| `by-memory/0x006219e8-0x00621db8.PaneParcelReadOnlyData.md` | `BBAB35F2A969A200BCE7033EF5AB58A21CE128747D556FCB0477C5B8949669C6` | 17,547 / 133 |
| `by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md` | `9FB6597AB2ECD17B82283ABCC0C22CAF55302D4E27A077424057571112C58A40` | 6,188 / 82 |
| `by-memory/0x005128a0-0x005128fd.HandleEditablePaperPacket.md` ([UID:000536]) | `66B05E2A31805750EFB7F37E7CD7B1562E49695B097A23C6D5ECDB518E1C74AC` | 9,012 / 112 |
| `by-memory/0x00512900-0x0051295d.HandleReadOnlyPaperPacket.md` ([UID:000537]) | `7D552735129A76432FFFA3C4E5E896FC82DDD8ADE4569B3EFAB9F633D97E83F6` | 8,280 / 110 |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `E9C1135BBFDD5AB0AAB56940DB6CEB0DEFCD4D04A92FF66F0026CCB30BA71EA9` | 106,344 / 425 |
| `by-file/MapPane.md` | `C9AD3196365495C8568C12E323CECE4BFCABEA92F916C975FA65AFBF28385723` | 209,258 / 857 |
| `by-class/ScrollPane.md` | `522FD248746535289E58E4A284AEC2AA0A9F8220B892FBEFC3E88CD7B4C425CB` | 41,147 / 260 |
| `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` | `EDD081249961E95C6EF0B04D2D700D29535057F4C9CAA0E550D2D8ADB7983F06` | 7,620 / 71 |
| `by-class/ScrollablePane.md` | `11C4A10F3B2D371CF8ED29A466E5EB30E98E610939AE8213E6BA45A8E9DF521E` | 26,873 / 246 |
| `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md` | `D302CE745178C42CD3B59497C82B2CA2153C14E9D61EFACD46419E868B6357C9` | 46,222 / 349 |
| `by-file/ScrollBar.md` | `9A7DEDFA0E1D1379F8D41C7F9FAC0F8FB193364420FC80676205BAC5A2AD5DBE` | 53,508 / 296 |
| `by-class/ControlPane.md` | `204345262F181CCB94854A3EE8664052715B8AAECCD726EDD70274264FDE3E18` | 39,099 / 269 |
| `by-file/ControlPane.md` | `6AD562686470CA5C0F8DC59B3F01DEDBDDE24EFE21EC4E54DABC9576A0016393` | 27,307 / 155 |

Verify-only [UID:0002OG] `by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md` was not edited; physical identity remains SHA256 `7697F91580006A6F045E341B92B3C232A181B7809029D6135DF908039813D799`, 18,223 bytes / 170 lines. The obsolete target path `by-memory/0x00621afc-0x00621b98.EditablePaperPaneVtableData.md` is absent. This same report was edited additively in place; its self-referential final identity is returned externally after lease release and mechanical readback.

No manual coverage, generated source, tracker, audit/catalog, goal/notes, validator registry/INI/queue/lock state, IDA database, or lifecycle metadata was directly edited. B001 released each ordinary lease immediately after its edit/validator batch and releases the report lease immediately after the final write.

## Implementation Tracking Checklist

Post-implementation allocation: 52 checked / 6 unchecked. Rows are exact ledger twins after removing `Done`; unchecked C41-C46 are supervisor-owned Gate 2B.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0002NC | Correct the same-UID range/path to `[0x00621af8,0x00621b98)`, 160 bytes, SHA256 `333CABA0EA935B111622DCA266CB46993EABE7CC33EF674E29F5CA909C9DE468`. | Certain | Raw bytes, predecessor fence, primary COL. | UID0002NC metadata/title/identity | reject-stale | applied |
| [x] | C02 | 0002NC | Preserve the historical 156-byte `[0x00621afc,0x00621b98)` SHA256 `3B9E0C4EEC08188E6877D61073E2735ED36C8E5AE0F54BDEB4CEF9657F23E4EA` as corrected extraction history. | Certain | Independent old-scope hash. | UID0002NC Changes/history | historicalize | applied |
| [x] | C03 | 0002NC | Record 40 contiguous four-byte data items with zero gaps or padding inside the corrected island. | Certain | Complete item/byte inventory. | UID0002NC Range/Item Inventory | incorporate | applied |
| [x] | C04 | 0002NC | Record primary locator `[0x621af8,0x621afc)` -> `0x64db30`, SHA256 `AEF765BAEC4BC6D8A19960E93A8D8917EF8C23972D6A8DD2299187263595EEDC`. | Certain | Bytes/COL/xref. | UID0002NC Primary View | incorporate | applied |
| [x] | C05 | 0002NC | Record primary table `[0x621afc,0x621b5c)`, 24 slots, SHA256 `AB38EDEC91491E7792EA370EE3E56AEC8A26CC26DA2CC25CC58FBD455734150B`. | Certain | Raw hash and 24-cell map. | UID0002NC Primary View | incorporate | applied |
| [x] | C06 | 0002NC | Record secondary locator/table hashes, 11 slots, object offset `+0xa0`, and constructor store `0x5451bd`. | Certain | COL, bytes, xrefs, adjustor. | UID0002NC Secondary View | incorporate | applied |
| [x] | C07 | 0002NC | Record tertiary locator/table hashes, 2 slots, object offset `+0xa4`, and constructor store `0x5451c7`. | Certain | COL, bytes, xrefs, adjustor. | UID0002NC Tertiary View | incorporate | applied |
| [x] | C08 | 0002NC | Preserve the complete 24-slot primary target/name/role inventory. | Certain | Every cell and target queried. | UID0002NC Slot Inventory | incorporate | applied |
| [x] | C09 | 0002NC | Preserve the complete 11-slot secondary target/name/role inventory. | Certain | Every cell and target queried. | UID0002NC Slot Inventory | incorporate | applied |
| [x] | C10 | 0002NC | Preserve the complete 2-slot tertiary target/name/role inventory. | Certain | Every cell and target queried. | UID0002NC Slot Inventory | incorporate | applied |
| [x] | C11 | 0002NC | Record LINE001.EPD `[0x621b98,0x621bb0)`, 24 bytes, SHA256 `360677F05A5B7E5FA705801995CF7DB126D43A42CA18269252F1F5695605B3F2`, as exact successor. | Certain | Item/type/hash/nine refs. | UID0002NC Boundary | incorporate | applied |
| [x] | C12 | 0001XF | Record three COLs, CHD attributes 1, seven bases, and PMDs `0/+0xa0/+0xa4`. | Certain | Complete RTTI records. | UID0001XF RTTI/Layout | incorporate | applied |
| [x] | C13 | 000048 | Declare only direct `DialogPane` inheritance; EventHandler/TimerHandler remain inherited through Pane. | Certain | RTTI and accepted base H. | UID000048 formal H/inheritance | reject-stale | applied |
| [x] | C14 | 000048 | Correct primary `+0x48` to `OnControlCommand(int,int)`; second argument is ignored. | Certain | Base slot and target ABI/body. | UID000048 method map/formal H | reject-stale | applied |
| [x] | C15 | 000048 | Declare protected virtual `InitializePaperContent(wchar_t *)` at new primary `+0x5c`. | Very strong | Slot/body/constructor virtual call. | UID000048 method map/formal H | incorporate | applied |
| [x] | C16 | 000048 | Preserve exact `0x280` layout and typed tail at `+0x26c..+0x27c` with natural padding. | Very strong | Complete accesses/allocation/RTTI. | UID000048 Layout/formal H | incorporate | applied |
| [x] | C17 | 000048 | Represent `+0x274` as descriptive four-byte `m_reservedPaperState`, uninitialized and unreferenced by this class. | Strong | Exhaustive class access audit. | UID000048 Layout/negative evidence | incorporate | applied |
| [x] | C18 | 0001EE | Preserve constructor base `DialogPane(L"",7,true)`, initialize only mode, and dispatch mode 0/1 parsers. | Very strong | Exact constructor body. | UID0001EE formal CPP/behavior | reject-stale | applied |
| [x] | C19 | 0001EE | Preserve editable packet bytes `1/2/3/4`, BE length at `5`, text at `7`, signed tile dimensions, and parsed-then-cleared status. | Certain | Parser body. | UID0001EE parser/formal CPP | incorporate | applied |
| [x] | C20 | 0001EE | Preserve read-only packet bytes `1/2/3/4`, BE length at `5`, text at `7`, centered byte, and parsed-then-cleared status. | Certain | Parser body. | UID0001EE parser/formal CPP | incorporate | applied |
| [x] | C21 | 0001EE | Preserve exact trusted-copy/CP_ACP conversion behavior without source-added clipping or early returns. | Very strong | Parser assembly/range lowering. | UID0001EE parser/history/formal CPP | reject-stale | applied |
| [x] | C22 | 0001EE | Preserve setup geometry, signed tile arithmetic, localized ids 95/96, control limits, focus/pending state, overlay create/show, and slide-open order. | Very strong | Complete setup decompile. | UID0001EE setup/formal CPP | incorporate | applied |
| [x] | C23 | 0001EE | Center read-only text from `wcslen(text)`, not cached `m_textLength`. | Certain | Direct setup call/math. | UID0001EE setup/history | reject-stale | applied |
| [x] | C24 | 0001EE | Preserve save opcode `0x23`, paper id, BE byte length, CR-to-tab normalization, exact conversion length, and send length `+4`. | Certain | Save body/callees. | UID0001EE save/formal CPP | incorporate | applied |
| [x] | C25 | 0001EE | Remove unsupported editor-null, conversion-failure, and packet-length early-return guards while preserving compiler range-failure semantics. | Very strong | Complete binary control flow. | UID0001EE formal CPP/history | reject-invalid | applied |
| [x] | C26 | 0001EE | Preserve LINE001 frames lookup order `0,1,2,7,3,6,5,4`, 16-pixel four-edge do-loops, corners, and frame 8 inset fill. | Certain | Draw bodies and nine literal refs. | UID0001EE draw/formal CPP | incorporate | applied |
| [x] | C27 | 000048 | Use an implicit derived destructor; scalar deleting wrapper and two adjustors remain compiler output. | Certain | No class cleanup; exact wrappers. | UID000048 H/destructor disposition | reject-stale | applied |
| [x] | C28 | 0002NC | Make target compiler-generated/non-reconstructable, owner UID000048, blank emitter/H, comment-only formal CPP no-code marker. | Certain | Class declaration is source cause. | UID0002NC metadata/formal CPP | incorporate | applied |
| [x] | C29 | 0001XF | Make vtable type compiler-generated/non-reconstructable, owner UID000048, blank emitter/H, comment-only formal CPP no-code marker. | Certain | Same class-generated storage. | UID0001XF metadata/formal CPP | incorporate | applied |
| [x] | C30 | 000048 | Emit CPP preamble include plus CHILDREN and complete class H from Section 22. | Very strong | Closed source surface/layout. | UID000048 formal CPP/H | incorporate | applied |
| [x] | C31 | 0001EE | Replace stale aggregate formal CPP with the complete corrected source in Section 22. | Very strong | Complete live method audit. | UID0001EE formal CPP | incorporate | applied |
| [x] | C32 | 0000IX | Preserve `NexusTK/ui/dialogs/EditablePaperPane.cpp/.h` and add full report-level source, dependency, generated, and history detail. | Strong | Dedicated class/resources/tree. | UID0000IX file page | incorporate | applied |
| [x] | C33 | 000263 | Correct parent aggregate target range, class-source closure, and compiler/source split without emitting duplicate code. | Certain | Parent inventory and corrected child. | UID000263 parent aggregate | incorporate | applied |
| [x] | C34 | 0001EF | Preserve exact adjustor thunks `this-0xa0`/`this-0xa4` as non-emitting compiler support. | Certain | Exact 11-byte bodies/xrefs. | UID0001EF support page | already-present | already-present |
| [x] | C35 | 0002OG | Preserve PanelPane predecessor end `0x621af8` and explicit EditablePaperPane locator exclusion. | Certain | Existing exact boundary plus bytes. | UID0002OG boundary cross-reference | already-present | already-present |
| [x] | C36 | 0001AW | Resolve `[0x5128a0,0x5128fd)` as [UID:000536] file-static editable packet adapter with one direct `../ui/dialogs/EditablePaperPane.h` include declaration-covering both siblings, exact hash `7ACA6F2E453503F0EAB9296F0169A9D354AED76D606891BAB5706A8F4CA66EEF`. | Strong | Exact body/locality/mode/zero refs. | UID000536 exact child; UID0001AW aggregate | incorporate | applied |
| [x] | C37 | 0001AW | Resolve `[0x512900,0x51295d)` as [UID:000537] file-static read-only packet adapter declaration-covered by UID000536's direct include, exact hash `D11423704E51BF3D23A0C60E786B96050BA3C818EC76BE4BED7360264377D4A1`. | Strong | Exact body/locality/mode/zero refs. | UID000537 exact child; UID0001AW aggregate | incorporate | applied |
| [x] | C38 | 0000L3 | Add both retained adapters to MapPane.cpp source/file inventory without claiming active inbound routes; preserve documentation/address order while recording the dated callback generated emitter topology as a non-authoritative receipt. | Strong | Neighbor adapter precedent/locality. | UID0000L3 MapPane file | incorporate | applied |
| [x] | C39 | 0002NC | Reject `0x0045004e` as a vtable slot; retain it as UTF-16 interior-byte pollution and LodePNG code address coincidence. | Certain | Successor type/bytes and LodePNG boundary. | UID0002NC historical correction | reject-invalid | applied |
| [x] | C40 | 0001EE | Historicalize stale `OnDialogAction`, field-zeroing, clipped packet, cached-length centering, and placeholder-helper source. | Certain | Live ABI/body contradictions. | UID0001EE/UID000048/UID0000IX history | historicalize | applied |
| [ ] | C41 | 0002NC | Stage I01 Classification apply through schema-complete `set_address_comments` for the primary-locator regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/xrefs. | Supervisor Gate 2B I01 | incorporate | proposed |
| [ ] | C42 | 0002NC | Stage I02 Classification apply through schema-complete `set_address_comments` for the secondary-facet regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/xrefs. | Supervisor Gate 2B I02 | incorporate | proposed |
| [ ] | C43 | 0002NC | Stage I03 Classification apply through schema-complete `set_address_comments` for the tertiary-facet regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/xrefs. | Supervisor Gate 2B I03 | incorporate | proposed |
| [ ] | C44 | 0002NC | Stage I04 Classification apply through schema-complete `set_address_comments` for the LINE001-boundary regular address comment, with complete no-change protections and fail-closed readback. | Certain | Exact item/comments/hash/nine refs. | Supervisor Gate 2B I04 | incorporate | proposed |
| [ ] | C45 | 0001AW | Stage I05 Classification apply through schema-complete pure `rename` to `HandleEditablePaperPacket`, with exact frame/type/comment/byte/xref protection and fail-closed readback. | Strong | Complete wrapper prestate/noncollision. | Supervisor Gate 2B I05 | incorporate | proposed |
| [ ] | C46 | 0001AW | Stage I06 Classification apply through schema-complete pure `rename` to `HandleReadOnlyPaperPacket`, with exact frame/type/comment/byte/xref protection and fail-closed readback. | Strong | Complete wrapper prestate/noncollision. | Supervisor Gate 2B I06 | incorporate | proposed |
| [x] | C47 | 0002NC | Raise target `88/92 -> 94/96` after corrected range, complete inventory, no-code route, and source closure. | Very strong | All target blockers resolved. | UID0002NC metadata/score | incorporate | applied |
| [x] | C48 | 0001XF | Raise vtable type `86/90 -> 94/96` after complete RTTI/layout and compiler disposition. | Very strong | Complete three-view proof. | UID0001XF metadata/score | incorporate | applied |
| [x] | C49 | 000048 | Raise class `87/88 -> 94/94` with complete H/source route and lexical caps. | Strong | Complete class/layout/behavior. | UID000048 metadata/score | incorporate | applied |
| [x] | C50 | 0000IX | Raise file `87/88 -> 94/93` with closed contents and wrapper boundary. | Strong | Complete file inventory/source placement. | UID0000IX metadata/score | incorporate | applied |
| [x] | C51 | 0001EE | Raise method aggregate `87/88 -> 94/93` with complete corrected source. | Strong | All bodies and dependencies resolved. | UID0001EE metadata/score | incorporate | applied |
| [x] | C52 | 0001EF | Raise adjustor support `85/90 -> 92/96` while remaining non-emitting. | Very strong | Exact bytes/arithmetic/source cause. | UID0001EF metadata/score | incorporate | applied |
| [x] | C53 | 0002NC | Supply the complete current-versus-proposed manual coverage audit for UID000263, UID0001AW, UID0000L3, UID00007Q, UID0000CM, UID00042X, UID0000CF, UID0001GL, UID0000NF, UID000038, and UID0000IG, plus target/type/class/file/method/adjustor rows; supply exact assigned adapter rows UID000536/UID000537 and dependent aggregate/file replacements, with no pre-assignment token remaining. | Certain | Current manual rows physically read; absent UID00042X row checked exactly. | Section 28; exact coverage roots/positions | incorporate | applied |
| [x] | C54 | 0002NC | Scoped-validate every changed ordinary page serially, then physically reread generated EditablePaperPane, MapPane, ScrollBar, ControlPane, and GrafPort CPP/H for complete definitions/declarations, no target/class/type marker, no duplicate adapter, and declared identifiers. | Certain | Validator/emitter workflow. | Validator/generated callback plan | incorporate | applied |
| [x] | C55 | 0002NC | Preserve generated commands 24635, 24719, 24721, and 24722 and their hashes only as dated callback receipts; later generated authority requires a dynamic physical reread. | Certain | Physical generated readback. | UID0000IX/report receipts | historicalize | applied |
| [x] | C56 | 0000CF | Apply the exact Section 22 formal support chain: UID0000CM H gains inline `SetScrollStyle(unsigned char)` after `SetSkinIndex`; UID00042X documents that inline source cause; UID0000CF H gains `void SetScrollbarsVisible(bool visible);` after `SetSkinIndex`; and UID0001GL CPP replaces only the `[0x0055e840,0x0055e897)` no-code row with the complete two-child body immediately after `SetSkinIndex`, with no new include. | Very strong | Exact `0x55e840` compare/write/invalidate lowering, UID00042X raw clone, and sole target caller. | Section 22 formal UID0000CM H / UID0000CF H / UID0001GL CPP blocks; UID00042X disposition | incorporate | applied |
| [x] | C57 | 000038 | Apply the exact Section 22 UID000038 formal H insertion `void SetSelectable(bool selectable) { m_controlFlags = selectable ? 1 : 0; }` immediately after `IsSelectable()`; keep ControlPane CPP blank for this API because it is inline, add no include/storage/slot, and preserve UID0000IG ownership. | Strong | Direct child byte write, protected layout, and inline lowering. | Section 22 formal UID000038 H block; UID0000IG header route | incorporate | applied |
| [x] | C58 | 0002NC | Report has 33 exact headings, 58/58 ledger/checklist parity, only formal C++ fences, lifecycle-neutral post-implementation prose, and exactly one terminal `READY_FOR_SUPERVISOR_EXECUTE` marker. | Certain | Mechanical report audit. | Report structure | already-present | already-present |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000024880","destination_path":"executed-b-agent-research/B001/0002NC-EditablePaperPaneVtableData-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002NC-EditablePaperPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-16T06:46:15-04:00","uid":"0002NC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
