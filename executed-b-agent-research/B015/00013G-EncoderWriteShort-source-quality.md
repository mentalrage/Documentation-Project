** TARGET-REPORT-UID:00013G **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013G EncoderWriteShort Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00013G] as an exact source-bearing `Encoder::WriteShort` method child owned by [UID:00004F] `Encoder`, routed through [UID:00004F] to [UID:0000J1] `NexusTK/util/Encoder.cpp`.
- Final disposition: no split or owner change is needed for the target range; replace the stale "below 95/95 no-code" rationale with the active combined-score/emitter gate and enter a first-draft method body during the supervisor implementation callback.
- Required action: update the target page metadata/body and C++ block, then validate the target and refresh autogen. Do not edit `by-memory/-coverage-report.md` directly; supervisor should apply the exact replacement row in this report.
- Confidence: high for target behavior, byte order, range/error behavior, owner/emitter route, and first-draft C++ readiness; medium-high for exact original member names because they remain descriptive rather than debug-symbol proven.

Recommended target metadata after implementation:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Before/after score: `84/90` -> recommended `88/90`. The completion increase is justified only after the stale gate text is removed, source shape/source-quality reasoning is added, and first-draft C++ is populated. Confidence should remain `90` rather than rising because current-session IDA MCP was unavailable.

## Supporting Research

## Target

- Target UID: `00013G`
- Target path: `source-3/project-documentation/by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00013G-EncoderWriteShort-source-quality.md`
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`.
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists [UID:00013G] as `emits`, owner `00004F`, emitter `00004F`, generated path `auto-generated/NexusTK/util/Encoder.cpp`.
- Current generated output state: `auto-generated/NexusTK/util/Encoder.cpp` contains an empty emitter marker for [UID:00013G], proving the route surfaces to a valid by-file root but no C++ has been entered yet.

## Executive Recommendation

The target already has the correct direct semantic owner and output route. [UID:00004F] `Encoder` is currently `86/90`, [UID:0000J1] `Encoder` is `86/88`, and [UID:0000J1] has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, so the emitter chain surfaces to `auto-generated/NexusTK/util/Encoder.cpp` without a dead end.

The stale blocker is the target's statement that final C++ is blank because the page is below a `95/95` threshold. Under the active rule in `by-structure.md` and `by-memory/-guidance.md`, the code-entry gate is:

```text
RECONSTRUCTABLE:TRUE
confirmed nonblank EMITTER_UIDS with a valid generated source route
(COMPLETION + CONFIDENCE) / 2 > 85
```

The current target average is `(84 + 90) / 2 = 87`, and the route is valid. The page is therefore numerically eligible already. After documenting this source-quality pass and inserting first-draft C++, `88/90` is a better score than `84/90`. No split, merge, rename, owner change, or emitter change is recommended.

## Supervisor Active Recheck

- Current user assignment explicitly requested a B-agent report first for [UID:00013G] `EncoderWriteShort`.
- I did not edit the target, support by-* docs, generated reports, or `by-memory/-coverage-report.md`.
- I preserved existing reports in `Agent-B015/research`; the new file path did not already exist.
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp` and `http://127.0.0.1:13337/config.html`; both connection attempts failed, and `Test-NetConnection 127.0.0.1 -Port 13337` reported `TcpTestSucceeded: False`. Current-session live IDA evidence is therefore unavailable.
- The report relies on current project docs that already record live IDA MCP checks, plus generated autogen route state. Generated Wave/simroot-style C++ was treated only as a lead/output-state check, not as authority.

## Inference Research Guidance Check

`by-structure.md` and `by-memory/-guidance.md` require source-quality investigation even after an item reaches the 85-level routing threshold. They also separate semantic ownership (`CANONICAL_OWNER`) from output routing (`EMITTER_UIDS`) and allow C++ entry below final-audit `95+` scores when the active combined-score/emitter gate is satisfied.

`inference_research.md` warns against treating consumer xrefs as ownership proof by themselves. Here the owner recommendation does not rely on the TextEditPane consumer alone. The direct owner is supported by the Encoder vtable/class docs, shared cursor layout, exact method family, and source-root route. TextEditPane remains caller evidence only.

Existing target assumptions revalidated:

- Validated: exact method range `0x004a4f00-0x004a4f59`.
- Validated: direct owner [UID:00004F] `Encoder`.
- Validated: concrete file root [UID:0000J1] `Encoder.cpp`.
- Validated: `+0x10` byte-order flag is nonzero for high-byte-first scalar writes.
- Validated: `+0x11` valid/writable byte gates writes and is cleared on overflow.
- Corrected recommendation: final C++ should no longer be blocked by stale `95/95` wording.

## Heuristic / Inference Reanalysis And Validation

### 1. Write-short source shape

Best source-facing shape:

```cpp
void Encoder::WriteShort(unsigned short value);
```

Evidence checked:

- Target page records IDA `lookup_funcs` start `0x004a4f00`, size `0x59`, end-exclusive `0x004a4f59`.
- [UID:00013D] `EncoderCore` lists this as the exact `Encoder::WriteShort` child and records it as a source-bearing method, not an aggregate.
- [UID:00004F] `Encoder` lists it in the confirmed methods table.
- [UID:0000J1] `Encoder` lists it in the proposed file contents for `NexusTK/util/Encoder.cpp`.
- [UID:0000UM] and [UID:0001JN] record the only confirmed behavioral caller set as TextEditPane serialization.

Rejected alternatives:

- `BinaryCodec::WriteShort`: rejected because the method mutates an `Encoder` instance and [UID:00004F] is the narrow direct owner.
- Free helper `WriteShort`: rejected because vtable/class/method-family docs place the function in the `Encoder` object layout.
- Packet/network `WriteShort`: rejected because current caller evidence is a TextEditPane serializer, not `PacketBuffer` or socket code.
- `std::uint16_t` as required final spelling: acceptable semantically, but less conservative for a late-1990s/mid-2000s Visual C++ codebase than `unsigned short`.

Final direction: use `void Encoder::WriteShort(unsigned short value)` in the first draft. Mark the name as descriptive/recovered, not debug-symbol proven.

### 2. Byte order

Best inference:

- `this + 0x10` is the byte-order flag.
- Nonzero writes the high byte first, then the low byte.
- Zero writes the `unsigned short` directly into the buffer, matching native little-endian x86 storage.

Evidence checked:

- Target page records the big-endian path as `value >> 8` at current byte, then low byte at the next cursor.
- Target page records the zero-byte-order path as a direct 16-bit store and cursor advance by two.
- [UID:0001TS] `BinaryCodecCursorLayout` records nonzero `+0x10` as big-endian for both Encoder and Decoder scalar operations.
- [UID:00013H] `EncoderWriteInt` records the same branch pattern for four-byte values.
- [UID:0000UM]/[UID:0001JN] record `EncoderWriteInt(0x6b6f6e67)` as emitting `"kong"` under the constructor-default nonzero byte order, supporting high-byte-first semantics.

Rejected alternatives:

- Nonzero means little-endian: rejected by the high-byte-first branch and the `"kong"` caller interpretation.
- Use byte-by-byte writes in both branches: rejected for binary/source-shape fidelity because the zero-byte-order branch is a native 16-bit store in the recorded IDA evidence.

### 3. Buffer, position, capacity, and flag fields

Best descriptive field directions for target C++:

| Offset | Role | Recommended C++ name direction | Status |
| --- | --- | --- | --- |
| `+0x04` | caller-owned output buffer pointer | `m_outputBuffer` or `m_buffer` | confirmed role, descriptive name |
| `+0x08` | writable capacity / limit | `m_capacity` | confirmed role, descriptive name |
| `+0x0c` | current write cursor | `m_writePos` | confirmed role, descriptive name |
| `+0x10` | byte-order flag | `m_useBigEndian` | confirmed semantics, descriptive name |
| `+0x11` | valid/writable flag | `m_isWritable` or `m_isValid` | confirmed semantics, descriptive name |

For this target's first draft, prefer `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`. These names are readable and match the write-only Encoder role; the page should state they are source-facing descriptive names, not recovered original symbols.

Rejected alternatives:

- Treat `+0x10/+0x11` as one opaque flags word in method source: rejected for this method because the body reads/writes the two bytes independently.
- Name `+0x11` `m_hasBuffer`: rejected because `Finalize` restores it to `1` after clearing the buffer.
- Treat the buffer as owned/freed by Encoder: rejected because destructor does not free it and `Finalize` only detaches.

### 4. Range and error behavior

Confirmed target range behavior:

- If `m_isWritable` / `+0x11` is zero, return immediately without touching buffer, cursor, capacity, or flags.
- Read cursor from `+0x0c`.
- Require `capacity >= cursor + 3`, not merely `cursor + 2`, so the two payload bytes still leave room for the final NUL written by [UID:00013K] `EncoderFinalize`.
- On insufficient capacity, clear `+0x11` and return without partial writes.
- On success, write exactly two bytes and advance cursor by two.
- No callees are recorded for this method.

Edge behavior to preserve in C++:

- Use unsigned arithmetic for `m_writePos + 3` to match 32-bit cursor/capacity fields.
- Do not throw, allocate, resize, or clamp.
- Do not write the final NUL here; `Finalize` owns that.
- Do not clear `m_isWritable` on null buffer unless the capacity check fails; the binary does not separately validate the buffer pointer.

### 5. Owner and emitter route

Best route:

- `CANONICAL_OWNER:00004F` [UID:00004F] `Encoder`
- `EMITTER_UIDS:00004F`
- [UID:00004F] emits to [UID:0000J1] `Encoder`
- [UID:0000J1] emits to `auto-generated/NexusTK/util/Encoder.cpp`

Evidence checked:

- [UID:00004F] current score `86/90`, owner [UID:0000J1], emitter [UID:0000J1].
- [UID:0000J1] current score `86/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
- `auto-generated/-ag-class-coverage.md` lists [UID:00004F] as emitting to `auto-generated/NexusTK/util/Encoder.cpp`.
- `auto-generated/-ag-file-coverage.md` lists [UID:0000J1] as a by-file generated root.
- `auto-generated/NexusTK/util/Encoder.cpp` already contains [UID:00013G]'s empty emitter marker.

Rejected routes:

- Direct owner [UID:0000J1]: rejected because [UID:00004F] is the narrower semantic owner.
- Direct owner [UID:0000HQ] `BinaryCodec`: rejected because this exact method mutates only Encoder state; BinaryCodec is the family coordinator.
- TextEditPane: rejected because it is the consumer, not the implementation owner.
- `CANONICAL_OWNER:NONE`: rejected because the class/file route is already supported above the gate.

### 6. Compiler-generated/raw names

Current source-quality state:

- Old IDA/docs may refer to `sub_4A4F00`; that is only the raw compiler/generated name.
- Current source-facing documentation should use `Encoder::WriteShort`.
- [UID:0001TS] records prior IDA naming work for modeled Encoder methods including `Encoder_WriteShort`. That name is useful as an IDA/database label but should not be the final C++ spelling.
- The adjacent raw helper at `0x004a4f60-0x004a4fe3` is likely `WriteTriByte` / `Write24`, but it is not part of [UID:00013G]. It should remain a boundary note and future child-page target, not a reason to block `WriteShort`.

Rejected alternatives:

- Keep `sub_4A4F00` in source-facing C++: rejected.
- Fold `0x004a4f60` into this page: rejected by the target end `0x004a4f59`, padding `0x004a4f59-0x004a4f5f`, and separate helper body.

### 7. Open questions and impact

Resolved in this pass:

- Active code-entry gate: resolved; stale `95/95` no-code rationale should be removed.
- Target owner/emitter route: resolved; keep [UID:00004F].
- Byte order: resolved; nonzero means high-byte-first.
- Range/error behavior: resolved enough for first-draft source.
- First-draft C++ readiness: resolved; populate the method block during implementation.

Remaining but non-blocking for this target:

- Exact original member names are not proven by debug/source metadata. Use descriptive names and keep confidence below final audit.
- Exact original header split between `Encoder.h` and a shared `BinaryCodec.h` remains open at the family level. It does not block this method's `Encoder.cpp` body.
- Adjacent raw helper `0x004a4f60-0x004a4fe3` still needs an exact child research pass. It does not overlap this range.
- Current-session IDA MCP was unavailable, so no new live disassembly was captured on 2026-06-19. Existing recorded IDA evidence is strong enough for the recommendation, but do not raise confidence above `90`.

## Evidence Standards Used

Evidence checked:

- Target doc [UID:00013G].
- Parent/support docs [UID:00004F], [UID:0000J1], [UID:0000HQ], [UID:00013D], [UID:00013F], [UID:00013H], [UID:00013I], [UID:00013J], [UID:00013K], [UID:0001TS], [UID:0001X1], [UID:0003IA], [UID:0000UM], and [UID:0001JN].
- Generated route reports `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, and generated file `auto-generated/NexusTK/util/Encoder.cpp`.
- Manual coverage row in `by-memory/-coverage-report.md`.
- Executed B002 report `Agent-B002/research/executed/00013D-encoder-core-index-source-quality.md`, rechecked against current docs rather than copied forward.
- `by-structure.md`, `by-memory/-guidance.md`, and `inference_research.md`.
- IDA MCP availability checks on `127.0.0.1:13337` failed this session; no current live IDA query was available.

Why evidence is strong enough:

- Multiple current by-* docs record the same IDA-backed boundaries, field offsets, caller set, and sibling writer semantics.
- The target is a small no-callee method with one branch on a documented flag and a simple capacity failure path.
- The owner/emitter chain is already generated and visible in autogen output.

What prevents stronger confidence:

- No current-session IDA MCP dump.
- No original debug/source metadata for exact member names.
- Sibling raw helper islands in the broader Encoder cluster still need separate pages.

## IDA MCP Facts From Current Docs

Function/range facts:

- `lookup_funcs` maps `0x004a4f00` to `sub_4A4F00`, size `0x59`; end-exclusive range is `0x004a4f00-0x004a4f59`.
- `0x004a4f59` is not a function.
- The next modeled writer helper is [UID:00013H] `EncoderWriteInt` at `0x004a4ff0-0x004a506b`.
- `callees 0x004a4f00` is empty.

Data/table/padding facts:

- `+0x04` is the buffer pointer.
- `+0x08` is capacity.
- `+0x0c` is cursor/write position.
- `+0x10` is byte-order flag.
- `+0x11` is valid/writable flag.
- `0x004a4f59-0x004a4f5f` is `0xcc` alignment after the function.
- Raw helper-shaped body `0x004a4f60-0x004a4fe3` is separate from this page and likely writes a 24-bit scalar.
- `0x004a4fe3-0x004a4fef` is `0xcc` alignment before [UID:00013H].

Xref facts:

- `callers 0x004a4f00` and `xrefs_to 0x004a4f00` report three call sites in `sub_58E490`: `0x0058e59a`, `0x0058e5c9`, and `0x0058e5f8`.
- [UID:0000UM]/[UID:0001JN] classify `sub_58E490` as TextEditPane serialization, not Encoder ownership.

Negative IDA facts:

- No callees for [UID:00013G].
- No packet/socket sender caller is documented for this method.
- No evidence that the adjacent raw 24-bit helper belongs inside this range.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a4f00-0x004a4f59` | `00013G` / target | `Encoder::WriteShort(unsigned short)` | `TRUE` | `00004F` | recommend `88/90` | exact source-bearing child; C++ ready |
| `0x004a4ec0-0x004a4ef1` | `00013F` | `Encoder::WriteByte` | `TRUE` | `00004F` | `84/90` | sibling one-byte writer |
| `0x004a4f60-0x004a4fe3` | no exact page yet | likely `Encoder::WriteTriByte` / `Write24` | likely `TRUE`, unconfirmed page | likely `00004F` | n/a | adjacent raw helper, outside target |
| `0x004a4ff0-0x004a506b` | `00013H` | `Encoder::WriteInt` | `TRUE` | `00004F` | `84/90` | sibling four-byte writer |
| `0x004a4e70-0x004a5621` | `00013D` | Encoder exact-child index | `FALSE` | `00004F` | `86/90` | non-emitting parent/index |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0058e59a` | call to `0x004a4f00` inside `sub_58E490` | writes second-table byte count, derived from `this+0x138` count * 16 |
| `0x0058e5c9` | call to `0x004a4f00` inside `sub_58E490` | writes third-table byte count, derived from `this+0x13c` count * 16 |
| `0x0058e5f8` | call to `0x004a4f00` inside `sub_58E490` | writes fourth-table byte count, derived from `this+0x140` count * 4 |
| `0x004a4f00` | no callees | method is self-contained |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00013G] records exact body, fields, byte order, no-callee status, caller sites, and boundary evidence.
- [UID:00004F] records the Encoder class state layout and confirmed method list.
- [UID:0000J1] records the concrete `Encoder.cpp` source root and child inventory.
- [UID:0000HQ] records BinaryCodec as a coordinator, not the direct owner.
- [UID:0001TS] records shared cursor layout and field offsets.
- [UID:0000UM]/[UID:0001JN] records the TextEditPane serialization caller and why it is only a consumer.
- [UID:00013D] records the aggregate/index disposition and adjacent raw-helper backlog.

Existing docs that are stale, incomplete, or contradicted:

- [UID:00013G] still says final C++ is blank because the page is below the `95/95` reconstruction-code threshold. This is stale under the active `(COMPLETION + CONFIDENCE) / 2 > 85` gate.
- [UID:00013G] status still mentions the parent class as `82/86`; [UID:00004F] is now `86/90`.
- [UID:00013G] lacks a first-draft C++ section even though the route surfaces and the method is small enough to model safely.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:00013G] as emitting through [UID:00004F] to `auto-generated/NexusTK/util/Encoder.cpp`.
- `auto-generated/NexusTK/util/Encoder.cpp` currently contains only an empty emitter marker for [UID:00013G].
- `by-memory/-coverage-report.md` row is mostly correct but should be replaced to reflect `88%`, active C++ readiness, and stale-gate correction.

## Ranked Ownership Analysis

### 1. [UID:00004F] Encoder

Evidence for:

- Target mutates Encoder object fields and uses the Encoder cursor layout.
- Encoder class doc lists `WriteShort` as a confirmed method.
- Encoder file doc owns the concrete `Encoder.cpp` source root.
- The exact method page already uses [UID:00004F] as owner and emitter, and autogen proves the route surfaces.

Evidence against:

- Exact original member names are descriptive, not proven.

Decision: accepted. Keep owner/emitter route unchanged.

### 2. [UID:0000HQ] BinaryCodec

Evidence for:

- Encoder and Decoder share cursor layout and vtable family context.
- BinaryCodec is the broader utility coordinator.

Evidence against:

- This method is not shared; it mutates an Encoder instance only.
- Direct assignment to BinaryCodec would bypass the narrower class owner.

Decision: rejected as direct owner/emitter; keep as context.

### 3. TextEditPane / [UID:0000ON]

Evidence for:

- The only recorded behavioral caller is TextEditPane serialization.

Evidence against:

- Consumer xrefs do not prove implementation ownership.
- TextEditPane constructs and uses a stack Encoder; it does not own the Encoder class, vtable, or writer method family.

Decision: rejected as owner; keep as caller evidence.

### 4. Packet/network helper ownership

Evidence for:

- Generic `WriteShort` naming can resemble packet helper code.

Evidence against:

- No packet sender/socket/network caller is documented for this method.
- Separate packet-buffer write helpers exist elsewhere and should not be conflated with this caller-buffer Encoder utility.

Decision: rejected.

## Negative Evidence Summary

- No current evidence supports moving [UID:00013G] to `BinaryCodec`, `TextEditPane`, `PacketBuffer`, `Socket`, or `NONE`.
- No current evidence supports merging the raw `0x004a4f60` helper into this target.
- No current evidence proves exact historical member names, so final wording should keep names descriptive.
- No current-session IDA MCP was available; do not raise confidence above `90`.

## First-Draft C++ Recommendation

Populate [UID:00013G]'s formal `RECONSTRUCTION_CPP CODE` block during implementation. This is not merely a body-only review artifact; the target satisfies the active code-entry gate and has a valid emitter route.

Recommended code:

```cpp
void Encoder::WriteShort(unsigned short value)
{
    if (!m_isWritable) {
        return;
    }

    const unsigned int writePos = m_writePos;
    if (m_capacity < writePos + 3) {
        m_isWritable = false;
        return;
    }

    unsigned char* const writePtr = m_outputBuffer + writePos;
    if (m_useBigEndian) {
        writePtr[0] = static_cast<unsigned char>(value >> 8);
        ++m_writePos;
        m_outputBuffer[m_writePos] = static_cast<unsigned char>(value);
        ++m_writePos;
        return;
    }

    *reinterpret_cast<unsigned short*>(writePtr) = value;
    m_writePos = writePos + 2;
}
```

Why this draft is source-ready:

- Uses late-1990s/mid-2000s-friendly primitive spellings (`unsigned short`, `unsigned int`, `unsigned char`) instead of requiring C++11 fixed-width typedefs.
- Preserves the valid-flag early return and overflow invalidation behavior.
- Preserves the `cursor + 3` capacity rule and final-NUL reserve.
- Preserves high-byte-first writes when `m_useBigEndian` is nonzero.
- Preserves the native 16-bit store in the zero-byte-order branch.
- Does not include adjacent helper code or caller serialization behavior outside `0x004a4f00-0x004a4f59`.

Implementation caveat:

- The code assumes the class-level field names `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`. If the supervisor prefers the existing class page's alternate names (`m_buffer`, `m_bufferCapacity`, `m_cursor`, `m_isValid`), adjust the names consistently in this method and note that the semantic field mapping is unchanged.

## Recommended Exact Doc Changes

Apply these changes to `source-3/project-documentation/by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md` during the implementation callback.

1. Metadata:

```text
COMPLETION:84 -> 88
CONFIDENCE:90 -> 90
CANONICAL_OWNER:00004F unchanged
RECONSTRUCTABLE:TRUE unchanged
EMITTER_UIDS:00004F unchanged
EMITTER_POSITION_OPTIONAL unchanged blank
```

2. Replace the stale status bullets:

Replace:

```text
- Parent attachment: attached to [UID:00004F][Encoder](by-class/Encoder.md) because this page is now `84/90`, the class is `82/86`, and [UID:0000J1][Encoder](by-file/Encoder.md) is the class's concrete file parent.
- Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold.
```

With:

```text
- Parent/emitter route: attached to [UID:00004F][Encoder](by-class/Encoder.md) and emitted through that class to [UID:0000J1][Encoder](by-file/Encoder.md). The direct class is now `86/90`, the file root is `86/88`, and the route surfaces to `auto-generated/NexusTK/util/Encoder.cpp`.
- C++ gate: eligible under the active combined-score/emitter rule (`RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(88 + 90) / 2 > 85`). The old `95/95` no-code threshold is stale; first-draft C++ is populated for this exact method only.
```

3. Add a `Source Shape And Field Names` section after `Behavior`:

```markdown
## Source Shape And Field Names

Recommended source-facing signature: `void Encoder::WriteShort(unsigned short value)`.

The method uses the shared Encoder cursor layout: `+0x04` output buffer, `+0x08` capacity, `+0x0c` write cursor, `+0x10` byte-order flag, and `+0x11` valid/writable flag. The first-draft C++ uses descriptive member names `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`; these names are behavior-backed but not proven original symbols.

Nonzero `m_useBigEndian` writes the high byte first and then the low byte. Zero `m_useBigEndian` writes the native little-endian `unsigned short` directly. The capacity check requires `m_writePos + 3` so that the two payload bytes still leave one byte for [UID:00013K][EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md)'s trailing NUL.
```

4. Add a `First-Draft C++` section containing the code block above, or populate only the formal `RECONSTRUCTION_CPP CODE` block and add a short prose section saying the formal block is the first draft.

5. Add a `Score And Gate Rationale` section:

```markdown
## Score And Gate Rationale

Completion is raised to `88` after this source-quality pass because the page now records the active code-entry gate, source-facing signature, field-name mapping, byte-order behavior, overflow behavior, caller route, adjacent raw-helper boundary, and first-draft C++ for the exact method. Confidence remains `90` because the recorded IDA evidence is strong and consistent across the Encoder class/file/type docs, but current-session IDA MCP was unavailable and exact original member names remain descriptive rather than symbol-proven.
```

6. Add to `Changes`:

```markdown
- 2026-06-19 B015 source-quality report:
  - Before: `COMPLETION:84`, `CONFIDENCE:90`, correct owner/emitter route, but stale final-C++ blocker text still cited an obsolete `95/95` threshold.
  - Recommended after implementation: `COMPLETION:88`, `CONFIDENCE:90`, unchanged owner/emitter route, and first-draft `Encoder::WriteShort(unsigned short)` C++ under the active combined-score/emitter gate.
  - Evidence: existing IDA-backed docs confirm exact `0x004a4f00-0x004a4f59` bounds, no callees, TextEditPane serialization call sites, `+0x04/+0x08/+0x0c/+0x10/+0x11` field roles, high-byte-first byte-order branch, native little-endian direct store when the byte-order flag is zero, overflow invalidation, and the adjacent raw 24-bit helper boundary outside this page. Current-session IDA MCP was unavailable, so confidence stays below final audit.
```

## Follow-Up Actions

Supervisor actions:

- Review this report and send B015 an implementation checklist if accepted.
- Keep `by-memory/-coverage-report.md` supervisor-owned; apply the exact replacement row below after target implementation or during downtime.
- After implementation, run target file validation and autogen refresh.

B015 implementation actions when called back:

- Lease the target if required by the leaser rules.
- Edit only [UID:00013G] and any explicitly accepted support docs.
- Do not edit `by-memory/-coverage-report.md`.
- Populate the formal `RECONSTRUCTION_CPP CODE` block unless supervisor rejects the draft.
- Report changed files, validation results, and pending coverage text.

Future B-agent/A-agent actions outside this target:

- Research exact child pages for raw Encoder helper islands, especially likely `SetByteOrder` at `0x004a4eb0-0x004a4ebd` and likely `WriteTriByte`/`Write24` at `0x004a4f60-0x004a4fe3`.
- Consider a coordinated pass over sibling exact Encoder method pages [UID:00013F], [UID:00013H], [UID:00013I], [UID:00013J], and [UID:00013K] because they carry the same stale `95/95` no-code wording and now likely need first-draft C++ under the active gate.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/90` after implementation; not final-audit level.
- Remaining uncertainty: exact original member names, exact original header split, sibling raw helper names, and no current-session IDA MCP verification.

## Validator Results / Validation Needs

No validator command was run because this was a report-only pass and no by-* files were edited.

Recommended commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00013G-EncoderWriteShort-source-quality-removed.md](00013G-EncoderWriteShort-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the validator expects paths relative to `source-3/project-documentation`, use:

> Executable block R002 was removed from this report and preserved verbatim in [00013G-EncoderWriteShort-source-quality-removed.md](00013G-EncoderWriteShort-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended post-validation checks:

> Executable block R003 was removed from this report and preserved verbatim in [00013G-EncoderWriteShort-source-quality-removed.md](00013G-EncoderWriteShort-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B015. Supervisor should replace the current [UID:00013G] row near the existing [UID:00013F] / [UID:00013H] rows with:

```markdown
    - [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) 0x004a4f00-0x004a4f59 | method | EncoderWriteShort : reconstructable : 88% : strong : B015 source-quality review clears the active combined-score/emitter C++ gate for this exact `Encoder::WriteShort(unsigned short)` method through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md). Documented behavior: valid flag `+0x11` gates writes, capacity `+0x08` must cover cursor `+0x0c` plus two payload bytes and the final-NUL reserve, byte-order flag `+0x10` writes high byte first when nonzero and a native little-endian word when zero, overflow clears valid without partial writes, three TextEditPane serialization length-prefix call sites are known, no callees are present, and adjacent raw 24-bit writer bytes at `0x004a4f60-0x004a4fe3` remain outside this page. First-draft C++ is recommended for the formal reconstruction block; exact member names remain descriptive rather than symbol-proven.
```

No delete/insert of neighboring coverage rows is recommended for this target.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00013G-EncoderWriteShort-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00013G-EncoderWriteShort-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00013G"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013G-EncoderWriteShort-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00013G-EncoderWriteShort-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
