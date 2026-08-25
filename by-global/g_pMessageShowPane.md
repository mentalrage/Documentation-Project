*** UID:0000RK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MessageShowPane;
MessageShowPane *g_pMessageShowPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMessageShowPane

## Status

- Confidence: very strong for active overlay singleton role, exact storage, external linkage, source owner, one-definition route, and direct Singleton specialization lifetime.
- Address: [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md)
- Symbol kind: global-data pointer
- Current IDA name: `g_pMessageShowPane`
- Final source type: `MessageShowPane *g_pMessageShowPane`.
- Likely owner file: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- Autogen parent: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), now that the file page clears the parent gate and records the constructor/destructor, packet-update, vtable, read-only data, and singleton evidence.
- Generated owner lead: `class_MessageShowPane.cpp` (lead only; IDA xrefs/decompilation are the authority).
- Reconstruction status: UID0000RK is the sole external-linkage definition at position `0` in UID0000LB `MessageShowPane.cpp`. Header/source reconstruction should expose `extern MessageShowPane *g_pMessageShowPane;`. Exact storage UID0001PX is non-emitting and must not duplicate the definition.

## Role

`g_pMessageShowPane` points to the current floating message overlay pane. Direct `Singleton<MessageShowPane>` base construction publishes the instance and reverse base destruction clears it; constructor, ordinary destructor, EH, and scalar-wrapper writes are compiler/inlined-base manifestations of that source declaration. External packet helper [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) requires external visibility to update, create, or close the overlay.

## Lifecycle And Consumers

- `MessageShowPane::MessageShowPane` at `0x00521da0` produces the publication stores through direct `Singleton<MessageShowPane>` base construction.
- [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) authors only `RemoveFromLayer()`; the later global clear is implicit Singleton base destruction.
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) is constructor-unwind duplication of Singleton base cleanup, not a handwritten standalone method.
- [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) duplicates ordinary/base teardown on the generated scalar-deleting path.
- [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md) reads the global at `0x005ac0bc` on the close path and at `0x005ac13f` on the update/create path. A zero `payload[1]` closes the current overlay through the virtual scalar deleting destructor with delete flag `1`; a nonzero flag updates an existing overlay through `MessageShowPane::SetWrappedText` at `0x00522530` or constructs `MessageShowPane(wideText)` at `0x00521da0` when the global is null.

## Xref Notes

IDA MCP checked on 2026-05-24:

- `0x00521da0` stores the constructed `MessageShowPane` pointer or clears the global on a null/invalid path.
- `0x00521fc0` is the ordinary source destructor clear, while `0x005226f0` and `0x00522720` are generated EH/scalar-wrapper duplicate clears.
- `0x005ac070` checks the pointer at `0x005ac0bc` and `0x005ac13f`, calls `0x00522530` to update existing text, constructs a new `MessageShowPane` if null, or deletes the current overlay through the scalar-deleting destructor path when the packet flag is zero.
- `0x005047f0` removes the current overlay from the layer during a broad UI/session cleanup path.

Rechecked on 2026-05-26:

- `xrefs_to 0x0069b4f4` reports constructor writes/clears at `0x00521e01` and `0x00521e08`, ordinary source destructor clear at `0x00522006`, EH cleanup clear at `0x005226f0`, generated scalar-wrapper clear at `0x0052276d`, and packet-handler reads at `0x005ac0bc` and `0x005ac13f`.
- The exact storage page is [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md).

Rechecked through live IDA MCP on 2026-05-31:

- `xrefs_to 0x0069b4f4` again reports the same eight data xrefs, including the `0x005048c4` UI cleanup reference.
- `lookup_funcs` resolves the referenced functions as `sub_521DA0` size `0x220`, `sub_521FC0` size `0x65`, `sub_5226F0` size `0x0b`, `sub_522720` size `0xa6`, `sub_5AC070` size `0x138`, and `sub_5047F0` size `0x37b`.
- `decompile` confirms constructor store/clear, ordinary destructor clear, EH cleanup clear, generated scalar-deleting destructor clear, packet update/create/delete behavior, and session/UI cleanup removal behavior.

Rechecked through live IDA MCP on 2026-06-16 by C001:

- Session `b001_mappane_0001AW_20260616` reported current zeroed storage bytes, the same eight data xrefs, constructor/ordinary-destructor/EH/scalar-wrapper writers, packet handler reads, and broad UI cleanup removal.
- `lookup_funcs` and `analyze_component` confirmed the modeled lifecycle functions at `0x00521da0`, `0x00521fc0`, `0x005226f0`, `0x00522720`, and packet handler `0x005ac070`.
- C001 saved `g_pMessageShowPane`, `MessageShowPaneConstructor`, `MessageShowPaneDestructor`, `MessageShowPaneClearSingletonEH`, `MessageShowPaneScalarDeletingDestructor`, and `HandleMessageShowPacket` in the IDB. The broad UI cleanup function at `0x005047f0` was intentionally not renamed because it owns many unrelated teardown paths.

## Generated Lead Evidence

- Active `simroot_v2/class_MessageShowPane.cpp` declares `MessageShowPane* g_pMessageShowPane;`.
- Its source map records `global-data:g_pMessageShowPane` with memory range `0x0069b4f4-0x0069b4f7` and `missing_memory_range_line_count: 0`.
- The same source map records constructor, destructor, and scalar-deleting destructor mappings at `0x00521da0`, `0x00521fc0`, and `0x00522720`, with mapped writes/clears to this global.
- Treat this generated mapping as a lead and consistency check only; the 2026-05-31 score change is based on live IDA MCP evidence above.

## Naming Caveat

Wave2 rename registry contains an early direct rename from `DAT_0069b4f4` to `g_pMessageShowPane`, while a later map row aliases the same raw symbol to `g_pExtendedUIPane`. Current exact class, storage, lifecycle, packet, and cleanup xrefs support `g_pMessageShowPane`; `g_pExtendedUIPane` is rejected as current source naming and retained only as historical search provenance.

## Parent Attachment Guidance

Use [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md) as the canonical owner/emitter for this global. The standalone source route is closed for reconstruction and requires one definition before the class/method children.

No derived method page owns a handwritten global assignment. UID0004HN, UID000492, UID0001C5, and UID0001C7 document inlined/direct-base lifecycle effects; UID0000RK alone emits the definition.

## Source Placement And One-Definition Policy

- Definition destination: UID0000RK, position `0`, in `NexusTK/ui/dialogs/MessageShowPane.cpp`.
- Header declaration: `extern MessageShowPane *g_pMessageShowPane;`, carried by the complete UID000087 class/header reconstruction.
- External linkage is required because UID0003UU consumes the pointer from LivingObjectPane.cpp.
- UID0001PX is exact binary backing storage under semantic owner UID0000RK and emits no source.
- A file-local `static` definition is rejected because it would not satisfy the cross-source packet consumer.
- A second definition on UID0001PX is rejected as an ODR violation and generated duplicate.

## Cross-References

- [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md)
- [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md)
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)
- [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md)

## Changes

- 2026-07-16 B002 UID0003PC implementation callback:
  - Raised `88/90` to `92/94`, retained owner/emitter UID0000LB and reconstructable true, and set position `0`.
  - Installed the sole external `MessageShowPane *g_pMessageShowPane = NULL;` definition and documented the header extern route.
  - Reclassified constructor/destructor/EH/scalar writes as direct Singleton base lowering, rejected duplicate/static definitions, closed standalone source placement, and historicalized `g_pExtendedUIPane`.
- 2026-06-27 B008 implementation callback: clarified the singleton lifecycle split so [UID:000492][0x00521fc0-0x00522025.MessageShowPaneDestructor](by-memory/0x00521fc0-0x00522025.MessageShowPaneDestructor.md) owns the source destructor clear and [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)/[UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) remain generated duplicate clear support.
- 2026-06-21 Rule 26 support sync from B011 [UID:0003UU][0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket](by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md):
  - Refined packet-handler consumer details with close-path read `0x005ac0bc`, update/create read `0x005ac13f`, scalar-deleting destructor close behavior, `SetWrappedText` update path, and constructor create path.
- Completion/confidence score update:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`, despite existing role/xref notes.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`, with explicit lifecycle, packet-handler consumers, exact source-map memory range, and validator-tracked cross references.
  - Summary/evidence: exact storage is documented at [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md); active `simroot_v2/class_MessageShowPane.cpp.source_map.json` maps the global data to `0x0069b4f4-0x0069b4f7`; class/file/range docs cover constructor/destructor/update/delete paths. Confidence remains below high because the historical `g_pExtendedUIPane` alias conflict still needs a wider surrounding-global cleanup pass.
- 2026-05-31 metadata/evidence update:
  - What existed before: `RECONSTRUCTABLE` was blank, score remained `84/82`, and the page still contained a stale note that IDA MCP was unavailable during the last score pass.
  - Changed to: `RECONSTRUCTABLE:TRUE`, completion `86`, confidence `86`, and a current live IDA MCP recheck section.
  - Summary/evidence: live IDA MCP `xrefs_to`, `lookup_funcs`, and `decompile` verified the exact storage slot, lifecycle writers, packet-handler readers, and cleanup path. Scores remain below `95` because source-file placement and the historical alias conflict still require a wider audit.
- 2026-06-07 A007 parent attachment:
  - What existed before: `AUTOGEN_PARENT_UID` was blank even though [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md) now clears the parent gate and lists this singleton in its proposed contents.
  - Changed to: `AUTOGEN_PARENT_UID:0000LB`, added explicit autogen-parent status, and recorded attachment guidance.
  - Summary/evidence: the file page records the overlay constructor/destructor cluster, `MessageShowPaneSetWrappedText`, vtable/read-only data, packet-handler behavior, and [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md). No score or final C++ change was made because the original source split and historical alias conflict remain open.
- 2026-06-16 C001 Goal 2 global/IDA refresh: raised `86/86` to `88/90` after live IDA reconfirmed current bytes, eight xrefs, lifecycle writers, packet create/update/delete reads, cleanup consumer, direct owner route through [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), and saved the singleton plus lifecycle/packet-handler names in the IDB. Final C++ remains blank because the `MessageShowPane.cpp` versus compact `MessageDialogs.cpp` split and exact declaration/header placement remain unresolved.
