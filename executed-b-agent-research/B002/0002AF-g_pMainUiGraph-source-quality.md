** TARGET-REPORT-UID:0002AF **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002AF g_pMainMenuPane Source Quality Report

## Finalized Report / Current Recommendation

- The UID-preserving exact-storage target is `by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md`, and direct semantic parent UID0000RF is `by-global/g_pMainMenuPane.md`. `g_pMainUiGraph`, `dword_67ABA4`, and `unk_67ABA4` remain only as explicitly historical/search aliases.
- The slot is not a `MainUiGraph *`. It is the zero-initialized, externally linked `MainMenuPane *` singleton backing `Singleton<MainMenuPane>`: the exact constructor publishes the complete `MainMenuPane` pointer, both destruction forms clear it, one consumer writes the accepted `MainMenuPane::m_serverName` field at `+0xfc`, and the login-success transition invokes a `__thiscall` operation on that same object.
- Applied target metadata is `93/94`, retained `CANONICAL_OWNER:0000RF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000RF`, blank optional position, and retained `Nested:-12`. Applied UID0000RF metadata is `92/94`, owner/emitter UID0000L0 `MainMenuPane`, position `0`, and a `[[CHILDREN]]` route. The target emits the sole definition; the by-global page does not duplicate it.
- Exact function UID00019K is now the emitted source operation `MainMenuPane::InitializeMainUiGraph()` under class UID00007O/file UID0000L0 at position `120`. UID0000UV is a `91/93` non-emitting alias/index covered by UID00019K. The complete behavior-identical human-shaped Destination 6 body is installed; the broad-body blank-code decision is historical only.
- The source-bearing rename sweep is applied to Destinations 5 and 9-17, B002's non-Layer Destination 18 prose/link sweep is applied, and B001's Layer portion is independently completed and supervisor-cleared. Every accepted formal block matches this report byte-for-byte and generated translation units contain no old source identifier.
- B002 callback edits, validators, and leases are complete. B001 retained exclusive write ownership of the three Layer pages, and the supervisor has now independently cleared that external dependency from B001's exact Gate-1/Gate-2-passed implementation artifact SHA256 `FBFF647ED2578F9F04B582ED13CBEB6CEAF0AD7ADAF24C75D481142B3798E82E`: UID0004NW contains the complete indexed traversal, UID000073 declares `Layer::MarkAllPanesForDeletion`, UID0000KL records the source route, and command `000000011354` emitted the method once. No implementation obligation remains in this report. Current/future report validation, execution, movement, archive, and manual coverage state are external and not asserted.

## Supporting Research

- Historical Gate 1 artifact SHA256 `7508F1F9B7292AB676EEA6C54FACB2F6D2C204909F896139C8DCC740EBAC2F8E` was returned because it accepted UID00019K as source-authored and `92/93` while retaining a blank formal body under an invalid broad-body no-code deferral. This additive repair preserves that artifact's valid UID0002AF storage research and replaces only the rejected UID00019K disposition and its dependent recommendations with complete source, `93/94`, and closed callee/CFG/EH evidence.
- Live MCP independently supersedes the 2026-06-07 `0xffffffff` note: the mapped target bytes and value are zero. PE inspection explains why: the target lies in the virtual zero-fill tail of `.data`, beyond that section's raw-data extent, so no four image bytes encode an `0xffffffff` initializer.
- Executed B003 report `executed-b-agent-research/B003/00036Y-MainMenuPaneCore-source-quality.md` supplies the accepted `MainMenuPane` layout, `Singleton<MainMenuPane>` RTTI base at `+0xf8`, exact size `0x454`, constructor/destructor family, and class source route. Its retained `g_pMainUiGraph` use and statement that `0x004f7d10` is not a MainMenuPane child are superseded by the current target-specific receiver/field/source-order evidence.
- Executed B011 reports `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md` and `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality-2.md` preserve exact function bounds, sole caller, two layout branches, and common tail. Their evidence-time broad-body no-code conclusion and `MainUiGraph` owner/type conclusion were explicitly capped by unresolved receiver layout, callee names, and source abstractions. Current evidence resolves those caps to a complete `MainMenuPane` method; the old no-code decision remains historical only.
- Executed B008 report `executed-b-agent-research/B008/0002H8-ApplicationShutdown-empty-emitter-source-quality.md` preserves the source-level delete site. Executed B010 report `executed-b-agent-research/B010/00019J-CloseMainMenuDialogSingletons-source-quality.md` preserves the MainMenuPane destructor/cleanup route. Both require only the accepted singleton-name correction.
- Executed B004 report `executed-b-agent-research/B004/0002T5-g_pActiveBrowserWindow-source-quality.md` and current DirectX UID0000QS/UID000295 docs supply the generator-compatible exact-storage pattern: direct by-global page at position `0`, `[[CHILDREN]]`, one definition on the exact storage child, no duplicate definition.
- Supervisor-accepted B001 UID00018W implementation artifact SHA256 `FBFF647ED2578F9F04B582ED13CBEB6CEAF0AD7ADAF24C75D481142B3798E82E` supplies the independently verified Layer dependency. Its implementation is now visible read-only under `executed-b-agent-research/B001/00018W-Layer-source-quality.md`; lifecycle-added history can change the archived file hash without changing the accepted implementation artifact. UID0004NW/UID000073/UID0000KL and supervisor commands `000000011303`-`000000011354` are exact external completion proof.
- Executed dialog/consumer reports remain support evidence rather than ownership evidence. Their body behavior remains accepted; only the root-parent singleton spelling changes.
- The report's authoring location is B002's assigned research directory. Current or future report count, validation, execution, movement, and archive state are external validator/supervisor-owned and are not asserted.

## Target

- Target UID: `0002AF`.
- Evidence-time path: `by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md`.
- Recommended UID-preserving path: `by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md`.
- Report authoring path: `tools/leaser/Agents/Agent-B002/research/0002AF-g_pMainUiGraph-source-quality.md`.
- Exact range: half-open `[0x0067aba4,0x0067aba8)`, four bytes.
- Queue state at assignment time: `86/90`, reconstructable, no direct report.

## Current Target State

- UID0002AF is applied at `93/94` with retained owner/emitter/reconstructable/blank position/`Nested:-12`, exact zero-fill/range/lifecycle/source evidence, and the sole `MainMenuPane *g_pMainMenuPane = NULL;` definition.
- UID0000RF is applied at `92/94`, owner/emitter UID0000L0, position `0`, and `[[CHILDREN]]`. UID0000L0 is `92/92`; UID00007O is `92/94`; UID00019K is `93/94` under UID00007O at position `120`; UID0000UV is `91/93`, owner UID00019K, non-reconstructable, and non-emitting; UID0000L1 remains `88/88` and no longer owns the target/global/method.
- Historical `0xffffffff`, `g_pMainUiGraph`, root-graph type, UID0000L1 ownership, and broad-body blank-C++ conclusions remain labeled provenance only.
- Waited generated command `000000011217` produced `NexusTK/login/MainMenuPane.cpp` SHA256 `8ED21B041ABF9706C845BABB0FBE4DD49FE25F8BCFBEE127726BA1ADB70328EB` with exactly one target definition, one global/class/method route, and zero old-name or Empty Emitter Marker hits. Its command-time `NexusTK/ui/MainUiGraph.cpp` SHA256 was `E69447E3B99E42845B21603E89E841F4243B0F73FC8D4FF6757B9B625AC9AFC2` with zero UID0002AF/UID0000RF/old/new singleton hits. An initial read-only handoff observed MainUiGraph.cpp SHA256 `E1A2CB0B4229F12C79E5F9F78F9D05099EF22B23FBB9DD5818D3EC19D63DDF85`. The clearance-time read-only snapshot at `2026-07-14T10:29:51.5328262-04:00` observed MainMenuPane.cpp SHA256 `5225AAB7A89DEF9CCD4DC7FDBAE946BD34858F9130C6E3D9201FA954859A3536` and MainUiGraph.cpp SHA256 `EB16EE28DFFA92FAE51DA250BADAC64F83335D8AA6898FCD25BBBF2372708FA9`; concurrent validator-owned refreshes changed hashes but every snapshot retained one target definition/method, zero old-name/target-empty hits, and zero MainUiGraph target-route hits.
- All B002 leases are released. The Layer pages remained excluded from B002 write scope and were completed independently under B001; supervisor clearance verifies same-or-greater UID0004NW/UID000073/UID0000KL incorporation and closes the dependency without a B002 Layer edit.

## Executive Recommendation

- `g_pMainMenuPane` is applied as the highest-probability human-written project name and `MainMenuPane *` as the concrete type. `g_pMainUiGraph` is rejected as a current source-facing name because it confuses the transition operation with the receiver object.
- Preserve UID0000RF as the semantic symbol owner and UID0002AF as its exact storage child. Move UID0000RF's file owner/emitter from UID0000L1 to UID0000L0 and set UID0000RF position `0`.
- One definition now emits from UID0002AF through UID0000RF. UID0000RF contains only the child insertion marker. Intended header reconstruction remains an external declaration in `MainMenuPane.h`; by-file pages received prose only and no RECONSTRUCTION_CPP metadata.
- `InitializeMainUiGraph()` is in the `MainMenuPane` declaration, exact UID00019K emits Destination 6 through UID00007O at position `120`, and UID0000UV is its non-emitting alias.
- Every source-bearing formal body in Destinations 5 and 9-17 uses `g_pMainMenuPane`; report-to-destination block comparison is exact.
- Old `0xffffffff`, root-graph, and UID0000L1 ownership conclusions are preserved only as explicitly superseded history.

## Supervisor Active Recheck

- Duplicate-report check at evidence time found no active B001-B005 direct report, no active direct-target lease, no Older-Research or SpecialReports direct report, and no archived direct report for UID0002AF.
- The central executed root contains indirect and support reports but no dedicated UID0002AF report. B011 UID00019K is an executed support report, not a duplicate target report.
- Split check: the target is already the exact four-byte pointer slot. No new UID or child is required.
- Source-bearing check: all formal pages containing the old identifier are included below. Non-emitting prose pages are separately listed so no hidden accepted-name contradiction remains.
- Collision check: active B001-B005 goals/research and current lease text contain no UID0002AF, `0x0067aba4`, `g_pMainUiGraph`, or `g_pMainMenuPane` ownership hit at evidence time.
- Callback collision history: B001 owned active UID00018W Layer research and leased `by-memory/0x004f0480-0x004f1bf6.Layer.md` while B002 performed this callback, so B002 did not lease or edit that aggregate, `by-class/Layer.md`, or `by-file/Layer.md`. The supervisor later passed B001 Gate 1 and Gate 2 for exact artifact SHA256 `FBFF647ED2578F9F04B582ED13CBEB6CEAF0AD7ADAF24C75D481142B3798E82E` and independently verified the accepted `0x004f0b40` full-list body/declaration/source route. The collision is resolved without overlapping writes.

## Inference Research Guidance Check

- Exact facts are limited to bytes, PE section geometry, xrefs, instructions, calling convention, object offsets, RTTI, allocation size, constructor/destructor writes, callers, and generated/docs state.
- `g_pMainMenuPane` is explicitly labeled a high-probability source name, not a recovered symbol. The active IDB has no global/name entity at the slot.
- `MainMenuPane *` is behavior- and layout-proven: it is not inferred only from adjacency or old documentation.
- External linkage is inferred from cross-module uses; `static` is rejected because source-bearing consumers span Application, login, dialog, and UI source roots.
- Explicit `= NULL` is a period/project-style source choice. The binary proves zero initialization but cannot distinguish explicit null initialization from implicit static zero initialization; this caps confidence below `95`.
- The source recommendation contains no raw `dword_` name, decompiler integer type, address literal, vtable syntax, manual Singleton base write, destructor-wrapper code, or relocation scaffolding.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Resolution | Confidence classification |
| --- | --- | --- | --- |
| Initial value | MCP bytes/value, PE raw/virtual section geometry | Loader-zeroed BSS/static storage; old `0xffffffff` is stale | Exact |
| Concrete type | MainMenuPane constructor writes, destructor clears, `+0xfc` `wcscpy_s`, UID00007O layout, 0x454 allocation | `MainMenuPane *` | Exact behavior/layout |
| Source name | Project `g_p<Class>` singleton style, neighboring global reports, constructor/destructor family, cross-module consumers | `g_pMainMenuPane` | High-probability inferred spelling |
| Old name | No `MainUiGraph` object allocation/layout/vtable; target exists before login and is queued for teardown by transition | `g_pMainUiGraph` rejected as source-facing; retained historical alias | Strong rejection |
| Linkage | Uses in Application, login dialogs, Employee UI, and later panes | external, not file-static | Strong inference |
| Initializer spelling | zero-filled static slot; project singleton definitions often use `= NULL` | emit `= NULL`; implicit-zero alternative remains equivalent | Period-plausible inference |
| Direct owner | by-global symbol versus exact storage versus file/class | UID0000RF owns symbol semantics; UID0002AF owns storage/definition; UID0000L0 owns source file | Strong |
| Transition operation | sole caller loads slot to ECX; callee is `__thiscall`; `this+126` wchar access equals byte `+0xfc`; common tail queues `this` | `MainMenuPane::InitializeMainUiGraph()` | Very strong |
| Transition source body | complete 3,611 bytes, 139 attributed blocks, 39 callees, both construction branches, exact common tail, caller return use, and all external funclets | complete Destination 6 human-written method; prior broad-body no-code disposition rejected | Very strong |
| Layer helper dependency | fresh `0x004f0b40` decompile/disassembly, child-list count/index traversal, node/pane null checks, and sole Pane-side `MarkForDeletion` effect | descriptive `Layer::MarkAllPanesForDeletion`; header/declaration prose support only, no duplicate body | Strong inferred spelling / exact behavior |
| UID0000UV | duplicate item view of exact UID00019K | non-emitting alias/index covered by UID00019K | Strong |
| Target nesting | coverage context before/after browser aggregate and URL state | retain `Nested:-12` to close prior aggregate context; target remains independent | Strong documentation structure |
| Relocation | PE Base Relocation directory absent; target zero-fill; 31 fixed-image absolute operand hits | no target relocation or pointer initializer | Exact |
| Compiler output | null-adjusted Singleton publish, scalar deleting destructor, vptr/member/base teardown | document but do not handwrite | Exact disposition |

Ranked source-name alternatives:

1. `g_pMainMenuPane`: accepted. It names the exact concrete object and matches project pointer-global style.
2. `g_pMainUiGraph`: rejected as current source-facing name. It describes what a method builds, not what the pointer owns.
3. `g_pRootPane` / `g_pMainPane`: rejected as too generic and weaker than concrete class evidence.
4. `s_pMainMenuPane`: rejected because cross-translation-unit consumers require external visibility.
5. `Singleton<MainMenuPane>::s_pInstance`: possible lost original implementation detail, but rejected as the current project source form because accepted project singleton storage is modeled as `g_p<Class>` globals and no static-member symbol/type survives.

## Evidence Standards Used

- Primary: fresh live IDA MCP session/list/health, bounded lookup and bytes, global values, xrefs, decompilation, disassembly, function lookup/callers, type inference, entity queries, raw byte-pattern search, and binary survey.
- Supplemental primary: structured PE header/section/data-directory parsing and SHA256 over the identical executable image. This explains mapped zero-fill but does not replace MCP.
- Secondary: current target/support by-* pages, by-structure/by-global/by-memory/by-file guidance, generated C++ read-only, manual coverage rows, active goals/leases read-only, and matching executed reports.
- Negative: no target function, no current target name/global entity, no raw-backed target bytes, no relocation directory, no data/table xref, no pointer/RVA table route, no `MainUiGraph` object construction or vtable, and no defensible static linkage.

## Evidence Checked

Mandatory MCP evidence-time state:

- Fresh `idb_list` after the supervisor restart returned one active adopted worker session: database `1feab207`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-07-14T07:48:17.357844`, `is_analyzing:false`, PID/worker PID `20008`.
- `server_health(database=1feab207)` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. This is an evidence-collection-time observation, not an assertion of future availability.
- Required bounded target checks succeeded: `lookup_funcs(0x0067aba4)` returned `Not a function`; `get_bytes(0x0067aba4,4)` returned `00 00 00 00`.
- Additional bounded calls: `get_bytes` over `0x0067ab90-0x0067abb0`; `get_global_value` at `0x0067aba0`, `0x0067aba4`, `0x0067aba8`; `xref_query` for all target refs; `entity_query` for globals/names in `0x0067ab90-0x0067abb0`; `infer_types`; `survey_binary(minimal)`; `find_bytes A4 AB 67 00`; `lookup_funcs`, `xrefs_to`, `decompile`, `disasm`, and caller checks for every writer/clear and the 26 modeled consumers.
- UID00019K repair calls: complete `get_bytes(0x004f7d10,3611)` plus in-memory SHA256, full `decompile`, full `callees(limit=100)`, and `basic_blocks(max_blocks=1000)`; bounded `decompile`/`disasm`/`callees` for Layer helper `0x004f0b40`. Final recheck returned the same 3,611-byte hash, 39 callees, 139 blocks, and exact helper loop behavior recorded below.
- Final bounded MCP calls during evidence collection remained successful. No MCP mutation, process management, IDB save, rename, type application, or IDA write was performed.

Binary/PE checks:

- Executable SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`; both the MCP input copy and `E:\NTK\Resources\NexusTK\NexusTK.exe` hash identically.
- Target mapped-byte SHA256: `df3f619804a92fdb4057192dc43dd748ea778adc52bc498ce80524c014b81119` for four zero bytes.
- PE `.data`: RVA `0x26d000`, virtual size `0x2fe24`, raw size `0xd800`, raw end RVA `0x27a800`. Target RVA is `0x27aba4`, exactly `0x3a4` bytes into the virtual zero-fill tail and naturally four-byte aligned.
- The PE Base Relocation data directory is absent (`RVA 0`, size `0`). The target has no relocation. All 31 references are fixed-image code operands found by MCP and the exact absolute-VA byte pattern.

Documentation/source inputs checked:

- UID0002AF, UID0000RF, UID0000L0, UID00007O, UID0004LY, UID0004LZ, UID00019K, UID0000UV, UID0000L1, UID0002H8, UID00019J, all ten old-name formal emitters, MainMenuPane vtable/layout, both constructor callers, exact adjacent storage pages, by-global/by-memory/by-file guidance, generated MainMenuPane/MainUiGraph/Application/dialog sources, and all affected manual coverage rows.

Exact report-root search terms:

- `UID:0002AF`, `UID0002AF`, `0x0067aba4`, `0x0067aba8`, `g_pMainUiGraph`, `g_pMainMenuPane`, `unk_67ABA4`, `dword_67ABA4`, `UID0000RF`, `UID0000L0`, `UID0000L1`, `UID00019K`, `UID0000UV`, `MainMenuPane`, and `InitializeMainUiGraph`.

Exact roots searched and outcomes at the pre-report snapshot:

- Active roots `tools/leaser/Agents/Agent-B001/research`, `Agent-B002/research`, `Agent-B003/research`, `Agent-B004/research`, and `Agent-B005/research`: no match in any root.
- Central executed root `executed-b-agent-research`: no dedicated UID0002AF report; 48 support/consumer matches. Decisive artifacts opened were B003 `00036Y-MainMenuPaneCore`, B011 both `00019K-InitializeMainUiGraph` artifacts, B008 `0002H8-ApplicationShutdown`, B010 `00019J-CloseMainMenuDialogSingletons`, and B004 `0002T5-g_pActiveBrowserWindow`.
- Direct affected-source artifacts opened were B002 `0002HE-EmployeeItemPropertyDialogPaneConstructor`, B004 `0002HH-EmployeeQuantityInputDialogPaneConstructor`, B005 `0004GL-NewUserMiscDialogPaneConstructor`, B014 `00019Z-StaffsDialogPaneCore` and `0001A2-BackStoryDialogPaneCore`, B003 `0001A3-new-history-dialog-pane-core` and `00022Y-MainMenuAnsiTextDialogPacketHelpers`, B008 `0001J7-ForcedInformMessageDialogCore`, and B001 `00019L-EnsureLoginDialogPane`.
- Remaining central executed matches were classified as indirect consumer/dependency/history: B003 `00016Z`, `0001IG`, `0002BD`, `0002CP...`, `0003V1`; B001 `000105...`, `000210`, `000244`, `0001AK`, `0002EO...`, `0002F7`; B002 `00019X`, `0001NR`, `0002EW`, `0002I7...`, `0002SW`; B009 `00039S`; B002 `0002HE`; B014 `0002WH`; B010 `0000LE`, `0000P9`, `0000Z6`, `0002AD`; B011 `0001KF`; B006 `000214`; B013 `00019T`; B007 `0002VO`; B004 `00001N`, `000214`, `00033F`; B005 `0001AH...`, `0002Q5`, `00030M`; and the already listed dialog artifacts. They preserve consumer behavior or nearby-global history but do not own UID0002AF.
- Legacy roots `tools/leaser/Agents/Older-Research`, `archived/b-agent-reports-20260623`, and `archived/duplicate-loose-b-agent-reports`: no match.
- `tools/leaser/Agents/SpecialReports`: no match.

## Claim And Incorporation Ledger

| Claim ID | Claim | Destination / operation proof | Action | Verification state |
| --- | --- | --- | --- | --- |
| C01 | Exact range is four-byte `[0x0067aba4,0x0067aba8)` | Destination 1 applied range/storage text | incorporate | applied |
| C02 | Current mapped bytes/value are zero; old `ffffffff` is stale | Destinations 1-3 applied evidence/history | historicalize | applied |
| C03 | Target is naturally aligned `.data` virtual zero-fill | Destination 1 applied storage detail | incorporate | applied |
| C04 | No target relocation; PE has no relocation directory | Destination 1 applied binary detail | incorporate | applied |
| C05 | Adjacent predecessor/successor are separate exact storage | Destination 1 plus UID0002AE applied boundary detail | incorporate | applied |
| C06 | Exactly 31 refs, 26 modeled functions plus one unmodeled fragment | Destination 1 applied xref inventory | incorporate | applied |
| C07 | Constructor publishes complete MainMenuPane pointer | Destinations 1, 3, 5 applied | incorporate | applied |
| C08 | Ordinary/scalar destruction clears the slot | Destinations 1, 3, 6 and UID00019J prose applied | incorporate | applied |
| C09 | Shutdown deletes through primary virtual destructor | Destinations 1 and 9 applied; block exact | incorporate | applied |
| C10 | Concrete pointee type is MainMenuPane | Destinations 1-8 applied | incorporate | applied |
| C11 | `+0xfc` write is `m_serverName[128]` | UID0002Q4 and Destinations 1, 3, 6-8 applied | incorporate | applied |
| C12 | Accepted source name is g_pMainMenuPane | All B002 destinations applied; externally owned Layer destinations independently completed and cleared as documented below | reject-stale | applied |
| C13 | Old g_pMainUiGraph remains historical/search alias only | Affected current prose/links synchronized; residue audit found only explicit history | historicalize | applied |
| C14 | Global requires external linkage | Destinations 1-3 applied source/header placement | incorporate | applied |
| C15 | Explicit NULL is period/project plausible but not byte-distinguishable | Destinations 1-2 applied confidence rationale | incorporate | applied |
| C16 | UID0000RF remains direct semantic owner | Target metadata retained and final generated route verified | already-present | already-present |
| C17 | UID0002AF emits sole definition through UID0000RF | Exact Destination 1-2 route; generated definition count `1` | incorporate | applied |
| C18 | UID0000RF moves to MainMenuPane file UID0000L0 at position 0 | UID-preserving rename/metadata applied and generated order verified | incorporate | applied |
| C19 | Target retains blank position and Nested:-12 | Final target readback | already-present | already-present |
| C20 | UID00019K is MainMenuPane instance operation | Destinations 4, 6-8 applied; generated method count `1` | reject-stale | applied |
| C21 | UID00019K emits the complete two-layout human-written method; the prior broad-body no-code decision is superseded | Destination 6 is applied/exact; external UID0004NW has the complete indexed traversal, UID000073 declares the method, UID0000KL records the source route, B001 artifact `FBFF647E...E82E` passed both gates, and command `000000011354` emitted it once | incorporate | applied |
| C22 | UID0000UV is non-emitting alias covered by exact UID00019K | Destination 7 metadata/prose applied; generated duplicate count `0` | incorporate | applied |
| C23 | UID0000L1 no longer owns target/global/transition | Destination 8 applied; MainUiGraph generated UID counts `0` | reject-stale | applied |
| C24 | Every current formal old-name use must rename atomically | Destinations 5 and 9-17 exact-block comparison passed | incorporate | applied |
| C25 | Compiler Singleton adjustment/wrappers are not handwritten | Applied prose/formal exclusion; generated scalar/vtable marker counts `0` | reject-invalid | applied |
| C26 | No split/new UID is needed | UID-preserving paths retained; no child created | not-applicable | excluded-with-reason |
| C27 | Target/global score improves beyond 86/90 and 86/88 | Applied `93/94` and `92/94` metadata | incorporate | applied |
| C28 | Manual coverage is supervisor-owned | Inspected exact text retained below; no manual coverage edit authorized | already-present | excluded-with-reason |
| C29 | Generated output must contain one definition and zero old names/target empty marker | Waited command `000000011217` and exact counts/hashes below | incorporate | applied |
| C30 | Callback restrictions remain intact | Only accepted ordinary pages/report changed; no manual generated/coverage/lifecycle/IDA write; all leases released | already-present | applied |

## Positive Evidence Summary

- Constructor `0x004f6700` is exact `MainMenuPane::MainMenuPane(bool)`, allocation size `0x454`, RTTI `Singleton<MainMenuPane>` base at `+0xf8`, and complete pointer publication to `0x0067aba4`.
- Ordinary destructor `0x004f6910` and scalar deleting destructor `0x00502850` clear the exact slot; compact helper `0x005023d0` is another compiler/lifecycle clear.
- Login request path `0x004fad00` writes `wcscpy_s(slot+0xfc, 0x80, account)`, exactly matching accepted `wchar_t m_serverName[128]` at MainMenuPane `+0xfc`.
- Login success path loads the slot to ECX before the sole `0x004f7d10` call. The callee is `__thiscall`, reads `this+126` in wchar units (byte `+0xfc`), and queues `this` for deferred cleanup after constructing the in-game graph.
- Two independent construction routes allocate `0x454` and call `MainMenuPane(bool)` with `false` (map exit) and `true` (terminal transition).
- Remaining consumers use the object as the pre-login root/show parent or boundary fallback, consistent with MainMenuPane lifetime and inconsistent with a persistent post-login MainUiGraph object.

## IDA MCP Facts

| Fact | Current evidence-time result |
| --- | --- |
| Target lookup | not a function |
| Target bytes/value | `00 00 00 00` / `0x0` |
| Target current name/global entity | none |
| IDA inferred type | raw existing `int`; rejected as untyped storage |
| Section | writable `.data`, IDA segment `0x0066d000-0x0069d000` |
| Raw backing | none at target; target is `0x3a4` bytes beyond `.data` raw end |
| Xrefs | 31 data-operand refs to target |
| Modeled functions | 26, plus unmodeled linear fragment at `0x0046cf80` |
| Absolute target byte-pattern hits | 31 |
| Target data/table refs | none |
| Constructor callers | `0x00504b35`, `0x0058b3de` |
| MainMenuPane allocation | `1108` decimal / `0x454` |
| Transition caller | only `0x004fac9b`, receiver load at `0x004fac95` |
| Transition receiver field | `this + 126` wchar units = byte `+0xfc` |
| Relocations | PE relocation directory absent; no target relocation |

UID00019K complete method resolution:

- Fresh `get_bytes(0x004f7d10,3611)` returned the complete in-range body with SHA256 `ed835eca4e3dbab9330dc9025ac1db1e46fa784dab942c34a4da5d854bbe7359`; first 16 bytes are `55 8b ec 6a ff 68 f1 14 60 00 64 a1 00 00 00 00`, and the last 16 are `5e 5b 8b 4d f0 33 cd e8 08 ec 0c 00 8b e5 5d c3`.
- `basic_blocks` returns 139 attributed blocks. The exact disposition is 104 blocks in `[0x004f7d10,0x004f8b2b)`, 33 constructor-unwind cleanup funclets in `[0x00601323,0x006014f1)`, one C++ frame-handler block in `[0x006014f1,0x00601519)`, and one synthetic zero-size terminal node at the `__CxxFrameHandler3` target. The apparent breadth is compiler allocation/EH expansion around a source CFG with two layout branches, a mode-sensitive tail allocation, and optional deletes.
- The sole caller at `0x004fac9b` loads `g_pMainMenuPane` into ECX and ignores EAX. The decompiler's `int` result is the last `g_pApplication` load, not a source return; the source contract is `void MainMenuPane::InitializeMainUiGraph()`.
- The EPF/current branch source order is exact: clear existing overlay-layer panes; construct `BackPane(L"FRAME.EPF")`; construct the 17-by-15 MapPane; construct ChattingBackPane, ChattingPane, ChattingModifyHeightPane and apply persisted line count; construct both general-purpose panels; build the above-frame border; construct MapNamePane, MiniMapButtonPane, TabPane, HourPane, ChattingVarietyPane, ChattingHandlePane, MenuVarietyPane, UserStatusPane, UserStatusPane2, SoundStatusPane, and ParcelIconPane; publish the local-player name; replace UserPane; then perform the ACP name conversion and packet-transform-key update.
- The legacy branch source order is exact: construct `BackPane(L"FRAME.EPD")`; construct the 17-by-15 MapPane at legacy offsets; build the above-frame border; construct MapNamePane, IconsPane, HourPane, ConnStatusPane, GeneralPurposePanel, OldSystemMessagePane, ChattingPane, OldUserStatusPane, SoundStatusPane, ParcelIconPane, and the replacement UserPane. The `InitRectBounds(244,374,263,388)` call after ConnStatusPane construction and the zero-bounds call before UserPane ordering are retained because the machine body executes them even though no later instruction consumes the resulting local rectangle.
- Both branches join in this exact order: `LoadUserProfileData()`, `g_pScreenPane->EnablePresentationMode()`, deferred queueing of the retiring MainMenuPane through `g_pApplicationCleanupQueue`, deletion of an optional `g_pScreenDimmer`, a fresh `g_useEpfAssets != 1` check and legacy-only InterfaceEfxMgr construction, `g_pInputMan->TrackInputTarget(0,false)`, `g_pSoundManager->RestartMusic(3000)`, and `g_pApplication->m_inMapSession = true`.
- Source-facing state is fully typed: `m_serverName[128]` at `MainMenuPane+0xfc`; `g_mapTilePixelWidth/Height`; `g_screenWidth/Height`; `g_pConfig->m_chatVisibleLineCount`; `MainUiLayerSlots` effect/root/overlay Layer pointers; `g_pUserPane`; `g_pScreenPane`; `g_pApplicationCleanupQueue`; `g_pScreenDimmer`; `g_pInputMan`; `g_pSoundManager`; and `g_pApplication`. `BackPane::GetBounds` is the public source expression that can inline to the observed `m_frameWidth/+0x120` and `m_frameHeight/+0x124` reads.
- All 39 direct callees are resolved. Source dependencies are `Layer::MarkAllPanesForDeletion` (`0x004f0b40`, inferred exact spelling from full-list iteration plus `Pane::MarkForDeletion`), BackPane, MapPane, ChattingBackPane, ChattingPane, ChattingModifyHeightPane, GeneralPurposePanel, GeneralPurposePanel2, MapNamePane, MiniMapButtonPane, TabPane, HourPane, ChattingVarietyPane, ChattingHandlePane, MenuVarietyPane, UserStatusPane, UserStatusPane2, SoundStatusPane, ParcelIconPane, UserPane, IconsPane, ConnStatusPane, OldSystemMessagePane, OldUserStatusPane, and InterfaceEfxMgr constructors; `InitRectBounds`; `ChattingModifyHeightPane::SetLineCount`; `BuildAboveFrameBorder`; `SetLocalPlayerName`; `WideCharToMultiByte`; `BuildPacketTransformKeyText`; `LoadUserProfileData`; `ScreenPane::EnablePresentationMode`; `BlackHole::QueuePaneForDeferredDeletion`; `InputMan::TrackInputTarget`; and `SoundManager::RestartMusic`.
- Fresh bounded MCP decompilation/disassembly of `0x004f0b40-0x004f0b79` proves the Layer dependency's complete behavior: read the owned child-list count, retrieve every node by index, skip null/sentinel nodes and null pane pointers, and call `Pane::MarkForDeletion()` on each surviving pane. `MarkAllPanesForDeletion` is the highest-probability descriptive member spelling. B001 implemented that exact source operation on UID0004NW and its declaration on UID000073, with UID0000KL retaining the source route; supervisor Gate 1/Gate 2 and generated command `000000011354` independently cleared the incorporation. UID00019K remains the sole MainMenuPane method-body destination. Exact original spelling remains a confidence cap, not a behavior or C++ blocker.
- The remaining direct callee entries are compiler/source-lowering support: global `operator new` at `0x004f4aa0`, `PoolAllocator::Allocate` at `0x004b1400` reached through UserPane's accepted pool allocation policy, and `__security_check_cookie` at `0x005c772f`. Indirect Pane virtual calls are source `AddToLayer`, `SetPaneOrder`, and virtual `delete`; they are not unresolved callees. The 31 global-delete unwind funclets call `operator delete`; the two UserPane funclets at `0x0060141f` and `0x006014d5` call `0x00502420`, the accepted constructor-failure pool-return wrapper. No EH funclet, allocation null branch, vtable dispatch scaffold, stack cookie, or decompiler temporary belongs in the formal source body.

## Function / Child Inventory

| UID/address | Current / evidence-time classification | Applied relationship / status |
| --- | --- | --- |
| UID0002AF `0x0067aba4-0x0067aba8` | exact global storage; evidence-time graph name and blank body are superseded | applied as `g_pMainMenuPane`; sole definition child of UID0000RF, `93/94` |
| UID0000RF | direct global symbol; evidence-time UID0000L1 ownership and blank route are superseded | applied as `g_pMainMenuPane`; owner/emitter UID0000L0; position 0; `[[CHILDREN]]`, `92/94` |
| UID00007O | exact MainMenuPane class | transition declaration applied; existing layout/method children retained, `92/94` |
| UID0004LY `0x004f6700-0x004f6904` | constructor | accepted body retained; singleton use synchronized to `g_pMainMenuPane` |
| UID0004LZ `0x004f6910-0x004f6998` | ordinary destructor | verify-only; compiler Singleton clear remains implicit |
| `0x005023d0-0x005023db` | tiny clear helper | compiler/lifecycle support; no handwritten child needed |
| `0x00502850-0x00502919` | scalar deleting destructor | compiler wrapper; no handwritten body |
| UID00019K `0x004f7d10-0x004f8b2b` modeled | MainMenuPane instance operation; evidence-time MainUiGraph free-function route and blank body are superseded | applied under class owner/emitter UID00007O with complete formal body at position 120, `93/94`; external Layer declaration/body/source route independently completed and cleared |
| `0x00601323-0x006014f1` | 33 out-of-line construction-unwind funclets attributed to UID00019K | compiler-generated cleanup: 31 global-delete releases plus two UserPane pool-return wrappers; no handwritten child |
| `0x006014f1-0x00601519` | UID00019K C++ frame handler/security-cookie bridge | compiler-generated `__CxxFrameHandler3`/cookie glue; no handwritten child |
| UID0000UV | duplicate by-item view | applied as `91/93` non-emitting alias/index covered by UID00019K |
| UID0000L1 | MainUiGraph support file | layer/bootstrap documentation retained; target/global/function ownership removed, score retained `88/88` |

## Direct Xref / Caller Inventory

| Function / sites | Count | Exact target use and source disposition |
| --- | ---: | --- |
| `0x0046cd00` / `0x0046cddf`; fragment `0x0046cf80` | 2 | WndProc `WM_NCPAINT` fallback chooses active root or MainMenuPane and calls virtual `+0x20`; fragment is same source control flow missed by function model |
| Application shutdown `0x004f6490` / `0x004f6526` | 1 | null-check then virtual deleting destruction flag `1`; source `delete` |
| MainMenuPane ctor `0x004f6700` / `0x004f6751,0x004f6758` | 2 | Singleton complete-pointer publish and compiler null-adjust fallback |
| MainMenuPane dtor `0x004f6910` / `0x004f6979` | 1 | Singleton clear |
| NewUserDialog ctor `0x004f9d30` / `0x004fa076` | 1 | parent/show root |
| LoginDialog ctor `0x004fa7a0` / `0x004faa9a` | 1 | parent/show root |
| Login success `0x004fab10` / `0x004fac95` | 1 | loads receiver before sole transition call |
| Login request `0x004fad00` / `0x004fadc6` | 1 | writes MainMenuPane server-name field at `+0xfc` |
| Login pointer handler `0x004fae90` / `0x004faf76` | 1 | root event/hit-test relay |
| NewUserMisc ctor `0x004fb630` / `0x004fbf9b` | 1 | parent/show root |
| ChangePassword ctor `0x004fdd40` / `0x004fe42d` | 1 | parent/show root |
| Staffs ctor `0x004ffaa0` / `0x004ffcea` | 1 | parent/show root |
| BackStory ctor `0x00500090` / `0x005003b1` | 1 | parent/show root |
| NewHistory ctor `0x00500410` / `0x00500589` | 1 | parent/show root |
| clear helper `0x005023d0` | 1 | compiler/lifecycle null store |
| scalar destructor `0x00502850` / `0x005028c0` | 1 | duplicate compiler clear |
| ANSI URL alert helper `0x00502e30` / `0x00502f8a,0x0050302a` | 2 | parent argument for subtype 1/2 alert construction |
| `0x0052b9f0` / `0x0052bb8d` | 1 | parent to `0xfc`-byte pane construction |
| `0x0052c360` / `0x0052cd1c` | 1 | dialog parent/show consumer |
| `0x0052dd30` / `0x0052e6be` | 1 | dialog parent/show consumer |
| `0x00547980` / `0x005479d5,0x00547a26` | 2 | parent to `0x270` pane and root update/invalidate consumer |
| `0x00548f80` / `0x00548fce,0x00548ff7` | 2 | same parent/update family |
| `0x00554210` / `0x005543db` | 1 | parent to `0x270` pane construction |
| `0x00574340` / `0x005743fb` | 1 | parent to `0xfc` pane construction |
| ForcedInform ordinary dtor `0x00588080` / `0x005880d1` | 1 | null guard before restoring login dialog |
| ForcedInform scalar dtor `0x0058abf0` / `0x0058ac48` | 1 | compiler-wrapper duplicate guard |

All 31 references are accounted for. There are no additional data/table references and no unclassified write outside the MainMenuPane lifecycle family.

## Documentation Evidence And IDA Status

- Evidence-time UID0002AF/UID0000RF docs preserved useful xref counts while their initializer, concrete type, name, owner file, and blank-emitter state were stale. Validators `000000011103` and `000000011107` applied the UID-preserving target/global renames, exact metadata, sole definition child, and parent `[[CHILDREN]]` route.
- UID00007O, UID0004LY, and UID0004LZ supplied the accepted exact layout and lifecycle. Validators `000000011111` and `000000011118` applied the transition declaration and constructor spelling synchronization; UID0004LZ remained verify-only because its ordinary-destructor source was already correct.
- UID00019K/UID0000UV were technically strong evidence-time records whose owner/type and blank-body wording were stale because B011 left receiver layout, callee names, and source shape open. Validators `000000011122`, `000000011212`, and `000000011123` applied the complete MainMenuPane source route/body and non-emitting alias disposition. Supervisor clearance of B001 artifact `FBFF647E...E82E`, UID0004NW/UID000073/UID0000KL readback, and command `000000011354` closes the final external declaration/body route, so C21 is applied.
- UID0000L1 remains a valid MainUiGraph/layer reconstruction root, but target/global/function ownership was removed by validator `000000011129`; it is not the declaration owner for the pre-login MainMenuPane singleton or the source owner for the receiver-bound transition method.
- Final waited validator `000000011217` generated `MainMenuPane.cpp` SHA256 `8ED21B041ABF9706C845BABB0FBE4DD49FE25F8BCFBEE127726BA1ADB70328EB` with one target definition, one class, one declaration, one UID00019K method, and no target/method empty marker or old identifier. Its command-time `MainUiGraph.cpp` SHA256 was `E69447E3B99E42845B21603E89E841F4243B0F73FC8D4FF6757B9B625AC9AFC2` with zero UID0002AF/UID0000RF/old/new singleton hits. Initial and clearance-time read-only snapshots observed later validator-owned hashes `E1A2CB0B...3DDF85` then `EB16EE28...8FA9` for MainUiGraph.cpp and `5225AAB7...A3536` for MainMenuPane.cpp; all semantic counts remained identical. These are time-scoped callback verification observations, not assertions of hash stability or external lifecycle state.
- Existing warnings in BackStory/NewHistory/Staffs docs not to call `0x0069b36c` `g_pMainMenuPane` remain valid. The correction applies to `0x0067aba4`; `0x0069b36c` remains a separate main-UI layer/context slot.

## Ranked Ownership Analysis

1. UID0000RF `g_pMainMenuPane`: accepted direct semantic owner of the process-wide symbol. It separates symbol semantics from exact storage.
2. UID0002AF: accepted exact storage and source-definition child. It does not directly own the source file.
3. UID0000L0 `MainMenuPane`: accepted source-file owner/emitter. Constructor, destructor, transition operation, and pre-login helpers form one contiguous source family.
4. UID00007O `MainMenuPane`: accepted class owner for UID00019K, but not direct owner of the global-storage page because the existing by-global layer is the narrower semantic owner.
5. UID0000L1 `MainUiGraph`: rejected for singleton and transition ownership. It owns the in-game graph/layer reconstruction concept, not the concrete pre-login receiver.
6. LoginDialogPane/Application/dialog classes: rejected. They trigger or consume the singleton but do not publish its concrete lifecycle.
7. Browser/WebBoard pages: rejected. Adjacency ends at `0x0067aba4`; no browser ref reaches the target.

## Source Placement

- Definition: `NexusTK/login/MainMenuPane.cpp`, emitted once by exact target UID0002AF through by-global UID0000RF and file UID0000L0.
- Declaration: intended `MainMenuPane.h` external declaration, visible to Application/login/dialog/UI consumers. This is source/header reconstruction prose on UID0000L0 and consumer by-file pages; by-file roots must not receive RECONSTRUCTION_CPP metadata.
- Class declaration: UID00007O adds the transition method declaration and keeps `[[CHILDREN]]`.
- Method operation: UID00019K routes through UID00007O at position `120`, immediately after the existing address-ordered MainMenuPane method island. Destination 6 supplies the full method body; no blank-body or future reconstruction gate remains.
- Header dependency: `Layer::MarkAllPanesForDeletion` is a source-level Layer member at `0x004f0b40`. B002 did not change the three B001-owned Layer pages; B001 independently applied the complete UID0004NW body, UID000073 declaration, and UID0000KL route, and supervisor verification cleared them at same-or-greater detail. UID00019K is the only destination for the complete `InitializeMainUiGraph` body.
- UID0000UV becomes a non-emitting alias/index to UID00019K so generated source does not carry two representations of one operation.
- Source-bearing consumers keep their current owner files and bodies. Only the accepted global identifier changes.

## Range / Split / Padding / Reclassification Analysis

- Target remains exact `[0x0067aba4,0x0067aba8)`. A 32-bit pointer is atomic here; no split is possible or useful.
- Predecessor `[0x0067aba0,0x0067aba4)` is UID0002WK `g_pWebBoardDialogOld`. Successor begins at `0x0067aba8` and belongs to UID0002AG WebBoard URL escape state. Neither overlaps the target.
- The preceding mixed browser aggregate ends exactly at `0x0067aba4`; target is independent. Retaining `Nested:-12` closes the prior aggregate nesting in the manual inventory. Changing it to zero would risk placing the target at the wrong structural depth.
- Target position remains blank because UID0000RF is its sole parent. UID0000RF position `0` ensures the forward declaration/definition child precedes the MainMenuPane class and methods, matching the validated DirectX pattern.
- UID00019K modeled range remains last covered byte `0x004f8b2a`, half-open end `0x004f8b2b`, then five `0xcc` bytes before `0x004f8b30`. Ownership reclassification does not rename/split that range.
- IDA attributes 139 CFG blocks to the function: 104 in-range blocks, 33 external cleanup funclets at `0x00601323-0x006014f0`, one external frame-handler block at `0x006014f1-0x00601518`, and one synthetic zero-size terminal node. The 33 cleanup funclets correspond one-for-one with source `new` expressions: 19 in the EPF/current branch, 13 in the legacy branch, and the legacy-only `InterfaceEfxMgr` construction in the common tail. Thirty-one call global `operator delete`; `0x0060141f` and `0x006014d5` call the UserPane pool-free unwind wrapper. These exact external blocks and the security-cookie/`__CxxFrameHandler3` bridge are compiler output generated by the handwritten method and are not split into source children.

## Negative Evidence Summary

- No current IDB name, global row, or UDT directly names the target.
- No mapped `0xffffffff` bytes or nonzero sentinel exist at the target.
- No raw-backed PE bytes exist for the target; it is BSS/zero-fill.
- No PE relocation directory exists, and no target relocation can encode an initializer.
- No browser or WebBoard function references the slot despite immediate adjacency.
- No `MainUiGraph` class allocation, layout, vtable, constructor, or destructor is tied to the slot.
- No source evidence supports file-static linkage; consumers cross multiple reconstructed files.
- No source reason supports duplicate by-global and by-memory definitions.
- No evidence justifies handwriting Singleton base adjustment, vptr stores, ordinary member/base teardown, clear thunks, or scalar deleting destructor wrappers.
- No unresolved direct callee remains in UID00019K. All 39 are classified: 30 pane/class/helper dependencies, `InitRectBounds`, `WideCharToMultiByte`, profile load, screen presentation, BlackHole queueing, input retargeting, sound restart, plus compiler-lowered global allocation, UserPane pool allocation, and security-cookie support. The 139-block count is inflated by allocation null paths and 35 external EH/synthetic blocks; it does not imply 139 source decisions. The source CFG is the EPF/legacy selection, optional existing-object deletes, legacy-only InterfaceEfxMgr construction, and one common tail.

## IDA Rename / Type / Comment Recommendations

- If a later supervisor-authorized IDA pass is performed, rename target data to `g_pMainMenuPane` and apply pointer type `MainMenuPane *` only after the MainMenuPane UDT is available. This report performs no IDA mutation.
- Rename/source-type `0x004f7d10` as `MainMenuPane::InitializeMainUiGraph()` only in an authorized type pass; current active label remains `sub_4F7D10`.
- Comment constructor sites `0x004f6751/0x004f6758` as Singleton publication/null-adjust lowering, destructor `0x004f6979` as Singleton clear, `0x004fadc6` as `m_serverName` write, and `0x004fac95` as transition receiver load.
- Keep `g_pMainUiGraph`, `dword_67ABA4`, and `unk_67ABA4` as searchable historical aliases in documentation comments, not accepted source identifiers.

## First-Draft C++ Recommendation

Destination 1: UID-preserving rename to `by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MainMenuPane;

MainMenuPane *g_pMainMenuPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 2: UID-preserving rename to `by-global/g_pMainMenuPane.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 3: `by-file/MainMenuPane.md` is prose/source-placement only. It receives no reconstruction metadata or formal block.

Destination 4: `by-class/MainMenuPane.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MainMenuPane : public Pane, public Singleton<MainMenuPane>
{
public:
    explicit MainMenuPane(bool fromTerminalTransition);
    virtual ~MainMenuPane();

    void SetServerName(const wchar_t *serverName);
    void SetPaintSuppressed(bool suppressed);
    void ActivateMenuItem();
    void InitializeMainUiGraph();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

    bool m_paintSuppressed;
    signed char m_menuItemCount;
    signed char m_selectedMenuItemIndex;
    wchar_t m_serverName[128];
    EPFTileContext m_backgroundTileContext;
    DLPalette m_backgroundPalette;
    bool m_fromTerminalTransition;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 5: `by-memory/0x004f6700-0x004f6904.MainMenuPaneConstructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MainMenuPane::MainMenuPane(bool fromTerminalTransition)
    : Pane(0),
      m_paintSuppressed(false),
      m_menuItemCount(6),
      m_selectedMenuItemIndex(1),
      m_fromTerminalTransition(fromTerminalTransition)
{
    m_serverName[0] = 0;

    g_pInputMan->SetInputMode(2);
    g_applicationPhase = 2;

    if (g_pConfig->m_useMenuMusic != 0)
        g_pSoundManager->PlayTrackByIndex(0, 100, 1);
    else
        g_pSoundManager->PlayTrackByIndex(999, 100, 1);

    ScheduleTimer(1, 20000, 0, 0);

    RectBounds bounds;
    InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
    InitializePane(&bounds, g_pMainMenuPane);
    SetPaneMode(0, g_pScreenPane);

    File levelFile(L"LEVEL.BMP", L"rb");
    if (levelFile.IsOpen()) {
        _AUTOBUF<unsigned char> bytes(levelFile.GetRemainingLength());
        levelFile.Read(bytes.GetBuffer(), bytes.GetSize());
        Decode8BitBmpToTileContext(
            bytes.GetBuffer(),
            bytes.GetSize(),
            &m_backgroundTileContext,
            &m_backgroundPalette);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 6: `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`; owner/emitter/position plus complete source body. The body preserves both layout branches, every source-visible construction/setup call, the two otherwise-unused bounds initializations, the common tail, and exact `== 1`/`!= 1` mode semantics. Allocation null tests, EH state writes, out-of-line unwind funclets, UserPane pool-return cleanup, stack cookies, and the decompiler's return value are compiler lowering and are intentionally absent.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MainMenuPane::InitializeMainUiGraph()
{
    RectBounds bounds;

    if (g_useEpfAssets == 1) {
        g_mainUiLayerSlots.overlayPaneLayerContext->MarkAllPanesForDeletion();

        BackPane *backPane = new BackPane(L"FRAME.EPF");
        backPane->GetBounds(&bounds);
        backPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.rootPaneLayerContext);
        backPane->SetPaneOrder(0, NULL);

        MapPane *mapPane = new MapPane(17, 15);
        InitRectBounds(
            &bounds,
            -g_mapTilePixelWidth,
            -g_mapTilePixelHeight,
            18 * g_mapTilePixelWidth,
            16 * g_mapTilePixelHeight);
        mapPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapPane->SetPaneOrder(0, backPane);

        ChattingBackPane *chattingBackPane = new ChattingBackPane();
        InitRectBounds(&bounds, 9, 596, 816, 720);
        chattingBackPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingBackPane->SetPaneOrder(0, backPane);

        ChattingPane *chattingPane = new ChattingPane();
        InitRectBounds(&bounds, 23, 606, 806, 710);
        chattingPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingPane->SetPaneOrder(0, backPane);

        ChattingModifyHeightPane *modifyHeightPane =
            new ChattingModifyHeightPane();
        InitRectBounds(&bounds, 792, 590, 807, 605);
        modifyHeightPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        modifyHeightPane->SetPaneOrder(0, backPane);
        modifyHeightPane->SetLineCount(g_pConfig->m_chatVisibleLineCount);

        new GeneralPurposePanel();
        new GeneralPurposePanel2();
        BuildAboveFrameBorder();

        MapNamePane *mapNamePane = new MapNamePane();
        InitRectBounds(&bounds, 316, 0, 509, 24);
        mapNamePane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapNamePane->SetPaneOrder(0, backPane);

        MiniMapButtonPane *miniMapButtonPane = new MiniMapButtonPane();
        InitRectBounds(&bounds, 6, 6, 34, 34);
        miniMapButtonPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        miniMapButtonPane->SetPaneOrder(0, backPane);

        TabPane *tabPane = new TabPane();
        InitRectBounds(&bounds, 808, 79, 831, 365);
        tabPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        tabPane->SetPaneOrder(0, backPane);

        HourPane *hourPane = new HourPane();
        InitRectBounds(&bounds, 830, 736, 885, 751);
        hourPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        hourPane->SetPaneOrder(0, backPane);

        ChattingVarietyPane *chattingVarietyPane =
            new ChattingVarietyPane();
        InitRectBounds(&bounds, 10, 727, 72, 751);
        chattingVarietyPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingVarietyPane->SetPaneOrder(0, backPane);

        ChattingHandlePane *chattingHandlePane = new ChattingHandlePane();
        InitRectBounds(&bounds, 74, 727, 740, 751);
        chattingHandlePane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        chattingHandlePane->SetPaneOrder(0, backPane);

        MenuVarietyPane *menuVarietyPane = new MenuVarietyPane();
        InitRectBounds(&bounds, 744, 727, 805, 751);
        menuVarietyPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        menuVarietyPane->SetPaneOrder(0, backPane);

        UserStatusPane *userStatusPane = new UserStatusPane(m_serverName);
        InitRectBounds(&bounds, 826, 16, 997, 58);
        userStatusPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        userStatusPane->SetPaneOrder(0, backPane);

        UserStatusPane2 *userStatusPane2 = new UserStatusPane2();
        InitRectBounds(&bounds, 881, 659, 1007, 753);
        userStatusPane2->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        userStatusPane2->SetPaneOrder(0, backPane);

        new SoundStatusPane();

        ParcelIconPane *parcelIconPane = new ParcelIconPane();
        parcelIconPane->SetPaneOrder(0, backPane);

        SetLocalPlayerName(m_serverName);

        delete g_pUserPane;
        UserPane *userPane = new UserPane();
        InitRectBounds(&bounds, 0, 0, 0, 0);
        userPane->SetPaneOrder(0, mapPane);

        char playerName[128];
        WideCharToMultiByte(
            CP_ACP,
            0,
            m_serverName,
            -1,
            playerName,
            sizeof(playerName),
            NULL,
            NULL);
        BuildPacketTransformKeyText(playerName);
    } else {
        BackPane *backPane = new BackPane(L"FRAME.EPD");
        InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
        backPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.rootPaneLayerContext);
        backPane->SetPaneOrder(0, NULL);

        MapPane *mapPane = new MapPane(17, 15);
        InitRectBounds(
            &bounds,
            14 - g_mapTilePixelWidth,
            12 - g_mapTilePixelHeight,
            18 * g_mapTilePixelWidth + 14,
            16 * g_mapTilePixelHeight + 12);
        mapPane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapPane->SetPaneOrder(0, backPane);

        BuildAboveFrameBorder();

        MapNamePane *mapNamePane = new MapNamePane();
        InitRectBounds(&bounds, 131, 0, 304, 12);
        mapNamePane->AddToLayer(
            &bounds, 0, NULL, g_mainUiLayerSlots.effectPaneLayerContext);
        mapNamePane->SetPaneOrder(0, backPane);

        IconsPane *iconsPane = new IconsPane();
        InitRectBounds(&bounds, 263, 374, 422, 388);
        iconsPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        iconsPane->SetPaneOrder(0, backPane);

        HourPane *hourPane = new HourPane();
        InitRectBounds(&bounds, 14, 375, 43, 387);
        hourPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        hourPane->SetPaneOrder(0, backPane);

        new ConnStatusPane();
        InitRectBounds(&bounds, 244, 374, 263, 388);

        new GeneralPurposePanel();

        OldSystemMessagePane *systemMessagePane =
            new OldSystemMessagePane();
        InitRectBounds(&bounds, 441, 304, 639, 369);
        systemMessagePane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        systemMessagePane->SetPaneOrder(0, backPane);

        ChattingPane *chattingPane = new ChattingPane();
        InitRectBounds(&bounds, 14, 390, 434, 455);
        chattingPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        chattingPane->SetPaneOrder(0, backPane);

        OldUserStatusPane *userStatusPane =
            new OldUserStatusPane(m_serverName);
        InitRectBounds(&bounds, 434, 373, 627, 469);
        userStatusPane->AddToLayer(
            &bounds, 0, backPane, g_mainUiLayerSlots.rootPaneLayerContext);
        userStatusPane->SetPaneOrder(0, backPane);

        new SoundStatusPane();

        ParcelIconPane *parcelIconPane = new ParcelIconPane();
        parcelIconPane->SetPaneOrder(0, backPane);

        SetLocalPlayerName(m_serverName);

        delete g_pUserPane;
        UserPane *userPane = new UserPane();
        InitRectBounds(&bounds, 0, 0, 0, 0);
        userPane->SetPaneOrder(0, mapPane);
    }

    LoadUserProfileData();
    g_pScreenPane->EnablePresentationMode();
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);

    delete g_pScreenDimmer;

    if (g_useEpfAssets != 1)
        new InterfaceEfxMgr();

    g_pInputMan->TrackInputTarget(0, false);
    g_pSoundManager->RestartMusic(3000);
    g_pApplication->m_inMapSession = true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 7: `by-item/InitializeMainUiGraph_004F7D10.md`; convert to non-emitting alias/index, blank formal block.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 8: `by-file/MainUiGraph.md` is prose/ownership correction only. It receives no reconstruction metadata or formal block.

Destination 9: `by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Application::Shutdown()
{
    ApplicationPhaseState = 4;

    if (g_pEventMan)
        g_pEventMan->ShutdownPacketEventSource();

    delete g_pIMEPane;

    if (g_pScreenPane) {
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.statusPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.layoutPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.overlayPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.effectPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.rootPaneLayerContext);
        g_pScreenPane->DetachLayerFrame(g_mainUiLayerSlots.fpsOverlayLayerContext);
    }

    delete g_pMainMenuPane;

    delete g_mainUiLayerSlots.fpsOverlayLayerContext;
    g_mainUiLayerSlots.fpsOverlayLayerContext = NULL;

    delete g_mainUiLayerSlots.statusPaneLayerContext;
    g_mainUiLayerSlots.statusPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.overlayPaneLayerContext;
    g_mainUiLayerSlots.overlayPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.effectPaneLayerContext;
    g_mainUiLayerSlots.effectPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.rootPaneLayerContext;
    g_mainUiLayerSlots.rootPaneLayerContext = NULL;

    delete g_mainUiLayerSlots.layoutPaneLayerContext;
    g_mainUiLayerSlots.layoutPaneLayerContext = NULL;

    delete g_pEffectObjImageLib;
    delete g_pStaticObjImageLib;
    delete g_pNewHumanImageLib;
    delete g_pMonsterImageLib;
    delete g_pRidingImageLib;
    delete g_pMapTileImageLib;
    delete g_pItemObjImageLib;
    delete g_pLightObjImageLib;

    delete g_pIdleWatcher;

    g_packetSender->ForceTerminate();
    delete g_packetSender;

    delete g_pTextFilter;
    delete g_pMetaMan;

    CleanupResources();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 10: `by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EmployeeItemPropertyDialogPane::EmployeeItemPropertyDialogPane(
    EmployeeRecord *itemRecord,
    EmployeeDialogPane *owner)
    : DialogPane(L"Property", 20, true)
{
    RectBounds rect;
    wchar_t editPriceText[128];
    wchar_t itemName[256];
    wchar_t priceText[128];

    m_owner = owner;
    m_itemRecord = itemRecord;

    InitRectBounds(&rect, 42, 90, 105, 114);
    AddControl(new ImageButtonControlPane(53, rect));

    InitRectBounds(&rect, 119, 90, 182, 114);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 196, 90, 259, 114);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 120, 47, 283, 59);
    swprintf_s(editPriceText, 128, L"%u", m_itemRecord->editablePriceValue);
    AddControl(new TextEditControlPane(editPriceText, true, 143, 128, rect));

    InitRectBounds(&m_itemIconRect, 20, 21, 68, 69);

    wcscpy_s(itemName, 256, m_itemRecord->name);
    InitRectBounds(&rect, 120, 25, 180, 37);
    AddControl(new StaticTextControlPane(itemName, true, 143, 128, rect));

    swprintf_s(priceText, 128, L"%d", m_itemRecord->priceValue);
    InitRectBounds(&rect, 259, 25, 287, 37);
    AddControl(new StaticTextControlPane(priceText, true, 143, 128, rect));

    SetDefaultAction(kEmployeeItemPropertyConfirmAction);
    SetCancelAction(kEmployeeItemPropertyCloseAction);
    SetInitialFocus(kEmployeeItemPropertyPriceEditControlId);

    InitRectBounds(&rect, 0, 0, 307, 124);
    Create(rect, 0, 0, overlayPaneLayerContext);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 11: `by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EmployeeQuantityInputDialogPane::EmployeeQuantityInputDialogPane(
    const wchar_t *promptText,
    EmployeeDialogPane *owner,
    char selectedIndex)
    : DialogPane(L"Quantity", 19, true)
{
    RectBounds rect;

    InitRectBounds(&rect, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(
        L"DLGEXC3.EPF",
        0,
        true,
        rect,
        L"PAL01.PAL"));

    InitRectBounds(&rect, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 30, 60, 197, 72);
    AddControl(new StaticTextControlPane(promptText, false, 128, rect));

    InitRectBounds(&rect, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(L"", true, 143, rect));

    SetBackgroundResource(L"DLGEXC3.EPF", 0);
    SetDefaultAction(1);
    SetCancelAction(2);
    SetInitialFocus(4);

    m_owner = owner;
    m_selectedIndex = selectedIndex;

    InitRectBounds(&rect, 0, 0, 239, 283);
    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 12: `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
NewUserMiscDialogPane::NewUserMiscDialogPane()
    : DialogPane(L"", -1, true)
{
    RectBounds rect;

    g_pNewUserMiscDialogPane = this;

    InitRectBounds(&rect, 0, 0, 402, 373);
    AddControl(new EPFImageControlPane(L"DLGNEW02.EPD", 0, true, rect, NULL));

    InitRectBounds(&rect, 123, 307, 195, 323);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 201, 307, 273, 323);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 172, 49, 196, 72);
    AddControl(new GenderButtonControlPane(0, 2, true, rect));

    InitRectBounds(&rect, 200, 49, 224, 72);
    AddControl(new GenderButtonControlPane(1, 0, false, rect));

    const int shapeCount = g_pNewHumanImageLib->GetHeadCount();
    const int firstShapeIndex = rand() % (shapeCount - 3);

    InitRectBounds(&rect, 80, 78, 139, 154);
    UserShapeSelectControlPane *shapeButton =
        new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex), true, &rect, 1);
    AddControl(shapeButton);
    shapeButton->SetSelected(true);

    InitRectBounds(&rect, 139, 78, 198, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 1),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 198, 78, 257, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 2),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 257, 78, 316, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 3),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 56, 107, 72, 123);
    DirectionButtonControlPane *leftButton = new DirectionButtonControlPane(0, rect);
    AddControl(leftButton);
    if (firstShapeIndex == 0) {
        leftButton->Disable();
    }

    InitRectBounds(&rect, 325, 107, 341, 123);
    DirectionButtonControlPane *rightButton = new DirectionButtonControlPane(1, rect);
    AddControl(rightButton);
    if (firstShapeIndex == shapeCount - 4) {
        rightButton->Disable();
    }

    srand((unsigned)_time64(0));

    const int genderChoice = rand() % 2;

    InitRectBounds(&rect, 145, 180, 196, 231);
    SelectBoxControlPane *maleBox = new SelectBoxControlPane(&rect);
    AddControl(maleBox);
    maleBox->SetSelected(genderChoice == 0);

    InitRectBounds(&rect, 200, 180, 251, 231);
    SelectBoxControlPane *femaleBox = new SelectBoxControlPane(&rect);
    AddControl(femaleBox);
    femaleBox->SetSelected(genderChoice != 0);

    const int styleChoice = rand() % 4;

    InitRectBounds(&rect, 90, 235, 141, 286);
    SelectBoxControlPane *styleBox0 = new SelectBoxControlPane(&rect);
    AddControl(styleBox0);
    styleBox0->SetSelected(styleChoice == 0);

    InitRectBounds(&rect, 146, 235, 197, 286);
    SelectBoxControlPane *styleBox1 = new SelectBoxControlPane(&rect);
    AddControl(styleBox1);
    styleBox1->SetSelected(styleChoice == 1);

    InitRectBounds(&rect, 200, 235, 251, 286);
    SelectBoxControlPane *styleBox2 = new SelectBoxControlPane(&rect);
    AddControl(styleBox2);
    styleBox2->SetSelected(styleChoice == 2);

    InitRectBounds(&rect, 255, 235, 306, 286);
    SelectBoxControlPane *styleBox3 = new SelectBoxControlPane(&rect);
    AddControl(styleBox3);
    styleBox3->SetSelected(styleChoice == 3);

    SetHoverControl(5);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGNEW02.EPD", 0);
    SetMode(1);

    InitRectBounds(&rect, 238, 107, 640, 480);
    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 13: `by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaffsDialogPane::StaffsDialogPane()
    : DialogPane(g_emptyWideString, -1, true)
{
    g_pStaffsDialog = this;

    RECT frameRect;
    RECT controlRect;
    const unsigned char eventFlags = GetCurrentEventFlags();

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    AddControl(new EPFImageControlPane(kStaffsDialogEpfName, 0, true, frameRect, L"NPAL8.PAL"));
    LoadDialogResource(kStaffsDialogEpfName, 0);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    SetRect(&controlRect,
            (frameRect.right - frameRect.left) / 2 - 31,
            322,
            (frameRect.right - frameRect.left) / 2 + 31,
            346);
    AddControl(new ImageButtonControlPane(14, controlRect));

    SetRect(&controlRect, 38, 62, 230, 305);
    AddControl(new ScrolledTextControlPane((eventFlags & kStaffsDialogAlternateTextEventFlag) != 0 ? L"STAFFS2" : L"STAFFS",
                                           controlRect,
                                           50));

    SetCloseOnEscape(true);
    SetModal(true);
    EnableKeyboardInput(true);

    GetDialogResourceFrame(kStaffsDialogEpfName, 0, &frameRect);
    OffsetRect(&frameRect, frameRect.left - frameRect.right + 630, 130);
    AttachToLayer(frameRect, 0, 0, g_mainUiLayer);
    Show(0, g_pMainMenuPane);
    SlideOpen();
}

void StaffsDialogPane::OnDialogAction(int actionId, int actionParam)
{
    (void)actionParam;

    if (actionId == 1) {
        SlideClose();
        CloseDialog();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 14: `by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BackStoryDialogPane::BackStoryDialogPane()
    : DialogPane(L"", -1, true)
{
    g_pBackStoryDialogPane = this;

    RectBounds rect;
    if (g_useEpfAssets) {
        InitRectBounds(&rect, 0, 0, 384, 341);
        AddControl(new EPFImageControlPane(L"STORY.EPF", 0, true, rect, L"PAL01.PAL"));

        InitRectBounds(&rect, 169, 305, 232, 329);
        AddControl(new ImageButtonControlPane(14, rect));

        InitRectBounds(&rect, 25, 56, 361, 278);
        AddControl(new ScrolledTextControlPane(L"BACKTALE", rect, 50));

        SetHoverControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"STORY.EPF", 0);
        SetMode(1);

        InitRectBounds(&rect, 246, 150, 630, 491);
    } else {
        InitRectBounds(&rect, 0, 0, 267, 337);
        AddControl(new EPFImageControlPane(L"STORY.EPD", 0, true, rect, L"NPAL8.PAL"));

        InitRectBounds(&rect, 98, 287, 170, 303);
        AddControl(new ImageButtonControlPane(14, rect));

        InitRectBounds(&rect, 36, 71, 228, 265);
        AddControl(new ScrolledTextControlPane(L"BACKTALE", rect, 50));

        SetHoverControl(1);
        SetPendingControl(1);
        SetBackgroundResource(L"STORY.EPD", 0);
        SetMode(1);

        InitRectBounds(&rect, 363, 150, 630, 487);
    }

    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}

void BackStoryDialogPane::HandleButtonClick(int buttonId, int /*unused*/)
{
    if (buttonId == 1) {
        SlideClose();
        Close();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 15: `by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {
constexpr unsigned char kEventLeftButtonUp = 3;
constexpr unsigned char kEventRightButtonUp = 6;
constexpr unsigned char kEventKeyInput = 8;
}

NewHistoryDialogPane::NewHistoryDialogPane()
    : DialogPane(L"", -1, true)
{
    g_pNewHistoryDialog = this;

    RectBounds rect;
    InitRectBounds(&rect, 0, 0, 1024, 768);
    AddControl(new EPFImageControlPane(L"HISTORYN.EPF", 0, true, rect, L"HISTORYN.PAL"));

    InitRectBounds(&rect, 614, 156, 950, 556);
    AddControl(new ScrolledTextControlPaneForMadeBy(L"MADEBY", &rect, 30));

    SetBackgroundResource(L"HISTORYN.EPF", 0);
    SetMode(1);

    InitRectBounds(&rect, 0, 0, 1024, 768);
    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainMenuPane);
}

bool NewHistoryDialogPane::OnKeyInput(const Event& event)
{
    if (event.type == kEventKeyInput) {
        const char key = NarrowKeyCode(event.keyCode, event.defaultChar);
        if (key == '\r' || key == '\x1b' || key == ' ') {
            Close();
        }
    }

    return true;
}

bool NewHistoryDialogPane::OnMouseInput(const Event& event)
{
    if (event.type == kEventLeftButtonUp || event.type == kEventRightButtonUp) {
        Close();
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 16: `by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void DestroyActiveScreenDimmer()
{
    if (g_pScreenDimmer != 0)
        delete g_pScreenDimmer;
}

static bool HandleAnsiTextUrlDialogPacket(const unsigned char *packet)
{
    int offset = 1;
    unsigned char subtype = packet[offset++];

    DestroyActiveScreenDimmer();

    if (subtype == 1 || subtype == 2) {
        unsigned short urlLength = PacketBufferReadUInt16BE(packet + offset);
        const char *urlText = reinterpret_cast<const char *>(packet + offset + 2);
        offset += 2 + urlLength;

        unsigned short messageLength = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;

        wchar_t messageText[1000];
        int wideLength = MultiByteToWideChar(
            0,
            0,
            reinterpret_cast<const char *>(packet + offset),
            messageLength,
            messageText,
            999);
        messageText[wideLength] = 0;

        new UrlAlertPane(
            subtype == 1,
            g_pMainMenuPane,
            messageText,
            urlText,
            urlLength);
    } else if (subtype == 3) {
        StringBase overrideUrl;
        PacketBufferReadAnsiBytes8(&overrideUrl, packet, &offset);
        g_ncauthConfirmUserUrlOverrideString = overrideUrl;
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 17: `by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md`.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ForcedInformMessageDialog::~ForcedInformMessageDialog()
{
    if (g_useEpfAssets == 1 &&
        m_bAccepted &&
        g_pMainMenuPane != NULL) {
        EnsureLoginDialogPane();
    }

    g_pForcedInformMessageDialog = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 18 applied state: the named non-Layer prose/link pages were synchronized and validated without formal metadata/body additions. Old spellings remain only in explicitly labeled history, and every affected page preserves the warning that `0x0069b36c` is not `g_pMainMenuPane`. The three Layer pages were not leased or edited by B002 because B001 UID00018W owned them. B001 subsequently applied the complete full-child-list operation to UID0004NW, declaration to UID000073, and source route to UID0000KL; supervisor artifact/gate/command proof independently clears that same-or-greater dependency. No duplicate helper or UID00019K body was added there.

## Final Recommendation

- Destinations 1-18 are complete: B002 applied and validated Destinations 1-17 plus every B002-owned Destination 18 page, while B001 independently applied the Layer body/declaration/source-route portion and the supervisor verified it at Gate 1/Gate 2. The two UID-preserving renames, by-global/target route, source-bearing replacements, external dependency, and generated verification are complete.
- Do not create a duplicate report, new UID, new storage child, compatibility alias, second definition, class-static storage page, or handwritten Singleton/ABI wrapper.
- UID00019K preserves accepted binary research as history and emits Destination 6's complete human-written source without decompiler temporaries, raw labels, allocation-null branches, EH state writes, cleanup funclets, vtable scaffolding, or artifact return.
- Generated verification proves `g_pMainMenuPane` only, one definition in MainMenuPane.cpp, no UID0002AF/UID00019K Empty Emitter Marker, and no UID0000RF/UID0002AF marker in MainUiGraph.cpp.
- B001's Layer work is independently complete and supervisor-cleared at same-or-greater detail. B002's report/docs/validators/leases and all external dependency checks are complete; current/future execution and lifecycle state remain supervisor-owned and are not asserted.

## Recommended Target Doc Changes

- Applied UID-preserving path/title/link text `g_pMainMenuPane`.
- Applied metadata `93/94` with retained owner/emitter/reconstructable/blank position/`Nested:-12`.
- Applied Destination 1 exact formal definition and all report-level byte/PE/xref/lifecycle/type/linkage/source/history evidence.

## Recommended Support Doc Changes

- UID0000RF is applied at `92/94`, owner/emitter UID0000L0, position `0`, with Destination 2 and no duplicate definition.
- UID0000L0 is applied at `92/92`; UID00007O at `92/94`; UID0004LY retains `90/93`; UID00019K is `93/94`, owner/emitter UID00007O, position `120`; UID0000UV is `91/93`, owner UID00019K, FALSE, blank emitter/position/C++; UID0000L1 retains `88/88` and is de-owned.
- Destinations 9-17 retain metadata/behavior/unrelated code and match their accepted formal blocks exactly. Non-Layer Destination 18 pages retain same-or-greater detail and no by-file reconstruction metadata.
- Layer support is externally completed under B001 UID00018W without a B002 edit: UID0004NW is `91/94`, owner/emitter UID000073, position `70`, with the exact body; UID000073 is `92/94` and declares the method; UID0000KL is `91/93` and records `NexusTK/ui/core/Layer.cpp` as the source route.
- Adjacent UID0002WK, UID0002AG, UID0002AE storage boundaries are verify-only unless direct readback finds stale target-overlap text.

## Score And Metadata Recommendation

| Page | Recommended metadata | Rationale / cap |
| --- | --- | --- |
| UID0002AF target | `93/94`, owner/emitter UID0000RF, TRUE, blank position, `Nested:-12` | Exact bytes, section, adjacency, all refs, lifecycle, type, linkage, owner, and definition resolved; original symbol and explicit-vs-implicit null spelling remain inferred |
| UID0000RF global | `92/94`, owner/emitter UID0000L0, TRUE, position `0` | Complete symbol semantics/source route and nonduplicate child emission; original symbol spelling cap |
| UID0000L0 file | `92/92` | Existing source island plus resolved singleton/transition ownership; retained no-route helpers cap final audit |
| UID00007O class | `92/94` | Exact layout/lifecycle and transition declaration; original access/name spellings cap confidence |
| UID00019K exact method | `93/94`, owner/emitter UID00007O, TRUE, position `120`, complete Destination 6 C++ | Exact receiver, sole caller, both layout branches, source order, all state/callees, common tail, and compiler/EH distinctions resolved; stripped helper/member spellings cap final audit |
| UID0000UV alias | `91/93`, owner UID00019K, FALSE, blank emitter/position/C++ | Exact alias relationship; no duplicate emission |
| UID0000L1 file | retain `88/88` | Deownership correction improves accuracy but does not complete its broader layer declarations |

Why target remains below `95`: no PDB/source symbol survives; `g_pMainMenuPane` and explicit `= NULL` remain highest-probability project source choices; several late consumer functions retain provisional names; header include topology is not represented by current validator output.

## Open Questions With Attempted Resolution

| Question | Checks | Resolution / remaining impact |
| --- | --- | --- |
| Is `0xffffffff` real? | MCP bytes/value; PE section raw/virtual geometry | No. Loader-zeroed BSS; historicalize old note. Closed. |
| Is the object MainUiGraph or MainMenuPane? | constructor/destructors, allocation, RTTI/layout, `+0xfc` write, transition receiver | MainMenuPane. Closed. |
| What is the best source name? | project singleton names, class evidence, alternatives, active symbol absence | `g_pMainMenuPane`; inferred spelling caps confidence. |
| Static or external? | all 31 users and generated source files | external. Closed. |
| Explicit or implicit null initializer? | BSS bytes and project style | behavior-equivalent; choose explicit `NULL`, retain confidence cap. |
| Which page emits? | DirectX/Browser validated patterns, current parent chain | exact storage child emits; by-global inserts children. Closed. |
| Where is declaration visible? | cross-TU consumers and by-file guidance | intended `MainMenuPane.h` external declaration; prose-only current header route. |
| Is UID00019K a method? | ECX receiver, exact member offset, sole caller, source order, teardown queue | yes, `MainMenuPane::InitializeMainUiGraph()`. Closed with complete formal body. |
| Can all 39 callees and 139 blocks be reduced to source? | fresh decompile/disassembly, callee list, CFG blocks, EH funclets, current pane/support docs | yes. All source dependencies are named; allocation, pool allocation/free, 33 unwind funclets, frame handler, cookie, and virtual-dispatch scaffolding are compiler lowering. Closed. |
| Does the 3611-byte size justify no code? | exact branch/CFG/source-order reconstruction | no. Complexity is dominated by repeated construction/unwind expansion; Destination 6 supplies the full human source. Closed. |
| Does UID0000UV emit? | exact memory page is canonical full documentation | no; convert to alias/index. Closed. |
| Change `Nested:-12`? | manual inventory structure and predecessor aggregate closure | retain. Closed. |

No investigable target, UID00019K, or Layer dependency blocker remains. Remaining uncertainty is stripped original spelling, header formatting, and whether a few simple helper/accessor names were inline; these cap confidence below 95 but do not justify blank source. Supervisor-cleared B001 implementation proof closes C21 without any B002 edit to the Layer pages.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual coverage is supervisor-owned and was not edited by B002. The exact replacement/addition text below reflects the completed callback and remains available for supervisor-owned coverage reconciliation:

Replace UID0002AF in `by-memory/-coverage-report.md` and preserve its independent four-space level:

`    - [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md) 0x0067aba4-0x0067aba8 | global pointer | g_pMainMenuPane : reconstructable : 93% : very strong : Exact zero-initialized MainMenuPane singleton storage in the .data virtual zero-fill tail; current MCP proves 31 refs across 26 modeled functions plus one WndProc fragment, constructor publication, ordinary/scalar destruction clears, MainMenuPane +0xfc server-name access, transition receiver use, external linkage, sole source definition through [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md), and historical rejection of g_pMainUiGraph/0xffffffff.`

Replace UID0000RF in `by-global/-coverage-report.md` and re-sort at `g_pMainMenuPane`:

`- [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) : reconstructable : 92% : very strong : MainMenuPane singleton symbol at exact storage [UID:0002AF][0x0067aba4-0x0067aba8.g_pMainMenuPane](by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md), with current zero-fill bytes, complete 31-reference lifecycle/consumer inventory, external linkage, MainMenuPane.cpp owner/emitter, exact-child sole definition, and g_pMainUiGraph retained only as a historical alias.`

Replace UID0000L0 in `by-file/-coverage-report.md`:

`- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) : reconstructable : 92% : very strong : Exact pre-login MainMenuPane source family with 0x454 class/layout, constructor/destructor/input/packet/timer/paint/activation methods, retained helpers, externally visible g_pMainMenuPane singleton definition/header route, and complete MainMenuPane::InitializeMainUiGraph two-layout transition source resolved from live receiver/member/lifetime/callee/EH evidence.`

Replace UID0000L1 in `by-file/-coverage-report.md`:

`- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) : reconstructable : 88% : strong : In-game UI graph/layer bootstrap support root with new/old layout branches, MainUiLayerSlots, resource and map-session evidence; UID0002AF/UID0000RF and receiver-bound UID00019K are explicitly routed to MainMenuPane rather than modeled as a separate MainUiGraph object.`

Replace UID00007O in `by-class/-coverage-report.md`:

`- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) : reconstructable : 92% : very strong : Exact 0x454 Pane/Singleton<MainMenuPane> declaration and address-ordered method family, including constructor/destructor, input/packet/timer/paint/activation methods and complete MainMenuPane::InitializeMainUiGraph source; singleton storage/lifetime, natural padding, vtable/compiler exclusions, retained helper ownership, and source route are documented.`

Replace UID00019K in `by-memory/-coverage-report.md`:

`    - [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) 0x004f7d10-0x004f8b2a | class method | MainMenuPane::InitializeMainUiGraph : reconstructable : 93% : very strong : Exact MainMenuPane transition method with sole login-success caller through g_pMainMenuPane, m_serverName receiver access, complete EPF/current and legacy pane-construction branches, exact bounds/layer/order/resource/profile/name/input/sound/session common-tail behavior, all 39 callees resolved, 33 unwind funclets plus frame/cookie/pool cleanup classified as compiler output, owner/emitter UID00007O, and complete human-shaped formal C++.`

Replace UID0000UV in `by-item/-coverage-report.md`:

`- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) : not_reconstructable : 91% : very strong : Non-emitting alias/index for exact [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md), resolved as MainMenuPane::InitializeMainUiGraph; the exact memory page owns complete behavior, formal source, compiler exclusions, and routing without duplicate emission.`

Current UID000073 in `by-class/-coverage-report.md` was read-only verified to match this exact externally completed B001 state:

`- [UID:000073][Layer](by-class/Layer.md) : reconstructable : 92% : very-strong : Complete Layer and 48-byte LayerNode declaration with exact 24 source-method children, one compiler scalar-wrapper disposition, Pane/HierList/Region relationships, callers, vtable, and UID0000KL owner/emitter route.`

Current UID0000KL in `by-file/-coverage-report.md` was read-only verified to match this exact externally completed B001 state:

`- [UID:0000KL][Layer](by-file/Layer.md) : reconstructable : 91% : very-strong : NexusTK/ui/core/Layer.cpp source root with declaration-first emission, exact positions 20-250 for 24 source methods, compiler-only scalar wrapper exclusion, complete layout/caller/source-order evidence, and no aggregate duplicate.`

Current UID00018W and directly relevant UID0004NW child in `by-memory/-coverage-report.md` were read-only verified to match this exact externally completed B001 split-index state and accepted child indentation:

`    - [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md) 0x004f0480-0x004f1bf6 | exact split index | Layer : ignored : 92% : very-strong : Exact non-emitting index over 25 code bodies: 24 Layer source methods and one compiler scalar deleting destructor; complete raw-body, layout, caller, vtable, padding, and source/compiler dispositions are documented.`

`        - [UID:0004NW][0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion](by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md) 0x004f0b40-0x004f0b79 | method | Layer::MarkAllPanesForDeletion : reconstructable : 91% : very-strong : Full top-level child-list traversal skips null/sentinel rows and null pane pointers, then calls Pane::MarkForDeletion; position 70.`

Add UID0004LY under the MainMenuPane family in `by-memory/-coverage-report.md`:

`        - [UID:0004LY][0x004f6700-0x004f6904.MainMenuPaneConstructor](by-memory/0x004f6700-0x004f6904.MainMenuPaneConstructor.md) 0x004f6700-0x004f6904 | constructor | MainMenuPane::MainMenuPane : reconstructable : 90% : very strong : Exact 0x204-byte constructor with 0x454 allocation callers, Pane/Singleton setup, g_pMainMenuPane publication relationship, menu/server/background fields, timer/music/input state, root-pane initialization, optional LEVEL.BMP decode, exact padding, and source-ready body.`

Replace the stale UID0002H8 row:

`        - [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md) 0x004f6490-0x004f66a5 | class method | Application::Shutdown : reconstructable : 90% : very strong : Exact second-stage shutdown method with phase/event/IME teardown, six layer detach/destroy order, delete of g_pMainMenuPane through its virtual destructor, image-library and late singleton cleanup, packet sender termination, CleanupResources tail, and source-ready formal body.`

Replace the stale UID0002HE row:

`        - [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md) 0x004a41c0-0x004a456b | constructor | EmployeeItemPropertyDialogPane::EmployeeItemPropertyDialogPane : reconstructable : 90% : very strong : Exact property-dialog constructor with owner/record fields, buttons and edit/text controls, price/name formatting, icon bounds, default/cancel/focus actions, overlay creation, g_pMainMenuPane show parent, and source-ready formal body.`

Replace the stale UID0002HH row:

`        - [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) 0x004a4770-0x004a4a25 | constructor | EmployeeQuantityInputDialogPane::EmployeeQuantityInputDialogPane : reconstructable : 89% : very strong : Exact quantity-dialog constructor with prompt/owner/index inputs, resource and control layout, focus/default/cancel actions, main UI layer context, g_pMainMenuPane show parent, and source-ready formal body.`

Add absent UID0004GL:

`        - [UID:0004GL][0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor](by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md) 0x004fb630-0x004fbfcf | constructor | NewUserMiscDialogPane::NewUserMiscDialogPane : reconstructable : 88% : very strong : Exact new-user appearance dialog constructor with singleton publication, shape/gender/style controls, random selection, resource/layout state, main UI context, g_pMainMenuPane show parent, and source-ready formal body.`

Replace UID00019Z:

`    - [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) 0x004ffaa0-0x004ffd3d | class method cluster | StaffsDialogPaneCore : reconstructable : 88% : very strong : Exact StaffsDialogPane constructor/action cluster with singleton, STAFF.EPF/NPAL8.PAL resources, STAFFS/STAFFS2 selection, controls, layer attachment, g_pMainMenuPane show parent, close action, boundaries, and source-ready formal body.`

Replace UID0001A2:

`    - [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) 0x00500090-0x0050040d | class method cluster | BackStoryDialogPaneCore : reconstructable : 88% : very strong : Exact retained story-dialog constructor/close-handler cluster with EPF/EPD branches, singleton/resources/controls, main UI context, g_pMainMenuPane show parent, source-ready formal body, and explicit indirect-reachability caveat.`

Replace UID0001A3:

`    - [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) 0x00500410-0x00500632 | class method cluster | NewHistoryDialogPaneCore : reconstructable : 87% : very strong : Exact history/credits dialog constructor and input-close handlers with HISTORYN resources, MADEBY scrolled text, singleton, main UI context, g_pMainMenuPane show parent, source-ready formal body, padding, and retained indirect-reachability caveat.`

Replace UID00022Y:

`    - [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) 0x00502e10-0x0050305c | packet helper function cluster | MainMenuAnsiTextDialogPacketHelpers : reconstructable : 87% : very strong : MainMenuPane-owned ANSI/URL alert helpers with screen-dimmer cleanup, subtype 1/2 URL/message decoding and g_pMainMenuPane parent, subtype 3 override-string update, exact bounds/callers, and source-ready formal body.`

Add absent UID00048Z:

`        - [UID:00048Z][0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor](by-memory/0x00588080-0x00588101.ForcedInformMessageDialogNonDeletingDestructor.md) 0x00588080-0x00588101 | destructor | ForcedInformMessageDialog::~ForcedInformMessageDialog : reconstructable : 89% : very strong : Exact ordinary destructor body with EPF/accepted/g_pMainMenuPane guard, EnsureLoginDialogPane restoration, singleton clear, compiler teardown exclusion, and source-ready formal body.`

Rows for Destinations 13-18 not replaced above were inspected. Where path, UID, status, score, and row summary remain accurate and do not contain the rejected identifier, no manual row text change is required. Generated tracker rows are validator-owned; no manual tracker edit is proposed.

## Follow-Up Actions

- B002 implementation, scoped validators, waited generation, generated readback, and lease release are complete for every B002-owned accepted destination.
- B001 UID00018W independently completed the `0x004f0b40` Layer body/declaration/source route at same-or-greater detail. Supervisor Gate 1/Gate 2 artifact verification, fresh commands `000000011303`-`000000011354`, and direct read-only destination/generated checks close the external dependency.
- Manual coverage remains supervisor-owned. The four Layer rows above were read-only confirmed current; UID0002AF callback coverage text remains exact external reconciliation material. Current/future Gate 2, execution, movement, archive, and lifecycle state are external and not asserted.
- No additional target begins from this callback.

## Confidence

- Applied completion/confidence is `93/94` for UID0002AF because every exact-storage, byte, section, adjacency, xref, writer/clear, type, lifetime, linkage, ownership, emission, source-placement, and generated-impact question is documented and verified.
- Applied UID00019K score is `93/94`; the complete 3,611-byte source operation is emitted. Stripped exact helper/member spellings and compiler-version-specific inline decisions remain the only source-confidence caps.
- The B001 Layer coordination dependency is cleared and does not limit target behavior, score, implementation completeness, or readiness for supervisor post-callback review.

## Validator Results

All commands below exited `0` with `ok:1`. Timestamps are `2026-07-14` America/New_York. Each ordinary page was leased immediately before editing and released after its final scoped validator.

| Command | Time | Scope | Warnings / validator-owned side effects |
| --- | --- | --- | --- |
| `000000011103` | `08:54:51-04:00` | UID0002AF rename, `--uid-only` | path/registry/score/code updates; generated skipped |
| `000000011107` | `08:56:04-04:00` | UID0000RF rename, `--uid-only` | path/owner/position/code updates; generated skipped |
| `000000011111` | `08:57:22-04:00` | `by-class/MainMenuPane.md` | score/hash/link/index updates; generated deferred |
| `000000011118` | `08:58:03-04:00` | UID0004LY | formal hash/ref-index update; generated deferred |
| `000000011122` | `09:02:28-04:00` | UID00019K | owner/score/position/code applied; pre-existing missing UID0003ZI warning |
| `000000011123` | `09:04:08-04:00` | UID0000UV | owner/FALSE/blank-emitter applied; two pre-existing UID0003ZI warnings |
| `000000011124` | `09:04:58-04:00` | `by-file/MainMenuPane.md` | confidence/link/index updates; generated deferred |
| `000000011129` | `09:06:07-04:00` | `by-file/MainUiGraph.md` | link/index updates; pre-existing UID0003ZI warning |
| `000000011132` | `09:07:07-04:00` | UID0002H8 | formal hash update; generated deferred |
| `000000011133` | `09:07:40-04:00` | UID0002HE | formal hash update; pre-existing UID0003KY warning |
| `000000011134` | `09:08:04-04:00` | UID0002HH | formal hash update; six pre-existing UID0003KT/UID0003KY warnings |
| `000000011135` | `09:08:38-04:00` | UID0004GL | formal hash update; generated deferred |
| `000000011136` | `09:09:15-04:00` | UID00019Z | formal hash update; generated deferred |
| `000000011137` | `09:09:54-04:00` | UID0001A2 | formal hash update; generated deferred |
| `000000011138` | `09:10:31-04:00` | UID0001A3 intermediate | formal hash update and two ref removals exposed an over-short prose edit |
| `000000011139` | `09:10:51-04:00` | UID0001A3 corrective final | restored UID0000CJ/UID0004MA detail and both reference-index rows |
| `000000011140` | `09:11:35-04:00` | UID00022Y | formal hash/index update; two pre-existing UID0003YP warnings |
| `000000011141` | `09:12:06-04:00` | UID00048Z | formal hash update; generated deferred |
| `000000011142` | `09:13:28-04:00` | BackStory file | no warning; generated deferred |
| `000000011143` | `09:13:54-04:00` | BackStory class | no warning; generated deferred |
| `000000011144` | `09:14:39-04:00` | Employee file | 20 pre-existing missing legacy UID warnings; `ok:1` |
| `000000011145` | `09:15:10-04:00` | EmployeeItemProperty class | six pre-existing UID0003L5 warnings; `ok:1` |
| `000000011146` | `09:15:37-04:00` | ForcedInform file | no warning; generated deferred |
| `000000011147` | `09:16:03-04:00` | ForcedInform class | no warning; generated deferred |
| `000000011148` | `09:16:42-04:00` | NewHistory file | no warning; generated deferred |
| `000000011154` | `09:17:46-04:00` | NewHistory class | four validator-owned generated stats-row refreshes |
| `000000011162` | `09:18:27-04:00` | Staffs file | no warning; generated deferred |
| `000000011170` | `09:19:00-04:00` | Staffs class | one validator-owned generated stats-row refresh |
| `000000011175` | `09:19:41-04:00` | UID00019J | no warning; generated deferred |
| `000000011176` | `09:20:19-04:00` | UID0002Q3 | no warning; generated deferred |
| `000000011180` | `09:21:28-04:00` | UID0002Q4 | UID00019K link/index normalization; generated deferred |
| `000000011187` | `09:22:16-04:00` | UID0001J7 | pre-existing UID0003KG warning; validator inserted now-registered UID0003KH link |
| `000000011192` | `09:23:04-04:00` | UID0001JA | no warning; generated deferred |
| `000000011198` | `09:23:50-04:00` | UID00018G | UID0000RF reference-index add; generated deferred |
| `000000011205` | `09:24:49-04:00` | UID0002AE | no warning; generated deferred |
| `000000011211` | `09:25:30-04:00` | UID0001PV | no warning; generated deferred |
| `000000011212` | `09:26:23-04:00` | UID0002AF final prose | owner/file reference-index adds; generated deferred |
| `000000011213` | `09:27:14-04:00` | UID0000RF intermediate | link/index normalization exposed removed UID0000T6 reference |
| `000000011214` | `09:27:42-04:00` | UID0000RF corrective final | restored explicit UID0000T6 support reference |
| `000000011217` | `09:28:56-04:00` | UID0002AF `--wait-generated` | generated refresh completed; global project warnings: 15 fallback inserts, 84 missing child markers, 192 no-code emitters; validator-owned Layer.cpp refresh from concurrent external work |

- External dependency clearance used the supervisor's exact B001 Gate-1/Gate-2-passed implementation artifact SHA256 `FBFF647ED2578F9F04B582ED13CBEB6CEAF0AD7ADAF24C75D481142B3798E82E`. Fresh supervisor validators `000000011303`-`000000011354` all exited `0` with `ok:1`; final command `000000011354` validated `by-file/Layer.md` and generated `Layer.cpp` SHA256 `2E3F94954F4CB57977F4C0793D60B5A374E6988431C6692C79509D670FB825BE` with one LayerNode/class, one definition of every checked source method, and no aggregate/scalar/empty-marker artifact.
- Clearance-time B002 read-only verification made no edit and ran no validator. UID0004NW is `91/94`, owner/emitter UID000073, position `70`, and contains the exact count/index/node/pane/`MarkForDeletion` body; UID000073 is `92/94`, position `10`, and declares `void MarkAllPanesForDeletion();`; UID0000KL is `91/93` and records `NexusTK/ui/core/Layer.cpp`. An initial clearance read observed `Layer.cpp` SHA256 `299C497960B95634A3BB3A60DD72FB8CCCF517C0795FCE5A17293EFA6A8BF78A`; the `2026-07-14T10:29:51.5328262-04:00` snapshot observed SHA256 `FA928FD7596882BA00368D4A871DEE35DD212120C422B052185725660F64542B`. Both contain one declaration, one definition, one UID0004NW marker, and zero UID0004NW Empty Emitter Markers. Hash changes after command `000000011354` are validator-owned refreshes; the dependency assertions are stable.
- Command `000000011217` generated `NexusTK/login/MainMenuPane.cpp` SHA256 `8ED21B041ABF9706C845BABB0FBE4DD49FE25F8BCFBEE127726BA1ADB70328EB`; clearance-time read-only SHA256 was `5225AAB7A89DEF9CCD4DC7FDBAE946BD34858F9130C6E3D9201FA954859A3536`.
- Exact counts: one `MainMenuPane *g_pMainMenuPane = NULL;`, one MainMenuPane class, one `InitializeMainUiGraph` declaration, one UID00019K method, one marker each for UID0000RF/UID0002AF/UID00019K, zero target/method Empty Emitter Markers, zero scalar/vtable/RTTI markers, and zero `g_pMainUiGraph` hits.
- Command-time generated `NexusTK/ui/MainUiGraph.cpp` SHA256: `E69447E3B99E42845B21603E89E841F4243B0F73FC8D4FF6757B9B625AC9AFC2`; initial read-only handoff SHA256: `E1A2CB0B4229F12C79E5F9F78F9D05099EF22B23FBB9DD5818D3EC19D63DDF85`; clearance-time read-only SHA256: `EB16EE28DFFA92FAE51DA250BADAC64F83335D8AA6898FCD25BBBF2372708FA9`. UID0002AF, UID0000RF, old-name, and new-name counts are zero in all snapshots.
- Recursive generated C++ search found zero `g_pMainUiGraph` identifiers. All formal Destination 1-6 and 9-17 blocks compare exactly to this report; Destination 7 is blank as accepted.
- No report lifecycle/probe/execute/move/archive command or IDA write was run. Mandatory MCP evidence remains evidence-time database `1feab207`; no callback IDA mutation was needed.

## Changed Files

- UID-preserving renames: `by-memory/0x0067aba4-0x0067aba8.g_pMainUiGraph.md` -> `by-memory/0x0067aba4-0x0067aba8.g_pMainMenuPane.md`; `by-global/g_pMainUiGraph.md` -> `by-global/g_pMainMenuPane.md`.
- Core/source pages: `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, UID0004LY, UID00019K, UID0000UV, and `by-file/MainUiGraph.md`.
- Exact old-name formal emitters: UID0002H8, UID0002HE, UID0002HH, UID0004GL, UID00019Z, UID0001A2, UID0001A3, UID00022Y, and UID00048Z.
- Non-emitting prose/support: BackStory file/class, Employee file/EmployeeItemProperty class, ForcedInform file/class, NewHistory file/class, Staffs file/class, UID00019J, UID0002Q3, UID0002Q4, UID0001J7, UID0001JA, UID00018G, UID0002AE, and UID0001PV.
- External read-only completion dependencies, changed by B001 rather than B002: UID0004NW `by-memory/0x004f0b40-0x004f0b79.LayerMarkAllPanesForDeletion.md`, UID000073 `by-class/Layer.md`, and UID0000KL `by-file/Layer.md`. B002 read these pages and generated Layer.cpp only after supervisor clearance.
- This report was updated additively. Validator-owned generated/index/stats files changed only through the authorized scoped validators and waited refresh; none was edited manually.
- During this dependency-clearance repair, only this B002 report changed. Manual coverage, generated/tracker/audit/supervisor/goal/lifecycle/IDA files, target/support ordinary pages, and the three B001-owned Layer pages were not edited; no validator or report execution/move/archive command was run.
- Every B002 lease command returned success, every lease was released after its page's final validator, and final `current_leases.md` contained no B002 lease.

## Implementation Tracking Checklist

Historical report-only self-review:

- [x] Read current B002 goal and complete project workflow/template/score standards.
- [x] Obtained a fresh MCP session after supervisor restart and passed `idb_list`, `server_health`, target lookup, and target bytes.
- [x] Verified exact bytes/hash/section/alignment/zero-fill/relocation and adjacent boundaries.
- [x] Accounted for all 31 refs across 26 modeled functions plus the unmodeled WndProc fragment.
- [x] Resolved constructor/destructor/clear/lifetime/null/type/name/linkage/source placement.
- [x] Revalidated UID00019K receiver/source operation and UID0000UV alias disposition.
- [x] Reconstructed UID00019K through all 39 direct callees, 139 attributed blocks, both layout branches, exact common tail, 33 cleanup funclets, UserPane pool unwind, and C++ frame/cookie support.
- [x] Confirmed Destination 6 is complete human-written C++ with no raw labels, decompiler temporaries, manual vtable calls, allocation-null scaffolding, EH state, funclets, or artifact return.
- [x] Resolved `0x004f0b40` as the Layer full-child-list `Pane::MarkForDeletion` helper and recorded the bounded declaration/prose dependency without adding a second source body.
- [x] Searched and classified active, central executed, Older-Research, archived, and SpecialReports roots using the exact term list.
- [x] Inspected current generated output and every affected manual coverage row read-only.
- [x] Ledger Action cells use only `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, and `not-applicable`.
- [x] Every report-only Verification state was exactly `proposed` in the Gate-1 artifact; current callback states use only the authorized final vocabulary.
- [x] Every source-bearing destination has complete managed formal insertion text; by-file roots remain prose-only.
- [x] No by-* edit, lease, implementation validator, IDA write, generated/coverage/tracker/audit/lifecycle edit, execute_report, probe, move, archive, or subagent occurred during the historical report-only phase.

Implementation callback:

- [x] Confirmed supervisor Gate 1 acceptance of exact SHA `13BC2BC7E98452AEA4EC47BDF364D4F504C87479D2C27B4409E7F013FD9D8DBA`.
- [x] Re-read every Destination 1-18 page and concurrent lease/goal state before edits.
- [x] Completed UID-preserving target/global renames without UID or link loss.
- [x] Applied target/global metadata, nesting/position, exact formal blocks, and report-level evidence.
- [x] Applied UID0000L0/UID00007O/UID00019K/UID0000UV/UID0000L1 ownership and source-operation corrections.
- [x] Applied Destinations 5 and 9-17 byte-for-byte except the accepted identifier change; final comparison is exact to this report.
- [x] Applied every non-Layer Destination 18 prose/history/link synchronization and preserved `0x0069b36c` separation.
- [x] Verified supervisor-cleared B001 same-or-greater incorporation on UID0004NW/UID000073/UID0000KL and generated command `000000011354`; B002 did not lease or edit those pages.
- [x] Leased one ordinary page at a time, scoped-validated it, and released it before proceeding.
- [x] Kept all ledger Actions/states in the authorized vocabularies.
- [x] Ran final waited refresh `000000011217` and recorded global warnings/side effects.
- [x] Verified MainMenuPane.cpp exact target/global/class/method counts and address order with no Empty Emitter Marker.
- [x] Verified MainUiGraph.cpp has no UID0000RF/UID0002AF ownership marker.
- [x] Verified recursive generated C++ has zero `g_pMainUiGraph` identifiers.
- [x] Verified no duplicate definition, compatibility alias, handwritten Singleton clear, scalar deleting destructor, or vtable/ABI object.
- [x] Recorded command IDs/timestamps/results/warnings/side effects, changed files, hashes/counts, and lease proof.
- [x] Left supervisor-owned coverage/tracker/audit/lifecycle/report execution/move/archive state untouched.
- [x] Recorded the supervisor's exact B001 Gate 1/Gate 2 artifact SHA, validator range, generated proof, and direct read-only destination proof; the external Layer dependency is cleared.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000011439","destination_path":"executed-b-agent-research/B002/0002AF-g_pMainUiGraph-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002AF-g_pMainUiGraph-source-quality.md","timestamp":"2026-07-14T11:00:51-04:00","uid":"0002AF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
