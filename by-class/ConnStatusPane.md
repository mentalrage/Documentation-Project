*** UID:000037 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConnStatusPane

## Status

- Confidence: strong for local class block, singleton, vtables, and event/update behavior; medium-high for final source placement and field names.
- Likely source file: [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- Address range: [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)

## Class Purpose

`ConnStatusPane` is the in-game connection-status indicator. It renders `CONNSTAT.EPD`, tracks recent response timings, maps latency to status frames, and reacts to selected server-message opcodes that imply connection/parcel status changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ConnStatusPane` | `0x00494520-0x004945e0` | Constructs pane, installs vtables, initializes timing/status slots, and sets `g_pConnStatusPane`. |
| vtable reset helper | `0x004945e0-0x00494609` | Restores ConnStatusPane vtables, clears singleton, and tail-jumps to the base destructor path. |
| state snapshot helper | `0x00494610-0x0049461f` | Unreferenced local helper that snapshots `g_pApplication + 0x18` into `this + 0x120`. |
| `OnPaint` | `0x00494620-0x004946b1` | Clears invalid state or renders the active `CONNSTAT.EPD` frame. |
| `HandleConnectionMessage` | `0x004946c0-0x00494765` | Handles selected opcodes and parcel notification state. |
| `UpdateConnectionFrame` | `0x004947a0-0x00494964` | Computes average response delta and updates status frame. |
| Destructor family | `0x00494964-0x004949df` | Adjustor thunks and scalar deleting destructor logic. |
| `SetConnecting` / `SetDisconnected` / `SetConnected` | `0x00544db0`, `0x00544dc0`, `0x00544dd0` | Shared base `Pane` wrappers referenced by this vtable and many other pane vtables. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms exact local ranges for constructor, vtable reset helper, state snapshot helper, paint, message handler, frame updater, destructor adjustors, and scalar deleting destructor.
- The constructor has one direct caller: `0x004f87ec` inside `0x004f7d10`, matching main UI graph setup.
- Constructor stores `g_pConnStatusPane` at `0x0069adf4`; the vtable reset helper and scalar deleting destructor clear it; `0x00504a32` reads it later.
- Constructor/vtable-reset/destructor stores use primary vtable `0x006179ec`, secondary vtable `0x00617a38`, and tertiary vtable `0x00617a68`.
- Primary vtable slot 17 (`0x00617a30`) points to `OnPaint`; slot 23 (`0x00617a48`) points to `HandleConnectionMessage`; slots `0x00617a38` and `0x00617a68` point to destructor adjustors.
- `HandleConnectionMessage` dispatches packet byte cases 4, 11, 21, and 38 through a jump table, checks global state at `0x0067a7c8`, calls `0x005055d0`, and calls `UpdateConnectionFrame` from two paths.
- `UpdateConnectionFrame` reads `dword_67AB80`, rolls a latency sample window, maps average response times around `0x190`, `0x320`, and `0x4b0` into frame ids, and invalidates the pane only when the frame changes.
- `0x00544db0`, `0x00544dc0`, and `0x00544dd0` are kept as base-pane dependencies. Live IDA reports broad vtable fan-in for these wrappers, including 79/72/120 data refs, even though `ConnStatusPane` uses them in its vtable.

## Cross-References

- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: construction, paint, message handling, frame update, destructor family, singleton ownership, and base-state caveat are documented; remaining uncertainty is mostly the base `Pane` setter ownership and exact member names.
- 2026-06-04: Raised from `72/80` to `84/86`, marked reconstructable, and attached to [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md).
  - Before: page had class behavior notes but no reconstructable/parent metadata, stale recovered-file provenance, no exact half-open ranges, and no vtable-slot or singleton-xref details.
  - After: live IDA evidence records executable identity, exact ranges, constructor caller, singleton writes/clear/read, primary/secondary/tertiary vtables, paint/message/destructor slots, message dispatch cases, latency thresholds, and base-wrapper fan-in counts.
  - Reasoning: parent [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md) now has a valid `NexusTK/network/` path and stronger live evidence, so class attachment is justified. Completion remains below final-code range because final member names and exact `network` versus `ui/status` source split are still provisional.
