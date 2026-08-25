*** UID:0000RI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MenuVarietyPane *g_pMenuVarietyPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMenuVarietyPane

## Status

- Address: `0x0069b4e8`
- Type kind: inferred singleton pointer.
- Storage: `0x4` / 4-byte `.data` singleton slot; current MCP session `3fa0535f` reads `00 00 00 00` at `0x0069b4e8`.
- Likely owner: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Storage cluster: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- Exact storage child: [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md)
- Confidence: strong for address, zero-initialized storage, owner, lifecycle writes/clears, map-exit teardown, selector consumers, and source declaration form; medium-high for exact original linkage/spelling.

## Score Rationale

- Completion `87`: this page accounts for the exact storage child, owner file, related classes, lifecycle writes/clears, map-exit teardown, selector consumers, scalar-deleting destructor clear, neighboring split-index context, current zero initialization, and the formal source definition.
- Confidence `91`: strong for the one-dword slot, direct xref set, [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) ownership, source-facing role, and `MenuVarietyPane *g_pMenuVarietyPane = NULL;` definition. It remains below final audit because exact original declaration spelling/linkage remains inferred.

## Role

`g_pMenuVarietyPane` points to the active in-game menu button pane. `MenuVarietyPane` construction publishes the pointer, the normal cleanup body and scalar deleting destructor clear it, [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) removes it during UI shutdown, and `MenuVarietySelectPane` action handlers use it to pulse or refresh the owning menu button.

## Evidence

- Live IDA MCP `xrefs_to 0x0069b4e8` on 2026-06-06 reports nine data xrefs: one map-exit teardown read, one constructor publish, one cleanup clear, four selector action-handler reads, one selector notify/delete-helper read, and one scalar-deleting-destructor clear.
- 2026-06-29 B003 current MCP session `3fa0535f` `get_bytes` / `get_int` reads `00 00 00 00` / integer `0` at `0x0069b4e8`; this supersedes older stale `0xff 0xff 0xff 0xff` wording and supports the source definition `MenuVarietyPane *g_pMenuVarietyPane = NULL;`.
- [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md) records the exact `0x4` / 4-byte storage child (Verified with int_convert.py), successor/predecessor boundaries, and the Batch044 split out of the mixed singleton cluster.
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
- [UID:0001NP][0x005bc610-0x005c0034.MenuVarietyPanes](by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md)

## Changes

- 2026-06-29 B003 implementation callback:
  - Changed to `COMPLETION:87`, `CONFIDENCE:91`, and inserted the formal source definition `MenuVarietyPane *g_pMenuVarietyPane = NULL;`.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed zero-initialized bytes at `0x0069b4e8`, integer value `0`, and the nine-reference lifecycle: map-exit teardown, constructor publish, cleanup clear, four selector action-handler reads, selector notify/delete-helper read, and scalar deleting destructor clear. Exact storage child [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md) now emits a marker-only covered-by comment instead of duplicating this global definition.
- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0` with brief singleton/lifecycle notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, storage-cluster reference, IDA lifecycle evidence, selector consumer evidence, and teardown-consumer note.
  - Summary/evidence: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), [UID:0001NP][0x005bc610-0x005c0034.MenuVarietyPanes](by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md), and class docs for [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md) and [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md) support the role. Completion is capped because this page still uses the aggregate UI singleton storage page rather than a dedicated exact by-memory page.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000L8`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b4e8` and decompilation of `0x005bc610`, `0x005bc660`, and `0x005bfc80` prove NexusTK-owned `MenuVarietyPane` singleton storage owned by [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.

- 2026-06-06 xref/cleanup pass:
  - What existed before: the page still carried raw singleton labels, omitted the map-exit teardown consumer from the main evidence, and stayed at `78/84` despite all direct xrefs being identifiable.
  - Changed to: completion `84`, confidence `88`, initialized storage evidence, source-facing lifetime/consumer descriptions, and a direct MapPane teardown cross-reference.
  - Summary/evidence: live IDA MCP `xrefs_to`, `get_bytes`, `lookup_funcs`, `decompile`, and `disasm` on 2026-06-06 account for all nine direct xrefs, constructor publish/fallback behavior, cleanup/destructor clears, map-exit removal, selector action refreshes, and selector notify/delete helper reads. No final C++ body was added because the page remains below the 95/95 reconstruction gate and the exact source declaration is not yet final-audited.

- 2026-06-11 A005 Batch239: Raised `84/88` to `86/90` by linking the exact one-dword memory child [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md), verifying `0x4` / 4-byte storage with int_convert.py, and confirming [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) remains above the parent-side gate. This made the global page eligible as the direct parent for the exact storage child under the older gate; the 2026-06-29 B003 callback supersedes the old blank-C++ policy with a formal zero-initialized singleton definition.
