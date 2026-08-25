
# UID0000OQ TextPad Whole-File Source-Quality Report
** TARGET-REPORT-UID:0000OQ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

UID0000OQ is reconstructable as complete NexusTK/ui/dialogs/TextPad.cpp and required TextPad.h. The whole-file inventory resolves nine authored methods, including two raw-but-authored bodies, three compiler-emitted vtable groups, four source literals, all padding, cleanup regions, imports, state dependencies, source order, and adjacent Thread boundaries. The accepted ordinary callback corrected the routed source and dependencies. This report supplies exact formal CPP/H, support historicalization, score and manual-coverage changes, and a proposed supervisor-owned IDA handoff with seven function rename/type/comment entities, two raw address-comment-only entities, and thirteen data-comment entities. No additional target UID is declared.

## Supporting Research

- Original report-time assignment goal SHA256: FE9A1EBA224076562482EA0DFF8C30EB05C94E42CC03F49A96D1238D86FE1C37; prior generated-authority repair override SHA256: 80A52025173BF20DFE2AA1C090F035317B1CF0924AF21E066FCE4BF89C9A2DD7; prior transaction-contract repair override SHA256: 6AE5E080BF26713E0D299D438B4510C22AD630FFCB460645776CC6DBB152273F; final C064 destination-count repair override SHA256: 5C94A1DE46C8AD339782851CFDCFADA1020B79F83724DFBA300D7CBC0D8F76F4; authoritative implementation callback goal SHA256: 67D68567D225FC79FB2DE12503C62692BA13CBF0A0241054D03CA01627797D52; prior Gate 2B raw-frame safe-subset repair goal SHA256: F25FFCEDA4B8DE75D186CA0418159D198EBA840926000549F8A3BB3E4E14392F; current Gate 2B TYPE-PRE contract repair goal SHA256: C3234C346AFAFB0418DBCD2F167C73D22099F1C9454503EACD26C7479CA61356.
- Project skill SHA256: F9C621CC1EC9A8028E9B571D4EB01FECFFF37C3834F943ECA762F04D0004A379; current workflow/template/score rules were applied.
- Primary by-file/TextPad.md UID0000OQ: SHA256 01A7FC1288356976BEC7A63741F03AB3175339810B352F06E43D9A298E2714C4, 18,964 bytes, 134 lines.
- Related exact pages: by-class/TextPad.md UID0000EU; executable UID0001JV, UID0001JW, UID000248; data UID0003DY, UID0003DZ; mixed parent UID00026O; ignored-range UID0000VN; PlatformApi UID0002AS; all named control/editor/event/render/memory/global/source-tree dependencies.
- Historical report-time generated snapshot: validator command 000000026444, refreshed 2026-08-22T06:46:20-04:00, produced TextPad.cpp SHA256 3552E0B8285E03D28AC337B51C3CC0C8C60277D7E85A428089E30D65D6DA7D3D at 5,856 bytes/193 LF-only lines; TextPad.h was physically absent. This dated receipt is not current authority.
- Later read-only generated receipt: validator command 000000026459, refreshed 2026-08-22T09:48:26-04:00, produced TextPad.cpp SHA256 3B7915E04C1EFAE0C1EE3C35DA50DA4903608553F46AAA9C63088E0DE6C59F57 at 5,856 bytes/193 LF-only lines; TextPad.h remained physically absent and the CPP retained the documented stale identities/APIs. This is another dated observation, not timeless authority. Every supervisor Gate 2A must physically reread the then-current command, refresh time, size, SHA256, header presence, and semantics.
- Physically read generated dependencies: DialogPane.h 122D636F9586389EF7123356290601F028937100373BED4059D6C97D3288BF78; TextEditControlPane.h A4A67436DD60585A1DC58B649D0EF363C91AA7DBEA1ECB77A6F761AF8A1642B4; TextEditPane.h 2181D40E69E70A4F84F3956179413EA189AEDCC25FCD21F6ECD7C695C01DD75E; Event.h F8AC312E590A86AE852EB6D999F36DDD81071107099666D88F4B4698498FCAA6; MainUiGraph.h 9FABDD6F4547184FD733647BDC1DC6BD5B0CCDA2CB893CE022EEC02C9C74B78A; PlatformApi.h 44643EF1B6632E8B5350AE0B29FBA5605F7E28FF82ED4638D424458990A6BFBA; Surface.h 8D2D75D2446EFC1C5828ECFFF42ABDD7C92EEC865E8166A73D2288DD9F57B7B8; MemoryMan.h B985D6C94D65827A2164EAC0C541054CED1EE18FB3E8AF60014953F835AF110B.
- Manual coverage and generated tracker were read only; exact stale-row replacements are in Section 28.
- Historical isolated transaction `UID0000OQ-20260822-153330693` is unsaved and superseded. All isolated runtime/function/item/comment/xref/byte/type/instruction prestates passed; A00 declared only incomplete TextPad types in memory; and `define_func` created exact A08/A09 bounds/autonames without geometry, byte, xref, or padding drift. Mandatory MID-RAW `stack_frame` then returned only `__saved_registers@0xc/0x4 _DWORD` and `__return_address@0x10/0x4 _UNKNOWN *` for each raw body, contradicting the required local/argument rows. The supervisor stopped before rename/type/comment, performed no save, created no TX, and left canonical/backup/working physical files unchanged at SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28`, 143,211,242 bytes. No in-memory action receives applied credit.
- Historical isolated transaction `UID0000OQ-20260822-155922093` is also unsaved and superseded. PRE-00-PRE-10 passed against isolated session `supervisor_uid0000oq_gate2b_20260822_155922` and working path `E:\NTK\Resources\NexusTK\gate2b-transactions\UID0000OQ-20260822-155922093\NexusTK.exe.uid0000oq-working.i64`; A00 declared only incomplete TextPad types; the pure seven-function rename and immediate address/name/raw-absence lookup passed. TYPE-PRE then returned exact first lines A01 `DialogPane *__thiscall TextPad__Constructor(DialogPane *this)`, A02 `bool __thiscall TextPad__HandleKeyOrTextEvent(int this, Event *event)`, A03 `void __thiscall TextPad__DrawBackground(GrafPort *this)`, A04 `void TextPad__DrawBorder()`, A05 `void __thiscall TextPad__SendText(_DWORD **this, unsigned int nNumberOfBytesToRead)`, A06 `void __thiscall TextPad__Open(_DWORD **this, DWORD nNumberOfBytesToRead)`, and A07 `void __thiscall TextPad__Save(_DWORD *this, int a2)`. Five contradicted the prior literal pair table, so the supervisor stopped before `set_type`, comments, save, TX creation, or canonical promotion. Working and backup files remained SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28`, 143,211,242 bytes; intended TX was absent. No in-memory action receives applied credit.

## Target

- Primary target only: UID0000OQ by-file/TextPad.md.
- Complete source unit: NexusTK/ui/dialogs/TextPad.cpp and TextPad.h.
- Canonical owner FILE; path remains NexusTK/ui/dialogs/.
- Support UIDs are destinations, not additional report targets.

## Current Target State

The accepted ordinary callback now records UID0000OQ at 94/93 and the routed support scores in the exact eleven by-* destinations; the mutable tracker and manual coverage remain supervisor-owned. Dated commands 26444/26459 are historical stale generated receipts, while the later callback-generated receipts remain dated rather than timeless authority; every fresh Gate 2A rereads live generated state. Gate 2B transactions `UID0000OQ-20260822-153330693` and `UID0000OQ-20260822-155922093` are historical, unsaved, and superseded: the first established the A08/A09 address-comment-only boundary, and the second established the seven exact transaction-local TYPE-PRE first lines now required before `set_type`. The ordinary source remains unchanged.

## Executive Recommendation

1. Keep UID0000OQ and NexusTK/ui/dialogs/.
2. Route UID0000EU/0001JV/0001JW/000248/0003DY/0003DZ at 10/20/30/40/50/60.
3. Replace their formal channels with Section 22.
4. Correct the overrides to HandleKeyOrTextEvent, DrawBackground, DrawBorder.
5. Use current dependency APIs and TextRunFormatData while preserving shipped file arithmetic and absent handle guards.
6. Add g_pfnCreateFileW through UID0002AS H.
7. Historicalize stale normative prose and apply Section 28 coverage text only under supervisor ownership.
8. Apply Section 21 only after fresh Gate 1 and Gate 2A and only in the supervisor-created isolated working copy bound to the supplied exact session/path: after A00 and pure rename, require all seven corrected TYPE-PRE first lines exactly before `set_type`; seven existing functions receive rename/type/function comments, while raw A08/A09 receive address comments only and remain function/name/type/frame absent; the canonical IDB remains read-only.

## Supervisor Active Recheck

Re-read the exact artifact through wholly fresh Gate 1 and Gate 2A and retain the canonical IDB only as dated read-only baseline evidence. At Gate 2B the supervisor creates a new isolated working copy, supplies its exact MCP session and exact physical path, and runs every Section 21 mutation preflight, action, and post-read only against that isolated pair. The seven TYPE-PRE responses must reproduce the exact corrected first lines and complete-body baselines before `set_type`; a first-line mismatch is substantive transaction drift, not harmless formatting. A08/A09 remain deterministic address-comment-only actions: no function definition, rename, type, function comment, decompile pair, or stack-frame read is permitted for either raw start. Any session/path, function-bound/absence, byte, xref, vtable/string, protected-name, padding, first-line/body decompile, raw-item, address-comment, or successor mismatch is a hard stop. This report contains no transaction program; IDA mutation/persistence/rollback, validators, generated refresh, coverage, and lifecycle are supervisor-owned.

## Inference Research Guidance Check

The pass used whole-file owner-first inference: complete base vtable order, adjusted-this mapping, sibling ControlPane contracts, current dependency declarations, source-family comparison, raw-body and neighbor analysis, and compiler-output separation. No sub_, nullsub_, address label, or decompiler variable survives in formal source.

## Heuristic / Inference Reanalysis And Validation

Secondary slot +0x08 is HandleKeyOrTextEvent; its translated-key test and base fallback confirm that identity. Primary cells 0x62e1e0/1e4 are DrawBackground/DrawBorder; live bodies independently confirm fill-rectangle and empty-border behavior. The main-control +0x100 write is inherited m_handlesEnterKey, closed by current ControlPane source and sibling consumers. The raw format helpers use current 12-byte TextRunFormatData and ApplySelectionFormat, rejecting the invented payload/API.

No constructor caller or retained-helper xref is visible, including current bounded xrefs and documented local rel32/dword scans. Unique vptr stores, receiver/state use, duplicated inlining, source proximity, and exact padding still establish TextPad ownership. Those negative results cap reachability/liveness confidence only; they are not unresolved blockers.

## Evidence Standards Used

Live canonical bytes/bounds/xrefs/types are dated read-only research evidence and outrank generated labels; they are not mutation authority. Gate 2B mutation authority is only the supervisor-supplied isolated session/path after the isolated preflight reproduces every protected baseline fact. Current formal dependency declarations outrank stale helper spellings. Human names require convergent behavior/vtable/source-family evidence. Negative evidence is accepted only after bounded searches and neighbor analysis. Compiler EH/RTTI/vtables/padding are documented but not handwritten. Generated files remain read-only dated evidence.

## Evidence Checked

| Evidence | Concrete check | Result |
| --- | --- | --- |
| Canonical IDB | idb_list, runtime_attestation, and server_health | Original report-time session supervisor_uid0003fc_preexecute_20260822 is historical. Fresh repair read at 2026-08-22T14:34:16Z used canonical session b006_uid0000kf_recheck_20260822 and exact E:\NTK\Resources\NexusTK\NexusTK.exe.i64. `idb_list` supplied `is_analyzing:false`; runtime_attestation supplied top-level/listener/canonical-worker route and role-specific manifest success; server_health supplied `status:"ok"`, module NexusTK.exe, Hex-Rays ready, and strings cache false/0. The cache flags did not block the bounded successful IDB queries, and server_health is not credited with `is_analyzing`. |
| Functions | lookup_funcs at seven function entries, two raw starts, and successor | Seven exact functions; A08/A09 function/name/type absent; Thread successor at 0x596250. |
| Items/types/comments | inspect_items, type_inspect, get_comments, stack_frame | Section 21 records every dated canonical literal item/name/type/comment/frame baseline and requires exact isolated-session replay before mutation; TextPad and TextPadEventHandlerFacet were absent, TextRunFormatData was the exact existing 12-byte four-member UDT, no stack mutation is authorized, and the raw starts remain function/frame absent with only regular/repeatable address comments permitted. |
| Xrefs | xref_query direction to | Exact method/vtable/string results in Section 15. |
| Raw/padding | insn_query, inspect_items, get_bytes | Two raw methods and all 0xcc islands exact. |
| Data | get_bytes at 0x62e18c size 220 | Three COLs, 23/11/2 slots, four UTF-16 literals through 0x62e268. |
| Routed source | Physical generated reads | Dated commands 26444 and 26459 both show incomplete CPP and absent H; neither is timeless authority, and every Gate 2A dynamically rereads command/time/size/hash/presence/semantics. |
| Support docs | Physical owner/child/dependency/coverage/tracker reads | Concrete destinations closed; no new UID. |
| Failed Gate 2B transaction | Supervisor receipt `UID0000OQ-20260822-153330693` | All prestates passed and temporary A08/A09 definitions preserved geometry, but MID-RAW exposed only saved-register and return-address rows. Stop occurred before rename/type/comment; no save/TX; three physical files remained SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28`, 143,211,242 bytes. Receipt is historical/superseded and grants no applied credit. |
| Failed TYPE-PRE Gate 2B transaction | Supervisor receipt `UID0000OQ-20260822-155922093` | PRE-00-PRE-10, A00, pure seven-function rename, and immediate lookup passed. TYPE-PRE produced the seven exact corrected first lines in Section 21; five contradicted the prior contract. Stop occurred before `set_type`/comments/save; no TX/promotion; working and backup remained SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28`, 143,211,242 bytes. Receipt is historical/superseded and grants no applied credit. |

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination | Action | Verification State |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000OQ-001 | 0000OQ | TextPad is one complete CPP/H source unit with nine authored methods, exact data consequences, dependencies, and boundaries. | high | Whole-file docs, MCP, and generated inventory. | by-file/TextPad.md UID0000OQ, Status, File Role, Function Map, Reconstruction Status. | incorporate | applied |
| C0000OQ-002 | 0000OQ | Current 88/89 and blank tracker reconstructable metadata are historical scope, not negative evidence. | high | Stable authority: auto-generated/-ag-research-tracker.md -> `## by-file` -> `### Not-Covered Files - Not Reconstructable` -> `[UID:0000OQ][TextPad](by-file/TextPad.md)`; no mutable line number is authoritative. | by-file/TextPad.md UID0000OQ, metadata and Score Rationale. | historicalize | applied |
| C0000OQ-003 | 0000OQ | Canonical placement is NexusTK/ui/dialogs/TextPad.cpp with required TextPad.h. | high | Source tree, owner docs, generated route. | by-file/TextPad.md UID0000OQ, Status and Source Placement. | incorporate | applied |
| C0000OQ-004 | 0000OQ | TextPad adds no source fields and needs no authored destructor declaration or body. | high | Base-state use, vtables, no destructor body. | by-class/TextPad.md UID0000EU, Responsibility, Layout, Reconstruction Notes. | incorporate | applied |
| C0000OQ-005 | 0000OQ | Exact emitter order is UID0000EU, 0001JV, 0001JW, 000248, 0003DY, 0003DZ at positions 10,20,30,40,50,60. | high | Complete source dependency order. | by-class/TextPad.md UID0000EU and by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, 0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW, 0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, 0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, and 0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, EMITTER_POSITION_OPTIONAL metadata and formal-channel order. | incorporate | applied |
| C0000OQ-006 | 0000OQ | 0x00595900-0x00595ae2 is TextPad::TextPad(), size 0x1e2. | high | Live lookup, disassembly, decompile. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Covered Range and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-007 | 0000OQ | Constructor calls DialogPane with empty title, config 0xffff, mode 0, and builds exact full-screen/main/command bounds. | high | Live constructor operands and globals. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Constructor Evidence and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-008 | 0000OQ | Main control uses the exact eleven-argument TextEditControlPane constructor contract. | high | Live call operands and current H. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Constructor Evidence and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-009 | 0000OQ | Main control is added, limited to 2000 lines and 30000 chars, and sets inherited handles-Enter true. | high | Live calls, +0x100 ControlPane contract. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV and by-class/ControlPane.md UID000038 consumer prose. | incorporate | applied |
| C0000OQ-010 | 0000OQ | Command control is child 1 and uses the exact no-vertical-scrollbar constructor flags. | high | Constructor operands and handler lookup. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-011 | 0000OQ | Constructor order is hover 0, clamp full frame, OnCreate root layer, OnShow before screen pane. | high | Calls at 0x595a91-0x595ac0. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV Behavior/RECONSTRUCTION_CPP CODE and by-file/TextPad.md UID0000OQ Function Map. | incorporate | applied |
| C0000OQ-012 | 0000OQ | Constructor cleanup range 0x609900-0x609943 is compiler-only EH/delete/cookie output. | high | Exception references and ordinary construction. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Compiler Output. | incorporate | applied |
| C0000OQ-013 | 0000OQ | 0x00595af0 is secondary-view HandleKeyOrTextEvent, not OnKeyInput. | high | Secondary vtable slot +0x08 and live body. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ identity tables and RECONSTRUCTION_CPP CODE / RECONSTRUCTION_H CODE. | reject-stale | applied |
| C0000OQ-014 | 0000OQ | Handler requires translated key 13, active control 1, and kEventKeyDown. | high | Live decompile and Event enum. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-015 | 0000OQ | Handler reads child 1 to 1023 chars, sends text, selects 0..0x7fff, else calls the base. | high | Live call and data flow. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-016 | 0000OQ | 0x00595bb0 is DrawBackground using color 0x80, mode 0, and g_pfnFillRect on m_visibleBounds. | high | Primary slot +0x50 and disassembly. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ formal/prose and Surface dependency. | reject-stale | applied |
| C0000OQ-017 | 0000OQ | 0x00595bd0 is the empty DrawBorder override. | high | Primary slot +0x54 and one-byte return. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ formal/prose. | reject-stale | applied |
| C0000OQ-018 | 0000OQ | Historical OnClose, OnEmptyVirtual, and close/hide prose are invalid. | high | Complete primary vtable order. | by-file/TextPad.md UID0000OQ; by-class/TextPad.md UID0000EU; by-memory/0x00595900-0x00596242.TextPad.md UID0001JV; 0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW; 0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248; 0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY; 0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ; 0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O; by-memory/-ignored.md UID0000VN, normative and historical identity sections. | reject-invalid | applied |
| C0000OQ-019 | 0000OQ | 0x00595be0-0x00595f26 is private SendText with sole code caller 0x595b64. | high | Live lookup and xref. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW. | incorporate | applied |
| C0000OQ-020 | 0000OQ | Prefix tests are direct wcsstr(input,prefix)==input with no null guard. | high | Live decompile. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW behavior/RECONSTRUCTION_CPP CODE and generated-defect history. | reject-stale | applied |
| C0000OQ-021 | 0000OQ | Prefix offsets are 5,5,8,9 wchar units and format values use decimal wide scan. | high | Branch operands and scan calls. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-022 | 0000OQ | SendText inlines four retained helpers while out-of-line copies remain authored source. | high | Identical flows and retained bodies. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW and by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Relationship/Reconstruction Notes. | incorporate | applied |
| C0000OQ-023 | 0000OQ | 0x00595f30-0x00596065 is retained Open(const wchar_t*), size 0x135. | high | Live lookup and decompile. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248. | incorporate | applied |
| C0000OQ-024 | 0000OQ | Open uses read/open-existing/sequential CreateFileW flags and has no invalid-handle guard. | high | Live decompile and API constants. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-025 | 0000OQ | Open allocates fileSize+1, reads fileSize, and performs the shipped word write at buffer+2*fileSize. | high | Exact live instructions. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE anomaly note. | incorporate | applied |
| C0000OQ-026 | 0000OQ | Open reads payload length at +2*textChars+2 and uses the shipped payload pointer +textChars+5. | high | Exact live addressing. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 file-format section and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-027 | 0000OQ | Open pastes through main child TextEditPane and frees through MemoryMan. | high | Live calls and current declarations. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-028 | 0000OQ | 0x00596070-0x005961c8 is retained Save(const wchar_t*), size 0x158. | high | Live lookup and decompile. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Covered Range and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-029 | 0000OQ | Save preserves short caret range around select-all and CopySelectionToScrap. | high | Live flow and current H. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-030 | 0000OQ | Save writes text bytes, one zero byte, optional four-byte payload size, then payload bytes. | high | Live WriteFile sequence. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 file-format section and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-031 | 0000OQ | Save has no handle guard and frees both optional duplicate buffers via MemoryMan. | high | Live branches and calls. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| C0000OQ-032 | 0000OQ | Raw 0x005961d0-0x00596204 is SetFont using TextRunFormatData +0 and mask 1; formal source is implemented, while the proposed IDA disposition is address-comment-only with function/name/type/frame absent. | high | Live raw instructions/type layout, accepted ordinary callback, and failed MID-RAW receipt. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Covered Range and RECONSTRUCTION_CPP CODE; this report Section 21 A08 address-comment-only recommendation. | incorporate | applied to ordinary destination; IDA remains proposed under C0000OQ-060 |
| C0000OQ-033 | 0000OQ | Raw 0x00596210-0x00596242 is SetColor using TextRunFormatData +4 and mask 2; formal source is implemented, while the proposed IDA disposition is address-comment-only with function/name/type/frame absent. | high | Live raw instructions/type layout, accepted ordinary callback, and failed MID-RAW receipt. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Covered Range and RECONSTRUCTION_CPP CODE; this report Section 21 A09 address-comment-only recommendation. | incorporate | applied to ordinary destination; IDA remains proposed under C0000OQ-060 |
| C0000OQ-034 | 0000OQ | Every internal separator is exact 0xcc padding and the successor starts at 0x00596250; A08/A09 remain raw code outside functions and their address-comment-only actions preserve every separator and successor fact. | high | Live bytes/items plus failed-transaction geometry receipt. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, by-memory/-ignored.md UID0000VN, and this report Section 21 P01. | incorporate | applied to ordinary destinations; IDA protection remains proposed under C0000OQ-060 |
| C0000OQ-035 | 0000OQ | Current TextRunFormatData and ApplySelectionFormat replace the invented payload and InsertTextObject. | high | Current TextEditPane H and live type. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 RECONSTRUCTION_CPP CODE/prose; by-class/TextEditPane.md already-present support. | reject-invalid | applied |
| C0000OQ-036 | 0000OQ | Zero xrefs to standalone starts are a retained-liveness cap, not dead/no-code proof. | strong | Live xrefs and duplicated/inlined source family. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU negative evidence and scores. | incorporate | applied |
| C0000OQ-037 | 0000OQ | Vtable data is exactly 0x9c bytes: three COL cells plus 23,11,2 slots. | high | Live 220-byte read and constructor stores. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY. | incorporate | applied |
| C0000OQ-038 | 0000OQ | Exact overridden cells are DrawBackground, DrawBorder, and HandleKeyOrTextEvent. | high | Vtable order and cell xrefs. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY plus by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ. | reject-stale | applied |
| C0000OQ-039 | 0000OQ | RTTI, COLs, and vtables are compiler-emitted; UID0003DY emits only a covered-by comment. | high | Ordinary class declaration explains data. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY RECONSTRUCTION_CPP CODE and no-code disposition. | incorporate | applied |
| C0000OQ-040 | 0000OQ | Command-string range is exact 0x40 bytes with four literals and one xref each. | high | Live bytes, items, xrefs. | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ. | incorporate | applied |
| C0000OQ-041 | 0000OQ | Three short IDA string heads must not trigger tail resize or retyping. | high | Current itemization versus exact bytes. | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ IDA status and report Section 21 protections. | incorporate | applied |
| C0000OQ-042 | 0000OQ | Dword 0x0062e268 and function 0x00596250 belong to Thread and are excluded. | high | Neighbor bytes, items, docs. | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O boundary prose. | incorporate | applied |
| C0000OQ-043 | 0000OQ | File dependencies are CreateFileW dispatch plus GetFileSize, ReadFile, WriteFile, CloseHandle, and CRT wide routines. | high | Live refs and current imports. | by-file/TextPad.md UID0000OQ Dependencies; by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 and by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW evidence. | incorporate | applied |
| C0000OQ-044 | 0000OQ | Globals are screen dimensions, root layer slot, screen pane, event manager, and Surface fill callback. | high | Constructor, handler, draw refs. | by-file/TextPad.md UID0000OQ Dependencies and exact by-global cross-references. | incorporate | applied |
| C0000OQ-045 | 0000OQ | No TextPad-owned writable globals, resources, or statics exist beyond source literals and pooled empty string. | strong | Whole-file data/xref inventory. | by-file/TextPad.md UID0000OQ Data, Resources, Negative Evidence. | incorporate | applied |
| C0000OQ-046 | 0000OQ | TextEditScrap owns text/payload copying and duplication used by TextPad. | high | Current UID0000EP H and live calls. | by-class/TextEditScrap.md UID0000EP, existing API section. | already-present | applied |
| C0000OQ-047 | 0000OQ | Allocation/free route is GetMemoryMan with AllocateBufferMemory and FreeBufferMemory. | high | Live calls and UID00007U/0001BC declarations. | by-class/MemoryMan.md UID00007U and by-memory GetMemoryMan by-memory/0x00516030-0x00516036.GetMemoryMan.md UID0001BC. | already-present | applied |
| C0000OQ-048 | 0000OQ | PlatformApi H lacks the required exact g_pfnCreateFileW extern. | high | Physical H read and dispatch-slot reference. | by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md UID0002AS RECONSTRUCTION_H CODE and by-file/PlatformApi.md prose. | incorporate | applied |
| C0000OQ-049 | 0000OQ | Dated command-26444 and command-26459 generated TextPad snapshots have wrong event/background/border identities; neither receipt is timeless authority. | high | Dated generated reads versus live vtables; dynamic Gate 2A reread required. | by-file/TextPad.md UID0000OQ, by-class/TextPad.md UID0000EU, by-memory/0x00595900-0x00596242.TextPad.md UID0001JV historical generated-defect prose and dynamic generated verification. | historicalize | applied |
| C0000OQ-050 | 0000OQ | Dated command-26444 and command-26459 generated constructor snapshots use abbreviated or wrong control/create/layer/show APIs; every Gate 2A rereads current semantics. | high | Dated generated reads versus live operands/current H. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV and by-file/TextPad.md UID0000OQ historical generated comparison and dynamic generated verification. | historicalize | applied |
| C0000OQ-051 | 0000OQ | Dated command-26444 and command-26459 generated helper snapshots use nonexistent editor/memory/format APIs and an unsupported null-guard source shape; every Gate 2A rereads current semantics. | high | Dated generated reads versus dependencies/live bodies. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW and by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 historical generated comparison and dynamic generated verification. | historicalize | applied |
| C0000OQ-052 | 0000OQ | TextPad.h is absent in both dated generated receipts and remains a completion defect requiring a complete class declaration, subject to dynamic Gate 2A presence/readback. | high | Dated physical absence and cross-TU class use. | by-class/TextPad.md UID0000EU RECONSTRUCTION_H CODE and by-file/TextPad.md UID0000OQ Reconstruction Status and dynamic generated verification. | incorporate | applied |
| C0000OQ-053 | 0000OQ | Section 22 CPP is the complete C++03 source recommendation. | high | Reconciled live/source contracts. | by-class/TextPad.md UID0000EU, 0001JV, 0001JW, 000248, 0003DY, 0003DZ RECONSTRUCTION_CPP CODE channels. | incorporate | applied |
| C0000OQ-054 | 0000OQ | Section 22 H is the complete TextPad declaration with no fields or explicit destructor. | high | Vtable/source inventory and base contract. | by-class/TextPad.md UID0000EU RECONSTRUCTION_H CODE. | incorporate | applied |
| C0000OQ-055 | 0000OQ | Main executable page must replace stale behavior, identities, provisional flags, and open questions. | high | Current page versus closed research. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV normative sections. | incorporate | applied |
| C0000OQ-056 | 0000OQ | File and class pages must carry complete inventory, corrected identities, source order, dependencies, and caps. | high | Whole-file report. | by-file/TextPad.md UID0000OQ and by-class/TextPad.md UID0000EU. | incorporate | applied |
| C0000OQ-057 | 0000OQ | Vtable, string, and aggregate pages must replace stale slot labels and record compiler/source-literal dispositions. | high | Live data reconciliation. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O TextPad subsections. | incorporate | applied |
| C0000OQ-058 | 0000OQ | Proposed scores are 94/93, 94/93, 94/94, 93/94, 93/93, 92/96, 92/96 for file/class/main/command/standalone/vtable/strings. | strong | Closed inventory with named residual caps. | by-file/TextPad.md UID0000OQ; by-class/TextPad.md UID0000EU; by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, 0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW, 0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, 0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, and 0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, metadata and Score Rationale. | incorporate | applied |
| C0000OQ-059 | 0000OQ | No new UID, split, owner, resource, or source file is justified. | high | Exhaustive code/data/neighbor inventory. | by-file/TextPad.md UID0000OQ Range, Split, Ownership sections. | not-applicable | applied |
| C0000OQ-060 | 0000OQ | The IDA handoff is a proposed isolated-transaction contract for seven existing function rename/type/comment entities with seven exact corrected TYPE-PRE first lines, two raw address-comment-only entities, thirteen data-comment entities, and seven direct decompile pairs; A08/A09 must remain function/name/type/frame absent. | high | Dated canonical prestates, failed unsaved transactions `UID0000OQ-20260822-153330693` and `UID0000OQ-20260822-155922093`, and current public schemas; supervisor-time isolated replay remains mandatory and no mutation receipt is claimed. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ, Section 21 PRE-00-PRE-10, A00-A09, exact TYPE-PRE/TYPE-POST-A01-A07 table, POST-01-POST-08, and both failed-transaction histories. | incorporate | proposed |
| C0000OQ-061 | 0000OQ | Thirteen COL/vtable/slot/string and two raw-start address-comment entities have per-entity physical item/name/type/byte/xref/comment prestates, exact comments, protected tails/neighbors, and deterministic readbacks; the raw starts additionally require function/name/type/frame absence. | high | Fresh canonical compiler/data identity, partial string itemization, exact raw geometry, and failed MID-RAW receipt. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ, Section 21 A08-A09, D01a-D09, P01-P02, and POST-01-POST-08. | incorporate | proposed |
| C0000OQ-062 | 0000OQ | Gate 2B replay of the corrected seven-pair TYPE-PRE contract and unchanged address-comment-only safe subset, persistence, rollback, and lifecycle are external supervisor work; both failed unsaved transactions grant no applied credit and no operational package is embedded. | high | Current workflow role boundary and two historical failed-transaction receipts. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ Section 21 external handoff and Validator Results; supervisor Gate 2B persistence/rollback and validator lifecycle actions. | not-applicable | proposed |
| C0000OQ-063 | 0000OQ | Seven exact manual coverage row replacements or inserts are required. | high | Read-only coverage comparison. | by-file/-coverage-report.md UID0000OQ row; by-class/-coverage-report.md UID0000EU row; by-memory/-coverage-report.md UID0001JV, UID0001JW, UID000248, UID0003DY, and UID0003DZ rows; Exact Manual Supervisor-Owned Coverage Or Tracker Text. | incorporate | proposed |
| C0000OQ-064 | 0000OQ | Later callback edits and validates exactly eleven ordinary destinations: `by-file/TextPad.md`; `by-class/TextPad.md`; `by-memory/0x00595900-0x00596242.TextPad.md` UID0001JV; `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md` UID0001JW; `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md` UID000248; `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md` UID0003DY; `by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md` UID0003DZ; `by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md` UID00026O; `by-memory/-ignored.md`; `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` UID0002AS; and `by-file/PlatformApi.md`. Already-present unchanged dependency pages are excluded. Every supervisor Gate 2A also dynamically rereads then-current generated command/time/size/hash/presence/semantics for TextPad CPP/H and PlatformApi H. | high | Exact accepted ordinary destination set plus mutable generated-authority workflow rule and dated 26444/26459 receipts. | B003 implementation/scoped validation: the exact eleven ordinary paths named in this claim, no others. Supervisor Gate 2A dynamic physical readback: `auto-generated/NexusTK/ui/dialogs/TextPad.cpp`, `auto-generated/NexusTK/ui/dialogs/TextPad.h`, and `auto-generated/NexusTK/platform/PlatformApi.h`. | incorporate | applied |
| C0000OQ-065 | 0000OQ | Report remains lifecycle-neutral with exactly one physically terminal readiness marker; lifecycle authority remains external. | high | Current TYPE-PRE repair goal SHA256 C3234C346AFAFB0418DBCD2F167C73D22099F1C9454503EACD26C7479CA61356 and physical report-end readback. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ, terminal line after the Implementation Tracking Checklist; validator-owned report status/history. | incorporate | applied |

## Positive Evidence Summary

- Seven modeled and two raw authored methods form one TextPad family.
- Constructor stores all three TextPad vtable heads and builds a unique full-screen two-control dialog.
- SendText has one caller; each command literal has one SendText xref.
- Complete vtable ordering resolves all stale virtual names.
- Current dependency APIs resolve every former helper/type blocker.
- File envelope, allocation ownership, padding, compiler regions, and both adjacent owners are exact.
- No hidden TextPad body, data island, global, resource, or table remains unassigned.

## IDA MCP Facts

- Historical report-time session supervisor_uid0003fc_preexecute_20260822 used canonical E:\NTK\Resources\NexusTK\NexusTK.exe.i64, input C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe, imagebase 0x400000; its 2026-08-22T11:56:35Z attestation returned top-level/listener/canonical-worker ok and role-specific manifests remained separate.
- Fresh repair read used canonical session b006_uid0000kf_recheck_20260822. At 2026-08-22T14:34:16Z, `idb_list` returned the selected canonical row with `is_analyzing:false`; runtime_attestation returned top-level/listener/canonical-worker ok for the exact canonical path; server_health returned status ok, Hex-Rays ready, strings cache false/0, and auto_analysis_ready false. The cache flags were context, not outage, because every bounded lookup/item/comment/xref/byte/frame/type query succeeded. Only `idb_list`, not server_health, supplies the analysis-running state.
- The dated canonical literal functions were sub_595900 [0x595900,0x595ae2), sub_595AF0 [0x595af0,0x595ba9), sub_595BB0 [0x595bb0,0x595bcf), nullsub_60 [0x595bd0,0x595bd1), sub_595BE0 [0x595be0,0x595f26), sub_595F30 [0x595f30,0x596065), and sub_596070 [0x596070,0x5961c8). Raw starts 0x5961d0 and 0x596210 were code without functions; Thread successor sub_596250 was [0x596250,0x5963f2). Gate 2B must reproduce and preserve that function-absence state in the isolated working copy; A08/A09 receive address comments only.
- The dated canonical stored function-item declarations were `__int16 *__thiscall(__int16 *this)`, `char __thiscall(int this, _BYTE *)`, `int __thiscall(int this)`, `void()`, `void __thiscall(_DWORD **this, const wchar_t *nNumberOfBytesToRead)`, `void __thiscall(_DWORD **this, DWORD nNumberOfBytesToRead)`, and `void __thiscall(_DWORD *this, int)` in address order. Every action-head regular/repeatable address comment and all seven existing function regular/repeatable comments were empty. Those exact stored declarations remain PRE-04 item expectations, but they are not substitutes for transaction-local Hex-Rays TYPE-PRE first lines after A00 and pure rename.
- TextPad and TextPadEventHandlerFacet are absent. TextRunFormatData is the existing 12-byte UDT with unsigned __int16 legacyAssetMode +0, unsigned __int16 reserved02 +2, unsigned int textColor +4, and TextEditObject *object +8; Event is an existing 272-byte UDT.
- Historical isolated transaction `UID0000OQ-20260822-153330693` passed all prestates and temporarily defined exact A08/A09 bounds, but its mandatory MID-RAW `stack_frame` returned only `__saved_registers@0xc/0x4 _DWORD` and `__return_address@0x10/0x4 _UNKNOWN *` for each body. That contradicted the report's promised local/argument rows, so the supervisor stopped before rename/type/comment and saved nothing. It is superseded evidence for the final address-comment-only disposition, not an applied receipt.
- Historical isolated transaction `UID0000OQ-20260822-155922093` passed PRE-00-PRE-10, declared only incomplete TextPad/TextPadEventHandlerFacet types, completed the pure seven-function rename, and passed immediate address/name/raw-absence lookup. Before `set_type`, Hex-Rays returned exact first lines A01 `DialogPane *__thiscall TextPad__Constructor(DialogPane *this)`, A02 `bool __thiscall TextPad__HandleKeyOrTextEvent(int this, Event *event)`, A03 `void __thiscall TextPad__DrawBackground(GrafPort *this)`, A04 `void TextPad__DrawBorder()`, A05 `void __thiscall TextPad__SendText(_DWORD **this, unsigned int nNumberOfBytesToRead)`, A06 `void __thiscall TextPad__Open(_DWORD **this, DWORD nNumberOfBytesToRead)`, and A07 `void __thiscall TextPad__Save(_DWORD *this, int a2)`. A00 made the two intended target type names available only as incomplete declarations, while pure rename changed symbols without setting signatures; Hex-Rays then recomputed pseudocode from the unchanged stored tinfo plus propagated body/callee/frame evidence. That produced existing DialogPane/Event/GrafPort types, inferred bool/void/scalar types, and auto-name `a2` in the transaction-local first lines. These are semantic TYPE-PRE baselines, not formatting aliases of PRE-04. The supervisor stopped at the five literal mismatches before `set_type`, comments, save, TX, or promotion; no in-memory action is applied.

## Function / Child Inventory

| Range | Size | Source item | Disposition |
| --- | ---: | --- | --- |
| 0x00595900-0x00595ae2 | 0x1e2 | TextPad::TextPad | UID0001JV CPP |
| 0x00595ae2-0x00595af0 | 0x0e | alignment | compiler padding |
| 0x00595af0-0x00595ba9 | 0xb9 | HandleKeyOrTextEvent | UID0001JV CPP |
| 0x00595ba9-0x00595bb0 | 0x07 | alignment | compiler padding |
| 0x00595bb0-0x00595bcf | 0x1f | DrawBackground | UID0001JV CPP |
| 0x00595bcf-0x00595bd0 | 0x01 | alignment | compiler padding |
| 0x00595bd0-0x00595bd1 | 0x01 | DrawBorder | UID0001JV CPP |
| 0x00595bd1-0x00595be0 | 0x0f | alignment | compiler padding |
| 0x00595be0-0x00595f26 | 0x346 | SendText | UID0001JW CPP |
| 0x00595f26-0x00595f30 | 0x0a | alignment | compiler padding |
| 0x00595f30-0x00596065 | 0x135 | Open | UID000248 CPP |
| 0x00596065-0x00596070 | 0x0b | alignment | compiler padding |
| 0x00596070-0x005961c8 | 0x158 | Save | UID000248 CPP |
| 0x005961c8-0x005961d0 | 0x08 | alignment | compiler padding |
| 0x005961d0-0x00596204 | 0x34 | SetFont raw | remain outside a function; address-comment-only IDA disposition; UID000248 CPP |
| 0x00596204-0x00596210 | 0x0c | alignment | compiler padding |
| 0x00596210-0x00596242 | 0x32 | SetColor raw | remain outside a function; address-comment-only IDA disposition; UID000248 CPP |
| 0x00596242-0x00596250 | 0x0e | alignment | compiler padding |
| 0x0062e18c-0x0062e228 | 0x9c | 3 COL plus 23/11/2 slots | compiler-emitted; UID0003DY marker |
| 0x0062e228-0x0062e268 | 0x40 | four command literals | source literals; UID0003DZ marker |
| 0x0062e268 onward | n/a | Thread data | excluded successor |

### Complete vtable inventory

- Complete-object-locator cells are 0x0062e18c, 0x0062e1ec, and 0x0062e21c. Constructor stores the corresponding decorated vtable heads at primary +0x00, secondary +0xa0, and tertiary +0xa4.
- Primary group 0x0062e190-0x0062e1ec has 23 slots: +0x00 deleting destructor, +0x04 GetRuntimeClass, +0x08 OnChangeMessage, +0x0c UpdateRenderRegion, +0x10 three-argument no-op extension, +0x14 Show, +0x18 Hide, +0x1c GetParentPane, +0x20 InvalidateRect, +0x24 GetDescription, +0x28 GetScreenBounds, +0x2c SetBounds, +0x30 OnCreate, +0x34 InsertInLayer, +0x38 OnDestroy, +0x3c OnShow, +0x40 OnHide, +0x44 OnPaint, +0x48 OnControlCommand, +0x4c UpdateActionButton, +0x50 TextPad::DrawBackground, +0x54 TextPad::DrawBorder, +0x58 SetHoverControl.
- Secondary group 0x0062e1f0-0x0062e21c has 11 slots: +0x00 deleting-destructor adjustor, +0x04 HandlePointerOrMouseEvent, +0x08 TextPad::HandleKeyOrTextEvent, +0x0c HandleImeEvent, +0x10 false HandlePacketEvent, +0x14 HandleSystemOrControlEvent, +0x18 HandleType19Event, +0x1c ForwardHandlerOrder, +0x20 GetLocalEventPair, +0x24 GetScreenEventPair, +0x28 ShouldAcceptEvent.
- Tertiary group 0x0062e220-0x0062e228 has two slots: +0x00 deleting-destructor adjustor and +0x04 inherited OnTimer.
- All non-TextPad slots are inherited/compiler consequences. TextPad authors only the three overrides named above; no raw vtable array or destructor wrapper is handwritten.

### Complete non-code, type, import, and resource inventory

- Literal/data layout is exact: L'Open ' at 0x0062e228-0x0062e234 (12 bytes), L'Save ' at 0x0062e234-0x0062e240 (12), L'SetFont ' at 0x0062e240-0x0062e252 (18), two zero alignment bytes at 0x0062e252-0x0062e254, and L'SetColor ' at 0x0062e254-0x0062e268 (20). The next dword is Thread's locator.
- TextPad declares no fields. All observed state is inherited from DialogPane, Pane/EventHandler facets, and GrafPort; live DialogPane size is 0x26c. No speculative TextPad size guard is recommended because the external allocation route is stripped.
- Source-visible types are TextPad, Event/EventType, RectBounds, TextEditControlPane, TextEditPane, TextEditScrap, TextRunFormatData, MemoryMan, Layer/MainUiLayerSlots, ScreenPane, and Win32 HANDLE/DWORD APIs. No new enum, packed format struct, or TextPad-local layout is required.
- Globals/constants are g_screenWidth, g_screenHeight, g_mainUiLayerSlots.rootPaneLayerContext, g_pScreenPane, g_pEventMan, g_pfnFillRect, control ids 0/1, key 13, event kEventKeyDown, limits 2000/30000, colors 0x80/0x8f, selection endpoint 0x7fff, and format masks 1/2.
- Imported/platform calls are g_pfnCreateFileW, GetFileSize, ReadFile, WriteFile, CloseHandle, wcsstr, wcslen, and the source-facing decimal wide scan. Memory ownership routes through GetMemoryMan. No TextPad-owned writable global/static, Windows resource, external asset, packet/protocol item, or additional data island exists.

Cleanup ranges 0x609900-0x609943, 0x609943-0x60996e, 0x60996e-0x609991, and 0x609991-0x6099b4 are compiler EH/cookie/destructor consequences, not separate source bodies.

## Direct Xref / Caller Inventory

| Target | Exact inbound result |
| --- | --- |
| 0x595900 | zero |
| 0x595af0 | data from 0x62e1f8 |
| 0x595bb0 | data from 0x62e1e0 |
| 0x595bd0 | data from 0x62e1e4 |
| 0x595be0 | code from 0x595b64 in handler |
| 0x595f30, 0x596070, 0x5961d0, 0x596210 | zero each |
| 0x62e190, 0x62e1f0, 0x62e220 | stores from 0x595940, 0x595946, 0x595950 |
| 0x62e228, 0x62e234, 0x62e240, 0x62e254 | one each from 0x595c0d, 0x595d35, 0x595e79, 0x595ec5 |
| 0x62e268 | zero direct; Thread ownership independently established |

## Documentation Evidence And IDA Status

The authorized callback corrected the file/class/main/support pages while preserving their historical stale identities and provisional language as history. The dated canonical receipt found only Open fully defined among the four command literals, with the other three as four-byte heads, plus seven stale function names/types, two raw starts, and blank comments. Gate 2B must reproduce those facts in its isolated session, rename/type/comment only the seven existing functions, and change only regular/repeatable address comments at the two raw starts. Decorated vtable names are valid and protected.

## Ranked Ownership Analysis

1. TextPad.cpp / UID0000OQ: unique constructor vptr stores, full-screen graph, one handler/command route, literals, receiver offsets, duplicated helpers.
2. TextEditPane/TextEditControlPane: editor dependencies only.
3. PlatformApi/FileIO: dispatch dependency only.
4. TextDialog, EditablePaperPane, terminal, chat: rejected by vtables, controls, literals, and route.
5. Dead/compiler-only helper island: rejected; retained ordinary methods explain out-of-line copies plus inlining.

## Source Placement

Keep TextPad.cpp/TextPad.h under NexusTK/ui/dialogs. UID0000EU owns preamble/header and closes the class before UID0001JV, UID0001JW, UID000248 bodies. UID0003DY/UID0003DZ add inert covered-by comments. UID0002AS independently adds the PlatformApi extern. No source moves to controls/editor/platform/terminal/chat or a new file.

## Range / Split / Padding / Reclassification Analysis

Existing UIDs already cover every exact authored subrange, so no split/new UID is needed. All Section 14 gaps are 0xcc. Thread starts at 0x00596250. Read-only TextPad begins at COL 0x0062e18c and ends before Thread dword 0x0062e268. UID0003DY/UID0003DZ remain exact children of mixed non-emitting UID00026O but are reconstructable through covered-by source consequences.

## Negative Evidence Summary

No direct constructor caller, retained-helper xref, TextPad destructor body, TextPad field, writable global, external resource, extra static table/literal, or additional source body was found. No evidence supports manual RTTI/vtable arrays, string-tail retyping, separate helper file, new UID, or generated stale APIs. The first failed isolated transaction proved that public MID-RAW frame output cannot support A08/A09 function/type actions, so the raw address-comment-only disposition is final. The second proved that a post-A00/pure-rename Hex-Rays first line can differ materially from the stored item declaration: DialogPane/Event/GrafPort propagation, bool/void/scalar inference, and `a2` auto-naming are exact transaction state and cannot be dismissed as formatting. The corrected seven-line TYPE-PRE contract resolves that blocker without changing complete-body semantics or ordinary source. Stripped private spellings remain inferred but final source names are selected from convergent class vocabulary.

## IDA Rename / Type / Comment Recommendations

The canonical session b006_uid0000kf_recheck_20260822 and canonical path E:\NTK\Resources\NexusTK\NexusTK.exe.i64 are dated read-only research evidence only and are forbidden mutation targets. At Gate 2B the supervisor supplies two exact opaque values for one supervisor-created isolated working copy: `DB` is that isolated MCP session ID only, and `ISOLATED_PATH` is that isolated working copy's exact physical path only. Before PRE-00, the supervisor substitutes those values once; they remain immutable through every preflight, action, direct decompile pair, and post-read. Every `database` field below binds only to `DB`, never to the canonical session. The literal baseline facts are from the 2026-08-22T14:34:16Z canonical receipt, but every one must be reproduced directly in the isolated transaction before mutation. B003 performed no mutation or save.

### Deterministic preflight

| Step | Literal current public request | Exact acceptance or stop |
| --- | --- | --- |
| PRE-00 | `idb_list({})`; then `runtime_attestation({"expected_database":"DB","expected_canonical_path":"ISOLATED_PATH"})` | `idb_list` must contain the selected row whose `session_id` equals the supervisor-supplied `DB`, whose `filename` equals the supervisor-supplied `ISOLATED_PATH`, and whose `is_analyzing` is exactly `false`; the canonical session/path must not match either value. runtime_attestation must return top-level `ok:true` for that same exact isolated session/path, with listener and selected worker each passing role/freshness/process/endpoint/source-root/role-specific-manifest validation. Missing, duplicate-selected, or mismatched session/path evidence stops before mutation. |
| PRE-01 | `server_health({"database":"DB"})` | `status:"ok"`, `idb_path` exactly equals `ISOLATED_PATH`, expected module/imagebase/input, and Hex-Rays ready. server_health does not supply `is_analyzing` and is not analysis-idle authority. `auto_analysis_ready:false` or an unready string cache alone is allowed only while PRE-00 has `is_analyzing:false` and all following bounded reads succeed. |
| PRE-02 | `lookup_funcs({"database":"DB","queries":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070","0x5961d0","0x596210","0x596250"]})` | Exact seven old names/bounds in the function-prestate table; raw starts return `fn:null,error:"Not a function"`; successor is `sub_596250`, size 0x1a2. |
| PRE-03 | `lookup_funcs({"database":"DB","queries":["TextPad__Constructor","TextPad__HandleKeyOrTextEvent","TextPad__DrawBackground","TextPad__DrawBorder","TextPad__SendText","TextPad__Open","TextPad__Save"]})` | Every one of the seven proposed function names returns `fn:null,error:"Not found"`; any collision stops before mutation. No function name is proposed for A08/A09. |
| PRE-04 | `inspect_items({"database":"DB","addrs":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070","0x5961c8","0x5961d0","0x5961d1","0x5961d3","0x5961d6","0x5961dc","0x5961de","0x5961e0","0x5961e3","0x5961e5","0x5961eb","0x5961ef","0x5961f3","0x5961f6","0x5961f7","0x5961f9","0x5961fe","0x596200","0x596201","0x596204","0x596210","0x596211","0x596213","0x596216","0x59621c","0x59621e","0x596220","0x596223","0x596225","0x59622b","0x59622e","0x596231","0x596234","0x596235","0x596237","0x59623c","0x59623e","0x59623f","0x596242","0x596250","0x62e18c","0x62e190","0x62e1e0","0x62e1e4","0x62e1ec","0x62e1f0","0x62e1f8","0x62e21c","0x62e220","0x62e224","0x62e228","0x62e234","0x62e238","0x62e23c","0x62e23d","0x62e23e","0x62e23f","0x62e240","0x62e244","0x62e252","0x62e254","0x62e258","0x62e268"]})` | Every literal head/end/width/kind/name/type below matches; no containment substitution or merged item is accepted. |
| PRE-05 | `get_comments({"database":"DB","addrs":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070","0x5961d0","0x596204","0x596210","0x596242","0x596250","0x62e18c","0x62e190","0x62e1e0","0x62e1e4","0x62e1ec","0x62e1f0","0x62e1f8","0x62e21c","0x62e220","0x62e228","0x62e234","0x62e238","0x62e23c","0x62e23d","0x62e23e","0x62e23f","0x62e240","0x62e244","0x62e252","0x62e254","0x62e258","0x62e268"]})` | Every regular/repeatable address channel is `""`; all seven existing function regular/repeatable channels are also `""`; A08/A09 expose no function-comment channel because PRE-02 requires no function. Any nonblank or raw function-comment channel stops. |
| PRE-06a | `xref_query({"database":"DB","queries":[{"addr":"0x595900","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x595af0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x595bb0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x595bd0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x595be0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x595f30","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x596070","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x5961c8","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x5961d0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x596204","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x596210","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x596242","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x596250","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e18c","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e190","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1e0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1e4","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1ec","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1f0","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1f8","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e21c","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e220","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e228","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e234","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e240","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e254","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e268","direction":"to","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true}]})` | Exact inbound results in the literal tables and Section 15; each `next_offset:null`, no truncation. Extra, missing, or changed xrefs stop. |
| PRE-06b | `xref_query({"database":"DB","queries":[{"addr":"0x5961f9","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x596237","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e18c","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e190","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1e0","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1e4","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1ec","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1f0","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e1f8","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e21c","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e220","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e228","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e234","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e240","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true},{"addr":"0x62e254","direction":"from","xref_type":"any","count":50,"offset":0,"sort_by":"addr","descending":false,"dedup":true,"include_fn":true}]})` | Raw calls and every D-row outbound result exactly match the literal tables; each `next_offset:null`, no truncation. Extra, missing, or changed xrefs stop. |
| PRE-07 | `stack_frame({"database":"DB","addrs":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070"]})` | Exact ordered rows in the frame-baseline table, including all locals, arguments, saved-register rows, return-address rows, and required absences. |
| PRE-08 | `get_bytes({"database":"DB","regions":[{"addr":"0x595900","size":8},{"addr":"0x595af0","size":8},{"addr":"0x595bb0","size":8},{"addr":"0x595bd0","size":1},{"addr":"0x595be0","size":8},{"addr":"0x595f30","size":8},{"addr":"0x596070","size":8},{"addr":"0x5961c8","size":8},{"addr":"0x5961d0","size":52},{"addr":"0x596204","size":12},{"addr":"0x596210","size":50},{"addr":"0x596242","size":14},{"addr":"0x596250","size":8},{"addr":"0x62e18c","size":4},{"addr":"0x62e190","size":4},{"addr":"0x62e1e0","size":4},{"addr":"0x62e1e4","size":4},{"addr":"0x62e1ec","size":4},{"addr":"0x62e1f0","size":4},{"addr":"0x62e1f8","size":4},{"addr":"0x62e21c","size":4},{"addr":"0x62e220","size":4},{"addr":"0x62e228","size":12},{"addr":"0x62e234","size":12},{"addr":"0x62e240","size":18},{"addr":"0x62e254","size":20},{"addr":"0x62e268","size":4}]})` | Exact bytes below; all padding remains 0xcc and all pointers/literals/successor bytes remain fixed. |
| PRE-09 | `type_inspect({"database":"DB","queries":[{"name":"TextPad","include_members":true,"max_members":32},{"name":"TextPadEventHandlerFacet","include_members":true,"max_members":32},{"name":"TextRunFormatData","include_members":true,"max_members":32},{"name":"Event","include_members":false,"max_members":0}]})` | First two absent; TextRunFormatData exact 12-byte/four-member layout; Event exists at size 272. |
| PRE-10 | `insn_query({"database":"DB","queries":[{"start":"0x5961d0","end":"0x596204","count":100,"max_scan_insns":100,"include_disasm":true,"include_fn":true},{"start":"0x596210","end":"0x596242","count":100,"max_scan_insns":100,"include_disasm":true,"include_fn":true}]})` | Exactly 18 instruction heads in each raw range, `fn:null`, no truncation, exact disassembly/body shape and final `retn 4`; mismatch stops. |

### Literal existing-function prestates

Every function entry is a one-byte code item except A04's same one-byte whole body; the separate lookup bound is authoritative for the function range. `addr-reg/addr-rpt/fn-reg/fn-rpt=""` is literal, not shorthand.

| ID | Exact item/function/name/declaration prestate | Exact comments, xrefs, and entry bytes |
| --- | --- | --- |
| A01 | entry item [0x595900,0x595901), width 1, code; function [0x595900,0x595ae2), size 0x1e2; name `sub_595900`; type `__int16 *__thiscall(__int16 *this)` | addr-reg/addr-rpt/fn-reg/fn-rpt=""; inbound 0; bytes `55 8b ec 6a ff 68 1e 99` |
| A02 | entry item [0x595af0,0x595af1), width 1, code; function [0x595af0,0x595ba9), size 0xb9; name `sub_595AF0`; type `char __thiscall(int this, _BYTE *)` | four comment channels=""; inbound one data xref 0x62e1f8; bytes `55 8b ec 81 ec 04 08 00` |
| A03 | entry item [0x595bb0,0x595bb1), width 1, code; function [0x595bb0,0x595bcf), size 0x1f; name `sub_595BB0`; type `int __thiscall(int this)` | four comment channels=""; inbound one data xref 0x62e1e0; bytes `56 68 80 00 00 00 8b f1` |
| A04 | item/function [0x595bd0,0x595bd1), width/size 1, code; name `nullsub_60`; type `void()` | four comment channels=""; inbound one data xref 0x62e1e4; byte `c3` |
| A05 | entry item [0x595be0,0x595be1), width 1, code; function [0x595be0,0x595f26), size 0x346; name `sub_595BE0`; type `void __thiscall(_DWORD **this, const wchar_t *nNumberOfBytesToRead)` | four comment channels=""; inbound one code xref 0x595b64 from A02; bytes `55 8b ec 6a ff 68 53 99` |
| A06 | entry item [0x595f30,0x595f31), width 1, code; function [0x595f30,0x596065), size 0x135; name `sub_595F30`; type `void __thiscall(_DWORD **this, DWORD nNumberOfBytesToRead)` | four comment channels=""; inbound 0; bytes `55 8b ec 6a ff 68 76 99` |
| A07 | entry item [0x596070,0x596071), width 1, code; function [0x596070,0x5961c8), size 0x158; name `sub_596070`; type `void __thiscall(_DWORD *this, int)` | four comment channels=""; inbound 0; bytes `55 8b ec 6a ff 68 99 99` |

### Literal raw address-comment prestates and poststates

| ID | Exact physical prestate | Exact address-comment-only poststate and protected readback |
| --- | --- | --- |
| A08 | No function, name, or type at 0x5961d0; regular/repeatable address comments `""`; no function-comment or frame channel. Eighteen code items: [1d0,1d1)/1, [1d1,1d3)/2, [1d3,1d6)/3, [1d6,1dc)/6, [1dc,1de)/2, [1de,1e0)/2, [1e0,1e3)/3, [1e3,1e5)/2, [1e5,1eb)/6, [1eb,1ef)/4, [1ef,1f3)/4, [1f3,1f6)/3, [1f6,1f7)/1, [1f7,1f9)/2, [1f9,1fe)/5, [1fe,200)/2, [200,201)/1, [201,204)/3, all names/types empty. | Set only regular and repeatable address comments at 0x5961d0 to `TextPad retained SetFont: applies TextRunFormatData legacyAssetMode with selection mask 1.` Function/name/type/function-comment/frame remain absent. Preserve all 18 item heads/ranges/kinds/widths and exact bytes `55 8b ec 83 ec 0c 8b 89 fc 01 00 00 6a 00 8b 01 ff 50 10 8b 00 8b 88 0c 01 00 00 66 8b 45 08 66 89 45 f4 8d 45 f4 50 6a 01 e8 f2 9c ff ff 8b e5 5d c2 04 00`; inbound 0; call item 0x5961f9 code xref -> 0x58fef0 and flow -> 0x5961fe; predecessor data [0x5961c8,0x5961d0), width 8, eight 0xcc, inbound 0; successor data [0x596204,0x596210), width 12, twelve 0xcc, inbound 0. Only the two address-comment channels may differ. |
| A09 | No function, name, or type at 0x596210; regular/repeatable address comments `""`; no function-comment or frame channel. Eighteen code items: [210,211)/1, [211,213)/2, [213,216)/3, [216,21c)/6, [21c,21e)/2, [21e,220)/2, [220,223)/3, [223,225)/2, [225,22b)/6, [22b,22e)/3, [22e,231)/3, [231,234)/3, [234,235)/1, [235,237)/2, [237,23c)/5, [23c,23e)/2, [23e,23f)/1, [23f,242)/3, all names/types empty. | Set only regular and repeatable address comments at 0x596210 to `TextPad retained SetColor: applies TextRunFormatData textColor with selection mask 2.` Function/name/type/function-comment/frame remain absent. Preserve all 18 item heads/ranges/kinds/widths and exact bytes `55 8b ec 83 ec 0c 8b 89 fc 01 00 00 6a 00 8b 01 ff 50 10 8b 00 8b 88 0c 01 00 00 8b 45 08 89 45 f8 8d 45 f4 50 6a 02 e8 b4 9c ff ff 8b e5 5d c2 04 00`; inbound 0; call item 0x596237 code xref -> 0x58fef0 and flow -> 0x59623c; predecessor data [0x596204,0x596210), width 12, twelve 0xcc, inbound 0; successor data [0x596242,0x596250), width 14, fourteen 0xcc, inbound 0; Thread entry [0x596250,0x596251), name `sub_596250`, type `_DWORD *__thiscall(_DWORD *ArgList, _DWORD *pExceptionObject)`, bytes `55 8b ec 6a ff 68 0e 9a`, inbound code xrefs 0x41a69b/0x45393b/0x4700dd/0x5281db/0x574812. Only the two address-comment channels may differ. |

Addresses in the raw item lists use the common 0x596000 prefix. PRE-02/PRE-04-PRE-06/PRE-08/PRE-10 jointly seal A08/A09 as raw code without functions; the postread repeats those exact requests after both address-comment actions. No `define_func`, function rename/type/comment, direct `decompile`, or `stack_frame` request may target either raw start. Historical transaction `UID0000OQ-20260822-153330693` temporarily defined both exact bounds, then MID-RAW returned only `__saved_registers@0xc/0x4 _DWORD` and `__return_address@0x10/0x4 _UNKNOWN *` for each, not the promised local/argument rows. The immediate hard stop occurred before rename/type/comment; no save or TX occurred, so the failed in-memory definitions are superseded and receive no applied credit.

### Literal comment-only data prestates and poststates

For every row, current regular/repeatable comments are exactly `""`. The action sets both channels to the exact stated comment. Post-read must reproduce the same item geometry/name/type/bytes/xrefs and only those two comment fields may differ.

| ID | Exact per-entity prestate and protected relationships | Exact required regular and repeatable comment |
| --- | --- | --- |
| D01a | data [0x62e18c,0x62e190), width 4, name/type empty, bytes `b4 15 65 00`; inbound 0, outbound data -> 0x6515b4 | `TextPad complete-object-locator cell; compiler-emitted.` |
| D01b | data [0x62e1ec,0x62e1f0), width 4, name/type empty, bytes `14 16 65 00`; inbound 0, outbound data -> 0x651614 | `TextPad complete-object-locator cell; compiler-emitted.` |
| D01c | data [0x62e21c,0x62e220), width 4, name/type empty, bytes `28 16 65 00`; inbound 0, outbound data -> 0x651628 | `TextPad complete-object-locator cell; compiler-emitted.` |
| D02a | data [0x62e190,0x62e194), width 4, name `??_7TextPad@@6B@`, type empty, bytes `50 c3 48 00`; inbound data 0x595940, outbound data -> 0x48c350 | `TextPad primary vtable; 23 slots.` |
| D02b | data [0x62e1f0,0x62e1f4), width 4, name `??_7TextPad@@6B@_0`, type empty, bytes `7b c2 48 00`; inbound data 0x595946, outbound data -> 0x48c27b | `TextPad secondary event-handler vtable; 11 slots.` |
| D02c | data [0x62e220,0x62e224), width 4, name `??_7TextPad@@6B@_1`, type empty, bytes `86 c2 48 00`; inbound data 0x595950, outbound data -> 0x48c286; protect following data [0x62e224,0x62e228), width 4 | `TextPad tertiary timer vtable; 2 slots.` |
| D03 | data [0x62e1e0,0x62e1e4), width 4, name/type empty, bytes `b0 5b 59 00`; inbound 0, outbound data -> 0x595bb0 | `TextPad primary slot +0x50: DrawBackground.` |
| D04 | data [0x62e1e4,0x62e1e8), width 4, name/type empty, bytes `d0 5b 59 00`; inbound 0, outbound data -> 0x595bd0 | `TextPad primary slot +0x54: DrawBorder.` |
| D05 | data [0x62e1f8,0x62e1fc), width 4, name/type empty, bytes `f0 5a 59 00`; inbound 0, outbound data -> 0x595af0 | `TextPad secondary slot +0x08: HandleKeyOrTextEvent.` |
| D06 | data [0x62e228,0x62e234), width 12, name `aOpen`, type `const wchar_t[]`, bytes `4f 00 70 00 65 00 6e 00 20 00 00 00`; inbound data 0x595c0d, outbound 0 | `TextPad SendText source prefix: L"Open ".` |
| D07 | action head data [0x62e234,0x62e238), width 4, name `aSa_9`, type `const wchar_t[]`; protected tails are data [0x62e238,0x62e23c), width 4, name/type empty, then four one-byte undefined items [0x62e23c,0x62e23d), [0x62e23d,0x62e23e), [0x62e23e,0x62e23f), [0x62e23f,0x62e240), all name/type/comment empty. Full literal bytes `53 00 61 00 76 00 65 00 20 00 00 00`; head inbound data 0x595d35, outbound 0. | `TextPad SendText source prefix: L"Save "; preserve current item tails.` |
| D08 | action head data [0x62e240,0x62e244), width 4, name `aSe_1`, type `const wchar_t[]`; protected tail data [0x62e244,0x62e252), width 14, name `aTfont`, type empty; protected padding data [0x62e252,0x62e254), width 2, name/type empty. Full literal bytes `53 00 65 00 74 00 46 00 6f 00 6e 00 74 00 20 00 00 00`; head inbound data 0x595e79, outbound 0. | `TextPad SendText source prefix: L"SetFont "; preserve current item tails.` |
| D09 | action head data [0x62e254,0x62e258), width 4, name `aSe_2`, type `const wchar_t[]`; protected tail data [0x62e258,0x62e268), width 16, name `aTcolor`, type empty. Full literal bytes `53 00 65 00 74 00 43 00 6f 00 6c 00 6f 00 72 00 20 00 00 00`; head inbound data 0x595ec5, outbound 0. Protect successor data [0x62e268,0x62e26c), width 4, name/type/comments empty, bytes `3c 16 65 00`, inbound 0. | `TextPad SendText source prefix: L"SetColor "; preserve current item tails.` |

### Literal existing-function frame baseline and permitted set_type deltas

| ID | Exact PRE-07 ordered public stack_frame rows | Only permitted set_type row delta; every other row is protected |
| --- | --- | --- |
| A01 | `textWidthScale@0x0/0x4 float; var_38@0x14/0x4 DialogPane *; Block@0x18/0x4 void *; var_30@0x1c/0x10 struct RectBounds; bounds@0x2c/0x10 struct RectBounds; var_10@0x3c/0x4 _DWORD; var_C@0x40/0x4 _DWORD; var_4@0x48/0x4 _DWORD; __saved_registers@0x4c/0x4 _DWORD; __return_address@0x50/0x4 _UNKNOWN *; arg_4@0x58/0x4 _DWORD` | TYPE-PRE renders `DialogPane *this` and DialogPane return; `set_type` changes both to `TextPad *`. ECX is not a public frame row, so no frame-row delta is permitted; `arg_4` and every local/metadata row remain byte-for-byte identical. |
| A02 | `nNumberOfBytesToRead@0x8/0x800 wchar_t[1024]; var_4@0x808/0x4 _DWORD; __saved_registers@0x80c/0x4 _DWORD; __return_address@0x810/0x4 _UNKNOWN *; event@0x814/0x4 Event *` | TYPE-PRE already renders `bool` return and `Event *event`; only receiver `int this` changes to `TextPadEventHandlerFacet *this`. The public event row is already exact, so no public frame-row delta is permitted; all five rows remain exact. |
| A03 | `__return_address@0x4/0x4 _UNKNOWN *` | TYPE-PRE already renders `void` and changes only receiver `GrafPort *this` -> `TextPad *this`; no argument/local/saved-register row exists or may appear. Return row stays exact. |
| A04 | `__return_address@0x0/0x4 _UNKNOWN *` | Declaration changes `void()` -> thiscall with register receiver; no public argument/local/saved-register row may appear. Return row stays exact. |
| A05 | `var_50@0x10/0x4 _BYTE[4]; var_4C@0x14/0x4 _DWORD; var_44@0x1c/0x14 TextEditScrap; var_30@0x30/0x4 char[4]; ArgList@0x34/0x2 char[2]; NumberOfBytesRead@0x38/0x4 DWORD; end@0x3c/0x4 __int16[2]; var_20@0x40/0x4 LPCVOID; var_1C@0x44/0x4 MemoryMan *; lpBuffer@0x48/0x4 LPCVOID; Buffer@0x4c/0x4 _DWORD; NumberOfBytesWritten@0x50/0x4 DWORD; var_C@0x54/0x4 _DWORD; var_4@0x5c/0x4 _DWORD; __saved_registers@0x60/0x4 _DWORD; __return_address@0x64/0x4 _UNKNOWN *; nNumberOfBytesToRead@0x68/0x4 DWORD; arg_4@0x6c/0x4 _DWORD` | TYPE-PRE renders the physical 0x68 scalar as `unsigned int nNumberOfBytesToRead`; only that row may change to `commandLine/const wchar_t *`. Offset and one 4-byte ABI slot remain; `arg_4` and all 16 non-delta rows remain exact. |
| A06 | `var_28@0x10/0x14 TextEditScrap; NumberOfBytesRead@0x24/0x4 DWORD; var_10@0x28/0x4 MemoryMan *; var_C@0x2c/0x4 _DWORD; var_4@0x34/0x4 _DWORD; __saved_registers@0x38/0x4 _DWORD; __return_address@0x3c/0x4 _UNKNOWN *; nNumberOfBytesToRead@0x40/0x4 DWORD; arg_4@0x44/0x4 _DWORD` | Only row 0x40 may change from `nNumberOfBytesToRead/DWORD` to `path/const wchar_t *`; offset/slot remain. `arg_4` and all seven non-delta rows remain exact. |
| A07 | `var_40@0x10/0x14 TextEditScrap; nNumberOfBytesToWrite@0x24/0x4 DWORD; start@0x28/0x4 __int16[2]; end@0x2c/0x4 __int16[2]; var_20@0x30/0x4 LPCVOID; lpBuffer@0x34/0x4 LPCVOID; var_18@0x38/0x4 DWORD; NumberOfBytesWritten@0x3c/0x4 DWORD; Buffer@0x43/0x1 _BYTE; var_C@0x44/0x4 _DWORD; var_4@0x4c/0x4 _DWORD; __saved_registers@0x50/0x4 _DWORD; __return_address@0x54/0x4 _UNKNOWN *; arg_0@0x58/0x4 _DWORD; arg_4@0x5c/0x4 _DWORD` | TYPE-PRE first-line auto-name `a2` denotes the same physical argument whose public frame row remains `arg_0@0x58/_DWORD`; only that row may change to `path/const wchar_t *`. Offset/slot remain; `arg_4` and all 13 non-delta rows remain exact. |

The supervisor runs each A01-A07 direct `decompile` request below twice in the same isolated `DB`: `TYPE-PRE-Axx` immediately after A00 plus pure rename readback and immediately before `set_type`, then `TYPE-POST-Axx` immediately after `set_type` and before any comment action. Each response must return the exact requested `addr`, no `error`, non-null `code`, and the exact first line stated below. A00 declares only two incomplete target types and pure rename changes only symbols; neither action sets a function signature. Hex-Rays therefore recomputes the TYPE-PRE presentation from unchanged stored tinfo plus propagated body/callee/frame evidence, yielding existing DialogPane/Event/GrafPort types, inferred bool/void/scalar types, and auto-name `a2`. The complete TYPE-PRE response, including its exact first line and body, is the transaction-local pseudocode baseline; a mismatch is substantive drift, not formatting. TYPE-POST must show only the stated prototype/type propagation while preserving complete-body control flow, constants, callee targets, side effects, and `refs`; unrelated pseudocode drift stops. A canonical-session response cannot satisfy either side of a pair. A08/A09 are excluded: they remain raw code and receive no direct decompile request.

| ID | Exact direct request for both transaction-local reads | Required TYPE-PRE -> TYPE-POST prototype/decompilation change |
| --- | --- | --- |
| A01 | `decompile({"database":"DB","addr":"0x595900","include_addresses":false})` | TYPE-PRE first line exactly `DialogPane *__thiscall TextPad__Constructor(DialogPane *this)`; TYPE-POST exactly `TextPad *__thiscall TextPad__Constructor(TextPad *this)`. Only return/receiver DialogPane-to-TextPad propagation may change; the complete constructor body and A01 frame protections remain exact. |
| A02 | `decompile({"database":"DB","addr":"0x595af0","include_addresses":false})` | TYPE-PRE first line exactly `bool __thiscall TextPad__HandleKeyOrTextEvent(int this, Event *event)`; TYPE-POST exactly `bool __thiscall TextPad__HandleKeyOrTextEvent(TextPadEventHandlerFacet *this, Event *event)`. Only receiver propagation may change; bool/Event are already exact and the complete handler body/public frame rows remain exact. |
| A03 | `decompile({"database":"DB","addr":"0x595bb0","include_addresses":false})` | TYPE-PRE first line exactly `void __thiscall TextPad__DrawBackground(GrafPort *this)`; TYPE-POST exactly `void __thiscall TextPad__DrawBackground(TextPad *this)`. Only receiver GrafPort-to-TextPad propagation may change; the complete fill body and return-only frame remain exact. |
| A04 | `decompile({"database":"DB","addr":"0x595bd0","include_addresses":false})` | TYPE-PRE first line exactly `void TextPad__DrawBorder()`; TYPE-POST exactly `void __thiscall TextPad__DrawBorder(TextPad *this)`. Only the register receiver is introduced; the complete empty body and sole return-address frame row remain exact. |
| A05 | `decompile({"database":"DB","addr":"0x595be0","include_addresses":false})` | TYPE-PRE first line exactly `void __thiscall TextPad__SendText(_DWORD **this, unsigned int nNumberOfBytesToRead)`; TYPE-POST exactly `void __thiscall TextPad__SendText(TextPad *this, const wchar_t *commandLine)`. Receiver and scalar-to-path argument propagation plus the permitted row-0x68 delta are the only changes; the complete dispatcher body remains exact. |
| A06 | `decompile({"database":"DB","addr":"0x595f30","include_addresses":false})` | TYPE-PRE first line exactly `void __thiscall TextPad__Open(_DWORD **this, DWORD nNumberOfBytesToRead)`; TYPE-POST exactly `void __thiscall TextPad__Open(TextPad *this, const wchar_t *path)`. Receiver/path propagation and the permitted row-0x40 delta are the only changes; the complete Open body remains exact. |
| A07 | `decompile({"database":"DB","addr":"0x596070","include_addresses":false})` | TYPE-PRE first line exactly `void __thiscall TextPad__Save(_DWORD *this, int a2)`; TYPE-POST exactly `void __thiscall TextPad__Save(TextPad *this, const wchar_t *path)`. Receiver/path propagation and the permitted physical row-0x58 delta are the only changes; `a2` is the TYPE-PRE decompiler auto-name while public frame row `arg_0` remains the pre-type stack name, and the complete Save body remains exact. |

### Entity actions and deterministic readbacks

| ID | Exact old -> new action | Exact required postread/protection |
| --- | --- | --- |
| A00 | Types `TextPad` and `TextPadEventHandlerFacet` absent -> declare exactly `struct TextPad;` and `struct TextPadEventHandlerFacet;` | Both exist only as incomplete/opaque declarations with no size/members; TextRunFormatData and Event remain exact. |
| A01 | `sub_595900` -> `TextPad__Constructor`; set `TextPad *__thiscall TextPad__Constructor(TextPad *this)`; set both function comment channels to `TextPad constructor: builds main editor and command input, then creates and shows the full-screen dialog.` | Exact new name/declaration/comments at 0x595900; TYPE-PRE/TYPE-POST-A01 must show exact `DialogPane *` -> `TextPad *` return/receiver propagation with the complete body unchanged; function/item bounds, inbound 0, bytes, and A01 frame protection remain exact. |
| A02 | `sub_595AF0` -> `TextPad__HandleKeyOrTextEvent`; set `bool __thiscall TextPad__HandleKeyOrTextEvent(TextPadEventHandlerFacet *this, Event *event)`; both function comments `TextPad secondary facet at primary +0xa0: handles Enter command submission or delegates to DialogPane.` | Exact address readback; TYPE-PRE/TYPE-POST-A02 changes only `int this` to `TextPadEventHandlerFacet *this` because bool/Event are already present, with complete body unchanged; one inbound xref 0x62e1f8, bytes/bounds, and A02 zero-delta frame remain exact. |
| A03 | `sub_595BB0` -> `TextPad__DrawBackground`; set `void __thiscall TextPad__DrawBackground(TextPad *this)`; both comments `TextPad DrawBackground: color 0x80, draw mode 0, fill inherited visible bounds.` | Exact address readback; TYPE-PRE/TYPE-POST-A03 changes only `GrafPort *this` to `TextPad *this`, with complete fill body unchanged; one inbound xref 0x62e1e0, bytes/bounds, and frame remain exact. |
| A04 | `nullsub_60` -> `TextPad__DrawBorder`; set `void __thiscall TextPad__DrawBorder(TextPad *this)`; both comments `TextPad DrawBorder: intentional empty border override.` | Exact address readback; TYPE-PRE/TYPE-POST-A04 direct decompiles show the new register receiver with unchanged empty body; one inbound xref 0x62e1e4, sole byte c3, and return-only frame remain exact. |
| A05 | `sub_595BE0` -> `TextPad__SendText`; set `void __thiscall TextPad__SendText(TextPad *this, const wchar_t *commandLine)`; both comments `TextPad SendText: four-prefix dispatcher with compiler-inlined Open, Save, SetFont, and SetColor behavior.` | Exact address readback; TYPE-PRE/TYPE-POST-A05 shows `_DWORD **`/`unsigned int nNumberOfBytesToRead` -> `TextPad *`/`const wchar_t *commandLine`, with complete dispatcher body unchanged; sole caller 0x595b64, bytes/bounds, and only A05 row-0x68 delta remain allowed. |
| A06 | `sub_595F30` -> `TextPad__Open`; set `void __thiscall TextPad__Open(TextPad *this, const wchar_t *path)`; both comments `TextPad retained Open: loads UTF-16 text and optional TextEditScrap payload with shipped pointer arithmetic.` | Exact address readback; TYPE-PRE/TYPE-POST-A06 direct decompiles show only the specified type propagation; inbound 0, bytes/bounds, and only A06 row-0x40 delta remain allowed. |
| A07 | `sub_596070` -> `TextPad__Save`; set `void __thiscall TextPad__Save(TextPad *this, const wchar_t *path)`; both comments `TextPad retained Save: writes text, one zero separator byte, optional payload size, and payload.` | Exact address readback; TYPE-PRE/TYPE-POST-A07 shows `_DWORD *this, int a2` -> `TextPad *this, const wchar_t *path`, with complete Save body unchanged; `a2` remains distinct from pre-type public frame row name `arg_0`, inbound 0/bytes/bounds remain exact, and only A07 row-0x58 delta is allowed. |
| A08 | At raw start 0x5961d0, set regular and repeatable address comments exactly to `TextPad retained SetFont: applies TextRunFormatData legacyAssetMode with selection mask 1.` | Only those two address-comment channels change. Function/name/type/function-comment/frame remain absent; all 18 instruction items, exact 0x34 bytes, call/fallthrough, inbound 0, and both exact padding neighbors remain unchanged. |
| A09 | At raw start 0x596210, set regular and repeatable address comments exactly to `TextPad retained SetColor: applies TextRunFormatData textColor with selection mask 2.` | Only those two address-comment channels change. Function/name/type/function-comment/frame remain absent; all 18 instruction items, exact 0x32 bytes, call/fallthrough, inbound 0, both exact padding neighbors, and Thread successor remain unchanged. |
| P01 | No mutation to any Section 14 padding, raw instruction item, string tail, vtable/COL/slot name/type, 0x62e268 successor, or Thread function at 0x596250. | Every listed physical item/name/type/byte/xref/comment not explicitly changed remains exact. |
| P02 | No declare_stack, delete_stack, stack/local rename, or stack/local type action; no frame operation targets A08/A09. | A01-A07 frames obey the literal delta table; each TYPE-PRE first line is exact and distinct from stored-item declarations where observed; every pair preserves complete-body control flow, constants, callees, side effects, refs, and unaffected frame rows. A08/A09 remain outside functions with no frame channel. |

Use only public `declare_type`, `rename`, `set_type`, `set_function_comments`, `set_repeatable_comments`, `set_address_comments`, and `set_address_repeatable_comments` for mutation, and public `decompile` for the seven mandatory A01-A07 direct transaction-local type readbacks. `define_func`, `make_data`, `undefine`, `patch`, stack mutation, vtable/data/raw rename/type, string resizing, and every unlisted mutation are forbidden. A08/A09 may appear only in the two address-comment mutation requests and physical readbacks specified here.

Affected-claim mapping is exact: A00 protects C004/C060; A01 covers C006-C012; A02 covers C013-C015; A03 covers C016/C018; A04 covers C017/C018; A05 covers C019-C022; A06 covers C023-C027; A07 covers C028-C031; address-comment-only A08 covers C032/C034/C060/C061; address-comment-only A09 covers C033/C034/C060/C061; D01a-D05 cover C037-C039/C061; D06-D09 cover C040-C042/C061; P01/P02 protect C034/C041/C042/C060-C062. PRE-00-PRE-10, TYPE-PRE/TYPE-POST-A01-A07, and POST-01-POST-08 are mandatory isolated-session protections for every mapped action; no canonical-session read can substitute for them. The historical MID-RAW failure is evidence for excluding A08/A09 function/frame operations, not a current action or readback step.

### Literal public mutation requests

After every preflight row passes in the bound isolated `DB`/`ISOLATED_PATH`, the supervisor uses these public requests in order against that same immutable `DB`. Every returned item must succeed; partial success, an unexpected result field, a session/path change, a canonical-session response, or any intervening drift is a hard stop.

1. `declare_type({"database":"DB","decls":["struct TextPad;","struct TextPadEventHandlerFacet;"]})`
2. `rename({"database":"DB","batch":{"func":[{"addr":"0x595900","name":"TextPad__Constructor"},{"addr":"0x595af0","name":"TextPad__HandleKeyOrTextEvent"},{"addr":"0x595bb0","name":"TextPad__DrawBackground"},{"addr":"0x595bd0","name":"TextPad__DrawBorder"},{"addr":"0x595be0","name":"TextPad__SendText"},{"addr":"0x595f30","name":"TextPad__Open"},{"addr":"0x596070","name":"TextPad__Save"}],"allow_overwrite":false,"stop_on_error":true,"pure":true}})`; the exact old/new mapping is A01-A07, and PRE-02/PRE-03 must still be the immediately preceding collision/name seal.
3. Immediate rename/raw-absence readback: `lookup_funcs({"database":"DB","queries":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070","0x5961d0","0x596210","TextPad__Constructor","TextPad__HandleKeyOrTextEvent","TextPad__DrawBackground","TextPad__DrawBorder","TextPad__SendText","TextPad__Open","TextPad__Save"]})`; all seven addresses/names resolve bijectively to exact bounds, while A08/A09 still return `fn:null,error:"Not a function"`.
4. TYPE-PRE-A01-A07: run the seven exact direct `decompile` requests in the pair table, retain each complete isolated response, and require its exact first line plus complete pre-type body/frame contract before `set_type`; any difference from any of the seven stated first lines stops.
5. `set_type({"database":"DB","edits":[{"addr":"0x595900","kind":"function","signature":"TextPad *__thiscall TextPad__Constructor(TextPad *this)"},{"addr":"0x595af0","kind":"function","signature":"bool __thiscall TextPad__HandleKeyOrTextEvent(TextPadEventHandlerFacet *this, Event *event)"},{"addr":"0x595bb0","kind":"function","signature":"void __thiscall TextPad__DrawBackground(TextPad *this)"},{"addr":"0x595bd0","kind":"function","signature":"void __thiscall TextPad__DrawBorder(TextPad *this)"},{"addr":"0x595be0","kind":"function","signature":"void __thiscall TextPad__SendText(TextPad *this, const wchar_t *commandLine)"},{"addr":"0x595f30","kind":"function","signature":"void __thiscall TextPad__Open(TextPad *this, const wchar_t *path)"},{"addr":"0x596070","kind":"function","signature":"void __thiscall TextPad__Save(TextPad *this, const wchar_t *path)"}]})`
6. TYPE-POST-A01-A07: immediately run the same seven exact direct `decompile` requests, compare each response with its retained TYPE-PRE partner, and require every stated post-type prototype/type-propagation and protected-body contract before any comment action.
7. Immediate seven-function type/frame readback: `inspect_items({"database":"DB","addrs":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070"]})`; then `stack_frame({"database":"DB","addrs":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070"]})`. All seven declarations and frames must satisfy the literal delta table.
8. Immediate raw-absence readback: `inspect_items({"database":"DB","addrs":["0x5961d0","0x596210"]})`; then `lookup_funcs({"database":"DB","queries":["0x5961d0","0x596210"]})`. Both raw items remain name/type empty and both lookups remain `fn:null,error:"Not a function"`; no frame request is made.
9. `set_function_comments({"database":"DB","items":[{"addr":"0x595900","comment":"TextPad constructor: builds main editor and command input, then creates and shows the full-screen dialog."},{"addr":"0x595af0","comment":"TextPad secondary facet at primary +0xa0: handles Enter command submission or delegates to DialogPane."},{"addr":"0x595bb0","comment":"TextPad DrawBackground: color 0x80, draw mode 0, fill inherited visible bounds."},{"addr":"0x595bd0","comment":"TextPad DrawBorder: intentional empty border override."},{"addr":"0x595be0","comment":"TextPad SendText: four-prefix dispatcher with compiler-inlined Open, Save, SetFont, and SetColor behavior."},{"addr":"0x595f30","comment":"TextPad retained Open: loads UTF-16 text and optional TextEditScrap payload with shipped pointer arithmetic."},{"addr":"0x596070","comment":"TextPad retained Save: writes text, one zero separator byte, optional payload size, and payload."}]})`
10. `set_repeatable_comments({"database":"DB","items":[{"addr":"0x595900","comment":"TextPad constructor: builds main editor and command input, then creates and shows the full-screen dialog."},{"addr":"0x595af0","comment":"TextPad secondary facet at primary +0xa0: handles Enter command submission or delegates to DialogPane."},{"addr":"0x595bb0","comment":"TextPad DrawBackground: color 0x80, draw mode 0, fill inherited visible bounds."},{"addr":"0x595bd0","comment":"TextPad DrawBorder: intentional empty border override."},{"addr":"0x595be0","comment":"TextPad SendText: four-prefix dispatcher with compiler-inlined Open, Save, SetFont, and SetColor behavior."},{"addr":"0x595f30","comment":"TextPad retained Open: loads UTF-16 text and optional TextEditScrap payload with shipped pointer arithmetic."},{"addr":"0x596070","comment":"TextPad retained Save: writes text, one zero separator byte, optional payload size, and payload."}]})`
11. `set_address_comments({"database":"DB","items":[{"addr":"0x5961d0","comment":"TextPad retained SetFont: applies TextRunFormatData legacyAssetMode with selection mask 1."},{"addr":"0x596210","comment":"TextPad retained SetColor: applies TextRunFormatData textColor with selection mask 2."},{"addr":"0x62e18c","comment":"TextPad complete-object-locator cell; compiler-emitted."},{"addr":"0x62e1ec","comment":"TextPad complete-object-locator cell; compiler-emitted."},{"addr":"0x62e21c","comment":"TextPad complete-object-locator cell; compiler-emitted."},{"addr":"0x62e190","comment":"TextPad primary vtable; 23 slots."},{"addr":"0x62e1f0","comment":"TextPad secondary event-handler vtable; 11 slots."},{"addr":"0x62e220","comment":"TextPad tertiary timer vtable; 2 slots."},{"addr":"0x62e1e0","comment":"TextPad primary slot +0x50: DrawBackground."},{"addr":"0x62e1e4","comment":"TextPad primary slot +0x54: DrawBorder."},{"addr":"0x62e1f8","comment":"TextPad secondary slot +0x08: HandleKeyOrTextEvent."},{"addr":"0x62e228","comment":"TextPad SendText source prefix: L\"Open \"."},{"addr":"0x62e234","comment":"TextPad SendText source prefix: L\"Save \"; preserve current item tails."},{"addr":"0x62e240","comment":"TextPad SendText source prefix: L\"SetFont \"; preserve current item tails."},{"addr":"0x62e254","comment":"TextPad SendText source prefix: L\"SetColor \"; preserve current item tails."}]})`
12. `set_address_repeatable_comments({"database":"DB","items":[{"addr":"0x5961d0","comment":"TextPad retained SetFont: applies TextRunFormatData legacyAssetMode with selection mask 1."},{"addr":"0x596210","comment":"TextPad retained SetColor: applies TextRunFormatData textColor with selection mask 2."},{"addr":"0x62e18c","comment":"TextPad complete-object-locator cell; compiler-emitted."},{"addr":"0x62e1ec","comment":"TextPad complete-object-locator cell; compiler-emitted."},{"addr":"0x62e21c","comment":"TextPad complete-object-locator cell; compiler-emitted."},{"addr":"0x62e190","comment":"TextPad primary vtable; 23 slots."},{"addr":"0x62e1f0","comment":"TextPad secondary event-handler vtable; 11 slots."},{"addr":"0x62e220","comment":"TextPad tertiary timer vtable; 2 slots."},{"addr":"0x62e1e0","comment":"TextPad primary slot +0x50: DrawBackground."},{"addr":"0x62e1e4","comment":"TextPad primary slot +0x54: DrawBorder."},{"addr":"0x62e1f8","comment":"TextPad secondary slot +0x08: HandleKeyOrTextEvent."},{"addr":"0x62e228","comment":"TextPad SendText source prefix: L\"Open \"."},{"addr":"0x62e234","comment":"TextPad SendText source prefix: L\"Save \"; preserve current item tails."},{"addr":"0x62e240","comment":"TextPad SendText source prefix: L\"SetFont \"; preserve current item tails."},{"addr":"0x62e254","comment":"TextPad SendText source prefix: L\"SetColor \"; preserve current item tails."}]})`

### Mandatory post-read

| Step | Exact literal readback | Acceptance or stop |
| --- | --- | --- |
| POST-01 | Repeat PRE-02 and the immediate rename/raw-absence query from request 3. | Seven exact new function names resolve bijectively by address/name with bounds [595900,595ae2), [595af0,595ba9), [595bb0,595bcf), [595bd0,595bd1), [595be0,595f26), [595f30,596065), and [596070,5961c8). A08/A09 still return `fn:null,error:"Not a function"` with no name/type; successor remains sub_596250 [596250,5963f2). |
| POST-02 | Repeat PRE-04 `inspect_items`. | Seven original entry items unchanged; both raw ranges remain outside functions as the exact 18+18 instruction items with every raw item name/type empty; every D item/tail/padding/successor geometry/name/type is identical; only seven function names/types and authorized comment channels differ. |
| POST-03 | Repeat PRE-05 `get_comments` on all action/protected heads. | A01-A07 function regular/repeatable comments exactly equal their action strings. A08/A09 regular/repeatable address comments equal their exact A08/A09 strings while function-comment channels remain absent. D01a-D09 regular/repeatable address comments equal their table strings; every protected neighbor comment remains `""`; no extra channel changes. |
| POST-04 | Repeat PRE-06a/PRE-06b `xref_query`. | Exact function/raw/data/padding/successor xrefs remain unchanged, including A05 caller, three vtable cells, three constructor vptr stores, four string refs, two raw calls plus fallthroughs, and the five protected Thread inbound xrefs. |
| POST-05 | `stack_frame({"database":"DB","addrs":["0x595900","0x595af0","0x595bb0","0x595bd0","0x595be0","0x595f30","0x596070"]})` | A01-A07 equal PRE-07 except the three explicitly permitted argument rows. Every unaffected argument/local/saved-register/return row and every required absence is exact. A08/A09 are deliberately absent from this request because POST-01 requires no functions and therefore no frame channels at those starts. |
| POST-05D | Run `decompile({"database":"DB","addr":"0x595900","include_addresses":false})`, `decompile({"database":"DB","addr":"0x595af0","include_addresses":false})`, `decompile({"database":"DB","addr":"0x595bb0","include_addresses":false})`, `decompile({"database":"DB","addr":"0x595bd0","include_addresses":false})`, `decompile({"database":"DB","addr":"0x595be0","include_addresses":false})`, `decompile({"database":"DB","addr":"0x595f30","include_addresses":false})`, and `decompile({"database":"DB","addr":"0x596070","include_addresses":false})` in that order. | Every final isolated response has its exact TYPE-POST first line and equals its corresponding partner in complete-body semantics, constants, callee targets, side effects, and refs; each remains paired with its retained exact-first-line TYPE-PRE response and satisfies its entity frame protection. No direct decompile may target A08/A09. Any canonical-session response, missing A01-A07 pair, null code, first-line mismatch, or unrelated decompilation drift stops. |
| POST-06 | Repeat PRE-08 `get_bytes`. | Every byte is identical; raw bounds stop before exact 0xcc padding; Thread/data successor bytes and all vtable/string bytes are unchanged. |
| POST-07 | Repeat PRE-09 `type_inspect`. | TextPad and TextPadEventHandlerFacet are incomplete/opaque only; TextRunFormatData remains exact 12-byte/four-member UDT; Event remains size 272. |
| POST-08 | Repeat PRE-10 `insn_query`. | Both raw code ranges still have `fn:null`, the exact 18+18 instruction heads/disassembly, and final retn 4 inside the exact ranges; no function creation or instruction/padding reclassification occurred. |

Any failed/partial request, isolated session/path mismatch, canonical-session response, prestate mismatch, missing A01-A07 direct decompile pair, any exact TYPE-PRE/TYPE-POST first-line mismatch, unrelated complete-body decompilation drift, name collision, non-pure rename effect, A08/A09 function/name/type/function-comment/frame appearance, extra/missing xref, byte drift, unlisted A01-A07 frame-row delta, sized-UDT creation, item-boundary change, or unauthorized/protected comment change is a hard stop. Supervisor owns rollback/restoration/persistence outside this report; no operational package is embedded.

## First-Draft C++ Recommendation

All C++ is formal channel content and C++03-compatible.

### UID0000EU RECONSTRUCTION_CPP CODE

~~~cpp
#include "TextPad.h"

#include <wchar.h>
#include <windows.h>

#include "../../app/Application.h"
#include "../../platform/PlatformApi.h"
#include "../../render/Surface.h"
#include "../../util/MemoryMan.h"
#include "../MainUiGraph.h"
#include "../controls/TextEditControlPane.h"
#include "../controls/TextEditPane.h"
#include "../core/Event.h"
#include "../core/ScreenPane.h"

[[CHILDREN]]
~~~

### UID0000EU RECONSTRUCTION_H CODE

~~~cpp
#pragma once

#include "../core/DialogPane.h"

class Event;

class TextPad : public DialogPane
{
public:
    TextPad();
    virtual bool HandleKeyOrTextEvent(Event *event);

protected:
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    void SendText(const wchar_t *commandLine);
    void Open(const wchar_t *path);
    void Save(const wchar_t *path);
    void SetFont(unsigned short fontId);
    void SetColor(unsigned int color);
};
~~~

### UID0001JV RECONSTRUCTION_CPP CODE

~~~cpp
TextPad::TextPad()
    : DialogPane(L"", 0xffff, 0)
{
    RectBounds mainBounds = { 0, 0, g_screenWidth, g_screenHeight - 32 };
    TextEditControlPane *mainEdit = new TextEditControlPane(
        L"", false, 0x80, 0x8f, &mainBounds,
        false, true, true, false, 1.0f, false);
    AddControl(mainEdit);
    mainEdit->SetMaxLines(2000);
    mainEdit->SetMaxLength(30000);
    mainEdit->SetHandlesEnterKey(true);

    RectBounds commandBounds = {
        0, g_screenHeight - 32, g_screenWidth, g_screenHeight
    };
    TextEditControlPane *commandEdit = new TextEditControlPane(
        L"", false, 0x80, 0x8f, &commandBounds,
        false, false, true, false, 1.0f, false);
    AddControl(commandEdit);

    RectBounds frameBounds = { 0, 0, g_screenWidth, g_screenHeight };
    SetHoverControl(0);
    StoreClampRect(&frameBounds);
    OnCreate(&frameBounds, 0, 0, g_mainUiLayerSlots.rootPaneLayerContext);
    OnShow(0, g_pScreenPane);
}

bool TextPad::HandleKeyOrTextEvent(Event *event)
{
    if (g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers) == 13 &&
        m_activeControlId == 1 &&
        event->m_type == kEventKeyDown) {
        TextEditControlPane *commandEdit = GetChild<TextEditControlPane>(1);
        wchar_t commandLine[1024];
        commandEdit->ReadText(commandLine, 1023);
        SendText(commandLine);
        commandEdit->GetTextEditPane()->SetSelectionRange(0, 0x7fff);
        return true;
    }
    return DialogPane::HandleKeyOrTextEvent(event);
}

void TextPad::DrawBackground()
{
    SetDrawColor(0x80);
    SetDrawMode(0);
    g_pfnFillRect(this, &m_visibleBounds);
}

void TextPad::DrawBorder()
{
}
~~~

### UID0001JW RECONSTRUCTION_CPP CODE

~~~cpp
void TextPad::SendText(const wchar_t *commandLine)
{
    if (wcsstr(commandLine, L"Open ") == commandLine) {
        Open(commandLine + 5);
    } else if (wcsstr(commandLine, L"Save ") == commandLine) {
        Save(commandLine + 5);
    } else if (wcsstr(commandLine, L"SetFont ") == commandLine) {
        int fontId;
        swscanf(commandLine + 8, L"%d", &fontId);
        SetFont(static_cast<unsigned short>(fontId));
    } else if (wcsstr(commandLine, L"SetColor ") == commandLine) {
        int color;
        swscanf(commandLine + 9, L"%d", &color);
        SetColor(static_cast<unsigned int>(color));
    }
}
~~~

### UID000248 RECONSTRUCTION_CPP CODE

~~~cpp
void TextPad::Open(const wchar_t *path)
{
    MemoryMan *memoryMan = GetMemoryMan();
    TextEditScrap scrap;
    HANDLE file = g_pfnCreateFileW(path, GENERIC_READ, 0, 0,
        OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0);
    DWORD fileSize = GetFileSize(file, 0);
    char *fileBytes = static_cast<char *>(
        memoryMan->AllocateBufferMemory(fileSize + 1));
    DWORD bytesRead;
    ReadFile(file, fileBytes, fileSize, &bytesRead, 0);
    *reinterpret_cast<wchar_t *>(
        fileBytes + fileSize * sizeof(wchar_t)) = L'\0';
    CloseHandle(file);

    const wchar_t *text = reinterpret_cast<const wchar_t *>(fileBytes);
    unsigned int textChars = static_cast<unsigned int>(wcslen(text));
    scrap.SetText(text, static_cast<int>(textChars));
    if (textChars < fileSize) {
        int payloadSize = *reinterpret_cast<const int *>(
            fileBytes + textChars * sizeof(wchar_t) + sizeof(wchar_t));
        const void *payload = fileBytes + textChars + 5;
        scrap.SetPayload(payload, payloadSize);
    }

    TextEditPane *editor =
        GetChild<TextEditControlPane>(0)->GetTextEditPane();
    editor->SetSelectionRange(0, 0x7fff);
    editor->PasteFromClipboard(&scrap);
    editor->SetSelectionRange(0, 0);
    memoryMan->FreeBufferMemory(fileBytes);
}

void TextPad::Save(const wchar_t *path)
{
    MemoryMan *memoryMan = GetMemoryMan();
    TextEditScrap scrap;
    TextEditPane *editor =
        GetChild<TextEditControlPane>(0)->GetTextEditPane();

    short selectionStart;
    short selectionEnd;
    editor->GetCaretRange(&selectionStart, &selectionEnd);
    editor->SetSelectionRange(0, 0x7fff);
    editor->CopySelectionToScrap(&scrap);
    editor->SetSelectionRange(selectionStart, selectionEnd);

    wchar_t *textBuffer = 0;
    int textBytes = scrap.DuplicateText(&textBuffer);
    void *payloadBuffer = 0;
    int payloadBytes = scrap.DuplicatePayload(&payloadBuffer);
    HANDLE file = g_pfnCreateFileW(path, GENERIC_WRITE, 0, 0,
        CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, 0);

    DWORD bytesWritten;
    if (textBytes > 0)
        WriteFile(file, textBuffer, textBytes, &bytesWritten, 0);
    unsigned char separator = 0;
    WriteFile(file, &separator, 1, &bytesWritten, 0);
    if (payloadBytes > 0) {
        WriteFile(file, &payloadBytes, 4, &bytesWritten, 0);
        WriteFile(file, payloadBuffer, payloadBytes, &bytesWritten, 0);
    }
    CloseHandle(file);

    if (textBuffer != 0)
        memoryMan->FreeBufferMemory(textBuffer);
    if (payloadBuffer != 0)
        memoryMan->FreeBufferMemory(payloadBuffer);
}

void TextPad::SetFont(unsigned short fontId)
{
    TextRunFormatData format;
    format.legacyAssetMode = fontId;
    GetChild<TextEditControlPane>(0)->GetTextEditPane()
        ->ApplySelectionFormat(1, &format);
}

void TextPad::SetColor(unsigned int color)
{
    TextRunFormatData format;
    format.textColor = color;
    GetChild<TextEditControlPane>(0)->GetTextEditPane()
        ->ApplySelectionFormat(2, &format);
}
~~~

### UID0003DY RECONSTRUCTION_CPP CODE

~~~cpp
// TextPad RTTI and vtables are compiler-emitted from UID0000EU's class
// declaration and UID0001JV's virtual method definitions.
~~~

### UID0003DZ RECONSTRUCTION_CPP CODE

~~~cpp
// TextPad command literals are emitted by UID0001JW's SendText definition.
~~~

### UID0002AS RECONSTRUCTION_H CODE

~~~cpp
#pragma once

#include <stdio.h>
#include <sys/stat.h>
#include <windows.h>

extern FILE *(__cdecl *g_pfnWideOpenFile)(const wchar_t *path,
                                          const wchar_t *mode);
extern int (__cdecl *g_pfnWideStat)(const wchar_t *path,
                                   struct _stat64i32 *buffer);
extern HANDLE (WINAPI *g_pfnCreateFileW)(
    LPCWSTR fileName,
    DWORD desiredAccess,
    DWORD shareMode,
    LPSECURITY_ATTRIBUTES securityAttributes,
    DWORD creationDisposition,
    DWORD flagsAndAttributes,
    HANDLE templateFile);
extern DWORD (WINAPI *g_pfnGetCurrentDirectoryW)(DWORD bufferLength,
                                                 LPWSTR buffer);
extern DWORD (WINAPI *g_pfnCharUpperBuffW)(LPWSTR text, DWORD length);
~~~

All other child H channels remain blank because UID0000EU owns the complete declaration. UID0003DY/UID0003DZ comments are intentional covered-by output, not placeholders.

## Final Recommendation

Accept UID0000OQ as a complete reconstructable whole-file recommendation. The authorized implementation callback applied and validated the exact eleven ordinary destinations enumerated below and in C0000OQ-064; the dated receipts are in Validator Results and Changed Files. Section 21 remains a proposed supervisor-owned IDA contract, not a mutation receipt: Gate 2B must bind every request to the supplied isolated session/path, reproduce the baseline there, require the seven exact transaction-local TYPE-PRE first lines after A00/pure rename, apply rename/type/function comments to seven existing functions, apply only regular/repeatable address comments to raw A08/A09, and pass seven complete-body direct decompile pairs plus all protected postreads. A08/A09 must remain function/name/type/function-comment/frame absent. Historical transactions `UID0000OQ-20260822-153330693` and `UID0000OQ-20260822-155922093` are unsaved/superseded and grant no applied credit. Every ordinary source-quality blocker is resolved. No-caller/no-xref/original-spelling facts are exhausted score caps, not deferred work.

## Recommended Target Doc Changes

The authorized callback applied ordinary destination 1 of 11, `by-file/TextPad.md` UID0000OQ, at `94/93`: Status, File Role, inventory, dependencies, ownership, source placement, reconstruction status, generated comparison, negative evidence, score rationale, and changes now carry this report's complete facts. Path, FILE owner, one CPP/H unit, exact child order, and historicalized read-only/main-close/old-event identities are preserved.

## Recommended Support Doc Changes

The authorized callback applied the following ten support recommendations. This list remains the accepted destination/mechanics record rather than an outstanding ordinary task.

- Ordinary destination 2 is `by-class/TextPad.md` UID0000EU: 94/93, position 10, exact preamble/header, no fields/destructor, corrected vtables.
- Ordinary destination 3 is `by-memory/0x00595900-0x00596242.TextPad.md` UID0001JV: 94/94, position 20, exact four bodies; replace stale/provisional prose.
- Ordinary destination 4 is `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md` UID0001JW: 93/94, position 30, direct prefix CPP, no null helper, inlining documented.
- Ordinary destination 5 is `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md` UID000248: 93/93, position 40, exact current APIs/file format/raw helper source/liveness cap. Its implemented formal SetFont/SetColor source remains valid; the separate Section 21 IDA disposition is now address-comment-only and does not define/type/name either raw body.
- Ordinary destination 6 is `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md` UID0003DY: 92/96, position 50, exact 23/11/2 inventory and covered-by comment.
- Ordinary destination 7 is `by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md` UID0003DZ: 92/96, position 60, exact literals/xrefs/tail protection and covered-by comment.
- Ordinary destination 8 is `by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md` UID00026O: preserve 87/92 mixed non-emitting state; correct only TextPad subsections.
- Ordinary destination 9 is `by-memory/-ignored.md` UID0000VN: add all exact Section 14 padding islands.
- Ordinary destination 10 is `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` UID0002AS: preserve 90/90; add the exact CreateFileW H declaration.
- Ordinary destination 11 is `by-file/PlatformApi.md`: preserve 90/90; add exact CreateFileW consumer/dependency prose.
- Every other named dependency page remains unchanged and is excluded from the callback/validation set because its required API is already present.

## Score And Metadata Recommendation

| UID | Current | Proposed | Basis and cap |
| --- | --- | --- | --- |
| 0000OQ | 88/89 | 94/93 | complete inventory/CPP/H/routing; no constructor caller and stripped spellings cap |
| 0000EU | 88/89 | 94/93 | complete declaration/vtables/no-field closure; same caps |
| 0001JV | 88/89 | 94/94 | exact corrected methods/constructor/padding/EH |
| 0001JW | 88/90 | 93/94 | exact dispatcher/caller/literals/inlining; private spelling inferred |
| 000248 | 90/90 | 93/93 | exact APIs/file format/raw bodies; zero xrefs and anomalous arithmetic cap |
| 0003DY | 87/92 | 92/96 | exact bytes/COL/slots/compiler disposition |
| 0003DZ | 87/92 | 92/96 | exact bytes/literals/xrefs/boundary; partial itemization protected |
| 00026O | 87/92 | unchanged | broad mixed-owner aggregate |
| 0002AS | 90/90 | unchanged | one consumer declaration omission only |

All six TextPad support pages remain reconstructable, owned/emitted by UID0000OQ, positions 10-60. No additional target/split.

## Open Questions With Attempted Resolution

| Question | Attempted routes | Final disposition |
| --- | --- | --- |
| Constructor caller | live xrefs, historical rel32/dword scans, vptr/global/layer/source neighbors | no caller recoverable; owner/behavior closed; confidence cap |
| Standalone liveness | all-start xrefs, raw validation, inlined duplicate flow, receiver/neighbor/padding | retained authored methods; no-xref cap |
| Virtual names | complete base slot order plus target bodies/xrefs | HandleKeyOrTextEvent, DrawBackground, DrawBorder final |
| Control +0x100 | current ControlPane layout and sibling Enter consumers | inherited m_handlesEnterKey final |
| Format payload/API | live type, raw offsets/masks, current H | TextRunFormatData plus ApplySelectionFormat final |
| Header/fields/destructor | cross-TU need, base-state use, vtables, destructor search | H required; no fields/explicit destructor |
| String item resizing | exact bytes/xrefs/current heads | no resize; comments only |
| Raw A08/A09 IDA modeling | exact disassembly semantics plus failed isolated MID-RAW frame readback | source identities remain final, but public IDA mutation is conclusively limited to regular/repeatable address comments; functions/names/types/function comments/frames remain absent |
| A01-A07 TYPE-PRE rendering | canonical stored declarations, isolated A00/pure-rename replay, seven direct decompiles | exact transaction-local first lines are the seven Section 21 values; Hex-Rays propagation and auto-naming are semantic baseline state, not formatting or a source change |

No item is deferred as future investigation or blocks source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Replace by-file/-coverage-report.md UID0000OQ row exactly:

- [UID:0000OQ][TextPad](by-file/TextPad.md) : reconstructable : 94% : very-strong : Complete ui/dialogs TextPad.cpp/TextPad.h reconstruction with nine authored methods, exact constructor/control/event/draw/file/format behavior, complete source order and dependency includes, compiler-only EH/vtable handling, exact command literals and padding, live IDA xrefs/boundaries, and retained no-constructor-caller/no-helper-xref lexical caps.

Replace by-class/-coverage-report.md UID0000EU row exactly:

- [UID:0000EU][TextPad](by-class/TextPad.md) : reconstructable : 94% : very-strong : Complete field-free DialogPane-derived TextPad declaration and source preamble with required TextPad.h, exact HandleKeyOrTextEvent/DrawBackground/DrawBorder overrides, private command/file/format methods, three-vtable compiler disposition, six-child source order, and explicit reachability/lexical confidence caps.

Replace three by-memory/-coverage-report.md executable rows exactly:

    - [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md) : reconstructable : 94% : very-strong : Exact TextPad executable aggregate with constructor, HandleKeyOrTextEvent, DrawBackground, DrawBorder, private command and retained helper children, adjusted-this inheritance, compiler EH exclusions, and every alignment/successor boundary.
    - [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) : reconstructable : 93% : very-strong : Exact private TextPad SendText dispatcher with sole Enter-handler caller, direct four-prefix tests and offsets, decimal format parsing, no unsupported null guard, and compiler-inlined retained helper behavior.
    - [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md) : reconstructable : 93% : very-strong : Exact retained TextPad Open/Save/SetFont/SetColor methods with modeled/raw bounds, current TextEditScrap/TextRunFormatData APIs, shipped file-envelope arithmetic and no-handle-guard behavior, MemoryMan ownership, exact padding, and explicit no-xref liveness cap.

Under UID00026O, insert immediately after UID0002OZ exactly:

        - [UID:0003DY][0x0062e18c-0x0062e228.TextPadVtableData](by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md) 0x0062e18c-0x0062e228 | vtable-data | TextPadVtableData : reconstructable : 92% : very-strong : Exact three-COL and 23/11/2-slot TextPad vtable data with constructor stores, corrected HandleKeyOrTextEvent/DrawBackground/DrawBorder cells, compiler-emitted covered-by source disposition, and protected decorated names/bytes.
        - [UID:0003DZ][0x0062e228-0x0062e268.TextPadCommandStrings](by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md) 0x0062e228-0x0062e268 | string-data | TextPadCommandStrings : reconstructable : 92% : very-strong : Exact Open/Save/SetFont/SetColor UTF-16 prefix island with one SendText xref per literal, exact Thread successor boundary, source-literal covered-by disposition, and protected partial IDA item tails.

The tracker is validator-owned. It should later derive 94/93, reconstructable true, six routed supports, and lifecycle state from source docs; no manual tracker edit.

## Follow-Up Actions

1. Supervisor performs wholly fresh exact-artifact Gate 1, then fresh Gate 2A on this exact callback artifact and all 65 twins, including an independent then-current generated readback.
2. Supervisor creates a new isolated Gate 2B working copy, supplies and immutably binds its exact MCP session/path, proves `is_analyzing:false` through `idb_list`, replays every Section 21 preflight/action/post-read only there, requires all seven exact corrected TYPE-PRE first lines before `set_type`, retains complete TYPE-PRE/TYPE-POST bodies for A01-A07, and applies only the two exact address-comment channels at each raw A08/A09 start while preserving function/name/type/function-comment/frame absence. Persistence/rollback remain supervisor-owned; the canonical IDB remains read-only.
3. Supervisor applies the exact Section 28 manual coverage text and all lifecycle actions. B003 performs no coverage, IDA, execution, archive, or lifecycle mutation.

## Confidence

High for inventory, ownership, identities, behavior, ranges, vtables, literals, APIs, order, formal source, the seven exact transaction-local TYPE-PRE first lines, and the address-comment-only A08/A09 safety boundary. Strong for constructor activation, retained-helper liveness, and stripped private spelling; those exact caps are scored and do not block reconstruction. Neither failed transaction reduces source confidence: the first conclusively removed raw function/frame mutation, while the second corrected pre-type Hex-Rays rendering without changing complete-body semantics or intended post-type declarations.

## Validator Results

Historical report-only receipts remain preserved: command 000000026444 at 2026-08-22T06:46:20-04:00 and command 000000026459 at 2026-08-22T09:48:26-04:00 each observed a 5,856-byte/193-LF TextPad.cpp with stale APIs and no TextPad.h. Neither is current authority.

The authorized callback ran all eleven scoped validators serially, each exit `0` / `ok: 1`, with the owning by-file page last. Ordered receipts are: `000000026681` at `2026-08-22T15:03:43-04:00` for `by-class/TextPad.md`; `000000026683` at `15:04:27` for UID0001JV; `000000026685` at `15:04:59` for UID0001JW; `000000026687` at `15:05:32` for UID000248; `000000026689` at `15:06:03` for UID0003DY; `000000026690` at `15:06:16` for UID0003DZ; `000000026693` at `15:06:32` for UID00026O; `000000026696` at `15:06:54` for `by-memory/-ignored.md`; `000000026699` at `15:07:10` for UID0002AS; `000000026702` at `15:07:27` for `by-file/PlatformApi.md`; and `000000026705` at `15:07:45` for `by-file/TextPad.md`. Each command initially reported `generated_refresh: deferred`; the relevant deferred refreshes completed before physical readback.

Dated physical generated receipts after all callback refreshes had completed were reread at 2026-08-22T15:13-04:00. The latest observed global generated header was command `000000026747`, refreshed `2026-08-22T15:13:14-04:00`: `auto-generated/NexusTK/ui/dialogs/TextPad.cpp` SHA256 `C138069651ABD4E16E7151CD7E8B5FA60D866A623A3EA5B4230E202AB52FD31F`, 6,841 bytes, 192 LF/0 CR; required `TextPad.h` SHA256 `AA567EED4F6DAEEB54BA747D671635F24EE7A508E49A41DEA7EC6B458CD2E834`, 837 bytes, 30 LF/0 CR; and `auto-generated/NexusTK/platform/PlatformApi.h` SHA256 `214F5BCFC80B0543AE3EE738344936EC8D4B87A07D1563258C957AE0F5021CE9`, 1,067 bytes, 25 LF/0 CR. TextPad CPP contains all nine authored methods, exact current constructor/event/draw/file/format APIs, direct prefix tests, both covered-by comments, and no stale identities/APIs; TextPad H is the complete fieldless/no-explicit-destructor class; PlatformApi H contains exactly five externs and the exact seven-parameter `g_pfnCreateFileW`. The source-specific validator receipts remain `000000026705` for TextPad and `000000026702` for PlatformApi; command `000000026747` is the later observed global generated refresh header. These are dated callback receipts, so fresh Gate 2A independently rereads mutable generated authority.

Supervisor Gate 2B transaction `UID0000OQ-20260822-153330693` is a dated failed, unsaved, superseded receipt. All isolated prestates passed; A00 declared only the two incomplete TextPad types in memory; temporary `define_func` actions created exact A08/A09 bounds/autonames without geometry/byte/xref/padding drift; then MID-RAW `stack_frame` returned only `__saved_registers@0xc/0x4 _DWORD` and `__return_address@0x10/0x4 _UNKNOWN *` for each body. Because the promised local/argument rows were absent, the supervisor hard-stopped before rename/type/comment. No save occurred, no TX exists, and canonical/backup/working physical files remained SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28`, 143,211,242 bytes. No failed in-memory action is applied. The prior raw-frame report repair ran no validator, generated refresh, IDA request, or lifecycle command.

Supervisor Gate 2B transaction `UID0000OQ-20260822-155922093` is a second dated failed, unsaved, superseded receipt. PRE-00-PRE-10 passed against isolated session `supervisor_uid0000oq_gate2b_20260822_155922` and working path `E:\NTK\Resources\NexusTK\gate2b-transactions\UID0000OQ-20260822-155922093\NexusTK.exe.uid0000oq-working.i64`; A00 declared only incomplete TextPad/TextPadEventHandlerFacet types; the pure seven-function rename and immediate address/name/raw-absence lookup passed. TYPE-PRE then returned the seven exact Section 21 first lines, with A01/A02/A03/A05/A07 contradicting the previous literals and A04/A06 matching. The supervisor stopped before `set_type`, comments, save, TX creation, or canonical promotion. Working and backup files remained SHA256 `A4A6CF1D81D595DD7265F05183D92D977BF141688C1EB91E23970C6920C55C28`, 143,211,242 bytes; intended TX does not exist. No failed in-memory action is applied. This additive report repair ran no validator, generated refresh, IDA request, or lifecycle command.

## Changed Files

The authorized callback authored exactly eleven ordinary destinations plus this report. Closing ordinary hashes are: `by-file/TextPad.md` `4037A722282319AAF02D3ED43E4AD7B200AD8D053047ABE1581F4F7486846043`; `by-class/TextPad.md` `1ABB17BE8863512D1E4DD399BA3CADD578E0136BA5A2C1611549BED3F47E4362`; UID0001JV `DD62EE187A001DC59EEE8572011CC934A903AD17E6C43874B2632D5331C050FD`; UID0001JW `2699BC959CC7279BA4256C9BA4757C5590EF11C9F18BE1C1B77A6F6300914014`; UID000248 `C2CE025135FFB9C319ED0F2CC4CAA8CEF77B9C5DB0822BA16C536AB74B5D3795`; UID0003DY `64D9DC84580D90E865C4D8D37FD7072A61025B18E7823AD80C9FD867CEDD5B2E`; UID0003DZ `415D478200C19898D306E3538F255EC456A283904684595FA04101966FBE7BAB`; UID00026O `934AE45B7052B9D8F748F41CD99BB3674DD16318C75C8573A2DC42536A872441`; `by-memory/-ignored.md` `5769416BCCA0BB5AE31CD3FFB2FE180879FA4752EC0750FEF69733A2292E803C`; UID0002AS `E9C453D64E01EAE1FB2CAE89C68225F4FF0361F4C6E49315336FE426A0C0B0C7`; and `by-file/PlatformApi.md` `F7E890E84D4EF485C2C96B8C18BCB786294ED4784BF7CE87896F3508624B895C`. No unchanged dependency page was edited. This additive TYPE-PRE repair changes only this report and preserves every ordinary hash/source/receipt and the prior A08/A09 safe subset. B003 used only the short report lease for active edits and releases it immediately after the final save. Generated artifacts changed only through historical authorized validators; B003 made no direct ordinary-doc, generated, coverage, tracker, audit, catalog, IDA, report-lifecycle, archive, or `execute_report` mutation during this repair. The release receipt is returned to the supervisor.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination | Action | Verification State |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000OQ-001 | 0000OQ | TextPad is one complete CPP/H source unit with nine authored methods, exact data consequences, dependencies, and boundaries. | high | Whole-file docs, MCP, and generated inventory. | by-file/TextPad.md UID0000OQ, Status, File Role, Function Map, Reconstruction Status. | incorporate | applied |
| [x] | C0000OQ-002 | 0000OQ | Current 88/89 and blank tracker reconstructable metadata are historical scope, not negative evidence. | high | Stable authority: auto-generated/-ag-research-tracker.md -> `## by-file` -> `### Not-Covered Files - Not Reconstructable` -> `[UID:0000OQ][TextPad](by-file/TextPad.md)`; no mutable line number is authoritative. | by-file/TextPad.md UID0000OQ, metadata and Score Rationale. | historicalize | applied |
| [x] | C0000OQ-003 | 0000OQ | Canonical placement is NexusTK/ui/dialogs/TextPad.cpp with required TextPad.h. | high | Source tree, owner docs, generated route. | by-file/TextPad.md UID0000OQ, Status and Source Placement. | incorporate | applied |
| [x] | C0000OQ-004 | 0000OQ | TextPad adds no source fields and needs no authored destructor declaration or body. | high | Base-state use, vtables, no destructor body. | by-class/TextPad.md UID0000EU, Responsibility, Layout, Reconstruction Notes. | incorporate | applied |
| [x] | C0000OQ-005 | 0000OQ | Exact emitter order is UID0000EU, 0001JV, 0001JW, 000248, 0003DY, 0003DZ at positions 10,20,30,40,50,60. | high | Complete source dependency order. | by-class/TextPad.md UID0000EU and by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, 0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW, 0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, 0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, and 0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, EMITTER_POSITION_OPTIONAL metadata and formal-channel order. | incorporate | applied |
| [x] | C0000OQ-006 | 0000OQ | 0x00595900-0x00595ae2 is TextPad::TextPad(), size 0x1e2. | high | Live lookup, disassembly, decompile. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Covered Range and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-007 | 0000OQ | Constructor calls DialogPane with empty title, config 0xffff, mode 0, and builds exact full-screen/main/command bounds. | high | Live constructor operands and globals. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Constructor Evidence and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-008 | 0000OQ | Main control uses the exact eleven-argument TextEditControlPane constructor contract. | high | Live call operands and current H. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Constructor Evidence and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-009 | 0000OQ | Main control is added, limited to 2000 lines and 30000 chars, and sets inherited handles-Enter true. | high | Live calls, +0x100 ControlPane contract. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV and by-class/ControlPane.md UID000038 consumer prose. | incorporate | applied |
| [x] | C0000OQ-010 | 0000OQ | Command control is child 1 and uses the exact no-vertical-scrollbar constructor flags. | high | Constructor operands and handler lookup. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-011 | 0000OQ | Constructor order is hover 0, clamp full frame, OnCreate root layer, OnShow before screen pane. | high | Calls at 0x595a91-0x595ac0. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV Behavior/RECONSTRUCTION_CPP CODE and by-file/TextPad.md UID0000OQ Function Map. | incorporate | applied |
| [x] | C0000OQ-012 | 0000OQ | Constructor cleanup range 0x609900-0x609943 is compiler-only EH/delete/cookie output. | high | Exception references and ordinary construction. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Compiler Output. | incorporate | applied |
| [x] | C0000OQ-013 | 0000OQ | 0x00595af0 is secondary-view HandleKeyOrTextEvent, not OnKeyInput. | high | Secondary vtable slot +0x08 and live body. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ identity tables and RECONSTRUCTION_CPP CODE / RECONSTRUCTION_H CODE. | reject-stale | applied |
| [x] | C0000OQ-014 | 0000OQ | Handler requires translated key 13, active control 1, and kEventKeyDown. | high | Live decompile and Event enum. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-015 | 0000OQ | Handler reads child 1 to 1023 chars, sends text, selects 0..0x7fff, else calls the base. | high | Live call and data flow. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, Behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-016 | 0000OQ | 0x00595bb0 is DrawBackground using color 0x80, mode 0, and g_pfnFillRect on m_visibleBounds. | high | Primary slot +0x50 and disassembly. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ formal/prose and Surface dependency. | reject-stale | applied |
| [x] | C0000OQ-017 | 0000OQ | 0x00595bd0 is the empty DrawBorder override. | high | Primary slot +0x54 and one-byte return. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ formal/prose. | reject-stale | applied |
| [x] | C0000OQ-018 | 0000OQ | Historical OnClose, OnEmptyVirtual, and close/hide prose are invalid. | high | Complete primary vtable order. | by-file/TextPad.md UID0000OQ; by-class/TextPad.md UID0000EU; by-memory/0x00595900-0x00596242.TextPad.md UID0001JV; 0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW; 0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248; 0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY; 0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ; 0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O; by-memory/-ignored.md UID0000VN, normative and historical identity sections. | reject-invalid | applied |
| [x] | C0000OQ-019 | 0000OQ | 0x00595be0-0x00595f26 is private SendText with sole code caller 0x595b64. | high | Live lookup and xref. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW. | incorporate | applied |
| [x] | C0000OQ-020 | 0000OQ | Prefix tests are direct wcsstr(input,prefix)==input with no null guard. | high | Live decompile. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW behavior/RECONSTRUCTION_CPP CODE and generated-defect history. | reject-stale | applied |
| [x] | C0000OQ-021 | 0000OQ | Prefix offsets are 5,5,8,9 wchar units and format values use decimal wide scan. | high | Branch operands and scan calls. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-022 | 0000OQ | SendText inlines four retained helpers while out-of-line copies remain authored source. | high | Identical flows and retained bodies. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW and by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Relationship/Reconstruction Notes. | incorporate | applied |
| [x] | C0000OQ-023 | 0000OQ | 0x00595f30-0x00596065 is retained Open(const wchar_t*), size 0x135. | high | Live lookup and decompile. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248. | incorporate | applied |
| [x] | C0000OQ-024 | 0000OQ | Open uses read/open-existing/sequential CreateFileW flags and has no invalid-handle guard. | high | Live decompile and API constants. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-025 | 0000OQ | Open allocates fileSize+1, reads fileSize, and performs the shipped word write at buffer+2*fileSize. | high | Exact live instructions. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE anomaly note. | incorporate | applied |
| [x] | C0000OQ-026 | 0000OQ | Open reads payload length at +2*textChars+2 and uses the shipped payload pointer +textChars+5. | high | Exact live addressing. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 file-format section and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-027 | 0000OQ | Open pastes through main child TextEditPane and frees through MemoryMan. | high | Live calls and current declarations. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-028 | 0000OQ | 0x00596070-0x005961c8 is retained Save(const wchar_t*), size 0x158. | high | Live lookup and decompile. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Covered Range and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-029 | 0000OQ | Save preserves short caret range around select-all and CopySelectionToScrap. | high | Live flow and current H. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-030 | 0000OQ | Save writes text bytes, one zero byte, optional four-byte payload size, then payload bytes. | high | Live WriteFile sequence. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 file-format section and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-031 | 0000OQ | Save has no handle guard and frees both optional duplicate buffers via MemoryMan. | high | Live branches and calls. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 behavior and RECONSTRUCTION_CPP CODE. | incorporate | applied |
| [x] | C0000OQ-032 | 0000OQ | Raw 0x005961d0-0x00596204 is SetFont using TextRunFormatData +0 and mask 1; formal source is implemented, while the proposed IDA disposition is address-comment-only with function/name/type/frame absent. | high | Live raw instructions/type layout, accepted ordinary callback, and failed MID-RAW receipt. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Covered Range and RECONSTRUCTION_CPP CODE; this report Section 21 A08 address-comment-only recommendation. | incorporate | applied to ordinary destination; IDA remains proposed under C0000OQ-060 |
| [x] | C0000OQ-033 | 0000OQ | Raw 0x00596210-0x00596242 is SetColor using TextRunFormatData +4 and mask 2; formal source is implemented, while the proposed IDA disposition is address-comment-only with function/name/type/frame absent. | high | Live raw instructions/type layout, accepted ordinary callback, and failed MID-RAW receipt. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 Covered Range and RECONSTRUCTION_CPP CODE; this report Section 21 A09 address-comment-only recommendation. | incorporate | applied to ordinary destination; IDA remains proposed under C0000OQ-060 |
| [x] | C0000OQ-034 | 0000OQ | Every internal separator is exact 0xcc padding and the successor starts at 0x00596250; A08/A09 remain raw code outside functions and their address-comment-only actions preserve every separator and successor fact. | high | Live bytes/items plus failed-transaction geometry receipt. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, by-memory/-ignored.md UID0000VN, and this report Section 21 P01. | incorporate | applied to ordinary destinations; IDA protection remains proposed under C0000OQ-060 |
| [x] | C0000OQ-035 | 0000OQ | Current TextRunFormatData and ApplySelectionFormat replace the invented payload and InsertTextObject. | high | Current TextEditPane H and live type. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 RECONSTRUCTION_CPP CODE/prose; by-class/TextEditPane.md already-present support. | reject-invalid | applied |
| [x] | C0000OQ-036 | 0000OQ | Zero xrefs to standalone starts are a retained-liveness cap, not dead/no-code proof. | strong | Live xrefs and duplicated/inlined source family. | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, by-class/TextPad.md UID0000EU negative evidence and scores. | incorporate | applied |
| [x] | C0000OQ-037 | 0000OQ | Vtable data is exactly 0x9c bytes: three COL cells plus 23,11,2 slots. | high | Live 220-byte read and constructor stores. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY. | incorporate | applied |
| [x] | C0000OQ-038 | 0000OQ | Exact overridden cells are DrawBackground, DrawBorder, and HandleKeyOrTextEvent. | high | Vtable order and cell xrefs. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY plus by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O, by-class/TextPad.md UID0000EU, by-file/TextPad.md UID0000OQ. | reject-stale | applied |
| [x] | C0000OQ-039 | 0000OQ | RTTI, COLs, and vtables are compiler-emitted; UID0003DY emits only a covered-by comment. | high | Ordinary class declaration explains data. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY RECONSTRUCTION_CPP CODE and no-code disposition. | incorporate | applied |
| [x] | C0000OQ-040 | 0000OQ | Command-string range is exact 0x40 bytes with four literals and one xref each. | high | Live bytes, items, xrefs. | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ. | incorporate | applied |
| [x] | C0000OQ-041 | 0000OQ | Three short IDA string heads must not trigger tail resize or retyping. | high | Current itemization versus exact bytes. | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ IDA status and report Section 21 protections. | incorporate | applied |
| [x] | C0000OQ-042 | 0000OQ | Dword 0x0062e268 and function 0x00596250 belong to Thread and are excluded. | high | Neighbor bytes, items, docs. | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O boundary prose. | incorporate | applied |
| [x] | C0000OQ-043 | 0000OQ | File dependencies are CreateFileW dispatch plus GetFileSize, ReadFile, WriteFile, CloseHandle, and CRT wide routines. | high | Live refs and current imports. | by-file/TextPad.md UID0000OQ Dependencies; by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 and by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW evidence. | incorporate | applied |
| [x] | C0000OQ-044 | 0000OQ | Globals are screen dimensions, root layer slot, screen pane, event manager, and Surface fill callback. | high | Constructor, handler, draw refs. | by-file/TextPad.md UID0000OQ Dependencies and exact by-global cross-references. | incorporate | applied |
| [x] | C0000OQ-045 | 0000OQ | No TextPad-owned writable globals, resources, or statics exist beyond source literals and pooled empty string. | strong | Whole-file data/xref inventory. | by-file/TextPad.md UID0000OQ Data, Resources, Negative Evidence. | incorporate | applied |
| [x] | C0000OQ-046 | 0000OQ | TextEditScrap owns text/payload copying and duplication used by TextPad. | high | Current UID0000EP H and live calls. | by-class/TextEditScrap.md UID0000EP, existing API section. | already-present | applied |
| [x] | C0000OQ-047 | 0000OQ | Allocation/free route is GetMemoryMan with AllocateBufferMemory and FreeBufferMemory. | high | Live calls and UID00007U/0001BC declarations. | by-class/MemoryMan.md UID00007U and by-memory GetMemoryMan by-memory/0x00516030-0x00516036.GetMemoryMan.md UID0001BC. | already-present | applied |
| [x] | C0000OQ-048 | 0000OQ | PlatformApi H lacks the required exact g_pfnCreateFileW extern. | high | Physical H read and dispatch-slot reference. | by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md UID0002AS RECONSTRUCTION_H CODE and by-file/PlatformApi.md prose. | incorporate | applied |
| [x] | C0000OQ-049 | 0000OQ | Dated command-26444 and command-26459 generated TextPad snapshots have wrong event/background/border identities; neither receipt is timeless authority. | high | Dated generated reads versus live vtables; dynamic Gate 2A reread required. | by-file/TextPad.md UID0000OQ, by-class/TextPad.md UID0000EU, by-memory/0x00595900-0x00596242.TextPad.md UID0001JV historical generated-defect prose and dynamic generated verification. | historicalize | applied |
| [x] | C0000OQ-050 | 0000OQ | Dated command-26444 and command-26459 generated constructor snapshots use abbreviated or wrong control/create/layer/show APIs; every Gate 2A rereads current semantics. | high | Dated generated reads versus live operands/current H. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV and by-file/TextPad.md UID0000OQ historical generated comparison and dynamic generated verification. | historicalize | applied |
| [x] | C0000OQ-051 | 0000OQ | Dated command-26444 and command-26459 generated helper snapshots use nonexistent editor/memory/format APIs and an unsupported null-guard source shape; every Gate 2A rereads current semantics. | high | Dated generated reads versus dependencies/live bodies. | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW and by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248 historical generated comparison and dynamic generated verification. | historicalize | applied |
| [x] | C0000OQ-052 | 0000OQ | TextPad.h is absent in both dated generated receipts and remains a completion defect requiring a complete class declaration, subject to dynamic Gate 2A presence/readback. | high | Dated physical absence and cross-TU class use. | by-class/TextPad.md UID0000EU RECONSTRUCTION_H CODE and by-file/TextPad.md UID0000OQ Reconstruction Status and dynamic generated verification. | incorporate | applied |
| [x] | C0000OQ-053 | 0000OQ | Section 22 CPP is the complete C++03 source recommendation. | high | Reconciled live/source contracts. | by-class/TextPad.md UID0000EU, 0001JV, 0001JW, 000248, 0003DY, 0003DZ RECONSTRUCTION_CPP CODE channels. | incorporate | applied |
| [x] | C0000OQ-054 | 0000OQ | Section 22 H is the complete TextPad declaration with no fields or explicit destructor. | high | Vtable/source inventory and base contract. | by-class/TextPad.md UID0000EU RECONSTRUCTION_H CODE. | incorporate | applied |
| [x] | C0000OQ-055 | 0000OQ | Main executable page must replace stale behavior, identities, provisional flags, and open questions. | high | Current page versus closed research. | by-memory/0x00595900-0x00596242.TextPad.md UID0001JV normative sections. | incorporate | applied |
| [x] | C0000OQ-056 | 0000OQ | File and class pages must carry complete inventory, corrected identities, source order, dependencies, and caps. | high | Whole-file report. | by-file/TextPad.md UID0000OQ and by-class/TextPad.md UID0000EU. | incorporate | applied |
| [x] | C0000OQ-057 | 0000OQ | Vtable, string, and aggregate pages must replace stale slot labels and record compiler/source-literal dispositions. | high | Live data reconciliation. | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md UID00026O TextPad subsections. | incorporate | applied |
| [x] | C0000OQ-058 | 0000OQ | Proposed scores are 94/93, 94/93, 94/94, 93/94, 93/93, 92/96, 92/96 for file/class/main/command/standalone/vtable/strings. | strong | Closed inventory with named residual caps. | by-file/TextPad.md UID0000OQ; by-class/TextPad.md UID0000EU; by-memory/0x00595900-0x00596242.TextPad.md UID0001JV, 0x00595be0-0x00595f26.TextPadCommandHelper.md UID0001JW, 0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md UID000248, 0x0062e18c-0x0062e228.TextPadVtableData.md UID0003DY, and 0x0062e228-0x0062e268.TextPadCommandStrings.md UID0003DZ, metadata and Score Rationale. | incorporate | applied |
| [x] | C0000OQ-059 | 0000OQ | No new UID, split, owner, resource, or source file is justified. | high | Exhaustive code/data/neighbor inventory. | by-file/TextPad.md UID0000OQ Range, Split, Ownership sections. | not-applicable | applied |
| [ ] | C0000OQ-060 | 0000OQ | The IDA handoff is a proposed isolated-transaction contract for seven existing function rename/type/comment entities with seven exact corrected TYPE-PRE first lines, two raw address-comment-only entities, thirteen data-comment entities, and seven direct decompile pairs; A08/A09 must remain function/name/type/frame absent. | high | Dated canonical prestates, failed unsaved transactions `UID0000OQ-20260822-153330693` and `UID0000OQ-20260822-155922093`, and current public schemas; supervisor-time isolated replay remains mandatory and no mutation receipt is claimed. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ, Section 21 PRE-00-PRE-10, A00-A09, exact TYPE-PRE/TYPE-POST-A01-A07 table, POST-01-POST-08, and both failed-transaction histories. | incorporate | proposed |
| [ ] | C0000OQ-061 | 0000OQ | Thirteen COL/vtable/slot/string and two raw-start address-comment entities have per-entity physical item/name/type/byte/xref/comment prestates, exact comments, protected tails/neighbors, and deterministic readbacks; the raw starts additionally require function/name/type/frame absence. | high | Fresh canonical compiler/data identity, partial string itemization, exact raw geometry, and failed MID-RAW receipt. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ, Section 21 A08-A09, D01a-D09, P01-P02, and POST-01-POST-08. | incorporate | proposed |
| [ ] | C0000OQ-062 | 0000OQ | Gate 2B replay of the corrected seven-pair TYPE-PRE contract and unchanged address-comment-only safe subset, persistence, rollback, and lifecycle are external supervisor work; both failed unsaved transactions grant no applied credit and no operational package is embedded. | high | Current workflow role boundary and two historical failed-transaction receipts. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ Section 21 external handoff and Validator Results; supervisor Gate 2B persistence/rollback and validator lifecycle actions. | not-applicable | proposed |
| [ ] | C0000OQ-063 | 0000OQ | Seven exact manual coverage row replacements or inserts are required. | high | Read-only coverage comparison. | by-file/-coverage-report.md UID0000OQ row; by-class/-coverage-report.md UID0000EU row; by-memory/-coverage-report.md UID0001JV, UID0001JW, UID000248, UID0003DY, and UID0003DZ rows; Exact Manual Supervisor-Owned Coverage Or Tracker Text. | incorporate | proposed |
| [x] | C0000OQ-064 | 0000OQ | Later callback edits and validates exactly eleven ordinary destinations: `by-file/TextPad.md`; `by-class/TextPad.md`; `by-memory/0x00595900-0x00596242.TextPad.md` UID0001JV; `by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md` UID0001JW; `by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md` UID000248; `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md` UID0003DY; `by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md` UID0003DZ; `by-memory/0x0062df94-0x0062e268.TextEditReadOnlyData.md` UID00026O; `by-memory/-ignored.md`; `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md` UID0002AS; and `by-file/PlatformApi.md`. Already-present unchanged dependency pages are excluded. Every supervisor Gate 2A also dynamically rereads then-current generated command/time/size/hash/presence/semantics for TextPad CPP/H and PlatformApi H. | high | Exact accepted ordinary destination set plus mutable generated-authority workflow rule and dated 26444/26459 receipts. | B003 implementation/scoped validation: the exact eleven ordinary paths named in this claim, no others. Supervisor Gate 2A dynamic physical readback: `auto-generated/NexusTK/ui/dialogs/TextPad.cpp`, `auto-generated/NexusTK/ui/dialogs/TextPad.h`, and `auto-generated/NexusTK/platform/PlatformApi.h`. | incorporate | applied |
| [x] | C0000OQ-065 | 0000OQ | Report remains lifecycle-neutral with exactly one physically terminal readiness marker; lifecycle authority remains external. | high | Current TYPE-PRE repair goal SHA256 C3234C346AFAFB0418DBCD2F167C73D22099F1C9454503EACD26C7479CA61356 and physical report-end readback. | tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md UID0000OQ, terminal line after the Implementation Tracking Checklist; validator-owned report status/history. | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000026932","destination_path":"executed-b-agent-research/B003/0000OQ-TextPad-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0000OQ-TextPad-file-source-quality.md","timestamp":"2026-08-22T16:39:08-04:00","uid":"0000OQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
