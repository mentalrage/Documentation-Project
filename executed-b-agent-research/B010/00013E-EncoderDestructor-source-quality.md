** TARGET-REPORT-UID:00013E **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013E Encoder Destructor Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00013E] `0x004a4ea0-0x004a4ea7.EncoderDestructor` as the exact source-bearing non-deleting `Encoder::~Encoder()` method owned by [UID:00004F][Encoder] and emitted through [UID:00004F] to [UID:0000J1][Encoder.cpp].
- Final disposition: source-quality implementation-ready. Replace the stale below-95 no-code rationale with the active combined-score/emitter gate and enter a first-draft empty destructor body.
- Required action: update target metadata/body and formal C++; carry source-shape, no-owned-buffer cleanup proof, scalar deleting destructor relationship, raw neighbor split direction, and support-doc notes into target/support docs during supervisor callback.
- Recommended metadata: `COMPLETION:87`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`.
- Recommended formal C++:

```cpp
Encoder::~Encoder()
{
}
```

- Confidence: high for exact body, source-owner route, no-owned-resource destructor shape, and C++ readiness from local PE/Capstone verification plus current live-IDA-backed by-* docs. Confidence is capped below final audit because the live IDA MCP endpoint was unavailable in this B010 pass and exact original header/member spelling remains descriptive.

## Supporting Research

## Target
- Target UID: `00013E`.
- Target path: `source-3/project-documentation/by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00013E-EncoderDestructor-source-quality.md`.
- Current target state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004F`, blank formal C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists [UID:00013E] as `emits` through `00004F` to `auto-generated/NexusTK/util/Encoder.cpp`.
- Current generated output: `auto-generated/NexusTK/util/Encoder.cpp` contains only an empty emitter marker for [UID:00013E].
- Current coverage row: `by-memory/-coverage-report.md` marks [UID:00013E] as `reconstructable : 84% : strong`.

## Executive Recommendation
[UID:00013E] should remain source-bearing and should now receive first-draft C++. The exact body is seven bytes:

```asm
004a4ea0  mov dword ptr [ecx], 0x6192cc
004a4ea6  ret
```

That vtable write is compiler destructor mechanics. It does not imply handwritten source that manually assigns the vtable. There are no destructor callees, no delete/free call, and no writes to the shared buffer/capacity/cursor/byte-order/valid fields. The source-level behavior is therefore an empty `Encoder::~Encoder()` destructor. This is safe because all ownership-sensitive buffer state is managed elsewhere:

- `Encoder::Encoder()` initializes caller-buffer cursor fields and flags.
- `Encoder::Initialize()` attaches caller-owned storage.
- writer methods advance cursor and clear validity on overflow.
- `Encoder::Finalize()` appends the final NUL, optionally reports bytes written, detaches caller-owned storage, clears buffer/capacity/cursor, and restores valid state.
- `Encoder::~Encoder()` does not free or detach the buffer.
- `EncoderScalarDeletingDestructor` at `0x004a5e30-0x004a5e54` is the compiler deleting wrapper generated from the destructor/vtable shape; it should remain blank/no handwritten method body.

The target already clears the active final-code eligibility gate: it is reconstructable, has a nonblank emitter route that reaches `Encoder.cpp`, and its current average score is `(84 + 90) / 2 = 87.0`. After replacing stale gate text and adding the source-shape proof, `87/92` is justified.

## Supervisor Active Recheck
- This pass is report-only. No target/support by-* docs, generated files, IDA DB files, project-level reports, or `by-memory/-coverage-report.md` were edited.
- No split was performed. The destructor target is already exact and should stay `0x004a4ea0-0x004a4ea7`.
- The raw neighbor at `0x004a4eb0-0x004a4ebd` is not part of this destructor; local bytes show it is an exact setter-shaped body followed by three bytes of padding before [UID:00013F] `EncoderWriteByte`.
- Prior B013 report `Agent-B013/research/00013E-EncoderDestructor-source-quality.md` was treated as a lead only. B010 rechecked current docs, current coverage/generated state, and local executable bytes before making this recommendation.

## Inference Research Guidance Check
`by-structure.md` says final C++ eligibility now uses the active reconstructable + emitter route + combined-score gate, not the older `95/95` blocker. It also says C++ should reflect plausible original mid-2000s source rather than decompiler-shaped scaffolding. For this target, that means the formal source should be an empty destructor body, not a vtable assignment.

`inference_research.md` cautions that source ownership cannot be inferred from one clue such as adjacency. The accepted owner here is not adjacency-only: the method writes the Encoder vtable base, is listed under the Encoder class and file root, shares the BinaryCodec cursor layout, has its only ordinary consumer in the text-edit serializer's stack `Encoder` cleanup, and is paired with the Encoder scalar deleting destructor/vtable data.

Facts, documentation evidence, and inference are separated below:

- Direct local binary facts: exact bytes, disassembly, padding, local pointer/reference scans, and vtable dwords from the read-only executable.
- Current documentation facts: prior live IDA function/xref/callee facts recorded by current by-* docs.
- Inference: final source shape is empty `Encoder::~Encoder()`; raw neighbor is the Encoder-side `SetByteOrder` counterpart to [UID:0003K8] `DecoderSetByteOrder`; exact original member names remain descriptive rather than proven.

## Heuristic / Inference Reanalysis And Validation

### Exact body, boundary, and padding
- Best conclusion: [UID:00013E] is exactly `0x004a4ea0-0x004a4ea7`, size `0x7` / 7 bytes.
- Local PE/Capstone bytes: `c7 01 cc 92 61 00 c3`.
- Local disassembly:

```asm
004a4ea0  mov dword ptr [ecx], 0x6192cc
004a4ea6  ret
```

- Boundary evidence:
  - `0x004a4e94-0x004a4ea0`: twelve `0xcc` bytes after [UID:00013C] `EncoderConstructor`.
  - `0x004a4ea7-0x004a4eb0`: nine `0xcc` bytes after this destructor.
  - `0x004a4eb0` begins a separate setter-shaped body.
- Rejected alternatives:
  - Extend destructor to `0x004a4eb0`: rejected by nine `0xcc` bytes and distinct prologue at `0x004a4eb0`.
  - Merge with constructor: rejected by `0x004a4e94-0x004a4ea0` padding and separate IDA function object.
  - Treat as padding/compiler-only no-code: rejected because this is the ordinary source-level non-deleting destructor body for a NexusTK class, even though its only emitted machine effect is vtable restoration.

### Vtable restoration and source C++ shape
- Best conclusion: the vtable store is compiler output for the ordinary destructor; source should not manually store `0x006192cc`.
- Evidence checked:
  - Local destructor store to `[ecx] = 0x006192cc`.
  - Local pointer scan: `0x006192cc` is referenced by instructions in `Encoder::Encoder` at `0x004a4e72`, `Encoder::~Encoder` at `0x004a4ea2`, and `EncoderScalarDeletingDestructor` at `0x004a5e3c`.
  - [UID:0003IA] `EncoderVtableData` records the compact Encoder vtable data at `0x006192c8-0x006192d4`, including RTTI/COL pointer `0x00646b2c`, scalar deleting destructor slot `0x004a5e30`, and no-op virtual slot `0x004a5630`.
  - [UID:0001X1] `BinaryCodecVtables` records `0x006192cc` as the Encoder vtable base and the same constructor/destructor/scalar-destructor refs.
- Rejected alternatives:
  - Emit `*(void**)this = &off_6192CC;` in C++. Rejected as decompiler-shaped compiler mechanics.
  - Leave formal C++ blank because machine body only restores vtable. Rejected because the source-level destructor is still real and safe to express as empty once the compiler mechanics are documented.
- Final source recommendation: `Encoder::~Encoder() {}`.

### No-owned-buffer cleanup proof
- Best conclusion: `Encoder` does not own or free the attached buffer in its destructor.
- Evidence checked:
  - Local destructor has no callees and no field writes except the vtable pointer.
  - Current target page records `callees 0x004a4ea0` as empty.
  - [UID:0001TS] `BinaryCodecCursorLayout` identifies `+0x04` buffer pointer, `+0x08` capacity/limit, `+0x0c` cursor, `+0x10` byte-order flag, and `+0x11` valid/writable flag.
  - [UID:00013K] `EncoderFinalize` locally disassembles as the method that writes the trailing NUL, optionally reports `+0x0c`, clears `+0x04/+0x08/+0x0c`, and restores `+0x11` to `1`.
  - [UID:00004F] class page says `Encoder` is a caller-buffer binary writer and does not own the output buffer.
- Rejected alternatives:
  - Add `delete[] m_outputBuffer` or free helper call to C++. Rejected by exact destructor body and `Finalize` detach behavior.
  - Reset buffer/capacity/cursor in the destructor. Rejected by exact body; that reset belongs to `Finalize`.
  - Treat `m_isWritable`/`m_isValid` as cleanup state that destructor must restore. Rejected by exact body and `Finalize` handling.

### Text-edit cleanup caller and reachability
- Best conclusion: the destructor is live in stack cleanup for [UID:0000UM] / [UID:0001JN] TextEditPane serialization, but that consumer is not the owner.
- Evidence checked:
  - Existing target docs record one ordinary caller, `sub_58E490` at call site `0x0058e66c`.
  - Local disassembly near `0x0058e66c` shows `lea ecx, [ebp - 0x802c]` followed by `call 0x004a4ea0`, matching destruction of a stack `Encoder`.
  - Existing docs also mention an additional xref at `0x0060970c` attributed to the same function. Local rel32 scan and disassembly show a compiler cleanup stub at `0x00609706`: `lea ecx, [ebp - 0x802c]; jmp 0x004a4ea0`.
  - [UID:0001JN] `TextEditPaneSerialization` records the full stack Encoder call sequence: constructor, initialize, raw/scalar writes, finalize, allocation/copy, output size store, and destructor cleanup.
- Rejected alternatives:
  - Move the destructor to TextEditPane ownership because TextEditPane is the only ordinary caller. Rejected because caller/consumer is not owner; vtable and fields belong to Encoder.
  - Treat the cleanup stub as a second source caller. Rejected because it is compiler cleanup/unwind-style forwarding to the same stack-object destructor.
- Documentation impact: target should say "one ordinary source-level cleanup call plus one compiler cleanup/jump xref in the same serializer context."

### Scalar deleting destructor relationship
- Best conclusion: [UID:00013V] `0x004a5e30-0x004a5e54` is compiler deleting-destructor glue generated from the class destructor/vtable shape; it is not the source body for [UID:00013E].
- Local scalar wrapper disassembly:

```asm
004a5e30  push ebp
004a5e31  mov ebp, esp
004a5e33  test byte ptr [ebp + 8], 1
004a5e37  push esi
004a5e38  mov esi, ecx
004a5e3a  mov dword ptr [esi], 0x6192cc
004a5e40  je 0x4a5e4d
004a5e42  push 0x14
004a5e44  push esi
004a5e45  call 0x5c7526
004a5e4a  add esp, 8
004a5e4d  mov eax, esi
004a5e4f  pop esi
004a5e50  pop ebp
004a5e51  ret 4
```

- Relationship:
  - Ordinary destructor [UID:00013E] restores the vtable and returns.
  - Scalar wrapper [UID:00013V] restores the same vtable, tests delete flag bit `1`, optionally pushes size `0x14` / 20 and `this` into delete helper `0x005c7526`, and returns `this`.
  - Encoder vtable slot `0x006192cc` points to the scalar wrapper, not to the ordinary destructor.
- Rejected alternatives:
  - Put scalar-delete flag logic in `Encoder::~Encoder()` C++. Rejected because ordinary source destructor does not receive deleting flags and exact [UID:00013E] has no such body.
  - Emit [UID:00013V] as a handwritten `Encoder::ScalarDeletingDestructor` method. Rejected as compiler/vtable wrapper mechanics. [UID:00013V] should remain blank/no standalone handwritten source unless project policy chooses comment-only wrapper markers.
- Support-doc impact: [UID:00013V] should cross-reference [UID:00013E] as the source destructor and say final source should define the ordinary destructor and let the compiler generate scalar deleting glue.

### Raw neighbor at `0x004a4eb0`
- Best conclusion: `0x004a4eb0-0x004a4ebd` is a clean raw Encoder method body, likely `Encoder::SetByteOrder(unsigned char byteOrderFlag)`, and not part of [UID:00013E] or [UID:00013F].
- Local bytes: `55 8b ec 8a 45 08 88 41 10 5d c2 04 00`.
- Local disassembly:

```asm
004a4eb0  push ebp
004a4eb1  mov ebp, esp
004a4eb3  mov al, byte ptr [ebp + 8]
004a4eb6  mov byte ptr [ecx + 0x10], al
004a4eb9  pop ebp
004a4eba  ret 4
004a4ebd  int3
004a4ebe  int3
004a4ebf  int3
```

- Local rel32 scan found zero direct callers to `0x004a4eb0` in the read-only executable.
- Symmetry evidence: [UID:0003K8] `DecoderSetByteOrder` at `0x004a5680-0x004a568d` has the same instruction shape and working signature `void __thiscall Decoder::SetByteOrder(unsigned char byteOrderFlag)`.
- Best future split recommendation:
  - Create `by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md` if the supervisor assigns split implementation.
  - Direct owner/emitter should be [UID:00004F][Encoder] if created and if the parent remains above gate.
  - Formal C++ should likely be:

```cpp
void Encoder::SetByteOrder(unsigned char byteOrderFlag)
{
    m_useBigEndian = byteOrderFlag;
}
```

- Rejected alternatives:
  - Treat the raw block as destructor tail: rejected by nine `0xcc` bytes before it.
  - Treat it as `WriteByte`: rejected by its standalone prologue/ret and three bytes of padding before `WriteByte`.
  - Name it `SetLittleEndian`: rejected because nonzero `+0x10` means big-endian scalar writes in current layout docs.
  - Leave as meaningless raw bytes: rejected because Decoder has an exact symmetric `SetByteOrder` child with the same byte pattern.
- Impact on [UID:00013E]: it does not block empty destructor C++; it is only a support/split follow-up.

### Owner, file, and source-family routing
- Best route:
  - Direct semantic owner: [UID:00004F] `Encoder`.
  - Emitter route: [UID:00004F] to [UID:0000J1] `Encoder`, generated at `auto-generated/NexusTK/util/Encoder.cpp`.
  - Family coordinator: [UID:0000HQ] `BinaryCodec`.
- Evidence checked:
  - [UID:00004F] class page is `86/90`, lists the destructor and all modeled Encoder methods, and documents caller-buffer writer semantics.
  - [UID:0000J1] file page is `86/88`, validates `NexusTK/util/Encoder.cpp` as the concrete source root.
  - [UID:0000HQ] BinaryCodec is only the utility-family coordinator, not the direct owner of this exact class method.
  - [UID:0000UM]/[UID:0001JN] TextEditPane serialization is the only confirmed consumer, not the owner.
- Rejected alternatives:
  - `CANONICAL_OWNER:NONE`: rejected because class ownership and emitter routing are already strong and above gate.
  - [UID:0000HQ] `BinaryCodec` as direct owner: rejected because the destructor mutates an `Encoder` object and writes the Encoder vtable.
  - [UID:0000ON] `TextEditPane` as owner: rejected because it consumes a stack Encoder.
  - Packet/network/DAT ownership: rejected because no packet/socket/DAT caller or source route is documented.

### Final-C++ readiness
- Best conclusion: first-draft `Encoder::~Encoder()` C++ is safe now.
- Active gate:
  - `RECONSTRUCTABLE:TRUE`.
  - `EMITTER_UIDS:00004F`.
  - [UID:00004F] emits to [UID:0000J1], a valid generated source root.
  - Current average `(84 + 90) / 2 = 87.0`; recommended average `(87 + 92) / 2 = 89.5`.
- Source-shape proof:
  - Empty destructor is the only plausible source body because no owned cleanup exists and vtable restoration is compiler-generated.
  - This body does not depend on unresolved field names, raw helper splits, or exact `sizeof(Encoder)`.
  - Out-of-class method body is preferred for the by-memory generated output because sibling method pages emit out-of-class method bodies under `Encoder.cpp`.
- Rejected alternatives:
  - `Encoder::~Encoder() = default;`: rejected because C++11 syntax is not appropriate for mid-2000s source reconstruction and by-memory output expects a body.
  - Inline header-only destructor: possible historically, but not preferred for this generated by-memory method page. The final source can later move it if a class/header pass proves inline placement.
  - Leave blank pending other Encoder methods: rejected because this destructor has no dependency on unresolved writer helper names.

## Evidence Standards Used
- Direct local binary evidence:
  - PE section mapping and byte reads from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Capstone x86 disassembly for constructor, destructor, raw `0x004a4eb0` neighbor, `WriteByte`, `Finalize`, and scalar deleting destructor.
  - Pointer scans for `0x006192cc`, `0x004a5e30`, and `0x004a5630`.
  - rel32 scans for ordinary caller/cleanup routes to `0x004a4ea0` and absence of direct callers to `0x004a4eb0`.
- Numeric verification:
  - `tools/int_convert.py` verified `0x7` = 7, `0x9` = 9, `0xc` = 12, `0x14` = 20, `0x24` = 36, `0x31` = 49, `0x41` = 65, and `0x101` = 257.
- Documentation evidence:
  - Target [UID:00013E], class/file pages [UID:00004F]/[UID:0000J1]/[UID:0000HQ], layout [UID:0001TS], vtables [UID:0001X1]/[UID:0003IA], siblings [UID:00013C]/[UID:00013D]/[UID:00013F]/[UID:00013K]/[UID:00013V], direct caller pages [UID:0000UM]/[UID:0001JN], and [UID:0003K8] DecoderSetByteOrder symmetry.
- Tool limitation:
  - IDA MCP JSON-RPC `tools/list` to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. No IDA DB mutation or fresh live MCP query was performed.

## IDA / Local Binary Facts
- Function/range facts:
  - `0x004a4e70-0x004a4e94`: `Encoder::Encoder`, size `0x24` / 36; stores vtable, clears `+0x04/+0x08/+0x0c`, writes word `0x0101` at `+0x10`.
  - `0x004a4ea0-0x004a4ea7`: `Encoder::~Encoder`, size `0x7` / 7; stores vtable, returns.
  - `0x004a4eb0-0x004a4ebd`: raw setter-shaped body; stores argument byte to `+0x10`, returns `4`.
  - `0x004a4ec0-0x004a4ef1`: `Encoder::WriteByte`, size `0x31` / 49.
  - `0x004a55e0-0x004a5621`: `Encoder::Finalize`, size `0x41` / 65.
  - `0x004a5e30-0x004a5e54`: `EncoderScalarDeletingDestructor`, size `0x24` / 36.
- Padding facts:
  - `0x004a4e6b-0x004a4e70`: five `0xcc` bytes.
  - `0x004a4e94-0x004a4ea0`: twelve `0xcc` bytes.
  - `0x004a4ea7-0x004a4eb0`: nine `0xcc` bytes.
  - `0x004a4ebd-0x004a4ec0`: three `0xcc` bytes.
  - `0x004a4ef1-0x004a4f00`: fifteen `0xcc` bytes.
  - `0x004a5621-0x004a5630`: fifteen `0xcc` bytes.
  - `0x004a5e54-0x004a5e60`: twelve `0xcc` bytes.
- Vtable facts:
  - `0x006192c8`: Encoder RTTI/COL pointer `0x00646b2c`.
  - `0x006192cc`: Encoder vtable slot 0 `0x004a5e30`.
  - `0x006192d0`: Encoder no-op virtual slot `0x004a5630`.
  - `0x006192d4`: Decoder RTTI/COL pointer `0x00646b74`.
  - `0x006192d8`: Decoder scalar deleting destructor slot `0x004a5e00`.
  - `0x006192dc`: Decoder no-op virtual slot `0x004a5df0`.
  - `0x006192e0`: non-vtable DAT parser constant `0x0000001a`.
- Xref facts:
  - Local rel32 scan found ordinary call opcode at `0x0058e66c` to `0x004a4ea0`.
  - Local rel32 scan found compiler cleanup/jump opcode at `0x0060970c` to `0x004a4ea0`.
  - Local rel32 scan found no direct refs to `0x004a4eb0`.
  - Local pointer scan found `0x004a5e30` at `0x006192cc` and `0x004a5630` at `0x006192d0`.
  - Local pointer scan found `0x006192cc` encoded in instructions at `0x004a4e72`, `0x004a4ea2`, and `0x004a5e3c`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a4e70-0x004a4e94` | [UID:00013C] `EncoderConstructor` | Constructor | TRUE | [UID:00004F] | `84/90` | Source-bearing sibling, still stale below-95 C++ wording. |
| `0x004a4ea0-0x004a4ea7` | [UID:00013E] target | Non-deleting destructor | TRUE | [UID:00004F] | recommend `87/92` | Add empty destructor C++. |
| `0x004a4eb0-0x004a4ebd` | no exact page yet | likely `Encoder::SetByteOrder` | likely TRUE if split | likely [UID:00004F] | n/a | Raw helper-shaped neighbor, no direct xrefs, symmetrical with DecoderSetByteOrder. |
| `0x004a4ec0-0x004a4ef1` | [UID:00013F] `EncoderWriteByte` | Byte writer | TRUE | [UID:00004F] | `84/90` | Starts after three-byte pad from raw setter. |
| `0x004a55e0-0x004a5621` | [UID:00013K] `EncoderFinalize` | Finalize/detach | TRUE | [UID:00004F] | `84/90` | Owns detach/reset behavior; destructor does not. |
| `0x004a5e30-0x004a5e54` | [UID:00013V] `EncoderScalarDeletingDestructor` | Scalar deleting wrapper | TRUE currently, no formal C++ | [UID:00004F] | `85/91` | Compiler wrapper generated from class destructor/vtable shape. |
| `0x006192c8-0x006192d4` | [UID:0003IA] `EncoderVtableData` | Encoder RTTI/vtable data | TRUE | [UID:00004F] | `89/92` | Source-declared/generated-binary support. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0058e66c` | `call 0x004a4ea0` after `lea ecx, [ebp-0x802c]` | Ordinary text-edit serializer cleanup of stack Encoder. |
| `0x0060970c` | `jmp 0x004a4ea0` after `lea ecx, [ebp-0x802c]` | Compiler cleanup/forwarder route in same stack Encoder context. |
| `0x004a4e72` | instruction constant `0x006192cc` | Constructor installs Encoder vtable. |
| `0x004a4ea2` | instruction constant `0x006192cc` | Non-deleting destructor restores Encoder vtable. |
| `0x004a5e3c` | instruction constant `0x006192cc` | Scalar deleting destructor restores Encoder vtable. |
| `0x006192cc` | data pointer to `0x004a5e30` | Vtable slot targets scalar deleting destructor. |
| `0x006192d0` | data pointer to `0x004a5630` | Vtable slot targets Encoder no-op virtual. |

## Documentation Evidence And Status
- Existing docs that support this report:
  - [UID:00013E] already records exact `0x7` body, no callees, text-edit cleanup caller, no owned-buffer cleanup, and vtable-store refs.
  - [UID:00004F] class page documents Encoder as a caller-buffer writer with observed state through `+0x11`.
  - [UID:0000J1] file page validates `NexusTK/util/Encoder.cpp` as the concrete source root.
  - [UID:00013D] now correctly acts as non-emitting split/index and records the raw `0x004a4eb0` helper-shaped island.
  - [UID:00013K] documents `Finalize` as the detach/reset method.
  - [UID:00013V] documents scalar deleting wrapper behavior.
  - [UID:0003K8] gives the exact Decoder-side `SetByteOrder` counterpart.
- Existing docs that are stale or incomplete:
  - [UID:00013E] still says final C++ is blank because of the old `95/95` threshold.
  - [UID:00013E] still says [UID:00004F] was `82/88`; current class page is `86/90`.
  - [UID:00013E] should distinguish the ordinary call at `0x0058e66c` from the cleanup/jump xref at `0x0060970c`.
  - [UID:00013E] should replace raw names `sub_4A4EA0` / `off_6192CC` with source-quality names in prose while preserving raw names as aliases/evidence.
  - [UID:0000HQ] still mentions old `90/90+` code-entry wording; optional support cleanup should update it to active combined-score/emitter gate language when touched.

## Ranked Ownership Analysis

### 1. [UID:00004F] Encoder
- Evidence for: destructor writes Encoder vtable base, class page documents the full method surface, file route reaches `Encoder.cpp`, vtable data ties constructor/destructor/scalar wrapper together, and direct consumer constructs a stack Encoder.
- Evidence against: exact original member/method names are descriptive rather than debug-symbol proven.
- Decision: accepted. Keep `CANONICAL_OWNER:00004F` and `EMITTER_UIDS:00004F`.

### 2. [UID:0000J1] Encoder file
- Evidence for: concrete generated root `NexusTK/util/Encoder.cpp`.
- Evidence against: by-structure direct owner should be the class, not the file, for class methods.
- Decision: keep as file root through the class emitter chain, not direct owner.

### 3. [UID:0000HQ] BinaryCodec
- Evidence for: source-family coordinator for Encoder/Decoder, shared cursor layout/vtables.
- Evidence against: this exact method is not shared. It mutates an Encoder object and writes Encoder vtable data.
- Decision: reject as direct owner; retain as source-family context and support-doc cross-reference.

### 4. [UID:0000ON] TextEditPane / [UID:0000UM] serializer
- Evidence for: only confirmed ordinary behavioral caller.
- Evidence against: it consumes a stack Encoder; ownership of vtable, fields, methods, and source root remains with Encoder.
- Decision: reject as owner; retain as caller evidence.

### 5. Packet/network/DAT/Socket alternatives
- Evidence for: generic "encoder" naming could suggest packet or binary payload work.
- Evidence against: no packet/network/DAT caller is documented; BinaryCodec docs explicitly reject moving this utility into PacketBuffer, Socket, TextEditPane, or DATFile.
- Decision: reject.

## Negative Evidence Summary
- No destructor callee exists.
- No buffer delete/free/reset exists in [UID:00013E].
- No evidence supports writing vtable assignments in final C++.
- No evidence supports assigning [UID:00013E] to TextEditPane just because TextEditPane is the only ordinary caller.
- No evidence supports merging [UID:00013E] into the constructor, raw `0x004a4eb0` helper, `WriteByte`, scalar deleting destructor, or broad [UID:00013D] index.
- No direct caller was found for raw `0x004a4eb0`; the setter role is inferred from exact bytes and Decoder counterpart symmetry.
- No original source/header metadata proves exact field names or inline versus out-of-line destructor placement.

## Final Recommendation

### Exact target metadata recommendation
Use this header state for [UID:00013E]:

```text
*** UID:00013E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Encoder::~Encoder()
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Exact target body changes recommended
- Replace stale "below 95/95" wording with active gate analysis:
  - target is reconstructable;
  - owner/emitter route `00013E -> 00004F -> 0000J1` reaches `auto-generated/NexusTK/util/Encoder.cpp`;
  - current average score already clears the active gate;
  - source-shape review resolves the destructor body as empty.
- Add local byte/disassembly evidence for `0x004a4ea0-0x004a4ea7`.
- Add padding evidence before and after the destructor.
- Add source-shape note: vtable restoration is compiler output; formal C++ is `Encoder::~Encoder() {}`.
- Add no-owned-buffer proof and link it to `Finalize`.
- Add caller/reachability note: ordinary call at `0x0058e66c` and cleanup/jump xref at `0x0060970c`.
- Add scalar wrapper relationship with [UID:00013V].
- Add raw neighbor note for `0x004a4eb0-0x004a4ebd` as likely future `EncoderSetByteOrder`.
- Add rejected alternatives listed in this report.

### Support doc changes recommended
- [UID:00004F] `by-class/Encoder.md`:
  - Update destructor row to say [UID:00013E] now has first-draft empty destructor C++ and no owned-buffer cleanup.
  - Add/adjust note that scalar deleting wrapper [UID:00013V] remains generated/compiler wrapper support, not the source destructor body.
  - Optionally add raw `0x004a4eb0-0x004a4ebd` as likely `Encoder::SetByteOrder` future child symmetrical with [UID:0003K8].
- [UID:0000J1] `by-file/Encoder.md`:
  - Update proposed contents/status to say `Encoder.cpp` should emit the empty destructor from [UID:00013E].
  - Keep BinaryCodec as coordinator and TextEditPane as consumer only.
- [UID:00013D] `by-memory/0x004a4e70-0x004a5621.EncoderCore.md`:
  - Update the [UID:00013E] child row to mention first-draft empty destructor readiness.
  - Preserve raw helper island note for `0x004a4eb0-0x004a4ebd`, but strengthen the recommended name to `Encoder::SetByteOrder(unsigned char byteOrderFlag)` based on Decoder symmetry.
- [UID:00013V] `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md`:
  - Add relationship note: ordinary source destructor is [UID:00013E]; wrapper should remain formal-C++ blank/no standalone handwritten body.
- [UID:0000HQ] `by-file/BinaryCodec.md`:
  - Optional if touched: replace stale `90/90+` code-entry wording with active combined-score/emitter gate wording. This is not required for [UID:00013E] implementation.
- [UID:0001TS] `BinaryCodecCursorLayout` and [UID:0003IA] `EncoderVtableData`:
  - No required change. They already carry the needed layout/vtable evidence.

### Exact items left unchanged
- [UID:00013D] remains non-reconstructable split/index.
- [UID:00013V] remains formal-C++ blank because it is scalar deleting wrapper support.
- Raw `0x004a4eb0-0x004a4ebd` remains unsplit until a supervisor assigns split/implementation; this target report does not create that page.

## First-Draft C++ Recommendation
Populate [UID:00013E]'s formal C++ block with:

```cpp
Encoder::~Encoder()
{
}
```

Reasoning:

- The exact destructor body has no source-side work other than compiler vtable restoration.
- Buffer lifecycle does not belong in the destructor.
- C++ base/member cleanup for this class is empty from current evidence.
- The active emitter route is valid.
- This C++ is plausible mid-2000s out-of-class source and does not use C++11 `= default`.

Do not include:

```cpp
*(void **)this = &off_6192CC;
delete[] m_outputBuffer;
Finalize(...);
EncoderScalarDeletingDestructor(...);
```

All of those would be incorrect or compiler-shaped for the ordinary destructor.

## Score / Metadata Rationale
| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `84` | `87` | Exact bytes, padding, vtable restore, no-owned-buffer proof, caller/cleanup xrefs, raw neighbor boundary, scalar wrapper relation, source-shape proof, and first-draft C++ are resolved. |
| `CONFIDENCE` | `90` | `92` | Local PE/Capstone verification confirms prior live-IDA-backed docs. Capped below final-audit because live IDA MCP was unavailable and exact original header/member names remain descriptive. |
| `CANONICAL_OWNER` | `00004F` | `00004F` | Direct class owner is supported by vtable writes, class/file docs, and method family. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | This is the ordinary source-level class destructor body. |
| `EMITTER_UIDS` | `00004F` | `00004F` | Emitter chain reaches `NexusTK/util/Encoder.cpp`. |
| formal C++ | blank | empty destructor body | Blank reason was stale; source shape is safe. |

## IDA Rename / Type / Comment Recommendations
- `0x004a4ea0`: keep or apply source-quality name `Encoder_Destructor` in IDA; comment "source ordinary destructor `Encoder::~Encoder`; body only restores vtable; final C++ is empty; no buffer ownership cleanup."
- `0x004a4eb0`: if future split/IDA work is approved, create/name function `Encoder_SetByteOrder` or `Encoder::SetByteOrder`; signature `void __thiscall Encoder::SetByteOrder(unsigned char byteOrderFlag)`; comment "raw no-xref counterpart to DecoderSetByteOrder; stores argument byte to byte-order field `+0x10`."
- `0x004a5e30`: keep/name `Encoder_ScalarDeletingDestructor`; comment "compiler-generated deleting destructor wrapper generated from Encoder destructor/vtable shape; do not hand-write ordinary source body here."
- `0x006192cc`: comment/name as Encoder primary vtable base / `??_7Encoder@@6B@` if IDA naming policy permits; cross-link [UID:0003IA].
- `BinaryCodecCursorLayout` type recommendation: keep `+0x10` as descriptive `m_useBigEndian` / `byteOrderFlag` and `+0x11` as `m_isWritable` or `m_isValid`; do not claim exact original names.

## Exact Implementation Checklist For Callback
1. Lease before editing any by-* docs.
2. Update [UID:00013E] metadata to `87/92`, keeping owner/emitter/reconstructable unchanged.
3. Populate [UID:00013E] formal C++ with the empty destructor body.
4. Replace stale below-95 gate text with active gate/source-shape rationale.
5. Add the local binary evidence, no-owned-buffer proof, caller/cleanup route, scalar wrapper relationship, raw neighbor boundary, and rejected alternatives from this report.
6. Update support docs:
   - `by-class/Encoder.md`
   - `by-file/Encoder.md`
   - `by-memory/0x004a4e70-0x004a5621.EncoderCore.md`
   - `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md`
   - optional `by-file/BinaryCodec.md` only if touching stale code-gate wording.
7. Do not edit `by-memory/-coverage-report.md`; use the exact supervisor-owned replacement row below.
8. Run scoped validators from `source-3/project-documentation` for every edited file.
9. Report generated/project-level side effects, especially the generated `auto-generated/NexusTK/util/Encoder.cpp` replacement of [UID:00013E]'s empty marker with the destructor snippet.

## Expected Validation Commands
No validators were run in this report-only pass because no by-* docs were edited. Expected implementation commands:

> Executable block R001 was removed from this report and preserved verbatim in [00013E-EncoderDestructor-source-quality-removed.md](00013E-EncoderDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run this only if [UID:0000HQ] `BinaryCodec` is edited:

> Executable block R002 was removed from this report and preserved verbatim in [00013E-EncoderDestructor-source-quality-removed.md](00013E-EncoderDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If autogen refresh is requested by the supervisor/validator workflow after C++ insertion:

> Executable block R003 was removed from this report and preserved verbatim in [00013E-EncoderDestructor-source-quality-removed.md](00013E-EncoderDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Pending Coverage Text
Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly. Supervisor-owned replacement:

Replace current row:

```text
    - [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) 0x004a4ea0-0x004a4ea7 | method | EncoderDestructor : reconstructable : 84% : strong : Non-deleting Encoder destructor; live IDA confirms exact vtable-restore body, no callees, text-edit encoder cleanup caller, no owned-buffer cleanup, and padding before the raw non-modeled helper/WriteByte.
```

With:

```text
    - [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) 0x004a4ea0-0x004a4ea7 | method | EncoderDestructor : reconstructable : 87% : strong : B010 source-quality pass resolves this as source-bearing non-deleting `Encoder::~Encoder()` with first-draft C++ `Encoder::~Encoder() {}` under owner/emitter [UID:00004F][Encoder](by-class/Encoder.md) to [UID:0000J1][Encoder](by-file/Encoder.md). Local PE/Capstone verification plus existing live-IDA-backed docs confirm exact seven-byte body `mov [ecx], 0x006192cc; ret`, twelve-byte prepad at `0x004a4e94-0x004a4ea0`, nine-byte postpad at `0x004a4ea7-0x004a4eb0`, no callees or owned-buffer cleanup, ordinary text-edit serializer cleanup call at `0x0058e66c`, compiler cleanup/jump xref at `0x0060970c`, vtable-base refs shared with constructor `0x004a4e70` and scalar deleting destructor `0x004a5e3a`, scalar wrapper [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) as generated delete-flag glue, and raw neighbor `0x004a4eb0-0x004a4ebd` as likely future `Encoder::SetByteOrder` rather than destructor tail.
```

No exact coverage insertion is provided for the raw `0x004a4eb0-0x004a4ebd` helper because it does not yet have a UID. If a future split creates `EncoderSetByteOrder`, the validator/supervisor should allocate the UID and add a new row at that time.

Generated `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `auto-generated/NexusTK/util/Encoder.cpp` should change only through validator/autogen refresh after by-* implementation, not by manual edit during this report pass.

## Follow-Up Actions
- Supervisor: review and, if accepted, send B010 a detailed implementation callback for the target/support docs and C++ insertion. Apply the supervisor-owned coverage row only after implementation verification.
- B010 on callback: lease target/support docs, apply metadata/prose/C++ changes, validate scoped files, report validator exit codes and generated side effects, and keep `by-memory/-coverage-report.md` untouched.
- Future B work: split/research `0x004a4eb0-0x004a4ebd.EncoderSetByteOrder` and later raw Encoder helper islands inside [UID:00013D].

## Changed Files
- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00013E-EncoderDestructor-source-quality.md`.
- Modified: none outside Agent-B010 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00013E-EncoderDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00013E"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013E-EncoderDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00013E-EncoderDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
