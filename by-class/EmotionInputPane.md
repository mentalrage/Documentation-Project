*** UID:00004B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "CommandInputPanes.h"

static void SendEmotionPacket(int selector);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "InputPanes.h"

class EmotionInputPane : public CharInputPane
{
public:
    EmotionInputPane();
    virtual void OnAccept();
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmotionInputPane

## Status

- Confidence: high for the exact `CharInputPane` inheritance, `0x108` object size, no Emotion-specific persistent field, constructor and `OnAccept` virtual route, three-view ABI, shared compiler-destructor artifacts, static packet helper, and `CommandInputPanes` source route. Original private helper/member spellings and the exact historical translation-unit split remain inferred, which caps the score below 95 without blocking source-ready output.
- Current source route: `NexusTK/ui/dialogs/CommandInputPanes.h` and `NexusTK/ui/dialogs/CommandInputPanes.cpp`, owned by [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
- Address range: [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), helper [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- Vtable page: [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md), split from aggregate [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Historical recovered artifact: `source-3/simroot_v2/class_EmotionInputPane.cpp`; this does not override the current source root or emitter topology.

## Class Purpose

`EmotionInputPane` is the command prompt for choosing an emotion. It formats a localized prompt with the maximum emotion count and handles character input for emotion indices and the emotion menu shortcut.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EmotionInputPane` | `0x005b29c0-0x005b2a70` | Constructs the `CharInputPane`, installs vtables, and formats the prompt. |
| `OnAccept` | `0x005b2a70-0x005b2f68` | Overrides `CharInputPane::OnAccept`, reads one character, lowercases `A-Z`, maps `a` through `p` through the emotion packet helper with exact split `a-l`/`m-n`/`o-p` selector arithmetic, and opens the current/legacy localized emotion menu on `?`; the method body belongs to [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), not this class page. |
| `SendEmotionPacket` | `0x005b2f70-0x005b2fcb` | File-local/static helper called only by `EmotionInputPane::OnAccept`; writes opcode `0x1d` and queues the normalized selector packet. Its forward declaration precedes `[[CHILDREN]]`, while its body is emitted later by [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md). |

## Current B007 Source-Quality Closure

### Inheritance And Object Layout

- The direct source declaration is `class EmotionInputPane : public CharInputPane`. RTTI follows `EmotionInputPane -> CharInputPane -> LineInputPane -> Pane`, with primary `GrafPort -> LObject` ancestry and non-virtual `EventHandler` and `TimerHandler` base views.
- Exact PMDs place `EventHandler` at `+0xa0` and `TimerHandler` at `+0xa4`. Constructor stores install the three class views at object offsets `+0x00`, `+0xa0`, and `+0xa4` from instruction starts `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`.
- The `?` reopen path allocates exactly `0x108` bytes before calling the constructor. That size, the inherited base layout, and the absence of any constructor write beyond inherited state provide no evidence for an Emotion-specific persistent field.
- The class H block therefore declares only the constructor and `virtual void OnAccept()`; it does not invent fields or expose compiler ABI records.

### Virtual And Destructor Policy

- Primary vtable slot `+0x48` at `0x0062fa00` is the sole binary route to `0x005b2a70`. The current base header [UID:00001P][CharInputPane](by-class/CharInputPane.md) declares `virtual void OnAccept() {}`, resolving the source-facing override as `EmotionInputPane::OnAccept` and superseding the historical `OnCharInput` hypothesis.
- No explicit `EmotionInputPane` destructor is emitted. The primary deleting wrapper at `0x005b7940` is shared by 23 prompt classes, and the `-0xa0`/`-0xa4` adjustors at `0x005b77c8`/`0x005b77d3` are likewise shared. No class-specific cleanup body, field cleanup, or size delta supports a handwritten derived destructor.
- Vtables, complete-object locators, RTTI records, deleting wrappers, and adjustor thunks are generated from this class declaration and its virtual set. They are documented by UID0002N4/UID0003HI but are not written as raw C++ arrays or explicit ABI functions.

### Source And Emitter Topology

- Position `0` emits the exact `CommandInputPanes.h` declaration and `CommandInputPanes.cpp` include/forward declaration above. Position `10` emits the constructor and `OnAccept` bodies through UID0001M3; positions `20` and `30` emit explanatory generated-data markers through UID0002N4 and UID0003HI; position `40` emits `SendEmotionPacket` through UID0001M4.
- The static helper is forward-declared before `[[CHILDREN]]` because `OnAccept` calls it before the position-40 definition. This class page owns the declaration and source skeleton only; it deliberately does not duplicate child method/helper bodies.
- A standalone historical `EmotionInputPane.cpp` remains possible but unproven. The current least-invented source route stays under UID0000ID `CommandInputPanes` and does not move unrelated command-input families.

### Current Score Rationale

Completion `91` and confidence `93` reflect exact class hierarchy, object size, three-view layout, canonical virtual identity, implicit-destructor policy, exact formal header/source skeleton, and complete child ordering. The remaining cap is limited to original private spellings and the exact historical translation-unit split; all in-scope ownership, source-placement, code-emission, and empty-emitter questions are resolved.

## Historical Evidence Notes (Names As Recorded At The Time)

The entries below preserve dated evidence and the names used when each pass was performed. Present-tense `OnCharInput` and blank-class conclusions in those dated notes are superseded by the current B007 closure above; their behavioral, address, caller, and byte evidence remains valid.

- IDA MCP confirms both function starts.
- IDA MCP confirms three `EmotionInputPane` vtable views at `0x0062f9b8`, `0x0062fa08`, and `0x0062fa38`, installed by constructor stores at `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`.
- IDA MCP recheck on 2026-05-26 confirms the adjacent packet helper at `0x005b2f70` is only called by `OnCharInput`.
- IDA MCP decompile on 2026-05-26 confirms `OnCharInput` uses the shared one-character input helpers `0x004f2310`/`0x004f2300`, calls `SendEmotionPacket` from `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`, and uses localized string ids `31` plus `15-30` when building the help/menu list.
- IDA MCP refresh on 2026-06-02 confirms constructor callers at `0x005a6138`, `0x005a9390`, and the `?` help/menu reopen path at `0x005b2f38`; `OnCharInput` is reached through vtable data xref `0x0062fa00`.
- IDA MCP confirms two menu-backend branches in `OnCharInput`: when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`, the help/menu path uses [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md) / historical `dword_67ADC4` and helpers `0x005854b0`/`0x005854d0`/`0x00585560`/`0x00585360`; otherwise it uses [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md) / historical `dword_69B4C8` and helpers `0x00589330`/`0x00589350`/`0x00589470`/`0x005892a0`.
- IDA MCP confirms the adjacent alignment spans `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0` are pure `0xcc` bytes, so the class/helper boundary is now proven before `ChangeItemSlotInputPane`.
- IDA MCP recheck on 2026-06-11 against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) confirms the parent gate for [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md): `lookup_funcs` still maps `0x005b29c0` to the constructor size `0xb0`, `0x005b2a70` to `OnCharInput` size `0x4f8`, and `0x005b2f70` to the packet helper size `0x5b`; constructor callers remain `0x005a6138`, `0x005a9390`, and the `?` reopen path at `0x005b2f38`; helper calls remain `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`.
- The same 2026-06-11 vtable scan confirms `0x0062f9b8` primary slot `0x005b7940`, inherited slot `0x004f4b10`, virtual input slot `0x0062fa00 -> 0x005b2a70`, secondary base `0x0062fa08 -> 0x005b77c8`, tertiary base `0x0062fa38 -> 0x005b77d3`, and the next `ChangeItemSlotInputPane` RTTI locator at `0x0062fa40`.
- Wave3 method notes explicitly state the current code override is a struct definition rather than the function body; track this under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- The class belongs with command input panes rather than item action panes.
- 2026-06-26 B006 accepted [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) implementation moves the missing generated handler-body issue to the child page's formal C++ block. Live MCP session `80de0a67` reconfirmed constructor size `0xb0` / `176` (Verified with int_convert.py), handler size `0x4f8` / `1272` (Verified with int_convert.py), virtual slot `0x0062fa00`, constructor callers `0x005a6138`, `0x005a9390`, and `0x005b2f38`, helper calls `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`, and padding `0x005b2f68-0x005b2f70` before [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md). The child target now uses inferred but behavior-backed source names `TextLength()`, `CopyText(...)`, `g_useEpfAssets`, `g_pChattingViewport`, `g_pOldSystemMessagePane`, `AppendHeaderMarker()`, `AppendColoredText(...)`, `AppendFooterMarker()`, `RefreshAndPruneMessages()`, and `m_refreshOnAppend`.

## Historical B009 Source-Quality Incorporation

2026-06-21 Rule 26 incorporation of `Agent-B009/research/00004B-EmotionInputPane-class-source-quality.md` kept the class owner/emitter at [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), kept `RECONSTRUCTABLE:TRUE`, and intentionally kept the class-page C++ blank at that checkpoint. The current B007 closure supersedes only that blank-class conclusion by adding the exact declaration and source skeleton; executable method bodies still belong to the child by-memory pages [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) and [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md).

PE/Capstone route evidence from the B009 report:

- Parsed local `NexusTK.exe` sections map `.text` at VA `0x00401000-0x0060c600` with raw base `0x00000400`; the constructor raw offset is `0x001b1dc0`, and `OnCharInput` starts at raw offset `0x001b1e70`.
- Constructor range is exactly `0x005b29c0-0x005b2a70` (`0xb0` bytes). Direct rel32 callers are `0x005a6138`, `0x005a9390`, and `0x005b2f38`; whole-image absolute dword scan found no pointer-table owner for the constructor start.
- The constructor calls the [UID:00001P][CharInputPane](by-class/CharInputPane.md) setup at `0x004f28a0`, installs vtables `0x0062f9b8`, `0x0062fa08`, and `0x0062fa38` at stores `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`, reads [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), looks up localized prompt id `0x20` / `32`, and passes `0x70` / `112` as the emotion selector count/limit. The `0x70` value is not object size.
- The `?` menu reopen path allocates `0x108` / `264` bytes before calling the constructor again at `0x005b2f38 -> 0x005b29c0`, providing the current best concrete object-size evidence.
- `OnCharInput` range is exactly `0x005b2a70-0x005b2f68` (`0x4f8` bytes). Direct rel32 call scan found no code callers; whole-image absolute dword scan found exactly one pointer to the function start at vtable slot `0x0062fa00`, so the body is virtual/vtable-routed rather than a free helper or direct dispatcher target.
- The one-character input path calls `0x004f2310` and compares the returned `ax` with `1`, then calls `0x004f2300` to copy one UTF-16 character. Uppercase `A-Z` is normalized by adding `0x20` and assigning the normalized value back before the `a-p` range test.
- For letters `a-p`, the handler calls [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) at `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`. The selector is not a single linear `ch - 'a'`: `a-l` passes `ch - 0x56` so the helper sends `0..11`, `m-n` passes `ch - 0x64` so the helper sends `0xfe`/`0xff` if treated unsigned after its own subtraction, and `o-p` passes `ch - 0x58` so the helper sends `12..13`.
- The `?` path appends a localized emotion menu through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), resource id `31` (`0x1f`) with parameters `4` and `0x24`, then ids `15-30` (`0x0f-0x1e`) with parameters `0x84` and `0x24`.
- The current/new branch (`g_useEpfAssets == 1`) uses [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md), clears byte `[g_pChattingViewport + 0x130]`, then calls the SystemMessagePane helper family at `0x005854b0`, `0x005854d0`, `0x00585560`, and `0x00585360`.
- The legacy branch (`g_useEpfAssets != 1`) uses [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md), clears byte `[g_pOldSystemMessagePane + 0x130]`, then calls the OldSystemMessagePane helper family at `0x00589330`, `0x00589350`, `0x00589470`, and `0x005892a0`.
- The helper [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) is `0x005b2f70-0x005b2fcb` (`0x5b` bytes), has no pointer-table route, has direct callers only from `OnCharInput`, returns with `ret 4`, and does not read the incoming `ecx` receiver. This supports file-local/static helper placement under `CommandInputPanes`, not ordinary instance-method ownership.
- The helper sends opcode `0x1d`, not opcode `0x0e`; `0x0e` belongs to the adjacent ChatInputPane family. It writes `{0x1d, selectorArgument - 0x0b}` into a source-shaped `unsigned char packet[128]` local scratch buffer, leaves `packet[2]` as a local unsent zero scratch/terminator, then calls [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) with send length `2`. The earlier `packet[3]` helper draft was behavior-equivalent for the sent bytes but is superseded by [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)'s 2026-06-26 stack-frame audit and formal C++ block.
- Padding spans `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0` remain confirmed `0xcc` alignment, not source-authored code.

Rejected source-placement and ownership alternatives:

- `PacketBuffer.cpp`, `Socket.cpp`, and central protocol send code are dependencies only. They own `PacketBufferWriteUInt8`, `g_packetSender`, and queue/send support; they do not own the feature opcode helper.
- `SystemMessagePanes.cpp` owns display/list helper mechanics, not the Emotion input command logic or packet route.
- `Chatting.cpp` and ChatInputPane are rejected because this path sends opcode `0x1d` through the Emotion helper, not ChatInputPane opcode `0x0e`.
- A future standalone `EmotionInputPane.cpp` split remains plausible, but current evidence does not prove the split; `CommandInputPanes.cpp` remains the least-invented source route.

Historical class-page no-duplicate-body proof: the executable constructor/then-named `OnCharInput` method cluster belongs to UID0001M3, and the packet helper body belongs to UID0001M4. That ownership remains correct. The historical conclusion that it required a completely blank class formal channel is superseded: this page now emits only the class declaration, include, helper forward declaration, and `[[CHILDREN]]` skeleton, never duplicate method bodies.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md)
- [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)

## Changes

- 2026-06-07 A008 alias cleanup: normalized the `OnCharInput` `byte_66DA97` menu-backend branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/74`.
  - Summary/evidence: prompt role, constructor, `OnCharInput` behavior, private packet helper, vtable stores, localized menu behavior, and missing emitted-body issue are documented; confidence remains limited because active generated output still lacks the real `OnCharInput` body.
- 2026-06-02 IDA MCP refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
  - Why: exact constructor/handler/helper ranges, constructor callers, vtable slot evidence, menu-mode branches, packet helper ownership, and padding boundaries are documented. C++ remains blank because final source names and menu object types are not final-source quality.
- 2026-06-11 A003 vtable-data parent-gate refresh:
  - Before: `82/84`, which left the exact [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md) child unassigned under the corrected `85/85` gate.
  - After: `85/86`, based on a fresh IDA recheck of constructor/handler/helper bounds, constructor and helper xrefs, three vtable bases, key slot dwords, and the next-class boundary.
  - Evidence: the new 2026-06-11 notes confirm this class is the direct owner of the emitted Emotion vtable data, while final C++ remains blank because generated `OnCharInput` output and final menu object names are not source-quality.
- 2026-06-12 A004 Batch 313 cross-reference update: added [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md) as the source-local reconstructable vtable page for this class. Scores stay `85/86`; the direct-parent gate was already closed by the 2026-06-11 evidence.
- 2026-06-21 Rule 26 B009 source-quality incorporation:
  - Before: `85/86`.
  - After: `87/89`.
  - Summary/evidence: incorporated PE/Capstone range and route scans, exact constructor/object-size/prompt facts, vtable-only `OnCharInput` route, resolved `g_pChattingViewport` and `g_pOldSystemMessagePane` menu branches, non-linear selector arithmetic, packet helper opcode `0x1d`/static-helper conclusion, rejected owner routes, padding boundaries, and class-page no-code proof. Formal class C++ remains blank because child by-memory pages own the executable bodies.
- 2026-06-26 B009 SendEmotionPacket support sync:
  - Scores remain `87/89`.
  - Synced [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) after accepted implementation callback: the helper's formal C++ now uses a source-shaped `packet[128]` local scratch buffer while still sending only two bytes; the prior `packet[3]` shape is historical behavior-equivalent draft evidence, not the current source-shaped helper body.
- 2026-06-26 B006 EmotionInputPane child C++ support sync:
  - Before: `87/89`.
  - After: `88/90`; class owner/emitter [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) and blank class formal C++ are preserved.
  - Summary/evidence: [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) now carries first-draft constructor/`OnCharInput` method-cluster C++ with exact `a-l`/`m-n`/`o-p` selector arithmetic, current/legacy `?` menu branches, and behavior-backed SystemMessagePane/OldSystemMessagePane helper names. The class page remains declaration/layout/inventory only.
- 2026-08-02 B007 UID0002N4 implementation callback:
  - Before: `88/90`, blank formal H/CPP and position, current prose used `OnCharInput`, and the B009 no-duplicate-body conclusion had been overextended into a blank-class conclusion.
  - After: `91/93`, position `0`, exact `EmotionInputPane : public CharInputPane` H declaration, exact CPP include/static-helper-forward/`[[CHILDREN]]` skeleton, canonical `OnAccept`, complete `0x108`/PMD/no-field evidence, explicit implicit-destructor policy, and ordered child source route without duplicated bodies.
