*** UID:0000C4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SayToGroupMessageInputPane : public LineInputPane
{
public:
    explicit SayToGroupMessageInputPane(const wchar_t *groupName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_groupName[128];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- Score is `93/94` after exact constructor/submit, `m_groupName[128]` at `+0x108`, vtable, packet, header, and source-route closure. Deterministic emitter position is `30`.
- The class declaration now belongs only in formal H; formal CPP is `[[CHILDREN]]`, so UID0001LZ definitions emit at namespace scope. Shared adjustor/scalar wrappers provide compiler destruction and do not justify an explicit derived destructor.

# SayToGroupMessageInputPane

## Status

- Confidence: strong for behavior, vtable submit evidence, packet layout, and direct class ownership of the exact memory child; medium-high for final file/source split.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), cross-referenced from [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- Historical generated/recovered file: `source-3/simroot_v2/class_SayToGroupMessageInputPane.cpp`; current source placement is the shared `NexusTK/social/SayInputPanes.cpp/.h` formal route.
- C++ reconstruction: declaration-only class shell with `[[CHILDREN]]`; exact constructor/submit body evidence and first-draft method C++ live on [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md), where `OnSubmitInput()` now serializes the opcode `0x19` group/message packet inline.

## Class Purpose

`SayToGroupMessageInputPane` is the group-chat line input pane. It stores the destination group name, prompts with `Group => `, validates and sanitizes the wide input text, converts group name and message to multibyte strings, and sends an opcode `0x19` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToGroupMessageInputPane` | `0x005b1ec0-0x005b1f7e` | Initializes line input, stores group name, installs primary/secondary/tertiary vtables, and sets prompt text. |
| `OnSubmitInput()` / `SendGroupMessage` | `0x005b1f80-0x005b2152` | Validates/sanitizes the pending line text, converts the stored group name and message, writes the length-prefixed opcode `0x19` payload inline, writes a local-only terminator, and sends through `g_packetSender`. `SendGroupMessage` is an accepted behavioral role label; `OnSubmitInput()` is the vtable/source callback role. |

## Evidence Notes

- 2026-06-13 live IDA MCP session `a001_goal2_0002UM` confirms constructor `sub_5B1EC0` at `0x005b1ec0`, size `0xbe` / 190 bytes (Verified with int_convert.py), and submit method `sub_5B1F80` at `0x005b1f80`, size `0x1d2` / 466 bytes (Verified with int_convert.py). `0x005b2152` is not a function; the next target-message constructor starts at `0x005b22d0`.
- `xrefs_to 0x005b1ec0` reports no direct references. `xrefs_to 0x005b1f80` reports one data xref from vtable slot `0x0062f85c`, and `search_text` renders the submit start as `.rdata:0062F85C` data-referenced rather than directly called.
- Constructor decompilation stores the class vtables at offsets `+0x00`, `+0xa0` / 160, and `+0xa4` / 164 (Verified with int_convert.py), copies the destination group name to `this+0x108` / 264 (Verified with int_convert.py) using a `0x80` / 128-wide-character bound (Verified with int_convert.py), and formats the `Group => ` prompt through the shared prompt helper.
- Submit decompilation reads pending line text, calls the password-disclosure guard `0x00465890`, filters/sanitizes the wide message through `0x005957c0`, converts group name and message with `WideCharToMultiByte`, writes opcode `0x19` / 25 (Verified with int_convert.py), length-prefixes both converted strings, range-checks the combined payload against `0x12c` / 300 bytes (Verified with int_convert.py), and sends through `dword_67A7EC` via `0x00574bb0`.
- `xrefs_to 0x00630a44` shows `Group => ` used by the mode dispatcher `0x005a5110`, the group open helper `0x005a5570`, and this constructor at `0x005b1f38`. `xrefs_to 0x00630a58` shows the neighboring `Clan => ` prompt routed to `SayToPlanMessageInputPane`, supporting the group-vs-plan sibling boundary.
- Behavior is group-specific, but address locality, shared target-message opcode `0x19` packet shape, and the dispatcher/open-helper prompt/vtable refs place the class in the broader `Say*InputPane` source family. [UID:0000JS][Group](by-file/Group.md) remains a feature cross-reference, while [UID:00005W][GroupInputPane](by-class/GroupInputPane.md) is a separate command-input class that sends opcode `0x2e`.
- 2026-06-19 B001 aggregate reanalysis confirms the preceding sibling [UID:000404][0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB](by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md), padding `0x005b1eb3-0x005b1ec0`, following padding `0x005b2152-0x005b2160`, and following sibling [UID:000405][0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC](by-memory/0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md). Those helpers are not part of this class.
- 2026-06-26 B006 current MCP session `80de0a67` reconfirmed constructor `0x005b1ec0` size `0xbe` / 190 bytes and submit `0x005b1f80` size `0x1d2` / 466 bytes (Verified with int_convert.py), submit vtable slot `0x0062f85c`, zero direct constructor xrefs, `Group => ` prompt refs at dispatcher/open-helper/constructor sites, `m_groupName[128]` at `this+0x108`, password guard `0x00465890`, sanitizer helper `0x005957c0`, conversion caps `0x100`, packet cap `0x12c`, local-only terminator, and send through `dword_67A7EC` / `g_packetSender`.
- B006 also reconfirmed negative helper evidence: `lookup_funcs` reports no function objects at adjacent starts `0x005b1d50` and `0x005b2160`, `xrefs_to` returns zero for both starts, and `OnSubmitInput()` serializes the packet inline rather than calling either no-route helper clone.

## Assignment Gate

| Item | Score | Gate decision |
| --- | --- | --- |
| This class | `88/91` | Clears the strict child side after the 2026-06-13 IDA MCP refresh, 2026-06-20 B001 incorporation, and 2026-06-26 B006 source-quality pass documented boundaries, vtables, prompt refs, touched state, packet layout, inline method-body C++ placement, source-family routing, declaration-level C++, and neighboring helper exclusions. |
| Direct file parent [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) | `88/87` | Clears the strict parent side and remains the strongest source-file owner for the say/shout/whisper/group/plan target-message input family. |
| Feature cross-reference [UID:0000JS][Group](by-file/Group.md) | `89/85` | Also clears the gate, but its own notes identify `SayToGroupMessageInputPane` as feature-related rather than the best direct file owner. |
| Related command class [UID:00005W][GroupInputPane](by-class/GroupInputPane.md) | `86/88` | Distinct group-command input; not the direct parent or source-file owner for this group-chat target-message pane. |

Assignment decision: keep `CANONICAL_OWNER:0000N9` and `EMITTER_UIDS:0000N9` for this class, routing the declaration shell through [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). The exact memory child [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) clears the direct-child gate and attaches to this class as the narrower semantic parent. Method-body C++ belongs on that child, not in this declaration-only class page.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- [UID:000404][0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB](by-memory/0x005b1d50-0x005b1eb3.SayTargetMessagePacketHelperNoRouteB.md)
- [UID:000405][0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC](by-memory/0x005b2160-0x005b22c3.SayTargetMessagePacketHelperNoRouteC.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `74/78`.
  - Before: The page was unevaluated despite documenting constructor behavior, message payload construction, and file-placement ambiguity.
  - After: Scored as moderate-high completion and confidence because group-message behavior is strong while final source grouping remains open.
  - Evidence: Existing method notes, IDA MCP function-start evidence, vtable-reference note, and group/say input cross-references support the score.
- 2026-06-02: Attached to `SayInputPanes` and refreshed score to `78/82`.
  - Before: reconstructable/autogen metadata was blank and confidence stayed below the parent-attachment threshold.
  - After: marked reconstructable, attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and added vtable/packet/touched-state evidence from the exact memory page.
  - Evidence: [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) now records refreshed IDA MCP boundary, vtable, decompile, callee, and packet-layout evidence.
- 2026-06-13 A001 Goal 2 class-quality refresh:
  - Before: `78/82`; the class was documented but still below the strict `85/85` target gate and the exact memory child still routed directly to the file parent.
  - After: `86/88`; class parent remains [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) is rerouted to this class as its direct semantic parent.
  - Evidence: live IDA MCP session `a001_goal2_0002UM` reconfirmed function sizes/bounds, no direct constructor xrefs, submit vtable slot `0x0062f85c`, constructor vtable stores, group prompt refs, `this+0x108` destination buffer, opcode `0x19` payload construction, packet send path, and the distinct `GroupInputPane`/opcode `0x2e` command-input separation. Numeric conversions were checked with `tools/int_convert.py`.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `0001LY-SayTargetMessageInputPanes-source-quality.md`:
  - Before: `86/88`, no formal class C++, and surrounding helper/padding context only lived in the aggregate.
  - After: `87/90`, declaration-only class C++ with `m_groupName[128]` at `+0x108`, `OnSubmitInput()` recorded as the callback role beside the accepted `SendGroupMessage` label, and surrounding no-route helper clones/padding are explicitly excluded from class ownership.
  - Evidence: B001 PE/Capstone aggregate pass confirmed the exact neighboring helper/padding spans, vtable slot `0x0062f85c`, prompt refs, packet shape, and [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) source-file ownership with [UID:0000JS][Group](by-file/Group.md) as a feature cross-reference only.
- 2026-06-26 B006 source-quality implementation for [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md):
  - Before: `87/90`, the class still used stale `AUTOGEN_PARENT_UID` wording and the method row did not state that target method C++ now serializes inline.
  - After: `88/91`, current owner/emitter/source-route wording uses `CANONICAL_OWNER:0000N9` / `EMITTER_UIDS:0000N9`, declaration-only C++ remains unchanged, and method-body C++ placement points to [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) with inline opcode `0x19` packet serialization.
  - Evidence: B006 MCP session `80de0a67` reconfirmed constructor/submit sizes, submit vtable data xref `0x0062f85c`, `m_groupName[128]`, prompt refs, packet caps and local terminator, `g_packetSender` send path, and no function/xref/call route to adjacent helper starts `0x005b1d50` or `0x005b2160`.
