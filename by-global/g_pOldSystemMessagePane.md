*** UID:0003ED | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class OldSystemMessagePane;

OldSystemMessagePane *g_pOldSystemMessagePane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pOldSystemMessagePane

## Status

- Address: `0x0069b4c8`.
- Kind: process-wide singleton pointer.
- Proposed type: `OldSystemMessagePane*`.
- Owner module: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md).
- Exact memory child: [UID:0002W7][0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane](by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md).

This global stores the legacy system-message pane instance used by the old gameplay UI layout. It is a source-level singleton declaration for the system-message pane module, while the exact address bytes remain documented on the by-memory child.

## Lifecycle

| Site | Access | Meaning |
| --- | --- | --- |
| `0x00588e7c` in `0x00588e30` | write `this` | `OldSystemMessagePane` constructor publishes the old-layout message pane singleton. |
| `0x00588e83` in `0x00588e30` | write `0` | Constructor fallback/null-adjusted path clears the same slot. |
| `0x005049c4` in `0x005047f0` | read | Gameplay exit/menu teardown removes the old system-message pane when the old UI path is active. |
| `0x00589180` helper family | read/write | Message-list support path uses the singleton while clearing or updating old message state. |
| `0x0058aac0` and `0x0058adb0` family | read/write | Old system-message cleanup/destructor paths clear the singleton during teardown. |
| `0x005b2d5a` | read | Old-mode `EmotionInputPane` `?` menu flow reads this pane, clears `+0x130` / inferred `m_refreshOnAppend`, appends the emotion menu through legacy helper calls, refreshes/prunes, and reopens the prompt. |

## Evidence

- Existing IDA-backed memory documentation reports `0x0069b4c8` as a `0x4` / 4-byte slot (Verified with int_convert.py) initialized to `ff ff ff ff`, with seven direct data xrefs.
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md) documents the constructor at `0x00588e30`, the destructor family ending at `0x0058af00`, the three `OldSystemMessagePane` vtable stores, and the direct old UI graph constructor caller at `0x004f8861`.
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) is the source module for the old/new system-message pane family and already clears the 85/85 parent gate.
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) records this slot as the first dword in a mixed message/status/menu singleton cluster; this global page exists so the exact child can attach to a narrow source-level owner instead of the mixed aggregate.
- 2026-06-26 B006 [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) source-quality implementation records the exact legacy Emotion consumer. When `g_useEpfAssets != 1`, `EmotionInputPane::OnCharInput` reads this singleton at `0x005b2d5a`, clears `+0x130` before batching the `?` emotion menu, calls `OldSystemMessagePane::AppendHeaderMarker()` (`0x00589330`), `AppendColoredText(...)` (`0x00589350`) for localized title id `31` and entry ids `15-30`, `AppendFooterMarker()` (`0x00589470`), and `RefreshAndPruneMessages()` (`0x005892a0`), then reopens `EmotionInputPane`. This is consumer/type evidence for the existing `OldSystemMessagePane *` singleton only and does not change [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) ownership.

## Ownership Decision

Declare this singleton with `SystemMessagePanes.cpp`. It belongs to the legacy system-message pane source family, not to the broad message/status/menu data cluster. The `OldSystemMessagePane` class page still has final field/helper-name caveats, so this global attaches directly to the file-level source module rather than forcing a class-owned static relationship.

## B011 Emission Disposition

Accepted B011 report `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` emits this singleton as formal source in `social/SystemMessagePanes.cpp`:

```cpp
class OldSystemMessagePane;

OldSystemMessagePane *g_pOldSystemMessagePane = 0;
```

The declaration is source-ready because exact storage [UID:0002W7][0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane](by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md) proves the old-pane singleton dword, constructor/fallback writes, old-mode consumers, clear helper, and destructor clear. The exact by-memory storage child carries address/xref proof and should not duplicate this declaration.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:0002W7][0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane](by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)

## Changes

- 2026-06-30 B011 accepted empty-emitter implementation:
  - Inserted formal singleton pointer declaration into `RECONSTRUCTION_CPP CODE`.
  - Added emission disposition tying this declaration to exact storage [UID:0002W7][0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane](by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md) and the old-pane lifecycle refs.
- 2026-06-11 A005 Batch236: Created as the dedicated by-global parent for the old-layout system-message pane singleton. Evidence comes from existing IDA-backed constructor/destructor/xref docs plus int-convert verification of the one-dword storage size.
- 2026-06-26 B006 EmotionInputPane support sync:
  - Scores remain `86/90`; owner/emitter [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) and blank formal C++ are preserved.
  - Added [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) legacy-mode `?` menu read at `0x005b2d5a`, `+0x130` batch-refresh clear, and helper family calls as consumer evidence only.
