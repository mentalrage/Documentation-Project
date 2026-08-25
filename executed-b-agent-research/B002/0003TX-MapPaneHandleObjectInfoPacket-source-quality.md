** TARGET-REPORT-UID:0003TX **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003TX MapPaneHandleObjectInfoPacket Source-Quality Research


## Finalized Report / Current Recommendation

- B002 callback work is complete. [UID:0003TX] now emits the exact `bool MapPane::HandleObjectInfoPacket(const unsigned char *packet)` body at `92/94`, with owner/emitter UID00007Q, blank position, reconstructable true, and `Nested:0` retained.
- Destinations 1-10 are installed byte-for-byte. UID0003TW is the sole file-static helper definition, UID0002QN is the sole corrected by-value factory definition, ObjectInfoObjectPane and ItemObjectPane have complete declarations, and the Living/User/Item support fields are compile-visible without duplicate source.
- The callback-last MapPane declaration preserves the complete current B003/B005/B004/B011 union. Its formal differs from the leased baseline only by the accepted UID0002QN signature correction and stale `ItemObjectImageEntry` forward/overload removals; direct comparison against Destination 4 is exact.
- Current coordination artifacts were reread rather than frozen as implementation authority: B003 UID0003TJ report SHA256 `694A8629D30F6C50F87AE728C3DAE00E73DFA4BDB0B164344ADF7EF87FCF2217`, B005 UID0003TK report SHA256 `74F2EA10F97DB0CE431DC0EE58CE06184D78349501389F5CBA1DE8880F6FB182`, and executed B004 UID0003TO SHA256 `AC0096CBD7D6BD3EF3D7D8C8EF84F4124EE8A8A3135BB9E299D86F6A9C0D2D63` were read before the shared edit. Historical B004 pre-execution SHA and command `13556` remain provenance only.
- All scoped validators passed, final waited generated command `000000013588` remains the callback semantic proof, and every lease is released. The supervisor subsequently applied and validated the manual coverage delta through commands `13589`-`13592` as a no-loss union with the existing same-or-greater B003/B004/B005/B011 rows rather than pruning them to the report's shorter proposed replacements. Current/future report execution, move, archive, and later lifecycle state remain external validator/supervisor-owned and are not asserted.

## Supporting Research

- The exact target has no prior direct report. Older reports were treated as leads and independently checked against current bytes, decompilation, current by-* pages, generated output, and source-shape constraints.
- Historical B001 batch9 split correctly established the target range, opcode `0x33` route, MapPane ownership, helper [UID:0003TW], and adjacent padding, but its blank-C++/provisional-name conclusion is superseded by this current full pass.
- Historical B002 UID0002QN work correctly recognized the object factory and broad item/living branches, but its current formal signature, pooled-new source spelling, item lookup API, local-player helper names, and several argument orders are stale and are replaced below.
- Executed B004 UID0003TH/UID0003TO plus the completed ordinary callbacks for B003 UID0003TJ and B005 UID0003TK are preserved in the final ordinary MapPane union. Their reports were reread at callback time using the current hashes above; B002 changed only the accepted UID0003TX delta after a leased no-loss comparison. The older command-13552/generated and command-13553-13555/manual observations remain explicitly evidence-time pre-callback history.
- Evidence collection used live read-only MCP database `64c11373`. The target pass used transport session `a6a70cb2-7408-4101-b450-fe0cddab0f20`; the final ItemObjectPane blocker recheck used fresh transport session `037f677a-225c-41e3-a106-61d3a7930027`. Session health and all binary observations below are evidence-collection-time facts, not assertions of future availability.
- Wave2/Wave3 material appeared only in stale legacy reports and was ignored as reconstruction authority. It was used only to identify search aliases that were then revalidated independently.

## Target

- Target UID: `0003TX`.
- Target path: `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md`.
- Required report path: `tools/leaser/Agents/Agent-B002/research/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md`.
- Queue source: `auto-generated/-ag-research-tracker.md`, `by-memory / Not-Covered Files - Reconstructable`; assignment-time direct-report count zero.
- Exact executable range: `[0x0050fb00,0x0050feab)`, 939 bytes.
- Historical pre-callback metadata: `86/90`, owner/emitter `00007Q`, reconstructable true, blank position/formal/Item Summary, `Nested:0`.
- Applied metadata: `92/94`, same owner/emitter/reconstructable/blank position/Nested, exact Item Summary and Destination 1 formal body.

## Current Target State

- Current target page SHA256 is `E2AA4102AF72063575FE0B163DBC1F7D784EDAF676863F363E7E850904D37B90`, 15,917 bytes/242 lines. It carries `92/94`, the exact Item Summary, Destination 1, complete packet/control-flow/negative/compiler evidence, and historicalized pre-callback assumptions.
- Current MapPane class SHA256 is `95D07519D1DC46CFCE4A6D3D858AED6470D6ACE38E262F2F2AEA8655AF8FBFD2`, 169,668 bytes/950 lines; MapPane file SHA256 is `B949B30D78567BCB02018CD74C3E68116B6FFF77C206A996D3B3A37031EDCFEB`, 170,960 bytes/709 lines; parent UID0001AW SHA256 is `FD73F05C34345EE20358F63DA03CC051D5FC6DE34DABC508D812025872EDE2CF`, 86,354 bytes/352 lines. Class/file/parent retain `93/94`, `92/92`, and non-emitting `86/90` respectively.
- Destination 4 exact comparison is true against the current class formal. The B003 static-object, B005 opcode-`0x15`, B004 opcode-`0x29`/HitBar, B011 map-info, every unrelated method/field, the `0x910` size guard, class closure, and `[[CHILDREN]]` remain present.
- Final generated readback is command/header `000000013588`, refreshed `2026-07-16T00:09:40-04:00`. MapPane.cpp has one target definition, one helper declaration before it, one helper definition after it, one corrected factory definition, zero target marker, zero stale ItemObjectImageEntry references, and one each of the preserved shared packet definitions.
- A concrete callback drift was found and repaired: UID0002SD still emitted two stale `renderFlagsOrMode` references after the ItemInfo declaration changed. UID0002SD and current ItemInfo/ItemObjImageLib prose now use `lightImageIndex`; final generated ItemObjImageLib has three correct occurrences and zero stale spellings.
- Current supervisor-owned manual coverage is the command-13589/13590/13591/13592 no-loss union: UID0003TW and UID0003TX are present in the by-memory index, all accepted B002 target/support rows are applied, and pre-existing B003/B004/B005/B011 evidence remains present.
- B002 edited only the ordinary pages listed under Changed Files and this report. Manual coverage, generated output, tracker, audit, supervisor, validator-state, lifecycle, archive, and IDA files were not manually edited. Scoped validators and authorized generated refreshes were run; report execution/lifecycle commands were not run.

## Executive Recommendation

- The exact target body now emits through MapPane. The dispatcher adjusts the owner to MapPane and the body reads and mutates MapPane state; dependency calls do not transfer ownership.
- [UID:0003TW] now emits as a `static` MapPane.cpp helper through file owner `0000L3`. Because file helpers emit after class children, Destination 1 carries its exact forward declaration immediately before the target definition.
- UID0002QN's stale formal body was replaced by the by-value factory source. The status value is copied into the caller's stack argument area; the function ends in `retn 0x54` and therefore cannot be a const-reference body.
- ObjectInfoObjectPane is complete as a source-era class declaration at position 40. Its exact method bodies remain separate child-owned source; the declaration is no longer blank because UID0003TX constructs it and directly writes one private flag, represented by `friend class MapPane`.
- ItemObjectPane is complete as the exact `0x12c` ObjectPane-derived declaration at position 10. The declaration supplies the constructor and inherited virtual override surface required by UID0002QN without duplicating exact child bodies.
- `LivingObjectPane::m_objectInfoType`, UserPane's final byte plus `ObjectStatusBlob m_currentAppearance`, `ItemInfo::lightImageIndex`, and `friend class MapPane` on ItemObjImageLib are synchronized in their current declarations.
- All verify-only dependencies were preserved except UID0002SD, whose generated stale field spelling was a concrete contradiction repaired under the documented bounded exception.

## Supervisor Active Recheck

- The supervisor assigned this exact target because tracker direct-report count was zero and required a standalone report rather than reliance on MapPane batch reports.
- The exact function is already a clean child, so no new split is required. The pass did reclassify the nearby file-static helper and source-close the dependent factory/class/layout contracts that otherwise blocked compile-visible C++.
- Every source-bearing item named as a blocker has an exact destination and formal block. Compiler-only vtable/scalar/EH/range-check lowering remains non-emitting with exact exclusion evidence.

## Inference Research Guidance Check

- `by-structure.md` and the workflow evidence ladder were applied: executable ABI/bytes/callers first, then current declaration/layout support, then source-era inference, then historical reports.
- Existing docs were treated as hypotheses where they conflicted with live behavior: stale packet subtype wording, stale enum-correction prose, stale UID0002QN reference ABI, pooled allocation syntax, stale helper names, generic ItemInfo `+0x0c` semantics, LivingObjectPane `m_nameStateToken`, and UserPane's unresolved final reserve.
- Direct IDA facts, documentation facts, and inference are labeled separately. Original lexical spellings are not claimed; descriptive names are selected where source semantics are now narrow enough to compile and preserve behavior.
- Stale Wave2/Wave3 import history was not used as current source or lifecycle authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Evidence class | Disposition |
| --- | --- | --- | --- |
| Handler name/ABI | `bool MapPane::HandleObjectInfoPacket(const unsigned char *packet)` | dispatcher case, this adjustment, `retn 4`, normal returns | source-ready inferred spelling |
| Packet type | raw immutable byte pointer, not a packet struct | only fixed-offset reads; no current packet record declaration | exact source-safe type |
| Coordinates | `mapX` from BE16 `+1`, `mapY` from BE16 `+3` | call order to factory and y-first geometry | source-ready descriptive names |
| Action/object id | action byte `+5`; BE32 object id `+6` | direct reads and downstream APIs | exact widths |
| Status selector | `+10`: 0 full/43, 1 partial/5, otherwise return true | two parser calls and control flow | exact |
| Name fields | object-info type at `11+consumed`, one-byte length at `12+consumed`, bytes at `13+consumed` | exact pointer arithmetic | exact |
| Conversion | ACP, no flags, input length byte, output cap 32, terminator at returned count in 33-wide buffer | MultiByteToWideChar call/range check | exact |
| Visible gate | clamped bounds expanded one tile; y-first `PointInRect(mapY,mapX)` | current geometry APIs and pushes | exact |
| Factory call | objectId, mapX, mapY, action, 68-byte status by value | caller push order, callee `retn 0x54` | exact |
| Living `+0x16c` | `m_objectInfoType` | target writes decoded type; no token/counter behavior | descriptive source-ready rename |
| Object-info cases | 1 color 12, 2 color 39, 3 local skip/nonlocal 224, default 55 | four allocation/constructor sites | exact literals, inferred category name |
| Alternate label helper | `ObjectInfoObjectPane::SetSelectedName` | constructor fields and sole setter body/call family | strongest source-facing name |
| `+0x12c` flag | `m_tracksSelectedName` | type 1/2/3 set true after empty alternate name; default false | descriptive source-ready name |
| ObjectInfo virtual surface | `ClearOutputRects(RectBounds *, RectBounds *)`, `RenderFrame(GrafPort *, const RectBounds *)`, `SetSpriteAttribute(unsigned char)`, and `UpdatePosition()` | exact primary-vtable slot alignment; live `0x00539b20` and base `0x00538600` are ABI- and byte-identical one-byte overrides | complete source-safe declarations; historical `ComputeTooltipRect`, `DrawTooltip`, and `UpdatePositionFromDirection` remain descriptive aliases only |
| Status helper | `RefreshObjectStatusOverlay` | no receiver; exact two MapPane callers; status/equipment predicate | file-static |
| Effect request | `LivingObjectPane::RequestNameplateEffect` | sole helper caller leads to MapPane object effect 135, timer -2 | strongest behavioral name |
| Factory ABI | 68-byte status by value | `retn 0x54` equals 16 scalar bytes plus 68 status bytes | original-shape inference with direct ABI proof |
| Local-player copy | UserPane `m_currentAppearance` at `+0x13eb40` | exact 68-byte copy and complete object-size arithmetic | source-ready field |
| Item row `+0x0c` | `lightImageIndex` | only recovered consumer tests nonnegative then passes it to AttachObjectLighting | source-ready rename |
| Item table access | direct `ProtectedArray<ItemInfo>::GetAtOrDefault` through friendship | current template API plus exact object layout | most probable original header shape |
| ItemObjectPane class | `0x12c` class; `m_itemId` at `+0x128`, `m_paletteFlags` at `+0x12a` | fresh constructor/update/render decompilation and vtable slots | complete compile-visible declaration |
| Item virtual names | `ClearOutputRects` at primary slot `+0x50`; `RenderFrame` at `+0x5c` | exact base ObjectPane slot map plus Item vtable refs | stale BuildCentered/Process aliases superseded |
| Allocation syntax | ordinary `new` | pool allocator and EH are compiler lowering; no source placement-new API | compiler/source reduction |
| Compiler tails | range check, cookie, EH cleanup, vptrs, deleting wrappers, allocator/free | compiler patterns and separate ABI children | excluded from handwritten source |

Rejected alternatives:
- A packet struct was rejected because no current declaration or reuse proves field names beyond this handler, while raw bytes preserve exact unchecked reads.
- `ProcessMapPacket` and `MapPaneObjectInfoPacket` were rejected as too broad; one dispatcher case and current class naming support `HandleObjectInfoPacket`.
- ObjectList/ObjectInfo/Living ownership was rejected because those objects are dependencies and mutations, while MapPane is the adjusted receiver.
- A class-static status helper was rejected because the helper has no receiver and two file-local MapPane callers.
- Const-reference status in UID0002QN was rejected by `retn 0x54`.
- Pool placement new, status accessors, safety checks, a one-allocation-after-switch refactor, and helper wrappers were rejected because they alter source shape or generated behavior.
- Keeping `m_nameStateToken`, `renderFlagsOrMode`, or a 69-byte unresolved UserPane tail was rejected by direct semantic consumers.
- Handwritten vtables, scalar deleting destructors, null checks, conversion checks, packet bounds checks, allocation cleanup, and exception wrappers were rejected as absent or compiler-generated.

No investigable blocker remains. Exact original private lexical names remain confidence caps only; the selected descriptive names are narrow, type-correct, and behavior-preserving.

## Evidence Standards Used

- Live MCP: `idb_list`, `server_health`, bounded `lookup_funcs`, `get_bytes`, fresh target/helper/factory decompilation, function/caller/callee/CFG/xref inspection, and related setter/parser/constructor consumers.
- Binary: exact hashes, instruction counts, return cleanup, four constructor sites, adjacent `0xcc` spans, compiler failure tails, constants, field offsets, and branch order.
- Documentation: current by-memory/class/file/type pages, exact managed blocks, generated output, manual coverage rows, active collision reports, and archived matching reports.
- Negative evidence: absent alternate callers, absent target/helper definitions in generated output, absent safety branches, absent duplicate object-info route, and absent support for stale aliases.
- The evidence is strong enough for complete first-draft C++ because ABI, layout, call order, branch behavior, and declaration routes converge. Confidence remains below 95 because original symbols and packet record declarations are unavailable.

## Evidence Checked

### Live MCP checks

- Fresh `idb_list` selected NexusTK database `64c11373`, worker PID `21508`, analyzing false.
- `server_health` returned `ok` with auto-analysis, Hex-Rays, and strings ready.
- `lookup_funcs`: target `sub_50FB00` size `0x3ab`; helper `sub_50FA90` size `0x64`; factory `sub_505E00` size `0x2e3`.
- Fresh final transport `8512f5b8-258a-4303-ab13-ab8a3ceec9d7` rechecked `idb_list` at `2026-07-15T22:47:14-04:00`: sole active database `64c11373`, worker PID `21508`, analyzing false. `server_health` remained `ok` with auto-analysis/Hex-Rays/strings ready, and bounded `lookup_funcs` reconfirmed target/helper/factory starts and sizes `0x3ab`/`0x64`/`0x2e3`.
- `analyze_component` and fresh `decompile` covered ItemObjectPane constructor `0x00537b40` size `0x51`, ordinary destructor `0x00537ba0` size `0x1f`, status update `0x00537bc0` size `0x29`, `ClearOutputRects` implementation `0x00537bf0` size `0x75`, and `RenderFrame` implementation `0x00537c70` size `0x32`.
- Final bounded ObjectInfo declaration recheck used fresh MCP transport session `52120da0-6b84-4cd1-8e82-8a1e0e03c350` against database `64c11373`: `idb_list` returned the sole active worker PID `21508`, `server_health` remained `ok` with analysis/Hex-Rays/strings ready, and `analyze_function` proved derived `0x00539b20` and base `0x00538600` are both 146-byte `__thiscall(this, char)` functions with identical instructions, `retn 4`, and the corresponding primary-vtable cells `0x0062090c` and `0x006205b4`. The inherited source-facing declaration is therefore `SetSpriteAttribute(unsigned char)`, while the old `UpdatePositionFromDirection` label is superseded descriptive history.
- The same final live pass analyzed `0x00539760` as a 382-byte thiscall with two explicit output pointers and vtable xref `0x006208f0`, and `0x005398e0` as a 576-byte thiscall with GrafPort and bounds arguments and vtable xref `0x006208fc`. Their cells align with ObjectPane's accepted `ClearOutputRects(RectBounds *, RectBounds *)` and `RenderFrame(GrafPort *, const RectBounds *)` slots; the old `ComputeTooltipRect`/`DrawTooltip` labels remain behavior descriptions, not competing source declarations.
- Fresh setter analysis resolved the fixed-array semantics: `0x00539650` scans the source and copies to primary name `+0x12e` only when length is at most 32; `0x00539690` copies length-at-most-32 input to selected name `+0x170`, while its unusual overlength branch truncates into the primary-name array and writes its final terminator. UID0003TX passes the empty string, so its exact route is the bounded selected-name clear; neither setter deletes memory.
- Bounded bytes:
  - target: `55 8b ec 6a ff 68 0c 2b 60 00 64 a1 00 00 00 00`;
  - helper: `55 8b ec 83 ec 44 8b 4d 08 8d 45 bc 50 c6 45 e4`;
  - factory: `55 8b ec 6a ff 68 e8 22 60 00 64 a1 00 00 00 00`.
- Fresh decompilation and instruction/CFG review covered every target/helper/factory block and all material callees named in this report.

### Documentation and report-root searches

Exact search terms:
`UID0003TX`, `UID:0003TX`, `0x0050fb00`, `0x0050feab`, `MapPaneHandleObjectInfoPacket`, `HandleObjectInfoPacket`, `UID0003TW`, `0x0050fa90`, `RefreshObjectStatusOverlay`, `UID0002QN`, `0x00505e00`, `CreateOrUpdateObjectPane`, `UID00009P`, `ObjectInfoObjectPane`, `UID0003Z4`, `UID000179`, `UID0002C9`, `UID0003TB`, and `MapServerPacketOpcode`.

Roots and outcomes:
- `executed-b-agent-research`: matching reports opened; no exact UID0003TX direct report.
- `tools/leaser/Agents/Agent-B*/research`: current B003 UID0003TJ, B005 UID0003TK, and B004 UID0003TO callback artifacts opened for collision/current-union comparison; no duplicate UID0003TX report. Executed B004 UID0003TH remains historical/current support rather than active work.
- `archived`: searched, no relevant direct match.
- `tools/leaser/Agents/Older-Research`: searched, no current direct match.
- `tools/leaser/Agents/SpecialReports`: searched, no current direct match.

Relevant reports opened:
- `source-3/project-documentation/executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md`, SHA256 `8031B270F31D97AEC13CEAEFA1A423BF74D291972B6776BC68BCD528F75689F8`, 74,364 bytes/871 lines: valid split/range/opcode/helper lead; blank-body blockers superseded.
- `source-3/project-documentation/executed-b-agent-research/B002/0002QG-0002QL-0002QM-0002QN-MapPaneMovementObjectUpdate-source-quality.md`, SHA256 `7D449915FB90A58EE8899CD2AFD9731EF98F2B839A6B417C29EC4740B1B4867E`, 42,943 bytes/635 lines: valid factory role; formal signature/API/source lowering superseded.
- `source-3/project-documentation/executed-b-agent-research/B003/B003-MEMTOOL-00505E00-MapPaneCreateOrUpdateObjectPane.md`, SHA256 `07B4C2932E7DC99EAA112ACCBBDDF858A835D3CAAB16A73CF99C2DF985E39C35`, 12,856 bytes/178 lines: historical broad lead only.
- `source-3/project-documentation/executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md`, SHA256 `157E38B6F911C803660B9F7F39E9107B8F4F6D018922504FF12C8AA4CD2B3D9D`, 125,524 bytes/1,456 lines: exact parser/status layout evidence.
- `source-3/project-documentation/executed-b-agent-research/B005/0002C9-ObjectListTypeDispatchInsertCategorize-source-quality.md`, SHA256 `73E903FA2560252EC17FE40AA2A58921D74A568D9E6F939F9E5A183ADDED25A7`, 28,412 bytes/415 lines: exact AddObjectPane contract.
- `source-3/project-documentation/executed-b-agent-research/B001/0003Z4-LivingObjectPaneLinkedObjectSetupHelpers-source-quality.md`, SHA256 `522FD383FE3DD472AEA32CD18348A7943AA6D6650361549F8B857889A4F8D3A4`, 152,146 bytes/1,804 lines: exact ObjectInfo owner slot/replacement and Living declaration evidence.
- `source-3/project-documentation/executed-b-agent-research/B005/000355-ObjectInfoObjectPaneVtableData-empty-emitter-source-quality.md`, SHA256 `5320B81C6E331DFA6C393B5BC5690DD2B7FD2209E6D9DF84879967E8CF5ED130`, 32,208 bytes/412 lines: vtable/generated ABI exclusion.
- `source-3/project-documentation/executed-b-agent-research/B015/00037T-MapPanePacketDispatcher-source-quality.md`, SHA256 `BA37D273FC831EE08F3FBFEADFCE7288452C666D08454F3DA984ECEB47B7A448`, 61,652 bytes/392 lines: dispatcher context.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003TJ-MapPaneRefreshStaticObjectTileRegion-source-quality.md`, final callback coordination artifact SHA256 `694A8629D30F6C50F87AE728C3DAE00E73DFA4BDB0B164344ADF7EF87FCF2217`, 94,253 bytes/1,090 lines: completed ordinary implementation with real UID0004SI and seven exact formal blocks; the ordinary static-object union is present unchanged in the shared destinations. Historical command-13546-era report hashes remain evidence-time only.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0003TK-MapPaneHandleEffectMapStatePacket-source-quality.md`, final callback coordination artifact SHA256 `74F2EA10F97DB0CE431DC0EE58CE06184D78349501389F5CBA1DE8880F6FB182`, 82,755 bytes/821 lines: source-ready opcode-`0x15` target and support union applied; historical terminal-callback SHA `520711A2...F02` remains evidence-time only.
- `source-3/project-documentation/executed-b-agent-research/B004/0003TO-MapPaneHandleObjectMoveEffectPacket-source-quality.md`, current central SHA256 `AC0096CBD7D6BD3EF3D7D8C8EF84F4124EE8A8A3135BB9E299D86F6A9C0D2D63`, 77,831 bytes/620 lines: supervisor-executed by command `000000013556`; all 46 claims and 70 callback rows remain terminal, commands 13547-13552 remain exact implementation proof, and the lifecycle footer is validator-owned. Historical pre-execution callback SHA was `F419E519...C6A4`.
- `source-3/project-documentation/executed-b-agent-research/B004/0003TH-MapPaneCreateHitBarObjectPaneEventOverlay-source-quality.md`, SHA256 `1A24EBF0A105324342D7C1A985806EB413D6FCE4F4BBC8AE6226AEE3A19019AA`, 94,412 bytes/992 lines: executed implementation artifact supporting the current ordinary MapPane union, preserved read-only.

### Current by-* and generated checks

- Exact current target/support hashes and every B002 validator are recorded under `Validator Results` and `Changed Files`. Every destination was reread immediately before and after its short lease; each lease was released immediately after the page's scoped validator. The final lease read shows zero B002 leases.
- Current manual rows were reread directly from all four affected manual coverage files after supervisor commands `000000013589`-`000000013592`. Current hashes are by-memory `B9CC8370ECCB987D6D0559E926D86D4E6510579F49D27FA9D2ED1D0A46D2C7E9`, by-class `07D98BB8124B476FB9E2B39D298AB5BE92E1D21714F3B9622A0CA810D89F146B`, by-file `3BF998864768EC10DA471D4566381B64EFC8BDDD1B1E9B2633C305662522DA1C`, and by-struct `C0FA7E9B4079CC5080CBE9AC7FF16F7C2A11E1030EE6AC0EA2F503C6B468F873`. The supervisor applied B002's semantic delta as a no-loss union: UID0003TW/UID0003TX and all accepted target/support updates are current while the longer pre-existing B003/B004/B005/B011 evidence remains intact. The shorter row text below is historical handoff provenance, not a current replacement instruction. B002 did not edit manual coverage.
- Final generated outputs were read, hashed, and exact-count searched at validator header `000000013588`, refreshed `2026-07-16T00:09:40-04:00`. MapPane.cpp has exactly one UID0003TX definition, one UID0003TW declaration before it, one UID0003TW definition after it, one corrected UID0002QN definition, zero target marker, zero stale `ItemObjectImageEntry`, and one each of the preserved B003/B005/B004 packet definitions. AttachedObjectPane and ItemObjectPane each contain one complete class and no respective class marker; Living/User/Item output has the new fields and zero stale spellings. No handwritten vtable/scalar/EH/decompiler ABI source was introduced.
- Destination 4 no-loss proof used an ordered line transform, not a set comparison. The leased baseline differed only by the six-line factory declaration, `struct ItemObjectImageEntry;`, and the five-line stale overload; the applied formal is byte-for-byte equal to Destination 4 and preserves every B003/B004/B005/B011 and unrelated declaration.
- No MCP check failed. No unavailable evidence was replaced with fallback evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0003TX becomes 92/94 with exact summary/body; owner/emitter/reconstructable/blank position/Nested remain | very strong | live function plus route | Destination 1 / target / validator 13557 | incorporate | applied |
| C02 | Exact target range, 939-byte hash, 31 blocks, 298 instructions, padding and compiler tail | very strong | bytes/CFG | target prose / validator 13557 | incorporate | applied |
| C03 | ABI is bool MapPane member, one packet pointer, dispatcher case 0x33, retn 4 | very strong | caller/decompile/epilogue | target and MapPane class / validators 13557,13582 | incorporate | applied |
| C04 | Packet offsets +1/+3/+5/+6/+10 and dynamic +11/+12/+13 are exact | very strong | all reads | target/body / validator 13557 | incorporate | applied |
| C05 | Selector 0 consumes 43, selector 1 consumes 5, others return true before mutation | very strong | parser calls/branches | target/body / validator 13557 | incorporate | applied |
| C06 | ACP conversion uses length byte, 32 output cap, 33-wide buffer, returned-count terminator | very strong | call arguments/rangecheck | target/body / validator 13557 | incorporate | applied |
| C07 | Visible gate expands clamped bounds by one and tests y then x | very strong | geometry call order | target/body / validator 13557 | incorporate | applied |
| C08 | Factory call is objectId,mapX,mapY,action,status by value and result is unchecked Living pointer | very strong | caller/callee ABI | target and UID0002QN / validators 13557,13559 | incorporate | applied |
| C09 | Name copies to 33-wide buffer; +0x16c is m_objectInfoType | strong | direct writes/consumers | target/Living class/file / validators 13557,13564,13576 | incorporate | applied |
| C10 | Object-info cases preserve colors 12/39/224/55 and local type-3 skip | very strong | four branches | target/body / validator 13557 | incorporate | applied |
| C11 | Four ordinary ObjectInfo allocations call exact constructor with row,column and status colors | very strong | four call sites/EH | target/ObjectInfo / validators 13557,13562,13575 | incorporate | applied |
| C12 | Types 1-3 clear selected name and set m_tracksSelectedName; default clears flag | strong | setter plus direct flag writes | target/ObjectInfo / validators 13557,13562 | incorporate | applied |
| C13 | Replacement deletes old through UID0004QO, then Add/Update/GetBounds/Invalidate in exact order | very strong | call sequence/callee body | target prose/body / validator 13557 | incorporate | applied |
| C14 | Status overlay then group hit-bar refresh always precede true return after visible handling | very strong | common tail | target/body / validators 13557,13558 | incorporate | applied |
| C15 | No packet/name/null/type/conversion/allocation/list checks, cleanup, or false return | very strong | negative CFG review | target negative evidence / validator 13557 | incorporate | applied |
| C16 | Vptr/EH/cookie/rangecheck/scalar/delete/storage lowering stays out of handwritten source | very strong | compiler patterns | target/support history / generated 13588 | reject-invalid | applied |
| C17 | UID0003TW is a 100-byte file-static MapPane.cpp helper with two callers | very strong | no-this ABI/xrefs | Destination 2/helper / validator 13558 | incorporate | applied |
| C18 | UID0003TW copies status and requests effect only for exact shield/weapon predicates | strong | helper/callee decompile | Destination 2/helper / validator 13558 | incorporate | applied |
| C19 | UID0002QN status is by value; current const-ref formal is stale | very strong | retn 0x54/push layout | Destination 3/factory / validator 13559 | reject-stale | applied |
| C20 | UID0002QN item path detaches old, ordinary-news exact item, resolves ItemInfo, attaches light, then common tail | strong | complete factory decompile | Destination 3/item support / validators 13559,13566-13569,13584-13588 | incorporate | applied |
| C21 | UID0002QN local path normalizes human action, updates UserPane, copies appearance, deletes three overlays, clears flags | very strong | complete branch | Destination 3/User support / validators 13559,13565,13577 | incorporate | applied |
| C22 | UID0002QN nonlocal existing/new living branches and common screen/list/order are exact | very strong | complete branch | Destination 3 / validator 13559 | incorporate | applied |
| C23 | MapPane complete declaration removes stale ItemObjectImageEntry overload and corrects factory declaration without loss | very strong | current union/call ABI | Destination 4 / validator 13582 / exact formal comparison | incorporate | applied |
| C24 | ObjectInfoObjectPane complete 0x1c0 declaration, fields, exact inherited virtual signatures, friendship, position 40, 91/93 | strong | ctor/method/vtable/offsets plus byte-identical SetSpriteAttribute override | Destination 5 / validators 13562,13575 / generated 13588 | incorporate | applied |
| C25 | LivingObjectPane complete declaration preserves union and renames only +0x16c | strong | target write/current size | Destination 6 / validators 13564,13576 / generated 13588 | incorporate | applied |
| C26 | UserPane final 0x45 bytes split into one byte plus 68-byte m_currentAppearance | very strong | factory copy/size guard | Destination 7 / validators 13565,13577 / generated 13588 | incorporate | applied |
| C27 | ItemInfo +0x0c is lightImageIndex; row becomes 90/92 | strong | sole semantic consumer | Destination 8 / validators 13566,13584-13588 | incorporate | applied |
| C28 | ItemObjImageLib layout adds MapPane friendship and becomes 89/92; no runtime wrapper invented | strong | direct template access/source pattern | Destination 9 / validators 13567,13578-13579,13586-13588 | incorporate | applied |
| C29 | ItemObjectPane complete declaration plus file/parent/support prose/history/collision sync; exact child bodies remain singly owned and verify-only dependencies stay unchanged | strong | fresh Item family MCP/current docs/reports | Destination 10 and named prose supports / validators 13568-13574 / generated 13588 | incorporate | applied |
| C30 | Supervisor coverage handoff and callback validators/generated exact-count checks are complete, collision-safe, and implementation-verifiable against the stable B003/B004/B005 union | very strong | command-13589/13590/13591/13592 applied no-loss manual epoch plus final generated readback | coverage/checklist / validators 13588 and 13589-13592 | incorporate | applied |

## Positive Evidence Summary

- One dispatcher call at `0x00508818` selects case `0x33` and adjusts the receiver by `-0xa0` to MapPane.
- Every packet read has a stable offset/width and converges on current parser, geometry, factory, object-info, ObjectList, and refresh APIs.
- Four allocation sites and their colors/flag writes preserve source switch shape; the local-player type-3 skip is explicit.
- The factory's `retn 0x54` settles the largest ABI contradiction: 68-byte status by value.
- ObjectInfo constructor/setters/vtable, LivingObjectPane owner field, UserPane size tail, ItemInfo row, and ItemObjImageLib protected-array shape independently close compile visibility.
- Current source-tree ownership already places class members in MapPane and the receiverless helper in MapPane.cpp.
- Exact negative evidence constrains the draft: safety and compiler scaffolding must not be invented.

## IDA MCP Facts

- Target: `[0x0050fb00,0x0050feab)`, size `0x3ab`, SHA256 `1504D80F39145D54D0CC86F1FABC16E653C0914EC00AD264FBBBE4035C808F72`, 31 blocks, cyclomatic complexity 7, 298 instructions.
- Helper: `[0x0050fa90,0x0050faf4)`, size `0x64`, SHA256 `E075F870AB16785AB278DC716D244A976005E59C49F499C5B01379900ABF7E48`.
- Factory: `[0x00505e00,0x005060e3)`, size `0x2e3`.
- Target prepadding `[0x0050faf4,0x0050fb00)` is twelve `0xcc` bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`.
- Target postpadding `[0x0050feab,0x0050feb0)` is five `0xcc` bytes, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`.
- Target's only caller is dispatcher `0x00508818`. Helper callers are UID0003TX `0x0050fe75` and UID0003TT `0x00513634`.
- The instruction after target `retn 4` is an unreachable compiler range-check failure call, not a source continuation.
- UID0003TW copies one exact 68-byte status and requests the nameplate effect only for Human status with shield/arrow ids 13,14,15,16,27 or weapon ids 146,161.
- ObjectInfo setter `0x00539690` performs the exact bounded selected-name fixed-array copy for UID0003TX's empty string; its unrelated overlength fallback truncates into the primary-name array and is preserved as support evidence. UID0004QO, not the name setter, unconditionally deletes the old ObjectInfo pane before storing the new pointer.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050faf4-0x0050fb00` | ignored padding | alignment | false | none | n/a | keep ignored |
| `0x0050fb00-0x0050feab` | UID0003TX target | MapPane member | true | UID00007Q | 92/94 applied | source-ready/emitting |
| `0x0050feab-0x0050feb0` | ignored padding | alignment | false | none | n/a | keep ignored |
| `0x0050fa90-0x0050faf4` | UID0003TW | MapPane.cpp static helper | true | UID0000L3 | 91/93 applied | source-ready/emitting |
| `0x00505e00-0x005060e3` | UID0002QN | MapPane factory member | true | UID00007Q | 92/94 applied | corrected source-ready/emitting |
| ObjectInfo declaration | UID00009P | attached overlay class | true | UID0000HJ | 91/93 applied | declaration applied |
| Living declaration | UID00007B | living object class | true | UID0000KU | 92/93 retained | one field rename |
| User declaration | UID0000FQ | local player class | true | UID0000P1 | 93/94 retained | tail split |
| ItemInfo | UID0001UT | render-table row | true | UID0000KH | 90/92 applied | field resolved |
| ItemObjImageLib layout | UID0001UU | class/header layout | true | UID00006W | 89/92 applied | friendship added |
| ItemObjectPane declaration | UID00006V | ground-item class/header | true | UID0000KG | 92/93 applied | complete declaration applied |
| ItemObjectPane exact methods | UID0003HQ/HR/HS/HT/HU | constructor/destructor/update/virtual overrides | true | UID00006V | retained | declarations synchronized; bodies stay exact-child owned |
| packet-handler aggregate | UID0001AW | semantic split index | false | UID00007Q | 86/90 retained | prose/index only |
| ObjectInfo vtable | UID000355 | compiler ABI data | false | UID00009P | 90/93 retained | no raw source |
| UID0003TT/status parsers | existing exact pages | verify-only callers/callees | true | existing owners | retained | no edit unless drift |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00508818` | dispatcher -> UID0003TX | only target caller; case 0x33 |
| `0x0050fba3` | ParseFullStatus | selector 0, consumes 43 |
| `0x0050fbbc` | ParsePartialStatus | selector 1, consumes 5 |
| `0x0050fe75` | UID0003TX -> UID0003TW | first status-overlay caller |
| `0x00513634` | UID0003TT -> UID0003TW | second status-overlay caller |
| `0x0050fd17/0x0050fd8f/0x0050fdd1/0x0050fe10` | ObjectInfo constructors | four case-specific allocations |
| `0x0050fe29` | SetSelectedName | alternate empty-name route |
| `0x0050fe38` | UID0004QO | delete-old/store-new ObjectInfo pane |
| `0x0050fe43` | ObjectList::AddObjectPane | registration after replacement |
| `0x0050fe4c` | ObjectInfo UpdatePosition | owner-relative positioning |
| `0x0050fe5b..0x0050fe70` | bounds/invalidate | exact redraw order |
| `0x0050fe75/0x0050fe7f` | overlay/group refresh | common tail |
| `0x0053bab0` | RequestNameplateEffect dependency | effect 135, timer -2 route |
| `0x00511664` | independent UID0002QN caller | confirms objectId/mapX/mapY/action/status order |

## Documentation Evidence And IDA Status

- Historical pre-callback UID0003TX state was `86/90` with correct split/opcode/owner/padding facts but blank formal C++ and unresolved source blockers. Current applied state is `92/94` with Destination 1, the exact Item Summary, full evidence, retained owner/emitter/reconstructable/blank position/Nested metadata, and the stale enum correction explicitly historicalized.
- Historical pre-callback UID0003TW state was `86/89`, blank, with only file-owner/caller facts and broad status wording. Current applied state is `91/93` with Destination 2, exact file-static linkage, two-caller inventory, status-copy predicates, and nameplate-effect role.
- Historical pre-callback UID0002QN state was `88/90` and emitted a behaviorally stale const-reference-style body. Current applied state is `92/94` with Destination 3's exact by-value ABI and complete item/local/existing/new-living behavior.
- Historical pre-callback UID00009P state was an `85/89` blank class emitter while manual coverage still said 82. Current applied state is `91/93` at position 40 with Destination 5's complete `0x1c0` declaration; command 13590 records the same 91 row. The exact inherited surface is `ClearOutputRects(RectBounds *, RectBounds *)`, `RenderFrame(GrafPort *, const RectBounds *)`, `SetSpriteAttribute(unsigned char)`, and `UpdatePosition()`; stale no-argument and directional labels remain historical only.
- UID00007B and UID0000FQ are strong complete declarations; the one semantic field rename and one size-neutral tail split are applied without declaration-union loss.
- Historical pre-callback ItemInfo docs called `+0x0c` provisional `renderFlagsOrMode`. Current applied UID0001UT state is `90/92` with source-facing `lightImageIndex`; UID0002SD, ItemObjImageLib prose, generated ItemObjImageLib.cpp, and command-13592 manual coverage use the corrected name with zero stale generated occurrences.
- Historical pre-callback UID00006V state was an `86/89` blank class emitter whose prose deferred field/helper names. Current applied state is `92/93` at position 10 with Destination 10's complete `0x12c` declaration, exact fields, constructor ABI, ordinary destructor declaration, status-update declaration, inherited `ClearOutputRects`/`RenderFrame` override identities, and no duplicate child bodies.
- Historical command-13552 generated output exposed the pre-callback blockers: one target marker, no helper, stale factory, one ObjectInfo class marker, old Living field, unresolved User tail, and old ItemInfo name. Current command-13588 output resolves all of them: one target definition, one helper declaration and definition, one corrected factory, complete ObjectInfoObjectPane and ItemObjectPane classes, `m_objectInfoType`, `m_currentAppearance`, and `lightImageIndex`, with zero corresponding stale markers/names or duplicate definitions.
- Current MapServerPacketOpcode is already correct; no enum edit is recommended.

## Ranked Ownership Analysis

### 1. MapPane class and MapPane.cpp

- Evidence for: dispatcher receiver adjustment, direct MapPane fields, object list/local player/bounds methods, current class declaration, source-family ordering, and all sibling packet handlers.
- Evidence against: none. The helper has no receiver, so it belongs to the file rather than class.
- Decision: UID0003TX and UID0002QN are class members owned/emitted by UID00007Q; UID0003TW is file-static under UID0000L3.

### 2. ObjectInfoObjectPane / LivingObjectPane

- Evidence for: target constructs/replaces ObjectInfo and writes Living name/type state.
- Evidence against: neither receives the target's this pointer or owns packet dispatch/bounds/list/group refresh.
- Decision: support declaration/field owners only.

### 3. ObjectList / ObjectStatusBlob / packet utilities

- Evidence for: list registration, parser calls, big-endian reads.
- Evidence against: dependency APIs with independent owners; no target body or receiver ownership.
- Decision: verify-only dependencies except exact support prose where the target resolves a stale consumer fact.

### Proposed new file/grouping, if applicable

- No new source file. MapPane.cpp is the established module.
- No new children. All exact source-bearing pages already exist.
- The only ordering requirement is a static helper declaration before UID0003TX and helper definition under its existing file-emitter page.

## Source Placement

- UID0003TX belongs in `NexusTK/map/MapPane.cpp` as the opcode-0x33 MapPane member.
- UID0003TW belongs in the same translation unit as a file-static helper because it lacks a receiver and has exactly two MapPane method callers.
- UID0002QN remains a MapPane member in the same translation unit.
- ObjectInfoObjectPane declaration belongs to the AttachedObjectPane header/source family under UID0000HJ; its method bodies remain exact child-owned work.
- LivingObjectPane/UserPane declarations remain in their current modules. ItemInfo and ItemObjImageLib layout remain ItemObjImageLib-owned render declarations.
- Rejected placements: ObjectList, packet enum, ObjectStatusBlob, LivingObjectPane, and ObjectInfoObjectPane cannot own the target; a new packet helper file would split a tightly coupled MapPane source family without binary/source-tree evidence.
- Callback collision order was deterministic: B003 UID0003TJ, B005 UID0003TK, and B004 UID0003TO completed ordinary deltas formed the stable read-only MapPane baseline. After supervisor clearance, B002 reread the parent/class/file under each short lease, verified the complete B003/B004/B005/B011 union, and applied only this report's factory/declaration/prose delta callback-last. Disjoint UID0003TX/helper/ObjectInfo/Living/User/Item pages did not overlap those agents' target bodies.

## Range / Split / Padding / Reclassification Analysis

- UID0003TX is already the exact modeled function. No interior split or jump table is present.
- Twelve bytes `0x0050faf4-0x0050fb00` and five bytes `0x0050feab-0x0050feb0` remain ignored alignment padding.
- UID0003TW is an independent modeled function ending at the prepadding, not target prelude code.
- The target's out-of-line range-check-failure call after `retn 4` is compiler failure lowering and does not extend the source body.
- UID0001AW remains a semantic non-emitting packet-handler index; adding complete child bodies must not create duplicate aggregate source.
- UID000355 remains a covered-by/no-raw-vtable ABI child. Scalar deleting destructors/adjustors and compiler tables remain non-emitting.
- No target rename/path change or new validator UID is required.

## Negative Evidence Summary

- No second target caller, absolute pointer route, vtable slot, or duplicate source copy was found.
- No packet length check precedes any read; no name-length clamp precedes conversion; no conversion-failure branch exists.
- No null/type check follows the object factory; no allocation failure check exists at four ObjectInfo allocations.
- No list-insert, position, bounds, invalidate, overlay, or group-refresh failure path exists.
- No false return exists.
- The selector default performs no parser/name/object mutation and returns true immediately.
- The local type-3 path does not allocate/replace/register ObjectInfo, but still reaches both refresh calls.
- Default object-info type includes zero and values above three; it is not an error path.
- UID0003TW has no MapPane receiver and no callers outside the two MapPane packet handlers.
- No live consumer supports retaining the old generic `m_nameStateToken` or `renderFlagsOrMode` spellings; UID0003TX/UID0002QN directly support `m_objectInfoType` and `lightImageIndex` instead.
- No current support justifies hand-authored vptr stores, pool allocation calls, SEH, cookies, range-check calls, deleting flags, or storage free.

## IDA Rename / Type / Comment Recommendations

- Read-only recommendations only; no IDA mutation was requested or performed.
- `sub_50FB00` -> `MapPane::HandleObjectInfoPacket(const unsigned char *)`.
- `sub_50FA90` -> file-static `RefreshObjectStatusOverlay(LivingObjectPane *)`.
- `sub_505E00` -> `MapPane::CreateOrUpdateObjectPane(int objectId, int mapX, int mapY, unsigned char action, ObjectStatusBlob status)`.
- `sub_537B40` -> `ItemObjectPane::ItemObjectPane(int objectId, int mapX, int mapY, short itemId, unsigned char paletteFlags)`.
- `sub_537BC0` -> `ItemObjectPane::UpdateItemStatus(const ObjectStatusBlob *)`.
- Historical `BuildCenteredItemRect` at `0x00537bf0` -> inherited override `ItemObjectPane::ClearOutputRects(RectBounds *, RectBounds *)`.
- Historical `ProcessItemAction` at `0x00537c70` -> inherited override `ItemObjectPane::RenderFrame(GrafPort *, const RectBounds *)`.
- LivingObjectPane `+0x16c` -> `m_objectInfoType`.
- ObjectInfoObjectPane `+0x12c` -> `m_tracksSelectedName`; `0x539690` -> `SetSelectedName`.
- `sub_539B20` -> `ObjectInfoObjectPane::SetSpriteAttribute(unsigned char)` because it is byte-for-byte and vtable-slot equivalent to AttachedObjectPane `0x00538600`; retain `UpdatePositionFromDirection` only as a rejected/superseded descriptive alias for the body effect.
- UserPane `+0x13eb40` -> `m_currentAppearance`.
- ItemInfo `+0x0c` -> `lightImageIndex`.
- Keep packet category values literal because no named source enum is independently proven.
- Keep ObjectInfo color values literal because no color enum/token is independently proven.
- Keep the final one-byte UserPane field as `m_userPaneTrailingState2` because no consumer supplies a narrower meaning.

## First-Draft C++ Recommendation

All C++ below is destination-specific exact insertion text. No C++ appears elsewhere in this report.

### Destination 1 - UID0003TX target

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void RefreshObjectStatusOverlay(LivingObjectPane *objectPane);

bool MapPane::HandleObjectInfoPacket(const unsigned char *packet)
{
    const int mapX = PacketBufferReadUInt16BE(packet + 1);
    const int mapY = PacketBufferReadUInt16BE(packet + 3);
    const unsigned char action = packet[5];
    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 6);

    ObjectStatusBlob status;
    status.m_displayStatusByte = 80;
    status.m_actionState = 11;

    int statusBytes;
    switch (packet[10])
    {
    case 0:
        statusBytes = status.ParseFullStatus(packet + 11);
        break;

    case 1:
        statusBytes = status.ParsePartialStatus(packet + 11);
        break;

    default:
        return true;
    }

    const unsigned char objectInfoType = packet[11 + statusBytes];
    const unsigned char nameLength = packet[12 + statusBytes];

    wchar_t objectName[33];
    const int objectNameLength = MultiByteToWideChar(
        CP_ACP,
        0,
        reinterpret_cast<const char *>(packet + 13 + statusBytes),
        nameLength,
        objectName,
        32);
    objectName[objectNameLength] = L'\0';

    MapRect visibleBounds;
    GetClampedVisibleTileBounds(&visibleBounds);
    InsetRect(&visibleBounds, -1, -1);
    if (!PointInRect(mapY, mapX, &visibleBounds))
        return true;

    LivingObjectPane *objectPane =
        static_cast<LivingObjectPane *>(
            CreateOrUpdateObjectPane(
                objectId,
                mapX,
                mapY,
                action,
                status));

    wcscpy_s(objectPane->m_nameBuffer, 33, objectName);
    objectPane->m_objectInfoType = objectInfoType;

    if (objectInfoType != 3 || objectPane != m_localPlayerObjectPane)
    {
        ObjectInfoObjectPane *objectInfoPane;

        switch (objectInfoType)
        {
        case 1:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                12,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->SetSelectedName(L"");
            objectInfoPane->m_tracksSelectedName = true;
            break;

        case 2:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                39,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->SetSelectedName(L"");
            objectInfoPane->m_tracksSelectedName = true;
            break;

        case 3:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                224,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->SetSelectedName(L"");
            objectInfoPane->m_tracksSelectedName = true;
            break;

        default:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                55,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->m_tracksSelectedName = false;
            break;
        }

        objectPane->SetObjectInfoObjectPane(objectInfoPane);
        m_objectList->AddObjectPane(objectInfoPane);
        objectInfoPane->UpdatePosition();

        RectBounds bounds;
        objectInfoPane->GetBounds(&bounds);
        objectInfoPane->InvalidateRect(&bounds);
    }

    RefreshObjectStatusOverlay(objectPane);
    RefreshGroupMemberHitBar(objectId);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID0003TW file-static helper

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void RefreshObjectStatusOverlay(LivingObjectPane *objectPane)
{
    ObjectStatusBlob status;
    status.m_displayStatusByte = 80;
    objectPane->GetSpriteConfig(&status);

    if (status.m_statusKind == ObjectStatusBlob::HumanObject &&
        (status.m_shieldOrArrowId == 13 ||
         status.m_shieldOrArrowId == 14 ||
         status.m_shieldOrArrowId == 15 ||
         status.m_shieldOrArrowId == 16 ||
         status.m_shieldOrArrowId == 27 ||
         status.m_weaponId == 146 ||
         status.m_weaponId == 161))
    {
        objectPane->RequestNameplateEffect();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0002QN corrected factory

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ObjectPane *MapPane::CreateOrUpdateObjectPane(
    int objectId,
    int mapX,
    int mapY,
    unsigned char action,
    ObjectStatusBlob status)
{
    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    bool alreadyListed = false;

    if (status.m_statusKind == ObjectStatusBlob::ItemObject)
    {
        if (objectPane != NULL)
            DetachObjectPane(objectPane);

        ItemObjectPane *itemObjectPane = new ItemObjectPane(
            objectId,
            mapX,
            mapY,
            status.m_appearanceId,
            status.m_variantOrPalette);
        objectPane = itemObjectPane;

        const ItemInfo *itemInfo =
            g_pItemObjImageLib->m_itemInfos.GetAtOrDefault(
                static_cast<unsigned short>(
                    status.m_appearanceId + 0x4000));
        if (itemInfo->lightImageIndex >= 0)
        {
            AttachObjectLighting(
                itemObjectPane,
                g_mapTilePixelWidth / 2,
                g_mapTilePixelHeight / 2,
                itemInfo->lightImageIndex);
        }
    }
    else if (status.m_statusKind == ObjectStatusBlob::HumanObject ||
             status.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        if (m_localPlayerObjectPane->GetObjectId() == objectId)
        {
            if (objectPane != NULL)
                m_objectList->RemoveObjectPane(objectPane);

            RecenterAndSendPosition(mapX, mapY, 0, 0, true);

            UserPane *userPane =
                static_cast<UserPane *>(m_localPlayerObjectPane);
            objectPane = userPane;

            if (status.m_statusKind == ObjectStatusBlob::HumanObject &&
                status.m_actionState == 2)
            {
                status.m_actionState = 5;
            }

            userPane->SetSpriteConfig(&status, action);
            if (status.m_statusKind == ObjectStatusBlob::HumanObject)
                userPane->m_currentAppearance = status;

            delete userPane->m_hitBarObjectPane;
            delete userPane->m_damageNumberObjectPane;
            delete userPane->m_balloonObjectPane;

            userPane->m_transientObjectFlag = false;
            if (m_waitingForLocalPlayerStatus == 1)
                m_waitingForLocalPlayerStatus = 0;
        }
        else
        {
            if (static_cast<UserPane *>(
                    m_localPlayerObjectPane)->m_playerSettingsState[0] &&
                status.m_statusKind == ObjectStatusBlob::HumanObject &&
                status.m_actionState == 2)
            {
                status.m_actionState = 5;
            }

            if (objectPane != NULL)
            {
                LivingObjectPane *livingObjectPane =
                    static_cast<LivingObjectPane *>(objectPane);
                livingObjectPane->InitializeSpriteConfig(&status, action);
                livingObjectPane->SetMapPosition(mapX, mapY);
                livingObjectPane->m_transientObjectFlag = false;
                alreadyListed = true;
            }
            else
            {
                objectPane = new LivingObjectPane(
                    objectId,
                    mapX,
                    mapY,
                    status,
                    action);
            }
        }

        static_cast<LivingObjectPane *>(objectPane)->
            ScheduleBoxRotationStep();
    }
    else
    {
        return NULL;
    }

    UpdateObjectPaneScreenBounds(objectPane);
    if (!alreadyListed)
        m_objectList->AddObjectPane(objectPane);

    return objectPane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - UID00007Q complete MapPane declaration

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
        int objectId,
        int mapX,
        int mapY,
        unsigned char action,
        ObjectStatusBlob status);
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

### Destination 5 - UID00009P complete ObjectInfoObjectPane declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ObjectInfoObjectPane : public AttachedObjectPane
{
public:
    ObjectInfoObjectPane(
        LivingObjectPane *owner,
        int mapY,
        int mapX,
        const wchar_t *primaryName,
        int textColor,
        unsigned char outlineColor,
        unsigned char fillColor);
    virtual ~ObjectInfoObjectPane();

    void SetPrimaryName(const wchar_t *name);
    void SetSelectedName(const wchar_t *name);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void UpdatePosition();

private:
    friend class MapPane;

    bool m_tracksSelectedName;               // +0x12c
    wchar_t m_primaryName[33];               // +0x12e
    wchar_t m_selectedName[33];              // +0x170
    int m_textColor;                         // +0x1b4
    unsigned char m_outlineColor;            // +0x1b8
    unsigned char m_fillColor;               // +0x1b9
    LivingObjectPane *m_nameOwner;           // +0x1bc
};

typedef char ObjectInfoObjectPaneSizeMustBe448[
    sizeof(ObjectInfoObjectPane) == 0x1c0 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 6 - UID00007B complete LivingObjectPane declaration

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

### Destination 7 - UID0000FQ complete UserPane declaration

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

    GroupMemberRecord *FindGroupMemberById(unsigned int memberId);

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

### Destination 8 - UID0001UT ItemInfo declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ItemInfo
{
    int itemTableId;
    int paletteSlot;
    float alpha;
    int lightImageIndex;
    bool allowPaletteFilter;
    unsigned char reserved[3];
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 9 - UID0001UU ItemObjImageLib layout

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemObjImageLib : public LObject
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageIn43x43Slot(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 10 - UID00006V complete ItemObjectPane declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ObjectStatusBlob;

class ItemObjectPane : public ObjectPane
{
public:
    ItemObjectPane(
        int objectId,
        int mapX,
        int mapY,
        short itemId,
        unsigned char paletteFlags);
    virtual ~ItemObjectPane();

    void UpdateItemStatus(const ObjectStatusBlob *status);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);

protected:
    short m_itemId;                          // +0x128
    unsigned char m_paletteFlags;            // +0x12a
};

typedef char ItemObjectPaneSizeMustBe300[
    sizeof(ItemObjectPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- The ten formal blocks above are the only C++ in this report.
- The target/helper/factory bodies preserve unchecked behavior, four separate allocation sites, local-player skip, exact refresh ordering, destination linkage, and compiler/source exclusions.
- The full class blocks preserve every current unrelated declaration/field/size guard/`[[CHILDREN]]` union. Destination 4 removes only the stale `ItemObjectImageEntry` forward/overload and corrects UID0002QN's declaration. Destinations 6 and 7 change only the identified size-neutral fields.

## Final Recommendation

- Formal Destinations 1-10, every named prose destination, and C01-C30 are applied. All ten managed blocks match their destination blocks exactly.
- Only the stated target/support scores were raised. Every owner/emitter/reconstructable route and all same-or-greater evidence are preserved.
- Keep UID0001AW non-emitting. Keep UID000355 and compiler scalar/adjustor/vtable/EH/table artifacts non-emitting.
- Do not modify MapServerPacketOpcode; historicalize the target's stale correction note.
- Do not duplicate ObjectInfo method bodies in the class declaration.
- Do not add reconstruction metadata to by-file roots.
- Shared MapPane callback order was honored: the stable B003 UID0003TJ + B005 UID0003TK + B004 UID0003TO ordinary union was the leased baseline and B002 UID0003TX was applied callback-last. Destination 4 was line-verified after the edit and differs from that baseline only by the accepted UID0002QN factory signature and stale `ItemObjectImageEntry` declaration/overload removal.

## Recommended Target Doc Changes

- Applied path: `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md`.
- Applied `COMPLETION:92`, `CONFIDENCE:94`; retained owner/emitter `00007Q`, reconstructable true, blank position, `Nested:0`.
- Item Summary: `Opcode-0x33 MapPane member that parses full/partial ObjectStatusBlob payloads, converts a bounded ACP object name, creates or updates visible living state, replaces/registers ObjectInfoObjectPane labels by type, and refreshes status/group overlays with exact unchecked behavior.`
- Destination 1 is installed byte-for-byte.
- Full range/hash/instruction/CFG/caller/callee/packet/status/text/bounds/object/type/color/replacement/list/refresh/return/negative/compiler/source-placement/score evidence is incorporated.
- Old split/provenance findings are preserved; blank-C++, provisional-name, and stale enum-correction claims are labeled historical/superseded.

## Recommended Support Doc Changes

1. `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md`: applied `86/89 -> 91/93`, retained owner/emitter `0000L3`, reconstructable true, blank position, Nested 0, and added exact summary/body/predicate/callers/source placement.
2. `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md`: applied `88/90 -> 92/94`, retained owner/emitter `00007Q`, reconstructable true, blank position/Nested, replaced the stale formal with Destination 3, and preserved prior valid behavior/history as superseded where corrected.
3. `by-class/MapPane.md`: retained `93/94`, owner/emitter `0000L3`, position 0; installed Destination 4 after the required shared-baseline clearance and leased no-loss rebase. The complete B003/B005/B004/B011 and unrelated union remains present.
4. `by-class/ObjectInfoObjectPane.md`: applied `85/89 -> 91/93`, retained owner/emitter `0000HJ`, reconstructable true, set position 40, and installed Destination 5 with complete layout/method/compiler evidence and superseded directional history.
5. `by-class/LivingObjectPane.md`: retained `92/93` and the complete union; installed Destination 6 with only the `m_objectInfoType` rename.
6. `by-class/UserPane.md`: retained `93/94` and the complete union; installed Destination 7 with only the final-byte/status split.
7. `by-type/by-struct/ItemInfo.md`: applied `85/89 -> 90/92` and Destination 8.
8. `by-type/by-struct/ItemObjImageLibLayout.md`: applied `87/90 -> 89/92` and Destination 9.
9. `by-class/ItemObjectPane.md`: applied `86/89 -> 92/93`, position 10, and Destination 10 while preserving exact method/vtable/pool/history evidence.
10. `by-file/ItemObjectPane.md`: applied `86/88 -> 90/92` and prose-only class/constructor/factory/source-order/compiler-exclusion synchronization; no by-file reconstruction metadata was added.
11. UID0003HQ/HR/HS/HT/HU exact method pages retained their ranges/owners/bodies; declarations and stale aliases were synchronized without duplicate bodies.
12. `by-file/MapPane.md`, `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`, `by-file/AttachedObjectPane.md`, `by-file/LivingObjectPane.md`, `by-file/UserPane.md`, `by-class/ItemObjImageLib.md`, `by-file/ItemObjImageLib.md` received the accepted prose-only synchronization without by-file reconstruction metadata. UID0002SD was additionally corrected under the concrete-drift exception so generated ItemObjImageLib uses `lightImageIndex` consistently.
13. Verify-only UID0003TT, UID0003TB, UID0003Z4/UID0004QO, UID00009S/UID0004LL/UID0004LM, UID0002C9/ObjectList, geometry/packet helpers, UID00034Y/UID000355, MapServerPacketOpcode, and generic siblings remained unchanged. UID0002SD alone required the documented concrete-drift correction.
14. Read-only coordination preserved B003 UID0003TJ and B005 UID0003TK completed ordinary callback facts plus supervisor-executed B004 UID0003TO/UID0003TH facts; B002 did not edit another agent's report.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Applied | Metadata |
| --- | --- | --- | --- |
| UID0003TX | 86/90 | 92/94 | owner/emitter/reconstructable/blank position/Nested retained |
| UID0003TW | 86/89 | 91/93 | owner/emitter/reconstructable/blank position/Nested retained |
| UID0002QN | 88/90 | 92/94 | owner/emitter/reconstructable/blank position/Nested retained |
| UID00007Q | 93/94 | 93/94 | complete union retained |
| UID00009P | 85/89 | 91/93 | owner/emitter retained; position 40 |
| UID00007B | 92/93 | 92/93 | one field rename only |
| UID0000FQ | 93/94 | 93/94 | size-neutral tail split |
| UID0001UT | 85/89 | 90/92 | `+0x0c` semantics resolved |
| UID0001UU | 87/90 | 89/92 | friendship/source access resolved |
| UID00006V | 86/89 | 92/93 | complete 0x12c declaration, fields, constructor ABI, and override identities resolved |
| UID0000KG | 86/88 | 90/92 | complete class/source route and compiler exclusions synchronized |
| all other support | current | current | verify-only/prose-only |

Score-blocker audit:
- Blank C++: resolved by three complete bodies and seven complete declarations.
- Packet/status/type names: resolved to exact widths plus evidence-backed descriptive names.
- Helper liveness/linkage: resolved by two xrefs and no-this ABI.
- Factory ABI/body: resolved through all blocks and `retn 0x54`.
- ObjectInfo declaration/layout: resolved through constructor/method/vtable/field consumers.
- Living/User/Item fields: resolved by direct consumers and size arithmetic.
- ItemObjectPane declaration: resolved by fresh five-function/vtable/base-slot reanalysis; no blank class emitter remains in the recommendation.
- Source placement: resolved by current module/class/file union.
- Compiler/source distinction: resolved explicitly.
- Manual coverage: exact handoff supplied, then applied and validated by the supervisor as a same-or-greater no-loss union through commands 13589-13592.
- Scores remain below 95 only because original private symbols and a reusable packet struct are unavailable, not because implementation is blocked.

## Open Questions With Attempted Resolution

- Is packet `+10` an object subtype? No. It selects status encoding; object-info type follows the consumed status bytes.
- Is UID0003TW a class member? No. No receiver and two file-local callers prove a static file helper.
- Is factory status a const reference? No. `retn 0x54` proves by-value 68-byte status after scalar arguments.
- Is object-info type 3 always omitted? Only for the local player; nonlocal type 3 creates color-224 info.
- Does type 0 represent an error? No. It follows default color 55 and creates/registers info.
- Can the four allocations be folded? Not in the recommended source; separate case allocations best reproduce four EH sites and branch-local constructor constants.
- Is `+0x12c` a generic selection flag? Best resolution is `m_tracksSelectedName` because it is true only after alternate-name setup and false on primary-only default.
- Is Living `+0x16c` a token? No consumer supports token behavior; this handler stores only object-info type.
- Is ItemInfo `+0x0c` generic render mode? No. The recovered consumer treats it as a nonnegative light image index.
- How can MapPane access protected-array/private overlay fields? Source-era friendship is already used in this codebase and exactly represents direct access without runtime wrappers.
- Does UID0002QN have a compile-visible ItemObjectPane constructor? Yes. Destination 10 supplies the exact class, constructor ABI, fields, inherited virtual declarations, size guard, and child insertion point; exact child bodies remain singly owned.
- Does the enum need repair? No. Current MapServerPacketOpcode is already correct; only target prose is stale.
- Remaining unresolved question: exact original lexical spellings. This caps confidence but does not block behavior-identical, compile-visible source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current supervisor-applied no-loss manual union, reread after commands `000000013589`-`000000013592`:
- `by-memory/-coverage-report.md` SHA256 `B9CC8370ECCB987D6D0559E926D86D4E6510579F49D27FA9D2ED1D0A46D2C7E9`, 1,733,037 bytes/4,186 lines; command `13589`, `2026-07-16T00:35:58-04:00`, exit 0, `ok:1`.
- `by-class/-coverage-report.md` SHA256 `07D98BB8124B476FB9E2B39D298AB5BE92E1D21714F3B9622A0CA810D89F146B`, 224,612 bytes/622 lines; command `13590`, `2026-07-16T00:36:07-04:00`, exit 0, `ok:1`.
- `by-file/-coverage-report.md` SHA256 `3BF998864768EC10DA471D4566381B64EFC8BDDD1B1E9B2633C305662522DA1C`, 128,401 bytes/316 lines; command `13591`, `2026-07-16T00:36:18-04:00`, exit 0, `ok:1`.
- `by-type/by-struct/-coverage-report.md` SHA256 `C0FA7E9B4079CC5080CBE9AC7FF16F7C2A11E1030EE6AC0EA2F503C6B468F873`, 57,159 bytes/137 lines; command `13592`, `2026-07-16T00:36:28-04:00`, exit 0, `ok:1`.
- Current by-memory anchors are UID0002QN line 2226, UID0001AW line 2278, B003 UID0003TI/UID0003TJ lines 2291-2292, B002 UID0003TW/UID0003TX lines 2293-2294, corrected UID0003TK line 2296, and UID0003TO line 2298. The class/file/type rows contain every accepted B002 score and semantic update while retaining longer pre-existing evidence. The supervisor intentionally merged the delta instead of replacing same-or-greater rows with shorter text. B002 did not edit any manual file.

Historical accepted shorter handoff text, preserved for provenance and no longer a current replacement instruction:

1. Historical proposal: replace UID0002QN row in by-memory. Current command-13589 state incorporates this semantic delta into the no-loss row:
    - [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md) 0x00505e00-0x005060e3 | class method | MapPaneCreateOrUpdateObjectPane : reconstructable : 92% : very-strong : Exact by-value ObjectStatusBlob MapPane factory with objectId/mapX/mapY/action ABI, complete item/local-player/existing/new-living branches, typed ItemInfo light-image lookup, exact overlay deletion and current-appearance copy, common screen-bounds/ObjectList order, and compiler-allocation exclusions.

2. Historical proposal: replace UID0001AW with this complete stable-union parent row. Current command-13589 state retains the pre-existing union and incorporates the same B002 opcode-`0x33` delta:

```text
    - [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | packet-handler split index | MapPanePacketHandlers : not_reconstructable : 86% : very-strong : Non-emitting MapPane packet-handler split/container with exact source-bearing children, including source-ready UID0003TI/UID0003TJ static-object creation/region reconciliation, source-ready UID0003TK opcode-0x15 map/effect-state parsing and direct bool return, source-ready UID0003TO opcode-0x29 trusted-packet object/effect routing with signed descriptor/action, coordinate/object requests, compiler-inlined FlashMapColor(143), unconditional success, and preserved unsafe/no-length behavior, plus source-ready UID0003TX opcode-0x33 ObjectStatusBlob parsing, visible-bounds/factory/ObjectInfo replacement, and status/group refresh behavior; preserves unrelated packet/helper dispositions, live opcode `0x67` TimerPane create/update/delete flow, retained duplicate `0x005140a0` with zero inbound xrefs or pointer route, MapPane ownership of parsing, and TimerPane ownership of the called constructor/SetTimer source.
```

3. Applied command-13589 address-order result: current UID0003TH and padding, B003 UID0003TI/UID0003TJ, B002 UID0003TW/UID0003TX, UID0001AX, corrected B005 UID0003TK, UID0003TL, B004 UID0003TO, and UID0001AY are all preserved in order. The following accepted rows remain historical handoff text; the current file contains their semantics as a no-loss union. B002 does not claim ownership of B003/B005/B004 rows.
    - [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) 0x0050f030-0x0050f130 | private method | MapPaneCreateStaticObjectPaneForTile : reconstructable : 90% : very-strong : Exact source-ready MapPane static-object creation helper with typed tile/id/skip-insertion ABI, StaticObjImageLib bounds and metadata, preserved discarded IsRectEmptyOrInvalid call, ordinary-new StaticObjectPane pool lowering, optional lighting, screen-bounds update, ObjectList insertion gate, exact range/hash/caller, and compiler-only EH/pool cleanup exclusions.
    - [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) 0x0050f130-0x0050f26d | private method | MapPaneRefreshStaticObjectTileRegion : reconstructable : 91% : very-strong : Exact source-ready row-major half-open MapRect reconciliation method with one-argument void thiscall ABI, six-byte tile output/staticObjectId, typed static-row lookup, matching-id retention, duplicated invalidate/remove/release/delete order, nonzero replacement creation, four callers, exact bytes/hash/padding, and EDI/EAX/compiler-lowering exclusions.
    - [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) 0x0050fa90-0x0050faf4 | file-static helper | RefreshObjectStatusOverlay : reconstructable : 91% : very-strong : Exact MapPane.cpp helper shared by object-info and object-status handlers; copies 68-byte LivingObjectPane status and requests the nameplate effect only for Human shield/arrow ids 13/14/15/16/27 or weapon ids 146/161.
    - [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) 0x0050fb00-0x0050feab | class method | MapPaneHandleObjectInfoPacket : reconstructable : 92% : very-strong : Exact opcode-0x33 MapPane handler with full/partial ObjectStatusBlob parsing, bounded ACP name conversion, expanded visible-bounds gate, by-value object factory call, type-specific ObjectInfo replacement/registration, and exact status/group refresh tail with all unchecked behavior preserved.
    - [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) 0x005104d0-0x00510958 | method | MapPaneHandleEffectMapStatePacket : reconstructable : 92% : very strong : Source-ready opcode-0x15 MapPane effect/map-state packet handler with exact 1,160-byte body and direct dispatcher bool return; parses map id/dimensions, flags, counted ANSI map name, packed day/night adjustment, and target-selection byte; conditionally saves/rebuilds/loads map and ObjectList state; updates weather, movement, day/night, waiting/config, transient pane/layer, and two-stage EPF refresh state; preserves malformed-packet trust, ignored map-name conversion, and compiler exclusions; and emits complete human C++.
    - [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md) 0x00511c90-0x00511dae | private packet method | MapPaneHandleObjectMoveEffectPacket : reconstructable : 92% : very-strong : Exact source-ready opcode-0x29 MapPane handler over a trusted const-byte packet pointer; reads BE32 object id +1, signed BE16 effect descriptor +5 and timer action +7, and zero-extended BE16 column +9/row +11; descriptor 134 compiles FlashMapColor(143) policy inline, descriptors 160..162 set render-after-living ordering, null ObjectList or failed nonzero lookup produces no request, zero id routes RequestCoordinateEffect, successful nonzero id gates then calls RequestObjectEffect with its intentional repeated lookup, and every path returns true without packet-length checks; exact range/hash/two callers/padding/source placement and rejected raw/decompiler/extra-check alternatives preserved.

4. Historical shorter by-class replacement rows follow. Command 13590 instead retained prior same-or-greater detail and merged every accepted B002 score/semantic change:
- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era MapPane declaration emitter at position 0 with exact 0x910 layout and current method union, including source-ready RequestObjectEffect, RequestCoordinateEffect, CreateEffectObjectPane, and ApplyEffectObjectPaneTimerAction integration with typed EffectInfo/LivingObjectPane/EffectObjectPane and exact event-2 action semantics; source-ready private CreateHitBarObjectPane with unsigned-short current/maximum values, style 1 only for ObjectStatusBlob::HumanObject and 0 otherwise, separate ordinary-new branches, typed LivingObjectPane owner-slot installation and ObjectList registration, timer event 0 scheduled for 500 ms self-delete, and exact UpdatePosition, inherited GetBounds, then InvalidateRect order; corrected six-byte MapTileLayerIds with staticObjectId, typed CreateStaticObjectPaneForTile, and source-ready RefreshStaticObjectTileRegion declarations; source-ready opcode-0x15 HandleEffectMapStatePacket with exact packet/cache/ObjectList/weather/movement/day-night/transient/waiting/EPF/config lifecycle; source-ready opcode-0x29 HandleObjectMoveEffectPacket with signed descriptor/action, trusted conditional reads, coordinate/object effect routing, compiler-inlined FlashMapColor(143), lookup-miss/no-length behavior, and unconditional success; exact opcode-0x33 HandleObjectInfoPacket and corrected by-value CreateOrUpdateObjectPane declarations with typed ObjectInfo/Living/ObjectStatus/Item support; compiler ABI lowering excluded; followed by address-ordered exact children.
- [UID:00009P][ObjectInfoObjectPane](by-class/ObjectInfoObjectPane.md) : reconstructable : 91% : very-strong : Complete 0x1c0 AttachedObjectPane-derived declaration with primary/selected 33-wide names, selected-name tracking flag, text/outline/fill state, Living owner, exact constructor, inherited ClearOutputRects(RectBounds *, RectBounds *), RenderFrame(GrafPort *, const RectBounds *), SetSpriteAttribute(unsigned char), and UpdatePosition virtual surface, MapPane friendship, superseded descriptive directional alias, and generated vtable/scalar-wrapper exclusions.
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) : reconstructable : 92% : very-strong : Complete source-legal 0x20c LivingObjectPane declaration with exact linked overlay/effect lifecycle, ObjectStatusBlob/Motion state, MapPane/Motion friendship, 33-wide name storage, source-facing m_objectInfoType at +0x16c, size guard, and child insertion point.
- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 93% : very-strong : Complete 0x13eb84 UserPane declaration preserving the current shared method/record union and size guards, with exact final-byte plus 68-byte m_currentAppearance tail used by MapPane local-player status updates.
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) : reconstructable : 88% : strong : Item sprite image-library singleton with ItemInfo table/resource/draw/reload/destructor support, source-facing lightImageIndex consumer semantics, MapPane friendship through the exact layout declaration, and child-owned method bodies.
- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) : reconstructable : 92% : very-strong : Complete 0x12c ObjectPane-derived ground-item declaration with exact objectId/mapX/mapY/itemId/paletteFlags constructor, m_itemId and m_paletteFlags fields, UpdateItemStatus helper, inherited ClearOutputRects and RenderFrame overrides, size guard, exact child insertion, and compiler vtable/scalar/pool exclusions.

5. Historical shorter by-file replacement rows follow. Command 13591 instead retained prior same-or-greater detail and merged every accepted B002 source-route change:
- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children route and exact source-ready object/coordinate effect descriptor, EffectObjectPane creation, and existing-pane delete/cancel/guarded timer replacement family; preserves typed LivingObjectPane/EffectInfo/TimerHandler contracts, target registration/timer/bounds behavior, and prose-only by-file policy; includes source-ready private CreateHitBarObjectPane with unsigned-short current/maximum values, ObjectStatusBlob::HumanObject style-1 versus default style-0 decision, separate ordinary-new branches, typed LivingObjectPane owner-slot installation and ObjectList registration, timer event 0 scheduled for 500 ms self-delete, and exact UpdatePosition, inherited GetBounds, then InvalidateRect order; adds the corrected six-byte static-object tile view and source-ready CreateStaticObjectPaneForTile/RefreshStaticObjectTileRegion pair with exact ObjectList lookup, stale-object lifetime, replacement, and compiler-exclusion behavior; preserves source-ready opcode-0x15 HandleEffectMapStatePacket packet/cache/ObjectList/weather/day-night/transient/waiting/EPF/config behavior and compiler exclusions; preserves source-ready opcode-0x29 HandleObjectMoveEffectPacket with signed descriptor/action, conditional trusted reads, coordinate/object routing, compiler-inlined FlashMapColor(143), lookup-miss/no-length behavior, and unconditional success; adds exact opcode-0x33 HandleObjectInfoPacket, file-static RefreshObjectStatusOverlay, corrected by-value CreateOrUpdateObjectPane, ObjectInfo/Item declaration dependencies, and no by-file reconstruction metadata.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) : reconstructable : 86% : strong : NexusTK/map AttachedObjectPane.cpp source root with complete AttachedObjectPane and HitBarObjectPane declarations, exact common UpdatePosition slot, typed owner accessors, HitBar 0x138 layout/method/lifecycle evidence, derived overlay families, pool/vtable/resource support, and compiler ABI exclusions; adds the complete 0x1c0 ObjectInfoObjectPane declaration with exact name/layout state and inherited ClearOutputRects/RenderFrame/SetSpriteAttribute/UpdatePosition virtual surface; stale UpdateHitBarBounds, ComputeDisplayBounds, and ObjectInfo directional spellings remain historical aliases only.
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map LivingObjectPane.cpp source root with one complete 0x20c declaration, linked-object/effect lifecycle, 33-wide name plus m_objectInfoType field, ObjectStatusBlob/Motion integration, and exact children.
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/UserPane.cpp source root preserving the complete current shared UserPane union and exact 0x13eb84 layout, including the size-neutral trailing state byte plus 68-byte m_currentAppearance used by MapPane.
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) : reconstructable : 90% : strong : NexusTK/render/ItemObjImageLib.cpp source root with ItemInfo table/resource/draw/reload/destructor support, exact lightImageIndex consumer semantics, protected-array layout, MapPane friendship, and child-owned method bodies.
- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) : reconstructable : 90% : very-strong : NexusTK/map/ItemObjectPane.cpp source root with complete 0x12c ItemObjectPane declaration, exact constructor/status-update/ClearOutputRects/RenderFrame source identities, ground-item fields and factory route, pool/vtable/destructor support, and no by-file reconstruction metadata.

6. Historical shorter by-struct replacement rows follow. Command 13592 instead retained prior same-or-greater detail and merged the accepted ItemInfo/layout changes:
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) : reconstructable : 90% : very-strong : Exact 0x14 ItemObjImageLib render-table row with itemTableId, paletteSlot, alpha, source-facing lightImageIndex at +0x0c, allowPaletteFilter at +0x10, constructor/reload/default-row/draw consumers, and direct MapPane lighting attachment evidence.
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) : reconstructable : 89% : very-strong : Exact ItemObjImageLib/ProtectedArray<ItemInfo> layout with embedded default row, source methods, MapPane friendship for direct GetAtOrDefault access, vtable/singleton/resource/destructor evidence, and no synthetic runtime accessor.

UID0003HQ/HR/HS/HT/HU still require no manual by-memory rows; their exact pages received ordinary declaration/name synchronization only. No replacement was required for UID0003TB/UID0003TC/UID0003TD, UID0004QO, MapServerPacketOpcode, ObjectList, status parsers, or verify-only pages. Commands 13589-13592 applied the complete B002 delta while preserving the B003 UID0003TI/UID0003TJ, B004 UID0004Q9/UID0003TO, B005 UID0003TK, B011, and unrelated parent/class/file/type evidence. Manual coverage remains supervisor-owned; B002 did not edit it.

## Follow-Up Actions

- B002's callback, scoped validators, final waited generation, direct readback, report reconciliation, and lease release are complete.
- Destination 4 was applied callback-last over the leased complete B003/B005/B004/B011 union and reverified byte-for-byte; no shared-lane work remains for B002.
- Generated assertions passed: exactly one target definition, one static helper declaration before it, one static helper definition after it, one corrected factory definition, one complete ObjectInfo class, one complete ItemObjectPane class, one Living new field/zero old field, one User current-appearance field, and one ItemInfo light field; zero target/ObjectInfo/ItemObjectPane Empty Emitter Markers, duplicate target/helper/factory definitions, or handwritten vtable/scalar/EH ABI.
- The supervisor applied the manual handoff as a no-loss union and validated it through commands 13589-13592. No B002 coverage work remains. Current/future report review, execution, move, archive, and later lifecycle state remain external and are not asserted.
- No A-agent or new B-agent research action is required by the accepted recommendation.

## Confidence

- Recommendation confidence: 94/100.
- Score confidence: very strong for target/helper/factory; strong for inferred private field names.
- Remaining uncertainty: original lexical names and whether the original header exposed friendship in exactly the same access section. The proposed names and friend placement are the highest-probability compile-safe source shape and do not alter runtime behavior.
- No unresolved uncertainty blocks scores, ownership, emission, or formal C++.

## Validator Results

- Every changed ordinary page was validated with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` from `source-3/project-documentation` while its one-file lease was held. Every command exited `0` with `ok:1`; each lease was then released immediately.
- Command/timestamp map: `13557` target `2026-07-15T23:48:14-04:00`; `13558` helper `23:48:55`; `13559` factory `23:50:27`; `13562` ObjectInfo class `23:51:19`; `13564` Living class `23:52:04`; `13565` User class `23:52:37`; `13566` ItemInfo `23:53:11`; `13567` ItemObj layout `23:53:46`; `13568` ItemObject class `23:54:33`; `13569` ItemObject file `23:55:12`; `13570`-`13574` UID0003HQ/HR/HS/HT/HU at `23:56:00`, `23:56:33`, `23:57:10`, `23:57:36`, `23:58:09`; `13575` Attached file `23:58:39`; `13576` Living file `23:59:16`; `13577` User file `2026-07-16T00:00:13-04:00`; `13578` ItemObj class `00:00:45`; `13579` ItemObj file `00:01:22`; `13580` parent `00:02:15`; `13581` MapPane file `00:02:50`; `13582` MapPane class `00:04:40`.
- Authorized waited command `13583` at `2026-07-16T00:05:11-04:00` exposed a concrete generated contradiction: UID0002SD still emitted two stale `renderFlagsOrMode` uses. The verify-only exception was documented and repaired under a short lease; validator `13584` at `00:07:25` passed. Final consistency validators `13585` ItemInfo at `00:08:05`, `13586` ItemObj class at `00:08:38`, and `13587` ItemObj file at `00:09:12` all passed.
- Final authorized waited command `000000013588`, timestamp/refreshed `2026-07-16T00:09:40-04:00`, targeted UID0002SD and completed with exit `0`, `ok:1`. Its expected side effect was validator-owned generated refresh only. The two waited runs reported known unrelated project-wide `autogen_children_*` and `autogen_emitter_has_no_code` warnings; scoped pages had no target failure. Earlier missing-reference warnings for not-yet-registered callback dependencies disappeared or remained confined to unrelated existing UIDs.
- Exact final generated assertions: MapPane.cpp has one target definition, one helper declaration before it, one helper definition after it, one corrected factory definition, and zero target marker/stale `ItemObjectImageEntry`/duplicate definitions. AttachedObjectPane.cpp and ItemObjectPane.cpp each have one complete class and zero corresponding class markers. LivingObjectPane.cpp has one `m_objectInfoType` and zero `m_nameStateToken`; UserPane.cpp has one `m_currentAppearance`; ItemObjImageLib.cpp has three `lightImageIndex` occurrences and zero `renderFlagsOrMode`. No scalar-deleting definition, `__thiscall`, adjustor, EH-handler source, or vtable array was emitted.
- External supervisor manual commands `13589` by-memory (`2026-07-16T00:35:58-04:00`), `13590` by-class (`00:36:07`), `13591` by-file (`00:36:18`), and `13592` by-struct (`00:36:28`) each exited 0 with `ok:1`. These validations retained their pre-existing missing-reference diagnostics and are not characterized as warning-free. UID0003TW and UID0003TX were added to the by-memory reference index. B002 did not invoke or modify these validators or files. No report execution, probe, lifecycle, move, or archive command was run.

## Changed Files

- Modified ordinary pages and current SHA256/metrics:
  - target `by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md` `E2AA4102AF72063575FE0B163DBC1F7D784EDAF676863F363E7E850904D37B90`, 15,917 bytes/242 lines; helper `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md` `EE1FEEE55BA59E4CDCA7669CEE99C37EC8E8111405CDA3561548FA42FE75B59A`, 6,952/100; factory `by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md` `87F2783FC8073C76A25B70A496F3A79D6FADB3B4899131428CE50BDC013472FA`, 20,933/245.
  - `by-class/ObjectInfoObjectPane.md` `BF6A76B28B334F48F4C055DBC0120AB2EB190C4F26B90F77948CEBBF63AD757F`, 15,285/144; `by-class/LivingObjectPane.md` `85C5107ED83774B7E90F865F104756A69F0117976CAEBB406027AB1BDDEE896E`, 127,173/653; `by-class/UserPane.md` `58BDE128DAED89C884707DA6BA58DA25E2821AEFD88D1DFD4DDCA4029E3C047A`, 82,622/607.
  - `by-type/by-struct/ItemInfo.md` `889730F66FD76D059B19A2657A67C641D909BAB4181842EF8FC5BD906539FE0D`, 11,503/103; `by-type/by-struct/ItemObjImageLibLayout.md` `ED11AB5E46FA0BAE358D9EC4D526C07A5AF639CE25B4DAB32817F654D9C95410`, 12,120/112.
  - `by-class/ItemObjectPane.md` `C5E305D568BAA6889103E1458D7E3042EB47004FED07613AB0FE731B8E76B2F6`, 16,699/141; `by-file/ItemObjectPane.md` `7F70DEEE84FC3FD616495BD8002E2A0CBBBF7AF33790414A6FADF01D1BCDB927`, 25,421/162.
  - UID0003HQ `by-memory/0x00537b40-0x00537b91.ItemObjectPaneConstructor.md` `B22CC59AE9D226B83A7EC2A2828EC2A1AAC8DD6D1CBE542266D6C01FCF997FBE`; UID0003HR `by-memory/0x00537ba0-0x00537bbf.ItemObjectPaneNonDeletingDestructor.md` `65A80F33FC163AEC608ACD01ED042A6286B64E3742FF10DD3863D7DA861E3701`; UID0003HS `by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md` `E2A94349F1AD5012F4D3A52D998D2DEF40E34B1F0852865634E8F0F5B803EBC3`; UID0003HT `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneBuildCenteredItemRect.md` `8355C6DA543ADCDB5AB1CBE4D2F9686FD6601CF0F60F948508695F47A8F5465D`; UID0003HU `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneProcessItemAction.md` `F5863D2AB400C147DFFC9437004C2F996149A0502CA2C52FA8F70DC212E9A20D`.
  - `by-file/AttachedObjectPane.md` `63F59EF3F693986030A3DD4EC81B01C151186FF3BD41FA34AC7F9CAF9FF5CEEF`, 50,938/236; `by-file/LivingObjectPane.md` `526DFF01163BB656519574D69B5AA143B7A8F6E64F2D463AAFAA603FBB8A425A`, 119,953/431; `by-file/UserPane.md` `47BA0327E6C793F9D73B1469FE736237D0F3E70C3C649CCEA24F8D4D0BE945C5`, 95,402/383.
  - `by-class/ItemObjImageLib.md` `A452A2561CB5A4F93543920A5E39BFCA7FA9981F0D11A158632556C55645CCD0`, 39,806/180; `by-file/ItemObjImageLib.md` `660631351B015A79852E43D0D013A13CF2ED7C0859344B6072E09867AA03B976`, 38,390/182.
  - parent `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` `FD73F05C34345EE20358F63DA03CC051D5FC6DE34DABC508D812025872EDE2CF`, 86,354/352; `by-file/MapPane.md` `B949B30D78567BCB02018CD74C3E68116B6FFF77C206A996D3B3A37031EDCFEB`, 170,960/709; callback-last `by-class/MapPane.md` `95D07519D1DC46CFCE4A6D3D858AED6470D6ACE38E262F2F2AEA8655AF8FBFD2`, 169,668/950.
  - Concrete-drift repair `by-memory/0x004dec30-0x004dee1b.ItemObjImageLibConstructor.md` `4297889E1385CEBB5044901C8FAB23747AD6CA68ADA1DA0EC5EE238A00C77E90`, 15,033/170.
- Current validator-owned generated readback at command 13588: MapPane.cpp `CA211E27474F0EFD88BB8973D9B914007B62B981F4EE3359DB10A528E3A981BA`, 118,766/3,544; AttachedObjectPane.cpp `452B7275A9B41F24D6009CE23DB7319DA49B21F13999F0E22906F2D0F77041C1`, 8,975/208; LivingObjectPane.cpp `62AD6FB701785F8B4D8AEB265296267720AB3FEF27C9621194983689BAEB9F74`, 36,500/1,154; UserPane.cpp `721A4873C8BD29FFF0A39C7BD16E913FBC4ED66F7D4C014FBCC80842BFA0D4CF`, 90,353/2,698; ItemObjImageLib.cpp `7448D1C89A5FDD13F4A9A933FEBBE016EF7EB85DB0501F12C56526899CBC4AC0`, 7,527/169; ItemObjectPane.cpp `AC582836C4E459363E03713CECA91DE419F04B62B3F5EF0424ED9520762FBF5A`, 3,428/74.
- Current supervisor-owned manual snapshots are by-memory `B9CC8370ECCB987D6D0559E926D86D4E6510579F49D27FA9D2ED1D0A46D2C7E9` (command 13589), by-class `07D98BB8124B476FB9E2B39D298AB5BE92E1D21714F3B9622A0CA810D89F146B` (13590), by-file `3BF998864768EC10DA471D4566381B64EFC8BDDD1B1E9B2633C305662522DA1C` (13591), and by-struct `C0FA7E9B4079CC5080CBE9AC7FF16F7C2A11E1030EE6AC0EA2F503C6B468F873` (13592). All four are applied no-loss unions; B002 did not edit them.
- Modified report: this report only, additively reconciled after implementation. Manual coverage, generated, tracker, audit, supervisor, validator-state, lifecycle, archive, and IDA files were not manually edited. Report execution/lifecycle was not run. Active B002 leases: zero.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validated exact report-only SHA `FDFEDDE07DE1275D5621E981A9BE2243A1B28F018C0A1E14088636EBAFCE56C0` before implementation.
- [x] Confirm report provenance, target path, historical pre-callback metadata, and archive-neutral lifecycle truth.
- [x] Confirm every ledger Action is a permitted enum and every final state is exactly `applied`.
- [x] Apply UID0003TX metadata, summary, formal body, and complete evidence.
- [x] Apply UID0003TW metadata, summary, formal body, linkage, and evidence.
- [x] Apply UID0002QN corrected metadata, ABI, body, and historicalization.
- [x] Rebase and apply the complete MapPane declaration over the stable B003/B005/B004/B011 shared baseline after clearance.
- [x] Apply the complete ObjectInfoObjectPane declaration, exact inherited virtual signatures, and position 40.
- [x] Apply LivingObjectPane `m_objectInfoType` rename without union loss.
- [x] Apply UserPane tail split without union or size loss.
- [x] Apply ItemInfo `lightImageIndex` and score; repair concrete generated UID0002SD drift.
- [x] Apply ItemObjImageLib friendship/layout score without inventing a runtime API.
- [x] Apply the complete ItemObjectPane declaration, score, source identities, and file support without duplicating child bodies.
- [x] Apply MapPane/file/parent prose-only synchronization without by-file metadata and preserve the complete UID0003TI/UID0003TJ/UID0003TK/UID0003TO union.
- [x] Apply Attached/Living/User/Item support prose at report-level detail.
- [x] Preserve UID0003TT/3TB/3Z4/4QO/parser/ObjectList/geometry/enum/vtable verify-only pages except the documented concrete UID0002SD drift.
- [x] Preserve historical assumptions, negative evidence, rejected alternatives, and compiler exclusions.
- [x] Confirm supervisor commands 13589-13592 applied the accepted coverage delta as a no-loss union, added UID0003TW/UID0003TX to the by-memory index, retained existing diagnostics, and preserved all overlapping rows; B002 did not edit coverage.
- [x] Run no third-party import directive; none is applicable.
- [x] Close all score/source-quality blockers exactly as documented.
- [x] Confirm the historical report-only phase had zero ordinary edits, leases, implementation validators, or lifecycle actions.

Implementation callback pass:
- [x] Supervisor callback was explicitly authorized for the exact accepted SHA.
- [x] Supervisor explicitly cleared B002's callback-last lane over the stable B003/B005/B004 ordinary shared baseline.
- [x] Reread every destination and accepted overlapping report before leasing.
- [x] Lease only one ordinary destination immediately before editing.
- [x] Reread each destination after lease acquisition and preserve unrelated content.
- [x] Apply C01-C30 claim by claim with no compression.
- [x] Install all ten managed blocks exactly.
- [x] Ensure Destination 1's static helper declaration precedes the target definition.
- [x] Ensure UID0003TW is the sole static helper definition.
- [x] Ensure UID0002QN has the sole corrected by-value definition.
- [x] Ensure ObjectInfoObjectPane and ItemObjectPane each have one complete, base-slot-compatible declaration and no duplicate method bodies.
- [x] Ensure all full class unions retain class closure, size guards, and `[[CHILDREN]]`.
- [x] Run one scoped validator per changed ordinary page while its lease is held.
- [x] Record command id, timestamp, exit, ok, warnings, and side effects for every validator.
- [x] Release each lease immediately after its scoped validator.
- [x] Run final authorized waited generated command 13588 after the concrete-drift repair.
- [x] Verify all exact generated counts/order and zero forbidden ABI source.
- [x] Update all ledger states with legal terminal values and separate destination/validator proof.
- [x] Check every checklist row only after direct verification.
- [x] Return with zero leases; never run `execute_report`, lifecycle, move, or archive.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000013595","destination_path":"executed-b-agent-research/B002/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md","timestamp":"2026-07-16T01:01:11-04:00","uid":"0003TX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
