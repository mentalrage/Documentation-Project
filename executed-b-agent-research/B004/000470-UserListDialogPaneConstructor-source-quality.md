** TARGET-REPORT-UID:000470 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 000470 UserListDialogPaneConstructor Ownership / Split Research


## Finalized Report / Current Recommendation

- Current callback result: [UID:000470] is the one source-authored `UserListDialogPane::UserListDialogPane(const unsigned char *packet)` body over exact half-open range `0x0059bc90-0x0059d198`; it now emits through [UID:0000OZ] `UserListDialogPane`, retains owner [UID:0000FN], `RECONSTRUCTABLE:TRUE`, `Nested:0`, and blank emitter position, and is `93/94`.
- Final disposition applied: the stale blank-emitter/no-code rationale was replaced by exact managed Destination 1. The interval remains one constructor and needed no source-bearing split. The following `0x0059d198-0x0059d1e0` cleanup interval and `0x0059d1e0-0x0059d1e3` nullsub remain separate non-source children.
- Implementation result: C01-C46 and Destinations 1-9 are incorporated across the accepted target/support set. Complete `UserListDialogPane`/`UserListPane` declarations, bounded control/accessor declarations, corrected UID000479, renamed/reclassified UID00047S, semantic/physical Singleton storage, parent index, and file route are synchronized and scoped-validated.
- Confidence: very strong for the exact boundary, callers, ABI, branches, packet cursor, controls, resources, row layout, list behavior, direct bases, object fields, cleanup split, and source file; strong but below final-original-source certainty for several descriptive member/helper spellings.

## Supporting Research

- Live evidence-time MCP state: at `2026-07-14T22:40:52-04:00`, streamable MCP transport session `211650be-e5c3-4ff8-b15b-6229ee56ac74` returned one active NexusTK IDB database `0cf42e97`, worker PID `8808`, `is_analyzing:false`. `server_health(database='0cf42e97')` returned `status:ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, string cache ready, and cache size `2067`. A bounded recheck at `2026-07-14T22:51:51-04:00` rediscovered the same database, returned the same ready health state, and decompiled the target through fresh HTTP transport session `5e7aeea1-fca3-43a5-a15e-126df1446b4d`; a following fresh transport call decompiled UID000473 from the same database. These are evidence-time facts, not an indefinite availability assertion.
- Target MCP checks: `lookup_funcs` returned `sub_59BC90` size `0x1508`, no function at exclusive end `0x0059d198`, `nullsub_61` size `0x3` at `0x0059d1e0`, and `sub_59E710` size `0x189`. `analyze_function(0x0059bc90)` returned 5,384 bytes, 1,676 instructions from the paged disassembly audit, 213 basic blocks, cyclomatic complexity 43, 43 distinct callee identities, and four callers.
- Exact target-byte SHA-256 from the evidence-time MCP byte read over `[0x0059bc90,0x0059d198)` is `AEA719C39B3BFE89A1350E726FF6E770BCDC9947AB86643F52CE0BB9DF35491A`.
- Historical pre-callback generated lead: `auto-generated/NexusTK/social/UserListDialogPane.cpp`, SHA-256 `E6EC10DFFD16054C16A6025A4C46CB60322E86B862E2AFE20EE8C6C42D12C3AC`, 211 PowerShell-counted lines, validator command `000000012445`, refreshed `2026-07-14T22:36:28-04:00`. It had no UID000470 body, an incomplete one-base class, a stale one-argument UID000479 body, and a handwritten UID00047S clear helper; it remains historical lead evidence only.
- Callback generated readback: waited validator `000000012502`, timestamp `2026-07-14T23:20:13-04:00`, produced `auto-generated/NexusTK/social/UserListDialogPane.cpp`, SHA-256 `ED78D444FE27D5A67CAEFB377CEA421303F2F23725B79B287AE4279DC5287F9E`, 608 PowerShell-counted lines. It has one UID000470 marker/body, one corrected UID000479 body, one complete UserListDialogPane declaration, one complete UserListPane declaration, zero target Empty Emitter Markers, zero UID00047S marker/body, zero old singleton-helper/member/PartySearch forms, zero explicit vptr/cookie/delete source, 16 unique UID markers with no duplicates, and balanced braces `35/35`.
- Executed report search terms were `UID000470`, `0x0059bc90`, `0x0059d198`, `UserListDialogPaneConstructor`, `UserListDialogPane`, `UserListPane`, `UID0000FN`, `UID0001KI`, `UID00047B`, `UID00047L`, `UID00047M`, `g_pUserListDialogPane`, `Singleton<UserListDialogPane>`, `hunters list`, and owner/source-family aliases.
- `executed-b-agent-research/B001/0000FN-UserListDialogPane-class-source-quality.md`, SHA-256 `DCA937B09E8F38368A74C7BF11251D7A63E24089CA4AD8C614A4C9794AC8F124`, was opened. Its packet offsets, fixed `0x414` row, resources, helper names, hunters-list semantics, comparators, and source route remain useful. Its single-base class, `void *` master list, fake padding/member helpers, one-argument command callback, and incomplete constructor model are superseded by current RTTI and decompilation.
- `executed-b-agent-research/B002/0001KI-UserListDialogPaneAndUserListPane-source-quality.md`, SHA-256 `2290B2A2277B8A582C14612FA47D2B19C03E49C9496ED98A0B95A60D20329C1B`, was opened. Its exact split inventory, parent non-emitting status, child paths, and no-route taxonomy remain valid. Its UID000470 blank-C++ deferral is superseded because this pass resolves the missing class/control/list model.
- `executed-b-agent-research/B004/00047B-UserListDialogPaneLocalSourceUpdateSendHelperRaw-source-quality.md`, SHA-256 `DA38727FF3B326C04DAE7167802B28393CC7F6C2F6226BD70FDFEAA527A66CD9`, was opened. Current target research does not create an inbound route to `0x0059dc20`; preserve its no-owner/non-emitting decision.
- `executed-b-agent-research/B005/00047L-UserListPaneSortByStatusNoRouteWrapper-source-quality.md`, SHA-256 `581B4FB8F94D38D30E9F5A34165F899DAE19C9D46B4F999AC50E6942EF86C8CD`, and `executed-b-agent-research/B006/00047M-UserListPaneSortByNameNoRouteWrapper-source-quality.md`, SHA-256 `AA5B5354E7B627D4A246391767CD4A40701D090D7CAC67795363F77933658D09`, were opened. The constructor's direct/inlined sorting does not create a caller to either retained wrapper; preserve both no-route decisions and exact boundaries.
- `tools/leaser/Agents/Older-Research` contained three Markdown files and no match for the exact UID/address/name/source-family terms. `tools/leaser/Agents/SpecialReports` contained five Markdown files and no direct match. Agent goal/report roots were searched at evidence-collection time; no second UID000470 report or target assignment was active when searched. The actual project archive root `project-documentation/archived` contained zero Markdown reports, so it provided no direct prior report. These per-root negative results support the exact target's zero-report premise.
- Wave2/Wave3 text encountered in current docs and old reports was treated only as historical provenance. It was not used to override current MCP, current by-* docs, executed reports, or current generated output.

## Target

- Target UID: `000470`.
- Target path: `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md`.
- Historical pre-callback source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`; current tracker state is validator-owned and is not asserted here.
- Historical pre-report classification: exact source-authored constructor child with zero registered target reports before this artifact and a blank emitter/body.
- Current callback state: target `93/94`, owner `0000FN`, reconstructable true, emitter `0000OZ`, blank position, exact Destination 1 formal C++, and `Nested:0`; parent [UID:0001KI] remains `90/91`, non-reconstructable, non-emitting, and formally blank under [UID:0000OZ].

## Current Target State

- Applied target metadata: exact title/range, owner [UID:0000FN], emitter [UID:0000OZ], reconstructable state, blank position, `Nested:0`, `93/94`, item summary, and exact Destination 1 are current.
- Applied declaration/support state: `UserListDialogPane` is `92/93`, `UserListPane` is `91/92`, RadioGroup is `90/91`, CheckBoxText is `90/92`, GameServerConfig is `91/92`, DialogPane remains `90/92`, UID000479 is `90/92`, UID00047S is `92/95` false/non-emitting at its renamed path, semantic global is `90/94`, physical storage is `90/95` false/non-emitting, and by-file is `91/92`.
- Superseded state: the prior blank target block, incomplete class/list layouts, one-argument callback, invented control members, handwritten singleton clear helper, stale `ff ff ff ff` storage summary, and failed-gate language are retained only as historical/rejected evidence.
- Resolved blockers: exact one-argument packet signature; direct `Singleton<UserListDialogPane>` base and EBO; complete `0x28c` class tail; complete `0x49c` `UserListPane`; five list panes; exact high/legacy controls; packet fields and cursor; branch-specific row assignments; source/list API shape; global/template disposition; EH cleanup split; and source order.
- Related target/support docs checked: UID0001KI, UID0000FN, UID0000FO, UID0000OZ, UID000471/472/473/474/475/477/478/479, UID00047B/L/M/S, UID000022, UID0000BI, UID00003T, UID00005O, UID0003EI, UID0002WD, `List`, `ListPane`, `ProtectedArray`, `UserPane`, `EPFImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, `ScrollableControlPane`, `MainUiLayerSlots`, `g_bShowHuntersListOnly`, and current generated `UserListDialogPane.cpp`.
- Current artifact/lifecycle boundary: implementation, scoped validators, lease release, and generated readback are complete. B004 performed no report execution, lifecycle, probe, count, move, or archive operation. Report validation/execution/count/path/move/archive state remains external supervisor/validator-owned state and is authoritative only in external audit/history, not asserted by this artifact.

## Executive Recommendation

- UID000470 remains one source-bearing constructor; no EPF/EPD or packet-loop split was introduced because both branches share one entry, return, EH graph, and constructor ABI.
- `EMITTER_UIDS:0000OZ`, blank position, owner `0000FN`, `RECONSTRUCTABLE:TRUE`, `Nested:0`, and `93/94` are applied.
- The class declaration now uses direct bases `Singleton<UserListDialogPane>, DialogPane`, the exact `0x26c-0x28c` tail, `List *m_allUserRecords`, the corrected callback signature, and a class close before `[[CHILDREN]]`.
- `UserListPane` now declares the exact `0x14c` base boundary, 4/16/1 `EPFTileContext` arrays, sibling pointer/count at `+0x494/+0x498`, and complete `0x49c` size without absorbing separate child bodies.
- UID000479 now uses `OnControlCommand(int controlIndex, int notifyCode)` and child lookup. UID00047S was UID-preservingly renamed/reclassified as generated `Singleton<UserListDialogPane>` destructor support with blank formal C++.
- UID00047B, UID00047L, and UID00047M remain no-owner/non-emitting; implementation introduced no route to those retained raw helpers.

## Supervisor Active Recheck

- Historical trigger: the B004 report-only goal assigned direct target UID000470 and required the blank/no-code rationale to be exhausted rather than repeated; exact artifact SHA `520F64256F1C27395C140278AA4D80A9AC889ACC82873297508F1FBC03B397E9` then passed supervisor Gate 1.
- Applied split result: the prior B002 split remains structurally valid. This callback corrected UID000470 and UID00047S without creating a new range child.
- Applied source-bearing result: UID000470 emits, and UID000479 has the bounded signature/body correction. No accepted implementation item remains deferred.
- Non-source children: UID000471, UID000472, UID000476, UID00047A, UID00047T, UID00047V, and renamed UID00047S remain non-emitting for explicit compiler/no-op/table/template-support reasons.

## Inference Research Guidance Check

- The evidence ladder was applied in order: current IDB function/byte/range facts; current decompile/disassembly/xrefs/RTTI; current docs; exact executed reports as leads; current generated output; manual coverage; then descriptive source inference.
- Existing documentation was treated as uncertain where it used a one-base class, fake member helpers, a `void *` list, a one-argument callback, a standalone singleton-clear helper, stale zero/no-code thresholds, or unqualified generated names.
- Direct IDA facts are labeled as exact addresses, bytes, offsets, calls, stores, branches, xrefs, RTTI records, and resource operands. Source spellings such as `m_selectedNationId`, `m_categoryPage`, `m_statusIconFrames`, `GetNationEntryAtOrDefault`, and `overlayPaneLayerContext` are descriptive/inferred and are confidence caps.
- No Wave2/Wave3 artifact was accepted as current authority. Historical mentions were retained only to explain superseded assumptions.

## Heuristic / Inference Reanalysis And Validation

- Function signature: IDA's `_DWORD *__fastcall(_DWORD *, int, int)` is rejected. Four callers allocate/pass a `0x28c` object and one explicit packet pointer; target ends `retn 4`. Best source signature is `explicit UserListDialogPane(const unsigned char *packet)`.
- Constructor boundary: function object `0x0059bc90` size `0x1508` ends exactly at `0x0059d198`. Eight `0xcc` bytes start there before cleanup code at `0x0059d1a0`; this is not part of handwritten body text. Splitting the high/low branches is rejected.
- Direct bases: the constructor publishes the singleton before the `DialogPane` base call. RTTI COL `0x00651c68`, CHD `0x00651c7c`, base array `0x00651c8c`, self BCD `0x00651cb0`, and direct Singleton BCD `0x00651ccc` identify `.?AV?$Singleton@VUserListDialogPane@@@@` and PMD `mdisp=0x26c,pdisp=-1,vdisp=0`. Best declaration order is `Singleton<UserListDialogPane>` then `DialogPane`; a manual global assignment is rejected because it would duplicate the inlined base constructor.
- EBO/member layout: empty Singleton state overlaps the first derived short at `+0x26c`. Fields are selected nation table index `+0x26c`, nation page `+0x26e`, local career variant `+0x270`, natural two-byte alignment, five `UserListPane *` at `+0x274..+0x284`, and `List *` at `+0x288`; complete size is `0x28c`.
- UserListPane type: constructor `0x0059e710` calls `ListPane(recordSize,pageSize,108,12,0,1,1)`, begins derived state at `+0x14c`, constructs four 40-byte contexts, sixteen 40-byte contexts, one 40-byte context, then stores sibling pointer/count at `+0x494/+0x498`. The old incomplete-type blocker is resolved by a complete `0x49c` declaration.
- Packet header: `packet+1` is a big-endian reported/display count basis, `+3` is entry count, `+5` is initial sort selector, and `+6` starts records. Naming `+1` as an exact server-global total is rejected because the binary only proves its displayed-count use.
- New/EPF row header: four bytes map to career/bucket, status/badge, careerVariant/huntersListFlag, and displayColor. Reserved byte `+2` is zero. Arrival key is `100000-ordinal`. `hasSourceText` is zero; `sourceText` is not initialized. Local-name match writes display color `0x80` and captures career variant; absent that expected match, the member has no independent initialization in this constructor.
- Legacy/EPD row header: exactly three bytes map to career/bucket, status/badge, and displayColor. It deliberately does not initialize hunters-list flag, source flag/text, or career variant. It also does not initialize `m_selectedCareerVariant`. Adding zero initialization is rejected because it changes observed branch behavior.
- Name conversion: one unsigned-byte length, exact-byte copy into `char[256]`, explicit narrow terminator, `MultiByteToWideChar(CP_ACP,0,source,length,destination,256)`, and explicit wide terminator at returned count. `SimpleUString` is rejected for packet names because the binary directly proves fixed stack buffers and Win32 conversion.
- Master list: `new List(sizeof(UserListRecord),100)` at `+0x288`; records append through the generic list virtual `Append(1,&record)`. Generic `List` owns bytes, not per-row dynamic payloads.
- Filter: append predicate remains `record.reserved2 == 0 || playerSettingsFlag == 1`, even though constructor writes `reserved2=0`. The apparently dead branch and filtered counter are retained because removing them changes source evidence and may erase build/config history.
- New branch distribution: apply hunters-only filter first, then special nation id `10`/career-variant or ordinary career-id match; bucket `1..4` maps to panes `0..3`, bucket `0` maps to pane `4`. No bounds clamp exists.
- Legacy branch distribution: no global hunters-only filter and no bucket-zero route; immediately append only matching records with nonzero bucket. Preserve the special-id comparison over branch-uninitialized career variant/member state.
- Sorting: initial selector `0` uses status comparator, `1` uses name comparator, other values sort neither. Each bucket count label is created after sorting.
- Control model: EPF creates 22 controls indexed `0..21`; EPD creates 19 indexed `0..18`. The target relies on insertion order, and UID000479 later retrieves controls `3` and `21`; invented `m_sortControl` and `m_huntersListOnlyCheckBox` fields are rejected.
- Dialog API: live target call `0x0049db60` receives `(L"US",0)`, proving `SetBackgroundResource(const wchar_t *, short frameIndex)`, not the current palette-string second argument.
- OnControlCommand: the vtable/base contract is two `int` arguments. The second is ignored. Case 1 calls `SlideCloseVertical` then `BlackHole::QueuePaneForDeferredDeletion`; case 3 reads RadioGroup selected index; case 20 constructs parameterless `PartySearchEditPane`; case 21 toggles control 21. The former formal body was contradicted; Destination 8 replaced it with the accepted current body.
- Singleton clear support: `0x0059efe0` is an 11-byte function with no ordinary caller and one code xref from constructor EH cleanup at `0x00609f1c`. Combined with direct Singleton RTTI and inlined publication, it is source-declared/generated-binary template destructor support, not a handwritten `ClearUserListDialogPaneSingleton` helper.
- Global slot: `0x0069b4e0` is zero-filled, has twelve lifecycle/consumer refs, and represents the Singleton specialization's backing pointer. Preserve semantic alias `g_pUserListDialogPane` in documentation, but do not add a second standalone definition from this callback.
- Rejected ownership alternatives: `UserPane`/`LivingObjectPane` are packet callers; `DialogPane` and control modules are dependencies; `UserListPane` owns only repeated list controls; no generic packet/config/map file owns the dialog constructor.
- Remaining source-name uncertainty: original lexical spellings for nation/page fields, frame arrays, record fields, and inline accessors are not recoverable from stripped symbols. The proposed names are behavior-specific and consistent with accepted project vocabulary; this caps confidence at 94 but does not block source.

## Evidence Standards Used

- IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, paged disassembly, raw bytes, xrefs, callers/callees, RTTI/COL/CHD/base descriptors, globals, and resource operands.
- Binary context: exact half-open target bytes and SHA-256, five-byte predecessor `0xcc`, exact target epilogue, eight-byte successor `0xcc`, cleanup/nullsub successors, stack frame, `retn 4`, and EH cleanup references.
- Documentation: current target/parent/class/file/global/storage/control/container docs; exact split children; executed reports; generated source read-only; manual coverage rows read-only.
- Negative evidence: no function at target end, no second target entry, no constructor-body split, no incoming constructor route to retained UID00047B/47L/47M wrappers, no ordinary caller to UID00047S, no standalone source requirement for compiler vptr/EH/cookie/delete behavior, no direct prior exact target report.
- Strength: direct range/ABI/RTTI/caller/control/packet evidence is sufficient for implementation-ready source. Exact original spellings and legacy uninitialized intent remain confidence caps.

## Evidence Checked

- IDA MCP/manual checks: evidence-time database `0cf42e97`; health; target/start/end/successor lookups; target analyze/decompile/disassembly/raw bytes; caller sites `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, `0x005abc54`; `UserListPane` decompile; UID000479 decompile; UID00047S decompile/disassembly/xref; singleton/flag xrefs; resources; RTTI `0x00651c68-0x00651ccc`; exact vtable/base/member stores; conversion/list/control callees.
- Docs opened at evidence-collection time: target, parent, class/file owners, UserListPane, OnControlCommand, singleton global/storage, DialogPane, RadioGroup, CheckBoxText, GameServerConfig, ProtectedArray, List/ListPane, UserPane, controls, MainUiLayerSlots, relevant sibling children, generated source, and all affected manual coverage files.
- Prior-report roots and terms: exact terms listed under Supporting Research were searched in `executed-b-agent-research`, `tools/leaser/Agents/Older-Research`, `tools/leaser/Agents/SpecialReports`, active Agent report/goal roots, and actual `project-documentation/archived`. Exact matching executed paths and findings are listed above; other roots returned no direct report.
- Negative checks at evidence-collection time: no direct exact report outside the five executed leads; no assignment/lease collision then active for UID000470; no Markdown in actual archive root; no function at `0x0059d198`; no ordinary UID00047S caller; no target caller beyond the four listed; no route change for UID00047B/L/M.
- Failed/unavailable checks: the first PowerShell HTTP attempt omitted `-UseBasicParsing`, and the first argument-construction retry serialized the arguments incorrectly. Both were local client invocation errors; subsequent bounded `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, and `decompile` calls succeeded on the same listener/worker. No fallback-only evidence was used.
- Focused final source-shape recheck: fresh target decompilation reconfirmed that the EPF branch calls `UserStatusPane::GetNationId` at `0x0059be29` but does not consume its return before storing nation-table count minus one at `this+0x26c`; the EPD branch repeats that exact discarded-getter/default-last-entry shape with `OldUserStatusPane::GetNationId`. Fresh UID000473 decompilation independently reconfirmed `this+0x26e` as the clamped category page and `this+0x26c` as the selected nation/category value. The formal body intentionally preserves the apparently redundant getter calls instead of simplifying them away.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID000470 is exactly `[0x0059bc90,0x0059d198)`, one 5,384-byte constructor. | very high | Target range/body retained; validator `000000012484` exit 0/ok 1; generated UID marker/body exactly once. | target | incorporate | applied |
| C02 | Exact target-byte SHA-256 is `AEA719C39B3BFE89A1350E726FF6E770BCDC9947AB86643F52CE0BB9DF35491A`. | very high | Exact evidence-time byte hash retained in target Evidence and this report; no IDA mutation. | target evidence | incorporate | applied |
| C03 | Source signature is `explicit UserListDialogPane(const unsigned char *packet)`. | high | Exact Destination 1 and class declaration; validators `000000012484`/`000000012487`; generated definition/declaration each present once. | target/class | incorporate | applied |
| C04 | Parent UID0001KI remains a false/non-emitting split index; no new target split. | very high | Parent stayed `90/91`, false, blank emitter/formal, Nested 0; validator `000000012500`. | parent/file | already-present | already-present |
| C05 | Direct base order is Singleton then DialogPane; publication is base behavior. | very high | Exact target/class blocks and RTTI/EBO evidence applied; validators `000000012484`/`000000012487`; no manual global assignment. | class/target | incorporate | applied |
| C06 | Complete dialog object is `0x28c` with exact `+0x26c..+0x288` tail. | very high | UserListDialogPane complete tail applied at `92/93`; target layout evidence retained; validator `000000012487`. | class/target | incorporate | applied |
| C07 | Target owner remains UID0000FN and emitter becomes UID0000OZ; position remains blank. | very high | Header now owner `0000FN`, emitter `0000OZ`, blank position; validator `000000012484`. | target | incorporate | applied |
| C08 | Target score becomes `93/94`, reconstructable true, Nested 0. | high | Header/item state applied and scoped validator recorded completion/confidence updates. | target | incorporate | applied |
| C09 | EPF branch uses `USERLIST.EPF`/`USERLIST.PAL`, 709x452, 22 controls. | very high | Exact Destination 1 and target behavior detail; validator `000000012484`; generated body readback. | target | incorporate | applied |
| C10 | EPD branch uses `USERLIST.EPD`/`USERLIST.PAD`, 635x390, 19 controls. | very high | Exact Destination 1 and target behavior detail; validator `000000012484`; generated body readback. | target | incorporate | applied |
| C11 | Packet header is word +1, word +3, sort +5, rows +6. | very high | Exact reads and cursor preserved in Destination 1/target evidence; generated readback confirms body. | target/class | incorporate | applied |
| C12 | EPF row header is four bytes with careerVariant/hunters flag assignments. | very high | Four-byte EPF parse and field semantics preserved in exact target body/detail. | target/class | incorporate | applied |
| C13 | EPD row header is three bytes and omits four later-field initializations. | very high | Three-byte legacy parse and omission list preserved in exact target body/detail. | target/class | incorporate | applied |
| C14 | Legacy uninitialized fields/member are preserved, not normalized. | very high | Target explicitly documents and emits no invented initialization; generated Destination 1 matches exactly. | target | incorporate | applied |
| C15 | Names use fixed 256-byte narrow and 256-wide buffers plus direct conversion. | very high | `char[256]`, wide record buffer, `memmove`, terminators, and `MultiByteToWideChar` applied exactly. | target | incorporate | applied |
| C16 | Local name is copied with `GetLocalPlayerName(...,128)`; EPF match sets color/variant. | very high | Exact body and target evidence applied; generated readback preserves both operations. | target | incorporate | applied |
| C17 | Master storage is `List(sizeof(UserListRecord),100)` and generic append. | very high | Target body and class `List *m_allUserRecords` applied; validators `000000012484`/`000000012487`. | target/class | incorporate | applied |
| C18 | Reserved-byte/player-settings append predicate and filtered counter remain exact. | very high | Predicate/counter preserved verbatim in Destination 1 and behavior detail. | target | incorporate | applied |
| C19 | EPF and EPD bucket distribution differ exactly as documented. | very high | Both distinct distribution loops retained, including bucket-zero and filter differences. | target | incorporate | applied |
| C20 | Sort selector 0/status, 1/name, other/no-sort is exact. | very high | Exact conditional sort surface retained; no default sort invented. | target | incorporate | applied |
| C21 | Five counts, displayed total, and visible sum use exact branch rectangles. | very high | Both branch-specific count loops/labels retained in target body and detail. | target | incorporate | applied |
| C22 | EPF control order/rectangles/ids/checkboxes are exact. | very high | Destination 1 applied exactly; control order supports UID000479 child indexes. | target | incorporate | applied |
| C23 | EPD control order/rectangles/ids and absence of checkboxes are exact. | very high | Destination 1 applied exactly without EPF-only checkbox insertion. | target | incorporate | applied |
| C24 | Final setup is background `US`, focus/pending/hover 1, mode 1, OnCreate/OnShow/slide. | very high | Exact final sequence applied in both branches; target validator passed. | target/DialogPane | incorporate | applied |
| C25 | DialogPane background second argument is `short frameIndex`, not palette string. | very high | Destination 7 exact block and bounded change applied; validator `000000012492` exit 0/ok 1. | DialogPane | incorporate | applied |
| C26 | UserListPane complete layout is base 0x14c plus 4/16/1 contexts and sibling fields. | very high | Destination 3 exact block at `91/92`; validator `000000012488`; generated class once. | UserListPane | incorporate | applied |
| C27 | RadioGroup complete tail is options list + selected index; inline getter is safe. | high | Destination 4 exact block at `90/91`; validator `000000012489`. | RadioGroupControlPane | incorporate | applied |
| C28 | CheckBoxText complete tail is bool + wchar[256]; setter does not invalidate. | very high | Destination 5 exact block at `90/92`; no-invalidation evidence retained; validator `000000012490`. | CheckBoxTextControlPane | incorporate | applied |
| C29 | GameServerConfig access uses protected-array count/GetAtOrDefault inline surface. | high | Destination 6 exact block at `91/92`; validators `000000012491` and terminal score scan `000000012496`. | GameServerConfig | incorporate | applied |
| C30 | UID000479 is two-arg command callback and must use child lookup, correct close/new paths. | very high | Destination 8 exact body at `90/92`; validator `000000012493`; generated corrected definition once and old forms zero. | UID000479/class | incorporate | applied |
| C31 | UID00047S is Singleton destructor support, not handwritten clear helper. | very high | UID-preserving old-to-new move, false/blank formal disposition, owner `0000FN`; rename validator `000000012495`; old path absent and one UID header. | UID00047S/parent/file | incorporate | applied |
| C32 | g_p slot is Singleton backing storage; no duplicate standalone definition is added. | high | Semantic global `90/94` and physical slot `90/95` synchronized by `000000012497`/`000000012498`; generated standalone definition absent. | by-global/storage | incorporate | applied |
| C33 | UID0002WD keeps physical storage blank and corrects stale `ff`/gate/source wording. | very high | Exact zero-byte summary, false/blank emitter/formal, direct owner, and source-declared/generated-binary proof applied; validator `000000012498`. | storage | incorporate | applied |
| C34 | Parent child row changes target to emitting and UID00047S to compiler support. | very high | Both rows/current rationale updated while parent metadata stayed fixed; validator `000000012500`. | parent | incorporate | applied |
| C35 | UserListDialogPane class becomes `92/93` with complete balanced block. | high | Destination 2 exact byte match; terminal validator `000000012487`; generated class once and closed before child marker replacement. | class | incorporate | applied |
| C36 | UserListDialogPane file becomes `91/92` and records current source-ready constructor. | high | File inventory/source route applied; waited validator `000000012502`; generated readback current. | by-file | incorporate | applied |
| C37 | B001 layout/name evidence is retained but superseded declarations are historicalized. | high | Existing B001 evidence retained; incomplete one-base/void*/one-arg/helper alternatives explicitly superseded in target/class/file. | class/file/target | historicalize | applied |
| C38 | B002 exact split inventory remains valid. | very high | Parent/file inventories preserved; only target and UID00047S dispositions changed; validator `000000012500`. | parent/file | already-present | already-present |
| C39 | UID00047B remains no-owner/non-emitting. | high | Existing route-negative detail retained unchanged in parent/file/report; no destination edit or generated body. | parent/file/report | already-present | already-present |
| C40 | UID00047L/M remain no-owner/non-emitting. | high | Existing exact wrapper bytes/routes and no-emitter decisions retained unchanged; no generated bodies. | parent/file/report | already-present | already-present |
| C41 | All resource literals and branch selection are preserved. | very high | Exact Destination 1 and file detail preserve EPF/EPD/PAL/PAD/US strings and `g_useEpfAssets` branch. | target/file | incorporate | applied |
| C42 | EH/vptr/cookie/allocation-unwind/delete mechanics stay compiler-generated. | very high | No such source expressions in managed blocks or generated readback; UID00047S/cleanup/deleting children remain non-emitting. | target/UID000471/47S | reject-invalid | excluded-with-reason |
| C43 | Generated verification must find one UID000470 body and no target empty marker. | high | Waited command `000000012502`: one marker/body, zero target empty marker, balanced braces, unique UID markers, generated SHA recorded. | report callback | incorporate | applied |
| C44 | Exact manual coverage replacement/insertion text is supplied, not applied. | very high | Exact supervisor-owned text below preserved byte-for-byte; no manual `-coverage-report.md` file edited. | coverage section | not-applicable | excluded-with-reason |
| C45 | No IDA rename/type/comment mutation is requested. | very high | No IDA mutation call was made during callback; evidence-time IDB facts remain read-only. | report | not-applicable | excluded-with-reason |
| C46 | No new child/range/page registration is required. | very high | No new page/UID allocated; only validator-aware UID00047S path update retained UID; all existing siblings preserved. | report/parent | not-applicable | already-present |

## Positive Evidence Summary

- Exact source entry/end, four ordinary callers, one explicit packet argument, `retn 4`, and complete object allocation prove an ordinary constructor.
- RTTI and construction order prove the direct Singleton base and explain publication without manual source assignment.
- The target itself proves every high/low control, packet cursor increment, row assignment, conversion, append, filter, bucket, sort, count, and lifecycle call.
- The complete derived dialog and list-pane layouts are recovered from exact offsets and allocation sizes, removing the old declaration blocker.
- Existing class/file/split ownership and local resource/helper families consistently place the body in `NexusTK/social/UserListDialogPane.cpp`.

## IDA MCP Facts

- Function/range facts: target `0x0059bc90`, size `0x1508`, end `0x0059d198`, 213 blocks, complexity 43; no function at end; nullsub at `0x0059d1e0`; UserListPane constructor at `0x0059e710`, size `0x189`.
- Data/table/padding facts: five `0xcc` bytes before entry; target ends before eight `0xcc`; cleanup begins at `0x0059d1a0`; exact byte hash is recorded; no source split inside target.
- Xref facts: direct caller sites `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`; global slot has twelve refs; UID00047S has EH-only code xref `0x00609f1c` and no ordinary caller.
- Vtable/global/type facts: UserListDialogPane three vtable writes; direct Singleton RTTI BCD at `0x00651ccc`; Singleton subobject PMD `+0x26c`; zero-filled backing slot `0x0069b4e0`; filter byte `0x0069bed0`.
- Category-state facts: EPF call `0x0059be29` and its EPD sibling invoke the active status-pane nation getter but discard AL, then store nation-table count minus one at `this+0x26c`; UID000473 clamps `this+0x26e` to page `0..5` and maps that page to the selected value at `this+0x26c`. This preserves the binary's redundant getter/default assignment instead of inventing a lookup loop or consuming the getter result.
- Negative IDA facts: no function at target end, no separate high/low function, no direct route from target to UID00047B/47L/47M starts, no ordinary UID00047S caller, no evidence for manual vptr/global/cookie/EH source.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0059bc90-0x0059d198` | UID000470 target | source constructor | true | UID0000FN | current `93/94` | emits through UID0000OZ |
| `0x0059d198-0x0059d1e0` | UID000471 | constructor cleanup/unwind tail | false | UID0000FN | unchanged | blank compiler support |
| `0x0059d1e0-0x0059d1e3` | UID000472 | nullsub | false | UID0000FN | unchanged | blank |
| `0x0059da90-0x0059dbe3` | UID000479 | source command callback | true | UID0000FN | current `90/92` | corrected two-argument formal body applied |
| `0x0059dc20-0x0059de4a` | UID00047B | no-route raw send helper | true | none | unchanged | preserve blank/no-owner |
| `0x0059e710-0x0059e899` | UID00047H | UserListPane constructor child | true | UID0000FO | unchanged | separate child; class declaration support only |
| `0x0059e9b0-0x0059e9cf` | UID00047L | no-route status wrapper | true | none | unchanged | preserve blank/no-owner |
| `0x0059e9d0-0x0059e9ef` | UID00047M | no-route name wrapper/alignment | true | none | unchanged | preserve blank/no-owner |
| `0x0059efe0-0x0059efeb` | UID00047S | Singleton destructor support | false | UID0000FN | current `92/95` | UID-preserving rename complete; blank compiler/template support |
| `0x0059f110-0x0059f181` | UID00047V | scalar deleting destructor | false | UID0000FN | unchanged | blank compiler wrapper |
| `0x0059bc90-0x0059f25b` | UID0001KI | mixed split index | false | UID0000OZ | `90/91` unchanged | non-emitting |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005087f4` | dispatcher `0x00507c90` opcode `0x36` | lazy allocate `0x28c`, pass packet |
| `0x00513c6c` | function `0x00513c20` | second ordinary allocate/call route |
| `0x005a7ccb` | UserPane packet route `0x005a76c0` | passes Event payload at `+0x0c` |
| `0x005abc54` | retained LivingObjectPane duplicate `0x005abb20` | passes Event payload at `+0x0c` |
| `0x0059bd07` | DialogPane constructor | title, config 8, mode 1 |
| `0x0059bd41` | `GetLocalPlayerName` | copies local name with capacity `0x80` |
| `0x0059bee5/0x0059bef7` | packet word reads | reported/display count and entry count |
| `0x0059c00f/0x0059cb70` | UserListPane constructor | five panes per active branch |
| `0x0059c254/0x0059cd53` | `MultiByteToWideChar` | fixed-buffer user name conversion |
| `0x0059c2f1/0x0059cd85` | List append virtual | append master row |
| `0x0059c368/0x0059cdc9` | ListPane append | append visible bucket row |
| `0x0059c866/0x0059d0fd` | DialogPane background helper | `(L"US",0)` exact call shape |
| `0x00609f1c -> 0x0059efe0` | constructor EH cleanup | Singleton destructor support, not ordinary call |

## Documentation Evidence And IDA Status

- Supporting docs that remain correct: UID0001KI split ranges, UID0000OZ social source route, packed record size/most field roles, UserListPane ownership, reusable control ownership, packet dispatcher callers, resources, comparators, no-route children, and generic List/ProtectedArray behavior.
- Historical stale/incomplete docs corrected by this callback: target blank emitter/no-code text; UserListDialogPane one-base/invented-field declaration; UserListPane blank declaration; UID000479 signature/body; DialogPane background signature; RadioGroup/CheckBox declaration blockers; GameServer access surface; UID00047S handwritten helper classification; global/storage old gate language; parent/file child disposition.
- Current generated state: waited validator `000000012502` refreshed the validator-owned file; B004 made no manual generated edit. Exact hash/count/assertions are recorded under Supporting Research and Validator Results.
- Manual coverage: affected rows are stale or absent. Exact supervisor-owned text is supplied below.

## Ranked Ownership Analysis

### 1. UID0000FN UserListDialogPane / UID0000OZ UserListDialogPane.cpp

- Evidence for: exact constructor vtables/RTTI, dialog fields, source siblings, resources, packet callers, source-file parent, child controls, local helpers, and generated route all agree.
- Evidence against: original lexical names are stripped; this affects confidence only.
- Decision: selected owner/emitter.

### 2. UID0000FO UserListPane under the same file

- Evidence for: target creates five instances and directly uses inherited list behavior; source is physically adjacent.
- Evidence against: it owns repeated row widgets, not the dialog constructor, packet control tree, singleton, or dialog fields.
- Decision: supporting class declaration only; rejected as target owner.

### 3. UserPane / LivingObjectPane packet callers

- Evidence for: both dispatch user-list packet payloads to the constructor.
- Evidence against: they do not own target vtables, fields, resources, or controls; LivingObjectPane route remains retained duplicate evidence.
- Decision: caller dependencies only.

### 4. DialogPane and reusable controls

- Evidence for: target consumes their constructors and APIs.
- Evidence against: feature packet parsing, records, buckets, resources, singleton, and source siblings are UserList-specific.
- Decision: bounded support declaration corrections only.

### Proposed new file/grouping, if applicable

- Not applicable. Keep `NexusTK/social/UserListDialogPane.cpp` under UID0000OZ.
- Do not create a constructor-only source file, UserPane source fold, generic control fold, or standalone singleton-clear file.

## Source Placement

- Recommended placement: `NexusTK/social/UserListDialogPane.cpp`, existing owner UID0000OZ.
- Fit: the same file owns dialog/list/local party-search classes, comparators, packet/source helpers, hunters-list state, and resources.
- Rejected placements: `UserPane.cpp` and `LivingObjectPane.cpp` are caller-only; `DialogPane.cpp`, `ButtonControlPane.cpp`, and `SpecializedButtonPanes.cpp` own reusable dependencies; `GameServerConfig.cpp` owns the nation table only.
- Remaining uncertainty: header split and exact original private helper spellings, not source file.

## Range / Split / Padding / Reclassification Analysis

- Exact target: `[0x0059bc90,0x0059d198)`; one function and one source constructor.
- Predecessor: prior function return followed by five `0xcc` bytes at `0x0059bc8b-0x0059bc90`.
- Successor: eight `0xcc` bytes at `0x0059d198-0x0059d1a0`, then cleanup code through `0x0059d1e0`; separate UID000471 remains compiler/EH support.
- Nullsub: UID000472 remains `0x0059d1e0-0x0059d1e3` and blank.
- Reclassification applied: UID00047S was UID-preservingly renamed from `0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md` to `0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md`, owner UID0000FN, reconstructable false, blank emitter/position/formal C++, Nested 0. Validator `000000012495` updated its registry path and known reverse references; the old path is absent and the UID header is unique.
- Parent impact applied: UID0001KI remains non-emitting; only the target/UID00047S child descriptions/links and current source dispositions changed.

## Negative Evidence Summary

- No function, branch target, or source boundary at `0x0059d198` supports extending the source constructor into cleanup bytes.
- No internal source-bearing entry supports splitting EPF and EPD branches.
- No target call/xref supports promoting UID00047B, UID00047L, or UID00047M.
- No ordinary caller supports a handwritten UID00047S helper; its sole code xref is constructor EH cleanup.
- No source evidence supports manual vptr writes, null-allocation branches, cookie code, EH state writes, cleanup funclets, or deleting-destructor flags.
- No evidence supports zero-initializing the legacy-only uninitialized record fields or selected career variant.
- No evidence supports a `SimpleUString` packet-name conversion, a raw byte-offset UserPane expression, or a standalone target global definition.

## IDA Rename / Type / Comment Recommendations

- IDA database edits were not requested or performed during either research or callback.
- Source-facing target name: `UserListDialogPane::UserListDialogPane(const unsigned char *packet)`.
- Source-facing fields: `m_selectedNationId`, `m_categoryPage`, `m_selectedCareerVariant`, `m_bucketPanes`, `m_allUserRecords`; inferred/descriptive.
- Source-facing row: packed `UserListRecord` with current exact fields and branch-specific initialization caveat.
- Source-facing UID00047S path/name: `UserListDialogPaneSingletonDestructorSupport`; this is documentation/source-disposition naming, not an IDA mutation.
- Keep UID00047B/47L/47M names and no-route status unchanged.

## First-Draft C++ Recommendation

- Eligible for draft C++: UID000470 and the exact source declaration/support destinations below.
- Third-party import directive: not applicable; this is first-party reconstructed C++.
- Every draft/example C++ body or declaration intended for destination insertion appears only inside the exact managed destination blocks below; prose names and signatures are evidence labels only.

### Destination 1 - UID000470 target

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserListDialogPane::UserListDialogPane(const unsigned char *packet)
    : Singleton<UserListDialogPane>(),
      DialogPane(L"Users Dialog Pane", 8, 1)
{
    wchar_t localPlayerName[128];
    GetMemoryMan();
    GetLocalPlayerName(localPlayerName, 128);

    const unsigned char playerSettingsFlag = g_pUserPane->m_playerSettingsState[0];
    RectBounds bounds;
    wchar_t countText[12];
    char narrowName[256];
    int filteredCount = 0;
    int visibleCount = 0;

    if (g_useEpfAssets == 1)
    {
        InitRectBounds(&bounds, 0, 0, 709, 452);
        AddControl(new EPFImageControlPane(L"USERLIST.EPF", 0, true, &bounds,
                                           L"USERLIST.PAL"));

        InitRectBounds(&bounds, 608, 412, 671, 436);
        AddControl(new ImageButtonControlPane(15, &bounds));

        g_pUserStatusPane->GetNationId();
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        m_categoryPage = 1;

        const GameServerConfig::NationEntry *nationEntry =
            g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
        const unsigned short selectedNationId = nationEntry->nationId;

        InitRectBounds(&bounds, 82, 391, 154, 403);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        const unsigned short reportedCount = PacketBufferReadUInt16BE(packet + 1);
        const unsigned short entryCount = PacketBufferReadUInt16BE(packet + 3);
        const unsigned char initialSort = packet[5];
        const unsigned char *cursor = packet + 6;

        InitRectBounds(&bounds, 379, 388, 469, 432);
        RadioGroupControlPane *sortControl = new RadioGroupControlPane(&bounds);
        AddControl(sortControl);
        InitRectBounds(&bounds, 0, 1, 88, 15);
        sortControl->AddOption(L"", &bounds);
        InitRectBounds(&bounds, 0, 29, 88, 43);
        sortControl->AddOption(L"", &bounds);
        sortControl->SetSelectedIndex(initialSort);

        int left = 16;
        for (int index = 0; index < 5; ++index)
        {
            m_bucketPanes[index] = new UserListPane(sizeof(UserListRecord), 100,
                                                    m_bucketPanes, 5);
            InitRectBounds(&bounds, left, 95, left + 121, 331);
            AddControl(new ScrollableControlPane(&bounds, m_bucketPanes[index],
                                                 0, 0, 0));
            left += 135;
        }

        m_allUserRecords = new List(sizeof(UserListRecord), 100);

        for (unsigned int ordinal = 0; ordinal < entryCount; ++ordinal)
        {
            UserListRecord record;

            unsigned char encoded = *cursor++;
            record.careerId = encoded >> 4;
            record.bucketIndex = encoded & 7;

            encoded = *cursor++;
            record.statusIconId = encoded >> 4;
            record.badgeIconId = encoded & 7;

            encoded = *cursor++;
            record.careerVariant = encoded >> 4;
            record.huntersListFlag = encoded & 7;

            record.displayColor = *cursor++;
            record.arrivalSortKey = 100000 - ordinal;
            record.reserved2 = 0;

            const unsigned char nameLength = *cursor++;
            memmove(narrowName, cursor, nameLength);
            cursor += nameLength;
            narrowName[nameLength] = '\0';

            const int convertedLength = MultiByteToWideChar(
                CP_ACP, 0, narrowName, nameLength, record.name, 256);
            record.name[convertedLength] = L'\0';
            record.hasSourceText = 0;

            if (wcscmp(record.name, localPlayerName) == 0)
            {
                record.displayColor = 0x80;
                m_selectedCareerVariant = record.careerVariant;
            }

            if (record.reserved2 == 0 || playerSettingsFlag == 1)
                m_allUserRecords->Append(1, &record);
            else
                ++filteredCount;
        }

        for (int index = 0; index < m_allUserRecords->GetCount(); ++index)
        {
            UserListRecord *record = static_cast<UserListRecord *>(
                m_allUserRecords->GetElementAt(index));

            if ((g_bShowHuntersListOnly != 1 || record->huntersListFlag != 0) &&
                ((selectedNationId == 10 &&
                  record->careerVariant == m_selectedCareerVariant) ||
                 record->careerId == selectedNationId))
            {
                UserListPane *pane = record->bucketIndex != 0
                    ? m_bucketPanes[record->bucketIndex - 1]
                    : m_bucketPanes[4];
                pane->AddEntry(record);
            }
        }

        left = 89;
        for (int index = 0; index < 5; ++index)
        {
            if (initialSort == 0)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByStatus);
            else if (initialSort == 1)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByName);

            InitRectBounds(&bounds, left, 344, left + 24, 356);
            swprintf_s(countText, 12, L"%d", m_bucketPanes[index]->GetRecordCount());
            AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                                 &bounds, false, false));
            visibleCount += m_bucketPanes[index]->GetRecordCount();
            left += 135;
        }

        swprintf_s(countText, 12, L"%d",
                   static_cast<unsigned short>(reportedCount - filteredCount));
        InitRectBounds(&bounds, 176, 419, 248, 431);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        swprintf_s(countText, 12, L"%d", static_cast<unsigned short>(visibleCount));
        InitRectBounds(&bounds, 176, 391, 248, 403);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 270, 386, 333, 410);
        AddControl(new ImageButtonControlPane(45, &bounds));

        SimpleUString emptyText;
        InitRectBounds(&bounds, 288, 424, 374, 436);
        AddControl(new StaticTextControlPane(emptyText.c_str(), 1, 128, 0,
                                             &bounds, false, false));

        nationEntry = g_gameServerNationTable->GetNationEntryAtOrDefault(
            m_selectedNationId);
        InitRectBounds(&bounds, 83, 391, 155, 403);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 7, 386, 70, 410);
        AddControl(new ImageButtonControlPane(44, &bounds));

        InitRectBounds(&bounds, 530, 385, 680, 409);
        AddControl(new CheckBoxTextControlPane(
            g_pUserPane->m_preCollectionState[0] != 0, L"", &bounds));

        InitRectBounds(&bounds, 514, 13, 642, 37);
        AddControl(new CheckBoxTextControlPane(g_bShowHuntersListOnly, L"", &bounds));

        SetBackgroundResource(L"US", 0);
        SetHoverControl(1);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetMode(1);
        InitRectBounds(&bounds, 0, 0, 709, 452);
        OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
        OnShow(NULL, NULL);
        SlideOpenVertical();
    }
    else
    {
        InitRectBounds(&bounds, 0, 0, 635, 390);
        AddControl(new EPFImageControlPane(L"USERLIST.EPD", 0, true, &bounds,
                                           L"USERLIST.PAD"));

        InitRectBounds(&bounds, 529, 302, 601, 318);
        AddControl(new ImageButtonControlPane(15, &bounds));

        g_pOldUserStatusPane->GetNationId();
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        m_categoryPage = 1;

        const GameServerConfig::NationEntry *nationEntry =
            g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
        const unsigned short selectedNationId = nationEntry->nationId;

        InitRectBounds(&bounds, 36, 304, 107, 316);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        const unsigned short reportedCount = PacketBufferReadUInt16BE(packet + 1);
        const unsigned short entryCount = PacketBufferReadUInt16BE(packet + 3);
        const unsigned char initialSort = packet[5];
        const unsigned char *cursor = packet + 6;

        InitRectBounds(&bounds, 506, 37, 568, 63);
        RadioGroupControlPane *sortControl = new RadioGroupControlPane(&bounds);
        AddControl(sortControl);
        InitRectBounds(&bounds, 0, 0, 59, 11);
        sortControl->AddOption(L"", &bounds);
        InitRectBounds(&bounds, 0, 16, 59, 26);
        sortControl->AddOption(L"", &bounds);
        sortControl->SetSelectedIndex(initialSort);

        int left = 36;
        for (int index = 0; index < 5; ++index)
        {
            m_bucketPanes[index] = new UserListPane(sizeof(UserListRecord), 100,
                                                    m_bucketPanes, 5);
            InitRectBounds(&bounds, left, 102, left + 110, 282);
            AddControl(new ScrollableControlPane(&bounds, m_bucketPanes[index],
                                                 0, 0, 0));
            left += 113;
        }

        m_allUserRecords = new List(sizeof(UserListRecord), 100);

        for (unsigned int ordinal = 0; ordinal < entryCount; ++ordinal)
        {
            UserListRecord record;

            unsigned char encoded = *cursor++;
            record.careerId = encoded >> 4;
            record.bucketIndex = encoded & 7;

            encoded = *cursor++;
            record.statusIconId = encoded >> 4;
            record.badgeIconId = encoded & 7;

            record.displayColor = *cursor++;
            record.reserved2 = 0;
            record.arrivalSortKey = 100000 - ordinal;

            const unsigned char nameLength = *cursor++;
            memmove(narrowName, cursor, nameLength);
            cursor += nameLength;
            narrowName[nameLength] = '\0';

            const int convertedLength = MultiByteToWideChar(
                CP_ACP, 0, narrowName, nameLength, record.name, 256);
            record.name[convertedLength] = L'\0';

            if (record.reserved2 == 0 || playerSettingsFlag == 1)
            {
                m_allUserRecords->Append(1, &record);

                if (((selectedNationId == 10 &&
                      record.careerVariant == m_selectedCareerVariant) ||
                     record.careerId == selectedNationId) &&
                    record.bucketIndex != 0)
                {
                    m_bucketPanes[record.bucketIndex - 1]->AddEntry(&record);
                }
            }
            else
            {
                ++filteredCount;
            }
        }

        left = 36;
        for (int index = 0; index < 5; ++index)
        {
            if (initialSort == 0)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByStatus);
            else if (initialSort == 1)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByName);

            InitRectBounds(&bounds, left, 285, left + 110, 297);
            swprintf_s(countText, 12, L"%d", m_bucketPanes[index]->GetRecordCount());
            AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                                 &bounds, false, false));
            visibleCount += m_bucketPanes[index]->GetRecordCount();
            left += 113;
        }

        swprintf_s(countText, 12, L"%d",
                   static_cast<unsigned short>(reportedCount - filteredCount));
        InitRectBounds(&bounds, 111, 323, 183, 335);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        swprintf_s(countText, 12, L"%d", static_cast<unsigned short>(visibleCount));
        InitRectBounds(&bounds, 111, 304, 183, 316);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 190, 321, 262, 337);
        AddControl(new ImageButtonControlPane(45, &bounds));

        SimpleUString emptyText;
        InitRectBounds(&bounds, 111, 341, 261, 353);
        AddControl(new StaticTextControlPane(emptyText.c_str(), 1, 128, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 190, 302, 262, 318);
        AddControl(new ImageButtonControlPane(44, &bounds));

        SetBackgroundResource(L"US", 0);
        SetHoverControl(1);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetMode(1);
        InitRectBounds(&bounds, 0, 50, 635, 440);
        OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
        OnShow(NULL, NULL);
        SlideOpenVertical();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - by-class/UserListDialogPane.md

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T> class Singleton;
class DialogPane;
class UserListPane;
class PartySearchEditPane;
class PacketEventContext;
class KeyEvent;
class List;

#pragma pack(push, 1)
struct UserListRecord
{
    unsigned char careerId;
    unsigned char bucketIndex;
    unsigned char reserved2;
    unsigned char badgeIconId;
    unsigned char displayColor;
    unsigned char reserved5[3];
    long arrivalSortKey;
    unsigned char statusIconId;
    unsigned char reservedD;
    wchar_t name[256];
    unsigned char huntersListFlag;
    unsigned char hasSourceText;
    wchar_t sourceText[256];
    unsigned char careerVariant;
    unsigned char reserved411[3];
};
#pragma pack(pop)

int __cdecl CompareUserListRecordsByStatus(const UserListRecord *left,
                                           const UserListRecord *right);
int __cdecl CompareUserListRecordsByName(const UserListRecord *left,
                                         const UserListRecord *right);
void AddUserListSourceMessage(const UserListRecord *record);
void SyncUserListSourceTextIntoBucket(UserListPane *pane,
                                      const UserListRecord *record);

class UserListDialogPane : public Singleton<UserListDialogPane>, public DialogPane
{
public:
    explicit UserListDialogPane(const unsigned char *packet);
    virtual ~UserListDialogPane();

    void SortListsByStatus();
    void SortListsByName();
    void RefreshCategoryView(int step);
    bool HandleUserListPacket(PacketEventContext *event);
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    short m_selectedNationId;
    short m_categoryPage;
    short m_selectedCareerVariant;
    UserListPane *m_bucketPanes[5];
    List *m_allUserRecords;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - by-class/UserListPane.md

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MouseEvent;
class UserListRecord;

class UserListPane : public ListPane
{
public:
    UserListPane(int recordSize,
                 int pageSize,
                 UserListPane **siblingPanes,
                 int siblingPaneCount);
    virtual ~UserListPane();

    void SortRecords(ListCompareFunction compare);
    int GetRecordCount() const;
    UserListRecord *GetRecordAt(int index);
    UserListRecord *GetSelectedRecord();
    void AddEntry(const UserListRecord *record);

    virtual void DrawUserEntry(int itemIndex, const RectBounds *bounds);
    virtual void OnItemSelected(int itemIndex);
    void OpenSayToUserMessageInputPane();
    virtual bool OnDoubleClick(const MouseEvent &event);

private:
    EPFTileContext m_statusIconFrames[4];
    EPFTileContext m_badgeIconFrames[16];
    EPFTileContext m_selectionFrame;
    UserListPane **m_siblingPanes;
    int m_siblingPaneCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - by-class/RadioGroupControlPane.md

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RadioGroupControlPane : public ControlPane
{
public:
    explicit RadioGroupControlPane(const RectBounds *bounds);
    virtual ~RadioGroupControlPane();

    void AddOption(const wchar_t *text, const RectBounds *bounds);
    void SetSelectedIndex(int selectedIndex);
    int GetSelectedIndex() const
    {
        return m_selectedIndex;
    }

    virtual void OnPaint();

private:
    List *m_options;
    int m_selectedIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - by-class/CheckBoxTextControlPane.md

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CheckBoxTextControlPane : public ControlPane
{
public:
    CheckBoxTextControlPane(bool checked,
                            const wchar_t *label,
                            const RectBounds *bounds);
    virtual ~CheckBoxTextControlPane();

    virtual void OnPaint();
    virtual int GetControlType();
    void SetChecked(bool checked);
    bool GetChecked() const;

private:
    bool m_checked;
    wchar_t m_label[256];
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - by-class/GameServerConfig.md

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GameServerConfig : public LObject
{
public:
    struct NationEntry
    {
        NationEntry()
            : nationId((unsigned short)-1)
        {
        }

        unsigned short nationId;
        wchar_t label[33];
    };

    GameServerConfig();
    virtual ~GameServerConfig();

    NationEntry *CopyNationEntryOrFallback(NationEntry *destination, int nationId);
    void SeedDefaultNationEntries();
    void RequestNationEntries();
    void ParseNationEntries(const unsigned char *packet);

    int GetNationEntryCount() const
    {
        return m_nationEntries.GetCount();
    }

    NationEntry *GetNationEntryAtOrDefault(int index)
    {
        return m_nationEntries.GetAtOrDefault(index);
    }

private:
    ProtectedArray<NationEntry> m_nationEntries;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - by-class/DialogPane.md

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
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
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

### Destination 8 - UID000479 OnControlCommand

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserListDialogPane::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    switch (controlIndex)
    {
    case 1:
        SlideCloseVertical();
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
        break;

    case 3:
    {
        const int selectedIndex = GetChild<RadioGroupControlPane>(3)->GetSelectedIndex();
        if (selectedIndex == 0)
            SortListsByStatus();
        else if (selectedIndex == 1)
            SortListsByName();
        Invalidate();
        break;
    }

    case 0x10:
        RefreshCategoryView(1);
        break;

    case 0x13:
        RefreshCategoryView(-1);
        break;

    case 0x14:
        new PartySearchEditPane();
        break;

    case 0x15:
    {
        g_bShowHuntersListOnly = !g_bShowHuntersListOnly;
        CheckBoxTextControlPane *checkBox =
            GetChild<CheckBoxTextControlPane>(0x15);
        checkBox->SetChecked(g_bShowHuntersListOnly);
        checkBox->Invalidate();
        RefreshCategoryView(0);
        break;
    }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - renamed UID00047S formal block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- UID00047S exact no-code proof: direct Singleton RTTI, publication before DialogPane construction, 11-byte clear body, and sole constructor-EH cleanup xref prove template destructor support. The ordinary class declaration regenerates the lifecycle behavior; a standalone helper body duplicates it.
- Behavior preservation: Destination 1 preserves both branch layouts, every packet read/cursor increment, every initialized and intentionally uninitialized field, all append/filter/bucket/sort/count behavior, exact resources/control ids/rectangles, and final dialog lifecycle.
- Plausible period source: ordinary constructors, fixed stack buffers, `new`, generic containers, direct Win32 MBCS conversion, POD rectangles, and inline accessors match the accepted late-1999 through mid-2000s project style. Raw offsets, vptr writes, labels, and decompiler temporaries are absent.
- Naming convention: PascalCase classes/methods, `m_` members, `g_` globals, descriptive packet/record fields, and existing project helper names.

## Final Recommendation

- Applied target UID000470 `86/90 -> 93/94`, emitter UID0000OZ, owner UID0000FN, reconstructable true, blank position, Nested 0, and exact Destination 1.
- Applied complete class blocks Destinations 2-7 and corrected UID000479 Destination 8 at their named pages while preserving unrelated declarations/bodies/scores.
- UID-preservingly renamed/reclassified UID00047S and left its formal block exactly blank as Destination 9.
- Preserved parent UID0001KI, UID000471/472, all unrelated source siblings, UID00047B/L/M no-route dispositions, compiler tables/thunks/deleting wrappers, and the source file route.
- No future source investigation item remains inside UID000470. Lexical uncertainty is a documented confidence cap, not deferred work.

## Recommended Target Doc Changes

- Path applied: `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md`.
- Metadata applied: `COMPLETION:93`, `CONFIDENCE:94`, owner `0000FN`, reconstructable true, `EMITTER_UIDS:0000OZ`, blank position, `Nested:0`.
- Item Summary applied: exact one-constructor, two-layout, packet-row, Singleton/base, five-bucket, count/control/lifecycle coverage.
- Formal C++ applied: exact Destination 1; exact report/destination block comparison returned true with 13,183 normalized characters on each side.
- Body detail applied: complete C01-C24/C41-C42 facts, exact bytes/hash, callers, resources, branch-specific uninitialized state, no-clamp behavior, EH/compiler exclusions, superseded blank rationale, and rejected alternatives.

## Recommended Support Doc Changes

- `by-class/UserListDialogPane.md`: applied `88/88 -> 92/93`, exact Destination 2, direct Singleton base, complete `0x28c` tail, two-arg callback, helper declarations, and class close before `[[CHILDREN]]`.
- `by-class/UserListPane.md`: applied `85/87 -> 91/92`, exact Destination 3, complete `0x49c` layout/method surface, and preserved child/no-route decisions.
- `by-class/RadioGroupControlPane.md`: applied `87/89 -> 90/91`, exact Destination 4, options/selected-index tail and inline getter; raw option-helper disposition preserved.
- `by-class/CheckBoxTextControlPane.md`: applied `86/88 -> 90/92`, exact Destination 5, bool/label layout and method surface; child/vtable/reusable ownership preserved.
- `by-class/GameServerConfig.md`: applied `90/91 -> 91/92`, exact Destination 6, only inlined count/GetAtOrDefault accessors; existing source evidence preserved.
- `by-class/DialogPane.md`: kept `90/92`; exact Destination 7 changes only the background helper's second parameter to `short frameIndex`.
- `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md`: applied `87/90 -> 90/92`, exact Destination 8 and detailed cases; invented members/wrong constructor form historicalized.
- UID00047S old/new path: applied `by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md` -> `by-memory/0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md`; `92/95`, owner UID0000FN, false, blank emitter/position/formal, Nested 0, exhaustive no-code proof.
- `by-global/g_pUserListDialogPane.md`: applied `90/94`, retained owner UID0000OZ and blank formal block, documented Singleton backing storage/zero bytes/twelve refs/no duplicate definition.
- `by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md`: applied `90/95`, owner UID0003EI, false, blank emitter/position/formal, Nested 0, corrected summary and generated-storage disposition.
- `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`: retained `90/91`, false/non-emitting/Nested 0/formal blank; changed only target/UID00047S rows and current rationale.
- `by-file/UserListDialogPane.md`: applied `88/88 -> 91/92`, source-ready constructor/classes, compiler-support correction, retained no-route children/resources/branch behavior, and current generated proof.
- Verify-only: UID000471/472/473/474/475/477/478, UID00047B/L/M, UID00047H/I/J/K/N/O/P/Q/R/T/V/W, List, ListPane, ProtectedArray, UserPane, EPFImage, ImageButton, StaticText, ScrollableControlPane, UserStatus/OldUserStatus, MainUiLayerSlots, g_bShowHuntersListOnly, read-only/vtable pages, and unrelated support scores/formal blocks.

## Score And Metadata Recommendation

- Historical target before callback: `86/90`, owner UID0000FN, true, blank emitter/position/formal, Nested 0.
- Current target after callback: `93/94`, owner UID0000FN, true, emitter UID0000OZ, blank position, exact formal body, Nested 0.
- Completion rationale: exact ABI/range, full two-branch body, complete class/list layouts, required support APIs, source placement, cleanup split, resources, global/template disposition, and callback conflict are resolved.
- Confidence rationale: binary behavior and structure are direct; exact original lexical spellings and whether some trivial accessors were inline versus macros remain unprovable, so confidence stays below 95.
- Score-improvement attempts: target boundary, callers, RTTI/base order, class tail, list type, packet fields, conversions, controls, resources, branch differences, cleanup, globals, old reports, generated output, and coverage were all checked. Each former blocker was converted into exact source or explicit generated-support disposition.
- Support scores: only those listed under Recommended Support Doc Changes change. Parent and DialogPane scores remain unchanged where current evidence only corrects one support fact.

## Open Questions With Attempted Resolution

- Exact original field spellings: stripped symbols provide no lexical proof. Current names are behavior-specific and consistent; confidence cap only.
- Exact inline nation accessors: direct count/data/default-entry code and accepted ProtectedArray template prove the operation. `GetNationEntryCount`/`GetNationEntryAtOrDefault` are the highest-probability human source surface and generate equivalent direct accesses.
- Legacy uninitialized fields: checked every store in the EPD branch; no defensible initialization exists. Preserve the source shape rather than inventing safety.
- Singleton pointer declaration spelling: RTTI and EH support prove template specialization storage but not its original member spelling. Keep semantic doc alias and blank standalone formal C++.
- UID00047S liveness: checked modeled function, complete bytes, callers/xrefs, target EH map, and direct base. The only defensible disposition is generated template destructor support.
- No investigable UID000470 blocker remains. No future-work deferral is used.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual rows were read read-only from `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-memory/-coverage-report.md`. The target/UID000479/UID00047S child rows are absent from manual by-memory coverage; parent and storage rows are stale. Exact supervisor text follows.
- `by-class/-coverage-report.md` replace UID0000FN row with:
  `- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md) : reconstructable : 92% : very-strong : Complete Singleton<UserListDialogPane> plus DialogPane social user-list class with exact 0x28c layout, packed UserListRecord, source-ready constructor route, two-argument OnControlCommand, five UserListPane buckets, packet/filter/resource behavior, exact child inventory, compiler singleton/destructor separation, and UserListDialogPane.cpp ownership.`
- Replace UID0000FO row with:
  `- [UID:0000FO][UserListPane](by-class/UserListPane.md) : reconstructable : 91% : very-strong : Complete 0x49c UserListPane declaration over the 0x14c ListPane base with four status frames, sixteen badge frames, one selection frame, sibling-pane pointer/count, exact constructor/resource behavior, row/list method surface, separate source children, and retained no-route sort-wrapper exclusions.`
- Replace UID0000BI row with:
  `- [UID:0000BI][RadioGroupControlPane](by-class/RadioGroupControlPane.md) : reconstructable : 90% : very-strong : Complete ControlPane-derived radio group declaration with exact options-list and selected-index tail, constructor/AddOption/SetSelectedIndex/inline GetSelectedIndex/paint surface, current vtable and resource evidence, ButtonControlPane ownership, and retained raw option-helper no-route proof.`
- Replace UID000022 row with:
  `- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md) : reconstructable : 90% : very-strong : Complete reusable checkbox-text control declaration with checked byte, fixed wchar label, constructor/paint/type/get/set surface, exact vtable and field evidence, separate method children, SpecializedButtonPanes ownership, and no implicit invalidation in SetChecked.`
- Replace UID00005O row with:
  `- [UID:00005O][GameServerConfig](by-class/GameServerConfig.md) : reconstructable : 91% : very-strong : Complete map/game-server nation-table class with exact NationEntry and ProtectedArray storage, source-ready constructor/destructor/lookup/request/parser children, inline count/GetAtOrDefault access used by UserListDialogPane, raw-island route caveats, and GameServerConfig.cpp ownership.`
- Replace UID00003T row with:
  `- [UID:00003T][DialogPane](by-class/DialogPane.md) : reconstructable : 90% : very-strong : Base dialog class attached to DialogPane.cpp with full declaration/layout, current Event-family virtuals, public two-argument OnControlCommand and CloseDialog, exact control lookup/access, corrected SetBackgroundResource(resourceName, short frameIndex), lifecycle/animation/control families, and complete child routing.`
- `by-file/-coverage-report.md` replace UID0000OZ row with:
  `- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) : reconstructable : 91% : very-strong : Source-ready social UserListDialogPane.cpp family with complete dialog/list declarations, exact two-layout constructor, packet/user-row/filter/bucket/sort/count/control behavior, resources, local helpers/comparators, Singleton backing-storage lifecycle, exact split inventory, and retained no-route/compiler-child exclusions.`
- `by-global/-coverage-report.md` replace UID0003EI row with:
  `- [UID:0003EI][g_pUserListDialogPane](by-global/g_pUserListDialogPane.md) : reconstructable : 90% : very-strong : Semantic alias for zero-filled Singleton<UserListDialogPane> specialization storage at 0x0069b4e0 with twelve publish/clear/guard/consumer refs, direct Singleton RTTI and EBO lifecycle, UserListDialogPane.cpp ownership, exact storage child UID0002WD, and no duplicate standalone global definition.`
- `by-memory/-coverage-report.md` replace UID0001KI row with:
  `    - [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) 0x0059bc90-0x0059f25b | non-emitting split index | UserListDialogPaneAndUserListPane : ignored : 90% : very-strong : Exact mixed social user-list index over source-ready UserListDialogPane/UserListPane methods, reusable checkbox overlap, file-local helpers/comparators, switch tables, padding, no-route wrappers, Singleton compiler support, globals, and deleting/adjustor artifacts; source emits only from exact children/classes.`
- Insert under that parent in address order:
  `        - [UID:000470][0x0059bc90-0x0059d198.UserListDialogPaneConstructor](by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md) 0x0059bc90-0x0059d198 | constructor | UserListDialogPaneConstructor : reconstructable : 93% : very-strong : Exact one-argument UserListDialogPane constructor with Singleton then DialogPane bases, complete 0x28c layout, EPF/EPD control trees, five UserListPane buckets, packet row conversion/filter/distribution/sort/count behavior, resources, branch-specific uninitialized-state preservation, and UserListDialogPane.cpp emission.`
  `        - [UID:000479][0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand](by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md) 0x0059da90-0x0059dbe3 | virtual method | UserListDialogPaneOnControlCommand : reconstructable : 90% : very-strong : Exact two-argument DialogPane callback handling slide/deferred close, radio sort selection, category stepping, parameterless PartySearch dialog creation, hunters-list checkbox toggle, and child-index lookup without invented members.`
  `        - [UID:00047S][0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport](by-memory/0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md) 0x0059efe0-0x0059efeb | Singleton template destructor support | UserListDialogPaneSingletonDestructorSupport : ignored : 92% : very-strong : Exact 11-byte singleton-slot clear reached only from constructor EH cleanup; direct Singleton<UserListDialogPane> RTTI/base construction proves source-declared/generated-binary template support, so standalone formal C++ remains blank.`
- Replace UID0002WD row with:
  `        - [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md) 0x0069b4e0-0x0069b4e4 | Singleton specialization pointer storage | g_pUserListDialogPane : ignored : 90% : very-strong : Exact zero-filled four-byte Singleton<UserListDialogPane> backing slot with twelve publish/clear/guard/consumer refs, semantic alias parent UID0003EI, template-base lifecycle, and source-declared/generated-binary blank-emitter disposition.`
- Reason B004 did not apply these rows: manual coverage is supervisor-owned. Validator-generated coverage does not replace these manual rows.

## Follow-Up Actions

- Implementation, scoped validation, lease release, and waited generated readback are complete; no accepted implementation item remains.
- Report validation, execution, count, path, move, archive, and manual coverage state remain external supervisor/validator-owned facts and are neither asserted nor directed by this artifact. B004 ran no report lifecycle command.
- A-agent actions: none. IDA naming/type mutation was not requested or performed.
- B004 research actions: none remain inside UID000470; unrelated sibling work remains outside this bounded callback.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: high; `93/94` reflects complete behavior/structure with lexical uncertainty.
- Remaining uncertainty: original private field/helper names, header split, and inline accessor spellings. None changes range, owner, emitter, branch behavior, or code eligibility.

## Validator Results

- Every changed ordinary destination passed scoped file validation from `source-3/project-documentation`; all commands exited `0` with `ok=1`:

| Command | Timestamp | Final path / purpose | Result and side effects |
|---|---|---|---|
| `000000012484` | `2026-07-14T23:11:43-04:00` | `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md` | exit `0`, ok `1`; target metadata, emitter, details, and exact Destination 1 accepted. |
| `000000012486` | `2026-07-14T23:12:33-04:00` | `by-class/UserListDialogPane.md` initial content pass | exit `0`, ok `1`; validator normalized the UID0003US link to its current `UserPane` path; two existing `missing_ref_uid` warnings. |
| `000000012487` | `2026-07-14T23:13:06-04:00` | `by-class/UserListDialogPane.md` final whitespace repair | exit `0`, ok `1`; exact Destination 2 accepted; the same two existing `missing_ref_uid` warnings remained. |
| `000000012488` | `2026-07-14T23:13:32-04:00` | `by-class/UserListPane.md` | exit `0`, ok `1`; exact Destination 3 accepted; two existing `missing_ref_uid` warnings. |
| `000000012489` | `2026-07-14T23:14:01-04:00` | `by-class/RadioGroupControlPane.md` | exit `0`, ok `1`; exact Destination 4 accepted; validator normalized UID0003N3/UID0003N4 links to `Enable`/`Disable`; three existing `missing_ref_uid` warnings. |
| `000000012490` | `2026-07-14T23:14:46-04:00` | `by-class/CheckBoxTextControlPane.md` | exit `0`, ok `1`; exact Destination 5 accepted; nineteen existing `missing_ref_uid` warnings. |
| `000000012491` | `2026-07-14T23:15:11-04:00` | `by-class/GameServerConfig.md` content pass | exit `0`, ok `1`; exact Destination 6 accepted; fourteen existing `missing_ref_uid` warnings. |
| `000000012492` | `2026-07-14T23:15:38-04:00` | `by-class/DialogPane.md` | exit `0`, ok `1`; exact Destination 7 accepted; ten existing `missing_ref_uid` warnings. |
| `000000012493` | `2026-07-14T23:16:15-04:00` | `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md` | exit `0`, ok `1`; exact Destination 8 accepted. |
| `000000012495` | `2026-07-14T23:16:55-04:00` | final renamed `by-memory/0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md` | exit `0`, ok `1`; validator recorded the UID00047S path update, propagated reverse links in by-file/by-global/parent destinations, and accepted the no-code reclassification; nine existing `missing_ref_uid` warnings. |
| `000000012496` | `2026-07-14T23:17:21-04:00` | `by-class/GameServerConfig.md` terminal score pass | exit `0`, ok `1`; final `91/92` state accepted; fourteen existing `missing_ref_uid` warnings. |
| `000000012497` | `2026-07-14T23:17:57-04:00` | `by-global/g_pUserListDialogPane.md` | exit `0`, ok `1`; semantic Singleton storage state accepted. |
| `000000012498` | `2026-07-14T23:18:31-04:00` | `by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md` | exit `0`, ok `1`; exact zero-storage/generated disposition accepted. |
| `000000012500` | `2026-07-14T23:19:10-04:00` | `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md` | exit `0`, ok `1`; split-index synchronization accepted; nine existing `missing_ref_uid` warnings. |
| `000000012502` | `2026-07-14T23:20:13-04:00` | `by-file/UserListDialogPane.md`, final `--wait-generated` refresh | exit `0`, ok `1`; by-file synchronization accepted and generated refresh completed. Validator-owned broad warnings/counters were `autogen_children_fallback_insert=14`, `autogen_children_marker_missing=86`, `autogen_emitter_has_no_code=171`, and metadata refresh `280`; the validator also refreshed its research tracker. These were recorded side effects, not target-scoped failures, and no such file was manually edited by B004. |

- Generated readback: `auto-generated/NexusTK/social/UserListDialogPane.cpp`, SHA256 `ED78D444FE27D5A67CAEFB377CEA421303F2F23725B79B287AE4279DC5287F9E`, 608 lines, refresh command `000000012502` at `2026-07-14T23:20:13-04:00`.
- Generated assertions: one UID000470 marker and one constructor definition; one UID000479 marker and one OnControlCommand definition; zero UID000470 Empty Emitter Markers; zero UID00047S markers or bodies under either old or new name; zero old singleton-clear name; zero stale sort/checkbox members; zero old PartySearch constructor form; zero explicit vptr/cookie/delete mechanics; one UserListDialogPane class and one UserListPane class; sixteen total and sixteen unique UID markers with no duplicate marker group; balanced braces (`35` open, `35` close).
- Existing unrelated generated Empty Emitter Markers remain for PartySearch UID0000A7 and semantic storage UID0003EI; neither is a UID000470/UID00047S callback defect.
- All nine report-managed formal blocks were parsed after validation and matched their final destination blocks exactly after line-ending normalization; Destination 9 remained exactly blank.
- No validator failed. The listed `missing_ref_uid` warnings are pre-existing registry gaps on the affected support pages and did not prevent any scoped page from returning `ok=1`.

## Changed Files

- Updated report: `tools/leaser/Agents/Agent-B004/research/000470-UserListDialogPaneConstructor-source-quality.md`.
- Modified ordinary destinations and final SHA256 values:
  - `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md`: `5BD97D5937C58C94D31F8FD97B7FFAD492D86349902248C9793B0D08599FD9B9`.
  - `by-class/UserListDialogPane.md`: `4AEAED3DD4997D3B9A09FEDBA2E2E03FC5F63C0ADA75D37D784FD6981EA0E322`.
  - `by-class/UserListPane.md`: `08BF459CA3BE4F544B78F5275C288F4BE35550D1B9363DB478952A0B26F7FAA5`.
  - `by-class/RadioGroupControlPane.md`: `4098B85A2E5AF1F8D79F4C2C03ECA47D5D280ED2C4DA9ADCDF49A8A9ED88F982`.
  - `by-class/CheckBoxTextControlPane.md`: `687F53076487BA9D8A3866F2156B6364800C33AB9EA235DB9CDC8FFA7EE93E62`.
  - `by-class/GameServerConfig.md`: `0E48D664CEAA346C977FA1C375810D6D55219AC3A7B90F6F9082463219B019E6`.
  - `by-class/DialogPane.md`: `7C1EB795B4CAF2FC1574B8C749480E7822416580F7CEF87E1794AD9B8781A4D5`.
  - `by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md`: `6F75774BB0477AD98421A0944ADB245952FF7AB1D401F599D41D674F467197BC`.
  - `by-global/g_pUserListDialogPane.md`: `3A5CCC8BD4969DBCA89BB59EA0F99854F0FFC9FFB309A92005C0213A38560DE9`.
  - `by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md`: `1F0467839B5B380E7E3BC6B1767B810F0AD809870EB7D45C70CED652C78A617E`.
  - `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`: `943F56A2E63E0BE1A825A8A8B382DA5524F31147DDC06D4CE4651111F8E13C92`.
  - `by-file/UserListDialogPane.md`: `96B4BCD872CE9C806236AC5A20A7D271F20C10C758B367A150D9425D711D63F6`.
- UID-preserving rename: `by-memory/0x0059efe0-0x0059efeb.ClearUserListDialogPaneSingleton.md` -> `by-memory/0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md`; final SHA256 `1A108CF71AD7448EBDE621B73C99758030CDEDDCEDFBD4B1A5C8B122FF8F5DB6`. The old path is absent and exactly one Markdown UID header retains UID00047S.
- Validator-owned generated refresh was read only by B004. Manual coverage, generated output, tracker, audit, supervisor, validator-state, lifecycle, archive, queue/lock, and IDA files were not manually edited.
- Every B004 lease was released immediately after its file validation window; the final lease readback contained no B004 lease.
- B004 ran no `execute_report`, report probe/count/revalidation, move, archive, or other lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] The exact pre-callback artifact SHA `520F64256F1C27395C140278AA4D80A9AC889ACC82873297508F1FBC03B397E9` passed supervisor Gate 1 before implementation authorization.
- [x] Target/support scope recorded: UID000470, UID0000FN, UID0000FO, UID0000BI, UID000022, UID00005O, UID00003T, UID000479, UID00047S UID-preserving rename, UID0003EI, UID0002WD, UID0001KI, and UID0000OZ.
- [x] Pre-callback target state and actual evidence were recorded and have been historicalized where implementation changed current truth.
- [x] Claim And Incorporation Ledger C01-C46 now uses legal terminal actions and verification states with per-destination proof.
- [x] Metadata/score plan was exact: target `93/94`; class/file/support changes were bounded as listed; unrelated scores were preserved.
- [x] Score-limiting blockers were researched to resolution, including range, ABI, direct bases, class/list layouts, controls, packets, globals, cleanup, source route, and C++.
- [x] Owner/emitter/reconstructable plan was exact: target emitter UID0000OZ; UID00047S/UID0002WD compiler/generated dispositions; all other states as listed.
- [x] Split/rename/new-child plan was exact: no new split/child and only the UID00047S UID-preserving rename.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment decisions were recorded; IDA mutation was excluded.
- [x] Nine exact managed destination blocks were supplied and later matched against final destinations; Destination 9 remained blank by exhaustive no-code proof.
- [x] Third-party import directive was confirmed not applicable; no import path or third-party multiline block was introduced.
- [x] Exact target/support facts to incorporate were recorded at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, and branch-specific uninitialized behavior to preserve were recorded.
- [x] Wave2/Wave3 mentions encountered were retained only as historical leads and rejected as current authority.
- [x] Open questions were closed or retained only as evidence-backed lexical confidence caps.
- [x] Validator plan required one scoped validator per changed final ordinary path, including the final renamed UID00047S path; every such path passed.
- [x] One waited UID0000OZ/UserListDialogPane refresh completed with one UID000470 body, corrected declarations/callback, no target empty marker, no UID00047S standalone body, no duplicate UID marker, and no manual generated edit.
- [x] Exact supervisor-owned manual coverage replacement/insertion text remains preserved for external application only.

Implementation callback pass:
- [x] Supervisor accepted the exact pre-callback report SHA for implementation.
- [x] All accepted target/support details were incorporated at report-level detail without compressing evidence or unrelated content.
- [x] Claim And Incorporation Ledger C01-C46 has legal terminal callback states and concrete destination/validator proof.
- [x] Metadata, scores, owners, emitters, split state, UID00047S rename, and all nine managed blocks were applied or explicitly excluded with evidence-backed reason.
- [x] Historical assumptions, rejected alternatives, negative evidence, and branch-specific uninitialized behavior were preserved.
- [x] Open questions are resolved or retained only as lexical confidence caps that do not block source emission.
- [x] Every changed ordinary page passed scoped validation and each B004 lease was released immediately after its validation window.
- [x] Final waited generated refresh/readback completed; exact positive/negative assertions and generated SHA are recorded above.
- [x] Manual coverage text remains supervisor-owned and preserved; B004 did not edit a manual coverage file.
- [x] No accepted implementation item remains unapplied, no B004 lease remains, and no forbidden lifecycle command ran.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012573","destination_path":"executed-b-agent-research/B004/000470-UserListDialogPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000470-UserListDialogPaneConstructor-source-quality.md","timestamp":"2026-07-15T00:01:57-04:00","uid":"000470"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
