*** UID:0000SK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pTotemFrame

## Status

- Confidence: strong for address, storage slot, and lifecycle role.
- Address: `0x0069b35c`
- Current IDA name: `dword_69B35C`
- Proposed owner file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- Exact storage evidence: [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md) records the active `TotemFrame` singleton slot, initialized to `0xffffffff` with 11 direct refs.

## Symbol Role

`g_pTotemFrame` tracks the active totem/status frame pane. The constructor stores the singleton, cleanup and destructor helpers clear it, status-update handlers create or invalidate it, and spell-input code marks it for deletion before opening certain input panes. The status-update callers live in [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) and [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md).

The source declaration belongs with `TotemFrame.cpp`; the physical slot currently sits in a mixed `.data` aggregate beside `g_pGeneralPurposePanel2`, `g_pInterfaceEfxMgr`, and early `MainUiGraph` layer/context slots. Do not model that adjacency as a source-level struct unless later source-layout evidence proves the grouping.

## IDA MCP Evidence

Checked on 2026-05-24:

- Status/UI helper functions at `0x004b8650` and `0x004b89a0` check and mark the active frame for deletion when switching displayed status panes.
- Map/session cleanup reads it at `0x00504ad2`.
- `TotemFrame::TotemFrame` stores or clears the global at `0x00598d0e` and `0x00598d15`.
- `TotemFrame` cleanup body clears it at `0x00598dba`.
- `TotemFrame::ClearTotemFrameSingleton` clears it at `0x00598e40`.
- `TotemFrame::ScalarDeletingDestructor` clears it at `0x00598e90`.
- `UserStatusPane` status payload application at `0x005ba4a0` creates or invalidates it.
- `OldUserStatusPane` status payload application at `0x005bf7c0` creates or invalidates it.
- Status-update handlers at `0x005ba4a0` and `0x005bf7c0` read it and either invalidate the existing frame or allocate/construct a new one.
- IDA MCP `py_eval` rechecked `0x0069b35c` on 2026-05-31 and confirmed IDA name `dword_69B35C`, initial dword `0xffffffff`, and 11 data xrefs matching the status helpers, map cleanup read, constructor writes, cleanup helpers, and destructor clear paths above.
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md) now records the complete executable range map: constructor, cleanup body, `OnPaint`, singleton clear helper, adjustor thunks, and scalar deleting destructor.
- [UID:00026Q][0x0062e338-0x0062e480.TimerTotemReadOnlyData](by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md) records the TotemFrame vtable slice and `TOTFRAME.EPD` resource string; [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md) ties the frame image and `NPAL7.PAL` palette to `TotemFrame::OnPaint`.
- Batch 039 live IDA MCP recheck on 2026-06-07 confirmed the exact four-byte storage page [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md): initial dword `0xffffffff`, 11 direct refs, constructor writes at `0x00598d0e`/`0x00598d15`, cleanup/destructor clears at `0x00598dba`, `0x00598e40`, and `0x00598e90`, and neighboring singleton dword boundaries.

## Ownership Notes

- Keep this global with `ui/panels/TotemFrame.cpp` or a nearby old user-status/totem feature source.
- Do not merge it into generic [UID:0000JL][FrameChrome](by-file/FrameChrome.md); the frame-manager/chrome code owns generic frame UI, while this singleton is feature-specific to the totem/status panel.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:00026Q][0x0062e338-0x0062e480.TimerTotemReadOnlyData](by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000OV` for [UID:0000OV][TotemFrame](by-file/TotemFrame.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b35c` as a 4-byte singleton pointer with 11 data xrefs across totem/status helpers, map cleanup, TotemFrame construction, cleanup, clear helper, scalar deleting destructor, and status-update handlers.
- 2026-06-06: Raised `COMPLETION` from `74` to `80` and `CONFIDENCE` from `84` to `88`.
  - Added exact storage aggregate evidence, current executable range/vtable/resource links, and clarified that physical adjacency in `.data` is not source-level ownership.
  - Evidence: existing IDA-backed docs now account for the 4-byte singleton slot, all 11 direct refs, constructor publish/fallback clear, cleanup/helper/destructor clears, status-update create/invalidate users, map/session cleanup, read-only vtable/resource data, and `TotemFrame.cpp` ownership.
- 2026-06-07: Raised to `85/90` during Batch 039 parent-gate follow-up after splitting exact storage [UID:0002VR][0x0069b35c-0x0069b360.g_pTotemFrameStorage](by-memory/0x0069b35c-0x0069b360.g_pTotemFrameStorage.md). The parent now satisfies the corrected `85/85` gate for the storage child.
