** TARGET-REPORT-UID:00015O **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:00015O] FramePartPane

Target: `source-3/project-documentation/by-memory/0x004b73b0-0x004b7661.FramePartPane.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/00015O-FramePartPane-source-quality.md`  
Report scope: B-agent source-quality / heuristic research only. No target/support by-* docs or `by-memory/-coverage-report.md` were edited.

## Recommendation Summary

`FramePartPane` is ready for a first-draft source C++ reconstruction in the target by-memory page.

Recommended target metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00005I
EMITTER_UIDS: [00005I]
```

Owner/emitter should remain class-owned by [UID:00005I] `FramePartPane`. The class route emits through `FrameChrome.cpp`, so the implementation should not be moved to `Pane`, `BackPane`, `ResourceLayoutTable`, `BlackHole`, or a standalone helper page. The current blank C++ is a stale-gate issue, not a source-quality blocker under the active gate: `RECONSTRUCTABLE: TRUE`, valid emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`.

The formal C++ should emit source-authored methods only:

- `FramePartPane::FramePartPane(...)`
- `FramePartPane::~FramePartPane()`
- `FramePartPane::OnNotification(...)`
- `FramePartPane::OnPaintFrame()` or the local paint virtual spelling used by `Pane`

It should not handwrite the secondary/tertiary adjustor thunks or the scalar deleting destructor as source methods. Those are ABI/compiler products of the class declaration and destructor.

## Evidence Checked

Supervisor / process evidence checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and related documentation checked:

- `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`
- `by-class/FramePartPane.md`
- `by-file/FrameChrome.md`
- `by-global/FrameChromeSlots.md`
- `by-type/by-vtable/FramePartPaneVtables.md`
- `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`
- `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`
- `by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md`
- `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`
- `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`
- `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md`
- `by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-file/Pane.md`
- `by-class/Pane.md`
- `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/NexusTK/ui/core/FrameChrome.cpp`

Local IDA export JSON checked:

- `ida-export/0x004b73b0.json`
- `ida-export/0x004b7410.json`
- `ida-export/0x004b7480.json`
- `ida-export/0x004b7520.json`
- `ida-export/0x004b75b0.json`
- `ida-export/0x004b7590.json`
- `ida-export/0x004b759b.json`
- `ida-export/0x004b7120.json`

Live IDA MCP status:

- Attempted MCP JSON-RPC `tools/list` at `http://127.0.0.1:13337/mcp`.
- Result: connection failed, so live IDA MCP was unavailable in this session.
- This report relies on local IDA export JSON plus existing by-* documentation. That is sufficient for a first-draft source-quality recommendation, but it should cap confidence below final audit.

Conversion evidence:

- Verified with `int_convert.py`: `0x51` = 81.
- Verified with `int_convert.py`: `0x70` = 112.
- Verified with `int_convert.py`: `0x95` = 149.
- Verified with `int_convert.py`: `0xb1` = 177.
- Verified with `int_convert.py`: `0xb` = 11.
- Verified with `int_convert.py`: `0xa0` = 160.
- Verified with `int_convert.py`: `0xa4` = 164.
- Verified with `int_convert.py`: `0xf8` = 248.
- Verified with `int_convert.py`: `0xfc` = 252.
- Verified with `int_convert.py`: `0x44` = 68.
- Verified with `int_convert.py`: `0x28` = 40.
- Verified with `int_convert.py`: `0x88` = 136.
- Verified with `int_convert.py`: `0x1ff` = 511.
- Verified with `int_convert.py`: `0x83` = 131.
- Verified with `int_convert.py`: `0xd` = 13.
- Verified with `int_convert.py`: `0x676f6f67` = 1735356263, ASCII `goog`.

Prior-agent research check:

- Searched the active Agent research/notes area for this UID and symbol. I did not find an existing B-agent source-quality report for `00015O`; related A-agent notes and existing by-* docs were used as supporting evidence, not as an implementation callback.

## Source-Quality Inventory

The target range `0x004b73b0-0x004b7661` is a mixed class-method/compiler-wrapper aggregate. The existing child boundaries are correct enough for source reconstruction.

| Range | Size | Binary role | Source-facing role | Source emit? |
|---|---:|---|---|---|
| `0x004b73b0-0x004b7401` | `0x51` / 81 | virtual notification handler | `FramePartPane::OnNotification(...)` | Yes |
| `0x004b7410-0x004b7480` | `0x70` / 112 | virtual paint handler | `FramePartPane::OnPaintFrame()` or local paint virtual name | Yes |
| `0x004b7480-0x004b7515` | `0x95` / 149 | constructor | `FramePartPane::FramePartPane(int partIndex, const Rect& bounds)` | Yes |
| `0x004b7520-0x004b7590` | `0x70` / 112 | ordinary destructor body | `FramePartPane::~FramePartPane()` | Yes |
| `0x004b7590-0x004b759b` | `0xb` / 11 | secondary-base adjustor thunk | compiler-generated destructor adjustor, subtracts `0xa0` / 160 | No |
| `0x004b759b-0x004b75a6` | `0xb` / 11 | tertiary-base adjustor thunk | compiler-generated destructor adjustor, subtracts `0xa4` / 164 | No |
| `0x004b75b0-0x004b7661` | `0xb1` / 177 | scalar deleting destructor wrapper | compiler-generated scalar deleting destructor for `~FramePartPane` | No direct handwritten wrapper |

The ordinary destructor and scalar deleting destructor intentionally duplicate unregister/remove/base cleanup behavior. The source C++ should contain one destructor body; the compiler supplies the scalar deleting wrapper and adjustor thunks from the class declaration and multiple-base layout.

## Split Needs

No new by-memory split is required before a first-draft C++ insertion for UID `00015O`.

Current split model:

- UID `00015O`: class method aggregate plus compiler wrappers.
- UID `00015P`: adjustor thunk detail page, `RECONSTRUCTABLE: FALSE`, correct as a non-source child.
- UID `00022F`: file-level builder/factory, separate from the class method body.
- UID `00015N`: file-level raw slot cleanup, separate from the class method body.
- UID `0001PF`: five global slots, separate data page.
- UID `0003I3`: vtable data, separate non-handwritten compiler/data page.

The only split caveat is explanatory: the target target C++ should make clear that adjustor thunks and scalar deleting destructor behavior are represented by the class destructor and vtable layout, not by handwritten functions.

## Constructor Behavior

Local JSON for `0x004b7480` confirms:

- Calls `Pane::Pane(1)` via `sub_544460(this, 1)`.
- Writes the primary and secondary vtable pointers at offsets:
  - `+0x00`
  - `+0xa0` / 160
  - `+0xa4` / 164
- Stores the constructor part index argument at `this + 0xf8` / 248.
- Calls the pane attach/bounds helper through `sub_544c70(this, rect, 0, 0, dword_69b364)`.
- Registers a `goog` listener through `sub_4f4b30(dword_67a740, this, 0x676f6f67, 0)`.
- Has five constructor call sites from `BuildFramePartPanes` at:
  - `0x004b718c`
  - `0x004b71e2`
  - `0x004b723b`
  - `0x004b7294`
  - `0x004b72f0`

Source-facing constructor direction:

```cpp
FramePartPane::FramePartPane(int partIndex, const Rect& bounds)
    : Pane(1),
      m_partIndex(partIndex)
{
    AddToLayer(bounds, 0, 0, g_pMainLayer);
    RegisterChangeListener(g_pBackPane, this, kFramePartNotificationTag, 0);
}
```

The exact final names for `Rect`, `g_pMainLayer`, and the register-listener wrapper depend on the existing Pane/ChangeMan naming pass. The behavior is clear enough for first-draft source.

## Destructor Behavior

Local JSON for `0x004b7520` and `0x004b75b0` confirms:

- Restores the same three `FramePartPane` vtable pointers at `+0x00`, `+0xa0` / 160, and `+0xa4` / 164.
- Unregisters the `goog` listener through `sub_4f4b50(dword_67a740, this, 0x676f6f67, 0)`.
- Removes the pane from its layer through `Pane::RemoveFromLayer` / `sub_544ce0(this)`.
- Runs base cleanup through `Pane::~Pane` / `sub_544580(this)`.
- The scalar deleting destructor calls the same cleanup and only invokes the delete helper when `(flags & 1) != 0 && (flags & 4) == 0`.

Source-facing destructor direction:

```cpp
FramePartPane::~FramePartPane()
{
    UnregisterChangeListener(g_pBackPane, this, kFramePartNotificationTag, 0);
    RemoveFromLayer();
}
```

The base `Pane` destructor is implicit source behavior and should not be called manually in the final C++.

## Paint Behavior

Local JSON for `0x004b7410` confirms:

- Initializes a `0x28` / 40 byte `EPFTileContext` through `sub_457a60`.
- Reads the part index from `this + 0xf8` / 248. The decompiler prints `this[124]` because it typed `this` as `__int16*`; the constructor proves this is a dword field at byte offset `0xf8`.
- Selects resource name by `byte_66da97`:
  - true: `FRMPART.EPF` at `0x00610f60`
  - false: `FRMPART.EPD` at `0x00610f8c`
- Looks up the layout entry through `sub_4d02f0(dword_67a744, resourceName, m_partIndex, &tileContext)`.
- Calls the primary tile/frame blit callback at `dword_69b3e8`, passing the initialized context, a stack scratch object, and the inherited rect/bounds pointer at `this + 0x44` / 68.

Source-facing paint direction:

```cpp
int FramePartPane::OnPaintFrame()
{
    EPFTileContext tile;
    tile.Init();

    const wchar_t* resourceName = g_useEpfAssets ? L"FRMPART.EPF" : L"FRMPART.EPD";
    g_pEPFLib->LookupLayoutEntry(resourceName, m_partIndex, &tile);

    return RenderTileFrame(&tile, GetPaintBounds(), 0, 0, 0);
}
```

`RenderTileFrame`, `GetPaintBounds`, and the exact return type remain validator/name-alignment details. The behavior should not block first-draft C++.

## Notification Behavior

Local JSON for `0x004b73b0` confirms:

- The binary signature is decompiler-shaped as `void __thiscall(void* this, int, int)`.
- It checks a tag at `a3 + 4` against `0x676f6f67` / 1735356263, ASCII `goog`.
- On a match, it calls `sub_469180(dword_67a74c, this)`, documented as `BlackHole::QueuePaneForDeferredDeletion(Pane*)`.
- It clears five contiguous `FramePartPane` global slots:
  - `dword_69b33c`
  - `dword_69b340`
  - `dword_69b344`
  - `dword_69b348`
  - `dword_69b34c`

Best source-facing direction:

```cpp
void FramePartPane::OnNotification(const ChangeMessage& message)
{
    if (message.tag != kFramePartNotificationTag)
        return;

    g_pBlackHole->QueuePaneForDeferredDeletion(this);

    for (FramePartPane*& pane : g_framePartPanes)
        pane = nullptr;
}
```

The exact message type and tag field name remain open. A source-quality doc should avoid locking this to a decompiler `a3 + 4` spelling.

## Builder / Slot Family Relationship

`BuildFramePartPanes` at `0x004b7120-0x004b731f` constructs exactly five `FramePartPane` instances. It allocates `0xfc` / 252 bytes for each object and passes the constructor these part indexes and bounds:

| Slot address | Part index | Constructor rect | Placement offset |
|---|---:|---|---|
| `0x0069b33c` | 4 | `(0, 0, 198, 6)` | `(118, 12)` |
| `0x0069b340` | 0 | `(0, 0, 56, 93)` | `(14, 12)` |
| `0x0069b344` | 1 | `(0, 0, 57, 93)` | `(365, 12)` |
| `0x0069b348` | 2 | `(0, 0, 77, 37)` | `(14, 335)` |
| `0x0069b34c` | 3 | `(0, 0, 79, 39)` | `(343, 333)` |

The source-facing best guess is an array-like slot family, not five unrelated names:

```cpp
static FramePartPane* g_framePartPanes[5];
```

The binary writes individual globals, but contiguous addresses, factory order, cleanup order, and `OnNotification` bulk clear all support an original array or array-equivalent source structure. The report should retain raw slot addresses and indexes because the final names are still not proven.

The unresolved direct-caller issue for `BuildFramePartPanes` does not block method reconstruction for `FramePartPane`. It should cap confidence below final audit because it affects lifecycle placement and final file-level routing confidence.

## FrameChrome / Source-File Routing

Keep:

- `CANONICAL_OWNER: 00005I`
- `EMITTER_UIDS: [00005I]`
- class route: `FramePartPane`
- file route: `NexusTK/ui/core/FrameChrome.cpp`

Evidence:

- `by-class/FramePartPane.md` already assigns the class to `FrameChrome`.
- `by-file/FrameChrome.md` includes `FramePartPane`, `BuildFramePartPanes`, slot cleanup, frame-slot globals, and `FRMPART` resource strings.
- `auto-generated/-ag-class-coverage.md` routes UID `00005I` to `auto-generated/NexusTK/ui/core/FrameChrome.cpp`.
- `auto-generated/-ag-memory-coverage.md` routes UID `00015O` through owner/emitter UID `00005I`.
- `auto-generated/NexusTK/ui/core/FrameChrome.cpp` currently contains only empty generated markers for `00005I`, `00015O`, `0002NH`, `0003I3`, `00022F`, `00015N`, and `0001PF`.

Do not change this target to file-owned by `FrameChrome`. For source C++, class method ownership is the narrowest true owner. `FrameChrome` is the source-file/module owner, not the canonical method owner.

## Helper / Resource Name Recommendations

Recommended source-facing names for the target and support docs:

| Raw symbol / address | Recommended source-facing name | Confidence |
|---|---|---|
| `byte_66da97` | `g_useEpfAssets` | High |
| `dword_67a744` | `g_pEPFLib` / resource layout table singleton | High |
| `0x00610f60` | `L"FRMPART.EPF"` | High |
| `0x00610f8c` | `L"FRMPART.EPD"` | High |
| `sub_457a60` | `EPFTileContext::Init` / default constructor | High |
| `sub_4d02f0` | `ResourceLayoutTable::LookupLayoutEntry` | High |
| `dword_69b3e8` | primary tile/frame blit callback, provisional `RenderTileFrame` | Medium-high |
| `sub_544460` | `Pane::Pane` | High |
| `sub_544c70` | `Pane::AddToLayer` / bounds attach helper | Medium-high |
| `sub_544ce0` | `Pane::RemoveFromLayer` | High |
| `sub_544580` | `Pane::~Pane` / base cleanup | High |
| `sub_4f4b30` | register change listener wrapper | High behavior, medium exact owner name |
| `sub_4f4b50` | unregister change listener wrapper | High behavior, medium exact owner name |
| `sub_469180` | `BlackHole::QueuePaneForDeferredDeletion` | High |
| `sub_4f4ac0` | delete helper / `operator delete` path | High |
| `dword_67a740` | `g_pBackPane` | High |
| `dword_67a74c` | BlackHole/deferred pane deletion singleton | Medium-high exact global name |
| `dword_69b33c`..`dword_69b34c` | `g_framePartPanes[5]` or equivalent slot array | Medium-high |
| `0x676f6f67` | `kFramePartNotificationTag` / raw tag `goog` | Medium exact semantic name |

Palette note:

- The broader `FrameChrome` resource string page includes `FRMPART.PAL`, `TABS.PAL`, and `NPAL5.PAL`, but UID `00015O` directly uses only `FRMPART.EPF` and `FRMPART.EPD`.
- Do not inject palette setup into `FramePartPane` source unless a later implementation callback includes the builder/file-level resource setup.

## Owner / Emitter Decisions

Recommended owner/emitter decisions:

- Direct owner: `FramePartPane` class, UID `00005I`.
- Direct emitter: `FramePartPane` class, UID `00005I`.
- Generated source file: `NexusTK/ui/core/FrameChrome.cpp`.
- Support-only dependencies:
  - `Pane`
  - `BackPane`
  - `ChangeMan` / listener wrapper
  - `BlackHole`
  - `ResourceLayoutTable`
  - `EPFTileContext`
  - shared surface/render callback table

Rationale:

- The target is a class method/destructor aggregate, not a free file-level helper.
- Vtable refs point to `FramePartPane` method slots.
- Constructor refs come from the file-level `BuildFramePartPanes` builder, but constructor ownership stays with the class.
- Destructor adjustor thunks prove multiple-base class layout, not separate source routines.

## Compiler-Generated / Raw Name Decisions

Compiler-generated names to avoid in source C++:

- `sub_4b7590`
- `sub_4b759b`
- scalar deleting destructor wrapper spelling
- manual vtable writes
- manual base-destructor calls
- raw `this + 0xa0` / `this + 0xa4` adjustor expressions

Raw names that should be retained only as evidence:

- `sub_4b73b0`
- `sub_4b7410`
- `sub_4b7480`
- `sub_4b7520`
- `sub_4b75b0`
- `byte_66da97`
- `dword_69b33c`..`dword_69b34c`
- `dword_69b3e8`

Source-facing fields:

- `m_partIndex` at `+0xf8` / 248 should be added to the class layout discussion.
- The paint rect pointer at `this + 0x44` / 68 is inherited pane state, not a new `FramePartPane` field.

## Heuristic Issue Resolution

Current issue: target score is 84/90 with blank C++.

- Best-guess resolution: raise to 87/91 and populate source-authored C++. The stale 95/95 wording should be removed.

Current issue: exact source file is not fully proven.

- Best-guess resolution: keep `FrameChrome.cpp`. Existing module, class, slots, builder, cleanup, resource strings, and generated route all agree. Alternative `FramePartPane.cpp` is weaker and should not be used without broader source-tree evidence.

Current issue: no direct callers for `BuildFramePartPanes`.

- Best-guess resolution: not a blocker for UID `00015O`; it only caps lifecycle confidence. The constructor has five direct call sites from the builder, and all class method behavior is locally bounded.

Current issue: exact notification signature is not proven.

- Best-guess resolution: document as a ChangeMan/message notification method, not as raw `(int, int)`. The tag field at `message + 4` is proven, but final source field names require ChangeMan API alignment.

Current issue: exact paint virtual name/return type is not proven.

- Best-guess resolution: use `int FramePartPane::OnPaintFrame()` until the Pane vtable naming pass chooses a local spelling. Returning the blit callback result matches the binary.

Current issue: slot globals may be individual statics or an array.

- Best-guess resolution: document raw addresses and recommend source-facing `g_framePartPanes[5]`. The contiguous layout and uniform builder/cleanup/notification behavior strongly support an array-like source construct.

Current issue: register/unregister helper owner name.

- Best-guess resolution: use behavior-first names, `RegisterChangeListener(g_pBackPane, this, kFramePartNotificationTag, 0)` and `UnregisterChangeListener(...)`, until the `Application`/`ChangeMan` wrapper naming is finalized. Do not expose `sub_4f4b30`/`sub_4f4b50` in C++.

Current issue: `dword_69b364` layer/global context exact name.

- Best-guess resolution: treat it as the layer/context argument to the Pane attach helper. Use a provisional source name such as `g_pMainLayer` only after cross-checking the existing layer global page during implementation.

## First-Draft C++ Readiness

The source draft is ready with these constraints:

- Emit class methods only.
- Do not handwrite thunks or scalar deleting destructor wrappers.
- Use source-facing helper names with comments or doc notes where exact owner spelling remains provisional.
- Keep global slot declarations in the slot/global page, not in this method page, unless the emitter needs an `extern` declaration.

Recommended source draft for supervisor implementation callback:

```cpp
FramePartPane::FramePartPane(int partIndex, const Rect& bounds)
    : Pane(1),
      m_partIndex(partIndex)
{
    AddToLayer(bounds, 0, 0, g_pMainLayer);
    RegisterChangeListener(g_pBackPane, this, kFramePartNotificationTag, 0);
}

FramePartPane::~FramePartPane()
{
    UnregisterChangeListener(g_pBackPane, this, kFramePartNotificationTag, 0);
    RemoveFromLayer();
}

void FramePartPane::OnNotification(const ChangeMessage& message)
{
    if (message.tag != kFramePartNotificationTag)
        return;

    g_pBlackHole->QueuePaneForDeferredDeletion(this);

    for (FramePartPane*& pane : g_framePartPanes)
        pane = nullptr;
}

int FramePartPane::OnPaintFrame()
{
    EPFTileContext tile;
    tile.Init();

    const wchar_t* resourceName = g_useEpfAssets ? L"FRMPART.EPF" : L"FRMPART.EPD";
    g_pEPFLib->LookupLayoutEntry(resourceName, m_partIndex, &tile);

    return RenderTileFrame(&tile, GetPaintBounds(), 0, 0, 0);
}
```

Implementation notes for this draft:

- `Rect`, `ChangeMessage`, `AddToLayer`, `RegisterChangeListener`, `UnregisterChangeListener`, `g_pMainLayer`, `g_pBlackHole`, `g_framePartPanes`, `RenderTileFrame`, and `GetPaintBounds` are source-facing names that must be aligned with existing support docs before insertion.
- If the local class declaration uses different virtual names, follow the class declaration and keep this behavior.
- If the source project models the slot globals as five named statics rather than an array, the notification clear should be emitted as five explicit clears. Behavior remains the same.

## Recommended Exact Doc Changes

For `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`:

1. Change metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 91
```

2. Keep:

```yaml
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00005I
EMITTER_UIDS:
  - 00005I
```

3. Replace any stale `95/95` source-gate wording with:

```text
2026-06-19 source-quality pass: Active C++ gate is satisfied by RECONSTRUCTABLE: TRUE, valid FramePartPane -> FrameChrome emitter route, and an average score above 85. Final C++ should emit only the source-authored constructor, destructor, notification handler, and paint handler; the scalar deleting destructor and adjustor thunks are compiler-generated ABI artifacts.
```

4. Add or update method inventory text:

```text
Source method inventory:
- FramePartPane::OnNotification(...): checks notification tag 'goog', queues this pane for deferred deletion through BlackHole, and clears the five FramePartPane slot globals.
- FramePartPane::OnPaintFrame(): initializes an EPFTileContext, selects FRMPART.EPF or FRMPART.EPD from g_useEpfAssets, looks up m_partIndex through g_pEPFLib, and dispatches the shared tile/frame blit callback.
- FramePartPane::FramePartPane(int partIndex, const Rect& bounds): constructs the Pane base with mode 1, stores m_partIndex at +0xf8, attaches/bounds the pane through the Pane layer helper, and registers the 'goog' listener.
- FramePartPane::~FramePartPane(): unregisters the 'goog' listener, removes the pane from its layer, and relies on the implicit Pane base destructor.
- Compiler-generated only: secondary/tertiary destructor adjustor thunks at 0x004b7590 and 0x004b759b, plus the scalar deleting destructor wrapper at 0x004b75b0.
```

5. Add helper/source-name mapping:

```text
Source-facing helper names:
- byte_66DA97 -> g_useEpfAssets.
- dword_67A744 -> g_pEPFLib / ResourceLayoutTable singleton.
- off_610F60 -> L"FRMPART.EPF"; off_610F8C -> L"FRMPART.EPD".
- sub_457A60 -> EPFTileContext init/default construction.
- sub_4D02F0 -> ResourceLayoutTable::LookupLayoutEntry.
- dword_69B3E8 -> primary tile/frame blit callback, provisional RenderTileFrame.
- sub_4F4B30/sub_4F4B50 -> register/unregister ChangeMan listener wrapper.
- sub_469180 -> BlackHole::QueuePaneForDeferredDeletion.
- sub_544460/sub_544C70/sub_544CE0/sub_544580 -> Pane constructor, attach/bounds helper, RemoveFromLayer, and base destructor cleanup.
```

6. Add open-question text:

```text
Remaining source-quality caveats: exact ChangeMan message type/field names, exact Pane paint virtual spelling, exact layer/global name for dword_69B364, exact source spelling of the five FramePartPane slots, and the unresolved live caller for BuildFramePartPanes. None blocks first-draft C++; they cap confidence below final audit.
```

7. Populate the C++ block with the source-authored draft from this report, adjusted to whatever local class declaration names the implementation callback confirms.

For `by-class/FramePartPane.md`:

```text
Add a note that UID 00015O now has first-draft C++ readiness: constructor, destructor, notification, and paint methods are source-authored; scalar deleting destructor and adjustor thunks are compiler-generated and should remain non-handwritten.
```

Recommended class score after that note:

```yaml
COMPLETION: 86
CONFIDENCE: 90
```

For `by-file/FrameChrome.md`:

```text
Add a routing note that FramePartPane method implementation should emit through the class owner into FrameChrome.cpp. BuildFramePartPanes and FramePartPaneSlotCleanup remain file-level helpers and still have their own live-caller caveats.
```

No score change required for `FrameChrome.md` from this report alone.

For `by-global/FrameChromeSlots.md` and `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`:

```text
Prefer source-facing slot-family wording such as g_framePartPanes[5] while preserving exact raw slot addresses and the builder order. Mark final individual-vs-array spelling as provisional until implementation naming is aligned.
```

No score change required from this report alone.

## Validator Needs

Report-only validation:

- No validators were run because this task created a B-agent report only and intentionally did not edit target/support by-* docs.

Implementation-callback validation needs:

1. Run the by-memory validator on `by-memory/0x004b73b0-0x004b7661.FramePartPane.md` after inserting metadata/source text.
2. Run validators for any support docs edited by the callback.
3. Run autogen validation after C++ insertion so `auto-generated/NexusTK/ui/core/FrameChrome.cpp` updates from the owner/emitter route.
4. Verify generated C++ contains source methods only and does not generate handwritten adjustor thunk/scalar-deleting-destructor wrappers.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this B-agent report. If the supervisor later requests implementation, replace the UID `00015O` row with:

```text
    - [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md) 0x004b73b0-0x004b7661 | class | FramePartPane : reconstructable : 87% : strong : Source-quality pass confirms exact notification/paint/constructor/destructor/scalar-wrapper bounds, compiler-generated adjustor thunk exclusion, FramePartPane class owner/emitter route through FrameChrome.cpp, source-facing field m_partIndex at +0xf8, g_useEpfAssets selection of FRMPART.EPF/FRMPART.EPD, EPFTileContext/ResourceLayoutTable::LookupLayoutEntry/primary tile-frame blit dependencies, goog ChangeMan registration/unregistration, BlackHole deferred deletion and five FramePartPane slot clears; first-draft C++ is ready while factory live-caller and final helper spelling cap confidence below final audit.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00015O-FramePartPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00015O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
