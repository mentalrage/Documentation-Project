*** UID:0000LM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MSGHandler

## Status

- Confidence: strong for behavior and anchors; medium for original file split.
- Proposed module: `app/MSGHandler.cpp`, or private code inside [UID:0000HG][Application](by-file/Application.md)
- Current generated source: `class_MSGHandler.cpp`
- Primary class doc: [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- Main address doc: [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md)

## File Role

`MSGHandler` is a tiny application message-handler swap object. Construction swaps this handler into the [UID:0000HG][Application](by-file/Application.md), destruction restores the previous handler, and virtual dispatch forwards through the active target object.

This is app infrastructure. It should stay under `app/` even if final migration folds the class into `Application.cpp`.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `MSGHandler` | `0x00528d60-0x00528e55` | RAII-style application message handler swapper and dispatch wrapper. |
| `MSGHandler` read-only data | `0x0061fbf8-0x0061fc04` | Exact vtable tail split from the mixed work-thread/notification `.rdata` span. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Handler swap | `0x00528d60`, `0x00528d80` | Constructor/destructor call `Application::ExchangeMSGHandler` and restore the previous target. |
| Dispatch | `0x00528dd0` | Forwards through target virtual slot 1. |
| Destruction | `0x00528df0` | Restores handler state and optionally frees storage. |

## Boundary Notes

- IDA confirms exact starts at `0x00528d60`, `0x00528d80`, `0x00528dd0`, and `0x00528df0`.
- Constructor/destructor xrefs include application and browser/OLE message handling paths, but the object itself belongs to application dispatch infrastructure.
- `list missing-ref --class MSGHandler` returns zero entries.
- IDA MCP confirms `??_7MSGHandler@@6B@` at `0x0061fbf8`, with constructor/destructor/deleting-destructor xrefs from the executable `MSGHandler` range.

## Cross-References

- [UID:00008S][MSGHandler](by-class/MSGHandler.md)
- [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md)
- [UID:0002GL][0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData](by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- Before: the main address doc ended at `0x00528e54`.
- Changed to: the main address doc ends at `0x00528e55`.
- Summary/evidence: 2026-05-28 IDA MCP shows the scalar deleting destructor's `retn 4` operand ends at `0x00528e55`; padding begins at `0x00528e55`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: application message-handler swap behavior, method families, exact starts, Application boundary, zero missing refs, and range correction are documented; confidence is capped by whether the tiny helper was standalone or private to `Application.cpp`.
