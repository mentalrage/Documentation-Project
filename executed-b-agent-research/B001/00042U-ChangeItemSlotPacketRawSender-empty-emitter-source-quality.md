** TARGET-REPORT-UID:00042U **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B001 Report - [UID:00042U] ChangeItemSlotPacketRawSender

Assignment: `B001-empty-emitter-report-00042U-ChangeItemSlotPacketRawSender-20260629`
Mode: report-only research
Target: [UID:00042U] `by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md`
Report path: `tools/leaser/Agents/Agent-B001/research/00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md`
Report date: 2026-06-29

## Finalized Report / Current Recommendation

Recommendation: convert [UID:00042U] from the older blank class-owned no-route result into a source-bearing retained ItemActionInputPanes file-scope helper. Keep the exact byte range and no-route caveat, but treat no-route as a confidence/name cap rather than a blank-C++ blocker under current retained raw-helper policy.

Required target action:

- Change `CANONICAL_OWNER:00001J` to `CANONICAL_OWNER:0000KC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Change `EMITTER_UIDS:00001J` to `EMITTER_UIDS:0000KC`.
- Raise `COMPLETION:86` to `COMPLETION:88`.
- Raise `CONFIDENCE:90` to `CONFIDENCE:91`.
- Populate the formal C++ block with the exact first-draft helper below.
- Preserve the page label `ChangeItemSlotPacketRawSender` as a retained raw by-memory/search label, but emit source-facing `SendChangeItemSlotPacket` without `Raw`.
- Preserve that `ChangeItemSlotInputPane::OnSubmitInput` still builds and sends the packet inline. Do not rewrite the submit method to call this helper without future caller-route evidence.

Exact formal C++ for the target reconstruction block:

```cpp
static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)
{
    unsigned char packet[128];

    packet[0] = 0x30;
    PacketBufferWriteUInt8(0, packet + 1);
    PacketBufferWriteUInt8(sourceSlot, packet + 2);
    PacketBufferWriteUInt8(destinationSlot, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);
}
```

Why this is implementation-ready:

- The helper is exact, bounded source-authored packet code, not padding, aggregate inventory, compiler glue, or a duplicate of `OnSubmitInput`.
- Current MCP and PE route scans still find no modeled function, start xrefs, whole-image VA/RVA pointer hits, or rel32 call/jump route to this raw start. Those facts cap confidence and keep the helper separate from the live submit path.
- Current policy and accepted same-source-family reports [UID:0003NY] and [UID:0003NZ] show that no-route retained helpers can emit first-draft C++ when the body, owner/source placement, and packet semantics are strong enough.
- The no-`this` body, two stack arguments, and `retn 8` source shape support a file-scope static `__stdcall` helper rather than a `ChangeItemSlotInputPane::...` member.

## Current Target State

Current target header:

- UID: `00042U`
- Completion/confidence: `86/90`
- Canonical owner: `00001J` `ChangeItemSlotInputPane`
- Reconstructable: `TRUE`
- Emitters: `00001J`
- Formal C++: blank
- Item summary: retained no-route item-slot packet sender, opcode `0x30`, subcommand `0`, two signed-byte slot args, send length `4`, `g_packetSender`, `retn 8`, unique signature, padding-separated bounds.

Generated/read-only state:

- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` still shows `// UID:00042U ... Completion:86 | Confidence:90 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` lists [UID:00042U] at `86/90`, average `88.0`, reconstructable `true`, report count `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` reports [UID:00042U] as `emits_code:false`.

This report does not edit generated files. Those rows are post-implementation validation expectations only.

## Current MCP Availability And Provenance

MCP was available and used read-only. B001 did not start, stop, restart, or manage MCP/IDA.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- `tools/list` was rechecked in the restored MCP session and provided schema-current narrow tools including `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `find_bytes`, `insn_query`, `decompile`, `callees`, and `make_signature_for_range`.
- `idb_list` showed active session `d4d50b81` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active `true`, analyzing `false`, backend `worker`, owned/adopted `true`, PID `19640`, worker PID `19640`.
- `server_health` on session `d4d50b81` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

## Evidence Checked

Current direct IDA MCP / raw-byte checks:

- `tools/list` for current schema; `idb_list`; `server_health(database:"d4d50b81")`.
- `lookup_funcs` for positive-control `0x00480640`, target/interior/end addresses `0x005b31a0`, `0x005b31d0`, `0x005b3212`, `0x005b3215`, `0x005b3220`, live submit/method controls `0x005b3010` and `0x005b3080`, and spell-slot sibling controls `0x005b3410` and `0x005b3485`.
- `xrefs_to` for `0x005b31a0`, `0x005b3215`, `0x005b31c7`, `0x005b31e8`, `0x005b3200`, positive-control live submit `0x005b3080`, and sibling raw sender `0x005b3410`.
- `get_bytes` for predecessor padding `0x005b3196-0x005b31a0`, full helper `0x005b31a0-0x005b3215`, epilogue bytes at `0x005b3212`, and successor padding `0x005b3215-0x005b3220`.
- `insn_query` scoped to `0x005b3196-0x005b3220`, `count:80`, `include_fn:true`, `include_disasm:true`; this was bounded to the target neighborhood and returned 36 decoded heads.
- `find_bytes` for VA/RVA pointer encodings of the target start/end, positive-control live submit pointer bytes, and spell-slot sibling start bytes.
- `make_signature_for_range 0x005b31a0-0x005b3215` with operand wildcarding disabled and enabled.
- `decompile` and `callees` for raw start `0x005b31a0` and live submit control `0x005b3080`.
- Local read-only PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` for target VA/RVA/end dwords and rel32 `E8`/`E9` routes to the helper start, end, interior, `0x005b31c3`, and `0x005b3200`, with `QueueAndSendPacket` as a positive control.
- Numeric conversions through `tools/int_convert.py` for `0x75`, `0x30`, `0x04`, `0x08`, `0x84`, `0x80`, `0x284`, `0x116`, `0x6c`, and `0x54`.

Documentation and report evidence checked:

- Target page [UID:00042U] `by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md`.
- Support pages `by-class/ChangeItemSlotInputPane.md`, `by-file/ItemActionInputPanes.md`, `by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md`, `by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md`, `by-global/g_packetSender.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, and `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`.
- Generated/read-only context `auto-generated/-ag-research-tracker.md` and `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Existing active/executed B reports and related pages searched with the assignment terms: `00042U`, `005b31a0`, `ChangeItemSlotPacketRawSender`, `ChangeItemSlotInputPane`, `ChangeSpellSlotPacketRawSender`, `0002S6`, `SendThrowConfirmedItemPacketRaw`, `0003NY`, `ItemActionInputPanes`, `g_packetSender`, and `QueueAndSendPacket`. Relevant opened precedent reports/pages include B006 `0001M6-ChangeItemSlotInputPane-source-quality.md`, B003 `0002S6-change-spell-slot-raw-sender-source-quality.md`, B007 `0003NY-SendThrowConfirmedItemPacketRaw-empty-emitter-source-quality.md`, B008 `0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md`, [UID:0003O7] `SelfSaveInputPaneSendSelfSavePacketRaw`, and [UID:000230] `GameServerNationRequestPacketRawHelper`.

## Current IDA MCP Evidence

Function and boundary checks:

- `lookup_funcs` positive-control proof resolves `0x00480640` to `sub_480640`, size `0x54` / 84 bytes (Verified with int_convert.py).
- `lookup_funcs` reports `0x005b31a0`, `0x005b31d0`, `0x005b3212`, `0x005b3215`, `0x005b3220`, `0x005b3410`, and `0x005b3485` as not modeled functions.
- Positive controls: `0x005b3010` resolves to `sub_5B3010`, size `0x6c`; `0x005b3080` resolves to `sub_5B3080`, size `0x116`.
- `get_bytes` confirms ten `0xcc` padding bytes at `0x005b3196-0x005b31a0`, the full helper bytes at `0x005b31a0-0x005b3215`, `c2 08 00` at `0x005b3212-0x005b3215`, and eleven `0xcc` bytes at `0x005b3215-0x005b3220`.
- `make_signature_for_range 0x005b31a0-0x005b3215` with operand wildcarding disabled returned a unique full-range signature. The wildcarded signature was also unique.
- Numeric conversions with `tools/int_convert.py` confirmed `0x75` -> 117, `0x30` -> 48, `0x04` -> 4, `0x08` -> 8, `0x84` -> 132, `0x80` -> 128, `0x284` -> 644, `0x116` -> 278, `0x6c` -> 108, and `0x54` -> 84. (Verified with int_convert.py.)

Instruction evidence:

- `disasm 0x005b31a0` decodes a complete stack-cookie helper even though no IDA function owns it.
- `0x005b31a0`: prologue starts.
- `0x005b31a3`: stack frame reserves `0x84` bytes.
- `0x005b31b9`: writes local packet byte `0x30`.
- `0x005b31c0-0x005b31c3`: writes subcommand `0` through `sub_575380` / `PacketBufferWriteUInt8`.
- `0x005b31cf-0x005b31d4`: sign-extends `[ebp+8]` and writes source slot.
- `0x005b31e0-0x005b31e5`: sign-extends `[ebp+0xc]` and writes destination slot.
- `0x005b31ea`: loads `dword_67A7EC` / `g_packetSender`.
- `0x005b31f9`: writes local trailing zero at packet byte `4`.
- `0x005b31fd-0x005b3200`: sends explicit length `4` through `sub_574BB0` / `QueueAndSendPacket`.
- `0x005b3212`: `retn 8`, proving callee cleanup for two stack arguments.
- `0x005b3215`: alignment begins.

Reference and liveness checks:

- `xrefs_to 0x005b31a0`, `0x005b3215`, `0x005b31c7`, `0x005b31e8`, and sibling `0x005b3410` returned no external xrefs.
- `xrefs_to 0x005b3200` reports only the internal code/fall-through edge from `0x005b31ff`, not an external route.
- Positive-control submit method `0x005b3080` has a data xref from `0x0062fa8c`, proving the xref query sees live vtable routes when present.
- `find_bytes` found zero whole-image hits for VA/RVA start bytes `A0 31 5B 00` / `A0 31 1B 00` and end bytes `15 32 5B 00` / `15 32 1B 00`.
- Positive-control VA bytes for live submit `0x005b3080` had one hit at `0x0062fa8c`.
- Local PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` found zero VA/RVA dword hits for `0x005b31a0` and `0x005b3215`, zero rel32 `E8`/`E9` call/jump routes to `0x005b31a0`, `0x005b3215`, `0x005b31c3`, or `0x005b3200`, and 416 positive-control rel32 calls to `QueueAndSendPacket` at `0x00574bb0`.
- The same PE scan found zero rel32 routes to any address in the half-open target range `0x005b31a0-0x005b3215`.
- `decompile 0x005b31a0` failed, as expected for an unmodeled raw start.
- `callees 0x005b31a0` returned `No function found`; positive-control `callees 0x005b3080` lists `sub_4F2300`, `_wcschr`, `sub_575380`, `sub_574BB0`, and `@__security_check_cookie@4`.

Submit-method contrast:

- `decompile 0x005b3080` confirms live `ChangeItemSlotInputPane::OnSubmitInput` copies up to `0x7f` wide chars, splits on comma, maps `a-z` to slots `1-26`, maps `A-Z` to `27-52`, validates against `g_activeUserStatusPane + 0x284`, and sends `[0x30, 0, source, dest]` length `4`.
- The live submit method emits that packet inline and does not call `0x005b31a0`.
- This separation means [UID:00042U] is not covered by [UID:0001M6], but `OnSubmitInput` should also not be rewritten to call [UID:00042U] without future route proof.

## Positive Evidence Summary

- Direct IDA facts prove a complete source-shaped raw helper body at `0x005b31a0-0x005b3215`: prologue, `0x84` stack frame, security cookie, packet scratch buffer, packet byte writes, shared send call, cookie check, and `retn 8`.
- The packet semantics are exact: opcode byte `0x30`, item-slot subcommand `0`, first signed stack byte as source slot, second signed stack byte as destination slot, local-only `packet[4] = 0`, and explicit send length `4`.
- Exact boundaries are supported by `0xcc` padding on both sides: ten bytes before the helper and eleven bytes after it.
- `make_signature_for_range` reports the full `0x005b31a0-0x005b3215` byte signature unique both with operand wildcarding disabled and enabled.
- Source-facing dependency names are already supported by current docs: `PacketBufferWriteUInt8`, `Socket *g_packetSender`, and `QueueAndSendPacket`.
- The target already clears the current code-entry gate before the recommended improvement: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and current score average `88.0`.
- Same-source-family retained-helper precedent [UID:0003NZ] supports file-scope formal C++ for a no-`this`, stack-argument ItemActionInputPanes raw packet helper whose no-route evidence remains a confidence cap.

## Negative Evidence Summary

- IDA still has no modeled function at the target start, interior sample points, or end boundary.
- `xrefs_to` finds no cross-references to the helper start, end, argument-write interior addresses, or spell-slot sibling raw start; the only target-neighborhood code xref is the internal fall-through edge into `0x005b3200`.
- Whole-image `find_bytes` finds no VA/RVA pointer encodings for target start or end. The positive-control live submit VA encoding is found at vtable slot `0x0062fa8c`, proving the route check can find ordinary pointers when they exist.
- Local PE route scan finds no VA/RVA dword hit, no rel32 call/jump to the start/end/interior, and no rel32 route to `0x005b31c3` or `0x005b3200`.
- `decompile` and `callees` fail for `0x005b31a0` because IDA has no function object there; this remains modeling/liveness evidence and a confidence cap.
- Live `ChangeItemSlotInputPane::OnSubmitInput` builds and sends the same packet inline and does not call this retained helper, so the method page must not be rewritten to call [UID:00042U] without future route proof.
- The original helper spelling and declaration are not symbol-proven; `SendChangeItemSlotPacket` and file-scope `static __stdcall` are source-shape inferences from current evidence, not recovered symbols.

## Ranked Ownership Analysis

1. [UID:0000KC] `ItemActionInputPanes` as direct owner/emitter - recommended. The body is a no-`this`, two-stack-argument, `retn 8` packet helper in the item-action source island. It is source-shaped like file-local retained helper [UID:0003NZ], and file ownership avoids inventing a class member that the binary body does not support.
2. [UID:00001J] `ChangeItemSlotInputPane` as semantic class context - keep in prose/support docs, but remove as direct owner/emitter for this exact helper. The packet belongs to the ChangeItemSlot feature, but the raw body reads no object fields and has no `ecx`/`this` use.
3. [UID:0001M6] `ChangeItemSlotInputPane` method page as covered-by owner - rejected. The live submit method emits the same packet inline but occupies a separate modeled range and does not cover or call `0x005b31a0-0x005b3215`.
4. [UID:0000Q5] `g_packetSender`, [UID:0001HU] `QueueAndSendPacket`, or [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers` - rejected as owners. They are infrastructure dependencies for byte serialization and queueing, not owners of the item-slot packet semantics.
5. [UID:0002S6] `ChangeSpellSlotPacketRawSender` sibling policy - comparison only. It is a SpellInputPanes sibling with subcommand `1`, not the assigned target, and should not be bulk-converted in this report.

## Score And Metadata Recommendation

- Current metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00001J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001J`, formal C++ blank.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`, formal C++ populated with the exact `SendChangeItemSlotPacket` block in this report.
- Score rationale: completion rises because the report resolves the stale blank-C++ blocker, reroutes ownership to the better supported file-scope helper owner, supplies exact formal C++, records current MCP/PE route evidence, and converts no-route from a blocker into a documented confidence cap. Confidence rises modestly because behavior, range, and source shape are strong, but remains below final-audit quality because no caller/pointer route or original source spelling is proven.
- No-code/no-improvement exception does not apply. Every named blocker was checked through current MCP, PE route scan, support docs, precedent reports, source-shape inference, and score/C++ gate analysis; the defensible outcome is an implementation-ready C++/metadata/support-doc plan, not unchanged blank C++.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a confirmed nonblank emitter route after the recommended owner/emitter correction, clears the combined-score gate, has exact bytes/bounds/packet semantics, and has an implementation-ready source-facing helper shape.

Exact formal target insertion content remains:

```cpp
static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)
{
    unsigned char packet[128];

    packet[0] = 0x30;
    PacketBufferWriteUInt8(0, packet + 1);
    PacketBufferWriteUInt8(sourceSlot, packet + 2);
    PacketBufferWriteUInt8(destinationSlot, packet + 3);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);
}
```

This preserves exact behavior because it emits the observed opcode/subcommand/argument/terminator/send-length sequence and the observed `retn 8` ABI as `__stdcall`. It matches plausible mid-2000s source better than a class member because the binary reads no `this` and takes both slot bytes from the stack. The no-route state remains explicit and prevents rewriting live `OnSubmitInput` to call the helper.

## Source-Quality Reanalysis

The old B006 conclusion was correct for its date and created a useful exact child page, but its blank-C++ decision is now stale under the current retained raw-helper standard. The facts that remain true are:

- no function object;
- no start xrefs;
- no VA/RVA pointer route;
- no rel32 route;
- live submit emits inline;
- exact original declaration is not symbol-proven.

Those facts no longer force blank C++ when the helper is a complete source-shaped body, has a current emitter route above the code-entry threshold, and has strong source placement. They cap confidence and formal name certainty.

Accepted current precedents:

- [UID:0003NY] `SendThrowConfirmedItemPacketRaw`: no function/xref/pointer/rel32 route remained a caveat, but the exact child now emits `ThrowReallyInputPane::SendThrowConfirmedItemPacket()` because the body is source-shaped and class-field ownership is strong.
- [UID:0003NZ] `SendUseItemSlotPacketRaw`: no start route remained a caveat, but the exact child now emits file-scope `static void SendUseItemSlotPacket(char itemSlot)` because the body is source-shaped, has no `this`, and belongs to ItemActionInputPanes.
- [UID:0002S6] `ChangeSpellSlotPacketRawSender`: older sibling blank-helper policy is useful caution, but it predates the accepted [UID:0003NY]/[UID:0003NZ] retained-helper conversions. Do not bulk-convert UID0002S6 in this report; it needs its own focused current pass if assigned.

No in-scope no-code blocker remains:

- This target is not an aggregate/container.
- It is not padding or compiler-only glue.
- It is not a covered duplicate of `OnSubmitInput`.
- It is not owned by Socket or PacketBuffer infrastructure.
- It is not below the code-entry score/emitter gate.
- It has a source-facing helper shape that can be stated without pretending there is a live caller.

## Naming, Ownership, And Source Placement

Best formal source name and signature:

```cpp
static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)
```

Accepted details:

- `SendChangeItemSlotPacket` is the best source-facing name. It mirrors the operation and avoids the retained-doc `Raw` suffix.
- `Raw` should remain in the by-memory title/search label only.
- `signed char` is supported by the two `movsx byte ptr [ebp+8]` and `[ebp+0xc]` loads.
- `__stdcall` is supported by `retn 8`; omitting it would erase an observed ABI fact.
- File-scope `static` is the best source placement because the body reads no `ecx`, uses two stack arguments, has no class-field access, and has no external pointer/caller route.

Recommended owner/emitter change:

- Change target owner/emitter from [UID:00001J] `ChangeItemSlotInputPane` to [UID:0000KC] `ItemActionInputPanes`.
- Keep [UID:00001J] as semantic class context in prose and support rows.
- Reason: with no `this` use, this body is source-shaped like ItemActionInputPanes file-local helper [UID:0003NZ], not like a class instance method. The helper still belongs to the ChangeItemSlot feature row in the file page.

Rejected alternatives:

- `ChangeItemSlotInputPane::SendChangeItemSlotPacket`: reject as formal source shape because the body does not read `ecx` or object fields.
- `static ChangeItemSlotInputPane::SendChangeItemSlotPacket`: reject because no source declaration route proves a class static member over a file-local helper.
- `SendChangeItemSlotPacketRaw`: reject as formal source name because `Raw` is a by-memory retention label, not proven human source suffix.
- Covered-by marker under [UID:0001M6]: reject because the live method emits inline and does not represent the raw helper range.
- Socket/PacketBuffer ownership: reject because those pages own transport and byte serialization, not item-slot packet command semantics.

## Recommended Target Doc Changes

For `by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Set `CANONICAL_OWNER:0000KC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:0000KC`.
- Insert the exact formal C++ from this report.
- Update the item summary to cite current MCP session `d4d50b81`, exact opcode/subcommand/argument/send-length facts, `retn 8`, no function/xref/pointer/rel32 route, unique signature, and first-draft file-scope helper disposition.
- Replace blank-C++/no-code proof with a current source-quality decision: no-route remains a confidence/name cap, not a formal-C++ blocker.
- Preserve the separation from [UID:0001M6] and state that `OnSubmitInput` still sends inline.

## Recommended Support Doc Changes

For `by-class/ChangeItemSlotInputPane.md`:

- Historicalize the active stale line `Current recovered file: source-3/simroot_v2/class_ChangeItemSlotInputPane.cpp`.
- Exact replacement direction: `Historical recovered-source lead: source-3/simroot_v2/class_ChangeItemSlotInputPane.cpp; current source-routing authority is by-* documentation, current MCP evidence, and the ItemActionInputPanes route.`
- Update the method row for `ChangeItemSlotPacketRawSender` so it no longer says class-owned blank-C++. It should say this is a retained file-scope ItemActionInputPanes helper associated with ChangeItemSlot, now source-bearing on exact child [UID:00042U] as `static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)`.
- Update Direct Parent Gate prose so this class is semantic context for the helper, while the helper's owner/emitter is [UID:0000KC].
- Add a B001 change note with current session `d4d50b81`, no route caveat, and formal-helper conversion.

For `by-file/ItemActionInputPanes.md`:

- In the `ChangeItemSlotInputPane` row, rewrite `class_ChangeItemSlotInputPane.cpp / current route ItemActionInputPanes.cpp` as historical recovered/generated file lead plus current route. Exact action: mark `class_ChangeItemSlotInputPane.cpp` as a historical generated/recovered lead only and `ItemActionInputPanes.cpp` as the current route.
- Rewrite the row's retained raw sender clause from `separate class-owned no-route helper with blank formal C++` to source-bearing file-scope helper `static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)`.
- Add boundary/change notes with the current MCP/PE evidence: no function/start-xref/pointer/rel32 route, unique full signature, exact opcode `0x30`, subcommand `0`, source/destination stack bytes, length `4`, local-only terminator, and no rewrite of `OnSubmitInput` to call the helper.
- Existing Wave3 dry-run and recovered artifact sections are already mostly historicalized by B008. Do not reintroduce active Wave3 authority.

For `by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md`:

- Historicalize `Current Wave3 owner: ChangeItemSlotInputPane` as an old Wave3/generated owner label only; current authority is the exact by-memory methods page plus class/file by-* docs.
- Historicalize `IDA reports no function at Wave3 projected constructor start 0x005b2fd0` as old Wave3 projected-start context. Keep the underlying no-function fact for the raw constructor, but do not present Wave3 projection as current authority.
- Update notes that currently say [UID:00042U] is blank/no-route so they instead say [UID:00042U] is a separate source-bearing file-scope helper. Preserve that this method page's formal `OnSubmitInput` remains inline and should not call the helper without future route evidence.

For `by-global/g_packetSender.md`:

- Rewrite the active stale-source line `Current simroot_v2/class_Socket.cpp emits g_packetSender...` as historical generated/simroot lead material only. Current type authority remains by-* Socket lifecycle evidence and current MCP evidence.
- Update the 2026-06-26 B006 UID00042U support sync line that says the raw sender stays blank-C++. It should now say UID00042U emits first-draft file-scope `SendChangeItemSlotPacket` through ItemActionInputPanes, while preserving that both live submit and retained helper send opcode `0x30` subcommand `0` length `4` through `g_packetSender->QueueAndSendPacket`.
- Preserve Socket ownership for `g_packetSender`; this is consumer/type evidence only.

For `by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md`:

- Exclude from edits in this callback with explicit reason. It is the spell-slot sibling [UID:0002S6], not the assigned target. The report uses it as comparison only; changing its blank-C++ policy would require a separate current MCP-backed assignment because support ownership is SpellInputPanes, not ItemActionInputPanes.

For `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` and `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`:

- Exclude from edits unless implementation finds a direct stale UID00042U contradiction. Current docs already provide the required source-facing helper names and payload-length semantics. No target-specific support edit is required.

## Validation Plan For Implementation Callback

Run scoped validators only after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality-removed.md](00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-output check, read-only after validation:

> Executable block R002 was removed from this report and preserved verbatim in [00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality-removed.md](00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated result: UID00042U is no longer an `Empty Emitter Marker` and generated `ItemActionInputPanes.cpp` contains the file-scope helper body.

Do not run `execute_report`. Do not edit generated files, project-level generated reports, manual coverage reports, validator/tool state, executed archives, lock files, or IDA DB.

## Claim And Incorporation Ledger

| Claim / accepted fact | Action | Destination | Verification state | Proof / exclusion |
| --- | --- | --- | --- | --- |
| UID00042U is exact retained source-authored packet helper code at `0x005b31a0-0x005b3215`. | incorporate | Target summary/evidence/body | applied | `by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md` now records MCP session `d4d50b81`, bytes/instruction evidence, unique signatures, and padding-separated bounds; validator `000000000653` ok `1`. |
| No modeled function, start xref, VA/RVA pointer, or rel32 route exists for `0x005b31a0`. | incorporate | Target evidence/naming notes and support notes | applied | Target, class, file, method, and global support notes preserve no-function/no-xref/no-pointer/no-rel32 evidence as a confidence/name cap; validators `000000000653` through `000000000657` all ok `1`. |
| No-route is not a blank-C++ blocker under current retained raw-helper policy. | incorporate | Target reconstruction notes and support change notes | applied | Target reconstruction notes now state no-route is not a blank-C++ blocker; support docs describe UID00042U as source-bearing while preserving callgraph caveat. |
| Target should emit formal first-draft C++ as `static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)`. | incorporate | Target formal C++ block | applied | Exact accepted C++ block was inserted into UID00042U; validator `000000000653` changed autogen registry from `blank` to `block` and generated output contains `SendChangeItemSlotPacket`. |
| Owner/emitter should move from class [UID:00001J] to file [UID:0000KC]. | incorporate | Target metadata, class/file support docs | applied | Target metadata now has `CANONICAL_OWNER:0000KC` and `EMITTER_UIDS:0000KC`; validator `000000000653` recorded canonical owner update `00001J -> 0000KC` and autogen registry update `00001J -> 0000KC`. |
| Page label can remain `ChangeItemSlotPacketRawSender`; formal helper name should not include `Raw`. | incorporate | Target naming notes, file/class support docs | applied | Target, class, and file docs keep retained by-memory label while documenting source-facing `SendChangeItemSlotPacket` without `Raw`; generated output line 160 identifies UID00042U and line 161 emits the non-Raw helper name. |
| `ChangeItemSlotInputPane::OnSubmitInput` remains inline and should not call the retained helper. | incorporate | Target, [UID:0001M6], class/file support docs | applied | Target, class, file, and method docs all state `OnSubmitInput` remains inline and must not call UID00042U without future route proof; method formal C++ was not rewritten. |
| Target packet semantics are opcode `0x30`, item-slot subcommand `0`, source slot, destination slot, local-only trailing zero, send length `4`. | incorporate | Target behavior/evidence and support rows | applied | Target behavior/evidence and support docs now record opcode/subcommand/slot/local terminator/send-length facts; generated output includes the exact packet writes. |
| `by-class/ChangeItemSlotInputPane.md` active recovered-source wording is stale. | historicalize | `by-class/ChangeItemSlotInputPane.md` | applied | Rewritten as historical recovered-source lead only; validator `000000000654` ok `1` with pre-existing missing UID `000367` warnings. |
| `by-class/ChangeItemSlotInputPane.md` still says UID00042U is class-owned blank-C++. | incorporate | `by-class/ChangeItemSlotInputPane.md` | applied | Method row, evidence notes, Direct Parent Gate, and change notes now route UID00042U through [UID:0000KC] while preserving [UID:00001J] semantic context; validator `000000000654` ok `1`. |
| `by-file/ItemActionInputPanes.md` ChangeItemSlot row still says UID00042U is class-owned blank-C++. | incorporate | `by-file/ItemActionInputPanes.md` | applied | ChangeItemSlot row and boundary/change notes now describe UID00042U as source-bearing file-scope `SendChangeItemSlotPacket`; validator `000000000655` ok `1` with pre-existing missing UID warnings. |
| `by-file/ItemActionInputPanes.md` `class_ChangeItemSlotInputPane.cpp` lead needs explicit historicalization when row is edited. | historicalize | `by-file/ItemActionInputPanes.md` | applied | Row now says historical recovered/generated `class_ChangeItemSlotInputPane.cpp` lead only; current route is `ItemActionInputPanes.cpp`. |
| [UID:0001M6] support page has active Wave3 wording. | historicalize | `by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md` | applied | Status and IDA evidence now mark Wave3 owner/projection as historical generated lead context; validator `000000000656` ok `1`. |
| [UID:0001M6] support page says UID00042U remains blank/no-route. | incorporate | `by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md` | applied | Function map and source-quality notes now say UID00042U is separate source-bearing ItemActionInputPanes helper while this method page remains inline; validator `000000000656` ok `1`. |
| `by-global/g_packetSender.md` active simroot wording is stale. | historicalize | `by-global/g_packetSender.md` | applied | Simroot line now says historical generated/simroot lead and current authority remains Socket lifecycle plus IDA/MCP evidence; validator `000000000657` ok `1` with pre-existing missing UID `0003UT` warnings. |
| `by-global/g_packetSender.md` says UID00042U stays blank-C++. | incorporate | `by-global/g_packetSender.md` | applied | UID00042U consumer note and change note now say source-bearing file-scope `SendChangeItemSlotPacket`; Socket ownership unchanged. |
| [UID:0002S6] spell-slot raw sender is comparison only. | not-applicable | `by-memory/0x005b3410-0x005b3485.ChangeSpellSlotPacketRawSender.md` | excluded-with-reason | Not edited. It is the separate SpellInputPanes sibling and would need its own assignment/current evidence pass. |
| QueueAndSendPacket and PacketBuffer support docs already provide required helper names/semantics. | not-applicable | QueueAndSendPacket and PacketBuffer helper docs | excluded-with-reason | Not edited. Implementation found no direct stale UID00042U contradiction in those dependency docs; target links were validator-normalized only inside the target page. |
| Generated `ItemActionInputPanes.cpp` still has UID00042U as an empty marker. | incorporate | `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` | applied | Read-only generated inspection after validators shows header `validator-command-id: 000000000656`, `validator-refreshed-at: 2026-06-29T11:28:09-04:00`; lines 160-161 show UID00042U and `SendChangeItemSlotPacket`, with no UID00042U empty marker. |
| Report-only constraints were obeyed. | already-present | B001 research report only | already-present | Report-only pass remains unchanged historically; callback edits were limited to the five accepted by-* docs and this report ledger/checklist. No generated, coverage, tool state, IDA DB, executed archive, supervisor ledger, or lock file was manually edited; `execute_report` was not run. |

## Implementation Tracking Checklist

- [x] Take short leases only for the immediate accepted edit/validator batch, if implementation callback is issued. Proof: `python .\tools\leaser\leaser.py Agent-B001 lease ...` returned `Success` for all five edited by-* paths.
- [x] Update target metadata in `by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md`: `88/91`, `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`. Proof: target header updated; validator `000000000653` recorded completion/confidence updates and canonical owner update `00001J -> 0000KC`.
- [x] Insert the exact formal C++ block from this report into the target reconstruction block only. Proof: target formal block contains exact accepted `static void __stdcall SendChangeItemSlotPacket(...)`; validator `000000000653` recorded autogen registry `blank -> block`.
- [x] Update target body with current MCP session `d4d50b81`, exact bytes/instructions, no-route evidence, PE route-scan evidence, naming/ownership decision, and no-call-from-submit caveat. Proof: target `IDA MCP Evidence`, `Reconstruction Notes`, `Negative Evidence And Rejected Alternatives`, and `Changes` sections updated; validator `000000000653` ok `1`.
- [x] Update `by-class/ChangeItemSlotInputPane.md`: historicalize `source-3/simroot_v2/class_ChangeItemSlotInputPane.cpp`, rewrite UID00042U from class-owned blank-C++ to file-scope source-bearing helper associated with the class, and preserve class semantic context. Proof: status, method row, evidence notes, Direct Parent Gate, and change notes updated; validator `000000000654` ok `1` with pre-existing `missing_ref_uid 000367` warnings.
- [x] Update `by-file/ItemActionInputPanes.md`: historicalize `class_ChangeItemSlotInputPane.cpp` as generated/recovered lead only, rewrite UID00042U row as source-bearing file-scope helper, and add B001 current evidence/change notes. Proof: ChangeItemSlot row, Boundary Notes, and Changes updated; validator `000000000655` ok `1` with pre-existing missing UID warnings.
- [x] Update `by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md`: historicalize active Wave3 owner/projection wording and update UID00042U notes while preserving inline `OnSubmitInput`. Proof: status/evidence/function map/source-quality/change notes updated; validator `000000000656` ok `1`.
- [x] Update `by-global/g_packetSender.md`: historicalize `simroot_v2/class_Socket.cpp` generated lead wording and update UID00042U consumer note from blank-C++ to source-bearing helper; preserve Socket ownership. Proof: evidence note and change note updated; validator `000000000657` ok `1` with pre-existing `missing_ref_uid 0003UT` warnings.
- [x] Do not edit [UID:0002S6] `ChangeSpellSlotPacketRawSender` in this callback; record comparison-only exclusion if needed. Proof: no edit made; ledger marks excluded-with-reason because it is a separate SpellInputPanes sibling requiring its own assignment.
- [x] Do not edit QueueAndSendPacket or PacketBuffer helper docs unless a direct UID00042U contradiction is found during implementation; record no-edit reason if excluded. Proof: no direct stale UID00042U contradiction found; docs not edited; ledger marks excluded-with-reason.
- [x] Run scoped validators listed in this report with `--apply --queue-timeout 240` for every edited by-* file. Proof: ran target `000000000653` at `2026-06-29T11:27:44-04:00`, class `000000000654` at `11:27:51`, file `000000000655` at `11:28:01`, method `000000000656` at `11:28:09`, and global `000000000657` at `11:28:14`; all exit code `0`, ok `1`, generated_refresh `deferred`.
- [x] Inspect generated `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` read-only after validators and record that UID00042U is no longer an `Empty Emitter Marker`. Proof: queue status `000000000658` showed zero queued/processing generated refresh jobs; generated header is `validator-command-id: 000000000656`, `validator-refreshed-at: 2026-06-29T11:28:09-04:00`; `Select-String` shows UID00042U at lines 160-161 followed by `SendChangeItemSlotPacket`, and no UID00042U empty marker.
- [x] Release all leases immediately after the edit/validator batch and record release proof. Proof: unlease command returned `Rejected[No active lease]` for all five B001 paths because no B001 lease remained active; current lease report immediately after showed active leases only for unrelated B002/B008 paths and no B001 entries.
- [x] Do not run `execute_report`. Proof: only file validators, queue status, generated read-only inspection, and leaser commands were run.
- [x] Do not manually edit generated files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, executed archives, lock files, or IDA DB. Proof: generated file was inspected read-only; validator/project-level generated output was changed only by validator commands; no restricted files were manually edited.

No implementation blocker remains for UID00042U.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md","timestamp":"2026-06-29T11:31:54","uid":"00042U"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00042U-ChangeItemSlotPacketRawSender-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00042U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
