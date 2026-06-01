*** UID:0000T6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Main UI Layer Slots

## Status

- Confidence: medium for layer/context role, strong for startup/shutdown ownership.
- Symbol kind: global pointer set.
- Proposed owner: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) / UI layer infrastructure.
- Key backing storage: `dword_69B364` at `0x0069b364`, formerly mislabeled by generated output as [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).

## Summary

The main UI bootstrap allocates a small set of eight-byte layer/context objects, stores them in adjacent globals, uses them as pane initialization arguments, and releases them during UI shutdown. These are not runtime screen-effecter-owned globals.

## Observed Slots

| Storage | Startup write | Startup init | Shutdown release/clear | Notes |
| --- | --- | --- | --- | --- |
| `dword_69B368` / `0x0069b368` | `0x004f6239` | `0x004f6331` | `0x004f6510`, `0x004f65ae` | Used by root/background/status pane setup paths. |
| `dword_69B364` / `0x0069b364` | `0x004f6268` | `0x004f6340` | `0x004f64ff`, `0x004f6594` | Broad UI layer/context slot; stale alias [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md). |
| `dword_69B36C` / `0x0069b36c` | `0x004f6297` | `0x004f634f` | `0x004f64ee`, `0x004f657a` | Used by main UI graph setup; final role name open. |
| `dword_69B374` / `0x0069b374` | `0x004f62c6` | `0x004f635e` | `0x004f64dd`, `0x004f65c8` | Used by main UI graph setup; final role name open. |
| `dword_69B378` / `0x0069b378` | `0x004f62f5` | `0x004f636d` | `0x004f64cc`, `0x004f6560` | Used by main UI graph setup; final role name open. |
| `dword_69B37C` / `0x0069b37c` | `0x004f632c` | `0x004f637c` | `0x004f6521`, `0x004f6546` | Used by main UI graph setup; final role name open. |

## Evidence

- `0x004f5fb0` allocates and constructs the slot objects, then stores them into the adjacent globals.
- `0x004f6490` releases the same slots and clears each pointer.
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) passes these globals into pane initialization virtual calls across both new and old UI layout branches.
- IDA xrefs to `0x0069b364` are broad and include `InitializeMainUiGraph`, root/UI panes, chat/browser/status/user panes, and effecter pane setup. [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) is one consumer, not the owner.

## Reconstruction Guidance

Recover these as main UI graph layer/context globals or as fields of a recovered UI graph object if later layout evidence proves they were members. Do not create a `ScreenEffecterList` class or attach `dword_69B364` to `render/Effects.cpp`.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `72/82`.
  - Before: page documented the UI layer/context slot set, startup/shutdown writes, stale alias, and reconstruction guidance but remained unevaluated.
  - After: score reflects strong lifecycle/ownership evidence while preserving lower completion for unresolved final role names and object-vs-global modeling.
  - Evidence: startup `0x004f5fb0`, shutdown `0x004f6490`, `InitializeMainUiGraph`, and xrefs around `0x0069b364` tie the slots to UI graph setup rather than screen-effect ownership.
