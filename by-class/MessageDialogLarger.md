*** UID:000086 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MessageDialogLarger : public PursuitMessageDialogPane
{
public:
    MessageDialogLarger(const unsigned char *packet, bool hasText);
    virtual bool OnButtonAction(int actionId);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MessageDialogLarger

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Exact children: [UID:0003G8][0x0054db90-0x0054e8c7.MessageDialogLargerConstructor](by-memory/0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md), [UID:0003G9][0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler](by-memory/0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md), and [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md).
- Autogen parent: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). Batch 297 refreshed this class to `87/89`; the direct file parent remains `89/85`, so the strict child/direct-parent gate still clears.
- Declaration-level C++ is now emitted for the class shell; method-body emission remains gated on larger-layout packet/control field names and final class/member/helper naming.

## Class Purpose

`MessageDialogLarger` is the larger-layout variant of the packet-driven message dialog. It parses a message header and portrait/body data, builds backdrop/buttons/portrait/body controls, configures default actions, and closes after a command is handled.

It is the larger-layout sibling of [UID:000085][MessageDialog](by-class/MessageDialog.md) in the NPC message/menu-question dialog family. The packet dispatcher selects this constructor through the same dialog packet mode byte used for `MessageDialog`, `MenuQuestionDialog`, and `MenuQuestionDialogLarger`; the larger branch uses distinct `DLGMSG*` read-only resources and a `0x278`-byte allocation wrapper.

B010 2026-07-01 resolves the empty emitter as declaration-level source with a constructor and action virtual shell. [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) now emits factory calls to `MessageDialogLarger(payload, hasText)`, while exact constructor/action behavior remains on by-memory children.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054db90-0x0054e8c7` | [UID:0003G8][0x0054db90-0x0054e8c7.MessageDialogLargerConstructor](by-memory/0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md) | Larger message packet parser and UI/control builder; live IDA reports size `0xd37` / 3383 bytes. Verified with int_convert.py. |
| `0x0054e8d0-0x0054e91b` | [UID:0003G9][0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler](by-memory/0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md) | Handles previous/next/current action ids `1`/`2`/`3` and closes the dialog; live IDA reports size `0x4b` / 75 bytes. Verified with int_convert.py. |

## Evidence Notes

- IDA MCP confirms both functions as exact starts and Batch 265 exact child pages now carry the method-level evidence.
- Constructor xrefs come from the same packet dispatch area as `MessageDialog`, supporting same-source ownership.
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) records the dispatcher rule: `packet[1]` bit `0x10` selects the larger dialog family, while the low nibble selects message versus menu-question variants. Constructors receive `packet + 2` plus a final layout/text-mode flag.
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md) records exact constructor callers at `0x0054c27c` and `0x0054c2bb` and keeps the `0x0054db90-0x0054e91b` range grouped with the other message/menu-question constructors and action handlers.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) documents the small wrappers at `0x0054c5d0-0x0054c62b` and `0x0054c690-0x0054c6eb`: both allocate `0x278` bytes and call `0x0054db90`, passing final flags `1` and `0` respectively.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records `MessageDialogLarger` vtables at `0x00622560-0x006225f0`, `DLGMSG1.PAL` references from `0x0054db90`, and `DLGMSG1B.EPF` references from `0x0054db90`.
- Virtual/action helpers for this family are vtable-referenced in the `0x00622500-0x00622878` band, with shared object-response behavior documented separately at [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md).
- 2026-06-12 Batch 265 live IDA MCP reconfirmed constructor range `0x0054db90-0x0054e8c7`, action range `0x0054e8d0-0x0054e91b`, constructor callers at `0x0054c27c`/`0x0054c2bb` from the dispatcher plus wrapper calls at `0x0054c615`/`0x0054c6d5`, and wrapper allocation size `0x278` / decimal 632. Verified with int_convert.py.
- The same pass recorded constructor packet fields at `this + 0x26c`, `+0x270`, `+0x274`, and `+0x276` (decimal 620/624/628/630; Verified with int_convert.py), object descriptor parsing from `packet + 6`, optional text length/data at descriptor-relative `+16`/`+18`, and `MultiByteToWideChar` conversion bounded by `0x8000`.
- Constructor data refs prove the larger message resource branches: `DLGMSG1.PAL`; EPF assets `DLGMSG1B.EPF`, `DLGMSG11.EPF`, and `DLGMSG2.EPF` when `byte_66DA97 == 1`; EPD assets `DLGMSG1B.EPD`, `DLGMSG11.EPD`, and `DLGMSG2.EPD` otherwise.
- The constructor installs the primary/secondary/tertiary vtable views at `0x00622560`, `0x006225c0`, and `0x006225f0`; [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md) records the action slot `0x006225a8 -> 0x0054e8d0` and shared object-response slot `0x006225d0 -> 0x0054caf0`.
- 2026-06-12 Batch 297 live IDA MCP rechecked `NexusTK.exe.i64` through session `b001_nexustk`: auto-analysis, Hex-Rays, and string cache were ready; `lookup_funcs` reconfirmed `sub_54DB90` size `0xd37` / 3383 bytes and `sub_54E8D0` size `0x4b` / 75 bytes (Verified with int_convert.py).
- Batch 297 `analyze_component` grouped the dispatcher/wrapper path with this class: `sub_54C200`, `sub_54C5D0`, and `sub_54C690` all call `sub_54DB90`; the dispatcher remains the interface function and the constructor/action/wrappers are internal-only in that focused component.
- Batch 297 `trace_data_flow` reconfirmed the three constructor-installed vtable views: `0x00622560` is stored at `0x0054dbe1`, `0x006225c0` at `0x0054dbe7` into `this + 0xa0` / decimal 160, and `0x006225f0` at `0x0054dbf1` into `this + 0xa4` / decimal 164 (Verified with int_convert.py). The same pass confirmed `0x006225a8 -> 0x0054e8d0`, `0x006225d0 -> 0x0054caf0`, and a unique byte signature for the `0x0062255c-0x006225f8` vtable-data range.
- Batch 297 listing search inside `0x0054db90-0x0054e8c7` found the larger-resource pushes for `DLGMSG1.PAL`, `DLGMSG11.EPF`, `DLGMSG1B.EPF`, `DLGMSG2.EPF`, `DLGMSG11.EPD`, `DLGMSG1B.EPD`, and `DLGMSG2.EPD`, keeping the resource-branch evidence current.

## Batch 265 Parent Gate Repair

This class now clears the strict assignment gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears `89/85`, this class is now `87/89`, and the exact vtable-data child [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md) is now `88/92`.

The previous blocker was method-level evidence. Batch 265 repaired that by creating exact child pages for the constructor and action handler:

- [UID:0003G8][0x0054db90-0x0054e8c7.MessageDialogLargerConstructor](by-memory/0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md) records the packet offsets, constructor callers, vtable stores, resource branches, control command ids, global refs, and padding after the constructor.
- [UID:0003G9][0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler](by-memory/0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md) records exact action ids: case `1` calls the previous helper at `0x0054cc30`, case `2` calls the next helper at `0x0054ccd0`, and case `3` calls the current helper at `0x0054cd70`; all handled cases then call the close helper at `0x0049dad0`.

`AUTOGEN_PARENT_UID` is set to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md) can attach here as its direct semantic owner. The declaration shell now emits; constructor/action method bodies remain gated on final source-facing member names, packet struct names, and UI helper names.

## Score And Gate Rationale

The page is now `87/89`: it documents exact method ranges, exact method child pages, dispatcher selection, allocation wrappers, direct constructor caller evidence, constructor packet offsets, vtable stores, resource branches, action command-id mapping, read-only-data support, sibling relationship, parent gate, and final-C++ blockers. Batch 297 adds fresh live checks for current IDB readiness, focused component ownership, vtable data-flow, unique vtable range bytes, and resource listing hits.

`AUTOGEN_PARENT_UID` is set because both the class and direct file parent clear `85/85`. Completion stays below final-audit quality because source-facing field/control names and a final constructor rewrite remain unresolved.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:000085][MessageDialog](by-class/MessageDialog.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- [UID:0003G8][0x0054db90-0x0054e8c7.MessageDialogLargerConstructor](by-memory/0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md)
- [UID:0003G9][0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler](by-memory/0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)
- [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md)

## Changes

- 2026-07-01 Agent-B010 implementation callback: raised `87/89 -> 88/90`, set emitter position `50`, and added the accepted declaration shell for `MessageDialogLarger(const unsigned char *packet, bool hasText)`, `OnButtonAction(int actionId)`, and `[[CHILDREN]]`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger message-dialog variant has role, constructor/action boundaries, packet-layout role, and same-source ownership documented, but it lacks the deeper packet offset detail already present on the normal `MessageDialog` page. Evidence: linked NPC message/menu-question range, IDA-confirmed starts, and constructor xrefs from the shared packet dispatch area.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `76/84`, below the strict `85/85` child gate, even though [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x0054db90` and `0x0054e8d0`; current `callers` confirms constructor references from the shared packet-dialog dispatch around `0x0054c200`.
- 2026-06-10 A002 provenance/gate cleanup:
  - Before: status/evidence still referenced generated recovered output and the change log cited the old parent-attachment threshold.
  - After: status records the strict `85/85` gate and evidence now centers on IDA-confirmed starts, packet-dispatch constructor xrefs, and the linked message/menu-question aggregate.
  - Summary/evidence: the direct parent is `89/85`, but this child remains `76/84`, so the source-owner link stays informational rather than an autogen assignment.
- 2026-06-11 A002 evidence refresh:
  - Before: `76/84`, with only role, method boundary, and broad dispatcher evidence.
  - After: `82/85`, `AUTOGEN_PARENT_UID` still blank.
  - Summary/evidence: incorporated the existing IDA-backed dispatcher rule from [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), exact caller/wrapper evidence from [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), aggregate range evidence from [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), and vtable/resource evidence from [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md). Parent remains blank because this child is still below the `85` completion gate.
- 2026-06-11 A002 Batch 238 reviewed-no-85 follow-up:
  - Score remains `82/85`; `AUTOGEN_PARENT_UID` remains blank.
  - Summary/evidence: added the exact remaining gate blockers after checking that [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `89/85`, [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) is a complete non-emitting index, and [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md) is `86/91` but parentless. The class still needs a live method-level constructor/action pass before the child side of the strict `85/85` gate can clear.
- 2026-06-12 Agent-A001 Batch 265 parent-gate repair:
  - Before: `82/85`, `AUTOGEN_PARENT_UID:` blank, and the exact [UID:0003D2][0x0062255c-0x006225f8.MessageDialogLargerVtableData](by-memory/0x0062255c-0x006225f8.MessageDialogLargerVtableData.md) vtable child was parent-blocked.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000LA`; the exact vtable child can attach to this class.
  - Summary/evidence: live IDA MCP reconfirmed constructor/action ranges, dispatcher and wrapper constructor callers, `0x278` / decimal 632 wrapper allocation size (Verified with int_convert.py), constructor packet fields at `+0x26c/+0x270/+0x274/+0x276`, vtable stores to `0x00622560`/`0x006225c0`/`0x006225f0`, EPF/EPD `DLGMSG*` resource branches, action ids `1`/`2`/`3` mapping to previous/next/current packet helpers plus close, and exact method child pages [UID:0003G8][0x0054db90-0x0054e8c7.MessageDialogLargerConstructor](by-memory/0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md) and [UID:0003G9][0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler](by-memory/0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md).
- 2026-06-12 Agent-A001 Batch 297 evidence refresh:
  - Before: `86/88`, `AUTOGEN_PARENT_UID:0000LA`.
  - After: `87/89`, `AUTOGEN_PARENT_UID:0000LA`; routing remains unchanged because the class and direct file parent both clear `85/85`.
  - Summary/evidence: live IDA MCP session `b001_nexustk` reconfirmed ready analysis state, `sub_54DB90` and `sub_54E8D0` sizes, dispatcher/wrapper calls into the constructor, the action handler's sole vtable data xref at `0x006225a8`, the three constructor-installed vtable views and `this + 0xa0`/`+0xa4` adjusted stores (Verified with int_convert.py), shared object-response slot `0x006225d0 -> 0x0054caf0`, unique `0x0062255c-0x006225f8` vtable-data signature, and current listing hits for all larger `DLGMSG*` resource branches.
