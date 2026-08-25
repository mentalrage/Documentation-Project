** TARGET-REPORT-UID:0003UK **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003UK **
# 0003UK LivingObjectPane Deferred Packet Buffer Source-Quality Report

Assignment: `B002-goal2-livingobject-deferred-packet-buffer-source-quality-0003UK-20260619`

Target: [UID:0003UK] `by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md`

Required output: `tools/leaser/Agents/Agent-B002/research/0003UK-LivingObjectPaneDeferredPacketBuffer-source-quality.md`

Report-only result: this pass does not edit any `by-*` documentation file and does not edit `by-memory/-coverage-report.md`.

## Final Recommendation

[UID:0003UK] should not remain source-described as `SetMovementBuffer`. The best-supported source-quality role is a `LivingObjectPane` thiscall helper that replaces the deferred user-list packet buffer:

`void LivingObjectPane::CopyDeferredUserListPacket(const unsigned char *packetData, size_t packetSize)`

`CopyDeferredPacketBuffer` remains an acceptable generic fallback name if the project wants to avoid user-list-specific naming before a full local-player aggregate audit, but the stronger current name is `CopyDeferredUserListPacket` or `CopyDeferredUserListPacketBuffer`. All direct route evidence found for `0x005a9310` is user-list opcode 0x36 deferred-payload staging. No movement-history or movement-prediction caller was found.

Recommended metadata:

```text
*** UID:0003UK
*** COMPLETION:88
*** CONFIDENCE:90
*** CANONICAL_OWNER:00007B
*** RECONSTRUCTABLE:TRUE
*** EMITTER_UIDS:00007B
```

The implementation route should remain [UID:00007B] `LivingObjectPane`, with source placement through [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`. This helper is not owned by `UserPane`, `UserListDialogPane`, or `PacketBuffer`.

First-draft C++ is now eligible. The body, receiver, arguments, side effects, all known callers, and owner/emitter route are source-quality enough for emission. The only unresolved item is exact original spelling, which should cap score below final-audit levels but does not block first-draft reconstruction.

## Exact Evidence Checked

Target document checked:

- [UID:0003UK] `by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md`
  - Current state is `85/87`, owner/emitter [UID:00007B], reconstructable true, blank C++ block.
  - Current title and body call the helper `Set Movement Buffer`, while already noting the name is too narrow because [UID:0003US] and [UID:0003VB] call it for deferred user-list payloads.
  - Current open question says final buffer type/field names/caller semantics are not source-quality. This report closes that issue for target-level purposes.

Source-quality rules checked:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`, especially Rule 26
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `by-structure.md`

Support documentation checked:

- [UID:00007B] `by-class/LivingObjectPane.md`
- [UID:0000KU] `by-file/LivingObjectPane.md`
- [UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- [UID:0003VB] `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`
- [UID:0003US] `by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md`
- [UID:0000FQ] `by-class/UserPane.md`
- [UID:0000P1] `by-file/UserPane.md`
- [UID:0000OZ] `by-class/UserListDialogPane.md`
- [UID:0000FN] `by-file/UserListDialogPane.md`
- [UID:0000M8] `by-file/PacketBuffer.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md` read-only lookup for the supervisor-owned row

Prior B-agent reports checked as support evidence:

- `tools/leaser/Agents/Agent-B001/research/executed/0003US-LivingObjectPaneHandleUserListPacket-source-quality.md`
- `tools/leaser/Agents/Agent-B001/research/executed/0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md`

Binary/listing evidence checked:

- IDA listing export: `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- Raw PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5 `4247e04e20b65d6414c7238aa8ff5515`
  - SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
  - Image base `0x00400000`
  - `.text` section `0x00401000-0x0060c600`, raw `0x400-0x20ba00`

Fresh local IDA MCP was attempted and was unavailable:

```text
MCP_ERROR: Unable to connect to the remote server
```

This does not block the report because the target body and all direct callers were rechecked against the IDA listing export and raw PE bytes. The live-MCP-backed prior docs remain support evidence, but the final target claims in this report are also independently verified against local artifacts.

## Function Body Facts

IDA listing export body at `0x005a9310`:

```asm
sub_5A9310 proc near
Src  = dword ptr  8
Size = dword ptr  0Ch

push    ebp
mov     ebp, esp
push    esi
push    edi
mov     edi, ecx
push    dword ptr [edi+13EB20h]
call    j_j_j___free_base
mov     esi, [ebp+Size]
push    esi
call    unknown_libname_19
push    esi
push    [ebp+Src]
mov     [edi+13EB20h], eax
push    eax
mov     [edi+13EB24h], esi
call    _memmove
add     esp, 14h
pop     edi
pop     esi
pop     ebp
retn    8
sub_5A9310 endp
```

Important body conclusions:

- The IDA prototype line says `int __stdcall sub_5A9310(void *Src, size_t Size)`, but the actual call convention is source-facing `thiscall`: callers load the receiver into `ecx`, and the function uses `ecx` as the object pointer.
- `retn 8` confirms two stack arguments.
- There is no meaningful return value. `eax` happens to hold the `memmove` return value after the call, but no caller evidence requires a return. Source reconstruction should use `void`.
- The receiver field `this+0x13eb20` is freed before replacement.
- The second argument is passed to allocation and stored at `this+0x13eb24`.
- The first argument is copied into the new allocation using `memmove`.
- There is no null check after allocation.
- There is no size-zero special case.
- The helper does not parse the packet. It only owns the deferred copy and byte count.
- The helper does not touch the movement-history ring fields at `+0x13eb14`, `+0x13eb18`, or `+0x13eb1c`.

Raw PE bytes for the target:

```text
Bytes 0x005a9310-0x005a934a:
55 8b ec 56 57 8b f9 ff b7 20 eb 13 00 e8 77 e4 01 00
8b 75 0c 56 e8 65 e4 01 00 56 ff 75 08 89 87 20 eb 13 00
50 89 b7 24 eb 13 00 e8 6f 02 02 00 83 c4 14 5f 5e 5d c2 08 00
```

Boundary bytes checked:

```text
Bytes 0x005a9307-0x005a9310: c2 08 00 cc cc cc cc cc cc
Bytes 0x005a934a-0x005a9350: cc cc cc cc cc cc
```

Boundary conclusion:

- `0x005a9310` is the function start.
- `0x005a9347` is `ret 8`.
- `0x005a934a` is the first byte after the function.
- `0x005a934a-0x005a9350` is six bytes of `0xcc` alignment padding.
- `by-memory/-ignored.md` already records the preceding `0x005a9307-0x005a9310` padding. It does not currently record the following `0x005a934a-0x005a9350` padding; that can be added later if coverage cleanup requires it.

## Direct Caller And Reachability Facts

Raw PE route scan found:

```text
VA pointer hits for 0x005a9310: 0
RVA pointer hits for 0x001a9310: 0
Direct E8 call hits to 0x005a9310: 6
  0x005a7c44
  0x005a7c64
  0x005a7c84
  0x005abbdb
  0x005abbfb
  0x005abc1b
```

All six direct calls are user-list deferred-payload staging calls.

Inline live route [UID:0003VB] `UserPane::HandleServerMessage`, opcode `0x36`:

- `0x005a7c44`
- `0x005a7c64`
- `0x005a7c84`

The listing around these calls shows the inline dispatcher normalizing the UserPane facet to the LivingObjectPane/local-player object, preserving the packet payload pointer and size, setting the deferral tick, and calling `0x005a9310` with:

- `ecx = ebx`, the LivingObjectPane/local-player receiver
- `Src = edi`, the packet payload pointer
- `Size = esi`, the payload byte count

The three tiers set `this+0x13eb2c` to deferred refresh times:

- `+0x15f90` decimal `90000`
- `+0xea60` decimal `60000`
- `+0x7530` decimal `30000`

Retained duplicate [UID:0003US] `LivingObjectPaneHandleUserListPacket`:

- `0x005abbdb`
- `0x005abbfb`
- `0x005abc1b`

The listing around these calls shows the same source shape in the standalone duplicate:

- `ecx = esi`, the LivingObjectPane receiver
- `Src = ebx`, the packet payload pointer
- `Size = edi`, the payload byte count
- The same tiered deferral-time writes to `this+0x13eb2c`

[UID:0003US] is already documented as retained duplicate/no-live-route:

- No direct live caller to `0x005abb20`
- No switch-table route
- No PE VA/RVA pointer route
- Live opcode `0x36` body is inline in [UID:0003VB]

Reachability conclusion:

- The helper at `0x005a9310` is live because [UID:0003VB] calls it directly from opcode `0x36`.
- [UID:0003US] provides corroborating duplicate source shape but is not the live dispatch route.
- No movement-history caller was found by PE direct-call scan or by the reviewed support docs.

## Field And Type Recommendations

Target-local fields:

```cpp
unsigned char *m_deferredUserListPacket;     // this + 0x13eb20
size_t m_deferredUserListPacketSize;         // this + 0x13eb24
```

Recommended generic aliases if the project chooses non-user-list-specific names:

```cpp
unsigned char *m_deferredPacketBuffer;       // this + 0x13eb20
size_t m_deferredPacketBufferSize;           // this + 0x13eb24
```

Related caller-side fields from [UID:0003US] and [UID:0003VB]:

```cpp
uint32_t m_userListPacketTick;               // this + 0x13eb28
uint32_t m_userListDeferUntilTick;           // this + 0x13eb2c
bool m_skipNextUserListPacket;               // this + 0x13eb30, byte-sized flag semantics
```

The alternative name `m_nextUserListRefreshTick` is also defensible for `+0x13eb2c`, but `m_userListDeferUntilTick` better describes the deferred-payload staging decision made immediately before this helper is called.

Separate movement-history fields from [UID:00007B]:

```cpp
LocalMovementHistoryRecord *m_movementHistory;  // adjusted this + 0x13eb14
uint32_t m_movementHistoryCapacity;             // adjusted this + 0x13eb18
uint32_t m_movementHistoryWriteIndex;           // adjusted this + 0x13eb1c
```

The target helper does not read or write these movement-history fields. This is the central reason `SetMovementBuffer` should be rejected.

Argument recommendations:

```cpp
const unsigned char *packetData
size_t packetSize
```

Evidence:

- The first argument is only a source to `memmove`; the helper does not write through it.
- The second argument is passed to allocation and `memmove`, and is stored as a byte count.
- On 32-bit VC++, `size_t` and `unsigned int` both match the binary width. `size_t` is the source-quality type because the value is used as CRT allocation/copy size.

Allocation/copy helper names:

- `j_j_j___free_base` is CRT `free`.
- `unknown_libname_19` is allocator-like and is used exactly like `malloc(packetSize)` in this body.
- `_memmove` is CRT `memmove`.

The body uses C allocation rather than `new[]`, and source C++ should preserve the `free`/`malloc`/`memmove` family unless a wider project allocator abstraction is later proven.

## Ownership And Source Placement

Recommended canonical owner remains [UID:00007B] `LivingObjectPane`.

Evidence:

- The function receiver is in `ecx`.
- The body writes fields in the LivingObjectPane/local-player adjusted object at `+0x13eb20` and `+0x13eb24`.
- [UID:00007B] already owns the local-player tail fields, movement ring fields, user-list packet state, and adjacent local player packet helpers.
- [UID:0003US] is documented as a `LivingObjectPane` duplicate handler and calls this helper with a LivingObjectPane receiver.
- [UID:0003VB] is a `UserPane` dispatcher, but before calling this helper it has normalized to the LivingObjectPane/local-player receiver.

Recommended emitter remains [UID:00007B].

Recommended file route remains [UID:0000KU] `NexusTK/map/LivingObjectPane.cpp`.

Rejected owners:

- [UID:0000FQ] `UserPane`: rejected. The live dispatcher is `UserPane::HandleServerMessage`, but the callee is a LivingObjectPane/local-player state mutator.
- [UID:0000P1] `UserPane.cpp`: rejected as implementation file for this helper. It may contain the inline opcode `0x36` dispatcher, but this helper belongs with LivingObjectPane local-player state.
- [UID:0000OZ] `UserListDialogPane`: rejected. The dialog pane is lazy-created by the opcode `0x36` path and renders/parses list UI; it does not own the deferred raw packet buffer pair.
- [UID:0000FN] `UserListDialogPane.cpp`: rejected for the same reason.
- [UID:0000M8] `PacketBuffer`: rejected. `PacketBuffer` owns generic packet serialization helpers. This helper has a `this` receiver, stores object fields, and is not a stateless packet-buffer primitive.
- Generic movement-history owner/section: rejected. The helper does not touch the movement ring.

## Heuristic / Inference Reanalysis And Validation

This section rechecks every unclear name, type, owner, helper, source-placement issue, and open question instead of carrying forward the previous shallow `SetMovementBuffer` label.

Compiler/generated name: `sub_5A9310`

- Evidence checked: IDA listing export body, raw PE bytes, direct call sites, target doc, support docs.
- Conclusion: generated placeholder only. Replace in source-facing text with `LivingObjectPane::CopyDeferredUserListPacket` or the generic fallback `LivingObjectPane::CopyDeferredPacketBuffer`.
- Confidence: high for role, moderate-high for exact spelling. Exact original spelling is not recoverable from current evidence, so the name should be described as best-supported source-quality naming.

Compiler/generated prototype: `int __stdcall sub_5A9310(void *Src, size_t Size)`

- Evidence checked: body uses `ecx` as receiver; callers set `ecx`; epilogue is `ret 8`.
- Conclusion: IDA prototype is misleading. Source-facing prototype should be a two-argument `thiscall` method returning `void`.
- Best signature: `void LivingObjectPane::CopyDeferredUserListPacket(const unsigned char *packetData, size_t packetSize)`.

Function name: `SetMovementBuffer`

- Evidence checked: all six direct call sites, support docs for movement ring fields, body offsets.
- Conclusion: reject. The helper does not touch movement-history fields and no movement caller was found. The name likely came from an older broad local-player/movement split table, not from the target body.
- Replacement: `CopyDeferredUserListPacket` preferred; `CopyDeferredPacketBuffer` acceptable generic alias.

Function name: `CopyDeferredPacketBuffer`

- Evidence checked: B001 executed reports, [UID:0003US], [UID:0003VB], direct call inventory.
- Conclusion: good generic name and much better than `SetMovementBuffer`. It correctly describes free/allocate/copy semantics and deferred payload storage. It is slightly less precise than user-list-specific naming because all known calls are user-list opcode `0x36` tiers.
- Recommendation: keep as alias in notes if the implementation team wants conservative naming; use `CopyDeferredUserListPacket` in first-draft C++.

Function name: `SetDeferredPacketBuffer`

- Evidence checked: body and side effects.
- Conclusion: acceptable but weaker. It hides the destructive free/reallocate/copy behavior and sounds like pointer ownership transfer. The helper copies caller data into owned storage; it does not store the caller pointer.
- Recommendation: reject in favor of `Copy...`.

Field `this+0x13eb20`

- Evidence checked: target body frees the old pointer, stores allocation result, [UID:0003US]/[UID:0003VB] deferred user-list logic, [UID:0000FQ]/[UID:0000P1] destructor evidence that this pointer is freed.
- Conclusion: `unsigned char *m_deferredUserListPacket` is the best-supported specific name. Generic fallback is `m_deferredPacketBuffer`.
- Not movement history: movement ring pointer is separately documented at `+0x13eb14`.

Field `this+0x13eb24`

- Evidence checked: target body stores the exact byte count argument immediately after allocation and before `memmove`; caller passes packet payload size.
- Conclusion: `size_t m_deferredUserListPacketSize` is best-supported. Generic fallback is `m_deferredPacketBufferSize`.
- Not capacity: no capacity comparison or growth behavior exists. It is the copied packet byte count.

Field `this+0x13eb28`

- Evidence checked: [UID:0003US]/[UID:0003VB] support docs; not touched by target body.
- Conclusion: `m_userListPacketTick` or equivalent packet-timing counter. It should be documented in support docs, but target C++ does not reference it.

Field `this+0x13eb2c`

- Evidence checked: direct caller instructions immediately before `0x005a9310` calls; tiered writes using current tick plus 30000/60000/90000 and direct heavy path plus 150000 in support docs.
- Conclusion: `m_userListDeferUntilTick` is the best local name for the deferred-buffer route. `m_nextUserListRefreshTick` is acceptable but less explicit.
- Target relation: callers set it before copying the deferred payload.

Field `this+0x13eb30`

- Evidence checked: [UID:0003US]/[UID:0003VB] support docs.
- Conclusion: byte/boolean one-shot user-list skip flag, best name `m_skipNextUserListPacket`. Target does not touch it.

Movement-history ring fields `+0x13eb14/+0x13eb18/+0x13eb1c`

- Evidence checked: [UID:00007B] class doc and target body.
- Conclusion: separate local movement-history state. They should remain documented as movement ring fields, while [UID:0003UK] should be moved out of movement-buffer wording.

Caller semantics: movement versus user-list deferred payload

- Evidence checked: raw PE direct call scan, listing call contexts, [UID:0003VB] opcode `0x36`, [UID:0003US] duplicate handler.
- Conclusion: all known direct callers are user-list deferred payload staging. There is no evidence for movement-buffer caller semantics. The current report should close this by recommending user-list-specific wording.

Reachability

- Evidence checked: raw PE direct calls and support docs.
- Conclusion: live route is [UID:0003VB] inline opcode `0x36`; [UID:0003US] is a retained duplicate/no-live-route body that still corroborates source shape.

Owner/source placement

- Evidence checked: body receiver, field offsets, [UID:00007B], [UID:0000KU], [UID:0000FQ], [UID:0000P1].
- Conclusion: owner [UID:00007B] and emitter [UID:00007B] remain correct. File route [UID:0000KU] remains correct. The helper may be mentioned by UserPane support docs as a callee, but not owned there.

Helper/library meanings

- Evidence checked: target body call order and arguments.
- Conclusion: `j_j_j___free_base` = `free`, `unknown_libname_19` = `malloc`-like allocator, `_memmove` = `memmove`.
- Source readiness: use CRT-style allocation/copy in the draft. Do not introduce `std::vector`, `new[]`, or RAII in the by-memory C++.

Split/range decision

- Evidence checked: raw bytes around function, IDA listing procedure bounds, predecessor padding in ignored ledger.
- Conclusion: range `0x005a9310-0x005a934a` is exact. The following `0x005a934a-0x005a9350` bytes are padding and can be recorded separately if coverage cleanup wants it. Do not merge this helper with callers or with adjacent runtime/collapsed helper bytes.

First-draft C++ eligibility

- Evidence checked: `by-structure.md` C++ rules, target metadata, body exactness, owner/emitter route.
- Conclusion: eligible. Current average `(85+87)/2 = 86` already meets the minimum gate, and this pass raises source-quality evidence. There is no exact no-code proof. The correct action after acceptance is to populate C++.

Open question: exact original source spelling

- Evidence checked: no symbol-bearing source was available; IDA name is generated; docs preserve inferred names.
- Conclusion: exact original spelling cannot be proven. This is not a blocker. Use a descriptive source-quality name and cap confidence below final-audit levels.

Open question: whether this is a general deferred packet buffer

- Evidence checked: all direct calls, support docs.
- Conclusion: all known uses are user-list opcode `0x36`. If future unobserved source had a generic name, current binary route does not prove it. For source reconstruction, the best current name is user-list-specific; preserve `CopyDeferredPacketBuffer` as an alias in notes only.

Open question: whether target should remain under movement helper family

- Evidence checked: [UID:0001KM] split table and [UID:0000KU] proposed contents.
- Conclusion: no. Support docs should move or relabel `0x005a9310` from movement-buffer wording into deferred user-list packet staging/local-player packet helpers.

Open question: whether first-draft C++ should include packet parsing

- Evidence checked: target body and caller docs.
- Conclusion: no. Parsing and tier decisions live in [UID:0003VB]/[UID:0003US]. [UID:0003UK] only copies the raw payload and size.

## First-Draft C++ Recommendation

Preferred source-facing draft:

```cpp
void LivingObjectPane::CopyDeferredUserListPacket(const unsigned char *packetData, size_t packetSize)
{
    free(m_deferredUserListPacket);

    m_deferredUserListPacket = static_cast<unsigned char *>(malloc(packetSize));
    m_deferredUserListPacketSize = packetSize;
    memmove(m_deferredUserListPacket, packetData, packetSize);
}
```

Generic fallback draft if the project chooses the broader field/helper names:

```cpp
void LivingObjectPane::CopyDeferredPacketBuffer(const unsigned char *packetData, size_t packetSize)
{
    free(m_deferredPacketBuffer);

    m_deferredPacketBuffer = static_cast<unsigned char *>(malloc(packetSize));
    m_deferredPacketBufferSize = packetSize;
    memmove(m_deferredPacketBuffer, packetData, packetSize);
}
```

Do not add allocation failure handling in this by-memory C++ because the binary does not branch after allocation. Do not add a `packetSize == 0` special case because the binary does not branch on size. Do not return the destination pointer because callers do not use a return and the source role is a mutating helper.

## Rejected Alternatives

`LivingObjectPane::SetMovementBuffer`

- Rejected. The helper does not touch movement-history fields and all found callers are user-list packet deferral paths.

`LivingObjectPane::SetMovementHistoryBuffer`

- Rejected. Same reason as `SetMovementBuffer`, and the documented movement-history ring starts at `+0x13eb14`, not `+0x13eb20`.

`LivingObjectPane::SetDeferredPacketBuffer`

- Rejected as primary name. It is closer than movement naming, but it underspecifies copy/reallocation semantics and could imply pointer ownership transfer.

`LivingObjectPane::CopyMovementBuffer`

- Rejected. No movement caller evidence and wrong field family.

`UserPane::CopyDeferredUserListPacket`

- Rejected. [UID:0003VB] is the live dispatcher caller, but the callee receiver and state are LivingObjectPane/local-player fields.

`UserListDialogPane::CopyDeferredPacketBuffer`

- Rejected. Dialog creation is adjacent in opcode `0x36`, but the dialog does not own these raw deferred packet fields.

`PacketBuffer::CopyDeferredPacketBuffer`

- Rejected. This is object-state replacement, not stateless packet serialization.

No-code/no-emission

- Rejected. The helper is exact-range, reconstructable, has a valid owner/emitter route, has a simple source-authored body, and now has caller/field semantics resolved. The only imperfect item is exact original spelling.

## Target Implementation Checklist

When this report is accepted for implementation, update [UID:0003UK] only after preserving the report evidence level:

- Keep `*** UID:0003UK`.
- Change `COMPLETION` from `85` to `88`.
- Change `CONFIDENCE` from `87` to `90`.
- Keep `CANONICAL_OWNER:00007B`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00007B`.
- Retitle the page from `LivingObjectPane Set Movement Buffer` to `LivingObjectPane Copy Deferred User List Packet` or, if preserving a generic name, `LivingObjectPane Copy Deferred Packet Buffer`.
- Prefer a later filename rename from `0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md` to `0x005a9310-0x005a934a.LivingObjectPaneCopyDeferredUserListPacket.md`. If the implementation pass avoids renaming by-memory files, keep the current file path but update title/body and coverage label.
- Replace the status summary with the exact body behavior:
  - thiscall receiver in `ecx`
  - two stack arguments
  - frees `this+0x13eb20`
  - allocates `packetSize`
  - stores new pointer at `this+0x13eb20`
  - stores byte count at `this+0x13eb24`
  - copies source bytes with `memmove`
  - returns with `ret 8`
- Replace the current open question about movement-buffer layout with resolved field recommendations:
  - `+0x13eb20` = `m_deferredUserListPacket`
  - `+0x13eb24` = `m_deferredUserListPacketSize`
  - movement ring fields are separate at `+0x13eb14/+0x13eb18/+0x13eb1c`
- Add the direct caller inventory:
  - [UID:0003VB] calls at `0x005a7c44`, `0x005a7c64`, `0x005a7c84`
  - [UID:0003US] duplicate calls at `0x005abbdb`, `0x005abbfb`, `0x005abc1b`
- Add the PE route result:
  - no VA pointer hits
  - no RVA pointer hits
  - exactly six direct E8 call hits
- Add the boundary facts:
  - `0x005a9310` start
  - `0x005a9347` `ret 8`
  - `0x005a934a` range end
  - `0x005a934a-0x005a9350` `0xcc` padding
- Populate `RECONSTRUCTION_CPP` with the preferred C++ draft in this report.
- Add a note that exact original source spelling is inferred, not symbol-proven.

## Support Implementation Checklist

Support docs that should be updated when implementation is authorized:

[UID:0001KM] `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`

- Replace table labels `SetMovementBuffer` and `Movement-buffer replacement/copy helper` for `0x005a9310-0x005a934a`.
- New row wording should call it `CopyDeferredUserListPacket` or `CopyDeferredPacketBuffer`.
- Record that all direct callers found are opcode `0x36` user-list deferred-payload tiers, not movement ring logic.
- Keep it as a child of the local-player extension split; do not merge it into [UID:0003VB] or [UID:0003US].

[UID:00007B] `by-class/LivingObjectPane.md`

- Add or sharpen the local-player/user-list packet fields:
  - `m_deferredUserListPacket` at adjusted `this+0x13eb20`
  - `m_deferredUserListPacketSize` at adjusted `this+0x13eb24`
  - `m_userListPacketTick` at adjusted `this+0x13eb28`
  - `m_userListDeferUntilTick` / `m_nextUserListRefreshTick` at adjusted `this+0x13eb2c`
  - `m_skipNextUserListPacket` at adjusted `this+0x13eb30`
- Keep movement history fields separately named at adjusted `this+0x13eb14/+0x13eb18/+0x13eb1c`.
- Move or qualify any `0x005a9310` mention that currently places the helper under movement-history-only wording.
- Add method row `CopyDeferredUserListPacket` under packet/user-list deferred staging.

[UID:0000KU] `by-file/LivingObjectPane.md`

- Keep file route `NexusTK/map/LivingObjectPane.cpp`.
- Move `0x005a9310` out of movement-history-only proposed contents.
- Add it under local-player packet/user-list deferred staging helpers.
- Mention it is called by inline [UID:0003VB] opcode `0x36` and retained duplicate [UID:0003US].

[UID:0003VB] `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`

- Update opcode `0x36` notes/snippets to call `living->CopyDeferredUserListPacket(payload, payloadSize)` if the stronger name is accepted.
- If the project chooses the generic fallback, use `living->CopyDeferredPacketBuffer(payload, payloadSize)`.
- Keep [UID:0003VB] owner/emitter as UserPane; do not move the helper into UserPane ownership.

[UID:0003US] `by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md`

- Update duplicate-handler notes/snippets to use the accepted helper name.
- Preserve the retained duplicate/no-live-route conclusion.
- Keep its C++ blank unless the supervisor separately chooses to emit duplicate-only source.

[UID:0000FQ] `by-class/UserPane.md` and [UID:0000P1] `by-file/UserPane.md`

- No ownership change.
- If these docs mention the opcode `0x36` helper by name, update the callee name to the accepted `LivingObjectPane::CopyDeferredUserListPacket` or `CopyDeferredPacketBuffer`.

[UID:0000OZ] `by-class/UserListDialogPane.md` and [UID:0000FN] `by-file/UserListDialogPane.md`

- No ownership change.
- Only update if they currently imply the dialog owns the deferred raw payload. The current evidence supports LivingObjectPane ownership.

[UID:0000M8] `by-file/PacketBuffer.md`

- No required update.
- Do not route [UID:0003UK] through PacketBuffer.

`by-memory/-ignored.md`

- Optional support cleanup only if coverage tooling wants every alignment gap recorded:

```text
- `0x005a934a-0x005a9350` - alignment padding after [UID:0003UK] before the next collapsed/runtime helper.
  - Why ignored: six `0xcc` bytes immediately after `ret 8` at `0x005a9347`.
  - Evidence: B002 raw PE byte scan on 2026-06-19.
```

`by-memory/-coverage-report.md`

- Add the supervisor-owned row below if accepted. Do not let implementation agents edit this file unless they are explicitly authorized by the supervisor process.

## Exact Supervisor-Owned Coverage Row

Read-only coverage lookup found no exact [UID:0003UK] row and no exact `0x005a9310` target row in `by-memory/-coverage-report.md`. Current support mentions exist inside [UID:0003VB] and [UID:0003US] rows, but the target itself is absent.

The proposed exact row should be inserted in address order after [UID:0003VB] `0x005a76c0-0x005a82bd` and before [UID:0003US] `0x005abb20-0x005abc6f`:

```text
        - [UID:0003UK][0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer](by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md) 0x005a9310-0x005a934a | LivingObjectPane deferred user-list packet copy helper | LivingObjectPaneCopyDeferredUserListPacket : reconstructable : 88% : very-strong : Source-authored `LivingObjectPane` thiscall helper reached by six direct calls from the opcode 0x36 user-list staging paths: inline [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) at 0x005a7c44/0x005a7c64/0x005a7c84 and retained duplicate [UID:0003US][0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md) at 0x005abbdb/0x005abbfb/0x005abc1b. It frees the old heap buffer at `this+0x13eb20`, allocates `packetSize`, copies `packetData` with `memmove`, stores the new pointer at `+0x13eb20`, and stores byte count at `+0x13eb24`. Raw PE route scan found no VA/RVA pointer hits and exactly those six direct E8 calls, all user-list deferred-payload tiers; no movement-history caller was found. Rename recommendation is descriptive `CopyDeferredUserListPacket` / `CopyDeferredPacketBuffer`; reject `SetMovementBuffer` because movement-history ring state is `+0x13eb14/+0x13eb18/+0x13eb1c`, while this helper owns the deferred user-list packet buffer pair. First-draft C++ should be emitted as `void LivingObjectPane::CopyDeferredUserListPacket(const unsigned char *packetData, size_t packetSize)` through [UID:00007B].
```

If the target file is later renamed, update the coverage link label/path accordingly:

```text
[UID:0003UK][0x005a9310-0x005a934a.LivingObjectPaneCopyDeferredUserListPacket](by-memory/0x005a9310-0x005a934a.LivingObjectPaneCopyDeferredUserListPacket.md)
```

## Validator Baseline

Scoped validator baseline command:

> Executable block R001 was removed from this report and preserved verbatim in [0003UK-LivingObjectPaneDeferredPacketBuffer-source-quality-removed.md](0003UK-LivingObjectPaneDeferredPacketBuffer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
root: C:\FastStorage\NTK_Sources\source-3\project-documentation
mode: file
apply: False
scanned markdown files: 1
ok: 1
ok 0003UK by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md UID header exists
stats_incremental_skip 0003UK project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

The validator run was dry-run only. It did not edit by-memory files, support docs, coverage, or generated stats. It emitted unrelated global autogen diagnostics outside the scoped target; no target-specific validator failure was present.

Recommended implementation-time validator scope:

- Target file [UID:0003UK]
- Split index [UID:0001KM]
- Class owner [UID:00007B]
- File owner [UID:0000KU]
- Caller docs [UID:0003VB] and [UID:0003US] if edited
- UserPane support docs [UID:0000FQ]/[UID:0000P1] only if edited
- Coverage report only under supervisor-owned coverage workflow

## Final Status

This report closes the target source-quality blockers for naming, fields, caller semantics, ownership/source placement, split/range boundaries, and first-draft C++ eligibility.

No `by-*` documentation file was edited.

`by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003UK","source_path":"executed-b-agent-research/B002/0003UK-LivingObjectPaneDeferredPacketBuffer-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
