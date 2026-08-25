*** UID:0000RJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMenuVarietySelectPane

## Status

- Address: `0x0069bf78`
- Type kind: inferred singleton pointer.
- Final source type: `MenuVarietySelectPane* g_pMenuVarietySelectPane`.
- Likely owner: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Exact storage page: [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md)
- Confidence: very strong for identity, owner, zero-initialized storage, lifecycle, and source definition; medium-high for exact original declaration spelling/linkage.

## Role

`g_pMenuVarietySelectPane` points to the currently open selector spawned by [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md). The menu button checks this pointer to decide whether to draw the open-frame artwork, refresh the existing selector, or allocate a new [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md).

## Lifecycle

- `MenuVarietySelectPane::MenuVarietySelectPane` at `0x005bc970` assigns `this` to the global.
- `MenuVarietySelectPane::~MenuVarietySelectPane` at `0x005bcf80` clears the global to null after unregistering/removing the pane and destroying the menu label vector.
- The clear helper at `0x005bfbd0-0x005bfbdb` also clears this exact slot during the shared UI-pane destructor/thunk tail.
- Current MCP session `3fa0535f` reads the image dword as zero-initialized (`00 00 00 00` / integer `0`), so the accepted source definition is `MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;`. Older `0xffffffff` wording is historical and superseded for the active IDB.

## Consumers

- `MenuVarietyPane::HandleClick` at `0x005bc690` checks the pointer. A live selector is refreshed; otherwise a new selector is allocated and stored on the owner pane.
- `MenuVarietyPane::DrawMenuArtwork` at `0x005bc800` checks the pointer to choose the menu artwork load/display mode.
- Selector action handling uses the sibling [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md) to pulse the menu button before marking the session for deletion.

## Evidence

- IDA xrefs to `0x0069bf78` include the menu button click handler at `0x005bc690`, menu artwork draw at `0x005bc800`, `MenuVarietySelectPane::MenuVarietySelectPane` at `0x005bc970`, destructor at `0x005bcf80`, singleton clear helper at `0x005bfbd0`, and scalar deleting destructor at `0x005bfce0`.
- Live IDA MCP on 2026-06-05 reports 7 xrefs to `0x0069bf78`, including constructor writes at `0x005bc9c0` / `0x005bc9c7`, destructor clears at `0x005bcfd8` and `0x005bfd3f`, the clear helper at `0x005bfbd0`, and menu button consumers at `0x005bc73f` / `0x005bc825`.
- Decompilation on 2026-06-05 shows `0x005bc970` storing `this` into `dword_69BF78` and installing the `MenuVarietySelectPane` vtable, `0x005bcf80` and `0x005bfce0` clearing the slot during teardown, and `0x005bc800` checking the slot before choosing `MENUVAR.EPF` artwork mode.
- The former unresolved `dword_69bf78` clear helper at `0x005bfbd0` is therefore a `MenuVarietySelectPane` singleton clear helper, not a `UserStatusPane` singleton.
- IDA MCP on 2026-06-07 reconfirmed the same seven xrefs and callee/caller context: `0x005bc970` is called from the menu button click handler at `0x005bc765`, while the ordinary destructor, standalone clear helper, and scalar deleting destructor have no direct static callers but are vtable/destructor-tail code for the same selector class.
- 2026-06-29 B003 current MCP session `3fa0535f` `get_bytes` / `get_int` reads `00 00 00 00` / integer `0` at `0x0069bf78`; this resolves the stale initializer caveat and supports the formal source definition.

## Assignment Gate

This global remains attached to [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md). The direct file parent was refreshed to `86/85`, and this global is now `86/88`, so the corrected `85/85` gate is satisfied. Exact storage child [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md) now attaches here as the concrete four-byte `.data` slot.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0001NP][0x005bc610-0x005c0034.MenuVarietyPanes](by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md)

## Changes

- 2026-06-29 B003 implementation callback:
  - Changed to `COMPLETION:87`, `CONFIDENCE:90`, and inserted the formal source definition `MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;`.
  - Summary/evidence: current MCP session `3fa0535f` reconfirmed zero-initialized bytes at `0x0069bf78`, integer value `0`, and the seven-reference lifecycle: menu click/draw consumers, constructor publish/null fallback, ordinary destructor clear, standalone clear helper, and scalar deleting destructor clear. The older `0xffffffff` initializer note is historicalized as superseded active-IDB evidence. Exact storage child [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md) now emits a marker-only covered-by comment instead of duplicating this global definition.
- 2026-06-07 A006 Batch 060 parent-gate refresh:
  - What existed before: `82/84`, attached to [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) under the old gate while the file parent was still below corrected `85` confidence.
  - Changed to: `86/88`, retained `AUTOGEN_PARENT_UID:0000L8`, and documented the exact memory child [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md).
  - Summary/evidence: live IDA MCP reconfirmed all seven storage refs, constructor/destructor/clear-helper behavior, menu button consumers, and direct ownership by the MenuVarietyPanes file after its file-page confidence refresh.

- Completion/confidence score update:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`, with only the basic role and xref summary documented.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:84`, with explicit storage page, lifecycle, consumers, and unresolved initializer caveat.
  - Summary/evidence: exact storage is covered by [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md); constructor/destructor and click/draw consumers are documented in the menu-variety memory/class/file pages and refreshed IDA xrefs. The then-observed `0xffffffff` image-initializer caveat was superseded by the 2026-06-29 B003 active-IDB zero-initialization check.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000L8`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069bf78` and decompilation of `0x005bc970`, `0x005bcf80`, `0x005bfbd0`, and `0x005bfce0` prove NexusTK-owned `MenuVarietySelectPane` singleton storage owned by [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
