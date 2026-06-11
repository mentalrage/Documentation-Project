*** UID:0000RK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMessageShowPane

## Status

- Confidence: strong for active overlay singleton role and exact storage; medium-high for final canonical name because rename registry has a conflicting later alias.
- Address: [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md)
- Symbol kind: global-data pointer
- Final source type: `MessageShowPane* g_pMessageShowPane`.
- Likely owner file: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- Autogen parent: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), now that the file page clears the parent gate and records the constructor/destructor, packet-update, vtable, read-only data, and singleton evidence.
- Generated owner lead: `class_MessageShowPane.cpp` (lead only; IDA xrefs/decompilation are the authority).
- Reconstruction status: attach as source-declared `MessageShowPane` overlay singleton storage; keep final C++ blank until the `MessageShowPane.cpp` versus `MessageDialogs.cpp` split and the historical `g_pExtendedUIPane` alias conflict are reconciled.

## Role

`g_pMessageShowPane` points to the current floating message overlay pane. `MessageShowPane` construction stores the active instance, the destructor and scalar deleting destructor clear it, and the message overlay packet handler at `0x005ac070` uses it to decide whether to update, create, or close the overlay.

## Lifecycle And Consumers

- `MessageShowPane::MessageShowPane` at `0x00521da0` writes `this` to the global after constructing the base pane.
- `MessageShowPane::~MessageShowPane` at `0x00521fc0` removes the overlay from its layer and clears the global.
- `0x005226f0` is the constructor EH singleton-clear helper; it should not become a handwritten standalone method.
- `MessageShowPane::ScalarDeletingDestructor` at `0x00522720` also clears the singleton on the scalar-deleting path.
- The message overlay packet handler at `0x005ac070` reads the global, calls `MessageShowPane::SetWrappedText` at `0x00522530` when an overlay already exists, constructs a new overlay when null, or deletes the current overlay when the packet disables it.

## Xref Notes

IDA MCP checked on 2026-05-24:

- `0x00521da0` stores the constructed `MessageShowPane` pointer or clears the global on a null/invalid path.
- `0x00521fc0`, `0x005226f0`, and `0x00522720` clear the global.
- `0x005ac070` checks the pointer, calls `0x00522530` to update existing text, constructs a new `MessageShowPane` if null, or deletes the current overlay when the packet flag is zero.
- `0x005047f0` removes the current overlay from the layer during a broad UI/session cleanup path.

Rechecked on 2026-05-26:

- `xrefs_to 0x0069b4f4` reports constructor writes/clears at `0x00521e01` and `0x00521e08`, destructor clear at `0x00522006`, EH cleanup clear at `0x005226f0`, scalar destructor clear at `0x0052276d`, and packet-handler reads at `0x005ac0bc` and `0x005ac13f`.
- The exact storage page is [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md).

Rechecked through live IDA MCP on 2026-05-31:

- `xrefs_to 0x0069b4f4` again reports the same eight data xrefs, including the `0x005048c4` UI cleanup reference.
- `lookup_funcs` resolves the referenced functions as `sub_521DA0` size `0x220`, `sub_521FC0` size `0x65`, `sub_5226F0` size `0x0b`, `sub_522720` size `0xa6`, `sub_5AC070` size `0x138`, and `sub_5047F0` size `0x37b`.
- `decompile` confirms constructor store/clear, destructor clear, EH cleanup clear, scalar-deleting destructor clear, packet update/create/delete behavior, and session/UI cleanup removal behavior.

## Generated Lead Evidence

- Active `simroot_v2/class_MessageShowPane.cpp` declares `MessageShowPane* g_pMessageShowPane;`.
- Its source map records `global-data:g_pMessageShowPane` with memory range `0x0069b4f4-0x0069b4f7` and `missing_memory_range_line_count: 0`.
- The same source map records constructor, destructor, and scalar-deleting destructor mappings at `0x00521da0`, `0x00521fc0`, and `0x00522720`, with mapped writes/clears to this global.
- Treat this generated mapping as a lead and consistency check only; the 2026-05-31 score change is based on live IDA MCP evidence above.

## Naming Caveat

Wave2 rename registry contains an early direct rename from `DAT_0069b4f4` to `g_pMessageShowPane`, but a later map row aliases the same raw symbol to `g_pExtendedUIPane`. Current direct xrefs in the message overlay cluster support `g_pMessageShowPane` for this role. Treat `g_pExtendedUIPane` as a suspect broader alias until a wider global cleanup pass reconciles the surrounding `0x0069b4xx` pane singleton group.

## Parent Attachment Guidance

Use [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md) as the autogen parent for this global. The file page is now above the `80/80` parent gate and ties the overlay constructor, destructor, scalar-deleting destructor, wrapped-text updater, packet handler, vtable/read-only data, and exact singleton storage into one source-root chain. This attachment is a source ownership link only; it does not settle whether the original source emitted a standalone `MessageShowPane.cpp` file or a compact `MessageDialogs.cpp` grouping.

## Cross-References

- [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md)
- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md)

## Changes

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
