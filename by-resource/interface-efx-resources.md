*** UID:0001RE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Interface Effect Resources

## UID0000KA Exact Item-Effect Consumer - 2026-08-15

Legacy `InventoryPane` constructs one `InterfaceEfx` with `ITEMEFX.EPD` and shared `INTEFX.PAD` at exact xrefs `0x004ea1c4` and `0x004ea1ac`, stores the pointer for pane lifetime, and calls `Play()` from its paired effect method. All other InterfaceEfxMgr, SpellInventoryPane, and loader xrefs retain their existing owners. This resource page remains packaging authority; InventoryPane emits only literal operands at its use site and no standalone resource data.

## Status

- Confidence: very strong for observed filenames, owning code, shared effect-loader consumers, source/resource boundary, current-package effect-family provenance, and legacy EPD/PAD blocker classification; medium for exact legacy payload provenance and PAD/EPF format mapping.
- Owner file hypothesis: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Resource Family

| Resource | Observed owner/use | Rebuild handling | Notes |
| --- | --- | --- | --- |
| `CHREFX.EPD` | `InterfaceEfxMgr` constructor | Resource-derived persistent effect payload. Preserve the constructor filename constant and owned-effect slot in `InterfaceEfxMgr`; the frame bytes belong to DAT/source-asset packaging. | Persistent character interface effect in old-layout manager. |
| `MAGEFX.EPD` | `InterfaceEfxMgr` constructor | Resource-derived persistent effect payload. Preserve the validated trigger id `3` mapping to the manager's `m_magicEffect` slot in source. | Persistent magic interface effect in old-layout manager. |
| `ITEMEFX.EPD` | `InterfaceEfxMgr` constructor | Resource-derived persistent effect payload. Preserve the validated trigger id `2` mapping to the manager's `m_itemEffect` slot in source. | Persistent item interface effect in old-layout manager. |
| `FRMLEFX.EPD` | `InterfaceEfxMgr::OnTimer` | Resource-derived transient frame-effect payload. Preserve the periodic spawn filename and left-side placement behavior in source. | Left-side periodic frame effect. |
| `FRMREFX.EPD` | `InterfaceEfxMgr::OnTimer` | Resource-derived transient frame-effect payload. Preserve the periodic spawn filename and right-side placement behavior in source. | Right-side periodic frame effect. |
| `INTEFX.PAD` | all manager-created `InterfaceEfx` instances | Resource-derived palette/config payload shared by these interface effects. Source owns the filename argument and loader call, not the PAD bytes. | Palette/config resource passed into `InterfaceEfx` construction. |

## Package Provenance

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format and checked for loose matching files. The current package does not contain the binary-referenced `.EPD` / `.PAD` names, but it does contain same-basename current effect assets in `efx.dat`:

| Binary operand | Current package evidence |
| --- | --- |
| `CHREFX.EPD` | No `CHREFX.EPD` entry or loose file found. Current package has `CHREFX.EPF` in `efx.dat`, index `0`, offset `174`, size `149,340`. |
| `MAGEFX.EPD` | No `MAGEFX.EPD` entry or loose file found. Current package has `MAGEFX.EPF` in `efx.dat`, index `8`, offset `2,227,336`, size `1,527,932`. |
| `ITEMEFX.EPD` | No `ITEMEFX.EPD` entry or loose file found. Current package has `ITEMEFX.EPF` in `efx.dat`, index `7`, offset `958,128`, size `1,269,208`. |
| `FRMLEFX.EPD` | No `FRMLEFX.EPD` entry or loose file found. Current package has `FRMLEFX.EPF` in `efx.dat`, index `4`, offset `922,632`, size `13,048`. |
| `FRMREFX.EPD` | No `FRMREFX.EPD` entry or loose file found. Current package has `FRMREFX.EPF` in `efx.dat`, index `5`, offset `935,680`, size `21,392`. |
| `INTEFX.PAD` | No `INTEFX.PAD` entry or loose file found. Current package has `INTEFX.PAL` in `efx.dat`, index `6`, offset `957,072`, size `1,056`, with `DLPalette` header. |

This proves the current package groups the interface-effect family in `efx.dat` and ships EPF/PAL variants for the same basenames. It does not prove that the old `.EPD` / `.PAD` operands are present in this distribution, so the page keeps the binary-referenced names as source operands and records the package variant as current-package provenance rather than a source rename.

2026-06-16 A002 table-only scan across all audited current-package `.dat` archives reconfirmed those exact `efx.dat` entries and found no exact `.EPD` or `INTEFX.PAD` entry. The first three `uint16` fields in the EPF/PAL successor headers are: `CHREFX.EPF` `12,25,270`; `MAGEFX.EPF` `12,155,289`; `ITEMEFX.EPF` `12,192,261`; `FRMLEFX.EPF` `43,19,26`; `FRMREFX.EPF` `43,28,26`; and `INTEFX.PAL` begins with `DLPalette`. These header values support same-family current-package provenance, not a rename of the binary operands.

## Blocker Classification

2026-06-14 A002 reran the package audit with corrected start-offset DAT parsing, case-insensitive exact-name checks, loose-file search across `E:\2026\Resources`, and a narrow raw-name scan over the read-only client files. The exact operands `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, `FRMREFX.EPD`, and `INTEFX.PAD` remain absent from DAT entry names and loose resources.

The only exact missing-operand occurrences outside IDA are UTF-16 executable literals in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`: `INTEFX.PAD` at raw offset `2,207,936`, `CHREFX.EPD` at `2,207,960`, `MAGEFX.EPD` at `2,207,984`, `ITEMEFX.EPD` at `2,208,008`, `FRMLEFX.EPD` at `2,208,032`, and `FRMREFX.EPD` at `2,208,056`.

2026-06-16 A002 repeated the legacy-name check with a full table-only DAT scan, loose exact-name search under `E:\2026\Resources`, and aligned UTF-16 scan of `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`. The same raw executable offsets were found, and no current DAT or loose payload for the exact legacy operands was found.

Treat these blockers as code-referenced old-interface-effect operands whose exact payloads are missing from the audited current distribution. The current `efx.dat` EPF/PAL entries are same-basename successor/current-package variants, not proof that the old `.EPD`/`.PAD` resources can be dropped from the source contract.

## Behavior Notes

- `InterfaceEfx` stores a short effect filename and resolves it through the effect frame library during construction/playback.
- `InterfaceEfx::Play` asks the effect frame library for frame dimensions, sets the render/clip rectangle, resets the current tick, and schedules immediate update.
- `InterfaceEfxMgr::TriggerInterfaceEffect` maps legacy side-panel effect ids `0` and `1` to the persistent character effect (`CHREFX.EPD`), id `2` to the item effect (`ITEMEFX.EPD`), and id `3` to the magic effect (`MAGEFX.EPD`).
- [UID:0004V2][0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer](by-memory/0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer.md) creates `FRMLEFX.EPD` and `FRMREFX.EPD`, plays them only when the `Shadow` graphics option byte at `g_pConfig +0x28de5e` is nonzero, then schedules the next frame-effect cycle after a randomized 120000-299999 ms delay and returns `true`.
- `InventoryPane` and `SpellInventoryPane` are confirmed non-manager consumers of this same resource family: `InventoryPane` constructs `ITEMEFX.EPD` with `INTEFX.PAD`, while `SpellInventoryPane` constructs `MAGEFX.EPD` with `INTEFX.PAD`. This makes `INTEFX.PAD` shared interface-effect packaging, not manager-private data.

## Runtime Role Matrix

| Runtime role | Resource inputs | Source behavior to preserve | Boundary notes |
| --- | --- | --- | --- |
| Persistent character interface effect | `CHREFX.EPD`, `INTEFX.PAD` | Constructed as long-lived `m_characterEffect` and played by trigger ids `0` and `1`. | Payload frames/config remain resource-derived; source owns the member slot and trigger routing. |
| Persistent magic interface effect | `MAGEFX.EPD`, `INTEFX.PAD` | Constructed as long-lived `m_magicEffect` and played by trigger id `3`. | Preserve the distinct filename and manager slot instead of folding into the character/item paths. |
| Persistent item interface effect | `ITEMEFX.EPD`, `INTEFX.PAD` | Constructed as long-lived `m_itemEffect` and played by trigger id `2`. | Preserve the distinct filename and trigger route; current tab/effect mapping is validated by [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md). |
| Transient left frame effect | `FRMLEFX.EPD`, `INTEFX.PAD` | Spawned by `InterfaceEfxMgr::OnTimer`, placed on the left interface frame, and option-gated before playback. | Lifetime and randomized scheduling are source behavior; visual bytes remain packaged resource data. |
| Transient right frame effect | `FRMREFX.EPD`, `INTEFX.PAD` | Spawned by `InterfaceEfxMgr::OnTimer`, placed on the right interface frame, and option-gated before playback. | Keep paired with `FRMLEFX.EPD`, but preserve the separate filename and placement. |

## Source Ownership Notes

[UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md) owns the source behavior: effect object construction, trigger id routing, client-option gating, left/right frame-effect spawn positions, and the randomized reschedule interval. The `.EPD` and `.PAD` files are resource packaging inputs consumed by that source.

The prior descriptive label `InterfaceEfxMgr::SpawnRandomFrameEffects` is retained only as a superseded behavior name. The tertiary timer vtable slot, `bool OnTimer(int,int,int)` ABI, scheduling call, and synchronized class declaration establish `InterfaceEfxMgr::OnTimer` as the source-facing method identity.

Keep this resource family separate from [UID:0000IZ][Effects](by-file/Effects.md) and map/screen overlay effecters. The owner docs place these assets in `ui/InterfaceEfx.cpp` because they are old-layout interface art, not general map effect logic.

## Rebuild Packaging Boundary

Package the five `.EPD` files and shared `INTEFX.PAD` as old-layout interface effect resources. Source reconstruction should preserve `InterfaceEfxMgr` member slots, trigger routing, the client-option gate, left/right placement, and the randomized frame-effect interval, while leaving frame pixels and PAD data in the resource pack.

Effect scheduling remains a `TimerMgr`/`TimerHandler` concern through the owner source. Do not merge this family into map/screen overlay `Effects` handling or `EffectObjImageLib`; those systems are adjacent consumers of effect infrastructure, not the owner of these UI filenames.

## Scope Boundaries

- `INTEFX.PAD` is shared by all `InterfaceEfx` construction paths, but this page does not decode its binary structure.
- 2026-06-16 decompilation identifies the non-manager consumers: `sub_4EA130` is the `InventoryPane` constructor path that creates `ITEMEFX.EPD` with `INTEFX.PAD`, and `sub_57C2D0` is the `SpellInventoryPane` constructor path that creates `MAGEFX.EPD` with `INTEFX.PAD`. Keep the semantic family here because the manager still owns the persistent/transient UI effect slots, but do not treat `INTEFX.PAD`, `ITEMEFX.EPD`, or `MAGEFX.EPD` as manager-private packaging data.
- `FRMLEFX.EPD` and `FRMREFX.EPD` are transient old-layout frame art, not persistent tab/action effects.
- `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD` describe interface actions; [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) validates the current trigger-id mapping as `0/1` character, `2` item, and `3` magic. Final names may still follow more specific legacy UI terminology if later evidence refines the labels.
- Exact legacy EPD/PAD payload provenance and PAD-format ownership remain open resource-pipeline questions; current-package EPF/PAL variant grouping is now proven.

## Rebuild Notes

For source reconstruction, the manager should keep three persistent effect members for `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD`, plus transient left/right spawns for `FRMLEFX.EPD` and `FRMREFX.EPD`. `INTEFX.PAD` should remain a shared resource argument passed into each `InterfaceEfx` construction path until the PAD format is documented elsewhere.

Final rebuild packaging still needs another package/distribution audit for the binary-referenced EPD/PAD files and a format review that explains the current `INTEFX.PAL` versus binary `INTEFX.PAD` split.

## Open Questions

- Find a distribution or loose-resource source for `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, `FRMREFX.EPD`, and `INTEFX.PAD`; the current package contains same-basename `.EPF` files and `INTEFX.PAL` in `efx.dat`, but not the exact legacy operands.
- What is the exact binary structure of `INTEFX.PAD`, and how does it relate to the current-package `INTEFX.PAL` payload?
- Are the source spellings for the persistent effect members and legacy tab/action labels more specific than the current descriptive `m_characterEffect`, `m_itemEffect`, and `m_magicEffect` names?

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms `INTEFX.PAD` at `0x0061c6c0` has seven observed xrefs: three in `sub_4E9D00`, two in `sub_4E9F40`, one in `sub_4EA130`, and one in `sub_57C2D0`.
- `CHREFX.EPD` at `0x0061c6d8` has one xref, `0x004e9dac` in `sub_4E9D00`, matching persistent character-effect construction.
- `MAGEFX.EPD` at `0x0061c6f0` has two xrefs, `0x004e9df0` in `sub_4E9D00` and `0x0057c361` in `sub_57C2D0`, so the magic-effect resource is not exclusively manager-local.
- `ITEMEFX.EPD` at `0x0061c708` has two xrefs, `0x004e9e38` in `sub_4E9D00` and `0x004ea1c4` in `sub_4EA130`.
- `FRMLEFX.EPD` and `FRMREFX.EPD` at `0x0061c720` and `0x0061c738` each have one xref, `0x004e9f98` and `0x004e9fe2` in `sub_4E9F40`, matching the randomized frame-effect spawn path.
- 2026-06-16 A002 live MCP refresh on database `b001_selflookpane_0001H7_20260616` reconfirmed function sizes for `sub_4E9D00` (`0x178`), `sub_4E9F40` (`0x11e`), `sub_4EA130` (`0xd2`), and `sub_57C2D0` (`0xcf`) plus the same xref counts. Decompilation confirms `sub_4E9D00` stores persistent effects at manager offsets `+0xf8`, `+0xfc`, and `+0x100`; `sub_4E9F40` creates left/right frame effects and reschedules with `rand() % 180000 + 120000`; `sub_4EA130` creates the inventory item effect; and `sub_57C2D0` creates the spell/magic effect.

## Score Rationale

- Completion is `88` because the page separates persistent character/magic/item roles from transient frame-effect roles, documents the shared PAD dependency, identifies source-owned trigger/spawn/scheduling behavior, records exclusion boundaries for adjacent effect systems, identifies both non-manager InventoryPane and SpellInventoryPane consumers, documents current-package `efx.dat` EPF/PAL variants with header evidence, and classifies every exact `.EPD`/`.PAD` operand as code-literal-only in the audited package. Completion remains capped because the exact binary-referenced EPD/PAD payloads, PAD-vs-PAL format relation, and final trigger labels remain unresolved.
- Confidence is `92` because the 2026-06-16 IDA xrefs and decompilation support the filenames, manager routes, frame-effect spawn path, non-manager consumers, and shared-resource caveat, while DAT parsing proves same-basename current effect assets are grouped in `efx.dat`. The repeated archive/loose/raw scan strengthens the negative exact-operand provenance. Confidence stays below final because the exact `.EPD` / `.PAD` payloads are still absent and the `INTEFX.PAD` structure remains unresolved.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)

## Changes

- 2026-06-17 B003 trigger-helper sync: updated the persistent resource mapping after [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) validated ids `0/1` as character, `2` as item, and `3` as magic, and refined the frame-playback gate to the `g_pConfig +0x28de5e` `Shadow` graphics option byte. Score unchanged because resource payload provenance and PAD/PAL format questions remain open.
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
- 2026-06-14 A003 score refresh: Raised completion/confidence from `78/87` to `85/89` after live IDA MCP xrefs confirmed the manager construction/spawn routes and identified extra `sub_57C2D0` use of `INTEFX.PAD`/`MAGEFX.EPD`; DAT provenance, PAD format, and final trigger naming remain below-gate blockers.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:85` / `CONFIDENCE:89` with DAT provenance still open.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:90`.
  - Evidence: current DAT table parsing found `CHREFX.EPF`, `MAGEFX.EPF`, `ITEMEFX.EPF`, `FRMLEFX.EPF`, `FRMREFX.EPF`, and `INTEFX.PAL` in `efx.dat`, with sizes and offsets recorded above. No exact `.EPD` or `INTEFX.PAD` DAT entries or loose files were found, so those binary operands remain payload blockers. `CANONICAL_OWNER:NONE` remains unchanged per batch owner-preservation guidance.
- 2026-06-14 A002 blocker provenance pass:
  - Before: `COMPLETION:86`, `CONFIDENCE:90`, with exact EPD/PAD operands only known as absent from the first current-package audit.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:91`, after corrected DAT start-offset parsing, case-insensitive exact-name checks, loose-resource search, and raw client scan confirmed `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD` are present only as UTF-16 executable literals in the packaged executables, not as current DAT or loose payloads.
- 2026-06-16 A002 resource-provenance refresh:
  - Before: `COMPLETION:87`, `CONFIDENCE:91`, with non-manager effect consumers described only by raw function names and EPF/PAL variant headers not recorded.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:92`.
  - Evidence: live MCP on `b001_selflookpane_0001H7_20260616` reconfirmed function sizes, xrefs, manager slot offsets, randomized frame-effect scheduling, and identified `sub_4EA130` / `sub_57C2D0` as InventoryPane and SpellInventoryPane constructor consumers. Current-package scanning reconfirmed exact EPF/PAL successor entries and no exact legacy EPD/PAD payloads.
