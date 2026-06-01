*** UID:0000PI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ComputeMenuItemRect_4F8B90

## Status

- Confidence: strong for behavior and source-family placement.
- Address range: [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md)
- Current generated file: `source-3/simroot_v2/recovered/ComputeMenuItemRect_004F8B90.cpp`
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Function Role

`ComputeMenuItemRect_4F8B90` computes the screen rectangle for a pre-login main-menu item. It uses different constants for EPF/high-layout mode and legacy mode, and returns a zero rectangle for item index `-1`.

## Rectangle Constants

| Layout | Rectangle |
| --- | --- |
| EPF/high-layout | left `781`, top `493 + 41 * index`, right `972`, bottom `532 + 41 * index` |
| Legacy | left `467`, top `299 + 30 * index`, right `640`, bottom `329 + 30 * index` |

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f8b90` reports a real function of size `0x77`.
- IDA MCP callers are [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) mouse/key/paint methods: `0x004f6b94`, `0x004f6baf`, `0x004f6c75`, `0x004f6c90`, `0x004f77d1`, `0x004f785d`, and `0x004f7966`.
- IDA MCP callees show only the rectangle initializer at `0x004b7c50`.
- The helper reads `g_useEpfAssets` / `byte_66DA97` at `0x0066da97`.

## Source Layout Decision

Keep this helper with `login/MainMenuPane.cpp`. It is shared by menu hit testing and rendering but has no broader UI-control role.

## Cross-References

- [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented rectangle behavior, constants, callers, callee, asset-mode global, and owner source but remained unevaluated.
  - After: score reflects nearly complete behavior/source-owner documentation for this small menu-layout helper.
  - Evidence: IDA notes confirm function size, MainMenuPane mouse/key/paint callers, rectangle initializer callee, and `g_useEpfAssets`/`byte_66DA97` dependency.
