*** UID:0000SK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TotemFrame;

TotemFrame *g_pTotemFrame = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTotemFrame

## Status

- Confidence: very strong for address, storage, type, linkage, lifecycle, and source route.
- Address: `0x0069b35c`
- Current IDA model: no names/globals entity at the address; live disassembly renders `unk_69B35C` until the supervisor-owned Gate 2B action is applied.
- Owner/source file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md), emitted at position 10.
- Exact storage evidence: [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md) records loader-zero physical backing, complete 11-reference evidence, and a false/non-emitting physical disposition.
- Source form: one externally linked zero definition, `TotemFrame *g_pTotemFrame = 0;`.

## Symbol Role

`g_pTotemFrame` tracks the active totem/status frame pane. Direct `Singleton<TotemFrame>` base construction publishes the complete object, direct-base destruction clears the pointer on ordinary, unwind, and deleting-wrapper paths, status-update handlers create or invalidate it, and panel/session teardown marks or deletes the active frame. The status-update callers live in [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) and [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md).

The sole source definition belongs with `TotemFrame.cpp`; the physical slot sits in the `.data` virtual tail beside independent `g_pGeneralPurposePanel2`, `g_pInterfaceEfxMgr`, and early `MainUiGraph` layer/context slots. Do not model that adjacency as a source-level struct. UID0002VR documents the address but does not emit a second definition.

## One-Definition And Declaration Order

- UID0000SK emits the only typed storage definition at position 10, after a forward declaration of `TotemFrame`.
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md) emits the complete class and matching `extern TotemFrame *g_pTotemFrame;` at position 20.
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md) emits source methods through the class child route and must not repeat the global definition.
- [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md) is false/non-emitting physical evidence with blank C++.
- A template-static spelling could be a lost original lexical detail, but no symbol proves it. The accepted project representation is the external `g_p<Class>` global; emitting both representations would violate one-definition behavior.

## Current IDA MCP And PE Evidence

- B003 live MCP session `7be8cc9f` returned zero at `0x0069b35c`, exactly 11 xrefs with no truncation, and no current names/globals entity at the target.
- PE `.data` raw-backed VA ends at `0x0067a800`; this slot is `0x20b5c` bytes into the virtual-only tail. Its four zero bytes are loader supplied, not an initialized `0xffffffff` payload.
- `find_bytes` for absolute operand bytes `5C B3 69 00` independently returned the same 11 sites; the RVA/raw-offset pattern had no matches.
- Five references are compiler/Singleton lifetime writes: constructor publication/fallback at `0x00598d0e`/`0x00598d15`, ordinary-destruction clear at `0x00598dba`, constructor-EH clear at `0x00598e40`, and deleting-wrapper clear at `0x00598e90`.
- Six references are consumers: panel-switch deletion checks at `0x004b8698`, `0x004b8768`, and `0x004b89c6`; MapPane deleting teardown at `0x00504ad2`; and status create/invalidate reads at `0x005ba7e2` and `0x005bf90c`.
- The two status paths allocate exactly `0xf8` and call the constructor at `0x005ba809`/`0x005bf933` only when this pointer is null.

## Direct Singleton Source Shape

- TotemFrame RTTI contains seven hierarchy entries including a direct non-virtual `Singleton<TotemFrame>` base descriptor at PMD `{0xf8,-1,0}`, attributes `0x40`.
- The constructor builds `Pane`, then publishes while constructing the empty Singleton base at `+0xf8`; constructor EH adjusts to that base before its retained destructor clears this slot.
- Ordinary/scalar destruction clears before Pane teardown, matching reverse base destruction.
- Correct human-written source declares direct inheritance and initializes `Singleton<TotemFrame>()`; it does not hand-author `g_pTotemFrame = this` or `g_pTotemFrame = 0` in TotemFrame methods.
- [UID:00026Q][0x0062e334-0x0062e47c.TimerTotemReadOnlyData](by-memory/0x0062e334-0x0062e47c.TimerTotemReadOnlyData.md) records the TotemFrame vtable/resource island, while [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) ties `TOTFRAME.EPD` and `NPAL7.PAL` to `OnPaint`.

## Complete Reference Inventory

| Address | Role |
| --- | --- |
| `0x004b8698`, `0x004b8768` | GeneralPurposePanel tab-switch reads and deletion requests. |
| `0x004b89c6` | GeneralPurposePanel2 child-switch read and deletion request. |
| `0x00504ad2` | MapPane exit-to-menu deleting teardown. |
| `0x00598d0e`, `0x00598d15` | Singleton constructor publication and null-adjust fallback. |
| `0x00598dba` | Inlined ordinary Singleton base clear. |
| `0x00598e40` | Constructor-EH Singleton destructor clear. |
| `0x00598e90` | Inlined scalar-wrapper Singleton clear. |
| `0x005ba7e2` | UserStatusPane create-or-invalidate read. |
| `0x005bf90c` | OldUserStatusPane create-or-invalidate read. |

## Ownership Notes

- Keep this global in `NexusTK/ui/panels/TotemFrame.cpp`; current class, resource, consumer, and source-tree evidence closes the active route.
- Do not merge it into generic [UID:0000JL][FrameChrome](by-file/FrameChrome.md); the frame-manager/chrome code owns generic frame UI, while this singleton is feature-specific to the totem/status panel.
- Do not move it into UserStatusPane/OldUserStatusPane. Those features create/invalidate the frame but do not own the TotemFrame class, RTTI, vtables, or resource literal.

## Historical Assumptions Superseded

- Earlier checks recorded `dword_69B35C` and `0xffffffff`. Preserve those observations as historical tool/document state, but current PE/live evidence proves an anonymous loader-zero slot.
- Earlier prose treated publication and clear as handwritten TotemFrame assignments. Direct Singleton RTTI, PMD, constructor-EH order, and teardown order supersede that source-shape interpretation.
- Earlier routing treated UID0002VR as a reconstructable physical emitter. The physical page is now false/non-emitting; this semantic page carries the sole definition.
- The earlier 11-reference count, feature identity, status/map consumers, address, and `TotemFrame.cpp` ownership remain valid.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:00026Q][0x0062e334-0x0062e47c.TimerTotemReadOnlyData](by-memory/0x0062e334-0x0062e47c.TimerTotemReadOnlyData.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)

## Changes

- 2026-07-24 B003 UID0002VR support implementation:
  - Raised `85/90` to `92/94`, retained owner/emitter UID0000OV, set emitter position 10, and added the sole `TotemFrame *g_pTotemFrame = 0;` definition.
  - Incorporated loader-zero physical evidence, the complete five-write/six-read inventory, direct `Singleton<TotemFrame>` PMD/EBO source cause, external linkage, and one-definition ordering.
  - Historicalized the disproved `0xffffffff`, raw-name, reconstructable-physical, and handwritten singleton-lifecycle assumptions while preserving all valid earlier consumer/resource evidence.
- 2026-07-20 B001 UID0001NM bounded support synchronization: [UID:0003AB][0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload](by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md) is an exact legacy status consumer. On a changed clamped spirit id it invalidates field 2, then invalidates the existing `g_pTotemFrame` or allocates `new TotemFrame()` if the pointer is null. This preserves TotemFrame.cpp ownership, current singleton lifecycle, score, storage route, and unrelated consumers.
- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OV` for [UID:0000OV][TotemFrame](by-file/TotemFrame.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b35c` as a 4-byte singleton pointer with 11 data xrefs across totem/status helpers, map cleanup, TotemFrame construction, cleanup, clear helper, scalar deleting destructor, and status-update handlers.
- 2026-06-06: Raised `COMPLETION` from `74` to `80` and `CONFIDENCE` from `84` to `88`.
  - Added exact storage aggregate evidence, current executable range/vtable/resource links, and clarified that physical adjacency in `.data` is not source-level ownership.
  - Evidence: existing IDA-backed docs now account for the 4-byte singleton slot, all 11 direct refs, constructor publish/fallback clear, cleanup/helper/destructor clears, status-update create/invalidate users, map/session cleanup, read-only vtable/resource data, and `TotemFrame.cpp` ownership.
- 2026-06-07: Raised to `85/90` during Batch 039 parent-gate follow-up after splitting exact storage [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md). The parent now satisfies the corrected `85/85` gate for the storage child.
  - Historical correction: UID0002VR's exact split and reference evidence remain valid, but its former `0xffffffff` and reconstructable-physical conclusions are superseded by the 2026-07-24 audit.
