** TARGET-REPORT-UID:00013K **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013K EncoderFinalize Source-Quality Report

Status: FINISHED

## Target And Scope

- Assignment: B008 report-only source-quality pass for [UID:00013K] `EncoderFinalize`.
- Target path: `source-3/project-documentation/by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00013K-EncoderFinalize-source-quality.md`
- Current target metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, blank formal C++.
- Current route: [UID:00013K] emits through [UID:00004F] `Encoder` to [UID:0000J1] `Encoder`, which resolves to `auto-generated/NexusTK/util/Encoder.cpp`.
- Report-only rules followed: no target/support by-* docs were edited, generated source/reports were not edited, IDA DB was not edited, and `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Keep [UID:00013K] as the exact source-bearing `Encoder::Finalize` method owned by [UID:00004F] `Encoder`, emitted through [UID:00004F] to [UID:0000J1] `NexusTK/util/Encoder.cpp`.

Recommended target metadata after implementation:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The old target statement that formal C++ remains blank because the page is below a `95/95` threshold is stale. The current gate is source-route and combined-score based: this target is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:00004F`, resolves to a generated source root, and already averages `(84 + 90) / 2 = 87`. After this source-quality detail and first-draft C++ are incorporated, `88/92` is defensible while still below final-audit range because original field names and full header shape remain inferred.

Recommended source-facing signature:

```cpp
bool Encoder::Finalize(unsigned int *outBytesWritten);
```

Preferred field-name direction for this method: `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable`. These are behavior-backed source-quality names, not recovered debug symbols. If the accepted Encoder header later standardizes `m_buffer` / `m_cursor` / `m_isValid`, rename this draft consistently without changing behavior.

## Evidence Checked

- Target doc [UID:00013K] `by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md`.
- Adjacent Encoder exact child docs: constructor [UID:00013C], destructor [UID:00013E], `WriteByte` [UID:00013F], `WriteShort` [UID:00013G], `WriteInt` [UID:00013H], `WriteBytes` [UID:00013I], `Initialize` [UID:00013J], no-op virtual [UID:00013L], scalar deleting destructor [UID:00013V], and vtable data [UID:0003IA].
- Owner/source support docs: [UID:00004F] `by-class/Encoder.md`, [UID:0000J1] `by-file/Encoder.md`, [UID:0000HQ] `by-file/BinaryCodec.md`, [UID:0001TS] `BinaryCodecCursorLayout`, [UID:0001X1] `BinaryCodecVtables`, and `by-project-structure/proposed-source-tree.md`.
- Caller docs: [UID:0001JN] `TextEditPaneSerialization` and [UID:0000UM] `EncodeTextEditState_0058E490`.
- Generated route state: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/NexusTK/util/Encoder.cpp`, and `project-level/-auto-completion-stats.md`.
- Manual coverage row state: `by-memory/-coverage-report.md` near the Encoder rows.
- Unresolved-name state: `project-level/-unresolved.md`, which still reports `sub_4A55E0` in the target page and `BinaryCodecCursorLayout`.
- Prior reports used only as leads and rechecked against current evidence: B011 same-UID report, B004 `EncoderInitialize`, B014 `EncoderWriteBytes`, B015 `EncoderWriteShort`, and B002 `EncoderCore` executed/index report.
- IDA MCP availability was checked with an HTTP `tools/list` request to `127.0.0.1:13337/mcp`; it was unavailable: `Unable to connect to the remote server`.
- Local PE byte verification was performed instead against both available copies:
  - `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Both hashes match: MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

## Local PE Facts

PE facts:

- Image base: `0x400000`.
- `.text` section: RVA `0x1000`, virtual size `0x20b4ac`, raw pointer `0x400`, raw size `0x20b600`.
- Target VA: `0x004a55e0`.
- Target size: `0x41` / 65 bytes.
- End-exclusive range: `0x004a55e0-0x004a5621`.
- Preceding padding: `0x004a55de-0x004a55e0` is `cc cc`.
- Following padding: `0x004a5621-0x004a5630` is fifteen `cc` bytes.

Target bytes:

```text
55 8b ec 53 56 8b f1 8b 4d 08 8a 5e 11 85 c9 74
05 8b 46 0c 89 01 8b 56 0c 8a c3 8b 4e 04 c6 04
0a 00 c7 46 04 00 00 00 00 c7 46 08 00 00 00 00
c7 46 0c 00 00 00 00 c6 46 11 01 5e 5b 5d c2 04
00
```

Disassembly:

```asm
004a55e0: push    ebp
004a55e1: mov     ebp, esp
004a55e3: push    ebx
004a55e4: push    esi
004a55e5: mov     esi, ecx
004a55e7: mov     ecx, dword ptr [ebp + 8]
004a55ea: mov     bl, byte ptr [esi + 0x11]
004a55ed: test    ecx, ecx
004a55ef: je      0x4a55f6
004a55f1: mov     eax, dword ptr [esi + 0xc]
004a55f4: mov     dword ptr [ecx], eax
004a55f6: mov     edx, dword ptr [esi + 0xc]
004a55f9: mov     al, bl
004a55fb: mov     ecx, dword ptr [esi + 4]
004a55fe: mov     byte ptr [edx + ecx], 0
004a5602: mov     dword ptr [esi + 4], 0
004a5609: mov     dword ptr [esi + 8], 0
004a5610: mov     dword ptr [esi + 0xc], 0
004a5617: mov     byte ptr [esi + 0x11], 1
004a561b: pop     esi
004a561c: pop     ebx
004a561d: pop     ebp
004a561e: ret     4
```

Direct rel32 call scan results for the active Encoder writer family:

| Target | Direct call sites found in local PE |
| --- | --- |
| `0x004a4e70` constructor | `0x0058e4e4` |
| `0x004a55c0` `Initialize` | `0x0058e54b` |
| `0x004a5480` `WriteBytes` | `0x0058e56e`, `0x0058e5ba`, `0x0058e5e3`, `0x0058e612` |
| `0x004a4ec0` `WriteByte` | `0x0058e57b` |
| `0x004a4ff0` `WriteInt` | `0x0058e58b` |
| `0x004a4f00` `WriteShort` | `0x0058e59a`, `0x0058e5c9`, `0x0058e5f8` |
| `0x004a55e0` `Finalize` | `0x0058e624` |
| `0x004a4ea0` destructor | `0x0058e66c` |

Caller context around the finalization path, disassembled linearly from `0x0058e4d8`:

```asm
0058e61d: push    eax
0058e61e: lea     ecx, [ebp - 0x802c]
0058e624: call    0x4a55e0
0058e629: push    dword ptr [ebp - 0x8018]
0058e62f: call    0x516030
0058e634: mov     ecx, eax
0058e636: call    0x516050
0058e63b: push    dword ptr [ebp - 0x8018]
0058e641: mov     ecx, dword ptr [ebp - 0x8034]
0058e647: mov     esi, eax
0058e649: lea     eax, [ebp - 0x8010]
0058e64f: push    eax
0058e650: push    esi
0058e651: call    0x516220
0058e656: mov     eax, dword ptr [ebp - 0x8038]
0058e65c: mov     cx, word ptr [ebp - 0x8018]
0058e663: mov     word ptr [eax], cx
0058e666: lea     ecx, [ebp - 0x802c]
0058e66c: call    0x4a4ea0
```

This proves `Finalize` writes a 32-bit byte count to a stack local, the caller uses that full local for allocation and copy, and only later truncates to a 16-bit caller-facing output field. The `Finalize` source signature should therefore use a 32-bit count pointer (`unsigned int *`, `uint32_t *`, or project typedef), not `unsigned short *`.

## Heuristic / Inference Reanalysis And Validation

### 1. Source-bearing method versus no-code glue

Conclusion: [UID:00013K] is source-bearing `Encoder` project code and should receive first-draft C++.

Evidence:

- The function is a normal `thiscall` method with a real state-mutating body and `ret 4`.
- It is not a thunk, not a scalar deleting destructor, not a vtable-only support body, not a library/runtime helper, and not an EH cleanup.
- It has one direct source caller, [UID:0001JN] `TextEditPaneSerialization`, at `0x0058e624`.
- It has no callees and does not call allocation, copy, free, flush, or runtime helpers.
- [UID:00013D] `EncoderCore` is now the non-emitting split/index; exact children, including [UID:00013K], carry source ownership.
- `auto-generated/-ag-memory-coverage.md` already routes [UID:00013K] through [UID:00004F] to `auto-generated/NexusTK/util/Encoder.cpp`; the generated file currently shows only an empty emitter marker because the formal C++ block is blank.

Rejected alternatives:

- Compiler glue/no-code: rejected because the method writes the final terminator, returns validity, and resets user-visible Encoder state.
- Aggregate-only C++: rejected because the parent aggregate [UID:00013D] is explicitly non-emitting and overlaps exact child pages.
- Runtime helper: rejected because the body touches only `Encoder` instance fields and has no import/library signature.

### 2. Source-facing name and signature

Best source-facing name: `Encoder::Finalize`.

Best first-draft signature:

```cpp
bool Encoder::Finalize(unsigned int *outBytesWritten);
```

Evidence:

- Current target, class, file, core index, generated route, and prior simroot-derived output all name this body `Finalize`.
- It is paired with [UID:00013J] `Encoder::Initialize`; initialize attaches a caller buffer, finalize terminates and detaches it.
- The method returns the previous valid/writable byte from `+0x11`, making `bool` the best source type.
- The only parameter is optional. If non-null, it receives the current write cursor at `+0x0c` as a 32-bit value.
- The caller at `0x0058e624` passes the address of a dword stack local, then uses that dword for allocation/copy size.

Rejected alternatives:

- `Flush`: rejected because there is no file/socket stream, no callee, and no external target to flush.
- `Reset`: rejected because reset is only the second half of the method; the method also writes a final NUL, reports byte count, and returns prior validity.
- `Detach`: plausible as part of behavior, but weaker than `Finalize` because it misses the NUL write and success return.
- `Finish`: plausible synonym, but weaker than existing `Initialize`/`Finalize` naming across current docs and generated route.
- `unsigned short *outBytesWritten`: rejected because this body writes a dword through the pointer. The caller truncates later for its own API, but `Finalize` itself does not.
- `void Encoder::Finalize(...)`: rejected because `al` returns the saved validity byte and caller can observe it, even if the currently documented caller ignores or does not branch on it.

Type caveat: if the accepted Encoder header uses `uint32_t *`, `DWORD *`, `int *`, or a project typedef, the implementation can use that type consistently. For a mid-2000s C++ style draft without relying on C++11 fixed-width headers, `unsigned int *` is the least surprising spelling.

### 3. Field layout and source-quality names

Best field mapping for the whole Encoder writer family:

| Offset | Role | Preferred draft name | Evidence |
| --- | --- | --- | --- |
| `+0x00` | vtable pointer | vptr | Constructor/destructor/scalar deleting destructor store `0x006192cc`; vtable data [UID:0003IA]. |
| `+0x04` | caller-owned output byte buffer | `m_outputBuffer` | `Initialize` stores it; writers write/copy through it; `Finalize` writes `m_outputBuffer[m_writePos] = 0` and then clears it. |
| `+0x08` | writable capacity/limit | `m_capacity` | Writers compare it against `m_writePos + payload + 1`; `Finalize` clears it. |
| `+0x0c` | write cursor / bytes written | `m_writePos` | Writers advance it; `Finalize` reports it and uses it as the terminator offset. |
| `+0x10` | scalar byte-order flag | `m_useBigEndian` | Constructor sets flags word `0x0101`; scalar writers use nonzero for high-byte-first writes. `Finalize` does not touch it. |
| `+0x11` | valid/writable flag | `m_isWritable` | Constructor/Initialize/Finalize set it to `1`; writers test it and clear it on overflow; `Finalize` returns previous value. |

Rejected field interpretations:

- `+0x08` as bytes written: rejected because `+0x0c` is what `Finalize` writes through the output pointer.
- `+0x11` as "buffer attached": rejected because `Finalize` sets it to `1` after clearing the buffer pointer and capacity.
- `+0x04` as owned buffer: rejected because destructor does not free it and `Finalize` only detaches.
- Opaque `flags` source model for `+0x10/+0x11`: rejected for first-draft method bodies because scalar writers and `Finalize` address the bytes independently.

### 4. Exact behavior and edge cases to preserve

Exact behavior:

1. Save the previous valid/writable byte from `this+0x11`.
2. If `outBytesWritten` is non-null, write the current cursor dword `this+0x0c` through it.
3. Read cursor again from `this+0x0c`.
4. Set the return value register byte from the saved validity byte before the terminator write/reset sequence.
5. Write `0` to `*(this+0x04 + this+0x0c)`.
6. Clear buffer pointer `+0x04`.
7. Clear capacity `+0x08`.
8. Clear cursor `+0x0c`.
9. Set valid/writable byte `+0x11` to `1`.
10. Return the saved previous validity byte.

Important exact-source policy:

- Do not add a null-buffer guard. The binary unconditionally writes the terminator through `m_outputBuffer + m_writePos`.
- Do not check `m_isWritable` before writing the terminator. The binary writes the terminator even if the saved valid byte is false.
- Do not free or delete `m_outputBuffer`. The caller owns it.
- Do not clear or reset `m_useBigEndian`; byte-order state survives finalize/detach.
- Do not count the trailing NUL in `outBytesWritten`. The cursor is stored before writing the terminator, and writers reserve capacity for this NUL.
- Do not include caller allocation/copy/destructor behavior in this method's C++ block. Those belong to [UID:0001JN] `TextEditPaneSerialization`.

Why unconditional NUL write is source-plausible: sibling writers reserve one extra byte in their capacity checks (`WriteByte` requires cursor + 2, `WriteShort` cursor + 3, `WriteInt` cursor + 5, `WriteBytes` cursor + byteCount + 1). `Finalize` consumes that reserved byte. The lack of an additional guard is consistent with this small utility class.

### 5. Caller and reachability

Conclusion: the only currently confirmed behavioral caller is TextEditPane serialization, and it proves liveness but not ownership transfer.

Evidence:

- Direct local PE call scan found one direct call to `0x004a55e0`: `0x0058e624`.
- `TextEditPaneSerialization` constructs a stack `Encoder`, initializes it against a `0x7ffe` writable window inside a `0x8000` stack buffer, writes table/list payloads, finalizes into a dword local, allocates exactly that dword count, copies the stack buffer, writes a 16-bit out size for the caller, and destroys the stack Encoder.
- The TextEditPane helper reads TextEditPane-owned state; it consumes `Encoder` but does not own the Encoder vtable, fields, source file, or methods.

Rejected ownership from caller:

- [UID:0000ON] `TextEditPane` and [UID:0001JN] should remain caller/consumer context only.
- The raw [UID:0000EM]/[UID:0000OM] `TextEditControlPane` forwarding stub exposes the serializer but does not own this Encoder method.

### 6. Boundary, split, and source placement

Target boundary conclusion: no split or merge is needed for [UID:00013K].

Evidence:

- `0x004a55e0-0x004a5621` is a complete method with a single `ret 4`.
- `0x004a55de-0x004a55e0` is two bytes of `0xcc` alignment after [UID:00013J] `Initialize`.
- `0x004a5621-0x004a5630` is fifteen bytes of `0xcc` alignment before [UID:00013L] `EncoderNoopVirtual`.
- [UID:00013L] is a one-byte vtable-only no-op virtual and must not be folded into `Finalize`.
- [UID:00013D] remains the non-emitting split/index over exact children and raw helper islands; this exact child remains a source-bearing method page.

Source placement conclusion:

- Direct semantic owner: [UID:00004F] `Encoder`.
- Concrete source root: [UID:0000J1] `Encoder`, `NexusTK/util/Encoder.cpp`.
- Source-family coordinator/context: [UID:0000HQ] `BinaryCodec`.

Rejected placements:

- Direct [UID:0000HQ] `BinaryCodec`: rejected because this body is not shared Encoder/Decoder code and mutates only Encoder instance state.
- Direct [UID:0000J1] file owner: rejected as `CANONICAL_OWNER` because a class method's narrow owner is the class; the file root remains the output route.
- [UID:0000ON] `TextEditPane`: rejected because it is only the caller.
- Packet/network owner: rejected because no packet sender, socket path, or packet-buffer owner calls this method.
- No owner/no-code: rejected because class ownership and route are established.

### 7. Compiler-generated/raw-name cleanup

Current unresolved state:

- `project-level/-unresolved.md` still reports `sub_4A55E0` in the target page and in `BinaryCodecCursorLayout`.
- `BinaryCodecCursorLayout` records a raw rename-arrow list containing `sub_4A55E0 -> Encoder_Finalize`.

Recommendation:

- Use `Encoder::Finalize` in source-facing prose and formal C++.
- Use `Encoder_Finalize` only when referring to IDA database naming.
- Replace active raw `sub_4A55E0` prose in the target with address/source-name wording, for example: "`0x004a55e0` / `Encoder::Finalize`, size `0x41`".
- In `BinaryCodecCursorLayout`, replace the raw rename-arrow fragment for this function with address-based wording: "`0x004a55e0` is named `Encoder_Finalize` / `Encoder::Finalize` in the current source-quality model." This preserves audit value without leaving a generated placeholder token as an unresolved source name.

Rejected raw-name policy:

- Do not emit `sub_4A55E0`, `meth_0x4a55e0`, or `Encoder_Finalize` as the C++ method name.
- Do not leave the target's source-facing status dependent on raw IDA labels now that the source name is resolved enough for first-draft output.

### 8. Open questions and score impact

Resolved for this target:

- Exact range and padding.
- Source-bearing versus compiler-generated/no-code.
- Direct owner and emitter route.
- Source-facing method role and signature.
- Return semantics and output-parameter width.
- Field roles and best source-quality member names.
- TextEditPane caller role versus ownership.
- First-draft C++ eligibility.

Remaining uncertainty, not blocking first-draft C++:

- Exact original member names are not symbol-proven. Keep field-name wording descriptive and scores below final audit.
- Exact original header placement (`Encoder.h`, `BinaryCodec.h`, or compact util header) remains a class/file-family question. It does not block this method body in `Encoder.cpp`.
- Other raw helper islands inside [UID:00013D] still need separate exact child research before the full Encoder class reaches final-source completion.
- IDA MCP was unavailable in this current session; local PE bytes and current IDA-backed docs are sufficient for the exact method but should keep confidence below `95+`.

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:00013K] after supervisor approval with:

```cpp
bool Encoder::Finalize(unsigned int *outBytesWritten)
{
    const bool wasWritable = (m_isWritable != 0);

    if (outBytesWritten != NULL) {
        *outBytesWritten = m_writePos;
    }

    m_outputBuffer[m_writePos] = 0;
    m_outputBuffer = NULL;
    m_capacity = 0;
    m_writePos = 0;
    m_isWritable = true;

    return wasWritable;
}
```

Draft rationale:

- Uses mid-2000s-compatible C++ spelling (`NULL`, `unsigned int`) rather than C++11-only `nullptr` or fixed-width headers.
- Preserves the previous-state return.
- Preserves output count before detach/reset.
- Preserves the unconditional trailing NUL write and does not count that byte.
- Preserves detach semantics and does not free the caller-owned buffer.
- Preserves byte-order flag at `+0x10`.
- Stays within the exact `0x004a55e0-0x004a5621` target range.

If the accepted class declaration uses alternate field names, adjust only names:

```text
m_outputBuffer <-> m_buffer
m_capacity <-> m_bufferCapacity
m_writePos <-> m_cursor
m_isWritable <-> m_isValid
```

The behavior and field offsets are unchanged.

## Recommended Exact Target Doc Changes

Apply only after a supervisor implementation callback.

Target: `source-3/project-documentation/by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md`

1. Metadata:

```text
COMPLETION:84 -> 88
CONFIDENCE:90 -> 92
CANONICAL_OWNER:00004F unchanged
RECONSTRUCTABLE:TRUE unchanged
EMITTER_UIDS:00004F unchanged
EMITTER_POSITION_OPTIONAL unchanged blank
```

2. Replace stale status text:

Replace:

```text
- Parent attachment: attached to [UID:00004F][Encoder](by-class/Encoder.md) because this page is now `84/90`, the class is `82/86`, and [UID:0000J1][Encoder](by-file/Encoder.md) is the class's concrete file parent.
- Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold.
```

With:

```text
- Parent/emitter route: attached to [UID:00004F][Encoder](by-class/Encoder.md) and emitted through that class to [UID:0000J1][Encoder](by-file/Encoder.md). The direct class is now `86/90`, the file root is `86/88`, and the route surfaces to `auto-generated/NexusTK/util/Encoder.cpp`.
- C++ gate: eligible under the active combined-score/emitter rule (`RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00004F`, valid generated source route, and recommended `(88 + 92) / 2 = 90`). The old `95/95` no-code threshold is stale; first-draft C++ is ready for this exact source-bearing method.
```

3. Replace the raw-name evidence bullet:

Replace:

```text
- `lookup_funcs` maps `0x004a55e0` to `sub_4A55E0`, size `0x41`; `0x004a5621` is not a function, and the next modeled Encoder method is the no-op virtual at [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md).
```

With:

```text
- IDA-backed docs and B008's 2026-06-19 local PE byte check map `0x004a55e0` to the exact source-facing `Encoder::Finalize` method, size `0x41` / 65 bytes; `0x004a5621` is not a function, and the next modeled Encoder method is the no-op virtual at [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md).
```

4. Add a source-shape section:

```markdown
## Source Shape And Field Names

Recommended source-facing signature: `bool Encoder::Finalize(unsigned int *outBytesWritten)`.

The method saves the previous valid/writable flag at `+0x11`, optionally stores the current write position `+0x0c` as a 32-bit byte count, writes a trailing NUL byte at `outputBuffer[writePos]`, clears output buffer `+0x04`, capacity `+0x08`, and write position `+0x0c`, restores valid/writable `+0x11` to true, and returns the saved previous valid/writable state.

The first-draft C++ uses descriptive member names `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable`; these names are behavior-backed but not proven original symbols. The byte-order flag at `+0x10` is intentionally left unchanged.
```

5. Add edge-case/source-fidelity notes:

```markdown
## Source-Fidelity Notes

Do not add a null-buffer guard or valid-state guard around the trailing NUL write; the machine code writes the terminator unconditionally. Do not free the buffer; `Encoder` does not own the caller-supplied storage. Do not count the final NUL in the returned byte count. Sibling writers reserve one trailing byte for this method, and `Finalize` consumes that reserve.
```

6. Populate the formal C++ block with the first-draft body above.

7. Add score/gate rationale:

```markdown
## Score And Gate Rationale

Completion is raised to `88` because this source-quality pass resolves the stale no-code gate, exact source signature, return/output semantics, field-name directions, caller role, no-code rejection, padding boundary, and first-draft C++ for the exact method. Confidence is raised to `92` because the method is a compact no-callee body verified from local PE bytes and current IDA-backed docs; confidence remains below final audit because exact original member names, header split, and broader Encoder helper islands remain descriptive/incomplete.
```

8. Add a change-log entry:

```markdown
- 2026-06-19 B008 source-quality report:
  - Before: `COMPLETION:84`, `CONFIDENCE:90`, correct owner/emitter route, blank formal C++, and stale no-code wording tied to an obsolete `95/95` threshold.
  - Recommended after implementation: `COMPLETION:88`, `CONFIDENCE:92`, unchanged owner/emitter route, raw-name cleanup for `sub_4A55E0`, and first-draft `bool Encoder::Finalize(unsigned int *outBytesWritten)` C++ under the active combined-score/emitter gate.
  - Evidence: B008's local PE check confirms exact `0x004a55e0-0x004a5621` bytes, `ret 4`, previous valid/writable return from `+0x11`, optional dword byte-count output from `+0x0c`, unconditional trailing NUL write through `+0x04 + +0x0c`, buffer/capacity/cursor reset, valid reset, one direct TextEditPaneSerialization caller at `0x0058e624`, no callees, matching hashes for both available `NexusTK.exe` copies, two-byte padding after Initialize, and fifteen-byte padding before the no-op virtual. IDA MCP was unavailable in this session, so final-audit scoring remains capped.
```

## Recommended Support Doc Changes

Apply only if included in a later supervisor implementation callback. These are support-doc changes that preserve report-level detail rather than compact summaries.

1. `source-3/project-documentation/by-class/Encoder.md`
   - No owner/emitter metadata change required.
   - Update the method row from `Finalize` to `Finalize(unsigned int *outBytesWritten)`.
   - Add or update state naming to prefer `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable` as current first-draft member directions, while noting exact original names are inferred.
   - Add a note that [UID:00013K] is source-bearing and first-draft C++ ready; [UID:00013L] no-op virtual and [UID:00013V] scalar deleting destructor remain compiler/vtable support and should not be represented as handwritten method bodies.

2. `source-3/project-documentation/by-file/Encoder.md`
   - No score change required.
   - Under proposed contents/evidence, note that [UID:00013K] now resolves to first-draft `bool Encoder::Finalize(unsigned int *outBytesWritten)` and should emit from the exact child page, not from the broad [UID:00013D] index.
   - Preserve `NexusTK/util/Encoder.cpp` as the concrete source root and [UID:0000HQ] `BinaryCodec` as family coordinator only.

3. `source-3/project-documentation/by-file/BinaryCodec.md`
   - No target-specific score change required.
   - Replace stale phrase `90/90+ code-entry gate` with current combined-score/emitter gate wording. This is coordinator wording cleanup; it does not block [UID:00013K].
   - Keep `BinaryCodec.cpp` as coordination context, not the direct owner for `Encoder::Finalize`.

4. `source-3/project-documentation/by-type/by-struct/BinaryCodecCursorLayout.md`
   - No metadata change required.
   - Replace the raw rename-arrow occurrence containing `sub_4A55E0` with address/source-name wording: "`0x004a55e0` is treated as `Encoder_Finalize` / `Encoder::Finalize`."
   - Add that `Finalize` stores `+0x0c` as a 32-bit byte count before NUL termination and reset.
   - Add current first-draft field-name direction for Encoder code: `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, `m_isWritable`.

5. `source-3/project-documentation/by-memory/0x004a4e70-0x004a5621.EncoderCore.md`
   - No metadata change required; keep it `RECONSTRUCTABLE:FALSE` with blank emitters.
   - Update the [UID:00013K] table row to `Encoder::Finalize(unsigned int *outBytesWritten)`.
   - Add that exact children own first-draft source emission; the parent index remains non-emitting because of overlap and raw helper islands.

6. `source-3/project-documentation/by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md` and `source-3/project-documentation/by-item/EncodeTextEditState_0058E490.md`
   - No ownership or metadata change required.
   - Add a concise caller note: `Encoder::Finalize(unsigned int *outBytesWritten)` writes a dword count into the local at `[ebp-0x8018]`; the caller uses that dword for exact allocation/copy, then truncates to a 16-bit external output size. This supports a 32-bit `Finalize` output pointer despite TextEditPane's public out-size storage being 16-bit.

7. `auto-generated/NexusTK/util/Encoder.cpp`
   - Do not edit by hand. After implementation and validator/autogen, [UID:00013K] should no longer be an empty emitter marker.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B008. Supervisor should replace the current [UID:00013K] row immediately after [UID:00013J] `EncoderInitialize` and before ignored padding `0x004a5621-0x004a5630` with:

```markdown
    - [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) 0x004a55e0-0x004a5621 | method | EncoderFinalize : reconstructable : 88% : very strong : B008 2026-06-19 source-quality review clears the active combined-score/emitter C++ gate for exact source-bearing `bool Encoder::Finalize(unsigned int *outBytesWritten)` through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md). Local PE bytes and current IDA-backed docs confirm the `0x41`-byte body, `ret 4`, one direct TextEditPaneSerialization caller at `0x0058e624`, no callees, previous valid/writable byte return from `+0x11`, optional dword byte-count output from write cursor `+0x0c`, unconditional trailing NUL write at `m_outputBuffer[m_writePos]`, buffer/capacity/cursor detach reset at `+0x04/+0x08/+0x0c`, valid reset to true, byte-order flag `+0x10` left unchanged, two-byte padding after Initialize, fifteen-byte padding before EncoderNoopVirtual, and no buffer ownership/free behavior. First-draft C++ is recommended with descriptive field names `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable`; exact original member names remain inferred rather than symbol-proven.
```

No neighboring coverage row deletion or insertion is recommended for this target.

## Validator Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Minimum target validation:

> Executable block R001 was removed from this report and preserved verbatim in [00013K-EncoderFinalize-source-quality-removed.md](00013K-EncoderFinalize-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the recommended support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [00013K-EncoderFinalize-source-quality-removed.md](00013K-EncoderFinalize-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected post-implementation checks:

> Executable block R003 was removed from this report and preserved verbatim in [00013K-EncoderFinalize-source-quality-removed.md](00013K-EncoderFinalize-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results:

- Target file validator exits cleanly.
- Autogen still routes [UID:00013K] through [UID:00004F] to `auto-generated/NexusTK/util/Encoder.cpp`.
- Generated `Encoder.cpp` contains the first-draft `Encoder::Finalize` body instead of the empty [UID:00013K] marker.
- `sub_4A55E0` disappears from `project-level/-unresolved.md` if both the target and `BinaryCodecCursorLayout` raw-name text are cleaned.

## IDA Rename / Type / Comment Recommendations

Do not apply IDA DB changes during this report-only pass. If a later IDA source-quality callback is approved:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x004a55e0` | Rename to `Encoder_Finalize`. Type as `bool __thiscall Encoder_Finalize(Encoder *this, unsigned int *outBytesWritten)` or accepted project typedef equivalent. | High |
| Encoder field `+0x04` | `m_outputBuffer`; `unsigned char *` / byte pointer. | High role, medium exact spelling |
| Encoder field `+0x08` | `m_capacity`; 32-bit integer capacity. | High role, medium exact spelling |
| Encoder field `+0x0c` | `m_writePos`; 32-bit integer write cursor / byte count. | High role, medium exact spelling |
| Encoder field `+0x10` | `m_useBigEndian`; byte/bool scalar byte-order flag. | High role, medium exact spelling |
| Encoder field `+0x11` | `m_isWritable`; byte/bool valid writer state. | High role, medium exact spelling |

Suggested function comment:

```text
Encoder::Finalize stores the current write cursor through an optional 32-bit output pointer, writes the trailing NUL reserved by the writer methods, detaches the caller-owned output buffer, resets capacity/cursor, restores the writable flag, and returns the previous writable/valid state. Direct caller is TextEditPaneSerialization at 0x0058e624.
```

## Rejected Alternatives Summary

- No-code/compiler glue: rejected by real state mutation, direct caller, and non-thunk body.
- `Flush` or I/O-style finalization: rejected by no callees and no external stream/file/socket.
- `Reset` or `Detach` as primary source name: rejected because they omit byte-count output, terminator write, and validity return.
- TextEditPane ownership: rejected because TextEditPane is the consumer and owns the serialized data, not the Encoder implementation.
- BinaryCodec direct ownership: rejected because the exact body is `Encoder`-only state.
- Packet/network placement: rejected by caller scan and existing separate packet-buffer helper families.
- Null-safe or valid-gated C++ rewrite: rejected because the binary writes the NUL unconditionally.
- 16-bit output pointer: rejected because the method writes a dword; caller truncation happens after allocation/copy.

## Implementation Readiness

Ready after supervisor acceptance.

The target has exact bytes, exact range, exact caller, no callees, correct owner/emitter route, resolved source-facing signature, resolved field roles, a policy-stale no-code blocker, and a first-draft body that stays inside the by-memory range. Remaining uncertainty is limited to original spelling of member names and header organization; that caps final-audit scoring but should not block first-draft C++.

## Changed Files In This Report Pass

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00013K-EncoderFinalize-source-quality.md`
- Modified: none outside this report.
- Moved/archived: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00013K-EncoderFinalize-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00013K"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013K-EncoderFinalize-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00013K-EncoderFinalize-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
