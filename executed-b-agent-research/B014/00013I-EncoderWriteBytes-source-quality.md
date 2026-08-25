** TARGET-REPORT-UID:00013I **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013I EncoderWriteBytes Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00013I] `0x004a5480-0x004a54c6.EncoderWriteBytes` as an exact source-bearing `Encoder` method owned by [UID:00004F] `Encoder`, routed through [UID:00004F] to [UID:0000J1] `NexusTK/util/Encoder.cpp`.
- Final disposition: no split, rename, owner change, or emitter change is needed for the target range. Replace stale below-95 no-code reasoning with the active combined-score/emitter gate and add first-draft C++ during the supervisor implementation callback.
- Required action after supervisor acceptance: update the target doc metadata/body/C++ block, apply the support-doc boundary corrections listed below, run scoped validators, and refresh autogen. Do not edit `by-memory/-coverage-report.md`; exact supervisor-owned replacement row text is included below.
- Recommended target score: `84/90 -> 88/90`.
- Confidence: high for exact behavior, range, caller set, field effects, owner/emitter route, helper roles, and first-draft C++ readiness. Keep below final audit because exact original member/helper names and full Encoder header/source completion remain descriptive rather than debug-symbol proven.

Recommended target metadata after implementation:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Target

- Target UID: `00013I`
- Target path: `source-3/project-documentation/by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/00013I-EncoderWriteBytes-source-quality.md`
- Assignment id: `B014-goal2-encoder-write-bytes-source-quality-00013I-20260619`
- Current scores and route: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists [UID:00013I] as `emits`, owner `00004F`, emitter `00004F`, generated path `auto-generated/NexusTK/util/Encoder.cpp`, coded `no`.
- Current generated source state: `auto-generated/NexusTK/util/Encoder.cpp` contains an empty marker for [UID:00013I], proving the route surfaces but no formal C++ has been entered.

## Supervisor Active Recheck

- This was a report-only B014 pass. I did not edit the target by-memory page, support by-* docs, generated reports/source, IDA DB, project-level reports, or `by-memory/-coverage-report.md`.
- The previously returned B014 `0002NQ-ClanStringListPaneDrawItem-source-quality.md` report remains untouched and pending supervisor review/implementation workflow.
- A same-UID B001 report exists at `Agent-B001/research/00013I-EncoderWriteBytes-source-quality.md`. I treated it as a lead only and independently rechecked current docs, generated route state, manual coverage text, IDA MCP availability, and local PE bytes.
- IDA MCP check on 2026-06-19 against `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. Current-session machine-code evidence therefore comes from direct local PE parsing/disassembly of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Local PE hash used for byte checks: MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

## Executive Recommendation

The best source-facing target shape is:

```cpp
void Encoder::WriteBytes(const void *data, unsigned int byteCount);
```

The method appends a caller-supplied byte span to the current output buffer, reserves one final byte for [UID:00013K] `Encoder::Finalize` to append the trailing NUL, clears the writable/valid flag on overflow, and advances the write cursor after a successful copy. It is an `Encoder` instance method, not a `BinaryCodec` free function, not a TextEditPane helper, and not a packet/network writer.

The target's stale statement that final C++ is blank because the page is below a `95/95` threshold should be removed. Current by-structure policy allows reconstruction C++ when the item is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank `EMITTER_UIDS` that surface to a valid generated source root, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided source shape and dependencies are strong enough. This target already averages `(84 + 90) / 2 = 87`, and the recommended `88/90` update clears both the 85/85 quality floor and the combined-score C++ gate with room for the new source-quality detail and first-draft C++.

## Inference Research Guidance Check

`by-structure.md` separates direct semantic ownership from output routing. The narrow direct owner for this exact method is [UID:00004F] `Encoder`; output routes through that class to [UID:0000J1] `Encoder`, a valid `NexusTK/util/` source root. [UID:0000HQ] `BinaryCodec` remains the family coordinator for shared cursor layout and Encoder/Decoder context, not the direct owner of this method.

`inference_research.md` warns that consumer xrefs alone do not prove source ownership. Here ownership is supported by the Encoder method family, class/file pages, vtable/lifecycle context, shared cursor layout, exact field effects, and generated route. The [UID:0001JN] `TextEditPaneSerialization` calls prove reachability and use, not ownership transfer.

Existing assumptions rechecked:

- Validated: exact target range `0x004a5480-0x004a54c6`.
- Validated: target is a complete source-authored `Encoder::WriteBytes` body with `ret 8`.
- Validated: direct owner/emitter route [UID:00004F] `Encoder` -> [UID:0000J1] `Encoder.cpp`.
- Validated: valid flag, capacity, cursor, output buffer, final-NUL reserve, no partial copy on overflow, and cursor advance behavior.
- Corrected: adjacent raw helper endpoints in support docs are stale. Direct PE bytes show the first raw helper ends at `0x004a558d`, not `0x004a558b`, and the second helper ends at `0x004a55b6`, not `0x004a55b4`.
- Corrected: old below-95 no-code wording is stale and should not block first-draft C++ for this exact method.

## Heuristic / Inference Reanalysis And Validation

### 1. Source-facing name and signature

Best source-facing signature:

```cpp
void Encoder::WriteBytes(const void *data, unsigned int byteCount);
```

Evidence:

- The target page, [UID:00004F] `Encoder`, [UID:0000J1] `Encoder`, and [UID:00013D] `EncoderCore` all identify this exact child as `WriteBytes`.
- Local PE disassembly proves a `thiscall` method with `ecx = Encoder*`, `[ebp+0x08]` as source pointer, `[ebp+0x0c]` as byte count, and `ret 8`.
- The body passes `[ebp+0x08]` and `[ebp+0x0c]` to the copy helper, confirming a source pointer plus count signature.
- TextEditPaneSerialization calls the method four times with table/list payload pointers and byte counts.

Rejected alternatives:

- `void *` return: rejected as a decompiler artifact from the copy helper returning through `eax`. The method is a mutator and all known callers ignore the return value.
- `Encoder::meth_0x4a5480`, `sub_4A5480`, or `Encoder_WriteBytes` in final source: rejected as raw/generated labels. They should remain only as search/evidence aliases.
- `BinaryCodec::WriteBytes`: rejected because the body mutates an `Encoder` object and routes through [UID:00004F].
- `TextEditPane::WriteBytes`: rejected because TextEditPane constructs and consumes a stack `Encoder` but does not own the implementation state.
- `PacketBufferWriteBytes`: rejected because packet/network buffer helpers are the separate packet helper family around `0x00575380`; no packet sender or socket path calls this method.

Parameter type direction:

- `unsigned int byteCount` is the recommended mid-2000s source-facing spelling for this report because the argument represents a byte span length and sibling B reports already use plain built-in integer types rather than modern fixed-width typedefs.
- If the accepted Encoder header standardizes `int byteCount` because the capacity comparison uses signed `jge`, adjust the signature and body consistently. The behavior does not change.
- If the accepted project style later chooses `size_t`, update all copy-helper signatures together. Do not leave this target alone with a one-off style.

### 2. Encoder fields and types

Best descriptive field directions for this method:

| Offset | Role | Recommended name direction | Evidence / status |
| --- | --- | --- | --- |
| `+0x04` | caller-owned output buffer pointer | `m_outputBuffer` or `m_buffer` | Confirmed by `Initialize`, writer stores/copies, and `Finalize`; descriptive name. |
| `+0x08` | output capacity / limit | `m_capacity` or `m_bufferCapacity` | Confirmed by every writer capacity check; descriptive name. |
| `+0x0c` | current write position / cursor | `m_writePos` or `m_cursor` | Confirmed by every writer cursor update and `Finalize`; descriptive name. |
| `+0x10` | scalar byte-order flag | `m_useBigEndian` | Not used by this method; confirmed by scalar siblings. |
| `+0x11` | valid/writable flag | `m_isWritable` or `m_isValid` | Confirmed by writer invalidation and `Finalize` reset; descriptive name. |

For this target's first draft, prefer `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable`. These are source-quality descriptive names, not proven original symbols.

Rejected alternatives:

- Treat `+0x11` as "buffer attached": rejected because `Finalize` restores it to `1` after clearing the buffer pointer/capacity/cursor.
- Treat the output buffer as Encoder-owned: rejected because the destructor does not free it and `Finalize` only detaches it.
- Treat `+0x10/+0x11` as one opaque flags word in source-facing prose: rejected because methods address the bytes independently. A low-level note may still say the constructor initializes the pair with word `0x0101`.

### 3. Copy-helper roles at `0x00516030` and `0x00516220`

Resolved helper direction:

| Address / raw name | Current docs | Direct byte evidence | Recommended source-facing role |
| --- | --- | --- | --- |
| `0x00516030` / `sub_516030` | [UID:0001BC] `GetMemoryMan` | `mov eax, dword ptr [0x69b4fc]; ret`, size `0x06`; `612` direct rel32 call refs in local PE scan. | `GetMemoryMan`, returns the process MemoryMan singleton. |
| `0x00516220` / `sub_516220` | [UID:0001BH] `MemmoveWrapper` | One basic block wrapper: pushes size/source/destination and calls `0x005c95b0`, then `ret 0x0c`; `604` direct rel32 call refs in local PE scan. | MemoryMan copy/move helper wrapping `memmove`; source-level form likely `GetMemoryMan()->MoveMemory(...)` or a nearby `MemmoveWrapper(...)` utility. |

Important source-shape inference:

- `WriteBytes` calls `GetMemoryMan`, moves the returned pointer into `ecx`, then calls `0x00516220`. The wrapper itself does not read `ecx`, which means the binary can be modeled either as a `MemoryMan` instance method that does not use `this` or as a helper called after a singleton touch/setup.
- For human C++, the most plausible mid-2000s source shape is a MemoryMan copy helper call, e.g. `GetMemoryMan()->MoveMemory(...)` / `GetMemoryMan()->CopyBytes(...)`. If the accepted MemoryMan helper docs retain `MemmoveWrapper` as a free helper, the implementation can use `GetMemoryMan(); MemmoveWrapper(...)` as the literal-safe variant, but that is less source-like.
- Do not model these helpers as packet-specific, TextEdit-specific, or Encoder-private. They are project-wide MemoryMan/copy utilities.

### 4. Exact behavior, range checks, and final-NUL reserve

Confirmed target behavior from local PE disassembly:

1. Save `esi`, copy `this` from `ecx` into `esi`.
2. If `byte ptr [esi+0x11] == 0`, return immediately without touching the buffer or cursor.
3. Read `m_writePos` from `[esi+0x0c]` into `ecx`.
4. Read `byteCount` from `[ebp+0x0c]` into `edi`.
5. Compute `required = m_writePos + byteCount + 1`.
6. Compare `m_capacity` at `[esi+0x08]` against `required` with signed `jge`.
7. If capacity is insufficient, set `byte ptr [esi+0x11] = 0` and return without copying partial data.
8. On success, compute destination `m_outputBuffer + m_writePos`.
9. Push `byteCount`, push source pointer, push destination, call `GetMemoryMan`, set `ecx` to the returned singleton, and call `MemmoveWrapper`.
10. Advance `m_writePos` by `byteCount`.
11. Return with `ret 8`.

The `+ 1` reserve is for [UID:00013K] `Encoder::Finalize`, which writes the trailing NUL at `m_outputBuffer[m_writePos]`. `WriteBytes` does not write that terminator itself.

Rejected behavior additions:

- Do not add a null-buffer guard. The binary does not test the output buffer or source pointer.
- Do not clamp `byteCount`.
- Do not allocate or grow the buffer.
- Do not write a final NUL in this method.
- Do not copy partially on overflow.
- Do not clear the valid flag after a successful copy.

### 5. Boundary, padding, and adjacent raw helper bodies

Target boundary facts:

- Exact target bytes: `0x004a5480-0x004a54c6`, size `0x46` / decimal `70` (Verified with `int_convert.py`).
- `0x004a5472-0x004a5480` is `0xcc` padding after the preceding raw string/helper island; local byte check over `0x004a5470-0x004a5480` shows `08 00` from a prior `ret 8`, then `cc` padding.
- `0x004a54c6-0x004a54d0` is ten `0xcc` bytes of padding after `WriteBytes`.
- No absolute VA dword hits, no RVA dword hits, and no direct `E9` jump refs to the target start were found in the local PE scan.

Adjacent raw helper body reanalysis:

- `0x004a54d0-0x004a558d`: source-shaped compressed/transformed byte writer candidate, outside this target. The direct bytes show it ends at `0x004a558a: ret 8`, whose operand bytes occupy `0x004a558b-0x004a558c`; padding begins at `0x004a558d`. Existing docs saying `0x004a54d0-0x004a558b` cut through that `ret 8` instruction and should be corrected.
- `0x004a558d-0x004a5590`: three `0xcc` padding bytes between the two raw helpers.
- `0x004a5590-0x004a55b6`: source-shaped cursor-advance/reserve helper candidate, outside this target and outside `Initialize`. Direct bytes show it ends at `0x004a55b3: ret 4`, whose operand bytes occupy `0x004a55b4-0x004a55b5`; padding begins at `0x004a55b6`.
- `0x004a55b6-0x004a55c0`: ten `0xcc` padding bytes before [UID:00013J] `EncoderInitialize`.

Best helper-name directions:

- `0x004a54d0-0x004a558d`: likely `Encoder::WriteCompressedBytes`, `Encoder::WriteCompressedBlock`, or `Encoder::WritePackedBytes`. Evidence: estimates compressed output bound with `(inputSize + 0x0c) * 0x0b / 10`, allocates a temporary buffer via `0x005c7790`, calls compression/transform helper `0x00414370`, writes a two-byte length prefix honoring byte-order flag `+0x10`, copies payload via `GetMemoryMan`/`MemmoveWrapper`, advances cursor, frees temp buffer via `0x005c7799`, and returns `ret 8`. Constants `0x0c` / decimal `12` and `0x0b` / decimal `11` were verified with `int_convert.py`.
- `0x004a5590-0x004a55b6`: likely `Encoder::SkipBytes`, `Encoder::ReserveBytes`, or `Encoder::AdvanceWritePosition`. Evidence: checks valid flag, computes `cursor + count`, requires one final-NUL reserve byte, clears valid on overflow, and otherwise advances cursor without writing.

Rejected alternatives:

- Merge `0x004a54d0` into `WriteBytes`: rejected by padding `0x004a54c6-0x004a54d0`, different behavior, compression/allocation/free calls, and distinct `ret 8`.
- Merge `0x004a5590` into `Initialize`: rejected by separate source-shaped body, `ret 4`, and padding `0x004a55b6-0x004a55c0`.
- Treat either raw helper as padding: rejected by direct instruction sequences.
- Treat these helper questions as blocking this target's C++: rejected because they are non-overlapping ranges and do not affect `WriteBytes` behavior.

### 6. Caller and reachability

Local PE direct rel32 scan found four direct calls to `0x004a5480`, all inside [UID:0001JN] `TextEditPaneSerialization`:

| Call site | Caller context | Meaning |
| --- | --- | --- |
| `0x0058e56e` | `TextEditPaneSerialization` | Writes the first raw payload from TextEditPane storage at `+0x134`. |
| `0x0058e5ba` | `TextEditPaneSerialization` | Writes the second table/list payload after a size prefix. |
| `0x0058e5e3` | `TextEditPaneSerialization` | Writes the third table/list payload after a size prefix. |
| `0x0058e612` | `TextEditPaneSerialization` | Writes the fourth table/list payload after a size prefix. |

TextEditPaneSerialization constructs a stack `Encoder`, initializes it over a `0x7ffe` / decimal `32766` writable window inside a `0x8000` / decimal `32768` stack buffer (Verified with `int_convert.py` using four-byte size for `0x8000`), writes the first raw payload, delimiter byte `0`, marker `0x6b6f6e67` (`"kong"` under the Encoder default big-endian scalar write), three length-prefixed secondary payloads, finalizes to a byte count, allocates an exact heap buffer, copies the encoded stack bytes, stores the output byte count, and destroys the stack Encoder.

Ownership impact:

- TextEditPaneSerialization proves this method is live/reachable and used by text-edit state serialization.
- It does not transfer implementation ownership to TextEditPane. The state, vtable, field layout, and method family remain `Encoder`.

### 7. Owner and emitter route

Accepted route:

- `CANONICAL_OWNER:00004F` [UID:00004F] `Encoder`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00004F`
- [UID:00004F] routes through [UID:0000J1] `Encoder`
- [UID:0000J1] emits to `auto-generated/NexusTK/util/Encoder.cpp`

Evidence:

- [UID:00004F] `Encoder` is `86/90`, owns the method family, records the shared cursor layout, and emits through [UID:0000J1].
- [UID:0000J1] `Encoder` is `86/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, and is listed as a by-file generated root.
- `auto-generated/-ag-memory-coverage.md` lists [UID:00013I] as emitted through [UID:00004F] to `auto-generated/NexusTK/util/Encoder.cpp`.
- `auto-generated/NexusTK/util/Encoder.cpp` contains the empty [UID:00013I] emitter marker.

Rejected routes:

- Direct [UID:0000J1] file owner: rejected because by-structure says the narrow semantic owner for a class method is the class, not the file root.
- Direct [UID:0000HQ] `BinaryCodec` owner: rejected because the exact body mutates only Encoder instance state. BinaryCodec remains the source-family coordinator.
- [UID:0000ON] TextEditPane owner: rejected because it is the caller/consumer.
- PacketBuffer/network owner: rejected because no packet/network caller evidence exists and packet byte writers live in a separate helper family.
- `CANONICAL_OWNER:NONE`: rejected because direct class ownership and generated route are already strong.

### 8. Current C++ gate and score rationale

Current target state:

- Target score: `84/90`, average `87.0`.
- Parent class [UID:00004F]: `86/90`.
- Source root [UID:0000J1]: `86/88`.
- Route: nonblank `EMITTER_UIDS:00004F`, surfacing to `auto-generated/NexusTK/util/Encoder.cpp`.
- Generated output: empty marker only; `Coded` remains `no`.

Recommendation:

- Replace obsolete below-95 no-code text. `95+` remains a rare final-audit score, not a prerequisite for initial final-output C++ when the active gate is satisfied.
- Raise completion to `88` after implementation because the target will contain current source-quality signature, fields, helper roles, exact byte/padding evidence, corrected adjacent helper endpoints, gate analysis, first-draft C++, and updated change history.
- Keep confidence at `90` because the behavior and route are very strong, but current-session IDA MCP is unavailable and exact original member/helper names remain inferred/descriptive.
- First-draft C++ is safe for this exact method because the target is complete, source-authored, non-overlapping, routed to a valid emitter, and has no unresolved behavior blocker.

No unresolved issue blocks this target's first-draft C++. Remaining uncertainties are broader Encoder-class final-audit issues: exact original field names, exact original helper method name for `0x00516220`, exact header split, and future child pages for adjacent raw helpers.

## Evidence Standards Used

Evidence checked:

- Target page [UID:00013I] `by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md`.
- Support docs: [UID:00004F] `Encoder`, [UID:0000J1] `Encoder`, [UID:0000HQ] `BinaryCodec`, [UID:00013D] `EncoderCore`, [UID:00013F] `EncoderWriteByte`, [UID:00013J] `EncoderInitialize`, [UID:00013K] `EncoderFinalize`, [UID:0001TS] `BinaryCodecCursorLayout`, [UID:0001JN] `TextEditPaneSerialization`, [UID:0000UM] `EncodeTextEditState`, [UID:0001BC] `GetMemoryMan`, [UID:0001BH] `MemmoveWrapper`, [UID:0001X1] `BinaryCodecVtables`, [UID:0003IA] `EncoderVtableData`, [UID:0000L7] `MemoryMan`.
- Prior B reports as leads, revalidated against current evidence: B001 `00013I-EncoderWriteBytes-source-quality.md`, B004 `00013J-EncoderInitialize-source-quality.md`, and executed B002 `00013D-encoder-core-index-source-quality.md`.
- Generated route reports: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, and `auto-generated/NexusTK/util/Encoder.cpp`.
- Manual coverage row in `by-memory/-coverage-report.md`.
- Direct local PE byte/disassembly checks using `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Direct local PE rel32 call scans for `0x004a5480`, `0x00516030`, `0x00516220`, adjacent raw helper starts, `Initialize`, and `Finalize`.
- `int_convert.py` for `0x46`, `0x0c`, `0x0b`, `0x7ffe`, `0x8000`, `0x10`, `0x11`, `0x04`, `0x08`, and `0x0c`.
- IDA MCP availability check, which failed.

Why the evidence is strong enough:

- The target is a small exact method with a stable function body, two helper calls, four direct caller sites, and no overlapping source behavior.
- Field offsets and target behavior are corroborated by sibling Encoder writer/finalize/initialize docs and the shared cursor-layout doc.
- Owner/emitter route is already valid in generated reports and generated source markers.
- Direct local PE disassembly resolved a stale support-doc boundary issue without requiring IDA mutation.

What prevents higher confidence:

- No current-session live IDA MCP response.
- No original debug/source metadata proves exact member/helper spellings.
- Adjacent raw helper bodies still need exact child pages before the full Encoder class can be final-audit complete.

## Local PE / IDA Facts

IDA MCP:

- `tools/list` request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.

Local PE:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x400000`
- Sections: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`
- Target bytes `0x004a5480-0x004a54c6`:

```text
55 8b ec 56 8b f1 80 7e 11 00 74 35 8b 4e 0c 57
8b 7d 0c 8d 47 01 03 c1 39 46 08 7d 0a 5f c6 46
11 00 5e 5d c2 08 00 8b 46 04 57 ff 75 08 03 c1
50 e8 7a 0b 07 00 8b c8 e8 63 0d 07 00 01 7e 0c
5f 5e 5d c2 08 00
```

Target disassembly:

```asm
004a5480: push    ebp
004a5481: mov     ebp, esp
004a5483: push    esi
004a5484: mov     esi, ecx
004a5486: cmp     byte ptr [esi + 0x11], 0
004a548a: je      0x4a54c1
004a548c: mov     ecx, dword ptr [esi + 0xc]
004a548f: push    edi
004a5490: mov     edi, dword ptr [ebp + 0xc]
004a5493: lea     eax, [edi + 1]
004a5496: add     eax, ecx
004a5498: cmp     dword ptr [esi + 8], eax
004a549b: jge     0x4a54a7
004a549d: pop     edi
004a549e: mov     byte ptr [esi + 0x11], 0
004a54a2: pop     esi
004a54a3: pop     ebp
004a54a4: ret     8
004a54a7: mov     eax, dword ptr [esi + 4]
004a54aa: push    edi
004a54ab: push    dword ptr [ebp + 8]
004a54ae: add     eax, ecx
004a54b0: push    eax
004a54b1: call    0x516030
004a54b6: mov     ecx, eax
004a54b8: call    0x516220
004a54bd: add     dword ptr [esi + 0xc], edi
004a54c0: pop     edi
004a54c1: pop     esi
004a54c2: pop     ebp
004a54c3: ret     8
```

Direct rel32 call scan:

| Target | Count | Call sites / notes |
| --- | ---: | --- |
| `0x004a5480` | 4 | `0x0058e56e`, `0x0058e5ba`, `0x0058e5e3`, `0x0058e612` |
| `0x00516030` | 612 | Broad project-wide MemoryMan accessor/copy-allocation fanout |
| `0x00516220` | 604 | Broad project-wide memmove/copy helper fanout |
| `0x004a54d0` | 0 | No direct rel32 caller found in local scan |
| `0x004a5590` | 0 | No direct rel32 caller found in local scan |
| `0x004a55c0` | 1 | `0x0058e54b` TextEditPaneSerialization `Initialize` call |
| `0x004a55e0` | 1 | `0x0058e624` TextEditPaneSerialization `Finalize` call |

Pointer/reference scan for `0x004a5480`:

- VA dword hits: `0`
- RVA dword hits: `0`
- Meaning: the observed route is direct-call reachability from TextEditPaneSerialization, not vtable/data-table reachability for this non-virtual method.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a5480-0x004a54c6` | `00013I` / target | `Encoder::WriteBytes(const void *data, unsigned int byteCount)` | `TRUE` | `00004F` | recommend `88/90` | exact source-bearing child, C++ ready |
| `0x004a54c6-0x004a54d0` | no page | padding | `FALSE` | n/a | n/a | ten `0xcc` bytes after target |
| `0x004a54d0-0x004a558d` | no exact child yet | likely compressed/packed byte writer | likely `TRUE`, unresolved | likely `00004F` | n/a | outside target; future child research |
| `0x004a558d-0x004a5590` | no page | padding | `FALSE` | n/a | n/a | three `0xcc` bytes |
| `0x004a5590-0x004a55b6` | no exact child yet | likely skip/reserve/advance helper | likely `TRUE`, unresolved | likely `00004F` | n/a | outside target; future child research |
| `0x004a55b6-0x004a55c0` | no page | padding | `FALSE` | n/a | n/a | ten `0xcc` bytes before Initialize |
| `0x004a55c0-0x004a55de` | `00013J` | `Encoder::Initialize` | `TRUE` | `00004F` | `84/90`, B004 recommends `88/92` | next exact source-bearing child |

## Ranked Ownership Analysis

### 1. [UID:00004F] Encoder

- Evidence for: exact method mutates Encoder cursor fields, belongs to the documented Encoder writer family, uses shared `BinaryCodecCursorLayout` in Encoder output direction, has class/file route above gate, and is already emitted through [UID:00004F].
- Evidence against: exact original member names and MemoryMan copy-helper source spelling are not proven by source/debug metadata.
- Decision: accepted direct owner and emitter route. No owner/emitter metadata change.

### 2. [UID:0000J1] Encoder source file

- Evidence for: valid `NexusTK/util/` file root, [UID:00004F] emits through it, and generated output path exists.
- Evidence against: direct semantic owner for a class method is the class, not the file.
- Decision: accepted concrete generated source root through the class route, not direct `CANONICAL_OWNER`.

### 3. [UID:0000HQ] BinaryCodec coordinator

- Evidence for: shared cursor layout and paired Encoder/Decoder source family.
- Evidence against: this exact method is Encoder-only behavior and mutates only Encoder fields.
- Decision: rejected as direct owner; retain as coordinator/source-family context.

### 4. TextEditPane / TextEditPaneSerialization

- Evidence for: all four direct call sites are in TextEditPaneSerialization.
- Evidence against: consumer xrefs are not ownership; the caller constructs and uses a stack Encoder object.
- Decision: rejected as owner; retain as reachability, argument, and serialization-use evidence.

### 5. Packet/network owners

- Evidence for: generic "encoder" naming can suggest serialization in isolation.
- Evidence against: no packet sender, socket, or packet-buffer path calls this method, and packet helper families are separately documented.
- Decision: rejected.

## Negative Evidence Summary

- No evidence supports leaving final C++ blank solely because of the obsolete `95/95` threshold.
- No evidence supports changing owner/emitter away from [UID:00004F].
- No evidence supports merging adjacent raw helpers into this target.
- No evidence supports TextEditPane, BinaryCodec, PacketBuffer, Socket, DATFile, or MemoryMan as the direct owner.
- No VA/RVA dword references to the target start were found; no vtable/data route is required for this non-virtual method.
- No source/debug evidence proves exact original member names or MemoryMan copy-helper method names, so scores should remain below `95+`.

## First-Draft C++ Recommendation

Preferred source-shaped draft for the formal `RECONSTRUCTION_CPP CODE` block:

```cpp
void Encoder::WriteBytes(const void *data, unsigned int byteCount)
{
    if (!m_isWritable)
        return;

    unsigned int writePos = m_writePos;
    unsigned int required = writePos + byteCount + 1;
    if (static_cast<int>(m_capacity) < static_cast<int>(required)) {
        m_isWritable = false;
        return;
    }

    GetMemoryMan()->MoveMemory(m_outputBuffer + writePos, data, byteCount);
    m_writePos = writePos + byteCount;
}
```

Implementation notes:

- `m_outputBuffer`, `m_capacity`, `m_writePos`, and `m_isWritable` are descriptive field names. If the accepted Encoder header uses `m_buffer`, `m_cursor`, or `m_isValid`, adjust consistently in this target and sibling Encoder methods.
- `GetMemoryMan()->MoveMemory(...)` is the source-quality direction for the `0x00516030` plus `0x00516220` call pair. If the accepted MemoryMan helper API remains a free wrapper, use the literal-safe fallback:

```cpp
GetMemoryMan();
MemmoveWrapper(m_outputBuffer + writePos, data, byteCount);
```

- If the accepted Encoder header uses signed `int` fields/counts, simplify the `static_cast<int>` comparison to the natural signed comparison. If it uses unsigned fields, keep the casts to preserve the recorded signed `jge` capacity test.
- Do not include `0x004a54d0` compressed-write behavior or `0x004a5590` skip/reserve behavior inside this target's C++ block.
- Do not add markdown fences inside the managed reconstruction block during implementation.

## Recommended Exact Target Doc Changes

For `source-3/project-documentation/by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md` after supervisor implementation callback:

1. Update metadata:

```text
COMPLETION:84 -> 88
CONFIDENCE:90 unchanged
CANONICAL_OWNER:00004F unchanged
RECONSTRUCTABLE:TRUE unchanged
EMITTER_UIDS:00004F unchanged
EMITTER_POSITION_OPTIONAL unchanged blank
```

2. Replace the stale status bullet:

```text
- Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold.
```

with:

```text
- First-draft C++ is ready under the active combined-score/emitter gate: `RECONSTRUCTABLE:TRUE`, confirmed `EMITTER_UIDS:00004F` that surface through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md), and recommended `88/90` gives `(88 + 90) / 2 = 89`. The old `95/95` no-code wording was previous policy and no longer blocks this exact method.
```

3. Add source-facing signature:

```cpp
void Encoder::WriteBytes(const void *data, unsigned int byteCount)
```

4. Expand behavior/source-shape notes to include:

- valid/writable byte `+0x11` gates the method;
- capacity `+0x08` is compared against cursor `+0x0c` plus `byteCount` plus one final-NUL reserve byte;
- capacity failure clears `+0x11` and copies no partial data;
- success copies from caller source to `m_outputBuffer + m_writePos` through `GetMemoryMan`/`MemmoveWrapper` helper roles;
- success advances cursor by `byteCount`;
- `WriteBytes` does not write the trailing NUL; [UID:00013K] `Finalize` owns that.

5. Replace raw/source-quality names in prose:

- `sub_4A5480` / `meth_0x4a5480` -> `Encoder::WriteBytes`
- `sub_516030` -> `GetMemoryMan`
- `sub_516220` -> `MemoryMan` copy/move helper / `MemmoveWrapper`
- raw field offsets -> descriptive field directions `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_isWritable`

6. Correct boundary evidence from:

```text
`0x004a54c6-0x004a54d0` is `0xcc` padding, followed by raw non-modeled helper bodies at `0x004a54d0-0x004a558b` and `0x004a5590-0x004a55b4`; those bodies are not part of `WriteBytes` or `Initialize`.
```

to:

```text
`0x004a54c6-0x004a54d0` is ten `0xcc` padding bytes, followed by raw non-modeled helper bodies at `0x004a54d0-0x004a558d` and `0x004a5590-0x004a55b6`; `0x004a558d-0x004a5590` and `0x004a55b6-0x004a55c0` are `0xcc` alignment spans. B014's 2026-06-19 local PE byte check confirms the first helper's `ret 8` consumes `0x004a558a-0x004a558c` and the second helper's `ret 4` consumes `0x004a55b3-0x004a55b5`, so those bodies are outside both `WriteBytes` and `Initialize`.
```

7. Add the first-draft C++ block above.

8. Add a `## Score And Gate Rationale` section:

```markdown
Completion is raised to `88` after this source-quality pass because the page now records active code-entry policy, exact source signature, field mapping, copy-helper roles, direct local PE byte/disassembly evidence, caller set, final-NUL reserve behavior, corrected neighboring raw-helper endpoints, and first-draft C++ for the exact method. Confidence remains `90` because behavior/range/route evidence is very strong, but exact original member names, exact MemoryMan copy-helper API spelling, and current-session live IDA MCP remain unresolved.
```

9. Add a `## Changes` entry:

```markdown
- 2026-06-19 B014 source-quality report:
  - Before: `84/90`, correct owner/emitter route, blank formal C++, stale no-code wording tied to an obsolete `95/95` threshold, and stale adjacent helper endpoints.
  - Recommended after implementation: `88/90`, unchanged owner/emitter route, corrected adjacent raw helper spans `0x004a54d0-0x004a558d` and `0x004a5590-0x004a55b6`, and first-draft `Encoder::WriteBytes(const void *data, unsigned int byteCount)` C++ under the active combined-score/emitter gate.
  - Evidence: B014's local PE check confirms exact `0x004a5480-0x004a54c6` body, size `0x46` / decimal `70` (Verified with `int_convert.py`), valid/capacity/cursor/buffer behavior, final-NUL reserve, `GetMemoryMan`/`MemmoveWrapper` call pair, four TextEditPaneSerialization call sites, no target VA/RVA dword hits, padding before/after, and corrected raw helper endpoints. IDA MCP was unavailable in this session, so confidence stays below final audit.
```

## Recommended Support Doc Changes

Apply these only if the supervisor accepts this report and sends an implementation callback.

1. `source-3/project-documentation/by-memory/0x004a4e70-0x004a5621.EncoderCore.md`

Replace:

```text
`0x004a54d0-0x004a558b` and `0x004a5590-0x004a55b4`: additional writer-family helper bodies documented outside `WriteBytes` and `Initialize`.
```

with:

```text
`0x004a54d0-0x004a558d` and `0x004a5590-0x004a55b6`: additional writer-family helper bodies documented outside `WriteBytes` and `Initialize`; B014's byte check confirms the first helper's `ret 8` consumes `0x004a558a-0x004a558c`, so padding begins at `0x004a558d`, and the second helper's `ret 4` consumes `0x004a55b3-0x004a55b5`, so padding begins at `0x004a55b6`.
```

2. `source-3/project-documentation/by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md`

If the B004 `00013J` report has not already been accepted/implemented, replace:

```text
- Boundary evidence: raw non-modeled helper body `0x004a5590-0x004a55b4` and `0x004a55b4-0x004a55c0` alignment precede this method; `0x004a55de-0x004a55e0` is two `0xcc` bytes before [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md).
```

with:

```text
- Boundary evidence: raw non-modeled cursor-advance/reserve helper body `0x004a5590-0x004a55b6` and `0x004a55b6-0x004a55c0` alignment precede this method; B014's byte check confirms the helper's `ret 4` consumes `0x004a55b3-0x004a55b5`, and `0x004a55de-0x004a55e0` is two `0xcc` bytes before [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md).
```

3. Optional consistency updates:

- `by-class/Encoder.md`: update the method inventory row to show `WriteBytes(const void *data, unsigned int byteCount)` and note that [UID:00013I] is first-draft C++ ready after B014's source-quality pass. No class metadata change is required.
- `by-file/Encoder.md`: optionally note that [UID:00013I] now carries first-draft C++ once implemented; no file score change is required.
- `by-type/by-struct/BinaryCodecCursorLayout.md`: no required metadata change. Existing field-role notes are already sufficient; optional cleanup can record `m_outputBuffer`/`m_capacity`/`m_writePos`/`m_isWritable` as current Encoder first-draft directions.
- [UID:0001BC] `GetMemoryMan` and [UID:0001BH] `MemmoveWrapper`: no required metadata change. If a broader MemoryMan implementation pass standardizes helper source spelling, reconcile this target's C++ call with that accepted API.

## Exact Implementation Checklist

When the supervisor sends an implementation callback, apply only accepted changes:

1. Edit `by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md`.
2. Set metadata `COMPLETION:88`, keep `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, blank `EMITTER_POSITION_OPTIONAL`.
3. Replace stale `95/95` C++ blocker wording with active combined-score/emitter gate analysis.
4. Add/expand source-shape, field, helper, behavior, caller, boundary, rejected-alternative, and score rationale sections at report-level detail.
5. Populate the formal C++ block with the accepted first-draft body, using either the source-shaped `GetMemoryMan()->MoveMemory(...)` call or the literal-safe `GetMemoryMan(); MemmoveWrapper(...)` variant if MemoryMan helper naming remains unaccepted.
6. Correct target boundary text to `0x004a54d0-0x004a558d` and `0x004a5590-0x004a55b6`.
7. Apply the accepted support-doc corrections to `EncoderCore` and, if not already done by B004, `EncoderInitialize`.
8. Do not edit `by-memory/-coverage-report.md`; keep the replacement row below for supervisor-owned application.
9. Run validators from `source-3/project-documentation` as listed below and report outputs.

## Validator Needs

No validator was run for this report-only pass because no target/support by-* docs were edited.

Recommended implementation validation from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00013I-EncoderWriteBytes-source-quality-removed.md](00013I-EncoderWriteBytes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor accepts only the target page update, run the first target-file validator plus autogen. If the support boundary corrections are accepted, run all listed file validators.

Expected results after implementation:

- Target metadata validates.
- `auto-generated/NexusTK/util/Encoder.cpp` changes from an empty [UID:00013I] marker to the emitted `Encoder::WriteBytes` method body.
- `auto-generated/-ag-memory-coverage.md` continues to route [UID:00013I] through [UID:00004F] to `auto-generated/NexusTK/util/Encoder.cpp`, with coded status changing after C++ population.
- Manual `by-memory/-coverage-report.md` still requires supervisor-owned replacement text below.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B014. Supervisor should replace the current [UID:00013I] row near the existing [UID:00013H] and [UID:00013J] rows with:

```markdown
    - [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md) 0x004a5480-0x004a54c6 | method | EncoderWriteBytes : reconstructable : 88% : strong : B014 source-quality review clears the active combined-score/emitter C++ gate for exact `Encoder::WriteBytes(const void *data, unsigned int byteCount)` through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md). Documented behavior: valid/writable flag `+0x11` gates writes, capacity `+0x08` must cover cursor `+0x0c` plus `byteCount` plus the final-NUL reserve used by [UID:00013K][EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md), overflow clears valid without partial copy, success copies from caller data to `m_outputBuffer + m_writePos` through the resolved `GetMemoryMan`/MemoryMan copy-helper call pair at `0x00516030`/`0x00516220` and advances cursor by `byteCount`, four TextEditPaneSerialization call sites at `0x0058e56e`, `0x0058e5ba`, `0x0058e5e3`, and `0x0058e612` prove reachability, no VA/RVA dword hits or non-caller owner route were found for the target start, `0x004a54c6-0x004a54d0` is padding, adjacent raw helpers remain outside this page with corrected spans `0x004a54d0-0x004a558d` likely compressed/packed bytes writer and `0x004a5590-0x004a55b6` likely skip/reserve helper, and first-draft C++ is recommended while exact member/helper spellings remain descriptive rather than symbol-proven.
```

No delete/insert of neighboring coverage rows is recommended for this target.

## IDA Rename / Type / Comment Recommendations

Do not apply IDA DB edits during the report-only pass. If an IDA source-quality callback is later approved, recommended names/types are:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x004a5480` | Rename `sub_4A5480` to `Encoder_WriteBytes`. Type as `void __thiscall Encoder_WriteBytes(Encoder *this, const void *data, unsigned int byteCount)` or signed-count variant if the class header standardizes signed fields. | High |
| `0x004a54d0` | If creating a function after separate child research, provisional name `Encoder_WriteCompressedBytes` / `Encoder_WritePackedBytes`; comment as outside [UID:00013I], exact range `0x004a54d0-0x004a558d`. | Medium-high role, name descriptive |
| `0x004a5590` | If creating a function after separate child research, provisional name `Encoder_SkipBytes` / `Encoder_ReserveBytes`; comment as outside [UID:00013J], exact range `0x004a5590-0x004a55b6`. | Medium-high role, name descriptive |
| `0x00516030` | Keep/rename as `GetMemoryMan`. Type as returning `MemoryMan *`. | High |
| `0x00516220` | Keep/rename as `MemoryMan_MoveMemory`, `MemoryMan_CopyBytes`, or `MemmoveWrapper` depending on accepted MemoryMan API. Type as copy/move wrapper taking destination, source, size. | High behavior, medium exact source name |
| `Encoder` field `+0x04` | `m_outputBuffer` / `m_buffer`; byte pointer. | High role |
| `Encoder` field `+0x08` | `m_capacity` / `m_bufferCapacity`; signed or unsigned integer capacity. | High role |
| `Encoder` field `+0x0c` | `m_writePos` / `m_cursor`; signed or unsigned integer cursor. | High role |
| `Encoder` field `+0x11` | `m_isWritable` / `m_isValid`; byte/bool. | High role |

Suggested function comment for `0x004a5480`:

```text
Encoder::WriteBytes appends byteCount bytes from caller data to the caller-owned output buffer when valid and when capacity leaves one byte for Finalize's trailing NUL. On overflow it clears the writable/valid flag and performs no partial copy. Direct callers are the TextEditPane serialization raw table writes.
```

## Follow-Up Actions

- Supervisor: review this report and, if accepted, send B014 an implementation callback with target/support doc edits and validator commands.
- Supervisor: apply or queue the manual `by-memory/-coverage-report.md` row replacement during supervisor-owned coverage maintenance.
- Future B-agent work: split/research exact child pages for `0x004a54d0-0x004a558d` and `0x004a5590-0x004a55b6`, plus earlier raw Encoder helper islands, before declaring the full Encoder class final-source complete.
- Future MemoryMan work: standardize whether `0x00516220` should be emitted as `GetMemoryMan()->MoveMemory(...)`, `MemoryMan::CopyBytes(...)`, `MemmoveWrapper(...)`, or direct `memmove(...)` in final C++.

## Confidence

- Recommendation confidence: high.
- Score confidence: `88/90` after implementation is defensible; keep below `95+`.
- Remaining uncertainty: exact original member names, exact original helper API name for the `GetMemoryMan`/copy-helper pair, exact original header split (`Encoder.h` versus shared `BinaryCodec.h`), and the adjacent raw helper pages.

## Validator Results

- Commands run: none for by-* docs; this was report-only.
- IDA MCP result: unavailable, `Unable to connect to the remote server`.
- Local validation performed: PE hash/section parse, target disassembly, adjacent raw-helper disassembly, rel32 call scans, VA/RVA dword scans, and `int_convert.py` conversions.
- Unresolved validator warnings/errors: none checked in this pass. Run the validator commands above after implementation.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/00013I-EncoderWriteBytes-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00013I-EncoderWriteBytes-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00013I"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013I-EncoderWriteBytes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/00013I-EncoderWriteBytes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
