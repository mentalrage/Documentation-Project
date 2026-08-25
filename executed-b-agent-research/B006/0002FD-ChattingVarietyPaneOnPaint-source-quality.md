** TARGET-REPORT-UID:0002FD **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0002FD ChattingVarietyPane OnPaint Source Quality

> Removed executable code archive: [0002FD-ChattingVarietyPaneOnPaint-source-quality-removed.md](0002FD-ChattingVarietyPaneOnPaint-source-quality-removed.md). This non-authoritative archive preserves report-local script history only; it must not be executed and is not report evidence.

## Finalized Report / Current Recommendation

- Retain [UID:0002FD] as reconstructable ChattingVarietyPane::OnPaint, owned/emitted through [UID:00001Y], placed under [UID:0000I5] / NexusTK/social/Chatting.cpp.
- Retain 94/94, CANONICAL_OWNER:00001Y, RECONSTRUCTABLE:TRUE, and EMITTER_UIDS:00001Y.
- Retain the exact method-only formal CPP below. Formal H stays blank because the parent declares OnPaint and UID0002RX owns SayInputMode in SayInputPanes.h.
- Correct behavior is source-ready: 0x004b9670 sets text-back-fill color 0 at GrafPort +0x78; 0x004b9680 sets text color 128 at +0x7c; both text calls use the same state at x + 1 and x.
- UserPane say mode, EPFTileContext, GrafPort, ImageLib/resource alias, g_pEPFLib, selector global, and shared enum placement are resolved. Inferred lexical names use plausible human source spellings, never raw IDA labels.
- B006 completed the authorized documentation callback and five scoped validator reruns. Manual coverage, generated/compile checks, lifecycle, and IDA mutation/save/readback remain supervisor-owned.
- Section 21 is the sole current IDA handoff authority. A01-A04 give exact entity/address, literal observed pre-state, action or no-change disposition, evidence, constraints, and expected readback. A01 permits only A01-NAME, A01-LOCAL-THIS, A01-LOCAL-CONTEXT, A01-LOCAL-TEXT, A01-TYPE, and A01-COMMENT while freezing exactly one inbound data xref at `0x00614ee4` and zero ordinary code callers; A02 permits only A02-NAME, A02-LOCAL, A02-TYPE, and A02-COMMENT while freezing its exact literal 11-reference set and every other unlisted prestate.
- This report is non-executable. Former V1-V6 packages, script fixtures, launchers, hostile suites, and package-only receipts were removed. Their failures remain history only and provide no current Gate 1, IDA, save, rollback, process, filesystem, or lifecycle credit.
- C2FD-031..038 remain proposed and unchecked pending direct supervisor rebase, acceptance, MCP/IDA application, and readback.

## Supporting Research

- Fresh primary-supervisor Gate 2B prestate rebase after the completed documentation callback: canonical live IDB readback proves helper `0x004b9670` has exactly 11 inbound references at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`. The former overcounted A02 handoff was stale report text; this rebase supersedes that count without changing helper identity, behavior, ownership, bytes, type/frame recommendation, ordinary documentation evidence, or any persisted IDA state.

- Dated live MCP evidence snapshot: session `b002-uid0004hv-persist-reopen`, worker PID `24648`, canonical IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status:ok`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`. Bounded IDB-backed function, frame, type, item, comment, byte, name, and xref queries succeeded, so the analysis flag was context rather than an outage.
- Dated canonical disk snapshot at `2026-08-05T16:06:58.1612410-04:00`: SHA256 `77F5EF16C3CD3D78D86B6AA15768830BC11E6B6DC3DB44EB9537D30509538127`, size `143196656`. Session/PID/disk values are evidence snapshots only; every supervisor Gate 2B attempt must dynamically rebind with `idb_list`, `server_health`, and a fresh disk identity check.
- Target documentation snapshot: SHA256 `549FAAC1A740F7526A79D11CE70E0488938810ADB42E2C4EDC2B4A551F1DEC40`, `10228` bytes, `86/91`, owner/emitter `00001Y`, reconstructable true, blank CPP/H.
- Parent class snapshot: SHA256 `356945596D97B29B13D324492E5C3958003B3DC7FEB032ABAB9BF54EA70E3A5C`, `21753` bytes, `90/93`. Its formal class already contains `virtual void OnPaint();` and closes before `[[CHILDREN]]`.
- Source-file snapshot: SHA256 `6D46EFD11BB7D7EF76DEFBA432E2619E074A272BB19A30AFB8DCE5FE75C4BA28`, `156919` bytes, `89/93`, established `NexusTK/social/` route.
- Dated validator-generated snapshot command `000000021178`, timestamp `2026-08-05T16:08:27-04:00`: tracker SHA256 `B64B3A40679BA9723FB24D2EEB552D21B557931CA3B1D0DE8986AE6824DFC2A1`; `Chatting.cpp` SHA256 `DE1AF4D957F21FFC24AEEF7F694202B1CFD4522D581AF969E7370CB258D18911`; `Chatting.h` SHA256 `08A8DCA02FB74DBE080A0E49AF10AE6DB7370F68564AEDDDBDE06E00C91D7903`. UID0002FD was `86/91`, reconstructable true, report counts `0/0/0`, with one CPP empty-emitter marker and no H declaration/marker.
- Dated initial manual coverage snapshots were read, not edited: by-memory SHA256 `3AC4ACAB647FCF67C0E6FEFDA3E7ECEB9760ED0CEFA9A320E14DB9B933AC36C7`; by-class SHA256 `E0D22C4A79C5DAAA9F80727997C6CE16DA8AFA38DB4C12F124397AFC6E6976B2`; by-file SHA256 `AB5A6B8C16A046E0D0792BA060D0B8391224F5FF823E744CCB3701B48A122500`. These are historical research snapshots, not permanent edit preconditions.
- Fresh report-only manual handoff snapshot at `2026-08-05T21:07:13-04:00`: by-memory SHA256 `B04639D5DEB863202A9B08B3150E7EE861418FED185AD6FB4721BCF5F575B445`; by-class SHA256 `6A3C3B2258F3F751C629B383D899E7E0A056F656B0004601822A0838D4093469`; by-file SHA256 `30D50E279B2B9D4F92DCCAAD1E7425140D58822A4FAB70AF8BD65C17FCC47AE5`; by-global SHA256 `C4935BAA37405B05ADBB91E00C63DE5754691703402A6E66886324C7EB11CE14`. These hashes and line anchors are dated no-clobber evidence; the supervisor must reread them immediately before manual application.
- Matching old reports were searched by UID, address, method name, class name, and helper address. They were used only as lead/history. Current binary and current by-* evidence supersede the old claim that helper `0x004b9670` is a display-mode setter and the old claim that formal dependencies require blank C++.
- Dated B006 implementation readback at `2026-08-05T21:57:26-04:00` confirmed the five changed destinations after scoped validation: target SHA256 `074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43`, `19523` bytes, `94/94`; class SHA256 `A23D1A57B84D712664A4BEC65F89E0D41AD83C589C09561F00696079B3A22020`, `25454` bytes, `90/93`; file SHA256 `122924E2E6A6D81DC23F31E97D74F895C7732776761606BA1064BC404A16B0D7`, `159874` bytes, `89/93`; UID0000QU SHA256 `12B1FDCB0EB961228D45CB02C17A6D3EFAA9892CD73001CCC4E5FB3AC047BE25`, `17235` bytes; UID0000BY SHA256 `4DA2DF570E5FFED3B1BE62B7D8BC386B878469B3ACAE5894C8388896626D5449`, `21791` bytes.
- Independent Gate 2A receipt readback at `2026-08-06T05:46:14-04:00` found the validators made no destination-byte change: target remained `074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43`, `19523` bytes, `94/94`; class remained `A23D1A57B84D712664A4BEC65F89E0D41AD83C589C09561F00696079B3A22020`, `25454` bytes; UID0000QU remained `12B1FDCB0EB961228D45CB02C17A6D3EFAA9892CD73001CCC4E5FB3AC047BE25`, `17235` bytes; and UID0000BY remained `4DA2DF570E5FFED3B1BE62B7D8BC386B878469B3ACAE5894C8388896626D5449`, `21791` bytes. UID0000I5 had already advanced before the rerun through disjoint accepted Chatting work to SHA256 `6F5FBD2D098C686A85908BBE41E01AB6C4924FD8FB600A0A4A5E0CF04806B4A0`, `162268` bytes; command `000000021477` preserved that exact identity and the accepted UID0002FD source-closure entry.
- Same-or-greater support readback required no edits: UID00006E `5CE72DD74DC55D7F0AF8C38CF5F294C1A627106B4BA6B57CB9C41D799880CFF4` contains one formal `typedef ImageLib ResourceLayoutTable`, one `extern ImageLib *g_pEPFLib`, and `LookupLayoutEntry`; UID0000FQ `9C325FBF0910ACD3A757EEA560CC9DC7CE6AE732951983A956837EBD4D14A33D` contains `int m_currentSayMode` at `+0x3eb4`; UID0000QK `3341473A64A33E4D9D206B799BE40810078C86C1ED30B3E5BAFBC6AD8A1C9290` independently records the `g_pUserPane` alias view and same field offset; UID000162 `6B5D6739EB8436DB939D9AFC71243996D974D9EB149FCFF6C3821CB959F76596` contains formal `SetTextBackFillColor`/`SetTextColor` and exact `+0x78/+0x7c` roles; UID0000XY `759B674505E1C022729AD03D7B5C958E0353D8239F526CA08236F6DB373E7232` preserves the 0x28 layout and initializer; UID0002RX `47F1496A491DF78C5586FE3315769B4B50BF1560E00BC170194CC38339DD5C83` contains the sole shared enum in formal H; UID0002XA `407E91D9DB30E8FD5777D632A7DD952927220BB8160B8980D57417A1ECEDB099` contains the sole source definition and exact seven-reference classification.
- Dated primary Gate 2B failure and rollback at `2026-08-06T07:19:00-04:00`: exact report SHA256 `140F5FC3C4A6F104D46AAF096BD26E002ACE7D7EAF3A20B195B86BEE705849D2` entered `GATE2B_FAILED_PRE_SAVE`. Closed canonical P0 was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `2F5594535B9730C2195466DC6673A6325B19E572D0DCCB9D054B0F6DFAC48D70`, size `143197685`, UTC mtime `2026-08-06T09:28:16.2969329Z`, ticks `639216052962969329`; collision-free backup `NexusTK.exe.i64.bak-UID0002FD-prestate-20260806T0656` matched P0 byte for byte and was not restored because no save occurred. Diagnostic worker `uid0002fd-diagnostic-202608060657`/PID `15068` was retired unsaved before P0/B0. Transaction worker `uid0002fd-transaction-202608060658`/PID `11540` completed I01/I02 in memory and reached only M03 in I03. The literal no-name `make_data` produced `[0x0067addc,0x0067ade0)`, size 4, data true, type `ChattingVarietySelectPane *`, unchanged zero bytes, and exactly one semantic names-index result `g_pChattingVarietySelectPane` at the same address, while physical `inspect_items.name` remained empty. That channel mismatch against the old A03 contract stopped the transaction before C03/I04/save; no Gate 2B credit was granted.
- Dated rollback proof for that attempt: the transaction worker was retired without save; its retained row was inactive and PID `11540` absent; exclusive `FileShare.None` read succeeded; disk remained exact P0. Fresh rollback verifier `uid0002fd-rollback-202608060716`/PID `12300` proved normalized xref aggregate `F8715CB1F4F0531829B3600EDF1B0B9BF3562E82F68346A2E4AFAFC3D6EAD16B` and full rollback aggregate `558F3F9E7E6FBC31628DD7E77F9C6D7A3CCD1DB8D0D6F71C5E11511C39FCF06B`, covering lookup, frames, function/data items, function/internal/data comments, bytes, types, and names. The verifier was retired unsaved; its retained row was inactive and PID `12300` absent; final exclusive read succeeded; disk again matched exact P0. These facts are dated failure/rollback evidence only and require fresh Gate 1 before another transaction.
- Dated primary Gate 2B failure and closed-disk proof at `2026-08-06T08:55:00-04:00`: accepted report SHA256 `605A4217966A43F2BBA9AF577357D607D7ED5F2C6A4EF6DCCA386DB03199A6F2` entered `GATE2B_FAILED_PRE_SAVE`. Closed P0 and byte-identical backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0002FD-prestate-20260806T0758` used canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `2F5594535B9730C2195466DC6673A6325B19E572D0DCCB9D054B0F6DFAC48D70`, size `143197685`, UTC mtime `2026-08-06T09:28:16.2969329Z`, ticks `639216052962969329`. Fresh transaction worker `uid0002fd-transaction-202608060758`/PID `6596` completed I01, N02, and R02 only in memory with their full packages. Literal T02a `set_type` with `ty:"unsigned int"` returned `ok:true`, but immediate authoritative `stack_frame` canonicalized `color@+0x8`, size 4, to exact physical type `unsigned __int32`. The old exact-`unsigned int` frame contract stopped execution before F02/C02/I03/I04/final package/save. PID `6596` was retired without save; its retained row became inactive, the PID was absent, literal exclusive `FileShare.None` read succeeded at exact length, and closed disk remained exact P0. No restore was needed, no mutation persisted, and no prior transaction action receives credit.
- Dated primary Gate 2B lookup-fallback failure and rollback on `2026-08-06`: exact report SHA256 `21D5CC73950E0012481C2CDA701E9E5DE36C23D842B811D70418FD3549DBD510` entered `GATE2B_FAILED_PRE_SAVE`. Exact P0/B0 remained SHA256 `2F5594535B9730C2195466DC6673A6325B19E572D0DCCB9D054B0F6DFAC48D70`, size `143197685`, UTC ticks `639216052962969329`. Transaction session `uid0002fd-transaction-202608061350`/PID `15604` passed prestate and performed only pure N01 in memory. Address readback returned physical `ChattingVarietyPane__OnPaint` at `0x00480e80`, while `lookup_funcs("sub_480E80")` resolved the same renamed function because the endpoint parses `sub_<hex-address>` as an address fallback; the old V00 contract incorrectly treated that query result as a surviving old physical name. The supervisor stopped before R01a and before save. PID `15604` retired unsaved; rollback session `uid0002fd-rollback-202608061407`/PID `11228` proved original names/prototypes/frames from exact P0 and also retired unsaved. Both retained rows were inactive, both PIDs absent, final `ER00` succeeded, and the final canonical disk remained exact P0. No mutation persisted and no Gate 2B action receives credit.
- Dated supervisor package-reopen at exact artifact SHA256 `0D2F8ACC53DB6F6073E5B9B5BD5DEC1D3FCC65AD4FC8966B1B41FD2E635AD8C2`: ordinary Gate 2A documentation evidence remains valid, but Gate 2B could not proceed because local installed-file hashes were not bound through the actual listener/process generation, B0 creation lacked literal collision-safe durable code, and restore prose retained a newly observed `R0` timestamp instead of restoring the complete original P0 tuple. This same-report additive repair supplies the literal listener/runtime/package chain, exclusive `FileMode.CreateNew` plus `Flush(true)` B0 package, explicit truncating plus `Flush(true)` restore, exact P0 `LastWriteTimeUtc` restoration, and twice-read complete P0 tuples. No IDA mutation/save, by-* edit, validator, or lifecycle credit follows from the repair itself.

## Target

- Primary target: [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md).
- Exact executable body: `[0x00480e80,0x00480ff1)`, `369` bytes / `0x171`.
- Exact target-body SHA256: `51D838D5125C26AC11DAA7357271B5BD6CC20884638CE1EC66560862E0F60679`.
- Direct owner/emitter: [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md).
- Source route: [UID:0000I5][Chatting](by-file/Chatting.md), `NexusTK/social/Chatting.cpp`.
- The accepted ordinary callback now covers the parent class, Chatting file, and UID0000QU/UID0000BY resource-contract prose. Shared GrafPort, EPFTileContext, UID0000FQ UserPane, UID0000QK global-alias support, UID00006E formal ImageLib source, UID0002RX `SayInputPanes.h`, and UID0002XA singleton pages passed same-or-greater readback and were not duplicated or edited.

## Current Target State

- Physical callback readback is `COMPLETION:94`, `CONFIDENCE:94`, `CANONICAL_OWNER:00001Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Y`; formal CPP contains exactly the accepted method body and formal H remains blank for the two documented ownership reasons.
- The Item Summary, Behavior, exact-call, stack/layout, reachability, resource, ownership, source-placement, rejected-alternative, open-question, history, attachment, and change sections now carry the accepted report-level detail. The old display-mode/background/shadow/blank-C++ statements survive only as explicitly superseded history.
- The target remains one unsplit authored method with the exact vtable-only route, protected literals, source-level five-case invariant, borrowed-context lifetime, and external 15-byte fence.
- The parent class is source-closed at `90/93` and already declares `OnPaint`; the source file is established at `89/93`. No owner, emitter, split, class-surface, or support-score gate blocks method emission.
- Generated CPP/H and tracker truth were not refreshed by B006. Original callback commands `000000021289` through `000000021293` and independent receipt commands `000000021475` through `000000021479` all reported `generated_refresh: deferred`; the latter five current receipts prove C2FD-042..044 and C2FD-065..066, while generated body/marker/header/tracker/compile assertions C2FD-045..047 and C2FD-052 remain primary-supervisor work and unchecked.

## Executive Recommendation

Implement the target as a human-written VC-era paint override, not a decompiler transcription. Preserve the exact resource/frame selection, uninitialized invalid-mode behavior, fixed 128-wide buffer, five bounded copies, inline-length semantics, text state, integer arithmetic, and two draw passes. Correct the shared GrafPort helper identity in both docs and IDA. Do not create a new helper, new file, duplicate class declaration, fallback label, cleanup call, or shadow-color state that the binary does not contain.

## Supervisor Active Recheck

- Confirm zero executable script packages, programs, launchers, hostile suites, or fixtures.
- Confirm all headings are substantive, formal C++ occurs only in its CPP section, and blank H is explicit.
- Confirm C2FD-001..066 appear once per ledger/checklist with exact Claim ID, Target UID, actor/authority, action, and verification-state parity; confirm each ledger claim/destination identity is represented by the corresponding checklist action/readback where applicable, with a 42 checked / 24 unchecked allocation.
- Confirm A01's complete current and protected reachability is exactly one inbound data xref `0x00614ee4 -> 0x00480e80` and zero ordinary code callers; only A01-NAME, A01-LOCAL-THIS, A01-LOCAL-CONTEXT, A01-LOCAL-TEXT, A01-TYPE, and A01-COMMENT may change their literal listed fields.
- Confirm A02's complete current and protected inbound-reference set is exactly 11 entries at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`; only A02-NAME, A02-LOCAL, A02-TYPE, and A02-COMMENT may change their literal listed fields, and any count, address, xref-kind, or other unlisted-prestate drift stops before mutation.
- Rebase every Section-21 row against fresh live pre-state. Any drift, collision, occupied extent, xref/type/comment mismatch, unrelated unsaved worker, or database-identity uncertainty stops the action.
- Supervisor alone owns MCP/IDA mutation, backup/save/readback, process handling, persistence, rollback, coverage, generated checks, execution, and archive movement.
- Former V1-V6 receipts are withdrawn. No current claim depends on them.

## Inference Research Guidance Check

- Binary facts and source inference are separated. Range, bytes, xrefs, field offsets, call order, arguments, labels, stack extent, branch behavior, and vtable cell are direct evidence.
- `ChattingVarietyPane::OnPaint`, `SetTextBackFillColor`, `m_currentSayMode`, local names, and source formatting are evidence-ranked human source inferences supported by current subsystem conventions and accepted docs. `SayInputMode` is stronger than a target-local inference: UID0002RX already owns its exact five-value formal declaration in `SayInputPanes.h`.
- No finalized recommendation uses `sub_`, `dword_`, `off_`, raw offsets, decompiler temporaries, or synthetic reverse-engineering wrappers.
- Behavior replication outranks naming/style. Human-looking source is next; project/subsystem style consistency is a lower priority. The recommendation therefore preserves the binary's invalid-mode undefined behavior instead of adding a safer but non-equivalent fallback.
- Wave2/Wave3 material was ignored as stale workflow/source evidence.

## Heuristic / Inference Reanalysis And Validation

1. **Receiver/class inference:** the sole inbound xref is the `ChattingVarietyPane` primary-vtable slot at `0x00614ee4`; sibling slots and the current parent declaration establish the source override `ChattingVarietyPane::OnPaint`.
2. **Helper inference:** helper bytes write the argument to receiver `+0x78`. Current `GrafPort` UDT names that exact field `m_textBackFillColor`; sibling `0x004b9680` is already `GrafPort_SetTextColor` over `+0x7c`. The old display-mode/background-color interpretation is rejected.
3. **Popup/frame inference:** `g_pChattingVarietySelectPane != NULL` is passed as the layout frame index. Seven exact singleton refs tie the value to selector creation/destruction and this paint consumer. Frame 1 therefore means the selector popup exists; frame 0 means it does not.
4. **Mode-field inference:** current `UserPane` UDT places `int m_currentSayMode` at `+0x3eb4`. Selector click logic writes values 0..4, and the independent input dispatcher uses the same default/shout/whisper/group/clan enum vocabulary.
5. **Text-effect inference:** no state-changing call occurs between the two draw passes. Calling them distinct-color shadow/foreground is unsupported. A same-state one-pixel double-strike/overdraw is the exact defensible description.
6. **Lifetime inference:** the stack `EPFTileContext` is initialized and used as a borrowed resource view. No allocation, release, destructor, or EH cleanup appears. Adding RAII destruction or `ReleaseBuffers` would change behavior.
7. **Invalid-mode inference:** cases 0..4 initialize the local buffer; no default path does. Source must retain this invariant/undefined behavior rather than inventing `Talk`, empty text, or early return for out-of-range state.
8. **Source-file inference:** the method is a class child, shares Chatting globals/resources and adjacent methods, and has no cross-file helper body. `social/Chatting.cpp` remains stronger than GrafPort, ImageLib, UserPane, or a new one-method source file. Consuming `SayInputMode` from `SayInputPanes.h` is a normal shared-header dependency and does not move the method out of Chatting.

## Evidence Standards Used

- Highest weight: live IDA MCP function/type/frame/item/comment/xref/byte facts and exact current by-* formal source.
- Strong corroboration: vtable order, sibling method behavior, accepted UserPane and GrafPort layouts, singleton reference graph, and resource-string xrefs.
- Medium weight: project naming conventions and likely VC-era expression shape. The `SayInputMode` ownership evidence is stronger because its exact declaration already emits through UID0002RX into `SayInputPanes.h` and is consumed by existing Chatting source.
- Historical reports and generated C++ are leads only. No score or source decision relies on an old report without current corroboration.
- Negative evidence is affirmative where bounded: no ordinary callers, no cleanup call, no draw-mode write, no color-state change between passes, no default branch, no second function body, and no range overlap.

## Evidence Checked

- Target bytes, function extent, 15-byte fence, successor, frame, decompilation, calls, strings, vtable slot, and inbound xrefs.
- Helper bytes/callers at 0x004b9670 and 0x004b9680; GrafPort layout/formal accessors.
- UserPane, ChattingVarietyPane, Chatting, EPFTileContext, ImageLib, ResourceLayoutTable, g_pEPFLib, SayInputMode, and selector-global docs.
- Target/helper frame rows, prototypes, comments, singleton item, vtable bytes, adjacent items, xrefs, and name-collision observations in the dated live MCP evidence.
- Target/support metadata, formal CPP/H ownership, dated generated/tracker snapshots, original callback validators, and five independent validator receipts.
- Three dated Gate 2B attempts stopped before save and prove rollback/no persistence only.
- Superseded V1-V6 automation is failed history, not current evidence.

## Claim And Incorporation Ledger

Controlled ledger retains C2FD-001..066. Its checklist parity contract covers Claim ID, Target UID, actor/authority, action, and verification state, while each ledger claim and destination doc/section must remain identifiable in the corresponding checklist action/readback where represented. Executable-package claims are withdrawn; IDA credit is only the pending A01-A04 supervisor handoff.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Actor / authority | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C2FD-001 | 0002FD | Exact source body is `[0x00480e80,0x00480ff1)`, 369 bytes, hash `51D838...0679`. | Exact | MCP function/bytes | target / Status, Boundary, Evidence | B006 implementation callback | incorporate | applied |
| C2FD-002 | 0002FD | `[0x00480ff1,0x00481000)` is fifteen `0xcc` bytes outside target; successor begins `0x00481000`. | Exact | MCP bytes/function | target / Boundary And Padding | B006 implementation callback | incorporate | applied |
| C2FD-003 | 0002FD | Only inbound target xref is vtable data slot `0x00614ee4`; there are no ordinary callers. | Exact | analyze/xref | target / Reachability | B006 implementation callback | incorporate | applied |
| C2FD-004 | 0002FD | Source identity is `ChattingVarietyPane::OnPaint` under UID00001Y/UID0000I5. | Very strong | vtable, class, source route | target / Status, Ownership | B006 implementation callback | incorporate | applied |
| C2FD-005 | 0002FD | Stack `EPFTileContext` is initialized once as a borrowed render view. | Exact | body/frame/callees | target / Behavior, Lifetime | B006 implementation callback | incorporate | applied |
| C2FD-006 | 0002FD | `0x004b9670` is `SetTextBackFillColor(0)` over GrafPort `+0x78`, not draw mode. | Very strong | helper bytes, UDT, support | target and class / Paint dependency | B006 implementation callback | incorporate | applied |
| C2FD-007 | 0002FD | `g_pChattingVarietySelectPane != NULL` selects CHATVAR frame 1; null selects frame 0. | Very strong | argument and 7-ref lifecycle | target / Behavior | B006 implementation callback | incorporate | applied |
| C2FD-008 | 0002FD | Assets are exactly `CHATVAR.EPF` and `CHATVAR.PAL`, each with sole target ref. | Exact | bytes/xrefs | target / Resources | B006 implementation callback | incorporate | applied |
| C2FD-009 | 0002FD | Render call uses context, context bounds, pane visible bounds, mode 0, palette, null options. | Exact | dated diagnostic decompile/arguments corroborated by exact body bytes and call targets; no transaction-prestate credit | target / Render Call | B006 implementation callback | incorporate | applied |
| C2FD-010 | 0002FD | Mode source is `g_pUserPane->m_currentSayMode` at `+0x3eb4`. | Very strong | current UDT and body | target/class/file / State | B006 implementation callback | incorporate | applied |
| C2FD-011 | 0002FD | Values 0..4 map to Talk/Shout/Whisper/Group/Clan. | Exact | branches, literals, selector | target / Mode Mapping | B006 implementation callback | incorporate | applied |
| C2FD-012 | 0002FD | No default branch exists; invalid modes leave `modeText` uninitialized. | Exact | control flow | target / Invariant | B006 implementation callback | incorporate | applied |
| C2FD-013 | 0002FD | Each label uses bounded `wcscpy_s(...,128,...)`; the following scan is source `wcslen`. | Very strong | calls/inline scan | target / Text Preparation | B006 implementation callback | incorporate | applied |
| C2FD-014 | 0002FD | `SetTextColor(128)` writes GrafPort `+0x7c` before text drawing. | Exact | call, sibling type/frame | target / Text State | B006 implementation callback | incorporate | applied |
| C2FD-015 | 0002FD | Coordinates are exact integer expressions: center minus half six-pixel estimate minus 2; bottom minus 6. | Exact | arithmetic | target / Positioning | B006 implementation callback | incorporate | applied |
| C2FD-016 | 0002FD | Text is double-struck with identical state at `(x+1,y)` then `(x,y)`, not distinct colors. | Exact | no intervening state call | target / Draw Passes | B006 implementation callback | incorporate | applied |
| C2FD-017 | 0002FD | No local release/destructor/EH cleanup exists; do not add one. | Exact | callee/body/frame | target / Lifetime | B006 implementation callback | incorporate | applied |
| C2FD-018 | 0002FD | Insert the report's exact method-only first-draft C++ in formal CPP; consume, but do not redeclare, UID0002RX's shared `SayInputMode`. | Strong | full reconstruction plus accepted shared-header route | target / RECONSTRUCTION_CPP CODE | B006 implementation callback | incorporate | applied |
| C2FD-019 | 0002FD | Keep formal H blank because the parent already declares `virtual void OnPaint();` and UID0002RX separately owns the shared enum in `SayInputPanes.h`. | Exact | parent formal source plus UID0002RX formal H | target / RECONSTRUCTION_H CODE | B006 implementation callback | not-applicable | applied |
| C2FD-020 | 0002FD | Raise target to `94/94`. | Strong | blocker closure and source readiness | target / metadata | B006 implementation callback | incorporate | applied |
| C2FD-021 | 0002FD | Preserve owner/emitter/reconstructable route `00001Y/00001Y/TRUE`. | Very strong | class/vtable/source route | target / metadata | B006 implementation callback | already-present | already-present |
| C2FD-022 | 0002FD | Replace stale target summary/behavior/open questions with corrected full detail. | Very strong | current contradictions | target / prose | B006 implementation callback | incorporate | applied |
| C2FD-023 | 0002FD | Retain old display-mode/blank-C++ claims only as corrected historical assumptions. | Very strong | current support closure | target / Historical Assumptions | B006 implementation callback | historicalize | applied |
| C2FD-024 | 00001Y | Correct parent paint dependency and strengthen exact OnPaint role; keep `90/93`. | Very strong | target and GrafPort facts | class / Method Notes, Evidence | B006 implementation callback | incorporate | applied |
| C2FD-025 | 0000I5 | Add detailed OnPaint source-closure entry, including its established `SayInputPanes.h` enum dependency; keep source path and `89/93`. | Strong | ownership/source inventory and UID0002RX formal H | file / Source Closure | B006 implementation callback | incorporate | applied |
| C2FD-026 | 000162 | GrafPort accessor page already formalizes `SetTextBackFillColor` and `SetTextColor`. | Exact | support readback | GrafPort support | B006 implementation callback | already-present | already-present |
| C2FD-027 | 0000FQ | UID0000FQ UserPane formally emits `int m_currentSayMode` at `+0x3eb4`; UID0000QK independently corroborates the `g_pUserPane`/`g_pCollectionData` global-alias view and the same offset. | Exact | class formal/type readback plus global-alias support | UserPane and global-alias support | B006 implementation callback | already-present | already-present |
| C2FD-028 | 0000XY | EPFTileContext already formalizes the 0x28 layout and `Initialize`. | Exact | support/type readback | EPFTileContext support | B006 implementation callback | already-present | already-present |
| C2FD-029 | 00006E | Reconcile support prose to the accepted source contract: UID00006E `ImageLib` owns non-virtual `LookupLayoutEntry`, `typedef ImageLib ResourceLayoutTable` is the compatibility alias, and `extern ImageLib *g_pEPFLib` is the sole source-facing global declaration; UID0000QU/UID0000BY retain storage, lifetime, method-history, and rejected-independent-type evidence. | Very strong | UID00006E formal source, UID0000QU implemented C2E6-091 disposition, UID0000BY no-independent-object evidence | ImageLib/global/compatibility-facet support | B006 implementation callback | incorporate | applied |
| C2FD-030 | 0002XA | Semantic selector global already has one source definition and seven-ref proof. | Exact | global page and MCP | singleton support | B006 implementation callback | already-present | already-present |
| C2FD-031 | 0002FD | Retain only the A01-NAME, A01-LOCAL-THIS, A01-LOCAL-CONTEXT, A01-LOCAL-TEXT, A01-TYPE, and A01-COMMENT outcomes; preserve exactly one inbound data xref `0x00614ee4 -> 0x00480e80`, zero ordinary code callers, the approved physical frame deltas, and every unlisted name/type/comment/body/range state. | High | body/frame/pre-state/class ownership and current endpoint contracts | Canonical IDB / A01 | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-032 | 0002FD | Require the complete A01 physical frame readback: `thisPane` `ChattingVarietyPane *` at `+0xc`, `tileContext` `EPFTileContext` at `+0x10`, `modeText` `wchar_t[128]` at `+0x38..+0x138`, with every unlisted row and byte unchanged. | High | occupied frame/body/readback and narrow stack schemas | Canonical IDB / A01 frame | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-033 | 000162 | Retain only the A02-NAME, A02-LOCAL, A02-TYPE, and A02-COMMENT outcomes; preserve the exact 11 inbound references at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`, the 13-byte body, three-row frame, physical `unsigned __int32` normalization, and every unlisted state. | High | exact 11-reference set/helper/callers/GrafPort/frame/prototype and current endpoint contracts | Canonical IDB / A02 | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-034 | 0002XA | Normalize `0x0067addc` to one four-byte data item of type `ChattingVarietySelectPane *` with an empty physical item name; set only the address-regular comment to `ChattingVarietySelectPane singleton. Non-null selects CHATVAR.EPF frame 1 in ChattingVarietyPane::OnPaint; null selects frame 0.` Preserve four zero bytes, seven refs, adjacent heads, one semantic same-address name, and all other analysis state. | High | item/global/bytes/xrefs, demonstrated no-name endpoint behavior, and current schemas | Canonical IDB / A03 | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-035 | 00001Y | Set only the address-regular comment at `0x00614ee4` to `ChattingVarietyPane primary-vtable OnPaint slot -> ChattingVarietyPane__OnPaint (0x00480e80).` Preserve repeatable-comment absence, slot value, target ref, item bounds, bytes, and adjacent slots. | High | exact slot/body and narrow address-comment endpoint | Canonical IDB / A04 | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-036 | 0002FD | Protect every unlisted function/frame/prototype/comment/item/name/string/byte/xref/UDT/adjacent global or slot; permit only the listed A01-A04 deltas, including A01's one-data-xref/zero-code-caller state and A02's literal 11-reference set; no unrelated cache, analysis, naming, typing, comment, body, range, or item effect is accepted. | Exact | complete pre-state, endpoint implementation, and no-change contract | Canonical IDB / protections | Primary supervisor Gate 2B | already-present | proposed |
| C2FD-037 | 0002FD | Treat all dated session, path, schema, and endpoint evidence as non-authoritative history. Credit requires independent confirmation that each literal entity prestate and expected physical readback remains exact; any mismatch rejects the affected outcome rather than authorizing adaptation. | Exact | Section-21 endpoint binding/table/no-change state | Canonical IDB / collision/readback | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-038 | 0002FD | Grant IDA credit only after independent physical readback proves every accepted Section 21 outcome and protected no-change state. Report text and the inert removed companion grant no mutation or persistence credit. | Exact | literal Section-21 handoff, dated live evidence, no-save histories, direct verification requirement | Canonical IDB / Gate 2B | Primary supervisor Gate 2B | incorporate | proposed |
| C2FD-039 | 0002FD | Replace stale manual by-memory coverage row with exact 94% source-ready text. | Very strong | current row comparison | by-memory/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-040 | 00001Y | Replace manual class row with exact strengthened OnPaint text, score 90 unchanged. | Strong | current row comparison | by-class/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-041 | 0000I5 | Current manual file row remains semantically valid; no replacement is required. | Strong | current row comparison | by-file/-coverage-report.md | Primary supervisor manual coverage | already-present | proposed |
| C2FD-042 | 0002FD | Independent scoped target receipt command `000000021475` exited `0`, returned literal `ok: 1`, scanned exactly one file, and deferred generated refresh; physical readback remained `94/94` at SHA256 `074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43`. | Exact | command `000000021475`, `2026-08-06T05:45:36-04:00`, full receipt below | target validator | B006 implementation callback | incorporate | applied |
| C2FD-043 | 00001Y | Independent scoped class receipt command `000000021476` exited `0`, returned literal `ok: 1`, scanned exactly one file, and deferred generated refresh; destination remained SHA256 `A23D1A57B84D712664A4BEC65F89E0D41AD83C589C09561F00696079B3A22020`. | Exact | command `000000021476`, `2026-08-06T05:45:44-04:00`, full receipt below | class validator | B006 implementation callback | incorporate | applied |
| C2FD-044 | 0000I5 | Independent scoped file receipt command `000000021477` exited `0`, returned literal `ok: 1`, scanned exactly one file, and deferred generated refresh; it preserved pre-rerun concurrent Chatting SHA256 `6F5FBD2D098C686A85908BBE41E01AB6C4924FD8FB600A0A4A5E0CF04806B4A0` and the accepted UID0002FD source-closure detail. | Exact | command `000000021477`, `2026-08-06T05:45:56-04:00`, full receipt below | file validator | B006 implementation callback | incorporate | applied |
| C2FD-045 | 0002FD | Generated Chatting.cpp must contain one target body and zero UID0002FD empty markers. | Exact | emitter contract | generated Chatting.cpp | Primary supervisor validator/generated | incorporate | proposed |
| C2FD-046 | 0002FD | Generated Chatting.h must not gain a duplicate UID0002FD OnPaint declaration. | Exact | parent declaration route | generated Chatting.h | Primary supervisor validator/generated | already-present | proposed |
| C2FD-047 | 0002FD | Dynamically reread tracker row/counts after supervisor lifecycle; no fixed tracker hash is permanent. | Exact | lifecycle-sensitive tracker | research tracker | Primary supervisor validator/generated | incorporate | proposed |
| C2FD-048 | 0002FD | Preserve matching old reports only as historical leads superseded where contradicted. | Strong | old/current comparison | target / History | B006 implementation callback | historicalize | applied |
| C2FD-049 | 0002FD | Protect all CHATVAR and mode-label literal items; emit source literals, not data objects. | Exact | bytes/xrefs | target / Resources | B006 implementation callback | incorporate | applied |
| C2FD-050 | 0002FD | Keep target range unsplit and keep 15-byte padding outside it. | Exact | body/fence/successor | target / Range | B006 implementation callback | already-present | already-present |
| C2FD-051 | 0002FD | Reject GrafPort/ImageLib/UserPane/new-file/no-owner ownership alternatives. | Very strong | dependency direction | target / Ownership | B006 implementation callback | incorporate | applied |
| C2FD-052 | 0002FD | Verify x86 MSVC compilation with `SayInputPanes.h` visible to `Chatting.cpp`, exactly one `SayInputMode` definition in generated `SayInputPanes.h`, zero enum definitions in generated `Chatting.cpp`/`Chatting.h`, one UID0002FD method body, and no duplicate target H declaration. | Strong | exact shared-header/source dependency closure | generated compile and uniqueness checks | Primary supervisor validator/generated | incorporate | proposed |
| C2FD-053 | 0002FD | During the dated initial report-only phase B006 changed only this report and no external target/support file; the later supervisor-authorized callback changed exactly the five destinations separately recorded in Changed Files. | Exact | dated phase boundary and callback hashes | report / Changed Files | B006 report/callback history | historicalize | applied |
| C2FD-054 | 0002FD | During the dated initial report-only phase B006 ran no validator, IDA mutation/save, coverage edit, or lifecycle command; during the later callback B006 ran scoped validators `000000021289` through `000000021293`, and during this Gate 2A receipt repair reran the same five file scopes as `000000021475` through `000000021479`. Both validator sets deferred generated refresh, and B006 still performed no IDA, manual coverage, lifecycle, execution, or movement action. | Exact | dated phase boundary, five callback receipts, and five independent Gate 2A receipts | report / Validator Results | B006 report/callback history | historicalize | applied |
| C2FD-055 | 0002FD | Third-party source import is not applicable to this project method. | Exact | target provenance | target / Source Disposition | B006 implementation callback | not-applicable | applied |
| C2FD-056 | 000162 | Replace stale manual GrafPort accessor row with current 89% formal-source detail. | Exact | current row/support comparison | by-memory/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-057 | 0000XY | Replace stale manual EPFTileContext aggregate row with current 88% child-placement detail. | Exact | current row/support comparison | by-memory/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-058 | 00006E | Correct stale manual ImageLib score/confidence tokens while preserving the complete current row. | Exact | current row/support comparison | by-class/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-059 | 0000QK | Replace stale manual UserPane-global alias row with current 89% canonical g_pUserPane detail. | Exact | current row/support comparison | by-global/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-060 | 0000QU | Replace stale manual g_pEPFLib row with the accepted ImageLib/ResourceLayoutTable source contract. | Exact | current row/support comparison | by-global/-coverage-report.md | Primary supervisor manual coverage | incorporate | proposed |
| C2FD-061 | 0000BY | Current manual ResourceLayoutTable row already preserves the accepted compatibility-facet contract. | Exact | current row/support comparison | by-class/-coverage-report.md | Primary supervisor manual coverage | already-present | proposed |
| C2FD-062 | 0000FQ | Current manual UserPane row already preserves the complete declaration and integer say-mode field split. | Exact | current row/support comparison | by-class/-coverage-report.md | Primary supervisor manual coverage | already-present | proposed |
| C2FD-063 | 0002RX | Current manual say-input dispatcher row already preserves source-ready shared-header evidence. | Exact | current row/support comparison | by-memory/-coverage-report.md | Primary supervisor manual coverage | already-present | proposed |
| C2FD-064 | 0002XA | Current manual selector-global row already preserves storage, seven-ref lifecycle, and sole-definition evidence. | Exact | current row/support comparison | by-global/-coverage-report.md | Primary supervisor manual coverage | already-present | proposed |
| C2FD-065 | 0000QU | Independent scoped g_pEPFLib receipt command `000000021478` exited `0`, returned literal `ok: 1`, scanned exactly one file, recorded one current stats-row update, and deferred generated refresh; destination remained SHA256 `12B1FDCB0EB961228D45CB02C17A6D3EFAA9892CD73001CCC4E5FB3AC047BE25`. | Exact | command `000000021478`, `2026-08-06T05:46:04-04:00`, full receipt below | UID0000QU global validator | B006 implementation callback | incorporate | applied |
| C2FD-066 | 0000BY | Independent scoped ResourceLayoutTable receipt command `000000021479` exited `0`, returned literal `ok: 1`, scanned exactly one file, and deferred generated refresh; destination remained SHA256 `4DA2DF570E5FFED3B1BE62B7D8BC386B878469B3ACAE5894C8388896626D5449`. | Exact | command `000000021479`, `2026-08-06T05:46:14-04:00`, full receipt below | UID0000BY class validator | B006 implementation callback | incorporate | applied |

- Exactly 66 unique rows; actor/action/state mirror the checklist.
- C2FD-031..038 remain supervisor-owned proposed rows.

## Positive Evidence Summary

- Exact function boundary, body bytes, vtable slot, and successor fence are closed.
- Exact helper/callee sequence and arguments are closed.
- Current UDTs resolve the three former raw-offset blockers: GrafPort `+0x78/+0x7c`, UserPane `+0x3eb4`, and EPFTileContext's 0x28 layout.
- The selector singleton has a canonical source definition, exact type, and seven-reference lifecycle.
- Resource names and five mode labels are literal binary data with direct target references.
- Parent class and source file already satisfy owner/emitter and declaration routing.
- A behaviorally exact, human-looking CPP body is possible without raw labels or synthetic wrappers.

## IDA MCP Facts

- Target: `sub_480E80`, declaration `void __thiscall(GrafPort *this)`, size `369`, 17 basic blocks, cyclomatic complexity 8, zero ordinary callers, one data xref from `0x00614ee4`.
- Target callees at the dated IDA layer are `EPFTileContext_Initialize`, `sub_4B9670`, `ResourceLayoutTable_LookupLayoutEntry`, `GrafPort_RenderTileFrame`, `_wcscpy_s`, `GrafPort_SetTextColor`, `GrafPort_MoveTo`, `GrafPort_DrawWideText`, and security-cookie check. The `ResourceLayoutTable` spelling is retained here as exact current IDA provenance; accepted human source exposes the same non-virtual method through `ImageLib` with a compatibility typedef. The length scan is inline source `wcslen`.
- Target frame: `var_130@+0xc GrafPort *`, `outContext@+0x10 EPFTileContext` size 0x28, `Destination@+0x38 wchar_t` with proven 128-element extent to `+0x138`, `var_4@+0x138`, saved registers `+0x13c`, return address `+0x140`.
- Helper: `sub_4B9670`, `[0x004b9670,0x004b967d)`, declaration `int __thiscall(_DWORD *this, int)`, one block, no callees, exactly 11 inbound code refs enumerated below, bytes `55 8B EC 8B 45 08 89 41 78 5D C2 04 00`, SHA256 `424C9648B41BCB43DAA854D6F6F0C9B6F5080BACB242A564E2F6C7117AA8678A`.
- GrafPort UDT is size 0xa0. Relevant exact fields are `m_visibleBounds@+0x44`, `m_currentY@+0x68`, `m_currentX@+0x6c`, `m_drawMode@+0x70`, `m_drawColor@+0x74`, `m_textBackFillColor@+0x78`, `m_textColor@+0x7c`, `m_textBackColor@+0x80`.
- UserPane UDT is size `0x13eb84`; `m_currentSayMode` is `int` at `+0x3eb4`.
- `0x0067addc` currently renders as a one-byte non-data item with semantic type `ChattingVarietySelectPane *`, while the names index has exactly one `g_pChattingVarietySelectPane` alias at that same address. Twelve bytes from `0x0067add8` are zero.
- Exact singleton refs: `0x480d7f`, `0x480dc2`, `0x480dc9`, `0x480eb2`, `0x481115`, `0x48119d`, `0x483e04`.
- Vtable bytes `[0x00614edc,0x00614ef8)` hash to `6124E27DA4C22BE493FFBB7C259FB40AACFCFABAE41F6BE3AB2143E49539EEE2`; `0x00614ee4 -> 0x00480e80`, `0x00614ee8 -> 0x00481000`.
- Resource/label band `[0x00615334,0x006153a8)` is 116 bytes, SHA256 `D56314BDC56B2F809CCF789D01EFFDB75D138D1CA10B8F2804545F0F56B811ED`, and contains `CHATVAR.EPF`, `CHATVAR.PAL`, `Talk`, `Shout`, `Whisper`, `Group`, and `Clan`.

## Function / Child Inventory

| Range/entity | Current identity | Source role | Disposition |
| --- | --- | --- | --- |
| `0x00480e80-0x00480ff1` | `sub_480E80` | `ChattingVarietyPane::OnPaint` | Target source body; emit exact CPP. |
| `0x00480ff1-0x00481000` | no function, 15 `0xcc` | alignment fence | Outside target; protect, do not emit. |
| `0x00481000-0x0048100a` | `sub_481000` | secondary forwarder | Separate UID0002FE compiler-generated child. |
| `0x004b9670-0x004b967d` | `sub_4B9670` | `GrafPort::SetTextBackFillColor` | Shared support helper; rename/type/comment in IDA, no duplicate body in target. |
| `0x004b9680-0x004b968d` | `GrafPort_SetTextColor` | `GrafPort::SetTextColor` | Existing shared dependency; no action. |
| `0x00614ee4` | unnamed dword | primary-vtable `OnPaint` slot | Comment-only IDA action. |
| `0x0067addc` | malformed physical item plus semantic alias | selector singleton pointer | Normalize physical data item; source definition already owned by UID0002XA. |

## Direct Xref / Caller Inventory

- Target has exactly one inbound reference: data xref `0x00614ee4 -> 0x00480e80`. There are no direct code callers. This is normal virtual reachability, not dead-code evidence.
- Helper `0x004b9670` has exactly 11 inbound code refs at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`. Broad caller diversity rejects Chatting ownership for the helper.
- Selector global has seven refs listed in IDA MCP Facts. Four concern this compact/selector family directly; the remaining lifecycle writes are constructor/destructor/compiler-wrapper evidence.
- `g_pEPFLib` has 231 refs and `g_pUserPane` has 505 refs. They are broad shared globals, not target-owned storage.
- `CHATVAR.EPF` at `0x00615334` and `CHATVAR.PAL` at `0x0061534c` each have one direct target data ref.

## Documentation Evidence And IDA Status

- Ordinary documentation callback is complete at 94/94 with corrected helper/color/double-strike behavior, exact method-only CPP, and blank-H rationale.
- UID000162 formalizes the two color accessors; UID0000FQ/UID0000QK support m_currentSayMode +0x3eb4; UID0000XY supports EPFTileContext.
- UID00006E owns ImageLib, LookupLayoutEntry, ResourceLayoutTable alias, and extern ImageLib *g_pEPFLib; UID0000QU owns storage/lifetime and UID0000BY preserves compatibility history.
- UID0002XA owns the sole selector-global definition and seven-reference lifecycle.
- IDB source-facing identities, selected frame/prototype refinements, singleton normalization, and two regular comments remain pending supervisor actions in Section 21. B006 did not apply or save them.
- Script packages, fixtures, counters, process observations, and report-local receipts are not current IDA evidence.

## Ranked Ownership Analysis

1. **UID00001Y ChattingVarietyPane / UID0000I5 Chatting - accepted.** Vtable slot, receiver fields, adjacent class methods, resources, singleton interactions, and established emitter route all converge.
2. **UID00005V/UID0000JR GrafPort - dependency only.** The target calls inherited/shared GrafPort methods, but its vtable identity and chat-specific state/resources reject GrafPort method ownership.
3. **ImageLib with ResourceLayout compatibility alias - dependency only.** UID00006E supplies the accepted lookup/global source contract; UID0000BY remains a compatibility-facet history rather than an independent object. Neither owns pane state, vtable slot, label selection, or draw positions.
4. **UserPane - dependency only.** It owns the selected mode field, not the paint receiver or source body.
5. **ChattingVarietySelectPane - state dependency only.** Its singleton selects the frame; the target belongs to the compact parent pane.
6. **New file/free helper/no canonical owner - rejected.** Class-vtable identity and established Chatting source closure make these weaker and unnecessarily decompiler-shaped.

## Source Placement

The superseding report format does not alter ordinary source placement: UID0002FD remains a `Chatting.cpp` child emitted through UID00001Y. IDA recommendations are supervisor-owned implementation handoffs and never source owners, emitters, generated-source containers, or reasons to change the accepted `94/94` route.

- Place only the method definition in the target's formal CPP under the existing `NexusTK/social/Chatting.cpp` route. Do not duplicate the shared `SayInputMode` declaration in this CPP.
- Keep the method declaration in the parent class's existing formal class block; target H remains blank to avoid that duplicate. Keep the enum in UID0002RX's existing `SayInputPanes.h` formal H route, so the target H also does not duplicate shared-header ownership.
- Keep shared GrafPort method definitions in GrafPort source, EPFTileContext in its source, the accepted ImageLib lookup/global declaration in ImageLib source/header, the ResourceLayout compatibility alias/facet history in its support docs, the UID0000FQ field/type in UserPane source/header, and the singleton definition in the current Chatting source global page.
- No new source file, static helper, wrapper, import directive, or child emitter is justified.

## Range / Split / Padding / Reclassification Analysis

- The exact target range is one complete modeled function. It neither includes the preceding mouse handler nor the following padding/forwarder.
- The 15-byte `0xcc` fence begins exactly at the function's half-open end and remains represented by the existing ignored padding child.
- The successor at `0x00481000` is a distinct compiler forwarder and must not be merged into this authored body.
- Helper `0x004b9670`, vtable data, singleton storage, and literal data remain separate shared entities. No split or range expansion is required.
- Reclassification from reconstructable/source-authored to compiler-only, covered-by, or non-emitting is rejected because the body contains the unique authored paint behavior.

## Negative Evidence Summary

- No ordinary code caller exists; the vtable reference fully explains reachability.
- No call or write sets draw mode inside this function.
- No state-changing call occurs between text passes; separate shadow/foreground colors are unsupported.
- No default mode branch exists.
- No `EPFTileContext` release/destructor/EH cleanup exists.
- No helper body belongs under Chatting; helper has 11 broad refs and a direct GrafPort field store.
- No proposed target/helper function name collision exists. The global semantic name exists exactly once at the same address and must be preserved, not treated as a collision.
- No boundary overlap, secondary body, third-party source, or source-file split pressure remains.

## IDA Rename / Type / Comment Recommendations

| Record | Declarative evidence / disposition |
| --- | --- |
| Archive | Exact removed endpoint schemas, request objects, session tokens, action ordering, and transaction orchestration are preserved only in [0002FD-ChattingVarietyPaneOnPaint-source-quality-removed.md](./0002FD-ChattingVarietyPaneOnPaint-source-quality-removed.md); that companion is non-authoritative and must never be executed. |
| Scope | B006 performed read-only research. The supervisor owns any independent acceptance or rejection of the declarative outcomes and physical readbacks below; C2FD-031 through C2FD-038 remain supervisor-owned. |
| Historical format | Earlier revisions embedded V1-V6 PowerShell/C#/fixture transaction packages and recorded their parser, hostile, process, and recovery receipts. The superseding report-format rule removes those executable packages and withdraws every claim supported only by running them. Their existence, repeated Gate 1 failures, stopped encoded/unbounded runs, and dated pre-save Gate 2B rollback attempts remain historical process facts, but none is current acceptance evidence. Ordinary binary research, documentation callback evidence, formal C++, exact proposed IDA pre/post states, and the three dated no-persistence Gate 2B failures remain independently supported and retained. |

| Action ID | Exact entity/address | Literal current pre-state | Proposed action or disposition | Evidence | Safety constraints | Expected direct readback |
| --- | --- | --- | --- | --- | --- | --- |
| `A01-NAME` | Function `0x00480e80`, modeled `[0x00480e80,0x00480ff1)`, 369 bytes | Name `sub_480E80`; type `void __thiscall(GrafPort *this)`; body SHA256 `51D838D5125C26AC11DAA7357271B5BD6CC20884638CE1EC66560862E0F60679`; address regular/repeatable and function regular/repeatable comments all absent; exactly one inbound data xref `0x00614ee4 -> 0x00480e80`; zero ordinary code callers | Rename only to `ChattingVarietyPane__OnPaint` | Sole primary-vtable data xref `0x00614ee4 -> 0x00480e80`, zero ordinary code callers, exact class declaration, body behavior, and dated successful in-memory readback | Require zero proposed-name collision; pure function rename only; do not overwrite another entity; do not treat same-address `sub_<hex>` query fallback as a surviving old physical name; preserve body/range/comments and the exact one-data-xref/zero-code-caller state | Address, proposed-name, and old-token lookups resolve only `0x00480e80` with physical name `ChattingVarietyPane__OnPaint`; proposed names index is exactly one at this address; old exact names index remains zero; the sole inbound data xref remains `0x00614ee4 -> 0x00480e80`, with zero ordinary code callers |
| `A01-LOCAL-THIS` | Stack row in `0x00480e80` | `var_130@+0xc`, size 4, type `GrafPort *` | Rename to `thisPane`; set type `ChattingVarietyPane *` | Receiver use and primary-vtable ownership | Specialized stack edit only; preserve offset/size and every other frame row | `thisPane@+0xc`, size 4, type `ChattingVarietyPane *` |
| `A01-LOCAL-CONTEXT` | Stack row in `0x00480e80` | `outContext@+0x10`, size `0x28`, type `EPFTileContext` | Rename to `tileContext`; keep type unchanged | Initialization and render-call dataflow | Rename only; no type, offset, extent, or neighboring-row change | `tileContext@+0x10`, size `0x28`, type `EPFTileContext` |
| `A01-LOCAL-TEXT` | Stack row in `0x00480e80` | `Destination@+0x38`, physical size 2, type `wchar_t`; body proves occupied extent through `+0x138` | Rename to `modeText`; set type `wchar_t[128]` | Five bounded label copies and later length/draw use | Preserve start offset and exact end at `+0x138`; do not overlap `var_4` | `modeText@+0x38`, size `0x100`, type `wchar_t[128]`; `var_4` remains at `+0x138` |
| `A01-TYPE` | Function `0x00480e80` | `void __thiscall(GrafPort *this)` | Set function type to `void __thiscall ChattingVarietyPane__OnPaint(ChattingVarietyPane *this)` | Vtable ownership and exact parent declaration | Function-type action only; preserve calling convention, body, range, and stack layout except separately approved rows | Exact proposed prototype plus complete A01 frame readback |
| `A01-COMMENT` | Function regular-comment channel at `0x00480e80` | Function regular absent; function repeatable absent; address regular absent; address repeatable absent | Set only function regular text to `Source virtual ChattingVarietyPane::OnPaint. Draws CHATVAR.EPF frame 1 while g_pChattingVarietySelectPane exists, otherwise frame 0; labels g_pUserPane->m_currentSayMode as Talk/Shout/Whisper/Group/Clan and double-strikes centered text at x+1 then x.` | Exact body, globals, mode field, and paint-call sequence | Do not alter either address-comment channel, function repeatable channel, or the 27 internal regular comments | Function regular equals exact text; all other comment channels remain at literal pre-state |
| `A02-NAME` | Helper function `0x004b9670`, modeled `[0x004b9670,0x004b967d)`, 13 bytes | Name `sub_4B9670`; type `int __thiscall(_DWORD *this, int)`; bytes `55 8B EC 8B 45 08 89 41 78 5D C2 04 00`; SHA256 `424C9648B41BCB43DAA854D6F6F0C9B6F5080BACB242A564E2F6C7117AA8678A`; all four comment channels absent; exactly 11 inbound refs at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820` | Rename only to `GrafPort_SetTextBackFillColor` | Direct store to `GrafPort +0x78`, exact 11-reference set, and current GrafPort layout | Require zero proposed-name collision; pure function rename only; preserve bytes/range/comments and the literal 11-reference set; same-address old-token fallback is not an old-name entity | Address, proposed-name, and old-token lookups resolve only `0x004b9670` with new physical name; proposed names index exactly one here; old exact names index zero; inbound refs remain exactly the same 11-address set |
| `A02-LOCAL` | Stack row in `0x004b9670` | `arg_0@+0x8`, size 4, physical type `_DWORD`; saved registers `+0x0`; return address `+0x4` | Rename to `color`; request source type `unsigned int` | Store width and source-facing GrafPort convention | Preserve offset/width and protected rows; accept IDA's demonstrated canonical physical spelling `unsigned __int32` | `color@+0x8`, size 4, physical type `unsigned __int32`; protected rows unchanged |
| `A02-TYPE` | Function `0x004b9670` | `int __thiscall(_DWORD *this, int)` | Set to `void __thiscall GrafPort_SetTextBackFillColor(GrafPort *this, unsigned int color)` | Exact store-only helper semantics and stack cleanup | Preserve `__thiscall`, 13-byte body, and physical `unsigned __int32` frame spelling | Exact source-facing prototype and exact three-row frame |
| `A02-COMMENT` | Function regular-comment channel at `0x004b9670` | Function regular absent; function repeatable absent; address regular absent; address repeatable absent | Set only function regular text to `Source GrafPort::SetTextBackFillColor. Stores color in m_textBackFillColor at +0x78; this is not the +0x70 draw-mode setter.` | Exact instruction store and GrafPort field offsets | Do not alter address or repeatable channels | Exact function regular text; other channels remain absent |
| `A03-ITEM` | Global storage `0x0067addc` | Physical item `[0x0067addc,0x0067addd)`, size 1, not code/data, physical name empty; semantic type `ChattingVarietySelectPane *`; bytes at `[0x0067addc,0x0067ade0)` are four zero bytes; semantic names index already has exactly one `g_pChattingVarietySelectPane` at this address | Normalize to one four-byte data item and retain type `ChattingVarietySelectPane *`; do not issue a data rename | Seven exact refs and dated failed-attempt channel readback | Preserve four zero bytes, seven-ref topology, empty physical item name, and one same-address semantic name; no other-address collision | Physical item `[0x0067addc,0x0067ade0)`, size 4, data true, code false, name empty, type `ChattingVarietySelectPane *`; semantic names index remains exactly one same-address result |
| `A03-COMMENT` | Address regular-comment channel at `0x0067addc` | Address regular absent; address repeatable absent | Set only regular text to `ChattingVarietySelectPane singleton. Non-null selects CHATVAR.EPF frame 1 in ChattingVarietyPane::OnPaint; null selects frame 0.` | Seven-ref lifecycle and exact OnPaint use | Do not populate physical item name or repeatable comment | Exact regular text; repeatable absent; physical and semantic name channels unchanged |
| `A04-COMMENT` | Primary-vtable slot `0x00614ee4` | Four-byte data item, name empty, type empty, bytes `80 0E 48 00`, value `0x00480e80`, SHA256 `8BC85E9FFDAD3B434EEED034E020998621B7E69E400388B2C1461694AC977BB9`; address regular/repeatable absent | Set only regular address text to `ChattingVarietyPane primary-vtable OnPaint slot -> ChattingVarietyPane__OnPaint (0x00480e80).` | Sole inbound target xref and class vtable order | Comment-only; no rename, type, bytes, value, boundary, or repeatable-comment change | Exact regular text; repeatable absent; bytes/value/xref unchanged |

| Protection ID | Declarative no-change protection |
| --- | --- |
| P01 | Preserve target range `[0x00480e80,0x00480ff1)`, successor at `0x00481000`, and the intervening fifteen `0xcc` bytes outside the function. |
| P02 | Freeze A01's reachability at exactly one inbound data xref `0x00614ee4 -> 0x00480e80` and zero ordinary code callers; preserve its body/range/bytes and all 27 existing internal regular comments. Permit only the literal listed deltas in A01-NAME, A01-LOCAL-THIS, A01-LOCAL-CONTEXT, A01-LOCAL-TEXT, A01-TYPE, and A01-COMMENT; freeze every unlisted frame row, name, type/prototype field, comment channel, byte, range, xref, and caller state. |
| P03 | Freeze A02's complete 11-reference set at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`, plus the exact 13-byte body, saved-register row, return-address row, and every other unlisted prestate. Permit only the literal listed deltas in A02-NAME, A02-LOCAL, A02-TYPE, and A02-COMMENT; freeze every other frame row, name, type/prototype field, comment channel, byte, range, and xref state. |
| P04 | Preserve A03's four zero bytes, seven xrefs, one semantic singleton name, and physically empty item-name channel. |
| P05 | Preserve A04's four bytes, value, one data xref, empty name/type, and absent repeatable comment. |
| P06 | Protect adjacent vtable cells `0x00614edc` and `0x00614ee8`, neighboring singleton storage `0x0067add8` and `0x0067ade0`, `g_pEPFLib`, `g_pUserPane`, `EPFTileContext_Initialize`, `ResourceLayoutTable_LookupLayoutEntry`, `GrafPort_RenderTileFrame`, `_wcscpy_s`, `GrafPort_SetTextColor`, `GrafPort_MoveTo`, and `GrafPort_DrawWideText`; no action is recommended for these dependencies. |
| P07 | Any current pre-state drift, collision, unexpected frame/type/comment delta, changed bytes/range/xrefs, or inability to identify the exact current session/path makes the affected row unsafe/stale and requires supervisor stop-and-reread rather than adaptation by guess. |

## First-Draft C++ Recommendation

Superseded draft-placement history: the first report artifact placed a second file-scope `enum SayInputMode` immediately before this method. That was a placement defect, not missing behavior. Current UID0002RX already emits the exact five-value enum through `SayInputPanes.h`, and existing Chatting source consumes those constants. Preserve the old local-enum proposal only as this corrected historical note; it is not part of active target CPP.

Target `RECONSTRUCTION_CPP CODE` should contain exactly the method definition below:

```cpp
void ChattingVarietyPane::OnPaint()
{
    EPFTileContext tileContext;
    tileContext.Initialize();

    SetTextBackFillColor(0);

    g_pEPFLib->LookupLayoutEntry(
        L"CHATVAR.EPF",
        g_pChattingVarietySelectPane != NULL,
        &tileContext);

    RenderTileFrame(
        &tileContext,
        &tileContext.bounds,
        &m_visibleBounds,
        0,
        L"CHATVAR.PAL",
        NULL);

    wchar_t modeText[128];

    switch (g_pUserPane->m_currentSayMode) {
    case kSayInputModeDefault:
        wcscpy_s(modeText, _countof(modeText), L"Talk");
        break;

    case kSayInputModeShout:
        wcscpy_s(modeText, _countof(modeText), L"Shout");
        break;

    case kSayInputModeWhisper:
        wcscpy_s(modeText, _countof(modeText), L"Whisper");
        break;

    case kSayInputModeGroup:
        wcscpy_s(modeText, _countof(modeText), L"Group");
        break;

    case kSayInputModeClan:
        wcscpy_s(modeText, _countof(modeText), L"Clan");
        break;
    }

    const int textLength = static_cast<int>(wcslen(modeText));
    SetTextColor(128);

    const int textX =
        (m_visibleBounds.left + m_visibleBounds.right) / 2
        - (6 * textLength) / 2 - 2;
    const int textY = m_visibleBounds.bottom - 6;

    MoveTo(textX + 1, textY);
    DrawWideText(modeText, textLength);
    MoveTo(textX, textY);
    DrawWideText(modeText, textLength);
}
```

The absent `default` is intentional and behaviorally required. The source uses existing human-facing APIs and field names; it does not emit IDA labels or manual pointer arithmetic. The block-scope behavior and fixed buffer reproduce the binary. `SayInputMode` is consumed from UID0002RX's established `SayInputPanes.h` formal H output; this target must not redeclare it locally.

Target `RECONSTRUCTION_H CODE` remains blank for two independent reasons: the parent class formal block already declares the method as `protected: virtual void OnPaint();`, and the shared enum already belongs to UID0002RX's `SayInputPanes.h` block. No declaration text is emitted by this target.

## Final Recommendation

Accept 94/94 and owner/emitter route 00001Y/00001Y/TRUE. Formal CPP is the method-only body below; formal H stays blank because the parent and shared SayInputMode header own the declarations.

No behavior, ownership, range, helper/global role, type, enum-placement, or formal-code blocker remains. Lexical uncertainty is resolved with evidence-backed human names, not raw IDA labels.

Section 21 is a declarative handoff. A01 permits only A01-NAME, A01-LOCAL-THIS, A01-LOCAL-CONTEXT, A01-LOCAL-TEXT, A01-TYPE, and A01-COMMENT while freezing the sole data xref `0x00614ee4 -> 0x00480e80`, zero ordinary code callers, and every unlisted state. A02 permits only A02-NAME, A02-LOCAL, A02-TYPE, and A02-COMMENT while freezing the literal 11-reference set and all unlisted states. A03/A04 permit only their listed item/comment deltas. Execution, persistence, recovery, and credit authority remain external.

C2FD-031..038 stay proposed and unchecked. Former V1-V6 package bodies/receipts give no current credit.

The current A02 recommendation is explicitly rebased to the canonical 11-reference set `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`; the stale overcounted handoff is rejected and supplies no current protection or readback authority.

## Recommended Target Doc Changes

- Callback readback: all target changes in this section are applied at SHA256 `074982DE1F769DC4F45245AB4420CEE5AE4869D51F5D5861CF689E696843FB43`; the bullets remain the accepted no-loss specification for Gate 2A verification.
- Set `COMPLETION:94`, `CONFIDENCE:94`; preserve owner/emitter/reconstructable fields.
- Replace Item Summary with a source-ready summary covering exact range, frame selection, correct GrafPort state order, mode mapping/invariant, integer positioning, same-state double-strike, and formal source.
- Populate formal CPP with the exact method-only block above; keep H blank with explicit parent-method and UID0002RX shared-enum ownership rationale.
- Add detailed sections for exact call flow, resources, mode-state invariant, text state, arithmetic, lifetime, xrefs/vtable, stack layout, bytes/hashes, ownership, range/fence, source-name inference, rejected alternatives, and current IDA recommendations.
- Retain prior valid evidence and move contradicted `display mode`, `background-color 128`, `shadow/foreground`, and blank-C++ claims into a clearly labeled historical-assumptions section with correction reasons.

## Recommended Support Doc Changes

- Callback readback: UID00001Y, UID0000I5, UID0000QU, and UID0000BY are applied at the exact hashes in Supporting Research. UID000162, UID0000FQ, UID0000QK, UID0000XY, UID00006E, UID0002RX, and UID0002XA passed same-or-greater readback and were not edited.
- [UID:00001Y] class: correct the `0x004b9670` dependency to shared `SetTextBackFillColor`, whose current support evidence is the exact 11-reference set `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`; expand the OnPaint method row with exact frame/resource/mode/text behavior, and add a dated source-closure entry. Keep score `90/93`, class declaration, owner/emitter, size, and all unrelated content unchanged.
- [UID:0000I5] file: add a dated UID0002FD source-closure entry with the complete accepted behavior/source route, its existing `SayInputPanes.h` enum dependency, and the fact that shared render/UserPane/global dependencies do not move ownership. Keep `89/93`, source path, inventory, and all unrelated content unchanged.
- [UID:0000QU] global and [UID:0000BY] compatibility-facet pages: reconcile older active uncertainty to the accepted UID00006E source contract. Preserve the former independent-base/facet hypothesis only as corrected history; retain storage, lifetime, method-family, no-separate-vtable, and no-independent-object evidence. Do not create a second declaration or global.
- UID000162 GrafPort, UID0000FQ UserPane, UID0000QK global-alias support, UID0000XY EPFTileContext, UID00006E ImageLib formal source, UID0002RX shared enum, and UID0002XA singleton pages: no duplicate edit; physically verify their same-or-greater facts remain present before callback completion.

## Score And Metadata Recommendation

| Document | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| UID0002FD target | `94/94` | `94/94` | Physical callback readback already holds the accepted score. Exact behavior, range, ownership, dependencies, shared-enum placement, source shape, CPP, and report-level IDA transaction design close the research blockers. Below 95 because original lexical spellings remain inferred and the supervisor-owned IDA transaction, including every boundary-specific exclusive `FileShare.None` read probe, plus generated/compile gates remain unperformed. The earlier `86/91` value is pre-callback history only. |
| UID00001Y class | `90/93` | unchanged | Class surface, size, and source route are already closed; callback is a detail correction, not a class-score gap. |
| UID0000I5 file | `89/93` | unchanged | Established file route/inventory remains correct; callback adds detail without closing the file's unrelated remaining gaps. |

Target metadata remains `CANONICAL_OWNER:00001Y`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Y`, blank emitter position. No split, additional emitter, covered-by marker, or non-reconstructable downgrade is justified.

## Open Questions With Attempted Resolution

- Original lexical spellings cannot be certain from a stripped binary; project-consistent names are inferred from role, offsets, callers, behavior, and docs. Raw labels are not acceptable final source.
- Source placement is resolved: body in Chatting.cpp; parent owns OnPaint declaration; UID0002RX owns SayInputMode in SayInputPanes.h.
- Behavior, ownership, extent/fence, singleton role, dependencies, and formal C++ are resolved; no research blocker remains for 94/94.
- IDA pre-state is dated. Section 21 records it exactly; supervisor must freshly rebase before mutation and return drift for report repair.
- Three prior Gate 2B attempts stopped before save and retain only rollback/no-persistence history.
- Former executable report packages were a format error and are not an open question or current evidence.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read each current row immediately before editing. Only the primary supervisor may edit manual coverage.

The twelve target/support manual dispositions below are the complete triggered-row package. Apply them only after accepted ordinary documentation reaches the report's intended poststate. Abort and reread every current row if a dated hash, unique UID row, or neighboring anchor differs. Preserve every unrelated row and every valid neighboring fact; no insertion or deletion is authorized.

Replace the current UID0002FD by-memory row with exactly:

```text
        - [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) 0x00480e80-0x00480ff1 | paint method | ChattingVarietyPaneOnPaint : reconstructable : 94% : very-strong : Source-ready ChattingVarietyPane::OnPaint at exact bounds 0x00480e80-0x00480ff1 and vtable-only slot 0x00614ee4 initializes a borrowed EPFTileContext, calls SetTextBackFillColor(0), resolves CHATVAR.EPF through the ImageLib/ResourceLayoutTable::LookupLayoutEntry facet, selects frame 0/1 from g_pChattingVarietySelectPane at 0x0067addc, renders CHATVAR.PAL through SurfacePaintHelpers, maps UserPane::m_currentSayMode at g_pUserPane+0x3eb4 values 0..4 to Talk/Shout/Whisper/Group/Clan without inventing an invalid-mode fallback, calls SetTextColor(128), computes exact centered coordinates, performs the same-state one-pixel double-strike at x+1/x, preserves ChattingVarietyPane ownership/emission, and leaves the trailing 15-byte 0xcc fence outside the method.
```

Replace the current UID00001Y by-class row with exactly:

```text
- [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md) : reconstructable : 90% : very-strong : Source-clean Pane-derived compact chat-mode class with exact constructor/destructor/HandlePointerOrMouseEvent/OnPaint declarations, compact state byte at +0xf8, implicit pointer alignment at +0xf9..+0xfb rather than a fabricated reserve array, selector pointer at +0xfc, header-facing extern g_pChattingVarietyPane contract, class closure before child definitions, exact singleton lifecycle, retained raw-helper/compiler-forwarder distinctions, private GetItemRect/HitTest helper surface, canonical HandlePointerOrMouseEvent(Event *) popup create/delete/invalidate behavior, complete UID0002FC/FF/FG source, and size 0x100; source-ready OnPaint initializes a borrowed EPFTileContext, sets text-back fill 0, resolves CHATVAR.EPF through ImageLib/ResourceLayoutTable, selects frame 0/1 from g_pChattingVarietySelectPane, renders CHATVAR.PAL, maps UserPane::m_currentSayMode 0..4 to Talk/Shout/Whisper/Group/Clan without a fabricated fallback, sets text color 128, and double-strikes centered text at x+1/x with unchanged draw state.
```

Replace the current UID000162 by-memory row, uniquely anchored between UID000161 and UID000163, with exactly:

```text
    - [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) 0x004b95e0-0x004b96a0 | method-cluster | GrafPortDrawStateAccessors : reconstructable : 89% : very-strong : Current evidence confirms eight leaf GrafPort accessors over the exact half-open range 0x004b95e0-0x004b96a0: GetDrawPosition, MoveTo, OffsetDrawPosition, SetFontId, SetDrawColor, SetTextBackFillColor, SetTextColor, and SetTextBackColor. Exact field offsets, broad caller totals, no-callee behavior, direct GrafPort ownership/emission, padding, and formal first-draft C++ are documented; exact original public/member spellings remain inferred confidence caps rather than blank-C++ blockers.
```

Replace the current UID0000XY by-memory row, uniquely anchored between the `0x00457a5d-0x00457a60` alignment row and the `0x00458557-0x00458560` tail-padding row, with exactly:

```text
    - [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) 0x00457a60-0x00458610 | class aggregate | EPFTileContext : reconstructable : 88% : very-strong : Full EPFTileContext aggregate owned/emitted through UID00004I with all 12 bodies, exact padding, 0x28-byte layout, raw-copy, decimation/allocation, broad initialization/release fan-in, image-loader callers, and render-support ownership documented. UID000200 and UID000201 carry accepted child first-draft C++; aggregate formal C++ remains intentionally blank only under retained/no-route and exact-child placement policy, not because the usable EPFTileContext declaration is unresolved.
```

For the unique UID00006E by-class row between UID00006D and UID00006F, preserve the complete current row byte-for-byte and replace only `: reconstructable : 82% : strong :` with `: reconstructable : 89% : very-strong :`.

Replace the current UID0000QK by-global row, uniquely anchored between UID0002XG and UID0000QL, with exactly:

```text
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) : reconstructable : 89% : very-strong : Canonical source-facing UserPane *g_pUserPane storage view at 0x0067a748 with historical g_pCollectionData/g_pPlayerData aliases retained for search continuity. Exact UserPane constructor/destructor/clear ownership, five-write lifetime set, 505-reference client-state use, collection/spell/item/chat typed views, m_currentSayMode at +0x3eb4, and non-collection consumers are documented. This semantic alias page emits no duplicate global; UID0001OR remains the sole formal UserPane *g_pUserPane definition.
```

Replace the current UID0000QU by-global row, uniquely anchored between UID0000QT and UID0000QV, with exactly:

```text
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) : reconstructable : 89% : strong : Process-wide EPF/EPD image-resource singleton storage at 0x0067a744, owned by ImageLib with the accepted source declaration extern ImageLib *g_pEPFLib and exposed through the non-virtual typedef ImageLib ResourceLayoutTable compatibility facet. Exact constructor/destructor writes and clears, ImageLib vtable/lifecycle refs, broad UI/render consumers, aliases/layout references, and saved g_pEPFLib/ImageLib_vftable labels remain preserved. UID0002KQ remains a raw no-this helper whose caller preload does not move ownership. UID0002P6's 81-xref family supplies direct ResourceLayoutTable::LoadFrameDrawRecord receiver evidence, and UID0002DL plus UID0002FD supply direct LookupLayoutEntry paint consumers. The semantic page emits no second definition; generated g_pResourceMan, ResourceLayoutTable * storage, and an independent ResourceLayoutTable object are rejected. Exact lost typedef spelling remains only a confidence cap.
```

Exact same-or-greater no-op proofs:

- UID0000I5 by-file: the unique current `89% : very-strong` row already preserves Chatting ownership, selector singleton, class/helper inventory, and source routing. Do not edit or duplicate it.
- UID0000BY by-class: the unique current row already records `typedef ImageLib ResourceLayoutTable`, `ImageLib *g_pEPFLib`, the non-virtual facet, and rejection of independent storage. Do not edit it.
- UID0000FQ by-class: the unique current `94% : very-strong` row already preserves the complete UserPane declaration and integer say-mode field split. Do not edit it.
- UID0002RX by-memory: the unique current `90% : very-strong` row already preserves source-ready mode/field/helper and shared-header evidence. Do not edit it.
- UID0002XA by-global: the unique current row already preserves `0x0067addc`, the seven-reference lifecycle, sole definition, direct Chatting route, and source/compiler split. Do not edit it.

Generated tracker truth is validator-owned and must be reread dynamically; no manual tracker text edit is authorized.

## Follow-Up Actions

1. Supervisor Gate 1 checks substantive headings, zero executable packages, formal CPP placement, blank H, one terminal marker, lifecycle language, and literal ledger/checklist parity across Claim ID, Target UID, represented claim/destination identity, actor/authority, action, and verification state.
2. Supervisor rebases every Section-21 row in live MCP/IDA. Drift, collision, occupied extent, unexpected xref/type/comment, unrelated unsaved work, or uncertain database identity stops the row.
3. The accepted IDA scope is limited to the listed A01/A02 name, frame, type, and comment outcomes plus the listed A03/A04 item/comment outcomes; all protected xrefs, callers, frames, bytes, ranges, comments, names, types, globals, and adjacent slots remain exact. Physical execution and persistence credit are supervisor-owned and external.
4. Supervisor applies C2FD-039..041 and C2FD-056..064 after exact coverage-row reread.
5. C2FD-042..044 and C2FD-065..066 already record scoped validators; supervisor handles C2FD-045..047 and C2FD-052.
6. Execution/archive is supervisor-owned from current path and validator history. B006 must not run execute_report or move the report.

## Confidence

- **Behavior/range/vtable/resources/arguments:** exact to very strong.
- **Class owner/emitter/source file:** very strong.
- **GrafPort/UserPane/EPFTileContext/global roles:** very strong, supported by current UDTs and formal docs.
- **First-draft source behavior:** very strong; deliberate no-default behavior matches the binary.
- **Original lexical names:** strong inference, not symbol-proven. Enum/header ownership is resolved by current UID0002RX formal H and generated `SayInputPanes.h` evidence.
- **Recommended score:** `94/94`, deliberately below the `95/95` final-source barrier.

## Validator Results

- Current format repair ran no validator, lifecycle command, execute_report, generated refresh, coverage edit, MCP/IDA operation, process control, movement, or external doc edit. Former package evidence is withdrawn; no Gate 2B credit is claimed.

- During the initial report-only phase B006 ran no validator, IDA mutation/save, coverage edit, generated refresh, lifecycle command, execution, or movement action. During the later supervisor-authorized implementation callback B006 ran these five serial scoped validators from `source-3/project-documentation`; they are dated origin history:
  - command `000000021289`, `2026-08-05T21:53:10-04:00`: target validator; completion/confidence read back `94/94`, blank-to-block registry update recorded, generated refresh deferred.
  - command `000000021290`, `2026-08-05T21:54:12-04:00`: UID00001Y class validator; generated refresh deferred.
  - command `000000021291`, `2026-08-05T21:54:55-04:00`: UID0000I5 file validator; generated refresh deferred.
  - command `000000021292`, `2026-08-05T21:56:13-04:00`: UID0000QU global validator; registry/reference/stat updates recorded, generated refresh deferred.
  - command `000000021293`, `2026-08-05T21:57:26-04:00`: UID0000BY class validator; registry/reference updates recorded, generated refresh deferred.
- Gate 2A independently accepted 37/42 checked non-IDA claims but failed closed on C2FD-042..044/C2FD-065..066 because the original command prose lacked independently locatable literal `ok: 1` receipts. B006 therefore reran the same five current scopes serially as commands `000000021475` through `000000021479`. Every rerun exited `0`, returned literal `ok: 1`, scanned exactly one file, and reported `generated_refresh: deferred`; the exact receipts below now support those five checked claims.

### Independent Gate 2A Scoped Validator Receipts - 2026-08-06

Command `python .\tools\validator.py --mode file --file by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md --apply --queue-timeout 240` exited `0`; stderr was empty. Full stdout:

```text
command_id: 000000021475
command_timestamp: 2026-08-06T05:45:36-04:00
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
ini: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.ini
lock: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.lock
mode: file
scope: direct by-* folders under root
apply: True
remove missing: False
uid phase: True
reference phase: True
scanned markdown files: 1
last used UID: 00050J
ok: 1
projected_stats_update: 1
stats_incremental_noop: 1
stats_incremental_noop 0002FD project-level/-auto-completion-stats.md file is not present in generated stats lists
projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section
generated_refresh: deferred
generated_refresh_command_id: 000000021475
generated_refresh_timestamp: 2026-08-06T05:45:36-04:00
```

Command `python .\tools\validator.py --mode file --file by-class/ChattingVarietyPane.md --apply --queue-timeout 240` exited `0`; stderr was empty. Full stdout:

```text
command_id: 000000021476
command_timestamp: 2026-08-06T05:45:44-04:00
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
ini: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.ini
lock: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.lock
mode: file
scope: direct by-* folders under root
apply: True
remove missing: False
uid phase: True
reference phase: True
scanned markdown files: 1
last used UID: 00050J
ok: 1
projected_stats_update: 1
stats_incremental_noop: 1
stats_incremental_noop 00001Y project-level/-auto-completion-stats.md file is not present in generated stats lists
projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section
generated_refresh: deferred
generated_refresh_command_id: 000000021476
generated_refresh_timestamp: 2026-08-06T05:45:44-04:00
```

Command `python .\tools\validator.py --mode file --file by-file/Chatting.md --apply --queue-timeout 240` exited `0`; stderr was empty. Full stdout:

```text
command_id: 000000021477
command_timestamp: 2026-08-06T05:45:56-04:00
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
ini: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.ini
lock: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.lock
mode: file
scope: direct by-* folders under root
apply: True
remove missing: False
uid phase: True
reference phase: True
scanned markdown files: 1
last used UID: 00050J
ok: 1
projected_stats_update: 1
stats_incremental_noop: 1
stats_incremental_noop 0000I5 project-level/-auto-completion-stats.md file is not present in generated stats lists
projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section
generated_refresh: deferred
generated_refresh_command_id: 000000021477
generated_refresh_timestamp: 2026-08-06T05:45:56-04:00
```

Command `python .\tools\validator.py --mode file --file by-global/g_pEPFLib.md --apply --queue-timeout 240` exited `0`; stderr was empty. Full stdout:

```text
command_id: 000000021478
command_timestamp: 2026-08-06T05:46:04-04:00
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
ini: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.ini
lock: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.lock
mode: file
scope: direct by-* folders under root
apply: True
remove missing: False
uid phase: True
reference phase: True
scanned markdown files: 1
last used UID: 00050J
ok: 1
projected_stats_update: 1
stats_row_update: 1
stats_row_update 0000QU project-level/-auto-completion-stats.md by-global_Reconstructable
projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section
generated_refresh: deferred
generated_refresh_command_id: 000000021478
generated_refresh_timestamp: 2026-08-06T05:46:04-04:00
```

Command `python .\tools\validator.py --mode file --file by-class/ResourceLayoutTable.md --apply --queue-timeout 240` exited `0`; stderr was empty. Full stdout:

```text
command_id: 000000021479
command_timestamp: 2026-08-06T05:46:14-04:00
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
ini: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.ini
lock: C:\FastStorage\NTK_Sources\source-3\project-documentation\tools\validator.lock
mode: file
scope: direct by-* folders under root
apply: True
remove missing: False
uid phase: True
reference phase: True
scanned markdown files: 1
last used UID: 00050J
ok: 1
projected_stats_update: 1
stats_incremental_noop: 1
stats_incremental_noop 0000BY project-level/-auto-completion-stats.md file is not present in generated stats lists
projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section
generated_refresh: deferred
generated_refresh_command_id: 000000021479
generated_refresh_timestamp: 2026-08-06T05:46:14-04:00
```

- No manual coverage validator was run because B006 did not edit any `-coverage-report.md`. Generated verification must use a later coherent supervisor refresh and its returned command IDs/timestamps; command `000000021178` remains a dated report-time snapshot only.
- Compile/uniqueness verification for C2FD-052 is exact: `SayInputPanes.h` must be visible to `Chatting.cpp`; generated `SayInputPanes.h` must contain exactly one `SayInputMode` definition; generated `Chatting.cpp` and `Chatting.h` must contain zero enum definitions; `Chatting.cpp` must contain exactly one UID0002FD method body; target H must add no duplicate `OnPaint` declaration; and the project x86 MSVC harness must compile the resulting source.
- Report execution/archive, generated refresh, manual coverage/archive/move, compile verification, and IDA mutation/save actions remain supervisor/validator-owned. Neither the five original callback validators nor the five independent receipt reruns claim any of those unperformed actions.

## Changed Files

- Earlier authorized callback changed and scoped-validated exactly target UID0002FD plus UID00001Y, UID0000I5, UID0000QU, and UID0000BY; exact dated hashes and validator receipts remain below.
- All callback leases were explicitly released; no callback lease expired.
- Independent receipt reruns 000000021475..000000021479 made no destination-byte change; dated identities require dynamic reread.
- Same-or-greater support pages read but not edited: UID00006E, UID0000FQ, UID0000QK, UID000162, UID0000XY, UID0002RX, UID0002XA.
- Current format repair edits only this report, removes embedded automation/package-only claims, preserves research/formal source/doc recommendations, and converts IDA work to Section 21 structured handoff.
- No coverage, generated/tracker, IDB, goal, notes, audit, catalog, or lifecycle file was edited in this repair.
- Execution/archive/status/history/tracker lifecycle are supervisor/validator-owned. B006 did not invoke execute_report.

## Implementation Tracking Checklist

Checklist mirrors the ledger literally on Claim ID, Target UID, actor/authority, action, and verification state; each Exact action/readback preserves the corresponding ledger claim and destination identity where represented. Checked rows are prior completed work; unchecked rows stay with named supervisor authority.

| Claim ID | Target UID | Actor / authority | Action | Exact action/readback | Verification state |
| --- | --- | --- | --- | --- | --- |
| C2FD-001 | 0002FD | B006 implementation callback | incorporate | [x] Add exact body range/size/hash to target. | applied |
| C2FD-002 | 0002FD | B006 implementation callback | incorporate | [x] Add/protect exact 15-byte fence and successor boundary. | applied |
| C2FD-003 | 0002FD | B006 implementation callback | incorporate | [x] Add vtable-only reachability and zero ordinary callers. | applied |
| C2FD-004 | 0002FD | B006 implementation callback | incorporate | [x] Record canonical method/class/file ownership. | applied |
| C2FD-005 | 0002FD | B006 implementation callback | incorporate | [x] Record borrowed initialized stack context semantics. | applied |
| C2FD-006 | 0002FD | B006 implementation callback | incorporate | [x] Correct helper to SetTextBackFillColor(0) at +0x78. | applied |
| C2FD-007 | 0002FD | B006 implementation callback | incorporate | [x] Record selector-present frame 1/null frame 0. | applied |
| C2FD-008 | 0002FD | B006 implementation callback | incorporate | [x] Record exact CHATVAR resources/xrefs. | applied |
| C2FD-009 | 0002FD | B006 implementation callback | incorporate | [x] Record exact RenderTileFrame arguments. | applied |
| C2FD-010 | 0002FD | B006 implementation callback | incorporate | [x] Record UserPane::m_currentSayMode at +0x3eb4. | applied |
| C2FD-011 | 0002FD | B006 implementation callback | incorporate | [x] Record exact 0..4 label mapping. | applied |
| C2FD-012 | 0002FD | B006 implementation callback | incorporate | [x] Record no-default invalid-mode invariant. | applied |
| C2FD-013 | 0002FD | B006 implementation callback | incorporate | [x] Record bounded copies and source wcslen. | applied |
| C2FD-014 | 0002FD | B006 implementation callback | incorporate | [x] Record SetTextColor(128) at +0x7c. | applied |
| C2FD-015 | 0002FD | B006 implementation callback | incorporate | [x] Record exact integer coordinate expressions. | applied |
| C2FD-016 | 0002FD | B006 implementation callback | incorporate | [x] Correct effect to same-state x+1/x double-strike. | applied |
| C2FD-017 | 0002FD | B006 implementation callback | incorporate | [x] Record no release/destructor/EH cleanup. | applied |
| C2FD-018 | 0002FD | B006 implementation callback | incorporate | [x] Insert exact method-only formal CPP and consume, but do not redeclare, UID0002RX `SayInputMode`. | applied |
| C2FD-019 | 0002FD | B006 implementation callback | not-applicable | [x] Keep target H blank and record both parent-method and UID0002RX shared-enum ownership reasons. | applied |
| C2FD-020 | 0002FD | B006 implementation callback | incorporate | [x] Set target score 94/94. | applied |
| C2FD-021 | 0002FD | B006 implementation callback | already-present | [x] Verify owner/emitter/reconstructable route unchanged. | already-present |
| C2FD-022 | 0002FD | B006 implementation callback | incorporate | [x] Replace stale target summary/behavior/open questions. | applied |
| C2FD-023 | 0002FD | B006 implementation callback | historicalize | [x] Preserve contradicted old claims in historical section. | applied |
| C2FD-024 | 00001Y | B006 implementation callback | incorporate | [x] Correct/strengthen UID00001Y OnPaint detail, score unchanged. | applied |
| C2FD-025 | 0000I5 | B006 implementation callback | incorporate | [x] Add detailed UID0000I5 source-closure entry with established `SayInputPanes.h` dependency, score unchanged. | applied |
| C2FD-026 | 000162 | B006 implementation callback | already-present | [x] Verify GrafPort formal accessors remain same-or-greater. | already-present |
| C2FD-027 | 0000FQ | B006 implementation callback | already-present | [x] Verify UID0000FQ formal UserPane member and UID0000QK global-alias/offset support remain same-or-greater. | already-present |
| C2FD-028 | 0000XY | B006 implementation callback | already-present | [x] Verify EPFTileContext layout/Initialize remains same-or-greater. | already-present |
| C2FD-029 | 00006E | B006 implementation callback | incorporate | [x] Reconcile UID0000QU/UID0000BY prose to UID00006E `ImageLib`, compatibility typedef `ResourceLayoutTable`, and sole `extern ImageLib *g_pEPFLib` source contract while preserving historical alternatives as corrected history. | applied |
| C2FD-030 | 0002XA | B006 implementation callback | already-present | [x] Verify singleton source definition/seven-ref proof remains same-or-greater. | already-present |
| C2FD-031 | 0002FD | Primary supervisor Gate 2B | incorporate | [ ] Retain only the A01-NAME, A01-LOCAL-THIS, A01-LOCAL-CONTEXT, A01-LOCAL-TEXT, A01-TYPE, and A01-COMMENT outcomes; preserve exactly one inbound data xref `0x00614ee4 -> 0x00480e80`, zero ordinary code callers, the approved physical frame deltas, and every unlisted name/type/comment/body/range state. | proposed |
| C2FD-032 | 0002FD | Primary supervisor Gate 2B | incorporate | [ ] Require the complete A01 physical frame readback: `thisPane` `ChattingVarietyPane *` at `+0xc`, `tileContext` `EPFTileContext` at `+0x10`, `modeText` `wchar_t[128]` at `+0x38..+0x138`, with every unlisted row and byte unchanged. | proposed |
| C2FD-033 | 000162 | Primary supervisor Gate 2B | incorporate | [ ] Retain only the A02-NAME, A02-LOCAL, A02-TYPE, and A02-COMMENT outcomes; preserve the exact 11 inbound references at `0x00467be6`, `0x00467e26`, `0x00467ec4`, `0x00480ead`, `0x0048216f`, `0x004b1c7b`, `0x00550e87`, `0x00550fe7`, `0x0057c1a5`, `0x00585bf5`, and `0x005bc820`, the 13-byte body, three-row frame, physical `unsigned __int32` normalization, and every unlisted state. | proposed |
| C2FD-034 | 0002XA | Primary supervisor Gate 2B | incorporate | [ ] Normalize `0x0067addc` to one four-byte data item of type `ChattingVarietySelectPane *` with an empty physical item name; set only the address-regular comment to `ChattingVarietySelectPane singleton. Non-null selects CHATVAR.EPF frame 1 in ChattingVarietyPane::OnPaint; null selects frame 0.` Preserve four zero bytes, seven refs, adjacent heads, one semantic same-address name, and all other analysis state. | proposed |
| C2FD-035 | 00001Y | Primary supervisor Gate 2B | incorporate | [ ] Set only the address-regular comment at `0x00614ee4` to `ChattingVarietyPane primary-vtable OnPaint slot -> ChattingVarietyPane__OnPaint (0x00480e80).` Preserve repeatable-comment absence, slot value, target ref, item bounds, bytes, and adjacent slots. | proposed |
| C2FD-036 | 0002FD | Primary supervisor Gate 2B | already-present | [ ] Protect every unlisted function/frame/prototype/comment/item/name/string/byte/xref/UDT/adjacent global or slot; permit only the listed A01-A04 deltas, including A01's one-data-xref/zero-code-caller state and A02's literal 11-reference set; no unrelated cache, analysis, naming, typing, comment, body, range, or item effect is accepted. | proposed |
| C2FD-037 | 0002FD | Primary supervisor Gate 2B | incorporate | [ ] Treat all dated session, path, schema, and endpoint evidence as non-authoritative history. Credit requires independent confirmation that each literal entity prestate and expected physical readback remains exact; any mismatch rejects the affected outcome rather than authorizing adaptation. | proposed |
| C2FD-038 | 0002FD | Primary supervisor Gate 2B | incorporate | [ ] Grant IDA credit only after independent physical readback proves every accepted Section 21 outcome and protected no-change state. Report text and the inert removed companion grant no mutation or persistence credit. | proposed |
| C2FD-039 | 0002FD | Primary supervisor manual coverage | incorporate | [ ] Apply exact current by-memory row replacement after reread. | proposed |
| C2FD-040 | 00001Y | Primary supervisor manual coverage | incorporate | [ ] Apply exact current by-class row replacement after reread. | proposed |
| C2FD-041 | 0000I5 | Primary supervisor manual coverage | already-present | [ ] Confirm by-file row remains valid; do not duplicate. | proposed |
| C2FD-042 | 0002FD | B006 implementation callback | incorporate | [x] Independent command `000000021475` validated the target with exit `0`, literal `ok: 1`, one scanned file, unchanged `94/94`/SHA, and deferred generated refresh. | applied |
| C2FD-043 | 00001Y | B006 implementation callback | incorporate | [x] Independent command `000000021476` validated UID00001Y with exit `0`, literal `ok: 1`, one scanned file, unchanged SHA, and deferred generated refresh. | applied |
| C2FD-044 | 0000I5 | B006 implementation callback | incorporate | [x] Independent command `000000021477` validated UID0000I5 with exit `0`, literal `ok: 1`, one scanned file, preserved pre-rerun concurrent SHA/UID0002FD detail, and deferred generated refresh. | applied |
| C2FD-045 | 0002FD | Primary supervisor validator/generated | incorporate | [ ] Verify one generated body and zero CPP empty markers. | proposed |
| C2FD-046 | 0002FD | Primary supervisor validator/generated | already-present | [ ] Verify generated H has no duplicate declaration. | proposed |
| C2FD-047 | 0002FD | Primary supervisor validator/generated | incorporate | [ ] Dynamically reread tracker row/counts/current path. | proposed |
| C2FD-048 | 0002FD | B006 implementation callback | historicalize | [x] Preserve old-report leads only as corrected history. | applied |
| C2FD-049 | 0002FD | B006 implementation callback | incorporate | [x] Protect literals and emit source literals only. | applied |
| C2FD-050 | 0002FD | B006 implementation callback | already-present | [x] Verify unsplit target and external fence. | already-present |
| C2FD-051 | 0002FD | B006 implementation callback | incorporate | [x] Record rejected ownership/source alternatives. | applied |
| C2FD-052 | 0002FD | Primary supervisor validator/generated | incorporate | [ ] Verify x86 MSVC compile, shared-header visibility, one enum in `SayInputPanes.h`, zero enum copies in Chatting CPP/H, one UID0002FD body, and no duplicate target H declaration. | proposed |
| C2FD-053 | 0002FD | B006 report/callback history | historicalize | [x] Record that the initial report-only phase changed only this report and the later callback changed exactly five listed destinations. | applied |
| C2FD-054 | 0002FD | B006 report/callback history | historicalize | [x] Record zero initial-phase validators/actions, five callback validators, and five independent Gate 2A receipt reruns with no IDA/manual/generated-refresh/lifecycle/execution/movement action. | applied |
| C2FD-055 | 0002FD | B006 implementation callback | not-applicable | [x] Confirm no third-party import directive is needed. | applied |
| C2FD-056 | 000162 | Primary supervisor manual coverage | incorporate | [ ] Replace the unique stale UID000162 by-memory row after hash/anchor reread. | proposed |
| C2FD-057 | 0000XY | Primary supervisor manual coverage | incorporate | [ ] Replace the unique stale UID0000XY by-memory row after hash/anchor reread. | proposed |
| C2FD-058 | 00006E | Primary supervisor manual coverage | incorporate | [ ] Correct only the stale UID00006E manual score/confidence tokens and preserve the row. | proposed |
| C2FD-059 | 0000QK | Primary supervisor manual coverage | incorporate | [ ] Replace the unique stale UID0000QK by-global row after hash/anchor reread. | proposed |
| C2FD-060 | 0000QU | Primary supervisor manual coverage | incorporate | [ ] Replace the unique stale UID0000QU by-global row after hash/anchor reread. | proposed |
| C2FD-061 | 0000BY | Primary supervisor manual coverage | already-present | [ ] Confirm UID0000BY manual compatibility-facet detail remains same-or-greater; do not edit. | proposed |
| C2FD-062 | 0000FQ | Primary supervisor manual coverage | already-present | [ ] Confirm UID0000FQ manual UserPane/say-mode detail remains same-or-greater; do not edit. | proposed |
| C2FD-063 | 0002RX | Primary supervisor manual coverage | already-present | [ ] Confirm UID0002RX manual shared-header dispatcher detail remains same-or-greater; do not edit. | proposed |
| C2FD-064 | 0002XA | Primary supervisor manual coverage | already-present | [ ] Confirm UID0002XA manual singleton detail remains same-or-greater; do not edit. | proposed |
| C2FD-065 | 0000QU | B006 implementation callback | incorporate | [x] Independent command `000000021478` validated UID0000QU with exit `0`, literal `ok: 1`, one scanned file, one stats-row update, unchanged SHA, and deferred generated refresh. | applied |
| C2FD-066 | 0000BY | B006 implementation callback | incorporate | [x] Independent command `000000021479` validated UID0000BY with exit `0`, literal `ok: 1`, one scanned file, unchanged SHA, and deferred generated refresh. | applied |

- Exact parity/allocation self-audit: 66 ledger rows and 66 checklist rows preserve identical Claim ID, Target UID, actor/authority, action, and verification state in C2FD-001..066 order; each ledger claim/destination identity remains represented by the checklist Exact action/readback where applicable; allocation remains 42 checked/applied-or-already-present and 24 unchecked/proposed.
- C2FD-031..038 remain pending; no B006 automation, execute_report, IDA mutation/save, move, or archive action is authorized.
- Former V1-V6 packages/receipts give no current credit.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000021684","destination_path":"executed-b-agent-research/B006/0002FD-ChattingVarietyPaneOnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0002FD-ChattingVarietyPaneOnPaint-source-quality.md","timestamp":"2026-08-10T11:20:22-04:00","uid":"0002FD"} -->
<!-- {"agent":"B006","command_id":"000000023052","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002FD-ChattingVarietyPaneOnPaint-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002FD-ChattingVarietyPaneOnPaint-source-quality.md","timestamp":"2026-08-13T03:35:41-04:00","uid":"0002FD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
