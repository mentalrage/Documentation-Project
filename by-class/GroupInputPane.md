*** UID:00005W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GroupInputPane : public LineInputPane
{
public:
    GroupInputPane();

protected:
    virtual void OnConfirmInput();

    static const int kGroupPromptStringId = 0x2f;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GroupInputPane

## Status

- Confidence: very strong for submit behavior, exact raw constructor bytes, source-ready constructor and submit C++, vtable stores/slots, open-helper and dispatcher construction mirrors, command-input placement, and boundary separation from the preceding item-action helper; capped below final because IDA does not model `0x005b5400` as a function and exact original local/helper spellings plus original source-file metadata remain inferred.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), with feature cross-reference to [UID:0000JS][Group](by-file/Group.md)
- Address ranges: raw constructor [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md), submit cluster [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_GroupInputPane.cpp`

## Class Purpose

`GroupInputPane` is a line-input prompt for group-related commands. Its constructor looks up localized prompt id `0x2f` through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) and passes that prompt to the `LineInputPane` base constructor. Its submit handler gates on current text length, copies the current wide input text, converts the text to multibyte bytes, and sends a length-prefixed group command packet with opcode `0x2e`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupInputPane::GroupInputPane()` | [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md) | Source-ready raw constructor body; initializes the `LineInputPane` base with `g_pLanguageMan->GetLocalizedString(kGroupPromptStringId)`. The three vtable stores are compiler output. |
| `OnConfirmInput` | [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) | Source-ready submit body; returns when text length is zero or negative, copies up to `0xff` / 255 wide chars (Verified with int_convert.py), converts through `WideCharToMultiByte(CP_ACP, 0, ...)`, writes opcode `0x2e` / 46 (Verified with int_convert.py) and one-byte encoded length through `PacketBufferWriteUInt8`, copies exactly `encodedLength` payload bytes, writes local-only terminators, and sends exactly `encodedLength + 2` bytes through `g_packetSender->QueueAndSendPacket`. |

## Evidence Notes

- IDA MCP confirms `0x005b5440-0x005b5547` as the submit method with size `0x107` / 263 bytes (Verified with int_convert.py) and reports no modeled function at `0x005b5400`.
- B001 2026-06-25 current MCP session `80de0a67` confirms the raw constructor body at `0x005b5400-0x005b5440` is exactly `0x40` / 64 bytes (Verified with int_convert.py), unique by signature, and bounded by seven bytes of predecessor `0xcc` padding at `0x005b53f9-0x005b5400` and the immediate submit method successor at `0x005b5440`.
- Current disassembly confirms the raw constructor requests prompt id `0x2f` / 47 (Verified with int_convert.py), calls [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md), calls the line-input base constructor at `0x004f1c00`, stores vtables `0x006300d4`, `0x00630124`, and `0x00630154`, returns `this`, and ends with `retn` at `0x005b543f`.
- Current no-route checks report no direct xref to `0x005b5400` and no whole-image VA/RVA pointer hit for the raw start. That no-route state is a confidence cap, not a first-draft constructor C++ blocker.
- `0x005b5440` is referenced by primary vtable slot `0x0063011c`, and the three vtable bases have constructor-local stores plus dispatcher/open-helper stores.
- Current open helper `0x005a9a10` and dispatcher mirror around `0x005a668b-0x005a66e0` both allocate `0x108` / 264 bytes (Verified with int_convert.py), request prompt id `0x2f`, call `0x004f0350` and `0x004f1c00`, and install the same primary/secondary/tertiary `GroupInputPane` vtables. These mirrors prove live construction semantics but do not call the raw start.
- IDA MCP decompilation confirms submit opcode `0x2e` / 46 (Verified with int_convert.py), line-input length/read helpers, `WideCharToMultiByte`, length-prefixed payload assembly, and send through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- 2026-06-28 B009 current MCP session `agent_b009_0002my_20260628` resolves [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) as source-ready `GroupInputPane::OnConfirmInput()` C++: `lookup_funcs` confirms `0x005b5440` size `0x107` / 263 bytes (Verified with int_convert.py), `0x005b5547` is not a function, vtable slot `0x0063011c -> 0x005b5440`, and the callee set is [UID:00035S][0x004f2310-0x004f231b.LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md) `LineInputPaneTextLength`, [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md) `LineInputPaneCopyText`, [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) `GetMemoryMan`, [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) `PacketBufferWriteUInt8`, `WideCharToMultiByte`, [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) `MemoryMan::MemmoveWrapper`, and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) `Socket::QueueAndSendPacket`.
- B009 corrects the stale helper interpretation: raw `0x00516030` is [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) `GetMemoryMan`, not input reset/clear state. The call obtains the MemoryMan singleton used by the later wrapper copy path; feature-level source can model the payload copy as `memmove(...)` while the exact by-memory page preserves the binary helper route.
- The predecessor gap is now separated as item-action padding plus [UID:0003MW][0x005b5390-0x005b53f9.SendGiveGoldPacketRaw](by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md); the Group constructor boundary at `0x005b5400` is therefore exact and not part of `GiveGoldInputPane`.
- Final placement is command/social input code, not item dialogs.

## Assignment Gate

- Child gate: [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md) is `88/91`, and [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) is now `90/92`.
- Parent gate: direct file parent [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) is already `86/86`.
- Assignment decision: this class stays attached to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), and the constructor/submit children stay attached to this class as the narrower direct parent.
- Remaining cap: both constructor and submit method children now carry source-ready first-draft C++. Remaining confidence caps are the raw-constructor no-route/no-function state, inferred original helper/local names, and unresolved original source-file metadata rather than a blank submit-C++ blocker.

## Source Placement And C++ Notes

This class page carries its declaration in the formal H channel and emits only `[[CHILDREN]]` through CPP. The declaration uses period-compatible `virtual void OnConfirmInput();` syntax rather than the later C++11 `override` keyword. The primary vtable slot independently proves virtual dispatch. Method bodies remain on exact by-memory children: [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md) emits the constructor and [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) emits `OnConfirmInput`.

The retained raw constructor has no direct start route, no IDA function object, and no raw-start pointer hit, but current B001 evidence and accepted Say/Shout/SelfSave raw-constructor precedent make that state a confidence cap rather than a no-code proof. The source constructor operation is the `LineInputPane` base initializer using `g_pLanguageMan->GetLocalizedString(kGroupPromptStringId)`. Vtable stores at `this+0`, `this+0xa0`, and `this+0xa4` are compiler output from the class declaration and should not be represented as handwritten source statements.

Rejected direct owners for this constructor/class fact are [UID:0000JS][Group](by-file/Group.md), [UID:000077][LineInputPane](by-class/LineInputPane.md), [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md), [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), packet-sender infrastructure, and the vtable data pages. Those are feature cross-reference, base class, resource lookup, dependency, or compiler-generated data owners, not the direct class owner.

B009's submit pass preserves the same source placement: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) `CommandInputPanes` is still the generated file route; [UID:0000JS][Group](by-file/Group.md) `Group` is feature context only; [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) `g_packetSender`, [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) `QueueAndSendPacket`, [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) packet-buffer helpers, [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) `MemmoveWrapper`, and [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) `GetMemoryMan` are dependencies only; and [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) `SayToGroupMessageInputPane` is the separate opcode `0x19` group-message prompt rather than this opcode `0x2e` command submitter.

## 2026-08-14 RTTI, Layout, And Header Closure

- The complete-object table head is `0x6300d4`; EventHandler and TimerHandler views are `0x630124` and `0x630154`. Their COLs are `0x653334`, `0x653394`, and `0x6533a8`, with PMD offsets `0`, `+0xa0`, and `+0xa4`.
- Type descriptor `0x67a128` carries `.?AVGroupInputPane@@`. CHD `0x653348` has seven exact BCDs in order: `GroupInputPane`, `LineInputPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`.
- The class is exactly `0x108` bytes. The secondary interfaces begin at `+0xa0` and `+0xa4`; no constructor or method accesses a persistent derived field, so no field beyond inherited state is supported.
- Primary slot `0x63011c -> 0x5b5440` proves the protected virtual confirmation method. The Group EventHandler view inherits the base key/text route at `0x63012c -> 0x4f25a0`; the TimerHandler view inherits `0x630158 -> 0x544e90`.
- Shared `0x5b7940`, `0x5b77c8`, and `0x5b77d3` compiler deleting-wrapper/adjustor functions are reused by multiple prompt classes. They disprove a class-specific handwritten destructor or thunk body; no explicit derived destructor is emitted.
- The raw constructor `[0x5b5400,0x5b5440)` remains source-authored despite lacking an IDA function object or raw-start route. It has 20 valid instructions, seven preceding `0xcc` bytes, an exact successor boundary, prompt lookup `0x2f`, base construction, and all three vptr stores. Dispatcher and open-helper inline mirrors reproduce that exact construction path.
- Source order is declaration position `50` in `CommandInputPanes.h`, followed in CPP by constructor child position `10` and confirmation child position `20`. The exact ABI-data and source-local index markers follow at direct positions `70` and `80` after the Post class at `60`.
- The old CPP-contained declaration was a generated-output defect: it left the required `CommandInputPanes.h` declaration absent. Moving the same evidence-backed declaration to H fixes the channel without inventing an additional class or standalone source file.
- Historical uncertainty is retained: the stripped original translation-unit spelling and exact access-label spelling cannot be proven. `CommandInputPanes.h/.cpp` remains the best route from the complete Emotion/Group/Post family; a standalone Group file is rejected without source-path evidence.

## Score Rationale

Completion `91` reflects complete constructor and submit ownership, exact seven-base RTTI and three-view layout, no-field/no-destructor conclusions, formal CPP/H routing, source order, and packet behavior. Confidence `93` reflects agreement between raw bytes, inline construction mirrors, vtable slots, COL/PMD data, and modeled submit behavior. The remaining cap is stripped original source naming/access metadata and the raw constructor's absent direct start route, not unresolved functionality.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md)
- [UID:0000AO][PostInputPane](by-class/PostInputPane.md)

## Changes

- 2026-08-14 Agent-B010 UID0002N6 callback: raised `88/91 -> 91/93`, set direct file position `50`, moved the class declaration from CPP to H, replaced C++11 `override` with period-compatible `virtual` syntax, left CPP as `[[CHILDREN]]`, and added complete seven-base RTTI, `0x108` no-field layout, shared-destructor disposition, raw-constructor closure, source/header order, score rationale, and preserved historical uncertainty.
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: group command input behavior, submit packet format, constructor boundary caveat, vtable evidence, and source placement are documented, but constructor reachability remains medium-confidence. Evidence: `0x005b5440-0x005b5547` memory page, IDA no-function note at `0x005b5400`, vtable family documentation, and command/group cross-references.
- 2026-06-02 IDA MCP refresh:
  - Before: the class stayed at `68/76`, reconstructable metadata was blank, and the constructor was only a projected start caveat.
  - After: raised to `80/84`, marked reconstructable, attached to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), and linked the raw constructor child.
  - Evidence: refreshed memory docs now record the raw constructor bytes, vtable stores, submit method decompile, packet layout, and command-input ownership.
- 2026-06-13 A001 Goal 2 strict-gate refresh:
  - Before: `80/84`, with the class below the direct-parent gate and the submit memory cluster still routed directly to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
  - Changed to: `86/88`, parent unchanged as [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md); [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) now routes to this class.
  - Evidence: live IDA MCP reconfirmed exact constructor bytes/boundaries, no direct raw-start xref, submit method size and packet decompile, `0x0063011c` submit vtable slot, `0x005a9a10` open-helper construction mirror, scalar deleting destructor behavior through `0x005b7940`, and the adjacent give-gold helper split before the Group constructor.
- 2026-06-25 B001 source-quality implementation:
  - Changed to: `87/90` with owner/emitter [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) preserved.
  - Added declaration-only first-draft C++ with `GroupInputPane`, `OnConfirmInput`, `kGroupPromptStringId = 0x2f`, and `[[CHILDREN]]`.
  - Summary/evidence: [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md) now emits first-draft `GroupInputPane::GroupInputPane()` C++; current MCP session `80de0a67` confirms exact raw bytes, prompt id `0x2f`, `g_pLanguageMan->GetLocalizedString`, `LineInputPane` base construction, vtable stores, no-function/no-route confidence cap, open-helper and dispatcher mirrors, submit slot `0x0063011c -> 0x005b5440`, and unique constructor signature. Submit method C++ remains separate work.
- 2026-06-28 B009 submit source-quality implementation:
  - Changed to: `88/91` with owner/emitter [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) and declaration-only class C++ preserved.
  - Summary/evidence: [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) now emits first-draft `GroupInputPane::OnConfirmInput()` C++; current MCP session `agent_b009_0002my_20260628` confirms exact size `0x107` / 263 bytes (Verified with int_convert.py), end boundary `0x005b5547`, vtable slot `0x0063011c`, `TextLength`/`CopyText` calls, corrected [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) `GetMemoryMan`, [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) `PacketBufferWriteUInt8`, [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) payload-copy wrapper, [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) `g_packetSender`, [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) `QueueAndSendPacket`, packet layout `[0x2e, encodedLength, encodedText...]`, and local-only terminators.
