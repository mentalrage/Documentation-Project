*** UID:0000PI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ComputeMenuItemRect is emitted by exact helper [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md); this address-suffixed global page is an alias/search marker and does not duplicate the helper body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ComputeMenuItemRect_4F8B90

## Status

- Confidence: very strong for behavior, bounds, caller set, callee set, asset-layout dependency, source-family placement, and alias/body split; medium-high only for whether the original source spelled the private helper with explicit `__stdcall` and whether rectangle initialization was a free helper or member wrapper.
- Address range: [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md)
- Likely owner source: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Function Role

`ComputeMenuItemRect_4F8B90` is the address-suffixed documentation alias for the private/static `MainMenuPane.cpp` helper whose source-facing name should be `ComputeMenuItemRect`. The body is owned by [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md) and emitted through [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md); this page should not emit a duplicate formal C++ body. [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) may call the source-facing `ComputeMenuItemRect` in its first-draft C++ while preserving the raw duplicated-constants form as byte-for-byte fallback evidence.

The helper computes the screen rectangle for a pre-login main-menu item. It uses different constants for EPF/current mode and legacy EPD mode, and returns a zero rectangle for signed item index `-1`.

## Rectangle Constants

| Layout | Rectangle |
| --- | --- |
| EPF/high-layout | left `781`, top `493 + 41 * index`, right `972`, bottom `532 + 41 * index` |
| Legacy | left `467`, top `299 + 30 * index`, right `640`, bottom `329 + 30 * index` |

## Evidence Notes

- IDA MCP `lookup_funcs 0x004f8b90` reports a real function of size `0x77`.
- IDA MCP callers are [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) mouse/key/paint methods: `0x004f6b94`, `0x004f6baf`, `0x004f6c75`, `0x004f6c90`, `0x004f77d1`, `0x004f785d`, and `0x004f7966`.
- IDA MCP callees show only the rectangle initializer at `0x004b7c50`.
- The helper reads [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` at `0x0066da97`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4F8B90`, size `0x77`, the same seven main-menu callers, and the rectangle initializer callee `0x004b7c50`.
- Live IDA MCP on 2026-06-14 rechecked `sub_4F8B90` at `0x004f8b90`, size `0x77`, 119 decimal bytes (Verified with int_convert.py), exactly seven code xrefs from `MainMenuPane` mouse/key/paint handlers, one behavioral callee `sub_4B7C50`, seven basic blocks, and cyclomatic complexity 4.

## Source Layout Decision

Keep this helper with `login/MainMenuPane.cpp`. It is shared by mouse/key invalidation and paint placement and is paired with the sibling hit-test helper, but it has no broader UI-control role. The emitted source helper should use `ComputeMenuItemRect`, not the recovered address suffix.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page records exact range, size, rectangle constants, zero-rectangle path, asset-layout flag dependency, caller/callee set, MainMenuPane-only ownership, support memory page, parent/emitter route, and the alias-only/no-duplicate-body role. |
| Confidence | 90 | Live IDA MCP on 2026-06-14 and B007 local export review match [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md), including size, callers, callee, and ownership; helper spelling is resolved for implementation as `ComputeMenuItemRect`, while remaining uncertainty is only whether the original file used explicit `__stdcall` and whether `RectBounds` was called through a free helper or member-style wrapper. |
| Parent | [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) | Child `86/90` and direct parent `89/86` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/login/MainMenuPane.cpp`. |

## Cross-References

- [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented rectangle behavior, constants, callers, callee, asset-mode global, and owner source but remained unevaluated.
  - After: score reflects nearly complete behavior/source-owner documentation for this small menu-layout helper.
  - Evidence: IDA notes confirm function size, MainMenuPane mouse/key/paint callers, rectangle initializer callee, and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` dependency.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Reason: live IDA MCP recheck confirms this is source-authored main-menu layout helper code and every observed caller is inside `MainMenuPane` logic.
- 2026-06-07 A008 alias cleanup:
  - Normalized the asset-mode dependency to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), retaining `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-14 A003 score refresh:
  - Before: `84/88`; the page lacked an explicit score rationale and a current live recheck after the exact memory page had reached `84/90`.
  - Changed to: `86/90`, retaining [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked `sub_4F8B90`, `0x77` / 119-byte size (Verified with int_convert.py), seven `MainMenuPane` code xrefs, single rectangle-initializer callee, seven basic blocks, and cyclomatic complexity 4. Final helper spelling and surrounding source names remain the blockers below final code entry.
- 2026-06-21 Supervisor Rule 26 / B007 source-quality incorporation:
  - Reframed this page as the recovered address-suffixed alias for [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md), not the source-emitting body page.
  - Preserved the valid report details that the source-facing private/static helper name is `ComputeMenuItemRect`, the body emits once through [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and unresolved source spelling is limited to explicit `__stdcall` versus project default plus free `InitRectBounds` versus member-style rectangle setter.
- 2026-06-21 B012 MainMenuHitTest source-quality sync:
  - Score unchanged; recorded that [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) uses this source-facing helper in first-draft C++, while this alias page remains non-duplicating documentation for the address-suffixed recovered symbol.
