*** UID:0000RI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMenuVarietyPane

## Status

- Address: `0x0069b4e8`
- Type kind: inferred singleton pointer.
- Storage: four-byte `.data` singleton slot, initialized as `0xffffffff` bytes in the image.
- Likely owner: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Storage cluster: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- Confidence: strong for address, initialized storage, owner, lifecycle writes/clears, map-exit teardown, and selector consumers; medium-high for final source declaration details.

## Role

`g_pMenuVarietyPane` points to the active in-game menu button pane. `MenuVarietyPane` construction publishes the pointer, the normal cleanup body and scalar deleting destructor clear it, [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) removes it during UI shutdown, and `MenuVarietySelectPane` action handlers use it to pulse or refresh the owning menu button.

## Evidence

- Live IDA MCP `xrefs_to 0x0069b4e8` on 2026-06-06 reports nine data xrefs: one map-exit teardown read, one constructor publish, one cleanup clear, four selector action-handler reads, one selector notify/delete-helper read, and one scalar-deleting-destructor clear.
- `get_bytes 0x0069b4e8 size 4` returns `0xff 0xff 0xff 0xff`, matching image-initialized singleton storage.
- `MenuVarietyPane::MenuVarietyPane` writes either the constructed instance or a null fallback at `0x005bc635`, after pane-base construction and before installing `MenuVarietyPane` vtables.
- The non-deleting cleanup body clears the slot at `0x005bc67a`, and the scalar deleting destructor clears it at `0x005bfca0` before pane-base cleanup and optional delete handling.
- [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) reads the slot at `0x005049a5`, tests it, and removes the menu button through the common pane detach helper during session/menu teardown.
- `MenuVarietySelectPane::HandleMenuMouseEvent` reads the slot at `0x005bd0db`, `0x005bd1b1`, `0x005bd2b5`, and `0x005bd2fa` while dispatching menu actions and refreshing/pulsing the owning menu button.
- `MenuVarietySelectPane::NotifyAndMarkSessionForDeletion` reads the slot at `0x005bd3a3`, pulses the menu button, and marks the selector pane for deletion.
- The selector interaction remains documented through [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md); consumer reads do not change the source-owner decision.
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) documents the slot inside the dense UI singleton pointer run and separates it from adjacent `UserStatusPane2` and `OldUserStatusPane` globals.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md)
- [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0` with brief singleton/lifecycle notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, storage-cluster reference, IDA lifecycle evidence, selector consumer evidence, and teardown-consumer note.
  - Summary/evidence: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md), and class docs for [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md) and [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md) support the role. Completion is capped because this page still uses the aggregate UI singleton storage page rather than a dedicated exact by-memory page.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000L8`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b4e8` and decompilation of `0x005bc610`, `0x005bc660`, and `0x005bfc80` prove NexusTK-owned `MenuVarietyPane` singleton storage owned by [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.

- 2026-06-06 xref/cleanup pass:
  - What existed before: the page still carried raw singleton labels, omitted the map-exit teardown consumer from the main evidence, and stayed at `78/84` despite all direct xrefs being identifiable.
  - Changed to: completion `84`, confidence `88`, initialized storage evidence, source-facing lifetime/consumer descriptions, and a direct MapPane teardown cross-reference.
  - Summary/evidence: live IDA MCP `xrefs_to`, `get_bytes`, `lookup_funcs`, `decompile`, and `disasm` on 2026-06-06 account for all nine direct xrefs, constructor publish/fallback behavior, cleanup/destructor clears, map-exit removal, selector action refreshes, and selector notify/delete helper reads. No final C++ body was added because the page remains below the 95/95 reconstruction gate and the exact source declaration is not yet final-audited.
