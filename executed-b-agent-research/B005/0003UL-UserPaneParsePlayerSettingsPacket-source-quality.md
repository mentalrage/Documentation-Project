** TARGET-REPORT-UID:0003UL **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003UL UserPaneParsePlayerSettingsPacket Ownership / Split Research


## Finalized Report / Current Recommendation
- Current recommendation and callback result: `[0x005aa480,0x005aa702)` is retained as one source-bearing `bool UserPane::ParsePlayerSettingsPacket(const unsigned char *packet)` member in `NexusTK/ui/panels/UserPane.cpp`; Destination 1 is applied exactly and UID0003UL is now `92/94`.
- Final disposition: no split, merge, rename, owner change, emitter change, or source-route change occurred. Owner/emitter UID0000FQ, reconstructable true, blank optional position, cumulative `Nested:8`, exact range, and source order are preserved.
- C01-C35, Destinations 1-3, and every accepted bounded support synchronization are applied or verified. The shared UserPane pages were rebased against executed B001/B004 artifacts before the original callback and against the current B001/B003/B004 callback union during the bounded Gate 2 repair. All 14 unique changed ordinary pages passed scoped validation; the three repaired shared pages passed the additional commands `000000012884` through `000000012886`; every lease was released; and final waited command `000000012887` completed successfully.
- Remaining report execution, archival, tracker lifecycle, and manual coverage application are external supervisor-owned state; they are not pending B005 implementation work and this artifact does not assert their future outcome.
- Confidence: very strong for bytes, range, caller, opcode, ABI, packet arithmetic, all side effects, owner, route, and source body; exact original private names for several state/config bytes remain unavailable and are explicitly descriptive lexical caps.

## Supporting Research
- At report-only evidence time, the pre-callback UID0003UL page was not blank, but its then-existing body was not binary-equivalent. It used base offsets `10/39` instead of `2/31`, assigned byte `+0x19a` through the unrelated 32-bit `ObjectStatusBlob::m_actionState`, invented `RefreshMovementBounds`, tested movement-state index 4 instead of index 3, called `RemovePendingTimers` instead of `TryStepForward`, used a 16-bit reader instead of the 32-bit reader, compressed ten direct config stores into an unproven helper, used stale sound-helper names, and refreshed through the wrong global. The accepted callback superseded those defects with Destination 1.
- The 2026-07-14 UID0002QY callback is useful executed support evidence for UserPane ownership and source routing, not a target-specific source-quality report. Its Destination 35 preserved the defects above and kept `86/88`.
- The executed UID00037V report is useful support for `m_playerSettingsState[4]` blindness semantics only. It intentionally changed only the former `oldSpeed` token and did not audit the rest of UID0003UL.
- Historical report-only phase: before Gate 1, no ordinary by-* page, generated file, coverage file, tracker, audit, lifecycle state, or IDA database was modified, and no validator or lease was used. During the accepted callback and bounded Gate 2 repair, only the same 14 unique ordinary pages listed under Changed Files were leased, edited, scoped-validated, and released; the repair re-edited only the class, aggregate, and file UserPane support pages. Generated output changed through validator-owned refreshes, including B005 waited commands `000000012859` and `000000012887`; B005 did not edit coverage/generated/tracker/audit/lifecycle state manually and did not run `execute_report`, a report probe, move, or archive command.

### Prior-report search record
- Exact terms searched: `0003UL`, `0x005aa480`, `UserPaneParsePlayerSettingsPacket`, `ParsePlayerSettingsPacket`, `sub_5AA480`, `m_playerSettingsState`, `UserPane`, `LivingObjectPane`, `UserPaneHandleServerMessage`, `0x005a76c0`, `0003VB`, `0002QY`, and `00037V`.
- Roots searched read-only: `executed-b-agent-research`, active `tools/leaser/Agents/Agent-B*/research` folders, `archived/b-agent-reports-20260623`, `archived/duplicate-loose-b-agent-reports`, and `tools/leaser/Agents/Older-Research`.
- Matching reports opened and classified:
  - `executed-b-agent-research/B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`: direct aggregate-support match, executed, current for the 2026-07-14 ownership migration but superseded for UID0003UL body accuracy by this bounded target pass.
  - `executed-b-agent-research/B005/00037V-MapPaneRenderViewCore-source-quality.md`: incidental executed support; proves only state index 4 blindness/invalidation semantics and historically corrected `oldSpeed`.
  - `executed-b-agent-research/B005/0002EZ-ChatPacketType13Handler-source-quality.md`: incidental executed support; records UID0003UL only as a settings producer and resolves indices 5/6 through receive/send consumers. Its old verify-only LivingObjectPane-era wording is superseded.
  - `executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md` and `...-retry.md`: direct historical split evidence; their LivingObjectPane ownership conclusion is stale after the executed UserPane migration.
  - `executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md`: direct historical inventory match; stale target path/owner and blank-C++ blocker.
  - `executed-b-agent-research/B001/00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`: incidental direct-address support for `m_mapPane` use.
  - `executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md`: incidental caller support for `TryStepForward`.
  - `executed-b-agent-research/B001/0003U6-UserPaneProcessMovement-source-quality.md`: incidental declaration and state-index consumer support.
  - `executed-b-agent-research/B010/0003UV-LivingObjectPaneRawPositionSyncPacketHelper-source-quality.md`, `B011/0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`, and `B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md`: incidental dispatcher, adjusted-receiver, and child-accessor evidence.
  - `executed-b-agent-research/B004/0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality.md`: incidental historical sibling inventory whose broad LivingObjectPane wording is superseded for this target.
  - `executed-b-agent-research/B005/00037X-MapPaneInteractionMapChangeCore-source-quality.md`: incidental current UserPane declaration support.
  - `executed-b-agent-research/B004/0003UM-UserPaneParseInventorySlotUpdatePacket-source-quality.md`: executed successor report, current exact SHA256 `3ED435EE6680006F2ED713E568E9AE4630A1E18F07E836A3BE8C792E117C182A`. During the earlier active phase a repair-time read observed SHA256 `CFE5324020E16D6D3BAAC048E4A29006CA3BEF8AF5B722FE866CE87110A6B8A9`; that is historical evidence-time provenance. Its target range/body is independent, while its no-loss contribution to the shared pages is the opcode-`0x0f` route plus `itemMetaKey`, `ownerName`, `currentDurability`, and `protectionCount` fields, all preserved by B005.
  - `executed-b-agent-research/B001/0003U8-UserPaneStartDirectionalAnimation-source-quality.md`: executed sibling report, current exact SHA256 `4937108A56AF541AFB4FCFF385265D02571B64ADC40FF715996E26CB73F1085D`. Historical active-phase reads observed revisions `1B54C472440C887139E601D7C17B00D8A5922D59DC64BE74423F49A3E5E8EF04`, `399E553CCF795AE7CA3B4B6FE5B40B0F189066D167A618541AF2D2C940CF85F1`, and `5EAA7552D9CD5779306BAE8210F8DB9DA897E40C40791E039E92006224058806`; that evidence-time drift required the later B005 reread/rebase. Its accepted `StartDirectionalAnimation(char direction)` declaration and all unrelated UserPane evidence remain current.
- No report with `TARGET-REPORT-UID:0003UL` and no prior target-specific audit of this exact body was found. UID0002QY and UID00037V are support reports, not direct prior coverage.

## Target
- Target UID: `0003UL`.
- Target path: `by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current artifact classification: accepted target-specific research plus completed same-report implementation callback, pending only external supervisor lifecycle decisions.
- Current scores and parent state: `92/94`, owner/emitter UID0000FQ, reconstructable true, optional position blank, `Nested:8`, source route UID0000P1 / `NexusTK/ui/panels/UserPane.cpp`.

## Current Target State
- Current metadata is exact: `92/94`, exact path/title/range, owner/emitter UID0000FQ, reconstructable true, blank optional position, and cumulative `Nested:8`.
- Current C++ is Destination 1 byte-for-byte. The prior nine semantic defects in base offset, action field, bounds invalidation, movement-state byte/helper, reader width/narrowing, direct config stores, SoundManager calls/mirror, and active-panel refresh route are corrected.
- Current prose preserves old LivingObjectPane ownership, blank-C++, unresolved opcode/field, speed-token, wrong-offset/helper/reader/global, and generated-body assumptions only as explicitly historical or rejected evidence.
- Current `Item Summary` is the accepted exact target summary. UID0003UP and UID0003UQ each preserve `86/88` and now use Destination 2/3 byte-for-byte with two exact `m_movementState[3]` tests.
- Related current docs checked: UID0000FQ, UID0000P1, UID0001KL, UID0001KM, UID0003VB, UID0003UP, UID0003UQ, UID0003U6, UID0003U7, UID0003Z8, UID0004QY, UID00028Q, UID00028R, UID0003YK, UID00015W, GeneralPurposePanel, Pane, GrafPort, MapPane, SoundManager, NewOptionPane, SelfLookPane, ChattingPane type-13 handler, say/chat/shout senders, generated `UserPane.cpp`, and current manual coverage rows.
- Historical pre-callback shared snapshots were `A0364680...`, `B1CDF3C9...`, and `F866B1B8...`; B005 callback-time hashes were `5F938CC7...`, `EC861338...`, and `5DB48C5E...`; later concurrent pre-repair hashes were `94D7FB62...A258`, `B6A80763...4D42`, and `C2466057...559D`. The bounded repair corrected only the no-loss array/option prose. Current hashes are `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291` for `by-class/UserPane.md`, `5C20099E100A4FD69BACD1D37917BE2E8ADB8DF3CAFC942698F697FDDE785AEF` for `by-file/UserPane.md`, and `F18352411F35DB759FAE28907827D2F07F72D1052BDEDC7994627DDF3675EA98` for UID0001KM. Read-only recheck confirms the exact `m_playerSettingsState[8]` versus `m_movementState[5]` distinction, accepted option-store order, B001 signed-char contract, B004 record/opcode inventory, and all unrelated current content remain present.
- Current lifecycle statement: B005's accepted implementation, bounded Gate 2 defect repair, validation, generated readback, and self-review are complete; this mutated exact artifact requires fresh supervisor Gate 1 before independent Gate 2. No B005 lease remains.

## Executive Recommendation
- UID0003UL now contains the complete human-shaped opcode-`0x08` UserPane parser, preserving every unchecked packet access and source ordering while exposing direct config writes instead of invented wrappers.
- UID0003UP and UID0003UQ now contain the accepted full managed blocks; both binaries and both source bodies test `m_movementState[3]` at `+0x13eaf3` in the two relevant branches.
- The established index-4 direction-delay helper remains unchanged for its real consumers. No class-layout shift was made.
- No source-bearing child, raw helper, table, or padding split is required. Exact boundary padding remains ignored and outside the target.

## Supervisor Active Recheck
- The supervisor assigned UID0003UL after UID00037V completed its lifecycle, accepted exact report SHA `0B92044FF2722EB2593FB3F990EB53C49ABA3247661F26B55EB4ACE7FD1D4384`, and authorized this same-report callback.
- Split repair was tested before source drafting. The target is one modeled function with one entry, fourteen CFG blocks, one dispatcher caller, no internal entry xrefs, and clean `int3` fences; no child split is justified.
- Every source-bearing C++ change is represented by one of the three exact destination blocks below; all three are applied and mechanically equal to their current ordinary-page managed blocks.
- Shared-destination coordination completed against executed B001 report SHA `4937108A56AF541AFB4FCFF385265D02571B64ADC40FF715996E26CB73F1085D` and executed B004 report SHA `3ED435EE6680006F2ED713E568E9AE4630A1E18F07E836A3BE8C792E117C182A`. Each shared page was reread after acquiring its B005 lease, the complete current union was preserved, and only accepted B005 settings-state/source-readiness prose was added.
- Independent Gate 2 at `2026-07-15T05:09:46-04:00` accepted the target, formals, other support, generated output, restrictions, and lease closure but found one bounded no-loss defect across the three shared support pages: settings indices had been attributed to `m_movementState`, UID0001KM listed the ten option stores out of machine order, and the file page retained a historical blindness-array error plus an all-eight-state overstatement. Before repair, B005 reread current B001 report SHA `0D78086AA52DEB81EB9434EA2A9B7C2FBE0FB975EF0B74C0714F7374BB751EFF`, current B003 report SHA `4360B72748FCEBC77A53670A853F36DDB6B8DA72EC4DE611E26A895C6598896D`, current B004 report SHA `C1D55E96017508B7619841A0379D874A371B6397685911E22F9A5F8E7FFEDD55`, their goals, and the global lease report. Those callbacks explicitly deferred shared UserPane destinations until B005 settled, and no active lease existed. B005 then reread each destination under its own one-file lease, preserved the complete current union, corrected only the bounded defects, validated, and released serially.

## Inference Research Guidance Check
- `by-structure.md` and the project inference ladder require address/range and compiler-artifact questions before naming. That led to retaining one ordinary method, excluding both padding fences, and preserving cumulative nesting rather than treating `Nested` as a child count.
- Existing names, offsets, helper calls, current comments, and generated C++ were treated as hypotheses. Binary facts were separated from documentation evidence and source-facing descriptive inference.
- Direct IDA facts establish the body and offsets. Cross-consumer documentation establishes semantic names for state indices and config labels. Exact original lexical spellings remain inferred and cap confidence rather than blocking code.
- Historical Wave2/Wave3 wording was encountered in older family reports and current GeneralPurposePanel coverage prose. It was ignored as stale and is not used as evidence.

## Heuristic / Inference Reanalysis And Validation

### Packet dispatch and ABI
- Bounded dispatcher disassembly at `0x005a76c0` proves payload byte 0 is the opcode selector and case `8` adjusts the receiver by `-0xa0` to the UserPane primary object before calling `0x005aa480`.
- There is no secondary subtype. `packet[1]` is the parser flags byte. Historical “opcode/subtype unresolved” text is rejected-stale.
- The target is `__thiscall`, takes one pointer argument, ends in `ret 4`, returns AL false, and has no length argument. Source type is `bool UserPane::ParsePlayerSettingsPacket(const unsigned char *packet)`.

### Flag and optional-offset arithmetic
- `packet[1] >> 7` writes state index 0. Bit `0x04` writes byte `3` to inherited object offset `+0x19a`. Bit `0x02` is inverted into state index 2.
- Base offset is exactly `31` when bit `0x40` is set and `2` otherwise. Bit `0x20` adds 8; bit `0x10` adds 9. Possible bases are `2,10,11,19,31,39,40,48`. Existing `10/39` applies an erroneous unconditional +8 and is rejected-invalid.
- If bit `0x08` is set, bytes at base through base+3 become state indices 3 through 6. The parser then advances five positions, and the later preincrement means the movement-status byte is at base+6. Thus base+4 and base+5 are not consumed as modeled state. Without the optional group, base itself is skipped and movement status is at base+1.
- The following `PacketBufferReadUInt32BE` starts at base+2 without the optional group or base+7 with it. Maximum possible read is through packet byte 53 without the group and byte 58 with it. The source must not add length/null checks absent from the original.

### UserPane and inherited fields
- State index 0 is a multi-consumer local-player feature/UI mode: UserListDialog and predefined-form free-text behavior consume it. `kPlayerFeatureMode` is descriptive, not an original symbol.
- State index 2 selects viewport movement-threshold behavior in `UserPane::ProcessMovement`; `kUseViewportMovementThresholds` is descriptive and behavior-backed.
- State index 3 controls direction transformation in ProcessMovement: zero normal, one reverse by two quadrants, other nonzero values use the current tick low bits. `kDirectionMode` is behavior-backed.
- State index 4 is blindness level. UID0004QY renders only the local player/effects against a solid fill when nonzero; this parser invalidates the full map bounds only when the value changes.
- State indices 5 and 6 are chat display and send restriction levels. UID0002EZ resolves receive-side level tests and adjacent say/chat/shout senders resolve send-side restrictions. The names are descriptive; exact value names remain lexical uncertainty.
- Byte `+0x19a` is `m_actionGateState`, not `m_objectStatus.m_actionState`. The latter is a distinct 32-bit ObjectStatusBlob member at blob offset `+0x24`; direct byte stores and action-gate consumers prove the distinction.

### Movement-state contradiction
- Target instructions at `0x005aa5b6` and `0x005aa5c6` test and clear `UserPane+0x13eaf3`, exactly `m_movementState[3]`.
- Raw displacement scans and bounded MCP decompilation prove both movement-reply handlers also test `+0x13eaf3`. Their pre-callback formal used `IsDirectionDelayActive()`, which reads `m_movementState[4]` / `+0x13eaf4`, so those earlier source bodies were wrong; applied Destinations 2/3 now use exact index-3 tests.
- Independent consumers preserve index 4: constructor/animation initialization and other movement flows use `+0x13eaf4`; this report does not rename, shift, or delete that byte/helper.
- When the incoming movement-status byte is nonzero and index 3 is nonzero, the target calls UID0003Z8 `LivingObjectPane::TryStepForward()`, ignores its bool result, clears index 3, and clears inherited `m_isMoving`. `RemovePendingTimers` and `SetDirectionDelayActive(false)` are rejected-invalid for this branch.

### Config option word and field names
- The target calls UID0003YK `PacketBufferReadUInt32BE` at `0x005754c0`, then retains only the low 16 bits in DI. Destination 1 models the observable narrowing explicitly as `static_cast<unsigned short>`.
- Direct stores map low-word bits to config bytes: bit 0 -> `+0x28de6e`; bit 2 -> `+0x28de6f`; bit 3 -> `+0x28de70`; bit 4 -> `+0x28de72`; bit 5 -> `+0x28de73`; bit 6 -> `+0x28de74`; bit 8 -> `+0x28de75`; bit 12 -> `+0x28de48`; bit 13 -> `+0x28de60`; bit 14 -> `+0x28de61`.
- NewOptionPane labels and option-index consumers resolve `+6e Whisper`, `+6f Shout`, `+70 Advice`, `+72 Magic`, `+73 Weather`, and `+74 Fixed movement`. Descriptive fields are `m_whisperEnabled`, `m_shoutEnabled`, `m_adviceEnabled`, `m_magicEnabled`, `m_weatherEnabled`, and `m_fixedMovementEnabled`.
- `+0x28de75` remains `m_sendMovementStatusBit` / map-movement-status option. The packet byte is written first and governs `TryStepForward`; bit 8 of the later narrowed option value overwrites it afterward. Reordering or merging these stores would change behavior.
- `+0x28de48` is `m_soundEffectsEnabled`. SelfLookPane::OnPaint proves `+0x28de60/+61` select alternate render resource/color pairs for slots 5/6. `m_selfLookSlot5AlternateStyle` and `m_selfLookSlot6AlternateStyle` are precise descriptive names with lexical caps.
- `Config::ApplyServerOptionBits` is not an observed callee and hides order/field behavior; reject it for this body.

### Rendering, sound, and panel refresh
- On blindness change the binary calls `GrafPort::GetBounds(&bounds)` on `m_mapPane`, then virtual slot `+0x20` `InvalidateRect(&bounds)`. `RefreshMovementBounds` is invented and rejected-invalid.
- Sound enabled calls `SoundManager::EnableSoundEffects`; disabled calls `DisableSoundEffects`. Both branches then directly mirror 1/0 to SoundManager byte `+5`. `m_soundEffectsOptionEnabled` is the conservative descriptive field name; `+0x41` remains the distinct runtime sound-effects-enabled field.
- The final branch reads `g_pGeneralPurposePanel->m_activeChildIndex`; if it equals 6, it calls `GetChildPaneByIndex(6)->OnActivate(NULL)` with no null check. `g_pMainWindow->RefreshSettingsPaneIfVisible()` is the wrong global and an invented compression.

### Rejected alternatives
- LivingObjectPane owner: rejected because receiver state reaches the UserPane extension through `+0x13eaf3`; LivingObjectPane only supplies inherited fields/methods.
- Separate subtype parser: rejected because dispatcher case 8 passes the same packet whose byte 1 is consumed as flags.
- Split children for optional branches: rejected because all blocks are one CFG/function with no entry route.
- `m_objectStatus.m_actionState`: rejected by byte width and offset.
- 16-bit packet reader: rejected by direct call to `0x005754c0` / four-byte reader; explicit low-word narrowing preserves the binary.
- Timer-removal and MainWindow helpers: rejected by direct callees/globals.
- Adding malformed-packet checks, null checks, or sanitization: rejected because the original has none.

## Evidence Standards Used
- Strongest evidence: fresh IDA MCP function lookup, exact bytes, bounded disassembly/decompilation, CFG/caller/callee analysis, dispatcher case disassembly, bounded helper decompilation, and raw displacement positive-control scans.
- Corroboration: current class/file/layout/vtable/global pages, exact consumer formals, generated UserPane.cpp, executed support reports, and manual coverage rows.
- Negative evidence: no function at target exclusive end, no internal entry/xrefs, no user EH, no string literal, no second caller, no subtype dispatch, no helper calls matching the invented wrappers, and no source reason to split.
- Lexical confidence is lower than behavioral confidence. Descriptive names preserve exact offsets/roles and are marked inferred; they do not justify reducing the completion score once the full body is reconstructable.

## Evidence Checked
- Fresh MCP discovery: `idb_list` returned active adopted NexusTK database session `01f84d61`; transport session `9b991fd3-1c9f-4365-afa9-edaf25c5506c`. `server_health` at `2026-07-15T03:01:29-04:00` returned `ok` with auto-analysis, Hex-Rays, and strings cache ready.
- MCP target checks: `lookup_funcs` at start/interior/end/successor/predecessor; `get_bytes` for target and both fences; `analyze_function`; `decompile(0x005aa480)`; target xrefs/callees; bounded dispatcher instruction queries around the case-8 call.
- MCP helper checks: decompiled `0x0053c390`, `0x004b8e00`, `0x004b85f0`, `0x005754c0`, `0x0057a760`, `0x0057a770`, movement-reply functions `0x005ab090/0x005ab410`, NewOptionPane consumers, and SelfLookPane render consumers.
- Raw PE checks: exact displacement occurrences for `+0x13eaf2/+f3/+f4`, `+0x1340fc..+0x134102`, and config bytes `+0x28de48/+60/+61/+6e..+75`; bounded MCP lookups/decompilations mapped positive hits back to functions.
- Documentation checked before and after callback: all 14 changed ordinary paths named under Changed Files; verify-only UID0001KL, LivingObjectPane class/file, TryStepForward, MapPane/GrafPort, GeneralPurposePanel/Pane, UID0004QY, UID00015W, and ignored padding; current manual by-memory/by-class/by-file rows; and validator-generated `auto-generated/NexusTK/ui/panels/UserPane.cpp`.
- Coordination recheck: opened executed B001 UID0003U8 report SHA `4937108A56AF541AFB4FCFF385265D02571B64ADC40FF715996E26CB73F1085D` and executed B004 UID0003UM report SHA `3ED435EE6680006F2ED713E568E9AE4630A1E18F07E836A3BE8C792E117C182A` for the original callback. For the bounded repair, B005 additionally opened the current accepted/callback B001/B003/B004 reports at SHAs `0D78086A...1EFF`, `4360B727...896D`, and `C1D55E96...DD55`, reread their goals, confirmed that each deferred shared UserPane edits until B005 settled, and observed zero active global leases before each serial acquisition. Current post-repair hashes are `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291`, `5C20099E100A4FD69BACD1D37917BE2E8ADB8DF3CAFC942698F697FDDE785AEF`, and `F18352411F35DB759FAE28907827D2F07F72D1052BDEDC7994627DDF3675EA98`. They retain the complete B005 UID0003UL sections, B001 signed-char facts, B004 inventory/opcode facts, and concurrent content while now distinguishing settings storage from movement storage exactly.
- Manual no-loss recheck after callback: read-only hashes were `5F7E4B123EC484482D17633E3372B1A99A9258A3E36A45411F5891514672CCF2` for `by-memory/-coverage-report.md`, `AE64427CF5F99D4C0830412CA72BD7B36D6D6BB256CE4486457C642EADB26E40` for `by-class/-coverage-report.md`, and `F9C2ED6B468DBAE4DA9576119350B1D5F1D50D6BC402970B202D8CCCA42822D7` for `by-file/-coverage-report.md`. The seven UID0003UL/UP/UQ/28Q/0000FQ/0000DG/0000P1 rows remain stale exactly as the preserved supervisor-owned replacements below describe; no B005 coverage edit occurred.
- Negative checks: no overlap at `0x005aa702`; no code in either `int3` fence; no alternate pointer/member route; no direct helper supporting `ApplyServerOptionBits`, `RefreshMovementBounds`, `RemovePendingTimers`, or MainWindow refresh in this target.
- One expensive operand-wide MCP `insn_query` over `0x00401000-0x0060d000` for config displacement `0x28de6e` reached the 30-second client timeout. It was not repeated. Immediate lightweight `idb_list` and all later bounded target/helper calls succeeded, so this was query cost rather than MCP unavailability. Localized raw displacement scans plus bounded MCP mapping replaced it.
- Original callback validation checked every changed ordinary page once under its short lease with commands `000000012845` through `000000012858`; every command exited 0 with `ok: 1`, after which the lease was released. The bounded repair scoped-validated class, aggregate, and file pages with commands `000000012884`, `000000012885`, and `000000012886`, each exit 0 and `ok:1`, releasing each lease immediately. Final waited command `000000012887` exited 0 with `ok:1` and generated `UserPane.cpp` header command `000000012887`, refresh time `2026-07-15T05:15:41-04:00`, and SHA256 `A9E92CA64E55EB398DB1D29CC8C436C7C8B126AB584734A41EB6D1480113FAE3`.
- Callback-time and successive external generated readbacks all found one UID0003UL marker/definition, one UID0003UP marker/definition, and one UID0003UQ marker/definition in source order; the target segment has one UInt32BE call, one EnableSoundEffects call, one DisableSoundEffects call, one child-6 `OnActivate(NULL)`, and zero rejected target spellings. UID0003UP/UQ each have two index-3 tests and zero `IsDirectionDelayActive` calls.
- Three report destination blocks were mechanically compared with current ordinary managed blocks and remain byte-for-byte equal. Eleven ordinary hashes remain at their prior B005 post-validator values; the three repaired shared UserPane pages match the new hashes above and preserve every accepted B005/B001/B003/B004 fact. Historical external generated commands `000000012867`, `000000012870`, `000000012876`, and supervisor audit checkpoint `000000012882` preserved target assertions; B005 final command `000000012887` is the current generated checkpoint. The B005 and global lease reports contain zero B005 rows.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target is one modeled function `[0x005aa480,0x005aa702)`, size `0x282`, SHA256 `CA93F04AE7BC6BD08862ED21420A7AD284710C5BBC643330EA5154CC22EDBF43`. | very strong | lookup/get_bytes/analyze | UID0003UL range/evidence | incorporate | applied |
| C02 | Predecessor ends `0x005aa473`; `[0x005aa473,0x005aa480)` and `[0x005aa702,0x005aa710)` are 13/14-byte `0xcc` fences. | very strong | bytes/function boundaries | UID0003UL; ignored verify-only | incorporate | applied |
| C03 | Fourteen-block CFG, complexity 8, security cookie, no user EH/string/table/internal entry; no split. | very strong | analyze/decompile/xrefs | UID0003UL | incorporate | applied |
| C04 | ABI is `bool __thiscall UserPane::ParsePlayerSettingsPacket(const unsigned char *)`, `ret 4`, always false. | very strong | prologue/epilogue/caller | UID0003UL Destination 1 | incorporate | applied |
| C05 | Dispatcher case opcode `0x08` is sole caller; packet[1] is flags and no subtype exists. | very strong | bounded dispatcher disassembly | UID0003UL; UID0003VB | incorporate | applied |
| C06 | Owner/emitter UID0000FQ and `UserPane.cpp` route UID0000P1 are correct; LivingObjectPane is inherited support only. | very strong | large receiver offsets/class split | target/class/file/aggregates | incorporate | applied |
| C07 | Target remains one child; exact padding remains ignored; no raw/table child is created. | very strong | CFG/boundaries/xrefs | target/ignored verify-only | already-present | already-present |
| C08 | Flags high bit writes state[0], a multi-consumer local-player feature/UI mode. | strong | target + UserList/form consumers | UID0003UL/UserPane | incorporate | applied |
| C09 | Bit 0x04 writes byte 3 to inherited `m_actionGateState` at +0x19a, not ObjectStatusBlob dword. | very strong | width/offset/action consumers | UID0003UL | incorporate | applied |
| C10 | State[2] is `(flags & 2)==0` and gates viewport movement thresholds. | very strong | target + ProcessMovement | UID0003UL/UserPane | incorporate | applied |
| C11 | Base offset formula is 2/31 plus optional 8 and 9; old 10/39 is invalid. | very strong | exact instruction parity | UID0003UL Destination 1 | reject-invalid | applied |
| C12 | Bit 0x08 loads state[3..6], skips exact reserved positions, and preserves cursor ordering/max reads. | very strong | decompile/disassembly | UID0003UL | incorporate | applied |
| C13 | State[4] is blindness; change calls GetBounds then InvalidateRect. | very strong | target + UID0004QY | UID0003UL/UserPane | incorporate | applied |
| C14 | Movement byte is read after preincrement and stored to config +0x28de75 before option overwrite. | very strong | instructions/data flow | UID0003UL/g_pConfig | incorporate | applied |
| C15 | Movement branch tests/clears `m_movementState[3]` at +0x13eaf3; index 4 is distinct. | very strong | displacement scan/decompile | UID0003UL/UP/UQ/UserPane | incorporate | applied |
| C16 | Branch calls TryStepForward, ignores result, clears index 3 and m_isMoving; timer-removal path is invalid. | very strong | direct callee/body | UID0003UL Destination 1 | reject-invalid | applied |
| C17 | Reader is UInt32BE with explicit low-16 narrowing; UInt16BE is invalid. | very strong | call target/helper body/DI use | UID0003UL/UID0003YK | incorporate | applied |
| C18 | Bits 0/2/3/4/5/6 directly map Whisper/Shout/Advice/Magic/Weather/Fixed movement config bytes. | strong | target stores/NewOption labels | UID0003UL/g_pConfig/NewOption | incorporate | applied |
| C19 | Bit 8 overwrites movement-status config only after the movement branch; ordering is observable. | very strong | target data flow | UID0003UL/g_pConfig | incorporate | applied |
| C20 | Bits 12/13/14 map sound effects and SelfLook slot-5/6 alternate-style selectors. | strong | target/SelfLook consumers | UID0003UL/g_pConfig/SelfLook | incorporate | applied |
| C21 | Sound branches use Enable/DisableSoundEffects and mirror byte +5. | very strong | direct callees/stores | UID0003UL/SoundManager | incorporate | applied |
| C22 | Active GeneralPurposePanel child 6 receives `OnActivate(NULL)`; MainWindow wrapper is invalid. | very strong | global/accessor/vslot | UID0003UL | reject-invalid | applied |
| C23 | No length/null checks exist; malformed/truncated behavior and unconditional false return must remain. | very strong | ABI/CFG/negative evidence | UID0003UL | incorporate | applied |
| C24 | State indices 0,2,3,4,5,6 receive behavior-backed descriptive semantics; indices 1/7 remain reserved/unknown. | strong | all consumer inventory | UID0003UL/UserPane | incorporate | applied |
| C25 | Current nested LivingObjectPane/blank/open-question prose is historical and must be explicitly superseded, not deleted. | very strong | current page/prior reports | UID0003UL history | historicalize | applied |
| C26 | Preserve blank position and cumulative `Nested:8`; source order is after deferred user-list copy and before inventory parser. | very strong | address/file inventory/nesting | UID0003UL/UserPane file | already-present | already-present |
| C27 | Raise only target to 92/94; preserve path/title/owner/emitter/reconstructable/range. | strong | blocker closure/lexical caps | UID0003UL metadata | incorporate | applied |
| C28 | UID0003UP formal must replace two index-4 helper calls with exact index-3 tests. | very strong | binary +eaf3 reads | UID0003UP Destination 2 | reject-invalid | applied |
| C29 | UID0003UQ formal must replace two index-4 helper calls with exact index-3 tests. | very strong | binary +eaf3 reads | UID0003UQ Destination 3 | reject-invalid | applied |
| C30 | UserPane class/file prose records `m_playerSettingsState[8]` at `+0x1340fc` for settings indices 0/2 and conditional 3/4/5/6, separate `m_movementState[5]` at `+0x13eaf0` for pending-reply index 3 and direction-delay index 4, and preserves the complete class block byte-for-byte. | strong | target/consumers/current docs plus Gate 2 no-loss repair | UID0000FQ/UID0000P1 | incorporate | applied |
| C31 | UID0001KM records the same two-array distinction and exact direct option-store order Whisper/Shout/Advice/Magic/Weather/Fixed movement/movement-status/sound/SelfLook-5/SelfLook-6 while preserving the earlier packet movement-status branch; UID0003VB carries the exact opcode/body route; UID0001KL and LivingObjectPane pages remain verify-only where already correct. | strong | source family/dispatcher/current docs plus Gate 2 no-loss repair | aggregate/dispatcher | incorporate | applied |
| C32 | g_pConfig field cluster must record exact direct stores, labels, overwrite order, and no ApplyServerOptionBits call. | strong | target/NewOption/SelfLook | UID00028Q | incorporate | applied |
| C33 | SoundManager, PacketBuffer, NewOptionPane, SelfLookPane, and movement support get bounded caller/field corrections without score/route changes. | strong | direct callees/consumers | listed support docs | incorporate | applied |
| C34 | Exact no-loss manual coverage replacements are supplied for all rows made stale; remaining rows are verify-only. | very strong | current manual rows | supervisor-owned coverage text | incorporate | applied |
| C35 | Pre-callback generated UserPane.cpp was stale for target semantics; callback used scoped validators and a waited readback without manual generated edits. | very strong | generated readback/restrictions | report validator plan | incorporate | applied |

## Positive Evidence Summary
- Exact bytes and a modeled function object establish the range and ordinary source-bearing status.
- A sole case-8 dispatcher call proves UserPane reachability and the opcode/no-subtype contract.
- Every target call resolves to a documented helper or virtual contract; every field store has an exact offset and independent consumers.
- Cross-consumer state evidence resolves all body-blocking roles without requiring original symbols.
- The corrected body can preserve exact unchecked packet behavior and source order using normal mid-2000s C++.

## IDA MCP Facts
- Function/range facts: `sub_5AA480`, start `0x005aa480`, size `0x282`, exclusive end `0x005aa702`; successor `sub_5AA710` starts at `0x005aa710`; predecessor `sub_5AA3B0` ends at `0x005aa473`.
- Data/table/padding facts: SHA256 `CA93F04AE7BC6BD08862ED21420A7AD284710C5BBC643330EA5154CC22EDBF43`; 13-byte and 14-byte `int3` fences; no table/data owned by target.
- Xref facts: one direct code caller, dispatcher call at `0x005a774b`; no internal target-entry xrefs.
- Callee facts: narrow byte loads, GrafPort::GetBounds, MapPane virtual InvalidateRect, LivingObjectPane::TryStepForward, PacketBufferReadUInt32BE, Enable/DisableSoundEffects, GeneralPurposePanel::GetChildPaneByIndex, Pane::OnActivate, security cookie.
- Negative IDA facts: no second caller, no subtype parser, no user EH, no target string refs, no target-owned switch table, no observed invented wrapper helpers.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005aa480-0x005aa702` | UID0003UL | UserPane opcode-8 settings parser | true | UID0001KM/UID0001KL source indexes | `86/88 -> 92/94` | retain one source-bearing method |
| `0x005aa473-0x005aa480` | UID0000VN ignored | predecessor alignment | n/a | ignored | `100` | verify-only/no duplicate |
| `0x005aa702-0x005aa710` | UID0000VN ignored | successor alignment | n/a | ignored | `100` | verify-only/no duplicate |
| `0x005ab090-0x005ab410` | UID0003UP | movement reply support | true | UID0001KM/UID0001KL | `86/88` unchanged | correct two index tests only |
| `0x005ab410-0x005ab75d` | UID0003UQ | extended movement reply support | true | UID0001KM/UID0001KL | `86/88` unchanged | correct two index tests only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005a774b` | `UserPane::HandleServerMessage` case 8 -> target | sole live call; opcode 8; UserPane adjusted receiver |
| `0x005aa57f` | `GrafPort::GetBounds` | captures exact map bounds on blindness change |
| `0x005aa590` | MapPane/GrafPort primary vslot `+0x20` | `InvalidateRect(&bounds)` |
| `0x005aa5c1` | `LivingObjectPane::TryStepForward` | movement/status interaction; bool ignored |
| `0x005aa5da` | `PacketBufferReadUInt32BE` | four-byte big-endian decode narrowed to 16 bits |
| `0x005aa6b6/0x005aa6c6` | Enable/DisableSoundEffects | applies sound option before byte-5 mirror |
| `0x005aa6e2` | GeneralPurposePanel::GetChildPaneByIndex(6) | active option child lookup |
| `0x005aa6ed` | Pane vslot `+0x48` / `OnActivate(NULL)` | refreshes active child 6 |

## Documentation Evidence And IDA Status
- Current UserPane class/file, aggregates, and dispatcher support the accepted owner/route but do not contain the exact corrected parser behavior.
- UID0003Z8 already lists target `0x005aa480` as a TryStepForward caller; this directly disproves current target `RemovePendingTimers`.
- UID0003YK identifies `0x005754c0` as the four-byte reader, directly disproving current UInt16BE.
- UID0004QY and UID0002EZ resolve blindness and chat-level state indices. ProcessMovement and UserList/form consumers resolve indices 0/2/3.
- Current generated UserPane.cpp reproduces the incorrect current target formal and is read-only evidence, not an authority.
- Current manual UID0003UL row says “exact optional offsets” although current body uses wrong offsets; it requires the exact replacement below.

## Ranked Ownership Analysis

### 1. UserPane / NexusTK/ui/panels/UserPane.cpp
- Evidence for: receiver uses UserPane-only `+0x1340fc`, `+0x1340f8`, and `+0x13eaf3`; sole caller adjusts to the UserPane primary object; class/file declarations and sibling source order are established.
- Evidence against: exact original private method and field spellings are stripped.
- Decision: retain canonical owner/emitter UID0000FQ and file UID0000P1. Lexical uncertainty caps confidence but does not block source.

### 2. LivingObjectPane / NexusTK/map/LivingObjectPane.cpp
- Evidence for: target writes inherited `m_actionGateState`/`m_isMoving` and calls inherited TryStepForward.
- Evidence against: standalone LivingObjectPane ends at `0x20c`; target requires multi-megabyte UserPane extension fields and dispatcher-adjusted UserPane receiver.
- Decision: inherited dependency only, not owner/emitter.

### 3. Config, SoundManager, PacketBuffer, or GeneralPurposePanel source
- Evidence for: target consumes their fields/helpers.
- Evidence against: receiver, dispatch, state array, and method ABI are UserPane-specific; these modules own dependencies, not orchestration.
- Decision: support docs only; no ownership transfer.

### Proposed new file/grouping, if applicable
- Not applicable. Existing `NexusTK/ui/panels/UserPane.cpp` is exact.

## Source Placement
- Recommended source file/class/module placement: private or non-public UserPane member definition in `NexusTK/ui/panels/UserPane.cpp`.
- Source order: after `CopyDeferredUserListPacket` at `0x005a9310` and later unrelated source islands, before `ParseInventorySlotUpdatePacket` at `0x005aa710`; retain blank explicit emitter position and validator ordering.
- Rejected placements: LivingObjectPane.cpp, Config.cpp, SoundManager.cpp, PacketBuffer.cpp, and GeneralPurposePanel.cpp.
- Remaining placement uncertainty: exact original header visibility/private spelling only; no file/owner uncertainty.

## Range / Split / Padding / Reclassification Analysis
- Exact target half-open range is preserved. The final instruction is `ret 4`; exclusive end is `0x005aa702`.
- Preceding and following `int3` spans remain existing ignored entries. No ignored duplicate should be created.
- No child/table/raw-helper split is warranted. Branches share one stack frame, cookie, return, and entry.
- Parent cumulative nesting remains `8`: the two open UserPane source-family aggregates contribute cumulative depth; it is not a child count.

## Negative Evidence Summary
- No evidence supports the existing base offsets, ObjectStatusBlob field, timer-removal helper, 16-bit reader, compressed config helper, stale sound names, or MainWindow refresh wrapper.
- No evidence supports LivingObjectPane ownership after the UserPane split.
- No internal entry, table, padding-owned code, or alternate caller supports a child split.
- No length/null checks or exception path supports safer malformed-packet behavior.
- No symbols prove exact private lexical names for the state indices or the two SelfLook style flags; those remain explicitly descriptive.

## IDA Rename / Type / Comment Recommendations
- Source-facing method: retain `UserPane::ParsePlayerSettingsPacket(const unsigned char *packet)`.
- Source-facing state index constants: `kPlayerFeatureMode`, `kUseViewportMovementThresholds`, `kDirectionMode`, `kBlindnessLevel`, `kChatDisplayRestrictionLevel`, and `kChatSendRestrictionLevel`; descriptive, behavior-backed, not symbol-proven.
- Config names: `m_whisperEnabled`, `m_shoutEnabled`, `m_adviceEnabled`, `m_magicEnabled`, `m_weatherEnabled`, `m_fixedMovementEnabled`, `m_sendMovementStatusBit`, `m_soundEffectsEnabled`, `m_selfLookSlot5AlternateStyle`, `m_selfLookSlot6AlternateStyle`; labels exact for the first six, descriptive for the last two.
- SoundManager byte +5: `m_soundEffectsOptionEnabled`, descriptive mirror-state name distinct from runtime +0x41.
- IDA database edits are not requested and were not performed.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. Exactly three accepted destination blocks follow; these are the only applied C++ edits and they remain byte-for-byte equal to the current managed ordinary blocks.
- Third-party import: not applicable; this is project source, not a static third-party embed.

### Destination 1 - UID0003UL
`by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::ParsePlayerSettingsPacket(const unsigned char *packet)
{
    enum PlayerSettingsStateIndex
    {
        kPlayerFeatureMode = 0,
        kUseViewportMovementThresholds = 2,
        kDirectionMode = 3,
        kBlindnessLevel = 4,
        kChatDisplayRestrictionLevel = 5,
        kChatSendRestrictionLevel = 6
    };

    const unsigned char flags = packet[1];
    m_playerSettingsState[kPlayerFeatureMode] =
        static_cast<unsigned char>(flags >> 7);
    if (flags & 0x04)
        m_actionGateState = 3;
    m_playerSettingsState[kUseViewportMovementThresholds] =
        (flags & 0x02) == 0;

    unsigned int offset = (flags & 0x40) ? 31 : 2;
    if (flags & 0x20)
        offset += 8;
    if (flags & 0x10)
        offset += 9;
    if (flags & 0x08)
    {
        const unsigned char oldBlindnessLevel =
            m_playerSettingsState[kBlindnessLevel];
        m_playerSettingsState[kDirectionMode] = packet[offset++];
        m_playerSettingsState[kBlindnessLevel] = packet[offset++];
        m_playerSettingsState[kChatDisplayRestrictionLevel] = packet[offset++];
        m_playerSettingsState[kChatSendRestrictionLevel] = packet[offset++];
        ++offset;
        if (oldBlindnessLevel !=
            m_playerSettingsState[kBlindnessLevel])
        {
            RectBounds bounds;
            m_mapPane->GetBounds(&bounds);
            m_mapPane->InvalidateRect(&bounds);
        }
    }

    g_pConfig->m_sendMovementStatusBit = packet[++offset];
    if (g_pConfig->m_sendMovementStatusBit &&
        m_movementState[3] != 0)
    {
        TryStepForward();
        m_movementState[3] = 0;
        m_isMoving = false;
    }

    const unsigned short options = static_cast<unsigned short>(
        PacketBufferReadUInt32BE(packet + offset + 1));
    g_pConfig->m_whisperEnabled = (options & 0x0001) != 0;
    g_pConfig->m_shoutEnabled = (options & 0x0004) != 0;
    g_pConfig->m_adviceEnabled = (options & 0x0008) != 0;
    g_pConfig->m_magicEnabled = (options & 0x0010) != 0;
    g_pConfig->m_weatherEnabled = (options & 0x0020) != 0;
    g_pConfig->m_fixedMovementEnabled = (options & 0x0040) != 0;
    g_pConfig->m_sendMovementStatusBit = (options & 0x0100) != 0;
    g_pConfig->m_soundEffectsEnabled = (options & 0x1000) != 0;
    g_pConfig->m_selfLookSlot5AlternateStyle =
        (options & 0x2000) != 0;
    g_pConfig->m_selfLookSlot6AlternateStyle =
        (options & 0x4000) != 0;

    if (g_pConfig->m_soundEffectsEnabled)
    {
        g_pSoundManager->EnableSoundEffects();
        g_pSoundManager->m_soundEffectsOptionEnabled = true;
    }
    else
    {
        g_pSoundManager->DisableSoundEffects();
        g_pSoundManager->m_soundEffectsOptionEnabled = false;
    }

    if (g_pGeneralPurposePanel->m_activeChildIndex == 6)
        g_pGeneralPurposePanel->GetChildPaneByIndex(6)->OnActivate(NULL);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID0003UP
`by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::HandleMovementReplyPacket(const unsigned char *packet)
{
    const unsigned char direction = packet[1];
    const int serverX = PacketBufferReadUInt16BE(packet + 2);
    const int serverY = PacketBufferReadUInt16BE(packet + 4);
    const int viewportColumn = PacketBufferReadUInt16BE(packet + 6);
    const int viewportRow = PacketBufferReadUInt16BE(packet + 8);
    const unsigned char historyIndex = packet[10] & 0x7f;

    if (!m_isMoving &&
        (!m_mapPane->AllowsMovementStatusFlag() ||
         !g_pConfig->m_sendMovementStatusBit))
    {
        WarpToPosition(serverX, serverY, viewportColumn, viewportRow);
        if (direction != 4)
            InitializeWalkAnimation(direction);
        SetMovementReplyState();
        m_mapPane->RecenterAndSendPosition(
            serverX, serverY, viewportColumn, viewportRow, false);
        m_mapPane->InvalidateObject(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        return true;
    }

    if (!m_mapPane->AllowsMovementStatusFlag() ||
        g_pConfig->m_sendMovementStatusBit != 1)
    {
        if (serverX == m_tileX && serverY == m_tileY && direction == m_facing)
        {
            SetMovementReplyState();
            if (m_movementState[3] != 0)
            {
                const int eventId = m_actionMode != 0
                    ? kLivingTimerForwardStep : kUserPaneMovementStep;
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this), eventId,
                    0, m_facing, 0);
            }
            return false;
        }

        MapPoint step;
        m_mapPane->DirectionToTileOffset(&step, direction);
        WarpToPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow, false);
        m_mapPane->InvalidateObject(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        return false;
    }

    if (direction & 0x80)
    {
        SetMovementReplyState();
        if (m_movementState[3] != 0)
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLivingTimerForwardStep, 0, m_facing, 0);
        return false;
    }
    if (historyIndex >= m_movementHistoryCapacity)
        return false;
    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[historyIndex];
    if (!record.active)
        return false;
    if (record.tileX != serverX || record.tileY != serverY ||
        record.direction != direction)
    {
        MapPoint step;
        m_mapPane->DirectionToTileOffset(&step, direction);
        WarpToPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow, false);
        m_mapPane->InvalidateObject(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        ClearAllMovementHistoryRecords();
    }
    ClearMovementHistoryRecordByIndex(historyIndex);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - UID0003UQ
`by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::HandleExtendedMovementReplyPacket(const unsigned char *packet)
{
    const unsigned char direction = packet[1];
    const int serverX = PacketBufferReadUInt16BE(packet + 2);
    const int serverY = PacketBufferReadUInt16BE(packet + 4);
    const int viewportColumn = PacketBufferReadUInt16BE(packet + 6);
    const int viewportRow = PacketBufferReadUInt16BE(packet + 8);
    const unsigned char historyIndex = packet[10] & 0x7f;

    if (!m_isMoving &&
        (!m_mapPane->AllowsMovementStatusFlag() ||
         !g_pConfig->m_sendMovementStatusBit))
    {
        WarpToPosition(serverX, serverY, viewportColumn, viewportRow);
        if (direction != 4)
            InitializeWalkAnimation(direction);
        SetMovementReplyState();
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        return true;
    }

    if (!m_mapPane->AllowsMovementStatusFlag() ||
        g_pConfig->m_sendMovementStatusBit != 1)
    {
        if (serverX == m_tileX && serverY == m_tileY && direction == m_facing)
        {
            SetMovementReplyState();
            if (m_movementState[3] != 0)
            {
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kUserPaneMovementStep,
                    m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
                    m_facing, 0);
            }
            return false;
        }

        MapPoint step;
        m_mapPane->DirectionToTileOffset(&step, direction);
        WarpToPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow);
        m_mapPane->RecenterAndSendPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow, false);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        return false;
    }

    if (direction & 0x80)
    {
        SetMovementReplyState();
        if (m_movementState[3] != 0)
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kUserPaneMovementStep,
                m_objectStatus.m_displayStatusByte / g_movementSubstepScale,
                m_facing, 0);
        return false;
    }
    if (historyIndex >= m_movementHistoryCapacity)
        return false;
    LocalMovementHistoryRecord &record =
        m_movementHistoryRecords[historyIndex];
    if (!record.active)
        return false;
    if (record.tileX != serverX || record.tileY != serverY ||
        record.direction != direction)
    {
        MapPoint step;
        m_mapPane->DirectionToTileOffset(&step, direction);
        WarpToPosition(
            serverX + step.x, serverY + step.y,
            viewportColumn, viewportRow);
        m_mapPane->UpdateObjectPaneScreenBounds(this);
        RefreshAllLinkedObjects();
        g_pTimerMgr->RemoveTimersForOwner(&m_mapPane->m_timerHandler);
        ClearAllMovementHistoryRecords();
    }
    ClearMovementHistoryRecordByIndex(historyIndex);
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: Destination 1 follows instruction order, uses exact unchecked accesses, keeps the first movement-status write before the low-word option overwrite, mirrors SoundManager byte +5 after the helper, and performs the exact active-child virtual call.
- Source shape: ordinary locals, an internal enum, direct fields, documented helper names, one stack RectBounds, and no decompiler labels, vtable syntax, handwritten cookie, or ABI mechanics.
- Destinations 2/3 preserve every accepted current line except the two tests whose helper reads the wrong byte.

## Final Recommendation
- Destination 1 is applied to UID0003UL, the exact Item Summary and full binary/source evidence are current, and target metadata is `92/94` with every non-score field preserved.
- Destinations 2/3 are applied byte-for-byte to UID0003UP/UQ; each remains `86/88` with unchanged owner/emitter/range/route/nesting and two corrected index-3 tests.
- The three shared UserPane destinations were reread and rebased against the executed B001/B004 evidence and current B001/B003/B004 callback union without loss. They now explicitly separate `m_playerSettingsState[8]` at `+0x1340fc` from `m_movementState[5]` at `+0x13eaf0`, preserve conditional settings writes and exact movement-byte roles, and record the ten direct RegistryConfig stores in machine order. The eight other bounded support destinations retain the accepted dispatcher, config, SoundManager, PacketBuffer, NewOptionPane, and SelfLook consumer evidence at unchanged scores/routes/formals.
- UID0001KL, LivingObjectPane class/file, TryStepForward, MapPane/GrafPort, GeneralPurposePanel/Pane, UID0004QY, UID00015W, and ignored padding were read-only verified; no contradiction justified an ordinary edit.
- No item is left no-owner or non-emitting, no new child or UID was required, every accepted claim is terminal, and no B005 implementation work remains.

## Recommended Target Doc Changes
- Target path: `by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md`.
- Applied metadata: completion/confidence changed only from `86/88` to `92/94`; UID/path/title/range, owner/emitter `0000FQ`, reconstructable true, blank position, and `Nested:8` remain unchanged.
- Applied Item Summary: `Exact opcode-0x08 UserPane player-settings parser with proven 0x282-byte range, case-8 dispatcher route, flag-derived state indices, 2/31 optional-offset arithmetic, blindness bounds invalidation, movement-status/TryStepForward interaction, narrowed UInt32BE option word, ten direct config stores, SoundManager mirror, active child-6 OnActivate refresh, unchecked packet behavior, and complete source-ready C++.`
- Destination 1 and all bytes/hash, boundary/padding, CFG/cookie/no-user-EH, ABI/caller/opcode, cursor/max-read, field/store/callee/global, positive/negative, source-order, score, lexical-cap, and rejected-alternative evidence are applied at report-level detail. Scoped validator `000000012845` passed; final waited repair command `000000012887` generated exactly one target definition and no empty marker.
- Old LivingObjectPane ownership, blank-body blocker, unresolved subtype/fields, speed token, 10/39 offsets, ObjectStatusBlob action-state, invented wrappers, wrong reader/sound names, and MainWindow refresh claims remain only as explicitly superseded or rejected history.
- Current target SHA256 is `093DFBFD99A21034E0446DD9FDE5BA05526DF0C725814958F512DEB8BDFF1752`; Destination 1 remains mechanically equal to the managed target block.

## Recommended Support Doc Changes
- Changed and validated: UID0003UP and UID0003UQ contain Destinations 2/3 plus exact `+0x13eaf3` evidence while preserving `86/88`, all metadata/routes, and the distinct index-4 helper contract (`000000012846`, `000000012847`).
- Changed and validated after no-loss rebase: `by-class/UserPane.md`, `by-file/UserPane.md`, and UID0001KM preserve B001 `StartDirectionalAnimation(char direction)`, B004 `itemMetaKey`/`ownerName`/`currentDurability`/`protectionCount`, opcode-`0x0f` inventory behavior, B003/B004 pending callback unions, all unrelated content, and the complete class formal. Original callback commands were `000000012848` through `000000012850`; bounded repair commands `000000012884` through `000000012886` corrected only the array semantics, conditional settings assignments, direct option-store order, and historical blindness reference. Current hashes are `E4AA6D4F...5291`, `5C20099E...AEF`, and `F1835241...EA98` respectively.
- Changed and validated: UID0003VB records the opcode-`0x08` no-subtype route, sole call, and adjusted UserPane receiver at unchanged score/formal (`000000012851`).
- Changed and validated: UID00028Q records exact `+0x28de6e..+75`, `+48`, `+60/+61` mappings, labels, overwrite order, direct stores, no-helper evidence, and lexical caps at unchanged metadata/formal (`000000012852`).
- Changed and validated: `by-class/SoundManager.md` and `SoundManagerPlaybackControls.md` record the target caller and `+5` option/deferred-restore mirror versus runtime `+0x41` at unchanged scores/routes/formals (`000000012853`, `000000012854`).
- Changed and validated: UID0003YK records the UInt32BE target caller and explicit low-word narrowing at unchanged score/route/formal (`000000012855`).
- Changed and validated: `by-class/NewOptionPane.md` and `NewOptionPaneServerOptionHelpers.md` record label/offset source-name evidence and the five-byte-helper versus ten-direct-store boundary at unchanged scores/routes/formals (`000000012856`, `000000012857`).
- Changed and validated: UID0003QN records exact `+0x28de60/+61` slot-5/6 alternate resource/color consumers at unchanged score/route/formal (`000000012858`).
- Verify-only/excluded with reason: UID0001KL, UID00007B, UID0000KU, UID0003Z8, UID0004QY, GrafPort/MapPane bounds and invalidation pages, UID00015W, GeneralPurposePanel class/file/global, Pane vtable, and current ignored padding already contained same-or-greater supporting truth or remained outside the accepted edit boundary. Read-only recheck found no contradiction; none was edited.

## Score And Metadata Recommendation
- Historical pre-callback target: `86/88`, owner/emitter UID0000FQ, true, blank position, `Nested:8`.
- Current applied target: `92/94`; all metadata except scores remains unchanged.
- Completion 92: exact range, bytes/hash, CFG, ABI, dispatcher, packet arithmetic, fields, option mapping, callers/callees, source route, malformed behavior, first-draft body, and support corrections are complete.
- Confidence 94: direct binary evidence is exhaustive and independently corroborated. It remains below final-source certainty because original private method/state/config names are stripped, two SelfLook config names are behavior-descriptive, and explicit emitter position is not symbol-proven.
- Blocker removal: opcode/subtype closed; owner/source closed; blank/body closed; offsets closed; field widths/roles closed; movement helper/state closed; packet reader closed; config mapping closed; sound/panel refresh closed; range/split/nesting closed. No “needs investigation” blocker remains.
- Support scores/routes remain unchanged.

## Open Questions With Attempted Resolution
- Exact original private method name: symbols absent; current descriptive name fits dispatcher/behavior and established family. No C++ blocker; lexical cap only.
- Exact names for state indices 0/2/3/5/6: all consumers were inventoried. Roles are closed and descriptive names are supplied; exact lexical spelling remains unrecoverable from stripped binary.
- Exact names for config +60/+61: all displacement hits and SelfLook render branches were checked. They select alternate draw resource/color pairs for slots 5/6; no registry/UI string names them. Behavior-descriptive names are safe and cap confidence.
- SoundManager +5 original name: OptionPane and target mirror the requested sound-effects option while runtime enable is +0x41. `m_soundEffectsOptionEnabled` is conservative; no behavior uncertainty remains.
- PacketBuffer reader width: closed as UInt32BE with low-word narrowing, not unresolved.
- `Nested:8`: closed as cumulative aggregate depth, not child count.
- No open question affects range, owner, emitter, source route, score improvement, or ability to emit exact first-draft C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Manual rows inspected read-only: UID0003UL, UID0003UP, UID0003UQ, UID0001KL, UID0001KM, UID0000FQ, UID0000P1, UID00007B, UID0000KU, UID00028Q, UID0000DG, UID0000NV, UID00028R, UID00015W, UID00005Q, UID0000JQ, UID0003YK family placement, SelfLook aggregate, and current ignored padding.
- Accepted-report recheck covered the now-executed B001 UID0003U8 and B004 UID0003UM handoffs. B004's UID0003UM/two-padding/class/file facts and B001's signed-char/padding/table/timer/file facts are current ordinary evidence. The two shared rows below are full no-loss unions of both executed contributions, all previously current movement/packet/history facts, and B005's settings facts. The other five B005 replacement rows were rechecked and have no B001/B004 overlap.
- Exact rows still requiring external supervisor-owned replacement are below. B005 did not edit manual coverage.

File `by-memory/-coverage-report.md`, replace UID0003UL row:

        - [UID:0003UL][0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket](by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md) 0x005aa480-0x005aa702 | UserPane member | UserPaneParsePlayerSettingsPacket : reconstructable : 92% : very-strong : Exact opcode-0x08 UserPane settings parser with case-8 dispatcher route, 2/31 optional-offset arithmetic, m_playerSettingsState indices 0/2 plus conditional 3-6 including blindness/chat restrictions, GetBounds/InvalidateRect blindness refresh, separate m_movementState index-3 TryStepForward interaction, narrowed UInt32BE option word, ten ordered direct config stores, SoundManager enable/mirror behavior, active GeneralPurposePanel child-6 OnActivate refresh, unchecked packet behavior, and complete source-ready C++.

Replace UID0003UP row:

        - [UID:0003UP][0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket](by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md) 0x005ab090-0x005ab410 | UserPane member | UserPaneHandleMovementReplyPacket : reconstructable : 86% : strong : Complete source-ready baseline opcode-0x0b movement reply with exact warp/history, MapPane recenter/send/state behavior, and corrected pending-reply test at m_movementState[3]/+0x13eaf3 rather than the distinct index-4 direction-delay helper.

Replace UID0003UQ row:

        - [UID:0003UQ][0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket](by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md) 0x005ab410-0x005ab75d | UserPane member | UserPaneHandleExtendedMovementReplyPacket : reconstructable : 86% : strong : Complete source-ready opcode-0x26 extended movement reply with capability-gated producer relation, distinct timer/recenter branches, and corrected pending-reply test at m_movementState[3]/+0x13eaf3 rather than the distinct index-4 direction-delay helper.

Replace UID00028Q row:

    - [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) 0x0067a7c8-0x0067a7cc | global pointer | g_pConfig : reconstructable : 86% : strong : Config/RegistryConfig singleton pointer with zero storage, 433 xrefs, constructor/startup/teardown lifecycle, base-typed Config pointer and derived-runtime use, broad UI/profile/network/audio consumers, exact NewUserDialogPane SetLogData success consumer, and UID0003UL's ordered direct server-option stores for Whisper/Shout/Advice/Magic/Weather/Fixed movement, movement-status overwrite, sound effects, and SelfLook slot-5/6 alternate styles.

File `by-class/-coverage-report.md`, replace UID0000FQ row with a no-loss union:

- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 92% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, signed plain-char StartDirectionalAnimation(char direction), 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, exact m_playerSettingsState[8] at +0x1340fc with index[0] feature/UI mode, [2] viewport-threshold mode, [3] direction mode, [4] MapPane-render blindness with bounds invalidation, and [5]/[6] chat display/send restriction levels while [1]/[7] remain reserved, separate m_movementState[5] at +0x13eaf0 with index[3] pending reply and index[4] direction delay, and preserved full field/record/size-guard layout surface.

Replace UID0000DG row, preserving the current ownership confidence while correcting the stale manual score and adding the accepted field fact:

- [UID:0000DG][SoundManager](by-class/SoundManager.md) : reconstructable : 87% : strong : SoundManager class ownership and core audio role with playback/resource state, inferred runtime sound-effects flag at +0x41, distinct sound-effects option mirror byte at +5 written by OptionPane and UID0003UL after EnableSoundEffects/DisableSoundEffects, source route through SoundManager.cpp, and exact field spellings retained as confidence caps.

File `by-file/-coverage-report.md`, replace UID0000P1 row with a no-loss union:

- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, signed plain-char StartDirectionalAnimation(char direction), corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior, preserved action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the exact 508-byte inventory record with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, active UserStatusPane slot-count bound, exact write order, and preserved invalid-slot/always-false behavior, plus source-ready opcode-0x08 settings parsing with exact m_playerSettingsState[8] assignments to indices 0/2 and conditional 3/4/5/6, separate m_movementState[5] pending-reply index 3 versus direction-delay index 4, 2/31 offset arithmetic, blindness invalidation, ordered config/sound/active-panel effects, and adjacent movement-reply index-3 corrections.

- Verify-only/no replacement required: UID0001KL/UID0001KM manual rows remain true at unchanged scores and aggregate disposition; UID00007B/UID0000KU already exclude UserPane-only large-offset methods; UID0000NV/UID00028R audio owner/global rows remain true; GeneralPurposePanel/accessor rows remain true; PacketBuffer/SelfLook method children have no standalone current row whose score/state changes; ignored padding rows remain exact. Current B004 UID0003UM/two-padding rows and the executed B001 facts remain separate retained evidence; neither narrows the full UID0000FQ/UID0000P1 unions above.
- Placement is external lifecycle state: after independent verification, the supervisor-owned replacements can occupy existing address/class/file order. No tracker text is proposed; validator-owned tracker/generated reports refresh only through normal validator workflow.

## Follow-Up Actions
- B005 target/support implementation, validators, generated readback, lease closure, and same-report reconciliation are complete. No accepted B005 item remains pending.
- External supervisor-owned state: fresh exact-artifact Gate 1 review, independent Gate 2 claim verification, optional application of the preserved manual coverage rows, and any later report execution/archive/tracker lifecycle. This report records no assumption that any of those external actions has occurred.
- A-agent actions: none.
- Future technical research: none required for the accepted scope. Original private lexical spellings remain confidence caps, not unresolved behavioral or source-placement work.

## Confidence
- Recommendation confidence: very strong.
- Score confidence: strong for `92/94` under current project conventions.
- Remaining uncertainty: original private lexical spellings only; all behavioral/source-placement blockers are closed.

## Validator Results
- All B005 commands ran from `source-3/project-documentation` as scoped file validators with `--apply --queue-timeout 240`; commands `000000012859` and `000000012887` additionally used `--wait-generated`. Every command exited 0 with `ok: 1`.

| Command | Timestamp | Scoped ordinary path | Result and diagnostics |
| --- | --- | --- | --- |
| `000000012845` | `2026-07-15T04:29:08-04:00` | `by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md` | exit 0, `ok:1`; completion/confidence and autogen registry synchronized to `92/94`; projected stats updated; generated refresh deferred. |
| `000000012846` | `2026-07-15T04:31:19-04:00` | `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | exit 0, `ok:1`; registry/reference index updated; projected stats updated; no target warning; generated refresh deferred. |
| `000000012847` | `2026-07-15T04:31:51-04:00` | `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | exit 0, `ok:1`; registry/reference index updated; projected stats updated; no target warning; generated refresh deferred. |
| `000000012848` | `2026-07-15T04:32:40-04:00` | `by-class/UserPane.md` | exit 0, `ok:1`; seven pre-existing `missing_ref_uid` diagnostics for unregistered historical UIDs; projected stats updated; generated refresh deferred. |
| `000000012849` | `2026-07-15T04:33:20-04:00` | `by-file/UserPane.md` | exit 0, `ok:1`; 22 pre-existing `missing_ref_uid` diagnostics in retained historical inventory; projected stats updated; generated refresh deferred. |
| `000000012850` | `2026-07-15T04:34:06-04:00` | `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | exit 0, `ok:1`; 11 pre-existing `missing_ref_uid` diagnostics in retained aggregate history; projected stats updated; generated refresh deferred. |
| `000000012851` | `2026-07-15T04:35:00-04:00` | `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | exit 0, `ok:1`; six pre-existing UID0003VC missing-reference diagnostics; UID0003UL reference indexed; generated refresh deferred. |
| `000000012852` | `2026-07-15T04:35:33-04:00` | `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | exit 0, `ok:1`; UID0003UL reference indexed; no warning; generated refresh deferred. |
| `000000012853` | `2026-07-15T04:36:06-04:00` | `by-class/SoundManager.md` | exit 0, `ok:1`; 20 pre-existing missing-reference diagnostics from retained SoundManager child history; UID0003UL reference indexed; generated refresh deferred. |
| `000000012854` | `2026-07-15T04:36:41-04:00` | `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | exit 0, `ok:1`; six pre-existing UID0003ZJ missing-reference diagnostics; UID0003UL reference indexed; generated refresh deferred. |
| `000000012855` | `2026-07-15T04:37:11-04:00` | `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md` | exit 0, `ok:1`; UID0003UL reference indexed; no warning; generated refresh deferred. |
| `000000012856` | `2026-07-15T04:37:44-04:00` | `by-class/NewOptionPane.md` | exit 0, `ok:1`; five pre-existing UID00038E missing-reference diagnostics; UID0003UL reference indexed; generated refresh deferred. |
| `000000012857` | `2026-07-15T04:38:23-04:00` | `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md` | exit 0, `ok:1`; UID0003UL reference indexed; no warning; generated refresh deferred. |
| `000000012858` | `2026-07-15T04:38:53-04:00` | `by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | exit 0, `ok:1`; validator inserted the required metadata-header blank and synchronized unchanged UID/score/owner registry fields; two pre-existing UID0003QU/UID0003QV missing-reference diagnostics; generated refresh deferred. |
| `000000012859` | `2026-07-15T04:39:34-04:00` | final waited revalidation of UID0003UL | exit 0, `ok:1`; registry rebuilt (`4959` nodes, `3997` edges), projected stats refreshed, generated refresh completed. Project-wide diagnostics were 14 children-fallback inserts, 86 children-marker-missing notices, 170 emitter-has-no-code notices, and 281 generated metadata refreshes; none is target-specific. |
| `000000012884` | `2026-07-15T05:13:40-04:00` | Gate 2 repair of `by-class/UserPane.md` | exit 0, `ok:1`; corrected the two-array semantics under one short lease; validator reported five pre-existing missing-reference rows, normalized two UID0003VA link occurrences, updated the reference index/projected stats, and deferred generation. |
| `000000012885` | `2026-07-15T05:14:39-04:00` | Gate 2 repair of `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | exit 0, `ok:1`; corrected the settings/movement split and ten-store order under one short lease; validator reported nine pre-existing missing-reference rows, normalized two UID0003VA link occurrences, updated the reference index/projected stats, and deferred generation. |
| `000000012886` | `2026-07-15T05:15:20-04:00` | Gate 2 repair of `by-file/UserPane.md` | exit 0, `ok:1`; corrected historical blindness storage, conditional settings writes, both-array ownership, and option order under one short lease; validator reported 18 pre-existing missing-reference rows, normalized four UID0003VA link occurrences, updated the reference index/projected stats, and deferred generation. |
| `000000012887` | `2026-07-15T05:15:41-04:00` | final waited revalidation of UID0003UL after repair | exit 0, `ok:1`; registry rebuilt (`4968` nodes, `4004` edges), projected stats refreshed, generated refresh completed. Project-wide diagnostics were 14 children-fallback inserts, 86 children-marker-missing notices, 170 emitter-has-no-code notices, and 281 generated metadata refreshes; none is target-specific. |

- Validator-owned side effects: projected statistics, reference/autogen registry state, normalized UID0003VA link text, generated metadata, and generated output refreshed through the commands above. B005 did not edit those files manually and did not edit manual coverage.
- Historical original-callback generated proof: `auto-generated/NexusTK/ui/panels/UserPane.cpp`, 67,095 bytes, 1,815 physical lines, header command `000000012859`, refreshed `2026-07-15T04:39:34-04:00`, SHA256 `63954B8746420C481BDB60F4D009731D379FEDA29FE24C0EF70D7E3097AA52DD`.
- External read-only generated checkpoints observed between callback and repair were command `000000012867` at `2026-07-15T04:57:30-04:00`, SHA256 `E6A70E327F3FF79E1ABAE41BE94F4223BED200ABAFEBC659AFA33C2DBCA8B9E7`; command `000000012870` at `2026-07-15T04:59:38-04:00`, SHA256 `DB37A83267A49764DF38F4897DD71CD16C8B4148FCF800CAE2C9F524CA280D13`; command `000000012876` at `2026-07-15T05:02:17-04:00`, SHA256 `8993B97C1C33D4D5FF5827E1061F1CAC03BBB045BCA77197782014CD889339B3`; and supervisor Gate 2 checkpoint `000000012882` at `2026-07-15T05:08:12-04:00`, SHA256 `F4024F868B5B7D12BF66D468416DE4861702F143690A3C82CF2C25CFF5C95223`. B005 ran none of those external commands and did not edit generated output.
- Current final generated proof: `auto-generated/NexusTK/ui/panels/UserPane.cpp`, 89,852 bytes, 2,636 physical lines, header command `000000012887`, refreshed `2026-07-15T05:15:41-04:00`, SHA256 `A9E92CA64E55EB398DB1D29CC8C436C7C8B126AB584734A41EB6D1480113FAE3`.
- Current assertions: one UID0003UL marker and one `ParsePlayerSettingsPacket` definition; zero UID0003UL empty markers; one UID0003UP marker; one UID0003UQ marker; one class declaration each for `m_playerSettingsState[8]` and `m_movementState[5]`. The UID0003UL segment has eight `m_playerSettingsState[...]` references, two `m_movementState[3]` references, zero `m_movementState[4]` references, and option-store token offsets strictly increasing in accepted order: Whisper `1911`, Shout `1970`, Advice `2027`, Magic `2085`, Weather `2142`, Fixed movement `2201`, movement-status option `2266`, sound effects `2332`, SelfLook slot 5 `2396`, SelfLook slot 6 `2476`. It retains zero `RefreshMovementBounds`, `RemovePendingTimers`, `PacketBufferReadUInt16BE`, `ApplyServerOptionBits`, `g_pMainWindow`, generic `EnableSound`/`DisableSound`, or `m_objectStatus.m_actionState` spellings; UID0003UP and UID0003UQ retain their accepted index-3 tests and no direction-delay helper substitution.

## Changed Files
- The callback modified exactly 14 unique ordinary pages. The bounded Gate 2 repair re-edited only the three shared UserPane rows identified below. Every edit had a successful B005 lease acquisition immediately before reread/edit, its scoped validator while leased, and successful immediate release afterward.

| Ordinary path | Current SHA256 | Validator | Lease closure |
| --- | --- | --- | --- |
| `by-memory/0x005aa480-0x005aa702.UserPaneParsePlayerSettingsPacket.md` | `093DFBFD99A21034E0446DD9FDE5BA05526DF0C725814958F512DEB8BDFF1752` | `000000012845`; rechecked waited by `000000012859` and `000000012887` | acquired/released successfully |
| `by-memory/0x005ab090-0x005ab410.UserPaneHandleMovementReplyPacket.md` | `7FA7D2EAEB1B532F290306355839DDE7C55C5D43C7077DFF009C3896CB103292` | `000000012846` | acquired/released successfully |
| `by-memory/0x005ab410-0x005ab75d.UserPaneHandleExtendedMovementReplyPacket.md` | `D2B73895C35DBDABDC2FC442ECD6AB49422875743727B924199E4AE20A7C53ED` | `000000012847` | acquired/released successfully |
| `by-class/UserPane.md` | `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291` | original `000000012848`; bounded no-loss repair `000000012884`; validator-normalized UID0003VA link text preserved | acquired/validated/released in both cycles |
| `by-file/UserPane.md` | `5C20099E100A4FD69BACD1D37917BE2E8ADB8DF3CAFC942698F697FDDE785AEF` | original `000000012849`; bounded no-loss repair `000000012886`; validator-normalized UID0003VA link text preserved | acquired/validated/released in both cycles |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `F18352411F35DB759FAE28907827D2F07F72D1052BDEDC7994627DDF3675EA98` | original `000000012850`; bounded no-loss repair `000000012885`; validator-normalized UID0003VA link text preserved | acquired/validated/released in both cycles |
| `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | `E30201C80A3D0F12DFC920178626CDF8C384050FEBBD4CA6292DAFA0CA63FE6D` | `000000012851` | acquired/released successfully |
| `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | `FEA71AEB289AD443098D6E9B12BDA0126EA421909B02F57D5E43E007C258DF48` | `000000012852` | acquired/released successfully |
| `by-class/SoundManager.md` | `72E2DFFCAABC29FEDFD3A59A9361B22CD72FA1EB82B4A85240B83C14885C5B57` | `000000012853` | acquired/released successfully |
| `by-memory/0x0057a260-0x0057a88e.SoundManagerPlaybackControls.md` | `543E797B51B3332DA38955083C4E2490EB02B56AC1C898EB8EC4B449EE2152A9` | `000000012854` | acquired/released successfully |
| `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md` | `FDF03052FDA0433709D9A78ED931D3AB4565DB63F974A551B8B5FD84C5B7ACC4` | `000000012855` | acquired/released successfully |
| `by-class/NewOptionPane.md` | `A19941013DD2151F6F776472C1149EBA282DA147886A5912C969EB90F1B1DC95` | `000000012856` | acquired/released successfully |
| `by-memory/0x00540db0-0x00541114.NewOptionPaneServerOptionHelpers.md` | `475DCDE83ABD2B713E34A777D8F44607F66F389076983862E7DACF317334D814` | `000000012857` | acquired/released successfully |
| `by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | `B0D6BD9811BA5ABC67D29C1A2ED2FBD2F13883A44002654B8FA58B8444203212` | `000000012858` | acquired/released successfully |

- Mutated same-report artifact: `tools/leaser/Agents/Agent-B005/research/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md`; its exact post-repair SHA/bytes/lines are intentionally reported externally because embedding a self-hash would invalidate it.
- Created ordinary paths: none. Renamed paths: none. Deleted paths: none. No child UID was allocated.
- Validator-owned side effects include original callback `UserPane.cpp` SHA256 `63954B8746420C481BDB60F4D009731D379FEDA29FE24C0EF70D7E3097AA52DD` under B005 command `000000012859`, external checkpoints `000000012867`/`000000012870`/`000000012876`/`000000012882`, and current final SHA256 `A9E92CA64E55EB398DB1D29CC8C436C7C8B126AB584734A41EB6D1480113FAE3` under B005 command `000000012887`. Generated metadata, projected stats, reference indexes, normalized UID0003VA link text, and validator registry synchronization were tool-owned; none was manually edited by B005.
- Current `tools/leaser/Agents/Agent-B005/current_leases.md` and the global current-lease report contain zero B005 rows. Manual coverage, tracker, audit, supervisor, lifecycle, IDA, and generated files received no direct B005 edit. `execute_report`, report probe/count/revalidation/registry/lifecycle, move, and archive commands were not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: exact report-only SHA `0B92044FF2722EB2593FB3F990EB53C49ABA3247661F26B55EB4ACE7FD1D4384` passed Gate 1 before the callback.
- [x] Update UID0003UL with Destination 1, exact evidence, Item Summary, and `92/94` while preserving owner/emitter/range/position/Nested. Proof: current target hash `093DFBFD...FF1752`; validator `000000012845`; metadata/formal generated by original command `000000012859` and current command `000000012887`.
- [x] Update UID0003UP with Destination 2 and exact index-3 proof while preserving all other content/metadata. Proof: current hash `7FA7D2EA...3292`; validator `000000012846`; formal equality true.
- [x] Update UID0003UQ with Destination 3 and exact index-3 proof while preserving all other content/metadata. Proof: current hash `D2B73895...3ED`; validator `000000012847`; formal equality true.
- [x] Update UserPane class/file prose at report-level detail while preserving the complete class formal byte-for-byte. Proof: original validators `000000012848`/`000000012849`, bounded repair validators `000000012884`/`000000012886`, and current hashes `E4AA6D4F...5291`/`5C20099E...AEF`; both pages distinguish `m_playerSettingsState[8]` from `m_movementState[5]`, and accepted B001/B003/B004/current content remains intact.
- [x] Update UID0001KM and UID0003VB bounded target inventory/dispatch prose; verify UID0001KL current no-change state. Proof: original validators `000000012850`/`000000012851`, bounded aggregate repair validator `000000012885`, current UID0001KM hash `F1835241...EA98`, exact option-store order and two-array distinction, and UID0001KL read-only hash `133CB4AEFA47A472E81BB367FCA936E49BA5034570ADC2B6409BACC84974F844` with no contradiction.
- [x] Update g_pConfig exact option field cluster/order/naming evidence without score/formal/owner changes. Proof: validator `000000012852`, current hash `FEA71AEB...DF48`, unchanged metadata/formal.
- [x] Update SoundManager class/playback support, PacketBuffer reader support, NewOptionPane label support, and SelfLook OnPaint consumer evidence at unchanged scores/routes/formals. Proof: validators `000000012853` through `000000012858`; current hashes enumerated under Changed Files.
- [x] Verify LivingObjectPane class/file, TryStepForward, MapPane/GrafPort, GeneralPurposePanel/Pane, and ignored padding unchanged absent contradiction. Proof: read-only recheck found no accepted mismatch; representative hashes are recorded in Evidence Checked and these pages were excluded with reason.
- [x] Preserve target bytes/hash, CFG/cookie/no-user-EH, ABI/caller, packet cursor/max-read, all field/global/callee, and negative/rejected evidence without compression. Proof: target callback section retains the complete report evidence and Destination 1; C01-C24 are terminal.
- [x] Preserve historical LivingObjectPane, blank-body, old-speed, wrong-offset/helper/reader/global assumptions as explicitly superseded history. Proof: target historical sections and C25 remain present; none was deleted.
- [x] Apply Claim And Incorporation Ledger C01-C35 with legal callback states and destination-specific proof. Proof: 33 `applied`, two `already-present`, zero proposed/blocked rows; destinations and validator sections provide proof.
- [x] Keep every C++ line only inside the three exact managed destination blocks. Proof: exactly three formal blocks remain and mechanically equal the three current ordinary blocks; no illustrative body exists elsewhere.
- [x] Confirm third-party import is not applicable and no import directive is added. Proof: project source reconstruction, zero `third_party_embeds` directive.
- [x] Before shared UID0000FQ/UID0000P1/UID0001KM edits, inspect current leases and accepted B001/B004 artifacts; wait for any active callback/lease to clear, then reread each destination immediately before edit and rebase concurrent content. Proof: original executed report SHAs plus current B001/B003/B004 callback report SHAs/states are recorded under Supervisor Active Recheck/Evidence Checked; those agents deferred shared edits until B005 settled, the global lease report was empty, and each shared page was leased and reread serially.
- [x] Preserve B001 `StartDirectionalAnimation(char direction)`, B004 `itemMetaKey`/`ownerName`/`currentDurability`/`protectionCount`, opcode-`0x0f` inventory-parser prose, pending B003/B004 union content, and every unrelated current UserPane fact before applying only the bounded B005 repair. Proof: all exact tokens and complete opcode-`0x0f` inventory remain in current shared pages alongside the corrected arrays/order.
- [x] Acquire only one short lease immediately around each ordinary edit/scoped validator; release immediately. Proof: all 14 unique Changed Files rows record successful acquire/release; the three bounded repair cycles also record acquire/validate/release; no lease overlapped another B005 edit.
- [x] Run one scoped file validator per changed ordinary page and record command id/timestamp/exit/ok/side effects. Proof: original commands `000000012845` through `000000012858` plus repair commands `000000012884` through `000000012886` are enumerated under Validator Results; all exit 0, `ok:1`.
- [x] Run one final authorized `--wait-generated` refresh after all scoped validators. Proof: original command `000000012859` and current repair command `000000012887`; command `12887` at `2026-07-15T05:15:41-04:00` exited 0 with `ok:1` and completed generation.
- [x] Verify generated UserPane.cpp has one corrected UID0003UL body, corrected UID0003UP/UQ index-3 tests, exact ordering, no stale target calls/offsets, no duplicate target, and no decompiler/ABI mechanics. Proof: current command `12887`, SHA `A9E92CA6...FAE3`, has one target marker/definition, zero target empty markers, both array declarations, target settings/movement reference counts `8/2/0`, and strictly increasing accepted option-store token offsets.
- [x] Do not edit manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle files. Proof: no direct B005 edit occurred; validator-owned side effects are explicitly separated from ordinary edits.
- [x] Preserve exact supervisor-owned manual replacement text for later external application. Proof: seven exact replacement rows and placement/verify-only text remain under the required manual section.
- [x] Update report Current Target State, recommendations, ledger, validators, changed files, generated proof, checklist, and archive-neutral lifecycle wording after callback and bounded Gate 2 repair. Proof: each exact required heading now states terminal B005 truth, current hashes/commands, fresh Gate 1 requirement, and external lifecycle ownership.
- [x] Confirm no placeholder UID/token exists and no child UID allocation is required. Proof: zero brace UID placeholders, one retained target, no created/renamed ordinary path.
- [x] Confirm all B005 leases released before return. Proof: `tools/leaser/Agents/Agent-B005/current_leases.md` and global current lease report contain zero B005 rows.
- [x] Do not run/probe `execute_report`, lifecycle, move, archive, or registry commands. Proof: none was invoked; only authorized scoped file validators and final waited refresh ran.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: exact accepted SHA and callback authorization are recorded at the top of this artifact.
- [x] C01-C35 applied/already-present/excluded-with-reason with no blocked accepted claim. Proof: ledger has 35 legal terminal states and zero blocked/proposed rows.
- [x] Destinations 1-3 applied exactly. Proof: byte-for-byte formal comparisons are true for UID0003UL/UP/UQ.
- [x] All accepted support facts incorporated at same-or-greater report detail. Proof: 11 support pages are enumerated under Recommended Support Doc Changes/Changed Files; the three repaired shared pages now carry the exact two-array and option-order union; verify-only exclusions have concrete reasons.
- [x] Scores/metadata changed only as accepted. Proof: only UID0003UL moved `86/88 -> 92/94`; UID0003UP/UQ and every support score/route/formal remained unchanged.
- [x] Historical assumptions, rejected alternatives, malformed behavior, and negative evidence preserved. Proof: dedicated research/history/negative sections remain intact and current target prose explicitly supersedes rather than deletes them.
- [x] Scoped validators and final waited refresh recorded. Proof: command/timestamp/path/result/diagnostic table lists original `000000012845` through `000000012859` and bounded repair `000000012884` through `000000012887`.
- [x] Generated assertions independently checked read-only. Proof: current command `000000012887` header, refresh time, SHA, size/line count, marker/definition/array/order/token assertions are recorded under Validator Results.
- [x] Exact changed-file hashes and lease closure recorded. Proof: Changed Files contains 14 path/hash/validator/lease rows and zero B005 lease state.
- [x] Manual coverage text retained for supervisor application; B005 did not edit coverage. Proof: exact seven-row handoff remains, current manual hashes are recorded, and application remains external.
- [x] Same report reconciled to durable post-repair callback state and returned for fresh Gate 1 before independent Gate 2. Proof: all required headings, 35 ledger rows, three formals, 37 checked rows, current validator/generated/hash/lease evidence, and archive-neutral lifecycle language are present.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000012891","destination_path":"executed-b-agent-research/B005/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md","timestamp":"2026-07-15T05:32:33-04:00","uid":"0003UL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
