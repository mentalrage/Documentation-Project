*** UID:00009C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewSystemMessagePane

## Status

- Confidence: strong for class role and IDA boundaries; tiny virtual helper names remain provisional.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewSystemMessagePane.cpp`; constructor currently appears in `class_NewSystemMessageModifyHeightPane.cpp`

## Class Purpose

`NewSystemMessagePane` is the newer system-message panel wrapper. It manages child message panes, rebuilds the scrollable message pane when the available row count changes, refreshes a child world-map pane, and draws an EPF/tile-backed panel background.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00588560-0x00588797` | `NewSystemMessagePane::NewSystemMessagePane()` | Constructs panel wrapper, stores [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md), creates height handle, `SpelledPane`, and child `SystemMessagePane`. Active generated source emits this in the height-pane file. |
| `0x00588800-0x00588c0c` | `RebuildMessagePanes(int newMessageCount)` | Rebuilds child message panes, clones existing and incoming messages, and scrolls to bottom. |
| `0x00588d50-0x00588d6e` | `RefreshWorldMapPane()` | Restarts/registers the embedded world-map child. |
| `0x00588d90-0x00588dfb` | `OnPaint()` | Draws the tiled panel background. |
| `0x00588e00-0x00588e15` | Tiny virtual helpers | Two 5-byte helpers listed by Wave3, omitted from current emitted source. |
| `0x0058aab0-0x0058aaba` | singleton clear helper | Clears `g_pNewSystemMessagePane`. Active generated output omits this body. |
| `0x0058ab07-0x0058ab1d` | Adjustor/thunk helpers | Vtable-referenced destructor thunks, omitted from current emitted source. |
| `0x0058ad20-0x0058adab` | `ScalarDeletingDestructor(char flags)` | Destroys child panes, clears `g_pNewSystemMessagePane`, destroys the panel base, and optionally deletes. |

## Evidence Notes

- Wave3 grades the class at effective `97.0`.
- IDA MCP confirms all listed starts as exact functions.
- Older Wave2 notes identify `RefreshWorldMapPane` as a restored `NewSystemMessagePane` method called from `LivingObjectPane::HandleServerEntryPacket`.
- IDA `xrefs_to 0x0069bc10` confirms the singleton writes/clears in constructor, clear helper, and destructor, plus use from [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md).
- 2026-05-25 IDA recheck: the constructor at `0x00588560` is directly called from `GeneralPurposePanel2` construction at `0x004b88ae`; it writes `g_pNewSystemMessagePane`, creates `NewSystemMessageModifyHeightPane`, `SpelledPane`, and child `SystemMessagePane`, and installs `NewSystemMessagePane` vtables.
- Current `simroot_v2/class_NewSystemMessagePane.cpp` still lacks the constructor body, while `class_NewSystemMessageModifyHeightPane.cpp` still emits `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560`; keep this as a generated-file partition issue, not source ownership evidence.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md)

## Changes

- Before: completion/confidence metadata were `0/0` while the page already documented class role, constructor partition issue, child-pane rebuild behavior, singleton evidence, and destructor support.
- Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
- Evidence: the page contains IDA-backed function starts, constructor caller evidence, singleton xrefs, method roles, and generated-file caveats; remaining gaps are the tiny virtual helper names and final source-file partition correction.
