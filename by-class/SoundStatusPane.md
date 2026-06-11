*** UID:0000DJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SoundStatusPane

## Status

- Confidence: strong for behavior and range, medium-high for exact inherited base names.
- Likely source module: [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- Main range: [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- Singleton global: [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- Evidence basis: live IDA MCP function, xref, byte, decompilation, and instruction checks through 2026-06-06.

## Responsibility

`SoundStatusPane` is a compact HUD/control pane for sound and music state. It displays the current sound-effect and music enabled state, handles keyboard shortcuts for toggling them, and forwards actual playback changes to [UID:0000NV][SoundManager](by-file/SoundManager.md) and the global MIDI player.

## Layout Evidence

- Constructor writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`, matching one primary pane object plus two adjustor subobjects.
- Constructor writes bounds-like fields at `0xf8`, `0xfc`, `0x100`, and `0x104`.
- `HandleSoundHotkeys` receives a subobject `this` pointer and subtracts `0xa0` before invoking the owner pane repaint slot.
- Vtable addresses observed by IDA: `0x0062cef4`, `0x0062cf40`, and `0x0062cf70`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x0057bf70-0x0057c04d` | constructor | Registers singleton, installs vtables, computes bottom-right bounds from screen dimensions. |
| `0x0057c050-0x0057c079` | cleanup helper | Reinstalls vtables, clears singleton, calls shared pane-base cleanup. |
| `0x0057c080-0x0057c15b` | `HandleSoundHotkeys` | Handles key event type `8`; `modifier == 2 && 'm'` toggles SFX/config byte, `modifier & 2 && 'M'` toggles music/MIDI. |
| `0x0057c160-0x0057c23e` | `RefreshSoundStatusText` | Resets selector/page state and sets caption to `Sound On/Off` plus `Music On/Off`. |
| `0x0057c240-0x0057c24b` | singleton clear helper | Clears [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md). |
| `0x0057c24b-0x0057c256` | adjustor thunk | Subtracts `0xa0` and forwards to scalar deleting destructor. |
| `0x0057c256-0x0057c261` | adjustor thunk | Subtracts `0xa4` and forwards to scalar deleting destructor. |
| `0x0057c270-0x0057c2cf` | scalar deleting destructor | Clears singleton, calls shared pane cleanup, and optionally frees object storage. |

## External State

- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) at `0x0069b4d4`.
- `g_pSoundManager` at `0x0067a7d0` for music/sound enabled state and toggles.
- `g_pMidiPlayer` at `0x0067ab4c` for MIDI play/stop state.
- `g_pConfig` at `0x0067a7c8`, sound-enabled byte at offset `0x28de48`.
- `g_screenWidth` at `0x0066da94` and `g_screenHeight` at `0x0066da98`.

## Open Questions

- Confirm the final inherited base class naming for the status-text/control pane hierarchy. Current decompiler type recovery names `TextButtonExControlPane` in destructor paths, but IDA only proves the shared pane-base cleanup target.
- Decide whether the final header declares the three vtables explicitly or keeps them as compiler-emitted artifacts in type docs.
- Review whether the constructor's stack `RectBounds` creation feeds a hidden/base-side side effect or is dead local initialization after decompilation.

## Cross-References

- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents HUD/control responsibility, layout/vtable evidence, method ranges, singleton/global state, sound/MIDI/config interactions, and open inherited-base questions.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, cleanup helper, hotkey handler, caption refresh, singleton-clear helper, adjustor thunks, and scalar deleting destructor at `0x0057bf70`, `0x0057c050`, `0x0057c080`, `0x0057c160`, `0x0057c240`, `0x0057c24b`, `0x0057c256`, and `0x0057c270`. The likely parent file meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
- 2026-06-06: Raised confidence from `78` to `84` and attached the class to [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md).
  - Reasoning: current live IDA MCP verifies the class method inventory, both constructor callers from `InitializeMainUiGraph`, singleton bytes and six refs, hotkey behavior, caption formatting, cleanup helpers, adjustor thunks, and scalar deleting destructor. Remaining uncertainty is limited to final inherited base naming.
  - Summary and evidence: constructor `0x0057bf70`, cleanup `0x0057c050`, hotkey handler `0x0057c080`, caption refresh `0x0057c160`, singleton clear `0x0057c240`, thunks `0x0057c24b`/`0x0057c256`, scalar deleting destructor `0x0057c270`, constructor calls `0x004f8460`/`0x004f89c7`, and `g_pSoundStatusPane` lifecycle refs are all live-verified.
