*** UID:0000NM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SelfSaveInputPane

## Status

- Confidence: very strong for class behavior, hierarchy/layout, constructor/handler/helper/factory source shape, vtable/RTTI disposition, raw boundaries, and packet/resource dependencies; strong for the immediate standalone route, with historical grouping still inferential.
- Current immediate source unit: this file page owns `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`. [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) is only a coordinated future consolidation candidate, not the current owner or destination.
- Proposed reconstruction path: `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`
- Historical recovered artifact: `source-3/simroot_v2/class_SelfSaveInputPane.cpp`; current generated verification uses `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp` and validator metadata, not Wave2/Wave3 output.
- Main address docs: [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md) and [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- Boundary/source-quality status: B007's 2026-06-19 PE recheck corrects the retained raw send helper to [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md); `0x005b68b0` is its `ret`, and padding begins at `0x005b68b1`.
- Constructor/source-quality status: B005's 2026-06-21 source-quality pass resolves [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) as source-ready `SelfSaveInputPane::SelfSaveInputPane()` with first-draft C++ under this file route. It keeps the raw-start/no-direct-caller caveat and final [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) grouping caveat, but these no longer block the constructor child.
- Factory/source-quality status: B012's 2026-06-19 reanalysis resolves [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) as retained file-level `CreateSelfSaveInputPane()` source, returning `new SelfSaveInputPane`. Fresh PE scanning found no rel32 call/jump, absolute VA pointer, or RVA pointer route to `0x005aa140`, so the helper remains liveness-capped but source-authored, not compiler glue.

## File Role

`SelfSaveInputPane` is a `CharInputPane`-derived confirmation prompt. Its constructor looks up `STR.RES` id `0x26` through `g_pLanguageMan`; the current resource text is `Save profile? (Y/N) ` with a trailing space. It asks for one character, accepts only `y` or `Y`, then sends a one-byte packet with opcode `0x25` through the shared packet queue at `dword_67A7EC`.

The class sits in the same command-input neighborhood as spell and block-list prompt classes, so [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains a plausible historical grouping. Current reconstruction keeps this standalone file route because every SelfSave child already has a coherent owner/emitter graph here. Moving only one child is invalid; a future consolidation would have to move the complete unit after independent source-tree evidence.

The retained factory/open body [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) belongs on this file route for the current implementation pass. Best source-facing form is `SelfSaveInputPane *CreateSelfSaveInputPane()` and its first-draft source is `return new SelfSaveInputPane;`. The body has no activation, attach, show, packet, or input-read side effect, so `Create` is stronger than `Open`. Do not move this factory alone to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md); any final move should consolidate this file page, the class page, factory, constructor, confirm handler, retained send helper, vtable data, and vtable-type pages together.

The retained send-only helper is private nonvirtual `SelfSaveInputPane::SendSelfSavePacket()`. Human `OnConfirmInput` source calls it once after validating `y`/`Y`; release optimization inlines its exact send core while retaining the out-of-line definition. The helper's lack of a field read and ordinary binary route remains exact evidence, but Wield's object-call ABI, Wear's retained/inlined parallel, normalized clone identity, and class-local order outweigh the historical file-static inference.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SelfSaveInputPane::SelfSaveInputPane()` constructor body | `0x005b67c0-0x005b67ff`; IDA does not currently model it as a function | Source-ready child that reads `g_pLanguageMan`, calls `LanguageMan::GetLocalizedString(0x26)`, passes the returned `const wchar_t *` to `CharInputPane::CharInputPane`, returns `this`, and installs compiler-emitted primary/secondary/tertiary vptrs at `+0/+0xa0/+0xa4`. The current package maps id `0x26` to `Save profile? (Y/N) `. |
| `SelfSaveInputPane::OnConfirmInput` | `0x005b6800-0x005b686b` | Requires one-character input, accepts `y`/`Y`, and calls `SendSelfSavePacket()` in human source; exact release bytes inline its one-byte opcode `0x25` send core. |
| private `SelfSaveInputPane::SendSelfSavePacket()` | `0x005b6870-0x005b68b1`; raw code, not an IDA function | Retained out-of-line definition with exact frame/base/cookie `0x14/-0x14/-4`, writes offsets `0/1`, explicit redundant byte-one zero, and `g_packetSender->QueueAndSendPacket(packet, 1)`. Highest-probability source is inferred `unsigned char packet[16]`; `[2]` plus exact-toolchain padding remains the bounded runner-up. |
| `CreateSelfSaveInputPane()` retained factory helper | `0x005aa140-0x005aa1bf` | Allocates 264 bytes, constructs the same `CharInputPane`/`SelfSaveInputPane` layout inline, and returns the object. B012's PE scan found no ordinary route to the helper start, but the source shape is clear enough for first-draft `return new SelfSaveInputPane;` C++ under this file route. |

The constructor child should now emit first-draft C++ under this source route:

```cpp
SelfSaveInputPane::SelfSaveInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(kSelfSavePromptStringId))
{
}
```

The class/file support constant is `kSelfSavePromptStringId = 0x26`; final spelling can be replaced by a broader localized-string-id enum if one is established. Do not emit the three vptr stores as source statements.

## Boundary Notes

- `0x005b68c0` starts the block-list input pane neighborhood. Do not extend this file range into [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
- The helper immediately before that boundary ends at `0x005b68b0` with `ret`; only `0x005b68b1-0x005b68c0` is successor alignment. The older statement that the raw helper ended at `0x005b68af` followed by sixteen `0xcc` bytes was one byte short.
- The shared sender at `0x0067a7ec` is accepted as `Socket *g_packetSender`; SelfSave source uses member syntax `g_packetSender->QueueAndSendPacket(packet, 1)`. Historical generated `CashShopRequest *`, `void *`, and free-function aliases remain rejected lead material.
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) is related by feature name but currently has a separate, far earlier `TextBoxPane` island and polluted generated ownership. Do not merge the two solely by name.

## IDA MCP Evidence

2026-05-25 recheck using current `simroot_v2` plus IDA MCP:

- `lookup_funcs` still reports `0x005b67c0` and `0x005b6870` as `Not a function`; raw disassembly confirms complete constructor/send-helper bodies.
- `lookup_funcs` confirms `0x005b6800` as `sub_5B6800` with size `0x6c` and `0x005aa140` as `sub_5AA140` with size `0x80`.
- `callers` reports no direct callers for `0x005b6800`, `0x005b6870`, or `0x005aa140`; `xrefs_to 0x005b6800` reports the vtable data ref at `0x00630608`.
- `dword_67A7EC` has 489 IDA xrefs, with SelfSave-local uses at `0x005b6845` and `0x005b688b`, confirming the sender global is broad network state rather than SelfSave-owned storage.

2026-05-26 recheck using current `simroot_v2` plus IDA MCP:

- Active `class_SelfSaveInputPane.cpp` still emits only the constructor and `OnConfirmInput`; the raw send helper at `0x005b6870` and factory/open helper at `0x005aa140` remain absent from the active source view.
- `lookup_funcs`, `callers`, and `xrefs_to` results are unchanged: `0x005b67c0` and `0x005b6870` are still not modeled functions, `0x005b6800` remains a `0x6c`-byte function with only the vtable data ref, and `0x005aa140` remains a `0x80`-byte function with no direct callers.
- IDA MCP `disasm` reconfirmed the raw helper at `0x005b6870` writes opcode `0x25`, appends a zero byte, and queues one byte through `dword_67A7EC`. B007's later PE recheck corrects the half-open range to `0x005b6870-0x005b68b1`.
- IDA MCP `py_eval` reconfirmed 489 xrefs to `dword_67A7EC`.

2026-06-02 recheck using IDA MCP only:

- `lookup_funcs` reports `0x005aa140` as `sub_5AA140`, size `0x80`, ending at `0x005aa1c0`; `0x005aa1c0` itself is not a function.
- `decompile 0x005aa140` shows allocation of `264` bytes, localized string lookup id `38` (`0x26`), `CharInputPane` construction, and three `SelfSaveInputPane` vtable writes.
- `xrefs_to` for `0x006305c0`, `0x00630610`, and `0x00630640` reports factory stores at `0x005aa196`, `0x005aa19c`, and `0x005aa1a6`, plus raw constructor stores at `0x005b67df`, `0x005b67e7`, and `0x005b67f1`.
- `callers` still reports no direct callers for `0x005aa140`, `0x005b67c0`, `0x005b6800`, or `0x005b6870`; `0x005b6800` remains reachable through the vtable data slot at `0x00630608`.
- Raw byte reads show `0x005b67c0-0x005b67ff` as a constructor-shaped body, `0x005b6800-0x005b686b` as the modeled input handler, and a raw send helper at `0x005b6870`. The written `0x005b6870-0x005b68af` helper-end wording was stale; B007's PE recheck proves `0x005b68af` is `pop ebp`, `0x005b68b0` is `ret`, and only `0x005b68b1-0x005b68c0` is `0xcc` alignment before the next neighborhood at `0x005b68c0`.

2026-06-14 C001 recheck using live IDA MCP session `b001_0003gy`:

- `lookup_funcs` still reports `0x005b67c0`, `0x005b6870`, `0x005b68b0`, `0x005b68c0`, and `0x005aa1c0` as not functions; `0x005b6800` remains a `0x6c`-byte modeled input handler, and `0x005aa140` remains a `0x80`-byte factory/open helper.
- `analyze_component` confirms `0x005b6800` calls the same packet/text helper set recorded by earlier audits plus the security-cookie check, while `0x005aa140` calls allocation/base-pane construction helpers and writes the same vtable family.
- `xrefs_to 0x005b6800` reports only the vtable data ref at `0x00630608`; the raw constructor, raw send helper, and factory/open helper still have zero xrefs to their exact starts.
- `xrefs_to` for vtable heads `0x006305c0`, `0x00630610`, and `0x00630640` reports the paired factory stores at `0x005aa196`, `0x005aa19c`, and `0x005aa1a6`, plus raw constructor stores at `0x005b67df`, `0x005b67e7`, and `0x005b67f1`.
- `entity_query` confirms the `SelfSaveInputPane` primary/secondary/tertiary vtable names at `0x006305c0`, `0x00630610`, and `0x00630640`, followed immediately by the `BlockListenInputPane` successor vtable at `0x0063064c`. `xrefs_to 0x0067a7ec` still shows broad packet-sender usage with more than the first 100 refs, so the sender remains shared client network state.

## 2026-06-19 B012 Factory Source-Quality Recheck

- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) is best modeled as retained source helper `CreateSelfSaveInputPane`, not a class method, compiler glue, LivingObject/UserPane artifact, or generic input-pane helper.
- The helper allocates `0x108` bytes through [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md), reads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), calls `LanguageMan::GetLocalizedString(0x26)`, calls [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), installs primary/secondary/tertiary SelfSave vptrs, and returns the constructed pointer or null on allocation failure.
- Fresh PE route scan found no rel32 call/jump, absolute VA pointer, or RVA pointer to `0x005aa140`. Positive controls found the [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) vtable pointer at `0x00630608`, 50 rel32 calls to [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), and 1,785 rel32 calls to the operator-new wrapper, so the missing route is a real liveness caveat.
- The `0x26` localized prompt id maps to `Save profile? (Y/N) ` in current [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md). Keep the literal as resource evidence; source should use `kSelfSavePromptStringId` or a future localized-string enum in the constructor path.
- Keep this file as the immediate owner/emitter for [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md). [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains the likely final source consolidation destination, but only as a coordinated move for [UID:0000NM], [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md), [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md), [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md), [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md), [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md), [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md), and [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md).

## 2026-06-21 B005 Constructor Source-Quality Recheck

- Exact constructor range [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) is `0x40` bytes, unique in the checked PE, starts after predecessor `ret 4`, and is followed immediately by [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md).
- Whole-image route scan found no direct branch or VA/RVA/raw pointer route to `0x005b67c0`; this remains a confidence cap and raw-liveness caveat, not a no-code reason.
- The constructor loads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), pushes id `0x26`, calls `0x004f0350`, passes the returned string to [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), writes SelfSave vptrs at `0x005b67df/0x005b67e7/0x005b67f1`, and returns `this`.
- Read-only `STR.RES` extraction from `baram.dat` maps zero-based id `38` / `0x26` to `Save profile? (Y/N) `. Source should use symbolic id `kSelfSavePromptStringId` or a future enum, not hard-code the English text.
- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) duplicates the same construction sequence after `0x108` allocation and EH setup, but still has no direct caller route; keep it as a separate factory/open-helper candidate.
- Rejected direct source owners for the constructor are `InputPanes`, `BlockListenInputPanes`, `ItemActionInputPanes`, `SelfSaveOKPane`, `MapPane`, `LanguageMan`, and `g_packetSender`. [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains only a coordinated final grouping candidate.
- Generated names such as `ctor_0x5b67c0`, `FUN_005b67c0`, control-character `SelfSaveInputPane\r`, raw vtable labels, and documentation slug names should remain quarantined from source-facing C++.

## Historical 2026-06-19 B007 Source-Quality Recheck

The exact range, packet behavior, and no-route scans below remain valid. Its file-static/no-call source conclusion is evidence-time history superseded by the B004 source-family and clone analysis.

- The raw helper's correct half-open range is `0x005b6870-0x005b68b1`. The byte at `0x005b68b0` is the helper `ret`, not padding.
- The helper writes opcode `0x25` through `PacketBufferWriteUInt8`, clears non-transmitted `packet[1]`, loads [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and calls `QueueAndSendPacket(g_packetSender, packet, 1)`.
- The helper reads no input, no `this`, no `SelfSaveInputPane` fields, no localized strings, and no feature state. This supports file-local `static void SendSelfSavePacket()` as the best source-facing shape.
- Whole-image PE scanning found no rel32 call/jump/conditional branch, no absolute VA pointer, no RVA pointer, no raw-offset pointer, and no pointer to any byte in the corrected helper range. Positive controls found the [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) vtable route and 489 `g_packetSender` references.
- [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) already sends opcode `0x25` inline after `y`/`Y` validation. Do not force a call to [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) without route evidence.
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains the likely final source consolidation file, but only as a coordinated move for [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md), [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md), [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md), [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md), [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md), [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md), [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md), and [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md).

## Historical 2026-07-13 B002 UID0002N8 Complete Source Unit Callback

The hierarchy, compiler-ABI disposition, constructor/factory facts, standalone route, and deterministic order below remain current. Its file-static helper and duplicate-handwritten active-source conclusions are superseded by the B004 reconciliation after this subsection.

The older 2026-06-19 statements that called CommandInputPanes the likely final consolidation file are retained above as evidence-time history. They do not override the current immediate standalone route. This by-file root remains metadata/prose only and must not receive `RECONSTRUCTION_CPP`, owner-emitter child metadata, or a formal block; its ordinary class/by-memory/by-vtable children supply generated C++.

The complete deterministic output for `NexusTK/ui/dialogs/SelfSaveInputPane.cpp` is:

| Position | UID | Exact source role |
| --- | --- | --- |
| `0` | [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | `CharInputPane`-derived class declaration, new `virtual OnConfirmInput`, prompt-id constant, and `[[CHILDREN]]` |
| `10` | [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) | accepted constructor using localized resource id `0x26` |
| `20` | [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) | active vtable-routed one-character confirmation body |
| `30` | [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) | retained private nonvirtual packet-member definition |
| `40` | [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) | compiler-generated exact-data disposition marker |
| `50` | [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) | source-local vtable-index/no-duplicate marker |
| `60` | [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) | retained file-level factory returning `new SelfSaveInputPane` |

### Class, Layout, And Generated ABI

RTTI proves `SelfSaveInputPane -> CharInputPane -> LineInputPane -> Pane`, the GrafPort/LObject primary chain, EventHandler at object offset `+0xa0`, and TimerHandler at `+0xa4`. Factory allocation is `0x108`; no SelfSave-specific persistent field is written, so no reserve member is added.

Exact UID0002N8 is one `0x88`-byte cluster: 19 primary slots, an internal EventHandler COL and 11 slots, an internal TimerHandler COL and two slots. Constructor/factory stores install bases `0x006305c0`, `0x00630610`, and `0x00630640`. The active handler occupies primary slot `+0x48` at `0x00630608 -> 0x005b6800`; base tables end at `+0x44`, so the class uses new period-plausible `virtual void OnConfirmInput();`, not superseded compile-invalid `override`.

The scalar deleting destructor `0x005b7940`, adjustors `0x005b77c8/0x005b77d3`, all fixed vtable slots, and RTTI locator cells are compiler ABI. The source unit must not contain an explicit destructor body, thunk, raw vptr write, literal vtable array, or RTTI record. UID0002N8/UID0003HM markers document this without leaving an Empty Emitter Marker.

### Constructor, Confirmation, Helper, And Factory Behavior

The constructor obtains [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) id `0x26` / decimal `38` through `g_pLanguageMan`; current text is `Save profile? (Y/N) ` including trailing space. It passes the returned `const wchar_t *` to `CharInputPane` and relies on the compiler for all three vptr stores.

Exact release behavior requires text length one, copies one `wchar_t`, accepts only `L'y'`/`L'Y'`, then executes the inlined opcode `0x25`, byte-one clear, and length-one Socket send. Human source uses one helper call. It has no sender null check, parse branch, close/reset side effect, or second sent byte.

The retained helper definition reads no input or object field and has no ordinary route, but same-family member ABI and exact normalized duplicate evidence make private nonvirtual membership highest probability. The retained factory remains separate file-level `CreateSelfSaveInputPane` source with no activation/show/input/send side effect and no ordinary route.

### Ownership, Negatives, And Score

This file page is the immediate source route and file owner for UID0000CW and UID0001KQ. UID0000CW is semantic owner/emitter for constructor, active method, retained helper, UID0002N8, and UID0003HM. Broad method/vtable aggregates and shared adjustor pages remain non-emitting. Resource, LanguageMan, packet sender, packet helpers, InputPanes, BlockListen, ItemActionInputPanes, and SelfSaveOKPane are dependencies/adjacency only.

No direct route reaches raw constructor/helper/factory starts; this caps confidence without reclassifying coherent source bodies. No target padding, source-authored table constant, added class field, explicit destructor, or evidence for a partial file move exists. The source helper call is an inference validated by clone/family evidence rather than an observed release call instruction.

The B002 score at that evidence time was `89/91`; current file score is `91/92` after resolving private-helper source shape, call/inlining, provider syntax, and packet-layout ranking.

## 2026-07-13 B004 Complete Source Unit Reconciliation

The current deterministic output order remains `0/10/20/30/40/50/60`: class declaration, constructor, active handler, retained private member definition, generated-binary marker, vtable-index marker, and retained factory. Source has one private declaration, one `OnConfirmInput` call, and one out-of-line definition. Exact release output retains the UID0003O7 definition and inlines its 35-byte send core into UID0003O6; after only rel32 normalization both cores hash to `3844f03d9ccc79066d190bb05f2908454eeaaee2844c1b056762124a3f57b093`.

UID0003O7's exact binary tuple is frame/base/cookie `0x14/-0x14/-4`, with packet offsets `0/1` touched and send length one. `unsigned char packet[16]` is the selected inferred source form because the closest x86 MSVC control reproduces that tuple only for `[16]`; same-binary smaller-array controls and lack of the exact 14.16 compiler preserve `packet[2]` plus exact-toolchain padding as the bounded runner-up. Source uses value-first `PacketBufferWriteUInt8(0x25, packet)`, preserves the explicit redundant byte-one zero, and calls `Socket *g_packetSender` with member syntax.

All compiler ABI remains generated: no explicit destructor, adjustor, vptr store, vtable array, RTTI record, or duplicate active packet body. Provider, SelfSaveOKPane, BlockListen, generic InputPanes, and partial CommandInputPanes ownership are rejected. Constructor/factory/helper no-route evidence, prompt id `0x26`, no added class field, exact padding, and historical standalone-versus-broader grouping remain explicit.

Completion `91` records complete contents/order, source call/definition relation, exact binary layout, class/vtable/factory dispositions, providers, rejected alternatives, and confidence caps. Confidence `92` reflects exact clone and family agreement while retaining caps for stripped names, no ordinary target route, inferred array capacity, and unrecoverable historical translation-unit grouping.

## Cross-References

- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md)
- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md)
- [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md)
- [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-06-14 C001 confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:82`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP session `b001_0003gy` reconfirmed the raw constructor/helper non-function boundaries, modeled handler/factory sizes, vtable-only handler reachability, paired factory and raw-constructor vtable stores, the `BlockListenInputPane` successor boundary, and broad shared packet-sender usage. Confidence remains capped at `85` because the final source grouping is still more likely [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) than a standalone file, and the raw helper relationship is not directly called.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `76`.
  - Evidence: document covers prompt behavior, proposed ownership, raw constructor/send helper, factory/open helper, packet-sender dependency, boundary notes, two IDA rechecks, and cross-references; confidence is capped by raw unmodeled starts and final grouping under command input panes.
- 2026-06-02: Raised to `86/82` and added `NexusTK/ui/dialogs/` reconstruction path.
  - Evidence: fresh IDA MCP confirms the exact factory/open helper, current vtable-store map, no direct caller state, vtable-only handler reachability, and raw byte boundaries for the constructor/helper island.
- 2026-06-19 Agent-B007 implementation:
  - Scores remain `86/85`.
  - Updated the raw helper range from `0x005b6870-0x005b68b0` to `0x005b6870-0x005b68b1`, corrected the `ret`/padding split, recorded `SendSelfSavePacket()` as the best file-local source shape, preserved the no-route caveat with PE-scan positive controls, and kept [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) as a future coordinated consolidation candidate rather than moving only the retained helper.
- 2026-06-21 Rule 26 B005 incorporation:
  - Scores changed from `86/85` to `87/87`.
  - Added constructor first-draft C++ readiness, prompt id/text mapping, exact route-negative constructor evidence, matching factory-construction context, generated-name cleanup, and rejected-owner/source-placement alternatives. The remaining file-level blockers are handler/helper/factory final names and coordinated source grouping, not the constructor source shape.
- 2026-06-21 Rule 26 B012 incorporation:
  - Scores remain `87/87`.
  - Added the factory/open helper source-quality result for [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md): best source name `CreateSelfSaveInputPane`, first-draft `new SelfSaveInputPane` source shape, no ordinary PE route with positive controls, normalized `operator new`/`g_pLanguageMan`/`LanguageMan::GetLocalizedString`/`CharInputPane::CharInputPane` dependencies, string id `0x26` evidence, and coordinated `CommandInputPanes` consolidation guidance.
- 2026-07-13 Agent-B002 UID0002N8 callback: raised `87/87 -> 89/91`, retained the standalone immediate route, documented exact positions `0/10/20/30/40/50/60`, complete class/layout/constructor/confirm/helper/factory behavior, generated vtable/RTTI/destructor dispositions, no-route and rejected ownership evidence, and historicalized CommandInputPanes as coordinated future work. No by-file reconstruction metadata was added.
- 2026-07-13 Agent-B004 UID0003O7 callback: raised `89/91 -> 91/92`, retained the standalone route and full position order, replaced stale file-static/free-sender/duplicate-source conclusions with a private member definition and active source call, preserved optimized inline bytes, added ranked `[16]` versus `[2]`-plus-padding evidence, and retained all constructor/factory/vtable/no-route/grouping facts.
