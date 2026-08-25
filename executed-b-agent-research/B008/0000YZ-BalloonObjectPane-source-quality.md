** TARGET-REPORT-UID:0000YZ **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000YZ BalloonObjectPane Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep the source route under `NexusTK/map/AttachedObjectPane.cpp`, but correct the direct semantic owner/emitter from file UID `0000HJ` to class UID `00000U` (`BalloonObjectPane`) because every source-authored body in this range is a BalloonObjectPane method, helper, constructor/destructor artifact, or class static support.
- Final disposition: do not populate formal `RECONSTRUCTION_CPP CODE` for UID `0000YZ` as a single aggregate. The target is source-reconstructable, but the current range is a mixed method island with raw no-xref helpers, constructor-unwind cleanup, adjustor thunks, and scalar deleting destructor glue.
- Required action: update the target documentation with the field/global/helper-name resolutions below, add the missing raw helper at `0x00468e00`, update owner/emitter metadata, update coverage rows from this report, and keep final C++ blank until the method island is split or represented with exact child ranges.
- Confidence: high for ownership, source route, field meanings, raw helper roles, and no-code recommendation; moderate-high for exact descriptive source names because original source names are not recoverable from current evidence.

## Supporting Research

## Target
- Target UID: `0000YZ`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00467b30-0x0046904e.BalloonObjectPane.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\0000YZ-BalloonObjectPane-source-quality.md`.
- Source queue/report row: `project-level/-auto-completion-stats.md` currently lists `0000YZ | 84 | 90 | 87.0`.
- Current supervisor classification: B-preferred source-quality and heuristic/inference pass from refreshed auto-completion stats.
- Current documented state: `RECONSTRUCTABLE:TRUE`, `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HJ`, `EMITTER_UIDS:0000HJ`, generated marker is empty in `auto-generated/NexusTK/map/AttachedObjectPane.cpp`.
- Recommended state: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00000U`, `EMITTER_UIDS:00000U`; generated path still resolves through the BalloonObjectPane class/file chain to `auto-generated/NexusTK/map/AttachedObjectPane.cpp`.

## Executive Recommendation
- Best direct owner: `by-class/BalloonObjectPane.md` UID `00000U`.
- Best source file route: `by-file/AttachedObjectPane.md` UID `0000HJ`, producing `NexusTK/map/AttachedObjectPane.cpp`.
- Keep the current target as an audited method-island aggregate for now, but do not use it as the formal C++ emitter body. A later split should create exact child pages for each source-authored method, raw helper, and compiler-generated glue range before code is entered.
- The current aggregate has enough evidence to raise source-quality scores, but not enough source-shape precision to emit copy/paste-ready C++ without either omitting in-range bodies or hand-writing compiler artifacts as if they were source.

## Supervisor Active Recheck
- The active `Agent-B008/goal.md` assignment records UID `0000YZ` `BalloonObjectPane` source-quality, target path above, and this report path.
- The assignment explicitly bans direct edits to `by-memory/-coverage-report.md`; exact replacement rows are included below.
- The assignment asks for focus on raw `0x00468250`, method/helper names, fields `+0x12c`, `+0x1b8/+0x1bc/+0x1c0`, `+0x1dc`, static mask/palette/color globals, constructor/destructor/adjustor thunks, source placement, support rows, scores, and first-draft C++ readiness. Each is addressed below.
- No direct split was performed. The active supervisor text says B-agents should usually report/recommend unless explicitly doing split repair; the report-only scope and current lease rules allow writing this research report without leasing.

## Inference Research Guidance Check
- `by-structure.md` makes the active C++ gate `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitter route, and `(completion + confidence) / 2 > 85`. This target meets the numeric gate, but the gate is a minimum. Source-shape and range safety still block formal code.
- `inference_research.md` was applied by separating direct facts, documentation evidence, and inference. Where original source names cannot be proven, the report recommends strong descriptive names and rejects weaker alternatives with evidence.
- Existing docs were treated as leads, not proof. The current file-owner metadata, raw helper uncertainty, and missing `0x00468e00` helper are all corrected or narrowed here.

## Heuristic / Inference Reanalysis And Validation

### Direct Owner And Source Placement
- Best inference: direct semantic owner should be `BalloonObjectPane` UID `00000U`, not by-file UID `0000HJ`.
- Evidence: constructor at `0x004682c0` installs BalloonObjectPane vtables, initializes BalloonObjectPane fields, allocates the cached bubble GrafPort, calls layout, and paints the initial bubble. The update, layout, paint, blit, cleanup, and destructor ranges all operate on the same BalloonObjectPane layout. Static mask and pool docs already route through class UID `00000U`.
- Rejected alternative, direct owner `AttachedObjectPane` class: the range consumes inherited base state and calls base helpers, but the methods are derived-class implementations and vtable overrides, not base-class behavior.
- Rejected alternative, direct owner `AttachedObjectPane.cpp` file: the file is still the correct generated source placement, but by-structure direct owner should be the narrowest semantic owner. File ownership hides class-level fields and method names.
- Final direction: `CANONICAL_OWNER:00000U`, `EMITTER_UIDS:00000U`; class UID `00000U` continues to route to file UID `0000HJ`.

### Raw `0x00468250` Repaint Island
- Best descriptive name: `BalloonObjectPane::RefreshBubbleSurface`, with `RefreshBubbleGrafPort` as a useful alias while GrafPort naming remains in flight.
- Evidence: the local exported function record shows a 108-byte Ghidra-only helper at `0x00468250`, no IDA function name, no exported callers/xrefs, and callees for GrafPort bounds, empty-rect check, lock, `PaintBubble`, unlock, and security-cookie handling. It reads `this + 0x1dc`, tests the cached GrafPort, obtains bounds, skips empty rectangles, locks the cached surface, repaints through `PaintBubble`, and unlocks.
- Rejected alternative, merge into `PaintBubble`: it is a wrapper around `PaintBubble`, not the renderer body.
- Rejected alternative, unreachable padding: it has valid code, coherent object-field use, and normal callee structure. It is raw because the toolchain lacks an IDA function/xref record, not because the bytes are inert.
- Final direction: document as a source-authored-looking raw repaint helper, but do not emit formal C++ from the aggregate until the raw entry is modeled as its own child or live entry evidence is available.

### Newly Found Raw `0x00468e00` Helper
- Best descriptive name: `BalloonObjectPane::MeasureWrappedTextWidthRaw`.
- Evidence: local function export has Ghidra-only `FUN_00468e00`, size `0x165` / 357 bytes (Verified with `int_convert.py`), no IDA name, no callers/xrefs, and no current target-doc coverage. Its decompilation reads the text buffer at `+0x12c`, line count at `+0x1c4`, line break/index table at `+0x1c6`, font id at `+0x8a`, global text/font measurement service `DAT_0067ab24`, and helper `0x004b6020`. It computes wrapped line lengths and returns max width plus one.
- Rejected alternative, `CalculateLayout`: `0x00468e00` does not position the bubble, call `MapPane::HasObjectIntersectingRect`, move the cached GrafPort, or apply final bounds. It is a measurement/wrapping helper only.
- Rejected alternative, dead bytes: the body is coherent, field-compatible with the constructor/layout range, and source-authored-looking. The absence of direct xrefs caps confidence and blocks final code, but does not justify omitting it from the target documentation.
- Final direction: add this raw island to the target's inventory and use it as a primary reason the aggregate should remain C++-blank until split.

### `PaintBubble` Name And Role
- Best name: `BalloonObjectPane::PaintBubble`.
- Evidence: callers include the raw refresh helper, constructor initial paint, direction update repaint when tail orientation changes, and position update repaint. The body uses cached GrafPort/draw context state, static mask table at `0x0066d414`, palette library `g_pPaletteLib`, render callback table slots, text colors, tail orientation, and text line layout state.
- Rejected alternative, `DrawSpeechBubbleFrameOnly`: the function also configures text colors, fills/draws text/bubble state, uses line layout, and handles custom palette entries.
- Rejected alternative, source-file-level free helper: every call passes the BalloonObjectPane `this` and the body reads BalloonObjectPane fields throughout.
- Final direction: keep `PaintBubble`; no unresolved naming blocker.

### Layout And Position Helper Names
- `0x00468b90`: keep `CalculateLayout` or use `RecalculateLayout`. Evidence: it reads message text, computes line count/breaks, sizes the bubble, checks collision with `MapPane::HasObjectIntersectingRect`, sets tail side/offset, applies bounds, and moves/sizes the cached GrafPort. `CalculateLayout` is accurate and close to source style.
- `0x00468520`: use `UpdatePositionForDirection` or `UpdatePositionFromDirection`. Evidence: vtable slot ref, direction argument, MapPane direction offset helpers, screen-bound logic, tail-side recomputation, and repaint when tail side changes.
- `0x00468800`: use `UpdatePosition` or `UpdateAttachedPosition`. Evidence: no direction argument, calls shared attached-position helper `0x005386c0`, then applies the same screen-bound/tail repaint logic.
- `0x00468ab0`: prefer `ClearOutputRects` over current generic `ClearBounds`. Evidence: vtable default-style method clears two caller-supplied Rect outputs through `sub_4B7C50`; it does not clear object-owned bounds fields.
- `0x00468ae0`: prefer `BlitBubbleSurface` over `MoveBubbleGrafPort`. Evidence: it locks the cached GrafPort at `+0x1dc`, offsets cached bounds to the requested point, calls the GrafPort/surface copy helper with mode `5`, and unlocks. It renders a cached bubble surface into a target GrafPort rather than merely moving a GrafPort object.
- Rejected alternative, all helpers belong to `AttachedObjectPane`: position helpers consume inherited placement APIs, but their tail-side and cached-bubble behavior is BalloonObjectPane-specific.

### Field Layout
- `+0x12c`: `wchar_t m_messageText[0x46]` or `m_text[0x46]`. The constructor clamps copied text to `0x45` / 69 characters and writes into a `0x46` / 70 wide-character buffer (Verified with `int_convert.py`). This is not earlier processor state.
- `+0x1b8`: `m_textPaletteIndex` is the best descriptive name. Constructor callers map speech balloon style values to palette indices `143`, `14`, `9`, `200`, and `253`; `PaintBubble` uses this field to select text/palette state. `m_balloonPaletteIndex` is acceptable but less precise because custom handling at palette index `253` is text-color oriented.
- `+0x1bc`: `m_customTextRgb` or `m_customPrimaryTextRgb`. Evidence: packet/style path supplies this only for style `4`, and `PaintBubble` writes it into palette entry `253` when nonzero.
- `+0x1c0`: `m_customSecondaryTextRgb` is the safest name. Evidence: `PaintBubble` writes it into the next palette entry (`m_textPaletteIndex + 1`, index `254` for custom style). `m_customOutlineRgb` is plausible, but current evidence proves secondary text/palette color, not outline semantics.
- `+0x1c4`: `m_lineCount`. Evidence: layout writes line count, paint/measure read the same count.
- `+0x1c6`: `m_lineBreaks` or `m_lineBreakIndexes`. Evidence: layout and measure/wrap code store/read line break positions in the message buffer.
- `+0x1d8`: `m_tailSide` or `m_tailPlacement`. Evidence: layout/update store values such as `0` and `2`; `PaintBubble` chooses tail/frame branch from this field.
- `+0x1da`: `m_tailOffsetX`. Evidence: layout computes half-width-related offset and PaintBubble uses it as a tail x offset.
- `+0x1dc`: `m_cachedBubbleGrafPort`. Evidence: constructor allocates and initializes a `0xa0`-byte GrafPort object, refresh/blit/update/destructor all treat this pointer as the cached offscreen bubble draw target, and destructor deletes it.
- Rejected alternative for `+0x12c`, earlier processor/application state: no caller or field access in this range supports processor state. All accesses are text copy, text measurement, wrapping, and painting.

### Static Mask, Palette, Color, And Callback Globals
- `0x0066d414-0x0066d42c`: class-owned static mask/pattern table, best name `s_balloonFrameMasks`. Evidence: six dwords are referenced only from `PaintBubble`, matching frame/tail rendering masks. Direct owner should remain `BalloonObjectPane` UID `00000U`.
- `0x0069b9fc-0x0069ba24`: class-owned static `PoolAllocator` storage for BalloonObjectPane, 40 bytes, block size 480, chunk count 16 (Verified with `int_convert.py`). Direct owner should remain `BalloonObjectPane`.
- `dword_67A7E0`: `g_pPaletteLib`, not Balloon-owned. It supplies palette lookup/update behavior consumed by `PaintBubble`.
- `byte_66DA97`: `g_useEpfAssets`, not Balloon-owned. It is a broad asset-mode global; BalloonObjectPane is only a consumer.
- `dword_67A7C8 + 2678364`: `g_pConfig + 0x28de5c` (Verified with `int_convert.py`). Best field inference is a persisted speech-balloon fill/background mode flag that toggles the draw-color path in `PaintBubble`. Do not leave the raw `dword_67A7C8 + 2678364` expression in the target; document it as a `g_pConfig` field with a weak descriptive name such as `m_balloonFillEnabled` or `m_speechBubbleBackgroundMode` until the Config layout owner is researched.
- `dword_69B3F8`, `dword_69B3FC`, `dword_69B3E4`: Surface render callback table slots, not Balloon-owned. They should remain dependency names until the Surface/GrafPort callback table pass assigns final APIs.

### Constructor, Destructor, And Compiler Glue
- `0x004682c0`: source constructor. Evidence: called by local balloon creation wrapper `0x0050e100` and packet handler `0x00511710`, calls `AttachedObjectPane` constructor with type `6`, installs vtables, copies text, stores palette/custom-color fields, creates cached GrafPort, computes layout, sets state, and paints.
- `0x004684a0`: constructor-unwind/non-deleting cleanup helper, not a standalone source method. Evidence: no callers in exported function cache, destructor-like cleanup sequence, vtable resets, payload clear, cached GrafPort delete, base destructor call, but no scalar delete/pool free path.
- `0x00468f65` and `0x00468f70`: compiler-generated adjustor thunks. Evidence: each subtracts a fixed base offset from `ecx` and jumps to destructor `0x00468f80`; vtable refs align with secondary base/vtable slices.
- `0x00468f80`: scalar deleting destructor wrapper/source destructor artifact. Evidence: resets vtables, clears owner payload back-reference, deletes cached GrafPort, calls base destructor, frees through BalloonObjectPane pool or generic free based on flags. Source should be modeled as `~BalloonObjectPane()` plus class allocator/delete behavior, not by hand-emitting the scalar deleting wrapper as user source.
- Final direction: document all compiler glue, but keep formal source C++ blank for the current aggregate.

### Message Path And Callers
- Creation wrapper `0x0050e100`: maps style values to palette indices and constructs a BalloonObjectPane from caller-supplied text and optional custom colors.
- Packet/message handler `0x00511710`: parses speech balloon movement/message data, converts text to UTF-16, reads optional custom colors for custom style, maps style to palette indices, allocates from the BalloonObjectPane pool, constructs/registers the object, and therefore proves `+0x1b8/+0x1bc/+0x1c0` are message style/color fields rather than generic unknown ints.
- Map collision helper `0x005062f0`: documented by B002 as `MapPane::HasObjectIntersectingRect(const Rect *rect) const`. It is consumed by BalloonObjectPane layout, not owned by BalloonObjectPane.
- Shared attached-position helper `0x005386c0`: consumed by `0x00468800` and other overlay classes. It belongs to the attached-object placement family, not BalloonObjectPane specifically.

### First-Draft C++ Readiness
- The target meets the numeric C++ gate after recommended scores, but still must not receive formal C++ as a combined aggregate.
- Blocking evidence: raw no-xref helper `0x00468250`; newly discovered raw no-xref helper `0x00468e00`; constructor-unwind cleanup helper; two adjustor thunks; scalar deleting destructor wrapper; large renderer body depending on unresolved Surface/GrafPort callback names/signatures; aggregate range containing multiple source methods and compiler artifacts.
- Rejected alternative, emit one large C++ block now: it would either omit in-range source-authored code, include compiler-generated thunks as false source, or depend on placeholder callback APIs that are not copy/paste-ready.
- Final direction: exact no-code proof for current target is satisfied. Formal C++ should start only after split or after a higher-level source-file/class page emits method declarations while child method pages own individual method bodies.

## Evidence Standards Used
- Direct facts: local exported function records derived from IDA/Ghidra exports for the relevant addresses, current by-* documentation, generated coverage/project rows, and previous executed B-agent reports for adjacent dependencies.
- Documentation evidence: target, class, file, global, static-mask, pool, GrafPort, MapPane, AttachedObjectPane, and proposed source-tree docs.
- Negative evidence: live IDA MCP connection was unavailable from this run, so no new live MCP queries were completed. The report relies on existing live-IDA-backed docs and local exported function records. Lack of IDA name/xrefs for raw helper islands is treated as confidence-limiting negative evidence, not as proof of dead code.
- Inference standard: where original symbol names are not directly recoverable, recommended names are descriptive and source-facing, with rejected alternatives recorded.

## IDA / Exported Function Facts
- `0x00467b30`: `PaintBubble`, IDA-named as `sub_467B30` in current exports, size 1809, callers from repaint/constructor/update paths.
- `0x00468250`: raw repaint helper, size 108, no IDA function name/callers/xrefs in exports; calls GrafPort bounds, empty-rect check, lock, `PaintBubble`, unlock.
- `0x004682c0`: constructor, called by `0x0050e100` and `0x00511710`; initializes base, vtables, message text, style/color fields, cached GrafPort, layout, state, and initial paint.
- `0x004684a0`: destructor-like cleanup helper, no exported callers; best modeled as constructor unwind/non-deleting cleanup.
- `0x00468520`: direction-position update, vtable referenced, consumes MapPane direction helpers and tail-side state.
- `0x00468800`: no-argument position update, vtable referenced, calls shared attached-position helper.
- `0x00468ab0`: vtable referenced, clears two output Rects.
- `0x00468ae0`: vtable referenced, locks and blits cached bubble GrafPort to target.
- `0x00468b90`: layout calculation; writes line count, line break table, bounds, tail placement, and cached GrafPort bounds.
- `0x00468e00`: missing from current target inventory; Ghidra-only measurement/wrap helper, size 357 bytes, no exported IDA callers/xrefs.
- `0x00468f65`, `0x00468f70`: adjustor thunks to destructor.
- `0x00468f80`: scalar deleting destructor / destructor wrapper with pool free.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00467b30-0x00468241` | current target child range | `BalloonObjectPane::PaintBubble` | Yes | `00000U` | target score | Keep, source-authored method |
| `0x00468250-0x004682bb` | current target child range | `RefreshBubbleSurface` raw repaint helper | Yes, raw | `00000U` | target score capped | Add/document, no aggregate C++ |
| `0x004682c0-0x0046849c` | current target child range | Constructor | Yes | `00000U` | target score | Keep, source constructor |
| `0x004684a0-0x0046851d` | current target child range | Constructor-unwind/non-deleting cleanup | Compiler glue | `00000U` artifact | no standalone score | Document, do not emit as source method |
| `0x00468520-0x004687fc` | current target child range | `UpdatePositionForDirection` | Yes | `00000U` | target score | Keep |
| `0x00468800-0x00468aab` | current target child range | `UpdatePosition` / `UpdateAttachedPosition` | Yes | `00000U` | target score | Keep |
| `0x00468ab0-0x00468ada` | current target child range | `ClearOutputRects` | Yes | `00000U` | target score | Rename from generic clear-bounds wording |
| `0x00468ae0-0x00468b81` | current target child range | `BlitBubbleSurface` | Yes | `00000U` | target score | Rename from `MoveBubbleGrafPort` |
| `0x00468b90-0x00468df1` | current target child range | `CalculateLayout` | Yes | `00000U` | target score | Keep |
| `0x00468e00-0x00468f65` | missing current inventory | `MeasureWrappedTextWidthRaw` | Yes, raw | `00000U` | target score capped | Add/document before code |
| `0x00468f65-0x00468f70` | current target child range | Adjustor thunk | Compiler glue | `00000U` artifact | no standalone score | Document, no source body |
| `0x00468f70-0x00468f7b` | current target child range | Adjustor thunk | Compiler glue | `00000U` artifact | no standalone score | Document, no source body |
| `0x00468f80-0x0046904e` | current target child range | Scalar deleting destructor / destructor wrapper | Yes as source destructor plus glue | `00000U` | target score | Do not hand-emit wrapper as source |
| `0x0066d414-0x0066d42c` | `by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md` | static mask table | Yes data | `00000U` | 86/92 | Support row update |
| `0x0069b9fc-0x0069ba24` | `by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md` | static pool storage | Yes data | `00000U` | 85/91 | Support row update |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00468250` | calls `0x00467b30` | Refreshes cached bubble surface by repainting through `PaintBubble`. |
| `0x004682c0` | callers `0x0050e100`, `0x00511710` | Local wrapper and packet/message path construct BalloonObjectPane. |
| `0x00467b30` | callers `0x0046829d`, `0x0046846c`, `0x004687a3`, `0x00468a54` | Paint used after cached-surface refresh, construction, and position/tail changes. |
| `0x00468b90` | calls `0x005062f0` | Layout asks MapPane whether candidate bubble rect intersects an object. |
| `0x00468800` | calls `0x005386c0` | Reuses shared attached-object position helper. |
| `0x00468ae0` | calls GrafPort copy/blit helper | Draws cached bubble surface into target GrafPort. |
| `0x00468f65`, `0x00468f70` | jump to `0x00468f80` | Destructor adjustor thunks for secondary base/vtable entries. |
| `0x0066d414` table | read from `PaintBubble` only | Class-local static frame/tail mask table. |
| `0x0069b9fc` storage | allocation/free construction/destruction refs | Class-local BalloonObjectPane pool allocator storage. |

## Documentation Evidence And IDA Status
- `by-class/BalloonObjectPane.md`: supports class-level source ownership, speech balloon overlay role, cached bubble surface refresh, frame/tail/text drawing, owner-relative placement, static masks, and pool storage. It still needs the field/global/helper-name closures from this report.
- `by-file/AttachedObjectPane.md`: supports the final source file path `NexusTK/map/AttachedObjectPane.cpp` and groups attached overlay classes in one source file. This remains the correct file route.
- `by-class/AttachedObjectPane.md` and `by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md`: support inherited registry/placement state and shared attached-position helper, but do not make the BalloonObjectPane method island base-owned.
- `by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md` and the executed B002 report: support final name `MapPane::HasObjectIntersectingRect(const Rect *rect) const`; BalloonObjectPane is a caller only.
- `by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md`: supports exact class-owned mask table and should have its coverage row refreshed.
- `by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md`: supports exact class-owned pool storage and should have its coverage row refreshed.
- `by-global/g_useEpfAssets.md`: rejects attachment-specific naming for `byte_66DA97`.
- `by-global/g_pPaletteLib.md` and `by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md`: support `g_pPaletteLib` as a PaletteLib global dependency, not a BalloonObjectPane static.
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: supports callback table ownership for render callback slots used by `PaintBubble`.
- Generated state: current generated output has only an empty marker for UID `0000YZ`; current auto coverage row routes through file UID `0000HJ` and should be changed to class UID `00000U` after metadata is updated.

## Ranked Ownership Analysis

### 1. BalloonObjectPane class UID `00000U`
- Evidence for: vtable installation, class-specific constructor/destructor, field layout, text buffer, cached GrafPort, tail placement, class static masks, class pool storage, all method bodies using `this` as BalloonObjectPane.
- Evidence against: generated source file remains `AttachedObjectPane.cpp`, and some helpers call inherited AttachedObjectPane/MapPane services. This is source placement/dependency evidence, not direct-owner evidence.
- Decision: accept as canonical owner and emitter UID.

### 2. AttachedObjectPane.cpp file UID `0000HJ`
- Evidence for: proposed source tree and by-file docs place BalloonObjectPane inside the attached overlay implementation file alongside related overlay panes. Current generated output path already uses `NexusTK/map/AttachedObjectPane.cpp`.
- Evidence against: file-level owner is broader than the actual semantic owner and obscures method/class state. It is not the narrowest direct owner under by-structure rules.
- Decision: keep as source route through class/file chain, reject as direct canonical owner for the memory item.

### 3. AttachedObjectPane class UID `00000M`
- Evidence for: BalloonObjectPane inherits base placement/registry behavior and calls shared attached-position logic.
- Evidence against: the target range is derived-specific and vtable-owned by BalloonObjectPane, not base class code.
- Decision: reject as owner; keep as dependency.

### 4. New standalone `BalloonObjectPane.cpp`
- Evidence for: the method island is large enough to plausibly be a separate source file in another project organization.
- Evidence against: project proposed-source-tree explicitly groups BalloonObjectPane under `AttachedObjectPane.cpp`; sibling overlay classes and current by-file docs support one attached-overlay file; generated route already exists and is coherent.
- Decision: reject for now. If later source-tree research splits attached overlay classes into separate files, this item should be reconsidered, but current evidence favors `AttachedObjectPane.cpp`.

### Proposed New File/Grouping
- Proposed owner/name/path: no new file recommended now. Use existing class UID `00000U` under file UID `0000HJ`.
- Likely full contents of existing grouping: `AttachedObjectPane`, `AttachmentAnchorResolver`, `BalloonObjectPane`, `ObjectInfoObjectPane`, `HitBarObjectPane`, and `DamageNumberObjectPane`, matching the proposed source-tree evidence.
- Candidate related items that belong: BalloonObjectPane methods in UID `0000YZ`, static masks UID `000276`, pool static storage UID `0002WU`, and class/vtable declarations in UID `00000U`.
- Candidate related items rejected: `MapPane::HasObjectIntersectingRect` UID `0002QQ` belongs to MapPane; `g_pPaletteLib` belongs to PaletteLib global ownership; Surface render callback table belongs to Surface/GrafPort infrastructure; `g_useEpfAssets` belongs to global asset/config startup ownership.
- Standalone, narrow, or broad source-file inference: broad existing attached-overlay source file, narrow class-level method ownership.

## Negative Evidence Summary
- Live IDA MCP could not be reached during this pass. This prevents new live xref confirmation and keeps confidence below final-audit levels.
- Raw helper `0x00468250` has no exported IDA function name or callers/xrefs. The body is coherent, but raw reachability remains a C++ blocker.
- Raw helper `0x00468e00` is missing from target docs and has no exported IDA callers/xrefs. The body is coherent and should be documented, but its no-xref status blocks aggregate source emission.
- Render callback globals used by `PaintBubble` are not final named APIs. They are dependencies, not BalloonObjectPane-owned globals.
- Consumer-only xrefs from BalloonObjectPane to MapPane, PaletteLib, Config, Surface callbacks, and shared placement helpers do not prove ownership of those dependencies.
- Current file-owner metadata is useful generated-routing evidence, but it is too broad for direct canonical ownership.

## Score And Metadata Recommendation
- Target before: `COMPLETION:84`, `CONFIDENCE:90`, combined `87.0`.
- Target after: `COMPLETION:88`, `CONFIDENCE:91`, combined `89.5`.
- Reason for raising completion: field meanings, raw repaint helper role, missing raw measurement helper, static support ownership, message path, function inventory, and no-code proof are now substantially resolved.
- Reason confidence remains under 95: live IDA MCP was unavailable, two raw no-xref helper islands remain, renderer callback signatures are not final, and no formal split/child pages were created in this report-only pass.
- Metadata recommendation:
  - `CANONICAL_OWNER:00000U`
  - `EMITTER_UIDS:00000U`
  - Keep generated path through class/file ownership as `auto-generated/NexusTK/map/AttachedObjectPane.cpp`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `RECONSTRUCTION_CPP CODE` blank for UID `0000YZ`

## Coverage / Generated Row Replacement Text

Do not edit `by-memory/-coverage-report.md` directly during the active ban. Replace the current UID `0000YZ`, `000276`, and `0002WU` rows with the following exact rows after the corresponding target metadata/docs are updated:

```markdown
    - [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) 0x00467b30-0x0046904e | class-method aggregate | BalloonObjectPaneMethodIsland : reconstructable : 88% : strong : Source-quality reanalysis keeps the implementation in the BalloonObjectPane class while routing emitted source through AttachedObjectPane.cpp; resolves `+0x12c` as the 70-wide-character message buffer, `+0x1b8/+0x1bc/+0x1c0` as the speech text palette/custom RGB fields, `+0x1d8/+0x1da` as tail placement/offset, and `+0x1dc` as the cached bubble GrafPort. Existing modeled methods cover PaintBubble, constructor, layout, position, blit, clear, and destructor behavior; raw no-xref islands at `0x00468250` (`RefreshBubbleSurface`) and newly documented `0x00468e00` (`MeasureWrappedTextWidthRaw`) plus EH cleanup/adjustor thunks prove the current aggregate should remain C++-blank until split into exact children.
```

```markdown
    - [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md) 0x0066d414-0x0066d42c | initialized data table | BalloonObjectPaneStaticMasks : reconstructable : 86% : very strong : Exact six-dword BalloonObjectPane PaintBubble frame/tail mask table; live IDA-backed docs record the raw bytes, per-entry values, nine direct xrefs all inside `PaintBubble`, immediate padding/AutoInit successor boundaries, direct class owner [UID:00000U], and source-declared/generated-binary handling through AttachedObjectPane.cpp.
```

```markdown
    - [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md) 0x0069b9fc-0x0069ba24 | static PoolAllocator storage | BalloonObjectPanePoolStaticStorage : reconstructable : 85% : very strong : Exact BalloonObjectPane static PoolAllocator storage, `0x28` / 40 bytes (Verified with int_convert.py), block size `0x1e0` / 480 and chunk count `0x10` / 16 (Verified with int_convert.py); direct xrefs cover startup construction, allocation from MapPane speech-balloon paths, constructor-unwind free, scalar deleting destructor free, cleanup wrapper, direct class owner [UID:00000U], and source-declared/generated-binary handling.
```

Expected generated memory coverage row after metadata correction:

```markdown
| [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) | emits | `00000U` | `00000U` |  | no | `auto-generated/NexusTK/map/AttachedObjectPane.cpp` | `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md` |  |
```

Expected project-level stats row after target score update:

```markdown
| `0000YZ` | 88 | 91 | 89.5 | `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md` |
```

## First-Draft C++ Recommendation
- Do not populate `RECONSTRUCTION_CPP CODE` for UID `0000YZ` now.
- This is an exact no-code recommendation, not a failure to pass the active C++ gate. The target is numerically eligible after score correction, but the current range is the wrong emission unit.
- Formal code should be entered only after one of these happens:
  - the range is split into exact source-bearing method children plus compiler-glue children; or
  - a class/file emitter owns declarations and the in-range method bodies are represented by child emitters with raw helper boundaries explicitly handled.
- First split candidates:
  - `0x00467b30-0x00468241` `BalloonObjectPane::PaintBubble`
  - `0x00468250-0x004682bb` `BalloonObjectPane::RefreshBubbleSurface`
  - `0x004682c0-0x0046849c` constructor
  - `0x004684a0-0x0046851d` constructor-unwind cleanup artifact
  - `0x00468520-0x004687fc` `UpdatePositionForDirection`
  - `0x00468800-0x00468aab` `UpdatePosition`
  - `0x00468ab0-0x00468ada` `ClearOutputRects`
  - `0x00468ae0-0x00468b81` `BlitBubbleSurface`
  - `0x00468b90-0x00468df1` `CalculateLayout`
  - `0x00468e00-0x00468f65` `MeasureWrappedTextWidthRaw`
  - `0x00468f65-0x00468f70` adjustor thunk
  - `0x00468f70-0x00468f7b` adjustor thunk
  - `0x00468f80-0x0046904e` destructor/scalar deleting wrapper
- Before actual split, verify padding/gaps around `0x00468df1-0x00468e00`, `0x00468f7b-0x00468f80`, and after `0x0046904e` against live IDA/validator state.

## Final Recommendation
- Update UID `0000YZ` documentation to:
  - add the missing `0x00468e00` raw helper inventory;
  - name `0x00468250` as `RefreshBubbleSurface`;
  - use `PaintBubble`, `CalculateLayout`, `UpdatePositionForDirection`, `UpdatePosition`, `ClearOutputRects`, `BlitBubbleSurface`, and `MeasureWrappedTextWidthRaw` as source-facing helper names;
  - record field layout names for `+0x12c`, `+0x1b8/+0x1bc/+0x1c0`, `+0x1c4/+0x1c6`, `+0x1d8/+0x1da`, and `+0x1dc`;
  - classify Config/PaletteLib/Surface callback dependencies as external globals, not Balloon-owned globals;
  - set `CANONICAL_OWNER:00000U` and `EMITTER_UIDS:00000U`;
  - score as `88/91`;
  - keep final C++ blank with the no-code proof above.
- Update support row text for UID `000276` and UID `0002WU` to match their current docs and class ownership.
- Do not create `BalloonObjectPane.cpp` at this time. Use class-level ownership under `AttachedObjectPane.cpp`.

## Follow-Up Actions
- Supervisor actions:
  - Apply the target-doc field/name/ownership/score updates or assign an A/C agent to incorporate them.
  - Apply the exact coverage replacement rows above when coverage-report edits are allowed.
  - Preserve blank formal C++ for UID `0000YZ` unless the target is split or a child-emitter plan is implemented.
- A-agent actions:
  - Incorporate the report-level facts into the target by-memory page and class page, including the missing `0x00468e00` helper and exact field/global descriptions.
  - If writing C++ later, split or model method children first rather than emitting the current aggregate.
- B008 future research actions:
  - If assigned a follow-up split pass, create exact child pages for the method island and validate padding/range boundaries before any C++ draft.
  - If assigned Config research, resolve the exact `g_pConfig + 0x28de5c` field name and semantics.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `88/91`; raising above this should wait for live IDA MCP confirmation, exact split/child validation, and final callback API names.
- Remaining uncertainty: original source names for several helpers and Config field name cannot be proven from current evidence. The descriptive names are strong enough for documentation and source-quality improvement, but not enough for final-audit scoring or aggregate C++.

## Validator Results
- Commands run: none.
- Results: not applicable. This pass created only the B008 research report and did not edit by-* target docs, generated files, project-level reports, or coverage reports.
- Unresolved validator warnings/errors: none introduced by this report.

## Changed Files
- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B008\research\0000YZ-BalloonObjectPane-source-quality.md`
- Modified: none outside the created B008 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000YZ-BalloonObjectPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000YZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
