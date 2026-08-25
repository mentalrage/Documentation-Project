** TARGET-REPORT-UID:00013P **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013P DecoderPrimitiveReaders Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00013P] `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md` as a non-emitting split index, not as reconstructable source code.
- Final disposition: source page metadata should remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++ for the index itself. The exact children [UID:0003K8]-[UID:0003KC] are the reconstructable source methods and should continue to route to [UID:00003M] `Decoder`.
- Required action after supervisor acceptance: update stale target/support prose that still says `AUTOGEN_PARENT_UID` or below-`95/95` code gate; add current live MCP evidence; add first-draft C++ to the five exact primitive child pages under the active combined-score/emitter gate; refresh stale generated reports through validators; and have the supervisor update the manual `by-memory/-coverage-report.md` target row if manual coverage is still maintained.
- Confidence: high for the split/index disposition and exact child boundaries; medium-high for final source names because the raw starts still have no IDA function objects, no incoming xrefs, and no original symbols.

## Target

- Assignment id: `B004-report-00013P-decoder-primitive-readers-20260625`.
- Target UID: [UID:00013P].
- Target path: `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`.
- Required report path: `tools/leaser/Agents/Agent-B004/research/00013P-DecoderPrimitiveReaders-source-quality.md`.
- Source queue row: `auto-generated/-ag-research-tracker.md` still lists the target in `## by-memory` / `### Not-Covered Files - Reconstructable` as `74/84`, reconstructable `true`.
- Current source-page metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++ block, `Nested:0`.
- Current source-page role: non-emitting split index over five exact primitive reader children.

## Current Target State

The source page itself is ahead of the generated reports. It already records the A002 split repair: the old broad primitive-reader range became a reviewed, non-reconstructable index, and the exact methods were split into:

| Range | UID | Current role | Current route |
| --- | --- | --- | --- |
| `0x004a5680-0x004a568d` | [UID:0003K8] | `Decoder::SetByteOrder` raw method body | `CANONICAL_OWNER:00003M`, `EMITTER_UIDS:00003M` |
| `0x004a5690-0x004a56b8` | [UID:0003K9] | `Decoder::ReadByte` raw method body | `CANONICAL_OWNER:00003M`, `EMITTER_UIDS:00003M` |
| `0x004a56c0-0x004a570f` | [UID:0003KA] | `Decoder::ReadShort` raw method body | `CANONICAL_OWNER:00003M`, `EMITTER_UIDS:00003M` |
| `0x004a5710-0x004a576f` | [UID:0003KB] | `Decoder::ReadTriByte` raw method body | `CANONICAL_OWNER:00003M`, `EMITTER_UIDS:00003M` |
| `0x004a5770-0x004a57dc` | [UID:0003KC] | `Decoder::ReadInt` raw method body | `CANONICAL_OWNER:00003M`, `EMITTER_UIDS:00003M` |

Open or stale points found in the current docs:

- The target page still says the child C++ is blank because the children are below the old `95/95` final-code gate. That gate is stale under current `by-structure.md`; the active minimum is `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- The target page still says blank `AUTOGEN_PARENT_UID`. Current terminology is `CANONICAL_OWNER` and `EMITTER_UIDS`.
- The five child pages still say `AUTOGEN_PARENT_UID` in prose, despite using current metadata headers.
- The child pages have blank `Item Summary` values. [UID:0003K8] also has `Nested:8` even though it is an exact leaf method; it should be `Nested:0`.
- The manual `by-memory/-coverage-report.md`, generated `auto-generated/-ag-research-tracker.md`, generated `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md` still show old `74/84` reconstructable target state for [UID:00013P]. `auto-generated/-ag-memory-coverage.md` already shows [UID:00013P] as `not_reconstructable`, so generated state is internally inconsistent.

## Evidence Checked

Local docs and generated context checked:

- `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`.
- Exact child pages [UID:0003K8], [UID:0003K9], [UID:0003KA], [UID:0003KB], and [UID:0003KC].
- Support docs [UID:00003M] `by-class/Decoder.md`, [UID:0000IQ] `by-file/Decoder.md`, [UID:0000HQ] `by-file/BinaryCodec.md`, [UID:0001TS] `by-type/by-struct/BinaryCodecCursorLayout.md`, [UID:0001X1] `by-type/by-vtable/BinaryCodecVtables.md`, and [UID:00013Q] `by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md`.
- `by-project-structure/proposed-source-tree.md` lines for `util/BinaryCodec.cpp`, `util/Encoder.cpp`, and `util/Decoder.cpp`.
- Generated context: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Manual coverage context: `by-memory/-coverage-report.md` row 1238.
- Prior report search: no direct executed B report for [UID:00013P] was found. `executed-b-agent-research/B010/00013E-EncoderDestructor-source-quality.md` was checked as an Encoder-side symmetry lead for `DecoderSetByteOrder`. A002 notes and Supervisor notes were checked as non-B historical split-repair leads and revalidated against current docs/MCP rather than treated as final proof.
- Stale Wave2/Wave3/generator material encountered: `simroot_v2/class_Decoder.cpp` and generated low-score rows were treated as lead/stale context only, not authority.

Live IDA MCP evidence checked:

- Endpoint/tool schema: `initialize`, `tools/list`, and active tool schemas checked on 2026-06-25.
- Active session: `idb_list` returned session `80de0a67`, worker PID `26892`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status `ok`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready.
- Correction pass after supervisor rejection: `initialize`, `tools/list`, `idb_list`, and `server_health` still responded on 2026-06-25; session `80de0a67` remained active with worker PID `26892`, `server_health` status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.
- `lookup_funcs` for the primitive starts and nearby modeled functions.
- `entity_query` for functions in `0x004a5600-0x004a5e60`.
- `xrefs_to` and `xref_query` for the primitive starts and successor `0x004a57e0`.
- `insn_query 0x004a5680-0x004a57e0`.
- `get_bytes` for all internal/adjacent padding spans and the whole primitive block through the following alignment.
- `decompile 0x004a5680`, `decompile 0x004a5640`, `decompile 0x004a5dd0`, and disassembly for the modeled constructor/finalize methods.
- `find_bytes` for little-endian dword VA and RVA pointer patterns to `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, and `0x004a57e0`.

No validators were run and no leases were taken during this report-only pass.

## IDA MCP Facts

Live session `80de0a67` confirms the current split premise.

Modeled nearby functions:

- `0x004a5630`: `nullsub_27`, size `0x1`.
- `0x004a5640`: `sub_4A5640`, size `0x24`; decompilation stores `Decoder::vftable`, clears `+0x04/+0x08/+0x0c`, and writes word `0x0101` at `+0x10`.
- `0x004a5670`: `sub_4A5670`, size `0x7`.
- `0x004a5dd0`: `sub_4A5DD0`, size `0x1d`; decompilation reads `+0x11`, clears `+0x04/+0x08/+0x0c`, restores `+0x11` to `1`, and returns the saved byte.
- `0x004a5df0`: `nullsub_28`, size `0x1`.
- `0x004a5e00`: `sub_4A5E00`, size `0x24`.
- `0x004a5e30`: `sub_4A5E30`, size `0x24`.
- `entity_query` shows the next modeled function after this local codec/glue window is `0x004a5e60`.

Raw primitive starts:

- `lookup_funcs` reports `Not a function` for `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, and successor `0x004a57e0`.
- `xrefs_to` reports zero direct code/data xrefs for all six addresses.
- `xref_query` reports only local outgoing flow/branch records from each raw start with `fn:null`; it does not report an incoming caller, data pointer, vtable, or table route.
- `decompile 0x004a5680` fails, consistent with no IDA function object at the raw start.
- `find_bytes` found zero little-endian dword pointer matches for all six raw start VAs and RVAs, so there is no obvious raw pointer table route in the current IDB image.
- Correction-pass `xrefs_to` and `xref_query direction=to` again report zero incoming refs for `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, and `0x004a57e0`; `xref_query direction=from` reports only one local outgoing code-flow record per raw start, all with `fn:null`.
- Correction-pass `find_bytes` found zero little-endian dword pointer matches for all six raw start VAs (`80 56 4A 00`, `90 56 4A 00`, `C0 56 4A 00`, `10 57 4A 00`, `70 57 4A 00`, `E0 57 4A 00`) and RVAs (`80 56 0A 00`, `90 56 0A 00`, `C0 56 0A 00`, `10 57 0A 00`, `70 57 0A 00`, `E0 57 0A 00`).
- Correction-pass vtable/table route recheck found no primitive-start slot or adjacent table route: `xrefs_to 0x006192d8` reports only Decoder vtable stores from `0x004a5640`, `0x004a5670`, and `0x004a5e0a`; `xrefs_to 0x004a5df0` reports only the no-op vtable slot at `0x006192dc`; `xrefs_to 0x004a5e00` reports only the scalar deleting destructor slot at `0x006192d8`; and `xrefs_to 0x006192e0` reports only adjacent table use from `0x004a5e9e` in `sub_4A5E60`.
- Correction-pass `entity_query functions 0x004a5600-0x004a5e80` returns only modeled functions `0x004a5630`, `0x004a5640`, `0x004a5670`, `0x004a5dd0`, `0x004a5df0`, `0x004a5e00`, `0x004a5e30`, and `0x004a5e60`; it does not expose a function object at any primitive start.

Raw instruction/range facts:

- `insn_query 0x004a5680-0x004a57e0` returns `count:154`, `truncated:false`, and `fn:null` for the primitive instructions and alignment directives.
- `0x004a5680-0x004a568d` stores `[ebp+8]` into `[ecx+0x10]` and returns with `retn 4`.
- `0x004a5690-0x004a56b8` checks `[ecx+0x11]`, validates `cursor + 1 <= limit`, clears `[ecx+0x11]` on underflow, reads one byte from `[buffer + cursor]`, updates `[ecx+0x0c]`, and returns in `al`.
- `0x004a56c0-0x004a570f` checks `[esi+0x11]`, validates `cursor + 2 <= limit`, clears `[esi+0x11]` on underflow, then either assembles high-byte-first when `[esi+0x10]` is nonzero or performs a native word read when it is zero.
- `0x004a5710-0x004a576f` checks `[esi+0x11]`, validates `cursor + 3 <= limit`, clears `[esi+0x11]` on underflow, reads three bytes with cursor updates after each byte, and assembles a 24-bit value in selected byte order.
- `0x004a5770-0x004a57dc` checks `[esi+0x11]`, validates `cursor + 4 <= limit`, clears `[esi+0x11]` on underflow, reads four bytes with cursor updates after each byte for the high-byte-first path, or performs a native dword read and updates cursor to `cursor + 4` for the little-endian path.

Padding/byte facts:

- `get_bytes 0x004a5677 size 9`: nine `0xcc` bytes before the primitive block.
- `get_bytes 0x004a568d size 3`: three `0xcc` bytes between `SetByteOrder` and `ReadByte`.
- `get_bytes 0x004a56b8 size 8`: eight `0xcc` bytes between `ReadByte` and `ReadShort`.
- `get_bytes 0x004a570f size 1`: one `0xcc` byte between `ReadShort` and `ReadTriByte`.
- `get_bytes 0x004a576f size 1`: one `0xcc` byte between `ReadTriByte` and `ReadInt`.
- `get_bytes 0x004a57dc size 4`: four `0xcc` bytes before successor raw reader start `0x004a57e0`.
- `get_bytes 0x004a5680 size 352` confirms the contiguous primitive bodies and alignment bytes through `0x004a57df`.

## Heuristic / Inference Reanalysis And Validation

Compiler/generated names:

- The raw starts have no IDA functions, so there are no live IDA names to preserve. Final source should not use `sub_4A5680`-style names.
- Existing doc names `DecoderSetByteOrder`, `DecoderReadByte`, `DecoderReadShort`, `DecoderReadTriByte`, and `DecoderReadInt` are source-facing descriptive names. They are not original-proof names, but they are the best current names from behavior, Encoder/Decoder symmetry, and the BinaryCodec utility family.
- Rejected alternatives: `func_`, `sub_`, `byte reader helper`, or one broad `DecoderPrimitiveReaders` source function. Those names either preserve tool labels or wrongly merge five separate callable bodies.

Raw helper role and liveness:

- The bodies are real source-shaped `thiscall` methods over the Decoder cursor layout, not padding, vtable data, or compiler helper code.
- Current direct-entry route is exhausted negative in the active IDB: live IDA has no function objects, no incoming xrefs, no VA/RVA pointer matches, no primitive-start vtable slot, and no candidate table route. That blocks final-audit confidence and exact caller documentation, but it does not make the bytes non-source or justify leaving exact child C++ blank under the current code gate.
- Rejected alternatives: ignored/dead-code classification and runtime/library classification. The bodies sit between modeled Decoder destructor/finalize code, use the exact Decoder fields, and mirror Encoder scalar writer behavior.

Field/type naming:

- Use Decoder-side names aligned with [UID:0001TS]: `m_inputBuffer`, `m_inputSize`, `m_readPos`, `m_useBigEndian`, and `m_isValid`.
- For exact binary comparison shape, `m_inputSize` and `m_readPos` should be treated as signed-int-shaped cursor/limit fields in method C++ where the binary uses signed `jge` comparisons. The public `Initialize` size parameter can remain `unsigned int` in support prose, but the field comparison semantics should be documented before final header emission.
- `m_useBigEndian` should be byte-like, not normalized through `bool`, because `SetByteOrder` stores the caller byte exactly. Reader behavior only tests nonzero, but exact memory state is better preserved by assigning the byte value.
- Rejected alternatives: raw offsets as final member names, generic `m_buffer` without input/output distinction, or forcing `bool` assignment for the byte-order setter.

Source placement:

- Exact children belong under [UID:00003M] `Decoder`, emitted through [UID:0000IQ] `Decoder.cpp` in `NexusTK/util/`.
- [UID:0000HQ] `BinaryCodec` remains a family coordinator, not the direct owner of these exact methods.
- TextEditPane, PacketBuffer, DATFile, and parser/DAT neighbors remain rejected. There is no caller or data-flow route from those subsystems to the raw Decoder primitive starts.

Split/range:

- No new split is needed for [UID:00013P]. Live MCP reconfirms the five exact children and all internal/following alignment bytes.
- The target page should stay a split index; exact child pages carry the reconstructable code and ownership.

C++ readiness:

- [UID:00013P] itself is not eligible for C++ because it is `RECONSTRUCTABLE:FALSE`, has no emitter, and overlaps child ranges.
- The exact child pages are eligible for first-draft C++ under the active gate: each is `RECONSTRUCTABLE:TRUE`, has `EMITTER_UIDS:00003M`, routes through [UID:00003M] to [UID:0000IQ], and has a combined score above `85`.
- The exhausted no-direct-entry result should remain documented as a final-audit confidence cap, not as a blanket no-code proof for the exact children.

## Positive Evidence Summary

- Direct live IDA MCP confirms the parent page is not one source-level function: every primitive start is still `Not a function`, while adjacent Decoder lifecycle functions are modeled normally.
- Direct live IDA MCP confirms the exact child bodies, field offsets, byte-order behavior, underflow invalidation, cursor updates, and padding.
- Current [UID:00003M], [UID:0000IQ], [UID:0000HQ], and [UID:0001TS] docs consistently place these methods in the Decoder/BinaryCodec utility family.
- The exact children already have current owner/emitter metadata that surfaces to a valid file root.
- The current source page header already has the correct non-emitting index metadata. The stale state is in prose and generated/manual coverage views, not in the target metadata header.

## Negative Evidence Summary

- No incoming code/data xrefs exist for `0x004a5680`, `0x004a5690`, `0x004a56c0`, `0x004a5710`, `0x004a5770`, or successor `0x004a57e0` in live IDA.
- No little-endian dword pointer patterns to those raw starts were found by MCP `find_bytes`.
- `decompile 0x004a5680` fails because IDA does not model the raw start as a function.
- No vtable slot, RTTI, import, string, resource, or table evidence points at [UID:00013P] as a standalone source object.
- The generated research tracker and generated by-memory coverage row still reflect old `74/84` reconstructable state, contradicting the current source header and `auto-generated/-ag-memory-coverage.md`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:00013P] is a non-emitting split index, not source code. | Confirmed | Source header `RECONSTRUCTABLE:FALSE`, exact child split, live `lookup_funcs` no single function, padding between child bodies. | Considered assigning owner/emitter to Decoder; rejected because that would make the overlapping index look source-bearing. | None material for target disposition. |
| The five exact children are `Decoder` member methods. | Strong | Shared `ecx`/`this` field access, adjacent Decoder constructor/destructor/finalize, [UID:00003M] method inventory, [UID:0001TS] layout, live instruction bodies. | Checked raw starts for callers, xrefs, VA/RVA pointer routes, vtable slots, adjacent table routes, sibling/parent raw-family routes, and non-Decoder owners; no direct-entry or non-Decoder evidence found. | No direct-entry route exists in the current IDB; this is a final-audit confidence cap, not a current-scope blocker. |
| `Decoder.cpp` under `NexusTK/util/` is the best source route. | Strong | [UID:0000IQ] source root, [UID:0000HQ] utility family, [UID:00003M] class route, proposed source tree. | Rejected BinaryCodec direct ownership, TextEditPane, PacketBuffer, DATFile, and adjacent parser ownership. | Current route is accepted; exact historical folded-vs-separate codec packaging is only a final-audit caveat. |
| Child C++ is now supportable under current rules. | Medium-high | Active gate is met; exact behavior has live MCP verification; field names are supported by layout and Encoder-side accepted style. | Missing function objects and callers checked; they cap confidence but do not contradict behavior or owner. | Source-facing names and field types are accepted for first-draft C++; original symbol/header proof remains a final-audit caveat. |

## Ranked Ownership Analysis

### 1. Keep [UID:00013P] ownerless and non-emitting; exact children owned by [UID:00003M]

- Evidence for: [UID:00013P] overlaps five exact child method pages plus padding. Current by-structure rules keep overlapping index/container pages non-reconstructable when children carry the real source. Current source header already reflects this.
- Evidence against: the whole range is semantically within Decoder. A non-reconstructable container could technically use `CANONICAL_OWNER:00003M`, but doing so adds no source-route value and may imply the index itself is a class method.
- Decision: keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS` on [UID:00013P]. Keep exact child owner/emitter route to [UID:00003M].

### 2. Assign [UID:00013P] directly to [UID:00003M]

- Evidence for: all child bodies use Decoder fields and sit between Decoder lifecycle methods.
- Evidence against: the target is not a source-level method or declaration. Direct class ownership on the index would duplicate the child ownership and risks overlapping generated output.
- Decision: rejected for [UID:00013P], accepted only for exact children.

### 3. Assign [UID:00013P] to [UID:0000HQ] BinaryCodec or [UID:0000IQ] Decoder file

- Evidence for: `BinaryCodec` and `Decoder.cpp` are the source family/file context.
- Evidence against: file/coordinator ownership is broader than the direct semantic owner of exact methods, and the target index is not code-bearing.
- Decision: rejected for the index. [UID:0000IQ] remains the file root reached through [UID:00003M].

### 4. Ignore or mark as runtime/compiler-generated

- Evidence for: no direct xrefs and no IDA function objects.
- Evidence against: instruction bodies are compact source-shaped member methods, use Decoder cursor fields, mirror Encoder writers, and live between modeled Decoder methods.
- Decision: rejected.

## Source Placement

Recommended source placement after accepted implementation:

- Parent/index [UID:00013P]: no source placement or emitter.
- Exact children [UID:0003K8]-[UID:0003KC]: [UID:00003M] `Decoder` class, emitted through [UID:0000IQ] `NexusTK/util/Decoder.cpp`.
- [UID:0000HQ] `BinaryCodec`: family coordinator only.
- [UID:0001TS] layout: shared layout support; update type notes only if the implementation callback chooses to record signed cursor/limit comparison semantics and byte-like `m_useBigEndian`.

Rejected placements:

- `BinaryCodec.cpp` direct emission: too broad for exact method bodies.
- `TextEditPane`, `PacketBuffer`, `DATFile`, or parser helpers: no caller/xref/source-family evidence.
- New standalone file: unnecessary because [UID:0000IQ] already exists and clears the source-root route.

## Range / Split / Padding / Reclassification Analysis

No additional split is required. Live MCP reconfirms the existing split:

| Span | Disposition |
| --- | --- |
| `0x004a5677-0x004a5680` | `0xcc` alignment after Decoder destructor |
| `0x004a5680-0x004a568d` | exact [UID:0003K8] method |
| `0x004a568d-0x004a5690` | `0xcc` alignment |
| `0x004a5690-0x004a56b8` | exact [UID:0003K9] method |
| `0x004a56b8-0x004a56c0` | `0xcc` alignment |
| `0x004a56c0-0x004a570f` | exact [UID:0003KA] method |
| `0x004a570f-0x004a5710` | `0xcc` alignment |
| `0x004a5710-0x004a576f` | exact [UID:0003KB] method |
| `0x004a576f-0x004a5770` | `0xcc` alignment |
| `0x004a5770-0x004a57dc` | exact [UID:0003KC] method |
| `0x004a57dc-0x004a57e0` | `0xcc` alignment before successor raw string/blob reader |

The implementation should not merge children back into [UID:00013P] and should not add C++ to the index page.

## First-Draft C++ Recommendation

### Target [UID:00013P] no-code proof

[UID:00013P] must keep an empty formal `RECONSTRUCTION_CPP CODE` block. It is `RECONSTRUCTABLE:FALSE`, has blank `EMITTER_UIDS`, and exists only to index overlapping exact child ranges and padding. Any C++ placed on [UID:00013P] would duplicate child source bodies and violate the by-memory rule that C++ content must represent the page's own source item rather than sibling/child ranges.

### Exact child C++ insertion text

If the supervisor accepts this report, replace the blank formal C++ blocks in the five exact child pages with the following exact content. These drafts intentionally use the same mid-2000s primitive spelling and member-name style as the accepted Encoder writer pages. They assume `m_inputSize` and `m_readPos` are signed-int-shaped cursor/limit fields and `m_useBigEndian` is byte-like so `SetByteOrder` preserves the caller byte.

[UID:0003K8] `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md`:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Decoder::SetByteOrder(unsigned char byteOrderFlag)
{
    m_useBigEndian = byteOrderFlag;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0003K9] `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md`:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned char Decoder::ReadByte()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    unsigned char value = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    return value;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0003KA] `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md`:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short Decoder::ReadShort()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        m_readPos = nextReadPos;
        return (unsigned short)(((unsigned short)high << 8) | low);
    }

    m_readPos = nextReadPos;
    return *(const unsigned short *)src;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0003KB] `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md`:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned int Decoder::ReadTriByte()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 3;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    unsigned int b0 = *src++;
    m_readPos = ++readPos;
    unsigned int b1 = *src++;
    m_readPos = ++readPos;
    unsigned int b2 = *src;
    m_readPos = nextReadPos;

    if (m_useBigEndian)
        return (b0 << 16) | (b1 << 8) | b2;

    return b0 | (b1 << 8) | (b2 << 16);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

[UID:0003KC] `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md`:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned int Decoder::ReadInt()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 4;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    if (m_useBigEndian)
    {
        unsigned int b0 = *src++;
        m_readPos = ++readPos;
        unsigned int b1 = *src++;
        m_readPos = ++readPos;
        unsigned int b2 = *src++;
        m_readPos = ++readPos;
        unsigned int b3 = *src;
        m_readPos = nextReadPos;
        return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
    }

    m_readPos = nextReadPos;
    return *(const unsigned int *)src;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason this preserves behavior:

- The valid flag is tested before any cursor/buffer mutation.
- Underflow clears `m_isValid` and returns zero without partial reads.
- Successful multi-byte high-byte-first paths update `m_readPos` after each byte, matching the raw bodies' repeated stores.
- Native little-endian branches use direct word/dword loads and one final cursor update, matching the observed x86 source shape.
- No allocation, exception logic, null-buffer guard, clamping, or caller status return is invented.

Reason this fits likely original source shape:

- It mirrors accepted Encoder writer method style and primitive types.
- It uses class members instead of raw offsets.
- It keeps `ReadTriByte` as a descriptive counterpart to the documented 24-bit reader, while recording that exact original spelling remains unproved.

## Recommended Target Doc Changes

Target path: `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`.

Apply these changes after supervisor validation:

- Preserve metadata as non-emitting index: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Recommended score after update: `COMPLETION:91`, `CONFIDENCE:93`.
- Update `Live IDA Evidence` with the 2026-06-25 session `80de0a67` facts from this report: health/session, `lookup_funcs`, `xrefs_to`, `xref_query`, `insn_query`, `get_bytes`, raw `decompile` failure, and no dword pointer patterns.
- Replace stale "blank AUTOGEN_PARENT_UID" language with current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology.
- Replace stale "child C++ blank because below 95/95 gate" language. The target index C++ remains blank, but the exact children now qualify for first-draft C++ under the active combined-score/emitter gate if the supervisor accepts the child support updates.
- Preserve negative evidence: no IDA function objects, no direct incoming xrefs, no raw VA pointer-table route, and no proven original method spellings.
- Preserve positive evidence: exact child split, padding boundaries, shared Decoder cursor layout, source-file route through [UID:00003M] and [UID:0000IQ].

## Recommended Support Doc Changes

Child pages [UID:0003K8]-[UID:0003KC]:

- Replace stale `AUTOGEN_PARENT_UID` prose with "canonical owner and emitter are [UID:00003M] Decoder; the emitter chain reaches [UID:0000IQ] Decoder.cpp."
- Replace stale blank-C++ rationale with active-gate rationale and insert the formal C++ blocks listed above.
- Add concise `Item Summary` text for each child. Suggested summaries:
  - [UID:0003K8]: `Decoder byte-order setter; live IDA confirms raw non-function body, exact byte store to +0x10, no incoming xrefs, padding boundaries, and Decoder owner/emitter route.`
  - [UID:0003K9]: `Decoder byte reader; live IDA confirms raw non-function body, valid/limit checks, one-byte cursor advance, underflow invalidation, no incoming xrefs, and Decoder owner/emitter route.`
  - [UID:0003KA]: `Decoder 16-bit reader; live IDA confirms raw non-function body, valid/limit checks, selected byte-order assembly/native read paths, no incoming xrefs, and Decoder owner/emitter route.`
  - [UID:0003KB]: `Decoder 24-bit reader; live IDA confirms raw non-function body, valid/limit checks, selected byte-order assembly, per-byte cursor updates, no incoming xrefs, and Decoder owner/emitter route.`
  - [UID:0003KC]: `Decoder 32-bit reader; live IDA confirms raw non-function body, valid/limit checks, selected byte-order assembly/native dword read paths, no incoming xrefs, and Decoder owner/emitter route.`
- Set [UID:0003K8] `Nested:0` unless a later validator-specific reason proves the current `Nested:8` is intentional.
- Recommended child scores after accepted C++ and live evidence update:
  - [UID:0003K8] `87/91 -> 89/92`.
  - [UID:0003K9] `87/91 -> 89/92`.
  - [UID:0003KA] `86/90 -> 88/91`.
  - [UID:0003KB] `86/90 -> 88/91`.
  - [UID:0003KC] `86/90 -> 88/91`.

[UID:00003M] `by-class/Decoder.md`:

- Add the primitive reader declarations to the declaration direction:
  - `void SetByteOrder(unsigned char byteOrderFlag);`
  - `unsigned char ReadByte();`
  - `unsigned short ReadShort();`
  - `unsigned int ReadTriByte();`
  - `unsigned int ReadInt();`
- Record that the names are descriptive/source-facing and not original-symbol proof.
- Record that `m_useBigEndian` should be byte-like because `SetByteOrder` stores the caller byte exactly.
- Record that `m_inputSize` / `m_readPos` are signed-compare-shaped in reader bounds checks.

[UID:0000IQ] `by-file/Decoder.md`:

- Update the primitive reader split row to say the exact children now carry first-draft method C++ when accepted; the broad index remains non-emitting.
- Keep final source placement as `NexusTK/util/Decoder.cpp`; do not fold into `BinaryCodec.cpp` without stronger original source evidence.

[UID:0001TS] `by-type/by-struct/BinaryCodecCursorLayout.md`:

- If the class/page update touches field types, add a note that Decoder reader bounds checks use signed `jge` compare shape for input size/read position and that the byte-order field should not be normalized through a boolean setter.
- Treat final `sizeof` and exact original field spellings as broader layout final-audit caveats; they do not block the accepted primitive child method bodies.

No [UID:0000HQ] `BinaryCodec` content change is required unless the supervisor wants the coordinator to mention the newly accepted Decoder child C++.

## Score And Metadata Recommendation

Target source page:

- Current source metadata: `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Generated queue/coverage stale state: `74/84`, reconstructable `true` in `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`; `auto-generated/-ag-memory-coverage.md` already reports `not_reconstructable`.
- Recommended target metadata after accepted update: `COMPLETION:91`, `CONFIDENCE:93`, owner/emitter/reconstructable unchanged.

Reason not higher:

- Raw starts still lack IDA function objects.
- Direct-entry route checks are exhausted negative in the current IDB: no ordinary xrefs, no `xref_query` incoming refs, no VA/RVA pointer hits, no primitive-start vtable slot, no adjacent table route, and no sibling/parent raw-family page supplies an entry route.
- Exact original method spellings and final class header declarations remain final-audit caveats, but the source-facing names and method-body field types are accepted for first-draft C++.
- Generated/manual coverage state is validator/supervisor-owned; B004 supplied source metadata, validators, and exact supervisor-owned manual row text without hand-editing generated or coverage files.
- `95+` remains inappropriate because this is not a final-audit page and sibling/final-header questions remain.

## Resolved Dispositions And Final-Audit Caveats

- Caller/reachability: strict exhausted no-direct-entry proof in the current IDB. B004 correction rechecked `lookup_funcs`, `xrefs_to`, `xref_query direction=to`, `xref_query direction=from`, VA/RVA `find_bytes` pointer patterns, vtable slot xrefs, adjacent table xrefs, surrounding `entity_query` function inventory, [UID:00013Q] parent raw-family docs, [UID:00013M] Decoder/codec glue, [UID:00003M] Decoder class docs, [UID:0000IQ] Decoder file docs, and [UID:0001X1] vtable docs. The current result is no function object at any primitive start, no ordinary incoming xrefs, no incoming `xref_query` records, only local outgoing `fn:null` flow records, no raw VA/RVA pointer-pattern hits, no primitive-start vtable slot, no adjacent table route, and no sibling/parent page that supplies a hidden entry route. This is a final-audit confidence cap only; it is not a blocker for the exact child C++ because the method bodies, owner route, field layout, and active gate are otherwise strong.
- Original source names: accepted current source-facing names are `SetByteOrder`, `ReadByte`, `ReadShort`, `ReadTriByte`, and `ReadInt`. No original symbols were found, so the names remain descriptive/inferred for final-audit scoring, but they are the implementation names for this pass and should not be downgraded to IDA labels or generic helper names.
- `ReadTriByte` spelling: accepted current spelling is `ReadTriByte`. It matches existing docs and the observed 24-bit primitive-reader role. `ReadUInt24` remains only a rejected alternative for this pass because no project-wide source-style evidence currently prefers uint-width spelling here.
- Field signedness and `m_useBigEndian` type: accepted method-body model uses signed-int-shaped `m_inputSize` and `m_readPos` in reader bounds checks because the binary uses signed compare shape, and byte-like `m_useBigEndian` because `SetByteOrder` stores the caller byte exactly. Exact final class-header spellings and declarations remain final-audit caveats, not blockers for these method bodies.
- Header/source split: accepted current emission route is [UID:00003M] `Decoder` through [UID:0000IQ] `NexusTK/util/Decoder.cpp`; [UID:0000HQ] `BinaryCodec` remains a family coordinator, not the direct emitter. Exact historical separate-vs-folded codec packaging is a broader source-tree final-audit caveat and does not block the accepted primitive child C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not write row text for validator-owned `auto-generated/-ag-*` reports. Those must be refreshed through validator/autogen state after accepted source edits.

Manual file requiring supervisor-owned replacement if manual by-memory coverage is still maintained:

- File: `by-memory/-coverage-report.md`.
- Placement: replace the existing [UID:00013P] row currently at line 1238.
- Replacement text:

```text
    - [UID:00013P][0x004a5680-0x004a57dc.DecoderPrimitiveReaders](by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md) 0x004a5680-0x004a57dc | split index | DecoderPrimitiveReaders : not_reconstructable : 91% : very-strong : Non-emitting split index over exact primitive Decoder reader children [UID:0003K8]-[UID:0003KC]; live IDA confirms all child starts remain raw non-functions with zero incoming xrefs, exact instruction bodies, shared cursor layout use, and `0xcc` padding, while the exact children carry the reconstructable source methods and route to [UID:00003M].
```

Reason B004 must not apply it directly: report-only assignment forbids editing manual `-coverage-report.md`; supervisor owns manual coverage edits or may instead rely on validator/generated refresh where applicable.

## Validator Results

- Working directory for all validators: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Validator command form for all final accepted files: `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240 --wait-generated`.
- Generated refresh state: completed for every listed validator, with `generated_refresh_command_id` equal to the file command ID and matching `generated_refresh_timestamp`.

| File | Command ID | Timestamp | Exit | OK | Generated refresh |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md` final rerun | `000000001049` | `2026-06-25T03:47:34-04:00` | `0` | `1` | completed |
| `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md` | `000000001034` | `2026-06-25T03:46:30-04:00` | `0` | `1` | completed |
| `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md` | `000000001036` | `2026-06-25T03:46:41-04:00` | `0` | `1` | completed |
| `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md` | `000000001039` | `2026-06-25T03:46:51-04:00` | `0` | `1` | completed |
| `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md` | `000000001041` | `2026-06-25T03:47:03-04:00` | `0` | `1` | completed |
| `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md` | `000000001043` | `2026-06-25T03:47:13-04:00` | `0` | `1` | completed |
| `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md` summary-durability check | `000000001090` | `2026-06-25T03:51:35-04:00` | `0` | `1` | completed |
| `by-class/Decoder.md` final rerun | `000000001153` | `2026-06-25T03:57:06-04:00` | `0` | `1` | completed |
| `by-file/Decoder.md` final rerun | `000000001159` | `2026-06-25T03:57:21-04:00` | `0` | `1` | completed |
| `by-type/by-struct/BinaryCodecCursorLayout.md` | `000000001056` | `2026-06-25T03:48:08-04:00` | `0` | `1` | completed |
| Correction rerun `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md` | `000000001204` | `2026-06-25T04:28:32-04:00` | `0` | `1` | completed |
| Correction rerun `by-class/Decoder.md` | `000000001205` | `2026-06-25T04:28:43-04:00` | `0` | `1` | completed |
| Correction rerun `by-file/Decoder.md` | `000000001206` | `2026-06-25T04:28:54-04:00` | `0` | `1` | completed |
| Correction rerun `by-type/by-struct/BinaryCodecCursorLayout.md` | `000000001207` | `2026-06-25T04:29:05-04:00` | `0` | `1` | completed |

Additional validator notes:

- Initial target validation `000000001030` ran before the child pages were registered in validator.ini and reported missing refs for [UID:0003K8]-[UID:0003KC]. After child validators registered those pages, target rerun `000000001049` resolved the primitive-child references and inserted UID links.
- Child validators `000000001034`, `000000001036`, `000000001039`, and `000000001041` reported missing refs only to later primitive siblings before those later sibling pages were registered; [UID:0003KC] validation `000000001043` then completed without primitive-sibling missing refs.
- Post-validator summary-durability check `000000001090` on [UID:0003K8] exited `0`, `ok:1`, and generated refresh completed, but it also proved the current validator/coverage injection state rewrites the child `Item Summary` field back to blank. Support-doc validator reruns `000000001153` and `000000001159` triggered the same child-summary overwrite. B004 restored the accepted source-header summaries after all validators while manual `by-memory/-coverage-report.md`, generated coverage, and validator state remained out of scope. Future validator scans may repeat the overwrite until supervisor/tool-owned coverage metadata is repaired.
- Earlier support validators `000000001051` and `000000001054` were superseded by final reruns `000000001153` and `000000001159` after stale historical `95+` no-code wording was removed from `by-class/Decoder.md` and `by-file/Decoder.md`.
- Correction validators `000000001204`-`000000001207` supersede the earlier final rows for the four docs touched by the supervisor-rejection correction. They confirm the amended report/doc wording validates with `ok:1` and generated refresh completed. The final correction batch did not blank the parent or child `Item Summary` fields.
- `by-class/Decoder.md` and `by-file/Decoder.md` still report unrelated pre-existing `missing_ref_uid` diagnostics for unregistered string/blob sibling UIDs [UID:0003L6]-[UID:0003LE] and [UID:0003IB]. The B004 primitive children [UID:0003K8]-[UID:0003KC] resolved and were added to the reference index.
- Validator-owned side effects were produced by the commands, not by manual edits: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `tools/validator_autogen_backup/20260625-034531`, `tools/validator_autogen_backup/20260625-035715`, and `tools/validator_autogen_backup/20260625-035731`.

## Changed Files

- Created earlier during report-only pass: `tools/leaser/Agents/Agent-B004/research/00013P-DecoderPrimitiveReaders-source-quality.md`.
- Updated by B004 implementation:
  - `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`
  - `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md`
  - `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md`
  - `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md`
  - `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md`
  - `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md`
  - `by-class/Decoder.md`
  - `by-file/Decoder.md`
  - `by-type/by-struct/BinaryCodecCursorLayout.md`
- Validator-owned generated/state side effects are listed in `Validator Results`; B004 did not manually edit generated/project-level/manual coverage/tool-state files.
- Renamed: none.
- Leases: B004 leased the nine by-* files for the edit/validator batch, refreshed once by releasing and immediately reacquiring the same set before the long validator sequence, released all nine leases after validators, then used short final B004 leases for support-doc stale-wording cleanup and by-memory summary restoration after validator overwrites. During the supervisor-rejection correction, B004 used fresh short leases for `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`, `by-class/Decoder.md`, `by-file/Decoder.md`, and `by-type/by-struct/BinaryCodecCursorLayout.md` for the final validation batch; final `python tools/leaser/leaser.py B004 unlease` returned `Success` for those four files, and `current_leases.md` showed no active B004 leases.
- Report execution: supervisor-owned; do not move this report manually.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for implementation in assignment `B004-implement-00013P-decoder-primitive-readers-20260625`.
- [x] Target doc `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`: preserve non-emitting index metadata; update score to `91/93`; add 2026-06-25 live MCP evidence; replace stale `AUTOGEN_PARENT_UID` and below-`95/95` wording; preserve no-function/no-xref/no-pointer-route caveats and exact split/padding facts. Proof: file now has `COMPLETION:91`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; Live IDA Evidence records session `80de0a67`; Reconstruction Notes include target no-code proof; validator `000000001049` exited `0`, `ok:1`, generated refresh completed.
- [x] Child doc [UID:0003K8] `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md`: update stale parent/gate prose, set `Nested:0` if no validator-specific blocker exists, fill `Item Summary`, insert exact formal `Decoder::SetByteOrder` C++ from this report, and rescore to `89/92`. Proof: header `89/92`, `Nested:0`, accepted C++ block inserted, current owner/emitter gate prose present, and accepted summary restored after validator overwrite; validator `000000001034` exited `0`, `ok:1`, generated refresh completed, while `000000001090` proved future validator scans can blank the summary until coverage metadata is repaired.
- [x] Child doc [UID:0003K9] `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md`: update stale parent/gate prose, fill `Item Summary`, insert exact formal `Decoder::ReadByte` C++ from this report, and rescore to `89/92`. Proof: header `89/92`, accepted summary restored after validator overwrite, accepted C++ block inserted, current owner/emitter gate prose present; validator `000000001036` exited `0`, `ok:1`, generated refresh completed.
- [x] Child doc [UID:0003KA] `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md`: update stale parent/gate prose, fill `Item Summary`, insert exact formal `Decoder::ReadShort` C++ from this report, and rescore to `88/91`. Proof: header `88/91`, accepted summary restored after validator overwrite, accepted C++ block inserted, current owner/emitter gate prose present; validator `000000001039` exited `0`, `ok:1`, generated refresh completed.
- [x] Child doc [UID:0003KB] `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md`: update stale parent/gate prose, fill `Item Summary`, insert exact formal `Decoder::ReadTriByte` C++ from this report, and rescore to `88/91`. Proof: header `88/91`, accepted summary restored after validator overwrite, accepted C++ block inserted, current owner/emitter gate prose present; validator `000000001041` exited `0`, `ok:1`, generated refresh completed.
- [x] Child doc [UID:0003KC] `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md`: update stale parent/gate prose, fill `Item Summary`, insert exact formal `Decoder::ReadInt` C++ from this report, and rescore to `88/91`. Proof: header `88/91`, accepted summary restored after validator overwrite, accepted C++ block inserted, current owner/emitter gate prose present; validator `000000001043` exited `0`, `ok:1`, generated refresh completed.
- [x] Support doc [UID:00003M] `by-class/Decoder.md`: add primitive reader declarations, record descriptive-name status, record byte-like `m_useBigEndian`, and record signed-compare-shaped input size/read position semantics. Proof: Declaration Direction now lists `SetByteOrder`, `ReadByte`, `ReadShort`, `ReadTriByte`, and `ReadInt`; Observed State records byte-like flag and signed-compare-shaped fields; Evidence/Changes record B004 details; stale historical `95+` no-code wording is superseded with active combined-score/emitter gate language; final validator `000000001153` exited `0`, `ok:1`, generated refresh completed.
- [x] Support doc [UID:0000IQ] `by-file/Decoder.md`: update primitive reader split inventory to say exact children can carry first-draft method C++ after acceptance while [UID:00013P] remains non-emitting. Proof: Proposed Contents and Autogen Notes now state [UID:00013P] remains non-emitting and exact primitive children carry first-draft method C++; stale historical `95+` no-code wording is superseded with active combined-score/emitter gate language; final validator `000000001159` exited `0`, `ok:1`, generated refresh completed.
- [x] Optional support doc [UID:0001TS] `by-type/by-struct/BinaryCodecCursorLayout.md`: update only if implementation records field type/name notes; keep final `sizeof`, exact spellings, and header ownership as broader layout final-audit caveats. Proof: layout table/evidence/open questions/changes now document signed-compare-shaped Decoder bounds fields and byte-like `m_useBigEndian`; final `sizeof`, spellings, and header ownership are preserved only as broader layout caveats; validator `000000001056` exited `0`, `ok:1`, generated refresh completed.
- [x] Do not edit `auto-generated/-ag-*`, `project-level/*`, validator state, queue state, or lock files manually. Refresh generated state only through validator commands. Proof: no manual edits were made to those files; validator commands produced the listed generated/state side effects.
- [x] Supervisor-owned manual coverage action if still required: replace the [UID:00013P] row in `by-memory/-coverage-report.md` with the exact row supplied in this report; B004 must not edit the manual coverage file without explicit callback permission. Proof: B004 did not edit manual `by-memory/-coverage-report.md`; exact supervisor-owned row remains in this report.
- [x] Preserve historical/stale assumptions: old `74/84` reconstructable generated/manual rows are stale; old `95/95` no-code rationale is stale; raw no-function/no-xref status remains current. Proof: target doc has `Generated-State Caveats`, superseded historical notes, active gate language, and current raw no-function/no-xref/no-pointer-route caveats.
- [x] Preserve rejected alternatives and negative evidence: no direct caller, no dword pointer route, no standalone source owner, no BinaryCodec direct emitter, no TextEditPane/PacketBuffer/DATFile ownership, no runtime/compiler-generated classification. Proof: target doc now has `Source Placement And Rejected Alternatives` plus Live IDA evidence for no direct xrefs and no raw pointer route.
- [x] Validators to run after implementation: file validators listed in `Validator Results`; record command, `command_id`, `command_timestamp`, exit code, ok count, and generated-refresh state. Proof: table above records every scoped file validator and generated refresh result.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: active `goal.md` and user callback name assignment `B004-implement-00013P-decoder-primitive-readers-20260625`.
- [x] Leases taken only for immediate edit/validator batch and released after the correction validation batch. Proof: B004 leased the approved by-* files for the active edit/validator windows, including the final support-doc cleanup, summary-restore pass, and supervisor-rejection correction validators; final `python tools/leaser/leaser.py B004 unlease` returned `Success` for `by-memory/0x004a5680-0x004a57dc.DecoderPrimitiveReaders.md`, `by-class/Decoder.md`, `by-file/Decoder.md`, and `by-type/by-struct/BinaryCodecCursorLayout.md`, and `current_leases.md` showed no active B004 leases.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target, five child pages, `by-class/Decoder.md`, `by-file/Decoder.md`, and `by-type/by-struct/BinaryCodecCursorLayout.md` updated as listed above.
- [x] Metadata/score/C++ changes applied or explicitly not applied with reason. Proof: target score `91/93` with no C++ by no-code proof; children scores `89/92`, `89/92`, `88/91`, `88/91`, `88/91` with accepted formal C++; support-doc scores unchanged by design and recorded as before/after unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs record stale old-gate/generated states, rejected owner/source alternatives, no-function/no-xref/no-pointer-route evidence, and current confidence caps.
- [x] Supervisor correction after rejected execution: current-scope questions converted to resolved dispositions with final-audit caveats. Proof: the report now records the correction-pass MCP availability check and route checks (`lookup_funcs`, `xrefs_to`, `xref_query`, VA/RVA `find_bytes`, vtable/table xrefs, `entity_query`, and sibling/parent doc route review); caller/reachability is an exhausted no-direct-entry proof, while original names, `ReadTriByte`, field signedness/byte flag, and header/source split are accepted source-facing dispositions with final-audit caveats. Source docs with stale current-scope wording were amended and correction validators `000000001204`-`000000001207` all exited `0`, `ok:1`, with generated refresh completed.
- [x] Validators run and results recorded. Proof: `Validator Results` table.
- [x] Generated report refresh completed by validator or exact supervisor-owned manual coverage update confirmed. Proof: every scoped validator used `--wait-generated` and returned `generated_refresh: completed`; manual coverage remains supervisor-owned and was not edited by B004. Validator `000000001090` exposed a coverage-metadata durability caveat for child `Item Summary` fields, documented above.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none for source-doc body, metadata, C++, score, owner/emitter, and support-doc incorporation. Residual validator `missing_ref_uid` diagnostics in `by-class/Decoder.md` and `by-file/Decoder.md` concern pre-existing unregistered string/blob/vtable sibling UIDs outside this B004 primitive-child implementation. Future summary durability under validator scans depends on supervisor/tool-owned coverage metadata because B004 may not edit manual coverage, generated coverage, or validator state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00013P-DecoderPrimitiveReaders-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00013P-DecoderPrimitiveReaders-source-quality.md","timestamp":"2026-06-25T04:31:26","uid":"00013P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
