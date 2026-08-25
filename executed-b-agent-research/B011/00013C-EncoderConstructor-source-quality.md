** TARGET-REPORT-UID:00013C **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013C EncoderConstructor Source Quality Research

## Finalized Report / Current Recommendation

- Assignment: `B011-goal2-encoder-constructor-source-quality-00013C-20260619`.
- Target: [UID:00013C] `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md`.
- Current recommendation: keep [UID:00013C] as source-bearing `Encoder::Encoder()`, raise it from `84/90` to `87/91`, keep owner/emitter routing unchanged, replace stale below-95 no-code wording with current combined-score/emitter gate analysis, and populate first-draft constructor C++.
- Final disposition: exact class constructor body, owned by [UID:00004F] `Encoder`, emitted through [UID:00004F] to [UID:0000J1] `Encoder` / `auto-generated/NexusTK/util/Encoder.cpp`.
- Required action: supervisor implementation callback should update the target metadata/body/C++ block and any accepted support-doc wording. Do not edit `by-memory/-coverage-report.md` directly; exact replacement row is below.
- Confidence: high for range, behavior, direct owner, emitter route, source-level constructor shape, and code-gate eligibility; medium-high for exact historical member/header spelling because field names are descriptive inferences.

Recommended target metadata after implementation:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The score change is `84/90 -> 87/91`. Completion should rise because the stale no-code blocker is resolved, the source-level constructor shape is ready, the field-role questions for this exact body are closed enough for first-draft C++, and ownership/caller alternatives have been rechecked. Confidence should rise slightly because target docs, support docs, exported IDA/Ghidra data, and a direct PE byte audit agree. Scores should stay below final audit because original field names, exact header split, and full class helper-island source remain inferred or unfinished.

## Target

- Target UID: `00013C`.
- Target path: `source-3/project-documentation/by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00013C-EncoderConstructor-source-quality.md`.
- Current target metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, blank formal C++.
- Current stale blocker: the target says final C++ is blank because it is below an old `95/95` reconstruction-code threshold.
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists [UID:00013C] as `emits` through [UID:00004F] to `auto-generated/NexusTK/util/Encoder.cpp`, but generated `Encoder.cpp` currently contains only an empty emitter marker for this UID.

## Executive Recommendation

[UID:00013C] should remain an exact source-bearing `Encoder` constructor and should receive first-draft C++.

The active C++ gate is met now:

- `RECONSTRUCTABLE:TRUE`
- nonblank `EMITTER_UIDS:00004F`
- emitter chain reaches [UID:00004F] `Encoder` -> [UID:0000J1] `Encoder` -> `NexusTK/util/Encoder.cpp`
- current combined score is `(84 + 90) / 2 = 87`, already greater than `85`

The page's old `95/95` wording is stale. The current `by-structure.md` gate requires reconstructable status, a valid nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`; it does not require 95/95 to start first-draft C++.

No split or reclassification is needed. The half-open function range is already exact, and the surrounding bytes are padding before the non-deleting destructor. [UID:00013D] `EncoderCore` is the non-emitting index; this exact child is one of the source-bearing method pages that should carry code.

## Supervisor Active Recheck

This was a report-only B-agent assignment. I did not edit target/support by-* documentation, generated files, project-level reports, IDA DB state, or `by-memory/-coverage-report.md`.

The assigned item does not require split repair:

- Exact range: `0x004a4e70-0x004a4e94`.
- Size: `0x24` / 36 bytes (Verified with `int_convert.py`).
- Preceding bytes: five `0xcc` bytes at `0x004a4e6b-0x004a4e70`.
- Following bytes: twelve `0xcc` bytes at `0x004a4e94-0x004a4ea0` before [UID:00013E] `EncoderDestructor`.

IDA MCP was attempted for this pass but was not reachable:

```text
MCP_ERROR: Unable to connect to the remote server
```

Therefore this report does not invent new live-IDB claims. It relies on current by-* docs' recorded live IDA evidence, exported IDA/Ghidra function data, generated coverage/output, support docs, and a direct local PE byte audit.

## Evidence Checked

- Required project rules:
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
  - `.codex/AGENTS.md`
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Agent-B011/goal.md`
- Target and support docs:
  - `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md`
  - `by-memory/0x004a4e70-0x004a5621.EncoderCore.md`
  - `by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md`
  - `by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md`
  - `by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md`
  - `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md`
  - `by-memory/0x006192c8-0x006192d4.EncoderVtableData.md`
  - `by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md`
  - `by-class/Encoder.md`
  - `by-file/Encoder.md`
  - `by-file/BinaryCodec.md`
  - `by-type/by-struct/BinaryCodecCursorLayout.md`
  - `by-type/by-vtable/BinaryCodecVtables.md`
  - `by-item/EncodeTextEditState_0058E490.md`
- Generated and coverage evidence:
  - `auto-generated/NexusTK/util/Encoder.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `by-memory/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
- Prior reports used as leads and rechecked against current evidence:
  - `Agent-B002/research/executed/00013D-encoder-core-index-source-quality.md`
  - `Agent-B006/research/0001X1-BinaryCodecVtables-source-quality.md`
  - `Agent-B011/research/00013K-EncoderFinalize-source-quality.md`
  - `Agent-B012/research/00013C-EncoderConstructor-source-quality.md`
- Exported function evidence:
  - `resources/exported_data/functions/0x004a4e70.json`
  - `hooks-generation/tests/function_data/ghidra/0x004a4e70.json`
  - `resources/exported_data/functions/0x0058e490.json`
- Direct byte evidence:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`

## Direct Binary Byte Audit

- Binary audited: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5: `4247E04E20B65D6414C7238AA8FF5515`.
- SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Target VA `0x004a4e70` maps to raw offset `0x000a4270` / decimal `672368` (Verified with `int_convert.py`).
- Byte window from raw offset `0x000a426b`:

```text
cc cc cc cc cc
c7 01 cc 92 61 00 8b c1 c7 41 04 00 00 00 00 c7
41 08 00 00 00 00 c7 41 0c 00 00 00 00 66 c7 41
10 01 01 c3
cc cc cc cc cc cc cc cc cc cc cc cc
```

Instruction-level meaning:

- `c7 01 cc 92 61 00`: store vtable pointer `0x006192cc` at `this+0x00`.
- `8b c1`: move `this` into `eax`, the constructor ABI return value.
- `c7 41 04 00 00 00 00`: zero dword at `this+0x04`.
- `c7 41 08 00 00 00 00`: zero dword at `this+0x08`.
- `c7 41 0c 00 00 00 00`: zero dword at `this+0x0c`.
- `66 c7 41 10 01 01`: store word `0x0101` / decimal `257` at `this+0x10` (Verified with `int_convert.py`).
- `c3`: return.

The byte audit confirms the current half-open range and boundary padding. It also confirms that the constructor itself does not allocate, call helpers, attach a caller buffer, or free any state.

## IDA/Ghidra Export Facts

`resources/exported_data/functions/0x004a4e70.json` reports:

- IDA name `sub_4A4E70`; Ghidra source-shaped name `Encoder`; OOAnalyzer class `Encoder`, method type `ctor`.
- Size `36` bytes in both IDA and Ghidra.
- Signature shapes: Ghidra `Encoder * __thiscall Encoder(Encoder * this)`, IDA `_DWORD *__thiscall(_DWORD *this)`.
- `is_thunk:false`, `is_library:false`, `is_external:false`, `has_no_return:false`.
- `num_callers:1`, `num_callees:0`.
- IDA xref from `0x0058e4e4` inside `sub_58E490`.
- Ghidra caller at `FUN_0058e490`.
- Decompilation agrees with the byte audit: vtable store, zero stores at offsets `+0x04`, `+0x08`, `+0x0c`, store `0x101` at `+0x10`, return `this`.

`resources/exported_data/functions/0x0058e490.json` confirms the direct caller constructs a stack `Encoder`, initializes it over a stack buffer, writes text-edit state through `Encoder` writer methods, finalizes, allocates/copies the encoded byte stream, and destroys the stack `Encoder`. That supports `Encoder` as a utility class consumed by TextEditPane, not a TextEditPane-owned implementation.

## Heuristic / Inference Reanalysis And Validation

### 1. Source-bearing constructor or no-code compiler glue

Best inference: source-bearing constructor body.

Evidence checked:

- Target is already `RECONSTRUCTABLE:TRUE` and routes through [UID:00004F].
- Exported IDA/Ghidra records classify the body as non-thunk, non-library, non-external, with one source caller and no callees.
- OOAnalyzer classifies the method as an `Encoder` constructor.
- The body initializes source-visible class state: buffer pointer, capacity, write cursor, byte-order flag, and valid/writable flag.
- [UID:00013D] `EncoderCore` explicitly says exact children such as [UID:00013C] carry source ownership while the broad range is a non-emitting split/index.

Rejected alternatives:

- No-code compiler glue: rejected. The vtable write is compiler lowering, but the field initialization is ordinary source-authored constructor behavior.
- Vtable-only support: rejected because most of the body initializes data members after the vtable store.
- Runtime/library code: rejected by class/vtable ownership, project caller, and no import/library evidence.
- Aggregate-only source: rejected because the exact child page covers the full constructor range, while [UID:00013D] is non-emitting.

Impact: populate first-draft C++ for this exact target. The C++ must omit explicit vtable assignment and return-value scaffolding.

### 2. Constructor source shape

Best source-facing form: `Encoder::Encoder()` with an initializer list:

- `m_outputBuffer(NULL)`
- `m_capacity(0)`
- `m_writePos(0)`
- `m_useBigEndian(true)`
- `m_isWritable(true)`

Evidence checked:

- The three dword zero stores map to the shared cursor layout offsets `+0x04`, `+0x08`, and `+0x0c`.
- `BinaryCodecCursorLayout` documents `+0x10` as byte-order flag and `+0x11` as valid flag.
- The constructor writes adjacent bytes `01 01` as one word store at `+0x10`; this is best represented as two adjacent byte/bool fields both initialized to true.
- Writer docs say nonzero `+0x10` writes scalar values big-endian, and overflow paths clear `+0x11`.
- `Initialize` later attaches caller storage; the constructor only sets a detached but valid default state.

Rejected alternatives:

- Emit `*(void**)this = &off_6192CC;`: rejected because vptr installation is compiler-generated from class construction.
- Emit `return this;`: rejected because C++ constructors have no explicit return.
- Treat `0x0101` as one opaque 16-bit mode field: rejected for source-quality docs because later methods independently address the two flag bytes.
- Treat `0x0101` as a buffer size or capacity: rejected because capacity at `+0x08` is zeroed and later set by `Initialize`.
- Initialize/own a buffer in the constructor: rejected because `+0x04` is cleared and no allocator call exists.

Impact: constructor C++ is ready using descriptive field names. Exact historical names remain inferred, so score stays below final audit.

### 3. Encoder fields and source-facing names

Best field mapping for this constructor:

| Offset | Constructor write | Best source-facing name | Meaning / evidence | Confidence |
| --- | --- | --- | --- | --- |
| `+0x00` | `0x006192cc` | vptr / generated vtable pointer | Installed by compiler from class construction; vtable data refs match Encoder constructor/destructor/scalar destructor. | Confirmed binary role; not a handwritten field. |
| `+0x04` | `0` | `m_outputBuffer` | Caller-owned output buffer pointer; `Initialize` stores it and `Finalize` clears it. | Strong, descriptive. |
| `+0x08` | `0` | `m_capacity` | Output capacity/limit; writers compare against cursor growth. | Strong, descriptive. |
| `+0x0c` | `0` | `m_writePos` | Current write cursor; `Finalize` returns this as bytes written. | Strong, descriptive. |
| `+0x10` | low byte of `0x0101` | `m_useBigEndian` | Nonzero path writes scalar values high-byte first. | Strong, descriptive. |
| `+0x11` | high byte of `0x0101` | `m_isWritable` | Valid/writable flag; writer overflow clears it, finalize returns prior value and restores true. | Strong, descriptive. |

`m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, and `m_isWritable` are recommended descriptive names for first-draft C++. The docs may mention `m_buffer`, `m_bufferCapacity`, `m_cursor`, and `m_isValid` as acceptable name directions, but this target should pick one coherent set.

Rejected alternatives:

- `mbr_0x4`, `mbr_0x8`, `mbr_0xc`, `mbr_0x10`: generated placeholders, not source-quality names.
- `m_inputBuffer` / `m_readPos`: rejected for Encoder; those are Decoder-side interpretations.
- `m_flags` as a single final field: possible as an implementation detail but worse source-level representation because method bodies read/write the two bytes independently.

### 4. Caller and reachability

Best caller/reachability conclusion: the only confirmed ordinary call to this constructor is from [UID:0000UM] `EncodeTextEditState_0058E490` / [UID:0001JN] `TextEditPaneSerialization`.

Evidence checked:

- Target page records one ordinary caller at call site `0x0058e4e4`.
- Exported function data for `0x004a4e70` records IDA xref from `0x0058e4e4` and Ghidra caller `FUN_0058e490`.
- `TextEditPaneSerialization` docs record the full Encoder call sequence: constructor `0x0058e4e4`, initialize `0x0058e54b`, writers, finalize `0x0058e624`, destructor `0x0058e66c`.
- `EncodeTextEditState_0058E490` is TextEditPane-owned and reached through a raw TextEditControlPane forwarding jump at `0x00498c4a`.

Rejected alternatives:

- TextEditPane owns the constructor: rejected because it constructs and consumes a stack Encoder object; all initialized fields and vtable belong to Encoder.
- Packet/network owner: rejected because no packet sender, socket, or PacketBuffer caller was found in current docs/export data.
- Dead retained code: rejected because there is a direct behavioral caller and generated reports route the constructor as emitting.

Impact: reachability supports utility ownership. No route blocker remains for this exact target.

### 5. Owner/emitter/source placement

Best route:

- Direct semantic owner: [UID:00004F] `Encoder`.
- Concrete source root: [UID:0000J1] `Encoder`, projected to `NexusTK/util/Encoder.cpp`.
- Family coordinator/context: [UID:0000HQ] `BinaryCodec`.

Evidence checked:

- `by-class/Encoder.md` is `86/90`, reconstructable, emits through [UID:0000J1], lists [UID:00013C] as constructor, and documents the complete method/vtable surface.
- `by-file/Encoder.md` is `86/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, and lists [UID:00013C] under proposed contents.
- `by-project-structure/proposed-source-tree.md` places `Encoder.cpp`, `Decoder.cpp`, and `BinaryCodec.cpp` under `NexusTK/util/`, and states `Encoder.cpp` owns exact in-memory writer children inside `0x004a4e70-0x004a5621`.
- `auto-generated/NexusTK/util/Encoder.cpp` already includes an empty emitter marker for [UID:00013C].
- `BinaryCodec.md` is the source-family coordinator, not the exact method owner.

Rejected alternatives:

- `CANONICAL_OWNER:0000J1`: rejected because `by-structure.md` requires the narrowest direct semantic owner; this is a class method.
- `CANONICAL_OWNER:0000HQ`: rejected because this exact body initializes only Encoder state; BinaryCodec is broader context.
- `CANONICAL_OWNER:0000ON` / TextEditPane: rejected because TextEditPane is only the consumer.
- `CANONICAL_OWNER:NONE`: rejected because class/file route is well supported and gated.

Impact: keep `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004F`.

### 6. Vtable store and compiler-generated names

Best handling:

- Source-facing constructor name should be `Encoder::Encoder()`.
- `sub_4A4E70`, `ctor_0x4a4e70`, `off_6192CC`, `vftable_006192cc`, and raw `mbr_0x...` names should be kept only as evidence/search aliases, not as final source names.
- The constructor's explicit vtable store should be documented as compiler lowering from the class declaration and virtual surface. Do not hand-code it.

Evidence checked:

- [UID:0003IA] `EncoderVtableData` documents RTTI/vtable child `0x006192c8-0x006192d4`, with `0x006192cc` slot base.
- [UID:0001X1] `BinaryCodecVtables` documents `0x006192cc` xrefs from constructor `0x004a4e70`, destructor `0x004a4ea0`, and scalar deleting destructor `0x004a5e3a`.
- [UID:00013V] scalar deleting destructor report/docs classify delete-wrapper behavior as compiler-generated, not handwritten source.

Rejected alternatives:

- Emit the scalar deleting destructor or vtable dwords in this constructor: rejected as compiler/linker ABI support.
- Use IDA raw names in C++: rejected by source-quality rules.

Impact: target docs should explicitly distinguish source-authored member initialization from compiler-emitted vptr setup.

### 7. Open questions and score impact

Resolved for this exact page:

- Exact function range and padding boundaries.
- Constructor behavior and field writes.
- Source-bearing versus no-code policy.
- Direct owner/emitter route.
- Direct caller and no-callee status.
- First-draft C++ source shape.

Remaining open but not blocking first-draft constructor C++:

- Exact original member names are not proven by debug symbols. Use descriptive names and keep score below final audit.
- Exact header split remains open: separate `Encoder.h` / `Decoder.h` or a compact `BinaryCodec.h` are both plausible. This does not change the constructor body under current `Encoder.cpp` route.
- Final `sizeof(Encoder)` and tail padding remain open. Observed field use spans through `+0x11`; constructor C++ does not need a final allocation-size proof.
- Raw helper islands elsewhere in [UID:00013D] still need separate exact-child research. They do not change this constructor's range or source shape.
- The exact original spelling of the valid flag may have been `m_isValid`, `m_valid`, or similar. `m_isWritable` is descriptive and supported by writer behavior.

Score impact: these residual naming/header/class-wide questions cap confidence below final-audit range but do not justify leaving the C++ block blank under the current gate.

## Evidence Standards Used

Evidence types used:

- Direct local executable bytes and hashes.
- Exported IDA/Ghidra function metadata and decompilation.
- Current by-* docs with recorded live IDA evidence.
- Vtable/read-only data docs.
- Direct caller docs for TextEditPane serialization.
- Generated autogen route and coverage rows.
- Prior B-agent reports as leads, rechecked against current target/support docs.

Why evidence is strong enough:

- Three independent evidence streams agree on size, range, constructor classification, one caller, no callees, and field writes.
- Class/file/type docs already clear the direct owner and emitter route gates.
- No competing owner has positive evidence beyond consumer xrefs.

What prevents stronger confidence:

- MCP was offline during this pass, so no new live IDB query was added.
- Original source headers and debug names are not available.
- Class-wide helper islands are not all final-source resolved.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a4e70-0x004a4e94` | `00013C` / target | `Encoder::Encoder()` | `TRUE` | `00004F` | Recommend `87/91` | Exact source-bearing constructor |
| `0x004a4e6b-0x004a4e70` | ignored ledger / coverage row | Pre-constructor alignment | `FALSE` | n/a | `100` coverage | Confirmed `0xcc` padding |
| `0x004a4e94-0x004a4ea0` | target/local boundary evidence | Constructor-to-destructor padding | `FALSE` | n/a | n/a | Twelve `0xcc` bytes before [UID:00013E] |
| `0x004a4ea0-0x004a4ea7` | `00013E` | `Encoder::~Encoder()` | `TRUE` | `00004F` | `84/90` | Exact sibling destructor; vtable restore only |
| `0x004a4e70-0x004a5621` | `00013D` | Encoder writer cluster index | `FALSE` | `00004F` | `86/90` | Non-emitting split/index |
| `0x006192c8-0x006192d4` | `0003IA` | Encoder RTTI/vtable data | `TRUE` | `00004F` | `89/92` | Source-declared/generated-binary support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0058e4e4` | call to `0x004a4e70` | TextEditPane serializer constructs a stack `Encoder`. |
| `0x0058e54b` | call to `0x004a55c0` | Same caller attaches stack buffer through `Encoder::Initialize`. |
| `0x0058e624` | call to `0x004a55e0` | Same caller finalizes and retrieves byte count. |
| `0x0058e66c` | call to `0x004a4ea0` | Same caller destroys stack `Encoder`. |
| `0x006192cc` | vtable base data/support | Constructor writes this compiler-generated vptr value. |

The constructor has no callees.

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page already records exact range, vtable store, three zero dword stores, `0x0101` flags word, one caller, no callees, and padding.
- [UID:00004F] `Encoder` records the shared field layout, constructor/default flags, method inventory, and direct source route.
- [UID:0000J1] `Encoder` records `NexusTK/util/Encoder.cpp` as the concrete source root.
- [UID:0000HQ] `BinaryCodec` records the paired Encoder/Decoder utility family and rejects TextEditPane/network ownership of the class.
- [UID:0001TS] `BinaryCodecCursorLayout` records the offset meanings through `+0x11`.
- [UID:0001X1] `BinaryCodecVtables` and [UID:0003IA] `EncoderVtableData` record the `0x006192cc` vtable evidence.
- [UID:0000UM] / [UID:0001JN] record the direct TextEditPane serialization caller and full Encoder call sequence.

Existing docs that are stale or incomplete:

- Target still says final C++ is blank under an old `95/95` threshold. This is superseded by the current combined-score/emitter gate.
- Target status says the current parent class is `82/88` in older notes; current `by-class/Encoder.md` is `86/90`.
- Some support docs still use older "90/90+" or "95/95" code-entry wording. Those should be corrected opportunistically during accepted implementation passes.
- Raw/generated names such as `sub_4A4E70`, `off_6192CC`, and `mbr_0x...` remain useful evidence labels but should not appear as active source-facing names.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:00013C] as `emits`, owner `00004F`, emitter `00004F`, generated output `auto-generated/NexusTK/util/Encoder.cpp`, but `coded` is `no`.
- `auto-generated/NexusTK/util/Encoder.cpp` currently contains an empty emitter marker for [UID:00013C].
- `by-memory/-coverage-report.md` current row scores [UID:00013C] at `84%` and should be replaced after implementation.

## Ranked Ownership Analysis

### 1. [UID:00004F] Encoder class

Evidence for:

- Constructor installs the `Encoder` vtable and initializes Encoder cursor fields.
- Sibling destructor and scalar deleting destructor use the same vtable.
- Class page lists this exact constructor and clears the 85/85 owner gate.
- Emission through the class reaches a valid `Encoder.cpp` file root.

Evidence against:

- Exact original field names are inferred, not symbol-proven.

Decision: accepted as direct owner and emitter.

### 2. [UID:0000J1] Encoder source file

Evidence for:

- Valid `NexusTK/util/` source root.
- Proposed tree and file doc both say Encoder exact method children belong in `Encoder.cpp`.
- Generated output already routes the constructor there.

Evidence against:

- It is the file root, not the narrow direct semantic owner.
- The original project might have used a paired `BinaryCodec.cpp`/header, but current evidence favors separate `Encoder.cpp` for concrete method output.

Decision: accepted as file route through [UID:00004F], not as direct `CANONICAL_OWNER`.

### 3. [UID:0000HQ] BinaryCodec coordinator

Evidence for:

- Shared layout/vtable family with Decoder.
- Current docs use BinaryCodec as source-family coordinator.

Evidence against:

- This exact body is an Encoder class constructor and writes no Decoder/shared global state.
- A narrower class owner clears the gate.

Decision: keep as context and support-doc owner for shared layout/vtables, not direct owner/emitter for the constructor.

### 4. TextEditPane / TextEditControlPane

Evidence for:

- TextEditPane serialization is the only confirmed behavioral caller.

Evidence against:

- It consumes a stack Encoder object and does not own the Encoder vtable or fields.
- TextEditControlPane only forwards to TextEditPane serialization through a raw wrapper stub.

Decision: rejected as owner; retain as caller evidence.

### 5. PacketBuffer / network / no-owner

Evidence for:

- Generic "Encoder" naming can sound packet-related.

Evidence against:

- No packet/network caller or socket route is documented for this constructor.
- Current direct caller is UI text-edit serialization.
- Class/file route is strong, so no-owner is unnecessary.

Decision: rejected.

## Negative Evidence Summary

- No evidence supports hand-writing the vtable store in source.
- No evidence supports a constructor allocator, buffer ownership, or destructor-side buffer cleanup.
- No evidence supports moving this constructor to TextEditPane, TextEditControlPane, PacketBuffer, Socket, Decoder, or DATFile.
- No evidence supports keeping the target formal C++ blank for compiler-glue reasons; only the vptr write is compiler lowering.
- The old 95/95 code-entry threshold is stale under current `by-structure.md` and supervisor rules.

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

Implementation notes:

- Do not include the explicit `off_6192CC` / vptr store.
- Do not include `return this`.
- Do not allocate or attach a buffer here.
- Keep `NULL` rather than `nullptr` unless the surrounding project has already standardized on newer C++; this code should remain plausible for mid-2000s C++.
- If accepted class field declarations choose `m_buffer`, `m_bufferCapacity`, `m_cursor`, or `m_isValid`, adjust the names consistently but preserve the semantics above.

## Recommended Exact Target Doc Changes

Do not apply during report review; apply only if the supervisor sends an implementation callback.

1. Metadata:

```text
COMPLETION: 84 -> 87
CONFIDENCE: 90 -> 91
CANONICAL_OWNER: keep 00004F
RECONSTRUCTABLE: keep TRUE
EMITTER_UIDS: keep 00004F
```

2. Replace the stale status sentence:

```markdown
- Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold.
```

With:

```markdown
- C++ gate: eligible for first-draft reconstruction C++ under the current `by-structure.md` combined-score/emitter gate because this page is `RECONSTRUCTABLE:TRUE`, emits through [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md), and has combined score above 85. The emitted source should be a source-level constructor initializer list; the binary vtable store is compiler-generated and must not be hand-written.
```

3. Add or merge a source-quality section:

```markdown
## Source-Quality Notes

- Source-facing constructor shape: `Encoder::Encoder()`.
- The constructor initializes a detached caller-buffer writer: `m_outputBuffer = NULL`, `m_capacity = 0`, `m_writePos = 0`, `m_useBigEndian = true`, and `m_isWritable = true`.
- The binary word store `0x0101` at `+0x10` is best interpreted as two adjacent true byte/bool fields (`m_useBigEndian` and `m_isWritable`), not one opaque final source field. Writer/finalize methods access those bytes separately.
- The vtable store to `0x006192cc` is compiler-generated object construction from the class declaration and virtual surface. It is evidence for class identity, not a handwritten source statement.
- The constructor has one confirmed caller, [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md), which constructs a stack Encoder for TextEditPane serialization. The caller does not own this constructor.
```

4. Add a B011 evidence/change entry:

```markdown
- 2026-06-19 B011 source-quality report:
  - Before: `COMPLETION:84`, `CONFIDENCE:90`, owner/emitter already [UID:00004F][Encoder](by-class/Encoder.md), and formal C++ blank under stale below-95 wording.
  - Recommended after implementation: `COMPLETION:87`, `CONFIDENCE:91`, owner/emitter unchanged, and first-draft constructor C++ populated.
  - Evidence: exported IDA/Ghidra records and direct PE bytes agree with prior live IDA-backed docs for exact `0x24` / 36-byte body (Verified with `int_convert.py`), vtable store `0x006192cc`, zero stores at `+0x04/+0x08/+0x0c`, flags word `0x0101` / 257 (Verified with `int_convert.py`), one TextEditPane serialization caller at `0x0058e4e4`, no callees, and padding before [UID:00013E][EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md).
```

5. Populate formal C++ block with the draft above.

6. Prefer source-facing names in prose. Keep raw names only as evidence labels:

```markdown
- IDA/Ghidra exports report the method at `0x004a4e70` with size `0x24`; current source-facing name is `Encoder::Encoder()`.
```

## Recommended Support Doc Changes

Recommended support-doc changes for an implementation callback if the supervisor includes them:

- [UID:00004F] `by-class/Encoder.md`:
  - Add a note that [UID:00013C] now has first-draft constructor C++ using source-level member initialization.
  - Standardize recommended field-name direction for constructor/finalize drafts: `m_outputBuffer`, `m_capacity`, `m_writePos`, `m_useBigEndian`, `m_isWritable`.
  - Preserve caveat that exact original member names and final `sizeof` remain below final audit.
- [UID:0000J1] `by-file/Encoder.md`:
  - Note that [UID:00013C] is no longer merely an empty emitter marker after implementation; it should emit constructor code through [UID:00004F].
  - Keep `Encoder.cpp` as the concrete source root and [UID:0000HQ] `BinaryCodec` as coordinator.
- [UID:0001TS] `by-type/by-struct/BinaryCodecCursorLayout.md`:
  - Replace old final-code gate wording if touched; the active gate is the combined-score/emitter rule.
  - Add that constructor C++ should model `0x0101` as two adjacent true flags, while still documenting the observed word store.
- [UID:0001X1] `by-type/by-vtable/BinaryCodecVtables.md` / [UID:0003IA] `EncoderVtableData`:
  - No metadata change required for this target. Optional note: [UID:00013C] uses the vtable base only as compiler-generated constructor evidence.
- [UID:00013D] `EncoderCore`:
  - No required metadata change. Optionally note that exact child [UID:00013C] has first-draft constructor C++ while the aggregate remains non-emitting.
- [UID:00013E] `EncoderDestructor`:
  - No required metadata change. It has the same stale below-95 wording pattern and should receive its own source-quality/no-code decision separately.

Do not edit `by-memory/-coverage-report.md` directly.

## Exact Pending Coverage Text

Replace the current [UID:00013C] row near `0x004a4e70` in `source-3/project-documentation/by-memory/-coverage-report.md` with:

```markdown
    - [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) 0x004a4e70-0x004a4e94 | method | EncoderConstructor : reconstructable : 87% : strong : B011 source-quality pass confirms this exact Encoder constructor is source-bearing and meets the active C++ gate (`RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, combined score 89). Recommended source-level `Encoder::Encoder()` initializer code clears caller-owned buffer/capacity/cursor state and defaults big-endian/writable flags; vtable store `0x006192cc` is compiler-generated evidence, not handwritten source. Exported IDA/Ghidra data and direct PE bytes confirm exact `0x24` / 36-byte body, field clears at `+0x04/+0x08/+0x0c`, flags word `0x0101`, single TextEditPane serialization caller at `0x0058e4e4`, no callees, and `0xcc` padding before destructor.
```

Expected generated `auto-generated/-ag-memory-coverage.md` row after implementation/validation, for verification only:

```markdown
| [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) | coded | `00004F` | `00004F` |  | yes | `auto-generated/NexusTK/util/Encoder.cpp` | `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md` |  |
```

Expected generated `auto-generated/NexusTK/util/Encoder.cpp` target snippet after implementation/validation:

```cpp
// UID:00013C | by-memory\0x004a4e70-0x004a4e94.EncoderConstructor.md | Completion:87 | Confidence:91
Encoder::Encoder()
    : m_outputBuffer(NULL),
      m_capacity(0),
      m_writePos(0),
      m_useBigEndian(true),
      m_isWritable(true)
{
}
```

The exact generated comment formatting is validator-owned; the source body should match the accepted constructor draft.

## IDA Rename / Type / Comment Recommendations

Report-only recommendations. Do not edit IDA DB in this pass.

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x004a4e70` | Use source-facing function name/comment `Encoder::Encoder()` / `Encoder_Constructor`; keep raw `sub_4A4E70` only as historical/search alias. | Very high |
| `0x006192cc` | Ensure vtable-base comment says `Encoder::vftable`; constructor write is compiler-generated vptr setup. | Very high |
| `+0x04` | Type/name as output buffer pointer, proposed `m_outputBuffer`. | High |
| `+0x08` | Type/name as output capacity/limit, proposed `m_capacity`. | High |
| `+0x0c` | Type/name as write cursor, proposed `m_writePos`. | High |
| `+0x10` | Type/name as byte-order flag, proposed `m_useBigEndian`; default `true`. | High |
| `+0x11` | Type/name as valid/writable flag, proposed `m_isWritable`; default `true`. | High |

Suggested IDA comment for `0x004a4e70`:

```text
Encoder constructor. Compiler stores Encoder vptr 0x006192cc, then source-level initialization clears caller-owned buffer/capacity/write cursor and defaults byte-order and writable flags to true via word store 0x0101.
```

## Validator Results / Validator Needs

No validator was run because this task was report-only and no by-* files were edited.

Recommended validation after an implementation callback updates the target:

> Executable block R001 was removed from this report and preserved verbatim in [00013C-EncoderConstructor-source-quality-removed.md](00013C-EncoderConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are also edited:

> Executable block R002 was removed from this report and preserved verbatim in [00013C-EncoderConstructor-source-quality-removed.md](00013C-EncoderConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended post-validation checks:

> Executable block R003 was removed from this report and preserved verbatim in [00013C-EncoderConstructor-source-quality-removed.md](00013C-EncoderConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected effects after target implementation:

- [UID:00013C] changes from empty emitter marker to generated coded output.
- `auto-generated/-ag-memory-coverage.md` reports [UID:00013C] as coded/yes.
- Manual `by-memory/-coverage-report.md` should use the replacement row above, applied by supervisor.

## Follow-Up Actions

Supervisor actions:

- Review this B011 report and send an implementation callback if accepted.
- Keep `by-memory/-coverage-report.md` supervisor-owned and apply the exact row above after implementation verification.

B011 implementation callback actions if assigned:

- Lease only accepted target/support docs.
- Update target metadata, body evidence, stale gate wording, and formal C++ block.
- Validate scoped files with `--apply --queue-timeout 240`.
- Do not edit `by-memory/-coverage-report.md`.

Future research actions outside this target:

- [UID:00013E] `EncoderDestructor` still has the same stale below-95 wording and needs its own source/no-code decision.
- Raw helper islands inside [UID:00013D] still need exact child source-quality passes before the full `Encoder` class reaches final audit.
- [UID:00013L] no-op virtual declaration name and [UID:00013V] scalar deleting destructor no-code policy should remain aligned with vtable/source-class work.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00013C-EncoderConstructor-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.
- Coverage report edits: none; exact pending row is included above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00013C-EncoderConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00013C"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013C-EncoderConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00013C-EncoderConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
