*** UID:0003EI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserListDialogPane *g_pUserListDialogPane = NULL;
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Source-authored zero-initialized UserListDialogPane singleton pointer definition for exact storage at 0x0069b4e0, with one class-level extern, one module definition, twelve lifecycle/consumer refs, implicit Singleton<UserListDialogPane> publish/clear at +0x26c, exact false storage child, and no handwritten lifecycle mechanics. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# g_pUserListDialogPane

## Status

- Symbol kind: source-authored module pointer definition used by the direct `Singleton<UserListDialogPane>` base.
- Address: `0x0069b4e0`.
- Fresh dated 2026-08-13 multi-view IDA readback in attested canonical session `supervisor-uid0004HB-gate2b-20260813T1105Z`: both `entity_query(globals)` and `list_globals` return explicit current global name `g_pUserListDialogPane` at `0x0069b4e0`. `inspect_items` separately reports a blank containing-item name field for exact item `[0x0069b4e0,0x0069b4e1)`, size one, type `UserListDialogPane *`, neither code nor modeled data. These views are not contradictory: the global-entity APIs expose the named global identity, while the item-model API exposes the narrower containing item's blank name field. The explicit global name is current protected authority; the older conclusion that the global itself was unnamed is superseded and retained only as historical interpretation.
- Exact source type: `UserListDialogPane *`.
- Owner/emitter file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
- Related class: [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md).
- Exact storage child: [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md).
- Confidence: very strong for address, zero-filled storage, pointer type, one extern/definition split, lifecycle xrefs, and feature-file ownership; original linkage spelling remains the bounded cap.

## Role

`g_pUserListDialogPane` is the one zero-initialized module pointer definition for the currently active social user-list dialog. The class page provides one `extern UserListDialogPane *g_pUserListDialogPane;` declaration. Direct Singleton base construction publishes the instance, user-list/menu command paths test the slot before opening or closing the dialog, and generated base/EH/destructor paths clear or consume it during cleanup.

This is treated as module-level singleton storage for [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), not as a separate source file. The pointee class [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md), the feature file, and this global page all meet the strict `85/85` gate, so this page can serve as the direct global parent for the exact memory slot.

## Score Rationale

- Completion `92`: this page records and emits the exact one-definition contract, address/zero bytes, exact false storage child, owner file, class extern, direct Singleton base/RTTI/EBO lifecycle, twelve publish/clear/guard/consumer refs, neighboring slots, and compiler/source separation.
- Confidence `94`: the one-dword storage identity, direct-base lifecycle, feature owner, class declaration, generated missing-definition diagnosis, and complete xref family agree. Original linkage spelling and one raw-site label remain lexical caps.

## Evidence Notes

- Historical read-only MCP snapshot `supervisor-uid0002OW-gate2b-20260813T0115Z` reported containing item `[0x0069b4e0,0x0069b4e1)`, size one in the item model, blank item-view name field, type `UserListDialogPane *`, neither code nor modeled data, blank regular/repeatable address comments, and 12 xrefs. The item-view facts remain valid evidence; only the earlier inference that a blank item-view field meant the global itself was unnamed is superseded.
- Fresh public `runtime_attestation` returned `ok:true` at `2026-08-13T12:02:37.145258Z` for canonical session `supervisor-uid0004HB-gate2b-20260813T1105Z` and `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. In that snapshot, `entity_query(globals)` and `list_globals` independently returned `g_pUserListDialogPane` at `0x0069b4e0`; `inspect_items` retained exact containing item `[0x0069b4e0,0x0069b4e1)`, size one, blank item-view name field, type `UserListDialogPane *`, neither code nor modeled data; regular and repeatable address comments were blank; `xref_query` returned exactly 12 inbound data xrefs; bytes were `00 00 00 00`; and address/name global-value reads both returned `0x0`. This establishes an explicit named global over a separately unnamed item-model view and protects the current name from rename, retype, resize, or reshaping. UID00047Q A006 is therefore regular address-comment-only.
- [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md) records the exact `0x4` / 4-byte `.data` slot (Verified with int_convert.py). Exact bytes are `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; the false child records linker storage and must not duplicate source.
- Constructor publish/fallback references occur at `0x0059bce4` and `0x0059bceb` inside [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md).
- Exact twelve refs are broad UI consumer `0x005087c2`, lazy-open guard `0x00513c43`, constructor publish/fallback `0x0059bce4/0x0059bceb`, raw constructor-cleanup tail `0x0059d1d4`, active-list consumer `0x0059e4cf`, close/open consumers `0x0059ed8f/0x0059eea1`, EH clear `0x0059efe0`, scalar-wrapper clear `0x0059f14a`, UserPane dispatcher `0x005a7c97`, and retained duplicate-helper consumer `0x005abc28`.
- [UID:00047S][0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport](by-memory/0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md) is exact 11-byte compiler-generated template destructor support reached only from constructor EH cleanup. Its formal block is blank; the source class/base declaration regenerates the clear.
- RTTI `0x00651c68-0x00651ccc` places direct `Singleton<UserListDialogPane>` at PMD `+0x26c` with EBO overlap, and UID000470 constructs that base before DialogPane. Constructor instructions adjust from that base to the complete object and publish the pointer. This proves implicit publish/clear lifecycle around one ordinary module definition, not handwritten stores or a duplicate template body.
- The adjacent split-index slots identify this as part of the dense UI singleton run: predecessor `0x0069b4dc` is [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), successor `0x0069b4e4` is [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md), and the enclosing non-emitting index is [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md).
- The file-level page [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) documents the active singleton as direct module state alongside [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md) and the user-list layout globals.
- Current generated source previously had the class extern and consumers but no definition, followed by an Empty Emitter Marker for this page. Accepted project analogs `g_pHourPane` and `g_pMapNamePane` use one zero-initialized by-global definition, a false physical child, and implicit singleton lifecycle. This exact definition closes the compile/link contract and removes the marker.

## Assignment Decision

Keep this source global attached to and emitted by [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md). Emit exactly the one zero-initialized definition above, retain the one class-level extern, and keep UID0002WD false/blank as physical storage. Reject a second declaration/definition, file-local `static`, explicit template specialization body, and handwritten constructor/EH/destructor publish-clear mechanics.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md)

## Changes

- 2026-08-13 B001 UID00047Q Gate 2A C029 repair: added the fresh attested multi-view name evidence that `entity_query(globals)` and `list_globals` expose explicit current global `g_pUserListDialogPane` while `inspect_items` retains a blank containing-item name field; preserved the older item-view evidence as valid dated history, historicalized only the superseded unnamed-global interpretation, and recorded the exact one-byte item/type/comment/xref/zero-value protections and comment-only IDA disposition without changing source, metadata, ownership, or lifecycle evidence.

- 2026-08-13 B001 UID00047Q accepted implementation callback: preserved `92/94`, owner/emitter UID0000OZ, one-definition formal source, exact storage child, type/address/lifecycle/xref/source-ownership evidence, and all prior history; replaced only the active stale `dword_69B4E0` status with the dated unnamed `UserListDialogPane *` readback and retained the raw label explicitly as historical IDA evidence.

- 2026-07-20 B005 UID00047H expanded implementation callback:
  - Raised only `90/94 -> 92/94`, preserved owner/emitter UID0000OZ, true, blank position, address/name/type, and applied the exact one-definition formal plus `[[CHILDREN]]`.
  - Added the exact storage hash, twelve xrefs, class extern/module definition/false child separation, direct Singleton RTTI/base/publish-clear lifecycle, generated marker diagnosis, accepted analogs, compiler exclusions, and rejected duplicate/static/template/explicit-lifecycle alternatives.
  - Historicalized B004's template-only/no-definition conclusion as superseded; the direct Singleton still owns implicit lifecycle, but it does not eliminate the translation-unit definition required by the existing extern and consumers.

- 2026-07-14 B004 UID000470 implementation callback:
  - Raised `86/90 -> 90/94`, preserved owner/emitter UID0000OZ and the blank managed block, and retained the semantic alias `g_pUserListDialogPane` for the exact zero-filled storage child.
  - Reclassified the role from an independent module pointer plus handwritten clear helper to `Singleton<UserListDialogPane>` specialization backing storage, supported by direct RTTI/base order, EBO overlap, twelve refs, and UID00047S's EH-only generated cleanup.
  - At that evidence-time stage rejected a standalone definition as duplicate. The later expanded direct audit proved the generated translation unit had an extern and consumers but no definition; the accepted one-definition formal above supersedes only that conclusion while retaining the template/explicit-helper exclusions.

- 2026-06-11 A005 Batch239: Created the direct by-global parent for the exact `0x0069b4e0` user-list singleton slot and set it to `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md). Evidence comes from the existing IDA-backed exact memory child, the user-list feature file/class pages, and the surrounding singleton split-index cluster. This closes the previous parentless state for [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md).
- 2026-06-18 B001 support rename: Updated sibling global references from stale `g_bShowHiddenUsers` to [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md) after B001 resolved the `0x0069bed0` flag as hunters-list-only filtering.
- 2026-06-26 B002 split implementation support sync:
  - Added the exact [UID:00047S][0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport](by-memory/0x0059efe0-0x0059efeb.UserListDialogPaneSingletonDestructorSupport.md) child link for the `0x0059efe0` clear helper and preserved constructor publish/destructor cleanup evidence. Owner/emitter and blank formal C++ remain unchanged.
