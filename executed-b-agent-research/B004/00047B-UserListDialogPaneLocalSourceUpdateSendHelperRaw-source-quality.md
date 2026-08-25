** TARGET-REPORT-UID:00047B **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 00047B - UserListDialogPaneLocalSourceUpdateSendHelperRaw Source-Quality Report

## Finalized Report / Current Recommendation

Implementation callback complete: [UID:00047B] `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` remains reconstructable raw source-authored code with `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank formal C++. The target is now `COMPLETION:87`, `CONFIDENCE:91` after incorporating the renewed MCP evidence, and it is still not routed to [UID:0000FN] `UserListDialogPane`, [UID:0000OZ] `UserListDialogPane.cpp`, [UID:0000A7] `PartySearchEditPane`, [UID:0000P1] `UserPane`, or any packet/helper file as an emitter.

The body is real executable code, not switch-table data or padding, and it is source-shaped as a hidden `__thiscall` helper using `ecx` as a `UserListDialogPane *` receiver. It reads local-player state through `dword_67A748`, which current support docs identify as canonical source-facing `g_pUserPane`, not `g_pUserListDialogPane`. It searches the dialog master `UserListRecord` list at `this+0x288`, mirrors `huntersListFlag` at row `+0x20e`, clears `hasSourceText` at row `+0x20f` when the local state differs, copies local source text from `g_pUserPane+0x3cb2` into row `+0x210`, builds an outbound opcode `0x84` / decimal `132` packet (Verified with `int_convert.py`), appends the selected flag and optional source text, then sends through the packet-sender global `dword_67A7EC` via `0x00574bb0`.

The score improvement is documentation-quality only. The renewed route pass still finds no IDA function object at `0x0059dc20`, no incoming xref to the raw start, no little-endian PE pointer-pattern hit for `0x0059dc20` or `0x0059de4a`, and only internal branch xrefs to labels inside the raw helper. Because no caller/source route is proven, emitting a standalone method or file-local helper would risk adding dead or duplicate source API surface.

## Supporting Research

Read current assignment and workflow:

- `tools/leaser/Agents/Agent-B004/goal.md` for UID `00047B`, target path, required report path, Medium provenance, report-only boundary, and target-specific MCP route requirements.
- Project-level `ntk-b-agent-workflow` skill and `references/b-agent-research-and-implementation-workflow.md`.
- `by-structure.md` IDA MCP output discipline: narrow exact-address calls, bounded disassembly/xref/pointer searches, no broad unbounded scans.

Read current target/support docs:

- Target [UID:00047B] `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md`.
- Parent [UID:0001KI] `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`.
- File [UID:0000OZ] `by-file/UserListDialogPane.md`.
- Class [UID:0000FN] `by-class/UserListDialogPane.md`.
- Class [UID:0000FO] `by-class/UserListPane.md`.
- Class [UID:0000A7] `by-class/PartySearchEditPane.md`.
- Global/support [UID:0003EI] `by-global/g_pUserListDialogPane.md`.
- UserPane/global support [UID:0001OR] `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` and [UID:0000QK] `by-global/g_pCollectionData.md`.
- Adjacent/related exact children [UID:000477], [UID:000479], [UID:00047C], and [UID:00047G].
- Generated lead `auto-generated/NexusTK/social/UserListDialogPane.cpp`, refreshed by validator command id `000000005507` at `2026-07-03T14:20:41-04:00`.

Search-gated prior reports:

- `rg` terms used: `00047B`, `0059dc20`, `0059de4a`, `UserListDialogPaneLocalSourceUpdateSendHelperRaw`, `LocalSourceUpdate`, `source-update`, `g_pUserListDialogPane`, `huntersListFlag`, `sourceText`.
- Opened matching central executed reports only: B001 `0000FN-UserListDialogPane-class-source-quality.md` and B002 `0001KI-UserListDialogPaneAndUserListPane-source-quality.md`.
- Prior reports are used as leads. The current recommendation is based on the live MCP session `2ec9c08f` plus current docs.

## Target

- UID: `00047B`.
- Target path: `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md`.
- Current metadata after callback: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Current queue row at assignment time: tracker `84/90`, combined `87.0`, reconstructable `true`, reports `0`.
- Current parent: [UID:0001KI] split/index range under [UID:0000OZ] `UserListDialogPane.cpp`.

## Current Target State

The target already records the broad behavior, no-route status, blank emitter/C++ disposition, and earlier route checks. The stale or under-specified part is the active evidence detail:

- The current summary says "reads `g_pUserListDialogPane`-local state." Current MCP proves the receiver is the `ecx`/`esi` `UserListDialogPane *this`, while the local-player state pointer read at `0x0059dc33` and `0x0059dcfa` is `dword_67A748`, now documented as source-facing `g_pUserPane`.
- The page does not record enough current line-level evidence for the name-copy, row scan, row `+0x20e/+0x20f/+0x210` updates, `0x84` packet construction, `WideCharToMultiByte` conversion, packet append helpers, and send call.
- The existing no-route proof remains directionally correct but should be refreshed with the live session id, exact negative pointer-pattern result, no IDA function object, decompilation failure at raw start, and internal-only label xrefs.

Generated freshness observation: `auto-generated/NexusTK/social/UserListDialogPane.cpp` currently has validator header `validator-command-id: 000000005507` and `validator-refreshed-at: 2026-07-03T14:20:41-04:00`. It has no UID00047B emitted helper, which matches the current blank-emitter disposition.

## Heuristic / Inference Reanalysis And Validation

This body is source-authored behavior but lacks a proven source route. The correct reconstruction stance is to document it as retained raw helper code and avoid source emission until a caller/route is found.

Facts:

- `lookup_funcs` on live session `2ec9c08f` reports `0x0059dc20` and `0x0059de4a` are not functions. Neighboring source functions are modeled: `0x0059d620` size `0x2d5`, `0x0059e3d0` size `0x337`, and `0x0059de60` size `0x70`.
- `get_bytes(0x0059dbe0, 0x90)` shows `OnControlCommand` switch-table selector bytes and `0xcc` padding before real code begins at `0x0059dc20`.
- `get_bytes(0x0059de40, 0x30)` shows the raw helper epilogue, return at `0x0059de4a`, range-check failure edge at `0x0059de4b`, `0xcc` alignment, then `sub_59DE60` at `0x0059de60`.
- Decompilation of `0x0059dc20` fails because IDA does not model it as a function, but bounded disassembly is complete enough to reconstruct the behavior.

Source-facing interpretation:

- Best descriptive role: `SendUserListPartySearchSettings` or `SubmitPartySearchSettingsFromDialog`.
- Best forced source placement if a route later appears: a private `UserListDialogPane.cpp` file-local/helper or private `UserListDialogPane` method, because the body uses `this+0x288` master records and the same UserListRecord/source-text model as [UID:000477] and [UID:00047G].
- Current final route: no owner/emitter. Without a caller, adding a method body through [UID:0000FN] or a static helper through [UID:0000OZ] would create source not proven reachable from the rebuilt program.

Score-blocker resolution:

- The old "needs more investigation" route state is now closed for this pass: renewed MCP did not find a route. The remaining blocker is a specific negative fact, not an unresearched gap.
- The target can improve to `87/91` because the body semantics and no-code proof are better documented. It should not exceed low 90s because original source route/name/access level and live call mechanism remain unproven.

## Evidence Standards Used

- Current by-* docs are authoritative for UID, current metadata, support names, and accepted source-facing terminology.
- Generated `auto-generated/NexusTK/social/UserListDialogPane.cpp` is lead material only; it confirms absence of UID00047B output and current generated context, not source truth.
- Executed B reports are historical leads only until rechecked. B001/B002 no-route statements were revalidated against live MCP session `2ec9c08f`.
- MCP calls were narrow and bounded: exact `lookup_funcs`, `disasm`, `get_bytes`, `xrefs_to`, `xref_query`, `find_bytes`, and targeted support lookup/xrefs.
- Numeric conversions for `0x84`, `0x85`, `0x410`, `0x414`, `0x3cb1`, and `0x3cb2` were verified with `tools/int_convert.py`.

## Evidence Checked

Live MCP session:

- `initialize` returned protocol `2025-06-18`.
- `tools/list` was checked before schema use.
- `idb_list` returned active session `2ec9c08f` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `12188`.
- `server_health` on `2ec9c08f` returned `status:"ok"`, auto-analysis ready, Hex-Rays ready, strings cache ready.

MCP calls and results:

- `lookup_funcs` for `0x0059dc20`, `0x0059de4a`, `0x0059d620`, `0x0059e3d0`, `0x0059de60`: no function at raw start/end; related function sizes confirmed.
- `disasm 0x0059dc20 max_instructions=180`: proved the full helper body, local row scan, `g_pUserPane` reads, row update, packet construction, send path, and epilogue.
- `decompile 0x0059dc20`: failed with "Decompilation failed at 0x59dc20", consistent with no IDA function object.
- `xrefs_to` / `xref_query` for `0x0059dc20`: no incoming xrefs.
- `xref_query` for selected interior labels `0x0059dc80`, `0x0059dce0`, `0x0059dd41`, `0x0059de27`, `0x0059de3a`, and `0x0059de4b`: only internal branch xrefs inside the raw helper, `fn:null`.
- `xrefs_to` / `xref_query` for `0x0059de4a`: the only ref is internal fall-through/control at `0x0059de49`.
- `find_bytes` for little-endian absolute pointers `20 dc 59 00` and `4a de 59 00`: no matches.
- `lookup_funcs` for packet/string helper callees: `0x00575380` size `0x11`, `0x00516030` size `0x6`, `0x00516220` size `0x18`, `0x00574bb0` size `0x63`, `0x005a2da0` size `0x18`.
- `xref_query` for `0x0067a748`: total `505` refs, matching current `g_pUserPane` support docs.
- `xref_query` for `0x0069b4e0`: total `12` refs, none from this raw helper body.

Representative disassembly facts:

- `0x0059dc33 mov eax, dword_67A748`; `0x0059dc3b mov al, [eax+3CB1h]` reads `g_pUserPane->m_partySearchListed` / local hunters-list state.
- `0x0059dc41 mov esi, ecx` treats incoming `ecx` as the dialog receiver.
- `0x0059dc5b call sub_5A2DA0` fills the stack name buffer used to find the local row.
- `0x0059dc60 mov eax, [esi+288h]`; loop at `0x0059dc80` calls virtual slot `[eax+0x10]` on the master-list object and compares row `+0x00e` name against the local name buffer.
- `0x0059dce6 lea esi, [ecx+210h]`; `0x0059dcec movzx eax, byte ptr [ecx+20Eh]`; `0x0059dd41 mov byte ptr [ecx+20Fh], 0`; `0x0059dd48 mov [ecx+20Eh], bl`; `0x0059dd5f call _wcscpy_s` copies `g_pUserPane+0x3cb2` into row `+0x210`.
- `0x0059dd6b push 84h; call sub_575380` writes opcode `0x84` / decimal `132` (Verified with `int_convert.py`).
- `0x0059dd7c push edi; call sub_575380` writes the selected/hunters flag byte.
- `0x0059ddc8 call WideCharToMultiByte`; `0x0059ddec call sub_575380`; `0x0059ddfc call sub_516030`; `0x0059de0a call sub_516220` append converted source text only when the flag is `1`.
- `0x0059de27 mov ecx, dword_67A7EC`; `0x0059de35 call sub_574BB0` sends the built payload.

Search-gated report evidence:

- B001 recorded best descriptive names `SubmitPartySearchSettingsFromDialog` / `SendUserListPartySearchSettings` but rejected emission without a route.
- B002 split report created the exact UID00047B child and preserved no-route proof. The live session revalidated that conclusion and adds corrected `g_pUserPane` wording.

## Claim And Incorporation Ledger

| Claim ID | Accepted claim / fact | Evidence source | Destination doc / section | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| 47B-001 | Target remains reconstructable raw helper with no owner/emitter. | Current target metadata; MCP no function/no start xref/no pointer route. | `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` metadata, Status, and No-Route / No-Code Proof. | incorporate | applied: target keeps `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++; validator `000000005525` ok. |
| 47B-002 | Set target score to `COMPLETION:87`, `CONFIDENCE:91`. | Renewed body evidence plus negative route proof; below final-source cap due no caller/original name. | Target metadata and Score Rationale. | incorporate | applied: validator `000000005525` recorded `completion_update 00047B ... 87` and `confidence_update 00047B ... 91`. |
| 47B-003 | Correct active state dependency: raw body reads `dword_67A748` / `g_pUserPane`, not `g_pUserListDialogPane`; `UserListDialogPane` is the `ecx` receiver. | Disasm `0x0059dc33`, `0x0059dc41`; [UID:0001OR]/[UID:0000QK]. | Target Behavior/Evidence; parent/file/class support; UserPane global support. | incorporate | applied: target, parent, file, class, memory global, and global alias docs now use `UserListDialogPane *this` plus `g_pUserPane+0x3cb1/+0x3cb2`; `by-class/PartySearchEditPane.md` already had `g_pUserPane + 0x3cb1` at lines 49/53/80 and was not edited. |
| 47B-004 | The row lookup scans `this+0x288` master records and compares local player name against row `+0x00e`. | Disasm `0x0059dc60-0x0059dcd8`. | Target Behavior/Evidence; parent/file/class support rows. | incorporate | applied: target and UserListDialogPane parent/file/class support docs document `this+0x288` and row `+0x00e`. |
| 47B-005 | The body mirrors `huntersListFlag` at row `+0x20e`, clears `hasSourceText` at `+0x20f`, and copies source text to row `+0x210`. | Disasm `0x0059dce6-0x0059dd5f`. | Target Behavior/Evidence; UserListDialogPane support; UserPane global typed-view rows. | incorporate | applied: target, parent/file/class support, and both `g_pCollectionData` pages record row `+0x20e/+0x20f/+0x210` and `g_pUserPane+0x3cb2`. |
| 47B-006 | Outbound packet opcode is `0x84` / decimal `132` and uses packet append helpers before send. | Disasm `0x0059dd6b-0x0059de35`; `int_convert.py`. | Target Behavior/Evidence; parent/file support; PartySearch memory summary. | incorporate | applied: target and support docs preserve opcode `0x84`/decimal `132`; `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` now says local UserPane/UserListRecord state and opcode `0x84`. |
| 47B-007 | Optional source text append is guarded by flag `bl == 1` and includes `WideCharToMultiByte` conversion. | Disasm `0x0059dd8a-0x0059de1f`. | Target Behavior/Evidence. | incorporate | applied: target behavior records the optional `WideCharToMultiByte` source-text branch. |
| 47B-008 | Send path is `dword_67A7EC` receiver and `sub_574BB0`. | Disasm `0x0059de27-0x0059de35`; `lookup_funcs 0x00574bb0`. | Target Evidence. | incorporate | applied: target behavior/evidence records `dword_67A7EC` and `sub_574BB0`. |
| 47B-009 | No IDA function object and no Hex-Rays decompile at `0x0059dc20`. | `lookup_funcs`; `decompile`. | Target No-Route / No-Code Proof. | incorporate | applied: target no-route proof records no function object and failed decompile under MCP session `2ec9c08f`. |
| 47B-010 | No incoming start xrefs and no PE pointer-pattern matches for `0x0059dc20` or `0x0059de4a`. | `xrefs_to`, `xref_query`, `find_bytes`. | Target No-Route / No-Code Proof. | incorporate | applied: target no-route proof records no incoming start xrefs and no absolute pointer-pattern route for start/end. |
| 47B-011 | Interior xrefs are internal labels only, not external route evidence. | `xref_query` selected labels. | Target No-Route / No-Code Proof. | incorporate | applied: target no-route proof records internal-only label xrefs. |
| 47B-012 | Reject class public method emission and file-local helper emission until a caller/source route is found. | Negative route proof and current generated output absence. | Target C++ disposition; file/class support notes. | incorporate | applied: target keeps blank formal C++/no illustrative C++; file/class support preserve best forced future placement but no current emitter/public API. |
| 47B-013 | Preserve rejected alternatives: not padding/switch table, not `AddUserListSourceMessage`, not `HandleUserListPacket`, not `PartySearchEditPane::OnAction`, not `UserPane` owner, not packet-helper owner, not generated-output-only source. | Current docs plus MCP boundaries and adjacent child evidence. | Target Negative Evidence; support sync where stale. | incorporate | applied: target negative evidence and support sync preserve these rejected alternatives; `PartySearchEditPane.md` already-present support lines 49/53/80 did not need edit. |
| 47B-014 | Generated `UserListDialogPane.cpp` currently has no UID00047B helper, expected for blank emitter. | Generated header `000000005507`; file content; callback validators. | Report Validator Results / generated freshness. | incorporate | applied: report validator section records generated refresh deferred for commands `000000005525`-`000000005535`; no generated file was hand-edited and absence of UID00047B output remains expected for blank emitter. |

## Positive Evidence Summary

- Real executable helper body: `0x0059dc20` begins with a normal security-cookie stack frame and runs until `retn` at `0x0059de4a`.
- Exact range is bounded: preceding `0x0059dbe3-0x0059dc20` is `OnControlCommand` switch support/padding; successor `0x0059de60` is modeled `AddUserListSourceMessage`.
- Behavior matches user-list local source update semantics: receiver `this` supplies master row list at `+0x288`; row layout matches [UID:0000FN] `UserListRecord`.
- Local-player state source is now precise: `dword_67A748` is canonical `g_pUserPane`; offsets `+0x3cb1` and `+0x3cb2` are local party-search/hunters flag and source text typed views.
- Packet construction is concrete: opcode `0x84` / decimal `132` (Verified with `int_convert.py`), selected flag byte, optional source-text bytes, and send via `dword_67A7EC` / `0x00574bb0`.
- Sibling paths corroborate semantics: [UID:000477] handles incoming `0x83/0x84` state updates, [UID:00047G] sends similar `0x84` from `PartySearchEditPane::OnAction`, [UID:00047C] posts source text, and [UID:00047R] requests source text with `0x85`.

## Negative Evidence Summary

- No IDA function object at `0x0059dc20`; `lookup_funcs` returns `Not a function`.
- `decompile 0x0059dc20` fails, so no modeled source signature or function prototype exists.
- No incoming cross-reference to `0x0059dc20`.
- No pointer-pattern match for little-endian `0x0059dc20` (`20 dc 59 00`) or `0x0059de4a` (`4a de 59 00`).
- Interior label xrefs are internal-only and `fn:null`; they do not establish reachability.
- `xrefs_to(0x0069b4e0)` shows the known `g_pUserListDialogPane` refs, but none are from this raw helper body, rejecting the older wording that this helper reads `g_pUserListDialogPane` storage.
- The generated `UserListDialogPane.cpp` has no emitted UID00047B helper; this is expected under blank emitter and does not prove deadness, but it rejects any claim that generated output currently routes the helper.
- No source text proves original name, public/private access level, or whether the original compiler reached this as a local helper, dead retained code, function pointer target, or unmodeled callback.

## Ranked Ownership Analysis

1. [UID:0000OZ] `UserListDialogPane.cpp` / [UID:0000FN] `UserListDialogPane`: best forced source placement if a route appears. The body is `__thiscall`-shaped on `UserListDialogPane *this`, uses `this+0x288`, and belongs semantically to the user-list/party-search source family. Rejected for current emitter because no caller/source route proves this code should appear in rebuilt output.
2. [UID:0000A7] `PartySearchEditPane`: strong semantic sibling, but rejected as owner. [UID:00047G] is the live documented action handler for the editable party-search dialog; UID00047B does not use a `PartySearchEditPane *this` layout and starts before `AddUserListSourceMessage`, not in the PartySearch class range.
3. [UID:0000P1] `UserPane`: dependency owner only. UID00047B reads `g_pUserPane+0x3cb1/+0x3cb2`, but the writable row and list state are in the UserListDialogPane receiver. UserPane owns the global storage, not this helper body.
4. Packet helper / sender module: dependency only. The body calls packet append and send helpers, but packet helpers do not own social user-list row semantics.
5. No-owner/non-emitting raw helper: selected current disposition. It preserves real behavior and route-negative proof without inventing an API.

## Source Placement

No source emission is recommended now. The report should still name the best future source shape so the next route-finding pass has a stable target:

- Descriptive name candidates: `SendUserListPartySearchSettings`, `SubmitPartySearchSettingsFromDialog`, or `SendLocalUserListSourceUpdate`.
- If a route is later found from a method/callback that passes `UserListDialogPane *` in `ecx`, place the body under `NexusTK/social/UserListDialogPane.cpp`, likely as a private `UserListDialogPane` method or file-local helper rather than a public API.
- Do not create a new source file for this single helper. The behavior is tightly coupled to `UserListRecord`, `g_pUserPane` local state, and the existing user-list source file.

## First-Draft C++ Recommendation

Formal C++ should remain blank for [UID:00047B].

Target-specific no-code proof: the binary body is understood well enough to describe, but it has no proven call route. Adding even a plausible private method or static helper would cause generated source to contain a callable body whose original reachability and invocation site are not documented. The function also depends on packet helper and list/container APIs whose source-facing declarations are only partially standardized for nearby blank-emitter methods [UID:000477] and [UID:00047G]. Until a route is found, the correct formal `RECONSTRUCTION_CPP CODE` block is empty.

No illustrative C++ is supplied in this report because the workflow requires any C++ text to be formal insertion-ready. The current recommendation is an exact no-code proof, not a draft body.

## Final Recommendation

During callback, update only documentation, not generated files:

- Target [UID:00047B]: set `COMPLETION:87`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:TRUE`, keep blank `EMITTER_UIDS`, keep blank formal C++.
- Replace stale/ambiguous `g_pUserListDialogPane-local state` wording with precise state split: `ecx`/`esi` is the `UserListDialogPane *this` receiver, while `dword_67A748` is canonical `g_pUserPane` local-player state.
- Add current MCP session `2ec9c08f` evidence for raw body, range, no function object, no xrefs, no pointer pattern, row field updates, opcode `0x84`, and send path.
- Preserve no-route/no-emitter conclusion and rejected alternatives.

## Recommended Target Doc Changes

Target file: `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md`.

Apply these exact dispositions if accepted:

- Metadata: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Item Summary: change from "reads `g_pUserListDialogPane`-local state" to "uses `UserListDialogPane *this` plus `g_pUserPane` local state".
- Status: classify as source-authored raw helper with no current caller/source route; not padding, not switch table, not modeled IDA function.
- Behavior/Evidence: add disassembly-backed facts for `g_pUserPane+0x3cb1`, local player name copy, `this+0x288` list scan, row `+0x00e` compare, row `+0x20e/+0x20f/+0x210` updates, opcode `0x84` write, optional `WideCharToMultiByte` source text append, packet helper calls, `dword_67A7EC` send.
- No-Route / No-Code Proof: add live session `2ec9c08f`, no function object, failed decompilation, no `xrefs_to(0x0059dc20)`, no absolute pointer-pattern hits, internal-only label xrefs, generated output absence, and exact reason formal C++ remains blank.
- Related Docs: add/confirm [UID:0001OR] and [UID:0000QK] for `g_pUserPane` support, alongside existing user-list docs.

## Recommended Support Doc Changes

Edit support docs only if stale at callback time:

- `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`: update the UID00047B child row and no-route notes to say `this`/`UserListDialogPane` receiver plus `g_pUserPane+0x3cb1/+0x3cb2`, not `g_pUserListDialogPane-local state`.
- `by-file/UserListDialogPane.md`: update the no-route raw helper row if it still lacks current route-negative detail or still implies `g_pUserListDialogPane` storage. Preserve the file as best forced future source placement but no current emitter.
- `by-class/UserListDialogPane.md`: update the exact child note if stale; preserve that UID00047B remains no-owner/raw and is not promoted to a public class method.
- `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md`: update only if its summary still says "writes `g_pUserListDialogPane` local source state"; the accepted wording should be "writes/mirrors local UserPane/UserListRecord party-search/source state and sends opcode `0x84`".
- `by-class/PartySearchEditPane.md`: no required change unless the support row lacks the now-correct `g_pUserPane+0x3cb1` terminology.
- `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` and `by-global/g_pCollectionData.md`: likely already present at same-or-greater detail for `g_pUserPane+0x3cb1/+0x3cb2`; mark `already-present` if unchanged.
- `auto-generated/NexusTK/social/UserListDialogPane.cpp`: do not edit. Generated absence of UID00047B remains expected until a future route/emitter is accepted and validator refreshes output.

## Score And Metadata Recommendation

Recommended target metadata:

- `COMPLETION:87`: up from `84` because current MCP evidence now documents the complete raw body, exact state split, row-field updates, packet build/send, no function object, pointer-pattern negative proof, and source-placement decision.
- `CONFIDENCE:91`: up from `90` because current MCP revalidates the earlier no-route conclusion and corrects the stale `g_pUserListDialogPane` wording. Keep below `95` because no original name, direct caller, source API, or function-pointer route is proven.
- `CANONICAL_OWNER:NONE`: unchanged because ownership cannot pass the route gate.
- `RECONSTRUCTABLE:TRUE`: unchanged because the bytes are source-authored behavior that may need source representation if reachability is later found.
- `EMITTER_UIDS:` blank: unchanged because no safe emitter route exists.
- Formal C++: blank by exact no-code proof.

## Open Questions With Attempted Resolution

- Is `0x0059dc20` reachable through a direct code xref? Attempted with live `xrefs_to`/`xref_query`; result no incoming xref to start.
- Is it reachable through a PE absolute pointer pattern? Attempted with `find_bytes` for `20 dc 59 00`; result no matches.
- Is it an IDA-modeled function with a recoverable signature? Attempted with `lookup_funcs` and `decompile`; result not a function and decompilation failed.
- Is it really `g_pUserListDialogPane` state? Attempted with disassembly and global xrefs; result no `0x0069b4e0` use in the raw helper. The raw body uses `this` plus `g_pUserPane`.
- Is it dead code? Unresolved. Negative route evidence does not prove deadness because IDA may miss nonstandard callback/jump-table routes; therefore keep reconstructable raw documentation rather than ignoring it.
- Can first-draft C++ be emitted now? Resolved no. Behavior is clear, but route and API shape are not.

## Validator Results

Callback scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* doc. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, generated/manual coverage edit, validator-state edit, or supervisor-ledger edit was run.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` | `python .\tools\validator.py --mode file --file by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md --apply --queue-timeout 240` | `000000005525` | `2026-07-03T15:10:12-04:00` | `0` | `1` | completion/confidence updated to `87/91`; UID links/reference index updated; projected stats updated; `generated_refresh: deferred`. |
| `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md --apply --queue-timeout 240` | `000000005526` | `2026-07-03T15:10:13-04:00` | `0` | `1` | Existing `missing_ref_uid` warnings for `0003FE/0003FF/0003FG/0003FH/0003FI/0003FJ`; projected stats updated; `generated_refresh: deferred`. |
| `by-file/UserListDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/UserListDialogPane.md --apply --queue-timeout 240` | `000000005527` | `2026-07-03T15:10:15-04:00` | `0` | `1` | Existing `missing_ref_uid 0003US`; projected stats updated; `generated_refresh: deferred`. |
| `by-class/UserListDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/UserListDialogPane.md --apply --queue-timeout 240` | `000000005529` | `2026-07-03T15:10:26-04:00` | `0` | `1` | Existing `missing_ref_uid 0003E6/0003US`; projected stats updated; `generated_refresh: deferred`. |
| `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` | `python .\tools\validator.py --mode file --file by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md --apply --queue-timeout 240` | `000000005531` | `2026-07-03T15:10:28-04:00` | `0` | `1` | Projected stats updated; `generated_refresh: deferred`; no target-specific warnings. |
| `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md --apply --queue-timeout 240` | `000000005533` | `2026-07-03T15:10:30-04:00` | `0` | `1` | Existing `missing_ref_uid` warnings for `0003ZR/0003U9/0003UC/0003UD`; UID00047B reference index added; projected stats updated; `generated_refresh: deferred`. |
| `by-global/g_pCollectionData.md` | `python .\tools\validator.py --mode file --file by-global/g_pCollectionData.md --apply --queue-timeout 240` | `000000005535` | `2026-07-03T15:10:32-04:00` | `0` | `1` | Existing `missing_ref_uid` warnings for `0003UC/0003ZR/0003U9/0003UD`; UID00047B reference index added; projected stats updated; `generated_refresh: deferred`. |

Generated freshness observations:

- Validator output for all edited by-* docs reported `generated_refresh: deferred` with command ids `000000005525`, `000000005526`, `000000005527`, `000000005529`, `000000005531`, `000000005533`, and `000000005535`.
- `auto-generated/NexusTK/social/UserListDialogPane.cpp` contained no UID00047B helper during the report-only evidence pass, and that remains expected because UID00047B still has blank `EMITTER_UIDS` and blank formal C++. No generated output was hand-edited.

Read-only historical tool note from report-only evidence gathering:

- First `int_convert.py` attempt passed all numbers as one argument and returned "Invalid number"; no files changed.
- Successful separate conversions: `0x84 -> 132`, `0x85 -> 133`, `0x410 -> 1040`, `0x414 -> 1044`, `0x3cb1 -> 15537`, `0x3cb2 -> 15538`.

## Changed Files

Callback changed files:

- `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md`
- `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`
- `by-file/UserListDialogPane.md`
- `by-class/UserListDialogPane.md`
- `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md`
- `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
- `by-global/g_pCollectionData.md`
- `tools/leaser/Agents/Agent-B004/research/00047B-UserListDialogPaneLocalSourceUpdateSendHelperRaw-source-quality.md`

Already-present support inspected and left unchanged:

- `by-class/PartySearchEditPane.md`: lines 49, 53, and 80 already use `g_pUserPane + 0x3cb1` / historical `g_pPlayerData+0x3cb1` for party-search state and opcode `0x84`; no UID00047B contradiction remained.

No generated files, manual/generated `-coverage-report.md` files, validator state, report lifecycle state, archives, or supervisor ledgers were manually edited. Scoped validators updated projected stats/reference indexes as validator-owned side effects.

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` and support docs only for the edit/validator batch. Proof: leased target, parent, file, class, PartySearch memory, memory global, and global alias docs as B004; release attempt after validation reported `Rejected[No active lease]` for each, and `current_leases.md` search showed no active B004 lease entries.
- [x] Target metadata: set `COMPLETION:87`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++. Proof: target validator `000000005525` recorded completion/confidence updates and exited 0/ok 1.
- [x] Target active evidence: added MCP session `2ec9c08f`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, server health ok, no function object, decompile failure, exact range bytes, and no start xrefs/pointer-pattern route.
- [x] Target behavior: replaced ambiguous `g_pUserListDialogPane-local state` wording with `UserListDialogPane *this` receiver plus `g_pUserPane` local state; documented `g_pUserPane+0x3cb1/+0x3cb2`.
- [x] Target row evidence: documented `this+0x288` master-list scan, row `+0x00e` name compare, row `+0x20e` flag mirror, row `+0x20f` source-present clear, row `+0x210` source-text copy.
- [x] Target packet evidence: documented opcode `0x84` / decimal `132`, packet append helpers, optional `WideCharToMultiByte` source-text branch, range-check edge, `dword_67A7EC` send receiver, and `sub_574BB0` send call.
- [x] Preserved rejected alternatives/negative evidence: not padding/switch table, not direct `AddUserListSourceMessage`, not `HandleUserListPacket`, not `PartySearchEditPane::OnAction`, not `UserPane` owner, not packet-helper owner, no public method route, no file-local emitter until caller proof appears.
- [x] Support sync: updated [UID:0001KI] parent row/no-route notes with `this`/`UserListDialogPane` receiver, `g_pUserPane+0x3cb1/+0x3cb2`, row offsets, opcode `0x84`, and no public/API route; validator `000000005526` exited 0/ok 1.
- [x] Support sync: updated [UID:0000OZ] file page UID00047B no-route raw helper row/source-output note with route-negative detail and corrected state split; validator `000000005527` exited 0/ok 1.
- [x] Support sync: updated [UID:0000FN] class child/no-route note and kept UID00047B out of public class API; validator `000000005529` exited 0/ok 1.
- [x] Support sync: updated [UID:00047G] memory page to remove stale `g_pUserListDialogPane` local source wording and use local UserPane/UserListRecord party-search/source state with opcode `0x84`; validator `000000005531` exited 0/ok 1.
- [x] Support sync: inspected [UID:0000A7] `by-class/PartySearchEditPane.md` and left unchanged as already-present; proof lines 49/53/80 already use `g_pUserPane + 0x3cb1` / historical alias and opcode `0x84`.
- [x] Support sync: updated [UID:0001OR] and [UID:0000QK] with `g_pUserPane+0x3cb2` typed-view wording tied to UID00047B; validators `000000005533` and `000000005535` exited 0/ok 1.
- [x] Ran scoped validators from `source-3/project-documentation` for every edited by-* file. Proof: Validator Results table records command, command id, timestamp, exit code, ok count, warnings, and generated-refresh state for all seven edited by-* docs.
- [x] Did not edit generated files or any manual/generated `-coverage-report.md`; generated `UserListDialogPane.cpp` absence of UID00047B remains expected because target is blank-emitter/no-code.
- [x] Updated this report's Claim And Incorporation Ledger after callback with `applied`/`already-present` proof for every accepted claim; no accepted item remains blocked or unapplied.
- [x] Updated this checklist after callback with validator command id, timestamp, exit code, ok count, warnings/errors, generated-refresh state, changed files, and lease release/no-active-lease proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000005553","destination_path":"executed-b-agent-research/B004/00047B-UserListDialogPaneLocalSourceUpdateSendHelperRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00047B-UserListDialogPaneLocalSourceUpdateSendHelperRaw-source-quality.md","timestamp":"2026-07-03T15:20:13-04:00","uid":"00047B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
