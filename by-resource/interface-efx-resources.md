*** UID:0001RE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Interface Effect Resources

## Status

- Confidence: strong for observed filenames, owning code, and source/resource boundary; medium for exact DAT family/format details.
- Owner file hypothesis: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Resource Family

| Resource | Observed owner/use | Rebuild handling | Notes |
| --- | --- | --- | --- |
| `CHREFX.EPD` | `InterfaceEfxMgr` constructor | Resource-derived persistent effect payload. Preserve the constructor filename constant and owned-effect slot in `InterfaceEfxMgr`; the frame bytes belong to DAT/source-asset packaging. | Persistent character interface effect in old-layout manager. |
| `MAGEFX.EPD` | `InterfaceEfxMgr` constructor | Resource-derived persistent effect payload. Preserve the trigger id mapping to the manager's magic-effect slot in source. | Persistent magic interface effect in old-layout manager. |
| `ITEMEFX.EPD` | `InterfaceEfxMgr` constructor | Resource-derived persistent effect payload. Preserve the trigger id mapping to the manager's item-effect slot in source. | Persistent item interface effect in old-layout manager. |
| `FRMLEFX.EPD` | `InterfaceEfxMgr::SpawnRandomFrameEffects` | Resource-derived transient frame-effect payload. Preserve the periodic spawn filename and left-side placement behavior in source. | Left-side periodic frame effect. |
| `FRMREFX.EPD` | `InterfaceEfxMgr::SpawnRandomFrameEffects` | Resource-derived transient frame-effect payload. Preserve the periodic spawn filename and right-side placement behavior in source. | Right-side periodic frame effect. |
| `INTEFX.PAD` | all manager-created `InterfaceEfx` instances | Resource-derived palette/config payload shared by these interface effects. Source owns the filename argument and loader call, not the PAD bytes. | Palette/config resource passed into `InterfaceEfx` construction. |

## Behavior Notes

- `InterfaceEfx` stores a short effect filename and resolves it through the effect frame library during construction/playback.
- `InterfaceEfx::Play` asks the effect frame library for frame dimensions, sets the render/clip rectangle, resets the current tick, and schedules immediate update.
- `InterfaceEfxMgr::SpawnRandomFrameEffects` creates `FRMLEFX.EPD` and `FRMREFX.EPD`, plays them only when the client option flag at `g_clientStateBase + 0x28de5e` is nonzero, then schedules the next frame-effect cycle after a randomized 120000-299999 ms delay.

## Runtime Role Matrix

| Runtime role | Resource inputs | Source behavior to preserve | Boundary notes |
| --- | --- | --- | --- |
| Persistent character interface effect | `CHREFX.EPD`, `INTEFX.PAD` | Constructed as a long-lived `InterfaceEfxMgr` member and played through the trigger-id route. | Payload frames/config remain resource-derived; source owns the member slot and trigger routing. |
| Persistent magic interface effect | `MAGEFX.EPD`, `INTEFX.PAD` | Constructed as a long-lived manager member and played by the magic-effect trigger route. | Preserve the distinct filename and manager slot instead of folding into the character/item paths. |
| Persistent item interface effect | `ITEMEFX.EPD`, `INTEFX.PAD` | Constructed as a long-lived manager member and played by the item-effect trigger route. | Preserve the distinct filename and trigger route until UI action names are verified. |
| Transient left frame effect | `FRMLEFX.EPD`, `INTEFX.PAD` | Spawned by `SpawnRandomFrameEffects`, placed on the left interface frame, and option-gated before playback. | Lifetime and randomized scheduling are source behavior; visual bytes remain packaged resource data. |
| Transient right frame effect | `FRMREFX.EPD`, `INTEFX.PAD` | Spawned by `SpawnRandomFrameEffects`, placed on the right interface frame, and option-gated before playback. | Keep paired with `FRMLEFX.EPD`, but preserve the separate filename and placement. |

## Source Ownership Notes

[UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) owns the source behavior: effect object construction, trigger id routing, client-option gating, left/right frame-effect spawn positions, and the randomized reschedule interval. The `.EPD` and `.PAD` files are resource packaging inputs consumed by that source.

Keep this resource family separate from [UID:0000IZ][Effects](by-file/Effects.md) and map/screen overlay effecters. The owner docs place these assets in `ui/InterfaceEfx.cpp` because they are old-layout interface art, not general map effect logic.

## Rebuild Packaging Boundary

Package the five `.EPD` files and shared `INTEFX.PAD` as old-layout interface effect resources. Source reconstruction should preserve `InterfaceEfxMgr` member slots, trigger routing, the client-option gate, left/right placement, and the randomized frame-effect interval, while leaving frame pixels and PAD data in the resource pack.

Effect scheduling remains a `TimerMgr`/`TimerHandler` concern through the owner source. Do not merge this family into map/screen overlay `Effects` handling or `EffectObjImageLib`; those systems are adjacent consumers of effect infrastructure, not the owner of these UI filenames.

## Scope Boundaries

- `INTEFX.PAD` is shared by all `InterfaceEfx` construction paths, but this page does not decode its binary structure.
- `FRMLEFX.EPD` and `FRMREFX.EPD` are transient old-layout frame art, not persistent tab/action effects.
- `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD` describe interface actions; final names should still follow verified legacy UI terminology if later evidence refines the trigger labels.
- DAT/archive provenance and PAD-format ownership remain open resource-pipeline questions.

## Rebuild Notes

For source reconstruction, the manager should keep three persistent effect members for `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD`, plus transient left/right spawns for `FRMLEFX.EPD` and `FRMREFX.EPD`. `INTEFX.PAD` should remain a shared resource argument passed into each `InterfaceEfx` construction path until the PAD format is documented elsewhere.

Final rebuild packaging still needs DAT/archive review to identify the package containing the EPD/PAD files and to determine whether `INTEFX.PAD` is a palette, draw-state table, or broader effect configuration blob.

## Open Questions

- Which DAT/archive contains `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, `FRMREFX.EPD`, and `INTEFX.PAD`?
- What is the exact binary structure of `INTEFX.PAD` and does it contain palette data, frame offsets, or both?
- Are the persistent trigger ids final as character/item/magic, or should the source names follow legacy UI tab/action terminology?

## IDA MCP Evidence

- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed InterfaceEfx/resource docs and does not claim a fresh string/xref pass.
- `INTEFX.PAD` at `0x0061c6c0` xrefs from `0x004e9d00-0x004e9e78`, `0x004e9f40-0x004ea05e`, and `0x004ea130-0x004ea202`.
- `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD` at `0x0061c6d8`, `0x0061c6f0`, and `0x0061c708` xref into the persistent interface-effect construction paths.
- `FRMLEFX.EPD` and `FRMREFX.EPD` at `0x0061c720` and `0x0061c738` xref from `0x004e9f40-0x004ea05e`, matching the randomized frame-effect spawn path.

## Score Rationale

- Completion is `78` because the page now separates persistent character/magic/item roles from transient frame-effect roles, documents the shared PAD dependency, identifies source-owned trigger/spawn/scheduling behavior, and records explicit exclusion boundaries for adjacent effect systems.
- Confidence remains `87` because the earlier IDA-backed string/xref evidence and owner docs support the filenames and ownership, but this session could not perform a fresh IDA check and the DAT/PAD format remains unresolved.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with IDA MCP resource string addresses and xrefs.
- Evidence: IDA MCP UTF-16 byte search and xrefs for `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`.
- 2026-06-06 rebuild-boundary pass:
  - What existed before: resource filenames, owner usage, and behavior notes were present, but the page did not separate source-owned manager behavior from resource-derived EPD/PAD payloads.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:87`, with rebuild handling, source ownership notes, and DAT/PAD-format open questions.
  - Summary/evidence: `InterfaceEfx` and `InterfaceEfxMgr` owner docs now support the UI/source placement and trigger/spawn behavior; final asset provenance and PAD structure remain open.
- 2026-06-07 role-matrix pass:
  - What existed before: the page listed the resource family and owner behavior, but did not spell out the persistent/transient runtime roles or scheduler/effect-system exclusions.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:87`, with a runtime role matrix, rebuild packaging boundary, scope boundaries, and current-session IDA availability caveat.
  - Summary/evidence: existing InterfaceEfx owner/resource docs support the persistent manager members, transient frame spawns, shared `INTEFX.PAD` dependency, and source-versus-resource split; confidence is unchanged because fresh IDA MCP verification was unavailable.
