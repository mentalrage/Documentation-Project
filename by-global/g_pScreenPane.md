*** UID:0000S7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ScreenPane;
ScreenPane *g_pScreenPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pScreenPane

## Status

- Confidence: very strong for the sole source definition, exact four-byte backing slot, ScreenPane ownership, constructor/destructor/constructor-unwind lifecycle, 145-xref consumer family, separate successor boundary, and alias consolidation.
- Storage: [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- Likely owner file and autogen parent: [UID:0000NB][ScreenPane](by-file/ScreenPane.md), with cursor helper aliases documented under [UID:0000IL][CursorManager](by-file/CursorManager.md).
- Reconstruction status: source-bearing sole definition `ScreenPane *g_pScreenPane = 0` emitted through `ScreenPane.cpp`; the exact physical slot is documented separately by non-emitting [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md).

## Purpose

`g_pScreenPane` is the process-wide root screen pane singleton. Startup constructs [UID:0000CB][ScreenPane](by-class/ScreenPane.md), stores `this` at `0x0067a7cc`, and many UI/render helpers use the global to reach screen dimensions, cursor state, dirty regions, frame/presentation state, and DirectDraw-owned surfaces.

## Known Aliases

| Alias | Source | Notes |
| --- | --- | --- |
| `g_pScreenPane` | ScreenPane documentation plus live IDA ownership evidence | Preferred canonical name for the global storage. |
| `dword_67A7CC` | IDA auto-name | Raw global name seen in decompilation. |
| `DAT_0067a7cc` | Raw recovered data name | Raw global name in data-oriented views. |
| [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) | Cursor-helper alias documentation | Typed alias used when calling cursor/dimension helpers. Do not treat as a separate proven singleton yet. |
| `g_browserRuntime` | Browser-dispatch alias documentation | Browser dispatch fallback alias over the same storage; not a proven separate browser-owned singleton. |
| `g_browserStatusTextPane` | Exact storage-page alias list | Browser-adjacent alias family member that still needs separate review before use as a declaration. |

## Evidence Notes

- 2026-05-30 live IDA MCP `py_eval` reports `0x0067a7cc` as a 4-byte `.data` item named `dword_67A7CC` with 145 data xrefs.
- 2026-06-07 A010 live IDA MCP refresh reconfirmed the zero-initialized four-byte storage at `0x0067a7cc`, 145 direct data xrefs, and direct lifecycle writes at `0x00556962`, `0x00556969`, `0x00556c16`, and `0x00559b20`.
- In `0x00556910` (`ScreenPane` construction path), `0x00556962` writes `dword_67A7CC = eax` after adjusting the constructed object pointer, and `0x00556969` writes `0` on the null fallback path. The same basic block then installs `ScreenPane` vtables at `0x0055697b` and `0x00556981`.
- In ordinary destructor `0x00556a60`, `0x00556c16` clears `dword_67A7CC = 0` after releasing/resetting fields such as `[edi+0x5a8]`; source C++ relies on implicit `Singleton<ScreenPane>` teardown rather than spelling this assignment in the destructor body.
- Function `0x00559b20` clears the same slot only as constructor-unwind cleanup for the empty `Singleton<ScreenPane>` base at primary `+0xfc`. It is compiler lowering, not a reusable source helper.
- Cursor helper methods at `0x00557450` and `0x00557460` read `[ecx+0x112]` and `[ecx+0x114]`, the screen-dimension fields initialized by `ScreenPane`.
- The active-cursor helper at `0x005573f0` compares against `[ecx+0x580]`, matching cursor state inside the same root object rather than a separate proven cursor-manager singleton.
- Browser dispatch fallback at `0x0046c960` reads `dword_67A7CC` at `0x0046cacd`/`0x0046cadb`, writes a byte at `+0x5b2`, and calls the object vtable at `[eax+0x20]`; this supports [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) as an ignored alias over `g_pScreenPane`.
- Main UI setup/teardown also consumes the pointer: `0x004f618a` loads `dword_67A7CC` during startup graph setup, and `0x004f64bc` reads it during shutdown/removal of UI layers.
- Startup graph setup at `0x004f5fb0` reads `dword_67A7CC` into a local root-screen pointer, calls the screen vtable at slot `+0x3c`, schedules presentation/timer work through `0x005573b0`, and calls cursor visibility wrappers through `0x00557440`/`0x00557430`.
- Shutdown/removal at `0x004f6490` checks `dword_67A7CC` before removing six layer-list entries through `0x00556d20`, matching the root layer-list field initialized by [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md).
- Window focus restore path: `Main_WndProc` at `0x00465f20` handles case `7` / `WM_SETFOCUS`, checks `DAT_0067a7cc`, and calls [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) on the root object at `0x0046602e`. This confirms `g_pScreenPane` is the runtime receiver for `ScreenPane::RestoreLostSurfaces`, which restores DirectDraw surface fields `+0x18`, `+0x100`, and `+0x108`.
- No live IDA evidence currently proves separate storage or a separate lifetime for [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md), [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md), or the unresolved `g_browserStatusTextPane` alias.
- Xrefs are broad and include core UI, cursor switching, help/tooltip placement, IME popup placement, map/render presentation, and transfer/update dialogs.
- The 2026-06-07 refresh also checked successor `0x0067a7d0` as a separate zero-initialized global with its own 117-xref family and writes in `0x00579a30`, `0x00579cb0`, `0x0057b9a0`, and `0x0057bb30`, confirming the `g_pScreenPane` one-dword boundary.

## Lifecycle Evidence

| Address | Access | Meaning |
| --- | --- | --- |
| `0x00556962` | write | `ScreenPane` constructor publishes the adjusted root screen object to `dword_67A7CC`. |
| `0x00556969` | clear | Constructor null-fallback path clears the singleton slot. |
| `0x00556c16` | clear | Main `ScreenPane` destructor clears the singleton after owned field cleanup. |
| `0x00559b20` | clear | [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) begins with compiler-generated constructor-unwind cleanup for the `Singleton<ScreenPane>` base at primary `+0xfc`. |
| `0x0046cacd` / `0x0046cadb` | read | Browser dispatch fallback uses the same root screen object, proving `g_browserRuntime` is an alias. |
| `0x004f5fb0` | read | Startup graph setup obtains the root screen pointer for vtable setup, frame scheduling, and cursor visibility wrappers. |
| `0x004f6490` | read | Shutdown/removal checks the root screen pointer before removing six layer-list entries. |
| `0x0046602e` | read/call receiver | `Main_WndProc` `WM_SETFOCUS` checks the singleton and invokes [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) on it. |
| `0x005573f0`, `0x00557450`, `0x00557460` | read | Cursor and screen-dimension helpers operate on fields inside the root screen object, not a proven separate cursor singleton. |

## Migration Guidance

- Keep the canonical global as `g_pScreenPane` while reconstructing source structure.
- Emit this semantic definition exactly once through [UID:0000NB][ScreenPane](by-file/ScreenPane.md). Keep physical UID0001OX false/non-emitting so generated source cannot define duplicate storage.
- Allow temporary typed local casts/views such as `CursorManager*` for calls to `SetActiveCursor`, `GetScreenWidth`, and `GetScreenHeight`.
- Do not emit a second independent global for `g_pCursorManager` unless a later constructor/allocation path proves a distinct object.
- Parent attachment uses [UID:0000NB][ScreenPane](by-file/ScreenPane.md) because that file page now clears the 80/80 gate and records the constructor/destructor, layer-list, browser-notification, destructor-support, read-only-data, and cursor-alias evidence tying this storage to `ScreenPane.cpp`.

## Cross-References

- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000CB][ScreenPane](by-class/ScreenPane.md)
- [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md)
- [UID:0000IL][CursorManager](by-file/CursorManager.md)
- [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md)
- [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md)
- [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md)
- [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md)
- [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md)

## Changes

- 2026-07-22 B003 UID00023U exact implementation callback:
  - Raised `86/92` to `92/94` and installed the sole source definition `ScreenPane *g_pScreenPane = 0` through [UID:0000NB][ScreenPane](by-file/ScreenPane.md).
  - Preserved all 145 xrefs, constructor publication/fallback, ordinary-destructor and constructor-unwind Singleton clears, UI/browser/cursor consumers, aliases, and separate `0x0067a7d0` successor evidence.
  - Distinguished semantic source from non-emitting physical UID0001OX storage and corrected `0x00559b20` from a possible source helper to compiler-generated constructor-unwind cleanup.

- 2026-06-21 B005 SurfaceRestoreLostSurfaces consumer sync:
  - Score unchanged at `86/92`.
  - Added the `Main_WndProc` `WM_SETFOCUS` consumer path at `0x0046602e`, where the window procedure checks `g_pScreenPane` and invokes [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md).
  - Evidence: accepted B005 report `tools/leaser/Agents/Agent-B005/research/00039Z-SurfaceRestoreLostSurfaces-source-quality.md`, target [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md), and existing lifecycle evidence tying `0x0067a7cc` to ScreenPane construction/destruction.
- 2026-06-07 A010 Batch032:
  - Before: `84/90`; the page had strong lifecycle evidence but did not clear the corrected child-side 85 completion gate, and its file parent [UID:0000NB][ScreenPane](by-file/ScreenPane.md) was `86/82`.
  - After: `86/92`; added refreshed live xref and successor-boundary evidence, retained `AUTOGEN_PARENT_UID:0000NB` after raising the direct file parent to `86/85`. Final C++ remains blank under the final-source threshold.
- 2026-06-07 A007: Attached to the ScreenPane source root.
  - What existed before: `AUTOGEN_PARENT_UID` was blank and the status text said [UID:0000NB][ScreenPane](by-file/ScreenPane.md) had not cleared the attachment gate.
  - Changed to: set `AUTOGEN_PARENT_UID:0000NB` and documented the attachment as source-declared singleton storage owned by `ScreenPane.cpp`; reconstruction C++ remains blank.
  - Evidence: [UID:0000NB][ScreenPane](by-file/ScreenPane.md) is now scored `86/82` and records the constructor/destructor, layer-list helpers, browser notification handler, destructor-support island, read-only data, cursor alias caveats, and [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) storage evidence needed for parent attachment. The remaining cursor/surface/helper split keeps the score and C++ block unchanged.

- 2026-06-06: Raised completion/confidence from `78/88` to `84/90`, cleared `AUTOGEN_PARENT_UID` while [UID:0000NB][ScreenPane](by-file/ScreenPane.md) was still below the then-current attachment gate, added the unresolved `g_browserStatusTextPane` alias caveat, and added lifecycle evidence for constructor publish/fallback, destructor/helper clears, browser alias reads, startup graph setup, shutdown layer removal, and cursor/dimension typed-view users. Evidence: [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) records the exact zero-initialized storage, 145 xrefs, four direct writes, alias set, startup/shutdown users, and reconstruction guidance; [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md) records the constructor/destructor and root layer-list helpers at `88/90`; [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md) records the compact clear helper and deleting-destructor island.

- 2026-06-05: Marked reconstructable and attached to [UID:0000NB][ScreenPane](by-file/ScreenPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to `ScreenPane` construction, teardown, cursor/helper typed views, browser fallback use, and main UI setup/shutdown consumers; no separate storage or lifetime is proven for aliases. No score change and no reconstruction C++ were added.
- What existed before: this page identified `g_pScreenPane` correctly but still treated alias output as part of the evidence trail, and its completion/confidence metadata was unevaluated.
- What changed to: the page now uses live IDA MCP evidence only for storage shape, constructor/destructor writes, cursor/browser alias interpretation, and major lifecycle references. Completion/confidence were set to `78/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `dword_67A7CC` as a 4-byte `.data` item with 145 xrefs, constructor assignment at `0x00556962`, constructor null fallback at `0x00556969`, teardown clear at `0x00556c16`, helper clear at `0x00559b20`, cursor-field reads at `0x00557450`/`0x00557460`, browser dispatch use at `0x0046cacd`/`0x0046cadb`, and startup/shutdown graph consumers at `0x004f618a`/`0x004f64bc`.
