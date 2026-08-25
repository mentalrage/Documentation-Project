** TARGET-REPORT-UID:0001NM **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Callback-applied recommendation: [UID:0001NM] is now a `92/94`, `RECONSTRUCTABLE:FALSE`, non-emitting split index whose fifteen exact children carry every source body in address order.
- Semantic owner [UID:0000FS] `UserStatusPane` is preserved; the aggregate emitter, position, and formal value are blank; `Nested:0` is retained; and the former incomplete ten-child index is replaced by ten corrected existing children plus validator-issued children UID0004T3 through UID0004T7.
- The executable contains fifteen source-authored UserStatusPane bodies, not one aggregate body. The constructor, ordinary destructor, accessor island, status-icon setter, three virtuals, rect/glyph helpers, payload parser, and five retained raw helpers all belong in `NexusTK/ui/panels/UserStatusPane.cpp` through class [UID:0000FS] and file [UID:0000P2].
- The five raw starts have no direct entry xrefs or pointer-table routes, but their complete behavior, exact OldUserStatusPane analogs, class-local field use, adjacency, and optimizer-inlined router copies establish retained human source rather than padding, dead bytes, or compiler glue.
- Correct the class layout to a `0x2ac` Pane-derived object. In particular, `+0x27c` is a 16-bit nation id, `+0x27e` is a signed spirit/totem id, `+0x27f` is the status icon, `+0x280` is the class id, and `+0x281..+0x283` are three percentage attributes. The historical signed-byte nation plus reserved byte model is rejected.
- Preserve the executable's noncanonical and edge behavior: EPF status-rect ids `5/6/7` leave the output rectangle untouched, raw movement helpers return false in EPF mode, direction masking accepts only negative encoded directions under its gate, and payload parsing follows exact flag/cursor semantics without hardening.
- Raise source quality by providing a complete class declaration and complete managed C++ for all fifteen child bodies. Compiler vptr stores, base teardown, scalar/adjustor wrappers, switch tables, cookies, and alignment remain excluded from human source.
- Manual coverage synchronization remained supervisor-owned. The supervisor later applied and validated the exact five-file handoff under commands 14847-14851; the implemented text with the five real child UIDs remains preserved below, and B001 did not edit manual coverage.
- During the initial report-only evidence pass no ordinary edit, lease, validator, or generated refresh was performed. During the accepted implementation callback B001 performed the ordinary edits, short leases, scoped validators, and waited generated refresh enumerated later. IDA mutation, manual coverage edits, report execution, lifecycle actions, moves, and archives remained unperformed by B001.

## Supporting Research

- Mandatory MCP evidence was collected through the streamable NexusTK MCP endpoint. At research time `idb_list` returned active database `9b0396a3`, worker PID `15732`, `is_analyzing:false`; `server_health` returned `ok` with image base `0x00400000`, auto-analysis, Hex-Rays, strings, and a 2,067-entry string cache ready.
- Valid bounded `lookup_funcs`, `analyze_function`, `decompile`, `get_bytes`, `xrefs_to`, `find_bytes`, `insn_query`, and data-reference calls succeeded against database `9b0396a3`. Session identifiers are evidence-time provenance, not an assertion of indefinite future availability.
- Local PE input: `C:/Users/admin/Desktop/Clone/NexusTK/NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Exact aggregate bytes `[0x005b83b0,0x005baafe)` are 10,062 bytes, SHA256 `6D2120BB3260F821A592549A59FB876DAD3ABE00A24C45164A6B797FF3CE9723`.
- Direct historical report roots searched with UID, address, name, source-family, helper, field, protocol, and owner terms: active `tools/leaser/Agents/Agent-B001` through `Agent-B005`, central `executed-b-agent-research/**`, `tools/leaser/Agents/Older-Research/**`, `tools/leaser/Agents/SpecialReports/**`, and `archived/**`.
- Opened `executed-b-agent-research/B009/0000P2-UserStatusPane-empty-emitter-family-source-quality.md`, SHA256 `D55F1B79CD1ECA264516A3C175D65DBA620E0AF8DBB88E0D2394860D1ABE2388`: useful source-family and empty-emitter evidence, but not direct target closure; it leaves large children and raw helpers unresolved.
- Opened `executed-b-agent-research/B013/0000P2-UserStatusPane-current-empty-emitter-checkpoint.md`, SHA256 `CB9FB2E386AC8D50915116AFB47235B3CF85D8E1FC460C8FF5CA90E75E52CB44`: generated checkpoint and family inventory only.
- Opened `executed-b-agent-research/B003/0001NN-UserStatusPaneSummaryAccessors-source-quality.md`, SHA256 `034B3553E3181A70919630F1239925E42932CF61127BA253BC84F2FCD3A406B1`: direct accessor-child evidence only; its phantom `InvalidateSummaryText` and signed-byte nation declaration are superseded here.
- Opened `executed-b-agent-research/B004/00001N-CharacterSummaryRecord-source-routing.md`, SHA256 `B7317BD90BD5F98AAE0D4957EAD9CF7460D1B9E0D127EF5A1535682A6AB405CF`: supports folding the generated alias into UserStatusPane, not a standalone class.
- Opened `executed-b-agent-research/B002/0001NR-OldUserStatusPane-source-quality.md`, SHA256 `9EEF202E9416C4281F5DE348855DB6994DF99A71632590997468CE5B1C259464`: complete legacy aggregate/source analog, not direct newer-pane coverage.
- Opened `executed-b-agent-research/B007/000499-OldUserStatusPaneApplyLegacyMovementStep-source-quality.md`, SHA256 `965B8B045EE7570B9E5A9600ED7CD9DE062BF70F812E8E160386DA92A53DE99B`, and `executed-b-agent-research/B011/00049A-OldUserStatusPaneApplyLegacyMovementStepAlt-source-quality.md`, SHA256 `5575117FFCA14A5114B2EA5F73F5202B918E37DBF9BC67C01BD2D7CFC1CFCFEB`: behavior/name analogs independently validated against the newer raw bodies.
- Opened `executed-b-agent-research/B004/00049B-OldUserStatusPaneApplyLegacyStatusPayload-source-quality.md`, SHA256 `EC2EFAEC2C036CC469BBFFF91D5335ABFFF1CBB3F5FB5C5217E83E701E8FDE5C`: legacy payload analog, not a substitute for the newer EPF branch.
- Opened `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md`, SHA256 `6095198FF148691C9057C27C1EAEFAE6321F829A5BAB0DEABDAC8FD1974408C8`, its later `-2` revision SHA256 `1CAB6E8329CF778CF18B3FCC403DF9FD93E8979D952BCDCE8D62F287DD107B77`, and `executed-b-agent-research/B005/0001KC-TotemFrame-source-quality.md`, SHA256 `12E179678254F7DD509F392738E04DBB18329AEEE0037285DFBF4E977C88A13C`: caller and dependency evidence only.
- Opened active evidence-time report `tools/leaser/Agents/Agent-B003/research/0001LM-SpellFourArgsInputPaneConstructor-source-quality.md`, SHA256 `134FCD1EBCB4467F4313A88AA7EDB1500043C7E35C1DC4F6335D81AE1CDD4317`: its UserStatusPane occurrence is incidental dependency text and does not target this UID, range, class body, or destination set.
- `Older-Research/**` and `SpecialReports/**` contained no relevant direct report after the same concrete searches. `archived/**` contained no direct target report. The active B003 report mentions UserStatusPane incidentally but does not own UID0001NM or this source family.
- Explicit duplicate conclusion: no exact direct target report header for UID0001NM/address/name was found in active, central executed, older, special, or archived report roots. Existing reports cover support, adjacency, or individual children only.

## Target

- UID: `0001NM`.
- Current path: `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md`.
- Exact range: `[0x005b83b0,0x005baafe)`.
- Current SHA256: `FDD5CAC37B1DA542174B6AF1A48009F75FB2E2A03B08378A5EB781927B3800AE`.
- Current metrics: 22,358 bytes/171 lines.
- Current metadata: `92/94`, owner `0000FS`, reconstructable false, blank emitter/position/formal value, `Nested:0`.
- Selected source disposition: non-emitting audit/split index under UserStatusPane, with exact children as the only body emitters.

## Current Target State

- UID0001NM now contains the exact address-ordered fifteen-child split and emits no aggregate body. Real children UID0004T3, UID0004T4, UID0004T5, UID0004T6, and UID0004T7 own the five formerly undocumented retained bodies.
- UID0003AA now spans `[0x005b8700,0x005b8a0c)` and UID0003AD spans `[0x005b9db0,0x005ba017)`, retaining each body-owned switch/NOP table tail outside ignored padding.
- UID0000FS now carries the complete accepted `0x2ac` declaration with corrected field types/names, complete virtual/helper declarations, and exact ordered children. The target and all sixteen other managed destinations match the accepted blocks exactly.
- B001's completed waited refresh was command `000000014808` at `2026-07-20T00:42:23-04:00`; a one-line exact-block indentation repair was scoped-validated by command `000000014816`; final B001 waited command `000000014817` at `2026-07-20T00:49:16-04:00` produced historical callback SHA256 `BF60185943D18714E1F29FD32D4AD644A2BE7D66A665B9ED640EA4DFEFDD2B7D`, 39,093 bytes/1,155 lines. Commands 14732/14749/14758 are historical report-only baselines, command 14814 was an intervening external header refresh, command 14831/SHA `7239A048...329` is historical pre-command-14846 evidence, and command 14846/SHA `60340C7D...3789` is the exact historical implementation checkpoint. At this final read, external `UserStatusPane.cpp` is command `000000014857`, refreshed `2026-07-20T02:14:47-04:00`, SHA256 `73063CC95402E5641D0C085A846BE037B4A68EB27F4241959B1812DD107B238F`, 39,093 bytes/1,155 lines.
- Final-read command-14857 generated output has one complete `UserStatusPane : public Pane` declaration and one marker for each of the fifteen address-ordered source children. It has zero UID0001NM aggregate markers, zero Empty Emitter Markers, zero CharacterSummaryRecord tokens, zero `sub_*` or temporary UID tokens, and no manual RTTI/cookie/scalar/adjustor implementation. Six case-insensitive vtable tokens occur only in three covered-by comment pairs, not arrays or bodies; this is the same-or-greater semantic union seen at commands 14817, 14831, and 14846.
- The exact UserStatus manual coverage handoff was supervisor-applied and validated under commands 14847-14851. At this final read after unrelated B003 WorldMap supervisor-owned row changes, the sixteen by-memory rows and the class/file/layout/global rows in the preserved handoff still occur exactly once and match exactly; B001 did not apply, validate, or modify them.
- Final-read external tracker command `000000014857`, refreshed `2026-07-20T02:14:47-04:00`, SHA256 `63DED0512383825D29D170252D72040A97DA693D736AD2697AEF8260A6199DEF`, 1,517,511 bytes/6,158 lines, records UID0001NM at `92/94`, reconstructable false, zero direct reports, and the current target path; it also preserves current class/file/global/new-child scores. Command-14851-era and command-14846-era tracker snapshots are historical external checkpoints, not current authority or B001 lifecycle action.
- Callback status is terminal: all accepted claims have destination proof, all callback rows are checked, the 17 managed blocks match exactly, and B001 holds zero leases.

## Executive Recommendation

1. UID0001NM was converted to the accepted non-emitting fifteen-child index.
2. Five exact raw-helper pages were serially created and registered as UID0004T3, UID0004T4, UID0004T5, UID0004T6, and UID0004T7 before dependent links were added.
3. Validator-aware UID-preserving renames/range corrections were completed for UID0003A9, UID0003AA, UID0003AC, UID0003AE, UID0003AD, UID0003AF, and UID0003AB.
4. The UserStatusPane class formal is the complete accepted `0x2ac` declaration and retains the established class/file emission route.
5. All fifteen exact child bodies occupy positions `10..150`; hierarchy deltas are parent `0`, constructor `+4`, later children `0`, and following UID0001NO `-4`.
6. Only the proven internal all-`0xcc` intervals were added to `by-memory/-ignored.md`; compiler-table tails remain in their owning children and successor padding remains present.
7. Bounded class/file/layout/vtable/global/tail/caller support was synchronized at no loss; verify-only resource/RTTI/literal support remained same-or-greater.
8. Every changed ordinary page was scoped-validated; final B001 waited command 14817 verified the complete ordered source union, historical external commands 14831 and 14846 preserved it, and final-read external command 14857 confirms the same union without an aggregate or compiler-body duplicate.

## Supervisor Active Recheck

- The initial duplicate/goal search found B001 alone owning UID0001NM; B004's priority TextEdit work was preserved during the callback, including serialization of the shared ignored-page lane.
- The report did not exist before the report-only phase; this same accepted artifact was updated after implementation rather than rewritten.
- Every ordinary destination was reread and leased only for its immediate edit/validation. The current lease registry has no B001 row.
- Shared pages were rebased against their then-current contents. Current destination hashes below are verification checkpoints, not permission to overwrite later work.
- Direct MCP health, target lookup, byte, decompile, xref, and disassembly checks succeeded against evidence-time database `9b0396a3`; no callback-time binary uncertainty required IDA requery or mutation.

## Inference Research Guidance Check

- Human names were selected only after exact behavior and nearest source-family analogs were compared. The selected names preserve established project API names where downstream formal code already depends on them.
- `GetSpiritIdValue` distinguishes the raw sign-extending `int` helper from the existing `signed char GetSpiritId` API instead of fabricating a second semantic field.
- `HandlePacketEvent`, `HandlePointerOrMouseEvent`, and `OnPaint` follow current EventHandler/Pane contracts and vtable evidence, superseding `PacketMovementRouter`, `MouseHoverHelp`, and generic paint slugs.
- `GetStatusFieldRect`, `DrawNumberGlyphString`, `ApplyLegacyPositionPacket`, `ApplyLegacyMovementStep`, `ApplyLegacyMovementStepAlt`, and `ApplyStatusPayload` are independently supported by exact OldUserStatusPane source analogs and current UserStatusPane behavior.
- Stable public accessors `CopyNameLineA/B`, `GetPercentStatA/B/C`, `GetDisplayValueA/B/C`, and `SetDisplayLineA/B` are retained to avoid breaking current downstream source. Their exact field and type semantics are documented rather than cosmetically renamed.
- Source placement ranks `UserStatusPane.cpp` first because the constructor route, class vtables, singleton, three pane variants, resources, existing emitter chain, and all exact children converge there. A separate raw-helper file or CharacterSummaryRecord file has no supporting ownership route.
- Inference caps remain reflected in `92/93` paint/hover and `91/92` no-route raw-helper scores; no unresolved item blocks formal C++ or the selected route.

## Heuristic / Inference Reanalysis And Validation

- Constructor allocation size and field writes prove a complete size of `0x2ac`; the field sequence naturally follows Pane's `0xf8` base without a separate CharacterSummaryRecord object.
- The constructor's dword write at `+0x27e` is value `0x0000ffff`: spirit and icon become `0xff`, while class and first percentage byte become zero. A later word write clears `+0x282/+0x283`. This rejects four independent signed fields initialized to `-1`.
- Nation is stored and compared as a 16-bit value by payload parsing. Getter `0x005b8620` intentionally zero-extends only the low byte, so its source return remains `unsigned char`; the backing field remains `unsigned short`.
- The raw signed helper at `0x005b86d0` performs sign extension from `+0x27e`. Its distinct return width supports a separate retained source helper rather than treating the bytes as an alternate entry into the seven-byte getter island.
- UID0003AA and UID0003AD each contain a compiler switch table reached only from the function body. Their tails are not padding or independent source data and belong inside the child range.
- The no-xref raw position/movement helpers match retained OldUserStatusPane bodies at the operation, branch, field, and rectangle level. The live router duplicates their work, consistent with MSVC inlining while retaining unused out-of-line definitions.
- EPF payload and paint branches use different asset and packet layouts from legacy mode. That difference is mode behavior, not evidence for a second class or source file.
- `GetStatusFieldRect` has an unused receiver in optimized machine code, causing IDA to infer `__stdcall`; class-local calls, the raw invalidation wrapper, private class state/source analog, and source family support a private member whose receiver optimized away.
- Hover event fields are y at `+0x08`, x at `+0x0c`, matching canonical `PointInRect(y,x,bounds)`. The old generic event-field ordering is rejected.
- The source destructor contains only guarded font-buffer release plus unconditional singleton clear. Vptr restoration, Pane teardown, scalar delete, and adjustor thunks are compiler output caused by the virtual ordinary destructor and multiple facets.
- The exact paint helper calls and resource names resolve the former body blocker. Some original local variable and descriptive private field spellings are irrecoverable, which caps confidence below final audit but does not prevent behavior-identical human source.

## Evidence Standards Used

- Exact raw bytes, SHA256, modeled function boundaries, bounded disassembly, Hex-Rays output, xrefs, data refs, vtable refs, and caller/callee graphs are direct evidence.
- Current ordinary and generated artifacts are read-only report-time snapshots, not binary authority.
- Historical reports are leads only and are accepted only where current binary/docs independently agree.
- Names are strongest when established by current class/file APIs or exact analogs; descriptive private names are marked inferred and scored accordingly.
- Negative searches include direct xrefs, VA/RVA pointer patterns, function starts, data refs, class allocations, vtable ownership, and whole-report duplicate searches.
- Source reconstruction excludes compiler-only code even when its machine bytes are inside a broad aggregate.

## Evidence Checked

- Complete modeled function inventory and every byte gap across `[0x005b83b0,0x005baafe)`.
- Constructor caller `0x004f7d10`/callsite `0x004f837a`; selector construction of UserStatusPane, UserStatusPane2, or OldUserStatusPane by UI mode.
- Vtable data refs at `0x00630c70`, `0x00630c7c`, `0x00630c88`, destructor/scalar-wrapper refs, RTTI, singleton storage, and source file routing.
- Direct callers/callees for constructor, destructor, router, hover, paint, rect, glyph, payload, accessor, and setter bodies.
- Raw starts `0x005b86d0`, `0x005b9d70`, `0x005ba100`, `0x005ba1a0`, `0x005ba320`: bounded instructions, zero modeled-function status where applicable, zero direct xrefs, and zero VA/RVA pointer-pattern matches.
- Internal table refs at `0x005b89b4`, `0x005b9fb4`, `0x005ba30c`, and `0x005ba48c`, each owned by its preceding source body.
- Exact resource strings `9X11FONT.BIN`, `USERSTAT.EPF`, `ITEMINV.PAL`, `USERSTAT.EPD`, `NPAL7.PAL`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, `NPAL5.PAL`, and `BAR.EPD`.
- Exact packet opcodes `0x04`, `0x08`, `0x0b`, `0x26`; flags `0x40`, `0x20`, `0x10`; cursor progression; big-endian reads; field invalidations; inventory-panel activation; TotemFrame invalidation/allocation.
- Current target/class/file/children/layout/vtable/RTTI/global/resource/tail/caller/generated/manual artifacts and their bounded report-time hashes.
- During the initial report-only evidence pass, ordinary edits, leases, validators, and generated refresh were intentionally not performed. During the accepted callback the ordinary edits, leases, scoped validators, and final generated refresh listed later were performed. The supervisor subsequently applied/validated manual coverage under commands 14847-14851. Manual coverage application by B001, IDA mutation, execute/lifecycle actions, moves, and archives remained unperformed by B001.

## Claim And Incorporation Ledger

| Claim ID | Claim | Action | Destination | Verification state | Callback proof |
| --- | --- | --- | --- | --- | --- |
| C1NM-001 | Preserve exact aggregate bytes/hash/range evidence. | incorporate | UID0001NM | applied | Target retains `[0x005b83b0,0x005baafe)`, 10,062-byte SHA256 `6D2120BB...E9723`, full inventory, and negative evidence; current page SHA `FDD5CAC3...00AE`. |
| C1NM-002 | Convert aggregate to `92/94` non-emitting split index. | incorporate | UID0001NM | applied | Header is `92/94`, false, no emitter/position; B001 validator 14817 emitted no aggregate marker, historical commands 14831/14846 retained zero, and final-read external command 14857 retains zero. |
| C1NM-003 | Retain owner UID0000FS; clear emitter/position/formal. | incorporate | UID0001NM | applied | Current header retains owner `0000FS`; emitter/position/formal are blank and Destination 1 matches exactly. |
| C1NM-004 | Set aggregate `Nested:0` and exact fifteen-child inventory. | incorporate | UID0001NM | applied | Target has `Nested:0` and fifteen address-ordered real-UID links; generated hierarchy returns to baseline at UID0001NO. |
| C1NM-005 | Correct constructor behavior, ABI, size, fields, resources, and score `92/94`. | incorporate | UID0003A8 | applied | Constructor page SHA `168E1C9D...A8D3`, validator 14769, exact body/ABI/resource evidence and position 10. |
| C1NM-006 | Rename cleanup body to ordinary destructor and set `92/94`, position 20. | incorporate | UID0003A9 | applied | UID-preserving path is `...UserStatusPaneDestructor.md`, SHA `83FDC3D5...E3E`, validator 14770. |
| C1NM-007 | Exclude vptr/base/scalar/adjustor lowering from destructor source. | reject-invalid | UID0003A9/UID0001NS | excluded-with-reason | Ordinary destructor contains only guarded release/unconditional clear; UID0001NS documents compiler wrappers and generated output emits no compiler body. |
| C1NM-008 | Correct accessor types/fields/invalidation and set `92/94`, position 30. | incorporate | UID0001NN | applied | Accessor page SHA `67121DD8...D220`, validator 14771, exact twelve-method managed block and direct `InvalidateRect`. |
| C1NM-009 | Create signed spirit-value child at `[0x005b86d0,0x005b86d8)`. | incorporate | UID0004T3 | applied | Serial registration issued UID0004T3 under validator 14762; page SHA `60A03F02...7C4`. |
| C1NM-010 | Use `GetSpiritIdValue` and retain no-route evidence at `90/92`, position 40. | incorporate | UID0004T3 | applied | Header/body/name/score/position and zero-xref/zero-pointer evidence are present and exact. |
| C1NM-011 | Correct SetStatusIconId direct invalidation and set `92/94`, position 50. | incorporate | UID0002LP | applied | Setter SHA `A0104C42...C4E8`, validator 14772, exact direct invalidation body. |
| C1NM-012 | Rename/range UID0003AA through owned table tail `[0x005b8700,0x005b8a0c)`. | incorporate | UID0003AA | applied | UID-preserving corrected path/range SHA `B97E0D0A...B722`; final scoped validator 14805. |
| C1NM-013 | Resolve router as `HandlePacketEvent(Event *)`, `92/94`, position 60. | incorporate | UID0003AA | applied | Current metadata and exact managed definition use the selected virtual identity. |
| C1NM-014 | Preserve exact EPF/legacy opcode dispatch and false returns. | incorporate | UID0003AA | applied | Current body/evidence retain EPF opcode 8, legacy 4/8/0x0b/0x26, and false defaults. |
| C1NM-015 | Rename hover body to `HandlePointerOrMouseEvent`, `92/93`, position 70. | incorporate | UID0003AC | applied | Corrected path SHA `781F9328...8A98`; final validator 14806. |
| C1NM-016 | Preserve y/x event ordering, four regions, ids 185/186/187/188, and 5000 ms help. | incorporate | UID0003AC | applied | Exact managed body and behavior/evidence sections preserve all listed values and branch returns. |
| C1NM-017 | Rename paint body to `OnPaint`, `92/93`, position 80. | incorporate | UID0003AE | applied | Corrected page SHA `8EBF42D4...61F`; exact-block repair validator 14816. |
| C1NM-018 | Preserve complete EPF paint assets, fields, geometry, text, and glyph behavior. | incorporate | UID0003AE | applied | Destination 10 now exactly equals the accepted full formal block and retains detailed EPF evidence. |
| C1NM-019 | Preserve complete legacy assets/icons/bars/value/position paint behavior. | incorporate | UID0003AE | applied | Same exact block/evidence preserves the full legacy path without simplification. |
| C1NM-020 | Create invalidation wrapper child `[0x005b9d70,0x005b9dab)`. | incorporate | UID0004T4 | applied | Serial registration issued UID0004T4; current SHA `505BE0F4...DFF2`, final validator 14777. |
| C1NM-021 | Emit `InvalidateStatusFieldRect`, `91/93`, position 90; exclude cookie. | incorporate | UID0004T4 | applied | Exact managed body/metadata are present; cookie is retained only as compiler-exclusion evidence. |
| C1NM-022 | Rename/range UID0003AD through owned table tail `[0x005b9db0,0x005ba017)`. | incorporate | UID0003AD | applied | Corrected path/range SHA `C3AE8AEA...A8CC`, validator 14776. |
| C1NM-023 | Resolve member `GetStatusFieldRect`, `92/94`, position 100. | incorporate | UID0003AD | applied | Header/formal/evidence carry the private member disposition and exact position. |
| C1NM-024 | Preserve EPF default output-untouched quirk and legacy default-zero behavior. | incorporate | UID0003AD | applied | Body and negative-evidence text preserve both distinct defaults without normalization. |
| C1NM-025 | Rename glyph body to `DrawNumberGlyphString`, `92/94`, position 110. | incorporate | UID0003AF | applied | Corrected path SHA `55B9340C...A2B`, validator 14783. |
| C1NM-026 | Preserve 9x11 geometry, skip characters, formula, and x advance. | incorporate | UID0003AF | applied | Exact managed body/evidence preserve source/destination geometry, formula, skips, and advance. |
| C1NM-027 | Create legacy position child `[0x005ba100,0x005ba19c)`. | incorporate | UID0004T5 | applied | Serial registration issued UID0004T5; SHA `C6FCB79E...9229`, final validator 14784. |
| C1NM-028 | Preserve EPF early false and legacy BE x/y update; `91/92`, position 120. | incorporate | UID0004T5 | applied | Exact body/metadata/no-route evidence are present and emitted once. |
| C1NM-029 | Create movement child `[0x005ba1a0,0x005ba31c)`. | incorporate | UID0004T6 | applied | Serial registration issued UID0004T6; SHA `8C2BB5C1...A09E`, validator 14765. |
| C1NM-030 | Preserve exact direction masking, bounds, updates, and field-15 invalidation; `91/92`, position 130. | incorporate | UID0004T6 | applied | Exact body/evidence retain signed gate/mask, direction-4 reject, map clamp, updates, invalidation, and false return. |
| C1NM-031 | Create alternate movement child `[0x005ba320,0x005ba49c)`. | incorporate | UID0004T7 | applied | Serial registration issued UID0004T7; SHA `44B3B3A3...E9D`, validator 14767. |
| C1NM-032 | Preserve identical alternate movement semantics and independent body; `91/92`, position 140. | incorporate | UID0004T7 | applied | Independent managed body/table/no-route evidence are present; it is not aliased to UID0004T6. |
| C1NM-033 | Rename payload body to `ApplyStatusPayload`, `92/94`, position 150. | incorporate | UID0003AB | applied | Corrected path SHA `B1431B77...EFD6`, validator 14785. |
| C1NM-034 | Preserve exact EPF flags/offsets/fields/tail/slot-refresh behavior. | incorporate | UID0003AB | applied | Complete EPF branch and support effects remain in body/evidence at full detail. |
| C1NM-035 | Preserve exact legacy flags/cursor/clamp/Totem/invalidation behavior. | incorporate | UID0003AB | applied | Complete legacy branch, Totem interaction, cursor/clamp, and invalidations remain exact. |
| C1NM-036 | Replace UserStatusPane declaration with exact `0x2ac` layout and complete API. | incorporate | UID0000FS | applied | Class SHA `D2F570D6...733D`, validator 14786; Destination 2 matches exactly. |
| C1NM-037 | Raise class to `92/94`; preserve owner/emitter UID0000P2. | incorporate | UID0000FS | applied | Current class header is `92/94` and retains owner/emitter route 0000P2. |
| C1NM-038 | Preserve stable accessor API names while documenting exact semantics. | incorporate | UID0000FS | applied | Complete class/API and explanatory field semantics retain downstream-compatible names. |
| C1NM-039 | Reject standalone CharacterSummaryRecord declaration/source. | reject-stale | UID0000FS/UID0001WF | excluded-with-reason | Class/layout history explains generated alias rejection; generated file contains zero CharacterSummaryRecord tokens. |
| C1NM-040 | Raise source file to `92/93` with exact order and family ownership. | incorporate | UID0000P2 | applied | File SHA `5AB3BDA7...2D87`, validator 14787, exact source order and complete existing union. |
| C1NM-041 | Preserve unrelated UserStatusPane2/OldUserStatusPane/MenuVariety union. | already-present | UID0000P2 | already-present | Reread/merge retained the full existing family content; generated output still includes those unrelated sections. |
| C1NM-042 | Update layout support to `91/94`, non-reconstructable/non-emitting. | incorporate | UID0001WF | applied | Layout SHA `3269F902...9BC`, validator 14788, false/non-emitting exact tail layout. |
| C1NM-043 | Replace signed nation/reserved and opaque-tail layout assumptions. | historicalize | UID0001WF | applied | Correct 16-bit nation/tail fields are current; superseded signed/reserved/opaque assumptions remain explicitly historical. |
| C1NM-044 | Update vtable slots/virtual identities and covered-by class proof. | incorporate | UID0002YZ | applied | Vtable page SHA `38B05AD7...43FF`, validator 14790; generated route is covered-by comment only. |
| C1NM-045 | Preserve RTTI as verify-only compiler metadata. | already-present | UID0003EC | already-present | UID0003EC was reread unchanged and no RTTI body appears in generated source. |
| C1NM-046 | Raise g_activeUserStatusPane to `92/94` with exact lifecycle/type. | incorporate | UID0000PS | applied | Global SHA `FEBA96E1...F9C6`, validator 14791, exact constructor/destructor lifecycle and type. |
| C1NM-047 | Synchronize singleton storage child and preserve covered-by route. | incorporate | UID0001PE | applied | Storage SHA `98D351B2...C671`, validator 14792, covered-by global definition retained. |
| C1NM-048 | Historicalize generated aliases for `0x0069ae0c`. | historicalize | UID0000PS/UID0001PE | applied | Canonical active singleton is current; prior generated aliases are retained only under superseded history. |
| C1NM-049 | Synchronize source destructor cause in shared tail without emitting wrapper bodies. | incorporate | UID0001NS | applied | Tail SHA `6B71C74A...4464`, validator 14793; ordinary-source cause and compiler exclusions are explicit. |
| C1NM-050 | Preserve UID0001NO body/score and set successor closure `Nested:-4`. | incorporate | UID0001NO | applied | SHA `F2363272...4D37`, validator 14794; body/score unchanged and `Nested:-4` closes hierarchy. |
| C1NM-051 | Set first child UID0003A8 `Nested:+4`; all later children `0`. | incorporate | child headers | applied | Headers implement `+4/0`; generated memory report shows 621-space parent baseline, 625-space children, 621-space UID0001NO closure. |
| C1NM-052 | Add proven internal all-CC spans only. | incorporate | UID0000VN | applied | Ignored page SHA `A5AD04AE...AC7E`, validator 14797; exactly 25 accepted all-CC intervals were added. |
| C1NM-053 | Preserve existing `[0x005baafe,0x005bab00)` successor padding row. | already-present | UID0000VN | already-present | Exact two-byte successor row remains present after no-loss ignored-page merge. |
| C1NM-054 | Keep switch/NOP table tails out of ignored padding. | reject-invalid | UID0000VN | excluded-with-reason | `89b1-8a0c` and `9fb1-a017` remain owned by UID0003AA/UID0003AD and are absent from ignored rows. |
| C1NM-055 | Preserve InitializeMainUiGraph three-variant construction evidence. | already-present | UID0000MZ | already-present | UID0000MZ was reread same-or-greater; no ordinary change or score inflation was required. |
| C1NM-056 | Synchronize TotemFrame invalidation/allocation relationship without ownership transfer. | incorporate | UID0000F4/UID0000SK | applied | Totem class/global SHAs `BA6A9A92...1A9E`/`BD89EB01...8B6A`, validators 14800/14801. |
| C1NM-057 | Synchronize inventory-slot GeneralPurposePanel child-2 activation. | incorporate | UID00005Q/UID0000R0 | applied | Canonical current IDs correct accepted coordination typos; SHAs `EB55B3BA...15987`/`40D8FD9C...C66E`, validators 14803/14804. |
| C1NM-058 | Preserve exact user-status resource inventory and source-use ownership. | incorporate | UID0001RS | already-present | Resource page was reread at same-or-greater exact inventory/source-use detail; no change was needed. |
| C1NM-059 | Preserve no-standalone source for pooled resource literal storage. | already-present | UID0003JC/UID00044W | already-present | Both literal pages were verified unchanged and remain non-standalone support. |
| C1NM-060 | Record latest-observed generated omission baseline command 14758 and historical commands 14732/14749. | incorporate | report/class/file | applied | Historical omission commands are retained; B001 commands 14808/14816/14817, historical external commands 14831/14846, and final-read external command 14857 are separately attributed. |
| C1NM-061 | Require final generated one-definition/source-order assertions. | incorporate | callback proof | applied | B001 command 14817, historical external commands 14831/14846, and final-read external command 14857 each show one class and fifteen ordered UID markers with zero aggregate/empty/temporary-UID/raw-name duplicate. |
| C1NM-062 | Replace stale by-memory target/accessor/setter rows and add exact subtree rows. | incorporate | supervisor coverage handoff | applied | The exact by-memory handoff below uses UID0004T3-T7; supervisor command 14847 applied/validated every listed row once with exit 0/`ok:1`. |
| C1NM-063 | Replace stale class/file/layout/global coverage rows. | incorporate | supervisor coverage handoff | applied | Supervisor commands 14848-14851 applied/validated the exact class/file/layout/global rows once with exit 0/`ok:1`; current hashes are recorded below. |
| C1NM-064 | Keep manual coverage application supervisor-owned. | not-applicable | B001 callback | excluded-with-reason | B001 kept all manual files read only; the supervisor independently applied and validated them under commands 14847-14851. |
| C1NM-065 | Preserve PE and per-child byte hashes in destinations. | incorporate | child evidence | applied | Target and all source pages retain complete PE/range/per-child hashes and instruction evidence. |
| C1NM-066 | Preserve direct caller/callee/vtable/data-ref inventories. | incorporate | target/children/class/file | applied | No-loss target, child, class, and file evidence retains all accepted inventories. |
| C1NM-067 | Preserve raw-helper zero-xref/pointer negative evidence. | incorporate | UID0004T3-T7 | applied | Every raw child records bounded zero-entry/zero-pointer evidence plus analog/inlining rationale. |
| C1NM-068 | Preserve rejected separate-file, CharacterSummaryRecord, and compiler-body alternatives. | historicalize | affected destinations | applied | Rejected alternatives and superseded assumptions remain in explicit historical/negative sections. |
| C1NM-069 | Preserve EPF output-rectangle uninitialized behavior; do not normalize. | reject-invalid | UID0003AD/UID0003AB | excluded-with-reason | Exact default path leaves the EPF output untouched; no invented initialization was introduced. |
| C1NM-070 | Preserve negative direction/count branches; do not harden. | reject-invalid | UID0004T6/UID0004T7 | excluded-with-reason | Both exact formals preserve signed gate/mask and false branches without defensive rewrite. |
| C1NM-071 | Use only validator-issued UIDs for five new children. | incorporate | callback sequencing | applied | Serial validators issued UID0004T3, UID0004T4, UID0004T5, UID0004T6, and UID0004T7 before dependent links. |
| C1NM-072 | Remove every temporary UID placeholder after serial registration. | incorporate | report/all links | applied | Report, ordinary links, formals, generated output, and handoff contain only the five real issued UIDs. |
| C1NM-073 | Scoped-validate each changed ordinary page under short lease. | incorporate | callback validation | applied | All 29 changed ordinary pages have exit-0/ok-1 scoped proof; every lease was released immediately. |
| C1NM-074 | Run final waited UID0001NM refresh and read generated output. | incorporate | callback validation | applied | Final command 14817 at `2026-07-20T00:49:16-04:00` completed generated refresh and exact readback. |
| C1NM-075 | Preserve all unrelated/newer concurrent content by reread/rebase. | incorporate | all destinations | applied | Per-file rereads retained the B004/shared union; verify-only dependencies remained same-or-greater and no unrelated content was removed. |

## Positive Evidence Summary

- All twenty-one modeled functions and all five raw source bodies fit one class/file family with no overlapping successor code.
- Constructor callsite, `0x2ac` allocation, three vtable facets, singleton publication, resource load, and exact field initialization identify the complete class.
- Router/hover/paint vtable refs resolve the virtual names and secondary receiver adjustments.
- Payload, paint, accessors, and external consumers agree on the field map through `+0x2aa`.
- Raw helpers duplicate exact OldUserStatusPane source behavior and are surrounded by all-CC alignment or owned compiler tables.
- Source destructor behavior explains every compiler wrapper without requiring emitted wrapper C++.
- Existing class/file/global routes already converge on `NexusTK/ui/panels/UserStatusPane.cpp`.

## IDA MCP Facts

| Address/range | Direct fact |
| --- | --- |
| `0x005b83b0`, size `0x176` | Constructor; IDA prototype `int __thiscall(int,wchar_t *)`; caller `sub_4F7D10`; calls Pane constructor, LoadDatFileBuffer, wcscpy_s. |
| `0x005b8530`, size `0x7d` | Ordinary destructor body; calls memory manager/free and Pane teardown in lowered output. |
| `0x005b85b0..0x005b86ca` | Two text copies, eight seven-byte getters, two setters. |
| `0x005b86d0..0x005b86d8` | Sign-extending `+0x27e` getter; no xref/pointer route. |
| `0x005b86e0`, size `0x18` | Status-icon setter and inherited bounds invalidation. |
| `0x005b8700`, size `0x2b1` | EventHandler packet virtual; data ref `0x00630c88`; opcodes 4/8/b/26; payload call. |
| `0x005b8a10`, size `0x25b` | Pointer/mouse virtual; data ref `0x00630c7c`; four help regions. |
| `0x005b8c70`, size `0x10fa` | OnPaint; data ref `0x00630c70`; 118 blocks, complexity 54; ten glyph calls. |
| `0x005b9d70..0x005b9dab` | Raw invalidation wrapper; cookie lowering excluded. |
| `0x005b9db0`, size `0x201` | Status rect switch; sole caller raw wrapper; unused receiver causes IDA `__stdcall` artifact. |
| `0x005ba020`, size `0xd1` | Numeric glyph renderer; ten paint callers. |
| `0x005ba100..0x005ba19c` | Raw position packet helper; no route; exact class analog. |
| `0x005ba1a0..0x005ba31c` | Raw movement helper and owned 16-byte table. |
| `0x005ba320..0x005ba49c` | Raw alternate movement helper and owned 16-byte table. |
| `0x005ba4a0`, size `0x65e` | Status payload parser; router caller; 90 blocks, complexity 43. |
| `0x005bab00` | Successor UserStatusPane2 constructor; target does not absorb it. |
| `0x005bff20`, size `0xbe` | Scalar deleting wrapper with vtable refs/adjustors; compiler-only. |

## Function / Child Inventory

| Order | Range | Current applied identity | Score/status |
| ---: | --- | --- | --- |
| index | `[0x005b83b0,0x005baafe)` | UID0001NM UserStatusPane | current `92/94` non-emitting split index; implemented/validated |
| 10 | `[0x005b83b0,0x005b8526)` | UID0003A8 `UserStatusPane::UserStatusPane` | current `92/94`; implemented/validated |
| 20 | `[0x005b8530,0x005b85ad)` | UID0003A9 `UserStatusPane::~UserStatusPane` | current `92/94`; implemented/validated |
| 30 | `[0x005b85b0,0x005b86ca)` | UID0001NN accessor island | current `92/94`; implemented/validated |
| 40 | `[0x005b86d0,0x005b86d8)` | UID0004T3 `GetSpiritIdValue` | current `90/92`; created/validated |
| 50 | `[0x005b86e0,0x005b86f8)` | UID0002LP `SetStatusIconId` | current `92/94`; implemented/validated |
| 60 | `[0x005b8700,0x005b8a0c)` | UID0003AA `HandlePacketEvent` plus owned table | current `92/94`; implemented/validated |
| 70 | `[0x005b8a10,0x005b8c6b)` | UID0003AC `HandlePointerOrMouseEvent` | current `92/93`; implemented/validated |
| 80 | `[0x005b8c70,0x005b9d6a)` | UID0003AE `OnPaint` | current `92/93`; implemented/validated |
| 90 | `[0x005b9d70,0x005b9dab)` | UID0004T4 `InvalidateStatusFieldRect` | current `91/93`; created/validated |
| 100 | `[0x005b9db0,0x005ba017)` | UID0003AD `GetStatusFieldRect` plus owned table | current `92/94`; implemented/validated |
| 110 | `[0x005ba020,0x005ba0f1)` | UID0003AF `DrawNumberGlyphString` | current `92/94`; implemented/validated |
| 120 | `[0x005ba100,0x005ba19c)` | UID0004T5 `ApplyLegacyPositionPacket` | current `91/92`; created/validated |
| 130 | `[0x005ba1a0,0x005ba31c)` | UID0004T6 `ApplyLegacyMovementStep` | current `91/92`; created/validated |
| 140 | `[0x005ba320,0x005ba49c)` | UID0004T7 `ApplyLegacyMovementStepAlt` | current `91/92`; created/validated |
| 150 | `[0x005ba4a0,0x005baafe)` | UID0003AB `ApplyStatusPayload` | current `92/94`; implemented/validated |

Exact body hashes in the same order are: constructor `6805DEF02D989FC36F335C9C7711F67B9E7C9CE4CED33D1619115B06FF67B7CF`; destructor `6FE4F2F7976B5B95CF729DD8BACC7038B19A66D7B59513BAD037ED01283777CD`; accessors `361A48BCE9726A27082633B3DCD6C92A7226DE5C91569ECA8EAB483341F1A5D9`; signed getter `1AD8225E3E55D44D81799574541EF1858BB6460A8970CCD991E80A4E630F1D40`; setter `51B252AF577883926B8CE8E9AEC5B691F627B83B733AA10E2D0EB3D61FCF4222`; router body `9875E5C143D4DFCD73A06F647D8F19FCA3AEB5BC198FDC0F34B099D9BE8D4F0C`, owned range `1007C6701256A3746B9F74CE90BFFD0AD541EC3243E2B4AD1844A441810F7755`; hover `43903A8037F2186B254FFFE778144C36786DC38DA04A0272A212E069022B4781`; paint `4D6B747F23E78E982D036EEEF688422932B3C927B26DDBB9CED05EF5D530A38D`; invalidation `3BEC691C871BDD0E142BBABE15B62719905081BA216BAD1BDBE5AECE698A0CCF`; rect body `C07503682A8A26BBDA6F2D91C4B10734B4CE0B0302A7E2FF2C9249AFD0703336`, owned range `5EF0D3BF0E7A371794F7EADC95047A6E91103B18F256602D24A6513226A3D0BE`; glyph `37BD9A9124BE9947D2391C359BDA8F05782DD2DB84C2C29DE7BCEA56CE6F1504`; position `60D509E04340310E13673B1A5162DFE553F251F6E099F97D8F710824640562BB`; movement `EBA93DE01356B9163FF9A686A61D7CB0CB3E33310EE5A2AD5483892A49BC832F`; alternate movement `54F2A4C769FF383172F9A85D9D0CB83A1519D4B7EC5008305A164F116188B6C1`; payload `35DA6CC5E3FC4FF1925B1C28E73BD2CCE5318D115029ABA2ABD983561ABFBD42`.

## Direct Xref / Caller Inventory

- Constructor has the live `InitializeMainUiGraph` callsite at `0x004f837a`; the same caller chooses UserStatusPane2 or OldUserStatusPane under alternate mode paths.
- Destructor is reached by class destruction and compiler wrappers; the source body owns font-buffer release and singleton clear only.
- Router, hover, and paint are vtable-routed; absence of static callers is expected for virtual dispatch.
- Rect helper has one direct raw-wrapper caller. Glyph helper has ten direct paint callsites.
- Payload helper has one direct router callsite.
- Accessors and setter have live external consumers through `g_activeUserStatusPane`; their stable public names should remain.
- Raw signed/position/movement starts have zero direct xrefs and zero VA/RVA pointer matches. This is recorded negative evidence, not a liveness veto.
- Internal table xrefs are `0x005b8764 -> 0x005b89b4`, `0x005b9dcf -> 0x005b9fb4`, `0x005ba266 -> 0x005ba30c`, and `0x005ba3e6 -> 0x005ba48c`.

## Documentation Evidence And IDA Status

- Historical pre-callback ordinary baselines remain preserved above and in the accepted Gate 1 artifact; they are not current implementation hashes.
- Current target/child/class/file/layout/vtable/global/tail/caller hashes and metrics are enumerated under Changed Files. All seventeen accepted managed blocks compare byte-for-byte equal to their current destination blocks.
- The shared ignored page was reread after B004 priority work, merged without loss, scoped-validated by command 14797, and currently has SHA256 `A5AD04AE4FBAA3FAE1D32A766365EC42EB02180147AB9A8BF3E9235A9B83AC7E`, 1,063,063 bytes/5,192 lines. The accepted 25 all-CC intervals and existing successor row are present; both owned table tails remain absent.
- MCP remained healthy for the final report-only bounded target checks. The callback introduced no binary uncertainty and did not mutate IDA.

## Ranked Ownership Analysis

1. [UID:0000FS] UserStatusPane class: direct constructor/vtable/layout/method/singleton owner; selected canonical owner for every source child.
2. [UID:0000P2] UserStatusPane file: exact source root containing the three status-pane variants and shared source resources; selected emission route through the class.
3. [UID:0001WF] UserStatusPaneSummaryFields: layout support only; rejected as source owner because it has no allocation, constructor, vtable, or independent instance.
4. [UID:0001NS] shared destructor/thunk tail: compiler-family evidence only; it does not own the ordinary UserStatusPane source destructor.
5. TotemFrame, GeneralPurposePanel, resource, MapPane, and configuration pages: dependencies/consumers only, not target owners.

## Source Placement

- Selected: `NexusTK/ui/panels/UserStatusPane.cpp` under [UID:0000P2].
- Declaration owner: [UID:0000FS] UserStatusPane class with `[[CHILDREN]]` before the closing managed block.
- Exact source order: constructor, destructor, accessor island, raw signed getter, status-icon setter, packet virtual, pointer virtual, paint, invalidation wrapper, rect helper, glyph helper, raw position helper, raw movement helper, alternate movement helper, payload parser.
- Raw helpers remain private UserStatusPane members in the same translation unit. They are not generic packet, MapPane, RectBounds, or movement-library functions.
- Runner-up separate `UserStatusPaneHelpers.cpp` is rejected: no independent owner, literals, callers, or file boundary support it.
- CharacterSummaryRecord source placement is rejected; it is a generated alias over this class tail.

## Range / Split / Padding / Reclassification Analysis

- Parent UID0001NM is an index, not a source object; exact children cover every source byte.
- UID0003AA expands to `[0x005b8700,0x005b8a0c)` and UID0003AD expands to `[0x005b9db0,0x005ba017)` because each trailing table is referenced only by that body.
- Five new exact children are required at `86d0-86d8`, `9d70-9dab`, `a100-a19c`, `a1a0-a31c`, and `a320-a49c`.
- Proven internal all-CC spans to add if still absent: `8526-8530`, `85ad-85b0`, `85cc-85d0`, `85ec-85f0`, `85f7-8600`, `8607-8610`, `8617-8620`, `8627-8630`, `8637-8640`, `8647-8650`, `8657-8660`, `8667-8670`, `869a-86a0`, `86ca-86d0`, `86d8-86e0`, `86f8-8700`, `8a0c-8a10`, `8c6b-8c70`, `9d6a-9d70`, `9dab-9db0`, `a017-a020`, `a0f1-a100`, `a19c-a1a0`, `a31c-a320`, and `a49c-a4a0`.
- Exact all-CC hash groups: `8526-8530` is 10 bytes / `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045`; `85ad-85b0` is 3 bytes / `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`; four-byte spans `85cc-85d0`, `85ec-85f0`, `8a0c-8a10`, `a19c-a1a0`, `a31c-a320`, and `a49c-a4a0` each hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`.
- The eight nine-byte accessor gaps `85f7-8600` through `8667-8670` each hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; six-byte spans `869a-86a0`, `86ca-86d0`, and `9d6a-9d70` each hash `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`.
- Eight-byte spans `86d8-86e0` and `86f8-8700` each hash `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; five-byte spans `8c6b-8c70` and `9dab-9db0` each hash `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`; `a017-a020` is 9 bytes / `7CA320A4DC98B1022B7CAF0832812B3D29344F77A2AF04D040A3DA21D323AC4E`; `a0f1-a100` is 15 bytes / `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`.
- Existing successor `[0x005baafe,0x005bab00)` is already documented and remains unchanged.
- The existing successor is 2 bytes, both `0xcc`, SHA256 `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`.
- Table tails `89b1-8a0c` SHA256 `B715811214C28F8E562DC01031F1880F9A862A01937E03E316926E3F920793C8` and `9fb1-a017` SHA256 `819544AB914E2EFA7B9DAE3594068351F130B21A51176281740AF76F8E753F44` are not all-CC and must not be ignored.
- Balanced relative hierarchy: parent `0`; first child UID0003A8 `+4`; every later child `0`; following UID0001NO `-4`.

## Negative Evidence Summary

- No raw helper has an external pointer or direct entry xref; no evidence supports public APIs or a separate helper module.
- No constructor/allocation/vtable exists for CharacterSummaryRecord.
- No evidence supports manual vtable, RTTI, scalar-delete, adjustor, cookie, base-destructor, or switch-table source.
- No evidence supports replacing two movement helper bodies with one alias; both machine bodies and owned tables exist independently.
- No evidence supports canonicalizing EPF rect defaults or movement direction handling.
- No evidence supports treating status payload fields as one packed external record object.
- No target body belongs to UserStatusPane2, OldUserStatusPane, MenuVarietyPane, TotemFrame, GeneralPurposePanel, or MapPane.
- The two bytes at `0x005baafe` are padding; UserStatusPane2 begins at `0x005bab00`.

## IDA Rename / Type / Comment Recommendations

- Rename IDA functions to the source names selected in the inventory, retaining exact start addresses.
- Type constructor as `UserStatusPane *__thiscall UserStatusPane::UserStatusPane(UserStatusPane *, const wchar_t *)` for analysis while source remains an ordinary constructor.
- Type destructor as `void __thiscall UserStatusPane::~UserStatusPane(UserStatusPane *)` and mark wrapper/thunk aliases compiler-only.
- Type virtual handlers as `bool __thiscall (...)(UserStatusPane *, Event *)`; type paint as `void __thiscall`.
- Type nation storage `unsigned short`, spirit `signed char`, icon/class/attributes/slot count `unsigned char`, row values `unsigned int`, coordinates `int`, and tail words `unsigned short`.
- Comment raw-helper no-xref status and exact OldUserStatusPane analog evidence; do not force-create external xrefs.
- Do not mutate IDA in this task. These are recommendations for supervisor/tooling review only.

## First-Draft C++ Recommendation

### Destination 1: UID0001NM aggregate

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: UID0000FS UserStatusPane class

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class UserStatusPane : public Pane
{
public:
    explicit UserStatusPane(const wchar_t *displayName);
    virtual ~UserStatusPane();

    errno_t CopyNameLineA(wchar_t *destination, size_t capacity) const;
    errno_t CopyNameLineB(wchar_t *destination, size_t capacity) const;
    unsigned char GetPercentStatA() const;
    unsigned char GetPercentStatB() const;
    unsigned char GetPercentStatC() const;
    unsigned char GetNationId() const;
    signed char GetSpiritId() const;
    int GetSpiritIdValue() const;
    unsigned int GetDisplayValueA() const;
    unsigned int GetDisplayValueB() const;
    unsigned int GetDisplayValueC() const;
    void SetDisplayLineA(const wchar_t *text);
    void SetDisplayLineB(const wchar_t *text);
    void SetStatusIconId(unsigned char iconId);

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds) const;
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    bool ApplyStatusPayload(const unsigned char *packet);

    unsigned char *m_numberGlyphs;
    wchar_t m_nameLine[64];
    wchar_t m_displayLineA[64];
    wchar_t m_secondaryLine[64];
    unsigned short m_nationId;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_classId;
    unsigned char m_percentStatA;
    unsigned char m_percentStatB;
    unsigned char m_percentStatC;
    unsigned char m_inventorySlotCount;
    unsigned char m_padding285[3];
    unsigned int m_statusRow8PartialValue;
    unsigned int m_statusRow8FullValue;
    unsigned int m_statusRow9PartialValue;
    unsigned int m_statusRow9FullValue;
    unsigned int m_statusRow10Value;
    unsigned int m_statusRow11Value;
    int m_positionX;
    int m_positionY;
    unsigned short m_epfStatusTailWord0;
    unsigned short m_epfStatusTailWord1;
};

extern UserStatusPane *g_activeUserStatusPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3: UID0003A8 constructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserStatusPane::UserStatusPane(const wchar_t *displayName)
    : Pane(0),
      m_numberGlyphs(NULL)
{
    g_activeUserStatusPane = this;

    unsigned int fontSize = 0;
    m_numberGlyphs = static_cast<unsigned char *>(
        LoadDatFileBuffer(L"9X11FONT.BIN", 99, &fontSize));

    wcscpy_s(m_nameLine, 64, displayName);
    if (g_useEpfAssets)
    {
        m_displayLineA[0] = L'\0';
        m_secondaryLine[0] = L'\0';
    }

    m_nationId = 0xffff;
    m_spiritId = -1;
    m_statusIconId = 0xff;
    m_classId = 0;
    m_percentStatA = 0;
    m_percentStatB = 0;
    m_percentStatC = 0;
    m_inventorySlotCount = 52;
    m_statusRow8PartialValue = 0;
    m_statusRow8FullValue = 0;
    m_statusRow9PartialValue = 0;
    m_statusRow9FullValue = 0;
    m_statusRow10Value = 0;
    m_statusRow11Value = 0;
    m_positionX = 0;
    m_positionY = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: UID0003A9 destructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserStatusPane::~UserStatusPane()
{
    if (m_numberGlyphs != NULL)
        m_numberGlyphs = static_cast<unsigned char *>(
            GetMemoryMan()->FreeBufferMemory(m_numberGlyphs));

    g_activeUserStatusPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5: UID0001NN accessors

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
errno_t UserStatusPane::CopyNameLineA(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_nameLine);
}

errno_t UserStatusPane::CopyNameLineB(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_secondaryLine);
}

unsigned char UserStatusPane::GetPercentStatA() const { return m_percentStatA; }
unsigned char UserStatusPane::GetPercentStatB() const { return m_percentStatB; }
unsigned char UserStatusPane::GetPercentStatC() const { return m_percentStatC; }
unsigned char UserStatusPane::GetNationId() const { return static_cast<unsigned char>(m_nationId); }
signed char UserStatusPane::GetSpiritId() const { return m_spiritId; }
unsigned int UserStatusPane::GetDisplayValueA() const { return m_statusRow8FullValue; }
unsigned int UserStatusPane::GetDisplayValueB() const { return m_statusRow9FullValue; }
unsigned int UserStatusPane::GetDisplayValueC() const { return m_statusRow10Value; }

void UserStatusPane::SetDisplayLineA(const wchar_t *text)
{
    wcscpy_s(m_displayLineA, 64, text);
    InvalidateRect(&m_bounds);
}

void UserStatusPane::SetDisplayLineB(const wchar_t *text)
{
    wcscpy_s(m_secondaryLine, 64, text);
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6: UID0004T3 UserStatusPaneGetSpiritIdValue

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int UserStatusPane::GetSpiritIdValue() const
{
    return m_spiritId;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7: UID0002LP setter

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserStatusPane::SetStatusIconId(unsigned char iconId)
{
    m_statusIconId = iconId;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8: UID0003AA packet event

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserStatusPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->m_payload.m_packet.m_data;

    if (g_useEpfAssets)
    {
        if (packet[0] == 0x08)
            return ApplyStatusPayload(packet);
        return false;
    }

    switch (packet[0])
    {
    case 0x04:
        return ApplyLegacyPositionPacket(packet);
    case 0x08:
        return ApplyStatusPayload(packet);
    case 0x0b:
        return ApplyLegacyMovementStep(packet);
    case 0x26:
        return ApplyLegacyMovementStepAlt(packet);
    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9: UID0003AC pointer event

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserStatusPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != kEventRightButtonDown)
        return false;

    if (g_pSimpleHelpPane != NULL)
        delete g_pSimpleHelpPane;

    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;
    RectBounds bounds;
    int stringId = -1;

    if (g_useEpfAssets)
    {
        InitRectBounds(&bounds, 20, 3, 96, 17);
        if (PointInRect(mouseY, mouseX, &bounds))
            stringId = 185;
        else
        {
            InitRectBounds(&bounds, 121, 4, 170, 17);
            if (PointInRect(mouseY, mouseX, &bounds))
                stringId = 186;
            else
            {
                InitRectBounds(&bounds, 0, 26, 102, 40);
                if (PointInRect(mouseY, mouseX, &bounds))
                    stringId = 188;
                else
                {
                    InitRectBounds(&bounds, 106, 26, 170, 40);
                    if (PointInRect(mouseY, mouseX, &bounds))
                        stringId = 187;
                }
            }
        }
    }
    else
    {
        InitRectBounds(&bounds, 59, 3, 131, 15);
        if (PointInRect(mouseY, mouseX, &bounds))
            stringId = 185;
        else
        {
            InitRectBounds(&bounds, 160, 3, 190, 15);
            if (PointInRect(mouseY, mouseX, &bounds))
                stringId = 186;
        }
    }

    if (stringId < 0)
        return false;

    new SimpleHelpPane(g_pLanguageMan->GetLocalizedString(stringId),
                       this, mouseX, mouseY, 5000);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10: UID0003AE paint

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserStatusPane::OnPaint()
{
    RectBounds sourceBounds;
    RectBounds fieldBounds;
    wchar_t text[32];

    if (g_useEpfAssets)
    {
        EPFTileContext background;
        background.Initialize(L"USERSTAT.EPF", 0, L"ITEMINV.PAL");
        RenderTileFrame(&background, &m_bounds);

        GetStatusFieldRect(0, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
        {
            const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_nameLine)) / 2;
            SetTextBackColor(0);
            SetTextColor(0);
            MoveTo(x + 1, fieldBounds.top + 1);
            DrawWideText(m_nameLine);
            SetTextColor(0xffff);
            MoveTo(x, fieldBounds.top);
            DrawWideText(m_nameLine);
        }

        swprintf_s(text, 32, L"%u", static_cast<unsigned int>(m_classId));
        GetStatusFieldRect(4, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
            DrawNumberGlyphString(text, (fieldBounds.left + fieldBounds.right - 10 * wcslen(text)) / 2,
                                  fieldBounds.top, 1);

        GetStatusFieldRect(12, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
        {
            const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_displayLineA)) / 2;
            SetTextBackColor(0);
            SetTextColor(0);
            MoveTo(x + 1, fieldBounds.top + 1);
            DrawWideText(m_displayLineA);
            SetTextColor(0xffff);
            MoveTo(x, fieldBounds.top);
            DrawWideText(m_displayLineA);
        }

        GetStatusFieldRect(13, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
        {
            const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_secondaryLine)) / 2;
            SetTextBackColor(0);
            SetTextColor(0);
            MoveTo(x + 1, fieldBounds.top + 1);
            DrawWideText(m_secondaryLine);
            SetTextColor(0xffff);
            MoveTo(x, fieldBounds.top);
            DrawWideText(m_secondaryLine);
        }
        return;
    }

        EPFTileContext background;
    background.Initialize(L"USERSTAT.EPD", 0, L"NPAL7.PAL");
    RenderTileFrame(&background, &m_bounds);

    GetStatusFieldRect(0, &fieldBounds);
    if (m_exposedRegion.IntersectsRect(&fieldBounds))
    {
        const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_nameLine)) / 2;
        SetTextBackColor(0);
        SetTextColor(0);
        MoveTo(x + 1, fieldBounds.top + 1);
        DrawWideText(m_nameLine);
        SetTextColor(0xffff);
        MoveTo(x, fieldBounds.top);
        DrawWideText(m_nameLine);
    }

    if (m_nationId != 0xffff)
    {
        GetStatusFieldRect(1, &fieldBounds);
        EPFTileContext nation;
        if (nation.Initialize(L"NATION.EPD", m_nationId, L"NPAL7.PAL"))
            RenderTileFrame(&nation, &fieldBounds);
        else
        {
            const wchar_t *nationName = g_pLanguageMan->GetLocalizedString(m_nationId);
            MoveTo((fieldBounds.left + fieldBounds.right - GetTextWidth(nationName)) / 2,
                   fieldBounds.top);
            DrawWideText(nationName);
        }
    }

    if (m_spiritId != -1)
    {
        GetStatusFieldRect(2, &fieldBounds);
        EPFTileContext spirit;
        spirit.Initialize(L"TOTEM.EPD", m_spiritId, L"NPAL7.PAL");
        RenderTileFrame(&spirit, &fieldBounds);
    }

    if (m_statusIconId != 0xff)
    {
        GetStatusFieldRect(3, &fieldBounds);
        EPFTileContext statusIcon;
        statusIcon.Initialize(L"CLASS.EPD",
                              m_statusIconId == 0 ? 4 : m_statusIconId - 1,
                              L"NPAL5.PAL");
        RenderTileFrame(&statusIcon, &fieldBounds);
    }

    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_classId));
    GetStatusFieldRect(4, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 2);

    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_percentStatA));
    GetStatusFieldRect(5, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 1);
    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_percentStatC));
    GetStatusFieldRect(6, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 1);
    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_percentStatB));
    GetStatusFieldRect(7, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 1);

    InitRectBounds(&sourceBounds, 0, 0, 91, 12);
    GetStatusFieldRect(8, &fieldBounds);
    EPFTileContext row8Missing;
    row8Missing.Initialize(L"BAR.EPD", 2, L"NPAL7.PAL");
    RenderTileFrame(&row8Missing, &sourceBounds, &fieldBounds);
    if (m_statusRow8FullValue != 0)
    {
        RectBounds filled = fieldBounds;
        filled.right = filled.left + MulDiv(fieldBounds.right - fieldBounds.left,
                                             m_statusRow8PartialValue,
                                             m_statusRow8FullValue);
        EPFTileContext row8Fill;
        row8Fill.Initialize(L"BAR.EPD", 0, L"NPAL7.PAL");
        RenderTileFrame(&row8Fill, &sourceBounds, &filled);
    }
    swprintf_s(text, 32, L"%10u", m_statusRow8PartialValue);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 0);

    GetStatusFieldRect(9, &fieldBounds);
    EPFTileContext row9Missing;
    row9Missing.Initialize(L"BAR.EPD", 2, L"NPAL7.PAL");
    RenderTileFrame(&row9Missing, &sourceBounds, &fieldBounds);
    if (m_statusRow9FullValue != 0)
    {
        RectBounds filled = fieldBounds;
        filled.right = filled.left + MulDiv(fieldBounds.right - fieldBounds.left,
                                             m_statusRow9PartialValue,
                                             m_statusRow9FullValue);
        EPFTileContext row9Fill;
        row9Fill.Initialize(L"BAR.EPD", 1, L"NPAL7.PAL");
        RenderTileFrame(&row9Fill, &sourceBounds, &filled);
    }
    swprintf_s(text, 32, L"%10u", m_statusRow9PartialValue);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 0);

    swprintf_s(text, 32, L"%10u", m_statusRow10Value);
    GetStatusFieldRect(10, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 0);
    swprintf_s(text, 32, L"%10u", m_statusRow11Value);
    GetStatusFieldRect(11, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 2);
    swprintf_s(text, 32, L"%04u/%04u", m_positionX, m_positionY);
    GetStatusFieldRect(15, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 2);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11: UID0004T4 UserStatusPaneInvalidateStatusFieldRect

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserStatusPane::InvalidateStatusFieldRect(int fieldId)
{
    RectBounds bounds;
    GetStatusFieldRect(fieldId, &bounds);
    InvalidateRect(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12: UID0003AD rectangle helper

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserStatusPane::GetStatusFieldRect(int fieldId, RectBounds *bounds) const
{
    if (g_useEpfAssets)
    {
        switch (fieldId)
        {
        case 0: InitRectBounds(bounds, 20, 3, 96, 17); break;
        case 4: InitRectBounds(bounds, 121, 4, 170, 17); break;
        case 12: InitRectBounds(bounds, 0, 26, 102, 40); break;
        case 13: InitRectBounds(bounds, 106, 26, 170, 40); break;
        default: break;
        }
        return;
    }

    switch (fieldId)
    {
    case 0: InitRectBounds(bounds, 59, 3, 131, 15); break;
    case 1: InitRectBounds(bounds, 1, 49, 56, 94); break;
    case 2: InitRectBounds(bounds, 1, 2, 56, 47); break;
    case 3: InitRectBounds(bounds, 147, 0, 193, 17); break;
    case 4: InitRectBounds(bounds, 160, 3, 190, 15); break;
    case 5: InitRectBounds(bounds, 75, 17, 102, 29); break;
    case 6: InitRectBounds(bounds, 163, 17, 190, 29); break;
    case 7: InitRectBounds(bounds, 120, 17, 147, 29); break;
    case 8: InitRectBounds(bounds, 101, 30, 192, 42); break;
    case 9: InitRectBounds(bounds, 101, 43, 192, 55); break;
    case 10: InitRectBounds(bounds, 101, 56, 192, 68); break;
    case 11: InitRectBounds(bounds, 101, 69, 192, 81); break;
    case 15: InitRectBounds(bounds, 101, 82, 192, 94); break;
    default: InitRectBounds(bounds, 0, 0, 0, 0); break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 13: UID0003AF glyph helper

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserStatusPane::DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow)
{
    RectBounds sourceBounds;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);

    for (const wchar_t *scan = text; *scan != L'\0'; ++scan, x += 9)
    {
        if (*scan == L' ' || *scan == L'/')
            continue;

        RectBounds destinationBounds;
        InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);
        const int glyphIndex = static_cast<int>(*scan) + glyphRow * 10 - 47;
        RenderTileFrame(m_numberGlyphs, glyphIndex,
                        &sourceBounds, &destinationBounds, true);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 14: UID0004T5 UserStatusPaneApplyLegacyPositionPacket

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserStatusPane::ApplyLegacyPositionPacket(const unsigned char *packet)
{
    if (g_useEpfAssets)
        return false;

    const int x = ReadPacketInt16BE(packet + 1);
    const int y = ReadPacketInt16BE(packet + 3);
    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(15);
    }
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 15: UID0004T6 UserStatusPaneApplyLegacyMovementStep

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserStatusPane::ApplyLegacyMovementStep(const unsigned char *packet)
{
    if (g_useEpfAssets)
        return false;

    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;
        direction &= 0x7f;
    }
    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);
    switch (direction)
    {
    case 0: if (--y < movementBounds.top) y = movementBounds.top; break;
    case 1: if (++x >= movementBounds.right) x = movementBounds.right - 1; break;
    case 2: if (++y >= movementBounds.bottom) y = movementBounds.bottom - 1; break;
    case 3: if (--x < movementBounds.left) x = movementBounds.left; break;
    default: break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(15);
    }
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 16: UID0004T7 UserStatusPaneApplyLegacyMovementStepAlt

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)
{
    if (g_useEpfAssets)
        return false;

    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;
        direction &= 0x7f;
    }
    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);
    switch (direction)
    {
    case 0: if (--y < movementBounds.top) y = movementBounds.top; break;
    case 1: if (++x >= movementBounds.right) x = movementBounds.right - 1; break;
    case 2: if (++y >= movementBounds.bottom) y = movementBounds.bottom - 1; break;
    case 3: if (--x < movementBounds.left) x = movementBounds.left; break;
    default: break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(15);
    }
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 17: UID0003AB payload

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserStatusPane::ApplyStatusPayload(const unsigned char *packet)
{
    if (g_useEpfAssets)
    {
        if ((packet[1] & 0x40) == 0)
            return false;

        m_nationId = PacketBufferReadUInt16BE(packet + 2);
        m_spiritId = static_cast<signed char>(packet[4]);

        if (m_classId != packet[6])
        {
            m_classId = packet[6];
            InvalidateStatusFieldRect(4);
        }
        m_statusRow8FullValue = PacketBufferReadUInt32BE(packet + 7);
        m_statusRow9FullValue = PacketBufferReadUInt32BE(packet + 11);

        if (m_percentStatA != packet[15])
        {
            m_percentStatA = packet[15];
            InvalidateStatusFieldRect(5);
        }
        if (m_percentStatB != packet[16])
        {
            m_percentStatB = packet[16];
            InvalidateStatusFieldRect(7);
        }
        if (m_percentStatC != packet[19])
        {
            m_percentStatC = packet[19];
            InvalidateStatusFieldRect(6);
        }

        m_epfStatusTailWord0 = PacketBufferReadUInt16BE(packet + 26);
        m_epfStatusTailWord1 = PacketBufferReadUInt16BE(packet + 28);
        if (m_inventorySlotCount != packet[30])
        {
            m_inventorySlotCount = packet[30];
            g_pGeneralPurposePanel->GetChildPaneByIndex(2)->OnActivate(NULL);
        }
        return false;
    }

    const unsigned char flags = packet[1];
    unsigned char cursor = 2;
    if ((flags & 0x40) != 0)
    {
        const unsigned short nationId = packet[2];
        signed char spiritId = static_cast<signed char>(packet[3]);
        const unsigned char classId = packet[5];
        const unsigned int row8Full = PacketBufferReadUInt32BE(packet + 6);
        const unsigned int row9Full = PacketBufferReadUInt32BE(packet + 10);

        if (m_nationId != nationId)
        {
            m_nationId = nationId;
            InvalidateStatusFieldRect(1);
        }
        if (spiritId < -1) spiritId = -1;
        if (spiritId > 3) spiritId = 3;
        if (m_spiritId != spiritId)
        {
            m_spiritId = spiritId;
            InvalidateStatusFieldRect(2);
            if (g_pTotemFrame != NULL)
                g_pTotemFrame->InvalidateFrame();
            else
                new TotemFrame();
        }
        if (m_classId != classId)
        {
            m_classId = classId;
            InvalidateStatusFieldRect(4);
        }
        if (m_statusRow8FullValue != row8Full)
        {
            m_statusRow8FullValue = row8Full;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9FullValue != row9Full)
        {
            m_statusRow9FullValue = row9Full;
            InvalidateStatusFieldRect(9);
        }

        if (m_percentStatA != packet[14])
        {
            m_percentStatA = packet[14];
            InvalidateStatusFieldRect(5);
        }
        if (m_percentStatB != packet[15])
        {
            m_percentStatB = packet[15];
            InvalidateStatusFieldRect(7);
        }
        if (m_percentStatC != packet[18])
        {
            m_percentStatC = packet[18];
            InvalidateStatusFieldRect(6);
        }
        cursor = 30;
    }

    if ((flags & 0x20) != 0)
    {
        const unsigned int row8Partial = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int row9Partial = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        if (m_statusRow8PartialValue != row8Partial)
        {
            m_statusRow8PartialValue = row8Partial;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9PartialValue != row9Partial)
        {
            m_statusRow9PartialValue = row9Partial;
            InvalidateStatusFieldRect(9);
        }
    }

    if ((flags & 0x10) != 0)
    {
        const unsigned int row10 = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int row11 = PacketBufferReadUInt32BE(packet + cursor);
        if (m_statusRow10Value != row10)
        {
            m_statusRow10Value = row10;
            InvalidateStatusFieldRect(10);
        }
        if (m_statusRow11Value != row11)
        {
            m_statusRow11Value = row11;
            InvalidateStatusFieldRect(11);
        }
    }
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- The accepted fifteen-child split, five serial child registrations, complete class declaration, seventeen destination-specific managed blocks, exact hierarchy deltas, and source order are applied and validated.
- Keep aggregate UID0001NM blank/non-emitting rather than emitting an aggregate marker or duplicate child code.
- Keep all compiler mechanics excluded and retain the raw helper bodies despite their no-entry state.
- Score improvements are backed by the full evidence and exact formals in this report; the implementation is not a metadata-only patch.

## Recommended Target Doc Changes

- UID0001NM is `92/94`, owner UID0000FS, reconstructable false, blank emitter/position/formal, `Nested:0`, with the exact fifteen-child index and complete hashes/ranges/tables/padding/negative evidence/history.
- The former comment-only managed value is replaced by the exact blank Destination 1 block.
- The former "21-function inventory but unresolved" wording is historicalized behind the implemented split and source-ready disposition.
- Preserve target provenance and unrelated historical research; explicitly mark B009/A001 assumptions superseded where corrected.

## Recommended Support Doc Changes

- UID0003A8, UID0003A9, UID0001NN, UID0002LP, UID0003AA, UID0003AC, UID0003AE, UID0003AD, UID0003AF, and UID0003AB now contain the exact bodies, scores, corrected paths/ranges/names, positions, hashes, behavior, callers/callees, negative evidence, and history.
- UID0004T3 through UID0004T7 were created and registered serially before dependent real-UID references were inserted.
- UID0000FS now has the complete declaration/layout/API at `92/94`, with full method inventory/history and preserved emitter/file route.
- UID0000P2 is `92/93` with exact source order, retained UserStatusPane2/OldUserStatusPane union, raw-helper retention, resources/globals, and compiler exclusions.
- UID0001WF is `91/94`, non-reconstructable/non-emitting exact layout support; CharacterSummaryRecord source remains rejected.
- UID0002YZ has exact virtual slots and covered-by-class proof; UID0003EC remains verify-only RTTI.
- UID0000PS/UID0001PE have exact type, constructor publication, destructor clear, consumer aliases, and `92/94` where listed.
- UID0001NS carries ordinary-destructor source cause and compiler-wrapper exclusions only.
- UID0001NO preserves content/score and uses `Nested:-4` to close hierarchy.
- UID0000VN contains only the accepted all-CC additions and preserves all prior/newer ranges.
- UID0000MZ, UID0001RS, UID0003JC, and UID00044W were verified same-or-greater without change. UID0000F4/UID0000SK and canonical UID00005Q/UID0000R0 received the bounded accepted synchronization; the accepted report's UID00005M/UID0000RO spellings are recorded as coordination typos, not current IDs.

## Score And Metadata Recommendation

| Destination | Historical baseline | Current applied | Metadata disposition |
| --- | ---: | ---: | --- |
| UID0001NM | 86/90 | 92/94 | owner 0000FS; false; blank emitter/position/C++; Nested0 |
| UID0003A8 | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position10; Nested+4 |
| UID0003A9 | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position20; Nested0 |
| UID0001NN | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position30; Nested0 |
| UID0004T3 signed getter | absent | 90/92 | owner/emitter 0000FS; true; position40; Nested0 |
| UID0002LP | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position50; Nested0 |
| UID0003AA | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position60; Nested0 |
| UID0003AC | pre-callback page score | 92/93 | owner/emitter 0000FS; true; position70; Nested0 |
| UID0003AE | pre-callback page score | 92/93 | owner/emitter 0000FS; true; position80; Nested0 |
| UID0004T4 invalidator | absent | 91/93 | owner/emitter 0000FS; true; position90; Nested0 |
| UID0003AD | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position100; Nested0 |
| UID0003AF | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position110; Nested0 |
| UID0004T5 position helper | absent | 91/92 | owner/emitter 0000FS; true; position120; Nested0 |
| UID0004T6 movement helper | absent | 91/92 | owner/emitter 0000FS; true; position130; Nested0 |
| UID0004T7 alternate movement | absent | 91/92 | owner/emitter 0000FS; true; position140; Nested0 |
| UID0003AB | pre-callback page score | 92/94 | owner/emitter 0000FS; true; position150; Nested0 |
| UID0000FS | 88/88 | 92/94 | preserve owner/emitter 0000P2 |
| UID0000P2 | 90/87 page body | 92/93 | preserve source path `NexusTK/ui/panels/` |
| UID0001WF | 85-era coverage | 91/94 | owner 0000FS; false; blank emitter/formal |
| UID0000PS/UID0001PE | 91/88-era | 92/94 | global emits definition; storage covered-by global |
| UID0001NO | prior Nested0 | unchanged score/body | Nested is -4 only |

## Open Questions With Attempted Resolution

- Original private field spellings are not recoverable from symbols. Resolved with stable public API names and role-specific private names supported by all readers/writers; confidence caps reflect inference.
- The raw signed helper may have shared the `GetSpiritId` spelling under return-type overloading impossible in C++. Resolved as `GetSpiritIdValue` to preserve its distinct sign-extended int contract without collision.
- Rect helper IDA ABI is `__stdcall`. Resolved as private member: unused receiver optimization plus class-local source analog outweigh the decompiler prototype.
- Raw-helper liveness has no inbound route. Resolved as retained source due exact analogs and optimizer-inlined live copies; no-route remains explicit negative evidence and score cap.
- EPF rect ids `5/6/7` appear unsafe. Resolved by preserving output-untouched binary behavior; no normalization or invented rectangles.
- Paint local helper spellings are inferred. Resolved with existing project resource/tile/text helper APIs and direct behavior; no binary-local standalone helper is invented.
- Whether the source was one or multiple files is resolved to the established one-file route. No contrary boundary or owner evidence exists.
- No blocker remains that prevents the split, score movement, class declaration, or all fifteen child formals.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

At this bounded final read after command 14857, current supervisor-owned manual hashes are by-memory `648C96BC0CF3AC950310399BBB69ADDCF9D955035B314F6C57FF263A6CF9690E` (1,815,581 bytes/4,327 lines), by-class `CF71F86225D5A027627EE50C49236C7C0A1863DD622C6845F1698B2C059C864C` (235,871/623), by-file `22316E877291B68B3D0AA99ECD5CB1C6457E0EBB71B7FEC4E222CE5E1665297B` (134,565/316), by-struct `FEB144165B08A72402ED071C1C359C7A9BCE12A93541B84C2721A1D477805AE0` (57,041/137), by-global `B1D9DE82100DEFA76A964C097A808F0DAC6781CF4D51F6D670000F21B6AC3357` (90,593/213), and by-item `66C86AAFBA920F09B29B5E6C5B1C5E477255362F2A4A2A009402DA8428079EA6` (28,963/87). The exact B001 handoff was applied and scoped-validated by supervisor commands 14847-14851, each with exit 0 and `ok:1`; later current-hash changes are unrelated B003 WorldMap supervisor-owned row updates, while by-struct and by-item remain unchanged and no by-item UserStatus row exists. B001 neither applied nor validated manual coverage. Prior post-application hashes by-memory `C8202C988A6C0AD282B4C43B4D4EBB4F72449EB2F0739F91E2B6431C39DD743E`, by-class `862E9BE235064C33459EC225C96742B03829D18ECB39A53FF599ACCB2657F75B`, by-file `6E32409881C7D5C8D11792F140B775AF022D3A3D01BE808FBD632CF58DFB367F`, by-struct `FEB144165B08A72402ED071C1C359C7A9BCE12A93541B84C2721A1D477805AE0`, and by-global `3F831C9FA2FB5CD22E1DD2796DFA0E73731B115FC03E33EC8D3744B886AB6238` are historical pre-WorldMap snapshots. Pre-application hashes by-memory `B2D90EE83DB9AE8F953FD5B59AD22CA179A627843DBF7059E07DC4EE96C1F17D`, by-class `D71E09E87C26B5BB276C0E27E5B05E23BAF99E72B3DC44AE072A48A681B64730`, by-file `629C9E94D82D9D088387C21EDD3FB36DB12553C6DC1967C662F8AAEFB1FD55E6`, by-struct `3B602846F676F11D8211BF0E95A1F30D64EF7480FB74C5DA4E57502FBC29E87E`, and by-global `CC4B84DE2CF9CA08A16F2AAA2E694ADAF00C5B363CD8767449F504FB2CCD3975` remain historical handoff evidence; still earlier hashes `674D856B...10E4`, `DF1976C5...32B1`, and `25E8C29C...2A44` remain historical snapshots superseded by unrelated supervisor-owned coverage updates.

Current readback proves that all sixteen by-memory rows below occur exactly once at lines 3674-3689 in exact address order, and that the exact class UID0000FS, file UID0000P2, layout UID0001WF, and global UID0000PS rows each occur exactly once at their established placements. The supervisor-applied handoff uses only the real validator-issued UIDs and is preserved verbatim below as durable implemented text:

```text
    - [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) 0x005b83b0-0x005baafe | class method aggregate | UserStatusPane : not_reconstructable : 92% : very-strong : Exact non-emitting fifteen-child UserStatusPane split index with complete source ranges, five retained raw helpers, two owned switch-table tails, balanced hierarchy, compiler exclusions, and source routed solely through exact children under UID0000FS.
    - [UID:0003A8][0x005b83b0-0x005b8526.UserStatusPaneConstructor](by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md) 0x005b83b0-0x005b8526 | constructor | UserStatusPane::UserStatusPane : reconstructable : 92% : very-strong : Exact 0x2ac construction, singleton publication, 9X11FONT.BIN load, EPF text initialization, field defaults, source ABI, and compiler-vptr exclusion.
    - [UID:0003A9][0x005b8530-0x005b85ad.UserStatusPaneDestructor](by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md) 0x005b8530-0x005b85ad | destructor | UserStatusPane::~UserStatusPane : reconstructable : 92% : very-strong : Exact guarded font-buffer release and unconditional singleton clear with base/vptr/scalar/adjustor lowering excluded.
    - [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) 0x005b85b0-0x005b86ca | method cluster | UserStatusPaneSummaryAccessors : reconstructable : 92% : very-strong : Exact two text copies, eight typed getters, two text setters, stable API names, corrected unsigned nation getter, direct bounds invalidation, and complete UserStatusPane field ownership.
    - [UID:0004T3][0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue](by-memory/0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md) 0x005b86d0-0x005b86d8 | method | UserStatusPane::GetSpiritIdValue : reconstructable : 90% : very-strong : Retained sign-extending int getter over m_spiritId with exact bytes, no-entry negative evidence, class adjacency, and distinct source contract.
    - [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) 0x005b86e0-0x005b86f8 | method | UserStatusPane::SetStatusIconId : reconstructable : 92% : very-strong : Exact status-icon write followed by inherited bounds invalidation, live caller, owner/emitter route, and source-ready body.
    - [UID:0003AA][0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent](by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md) 0x005b8700-0x005b8a0c | virtual method | UserStatusPane::HandlePacketEvent : reconstructable : 92% : very-strong : Exact Event packet payload route, EPF opcode-8 gate, legacy opcode 4/8/0x0b/0x26 dispatch, false defaults, source-helper factoring, and owned switch-table tail.
    - [UID:0003AC][0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent](by-memory/0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent.md) 0x005b8a10-0x005b8c6b | virtual method | UserStatusPane::HandlePointerOrMouseEvent : reconstructable : 92% : very-strong : Exact right-button help handling, y/x order, prior help close, EPF/legacy regions, localized ids 185/186/187/188, 5000-ms pane lifetime, and branch returns.
    - [UID:0003AE][0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint](by-memory/0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint.md) 0x005b8c70-0x005b9d6a | virtual method | UserStatusPane::OnPaint : reconstructable : 92% : very-strong : Complete EPF and legacy status HUD paint behavior, exact resources, fields, rects, icons, bars, text, glyph rows, position display, clipping/exposure, and source-ready body.
    - [UID:0004T4][0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect](by-memory/0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect.md) 0x005b9d70-0x005b9dab | method | UserStatusPane::InvalidateStatusFieldRect : reconstructable : 91% : very-strong : Retained private rect-build/invalidate wrapper with exact body, class analog, no-entry evidence, and cookie exclusion.
    - [UID:0003AD][0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect](by-memory/0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect.md) 0x005b9db0-0x005ba017 | method | UserStatusPane::GetStatusFieldRect : reconstructable : 92% : very-strong : Exact EPF and legacy field-id geometry, untouched EPF default, zeroed legacy default, member-source disposition, sole wrapper caller, and owned switch-table tail.
    - [UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString](by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md) 0x005ba020-0x005ba0f1 | method | UserStatusPane::DrawNumberGlyphString : reconstructable : 92% : very-strong : Exact 9x11 source/destination rectangles, digit-row formula, space/slash skip with x advance, ten paint calls, and tile render behavior.
    - [UID:0004T5][0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket](by-memory/0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket.md) 0x005ba100-0x005ba19c | method | UserStatusPane::ApplyLegacyPositionPacket : reconstructable : 91% : very-strong : Retained EPF early-false and legacy signed big-endian x/y update with field-15 invalidation, exact bytes, analog, and no-entry evidence.
    - [UID:0004T6][0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep](by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md) 0x005ba1a0-0x005ba31c | method | UserStatusPane::ApplyLegacyMovementStep : reconstructable : 91% : very-strong : Retained EPF early-false, signed direction gate/mask, direction-4 rejection, map-bound clamping, x/y update, field-15 invalidation, owned table, and no-entry evidence.
    - [UID:0004T7][0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt](by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md) 0x005ba320-0x005ba49c | method | UserStatusPane::ApplyLegacyMovementStepAlt : reconstructable : 91% : very-strong : Independent retained alternate movement body with exact matching direction/bounds/update behavior, owned table, exact bytes, and no-entry evidence.
    - [UID:0003AB][0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload](by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md) 0x005ba4a0-0x005baafe | method | UserStatusPane::ApplyStatusPayload : reconstructable : 92% : very-strong : Complete EPF/legacy flags, cursor, endian reads, nation/spirit/class/attribute/row/tail/slot updates, TotemFrame behavior, exact invalidations, child-2 activation, and false return.
```

The exact supervisor-applied class/file/layout/global rows are preserved verbatim below in their established alphabetical positions:

```text
- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) : reconstructable : 92% : very-strong : Complete 0x2ac Pane-derived UserStatusPane declaration with exact constructor/destructor, stable typed accessor API, three virtuals, seven private helpers, corrected 16-bit nation/signed spirit/status/class/attribute fields, exact row/coordinate/tail layout, singleton extern, fifteen ordered children, source-ready bodies, and compiler/alias exclusions.
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/UserStatusPane.cpp source root with complete UserStatusPane declaration and fifteen ordered source bodies, five retained no-entry helpers, exact EPF/legacy packet/paint behavior, resources/globals/Totem/inventory interactions, CharacterSummaryRecord rejection, and preserved UserStatusPane2/OldUserStatusPane family union.
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) : ignored : 91% : very-strong : Non-emitting exact UserStatusPane +0xfc..+0x2ab layout support with 16-bit nation, signed spirit, icon/class/three attributes, slot count, naturally aligned row values, x/y, tail words, complete 0x2ac size, and standalone CharacterSummaryRecord rejection; class UID0000FS owns the declaration.
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) : reconstructable : 92% : very-strong : UserStatusPane singleton definition with exact zero storage, constructor publication, ordinary-destructor unconditional clear, 67-xref consumer family, corrected type/aliases, and UserStatusPane.cpp owner/emitter route.
```

No by-item row is affected. `by-memory/-ignored.md` is an ordinary support page, not a manual coverage row replacement; its exact interval additions remain validator-generated coverage side effects after ordinary validation.

## Follow-Up Actions

- B001's accepted callback is complete; external supervisor review may audit this exact current report against the implemented ordinary/generated state.
- Serial registration is complete: the five real UIDs are UID0004T3, UID0004T4, UID0004T5, UID0004T6, and UID0004T7, and no temporary UID token remains.
- A-agent actions: none.
- Manual coverage application and validation are complete as external supervisor actions under commands 14847-14851; at the final read after unrelated B003 WorldMap row updates, every exact B001 handoff row remains present once and unchanged. B001 did not apply, validate, or modify those rows.
- Report validation, execution, count, path transition, move, and archive state are external supervisor/validator-owned and are neither asserted nor performed by this artifact.

## Confidence

- Target disposition/ranges/bytes/child count: very strong (`94`).
- Constructor/destructor/accessor/router/rect/glyph/payload behavior: very strong (`94`).
- Hover/paint source spellings and local presentation API: strong (`93`) because private/local original names are inferred despite exact behavior.
- No-route raw helper source retention: strong (`92`) because direct route is negative but exact analog/inlining/source-family evidence is convergent.
- Class/file ownership and source placement: very strong (`93-94`).
- No rare unresolved blocker prevents callback-ready C++ or score improvement.

## Validator Results

- The initial report-only phase ran no validator. The accepted callback scoped-validated every changed ordinary page under its immediate lease, released each lease, and then ran the authorized waited target refresh.
- All abbreviated times in the table below are exact `2026-07-20T<time>-04:00` timestamps.

| Destination | Validator command(s) | Timestamp(s), exit/ok | Result / side effects |
| --- | --- | --- | --- |
| UID0004T3 new child | 14762 | 2026-07-20T00:11:39-04:00, 0/1 | Registered real UID0004T3; generated deferred. |
| UID0004T4 new child | 14763, 14777 | 00:12:26, 00:27:31, 0/1 each | Registered UID0004T4; initial forward UID0003AD reference resolved on final pass. |
| UID0004T5 new child | 14764, 14784 | 00:13:22, 00:28:38, 0/1 each | Registered UID0004T5; initial forward UID0003AA reference resolved on final pass. |
| UID0004T6 new child | 14765 | 00:14:13, 0/1 | Registered real UID0004T6; generated deferred. |
| UID0004T7 new child | 14767 | 00:15:03, 0/1 | Registered real UID0004T7; generated deferred. |
| UID0001NM target | 14768, 14817 | 00:18:27, 00:49:16, 0/1 each | Initial split validation preceded dependent renames; final waited refresh completed and resolved the full graph. |
| UID0003A8 constructor | 14769 | 00:20:18, 0/1 | Scoped validation passed; generated deferred. |
| UID0003A9 destructor rename | 14770 | 00:21:17, 0/1 | UID-preserving rename/path update passed. |
| UID0001NN accessors | 14771 | 00:22:22, 0/1 | Scoped validation passed. |
| UID0002LP setter | 14772 | 00:23:10, 0/1 | Scoped validation passed. |
| UID0003AA router rename/range | 14773, 14805 | 00:24:07, 00:41:18, 0/1 each | UID-preserving rename/range passed; initial forward UID0003AB reference resolved. |
| UID0003AC pointer-event rename | 14774, 14806 | 00:24:57, 00:41:37, 0/1 each | UID-preserving rename passed; initial forward UID0003AD reference resolved. |
| UID0003AE OnPaint rename/body | 14775, 14807, 14816 | 00:26:20, 00:41:59, 00:48:47, 0/1 each | Rename and forward references passed; 14816 validated exact accepted formal indentation. |
| UID0003AD rect rename/range | 14776 | 00:27:14, 0/1 | UID-preserving rename/range and table ownership passed. |
| UID0003AF glyph rename | 14783 | 00:28:23, 0/1 | UID-preserving rename passed. |
| UID0003AB payload rename | 14785 | 00:29:54, 0/1 | UID-preserving rename passed. |
| UID0000FS class | 14786 | 00:31:05, 0/1 | Complete class/formal/children validation passed. |
| UID0000P2 file | 14787 | 00:31:45, 0/1 | Full no-loss source-family union validation passed. |
| UID0001WF layout | 14788 | 00:32:55, 0/1 | Exact non-emitting layout support passed. |
| UID0002YZ vtable | 14790 | 00:33:43, 0/1 | Virtual identities/covered-by proof passed. |
| UID0000PS global | 14791 | 00:34:22, 0/1 | Lifecycle/type synchronization passed. |
| UID0001PE storage | 14792 | 00:35:07, 0/1 | Storage/covered-by synchronization passed. |
| UID0001NS compiler tail | 14793 | 00:35:44, 0/1 | Source cause/compiler exclusions passed. |
| UID0001NO successor | 14794 | 00:36:17, 0/1 | `Nested:-4` closure passed without body/score change. |
| UID0000VN ignored page | 14797 | 00:37:34, 0/1 | Exact all-CC additions passed; 251 unrelated pre-existing missing-reference warnings were preserved. |
| TotemFrame class/global | 14800, 14801 | 00:38:57, 00:39:30, 0/1 each | Bounded invalidation/allocation synchronization passed. |
| GeneralPurposePanel class/global | 14803, 14804 | 00:40:15, 00:40:46, 0/1 each | Bounded child-2 activation synchronization passed under canonical UIDs 00005Q/0000R0. |

- Final waited command `000000014817`, timestamp `2026-07-20T00:49:16-04:00`, exited 0 with `ok:1` and `generated_refresh: completed`. Validator side effects were registry rebuild `5116` nodes/`4112` edges, metadata refresh `279`, one projected stats refresh, one unrelated validator-owned UID0000P0 `UserLookPane.cpp` update, and pre-existing warnings `autogen_children_fallback_insert:13`, `autogen_children_marker_missing:85`, `autogen_emitter_has_no_code:142`, plus missing registered old UID0003RM UserLookPane path. Later external deferred command 14828 superseded only that unrelated UserLookPane generated header. No ordinary failure remained.
- At this final read, `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` is external command 14857, refreshed `2026-07-20T02:14:47-04:00`, SHA256 `73063CC95402E5641D0C085A846BE037B4A68EB27F4241959B1812DD107B238F`, 39,093 bytes/1,155 lines. External command 14846, refreshed `2026-07-20T01:45:47-04:00`, SHA256 `60340C7DE6DB11336223B70D060EA4F3F9BB056A719F957674D72C39AB913789`, 39,093 bytes/1,155 lines, is the exact historical implementation checkpoint; external command 14831/SHA `7239A048...329` is earlier historical evidence. B001's final waited callback proof is historical command 14817/SHA `BF601859...B7D`; command 14808 was the earlier complete callback refresh, command 14814 an intervening external header refresh, and command 14816 the final OnPaint scoped validation.
- Final-read command-14857 generated assertions: exactly one complete UserStatusPane class; UID markers UID0003A8, UID0003A9, UID0001NN, UID0004T3, UID0002LP, UID0003AA, UID0003AC, UID0003AE, UID0004T4, UID0003AD, UID0003AF, UID0004T5, UID0004T6, UID0004T7, UID0003AB each occur once and in that order; zero UID0001NM markers; zero Empty Emitter Marker, CharacterSummaryRecord, `sub_*`, or temporary UID tokens; no RTTI/cookie/scalar/adjustor implementation. Six case-insensitive vtable tokens occur only in three covered-by documentation comment pairs.
- Supervisor coverage validators were external post-callback actions: command 14847 by-memory, 14848 by-class, 14849 by-file, 14850 by-type/by-struct, and 14851 by-global each exited 0 with `ok:1`. At this final read the exact B001 rows still occur once and match the preserved handoff; subsequent current manual hash drift is unrelated B003 WorldMap supervisor-owned content. B001 did not run any of those commands.
- Generated hierarchy proof: UID0001NM uses 621 leading spaces, all children use 625 after UID0003A8's `+4`, and following UID0001NO returns to 621 after UID0004T7/UID0003AB, proving balanced closure.
- All 17 report managed blocks compare byte-for-byte equal to their current ordinary destination blocks.

## Changed Files

- Current ordinary callback inventory:

| Current path | SHA256 | Bytes / lines |
| --- | --- | ---: |
| `by-memory/0x005b83b0-0x005baafe.UserStatusPane.md` | `FDD5CAC37B1DA542174B6AF1A48009F75FB2E2A03B08378A5EB781927B3800AE` | 22,358 / 171 |
| `by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md` | `168E1C9D81FC70BB1DE2D4DDE5B19BAB1D67A361C602CC8254522A0237B7A8D3` | 5,465 / 90 |
| `by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md` | `83FDC3D5AB71F42C970E627513B773D02EDE1ADD6480D01193B629D6A5544E3E` | 4,341 / 61 |
| `by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md` | `67121DD8164D41ABAB49702078E1A5DEC52012F6183C5D0D38EED5DC5205D220` | 22,501 / 209 |
| `by-memory/0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md` | `60A03F02273D9F3B22AFE86F44742254B153358AF0FEC39D605CB5E3284167C4` | 5,683 / 72 |
| `by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md` | `A0104C422DA553CD1B96E61115711E131C571AE27F3C1EA5477DA6CFC5B6C4E8` | 8,025 / 97 |
| `by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md` | `B97E0D0AA36B9B61BCF36330A99C985E397C4B67299757425A14709A1DDDB722` | 5,493 / 84 |
| `by-memory/0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent.md` | `781F93280099F609C3152E4CBE19B0B1CFE2A78508A7464DF42C32AC86DA8A98` | 5,671 / 112 |
| `by-memory/0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint.md` | `8EBF42D49E101F7E0C0581876D413F1A1DE52D234572E302742C329B71F6561F` | 11,154 / 224 |
| `by-memory/0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect.md` | `505BE0F46E193D9DEDB0C8C93F63EA283505AC19701A307024803BB2FBF5DFF2` | 5,013 / 72 |
| `by-memory/0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect.md` | `C3AE8AEA4CDD9411A241E212F1208A5BB7CC2CA76AF1ECA8654452C40FFFA8CC` | 5,326 / 87 |
| `by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md` | `55B9340C1E589EA758E58DD9C67B331BB0A3504167EE6829352378997F04BA2B` | 4,501 / 71 |
| `by-memory/0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket.md` | `C6FCB79EA66D9E07FA2387DD3AEE5E68F575AA17F58A286FF948531CF3319229` | 5,161 / 83 |
| `by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md` | `8C2BB5C19EB98824D2BC90AA6A5EE6A2765F6F433AC64D950B8D3D77D2ECA09E` | 6,158 / 110 |
| `by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md` | `44B3B3A3C24159520E3B942001F692B214B7D3D18770624229C328D85F818E9D` | 5,886 / 104 |
| `by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md` | `B1431B770605EEED0A330CE245FB1E061E15284E722336F42E7F813F4A4EEFD6` | 9,216 / 199 |
| `by-class/UserStatusPane.md` | `D2F570D66CBFFF9739A649411BF283E4F9109912F1989A564060AF265FB0733D` | 17,949 / 188 |
| `by-file/UserStatusPane.md` | `5AB3BDA764DE724E20F972DB77EF90DBB2CED65BBA277E5EBB73F099E5612D87` | 23,093 / 161 |
| `by-type/by-struct/UserStatusPaneSummaryFields.md` | `3269F90245E1671835FD0D0B5163D71589241E645623D032D1EDB86F726A99BC` | 13,089 / 110 |
| `by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md` | `38B05AD743503F39A28EE4C6F6EAC9B66D1C891E82026F3AC1D9DCCE9B7443FF` | 5,503 / 68 |
| `by-global/g_activeUserStatusPane.md` | `FEBA96E1E4FB032ABD418BD597460BD3C2DE54A2309D3F9FB2C4710BF09FF9C6` | 10,198 / 89 |
| `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md` | `98D351B2EB95E94F10449662259AAB5204FB06885B21B977E31FE17FAC8CC671` | 11,936 / 116 |
| `by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md` | `6B71C74AEF1CD1797A43105840ECDD75BF9645FDE17A08AEB2EFADACAB124464` | 16,726 / 134 |
| `by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md` | `F2363272995ACCB6B62F533C639FB2F12DC07C95DE3B89ABD6B2DC8E5ECB4D37` | 15,684 / 118 |
| `by-memory/-ignored.md` | `A5AD04AE4FBAA3FAE1D32A766365EC42EB02180147AB9A8BF3E9235A9B83AC7E` | 1,063,063 / 5,192 |
| `by-class/TotemFrame.md` | `BA6A9A92A35AB7A016ECA4DED93B422C4C051D2D027605B3547AAF3244E51A9E` | 9,847 / 99 |
| `by-global/g_pTotemFrame.md` | `BD89EB01A04B2AB7AE07FB3DCA5DF1A20168CC2EF66E036E0EA744587D5F8B6A` | 7,121 / 73 |
| `by-class/GeneralPurposePanel.md` | `EB55B3BAF33C3DE4699D6292289750C55E73C19DDD55B5176DA2F5EF4E215987` | 13,334 / 126 |
| `by-global/g_pGeneralPurposePanel.md` | `40D8FD9C67A1BF47869F961F061DBCCC41B7A04EA2BAD0C7AE932F780B47C66E` | 6,433 / 56 |

- Validator-aware UID-preserving renames superseded the old UID0003A9 CleanupBody, UID0003AA PacketMovementRouter, UID0003AC MouseHoverHelp, UID0003AE Paint, UID0003AD StatusRectLookup, UID0003AF GlyphTextDraw, and UID0003AB StatusPayloadApply paths; current paths are listed above.
- This same report is the only file edited by B001 during this report-only repair. Validator-owned side effects include historical B001 command-14817 `UserStatusPane.cpp`, historical external commands 14831/14846 generated metadata, final-read external command-14857 generated/tracker metadata, supervisor commands 14847-14851 UserStatus manual coverage application, later unrelated B003 WorldMap coverage/lifecycle updates, registry/stats refreshes, and the unrelated UserLookPane update noted above; none was edited manually by B001 during this repair.
- Final-read tracker/manual snapshots were read only. Tracker command 14857/SHA256 `63DED0512383825D29D170252D72040A97DA693D736AD2697AEF8260A6199DEF`, 1,517,511 bytes/6,158 lines, records UID0001NM at `92/94`, reconstructable false, zero direct reports, and the current path. All 29 ordinary hashes in the table above still match 29/29, and all 17 ordinary managed blocks still match the accepted report blocks exactly.
- Manual coverage, generated files, tracker, audit, supervisor, validator state, lifecycle, archive, goal, and IDA were not manually edited by B001.

## Implementation Tracking Checklist

### Initial report-only research

- [x] Supervisor Gate 1 accepted exact SHA `DAAF4A8F21BC063EA674B3502132CBCD0FC603D8DEC3A6E5E2C61A7A9BBBF1DB`.
- [x] Re-read every destination immediately before its callback edit.
- [x] Confirmed current shared hashes/rows and preserved newer concurrent content, including B004 priority work.
- [x] No callback-time binary uncertainty required an MCP recheck; report-only MCP evidence remains complete and no IDA mutation occurred.
- [x] Kept manual coverage files read-only as B001, synchronized the exact handoff text, confirmed the supervisor applied/validated it under commands 14847-14851, and reconfirmed every row unchanged after unrelated B003 WorldMap updates.

### Implementation callback

- [x] Created/registered `0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md` as UID0004T3.
- [x] Created/registered `0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect.md` as UID0004T4.
- [x] Created/registered `0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket.md` as UID0004T5.
- [x] Created/registered `0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md` as UID0004T6.
- [x] Created/registered `0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md` as UID0004T7.
- [x] Replaced every temporary UID token with the five real UIDs in report, ordinary links, and handoff.
- [x] Updated UID0001NM metadata, blank formal, exact fifteen-child index, and complete evidence/history.
- [x] Applied UID0003A8 constructor body, score, position, first-child `Nested:+4`, evidence, and history.
- [x] Validator-aware renamed UID0003A9 and applied ordinary destructor body/evidence/score/position.
- [x] Applied UID0001NN corrected types, fields, stable APIs, direct invalidation, score, and position.
- [x] Applied UID0004T3 body, no-route evidence, score, owner/emitter, position, and `Nested:0`.
- [x] Applied UID0002LP exact setter body/direct invalidation/evidence/score/position.
- [x] Validator-aware renamed/ranged UID0003AA through `0x005b8a0c` and applied exact packet virtual/table evidence.
- [x] Validator-aware renamed UID0003AC and applied exact pointer-event behavior and score.
- [x] Validator-aware renamed UID0003AE and applied full paint body/resources/fields/negative evidence and score.
- [x] Applied UID0004T4 body, cookie exclusion, score, and position.
- [x] Validator-aware renamed/ranged UID0003AD through `0x005ba017` and applied exact rect body/quirk.
- [x] Validator-aware renamed UID0003AF and applied exact glyph body and score.
- [x] Applied UID0004T5 body, EPF/legacy behavior, no-route evidence, score, and position.
- [x] Applied UID0004T6 body, table/bounds/mask/negative evidence, score, and position.
- [x] Applied UID0004T7 independent body/table/evidence, score, and position.
- [x] Validator-aware renamed UID0003AB and applied complete payload body/behavior/evidence/score/position.
- [x] Replaced UID0000FS class declaration and incorporated complete layout/method/source/history evidence.
- [x] Updated UID0000P2 file source order/route/full family union at no loss.
- [x] Updated UID0001WF exact non-emitting layout and historicalized alias assumptions.
- [x] Updated UID0002YZ virtual identities/covered-by proof and verified UID0003EC remains correct.
- [x] Updated UID0000PS and UID0001PE lifecycle/type/alias evidence without duplicate definition.
- [x] Updated UID0001NS source-destructor cause/compiler exclusions without wrapper source.
- [x] Set following UID0001NO `Nested:-4` and preserved unrelated content.
- [x] Added only accepted all-CC internal spans to UID0000VN and preserved successor padding/table exclusions.
- [x] Synchronized bounded TotemFrame/GeneralPurposePanel facts; verified UID0000MZ/resource/literal support same-or-greater.
- [x] Scoped-validated all 29 changed ordinary pages under one-file leases and released each immediately.
- [x] Confirmed all five new UIDs exist and parent/class/file/manual-handoff links use them.
- [x] Ran final authorized UID0001NM validation with `--wait-generated` as command 14817.
- [x] Verified generated one class plus fifteen ordered child markers and exact hierarchy closure.
- [x] Verified no aggregate/Empty Emitter/CharacterSummaryRecord/RTTI/cookie/base/scalar/adjustor/table body duplicate; vtable text is covered-by comments only.
- [x] Recorded command IDs/timestamps/exits/ok/warnings/side effects and generated hashes/counts.
- [x] Updated all C1NM-001..075 states to legal terminal values with claim-specific proof.
- [x] Updated Changed Files with exact current hashes and distinguished validator-owned side effects.
- [x] Checked each callback row only after its independent proof became true.
- [x] Confirmed manual coverage remained unedited by B001, the handoff text uses the five real UIDs, supervisor commands 14847-14851 applied/validated every exact row once, and the final-read current union preserves those rows exactly.
- [x] Confirmed zero B001 leases and no report lifecycle/execute/move/archive action.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000014858","destination_path":"executed-b-agent-research/B001/0001NM-UserStatusPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001NM-UserStatusPane-source-quality.md","timestamp":"2026-07-20T02:33:36-04:00","uid":"0001NM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
