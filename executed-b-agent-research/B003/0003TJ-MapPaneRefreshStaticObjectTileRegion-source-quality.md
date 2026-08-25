** TARGET-REPORT-UID:0003TJ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003TJ MapPaneRefreshStaticObjectTileRegion Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented recommendation: UID0003TJ is the exact private `MapPane::RefreshStaticObjectTileRegion(const MapRect &tileBounds)` method at `91/94` with formal destination R1 installed.
- Final disposition: source-authored MapPane method. The IDA `__userpurge` EDI parameter and EAX pointer return are decompiler artifacts; the source ABI is a `void __thiscall` method with one explicit rectangle-reference argument.
- Callback result: C01-C20 and R1-R7 are implemented; validator command `000000013520` registered exact ObjectList child `0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt` as UID0004SI, while the other three UID0001D3 split candidates remain preserved.
- Confidence: very strong for behavior, ABI, range, ownership, call flow, six-byte tile view, object lifetime, and formal source shape; exact private lexemes remain inferred and cap confidence at `94`.
- Current-union rebase: executed B001 UID0003TP and final executed B002 UID0003TS are incorporated without loss in the shared index/class/file, command-13645 generated output, and commands-13646-13648 manual coverage. B003 target/support pages and R1-R5/R7 remain byte-identical; R6 survives at same-or-greater detail under only the accepted UID0003TX and UID0003TS deltas.

## Supporting Research

- Direct-report duplicate search found no UID0003TJ report in active research, `executed-b-agent-research`, `archived`, `Older-Research`, or `SpecialReports`; existing reports are support leads only.
- Relevant executed B001 `0001AW` continuation reports created UID0003TI/UID0003TJ and established the MapPane child boundaries, but left both formals blank and retained provisional helper/type names.
- Relevant executed B011 UID0003TL proves the opcode-`0x06` writer and two calls at `0x00510e28`/`0x00511318`; its six-byte `MapPaneTileRecord` evidence is retained.
- Relevant executed B005 UID00037Y and UID000425 reports established the tile helper and collision consumer. Their historical 12-byte `MapTileLayerIds` declaration was contradicted by the evidence-time live disassembly and is corrected in the applied current union without discarding their movement policy.
- Relevant executed B006 UID0001D3 proves ObjectList ownership, exact helper range `0x00532eb0-0x00532f67`, surrounding padding, and child-only aggregate policy; this direct target pass resolves its formerly open coordinate order and source name.
- Relevant StaticObjectPane reports prove `+0x128` is the subclass static-object id, the `0x12c` allocation, the scalar deleting wrapper/pool lowering, and three compiler-generated vtable views. They are revalidated support, not inherited conclusions.
- Searches used exact terms `0003TJ`, `0x0050f130`, `0x0050f26d`, `MapPaneRefreshStaticObjectTileRegion`, `sub_50F130`, `0003TI`, `0x00532eb0`, `ObjectListFindObjectAt`, and `GetLegacyAwareMapTileLayerIds`.
- Root outcomes: `executed-b-agent-research/**` had target-specific B001/B002/B005/B006/B007/B010/B011 leads; `archived/**`, `tools/leaser/Agents/Older-Research/**`, and `tools/leaser/Agents/SpecialReports/**` had zero matches for every exact term. Active `tools/leaser/Agents/**` matches were supervisor/audit/tracker assignment records plus unrelated current MapPane support reports, not substitute direct research.
- Current-union report reread captured executed B001 UID0003TP at `executed-b-agent-research/B001/0003TP-MapPaneHandleObjectWorldMapCreationPacket-source-quality.md`, SHA `089014A525DD1EE3A4E945D54768416F8082157802924116278EE5587AAA6C62`, 124,989 bytes/1,118 lines, with validator-owned execution command 13641; and executed B002 UID0003TS at `executed-b-agent-research/B002/0003TS-MapPaneHandleAnimationSoundPacket-source-quality.md`, SHA `6C57AAEF2F4DBEBA621D2A1A9F7CDCBB6FF0D828A93ECFF3E70828A3B61973DF`, 108,182/1,394, with final execution command 13651. The current active B004 UID0003TQ artifact is `1EB92F1C70A0A6C90BFF9C0E1BE605BF7E296981EC79CF1024ABA3DF879F597C`, 108,975/1,138; current B005 UID0003TK is `67A6ABF7EDBF362FF3105815528E107D258D5B658A7D616BB639FA3B70F3E13F`, 102,240/860. Earlier executed B002/B004 and evidence-time artifacts remain historical support. B003 changed none of these reports; exact paths and validator-owned footers are lifecycle authority.

## Target

- Target UID: `0003TJ`.
- Target path: `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`.
- Source queue/report row: tracker `by-memory -> Not-Covered Files - Reconstructable`; direct report count was zero at assignment.
- Implemented callback classification: accepted report research incorporated into the bounded ordinary destinations; report validation/execution/count/path/move/archive state remains external supervisor/validator-owned.
- Implemented scores and parent state: `91/94`, owner/emitter UID00007Q MapPane, reconstructable true, blank optional position, R1 formal, `Nested:0`; class UID00007Q remains `93/94`, file UID0000L3 remains `92/92`.

## Current Target State

- Implemented metadata and route are exact; final callback target SHA256 is `078D87D1FEB3CEAF09AEE82E067B77031A16E1BBBBF05BC26738B9F438A483B5`, 14,270 bytes, 160 lines.
- Current captured ordinary target/support snapshots, reread after executed B001 UID0003TP and final executed B002 UID0003TS:

| Path | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md` | `078D87D1FEB3CEAF09AEE82E067B77031A16E1BBBBF05BC26738B9F438A483B5` | 14,270 | 160 |
| `by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md` | `0DECF5F48B720E01BC392D0CFA1B9EC473A4F7F89C2D0418ABF73A0688195D8D` | 11,087 | 138 |
| `by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md` | `41B2636071239F4F2EFB7BF19577FA8109DE3AF4D0862000B6784B3141E93787` | 9,519 | 108 |
| `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md` | `8F919A95D54C9FEDAB46877FB7690D53ABF6C0069863968BFC02801ECB391458` | 23,983 | 151 |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `4241D9B3BA6432D9291DBE3686A13E2E89F2446BAE1797C06811767A83C57111` | 97,479 | 390 |
| `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md` | `E7B3E2E369F384003BC30FA2A93324A125D1386799FA0FBA1D547F324A047E3E` | 9,949 | 96 |
| `by-class/MapPane.md` | `A076D4E350565BAD1EADF679A93E9E908CB0F321EAF11710B16FC580E7F1375C` | 178,762 | 985 |
| `by-file/MapPane.md` | `978C6CD6F6309E86007DD77D39788A1C063F998D16A060C0C55D2BBB479959A5` | 180,600 | 744 |
| `by-class/ObjectList.md` | `812673D1AF24712C765A68E8D8E7A21D0ACA7588CC2B1B431B318FCC88DBD2C2` | 53,602 | 371 |
| `by-file/ObjectList.md` | `901DE1AA6201D8EC1842BC1213C7D5646ACCD5A46AE9F6F2FF05DBF7771B00E1` | 52,729 | 298 |
| `by-class/StaticObjectPane.md` | `23419D4A95AF7149E835E82941F83FE65181E28290EF012963BBDB61DF9898FE` | 15,522 | 120 |
| `by-file/StaticObjectPane.md` | `16DCA9BAA1D1EA16C98633315A174E517D0837576A5D4BF6A311E07062DFA80B` | 15,698 | 83 |
| `by-type/by-struct/MapPaneTileRecord.md` | `E8EE4EE9C74FA3230C2676FFE3AC12CAEA573B991DD547C1025F28E523E16524` | 7,268 | 72 |
| `by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md` | `AE1685AA2255019B4B887CDBCF8594F03D98B86D4466D8F15C2B2D25D810BCDB` | 17,832 | 242 |
| `by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md` | `A1E2A58BC9ECF985FEA5E33BAA8D0404A52A18E748E75C0238DB44D2BB00BB32` | 21,901 | 385 |
| `by-memory/0x00512840-0x0051289f.MapPaneHandlePursuitMessageDialogPacket.md` | `767AB18D60C12CADE0D78CCF65F2133DD279B9170271FD54BF77C7F642FAC4A6` | 8,608 | 96 |
| `by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md` | `9195485399E2C8B271478A761605C695023D7470A19B4C3817A007C0268B5A50` | 21,028 | 330 |
| `by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md` | `49D86F96448F8A38C2E3BE95A17F7996016E07CC84CE3C5481381A643535C083` | 5,652 | 74 |
| `by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md` | `D21F2097555F89DD930C0224AB52862725CF86E1C6FE41AC4C5F8EF41081A52D` | 8,480 | 131 |
| `by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md` | `49381B23F0BE3CACF4071834AD579D2A5EBA4413A541EE16025A7D3A72D67095` | 6,197 | 84 |
| `by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md` | `9B945CFFCD60859A8CFEACDAF14F6CBEA2A14F9BE98F5E136C193FD7A6393E8E` | 6,132 | 85 |

- Historical pre-callback generated checkpoint: external command/header `000000013515`, refreshed `2026-07-15T21:17:18-04:00`, still had the UID0003TJ/UID0000E1 Empty Emitter Markers and omitted the new source definitions. It is retained only as the before-state.
- Historical B003 waited callback checkpoint: validator command/header `000000013536`, refreshed `2026-07-15T22:16:44-04:00`, proved the accepted callback before later shared-lane additions. Its hashes and exact validator result remain preserved in Validator Results, but it is not asserted as the current generated epoch.
- Historical external B005 checkpoint: command/header `000000013546`, refreshed `2026-07-15T22:44:53-04:00`, was the valid interim SHA `33185FED...A95C7` evidence epoch. Its generated hashes were MapPane `ABA0B325...E604`, ObjectList `2CC9C3B9...6D43`, and StaticObjectPane `48F5D990...0B53`; it is retained as the post-B005/pre-B004 history rather than asserted as the final captured epoch.
- Gate-2 accepted generated checkpoint is external B004 command/header `000000013552`, refreshed `2026-07-15T23:04:53-04:00`. `MapPane.cpp` was SHA256 `3B36D303F2695234A21E2B08A54460D669D364DD927C90BC3D48AC8674622E9F`, 113,618 bytes, 3,366 lines; `ObjectList.cpp` is SHA256 `CE74F59536ECBDE973D4889610B8879C34B25AD0FED65C410A6C94E35C79EFEF`, 30,650 bytes, 951 lines; `StaticObjectPane.cpp` is SHA256 `3B2F2BAB6926DBB92553DBDCDB3A484D877E504A7090A684181C4309D8C64235`, 3,777 bytes, 107 lines. This exact checkpoint remains the accepted generated proof; it is no longer presented as the latest filesystem header.
- Command 13552 closed MapPane at line 328 and had 76 uniquely named qualified definitions: `UID:0003TI`/definition once at lines 2681/2682, `UID:0003TJ`/definition once at 2714/2715, B005 UID0003TK/definition once at 2764/2810, and B004 UID0003TO/definition once at 3114/3115. ObjectList closed at line 73 with 31 unique qualified definitions and UID0004SI/definition once at 694/695. StaticObjectPane closed at line 33 with all six accepted source definitions once. Target, sibling, new child, UID0000E1, and UID0003TO had zero Empty Emitter Markers; the nine MapPane and one ObjectList markers that remained were unrelated support debt.
- Historical post-coverage/pre-B002 generated state: external deferred-refresh header command `000000013559`, refreshed `2026-07-15T23:50:27-04:00`, had MapPane SHA256 `57269325A1A9C72B308BE970AF875FC91EBE73378EF5D686D0657F8B2307364B`, 118,968 bytes/3,550 lines and preserved every B003 scoped assertion. It is retained as the immediate pre-B002 generated epoch, not asserted as current.
- Historical terminal-B002 generated state is command/header `000000013588`, refreshed `2026-07-16T00:09:40-04:00`; it preserved all B003 scoped assertions before the later B004 UID0003TQ callback and is no longer presented as current.
- Historical B004 generated checkpoint: command/header `000000013612`, refreshed `2026-07-16T01:18:34-04:00`, established the pre-B001/B002 shared baseline recorded in the earlier artifact. Its hashes/counts remain historical and are no longer asserted as current.
- Current read-only generated state is final waited command/header `000000013645`, refreshed `2026-07-16T03:09:31-04:00`, exit `0`/ok `1`. `MapPane.cpp` is SHA256 `B4D6F013338AC0B013C6100BE60036572537F44761C9A39C290F4F13AD419EA3`, 138,106 bytes/4,132 lines; `ObjectList.cpp` is `2D73464A9D67A4E80ED95E6DF7BBF8DEADBC1132413FD51D962AC069C3E26768`, 30,650/951; `StaticObjectPane.cpp` is `6DEFDAE58E1BBBF2ADC4D9CDE34D65F03A947AEA4793E7DD9EA53F7B1AD6D635`, 3,777/107; `UserPane.cpp` is `390FDEA85F3999182CC4781FE17511E8F39D8C33967D01A53861D257F3547CEE`, 91,175/2,723; `BowGaugeObjectPane.cpp` is `99FD52CAFF19E0D75605D68F1745817EF4EF09DD4C2CD7ABCBFEBE39417E6087`, 2,205/49; and `AttachedObjectPane.cpp` is `1FEA2686B2D4EA2E112FC874943F321EC570612449A3875FCBACC6D630F2A491`, 10,901/288.
- Command 13645 closes MapPane at line 322 before the first qualified definition at 328 and has 80 total qualified MapPane definitions / 80 unique qualified names, of which 78 are non-constructor/destructor definitions. UID0003TI/definition remains once at 2710/2711 and UID0003TJ once at 2743/2744; UID0003TX is 2792/2795, UID0003TK 2924/2970, UID0003TO 3274/3275, B001 UID0003TP 3318/3319, UID0003TQ 3581/3582, B002 UID0003TS 3718/3737, UID0003TW 4013/4014, and B001 UID0004SN 4036/4037. B003 target/sibling markers remain zero. Five MapPane Empty Emitter Markers remain, all unrelated UIDs 0004DS/00037T/0003TN/0003TT/0001SO; target-scope handwritten vtable/RTTI/cookie/EH/scalar-wrapper text remains zero. UID0004SI remains once at ObjectList 694/695 with one unrelated marker. StaticObjectPane retains six unique definitions at lines 45/51/56/63/68/95 and zero marker. UID0004SJ/UID0004SK/UID0004SL/UID0004SM each remain one annotation/definition with zero corresponding marker in their generated owner file.
- Complete no-loss shared-union survival after B001 UID0003TP and B002 UID0003TS: UID0001AW at `4241D9B3...7111` / 390 lines preserves B003 UID0003TI/UID0003TJ, B002 UID0003TW/UID0003TX, B005 UID0003TK, B004 UID0003TO/UID0003TQ plus UID0004SJ-UID0004SM, B001 UID0003TP/UID0004SN, B002 UID0003TS, every unrelated child, padding span, retained raw helper, and source/compiler disposition. MapPane class at `A076D4E3...375C` / 985 lines retains every B003 six-byte `MapTileLayerIds`, `CreateStaticObjectPaneForTile`, `RefreshStaticObjectTileRegion`, size guard, class closure, and `[[CHILDREN]]` fact. Its current managed SHA is `E41EBEDD2A34A3F7CB5E37197941E08A1683FD1751F04D244C530D1BE773A5E5`: relative to accepted B003 R6 `7D6432B6...09C48`, only the accepted UID0003TX factory/ItemObjectImageEntry correction and UID0003TS replacement of three stale map-display fields with `m_zoneMusicId`, `m_zoneMusicFallbackTrackIndex`, and `m_zoneMusicVolumeScale` differ; B001's already-declared UID0003TP route and all B003 lines remain in order. MapPane file at `978C6CD6...59A5` / 744 lines retains B003 static-object history and all prior cross-agent routes while adding B001 world-map/Pursuit and B002 sound-packet source facts. R1-R5 and R7 remain byte-identical to current destinations; accepted R6 survives at same-or-greater detail under those bounded accepted deltas.
- B004 report `tools/leaser/Agents/Agent-B004/research/0003TQ-MapPaneHandleActionPacket-source-quality.md`, SHA256 `E81D0DC0022249DD5B4683BD886FD8E79F951ADABA90ADA80C53467346F30A5E`, 107,688 bytes/1,138 lines, is retained as an evidence-time coordination artifact whose exact artifact passed written Gate 1 and independent ordinary Gate 2; B004 manual reconciliation and final lifecycle remained supervisor-controlled at the B003 evidence read. The direct ordinary/generated/manual reads above, not mutable report lifecycle state, establish this durable current-union snapshot.
- Stability proof: the twelve changed ordinary destinations, three generated outputs, and four manual files were identical across reads at `2026-07-15T23:28:23.4505600-04:00` and `2026-07-15T23:28:36.4153354-04:00`, aggregate fingerprint `C1D5B044E1D950D094DCA04397E4DE641F32CF366D494569A2DB045FAC53E841`. A broader pair including verify-only UID0004HP, B004 UID0003TO/UID0004Q9, and the externally executed B004 report was identical at `2026-07-15T23:29:32.5624894-04:00` and `2026-07-15T23:29:43.1294241-04:00`, fingerprint `5AF36D16F85BA7FB929DE4CADAAF5B43FDF3FD13560B6CE947CC7AF566BA3DFB`. The B004 artifact is externally lifecycle-closed at `executed-b-agent-research/B004/0003TO-MapPaneHandleObjectMoveEffectPacket-source-quality.md`, SHA `AC0096CB...2D63`, 77,831 bytes/620 lines, with supervisor command 13556 at `2026-07-15T23:26:51-04:00`. No active B003, B004, or B005 lease was present.
- Historical pre-coverage cross-agent stability proof: all twelve changed ordinary destinations, three generated outputs, four manual files, the three relevant executed B002 artifacts, executed B004 UID0003TO, and evidence-time terminal B005 UID0003TK were byte/metric/last-write identical at `2026-07-15T23:44:20.3595978-04:00` and `2026-07-15T23:44:32.9807578-04:00`, aggregate fingerprint `46168E084F18A7D5C35F1786DC49377F820AA59BBA9DC11C077108B48B0A55E0`. It is retained as historical proof, not current-union evidence.
- Historical post-B002-UID0003TX/pre-B004 stability proof: all twelve B003 ordinary destinations, terminal B002 UID0003TX report SHA `E48D1FA1...D7BE`, three evidence-time generated outputs, four evidence-time manual files, and the lease file were hash/byte/line/last-write identical at `2026-07-16T00:26:35.4438723-04:00` and `2026-07-16T00:27:00.8783747-04:00`. It remains historical proof only.
- Current stability proof: the two executed B001/B002 archives, all B003 target/support destinations, the three shared MapPane ordinary pages, relevant generated outputs, four manual roots, and the lease report were identical across direct reads at `2026-07-16T03:49:35.7577295-04:00` and `2026-07-16T03:49:39.3809331-04:00` (`23` files, zero differences). `current_leases.md` contained no active leases.
- The formerly open rectangle/tile/output/helper/object-field names, IDA EDI/return artifacts, private access, ObjectList lookup source shape, and sibling creation source shape are resolved and incorporated.
- Historical artifact location: this B003 research/implementation-callback path before external supervisor lifecycle. B003 performed no report execution, probe, count, move, archive, or lifecycle command; external lifecycle state is neither asserted nor directed here.

## Executive Recommendation

- Keep owner/emitter UID00007Q and source placement `NexusTK/map/MapPane.cpp`.
- Raise target to `91/94`; retain exact range, true reconstructability, blank position, and `Nested:0`; install R1.
- Raise sibling UID0003TI to `90/93` and install R2 because this pass resolves its parameter order, return type, metadata fields, bounds-call disposition, pool lowering, placement, refresh, and insertion behavior.
- The callback split/registered only the source-ready `0x00532eb0-0x00532f67` helper as UID0004SI `ObjectList::FindStaticObjectPaneAt`, `90/93`, owner/emitter UID00009Q, blank position, `Nested:0`, formal R3. UID0001D3's ShiftAll/DetachAll/Prune candidates remain documented future children.
- MapPane's `MapTileLayerIds` view is corrected to three unsigned 16-bit fields and UID000425's source use is synchronized from stale `objectNation`/`0x10000` expressions to `staticObjectId`/flag bit `1` without changing movement behavior.
- Complete StaticObjectPane's class declaration so `GetStaticObjectId()` is a natural inline accessor and compiler-generated scalar deletion/vtables remain compiler output.

## Supervisor Active Recheck

- Historical Gate 1 authorization boundary: the assignment required direct report-only UID0003TJ research with mandatory healthy MCP and forbade by-* implementation before exact-artifact acceptance; the supervisor subsequently accepted SHA `7FB957C253861AD0DE9427B65BB86DA4607C4D15F1C0F6BB178116DDFE06A626` and authorized this completed callback.
- Split repair is triggered only for the exact ObjectList lookup helper needed by R1. The target itself is already an exact child and must not be split.
- Every source-bearing dependency required to express R1 has either complete destination code in R1-R7 or an already-present source API. Verify-only dependencies are listed explicitly; no blocker is deferred to a separate target.

## Inference Research Guidance Check

- Binary facts are separated from source inference: addresses, bytes, stack cleanup, field offsets, branch order, xrefs, and vtable calls are direct; names such as `FindStaticObjectPaneAt` and `skipListInsertion` are descriptive source-facing inferences.
- Existing documentation was treated as fallible. The mandatory evidence-time MCP pass rejected the old `int@edi` source argument, pointer return, 12-byte tile view, "rectangle normalization" claim for `0x004b7eb0`, and generic `FindObjectAt` ambiguity.
- `by-structure.md` requires exact child ownership: UID0001D3 remains a routing aggregate; only UID0004SI owns the lookup body.
- No Wave2/Wave3 evidence was used. No matching stale artifact was found in the required older/special roots.

## Heuristic / Inference Reanalysis And Validation

- ABI: `retn 4` at `0x0050f26a` proves one explicit stack argument. Every caller pushes one rectangle pointer and sets ECX. EDI is loaded from `tileBounds.left` inside the target, not supplied by callers. EAX merely retains the input pointer and every caller ignores it. Resolution: `void MapPane::RefreshStaticObjectTileRegion(const MapRect &)`.
- Rectangle math: loads are `left +0`, `top +4`, `right +8`, `bottom +0xc`; outer loop advances row/top, inner loop advances column/left, both stop on `<` right/bottom. Resolution: half-open row-major traversal.
- Tile output: `0x0050c120` copies one dword plus one word. The dword is the first two words of the live six-byte tile record; the last word at `+4` is the static-object id. Resolution: `MapTileLayerIds` is `{ unsigned short groundTileId; unsigned short flags; unsigned short staticObjectId; }`, not three dwords.
- Collision consequence: UID000425's former `objectNation` is the same static-object id used to index `g_objectNationMap`; former `flags & 0x10000` is the first bit of the 16-bit flags word. Resolution: preserve exact policy using `.staticObjectId` and `(nextTile.flags & 1) == 0`.
- Object lookup: `0x00532eb0` indexes `m_staticObjectRows` (`ObjectList+0x28`) by `tileY - paddedBounds.top`; `GetMapPosition` writes row/Y at `+0`, column/X at `+4`; comparison is column to first argument and row to second. Resolution: `StaticObjectPane *ObjectList::FindStaticObjectPaneAt(int tileX, int tileY)`.
- Object field: `StaticObjectPane+0x128` is a 16-bit id from its constructor and all image-library consumers. Resolution: inline `GetStaticObjectId()` in a complete class declaration; no raw offset or friendship-only field access in R1.
- Lifetime: both stale/nonzero and zero-id branches call GetBounds, MapPane invalidation, ObjectList removal, conditional backing-store release, then scalar deleting virtual dispatch with flag 1. Resolution: source `delete existingObject`; no explicit vtable, scalar flag, pool free, or base destructor call.
- Retention: if the tile id is nonzero and matches the existing pane id, the target continues without invalidation, removal, refresh, or replacement.
- Replacement: if nonzero and no matching pane remains, target calls sibling with `(tileX, tileY, staticObjectId, false)`. The sibling allocates/constructs through ordinary `new`, attaches optional lighting, updates screen bounds, and adds to ObjectList unless suppressed.
- Sibling bounds call: `0x004b7eb0` is the accepted `IsRectEmptyOrInvalid` predicate and its return is discarded at `0x0050f07e`; "normalizes the rectangle" is rejected stale. R2 retains the standalone call because removing it changes an observable external call even though the result is unused.
- Static class historical pre-callback state: six qualified definitions and a class-owned vtable route coexisted with the UID0000E1 Empty Emitter Marker, proving that a complete declaration was necessary. Current applied disposition: UID0000E1 is `90/92`; R4 declares all accepted methods, an inline empty virtual source destructor, private packet helper, 16-bit field, and `0x12c` size guard; current command-13645 output retains the six source definitions with zero StaticObjectPane marker, while compiler lowering regenerates wrappers/tables.
- Rejected alternatives: StaticObjectPane ownership, ObjectList ownership of the target, StaticObjImageLib ownership, file-level target, extra EDI parameter, pointer return, inclusive rectangle edges, generic object-row lookup, raw `+0x128` access, explicit deleting-destructor calls, and aggregate ObjectList body emission.
- Remaining inference: exact private method lexemes are not symbol-recovered. All types, order, ownership, and behavior are closed; lexical uncertainty only caps confidence.

## Evidence Standards Used

- Direct evidence: MCP `idb_list`, `server_health`, `get_bytes`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, caller windows, vtable slots, stack cleanup, and field offsets.
- Corroboration: current by-memory/class/file/struct docs, current generated C++, exact historical reports, manual coverage, and address-sorted nesting.
- Negative evidence: no extra pushed target argument, no caller use of EAX, no absolute/pointer route changing ownership, no raw target split, no handwritten RTTI/vtable need, and no older-root direct report.
- Evidence is sufficient for source-ready code. Confidence remains below symbol-level certainty only because original private names are inferred.

## Evidence Checked

- At evidence-collection time, fresh MCP `idb_list` returned database `64c11373`, `NexusTK.exe.i64`, worker PID 21508; `server_health` returned `status:ok`, imagebase `0x400000`, analysis/Hex-Rays/strings ready, cache size 2067. This captures the mandatory healthy evidence pass and does not assert indefinite later session availability.
- A bounded `get_bytes` at `0x0050f130` returned `55 8b ec 83 ec 40 a1 24 2f 67 00 33 c5 89 45 fc`; full target bytes hash to `BA72395C83D7DCE141FE285CABDE26024E026AB464934777E9FFA1F1891C70B8`.
- Target analysis: size `317/0x13d`, 112 instructions, 20 blocks, complexity 11, four callsites, six direct callees, exact `retn 4`.
- Helper analysis: `0x0050c120`, `0x0050f030`, `0x00532eb0`, `0x00531c10`, `0x004b97d0`, StaticObjectPane constructor/core/destructor/vtable, and all four target caller windows.
- Docs checked: UID0003TJ, UID0003TI, UID0001AW, UID0003TL, UID00037Y, UID000425, UID0001D3, UID0001D2, UID00023F, UID00007Q, UID0000L3, UID00009Q, UID0000M4, UID0000E1, UID0000O6, UID0001D6, UID000388, UID00034X, UID0004HP, UID0004R0, ObjectPane, List, StaticObjImageLib, Rect/MapPoint support.
- Historical Gate 1 destination diff: UID0003TJ/UID0003TI/UID0000E1 were blank formal destinations that R1/R2/R4 now complete; UID0004SI did not exist before command 13520 registration; R5 preserves every prior ObjectList line and adds only the StaticObjectPane forward declaration plus typed lookup; R6 preserves every prior MapPane declaration including the unsigned-short CreateHitBarObjectPane contract and changes only the six-byte tile view, required forward declarations, and typed creation helper; R7 differs from pre-callback UID000425 only by the evidence-proven staticObjectId names and 16-bit flag-bit expression.
- Generated read-only checks: historical external command 13515 establishes the pre-callback marker baseline; historical B003 command/header 13536 proves the accepted implementation; commands 13546/13552/13559/13588/13612 and B001 command 13636 remain ordered historical checkpoints. Final B002 waited command 13645 is the current read-only epoch. Every B003 scoped definition, marker removal, class order, and compiler-code exclusion survives alongside B001 UID0003TP/UID0004SN, B002 UID0003TS, B004 UID0003TQ/UID0004SJ-UID0004SM, and the earlier shared union.
- Post-B001/B002 shared-union readback: UID0001AW is `4241D9B3...7111` / 390 lines, MapPane class is `A076D4E3...375C` / 985, and MapPane file is `978C6CD6...59A5` / 744. The current union preserves all B003 UID0003TI/UID0003TJ and prior B002/B004/B005/B011 facts while adding B001 UID0003TP/UID0004SN and B002 UID0003TS without loss. R1-R5/R7 independently match their destinations exactly. R6 remains unchanged in this accepted report; current managed SHA `E41EBEDD...A5E5` differs only by the accepted UID0003TX factory/ItemObjectImageEntry correction and UID0003TS three-field replacement, with every B003 line not superseded by those bounded corrections preserved in order.
- Manual coverage was reread after the external supervisor applied the complete B001/B002 no-loss union with by-memory command 13646, by-class command 13647, and by-file command 13648. Current hashes are memory `15503038...2D93`, class `9D42F839...A391`, and file `C2A5EC49...BC17`. The union retains B003 UID0003TI/UID0003TJ/UID0004SI, corrected UID000425/UID0001D3, ObjectList/StaticObjectPane facts, and all prior B002/B004/B005/B011 content while adding B001 UID0003TP/UID0004SN and B002 UID0003TS plus their exact class/file support. No B003 manual delta remains. No current by-struct change is triggered; direct read-only comparison confirms UID0004HP remains unchanged at line 71, SHA `C0FA7E9B...F873`, from command 13592. Commands 13613-13615 and 13638-13640 remain historical pre-B001/pre-B002 manual epochs; B003 made no manual coverage edit or validation command.
- Intentionally skipped throughout: IDA mutation, broad MCP enumeration, execute/report lifecycle/probe commands, manual coverage edits, and direct generated edits. The authorized callback used only scoped ordinary validators and one waited generated refresh.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | MCP session `64c11373` was healthy for evidence collection. | direct | idb_list, health, bounded bytes | target Evidence/Changes | incorporate | applied | UID0003TJ evidence records the evidence-time database, health readiness, bounded bytes, analysis, and hashes; command 13522 validated the destination. This is a durable evidence-time fact, not an indefinite active-session assertion. |
| C02 | Target is exactly `[0x0050f130,0x0050f26d)`, 0x13d, hash stated above. | direct | analysis/full bytes | UID0003TJ range | incorporate | applied | UID0003TJ records exact end-exclusive range, `0x13d`/317-byte size, SHA256 `BA7239...70B8`, predecessor/successor padding, and command 13522 exit 0/ok 1. |
| C03 | ABI is void thiscall with one `const MapRect &`; EDI/EAX are artifacts. | very strong | retn 4 and four callers | UID0003TJ/R1/MapPane | reject-stale | applied | UID0003TJ and UID00007Q carry the one-argument declaration/body and four-caller/`retn 4` proof; R1 and accepted B003 R6 matched at commands 13522/13529. Current class hash `A076D4E3...375C` preserves this exact declaration/body; managed SHA `E41EBEDD...A5E5` differs from accepted R6 only by the separately accepted UID0003TX factory/ItemObjectImageEntry correction and UID0003TS three-field replacement. |
| C04 | Iteration is row-major and half-open top/bottom, left/right. | direct | target disassembly | UID0003TJ behavior | incorporate | applied | UID0003TJ Item Summary/evidence/R1 preserve top-row then left-column nesting and strict `< bottom`/`< right`; command 13522 passed. |
| C05 | Tile helper output is six bytes/three words; +4 is staticObjectId. | direct | 0x50c120 stores and UID4HP | UID0003TJ/UID07Q/UID425 | reject-stale | applied | UID0003TJ, UID00007Q, UID0000L3, and UID000425 use three unsigned-short fields with `staticObjectId` at +4; commands 13522/13529/13530/13531 passed; verify-only UID0004HP remained unchanged. |
| C06 | UID000425 must use staticObjectId and 16-bit flag bit 1. | very strong | target/helper/collision disassembly | UID000425/R7 | incorporate | applied | UID000425 R7 exact hash `C81CC384...509D3` replaces only stale `objectNation`/`0x10000`; score/range/route remain unchanged; command 13531 exit 0/ok 1. |
| C07 | 0x532eb0 is typed static-row lookup with X/Y order closed. | direct | decompile, MapPoint, ObjectList layout | UID0004SI/R3 | incorporate | applied | Command 13520 issued UID0004SI; its exact page/R3 records `tileX,tileY`, pointer-slot List semantics, padded-row selection, callers, range/hash/padding, and command 13520 completed registration. |
| C08 | UID0001D3 remains aggregate; new child Nested is 0. | very strong | address-sorted parent/child deltas | UID0001D3/new child | incorporate | applied | UID0001D3 remains a child-only aggregate at `89/92`; UID0004SI is Nested 0, linked in exact order, and the other three future splits/padding remain. Commands 13520/13524 passed. |
| C09 | Matching existing id is retained with no update side effect. | direct | target branch | UID0003TJ/R1 | incorporate | applied | UID0003TJ behavior and R1 retain the immediate continue path with no invalidate/remove/refresh/replacement; commands 13522/13536 established the callback and historical commands 13546/13552/13588/13612/13636 preserved it. Current read-only command 13645 emits it once at line 2744. |
| C10 | Stale/zero objects follow exact invalidate/remove/release/delete order. | direct | two target branches | UID0003TJ/R1 | incorporate | applied | UID0003TJ documents and emits both duplicated GetBounds/invalidate/remove/conditional-release/delete sequences; no compiler scalar flag/pool call is handwritten. Commands 13522/13536 passed, later historical epochs preserved the body, and current command 13645 retains the exact one-definition body. |
| C11 | Nonzero missing/stale tiles call UID0003TI with final false. | direct | call at 0x50f1f8 | UID0003TJ/UID0003TI | incorporate | applied | R1 calls `CreateStaticObjectPaneForTile(tileX, tileY, staticObjectId, false)` and R2 matches; commands 13522/13523/13536 established the pair. Current command 13645 preserves UID0003TI at 2710/2711 and UID0003TJ at 2743/2744 once each. |
| C12 | UID0003TI source shape is typed creation/lighting/update/optional insertion. | very strong | sibling disassembly/support | UID0003TI/R2 | incorporate | applied | UID0003TI is `90/93` with full bounds/metadata/ordinary-new/lighting/update/skip-insertion flow and compiler exclusions; R2 hash `16D265...E065`; command 13523 passed. |
| C13 | IsRectEmptyOrInvalid return is discarded, not normalization. | direct | call/result disassembly | UID0003TI | reject-stale | applied | UID0003TI prose and R2 retain the standalone discarded predicate call and historicalize normalization; command 13523 passed. |
| C14 | StaticObjectPane id access is an inline source accessor over +0x128. | very strong | constructor/core/layout | UID0000E1/R4 | incorporate | applied | UID0000E1 is `90/92` with exact 0x12c class and inline accessor; UID0000O6 is `90/91`; R4 hash `E0829C...EF47`; commands 13525/13526 passed. |
| C15 | Scalar flags, pool free, vptrs, base teardown, cookies/EH are compiler-only. | very strong | destructor/vtable/sibling lowering | target/support negatives | reject-invalid | applied | All changed pages preserve source/compiler exclusions; historical B003 command 13536 and external commands 13546/13552/13559/13588/13612/13636 contain no target-scope handwritten lowering. Current read-only command 13645 likewise has zero target-scope handwritten vtable/RTTI/scalar-delete/EH/pool/cookie text. |
| C16 | Owner/emitter remains UID00007Q through UID0000L3. | very strong | receiver/state/caller family | target/class/file | already-present | already-present | UID0003TJ/UID0003TI keep owner/emitter UID00007Q; UID00007Q/UID0000L3 routes remain unchanged and commands 13522/13523/13529/13530 passed. |
| C17 | Scores become target 91/94, sibling 90/93, new child 90/93, parent 89/92, ObjectList class/file 91/93, Static class 90/92, Static file 90/91. | high | blocker closure | named destinations/manual rows | incorporate | applied | Every listed ordinary metadata score is present in the final snapshots and its scoped validator passed; MapPane/UID000425/UID0001AW scores remain unchanged as accepted. |
| C18 | R1-R7 are complete destination-specific source operations. | high | source model, latest formal rereads, and no-loss line diffs | formal destinations | incorporate | applied | Accepted report managed SHA256 values remain R1 `3E4B...78E0`, R2 `16D2...E065`, R3 `3940...B754`, R4 `E082...EF47`, R5 `8844...2DEE`, R6 `7D64...9C48`, R7 `C81C...09D3`; every B003 destination validator passed. R1-R5/R7 remain exact current parity. R6 survives at same-or-greater detail: current class file SHA is `A076D4E3...375C`, current managed SHA is `E41EBEDD...A5E5`, and direct comparison limits the difference to accepted UID0003TX factory/ItemObjectImageEntry corrections plus UID0003TS zone-music field replacements. |
| C19 | Generated refresh removes target/sibling/class markers and emits each body once without handwritten compiler data. | high | historical command 13515 baseline | waited/current MapPane/ObjectList/StaticObjectPane | incorporate | applied | B003 command/header 13536 established the callback; commands 13546/13552/13559/13588/13612/13636 preserved it. Current command 13645 preserves UID0003TI/UID0003TJ/UID0004SI once, class-before-children order, zero B003 scoped markers, 80 total qualified MapPane definitions / 80 unique qualified names, of which 78 are non-constructor/destructor definitions, no target-scope handwritten compiler arrays/wrappers, and the complete B001/B002/B003/B004/B005/B011 union including UID0003TP/UID0004SN/UID0003TS. |
| C20 | Manual coverage handoff uses fresh current read-only hashes and exact no-loss rows/anchors; B003 does not edit coverage. | direct | post-coverage snapshots and exact row rereads | three current post-B001/B002 manual destinations plus unaffected struct no-change proof | incorporate | applied | The current external supervisor-owned union is memory `15503038...2D93` from command 13646, class `9D42F839...A391` from command 13647, and file `C2A5EC49...BC17` from command 13648. B003 UID0003TI/UID0003TJ/UID0004SI, corrected UID000425/UID0001D3, ObjectList/StaticObjectPane facts, and all prior B002/B004/B005/B011 evidence survive while B001 UID0003TP/UID0004SN and B002 UID0003TS are added. Direct row comparison proves no B003 manual delta remains. UID0004HP remains unchanged at line 71 of `by-type/by-struct/-coverage-report.md`, SHA `C0FA7E9B...F873`, from command 13592. Earlier manual commands remain historical applied epochs. B003 made no manual coverage edit or validator call. |

## Positive Evidence Summary

- Four callers independently agree on one rectangle pointer and MapPane ECX.
- Target bytes, CFG, half-open loops, tile id read, static-row lookup, duplicated removal flow, and sibling call form one coherent method.
- Writer, loader, allocator, saver, tile helper, collision consumer, and target all agree on a six-byte three-word tile record.
- ObjectList `+0x28`, MapPoint row/column order, and target push order close lookup naming and signature.
- StaticObjectPane constructor and image consumers close the 16-bit id field and support a natural inline accessor.

## IDA MCP Facts

- Target: `sub_50F130`, `0x13d`, 112 instructions, 20 blocks, complexity 11, no strings.
- Xrefs: `0x00505be0`, `0x0050bff9`, `0x00510e28`, `0x00511318`.
- Callees: `0x0050c120`, `0x00532eb0`, `0x00531c10`, `0x004b97d0`, `0x0050f030`, security-cookie check.
- Padding: predecessor UID0003TI ends exactly at target start; target successor is three `0xcc` bytes `[0x0050f26d,0x0050f270)`.
- Lookup helper `0x00532eb0` size `0xb7`, hash `075E96489BF20C188C39662ED198FAD9DE004A24025CE02851AAAEEB432FAA3C`; xrefs `0x0050583e` and `0x0050f191`.
- Sibling `0x0050f030` size `0x100`, hash `B454298516F095896836E9FFEAEAA9D2B74AB672DABFBD07AE755E5226F5D497`; one caller at `0x0050f1f8`.
- Negative facts: no second explicit target argument; no returned pointer consumer; no raw vtable/RTTI source; no target data-pointer route requiring nonmember ownership.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050f030-0x0050f130` | UID0003TI MapPaneCreateStaticObjectPaneForTile | private creation helper | true | UID0001AW / UID00007Q | `90/93` implemented | source-ready R2 installed |
| `0x0050f130-0x0050f26d` | UID0003TJ target | private reconciliation method | true | UID0001AW / UID00007Q | `91/94` implemented | source-ready R1 installed |
| `0x0050f26d-0x0050f270` | UID0000VN ignored | `0xcc` padding | false | parent-only | n/a | preserve |
| `0x00532530-0x00532f67` | UID0001D3 | ObjectList aggregate/index | true | UID00009Q | `89/92` implemented | retained aggregate marker |
| `0x00532530-0x0053272e` | UID0001D2 | accessor child | true | UID0001D3 | `92/93` current | verify-only |
| `0x00532730-0x00532b72` | future ShiftAll child | shift helper | true | UID0001D3 | unresolved child | preserve future split |
| `0x00532b80-0x00532e11` | future DetachAll child | detach helper | true | UID0001D3 | unresolved child | preserve future split |
| `0x00532e20-0x00532eae` | future Prune child | prune helper | true | UID0001D3 | unresolved child | preserve future split |
| `0x00532eb0-0x00532f67` | UID0004SI ObjectListFindStaticObjectPaneAt | typed static-row lookup | true | UID0001D3 / UID00009Q | `90/93` implemented | validator-registered; R3 installed |
| `0x00532f67-0x00532f70` | UID0000VN ignored | `0xcc` padding | false | parent-only | n/a | preserve |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00505be0` | UID0002QM recenter/send | one pushed MapRect; post-position reconciliation |
| `0x0050bff9` | MapPane map/tile render path | one pushed MapRect; ECX is MapPane |
| `0x00510e28` | UID0003TL first region update | clipped packet rectangle, one argument |
| `0x00511318` | UID0003TL second region update | same ABI/order after alternate packet branch |
| `0x0050f178` | target -> tile helper | obtains six-byte remapped tile view |
| `0x0050f191` | target -> `0x00532eb0` | passes tileX then tileY to ObjectList |
| `0x0050f1cf`, `0x0050f220` | target -> RemoveObjectPane | stale and zero-id branches |
| `0x0050f1df`, `0x0050f230` | target -> ReleaseBackingStore | conditional non-static cleanup before delete |
| `0x0050f1f8` | target -> UID0003TI | tileX, tileY, id, false |

## Documentation Evidence And IDA Status

- Historical pre-callback UID0003TJ state: its range/route/padding and EDI correction were already correct, but its C++ was blank and its blocker prose remained provisional. Current applied disposition: UID0003TJ is `91/94` with exact R1, range/hash/ABI/behavior/evidence, command 13522 validation, and one command-13645 definition at line 2744 with zero target marker.
- Historical pre-callback UID0003TI state: its broad creation flow was correct, but it mislabeled `IsRectEmptyOrInvalid` as a normalizer and left the source body blank. Current applied disposition: UID0003TI is `90/93` with exact R2, preserves the discarded predicate return, passed command 13523, and appears once in command-13645 output at line 2711 with zero B003 sibling marker.
- Historical pre-callback UID0001D3 state: the aggregate recorded the future lookup-child range and ObjectList ownership, while the final lookup name/order remained open. Current applied disposition: validator command 13520 issued UID0004SI, command 13524 linked it in exact address order, UID0001D3 is `89/92`, and UID0004SI is the `90/93`, Nested-0, R3-owning `ObjectList::FindStaticObjectPaneAt` child; the three separately documented ShiftAll/DetachAll/Prune future splits remain unchanged.
- UID0004HP and MapPoint are current, exact support and remain unchanged.
- Historical pre-callback UID00007Q/UID000425 state: the 12-byte `MapTileLayerIds` declaration contradicted live six-byte stores, and UID000425 retained the downstream `objectNation`/`0x10000` contradiction. Current applied disposition: MapPane class SHA `A076D4E3...375C` preserves the corrected three-word/six-byte tile view and every B003 R6 fact not superseded by the accepted UID0003TX factory correction or UID0003TS zone-music field replacement; UID000425 contains exact R7 `staticObjectId`/16-bit flag-bit source at unchanged score/range/route.
- Historical pre-callback StaticObjectPane state: its qualified definitions coexisted with the UID0000E1 Empty Emitter Marker. Current applied disposition: UID0000E1 is `90/92` with exact R4 and command 13525 validation; command-13645 StaticObjectPane output has six unique definitions and zero class marker, while UID000388/UID00034X remain compiler/no-code support.
- Historical pre-callback generated baseline: command 13515 had one UID0003TJ marker, no UID0003TI definition, no UID0004SI definition, and one StaticObjectPane class marker alongside six qualified definitions; it contained no handwritten vtable arrays. Current applied disposition: command 13645 emits UID0003TI at 2710/2711, UID0003TJ at 2743/2744, and UID0004SI at 694/695 once, with zero B003 target/sibling/StaticObjectPane markers, class-before-children order, unique definitions, and no target-scope handwritten vtable/RTTI/cookie/EH/scalar-wrapper code. The same current epoch preserves B004 UID0003TQ/UID0004SJ-UID0004SM and adds B001 UID0003TP/UID0004SN plus B002 UID0003TS without regressing B003 scope.

## Ranked Ownership Analysis

### 1. MapPane class UID00007Q

- Evidence for: ECX is MapPane in all callers; reads tile buffer and ObjectList fields; calls inherited invalidation; owns sibling creation policy.
- Evidence against: none material; private name is inferred.
- Decision: direct target/sibling owner and emitter.

### 2. ObjectList class UID00009Q

- Evidence for: owns `0x00532eb0` receiver/layout/static-row traversal.
- Evidence against: receives coordinates from MapPane and does not own tile reconciliation or pane replacement.
- Decision: own UID0004SI only.

### 3. StaticObjectPane / StaticObjImageLib

- Evidence for: own pane object and resource metadata operations.
- Evidence against: neither owns MapPane tile-buffer scanning or ObjectList reconciliation.
- Decision: support declarations only; target move rejected.

### Proposed new file/grouping, if applicable

- No new source file. UID0004SI is an exact child routed through existing `NexusTK/map/ObjectList.cpp`.
- Candidate related items retained outside this callback: three other UID0001D3 helper children.

## Source Placement

- UID0003TJ and UID0003TI: private MapPane methods in `NexusTK/map/MapPane.cpp`.
- UID0004SI: ObjectList method in `NexusTK/map/ObjectList.cpp`.
- StaticObjectPane declaration/methods: `NexusTK/map/StaticObjectPane.cpp` route.
- Rejected: placing target in StaticObjectPane.cpp, ObjectList.cpp, StaticObjImageLib.cpp, a generic geometry module, or a new file.
- Remaining uncertainty is lexical only and does not affect placement.

## Range / Split / Padding / Reclassification Analysis

- Target exact range stays `[0x0050f130,0x0050f26d)`; no split or rename.
- UID0003TI stays `[0x0050f030,0x0050f130)`; seven-byte predecessor padding `[0x0050f029,0x0050f030)` remains parent-only ignored evidence.
- Three-byte successor padding `[0x0050f26d,0x0050f270)` remains ignored and is not absorbed.
- Register UID0004SI exactly `[0x00532eb0,0x00532f67)`. Internal predecessor alignment `[0x00532eae,0x00532eb0)` and successor `[0x00532f67,0x00532f70)` stay parent-only.
- Relative nesting proof: UID0001D3 has `Nested:-4`; first exact child UID0001D2 has `Nested:+4`; a later same-level child therefore uses delta `0`; successor UID00023F already uses `Nested:0`. UID0004SI `Nested:0` preserves all following levels.
- UID0001D3 remains a reconstructable `[[CHILDREN]]` aggregate; no broad body is emitted.

## Negative Evidence Summary

- No caller sets EDI as an argument or consumes EAX.
- No inclusive rectangle comparison exists.
- No lookup of primary/effect/living rows occurs in `0x00532eb0`; generic all-object naming is weaker.
- No source justification exists for raw `this[265]`, `+0x128`, manual virtual calls, scalar flags, vptr stores, pool-free calls, SEH, or cookie logic.
- No evidence supports moving target ownership to an adjacent class/file.
- No evidence supports hand-authored vtable/RTTI arrays or a standalone compiler-wrapper body.
- No direct report exists in older/special/archive roots.

## IDA Rename / Type / Comment Recommendations

- Read-only documentation/source names: `MapPane::RefreshStaticObjectTileRegion`, `MapPane::CreateStaticObjectPaneForTile`, `ObjectList::FindStaticObjectPaneAt`, `StaticObjectPane::GetStaticObjectId`.
- Correct type: packed-by-natural-members six-byte `MapTileLayerIds` with three unsigned shorts. No packing pragma is needed because all members are 2-byte aligned.
- Correct parameter order: tileX/column first, tileY/row second for ObjectList lookup; MapPoint stores row then column.
- IDA labels were kept unchanged during the evidence pass and callback. No IDB mutation was performed or requested.
- Historical aliases `sub_50F130`, `__userpurge`, `FindObjectAt`, `objectNation`, three-dword tile view, and "normalizes rectangle" remain only as superseded provenance.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. R1 is exact target code; R2-R7 close all compile/source dependencies caused by this target.
- Third-party import directive: not applicable; all code is project-authored NexusTK source.

### Destination R1 - UID0003TJ target formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::RefreshStaticObjectTileRegion(const MapRect &tileBounds)
{
    for (int tileY = tileBounds.top; tileY < tileBounds.bottom; ++tileY)
    {
        for (int tileX = tileBounds.left; tileX < tileBounds.right; ++tileX)
        {
            MapTileLayerIds tile;
            GetLegacyAwareMapTileLayerIds(&tile, tileX, tileY);

            StaticObjectPane *existingObject =
                m_objectList->FindStaticObjectPaneAt(tileX, tileY);

            if (tile.staticObjectId != 0)
            {
                if (existingObject != NULL)
                {
                    if (existingObject->GetStaticObjectId() == tile.staticObjectId)
                        continue;

                    RectBounds bounds;
                    existingObject->GetBounds(&bounds);
                    InvalidateRect(&bounds);
                    m_objectList->RemoveObjectPane(existingObject);
                    if (existingObject->GetObjectType() != kObjectPaneTypeStatic)
                        existingObject->ReleaseBackingStore();
                    delete existingObject;
                }

                CreateStaticObjectPaneForTile(
                    tileX,
                    tileY,
                    tile.staticObjectId,
                    false);
            }
            else if (existingObject != NULL)
            {
                RectBounds bounds;
                existingObject->GetBounds(&bounds);
                InvalidateRect(&bounds);
                m_objectList->RemoveObjectPane(existingObject);
                if (existingObject->GetObjectType() != kObjectPaneTypeStatic)
                    existingObject->ReleaseBackingStore();
                delete existingObject;
            }
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination R2 - UID0003TI complete formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaticObjectPane *MapPane::CreateStaticObjectPaneForTile(
    int tileX,
    int tileY,
    unsigned short staticObjectId,
    bool skipListInsertion)
{
    Rect objectBounds;
    g_pStaticObjImageLib->GetStaticObjectBounds(staticObjectId, &objectBounds);
    IsRectEmptyOrInvalid(&objectBounds);

    StaticObjectPane *objectPane =
        new StaticObjectPane(tileX, tileY, staticObjectId);

    StaticObjEntry *entry =
        g_pStaticObjImageLib->GetStaticObjectEntry(staticObjectId);
    if (entry != NULL && entry->lightIntensity >= 0)
    {
        AttachObjectLighting(
            objectPane,
            g_mapTilePixelWidth,
            g_mapTilePixelHeight / 2 -
                g_mapTilePixelHeight * entry->lightHeightClass,
            entry->lightIntensity);
    }

    UpdateObjectPaneScreenBounds(objectPane);
    if (!skipListInsertion)
        m_objectList->AddObjectPane(objectPane);

    return objectPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination R3 - UID0004SI complete formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaticObjectPane *ObjectList::FindStaticObjectPaneAt(int tileX, int tileY)
{
    RectBounds paddedBounds;
    InitRectBounds(
        &paddedBounds,
        m_minX - 2,
        m_minY - 2,
        m_minX + m_gridWidth + 2,
        m_minY + m_gridHeight + 10);

    List *row = m_staticObjectRows[tileY - paddedBounds.top];
    const int count = row->GetCount();
    for (int index = 0; index < count; ++index)
    {
        StaticObjectPane *objectPane =
            *static_cast<StaticObjectPane **>(row->GetElementAt(index));
        MapPoint position;
        objectPane->GetMapPosition(&position);
        if (position.column == tileX && position.row == tileY)
            return objectPane;
    }

    return NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination R4 - UID0000E1 complete class formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PaneEvent;
struct Rect;
struct StaticObjectDrawRequest;

class StaticObjectPane : public ObjectPane
{
public:
    StaticObjectPane(int tileX, int tileY, unsigned short staticObjectId);
    virtual ~StaticObjectPane() {}

    bool HitTestStaticObjectPixel(int localX, int localY) const;
    virtual Rect *CopyStaticObjectBounds(Rect *scratch, Rect *out) const;
    virtual bool RenderStaticObjectForTarget(
        int renderMode,
        StaticObjectDrawRequest *request);
    virtual bool HandleStaticObjectEvent(const PaneEvent *event);

    unsigned short GetStaticObjectId() const
    {
        return m_staticObjectId;
    }

private:
    void SendInteractionPacket();
    unsigned short m_staticObjectId;
};

typedef char StaticObjectPaneSizeMustBe0x12c[
    sizeof(StaticObjectPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination R5 - UID00009Q complete class formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
typedef unsigned int ObjectListKey;

class List;
class ObjectPane;
class StaticObjectPane;

class ObjectList : public LObject
{
public:
    ObjectList(int gridWidth, int gridHeight);
    virtual ~ObjectList();

    bool HasValidGridOrigin();
    void AddObjectPane(ObjectPane *object);
    void RemoveObjectPane(ObjectPane *object);
    ObjectPane *ResolveObjectListKey(ObjectListKey key);
    ObjectListKey GetTypedObjectKey(ObjectPane *object);
    ObjectPane *FindByObjectId(int objectId);
    bool ContainsTypedObject(ObjectPane *object);
    void DetachAll(ObjectPane *preserveObject);
    void RemoveMarkedVisibleObjects();

    List *GetPrimaryCellList();
    List *GetSecondaryCellList();
    List *GetPrimaryRowBucket(int row);
    List *GetSecondaryRowBucket(int row);
    List *GetVisibleObjectList();
    List *GetSecondaryGlobalList();
    List *GetAlternateGlobalList();
    List *GetTertiaryGlobalList();
    List *GetQuaternaryGlobalList();
    List *GetQuinaryGlobalList();
    List *GetFrontRowBucket(int row);
    List *GetBackRowBucket(int row);
    StaticObjectPane *FindStaticObjectPaneAt(int tileX, int tileY);

private:
    static const ObjectListKey kObjectListKeyNotFound = 0xffffffffu;

    ObjectListKey FindStaticObjectKey(ObjectPane *object);
    ObjectListKey FindLivingObjectKey(ObjectPane *object);
    ObjectListKey FindItemObjectKey(ObjectPane *object);
    ObjectListKey FindFlyingObjectKey(ObjectPane *object);
    ObjectListKey FindPrimaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindSecondaryEffectObjectKey(ObjectPane *object);
    ObjectListKey FindBalloonObjectKey(ObjectPane *object);
    ObjectListKey FindHitBarObjectKey(ObjectPane *object);
    ObjectListKey FindDamageNumberObjectKey(ObjectPane *object);

    int m_minX;
    int m_minY;
    int m_gridWidth;
    int m_gridHeight;
    List *m_itemObjects;
    List *m_flyingObjects;
    List **m_primaryEffectRows;
    List **m_secondaryEffectRows;
    List **m_livingObjectRows;
    List **m_staticObjectRows;
    List *m_balloonObjects;
    List *m_hitBarObjects;
    List *m_damageNumberObjects;
    List *m_objectInfoObjects;
    List *m_lightingObjects;
    List *m_soundObjects;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination R6 - UID00007Q complete class formal block

R6 is the complete no-loss replacement for the latest UID00007Q managed block. It changes only the six-byte `MapTileLayerIds` declaration, adds the required forward declarations, and adds `CreateStaticObjectPaneForTile`; every unrelated declaration, including the externally accepted `CreateHitBarObjectPane` unsigned-short contract, exact field order, size guard, class close, and `[[CHILDREN]]` placement is preserved.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Pane.h"
#include "GrafPort.h"
#include "Motion.h"

#include <vector>

class AlphaMaskSurface;
class Event;
class EffectObjectPane;
class Layer;
class LightingObjectPane;
class LivingObjectPane;
class LObject;
class Message;
class ObjectList;
class ObjectPane;
class ScreenEffecter;
class StaticObjectPane;
struct EffectInfo;
struct ItemObjectImageEntry;
struct StaticObjEntry;
struct MapTileLayerIds
{
    unsigned short groundTileId;
    unsigned short flags;
    unsigned short staticObjectId;
};
struct MapPaneTileRecord;
struct MapPoint;
struct RectBounds;
typedef RectBounds MapRect;
struct ObjectStatusBlob;
struct Rect;

class MapPane : public Pane
{
public:
    MapPane(int visibleTileColumns, int visibleTileRows);
    virtual ~MapPane();

    virtual void AddToLayer(
        const RectBounds *bounds,
        int order,
        Pane *parentPane,
        Layer *layer);
    virtual void QueueMotionMessage(const Rect *rect);
    virtual void OnChangeMessage(LObject *sender, Message *message);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnNotifyMessage(const unsigned char *message);
    virtual bool OnTimerEvent(int timerId, int param1, int param2);
    virtual void OnPaint();

    bool HasScreenEffecters() const;
    ScreenEffecter *FindActivePixelEffecter();
    void ResetScreenEffecterListFields();
    void ConfigureScreenEffecterList(signed char effectMode);
    void ClearScreenEffecterList();
    void ExitToMenu(bool notifyServer);
    void LoadCompressedMapFile(unsigned short mapId, int unusedLoadOption);
    void SaveCompressedMapFile();
    void MapToScreenCoords(MapPoint *point) const;
    void ScreenToMapCoords(MapPoint *point) const;
    void RedrawVisibleTiles();
    bool ValidateMapAndViewportCoords(
        int mapColumn,
        int mapRow,
        int viewportColumn,
        int viewportRow) const;
    void GetClampedVisibleTileBounds(MapRect *outBounds) const;
    void GetVisibleTileBounds(MapRect *outBounds) const;
    MapPoint *GetVisibleTileSpan(MapPoint *outSpan) const;
    void GetExtendedVisibleTileBounds(MapRect *outBounds) const;
    int CheckMovementCollision(
        int mapColumn,
        int mapRow,
        unsigned char direction);
    bool AllowsMovementStatusTag() const;
    bool ApplyMovementSubstepScroll(unsigned char direction);
    unsigned short GetAdjacentVisibleTileBounds(
        unsigned char direction,
        MapRect *outBounds) const;
    void AfterLocalPlayerWarp();
    void ObjectCallbackNoOp(ObjectPane *objectPane);
    void ScrollViewportByDirection(unsigned char direction);
    void ReindexObjectPanePosition(
        ObjectPane *objectPane,
        int removeRow,
        int removeColumn,
        int addRow,
        int addColumn);
    void RecenterAndSendPosition(
        int targetX,
        int targetY,
        int viewportX,
        int viewportY,
        bool useActiveObjectViewport);
    void ClearQueuedMapStateRefresh();
    void ClearPendingActionPoll();
    ObjectPane *CreateOrUpdateObjectPane(
        int tileX,
        int tileY,
        int objectId,
        unsigned char action,
        const ObjectStatusBlob &status);
    void RemoveObjectPaneById(int objectId);
    void DetachObjectPane(ObjectPane *objectPane);
    bool HasObjectIntersectingRect(const Rect *rect) const;
    ObjectPane *FindObjectPaneById(int objectId);
    ObjectPane *FindPreviousSelectableObject(ObjectPane *current);
    ObjectPane *FindNextSelectableObject(ObjectPane *current);
    ObjectPane *FindPreviousItemTargetObject(ObjectPane *current);
    ObjectPane *FindNextItemTargetObject(ObjectPane *current);
    ObjectPane *FindPreviousLivingTarget(ObjectPane *current, int targetFilter);
    ObjectPane *FindNextLivingTarget(ObjectPane *current, int targetFilter);
    void RemoveObjectPaneIfPresent(ObjectPane *objectPane);
    void UpdateObjectPaneScreenBounds(ObjectPane *objectPane);
    void UpdateObjectPosition(ObjectPane *objectPane);
    LivingObjectPane *HitTestObjectAtPoint(int y, int x);
    unsigned short GetCurrentMapId() const;
    void RenderMapView();
    void ComputeDayNightBrightnessAndTint(
        unsigned char hour,
        float brightnessScale,
        float brightnessBias,
        float *outBrightness,
        float *outTintAmount) const;
    void SetDayNightFadeTarget(float targetBrightness, float tintAmount);
    void AttachObjectLighting(
        ObjectPane *anchorSource,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    void RenderDayNightOverlay(const RectBounds *dirtyBounds);
    bool ShouldUseLivingObjectLightOverlay() const;
    bool ShouldOffsetElevatedLivingObjects() const;
    MapPoint *GetObjectScreenPoint(
        ObjectPane *objectPane,
        MapPoint *outPoint) const;
    void FlashMapColor(int drawColor);
    void FinishVisibleObjectRefresh();
    void InteractWithObject(LivingObjectPane *target);
    void CollectMovementTargetObjectIds(
        std::vector<unsigned int> &objectIds) const;
    void SortMovementTargetObjectIdsByDistance(
        std::vector<unsigned int> &objectIds) const;
    void ChangeMap(
        unsigned short mapId,
        short mapWidth,
        short mapHeight,
        unsigned char weatherMode,
        unsigned char transitionState,
        int loadOption);
    void AllocateTileBuffer();
    void RequestObjectEffect(
        unsigned int objectId,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void RefreshGroupMemberHitBar(unsigned int memberId);
    void ApplyHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned int primaryValue,
        unsigned int primaryMaximum,
        unsigned int secondaryValue,
        unsigned int secondaryMaximum);
    void RemoveGroupMemberHitBar(unsigned int memberId);
    bool HandleMapInfoTileRegionPacket(const unsigned char *packet);

private:
    void NotifyDeferredMotionChanged();
    void RefreshQueuedMapState();
    LivingObjectPane *FindObjectAtMapPoint(int y, int x);
    void DrawVisibleTiles();
    void DrawTileAt(int tileX, int tileY, bool refreshStaticObjects);
    unsigned short ComputeTileRectChecksum(const MapRect *bounds) const;
    unsigned int ComputeVisibleTileChecksum(const MapRect &bounds) const;
    MapTileLayerIds *GetLegacyAwareMapTileLayerIds(
        MapTileLayerIds *outTile,
        int mapColumn,
        int mapRow) const;
    unsigned char RemapMovementDirectionForMapScroll(unsigned char direction) const;
    void RefreshScrolledTileData(
        int objectColumn,
        int objectRow,
        int viewportColumn,
        int viewportRow,
        unsigned char direction);
    int SelectMovementPathStep();
    bool ShouldClearMovementTimerState() const;
    int BuildPathToPendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void ResolvePendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void SetMapState(int weatherType, unsigned char weatherMode);
    void RequestCoordinateEffect(
        int mapColumn,
        int mapRow,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void ApplyEffectObjectPaneTimerAction(
        EffectObjectPane *effectObjectPane,
        int timerAction);
    void CreateEffectObjectPane(
        LivingObjectPane *target,
        int mapRow,
        int mapColumn,
        EffectInfo effectInfo,
        int timerAction,
        int sequenceIndex,
        bool renderAfterLivingObjects);
    void AttachObjectLighting(
        ObjectPane *anchorSource,
        const ItemObjectImageEntry *imageEntry,
        int localOffsetX,
        int localOffsetY);
    void CreateHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned short currentValue,
        unsigned short maximumValue);
    StaticObjectPane *CreateStaticObjectPaneForTile(
        int tileX,
        int tileY,
        unsigned short staticObjectId,
        bool skipListInsertion);
    void RefreshStaticObjectTileRegion(const MapRect &tileBounds);
    void ResetMapResourceStateForModeChange();
    void RefreshDeferredMapSurfacesForTileRegion();
    bool InvalidateShiftedMapArea(int deltaX, int deltaY);
    bool HandleObjectInfoPacket(const unsigned char *packet);
    bool HandleEffectMapStatePacket(const unsigned char *packet);
    bool HandleDrawObjectsPacket(const unsigned char *packet);
    bool HandleMovementSpeechBalloonPacket(const unsigned char *packet);
    bool HandleObjectMoveEffectPacket(const unsigned char *packet);
    bool HandleObjectWorldMapCreationPacket(const unsigned char *packet);
    bool HandleActionPacket(const unsigned char *packet);
    bool HandleFlyingObjectUpdatePacket(const unsigned char *packet);
    bool HandleAnimationSoundPacket(const unsigned char *packet);
    bool HandleObjectStatusPacket(const unsigned char *packet);

public:
    int m_screenEffecterCount;
    int m_screenEffecterCapacity;
    ScreenEffecter **m_screenEffecters;
    LivingObjectPane *m_highlightedObjectPane;
    bool m_selectedObjectActive;
    unsigned char m_selectedObjectPadding[3];
    LivingObjectPane *m_selectedObjectPane;
    int m_mapResourceMode;
    bool m_mapEffectEnabled;
    unsigned char m_mapEffectPadding[3];
    Motion m_deferredMotionRecords[32];
    int m_deferredMotionRecordCount;
    bool m_deferMotionMessages;
    bool m_queuedMapStateRefresh;
    bool m_pendingActionPoll;
    unsigned char m_deferredStatePadding;
    int m_pendingMovementState[6];
    float m_currentDayNightBrightness;
    float m_dayNightCurrentScale;
    float m_dayNightCurrentBias;
    float m_dayNightCurrentTint;
    float m_dayNightTintCurveScale;
    float m_dayNightTintCurveBase;
    float m_dayNightTintAmount;
    float m_newHumanProjectionDivisor;
    float m_newHumanProjectionShear;
    float m_dayNightTargetBrightness;
    AlphaMaskSurface *m_selectionOverlay;
    float m_dayNightBrightnessScale;
    float m_dayNightBrightnessBias;
    unsigned int m_pendingMapStateToken;
    bool m_waitingForLocalPlayerStatus;
    bool m_objectInteractionTimerActive;
    unsigned short m_mapId;
    short m_mapWidth;
    short m_mapHeight;
    MapPaneTileRecord *m_tileBuffer;
    int m_tileOriginX;
    int m_tileOriginY;
    int m_visibleTileColumns;
    int m_visibleTileRows;
    unsigned char m_mapTransitionState;
    unsigned char m_weatherMode;
    unsigned char m_movementGate;
    unsigned char m_dayNightHour;
    int m_weatherType;
    Pane *m_weatherLayerPane;
    LivingObjectPane *m_localPlayerObjectPane;
    Pane *m_auxiliaryPane;
    Layer *m_activeScreenLayer;
    ObjectList *m_objectList;
    GrafPort m_viewportGrafPort;
    int m_mapFlashColor;
    unsigned char m_mapRuntimeMode;
    bool m_visibleObjectRefreshPending;
    bool m_refreshWholeVisibleMap;
    unsigned char m_mapRefreshPadding;
    int m_mapDisplayOriginX;
    int m_mapDisplayOriginY;
    int m_mapDisplayScalePercent;
    wchar_t m_mapName[256];
    unsigned short m_mapNameLength;
    wchar_t m_mapResourceName[256];
    unsigned short m_mapResourceNameLength;
    unsigned char m_actionStatePrefix[8];
    bool m_pendingActionModeActive;
    unsigned char m_pendingActionModePadding[3];
    int m_pendingActionTileX;
    int m_pendingActionTileY;
    unsigned char m_pendingActionState[20];
    unsigned int m_pendingActionTargetObjectId;
    bool m_deferredPrimarySurfaceDirty;
    unsigned char m_deferredSurfacePadding;
    bool m_deferredSecondarySurfaceDirty;
    unsigned char m_finalPadding;
};

typedef char MapPaneSizeMustBe0x910[
    sizeof(MapPane) == 0x910 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination R7 - UID000425 complete formal block

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int MapPane::CheckMovementCollision(int mapColumn, int mapRow, unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int nextColumn = mapColumn + offset.column;
    const int nextRow = mapRow + offset.row;

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    if (!PointInRect(nextRow, nextColumn, &mapBounds))
        return -1;

    if (m_localPlayerObjectPane->AllowsMovementCollisionBypass())
        return 1;

    ObjectPane *blockingObject = m_objectList->FindObjectAtMapPoint(nextColumn, nextRow);
    if (blockingObject != NULL)
    {
        if (_wcsicmp(blockingObject->GetObjectName(), L"GM") != 0 &&
            !blockingObject->IsMovementPassable())
        {
            return 0;
        }
    }

    MapTileLayerIds currentTile;
    MapTileLayerIds nextTile;
    GetLegacyAwareMapTileLayerIds(&currentTile, mapColumn, mapRow);
    GetLegacyAwareMapTileLayerIds(&nextTile, nextColumn, nextRow);

    if ((g_objectRecordCount >= currentTile.staticObjectId ||
         g_objectRecordCount >= nextTile.staticObjectId) &&
        (g_objectNationMap[currentTile.staticObjectId] & s_objectDirectionMasks[direction]) == 0 &&
        (g_objectNationMap[nextTile.staticObjectId] & s_objectReverseDirectionMasks[direction]) == 0 &&
        nextTile.groundTileId != 0 &&
        (nextTile.flags & 1) == 0)
    {
        return 1;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- R1 preserves exact duplicated removal order instead of introducing a helper not present in the binary.
- R2 preserves the otherwise odd discarded predicate call and uses ordinary `new`; pool/EH mechanics are compiler lowering.
- R3 preserves List pointer-slot dereference and MapPoint row/column order.
- R4 closes the class before `[[CHILDREN]]`; it does not hand-author vtables, adjustors, scalar flags, or pool deletion.
- R6/R7 jointly preserve the exact six-byte representation and existing collision policy.

## Final Recommendation

- R1-R7 and all C01-C20 are implemented at the accepted destinations.
- Validator command 13520 created/registered only UID0004SI; its issued UID replaced the placeholder everywhere before dependent validation.
- Target owner/emitter/range/position/nesting and parent UID0001AW are preserved; verify-only callers/dependencies remain unchanged except validator-owned reverse links.
- UID000388, UID00034X, UID0004HP, UID0004R0, ObjectPane, List, StaticObjImageLib, Rect helpers, target callers, and the other three UID0001D3 future helpers remain unchanged; their accepted evidence was preserved.
- Remaining work outside this callback scope is limited to separate exact child reports for ShiftAll, DetachAll, and PruneMarkedRowObjects.

## Recommended Target Doc Changes

- Path: `by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md`.
- Implemented `91/94`; retained owner/emitter UID00007Q, true, blank position, `Nested:0`, and exact range.
- Installed R1; Item Summary and prose now carry the full hash/ABI/loop/tile/output/lookup/lifetime/sibling/compiler-exclusion evidence.
- Historicalized the IDA EDI/return prototype, provisional names, and blank-C++ conclusion without deleting their provenance.

## Recommended Support Doc Changes

- UID0003TI is `90/93` with exact Item Summary/evidence, R2, and corrected predicate disposition.
- UID0001D3 is `89/92` with issued-child inventory while preserving its marker, three future splits, padding, and history.
- UID0004SI exists at the exact path/range with owner/emitter UID00009Q, true, blank position, `Nested:0`, `90/93`, R3, and full evidence.
- UID00009Q / UID0000M4 are `91/93` each, with R5 on the class and typed lookup declaration/inventory/source route; all concurrent methods/storage remain.
- UID0000E1 is `90/92` with R4 and exact layout/vtable/compiler evidence. UID0000O6 is `90/91` with source/class closure wording and unchanged path.
- UID00007Q remains `93/94` with R6 transformations and the full class union/layout preserved. UID0000L3 remains `92/92` with the target/sibling/type/generated route synchronized.
- UID000425 score/range/route remain unchanged; R7 is installed and only stale field/type expressions were historicalized.
- UID0001AW preserves `86/90`, owner UID00007Q, non-reconstructable split/container state, blank emitter/position/formal, `Nested:0`, exact range, Item Summary, and its complete current 390-line union. The B003 bounded edit remains only exact source-ready UID0003TI/UID0003TJ status and padding/ordering facts. The no-loss union now includes the previously accepted B002/B004/B005/B011 families, B001 UID0003TP/UID0004SN, and B002 UID0003TS while preserving every other exact child, raw duplicate, padding span, boundary, ownership decision, open question, cross-reference, and historical change entry.
- UID0004HP/UID0004R0/ObjectPane/List/StaticObjImageLib/UID0001D6/UID000388/UID00034X: verify-only.

## Score And Metadata Recommendation

- Implemented target `86/90 -> 91/94`: all prior ABI/type/name/private-access/lifetime/body blockers are closed. Not higher because private original lexemes are inferred.
- Implemented UID0003TI `86/90 -> 90/93`: return/parameters, metadata, placement and insertion flow are closed; discarded predicate and private names cap confidence.
- Implemented UID0001D3 `87/90 -> 89/92`: one formerly provisional later helper is now exact child UID0004SI; three later helper bodies remain unsplit.
- Implemented UID0004SI `90/93`: exact body/range/hash/order/owner/source shape; name is descriptive rather than symbol-proven.
- Implemented ObjectList class/file `90/92 -> 91/93`: typed declaration and exact child close the lookup gap; broad remaining helper split debt prevents higher completion.
- Implemented StaticObjectPane class `86/88 -> 90/92`, file `86/88 -> 90/91`: complete declaration removes the scoped marker and closes layout/accessor/virtual source route; exact event lexeme and pool operator source spelling remain inferred.
- MapPane class/file and UID000425 scores remain unchanged because this is a bounded correction within already broad high-quality pages.
- All owner/emitter/reconstructable/position metadata stays unchanged except new child assignment; target/sibling/new child nesting is exact as stated.

## Open Questions With Attempted Resolution

- Is EDI a source argument? No: all callers and `retn 4` reject it.
- Is the return pointer source-visible? No: it is the incoming pointer left in EAX and all callers ignore it.
- Is the rectangle inclusive? No: both comparisons are strict `<`.
- Is tile output 12 bytes? No: helper stores exactly six bytes; loader/writer/allocator/saver agree.
- Is +4 objectNation or staticObjectId? It is the packet static id and pane id; collision uses that same id to index nation metadata. `staticObjectId` is the narrower source field.
- Does `0x004b7eb0` normalize bounds? No: it is a predicate and sibling discards the return.
- Is lookup generic? No: only `m_staticObjectRows` is searched; typed static name is best.
- Can delete be hand-expanded? No: scalar wrapper/pool free/base teardown are compiler lowering.
- Remaining unresolved: original private lexemes and why source retained a discarded predicate call. Exact binary behavior is preserved; these do not block code and only cap score.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current no-loss supervisor-owned manual snapshot after B001 UID0003TP and B002 UID0003TS coverage application:
  - `by-memory/-coverage-report.md`: command `000000013646`, exit `0`/ok `1`; SHA256 `15503038D5DF3CA5364A424E8AF4F83CC44196E748D27A33670F01B069BB2D93`, 1,744,817 bytes, 4,210 lines, last write `2026-07-16T03:27:44.6024636-04:00`.
  - `by-class/-coverage-report.md`: command `000000013647`, exit `0`/ok `1`; SHA256 `9D42F839A670E40D90CD834A0FE0F25A964ADF5BC2A12FDDF77AFB7AE6C2A391`, 225,346 bytes, 622 lines, last write `2026-07-16T03:27:44.6106381-04:00`.
  - `by-file/-coverage-report.md`: command `000000013648`, exit `0`/ok `1`; SHA256 `C2A5EC493F029B814FD600A31E49B08888FB13ABE14D4247822F220A4562BC17`, 129,033 bytes, 316 lines, last write `2026-07-16T03:27:44.6128162-04:00`.
  - No current by-struct coverage change or B003 proposed delta exists. Read-only no-change proof: `by-type/by-struct/-coverage-report.md` remains SHA256 `C0FA7E9B4079CC5080CBE9AC7FF16F7C2A11E1030EE6AC0EA2F503C6B468F873`, 57,159 bytes, 137 lines; UID0004HP remains exact at line 71 from command 13592.
- Current manual by-memory anchors are UID000425 2231; UID0001AW 2278; B003 UID0003TI/UID0003TJ 2291/2292; B002 UID0003TW/UID0003TX 2293/2294; B005 UID0003TK/UID0003TL/B004 UID0003TO 2296-2298; B001 UID0003TP 2299 and UID0004SN 2301; B004 UID0003TQ 2304; B002 UID0003TS 2307; UID0001D3/UID0001D2/B003 UID0004SI 2517-2519. B004 UID0004SJ/UID0004SK/UID0004SL/UID0004SM remain in the complete union. Class anchors retain MapPane/ObjectList/StaticObjectPane at 302/373/526; file anchors retain them at 156/193/267; struct UID0004HP remains at 71.
- Commands 13560/13561/13563 remain historical B003-handoff proof; commands 13589-13592 are the historical pre-B004 epoch; commands 13613-13615 are the historical B004 epoch; and commands 13638-13640 are the historical post-B001/pre-B002 epoch. Current commands 13646/13647/13648 preserve every B003 row and add the complete B001/B002 union without pruning prior facts. B003 made no manual coverage edit or validation command, and direct current comparison leaves no supervisor manual delta for UID0003TJ scope.
- Historical command-13560 UID0001AW parent handoff at line 2278 is retained below; all of its B003/B005/B004, TimerPane, raw-duplicate, and source-ownership facts survive in the current line-2278 no-loss union, which additionally includes B002 UID0003TX:

```text
    - [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | packet-handler split index | MapPanePacketHandlers : not_reconstructable : 86% : very-strong : Non-emitting MapPane packet-handler split/container with exact source-bearing children, including source-ready UID0003TK opcode-0x15 map/effect-state parsing and direct bool return plus source-ready UID0003TO opcode-0x29 trusted-packet object/effect routing with signed descriptor/action, coordinate/object requests, compiler-inlined FlashMapColor(143), unconditional success, and preserved unsafe/no-length behavior; preserves unrelated packet/helper dispositions, live opcode 0x67 TimerPane create/update/delete flow, retained duplicate 0x005140a0 with zero inbound xrefs or pointer route, MapPane ownership of parsing, and TimerPane ownership of the called constructor/SetTimer source.
```

- Historical B003 by-memory handoff result: the two static-object rows below remain present at current lines 2291/2292 before B002 UID0003TW/UID0003TX at 2293/2294; later B001/B002 insertions move UID0001D3/UID0001D2/UID0004SI to 2517/2518/2519 without changing their B003 facts.

```text
        - [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) 0x0050f030-0x0050f130 | private method | MapPaneCreateStaticObjectPaneForTile : reconstructable : 90% : very-strong : Exact source-ready MapPane static-object creation helper with typed tile/id/skip-insertion ABI, StaticObjImageLib bounds and metadata, preserved discarded IsRectEmptyOrInvalid call, ordinary-new StaticObjectPane pool lowering, optional lighting, screen-bounds update, ObjectList insertion gate, exact range/hash/caller, and compiler-only EH/pool cleanup exclusions.
        - [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) 0x0050f130-0x0050f26d | private method | MapPaneRefreshStaticObjectTileRegion : reconstructable : 91% : very-strong : Exact source-ready row-major half-open MapRect reconciliation method with one-argument void thiscall ABI, six-byte tile output/staticObjectId, typed static-row lookup, matching-id retention, duplicated invalidate/remove/release/delete order, nonzero replacement creation, four callers, exact bytes/hash/padding, and EDI/EAX/compiler-lowering exclusions.
    - [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md) 0x00532530-0x00532f67 | class method cluster | ObjectListAccessorsAndSweeps : reconstructable : 89% : very-strong : ObjectList accessor/sweep aggregate with exact accessor child, source-ready typed static-row lookup child, preserved ShiftAll/DetachAll/Prune future splits, exact internal padding, ObjectList ownership, child-only emission, and historical MapPaneSpatialIndex aliases rejected.
    - [UID:0004SI][0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt](by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md) 0x00532eb0-0x00532f67 | method | ObjectListFindStaticObjectPaneAt : reconstructable : 90% : very-strong : Exact ObjectList static-row lookup with padded bounds, m_staticObjectRows indexing, List count/element-slot semantics, MapPoint row/column comparison, two callers, exact range/hash/padding, typed StaticObjectPane return, and complete source body.
```

- Historical B003 UID000425 handoff remains current at by-memory line 2231 and equals:

```text
        - [UID:000425][0x00505430-0x005055ca.MapPaneCheckMovementCollision](by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md) 0x00505430-0x005055ca | method | MapPaneCheckMovementCollision : reconstructable : 88% : very strong : Source-ready collision helper preserving exact -1/0/1 policy, singular m_localPlayerObjectPane precondition, object blocking/GM bypass, corrected six-byte MapTileLayerIds staticObjectId lookups and 16-bit flag-bit test, direction masks, nine callers, and complete body.
```

- Historical B003 by-class handoff result: the rows below are retained as applied proof. Current ObjectList/StaticObjectPane lines 373/526 remain equal; current MapPane line 302 preserves every B003 fact and adds the accepted UID0003TX object-info/factory correction, B004 UID0003TQ support, B001 UID0003TP/UID0004SN, and B002 UID0003TS field/source union.

```text
- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era MapPane declaration emitter at position 0 with exact 0x910 layout and current method union, including source-ready RequestObjectEffect, RequestCoordinateEffect, CreateEffectObjectPane, and ApplyEffectObjectPaneTimerAction integration with typed EffectInfo/LivingObjectPane/EffectObjectPane and exact event-2 action semantics; source-ready private CreateHitBarObjectPane with unsigned-short current/maximum values, style 1 only for ObjectStatusBlob::HumanObject and 0 otherwise, separate ordinary-new branches, typed LivingObjectPane owner-slot installation and ObjectList registration, timer event 0 scheduled for 500 ms self-delete, and exact UpdatePosition, inherited GetBounds, then InvalidateRect order; corrected six-byte MapTileLayerIds with staticObjectId, typed CreateStaticObjectPaneForTile, and source-ready RefreshStaticObjectTileRegion declarations; source-ready opcode-0x15 HandleEffectMapStatePacket parsing with exact cache/ObjectList/weather/movement/day-night/waiting/EPF/target-selection lifecycle; source-ready HandleObjectMoveEffectPacket with signed descriptor/action, trusted packet reads, coordinate/object effect routing, FlashMapColor(143) source call, and unconditional true return; compiler ABI lowering excluded; followed by address-ordered exact children.
- [UID:00009Q][ObjectList](by-class/ObjectList.md) : reconstructable : 91% : very-strong : Complete LObject-derived 0x44 ObjectList declaration with semantic storage, exact lifecycle/dispatch/accessor/private-key methods, typed FindStaticObjectPaneAt static-row lookup, child-only definitions, and compiler table/cookie/vtable/scalar-wrapper exclusions.
- [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) : reconstructable : 90% : very-strong : Complete 0x12c ObjectPane-derived StaticObjectPane declaration with constructor, inline virtual source destructor, bounds/render/event methods, private packet helper, inline static-object-id accessor, exact +0x128 field, class-before-children order, and compiler-generated three-view vtable/scalar-delete/pool mechanics excluded.
```

- Historical B003 by-file handoff result: the rows below are retained as applied proof. Current ObjectList/StaticObjectPane lines 193/267 remain equal; current MapPane line 156 preserves every B003 fact and adds UID0003TW/UID0003TX/factory, B004 UID0003TQ/helper support, B001 UID0003TP/UID0004SN, and B002 UID0003TS source routes.

```text
- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children route and exact source-ready object/coordinate effect descriptor, EffectObjectPane creation, and existing-pane delete/cancel/guarded timer replacement family; preserves typed LivingObjectPane/EffectInfo/TimerHandler contracts, target registration/timer/bounds behavior, and prose-only by-file policy; includes source-ready private CreateHitBarObjectPane with unsigned-short current/maximum values, ObjectStatusBlob::HumanObject style-1 versus default style-0 decision, separate ordinary-new branches, typed LivingObjectPane owner-slot installation and ObjectList registration, timer event 0 scheduled for 500 ms self-delete, and exact UpdatePosition, inherited GetBounds, then InvalidateRect order; adds the corrected six-byte static-object tile view and source-ready CreateStaticObjectPaneForTile/RefreshStaticObjectTileRegion pair with exact ObjectList lookup, stale-object lifetime, replacement, and compiler-exclusion behavior; preserves B005's accepted source-ready opcode-0x15 HandleEffectMapStatePacket packet/cache/ObjectList/weather/day-night/transient/waiting/EPF/config behavior and compiler exclusions; includes source-ready HandleObjectMoveEffectPacket with signed descriptor/action, conditional trusted packet reads, coordinate/object routing, compiler-inlined FlashMapColor(143), lookup-miss/no-length behavior, and unconditional success.
- [UID:0000M4][ObjectList](by-file/ObjectList.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectList.cpp source root with complete ObjectList declaration, semantic storage taxonomy, exact lifecycle/dispatch/accessor/private-key methods, typed static-row lookup child, preserved remaining helper splits, child-only emission, and compiler exclusions.
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map/StaticObjectPane.cpp source root with complete 0x12c class declaration, source constructor/hit-test/bounds/render/event/packet methods, inline id accessor and destructor source cause, pool allocation/deletion lowering, and compiler-generated vtable/RTTI/adjustor/scalar-wrapper exclusions.
```

- By-struct UID0004HP line 71 remains exact and unchanged byte-for-byte.
- The code blocks above preserve the exact accepted B003 handoff text as historical applied proof. Commands 13560/13561/13563 applied those updates; commands 13589-13592, 13613-13615, and 13638-13640 retained them through successive shared epochs; current commands 13646/13647/13648 retain every B003 row/fact while adding B001 UID0003TP/UID0004SN and B002 UID0003TS over the complete B004/B005 union. The unaffected UID0004HP struct row requires no change. No B003 coverage item remains, and B003 did not edit or validate any manual file.

## Follow-Up Actions

- Implementation, scoped validation, and supervisor-owned no-loss manual coverage reconciliation are complete; no B003 implementation or coverage-handoff item remains. C01-C20/R1-R7 are reconciled against UID0004SI, historical commands 13552/13559/13588/13612/13636, current command-13645 generated state, executed B001 UID0003TP and B002 UID0003TS archives, the complete shared ordinary union, historical manual epochs through 13640, current by-memory/by-class/by-file commands 13646/13647/13648, and the unaffected command-13592 UID0004HP no-change row.
- External supervisor/validator ownership: report validation/execution/count/path/move/archive state is external and is neither asserted nor directed by this artifact. The report records durable completed evidence rather than a pending lifecycle state.
- B003 itself ran no execute, report probe/count, revalidation lifecycle, move, archive, or manual coverage command.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: high; score caps reflect private lexical uncertainty, not behavioral/type/range gaps.
- Remaining uncertainty: original private spellings and rationale for discarded predicate call; neither changes formal behavior.

## Validator Results

- All commands ran from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; every changed ordinary destination has a scoped successful command. Each existing-file lease was acquired only after reread, and released immediately after its validator. The temporary UID0001D3 parent lease used for child registration was also released immediately after command 13520.

| Command | Timestamp EDT | Scoped destination | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000013520` | `2026-07-15T21:58:35-04:00` | `by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md` | `0` / registration success | Validator-supported new-file registration issued UID0004SI; registry/generated metadata were rebuilt by validator ownership. R3 hash `3940AF30...EB754`. |
| `000000013522` | `2026-07-15T22:01:40-04:00` | UID0003TJ target | `0` / `1` | Accepted `91/94`, complete evidence and R1. Its initial missing-UID0003TI warning was resolved by the next scoped sibling command. |
| `000000013523` | `2026-07-15T22:02:50-04:00` | UID0003TI sibling | `0` / `1` | Accepted `90/93`, R2, and restored current UID reverse mapping. |
| `000000013524` | `2026-07-15T22:04:42-04:00` | UID0001D3 parent | `0` / `1` | Accepted `89/92`, issued-child link/order, retained marker, padding, history, and three future splits. |
| `000000013525` | `2026-07-15T22:05:31-04:00` | `by-class/StaticObjectPane.md` | `0` / `1` | Accepted `90/92` and R4. Warning for pre-existing verify-only missing UID000388 registry reference remains unrelated. |
| `000000013526` | `2026-07-15T22:07:02-04:00` | `by-file/StaticObjectPane.md` | `0` / `1` | Accepted `90/91` source/class/compiler route; same pre-existing UID000388 warning only. |
| `000000013527` | `2026-07-15T22:08:16-04:00` | `by-class/ObjectList.md` | `0` / `1` | Accepted `91/93`, complete no-loss class union, and R5. |
| `000000013528` | `2026-07-15T22:10:07-04:00` | `by-file/ObjectList.md` | `0` / `1` | Accepted `91/93` and typed source inventory. Warning for pre-existing unrelated missing UID0003IO registry reference remains. |
| `000000013529` | `2026-07-15T22:11:52-04:00` | `by-class/MapPane.md` | `0` / `1` | Accepted unchanged `93/94` and R6; complete B002/B004/B005 union, including unsigned-short HitBar contract, preserved. Broad pre-existing missing-UID warnings were not introduced or broadened. |
| `000000013530` | `2026-07-15T22:13:37-04:00` | `by-file/MapPane.md` | `0` / `1` | Accepted unchanged `92/92` and bounded source route; broad pre-existing missing-UID warnings remain unrelated. |
| `000000013531` | `2026-07-15T22:14:31-04:00` | UID000425 collision helper | `0` / `1` | Accepted unchanged score/route and exact R7 field/flag correction. Validator-owned registry/generated metadata refresh occurred; B003 made no manual coverage/generated edit. |
| `000000013535` | `2026-07-15T22:16:24-04:00` | UID0001AW parent | `0` / `1` | Accepted bounded target/sibling/order prose while preserving the complete current shared union. |
| `000000013536` | `2026-07-15T22:16:44-04:00` | B003 UID0003TJ `--wait-generated` | `0` / `1` | `generated_refresh: completed`; this is the exact historical B003 callback checkpoint. Registry/projected-stat/generated metadata side effects were validator-owned; no file was manually edited. External command 13546 superseded it as the valid interim header and command 13552 became the Gate-2 accepted generated checkpoint. |
| `000000013547` | `2026-07-15T22:59:45-04:00` | External B004 UID0003TO target | `0` / `1` | Applied B004's accepted `92/94` target block; recorded read-only from the terminal B004 artifact. |
| `000000013548` | `2026-07-15T23:01:42-04:00` | External B004 UID0001AW parent | `0` / `1` | Applied bounded UID0003TO parent closure while preserving B003/B005 and unrelated union content. |
| `000000013549` | `2026-07-15T23:02:39-04:00` | External B004 `by-class/MapPane.md` | `0` / `1` | Applied prose-only UID0003TO support with the R6/class formal unchanged. |
| `000000013550` | `2026-07-15T23:03:32-04:00` | External B004 `by-file/MapPane.md` | `0` / `1` | Applied prose-only UID0003TO source-route support with the complete current union preserved. |
| `000000013551` | `2026-07-15T23:04:27-04:00` | External B004 UID0004Q9 | `0` / `1` | Applied source-cause prose only; score/range/formal remained unchanged. |
| `000000013552` | `2026-07-15T23:04:53-04:00` | External B004 UID0003TO `--wait-generated` | `0` / `1` | `generated_refresh: completed`; Gate-2 accepted headers on all three generated outputs. Broad generator diagnostics were external/pre-existing and not UID0003TJ-specific; later commands 13559, 13588, and 13612 advanced external generated epochs without regressing B003 scope. |

- External supervisor coverage commands `000000013553`, `000000013554`, and `000000013555` established the historical B004 manual epoch; external supervisor execute command `000000013556` then moved the B004 artifact to its executed path. These are lifecycle provenance only.
- Historical external supervisor command `000000013560` at `2026-07-15T23:50:44-04:00` applied/validated `by-memory/-coverage-report.md`, exit `0`/ok `1`; command `000000013561` at `2026-07-15T23:51:14-04:00` applied/validated `by-class/-coverage-report.md`, exit `0`/ok `1`; command `000000013563` at `2026-07-15T23:51:43-04:00` applied/validated `by-file/-coverage-report.md`, exit `0`/ok `1`. They were not B003 commands; this remains the historical B003 handoff-application epoch.
- Historical external supervisor commands `000000013589`-`000000013592` applied the pre-B004 manual union; commands `000000013613`-`000000013615` applied the B004 union; and commands `000000013638`-`000000013640` applied the post-B001/pre-B002 union. They were not B003 commands. Exact pre-existing warnings remain historical; no warning-free assertion is made.
- External B004 waited command `000000013612`, timestamp/refreshed `2026-07-16T01:18:34-04:00`, exit `0`/ok `1`, is the historical pre-B001 generated epoch. Evidence-time B004 report SHA `E81D0DC0...0A5E` had passed written Gate 1 plus independent ordinary Gate 2; current active B004 artifact SHA is `1EB92F1C...597C`. Direct current file reads, not mutable report lifecycle, establish durable implementation facts.
- External B001 waited command `000000013636`, refreshed `2026-07-16T02:24:00-04:00`, exit `0`/ok `1`, added UID0003TP/UID0004SN over the preserved union. Its exact report is now validator-archived at SHA `089014A5...6C62` under execution command 13641.
- External B002 scoped shared validators `000000013642`/`13643`/`13644` applied UID0003TS index/class/file additions over the B001-complete union, each exit `0`/ok `1`. Final waited command `000000013645`, refreshed `2026-07-16T03:09:31-04:00`, exit `0`/ok `1`, established the current generated epoch. The exact B002 archive is SHA `6C57AAEF...73DF` with final validator-owned execution command 13651.
- Current external supervisor manual commands `000000013646`, `000000013647`, and `000000013648` applied/validated by-memory/by-class/by-file respectively, each exit `0`/ok `1`, at current hashes `15503038...2D93`, `9D42F839...A391`, and `C2A5EC49...BC17`. Direct comparison proves all B003 rows survive and no B003 manual delta remains.

- R1 formal parity: accepted report and current UID0003TJ destination are byte-identical at SHA256 `3E4BFB1DA6BEDEBD8626439A012A60A8BD74A55BD7CC44115868785055FD78E0`.
- R2 formal parity: accepted report and current UID0003TI destination are byte-identical at SHA256 `16D265CEE5E4741A094F5BF9453EF842FA4796C1D301A399F5FD2FB2433AE065`.
- R3 formal parity: accepted report and current UID0004SI destination are byte-identical at SHA256 `3940AF3088DD9BA7162A4D6200C7DF5DF5A53A9654FB8B23FB7779BB0C5EB754`.
- R4 formal parity: accepted report and current StaticObjectPane destination are byte-identical at SHA256 `E0829C7EA933FE8450DA7FB0EEC837B8414DA8D9878089C0CA3185D51841EF47`.
- R5 formal parity: accepted report and current ObjectList destination are byte-identical at SHA256 `88449C202E4F0B75EBECD2A5490DC8E56F93FB8AC41112637A2CBFA273A52DEE`.
- R6 formal survival: the accepted report block remains unchanged at SHA256 `7D6432B6DB3AFA46E72B12B456AC0169D23C36F134C28DA7CB90B5C1E6309C48`; current MapPane page SHA256 is `A076D4E350565BAD1EADF679A93E9E908CB0F321EAF11710B16FC580E7F1375C`, while its managed-value SHA256 is `E41EBEDD2A34A3F7CB5E37197941E08A1683FD1751F04D244C530D1BE773A5E5`. Direct line comparison shows only the accepted UID0003TX by-value factory/ItemObjectImageEntry cleanup and UID0003TS replacement of the three stale display fields with zone-music fields; every B003 R6 line not superseded by those bounded accepted corrections remains present in order.
- R7 formal parity: accepted report and current UID000425 destination are byte-identical at SHA256 `C81CC38466D857A85CD99EBBFC7402B9DE228F4FCF15390637188A6AE52509D3`.
- Accepted generated proof remains external B004 command/header `000000013552`, timestamp `2026-07-15T23:04:53-04:00`; B003 did not invoke it. At that checkpoint MapPane.cpp closed its class at line 328 before children, contained 76 qualified definitions with 76 unique names, preserved UID0003TI/UID0003TJ exact-range comments and definitions once each at lines 2681-2682/2714-2715, preserved B005 UID0003TK at comment/definition 2764/2810, and added B004 UID0003TO at 3114/3115. ObjectList.cpp closed its class at line 73, contained 31 qualified definitions with 31 unique names, and preserved UID0004SI exact-range comment/`FindStaticObjectPaneAt` once at lines 694-695. StaticObjectPane.cpp closed its class at line 33, contained six unique qualified definitions, and had zero UID0000E1 marker. No target-scope handwritten vtable/RTTI/cookie/EH/scalar-wrapper code appeared.
- Historical command-13559 readback remains the immediate post-coverage/pre-B002 state described in Current Target State; it is not current.
- Historical command-13588 readback remains the terminal-B002/pre-latest-B004 state described in Current Target State; it is not current.
- Current read-only generated state is final B002 command/header `000000013645`, refreshed `2026-07-16T03:09:31-04:00`: MapPane `B4D6F013338AC0B013C6100BE60036572537F44761C9A39C290F4F13AD419EA3` / 138,106 bytes / 4,132 lines; ObjectList `2D73464A9D67A4E80ED95E6DF7BBF8DEADBC1132413FD51D962AC069C3E26768` / 30,650 / 951; StaticObjectPane `6DEFDAE58E1BBBF2ADC4D9CDE34D65F03A947AEA4793E7DD9EA53F7B1AD6D635` / 3,777 / 107; UserPane `390FDEA85F3999182CC4781FE17511E8F39D8C33967D01A53861D257F3547CEE` / 91,175 / 2,723; BowGaugeObjectPane `99FD52CAFF19E0D75605D68F1745817EF4EF09DD4C2CD7ABCBFEBE39417E6087` / 2,205 / 49; AttachedObjectPane `1FEA2686B2D4EA2E112FC874943F321EC570612449A3875FCBACC6D630F2A491` / 10,901 / 288. MapPane closes at 322, first definition is 328, and it has 80 total qualified MapPane definitions / 80 unique qualified names, of which 78 are non-constructor/destructor definitions. UID0003TI 2710/2711, UID0003TJ 2743/2744, UID0003TX 2792/2795, UID0003TK 2924/2970, UID0003TO 3274/3275, UID0003TP 3318/3319, UID0003TQ 3581/3582, UID0003TS 3718/3737, UID0003TW 4013/4014, and UID0004SN 4036/4037 each occur once on their accepted route. B003 scoped markers remain zero; five MapPane markers are unrelated. UID0004SI remains at ObjectList 694/695 with one unrelated marker; StaticObjectPane has six unique definitions and zero marker. UID0004SJ-UID0004SM remain one annotation/definition each with zero corresponding marker.
- Historical pre-coverage stable-double-read proof: all twelve changed ordinary destinations, three generated outputs, and four manual files had identical hashes and last-write times at `23:28:23.4505600` and `23:28:36.4153354` EDT, aggregate fingerprint `C1D5B044E1D950D094DCA04397E4DE641F32CF366D494569A2DB045FAC53E841`; the 23-file extended union was identical at `23:29:32.5624894` and `23:29:43.1294241`, fingerprint `5AF36D16F85BA7FB929DE4CADAAF5B43FDF3FD13560B6CE947CC7AF566BA3DFB`.
- Historical post-UID0003TX/pre-B004 double-read proof remains accepted historical evidence at `2026-07-16T00:26:35.4438723-04:00` and `2026-07-16T00:27:00.8783747-04:00`. Current post-B001/B002 proof is the 23-file zero-difference read pair at `2026-07-16T03:49:35.7577295-04:00` and `2026-07-16T03:49:39.3809331-04:00`; it covers both executed archives, all B003 target/support pages, the three shared MapPane pages, generated outputs, manual roots, and leases. No active lease was present.

## Changed Files

- Created ordinary page: `by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md` as validator-issued UID0004SI.
- Historical B003 callback changed ordinary pages: UID0003TJ target; UID0003TI sibling; UID0001D3 parent; `by-class/StaticObjectPane.md`; `by-file/StaticObjectPane.md`; `by-class/ObjectList.md`; `by-file/ObjectList.md`; `by-class/MapPane.md`; `by-file/MapPane.md`; UID000425 collision helper; bounded UID0001AW parent. Current SHA256/bytes/lines are recorded in Current Target State. B001/B002 later advanced only UID0001AW, MapPane class, and MapPane file among that B003 set; the other nine remain byte-identical to B003's passed state.
- This bounded post-B001/B002 current-union rebase changed only this same B003 report. It preserves all C01-C20/R1-R7 research, implementation, warnings, validators, and historical epochs; it records executed B001/B002 archive anchors, current shared hashes, UID0003TP/UID0004SN/UID0003TS union facts, command 13645 generated proof, commands 13646/13647/13648 manual proof, unaffected UID0004HP no-change proof, and same-or-greater R6 survival. Exact current paths and validator-owned footers are lifecycle authority; B003 does not forecast or perform report execution/movement/archive state.
- Renamed ordinary files: none. B003's only new child remains UID0004SI. External B004 current-union children UID0004SJ/UID0004SK/UID0004SL/UID0004SM are read-only coordination facts and were not created or edited by B003.
- Verify-only ordinary dependencies remained unedited except validator-owned reverse-reference propagation. Manual coverage and generated C++ were read-only; validator-owned refresh side effects are recorded, not manual edits.
- Prohibited/lifecycle scope: B003 edited no `-coverage-report.md`, generated/tracker/audit/supervisor/validator-state/lifecycle/archive/queue/lock/IDA/other-agent file and ran no execute, report probe/count, revalidation lifecycle, move, or archive command.

## Implementation Tracking Checklist

Initial research/Gate 1 pass (completed):
- [x] Supervisor validated exact report artifact before implementation authorization.
- [x] Target/support destination scope covered UID0003TJ, UID0003TI, UID0001D3, UID0004SI, UID00007Q, UID0000L3, UID00009Q, UID0000M4, UID0000E1, UID0000O6, UID000425, and bounded UID0001AW prose.
- [x] UID0001AW complete B001/B002/B003/B004/B005/B011 union is preserved; B003 UID0003TI/UID0003TJ, UID0003TW/UID0003TX, B004 UID0003TQ/UID0004SJ-UID0004SM, B001 UID0003TP/UID0004SN, and B002 UID0003TS coexist without loss at current SHA `4241D9B3...7111` / 390 lines.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger carries destination and legal terminal verification state for every accepted claim.
- [x] Metadata/score changes were applied exactly as listed.
- [x] Score-limiting blockers were researched to resolution; private lexemes remain only confidence caps.
- [x] Owner/emitter/reconstructable routes were preserved; UID0004SI is assigned to UID00009Q.
- [x] Split/new-child work registered only UID0004SI and replaced every placeholder before dependent validation; no rename was required.
- [x] Source-placement, range/split/padding/reclassification, and type changes were applied exactly.
- [x] First-draft C++ R1-R7 was applied exactly with managed-value hashes recorded.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support facts were incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence were preserved.
- [x] Wave2/Wave3 artifacts confirmed absent/not used.
- [x] Open questions remain closed or bounded with evidence-backed lexical caps.
- [x] One scoped validator ran successfully for every changed/new ordinary page.
- [x] Historical B003 command 13536, B005 command 13546, B004 command 13552, later historical commands through 13636, current B002 command 13645, historical manual epochs through 13640, current commands 13646/13647/13648, executed B001/B002 archives, and the unaffected command-13592 UID0004HP row are reconciled; current shared ordinary/generated files and manual rows were reread directly.

Implementation callback pass (completed):
- [x] Exact report SHA `7FB957C253861AD0DE9427B65BB86DA4607C4D15F1C0F6BB178116DDFE06A626` was accepted by the supervisor for implementation.
- [x] All accepted target/support details were incorporated without loss, including the current post-B001/B002 MapPane union and unchanged B003 ObjectList/StaticObjectPane semantics.
- [x] C01-C20 ledger is in legal terminal callback states with claim-specific destination/validator/generated proof.
- [x] Metadata/score/owner/emitter/split/new-child/C++ changes are applied or retained exactly with reasons.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Open questions remain resolved/bounded exactly as accepted.
- [x] Scoped validator command IDs, timestamps, exits, ok results, warnings, and side effects are recorded.
- [x] Waited callback history through B001 command 13636, current B002 command-13645 assertions including 80 total qualified MapPane definitions / 80 unique qualified names with 78 non-constructor/destructor definitions, the complete post-B001/B002 ordinary union, current manual commands 13646/13647/13648, executed archive commands 13641/13651, and the unchanged command-13592 UID0004HP row are reconciled; final lease proof confirms zero B003 lease and no shared ordinary lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000013652","destination_path":"executed-b-agent-research/B003/0003TJ-MapPaneRefreshStaticObjectTileRegion-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003TJ-MapPaneRefreshStaticObjectTileRegion-source-quality.md","timestamp":"2026-07-16T04:16:56-04:00","uid":"0003TJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
