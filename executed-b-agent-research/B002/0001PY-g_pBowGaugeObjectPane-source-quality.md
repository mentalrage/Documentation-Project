** TARGET-REPORT-UID:0001PY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0001PY g_pBowGaugeObjectPane Source-Quality Report

## Finalized Report / Current Recommendation

UID0001PY is the exact four-byte physical backing slot at `[0x0069ba24,0x0069ba28)`, but it is not an independent source emitter. Fresh PE arithmetic and live IDA MCP show that the address lies in the loader-zeroed virtual tail of `.data`, has four zero bytes at load time, and is the storage occupied by the source-level singleton pointer `BowGaugeObjectPane *g_pBowGaugeObjectPane`. The historical `ff ff ff ff` initializer is disproved for the current executable and is retained only as an old raw-offset/tooling interpretation.

The semantic global page UID0000QA now carries the sole external definition `BowGaugeObjectPane *g_pBowGaugeObjectPane = 0;` at file position 0 under UID0000HU. UID0001PY retains semantic `CANONICAL_OWNER:0000QA`, is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS`, position, and formal C++, uses `Nested:0`, and scores `92/94`. This separates physical storage documentation from source emission without losing the address, PE mapping, zero initialization, 13-reference lifecycle, or neighboring-range evidence.

The BowGauge family is now source-ready rather than a deferred blank-emitter family. UID000011 is a complete `Pane` plus `Singleton<BowGaugeObjectPane>` declaration of exact size `0xfc`; validator-issued UID0004VN, UID0004VO, UID0004VP, and UID0004VQ carry the constructor, `StartAnimation`, `OnPaint`, and `OnTimer`; UID0001DC and UID0004SJ retain accepted bodies at positions 40 and 60; validator-allocated UID0004VR carries the non-emitting compiler scalar page; UID000352 and UID0002YQ carry marker-only coverage. Historical UID000380 on the BowGauge scalar page was an invalid duplicate and now remains canonical only to the unrelated JsonCpp `OurReader` prelude. UID00007B has the bounded BowGauge friendship required for direct `g_pUserPane->m_nameVisible` access. UID0001DB and UID0001DL remain non-emitting inventories.

B002's accepted implementation callback and duplicate-UID repair are complete. All 15 formal blocks are byte-equal to their destinations, prose Destination 16 is applied, read-only Destination 17 is unchanged at the accepted hashes, C01-C40 are terminal, all callback obligations are checked, final waited generation passed, UID0004VR and canonical JsonCpp UID000380 have independent restored validator mappings, and B002 holds zero ordinary leases. The sixteen manual coverage actions remain exact and supervisor-owned; report execution and lifecycle remain external.

## Supporting Research

### Current project evidence opened

- Target UID0001PY, semantic global UID0000QA, class UID000011, file UID0000HU, broad method aggregate UID0001DB, destructor aggregate UID0001DL, exact UID0001DC/UID0004SJ/UID0004VR children, UID000352 vtable data, UID0002YQ resource data, UID00007B LivingObjectPane, canonical JsonCpp UID000380, and the current UserPane class/file/aggregate were reread from the canonical tree.
- Evidence-time generated `auto-generated/NexusTK/ui/panels/BowGaugeObjectPane.cpp` initially contained one incomplete Pane-only class, two methods, and three empty-emitter markers. That command-16132 snapshot is historical routing evidence. Final waited command `000000016209` emits the complete one-definition/class/six-method/marker union documented under Validator Results.
- Current manual `by-memory`, `by-global`, `by-class`, and `by-file` coverage rows were compared read-only. Sixteen exact no-loss supervisor-owned actions are supplied below; no coverage file was edited.
- The executable PE headers and current executable bytes were checked independently of IDA. The executable SHA256 was `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` at the evidence pass.

### Historical and concurrent report search

Exact search terms were `UID0001PY`, `0001PY`, `0x0069ba24`, `0x0069ba28`, `g_pBowGaugeObjectPane`, `BowGaugeObjectPane`, `dword_69BA24`, `unk_69BA24`, `0x00538bc0`, `0x00538c10`, `0x00538c40`, `0x00538c50`, `0x00538d00`, `0x00538d10`, `0x0053cfe0`, `UserPane`, `Singleton<BowGaugeObjectPane>`, `BGAUGE.EPF`, and `BGAUGE.pal`.

- Central executed root `executed-b-agent-research/B001` through `B015`: no direct UID0001PY report exists. Relevant opened leads were `B003/0001DC-BowGaugeObjectPaneRemovePendingTimers-source-quality.md` SHA256 `CF2197421773F62B1B38D4641CC096FE83B90537444CE6A465275FC4ACF6FE0E`, `B005/000352-BowGaugeObjectPaneVtableData-source-quality.md` SHA256 `714B8C5C7F4CAC703D251BC942294709B3CFEA2AF244981E44C37C5ACF9417CF`, `B004/0001KL-UserPane-source-quality.md` SHA256 `477BC1F399BA263B0C28C7E77E65F1B3D20BADE92DDCF85195FFF101E1D5952F`, `B003/000169-CompositePixels16-source-quality.md` SHA256 `47674C67235BE4C07B0FB3EA09244019BC8D57ED601B95D01E967EFBE91375F4`, `B009/0000HJ-AttachedObjectPane-empty-emitter-family-source-quality.md` SHA256 `2460A17316FF5C9BE8285EAD5EA265D4A3CF48930B8CE64C7B1E8F518961FE4C`, `B005/0000YZ-BalloonObjectPane-source-quality.md` SHA256 `7BCCDA1A1ABD618D4823709DB3C64FB9888B5741F46225FD0EA3448E3196CDD8`, `B008/0000YZ-BalloonObjectPane-source-quality.md` SHA256 `CA655E8FC9DD8A23FBBADF87EF27A4169D946F1DA74866A44E11BF4A01DCDC2A`, `B001/0002WL-LivingObjectPanePoolStaticStorage-source-quality.md` SHA256 `5A0A13022343170F06C9F62A7D00591BFDF124415B99AC86162FC7498F6D990A`, `B001/0003CC-ObjectOverlayFrameIndexTables.md` SHA256 `5CA6E26A7076BE0B0E5DB989BA81E7DA81FA74F31C16DAD723B61DD4CEBD9674`, and `B003/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md` SHA256 `F1DEBFD2DEA6061286B3C6493CAF10FB9204743A0713FBD8EDE2A6D5FE79A944`. They corroborate exact children, compiler/data treatment, UserPane consumers, and neighbor boundaries; none substitutes for this direct report.
- Active roots `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`: no loose direct UID0001PY report was found. At the final coordination read B001 was on report-only UID0002ZO, the immediate Parcel/Patch successor family; B003 was implementing UID0001PW; B004 was researching UID0003ZY; and B005 was rebasing UID00029O. B005 held a lease only on its own UID00029O report; no active assignment or lease overlapped a BowGauge target/support destination, and B002 held no lease. These are time-bounded coordination observations, not durable lifecycle claims.
- Legacy per-agent executed roots under `tools/leaser/Agents/Agent-B001` through `Agent-B015`: no direct UID0001PY report was found.
- Invalidated central report roots: no direct UID0001PY report was found.
- `tools/leaser/Agents/Older-Research`: no direct UID0001PY report was found.

The old reports were treated as leads. Fresh current MCP, current ordinary docs, raw executable bytes, generated output, and current coverage rows control all final conclusions.

## Target

- Target: [UID:0001PY] `by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md`.
- Exact range: `[0x0069ba24,0x0069ba28)`, four bytes.
- Historical evidence-time metadata: `86/90`, owner/emitter UID0000QA, reconstructable true, blank position/formal body, `Nested:-4`.
- Applied metadata: `92/94`, semantic owner UID0000QA, reconstructable false, blank emitter/position/formal body, `Nested:0`.
- Exact source identity: physical loader-zeroed backing storage for `BowGaugeObjectPane *g_pBowGaugeObjectPane`.
- Source emission: none on this physical page; UID0000QA owns the sole definition.

## Current Target State

The old `ff ff ff ff`, source-reconstructable, `Nested:-4`, and blank-emitter statements are explicitly historical. UID0001PY now documents four loader-zeroed bytes in the virtual `.data` tail, exact 13-reference lifecycle, physical-versus-semantic ownership, `92/94`, `RECONSTRUCTABLE:FALSE`, blank emission fields/formal, and `Nested:0`.

Historical command `000000016132` (SHA256 `DFEBDDD77B87C1E689F0F30E1C0F2D0C9EDAD2DDDFC776B8F8BB58D13CC5A632`, 2,205 bytes/49 lines) and tracker command `000000016138` record the pre-callback problem. Final waited repair command `000000016209`, refreshed `2026-07-21T19:08:07-04:00`, established `BowGaugeObjectPane.cpp` SHA256 `F2A8B9E50C8E11C23AD0D1253C042BF8D2AAD9028D9E1ECA83958409AEE432D7`, 3,800 bytes/111 lines, with one global, one complete direct-base class, all six authored methods in order, one vtable marker, one resource marker, and zero Empty Emitter Marker or handwritten ABI/scalar source. At the final report read, later unrelated validator activity had advanced only the volatile generated header to command `000000016223`, refreshed `2026-07-21T19:11:08-04:00`, SHA256 `333F81AE0DA5F21DF93636127C0445A2A4A0422B104150C04F4372DB72DCF8C0`, still 3,800 bytes/111 lines with the same exact semantic assertions. A time-bounded intermediate tracker read recorded command `000000016238`, SHA256 `E32E2AA23E54860C9CB145449FD126B1684A5015CD6BAAD5824FCF0A44F89B6A`, 1,556,434 bytes/6,295 lines; subsequent unrelated tracker refreshes are volatile, and the generated tracker header itself remains the current authority. These generated/tracker values are evidence-time observations, not durable claims about later unrelated validator epochs.

## Executive Recommendation

1. UID0001PY is now a detailed non-emitting `92/94` physical-storage page retaining semantic owner UID0000QA.
2. UID0000QA now emits the sole external initialized definition at position 0.
3. UID000011 now has the exact direct bases, size, field, declarations, inline empty destructor, child insertion point, and position 10.
4. Validator issued UID0004VN/VO/VP/VQ at positions 20/30/50/70; UID0001DC and UID0004SJ are synchronized at 40/60.
5. The BowGauge scalar page is non-emitting compiler lowering; UID000352 and UID0002YQ carry covered markers at 80/90.
6. UID0001DB/UID0001DL remain non-emitting split inventories with exact BowGauge child/padding/compiler detail added.
7. UID00007B contains only the bounded BowGauge forward/friend addition; UserPane pages remained read-only at same-or-greater detail.
8. The exact sixteen-row manual coverage handoff is rebased but remains exclusively supervisor-owned.

## Supervisor Active Recheck

- Executable mapping was rechecked: target RVA `0x0029ba24` is in `.data` virtual tail beyond file raw data; old `ff ff ff ff` prose is historical.
- Active B001 UID0002ZO and every successor Parcel/Patch page beginning at `0x0069ba28` were reread and left untouched.
- Four children were registered serially as UID0004VN, UID0004VO, UID0004VP, and UID0004VQ; no placeholder remains.
- UID00007B was reread after leasing and its complete union preserved; only the forward declaration and friend were added.
- Command 16209 verifies one external global, one complete class, six authored methods, one vtable marker, one resource marker, zero empty markers, and no handwritten scalar/adjustor/vtable ABI source after unique-UID repair.
- All sixteen manual rows were reread against the final hashes and rebased without erasing concurrent facts; application remains external.

## Inference Research Guidance Check

The final names and source shape use the narrowest human-written late-1999 through mid-2000s interpretation supported by behavior and project conventions. `BowGaugeObjectPane`, `g_pBowGaugeObjectPane`, `StartAnimation`, `RemovePendingTimers`, `OnPaint`, `SetAnimationStartTick`, `OnTimer`, `m_animationStartTick`, `BGAUGE.EPF`, and `BGAUGE.pal` are stable family or resource names. Decompiler labels, addresses, explicit vptr writes, adjusted-null arithmetic, scalar delete flags, security cookies, and raw RTTI arrays are excluded.

Lexical uncertainty remains only in the exact original spelling of `StartAnimation` and `m_animationStartTick`; the unique write/read roles and existing project naming make these the highest-probability source names. That uncertainty caps confidence at 94 rather than blocking formal C++.

## Heuristic / Inference Reanalysis And Validation

### Physical storage versus semantic declaration

The slot is four bytes because the binary is x86 and every code reference uses a dword pointer load/store. Its initial value is zero because the RVA falls after `.data` raw bytes but before `.data` virtual end. A source definition initialized to zero is period-plausible and commonly linker-placed in BSS-like storage. A physical memory page emitting a second definition would violate the one-definition route already modeled by UID0000QA.

### Singleton lowering

RTTI identifies `Singleton<BowGaugeObjectPane>` as a direct nonvirtual empty base at `+0xf8`. The constructor's add/subtract/null-adjust sequence and global store are template/base publication lowering, not authored explicit pointer assignment. EBO permits the derived `unsigned int` field to share offset `+0xf8`; no explicit reserve member exists. The scalar destructor's global clear is corresponding generated template/base cleanup.

### Authored versus compiler-only methods

The constructor, `StartAnimation`, timer removal wrapper, `OnPaint`, tick setter, and `OnTimer` each have behavior that must be represented in source. The destructor's authored source is an inline empty virtual destructor; the 69-byte scalar deleting wrapper, two adjusted thunks, global clear, base destruction, deleting-flag branch, and storage release are compiler output. Vtable/RTTI arrays and string storage are likewise generated from declarations and literals.

### OnPaint source fidelity

The accepted body preserves all unusual observed behavior: fill color 0; direct fill of `m_visibleBounds`; unguarded `g_pUserPane->m_nameVisible`; unsigned elapsed tick division by 138 followed by signed upper clamp to 36 only; resource lookup and render without result checks; no buffer cleanup; and unconditional `CompositePixels` using a separate uninitialized `RectBounds compositeRect`. Initializing or replacing that local would improve safety but would not be behavior-identical.

### Timer callback identity

The adjusted `+0xa4` vtable slot and `ret 0xc` body identify a three-argument `TimerHandler` callback. The body ignores all inputs, invalidates `m_visibleBounds`, schedules timer `(1,1,0,0)`, and returns true. The old `OnShow` label is rejected because no show-state transition or show parameter appears.

### Source placement

The contiguous BowGauge function island, dedicated global/class/file pages, dedicated vtable/resource bands, and generated file route favor `NexusTK/ui/panels/BowGaugeObjectPane.cpp`. UserPane constructs and consumes the object but does not semantically own the class. Cross-TU consumers require external global linkage and a class declaration visible to UserPane.

## Evidence Standards Used

- Direct: executable bytes, PE section arithmetic, MCP boundaries/decompilation/disassembly/xrefs/callers/callees/globals/RTTI, exact generated output, and current ordinary metadata/formal blocks.
- Very strong: source names and access derived from unique behavior, established project family names, exact field offsets, caller/consumer pairing, and accepted support declarations.
- Historical only: old report conclusions and stale ordinary/manual/generated snapshots that conflict with current direct evidence.
- Rejected: any source proposal that emits physical storage twice, reproduces compiler ABI mechanics, crosses exact range boundaries, initializes the observed uninitialized paint local, or invents defensive branches.

## Evidence Checked

### Live MCP and executable checks

- Fresh `idb_list` returned one live adopted NexusTK session `9b0396a3`, worker PID 15732.
- `server_health(database=9b0396a3)` returned `status:ok`, imagebase `0x00400000`, analysis ready, Hex-Rays ready, strings cache ready with 2,067 entries.
- Bounded `get_bytes` at `0x0069ba20` returned sixteen zero bytes, including exact target bytes `00 00 00 00`; target-byte SHA256 is `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- `get_global_value` at `0x0069ba20`, `0x0069ba24`, `0x0069ba28`, and `0x0069ba2c` returned zero at the evidence pass.
- PE offset `0x138`, machine `0x014c`, imagebase `0x00400000`; `.data` RVA `0x0026d000`, virtual size `0x0002fe24`, raw offset `0x0026ac00`, raw size `0x0000d800`. Target delta `0x0002ea24` is beyond raw size and inside virtual size.
- Function lookups, bounded bytes, decompilation, disassembly, xrefs, callers, callees, immediate searches, data-reference searches, byte-pattern searches, RTTI globals, and function/table/string negatives were run for every address named in the function inventory.

### Current documentation and generated checks

- All ordinary destination/support paths and their formal blocks were reread; exact hashes are recorded under Changed Files.
- Generated BowGauge and tracker snapshots were reread as time-bounded routing evidence under Current Target State.
- Historical Gate 1 manual hashes were `316B...7DC`, `DAD2...666C`, `6753...B9A1`, and `FD97...3CF`. At the final callback read the unchanged supervisor-owned files were: by-memory SHA256 `9C85F43016093B0D10E9835F00C7BFA543BC6E88AF2AF55F7942A4D9B4CF5436`, 1,935,893 bytes/4,495 lines; by-global `84C05ED823B2998B0F1323D323D8EA8730DA89A5B54543D7B868E153187CBBDE`, 98,313/217; by-class `0141E8E8C2A70A008850E8828837530E34BACC29F115579FE1538FAB464E1AD3`, 250,718/623; by-file `EE392406F9621CE98EF0A7E42B122441DADEF8C226DA1066ADCDC72CB7313244`, 148,324/316. The exact current anchors and no-loss B002 replacements/additions are recorded below; B002 edited none of them.
- Destination and lease ledgers were reread at the final callback checkpoint. No B002 lease remained; the active B001 successor UID0002ZO and every Parcel/Patch page beginning at `0x0069ba28` remained unedited.

## Claim And Incorporation Ledger

| ID | Claim | Destination / exact operation | Action | Verification state |
| --- | --- | --- | --- | --- |
| C01 | UID0001PY is exactly four bytes at `[0x0069ba24,0x0069ba28)`. | Destination 1 target range/body. | incorporate | applied |
| C02 | Current target bytes are four zeros with SHA256 `DF3F...119`. | Destination 1 storage/evidence. | incorporate | applied |
| C03 | Target is `.data` virtual-tail/BSS-like storage, not file-backed raw bytes. | Destination 1 PE mapping. | incorporate | applied |
| C04 | Historical `ff ff ff ff`/`0xffffffff` is disproved for this executable. | Destination 1 history with explicit supersession. | historicalize | applied |
| C05 | Predecessor ends exactly at `0x69ba24`; successor starts exactly at `0x69ba28`. | Destination 1 boundary table; successor read-only. | incorporate | applied |
| C06 | Exactly 13 data references implement publish, clear, and UserPane lifecycle. | Destinations 1, 2, 4, and 13 evidence. | incorporate | applied |
| C07 | Constructor publication is Singleton base lowering, not an authored assignment. | Destinations 3 and 4 class/constructor source-versus-compiler proof. | incorporate | applied |
| C08 | Scalar destruction clears the global through compiler/template lowering. | Destinations 3, 10, and 14 destructor/compiler proof. | incorporate | applied |
| C09 | UserPane cleanup/show/hide/update paths are consumers, not source owners. | Destinations 1, 2, and 16 plus read-only Destination 17 evidence. | incorporate | applied |
| C10 | No extra VA/RVA/raw-offset pointer-table route exists. | Destination 1 negative evidence. | not-applicable | applied |
| C11 | UID0001PY is physical storage while UID0000QA is semantic source owner. | Destinations 1 and 2. | incorporate | applied |
| C12 | Exact type/name are `BowGaugeObjectPane *g_pBowGaugeObjectPane`. | Destinations 2, 3, and prose-only 16. | incorporate | applied |
| C13 | Global has external linkage for cross-TU UserPane consumers. | Destinations 2, 3, and prose-only 16. | incorporate | applied |
| C14 | Exactly one initialized global definition emits at position 0. | Destination 2 and generated assertions. | incorporate | applied |
| C15 | Direct bases are Pane and empty Singleton; inherited handler facets are not extra direct bases. | Destinations 3, 4, and 11. | incorporate | applied |
| C16 | Exact class size is `0xfc`; terminal tick field is at `+0xf8` with no reserve member. | Destination 3. | incorporate | applied |
| C17 | Constructor authored body is the two base initializers and empty body. | Destination 4. | incorporate | applied |
| C18 | Authored destructor is inline empty; scalar wrapper mechanics are compiler-only. | Destinations 3, 10, 11, 14. | incorporate | applied |
| C19 | `StartAnimation` stores the tick and schedules `(1,1,0,0)`. | Destination 5. | incorporate | applied |
| C20 | UID0001DC is the exact TimerHandler removal wrapper with three callers. | Destination 6 preserves its accepted body and applies score/order/detail synchronization. | incorporate | applied |
| C21 | OnPaint preserves exact fill, visibility, frame, resource, render, and composite behavior. | Destination 7. | incorporate | applied |
| C22 | `BGAUGE.EPF` and `BGAUGE.pal` are exact source literals. | Destinations 7 and 12. | incorporate | applied |
| C23 | Separate uninitialized `compositeRect`, absent checks, and absent cleanup are intentional exact behavior. | Destination 7. | incorporate | applied |
| C24 | UID0004SJ is the exact one-store unsigned tick setter. | Destination 8 preserves its accepted body and applies position/detail synchronization. | incorporate | applied |
| C25 | `0x00538d10` is `OnTimer`, not `OnShow`, and returns true after invalidate/reschedule. | Destinations 3, 9, 11, and prose-only 16. | reject-stale | applied |
| C26 | `+0xa4` is an inherited TimerHandler facet; no synthetic timer member is emitted. | Destinations 3, 6, 9, and 11. | incorporate | applied |
| C27 | Vtables, RTTI, adjustors, cookies, and vptr stores are compiler output. | Destinations 3, 4, 7, 9, 10, and 11. | incorporate | applied |
| C28 | Validator-allocated UID0004VR must not emit a handwritten scalar deleting destructor; historical duplicate UID000380 is rejected for BowGauge and retained canonically only for JsonCpp. | Destination 10 plus commands 16195/16198/16200. | reject-invalid | applied |
| C29 | UID0002YQ emits a covered-by literal marker, not duplicate arrays. | Destination 12. | incorporate | applied |
| C30 | Standalone BowGauge source route is stronger than private UserPane colocation. | Prose-only Destination 16 and source-order proof. | incorporate | applied |
| C31 | UserPane's complete current caller/global/field union is same-or-greater and verify-only. | Read-only UserPane class/file/aggregate verification. | already-present | already-present |
| C32 | UID0001DB/UID0001DL remain non-emitting split inventories with exact children/padding, and UID0001DL links the scalar child through unique UID0004VR. | Destinations 13 and 14 plus command 16208. | incorporate | applied |
| C33 | Target/family score changes are evidence-bounded and lexical uncertainty caps confidence at 94. | Score table and Destinations 1-14. | incorporate | applied |
| C34 | Historical generated output proved the blank/incomplete routing symptom; final waited command 16209 proves closure after UID repair. | Validator Results final-read snapshot. | incorporate | applied |
| C35 | Final output is one global, one class, six authored methods, and covered ABI/resource markers. | Final generated assertions. | incorporate | applied |
| C36 | Historical BowGauge reports remain provenance leads, not direct-report substitutes. | Supporting Research/history sections. | historicalize | applied |
| C37 | UID00007B friendship is the narrow source-safe access route for `m_nameVisible`. | Destination 15. | incorporate | applied |
| C38 | ObjectPane ownership, static linkage, duplicate physical emission, raw ABI tables, defensive branches, and `OnShow` are rejected. | Negative Evidence and destinations. | reject-invalid | applied |
| C39 | Sixteen literal no-loss manual coverage actions are supervisor-owned. | Exact Manual Supervisor-Owned Coverage Or Tracker Text. | incorporate | applied |
| C40 | B002 callback edits, validator-issued UID0004VR allocation, canonical JsonCpp UID000380 restoration, reference migration, validators, and leases are complete; coverage and report lifecycle remain external. | Changed Files, Validator Results, registry proof, and checklist. | not-applicable | applied |

## Positive Evidence Summary

- Four current zero bytes and PE virtual-tail mapping directly establish zero-initialized pointer storage.
- Constructor write at `0x00538be4` and scalar clear at `0x0053cfe6` establish singleton lifetime endpoints.
- Eleven UserPane read sites plus the two write/clear sites produce the exact 13-reference inventory.
- RTTI PMD data identifies direct empty Singleton base at `+0xf8`; class extent and setter/paint access identify the overlapping terminal unsigned tick member.
- Dedicated function boundaries, caller sets, vtable slots, resource xrefs, and padding isolate six authored methods and one compiler scalar wrapper.
- The existing dedicated global/class/file routes and cross-TU UserPane consumers require one external definition in BowGauge source.
- The existing UserPane declaration already exposes `g_pUserPane` and `m_nameVisible`; one friend addition to LivingObjectPane is sufficient and does not alter layout.

## IDA MCP Facts

- Evidence session: `9b0396a3`; fresh final `idb_list` showed one active adopted worker, PID 15732.
- Health observation: `status:ok`, NexusTK.exe imagebase `0x00400000`, auto-analysis/Hex-Rays/strings ready.
- Target bytes: all zero at `0x0069ba20-0x0069ba2f`; target SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Exact source-function hashes: constructor `47CF71BF04CD01F506F79A18F067B0B0CEB23C2E11DFE4A84CDBF5A345A3A6B9`; Start `7DDD77459D9D7C6308530CBC036E8C1E3FA3A9ECC1ACD332D5026B9A637E7F2D`; removal `B64F0800FCF8C48DD1F2F3FBE60397F472492CCD28F7DDE4099A63389D496ECF`; paint `A528BA44509D31FC83AF9DF731788A20EAFA215FC9732541A2264127BC6E3486`; setter `DC58908B6D24CBBB03AAF187E09E52B994604615699C660E2E0B123D46D31858`; timer `A6743AA2D99A29DDFC1505C6D9D40886D4DC2C50CEDE3442C187439B366BE4AC`; scalar wrapper `AB6BE963F2C855D7B0CF242414EA4D9CAA2E758563F12411BAFDB0EFC95B3386`.
- Exact compiler/data hashes: vtable/RTTI range `3DBDC19B772A515C368866E249B19CA41BD319C23A1E9F1EFB4F2933C89330D6`; resource literals `3C61DA648E1AF00F50D0E7C049ABAA5DC9102A5B0CD3757C899D6EA9F0283366`; RTTI support `0590C2A1D8700AFCF6E5A093066B14E0825D68BB8AD8168E7E9AFC49A6F07D41`.
- Alignment: six `0xcc` bytes after constructor, six after Start, five after removal, six after paint, and five after timer. Padding hashes are `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722` for six bytes and `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329` for five bytes.

## Function / Child Inventory

| Range | Recommended child | Kind | Source disposition | Owner / position |
| --- | --- | --- | --- | --- |
| `0x00538bc0-0x00538c0a` | `0004VN` BowGaugeObjectPaneConstructor | authored constructor plus compiler lowering | emit authored base initialization only | UID000011 / 20 |
| `0x00538c0a-0x00538c10` | parent padding | six `0xcc` bytes | no child/source | UID0001DB inventory |
| `0x00538c10-0x00538c3a` | `0004VO` BowGaugeObjectPaneStartAnimation | authored method | emit | UID000011 / 30 |
| `0x00538c3a-0x00538c40` | parent padding | six `0xcc` bytes | no child/source | UID0001DB inventory |
| `0x00538c40-0x00538c4b` | UID0001DC RemovePendingTimers | authored wrapper | existing body, raise to 92/94 | UID000011 / 40 |
| `0x00538c4b-0x00538c50` | parent padding | five `0xcc` bytes | no child/source | UID0001DB inventory |
| `0x00538c50-0x00538cfa` | `0004VP` BowGaugeObjectPaneOnPaint | authored virtual | emit exact behavior | UID000011 / 50 |
| `0x00538cfa-0x00538d00` | parent padding | six `0xcc` bytes | no child/source | UID0001DB inventory |
| `0x00538d00-0x00538d10` | UID0004SJ SetAnimationStartTick | authored setter | retain body | UID000011 / 60 |
| `0x00538d10-0x00538d4b` | `0004VQ` BowGaugeObjectPaneOnTimer | authored virtual | emit; supersedes OnShow | UID000011 / 70 |
| `0x00538d4b-0x00538d50` | parent padding | five `0xcc` bytes | no child/source | UID0001DB inventory |
| `0x0053cfe0-0x0053d025` | UID0004VR scalar deleting destructor | compiler wrapper | false/non-emitting; inline empty destructor is source cause | UID000011 / blank |
| `0x006206ac-0x00620734` | UID000352 vtable/RTTI data | compiler ABI | covered marker only | UID000011 / 80 |
| `0x00620b90-0x00620bc0` | UID0002YQ resource literals | source-declared/generated data | covered marker only | UID000011 / 90 |
| `0x0069ba24-0x0069ba28` | UID0001PY physical slot | source storage | false/non-emitting | UID0000QA / blank |

## Direct Xref / Caller Inventory

### Global references

| Address | Containing function | Access and interpretation |
| --- | --- | --- |
| `0x00538be4` | constructor | publishes complete object pointer through Singleton lowering |
| `0x0053cfe6` | scalar deleting destructor | clears singleton through compiler/template cleanup |
| `0x005a2d1b`, `0x005a2d2d` | UserPane nondeleting destructor | nullable timer cancel and deferred pane deletion |
| `0x005a8e97`, `0x005a8ea2`, `0x005a8ef2`, `0x005a8f0e`, `0x005a8f3f` | UserPane::ShowNameLabel | show/position/tick/start animation sequence |
| `0x005a8f71` | UserPane::HideNameLabel | nullable timer removal |
| `0x005a8fe5` | UserPane::AdvanceMovementSendTick | unguarded setter call after unsigned clamp |
| `0x005b82f2`, `0x005b8304` | UserPane scalar deleting destructor | mirrored nullable cleanup and deferred deletion |

`find` immediate yielded twelve operand starts because the constructor store was classified differently; data-reference search yielded all thirteen. Literal VA byte search `24 ba 69 00` found exactly thirteen operand-byte occurrences. RVA pattern `24 ba 29 00` and non-code pointer-table scans found none.

### Method callers

- Constructor has one direct call at `0x005a2956` in UserPane constructor; that UserPane constructor has callers at `0x004f84e2` and `0x004f8a49`.
- `StartAnimation` has one direct call at `0x005a8f46` in `UserPane::ShowNameLabel`.
- UID0001DC has exactly three direct callers at `0x005a2d28`, `0x005a8f7b`, and `0x005b82ff`.
- `OnPaint` is reached through primary vtable cell `0x006206f4`; no direct call is expected.
- UID0004SJ has one direct call at `0x005a8fec`; the containing helper's sole caller is `0x00512bb4` in the action/status path.
- `OnTimer` is reached through adjusted TimerHandler vtable cell `0x00620730`; no direct source call is expected.
- UID0004VR is reached through primary vtable cell `0x006206b0` and compiler adjustor thunks `0x0053cea4`/`0x0053ceaf`; no source direct caller exists. Its former BowGauge UID000380 label was an invalid duplicate, not a second function identity.

## Documentation Evidence And IDA Status

- Evidence-time UID0001PY retained valid lifecycle evidence but had stale bytes/reconstructable/nesting/blank-emitter claims. Current applied D1 is `92/94`, false/non-emitting, zero-backed virtual-tail storage with exact no-code proof.
- Evidence-time UID0000QA lacked code/order. Current D2 is `92/94`, position 0, and emits the sole external zero-initialized definition.
- Evidence-time UID000011 omitted the Singleton base, inline destructor, Start declaration, external declaration, access order, and children. Current D3 is the complete `92/94`, position-10 declaration with all four real children.
- Evidence-time UID0000HU lagged the resolved family. Current prose-only D16 is `92/94` with complete source order, one-definition route, resources, lifecycle, and compiler exclusions; it has no by-file reconstruction metadata.
- UID0001DC and UID0004SJ retained their source-ready bodies and now have positions 40/60 plus final report-level synchronization.
- BowGauge scalar UID0004VR is `92/94`, false/non-emitting, blank formal C++, with exhaustive compiler no-code proof. Command 16195 allocated its unique UID, command 16200 revalidated the repaired page, and command 16198 restored unchanged canonical JsonCpp UID000380 to `88/91`; registry/path scans prove one ordinary header and one mapping for each UID.
- UID000352 is now `92/94`, position 80, with the exact direct-base/OnTimer compiler marker; the old show/timer wording is historical.
- UID0002YQ is now `92/94`, position 90, `Nested:0`, with the exact covered literal marker; it no longer produces an Empty Emitter Marker.
- UID00007B preserves its complete `92/93` declaration and adds only the source-safe BowGauge forward/friend route to protected `m_nameVisible`.
- UserPane class/file/aggregate remain read-only and byte-identical at same-or-greater caller/global/field/lifecycle detail.

## Ranked Ownership Analysis

1. **UID0000QA semantic global under UID0000HU** - accepted. It represents the source symbol and can emit exactly one external definition in BowGauge source.
2. **UID0001PY physical backing storage under UID0000QA** - accepted as semantic documentation ownership only. It records address/bytes/mapping/lifetime but emits no duplicate definition.
3. **UID000011 class ownership for methods, compiler data, and resources** - accepted. Receiver, RTTI, vtable, field, resources, and method island all converge here.
4. **UserPane source ownership** - rejected. UserPane constructs and consumes BowGauge but has different function island, class, file, and global ownership. It is a caller/dependency route.
5. **ObjectPane/AttachedObjectPane ownership** - rejected. BowGauge constructs through Pane and has distinct RTTI/resources/global; object-pane adjacency is not inheritance.
6. **Broad UID0001DB/UID0001DL ownership** - rejected as emitters. They are mixed-owner physical inventories and remain non-emitting.
7. **Static/anonymous/local singleton definition** - rejected. Cross-TU UserPane consumers and the dedicated by-global route require external linkage.

## Source Placement

- Header/class declaration: UID000011 emitted by UID0000HU at position 10.
- External declaration: appended inside the UID000011 class formal after the size guard.
- Sole definition: UID0000QA at position 0 in `NexusTK/ui/panels/BowGaugeObjectPane.cpp`.
- Method order: constructor 20, Start 30, Remove 40, OnPaint 50, setter 60, OnTimer 70.
- Compiler/data marker order: vtable 80, resource literal coverage 90.
- Physical target UID0001PY, compiler scalar UID0004VR, and broad inventories UID0001DB/UID0001DL emit nothing.
- UserPane source includes/uses the BowGauge declaration and external pointer but remains a separate emitter.
- UID00007B adds only friendship; it does not move BowGauge code into LivingObjectPane source.

Rejected source placement alternatives are private static state in UserPane, duplicate target/global definitions, anonymous namespace linkage, inline header definition, local static accessor, raw vtable/resource arrays, and attaching the mixed physical aggregates to one emitter.

## Range / Split / Padding / Reclassification Analysis

The target is an exact four-byte range and needed no split. Historical `Nested:-4` was stale; applied D1 uses `Nested:0` and consumes neither predecessor nor successor bytes.

UID0001DB remains a broad non-emitting inventory. D13 now indexes UID0004VN/VO/VP/VQ plus existing exact BowGauge children and keeps all six/five-byte `0xcc` runs as parent alignment. No function absorbs padding.

UID0001DL remains a broad non-emitting destructor inventory. D14 now uses unique [UID:0004VR][BowGaugeObjectPaneScalarDeletingDestructor](by-memory/0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor.md), records its compiler-generated disposition and inline empty destructor source cause, and preserves invalid duplicated UID000380 only as resolved history. The exact child range absorbs no padding.

Vtable UID000352 remains exact through `0x00620734`; successor HitBar data starts there. Resource UID0002YQ remains exact through `0x00620bc0`; `DEADSIGN.EPF` starts there. The global predecessor UID0002WU ends at `0x0069ba24`, and the Parcel/Patch successor begins at `0x0069ba28`.

## Negative Evidence Summary

- No current file-backed bytes support `0xffffffff`; target lies outside `.data` raw extent.
- No second writable slot, pointer table, RVA literal, accessor-return function, or alternate publication/clear route was found.
- No evidence supports `ObjectPane *`, `void *`, integer sentinel storage, an array, or a pointer-to-pointer type.
- No evidence supports explicit authored singleton publication/clear, null-adjust arithmetic, vptr stores, base teardown, deleting flags, sized delete, generic free, or security-cookie code.
- No source behavior supports an `OnShow` method at `0x00538d10`.
- No evidence supports lower-frame clamping, null guards, resource-result checks, buffer cleanup, or initialization of `compositeRect` in OnPaint.
- No explicit source member exists for `+0xa0` or `+0xa4`; those are inherited handler facets.
- No reserve/padding member exists after `m_animationStartTick`; class size ends at `0xfc`.
- No handwritten RTTI/vtable or resource array is defensible.
- No evidence supports UserPane, ObjectPane, broad aggregate, or successor Parcel/Patch ownership of the BowGauge definition.

## IDA Rename / Type / Comment Recommendations

- Rename data symbol `dword_69BA24`/`unk_69BA24` to `g_pBowGaugeObjectPane` and type it `BowGaugeObjectPane *` only during authorized IDA mutation; this report performs no IDA write.
- Rename source functions to `BowGaugeObjectPane::BowGaugeObjectPane`, `BowGaugeObjectPane::StartAnimation`, `BowGaugeObjectPane::RemovePendingTimers`, `BowGaugeObjectPane::OnPaint`, `BowGaugeObjectPane::SetAnimationStartTick`, and `BowGaugeObjectPane::OnTimer`.
- Type the terminal field at `+0xf8` as `unsigned int m_animationStartTick`.
- Comment constructor/destructor global stores as Singleton-template/compiler lowering, not authored assignments.
- Comment `+0xa0` and `+0xa4` as inherited EventHandler/TimerHandler adjusted views, not data members.
- Comment UID0004VR, adjusted thunks, UID000352, cookies, and vptr stores as compiler-only; note historical BowGauge UID000380 as a superseded duplicate of canonical JsonCpp identity.
- Comment UID0002YQ as source literals consumed by OnPaint, with no standalone raw-array source.
- Preserve `compositeRect` as a distinct uninitialized local in the reconstructed OnPaint comment/type record.

## First-Draft C++ Recommendation

### Destination 1 - UID0001PY target physical page

*** UID:0001PY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000QA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact loader-zeroed physical backing slot for the externally defined BowGaugeObjectPane singleton pointer, with proven virtual-tail mapping, zero initializer, complete 13-reference lifecycle, exact neighbors, and no duplicate source emission. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 2 - UID0000QA semantic global

*** UID:0000QA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BowGaugeObjectPane;

BowGaugeObjectPane *g_pBowGaugeObjectPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID000011 complete class

*** UID:000011 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BowGaugeObjectPane : public Pane,
                           public Singleton<BowGaugeObjectPane>
{
public:
    BowGaugeObjectPane();
    virtual ~BowGaugeObjectPane() {}

    void StartAnimation(unsigned int startTick);
    void RemovePendingTimers();
    void SetAnimationStartTick(unsigned int startTick);

protected:
    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    unsigned int m_animationStartTick;
};

typedef char BowGaugeObjectPaneSizeMustBe252[
    sizeof(BowGaugeObjectPane) == 0xfc ? 1 : -1];

extern BowGaugeObjectPane *g_pBowGaugeObjectPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - 0004VN constructor child

*** UID:0004VN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BowGaugeObjectPane::BowGaugeObjectPane()
    : Pane(1),
      Singleton<BowGaugeObjectPane>()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact BowGaugeObjectPane source constructor with Pane mode 1 and empty Singleton base initialization; global publication, null adjustment, and three vptr stores are compiler/template lowering rather than handwritten body statements. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 5 - 0004VO StartAnimation child

*** UID:0004VO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BowGaugeObjectPane::StartAnimation(unsigned int startTick)
{
    m_animationStartTick = startTick;
    ScheduleTimer(1, 1, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source method that records the unsigned animation start tick and schedules timer 1 after one millisecond, with one direct UserPane ShowNameLabel caller and no validation or secondary state. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 6 - UID0001DC RemovePendingTimers

*** UID:0001DC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BowGaugeObjectPane::RemovePendingTimers()
{
    TimerHandler::RemovePendingTimers();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact BowGaugeObjectPane TimerHandler-facet cleanup wrapper with two-instruction tail jump, three UserPane lifecycle callers, exact adjacent padding, and no independent return value or BulletinSession ownership. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 7 - 0004VP OnPaint child

*** UID:0004VP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BowGaugeObjectPane::OnPaint()
{
    RectBounds compositeRect;
    EPFTileContext frame;
    frame.Initialize();

    SetDrawColor(0);
    FillRect(&m_visibleBounds);

    if (g_pUserPane->m_nameVisible)
    {
        int frameIndex =
            (timeGetTime() - m_animationStartTick) / 138;
        if (frameIndex > 36)
            frameIndex = 36;

        g_pEPFLib->LookupLayoutEntry(
            L"BGAUGE.EPF", frameIndex, &frame);
        RenderTileFrame(
            &frame,
            &frame.bounds,
            &m_visibleBounds,
            0,
            L"BGAUGE.pal",
            0);
    }

    CompositePixels(&compositeRect);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Behavior-identical BowGauge paint virtual preserving background fill, unguarded UserPane name visibility, unsigned elapsed-time frame selection with upper-only clamp, exact EPF/palette rendering, and unconditional composite through the observed separate uninitialized rectangle local. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 8 - UID0004SJ SetAnimationStartTick

*** UID:0004SJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BowGaugeObjectPane::SetAnimationStartTick(unsigned int startTick)
{
    m_animationStartTick = startTick;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact one-store BowGaugeObjectPane method that records the unsigned animation-start tick consumed by OnPaint; sole live caller is the UserPane movement-tick helper, receiver offset is +0xf8 in the exact 0xfc class, and no guard or wrapper code belongs to the body. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 9 - 0004VQ OnTimer child

*** UID:0004VQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool BowGaugeObjectPane::OnTimer(int, int, int)
{
    InvalidateRect(&m_visibleBounds);
    ScheduleTimer(1, 1, 0, 0);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact TimerHandler virtual reached through the +0xa4 adjusted view; ignores all three inputs, invalidates the visible bounds, reschedules timer 1 after one millisecond, returns true, and supersedes the stale OnShow interpretation. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 10 - UID0004VR scalar deleting destructor

*** UID:0004VR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler scalar-deleting destructor and adjusted-view endpoint regenerated from the inline empty virtual destructor, Pane and Singleton bases, deleting flags, size guard, and storage release; no handwritten wrapper body is defensible. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 11 - UID000352 vtable data

*** UID:000352 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-emitted RTTI/vtable data for BowGaugeObjectPane is regenerated
// from its complete Pane plus Singleton<BowGaugeObjectPane> declaration,
// virtual destructor, OnPaint, OnTimer, and compiler adjustors. Do not emit
// hand-authored ABI arrays or a standalone body for this .rdata range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact primary, +0xa0 adjusted, and +0xa4 TimerHandler adjusted BowGaugeObjectPane RTTI/vtable range, covered by complete source declarations and virtual definitions rather than handwritten ABI arrays. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 12 - UID0002YQ resource literals

*** UID:0002YQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000011 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The BGAUGE.EPF and BGAUGE.pal literals are emitted by
// BowGaugeObjectPane::OnPaint(). Do not emit duplicate standalone arrays
// for this source-declared/generated-binary .rdata range.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact BGAUGE.EPF and BGAUGE.pal source literals with one OnPaint xref each, covered by the paint definition and excluded from standalone raw-array emission. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 13 - UID0001DB method-island aggregate

*** UID:0001DB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting mixed BowGauge and attached-overlay physical inventory with exact source children, function boundaries, alignment runs, per-class ownership, and compiler exclusions; exact children carry all source emission. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 14 - UID0001DL destructor aggregate

*** UID:0001DL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting mixed-owner scalar-destructor inventory with exact companion bounds, compiler adjustors, cleanup/free routes, padding, and exact child dispositions; authored class destructors regenerate the wrappers. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

### Destination 15 - UID00007B no-loss class block with BowGauge access

*** UID:00007B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Motion;
class List;
class AttachedObjectPane;
class BalloonObjectPane;
class EffectObjectPane;
class HitBarObjectPane;
class DamageNumberObjectPane;
class ObjectInfoObjectPane;
class BowGaugeObjectPane;
class GrafPort;
struct NxRect;

class LivingObjectPane : public ObjectPane
{
public:
    enum TimerMessage
    {
        kLivingTimerForwardStep = 0x41645746,
        kLivingTimerBoxStep = 0x41534246,
        kLivingTimerDirectionDelay = 0x43684469,
        kLivingTimerFrameAnimation = 0x446e4146,
        kLivingTimerRefresh = 0x52654461
    };

    class BoxRotator : public FrameHandler
    {
    public:
        explicit BoxRotator(LivingObjectPane *owner) : m_owner(owner) {}
        virtual ~BoxRotator() {}

        virtual void Advance(int frame);
        void Start();
        void Stop();

    private:
        friend class LivingObjectPane;
        LivingObjectPane *m_owner;
    };

    LivingObjectPane(
        int objectId,
        int mapX,
        int mapY,
        const ObjectStatusBlob &objectStatus,
        unsigned char facing);
    LivingObjectPane(int objectId, int mapX, int mapY, unsigned char facing);
    virtual ~LivingObjectPane();

    void GetSpriteConfig(ObjectStatusBlob *out) const;
    bool SetSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    void InitializeSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    bool HasGMNameSuffix() const;

    void SetMovingState(bool moving);
    void DestroyAllLinkedObjects();
    void DestroyAttachedObjects();
    void SetBalloonObjectPane(BalloonObjectPane *pane);
    void AddPrimaryEffectObjectPane(EffectObjectPane *pane);
    void AddSecondaryEffectObjectPane(EffectObjectPane *pane);
    void SetHitBarObjectPane(HitBarObjectPane *pane);
    void SetDamageNumberObjectPane(DamageNumberObjectPane *pane);
    void SetObjectInfoObjectPane(ObjectInfoObjectPane *pane);
    void UnregisterAttachedObjectPane(AttachedObjectPane *pane);

    void AddMotion(Motion *effect);
    void RemoveMotion(Motion *effect);
    void ClearAllEffects();
    void SetCurrentMotion(Motion *effect);
    void SetHighlightState(bool highlighted);
    void ShowDamageEffect(int value, short soundId);
    bool BeginMoveTo(int x, int y, unsigned char facing, short stepDelay);
    void SetFacing(unsigned char facing);
    void PlayAnimation(unsigned int animationGroup);
    void PlayFacingAnimation();
    void PlayDeathAnimation();
    void RequestNameplateEffect();
    void RemoveSpecialEffect();
    void ScheduleBoxRotationStep();
    void CancelBoxRotationStep();
    void ApplyLinkedObjectMode(int mode);
    void SyncPositionToLinkedObjects();
    void RefreshAllLinkedObjects();

    virtual void GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const;
    virtual void RenderFrame(GrafPort *target, const RectBounds *bounds);
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target, const RectBounds *bounds);
    virtual void SetMapPosition(int x, int y);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void PlayActionAnimationOrEffect(
        unsigned action,
        int value,
        unsigned char facing);
    virtual void ShowName();
    virtual void HideName();
    virtual void PropagateLinkedObjectMode(int mode);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    friend class MapPane;
    friend class Motion;
    friend class BowGaugeObjectPane;

    bool TryStepForward();

protected:
    unsigned char m_nameState;                       // 0x128
    wchar_t m_nameBuffer[33];                        // 0x12a
    unsigned int m_objectInfoType;                   // 0x16c
    List *m_primaryEffectObjectPanes;                 // 0x170
    List *m_secondaryEffectObjectPanes;               // 0x174
    ObjectStatusBlob m_objectStatus;                  // 0x178
    List *m_activeEffects;                            // 0x1bc, Motion * values
    Motion *m_currentEffect;                          // 0x1c0
    bool m_isMoving;                                  // 0x1c4
    unsigned char m_facing;                           // 0x1c5
    signed char m_moveFrame;                          // 0x1c6
    unsigned int m_animationFrame;                    // 0x1c8
    unsigned int m_animationGroup;                    // 0x1cc
    bool m_terminalAnimation;                         // 0x1d0
    bool m_nameVisible;                               // 0x1d1
    unsigned int m_boxRotationStep;                   // 0x1d4
    BalloonObjectPane *m_balloonObjectPane;            // 0x1d8
    HitBarObjectPane *m_hitBarObjectPane;              // 0x1dc
    DamageNumberObjectPane *m_damageNumberObjectPane;  // 0x1e0
    ObjectInfoObjectPane *m_objectInfoObjectPane;      // 0x1e4
    bool m_highlighted;                               // 0x1e8
    unsigned int m_boxRotationPhase;                  // 0x1ec
    BoxRotator m_boxRotator;                          // 0x1f0
    unsigned int m_renderEffectState;                 // 0x1f8
    RectBounds m_bounds;                              // 0x1fc
};

typedef char LivingObjectPaneSizeMustBe524[
    sizeof(LivingObjectPane) == 0x20c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 16 is prose-only UID0000HU file guidance. It must not receive `RECONSTRUCTION_CPP` metadata. Destination 17 is read-only verification of current UserPane class/file/aggregate. These do not add managed blocks.

## Final Recommendation

Destinations 1-15 and prose-only/read-only Destinations 16-17 are applied/verified as the complete callback result. Every investigable target blocker is closed: exact physical bytes/mapping, semantic owner, type/name/linkage, one-definition route, complete class declaration, all source-bearing methods, direct-base/EBO layout, compiler wrapper/data treatment, UserPane access, resource literals, scores, generated route, and manual handoff.

The exact source-bearing inventory is global UID0000QA, class UID000011, UID0004VN/VO/VP/VQ, UID0001DC, and UID0004SJ. UID0001PY, scalar UID0004VR, UID0001DB, and UID0001DL remain non-emitting for documented reasons. UID000352/UID0002YQ emit only coverage markers, not raw ABI/data definitions. UID000380 is not a BowGauge identity; it remains the canonical JsonCpp `OurReader` prelude UID at restored `88/91`.

## Recommended Target Doc Changes

- Applied Destination 1 metadata and blank formal exactly.
- Replaced stale value/storage prose with zero bytes and precise PE virtual-tail arithmetic while preserving `0xffffffff` only as labeled history.
- Preserved/expanded all 13 references, lifetime endpoints, UserPane consumers, caller chains, scans, negative routes, and exact neighbors without claiming successor ownership.
- Recorded UID0000QA semantic ownership independently of physical-page emission and supplied the exact no-code proof against duplicate definition.

## Recommended Support Doc Changes

- UID0000QA: applied Destination 2 and full one-definition/linkage/lifetime evidence.
- UID000011: Destination 3, exact bases/layout/access/method order/source/compiler distinctions.
- Four exact method pages: Destinations 4, 5, 7, and 9 registered serially as UID0004VN/VO/VP/VQ.
- UID0001DC/UID0004SJ: Destinations 6/8, positions and report-level evidence while preserving bodies.
- UID0004VR: Destination 10 unique non-emitting compiler proof; invalid BowGauge duplicate UID000380 historicalized, canonical JsonCpp UID000380 restored independently.
- UID000352/UID0002YQ: Destinations 11/12 marker and exact data evidence.
- UID0001DB/UID0001DL: Destinations 13/14 plus complete child/padding/source/compiler inventory.
- UID00007B: Destination 15 complete current formal plus only BowGauge forward/friend additions.
- UID0000HU: prose-only score/source-order/includes/lifecycle/resource/global/compiler-exclusion synchronization; no by-file reconstruction metadata.
- UserPane class/file/aggregate: read-only verification passed at the accepted hashes; no contradiction or edit occurred.

## Score And Metadata Recommendation

| UID | Evidence-time | Applied | Metadata disposition | Rationale |
| --- | --- | --- | --- | --- |
| 0001PY | 86/90 | 92/94 | owner 0000QA; false; blank emitter/position/formal; Nested 0 | exact zero/BSS/refs/no-duplicate proof |
| 0000QA | 87/90 | 92/94 | owner/emitter 0000HU; true; position 0 | sole typed external definition |
| 000011 | 90/92 | 92/94 | owner/emitter 0000HU; true; position 10 | complete class/layout/source declaration |
| 0004VN | new | 92/94 | owner/emitter 000011; true; position 20 | exact constructor source/compiler split |
| 0004VO | new | 92/94 | owner/emitter 000011; true; position 30 | exact source method and caller |
| 0001DC | 87/91 | 92/94 | retain owner/emitter; position 40 | exact wrapper/body/callers/padding |
| 0004VP | new | 92/94 | owner/emitter 000011; true; position 50 | complete behavior-identical OnPaint |
| 0004SJ | 92/94 | 92/94 | retain owner/emitter; position 60 | already source-ready; ordering only |
| 0004VQ | new | 92/94 | owner/emitter 000011; true; position 70 | exact OnTimer identity/body |
| 0004VR | legacy BowGauge duplicate UID000380 at 88/92 | 92/94 | semantic owner 000011; false; blank emitter/position/formal | validator-allocated unique identity plus exhaustive compiler-wrapper proof |
| 000380 | canonical JsonCpp page header 88/91; registry had been polluted to 92/94 by the duplicate scan | restored 88/91 | owner/emitter 0000KI; true; import route retained | command 16198 restored the canonical JsonCpp identity without changing its documentation |
| 000352 | 88/92 | 92/94 | owner/emitter 000011; true; position 80 | exact compiler-data marker and slots |
| 0002YQ | 88/92 | 92/94 | owner/emitter 000011; true; position 90; Nested 0 | exact source literals/covered marker |
| 0001DB | 86/91 | 86/91 | NONE/false/blank retained | mixed physical index only |
| 0001DL | 90/92 | 90/92 | NONE/false/blank retained | mixed destructor index only |
| 00007B | 92/93 | 92/93 | metadata retained | one no-layout friend addition |
| 0000HU | 85/90 | 92/94 | true file root; prose only | complete standalone source family |

Confidence stops at 94 because original private names, source filename packaging, and explicit-zero spelling are inferred from stripped binary/project conventions. Those lexical uncertainties do not leave behavioral, ownership, emission, layout, or compile-visibility blockers.

## Open Questions With Attempted Resolution

1. **Was the global explicitly initialized to zero?** File bytes cannot distinguish explicit from implicit zero initialization. Project style and a destination-ready definition favor `= 0`; both generate the proven storage. Confidence is capped, not blocked.
2. **Was BowGauge private to UserPane source?** Dedicated function/data/global/class/file clustering and existing generator route favor standalone BowGauge source. UserPane is kept as a consumer. No unresolved compile route remains.
3. **Is `StartAnimation` the exact original name?** Unique start-tick store plus schedule and call from ShowNameLabel support it. Alternatives `Show`, `Begin`, and `ResetTimer` describe less of the behavior.
4. **Is `m_animationStartTick` exact?** Setter, Start, OnPaint unsigned elapsed computation, and UserPane movement tick prove the role/type. Lexical uncertainty is bounded by confidence.
5. **Is `0x00538d10` OnShow?** No. Timer vtable placement, three stack arguments, invalidation, reschedule, true return, and absence of show state prove OnTimer.
6. **Should UID0004VR emit code?** No. Every instruction is compiler scalar-delete/template/base lowering; inline empty virtual destructor is the source cause. Historical BowGauge UID000380 was an invalid identity collision, not a reason to defer source disposition; validator allocation and JsonCpp revalidation resolved it.
7. **Should resource strings emit arrays?** No. They are source literals already present in OnPaint; the marker only documents coverage.
8. **How can BowGauge read protected Living state?** One forward declaration and friend on UID00007B preserves exact direct field access without layout change or invented getter.
9. **Does target need a child or split?** No. It is exact four-byte storage and becomes non-emitting under semantic owner UID0000QA.
10. **Can successor Parcel/Patch evidence be incorporated now?** Only boundary verification. Active B001 UID0002ZO owns that family; this report neither edits nor duplicates it.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

At the final duplicate-UID repair read, the supervisor-owned roots were by-memory `0D9730FCC80E0793B798E33133712E44C0CA31503303002055C3C385CCF7E37F` (1,935,893 bytes/4,495 lines), by-global `84C05ED823B2998B0F1323D323D8EA8730DA89A5B54543D7B868E153187CBBDE` (98,313/217), by-class `0141E8E8C2A70A008850E8828837530E34BACC29F115579FE1538FAB464E1AD3` (250,718/623), and by-file `EE392406F9621CE98EF0A7E42B122441DADEF8C226DA1066ADCDC72CB7313244` (148,324/316). The following sixteen no-loss actions are rebased onto those rows. Existing anchors are by-memory UID0001DB line 2635, UID0001DC 2636, UID0004SJ 2638, UID0001DL 2695, UID000352 4055, UID0002YQ 4065, UID0001PY 4451; by-global UID0000QA line 56; by-class UID000011 line 63 and UID00007B line 287; by-file UID0000HU line 38. UID0004VN/VO/VP/VQ and unique BowGauge scalar UID0004VR are absent and remain exact additions. B002 did not edit coverage.

Historical Gate 1 hashes/line anchors are superseded only as mutable snapshots; their row facts were retained in the merged text below. Command 16161 historically exposed the invalid BowGauge/JsonCpp duplicate UID000380. Command 16195 allocated unique BowGauge UID0004VR through the documented missing-UID path, command 16198 restored canonical JsonCpp UID000380 to `88/91`, and commands 16200/16204/16205/16208 migrated and validated BowGauge ordinary references. The exact supervisor-owned scalar addition below therefore uses UID0004VR; B002 did not edit manual coverage or validator-owned state directly.

### by-memory replacements/additions

Replace current UID0001DB row at line 2635 with:

    - [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md) 0x00538bc0-0x00539bb2 | mixed-class-cluster | ObjectOverlayPanes : not_reconstructable : 86% : very-strong : Non-emitting mixed BowGauge/attached-overlay physical inventory with 27 modeled starts, exact function boundaries and alignment. HitBar rows retain dual/style constructors, SetValues, IsActive, shared UpdatePosition, ClearOutputRects, RenderFrame, exact 0x138 layout, pool/vtable/resource support, MapPane callers, and compiler-only unwind/deleting/vtable mechanics. BowGauge inventory adds exact constructor, StartAnimation, RemovePendingTimers, OnPaint, SetAnimationStartTick, and OnTimer children at positions 20-70; preserves six/five-byte 0xcc alignment runs; class/global/vtable/resource children own source or covered markers; the broad parent emits nothing.

Insert after UID0001DB and before current UID0001DC, in address order:

    - [UID:0004VN][0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor](by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md) 0x00538bc0-0x00538c0a | BowGaugeObjectPane constructor | BowGaugeObjectPaneConstructor : reconstructable : 92% : very-strong : Exact 0x4a source constructor with Pane mode 1 and empty Singleton<BowGaugeObjectPane> base initialization; sole UserPane constructor caller; compiler-only singleton publication/null adjustment and three vptr stores excluded; six-byte trailing alignment retained by UID0001DB.
    - [UID:0004VO][0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation](by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md) 0x00538c10-0x00538c3a | BowGaugeObjectPane method | BowGaugeObjectPaneStartAnimation : reconstructable : 92% : very-strong : Exact 0x2a method stores unsigned start tick at +0xf8 and schedules timer (1,1,0,0); sole direct caller is UserPane::ShowNameLabel; six-byte trailing alignment remains parent-only.

Replace current UID0001DC row at line 2636 with:

    - [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md) 0x00538c40-0x00538c4b | timer cleanup wrapper | BowGaugeObjectPaneRemovePendingTimers : reconstructable : 92% : very-strong : Exact 0xb two-instruction TimerHandler-facet wrapper adds +0xa4 and tail-jumps to shared pending-timer removal; three direct UserPane cleanup/hide callers, no call-return callee, exact adjacent six/five-byte alignment, g_pBowGaugeObjectPane lifecycle, class owner, position 40, and complete source body are resolved; BulletinSession and synthetic timer-member interpretations are rejected.

Insert after UID0001DC and before UID0004SJ:

    - [UID:0004VP][0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint](by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md) 0x00538c50-0x00538cfa | BowGaugeObjectPane virtual | BowGaugeObjectPaneOnPaint : reconstructable : 92% : very-strong : Exact 0xaa/58-instruction vtable-only paint body fills visible bounds, checks unguarded UserPane name visibility, computes unsigned elapsed/138 with signed upper-only clamp 36, looks up BGAUGE.EPF, renders BGAUGE.pal, and unconditionally composites through a distinct uninitialized RectBounds; no null/result/buffer-cleanup branches; six-byte trailing alignment remains parent-only.

Replace current UID0004SJ row at line 2638 with:

    - [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) 0x00538d00-0x00538d10 | BowGaugeObjectPane method | BowGaugeObjectPaneSetAnimationStartTick : reconstructable : 92% : very-strong : Exact one-store void setter for unsigned animation-start tick at +0xf8, sole UserPane movement-tick caller, BowGauge OnPaint elapsed-frame consumer, exact 0xfc class terminal field, position 60, and no guard/return/wrapper code.

Insert after UID0004SJ:

    - [UID:0004VQ][0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer](by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md) 0x00538d10-0x00538d4b | BowGaugeObjectPane TimerHandler virtual | BowGaugeObjectPaneOnTimer : reconstructable : 92% : very-strong : Exact 0x3b adjusted-vtable callback ignores three inputs, invalidates visible bounds, schedules timer (1,1,0,0), returns true, and ends before five-byte alignment; source-facing identity is OnTimer, superseding stale OnShow wording.

Replace current UID0001DL row at line 2695 and insert UID0004VR directly beneath it:

    - [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md) 0x0053cfa0-0x0053d65b | destructor-island | ObjectPaneCompanionDestructors : not_reconstructable : 90% : very-strong : Non-emitting mixed-owner exact inventory for Attached/BowGauge/DamageNumber/Effect/Flying/HitBar/Item/ObjectInfo scalar destructors plus separately owned Living/Lighting/BoxRotator/Motion spans; retains exact bounds, adjustor/vtable refs, cleanup/free/pool paths and padding. BowGauge UID0004VR is compiler scalar-delete output regenerated from its inline empty destructor, Pane and Singleton bases; its former duplicated UID000380 is rejected as BowGauge identity and retained canonically only for JsonCpp. Exact children own source dispositions and the broad range emits nothing.
        - [UID:0004VR][0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor](by-memory/0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor.md) 0x0053cfe0-0x0053d025 | compiler scalar deleting destructor | BowGaugeObjectPaneScalarDeletingDestructor : not_reconstructable : 92% : very-strong : Exact 0x45 wrapper reached by primary vtable and +0xa0/+0xa4 adjustors; clears singleton, performs Pane teardown, deleting-flag branch, size guard and storage release as compiler/template lowering. Authored source is inline empty virtual BowGauge destructor; no handwritten wrapper or ABI body. UID0004VR is validator-allocated uniquely to this path; canonical JsonCpp UID000380 remains independent at 88/91.

Replace current UID000352 row at line 4055:

        - [UID:000352][0x006206ac-0x00620734.BowGaugeObjectPaneVtableData](by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md) 0x006206ac-0x00620734 | vtable-data | BowGaugeObjectPaneVtableData : reconstructable : 92% : very-strong : Exact 0x88 primary, +0xa0 adjusted, and +0xa4 TimerHandler adjusted BowGauge RTTI/vtable family with constructor stores, scalar/adjustor slots, OnPaint and OnTimer slots, direct Pane plus Singleton hierarchy, exact HitBar successor boundary, and covered-by marker; compiler regenerates ABI data and no raw arrays emit.

Replace current UID0002YQ row at line 4065:

            - [UID:0002YQ][0x00620b90-0x00620bc0.BowGaugeResourceStrings](by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md) 0x00620b90-0x00620bc0 | string-data | BowGaugeResourceStrings : reconstructable : 92% : very-strong : Exact BGAUGE.EPF and BGAUGE.pal UTF-16 source literals with one OnPaint xref each, exact DEADSIGN.EPF successor boundary, class owner/position 90, and covered-by marker; literals emit through OnPaint and no duplicate raw arrays emit.

Replace current UID0001PY row at line 4451:

    - [UID:0001PY][0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane](by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md) 0x0069ba24-0x0069ba28 | global pointer physical storage | g_pBowGaugeObjectPane : not_reconstructable : 92% : very-strong : Exact four-byte loader-zeroed .data virtual-tail backing slot for BowGaugeObjectPane *g_pBowGaugeObjectPane, current bytes 00 00 00 00 and no file-backed raw initializer; retains exact 13 publish/clear/UserPane lifecycle refs, VA/RVA/pointer negatives and exact Balloon-pool/Parcel-Patch neighbors. Historical ff ff ff ff/0xffffffff is disproved; semantic UID0000QA owns the sole source definition and this physical page emits nothing.

### by-global replacement

Replace current UID0000QA row at line 56:

- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) : reconstructable : 92% : very strong : Sole externally linked BowGaugeObjectPane *g_pBowGaugeObjectPane definition initialized to zero at BowGauge source position 0; physical UID0001PY is loader-zeroed virtual-tail storage and non-emitting. Exact 13-ref map preserves constructor Singleton publication, scalar compiler clear, UserPane cleanup/show/hide/movement consumers, timer wrapper calls, one-definition policy, standalone BowGauge source route, and historical ff/split uncertainty disposition.

### by-class replacements

Replace current UID000011 row at line 63:

- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) : reconstructable : 92% : very-strong : Complete source-ready 0xfc local-player HUD pane deriving directly from Pane and Singleton<BowGaugeObjectPane>, with EBO-overlapped unsigned m_animationStartTick at +0xf8, constructor and inline empty virtual destructor, StartAnimation, RemovePendingTimers, OnPaint, SetAnimationStartTick and OnTimer declarations/children in positions 20-70, external singleton declaration/definition route, BGAUGE.EPF/BGAUGE.pal rendering, exact UserPane consumers, class closure before children, size guard, and explicit compiler-only singleton/vptr/scalar/adjustor/vtable exclusions.

Replace current UID00007B row at line 287:

- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) : reconstructable : 92% : very-strong : Complete source-legal ObjectPane-derived 0x20c LivingObjectPane declaration with typed primary/secondary EffectObjectPane Lists, Balloon/HitBar/DamageNumber/ObjectInfo panes, exact linked-object lifecycle, ObjectStatusBlob/Motion state, protected derived-use fields, MapPane/Motion/BowGaugeObjectPane friendship, nested BoxRotator, 33-wide name storage, source-facing m_objectInfoType at +0x16c, size guard, and child insertion point; BowGauge friendship preserves observed direct m_nameVisible access without layout change or invented getter.

### by-file replacement

Replace current UID0000HU row at line 38:

- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) : reconstructable : 92% : very-strong : Standalone NexusTK/ui/panels/BowGaugeObjectPane.cpp source root with sole external zero-initialized singleton definition at position 0, complete Pane plus Singleton class at 10, constructor/StartAnimation/RemovePendingTimers/OnPaint/SetAnimationStartTick/OnTimer at 20-70, vtable/resource covered markers at 80/90, exact 0xfc EBO layout, UserPane construction/lifecycle consumers, EPF/palette rendering, TimerHandler scheduling/cleanup, source order/includes and one-definition policy. Historical private-UserPane companion uncertainty is bounded; singleton publication/clear, vptrs, scalar delete, adjustors, cookies and raw ABI/data arrays remain compiler-generated.

The current UID0002WU predecessor row remains stale about `ff` bytes but is outside B002's accepted ordinary write scope and is not rewritten by this handoff; its current ordinary page already documents the corrected zero storage. B001 UID0002ZO owns the successor family.

## Follow-Up Actions

1. B002 callback work, ordinary validators, final waited generation, report reconciliation, and lease release are complete.
2. Supervisor independently performs exact-artifact Gate 1/Gate 2 review against this terminal report and the current destinations.
3. The sixteen literal manual coverage actions above remain supervisor-owned and must be applied through the authorized coverage workflow without losing concurrent rows; B002 did not edit coverage.
4. Exact report path, any later coverage epoch, execution, move, archive, and validator-owned lifecycle history are external authority and are not asserted as mutable current state here.

## Confidence

- Physical bytes/range/PE mapping: 99%.
- Pointer type and semantic global identity: 98%.
- Exact 13-reference lifecycle: 99%.
- Direct bases, EBO, field offset, class size: 97%.
- Authored/compiler split: 97%.
- Method behavior and source signatures: 96%.
- Original lexical spellings and standalone filename: 94%.
- Overall recommended confidence score: 94.

## Validator Results

All B002 scoped commands ran from `source-3/project-documentation`, exited 0, and reported `ok:1`. Registration/apply sequence: UID0004VN command `000000016144` at `2026-07-21T18:25:29-04:00`; UID0004VO `16145` at `18:27:11`; UID0004VP initial `16146` at `18:28:42` and corrected dependency revalidation `16147` at `18:29:09`; UID0004VQ `16148` at `18:30:24`; target first/corrective passes `16152` at `18:32:20` and `16153` at `18:33:00`; global `16155` at `18:33:57`; BowGauge class `16156` at `18:35:58`; by-file prose `16157` at `18:37:46`; UID0001DC `16158` at `18:39:58`; UID0004SJ `16159` at `18:41:02`; UID0001DB `16160` at `18:42:14`; historical collided scalar pass `16161` at `18:43:49`; UID0001DL `16162` at `18:45:10`; UID000352 `16163` at `18:46:15`; UID0002YQ `16164` at `18:46:58`; UID00007B `16165` at `18:48:02`; historical waited target refresh `16166` at `18:48:27`. Duplicate-UID repair sequence: missing-UID allocator command `000000016195` at `2026-07-21T19:04:21-04:00` inserted UID0004VR; unchanged canonical JsonCpp UID000380 command `16198` at `19:04:39` restored `88/91`; repaired scalar command `16200` at `19:05:25`; target reference command `16204` at `19:06:10`; BowGauge class command `16205` at `19:06:41`; destructor aggregate command `16208` at `19:07:44`; final waited target command `000000016209` at `19:08:07`.

Command 16147 corrected the OnPaint dependency link from stale UID0000P0 to current UserPane class UID0000FQ. Command 16153 historically removed the target's ambiguous UID000380 link after the validator resolved it to JsonCpp. Command 16161 then exposed the exact callback defect with `duplicate_path_conflict` and `projected_path_skip`; its scan had also polluted canonical UID000380 completion/confidence to BowGauge `92/94`. That state is resolved, not contained: command 16195 used the missing-UID allocator to insert UID0004VR and map it to the BowGauge scalar path; command 16198 restored canonical JsonCpp UID000380 to `88/91`, owner/emitter UID0000KI, reconstructable/import; commands 16200/16204/16205/16208 validated the repaired scalar and every changed BowGauge reference. Registry/header scans find exactly one ordinary UID0004VR page and one ordinary UID000380 page, no duplicate path for either, and reference indexes route BowGauge only to UID0004VR while JsonCpp references remain UID000380. Command 16208 reported the aggregate's 17 pre-existing unrelated `missing_ref_uid` warnings; command 16165 had reported 12 pre-existing unrelated warnings. Commands 16166/16209 reported global pre-existing children-marker/emitter warnings while completing foreground refreshes. No target-specific validator error remains; no validator-owned state was edited manually.

Validator side effects were limited to normal validator-owned registry/reference/completion/confidence/position/code-hash metadata, projected stats, generated coverage/tracker metadata, and generated C++ refreshes. B002 did not directly edit any such output.

B002's final waited proof is command `000000016209`; the latest generated file observed at final report read carries later unrelated command `000000016223`, SHA256 `333F81AE0DA5F21DF93636127C0445A2A4A0422B104150C04F4372DB72DCF8C0`, 3,800 bytes/111 lines. Independent readback still finds exactly one `BowGaugeObjectPane *g_pBowGaugeObjectPane = 0;`, one complete direct `Pane` plus `Singleton<BowGaugeObjectPane>` class, one constructor, and one each `StartAnimation`, `RemovePendingTimers`, `OnPaint`, `SetAnimationStartTick`, and `OnTimer`, in positions 0-70. UID000352 and UID0002YQ markers occur once each. There are zero Empty Emitter Markers, scalar-deleting definitions, adjustor definitions, handwritten RTTI/vtable arrays, duplicate global definitions, or duplicate resource arrays. The class closes and its `0xfc` size guard precedes child insertion. UID0004VR is correctly absent from generated source because its page is false/non-emitting.

## Changed Files

- B002 changed only this report and the accepted ordinary destinations below. Four method pages were validator-issued new children during the original callback; the repair changed the scalar page identity/provenance plus three BowGauge references. Each ordinary lease was released immediately after scoped validation; final waited generation ran lease-free. Canonical JsonCpp UID000380 was revalidated read-only at unchanged page SHA256 `A4DBD8F054F1ECE98E8F67E5C33AC47783472B7FF0A474BF2942B3B78D329980` (8,046 bytes/85 lines).
- Read-only Destination 17 remained byte-identical: `by-class/UserPane.md` `F14644F980487F915D6EB0AC5CD00D8BA5A0D42583EFACFD6F90BF148F692F4B`; `by-file/UserPane.md` `4650C9DB50AAB98A97F39B0CC7B6F025F74F0278FF44293D8AE070E9B2442109`; `by-memory/0x005a2530-0x005b8395.UserPane.md` `151BA81756A0A35C9CEC7E765055458CADE4EB2D05BDF6FE4850F4704133DAD9`.
- Active B001 successor UID0002ZO and every Parcel/Patch page starting at `0x0069ba28` were not leased or edited. No manual coverage, generated/tracker/audit/supervisor/validator-state/IDA/lifecycle/archive file was directly edited.
- Lifecycle is supervisor/validator-owned. This B002-authored checkpoint asserts implementation completeness and zero leases, not later execution/move/archive state.

Final ordinary destination hashes:

| Path | SHA256 | Bytes / lines | Applied disposition |
| --- | --- | --- | --- |
| `by-memory/0x0069ba24-0x0069ba28.g_pBowGaugeObjectPane.md` | `800D080E300E186E4A5170D9A71BB03220E0E3B92DCF934E3713A059CDD882A6` | 12,834 / 127 | D1 physical/non-emitting; UID0004VR reference |
| `by-global/g_pBowGaugeObjectPane.md` | `3113D41C2A5B955FD91082AE83BD7553172801C2BF34D2C34155BF2FB0E3A0DA` | 9,363 / 85 | D2 sole definition |
| `by-class/BowGaugeObjectPane.md` | `4A832F71221170A22129DFE040E24B45E5E16A323683B35A29A365CCCD797842` | 22,773 / 177 | D3 complete class; UID0004VR references |
| `by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md` | `8CA8F8931B7393E2C78E23643B32B26078F036C8BBB7BB2FE3F9BDFFBC68787E` | 5,677 / 74 | D4 UID0004VN |
| `by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md` | `14FC1B837AE950AEC1458631E2B8D960F63B0DE8801619D8CC89907F73603D3A` | 5,595 / 79 | D5 UID0004VO |
| `by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md` | `B1A0E13D7798C22E80FA6067408A0E6B2CEC1F6793BE1B6CA630E6B65401CF8C` | 9,255 / 97 | D6 |
| `by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md` | `E225B66A613CF47E48EF3FA6CE8F739DC6FF32E5115558602B8DC367DF001C59` | 6,791 / 103 | D7 UID0004VP |
| `by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md` | `5B3941CEC9970CB9FDFF5D6F085E5039B495B742915EA998882B1D030A7CEBEA` | 5,952 / 78 | D8 |
| `by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md` | `380CDC7C8A79FDC256CA98CB03894F5CA9C20F5C7C29FB1A885B57821240D404` | 5,224 / 75 | D9 UID0004VQ |
| `by-memory/0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor.md` | `249BC23D73BF1A9BFACDF4C09CBD5120AA88DDD56400A594F5A94E00F440D95C` | 6,556 / 64 | D10 UID0004VR compiler-only; duplicate resolved |
| `by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md` | `CF6469C89E48E77E3AA718486C6AC25933ED6A52571A95D28E38DCCD581D531E` | 11,802 / 119 | D11 marker |
| `by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md` | `01F7FF56B7D52B6091F0BCD090506EA3AC875EE70568819B64BED409D417B224` | 4,421 / 64 | D12 marker |
| `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md` | `D761F31CF0D7E8325EB0212607BFC4F8CE7A17364DC7D557748C27607F7394CA` | 24,192 / 129 | D13 inventory |
| `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md` | `945432F5D45880FFAE40E84E04AF9ECDE2A4E90A9A39D9D32D002EFD3EA0F93A` | 19,447 / 116 | D14 inventory; UID0004VR child |
| `by-class/LivingObjectPane.md` | `098D288A9C64DA19DC77C871F738247A473CD4D7A23D4B046B045DC7F669B30E` | 130,776 / 672 | D15 bounded friend |
| `by-file/BowGaugeObjectPane.md` | `A070C2E69E36BCD7942E74008AEB53CBB83136703A7C9231813445DDA29F518D` | 20,661 / 147 | D16 prose only |

## Implementation Tracking Checklist

### Research and callback completion checks

- [x] Confirm exact provenance headers and all 33 literal H2 headings.
- [x] Confirm mandatory live MCP idb_list, health, and bounded target bytes.
- [x] Confirm PE raw-versus-virtual arithmetic and executable hash.
- [x] Confirm target, predecessor, and successor exact half-open bounds.
- [x] Confirm central/active/legacy/invalidated/Older-Research root searches and outcomes.
- [x] Confirm current B001-B005 assignment and lease collision inventory.
- [x] Confirm C01-C40 use permitted Action values and legal terminal verification states with destination proof.
- [x] Confirm all fifteen managed formal destinations include literal `[[[]]]`, BEGIN, and END lines.
- [x] Confirm no source C++ draft exists outside managed destination blocks.
- [x] Confirm sixteen exact no-loss manual actions against current rows.
- [x] Confirm only accepted ordinary/report edits, zero prohibited direct edits, and zero B002 leases on return.

### Claim implementation obligations

- [x] C01 exact four-byte range.
- [x] C02 zero bytes/hash.
- [x] C03 PE virtual-tail mapping.
- [x] C04 historicalize stale ff/0xffffffff.
- [x] C05 exact neighbors.
- [x] C06 exact 13 references.
- [x] C07 constructor Singleton lowering.
- [x] C08 scalar clear lowering.
- [x] C09 UserPane lifecycle consumers.
- [x] C10 negative pointer routes.
- [x] C11 physical-versus-semantic ownership.
- [x] C12 exact global type/name.
- [x] C13 external linkage.
- [x] C14 one definition/order.
- [x] C15 direct base hierarchy.
- [x] C16 EBO/size/field.
- [x] C17 constructor source body.
- [x] C18 destructor source/compiler split.
- [x] C19 StartAnimation body.
- [x] C20 RemovePendingTimers body/callers.
- [x] C21 OnPaint body.
- [x] C22 resource literals.
- [x] C23 uninitialized composite/no checks/cleanup.
- [x] C24 tick setter.
- [x] C25 OnTimer supersedes OnShow.
- [x] C26 inherited TimerHandler facet.
- [x] C27 compiler ABI exclusions.
- [x] C28 UID0004VR scalar false/no-code proof plus rejected historical BowGauge UID000380 identity.
- [x] C29 resource covered marker.
- [x] C30 standalone BowGauge route.
- [x] C31 UserPane verify-only union.
- [x] C32 aggregate/padding inventory with unique UID0004VR child route.
- [x] C33 scores/metadata.
- [x] C34 final waited command-16209 generated snapshot and earlier epochs historicalized.
- [x] C35 intended generated counts/order.
- [x] C36 old-report provenance retained.
- [x] C37 LivingObjectPane friendship.
- [x] C38 rejected alternatives preserved.
- [x] C39 manual coverage handoff rebased.
- [x] C40 callback plus duplicate-UID repair completion boundary and external lifecycle ownership.

### Destination and callback obligations

- [x] Apply Destination 1 UID0001PY exactly and scoped-validate/release.
- [x] Apply Destination 2 UID0000QA exactly and scoped-validate/release.
- [x] Apply Destination 3 UID000011 exactly and scoped-validate/release.
- [x] Register Destination 4 constructor child serially as UID0004VN and verify every placeholder replacement.
- [x] Register Destination 5 StartAnimation child serially as UID0004VO and verify every placeholder replacement.
- [x] Apply Destination 6 UID0001DC preserving its accepted body.
- [x] Register Destination 7 OnPaint child serially as UID0004VP and verify every placeholder replacement.
- [x] Apply Destination 8 UID0004SJ position while preserving its body.
- [x] Register Destination 9 OnTimer child serially as UID0004VQ and verify every placeholder replacement.
- [x] Apply Destination 10 UID0004VR exact non-emitting representation; preserve UID000380 only as resolved JsonCpp-owned history.
- [x] Apply Destination 11 UID000352 marker and full ABI evidence.
- [x] Apply Destination 12 UID0002YQ marker and literal evidence.
- [x] Apply Destination 13 UID0001DB child/padding inventory.
- [x] Apply Destination 14 UID0001DL scalar-child/compiler inventory.
- [x] Apply Destination 15 UID00007B complete no-loss formal plus BowGauge forward/friend.
- [x] Apply prose-only Destination 16 UID0000HU with no by-file reconstruction metadata.
- [x] Verify read-only Destination 17 UserPane class/file/aggregate or document concrete drift.
- [x] Reread/rebase every destination immediately after its lease is acquired.
- [x] Run and record one scoped validator per changed ordinary page.
- [x] Release each ordinary lease immediately after its validator.
- [x] Confirm no placeholder remains after validator-issued UID registration.
- [x] Run final authorized waited BowGauge generated refresh with zero leases.
- [x] Verify exactly one `g_pBowGaugeObjectPane` definition and one complete class.
- [x] Verify exactly one constructor, StartAnimation, RemovePendingTimers, OnPaint, SetAnimationStartTick, and OnTimer definition in positions 20-70.
- [x] Verify one vtable covered marker and one resource covered marker.
- [x] Verify no UID0001PY/UID0000QA/UID0002YQ Empty Emitter Marker.
- [x] Verify no handwritten scalar destructor, adjustor thunk, vtable/RTTI array, or duplicate resource array.
- [x] Verify class closing brace and size guard precede `[[CHILDREN]]`.
- [x] Reread current manual rows and preserve all concurrent facts in the sixteen-row handoff.
- [x] Confirm supervisor-owned manual coverage remains external and unapplied by B002.
- [x] Confirm report execution/move/archive remain entirely supervisor-owned.
- [x] Terminalize C01-C40 only after exact destination and generated proof exists.
- [x] Update Validator Results, Changed Files, hashes, generated assertions, and checklist after callback.
- [x] Return callback artifact with zero leases and no prohibited edits.

### Duplicate-UID repair obligations

- [x] Remove only the invalid BowGauge UID000380 header under lease and obtain validator-allocated UID0004VR through command 16195.
- [x] Prove exactly one ordinary UID0004VR header/mapping and exactly one canonical JsonCpp UID000380 header/mapping, with no duplicate ordinary page for either.
- [x] Revalidate unchanged canonical JsonCpp UID000380 through command 16198 and prove restored `88/91`, owner/emitter UID0000KI, reconstructable import state.
- [x] Migrate BowGauge-specific scalar references in the target, class, and destructor aggregate to UID0004VR under serial leases and validators 16204/16205/16208.
- [x] Revalidate repaired scalar UID0004VR through command 16200 and preserve exact `92/94`, owner UID000011, false/non-emitting, blank formal state.
- [x] Rebase the sixteen supervisor-owned manual actions so the scalar addition uses UID0004VR and canonical JsonCpp UID000380 remains untouched.
- [x] Run final lease-free waited command 16209, reconfirm generated assertions, release every B002 lease, and record no prohibited direct edits.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000016269","destination_path":"executed-b-agent-research/B002/0001PY-g_pBowGaugeObjectPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001PY-g_pBowGaugeObjectPane-source-quality.md","timestamp":"2026-07-21T19:30:10-04:00","uid":"0001PY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
