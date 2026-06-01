*** UID:0000IF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ConnStatusPane

## Status

- Confidence: strong for the core `ConnStatusPane` class; medium for final file placement.
- Proposed module folder: `network/` or `ui/status/`
- Proposed source file: `network/ConnStatusPane.cpp`
- Current generated source: `source-3/simroot_v2/class_ConnStatusPane.cpp`
- Evidence basis: Wave3 class inspection, generated source, existing Wave2 notes in `by-memory/-report.md`, and IDA MCP boundary checks.

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
| `ConnStatusPane` | `0x00494520-0x004949df` | `class_ConnStatusPane.cpp` | Constructor, paint, connection-message handler, latency-frame update, destructor family. |
| `Pane::SetConnecting` / `SetDisconnected` / `SetConnected` | `0x00544db0-0x00544dd9` | `class_Pane.cpp` | Base pane virtual wrappers; Wave3 also lists `ConnStatusPane` shadow rows, but canonical owner appears to be `Pane`. |
| `g_pConnStatusPane` | global-data | `class_ConnStatusPane.cpp` | Singleton pointer for the active status pane. |

## Boundary Notes

- IDA confirms `0x00494520`, `0x00494620`, `0x004946c0`, `0x004947a0`, `0x00494964`, `0x0049496f`, and `0x00494980` as real functions in the local class block.
- `InitializeMainUiGraph` calls the constructor through `CreateConnStatusPane`.
- The `0x00544db0`, `0x00544dc0`, and `0x00544dd0` methods are tiny connection-state wrappers with broad base-pane vtable xrefs. Treat them as `Pane` methods unless later vtable evidence proves a `ConnStatusPane` override.

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
