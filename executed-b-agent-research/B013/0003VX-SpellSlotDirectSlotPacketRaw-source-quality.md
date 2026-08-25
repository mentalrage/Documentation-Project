** TARGET-REPORT-UID:0003VX **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003VX **
# Agent-B013 Source-Quality Report: 0003VX SpellSlotDirectSlotPacketRaw

## Finalized Report / Current Recommendation

- Target UID: `0003VX`
- Target path: `source-3/project-documentation/by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md`
- Current target state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters.
- Recommendation: promote from ownerless non-emitting raw island to a reconstructable retained `SpellSlotInputPane` member helper.
- Recommended metadata: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000DS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DS`.
- Recommended source-facing name: `SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)`; descriptive/inferred, not proven original symbol text.
- Source route: [UID:0000DS] `SpellSlotInputPane` -> [UID:0000O0] `SpellInputPanes` -> `NexusTK/ui/dialogs/SpellInputPanes.cpp`.
- C++ readiness: first-draft C++ is appropriate if the supervisor accepts promotion. The no-route caveat should be documented as retained/unreferenced source code, not as proof that the bytes are non-source.

Only this report file was created. No by-* docs, generated files, IDA DB files, project-level reports, or `by-memory/-coverage-report.md` were edited.

## Supporting Research

## Target

- UID: `0003VX`
- Address range: `0x005b14f0-0x005b1568`
- Size: `0x78` / 120 bytes (Verified with `int_convert.py`)
- Current title: `SpellSlot Direct Slot Packet Raw`
- Current disposition: no-route raw code island, not reconstructable, no owner/emitter.
- Containing family: [UID:0001LN] `SpellArgumentInputPanes`
- Related live handler: [UID:0001LX] `SpellSlotInputPaneSubmitSpellSlot`
- Direct candidate owner: [UID:0000DS] `SpellSlotInputPane`
- Candidate source file: [UID:0000O0] `SpellInputPanes`

## Executive Recommendation

Promote [UID:0003VX] to a reconstructable retained member helper under [UID:0000DS] `SpellSlotInputPane`. The current no-route facts remain true, but they should cap confidence rather than force `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`.

The ownership evidence is stronger than address adjacency alone:

- The helper receives `this` in `ecx`, saves it in `esi`, and reads `this + 0x108`.
- `this + 0x108` is initialized by [UID:0001LV] `SpellSlotInputPaneConstructor` as the spell-index/spell-byte state and is serialized by the live submitter [UID:0001LX].
- The helper's body is exactly the packet-send tail of [UID:0001LX], except it receives the already-decoded selected slot as a stack byte instead of parsing/validating text.
- It is bounded by documented `0xcc` alignment immediately after [UID:0001LX] and before [UID:0001LY] `SayTargetMessageInputPanes`.
- The source file parent [UID:0000O0] and class parent [UID:0000DS] both clear the active 85/85 gate.

The route search is still negative: no rel32 call/jump, absolute VA pointer, or RVA pointer to `0x005b14f0` was found in the PE. This supports "retained no-route helper" and keeps the score below final-audit quality, but it does not overcome the stronger class-specific `this`/field/packet evidence for semantic ownership.

## Supervisor Active Recheck

The current supervisor assignment asks for a report-only Rule 26 pass. The report rechecked route/liveness, source placement, helper naming, packet helpers, the `this + 0x108` spell byte, selected-slot naming, and whether no-route/non-emitting should remain correct.

This target does not require a structural split before report completion. The range is already exact, the surrounding padding is already represented in [UID:0000VN] `-ignored`, and the raw successor begins at `0x005b1570`.

## Evidence Standards Used

Evidence classes used:

- Direct PE byte/disassembly evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Whole-image rel32, absolute VA, and RVA pointer scans.
- Positive controls for known nearby routed code.
- Current by-* documentation for the SpellSlot class, file, live submitter, constructor, packet buffer writers, send queue helper, and `g_packetSender`.
- Sibling raw helper comparison, especially [UID:0003VW] and [UID:0002S6].
- `by-structure.md` current reconstruction metadata rules.
- `inference_research.md` evidence ranking: direct instruction semantics and xrefs outrank adjacency, but source ownership without debug symbols is still probabilistic.

No IDA DB modifications were made. IDA MCP was not used for writes. Local PE/Capstone checks were used because the target's current doc already records the IDA MCP no-function/no-xref facts; this pass revalidated those claims independently against raw bytes.

## IDA / PE Facts

### Function / Range Facts

Direct disassembly of `0x005b14f0-0x005b1568`:

```asm
005b14f0  push ebp
005b14f1  mov ebp, esp
005b14f3  sub esp, 0x130
005b14f9  mov eax, dword ptr [0x672f24]
005b14fe  xor eax, ebp
005b1500  mov [ebp-4], eax
005b1503  push esi
005b1504  lea eax, [ebp-0x130]
005b150a  mov esi, ecx
005b150c  push eax
005b150d  push 0x0f
005b150f  call 0x00575380
005b1514  lea eax, [ebp-0x12f]
005b151a  push eax
005b151b  movsx eax, byte ptr [esi+0x108]
005b1522  push eax
005b1523  call 0x00575380
005b1528  lea eax, [ebp-0x12e]
005b152e  push eax
005b152f  movsx eax, byte ptr [ebp+8]
005b1533  push eax
005b1534  call 0x00575380
005b1539  mov ecx, dword ptr [0x67a7ec]
005b153f  lea eax, [ebp-0x130]
005b1545  add esp, 0x18
005b1548  mov byte ptr [ebp-0x12d], 0
005b154f  push 3
005b1551  push eax
005b1552  call 0x00574bb0
005b1557  mov ecx, [ebp-4]
005b155a  xor ecx, ebp
005b155c  pop esi
005b155d  call 0x005c772f
005b1562  mov esp, ebp
005b1564  pop ebp
005b1565  ret 4
```

Boundary facts:

- `0x005b14e6-0x005b14f0`: ten `0xcc` alignment bytes after [UID:0001LX].
- `0x005b14f0-0x005b1568`: complete helper-shaped body with stack cookie.
- `0x005b1565`: three-byte `ret 4`; target end-exclusive `0x005b1568`.
- `0x005b1568-0x005b1570`: eight `0xcc` alignment bytes.
- `0x005b1570`: next modeled successor context begins [UID:0001LY] `SayTargetMessageInputPanes`.

### Route / Xref Facts

Direct PE scan results:

- `0x005b14f0` rel32 call/jump refs: none.
- `0x005b14f0` absolute VA dword hits in the PE: none.
- `0x001b14f0` RVA dword hits in the PE: none.
- Positive control `0x005b1410` has one absolute VA hit in `.rdata` at `0x0062f6b8`, the vtable slot for [UID:0001LX].
- Positive control `0x005b1280` has rel32 constructor calls at `0x0057cc18`, `0x0057e52c`, and `0x0057f243`.
- Positive control `0x005b1570` has a rel32 constructor/helper call at `0x0059edf7`.
- Sibling raw starts `0x005b1200` and `0x005b3410` also have no rel32 or absolute VA/RVA hits in this scan.

Signature facts:

- First 16 bytes of the target's helper skeleton occur in 11 places, including unrelated packet helpers and the direct spell argument helpers.
- First 24 and first 32 bytes occur exactly at the five direct spell argument helper starts: `0x005b0a10`, `0x005b0d00`, `0x005b0fa0`, `0x005b1200`, and `0x005b14f0`.
- First 48 bytes are unique to `0x005b14f0`.
- Full `0x78` / 120-byte target signature is unique.

Meaning: route remains negative, while the body is part of a recognized direct-argument/direct-slot packet-helper family.

### Packet Layout Facts

Sent packet length is `3`. The helper writes four local bytes, but the final byte is an unsent terminator/safety byte:

| Packet local offset | Writer | Meaning |
| --- | --- | --- |
| `packet[0]` | `PacketBufferWriteUInt8(0x0f, packet)` | spell-use opcode `0x0f` / 15 (Verified with `int_convert.py`) |
| `packet[1]` | `PacketBufferWriteUInt8(this->m_spellIndex, packet + 1)` | stored spell-index/spell byte from `this + 0x108` / 264 (Verified with `int_convert.py`) |
| `packet[2]` | `PacketBufferWriteUInt8(selectedSlot, packet + 2)` | explicit selected spell slot argument from `[ebp + 8]` |
| `packet[3]` | direct zero write | unsent terminator outside `QueueAndSendPacket(..., 3)` |

The helper uses [UID:0003YJ] `PacketBufferWriteUInt8` at `0x00575380`. That helper also writes a spare zero after each byte; each subsequent write overwrites the previous spare zero, and the explicit final zero at `packet[3]` preserves the same terminator convention.

The send handoff is [UID:0001HU] `QueueAndSendPacket` at `0x00574bb0` with receiver `dword_67A7EC` / [UID:0000Q5] `g_packetSender`.

### Relationship To Live Submitter

[UID:0001LX] `SpellSlotInputPaneSubmitSpellSlot` sends the same three-byte packet at `0x005b1492-0x005b14d1` after it:

- checks the line-input text length is exactly one character;
- copies and decodes the character;
- maps `a-z` to slots `1..26`;
- maps `A-Z` to slots `27..52`;
- rejects values below `1`;
- checks the selected slot against `g_activeUserStatusPane + 0x284`.

[UID:0003VX] performs none of those parse/validation steps. It assumes its selected-slot argument is already valid enough to send. This is why the source-facing name should be packet-send oriented, not a submit/validate name.

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Status

Best inference: source-authored retained member helper, not padding, not compiler glue, and not a Socket/PacketBuffer helper.

Evidence:

- It is executable `.text` with a complete prologue, stack cookie, PacketBuffer writer calls, queue/send call, and `ret 4`.
- It writes NexusTK spell-use protocol opcode `0x0f`; compiler/runtime code would not know this feature packet layout.
- It reads class state at `this + 0x108` and sends through the shared project packet sender.
- It is bounded by documented alignment before and after.

Rejected alternatives:

- Padding/alignment: rejected by executable body and calls.
- Compiler-generated thunk: rejected because it builds feature packet data and has stack locals/security cookie, not a `this` adjustment jump.
- Socket/PacketBuffer-owned helper: rejected because those are dependencies; this helper chooses spell opcode and spell fields.
- SayTargetMessageInputPanes owner: rejected because `0x005b1570` begins after eight `0xcc` bytes and uses different constructor context.

### Route / Reachability

Best inference: no static reachability route is currently proven.

Evidence checked:

- Prior IDA MCP facts recorded in target doc: no function object at `0x005b14f0`, no xrefs, no pointer-byte hits for `F0 14 5B 00`.
- Current PE scan: no rel32 call/jump, no absolute VA pointer, no RVA pointer for `0x005b14f0`.
- Positive controls confirmed the scan can find nearby routes: vtable pointer for `0x005b1410`, direct constructor calls for `0x005b1280`, and successor call to `0x005b1570`.

Conclusion:

The helper should be documented as "retained no-route" code. No report should claim it is live. However, no-route is not a source-authorship disproof; it is compatible with an unused out-of-line helper retained because the object file was linked without function-level dead-stripping or because a helper was inlined into the live submitter while an out-of-line copy remained.

### Owner / Source Placement

Best owner: [UID:0000DS] `SpellSlotInputPane`.

Evidence:

- `ecx` is used as `this`; the body saves it to `esi`.
- The body reads `byte ptr [esi + 0x108]`, the same field initialized by [UID:0001LV] and serialized by [UID:0001LX].
- The helper immediately follows the live `SpellSlotInputPane` submit handler.
- The helper body is the packet-send tail of [UID:0001LX] with selected slot passed directly.
- Class parent [UID:0000DS] scores `86/88`; file parent [UID:0000O0] scores `88/87`; both meet the active route gate.

Second-best owner: [UID:0000O0] `SpellInputPanes` as a file-local helper.

Evidence for:

- The direct packet helper family lives in `SpellInputPanes.cpp` source context.
- The helper may have been a private static/free function in the original file.

Evidence against:

- The emitted calling convention is `thiscall`-shaped with `ecx` as a `SpellSlotInputPane *`, not a cdecl/free helper with explicit `this` pointer.
- It reads a class member rather than operating only on file-local state.

Decision: use [UID:0000DS] as canonical owner and [UID:0000DS] as emitter. The class then routes through [UID:0000O0].

Rejected owners:

- [UID:0001LN] `SpellArgumentInputPanes`: aggregate/index only; not the narrowest source owner.
- [UID:0003YJ] `PacketBufferScalarBigEndianWriteHelpers`: writes bytes but does not own feature packet semantics.
- [UID:0001HU] `QueueAndSendPacket` / [UID:0000DD] `Socket`: transport dependency only.
- [UID:0000Q5] `g_packetSender`: global receiver dependency only.
- `CANONICAL_OWNER:NONE`: current historical disposition, but now too conservative because class-specific `this` state and helper-family evidence are strong enough for a semantic owner.

### Source-Facing Names

Recommended descriptive method name:

```cpp
SpellSlotInputPane::SendSpellSlotPacket
```

Recommended signature:

```cpp
void SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot);
```

Reasoning:

- `Send` is better than `Submit` because this helper does not parse or validate input.
- `SpellSlotPacket` is better than `DirectSlotPacket` for source: "direct" describes our route condition, not necessarily the original programmer's concept.
- `selectedSlot` is the best argument name. It is the already-decoded slot selected by the user or caller, not a raw keyboard character.
- `signed char` is the safest binary-facing type because the body sign-extends `[ebp + 8]` and `this + 0x108` before calling `PacketBufferWriteUInt8`.
- `m_spellIndex`, `m_spellSlotIndex`, and `m_spellByte` are viable field names. Best recommendation is `m_spellIndex` or `m_spellIdByte` as a descriptive name; current class/support docs already use "stored spell index". The field is a one-byte spell record index used both for prompt lookup and as packet offset `+1`.

Rejected names:

- `SpellSlotDirectSlotPacketRaw`: useful documentation filename but not source-facing.
- `SubmitSpellSlot`: belongs to [UID:0001LX], which parses the line input and validates against max slot.
- `CastSpell`: too broad; this helper only builds the packet.
- `SendUseSpellPacket`: semantically plausible because opcode `0x0f` is the spell-use family, but less aligned with the current class and selected-slot docs than `SendSpellSlotPacket`.

### Protocol / Helper Names

Recommended names:

- `PacketBufferWriteUInt8` for `0x00575380`.
- `QueueAndSendPacket` for `0x00574bb0`.
- `g_packetSender` as a `Socket *`-backed global for `0x0067a7ec`.
- `kOpcodeUseSpell` or `kSpellUseOpcode` for `0x0f` if constants are introduced in support docs; otherwise keep literal `0x0f`.

Rejected:

- `sub_575380`, `sub_574BB0`, `dword_67A7EC`: should remain historical/generated labels only.
- `g_pCashShopRequest`: explicitly rejected by [UID:0000Q5] and [UID:0001P0] for this address.

### Source Shape And Inlining

Best source-shape inference:

The original source likely had an out-of-line helper equivalent to `SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)`. [UID:0001LX] may have called this helper in source and had the call inlined, or both the submitter and helper may have been written with duplicate packet-send code. The first explanation is source-cleaner and matches the existence of a retained out-of-line copy, but the binary alone cannot prove whether the programmer wrote a helper call or duplicate code in [UID:0001LX].

Impact:

- This target can emit the helper body directly.
- Do not rewrite [UID:0001LX] solely from this report. A later source-quality pass for [UID:0001LX] should decide whether its first-draft C++ calls `SendSpellSlotPacket(selectedSlot)` or preserves inline packet writes.

### Score / Metadata Impact

The current `85/86` is defensible for a documented no-route raw island, but it is missing the stronger source-owner conclusion and full route scan evidence. After incorporating B013 details, `87/89` is justified:

- Completion rises because the report resolves owner/source placement, packet helper names, selected-slot field naming, route checks, source-shape policy, and C++ readiness.
- Confidence rises because direct PE route scans with positive controls and field/submitter comparison strengthen the claims.
- Confidence stays below `90+` because no static caller/pointer route exists and original helper name/declaration style remains inferred.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005b1410-0x005b14e6` | [UID:0001LX] `SpellSlotInputPaneSubmitSpellSlot` | live virtual submit handler | `TRUE` | [UID:0000DS] | `86/89` | parses/validates typed slot, sends same packet |
| `0x005b14e6-0x005b14f0` | [UID:0000VN] ignored padding | alignment | `FALSE` | ignored ledger | `100/strong` | ten `0xcc` bytes |
| `0x005b14f0-0x005b1568` | [UID:0003VX] target | retained direct-slot packet member helper | recommend `TRUE` | recommend [UID:0000DS] | recommend `87/89` | no static route; source-authored helper |
| `0x005b1568-0x005b1570` | [UID:0000VN] ignored padding | alignment | `FALSE` | ignored ledger | `100/strong` | eight `0xcc` bytes |
| `0x005b1570-...` | [UID:0001LY] `SayTargetMessageInputPanes` | successor neighborhood | separate | separate | separate | not owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005b14f0` | no rel32/VA/RVA refs found | no static route to helper |
| `0x005b150f`, `0x005b1523`, `0x005b1534` | calls `0x00575380` | writes opcode, spell index, selected slot |
| `0x005b1539` | reads `0x0067a7ec` | loads shared `g_packetSender` |
| `0x005b1552` | calls `0x00574bb0` | queues 3-byte packet |
| `0x005b155d` | calls `0x005c772f` | security-cookie check |
| `0x0062f6b8 -> 0x005b1410` | positive-control vtable pointer | live submitter route exists nearby |
| `0x0057cc18`, `0x0057e52c`, `0x0057f243 -> 0x005b1280` | positive-control constructor calls | scanner sees ordinary nearby rel32 routes |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0001LV] documents constructor storage of the original spell-index byte at `this + 0x108`.
- [UID:0001LX] documents the live submitter serializing `this + 0x108` at packet offset `+1`, selected slot at `+2`, and length `3`.
- [UID:0000DS] identifies the class purpose as a spell-slot letter prompt.
- [UID:0000O0] identifies `SpellInputPanes.cpp` as the source family for spell prompt panes.
- [UID:0003YJ] gives the best source-facing name `PacketBufferWriteUInt8` for `0x00575380`.
- [UID:0001HU] gives `QueueAndSendPacket` for `0x00574bb0`.
- [UID:0000Q5]/[UID:0001P0] resolve `dword_67A7EC` to `g_packetSender`, not `g_pCashShopRequest`.

Existing docs that are stale or too conservative:

- [UID:0003VX] says there is no safe source owner. This should be replaced with a retained-helper conclusion: no route is proven, but [UID:0000DS] is the best semantic owner.
- [UID:0001LX] says the adjacent helper remains non-emitting. It should be updated after target implementation to say B013 promoted the helper as retained source-authored `SpellSlotInputPane` code, while preserving the no-route caveat.
- [UID:0001LN] lists all direct packet raw islands as non-emitting. For this target only, update the [UID:0003VX] row. The other direct-argument raw islands should not be bulk-promoted without their own B-source-quality passes, though this target's signature evidence is a strong lead.

## Ranked Ownership Analysis

### 1. [UID:0000DS] SpellSlotInputPane

- Evidence for: `thiscall` shape, `this + 0x108` class field, exact packet-tail match with [UID:0001LX], immediate adjacency after [UID:0001LX], class/file parents clear gate.
- Evidence against: no static route; exact original helper name unknown.
- Decision: accept as canonical owner/emitter. The negative route evidence is a confidence cap, not an owner blocker.

### 2. [UID:0000O0] SpellInputPanes

- Evidence for: correct file family, direct packet helper family lives in this module, source file can contain private helper functions.
- Evidence against: not the narrowest owner; helper uses implicit `this` and a class field.
- Decision: source file route only through class parent, not canonical owner.

### 3. [UID:0001LN] SpellArgumentInputPanes

- Evidence for: contains the contiguous exact children and raw helper family.
- Evidence against: aggregate/index page; not an original source-level method owner.
- Decision: support/index only.

### 4. Socket / PacketBuffer / g_packetSender

- Evidence for: helper calls PacketBuffer and QueueAndSendPacket, reads `g_packetSender`.
- Evidence against: dependencies do not choose spell opcode or class fields.
- Decision: rejected as owner; retain cross-references.

### 5. CANONICAL_OWNER:NONE

- Evidence for: no IDA function object, no xrefs, no VA/RVA route.
- Evidence against: body is feature-specific source code using class state and adjacent class handler packet semantics.
- Decision: reject as final disposition after B013 reanalysis. Preserve "no route" as caveat.

## Negative Evidence Summary

- No rel32 call/jump to `0x005b14f0`.
- No absolute VA dword pointer to `0x005b14f0`.
- No RVA dword pointer to `0x001b14f0`.
- No current known vtable slot points to `0x005b14f0`.
- No route was found via successor [UID:0001LY] or sibling direct helpers.
- First 24/32-byte skeleton is shared with all direct spell argument helper starts, so the prologue alone is not unique.
- Generated aliases `sub_575380`, `sub_574BB0`, `dword_67A7EC`, and `g_pCashShopRequest` are not source-facing names.

How this affects decisions:

- Blocks claiming live reachability.
- Blocks near-final confidence and original helper-name certainty.
- Does not block reconstructable status or class owner/emitter recommendation because the body is demonstrably NexusTK source-authored logic and class-specific.

## First-Draft C++ Recommendation

If the supervisor accepts promotion, add source-style C++ to the target's reconstruction block. This draft intentionally omits compiler-generated security-cookie scaffolding and uses descriptive names already supported by packet/global docs.

```cpp
void SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)
{
    unsigned char packet[4];

    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(m_spellIndex, packet + 1);
    PacketBufferWriteUInt8(selectedSlot, packet + 2);
    packet[3] = 0;

    QueueAndSendPacket(g_packetSender, packet, 3);
}
```

Source-shape notes:

- `m_spellIndex` is a descriptive placeholder for the one-byte field at `this + 0x108`. `m_spellIdByte` or `m_spellSlotIndex` are acceptable alternatives if the class-wide naming pass chooses them.
- `selectedSlot` is signed byte-shaped because the binary uses `movsx` on the stack argument before writing it.
- `PacketBufferWriteUInt8` writes one payload byte plus a spare zero. The explicit `packet[3] = 0` is outside the counted length and should be preserved for source fidelity.
- If constants are introduced later, `0x0f` should become `kOpcodeUseSpell` or `kSpellUseOpcode`.
- The live submitter [UID:0001LX] may be source-cleaner if written as `SendSpellSlotPacket(selectedSlot)` after validation, but this report does not recommend editing [UID:0001LX]'s formal C++ yet.

## Recommended Target Doc Changes

For `source-3/project-documentation/by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md`:

1. Metadata:
   - `COMPLETION:85 -> COMPLETION:87`
   - `CONFIDENCE:86 -> CONFIDENCE:89`
   - `CANONICAL_OWNER:NONE -> CANONICAL_OWNER:0000DS`
   - `RECONSTRUCTABLE:FALSE -> RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:` -> `EMITTER_UIDS:0000DS`
2. Keep the filename for now to avoid a one-target rename churn. Inside the page, add the source-facing name `SpellSlotInputPane::SendSpellSlotPacket`.
3. Replace "no safe source owner" with "retained no-route source-authored member helper; no static route is proven, but [UID:0000DS] is the best direct semantic owner."
4. Add a full "B013 2026-06-19 Source-Quality Reanalysis" section with:
   - exact disassembly summary;
   - packet layout table;
   - no rel32/VA/RVA route results and positive controls;
   - signature-family result: 24/32-byte skeleton shared by five direct spell helpers, 48-byte and full target unique;
   - owner ranking and rejected alternatives;
   - field/helper names: `m_spellIndex`, `selectedSlot`, `PacketBufferWriteUInt8`, `QueueAndSendPacket`, `g_packetSender`;
   - source-shape caveat for possible inline call from [UID:0001LX].
5. Add the first-draft C++ body above to `RECONSTRUCTION_CPP`.
6. Add a change-log entry:
   - Before: ownerless `RECONSTRUCTABLE:FALSE` no-route raw island.
   - After: reconstructable retained `SpellSlotInputPane` member helper at `87/89`, owner/emitter [UID:0000DS], formal C++ populated.
   - Evidence: B013 PE/Capstone recheck, route scans with positive controls, packet-tail comparison with [UID:0001LX], and constructor/field support from [UID:0001LV].

## Recommended Support-Doc Changes

### [UID:0000DS] `by-class/SpellSlotInputPane.md`

Add/update method inventory row:

```md
| retained packet helper | [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) | Source-authored retained no-route helper, best named `SendSpellSlotPacket(signed char selectedSlot)`, that sends opcode `0x0f`, stored spell-index byte `this+0x108`, and selected slot byte through `g_packetSender`. |
```

Add evidence note:

```md
- 2026-06-19 B013 rechecked [UID:0003VX] and promoted it from ownerless no-route raw island to retained `SpellSlotInputPane` source code. No static caller/pointer route to `0x005b14f0` is proven, but the helper has `thiscall` shape, reads the constructor-initialized `+0x108` spell-index byte, and duplicates the packet-send tail of `SubmitSpellSlot`.
```

### [UID:0000O0] `by-file/SpellInputPanes.md`

In the `SpellSlotInputPane` proposed-content row or placement notes, add:

```md
- [UID:0003VX] is a retained no-route `SpellSlotInputPane::SendSpellSlotPacket`-style helper in this source file. It should be treated like [UID:0002S6] in the ChangeSpellSlot family: source-authored packet helper code with no proven static route, not PacketBuffer/Socket-owned code.
```

Do not bulk-promote [UID:0003VT]/[UID:0003VU]/[UID:0003VV]/[UID:0003VW] from this one report. Add a follow-up note that their shared prologue/signature family is a lead for future B reanalysis.

### [UID:0001LN] `by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md`

Update [UID:0003VX] row in "Covered Exact Function Pages":

```md
| [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) | retained `SpellSlotInputPane::SendSpellSlotPacket` helper | Reconstructable retained no-route member helper that sends opcode `0x0f`, stored spell index, and selected slot byte; no static route proven. |
```

Update direct packet raw-island text to say the slot helper is now promoted after B013, while the four/three/two/one raw helpers remain no-owner/non-emitting pending separate reanalysis.

### [UID:0001LX] `SpellSlotInputPaneSubmitSpellSlot`

Replace the current adjacent raw-helper statement with:

```md
- [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) is a retained no-route `SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)`-style helper after B013 reanalysis. No static caller/pointer route is proven, but it duplicates this submitter's packet-send tail after validation. Future first-draft C++ for this submitter may call that helper after slot validation if the source-shape pass chooses a factored helper form.
```

### Packet / Global Support Docs

No required edits to [UID:0003YJ], [UID:0001HU], [UID:0000Q5], or [UID:0001P0]. They already supply the best helper/global names.

## Exact Coverage-Report Replacement Row

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B013. If the supervisor accepts this report and applies the target/support changes, replace the current [UID:0003VX] row with:

```md
    - [UID:0003VX][0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw](by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md) 0x005b14f0-0x005b1568 | retained raw packet helper | SpellSlotInputPaneSendSpellSlotPacketRaw : reconstructable : 87% : strong : B013 source-quality pass promotes this from ownerless non-emitting raw island to retained `SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)`-style source code; PE bytes confirm the 0x78/120-byte body, stack-cookie helper shape, opcode `0x0f`, stored spell-index byte from `this+0x108`, selected-slot byte argument, unsent terminator at packet `+3`, `QueueAndSendPacket(g_packetSender, packet, 3)`, exact padding `0x005b14e6-0x005b14f0` and `0x005b1568-0x005b1570`, and no rel32/absolute-VA/RVA route to `0x005b14f0` despite positive controls for neighboring routed functions; owner/emitter should be [UID:0000DS] `SpellSlotInputPane` through `SpellInputPanes.cpp`, with route absence retained as a confidence cap.
```

Expected project-level stats row after validator apply:

```md
| `0003VX` | 87 | 89 | 88.0 | `by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md` |
```

## Validation Commands Needed After Implementation

Run these after the supervisor-authorized by-* updates:

> Executable block R001 was removed from this report and preserved verbatim in [0003VX-SpellSlotDirectSlotPacketRaw-source-quality-removed.md](0003VX-SpellSlotDirectSlotPacketRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected results:

- Target validator exits `0`.
- [UID:0003VX] autogen memory coverage changes from `not_reconstructable` to emitting through owner/emitter `0000DS`.
- `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` contains a `0003VX` generated helper body instead of no output.
- Project stats show `0003VX | 87 | 89 | 88.0`.
- No by-memory coverage edit is made by B013; supervisor applies the exact row above.

Current pre-implementation dry run:

- Command: `python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005b14f0-0x005b1568.SpellSlotDirectSlotPacketRaw.md"`
- Result: exit `0`, `ok:1`; dry-run-only generated/stat output. Current generated state remains `not_reconstructable` because this report is not an implementation pass.

## IDA Rename / Type / Comment Recommendations

If IDA-side annotation is later allowed:

- Create/define function range `0x005b14f0-0x005b1568` if IDA still lacks a function object.
- Name: `SpellSlotInputPane__SendSpellSlotPacket` or local project C++ method naming equivalent.
- Type:

```c
void __thiscall SpellSlotInputPane_SendSpellSlotPacket(SpellSlotInputPane *this, signed char selectedSlot);
```

- Struct/member recommendation:
  - `SpellSlotInputPane + 0x108`: `signed char m_spellIndex` or `m_spellIdByte`; keep a comment that this byte indexes the local-player spell record and is serialized as packet byte `+1`.
- Comments:
  - At `0x005b150d`: `spell-use opcode 0x0f`
  - At `0x005b151b`: `stored spell index byte from SpellSlotInputPane`
  - At `0x005b152f`: `selected slot argument, already decoded/validated by caller`
  - At `0x005b1548`: `terminator outside counted 3-byte packet payload`
  - At `0x005b1552`: `QueueAndSendPacket(g_packetSender, packet, 3)`
  - At function header: `Retained no-route helper; no static caller/pointer route currently proven.`

## Open Questions After Reanalysis

- No static route to `0x005b14f0` is proven. This should remain documented and should cap confidence below final-audit levels.
- Exact original helper name is not recovered. `SendSpellSlotPacket` is the strongest descriptive source name.
- Exact class member name for `this + 0x108` remains class-wide unresolved. `m_spellIndex` is a strong descriptive name, but future class/source passes may choose a slightly different final spelling.
- Whether [UID:0001LX] source should call this helper or duplicate packet writes remains unresolved. This does not block [UID:0003VX] helper emission; it should be decided when [UID:0001LX] receives a first-draft C++ pass.
- Sibling direct raw helpers [UID:0003VT]/[UID:0003VU]/[UID:0003VV]/[UID:0003VW] likely deserve similar B reanalysis because their 24/32-byte skeleton matches this target, but this report does not apply metadata changes to them.

## Final Recommendation

Apply the promotion in a supervisor implementation callback:

- [UID:0003VX] `85/86 -> 87/89`
- `CANONICAL_OWNER:NONE -> 0000DS`
- `RECONSTRUCTABLE:FALSE -> TRUE`
- `EMITTER_UIDS:` -> `0000DS`
- Add first-draft C++ for `SpellSlotInputPane::SendSpellSlotPacket(signed char selectedSlot)`.
- Update [UID:0000DS], [UID:0000O0], [UID:0001LN], and [UID:0001LX] with the retained no-route helper conclusion and route-negative evidence.
- Replace the supervisor-owned coverage row with the exact text above.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md`
- Modified: none.
- Moved/renamed: none.

FINISHED: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VX","source_path":"executed-b-agent-research/B013/0003VX-SpellSlotDirectSlotPacketRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
