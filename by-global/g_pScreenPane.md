*** UID:0000S7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pScreenPane

## Status

- Confidence: strong for address, ScreenPane singleton ownership, and generated-alias consolidation.
- Storage: [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- Likely owner file: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), with cursor helper aliases documented under [UID:0000IL][CursorManager](by-file/CursorManager.md)

## Purpose

`g_pScreenPane` is the process-wide root screen pane singleton. Startup constructs [UID:0000CB][ScreenPane](by-class/ScreenPane.md), stores `this` at `0x0067a7cc`, and many UI/render helpers use the global to reach screen dimensions, cursor state, dirty regions, frame/presentation state, and DirectDraw-owned surfaces.

## Known Aliases

| Alias | Source | Notes |
| --- | --- | --- |
| `g_pScreenPane` | ScreenPane documentation plus live IDA ownership evidence | Preferred canonical name for the global storage. |
| `dword_67A7CC` | IDA auto-name | Raw global name seen in decompilation. |
| `DAT_0067a7cc` | Ghidra/generated data | Raw global name in generated source/data. |
| [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) | Generated cursor-helper alias documentation | Typed alias used when calling cursor/dimension helpers. Do not treat as a separate proven singleton yet. |
| `g_browserRuntime` | Generated browser-dispatch alias documentation | Browser dispatch fallback alias over the same storage; not a proven separate browser-owned singleton. |

## Evidence Notes

- 2026-05-30 live IDA MCP `py_eval` reports `0x0067a7cc` as a 4-byte `.data` item named `dword_67A7CC` with 145 data xrefs.
- In `0x00556910` (`ScreenPane` construction path), `0x00556962` writes `dword_67A7CC = eax` after adjusting the constructed object pointer, and `0x00556969` writes `0` on the null fallback path. The same basic block then installs `ScreenPane` vtables at `0x0055697b` and `0x00556981`.
- In `0x00556a60` (`ScreenPane` teardown path), `0x00556c16` clears `dword_67A7CC = 0` after releasing/resetting fields such as `[edi+0x5a8]`.
- The small helper at `0x00559b20` also clears `dword_67A7CC` directly and appears to be a generated scalar/vector deleting or cleanup-adjacent helper for the same object family.
- Cursor helper methods at `0x00557450` and `0x00557460` read `[ecx+0x112]` and `[ecx+0x114]`, the screen-dimension fields initialized by `ScreenPane`.
- The active-cursor helper at `0x005573f0` compares against `[ecx+0x580]`, matching cursor state inside the same root object rather than a separate proven cursor-manager singleton.
- Browser dispatch fallback at `0x0046c960` reads `dword_67A7CC` at `0x0046cacd`/`0x0046cadb`, writes a byte at `+0x5b2`, and calls the object vtable at `[eax+0x20]`; this supports [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) as an ignored alias over `g_pScreenPane`.
- Main UI setup/teardown also consumes the pointer: `0x004f618a` loads `dword_67A7CC` during startup graph setup, and `0x004f64bc` reads it during shutdown/removal of UI layers.
- No live IDA evidence currently proves separate storage or a separate lifetime for [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) or [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md).
- Xrefs are broad and include core UI, cursor switching, help/tooltip placement, IME popup placement, map/render presentation, and transfer/update dialogs.

## Migration Guidance

- Keep the canonical global as `g_pScreenPane` while reconstructing source structure.
- Allow temporary typed local casts/views such as `CursorManager*` for calls to `SetActiveCursor`, `GetScreenWidth`, and `GetScreenHeight`.
- Do not emit a second independent global for `g_pCursorManager` unless a later constructor/allocation path proves a distinct object.

## Cross-References

- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)

## Changes

- What existed before: this page identified `g_pScreenPane` correctly but still treated generated alias output as part of the evidence trail, and its completion/confidence metadata was unevaluated.
- What changed to: the page now uses live IDA MCP evidence only for storage shape, constructor/destructor writes, cursor/browser alias interpretation, and major lifecycle references. Completion/confidence were set to `78/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `dword_67A7CC` as a 4-byte `.data` item with 145 xrefs, constructor assignment at `0x00556962`, constructor null fallback at `0x00556969`, teardown clear at `0x00556c16`, helper clear at `0x00559b20`, cursor-field reads at `0x00557450`/`0x00557460`, browser dispatch use at `0x0046cacd`/`0x0046cadb`, and startup/shutdown graph consumers at `0x004f618a`/`0x004f64bc`.
