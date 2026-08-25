** TARGET-REPORT-UID:0001GQ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: ScrollNewGroupPane HitTestPart

Assignment id: `B002-report-0001GQ-scroll-new-group-pane-hit-test-part-20260625`

Agent: `Agent-B002`

Original report-only status: no by-memory, by-class, by-file, generated source, generated reports, validator state/cache, IDA DB, or coverage-report files were edited during the initial report-only pass.

Implementation callback status: accepted for implementation and applied by `Agent-B002` on 2026-06-26. The target [UID:0001GQ] and support [UID:0000CL] by-* docs were edited under leases and scoped validators. [UID:0000JS] `Group.md` was not edited because the accepted report marked it optional and its existing route prose already covers `ScrollNewGroupPane -> Group.cpp`. No generated reports, generated C++, manual coverage reports, validator state/cache, or IDA DB data were hand-edited.

Primary target:

- [UID:0001GQ] `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`

Summary recommendation:

- Keep [UID:0001GQ] source-owned by [UID:0000CL] `ScrollNewGroupPane`, emitting through [UID:0000CL] into [UID:0000JS] `social/Group.cpp`.
- Keep the exact range `0x00561420-0x0056173d`. Do not merge it with [UID:0001GR] `GetPartRect` at `0x00561740`, the raw helpers in [UID:0001GS], or the next `ScrollCollectionPane` range.
- Reject the generated `TextEditPane` ownership and reject a generic/shared scrollbar owner for this pass. Shared scrollbar idioms are real, but all modeled callers and the update callback path are the `ScrollNewGroupPane`/`NewGroupPane` path.
- Populate first-draft C++ for [UID:0001GQ] under the current code-entry gate. Recommended score after application: `COMPLETION:88`, `CONFIDENCE:90`.
- Keep [UID:0000CL] `ScrollNewGroupPane` and [UID:0000JS] `Group` scores unchanged unless the supervisor wants a separate class/file rescore after applying the target C++ and field-name support notes.
- Treat generated tracker/coverage rows currently showing stale `76/86` values as refresh output, not hand-edit targets.

## Evidence Checked

Instruction and workflow files:

- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `project-documentation/by-structure.md`

Primary target and support docs:

- [UID:0001GQ] `project-documentation/by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`
- [UID:0000CL] `project-documentation/by-class/ScrollNewGroupPane.md`
- [UID:0000JS] `project-documentation/by-file/Group.md`
- [UID:0001GP] `project-documentation/by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
- [UID:0001GR] `project-documentation/by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`
- [UID:0001GS] `project-documentation/by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`
- [UID:0001YR] `project-documentation/by-type/by-vtable/ScrollNewGroupPaneVtables.md`
- [UID:00015S] `project-documentation/by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- [UID:0000SE] `project-documentation/by-class/RectBounds.md`
- [UID:00028L] `project-documentation/by-memory/0x0067a754-0x0067a758.g_pEventMan.md`

Accepted context and comparison material:

- [UID:0000EO] executed B005 `TextEditPane` source-quality report, only for the already accepted rejection of generated `TextEditPane` ownership of `0x00561420`, `0x00561a40`, `0x00561b00`, and `0x00561bc0`.
- Executed B001 `GroupPanes` source-quality report, only for the already accepted relationship between `NewGroupPane`, `ScrollNewGroupPane`, and `Group.cpp`.
- `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`, only as a naming/style lead for the same scrollbar field block.
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` and the executed B002 FittingRoom scroll-pane reports, only as analogous scrollbar source-shape context.
- `re-agent/reports/code/0x00561420_TextEditPane_meth_0x561420.cpp`, only as a decompiler-derived formula lead with rejected class ownership.
- `unrefined-source-backup/source/ScrollNewGroupPane.cpp`, only as a weak source-shape lead.

Generated output checked for refresh implications only:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/social/Group.cpp`

The generated tracker and generated `Group.cpp` currently contain stale `76/86` values for [UID:0001GQ]. Those files should be refreshed by validator/autogen after supervisor application, not manually edited.

## IDA MCP Evidence Status

Live IDA MCP evidence was required and was collected successfully.

- Probe time: `2026-06-26T04:11:02Z` / `2026-06-26 00:11:02` local.
- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- `initialize`: HTTP 200, server `ida-pro-mcp` version `1.0.0`.
- `tools/list`: HTTP 200.
- `idb_list`: active session `80de0a67`, file `NexusTK.exe.i64`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker pid `26892`, not analyzing.
- `server_health` for `80de0a67`: status ok, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

No MCP patching, renaming, type mutation, IDB save, or other database-editing tool was used.

## Binary / Xref Facts

[UID:0001GQ] `0x00561420-0x0056173d`:

- `lookup_funcs` reports `sub_561420` at `0x00561420` with size `0x31d`.
- `lookup_funcs` reports no function at `0x0056173d`.
- `lookup_funcs` reports the next modeled function, [UID:0001GR] `sub_561740`, at `0x00561740` with size `0x287`.
- Boundary bytes:
  - `0x00561420` begins `55 8b ec 83 ec 38 a1 24 2f 67 00 33 c5 89 45 fc`.
  - The tail contains the part-loop exit, security-cookie check, `ret 8`, and then `cc cc cc`.
  - `0x0056173d-0x00561740` is exactly three `0xcc` padding bytes before [UID:0001GR].
- `xrefs_to 0x00561420` returns exactly two code xrefs:
  - `0x00560be1` inside [UID:0001GP] `sub_560B00`, the `ScrollNewGroupPane` mouse/input virtual path.
  - `0x00561b6f` inside [UID:0001GS] `sub_561B00`, the active interaction updater.
- `callees 0x00561420` returns:
  - `0x004a9090` `EventMan::GetCursorPosition`
  - `0x005447c0` pane screen-origin/screen-offset helper
  - `0x004b7c50` rectangle initializer
  - `0x004b7e80` `PointInRect`
  - `0x005c772f` `@__security_check_cookie@4`
- Data bytes at `0x00624144` begin `26 00 00 00 26 00 00 00 26 00 00 00 0d 00 00 00 0c 00 00 00 0c 00 00 00 0d 00 00 00 0a 00 00 00`, matching the fixed extent table used by the vertical branch.

Sibling live checks:

- `xrefs_to 0x00561740` returns thirteen references from [UID:0001GP], raw/manual helper sites in [UID:0001GS], `0x00561b00`, and `0x00561bc0`; this confirms `GetPartRect` is a separate shared helper, not the body of [UID:0001GQ].
- `xrefs_to 0x00561b00` returns references from [UID:0001GP] and raw/manual helper code; `callees 0x00561b00` includes `0x00561420`, `0x00561740`, and `0x00561bc0`.
- `callees 0x00561bc0` includes `0x00561740`, cursor/origin helpers, and `0x0056df00`, the `NewGroupPane::SetScrollPosition` callback route.
- `lookup_funcs` confirms modeled starts at `0x00560900`, `0x00561b00`, and `0x00561bc0`; raw starts `0x005619d0`, `0x00561a40`, and `0x00561d50` remain no-xref/no-function raw helper starts as documented by [UID:0001GS].

## Decompilation Facts For 0001GQ

Hex-Rays decompilation for `0x00561420` reports a `__thiscall` function with two explicit coordinate arguments and a `char` part-id return.

Confirmed behavior:

- Iterates candidate part ids `0` through `4`.
- Returns the first candidate id whose computed rectangle contains the supplied point.
- Returns `-1` / `0xff` after candidate `4` misses.
- Calls `EventMan::GetCursorPosition` and the pane screen-origin helper inside the candidate loop.
- Converts the live cursor to pane-local coordinates when the origin is not the sentinel `(-1000, -1000)`.
- Uses inherited `Pane::m_bounds` at object offset `+0x44` as the rectangle base.
- Uses the scrollbar state block:
  - `+0xf8`: style/index for `dword_624144`
  - `+0xfb`: thumb-drag-active byte
  - `+0xfc`: orientation byte
  - `+0xfe`: current scroll position
  - `+0x100`: scroll range
  - `+0x102`: enabled byte
  - `+0x103`: highlight part, confirmed by [UID:0001GS]
  - `+0x104`: active part, confirmed by [UID:0001GS]
  - `+0x108/+0x10c`: thumb drag offset point, confirmed by [UID:0001GS]
- Calls the shared rectangle point predicate as `PointInRect(y, x, &rect)` in project-facing source terms. `RectBounds` docs prove the first explicit coordinate is compared to top/bottom and the second is compared to left/right.

Orientation-specific geometry:

- `m_orientation == 0` is the vertical branch:
  - fixed thumb span comes from `dword_624144[m_scrollStyle]`;
  - part `0` collapses the top edge (`bottom = top`);
  - part `4` collapses the bottom edge (`top = bottom`);
  - when disabled or range is non-positive, part `2` is the middle track with top/bottom end spans removed and parts `1`/`3` are empty;
  - when enabled and ranged, part `2` is the thumb, part `1` is the page area before the thumb, and part `3` is the page area after the thumb;
  - the active drag byte influences only this vertical branch in [UID:0001GQ].
- `m_orientation != 0` is the horizontal branch:
  - fixed thumb span is `m_bounds.bottom - m_bounds.top`;
  - part `0` collapses the left edge (`right = left`);
  - part `4` collapses the right edge (`left = right`);
  - when disabled or range is non-positive, part `2` is the middle track with left/right end spans removed and parts `1`/`3` are empty;
  - when enabled and ranged, the thumb position is derived from scroll position and range; the [UID:0001GQ] horizontal branch does not consult the thumb-drag-active byte.

The method duplicates the same geometry family as [UID:0001GR] `GetPartRect`; it is not a call-through wrapper around `GetPartRect`.

## Source-Quality Reanalysis

Owner and emitter:

- `CANONICAL_OWNER` should remain `0000CL`.
- `EMITTER_UIDS` should remain `0000CL`.
- `EMITTER_POSITION_OPTIONAL` should remain `50`.
- The source-file route remains [UID:0000JS] `Group` because `NewGroupPane` constructs, shows, and receives scroll callbacks from this custom scrollbar.

Rejected alternatives:

- Generated `TextEditPane` ownership is stale. The only modeled callers are `ScrollNewGroupPane` methods, and [UID:0000EO] already rejected `TextEditPane` ownership for this method family.
- A generic/shared scrollbar class is not supported for this target. The method's field block resembles other scrollbars, but the vtables, callers, raw helpers, and callback target all remain `ScrollNewGroupPane`/`NewGroupPane`.
- A split into [UID:0001GR] is wrong. IDA shows `0x0056173d-0x00561740` padding and the next function begins at `0x00561740`.
- A merge into [UID:0001GS] is wrong. [UID:0001GQ] is a modeled function with two direct callers; the raw helpers begin later and have distinct call roles.

Score:

- Current target metadata is `COMPLETION:86`, `CONFIDENCE:89`.
- Recommended target metadata after supervisor application: `COMPLETION:88`, `CONFIDENCE:90`.
- Rationale: live MCP resolves the current score-limiting facts for boundary, callers, callee set, field offsets, orientation geometry, generated-owner rejection, source-file route, and formal C++ readiness. The score should stay below final/source-perfect range because preserved original enum/table spelling was not recovered from symbols or strings; the implementation-ready names below are descriptive project-facing names, not proven historical source spellings.

No named source-quality blocker remains for [UID:0001GQ]. The only residual cap is exact original spelling for the enum/table/field aliases; current available routes are exhausted for this report because the IDB has no source symbols for those names, strings do not name the table, generated output is stale or descriptive, and sibling accepted docs already use descriptive scrollbar aliases for the same field block.

## First-Draft C++ Recommendation

Populate [UID:0001GQ] `RECONSTRUCTION_CPP CODE` with the following exact insertion text. It assumes the class page support names listed after the block are applied in the same supervisor pass or already available through surrounding class declarations.

```cpp
ScrollNewGroupPart ScrollNewGroupPane::HitTestPart(int mouseY, int mouseX)
{
    for (int partValue = kScrollNewGroupPartLeading;
         partValue <= kScrollNewGroupPartTrailing;
         ++partValue) {
        const ScrollNewGroupPart part =
            static_cast<ScrollNewGroupPart>(partValue);
        Point cursor;
        Point origin;
        RectBounds rect;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);

        if (origin.x == -1000 && origin.y == -1000) {
            InitRectBounds(&rect, 0, 0, 0, 0);
        } else {
            cursor.x -= origin.x;
            cursor.y -= origin.y;
            rect = m_bounds;

            if (m_orientation == 0) {
                const int thumbSpan =
                    kScrollNewGroupPartExtentByStyle[m_scrollStyle];

                if (part == kScrollNewGroupPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollNewGroupPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackTop = m_bounds.top;
                    const int thumbLimit = m_bounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_bounds.top + cursor.y - m_thumbDragOffset.y;
                        if (thumbTop < trackTop) {
                            thumbTop = trackTop;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = trackTop +
                            ((thumbLimit - trackTop) * m_scrollPosition) /
                                m_scrollRange;
                    }

                    const int thumbBottom = thumbTop + thumbSpan;

                    if (part == kScrollNewGroupPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollNewGroupPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollNewGroupPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollNewGroupPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = m_bounds.bottom - m_bounds.top;

                if (part == kScrollNewGroupPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollNewGroupPartTrailing) {
                    rect.left = rect.right;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackLeft = m_bounds.left;
                    const int thumbLimit = m_bounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kScrollNewGroupPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollNewGroupPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollNewGroupPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollNewGroupPartThumb) {
                    rect.left += thumbSpan;
                    rect.right -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            }
        }

        if (PointInRect(mouseY, mouseX, &rect)) {
            return part;
        }
    }

    return kScrollNewGroupPartNone;
}
```

Support names expected on [UID:0000CL] `ScrollNewGroupPane`:

```cpp
enum ScrollNewGroupPart {
    kScrollNewGroupPartLeading = 0,
    kScrollNewGroupPartPageBeforeThumb = 1,
    kScrollNewGroupPartThumb = 2,
    kScrollNewGroupPartPageAfterThumb = 3,
    kScrollNewGroupPartTrailing = 4,
    kScrollNewGroupPartNone = -1
};
```

Recommended field aliases for the class page:

| Offset | Name | Evidence |
| --- | --- | --- |
| inherited `+0x44` | `m_bounds` | RectBounds base used by [UID:0001GQ] and [UID:0001GR]. |
| `+0xf8` | `m_scrollStyle` | Index into `dword_624144`, the vertical fixed-span table. |
| `+0xfb` | `m_thumbDragActive` | Drag-mode byte used by the vertical thumb geometry and interaction helpers. |
| `+0xfc` | `m_orientation` | Zero selects vertical geometry; nonzero selects horizontal geometry. |
| `+0xfe` | `m_scrollPosition` | Current scroll value used for thumb placement. |
| `+0x100` | `m_scrollRange` | Positive range gate and thumb-position divisor. |
| `+0x102` | `m_scrollEnabled` | Enables ranged thumb/page geometry. |
| `+0x103` | `m_highlightPart` | Highlighted part byte, cleared by [UID:0001GS]. |
| `+0x104` | `m_activePart` | Active pressed part byte, consumed by [UID:0001GS]. |
| `+0x108/+0x10c` | `m_thumbDragOffset` | Cursor offset inside the thumb during drag. |

Recommended helper aliases:

- `EventMan::GetCursorPosition(Point *out)` for `0x004a9090`, through [UID:00028L] `g_pEventMan`.
- `GetScreenOffset(Point *out)` for `0x005447c0`, matching existing pane-origin usage.
- `InitRectBounds(RectBounds *rect, int left, int top, int right, int bottom)` for `0x004b7c50`.
- `PointInRect(int y, int x, const RectBounds *bounds)` for `0x004b7e80`.

## Exact Supervisor Edits

For [UID:0001GQ] `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`:

- Set `COMPLETION` from `86` to `88`.
- Set `CONFIDENCE` from `89` to `90`.
- Keep `CANONICAL_OWNER:0000CL`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000CL`.
- Keep `EMITTER_POSITION_OPTIONAL:50`.
- Insert the C++ block above between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.
- Update the item summary to state that live IDA MCP confirms exact bounds/padding, two ScrollNewGroupPane-only callers, callee set, inline vertical/horizontal geometry, field offsets, source-owner rejection for TextEditPane, and first-draft C++ readiness.
- In body prose, replace the stale "C++ remains blank until exact field/helper names are final-source quality" language with the field/helper aliases and formal C++ readiness described here.

For [UID:0000CL] `by-class/ScrollNewGroupPane.md`:

- Add the `ScrollNewGroupPart` enum aliases and the field-alias table above, or equivalent source-facing prose.
- Update the `HitTestPart` method row to say first-draft C++ is ready on [UID:0001GQ].
- Add a note that [UID:0001GQ] duplicates the part-rectangle geometry inline, while [UID:0001GR] remains the separate `GetPartRect` helper used by paint/raw/interaction paths.
- Keep class metadata unchanged unless the supervisor chooses a separate class rescore.

For [UID:0000JS] `by-file/Group.md`:

- No required metadata change.
- Optional prose-only support update: note that [UID:0001GQ] now has source-ready C++ under `ScrollNewGroupPane` and does not require a shared-scrollbar source split for this pass.

Do not hand-edit:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/NexusTK/social/Group.cpp`
- any `-coverage-report.md`
- validator state/cache

Those outputs should refresh only through the normal validator/autogen flow after supervisor application.

## Coverage Row Recommendation

Validator-generated rows should ultimately reflect:

| UID | Target | Completion | Confidence | Reconstructable | Owner | Emitter |
| --- | --- | --- | --- | --- | --- | --- |
| `0001GQ` | `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md` | `88` | `90` | `TRUE` | `0000CL` | `0000CL` |

No manual generated coverage edit is recommended.

## Validator Commands To Run After Supervisor Application

Suggested report execution:

> Executable block R001 was removed from this report and preserved verbatim in [0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md](0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Suggested file validators after the edits are applied:

> Executable block R002 was removed from this report and preserved verbatim in [0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md](0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the `Group.md` file validator only if the optional [UID:0000JS] support prose is edited:

> Executable block R003 was removed from this report and preserved verbatim in [0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md](0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validator was run during this report-only pass because no by-* target/support doc was edited.

## Implementation Tracking Checklist

- [x] Apply [UID:0001GQ] metadata change to `88/90` with owner/emitter unchanged.
  - Proof: `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md` now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, and `EMITTER_POSITION_OPTIONAL:50`.
- [x] Insert the formal [UID:0001GQ] `RECONSTRUCTION_CPP CODE` block from this report.
  - Proof: the target formal block now contains `ScrollNewGroupPart ScrollNewGroupPane::HitTestPart(int mouseY, int mouseX)` with the exact B002 accepted body, including `g_pEventMan->GetCursorPosition`, `GetScreenOffset`, vertical/horizontal inline geometry, `PointInRect(mouseY, mouseX, &rect)`, and `kScrollNewGroupPartNone`.
- [x] Update [UID:0001GQ] prose to remove the now-stale blank-C++ blocker and document the live MCP field/helper evidence.
  - Proof: target `Status`, `Score Rationale`, `Field And Helper Aliases`, `Orientation Geometry`, `IDA MCP Evidence`, `Ownership And Rejected Routes`, and `Changes` sections now record the exact boundary, padding, two code xrefs, callee set, extent-table bytes, field/helper aliases, orientation geometry, C++ readiness, and generated `TextEditPane` route rejection.
- [x] Add or reconcile `ScrollNewGroupPart` enum aliases on [UID:0000CL].
  - Proof: `by-class/ScrollNewGroupPane.md` now has an explicit `enum ScrollNewGroupPart` block with leading/page-before/thumb/page-after/trailing/none values.
- [x] Add or reconcile the [UID:0000CL] field-alias table for offsets `+0xf8` through `+0x108/+0x10c`.
  - Proof: `by-class/ScrollNewGroupPane.md` now lists `+0xf8`, `+0xfb`, `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108/+0x10c`; it preserves the B005 `m_scrollSkinIndex` alias while adding the B002 accepted `m_scrollStyle` alias for [UID:0001GQ].
- [x] Keep [UID:0000CL] and [UID:0000JS] metadata unchanged unless a separate support rescore is intentionally performed.
  - Proof: `by-class/ScrollNewGroupPane.md` remains `85/86`, owner/emitter `0000JS`; `by-file/Group.md` was not edited and remains `89/85`, `CANONICAL_OWNER:FILE`.
- [x] Do not merge [UID:0001GQ] with [UID:0001GR] or [UID:0001GS].
  - Proof: target and class prose now explicitly state that [UID:0001GQ] ends at `0x0056173d`, three `0xcc` bytes pad to [UID:0001GR] at `0x00561740`, and [UID:0001GS] remains the later raw/manual interaction helper page.
- [x] Do not resurrect generated `TextEditPane` ownership.
  - Proof: target `Ownership And Rejected Routes` and class `Evidence Notes` retain/generated-route rejection, with [UID:0001GQ] owner/emitter unchanged as [UID:0000CL].
- [x] Run the target and support validators listed above after application.
  - Proof target validator: working directory `E:\NTK\GhidraBridge\source-3\project-documentation`; command `python .\tools\validator.py --mode file --file by-memory\0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md --apply --queue-timeout 240`; `command_id: 000000002002`; `command_timestamp: 2026-06-26T00:30:33-04:00`; exit code `0`; `ok: 1`; `generated_refresh: deferred`; `generated_refresh_command_id: 000000002002`; `generated_refresh_timestamp: 2026-06-26T00:30:33-04:00`.
  - Proof support validator: working directory `E:\NTK\GhidraBridge\source-3\project-documentation`; command `python .\tools\validator.py --mode file --file by-class\ScrollNewGroupPane.md --apply --queue-timeout 240`; `command_id: 000000002018`; `command_timestamp: 2026-06-26T00:34:22-04:00`; exit code `0`; `ok: 1`; `generated_refresh: deferred`; `generated_refresh_command_id: 000000002018`; `generated_refresh_timestamp: 2026-06-26T00:34:22-04:00`.
- [x] Let generated tracker, generated source, and coverage rows refresh through validator/autogen only.
  - Proof: no generated reports, generated C++, manual coverage reports, validator state/cache, or IDA DB data were hand-edited. The scoped validators reported validator-owned `projected_stats_update` and deferred generated refresh; generated tracker/source/coverage output was not manually touched. Queue-status check from `E:\NTK\GhidraBridge\source-3\project-documentation` with `python .\tools\validator.py --queue-status` returned `command_id: 000000002020`, `command_timestamp: 2026-06-26T00:35:58-04:00`, normal queued jobs `0`, processing jobs `0`, queued generated refresh jobs `1`, processing generated refresh jobs `0`.

Lease proof:

- Initial lease attempt from `tools/leaser`: target lease succeeded for `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`; class lease was rejected because B005 held `by-class/ScrollNewGroupPane.md` from `2026-06-26T04:28:17Z` to `2026-06-26T04:33:17Z`.
- Target lease was used only for the target edit and target validator, then released successfully with `python .\leaser.py B002 unlease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`.
- After the B005 class lease cleared, B002 leased `by-class/ScrollNewGroupPane.md`, applied the support edit, ran the class validator, and released it successfully with `python .\leaser.py B002 unlease E:\NTK\GhidraBridge\source-3\project-documentation\by-class\ScrollNewGroupPane.md`.

## Changed Files / Implementation Callback

Created during initial report-only pass:

- `tools/leaser/Agents/Agent-B002/research/0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md`

Modified during implementation callback:

- `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`
- `by-class/ScrollNewGroupPane.md`
- `tools/leaser/Agents/Agent-B002/research/0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md`

Validator-owned side effects reported by scoped validators:

- `project-level/-auto-completion-stats.md` projected path completion section update
- validator registry/autogen reference updates reported in validator output
- generated refresh deferred for both validator commands

No target/support `by-file/Group.md` edit was required. No generated source files, generated reports, manual coverage reports, validator state/cache files, or IDA DB data were hand-edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md","timestamp":"2026-06-26T00:42:12","uid":"0001GQ"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GQ-ScrollNewGroupPaneHitTestPart-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001GQ-ScrollNewGroupPaneHitTestPart-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
