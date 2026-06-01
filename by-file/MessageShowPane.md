*** UID:0000LB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MessageShowPane

## Status

- Confidence: strong for overlay source grouping; medium for whether the final original file was separate or part of `MessageDialogs.cpp`.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/MessageShowPane.cpp`
- Current generated sources: `class_MessageShowPane.cpp`; older generated/cache evidence attached `0x00522530` to `class_FittingRoomDownloadControlPane.cpp`, but current `simroot_v2` emits it in `class_MessageShowPane.cpp`.
- Evidence basis: IDA MCP boundary/xref/decompilation checks on 2026-05-24 through 2026-05-31. `simroot_v2`, Wave3 cache indexes, and older Wave2 rename/report data are lead/history sources only.

## Hypothesis

`MessageShowPane` was likely a small overlay source module rather than part of the packet-driven NPC/menu-question dialog file. It owns the active floating message pane singleton, wraps wide text to a fixed 288-pixel width, positions the pane near the right edge of the play area, and draws layered shadow/face text rows.

Likely structure:

```text
ui/dialogs/MessageShowPane.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/MessageDialogs.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:000087][MessageShowPane](by-class/MessageShowPane.md) | `0x00521da0-0x005227c6`, exact [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md), [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) | `class_MessageShowPane.cpp` | Floating overlay pane, text wrapping/layout, shadow/face text drawing, and deletion lifecycle. |
| [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md) | [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md) | `class_MessageShowPane.cpp` global-data alias | Active message overlay singleton. |
| `HandleMessageShowPacket` | `0x005ac070-0x005ac1a7` | currently outside MessageShowPane | Server packet handler that creates, updates, or closes the active message overlay. |

## Behavior Model

- Constructor copies a wide message buffer at `this + 0xf8`, counts newline-delimited lines using `g_wszNewline` (`0x00610668`), measures each segment, clamps maximum width to `288`, and attaches to render layer `0x0069b364`.
- `BuildMessageTextButtons` draws each line multiple times with palette `143` for shadow and palette `128` for face text.
- [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md) at `0x00522530` replaces the stored text, recomputes metrics, reapplies the overlay bounds, and refreshes/rebuilds child text rows.
- Packet handler `0x005ac070` reads an on/off flag, converts ANSI packet text to wide text, updates the existing `g_pMessageShowPane` via `0x00522530`, or allocates a new `MessageShowPane` when no overlay exists. If the flag is zero, it deletes the current overlay.

## Boundary Notes

- IDA confirms normal function starts at `0x00521da0`, `0x00521fc0`, `0x00522030`, `0x00522530`, `0x005226f0`, `0x005226fb`, `0x00522706`, and `0x00522720`.
- `0x00522530-0x005226ea` was historically owned by `FittingRoomDownloadControlPane` in Wave2/Wave3-derived data, but current `simroot_v2` emits it as `MessageShowPane::SetWrappedText`. IDA xrefs show the only direct caller is the message overlay packet handler at `0x005ac150`; its data layout and singleton flow are `MessageShowPane`-specific.
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) is a tiny constructor EH singleton-clear helper, referenced by the constructor's exception/unwind path. It is documented and ignored as standalone source.
- [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) are compiler-generated destructor adjustor thunks into `0x00522720`.
- `g_applyMessagePaneBorder` is Wave3-owned by `class_MessageShowPane.cpp`, but IDA xrefs show address `0x0069b3fc` is a broad UI drawing callback/table used across many panes. Do not make it a MessageShowPane-owned global solely from the current generated source.
- Rename registry evidence conflicts on `0x0069b4f4`: an older row names it `g_pMessageShowPane`, while a later map row aliases `DAT_0069b4f4` to `g_pExtendedUIPane`. The direct constructor/destructor/update xrefs support `g_pMessageShowPane` for this use.
- 2026-05-31 live IDA MCP recheck of [UID:0001PX][0x0069b4f4-0x0069b4f8.g_pMessageShowPane](by-memory/0x0069b4f4-0x0069b4f8.g_pMessageShowPane.md) confirms constructor store/clear, destructor clear, EH cleanup clear, scalar deleting destructor clear, packet-handler reads, and broad UI cleanup removal. This strengthens `MessageShowPane` ownership of the singleton, but it does not close the final split between `MessageShowPane.cpp` and `MessageDialogs.cpp`.

## Migration Notes

Use dry-run only until the remaining EH/thunk and alias caveats are reconciled:

```powershell
python source-3\wave3.py create file MessageShowPane.cpp --kind source --simpath ui/dialogs/MessageShowPane.cpp --dry-run
python source-3\wave3.py attach class MessageShowPane --to-file MessageShowPane.cpp --dry-run
python source-3\wave3.py attach method 0x00522530 --to-file MessageShowPane.cpp --dry-run
python source-3\wave3.py set global-data-owner g_pMessageShowPane MessageShowPane.cpp --dry-run
```

Verify the exact Wave3 command spelling for attaching methods before any real migration.

## Cross-References

- [UID:000087][MessageShowPane](by-class/MessageShowPane.md)
- [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md)
- [UID:0001C4][0x00522530-0x005226ea.MessageShowPaneSetWrappedText](by-memory/0x00522530-0x005226ea.MessageShowPaneSetWrappedText.md)
- [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md)
- [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md)
- [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md)
- [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page has detailed class/global/range ownership, packet-handler behavior, boundary notes, migration notes, and cross-references; confidence remains below strong-high because the final original source split between `MessageShowPane.cpp` and `MessageDialogs.cpp` is still open.
- 2026-05-31 evidence-basis correction:
  - What existed before: the status line mixed generated `simroot_v2`/Wave3/Wave2 leads with IDA checks as if they were comparable evidence.
  - Changed to: IDA MCP is explicitly listed as the authority, while generated/cache/rename data is marked as lead/history only.
  - Summary/evidence: live IDA MCP rechecked the singleton slot and class lifecycle xrefs on 2026-05-31; the final source-file split remains open, so the projected path line intentionally remains blank.
