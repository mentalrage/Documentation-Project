** TARGET-REPORT-UID:00002W **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00002W CollectionEntryControlPane Class Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00002W][CollectionEntryControlPane](../../../by-class/CollectionEntryControlPane.md) owned and emitted by [UID:0000IB][CollectionDialogPane](../../../by-file/CollectionDialogPane.md), raise the target from `85/86` to `88/90`, and populate declaration-level first-draft class C++.
- Final disposition: reconstructable private dialog-control class. The class page should emit a class declaration with `[[CHILDREN]]`; exact method bodies should remain in exact by-memory children or future method splits, not inside the class page.
- Required action after supervisor acceptance: update target/support docs only through an implementation callback; do not edit `by-memory/-coverage-report.md` directly.
- Confidence: high for class layout, constructor args, object size, vtable route, OnDraw data flow, wrapped-text helper signature, and source file routing; medium-high for original field/method spellings because no PDB/source strings prove exact names.
- Report status: FINISHED.

## Target

- Target UID: `00002W`
- Target path: `source-3/project-documentation/by-class/CollectionEntryControlPane.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00002W-CollectionEntryControlPane-class-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000IB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IB`, blank formal C++.
- Current source route: [UID:0000IB][CollectionDialogPane](../../../by-file/CollectionDialogPane.md) to `NexusTK/ui/dialogs/CollectionDialogPane.cpp`.
- Relevant exact memory/container docs:
  - [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
  - [UID:00010Y][0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor](../../../by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md)
  - [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](../../../by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md)
  - [UID:0001TZ][CollectionPlayerDataLayout](../../../by-type/by-struct/CollectionPlayerDataLayout.md)

## Executive Recommendation

`CollectionEntryControlPane` should stay as a private `ControlPane`-derived helper class inside `CollectionDialogPane.cpp` or its companion header. The current generated recovered filename `class_CollectionEntryControlPane.cpp` should be retained only as historical/generated search context; it should not drive a one-class source file split.

The previously open source-quality blockers are now resolvable enough for class declaration C++:

- Constructor signature: `CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds)`.
- Class-specific fields:
  - `m_groupIndex` at `+0x108`.
  - `m_entryIndex` at `+0x109`; value `0xfe` is the signed `-2` empty-slot sentinel.
  - `m_volumeEpfName[128]` at `+0x10a`.
  - `m_volumePaletteName[128]` at `+0x20a`.
  - Object size `0x30c` from allocation sites and scalar deleting destructor array-delete path.
- Private helper signature: `void DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds)`.
- Virtual paint method: source-facing name should be `OnDraw()` unless the project's final `ControlPane` naming standard settles on `OnPaint()`. Existing collection docs and IDA name use `OnDraw`; keep `OnDraw` for now and record the naming caveat.
- Destructor policy: source should declare normal `virtual ~CollectionEntryControlPane();`; ordinary destructor body, scalar deleting destructor, and adjustor thunks are compiler-generated/ABI route artifacts and should not be hand-authored as separate source methods.

Target formal C++ should be populated with a declaration only. Do not put `OnDraw` or `DrawWrappedText` bodies into the class page. If method bodies are later emitted, they should be split or attached as exact by-memory children for the constructor/draw/helper ranges inside [UID:00010X].

## Evidence Checked

### Documentation Evidence

- `by-class/CollectionEntryControlPane.md`: current class purpose, method inventory, data layout, destructor-family notes, unresolved GrafPort helper ownership and source-field naming.
- `by-file/CollectionDialogPane.md`: file grouping, proposed path, private control ownership, resource family, singleton/vtable routing, CollectionPane fold caveat.
- `by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md`: full dialog/private-control island, constructor edges, function table, page-step no-xref caveats.
- `by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md`: ordinary destructor no-direct-route proof and scalar/adjustor route.
- `by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md`: vtable/string resource island including `0x00616590`, `0x006165f8`, `0x00616628`, `CLTVOL`, `CLTENTRY`, and `CLTICON`.
- `by-type/by-struct/CollectionPlayerDataLayout.md`: corrected collection group/entry layout and `g_pCollectionData` ownership as a UserPane/local-player-state view.
- `by-global/g_pCollectionData.md` and `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: broad player-data pointer lifetime and alias caveats.
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` and `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`: shared GrafPort text helper ownership; caller-biased collection ownership is stale.
- Prior B001 reports in executed/research were used as leads only, especially `00010Y-collection-entry-control-pane-destructor-source-quality.md`, `00016B-00016C-00016D-GrafPortTextHelpers-source-quality.md`, and `000250-CollectionReadOnlyData-source-quality.md`.

### Binary / Tool Evidence

- IDA MCP recheck attempted with `tools/list` at `http://127.0.0.1:13337/mcp`; current session result: `Unable to connect to the remote server`.
- Local PE/Capstone disassembly was run against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for:
  - `0x0048d3a0-0x0048d47a` constructor.
  - `0x0048d4a0-0x0048d991` `OnDraw`.
  - `0x0048d9e0-0x0048dc21` wrapped-text helper.
  - `0x0048e177-0x0048e18c` adjustors.
  - `0x0048e2b0-0x0048e305` scalar deleting destructor.
  - constructor callers at `0x0048ca46` and `0x0048ce45`.
  - vtable cells at `0x00616590`, `0x006165f8`, `0x00616628`, and draw slot `0x006165d4`.
  - UTF-16 resource strings at `0x00616764`, `0x00616780`, `0x0061679c`, `0x006167bc`, `0x006167c4`, `0x006167e0`, `0x006167fc`, and `0x00616814`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best source-quality conclusion | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Final source owner | Constructor edges from `CollectionDialogPane` at `0x0048ca46`/`0x0048ce45`, collection-only resources, vtables in collection `.rdata`, file doc route. | Keep `CANONICAL_OWNER:0000IB`, `EMITTER_UIDS:0000IB`; private class in `CollectionDialogPane.cpp` or a paired header. | Reject standalone `class_CollectionEntryControlPane.cpp` as generated pollution; reject `CollectionPane.cpp` fold as an unresolved historical source-layout caveat, not current best route. |
| Constructor signature | Callers push `groupIndex`, `entryIndex`, `bounds` in source order; callee ret `0xc`; callee reads `[ebp+8]`, `[ebp+0xc]`, `[ebp+0x10]`. | `CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds)`. | Reject bounds-first constructor because stack order does not match; reject `int` source fields because the object stores bytes and uses byte sentinel semantics. |
| Group/entry fields | Constructor writes `[this+0x108]` and `[this+0x109]`; OnDraw uses both repeatedly. | `m_groupIndex` at `+0x108`; `m_entryIndex` at `+0x109`. Entry should be signed because `0xfe` is tested as the empty slot and later values are sign-extended. | Reject generic `byte_108/byte_109`, `category/type` without index role, and `bool` fields. |
| Resource buffers | Constructor formats `CLTVOL%d.EPF` into `this+0x10a` and `CLTVOL%d.PAL` into `this+0x20a`, each with count `0x80` wide chars. Scalar destructor array path uses size `0x30c`. | `wchar_t m_volumeEpfName[128]` at `+0x10a`; `wchar_t m_volumePaletteName[128]` at `+0x20a`; object tail padding `+0x30a..+0x30b`. | Reject unnamed scratch/global resource strings; these are per-control cached names, not process-wide constants. |
| OnDraw name | Vtable slot `0x006165d4 -> 0x0048d4a0`; existing IDA/doc name `CollectionEntryControlPane_OnDraw`; behavior is render-only. | Keep `OnDraw()` for now. Note `OnPaint()` remains possible if final `ControlPane` virtual naming standard requires it. | Reject public/free draw helper; vtable proves virtual class method. |
| Wrapped-text helper signature | All nine call sites push text pointer, char count, and rect pointer; callee is `thiscall`, returns `ret 0xc`, reads `[ebp+8]`, `[ebp+0xc]`, `[ebp+0x10]`, uses `this` as GrafPort receiver. | `void DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds)`. Private class helper. | Reject no-argument/raw helper and free GrafPort function: call sites pass `ecx=this` and only collection entry OnDraw calls it. |
| Wrapped-text behavior | Helper gets/restores draw position, sets cursor to rect origin, uses line height, counts chars fitting width, copies up to `0x100` bytes, handles literal backslash-n, aligns based on inherited draw alignment byte at `this+0x8c`, draws with GrafPort text helpers. | Document as class-local line-wrapper that draws at most `charCount` UTF-16 chars inside a rect, respects literal `\\n`, skips a following space after a line, and restores original draw cursor. | Reject "clip only" or "single-line label" description; the loop is true wrapping and multi-line drawing. |
| Collection entry field names | Producer docs prove `+0x18` row name/key, `+0x00` column 2, `+0x30` column 3; OnDraw renders `+0x18` first, then `+0x00`, then `+0x30`; `+0x48` gates collected branch. | Recommended descriptive names: `entryName`/`lookupName` for `+0x18`, `shortName`/`subtitleText` for `+0x00`, `description` for `+0x30`, `collectedFlag`/`unlockedFlag` for `+0x48`. Keep provenance note because exact table column labels are not proven. | Reject stale `groupBase+0x34` entry-base model; reject final public struct names as original-proof. |
| Shared GrafPort helper ownership | GrafPort docs own `0x004b95e0`, `0x004b9620`, `0x004ba8b0`, `0x004ba9a0`, `0x004bab20`, `0x004bab70`; current class target still lists some as caller-biased collection methods. | Move them out of the class method table into dependency notes. Name them as GrafPort/text helpers, especially `GrafPort::GetDrawPosition`, `GrafPort::OffsetDrawPosition`, and `GrafPort::DrawGlyphWithTextColors`. | Reject CollectionEntryControlPane ownership of those helpers. Caller use is not ownership. |
| Destructor/scalar policy | Ordinary destructor body has no direct rel32/VA/RVA route; scalar destructor is primary vtable slot and adjustors route from secondary/tertiary views. | Source class should declare/define normal `~CollectionEntryControlPane()` only; scalar deleting destructor and adjustors are compiler generated; ordinary destructor exact page should stay no-standalone-body unless final method body split is created. | Reject standalone `ScalarDeletingDestructor` C++; reject TextButtonEx, Pane, or GrafPort ownership for this class destructor family. |
| Vtable/adjustor view | Constructor/destructors store `0x00616590`, `0x006165f8`, `0x00616628`; adjustors subtract `0xa0`/`0xa4` then jump scalar. | Treat `+0xa0` and `+0xa4` as inherited secondary/tertiary views from the base hierarchy. Class declaration should stay `public ControlPane` unless ControlPane's final declaration exposes additional base interfaces. | Reject explicit extra base classes on this page without parent-class proof. |
| Final C++ readiness | Target is reconstructable, has valid emitter chain, and current combined score clears the active combined-score/emitter gate. Class-specific source shape is now resolved enough. | Populate declaration-level class C++ with `[[CHILDREN]]`. Do not emit method bodies from the class page. | Reject blank formal block as stale; reject body-level implementation in class doc because exact method bodies belong to by-memory children. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| Class page | [UID:00002W](../../../by-class/CollectionEntryControlPane.md) | Private entry-slot control class declaration and source-shape summary | TRUE | [UID:0000IB](../../../by-file/CollectionDialogPane.md) | `88/90` | Populate declaration-level C++. |
| `0x0048d3a0-0x0048d47a` | covered by [UID:00010X](../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) | Constructor | TRUE | `00002W` semantically, aggregate currently emits via `0000IB` | no split required in this report | Exact source signature resolved. Future exact child split would be useful if method body C++ is desired. |
| `0x0048d480-0x0048d49f` | [UID:00010Y](../../../by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md) | Ordinary destructor body | TRUE, no standalone body | `00002W` | keep `85/90` unless separately revisited | Existing no-direct-route proof remains valid. |
| `0x0048d4a0-0x0048d991` | covered by [UID:00010X](../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) | Virtual `OnDraw` | TRUE | `00002W` semantically | no split required in this report | Behavior/field names resolved enough for class docs. |
| `0x0048d9e0-0x0048dc21` | covered by [UID:00010X](../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) | Private `DrawWrappedText` | TRUE | `00002W` semantically | no split required in this report | Signature and behavior resolved. |
| `0x0048e177-0x0048e18c` | covered by [UID:00010X](../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) | Secondary/tertiary destructor adjustors | compiler-generated | `00002W` ABI route only | no C++ | Document, do not emit handwritten methods. |
| `0x0048e2b0-0x0048e305` | covered by [UID:00010X](../../../by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) | Scalar deleting destructor | compiler-generated wrapper | `00002W` ABI route only | no standalone C++ | Source declaration generates it. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0048ca46` | direct call to `0x0048d3a0` | Dialog constructor allocates `0x30c`, computes six-entry slot rect, pushes `groupIndex`, `entryIndex or 0xfe`, and rect pointer. |
| `0x0048ce45` | direct call to `0x0048d3a0` | Second dialog layout/pass creates the same entry controls. |
| `0x006165d4` | vtable cell to `0x0048d4a0` | `OnDraw` is vtable-routed virtual method, not direct helper. |
| `0x00616590` | primary first vtable slot to `0x0048e2b0` | Scalar deleting destructor route. |
| `0x006165f8` | secondary first vtable slot to `0x0048e177` | Adjustor subtracts `0xa0` before scalar destructor. |
| `0x00616628` | tertiary first vtable slot to `0x0048e182` | Adjustor subtracts `0xa4` before scalar destructor. |
| nine calls in `0x0048d4a0` | direct calls to `0x0048d9e0` | `DrawWrappedText` is private helper only used by this class's draw method. |

## Source Shape And Layout Details To Incorporate

### Constructor

Disassembly of `0x0048d3a0` supports this source shape:

- Calls `ControlPane` constructor with control type `8` and the passed bounds pointer.
- Installs primary/secondary/tertiary vtable views:
  - `this+0x00 = 0x00616590`
  - `this+0xa0 = 0x006165f8`
  - `this+0xa4 = 0x00616628`
- Stores `m_groupIndex` at `this+0x108` and `m_entryIndex` at `this+0x109`.
- Calls inherited enable/init helper `0x005446b0` with `1`.
- Computes `groupIndex * 0x2604`, reads group `volumeId/groupType` byte at `g_pCollectionData + groupIndex * 0x2604 + 0x3ec9`, and formats:
  - `CLTVOL%d.EPF` into `this+0x10a` with count `0x80`.
  - `CLTVOL%d.PAL` into `this+0x20a` with count `0x80`.
- Returns with `ret 0xc`, confirming three source arguments after `this`.

### OnDraw

`0x0048d4a0` should be documented as the virtual entry-slot drawing method:

- Initializes a stack tile/render context through `InitTileContext`/`0x00457a60`.
- Fills a local placeholder text buffer from the UTF-16 repeated `0xff1f` string at `0x0061679c` for unknown/locked display.
- Formats the one-based entry number with `L"%2d"` from `m_entryIndex + 1`.
- Loads/draws the entry frame resources `CLTENTRY.EPF` and `CLTENTRY.PAL`.
- Creates a `0,0,0x5f,0x5f` local rect and checks entry state:
  - If `m_entryIndex == 0xfe` or `m_entryIndex >= totalEntries`, it draws the empty/placeholder `CLTICON` frame path and returns.
  - Otherwise it computes `entryRecord = g_pCollectionData + m_groupIndex * 0x2604 + 0x3ecc + m_entryIndex * 0x4c`.
  - If `entryRecord->collectedFlag` at entry local `+0x48` is zero, it draws `CLTICON.EPF/PAL`, then wrapped placeholder and index text.
  - If `collectedFlag` is nonzero, it loads the per-volume names cached in `m_volumeEpfName`/`m_volumePaletteName`, draws the volume sprite, then draws entry text fields.
- It reads entry strings at:
  - absolute `+0x3ee4 + entry * 0x4c`, logical entry local `+0x18`: row name/key, rendered first.
  - absolute `+0x3ecc + entry * 0x4c`, logical entry local `+0x00`: column-2/short-name text, rendered after the index.
  - absolute `+0x3efc + entry * 0x4c`, logical entry local `+0x30`: description/body, rendered after the lower separator.

### DrawWrappedText

`0x0048d9e0` is source-authored class logic, not compiler glue:

- Source-facing signature: `void CollectionEntryControlPane::DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds)`.
- It uses the class/GrafPort draw state rather than a standalone renderer.
- It returns early if inherited visible/draw-enabled byte `this+0x71` is false.
- It saves the current draw position through `GrafPort::GetDrawPosition`.
- It gets the current line height through `GrafPort::GetLineHeight` and initially moves the draw cursor to `bounds->left, bounds->top`.
- It loops while characters remain and the current y/draw cursor does not exceed `bounds->bottom`.
- It asks the shared text-fit helper for how many UTF-16 characters fit in `bounds->right - bounds->left`.
- It copies the chosen text run to a stack buffer with the shared MemoryMan/memmove wrapper, null-terminates it, and aborts through the security-cookie failure path if the byte count reaches/exceeds `0x100`.
- It treats literal backslash followed by `n` as a forced line break by zeroing the copied run at that point and advancing past the two characters.
- It honors inherited text alignment at `this+0x8c`:
  - default/left: draw x is `bounds->left`;
  - center: measure run width and center between left/right;
  - right: measure run width and align to `bounds->right - width`.
- It draws the run through GrafPort text output and skips one following space after a wrapped run.
- It restores the original draw position before returning.

## Collection Data Layout Names

The target should use source-quality field names without pretending original spellings are proven:

| Location | Recommended source-facing name | Evidence / caveat |
| --- | --- | --- |
| `CollectionGroupRecord +0x01` / absolute `+0x3ec9` | `volumeId` or `groupType` | Constructor formats `CLTVOL%d` from this byte; existing layout docs call it `groupType`. Recommend writing `groupType/volumeId` until table semantics are final. |
| `CollectionGroupRecord +0x02` / absolute `+0x3eca` | `totalEntries` | OnDraw suppresses slots when `m_entryIndex >= totalEntries`; bar/list consumers agree. |
| `CollectionEntryRecord +0x00` | `shortName` or `subtitleText` | Producer stores `Collections` column 2; OnDraw renders it as secondary item text. Exact table column label remains unproven. |
| `CollectionEntryRecord +0x18` | `entryName` / `lookupName` | Producer copies row name/key here and OnDraw renders it first in the collected branch. |
| `CollectionEntryRecord +0x30` | `description` | Producer stores `Collections` column 3; OnDraw renders it as lower body text. |
| `CollectionEntryRecord +0x48` | `collectedFlag` / `unlockedFlag` | Dialog packet bit writes this byte; OnDraw uses nonzero to choose collected/detail rendering and zero for locked/placeholder rendering. |

The type page [UID:0001TZ] should preserve `g_pCollectionData` as a broad UserPane/local-player-state pointer. These collection names are feature-view names, not proof of a standalone allocation or public `CollectionGroupRecord` in original headers.

## Destructor And Compiler-Generated Policy

Keep the source-facing class destructor in the class declaration, but do not emit standalone C++ for:

- `0x0048e177`: secondary adjustor thunk, `this -= 0xa0; jmp 0x0048e2b0`.
- `0x0048e182`: tertiary adjustor thunk, `this -= 0xa4; jmp 0x0048e2b0`.
- `0x0048e2b0`: MSVC scalar deleting destructor wrapper. It restores the three vtable views, calls `Pane` teardown `0x00544580`, optionally frees with `0x004f4ac0`, and has an array/vector-delete sized path using `0x30c`.
- `0x0048d480`: ordinary non-deleting destructor body has no direct static inbound route in current docs and should not be emitted as a separate raw helper. It is the body implied by a normal source destructor.

Source-level C++ should look like a normal destructor declaration/definition. The compiler should regenerate scalar wrappers and adjustor thunks from the class hierarchy and vtables.

## Shared GrafPort Helper Ownership

The target page should remove shared GrafPort helpers from the class method table and list them as dependencies:

- `0x004b95e0`: [UID:000162] `GrafPort::GetDrawPosition` style helper.
- `0x004b9600`: draw cursor move/set helper used by `DrawWrappedText`.
- `0x004b9620`: [UID:000162] `GrafPort::OffsetDrawPosition` style helper.
- `0x004ba8b0`: shared text-fit/count helper, owned by GrafPort/text utilities.
- `0x004ba9a0`: shared `GrafPort::GetTextWidth`/measure helper.
- `0x004bab20`: [UID:00016C] `GrafPort::DrawGlyphWithTextColors`, not a CollectionEntryControlPane method.
- `0x004bab70`: shared wide-text draw helper.

Consumer frequency from `CollectionEntryControlPane` is useful, but it is not ownership evidence. The final class C++ may call these helpers through inherited `GrafPort`/`ControlPane` facilities without moving their source ownership into `CollectionDialogPane.cpp`.

## Ranked Ownership Analysis

### 1. [UID:0000IB] CollectionDialogPane

- Evidence for:
  - Direct constructor allocation/calls from dialog constructor at `0x0048ca46` and `0x0048ce45`.
  - The class draws only collection-detail resources: `CLTENTRY`, `CLTICON`, `CLTVOL`.
  - Vtables/resource strings sit in the collection dialog `.rdata` island [UID:000250].
  - File doc already groups `CollectionDialogPane`, `CollectionEntryControlPane`, `CollectionBarControlPane`, singleton, and read-only data.
  - The private control consumes dialog-populated packet state bits from the same `g_pCollectionData` view.
- Evidence against:
  - The broader collection feature also has [UID:0000IC][CollectionPane], and original source might have folded dialog code into a larger collection feature file.
- Decision:
  - Best current owner and emitter. Keep `0000IB`. Preserve the fold caveat as a source-layout caveat only, not a blocker.

### 2. [UID:0000IC] CollectionPane

- Evidence for:
  - Broader feature owns metadata loading, the summary pane, and collection-detail open routes.
  - Final original project might have grouped the feature under one collection source unit.
- Evidence against:
  - Direct class allocation, singleton lifecycle, private controls, and collection-detail resources are documented in the compact dialog/control island.
  - Existing file route already has a valid generated path and no current evidence proves a fold.
- Decision:
  - Reject as current direct owner. Keep as companion file/future placement caveat.

### 3. GrafPort / Text Helpers

- Evidence for:
  - `OnDraw` and `DrawWrappedText` call many GrafPort helpers.
- Evidence against:
  - Helper bodies are shared across UI classes and already documented under GrafPort/text helper owners.
  - The class-specific state and vtable route remain collection-private.
- Decision:
  - Reject as class owner. Keep helper references as dependencies only.

### 4. UserPane / g_pCollectionData

- Evidence for:
  - The draw path consumes `g_pCollectionData`, whose backing lifetime belongs to UserPane/local player state.
- Evidence against:
  - Data consumer is not class source owner. UserPane owns data layout/storage, not this UI control class.
- Decision:
  - Reject as direct class owner. Keep cross-reference for layout/source type ownership.

### 5. TextButtonEx / Pane / ControlPane

- Evidence for:
  - Base class cleanup and inherited drawing state are used.
- Evidence against:
  - Vtables and constructor/draw behavior are CollectionEntry-specific; TextButtonEx has separate destructor ranges.
- Decision:
  - Reject. Base classes provide inherited implementation only.

## First-Draft C++ Recommendation

Populate the class page formal block with declaration-level C++ only:

```cpp
class CollectionEntryControlPane : public ControlPane
{
public:
    CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds);
    virtual ~CollectionEntryControlPane();

protected:
    virtual void OnDraw();

private:
    void DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds);

    unsigned char m_groupIndex;       // +0x108
    signed char m_entryIndex;         // +0x109, -2 marks an empty/unused slot
    wchar_t m_volumeEpfName[128];     // +0x10a, formatted as CLTVOL%d.EPF
    wchar_t m_volumePaletteName[128]; // +0x20a, formatted as CLTVOL%d.PAL
};

[[CHILDREN]]
```

Why declaration-only is the correct scope:

- Rule 24 says class files should generally emit class-level code, not method-body specifics.
- The class page now has enough evidence for layout and declaration.
- Exact method bodies for constructor/OnDraw/DrawWrappedText are currently inside aggregate [UID:00010X], not separate child pages. Emitting their bodies from the class page would mix class-level declaration with exact address-body coverage.
- The ordinary destructor exact page [UID:00010Y] intentionally remains no-standalone-body because source should define only the normal destructor and let the compiler regenerate scalar/delete wrappers.

## Recommended Target / Support Doc Changes

### Target: `by-class/CollectionEntryControlPane.md`

1. Change metadata:
   - `COMPLETION:85 -> 88`
   - `CONFIDENCE:86 -> 90`
   - Keep `CANONICAL_OWNER:0000IB`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000IB`
2. Populate the formal C++ block with the declaration in the `First-Draft C++ Recommendation` section.
3. Replace status text that says confidence is only medium for shared GrafPort helper placement/final fields:
   - State that GrafPort helper ownership is resolved as shared GrafPort/text utilities, not class-owned methods.
   - State that class-local fields are resolved to `m_groupIndex`, `m_entryIndex`, `m_volumeEpfName[128]`, and `m_volumePaletteName[128]`; collection-entry data field names remain descriptive/proven-by-provenance rather than original-proof.
4. Update method table:
   - Constructor row: include signature `(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds)`, object size `0x30c`, vtable installs, `m_groupIndex`, `m_entryIndex`, and the two cached volume-name buffers.
   - OnDraw row: include vtable slot `0x006165d4`, placeholder/empty/locked/collected branches, `m_entryIndex == 0xfe` sentinel, `totalEntries` check, `entry +0x48` state check, resource names, and entry fields rendered.
   - DrawWrappedText row: include signature and line-wrapping behavior.
   - Destructor rows: preserve no-body/scalar-wrapper policy.
   - Remove `GetDrawPosition`, `OffsetDrawPosition`, and `DrawCharWithColors` from method table; move them to a dependency/helper section with GrafPort ownership.
5. Add a class layout table:
   - inherited `ControlPane` through `+0x107`;
   - `+0x108` `m_groupIndex`;
   - `+0x109` `m_entryIndex`;
   - `+0x10a` `m_volumeEpfName[128]`;
   - `+0x20a` `m_volumePaletteName[128]`;
   - `+0x30a..+0x30b` tail padding;
   - object size `0x30c`.
6. Add a source-quality/rejected-alternatives section:
   - reject standalone generated class file;
   - reject `CollectionPane.cpp` as current direct owner while preserving fold caveat;
   - reject GrafPort/Text helper ownership;
   - reject UserPane/data owner as UI class owner;
   - reject TextButtonEx/Pane ownership for destructor family;
   - reject handwritten scalar deleting destructor/adjustors.
7. Add a score rationale explaining `88/90`: the class declaration, source route, fields, helper signature, vtable route, constructor callers, and dependencies are now resolved; score remains below final-audit level because exact original spellings for `OnDraw` vs `OnPaint`, entry string column names, and broader player-data type names are still not PDB/source-proven.

### Support: `by-file/CollectionDialogPane.md`

1. Update the `CollectionEntryControlPane` proposed-contents row:
   - source-private detail slot control;
   - constructor signature and object size `0x30c`;
   - fields/buffers at `+0x108/+0x109/+0x10a/+0x20a`;
   - virtual `OnDraw` and private `DrawWrappedText`;
   - shared GrafPort helpers are dependencies, not contents of this file.
2. Keep proposed source path `NexusTK/ui/dialogs/CollectionDialogPane.cpp`.
3. Preserve the `CollectionPane.cpp` fold caveat, but say it is not strong enough to change direct ownership.
4. No required metadata score change. Optional: raise to `87/89` only if the implementation also expands the file page with this report's full source-shape evidence.

### Support: `by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md`

1. Update covered function rows for:
   - `0x0048d3a0-0x0048d47a`: constructor signature, fields, buffers, object size.
   - `0x0048d4a0-0x0048d991`: `OnDraw`, vtable slot, branch behavior, entry record fields.
   - `0x0048d9e0-0x0048dc21`: private `DrawWrappedText(const wchar_t *, int, const RectBounds *)`.
   - `0x0048e177-0x0048e18c` and `0x0048e2b0-0x0048e305`: compiler-generated adjustor/scalar policy.
2. Add that aggregate formal C++ should remain blank for now because it is a mixed island with dialog, entry, bar, singleton, page-step, and compiler thunks. The class page can emit declaration-level C++; method bodies should wait for exact child splits or an accepted aggregate-body plan.
3. Recommended metadata if fully updated: `COMPLETION:86`, `CONFIDENCE:90`. The aggregate remains below final-source level because page-step reachability and broad mixed-island body emission are still unresolved.

### Support: `by-type/by-struct/CollectionPlayerDataLayout.md`

1. Keep canonical owner/emitter as UserPane/local-player state.
2. Add a "consumer naming from CollectionEntryControlPane" note:
   - `+0x18`: `entryName`/`lookupName`, rendered first.
   - `+0x00`: `shortName`/`subtitleText`, rendered as secondary text.
   - `+0x30`: `description`, rendered as lower body.
   - `+0x48`: `collectedFlag`/`unlockedFlag`, controls locked versus collected rendering.
3. Preserve the caveat that exact original table-column labels and broader player-data type names remain open.
4. No required score change; optional `87/89` only if final semantic names are adopted throughout the related collection docs.

### Support: `by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md`

1. Ensure the entry-control vtable row names identify:
   - primary vtable `0x00616590` with scalar deleting destructor and `OnDraw` slot at `0x006165d4`;
   - secondary adjustor table `0x006165f8`;
   - tertiary adjustor table `0x00616628`.
2. Ensure resource strings include:
   - `0x00616764` `CLTVOL%d.EPF`;
   - `0x00616780` `CLTVOL%d.PAL`;
   - `0x0061679c` unknown/placeholder repeated `0xff1f` string;
   - `0x006167bc` `%2d`;
   - `0x006167c4` `CLTENTRY.EPF`;
   - `0x006167e0` `CLTENTRY.PAL`;
   - `0x006167fc` `CLTICON.EPF`;
   - `0x00616814` `CLTICON.PAL`.
3. No required score change; B001's `000250` report already recommended its own score/C++ action.

### Support: `by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md`

No required change if current B001 implementation is present. It already records the ordinary no-direct-route proof, scalar deleting destructor route, adjustors, vtable restores, and TextButtonEx rejection. If touched, add only a cross-reference that the class page now emits the normal destructor declaration while this page remains no-standalone-body.

## Exact Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` during B-agent implementation unless the supervisor explicitly lifts the ban.

### `by-class/-coverage-report.md` replacement row

Replace the current [UID:00002W] row with:

```text
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md) : reconstructable : 88% : very-strong : B010 source-quality pass resolves the private CollectionDialogPane entry-slot class shape: constructor args `groupIndex, entryIndex, bounds`, `m_groupIndex +0x108`, signed `m_entryIndex +0x109` with `0xfe` empty-slot sentinel, cached `CLTVOL%d` buffers at `+0x10a/+0x20a`, object size `0x30c`, virtual `OnDraw` slot `0x006165d4`, private `DrawWrappedText(const wchar_t *, int, const RectBounds *)`, corrected entry-record reads at `+0x18/+0x00/+0x30/+0x48`, destructor/scalar/adjustor compiler policy, and GrafPort helper ownership as shared dependency; declaration-level C++ with `[[CHILDREN]]` is ready.
```

### `by-memory/-coverage-report.md` replacement row, only if [UID:00010X] support metadata/wording is updated

Replace the current [UID:00010X] row with:

```text
    - [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) : reconstructable : 86% : very-strong : Collection dialog/private-control island with current function starts, constructor edges, singleton/vtable refs, resource ownership, page-step caveats, live IDA-confirmed CollectionEntryControlPane destructor/scalar/adjustor relationship, and B010 source-quality resolution for the entry-control constructor args, fields, object size, OnDraw data offsets, wrapped-text helper signature, and GrafPort dependency ownership.
```

No [UID:00010Y] coverage replacement is required; the existing destructor row remains accurate unless that exact page is changed.

## Validation Commands Expected After Implementation

Run from `source-3/project-documentation` after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00002W-CollectionEntryControlPane-class-source-quality-removed.md](00002W-CollectionEntryControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the last two if those support docs are actually edited. Also validate `by-memory\0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md` if touched.

Report expected side effects:

- Validator may update auto-generated coverage/completion reports.
- Note whether `project-level/-auto-completion-stats.md`, `tools/validator.ini`, or generated files changed.
- Keep `by-memory/-coverage-report.md` supervisor-owned and use the exact row text above if needed.

No validators were run for this report-only pass because no by-* documentation was edited.

## IDA Rename / Type / Comment Recommendations

These are recommendations only; do not apply IDA-side changes from this report.

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x0048d3a0` | `CollectionEntryControlPane::CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds)` | High |
| `0x0048d4a0` | `CollectionEntryControlPane::OnDraw()` | High for class method, medium-high for exact `OnDraw` vs `OnPaint` spelling |
| `0x0048d9e0` | `CollectionEntryControlPane::DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds)` | High |
| `0x0048d480` | `CollectionEntryControlPane::~CollectionEntryControlPane()` ordinary/non-deleting body, no direct static route | High |
| `0x0048e177` | `CollectionEntryControlPane` secondary destructor adjustor thunk, `this -= 0xa0` | High |
| `0x0048e182` | `CollectionEntryControlPane` tertiary destructor adjustor thunk, `this -= 0xa4` | High |
| `0x0048e2b0` | `CollectionEntryControlPane` scalar deleting destructor wrapper, compiler generated | High |
| `this+0x108` | `m_groupIndex` | High |
| `this+0x109` | `m_entryIndex` | High |
| `this+0x10a` | `m_volumeEpfName[128]` | High |
| `this+0x20a` | `m_volumePaletteName[128]` | High |
| entry record `+0x18` | `entryName`/`lookupName` | Medium-high, descriptive |
| entry record `+0x00` | `shortName`/`subtitleText` | Medium, descriptive |
| entry record `+0x30` | `description` | Medium-high, descriptive |
| entry record `+0x48` | `collectedFlag`/`unlockedFlag` | High for role, medium-high for final name |

## Open Questions Closed Or Left With Impact

- Shared GrafPort helper ownership: closed. They are shared GrafPort/text helpers, not class methods. Impact: target score can rise and formal class C++ can omit them.
- Class-local field names: closed at descriptive/source-quality level. Original spellings remain unproven, but `m_groupIndex`, `m_entryIndex`, `m_volumeEpfName`, and `m_volumePaletteName` are directly supported by offsets and behavior. Impact: no longer blocks class declaration.
- Wrapped-text helper signature: closed. Three arguments plus `this`, `ret 0xc`, and nine call sites prove the signature shape. Impact: no longer blocks class declaration.
- OnDraw vs OnPaint spelling: not fully original-proof. Existing docs and current IDA name use `OnDraw`; final base-class naming may later standardize to `OnPaint`. Impact: keep confidence below final-audit level, but do not block declaration.
- Collection entry string semantic names: partly closed with high-probability descriptive names and provenance. Exact `Collections` table column labels are still not proven. Impact: update docs with `entryName/lookupName`, `shortName/subtitleText`, `description`, and `collectedFlag/unlockedFlag` caveats; keep [UID:0001TZ] below final-audit scores.
- Original source file fold into `CollectionPane.cpp`: not proven. Direct current owner remains [UID:0000IB]. Impact: preserve caveat in file doc; do not change owner/emitter.
- Method-body C++: target class declaration is ready, but body emission should wait for exact by-memory children/splits or a separate accepted aggregate plan. Impact: class page emits declaration only.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/00002W-CollectionEntryControlPane-class-source-quality.md`
- Modified: none outside Agent-B010 research.
- by-* docs edited: none.
- `by-memory/-coverage-report.md` edited: no.
- Validators run: none for report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00002W-CollectionEntryControlPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00002W"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00002W-CollectionEntryControlPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00002W-CollectionEntryControlPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00002W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
