# UID0002XU g_pIconsPane Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0002XU **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Provenance: `CHATGPT | 5.6 | xHigh`

Research date: `2026-08-17` (`America/New_York`)

Dated original-assignment snapshot: on 2026-08-17, `tools/leaser/Agents/Agent-B002/goal.md` had SHA256 `A231EDF9893BC1FB390B7FF6A8AB3A2A4120B957B89B67795E854AE0EA67B591`. That mutable-file hash is historical evidence only and has no continuing authority; assignment authority is established by rereading the goal artifact applicable to the current supervisor action.

## Finalized Report / Current Recommendation

[UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](../../../../by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md) is one native x86 pointer slot in the loader-zeroed virtual tail of `.data`. Its six exact data xrefs prove one `IconsPane` singleton: direct `Singleton<IconsPane>` construction publishes the complete object, ordinary and scalar teardown lowerings clear it, `MapPane` exit-to-menu teardown conditionally queues it, and old `OptionPane` reads it to initialize and apply control `6`.

The source-quality repair is deterministic:

- [UID:0000R6][g_pIconsPane](../../../../by-global/g_pIconsPane.md) owns the sole external-linkage definition `IconsPane *g_pIconsPane = NULL;` in `NexusTK/ui/panels/IconsPane.cpp`, followed by `[[CHILDREN]]`.
- [UID:00006B][IconsPane](../../../../by-class/IconsPane.md) keeps the sole `extern IconsPane *g_pIconsPane;` declaration in its existing complete H block. Its CPP block contains the comment-only source-topology output plus explicit `[[CHILDREN]]` aggregation so the existing exact method bodies remain lossless.
- Physical child UID0002XU emits only an exact covered-by CPP marker and keeps H blank. It does not duplicate the object definition.
- File owner [UID:0000JZ][IconsPane](../../../../by-file/IconsPane.md) remains `NexusTK/ui/panels/`; source order is class `10`, global `30`, and physical child `10` under the global.
- The stale old `OptionPane` constructor expression `!g_pIconsPane->IsReducedIconMode()` is replaced by `!g_pIconsPane->IsShowingAllIcons()`. The accepted source-facing accessor identity at `0x004cf290` is `IconsPane::IsShowingAllIcons`; its literal current IDA identity remains `sub_4CF290` with type `char __thiscall(_BYTE *this)`. The body returns `m_showAllIcons`, and the caller's `setz` passes its inverse to control `6`.

The dated 2026-08-17 ordinary callback physically applied metadata UID0002XU `92/94`, UID0000R6 `92/94`, UID0000JZ `91/92`, and UID00006B unchanged at `92/94`. Reconstructable, owner, and emitter relationships remain true and unchanged except for deterministic emitter positions.

## Supporting Research

The following table is the dated pre-callback physical readback retained as implementation history:

| Artifact | Pre-callback SHA256 | Dated state |
| --- | --- | --- |
| `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md` | `FF9DC32A83F688CB1640890C873E4631B88941CE732E2589BE763B2BCB811FC9` | `88/90`, owner/emitter UID0000R6, blank CPP/H, stale saved-name and old-gate wording |
| `by-global/g_pIconsPane.md` | `0FB510C77A420FD812B7C2F0CE5B683B693BEC4F73F6D7DB09DF760305B984BA` | `88/89`, owner/emitter UID0000JZ, blank CPP/H, stale explicit-destructor-clear claims |
| `by-class/IconsPane.md` | `B2D1D9C8FAA6265221C421996728E2A0C221E7A1835AAC58F89DF00DE7A884D8` | `92/94`, complete H declaration and one extern, blank CPP, direct Singleton evidence |
| `by-file/IconsPane.md` | `B4D4982F669CDD7B7E7CC0FA7549023CA34D3859FDA3DCC10F9926B1821ED69B` | `90/91`, correct file root and child topology, missing global definition closure |
| `auto-generated/NexusTK/ui/panels/IconsPane.cpp` | `D27F1698F3BDD360B55FF29008D67115890464499B4D4ED59B3273916C8F2F17` | Dated command `000000025458`; three trailing empty markers for UID00006B/UID0000R6/UID0002XU |
| `auto-generated/NexusTK/ui/panels/IconsPane.h` | `BB44792321DF4F9B83840ECDE1CBC45B35F83213335E6C9758F3291CC145F35C` | Dated command `000000025458`; one complete class and exactly one extern |

The dated post-callback physical readback is:

| Artifact | Post-callback SHA256 | Bytes / lines | Applied current content |
| --- | --- | ---: | --- |
| `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md` | `9F7281ED1FCEFACF8FE0875A952A207EE724A29339F1364F60E077DC53AA9EA2` | `11753 / 108` | `92/94`, position `10`, exact covered-by CPP, blank H, complete zero/xref/source evidence |
| `by-global/g_pIconsPane.md` | `F47866A1FAE8EAE91013274FD2AD9AE3FF3D7F9DECA2C5C172B6F0B57434603A` | `12010 / 101` | `92/94`, position `30`, sole definition plus `[[CHILDREN]]`, blank H, lifecycle history reconciled |
| `by-class/IconsPane.md` | `EC588691B4E6AF7612E49A18EDB44A3C001FC352DCB4ABEDB3DE2B39B1B60438` | `46196 / 243` | `92/94`, complete H, comment-only CPP output plus explicit `[[CHILDREN]]`, empty human destructor source route |
| `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `88961DE4C60334F88AB80E6134D4E6CB0D4D4B27BAB1CF5C9CBF1A95999642C6` | `31462 / 261` | Exact old-assets read/queue and non-owner/no-clear route; score/formal source unchanged |
| `by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md` | `5FEF1CC623287CA36AF5CC9E120EBBD5E181E7A1330722D6090673BA4BB4CD9F` | `8748 / 104` | Exact `!g_pIconsPane->IsShowingAllIcons()` source and `setz` polarity; `88/90` preserved |
| `by-file/IconsPane.md` | `C473D86C4FBD1E0703CA2D977A5BA715A25FC8C2903900DCD095B3E0F5D2D619` | `40094 / 185` | `91/92`, complete class/global/physical topology, generated contract, retained caveats |
| `auto-generated/NexusTK/ui/panels/IconsPane.cpp` | `7DB1719BFC4D3576678AD0EDED20F27372AB19A3AE1EA2597515B2540A0C6F9B` | `8169 / 288` | Final command `000000025538`; nine method definitions, one topology comment, one definition, one physical marker, zero target-family empty markers |
| `auto-generated/NexusTK/ui/panels/IconsPane.h` | `6DDE538E9B2B552E70E67A037E086C87CFBDB344B16BB5793ACB6ECAC4A05980` | `905 / 33` | Final command `000000025538`; one complete class and exactly one extern |

Executed reports were evidence leads, not substitutes for current readback. Especially relevant were B002 UID0002SW constructor SHA `EEE36700D15BAFA18EB8C873C3E0BC2BB7AA63577AEFE08679AAA9363C35FD3D`, B014 UID0002SX ordinary destructor SHA `B191FE4858CA2215BA897599123B4EBF6E7FFC5A1FE0EFB972B5A11F7D7D89AE`, B001 UID00034V scalar wrapper SHA `8400D84E22D7F254EFC0AD6540067E7D815F33B6DC426CA724FAD44E30F0205A`, B003 UID00016Z class/source pass SHA `79F7D75F08C3D5E4784818AC5E52B907E7E0EB4D580F562345C86BE2BD99356C`, and B005 adjacent HourPane report SHA `7F7E52D6655C08B500EC41D500D5E955C3860589A4B2D2DA8F0EEBA06AC05014`.

The executed HourPane report is the strongest immediate comparator. Its semantic global emits `HourPane *g_pHourPane = NULL;` plus `[[CHILDREN]]`, its exact physical storage child emits a covered-by marker, its class H owns the extern, and direct Singleton lifecycle lowering excludes manual constructor/destructor assignments. UID0002XU has the same storage/source topology but two additional old-OptionPane consumers.

## Target

- Primary target UID: `0002XU`.
- Primary target path: `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md`.
- Address range: `[0x0069b41c,0x0069b420)`, size `4`.
- Entity: physical singleton-pointer storage for `g_pIconsPane`.
- Additional target UIDs: none.
- Support/dependency destinations only, receiving no report coverage: UID0000R6, UID00006B, UID0000JZ, UID0002SW, UID0002SX, UID00034V, UID0002SY, UID0002SZ, UID0002T0, UID0002QH, UID00040F, UID00040H, UID0001DO, UID0001PK, UID00029I, and UID00029J.
- Declared-target inventory: UID0002XU is the sole primary target and covers only the exact physical storage range.
- Source queue/report row: the dated tracker selection recorded UID0002XU with `0/0/0` direct/additional/total report coverage; exact report-header searches found no earlier direct or additional UID0002XU declaration.
- Current report-body allocation: `47` checked applied/already-present claims, `9` unchecked supervisor-owned proposed claims, and one terminal workflow-control marker.
- Current ordinary state: UID0002XU `92/94`, owner/emitter UID0000R6, reconstructable true, emitter position `10`, exact covered-by CPP, and blank H.
- Applied state: UID0002XU `92/94`, owner/emitter UID0000R6 and reconstructable true preserved, emitter position `10`, exact covered-by CPP, and blank H.

## Current Target State

Current live IDA does not have the meaningful name claimed by the ordinary page. `inspect_items` presents auto-name `unk_69B41C` at the first one-byte raw head, while the persisted names table has no entity at `0x0069b41c` and an exact `^g_pIconsPane$` collision search returns zero. The first head carries decompiler type `Pane *`; the remaining three byte heads have literal absent types. All four are code false/data false, and all address comment channels are absent.

The four bytes are `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. PE mapping resolves the historical `0xff` conflict: image RVA `0x29b41c` is `.data+0x2e41c`, beyond `.data` raw size `0xd800` but within virtual size `0x2fe24`. The loader therefore supplies zero-filled virtual storage; there are no raw file bytes at this RVA to support the old `0xff` claim.

Final dated command `000000025538` physically generated `IconsPane.cpp` SHA256 `7DB1719BFC4D3576678AD0EDED20F27372AB19A3AE1EA2597515B2540A0C6F9B`, `8169` bytes/`288` lines, with all nine exact method definitions, one class topology comment, one global definition, one physical covered-by marker, zero target-family empty markers, one empty human destructor body, and no authored singleton clear. Its `IconsPane.h` SHA256 is `6DDE538E9B2B552E70E67A037E086C87CFBDB344B16BB5793ACB6ECAC4A05980`, `905` bytes/`33` lines, with one complete class and exactly one extern.

## Executive Recommendation

The accepted ordinary callback applied and verified C001-C040 plus C050A-C051 across six by-* files. C050A-C050F are exact path-bound validator receipts and C051 is the completed dependent generated reread. Manual coverage C041-C045 and IDA C046-C049 remain supervisor-owned, proposed, and unchecked.

The global definition and covered-by child are not alternatives; together they are the nonduplicating aggregate route. The class emits only the comment while explicit `[[CHILDREN]]` aggregation retains all exact child method bodies. The one caller correction uses the already accepted public accessor and preserves the observed inverse checkbox value.

## Supervisor Active Recheck

The dated read-only MCP evidence used session `supervisor_uid0000n5_persistverify_20260817` against IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned status `ok`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready. `auto_analysis_ready:false` is recorded literally; bounded item/byte/xref/type/decompile endpoints nevertheless returned complete deterministic results.

That session identifier is dated evidence only. A supervisor must dynamically attest the then-current canonical session and reread all Section 21 prestates before any Gate 2B action. Current IDB, by-* and generated authority comes from supervisor gate-time readback, not this session label.

## Inference Research Guidance Check

The by-memory, by-global, by-class, and by-file guidance was applied:

- Physical by-memory ownership is limited to `[0x0069b41c,0x0069b420)` and may not absorb adjacent globals.
- Semantic global UID0000R6 is the canonical source declaration/definition owner.
- Class UID00006B is the complete header declaration owner and supplies type completeness before file children.
- File UID0000JZ owns `NexusTK/ui/panels/IconsPane.cpp/.h`.
- CPP and H are independent channels; a covered-by marker is valid source for a physical child whose authored definition is emitted by its semantic parent.
- The old `95/95` source gate is superseded. Evidence-supported first-draft source belongs in formal channels at lower scores.
- Numeric emitter positions are used only where order is source-significant.

## Heuristic / Inference Reanalysis And Validation

| Rank | Interpretation | Result |
| ---: | --- | --- |
| 1 | External `IconsPane *g_pIconsPane = NULL;` on semantic global, physical child covered-by | Accepted. Matches six cross-TU refs, class extern, file root, BSS state, and exact HourPane precedent. |
| 2 | External `IconsPane *g_pIconsPane;` without explicit initializer | Runtime-equivalent but rejected as less source-faithful than adjacent accepted singleton style and project convention. |
| 3 | Put the definition on physical UID0002XU | Rejected. It duplicates semantic ownership or forces the global parent to remain an empty emitter. |
| 4 | File-local `static IconsPane *` | Rejected. MapPane.cpp and OptionPane.cpp consume the same storage. |
| 5 | Class static member | Rejected. Existing sole extern and free-global consumer syntax prove a namespace-scope object. |
| 6 | Manual `g_pIconsPane = this/NULL` in derived constructor/destructor | Rejected. Direct `Singleton<IconsPane>` PMD/EBO and empty current human destructor account for publication/clear. |
| 7 | Create a flat IDA `IconsPane` UDT and set exact source pointer type | Rejected. No current `IconsPane` or `Singleton<IconsPane>` UDT exists, and a flat UDT would erase direct-base/EBO semantics. |
| 8 | Keep CPP blank below a score gate | Rejected. Source placement, type, linkage, initialization, and consumers are resolved. |

The source-facing pointer type is `IconsPane *`; the safe current IDA approximation remains `Pane *` until a separately accepted base-aware UDT model exists. Pointer signedness is not applicable; width is exactly one 32-bit native pointer. Endianness matters only to instruction operands and PE mapping; the zero initializer is endian-invariant.

## Evidence Standards Used

Claims use converging evidence: exact bytes and PE section mapping, item boundaries, complete xref sets, bounded decompilation/disassembly, function ranges and body hashes, RTTI/direct-base documentation, current formal channels, generated physical output, immediate adjacent precedent, and cross-translation-unit consumers.

Original symbol spelling is unavailable. `g_pIconsPane`, `IconsPane *`, `NULL`, and placement are source-level inferences supported by current project naming, the accepted class extern, and the exact g_pHourPane sibling. Confidence is therefore below certainty but high enough for source reconstruction.

## Evidence Checked

- Live read-only IDA MCP: health, items, bytes, comments, names, type inspection, inbound/outbound xrefs, decompilation, and bounded instruction bytes.
- Original PE `NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, size `2679296`; section mapping proved virtual-tail zero initialization.
- Target/global/class/file ordinary docs and their formal channels.
- Exact constructor, ordinary destructor, scalar wrapper, accessor, mutators, MapPane teardown, old OptionPane constructor, and old OptionPane command pages, with literal current IDA names/types kept distinct from accepted source-facing reconstruction identities.
- Adjacent WillBeChangedItemPane, HourPane, image-library error flag, and immediate g_pHourPane source topology.
- Current manual by-memory/by-global/by-class/by-file coverage rows.
- Dated pre-callback and final post-callback generated `IconsPane.cpp/.h`, including exact command provenance, hashes, class/extern shape, all nine method definitions, source order, and zero target-family empty markers.
- Tracker and report-header searches for direct/additional coverage.
- Executed source-quality reports listed in Supporting Research.

No reasonable evidence route remains unexamined for naming, type, linkage, initialization, ownership, source placement, ordering, lifecycle, consumers, boundaries, or generated output.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0002XU | The exact target is `[0x0069b41c,0x0069b420)`, one four-byte x86 pointer slot with bytes `00 00 00 00` and SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | Very high | MCP bytes/items and PE mapping | UID0002XU layout/evidence | incorporate | applied |
| C002 | 0002XU | The slot is in the `.data` zero-filled virtual tail, so the loader supplies zero and the old `0xff` observation is stale rather than raw-file truth. | Very high | `.data` VA/VS/raw mapping | UID0002XU history/reconstruction | historicalize | applied |
| C003 | 0002XU | Current IDA has four one-byte raw heads; the first is auto `unk_69B41C` with `Pane *`, the other types are absent, and all are code false/data false with absent comments. | Very high | inspect_items, names, comments | UID0002XU current IDA state | incorporate | applied |
| C004 | 0002XU | The head has exactly six inbound data xrefs and zero outbound xrefs; the three interior bytes have zero inbound/outbound xrefs. | Very high | xrefs_to/xref_query | UID0002XU xref inventory | incorporate | applied |
| C005 | 0002SW | Constructor `0x004cf1f0-0x004cf25d` publishes the adjusted complete object through direct `Singleton<IconsPane>` lowering, not authored assignment. | Very high | decompile/disasm/direct-base evidence | UID0002XU/UID0000R6 lifecycle | incorporate | applied |
| C006 | 0002SX | Ordinary destructor `0x004cf260-0x004cf289` has an empty human body; its clear is reverse direct-Singleton/base lowering. | Very high | exact body and current formal CPP | UID0000R6/UID00006B/UID0000JZ | reject-stale | applied |
| C007 | 00034V | Scalar wrapper `0x004cfda0-0x004cfdff` clears through compiler-generated teardown and must not emit a second destructor or global assignment. | Very high | wrapper body, vtable/delete mechanics | UID0002XU/global lifecycle | incorporate | applied |
| C008 | 0002QH | At `0x00504a07`, old-asset exit-to-menu teardown reads the slot and queues the pane at `0x00504a13`; it neither owns nor explicitly clears the global. | Very high | decompile/disasm | UID0002QH exact route | incorporate | applied |
| C009 | 00040F | Current IDA `sub_53D820` reads at `0x0053da72`, calls current IDA `sub_4CF290` at `0x0053da83`, inverts the result, and initializes control `6`; the accepted source identities are `OptionPane::OptionPane` and `IconsPane::IsShowingAllIcons`. | Very high | decompile and accessor body | UID00040F source/evidence | incorporate | applied |
| C010 | 00040H | Current IDA `sub_53DDB0` reads at `0x0053dec2` and routes control `6` to current IDA `sub_4CF2A0` or `sub_4CF2D0` while mirroring the config byte; the accepted source identities are `OptionPane::OnOptionCommand`, `IconsPane::ShowAllIcons`, and `IconsPane::ShowReducedIcons`. | Very high | decompile and mutator pages | UID00040H/UID0002XU evidence | incorporate | applied |
| C011 | 0002XU | Boundaries are exact: prior slots begin at `0x69b414` and `0x69b418`; successor flag begins at `0x69b420`; their xref counts are 5, 4, and 132. | Very high | item and xref queries | UID0002XU split rationale | incorporate | applied |
| C012 | 0000R6 | Source form is namespace-scope external `IconsPane *g_pIconsPane = NULL;`; pointer width is 32-bit and pointer signedness is not applicable. | High | extern, cross-TU uses, BSS, sibling precedent | UID0000R6 formal CPP | incorporate | applied |
| C013 | 0000R6 | UID0000R6 is the sole semantic definition owner and UID0000JZ is the sole source-file owner. | Very high | metadata and source graph | UID0002XU/global/file ownership | incorporate | applied |
| C014 | 0002XU | Physical UID0002XU emits only the exact covered-by CPP marker and no duplicate object. | Very high | hierarchy guidance and HourPane precedent | UID0002XU formal CPP | incorporate | applied |
| C015 | 0000R6 | Global CPP contains the definition followed by `[[CHILDREN]]`, so the physical marker is aggregated without a second definition. | Very high | generator hierarchy and precedent | UID0000R6 formal CPP | incorporate | applied |
| C016 | 00006B | The complete class H retains exactly one `extern IconsPane *g_pIconsPane;` declaration. | Very high | current class H/generated H | UID00006B formal H | already-present | already-present |
| C017 | 00006B | Class CPP emits a comment-only topology marker followed by explicit `[[CHILDREN]]`; exact child pages continue to own and emit all nine method definitions. | High | final no-loss class/generated routing | UID00006B formal CPP | incorporate | applied |
| C018 | 0000R6 | Global H remains blank because UID00006B already owns the sole extern. | Very high | current complete class H | UID0000R6 formal H | already-present | already-present |
| C019 | 0002XU | Target H remains blank because physical storage adds no declaration beyond the class-owned extern. | Very high | nonduplicate H topology | UID0002XU formal H | already-present | already-present |
| C020 | 0000JZ | Preserve class position `10`; set global position `30`; set target child position `10` under the global. | High | HourPane precedent and generated order | UID00006B/UID0000R6/UID0002XU metadata | incorporate | applied |
| C021 | 0002XU | Raise target metadata from `88/90` to `92/94`; preserve owner/emitter/reconstructable/range. | High | closed source and IDA questions | UID0002XU metadata | incorporate | applied |
| C022 | 0000R6 | Raise global metadata from `88/89` to `92/94`; preserve UID0000JZ ownership/emission. | High | sole definition/header/lifecycle closure | UID0000R6 metadata | incorporate | applied |
| C023 | 0000JZ | Raise file metadata from `90/91` to `91/92`; retained raw-dispatch naming/grouping caveats prevent a higher score. | High | complete file topology plus retained caveats | UID0000JZ metadata | incorporate | applied |
| C024 | 00006B | Keep class metadata `92/94`; the declaration is already complete and only CPP marker/stale prose need repair. | Very high | current class H/layout | UID00006B metadata | already-present | already-present |
| C025 | 0002XU | Replace stale saved-name, `0xff`, source-gate, placement, and score rationale text with current item/type/xref/BSS/formal-source evidence at full detail. | Very high | complete target recheck | UID0002XU body | incorporate | applied |
| C026 | 0000R6 | Add exact definition/linkage/order/current-IDB evidence and historicalize explicit derived-destructor-clear claims. | Very high | current formal/lifecycle evidence | UID0000R6 body | incorporate | applied |
| C027 | 00006B | Add class CPP topology and global definition route; correct every current claim that UID0002SX emits an explicit clear while preserving dated history. | Very high | current empty destructor and generated source | UID00006B body | incorporate | applied |
| C028 | 0000JZ | Add global/physical/class generated topology, scores, and expected tail; correct stale explicit-clear statements without losing history. | Very high | current file/generated/source evidence | UID0000JZ body | incorporate | applied |
| C029 | 0002QH | Add exact IconsPane teardown route mirroring the existing HourPane route, with old-assets branch, queue call, and no ownership/clear claim. | Very high | `0x504a07-0x504a13` | UID0002QH support prose | incorporate | applied |
| C030 | 00040F | Replace only `!g_pIconsPane->IsReducedIconMode()` with `!g_pIconsPane->IsShowingAllIcons()` in the complete formal constructor and explain the inverse control state. | Very high | accessor source and `setz` caller | UID00040F formal CPP/prose | reject-stale | applied |
| C031 | 00040H | Preserve current command-handler source/prose; its control-6 ShowAll/ShowReduced route is already correct. | Very high | current doc and live decompile | UID00040H | already-present | already-present |
| C032 | 0002SW | Preserve constructor/ordinary-destructor/scalar-wrapper formal bodies and compiler exclusions; no duplicate lifecycle source is added. | Very high | current exact child docs | UID0002SW/UID0002SX/UID00034V | already-present | already-present |
| C033 | 00029I | Preserve adjacent WillBeChangedItemPane, HourPane, and image-error children; no range, owner, source, or score change crosses target boundaries. | Very high | exact neighbor evidence | UID0001PK/UID00029I/UID00029J | already-present | already-present |
| C034 | 0000JZ | Dated pre-callback generated command `000000025458` ended with exactly three UID00006B/UID0000R6/UID0002XU empty markers and no global definition; final command `000000025538` superseded that state. | Very high | dated and final physical generated hashes | report/generated history | historicalize | applied |
| C035 | 0000JZ | Final command `000000025538` CPP readback has all nine method definitions, one class topology comment, one global definition, one physical covered-by marker, zero target-family empty markers, and no duplicate lifecycle body or authored clear. | Very high | final physical generated readback/hash | generated CPP contract | incorporate | applied |
| C036 | 0000JZ | Final command `000000025538` H readback has one complete IconsPane declaration and exactly one extern, with no global/target duplicate H emission. | Very high | final physical generated readback/hash | generated H contract | incorporate | applied |
| C037 | 0002XU | Historical `0xff` evidence remains dated but is explicitly superseded by PE virtual-tail mapping and current zero readback. | Very high | PE sections and MCP bytes | UID0002XU history | historicalize | applied |
| C038 | 0002XU | Source type is `IconsPane *`; IDA remains `Pane *` because no base-aware IconsPane UDT exists and a flat fake UDT is unsafe. | High | type_inspect and RTTI/class layout | UID0002XU type disposition | incorporate | applied |
| C039 | 0000R6 | Reject static, class-static, raw-address alias, duplicate physical definition, modern `nullptr`, and manual lifecycle assignments with explicit evidence. | High | linkage, compiler era, topology | UID0000R6 alternatives | incorporate | applied |
| C040 | 0002XU | Replace Item Summary and score rationale with exact zero-filled slot, six refs, covered-by route, and closed source placement. | Very high | target evidence | UID0002XU summary/scores | incorporate | applied |
| C041 | 0002XU | Replace the manual by-memory coverage row with the exact `92%` text in Section 28. | High | recommended target state | by-memory/-coverage-report.md | incorporate | proposed |
| C042 | 0000R6 | Replace the manual by-global coverage row with the exact `92%` text in Section 28. | High | recommended global state | by-global/-coverage-report.md | incorporate | proposed |
| C043 | 0000JZ | Replace the manual by-file coverage row with the exact `91%` text in Section 28. | High | recommended file state | by-file/-coverage-report.md | incorporate | proposed |
| C044 | 00006B | Preserve the exact current `92%` by-class manual row; its complete declaration description remains correct. | Very high | current manual row | by-class/-coverage-report.md | already-present | proposed |
| C045 | 00040F | Insert the exact constructor support row in Section 28 beneath UID0001DO; no current UID00040F manual row exists. | High | exact source-bearing child and manual search | by-memory/-coverage-report.md | incorporate | proposed |
| C046 | 0002XU | A01 atomically materializes one four-byte `Pane *` data item and meaningful `g_pIconsPane` name from the exact raw prestate. | High | deterministic make_data endpoint contract | Section 21 A01 | incorporate | proposed |
| C047 | 0002XU | A02 sets only the exact repeatable address comment after A01 and preserves every other field. | High | deterministic comment endpoint contract | Section 21 A02 | incorporate | proposed |
| C048 | 0002XU | P01 protects the `Pane *` IDA approximation and forbids a fabricated flat IconsPane UDT or unsupported exact-type mutation. | High | absent UDTs and EBO layout | Section 21 P01 | incorporate | proposed |
| C049 | 0002XU | P02A-P02M protect all 13 one-byte physical heads in predecessor `[0x69b414,0x69b41c)` and successor `[0x69b420,0x69b425)` with literal per-head ranges, widths, kinds, inspect/persisted names, types, bytes, AR/AP/FR/FP, complete inbound/outbound xrefs, permitted delta `none`, and exact unchanged poststates; F01-F06 separately protect the direct-target-xref functions at `0x004cf1f0`, `0x004cf260`, `0x004cfda0`, `0x005047f0`, `0x0053d820`, and `0x0053ddb0` by exact current IDA name/type/range/hash and no-delta poststate, outside the action table. | Very high | bounded function/neighbor inventory and dated read-only physical/xref reread | Section 21 P02A-P02M and F01-F06 | incorporate | proposed |
| C050A | 0002XU | From exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`, the exact target validator command completed as `000000025504` at `2026-08-17T14:33:03-04:00`, exit `0`/ok `1`, generated deferred; final target SHA256 is `9F7281ED1FCEFACF8FE0875A952A207EE724A29339F1364F60E077DC53AA9EA2`. | High | dated path-bound validator receipt | by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md | incorporate | applied |
| C050B | 0000R6 | From the same exact cwd, the exact semantic-global validator command completed as `000000025508` at `2026-08-17T14:35:48-04:00`, exit `0`/ok `1`, generated deferred; final global SHA256 is `F47866A1FAE8EAE91013274FD2AD9AE3FF3D7F9DECA2C5C172B6F0B57434603A`. | High | dated path-bound validator receipt | by-global/g_pIconsPane.md | incorporate | applied |
| C050C | 00006B | From the same exact cwd, the exact class validator command completed finally as `000000025537` at `2026-08-17T14:44:45-04:00`, exit `0`/ok `1`, generated deferred after the explicit no-loss `[[CHILDREN]]` correction; final class SHA256 is `EC588691B4E6AF7612E49A18EDB44A3C001FC352DCB4ABEDB3DE2B39B1B60438`. | High | dated path-bound validator receipt | by-class/IconsPane.md | incorporate | applied |
| C050D | 0002QH | From the same exact cwd, the exact teardown validator command completed as `000000025514` at `2026-08-17T14:40:14-04:00`, exit `0`/ok `1`, generated deferred; final teardown SHA256 is `88961DE4C60334F88AB80E6134D4E6CB0D4D4B27BAB1CF5C9CBF1A95999642C6`. | High | dated path-bound validator receipt | by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md | incorporate | applied |
| C050E | 00040F | From the same exact cwd, the exact old-constructor validator command completed as `000000025516` at `2026-08-17T14:41:05-04:00`, exit `0`/ok `1`, generated deferred; final constructor SHA256 is `5FEF1CC623287CA36AF5CC9E120EBBD5E181E7A1330722D6090673BA4BB4CD9F`. | High | dated path-bound validator receipt | by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md | incorporate | applied |
| C050F | 0000JZ | From the same exact cwd, after C050A-C050E, the exact final `--wait-generated` file validator command completed as `000000025538` at `2026-08-17T14:45:12-04:00`, exit `0`/ok `1`, generated completed; final file SHA256 is `C473D86C4FBD1E0703CA2D977A5BA715A25FC8C2903900DCD095B3E0F5D2D619`. | High | dated final coherent validator receipt | by-file/IconsPane.md | incorporate | applied |
| C051 | 0000JZ | After all six successful receipts, physical readback verified final CPP SHA256 `7DB1719BFC4D3576678AD0EDED20F27372AB19A3AE1EA2597515B2540A0C6F9B` (`8169` bytes/`288` lines) and H SHA256 `6DDE538E9B2B552E70E67A037E086C87CFBDB344B16BB5793ACB6ECAC4A05980` (`905` bytes/`33` lines) against the complete Section 23 contract. | Very high | command `000000025538` plus physical generated hashes/counts | Validator Results/generated readback | incorporate | applied |

## Positive Evidence Summary

- Four exact zero bytes in a loader-zeroed four-byte slot.
- Six and only six data xrefs, with no interior or outbound xrefs.
- Three lifecycle writes/clears agree with direct Singleton base lowering.
- Three runtime consumers agree on one active `IconsPane *`.
- Existing complete class H already declares the exact free global.
- Final generated C++ retains all nine exact IconsPane method definitions and now has the class/global/physical source topology with no target-family empty marker.
- The adjacent g_pHourPane source family provides an executed, byte-neighbor, same-pattern precedent.
- No competing name, owner, source file, or type family survived the bounded searches.

## IDA MCP Facts

| Entity | Literal current fact |
| --- | --- |
| Target items | Four raw one-byte heads: `0x69b41c` auto-name `unk_69B41C`, type `Pane *`; `0x69b41d-0x69b41f` names/types absent; each code false/data false |
| Target comments | AR absent, AP absent, FR absent because not a function entry, FP absent because not a function entry at every head |
| Target bytes | `00 00 00 00`; SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119` |
| Names | Persisted names in `[0x69b410,0x69b424]` are g_pMetaMan, g_pWillBeChangedItemPane, g_pHourPane, and g_imageLibraryLoadError; target has no persisted name; exact g_pIconsPane collision count `0` |
| Types | `IconsPane` absent; `Singleton<IconsPane>` absent; `Pane` exists as a 248-byte UDT with `_paneBase[248]` |
| Target xrefs | Code set/count `0/{}`; data set/count `6/{0x4cf215,0x4cf27a,0x4cfdc0,0x504a07,0x53da72,0x53dec2}`; outbound `0/{}` |
| Interior xrefs | Each of `0x69b41d`, `0x69b41e`, `0x69b41f`: inbound `0/{}`, outbound `0/{}` |
| Neighbor xrefs | `0x69b414`: 5; `0x69b418`: 4; `0x69b420`: 132 |
| Direct-target-xref current IDA functions | `0x004cf1f0` `IconsPane__IconsPane`, `int __thiscall(int this)`; `0x004cf260` `IconsPane__Destructor`, `void __thiscall(Pane *this)`; `0x004cfda0` `IconsPane__ScalarDeletingDestructor`, `Pane *__thiscall(Pane *Block, char)`; `0x005047f0` `sub_5047F0`, `char __thiscall(MapPane *this, char)`; `0x0053d820` `sub_53D820`, `int __thiscall(int this)`; `0x0053ddb0` `sub_53DDB0`, `void __userpurge(int a1@<ecx>, int a2@<ebx>, int a3, int a4)` |
| Accessor/mutator current IDA versus source | Current IDA `sub_4CF290`, `char __thiscall(_BYTE *this)` -> accepted source `IconsPane::IsShowingAllIcons`; current IDA `sub_4CF2A0`, `int __thiscall(_BYTE *this)` -> accepted source `IconsPane::ShowAllIcons`; current IDA `sub_4CF2D0`, `int __thiscall(_BYTE *this)` -> accepted source `IconsPane::ShowReducedIcons`. These are source-name evidence only; Section 21 proposes no IDA action for them. |

Constructor decompilation forms the Singleton subobject at `this+0xf8`, adjusts it back to the complete object, substitutes null on the invalid adjusted-null branch, and writes the result at `0x4cf215`. Ordinary and scalar teardown write zero after vtable restoration. Current IDA `sub_5047F0` reads and conditionally queues the object under accepted source identity `MapPane::ExitToMenu`. Current IDA `sub_53D820` and `sub_53DDB0` read, probe, invert, and toggle it under accepted source identities `OptionPane::OptionPane` and `OptionPane::OnOptionCommand`, exactly as described in C009-C010.

## Function / Child Inventory

| Range | Literal current IDA name | Literal current IDA type | Accepted source identity / disposition | Size | SHA256 | Target relationship |
| --- | --- | --- | --- | ---: | --- | --- |
| `0x004cf1f0-0x004cf25d` | `IconsPane__IconsPane` | `int __thiscall(int this)` | `IconsPane::IconsPane` | `0x6d` | `3E83899F79269A1D1143BC7EEDB2527F3B15C0F51D5FC7086E59B6EF491A5107` | Publishes target through implicit Singleton construction; preserve existing constructor source |
| `0x004cf260-0x004cf289` | `IconsPane__Destructor` | `void __thiscall(Pane *this)` | `IconsPane::~IconsPane` | `0x29` | `9A187A251F41270C820227A363BE415973A125F38336E09FC0C10826DE6AB952` | Clears target through implicit Singleton teardown; empty human destructor |
| `0x004cf290-0x004cf297` | `sub_4CF290` | `char __thiscall(_BYTE *this)` | `IconsPane::IsShowingAllIcons` | `0x7` | `E6D0C80B6814E3E16AC6F30079FCE867A28F08391122AA570630ADBE3029B8B2` | Returns `m_showAllIcons`; exact old OptionPane constructor callee; source-name evidence only |
| `0x004cf2a0-0x004cf2c6` | `sub_4CF2A0` | `int __thiscall(_BYTE *this)` | `IconsPane::ShowAllIcons` | `0x26` | `CF56D1A565193F0BC87EB5779E5978BEC23E5495F5AD4F5688C8EAF3F9D5797A` | Old OptionPane command full-mode callee; source-name evidence only |
| `0x004cf2d0-0x004cf2f6` | `sub_4CF2D0` | `int __thiscall(_BYTE *this)` | `IconsPane::ShowReducedIcons` | `0x26` | `3E55493FFF13A7C92CDE25559E6BF8F75B491A362D5E5F48C03706809269B103` | Old OptionPane command reduced-mode callee; source-name evidence only |
| `0x004cfda0-0x004cfdff` | `IconsPane__ScalarDeletingDestructor` | `Pane *__thiscall(Pane *Block, char)` | Compiler-generated scalar deleting wrapper; no authored source identity/body | `0x5f` | `CF5C1F45F503FB6B7FB6777214DA4575062D9940DCFC0E95F936A9083F542512` | Clears target through compiler teardown lowering |
| `0x005047f0-0x00504b6b` | `sub_5047F0` | `char __thiscall(MapPane *this, char)` | `MapPane::ExitToMenu(bool)` | `0x37b` | `B49987131F5E1EAC783D2B2041AC86CD0EC396B333C4D21B4790A7169F26ABB7` | External lifetime consumer; support prose only |
| `0x0053d820-0x0053dd4f` | `sub_53D820` | `int __thiscall(int this)` | `OptionPane::OptionPane` | `0x52f` | `DFEFBF60F778D7ECC034B2FD7B1882CD05C17017C03439DE5B8C3F16CCC24270` | Consumer; one formal source accessor-name correction |
| `0x0053ddb0-0x0053e191` | `sub_53DDB0` | `void __userpurge(int a1@<ecx>, int a2@<ebx>, int a3, int a4)` | `OptionPane::OnOptionCommand` | `0x3e1` | `2C35893AA527C2C7F8E5439215B1754F3838688D4F1A148D7B75AC4C6A992F9F` | Consumer; accepted source control-6 route already correct |

No function, code, padding, table, string, vtable, or standalone object lies inside `[0x0069b41c,0x0069b420)`. The target inventory is exhausted by one global pointer.

## Direct Xref / Caller Inventory

| Xref | Function range | Literal current IDA function/type | Accepted source identity | Instruction/use and exact meaning |
| --- | --- | --- | --- | --- |
| `0x004cf215` | `0x004cf1f0-0x004cf25d` | `IconsPane__IconsPane`; `int __thiscall(int this)` | `IconsPane::IconsPane` | `mov [0x69b41c], eax`; publish adjusted complete IconsPane pointer during direct Singleton base construction |
| `0x004cf27a` | `0x004cf260-0x004cf289` | `IconsPane__Destructor`; `void __thiscall(Pane *this)` | `IconsPane::~IconsPane` | `mov dword ptr [0x69b41c], 0`; clear during ordinary reverse base teardown |
| `0x004cfdc0` | `0x004cfda0-0x004cfdff` | `IconsPane__ScalarDeletingDestructor`; `Pane *__thiscall(Pane *Block, char)` | Compiler-generated scalar deleting wrapper; no authored source identity | `mov dword ptr [0x69b41c], 0`; clear in compiler scalar deleting path |
| `0x00504a07` | `0x005047f0-0x00504b6b` | `sub_5047F0`; `char __thiscall(MapPane *this, char)` | `MapPane::ExitToMenu(bool)` | load/test, queue at `0x00504a13`; old-assets exit-to-menu deferred deletion |
| `0x0053da72` | `0x0053d820-0x0053dd4f` | `sub_53D820`; `int __thiscall(int this)` | `OptionPane::OptionPane` | load, control `6`, call current IDA `sub_4CF290` at `0x0053da83`, invert; initialize reduced-icon option from inverse of source-facing `IconsPane::IsShowingAllIcons` |
| `0x0053dec2` | `0x0053ddb0-0x0053e191` | `sub_53DDB0`; `void __userpurge(int a1@<ecx>, int a2@<ebx>, int a3, int a4)` | `OptionPane::OnOptionCommand` | load then call current IDA `sub_4CF2D0` or `sub_4CF2A0`; apply source-facing `ShowReducedIcons`/`ShowAllIcons` behavior and mirror config |

All six are IDA data xrefs. There are no address-taken table entries, relocation routes, hidden interior refs, or target outbounds.

## Documentation Evidence And IDA Status

The dated pre-callback target/global docs preserved valuable xref and split history but were stale on current target-data IDA naming, raw-byte interpretation, source gate, and final placement. Class/file docs contained the decisive modern direct-Singleton and empty-human-destructor evidence while later paragraphs repeated an earlier explicit-clear incorporation. The callback historicalized those contradictions without deleting their dated evidence. Source-facing reconstruction names in ordinary docs are not current IDA identities unless a literal current-name row says so.

The old OptionPane constructor formal source called `IsReducedIconMode`, which the accepted accessor report explicitly rejects. The source-facing class H declares only `IsShowingAllIcons() const`. Current IDA still names that body `sub_4CF290` with type `char __thiscall(_BYTE *this)`; accepted source identity is `IconsPane::IsShowingAllIcons`. Current IDA likewise retains `sub_4CF2A0` / `sub_4CF2D0`, each `int __thiscall(_BYTE *this)`, while accepted source identities are `IconsPane::ShowAllIcons` / `IconsPane::ShowReducedIcons`. Caller bytes use `setz` after `sub_4CF290`, so the exact compileable and behavioral source correction is the inverse of `IsShowingAllIcons`.

IDA status is independently clear: meaningful target name absent, raw item boundary weak, safe Pane pointer approximation present, exact source UDT absent. Section 21 improves the data boundary/name/comment while refusing an unsafe fake UDT.

## Ranked Ownership Analysis

1. UID0000R6 semantic global: sole source definition owner.
2. UID0000JZ file root: sole `.cpp/.h` destination.
3. UID00006B class: sole complete class and extern declaration owner.
4. UID0002XU physical child: exact storage evidence and covered-by marker only.
5. UID0002SW/UID0002SX/UID00034V: lifecycle evidence, not global-definition owners.
6. UID0002QH/UID00040F/UID00040H: external consumers, not owners.
7. Adjacent singleton/data pages: hard split boundaries only.

No broad MainUiGraph, OptionPane, MapPane, TabPane, or compiler-data owner is supported for the definition.

## Source Placement

Final file root remains `NexusTK/ui/panels/IconsPane`.

CPP physical order after final command `000000025538`:

1. UID00006B at position `10`: comment-only topology output followed by explicit `[[CHILDREN]]` aggregation.
2. UID00006B children: compiler-covered UID0003BN vtable marker and all nine exact method definitions, including one empty human destructor.
3. UID0000R6 at position `30`: one definition, then its `[[CHILDREN]]`; UID0002XU at child position `10` supplies only the covered-by marker.
4. Retained direct file child UID00022Q follows as the existing file-local raw-dispatch helper.

H order:

1. UID00006B at position `10`: complete class and one extern.
2. No H payload from UID0000R6 or UID0002XU.

This route is compileable, nonduplicating, and generator-compatible.

## Range / Split / Padding / Reclassification Analysis

The target is exactly four bytes despite current one-byte raw items. Its six xrefs all target the logical head, instruction operands use address `0x69b41c`, and adjacent xref populations change sharply at `0x69b418` and `0x69b420`.

| Logical range | Role | Separation proof |
| --- | --- | --- |
| `[0x69b414,0x69b418)` | g_pWillBeChangedItemPane | Five distinct refs and different pointer type |
| `[0x69b418,0x69b41c)` | g_pHourPane | Four distinct refs and executed sibling source |
| `[0x69b41c,0x69b420)` | g_pIconsPane | Six exact refs and IconsPane lifecycle/consumers |
| `[0x69b420,0x69b424)` | image-library load error flag | Bool head and 132 refs |
| `0x69b424...` | ImageAnimationTable region | Different typed successor |

No padding is consumed. A01 reclassifies only the four target bytes into one data item. Any neighbor overlap is a hard stop.

## Negative Evidence Summary

- No persisted `g_pIconsPane` name and no destination-name collision.
- No `IconsPane` or `Singleton<IconsPane>` UDT in current IDA.
- No target interior or outbound xrefs.
- No raw-file bytes at the target RVA; old `0xff` cannot be a current file initializer.
- No evidence for `static`, class-static, TLS, array, integer, signed field, or multiword storage.
- No evidence for explicit derived-body lifecycle assignments.
- No second extern or global definition is needed.
- No H payload belongs on semantic or physical global pages.
- No separate source file or TabPane owner is supported.
- No accepted IDA action renames or retypes current `sub_4CF290`, `sub_4CF2A0`, or `sub_4CF2D0`; `IconsPane::IsShowingAllIcons`, `IconsPane::ShowAllIcons`, and `IconsPane::ShowReducedIcons` remain source-facing reconstruction identities only.
- No accepted IDA action changes the six direct-target-xref functions. Their literal current IDA names/types/ranges/hashes and exact unchanged poststates are independently protected by Section 21 F01-F06.
- No unresolved caller, boundary, source order, generated, score, or type-safety blocker remains.

## IDA Rename / Type / Comment Recommendations

These are inert supervisor handoff rows, not an operational package. The dated session ID is evidence only. A supervisor must attest a fresh canonical session, match each literal prestate, apply one stage, reread the complete endpoint, and stop before save on any mismatch.

### Direct-target-xref function no-delta contracts

These six rows are evidence/protection dependencies outside the A01/A02 action table. No endpoint, function rename, function type change, or source-name promotion is proposed. Each expected poststate is literal and independently mandatory after both A01 and A02.

| ID | Direct target data xref | Literal current IDA function contract | Exact expected unchanged poststate / hard stop |
| --- | --- | --- | --- |
| F01 | `0x004cf215` | name `IconsPane__IconsPane`; type `int __thiscall(int this)`; range `[0x004cf1f0,0x004cf25d)`; size `0x6d`; body SHA256 `3E83899F79269A1D1143BC7EEDB2527F3B15C0F51D5FC7086E59B6EF491A5107` | Name, type, range, size, hash, and direct target data xref `0x004cf215` remain exactly unchanged; permitted delta `none`. Any mismatch is a hard stop before save. |
| F02 | `0x004cf27a` | name `IconsPane__Destructor`; type `void __thiscall(Pane *this)`; range `[0x004cf260,0x004cf289)`; size `0x29`; body SHA256 `9A187A251F41270C820227A363BE415973A125F38336E09FC0C10826DE6AB952` | Name, type, range, size, hash, and direct target data xref `0x004cf27a` remain exactly unchanged; permitted delta `none`. Any mismatch is a hard stop before save. |
| F03 | `0x004cfdc0` | name `IconsPane__ScalarDeletingDestructor`; type `Pane *__thiscall(Pane *Block, char)`; range `[0x004cfda0,0x004cfdff)`; size `0x5f`; body SHA256 `CF5C1F45F503FB6B7FB6777214DA4575062D9940DCFC0E95F936A9083F542512` | Name, type, range, size, hash, and direct target data xref `0x004cfdc0` remain exactly unchanged; permitted delta `none`. Any mismatch is a hard stop before save. |
| F04 | `0x00504a07` | name `sub_5047F0`; type `char __thiscall(MapPane *this, char)`; range `[0x005047f0,0x00504b6b)`; size `0x37b`; primary-body SHA256 `B49987131F5E1EAC783D2B2041AC86CD0EC396B333C4D21B4790A7169F26ABB7` | Name, type, primary range, size, hash, and direct target data xref `0x00504a07` remain exactly unchanged; permitted delta `none`. Any mismatch is a hard stop before save. |
| F05 | `0x0053da72` | name `sub_53D820`; type `int __thiscall(int this)`; range `[0x0053d820,0x0053dd4f)`; size `0x52f`; body SHA256 `DFEFBF60F778D7ECC034B2FD7B1882CD05C17017C03439DE5B8C3F16CCC24270` | Name, type, range, size, hash, and direct target data xref `0x0053da72` remain exactly unchanged; permitted delta `none`. Any mismatch is a hard stop before save. |
| F06 | `0x0053dec2` | name `sub_53DDB0`; type `void __userpurge(int a1@<ecx>, int a2@<ebx>, int a3, int a4)`; range `[0x0053ddb0,0x0053e191)`; size `0x3e1`; body SHA256 `2C35893AA527C2C7F8E5439215B1754F3838688D4F1A148D7B75AC4C6A992F9F` | Name, type, range, size, hash, and direct target data xref `0x0053dec2` remain exactly unchanged; permitted delta `none`. Any mismatch is a hard stop before save. |

The accessor/mutator bodies are separately bounded source-name evidence, not Gate 2B action entities: `[0x004cf290,0x004cf297)` is current IDA `sub_4CF290`, type `char __thiscall(_BYTE *this)`, SHA256 `E6D0C80B6814E3E16AC6F30079FCE867A28F08391122AA570630ADBE3029B8B2`, accepted source `IconsPane::IsShowingAllIcons`; `[0x004cf2a0,0x004cf2c6)` is current IDA `sub_4CF2A0`, type `int __thiscall(_BYTE *this)`, SHA256 `CF56D1A565193F0BC87EB5779E5978BEC23E5495F5AD4F5688C8EAF3F9D5797A`, accepted source `IconsPane::ShowAllIcons`; `[0x004cf2d0,0x004cf2f6)` is current IDA `sub_4CF2D0`, type `int __thiscall(_BYTE *this)`, SHA256 `3E55493FFF13A7C92CDE25559E6BF8F75B491A362D5E5F48C03706809269B103`, accepted source `IconsPane::ShowReducedIcons`. No IDA delta is proposed for any of the three.

### A01 materialize, type, and name the data slot

- Classification/dependency: `apply`; first stage.
- Literal current prestate: logical range `[0x0069b41c,0x0069b420)`, size `4`, bytes `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. Four physical heads: `[0x69b41c,0x69b41d)` name `unk_69B41C`, type `Pane *`, data false/code false; `[0x69b41d,0x69b41e)`, `[0x69b41e,0x69b41f)`, and `[0x69b41f,0x69b420)` each name literal `absent`, type literal `absent`, data false/code false. At every head AR `absent`, AP `absent`, FR `absent` because not a function entry, FP `absent` because not a function entry. Head inbound code count/set `0/{}`; head inbound data count/set `6/{0x4cf215,0x4cf27a,0x4cfdc0,0x504a07,0x53da72,0x53dec2}`; each interior inbound `0/{}`; every target-head outbound `0/{}`. Exact persisted-name collision count for `g_pIconsPane` is `0`.
- Public endpoint/exact value: `make_data` with `database:"<fresh runtime-attested session ID>"` and `items:{addr:"0x0069b41c",delete_existing:true,type:"Pane * g_pIconsPane",name:"g_pIconsPane"}`.
- Owned fields: only the four target physical item classifications/boundary, target meaningful name, and preserved `Pane *` type.
- Expected immediate readback: one physical item `[0x0069b41c,0x0069b420)`, size `4`, name `g_pIconsPane`, type `Pane *`, data true/code false; bytes/hash exact; AR/AP/FR/FP all literal `absent`; head inbound code `0/{}`, data `6/{0x4cf215,0x4cf27a,0x4cfdc0,0x504a07,0x53da72,0x53dec2}`; outbound `0/{}`. No separate interior items remain because the one four-byte item owns the range.
- Protected fields/hard stops: preserve neighbor heads/types/xref counts at `0x69b414` WillBeChangedItemPane pointer/5, `0x69b418` HourPane pointer/4, `0x69b420` bool/132, and `0x69b424` ImageAnimationTable. Preserve direct target data xrefs `0x004cf215`, `0x004cf27a`, `0x004cfdc0`, `0x00504a07`, `0x0053da72`, and `0x0053dec2` plus every literal F01-F06 current IDA name/type/range/size/hash no-delta contract, comments, and bytes. Stop on any collision, size/type difference, xref delta, F01-F06 delta, neighbor overlap, byte change, or endpoint error.

### A02 set the repeatable address comment

- Classification/dependency: `apply`; requires exact A01 expected readback.
- Literal immediate prestate: one data item `[0x0069b41c,0x0069b420)`, size `4`, name `g_pIconsPane`, type `Pane *`, data true/code false; bytes `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code `0/{}`; inbound data `6/{0x4cf215,0x4cf27a,0x4cfdc0,0x504a07,0x53da72,0x53dec2}`; outbound `0/{}`; every P02A-P02M neighbor row and every F01-F06 direct-xref function current IDA name/type/range/size/hash contract is at its literal expected unchanged state.
- Public endpoint/exact value: `set_address_repeatable_comments` with `database:"<fresh runtime-attested session ID>"`, `items:{addr:"0x0069b41c",comment:"Loader-zeroed IconsPane singleton storage; source definition is IconsPane *g_pIconsPane = NULL; direct Singleton<IconsPane> lifecycle publishes/clears it; six data xrefs."}`.
- Owned field: AP only.
- Expected immediate readback: every A02 prestate field remains exact except AP becomes exactly `Loader-zeroed IconsPane singleton storage; source definition is IconsPane *g_pIconsPane = NULL; direct Singleton<IconsPane> lifecycle publishes/clears it; six data xrefs.` AR/FR/FP remain literal `absent`; xref sets/counts, bytes/hash, item, name, type, every P02A-P02M neighbor row, and every F01-F06 direct-xref function current IDA name/type/range/size/hash contract remain exactly unchanged.
- Protected fields/hard stops: any delta outside AP, including endpoint-created function comments, is a hard stop. Stop and discard unsaved work on any difference.

### Protection and no-operation rows

| ID | Classification | Literal current/expected unchanged state | Endpoint and hard stop |
| --- | --- | --- | --- |
| P01 | no change recommended | Source type is `IconsPane *`, but current IDA `IconsPane` and `Singleton<IconsPane>` types are literal absent. Current `Pane` exists as a 248-byte UDT with `_paneBase[248]`. After A01/A02 the target must remain `Pane *`; all other A02 poststate fields remain exact. | No endpoint. Do not call `set_type` for `IconsPane *`, create a flat UDT, add fake members, or alter direct-base/EBO presentation. Any such delta is a hard stop. |
| P02A | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b414`; half-open range `[0x0069b414,0x0069b415)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name `g_pWillBeChangedItemPane`; type `WillBeChangedItemPane *`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `5/{0x4c7939,0x4c7940,0x4c7b9a,0x4ce340,0x4ce690}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02B | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b415`; half-open range `[0x0069b415,0x0069b416)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02C | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b416`; half-open range `[0x0069b416,0x0069b417)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02D | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b417`; half-open range `[0x0069b417,0x0069b418)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02E | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b418`; half-open range `[0x0069b418,0x0069b419)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name `g_pHourPane`; type `HourPane *`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `4/{0x4cee85,0x4ceeca,0x4cf1b0,0x504a18}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02F | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b419`; half-open range `[0x0069b419,0x0069b41a)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02G | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b41a`; half-open range `[0x0069b41a,0x0069b41b)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02H | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b41b`; half-open range `[0x0069b41b,0x0069b41c)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02I | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b420`; half-open range `[0x0069b420,0x0069b421)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name `g_imageLibraryLoadError`; type `bool`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `132/{0x4d1a4e,0x4d2ba7,0x4d2bc4,0x4d2c62,0x4d2c79,0x4d2c8b,0x4d2ca2,0x4d2cb4,0x4d2ccb,0x4d2cdd,0x4d2cee,0x4d304c,0x4d3069,0x4d3122,0x4d3139,0x4d314b,0x4d3162,0x4d3174,0x4d3185,0x4d3234,0x4d3251,0x4d3302,0x4d3319,0x4d332b,0x4d3342,0x4d3354,0x4d3365,0x4d3407,0x4d3424,0x4d34e2,0x4d34f9,0x4d350b,0x4d3522,0x4d3534,0x4d354b,0x4d355d,0x4d356e,0x4d3634,0x4d3651,0x4d3712,0x4d3729,0x4d373b,0x4d3752,0x4d3764,0x4d377b,0x4d378d,0x4d379e,0x4d3862,0x4d387f,0x4d3934,0x4d394b,0x4d395d,0x4d3974,0x4d3986,0x4d399d,0x4d39af,0x4d39c0,0x4d3a7a,0x4d3a97,0x4d3b52,0x4d3b69,0x4d3b7b,0x4d3b92,0x4d3ba4,0x4d3bbb,0x4d3bcd,0x4d3bde,0x4d3c98,0x4d3cb5,0x4d3d72,0x4d3d89,0x4d3d9b,0x4d3db2,0x4d3dc4,0x4d3ddb,0x4d3ded,0x4d3dfe,0x4d3eb8,0x4d3ed5,0x4d3f92,0x4d3fa9,0x4d3fbb,0x4d3fd2,0x4d3fe4,0x4d3ffb,0x4d400d,0x4d401e,0x4d40de,0x4d40fb,0x4d4195,0x4d41ac,0x4d41be,0x4d41d5,0x4d41e7,0x4d41fe,0x4d4210,0x4d4227,0x4d4239,0x4d424a,0x4d5f93,0x4db3c0,0x4dcab0,0x4dd32e,0x4de1a0,0x4de887,0x4de89b,0x4de9b6,0x4de9c5,0x4dea4f,0x4dea5f,0x4deac7,0x4dead7,0x4dee60,0x4defd0,0x4e6b24,0x4e6b38,0x4e6baf,0x4e6bc3,0x4e6bd2,0x4e6be6,0x4e6bf5,0x4e6c06,0x4e6c92,0x4e6ca6,0x4e6d1c,0x4e6d30,0x4e6d3f,0x4e6d53,0x4e6d62,0x4e6d76,0x4e6d85,0x4e6d96}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02J | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b421`; half-open range `[0x0069b421,0x0069b422)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02K | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b422`; half-open range `[0x0069b422,0x0069b423)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02L | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b423`; half-open range `[0x0069b423,0x0069b424)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type literal `absent`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `0/{}`; outbound code count/set `0/{}`; outbound data count/set `0/{}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |
| P02M | no change recommended | Literal current prestate and exact expected unchanged poststate are identical: address `0x0069b424`; half-open range `[0x0069b424,0x0069b425)`; width `1`; kind one-byte raw head (`data false`, `code false`); inspect name literal `absent`; persisted name literal `absent`; type `ImageAnimationTable`; bytes `00`; AR `absent`; AP `absent`; FR `absent` because not a function entry; FP `absent` because not a function entry; inbound code count/set `0/{}`; inbound data count/set `4/{0x419fb0,0x4dacfe,0x4db33d,0x60c280}`; outbound code count/set `0/{}`; outbound data count/set `1/{0xff0000000000d8e2}`; permitted delta `none`. | No endpoint. Reread this exact row after A01/A02; any field, count, set, boundary, or byte delta is a hard stop. |

Ordered contract: verify F01-F06, apply A01, complete target/P02/F01-F06 readback, apply A02, complete target/P02/F01-F06 readback, then P01 and every P02A-P02M physical-item row plus all prior state reread before any save decision. The only permitted deltas are A01's target item/name/classification and A02's AP text; every F01-F06 and P02A-P02M permitted delta is `none`.

## First-Draft C++ Recommendation

### UID0002XU formal CPP

```cpp
// Emitted code for this range is covered by [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md).
```

UID0002XU formal H stays blank.

### UID0000R6 formal CPP

```cpp
IconsPane *g_pIconsPane = NULL;
[[CHILDREN]]
```

UID0000R6 formal H stays blank.

### UID00006B formal CPP

```cpp
// IconsPane declarations are emitted in IconsPane.h; exact child pages emit method definitions.
[[CHILDREN]]
```

### UID00006B formal H

```h
class PaneMouseEvent;

class IconsPane : public Pane, public Singleton<IconsPane>
{
public:
    IconsPane();
    virtual ~IconsPane();

    bool IsShowingAllIcons() const;
    void ShowAllIcons();
    void ShowReducedIcons();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();

private:
    int HitTestIcon(int y, int x);
    void SetIconHighlight(bool isPressed);

    bool m_showAllIcons;
    int m_selectedIconIndex;
    bool m_isPressed;
};

extern IconsPane *g_pIconsPane;
```

### UID00040F complete formal CPP with exact correction

```cpp
OptionPane::OptionPane()
    : DialogPane(L"Option", 3, true)
{
    m_serverOptionBytes[4] = g_pConfig->m_soundEffectsEnabled;

    LoadOptionDialogResources(g_pOptionPaneDlgOptEpd);
    CreateLegacyOptionControls();

    SetOptionChecked(2, !g_pSoundManager->IsMusicDisabled());
    SetOptionChecked(3, !g_pSoundManager->IsSoundEffectsDisabled());
    SetOptionChecked(6, !g_pIconsPane->IsShowingAllIcons());
    SetOptionChecked(8, g_pConfig->m_mapMovementStatusOption == 0);
    SetOptionChecked(9, g_pConfig->m_doubleClick == 0);
    SetOptionChecked(10, g_pConfig->m_shadow == 0);
    SetOptionChecked(11, g_pConfig->m_seeThrough == 0);
    SetOptionChecked(12, g_pConfig->m_sayWithEnter == 0);
    SetOptionChecked(13, g_pConfig->m_hearEmotions == 0);
    SetOptionChecked(14, g_pConfig->m_staticObjectTransparencyEnabled == 0);
    SetOptionChecked(15, g_pConfig->m_mapEffect == 0);

    AddLegacyOptionButtons();
    FinishDialogLayout();
    OptionPaneSendOptionPacket11B(0);
}
```

No other formal CPP/H body changes are supported.

## Final Recommendation

The dated accepted implementation produced exactly one authored global definition and one header extern. Direct Singleton lifecycle remains compiler-generated; the ordinary destructor stays empty. Final generated CPP retains all nine method bodies, replaces the three target-family empty markers with the class comment, global definition, and physical covered-by marker, and contains no nested definition, stub, placeholder, TODO, duplicate object, duplicate destructor, or explicit lifecycle assignment.

The OptionPane correction is required for compileability and behavior. `IsReducedIconMode` is neither declared nor accepted; using its negation also obscures the observed inverse. `!IsShowingAllIcons()` exactly matches the binary's `setz`.

## Recommended Target Doc Changes

For UID0002XU, the dated callback applied:

- Set completion/confidence `92/94` and emitter position `10`.
- Install the exact formal CPP marker and keep H blank.
- Replace current-IDB name with auto `unk_69B41C` plus absent persisted name.
- Record four raw byte heads, current Pane pointer approximation, zero bytes/hash, PE virtual-tail proof, all comments, and exact xrefs.
- Replace the historical byte ambiguity with dated supersession.
- Explain one source definition on UID0000R6 and no physical duplicate.
- Record implicit Singleton lifecycle, exact consumers, boundary counts, rejected alternatives, and score rationale.
- Preserve all valid split history and links.

## Recommended Support Doc Changes

- UID0000R6: applied `92/94`, position `30`, exact definition plus children; source/linkage/initialization/order evidence; current IDA name correction; stale explicit derived clear historicalized.
- UID00006B: preserved `92/94` and complete H; added exact CPP comment plus explicit children aggregation; corrected current explicit-clear/source-topology prose while retaining dated history.
- UID0000JZ: applied `91/92`; recorded class/global/physical order, one definition/extern, generated contract, and remaining score limits.
- UID0002QH: added the exact IconsPane teardown subsection analogous to the existing HourPane subsection.
- UID00040F: preserved all source except the exact accessor expression; added caller inversion evidence and kept `88/90`.
- UID00040H, UID0002SW, UID0002SX, UID00034V, UID0002SY, adjacent children, OptionPane class/file/aggregate: verified readback only; no content or score change.
- Manual coverage: apply only Section 28 exact rows under supervisor authority.

## Score And Metadata Recommendation

| UID | Pre-callback | Current | Metadata disposition |
| --- | --- | --- | --- |
| 0002XU | `88/90` | `92/94` | Owner/emitter UID0000R6 and reconstructable true preserved; position `10`; covered-by CPP |
| 0000R6 | `88/89` | `92/94` | Owner/emitter UID0000JZ preserved; position `30`; definition plus children |
| 00006B | `92/94` | `92/94` | Owner/emitter UID0000JZ and position `10` preserved; H preserved; CPP comment plus children aggregation added |
| 0000JZ | `90/91` | `91/92` | FILE owner/path preserved |
| 00040F | `88/90` | `88/90` | Owner/emitter UID00009V preserved; formal token correction only |

Scores stop below final certainty because original symbols and exact historical source formatting are unavailable, IDA lacks a base-aware class UDT, and the file retains independent raw-dispatch/grouping caveats. The accepted accessor/mutator and OptionPane/MapPane names are source-facing reconstruction identities, while the literal current IDA identities remain those in Sections 13-15 and 21; that distinction is a bounded symbol-recovery limit, not a source blocker.

## Open Questions With Attempted Resolution

| Question | Investigation | Resolution |
| --- | --- | --- |
| Were bytes zero or `0xff`? | Current MCP bytes plus PE section VA/VS/raw mapping | Loader-zeroed virtual tail; `0xff` is stale historical observation |
| Is the pointer `Pane *` or `IconsPane *`? | Lifecycle methods, class extern, consumers, type database | Source is `IconsPane *`; IDA safely remains `Pane *` |
| Explicit initializer? | BSS behavior, project convention, exact adjacent sibling | Use `= NULL`; uninitialized spelling rejected as less faithful |
| Which page emits the object? | Semantic/physical hierarchy and generated aggregation | Semantic global emits; physical page covered-by |
| Where is extern declared? | Current class H and generated H | Keep the sole class-owned extern |
| Are clears authored? | RTTI/direct Singleton, empty destructor source, wrapper semantics | No; all publication/clears are template/compiler lowering |
| Is Option constructor source valid? | Current IDA `sub_53D820` calls current IDA `sub_4CF290`; accessor body, source declaration, and caller inversion | Accepted source is `OptionPane::OptionPane` calling `!IconsPane::IsShowingAllIcons()`; neither source identity is asserted as the current IDA name |
| Are the three accessor/mutator source names current IDA names? | Fresh canonical names/types and bounded body hashes | No. Current IDA is `sub_4CF290` / `sub_4CF2A0` / `sub_4CF2D0`; accepted source is `IconsPane::IsShowingAllIcons` / `ShowAllIcons` / `ShowReducedIcons`; no IDA action is proposed for them |
| Which direct-xref function identities are protected? | Exact xref-containing ranges, current names/types, and body hashes | Section 21 F01-F06 protects `0x004cf1f0`, `0x004cf260`, `0x004cfda0`, `0x005047f0`, `0x0053d820`, and `0x0053ddb0` with permitted delta `none` |
| Can IDA use exact source type? | `type_inspect` and EBO layout | Not safely without separately accepted UDT work |
| Does source ordering remain uncertain? | Current emitter graph and HourPane precedent | Class `10`, global `30`, child `10` |

Unresolved items: none that affect this report's source, metadata, support, manual coverage, generated, or IDA recommendation contracts.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual coverage is supervisor-owned. Exact recommended rows are:

Replace UID0002XU in `by-memory/-coverage-report.md`:

>     - [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md) 0x0069b41c-0x0069b420 | global pointer | g_pIconsPane : reconstructable : 92% : very strong : Exact loader-zeroed four-byte IconsPane singleton slot with six complete lifecycle/teardown/option xrefs, implicit direct-Singleton publication and clearing, safe IDA boundary/name/comment plan, sole semantic-global definition, and covered-by physical source route.

Replace UID0000R6 in `by-global/-coverage-report.md`:

> - [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) : reconstructable : 92% : very strong : Sole external IconsPane singleton definition with NULL initialization, class-owned extern, direct Singleton lifecycle lowering, exact six-xref inventory, semantic-global/physical-child source aggregation, cross-file teardown/option consumers, and generated CPP/H contract.

Replace UID0000JZ in `by-file/-coverage-report.md`:

> - [UID:0000JZ][IconsPane](by-file/IconsPane.md) : reconstructable : 91% : very strong : Old-layout icon-strip source module with complete class/header and method source, sole g_pIconsPane definition/extern, deterministic class/global/physical-child order, implicit Singleton lifecycle, exact teardown/option consumers, generated output contract, and retained raw-dispatch/grouping caveats.

Preserve the current UID00006B row exactly:

> - [UID:00006B][IconsPane](by-class/IconsPane.md) : reconstructable : 92% : very strong : Complete Pane/Singleton IconsPane declaration with exact 0x104 EBO layout, inherited EventHandler/TimerHandler facets, constructor/destructor and virtual/helper inventory, source-generated RTTI/vtable causality, and formal H reconstruction.

Insert beneath UID0001DO and before its ignored alignment child in `by-memory/-coverage-report.md`:

>         - [UID:00040F][0x0053d820-0x0053dd4f.OptionPaneConstructor](by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md) 0x0053d820-0x0053dd4f | constructor | OptionPane::OptionPane : reconstructable : 88% : strong : Complete old OptionPane constructor source with exact dialog/control setup, audio/config initialization, corrected control-6 inverse of g_pIconsPane->IsShowingAllIcons(), and initial option-request packet.

The current UID0002QH coverage row remains accurate and needs no replacement. Tracker/auto coverage is validator-owned; no manual tracker text is proposed.

## Follow-Up Actions

1. Dated 2026-08-17 ordinary implementation, six scoped validation contracts, final coherent refresh, and physical CPP/H reread are complete and recorded in Sections 31-32.
2. Supervisor independently controls C041-C045 manual coverage state.
3. Supervisor Gate 2B dynamically attests current IDA and controls C046-C049, including A01/A02 exact prestates, all six F01-F06 direct-xref function no-delta contracts, P01 and every P02A-P02M literal no-delta poststate, and save decisions.
4. Report execution, lifecycle transitions, archive movement, and audit updates remain outside B002 scope and are authoritative only from current supervisor/validator-owned state.

## Confidence

Overall confidence: very high for range, bytes, loader state, xrefs, lifecycle, consumers, split, semantic/file ownership, nonduplicate CPP/H topology, and final generated readback; high for original source spelling and explicit `NULL` formatting.

The score floor is set by independent original-symbol/format uncertainty, not an uninvestigated blocker. Every source-relevant alternative has a documented acceptance or rejection.

## Validator Results

Dated pre-callback report-only research invoked no validator. The accepted callback ran every command below from exact working directory `E:\NTK\GhidraBridge\source-3\project-documentation`; command text is inline receipt evidence, not an executable fence.

| Claim | Exact single-line command | Command receipt | Command-specific warnings/errors and generated state | Relevant side effects | Final physical ordinary reread |
| --- | --- | --- | --- | --- | --- |
| C050A | `python .\tools\validator.py --mode file --file by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md --apply --queue-timeout 240` | `000000025504`; `2026-08-17T14:33:03-04:00`; exit `0`; ok `1` | Warnings/errors: none. Generated refresh deferred under the same command id/timestamp. | `autogen_registry_update:3`, `completion_update:1`, `confidence_update:1`, `projected_stats_update:1`, `reference_index_add:3`, `uid_link_update:1`. | SHA256 `9F7281ED1FCEFACF8FE0875A952A207EE724A29339F1364F60E077DC53AA9EA2`; `11753` bytes/`108` lines. |
| C050B | `python .\tools\validator.py --mode file --file by-global/g_pIconsPane.md --apply --queue-timeout 240` | `000000025508`; `2026-08-17T14:35:48-04:00`; exit `0`; ok `1` | Warnings/errors: none. Generated refresh deferred under the same command id/timestamp. | `autogen_registry_update:3`, `completion_update:1`, `confidence_update:1`, `projected_stats_update:1`, `reference_index_add:4`, `stats_rescore_recommended:1`, `stats_row_remove:1`. | SHA256 `F47866A1FAE8EAE91013274FD2AD9AE3FF3D7F9DECA2C5C172B6F0B57434603A`; `12010` bytes/`101` lines. |
| C050C | `python .\tools\validator.py --mode file --file by-class/IconsPane.md --apply --queue-timeout 240` | Final class receipt `000000025537`; `2026-08-17T14:44:45-04:00`; exit `0`; ok `1` | Warnings/errors: none. Generated refresh deferred under the same command id/timestamp. | `autogen_registry_update:1`, `projected_stats_update:1`, `stats_incremental_noop:1`. Earlier successful command `000000025512`, `2026-08-17T14:38:50-04:00`, was superseded after the generated no-loss readback required explicit class `[[CHILDREN]]`. | SHA256 `EC588691B4E6AF7612E49A18EDB44A3C001FC352DCB4ABEDB3DE2B39B1B60438`; `46196` bytes/`243` lines. |
| C050D | `python .\tools\validator.py --mode file --file by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md --apply --queue-timeout 240` | `000000025514`; `2026-08-17T14:40:14-04:00`; exit `0`; ok `1` | Warnings/errors: none. Generated refresh deferred under the same command id/timestamp. | `projected_stats_update:1`, `reference_index_add:1`, `stats_incremental_noop:1`. | SHA256 `88961DE4C60334F88AB80E6134D4E6CB0D4D4B27BAB1CF5C9CBF1A95999642C6`; `31462` bytes/`261` lines. |
| C050E | `python .\tools\validator.py --mode file --file by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md --apply --queue-timeout 240` | `000000025516`; `2026-08-17T14:41:05-04:00`; exit `0`; ok `1` | Warnings/errors: none. Generated refresh deferred under the same command id/timestamp. | `autogen_registry_update:1`, `projected_stats_update:1`, `stats_incremental_noop:1`. | SHA256 `5FEF1CC623287CA36AF5CC9E120EBBD5E181E7A1330722D6090673BA4BB4CD9F`; `8748` bytes/`104` lines. |
| C050F | `python .\tools\validator.py --mode file --file by-file/IconsPane.md --apply --queue-timeout 240 --wait-generated` | Final coherent receipt `000000025538`; `2026-08-17T14:45:12-04:00`; exit `0`; ok `1` | Errors: none. Unrelated project-wide diagnostics: `autogen_children_fallback_insert:6`, `autogen_children_marker_missing:73`, `autogen_emitter_has_no_code:59`, `autogen_header_children_marker_missing:2`, `autogen_header_emitter_has_no_code:1`, `autogen_header_noop:106`; generated refresh completed. | `autogen_cpp_update:2`, `autogen_header_metadata_refresh:160`, `autogen_registry_rebuild:1`, `generated_metadata_refresh:273`, `projected_stats_update:1`, `stats_incremental_noop:1`. The two CPP updates were validator-owned `SpecializedButtonPanes.cpp` metadata/content refresh and final `IconsPane.cpp`. | SHA256 `C473D86C4FBD1E0703CA2D977A5BA715A25FC8C2903900DCD095B3E0F5D2D619`; `40094` bytes/`185` lines. |

The first coherent wait command `000000025528`, timestamp `2026-08-17T14:42:47-04:00`, exited `0`/ok `1` but physical readback found `IconsPane.cpp` SHA256 `3F9F49163A7D419B5CC7CA88F72F18C6354D9C0051062E6604B9A2B4BB19485C`, `1673` bytes/`58` lines: the class comment had suppressed fallback child aggregation. B002 did not edit generated output. The class formal channel was repaired with explicit `[[CHILDREN]]`, C050C was revalidated under command `000000025537`, and final coherent command `000000025538` restored all nine exact method definitions.

C051 final physical generated reread after command `000000025538`:

| Generated file | Exact provenance | SHA256 / bytes / lines | Physical contract proof |
| --- | --- | --- | --- |
| `auto-generated/NexusTK/ui/panels/IconsPane.cpp` | header command `000000025538`; refreshed `2026-08-17T14:45:12-04:00`; foreground-generated-refresh | `7DB1719BFC4D3576678AD0EDED20F27372AB19A3AE1EA2597515B2540A0C6F9B` / `8169` / `288` | Nine exact method definitions; one class topology comment; one global definition; one physical marker; one empty human destructor definition; zero explicit clear inside it; zero nested global definitions, target-family empty markers, duplicate bodies/definitions, stubs, TODOs, or placeholders. |
| `auto-generated/NexusTK/ui/panels/IconsPane.h` | header command `000000025538`; refreshed `2026-08-17T14:45:12-04:00`; foreground-generated-refresh | `6DDE538E9B2B552E70E67A037E086C87CFBDB344B16BB5793ACB6ECAC4A05980` / `905` / `33` | One complete `IconsPane` class and exactly one `extern IconsPane *g_pIconsPane;`; no global/physical duplicate H payload, stub, TODO, or placeholder. |

## Changed Files

The dated callback edited and validated exactly these six ordinary pages:

| Ordinary file | Final SHA256 | Sections/content changed |
| --- | --- | --- |
| `by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md` | `9F7281ED1FCEFACF8FE0875A952A207EE724A29339F1364F60E077DC53AA9EA2` | Metadata/formal CPP; Item Summary; status/layout/IDA/bytes/xrefs/source ownership/order/history/scores/changes |
| `by-global/g_pIconsPane.md` | `F47866A1FAE8EAE91013274FD2AD9AE3FF3D7F9DECA2C5C172B6F0B57434603A` | Metadata/formal CPP; status/evidence/lifecycle/source order/rejected alternatives/history/changes |
| `by-class/IconsPane.md` | `EC588691B4E6AF7612E49A18EDB44A3C001FC352DCB4ABEDB3DE2B39B1B60438` | Formal CPP comment plus children aggregation; current source topology/destructor disposition; dated history/changes; formal H preserved |
| `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | `88961DE4C60334F88AB80E6134D4E6CB0D4D4B27BAB1CF5C9CBF1A95999642C6` | Exact IconsPane teardown-consumer subsection and changes entry only |
| `by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md` | `5FEF1CC623287CA36AF5CC9E120EBBD5E181E7A1330722D6090673BA4BB4CD9F` | Exact formal accessor correction; caller polarity/control table/caveat/changes |
| `by-file/IconsPane.md` | `C473D86C4FBD1E0703CA2D977A5BA715A25FC8C2903900DCD095B3E0F5D2D619` | Metadata; status/scores/contents/source route/order/generated contract/history/changes |

This same report was reconciled with callback receipts, current hashes, generated proof, ledger/checklist states, and the terminal control marker. Generated files and validator-owned registry/tracker/automatic coverage metadata changed only through the authorized validator refresh; B002 did not hand-edit them. No manual `-coverage-report.md`, audit/catalog, IDA database, goal/notes, or lifecycle file was edited.

Dated lease fact: B002 held only short per-file leases for each ordinary edit/validator batch and released each immediately; the class lease was reacquired once for the explicit no-loss `[[CHILDREN]]` correction and released after command `000000025537`. Current lease state remains authoritative only from the leaser registry.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 0002XU | The exact target is `[0x0069b41c,0x0069b420)`, one four-byte x86 pointer slot with bytes `00 00 00 00` and SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. | Very high | MCP bytes/items and PE mapping | UID0002XU layout/evidence | incorporate | applied |
| [x] | C002 | 0002XU | The slot is in the `.data` zero-filled virtual tail, so the loader supplies zero and the old `0xff` observation is stale rather than raw-file truth. | Very high | `.data` VA/VS/raw mapping | UID0002XU history/reconstruction | historicalize | applied |
| [x] | C003 | 0002XU | Current IDA has four one-byte raw heads; the first is auto `unk_69B41C` with `Pane *`, the other types are absent, and all are code false/data false with absent comments. | Very high | inspect_items, names, comments | UID0002XU current IDA state | incorporate | applied |
| [x] | C004 | 0002XU | The head has exactly six inbound data xrefs and zero outbound xrefs; the three interior bytes have zero inbound/outbound xrefs. | Very high | xrefs_to/xref_query | UID0002XU xref inventory | incorporate | applied |
| [x] | C005 | 0002SW | Constructor `0x004cf1f0-0x004cf25d` publishes the adjusted complete object through direct `Singleton<IconsPane>` lowering, not authored assignment. | Very high | decompile/disasm/direct-base evidence | UID0002XU/UID0000R6 lifecycle | incorporate | applied |
| [x] | C006 | 0002SX | Ordinary destructor `0x004cf260-0x004cf289` has an empty human body; its clear is reverse direct-Singleton/base lowering. | Very high | exact body and current formal CPP | UID0000R6/UID00006B/UID0000JZ | reject-stale | applied |
| [x] | C007 | 00034V | Scalar wrapper `0x004cfda0-0x004cfdff` clears through compiler-generated teardown and must not emit a second destructor or global assignment. | Very high | wrapper body, vtable/delete mechanics | UID0002XU/global lifecycle | incorporate | applied |
| [x] | C008 | 0002QH | At `0x00504a07`, old-asset exit-to-menu teardown reads the slot and queues the pane at `0x00504a13`; it neither owns nor explicitly clears the global. | Very high | decompile/disasm | UID0002QH exact route | incorporate | applied |
| [x] | C009 | 00040F | Current IDA `sub_53D820` reads at `0x0053da72`, calls current IDA `sub_4CF290` at `0x0053da83`, inverts the result, and initializes control `6`; the accepted source identities are `OptionPane::OptionPane` and `IconsPane::IsShowingAllIcons`. | Very high | decompile and accessor body | UID00040F source/evidence | incorporate | applied |
| [x] | C010 | 00040H | Current IDA `sub_53DDB0` reads at `0x0053dec2` and routes control `6` to current IDA `sub_4CF2A0` or `sub_4CF2D0` while mirroring the config byte; the accepted source identities are `OptionPane::OnOptionCommand`, `IconsPane::ShowAllIcons`, and `IconsPane::ShowReducedIcons`. | Very high | decompile and mutator pages | UID00040H/UID0002XU evidence | incorporate | applied |
| [x] | C011 | 0002XU | Boundaries are exact: prior slots begin at `0x69b414` and `0x69b418`; successor flag begins at `0x69b420`; their xref counts are 5, 4, and 132. | Very high | item and xref queries | UID0002XU split rationale | incorporate | applied |
| [x] | C012 | 0000R6 | Source form is namespace-scope external `IconsPane *g_pIconsPane = NULL;`; pointer width is 32-bit and pointer signedness is not applicable. | High | extern, cross-TU uses, BSS, sibling precedent | UID0000R6 formal CPP | incorporate | applied |
| [x] | C013 | 0000R6 | UID0000R6 is the sole semantic definition owner and UID0000JZ is the sole source-file owner. | Very high | metadata and source graph | UID0002XU/global/file ownership | incorporate | applied |
| [x] | C014 | 0002XU | Physical UID0002XU emits only the exact covered-by CPP marker and no duplicate object. | Very high | hierarchy guidance and HourPane precedent | UID0002XU formal CPP | incorporate | applied |
| [x] | C015 | 0000R6 | Global CPP contains the definition followed by `[[CHILDREN]]`, so the physical marker is aggregated without a second definition. | Very high | generator hierarchy and precedent | UID0000R6 formal CPP | incorporate | applied |
| [x] | C016 | 00006B | The complete class H retains exactly one `extern IconsPane *g_pIconsPane;` declaration. | Very high | current class H/generated H | UID00006B formal H | already-present | already-present |
| [x] | C017 | 00006B | Class CPP emits a comment-only topology marker followed by explicit `[[CHILDREN]]`; exact child pages continue to own and emit all nine method definitions. | High | final no-loss class/generated routing | UID00006B formal CPP | incorporate | applied |
| [x] | C018 | 0000R6 | Global H remains blank because UID00006B already owns the sole extern. | Very high | current complete class H | UID0000R6 formal H | already-present | already-present |
| [x] | C019 | 0002XU | Target H remains blank because physical storage adds no declaration beyond the class-owned extern. | Very high | nonduplicate H topology | UID0002XU formal H | already-present | already-present |
| [x] | C020 | 0000JZ | Preserve class position `10`; set global position `30`; set target child position `10` under the global. | High | HourPane precedent and generated order | UID00006B/UID0000R6/UID0002XU metadata | incorporate | applied |
| [x] | C021 | 0002XU | Raise target metadata from `88/90` to `92/94`; preserve owner/emitter/reconstructable/range. | High | closed source and IDA questions | UID0002XU metadata | incorporate | applied |
| [x] | C022 | 0000R6 | Raise global metadata from `88/89` to `92/94`; preserve UID0000JZ ownership/emission. | High | sole definition/header/lifecycle closure | UID0000R6 metadata | incorporate | applied |
| [x] | C023 | 0000JZ | Raise file metadata from `90/91` to `91/92`; retained raw-dispatch naming/grouping caveats prevent a higher score. | High | complete file topology plus retained caveats | UID0000JZ metadata | incorporate | applied |
| [x] | C024 | 00006B | Keep class metadata `92/94`; the declaration is already complete and only CPP marker/stale prose need repair. | Very high | current class H/layout | UID00006B metadata | already-present | already-present |
| [x] | C025 | 0002XU | Replace stale saved-name, `0xff`, source-gate, placement, and score rationale text with current item/type/xref/BSS/formal-source evidence at full detail. | Very high | complete target recheck | UID0002XU body | incorporate | applied |
| [x] | C026 | 0000R6 | Add exact definition/linkage/order/current-IDB evidence and historicalize explicit derived-destructor-clear claims. | Very high | current formal/lifecycle evidence | UID0000R6 body | incorporate | applied |
| [x] | C027 | 00006B | Add class CPP topology and global definition route; correct every current claim that UID0002SX emits an explicit clear while preserving dated history. | Very high | current empty destructor and generated source | UID00006B body | incorporate | applied |
| [x] | C028 | 0000JZ | Add global/physical/class generated topology, scores, and expected tail; correct stale explicit-clear statements without losing history. | Very high | current file/generated/source evidence | UID0000JZ body | incorporate | applied |
| [x] | C029 | 0002QH | Add exact IconsPane teardown route mirroring the existing HourPane route, with old-assets branch, queue call, and no ownership/clear claim. | Very high | `0x504a07-0x504a13` | UID0002QH support prose | incorporate | applied |
| [x] | C030 | 00040F | Replace only `!g_pIconsPane->IsReducedIconMode()` with `!g_pIconsPane->IsShowingAllIcons()` in the complete formal constructor and explain the inverse control state. | Very high | accessor source and `setz` caller | UID00040F formal CPP/prose | reject-stale | applied |
| [x] | C031 | 00040H | Preserve current command-handler source/prose; its control-6 ShowAll/ShowReduced route is already correct. | Very high | current doc and live decompile | UID00040H | already-present | already-present |
| [x] | C032 | 0002SW | Preserve constructor/ordinary-destructor/scalar-wrapper formal bodies and compiler exclusions; no duplicate lifecycle source is added. | Very high | current exact child docs | UID0002SW/UID0002SX/UID00034V | already-present | already-present |
| [x] | C033 | 00029I | Preserve adjacent WillBeChangedItemPane, HourPane, and image-error children; no range, owner, source, or score change crosses target boundaries. | Very high | exact neighbor evidence | UID0001PK/UID00029I/UID00029J | already-present | already-present |
| [x] | C034 | 0000JZ | Dated pre-callback generated command `000000025458` ended with exactly three UID00006B/UID0000R6/UID0002XU empty markers and no global definition; final command `000000025538` superseded that state. | Very high | dated and final physical generated hashes | report/generated history | historicalize | applied |
| [x] | C035 | 0000JZ | Final command `000000025538` CPP readback has all nine method definitions, one class topology comment, one global definition, one physical covered-by marker, zero target-family empty markers, and no duplicate lifecycle body or authored clear. | Very high | final physical generated readback/hash | generated CPP contract | incorporate | applied |
| [x] | C036 | 0000JZ | Final command `000000025538` H readback has one complete IconsPane declaration and exactly one extern, with no global/target duplicate H emission. | Very high | final physical generated readback/hash | generated H contract | incorporate | applied |
| [x] | C037 | 0002XU | Historical `0xff` evidence remains dated but is explicitly superseded by PE virtual-tail mapping and current zero readback. | Very high | PE sections and MCP bytes | UID0002XU history | historicalize | applied |
| [x] | C038 | 0002XU | Source type is `IconsPane *`; IDA remains `Pane *` because no base-aware IconsPane UDT exists and a flat fake UDT is unsafe. | High | type_inspect and RTTI/class layout | UID0002XU type disposition | incorporate | applied |
| [x] | C039 | 0000R6 | Reject static, class-static, raw-address alias, duplicate physical definition, modern `nullptr`, and manual lifecycle assignments with explicit evidence. | High | linkage, compiler era, topology | UID0000R6 alternatives | incorporate | applied |
| [x] | C040 | 0002XU | Replace Item Summary and score rationale with exact zero-filled slot, six refs, covered-by route, and closed source placement. | Very high | target evidence | UID0002XU summary/scores | incorporate | applied |
| [ ] | C041 | 0002XU | Replace the manual by-memory coverage row with the exact `92%` text in Section 28. | High | recommended target state | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C042 | 0000R6 | Replace the manual by-global coverage row with the exact `92%` text in Section 28. | High | recommended global state | by-global/-coverage-report.md | incorporate | proposed |
| [ ] | C043 | 0000JZ | Replace the manual by-file coverage row with the exact `91%` text in Section 28. | High | recommended file state | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | C044 | 00006B | Preserve the exact current `92%` by-class manual row; its complete declaration description remains correct. | Very high | current manual row | by-class/-coverage-report.md | already-present | proposed |
| [ ] | C045 | 00040F | Insert the exact constructor support row in Section 28 beneath UID0001DO; no current UID00040F manual row exists. | High | exact source-bearing child and manual search | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C046 | 0002XU | A01 atomically materializes one four-byte `Pane *` data item and meaningful `g_pIconsPane` name from the exact raw prestate. | High | deterministic make_data endpoint contract | Section 21 A01 | incorporate | proposed |
| [ ] | C047 | 0002XU | A02 sets only the exact repeatable address comment after A01 and preserves every other field. | High | deterministic comment endpoint contract | Section 21 A02 | incorporate | proposed |
| [ ] | C048 | 0002XU | P01 protects the `Pane *` IDA approximation and forbids a fabricated flat IconsPane UDT or unsupported exact-type mutation. | High | absent UDTs and EBO layout | Section 21 P01 | incorporate | proposed |
| [ ] | C049 | 0002XU | P02A-P02M protect all 13 one-byte physical heads in predecessor `[0x69b414,0x69b41c)` and successor `[0x69b420,0x69b425)` with literal per-head ranges, widths, kinds, inspect/persisted names, types, bytes, AR/AP/FR/FP, complete inbound/outbound xrefs, permitted delta `none`, and exact unchanged poststates; F01-F06 separately protect the direct-target-xref functions at `0x004cf1f0`, `0x004cf260`, `0x004cfda0`, `0x005047f0`, `0x0053d820`, and `0x0053ddb0` by exact current IDA name/type/range/hash and no-delta poststate, outside the action table. | Very high | bounded function/neighbor inventory and dated read-only physical/xref reread | Section 21 P02A-P02M and F01-F06 | incorporate | proposed |
| [x] | C050A | 0002XU | From exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`, the exact target validator command completed as `000000025504` at `2026-08-17T14:33:03-04:00`, exit `0`/ok `1`, generated deferred; final target SHA256 is `9F7281ED1FCEFACF8FE0875A952A207EE724A29339F1364F60E077DC53AA9EA2`. | High | dated path-bound validator receipt | by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md | incorporate | applied |
| [x] | C050B | 0000R6 | From the same exact cwd, the exact semantic-global validator command completed as `000000025508` at `2026-08-17T14:35:48-04:00`, exit `0`/ok `1`, generated deferred; final global SHA256 is `F47866A1FAE8EAE91013274FD2AD9AE3FF3D7F9DECA2C5C172B6F0B57434603A`. | High | dated path-bound validator receipt | by-global/g_pIconsPane.md | incorporate | applied |
| [x] | C050C | 00006B | From the same exact cwd, the exact class validator command completed finally as `000000025537` at `2026-08-17T14:44:45-04:00`, exit `0`/ok `1`, generated deferred after the explicit no-loss `[[CHILDREN]]` correction; final class SHA256 is `EC588691B4E6AF7612E49A18EDB44A3C001FC352DCB4ABEDB3DE2B39B1B60438`. | High | dated path-bound validator receipt | by-class/IconsPane.md | incorporate | applied |
| [x] | C050D | 0002QH | From the same exact cwd, the exact teardown validator command completed as `000000025514` at `2026-08-17T14:40:14-04:00`, exit `0`/ok `1`, generated deferred; final teardown SHA256 is `88961DE4C60334F88AB80E6134D4E6CB0D4D4B27BAB1CF5C9CBF1A95999642C6`. | High | dated path-bound validator receipt | by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md | incorporate | applied |
| [x] | C050E | 00040F | From the same exact cwd, the exact old-constructor validator command completed as `000000025516` at `2026-08-17T14:41:05-04:00`, exit `0`/ok `1`, generated deferred; final constructor SHA256 is `5FEF1CC623287CA36AF5CC9E120EBBD5E181E7A1330722D6090673BA4BB4CD9F`. | High | dated path-bound validator receipt | by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md | incorporate | applied |
| [x] | C050F | 0000JZ | From the same exact cwd, after C050A-C050E, the exact final `--wait-generated` file validator command completed as `000000025538` at `2026-08-17T14:45:12-04:00`, exit `0`/ok `1`, generated completed; final file SHA256 is `C473D86C4FBD1E0703CA2D977A5BA715A25FC8C2903900DCD095B3E0F5D2D619`. | High | dated final coherent validator receipt | by-file/IconsPane.md | incorporate | applied |
| [x] | C051 | 0000JZ | After all six successful receipts, physical readback verified final CPP SHA256 `7DB1719BFC4D3576678AD0EDED20F27372AB19A3AE1EA2597515B2540A0C6F9B` (`8169` bytes/`288` lines) and H SHA256 `6DDE538E9B2B552E70E67A037E086C87CFBDB344B16BB5793ACB6ECAC4A05980` (`905` bytes/`33` lines) against the complete Section 23 contract. | Very high | command `000000025538` plus physical generated hashes/counts | Validator Results/generated readback | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000025555","destination_path":"executed-b-agent-research/B002/0002XU-g_pIconsPane-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002XU-g_pIconsPane-empty-emitter-source-quality.md","timestamp":"2026-08-17T15:42:29-04:00","uid":"0002XU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
