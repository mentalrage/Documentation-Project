** TARGET-REPORT-UID:0002QB **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Source-Quality Report: [UID:0002QB] RawPasswordChangePacketWithAccount

## Assignment
- Agent: B005
- Assignment: report-only source-quality research for [UID:0002QB]
- Target: `by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md`
- Report path: `tools/leaser/Agents/Agent-B005/research/0002QB-RawPasswordChangePacketWithAccount-source-quality.md`
- Mode: report-only. No by-* docs, generated files, project-level files, validator state, IDA DB, tool-state files, leases, or `-coverage-report.md` files were edited.

## Current Target State
- Current target metadata on disk:
  - `COMPLETION:88`
  - `CONFIDENCE:89`
  - `CANONICAL_OWNER:0000I3`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000I3`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - Formal `RECONSTRUCTION_CPP CODE` block: blank
- Current target summary still carries stale wording: it calls the helper a "four-string opcode `0x26` sender" and says the cap includes "no direct Wave2 record." Current MCP evidence shows this retained body serializes three wide string fields plus a fourth wide string converted with `_wtol` into a 32-bit numeric field; "Wave2" wording should be replaced with current MCP/session provenance.
- The target already has useful B004-era evidence for owner/source route, active sibling separation, and no-route checks, but the B004 formal-C++-blank/no-code proof is superseded by this B005 report. Preserve B004's no-function/no-xref/no-pointer/no-active-route evidence as confidence caps and historical audit evidence; do not leave target/support language saying the helper must keep formal C++ blank until a future route is found.

## MCP Provenance
- MCP endpoint used by the current assignment: `http://127.0.0.1:13337/mcp`
- Active database/session: `80de0a67`
- `idb_list`: one active adopted worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input module `NexusTK.exe`, not analyzing.
- `server_health database=80de0a67`: `status=ok`; imagebase `0x400000`; Hex-Rays ready; auto-analysis ready; strings cache ready.
- IDB file SHA-256: `18D867EF297940CA8831639DB84F010F534BA9F4A609D148EB9B14B0D355E291`
- Backing PE SHA-256 from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- 2026-06-25 correction recheck: the same session `80de0a67` is active (`idb_list` one adopted worker, PID/worker PID `26892`, `is_analyzing:false`); `server_health database=80de0a67` returned `status=ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with size `2067`.

## Evidence Checked
- Read the current target page, parent packet-helper aggregate [UID:00022W] `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`, active sibling [UID:0002QC] `by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md`, submit/core page [UID:0002QA] `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`, `by-file/ChangePasswordDialogPane.md`, `by-class/ChangePasswordDialogPane.md`, PacketBuffer scalar helper [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`, memmove wrapper [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`, support global [UID:0000Q5] `by-global/g_packetSender.md`, `_wtol` CRT wrapper [UID:0001O5], and `by-meta/client_network.md`.
- Treated the previous B004 report and current target prose as leads only. The current pass rechecked function/range/body, route, caller, callee, pointer, sibling evidence, and the `sub_516220` copy-helper classification through MCP session `80de0a67`.
- Checked analogous current documentation precedents:
  - [UID:0002S8] `SelfSaveInputPaneSendSelfSavePacketRaw` carries formal source C++ despite a no-route raw-helper status because the packet body is exact, source-owned, and the no-route evidence is a liveness confidence cap.
  - [UID:00030E] `AddItemDialogSubmitPacketHelper` carries formal source C++ for a no-direct-xref helper when source placement, packet layout, and helper names are defensible.
  - [UID:00030H] `WebBoardDialogOldBrowserControlTeardownRaw` remains blank because the retained old-browser teardown is already covered by live close paths and lacks a standalone source call path. [UID:0002QB] differs: it is a self-contained source-family packet sender and is not covered by an accepted live-source body that includes the fourth numeric account/id field.

## MCP Function, Range, and Route Evidence
- `lookup_funcs 0x004fe790`: no function object at the target start.
- `lookup_funcs 0x004fe9c9` and `lookup_funcs 0x004fe9d1`: no function object at the raw return or padding boundary.
- `lookup_funcs 0x004fe560`: active submit/helper function `sub_4FE560`, size `0x222`.
- `lookup_funcs 0x004fe9e0`: active sibling function `sub_4FE9E0`, size `0x202`.
- `lookup_funcs 0x004febf0`: next password-change function `sub_4FEBF0`, size `0x221`.
- `lookup_funcs 0x004fee40`: later function `sub_4FEE40`, size `0x1ff`; no xrefs to the function start in the current MCP result.
- 2026-06-25 correction recheck `lookup_funcs`: `0x00516220` is real function `sub_516220`, size `0x18`; `0x004fe790` is not a function; `0x004fe560` is `sub_4FE560`, size `0x222`; `0x004fe778` resolves inside `sub_4FE560`; `0x004fe9e0` is `sub_4FE9E0`, size `0x202`.
- `xrefs_to 0x004fe790`: zero xrefs.
- 2026-06-25 correction recheck `xrefs_to`: `0x004fe790` still has `xref_count:0`; `0x004fe9e0` still has the one code xref at `0x004fe778` inside `sub_4FE560`.
- `xref_query to 0x004fe790`: zero code/data/all xrefs.
- `xref_query to 0x004fe9d1`: zero code/data/all xrefs.
- `find_bytes 90 E7 4F 00`: zero current matches for the little-endian VA of the raw helper start.
- `find_bytes 90 E7 4F`: zero current matches for the three-byte low VA pattern.
- Bounded entity query over `0x004fe400-0x004ff100` lists functions around the island but no named global/function record for the target raw start. The relevant neighbors are `sub_4FE560`, `sub_4FE9E0`, `sub_4FEBF0`, `sub_4FEE40`, and `sub_4FF040`.

## MCP Body Evidence
- `decompile 0x004fe790` fails because the target is not an IDA function object. This is expected and should be documented as raw/no-function state, not as a reason to leave a reconstructable emitter blank.
- `disasm 0x004fe790` shows a complete function-shaped body:
  - Standard prologue and security-cookie setup at `0x004fe790`.
  - Four stack arguments saved from `[ebp+8]`, `[ebp+0xc]`, `[ebp+0x10]`, and `[ebp+0x14]`.
  - Three wide-length scans for the first three arguments.
  - Fourth argument parsed by CRT `_wtol` (`unknown_libname_24`) at `0x004fe825`, then serialized later as a 32-bit integer.
  - Opcode `0x26` written through `PacketBufferWriteUInt8` at `0x004fe837`/`0x004fe839`.
  - Three `WideCharToMultiByte` calls with destination bound `0x100`, one for each text field.
  - Each converted text field is rangechecked against `0x100`, locally NUL-terminated, length-prefixed with `PacketBufferWriteUInt8`, and copied into the packet buffer with the shared copy helper.
  - Numeric value written with `PacketBufferWriteUInt32BE` at `0x004fe98b`.
  - Final packet length is checked against `0x100`; failure routes to `___report_rangecheckfailure` at `0x004fe9cc`.
  - `dword_67A7EC` is loaded as the packet sender receiver at `0x004fe99e`.
  - Final local terminator is written outside the sent length before `QueueAndSendPacket` at `0x004fe9b4`.
  - Security-cookie epilogue and `retn 10h` at `0x004fe9c9`.
  - `0x004fe9d1-0x004fe9df` is alignment padding before successor [UID:0002QC] at `0x004fe9e0`.
- `insn_query` over `0x004fe790-0x004fe9d1` scanned 165 instructions with no truncation and found the full call set:
  - `sub_516030`
  - `_wtol` / `unknown_libname_24`
  - four `PacketBufferWriteUInt8` calls
  - three `WideCharToMultiByte` calls
  - three packet payload copy calls
  - one `PacketBufferWriteUInt32BE`
  - one `QueueAndSendPacket`
  - `@__security_check_cookie@4`
  - `___report_rangecheckfailure`
- `get_bytes` around `0x004fe780` confirms the previous helper tail and fourteen `0xcc` bytes before the raw prologue at `0x004fe790`.
- `get_bytes` around `0x004fe9a0` confirms sender load, send, epilogue, `retn 10h`, rangecheck tail, fifteen `0xcc` bytes, and successor prologue at `0x004fe9e0`.

## Active Sibling and Caller Evidence
- `analyze_function 0x004fe560` confirms the live submit path reads controls `3`, `4`, `5`, and `6`, validates that the new password contains a digit, compares controls `5` and `6`, and on success calls [UID:0002QC] at `0x004fe778`.
- The live submit call is `sub_4FE9E0(v15, v16, v18)`: only the first three values are sent. The raw four-argument target is not called by the current submit path.
- `xrefs_to 0x004fe9e0`: one direct code xref from `0x004fe778` in `sub_4FE560`.
- 2026-06-25 `search_text` over `0x004fe560-0x004fe782` reconfirmed the only submit-path sender call as `.text:004FE778 call sub_4FE9E0`.
- `decompile 0x004fe9e0` confirms [UID:0002QC] is the active three-text-field opcode `0x26` sender. It has the same `WideCharToMultiByte`, one-byte length, packet-copy, and send pattern, but it omits `_wtol` and `PacketBufferWriteUInt32BE`.
- This relationship should be documented as a retained raw source-family variant. [UID:0002QC] is the active route; [UID:0002QB] preserves a related packet builder with an additional numeric account/id field.

## Helper and Type Evidence
- `sub_575380` is already documented by PacketBuffer helper docs as `PacketBufferWriteUInt8` with raw value-first ABI.
- `sub_5753F0` is already documented as `PacketBufferWriteUInt32BE`, also raw value-first.
- `sub_516220` is best represented in this target's formal C++ as `memmove`, not as a PacketBuffer scalar helper. Current MCP `analyze_function 0x00516220` returns prototype `void *__stdcall(void *, void *Src, size_t Size)`, decompile `return memmove(a1, Src, Size);`, one basic block, and assembly `push Size; push Src; push destination; call _memmove; retn 0Ch`. Current docs [UID:0001BH] name it `MemmoveWrapper`, attach it to the MemoryMan utility island pending final helper naming, and describe it as a thin `memmove(destination, source, size)` wrapper. The feature packet source block should therefore call `memmove(...)` for payload byte copies while citing [UID:0001BH] as the support wrapper; if a later project-wide MemoryMan API standardizes `MoveMemory`/`CopyBytes`, that should be a coordinated support-doc change, not a PacketBuffer ownership change for this target.
- 2026-06-25 `search_text` finds the same three `sub_516220` payload-copy sites in the raw helper (`0x004fe8a0`, `0x004fe907`, `0x004fe975`) and in the active sibling (`0x004feacf`, `0x004feb36`, `0x004feba0`), supporting the source-facing interpretation as repeated payload byte copies after `WideCharToMultiByte`.
- `dword_67A7EC` is the existing packet sender global. [UID:0000Q5] `by-global/g_packetSender.md` is a support doc only: it should be checked or updated only if it contradicts this report's use of `g_packetSender` / Socket-owned `Socket *` sender state. It is not the submit/core page, not a direct owner candidate for [UID:0002QB], and not a routine target edit for this report.
- `_wtol` is supported by [UID:0001O5] `by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md` as a CRT wrapper/non-project helper.
- The fourth argument's exact original source name is not recoverable from callers because no route survives. The best source-facing inference is an account/id text field converted with `_wtol` and serialized as a big-endian 32-bit value. This should remain a documented confidence caveat, but it no longer blocks a formal first-draft reconstruction because the serialized type and packet behavior are exact.

## Positive Evidence
- The body is complete, self-contained, stack-cleaning, security-cookie protected, and source-function-shaped despite missing an IDA function object.
- Packet layout is exact:
  - opcode `0x26`
  - first converted text field length byte and payload
  - second converted text field length byte and payload
  - third converted text field length byte and payload
  - fourth wide argument parsed by `_wtol` and serialized as a 32-bit big-endian integer
- Boundary evidence is exact: padding before the raw start and padding after the raw return isolate the helper from [UID:0002QC].
- Owner route remains coherent with [UID:0000I3] `ChangePasswordDialogPane`: same file/class source family as the active sibling and submit handler.
- Current support docs already reject Socket/PacketBuffer/ProtocolSend as direct owners; MCP evidence supports preserving those rejections.
- Current precedents show no-route packet helpers can carry formal C++ when the packet layout, helper names, and owner route are source-quality. [UID:0002QB] meets that standard.

## Negative Evidence and Confidence Caps
- No IDA function object exists at `0x004fe790`.
- No current xrefs to the raw helper start or tail boundary survive.
- No current little-endian VA byte pattern for the raw helper start was found through MCP `find_bytes`.
- The active submit route calls [UID:0002QC], not [UID:0002QB].
- The fourth parameter's original source spelling is not proven by a caller. `accountIdText` is a defensible source-facing name because the field is wide text parsed through `_wtol` and serialized through `PacketBufferWriteUInt32BE`, but it remains an inference.
- These negatives cap confidence and must stay in the target/support docs. They supersede rather than preserve B004's target-change conclusion: the negative evidence should no longer be phrased as a standing formal-C++-blank/no-code proof because the target is reconstructable, has an emitter route, is above the C++ gate, and has exact behavior. Any support-doc text that says [UID:0002QB] must remain blank until a future route is found should be revised to say B004's no-code proof is superseded by B005's source-ready retained-helper formal block, while B004's no-route evidence remains valid as confidence cap.

## Ownership and Source-Placement Ranking
1. [UID:0000I3] `ChangePasswordDialogPane` / `ChangePasswordDialogPane.cpp` - recommended. The raw helper sits in the same source-family island as the active dialog submit and active password-change sender, uses the same opcode, and serializes dialog/account/password fields.
2. [UID:00022W] `ChangePasswordDialogPacketHelpers` aggregate - support context only. It spans related packet helpers but should remain non-emitting for aggregate coverage and not steal the child helper's source route.
3. Socket / [UID:0000NS] - rejected as direct owner. Socket owns the send queue/global lifetime; the packet layout and feature opcode belong to the dialog feature. [UID:0000Q5] `g_packetSender` is only the support global page to check if contradictory, not an owner/support target requiring routine edits.
4. PacketBuffer / [UID:0000M8] - rejected as direct owner. PacketBuffer owns scalar field helpers only.
5. ProtocolSend or a shared networking file - rejected. No current route, global naming, or support-doc precedent proves a central source file for this feature packet.
6. Active sibling [UID:0002QC] as a covered-by replacement - rejected. [UID:0002QC] omits `_wtol` and the 32-bit account/id field, so it does not cover this raw helper's full behavior.
7. No-owner/non-emitting - rejected. The target is source-function-shaped, feature-owned, reconstructable, and current rule/precedent supports a formal first-draft helper despite liveness negatives.

## Score and Metadata Recommendation
- Recommended target metadata:
  - `COMPLETION:90`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000I3`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000I3`
  - `EMITTER_POSITION_OPTIONAL:` blank
- Rationale:
  - Completion should rise above `88` because the current pass resolves the old no-code disposition: the helper can carry an implementation-ready formal reconstruction block with exact opcode, field order, helper usage, rangechecks, numeric field write, final length, and sender call.
  - Confidence should rise modestly from `89` to `90`, not higher, because no call route or exact fourth-field source spelling survives. Those are confidence caps, not implementation blockers.
  - No owner/emitter reroute is recommended. [UID:0000I3] remains the best source owner/emitter.

## Formal RECONSTRUCTION_CPP CODE Recommendation
The target should receive the following exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
static void __stdcall SendPasswordChangeRequestWithAccountId(
    const wchar_t* accountName,
    const wchar_t* currentPassword,
    const wchar_t* newPassword,
    const wchar_t* accountIdText)
{
    char packet[0x100];
    char converted[0x100];

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short currentPasswordLength = static_cast<short>(wcslen(currentPassword));
    short newPasswordLength = static_cast<short>(wcslen(newPassword));
    long accountId = _wtol(accountIdText);

    PacketBufferWriteUInt8(0x26, packet);

    int accountNameByteLength = WideCharToMultiByte(0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    unsigned int packetLength = static_cast<unsigned int>(accountNameByteLength + 2);

    int currentPasswordByteLength = WideCharToMultiByte(0, 0, currentPassword, currentPasswordLength, converted, 0x100, NULL, NULL);
    if (currentPasswordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[currentPasswordByteLength] = 0;
    PacketBufferWriteUInt8(currentPasswordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, currentPasswordByteLength);
    packetLength += static_cast<unsigned int>(currentPasswordByteLength + 1);

    int newPasswordByteLength = WideCharToMultiByte(0, 0, newPassword, newPasswordLength, converted, 0x100, NULL, NULL);
    if (newPasswordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[newPasswordByteLength] = 0;
    PacketBufferWriteUInt8(newPasswordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, newPasswordByteLength);
    packetLength += static_cast<unsigned int>(newPasswordByteLength + 1);

    PacketBufferWriteUInt32BE(accountId, packet + packetLength);
    packetLength += 4;
    if (packetLength >= 0x100)
        __report_rangecheckfailure();

    packet[packetLength] = 0;
    QueueAndSendPacket(g_packetSender, packet, packetLength);
}
```

Notes for implementation review:
- This is intended as the target's formal block, not prose-only sample code.
- `accountIdText` is the only source-facing name with residual uncertainty; the body proves a wide text input parsed through `_wtol` and written as a 32-bit packet value.
- `memmove` is intentional for the three payload copies. It is the source-facing representation of [UID:0001BH] `MemmoveWrapper` / `sub_516220`, which current MCP proves is a one-basic-block wrapper around CRT `_memmove`; this is not a PacketBuffer scalar helper.
- The code intentionally does not connect this helper to the active submit path. Current MCP evidence says [UID:0002QC] remains the active submit sender.

## Recommended Target and Support Doc Changes
- `by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md`
  - Apply `90/90`, keep owner/emitter/reconstructable as above.
  - Replace stale "four-string" and "Wave2" wording with current MCP `80de0a67` evidence.
  - Add the exact formal C++ block above.
  - Preserve no-function/no-xref/no-pointer and no-active-route negatives as final-audit/confidence caps rather than no-code blockers; add an explicit historical note that the B004 formal-C++-blank/no-code proof is superseded by this B005 formal block.
  - Document exact packet layout, `_wtol` fourth-field conversion, three `WideCharToMultiByte` calls, `0x100` rangechecks, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, payload copies through [UID:0001BH] / `memmove`, `g_packetSender`, and final send length.
- `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`
  - This is [UID:00022W], the parent packet-helper aggregate. Update [UID:0002QB] child row/reconstruction notes from B004 blank-C++/no-code disposition to retained raw source-family helper with formal first-draft C++.
  - Preserve the aggregate as non-emitting/mixed packet-helper context.
  - Preserve [UID:0002QC] as active submit route and [UID:0002QB] as no-route retained helper.
- `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`
  - This is [UID:0002QA], the core submit page. Keep the submit route pointed to [UID:0002QC].
  - Add or update the distinction that [UID:0002QB] now has formal retained-helper reconstruction but no active submit call.
- `by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md`
  - If stale wording implies [UID:0002QB] must stay blank or cannot be reconstructed, update it.
  - Otherwise, mark already sufficient: this sibling remains the active three-text-field sender and does not cover the numeric account/id helper.
- `by-file/ChangePasswordDialogPane.md`
  - Update packet-helper inventory to say [UID:0002QB] is ChangePasswordDialogPane-owned retained opcode `0x26` helper with formal first-draft C++ and no active route; [UID:0002QC] remains active.
- `by-class/ChangePasswordDialogPane.md`
  - Update method notes similarly, including three text fields plus a `_wtol`/32-bit numeric account/id field and unresolved original fourth-field spelling.
- `by-meta/client_network.md`
  - Add or update a ChangePasswordDialogPane feature-packet note: opcode `0x26` has an active three-field sender and a retained raw account/id variant; PacketBuffer/Socket own shared helpers only; feature packet layout stays with the dialog owner.
- Support docs to check only if contradictory:
  - [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: should remain the PacketBuffer scalar writer support page for `PacketBufferWriteUInt8` and `PacketBufferWriteUInt32BE`; no routine edit expected.
  - [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`: should remain the support page for `sub_516220` / `memmove` payload copies; no routine edit expected unless it contradicts using `memmove` in target formal C++.
  - [UID:0000Q5] `by-global/g_packetSender.md`: support global only; check or update only if it contradicts Socket-owned `g_packetSender` / `Socket *` sender use.
  - [UID:0001O5] `_wtol` CRT wrapper support: no routine edit expected unless stale contradictory wording appears.

## Coverage And Generated-Report Handling
Do not edit `by-memory/-coverage-report.md`, `auto-generated/-ag-*`, generated C++ output, project-level files, or validator state during B-agent implementation. No explicit manual coverage-report row is required by this report. If accepted, source metadata and `Item Summary` changes in [UID:0002QB] should drive validator-owned generated by-memory auto coverage after the scoped target validator runs.

## Expected Validators After Implementation
Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:
- `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md --apply --queue-timeout 240` only if changed.
- `python .\tools\validator.py --mode file --file by-file\ChangePasswordDialogPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class\ChangePasswordDialogPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-meta\client_network.md --apply --queue-timeout 240` if changed.
- Conditional support-doc validators only if contradictions are found and the support docs are changed:
  - `python .\tools\validator.py --mode file --file by-memory\0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x00516220-0x00516238.MemmoveWrapper.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-global\g_packetSender.md --apply --queue-timeout 240`

## Implementation Tracking Checklist
- [x] Target metadata in [UID:0002QB] `by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md`: updated to `COMPLETION:90`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000I3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000I3`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target header now has `90/90`; validator command `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md --apply --queue-timeout 240`, command_id `000000000710`, timestamp `2026-06-25T00:19:37-04:00`, exit `0`, `ok:1`, generated_refresh `deferred`.
- [x] Target formal C++ in [UID:0002QB]: inserted the exact `SendPasswordChangeRequestWithAccountId` formal `RECONSTRUCTION_CPP CODE` block from this report. The block keeps all three payload copies as `memmove(...)`; target prose ties those calls to [UID:0001BH] `MemmoveWrapper` / `sub_516220`, and no PacketBuffer scalar helper substitution was made.
- [x] Target evidence prose in [UID:0002QB]: replaced stale "four-string" and direct "Wave2" wording with current MCP `80de0a67` evidence; documented exact opcode `0x26` layout, three `WideCharToMultiByte` conversions, `0x100` rangechecks, `_wtol` fourth-field numeric conversion, `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, [UID:0001BH] / `memmove`, [UID:0000Q5] / `g_packetSender`, final send length, no-function/no-xref/no-pointer/no-active-route evidence, and confidence-cap rationale. 2026-06-25 post-worker-restart verification retry: the active E-path target `Item Summary` was checked before validation and already matched the accepted text, then the normal required validator command `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md --apply --queue-timeout 240 --wait-generated` ran as command_id `000000000802`, timestamp `2026-06-25T00:42:00-04:00`, exit `0`, `ok:1`, generated_refresh `completed`. Post-validator reread of `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md` confirmed the header line exactly: ``*** Item Summary: Current MCP route evidence supports a retained opcode `0x26` password-change helper with three converted text fields plus an `_wtol` numeric field; active submit still routes to the three-field sibling, so no-function/no-xref/no-pointer evidence remains a confidence cap. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***``. A target-page scan for `Wave2|four-string` returned no matches. Earlier correction attempts `000000000756`, `000000000763`, `000000000781`, and generated-refresh/autogen command `000000000760` are superseded by this successful normal generated-refresh run. Known missing `0003YJ` reference warnings remained.
- [x] B004 supersession in [UID:0002QB]: target now explicitly says B004's blank-formal-C++/no-code proof is superseded by B005. B004's no-route/no-function/no-pointer/no-active-submit evidence is preserved as audit/confidence cap language, and older change-history blank-C++ statements were revised as historical/superseded rather than current target-change instructions.
- [x] Parent aggregate [UID:00022W] `by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md`: updated the [UID:0002QB] child row, behavior note, reconstruction note, and change log from blank-C++/no-code disposition to retained raw source-family helper with formal first-draft C++ on the child. Aggregate remains contextual/non-emitting with blank aggregate C++; [UID:0002QC] remains the active submit route. Proof: validator command `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md --apply --queue-timeout 240`, command_id `000000000711`, timestamp `2026-06-25T00:19:44-04:00`, exit `0`, `ok:1`, generated_refresh `deferred`; validator retained existing warnings for missing `0003YJ` in `validator.ini` and missing target for `00019W`.
- [x] Core submit page [UID:0002QA] `by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md`: live submit call remains pointed to [UID:0002QC] at `0x004fe778`; added that [UID:0002QB] is retained/no-route but now has formal retained-helper C++. Proof: validator command `python .\tools\validator.py --mode file --file by-memory\0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md --apply --queue-timeout 240`, command_id `000000000712`, timestamp `2026-06-25T00:19:52-04:00`, exit `0`, `ok:1`, generated_refresh `deferred`.
- [x] Active sibling [UID:0002QC] `by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md`: checked with `Select-String` for `0002QB`, `004fe790`, `blank`, `account`, `numeric`, and `unreconstructable`. No stale claim says [UID:0002QB] remains unreconstructable/blank, and no claim says [UID:0002QC] covers the numeric account/id helper. No edit or validator run was needed.
- [x] File page [UID:0000I3] `by-file/ChangePasswordDialogPane.md`: updated packet-helper inventory/source-placement notes to reflect B005 superseding the B004 blank-C++ proof for [UID:0002QB], while preserving [UID:0002QC] as active and Socket/PacketBuffer as support owners only. Proof: validator command `python .\tools\validator.py --mode file --file by-file\ChangePasswordDialogPane.md --apply --queue-timeout 240`, command_id `000000000713`, timestamp `2026-06-25T00:20:00-04:00`, exit `0`, `ok:1`, generated_refresh `deferred`.
- [x] Class page [UID:00001L] `by-class/ChangePasswordDialogPane.md`: updated method/helper notes, field/argument caveats, active-vs-retained helper distinction, and B004-era blank formal C++ wording for [UID:0002QB]. Proof: validator command `python .\tools\validator.py --mode file --file by-class\ChangePasswordDialogPane.md --apply --queue-timeout 240`, command_id `000000000714`, timestamp `2026-06-25T00:20:10-04:00`, exit `0`, `ok:1`, generated_refresh `deferred`.
- [x] Network meta page [UID:0001QH] `by-meta/client_network.md`: no sufficient ChangePasswordDialogPane opcode `0x26` note existed, so a feature-packet note was added for the active three-field sender [UID:0002QC], retained account/id numeric variant [UID:0002QB], and Socket/PacketBuffer support-owner boundaries. Proof: validator command `python .\tools\validator.py --mode file --file by-meta\client_network.md --apply --queue-timeout 240`, command_id `000000000715`, timestamp `2026-06-25T00:20:19-04:00`, exit `0`, `ok:1`, generated_refresh `deferred`; validator retained existing warning for missing `0003YJ` in `validator.ini`.
- [x] PacketBuffer support [UID:0003YJ] `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`: checked with `Select-String`; it already documents `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `sub_575380`, `sub_5753F0`, and value-first ABI. No contradiction and no edit.
- [x] Copy-helper support [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`: checked with `Select-String`; it already documents `sub_516220` as a thin `memmove(destination, source, size)` wrapper with live IDA decompile/analyze evidence. No contradiction and no edit.
- [x] Sender-global support [UID:0000Q5] `by-global/g_packetSender.md`: checked with `Select-String`; it already documents Socket-owned `g_packetSender`, best source-facing type `Socket *`, broad packet-builder consumption, and that feature use is not owner evidence. It remains support global only, not the submit/core page. No contradiction and no edit.
- [x] `_wtol` support [UID:0001O5] `by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md`: checked with `Select-String`; it already documents a CRT `__wtol` / wide base-10 parse wrapper and non-project ownership. No contradiction and no edit.
- [x] Coverage/generated files: no manual coverage-report, generated C++/report, project-level, validator-state, or IDA DB edits were made. Scoped validators with `--apply` performed validator-owned reference/stat/autogen bookkeeping; all six original validator outputs reported generated_refresh `deferred`. During the earlier verification correction, validator-owned `--mode autogen --apply --wait-generated` command_id `000000000760` completed and reported `memory_coverage_metadata_update 0002QB`, but that path restored stale metadata; those failed/partial correction attempts are superseded. After supervisor legacy-row correction and validator-worker restart, normal scoped target validation with `--wait-generated` command_id `000000000802` completed generated refresh successfully and preserved the accepted source `Item Summary`; the validator-owned generated refresh also reported `memory_auto_coverage_update`.
- [x] Validators: scoped validators ran for every changed by-* doc. Command IDs/timestamps were `000000000710` (`2026-06-25T00:19:37-04:00`, target), `000000000711` (`2026-06-25T00:19:44-04:00`, parent aggregate), `000000000712` (`2026-06-25T00:19:52-04:00`, core), `000000000713` (`2026-06-25T00:20:00-04:00`, file), `000000000714` (`2026-06-25T00:20:10-04:00`, class), and `000000000715` (`2026-06-25T00:20:19-04:00`, network meta). Every command exited `0` with `ok:1`; generated_refresh was `deferred` for each. Verification correction commands for the target summary included earlier failed/superseded generated-refresh attempts, followed by the successful normal required command `python .\tools\validator.py --mode file --file by-memory\0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md --apply --queue-timeout 240 --wait-generated`, command_id `000000000802`, command_timestamp `2026-06-25T00:42:00-04:00`, exit `0`, `ok:1`, generated_refresh `completed`, generated_refresh_command_id `000000000802`, generated_refresh_timestamp `2026-06-25T00:42:00-04:00`. Validator side effects included `insert_header_blank 0002QB`, `memory_auto_coverage_update`, `projected_stats_update`, and known missing `0003YJ` reference warnings.
- [x] Leases: no lease needed for this report. Exact by-* edit set was leased before editing with `python .\tools\leaser\leaser.py B005 lease ...` for target, parent aggregate, core, file page, class page, and network meta; each returned `Success`. After validators, `python .\tools\leaser\leaser.py B005 unlease ...` returned `Rejected[No active lease]` for each path, and `tools/leaser/Agents/current_leases.md` scan found no `B005`, `0x004fe790`, `0x004fdd40`, `ChangePasswordDialogPane`, or `client_network` lease rows. For the 2026-06-25 post-worker-restart verification retry, only `by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md` was leased; lease returned `Success`, validator command `000000000802` ran with generated refresh completed, the active E-path header was reopened and verified, and unlease returned `Success`.

## Blockers
- No MCP blocker. MCP session `80de0a67` responded for health, function lookup, xrefs, decompilation, disassembly, bytes, and bounded instruction queries.
- No current no-code blocker remains. The unresolved fourth-field original spelling and no active call route are documented confidence caps, not reasons to leave a reconstructable owned emitter blank.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002QB-RawPasswordChangePacketWithAccount-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002QB-RawPasswordChangePacketWithAccount-source-quality.md","timestamp":"2026-06-25T00:50:28","uid":"0002QB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
