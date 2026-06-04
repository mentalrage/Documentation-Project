*** UID:0000IF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ConnStatusPane

## Status

- Confidence: strong for the core `ConnStatusPane` class and singleton/vtable evidence; medium-high for final file placement.
- Proposed module folder: `network/` or `ui/status/`
- Proposed source file: `network/ConnStatusPane.cpp`
- Evidence basis: live IDA MCP/disassembly boundary, vtable, singleton, caller, paint/message/update, and destructor checks.

## Hypothesis

`ConnStatusPane` is the in-game connection-status indicator. It samples request/response timing, maps latency to a `CONNSTAT.EPD` frame, paints the frame with `NPAL7.PAL`, and reacts to selected server-message opcodes to update connection/parcel-notification state.

The class is game-network UI rather than generic pane core. A practical source placement is:

```text
network/ConnStatusPane.cpp
network/ConnStatusPane.h
```

If the final tree separates networking transport from UI, `ui/status/ConnStatusPane.cpp` is also plausible.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ConnStatusPane` | `0x00494520-0x004949df` | `ConnStatusPane.cpp` | Constructor, vtable reset helper, state snapshot helper, paint, connection-message handler, latency-frame update, and destructor family. |
| `Pane::SetConnecting` / `SetDisconnected` / `SetConnected` | `0x00544db0-0x00544dd9` | `Pane.cpp` | Shared base-pane virtual wrappers reused by many vtables, including `ConnStatusPane`; not class-local source. |
| `g_pConnStatusPane` | `0x0069adf4` | `ConnStatusPane.cpp` | Singleton pointer for the active status pane. |

## Boundary Notes

- Live IDA on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms local functions at `0x00494520-0x004945e0`, `0x004945e0-0x00494609`, `0x00494610-0x0049461f`, `0x00494620-0x004946b1`, `0x004946c0-0x00494765`, `0x004947a0-0x00494964`, `0x00494964-0x0049496f`, `0x0049496f-0x0049497a`, and `0x00494980-0x004949df`.
- `0x004f87ec` inside `0x004f7d10` is the sole constructor caller, matching main UI graph setup.
- Constructor and destructor paths write `g_pConnStatusPane` at `0x0069adf4`; another live xref reads it at `0x00504a32`.
- Constructor/vtable-reset/destructor stores use primary vtable `0x006179ec`, secondary vtable `0x00617a38`, and tertiary vtable `0x00617a68`.
- `ConnStatusPane` vtable slots place paint at `0x00617a30 -> 0x00494620`, message handling at `0x00617a48 -> 0x004946c0`, and destructor adjustors at `0x00617a38 -> 0x00494964` / `0x00617a68 -> 0x0049496f`.
- The `0x00544db0`, `0x00544dc0`, and `0x00544dd0` methods appear in `ConnStatusPane` slots but are shared base-pane wrappers: live IDA reports broad vtable fan-in for all three, including 79/72/120 data refs respectively.

## Cross-References

- [UID:000037][ConnStatusPane](by-class/ConnStatusPane.md)
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
  - Summary/evidence: class role, network/status UI placement options, local IDA function starts, singleton, base-pane wrapper caveat, and cross-references are documented; confidence remains medium-high because final `network` versus `ui/status` placement is unresolved.
- 2026-06-04: Raised from `80/78` to `84/84` and filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/network/`.
  - Before: parent placement was plausible but had a blank validator path, stale provenance wording, and only coarse IDA-start evidence.
  - After: live IDA evidence records executable identity, exact local ranges, constructor caller, singleton xrefs, vtable stores/slots, base-wrapper fan-in counts, and the reason the `0x00544d*` methods remain shared `Pane` dependencies.
  - Reasoning: `network/ConnStatusPane.cpp` is the best current reconstruction path because the class is connection-status UI with network-message handling, while `ui/status/` remains a plausible future split. Parent confidence is now high enough to receive the reconstructable class child, but final placement and field names remain below final-code confidence.
