** TARGET-REPORT-UID:00019M **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00019M ComputeMenuItemRect Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00019M] as source-bearing main-menu rectangle helper code, not no-code compiler glue.
- Final disposition: private/static file-local helper in [UID:0000L0] `MainMenuPane`, emitted to `NexusTK/login/MainMenuPane.cpp`.
- Required action: update the target page metadata/prose, remove stale `95/95` blank-C++ wording, reframe [UID:0000PI] `ComputeMenuItemRect_4F8B90` as an address-suffixed alias/summary, and populate first-draft C++ if the supervisor accepts this report.
- Confidence: strong for boundary, body, caller family, layout constants, `g_useEpfAssets` branch, `RectBounds` output helper, and owner/emitter route; medium-high for final original helper/member spellings only.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | keep `0000L0` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `0000L0` |
| Formal C++ | populate first draft after supervisor implementation callback |

## Target

- Target UID: [UID:00019M]
- Target path: `source-3/project-documentation/by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00019M-ComputeMenuItemRect-source-quality.md`
- Current target score/state: `84/90`, `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L0`, blank C++.
- Source queue/report row: `by-memory/-coverage-report.md` currently says `84% : strong` and summarizes the MainMenuPane parent route, exact bounds, `byte_66DA97` branch, `-1` zero-rectangle path, seven callers, and single rectangle-initializer callee.
- Generated state: `auto-generated/NexusTK/login/MainMenuPane.cpp` currently contains empty emitter markers for both [UID:0000PI] `by-global/ComputeMenuItemRect_4F8B90.md` and [UID:00019M] `by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md`. The implementation pass should put one body in the by-memory target and keep the by-global page as an alias/summary to avoid duplicate emitted code.

## Supervisor Active Recheck

- User assigned a B-preferred report-only source-quality / heuristic pass for [UID:00019M] `ComputeMenuItemRect`.
- Report-only pass: no target/support by-* docs were edited, no generated/project-level files were edited, and `by-memory/-coverage-report.md` was not edited.
- Prior completed B007 reports `000125`, `00015G`, and `00018P` were preserved. This report file did not already exist before creation.
- Split repair is not required. The existing half-open range `0x004f8b90-0x004f8c07` is exact, followed by alignment to sibling [UID:00019N] `0x004f8c10-0x004f8cfa.MainMenuHitTest`.

## Evidence Standards Used

- Direct binary-derived evidence: existing live IDA notes in target/support docs, local IDA export `.lst`, `.c`, and `.map` files under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS`.
- Documentation evidence: target page, [UID:0000L0] `MainMenuPane` file doc, [UID:00007O] `MainMenuPane` class doc, [UID:0000PI] by-global alias page, sibling [UID:00019N]/[UID:0000T1] hit-test pages, `MainMenuPaneCore`, `MainMenuLoginAndAccountDialogs`, `client_s2-main_menu`, [UID:0000SW] `g_useEpfAssets`, [UID:0001OH] memory byte page, and `RectBounds`/`RectGeometryHelpers`.
- Prior research evidence: B007, B001, and B002 research folders were searched for `00019M` / `ComputeMenuItemRect`; no completed direct B-agent report for this UID was present. Prior accepted `g_useEpfAssets` and UI asset-mode rectangle-helper research supports treating `byte_66DA97` as a broad mode dependency, not an owner route.
- Inference guidance: `by-structure.md` active C++ gate requires `RECONSTRUCTABLE:TRUE`, valid nonblank emitters, and `(COMPLETION + CONFIDENCE) / 2 > 85`; old `95/95` wording is stale.
- IDA MCP status: fresh MCP connection was attempted at `http://127.0.0.1:13337/mcp` and timed out. This report therefore relies on existing live-IDA documentation plus local IDA exports.

## IDA / Export Facts

- Local `.lst` export confirms `sub_4F8B90` starts at `0x004f8b90`, ends with `retn 8` at `0x004f8c04`, and is followed by alignment at `0x004f8c07`.
- IDA stack labels are `arg_0= byte ptr 8` and `arg_4= dword ptr 0Ch`; local `.c` export decompiles the prototype as `int __stdcall sub_4F8B90(char a1, _DWORD *a2)`.
- The apparent `int` return is the tail value left by `sub_4B7C50`; all known callers use the helper for its output-rectangle side effect. Source-level return should be `void`.
- Complete local assembly behavior:
  - reads `byte_66DA97` and compares it to `1`;
  - reads the first argument as a byte and compares it to `0xff`;
  - sign-extends the byte index for normal arithmetic;
  - EPF/current branch: left `0x30d` / 781, top `0x1ed + 0x29 * index` / `493 + 41 * index`, right `0x3cc` / 972, bottom `0x214 + 0x29 * index` / `532 + 41 * index`;
  - legacy branch: left `0x1d3` / 467, top `0x12b + 30 * index` / `299 + 30 * index`, right `0x280` / 640, bottom `0x149 + 30 * index` / `329 + 30 * index`;
  - `index == -1`: all four rectangle edges are zero;
  - calls only `sub_4B7C50`, then pops saved registers and returns.
- Local `.c` export confirms the same constants and calls `sub_4B7C50(a2, left, top, right, bottom)`.
- `sub_4B7C50` local export writes `a1[0]=left`, `a1[1]=top`, `a1[2]=right`, `a1[3]=bottom`; project-level alias resolution maps it to `InitRectBounds`.
- Local `.map` export lists `sub_4F8B90`, sibling `sub_4F8C10`, and `MainMenuPane` vtable/RTTI symbols, with no source symbol for an address-suffixed original name.
- Caller contexts confirmed by local `.lst` / `.c` exports:
  - `0x004f6b94` and `0x004f6baf` inside `MainMenuPane::OnMouseEvent`, after `HitTestMenuItem`, invalidate old and new selected/hover rectangles if the item changes.
  - `0x004f6c75` and `0x004f6c90` inside `MainMenuPane::OnKeyEvent`, after keyboard selection changes, invalidate old and new selected rectangles.
  - `0x004f77d1` in `MainMenuPane::OnPaint` EPF mode loops `i = 0..5` and draws `TITLEBUT.EPF` buttons at the computed rectangles.
  - `0x004f785d` in `MainMenuPane::OnPaint` EPF mode draws `TITLESEL.EPF` for the selected item if the selected index is not `-1`.
  - `0x004f7966` in `MainMenuPane::OnPaint` legacy mode draws `TITLESEL.EPD` for the selected item if the selected index is not `-1`.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

- Best inference: source-bearing helper, not compiler-generated glue.
- Evidence: meaningful feature-specific constants, seven semantic MainMenuPane caller sites, a process-wide asset-mode dependency, and an output `RectBounds` side effect. This is not destructor glue, thunk glue, vtable setup, EH/RTTI code, padding, or a generic compiler helper.
- Rejected no-code classification: no compiler artifact pattern appears. The function has custom UI layout constants and documented consumers in mouse, keyboard, and paint paths.
- Rejected generic `RectBounds` ownership: `InitRectBounds` is a dependency only. The branch and constants are main-menu layout policy, not shared geometry primitive behavior.
- Rejected `g_useEpfAssets` / `StartupWindow` ownership: the global controls asset/layout mode and is read by many consumers. Its writer/owner is not the owner of every layout helper that reads it.

### Name, Signature, And Placement

- Recommended source-facing name: `ComputeMenuItemRect`.
- Recommended formal signature if the project does not use a project-wide stdcall default:

```cpp
static void __stdcall ComputeMenuItemRect(signed char itemIndex, RectBounds *outRect);
```

- If the original build uses a file/project default calling convention, the source declaration may omit the explicit `__stdcall`, but the ABI must remain callee-cleaning (`retn 8`).
- Use `signed char` in documentation/C++ unless a broader MainMenuPane declaration proves plain `char` is project-safe. The binary compares the low byte to `0xff` and sign-extends normal indices, so the `-1` sentinel is semantically signed.
- Keep this as a file-local helper in `login/MainMenuPane.cpp`, not a `MainMenuPane` member. There is no `this` parameter, and all owner evidence is caller/file locality.
- Reframe [UID:0000PI] `ComputeMenuItemRect_4F8B90` as an address-suffixed documentation/global-alias page. Do not use `_4F8B90` in source C++.
- Alternate `GetMenuItemRect` or `BuildMenuItemRect` is plausible source style, but less supported than the existing documentation name and caller role. It should not block implementation; use `ComputeMenuItemRect` unless stronger symbol evidence appears.

### Relationship To `HitTestMenuItem`

- [UID:00019N]/[UID:0000T1] `HitTestMenuItem` is a sibling private/static helper in the same source file.
- `HitTestMenuItem` reads `MainMenuPane + 0xf9` as the menu item count, loops indices from `0` to `count - 1`, computes the same EPF/current and legacy rectangle family, calls `InitRectBounds`, and tests with `PointInRect`.
- The binary `HitTestMenuItem` body duplicates the rectangle formula; it does not call `ComputeMenuItemRect`.
- For exact per-function reconstruction, do not rewrite `HitTestMenuItem` to call this target. A broader source-cleanup pass may later factor shared constants, but the current function body should remain the direct helper used by mouse/key/paint invalidation and paint placement.

### `RectBounds` / Rectangle Initializer Naming

- Recommended helper name in prose/C++: `InitRectBounds(outRect, left, top, right, bottom)`.
- Evidence: `project-level/-resolved-multple-aliases.md` maps `sub_4B7C50` to `InitRectBounds`; [UID:00015S] `RectGeometryHelpers` documents `0x004b7c50-0x004b7c6f` as writing four explicit bounds edges; [UID:0000N2] `RectBounds` file doc lists `InitRectBounds` in the shared geometry family.
- `RectBounds::SetLTRB` is a source-style alternative if the final shared geometry API is made class-member based, but the current docs and direct callsite support the free helper spelling. Rectangle helper naming should not remain a passive blocker.

### Item Index And Field Semantics

- `itemIndex == -1` is a valid sentinel that writes a zero rectangle. This supports caller-side invalidation paths where there may be no current selection.
- Normal call sites pass signed-byte menu indices from selection state or loop counters; this helper does not range-check against the item count.
- `HitTestMenuItem` owns the range guard by reading `MainMenuPane + 0xf9` as the count and returning `-1` on no hit.
- The selected/hovered menu index used by mouse/key/paint paths is stored at `MainMenuPane + 0xfa` in OnPaint decompilation (`*(this + 250)`) and appears as `this[90]` in subobject-adjusted OnMouse/OnKey decompilation.

### `g_useEpfAssets` And Layout Branch Meaning

- Use [UID:0000SW] `g_useEpfAssets` for `byte_66DA97`; do not call it only `g_useHighResLayout`.
- `g_useEpfAssets == 1` means the current EPF asset/layout path. OnPaint confirms this branch uses `TITLE.EPF`, `TITLEBUT.EPF`, `TITLESEL.EPF`, and `TITLESEL.PAL`.
- `g_useEpfAssets != 1` means the legacy EPD/layout path. OnPaint confirms this branch uses `TITLE.EPD` and `TITLESEL.EPD`.
- The coordinate constants are layout data local to MainMenuPane:
  - EPF/current: `left=781`, `top=493 + 41*i`, `right=972`, `bottom=532 + 41*i`; item height 39 with a 41-pixel pitch.
  - legacy: `left=467`, `top=299 + 30*i`, `right=640`, `bottom=329 + 30*i`; item height 30 with a 30-pixel pitch.

## First-Draft C++ Readiness

This target is ready for first-draft mid-2000s C++ after supervisor implementation callback. Recommended body:

```cpp
static void __stdcall ComputeMenuItemRect(signed char itemIndex, RectBounds *outRect)
{
    if (itemIndex == -1) {
        InitRectBounds(outRect, 0, 0, 0, 0);
        return;
    }

    if (g_useEpfAssets == 1) {
        const int top = 493 + 41 * itemIndex;
        InitRectBounds(outRect, 781, top, 972, top + 39);
    } else {
        const int top = 299 + 30 * itemIndex;
        InitRectBounds(outRect, 467, top, 640, top + 30);
    }
}
```

Implementation notes:

- If project style or build defaults already imply `__stdcall` for file-local helpers, drop the explicit keyword in source while preserving the ABI in metadata/prose.
- If the final `RectBounds` API lands as a member-style setter, the equivalent calls are `outRect->SetLTRB(left, top, right, bottom)`. Current documentation favors `InitRectBounds`.
- Do not add a source return value. The decompiler's `int` return is not consumed by callers and comes from `InitRectBounds` leaving `right` in `EAX`.
- Do not emit a second body from [UID:0000PI]. Keep [UID:0000PI] as the alias page and this [UID:00019M] target as the body-bearing page.

## Recommended Exact Target Changes

For `source-3/project-documentation/by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md`:

- Set `COMPLETION:88` and `CONFIDENCE:92`; keep `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L0`.
- Replace stale wording that final C++ is blank because the helper is below old `95/95` thresholds with: `Final C++ is source-quality ready under the active gate; remaining helper/member spellings are implementation notes, not blockers.`
- Replace `Current generated owner: recovered global [UID:0000PI][ComputeMenuItemRect_4F8B90]` with: `Address-suffixed alias page: [UID:0000PI][ComputeMenuItemRect_4F8B90]; source-facing helper name is ComputeMenuItemRect and the body should be emitted from this by-memory page through [UID:0000L0].`
- Add the signature recommendation: `static void __stdcall ComputeMenuItemRect(signed char itemIndex, RectBounds *outRect)`; note that `__stdcall` may be implicit if the project default covers file-local helpers.
- Add the C++ body from this report.
- Add a change-log entry noting B007 source-quality pass, local IDA export verification, `InitRectBounds` naming resolution, `g_useEpfAssets` EPF/legacy branch normalization, sibling `HitTestMenuItem` duplicate-formula relationship, score recommendation `88/92`, and first-draft C++ readiness.

## Recommended Exact Support-Doc Updates

Support-doc updates if the supervisor includes them in a later implementation callback:

- [UID:0000PI] `by-global/ComputeMenuItemRect_4F8B90.md`:
  - Change the opening description to: `` `ComputeMenuItemRect_4F8B90` is the address-suffixed documentation alias for the private/static `MainMenuPane.cpp` helper whose source-facing name should be `ComputeMenuItemRect`. The body is owned by [UID:00019M] and emitted through [UID:0000L0]; this page should not emit a duplicate formal C++ body. ``
  - Replace the score rationale's "final helper spelling/source-migration caveat" with: `Helper spelling is resolved for implementation as ComputeMenuItemRect; remaining uncertainty is only whether the original file used explicit __stdcall and whether RectBounds was called through a free helper or member-style wrapper.`
- [UID:0000T1] `by-global/HitTestMenuItem_4F8C10.md`:
  - Replace references to `ComputeMenuItemRect_4F8B90` as the paired source helper with `[UID:00019M] ComputeMenuItemRect`.
  - Add: `The binary duplicates the rectangle formula here instead of calling ComputeMenuItemRect, so exact per-function reconstruction should not introduce that call.`
- [UID:0000L0] `by-file/MainMenuPane.md`:
  - Replace the helper rows with:

```markdown
| `ComputeMenuItemRect` | `0x004f8b90-0x004f8c07` | private/static helper in `login/MainMenuPane.cpp` | Computes menu item `RectBounds` for mouse/key invalidation and paint placement; source body lives on [UID:00019M], while [UID:0000PI] is the address-suffixed alias page. |
| `HitTestMenuItem` | `0x004f8c10-0x004f8cfa` | private/static helper in `login/MainMenuPane.cpp` | Maps mouse coordinates to a menu item index; duplicates the same rectangle constants and calls `PointInRect`, but does not call `ComputeMenuItemRect` in the binary. |
```

  - Replace `recovered/ComputeMenuItemRect_004F8B90.cpp` with `private/static helper in login/MainMenuPane.cpp`.
- [UID:00007O] `by-class/MainMenuPane.md`:
  - Add this method/helper row:

```markdown
| `ComputeMenuItemRect` | `0x004f8b90` | File-local helper used by mouse/key/paint paths to compute a `RectBounds` for a selected main-menu item or the `-1` zero-rectangle sentinel. |
```

  - Rename the existing `HitTestMenuItem_4F8C10` row display text to `HitTestMenuItem` and add that it is a sibling file-local helper, not a class method.
- `by-meta/client_s2-main_menu.md`:
  - Replace: `[UID:0000PI][ComputeMenuItemRect_4F8B90] owns the main-menu item rectangles used by mouse/key hit testing and paint.`
  - With: `[UID:00019M][ComputeMenuItemRect] documents the private/static MainMenuPane.cpp helper that computes main-menu item rectangles for mouse/key invalidation and paint; [UID:0000PI] remains the address-suffixed alias page.`
  - Replace `owns main-menu mouse-coordinate hit testing` for [UID:0000T1] with `documents the sibling private/static helper that maps mouse coordinates to a menu item index`.
- [UID:00019N] `by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md`:
  - Add: `This helper duplicates the rectangle formula from [UID:00019M] in the binary and should remain a sibling helper for exact reconstruction; do not call ComputeMenuItemRect from HitTestMenuItem unless a later whole-file source rewrite intentionally factors shared constants.`

## Validator Needs

- No validator was run because no by-* docs were edited in this report-only pass.
- Implementation callback should run a UID-targeted validation for [UID:00019M] after editing the target, then regenerate/inspect autogen output for `auto-generated/NexusTK/login/MainMenuPane.cpp`.
- If support docs are edited, validate them in the same pass and inspect duplicate-emitter behavior for [UID:0000PI] and [UID:00019M].

Suggested commands for the implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00019M-ComputeMenuItemRect-source-quality-removed.md](00019M-ComputeMenuItemRect-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Autogen inspection should confirm:

- UID `00019M` no longer appears only as an empty emitter marker.
- `auto-generated/NexusTK/login/MainMenuPane.cpp` contains exactly one `ComputeMenuItemRect` body.
- UID `0000PI` remains an alias/summary marker and does not emit a duplicate function body.
- `HitTestMenuItem` remains a sibling helper and is not silently rewritten to call `ComputeMenuItemRect`.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B007. Supervisor-owned replacement:

Replace the existing [UID:00019M] row with:

```text
    - [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md) 0x004f8b90-0x004f8c07 | helper | ComputeMenuItemRect : reconstructable : 88% : strong : B007 source-quality pass keeps this as a source-bearing private/static `MainMenuPane.cpp` helper, source name `ComputeMenuItemRect` without the address suffix and owner/emitter [UID:0000L0]; local IDA export confirms `sub_4F8B90` size `0x77`, `__stdcall` stack cleanup, signed-byte `-1` zero-rectangle sentinel, `g_useEpfAssets == 1` EPF/current layout `781,493,972,532` with pitch `41`, legacy layout `467,299,640,329` with pitch `30`, sole `InitRectBounds` callee, seven mouse/key/paint callers, sibling `HitTestMenuItem` duplicate-formula relationship, stale 95/95 blocker removal, and first-draft C++ readiness.
```

Generated `auto-generated/-ag-memory-coverage.md` should update through validator/autogen refresh, not by manual edit.

## Open Questions

- Whether the original source used explicit `__stdcall` or a project-wide default for file-local helpers. This affects declaration spelling only, not the source-bearing decision.
- Whether the final shared geometry API should present `InitRectBounds` as a free helper or `RectBounds::SetLTRB`. Current docs support `InitRectBounds`; this should not block C++ entry.
- Final MainMenuPane field names for `+0xf9` menu count and `+0xfa` selected/hovered index remain broader class-declaration work, but they are not needed for this helper body.

## Follow-Up Actions

- Supervisor: review/accept this report, then send B007 an implementation callback if target/support docs should be edited.
- Implementation pass: update [UID:00019M] metadata/prose/C++, update selected support docs, run validation/autogen, inspect `MainMenuPane.cpp`, and leave `by-memory/-coverage-report.md` for supervisor-owned application unless the ban is lifted.
- Future research: align [UID:00019N] `HitTestMenuItem` source-quality wording with this decision so the two sibling helpers use consistent names and shared constant descriptions without inventing a call edge.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00019M-ComputeMenuItemRect-source-quality.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00019M-ComputeMenuItemRect-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00019M"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019M-ComputeMenuItemRect-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00019M-ComputeMenuItemRect-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
