** TARGET-REPORT-UID:00004B **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Source-Quality Report: [UID:00004B] EmotionInputPane

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\EmotionInputPane.md`  
Report-only path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\00004B-EmotionInputPane-class-source-quality.md`  
Assignment date: 2026-06-19  
Disposition: report-only; no `by-*` documentation file and no `by-memory/-coverage-report.md` was edited during this pass.

## Executive Recommendation

Raise [UID:00004B] `EmotionInputPane` from `85/86` to `87/89`.

Keep:

- `CANONICAL_OWNER:0000ID`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000ID`
- blank formal `RECONSTRUCTION_CPP CODE` on the class page

Reason: PE/Capstone reanalysis confirms the class identity, constructor, vtable route, virtual input handler, packet helper route, localized help-menu branches, singleton names, packet-support dependencies, and padding boundaries. The class is source-authored and belongs under [UID:0000ID] `CommandInputPanes`, but the class page itself should not carry method-body C++. The missing emitted `OnCharInput` body belongs to a child by-memory method page or to a later split of [UID:0001M3], not to the `by-class` page. This is a class-level target, and Supervisor Rule 24 says class files should generally emit global class-level code only; method bodies should remain restricted to `by-memory`/`by-type` children.

I recommend updating the supporting method-cluster documentation as part of any accepted implementation callback, especially [UID:0001M3] `0x005b29c0-0x005b2f68.EmotionInputPane` and [UID:0001M4] `0x005b2f70-0x005b2fcb.SendEmotionPacket`, because the current generated output still shows empty emitter markers for the class, method cluster, vtables, and packet helper in `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp`.

## Evidence Checked

Documentation and generated-output evidence:

- `by-class/EmotionInputPane.md`
- `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`
- `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`
- `by-file/CommandInputPanes.md`
- `by-type/by-vtable/EmotionInputPaneVtables.md`
- `by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md`
- `by-type/by-vtable/CommandInputPaneVtableFamily.md`
- `by-item/ScopedMarkerMissingMethodBodies.md`
- `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp`
- `by-class/-coverage-report.md`
- `by-memory/-coverage-report.md` was read only to identify stale support rows; it was not edited.
- `by-memory/-ignored.md` padding rows for `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0`
- `by-global/g_useEpfAssets.md`, `by-global/g_pLanguageMan.md`, `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`
- `by-global/g_pChattingViewport.md`, `by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md`, `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
- `by-global/g_pOldSystemMessagePane.md`, `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md`, `by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md`
- `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
- `by-item/PacketBufferHelpers.md`, `by-file/PacketBuffer.md`, `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-global/g_packetSender.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`

Binary evidence:

- Local PE: `E:\NTK\Resources\NexusTK\NexusTK.exe`
- Parsed PE sections before converting VAs to raw offsets. The relevant mapping is `.text` VA `0x00401000-0x0060c600`, raw `0x00000400`, raw size `0x20b600`; `.rdata` VA `0x0060d000-0x0066c200`; `.data` VA `0x0066d000-0x0069ce24`.
- Capstone disassembly of:
  - `0x005b29c0-0x005b2a70`
  - `0x005b2a70-0x005b2f68`
  - `0x005b2f70-0x005b2fcb`
  - `0x0062f9b8-0x0062fa40`
- Direct `.text` rel32 call scans for `0x005b29c0`, `0x005b2a70`, and `0x005b2f70`.
- Whole-image absolute dword scans for `0x005b29c0`, `0x005b2a70`, `0x005b2f70`, and EmotionInputPane vtable bases.
- Scoped validator dry-run baseline on the target:

> Executable block R001 was removed from this report and preserved verbatim in [00004B-EmotionInputPane-class-source-quality-removed.md](00004B-EmotionInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit `0`; `apply=False`; scanned markdown files `1`; `ok: 1`; key result `ok 00004B by-class/EmotionInputPane.md UID header exists`. The dry-run also reported `autogen_emitter_has_no_code 00004B`, matching the current empty marker in generated output.

## Exact Binary Range And Route Findings

### Constructor: `0x005b29c0-0x005b2a70`

- Half-open range: `0x005b29c0-0x005b2a70`
- Size: `0xb0` / 176 bytes.
- Raw file offset for start under parsed PE mapping: `0x001b1dc0`.
- There is no internal padding between the constructor end and `OnCharInput`; `OnCharInput` starts immediately at `0x005b2a70`.
- Direct rel32 callers found by scan:
  - `0x005a6138`
  - `0x005a9390`
  - `0x005b2f38` from the `?` help-menu reopen path inside `EmotionInputPane::OnCharInput`
- Whole-image absolute dword scan for `0x005b29c0` found no pointer-table hits.

Confirmed constructor behavior:

- Calls `0x004f28a0` as the `CharInputPane` constructor/base setup.
- Installs EmotionInputPane vtables:
  - `0x005b2a03`: writes `0x0062f9b8` to `[esi]`
  - `0x005b2a09`: writes `0x0062fa08` to `[esi+0xa0]`
  - `0x005b2a13`: writes `0x0062fa38` to `[esi+0xa4]`
- Uses [UID:0000RC] `g_pLanguageMan` at `0x0067a750` and lookup helper `0x004f0350`.
- Pushes localized string id `0x20` / 32.
- Pushes `0x70` / 112 before the prompt/setup path. Existing docs correctly treat this as the emotion input count/limit, not object size.
- Formats a prompt buffer through `0x0041b9b0` and applies it through `0x004f20a0`.
- Uses the usual security-cookie prologue/epilogue and returns through `ret`.

### Virtual Input Handler: `0x005b2a70-0x005b2f68`

- Half-open range: `0x005b2a70-0x005b2f68`
- Size: `0x4f8` / 1272 bytes.
- Raw file offset for start: `0x001b1e70`.
- Direct rel32 call scan found no direct code callers.
- Whole-image absolute dword scan found exactly one pointer to the function start: `.rdata`/vtable slot `0x0062fa00`.
- This confirms `OnCharInput` is virtual/vtable-routed, not a free helper or direct dispatcher target.

Vtable data confirms:

```text
0x0062f9b8 -> 0x005b7940
0x0062f9bc -> 0x004f4b10
...
0x0062fa00 -> 0x005b2a70  EmotionInputPane::OnCharInput
0x0062fa08 -> 0x005b77c8
...
0x0062fa38 -> 0x005b77d3
```

The vtable range `0x0062f9b8-0x0062fa40` is `0x88` / 136 bytes. The three-view ABI matches the command input pane family: primary vfptr at object `+0`, secondary at `+0xa0`, tertiary at `+0xa4`.

Confirmed `OnCharInput` behavior:

- Branches on [UID:0000SW] `g_useEpfAssets` / historical `byte_66DA97` at `0x0066da97`.
- Both branches call the one-character input helpers:
  - `0x004f2310` and compare returned `ax` with `1`.
  - `0x004f2300` to copy one UTF-16 character into a stack local.
- Both branches normalize uppercase ASCII `A-Z` to lowercase by adding `0x20`. The corrected Capstone slice confirms the normalized value is assigned back to `ecx` before the `a-p` range test:

```text
0x005b2ac8 lea eax, [edx - 0x41]
0x005b2acb cmp ax, 0x19
0x005b2acf ja  0x005b2ad7
0x005b2ad1 lea eax, [edx + 0x20]
0x005b2ad4 movzx ecx, ax
0x005b2ad7 lea eax, [ecx - 0x61]
0x005b2ada cmp ax, 0x0f
```

- For letters `a-p`, the handler calls `SendEmotionPacket` at `0x005b2f70` through three call sites:
  - `0x005b2aef`
  - `0x005b2b15`
  - `0x005b2f52`
- The selector mapping is not simply a linear `ch - 'a'` at all call sites:
  - `a-l`: argument is `ch - 0x56`; after helper subtraction `0x0b`, sent byte is `0..11`.
  - `m-n`: argument is `ch - 0x64`; after helper subtraction `0x0b`, sent byte is `0xfe` / `0xff` if treated as unsigned.
  - `o-p`: argument is `ch - 0x58`; after helper subtraction `0x0b`, sent byte is `12..13`.
- This exact split should be documented rather than flattened to "a-p sequential" if child C++ is later drafted.
- If the one-character input is not in `a-p` and not `?`, the handler exits without packet send or menu construction.
- If the one-character input is `?`, the handler opens a localized emotion help/menu and then attempts to allocate and construct a replacement/reopened `EmotionInputPane` object of `0x108` / 264 bytes through allocator `0x004f4aa0` and constructor call `0x005b2f38 -> 0x005b29c0`.

New/current UI branch when `g_useEpfAssets == 1`:

- Reads `0x0067adc4`, now documented as [UID:0002WV] `g_pChattingViewport`.
- Clears `byte [g_pChattingViewport + 0x130]`.
- Calls `SystemMessagePane` helper `0x005854b0`.
- Uses [UID:0000RC] `g_pLanguageMan` and `0x004f0350` repeatedly.
- Appends localized id `31` (`0x1f`) with parameters `4` and `0x24`.
- Appends localized ids `15-30` (`0x0f-0x1e`) with parameters `0x84` and `0x24`.
- Calls `0x00585560` and refresh/prune helper `0x00585360`.
- Allocates `0x108` and constructs another `EmotionInputPane` if allocation succeeds.

Legacy/old UI branch when `g_useEpfAssets != 1`:

- Reads `0x0069b4c8`, now documented as [UID:0003ED] `g_pOldSystemMessagePane`.
- Clears `byte [g_pOldSystemMessagePane + 0x130]`.
- Calls `OldSystemMessagePane` helper `0x00589330`.
- Uses `g_pLanguageMan` and `0x004f0350` repeatedly.
- Appends localized id `31` with parameters `4` and `0x24`.
- Appends localized ids `15-30` with parameters `0x84` and `0x24`.
- Calls `0x00589470` and `0x005892a0`.
- Allocates `0x108` and constructs another `EmotionInputPane` if allocation succeeds.

### Packet Helper: `0x005b2f70-0x005b2fcb`

- Half-open range: `0x005b2f70-0x005b2fcb`
- Size: `0x5b` / 91 bytes.
- Raw file offset for start: `0x001b2370`.
- Direct rel32 callers:
  - `0x005b2aef`
  - `0x005b2b15`
  - `0x005b2f52`
- Whole-image absolute dword scan for `0x005b2f70` found no pointer-table hits.
- The helper uses `ret 4` and never reads the incoming `ecx` receiver, even though callers set `ecx = this` before calling. This is strong evidence for a file-local/static helper or a static class helper rather than an ordinary instance method.

Confirmed helper behavior:

```text
0x005b2f83 lea eax, [ebp - 0x83]       ; packet+1
0x005b2f89 mov byte ptr [ebp-0x84],0x1d
0x005b2f91 mov eax, [ebp+8]
0x005b2f94 add eax, -0x0b
0x005b2f98 call 0x00575380             ; PacketBufferWriteUInt8(value, out)
0x005b2f9d mov ecx, [0x0067a7ec]       ; g_packetSender
0x005b2fac mov byte ptr [ebp-0x82],0
0x005b2fb3 push 2
0x005b2fb5 push packet
0x005b2fb6 call 0x00574bb0             ; QueueAndSendPacket
```

Best source-facing helper name remains `SendEmotionPacket`.

The support names should be updated away from raw placeholders:

- `0x00575380`: `PacketBufferWriteUInt8(unsigned char value, unsigned char *out)` or equivalent. Existing PacketBuffer docs accept value-first as the ABI-faithful signature; older destination-first drafts should be treated as wrapper-style notation only.
- `0x0067a7ec`: [UID:0000Q5] `g_packetSender`, best current source-facing type `Socket *`.
- `0x00574bb0`: [UID:0001HU] `QueueAndSendPacket`, Socket-owned queue/send funnel.

The helper constructs a two-byte sent packet:

- byte `0`: opcode `0x1d`
- byte `1`: `selectorArgument - 0x0b`
- local byte `2`: zero scratch/safety terminator, not sent
- send length: `2`

The opcode is not `0x0e`; `0x0e` belongs to the adjacent ChatInputPane report/task family, not to EmotionInputPane. This target's packet route is opcode `0x1d`.

### Padding Boundaries

Confirmed by mapped PE bytes:

- `0x005b2f68-0x005b2f70`: eight bytes of `0xcc` padding after `OnCharInput` and before `SendEmotionPacket`.
- `0x005b2fcb-0x005b2fd0`: five bytes of `0xcc` padding after `SendEmotionPacket`.

These should remain ignored alignment padding, not source-authored helper code.

## Heuristic / Inference Reanalysis And Validation

### Class, Base, And Vtable Layout

Best-supported class name: `EmotionInputPane`.

Evidence:

- The constructor stores EmotionInputPane-specific vtables at object `+0`, `+0xa0`, and `+0xa4`.
- The input handler is referenced only from vtable slot `0x0062fa00`.
- Constructor callers at `0x005a6138` and `0x005a9390`, plus the self-reopen path at `0x005b2f38`, are command-input/UI construction routes rather than packet or system-message ownership.
- Existing [UID:0001XA] `CommandInputPaneVtableFamily` documents the shared three-view ABI used by related command input panes.

Best-supported base: `CharInputPane`, not a standalone `LineInputPane` or generic `Pane`.

Evidence:

- Constructor calls `0x004f28a0`, currently documented as `CharInputPane` construction.
- The class uses one-character input helper patterns and command prompt behavior matching the command input pane family.
- It inherits or uses line-input/prompt helper calls, but the class-level owner should stay `EmotionInputPane : CharInputPane`.

Object-size inference:

- The help-menu reopen path allocates `0x108` / 264 bytes before calling the constructor. This is strong evidence for the concrete object allocation size.
- The constructor also pushes `0x70` / 112 into input setup. That value is the max emotion selector count/input limit, not object size. Do not conflate it with allocation size.

### Source Placement

Best-supported source placement: [UID:0000ID] `CommandInputPanes`, likely `NexusTK/ui/dialogs/CommandInputPanes.cpp`.

Evidence:

- Current class page already emits through [UID:0000ID].
- `by-file/CommandInputPanes.md` groups Emotion, Group, Post, and related command input panes.
- The class is prompt/input behavior, not system-message ownership. It depends on SystemMessagePanes only for rendering the localized `?` menu.
- It sends through shared PacketBuffer/Socket infrastructure, but packet-support dependencies do not make it PacketBuffer, Socket, or ProtocolSend-owned.

Possible split: a separate `EmotionInputPane.cpp` remains plausible in original source, but current evidence does not prove a split. The most defensible current reconstruction route is still `CommandInputPanes.cpp` with a clear source-placement caveat that social/spell/block-listen command pane families are split elsewhere when evidence proves it.

### Packet Helper Ownership

Best-supported formal owner for [UID:0001M4] remains [UID:0000ID] `CommandInputPanes`, with a narrower source-role note: file-local/static `SendEmotionPacket` used only by `EmotionInputPane::OnCharInput`.

Evidence:

- All three direct callers are inside `EmotionInputPane::OnCharInput`.
- The helper does not read `ecx`, does not access object fields, and returns with `ret 4`.
- Callers set `ecx = this` before calling, but the helper discards it. That pattern is consistent with compiler/codegen preserving a conventional call setup from nearby member-call code, not proof of instance-method semantics.
- A private static class helper is possible, but a file-local `static void SendEmotionPacket(int selector)` in `CommandInputPanes.cpp` is the least invented source shape.

Rejected ownership alternatives:

- `PacketBuffer.cpp`: rejected. PacketBuffer owns `PacketBufferWriteUInt8`; this helper owns feature opcode `0x1d`.
- `Socket.cpp`: rejected. Socket owns `g_packetSender` and `QueueAndSendPacket`; this helper only consumes the shared send funnel.
- `SystemMessagePanes.cpp`: rejected. SystemMessagePane/OldSystemMessagePane are UI menu dependencies for `?`, not packet-helper owners.
- `Chatting.cpp`/ChatInputPane: rejected. ChatInputPane uses opcode `0x0e`; this target uses opcode `0x1d` and different command-input construction.
- `EmotionInputPane` ordinary instance method: rejected for now because the helper never reads `ecx`. If a later recovered header proves `static EmotionInputPane::SendEmotionPacket`, that would still emit in the same source file, but current evidence does not require class-member ownership.

### Globals And Placeholder Names

Use these source-facing names in future docs:

| Address / placeholder | Best-supported name | Evidence and status |
| --- | --- | --- |
| `byte_66DA97` / `0x0066da97` | `g_useEpfAssets` | Existing [UID:0000SW] page resolves this global; it selects EPF/new UI assets and drives the new/old system-message branch. |
| `dword_67A750` / `0x0067a750` | `g_pLanguageMan` | Existing [UID:0000RC] / [UID:0001OS] docs resolve this singleton and 192 xrefs; `0x004f0350` is the localized string lookup helper. |
| `dword_67ADC4` / `0x0067adc4` | `g_pChattingViewport` | Existing [UID:0002WV] resolves the first `UiChatClanSingletonSlots` dword as a `SystemMessagePane *` / chat viewport pointer; EmotionInputPane reads it in the `g_useEpfAssets == 1` branch. |
| `dword_69B4C8` / `0x0069b4c8` | `g_pOldSystemMessagePane` | Existing [UID:0003ED] resolves this legacy system-message pane singleton; EmotionInputPane reads it in the old-UI branch. |
| `dword_67A7EC` / `0x0067a7ec` | `g_packetSender` | Existing [UID:0000Q5] resolves this as the Socket-owned outbound sender global. |
| `sub_575380` / `0x00575380` | `PacketBufferWriteUInt8` | Existing PacketBuffer source-quality work resolves the high-fan-in byte writer; use value-first signature for ABI comments. |
| `sub_574BB0` / `0x00574bb0` | `QueueAndSendPacket` | Existing [UID:0001HU] resolves this as the Socket-owned queue/send funnel. |
| `sub_5854b0`, `sub_5854d0`, `sub_585560`, `sub_585360` | `SystemMessagePane` reset/append/finalize/refresh helpers | Existing [UID:0001J6] maps the range `0x005854b0-0x005856e9` as `SystemMessagePane` header marker append, colored-text append, footer marker append, cloned-entry insert, and prune path; `0x00585360-0x005854ac` is refresh/prune/list/scroll-geometry maintenance. Exact original method names are still inferred. |
| `sub_589330`, `sub_589350`, `sub_589470`, `sub_5892a0` | `OldSystemMessagePane` reset/append/finalize/refresh helpers | Existing [UID:0001J6] maps `0x00589180-0x0058948f` as old-pane cleanup/reset/message-list insertion/update support. Exact original method names remain inferred. |

### Localized Menu Branch Types

Best source-facing interpretation:

- `g_useEpfAssets == 1`: show emotion help using the current/new system-message/chat viewport path, `g_pChattingViewport`, whose concrete owner is the SystemMessagePanes source family.
- `g_useEpfAssets != 1`: show the same emotion help through the legacy `OldSystemMessagePane` singleton, `g_pOldSystemMessagePane`.

Rejected alternatives:

- "The `?` branch owns SystemMessagePane": rejected. EmotionInputPane is the caller/producer of the help menu contents; SystemMessagePane/OldSystemMessagePane own the display/list helpers and singleton storage.
- "The branch is only a generic language lookup": rejected. It clears display state at `+0x130`, appends 17 localized entries, finalizes, refreshes, and reopens the input pane.
- "The old/new branch names should stay `dword_67ADC4` and `dword_69B4C8`": rejected. Project-local global docs now resolve both placeholders.

### OnCharInput Emission Gap

Current generated output:

- `auto-generated/NexusTK/ui/dialogs/CommandInputPanes.cpp` contains a real PostInputPane body and empty emitter markers for [UID:00004B], [UID:0001M3], [UID:0002N4], [UID:0003HI], and [UID:0001M4].
- `by-item/ScopedMarkerMissingMethodBodies.md` still records a historical issue where `EmotionInputPane::OnCharInput` emitted a raw `sub_5B2A70` body. Current generated output no longer emits that raw body; it now emits empty markers. The tracker should be updated if accepted to say the current symptom is a missing/empty body, not an active raw generated function body.

Best resolution:

- Do not put method bodies into `by-class/EmotionInputPane.md`.
- Populate future formal method C++ on [UID:0001M3] or split [UID:0001M3] into exact constructor and `OnCharInput` child pages if the project wants cleaner per-method emission.
- [UID:0001M4] can eventually carry a small file-local/static helper body once the supervisor accepts helper placement and naming.

### First-Draft C++ Eligibility

Target class page [UID:00004B]: no formal C++ should be emitted now.

Exact target-specific no-code proof:

- The target is a class page, not the exact method-body range. Supervisor Rule 24 says class files should generally emit class-level code and not contain specifics for methods inside.
- The class page already routes through [UID:0000ID] `CommandInputPanes`; child [UID:0001M3] owns the constructor and `OnCharInput` executable bytes, while child [UID:0001M4] owns the packet helper executable bytes.
- Emitting `OnCharInput` on the class page would duplicate or bypass the child by-memory ownership structure.
- A correct `OnCharInput` first draft needs exact source names/signatures for SystemMessagePane append/finalize helpers and for the reopen/attachment pattern after allocator `0x004f4aa0`. Those can be described now, but formal C++ would still contain invented helper calls unless the support pages are split/named further.
- The class page should instead document the method inventory, layout/vtable evidence, and source-placement decisions, then let child pages emit code when ready.

Non-formal reference shape for [UID:0001M4] only, not to paste into the class page:

```cpp
static void SendEmotionPacket(int selector)
{
    unsigned char packet[3];

    packet[0] = 0x1d;
    PacketBufferWriteUInt8(static_cast<unsigned char>(selector - 0x0b), packet + 1);
    packet[2] = 0;
    QueueAndSendPacket(g_packetSender, packet, 2);
}
```

This reference shape reflects the helper's exact behavior and is plausible mid-2000s C++ if the project accepts file-local static helper placement. It should still be inserted only on the helper page, not on [UID:00004B].

I do not recommend formal `OnCharInput` C++ in this report pass. The behavior is now well enough documented for a modest score increase, but formal child C++ should wait for an implementation callback that either:

1. splits [UID:0001M3] into constructor and `OnCharInput` pages and drafts both, or
2. keeps [UID:0001M3] as a multi-method cluster and accepts inferred helper names for the system-message menu calls.

## Open-Question Closure

Question: Is `OnCharInput` missing because the class is not reconstructable?  
Answer: No. The function is source-authored and exact. It is missing because the current emitting docs keep class and method child C++ blank. The route is vtable-only through `0x0062fa00`, not unrecoverable.

Question: Is `SendEmotionPacket` an instance method of `EmotionInputPane`?  
Answer: Not safely. It is feature-private, but it does not read `ecx`. Best current source shape is file-local/static `SendEmotionPacket` in `CommandInputPanes.cpp`. Document it as Emotion-specific and called only from `EmotionInputPane::OnCharInput`.

Question: Should the `?` branch use raw `dword_67ADC4` / `dword_69B4C8` names?  
Answer: No. Existing global docs resolve these as `g_pChattingViewport` and `g_pOldSystemMessagePane`. Keep raw names only as historical aliases/search terms.

Question: Does `byte_66DA97` remain unresolved?  
Answer: No. Use [UID:0000SW] `g_useEpfAssets`.

Question: Does the class belong under `Chatting`, `SystemMessagePanes`, `PacketBuffer`, `Socket`, or a central `ProtocolSend` file?  
Answer: No. Those are dependencies. The semantic source owner remains command input pane UI code under `CommandInputPanes`.

Question: Should this target be split?  
Answer: The class page should not split. The method-cluster page [UID:0001M3] is a good future split candidate into constructor and `OnCharInput` if the project wants exact method-level emission, but the current assigned target is [UID:00004B] and can be improved without creating new files. The helper [UID:0001M4] already has its own page.

Question: Are padding ranges part of the class/helper source?  
Answer: No. `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0` are confirmed `0xcc` alignment and should stay ignored.

Question: Is opcode `0x0e` relevant?  
Answer: Not for this target. The Emotion packet helper sends opcode `0x1d`; opcode `0x0e` is ChatInputPane-related and should not be routed into EmotionInputPane docs except as a rejected adjacent-task confusion.

## Proposed Metadata And Scores

Target [UID:00004B] `by-class/EmotionInputPane.md`:

- `COMPLETION:87`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000ID`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000ID`
- Formal `RECONSTRUCTION_CPP CODE`: blank

Score rationale:

- Completion rises because this pass resolves placeholder global names, packet helper dependencies, exact selector arithmetic, exact route scans, current generated-output symptom, and class-vs-child C++ placement.
- Completion stays below 90 because formal method C++ is still not emitted and the SystemMessagePane/OldSystemMessagePane helper method spellings remain descriptive/inferred.
- Confidence rises because PE/Capstone confirms the exact ranges, routes, vtable pointer, direct callers, and padding; confidence stays below 90 because original source spellings for menu helper methods and exact file split remain inferred.

Support recommendation:

- [UID:0001M3] can also be raised to `87/89` if the implementation incorporates the exact PE/Capstone route and behavior details above.
- [UID:0001M4] can be raised to `87/90` if the implementation updates packet helper names, source placement, and the file-local/static helper conclusion. If no helper-page content is changed, leave its metadata unchanged and only correct stale coverage text later.

## Implementation Checklist For Accepted Callback

Do not edit `by-memory/-coverage-report.md`; leave exact rows for supervisor application.

Target:

1. `by-class/EmotionInputPane.md`
   - Change score to `87/89`.
   - Keep owner/emitter [UID:0000ID] and `RECONSTRUCTABLE:TRUE`.
   - Keep formal C++ blank.
   - Add a status/source-quality note that the class is source-authored, reconstructable, owner-routed through `CommandInputPanes`, but method-body C++ belongs to child pages.
   - Replace raw `dword_67ADC4` and `dword_69B4C8` wording with `g_pChattingViewport` and `g_pOldSystemMessagePane`, preserving raw aliases as historical search terms.
   - Add exact constructor/vtable evidence: constructor range, size, caller set, vtable stores, object allocation size `0x108`, prompt id `32`, max `0x70` / 112.
   - Add exact `OnCharInput` evidence: range, size, vtable-only pointer at `0x0062fa00`, no direct rel32 callers, one-character path, uppercase normalization, `a-p` selector split, `?` menu branches, `g_pLanguageMan` resource ids `31` and `15-30`, and reopen constructor call at `0x005b2f38`.
   - Add exact helper relationship: [UID:0001M4] called at `0x005b2aef`, `0x005b2b15`, `0x005b2f52`; helper sends opcode `0x1d`, not `0x0e`.
   - Add rejected alternatives and no-code proof.

Support:

2. `by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md`
   - Add PE/Capstone range proof for constructor and `OnCharInput`.
   - Add exact route scans and vtable slot evidence.
   - Replace raw menu singleton names with resolved globals.
   - Add exact selector arithmetic and note that `m/n` are not linear `12/13` if interpreted through helper subtraction.
   - Update generated-output warning: current generated file emits empty markers, not an active raw `sub_5B2A70` body.
   - Consider score `87/89`.

3. `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`
   - Add helper route scan, no pointer-table hits, three direct caller addresses, `ret 4`, no `ecx` use.
   - Normalize support names to `PacketBufferWriteUInt8`, `g_packetSender`, and `QueueAndSendPacket`.
   - Preserve or clarify `CANONICAL_OWNER:0000ID` unless supervisor chooses a static-class-helper route; my recommendation is file-local/static helper under `CommandInputPanes`.
   - Add the non-formal or formal helper C++ only if the supervisor accepts helper C++ insertion on this child page.
   - Consider score `87/90`.

4. `by-file/CommandInputPanes.md`
   - Update EmotionInputPane source-placement discussion with the current no-split recommendation, exact dependencies, and generated-output status.
   - Do not move EmotionInputPane to `Chatting`, `SystemMessagePanes`, `PacketBuffer`, or `Socket`.

5. `by-type/by-vtable/EmotionInputPaneVtables.md` and `by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md`
   - Add or preserve the route proof that `0x005b2a70` appears only at `0x0062fa00` as a pointer, and that constructor stores the three vtable bases.
   - No score change required unless the implementation adds new evidence.

6. `by-item/ScopedMarkerMissingMethodBodies.md`
   - Update the stale symptom if accepted: current generated output has empty markers for [UID:00004B]/[UID:0001M3], rather than the old raw `sub_5B2A70` emitted body.

7. Generated docs:
   - Do not manually edit generated files.
   - After by-* implementation, run scoped validators with `--apply`; generated `CommandInputPanes.cpp`, `auto-generated/-ag-*coverage.md`, and projected stats may refresh markers/scores.

## Exact Validator Commands For Implementation Callback

Baseline already run:

> Executable block R002 was removed from this report and preserved verbatim in [00004B-EmotionInputPane-class-source-quality-removed.md](00004B-EmotionInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Required after accepted implementation, from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R003 was removed from this report and preserved verbatim in [00004B-EmotionInputPane-class-source-quality-removed.md](00004B-EmotionInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If vtable support docs are edited:

> Executable block R004 was removed from this report and preserved verbatim in [00004B-EmotionInputPane-class-source-quality-removed.md](00004B-EmotionInputPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Coverage Row Text For Supervisor Application

Target class coverage row replacement for `by-class/-coverage-report.md`:

```text
- [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) : reconstructable : 87% : strong : B009 2026-06-19 source-quality reanalysis keeps owner/emitter [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md); PE/Capstone confirms constructor `0x005b29c0-0x005b2a70` installs EmotionInputPane vtables `0x0062f9b8`/`0x0062fa08`/`0x0062fa38` after `CharInputPane` construction, formats prompt resource id `32` with max `0x70` / 112, virtual `OnCharInput` at `0x005b2a70-0x005b2f68` is reached only through vtable slot `0x0062fa00`, lowercases one-character input, maps `a-p` through the opcode `0x1d` helper with split selector arithmetic, opens `g_pChattingViewport`/`SystemMessagePane` or `g_pOldSystemMessagePane`/`OldSystemMessagePane` localized `?` help menus for resource ids `31` and `15-30`, and keeps formal class-page C++ blank because method bodies belong on child by-memory pages while menu helper signatures/source spelling remain inferred.
```

Optional supervisor-owned support row replacements for `by-memory/-coverage-report.md` if the implementation changes the support pages:

```text
    - [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) 0x005b29c0-0x005b2f68 | class-method-cluster | EmotionInputPane : reconstructable : 87% : strong : B009 2026-06-19 source-quality reanalysis confirms exact constructor `0x005b29c0-0x005b2a70`, virtual input handler `0x005b2a70-0x005b2f68`, constructor callers `0x005a6138`/`0x005a9390`/`0x005b2f38`, vtable-only `OnCharInput` route through `0x0062fa00`, one-character uppercase normalization, non-linear `a-p` selector arithmetic into opcode `0x1d` helper [UID:0001M4], localized `?` help menus through `g_pChattingViewport`/`SystemMessagePane` and `g_pOldSystemMessagePane`/`OldSystemMessagePane`, `g_pLanguageMan` resource ids `31` and `15-30`, `0x108` reopen allocation, and exact `0x005b2f68-0x005b2f70` padding boundary; formal C++ remains deferred to a child method implementation/split.
    - [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) 0x005b2f70-0x005b2fcb | packet-helper | SendEmotionPacket : reconstructable : 87% : very strong : B009 2026-06-19 source-quality reanalysis keeps file-local/static helper placement under [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md); PE/Capstone confirms exact `0x5b` / 91-byte helper, direct callers only at `0x005b2aef`, `0x005b2b15`, and `0x005b2f52` from `EmotionInputPane::OnCharInput`, no pointer-table route, no `ecx` use despite caller setup, packet bytes `{0x1d, selector-0x0b}` with local unsent scratch zero, `PacketBufferWriteUInt8`, `g_packetSender`, and `QueueAndSendPacket(..., 2)` dependencies, plus `0x005b2fcb-0x005b2fd0` padding; ordinary instance-method ownership and opcode `0x0e` chat routing are rejected.
```

If support pages are not changed, do not apply the optional support rows yet; they are included so a later implementation can fix stale by-memory coverage text without re-running the report.

## Final Report-Only Status

Report file created. No `by-*` documentation files and no `by-memory/-coverage-report.md` were edited during this report-only assignment. Notes should record this report path and the pending coverage row text for supervisor review.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00004B-EmotionInputPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00004B"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00004B-EmotionInputPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00004B-EmotionInputPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00004B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
