*** UID:000037 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConnStatusPane

## Status

- Confidence: strong for local class block; medium for the base-pane state setter rows.
- Likely source file: [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- Address range: [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)
- Current recovered file: `source-3/simroot_v2/class_ConnStatusPane.cpp`

## Class Purpose

`ConnStatusPane` is the in-game connection-status indicator. It renders `CONNSTAT.EPD`, tracks recent response timings, maps latency to status frames, and reacts to selected server-message opcodes that imply connection/parcel status changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ConnStatusPane` | `0x00494520` | Constructs pane, installs vtables, initializes timing/status slots, and sets `g_pConnStatusPane`. |
| `OnPaint` | `0x00494620` | Clears invalid state or renders the active `CONNSTAT.EPD` frame. |
| `HandleConnectionMessage` | `0x004946c0` | Handles selected opcodes and parcel notification state. |
| `UpdateConnectionFrame` | `0x004947a0` | Computes average response delta and updates status frame. |
| Destructor family | `0x00494964`, `0x0049496f`, `0x00494980` | Adjustor and scalar deleting destructor logic. |
| `SetConnecting` / `SetDisconnected` / `SetConnected` | `0x00544db0`, `0x00544dc0`, `0x00544dd0` | Listed by Wave3 under `ConnStatusPane`, but canonical owner appears to be base `Pane`. |

## Evidence Notes

- IDA confirms all local class-block function starts.
- Existing Wave2 notes classify the three `0x00544d*` state setters as canonical `Pane` methods with stale `ConnStatusPane` shadow rows.
- `InitializeMainUiGraph` constructs this pane in the main in-game UI layout.

## Cross-References

- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: construction, paint, message handling, frame update, destructor family, singleton ownership, and base-state caveat are documented; remaining uncertainty is mostly the base `Pane` setter ownership and exact member names.
