*** UID:0000SN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserStatusPane2 *g_pUserStatusPane2 = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pUserStatusPane2

## Status

- Confidence: strong for address, lifecycle, compact-pane role, and exact storage slot.
- Address: `0x0069b4e4`
- IDA name: `dword_69B4E4`
- Proposed owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related class: [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md)
- Exact storage evidence: [UID:0002WE][0x0069b4e4-0x0069b4e8.g_pUserStatusPane2](by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md) records `0x0069b4e4` / `dword_69B4E4` as the compact status singleton slot. Older `0xffffffff` initializer notes are historical; B009 MCP reads current bytes as `00 00 00 00`.

## Role

`g_pUserStatusPane2` stores the active compact status-meter pane. It is installed by `UserStatusPane2` construction and cleared by cleanup, singleton-clear, and scalar deleting destructor paths.

Treat the adjacent `.data` cluster as physical storage adjacency rather than one source-level aggregate. The declaration belongs with the compact status HUD code in `UserStatusPane.cpp`; neighboring slots belong to TimerPane, UserListDialogPane, MenuVarietyPane, and legacy status/menu owners.

## Evidence Notes

- `UserStatusPane2::UserStatusPane2` writes the global at `0x005bab4a` and `0x005bab51`.
- The cleanup body clears it at `0x005bac5e`.
- The singleton clear helper at `0x005bfbf0` writes zero to `0x0069b4e4`.
- The scalar deleting destructor clears it at `0x005bfec5`.
- `InitializeMainUiGraph` constructs the pane in the newer layout at `0x004f83ea`.
- Historical note: IDA MCP `py_eval` on 2026-05-31 reported initial dword `0xffffffff`. B009 supersedes that as stale for current source reconstruction because current MCP `get_bytes` reads `00 00 00 00` at `0x0069b4e4`.
- IDA MCP and B009 xref evidence agree on 6 data xrefs: map cleanup read at `0x00504925`, constructor writes at `0x005bab4a` and `0x005bab51`, cleanup clear at `0x005bac5e`, singleton-clear helper at `0x005bfbf0`, and scalar deleting destructor clear at `0x005bfec5`.
- Live IDA MCP on 2026-06-04 reconfirmed the same 6 data xrefs and confirms `UserStatusPane2` constructor `0x005bab00` size `0xf7`, cleanup `0x005bac00` size `0x7d`, singleton clear helper `0x005bfbf0` size `0xb`, and scalar deleting destructor `0x005bfe60` size `0xbe`.
- IDA decompilation of `0x005bab00` writes `dword_69B4E4 = this` at `0x005bab4a` and clears it at `0x005bab51` on the null/sentinel path before installing the `UserStatusPane2` primary and secondary vtables.
- IDA decompilation of `0x005bac00`, `0x005bfbf0`, and `0x005bfe60` confirms all three teardown paths clear `dword_69B4E4`.
- IDA xrefs/callers confirm `UserStatusPane2` construction is from `InitializeMainUiGraph` at `0x004f83ea`, while the singleton clear helper and destructor are vtable/thunk-owned paths with no ordinary direct callers.
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md) records the compact status-pane executable range, including constructor, cleanup, packet/movement router, paint method, compact status-rect helper, glyph draw helper, and bitflagged payload application.
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md) separates the `UserStatusPane2` singleton clear helper and scalar deleting destructor from adjacent MenuVariety, OldUserStatusPane, and active UserStatusPane destructor forms.
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md) ties `9X11FONT.BIN` to the constructor family and `COMMA.EPF` / `COMMA.PAL` to `UserStatusPane2::OnPaint`; `BAR.EPF` / `BAR.PAL` remain cautious helper-owned resources until that helper is traced back cleanly.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md)
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)

## Changes

- 2026-06-30 B009 implementation callback:
  - Added formal zero-initialized global C++.
  - Historicalized stale `ff ff ff ff` initializer language. Current MCP bytes at `0x0069b4e4` are `00 00 00 00`; xrefs remain the documented six singleton lifecycle/UI refs.
- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:72`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P2` for [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md). `RECONSTRUCTION_CPP CODE` remained blank under the older 95+ wording at that time; B009 later superseded this with a zero-initialized global definition under the current code-entry gate.
  - Evidence: IDA MCP rechecked `0x0069b4e4` as a 4-byte singleton pointer with 6 data xrefs spanning map cleanup, UserStatusPane2 construction, cleanup, singleton-clear helper, and scalar deleting destructor.
- 2026-06-04 live IDA refresh:
  - Before: the page had the singleton xrefs but did not record current constructor/cleanup/destructor decompilation or vtable/thunk ownership details.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP reconfirmed exactly six data xrefs to `0x0069b4e4`, exact `UserStatusPane2` constructor/cleanup/clear/destructor sizes, singleton set/clear behavior in `0x005bab00`, clears in `0x005bac00`, `0x005bfbf0`, and `0x005bfe60`, and construction from `InitializeMainUiGraph` at `0x004f83ea`. The score remains below final reconstruction level because final source split across `UserStatusPane.cpp` and shared destructor/thunk glue is still provisional.
- 2026-06-06: Raised `COMPLETION` from `84` to `86` and `CONFIDENCE` from `88` to `89`.
  - Added exact storage-cluster evidence, executable-range support, shared destructor/thunk ownership separation, direct compact-status resource evidence, and a caveat for the surrounding UI singleton run.
  - Evidence: existing IDA-backed docs now account for the singleton slot in [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), compact status code in [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md), clear/destructor ownership in [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md), and `9X11FONT.BIN` plus `COMMA` resources in [UID:0001RS][user-status-resources](by-resource/user-status-resources.md). Final C++ remained blank under the older 95/95 threshold wording; B009 later superseded this with a zero-initialized global definition.
