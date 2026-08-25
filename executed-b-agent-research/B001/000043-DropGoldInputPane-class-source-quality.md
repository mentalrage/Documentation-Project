** TARGET-REPORT-UID:000043 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Source-Quality Report: [UID:000043] DropGoldInputPane

Assignment: `B001-goal2-drop-gold-input-pane-class-source-quality-000043-20260619`

Target: [UID:000043] `by-class/DropGoldInputPane.md`

Report path: `tools/leaser/Agents/Agent-B001/research/000043-DropGoldInputPane-class-source-quality.md`

This is a report-only B-agent source-quality pass. I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

## Executive Recommendation

Recommended metadata for [UID:000043] `DropGoldInputPane`:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:0000KC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000KC
RECONSTRUCTION_CPP: keep blank on the class target
```

The current `85/86` score is justified, but it is now conservative. The class has enough source-quality evidence for a modest raise to `87/88`: exact vtable identity, exact `NumberInputPane` base construction, exact prompt id, exact live creator branch, exact submit handler, exact packet format, exact adjacent helper split, exact busy-gate/global dependencies, and strong source placement in [UID:0000KC] `ItemActionInputPanes`.

Do not emit C++ from the class page yet. The class-level declaration is still blocked by unresolved source-level base/virtual naming details in the input-pane hierarchy and by the fact that the concrete method bodies belong to by-memory children, not the class page. If implementation later wants method code, split or update exact method/helper children instead of placing bodies under [UID:000043].

Recommended source-facing names:

| Binary/current label | Recommended source-facing name | Confidence | Evidence |
| --- | --- | --- | --- |
| `DropGoldInputPane` raw constructor at `0x005b4b70` | `DropGoldInputPane::DropGoldInputPane()` | High | Constructor-shaped thiscall body, `NumberInputPane` base construction, prompt id `7`, vtable triad installed, `this` returned in `eax`. |
| `OnSubmitGoldAmount` at `0x005b4bb0` | `DropGoldInputPane::OnSubmit()` | Medium-high | Sibling [UID:00005T] `GiveGoldInputPane` uses `OnSubmit`; [UID:000044] `DropInputPane` uses `OnSubmit`; vtable family identifies this as the primary action/submit slot at `+0x48`. `OnSubmitGoldAmount` is useful as a descriptive alias or split filename, but likely over-specific as original method spelling. |
| `SendDropGoldPacketRaw` at `0x005b4c50` | `static void SendDropGoldPacket(unsigned int amount)` | Medium-high | File-scope/no-`this` raw helper, adjacent to submit path, exact opcode `0x24`, amount parameter from `[ebp+8]`, `retn 4`. Direct xrefs are absent, so this remains a source-facing helper inference rather than original-name proof. |
| `g_pCollectionData + 0x3ec0` | `g_pCollectionData` historical alias / future `g_pUserPane->m_itemCommandBusy` | Medium | Global support now documents this as broad local-player/UserPane state, and the field gates drop/give gold plus direct item-action sends. `cash-shop busy state` is too narrow unless writer evidence later proves that narrower name. |
| prompt id `7` | `kPromptDropGoldAmount` / `IDS_DROP_GOLD_AMOUNT` | Medium | Passed through `g_pLanguageMan` lookup before the `NumberInputPane` constructor. No decoded language-table text was found in the checked docs, so keep the numeric id and use a descriptive constant name. |

## Evidence Checked

Checked target and support documentation:

- [UID:000043] `by-class/DropGoldInputPane.md`
- [UID:000044] `by-class/DropInputPane.md`
- [UID:00005T] `by-class/GiveGoldInputPane.md`
- [UID:00009L] `by-class/NumberInputPane.md`
- [UID:0000KC] `by-file/ItemActionInputPanes.md`
- [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`
- [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`
- [UID:0003FM] `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md`
- [UID:0003MW] `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`
- [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
- [UID:0000QK] `by-global/g_pCollectionData.md`
- [UID:0001OR] `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
- [UID:0000Q5] `by-global/g_packetSender.md`
- [UID:0001OR] prior B001 report `research/0001OR-g_pCollectionData-source-quality.md`
- A005 Batch253 notes in `tools/leaser/Agents/Agent-A005/notes.md`
- Existing class coverage row in `by-class/-coverage-report.md`
- Generated output marker in `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`

Checked direct raw-binary evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` using the PE image base `0x00400000` and disassembly of the relevant ranges. This revalidated the constructor, live creator branch, submit handler, helper body, stack-frame shapes, global references, opcode writes, and packet sender calls independently of the prose docs.

Validator baseline command:

> Executable block R001 was removed from this report and preserved verbatim in [000043-DropGoldInputPane-class-source-quality-removed.md](000043-DropGoldInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit code `0`; dry-run output reported `mode: file`, `scanned markdown files: 1`, `ok: 1`, `ok 000043 by-class/DropGoldInputPane.md UID header exists`, and no target validation failure. It also reported the expected project-wide generated-output noise, including `autogen_emitter_has_no_code` rows, but nothing blocking this target.

## Raw Constructor And Live Creator Evidence

The raw constructor range remains exact:

```text
0x005b4b70-0x005b4bb0
size 0x40 / 64 bytes
```

Representative raw constructor disassembly:

```asm
005b4b70  push ebp
005b4b71  mov  ebp, esp
005b4b74  push esi
005b4b75  mov  esi, ecx
005b4b77  mov  ecx, [0x0067a750]     ; g_pLanguageMan
005b4b7d  push 7
005b4b82  call 0x004f0350            ; language lookup
005b4b87  push eax
005b4b88  mov  ecx, esi
005b4b8a  call 0x004f27a0            ; NumberInputPane constructor
005b4b8f  mov  [esi], 0x0062fea4
005b4b95  mov  eax, esi
005b4b97  mov  [esi+0xa0], 0x0062fef4
005b4ba1  mov  [esi+0xa4], 0x0062ff24
005b4bab  pop  esi
005b4bac  mov  esp, ebp
005b4bae  pop  ebp
005b4baf  ret
```

The checked docs and A005 notes agree that IDA does not model `0x005b4b70` as a function, `xrefs_to 0x005b4b70` is empty, and pointer-pattern scans did not find a direct pointer to the raw start. This must stay explicit: there is no proof of a live direct call to this raw address.

The live reachability evidence comes from [UID:000044] `DropInputPane::OnSubmit`, where gold shortcut characters allocate and initialize the same class inline. The direct branch mirrors the raw constructor stores:

```asm
005b4a9a  mov  ecx, [0x0067a750]     ; g_pLanguageMan
005b4aa0  push 7
005b4aa2  call 0x004f0350
005b4aa7  push eax
005b4aa8  mov  ecx, esi
005b4aaa  call 0x004f27a0            ; NumberInputPane constructor
005b4aaf  mov  [esi], 0x0062fea4
005b4ab5  mov  [esi+0xa0], 0x0062fef4
005b4abf  mov  [esi+0xa4], 0x0062ff24
```

Best inference: `0x005b4b70` is a retained out-of-line constructor body for `DropGoldInputPane::DropGoldInputPane()`, while the live branch in `DropInputPane::OnSubmit` contains an inlined construction sequence. The raw constructor should not be described as directly called, but it is valid source evidence for the class constructor because the live inline construction and raw body match on prompt id, base constructor, vtable triad, and object layout.

Rejected alternatives:

- Not a padding island: it has a normal prologue/epilogue, base-constructor call, vtable stores, and `this` return.
- Not a free packet helper: it uses `ecx` as `this`, calls the input-pane constructor, and writes vptrs.
- Not owned by `NumberInputPane`: `NumberInputPane` is the base; the vtables installed are `DropGoldInputPane` vtables.
- Not proof of a live direct route: no direct xref/pointer evidence was found, so caller docs must say "inline mirror" or "retained out-of-line constructor", not "direct call".

## Submit Handler Evidence

The modeled submit/action body is:

```text
0x005b4bb0-0x005b4c4a
```

Representative disassembly of the behavior:

```asm
005b4bb3  sub  esp, 0xa8
005b4bc3  push 0xf
005b4bc5  lea  eax, [ebp-0x24]
005b4bc8  push eax
005b4bc9  call 0x004f2300            ; input text extraction/conversion helper
005b4bce  xor  ecx, ecx
005b4bd0  cmp  cx, ax
005b4bd3  jge  0x005b4c3c            ; no usable input
005b4bdd  lea  eax, [ebp-0x24]
005b4be0  push 0x006191b0            ; documented as "%u" format literal
005b4be5  push eax
005b4be6  call 0x004944f0            ; parse helper, return ignored
005b4beb  mov  eax, [0x0067a748]     ; g_pCollectionData historical alias
005b4bf3  mov  esi, [ebp-0xa8]       ; parsed amount
005b4bf9  cmp  byte ptr [eax+0x3ec0], 0
005b4c00  jne  0x005b4c3b
005b4c02  lea  eax, [ebp-0xa4]
005b4c09  push 0x24
005b4c0b  call 0x00575380            ; write opcode byte
005b4c16  push eax                   ; packet + 1
005b4c17  push esi                   ; amount
005b4c18  call 0x005753f0            ; encode amount
005b4c1d  mov  ecx, [0x0067a7ec]     ; g_packetSender
005b4c2c  mov  byte ptr [ebp-0x9f], 0
005b4c33  push 5
005b4c35  push eax                   ; packet buffer
005b4c36  call 0x00574bb0            ; queue/send
```

Confirmed behavior:

- Reads current numeric input into a local text/string buffer through `0x004f2300` with limit `0xf`.
- Treats the result as empty when the returned count/length is nonpositive.
- Parses an unsigned decimal amount through `0x004944f0` and the literal currently documented as `%u` at `0x006191b0`.
- Reads the amount from `[ebp-0xa8]`.
- Gates on byte `g_pCollectionData + 0x3ec0`.
- Builds a five-byte packet: opcode `0x24`, followed by the encoded unsigned amount.
- Calls the packet sender through `g_packetSender` / `dword_67A7EC` and `0x00574bb0` with length `5`.
- Writes a zero byte after the five sent bytes, which is local-buffer termination/scratch hygiene rather than part of the sent packet length.

Best source-facing method name: `DropGoldInputPane::OnSubmit()`.

Reasoning:

- The same class family generally uses a primary action/submit slot at vtable offset `+0x48`.
- `DropInputPane` and `GiveGoldInputPane` docs already use `OnSubmit`.
- `GiveGoldInputPane` is the closest sibling and names the equivalent amount submit handler `OnSubmit`.
- `OnSubmitGoldAmount` remains a useful descriptive recovered name, especially for split filenames, but is less likely as a source method name because the class name already supplies "Gold".

Rejected alternatives:

- `OnSubmitInput`: plausible from nearby `CharInputPane`-derived item prompts, but the direct sibling docs use `OnSubmit`, and the current class page already participates in the Drop/Give input-pane family naming rather than the exact `CharInputPane` method spelling.
- `SendDropGoldPacket`: wrong for the submit method because this body also reads/parses the prompt text.
- `OnConfirmInput`: wrong; no confirmation dialog branch and no yes/no confirmation semantics.

## Packet Helper Evidence

The adjacent helper range remains exact:

```text
0x005b4c50-0x005b4cb9
size 0x69 / 105 bytes
pre-padding 0x005b4c4a-0x005b4c50, 6 bytes of 0xcc
post-padding 0x005b4cb9-0x005b4cc0, 7 bytes of 0xcc
```

Representative helper disassembly:

```asm
005b4c63  mov  eax, [0x0067a748]
005b4c68  cmp  byte ptr [eax+0x3ec0], 0
005b4c6f  jne  0x005b4ca9
005b4c71  lea  eax, [ebp-0x84]
005b4c78  push 0x24
005b4c7a  call 0x00575380
005b4c85  push eax                   ; packet + 1
005b4c86  push dword ptr [ebp+8]     ; amount parameter
005b4c89  call 0x005753f0
005b4c8e  mov  ecx, [0x0067a7ec]
005b4c9d  mov  byte ptr [ebp-0x7f], 0
005b4ca1  push 5
005b4ca3  push eax
005b4ca4  call 0x00574bb0
005b4cb6  ret 4
```

The helper is no-`this`, takes one stack parameter, checks the same busy gate, writes the same opcode, encodes the same amount, and sends the same length. It has no direct xrefs or pointer-pattern hits in the checked notes.

Best inference: source file [UID:0000KC] contains or contained a file-scope helper equivalent to:

```cpp
static void SendDropGoldPacket(unsigned int amount);
```

However, the submit handler at `0x005b4bb0` does not call the raw helper directly in the binary; it emits the packet-building code inline. This can be modeled as a retained no-route out-of-line helper plus an inline or duplicate expansion inside `DropGoldInputPane::OnSubmit`. Do not state that `OnSubmit` directly calls `0x005b4c50`; no evidence supports that direct route.

Rejected alternatives:

- Not owned by `Socket`: it depends on `g_packetSender`, but the helper belongs to the item-action prompt module and just queues a packet.
- Not owned by `DropInputPane`: it sends gold amount opcode `0x24`, not slot-drop opcode `0x08`; it is adjacent to the `DropGoldInputPane` submit body and belongs to the drop/give item prompt cluster.
- Not generated thunk/padding: source-shaped stack-cookie body, parameter use, packet construction, and `retn 4`.

## Vtable And Base Layout

`DropGoldInputPane` is best modeled as a `NumberInputPane`-derived prompt class in the item-action prompt module.

Confirmed layout evidence:

- `NumberInputPane` constructor at `0x004f27a0` is called by both raw constructor and live inline branch.
- `DropGoldInputPane` primary vtable: `0x0062fea4`.
- Secondary vtable at `this + 0xa0`: `0x0062fef4`.
- Tertiary vtable at `this + 0xa4`: `0x0062ff24`.
- Primary action slot `+0x48` points to `0x005b4bb0`.
- Live branch in `DropInputPane::OnSubmit` and retained raw constructor install the same vtable triad.
- `DropInputPane` allocates `0x108` bytes for the gold prompt object before the inline constructor sequence.

The three-vtable layout should be documented as inherited input-pane/control-pane multiple-view layout, not hand-emitted as source code on this class page. Exact C++ base declaration remains unsafe because the reusable input-pane class declarations are still blank and the exact virtual method names across the inherited primary/secondary/tertiary views are not final.

## Global, Field, And Helper Meanings

`g_pCollectionData` / `dword_67A748`:

- Current by-doc name remains [UID:0000QK] `g_pCollectionData`.
- Current storage doc [UID:0001OR] now supports a stronger future source-facing name, likely `g_pUserPane`, because lifetime writes/clears belong to `UserPane` and many collection/non-collection views consume the same object.
- For this target, preserve the historical doc link to `g_pCollectionData`, but describe it as local-player/UserPane state, not collection-owned state.

Busy field `+0x3ec0`:

- Best source-facing field name: `m_itemCommandBusy`.
- Acceptable close alternative: `m_itemActionBusy`.
- Avoid finalizing `m_cashShopBusy` from current evidence. The field gates drop/give gold and direct item-action sends such as throw, so "cash-shop busy" is too narrow for this target unless separate writer evidence later proves it.
- The binary assumes the global pointer is non-null in the send path; do not add a source-level null guard in exact method/helper drafts unless a broader source convention requires it.

`g_packetSender` / `dword_67A7EC`:

- Support docs already identify this as the global packet sender, likely `Socket *g_packetSender`.
- This target should not rename or own it.
- `0x00574bb0` is the sender queue method/helper; current source-facing call can be represented as `QueueAndSendPacket(g_packetSender, packet, 5)` or `g_packetSender->QueueAndSendPacket(packet, 5)` depending on the Socket support owner.

`0x00575380`:

- Best role: packet byte writer, used here to write opcode `0x24`.
- Do not assign a final source name from this target alone.

`0x005753f0`:

- Best role: encode/write unsigned amount as the four payload bytes after the opcode.
- Current support text says big-endian/u32be; this remains consistent with the five-byte packet interpretation.

`0x004f0350`:

- Best role: localized string lookup through `g_pLanguageMan`.
- For this target, source shape is `g_pLanguageMan->GetString(7)` or equivalent.

`0x004f2300`:

- Best role: input text extraction/conversion from the base input pane into a local string/text buffer.
- Exact source name is not binary-unique from this target; use a descriptive name such as `GetInputText` only in prose unless the input-pane base owner finalizes the method.

`0x004944f0` and `0x006191b0`:

- Best role: formatted parse helper with `%u` format.
- The submit body ignores the parse helper return. Current reconstructed logic should preserve that behavior or explicitly note that invalid numeric input handling is not fully proven beyond the empty-input gate.

Prompt id `7`:

- Best descriptive constant: `kPromptDropGoldAmount`.
- Evidence checked did not include decoded localized text for id `7`; do not write a literal English prompt as fact.

## Ownership And Source Placement

Keep the canonical owner and emitter as [UID:0000KC] `ItemActionInputPanes`.

Evidence:

- [UID:0000KC] already groups `DropAllInputPane`, `DropInputPane`, `DropGoldInputPane`, `GiveAllInputPane`, `GiveInputPane`, and `GiveGoldInputPane`.
- [UID:0001MG] aggregate range `0x005b44b0-0x005b538a` contains the drop/give item-action prompt cluster and the submit body.
- [UID:0001XU] vtable family places the Drop/Give/Throw/Use/Eat/Wield/Wear input-pane variants in one item-action vtable family.
- `DropInputPane` live gold branch constructs this class from the drop command route.
- The packet helper is no-`this` and file-scope, but its opcode/placement/dependencies keep it in the item-action prompt module.

Rejected owners:

- `NumberInputPane` / [UID:0000K7] `InputPanes`: owns reusable numeric input behavior only. It is a base dependency, not the feature-specific gold prompt owner.
- `DropInputPane`: creates the gold prompt, but the gold prompt has distinct vtables, constructor, submit body, and adjacent helper.
- `CollectionPane` / `g_pCollectionData`: provides local-player state only; no class or helper ownership.
- `UserPane`: likely owns the broad global storage lifetime, but not this UI prompt class.
- `Socket` / `g_packetSender`: sends the packet only; no prompt ownership.
- `CashShopRequest`: rejected by current `g_packetSender` and `g_pCollectionData` support as stale/generated aliasing.

## Heuristic / Inference Reanalysis And Validation

This section resolves every generated/provisional name and open source-quality issue found in the checked target/support docs.

### Raw constructor reachability/modeling

Fact: `0x005b4b70` is not an IDA function and no direct start xref or pointer-pattern hit is documented. Fact: the raw bytes exactly perform the `DropGoldInputPane` construction sequence. Fact: the live `DropInputPane::OnSubmit` branch performs the same construction sequence inline.

Inference: model `0x005b4b70` as a retained out-of-line constructor body, not as a proven live route. This closes the reachability question without overstating it. The class is still source-real because the vtable triad and live construction branch prove a distinct `DropGoldInputPane` object.

### Best constructor name

Fact: the raw body uses `ecx` as `this`, calls the `NumberInputPane` constructor, installs `DropGoldInputPane` vtables, and returns `this`. Inference: `DropGoldInputPane::DropGoldInputPane()` is the correct source-facing constructor. The current `DropGoldInputPaneRawConstructor` page title should stay as a binary-doc qualifier until the start is modeled or intentionally documented as raw/no-route.

### Best submit method name

Fact: current target calls the method `OnSubmitGoldAmount`. Fact: [UID:00005T] sibling `GiveGoldInputPane` calls the equivalent amount handler `OnSubmit`. Fact: [UID:000044] `DropInputPane` uses `OnSubmit`. Fact: vtable family evidence only proves primary action slot `+0x48`, not the exact C++ identifier.

Inference: use `DropGoldInputPane::OnSubmit()` in source-facing prose and generated C++ recommendations. Keep `OnSubmitGoldAmount` only as a descriptive recovered alias or future exact child filename if the supervisor wants a more search-friendly page title.

### Best packet helper name

Fact: `0x005b4c50` takes an amount stack parameter, sends opcode `0x24`, and has no `this`. Fact: it has no direct xrefs. Fact: equivalent code appears inline in submit. Inference: `SendDropGoldPacket(unsigned int amount)` is the best source-facing helper name. Include `static` or anonymous-namespace source placement if C++ is emitted. Do not use `Raw` in source C++; `Raw` is a documentation qualifier.

### Busy field meaning

Fact: this target, `GiveGoldInputPane`, and direct item-action paths use byte `+0x3ec0` as a send gate. Fact: global support now says this is player/client-state, not collection-owned state. Inference: source-facing field should be `m_itemCommandBusy` or `m_itemActionBusy`; I recommend `m_itemCommandBusy`. Reject `m_cashShopBusy` as final wording for this target because the observed users are broader than cash shop.

### Global owner/name

Fact: current accepted docs still use [UID:0000QK] `g_pCollectionData`. Fact: the exact storage reanalysis report recommends future source-facing `g_pUserPane`/local-player state ownership. Inference: `DropGoldInputPane` docs should retain the current link but phrase the dependency as "`g_pCollectionData` historical alias / local-player UserPane state". Do not block this class on the global rename.

### Packet subtype/opcode and payload

Fact: submit and helper both write opcode `0x24`, encode one unsigned amount, and send length `5`. Fact: a trailing zero is written after the sent bytes. Inference: packet shape is `[0x24, amount:u32be]`, total sent length `5`; the trailing zero is not part of payload.

### Text parsing and UTF/string helper names

Fact: submit calls `0x004f2300` with limit `0xf`, checks the returned length/count, then calls `0x004944f0` with format literal `0x006191b0` and ignores the parse return. Inference: source should say "extracts input text, parses `%u`" without finalizing `0x004f2300` or `0x004944f0` names from this target. Do not invent a Unicode/UTF-16 conversion name here; the local object and helper belong to the input/string support docs.

### Prompt id

Fact: raw constructor and live inline branch both pass `7` to `g_pLanguageMan` lookup before constructing `NumberInputPane`. Fact: no decoded language text for id `7` was found in the checked docs. Inference: source-facing constant `kPromptDropGoldAmount = 7` is safe; literal text is not.

### Vtable/base layout

Fact: both raw and live construction install the same three vtables at `+0`, `+0xa0`, and `+0xa4`. Fact: `NumberInputPane` owns the reusable numeric input key filter and base constructor. Inference: class is `NumberInputPane`-derived, with inherited multiple-view/vfptr layout from the input-pane/control-pane hierarchy. Do not hand-code vtables or exact secondary/tertiary base declarations in [UID:000043].

### Source file placement

Fact: all checked range, vtable, caller, and helper evidence sits in the Drop/Give item-action prompt cluster. Inference: source file remains `ui/dialogs/ItemActionInputPanes.cpp`, owner/emitter [UID:0000KC]. The per-class recovered filename `class_DropGoldInputPane.cpp` is a migration artifact, not the preferred source placement.

### Split/range decisions

Fact: `0x005b4b70-0x005b4bb0` and `0x005b4c50-0x005b4cb9` already have exact child pages. Fact: the submit body `0x005b4bb0-0x005b4c4a` is currently only documented inside aggregate [UID:0001MG]. Inference: no class-page split is needed for this report. If supervisor wants first-draft method C++, create an exact by-memory child for `0x005b4bb0-0x005b4c4a` rather than emitting that body from [UID:000043] or from the aggregate.

### Open-question closure

Closed with high confidence:

- Owner/emitter: [UID:0000KC] `ItemActionInputPanes`.
- Base class: [UID:00009L] `NumberInputPane`.
- Constructor role: `DropGoldInputPane::DropGoldInputPane()`.
- Submit role: `DropGoldInputPane::OnSubmit()` amount submit handler.
- Packet helper role: file-scope `SendDropGoldPacket(unsigned int amount)`, retained/no-route helper.
- Packet shape: opcode `0x24`, amount payload, length `5`.
- Prompt id: `7`, descriptive constant `kPromptDropGoldAmount`.
- Busy gate: local-player/UserPane item-command busy byte at `+0x3ec0`.

Not safely final from current evidence, with exact reason:

- Original C++ spelling of `OnSubmit` vs an inherited virtual name such as `OnSubmitInput`: vtable proves slot and behavior, sibling names favor `OnSubmit`, but no source symbol survives.
- Exact source type/name of the local text object at `[ebp-0x24]`: input/string support docs are not final enough; use role language.
- Exact source method spelling for `0x004f2300`, `0x004944f0`, `0x00575380`, and `0x005753f0`: helper roles are clear, but final names are support-owner decisions.
- Exact class declaration/inheritance syntax: `NumberInputPane` base is clear, but primary/secondary/tertiary inherited vtable view declarations are not finalized in source headers.

## First-Draft C++ Recommendation

Target-specific recommendation: keep [UID:000043] `DropGoldInputPane` formal C++ blank for this implementation callback.

No-code proof for the class page:

- `by-class` docs should not own method bodies when exact by-memory children exist or should exist.
- The raw constructor already has an exact by-memory child [UID:0001MH].
- The file-scope helper already has an exact by-memory child [UID:0003FM].
- The submit method body lacks an exact by-memory child and currently lives only in aggregate [UID:0001MG]; emitting it from the class page would bypass the range/split model.
- The exact source class declaration is still blocked by input-pane base declaration details, secondary/tertiary vfptr view modeling, and final virtual method spelling.
- Current generated output for `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` has an empty marker for [UID:000043], which matches this no-code recommendation.

If supervisor accepts a later exact-child C++ pass, use this as the first-draft shape for exact method/helper children, not for the class page:

```cpp
// [UID:0001MH] exact child shape, not class-page emission.
DropGoldInputPane::DropGoldInputPane()
    : NumberInputPane(g_pLanguageMan->GetString(kPromptDropGoldAmount))
{
}

// [UID:NEW or aggregate child] exact 0x005b4bb0-0x005b4c4a shape.
void DropGoldInputPane::OnSubmit()
{
    unsigned int amount;
    InputText text;

    if (GetInputText(text, 0x0f) <= 0) {
        return;
    }

    ParseUnsigned(text, "%u", &amount);

    if (g_pCollectionData->m_itemCommandBusy != 0) {
        return;
    }

    unsigned char packet[6];
    WritePacketByte(packet, 0x24);
    WritePacketUInt32BE(packet + 1, amount);
    packet[5] = 0;
    QueueAndSendPacket(g_packetSender, packet, 5);
}

// [UID:0003FM] exact child shape.
static void SendDropGoldPacket(unsigned int amount)
{
    if (g_pCollectionData->m_itemCommandBusy != 0) {
        return;
    }

    unsigned char packet[6];
    WritePacketByte(packet, 0x24);
    WritePacketUInt32BE(packet + 1, amount);
    packet[5] = 0;
    QueueAndSendPacket(g_packetSender, packet, 5);
}
```

The identifiers `InputText`, `GetInputText`, `ParseUnsigned`, `WritePacketByte`, `WritePacketUInt32BE`, and `QueueAndSendPacket` are placeholders for support-owner names. Do not paste this code verbatim into by-doc C++ until those support names are either finalized or intentionally documented as placeholders.

## Score And Metadata Recommendation

Target [UID:000043]:

- Raise `COMPLETION` from `85` to `87`.
- Raise `CONFIDENCE` from `86` to `88`.
- Keep `CANONICAL_OWNER:0000KC`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000KC`.
- Keep formal C++ blank.

Rationale for `87/88` rather than higher:

- Strong source identity and ownership are established.
- Raw constructor direct reachability remains no-route/inferred, not directly called.
- Submit method exact child is missing.
- Class declaration C++ remains blocked by base/virtual declaration finalization.
- Helper original source name is high-probability but not symbol-proven.

Rationale for raising above `85/86`:

- The live inline constructor branch closes the practical class-reachability concern without requiring a direct xref to `0x005b4b70`.
- The adjacent helper relationship is now better modeled as no-route retained helper plus inline/duplicate submit body.
- The busy-state field can be named more accurately as a local-player item-command gate instead of vague cash-shop state.
- The method/helper names can be source-facing and do not need to remain generated/provisional in the main class prose.

Support score recommendations:

- [UID:0001MH] raw constructor: hold `85/88`; update prose but do not raise unless supervisor wants to reward the retained-constructor inference.
- [UID:0003FM] raw helper: hold `85/88`; update prose but do not raise unless a broader packet-helper naming pass is accepted.
- [UID:0001MG] aggregate: hold `86/88`; optionally add a note that `0x005b4bb0-0x005b4c4a` is eligible for an exact child if method C++ is desired.
- [UID:0000KC] file: hold `90/85`; update source-facing names and no-route helper relationship only.

## Exact Implementation Checklist

Target doc [UID:000043] `by-class/DropGoldInputPane.md`:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:88`.
- Keep owner/emitter metadata unchanged.
- Keep formal C++ blank.
- In Status, change the raw reachability wording from unresolved/medium to "strong for class identity; raw constructor is retained/no-route while live construction is inline in `DropInputPane::OnSubmit`".
- In Class Purpose, replace "cash-shop busy state" with "local-player/UserPane item-command busy gate" or "player/client-state item-command busy gate".
- In Method Notes, rename source-facing submit row to `OnSubmit`; mention `OnSubmitGoldAmount` only as descriptive recovered alias if desired.
- Add helper row wording: file-scope retained raw helper `SendDropGoldPacket(unsigned int amount)`, no direct call proof from submit.
- Add Evidence Notes for the live inline construction mirror at `0x005b4a9a-0x005b4abf`.
- Add Evidence Notes for packet shape `[0x24, amount:u32be]`, length `5`, and local terminator byte not sent.
- Add Source Quality / Inference note that prompt id `7` should be named `kPromptDropGoldAmount` until language text is decoded.
- Add First-Draft C++ note: no class-page C++; exact method/helper children are the correct emission targets.

Support doc [UID:0001MH] `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`:

- Keep metadata `85/88`.
- Replace stale "C++ remains blank under 95+ gate" wording with current no-code reasoning: raw constructor has source-quality body but is a retained/no-route constructor; class-page declaration and exact base names remain unresolved.
- Add explicit live inline mirror evidence from `DropInputPane::OnSubmit` at `0x005b4a9a-0x005b4abf`.
- Use source-facing constructor name `DropGoldInputPane::DropGoldInputPane()`.

Support doc [UID:0003FM] `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md`:

- Keep metadata `85/88`.
- Add source-facing helper recommendation `static void SendDropGoldPacket(unsigned int amount)`.
- State directly that `0x005b4bb0` does not call this helper in the binary; it duplicates or inlines equivalent packet construction.
- Replace stale "below 95/95 gate" wording with current helper-specific no-route/source-name caveat.

Support doc [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`:

- Keep metadata `86/88`.
- Change the table source-facing name for `0x005b4bb0-0x005b4c4a` from `DropGoldInputPane::OnSubmitGoldAmount` to `DropGoldInputPane::OnSubmit` with `OnSubmitGoldAmount` as a descriptive alias if retained.
- Add the range/split note: exact method child should be created if formal method C++ is required.
- Add the retained/no-route relationship for `0x005b4c50-0x005b4cb9`.

Support doc [UID:0000KC] `by-file/ItemActionInputPanes.md`:

- Keep metadata `90/85`.
- Update `DropGoldInputPane` row with source-facing `OnSubmit`, `SendDropGoldPacket(unsigned int)`, prompt id `7`, and item-command busy gate.
- Clarify that `class_DropGoldInputPane.cpp` is a recovered/migration artifact; source placement remains the compact `ui/dialogs/ItemActionInputPanes.cpp`.

Support doc [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`:

- Add or preserve that `DropGoldInputPane` primary action slot `+0x48` is source-facing `OnSubmit`.
- Preserve raw-constructor caveat: do not use `0x005b4b70` as an IDA function-boundary anchor without the raw/no-route qualifier.

Support doc [UID:000044] `by-class/DropInputPane.md`:

- Add a short note that gold shortcut construction at `0x005b4a9a-0x005b4abf` is the live inline constructor mirror for [UID:000043].
- Preserve the gold shortcut characters and allocation/constructor evidence.

Support globals [UID:0000QK] and [UID:0001OR]:

- No required metadata change for this callback.
- If text is touched, describe `+0x3ec0` as `m_itemCommandBusy` / item-command busy gate with historical `g_pCollectionData` alias and future `g_pUserPane` direction.

Support global [UID:0000Q5] `g_packetSender`:

- No required change; existing evidence already includes the gold prompt paths.

Generated code:

- Leave `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` DropGold class marker blank for this class-only callback.
- If a later callback creates an exact `0x005b4bb0-0x005b4c4a` child and accepts helper C++, regenerate through validator/autogen instead of manually editing generated output.

Coverage reports:

- Do not edit `by-memory/-coverage-report.md` for this class-only pass.
- If implementation callback accepts the target score change, update `by-class/-coverage-report.md` with the exact row below.

Validator commands for implementation callback:

> Executable block R002 was removed from this report and preserved verbatim in [000043-DropGoldInputPane-class-source-quality-removed.md](000043-DropGoldInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If any global support text is touched:

> Executable block R003 was removed from this report and preserved verbatim in [000043-DropGoldInputPane-class-source-quality-removed.md](000043-DropGoldInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Supervisor-Owned Coverage Row

Replacement row for `by-class/-coverage-report.md`:

```text
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md) : reconstructable : 87% : very strong : B001 source-quality reanalysis keeps owner/emitter [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), resolves the class as a [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)-derived gold amount prompt constructed by [UID:000044][DropInputPane](by-class/DropInputPane.md) gold shortcuts and retained raw constructor [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md), confirms vtable triple `0x0062fea4`/`0x0062fef4`/`0x0062ff24` and primary submit slot `0x005b4bb0`, identifies prompt id `7`, `%u` amount parse, local-player item-command busy gate [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) historical alias / future UserPane state `+0x3ec0`, opcode `0x24` five-byte packet through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), adjacent no-route file-scope helper [UID:0003FM][0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw](by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md) as `SendDropGoldPacket(unsigned int amount)`, and keeps class C++ blank pending exact class declaration/base/virtual names while recommending exact method-child C++ only for a future split.
```

No `by-memory/-coverage-report.md` row is required for this report-only class target unless the supervisor chooses to create a new exact method child for `0x005b4bb0-0x005b4c4a`. If a new child is created, its UID must be assigned by the validator/workflow first, so this report cannot provide an exact final by-memory row for that hypothetical child.

## Validator Baseline Result

Baseline command already run:

> Executable block R004 was removed from this report and preserved verbatim in [000043-DropGoldInputPane-class-source-quality-removed.md](000043-DropGoldInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result summary:

```text
exit code: 0
mode: file
scanned markdown files: 1
ok: 1
ok           000043 by-class/DropGoldInputPane.md UID header exists
dry run only; pass --apply to write changes
```

The validator also rebuilt registry/report state in dry-run mode and reported expected unrelated project-wide autogen noise. There was no target validation error.

## Final Non-Edit Statement

For this B001 report-only pass, I created only this research report and updated `tools/leaser/Agents/Agent-B001/notes.md`. I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000043-DropGoldInputPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"000043"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000043-DropGoldInputPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000043-DropGoldInputPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000043"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
