# UID0000N5 ResourceLayoutTable Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000N5 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain a narrow standalone `NexusTK/render/ResourceLayoutTable.cpp` and required sibling `ResourceLayoutTable.h` for exactly two externally linked no-`this` raw helpers, while retaining nine class/facet methods on the concrete `ImageLib` object in `ImageLib.cpp/.h`.
- Final disposition: make UID0000N5 source-complete and reconstructable at `95/93`; replace its empty emitter and private/static raw-record fragment with two complete externally linkable definitions and declarations.
- Required support disposition: correct four emitted `ImageLib` method bodies/signatures, add recovered no-xref method `[0x004d1830,0x004d1860)`, move row declarations into `ImageLib.h`, correct caller includes/access, and extend same-UID aggregate UID000174 through `0x004d1860`.
- Confidence: very strong for behavior, ABI, ranges, ownership, declarations, and generated closure; strong for the inferred original raw-helper filename and no-xref method name.

## Supporting Research

- This is the complete whole-file/source-family pass, not a sample of the two children already routed to UID0000N5.
- Live IDA was read through canonical session `supervisor_uid0000md_persistverify_20260816`, attested 2026-08-16 at `11:02:58Z` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Session identity is dated evidence; Gate 2B must enumerate and attest the then-active canonical session again.
- The 2026-08-17 Gate 2B repair enumerated sole active session `supervisor_uid0000n5_postdiscard_20260817`, runtime-attested the same canonical IDB at `2026-08-17T14:08:51.643994Z`, and received bounded health `status:ok`, image base `0x400000`, Hex-Rays/string cache ready with 2,068 entries, and non-blocking `auto_analysis_ready:false`. Fresh read-only item/function/frame/comment/byte/xref queries prove the failed unsaved worker was discarded and the raw I01 prestate is restored.
- Matching reports read as leads were B001 UID000174, B011 UID0000K2, B010 UID0002KQ, B013 UID0002KT, B004 UID00031T, and B013 UID00031U. Current docs, generated output, and live bytes supersede stale conclusions.
- The source family is eleven authored functions: nine `ImageLib`/`ResourceLayoutTable` facet methods and two no-`this` raw helpers. Ten are current IDA functions; the eleventh is complete 48-byte retained code at `0x004d1830` that IDA has decoded but not defined as a function.
- Corrected mixed band `[0x004d0120,0x004d1860)` is 5,952 bytes, SHA256 `7C8447664D714D5C45F451BB894D7D7C1EE557DD6433229970D9BBC4ED3D8897`.

## Target

- Target UID: `0000N5`.
- Additional target UIDs: none. Other UIDs are support destinations, exclusions, or a callback-created child under existing ownership.
- Target path: `by-file/ResourceLayoutTable.md`.
- Report path: `tools/leaser/Agents/Agent-B001/research/0000N5-ResourceLayoutTable-file-source-quality.md`.
- Assignment row: `88/86`, owner `FILE`, path `NexusTK/render/`, blank tracker reconstructability, zero reports.
- Inferred compilation unit: UID0002KQ then UID0002KT in address/source order. Class methods remain in `ImageLib.cpp`; decoder/frame helpers remain in established files.

## Current Target State

- UID0000N5 is implemented at `95/93` as the exact two-helper `NexusTK/render/ResourceLayoutTable.cpp/.h` module. The prior open split and incomplete aggregate end `0x004d182f` remain only as dated pre-callback history.
- The eleven in-scope definitions are individually identified as UID0002KO `[0x004d0120,0x004d02e5)`, UID0002KP `[0x004d02f0,0x004d039e)`, UID0002KQ `[0x004d03a0,0x004d04d0)`, UID0002KR `[0x004d04d0,0x004d0522)`, UID0002KS `[0x004d0530,0x004d059b)`, UID0002KT `[0x004d05a0,0x004d05e6)`, UID0002P6 `[0x004d1600,0x004d165d)`, UID0002KU `[0x004d1730,0x004d1773)`, UID0002KV `[0x004d1780,0x004d17b3)`, UID0002KW `[0x004d17c0,0x004d182f)`, and callback-created UID00054V private GetEntry `[0x004d1830,0x004d1860)`.
- The eleven separately excluded definitions are ImageLoaders children UID0002TJ `[0x004d05f0,0x004d0723)`, UID0002TK `[0x004d0730,0x004d07a3)`, UID0002TL `[0x004d07b0,0x004d09a7)`, UID0002TM `[0x004d09b0,0x004d0a8a)`, UID0002TN `[0x004d0a90,0x004d0c58)`, UID00032P `[0x004d0c60,0x004d0d89)`, and UID00032O `[0x004d0d90,0x004d0f4a)`, plus ImageFrameTable children UID0002P4 `[0x004d0f50,0x004d15c5)`, UID0002P5 `[0x004d15d0,0x004d15fc)`, UID00031T `[0x004d1660,0x004d1704)`, and UID00031U `[0x004d1710,0x004d172d)`. Each remains reconstructable in its own owner and is excluded only from ResourceLayout source.
- The twenty internal non-source gaps are `[0x004d02e5,0x004d02f0)` 11 bytes, `[0x004d039e,0x004d03a0)` 2, `[0x004d0522,0x004d0530)` 14, `[0x004d059b,0x004d05a0)` 5, `[0x004d05e6,0x004d05f0)` 10, `[0x004d0723,0x004d0730)` 13, `[0x004d07a3,0x004d07b0)` 13, `[0x004d09a7,0x004d09b0)` 9, `[0x004d0a8a,0x004d0a90)` 6, `[0x004d0c58,0x004d0c60)` 8, `[0x004d0d89,0x004d0d90)` 7, `[0x004d0f4a,0x004d0f50)` 6, `[0x004d15c5,0x004d15d0)` 11, `[0x004d15fc,0x004d1600)` 4, `[0x004d165d,0x004d1660)` 3, `[0x004d1704,0x004d1710)` 12, `[0x004d172d,0x004d1730)` 3, `[0x004d1773,0x004d1780)` 13, `[0x004d17b3,0x004d17c0)` 13, and `[0x004d182f,0x004d1830)` 1; every byte is `0xcc`, every span has blank CPP/H, and none emits.
- Type/data disposition is explicit: UID0000VB ResourceLayoutEntry is the single 24-byte entry declaration; UID0001VT ResourceLayoutNameRecord is the single 44-byte registry-row declaration and the exact GFACE type because the branch reads its `entryCount` at `+0x20` and `entries` at `+0x28`; undefined `ResourceLayoutRecord` is rejected rather than emitted. UID000079/UID0000KS supplies the complete `List`/`GetElementAt` H dependency needed by the compiler-covered accessor. UID0001US is the 0x14 ImageLib layout; UID0001VU ResourceLayoutStore and UID0001VS ResourceLayoutBucket remain non-emitting aliases; UID0000QU is the semantic `g_pEPFLib` declaration route and UID0001OQ is its sole four-byte storage at `0x0067a744`; UID0000UN supplies ArchiveMetadataTable/FrameDrawRecord declarations; no second ResourceLayout object, global, vtable, RTTI, string, constant, table, or data island exists.
- Related support routes are individually bounded: target UID0000N5; aggregate UID000174; class/file owners UID0000BY/UID00006E/UID0000K2; List dependency UID000079/UID0000KS; UserLook UID0003RK/UID0000P0; NewHuman UID0002V8/UID000092/UID0000LR; Riding UID0000BZ/UID0000N6; decoder aggregate/file UID000175/UID0000K3; frame aggregate/file UID000176/UID0000K1; item mirrors UID0000UX/UID0000UY; and successor-only MapTile pages UID0002IZ/UID000177/UID00007T/UID0000L5. Section 14 gives each its own disposition.
- Dated generated snapshot command `000000024889` at `2026-08-16T06:59:47-04:00` and the 2026-08-16 repair readback show `ResourceLayoutTable.cpp` has UID0002KT before UID0002KQ, KT is incorrectly `static` with duplicate `ResourceLayoutRawRecordTable`, KQ is an Empty Emitter Marker, and `ResourceLayoutTable.h` is absent. `ImageLib.cpp/.h` has eight methods, wrong KO/KP/KS/KW source, late duplicate structs and no GetEntry. `UserLookPane.cpp` has a local KQ declaration; `NewHumanImageLib.cpp` has two undeclared KT calls using stale `m_rawRecordTable`; `RidingImageLib.cpp` contains private `ridingEpfPackage` but no friendship and no generated H. These are dated evidence; Gate 2A rereads the latest validator-owned output dynamically.
- Section 22's complete dependency chain is implemented: UID0002V8 has literal `ImageLib.h`/`ResourceLayoutTable.h`/`RidingImageLib.h` includes, exact `ResourceLayoutNameRecord` GFACE access through public Find and the inline accessor, and both exact `ridingEpfPackage` operands; UID00006E H includes `List.h`, owns the sole row declarations, exposes Find/accessor legally, and keeps `GetEntry`/storage private; UID0000BZ CPP is an owner-H include plus `[[CHILDREN]]` with no class/extern redeclaration; and UID0000BZ H is the sole complete guarded Riding class/API/field/extern declaration with narrow friendship before private storage. Dated callback generated readback proves this complete chain; later lifecycle actions reread validator-owned output dynamically.
- A newer dated repair readback at validator command `000000025126` (`2026-08-16T10:19:10-04:00`) exposed the remaining GFACE compile defects without changing binary evidence: generated `NewHumanImageLib.cpp` SHA256 `B78C74212DFC6130E6D68B52FAA4FF7D126F23AAD88DC85302CD8D66F3056F84` uses undefined `ResourceLayoutRecord` and undeclared `GetResourceLayout` while calling private `FindResourceIndex`; generated `ImageLib.h` SHA256 `20F5BC2213108BC4EC4EA9CF7BED9105B25C0588458D9C68C9EF80EDFCDBE2B9` forward-declares `List`, keeps Find private, and has no accessor. These are dated snapshots only; Gate 2A and later lifecycle actions reread generated authority dynamically.
- At the report's dated generated readback, excluded-owner status was also explicit: `ImageLoaders.cpp` contained all seven decoder definitions and no Empty Emitter Marker while `ImageLoaders.h` was absent; `ImageFrameTable.cpp` contained UID0002P4, UID0002P5, UID00031T and UID00031U, and `ImageFrameTable.h` carried shared ArchiveMetadataTable/FrameDrawRecord types. P6 appeared only in `ImageLib.cpp`, and MapTile successor output began separately at `0x004d1860`. These are dated evidence; Gate 2A and later lifecycle actions reread generated authority dynamically.
- The preceding defective generated identities are explicitly dated pre-callback evidence. At callback completion, all 16 destinations were physically reread: ResourceLayoutTable CPP/H are complete; ImageLib CPP/H contain nine address-ordered facet definitions plus one H-only accessor and no late duplicate structs; UserLook CPP has one owner include/call and its H remains intentionally absent; NewHuman CPP/H are complete with legal GFACE/Riding routes; Riding CPP/H have one owner declaration and no CPP duplicate; ImageLoaders remains seven-definition/CPP-only; ImageFrameTable remains four-definition/shared-H with no P6 duplicate; and MapTile remains the separate successor with no H. Exact dated hashes and validator metadata are in Section 31; later lifecycle authority is reread dynamically.
- Complete inventory totals are 11 in-scope executable definitions, one compiler-covered H-only registry-row accessor, 11 excluded definitions, 20 internal gaps, 32 type/data/support-page routes including the two List dependency owners, and 16 generated CPP/H destinations. Lifecycle authority is the current path plus validator-owned status/history; the body makes no current execute/archive assertion.
- Dated Gate 2B history: the supervisor's first I01 `define_func` attempt created the correct `[0x004d1830,0x004d1860)` function but public `stack_frame` returned only `__saved_registers` and `__return_address`, not the report's predicted `arg_0`/`arg_4`. The supervisor hard-stopped before I02-I11, made no IDB save, discarded the unsaved worker, and freshly reopened canonical raw prestate. The repaired handoff accepts that evidence-backed two-row post-I01 frame and requires no type action.

## Executive Recommendation

UID0000N5 owns the implemented narrow raw-helper module. KQ and KT have stack-only `__stdcall` ABIs and cross-file callers, do not consume `this`, and are externally linked in the separately generated source. Caller ownership is weaker than shared ResourceLayout-format ownership.

UID0000BY/UID00006E own nine out-of-line class/facet methods through `ImageLib.cpp/.h`, plus public H-only `GetResourceLayout(int) const` compiled into callers. One concrete `ImageLib` object, private `List *m_pEntryList` at `+0x0c`, `g_pEPFLib`, and one lifecycle/vtable are proven; no independent ResourceLayout object is. The 13 direct Find calls include nine external Human/NewHuman sites, so `FindResourceIndex` is public; zero-xref UID00054V `GetEntry` remains private.

KQ's blocker is resolved by faithful reconstruction, not repair: non-zeroing allocation, only row zero initialized, `entries[1].pixelData` read for mask length, and allocation leaked. Source must preserve those historical behaviors and reject invented loop/sentinel/zero-fill/free/guards.

## Supervisor Active Recheck

- Supervisor assigned UID0000N5 after UID0002NC archival and required live canonical MCP.
- Split repair was required: no-`this` ownership was directionally correct, but linkage, header, source correctness, and the post-`0x004d182f` method were unresolved.
- Every source-bearing member now has formal CPP/H, an existing no-change body, a new-child disposition, or an exact exclusion/no-code reason.
- Dated 2026-08-16 repair readback enumerated active canonical session `supervisor_uid0000md_persistverify_20260816`; runtime attestation succeeded for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at `2026-08-16T12:36:52.423907Z`, and bounded health reported `status:ok`, image base `0x400000`, Hex-Rays ready, string cache ready with 2,068 entries, and `auto_analysis_ready:false` (which is non-blocking while bounded IDB queries succeed).
- Fresh item/function/frame/comment/byte/xref reads corrected stale literal declarations, frame-member spellings, and nine earlier body hashes in the IDA handoff. The replacement hashes below were independently identical for raw MCP bytes and section-mapped executable bytes under .NET SHA256; the earlier values were extraction errors, not binary changes. The `0x004d1830` and protected P6 hashes were already correct.
- The 2026-08-17 failed-I01 receipt resolves the only later handoff defect: public `define_func` deterministically created the exact 0x30-byte function with type absent and a two-row, zero-local frame. I02-I11 were not run, no save occurred, and fresh session `supervisor_uid0000n5_postdiscard_20260817` proves canonical raw prestate restored before this report-text repair.

## Inference Research Guidance Check

- IDA facts: ranges, bytes/hashes, ABIs, frame rows, instructions, comments, xrefs, and receiver fields.
- Documentation facts: accepted `List`, `EPFTileContext`, `ArchiveMetadataTable`, `FrameDrawRecord`, and row types.
- Inference is limited to original filenames, descriptive names, typedef spelling, and private placement; scores are capped accordingly.
- Rechecked assumptions: separate file, `static` KT, duplicate raw type, pointer returns, Open guard, seek origin, repeated List lookup, old aggregate end, and no source after `0x004d182f`.
- Wave2/Wave3 text was historical context only, not current authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Disposition |
| --- | --- | --- |
| Standalone file versus ImageLib | KQ/KT are external no-this helpers; methods use ImageLib `+0x0c`. | Two-helper `ResourceLayoutTable.cpp/.h` plus nine methods in `ImageLib.cpp/.h`. |
| KQ next-row blocker | One row initialized after non-zeroing allocation; row-one pixel pointer then read. | Emit bug/leak exactly; reject safety inventions. |
| KT raw type/linkage | Accesses match `ArchiveMetadataTable`; 28 outside callsites. | Reject duplicate struct/static; external declaration. |
| KO source | Binary ignores Open result, seeks `(offset,1)` then `(0,0)`, reads four signed shorts. | Replace formal body. |
| KP/KS return | Binary/source behavior is `void`; EAX is incidental. | Correct CPP/H; preserve stale IDA types until separate safe type work. |
| KW traversal | One `GetElementAt(0)` then `+44` pointer progression. | Replace generated repeated calls. |
| Tail code | Prologue, two `retn 8` exits, List call, signed test, 24-byte row math. | Create private `GetEntry(int,int)` child. |
| GFACE row type | Exact branch reads row `+0x20` and `+0x28`; UID0001VT has those fields in the List(44,10) row. | Use `ResourceLayoutNameRecord`; reject undefined/distinct `ResourceLayoutRecord`. |
| GFACE row access | After Find/Load, instructions `0x4e3421-0x4e3427` load `this+0x0c` and call List vtable slot `+0x10`; no direct accessor function call exists. | Define public in-class `GetResourceLayout(int) const`; include `List.h`; emit no out-of-line body/UID. |
| Find access control | Four of 13 calls are facet-internal; nine are Human/NewHuman composition sites or raw islands. | Declare `FindResourceIndex` public; reject private access and broad multi-class friendship. |
| Class identity | No ResourceLayout lifecycle/vtable/RTTI/storage/global. | Preserve concrete ImageLib plus compatibility alias. |
| Header closure | Structs emit after use; raw module has no H; GFACE lacks `ImageLib.h`; inline List call requires a complete List declaration. | Complete owner headers; add `ImageLib.h` to UID0002V8 and `List.h` to ImageLib H. |
| Caller field | NewHuman binary directly reads RidingImageLib `+0x0c`. | Use `ridingEpfPackage` with narrow friendship. |
| Neighbor ownership | Independent callers/formats/owners defeat adjacency. | Exclude all decoder/frame helpers except P6 method. |

Rejected: standalone ResourceLayout class, caller-owned statics, moving raw helpers into ImageLib, safe KQ rewrite, preserving KT static/duplicate type, preserving pointer returns/old endpoint, and classifying `0x4d1830` as padding.

## Evidence Standards Used

- Primary: live canonical MCP item/function/decompile/disasm/frame/comment/xref/byte reads plus independent SHA256.
- Corroboration: current by-* docs, generated CPP/H, accepted headers, caller source, and matching reports.
- Negative: zero data xrefs to starts, no KQ/KT `this`, no ResourceLayout lifecycle/object, no `0x4d1830` xrefs, no distinct `ResourceLayoutRecord` declaration, no direct `GetResourceLayout` function/call, exact `cc` gaps, desired-name noncollision.
- Confidence is below symbol certainty only for lost source spelling/placement details.

## Evidence Checked

- Enumerated IDB sessions before MCP; attested canonical path and healthy worker/Hex-Rays.
- Queried all eleven starts, neighbors, profiles, bodies, frames, four comment channels, bytes/hashes, xrefs, and name collisions.
- Fetched all 440 KP and all 81 P6 inbound code xrefs; did not mistake a paged subset for completeness.
- Read UID0000N5, 0000BY, 0000K2, 00006E, 000174, 0002KO-KW, 0002P6, 0001VT, 0000VB, 0001VU, 0001VS, 0001US, 0000QU/0001OQ, 000079/0000KS, 0003RK, 0002V8, 000092/0000LR, 0000BZ, and neighboring decoder/frame pages.
- Read generated ResourceLayoutTable, ImageLib, EPFTileContext, ImageFrameTable, MemoryMan, List, RectBounds, NewHumanImageLib, and RidingImageLib outputs.
- Gate 1 repair reread every exact decoder/frame child and owner page, all 20 gap spans, every type/data/item/file/class/boundary support route, and all 16 generated CPP/H destinations; generated identities/statuses are dated 2026-08-16 evidence rather than continuing authority.
- An independent raw executable direct-call scan reconfirmed all 81 P6 inbound code references listed literally in Section 21; the accepted live IDA prestate remains authority for P6 name/declaration/frame/comments/range/hash and zero data refs/callees.
- Read current manual coverage rows in all affected roots and searched reports, assignments, tracker, and leases by UID/address/name.
- Dated 2026-08-16 read-only MCP session `supervisor_uid0000nj_reportrepair_20260816` was selected only after fresh `idb_list`; health was `status:ok`, canonical IDB path matched, Hex-Rays/string cache were ready, and bounded queries succeeded despite non-blocking `auto_analysis_ready:false`. Decompile/disassembly proved the exact GFACE lowering at `0x4e33f3-0x4e344f`; `xrefs_to 0x004d17c0` returned all 13 direct calls. Session identity is a dated receipt, and every later Gate rediscovers runtime authority dynamically.
- Project searches for `ResourceLayoutRecord` and `GetResourceLayout` found only the stale UID0002V8 source/report route; the accepted 44-byte UID0001VT declaration and complete UID000079 `List::GetElementAt(int)` contract are the only source-facing types/APIs matching the instructions.
- During the initial report-only research pass, no validator, IDA mutation/save, manual coverage edit, direct generated-file edit, lifecycle command, or execute-report command ran. During the accepted implementation callback, B001 ran only the scoped file validators listed in Validator Results; no IDA mutation/save, manual coverage edit, direct generated-file edit, lifecycle command, or execute-report command ran in either phase.

## Claim And Incorporation Ledger

Post-implementation allocation: 112 checked / 14 unchecked. C01-C43 and C58-C126 are `applied`, `already-present`, or `excluded-with-reason` as physically implemented/verified; only supervisor-owned C44-C57 remain `proposed`. Section 33 is the exact eight-field twin after removing `Done`.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0000N5 | Raise whole-file score `88/86 -> 95/93` and record a complete reconstructable two-helper CPP/H module. | Very strong | Complete source, caller, type, split, and generated audit. | UID0000N5 metadata/Status | incorporate | applied |
| C02 | 0000N5 | Retain standalone `NexusTK/render/ResourceLayoutTable.cpp/.h` only for UID0002KQ then UID0002KT in address/source order. | Very strong | Both are external no-this helpers; class methods use ImageLib receiver. | UID0000N5 ownership/source inventory | incorporate | applied |
| C03 | 0000N5 | Record exhaustive family as nine ImageLib-facet methods plus two raw helpers, with no family-owned global/static/table/string/vtable/RTTI item. | Certain | Complete function/data/type/xref search. | UID0000N5 complete inventory | incorporate | applied |
| C04 | 000174 | Correct same-UID path/range to `[0x004d0120,0x004d1860)`, 5,952 bytes, SHA256 `7C8447664D714D5C45F451BB894D7D7C1EE557DD6433229970D9BBC4ED3D8897`. | Certain | Fresh raw MCP read and independent hash. | UID000174 identity/range/history | reject-stale | applied |
| C05 | 000174 | Preserve all 20 internal `0xcc` gaps and exact included/excluded child map; aggregate remains non-emitting. | Certain | Complete byte/boundary inventory. | UID000174 split/padding inventory | incorporate | applied |
| C06 | 0002KQ | Emit exact raw-buffer parser, including one-row initialization, non-zeroing allocation, row-one mask-length read, and unreleased allocation. | Certain | Exact 304-byte body/decompile/callees. | UID0002KQ formal CPP/behavior/history | incorporate | applied |
| C07 | 0002KQ | Replace unresolved blocker with faithful historical-bug rationale; reject loop, sentinel, zero-fill, free, and new guards. | Very strong | Negative instruction/callee evidence. | UID0002KQ source-quality/history | reject-stale | applied |
| C08 | 0002KQ | Centralize complete ResourceLayoutTable.h in UID0002KQ formal H with both external declarations; set position 10. | Very strong | Required cross-file declarations and header absence. | UID0002KQ formal H/emitter position | incorporate | applied |
| C09 | 0002KT | Replace static duplicate-table source with external `RectBounds *__stdcall` over `const ArchiveMetadataTable *`; position 20 and blank H centralization rationale. | Certain | ABI, 28 callers, accepted table layout. | UID0002KT formal CPP/H/metadata | reject-stale | applied |
| C10 | 0002KO | Correct loader to ignore Open result, seek `(offset,1)` then `(0,0)`, read four signed shorts, preserve sentinel/rebase/append and count-minus-one. | Certain | Live decompile and exact calls. | UID0002KO formal CPP/behavior/history | reject-stale | applied |
| C11 | 0002KP | Change LookupLayoutEntry CPP/H return to void, preserve 32-bit source frame index, mapping, next-row mask formula, and InitRectBounds failure. | Certain | Live type/body and 440 callers. | UID0002KP formal CPP; UID00006E H | reject-stale | applied |
| C12 | 0002KR | Preserve exact stack EPFTileContext initialize/void lookup/conditional CopyTo wrapper. | Certain | 82-byte body and 25 calls. | UID0002KR behavior/formal CPP | already-present | already-present |
| C13 | 0002KS | Change GetEntryRect CPP/H return to void and preserve lazy lookup, signed test, 16-byte copy, and InitRectBounds failure. | Certain | Live 107-byte void body and 11 calls. | UID0002KS formal CPP; UID00006E H | reject-stale | applied |
| C14 | 0002P6 | Preserve LoadFrameDrawRecord, including invalid pointer-only clears and next-record payload-span read. | Certain | 93-byte body, exact type, 81 calls. | UID0002P6 behavior/formal CPP | already-present | already-present |
| C15 | 0002KU | Preserve lazy frame-size lookup and record `+0x22/+0x24` copies. | Certain | 67-byte body and sole caller. | UID0002KU behavior/formal CPP | already-present | already-present |
| C16 | 0002KV | Preserve lazy lookup and unsigned 16-bit count return. | Certain | 51-byte body and six calls. | UID0002KV behavior/formal CPP | already-present | already-present |
| C17 | 0002KW | Replace repeated generated GetElementAt calls with one `GetElementAt(0)` and 44-byte pointer walk. | Certain | Live 111-byte decompile. | UID0002KW formal CPP/history | reject-stale | applied |
| C18 | 0000BY | Create exact child `[0x004d1830,0x004d1860)` for private `ResourceLayoutEntry *GetEntry(int,int)`, parent UID0000BY, position 110. | Very strong | 48 bytes, two exits, List slot, row math. | New by-memory child; UID0000BY inventory | incorporate | applied |
| C19 | 00006E | Replace `ImageLib.h` with its `List.h` dependency, both row structs before class use, public `FindResourceIndex`, inline compiler-covered `GetResourceLayout`, corrected void APIs, private `GetEntry`, existing fields/guard, typedef, and extern. | Very strong | Exact GFACE lowering, 13 Find calls, established List API, and dated command-25126 H incompleteness. | UID00006E complete formal H | incorporate | applied |
| C20 | 0001VT | Use the exact 44-byte `ResourceLayoutNameRecord` for the GFACE row, move its declaration from late CPP into UID00006E H, and reject undefined `ResourceLayoutRecord` as a duplicate convenience type. | Certain | GFACE reads `+0x20` entryCount and `+0x28` entries from the List(44,10) row. | UID0001VT formal channel/history and UID0002V8 type route | reject-stale | applied |
| C21 | 0000VB | Move exact 24-byte ResourceLayoutEntry declaration from late CPP into UID00006E H; retain type page as no-duplicate evidence. | Certain | Row stride, fields, sentinel, compile order. | UID0000VB formal channel/history | reject-stale | applied |
| C22 | 0000K2 | Add exact ImageLib CPP dependencies and the complete `../util/List.h` H dependency required by inline `GetResourceLayout`; preserve unaffected lifecycle and all out-of-line method children in source order. | Very strong | Generated compile audit and exact List virtual-access lowering. | UID0000K2 CPP/H dependency inventory | incorporate | applied |
| C23 | 0000K2 | Record nine out-of-line facet methods plus the public H-only compiler-covered `GetResourceLayout` accessor; make `FindResourceIndex` public and require one declaration/definition route per symbol with no out-of-line accessor body. | Very strong | Complete family inventory, 13 Find calls, and two observed inline List-slot lowerings. | UID0000K2 file/generated/API inventory | incorporate | applied |
| C24 | 0000BY | Expand the class/facet inventory to nine out-of-line methods plus H-only `GetResourceLayout`, expose `FindResourceIndex` publicly, retain `GetEntry` privately, preserve no independent object/vtable, and label alias/accessor spelling inferred. | Very strong | Lifecycle/vtable/global negatives plus external caller and inline-access evidence. | UID0000BY class/API inventory | incorporate | applied |
| C25 | 0003RK | Replace local KQ forward declaration with direct include `../../render/ResourceLayoutTable.h`; preserve parser/score. | Very strong | Caller source and new owner H. | UID0003RK formal CPP/dependencies | incorporate | applied |
| C26 | 000092 | Add literal `#include "ImageLib.h"`, `#include "ResourceLayoutTable.h"`, and `#include "RidingImageLib.h"` before UID0002V8's complete formal CPP; use public `FindResourceIndex`, inline `GetResourceLayout`, exact `ResourceLayoutNameRecord`, and both declared KT/private-field routes. | Very strong | Exact GFACE disassembly, two KT callsites, dated missing includes, and complete formal replacement. | UID000092/UID0002V8 formal CPP dependency and GFACE route | incorporate | applied |
| C27 | 0002V8 | Replace both stale `m_rawRecordTable` operands with `ridingEpfPackage`, preserving indexes/order/unions. | Certain | Binary direct `+0x0c` loads. | UID0002V8 formal CPP/history | reject-stale | applied |
| C28 | 0000BZ | Move the complete `RidingImageLib` declaration into UID0000BZ formal H with guard, `LObject` dependency, exact forwards/API/externs, and `friend class NewHumanImageLib;` immediately before the three private storage fields. | Very strong | Direct field access, existing CPP declaration, and absent H; no accessor call. | UID0000BZ complete formal CPP/H move | incorporate | applied |
| C29 | 0001VU | Preserve ResourceLayoutStore as non-emitting alias over generic List; no class/vtable. | Certain | Constructor and List vtable. | UID0001VU no-code proof | already-present | already-present |
| C30 | 0001VS | Preserve ResourceLayoutBucket as non-emitting alias of ResourceLayoutNameRecord. | Certain | Same row; no lifecycle. | UID0001VS no-code proof | already-present | already-present |
| C31 | 0000QU | Preserve one `extern ImageLib *g_pEPFLib`, one ImageLib lifecycle, and no ResourceLayout global. | Certain | Lifecycle/global xrefs. | UID0000QU/UID0001OQ evidence | already-present | already-present |
| C32 | 000175 | Keep all seven decode wrappers outside ResourceLayout ownership. | Certain | Formats/callers/pages. | UID000175/children exclusions | already-present | already-present |
| C33 | 000176 | Keep frame-table load/destroy/copy helpers outside ResourceLayout ownership; P6 alone is class method. | Certain | Roles/owners/pages. | UID000176/00031T/00031U | already-present | already-present |
| C34 | 000174 | Historicalize old range hash `A79F027CB1059637E061D17A455ACD277D47EB9EB136E544C7110A825E26DE0E` as incomplete-range evidence. | Certain | Fresh old-scope hash and new function. | UID000174 history | historicalize | applied |
| C35 | 0000N5 | Historicalize one-body/one-empty generated state, static KT, duplicate struct, wrong order, and absent H. | Certain | Physical generated snapshot. | UID0000N5 generated/history | historicalize | applied |
| C36 | 0002KQ | Raise `86/89 -> 93/93` after faithful source/declaration/ownership/blocker closure. | Very strong | Full source closure. | UID0002KQ metadata | incorporate | applied |
| C37 | 0002KT | Raise `88/90 -> 92/93` after type/linkage/header/caller closure. | Very strong | Full ABI closure. | UID0002KT metadata | incorporate | applied |
| C38 | 0002KO | Raise `90/90 -> 94/94` after correcting observed source mismatches. | Very strong | Complete body evidence. | UID0002KO metadata | incorporate | applied |
| C39 | 0002KP | Raise `90/91 -> 94/95` after void/failure correction. | Very strong | Exact body/440 xrefs. | UID0002KP metadata | incorporate | applied |
| C40 | 0002KS | Raise `89/90 -> 93/94` after void/failure correction. | Very strong | Exact body/callers. | UID0002KS metadata | incorporate | applied |
| C41 | 0002KW | Raise `90/92 -> 93/95` after pointer-walk correction. | Very strong | Exact body. | UID0002KW metadata | incorporate | applied |
| C42 | 0000BY | Raise class `90/91 -> 94/94`; use only Section 26 support scores. | Strong | Complete method/header boundary. | UID0000BY/0000K2/00006E metadata | incorporate | applied |
| C43 | 0000N5 | Supply exact complete manual coverage replacements/insertions for every affected target/support route, including UID000079/UID0000KS List dependencies and all GFACE API/type consumers, without editing coverage files. | Certain | Manual rows were physically read and compared for this report. | Section 28 coverage roots | incorporate | applied |
| C44 | 0000BY | I01 define exact function `[0x004d1830,0x004d1860)` and require the observed type-absent, zero-local frame containing only `__saved_registers` and `__return_address`; no argument rows and no save on mismatch. | Very strong | Exact body/boundary/hash plus public `define_func` and immediate `stack_frame` receipt. | Supervisor Gate 2B I01 | incorporate | proposed |
| C45 | 0000BY | I02 pure-rename the exact staged type-absent, two-row function to `ResourceLayoutTable__GetEntry`, changing no frame/type/comment/byte/xref/boundary field. | Strong | Public pure-rename schema, staged prestate, semantics and noncollision. | Supervisor Gate 2B I02 | incorporate | proposed |
| C46 | 0002KO | I03 pure-rename `sub_4D0120` to `ResourceLayoutTable__LoadResourceIndex`. | Very strong | Body/graph/noncollision. | Supervisor Gate 2B I03 | incorporate | proposed |
| C47 | 0002KP | I04 pure-rename `ResourceLayoutTable_LookupLayoutEntry` to `ResourceLayoutTable__LookupLayoutEntry`. | Very strong | Semantic name/noncollision. | Supervisor Gate 2B I04 | incorporate | proposed |
| C48 | 0002KQ | I05 pure-rename `sub_4D03A0` to `ResourceLayoutRawBufferLookupEntry`. | Very strong | Body/caller/noncollision. | Supervisor Gate 2B I05 | incorporate | proposed |
| C49 | 0002KR | I06 pure-rename `sub_4D04D0` to `ResourceLayoutTable__CopyEntryTileContext`. | Very strong | Body/callers/noncollision. | Supervisor Gate 2B I06 | incorporate | proposed |
| C50 | 0002KS | I07 pure-rename `sub_4D0530` to `ResourceLayoutTable__GetEntryRect`. | Very strong | Body/callers/noncollision. | Supervisor Gate 2B I07 | incorporate | proposed |
| C51 | 0002KT | I08 pure-rename `sub_4D05A0` to `ResourceLayoutRawRecordGetEntryRect`. | Very strong | Body/callers/noncollision. | Supervisor Gate 2B I08 | incorporate | proposed |
| C52 | 0002KU | I09 pure-rename `sub_4D1730` to `ResourceLayoutTable__GetFrameSize`. | Very strong | Body/noncollision. | Supervisor Gate 2B I09 | incorporate | proposed |
| C53 | 0002KV | I10 pure-rename `sub_4D1780` to `ResourceLayoutTable__GetEntryCount`. | Very strong | Body/noncollision. | Supervisor Gate 2B I10 | incorporate | proposed |
| C54 | 0002KW | I11 pure-rename `sub_4D17C0` to `ResourceLayoutTable__FindResourceIndex`. | Very strong | Body/noncollision. | Supervisor Gate 2B I11 | incorporate | proposed |
| C55 | 0002P6 | Preserve exact P6 name/declaration, five frame rows, zero locals, independently stated AR/AP/FR/FP, 93-byte hash, 81 exact code xrefs, zero data xrefs and zero callees; no action and no save on mismatch. | Certain | Complete literal protected prestate/no-change/readback contract. | Gate 2B protected P6 row | already-present | proposed |
| C56 | 0000N5 | Require fresh session enumeration/attestation, P6 pre-readback, deterministic I01 two-row poststate then I02 pure rename, ordered I03-I11, immediate action readbacks, complete final reread including P6, and fail-closed no-save behavior. | Certain | Session lifecycle, failed-I01 receipt, corrected staging and literal contracts. | Section 21 contract | incorporate | proposed |
| C57 | 0000N5 | Preserve read-only B-agent disposition and dated rollback truth: B001 made no IDA mutation/save/backup/process-control change; failed supervisor I01 was unsaved/discarded, I02-I11 did not run, and canonical raw prestate returned. | Certain | B001 tool audit plus supervisor failed-I01/discard/reopen receipt. | Report IDA status | already-present | proposed |
| C58 | 0000N5 | Apply all target/support facts at report detail and preserve contradictions as dated history. | Certain | Destination audit. | Sections 24-25 | incorporate | applied |
| C59 | 0000N5 | Apply every complete owner-specific formal CPP block in Section 22, including UID0002V8's legal GFACE row/accessor/rectangle route and two Riding replacements plus UID0000BZ's header-include/`[[CHILDREN]]` owner shell with no CPP class redeclaration. | Very strong | Exact source reconstruction and no-duplicate owner route. | Formal CPP channels | incorporate | applied |
| C60 | 0000N5 | Apply every complete owner-specific formal H block in Section 22, including ImageLib's List dependency, exact rows, public Find, inline compiler-covered accessor/private GetEntry split, and the guarded complete `RidingImageLib.h` declaration with narrow friendship before private storage. | Very strong | Compile-visible guarded owner declarations, access control, and types. | Formal H channels | incorporate | applied |
| C61 | 0000N5 | Use no third-party import; all bodies are reconstructed NexusTK project source. | Certain | Source-family evidence. | Formal disposition | not-applicable | excluded-with-reason |
| C62 | 0000N5 | Callback must scoped-validate each changed page and reread affected generated CPP/H against full inventory. | Certain | Validator workflow. | Sections 29/31 | incorporate | applied |
| C63 | 0000N5 | Report has 33 exact headings, 126/126 twin parity, two formal C++ fences, lifecycle-neutral post-implementation prose, and one terminal readiness marker. | Certain | Mechanical report audit. | Report structure | already-present | already-present |
| C64 | 0002TJ | Keep exact ZPF/FPF decoder `[0x004d05f0,0x004d0723)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | Format behavior, owner page and generated definition. | UID0002TJ/UID0000K3 exclusion route | already-present | already-present |
| C65 | 0002TK | Keep exact raw FPF decoder `[0x004d0730,0x004d07a3)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | Raw body/signature and generated definition. | UID0002TK/UID0000K3 exclusion route | already-present | already-present |
| C66 | 0002TL | Keep exact JPF/libjpeg decoder `[0x004d07b0,0x004d09a7)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | IJG/RGB565 behavior and generated definition. | UID0002TL/UID0000K3 exclusion route | already-present | already-present |
| C67 | 0002TM | Keep exact 8-bit BMP decoder `[0x004d09b0,0x004d0a8a)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | BMP/palette behavior and generated definition. | UID0002TM/UID0000K3 exclusion route | already-present | already-present |
| C68 | 0002TN | Keep exact JPEG-buffer decoder `[0x004d0a90,0x004d0c58)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | Minimap/IJG behavior and generated definition. | UID0002TN/UID0000K3 exclusion route | already-present | already-present |
| C69 | 00032P | Keep exact PNG-file decoder `[0x004d0c60,0x004d0d89)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | LodePNG file/RGBA conversion evidence. | UID00032P/UID0000K3 exclusion route | already-present | already-present |
| C70 | 00032O | Keep exact PNG-resource decoder `[0x004d0d90,0x004d0f4a)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | LodePNG memory/DAT behavior. | UID00032O/UID0000K3 exclusion route | already-present | already-present |
| C71 | 0002P4 | Keep exact frame-table loader `[0x004d0f50,0x004d15c5)` in ImageFrameTable with nonblank CPP, blank H, unchanged 89/92 and no ResourceLayout ownership. | Certain | DAT/frame-table construction and generated definition. | UID0002P4/UID0000K1 exclusion route | already-present | already-present |
| C72 | 0002P5 | Keep exact frame-table destroy helper `[0x004d15d0,0x004d15fc)` in ImageFrameTable with nonblank CPP, blank H, unchanged 88/92 and no ResourceLayout ownership. | Certain | Allocation pairing/eight callers and generated definition. | UID0002P5/UID0000K1 exclusion route | already-present | already-present |
| C73 | 00031T | Keep exact payload-copy helper `[0x004d1660,0x004d1704)` in ImageFrameTable with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | Raw body/MemoryMan/no-xref evidence. | UID00031T/UID0000K1 exclusion route | already-present | already-present |
| C74 | 00031U | Keep exact bounds-copy helper `[0x004d1710,0x004d172d)` in ImageFrameTable with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | Raw 24-byte-stride/movups/no-xref evidence. | UID00031U/UID0000K1 exclusion route | already-present | already-present |
| C75 | 0000VN | Preserve `[0x004d02e5,0x004d02f0)` as 11 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C76 | 0000VN | Preserve `[0x004d039e,0x004d03a0)` as 2 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C77 | 0000VN | Preserve `[0x004d0522,0x004d0530)` as 14 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C78 | 0000VN | Preserve `[0x004d059b,0x004d05a0)` as 5 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C79 | 0000VN | Preserve `[0x004d05e6,0x004d05f0)` as 10 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C80 | 0000VN | Preserve `[0x004d0723,0x004d0730)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C81 | 0000VN | Preserve `[0x004d07a3,0x004d07b0)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C82 | 0000VN | Preserve `[0x004d09a7,0x004d09b0)` as 9 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C83 | 0000VN | Preserve `[0x004d0a8a,0x004d0a90)` as 6 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C84 | 0000VN | Preserve `[0x004d0c58,0x004d0c60)` as 8 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C85 | 0000VN | Preserve `[0x004d0d89,0x004d0d90)` as 7 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C86 | 0000VN | Preserve `[0x004d0f4a,0x004d0f50)` as 6 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C87 | 0000VN | Preserve `[0x004d15c5,0x004d15d0)` as 11 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C88 | 0000VN | Preserve `[0x004d15fc,0x004d1600)` as 4 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C89 | 0000VN | Preserve `[0x004d165d,0x004d1660)` as 3 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C90 | 0000VN | Preserve `[0x004d1704,0x004d1710)` as 12 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C91 | 0000VN | Preserve `[0x004d172d,0x004d1730)` as 3 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C92 | 0000VN | Preserve `[0x004d1773,0x004d1780)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C93 | 0000VN | Preserve `[0x004d17b3,0x004d17c0)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C94 | 0000VN | Preserve `[0x004d182f,0x004d1830)` as 1 `0xcc` byte with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| C95 | 0001US | Add GetEntry's use of the established ImageLib `+0x0c List *` while preserving the exact 0x14 layout and 86/90. | Certain | New method body and existing layout proof. | ImageLibLayout support page | incorporate | applied |
| C96 | 0001OQ | Preserve exact four-byte `g_pEPFLib` storage at `0x0067a744`, one ImageLib lifecycle route and no duplicate ResourceLayout global. | Certain | Global address/lifecycle evidence. | g_pEPFLib by-memory support page | already-present | already-present |
| C97 | 0000P0 | Add UID0003RK's direct ResourceLayoutTable.h dependency/generated expectation without changing UserLookPane's 92/93 inventory. | Very strong | Sole KQ caller and formal include correction. | UserLookPane by-file support | incorporate | applied |
| C98 | 0000LR | Add UID0002V8's ImageLib/ResourceLayoutTable/Riding dependencies, exact GFACE row/accessor/public-Find route, and generated expectations without pruning NewHumanImageLib's inventory or changing 91/91. | Very strong | GFACE direct/virtual calls, two KT calls, and direct Riding field reads. | NewHumanImageLib by-file support | incorporate | applied |
| C99 | 0000N6 | Add narrow friendship/private-field route and generated expectation without pruning RidingImageLib's inventory or changing 91/92. | Very strong | Exact +0x0c access and formal friend insertion. | RidingImageLib by-file support | incorporate | applied |
| C100 | 0000K3 | Preserve ImageLoaders as owner of exactly seven excluded decoder bodies, all present in generated CPP, with no ResourceLayout ownership. | Certain | Child pages and physical generated readback. | ImageLoaders by-file verify-only route | already-present | already-present |
| C101 | 0000K1 | Preserve ImageFrameTable as owner of P4/P5/31T/31U and shared types, with P6 absent from its CPP. | Certain | Child pages and physical generated readback. | ImageFrameTable by-file verify-only route | already-present | already-present |
| C102 | 000175 | Preserve decoder aggregate as an index over seven individually owned ImageLoaders children, not an extra ResourceLayout body. | Certain | Complete range/child matrix. | ImageDecodeWrappers aggregate | already-present | already-present |
| C103 | 000176 | Preserve frame aggregate as non-emitting index; P4/P5 remain ImageFrameTable-owned and P6 remains separately ResourceLayout-owned. | Certain | Complete frame neighborhood split. | ImageFrameTable aggregate | already-present | already-present |
| C104 | 0000UN | Preserve ArchiveMetadataTable/PackedArchiveRecord/FrameDrawRecord declarations as the shared H dependency for KT, P6 and frame helpers. | Certain | Exact layouts and generated H readback. | EPFArchiveMetadataTable item support | already-present | already-present |
| C105 | 0000UX | Preserve LoadFrameDrawRecord item as a non-emitting semantic mirror; UID0002P6 alone owns the definition. | Certain | Item metadata and no-duplicate route. | LoadFrameDrawRecord item support | already-present | already-present |
| C106 | 0000UY | Preserve LoadImageFrameTable item as a non-emitting semantic mirror; UID0002P4 alone owns the definition. | Certain | Item metadata and no-duplicate route. | LoadImageFrameTable item support | already-present | already-present |
| C107 | 0002IZ | Preserve MapTile constructor `[0x004d1860,0x004d199e)` as the exact successor and exclude it from UID000174/ResourceLayout source. | Certain | Successor prologue/range/page. | MapTile constructor boundary route | already-present | already-present |
| C108 | 000177 | Preserve MapTile local-method cluster as a non-emitting successor index with no overlap at corrected end `0x004d1860`. | Certain | Aggregate boundary metadata. | MapTile cluster boundary route | already-present | already-present |
| C109 | 00007T | Preserve MapTileImageLib class ownership and 92/94 source route after the exact successor boundary. | Certain | Constructor parent/emitter metadata. | MapTileImageLib class boundary route | already-present | already-present |
| C110 | 0000L5 | Preserve MapTileImageLib file ownership and 91/93 generated route; no ResourceLayout callback edit applies. | Certain | File/source boundary evidence. | MapTileImageLib by-file boundary route | already-present | already-present |
| C111 | 0000N5 | Callback-generated ResourceLayoutTable.cpp must contain exactly corrected KQ then KT definitions, with no static helper, duplicate table or empty marker. | Certain | Dated generated defect readback and formal CPP. | Generated ResourceLayoutTable.cpp | incorporate | applied |
| C112 | 0000N5 | Callback-generated ResourceLayoutTable.h must contain exactly both external declarations from UID0002KQ formal H. | Certain | Dated generated absence and cross-file caller requirements. | Generated ResourceLayoutTable.h | incorporate | applied |
| C113 | 0000K2 | Callback-generated `ImageLib.cpp` must contain exactly nine out-of-line facet definitions, corrected KO/KP/KS/KW, new `GetEntry`, no out-of-line `GetResourceLayout`, and no late duplicate row structs. | Certain | Dated eight-method readback, compiler-covered accessor evidence, and formal CPP. | Generated ImageLib.cpp | incorporate | applied |
| C114 | 00006E | Callback-generated `ImageLib.h` must include `List.h`, declare both row types before class use, expose public `FindResourceIndex` and inline `GetResourceLayout`, retain private `GetEntry`, and preserve the complete class, typedef, singleton extern, and size guards. | Certain | Dated incomplete H readback and complete formal H. | Generated ImageLib.h | incorporate | applied |
| C115 | 0000P0 | Callback-generated UserLookPane.cpp must use the owner H include, retain one KQ call and contain no local KQ prototype. | Certain | Dated generated caller readback. | Generated UserLookPane.cpp | incorporate | applied |
| C116 | 0000P0 | Preserve intentional absence of UserLookPane.h for this dependency-only correction; no declaration is moved there. | Strong | Existing file route and CPP-only change. | Generated UserLookPane.h | already-present | already-present |
| C117 | 0000LR | Callback-generated `NewHumanImageLib.cpp` must include `ImageLib.h`, `ResourceLayoutTable.h`, and `RidingImageLib.h`; preserve UID0002V8's complete body; use `ResourceLayoutNameRecord` with public Find/inline accessor in GFACE; use `ridingEpfPackage` at both KT callsites; and contain no `ResourceLayoutRecord` or `m_rawRecordTable`. | Certain | Exact GFACE lowering, two binary Riding +0x0c reads, and dated generated defects. | Generated NewHumanImageLib.cpp | incorporate | applied |
| C118 | 000092 | Preserve complete `NewHumanImageLib.h` and verify it introduces no duplicate ResourceLayout helper/accessor/row declaration, `RidingImageLib` class declaration, undefined `ResourceLayoutRecord`, or stale field declaration. | Very strong | Existing generated H and complete class inventory. | Generated NewHumanImageLib.h | already-present | already-present |
| C119 | 0000N6 | Callback-generated `RidingImageLib.cpp` must include `RidingImageLib.h`, retain all `[[CHILDREN]]` method/global definitions in source order, and contain no duplicate `RidingImageLib` class or extern declaration. | Very strong | Dated CPP class shell, child order, and exact layout. | Generated RidingImageLib.cpp | incorporate | applied |
| C120 | 0000BZ | Callback-generated `RidingImageLib.h` must contain the complete guarded owner declaration, `LObject` include, exact forwards/API/externs, and `friend class NewHumanImageLib;` before `ridingDefinitions`/`ridingDefinitionCount`/`ridingEpfPackage`. | Very strong | Dated H absence and two direct private reads. | Generated RidingImageLib.h | incorporate | applied |
| C121 | 0000K3 | Preserve generated ImageLoaders.cpp with all seven decoder definitions and zero empty markers; no callback edit applies. | Certain | Dated physical readback. | Generated ImageLoaders.cpp | already-present | already-present |
| C122 | 0000K3 | Preserve intentional absence of ImageLoaders.h because all seven decoder child H channels are blank/file-local. | Certain | Formal channel and generated readback. | Generated ImageLoaders.h | already-present | already-present |
| C123 | 0000K1 | Preserve generated ImageFrameTable.cpp with P4/P5/31T/31U and no P6 duplicate; no callback edit applies. | Certain | Dated physical readback. | Generated ImageFrameTable.cpp | already-present | already-present |
| C124 | 0000UN | Preserve generated ImageFrameTable.h with shared ArchiveMetadataTable/FrameDrawRecord declarations used by KT/P6/frame helpers. | Certain | Dated physical readback. | Generated ImageFrameTable.h | already-present | already-present |
| C125 | 0000L5 | Preserve generated MapTileImageLib.cpp as the separate successor-family output beginning at `0x004d1860`; no callback edit applies. | Certain | Dated physical readback and boundary. | Generated MapTileImageLib.cpp | already-present | already-present |
| C126 | 0000L5 | Preserve intentional absence of MapTileImageLib.h and make no ResourceLayout-driven header change. | Strong | Existing file/class route. | Generated MapTileImageLib.h | already-present | already-present |

## Positive Evidence Summary

- KQ and KT are physically inside the ResourceLayout band, share 24-byte record semantics, and have external no-`this` ABIs.
- All class methods use the same ImageLib `+0x0c` List and singleton route; no second object exists.
- Tail method `0x4d1830` performs one List lookup, signed frame validation, and 24-byte row address formation, exactly matching a private entry accessor.
- Accepted support headers supply stable project-facing types; final source needs no `sub_`, `_DWORD`, or duplicate raw layout.
- Corrected split makes UserLook, NewHuman, RidingImageLib, ResourceLayoutTable, and ImageLib declaration routes coherent.

## IDA MCP Facts

| Start | Current name/type | Range, size, instructions/blocks | SHA256 | Inbound code refs |
| --- | --- | --- | --- | --- |
| `0x004d0120` | `sub_4D0120`; `int __thiscall(_DWORD **this, wchar_t *ArgList)` | `[0x4d0120,0x4d02e5)`, 453, 172/10 | `CB5CB9EA5E35F8B90731B0E5417B8B14D063F4E67E8256BDFC70DD78623EA6F9` | 13 |
| `0x004d02f0` | `ResourceLayoutTable_LookupLayoutEntry`; `void __thiscall(ResourceLayoutTable *this, const wchar_t *resourceName, __int16 frameIndex, EPFTileContext *outContext)` | `[0x4d02f0,0x4d039e)`, 174, 63/11 | `E4DDDDACB40CEDBE240F91399FDC8CA4CBA79D7A5D1C1C2A24EF5664A4FB21B5` | 440 |
| `0x004d03a0` | `sub_4D03A0`; `char *__stdcall(char *Src, struct RectBounds *)` | `[0x4d03a0,0x4d04d0)`, 304, 120/3 | `F62C5EF9B96FDBB2833DFB414353E29CB0CE2F77EE78D7A4E647AD1D98B5D2F4` | 1 |
| `0x004d04d0` | `sub_4D04D0`; `void __thiscall(ResourceLayoutTable *this, unsigned __int16 *ArgList, __int16 frameIndex, int)` | `[0x4d04d0,0x4d0522)`, 82, 34/3 | `C5676A33C1FD1CF966DBB936D5601DC51639E6363B236580E21F6A2E03E3D1A8` | 25 |
| `0x004d0530` | `sub_4D0530`; `void __thiscall(int this, unsigned __int16 *ArgList, int, struct RectBounds *bounds)` | `[0x4d0530,0x4d059b)`, 107, 43/7 | `F08F1825FAD936D414EFC757A11ED7E43438B5ABC52EC390429FEFE3D71CA85A` | 11 |
| `0x004d05a0` | `sub_4D05A0`; `_DWORD *__stdcall(unsigned __int16 *, int, _DWORD *)` | `[0x4d05a0,0x4d05e6)`, 70, 21/3 | `9451095D30885DBA7BAC9E00846B4A6DABC66625BFB8A04470F40F2154178519` | 28 |
| `0x004d1600` | `ResourceLayoutTable__LoadFrameDrawRecord`; exact typed void declaration | `[0x4d1600,0x4d165d)`, 93, 32/4 | `8A4817839F3CC4CE7546A51F0E4BA8410E1342C921A49B9BF060145A9BF3BB21` | 81 |
| `0x004d1730` | `sub_4D1730`; `_WORD *__thiscall(int this, unsigned __int16 *ArgList, _WORD *, _WORD *)` | `[0x4d1730,0x4d1773)`, 67, 26/3 | `2D32873F45C35253485C79F15D057FA79BCF5C3887576A73E1C6813735776C58` | 1 |
| `0x004d1780` | `sub_4D1780`; `__int16 __thiscall(int this, unsigned __int16 *ArgList)` | `[0x4d1780,0x4d17b3)`, 51, 21/3 | `2D3D5DBF8FEB16EF899CB06A122D2ADE3C164E180D3BA3E7EC4BDF35CC54E408` | 6 |
| `0x004d17c0` | `sub_4D17C0`; `int __thiscall(_DWORD *this, const unsigned __int16 *)` | `[0x4d17c0,0x4d182f)`, 111, 51/13 | `2F0168D65498440BDD742B3AF451982FA98945AB03CB463D6E9596A980726D0E` | 13 |
| `0x004d1830` | name absent; type absent; function absent; 20 decoded instructions | `[0x4d1830,0x4d1860)`, 48 | `3505E796AA1F9C411DAC68C3E1015E9AC053ECA55C83484BB6568B436DD01BE5` | 0 |

Fresh 2026-08-17 read-only receipt: `inspect_items` returned `[0x004d1830,0x004d1831)` as code with name absent and type absent; `lookup_funcs` returned `Not a function`; `stack_frame` returned no function; `get_comments` returned blank AR/AP with no FR/FP fields; `xref_query` returned zero inbound code and data refs; `lookup_funcs` found no `ResourceLayoutTable__GetEntry` collision; successor `sub_4D1860` remained `[0x004d1860,0x004d199e)` with declaration `_DWORD *__thiscall(_DWORD *this)`. The exact 48 raw MCP bytes independently hash to `3505E796AA1F9C411DAC68C3E1015E9AC053ECA55C83484BB6568B436DD01BE5` under .NET SHA256.

The dated failed-I01 worker receipt supplies the otherwise unobservable staged state without repeating mutation: public `define_func` created `sub_4D1830` at exact `[0x004d1830,0x004d1860)`, type absent, zero locals, and exactly two frame rows: `__saved_registers@0x0/0x4/_DWORD` and `__return_address@0x4/0x4/_UNKNOWN *`. It did not create `arg_0` or `arg_4`. At I01's no-function prestate, AR is absent; AP is absent; FR is not applicable; FP is not applicable. I02's corrected post-I01 prestate has AR absent; AP absent; FR absent; FP absent. Every existing I03-I11 function has AR absent; AP absent; FR absent; FP absent. P6 alone has FR: `Source ResourceLayoutTable/ImageLib-facet member LoadFrameDrawRecord. Callers deliberately establish g_pEPFLib in ECX even though this body does not consume the receiver.` Its AR is absent; AP is absent; FP is absent.

## Function / Child Inventory

Every row below is independently dispositioned. "Excluded" means excluded from ResourceLayout ownership, not unreconstructable or omitted from its own canonical owner.

### In-Scope Source Definitions

| Exact range/item | UID / exact page | Role / behavior | Ownership / source | Reconstructable | Formal CPP/H disposition | Metadata | Generated destination / dated readback | Completion / evidence-backed disposition |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `[0x004d0120,0x004d02e5)` | 0002KO / `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` | DAT loader; header/row reads, payload rebasing, sentinel, append | UID0000BY -> UID0000K2 `ImageLib.cpp` | true | Replace CPP; declaration in UID00006E H | `90/90 -> 94/94` | `ImageLib.cpp`; current body checks Open, uses wrong seek modes/int reads | Included; exact 453 bytes/hash and 13 xrefs prove class method. |
| `[0x004d02f0,0x004d039e)` | 0002KP / `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` | Lazy lookup and EPFTileContext projection/reset | UID0000BY -> UID0000K2 | true | Replace CPP with void/int source; declaration in UID00006E H | `90/91 -> 94/95` | `ImageLib.cpp/.h`; current pointer return and incomplete source type | Included; exact 174 bytes/hash and 440 code xrefs. |
| `[0x004d03a0,0x004d04d0)` | 0002KQ / `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` | Raw-buffer parser preserving one-row init, uninitialized row-one read and leak | UID0000N5 position 10, `ResourceLayoutTable.cpp/.h` | true | Complete formal CPP and central complete H | `86/89 -> 93/93` | `ResourceLayoutTable.cpp`: Empty Emitter Marker; H absent | Included as first external no-this helper; exact 304 bytes/hash/sole caller. |
| `[0x004d04d0,0x004d0522)` | 0002KR / `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | Stack context initialize, void lookup, conditional CopyTo | UID0000BY -> UID0000K2 | true | Preserve CPP; declaration in UID00006E H | `90/91` unchanged | `ImageLib.cpp/.h`; body present | Included; exact 82 bytes/hash and 25 calls. |
| `[0x004d0530,0x004d059b)` | 0002KS / `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` | Lazy bounds lookup, signed check, 16-byte copy, zero failure | UID0000BY -> UID0000K2 | true | Replace CPP with void; declaration in UID00006E H | `89/90 -> 93/94` | `ImageLib.cpp/.h`; current pointer return | Included; exact 107 bytes/hash and 11 calls. |
| `[0x004d05a0,0x004d05e6)` | 0002KT / `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md` | External ArchiveMetadataTable bounds copy/zero helper | UID0000N5 position 20 | true | Replace CPP; H intentionally blank because KQ centralizes both declarations | `88/90 -> 92/93` | `ResourceLayoutTable.cpp`: wrong static duplicate table; H absent | Included as second external no-this helper; exact 70 bytes/hash and 28 callers. |
| `[0x004d1600,0x004d165d)` | 0002P6 / `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md` | FrameDrawRecord projection with pointer-only failure clears and next-row span | UID0000BY -> UID0000K2 | true | Preserve current CPP/H declaration exactly | `91/94` unchanged | `ImageLib.cpp/.h`; one complete definition/declaration, absent from `ImageFrameTable.cpp` | Included; exact 93 bytes/hash, 81 code xrefs, protected C55 no-change. |
| `[0x004d1730,0x004d1773)` | 0002KU / `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` | Lazy +0x22/+0x24 width/height copy | UID0000BY -> UID0000K2 | true | Preserve CPP/H | `90/92` unchanged | `ImageLib.cpp/.h`; present | Included; exact 67 bytes/hash and sole caller. |
| `[0x004d1780,0x004d17b3)` | 0002KV / `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` | Lazy unsigned 16-bit count accessor | UID0000BY -> UID0000K2 | true | Preserve CPP/H | `90/93` unchanged | `ImageLib.cpp/.h`; present | Included; exact 51 bytes/hash and six callers. |
| `[0x004d17c0,0x004d182f)` | 0002KW / `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` | One initial List lookup and 44-byte linear name scan | UID0000BY -> UID0000K2 | true | Replace CPP; public declaration centralized in UID00006E H | `90/92 -> 93/95` | `ImageLib.cpp`; dated repeated `GetElementAt` source and private H declaration | Included; exact 111 bytes/hash and 13 calls, nine external to facet methods. |
| `[0x004d1830,0x004d1860)` | 00054V / `by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md` | Private signed-checked List row accessor | UID0000BY position 110 -> UID0000K2 | true | Complete CPP; declaration centralized in UID00006E H | implemented `92/93` | Present once in `ImageLib.cpp/.h` after UID0002KW | Included; exact 48 bytes/hash, two exits, no inbound xrefs, successor at 0x4d1860. |

### Excluded Decoder And Frame Definitions

| Exact range/item | UID / exact page | Role / behavior | Ownership / source | Reconstructable | Formal CPP/H disposition | Metadata | Generated destination / dated readback | Completion / evidence-backed disposition |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `[0x004d05f0,0x004d0723)` | 0002TJ / `by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md` | Inflate ZPF, validate inner FPF, copy RGB16, finalize context | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/89` unchanged | `ImageLoaders.cpp`, complete definition; no generated H | Excluded: image-format decoder, no ResourceLayout state or ABI. |
| `[0x004d0730,0x004d07a3)` | 0002TK / `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md` | Raw FPF reset/allocation/pixel-copy/finalizer | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/90` unchanged | `ImageLoaders.cpp`, complete definition | Excluded: raw unmodeled FPF decoder with no ResourceLayout receiver. |
| `[0x004d07b0,0x004d09a7)` | 0002TL / `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md` | IJG JPF/JPEG scanline decode to RGB565 | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/89` unchanged | `ImageLoaders.cpp`, complete definition | Excluded: libjpeg wrapper and format converter. |
| `[0x004d09b0,0x004d0a8a)` | 0002TM / `by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md` | 8-bit paletted BMP decode and palette route | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/90` unchanged | `ImageLoaders.cpp`, complete definition | Excluded: BMP/palette decoder. |
| `[0x004d0a90,0x004d0c58)` | 0002TN / `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md` | In-memory JPEG decode for minimap blobs, RGB565 finalize | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/89` unchanged | `ImageLoaders.cpp`, complete definition | Excluded: IJG buffer decoder. |
| `[0x004d0c60,0x004d0d89)` | 00032P / `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md` | LodePNG file front end, RGBA to RGB565/alpha, cleanup | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/89` unchanged | `ImageLoaders.cpp`, complete definition | Excluded: unmodeled PNG-file decoder. |
| `[0x004d0d90,0x004d0f4a)` | 00032O / `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md` | DAT/buffer PNG memory front end and context conversion | UID0000K3 `ImageLoaders.cpp` | true | CPP nonblank; H blank/file-local | `88/89` unchanged | `ImageLoaders.cpp`, complete definition | Excluded: PNG-resource decoder with no ResourceLayout ownership. |
| `[0x004d0f50,0x004d15c5)` | 0002P4 / `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md` | DAT-backed frame table load, direct/merge mode, sentinel/rebase | UID0000K1 `ImageFrameTable.cpp` position 10 | true | CPP nonblank; H blank because shared types are UID0000UN-owned | `89/92` unchanged | `ImageFrameTable.cpp`, complete definition | Excluded: constructs ArchiveMetadataTable; does not use ResourceLayout List. |
| `[0x004d15d0,0x004d15fc)` | 0002P5 / `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md` | Free nested record allocation then outer frame table | UID0000K1 `ImageFrameTable.cpp` position 20 | true | CPP nonblank; H blank/file-local | `88/92` unchanged | `ImageFrameTable.cpp`, complete definition | Excluded: paired frame-table cleanup with eight destructor callers. |
| `[0x004d1660,0x004d1704)` | 00031T / `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md` | Allocate/copy two record payload spans and bounds | UID0000K1 `ImageFrameTable.cpp` position 40 | true | CPP nonblank; H blank/file-local | `88/90` unchanged | `ImageFrameTable.cpp`, complete definition | Excluded: raw no-xref frame-record copy helper. |
| `[0x004d1710,0x004d172d)` | 00031U / `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md` | Copy 16-byte bounds from 24-byte frame row | UID0000K1 `ImageFrameTable.cpp` position 50 | true | CPP nonblank; H blank/file-local | `88/90` unchanged | `ImageFrameTable.cpp`, complete definition | Excluded: raw no-xref frame-record rectangle helper. |

### Exact Internal Gaps

| Exact range | UID / path | Role/content | Ownership/source | Reconstructable | Formal CPP/H | Metadata | Generated destination | Completion/evidence |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `[0x004d02e5,0x004d02f0)` | 0000VN / `by-memory/-ignored.md` | 11 `0xcc`, KO/KP alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d039e,0x004d03a0)` | 0000VN | 2 `0xcc`, KP/KQ alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d0522,0x004d0530)` | 0000VN | 14 `0xcc`, KR/KS alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d059b,0x004d05a0)` | 0000VN | 5 `0xcc`, KS/KT alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d05e6,0x004d05f0)` | 0000VN | 10 `0xcc`, KT/decoder boundary | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d0723,0x004d0730)` | 0000VN | 13 `0xcc`, decoder alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d07a3,0x004d07b0)` | 0000VN | 13 `0xcc`, decoder alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d09a7,0x004d09b0)` | 0000VN | 9 `0xcc`, decoder alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d0a8a,0x004d0a90)` | 0000VN | 6 `0xcc`, decoder alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d0c58,0x004d0c60)` | 0000VN | 8 `0xcc`, decoder alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d0d89,0x004d0d90)` | 0000VN | 7 `0xcc`, decoder alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d0f4a,0x004d0f50)` | 0000VN | 6 `0xcc`, decoder/frame boundary | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d15c5,0x004d15d0)` | 0000VN | 11 `0xcc`, frame alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d15fc,0x004d1600)` | 0000VN | 4 `0xcc`, P5/P6 alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d165d,0x004d1660)` | 0000VN | 3 `0xcc`, P6/frame-helper boundary | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d1704,0x004d1710)` | 0000VN | 12 `0xcc`, frame-helper alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d172d,0x004d1730)` | 0000VN | 3 `0xcc`, frame/ResourceLayout boundary | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d1773,0x004d1780)` | 0000VN | 13 `0xcc`, KU/KV alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d17b3,0x004d17c0)` | 0000VN | 13 `0xcc`, KV/KW alignment | none/non-source | false | blank/blank | ignored | none | Exact bytes; exclude. |
| `[0x004d182f,0x004d1830)` | 0000VN | 1 `0xcc`, KW/GetEntry alignment | none/non-source | false | blank/blank | ignored | none | Exact byte; exclude. |

### Type, Data, Support, And Boundary Routes

| Item | UID / exact path | Role / behavior | Ownership/source | Reconstructable | Formal disposition | Metadata | Generated destination/readback | Completion/evidence-backed disposition |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| ResourceLayoutTable file target | 0000N5 / `by-file/ResourceLayoutTable.md` | Two external raw helpers and complete family index | FILE, `NexusTK/render/` | true | KQ/KT formal CPP plus KQ-owned complete H | implemented `95/93` | `ResourceLayoutTable.cpp/.h`, two definitions/declarations | Exact target plan implemented; no class methods. |
| Mixed aggregate | 000174 / same-UID `by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md` | Range/inventory container | none | false | CPP/H blank | implemented `92/95` | none | Corrected path/hash; non-emission preserved; old endpoint historical. |
| ResourceLayout facet | 0000BY / `by-class/ResourceLayoutTable.md` | Nine out-of-line methods, public compiler-covered row accessor, no independent object | UID0000K2/UID00006E | true | Method children CPP; public Find/inline accessor and private GetEntry through UID00006E H | implemented `94/94` | `ImageLib.cpp/.h` | Complete class/API route with no accessor binary body. |
| ImageLib class | 00006E / `by-class/ImageLib.md` | Concrete 0x14 owner and compatibility typedef | UID0000K2 | true | Complete formal H with List include, public Find/inline accessor, private GetEntry; lifecycle CPP retained | implemented `92/93` | `ImageLib.cpp/.h` | Structs before use, nine out-of-line declarations, one H-only accessor, one singleton extern. |
| ImageLib file | 0000K2 / `by-file/ImageLib.md` | Lifecycle, nine facet definitions, and compiler-covered H accessor | FILE, `NexusTK/render/` | true | Child CPP plus complete UID00006E H | implemented `94/93` | `ImageLib.cpp/.h` | Includes/order complete; no accessor CPP body or raw helpers. |
| List class dependency | 000079 / `by-class/List.md` | Complete virtual `void *GetElementAt(int)` declaration at slot `+0x10` | UID0000KS | already present | Include complete owner H; no List source change | `93/94` unchanged | `List.h/.cpp`; command-25126 H is complete | Required by inline `GetResourceLayout`; verify-only dependency. |
| List file dependency | 0000KS / `by-file/List.md` | Owns complete List CPP/H and virtual accessor | FILE, `NexusTK/util/` | already present | No formal change; UID00006E includes `../util/List.h` | existing score unchanged | `List.h` SHA256 `FB6E05F7BA89037F6BB19B574B66D7F9BBE230BB5F94458802C44565C9EF341A` at dated command 25126 | Verify one header dependency; no ownership transfer. |
| ImageLib layout | 0001US / `by-type/by-struct/ImageLibLayout.md` | 0x14 object, List pointer at +0x0c | UID00006E | evidence/type | no separate source emission | `86/90` unchanged | UID00006E H | Add GetEntry use; no layout change. |
| Name row | 0001VT / `by-type/by-struct/ResourceLayoutNameRecord.md` | Exact 44-byte List/GFACE registry row | UID00006E H | true | Declaration centralized in owner H; proof-only CPP comment; no duplicate/distinct ResourceLayoutRecord | implemented `92/94` | `ImageLib.h`; no late duplicate or empty marker | GFACE `+0x20/+0x28` accesses close the type route. |
| Entry row | 0000VB / `by-item/ResourceLayoutEntry.md` | Exact 24-byte bounds/two-pointer row | UID00006E H | true | Declaration centralized in owner H; proof-only CPP comment; no late duplicate | implemented `92/94` | `ImageLib.h`; complete type before use | Complete type route. |
| ResourceLayoutStore | 0001VU / `by-type/by-struct/ResourceLayoutStore.md` | Semantic alias over generic List | none | false/no-code | CPP/H blank | `84/90` unchanged | none | Verify non-emitting alias. |
| ResourceLayoutBucket | 0001VS / `by-type/by-struct/ResourceLayoutBucket.md` | Semantic alias over ResourceLayoutNameRecord | none | false/no-code | CPP/H blank | `86/91` unchanged | none | Verify non-emitting alias. |
| Singleton semantic route | 0000QU / `by-global/g_pEPFLib.md` | One `extern ImageLib *g_pEPFLib` | UID00006E/UID0000K2 | data/compiler covered | declaration only; no second definition | `89/88` unchanged | `ImageLib.h/.cpp` | Preserve one singleton and no ResourceLayout global. |
| Singleton storage | 0001OQ / `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` | Sole four-byte global slot | UID0000K2 | data/compiler covered | no separate handwritten body | `87/91` unchanged | `ImageLib.cpp` lifecycle/global route | Preserve exact storage/no duplicate. |
| UserLook parser child | 0003RK / `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` | Sole KQ caller | UID0000P0 | true | Direct owner include in formal CPP | `92/93` unchanged | `UserLookPane.cpp`; one include/call, no local prototype | Dependency implemented only; parser preserved. |
| UserLook file | 0000P0 / `by-file/UserLookPane.md` | Parser owner/dependency route | FILE | true | Existing CPP plus owner-header include | `92/93` unchanged | `UserLookPane.cpp`; H intentionally absent | Target dependency/generated expectation implemented. |
| NewHuman bounds child | 0002V8 / `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` | GFACE Find/load/List-row path plus two KT calls and direct Riding reads | UID000092/UID0000LR | true | Complete formal CPP with three literal owner includes, exact GFACE type/accessor/rectangle copy, and both Riding field replacements | implemented `91/92` | `NewHumanImageLib.cpp`; legal type/access/field routes | Full Section 22 body applied; every branch/call/index/order/union preserved. |
| NewHuman class | 000092 / `by-class/NewHumanImageLib.md` | Complete composition class/declarations | UID0000LR | true | Preserve H; CPP receives complete UID0002V8 dependency route | `90/91` unchanged | `NewHumanImageLib.cpp/.h` | No inventory pruning or duplicate owner declarations. |
| NewHuman file | 0000LR / `by-file/NewHumanImageLib.md` | Owner file for UID0002V8 | FILE | true | Complete UID0002V8 CPP plus direct ResourceLayoutTable/Riding includes; existing H preserved | `91/91` unchanged | `NewHumanImageLib.cpp/.h` | Apply declared KT/Riding route and verify both replacements. |
| Riding class | 0000BZ / `by-class/RidingImageLib.md` | Complete API and private `ridingEpfPackage` at +0x0c | UID0000N6 | true | Complete class/extern declaration in guarded formal H; friend precedes private storage | implemented `92/94` | One `RidingImageLib.h`; no CPP class/extern duplicate | One owner declaration without accessor/public field. |
| Riding file | 0000N6 / `by-file/RidingImageLib.md` | Riding lifecycle/declaration owner | FILE | true | CPP is `#include "RidingImageLib.h"` plus retained `[[CHILDREN]]`; H owns complete declaration | `91/92` unchanged | Complete `RidingImageLib.cpp/.h` | Every method/global definition preserved in order with one guarded owner H. |
| Decoder aggregate | 000175 / `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` | Index over seven decoders | UID0000K3 | true as routed children; aggregate not an extra body | Comment/index CPP only; H blank | `88/89` unchanged | `ImageLoaders.cpp` | Verify complete exclusion and seven child bodies. |
| ImageLoaders file | 0000K3 / `by-file/ImageLoaders.md` | Canonical owner of seven decoders | FILE | true | Seven child CPP bodies; no H required for file-local APIs | `93/90` unchanged | `ImageLoaders.cpp`; all seven present, H absent | Verify-only owner route. |
| Frame aggregate | 000176 / `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` | Non-emitting frame neighborhood index | none | false as aggregate | CPP/H blank | `88/92` unchanged | none | Verify P4/P5 ownership; P6 separately ResourceLayout-owned. |
| ImageFrameTable file | 0000K1 / `by-file/ImageFrameTable.md` | P4/P5/31T/31U owner and shared type owner | FILE | true | Four child CPP bodies plus UID0000UN H types | `91/89` unchanged | `ImageFrameTable.cpp/.h`; all four and shared types present | Verify-only owner route; no P6 duplicate. |
| Archive/frame declarations | 0000UN / `by-item/EPFArchiveMetadataTable.md` | ArchiveMetadataTable, PackedArchiveRecord, FrameDrawRecord | UID0000K1 | true | H declarations; no extra CPP body | `90/92` unchanged | `ImageFrameTable.h`; type block present | Dependency for KT/P6 and excluded frame helpers. |
| LoadFrame item mirror | 0000UX / `by-item/LoadFrameDrawRecord_004D1600.md` | Semantic item mirror of P6 | UID0000BY | false/no separate emitter | blank; P6 child owns body | `89/93` unchanged | `ImageLib.cpp/.h` via UID0002P6 | Verify no duplicate item emission. |
| LoadImage item mirror | 0000UY / `by-item/LoadImageFrameTable_004D0F50.md` | Semantic item mirror of P4 | UID0000K1 | false/no separate emitter | blank; P4 child owns body | `87/91` unchanged | `ImageFrameTable.cpp` via UID0002P4 | Verify no duplicate item emission. |
| MapTile constructor successor | 0002IZ / `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md` | Exact next function at 0x4d1860 | UID00007T -> UID0000L5 | true | Existing MapTile CPP; no ResourceLayout source | `92/94` unchanged | `MapTileImageLib.cpp` | Boundary-only exclusion; successor prologue protected. |
| MapTile cluster | 000177 / `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md` | Non-emitting next-family index | none | false as aggregate | blank | `86/91` unchanged | none | Boundary-only no-overlap proof. |
| MapTile class | 00007T / `by-class/MapTileImageLib.md` | Successor class owner | UID0000L5 | true | Existing class route | `92/94` unchanged | `MapTileImageLib.cpp`; H absent | No ResourceLayout change. |
| MapTile file | 0000L5 / `by-file/MapTileImageLib.md` | Successor source file | FILE | true | Existing CPP; H absent | `91/93` unchanged | `MapTileImageLib.cpp` | No overlap with corrected aggregate endpoint. |

### Generated CPP/H Destinations

These are dated 2026-08-16 report-repair readbacks, not continuing lifecycle authority; Gate 2A dynamically rereads the latest validator-owned output.

| Generated destination | Related UIDs | Role / expected ownership | Reconstructability/formal owner | Metadata | Dated physical status | Completion disposition |
| --- | --- | --- | --- | --- | --- | --- |
| `auto-generated/NexusTK/render/ResourceLayoutTable.cpp` | 0000N5/0002KQ/0002KT | Exactly KQ then KT | formal CPP on child pages | target `95/93` | 1,339 bytes, SHA256 `69C7A5D38D98E1CA38E68019CC8530DF93CC26CE72FFE52105E0E5C7B344BA1B`; wrong KT-first/static/duplicate type plus KQ marker | Callback must produce exactly two corrected definitions in order. |
| `auto-generated/NexusTK/render/ResourceLayoutTable.h` | 0000N5/0002KQ | Two external declarations | complete formal H on KQ | target `95/93` | absent | Callback must create complete sibling H. |
| `auto-generated/NexusTK/render/ImageLib.cpp` | 0000K2/00006E/0000BY and nine out-of-line methods | One lifecycle and nine facet definitions; no accessor body | child formal CPP | file `94/93` | Dated command 25126: 12,248 bytes, SHA256 `628AF83BF2D94F5F077230D4963B37FDA085B80FCC9376FAD4D092939B1F4E20`; eight methods, wrong KO/KP/KS/KW, late structs, no GetEntry | Callback must yield nine exact definitions, no out-of-line GetResourceLayout, and no duplicate structs. |
| `auto-generated/NexusTK/render/ImageLib.h` | 00006E/0000BY/0001VT/0000VB/000079 | Complete class/row declarations and inline registry accessor | UID00006E formal H plus existing List H | class `92/93` | Dated command 25126: 1,943 bytes, SHA256 `20F5BC2213108BC4EC4EA9CF7BED9105B25C0588458D9C68C9EF80EDFCDBE2B9`; List forward only, entry forward only, eight method declarations, private Find, no accessor | Callback must include List H, place both row types before class, expose public Find and inline accessor, retain private GetEntry, and emit no convenience type. |
| `auto-generated/NexusTK/ui/panels/UserLookPane.cpp` | 0000P0/0003RK | Sole KQ caller with owner include | UID0003RK formal CPP | `92/93` unchanged | 57,758 bytes, SHA256 `D9C65463499993B7DA4A18167CF2CE4757A7C414F7F6F317610C9396FFB93F82`; local KQ prototype | Replace prototype with direct H include; preserve parser. |
| `auto-generated/NexusTK/ui/panels/UserLookPane.h` | 0000P0 | No change required by KQ include | existing owner route | `92/93` unchanged | absent | Intentional no-header/no-change for this dependency-only callback. |
| `auto-generated/NexusTK/render/NewHumanImageLib.cpp` | 0000LR/000092/0002V8 | Complete bounds definition, legal GFACE API/type route, two declared KT calls, and direct friend field reads | UID0002V8 complete formal CPP plus three literal includes | child `91/92` | Dated command 25126: 43,908 bytes, SHA256 `B78C74212DFC6130E6D68B52FAA4FF7D126F23AAD88DC85302CD8D66F3056F84`; undefined ResourceLayoutRecord/GetResourceLayout, illegal private Find call, and two stale m_rawRecordTable operands | Callback must apply the full Section 22 body, all three includes, exact GFACE row/accessor/copy, and both Riding operands. |
| `auto-generated/NexusTK/render/NewHumanImageLib.h` | 0000LR/000092 | Existing complete class declaration | existing class formal H | class `90/91` | 8,440 bytes, SHA256 `71DA3F538FC885E094013755049614EC609E30182A9B76AB8C7727D109B5A3C9` | Preserve; verify no duplicate ResourceLayout helper/Riding class or stale field declaration. |
| `auto-generated/NexusTK/render/RidingImageLib.cpp` | 0000N6/0000BZ | Owner-H include plus all lifecycle/method/global child definitions | UID0000BZ formal CPP owner shell and existing children | class `92/94` | 9,427 bytes, SHA256 `30CF4A923ED23C3116E1424A55FDEB398362F08AE83F0D5BFDD5E8F80ECA4068`; dated snapshot embeds class/extern declarations and lacks friend | Callback must move declarations to H, retain all children in order, and leave no duplicate class/extern in CPP. |
| `auto-generated/NexusTK/render/RidingImageLib.h` | 0000N6/0000BZ | Sole complete guarded declaration with narrow friendship | UID0000BZ complete formal H | class `92/94` | absent in dated snapshot | Callback must create the complete guard/include/forwards/API/fields/externs and friend-before-storage route needed by NewHuman source. |
| `auto-generated/NexusTK/render/ImageLoaders.cpp` | 0000K3/000175/0002TJ-TN/00032P/00032O | Seven excluded decoders | existing child CPP | file `93/90` | 17,712 bytes, SHA256 `1945C71FBA1F4A6C67EC728EA61E337AA838CDB68EEB7F1AA7C3B9605A003B40`; all seven definitions, zero empty markers | Verify-only; no ResourceLayout callback edit. |
| `auto-generated/NexusTK/render/ImageLoaders.h` | 0000K3 | No public declarations required for these file-local helpers | all child H blank | file `93/90` | absent | Intentional; no callback creation. |
| `auto-generated/NexusTK/render/ImageFrameTable.cpp` | 0000K1/0002P4/0002P5/00031T/00031U | Four excluded frame helpers | existing child CPP | file `91/89` | 8,542 bytes, SHA256 `56FF555BDCEF7229ECCD526463474DA4180A5512FEEF9A6D57F0DE247AC6633B`; all four definitions, no P6 | Verify-only; preserve ownership and no P6 duplicate. |
| `auto-generated/NexusTK/render/ImageFrameTable.h` | 0000K1/0000UN | Shared archive/frame declarations | UID0000UN formal H | item `90/92` | 1,024 bytes, SHA256 `A5F03970CB5D1314287EDB42DFB90676284061EAB9D3722804B7E86A4A0B5215`; ArchiveMetadataTable/FrameDrawRecord present | Verify-only dependency route. |
| `auto-generated/NexusTK/render/MapTileImageLib.cpp` | 0000L5/00007T/0002IZ | Successor family beginning at 0x4d1860 | existing MapTile source | file `91/93` | 8,735 bytes, SHA256 `AC4AED55A1C61F7141E24313A384FD4D897CAB3CC5A769FCBA48919FC1C6C06C` | Boundary-only verify; no ResourceLayout overlap/edit. |
| `auto-generated/NexusTK/render/MapTileImageLib.h` | 0000L5/00007T | Existing no-header route | no change | file `91/93` | absent | Boundary-only intentional absence; no callback creation. |

Exhaustive totals: 11 in-scope executable definitions, one compiler-covered H-only registry-row accessor, 11 separately excluded definitions, 20 exact internal gaps, 32 separately dispositioned type/data/support/boundary routes, 16 generated CPP/H destinations, and zero in-scope ResourceLayout vtable/RTTI/string/constant/static-table/data definitions.

## Direct Xref / Caller Inventory

| Address / item | Exact route | Meaning |
| --- | --- | --- |
| `0x4d0120` | `4d030a,4d054a,4d174a,4d179a,4d42e4,4d434e,4d80d2,4d819a,4d8a62,4d8b20,4e22aa,4e341a,4e3bdd` | 13 shared lazy-load calls. |
| `0x4d02f0` | 440 code xrefs, 129 modeled caller functions plus 10 unmodeled islands; zero data refs | Central public lookup. |
| `0x4d03a0` | `0x5a0042` in UID0003RK | Sole raw-profile consumer; ECX preload unused. |
| `0x4d04d0` | 25 calls: 10 in `0x584ea0`, 10 in `0x588e30`, 5 in UserListPane ctor | Tile-context wrapper. |
| `0x4d0530` | `4d8130,4d8aba,4de305,4de377,4df4cb,4ffb48,4ffbac,4ffcb7,53d8a5,598fa0,5990c0` | Bounds consumers. |
| `0x4d05a0` | 26 unmodeled calls `4d8140..4e4025` plus `4e33a4,4e394c` | External linkage proof. |
| `0x4d1600` | 81 calls: 10 modeled functions and broad unmodeled islands | Frame projection API. |
| `0x4d1730` | `0x4e99b4` | Sole frame-size consumer. |
| `0x4d1780` | `4e9888,4ffe27,595538,595559,598f82,59909b` | Six count consumers. |
| `0x4d17c0` | `4d02f9,4d0539,4d1739,4d1789,4d42d1,4d433b,4d80bf,4d8187,4d8a4f,4d8b0d,4e2297,4e3407,4e3bca` | 13 exact calls: four facet-internal and nine Human/NewHuman composition/raw-island probes; public access required. |
| GFACE row fetch | UID0002V8 `0x4e3421-0x4e3427`; matching NewHuman path `0x4e22b0-0x4e22b7` | Load private `m_pEntryList` at `+0x0c`, push resource index, call virtual `List::GetElementAt` slot `+0x10`; proves inline/compiler-covered accessor and no standalone function. |
| GFACE row fields | UID0002V8 `0x4e342c-0x4e343c` | Read unsigned word `+0x20`, pointer `+0x28`, and first 16 bytes; exact UID0001VT/UID0000VB layout, not a distinct ResourceLayoutRecord. |
| `0x4d1830` | zero code/data xrefs | Retained unused/private source helper. |
| KQ callees | GetMemoryMan, MemmoveWrapper, AllocateBufferMemory, InitRectBounds, cookie | Non-zero allocation/parser. |
| KO callees | DATFile lifecycle/read/seek/data, memory, InitRectBounds, `_wcscpy_s`, cookie | Complete loader dependencies. |
| KP/KS/KU/KV | Find, load, List; KP/KS InitRectBounds | Shared lazy route. |
| KR | EPFTileContext Initialize, KP, CopyTo | Exact wrapper. |
| KW | one List GetElementAt and inlined wide compare; 13 callers | Pointer-walk proof and public Find declaration. |
| New method | List GetElementAt slot only | Private row retrieval. |
| H-only accessor | `List::GetElementAt(int)` virtual slot `+0x10`, observed inside callers | `GetResourceLayout(int) const` is defined in-class and has no separate executable range/CPP body. |

## Documentation Evidence And IDA Status

- Current docs support the singleton/facet, private List storage, exact `ResourceLayoutNameRecord`/entry layouts, complete List virtual accessor, raw no-this status, and neighbor exclusions.
- Stale source statements additionally include undefined `ResourceLayoutRecord`, undeclared `GetResourceLayout`, private `FindResourceIndex` despite nine external sites, and `entries[0].rect` despite UID0000VB's four-scalar leading rectangle. The formal repair rejects the convenience type, defines the accessor inline, makes Find public, and copies the first 16 entry bytes through `RectBounds`.
- Dated generated snapshot `000000024889` and the 2026-08-16 report-repair physical destination readback are evidence, not continuing authority; Gate 2A must physically reread latest output.
- Dated supervisor Gate 2B history records one unsaved I01 function definition followed by a frame mismatch hard stop; I02-I11 were not run, no save occurred, and the worker was discarded. Fresh canonical reopen/read-only MCP proves ten existing functions retain their accepted states and `0x4d1830` is again decoded code without a function, name, type, or frame.

## Ranked Ownership Analysis

### 1. Narrow ResourceLayoutTable raw-helper file

- For: two external no-this ABIs, shared row semantics, physical family placement, existing file owner, cross-file callers.
- Against: no recovered source path string and only two definitions.
- Decision: strongest KQ/KT owner; complete CPP/H, not a class.

### 2. ImageLib concrete class with ResourceLayoutTable facet and public registry API

- For: one lifecycle/vtable/global, private `this+0x0c` List, nine out-of-line methods, 13 direct Find callers, and two exact compiler-covered List-slot row fetches.
- Against: exact lost typedef spelling is not symbol-proven.
- Decision: retain nine methods, make Find public, define the row accessor inline in the owner H, keep storage/GetEntry private, and do not absorb raw helpers.

### 3. Caller ownership

- For: UserLook is sole KQ caller; human-image code dominates KT calls.
- Against: generic shared bodies and multiple consumer families.
- Decision: rejected.

### Proposed new file/grouping

- Existing UID0000N5 at `NexusTK/render/ResourceLayoutTable.cpp/.h`.
- Contents: KQ position 10, KT position 20, complete H centralized on KQ.
- Excludes class methods, decoders, frame helpers, globals, and duplicate structs.

## Source Placement

- `ResourceLayoutTable.cpp/.h`: external raw-format adapters only.
- `ImageLib.cpp/.h`: lifecycle and nine out-of-line facet methods; H includes `List.h`, declares the exact rows, exposes public Find plus inline compiler-covered `GetResourceLayout`, retains private GetEntry/storage, singleton extern, and compatibility typedef.
- `UserLookPane.cpp`: include owner H and call KQ.
- `NewHumanImageLib.cpp`: use the complete UID0002V8 formal body with literal `#include "ImageLib.h"`, `#include "ResourceLayoutTable.h"`, and `#include "RidingImageLib.h"`; GFACE uses exact `ResourceLayoutNameRecord`, public Find, inline row accessor, and explicit leading-RectBounds copy; both exact KT operands are `g_pRidingImageLib->ridingEpfPackage`.
- `RidingImageLib.cpp/.h`: CPP includes its owner H and retains all `[[CHILDREN]]` method/global definitions without class/extern redeclaration; the guarded H owns the complete class/API/fields/externs and places narrow friendship immediately before private storage.
- Lost original file colocation remains confidence-only uncertainty; dedicated module is strongest compilable reconstruction.

## Range / Split / Padding / Reclassification Analysis

| Span | Size/content | Disposition |
| --- | --- | --- |
| `4d011b-4d0120` | 5 `cc` | predecessor pad outside aggregate |
| `4d02e5-4d02f0` | 11 `cc` | KO/KP |
| `4d039e-4d03a0` | 2 `cc` | KP/KQ |
| `4d0522-4d0530` | 14 `cc` | KR/KS |
| `4d059b-4d05a0` | 5 `cc` | KS/KT |
| `4d05e6-4d05f0` | 10 `cc` | KT/decoder |
| `4d0723-4d0730` | 13 `cc` | decoder pad |
| `4d07a3-4d07b0` | 13 `cc` | decoder pad |
| `4d09a7-4d09b0` | 9 `cc` | decoder pad |
| `4d0a8a-4d0a90` | 6 `cc` | decoder pad |
| `4d0c58-4d0c60` | 8 `cc` | decoder pad |
| `4d0d89-4d0d90` | 7 `cc` | decoder pad |
| `4d0f4a-4d0f50` | 6 `cc` | decoder/frame boundary |
| `4d15c5-4d15d0` | 11 `cc` | frame pad |
| `4d15fc-4d1600` | 4 `cc` | P5/P6 |
| `4d165d-4d1660` | 3 `cc` | P6/frame helper |
| `4d1704-4d1710` | 12 `cc` | frame helper pad |
| `4d172d-4d1730` | 3 `cc` | frame/ResourceLayout |
| `4d1773-4d1780` | 13 `cc` | KU/KV |
| `4d17b3-4d17c0` | 13 `cc` | KV/KW |
| `4d182f-4d1830` | 1 `cc` | KW/new method |
| `4d1830-4d1860` | 48 code bytes | new exact method |
| `4d1860` | successor prologue | MapTileImageLib, no trailing pad |

UID000174 is same-UID renamed/ranged to `by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md`, remains `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank CPP/H. New child receives a real validator UID during callback; no pseudo UID is declared.

## Negative Evidence Summary

- No independent ResourceLayout allocation/lifecycle/vtable/RTTI/storage/global.
- No KQ/KT receiver; both clean stack args and KQ overwrites caller ECX.
- No KQ loop/sentinel/zero-fill/free/guard.
- No unique KT table type; accepted ArchiveMetadataTable matches.
- No semantic KP/KS return value.
- No xref to `0x4d1830`; non-use does not make complete authored code padding.
- No family-owned literal/static/table/vtable/RTTI/data island.
- Adjacency does not transfer decoder/frame ownership.

## IDA Rename / Type / Comment Recommendations

Execution contract: fresh 2026-08-17 `idb_list` enumerated sole active canonical session `supervisor_uid0000n5_postdiscard_20260817`; runtime attestation succeeded for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at `2026-08-17T14:08:51.643994Z`, and bounded health returned `status:ok`, image base `0x400000`, Hex-Rays ready, string cache ready/2,068 entries, and non-blocking `auto_analysis_ready:false`. Current public schemas are `define_func {database,items:{addr,end}}` and `rename {database,batch:{func:{addr,name},pure,allow_overwrite,dry_run,stop_on_error}}`. The literal requests below are bound to that dated repair session. Immediately before Gate 2B, enumerate/runtime-attest again; if the active canonical session differs, stop and rebind every I01-I11 request only after repeating every I01-I11/P6 literal prestate and destination-collision read. Execute I01-I11 in order. Any prestate, destination collision, mutation response, boundary, frame, comment channel, hash, xref, or immediate poststate mismatch is a hard stop: perform no further mutation and do not save.

Dated failed-attempt receipt: the supervisor created a collision-safe durable backup and verified it byte-identical before mutation. I01 `define_func` succeeded only in unsaved worker state, creating the exact 0x30-byte function and the two-row frame documented below. Because the prior report required four rows, the supervisor hard-stopped before I02-I11, made no save, discarded that worker, and reopened canonical IDB state. Fresh read-only session `supervisor_uid0000n5_postdiscard_20260817` proves the raw I01 prestate and absent destination restored; the backup and canonical disk remained byte-identical. This history is evidence for the deterministic staged poststate, not execution credit.

**I01 - define function**

- Classification: apply.
- Endpoint: `define_func` request `{"database":"supervisor_uid0000n5_postdiscard_20260817","items":{"addr":"0x004d1830","end":"0x004d1860"}}`.
- Literal prestate: exact one-byte code item `[0x004d1830,0x004d1831)`; name absent; type absent; function absent; AR absent; AP absent; FR not applicable; FP not applicable. Proposed function range `[0x004d1830,0x004d1860)` is exactly 48 bytes with SHA256 `3505E796AA1F9C411DAC68C3E1015E9AC053ECA55C83484BB6568B436DD01BE5`; zero inbound code xrefs; zero inbound data xrefs. Boundary items are exact predecessor data item `[0x004d182f,0x004d1830)` and exact successor function `[0x004d1860,0x004d199e)`, name `sub_4D1860`, declaration `_DWORD *__thiscall(_DWORD *this)`.
- Expected poststate and permitted deltas: function `[0x004d1830,0x004d1860)` exists with name `sub_4D1830`; type remains absent; complete frame has zero locals and exactly two rows, `__saved_registers@0x0/0x4/_DWORD` and `__return_address@0x4/0x4/_UNKNOWN *`; no `arg_0`, `arg_4`, or other argument row exists. Function state changes absent -> present, name changes absent -> `sub_4D1830`, frame changes not applicable -> the exact two rows, FR changes not applicable -> absent, and FP changes not applicable -> absent. AR remains absent; AP remains absent; type remains absent; exact 48 bytes/hash, zero inbound code/data xrefs, predecessor item, and successor name/declaration/range remain unchanged.
- Protected fields and immediate readback: only the function boundary, generated `sub_4D1830` name, and exact two-row zero-local frame may appear. Immediately reread function existence/name/type, both frame rows and zero-local count, independently AR, AP, FR, FP, range/hash/xrefs, predecessor, and successor. Any additional frame row, any type, or any difference from the literal expected poststate is a hard stop with no I02-I11 mutation and no save.
- Evidence/confidence: very strong complete prologue, branches, two `retn 8` exits, List call and row math prove two source-facing stack arguments, while the public `define_func`/immediate `stack_frame` receipt proves that absent type leaves those arguments unmaterialized in IDA. The formal CPP/H declaration remains the source authority; no IDA type action is needed for source closure.

**I02 - staged rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d1830","name":"ResourceLayoutTable__GetEntry"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal post-I01 prestate: function `[0x004d1830,0x004d1860)` exists with name `sub_4D1830`; type absent; complete frame has zero locals and exactly two rows, `__saved_registers@0x0/0x4/_DWORD` and `__return_address@0x4/0x4/_UNKNOWN *`; no argument row exists; AR absent; AP absent; FR absent; FP absent; exact 48 bytes, SHA256 `3505E796AA1F9C411DAC68C3E1015E9AC053ECA55C83484BB6568B436DD01BE5`; zero inbound code xrefs; zero inbound data xrefs; exact predecessor data item `[0x004d182f,0x004d1830)`; exact successor function `[0x004d1860,0x004d199e)`, name `sub_4D1860`, declaration `_DWORD *__thiscall(_DWORD *this)`; destination `ResourceLayoutTable__GetEntry` absent.
- Expected poststate and sole permitted delta: function `[0x004d1830,0x004d1860)` has name `ResourceLayoutTable__GetEntry`; type remains absent; complete frame remains zero locals and exactly `__saved_registers@0x0/0x4/_DWORD`, `__return_address@0x4/0x4/_UNKNOWN *`, with no argument row; AR absent; AP absent; FR absent; FP absent; exact 48 bytes/SHA256, zero inbound code/data xrefs, predecessor item, and successor name/declaration/range remain unchanged. Only the function name changes from `sub_4D1830` to `ResourceLayoutTable__GetEntry`.
- Protected fields and immediate readback: immediately reread the new name plus the complete literal type/two-row frame/zero-local/comment/range/hash/xref/predecessor/successor state. Any additional frame row, any type, any destination collision, any rename response other than one success, or any poststate mismatch is a hard stop with no I03-I11 mutation and no save.
- Evidence/confidence: strong semantic/source ownership plus the absent-destination lookup and current public pure-rename schema support a name-only action; the complete staged readback prevents the rename from concealing any frame/type side effect.

**I03 - KO rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d0120","name":"ResourceLayoutTable__LoadResourceIndex"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D0120`; type `int __thiscall(_DWORD **this, wchar_t *ArgList)`; complete frame has exactly 17 rows: `Source@0x10/0x4/wchar_t *`, `var_64@0x14/0x14/DATFile`, `offset@0x28/0x4/int`, `var_4C@0x2c/0x2/_WORD`, `var_48@0x30/0x2/_WORD`, `var_44@0x34/0x2/_WORD`, `var_40@0x38/0x2/_WORD`, `Destination@0x3c/0x2/wchar_t`, `buffer@0x5c/0x8/unsigned __int16[4]`, `bounds@0x64/0x4/struct RectBounds *`, `var_10@0x68/0x4/_DWORD`, `var_C@0x6c/0x4/_DWORD`, `var_4@0x74/0x4/_DWORD`, `__saved_registers@0x78/0x4/_DWORD`, `__return_address@0x7c/0x4/_UNKNOWN *`, `ArgList@0x80/0x4/wchar_t *`, `arg_4@0x84/0x4/_DWORD`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d0120,0x004d02e5)`, 453 bytes, SHA256 `CB5CB9EA5E35F8B90731B0E5417B8B14D063F4E67E8256BDFC70DD78623EA6F9`; exact inbound code xrefs `0x004d030a,0x004d054a,0x004d174a,0x004d179a,0x004d42e4,0x004d434e,0x004d80d2,0x004d819a,0x004d8a62,0x004d8b20,0x004e22aa,0x004e341a,0x004e3bdd`; zero inbound data xrefs; predecessor data item `[0x004d011b,0x004d0120)` and successor padding item `[0x004d02e5,0x004d02f0)` remain exact; destination `ResourceLayoutTable__LoadResourceIndex` absent.
- Expected poststate: name `ResourceLayoutTable__LoadResourceIndex`; type, all 17 frame rows, AR, AP, FR, FP, exact range, 453 body bytes/hash, 13 code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I04-I11 mutation and no save.

**I04 - KP rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d02f0","name":"ResourceLayoutTable__LookupLayoutEntry"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `ResourceLayoutTable_LookupLayoutEntry`; type `void __thiscall(ResourceLayoutTable *this, const wchar_t *resourceName, __int16 frameIndex, EPFTileContext *outContext)`; complete frame has exactly five rows: `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, `ArgList@0xc/0x4/unsigned __int16 *`, `frameIndex@0x10/0x2/__int16`, `outContext@0x14/0x4/EPFTileContext *`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d02f0,0x004d039e)`, 174 bytes, SHA256 `E4DDDDACB40CEDBE240F91399FDC8CA4CBA79D7A5D1C1C2A24EF5664A4FB21B5`; exact 440 inbound code xrefs from the complete Section 15 grouped inventory; zero inbound data xrefs; predecessor padding item `[0x004d02e5,0x004d02f0)` and successor padding item `[0x004d039e,0x004d03a0)` remain exact; destination `ResourceLayoutTable__LookupLayoutEntry` absent.
- Expected poststate: name `ResourceLayoutTable__LookupLayoutEntry`; type, all five frame rows, AR, AP, FR, FP, exact range, 174 body bytes/hash, 440 code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes. The source `int` correction is not an IDA set_type action.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I05-I11 mutation and no save.

**I05 - KQ rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d03a0","name":"ResourceLayoutRawBufferLookupEntry"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D03A0`; type `char *__stdcall(char *Src, struct RectBounds *)`; complete frame has exactly 14 rows: `var_4C@0xc/0x4/_DWORD`, `var_48@0x10/0x4/_DWORD`, `var_44@0x14/0x2/_WORD`, `var_40@0x18/0x2/_WORD`, `var_3C@0x1c/0x2/_WORD`, `var_38@0x20/0x2/_WORD`, `var_34@0x24/0x4/_DWORD`, `destination@0x48/0x8/unsigned __int16[4]`, `var_8@0x50/0x4/_DWORD`, `var_4@0x54/0x4/_DWORD`, `__saved_registers@0x58/0x4/_DWORD`, `__return_address@0x5c/0x4/_UNKNOWN *`, `Src@0x60/0x4/void *`, `arg_4@0x64/0x4/int`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d03a0,0x004d04d0)`, 304 bytes, SHA256 `F62C5EF9B96FDBB2833DFB414353E29CB0CE2F77EE78D7A4E647AD1D98B5D2F4`; sole inbound code xref `0x005a0042`; zero inbound data xrefs; predecessor padding item `[0x004d039e,0x004d03a0)` and exact successor function start `0x004d04d0` remain unchanged; destination `ResourceLayoutRawBufferLookupEntry` absent.
- Expected poststate: name `ResourceLayoutRawBufferLookupEntry`; type, all 14 frame rows, AR, AP, FR, FP, exact range, 304 body bytes/hash, sole code xref, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I06-I11 mutation and no save.

**I06 - KR rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d04d0","name":"ResourceLayoutTable__CopyEntryTileContext"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D04D0`; type `void __thiscall(ResourceLayoutTable *this, unsigned __int16 *ArgList, __int16 frameIndex, int)`; complete frame has exactly seven rows: `outContext@0xc/0x28/EPFTileContext`, `var_4@0x34/0x4/_DWORD`, `__saved_registers@0x38/0x4/_DWORD`, `__return_address@0x3c/0x4/_UNKNOWN *`, `ArgList@0x40/0x4/unsigned __int16 *`, `frameIndex@0x44/0x2/__int16`, `arg_8@0x48/0x4/int`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d04d0,0x004d0522)`, 82 bytes, SHA256 `C5676A33C1FD1CF966DBB936D5601DC51639E6363B236580E21F6A2E03E3D1A8`; exact inbound code xrefs `0x005850c7,0x005850dc,0x005850f1,0x00585106,0x0058511b,0x00585130,0x00585145,0x0058515a,0x0058516f,0x00585184,0x00588fae,0x00588fc3,0x00588fd8,0x00588fed,0x00589002,0x00589017,0x0058902c,0x00589041,0x00589056,0x0058906b,0x0059e7e1,0x0059e801,0x0059e822,0x0059e840,0x0059e860`; zero inbound data xrefs; exact predecessor function end `0x004d04d0` and successor padding item `[0x004d0522,0x004d0530)` remain unchanged; destination `ResourceLayoutTable__CopyEntryTileContext` absent.
- Expected poststate: name `ResourceLayoutTable__CopyEntryTileContext`; type, all seven frame rows, AR, AP, FR, FP, exact range, 82 body bytes/hash, 25 code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I07-I11 mutation and no save.

**I07 - KS rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d0530","name":"ResourceLayoutTable__GetEntryRect"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D0530`; type `void __thiscall(int this, unsigned __int16 *ArgList, int, struct RectBounds *bounds)`; complete frame has exactly five rows: `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, `ArgList@0xc/0x4/unsigned __int16 *`, `arg_4@0x10/0x4/int`, `bounds@0x14/0x4/struct RectBounds *`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d0530,0x004d059b)`, 107 bytes, SHA256 `F08F1825FAD936D414EFC757A11ED7E43438B5ABC52EC390429FEFE3D71CA85A`; exact inbound code xrefs `0x004d8130,0x004d8aba,0x004de305,0x004de377,0x004df4cb,0x004ffb48,0x004ffbac,0x004ffcb7,0x0053d8a5,0x00598fa0,0x005990c0`; zero inbound data xrefs; predecessor padding item `[0x004d0522,0x004d0530)` and successor padding item `[0x004d059b,0x004d05a0)` remain exact; destination `ResourceLayoutTable__GetEntryRect` absent.
- Expected poststate: name `ResourceLayoutTable__GetEntryRect`; type, all five frame rows, AR, AP, FR, FP, exact range, 107 body bytes/hash, 11 code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I08-I11 mutation and no save.

**I08 - KT rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d05a0","name":"ResourceLayoutRawRecordGetEntryRect"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D05A0`; type `_DWORD *__stdcall(unsigned __int16 *, int, _DWORD *)`; complete frame has exactly five rows: `__saved_registers@0x0/0x4/_DWORD`, `__return_address@0x4/0x4/_UNKNOWN *`, `arg_0@0x8/0x4/_DWORD`, `arg_4@0xc/0x4/_DWORD`, `arg_8@0x10/0x4/_DWORD`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d05a0,0x004d05e6)`, 70 bytes, SHA256 `9451095D30885DBA7BAC9E00846B4A6DABC66625BFB8A04470F40F2154178519`; exact inbound code xrefs `0x004d8140,0x004d81ee,0x004d8232,0x004d8276,0x004d82ba,0x004d82fb,0x004d8339,0x004d8377,0x004d83b8,0x004d8401,0x004d844c,0x004d855c,0x004d8acd,0x004d8b71,0x004d8bab,0x004d8be2,0x004d8c19,0x004d8c53,0x004d8c90,0x004d8ccd,0x004d8d07,0x004d8d41,0x004d8d71,0x004d8e5a,0x004e33a4,0x004e394c,0x004e3cc9,0x004e4025`; zero inbound data xrefs; predecessor padding item `[0x004d059b,0x004d05a0)` and successor padding item `[0x004d05e6,0x004d05f0)` remain exact; destination `ResourceLayoutRawRecordGetEntryRect` absent.
- Expected poststate: name `ResourceLayoutRawRecordGetEntryRect`; type, all five frame rows, AR, AP, FR, FP, exact range, 70 body bytes/hash, 28 code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I09-I11 mutation and no save.

**I09 - KU rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d1730","name":"ResourceLayoutTable__GetFrameSize"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D1730`; type `_WORD *__thiscall(int this, unsigned __int16 *ArgList, _WORD *, _WORD *)`; complete frame has exactly five rows: `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, `ArgList@0xc/0x4/unsigned __int16 *`, `arg_4@0x10/0x4/int`, `arg_8@0x14/0x4/int`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d1730,0x004d1773)`, 67 bytes, SHA256 `2D32873F45C35253485C79F15D057FA79BCF5C3887576A73E1C6813735776C58`; sole inbound code xref `0x004e99b4`; zero inbound data xrefs; predecessor data item `[0x004d172d,0x004d1730)` and successor padding item `[0x004d1773,0x004d1780)` remain exact; destination `ResourceLayoutTable__GetFrameSize` absent.
- Expected poststate: name `ResourceLayoutTable__GetFrameSize`; type, all five frame rows, AR, AP, FR, FP, exact range, 67 body bytes/hash, sole code xref, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I10-I11 mutation and no save.

**I10 - KV rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d1780","name":"ResourceLayoutTable__GetEntryCount"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D1780`; type `__int16 __thiscall(int this, unsigned __int16 *ArgList)`; complete frame has exactly three rows: `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, `ArgList@0xc/0x1/char`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d1780,0x004d17b3)`, 51 bytes, SHA256 `2D3D5DBF8FEB16EF899CB06A122D2ADE3C164E180D3BA3E7EC4BDF35CC54E408`; exact inbound code xrefs `0x004e9888,0x004ffe27,0x00595538,0x00595559,0x00598f82,0x0059909b`; zero inbound data xrefs; predecessor padding item `[0x004d1773,0x004d1780)` and successor padding item `[0x004d17b3,0x004d17c0)` remain exact; destination `ResourceLayoutTable__GetEntryCount` absent.
- Expected poststate: name `ResourceLayoutTable__GetEntryCount`; type, all three frame rows, AR, AP, FR, FP, exact range, 51 body bytes/hash, six code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no I11 mutation and no save.

**I11 - KW rename**

- Classification: apply.
- Endpoint: `rename` with pure:true, request `{"database":"supervisor_uid0000n5_postdiscard_20260817","batch":{"func":{"addr":"0x004d17c0","name":"ResourceLayoutTable__FindResourceIndex"},"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
- Literal prestate: name `sub_4D17C0`; type `int __thiscall(_DWORD *this, const unsigned __int16 *)`; complete frame has exactly three rows: `__saved_registers@0xc/0x4/_DWORD`, `__return_address@0x10/0x4/_UNKNOWN *`, `arg_0@0x14/0x4/_DWORD`; AR absent; AP absent; FR absent; FP absent; exact function range `[0x004d17c0,0x004d182f)`, 111 bytes, SHA256 `2F0168D65498440BDD742B3AF451982FA98945AB03CB463D6E9596A980726D0E`; exact inbound code xrefs `0x004d02f9,0x004d0539,0x004d1739,0x004d1789,0x004d42d1,0x004d433b,0x004d80bf,0x004d8187,0x004d8a4f,0x004d8b0d,0x004e2297,0x004e3407,0x004e3bca`; zero inbound data xrefs; predecessor padding item `[0x004d17b3,0x004d17c0)` and successor data item `[0x004d182f,0x004d1830)` remain exact; destination `ResourceLayoutTable__FindResourceIndex` absent.
- Expected poststate: name `ResourceLayoutTable__FindResourceIndex`; type, all three frame rows, AR, AP, FR, FP, exact range, 111 body bytes/hash, 13 code xrefs, and zero data xrefs remain exactly as in the literal prestate. Only the function name changes.
- Protected fields and immediate readback: immediately reread the new name and every literal declaration/frame/comment/range/hash/xref/boundary field. Any mismatch or destination collision is a hard stop with no further mutation and no save.

**P6 protected no-change readback - C55**

- Classification/action: already-present protected no-change; no mutation endpoint, no comment endpoint, no type endpoint, and no rename endpoint applies.
- Literal current identity: exact function `[0x004d1600,0x004d165d)`, name `ResourceLayoutTable__LoadFrameDrawRecord`, declaration `void __thiscall ResourceLayoutTable__LoadFrameDrawRecord(ResourceLayoutTable *this, const ArchiveMetadataTable *table, int frameIndex, FrameDrawRecord *outRecord)`.
- Literal complete frame: zero locals and exactly five rows: `__saved_registers@0x0/0x4/_DWORD`, `__return_address@0x4/0x4/_UNKNOWN *`, `frameTable@0x8/0x4/ArchiveMetadataTable *`, `frameIndex@0xc/0x4/int`, `record@0x10/0x4/FrameDrawRecord *`.
- Literal comment channels: AR absent; AP absent; FR exactly `Source ResourceLayoutTable/ImageLib-facet member LoadFrameDrawRecord. Callers deliberately establish g_pEPFLib in ECX even though this body does not consume the receiver.`; FP absent.
- Literal body/range evidence: exact function `[0x004d1600,0x004d165d)`, 93 bytes, 32 instructions, four basic blocks, SHA256 `8A4817839F3CC4CE7546A51F0E4BA8410E1342C921A49B9BF060145A9BF3BB21`; zero direct callees; zero inbound data xrefs; predecessor padding item `[0x004d15fc,0x004d1600)` and successor padding item `[0x004d165d,0x004d1660)` remain exact.
- Literal 81 inbound code xrefs: `0x004d1aec,0x004d51cc,0x004d51f8,0x004d5224,0x004d5250,0x004d527c,0x004d52a8,0x004d52d4,0x004d5300,0x004d5334,0x004d5384,0x004d53cb,0x004d53f7,0x004d5423,0x004d544f,0x004d547b,0x004d54a7,0x004d54d3,0x004d54ff,0x004d552b,0x004d5572,0x004d55a7,0x004d5616,0x004d569c,0x004d57aa,0x004d6229,0x004d6249,0x004d6269,0x004d6289,0x004d62a3,0x004d62b3,0x004d62cd,0x004d62ed,0x004d630d,0x004d632d,0x004d634d,0x004d638f,0x004d63ec,0x004d6409,0x004d6465,0x004d6485,0x004d64a5,0x004d64c5,0x004d6522,0x004d6ddd,0x004d6e0c,0x004d6e3b,0x004d6e67,0x004d6e93,0x004d6ec2,0x004d6ef1,0x004d6f20,0x004d6f4f,0x004d6f77,0x004d718e,0x004d71db,0x004d7222,0x004d7269,0x004d72b0,0x004d72f7,0x004d733e,0x004d7385,0x004d73c9,0x004d740a,0x004d744a,0x004d74c8,0x004d755f,0x004d75d0,0x004dcb74,0x004dd561,0x004de208,0x004e0dc3,0x004e2bf3,0x004e2f2b,0x004e4261,0x004e43e7,0x004e445e,0x004e4b7a,0x004e4e21,0x004ff86e,0x0055b642`.
- Protected fields: name, complete declaration, all five frame rows and their names/offsets/widths/types, zero-local count, AR, AP, FR, FP, start/end, 93 body bytes/hash, instruction/block counts, zero callees, all 81 code xrefs, and zero data xrefs.
- Deterministic immediate/final readback: every protected field must equal the literal current state above before I01 and again after I11; P6 receives no change. If either readback differs, or any ordered I01-I11 response/poststate differs, stop immediately, perform no further mutation, and do not save.

No `set_type` or comment endpoint is recommended. Required UDTs are absent/incomplete in IDA and source declarations close project output without a broad unsafe type transaction. Final reread proves one new function boundary with the exact observed two-row zero-local frame and no argument rows, ten exact names including the staged new name, no type/comment/byte/hash/xref/boundary change, the complete literal P6 C55 no-change state above, and unchanged successor. Save only after complete success.

## First-Draft C++ Recommendation

CPP disposition: exact owner-specific formal replacement/insertion text follows. Existing unaffected ImageLib lifecycle, KR, P6, KU, and KV bodies stay unchanged. UID0002V8's GFACE branch uses the established owner type/API only: `ResourceLayoutNameRecord`, public `FindResourceIndex`, compiler-covered inline `GetResourceLayout`, and an explicit 16-byte leading-rectangle copy.

```cpp
// UID0002KQ formal CPP, position 10 in ResourceLayoutTable.cpp.
#include "ResourceLayoutTable.h"

#include "EPFTileContext.h"
#include "ImageFrameTable.h"
#include "ImageLib.h"
#include "../ui/core/RectBounds.h"
#include "../util/MemoryMan.h"

void __stdcall ResourceLayoutRawBufferLookupEntry(
    const unsigned char *buffer,
    EPFTileContext *outContext)
{
    MemoryMan *memory = GetMemoryMan();
    unsigned short header[4];
    int entryTableOffset;
    memory->MemmoveWrapper(header, buffer, sizeof(header));
    memory->MemmoveWrapper(&entryTableOffset, buffer + 8,
                           sizeof(entryTableOffset));

    ResourceLayoutEntry *entries =
        static_cast<ResourceLayoutEntry *>(
            memory->AllocateBufferMemory(
                sizeof(ResourceLayoutEntry) * (header[0] + 1)));
    const unsigned char *record = buffer + 12 + entryTableOffset;
    short top;
    short left;
    short bottom;
    short right;
    int offsets[2];
    memory->MemmoveWrapper(&top, record, sizeof(top));
    memory->MemmoveWrapper(&left, record + 2, sizeof(left));
    memory->MemmoveWrapper(&bottom, record + 4, sizeof(bottom));
    memory->MemmoveWrapper(&right, record + 6, sizeof(right));
    memory->MemmoveWrapper(offsets, record + 8, sizeof(offsets));

    InitRectBounds(reinterpret_cast<RectBounds *>(&entries[0]),
                   left, top, right, bottom);
    unsigned char *payloadBase =
        const_cast<unsigned char *>(buffer + 12);
    entries[0].pixelData = payloadBase + offsets[0];
    entries[0].encodedMaskData = payloadBase + offsets[1];

    if (outContext != 0) {
        outContext->pixelData = entries[0].pixelData;
        outContext->rowStridePixels =
            entries[0].right - entries[0].left;
        outContext->bounds =
            *reinterpret_cast<RectBounds *>(&entries[0]);
        // Preserve the original uninitialized next-row read and leak.
        outContext->encodedMaskByteCount =
            static_cast<int>(entries[1].pixelData -
                             entries[0].encodedMaskData);
        outContext->encodedMaskBytes =
            entries[0].encodedMaskData;
    }
}

// UID0002KT formal CPP, position 20.
RectBounds *__stdcall ResourceLayoutRawRecordGetEntryRect(
    const ArchiveMetadataTable *table,
    int entryIndex,
    RectBounds *bounds)
{
    if (entryIndex < table->frameCount) {
        *bounds = table->records[entryIndex].bounds;
    } else {
        InitRectBounds(bounds, 0, 0, 0, 0);
    }
    return bounds;
}

// UID00006E formal ImageLib.cpp preamble.
#include "ImageLib.h"
#include "EPFTileContext.h"
#include "ImageFrameTable.h"
#include "../archive/DATFile.h"
#include "../ui/core/RectBounds.h"
#include "../util/List.h"
#include "../util/MemoryMan.h"
#include <wchar.h>

// UID0002KO replacement.
int ResourceLayoutTable::LoadResourceIndex(
    const wchar_t *resourceName)
{
    DATFile file;
    file.Open(resourceName);
    unsigned short header[4];
    int entryTableOffset;
    file.Read(header, sizeof(header));
    file.Read(&entryTableOffset, sizeof(entryTableOffset));
    file.Seek(entryTableOffset, 1);

    const int entryCount = header[0];
    ResourceLayoutEntry *entries =
        static_cast<ResourceLayoutEntry *>(
            GetMemoryMan()->AllocateBufferMemory(
                sizeof(ResourceLayoutEntry) * (entryCount + 1)));
    for (int index = 0; index < entryCount; ++index) {
        short top;
        short left;
        short bottom;
        short right;
        int pixelDataOffset;
        int encodedMaskOffset;
        file.Read(&top, sizeof(top));
        file.Read(&left, sizeof(left));
        file.Read(&bottom, sizeof(bottom));
        file.Read(&right, sizeof(right));
        file.Read(&pixelDataOffset, sizeof(pixelDataOffset));
        file.Read(&encodedMaskOffset, sizeof(encodedMaskOffset));
        InitRectBounds(
            reinterpret_cast<RectBounds *>(&entries[index]),
            left, top, right, bottom);
        entries[index].pixelData =
            reinterpret_cast<unsigned char *>(pixelDataOffset);
        entries[index].encodedMaskData =
            reinterpret_cast<unsigned char *>(encodedMaskOffset);
    }

    file.Seek(0, 0);
    unsigned char *payloadBase =
        static_cast<unsigned char *>(file.GetDataPointer()) + 12;
    for (int index = 0; index < entryCount; ++index) {
        entries[index].pixelData +=
            reinterpret_cast<unsigned int>(payloadBase);
        entries[index].encodedMaskData +=
            reinterpret_cast<unsigned int>(payloadBase);
    }
    InitRectBounds(
        reinterpret_cast<RectBounds *>(&entries[entryCount]),
        0, 0, 0, 0);
    entries[entryCount].pixelData = payloadBase + entryTableOffset;
    entries[entryCount].encodedMaskData =
        payloadBase + entryTableOffset;

    ResourceLayoutNameRecord record;
    wcscpy_s(record.name, 16, resourceName);
    record.entryCount = header[0];
    record.frameWidth = header[1];
    record.frameHeight = header[2];
    record.reservedHeaderWord = header[3];
    record.entries = entries;
    m_pEntryList->Append(1, &record);
    file.Close();
    return m_pEntryList->GetCount() - 1;
}

// UID0002KP replacement.
void ResourceLayoutTable::LookupLayoutEntry(
    const wchar_t *resourceName,
    int frameIndex,
    EPFTileContext *outContext)
{
    int resourceIndex = FindResourceIndex(resourceName);
    if (resourceIndex == -1)
        resourceIndex = LoadResourceIndex(resourceName);
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    ResourceLayoutEntry *entry = 0;
    if (frameIndex >= 0 && frameIndex < record->entryCount)
        entry = &record->entries[frameIndex];

    if (outContext != 0) {
        if (entry != 0) {
            outContext->pixelData = entry->pixelData;
            outContext->rowStridePixels =
                entry->right - entry->left;
            outContext->bounds =
                *reinterpret_cast<RectBounds *>(entry);
            outContext->encodedMaskByteCount =
                static_cast<int>(
                    record->entries[frameIndex + 1].pixelData -
                    entry->encodedMaskData);
            outContext->encodedMaskBytes = entry->encodedMaskData;
        } else {
            outContext->pixelData = 0;
            outContext->rowStridePixels = 0;
            InitRectBounds(&outContext->bounds, 0, 0, 0, 0);
            outContext->encodedMaskByteCount = 0;
            outContext->encodedMaskBytes = 0;
        }
    }
}

// UID0002KS replacement.
void ResourceLayoutTable::GetEntryRect(
    const wchar_t *resourceName,
    int frameIndex,
    RectBounds *bounds)
{
    int resourceIndex = FindResourceIndex(resourceName);
    if (resourceIndex == -1)
        resourceIndex = LoadResourceIndex(resourceName);
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    if (frameIndex >= 0 && frameIndex < record->entryCount) {
        *bounds = *reinterpret_cast<RectBounds *>(
            &record->entries[frameIndex]);
    } else {
        InitRectBounds(bounds, 0, 0, 0, 0);
    }
}

// UID0002KW replacement.
int ResourceLayoutTable::FindResourceIndex(
    const wchar_t *resourceName)
{
    const int count = m_pEntryList->GetCount();
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(0));
    for (int index = 0; index < count; ++index, ++record) {
        if (wcscmp(record->name, resourceName) == 0)
            return index;
    }
    return -1;
}

// New exact child [0x004d1830,0x004d1860).
ResourceLayoutEntry *ResourceLayoutTable::GetEntry(
    int resourceIndex,
    int frameIndex)
{
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    if (frameIndex < 0 || frameIndex >= record->entryCount)
        return 0;
    return &record->entries[frameIndex];
}

// UID0003RK replaces its local KQ prototype with:
#include "../../render/ResourceLayoutTable.h"

// UID0002V8 complete formal CPP replacement in NewHumanImageLib.cpp.
#include "ImageLib.h"
#include "ResourceLayoutTable.h"
#include "RidingImageLib.h"

int NewHumanImageLib::CalculateCompositionBounds(
    const int *drawOrder,
    const NewHumanCompositionState &inputState,
    int sequence,
    int frame,
    RectBounds *bounds,
    RectBounds *projectedBounds,
    char direction)
{
    NewHumanCompositionState state = inputState;
    RectBounds partBounds;
    const RidingDefinition *ridingDefinition;
    int ridingYOffset;
    int normalizedSequence;
    int drawIndex;
    int tag;
    int bucket;
    int height;
    int projectedLeft;
    int projectedRight;
    float horizontalOffset;
    float verticalOffset;
    bool secondAccessoryPass;
    bool mergePart;
    int result = 0;

    ridingYOffset = 0;
    if (state.compositionMode == 3)
        ridingYOffset = state.ridingYOffset;

    if (state.baseBodyPartId == 0)
        return result;

    RectBoundsClear(bounds, 0, 0, 0, 0);

    if (state.compositionMode == 2) {
        result = RectBoundsSet(bounds, 0, 0, g_mapTilePixelHeight, g_mapTilePixelWidth);
        goto FinishBounds;
    }

    if (state.specialCompositionPartId != 0xffff) {
        ResolveCompositionPartRect(
            &m_partEntries[17],
            state.specialCompositionPartId,
            sequence,
            frame,
            ridingYOffset,
            0,
            &partBounds);
        RectBoundsUnion(bounds, &partBounds);

        if (state.compositionMode == 3) {
            ridingDefinition =
                g_pRidingImageLib->GetDefinitionOrDefault(state.ridingDefinitionIndex);
            ResourceLayoutRawRecordGetEntryRect(
                g_pRidingImageLib->ridingEpfPackage,
                ridingDefinition->baseRectIndex + 3 * sequence +
                    kNewHumanRidingFrameRectOffsets[frame] - 24,
                &partBounds);
        }

        RectBoundsUnion(bounds, &partBounds);
        result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
        goto FinishBounds;
    }

    if (state.compositionMode == 1) {
        int gfaceIndex = g_pEPFLib->FindResourceIndex(L"GFACE.EPF");
        if (gfaceIndex == -1)
            gfaceIndex = g_pEPFLib->LoadResourceIndex(L"GFACE.EPF");

        const ResourceLayoutNameRecord *gface =
            g_pEPFLib->GetResourceLayout(gfaceIndex);
        if (gface->entryCount != 0 && gface->entries != NULL)
            *bounds = *reinterpret_cast<const RectBounds *>(
                &gface->entries[0]);
        else
            RectBoundsSet(bounds, 0, 0, 0, 0);

        result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
        goto FinishBounds;
    }

    normalizedSequence = sequence;
    if (sequence >= 38 && sequence <= 50 && sequence != 47 && sequence != 49)
        normalizedSequence = direction + 55;

    secondAccessoryPass = false;
    for (drawIndex = 0; drawIndex < 30; ++drawIndex) {
        tag = drawOrder[drawIndex];
        mergePart = false;
        RectBoundsClear(&partBounds, 0, 0, 0, 0);

        switch (tag) {
        case 0x32:
            if (state.alternateBodyPartId == 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[0], state.baseBodyPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            else
                ResolveCompositionPartRect(
                    &m_partEntries[1], state.alternateBodyPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x33:
            state.baseBodyPartId = (unsigned short)(state.baseBodyPartId - 200);
            if (sequence >= 38 && sequence <= 54)
                ResolveCompositionPartRect(
                    &m_partEntries[3], state.baseBodyPartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            else
                ResolveCompositionPartRect(
                    &m_partEntries[2], state.baseBodyPartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x34:
            if (state.acc2drwSelector != 0xffff &&
                !m_acc2drwEntries[state.acc2drwSelector].enabled[0])
                break;
            if (state.acc2drwPart0Id != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[4], state.acc2drwPart0Id, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x35:
            if (state.acc2drwSelector != 0xffff &&
                !m_acc2drwEntries[state.acc2drwSelector].enabled[1])
                break;
            if (state.facePartId != 0xff)
                ResolveCompositionPartRect(
                    &m_partEntries[5], state.facePartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x36:
            if (secondAccessoryPass) {
                if (state.acc2drwSelector != 0xffff)
                    ResolveCompositionPartRect(
                        &m_partEntries[7], state.acc2drwSelector, sequence,
                        frame, ridingYOffset, 0, &partBounds);
                mergePart = true;
            } else {
                --drawIndex;
                secondAccessoryPass = true;
                if (state.acc2drwSelector == 0xffff ||
                    m_acc2drwEntries[state.acc2drwSelector].enabled[2]) {
                    if (state.accessoryLowPartId != 0xff)
                        ResolveCompositionPartRect(
                            &m_partEntries[6], state.accessoryLowPartId, sequence,
                            frame, ridingYOffset, 0, &partBounds);
                    mergePart = true;
                }
            }
            break;

        case 0x37:
            bucket = ClassifyHumanPartFiveBucket(state.primaryEquipmentId);
            switch (bucket) {
            case 1:
                ResolveCompositionPartRect(
                    &m_partEntries[8], state.primaryEquipmentId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 2:
                ResolveCompositionPartRect(
                    &m_partEntries[9], state.primaryEquipmentId - 10000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 3:
                ResolveCompositionPartRect(
                    &m_partEntries[10], state.primaryEquipmentId - 20000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 4:
                ResolveCompositionPartRect(
                    &m_partEntries[11], state.primaryEquipmentId - 30000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            default:
                break;
            }
            mergePart = true;
            break;

        case 0x38:
            if (ClassifyHumanPartTwoBucket(state.secondaryEquipmentId) == 1)
                ResolveCompositionPartRect(
                    &m_partEntries[12], state.secondaryEquipmentId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x39:
            if (state.capeOrBackPartId != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[14], state.capeOrBackPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3a:
            if (state.overlayPartIdA != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[15], state.overlayPartIdA, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3b:
            if (state.overlayPartIdB != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[16], state.overlayPartIdB, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3c: {
            ridingDefinition =
                g_pRidingImageLib->GetDefinitionOrDefault(state.ridingDefinitionIndex);
            ResourceLayoutRawRecordGetEntryRect(
                g_pRidingImageLib->ridingEpfPackage,
                ridingDefinition->baseRectIndex + 3 * sequence - 24 +
                    kNewHumanRidingFrameRectOffsets[frame],
                &partBounds);
            mergePart = true;
            break;
        }

        case 0x3e:
            if (ClassifyHumanPartTwoBucket(state.secondaryEquipmentId) == 2) {
                ResolveCompositionPartRect(
                    &m_partEntries[13], state.secondaryEquipmentId - 10000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            } else if (ClassifyHumanPartFiveBucket(state.primaryEquipmentId) == 5) {
                ResolveCompositionPartRect(
                    &m_partEntries[18],
                    (unsigned short)(state.primaryEquipmentId + 25536),
                    sequence,
                    frame,
                    ridingYOffset,
                    0,
                    &partBounds);
            }
            mergePart = true;
            break;

        case 0x3d:
        case 0x3f:
            mergePart = true;
            break;

        default:
            break;
        }

        if (mergePart)
            RectBoundsUnion(bounds, &partBounds);
    }

    result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);

FinishBounds:
    if (projectedBounds != NULL) {
        height = bounds->bottom - bounds->top;
        horizontalOffset = g_activeMapPane->m_newHumanProjectionShear * (float)height;
        verticalOffset = (float)height / g_activeMapPane->m_newHumanProjectionDivisor;

        projectedRight = bounds->right;
        if (projectedRight <= (int)((float)projectedRight + horizontalOffset))
            projectedRight = (int)((float)bounds->right + horizontalOffset);

        projectedLeft = (int)((float)bounds->left + horizontalOffset);
        if (bounds->left <= projectedLeft)
            projectedLeft = bounds->left;

        return RectBoundsSet(
            projectedBounds,
            projectedLeft,
            (int)((float)bounds->bottom - verticalOffset - 1.0f),
            projectedRight,
            bounds->bottom);
    }

    return result;
}

// UID0000BZ complete RidingImageLib.cpp owner-shell replacement.
// The class declaration and extern declarations move to RidingImageLib.h;
// all existing method/global definitions remain in their existing child order.
#include "RidingImageLib.h"

[[CHILDREN]]
```

H disposition: UID0002KQ owns the complete new ResourceLayoutTable H; UID0002KT H stays blank because declarations are centralized there. UID00006E owns the complete ImageLib H, directly includes the existing complete UID000079 List H, declares UID0001VT/0000VB before class use, exposes `FindResourceIndex` publicly, defines `GetResourceLayout` in-class, and keeps only `GetEntry` plus storage private. The accessor is H-only/compiler-covered and receives no separate CPP body or by-memory UID. UID0001VT/0000VB stop late CPP emission because their declarations are centralized in UID00006E H. UID0000BZ owns the complete guarded RidingImageLib H below; its former CPP class/extern declaration moves into that H, while the CPP owner shell retains every method/global child definition.

```cpp
// UID0002KQ complete ResourceLayoutTable.h.
#ifndef NEXUSTK_RENDER_RESOURCELAYOUTTABLE_H
#define NEXUSTK_RENDER_RESOURCELAYOUTTABLE_H

struct ArchiveMetadataTable;
struct EPFTileContext;
struct RectBounds;

void __stdcall ResourceLayoutRawBufferLookupEntry(
    const unsigned char *buffer,
    EPFTileContext *outContext);
RectBounds *__stdcall ResourceLayoutRawRecordGetEntryRect(
    const ArchiveMetadataTable *table,
    int entryIndex,
    RectBounds *bounds);

#endif

// UID00006E complete ImageLib.h replacement.
#ifndef NEXUSTK_RENDER_IMAGELIB_H
#define NEXUSTK_RENDER_IMAGELIB_H

#include "../util/LObject.h"
#include "../util/List.h"

struct ArchiveMetadataTable;
struct EPFTileContext;
struct FrameDrawRecord;
struct RectBounds;

struct ResourceLayoutEntry
{
    int left;
    int top;
    int right;
    int bottom;
    unsigned char *pixelData;
    unsigned char *encodedMaskData;
};

struct ResourceLayoutNameRecord
{
    wchar_t name[16];
    unsigned short entryCount;
    unsigned short frameWidth;
    unsigned short frameHeight;
    unsigned short reservedHeaderWord;
    ResourceLayoutEntry *entries;
};

class ImageLib : public LObject
{
public:
    ImageLib(int cacheLimit, int);
    virtual ~ImageLib();
    int LoadResourceIndex(const wchar_t *resourceName);
    int FindResourceIndex(const wchar_t *resourceName);
    const ResourceLayoutNameRecord *GetResourceLayout(
        int resourceIndex) const
    {
        return static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    }
    void LookupLayoutEntry(
        const wchar_t *resourceName, int frameIndex,
        EPFTileContext *outContext);
    void CopyEntryTileContext(
        const wchar_t *resourceName, int frameIndex,
        EPFTileContext *destination);
    void GetEntryRect(
        const wchar_t *resourceName, int frameIndex,
        RectBounds *bounds);
    void LoadFrameDrawRecord(
        const ArchiveMetadataTable *table, int frameIndex,
        FrameDrawRecord *outRecord);
    void GetFrameSize(
        const wchar_t *resourceName,
        unsigned short *width, unsigned short *height);
    unsigned short GetEntryCount(const wchar_t *resourceName);

private:
    ResourceLayoutEntry *GetEntry(int resourceIndex, int frameIndex);
    int m_refCount;
    int m_cacheLimit;
    List *m_pEntryList;
    int m_maxCacheSize;
};

typedef ImageLib ResourceLayoutTable;
extern ImageLib *g_pEPFLib;
typedef char ImageLibSizeMustBe20[
    sizeof(ImageLib) == 0x14 ? 1 : -1];
typedef char ResourceLayoutEntrySizeMustBe24[
    sizeof(ResourceLayoutEntry) == 0x18 ? 1 : -1];
typedef char ResourceLayoutNameRecordSizeMustBe44[
    sizeof(ResourceLayoutNameRecord) == 0x2c ? 1 : -1];

#endif

// UID0000BZ complete RidingImageLib.h replacement.
#ifndef NEXUSTK_RENDER_RIDINGIMAGELIB_H
#define NEXUSTK_RENDER_RIDINGIMAGELIB_H

#include "../util/LObject.h"

struct ArchiveMetadataTable;
struct ImageAnimationTable;
struct ImageAnimationGroup;
struct ImageAnimationFrame;
struct RidingDefinition;
struct ObjectStatusBlob;
struct RectBounds;
class GrafPort;
class NewHumanImageLib;

class RidingImageLib : public LObject
{
public:
    RidingImageLib();
    virtual ~RidingImageLib();

    void LoadRidingDefinitions();
    void RenderRiding(
        GrafPort *target,
        const RectBounds *bounds,
        const ObjectStatusBlob *objectStatus,
        unsigned int animationGroup,
        unsigned int animationFrame);
    const RidingDefinition *GetDefinitionOrDefault(
        unsigned int ridingDefinitionIndex) const;

private:
    friend class NewHumanImageLib;
    RidingDefinition *ridingDefinitions;
    unsigned int ridingDefinitionCount;
    ArchiveMetadataTable *ridingEpfPackage;
};

extern RidingImageLib *g_pRidingImageLib;
extern ImageAnimationTable g_ridingDefinitionGroups;

#endif
```

Blocks preserve binary behavior, accepted project APIs/types, the KQ defect, and one declaration/definition route per symbol. Compile closure is proposed only as the complete chain shown here: UID0002V8 supplies all three literal includes, exact `ResourceLayoutNameRecord` GFACE access, explicit first-entry rectangle copy, and both corrected Riding operands; UID00006E H includes complete List, makes the 13-caller Find API public, defines the no-standalone-body accessor inline, and keeps storage/GetEntry private; UID0000BZ CPP includes its owner H and retains `[[CHILDREN]]` without a class redeclaration; UID0000BZ H supplies the sole guarded Riding class/API/field/extern declaration and narrow friendship before private storage. No third-party import applies.

## Final Recommendation

- C01-C43 and C58-C126 are implemented or physically verified by the dated callback receipts below.
- I01-I11/C44-C57 remain exclusively supervisor-owned dispositions; this callback did not mutate or save IDA.
- The first supervisor Gate 2B attempt is retained only as dated failure evidence: unsaved I01 exposed the actual two-row frame, I02-I11 did not run, no save occurred, the worker was discarded, and fresh canonical raw prestate was restored. The corrected I01/I02 sequence below is deterministic and source-consistent without a type action.
- Exact tail child UID00054V exists at `by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md`; every pre-assignment placeholder is reconciled to that identity.
- Keep UID000174 non-emitting after same-UID range/path correction.
- Keep decoder/frame helpers, aliases, singleton storage, and compiler vtable/RTTI outside UID0000N5 emission.
- Section 22's complete formal dependency chain is applied. The dated callback readback proves three NewHuman includes, exact GFACE row/accessor/public-Find/rectangle-copy source, two Riding field replacements, complete ImageLib/List H closure with no accessor CPP body, one Riding H declaration, no Riding CPP class/extern duplicate, and all retained child definitions. Bounded spelling/file/accessor-name uncertainty affects confidence only; later Gate 2A/lifecycle actions reread generated authority dynamically.

## Recommended Target Doc Changes

- Implemented on target `by-file/ResourceLayoutTable.md`: final two-helper external module and complete eleven-function family at `95/93`, preserving `NexusTK/render/` and owner `FILE`.
- Exact KQ/KT behavior, ABI, hashes, calls, source order, external linkage, H ownership, dependencies, and generated expectations are present.
- The complete nine-method ImageLib relationship, excluded mixed-band functions, twenty gaps, H-only `GetResourceLayout`, public 13-caller `FindResourceIndex`, exact UID0001VT GFACE row, and verify-only UID000079/UID0000KS List route are present. The inline accessor is not counted as a tenth executable definition.
- Empty-marker/static-KT/duplicate-type/missing-H/wrong-order/open-blocker states are retained only as dated history. Callback output has exactly two target definitions/two H declarations, no target empty marker/duplicate struct/static cross-file helper, and no undefined ResourceLayout convenience type/accessor.

## Recommended Support Doc Changes

The following is the accepted callback payload and is now implemented or verify-only confirmed. Imperative wording in each row describes the applied delta from the dated pre-callback state; Section 31 gives the exact physical receipts.

| Exact owning path / UID | Exact change |
| --- | --- |
| `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` / 0002KQ | Complete formal CPP/H, position 10, 93/93, exact ABI/body defect/hash/frame/xrefs/dependencies and corrected history. H owns both external declarations and the new sibling header. |
| `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md` / 0002KT | Replace static duplicate-table source with external `ArchiveMetadataTable` formal CPP, position 20, 92/93; formal H remains blank because 0002KQ centralizes both declarations. |
| `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` / 0002KO | Replace formal CPP, record ignored Open result, exact seek origins, signed-short reads, sentinel/rebase/list behavior, and 94/94. |
| `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` / 0002KP | Replace formal CPP with void source signature, 32-bit source frame index, exact output/failure mapping, and 94/95; owner H declaration is centralized in 00006E. |
| `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` / 0002KR | Preserve formal body and 90/91; add void-KP dependency and complete family/position route without pruning its 25-call evidence. |
| `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` / 0002KS | Replace formal CPP/H-facing signature with void, preserve lazy lookup/16-byte copy/InitRectBounds failure, and set 93/94. |
| `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md` / 0002P6 | Verify existing formal body and 91/94; preserve invalid-pointer-only clear, next-row span, 81 xrefs, and exact current FR. |
| `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` / 0002KU | Verify existing formal body and 90/92; add complete family route while preserving the sole caller and `+0x22/+0x24` copies. |
| `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` / 0002KV | Verify existing formal body and 90/93; add complete family route while preserving unsigned 16-bit return and six callers. |
| `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` / 0002KW | Replace formal CPP with one initial List lookup and 44-byte pointer walk; document all 13 calls and the four-internal/nine-external split; centralize a public H declaration in UID00006E, retain compare/xref evidence, reject broad friendship/private access, and set 93/95. |
| `by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md` / 00054V | Exact created child at 92/93, owner 0000BY position 110, complete 48-byte evidence/formal CPP, and centralized declaration reason because 00006E owns H. |
| `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` / 000174 | Same-UID rename to `0x004d0120-0x004d1860.ResourceLayoutTable.md`; preserve non-emission and replace range/hash/inventory with 11 included, 11 excluded, and 20 exact internal gaps while historicalizing the old endpoint/hash. |
| `by-class/ResourceLayoutTable.md` / 0000BY | Record nine out-of-line methods, public H-only compiler-covered GetResourceLayout, public Find, private new GetEntry, corrected source/signatures, alias-only object identity, no independent lifecycle/vtable/global, and 94/94. |
| `by-class/ImageLib.md` / 00006E | Replace formal H with direct List H dependency, complete row declarations before use, nine out-of-line method surface, public Find, complete inline `const ResourceLayoutNameRecord *GetResourceLayout(int) const`, private GetEntry/storage, preserved fields/guard/typedef/extern/size guards, and 92/93. |
| `by-file/ImageLib.md` / 0000K2 | Add nine-method source/order/include/generated inventory plus the H-only compiler-covered accessor and public Find route; require no accessor CPP body; set 94/93 without pruning lifecycle or other file children. |
| `by-class/List.md` / 000079 | Verify-only complete `List::GetElementAt(int)` declaration/body/vtable slot `+0x10` and 93/94; no source, score, owner, or formal-channel change. UID00006E includes its existing H rather than duplicating List. |
| `by-file/List.md` / 0000KS | Verify-only complete List CPP/H route and dated generated `List.h`; no edit/score change. Validate only as the exact dependency of inline `GetResourceLayout`. |
| `by-type/by-struct/ImageLibLayout.md` / 0001US | Add GetEntry use of the already established `+0x0c List *`; preserve 86/90 and all constructor/destructor evidence. |
| `by-type/by-struct/ResourceLayoutNameRecord.md` / 0001VT | Move exact 44-byte declaration to 00006E formal H, identify it as the GFACE row proved by `+0x20/+0x28`, reject distinct undefined `ResourceLayoutRecord`, prohibit duplicate late CPP emission, retain all layout/List evidence, and set 92/94. |
| `by-item/ResourceLayoutEntry.md` / 0000VB | Move exact 24-byte declaration to 00006E formal H, prohibit duplicate late CPP emission, add KQ/KT/new-method/sentinel evidence, and set 92/94. |
| `by-type/by-struct/ResourceLayoutStore.md` / 0001VU | Verify-only no-code generic-List alias; preserve 84/90 and blank formal channels. |
| `by-type/by-struct/ResourceLayoutBucket.md` / 0001VS | Verify-only no-code NameRecord alias; preserve 86/91 and blank formal channels. |
| `by-global/g_pEPFLib.md` / 0000QU | Verify-only one ImageLib singleton declaration route and no ResourceLayout global; preserve 89/88 and no second definition. |
| `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` / 0001OQ | Verify-only sole four-byte singleton storage/lifecycle route; preserve 87/91 and no duplicate. |
| `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` / 0003RK | Replace only the local KQ prototype with direct `../../render/ResourceLayoutTable.h` include; preserve parser body, ABI, evidence, and score. |
| `by-file/UserLookPane.md` / 0000P0 | Add exact 0003RK owner-header dependency/generated expectation; preserve 92/93 and complete file inventory. |
| `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` / 0002V8 | Replace its formal CPP with the complete Section 22 body: literal `#include "ImageLib.h"`, `#include "ResourceLayoutTable.h"`, and `#include "RidingImageLib.h"`; exact `ResourceLayoutNameRecord` GFACE row through public Find/inline accessor; explicit leading 16-byte RectBounds copy; both exact `m_rawRecordTable` -> `ridingEpfPackage` substitutions; and every existing branch/call/index/order/union preserved. Historicalize undefined type/accessor/private-call assumptions and set 91/92. H remains blank because UID000092 owns declarations. |
| `by-class/NewHumanImageLib.md` / 000092 | Record UID0002V8's complete three-header formal CPP dependency, exact GFACE owner API/type route, and friend-authorized Riding reads; preserve the complete class/formal H inventory, add no duplicate helper/accessor/row/Riding declarations, and keep 90/91. |
| `by-file/NewHumanImageLib.md` / 0000LR | Route UID0002V8's complete formal CPP with three literal includes, legal GFACE source, and both Riding field substitutions to `NewHumanImageLib.cpp`; preserve the complete file inventory/H and 91/91. Generated expectation is one complete definition, public Find call, inlined List row fetch, two declared KT calls, no undefined convenience type/accessor, no stale field, and no duplicate owner declaration. |
| `by-class/RidingImageLib.md` / 0000BZ | Move the complete existing class/extern declaration out of formal CPP into a complete guarded formal H with `../util/LObject.h`, exact forwards/API/three fields/two externs, and `friend class NewHumanImageLib;` immediately before private storage; CPP becomes `#include "RidingImageLib.h"` plus `[[CHILDREN]]`, preserving all method/global definitions and preventing duplicate class/extern emission; retain all layout/lifecycle evidence and set 92/94. |
| `by-file/RidingImageLib.md` / 0000N6 | Route UID0000BZ's include-plus-children CPP shell and complete owner H without pruning RIDINGS.DNA/RIDINGS.EPF lifecycle/render children or changing 91/92; generated expectation is one guarded declaration, all prior method/global definitions in order, and no CPP class/extern duplicate. |
| `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` / 000175 | Verify-only aggregate/index over the seven exact ImageLoaders children; no extra body or ResourceLayout ownership. |
| `by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md` / 0002TJ | Verify-only ZPF/FPF decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/89. |
| `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md` / 0002TK | Verify-only raw FPF decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/90. |
| `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md` / 0002TL | Verify-only JPF/libjpeg decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/89. |
| `by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md` / 0002TM | Verify-only BMP/palette decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/90. |
| `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md` / 0002TN | Verify-only JPEG-buffer decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/89. |
| `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md` / 00032P | Verify-only PNG-file decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/89. |
| `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md` / 00032O | Verify-only PNG-resource decoder exclusion; preserve nonblank CPP, blank H, ImageLoaders owner and 88/89. |
| `by-file/ImageLoaders.md` / 0000K3 | Verify-only seven-definition owner and generated `ImageLoaders.cpp` route; no H or ResourceLayout edit. |
| `by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md` / 000176 | Verify-only non-emitting aggregate; P6 stays separately ResourceLayout-owned. |
| `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md` / 0002P4 | Verify-only frame loader exclusion; preserve nonblank CPP, blank H, ImageFrameTable owner and 89/92. |
| `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md` / 0002P5 | Verify-only frame destroy exclusion; preserve nonblank CPP, blank H, ImageFrameTable owner and 88/92. |
| `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md` / 00031T | Verify-only payload-copy exclusion; preserve nonblank CPP, blank H, ImageFrameTable owner and 88/90. |
| `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md` / 00031U | Verify-only bounds-copy exclusion; preserve nonblank CPP, blank H, ImageFrameTable owner and 88/90. |
| `by-file/ImageFrameTable.md` / 0000K1 | Verify-only P4/P5/31T/31U and shared-type owner; generated CPP must contain no P6 duplicate. |
| `by-item/EPFArchiveMetadataTable.md` / 0000UN | Verify-only shared ArchiveMetadataTable/PackedArchiveRecord/FrameDrawRecord H declarations used by KT/P6/frame helpers. |
| `by-item/LoadFrameDrawRecord_004D1600.md` / 0000UX | Verify-only non-emitting semantic P6 mirror; UID0002P6 remains the sole body. |
| `by-item/LoadImageFrameTable_004D0F50.md` / 0000UY | Verify-only non-emitting semantic P4 mirror; UID0002P4 remains the sole body. |
| `by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md` / 0002IZ | Verify-only exact successor at `0x004d1860`; no overlap or ResourceLayout edit. |
| `by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md` / 000177 | Verify-only non-emitting successor-family aggregate and boundary. |
| `by-class/MapTileImageLib.md` / 00007T | Verify-only successor class route; preserve 92/94. |
| `by-file/MapTileImageLib.md` / 0000L5 | Verify-only successor file/generated route; preserve 91/93 and no ResourceLayout edit. |

## Score And Metadata Recommendation

| UID | Historical pre-callback -> implemented | Confidence cap |
| --- | --- | --- |
| 0000N5 | `88/86 -> 95/93` | Original filename inferred. |
| 0002KQ | `86/89 -> 93/93` | Helper spelling/bug intent not symbol-proven. |
| 0002KT | `88/90 -> 92/93` | Helper spelling inferred. |
| 0002KO | `90/90 -> 94/94` | Private names inferred. |
| 0002KP | `90/91 -> 94/95` | Argument spelling inferred. |
| 0002KS | `89/90 -> 93/94` | Name inferred. |
| 0002KW | `90/92 -> 93/95` | Name inferred. |
| 00054V | absent -> `92/93` | No symbol/caller; name/private placement descriptive. |
| 0000BY | `90/91 -> 94/94` | Compatibility spelling inferred. |
| 00006E | `89/90 -> 92/93` | Private names partly inferred. |
| 0000K2 | `91/90 -> 94/93` | Same facet cap. |
| 000174 | `88/91 -> 92/95` | Intentionally mixed/non-emitting. |
| 0001VT/0000VB | `90/92 -> 92/94` | Exact original placement inferred. |
| 0002V8 | `89/90 -> 91/92` | Broader descriptive method/accessor names remain; GFACE type/layout is exact. |
| 0000BZ | `91/92 -> 92/94` | Friendship spelling reconstructed. |

Resolved report-source blockers: KQ behavior, KT type/linkage, split, full inventory/tail, method returns, KO source, KW traversal, headers/types/includes, UID0002V8's exact GFACE row/accessor/public-Find route, UID0002V8's complete two-site Riding replacement, and the complete Riding CPP-to-H declaration/friend move. No score changes beyond the table resulted from the GFACE repair because binary behavior/layout were already covered. The callback applied the source closure exactly and recorded a dated physical compile-surface readback; Gate 2A independently rereads current validator-owned output.

## Open Questions With Attempted Resolution

| Question | Evidence | Resolution/impact |
| --- | --- | --- |
| Literal ResourceLayoutTable.cpp? | ABIs, calls, adjacency, tree, generated TU needs, reports. | Strongest split; filename uncertainty only. |
| KQ compiler artifact? | Full body/allocator/negative loop/sentinel/free evidence. | No; emit historical defect. |
| Unique KT type? | Exact offsets/stride and ImageFrameTable H. | No; ArchiveMetadataTable. |
| KP/KS pointer return? | Body/calls/EAX/type. | No; void. |
| Tail code or padding? | Instructions/exits/bounds/successor/hash. | Complete method. |
| GetEntry public? | Zero callers/private List/API surface. | Private highest probability; score capped. |
| Structs CPP-local? | H/CPP use order and cross-TU declarations. | No; owner H. |
| Distinct `ResourceLayoutRecord`? | GFACE reads `+0x20` entryCount and `+0x28` entries from the same List(44,10) row; project search finds no separate declaration. | No; exact UID0001VT `ResourceLayoutNameRecord`; undefined convenience type rejected. |
| Out-of-line `GetResourceLayout`? | GFACE performs `mov ecx,[esi+0xc]`, pushes index, and calls List vtable slot `+0x10`; no direct accessor call/range exists. | Define it in-class in UID00006E H, compiler-covered in callers; include List H and emit no CPP body/new UID. |
| Private Find plus friendship? | Nine of 13 direct calls are external Human/NewHuman sites or raw islands, not one friend class. | Make `FindResourceIndex` public; retain only zero-xref `GetEntry` and storage as private. |
| Accessor instead of friend? | Binary reads `+0x0c` directly, no call; dated output embeds the Riding class in CPP and has no owner H. | Complete UID0000BZ formal H places narrow friendship before private storage; CPP includes that H and retains children, preserving direct access without accessor/public storage or duplicate class emission. |
| Does `define_func` infer GetEntry argument rows? | Dated supervisor I01 succeeded with exact bounds, then immediate public `stack_frame` returned only saved-register and return-address rows; fresh canonical reopen restored no-function state. | No. Accept the proven two-row, type-absent frame in I01; I02 changes only the name. The two `retn 8` exits preserve source ABI evidence without requiring materialized IDA argument rows. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Coverage files are supervisor-owned. The following are exact complete replacement/insert rows, not summaries; UID00054V is the validator-assigned child identity used in this report and payload. Validator-generated tracker rows are not manual payloads.

`by-file/-coverage-report.md` exact replacement rows, preserving file-address order:

- `- [UID:0000K2][ImageLib](by-file/ImageLib.md) : reconstructable : 94% : very-strong : NexusTK/render/ImageLib.cpp owns one ImageLib lifecycle/global and exactly nine out-of-line non-virtual ResourceLayoutTable facet definitions: exact loader, void lookup, tile-context copy, void rectangle lookup, frame-record projection, frame-size/count accessors, one-lookup 44-byte public finder, and retained private GetEntry. ImageLib.h includes complete List.h, declares both exact row layouts before use, exposes public FindResourceIndex plus in-class compiler-covered GetResourceLayout, retains private +0x0c List storage/GetEntry, compatibility typedef and one g_pEPFLib extern; no accessor CPP body exists. UID0002KQ/UID0002KT remain external no-this helpers in UID0000N5; decoder/frame neighbors and duplicate row definitions are excluded.`
- `- [UID:0000KS][List](by-file/List.md) : reconstructable : 91% : very-strong : Complete NexusTK/util/List.cpp/.h fixed-width container route remains unchanged and supplies the exact virtual void *GetElementAt(int) slot +0x10 used by ImageLib's in-class GetResourceLayout lowering. UID00006E includes this owner H directly; no List method, field, score, owner or formal-source change is introduced.`
- `- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) : reconstructable : 91% : very-strong : NexusTK/render/NewHumanImageLib.cpp retains its complete composition/render inventory and UID0002V8 full body, directly includes ImageLib.h, ResourceLayoutTable.h and RidingImageLib.h, uses exact ResourceLayoutNameRecord/public Find/inlined GetResourceLayout for GFACE, explicitly copies the first entry's leading RectBounds, and uses g_pRidingImageLib->ridingEpfPackage at both raw-record rectangle callsites. NewHumanImageLib.h remains complete and introduces no duplicate helper/accessor/row/Riding declaration; no undefined ResourceLayoutRecord, local raw-helper prototype or stale m_rawRecordTable remains.`
- `- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) : reconstructable : 95% : very-strong : NexusTK/render/ResourceLayoutTable.cpp/.h owns exactly two externally linked no-this helpers in source order: UID0002KQ faithfully parses the raw buffer with one-row initialization, non-zeroing allocation, uninitialized row-one mask-length read and unreleased allocation; UID0002KT returns a RectBounds pointer over the accepted ArchiveMetadataTable layout. The sibling H declares both APIs; nine ImageLib/facet methods, all decoder/frame neighbors, singleton storage and duplicate row structs remain excluded. Generated expectation is two definitions/two declarations, no empty marker, static duplicate helper, late duplicate type, undeclared caller, or missing header.`
- `- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) : reconstructable : 91% : very-strong : NexusTK/render/RidingImageLib.cpp includes RidingImageLib.h and retains every RIDINGS.DNA/RIDINGS.EPF lifecycle/render method/global child definition in source order without a class/extern redeclaration. The complete guarded owner H carries the LObject dependency, exact forwards/API/three fields/two externs and narrow NewHumanImageLib friendship immediately before private storage, making UID0002V8's direct ridingEpfPackage reads source-visible without an accessor, public storage or duplicate declaration.`
- `- [UID:0000P0][UserLookPane](by-file/UserLookPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/UserLookPane.cpp retains its complete pane/parser/helper inventory; UID0003RK now includes ../../render/ResourceLayoutTable.h instead of carrying a local raw-helper declaration, so the sole UID0002KQ call is owned and declared with no duplicate prototype or body.`

`by-class/-coverage-report.md` exact replacement rows:

- `- [UID:00006E][ImageLib](by-class/ImageLib.md) : reconstructable : 92% : very-strong : Exact 0x14 LObject-derived ImageLib declaration and inseparable ResourceLayoutTable facet includes complete List.h, declares the 24-byte ResourceLayoutEntry and 44-byte ResourceLayoutNameRecord before class use, owns nine out-of-line methods, exposes the 13-caller FindResourceIndex publicly, and defines compiler-covered const ResourceLayoutNameRecord *GetResourceLayout(int) const in-class over List::GetElementAt. Corrected void APIs use 32-bit indexes; private GetEntry and +0x0c List storage, guard fields, typedef, one g_pEPFLib extern and size guards remain. No accessor CPP body, distinct ResourceLayoutRecord, independent object/vtable/global or late duplicate struct is emitted.`
- `- [UID:000079][List](by-class/List.md) : reconstructable : 93% : very-strong : Complete 0x14 LObject-derived fixed-width List declaration and method inventory remain unchanged; virtual void *GetElementAt(int) at vtable slot +0x10 is the exact existing API called by compiler-covered ImageLib::GetResourceLayout. UID00006E includes List.h rather than forward-declaring an incomplete type for the inline body; no List ownership, formal source, layout, method or score change applies.`
- `- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md) : reconstructable : 90% : very-strong : The complete 0x60 NewHuman composition/render class and H declarations remain intact; UID0002V8's complete owner CPP includes ImageLib.h, ResourceLayoutTable.h and RidingImageLib.h, preserves every composition-bounds branch/order/union, uses exact ResourceLayoutNameRecord/public Find/inlined row access for GFACE, and performs both declared raw-record rectangle calls with friend-authorized ridingEpfPackage reads. No undefined ResourceLayoutRecord, stale m_rawRecordTable, duplicate ResourceLayout helper/accessor/row declaration or duplicate Riding class declaration remains.`
- `- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) : reconstructable : 94% : very-strong : Non-virtual ImageLib singleton/facet with nine exact out-of-line methods over the private +0x0c List: loader, void lookup, copy wrapper, void bounds lookup, frame projection, size/count accessors, public one-lookup finder and retained private GetEntry [0x004d1830,0x004d1860). The owner H additionally defines public compiler-covered GetResourceLayout over List::GetElementAt with no standalone binary/CPP body. Exact rows, source order and one g_pEPFLib receiver are documented; no independent lifecycle/object/vtable/global exists and external UID0002KQ/UID0002KT remain UID0000N5-owned.`
- `- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) : reconstructable : 92% : very-strong : Complete guarded RidingImageLib.h owns the LObject dependency, exact forwards, constructor/destructor/load/render/default-definition API, exact 0x10 three-field layout, two externs and friend class NewHumanImageLib immediately before private ArchiveMetadataTable *ridingEpfPackage at +0x0c. RidingImageLib.cpp includes that H and retains all method/global children without a duplicate class/extern declaration; the route preserves both direct UID0002V8 field reads without accessor, public storage, stale m_rawRecordTable alias or ownership transfer.`

`by-memory/-coverage-report.md` exact replacement rows at their existing address positions:

- `    - [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md) 0x004d0120-0x004d1860 | mixed-inventory | ResourceLayoutTable/ImageDecode/ImageFrameTable neighborhood : ignored/non-emitting : 92% : very-strong : Corrected 5,952-byte mixed range SHA256 7C8447664D714D5C45F451BB894D7D7C1EE557DD6433229970D9BBC4ED3D8897 contains 11 included ResourceLayout source definitions, 11 excluded decoder/frame definitions and 20 exact internal 0xcc gaps. The historical 0x004d182f endpoint/hash omitted retained private GetEntry [0x004d1830,0x004d1860); every source-bearing child has its own owner/emitter decision, so aggregate emission remains false.`
- `        - [UID:0002KO][0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex](by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md) 0x004d0120-0x004d02e5 | method | ResourceLayoutTable::LoadResourceIndex : reconstructable : 94% : very-strong : Exact 453-byte ImageLib/facet loader ignores DATFile::Open's result, reads the 8-byte header and 4-byte table offset, seeks (offset,1), reads four signed shorts plus two offsets per 24-byte row, seeks (0,0), rebases payload pointers, appends one 44-byte name record with a zero-bounds sentinel, and returns listCount-1; 13 exact code xrefs, ABI/frame/hash/source position and corrected history are retained.`
- `        - [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) 0x004d02f0-0x004d039e | method | ResourceLayoutTable::LookupLayoutEntry : reconstructable : 94% : very-strong : Exact 174-byte void ImageLib/facet lookup lazily loads by name, uses a 32-bit source frame index, maps the selected 24-byte row and next-row pixel pointer into EPFTileContext, and zeroes every output field through InitRectBounds on failure. Complete 440-code-xref fan-in, frame/hash/source position and stale pointer-return/16-bit-source history are retained.`
- `        - [UID:0002KQ][0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry](by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md) 0x004d03a0-0x004d04d0 | helper | ResourceLayoutRawBufferLookupEntry : reconstructable : 93% : very-strong : External no-this __stdcall helper and UID0000N5 position-10/H owner. Exact 304-byte body copies header/table offset, non-zero allocates (entryCount+1)*24, initializes only row zero, rebases its two pointers, optionally fills EPFTileContext, computes mask length from uninitialized entries[1].pixelData and leaks the allocation. Sole UID0003RK call, ABI/frame/hash/dependencies and rejection of invented loop/sentinel/zero-fill/free/guards are preserved.`
- `        - [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md) 0x004d04d0-0x004d0522 | method | ResourceLayoutTable::CopyEntryTileContext : reconstructable : 90% : very-strong : Exact 82-byte ImageLib/facet wrapper initializes a stack EPFTileContext, calls the corrected void LookupLayoutEntry, and conditionally CopyTo's the destination; all 25 calls, ABI/frame/hash, position and complete-family route remain preserved.`
- `        - [UID:0002KS][0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect](by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md) 0x004d0530-0x004d059b | method | ResourceLayoutTable::GetEntryRect : reconstructable : 93% : very-strong : Exact 107-byte void ImageLib/facet method lazily resolves the 44-byte name record, signed-checks the 32-bit source index, copies the selected 16-byte bounds, and calls InitRectBounds on failure; 11 exact calls, ABI/frame/hash/position and stale pointer-return history are retained.`
- `        - [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) 0x004d05a0-0x004d05e6 | helper | ResourceLayoutRawRecordGetEntryRect : reconstructable : 92% : very-strong : External no-this __stdcall UID0000N5 position-20 helper returns the destination RectBounds pointer, copies records[entryIndex].bounds when entryIndex is below ArchiveMetadataTable::frameCount, otherwise zeroes through InitRectBounds. Exact 70-byte body, 28 callers, ABI/frame/hash and rejection of static linkage/duplicate private table layout are retained; H is centralized on UID0002KQ.`
- `        - [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) 0x004d1600-0x004d165d | method | ResourceLayoutTable::LoadFrameDrawRecord : reconstructable : 91% : very-strong : Exact g_pEPFLib/ImageLib-facet frame projection with 81 code xrefs, bounds/count checks, pointer-only invalid clears, payload pointer/span/end reconstruction and next-record boundary semantics. The existing source, ABI/type/frame/hash and exact FR stay unchanged; neighboring ImageFrameTable helpers remain excluded.`
- `        - [UID:0002KU][0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize](by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md) 0x004d1730-0x004d1773 | method | ResourceLayoutTable::GetFrameSize : reconstructable : 90% : very-strong : Exact 67-byte ImageLib/facet lazy accessor copies ResourceLayoutNameRecord +0x22/+0x24 to width/height. Sole caller, ABI/frame/hash/position and complete nine-method route are preserved.`
- `        - [UID:0002KV][0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount](by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md) 0x004d1780-0x004d17b3 | method | ResourceLayoutTable::GetEntryCount : reconstructable : 90% : very-strong : Exact 51-byte ImageLib/facet lazy accessor returns the unsigned 16-bit count at ResourceLayoutNameRecord +0x20. Six callers, ABI/frame/hash/position and complete nine-method route are preserved.`
- `        - [UID:0002KW][0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex](by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md) 0x004d17c0-0x004d182f | method | ResourceLayoutTable::FindResourceIndex : reconstructable : 93% : very-strong : Exact 111-byte public ImageLib/facet finder obtains GetElementAt(0) once, walks contiguous 44-byte ResourceLayoutNameRecord rows, performs the inlined wide comparison, and returns index or -1. Its thirteen exact calls split into four internal ImageLib/facet calls and nine external HumanImageLib/NewHumanImageLib/raw-island calls; that observed ownership rejects the stale private declaration and an unsupported broad-friendship workaround. ABI/frame/hash/position and the historical repeated-GetElementAt source error are preserved.`
- Insertion immediately after UID0002KW and the one-byte `0xcc` gap, before the `0x004d1860` successor: `        - [UID:00054V][0x004d1830-0x004d1860.ResourceLayoutTableGetEntry](by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md) 0x004d1830-0x004d1860 | method | ResourceLayoutTable::GetEntry : reconstructable : 92% : very-strong : Retained private no-xref ImageLib/facet method with exact 48-byte SHA256 3505E796AA1F9C411DAC68C3E1015E9AC053ECA55C83484BB6568B436DD01BE5; one List GetElementAt, signed frame validation, 24-byte row calculation, zero failure return, parent UID0000BY position 110, complete CPP and declaration centralized in UID00006E H.`
- `        - [UID:0002V8][0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds](by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md) 0x004e31f0-0x004e3a2e | method | NewHumanImageLib::CalculateCompositionBounds : reconstructable : 91% : very-strong : Complete formal CPP includes ImageLib.h, ResourceLayoutTable.h and RidingImageLib.h; it preserves every part/default/union branch and ordering. The GFACE branch calls public ImageLib::FindResourceIndex, uses the compiler-covered inline GetResourceLayout accessor to obtain an exact ResourceLayoutNameRecord row, checks entryCount/+0x20 and entries/+0x28, and copies the first entry's leading 16-byte rectangle without inventing ResourceLayoutRecord or a nonexistent ResourceLayoutEntry::rect field. Both exact external ResourceLayoutRawRecordGetEntryRect callsites retain direct g_pRidingImageLib->ridingEpfPackage operands matching the binary +0x0c loads. Historical m_rawRecordTable operands are rejected; complete owner-header friendship and no-duplicate-helper/class generated expectations are explicit.`
- `        - [UID:0003RK][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) 0x0059f610-0x005a0626 | method | UserLookPane::ParseLookPacket : reconstructable : 92% : very-strong : Complete packet/parser behavior remains unchanged; the sole external ResourceLayoutRawBufferLookupEntry call is declared by direct ../../render/ResourceLayoutTable.h inclusion, replacing only the historical local prototype and preserving all ABI/caller/evidence/source facts.`

`by-item/-coverage-report.md` exact replacement row:

- `- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md) : reconstructable : 92% : very-strong : Exact 24-byte EPF/EPD row declared once in UID00006E ImageLib.h before class use: four 32-bit bounds fields and two byte pointers. KO row reads/rebasing/sentinel, KP/KQ output mapping, KT compatible raw-record prefix, and retained GetEntry 24-byte indexing are complete; late CPP duplication and separate bucket ownership are rejected.`

`by-type/by-struct/-coverage-report.md` exact replacement/no-change rows:

- `- [UID:0001US][ImageLibLayout](by-type/by-struct/ImageLibLayout.md) : reconstructable : 86% : very-strong : Exact 0x14 ImageLib object layout preserves LObject base, ref/cache fields and private generic List *m_pEntryList at +0x0c; constructor List(44,10), destructor payload cleanup, nine out-of-line ResourceLayout facet methods, the private GetEntry helper, and the H-only inline GetResourceLayout row accessor are documented. The accessor depends on the complete List declaration, emits no additional function, and exposes only a const ResourceLayoutNameRecord pointer; vtable/global anchors and the absence of independent ResourceLayout storage remain explicit. Field spellings remain confidence-capped.`
- `- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) : reconstructable : 92% : very-strong : Exact 44-byte List row declared once in UID00006E ImageLib.h before class use: wchar_t name[16], entryCount at +0x20, frameWidth at +0x22, frameHeight at +0x24, reserved at +0x26 and ResourceLayoutEntry *entries at +0x28. The GFACE caller's compare at +0x20 and load at +0x28 confirm this exact type and reject the undefined ResourceLayoutRecord convenience spelling. KO append, KP/KS/KU/KV/KW/GetEntry/accessor uses, List(44,10), source order and no late CPP duplicate are complete.`
- `- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) : ignored : 86% : very-strong : Verified non-emitting semantic alias of UID0001VT ResourceLayoutNameRecord; no separate allocation, declaration, vtable, source type or formal code is emitted.`
- `- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md) : ignored : 84% : strong : Verified non-emitting semantic alias over the generic List(44,10); no separate class, declaration, vtable, storage or formal code is emitted.`

`by-global/-coverage-report.md` and `by-memory/-coverage-report.md` singleton no-change rows:

- `- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) : reconstructable : 89% : strong : One process-wide ImageLib *g_pEPFLib declaration/definition owns the 0x0067a744 storage, lifecycle, nine out-of-line ResourceLayout facet methods and the H-only compiler-covered ResourceLayoutNameRecord row accessor. FindResourceIndex is public because nine of its thirteen exact callers are external to ImageLib/facet code; GetEntry and the List storage remain private. UID0002KQ/UID0002KT remain external no-this helpers; no g_pResourceMan, ResourceLayoutTable * storage, second singleton, independent ResourceLayout object or duplicate definition is introduced.`
- `    - [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](by-memory/0x0067a744-0x0067a748.g_pEPFLib.md) 0x0067a744-0x0067a748 | pointer-global | ImageLib *g_pEPFLib : reconstructable : 87% : very-strong : Exact four-byte singleton slot remains owned by ImageLib lifecycle and one extern declaration; nine out-of-line ResourceLayout facet methods plus the H-only inline row accessor share this receiver. FindResourceIndex has four internal and nine external callers and is therefore public; both raw helpers are no-this, and no second ResourceLayout global/storage or out-of-line accessor is emitted.`

UID000175 and its seven decoder children, UID000176/UID0002P4/UID0002P5, UID00031T and UID00031U require quoted no-change proof rather than replacement: their current coverage owners remain ImageLoaders/ImageFrameTable, none receives ResourceLayout formal source or a score change, and P6 remains the separately listed class-method exception.

## Follow-Up Actions

- B001's dated ordinary callback implemented or verified C01-C43 and C58-C126, assigned UID00054V, completed the formal dependency chain, serially scoped-validated every changed page, and physically reread every generated destination. Those receipts are evidence, not continuing generated or lifecycle authority.
- C44-C57 define supervisor-only Gate 2B dispositions: fresh session attestation, corrected I01 exact two-row poststate, I02 pure rename over that literal staged state, ordered I03-I11, hard stops, final reread, and save only after exact success. The dated failed attempt stopped at I01, ran no I02-I11 action, saved nothing, discarded the worker, and restored canonical raw prestate; B001 performed no IDA mutation, save, backup, or process control.
- Section 28 supplies the exact supervisor-owned manual coverage payload with assigned UID00054V. Coverage files were not manually edited by B001; the same-UID aggregate rename caused only validator-owned reference propagation, recorded below.
- Execution/archive authority remains supervisor-only and is determined from the report's current path plus validator-owned lifecycle history. This body makes no durable current execute/archive assertion.

## Confidence

- Ownership/source 93%; behavior 96%; range/inventory 99%; implemented compile closure 95%. The complete Section 22 dependency chain was applied together and physically proved in the dated callback generated surface; Gate 2A independently rereads later validator-owned output.
- Remaining bounded uncertainty: original filename, compatibility typedef spelling, the descriptive `GetResourceLayout` accessor spelling, and the private zero-xref `GetEntry` name/access. None changes ABI/behavior.

## Validator Results

- Exact command cwd for every row was `E:\NTK\GhidraBridge\source-3\project-documentation`; validator-reported root alias was `C:\FastStorage\NTK_Sources\source-3\project-documentation`. Every command was the literal single-line `python .\tools\validator.py --mode file --file '<path>' --apply --queue-timeout 240`; every exit was `0`, every listed `ok` count passed, and every generated refresh was reported `deferred` unless the generated snapshot table states otherwise.
- Gate 2B failure/reopen evidence and this report-text repair are not validator runs. No validator ran during this repair; the historical scoped callback receipts below remain unchanged.

| Command / timestamp | Path | Exit / ok | Literal warnings or side effects |
| --- | --- | --- | --- |
| `000000025137` / `2026-08-16T11:06:27-04:00` | `by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md` | `0 / 1` | `insert_uid:1`; assigned UID00054V. |
| `000000025138` / `2026-08-16T11:06:36-04:00` | `by-class/ResourceLayoutTable.md` | `0 / 2` | Replaced temporary child reference with UID00054V. |
| `000000025139` / `2026-08-16T11:08:10-04:00` | `by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md` | `0 / 1` | `missing_ref_uid:163` pre-existing warnings; same-UID rename/path update propagated links, including validator-owned coverage references. |
| `000000025140` / `2026-08-16T11:09:03-04:00` | `by-file/ResourceLayoutTable.md` | `0 / 1` | No warning. |
| `000000025143` / `2026-08-16T11:10:52-04:00` | `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` | `0 / 1` | No warning. |
| `000000025150` / `2026-08-16T11:12:21-04:00` | `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md` | `0 / 1` | No warning. |
| `000000025156` / `2026-08-16T11:14:27-04:00` | `by-class/ImageLib.md` | `0 / 1` | No warning. |
| `000000025158` / `2026-08-16T11:15:18-04:00` | `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` | `0 / 1` | No warning. |
| `000000025160` / `2026-08-16T11:16:01-04:00` | `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` | `0 / 1` | No warning. |
| `000000025162` / `2026-08-16T11:16:24-04:00` | `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `0 / 1` | No warning. |
| `000000025164` / `2026-08-16T11:17:10-04:00` | `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` | `0 / 1` | No warning. |
| `000000025166` / `2026-08-16T11:17:30-04:00` | `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` | `0 / 1` | No warning. |
| `000000025167` / `2026-08-16T11:18:15-04:00` | `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` | `0 / 1` | No warning. |
| `000000025168` / `2026-08-16T11:18:52-04:00` | `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` | `0 / 1` | No warning. |
| `000000025172` / `2026-08-16T11:19:56-04:00` | `by-file/ImageLib.md` | `0 / 1` | No warning. |
| `000000025184` / `2026-08-16T11:22:23-04:00` | `by-type/by-struct/ImageLibLayout.md` | `0 / 1` | Two UID00054V link-label normalizations. |
| `000000025185` / `2026-08-16T11:23:23-04:00` | `by-type/by-struct/ResourceLayoutNameRecord.md` | `0 / 1` | Score `92/94`; late CPP declaration removed. |
| `000000025186` / `2026-08-16T11:23:51-04:00` | `by-item/ResourceLayoutEntry.md` | `0 / 1` | Score `92/94`; late CPP declaration removed. |
| `000000025187` / `2026-08-16T11:24:32-04:00` | `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` | `0 / 1` | No warning. |
| `000000025188` / `2026-08-16T11:24:56-04:00` | `by-file/UserLookPane.md` | `0 / 1` | Six pre-existing missing-reference warnings: UID0003S4 three times and UID0003RJ/0003RL/0003S3 once each. |
| `000000025192` / `2026-08-16T11:25:49-04:00` | `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` | `0 / 1` | Score `91/92`; formal hash refreshed. |
| `000000025193` / `2026-08-16T11:26:45-04:00` | `by-class/NewHumanImageLib.md` | `0 / 1` | No warning. |
| `000000025194` / `2026-08-16T11:27:17-04:00` | `by-file/NewHumanImageLib.md` | `0 / 1` | No warning. |
| `000000025197` / `2026-08-16T11:28:29-04:00` | `by-class/RidingImageLib.md` | `0 / 1` | Score `92/94`; CPP/H registry moved to one header-owned declaration. |
| `000000025199` / `2026-08-16T11:29:01-04:00` | `by-file/RidingImageLib.md` | `0 / 1` | No warning. |
| `000000025202` / `2026-08-16T11:29:30-04:00` | `by-file/ResourceLayoutTable.md` | `0 / 1` | Final owner-route validation; no warning. |
| `000000025203` / `2026-08-16T11:29:34-04:00` | `by-file/ImageLib.md` | `0 / 1` | Owner-route checkpoint; no warning. |
| `000000025204` / `2026-08-16T11:29:50-04:00` | `by-file/UserLookPane.md` | `0 / 1` | Same six pre-existing UID0003S4/RJ/RL/S3 missing-reference warnings. |
| `000000025205` / `2026-08-16T11:30:00-04:00` | `by-file/NewHumanImageLib.md` | `0 / 1` | Final owner-route validation; no warning. |
| `000000025206` / `2026-08-16T11:30:11-04:00` | `by-file/RidingImageLib.md` | `0 / 1` | Final owner-route validation; no warning. |
| `000000025211` / `2026-08-16T11:31:17-04:00` | `by-type/by-struct/ResourceLayoutNameRecord.md` | `0 / 1` | Added explicit centralized-H proof comment to prevent an empty-emitter marker; no type duplication. |
| `000000025212` / `2026-08-16T11:31:29-04:00` | `by-item/ResourceLayoutEntry.md` | `0 / 1` | Added explicit centralized-H proof comment to prevent an empty-emitter marker; no type duplication. |
| `000000025214` / `2026-08-16T11:31:52-04:00` | `by-file/ImageLib.md` | `0 / 1` | Owner-route refresh after type-channel proof comments; no warning. |
| `000000025215` / `2026-08-16T11:33:36-04:00` | `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` | `0 / 1` | Deterministic emitter position 30. |
| `000000025216` / `2026-08-16T11:33:39-04:00` | `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` | `0 / 1` | Deterministic emitter position 40. |
| `000000025217` / `2026-08-16T11:33:56-04:00` | `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `0 / 1` | Deterministic emitter position 50. |
| `000000025219` / `2026-08-16T11:34:13-04:00` | `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` | `0 / 1` | Deterministic emitter position 60. |
| `000000025221` / `2026-08-16T11:34:18-04:00` | `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md` | `0 / 1` | Deterministic emitter position 70; source/name/type unchanged. |
| `000000025223` / `2026-08-16T11:34:23-04:00` | `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` | `0 / 1` | Deterministic emitter position 80. |
| `000000025225` / `2026-08-16T11:34:27-04:00` | `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` | `0 / 1` | Deterministic emitter position 90. |
| `000000025226` / `2026-08-16T11:34:32-04:00` | `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` | `0 / 1` | Deterministic emitter position 100; UID00054V remains position 110. |

- Dated callback generated readback: `ResourceLayoutTable.cpp`/`.h` command `000000025202`, hashes `7892CA10F55591102594C798D3A6B850E76C1752D69F6137BC4B2CA75888C843` / `22A1089FA60E6D936DF2A65F90E8967814FFAE879D4765726EEA2E13523E7FED`; `ImageLib.cpp`/`.h` command `000000025226`, hashes `CAB69EDB73D77EC923917A99545C1DDC83C46D549396507B29B1709946121619` / `C568FDD262870D865F5D399333CA4B6EE1C8C4181898FEA84C764FB2F41C4412`; `UserLookPane.cpp` command `000000025204`, hash `E0ED5028897E8F1C1421EDA43E7B431975EBC44072F61D7EEF074A6FFBEE0712`, H absent; `NewHumanImageLib.cpp`/`.h` command `000000025205`, hashes `D89A51D45240C11B028071CEBA9DF12CD15BC204E6F8E89A91EDD927FE6D2FEF` / `E4CFEC82BA0444B2628EF263BCB8186A5F1D13FCCCD59F35ED3C7EC741C4DEB1`; `RidingImageLib.cpp`/`.h` command `000000025206`, hashes `FFE8E234E35A3465F51C59CAD2D5328D7456BE1E84345263C2997BCD1718D1C0` / `48723EDF79FBBB0A3AFA3BEC07A9D4E30BE88FE1D63238DB5077390F52980121`.
- Verify-only dated generated readback at command `000000025165`: `ImageLoaders.cpp` hash `211770B6600EA255660A994042F4BB03D2309CCDDA2858D6D1C404F28CE3E49E`, H absent; `ImageFrameTable.cpp`/`.h` hashes `06052062B0D87C4C855B38F58127F1B8073F2A96E1CC56B85F36ACBDD8C786B9` / `FCA6BB038AFD285ECAE55E16DF575C693F667E8B85AE95685D9906F09DF5233F`, with P4/P5/31T/31U and no P6 duplicate; `MapTileImageLib.cpp` hash `1F1F6FCF2052FE5931AB77146F34711F7D26270CD22F30EC5BF617656363AFA5`, H absent; `List.h` hash `40BED2BC5266B9C25337C40756086F0B0C06DC47287D769CAD3881F5F9144091` with virtual `void *GetElementAt(int)`.
- Physical content audit passed: KQ then KT and two declarations; nine address-ordered facet definitions KO/KP/KR/KS/P6/KU/KV/KW/UID00054V; no out-of-line accessor, late row structs, or ImageLib empty marker; one UserLook owner include/call and no local prototype; three NewHuman includes, one exact GFACE route, one leading-rectangle copy, exactly two `ridingEpfPackage` operands, and zero stale identifiers; one Riding H declaration/friend-before-storage and no CPP class/extern duplicate; all seven decoders; all four frame helpers with no P6; and the separate MapTile successor.

## Changed Files

- Ordinary pages below were changed under short B001 leases and scoped-validated. Hashes, bytes, and physical line counts are callback-final snapshots; generated files were never edited directly.

| Destination | Pre-callback SHA256 | Final bytes / lines | Final SHA256 |
| --- | --- | ---: | --- |
| `by-file/ResourceLayoutTable.md` | `CED2039543D2B0439CD8DABDB91979B69F3F039B028ACAD9F65CD9FDFA4B7FA5` | `26,862 / 162` | `3CCC0B24763AF1881A2801847855726986A97146A01F61B262B32EDE0539BAED` |
| `by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md` | `C46A7C7C35C7B365B2C508F29AB63044050AC864962BD0FEF512CA9617D83448` at old same-UID path | `25,634 / 149` | `1455D4ED4860324F27A70DEA83E8C8023984A8EED1E47D866F768FE14497E9C6` |
| `by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md` / UID00054V | absent | `5,819 / 70` | `1659710509DCEDDE4D7495BA18A8020AC836BE3C3F8684C6FC3D4250786EEEB2` |
| `by-class/ResourceLayoutTable.md` | `4DA2DF570E5FFED3B1BE62B7D8BC386B878469B3ACAE5894C8388896626D5449` | `24,050 / 178` | `34FCC61CE06874E8BDAB805B9D48510D96872D3D0316BA39A8FA91BE0BEDADBF` |
| `by-class/ImageLib.md` | `2A26F0C14AB7B62F4BF8174BE8017E17B4E59BE627F6658AD6108C84B0F09201` | `24,049 / 252` | `DB81D10738532FC1F78087ED7C083E390A0BCB0145922621E73356102D241114` |
| `by-file/ImageLib.md` | `79B85C1C34B7F1205BC8D1957ED57757B65CCA22F251175177AA943BA67E677A` | `30,306 / 206` | `26347C3FEA85491413A19D2C3EFE162E1363E95D420EAD2C715DAF6187F7B070` |
| `by-type/by-struct/ImageLibLayout.md` | `0A30358954261EA11E1A1C550A7404A4773B4795E822A8A14CB521D398E7250B` | `13,601 / 100` | `8F2146201ADCBAC8F5609D1C690F81E9A6DA0C5579C55545B0AD2C3333F043C3` |
| `by-type/by-struct/ResourceLayoutNameRecord.md` | `636D879AF22D592A40BB1EC515FE0EA5FB604514625F9A492D07241811F481A8` | `10,703 / 101` | `22827AB591D7919509B4321C5B517A403A66DB50F57A70A23538FA36CB4DDFFB` |
| `by-item/ResourceLayoutEntry.md` | `B4802FC74870584076A95783F476F33C52ADBA404DE217C50395A6351DC81A2A` | `14,729 / 151` | `CBE3B75C10A90309CA03D0172AC52581DB37AE8F0A4D7ABB674275D065BEE566` |
| `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md` | `84420875A3F3F659E5BD78A39F79F465DDDBC4FB9F66787D3E1C3B3586D8ED25` | `16,305 / 199` | `B1488376E08A0476BF2DBFBE41168B3E92417839DE9DC0BB7F1629FAAECBC88C` |
| `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` | `76804D484D38F0D67A69CED3B1491234A09472EC8402375383091652B0D5C312` | `12,984 / 154` | `2FBEE1E288B98C84E08A31E374B7DC68862EE4BC234E161B1D214A7C15ECA21F` |
| `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` | `110D1C9811551475F3EFF50D4C0EE87CEB49255FDBCC3B787B445D07E141BF55` | `23,192 / 237` | `3CAE0576F9FC9AE8CDD3AAF53F744FA029EB42D27D6401F0CA5E971E9F68392A` |
| `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md` | `F21988AEEE1501C2011DC7D3061827F484BC5DBA0E0E7255845A23755383788A` | `9,558 / 105` | `4623FAE460485A5AFA65AB0CCD86B3A5570A38C591B439E619C3628B65DBB876` |
| `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md` | `0ADC76131E115AD3C140C3524C48D995E44C59777D42F7CE2EB2F8121C6D80CE` | `17,005 / 168` | `50B8B73C4DE3243A5049817217659748BC18022B765959BC6DC7D52AD60BD339` |
| `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md` | `431932A63CA52493E962F3F344F10AF540E2F3FE37939F4622DDC8A83AA49CAF` | `21,142 / 207` | `B0CF4E2B5E61AD1D2A967AC57C5F9F0B1ADB3F4A18EC8FD5C6D0C50ED01E323C` |
| `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md` | `8AD9057AC68888BDE93071D068B62530CD8CE07BEB3BE1421CCEA6FBA3D359E6` | `20,879 / 229` | `EE2AE63B1D25EE09D23E44ACD3AA082F5E972E53BF8430522D6D87C9F2CB7130` |
| `by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md` | `EE89FADD2DD2731CE0A4388560EF4D631AC78659FF84DF7B41CC261B2E0F9AFD` | `14,421 / 164` | `8DA13769EAB27EB7F936BA5A1F7A692C8F69291F3A6F93AE248A99AC2774F9F9` |
| `by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md` | `0F45426E72275FA43DF095ECA866BCF13461DF48E5ACA68264AB636875D8163F` | `10,747 / 135` | `9A76C381355A8A4D79991717612CFF2335D6AB94897EEDDA8C5F00F6861AB243` |
| `by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md` | `7A3F9F12B9ECAD1F64C7CC9FB21F81CF248D85C25741E63AA6C929D86F0E882D` | `11,201 / 133` | `7839A932AF9273FD97D247BF4E630F6B909FEE395F68020FFF0AE81A3A25D66F` |
| `by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` | `E7833DD44E32C7D822B33565BFA6A622B3C6084A400659189073C24CE6DECA86` | `35,938 / 522` | `11B17D9E6ABDA748A45432029DE7F8D56BDEF1CDDA70AB3D958870E2BB8FE1AA` |
| `by-file/UserLookPane.md` | `A6F944CE5D030FAF109C86F353F9C9104EF0FCEF248CE0214484C6F2D56FA01D` | `40,078 / 206` | `498E52418D8D2B6439493D0E0311BC3AB55566DA28995838CB325FE83BD36610` |
| `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md` | `2137F270AB60738C7A9410EE7A0571E26D3A8F3253AD37D066B233E93EBE0D2E` | `38,018 / 550` | `F037E8A2D6DF5AE9CE1C3F382465F1E7F168EFC0997886C51F564257B368725D` |
| `by-class/NewHumanImageLib.md` | `A8C98D8836F335D552C3809FE94E5E82EC3FC38BFAFB0608C10807FF6EB88867` | `89,704 / 482` | `8449AA21FDC119065A56EBDF491F5F16C856005FEC5904F2F803FA548C4F34B5` |
| `by-file/NewHumanImageLib.md` | `81F2F7C768F5D8B7A2D5EB76174E7CE5E69C8BDB60569295A865F9A7904DB0D6` | `75,169 / 331` | `68B73220AAA2DCE5709269F7357044B80DF1306635ACBB4883B0DB454B6FBED7` |
| `by-class/RidingImageLib.md` | `8FDBC2043EEC02765B614126D5D883B343A4971ACF92FE8BBA5EA1D39384D6F2` | `24,087 / 209` | `9CA81BDC9B3054B9F9C5974ADCFCB61AB8BE19DC40DE8810AA796DFD4979D7FB` |
| `by-file/RidingImageLib.md` | `8884FEE880ADD80F1953EB8B0D3DCF1034FF50534DCD82CF1E94970D23124995` | `28,638 / 187` | `CC0BFB78C484C34D5AC443B48C0B7F56E7643A277CE6FB7386E6DDC17C8094BC` |

- The old same-UID aggregate path `by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md` no longer exists; validator command 25139 performed the accepted path/reference propagation. No manual coverage, generated, IDA, audit/catalog/tracker, goal/notes, or lifecycle file was edited. Lifecycle truth remains authoritative only from current path and validator-owned status/history.
- This Gate 2B handoff repair changes only this report. The 26 ordinary-page identities above remain dated callback snapshots; the failed unsaved supervisor worker changed no canonical IDB or ordinary/generated/coverage/lifecycle artifact.
- Lease receipt: every one of the 26 ordinary destinations above returned `Success` on B001 acquisition immediately before its edit and `Success` on immediate release after its scoped-validator batch. No unrelated destination was held while waiting. Each report-only reconciliation leases only this report and releases it immediately after writing; the external return records the final no-active-lease proof.

## Implementation Tracking Checklist

Post-implementation allocation: 112 checked / 14 unchecked. This is the exact Section 11 eight-field twin with only the leading `Done` field added; the 14 unchecked rows are exactly supervisor-owned C44-C57.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0000N5 | Raise whole-file score `88/86 -> 95/93` and record a complete reconstructable two-helper CPP/H module. | Very strong | Complete source, caller, type, split, and generated audit. | UID0000N5 metadata/Status | incorporate | applied |
| [x] | C02 | 0000N5 | Retain standalone `NexusTK/render/ResourceLayoutTable.cpp/.h` only for UID0002KQ then UID0002KT in address/source order. | Very strong | Both are external no-this helpers; class methods use ImageLib receiver. | UID0000N5 ownership/source inventory | incorporate | applied |
| [x] | C03 | 0000N5 | Record exhaustive family as nine ImageLib-facet methods plus two raw helpers, with no family-owned global/static/table/string/vtable/RTTI item. | Certain | Complete function/data/type/xref search. | UID0000N5 complete inventory | incorporate | applied |
| [x] | C04 | 000174 | Correct same-UID path/range to `[0x004d0120,0x004d1860)`, 5,952 bytes, SHA256 `7C8447664D714D5C45F451BB894D7D7C1EE557DD6433229970D9BBC4ED3D8897`. | Certain | Fresh raw MCP read and independent hash. | UID000174 identity/range/history | reject-stale | applied |
| [x] | C05 | 000174 | Preserve all 20 internal `0xcc` gaps and exact included/excluded child map; aggregate remains non-emitting. | Certain | Complete byte/boundary inventory. | UID000174 split/padding inventory | incorporate | applied |
| [x] | C06 | 0002KQ | Emit exact raw-buffer parser, including one-row initialization, non-zeroing allocation, row-one mask-length read, and unreleased allocation. | Certain | Exact 304-byte body/decompile/callees. | UID0002KQ formal CPP/behavior/history | incorporate | applied |
| [x] | C07 | 0002KQ | Replace unresolved blocker with faithful historical-bug rationale; reject loop, sentinel, zero-fill, free, and new guards. | Very strong | Negative instruction/callee evidence. | UID0002KQ source-quality/history | reject-stale | applied |
| [x] | C08 | 0002KQ | Centralize complete ResourceLayoutTable.h in UID0002KQ formal H with both external declarations; set position 10. | Very strong | Required cross-file declarations and header absence. | UID0002KQ formal H/emitter position | incorporate | applied |
| [x] | C09 | 0002KT | Replace static duplicate-table source with external `RectBounds *__stdcall` over `const ArchiveMetadataTable *`; position 20 and blank H centralization rationale. | Certain | ABI, 28 callers, accepted table layout. | UID0002KT formal CPP/H/metadata | reject-stale | applied |
| [x] | C10 | 0002KO | Correct loader to ignore Open result, seek `(offset,1)` then `(0,0)`, read four signed shorts, preserve sentinel/rebase/append and count-minus-one. | Certain | Live decompile and exact calls. | UID0002KO formal CPP/behavior/history | reject-stale | applied |
| [x] | C11 | 0002KP | Change LookupLayoutEntry CPP/H return to void, preserve 32-bit source frame index, mapping, next-row mask formula, and InitRectBounds failure. | Certain | Live type/body and 440 callers. | UID0002KP formal CPP; UID00006E H | reject-stale | applied |
| [x] | C12 | 0002KR | Preserve exact stack EPFTileContext initialize/void lookup/conditional CopyTo wrapper. | Certain | 82-byte body and 25 calls. | UID0002KR behavior/formal CPP | already-present | already-present |
| [x] | C13 | 0002KS | Change GetEntryRect CPP/H return to void and preserve lazy lookup, signed test, 16-byte copy, and InitRectBounds failure. | Certain | Live 107-byte void body and 11 calls. | UID0002KS formal CPP; UID00006E H | reject-stale | applied |
| [x] | C14 | 0002P6 | Preserve LoadFrameDrawRecord, including invalid pointer-only clears and next-record payload-span read. | Certain | 93-byte body, exact type, 81 calls. | UID0002P6 behavior/formal CPP | already-present | already-present |
| [x] | C15 | 0002KU | Preserve lazy frame-size lookup and record `+0x22/+0x24` copies. | Certain | 67-byte body and sole caller. | UID0002KU behavior/formal CPP | already-present | already-present |
| [x] | C16 | 0002KV | Preserve lazy lookup and unsigned 16-bit count return. | Certain | 51-byte body and six calls. | UID0002KV behavior/formal CPP | already-present | already-present |
| [x] | C17 | 0002KW | Replace repeated generated GetElementAt calls with one `GetElementAt(0)` and 44-byte pointer walk. | Certain | Live 111-byte decompile. | UID0002KW formal CPP/history | reject-stale | applied |
| [x] | C18 | 0000BY | Create exact child `[0x004d1830,0x004d1860)` for private `ResourceLayoutEntry *GetEntry(int,int)`, parent UID0000BY, position 110. | Very strong | 48 bytes, two exits, List slot, row math. | New by-memory child; UID0000BY inventory | incorporate | applied |
| [x] | C19 | 00006E | Replace `ImageLib.h` with its `List.h` dependency, both row structs before class use, public `FindResourceIndex`, inline compiler-covered `GetResourceLayout`, corrected void APIs, private `GetEntry`, existing fields/guard, typedef, and extern. | Very strong | Exact GFACE lowering, 13 Find calls, established List API, and dated command-25126 H incompleteness. | UID00006E complete formal H | incorporate | applied |
| [x] | C20 | 0001VT | Use the exact 44-byte `ResourceLayoutNameRecord` for the GFACE row, move its declaration from late CPP into UID00006E H, and reject undefined `ResourceLayoutRecord` as a duplicate convenience type. | Certain | GFACE reads `+0x20` entryCount and `+0x28` entries from the List(44,10) row. | UID0001VT formal channel/history and UID0002V8 type route | reject-stale | applied |
| [x] | C21 | 0000VB | Move exact 24-byte ResourceLayoutEntry declaration from late CPP into UID00006E H; retain type page as no-duplicate evidence. | Certain | Row stride, fields, sentinel, compile order. | UID0000VB formal channel/history | reject-stale | applied |
| [x] | C22 | 0000K2 | Add exact ImageLib CPP dependencies and the complete `../util/List.h` H dependency required by inline `GetResourceLayout`; preserve unaffected lifecycle and all out-of-line method children in source order. | Very strong | Generated compile audit and exact List virtual-access lowering. | UID0000K2 CPP/H dependency inventory | incorporate | applied |
| [x] | C23 | 0000K2 | Record nine out-of-line facet methods plus the public H-only compiler-covered `GetResourceLayout` accessor; make `FindResourceIndex` public and require one declaration/definition route per symbol with no out-of-line accessor body. | Very strong | Complete family inventory, 13 Find calls, and two observed inline List-slot lowerings. | UID0000K2 file/generated/API inventory | incorporate | applied |
| [x] | C24 | 0000BY | Expand the class/facet inventory to nine out-of-line methods plus H-only `GetResourceLayout`, expose `FindResourceIndex` publicly, retain `GetEntry` privately, preserve no independent object/vtable, and label alias/accessor spelling inferred. | Very strong | Lifecycle/vtable/global negatives plus external caller and inline-access evidence. | UID0000BY class/API inventory | incorporate | applied |
| [x] | C25 | 0003RK | Replace local KQ forward declaration with direct include `../../render/ResourceLayoutTable.h`; preserve parser/score. | Very strong | Caller source and new owner H. | UID0003RK formal CPP/dependencies | incorporate | applied |
| [x] | C26 | 000092 | Add literal `#include "ImageLib.h"`, `#include "ResourceLayoutTable.h"`, and `#include "RidingImageLib.h"` before UID0002V8's complete formal CPP; use public `FindResourceIndex`, inline `GetResourceLayout`, exact `ResourceLayoutNameRecord`, and both declared KT/private-field routes. | Very strong | Exact GFACE disassembly, two KT callsites, dated missing includes, and complete formal replacement. | UID000092/UID0002V8 formal CPP dependency and GFACE route | incorporate | applied |
| [x] | C27 | 0002V8 | Replace both stale `m_rawRecordTable` operands with `ridingEpfPackage`, preserving indexes/order/unions. | Certain | Binary direct `+0x0c` loads. | UID0002V8 formal CPP/history | reject-stale | applied |
| [x] | C28 | 0000BZ | Move the complete `RidingImageLib` declaration into UID0000BZ formal H with guard, `LObject` dependency, exact forwards/API/externs, and `friend class NewHumanImageLib;` immediately before the three private storage fields. | Very strong | Direct field access, existing CPP declaration, and absent H; no accessor call. | UID0000BZ complete formal CPP/H move | incorporate | applied |
| [x] | C29 | 0001VU | Preserve ResourceLayoutStore as non-emitting alias over generic List; no class/vtable. | Certain | Constructor and List vtable. | UID0001VU no-code proof | already-present | already-present |
| [x] | C30 | 0001VS | Preserve ResourceLayoutBucket as non-emitting alias of ResourceLayoutNameRecord. | Certain | Same row; no lifecycle. | UID0001VS no-code proof | already-present | already-present |
| [x] | C31 | 0000QU | Preserve one `extern ImageLib *g_pEPFLib`, one ImageLib lifecycle, and no ResourceLayout global. | Certain | Lifecycle/global xrefs. | UID0000QU/UID0001OQ evidence | already-present | already-present |
| [x] | C32 | 000175 | Keep all seven decode wrappers outside ResourceLayout ownership. | Certain | Formats/callers/pages. | UID000175/children exclusions | already-present | already-present |
| [x] | C33 | 000176 | Keep frame-table load/destroy/copy helpers outside ResourceLayout ownership; P6 alone is class method. | Certain | Roles/owners/pages. | UID000176/00031T/00031U | already-present | already-present |
| [x] | C34 | 000174 | Historicalize old range hash `A79F027CB1059637E061D17A455ACD277D47EB9EB136E544C7110A825E26DE0E` as incomplete-range evidence. | Certain | Fresh old-scope hash and new function. | UID000174 history | historicalize | applied |
| [x] | C35 | 0000N5 | Historicalize one-body/one-empty generated state, static KT, duplicate struct, wrong order, and absent H. | Certain | Physical generated snapshot. | UID0000N5 generated/history | historicalize | applied |
| [x] | C36 | 0002KQ | Raise `86/89 -> 93/93` after faithful source/declaration/ownership/blocker closure. | Very strong | Full source closure. | UID0002KQ metadata | incorporate | applied |
| [x] | C37 | 0002KT | Raise `88/90 -> 92/93` after type/linkage/header/caller closure. | Very strong | Full ABI closure. | UID0002KT metadata | incorporate | applied |
| [x] | C38 | 0002KO | Raise `90/90 -> 94/94` after correcting observed source mismatches. | Very strong | Complete body evidence. | UID0002KO metadata | incorporate | applied |
| [x] | C39 | 0002KP | Raise `90/91 -> 94/95` after void/failure correction. | Very strong | Exact body/440 xrefs. | UID0002KP metadata | incorporate | applied |
| [x] | C40 | 0002KS | Raise `89/90 -> 93/94` after void/failure correction. | Very strong | Exact body/callers. | UID0002KS metadata | incorporate | applied |
| [x] | C41 | 0002KW | Raise `90/92 -> 93/95` after pointer-walk correction. | Very strong | Exact body. | UID0002KW metadata | incorporate | applied |
| [x] | C42 | 0000BY | Raise class `90/91 -> 94/94`; use only Section 26 support scores. | Strong | Complete method/header boundary. | UID0000BY/0000K2/00006E metadata | incorporate | applied |
| [x] | C43 | 0000N5 | Supply exact complete manual coverage replacements/insertions for every affected target/support route, including UID000079/UID0000KS List dependencies and all GFACE API/type consumers, without editing coverage files. | Certain | Manual rows were physically read and compared for this report. | Section 28 coverage roots | incorporate | applied |
| [ ] | C44 | 0000BY | I01 define exact function `[0x004d1830,0x004d1860)` and require the observed type-absent, zero-local frame containing only `__saved_registers` and `__return_address`; no argument rows and no save on mismatch. | Very strong | Exact body/boundary/hash plus public `define_func` and immediate `stack_frame` receipt. | Supervisor Gate 2B I01 | incorporate | proposed |
| [ ] | C45 | 0000BY | I02 pure-rename the exact staged type-absent, two-row function to `ResourceLayoutTable__GetEntry`, changing no frame/type/comment/byte/xref/boundary field. | Strong | Public pure-rename schema, staged prestate, semantics and noncollision. | Supervisor Gate 2B I02 | incorporate | proposed |
| [ ] | C46 | 0002KO | I03 pure-rename `sub_4D0120` to `ResourceLayoutTable__LoadResourceIndex`. | Very strong | Body/graph/noncollision. | Supervisor Gate 2B I03 | incorporate | proposed |
| [ ] | C47 | 0002KP | I04 pure-rename `ResourceLayoutTable_LookupLayoutEntry` to `ResourceLayoutTable__LookupLayoutEntry`. | Very strong | Semantic name/noncollision. | Supervisor Gate 2B I04 | incorporate | proposed |
| [ ] | C48 | 0002KQ | I05 pure-rename `sub_4D03A0` to `ResourceLayoutRawBufferLookupEntry`. | Very strong | Body/caller/noncollision. | Supervisor Gate 2B I05 | incorporate | proposed |
| [ ] | C49 | 0002KR | I06 pure-rename `sub_4D04D0` to `ResourceLayoutTable__CopyEntryTileContext`. | Very strong | Body/callers/noncollision. | Supervisor Gate 2B I06 | incorporate | proposed |
| [ ] | C50 | 0002KS | I07 pure-rename `sub_4D0530` to `ResourceLayoutTable__GetEntryRect`. | Very strong | Body/callers/noncollision. | Supervisor Gate 2B I07 | incorporate | proposed |
| [ ] | C51 | 0002KT | I08 pure-rename `sub_4D05A0` to `ResourceLayoutRawRecordGetEntryRect`. | Very strong | Body/callers/noncollision. | Supervisor Gate 2B I08 | incorporate | proposed |
| [ ] | C52 | 0002KU | I09 pure-rename `sub_4D1730` to `ResourceLayoutTable__GetFrameSize`. | Very strong | Body/noncollision. | Supervisor Gate 2B I09 | incorporate | proposed |
| [ ] | C53 | 0002KV | I10 pure-rename `sub_4D1780` to `ResourceLayoutTable__GetEntryCount`. | Very strong | Body/noncollision. | Supervisor Gate 2B I10 | incorporate | proposed |
| [ ] | C54 | 0002KW | I11 pure-rename `sub_4D17C0` to `ResourceLayoutTable__FindResourceIndex`. | Very strong | Body/noncollision. | Supervisor Gate 2B I11 | incorporate | proposed |
| [ ] | C55 | 0002P6 | Preserve exact P6 name/declaration, five frame rows, zero locals, independently stated AR/AP/FR/FP, 93-byte hash, 81 exact code xrefs, zero data xrefs and zero callees; no action and no save on mismatch. | Certain | Complete literal protected prestate/no-change/readback contract. | Gate 2B protected P6 row | already-present | proposed |
| [ ] | C56 | 0000N5 | Require fresh session enumeration/attestation, P6 pre-readback, deterministic I01 two-row poststate then I02 pure rename, ordered I03-I11, immediate action readbacks, complete final reread including P6, and fail-closed no-save behavior. | Certain | Session lifecycle, failed-I01 receipt, corrected staging and literal contracts. | Section 21 contract | incorporate | proposed |
| [ ] | C57 | 0000N5 | Preserve read-only B-agent disposition and dated rollback truth: B001 made no IDA mutation/save/backup/process-control change; failed supervisor I01 was unsaved/discarded, I02-I11 did not run, and canonical raw prestate returned. | Certain | B001 tool audit plus supervisor failed-I01/discard/reopen receipt. | Report IDA status | already-present | proposed |
| [x] | C58 | 0000N5 | Apply all target/support facts at report detail and preserve contradictions as dated history. | Certain | Destination audit. | Sections 24-25 | incorporate | applied |
| [x] | C59 | 0000N5 | Apply every complete owner-specific formal CPP block in Section 22, including UID0002V8's legal GFACE row/accessor/rectangle route and two Riding replacements plus UID0000BZ's header-include/`[[CHILDREN]]` owner shell with no CPP class redeclaration. | Very strong | Exact source reconstruction and no-duplicate owner route. | Formal CPP channels | incorporate | applied |
| [x] | C60 | 0000N5 | Apply every complete owner-specific formal H block in Section 22, including ImageLib's List dependency, exact rows, public Find, inline compiler-covered accessor/private GetEntry split, and the guarded complete `RidingImageLib.h` declaration with narrow friendship before private storage. | Very strong | Compile-visible guarded owner declarations, access control, and types. | Formal H channels | incorporate | applied |
| [x] | C61 | 0000N5 | Use no third-party import; all bodies are reconstructed NexusTK project source. | Certain | Source-family evidence. | Formal disposition | not-applicable | excluded-with-reason |
| [x] | C62 | 0000N5 | Callback must scoped-validate each changed page and reread affected generated CPP/H against full inventory. | Certain | Validator workflow. | Sections 29/31 | incorporate | applied |
| [x] | C63 | 0000N5 | Report has 33 exact headings, 126/126 twin parity, two formal C++ fences, lifecycle-neutral post-implementation prose, and one terminal readiness marker. | Certain | Mechanical report audit. | Report structure | already-present | already-present |
| [x] | C64 | 0002TJ | Keep exact ZPF/FPF decoder `[0x004d05f0,0x004d0723)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | Format behavior, owner page and generated definition. | UID0002TJ/UID0000K3 exclusion route | already-present | already-present |
| [x] | C65 | 0002TK | Keep exact raw FPF decoder `[0x004d0730,0x004d07a3)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | Raw body/signature and generated definition. | UID0002TK/UID0000K3 exclusion route | already-present | already-present |
| [x] | C66 | 0002TL | Keep exact JPF/libjpeg decoder `[0x004d07b0,0x004d09a7)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | IJG/RGB565 behavior and generated definition. | UID0002TL/UID0000K3 exclusion route | already-present | already-present |
| [x] | C67 | 0002TM | Keep exact 8-bit BMP decoder `[0x004d09b0,0x004d0a8a)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | BMP/palette behavior and generated definition. | UID0002TM/UID0000K3 exclusion route | already-present | already-present |
| [x] | C68 | 0002TN | Keep exact JPEG-buffer decoder `[0x004d0a90,0x004d0c58)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | Minimap/IJG behavior and generated definition. | UID0002TN/UID0000K3 exclusion route | already-present | already-present |
| [x] | C69 | 00032P | Keep exact PNG-file decoder `[0x004d0c60,0x004d0d89)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | LodePNG file/RGBA conversion evidence. | UID00032P/UID0000K3 exclusion route | already-present | already-present |
| [x] | C70 | 00032O | Keep exact PNG-resource decoder `[0x004d0d90,0x004d0f4a)` in ImageLoaders with nonblank CPP, blank H, unchanged 88/89 and no ResourceLayout ownership. | Certain | LodePNG memory/DAT behavior. | UID00032O/UID0000K3 exclusion route | already-present | already-present |
| [x] | C71 | 0002P4 | Keep exact frame-table loader `[0x004d0f50,0x004d15c5)` in ImageFrameTable with nonblank CPP, blank H, unchanged 89/92 and no ResourceLayout ownership. | Certain | DAT/frame-table construction and generated definition. | UID0002P4/UID0000K1 exclusion route | already-present | already-present |
| [x] | C72 | 0002P5 | Keep exact frame-table destroy helper `[0x004d15d0,0x004d15fc)` in ImageFrameTable with nonblank CPP, blank H, unchanged 88/92 and no ResourceLayout ownership. | Certain | Allocation pairing/eight callers and generated definition. | UID0002P5/UID0000K1 exclusion route | already-present | already-present |
| [x] | C73 | 00031T | Keep exact payload-copy helper `[0x004d1660,0x004d1704)` in ImageFrameTable with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | Raw body/MemoryMan/no-xref evidence. | UID00031T/UID0000K1 exclusion route | already-present | already-present |
| [x] | C74 | 00031U | Keep exact bounds-copy helper `[0x004d1710,0x004d172d)` in ImageFrameTable with nonblank CPP, blank H, unchanged 88/90 and no ResourceLayout ownership. | Certain | Raw 24-byte-stride/movups/no-xref evidence. | UID00031U/UID0000K1 exclusion route | already-present | already-present |
| [x] | C75 | 0000VN | Preserve `[0x004d02e5,0x004d02f0)` as 11 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C76 | 0000VN | Preserve `[0x004d039e,0x004d03a0)` as 2 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C77 | 0000VN | Preserve `[0x004d0522,0x004d0530)` as 14 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C78 | 0000VN | Preserve `[0x004d059b,0x004d05a0)` as 5 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C79 | 0000VN | Preserve `[0x004d05e6,0x004d05f0)` as 10 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C80 | 0000VN | Preserve `[0x004d0723,0x004d0730)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C81 | 0000VN | Preserve `[0x004d07a3,0x004d07b0)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C82 | 0000VN | Preserve `[0x004d09a7,0x004d09b0)` as 9 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C83 | 0000VN | Preserve `[0x004d0a8a,0x004d0a90)` as 6 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C84 | 0000VN | Preserve `[0x004d0c58,0x004d0c60)` as 8 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C85 | 0000VN | Preserve `[0x004d0d89,0x004d0d90)` as 7 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C86 | 0000VN | Preserve `[0x004d0f4a,0x004d0f50)` as 6 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C87 | 0000VN | Preserve `[0x004d15c5,0x004d15d0)` as 11 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C88 | 0000VN | Preserve `[0x004d15fc,0x004d1600)` as 4 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C89 | 0000VN | Preserve `[0x004d165d,0x004d1660)` as 3 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C90 | 0000VN | Preserve `[0x004d1704,0x004d1710)` as 12 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C91 | 0000VN | Preserve `[0x004d172d,0x004d1730)` as 3 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C92 | 0000VN | Preserve `[0x004d1773,0x004d1780)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C93 | 0000VN | Preserve `[0x004d17b3,0x004d17c0)` as 13 `0xcc` bytes with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C94 | 0000VN | Preserve `[0x004d182f,0x004d1830)` as 1 `0xcc` byte with no source or emission. | Certain | Exact gap-byte audit. | UID000174 gap inventory / ignored route | already-present | already-present |
| [x] | C95 | 0001US | Add GetEntry's use of the established ImageLib `+0x0c List *` while preserving the exact 0x14 layout and 86/90. | Certain | New method body and existing layout proof. | ImageLibLayout support page | incorporate | applied |
| [x] | C96 | 0001OQ | Preserve exact four-byte `g_pEPFLib` storage at `0x0067a744`, one ImageLib lifecycle route and no duplicate ResourceLayout global. | Certain | Global address/lifecycle evidence. | g_pEPFLib by-memory support page | already-present | already-present |
| [x] | C97 | 0000P0 | Add UID0003RK's direct ResourceLayoutTable.h dependency/generated expectation without changing UserLookPane's 92/93 inventory. | Very strong | Sole KQ caller and formal include correction. | UserLookPane by-file support | incorporate | applied |
| [x] | C98 | 0000LR | Add UID0002V8's ImageLib/ResourceLayoutTable/Riding dependencies, exact GFACE row/accessor/public-Find route, and generated expectations without pruning NewHumanImageLib's inventory or changing 91/91. | Very strong | GFACE direct/virtual calls, two KT calls, and direct Riding field reads. | NewHumanImageLib by-file support | incorporate | applied |
| [x] | C99 | 0000N6 | Add narrow friendship/private-field route and generated expectation without pruning RidingImageLib's inventory or changing 91/92. | Very strong | Exact +0x0c access and formal friend insertion. | RidingImageLib by-file support | incorporate | applied |
| [x] | C100 | 0000K3 | Preserve ImageLoaders as owner of exactly seven excluded decoder bodies, all present in generated CPP, with no ResourceLayout ownership. | Certain | Child pages and physical generated readback. | ImageLoaders by-file verify-only route | already-present | already-present |
| [x] | C101 | 0000K1 | Preserve ImageFrameTable as owner of P4/P5/31T/31U and shared types, with P6 absent from its CPP. | Certain | Child pages and physical generated readback. | ImageFrameTable by-file verify-only route | already-present | already-present |
| [x] | C102 | 000175 | Preserve decoder aggregate as an index over seven individually owned ImageLoaders children, not an extra ResourceLayout body. | Certain | Complete range/child matrix. | ImageDecodeWrappers aggregate | already-present | already-present |
| [x] | C103 | 000176 | Preserve frame aggregate as non-emitting index; P4/P5 remain ImageFrameTable-owned and P6 remains separately ResourceLayout-owned. | Certain | Complete frame neighborhood split. | ImageFrameTable aggregate | already-present | already-present |
| [x] | C104 | 0000UN | Preserve ArchiveMetadataTable/PackedArchiveRecord/FrameDrawRecord declarations as the shared H dependency for KT, P6 and frame helpers. | Certain | Exact layouts and generated H readback. | EPFArchiveMetadataTable item support | already-present | already-present |
| [x] | C105 | 0000UX | Preserve LoadFrameDrawRecord item as a non-emitting semantic mirror; UID0002P6 alone owns the definition. | Certain | Item metadata and no-duplicate route. | LoadFrameDrawRecord item support | already-present | already-present |
| [x] | C106 | 0000UY | Preserve LoadImageFrameTable item as a non-emitting semantic mirror; UID0002P4 alone owns the definition. | Certain | Item metadata and no-duplicate route. | LoadImageFrameTable item support | already-present | already-present |
| [x] | C107 | 0002IZ | Preserve MapTile constructor `[0x004d1860,0x004d199e)` as the exact successor and exclude it from UID000174/ResourceLayout source. | Certain | Successor prologue/range/page. | MapTile constructor boundary route | already-present | already-present |
| [x] | C108 | 000177 | Preserve MapTile local-method cluster as a non-emitting successor index with no overlap at corrected end `0x004d1860`. | Certain | Aggregate boundary metadata. | MapTile cluster boundary route | already-present | already-present |
| [x] | C109 | 00007T | Preserve MapTileImageLib class ownership and 92/94 source route after the exact successor boundary. | Certain | Constructor parent/emitter metadata. | MapTileImageLib class boundary route | already-present | already-present |
| [x] | C110 | 0000L5 | Preserve MapTileImageLib file ownership and 91/93 generated route; no ResourceLayout callback edit applies. | Certain | File/source boundary evidence. | MapTileImageLib by-file boundary route | already-present | already-present |
| [x] | C111 | 0000N5 | Callback-generated ResourceLayoutTable.cpp must contain exactly corrected KQ then KT definitions, with no static helper, duplicate table or empty marker. | Certain | Dated generated defect readback and formal CPP. | Generated ResourceLayoutTable.cpp | incorporate | applied |
| [x] | C112 | 0000N5 | Callback-generated ResourceLayoutTable.h must contain exactly both external declarations from UID0002KQ formal H. | Certain | Dated generated absence and cross-file caller requirements. | Generated ResourceLayoutTable.h | incorporate | applied |
| [x] | C113 | 0000K2 | Callback-generated `ImageLib.cpp` must contain exactly nine out-of-line facet definitions, corrected KO/KP/KS/KW, new `GetEntry`, no out-of-line `GetResourceLayout`, and no late duplicate row structs. | Certain | Dated eight-method readback, compiler-covered accessor evidence, and formal CPP. | Generated ImageLib.cpp | incorporate | applied |
| [x] | C114 | 00006E | Callback-generated `ImageLib.h` must include `List.h`, declare both row types before class use, expose public `FindResourceIndex` and inline `GetResourceLayout`, retain private `GetEntry`, and preserve the complete class, typedef, singleton extern, and size guards. | Certain | Dated incomplete H readback and complete formal H. | Generated ImageLib.h | incorporate | applied |
| [x] | C115 | 0000P0 | Callback-generated UserLookPane.cpp must use the owner H include, retain one KQ call and contain no local KQ prototype. | Certain | Dated generated caller readback. | Generated UserLookPane.cpp | incorporate | applied |
| [x] | C116 | 0000P0 | Preserve intentional absence of UserLookPane.h for this dependency-only correction; no declaration is moved there. | Strong | Existing file route and CPP-only change. | Generated UserLookPane.h | already-present | already-present |
| [x] | C117 | 0000LR | Callback-generated `NewHumanImageLib.cpp` must include `ImageLib.h`, `ResourceLayoutTable.h`, and `RidingImageLib.h`; preserve UID0002V8's complete body; use `ResourceLayoutNameRecord` with public Find/inline accessor in GFACE; use `ridingEpfPackage` at both KT callsites; and contain no `ResourceLayoutRecord` or `m_rawRecordTable`. | Certain | Exact GFACE lowering, two binary Riding +0x0c reads, and dated generated defects. | Generated NewHumanImageLib.cpp | incorporate | applied |
| [x] | C118 | 000092 | Preserve complete `NewHumanImageLib.h` and verify it introduces no duplicate ResourceLayout helper/accessor/row declaration, `RidingImageLib` class declaration, undefined `ResourceLayoutRecord`, or stale field declaration. | Very strong | Existing generated H and complete class inventory. | Generated NewHumanImageLib.h | already-present | already-present |
| [x] | C119 | 0000N6 | Callback-generated `RidingImageLib.cpp` must include `RidingImageLib.h`, retain all `[[CHILDREN]]` method/global definitions in source order, and contain no duplicate `RidingImageLib` class or extern declaration. | Very strong | Dated CPP class shell, child order, and exact layout. | Generated RidingImageLib.cpp | incorporate | applied |
| [x] | C120 | 0000BZ | Callback-generated `RidingImageLib.h` must contain the complete guarded owner declaration, `LObject` include, exact forwards/API/externs, and `friend class NewHumanImageLib;` before `ridingDefinitions`/`ridingDefinitionCount`/`ridingEpfPackage`. | Very strong | Dated H absence and two direct private reads. | Generated RidingImageLib.h | incorporate | applied |
| [x] | C121 | 0000K3 | Preserve generated ImageLoaders.cpp with all seven decoder definitions and zero empty markers; no callback edit applies. | Certain | Dated physical readback. | Generated ImageLoaders.cpp | already-present | already-present |
| [x] | C122 | 0000K3 | Preserve intentional absence of ImageLoaders.h because all seven decoder child H channels are blank/file-local. | Certain | Formal channel and generated readback. | Generated ImageLoaders.h | already-present | already-present |
| [x] | C123 | 0000K1 | Preserve generated ImageFrameTable.cpp with P4/P5/31T/31U and no P6 duplicate; no callback edit applies. | Certain | Dated physical readback. | Generated ImageFrameTable.cpp | already-present | already-present |
| [x] | C124 | 0000UN | Preserve generated ImageFrameTable.h with shared ArchiveMetadataTable/FrameDrawRecord declarations used by KT/P6/frame helpers. | Certain | Dated physical readback. | Generated ImageFrameTable.h | already-present | already-present |
| [x] | C125 | 0000L5 | Preserve generated MapTileImageLib.cpp as the separate successor-family output beginning at `0x004d1860`; no callback edit applies. | Certain | Dated physical readback and boundary. | Generated MapTileImageLib.cpp | already-present | already-present |
| [x] | C126 | 0000L5 | Preserve intentional absence of MapTileImageLib.h and make no ResourceLayout-driven header change. | Strong | Existing file/class route. | Generated MapTileImageLib.h | already-present | already-present |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000025406","destination_path":"executed-b-agent-research/B001/0000N5-ResourceLayoutTable-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0000N5-ResourceLayoutTable-file-source-quality.md","timestamp":"2026-08-17T11:02:03-04:00","uid":"0000N5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
