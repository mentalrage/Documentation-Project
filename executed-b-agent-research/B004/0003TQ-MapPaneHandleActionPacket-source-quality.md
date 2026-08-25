** TARGET-REPORT-UID:0003TQ **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003TQ MapPaneHandleActionPacket Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation: [UID:0003TQ] is `bool MapPane::HandleActionPacket(const unsigned char *packet)` at `92/94`, with retained owner/emitter [UID:00007Q], reconstructable true, blank optional position and `Nested:0`, a complete Item Summary, and Destination 1's exact source body.
- Final disposition: one source-authored MapPane opcode-`0x13` packet method, not a compiler wrapper, retained raw duplicate, mixed aggregate, ObjectList method, LivingObjectPane method, or overlay-class method.
- Source closure is complete: serial registration in ascending address order assigned UID0004SJ to `BowGaugeObjectPane::SetAnimationStartTick`, UID0004SK to `DamageNumberObjectPane` construction, UID0004SL to `UserPane::AdvanceMovementSendTick`, and UID0004SM to `UserPane::IsGroupMember`. All eight complete managed blocks and every accepted MapPane, UserPane, BowGauge, DamageNumber, aggregate, and padding synchronization are applied.
- Score and route: target `92/94`, owner/emitter UID00007Q, reconstructable true, blank position, `Nested:0`, source `NexusTK/map/MapPane.cpp`. The complete MapPane class already declares the method and remains `93/94`; the file remains `92/92`.
- Confidence: very strong for range, bytes, caller/opcode, packet offsets and promotions, EPF/legacy branch behavior, helper liveness, object/overlay ownership, exact unsafe behavior, source placement, and formal source. Stripped original lexemes and the inferred names of two private helpers cap confidence at 94.

## Supporting Research

- Historical executed B001 report `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md`, SHA256 `7F9C4CDB3572EC2C51451D450A168AE58EA658F10E8189469D705DC58C13DB55`, correctly split `[0x00512960,0x00512ca4)`, tied it to dispatcher opcode `0x13`, and identified the target's MapPane ownership, but left packet fields, helpers, score, and formal C++ unresolved. Those historical blank-C++ conclusions are superseded by this direct pass.
- Executed B004 UID0003TH report `executed-b-agent-research/B004/0003TH-MapPaneCreateHitBarObjectPaneEventOverlay-source-quality.md`, SHA256 `1A24EBF0A105324342D7C1A985806EB413D6FCE4F4BBC8AE6226AEE3A19019AA`, establishes the exact `CreateHitBarObjectPane` contract and the two target calls.
- Executed B004 UID0003TO report `executed-b-agent-research/B004/0003TO-MapPaneHandleObjectMoveEffectPacket-source-quality.md`, SHA256 `AC0096CBD7D6BD3EF3D7D8C8EF84F4124EE8A8A3135BB9E299D86F6A9C0D2D63`, establishes the exact nested packet consumer. Its body never reads packet byte zero, making the target's unseeded local byte exact and safe for the observed callee.
- Executed B009 report `executed-b-agent-research/B009/0000HJ-AttachedObjectPane-empty-emitter-family-source-quality.md`, SHA256 `2460A17316FF5C9BE8285EAD5EA265D4A3CF48930B8CE64C7B1E8F518961FE4C`, is a historical attached-overlay lead. Fresh target and constructor evidence below resolves the DamageNumber layout and constructor blockers it left open.
- The historical B002 UID0003TX coordination artifact `tools/leaser/Agents/Agent-B002/research/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md`, evidence-time SHA256 `ABC22C9A88DD10114FFBBEF80892E42B398FC4A23561F57D1FAD609BE0EA7314`, records the object-info portion of the union and remains a lead rather than the final shared-state anchor.
- Current stable coordination evidence is the validator-owned executed archive set: B001 UID0003TP `executed-b-agent-research/B001/0003TP-MapPaneHandleObjectWorldMapCreationPacket-source-quality.md`, SHA256 `089014A525DD1EE3A4E945D54768416F8082157802924116278EE5587AAA6C62`, 124,989 bytes/1,118 lines, execution command `13641`; B002 UID0003TS `executed-b-agent-research/B002/0003TS-MapPaneHandleAnimationSoundPacket-source-quality.md`, SHA256 `6C57AAEF2F4DBEBA621D2A1A9F7CDCBB6FF0D828A93ECFF3E70828A3B61973DF`, 108,182/1,394, execution command `13651`; and B003 UID0003TJ `executed-b-agent-research/B003/0003TJ-MapPaneRefreshStaticObjectTileRegion-source-quality.md`, SHA256 `155B28186C175388F332FB3FBC4E6808EB764468FB448425FC3FA02415AABA49`, 109,854/1,124, execution command `13652`. Their exact archive paths and validator-owned history footers are lifecycle authority. The shared ordinary/generated/manual union preserves their accepted additions together with all B004 UID0003TQ facts.
- Searches used exact terms `UID0003TQ`, `0003TQ`, `0x00512960`, `0x00512ca4`, `MapPaneHandleActionPacket`, `HandleActionPacket`, `sub_512960`, `opcode 0x13`, `DamageNumberObjectPane`, `0x00539230`, `sub_5ADBA0`, `sub_5A8FC0`, `sub_538D00`, `UserPane`, `BowGaugeObjectPane`, and `MapPanePacketHandlers`.
- Root outcomes: evidence-time `tools/leaser/Agents/**` produced goal/tracker/audit records and the historical incidental coordination artifacts, but no direct `TARGET-REPORT-UID:0003TQ`; current `executed-b-agent-research/**` contains the classified B001/B004/B009 leads plus the final executed B001 UID0003TP, B002 UID0003TS, and B003 UID0003TJ coordination artifacts above; project `archived/**` contains zero Markdown reports; `tools/leaser/Agents/Older-Research/**` contains three Markdown files and no direct match; `tools/leaser/Agents/SpecialReports/**` contains five Markdown files and no direct match. Wave2/Wave3 artifacts were ignored as stale authority.
- Live read-only MCP evidence was collected against NexusTK database `64c11373`. A fresh `idb_list` returned one active adopted worker, `server_health` returned `status:ok` with auto-analysis, Hex-Rays, and string cache ready, and bounded `lookup_funcs(0x00512960)` returned `sub_512960`, size `0x344`. These are evidence-collection-time facts, not a claim of indefinite session availability.

## Target

- Target UID: `0003TQ`.
- Target path: `by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md`.
- Historical B004 research/implementation-callback artifact path before supervisor lifecycle: `tools/leaser/Agents/Agent-B004/research/0003TQ-MapPaneHandleActionPacket-source-quality.md`. External validator history/current path is authoritative for later lifecycle state.
- Queue source: tracker command `000000013556`, `by-memory / Not-Covered Files - Reconstructable`.
- Historical pre-callback classification was `86/90`, owner/emitter UID00007Q, reconstructable true, blank optional position/formal/Item Summary, and `Nested:0`.
- Exact function: `[0x00512960,0x00512ca4)`, `0x344` / 836 bytes, one modeled function, 43 basic blocks, cyclomatic complexity 22, 290 instructions, no string references.
- Current implemented classification is `92/94`, with the same UID/owner/emitter/reconstructable/position/nesting, complete Destination 1 formal body, and complete Item Summary.

## Current Target State

- Current target SHA256 is `AE1685AA2255019B4B887CDBCF8594F03D98B86D4466D8F15C2B2D25D810BCDB`, 17,832 bytes, 242 lines. It is `92/94`, retains UID00007Q/true/blank position/`Nested:0`, contains Destination 1 exactly, and preserves complete exact, negative, historical, score, and compiler-exclusion evidence. Historical pre-callback SHA `D17912847FE3F399DA565C7C101EDFE065E42D1E287549BD6A56355E9D0F3898` was 7,154 bytes/87 lines with blank formal C++.
- Exact executable SHA256 is `3A07DE4DFA7B86255F45D54782F3D940E606FABBB8AF945120FD7540FE93AAF0`. First 16 bytes are `55 8B EC 6A FF 68 94 2D 60 00 64 A1 00 00 00 00`; last 16 bytes are `8B 4D F0 33 CD E8 91 4A 0B 00 8B E5 5D C2 04 00`.
- The complete MapPane class still contains `bool HandleActionPacket(const unsigned char *packet);` and closes before `[[CHILDREN]]`; its current SHA256 is `A076D4E350565BAD1EADF679A93E9E908CB0F321EAF11710B16FC580E7F1375C`, 178,762 bytes/985 lines. Current by-file MapPane SHA256 is `978C6CD6F6309E86007DD77D39788A1C063F998D16A060C0C55D2BBB479959A5`, 180,600/744; current UID0001AW SHA256 is `4241D9B3BA6432D9291DBE3686A13E2E89F2446BAE1797C06811767A83C57111`, 97,479/390. These separately accepted later deltas preserve the complete B001/B002/B003/B004/B005/B011 union, including UID0003TQ and UID0004SJ-UID0004SM, without changing B004's target declaration, score, route, or source body.
- Historical B004 waited command `000000013612`, timestamp `2026-07-16T01:18:34-04:00`, exit 0/ok 1, established the accepted callback. Current read-only generated epoch is validator command/header `000000013645`, refreshed `2026-07-16T03:09:31-04:00`, exit 0/ok 1. Current `MapPane.cpp` is SHA256 `B4D6F013338AC0B013C6100BE60036572537F44761C9A39C290F4F13AD419EA3`, 138,106 bytes/4,132 lines, with 80 total qualified MapPane definitions / 80 unique qualified names, of which 78 are non-constructor/destructor definitions. UID0003TQ occurs once at annotation/definition lines 3581/3582 with zero target marker; five MapPane Empty Emitter Markers remain only for unrelated UID0004DS/UID00037T/UID0003TN/UID0003TT/UID0001SO.
- The command-13645 epoch also has `UserPane.cpp` SHA256 `390FDEA85F3999182CC4781FE17511E8F39D8C33967D01A53861D257F3547CEE`, 91,175 bytes/2,723 lines; `BowGaugeObjectPane.cpp` SHA256 `99FD52CAFF19E0D75605D68F1745817EF4EF09DD4C2CD7ABCBFEBE39417E6087`, 2,205/49; and `AttachedObjectPane.cpp` SHA256 `1FEA2686B2D4EA2E112FC874943F321EC570612449A3875FCBACC6D630F2A491`, 10,901/288. UID0004SJ/UID0004SK/UID0004SL/UID0004SM each have one annotation and one definition in their owner file, with zero corresponding marker. Unrelated marker totals remain one in UserPane, three in BowGaugeObjectPane, and two in AttachedObjectPane.
- Current ordinary destination readback:

| B004 destination/support path | Current SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md` | `AE1685AA2255019B4B887CDBCF8594F03D98B86D4466D8F15C2B2D25D810BCDB` | 17,832 | 242 |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `4241D9B3BA6432D9291DBE3686A13E2E89F2446BAE1797C06811767A83C57111` | 97,479 | 390 |
| `by-class/MapPane.md` | `A076D4E350565BAD1EADF679A93E9E908CB0F321EAF11710B16FC580E7F1375C` | 178,762 | 985 |
| `by-file/MapPane.md` | `978C6CD6F6309E86007DD77D39788A1C063F998D16A060C0C55D2BBB479959A5` | 180,600 | 744 |
| `by-class/UserPane.md` | `CE6EADF292A480FEE13F3806C14D3A91C908ED475F5D31C8034A9BD5A910DF3D` | 84,725 | 618 |
| `by-file/UserPane.md` | `70856FF2053521D9C1CCDA194BFBC3BB662E8B2F63780CB10EE0994555A6898C` | 97,287 | 392 |
| `by-memory/0x005a2530-0x005b8395.UserPane.md` | `D7DBEE77DC7AF8BE74A11AB1FF07E7EF3C5328292E91F1292E142417EA4285FC` | 55,313 | 304 |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `B0BC01730F60290FD588BDE1BBB951451A1AA40AEF51D52CE4BB5B30A11657C7` | 137,565 | 590 |
| `by-class/BowGaugeObjectPane.md` | `D74E76A131108979941ED71A0BFDBA2BF6ABB6EA9D298B467C98219EB873FB04` | 17,753 | 138 |
| `by-file/BowGaugeObjectPane.md` | `2E90817487A8B484D1CE8715416F06D0AEFD1831B68D6CEA9B2E40A9E0703268` | 15,573 | 110 |
| `by-class/DamageNumberObjectPane.md` | `2F7E7EC7D804EF45FAE7EB3866BBBF290809FF470A5ECA23C29B445B76FE6328` | 17,803 | 151 |
| `by-file/AttachedObjectPane.md` | `7522EF91651938F2B8D7A2237FF9357671E35E0D0AC393A539A09994E979C8CE` | 53,462 | 248 |
| `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md` | `9CA8760C08438942B74E229FAC392C24871082322B86BE2DD211B2420A8C7D1C` | 21,612 | 122 |
| `by-memory/-ignored.md` | `BC3307AEADB436276C7AF9C83BCF52A049FFB7D0D03DDE6F393AB376A1EC42EA` | 1,046,468 | 5,121 |
| `by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md` | `49D86F96448F8A38C2E3BE95A17F7996016E07CC84CE3C5481381A643535C083` | 5,652 | 74 |
| `by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md` | `D21F2097555F89DD930C0224AB52862725CF86E1C6FE41AC4C5F8EF41081A52D` | 8,480 | 131 |
| `by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md` | `49381B23F0BE3CACF4071834AD579D2A5EBA4413A541EE16025A7D3A72D67095` | 6,197 | 84 |
| `by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md` | `9B945CFFCD60859A8CFEACDAF14F6CBEA2A14F9BE98F5E136C193FD7A6393E8E` | 6,132 | 85 |

- Direct managed-block comparison proves all eight B004 report formals remain byte-for-byte exact in their current destinations: Destination 1 SHA `C3283F1FBED5A52F974C1C6870247C323F95F47320D5C6C3F1870B70367F3E0E`; Destination 2 `047D63959460779BEF8F3A6816F2C7D2EBCD73534FE54C081072A95F816E11BA`; Destination 3 `0B068C8842D88880CEB4A47BC9CEDA0E05AF566B90345FA45CB5C56BA2E8CA9A`; Destination 4 `7129187421B09D16642405CEFD683B701D1C88971E1B82AA0F716EF31AC4C3A7`; Destination 5 `9CA63AC5520F13C56CF4B3EAF7D8A9F3CC5A9A862699FBA35881E7A4402E7600`; Destination 6 `E32DE11C9D6825F059BCC517F79141E40775764657DA2040DB930284137722EB`; Destination 7 `AB58D2A2EEB2AB2F649C2484238761571B3740CCF8BA6B80CA34A40DB21FCF14`; Destination 8 `89D05B8635BA873D95D24145B49CC20F40246B48E1580390ED62A28FF707F5A4`.
- During the implementation callback, B004 edited only the 18 accepted ordinary destinations and this same report under short leases. Supervisor commands `13613`/`13614`/`13615` are the historical B004 manual-coverage application epoch; later supervisor commands `13646`/`13647`/`13648` preserve those rows while adding the accepted B001/B002 union. This bounded current-union rebase changes only this report. Generated output, ordinary docs, manual coverage, tracker/audit/supervisor/validator/lifecycle/IDA state were not edited by B004, and B004 ran no report execution, probe, count, revalidation, move, archive, or lifecycle command.

## Executive Recommendation

- UID0003TQ now emits one exact source method through UID00007Q/UID0000L3; the sole dispatcher caller, receiver field, and method-call surface remain decisive MapPane ownership evidence.
- Serial registration assigned UID0004SJ `[0x00538d00,0x00538d10)`, UID0004SK `[0x00539230,0x0053935e)`, UID0004SL `[0x005a8fc0,0x005a8ff2)`, and UID0004SM `[0x005adba0,0x005adbdc)`. All temporary UID tokens are eliminated.
- Complete BowGaugeObjectPane and DamageNumberObjectPane declarations are installed, and the complete current UserPane declaration is rebased with only `IsGroupMember` and `AdvanceMovementSendTick` added. Unrelated class content and the full B001/B002/B003/B004/B005/B011 union are preserved.
- UID0001AW, UID0001DB, UID0001KL, and UID0001KM remain non-emitting indexes with inventory-only updates and no aggregate C++.
- All eight exact ignored padding rows are present, and the pre-existing target successor `[0x00512ca4,0x00512cb0)` remains unchanged.

## Supervisor Active Recheck

- The supervisor assigned this direct target because its historical blank-C++/no-final-helper state was an investigable blocker; exact-artifact Gate 1 accepted SHA `E014CC2AAD443C072060AA76E522E0755E0F8C284F101B4A58A09D776777ECD4` before this callback.
- The target required no split or rename. Four directly required out-of-target helper/constructor bodies are now exact registered children, closing the source graph.
- Every source-bearing dependency discovered by this pass has an exact managed destination. Compiler pool allocation, vptr stores, EH state, deleting destructors, adjustor thunks, RTTI/vtables, and padding remain excluded with explicit disposition.
- Historical callback coordination completed under short leases and validators. This report-only current-union rebase reread the final executed B001 UID0003TP, B002 UID0003TS, and B003 UID0003TJ artifacts; all 18 B004 destinations; command-13645 generated output; and commands-13646-13648 manual coverage, using no lease and no validator. Report validation/execution/archive/count status remains external supervisor/validator-owned and is neither asserted nor directed here.

## Inference Research Guidance Check

- The evidence ladder was applied in order: target bytes/decompilation/ABI, direct caller and callee graph, adjacent boundaries, current by-* contracts, generated output as a lead, historical reports as revalidated leads, then source-era naming inference.
- Existing names such as `byte_66DA97`, `sub_5ADBA0`, `sub_5A8FC0`, and `sub_538D00` were not retained merely because symbols are stripped. Their source roles are narrowed by global documentation, receiver offsets, caller sets, and downstream behavior.
- Direct IDA facts are stated as facts; current documentation and generated output are labeled documentation evidence; original lexical names and file factoring are labeled inference.
- Existing blank-C++ and "needs field/helper naming" statements are historical blockers, not authority. This pass resolves them rather than carrying them forward.
- Wave2/Wave3 references encountered in legacy prose were ignored as stale and supplied no accepted fact.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence class | Disposition |
| --- | --- | --- | --- |
| Target identity | `bool MapPane::HandleActionPacket(const unsigned char *packet)` | dispatcher opcode `0x13`, MapPane receiver, `retn 4`, bool returns | source-ready |
| Packet pointer | immutable trusted byte buffer | fixed-offset reads, no mutation, no packet object | exact source-safe type |
| EPF selector | `g_useEpfAssets == 1` | exact byte `0x0066da97`, current UID0000SW/UID0001OH docs, 366-consumer family | resolved global identity |
| Object id | BE32 unsigned at `+1` | `PacketBufferReadUInt32BE`, ObjectList lookup, object-id comparisons | exact |
| Action byte | plain `char` at `+5` | narrow-char helper and signed `< 0`; legacy subtraction preserves sign | exact behavior, source spelling inferred |
| Current value | `unsigned char` at `+6` | zero extension and unsigned `<=100` | exact |
| Damage amount | BE32 copied into `int` at `+7` | constructor argument and sign handling | exact bit-width/source role |
| Rich action code | `actionFlags & 0x1f`; display effect `143 - code` | byte mask and ShowDamageEffect call | exact |
| Nested descriptor flags | bit `0x20` selects 224, additional bit `0x40` selects 245 | exact branch/stores; low word tested/written | source `unsigned short` locals; dword stores are compiler widening |
| Rich overlay order | ShowDamageEffect, delete old DamageNumber, optional new DamageNumber, group/local HitBar policy, local negative-action tick, optional nested effect | exact control-flow and calls | exact |
| Damage style | HumanObject status zero -> style 1; nonzero -> style 0 | target branch at LivingObjectPane `+0x178` and constructor final byte | exact |
| Damage constructor | owner, map row, map column, signed amount, byte style | four callers, `retn 0x14`, base/field stores | exact source-ready child |
| Damage layout | style `+0x12c`, frame `+0x12d`, amount `+0x130`, positive `+0x134`, digit offset `+0x135`, text `[16]` `+0x136`, size `0x148` | constructor stores, pool size, render consumers | complete declaration |
| Group eligibility | local object, nonmember, or member while GroupBar disabled | exact duplicated helper calls and config byte | preserve duplicate call source expression |
| Membership helper | `bool UserPane::IsGroupMember(unsigned int) const` | signed count, 0x12c records, bool result, target-only callers | strongest private source name |
| Local negative-action helper | `void UserPane::AdvanceMovementSendTick()` | unique target call, +1000/clamp/Bow setter sequence | strongest behavioral name |
| Bow setter | `void BowGaugeObjectPane::SetAnimationStartTick(unsigned int)` | one store at `+0xf8`, sole caller, OnPaint tick consumer | exact role and type |
| Bow class | Pane-derived, timer facet, tick field at `+0xf8`, size `0xfc` | constructor/vtables/OnPaint/OnTimer/setter | complete declaration |
| Nested packet | 13-byte local with byte zero intentionally unseeded; BE32 id +1, BE16 descriptor +5, zeros +7/+9/+11 | exact stack addresses/writers and UID0003TO nonread of byte zero | exact unsafe source shape |
| Legacy branch | full signed action byte in `143-actionFlags`; discard BE32 damage; only HitBar | exact separate branch | source-ready |
| Return policy | true on every path | common and branch-local returns | exact; no error return invented |
| Safety policy | no packet/null/length/global/allocation/list/timer checks beyond observed gates | negative control-flow evidence | preserve unsafe behavior |
| Source placement | target MapPane.cpp; User helpers UserPane.cpp; Bow setter BowGaugeObjectPane.cpp; Damage constructor AttachedObjectPane.cpp | receiver/class/file families | source-ready |

- Rejected packet structs: no current canonical opcode-`0x13` record type covers both rich and legacy semantics; a local trusted byte pointer with named locals is more faithful than inventing a packed public type.
- Rejected unsigned action byte: it would not preserve the negative-action test or the legacy signed subtraction over the full domain.
- Rejected one-call membership simplification: caching the first helper result would be behavior-equivalent for the proven pure helper but would not reproduce the observed duplicated-call source shape. The formal preserves two short-circuit calls.
- Rejected nested packet zero-initialization: `{0}` would seed byte zero and change exact stack writes even though UID0003TO does not read it.
- Rejected defensive allocation/global checks: none exists in the binary and each would change failure behavior.
- Rejected monolithic aggregate emission: UID0001AW/UID0001DB/UID0001KL/UID0001KM are physical/source-family indexes; exact class/method pages own source.
- No investigable target blocker remains. Exact original helper lexemes remain unknowable from stripped symbols, but the selected names are behavior-specific, consistent with current project naming, and do not change source semantics.

## Evidence Standards Used

- Direct evidence: live IDA MCP decompilation, function boundaries, code bytes, basic-block metrics, caller/callee refs, global addresses, receiver offsets, stack writes, return cleanup, and adjacent padding.
- Corroborating evidence: current target/owner/file/class/global/layout/helper pages; exact UID0003TH/UID0003TO bodies; current generated C++; manual coverage rows; current report roots.
- Negative evidence: no second target caller, no pointer-table route, no string refs, no internal split seam, no alternate receiver, no packet checks, no byte-zero write, no UID0003TO byte-zero read, and no standalone source-file cluster.
- The evidence is strong enough for 92/94 because all behavior that affects output/state/control flow is direct. Confidence is not 100 because original private lexemes and original header factoring are stripped.

## Evidence Checked

- MCP: fresh `idb_list`; `server_health(database=64c11373)`; bounded `lookup_funcs(0x00512960)`; `get_bytes` at target and predecessor; decompilation of `0x00512960`, `0x00539230`, `0x005372d0`, `0x005adba0`, `0x005a8fc0`, and `0x00538d00`; prior bounded calls for hashes/function metrics/xrefs/callees/padding recorded in this report.
- Current docs: target; UID0001AW; UID00007Q/UID0000L3; UID0003TH/UID0003TO; UID0000FQ/UID0000P1/UID0001KL/UID0001KM/UID0004R9; UID000011/UID0000HU; UID00003F/UID0000HJ/UID0001DB; LivingObjectPane, ObjectPane, AttachedObjectPane, HitBarObjectPane, Config, TimerMgr, g_useEpfAssets/global storage, packet helpers, and `by-memory/-ignored.md`.
- Generated/read-only: `MapPane.cpp`, `UserPane.cpp`, `BowGaugeObjectPane.cpp`, `AttachedObjectPane.cpp`, research tracker, and current manual by-memory/by-class/by-file coverage reports. Direct `by-struct/-coverage-report.md` was checked and is absent; no by-struct manual row was required.
- Report search roots: current `tools/leaser/Agents/**`, central `executed-b-agent-research/**`, actual project `archived/**`, `Older-Research/**`, and `SpecialReports/**`, using the concrete terms listed in Supporting Research.
- Negative searches: no direct current report, no second target call, no target pointer/data xref, no hidden packet-byte-zero read, no source-emitting parent body, and no new standalone module evidence.
- Failed check: an initial `get_bytes` request used `address` instead of schema key `addr` and returned a parse diagnostic; the corrected bounded request returned real target and predecessor bytes. This was a client-schema correction, not an MCP outage.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3TQ-001 | Target is exact `[0x00512960,0x00512ca4)`, 836 bytes, hash `3A07...AF0`. | exact | MCP function/bytes/hash | UID0003TQ exact evidence; commands 13598/13612 | incorporate | applied |
| C3TQ-002 | Target is one source-authored MapPane method with opcode-0x13 dispatcher caller. | very strong | caller `0x0050837e`, receiver use | UID0003TQ and UID0001AW current prose | incorporate | applied |
| C3TQ-003 | Signature is `bool MapPane::HandleActionPacket(const unsigned char *)`. | very strong | `retn 4`, immutable reads, bool returns | UID0003TQ Destination 1; current command-13645 generated line 3582 | incorporate | applied |
| C3TQ-004 | `g_useEpfAssets == 1` selects rich behavior; other values select legacy. | exact | byte read/compare, UID0000SW/UID0001OH | UID0003TQ body/evidence | incorporate | applied |
| C3TQ-005 | Object id is BE32 unsigned at packet `+1`. | exact | parser call and ObjectList lookup | UID0003TQ body/evidence | incorporate | applied |
| C3TQ-006 | Action flags are plain signed `char` at `+5`. | very strong | narrow-char helper, sign test, legacy arithmetic | UID0003TQ body/evidence | incorporate | applied |
| C3TQ-007 | Current value is unsigned byte at `+6`; damage is BE32 signed-use `int` at `+7`. | exact | zero extension, <=100, ctor sign logic | UID0003TQ and UID0004SK | incorporate | applied |
| C3TQ-008 | Rich action display uses `143 - (actionFlags & 0x1f)`. | exact | mask/call | UID0003TQ generated body | incorporate | applied |
| C3TQ-009 | Bits 0x20/0x40 choose nested descriptor 224/245 through two low-word locals. | exact | branches/stores/word test | UID0003TQ generated body | incorporate | applied |
| C3TQ-010 | Null ObjectList or object lookup miss is a no-op success. | exact | CFG | UID0003TQ body/evidence | incorporate | applied |
| C3TQ-011 | Existing DamageNumber is deleted before the <=100 create gate. | exact | vtable deleting call/order | UID0003TQ and retained Living support | incorporate | applied |
| C3TQ-012 | HumanObject status creates DamageNumber style 1; other status creates style 0. | exact | branch and ctor args | UID0003TQ and UID0004SK | incorporate | applied |
| C3TQ-013 | DamageNumber create order is position, new, install, list add, timer500, update, bounds, invalidate. | exact | call sequence | UID0003TQ generated body | incorporate | applied |
| C3TQ-014 | Group/local HitBar eligibility preserves two IsGroupMember calls. | exact | short-circuit CFG | UID0003TQ plus UID0004SM | incorporate | applied |
| C3TQ-015 | Eligible old HitBar is deleted; <=100 calls UID0003TH with literal 100. | exact | two branches/calls | UID0003TQ; UID0003TH preserved unique | incorporate | applied |
| C3TQ-016 | Local negative action with visible name advances movement tick/Bow animation. | exact | triple condition and unique helper | UID0003TQ -> UID0004SL -> UID0004SJ | incorporate | applied |
| C3TQ-017 | Nested effect packet leaves byte zero unseeded and writes exact +1/+5/+7/+9/+11 fields. | exact | stack/write addresses; UID0003TO reads | UID0003TQ current command-13645 generated lines 3681-3688 | incorporate | applied |
| C3TQ-018 | Legacy branch discards BE32 damage and creates only HitBar. | exact | branch decompile | UID0003TQ generated legacy branch | incorporate | applied |
| C3TQ-019 | Legacy ShowDamageEffect uses full signed action byte. | exact | signed narrow local/subtraction | UID0003TQ generated legacy branch | incorporate | applied |
| C3TQ-020 | Every path returns true with no packet/length/global hardening. | exact | CFG/negative checks | UID0003TQ body/evidence | incorporate | applied |
| C3TQ-021 | Target becomes 92/94 with owner/emitter UID00007Q, true, blank position, Nested0. | very strong | resolved blockers/gates | UID0003TQ hash AE1685...BCDB; cmd 13598 | incorporate | applied |
| C3TQ-022 | MapPane class declaration already has exact target declaration and remains 93/94. | exact documentation | current managed block | historical cmd 13600; current full-union hash A076D4...375C preserves target declaration and all B001/B002/B003/B004/B005/B011 facts | already-present | already-present |
| C3TQ-023 | MapPane file remains 92/92 and gains target behavior/source-route prose only. | very strong | owner/source cluster | historical cmd 13601; current full-union hash 978C6C...59A5 preserves B004 route at same-or-greater detail | incorporate | applied |
| C3TQ-024 | UID0001AW stays false/non-emitting and adds source-ready target inventory. | exact documentation | split index policy | historical cmd 13599; current full-union hash 4241D9...7111 preserves target/support inventory and later accepted children | incorporate | applied |
| C3TQ-025 | `[0x0051295d,0x00512960)` is three CC bytes, hash `E668...CEE`. | exact | bounded bytes/hash | historical cmd 13611; current by-memory/-ignored.md hash BC3307...42EA retains every B004 padding row | incorporate | applied |
| C3TQ-026 | Existing `[0x00512ca4,0x00512cb0)` 12-CC padding remains unchanged. | exact | bytes/current ignored row | pre-existing row preserved in by-memory/-ignored.md | already-present | already-present |
| C3TQ-027 | New IsGroupMember child is exact `[0x005adba0,0x005adbdc)`, hash `E762...1C6A`. | exact | MCP decompile/bytes/xrefs | UID0004SM hash 9B945C...3E8E; cmd 13597 | incorporate | applied |
| C3TQ-028 | IsGroupMember uses signed count and 0x12c records, no clamp/checks. | exact | body/layout | UID0004SM and UID0000FQ Destination 6 | incorporate | applied |
| C3TQ-029 | New AdvanceMovementSendTick child is exact `[0x005a8fc0,0x005a8ff2)`, hash `2A84...6273`. | exact | MCP decompile/bytes/xrefs | UID0004SL hash 49381B...095; cmd 13596 | incorporate | applied |
| C3TQ-030 | Advance adds 1000, unsigned-clamps to current tick-1, and calls Bow setter. | exact | body | UID0004SL generated definition | incorporate | applied |
| C3TQ-031 | User class block is rebased completely and adds only two private declarations. | very strong | current formal plus helper bodies | UID0000FQ hash CE6EAD...F3D; cmd 13602 | incorporate | applied |
| C3TQ-032 | User file/aggregate indexes retain scores and add exact helper inventory/source route. | very strong | current source union | UID0000P1/UID0001KL/UID0001KM; cmds 13603-13605 | incorporate | applied |
| C3TQ-033 | New Bow setter child is `[0x00538d00,0x00538d10)`, hash `DC58...58`. | exact | MCP body/bytes/sole caller | UID0004SJ hash 49D86F...C083; cmd 13593 | incorporate | applied |
| C3TQ-034 | Bow setter writes unsigned tick at +0xf8 and source return is void. | very strong | store/caller ignores EAX/OnPaint consumer | UID0004SJ and UID000011 Destination 7 | incorporate | applied |
| C3TQ-035 | Bow class is Pane-derived with RemovePendingTimers, OnPaint, OnTimer, setter, one tick field, size0xfc. | very strong | ctor/vtables/methods/layout | UID000011 hash D74E76...FB04; cmd 13606 | incorporate | applied |
| C3TQ-036 | Bow class/file become 90/92 and 85/90; standalone ui/panels source wins. | strong | source cluster/resource/global/consumer evidence | UID000011/UID0000HU; cmds 13606/13607 | incorporate | applied |
| C3TQ-037 | New Damage constructor child is `[0x00539230,0x0053935e)`, hash `6F53...2420`. | exact | MCP body/bytes/four callers | UID0004SK hash D21F20...A52D; cmd 13594 | incorporate | applied |
| C3TQ-038 | Damage constructor signature/order/style/sign/text/timers are complete. | very strong | ABI/stores/calls | UID0004SK generated definition | incorporate | applied |
| C3TQ-039 | Damage class exact explicit fields end at +0x146 and implicit alignment yields size0x148. | very strong | stores/pool/render | UID00003F Destination 8 and size guard | incorporate | applied |
| C3TQ-040 | Damage class/file become 90/93 and 87/90 through AttachedObjectPane.cpp. | strong | class family/source root | UID00003F/UID0000HJ; cmds 13608/13609 | incorporate | applied |
| C3TQ-041 | UID0001DB remains 86/91 false/non-emitting and records exact children. | exact documentation | mixed-owner index | UID0001DB hash 9CA876...D1C; cmd 13610 | incorporate | applied |
| C3TQ-042 | Eight new exact padding intervals belong only in -ignored; no source body. | exact | bounded byte hashes | by-memory/-ignored.md; cmd 13611 | incorporate | applied |
| C3TQ-043 | Pool/EH/vptr/deleting/vtable/adjustor mechanics remain compiler-only. | very strong | ABI and current class/vtable docs | all accepted prose/generated negative scans | exclude-with-reason | excluded-with-reason |
| C3TQ-044 | Current g_useEpfAssets, Config, LivingObjectPane, ObjectList, TimerMgr, UID3TH/UID3TO support is verify-only. | exact documentation | current docs match binary | verify-only paths unchanged; generated UID3TH/UID3TO count 1 each | already-present | already-present |
| C3TQ-045 | Accepted manual by-memory/class/file replacements and insertions are present after supervisor application; B004 did not edit them. | exact documentation | current row readback plus historical B004 commands 13613/13614/13615 and current supervisor commands 13646/13647/13648 | current hashes 155030...2D93/9D42F8...A391/C2A5EC...BC17 preserve every B004 row at same-or-greater detail; no direct by-struct file/row required | incorporate | applied |
| C3TQ-046 | Callback must register children serially, replace every token, rebase shared B002/B003 union, validate each page, and run waited generated proof. | high process certainty | workflow/collision state | UID map 4SJ-4SM; historical commands 13593-13612; current archives 13641/13651/13652; generated 13645; manual 13646-13648; zero leases | incorporate | applied |

## Positive Evidence Summary

- The sole direct call is the opcode-`0x13` dispatcher edge at `0x0050837e`; the complete receiver is MapPane and the body uses `m_objectList` at `+0x424`.
- Packet reads, promotion widths, sign tests, action masks, helper calls, object fields, allocation arguments, and return paths converge without contradiction.
- UID0003TH and UID0003TO provide independently completed source contracts for the two outbound target paths.
- The two UserPane helpers have narrow complete bodies and direct target liveness; Bow setter has one target-derived caller and a matching OnPaint consumer; Damage constructor has four MapPane callers and complete field/timer/resource evidence.
- Current class/file routes already place MapPane, UserPane, BowGauge, and DamageNumber in coherent existing source modules. No new source file is needed.

## IDA MCP Facts

- Target `sub_512960`: `0x344` bytes, 43 blocks, complexity 22, 290 instructions, no strings, `retn 4`, hash `3A07DE4DFA7B86255F45D54782F3D940E606FABBB8AF945120FD7540FE93AAF0`.
- Target calls: `0x5754c0` BE32 reader, `0x575470` narrow-char conversion, `0x532370` ObjectList lookup, `0x53b200` ShowDamageEffect, `0x5374d0` GetMapPosition, `0x539230` DamageNumber constructor, `0x53ae80` Damage setter, `0x5314a0` ObjectList add, `0x597910` timer schedule, `0x4b8e00` GetBounds, `0x50edd0` UID0003TH, `0x511c90` UID0003TO, `0x5adba0`, and `0x5a8fc0`.
- `sub_5ADBA0`: `[0x005adba0,0x005adbdc)`, 60 bytes, six blocks, complexity 3, hash `E76201127A5720224741ED4B0106687265D009B6AB6E124CC63B4D5892223C6A`, only target calls.
- `sub_5A8FC0`: `[0x005a8fc0,0x005a8ff2)`, 50 bytes, hash `2A84A69FC7D222E3157C6A64DC9E8C460CF33A43D2B613CCAD278EA0D9B36273`, sole target caller and sole callee `0x00538d00`.
- `sub_538D00`: `[0x00538d00,0x00538d10)`, 16 bytes, hash `DC58908B6D24CBBB03AAF187E09E52B994604615699C660E2E0B123D46D31858`, stores argument at receiver `+0xf8`; sole caller `0x005a8fc0`.
- `sub_539230`: `[0x00539230,0x0053935e)`, 302 bytes, hash `6F536DA47AA93B32B46DE152F35CA785780F1C8CA3A37BDCC976939B4DA02420`; callers `0x0050ef7a`, `0x0050efa0`, `0x00512a9c`, `0x00512ac2`.
- Globals: `0x0066da97` is one-byte `g_useEpfAssets`; `0x0067a748` is current source-facing `g_pUserPane`; `0x0067a7c8` is `g_pConfig`; `0x0067ab80` is `g_pTimerMgr`; `0x0069ba24` is `g_pBowGaugeObjectPane`.
- Negative IDA facts: no alternate target caller/pointer/data route, no internal strings, no packet checks, no nested byte-zero write, no second owner receiver, and no target-internal code/data split.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x00512960,0x00512ca4)` | UID0003TQ | MapPane packet method | true | UID00007Q | `92/94` applied | complete formal |
| `[0x0051295d,0x00512960)` | UID0000VN / -ignored | target predecessor alignment | false | none | `100/strong` | insert ignored row |
| `[0x00512ca4,0x00512cb0)` | UID0000VN / -ignored | target successor alignment | false | none | `100/strong` | already present |
| `[0x00538d00,0x00538d10)` | UID0004SJ | BowGauge setter | true | UID000011 | `92/94` applied | registered exact child |
| `[0x00539230,0x0053935e)` | UID0004SK | DamageNumber constructor | true | UID00003F | `91/93` applied | registered exact child |
| `[0x005a8fc0,0x005a8ff2)` | UID0004SL | UserPane helper | true | UID0000FQ | `91/93` applied | registered exact child |
| `[0x005adba0,0x005adbdc)` | UID0004SM | UserPane query | true | UID0000FQ | `92/94` applied | registered exact child |
| `[0x0050e4c0,0x00514920)` | UID0001AW | MapPane packet index | false | UID00007Q | `86/90` unchanged | inventory update only |
| `[0x00538bc0,0x00539bb2)` | UID0001DB | mixed overlay index | false | none | `86/91` unchanged | inventory update only |
| `[0x005a2530,0x005b8395)` | UID0001KL | UserPane broad index | true/index | UID0000FQ | `91/93` unchanged | inventory update only |
| `[0x005a2de0,0x005ad441)` | UID0001KM | local-player extension index | false | none | `90/92` unchanged | Advance helper inventory only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0050837e` | dispatcher -> target | sole opcode-0x13 route and liveness proof |
| `0x00512a23` | target -> ObjectList lookup | object id is lookup key |
| `0x00512a41` | target -> ShowDamageEffect | rich low-five-bit action effect |
| `0x00512a9c/0x00512ac2` | target -> Damage ctor | Human/style branches |
| `0x00512ad7` | target -> UID0004QN | installs DamageNumber pointer |
| `0x00512b96` | target -> UID0003TH | rich HitBar create |
| `0x00512b42/0x00512b52` | target -> IsGroupMember | intentionally repeated query |
| `0x00512bb4` | target -> AdvanceMovementSendTick | local negative-visible branch |
| `0x00512c04` | target -> UID0003TO | nested descriptor packet reuse |
| `0x00512c7f` | target -> UID0003TH | legacy HitBar create |
| `0x0050ef7a/0x0050efa0` | retained MapPane helper -> Damage ctor | two non-target constructor callers |
| `0x005a8ff1` | Advance -> Bow setter | sole Bow setter caller |

## Documentation Evidence And IDA Status

- Historical pre-callback target documentation had correct split/owner/caller dependencies but stale blank-C++ and provisional-field conclusions; current target SHA `AE1685...BCDB` supersedes those statements with the complete implementation.
- UID00007Q is already a complete `93/94` class declaration with the exact target declaration. UID0000L3 is a prose-only `92/92` source root. UID0001AW is correctly false/non-emitting.
- UID0000FQ is a complete `93/94` class declaration with exact GroupMemberRecord layout, `m_groupMemberCount`, movement tick fields, `friend class MapPane`, and `[[CHILDREN]]`; it needs only the two private declarations in Destination 6.
- Historical pre-callback UID000011/UID00003F pages were blank at `86/88` and `86/90`; the implemented pages now contain complete declarations at `90/92` and `90/93`.
- Supervisor-owned commands `13613`/`13614`/`13615` remain the historical B004 manual-coverage application epoch. Current manual coverage was reread after supervisor commands `13646`/`13647`/`13648`, all exit 0/ok 1: by-memory SHA256 `15503038D5DF3CA5364A424E8AF4F83CC44196E748D27A33670F01B069BB2D93` (1,744,817 bytes/4,210 lines), by-class SHA256 `9D42F839A670E40D90CD834A0FE0F25A964ADF5BC2A12FDDF77AFB7AE6C2A391` (225,346/622), and by-file SHA256 `C2A5EC493F029B814FD600A31E49B08888FB13ABE14D4247822F220A4562BC17` (129,033/316). Current by-memory anchors are UID0001AW line 2278; B003 UID0003TJ line 2292; B001 UID0003TP line 2299; B004 predecessor/UID0003TQ/successor lines 2303-2305; B002 UID0003TS line 2307; UID0001DB line 2553; UID0004SJ line 2556; UID0004SK line 2558; UID0001KL/UID0001KM lines 3366-3367; UID0004SL line 3392; and UID0004SM line 3427. Accepted class rows remain Bow 63, Damage 148, MapPane 302, and UserPane 586; accepted file rows remain Attached 27, Bow 38, MapPane 156, and UserPane 297. Every B004 row is present at same-or-greater detail and no B004 manual delta remains. Direct `by-struct/-coverage-report.md` is absent and no by-struct manual row was required.
- Historical command 13588 had one target Empty Emitter Marker and no target definition; historical B004 command 13612 established the accepted implementation. Current read-only command/header `000000013645` preserves the exact target and all four real-UID child definitions once each with zero corresponding markers, while adding only separately accepted B001/B002/B003 union content; current generated hashes and semantic assertions are recorded under Current Target State and Validator Results.

## Ranked Ownership Analysis

### 1. MapPane / NexusTK/map/MapPane.cpp

- Evidence for: sole MapPane dispatcher caller, MapPane `this`, direct `m_objectList` use, existing class declaration, adjacent packet siblings, and exact UID0003TH/UID0003TO MapPane methods.
- Evidence against: none affecting ownership; constructed overlay classes own only their constructors/render/lifetime methods.
- Decision: canonical target owner/emitter UID00007Q, file UID0000L3.

### 2. UserPane, BowGaugeObjectPane, and DamageNumberObjectPane dependencies

- Evidence for: each owns the receiver/state of one newly required exact helper or constructor.
- Evidence against target ownership: none receives target `this` or owns opcode dispatch/ObjectList policy.
- Decision: exact support children only, in their existing source roots.

### 3. Rejected ObjectList, LivingObjectPane, Config, TimerMgr, packet-buffer, or new packet module

- Evidence for: each supplies a lookup, field, timer, global, or serialization dependency.
- Evidence against: no target receiver, dispatch route, source cluster, or complete policy ownership.
- Decision: dependencies only; no new by-file module and no target ownership transfer.

### Proposed new file/grouping, if applicable

- No new by-file/source root is applicable. Four new exact by-memory children route to existing class/file owners.
- BowGauge standalone `NexusTK/ui/panels/BowGaugeObjectPane.cpp` is now stronger than the private-UserPane companion alternative because the class has its own singleton, resources, vtables, constructor/destructor, paint/timer surface, and exact setter.
- DamageNumber remains in `NexusTK/map/AttachedObjectPane.cpp` beside HitBar/ObjectInfo; physical adjacency to BowGauge does not merge source ownership.

## Source Placement

- UID0003TQ definition: `NexusTK/map/MapPane.cpp`, emitted after complete UID00007Q class declaration and in address-ordered MapPane child position.
- IsGroupMember and AdvanceMovementSendTick: private `UserPane` methods in `NexusTK/ui/panels/UserPane.cpp` under UID0000FQ.
- Bow setter and class declaration: `NexusTK/ui/panels/BowGaugeObjectPane.cpp` under UID000011/UID0000HU.
- Damage constructor and class declaration: `NexusTK/map/AttachedObjectPane.cpp` under UID00003F/UID0000HJ.
- Rejected placements: packet-buffer utility, ObjectList.cpp, LivingObjectPane.cpp, TimerMgr.cpp, Config.cpp, one monolithic ObjectOverlayPanes.cpp, or a new ActionPacket.cpp.
- No third-party import directive is applicable.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and remains one child. Predecessor function ends `0x0051295d`; `[0x0051295d,0x00512960)` is three `0xcc` bytes, SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`.
- Existing target successor `[0x00512ca4,0x00512cb0)` is twelve `0xcc` bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`, and remains ignored.
- New Bow child is exact `[0x00538d00,0x00538d10)`; predecessor `[0x00538cfa,0x00538d00)` is six CC bytes, hash `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`.
- New Damage child is exact `[0x00539230,0x0053935e)`; predecessor `[0x0053922b,0x00539230)` is five CC bytes, hash `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`; successor `[0x0053935e,0x00539360)` is two CC bytes, hash `E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2`.
- New Advance child is exact `[0x005a8fc0,0x005a8ff2)`; predecessor `[0x005a8fb4,0x005a8fc0)` is twelve CC bytes, hash `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; successor `[0x005a8ff2,0x005a9000)` is fourteen CC bytes, hash `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- New membership child is exact `[0x005adba0,0x005adbdc)`; predecessor `[0x005adb97,0x005adba0)` is nine CC bytes, hash `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`; successor `[0x005adbdc,0x005adbe0)` is four CC bytes, hash `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`.
- Every new source child uses `Nested:0`; these are direct class methods, not children of preceding functions. Parent index nesting and current successor nesting remain unchanged.
- UID0001AW/UID0001DB/UID0001KL/UID0001KM remain indexes. No aggregate gains C++ or changes reconstructability.

## Negative Evidence Summary

- No second target caller, data pointer, vtable slot, or retained raw duplicate was found.
- No packet struct, length, null, allocation, ObjectList-result, timer-result, or global pointer guard exists; adding one is rejected.
- No write seeds nested packet byte zero; UID0003TO does not read byte zero. Zero-initializing the array is rejected.
- No evidence supports unsigned action flags over the full domain; signed `<0` and legacy subtraction reject it.
- No evidence supports caching membership result as original source shape; the exact binary has two calls on the member path.
- No evidence makes overlay constructors or UserPane/Bow helpers owners of the packet method.
- No evidence supports a raw vtable, pool call, deleting-destructor flag, explicit vptr store, EH state, or adjustor in handwritten source.
- No single owner spans UID0001DB; Bow HUD and attached map overlays remain separate source families.

## IDA Rename / Type / Comment Recommendations

- Optional source-facing IDA names after documentation acceptance: `MapPane::HandleActionPacket` at `0x00512960`, `UserPane::IsGroupMember` at `0x005adba0`, `UserPane::AdvanceMovementSendTick` at `0x005a8fc0`, `BowGaugeObjectPane::SetAnimationStartTick` at `0x00538d00`, and `DamageNumberObjectPane::DamageNumberObjectPane` at `0x00539230`.
- Recommended types are exactly the managed signatures below. Locals use `char actionFlags`, `unsigned char currentValue`, `int damageAmount`, `unsigned short nestedEffectTrigger`, and `unsigned short nestedEffectDescriptorId`.
- Suggested comments describe packet offsets/branch roles only in prose docs, not raw offsets or reverse-engineering narration inside formal C++.
- IDA mutation is not requested and was not performed.

## First-Draft C++ Recommendation

- Eligible: target and four new exact children are source-authored and clear the emitter gate. Three class destinations are required so those definitions have complete source declarations.
- Formal count: eight complete managed blocks. Every code line below is destination text, not an illustrative body.

### Destination 1 - UID0003TQ target

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MapPane::HandleActionPacket(const unsigned char *packet)
{
    if (g_useEpfAssets == 1)
    {
        const unsigned int objectId = PacketBufferReadUInt32BE(packet + 1);
        const char actionFlags = static_cast<char>(packet[5]);
        const unsigned char currentValue = packet[6];
        const int damageAmount =
            static_cast<int>(PacketBufferReadUInt32BE(packet + 7));
        const bool negativeAction = actionFlags < 0;

        unsigned short nestedEffectTrigger = 0;
        unsigned short nestedEffectDescriptorId = 0;
        if ((actionFlags & 0x20) != 0)
        {
            nestedEffectTrigger = 224;
            nestedEffectDescriptorId = 224;
            if ((actionFlags & 0x40) != 0)
            {
                nestedEffectTrigger = 245;
                nestedEffectDescriptorId = 245;
            }
        }

        if (m_objectList != NULL)
        {
            LivingObjectPane *objectPane =
                static_cast<LivingObjectPane *>(
                    m_objectList->FindByObjectId(objectId));
            if (objectPane != NULL)
            {
                objectPane->ShowDamageEffect(
                    143 - (actionFlags & 0x1f), 0);

                delete objectPane->m_damageNumberObjectPane;
                if (currentValue <= 100)
                {
                    MapPoint mapPosition;
                    objectPane->GetMapPosition(&mapPosition);

                    DamageNumberObjectPane *damageNumberObjectPane;
                    if (objectPane->m_objectStatus.m_statusKind ==
                        ObjectStatusBlob::HumanObject)
                    {
                        damageNumberObjectPane = new DamageNumberObjectPane(
                            objectPane,
                            mapPosition.row,
                            mapPosition.column,
                            damageAmount,
                            1);
                    }
                    else
                    {
                        damageNumberObjectPane = new DamageNumberObjectPane(
                            objectPane,
                            mapPosition.row,
                            mapPosition.column,
                            damageAmount,
                            0);
                    }

                    objectPane->SetDamageNumberObjectPane(
                        damageNumberObjectPane);
                    m_objectList->AddObjectPane(damageNumberObjectPane);
                    g_pTimerMgr->ScheduleTimer(
                        static_cast<TimerHandler *>(damageNumberObjectPane),
                        0,
                        500,
                        0,
                        0);
                    damageNumberObjectPane->UpdatePosition();

                    RectBounds bounds;
                    damageNumberObjectPane->GetBounds(&bounds);
                    damageNumberObjectPane->InvalidateRect(&bounds);
                }

                if (objectId == g_pUserPane->m_objectId ||
                    !g_pUserPane->IsGroupMember(objectId) ||
                    (g_pUserPane->IsGroupMember(objectId) == true &&
                     !g_pConfig->m_groupBarEnabled))
                {
                    delete objectPane->m_hitBarObjectPane;
                    if (currentValue <= 100)
                    {
                        CreateHitBarObjectPane(
                            objectPane, currentValue, 100);
                    }
                }

                if (objectPane == g_pUserPane &&
                    negativeAction &&
                    g_pUserPane->m_nameVisible)
                {
                    g_pUserPane->AdvanceMovementSendTick();
                }

                if (nestedEffectTrigger != 0)
                {
                    unsigned char effectPacket[13];
                    PacketBufferWriteUInt32BE(objectId, effectPacket + 1);
                    PacketBufferWriteUInt16BE(
                        nestedEffectDescriptorId, effectPacket + 5);
                    PacketBufferWriteUInt16BE(0, effectPacket + 7);
                    PacketBufferWriteUInt16BE(0, effectPacket + 9);
                    PacketBufferWriteUInt16BE(0, effectPacket + 11);
                    HandleObjectMoveEffectPacket(effectPacket);
                }
            }
        }

        return true;
    }

    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 1);
    const char actionFlags = static_cast<char>(packet[5]);
    const unsigned char currentValue = packet[6];
    PacketBufferReadUInt32BE(packet + 7);

    if (m_objectList != NULL)
    {
        LivingObjectPane *objectPane =
            static_cast<LivingObjectPane *>(
                m_objectList->FindByObjectId(objectId));
        if (objectPane != NULL)
        {
            objectPane->ShowDamageEffect(143 - actionFlags, 0);
            delete objectPane->m_hitBarObjectPane;
            if (currentValue <= 100)
                CreateHitBarObjectPane(objectPane, currentValue, 100);
        }
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - new UserPane IsGroupMember child

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::IsGroupMember(unsigned int memberId) const
{
    for (int i = 0; i < m_groupMemberCount; ++i)
    {
        if (m_groupMembers[i].memberId == memberId)
            return true;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - new UserPane AdvanceMovementSendTick child

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::AdvanceMovementSendTick()
{
    m_lastMovementSendTick += 1000;
    if (m_lastMovementSendTick >= g_pTimerMgr->m_currentTick)
        m_lastMovementSendTick = g_pTimerMgr->m_currentTick - 1;

    g_pBowGaugeObjectPane->SetAnimationStartTick(
        m_lastMovementSendTick);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - new BowGaugeObjectPane setter child

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BowGaugeObjectPane::SetAnimationStartTick(unsigned int startTick)
{
    m_animationStartTick = startTick;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 5 - new DamageNumberObjectPane constructor child

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DamageNumberObjectPane::DamageNumberObjectPane(
    LivingObjectPane *livingObjectPane,
    int mapY,
    int mapX,
    int damageAmount,
    unsigned char style)
    : AttachedObjectPane(
          kObjectPaneTypeDamageNumber,
          livingObjectPane,
          mapY,
          mapX),
      m_style(style),
      m_animationFrame(0),
      m_absoluteAmount(damageAmount),
      m_positive(damageAmount >= 0),
      m_digitFrameOffset(0)
{
    SetMode(3);
    m_alpha = 0;

    if (!m_positive)
        m_absoluteAmount = -damageAmount;

    sprintf_s(
        m_damageText,
        sizeof(m_damageText),
        "%d",
        m_absoluteAmount);

    if (m_style != 0)
    {
        if (!m_positive)
            m_digitFrameOffset += 10;
    }
    else
    {
        m_digitFrameOffset += 20;
        if (m_positive)
            m_digitFrameOffset += 10;
    }

    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        0,
        20,
        0,
        0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - complete rebased UserPane class block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MapPane;
class SelectObjectWithKeyboardPane;
class UserPane;
struct MapPoint;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

void ToggleTargetSelectionPane(bool alternateMode);
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer);
void ReverseTargetSelectionDirection();
extern bool g_selectObjectTargetModeActive;
extern bool g_targetObjectTargetModeActive;
extern SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void __stdcall SendDirectionPacket(unsigned char direction);
static void SendOpcode7Command(unsigned char command);
void RefreshGroupMemberMarkers(UserPane *userPane);
void ClearGroupMemberMarkers(UserPane *userPane);

struct GroupMemberRecord
{
    unsigned int memberId;                      // +0x000
    wchar_t name[128];                          // +0x004
    bool active;                                // +0x104
    unsigned short faceId;                      // +0x106
    unsigned char hairId;                       // +0x108
    unsigned char faceColor;                    // +0x109
    unsigned char hairColor;                    // +0x10a
    unsigned char skinColor;                    // +0x10b
    unsigned char bodyColor;                    // +0x10c
    unsigned char helmetId;                     // +0x10d
    unsigned char helmetColor;                  // +0x10e
    unsigned short faceDecorationId;            // +0x110
    unsigned char faceDecorationColor;          // +0x112
    unsigned short hairDecorationId;            // +0x114
    unsigned char hairDecorationColor;          // +0x116
    unsigned short secondFaceDecorationId;      // +0x118
    unsigned char secondFaceDecorationColor;    // +0x11a
    unsigned int maximumHitPoints;              // +0x11c
    unsigned int currentHitPoints;              // +0x120
    unsigned int maximumManaPoints;             // +0x124
    unsigned int currentManaPoints;              // +0x128
};

struct LocalInventorySlotRecord
{
    unsigned char active;
    unsigned char reserved001;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved005;
    wchar_t displayName[80];
    wchar_t itemMetaKey[80];
    wchar_t ownerName[80];
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;
    unsigned char quantityPromptFlag;
    unsigned char reserved1ed[3];
    unsigned int currentDurability;
    unsigned int protectionCount;
    unsigned char targetMode;
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;
    unsigned char reserved001[3];
    int inputKind;
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseGroupListPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(char direction);
    void BuildInventorySlotRangeText(wchar_t *outText) const;
    void BuildSpellSlotRangeText(wchar_t *outText) const;

private:
    friend class MapPane;
    friend void RefreshGroupMemberMarkers(UserPane *userPane);
    friend void ClearGroupMemberMarkers(UserPane *userPane);

    bool IsGroupMember(unsigned int memberId) const;
    GroupMemberRecord *FindGroupMemberById(unsigned int memberId);
    void AdvanceMovementSendTick();

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];
    GroupMemberRecord m_groupMembers[50];
    signed char m_groupMemberCount;
    unsigned char m_preCollectionState[0x203];
    int m_currentSayMode;
    unsigned char m_preCollectionCommandState[2];
    bool m_collectionPanelSoundEnabled;
    unsigned char m_postCollectionCommandState[9];
    int m_localPlayerHitRadius;
    CollectionPlayerDataView m_collectionData;
    int m_screenX;
    int m_screenY;
    unsigned int m_screenState;
    RectBounds m_screenHitBounds;
    RectBounds m_screenLowerHitBounds;
    MapPane *m_mapPane;
    unsigned char m_playerSettingsState[8];
    LocalInventorySlotRecord m_inventorySlots[52];
    SpellCommandSlotRecord m_spellCommandSlots[52];
    bool m_spellCommandSlotsReady;
    unsigned char m_preViewportState[3];
    int m_viewportColumn;
    int m_viewportRow;
    int m_viewportHalfColumns;
    int m_viewportHalfRows;
    int m_viewportRemainingColumns;
    int m_viewportRemainingRows;
    unsigned char m_movementState[5];
    unsigned char m_preActionTickState[3];
    unsigned int m_lastActionTick;
    unsigned int m_lastMapCommandTick;
    unsigned int m_lastGroundItemCommandTick;
    List *m_whisperHistoryOther;
    List *m_outgoingWhisperRecipientHistory;
    List *m_incomingWhisperSenderHistory;
    unsigned char m_whisperHistorySource;
    unsigned char m_preMovementHistory[3];
    LocalMovementHistoryRecord *m_movementHistoryRecords;
    int m_movementHistoryCapacity;
    unsigned char m_movementHistoryWriteIndex;
    bool m_inputLocked;
    unsigned char m_movementHistoryState[2];
    unsigned char *m_deferredUserListPacket;
    size_t m_deferredUserListPacketSize;
    int m_deferredUserListCount;
    unsigned int m_deferredUserListDeadline;
    bool m_deferredUserListActive;
    unsigned char m_preMovementTicks[3];
    unsigned int m_lastMovementSendTick;
    unsigned int m_lastMovementInputTick;
    unsigned char m_actionMode;
    unsigned char m_userPaneTrailingState0;
    bool m_includeAdjacentMovementTargets;
    unsigned char m_userPaneTrailingState2;
    ObjectStatusBlob m_currentAppearance;
};

typedef char GroupMemberRecordSizeMustBe300[
    sizeof(GroupMemberRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 7 - complete BowGaugeObjectPane class block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BowGaugeObjectPane : public Pane
{
public:
    BowGaugeObjectPane();
    virtual ~BowGaugeObjectPane();

    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void RemovePendingTimers();
    void SetAnimationStartTick(unsigned int startTick);

private:
    unsigned int m_animationStartTick;
};

typedef char BowGaugeObjectPaneSizeMustBe252[
    sizeof(BowGaugeObjectPane) == 0xfc ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 8 - complete DamageNumberObjectPane class block

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DamageNumberObjectPane : public AttachedObjectPane
{
public:
    DamageNumberObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        int damageAmount,
        unsigned char style);
    virtual ~DamageNumberObjectPane();

    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void UpdatePosition();

private:
    unsigned char m_style;
    unsigned char m_animationFrame;
    int m_absoluteAmount;
    bool m_positive;
    char m_digitFrameOffset;
    char m_damageText[16];
};

typedef char DamageNumberObjectPaneSizeMustBe328[
    sizeof(DamageNumberObjectPane) == 0x148 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior fidelity: the target keeps both EPF and legacy paths, duplicate membership query, unseeded packet byte zero, pool/allocation failure behavior, exact deletes, exact order, and unconditional true return.
- Source-era fidelity: ordinary classes/methods, local byte packet buffers, existing global/field names, `new`/`delete`, and private helpers fit the project's VC6/VC7-era style without decompiler labels or modern abstractions.
- Exact code-generation caveat: stripped compiler options and original lexemes cannot be proven. The chosen plain `char`, low-word nested locals, short-circuit expression, and ordinary `void` setters best explain the observed sign extension, word tests, repeated calls, and residue returns.

## Final Recommendation

- C3TQ-001 through C3TQ-046 are implemented without compression and carry terminal destination proof in the ledger.
- Four exact children were registered serially in ascending address order as UID0004SJ, UID0004SK, UID0004SL, and UID0004SM; all temporary tokens are gone before final cross-link verification.
- All eight complete managed blocks are installed exactly in their formal headers. No body-only sample, raw offset, explicit compiler mechanics, or duplicate class/aggregate emission was added.
- UID0003TH, UID0003TO, UID0004QN, UID0004R9, the complete B001/B002/B003/B004/B005/B011 MapPane/UserPane/Attached union, g_useEpfAssets, Config, LivingObjectPane, ObjectList, TimerMgr, packet helper, vtable, global, and pool facts are preserved.
- No implementation, investigable research, or manual-coverage item remains. Report validation, execution, move, archive, and counting remain external supervisor/validator-owned lifecycle state.

## Recommended Target Doc Changes

- Applied to `by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md`: `92/94`; retained UID0003TQ, owner/emitter UID00007Q, true, blank position, Nested0; Destination 1 exact.
- Item Summary: `Exact source-ready opcode-0x13 MapPane action/combat handler with rich g_useEpfAssets and legacy branches; parses BE32 object id, signed plain-char action flags, unsigned current value, and BE32 damage, resolves LivingObjectPane, preserves damage-effect, DamageNumber, group/local HitBar, local negative-action Bow tick, nested UID0003TO packet, unsafe trusted-buffer behavior, unconditional true return, exact range/hash/caller/padding, and compiler-lowering exclusions.`
- Preserved historical UID0003TH/UID0003Z4 notes and labeled their former broad blank-C++ conclusion superseded by this direct pass.
- Add complete packet layout, branch order, helper contracts, range/hash/padding, ownership, source placement, negative evidence, rejected alternatives, and score rationale from this report.

## Recommended Support Doc Changes

- Applied serially: the four exact child pages from Function / Child Inventory are UID0004SJ/UID0004SK/UID0004SL/UID0004SM; every later link, Item Summary, aggregate, class/file, manual template, generated assertion, ledger, and checklist uses those real UIDs.
- Applied and current-union verified: `by-class/MapPane.md` preserves the exact target declaration and complete class formal while later accepted B001/B002/B003 deltas extend the union; `by-file/MapPane.md` retains `92/92` and preserves all B001/B002/B003/B004/B005/B011 source routes, including UID0003TQ and UID0004SJ-UID0004SM, at same-or-greater detail.
- Applied: UID0001AW retains false/non-emitting/blank formal and score with source-ready UID0003TQ inventory. Destination 6 preserves the complete UserPane block and adds only the two private declarations; UID0000P1/UID0001KL/UID0001KM add bounded helper evidence without score inflation, and UID0001KM correctly covers Advance only.
- Applied: Bow class/file are `90/92` and `85/90`, Destination 7 is exact, and all resource/singleton/timer/vtable/paint/destructor/compositor evidence remains intact.
- Applied: Damage class/file are `90/93` and `87/90`, Destination 8 is exact, the complete Attached/HitBar/ObjectInfo union is preserved, and UID0001DB stays false/non-emitting `86/91` with exact child inventory.
- Applied: `by-memory/-ignored.md` contains all eight exact new padding rows and preserves every current fact, including the pre-existing target successor.
- Verify-only, unchanged unless contradiction: UID0003TH, UID0003TO, UID0004QN, UID0004R9, UID0001OH/UID0000SW, UID0001OR, Config, LivingObjectPane, ObjectList, TimerMgr, pool/vtable/resource/global pages.

## Score And Metadata Recommendation

| Destination | Pre-callback | Current implemented | Metadata |
| --- | ---: | ---: | --- |
| UID0003TQ | 86/90 | 92/94 | owner/emitter 00007Q, true, blank position, Nested0 |
| UID0004SJ Bow setter | absent | 92/94 | owner/emitter 000011, true, blank position, Nested0 |
| UID0004SK Damage constructor | absent | 91/93 | owner/emitter 00003F, true, blank position, Nested0 |
| UID0004SL Advance helper | absent | 91/93 | owner/emitter 0000FQ, true, blank position, Nested0 |
| UID0004SM IsGroupMember | absent | 92/94 | owner/emitter 0000FQ, true, blank position, Nested0 |
| UID000011 | 86/88 | 90/92 | owner/emitter 0000HU retained |
| UID0000HU | 84/88 | 85/90 | file owner/path retained |
| UID00003F | 86/90 | 90/93 | owner/emitter 0000HJ retained |
| UID0000HJ | 86/86 | 87/90 | file owner/path retained |

- Target completion rises because every packet field, branch, helper, child, overlay path, unsafe behavior, range, source route, and formal body is resolved. Confidence stops at 94 because private original names and exact historical source formatting are stripped.
- Bow/Damage score increases are bounded to the class/source surfaces directly closed here. Unrelated render body details remain child-owned and prevent unjustified whole-file scores.
- UID00007Q `93/94`, UID0000L3 `92/92`, UID0000FQ `93/94`, UID0000P1 `92/93`, UID0001AW `86/90`, UID0001DB `86/91`, UID0001KL `91/93`, UID0001KM `90/92`, and ignored metadata remain unchanged.
- All score-limiting blockers named by the assignment were researched: packet layout, global, field/helper names, Damage constructor/layout, group test, Bow tick path, nested packet, rich/legacy semantics, range/padding, owner/source, C++, and generated/manual consequences.

## Open Questions With Attempted Resolution

- Original action-subtype enum names: exact symbolic spellings are stripped. Resolution: preserve numeric mask/constants and use descriptive `actionFlags`; no enum invention is required for source correctness or score.
- Original helper spellings: source names are stripped. Resolution: `IsGroupMember`, `AdvanceMovementSendTick`, and `SetAnimationStartTick` are the narrowest behavior-specific names supported by receiver/callers/state. Confidence cap only.
- Nested locals' original declared width: dword initialization contrasts with low-word test/writer use. Resolution: `unsigned short` is highest probability because only the low word is semantically consumed and the writer contract is BE16; compiler widening explains dword stores. Values are only 0/224/245, so full observed behavior is exact.
- Bow standalone versus private UserPane companion: current separate file/class/global/resource/vtable route makes standalone primary. A private companion is retained only as historical runner-up and no longer blocks emission.
- DamageNumber original field names: exact spellings are stripped, but roles/offsets/types are complete. Descriptive names match all constructor/render consumers and are source-ready.
- Questions remaining unresolved with implementation impact: zero. Lexical uncertainty is bounded, documented, and reflected in confidence; it does not justify blank C++ or deferred investigation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical supervisor commands `13613`/`13614`/`13615` applied B004's accepted handoff exactly. Current read-only manual snapshots match later supervisor commands `13646`/`13647`/`13648`: by-memory SHA256 `15503038D5DF3CA5364A424E8AF4F83CC44196E748D27A33670F01B069BB2D93` (1,744,817 bytes/4,210 lines), by-class SHA256 `9D42F839A670E40D90CD834A0FE0F25A964ADF5BC2A12FDDF77AFB7AE6C2A391` (225,346 bytes/622 lines), and by-file SHA256 `C2A5EC493F029B814FD600A31E49B08888FB13ABE14D4247822F220A4562BC17` (129,033 bytes/316 lines). The later B001/B002 additions preserve every B004 by-memory/class/file replacement and insertion at same-or-greater detail. Direct `by-struct/-coverage-report.md` is absent, and no by-struct destination, affected row, or handoff text was required.
- UID0003TQ and real child UIDs UID0004SJ/UID0004SK/UID0004SL/UID0004SM are present in current manual coverage at the current address-ordered anchors recorded above. The exact text below is retained verbatim as historical accepted B004 handoff/application evidence, not as pending supervisor work; direct comparison leaves no B004 manual delta.
- Historical exact by-memory replacements applied by the supervisor:

```text
    - [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | packet-handler split index | MapPanePacketHandlers : not_reconstructable : 86% : very-strong : Non-emitting MapPane packet-handler split/container with exact source-bearing children, including source-ready UID0003TI/UID0003TJ static-object creation/region reconciliation, source-ready UID0003TK opcode-0x15 map/effect-state parsing and direct bool return, source-ready UID0003TO opcode-0x29 trusted-packet object/effect routing with signed descriptor/action, coordinate/object requests, compiler-inlined FlashMapColor(143), unconditional success, and preserved unsafe/no-length behavior, plus source-ready UID0003TX opcode-0x33 ObjectStatusBlob parsing, visible-bounds/factory/ObjectInfo replacement, and status/group refresh behavior; preserves unrelated packet/helper dispositions, live opcode `0x67` TimerPane create/update/delete flow, retained duplicate `0x005140a0` with zero inbound xrefs or pointer route, MapPane ownership of parsing, and TimerPane ownership of the called constructor/SetTimer source; adds source-ready UID0003TQ opcode-0x13 rich/legacy action-combat processing with exact DamageNumber, HitBar, UserPane/Bow-tick, nested UID0003TO, unsafe trusted-packet, and unconditional-success behavior.
    - [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md) 0x00538bc0-0x00539bb2 | mixed-class-cluster | ObjectOverlayPanes : not_reconstructable : 86% : very-strong : Non-emitting mixed BowGauge/attached-overlay physical inventory with 27 modeled starts and exact padding. HitBar rows resolve dual/style constructors, SetValues, IsActive, shared UpdatePosition, ClearOutputRects, RenderFrame, exact 0x138 layout, pool/vtable/resource support, MapPane callers, and compiler-only unwind/deleting/vtable mechanics; per-class children own source; adds the exact BowGauge SetAnimationStartTick child and DamageNumber constructor/class-layout child while retaining all existing HitBar/ObjectInfo/pool/vtable/resource/compiler dispositions.
    - [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md) 0x005a2530-0x005b8395 | broad reconstructable UserPane aggregate | UserPane : reconstructable : 91% : very-strong : Complete UserPane executable/source-family index with exact constructor/destructor/vtables, complete EventHandler key/text dispatcher, six source-ready B003 helper children, source-ready opcode-0x0f inventory/opcode-0x08 settings/opcode-0x05 server-entry members, current B002 UID0004R9 preservation, attached compiler switch data, exact 0x20c base and 0x13eb84 object boundary, corrected member/file-local routing, retained raw/inline-equivalent history, exact padding, and no synthetic aggregate body; adds source-ready AdvanceMovementSendTick and IsGroupMember children with exact group-count/table, movement-tick, TimerMgr, and BowGauge contracts.
    - [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | non-emitting UserPane source-family index | UserPaneLocalPlayerExtensions : not_reconstructable : 90% : very-strong : Exact mixed index for UserPane members, UserPane.cpp file-local helpers, retained raw bodies, inline-equivalent routes, and internal padding; preserves B001 movement, B004 opcode-0x0f inventory, B005 opcode-0x08 settings, B004 opcode-0x05 server-entry, and current B002 group-list path facts, and now routes exact UID0004R3 opcode-7 plus UID0004R7/UID0004R8 slot-range children while owner NONE/blank emitter/formal C++ remain index-only; adds source-ready UID0004SL AdvanceMovementSendTick at 0x005a8fc0 with exact +1000/current-tick clamp/Bow animation-start behavior. UID0004SM IsGroupMember begins after this row's exclusive 0x005ad441 end and remains a sibling under broad UID0001KL.
```

- Historical exact by-memory insertions applied by the supervisor in address order:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0051295d-0x00512960 | padding | MapPane predecessor to HandleActionPacket alignment : ignored : 100% : strong : Three exact 0xcc bytes before UID0003TQ; SHA256 E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE; no source body.
        - [UID:0003TQ][0x00512960-0x00512ca4.MapPaneHandleActionPacket](by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md) 0x00512960-0x00512ca4 | private packet method | MapPaneHandleActionPacket : reconstructable : 92% : very-strong : Exact source-ready opcode-0x13 MapPane action/combat handler with rich g_useEpfAssets and legacy branches; parses BE32 object id, signed plain-char action flags, unsigned current value, and BE32 damage, resolves LivingObjectPane, preserves damage effect, DamageNumber construction/registration/timers, group/local HitBar policy, local negative-action Bow tick, unseeded-byte nested UID0003TO packet reuse, unsafe trusted-buffer behavior, unconditional true return, exact range/hash/caller/padding, and compiler exclusions.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00512ca4-0x00512cb0 | padding | MapPaneHandleActionPacket to raw helper alignment : ignored : 100% : strong : Twelve exact 0xcc bytes after UID0003TQ; SHA256 A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902; existing ordinary ignored fact, absent manual row.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00538cfa-0x00538d00 | padding | BowGauge OnPaint to animation-start setter alignment : ignored : 100% : strong : Six exact 0xcc bytes; SHA256 33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722.
    - [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md) 0x00538d00-0x00538d10 | BowGaugeObjectPane method | BowGaugeObjectPaneSetAnimationStartTick : reconstructable : 92% : very-strong : Exact one-store void setter for unsigned animation-start tick at +0xf8, with sole UserPane caller and BowGauge OnPaint elapsed-frame consumer; source-owned by UID000011.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053922b-0x00539230 | padding | HitBar render to DamageNumber constructor alignment : ignored : 100% : strong : Five exact 0xcc bytes; SHA256 992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329.
    - [UID:0004SK][0x00539230-0x0053935e.DamageNumberObjectPaneConstructor](by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md) 0x00539230-0x0053935e | constructor | DamageNumberObjectPaneConstructor : reconstructable : 91% : very-strong : Complete AttachedObjectPane-derived DamageNumber constructor with owner/map row/map column/signed amount/style ABI, object type 8, mode 3, alpha zero, sign/absolute formatting, 16-byte %d text, style-dependent digit offset, timer event 0 after 20 ms, exact 0x148 layout, four callers, and compiler pool/EH/vptr exclusions.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053935e-0x00539360 | padding | DamageNumber constructor to unwind helper alignment : ignored : 100% : strong : Two exact 0xcc bytes; SHA256 E3966E3275BE536A16092EC0CADF1638F718218E616FBBE8FF1C5E67FFF4DEF2.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a8fb4-0x005a8fc0 | padding | UserPane action helper to AdvanceMovementSendTick alignment : ignored : 100% : strong : Twelve exact 0xcc bytes; SHA256 A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902.
        - [UID:0004SL][0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick](by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md) 0x005a8fc0-0x005a8ff2 | UserPane method | UserPaneAdvanceMovementSendTick : reconstructable : 91% : very-strong : Exact target-live UserPane helper that adds 1000 to m_lastMovementSendTick, unsigned-clamps values at/after TimerMgr current tick to current tick minus one, forwards the result to BowGauge SetAnimationStartTick, and preserves no-null/underflow checks.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005a8ff2-0x005a9000 | padding | AdvanceMovementSendTick to next UserPane body alignment : ignored : 100% : strong : Fourteen exact 0xcc bytes; SHA256 1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005adb97-0x005adba0 | padding | UserPane predecessor to IsGroupMember alignment : ignored : 100% : strong : Nine exact 0xcc bytes; SHA256 57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE.
    - [UID:0004SM][0x005adba0-0x005adbdc.UserPaneIsGroupMember](by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md) 0x005adba0-0x005adbdc | UserPane method | UserPaneIsGroupMember : reconstructable : 92% : very-strong : Exact private const membership query over signed group count and 0x12c GroupMemberRecord table, returning bool without clamps or defensive checks; its two opcode-0x13 target calls prove liveness.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005adbdc-0x005adbe0 | padding | IsGroupMember to FindGroupMemberById alignment : ignored : 100% : strong : Four exact 0xcc bytes; SHA256 8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA.
```

- Historical exact by-class replacements applied by the supervisor:

```text
- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era MapPane declaration emitter at position 0 with exact 0x910 layout and current method union, including source-ready RequestObjectEffect, RequestCoordinateEffect, CreateEffectObjectPane, and ApplyEffectObjectPaneTimerAction integration with typed EffectInfo/LivingObjectPane/EffectObjectPane and exact event-2 action semantics; source-ready private CreateHitBarObjectPane with unsigned-short current/maximum values, style 1 only for ObjectStatusBlob::HumanObject and 0 otherwise, separate ordinary-new branches, typed LivingObjectPane owner-slot installation and ObjectList registration, timer event 0 scheduled for 500 ms self-delete, and exact UpdatePosition, inherited GetBounds, then InvalidateRect order; corrected six-byte MapTileLayerIds with staticObjectId, typed CreateStaticObjectPaneForTile, and source-ready RefreshStaticObjectTileRegion declarations; source-ready opcode-0x15 HandleEffectMapStatePacket with exact packet/cache/ObjectList/weather/movement/day-night/transient/waiting/EPF/config lifecycle; source-ready opcode-0x29 HandleObjectMoveEffectPacket with signed descriptor/action, trusted conditional reads, coordinate/object effect routing, compiler-inlined FlashMapColor(143), lookup-miss/no-length behavior, and unconditional success; exact opcode-0x33 HandleObjectInfoPacket and corrected by-value CreateOrUpdateObjectPane declarations with typed ObjectInfo/Living/ObjectStatus/Item support; compiler ABI lowering excluded; followed by address-ordered exact children; adds source-ready UID0003TQ HandleActionPacket with exact rich/legacy DamageNumber, HitBar, UserPane/Bow-tick, nested UID0003TO, trusted-buffer, and unconditional-success behavior.
- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 93% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, signed plain-char StartDirectionalAnimation(char direction) with signed-short frame-duration/MonsterObject image-table and signed non-monster scaled-delay contracts, 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, exact player-settings semantics comprising state[0] feature/UI mode, state[2] viewport-threshold mode, state[3] direction mode, state[4] MapPane-render blindness with bounds invalidation, and state[5]/[6] chat display/send restriction levels, the distinct movement-state index-3 pending-reply flag versus index-4 direction-delay state, source-ready opcode-0x05 HandleServerEntryPacket declaration, exact EventHandler HandleKeyOrTextEvent(Event *) override, six resolved B003 target/helper declarations, preserved current B002 UID0004R9 child, int say-mode/collection-panel-sound/three-debounce/input-lock field splits, exact 0x20c base boundary, class closure before child definitions, exact records/size guards, preserved full unrelated field/record/layout/source surface, exact final-byte plus 68-byte m_currentAppearance tail used by MapPane local-player status updates, and UID0003UB's retained ExecuteHotkeyAction(short) declaration plus exact three-page 30-row Text/Spell/Item runtime behavior; the complete Config declaration exposes direct macro and compact tables; UID0003UA emits exact retained compact-shortcut source while UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; adds exact private IsGroupMember(unsigned int) const and AdvanceMovementSendTick() declarations over the existing signed group count, GroupMemberRecord table, movement tick, TimerMgr, and BowGauge state.
- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) : reconstructable : 90% : very-strong : Local-player bow-gauge HUD pane attached to `BowGaugeObjectPane.cpp`, with live IDA-confirmed constructor/global/vtable writes, `g_pBowGaugeObjectPane` lifecycle and UserPane consumers, `BGAUGE.EPF`/`BGAUGE.pal` paint path, shared compositor caller set, show/timer scheduling, destructor slot, and standalone-vs-UserPane source-split caveat; adds the complete 0xfc Pane-derived declaration, exact SetAnimationStartTick(unsigned int), one animation-start tick field, size guard, and compiler ABI exclusions.
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md) : reconstructable : 90% : very-strong : Attached combat-number overlay with exact constructor/animation/UpdatePosition/packed-copy/render/destructor anchors, pool/vtable/resource support, and compiler exclusions; historical ComputeDisplayBounds is retained as a descriptive alias for the shared final AttachedObjectPane UpdatePosition override; adds the complete 0x148 declaration with exact owner/map/signed-amount/style constructor, timer/render/position virtuals, style/frame/absolute/sign/digit-offset/16-byte text layout, MapPane callers, size guard, and compiler-only allocation/EH/deleting/vtable exclusions.
```

- Historical exact by-file replacements applied by the supervisor:

```text
- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children route and exact source-ready object/coordinate effect descriptor, EffectObjectPane creation, and existing-pane delete/cancel/guarded timer replacement family; preserves typed LivingObjectPane/EffectInfo/TimerHandler contracts, target registration/timer/bounds behavior, and prose-only by-file policy; includes source-ready private CreateHitBarObjectPane with unsigned-short current/maximum values, ObjectStatusBlob::HumanObject style-1 versus default style-0 decision, separate ordinary-new branches, typed LivingObjectPane owner-slot installation and ObjectList registration, timer event 0 scheduled for 500 ms self-delete, and exact UpdatePosition, inherited GetBounds, then InvalidateRect order; adds the corrected six-byte static-object tile view and source-ready CreateStaticObjectPaneForTile/RefreshStaticObjectTileRegion pair with exact ObjectList lookup, stale-object lifetime, replacement, and compiler-exclusion behavior; preserves source-ready opcode-0x15 HandleEffectMapStatePacket packet/cache/ObjectList/weather/day-night/transient/waiting/EPF/config behavior and compiler exclusions; preserves source-ready opcode-0x29 HandleObjectMoveEffectPacket with signed descriptor/action, conditional trusted reads, coordinate/object routing, compiler-inlined FlashMapColor(143), lookup-miss/no-length behavior, and unconditional success; adds exact opcode-0x33 HandleObjectInfoPacket, file-static RefreshObjectStatusOverlay, corrected by-value CreateOrUpdateObjectPane, ObjectInfo/Item declaration dependencies, and no by-file reconstruction metadata; adds source-ready opcode-0x13 HandleActionPacket with exact rich g_useEpfAssets and legacy parsing, DamageNumber create/register/timer flow, group/local HitBar policy, local negative-action UserPane/Bow update, unseeded-byte nested UID0003TO effect packet, unsafe trusted-buffer behavior, and unconditional true return.
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, signed plain-char StartDirectionalAnimation(char direction) with signed-short MonsterObject frame-duration image-table/group/frame path, signed non-monster scaled-delay arithmetic, event-20 scheduling, branch-specific ordering, and branch-local MapPane refresh, corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior, preserved action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the exact 508-byte inventory record with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, active UserStatusPane slot-count bound, exact write order, and preserved invalid-slot/always-false behavior, source-ready opcode-0x08 settings parsing with exact state indices, 2/31 offset arithmetic, packet cursor/store order, blindness invalidation, movement-state/TryStepForward order, ten ordered direct config stores, SoundManager enable/mirror order, active GeneralPurposePanel child-6 OnActivate refresh, and adjacent movement-reply index-3 versus index-4 corrections, source-ready opcode-0x05 HandleServerEntryPacket with duplicated EPF/legacy SpelledPane refresh, sender re-enable, transfer-overlay deferred deletion, object/facing/status-icon application, MapPane bounds refresh, and block/listen replay, plus exact HandleKeyOrTextEvent(Event *) entry gates/modifier and key switches/handled returns/packet order and source body, two slot-range methods, opcode-7 sender, current B002 UID0004R9 preservation, target-selection cross-TU declarations, compiler switch/vtable exclusions, retained raw/inline-equivalent history, exact source order, no UID0003V9 empty emitter or duplicate body, UID0003UB's exact source position, three-page caller route, 30-row Text/Spell/Item behavior, helper/packet dependencies, retained UID0000FQ emitter route, complete Config table declarations, exact retained UID0003UA compact-shortcut source, and exact final-byte plus 68-byte m_currentAppearance tail used by MapPane; UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; adds exact private IsGroupMember and AdvanceMovementSendTick definitions with class closure, source order, and compiler exclusions preserved.
- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) : reconstructable : 85% : very-strong : Local-player bow-gauge pane source root with UserPane construction, singleton lifecycle, EPF/palette drawing, timer scheduling/cleanup, vtable/resource anchors, shared compositor exclusion, and standalone-vs-UserPane companion caveat documented; adds the complete 0xfc class declaration, constructor/destructor, OnPaint/OnTimer, RemovePendingTimers, exact animation-start tick setter, singleton/resource/UserPane route, size guard, and no handwritten compiler ABI.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) : reconstructable : 87% : very-strong : NexusTK/map AttachedObjectPane.cpp source root with complete AttachedObjectPane and HitBarObjectPane declarations, exact common UpdatePosition slot, typed owner accessors, HitBar 0x138 layout/method/lifecycle evidence, derived overlay families, pool/vtable/resource support, and compiler ABI exclusions; adds the complete 0x1c0 ObjectInfoObjectPane declaration with exact name/layout state and inherited ClearOutputRects/RenderFrame/SetSpriteAttribute/UpdatePosition virtual surface; stale UpdateHitBarBounds, ComputeDisplayBounds, and ObjectInfo directional spellings remain historical aliases only; adds the complete 0x148 DamageNumberObjectPane declaration plus exact constructor with sign/style/text/timer behavior, four MapPane callers, pools/vtables/resources, and compiler allocation/EH/deleting/vtable exclusions without duplicating sibling bodies.
```

- Current placement: target predecessor, target, and target successor rows remain after UID0003TP/UID0004SN and before the later UID0003TS child; overlay rows remain after UID0001DC and before UID0001DB's successor padding; Advance rows remain after UID0003UI and before UID0003UJ; IsGroupMember remains immediately before UID0004R9. Class/file replacements retain alphabetical UID row positions.
- B004 did not apply these manual rows. Supervisor-owned commands `13613`/`13614`/`13615` performed the historical B004 application, and current commands `13646`/`13647`/`13648` retain every B004 row while adding the accepted B001/B002 union. The current hashes and anchors above are authoritative for this rebase.

## Follow-Up Actions

- Implementation, scoped/waited validation, and supervisor-owned manual coverage application are complete; no B004 implementation or coverage-handoff item remains. Report validation, execution, count, path, move, and archive state are external supervisor/validator-owned and authoritative only in external audit/validator history/current path.
- B004 itself performed no report execution, lifecycle/probe/count/revalidation, move, or archive command. This is a durable boundary statement, not a pending lifecycle directive.
- A-agent action: none.
- Further target research: none required. Original private lexemes could be refined by symbols/source recovery but are not current blockers.

## Confidence

- Recommendation confidence: very strong.
- Target score confidence: high for `92/94`; direct behavior is exact and only stripped lexical spelling remains inferred.
- Support score confidence: high for exact children and class layouts; bounded whole-file scores avoid claiming unrelated completion.
- Remaining uncertainty: original private helper/member spelling and historical file/header factoring only; no behavioral, ABI, ownership, source placement, range, or formal-C++ blocker remains.

## Validator Results

- Every changed ordinary page received one scoped validator while leased; the target received one additional final waited validator after all ordinary edits. All 19 invocations exited 0 with `ok:1`, and every lease was released immediately after its page's validation window.

| Command | Timestamp EDT | Final scoped file / purpose | Result | Warnings / side effects |
| --- | --- | --- | --- | --- |
| `000000013593` | `2026-07-16T00:58:53-04:00` | UID0004SJ registration | exit 0 / ok 1 | assigned UID0004SJ; completion/confidence/owner/emitter registry; generated deferred |
| `000000013594` | `2026-07-16T01:00:05-04:00` | UID0004SK registration | exit 0 / ok 1 | assigned UID0004SK; registry/generated deferred |
| `000000013596` | `2026-07-16T01:01:11-04:00` | UID0004SL registration | exit 0 / ok 1 | assigned UID0004SL; linked UID0004SJ; generated deferred |
| `000000013597` | `2026-07-16T01:02:17-04:00` | UID0004SM registration | exit 0 / ok 1 | assigned UID0004SM; registry/generated deferred |
| `000000013598` | `2026-07-16T01:04:31-04:00` | UID0003TQ target | exit 0 / ok 1 | target score/formal registry; validator-managed UID0001OH storage-link normalization; generated deferred |
| `000000013599` | `2026-07-16T01:05:20-04:00` | UID0001AW MapPane packet index | exit 0 / ok 1 | 30 pre-existing missing-ref warnings; generated deferred |
| `000000013600` | `2026-07-16T01:06:24-04:00` | UID00007Q MapPane class | exit 0 / ok 1 | 45 pre-existing missing-ref warnings; prose-only target synchronization; generated deferred |
| `000000013601` | `2026-07-16T01:07:10-04:00` | UID0000L3 MapPane file | exit 0 / ok 1 | 52 pre-existing missing-ref warnings; generated deferred |
| `000000013602` | `2026-07-16T01:08:14-04:00` | UID0000FQ UserPane class | exit 0 / ok 1 | 5 pre-existing missing-ref warnings; class formal hash update; generated deferred |
| `000000013603` | `2026-07-16T01:09:15-04:00` | UID0000P1 UserPane file | exit 0 / ok 1 | 18 pre-existing missing-ref warnings; generated deferred |
| `000000013604` | `2026-07-16T01:11:07-04:00` | UID0001KL broad UserPane index | exit 0 / ok 1 | 8 pre-existing UID0003V8/UID0003VC warnings; three reference additions; generated deferred |
| `000000013605` | `2026-07-16T01:12:33-04:00` | UID0001KM local-player index | exit 0 / ok 1 | 7 pre-existing UID0003JN/UID0003V8/UID0003VC warnings; three reference additions; generated deferred |
| `000000013606` | `2026-07-16T01:13:36-04:00` | UID000011 Bow class | exit 0 / ok 1 | score/formal registry and UID0004SJ link; generated deferred |
| `000000013607` | `2026-07-16T01:14:20-04:00` | UID0000HU Bow file | exit 0 / ok 1 | score/reference/stats updates; generated deferred |
| `000000013608` | `2026-07-16T01:15:15-04:00` | UID00003F Damage class | exit 0 / ok 1 | score/formal registry and UID0004SK link; generated deferred |
| `000000013609` | `2026-07-16T01:16:07-04:00` | UID0000HJ Attached file | exit 0 / ok 1 | score/reference/stats updates; generated deferred |
| `000000013610` | `2026-07-16T01:16:59-04:00` | UID0001DB overlay index | exit 0 / ok 1 | UID0004SJ/UID0004SK reference additions; generated deferred |
| `000000013611` | `2026-07-16T01:18:17-04:00` | UID0000VN ignored index | exit 0 / ok 1 | 257 pre-existing shared-index missing-ref warnings; seven reference additions; generated deferred |
| `000000013612` | `2026-07-16T01:18:34-04:00` | UID0003TQ final `--wait-generated` | exit 0 / ok 1 | generated completed; registry rebuild and project-wide pre-existing marker/no-code diagnostics |

- Historical before-state command `000000013588` had one UID0003TQ Empty Emitter Marker and zero target definitions. Historical B004 waited command `000000013612` established the accepted implementation. Current read-only command/header `000000013645`, refreshed `2026-07-16T03:09:31-04:00`, proves one UID0003TQ annotation/definition at 3581/3582 and zero target marker; one annotation/definition and zero corresponding marker for each UID0004SJ/UID0004SK/UID0004SL/UID0004SM; one UID0003TH and one UID0003TO; complete class closure before children; and no duplicate accepted definition.
- Generated target semantic readback preserves rich/legacy branches, signed plain-char action, exact DamageNumber/HitBar ordering, duplicated IsGroupMember calls, local negative-action helper, unconditional true returns, and a 13-byte nested packet whose byte zero remains unseeded while +1/+5/+7/+9/+11 are written. Target/child source contains no explicit allocation-pool call, vptr store, EH/unwind state, deleting-destructor body, adjustor thunk, RTTI/vtable table, or padding body.
- Current generated hashes at command/header `13645`: MapPane `B4D6F013338AC0B013C6100BE60036572537F44761C9A39C290F4F13AD419EA3` (138,106/4,132); UserPane `390FDEA85F3999182CC4781FE17511E8F39D8C33967D01A53861D257F3547CEE` (91,175/2,723); BowGaugeObjectPane `99FD52CAFF19E0D75605D68F1745817EF4EF09DD4C2CD7ABCBFEBE39417E6087` (2,205/49); AttachedObjectPane `1FEA2686B2D4EA2E112FC874943F321EC570612449A3875FCBACC6D630F2A491` (10,901/288). MapPane has exactly 80 total qualified definitions / 80 unique qualified names / 78 non-constructor/destructor definitions; its five Empty Emitter Markers are unrelated UID0004DS/UID00037T/UID0003TN/UID0003TT/UID0001SO.
- Supervisor-owned manual coverage validators: historical B004 application commands `13613`/`13614`/`13615` remain preserved; current by-memory command `13646`, timestamp `2026-07-16T03:27:51-04:00`, exit 0/ok 1, SHA `15503038D5DF3CA5364A424E8AF4F83CC44196E748D27A33670F01B069BB2D93`; current by-class command `13647`, timestamp `2026-07-16T03:28:00-04:00`, exit 0/ok 1, SHA `9D42F839A670E40D90CD834A0FE0F25A964ADF5BC2A12FDDF77AFB7AE6C2A391`; current by-file command `13648`, timestamp `2026-07-16T03:28:11-04:00`, exit 0/ok 1, SHA `C2A5EC493F029B814FD600A31E49B08888FB13ABE14D4247822F220A4562BC17`. Every B004 row is present at same-or-greater detail, no B004 manual delta remains, and no direct by-struct file/row was required. B004 ran none of these commands and edited no manual coverage.

## Changed Files

- Created and validator-registered ordinary pages:
  - `by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md` -> UID0004SJ, SHA `49D86F96448F8A38C2E3BE95A17F7996016E07CC84CE3C5481381A643535C083`.
  - `by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md` -> UID0004SK, SHA `D21F2097555F89DD930C0224AB52862725CF86E1C6FE41AC4C5F8EF41081A52D`.
  - `by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md` -> UID0004SL, SHA `49381B23F0BE3CACF4071834AD579D2A5EBA4413A541EE16025A7D3A72D67095`.
  - `by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md` -> UID0004SM, SHA `9B945CFFCD60859A8CFEACDAF14F6CBEA2A14F9BE98F5E136C193FD7A6393E8E`.
- Modified ordinary pages:
  - target UID0003TQ `by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md`, SHA `AE1685AA2255019B4B887CDBCF8594F03D98B86D4466D8F15C2B2D25D810BCDB`.
  - UID0001AW `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, current SHA `4241D9B3BA6432D9291DBE3686A13E2E89F2446BAE1797C06811767A83C57111`; historical B004 callback SHA `1D16109BFE130A3318F102A06D02C3A7A38C56A208A429FBE3DA653DDD93A297`.
  - UID00007Q `by-class/MapPane.md`, current SHA `A076D4E350565BAD1EADF679A93E9E908CB0F321EAF11710B16FC580E7F1375C`; historical B004 callback SHA `4E94A1DC256EE1FE623C353238F8B128F10CFCFCCD787825B09C8C68ECC51B42`.
  - UID0000L3 `by-file/MapPane.md`, current SHA `978C6CD6F6309E86007DD77D39788A1C063F998D16A060C0C55D2BBB479959A5`; historical B004 callback SHA `D305B897CD84E071BAE13CF34E829B7CECACA1BE63AD7AAEB002DFA0125D9D14`.
  - UID0000FQ `by-class/UserPane.md`, SHA `CE6EADF292A480FEE13F3806C14D3A91C908ED475F5D31C8034A9BD5A910DF3D`.
  - UID0000P1 `by-file/UserPane.md`, SHA `70856FF2053521D9C1CCDA194BFBC3BB662E8B2F63780CB10EE0994555A6898C`.
  - UID0001KL `by-memory/0x005a2530-0x005b8395.UserPane.md`, SHA `D7DBEE77DC7AF8BE74A11AB1FF07E7EF3C5328292E91F1292E142417EA4285FC`.
  - UID0001KM `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md`, SHA `B0BC01730F60290FD588BDE1BBB951451A1AA40AEF51D52CE4BB5B30A11657C7`.
  - UID000011 `by-class/BowGaugeObjectPane.md`, SHA `D74E76A131108979941ED71A0BFDBA2BF6ABB6EA9D298B467C98219EB873FB04`.
  - UID0000HU `by-file/BowGaugeObjectPane.md`, SHA `2E90817487A8B484D1CE8715416F06D0AEFD1831B68D6CEA9B2E40A9E0703268`.
  - UID00003F `by-class/DamageNumberObjectPane.md`, SHA `2F7E7EC7D804EF45FAE7EB3866BBBF290809FF470A5ECA23C29B445B76FE6328`.
  - UID0000HJ `by-file/AttachedObjectPane.md`, SHA `7522EF91651938F2B8D7A2237FF9357671E35E0D0AC393A539A09994E979C8CE`.
  - UID0001DB `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md`, SHA `9CA8760C08438942B74E229FAC392C24871082322B86BE2DD211B2420A8C7D1C`.
  - UID0000VN `by-memory/-ignored.md`, current SHA `BC3307AEADB436276C7AF9C83BCF52A049FFB7D0D03DDE6F393AB376A1EC42EA`; historical B004 callback SHA `D894AB2772645D9135BEA6A940ADC67133AA9ECA0DE1AA4D886DA5088C0EE676`.
- This same report is reconciled in place; its exact non-circular SHA/bytes/lines are reported after final release.
- Renamed: none.
- IDA mutations: none.
- During this bounded current-union rebase only this report changed. External supervisor/validator actions had already advanced the shared state through B001 execution `13641`, B002 waited generation `13645`, manual coverage `13646`-`13648`, B002 execution `13651`, and B003 execution `13652`. B004 did not edit ordinary, manual, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, or IDA files. Generated output plus registry/stats changes remain validator-owned side effects of historical authorized commands.
- No report lifecycle, execute, probe, count, revalidation, move, or archive command was run. No ordinary rename was required.

## Implementation Tracking Checklist

Implementation callback reconciliation; all 74 rows are independently true:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `E014CC2AAD443C072060AA76E522E0755E0F8C284F101B4A58A09D776777ECD4` before implementation.
- [x] Confirm exact accepted report SHA before callback.
- [x] Obtain supervisor shared-lane clearance for MapPane/UserPane/AttachedObjectPane destinations.
- [x] Re-read historical B002 UID0003TX coordination evidence and the current executed B001 UID0003TP/B002 UID0003TS/B003 UID0003TJ archives before this current-union rebase.
- [x] Re-read each destination after acquiring its short one-file lease.
- [x] Apply C3TQ-001 exact target range/hash evidence.
- [x] Apply C3TQ-002 opcode/caller/owner evidence.
- [x] Apply C3TQ-003 target signature.
- [x] Apply C3TQ-004 EPF selector semantics.
- [x] Apply C3TQ-005 object-id packet field.
- [x] Apply C3TQ-006 signed plain-char action field.
- [x] Apply C3TQ-007 current-value/damage fields.
- [x] Apply C3TQ-008 rich display action mask.
- [x] Apply C3TQ-009 nested descriptor flag mapping.
- [x] Apply C3TQ-010 null/miss no-op success behavior.
- [x] Apply C3TQ-011 old DamageNumber deletion order.
- [x] Apply C3TQ-012 Human/style branch.
- [x] Apply C3TQ-013 DamageNumber registration/timer/update/invalidate order.
- [x] Apply C3TQ-014 duplicated membership-query policy.
- [x] Apply C3TQ-015 HitBar delete/create policy.
- [x] Apply C3TQ-016 local negative-action Bow tick path.
- [x] Apply C3TQ-017 unseeded nested packet exact fields.
- [x] Apply C3TQ-018 legacy damage discard/HitBar-only behavior.
- [x] Apply C3TQ-019 legacy signed action arithmetic.
- [x] Apply C3TQ-020 unconditional true/no-hardening behavior.
- [x] Update UID0003TQ to `92/94` with retained metadata and Destination 1.
- [x] Update UID0003TQ Item Summary exactly.
- [x] Preserve complete MapPane formal unchanged and add target prose only.
- [x] Update MapPane file route without score/formal inflation.
- [x] Update UID0001AW inventory while preserving false/blank aggregate state.
- [x] Add target predecessor ignored row and preserve target successor ignored row.
- [x] Create/register `[0x00538d00,0x00538d10)` first as UID0004SJ.
- [x] Create/register `[0x00539230,0x0053935e)` second as UID0004SK.
- [x] Create/register `[0x005a8fc0,0x005a8ff2)` third as UID0004SL.
- [x] Create/register `[0x005adba0,0x005adbdc)` fourth as UID0004SM.
- [x] Replace every UID0004SJ pre-registration token after registration.
- [x] Replace every UID0004SK pre-registration token after registration.
- [x] Replace every UID0004SL pre-registration token after registration.
- [x] Replace every UID0004SM pre-registration token after registration.
- [x] Confirm zero temporary UID tokens remain before cross-linking completion.
- [x] Install Destination 2 IsGroupMember formal exactly.
- [x] Install Destination 3 AdvanceMovementSendTick formal exactly.
- [x] Install Destination 4 Bow setter formal exactly.
- [x] Install Destination 5 Damage constructor formal exactly.
- [x] Rebase/install complete Destination 6 UserPane class block with only two declarations added.
- [x] Install complete Destination 7 BowGaugeObjectPane class block.
- [x] Install complete Destination 8 DamageNumberObjectPane class block.
- [x] Update UserPane file/UID0001KL/UID0001KM inventories without score inflation.
- [x] Update Bow class/file scores and preserve singleton/resource/vtable/timer/compositor facts.
- [x] Update Damage class/file scores and preserve Attached/HitBar/ObjectInfo sibling union.
- [x] Update UID0001DB inventory without aggregate score/reconstructability/C++ change.
- [x] Add all eight exact new ignored padding rows with hashes.
- [x] Preserve compiler pool/EH/vptr/deleting/vtable/adjustor exclusions.
- [x] Preserve UID0003TH and UID0003TO bodies and generated uniqueness.
- [x] Preserve UID0004QN, UID0004R9, LivingObjectPane, ObjectList, TimerMgr, Config, and g_useEpfAssets facts.
- [x] Preserve the current B001/B002/B003/B004/B005/B011 shared MapPane/UserPane/Attached union without loss.
- [x] Scoped-validate every changed ordinary page while its lease is active.
- [x] Record each validator command id/timestamp/exit/ok/warnings/side effects.
- [x] Release each ordinary lease immediately after its edit/validation window.
- [x] Run historical B004 target `--wait-generated` command 13612 and reconcile its proof against current read-only command/header 13645 without running a new validator.
- [x] Verify current command 13645 has exactly one UID0003TQ definition and zero target Empty Emitter Marker.
- [x] Verify current command 13645 has one definition per real-UID new child, zero corresponding marker, 80/80 qualified MapPane names with 78 non-constructor/destructor definitions, and no duplicate class/body emission.
- [x] Verify nested packet byte zero remains unseeded in generated target source.
- [x] Verify no explicit pool/vptr/EH/deleting/vtable/adjustor handwritten source.
- [x] Preserve historical B004 manual commands 13613/13614/13615 and reread current supervisor-applied by-memory/by-class/by-file rows after commands 13646/13647/13648.
- [x] Confirm supervisor-applied manual rows and retained handoff text use real UIDs with zero pre-registration placeholders.
- [x] Preserve exact manual replacement/insertion text as historical supervisor-applied evidence.
- [x] Update C3TQ-001..046 to legal terminal callback states with destination proof.
- [x] Update Validator Results, Changed Files, current-union hashes, executed B001/B002/B003 coordination anchors, generated assertions, manual no-delta proof, and lease proof.
- [x] Check implementation rows only when independently true.
- [x] Confirm no ordinary implementation item remains.
- [x] Confirm zero B004 ordinary leases remain after each historical edit/validation window; final `current_leases.md` readback has zero B004 rows. The bounded current-union report-only rebase used no lease.
- [x] Confirm no manual coverage/generated/tracker/audit/supervisor/validator-state/IDA file was manually edited.
- [x] Confirm no report execute/status/count/probe/revalidation/move/archive/lifecycle command was run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000013653","destination_path":"executed-b-agent-research/B004/0003TQ-MapPaneHandleActionPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003TQ-MapPaneHandleActionPacket-source-quality.md","timestamp":"2026-07-16T04:33:33-04:00","uid":"0003TQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
