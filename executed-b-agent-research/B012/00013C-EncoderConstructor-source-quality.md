** TARGET-REPORT-UID:00013C **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013C EncoderConstructor Source Quality / C++ Gate Research

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:00013C] `0x004a4e70-0x004a4e94.EncoderConstructor` from stale below-95 no-code wording to current combined-score/emitter gate wording, raise the target from `84/90` to `87/91`, and populate first-draft source-level constructor C++.
- Final disposition: keep `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004F`. The direct route is `EncoderConstructor` -> [UID:00004F] `Encoder` -> [UID:0000J1] `NexusTK/util/Encoder.cpp`.
- Required action: supervisor implementation callback should edit only the target/support docs accepted from this report, then the supervisor should apply the pending `by-memory/-coverage-report.md` row because B agents remain banned from editing that file directly.
- Confidence: high for constructor behavior, direct owner, emitter route, source-level constructor shape, and code-gate eligibility; medium-high for exact original member/header spelling.

## Target

- Target UID: `00013C`
- Target path: `source-3/project-documentation/by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00013C-EncoderConstructor-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, blank C++ block.
- Current stale blocker: the page says final C++ is blank because it is below the old `95/95` threshold.
- Current gate state: reconstructable target, nonblank emitter route, and current combined score already averages above 85. After this source-quality pass, recommended `87/91` clears both the strict 85/85 documentation-routing expectation and the active `(COMPLETION + CONFIDENCE) / 2 > 85` reconstruction-C++ gate.

## Supervisor Active Recheck

- User explicitly assigned B012 to source-quality / heuristic research for [UID:00013C] `EncoderConstructor`.
- This is a report-first B-agent pass. I did not edit the target page, support by-* docs, generated reports, or `by-memory/-coverage-report.md`.
- The assigned item does not require split repair. The exact half-open function range is already narrow and is bounded by padding before the next `Encoder` destructor.

## Evidence Checked

- Required project rules: `by-structure.md`, `inference_research.md`, `.codex/AGENTS.md`, `Supervisor.md`, and B012 `goal.md`.
- Target/support docs:
  - `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md`
  - `by-memory/0x004a4e70-0x004a5621.EncoderCore.md`
  - `by-class/Encoder.md`
  - `by-file/Encoder.md`
  - `by-file/BinaryCodec.md`
  - `by-type/by-struct/BinaryCodecCursorLayout.md`
  - `by-type/by-vtable/BinaryCodecVtables.md`
  - `by-memory/0x006192c8-0x006192d4.EncoderVtableData.md`
  - `by-item/EncodeTextEditState_0058E490.md`
- Generated/report docs:
  - `by-memory/-coverage-report.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-project-structure/proposed-source-tree.md`
- Prior B-agent report used as a lead and rechecked against target evidence: `Agent-B002/research/executed/00013D-encoder-core-index-source-quality.md`.
- Local exported binary/decompiler evidence:
  - `resources/exported_data/functions/0x004a4e70.json`
  - `hooks-generation/tests/function_data/ghidra/0x004a4e70.json`
  - `resources/exported_data/functions/0x0058e490.json`
  - `resources/exported_data/master_function_list.json`
  - `resources/exported_data/master_globals.json`
- Direct local PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP status: attempted `initialize` against `http://127.0.0.1:13337/mcp`; connection failed with `Unable to connect to the remote server`. No new live MCP facts were added in this pass. Existing docs record multiple prior live IDA MCP checks, and the local PE/exported evidence agrees with them.

## Direct Binary Byte Audit

- Binary audited: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247E04E20B65D6414C7238AA8FF5515`
- SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- Image base from PE header: `0x00400000`.
- Constructor VA `0x004a4e70` maps to `.text`, raw offset `0x000a4270`.
- Range size `0x24` / 36 bytes (Verified with `int_convert.py`).
- Preceding padding `0x004a4e6b-0x004a4e70`: `cc cc cc cc cc`.
- Constructor bytes:

```text
c7 01 cc 92 61 00 8b c1 c7 41 04 00 00 00 00 c7
41 08 00 00 00 00 c7 41 0c 00 00 00 00 66 c7 41
10 01 01 c3
```

- Following padding `0x004a4e94-0x004a4ea0`: twelve `cc` bytes.
- Instruction meaning:
  - store vtable pointer `0x006192cc` at `this+0x00`;
  - return `this` in `eax`;
  - zero dwords at `+0x04`, `+0x08`, and `+0x0c`;
  - write word `0x0101` at `+0x10`; `0x0101` is decimal 257 (Verified with `int_convert.py`);
  - return.

## IDA/Ghidra Export Facts

- `resources/exported_data/functions/0x004a4e70.json` reports:
  - IDA name `sub_4A4E70`;
  - Ghidra/OOAnalyzer class `Encoder`, method type `ctor`;
  - size 36 bytes in both IDA and Ghidra;
  - `num_callers` 1, `num_callees` 0;
  - IDA xref from `0x0058e4e4` inside `sub_58E490`.
- The IDA decompile exported for `0x004a4e70` exactly matches the byte audit: vtable store, three zero dwords, word `257` at offset `+0x10`, and return `this`.
- The Ghidra decompile agrees semantically and names the source-shaped function `Encoder::Encoder(Encoder *this)`.
- `resources/exported_data/functions/0x0058e490.json` confirms the direct consumer constructs a stack `Encoder`, initializes it against a stack buffer, writes data through Encoder methods, finalizes, then destroys it. That supports utility-class use, not ownership by TextEditPane.
- `resources/exported_data/master_globals.json` records the vtable at `0x006192cc` as `Encoder::vftable_6192cc`, referenced by `0x004a4e70`, `0x004a4ea0`, and `0x004a5e30`, matching the target/class/vtable docs.

## Heuristic / Inference Reanalysis And Validation

### Constructor source shape

- Best source-facing form: `Encoder::Encoder()` using an initializer list for the caller-buffer pointer, capacity, write position, byte-order flag, and valid/writable flag.
- The vtable write is compiler-generated C++ object construction behavior and must not be manually emitted as `*(void**)this = ...` in source.
- The decompiler return value is the constructor ABI convention; final source should not write a `return this;` statement.
- Recommended first-draft source uses descriptive field names already supported by `Encoder` and `BinaryCodecCursorLayout`: `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable`.

### Encoder fields and buffer ownership

| Offset | Best source-facing field | Constructor value | Ownership / meaning |
| --- | --- | --- | --- |
| `+0x04` | `m_outputBuffer` | `NULL` | Caller-owned attached output buffer; `Encoder` does not allocate or free it. |
| `+0x08` | `m_capacity` | `0` | Caller-supplied capacity/limit. |
| `+0x0c` | `m_writePos` | `0` | Current write cursor. |
| `+0x10` | `m_useBigEndian` | `true` | Nonzero path writes scalar values big-endian. |
| `+0x11` | `m_isWritable` | `true` | Valid/writable flag cleared on overflow. |

- The word store `0x0101` is best represented as two adjacent `bool` or byte fields initialized to `true`. Treating it as one 16-bit configuration member loses the separate byte-order and valid-flag roles proven by the writer/finalize methods.
- `Initialize` attaches caller storage and resets cursor/valid state.
- `Finalize` optionally reports the cursor, writes the trailing NUL, then detaches the buffer and resets valid state.
- The ordinary destructor only restores the class vtable and does not free the buffer. This rejects owned-buffer construction/destruction semantics.

### Class/file routing

- Accepted direct semantic owner: [UID:00004F] `Encoder`.
- Accepted output emitter: [UID:00004F] `Encoder`, which routes through [UID:0000J1] `Encoder` file root at `NexusTK/util/Encoder.cpp`.
- [UID:0000HQ] `BinaryCodec` remains the shared family coordinator for `Encoder`, `Decoder`, cursor layout, and compact vtables. It is not the direct owner of this exact constructor because the range is an `Encoder` class method and only writes the `Encoder` vtable/fields.
- [UID:0000ON] `TextEditPane` owns the serializer caller, not the `Encoder` constructor. Its use of a stack `Encoder` is consumer evidence only.
- `PacketBuffer` / network ownership remains rejected: no packet send/receive owner is the direct caller, and this class writes caller-owned memory independently of socket framing.

### Callers and reachability

- Direct ordinary caller: `0x0058e4e4` inside [UID:0000UM] `EncodeTextEditState_0058E490`.
- The serializer itself is reached through a raw wrapper jump at `0x00498c4a`, already documented under TextEditPane/TextEditControlPane evidence.
- No callees from the constructor.
- No evidence of a second live feature owner surfaced in docs, exported function xrefs, or coverage rows.

### Compiler-generated/raw names

- `sub_4A4E70` and `ctor_0x4a4e70` are generated/raw aliases. Source-facing name should be `Encoder::Encoder()`.
- `off_6192CC`, `vftable_006192cc`, and `??_R4Encoder@@6B@` are compiler/RTTI/vtable artifacts. Source should declare the class and virtual surface, not hand-write those values in the constructor.
- Ghidra `mbr_0x4`, `mbr_0x8`, `mbr_0xc`, and `mbr_0x10` are raw field placeholders. They should be replaced in docs/source drafts with the descriptive names above.

### Open questions

- Exact original member names are not proven by symbols. Descriptive names are still good enough for first-draft code because field roles are independently proven.
- Exact header split remains open between separate `Encoder.h` / `Decoder.h` declarations and a compact shared `BinaryCodec.h`. This does not block the constructor body under the current emitter route.
- Final `sizeof(Encoder)` and tail padding remain open. Observed fields span through `+0x11`; the constructor does not need the final allocation size to emit a correct member initializer.
- Raw helper islands elsewhere inside `0x004a4e70-0x004a5621` remain future work for the full Encoder class, but they are outside this constructor range.
- There is no remaining constructor-specific blocker that justifies keeping this target C++ blank.

## Ranked Ownership Analysis

### 1. [UID:00004F] Encoder class

- Evidence for: constructor stores the `Encoder` vtable `0x006192cc`, initializes the shared Encoder cursor fields, has matching ordinary/scalar destructor vtable refs, and sits in the documented Encoder method cluster.
- Evidence against: exact original member names are inferred, not symbol-proven.
- Decision: accepted as direct owner and emitter.

### 2. [UID:0000J1] Encoder source file

- Evidence for: class parent routes to a validated `NexusTK/util/` file root; proposed source tree and file doc both place `Encoder.cpp` in util; method cluster is Encoder-only.
- Evidence against: original source could have used a paired `BinaryCodec.cpp`/header, but current docs keep `BinaryCodec` as coordinator rather than concrete method owner.
- Decision: accepted as file route through the class, not as direct `CANONICAL_OWNER`.

### 3. [UID:0000HQ] BinaryCodec coordinator

- Evidence for: shared layout/vtable family with Decoder, and `BinaryCodec` owns the cross-class layout/vtable docs.
- Evidence against: this exact body writes only `Encoder` fields/vtable and has a narrower class owner that clears the gate.
- Decision: keep as cross-reference/coordinator only.

### 4. TextEditPane / PacketBuffer / network owners

- Evidence for: TextEditPane serializer is the only direct behavioral caller.
- Evidence against: consumer xref does not own the class implementation; no network packet path calls the constructor; `PacketBuffer` owns packet scalar helpers elsewhere, not this caller-buffer utility class.
- Decision: rejected for ownership/emitter routing.

## First-Draft C++ Recommendation

Populate the target's formal `RECONSTRUCTION_CPP CODE` block with:

```cpp
Encoder::Encoder()
    : m_outputBuffer(NULL),
      m_capacity(0),
      m_writePos(0),
      m_useBigEndian(true),
      m_isWritable(true)
{
}
```

Rationale:

- Covers only this constructor range.
- Does not hand-emit compiler-generated vtable writes.
- Represents the three zero dword stores and the `0x0101` flag word as normal C++ member initialization.
- Uses late-1990s/mid-2000s-compatible C++ style (`NULL`, simple initializer list, no modern constructs).
- Correctly keeps the output buffer caller-owned.

## Score / Metadata Recommendation

- Before: `COMPLETION:84`, `CONFIDENCE:90`.
- After recommendation: `COMPLETION:87`, `CONFIDENCE:91`.
- Metadata unchanged:
  - `CANONICAL_OWNER:00004F`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00004F`
  - `EMITTER_POSITION_OPTIONAL:` blank
- Score rationale: completion should rise because this pass resolves the stale no-code blocker, current code gate, source-level constructor shape, field role names, caller/buffer ownership, and rejected owner alternatives. Confidence rises slightly because the direct PE byte audit and exported IDA/Ghidra data agree with existing IDA-backed docs. Scores remain below `95+` because original field/header names and class-wide helper islands are not final-audit complete.

## Recommended Exact Doc Changes

### Target metadata

Change the target header values to:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave these values unchanged:

```text
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Target reconstruction C++

Replace the currently empty formal C++ block contents with:

```cpp
Encoder::Encoder()
    : m_outputBuffer(NULL),
      m_capacity(0),
      m_writePos(0),
      m_useBigEndian(true),
      m_isWritable(true)
{
}
```

### Target status wording

Replace:

```text
- Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold.
```

With:

```text
- Reconstruction C++ should be populated under the active combined-score/emitter gate: this page is `RECONSTRUCTABLE:TRUE`, emits through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md), and the recommended `87/91` score gives a combined value above 85. The emitted source should be a source-level constructor initializer list; the binary vtable store is compiler-generated and must not be hand-written.
```

### Target behavior/source-quality addition

Add or merge this under `## Behavior` or a new `## Source Shape` section:

```text
Source-facing constructor shape: initialize `m_outputBuffer` to `NULL`, `m_capacity` and `m_writePos` to `0`, and both `m_useBigEndian` and `m_isWritable` to `true`. The binary `0x0101` word store is best interpreted as two adjacent true byte/bool fields, not one opaque 16-bit mode. The constructor does not allocate a buffer; later `Initialize` attaches caller-owned storage, and `Finalize`/destructor detach or restore state without freeing that storage.
```

### Target evidence addition

Add a `2026-06-19 B012 Source-Quality Recheck` entry:

```text
- 2026-06-19 B012 source-quality recheck: IDA MCP was unavailable in this session (`127.0.0.1:13337` refused connection), so no new live IDB command was recorded. Local PE byte audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`) maps `0x004a4e70` to `.text` raw offset `0x000a4270` and reads the exact `0x24` / 36-byte constructor body (Verified with `int_convert.py`): vtable store `0x006192cc`, `mov eax, ecx`, zero stores at `+0x04/+0x08/+0x0c`, word store `0x0101` at `+0x10`, and `ret`, bracketed by `0xcc` padding before and after. Exported IDA/Ghidra function data agrees: one caller at `0x0058e4e4` inside `EncodeTextEditState_0058E490`, no callees, and source-shaped `Encoder::Encoder` constructor classification.
```

### Target changes entry

Append:

```text
- 2026-06-19 B012 source-quality report:
  - Before: `COMPLETION:84`, `CONFIDENCE:90`, and final C++ blank because of stale below-95 code-gate wording.
  - Recommended after implementation: `COMPLETION:87`, `CONFIDENCE:91`, owner/emitter unchanged at [UID:00004F][Encoder](by-class/Encoder.md), and first-draft constructor C++ populated.
  - Evidence: local PE bytes and exported IDA/Ghidra data agree with prior live IDA docs for exact range, vtable store, field zeroing, `0x0101` flag initialization, one TextEditPane serializer caller, no callees, caller-owned buffer semantics, and source route through `NexusTK/util/Encoder.cpp`.
```

## Exact Pending Coverage Text

Do not let B012 edit `source-3/project-documentation/by-memory/-coverage-report.md` directly. Supervisor should replace the current [UID:00013C] row with:

```text
    - [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) 0x004a4e70-0x004a4e94 | method | EncoderConstructor : reconstructable : 87% : strong : Encoder constructor; source-quality review clears the current combined-score/emitter C++ gate, routes through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md), and recommends source-level `Encoder::Encoder()` initializer code for caller-owned buffer/capacity/cursor zeroing plus default big-endian/writable flags. Existing IDA/exported evidence confirms the exact vtable store, field clears, flags word `0x0101`, single text-edit serializer caller, no callees, and padding before destructor.
```

Expected generated `auto-generated/-ag-memory-coverage.md` row after target implementation/validation, for verification only:

```text
| [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) | coded | `00004F` | `00004F` |  | yes | `auto-generated/NexusTK/util/Encoder.cpp` | `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md` |  |
```

## Validator Needs

For the later implementation callback, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00013C-EncoderConstructor-source-quality-removed.md](00013C-EncoderConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If that file scan does not refresh generated output, run:

> Executable block R002 was removed from this report and preserved verbatim in [00013C-EncoderConstructor-source-quality-removed.md](00013C-EncoderConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Suggested post-validation checks:

> Executable block R003 was removed from this report and preserved verbatim in [00013C-EncoderConstructor-source-quality-removed.md](00013C-EncoderConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected effects after implementation:

- [UID:00013C] leaves the low-completion reconstructable list in `project-level/-auto-completion-stats.md`.
- `auto-generated/-ag-memory-coverage.md` changes [UID:00013C] from `emits`/`no` to `coded`/`yes`.
- `auto-generated/NexusTK/util/Encoder.cpp` receives the constructor snippet through the existing emitter route.

## Negative Evidence Summary

- No live IDA MCP evidence could be gathered in this session because the MCP endpoint was offline. I did not invent live command results.
- No direct evidence supports moving the constructor to TextEditPane; TextEditPane is only the stack-object consumer.
- No packet/network caller supports PacketBuffer ownership.
- No source-level evidence supports hand-writing `off_6192CC` into the constructor; that is compiler-generated vptr initialization.
- No evidence shows the constructor allocates, owns, or frees the output buffer.
- The old `95/95` code-entry threshold is stale under current `by-structure.md`/Supervisor rules.

## Follow-Up Actions

- Supervisor: review this report, then send B012 an implementation checklist if accepted.
- B012 implementation callback: lease/edit only the accepted target/support files, populate the constructor C++ block, update metadata/body wording, validate, and report validation results.
- Supervisor-owned coverage: apply the exact pending `by-memory/-coverage-report.md` row above after the target edit is accepted.
- Future B/A agents: exact source-quality passes for sibling Encoder methods should replace the same stale below-95 no-code wording independently, but those pages are outside this target report.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00013C-EncoderConstructor-source-quality.md`
- Modified: none outside B012 research.
- Coverage report edits: none; exact pending row is included above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00013C-EncoderConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00013C"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013C-EncoderConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00013C-EncoderConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
