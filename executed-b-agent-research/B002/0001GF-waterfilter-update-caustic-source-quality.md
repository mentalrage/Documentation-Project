** TARGET-REPORT-UID:0001GF **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GF WaterFilterEffecter Update Caustic Effect Source-Quality Report

Assignment: `B002-goal2-waterfilter-update-caustic-source-quality-0001GF-20260617`  
Target: [UID:0001GF] `by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md`  
Mode: report-only. I did not edit by-* documentation, generated reports, source files, the IDA DB, generated source, or `by-memory/-coverage-report.md`.

I searched existing B-agent reports and executed reports for `0001GF`, `WaterFilterEffecterUpdateCausticEffect`, `55b5d0`, and `UpdateCaustic`. The only hits were the current supervisor assignment/notes, not a prior executed research report for this target.

## Recommendation Summary

- Raise [UID:0001GF] from `82/88` to `88/91`.
- Keep `CANONICAL_OWNER:0000FZ`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000FZ`.
- Update [UID:0000FZ] `WaterFilterEffecter` from `84/88` to `86/90` so the direct class parent clears the strict gate after the field/source-shape evidence is added.
- Keep source placement under [UID:0000IZ] `Effects` / `NexusTK/render/Effects.cpp`.
- Replace raw names:
  - `sub_55B5D0` -> `WaterFilterEffecter::OnPaint` / paint-slot caustic update body. The compact target title can remain `UpdateCausticEffect`, but the source-facing virtual slot is best documented as the pane paint/default slot override.
  - `sub_4D1600` -> `LoadFrameDrawRecord`.
  - `sub_4BA6B0` -> `GrafPort::DrawTiledBackground`.
  - `dword_67AB80` -> `g_pTimerMgr`.
  - `dword_67A744` -> `g_pEPFLib`.
  - `aCa` / `0x00623d2c` -> `L"CAUST.PAL"`.
- Formal C++ should be populated with the first draft below. The body is source-authored project code, not a retained duplicate or compiler artifact.

## Evidence Checked

- Target, class, file, aggregate, vtable, timer, resource, frame-record, and GrafPort support docs:
  - [UID:0001GF] target page.
  - [UID:0000FZ] `WaterFilterEffecter`.
  - [UID:0000IZ] `Effects`.
  - [UID:0001GE] `ScreenEffecterRuntimeCluster`.
  - [UID:0001YO] / [UID:0002OR] `ScreenEffecter` vtable pages.
  - [UID:0003EH] `CAUST.EPF` / `CAUST.PAL` resource string tail.
  - [UID:0000UX] `LoadFrameDrawRecord_004D1600`.
  - [UID:00016A] `GrafPort::DrawTiledBackground`.
  - [UID:0000SI]/[UID:0002VW] `g_pTimerMgr`.
  - [UID:0000QU]/[UID:0001OQ] `g_pEPFLib`.
  - [UID:0000A2]/[UID:0000MC]/[UID:0001VH]/[UID:0003JA] Pane class/file/layout/vtable docs.
  - [UID:00005V]/[UID:0000JR]/[UID:000160] GrafPort support docs.
- Generated source was checked only as a lead. `source-3/simroot_v2/class_WaterFilterEffecter.cpp` uses non-source helpers such as `GetGlobalRenderTick`, `WritePaletteFrame`, and `RenderCausticFrame`; those names should not be accepted as source-quality identifiers.
- PE-aware byte checks were run against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. The PE map is `ImageBase=0x00400000`, `.text VA=0x00001000`, `.text RAW=0x00000400`, so target VA `0x0055b5d0` maps to file offset `0x0015a9d0`. This avoids the flat-offset pitfall.

## Binary Findings

Exact target body:

- Half-open range is `0x0055b5d0-0x0055b698`, size `0xc8`.
- The body returns at `0x0055b697`.
- `0x0055b698-0x0055b6a0` is eight `0xcc` bytes.
- `0x0055b6a0` begins the `WaterFilterEffecter` constructor.

Important instruction facts:

- `0x0055b5e6` calls the local frame/tile record initializer at `0x00457a60`.
- `0x0055b5eb` loads `g_pTimerMgr`, then reads current tick at `+0x18`.
- `0x0055b5f4-0x0055b602` gates on `currentTick <= lastTick + 60`.
- `0x0055b604-0x0055b62d` increments a 16-bit frame field and wraps at `32`.
- `0x0055b638-0x0055b642` loads `g_pEPFLib`, passes the caustic frame table, frame index, and local record, then calls `LoadFrameDrawRecord`.
- `0x0055b647-0x0055b65b` saves the current alpha/draw scalar at view `+0x90` and copies view `+0xbc` into it.
- `0x0055b660-0x0055b673` passes `L"CAUST.PAL"`, the local record, and local bounds `this+0x44`, sets byte `this+0x70` to `2`, then calls `GrafPort::DrawTiledBackground`.
- `0x0055b678-0x0055b686` restores byte `this+0x70` to `0` and restores view `+0x90`.

Vtable/source-shape evidence:

- WaterFilterEffecter constructor stores four vtable views at complete-object offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`.
- PE-aware vtable scan shows `0x00623c70` is the `+0x04` Pane/GrafPort view, and `0x00623cb4` (`+0x44` in that view) points directly to `0x0055b5d0`.
- The helper body therefore receives the adjusted Pane/GrafPort view pointer, not the complete object pointer. Offsets documented in this target are view-relative; complete-object offsets are four bytes higher.
- The base Pane slot `+0x44` is the guard/default slot at `0x0041b6a0`; many derived panes use this slot for their paint/draw callback. This makes `WaterFilterEffecter::OnPaint` the best source-facing virtual direction, with `UpdateCausticEffect` retained as a descriptive behavior label.

Constructor correlation:

- `0x0055b6f7-0x0055b70b`: calls the CAUST EPF metadata loader with `L"CAUST.EPF"` and stores the result at complete `+0x10c`, i.e. view `+0x108`.
- `0x0055b710-0x0055b723`: resolves/preloads `L"CAUST.PAL"` through the palette library and stores the result at complete `+0x110`, i.e. view `+0x10c`.
- `0x0055b724-0x0055b72f`: zeroes the 16-bit frame field at complete `+0x118`, i.e. view `+0x114`.
- `0x0055b730-0x0055b745`: reads `g_pTimerMgr->+0x18`, subtracts `61`, stores the baseline at complete `+0x114`, i.e. view `+0x110`, and sets the current alpha field at complete `+0x94`, i.e. view `+0x90`, to `0.7f`.

## Field And Helper Resolutions

| Offset/name | Best source-facing direction | Evidence and caveat |
| --- | --- | --- |
| View `+0x70` byte | `m_drawMode` / `m_blitMode` byte | `GrafPort` constructor initializes the word at `+0x70` to `0x0100`, making byte `+0x70` default `0` and byte `+0x71` true/enabled. `DrawTiledBackground` reads byte `+0x70` and passes it to the surface-render callback. Target sets it to `2` for the caustic draw and unconditionally restores `0`. This is not `Pane::m_mode`; Pane mode is `+0xb5`. |
| View `+0x90` float/dword | current draw alpha / opacity scalar | `GrafPort` constructor initializes it to `0.5f`; `ChattingBackPane` and `TransferServerDialogPane` docs also use `+0x90` as fade/opacity; WaterFilterEffecter constructor sets it to `0.7f`. Target saves/restores it around the caustic draw. |
| View `+0xbc` float/dword | caustic draw alpha / effect alpha source | Only this target references `+0xbc` inside the effecter cluster. The value is copied into known alpha field `+0x90` immediately before rendering, so the best defensible name is an alpha/opacity source such as `m_causticDrawAlpha`. No effecter-local write was found, so avoid stronger original-spelling claims. |
| View `+0x108` pointer | `m_causticFrameTable` / `ArchiveMetadataTable *` | Constructor stores the `CAUST.EPF` frame metadata/load result at complete `+0x10c` / view `+0x108`; target passes it to `LoadFrameDrawRecord`. This is not the palette buffer. |
| View `+0x10c` pointer/handle | `m_causticPalette` preload handle | Constructor stores the `CAUST.PAL` palette lookup result here. The target does not read it directly; it passes the `L"CAUST.PAL"` literal to `DrawTiledBackground`, which performs palette lookup. |
| View `+0x110` dword | `m_lastCausticTick` | Constructor seeds it to `g_pTimerMgr->m_currentTick - 61`; target compares `currentTick <= m_lastCausticTick + 60` and then stores the current tick. |
| View `+0x114` word | `m_causticFrameIndex` | Constructor zeroes the word; target increments it, stores it, and wraps at `32`. |
| Local `ebp-0x2c` record | `FrameDrawRecord` / `TileRectRecord` | Initialized by `0x00457a60`, filled by `LoadFrameDrawRecord`, and passed to `GrafPort::DrawTiledBackground`. Existing docs use both frame-record and tile-record wording; consolidate the shared type separately. |

## CAUST / Palette Semantics

- `0x00623d18` is `L"CAUST.EPF"`.
- `0x00623d2c` is `L"CAUST.PAL"`.
- Constructor loads the EPF frame metadata into view `+0x108` and preloads/resolves the palette into view `+0x10c`.
- The update/paint body selects one of 32 caustic frames, asks `LoadFrameDrawRecord` to project the frame metadata into a local draw record, then draws it tiled with `CAUST.PAL`.
- The cadence is strictly `currentTick > lastTick + 60`; equality returns without drawing/advancing.
- The frame wrap is `if (++frame >= 32) frame = 0`.
- The draw-state restore is source-visible: current alpha is saved, mode byte is set to `2`, tiled draw runs, mode byte is reset to `0`, and alpha is restored. The mode byte is not saved; default mode `0` is part of the source behavior.

## Owner / Emitter / Source Placement

Keep [UID:0001GF] owned and emitted by [UID:0000FZ] `WaterFilterEffecter`.

Rejected alternatives:

- `GrafPort`: `GrafPort::DrawTiledBackground` is only a callee. The target reads WaterFilterEffecter CAUST frame/timer fields and WaterFilter vtable data points to it.
- `Surface`: the target consumes render callbacks indirectly through `DrawTiledBackground`; it is not a generic surface routine.
- `ImageLib` / `ImageFrameTable`: `LoadFrameDrawRecord` is only a callee; ownership of the caustic update stays with WaterFilterEffecter.
- `DrawPictureObjectPane`: no resource string, vtable, class owner, or call-chain evidence supports this stale wording for `0x0055b5d0`.
- Standalone retained duplicate/compiler artifact: the body is vtable-referenced at `0x00623cb4`, has class constructor field correlation, and carries source-level CAUST timing/render behavior.

## Heuristic / Inference Reanalysis And Validation

Best defensible source directions:

- Source-facing method: `void WaterFilterEffecter::OnPaint()` as the `+0x04` Pane/GrafPort view slot `+0x44` override. `UpdateCausticEffect` remains a good descriptive filename/summary label, but the vtable slot argues against treating it as an arbitrary direct helper.
- Receiver model: the binary body is compiled for the adjusted Pane/GrafPort view. Documentation should keep target offsets view-relative and explicitly note the `+4` complete-object delta.
- Field names: `m_causticFrameTable`, `m_lastCausticTick`, `m_causticFrameIndex`, `m_drawMode`, and `m_alpha` are strong enough for support docs. `m_causticDrawAlpha` is high-probability but should be documented as descriptive because no setter/write was found in the effecter cluster.
- Helper names: `LoadFrameDrawRecord` and `GrafPort::DrawTiledBackground` are supported by existing source-quality pages; `g_pTimerMgr`, `g_pEPFLib`, `L"CAUST.EPF"`, and `L"CAUST.PAL"` are the correct replacements for raw globals/literals.

Evidence checked:

- PE-aware target bytes, constructor bytes, target successor padding, and vtable dwords.
- Current target/class/file/aggregate/type/global/item docs listed above.
- Generated `class_WaterFilterEffecter.cpp`, used only to identify generated pollution and not as authority.
- Whole-effecter-cluster displacement scan for `+0xbc`: only the target reads it, so the exact original field name cannot be proven from local WaterFilter code.
- Existing executed B reports: no prior executed B report for this UID or target was found.

Rejected alternatives:

- `UpdateCausticEffect` as final source name: rejected as the strongest source-facing name because the only direct reachability found is the Pane/GrafPort view vtable slot `+0x44`. It is acceptable as a behavior label.
- `Find/update timer callback`: rejected because target is in the Pane/GrafPort view paint/default slot, not the tertiary timer view.
- `+0x70` as visibility or Pane mode: rejected because visible/mode are Pane `+0xb4/+0xb5`; `+0x70` is the GrafPort render flag byte consumed by `DrawTiledBackground`.
- `+0x90` as software-buffer flag: rejected because software-buffer flag is view `+0x94`; constructor and sibling docs use `+0x90` as alpha/opacity.
- `+0x108` as palette buffer: rejected because constructor stores `CAUST.EPF` metadata there and target feeds it to `LoadFrameDrawRecord`; palette preload is view `+0x10c`.
- `+0x114` as tick: rejected because `+0x114` is a 16-bit frame index. The last-tick field is view `+0x110`.
- `sub_4BA6B0` as Ranking or picture-object local code: rejected by [UID:00016A] caller breadth and by the target's direct use as a generic GrafPort tiled-background primitive.
- Current generated helpers `GetGlobalRenderTick`, `WritePaletteFrame`, `RenderCausticFrame`, and `LoadCausticPaletteBuffer`: rejected because they are synthetic/generated names, not documented source APIs.

Validation/rejection of existing docs:

- Existing target docs correctly identify the exact range, WaterFilterEffecter ownership, 60 ms cadence, 32-frame wrap, `LoadFrameDrawRecord`, and `GrafPort::DrawTiledBackground`.
- Existing target docs are stale where they retain the old "current-session MCP timeout" score rationale, leave field names unresolved, and do not record the adjusted Pane/GrafPort receiver/vtable-slot evidence.
- Existing target docs already reject `DrawPictureObjectPane`; this report adds stronger vtable/resource/constructor evidence for that rejection.

Score/source-placement/final-C++ impact:

- The target can rise above the `85/85` formal-C++ gate because exact bytes, constructor correlation, vtable reachability, helper/global/literal names, range/padding, and source placement are now documented.
- The direct class parent [UID:0000FZ] should be raised to `86/90` after adding the adjusted receiver and field table; otherwise the class page remains the only stale gate issue.
- Formal C++ is ready as first draft with descriptive field names. It is not final 95+ original-spelling quality because `+0xbc` and the shared local record type still need broader source-declaration cleanup, but those are no longer blockers for an 85/85+ reconstructable/emitting method.

## First-Draft C++ Recommendation

Supervisor should populate the formal C++ block after applying the support-doc name/field updates. Preferred source-facing declaration is `WaterFilterEffecter::OnPaint`; if the target keeps the existing compact title, keep a note that this is the paint-slot caustic update body.

```cpp
void WaterFilterEffecter::OnPaint()
{
    FrameDrawRecord frameRecord;

    unsigned int currentTick = g_pTimerMgr->m_currentTick;
    if (currentTick <= m_lastCausticTick + 60) {
        return;
    }

    unsigned short frameIndex = static_cast<unsigned short>(m_causticFrameIndex + 1);
    m_lastCausticTick = currentTick;

    if (frameIndex >= 32) {
        frameIndex = 0;
    }
    m_causticFrameIndex = frameIndex;

    LoadFrameDrawRecord(m_causticFrameTable, frameIndex, &frameRecord);

    float savedAlpha = m_alpha;
    m_alpha = m_causticDrawAlpha;
    m_drawMode = 2;

    DrawTiledBackground(&m_localBounds, &frameRecord, L"CAUST.PAL");

    m_drawMode = 0;
    m_alpha = savedAlpha;
}
```

Notes for supervisor while entering the formal block:

- If the accepted shared helper signature becomes method-style, use `g_pEPFLib->LoadFrameDrawRecord(m_causticFrameTable, frameIndex, &frameRecord)` instead of the free-helper spelling. The binary preloads `ECX` with `g_pEPFLib` before the call.
- Existing support docs use `FrameDrawRecord` and `TileRectRecord` wording for the same local record family. Use whichever accepted shared type name is current when applying the C++.
- Do not use generated helper names `GetGlobalRenderTick`, `WritePaletteFrame`, or `RenderCausticFrame`.

## Score And Metadata Recommendations

Target [UID:0001GF]:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000FZ
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000FZ
RECONSTRUCTION_CPP CODE: populate with the first-draft C++ above
```

Support score update:

```text
[UID:0000FZ] WaterFilterEffecter: 84/88 -> 86/90
```

Reason: the class page can now document the exact `+0x04` Pane/GrafPort view slot, constructor-to-update field mapping, CAUST frame/palette resource fields, and paint-slot source shape. No owner/emitter/source-path change is recommended.

No score change is required for [UID:0001GE], [UID:00016A], [UID:0000UX], [UID:0003EH], [UID:0001YO], or [UID:0002OR] solely from this target, although they should receive support wording updates listed below.

## Support Docs To Update

- [UID:0001GF] target page:
  - Replace unresolved/raw names with the field/helper/global names above.
  - Add the PE-aware byte/range/padding evidence.
  - Add the vtable slot `0x00623cb4 -> 0x0055b5d0` and adjusted receiver note.
  - Replace the stale timeout-based score rationale.
  - Populate first-draft C++.
- [UID:0000FZ] `WaterFilterEffecter`:
  - Raise to `86/90`.
  - Document source-facing `OnPaint` / caustic update paint slot, constructor field mapping, and CAUST resource semantics.
- [UID:0001GE] `ScreenEffecterRuntimeCluster`:
  - Add one support bullet under the water/filter section noting the target is the `+0x04` Pane/GrafPort view `+0x44` override, with exact padding before the constructor.
- [UID:0001YO] / [UID:0002OR] vtable pages:
  - Add the specific WaterFilterEffecter `+0x04` view slot `0x00623cb4 -> 0x0055b5d0` as the caustic paint/update override.
- [UID:00005V] `GrafPort` and/or [UID:0001VH] `PaneLayout`:
  - Consider adding target-backed support that `+0x70` is a draw/blit mode byte and `+0x90` is the alpha/opacity scalar in Pane/GrafPort-derived views.
- [UID:00016A] `GrafPortDrawTiledBackground`:
  - Add this target as evidence that caller code sets byte `+0x70` to render mode `2` and restores `0` around a tiled background draw.
- [UID:0000UX] `LoadFrameDrawRecord_004D1600`:
  - Optional support wording only: this target's `m_causticFrameTable` is a CAUST EPF frame metadata table consumer.
- [UID:0003EH] `ScreenEffecterResourceStringsAndConstants`:
  - Optional support wording only: `0x00623d2c` is the exact `L"CAUST.PAL"` literal used by the target draw call.

## Supervisor-Owned `by-memory/-coverage-report.md` Replacement Row

Replace the current [UID:0001GF] row in `by-memory/-coverage-report.md` after [UID:0001GE] and before [UID:0001GG] with:

```text
    - [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) 0x0055b5d0-0x0055b698 | virtual method | WaterFilterEffecter::OnPaint caustic update : reconstructable : 88% : very strong : PE-aware byte and vtable reanalysis confirms exact 0xc8-byte body, return at 0x0055b697, eight `0xcc` bytes before the 0x0055b6a0 constructor, WaterFilterEffecter `+0x04` Pane/GrafPort view slot `0x00623cb4 -> 0x0055b5d0`, adjusted-view field mapping for `CAUST.EPF` frame table `+0x108`, last tick `+0x110`, 16-bit frame index `+0x114`, alpha/draw-state fields `+0x90/+0xbc`, draw-mode byte `+0x70`, `g_pTimerMgr` 60 ms cadence, 32-frame wrap, `LoadFrameDrawRecord`, `GrafPort::DrawTiledBackground`, exact `L"CAUST.PAL"` literal, stale DrawPictureObjectPane rejection, and first-draft C++ readiness.
```

No new padding row is required for `0x0055b698-0x0055b6a0`; the exact padding is documented in the target/support update and the surrounding aggregate already covers the runtime cluster.

## Validation Commands

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after supervisor applies accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001GF-waterfilter-update-caustic-source-quality-removed.md](0001GF-waterfilter-update-caustic-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional PE-byte recheck command pattern used for this report:

> Executable block R002 was removed from this report and preserved verbatim in [0001GF-waterfilter-update-caustic-source-quality-removed.md](0001GF-waterfilter-update-caustic-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

Created this report only:

- `tools/leaser/Agents/Agent-B002/research/0001GF-waterfilter-update-caustic-source-quality.md`

No leases were needed for this report file in the assigned Agent-B002 research folder. No blockers remain for supervisor review.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001GF-waterfilter-update-caustic-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001GF"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GF-waterfilter-update-caustic-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001GF-waterfilter-update-caustic-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
