*** UID:0000EC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TakeOffInputPane : public CharInputPane
{
public:
    TakeOffInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void ProcessUnequipCommand();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TakeOffInputPane

## Status

- Confidence: very strong for current MCP-backed behavior, method split, packet helper dependency, vtable identity, and module placement; raw-constructor reachability, event-field naming, command helper naming, and final shared-helper declaration/header placement remain documented caveats rather than blockers for class ownership.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md), [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md), exact method child [UID:0004TB][0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut](by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md), helper [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md), and command child `0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`.
- Historical generated source lead, not used as authority for this page: `source-3/simroot_v2/class_TakeOffInputPane.cpp`

## Class Purpose

`TakeOffInputPane` is the equipment-removal command prompt. It supports a shortcut path, single-slot unequip, and an all-equipment `A` path that iterates a fixed equipment slot list. The source-facing slot-key declaration is now carried by [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) as `static const wchar_t g_equipmentSlotKeys[23]`; this class consumes that table but does not own it as instance state or a proven class-static member.

## Method And Helper Notes

| Method | Address | Role |
| --- | --- | --- |
| `~TakeOffInputPane` | `0x004f2010-0x004f2092` | Destructor/reset path for base line-input state. |
| `TakeOffInputPane` | [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) | Formal first-draft `TakeOffInputPane::TakeOffInputPane()` C++ is now present. The retained raw body has prompt id `0x22` / 34 (Verified with `int_convert.py`), `g_pLanguageMan->GetLocalizedString`, `CharInputPane::CharInputPane(const wchar_t *)` base construction, and three compiler-emitted vtable stores; no direct raw-start route remains documented. |
| `HandleKeyOrTextEvent` | [UID:0004TB][0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut](by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md) | Exact class virtual Event handler. It translates `event->m_payload.m_key.m_key` with `event->m_payload.m_key.m_modifiers`, recognizes translated `?` only with `kEventModifierShift` and `kEventKeyDown`, sends the shortcut packet opcode `0x2d` / 45, returns `true`, and otherwise delegates to `CharInputPane::HandleKeyOrTextEvent(event)`. |
| `SendTakeOffPacket` | `0x005b27c0-0x005b2827` | Free/file-level helper [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md), best current signature `void SendTakeOffPacket(char equipmentSlotSelector)`, that sends opcode `0x1f` / 31 (Verified with `int_convert.py`) with a one-based selector byte; called by this class only from the uppercase `A` all-equipment branch, while typed single-slot removal scans [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) `g_equipmentSlotKeys` and emits the same packet inline. |
| `ProcessUnequipCommand` | `0x005b2830-0x005b296b` | Exact class virtual submit/command method. Handles one-character input, the uppercase `A` all-equipment path, or slot-key unequip opcode `0x1f`; its independent source body is retained outside this Event-contract repair. |
| `ScalarDeletingDestructor` | `0x005b7940-0x005b797b` | Delete wrapper around the destructor. |

## Evidence Notes

- IDA MCP confirms the destructor, shortcut handler, command handler, two thunks, and scalar deleting destructor.
- 2026-06-12 A001 read-only IDA MCP recheck confirms `lookup_funcs` still reports no function at `0x005b26e0`, while raw instruction query over `0x005b26e0-0x005b2720` decodes exactly 20 instructions. The body loads `dword_67A750`, pushes prompt id `0x22`, calls `0x004f0350`, calls [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), and installs vtables `0x0062f92c`, `0x0062f97c`, and `0x0062f9ac`.
- The same recheck found no direct xrefs to `0x005b26e0` and no `E0 26 5B 00` little-endian raw pointer matches. That keeps the raw-start caveat explicit, but does not weaken class ownership because the identical vtable/prompt/base-constructor sequence is present in the inline command factory.
- IDA decompiles command factory `0x005aa0c0` as an inline construction path: allocate `0x108` / 264 bytes (Verified with `int_convert.py`), request localized prompt id `34`, call `CharInputPane` construction, then store the same three `TakeOffInputPane` vtables at `0x005aa116`, `0x005aa11c`, and `0x005aa126`.
- Fresh vtable xrefs show each of the three `TakeOffInputPane` table bases has exactly three data refs: raw constructor stores, `0x005aa0c0` factory stores, and the large `UserPane` command dispatcher stores at `0x005a6ca4`, `0x005a6cac`, and `0x005a6cb6`.
- IDA confirms `0x005b27c0` as a real helper function. It sends opcode `0x1f` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) when [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md) is not positive.
- 2026-06-21 B006 source-quality recheck keeps [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) as a free/file-level helper, not a `TakeOffInputPane` member: the body is `__cdecl`, has no `this`, accepts one signed byte selector (`movsx`), and is called by both this class's `A` all-equipment branch and [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md) equipment-click branches.
- IDA `py_eval` and B014 current MCP confirm the fixed equipment key table [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) / [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md) at `0x00630bd8` contains `wash#nlr####fm#c###[]12`. B014 session `agent_b009_0002my_20260628` verifies exact 46 bytes, one data xref at `0x005b28f0`, unique full-pattern match, `get_string` only `"w"`, and the source-ready declaration `static const wchar_t g_equipmentSlotKeys[23]`.
- IDA MCP on 2026-06-02 confirms `ProcessUnequipCommand` compares the input wchar to `0x0041` (`A`) before calling `SendTakeOffPacket` for the fourteen all-equipment selectors. Older generated/source-lead wording that labeled this typed command as `*` should not be treated as authority.
- IDA MCP confirms internal padding at `0x005b27b3-0x005b27c0`, `0x005b2827-0x005b2830`, and `0x005b296b-0x005b2970`, so the main method island is now split cleanly from its alignment bytes.
- 2026-06-23 B002 current MCP session `ff68e691` refresh confirms the exact method split and support routes. `lookup_funcs` reports `sub_5B2720` size `0x93`, [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) size `0x67`, and `sub_5B2830` size `0x13b`; `0x005b26e0`, `0x005b27b3`, `0x005b2827`, and `0x005b296b` are not function starts. The raw constructor sibling remains no-function/no-xref/no-pointer but is mirrored by inline factory `0x005aa0c0`.
- 2026-06-25 B007 current MCP session `80de0a67` supersedes the raw-constructor no-code conclusion for [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md). It reconfirms no IDA function or direct raw-start route, but the exact `0x40` / 64-byte body, `g_pLanguageMan` prompt lookup id `0x22`, `LanguageMan::GetLocalizedString`, `CharInputPane::CharInputPane(const wchar_t *)`, the three `TakeOffInputPane` vtable stores, and the `0x005aa0c0` inline factory mirror now support formal first-draft constructor C++. The class-level formal C++ block can remain blank until broader declaration, virtual-method, event-field, and helper-naming policy is resolved; the child constructor emits separately through its own page.
- Current MCP vtable routes are `0x0062f984 -> 0x005b2720` for [UID:0004TB][0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut](by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md) and `0x0062f974 -> 0x005b2830` for the independent `ProcessUnequipCommand` child. `find_bytes` for both target VAs found only those vtable slots, not direct raw pointer tables or code callers.
- Historical validator-state caveat: UID00041L and UID00041M belong to unrelated MIDI pages and previously rewrote stale TakeOff links. The accepted callback registered the exact `0x005b2720-0x005b27b3` TakeOff handler as UID0004TB and uses its semantic `HandleKeyOrTextEvent` title; the command child remains identified by its exact path and range until separately registered.
- The shortcut child reads the event/ctype support object at `dword_67A754`, checks narrowed `?`, byte `+0x10a == 4`, and byte `+0x04 == 8`, sends opcode `0x2d` length `1` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and otherwise delegates to `CharInputPane`.
- The command child requires one typed wchar, uses uppercase `A` for all-equipment removal, calls [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) for selectors `1,2,3,4,6,7,8,13,14,16,20,21,22,23`, and emits the single-slot opcode `0x1f` packet inline after scanning [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) / [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md).
- Do not emit aggregate method-body C++ from [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md). The parent now emits only the accepted comment-only aggregate marker because it contains two source-bearing class methods, the file-level [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) helper, and alignment padding; method children remain no-code until event fields, command helper names, and return convention are standardized.

## Direct Parent Gate

`TakeOffInputPane` is the direct semantic parent for [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) because the raw body constructs this class and installs this class's three vtables. After the 2026-06-25 B007 implementation, the child is `88/90` and this class parent is `88/86`, so both clear the strict `85/85` gate. This class remains attached to file parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), already `90/85`, because the command prompt, factory construction path, vtable family, and equipment packet behavior all belong to the direct item-action input pane module.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0004TB][0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut](by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md`
- [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md)
- [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact constructor/helper/table/method children assemble under this route. The class page owns the TakeOff routing, while exact constructor/helper/table/method details remain split across child pages.
- Route proof: exact constructor source is [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md); exact method/range index is [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md); exact shared file helper source is [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md); exact slot-key table declaration is [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) through [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md). Exact method paths are `by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md` and `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md` despite validator-owned UID rewrite caveats.
- Rejected emission: a class-page body would duplicate the exact constructor, helper, table, and method children; [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md) remains the method/range index.

## B003 2026-07-20 Event Contract Completion

- The accepted source-facing class declaration supersedes the historical blank/comment-only class formal. It declares the source constructor, the canonical `bool HandleKeyOrTextEvent(Event *event)` override, and the independent `void ProcessUnequipCommand()` virtual, closes the class, and places `[[CHILDREN]]` afterward so child definitions emit at namespace scope.
- [UID:0004TB][0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut](by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md) now owns the complete Event handler body. Its translation order, Shift-only `?` shortcut, key-down guard, opcode `0x2d`, success return, and `CharInputPane` fallback match the binary and the shared Event/CharInputPane contract.
- The class score rises from `88/86` to `90/91`: source declaration and handler naming/type blockers are closed, while the raw-constructor reachability caveat and independent command-body source quality remain preserved rather than hidden.

## Changes

- 2026-06-28 B014 equipment-slot table source-quality implementation:
  - Score unchanged at `88/86`.
  - What changed: documented that [UID:0001OF][0x00630bd8-0x00630c06.g_equipmentSlotKeys](by-memory/0x00630bd8-0x00630c06.g_equipmentSlotKeys.md) now carries the formal `static const wchar_t g_equipmentSlotKeys[23]` declaration. This class remains the consumer, not the table owner, and class-level output now uses only the accepted comment-only no-standalone marker for broader declaration, virtual-method, event-field, helper-name, and return-convention policy.
  - Evidence: B014 current MCP session `agent_b009_0002my_20260628` reconfirms exact table bytes, one data xref at `0x005b28f0`, unique table pattern, `get_string` one-character caveat, uppercase `A` branch, table scan, and selector `index + 1`.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents equipment-removal behavior, destructor/raw-constructor/shortcut/packet/command/destructor methods, packet opcodes, equipment-slot key table, globals, and vtable identity; confidence remains capped by raw-constructor reachability and final helper source owner.
- 2026-06-02 TakeOff refresh:
  - Changed to: completion `86`, confidence `82`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: refreshed memory pages document exact function boundaries, vtable xrefs, raw constructor stores, opcode `0x2d` and `0x1f` packet paths, `A` all-equipment branch, selector list, and padding splits. C++ remains blank because final names/source ownership are below 95% confidence.
- 2026-06-12 A001 Goal 2 parent-gate repair:
  - Changed to: completion `88`, confidence `86`; parent remains [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: fresh read-only IDA MCP confirms exact raw constructor bytes/instructions, no function or pointer refs to the raw start, equivalent inline command-factory construction, vtable xref counts across raw/factory/dispatcher stores, and verified number conversions for constructor/object/prompt/opcode constants. This was enough for the raw constructor child to attach directly to this class; B002 now supersedes the blank-C++ rationale with source-quality naming/type standardization rather than a numeric threshold.
- 2026-06-21 B006 SendTakeOffPacket support sync:
  - Score unchanged at `88/86`.
  - What changed: clarified that [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) is a free/file-level helper with implementation in `ItemActionInputPanes.cpp`, not a class method; this class calls it from the uppercase `A` all-equipment branch and emits the single-slot key-table packet inline.
  - Evidence: B006 local IDA-export caller inventory, signed byte argument, exact packet body, and SelfLook caller group.
- 2026-06-23 B002 MCP source-quality implementation:
  - Score unchanged at `88/86`.
  - What changed: added exact method children [UID:00041L][0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods](by-memory/0x005260a0-0x005260ff.MidiPlayerPlaybackToggleMethods.md) and [UID:00041M][0x00526340-0x00526350.MidiPlayerStopPlayback](by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md), current MCP session `ff68e691` provenance, vtable slot/pointer-route evidence, the raw constructor sibling caveat with `0x005aa0c0` mirror, uppercase `A` all-equipment behavior, typed single-slot inline send, and no-aggregate-C++ rationale.
  - Evidence: current MCP `lookup_funcs`, `decompile`, `xrefs_to`, `find_bytes`, vtable byte reads, `g_equipmentSlotKeys` bytes, and padding byte reads all agree with the accepted B002 report. Older numeric code-gate wording is historical; the current blank-C++ reason is source-quality naming/type standardization, not a numeric threshold.
- 2026-06-25 B007 TakeOff raw-constructor implementation sync:
  - Score unchanged at `88/86` for the class page.
  - What changed: [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) is now documented as formal first-draft `TakeOffInputPane::TakeOffInputPane()` C++ while retaining the no-function/no-route caveat as a confidence cap. Class-level output now uses only the accepted comment-only no-standalone marker separately for broader declaration and method-name policy.
  - Evidence: B007 MCP session `80de0a67` and supplemental PE scan reconfirm exact constructor bytes, prompt id `0x22`, `g_pLanguageMan->GetLocalizedString`, `CharInputPane` base construction, vtable-store identity, `0x005aa0c0` inline factory mirror, and zero direct raw-start xref/pointer/code/ref/rel32 routes.
