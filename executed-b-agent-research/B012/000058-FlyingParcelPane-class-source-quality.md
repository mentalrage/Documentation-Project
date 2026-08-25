** TARGET-REPORT-UID:000058 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000058 FlyingParcelPane Class Source-Quality Reanalysis

## Target And Scope

- Assignment: `B012 assignment` received 2026-06-19.
- Target UID/path: [UID:000058] `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\FlyingParcelPane.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\000058-FlyingParcelPane-class-source-quality.md`.
- Work mode: report-only first pass. I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.
- Allowed writes for this pass: this report and `Agent-B012/notes.md`.

## Final Recommendation

- Recommend target metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:90`
  - Keep `CANONICAL_OWNER:0000MF`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000MF`.
  - Keep `EMITTER_POSITION_OPTIONAL:` blank.
  - Keep formal `RECONSTRUCTION_CPP CODE` blank in this class page for this pass.
- Recommended source placement: [UID:0000MF] `ParcelPane` / `NexusTK/ui/panels/ParcelPane.cpp`.
- Recommended source-facing class role: implementation-private or file-local `FlyingParcelPane`, a transient parcel/letter delivery animation pane used by the parcel notification UI. Do not expose it as a public standalone UI class unless later source/header evidence proves public declaration.
- Recommended source-facing method names:
  - `FlyingParcelPane::FlyingParcelPane()`
  - source-level ordinary `virtual FlyingParcelPane::~FlyingParcelPane()` represented by raw cleanup body [UID:0002R5], with [UID:0001EN] retained as generated scalar deleting wrapper documentation only.
  - `FlyingParcelPane::StartAnimation(...)` as the preferred class-facing name for [UID:0002R6]. `StartDeliveryAnimation(...)` is an acceptable descriptive alias in prose but should not replace the shorter canonical source-facing direction without caller/source evidence.
  - `FlyingParcelPane::AnimateStep(...)` for [UID:0002KK].
  - `FlyingParcelPane::DrawParcelOrLetter(...)` for [UID:0002KL]; avoid stale `DrawParcel` if the context could hide the letter path.
- Score rationale:
  - Completion should rise from `85` to `87` because the class page can now close the stale high-score draw-helper question, generated placeholder names, ordinary destructor vs wrapper split, layer/timer/helper names, callback-offset normalization, and source-placement direction at report-level detail.
  - Confidence should rise from `86` to `90` because direct PE disassembly and pointer/edge scans match existing IDA-backed docs: exact vtable slots, raw-body boundaries, no direct raw-start edges, `Layer` construction and ScreenPane layer-list dependency, `g_pSoundManager` playback dependency, and `ParcelPane.cpp` ownership. Keep confidence below final-audit range because the exact original header/private declaration spelling and raw no-entry source-call route remain unproven.

## Evidence Checked

Documentation read or sampled:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B012/goal.md`
- `tools/leaser/Agents/Agent-B012/notes.md`
- `by-class/FlyingParcelPane.md`
- `by-file/ParcelPane.md`
- `by-class/ParcelPane.md`
- `by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`
- `by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md`
- `by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md`
- `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`
- `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`
- `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md`
- `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`
- `by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md`
- `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`
- `by-type/by-vtable/ParcelNotificationVtableFamily.md`
- `by-type/by-struct/ParcelNotificationPaneLayouts.md`
- `by-type/by-struct/PaneLayout.md`
- `by-memory/0x00556910-0x00557132.ScreenPane.md`
- `by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-memory/0x004f0480-0x004f1bf6.Layer.md`
- `by-global/g_pParcelPane.md`
- `by-global/g_pScreenPane.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`
- `by-class/SoundManager.md`
- `by-file/SoundManager.md`
- `simroot_v2/class_FlyingParcelPane.cpp`
- `simroot_v2/class_FlyingParcelPane.cpp.source_map.json`
- `simroot_v2/class_FlyingParcelPane.meta_wave3`
- Prior executed support report: `tools/leaser/Agents/Agent-B002/research/executed/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`

Local binary evidence:

- Binary used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Image base: `0x00400000`
- PE sections checked:
  - `.text` VA `0x00401000`, virtual size `0x20b4ac`, raw size `0x20b600`
  - `.rdata` VA `0x0060d000`, virtual size `0x5f0be`, raw size `0x5f200`
  - `.data` VA `0x0066d000`, virtual size `0x2fe24`, raw size `0xd800`
  - `.rsrc` VA `0x0069d000`, virtual size `0x15c38`, raw size `0x15e00`

Tools/checks:

- PowerShell `Get-Content`, `rg`, `Get-ChildItem`.
- Python direct PE parser plus Capstone 32-bit disassembly.
- Direct scan for absolute VA dwords, RVA dwords, and direct `E8`/`E9` rel32 call/jump edges to `0x00546ac0`, `0x00546b80`, `0x00546bc0`, `0x00546d70`, `0x00546df0`, `0x00546ed0`, `0x00546e8b`, `0x00546e96`, `0x00556ce0`, `0x00556d20`, and `0x0057a5c0`.
- Scoped validator baseline on target class page.

## Direct PE Reanalysis

### Constructor `0x00546ac0-0x00546b74`

Direct disassembly confirms the constructor body and the existing [UID:0002KJ] page:

- Calls base pane construction at `0x00544460` with mode/setup argument `1`.
- Installs three `FlyingParcelPane` vtable views:
  - owner `+0x00` -> `0x00621ccc`
  - owner `+0xa0` -> `0x00621d18`
  - owner `+0xa4` -> `0x00621d48`
- Clears `this+0xf8` as one dword, covering `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, and `m_leftSlot`.
- Clears byte `this+0xfc`, the parcel/letter flag.
- Allocates exactly 8 bytes through `0x004f4aa0`.
- On allocation success, calls `0x004f0480`, the `Layer` constructor/setup path, and stores the result at `this+0x100`.
- On allocation failure, stores `0` at `this+0x100`.
- Ends at `0x00546b74`; `0x00546b74-0x00546b80` is twelve `0xcc` bytes.

Reference scan result:

- `0x00546ac0`: zero absolute VA dword hits, zero RVA dword hits, zero direct rel32 call/jump hits in the scanned binary. This matches current documentation: constructor ownership is proven through vtable writes, local class family, and layout, not through an ordinary direct xref.

### Raw Cleanup Body `0x00546b80-0x00546bb5`

Direct disassembly confirms [UID:0002R5]:

```text
0x00546b80 push esi
0x00546b81 mov esi, ecx
0x00546b83 mov ecx, [esi+0x100]
0x00546b89 write primary vtable 0x00621ccc
0x00546b8f write secondary vtable 0x00621d18
0x00546b99 write tertiary vtable 0x00621d48
0x00546ba3 test owned layer pointer
0x00546ba7 push 1; call [layer_vtable+0]
0x00546bb0 tail-jump 0x00544580
```

Interpretation:

- This is the ordinary non-deleting cleanup body for source-level `FlyingParcelPane::~FlyingParcelPane()`.
- It is not merely compiler thunk glue because it deletes the owned `Layer`/screen-layer entry at `+0x100` and tail-calls Pane base cleanup.
- It is not a separate file helper because it resets all three `FlyingParcelPane` vtables and consumes object state.
- `0x00546bb5-0x00546bc0` is eleven `0xcc` bytes before the raw start/configure body.

Reference scan result:

- `0x00546b80`: zero absolute VA dword hits, zero RVA dword hits, zero direct rel32 call/jump hits.
- This negative evidence blocks a proven ordinary source entry route, but it does not weaken class ownership because the body is tightly tied to the constructor, scalar deleting destructor, and vtable family.

### Raw Start Body `0x00546bc0-0x00546d64`

Direct disassembly confirms [UID:0002R6]:

- Has a security-cookie frame and ends in `ret 0x10`, proving a `thiscall` body with four stack arguments.
- Branches at `0x00546bd0` on `byte_66DA97 == 1`, documented as [UID:0000SW] `g_useEpfAssets`.
- In the `g_useEpfAssets == 1` branch:
  - Loads [UID:00028R] `g_pSoundManager` / `dword_67A7D0`.
  - Calls `0x0057a5c0` with sound/sample id `200` (`0xc8`) and volume `100` (`0x64`), matching the source-facing dependency `SoundManager::PlaySample(g_pSoundManager, 200, 100)`.
  - Calls `0x00556ce0` with [UID:0000S7] `g_pScreenPane` and the owned `this+0x100` entry, matching `ScreenPane::SetLayerFrame`.
  - Stores four payload bytes:
    - arg1 / `bl` -> `this+0xf9`
    - arg2 / `[ebp+0x0c]` -> `this+0xfb`
    - arg3 / `[ebp+0x10]` -> `this+0xfa`
    - arg4 / `[ebp+0x14]` -> `this+0xfc`
  - Clears `this+0xf8`.
  - Builds a flag-dependent rectangle with constants in the `0x276..0x2f3` range through `0x004b7c50`.
  - Calls inherited pane virtual slots `+0x38`, `+0x30`, and `+0x20`.
  - Adds `0x1e` / 30 to inherited Pane origin field `this+0xac`.
  - Schedules the tertiary handler at `this+0xa4` via `0x005975e0` with delay `100`.
- In the `g_useEpfAssets != 1` branch:
  - Calls `ScreenPane::SetLayerFrame` through `0x00556ce0` with the same `this+0x100` entry.
  - Stores the same four payload bytes and clears `this+0xf8`.
  - Builds a smaller rectangle from arg1, falling back when arg1 is greater than `4`.
  - Calls the same inherited pane virtual slots `+0x38`, `+0x30`, and `+0x20`.
  - Schedules the tertiary handler at `this+0xa4` via `0x005975e0` with delay `10`.
- `0x00546d64-0x00546d70` is twelve `0xcc` bytes.

Best signature direction:

```cpp
void FlyingParcelPane::StartAnimation(
    unsigned char parcelCountOrState,
    unsigned char leftSlot,
    unsigned char rightSlot,
    bool isParcel);
```

The parameter order is evidence-backed by store and later consumption order. `AnimateStep` forwards `+0xf9`, `+0xfb`, and `+0xfa` to `ParcelPane::SetParcelSlotData`, while `DrawParcelOrLetter` consumes `+0xfc` as the parcel/letter branch flag.

Reference scan result:

- `0x00546bc0`: zero absolute VA dword hits, zero RVA dword hits, zero direct rel32 call/jump hits.
- This is the main remaining first-draft-code blocker for the raw method: source-level behavior is well understood, but the original caller route/name is not proven.

### Animate Step `0x00546d70-0x00546dee`

Direct disassembly confirms [UID:0002KK]:

- Primary dispatch route is the `FlyingParcelPane` tertiary vtable slot at `0x00621d4c -> 0x00546d70`.
- Callback `ecx` is the embedded timer-handler view, so `this == owner + 0xa4`.
- Normalized owner offsets:
  - callback `+0x54` -> owner `+0xf8` / `m_animationFrame`
  - callback `+0x55` -> owner `+0xf9` / `m_parcelCountOrState`
  - callback `+0x56` -> owner `+0xfa` / `m_rightSlot`
  - callback `+0x57` -> owner `+0xfb` / `m_leftSlot`
  - callback `+0x5c` -> owner `+0x100` / `m_animationLayer`
  - callback `+0x08` -> owner `+0xac` / inherited Pane origin coordinate, not a `FlyingParcelPane` payload field
- Active branch when frame `< 0x1e` / 30:
  - decrements inherited origin coordinate at owner `+0xac`
  - invalidates owner bounds through primary vtable slot `+0x20`
  - increments `m_animationFrame`
  - reschedules through `0x005975e0` with event `0`, delay `10`, payloads `0,0`
  - returns true (`al = 1`) and `ret 0x0c`
- Completion branch when frame `>= 0x1e` / 30:
  - calls owner primary vtable slot `+0x38`
  - removes the `+0x100` layer through `g_pScreenPane` and `0x00556d20`, best source-facing `ScreenPane::RemoveLayer`
  - calls `ParcelPane::SetParcelSlotData(g_pParcelPane, m_parcelCountOrState, m_leftSlot, m_rightSlot)`
  - sets `g_pParcelPane + 0xfb` to `1`, the right-slot action-enable byte documented by ParcelPane layout
  - invalidates the ParcelPane bounds at `+0x44` through its primary vtable slot `+0x20`
  - returns true (`al = 1`) and `ret 0x0c`

Reference scan result:

- `0x00546d70`: one absolute VA dword hit at `0x00621d4c`, zero RVA dword hits, zero direct rel32 call/jump hits.

### Draw Helper `0x00546df0-0x00546e6b`

Direct disassembly confirms [UID:0002KL]:

- Primary dispatch route is the `FlyingParcelPane` primary vtable draw slot at `0x00621d10 -> 0x00546df0`.
- Calls `0x00457a60` to initialize a local `EPFTileContext`-style record.
- Reads `this+0xfc`:
  - nonzero -> `ALERTBTN.EPF`, frame `5`, palette `ALERTBTN.PAL`
  - zero -> `LETTER.EPF`, frame `0`, palette `LETTER.PAL`
- Loads [UID:0000QU] `g_pEPFLib` / `dword_67A744` for `0x004d02f0`, the resource layout lookup helper.
- Uses inherited Pane bounds at `this+0x44` as the destination rectangle.
- Calls `0x004b9980`, a shared surface/render helper, and returns its result.
- `0x00546e6b-0x00546e70` is five `0xcc` bytes before the singleton-clear helper.

Reference scan result:

- `0x00546df0`: one absolute VA dword hit at `0x00621d10`, zero RVA dword hits, zero direct rel32 call/jump hits.

This closes the target page's stale "exact high-score DrawParcel page remains open" wording. The exact draw child is currently `88/91`; the remaining issue is final render-helper declaration spelling, not target-class ownership or behavior.

### Compiler Cleanup And Destructor Wrapper Area

Direct disassembly confirms:

- `0x00546e70-0x00546e7b`: constructor/EH singleton clear for `g_pParcelIconPane`; non-emitting.
- `0x00546e80-0x00546e8b`: constructor/EH singleton clear for `g_pParcelPane`; non-emitting.
- `0x00546e8b-0x00546ea1`: two `FlyingParcelPane` destructor adjustor thunks:
  - `0x00546e8b`: subtracts `0xa0`, jumps to `0x00546ed0`
  - `0x00546e96`: subtracts `0xa4`, jumps to `0x00546ed0`
- `0x00546ed0-0x00546f37`: MSVC scalar deleting destructor wrapper:
  - restores all three `FlyingParcelPane` vtable views
  - deletes the owned `+0x100` `Layer`/screen-layer entry with flag `1`
  - calls Pane base cleanup at `0x00544580`
  - if `(flags & 1) != 0` and `(flags & 4) == 0`, calls operator delete `0x004f4ac0`
  - if `(flags & 1) != 0` and `(flags & 4) != 0`, calls sized/vector-style delete path `0x0041b6a0` with size `0x104`
  - returns `this`
  - final `ret 4` bytes are at `0x00546f34-0x00546f36`; `0x00546f37-0x00546f40` is nine `0xcc` bytes.

Reference scan result:

- `0x00546ed0`: one absolute VA dword hit at `0x00621ccc`, zero RVA dword hits, direct rel32 jump hits at `0x00546e91` and `0x00546e9c`.
- `0x00546e8b`: one absolute VA dword hit at `0x00621d18`.
- `0x00546e96`: one absolute VA dword hit at `0x00621d48`.

Source decision:

- Source should declare/define an ordinary virtual destructor. Do not hand-author a `ScalarDeletingDestructor` method in class C++.
- [UID:0001EN] should stay formal-C++ blank and documented as compiler-generated wrapper behavior.

### ScreenPane Layer Helpers

Direct PE disassembly of `0x00556ce0-0x00556d41` confirms the source-facing helper direction:

- `0x00556ce0-0x00556d1b`: root screen layer setter/attachment/update helper.
  - Uses `ScreenPane +0x10c` layer list.
  - If the second argument is nonzero, calls `0x00559360` to find an existing layer entry index.
  - Calls the layer-list vtable slot `+0x14` with insertion/update arguments.
  - Direct rel32 callers include `0x00546c04` and `0x00546cb5` in `FlyingParcelPane::StartAnimation`.
  - Best source-facing name: `ScreenPane::SetLayerFrame` or `ScreenPane::SetLayerEntryFrame`. Existing docs use `ScreenPane::SetLayerFrame`; keep that until ScreenPane final naming.
- `0x00556d20-0x00556d41`: root screen layer removal helper.
  - Calls `0x00559360` to find layer index.
  - Uses `ScreenPane +0x10c` layer list vtable slot `+0x1c` to remove.
  - Direct rel32 caller includes `0x00546db3` in `FlyingParcelPane::AnimateStep`.
  - Best source-facing name: `ScreenPane::RemoveLayer`.

This supports `m_animationLayer` / `m_screenLayerEntry` for `FlyingParcelPane +0x100`, not `RenderBuffer`, `SpriteFrame`, or `ObjectPane`.

## Vtable And Base Layout

`FlyingParcelPane` derives from the common `Pane` layout. The base occupies `+0x00..+0xf7`; derived fields start at `+0xf8`.

Vtable views:

| Owner offset | Vtable base | Evidence and role |
| --- | --- | --- |
| `+0x00` | `0x00621ccc` | Primary `Pane` view. Slot `+0x00` points to `0x00546ed0` scalar deleting destructor wrapper; slot `+0x44` points to `0x00546df0` draw helper. |
| `+0xa0` | `0x00621d18` | Secondary event-handler view. Slot `+0x00` points to adjustor thunk `0x00546e8b`, which subtracts `0xa0` and jumps to wrapper `0x00546ed0`. |
| `+0xa4` | `0x00621d48` | Tertiary timer-handler view. Slot `+0x00` points to adjustor thunk `0x00546e96`; slot `+0x04` points to `0x00546d70` `AnimateStep`. |

Do not read the tertiary table past `0x00621d4c`. The dword at `0x00621d50` begins the `ALERTBTN.EPF` UTF-16 resource string, not another virtual.

Callback normalization:

- Secondary event callbacks receive `this == owner + 0xa0`.
- Tertiary timer callbacks receive `this == owner + 0xa4`.
- Destructor adjustor thunks explicitly subtract `0xa0` and `0xa4`.
- `AnimateStep` must be documented with owner-normalized offsets; its raw decompiler offsets are not direct class offsets.

Inherited fields relevant to this class:

| Offset | Inherited owner | Class use |
| --- | --- | --- |
| `+0x44` | `Pane` bounds/local rectangle | Draw destination and invalidation rectangle. |
| `+0xa4` | `Pane` timer-handler subobject | Timer callback scheduling and vtable dispatch. |
| `+0xa8` | `Pane` cached attached `Layer*` | Not the same as `FlyingParcelPane +0x100`. |
| `+0xac` | `Pane` origin point | Current asset branch adds `30`; animation step decrements one coordinate. Do not name this as derived payload. |

Derived fields:

| Offset | Recommended field/type | Evidence |
| --- | --- | --- |
| `+0xf8` | `unsigned char m_animationFrame` | Constructor clears; start body clears; `AnimateStep` compares to `30` and increments. |
| `+0xf9` | `unsigned char m_parcelCountOrState` | Start arg1; forwarded to `ParcelPane::SetParcelSlotData` as first payload byte. |
| `+0xfa` | `unsigned char m_rightSlot` | Start arg3; forwarded to ParcelPane as right-slot value. |
| `+0xfb` | `unsigned char m_leftSlot` | Start arg2; forwarded to ParcelPane as left-slot value. |
| `+0xfc` | `bool`/`unsigned char m_isParcel` | Start arg4; `DrawParcelOrLetter` selects `ALERTBTN` when nonzero and `LETTER` when zero. |
| `+0x100` | `Layer *m_animationLayer` / `m_screenLayerEntry` | Constructor allocates 8 bytes and calls `Layer::Layer`; start attaches through ScreenPane layer helper; animate removes through ScreenPane; cleanup/destructor deletes through helper vtable. |

Rejected derived field names:

- `m_targetObjectId`, `m_itemType`, `m_itemSubType`, `m_itemId`, `m_parentPane`, `m_altitude`, and `m_animBounds` from active generated code: rejected because they do not match the actual offsets or later handoff semantics.
- `RenderBuffer*`, `SpriteFrame*`, `ObjectPane*`, or `AssetManager` for `+0x100`: rejected because constructor, helper size, ScreenPane callers, and deletion behavior point to the existing `Layer`/screen-layer entry family.
- `m_isFlying` for `+0xfc`: rejected because the flag selects parcel art versus letter art, not general flying state.
- Class-owned field name for `+0xac`: rejected because [UID:0001VH] `PaneLayout` documents it as inherited pane origin point.

## Source Placement And Class Exposure

Best-supported source placement is [UID:0000MF] `ParcelPane` / `NexusTK/ui/panels/ParcelPane.cpp`.

Positive evidence:

- The `ParcelIconPane`, `ParcelPane`, and `FlyingParcelPane` executable island is contiguous at `0x00545e40-0x005470ad`.
- The next function at `0x005470b0` is [UID:0000MH] `PatchPane`; do not merge patch code into the parcel source family.
- Vtable/data island `0x00621bb0-0x00621d50` is exactly the three parcel-notification classes.
- Resource strings `ALERTBTN.EPF`, `ALERTBTN.PAL`, `LETTER.EPF`, and `LETTER.PAL` tie `ParcelPane` draw and `FlyingParcelPane` draw together.
- `FlyingParcelPane::AnimateStep` completes by calling `ParcelPane::SetParcelSlotData` through [UID:0000RY] `g_pParcelPane`.
- File page [UID:0000MF] already owns the parcel globals and the three class pages.
- Direct PE scan finds no independent public entry edge to the `FlyingParcelPane` constructor or raw start body, making public header/API exposure weaker than implementation-private helper exposure.

Recommended class exposure:

- Treat `FlyingParcelPane` as an implementation-private helper class in the `ParcelPane.cpp` translation unit, or as a private helper declaration included only by the parcel notification source family.
- Do not force it into a public `ParcelPane.h` API in this pass. The binary has RTTI/vtables for the class name, but no recovered source/header route proves public exposure.
- Preserve the separate class page because RTTI/vtables and method bodies prove a real C++ class, not a free helper struct.

Rejected source placements:

- `ScreenPane.cpp`: rejected because ScreenPane is only the layer-list service dependency for `+0x100`.
- `Layer.cpp`: rejected because `Layer` is only the helper object type constructed and stored by the class.
- `TimerMgr.cpp`: rejected because `0x005975e0` is a generic scheduler wrapper, not owner logic.
- `SoundManager.cpp`: rejected because `0x0057a5c0` is only a sample-playback dependency in one branch.
- `PatchPane.cpp`: rejected by the exact `0x005470b0` successor boundary and lack of shared behavior.
- Standalone `FlyingParcelPane.cpp`: weaker than `ParcelPane.cpp` because the class is small, parcel-specific, physically interleaved with the parcel notification family, and has no external direct entry refs.

## Heuristic / Inference Reanalysis And Validation

### Compiler / Generated Names

- `ScalarDeletingDestructor`: keep only as binary-wrapper terminology for [UID:0001EN]. Source should be ordinary `virtual ~FlyingParcelPane()`.
  - Evidence: primary vtable slot, secondary/tertiary adjustor thunks, deleting flags, optional storage free, and duplicate cleanup sequence.
  - Rejected: hand-authored `FlyingParcelPane::ScalarDeletingDestructor(unsigned int)`.
- `DrawParcel`: replace or qualify as `DrawParcelOrLetter`.
  - Evidence: exact draw child uses `+0xfc` to choose `ALERTBTN` or `LETTER`.
  - Rejected: parcel-only draw name.
- `StartDeliveryAnimation`: acceptable descriptive alias, but use `StartAnimation` as the preferred source-facing method name until caller/source evidence proves original spelling.
  - Evidence: no caller edge to raw start, existing child filename, and four-argument payload role.
- Active generated names `RenderBuffer`, `SpriteFrame`, `AssetManager`, `RemoveFromObjectList`, `DeliverParcel`, and `ObjectPane::~ObjectPane`: reject as generated-source pollution.
  - Evidence: direct callee set is `Layer::Layer`, ScreenPane layer helpers, EPF resource lookup, shared render helper, Pane base cleanup, and `ParcelPane::SetParcelSlotData`.

### Unclear Types, Helpers, And Globals

- `+0x100` type:
  - Best direction: `Layer *m_animationLayer` / `m_screenLayerEntry`.
  - Evidence checked: constructor allocates 8 bytes and calls `Layer::Layer`; start passes the pointer to `ScreenPane::SetLayerFrame`; animate passes it to `ScreenPane::RemoveLayer`; cleanup/destructor invoke its deleting vtable slot; [UID:00018W] documents the broader `Layer` class and constructor callers include this site.
  - Limit: exact source class name may be `Layer`, `LayerEntry`, or a screen-layer wrapper typedef. The target page should carry both `m_animationLayer` and `m_screenLayerEntry` until the Layer type pass finalizes declaration spelling.
- `0x00556ce0`:
  - Best direction: `ScreenPane::SetLayerFrame`.
  - Evidence checked: root screen layer list at `ScreenPane +0x10c`, layer index lookup via `0x00559360`, direct caller set from startup/map/flying parcel setup, and list vtable slot `+0x14`.
  - Limit: exact verb may be `SetLayer`, `AddLayer`, or `SetLayerFrame`; keep documented current name `SetLayerFrame`.
- `0x00556d20`:
  - Best direction: `ScreenPane::RemoveLayer`.
  - Evidence checked: root screen layer list at `ScreenPane +0x10c`, index lookup via `0x00559360`, direct caller `0x00546db3`, and list vtable slot `+0x1c`.
- `0x005975e0`:
  - Best direction: `TimerHandler::ScheduleTimer` candidate.
  - Evidence checked: wrapper forwards through `g_pTimerMgr` to `0x00597910`, broad caller fan-in, and `ret 0x10`.
  - Limit: final wrapper name/source split remains TimerMgr-wide, not FlyingParcelPane-local.
- `byte_66DA97`:
  - Best direction: [UID:0000SW] `g_useEpfAssets`, process-wide current EPF/layout asset selector.
  - Evidence checked: one-byte global, broad UI/render xrefs, StartupWindow write, existing global page.
  - Rejected: parcel-local animation mode flag.
- `dword_67A7CC`:
  - Best direction: [UID:0000S7] `g_pScreenPane`.
  - Evidence checked: ScreenPane singleton lifecycle and layer-list helper use.
- `dword_67A7D0`:
  - Best direction: [UID:00028R] `g_pSoundManager`.
  - Evidence checked: SoundManager singleton page, direct read in start body, `0x0057a5c0` SoundManager sample playback body.
- `dword_69BA28`:
  - Best direction: [UID:0000RY] `g_pParcelPane`.
  - Evidence checked: `AnimateStep` reads it twice, calls `ParcelPane::SetParcelSlotData`, sets `+0xfb`, invalidates bounds, and global page lifecycle refs match parcel owner.

### Ownership / Source Placement Issues

- Best owner: [UID:000058] class, emitted through [UID:0000MF] file.
  - Evidence: constructor/destructor vtable stores, vtable-data slots, exact class layout, method family adjacency, resource strings, parcel singleton interaction, and file page source grouping.
- Best source path: `NexusTK/ui/panels/ParcelPane.cpp`.
  - Evidence: direct by-file parent, proposed-source-tree placement, current file score `88/88`, and aggregate source island.
- Helper class exposure:
  - Best high-probability direction: implementation-private helper class, likely declared in `ParcelPane.cpp` or a private parcel-notification companion declaration.
  - Evidence checked: no ordinary PE direct edge to constructor/start, no separate source-file island, no global singleton for `FlyingParcelPane`, and no external/public method evidence beyond virtual dispatch.
  - Why not fully final: RTTI/vtables prove a named class but cannot distinguish a `ParcelPane.cpp` local class definition from a private header included by that file.

### Reachability / Caller Questions

- Constructor `0x00546ac0`: no direct absolute/RVA/rel32 pointer edge found. This is expected for class construction paths not modeled as ordinary function calls in the current database, but it blocks public factory/caller claims.
- Raw cleanup `0x00546b80`: no direct absolute/RVA/rel32 pointer edge found. Its destructor role is inferred from vtable resets, layer deletion, and Pane base tail-call.
- Raw start `0x00546bc0`: no direct absolute/RVA/rel32 pointer edge found. Its method role is inferred from `ret 0x10`, payload writes, layer attach, timer schedule, and consumption by `AnimateStep`/draw.
- `AnimateStep` `0x00546d70`: vtable data edge at `0x00621d4c`, no ordinary direct code caller. This is correct for virtual timer dispatch.
- `DrawParcelOrLetter` `0x00546df0`: vtable data edge at `0x00621d10`, no ordinary direct code caller. This is correct for primary draw virtual dispatch.
- Scalar wrapper `0x00546ed0`: primary vtable data edge plus two adjustor-thunk jumps; compiler-generated route proven.

### Split / Range Decisions

- Keep `0x00546ac0-0x00546b74` as the constructor, followed by `0x00546b74-0x00546b80` padding.
- Keep `0x00546b80-0x00546bb5` as raw ordinary destructor cleanup body, followed by `0x00546bb5-0x00546bc0` padding.
- Keep `0x00546bc0-0x00546d64` as raw start/configure method, followed by `0x00546d64-0x00546d70` padding.
- Keep `0x00546d70-0x00546dee` as `AnimateStep`, followed by `0x00546dee-0x00546df0` padding.
- Keep `0x00546df0-0x00546e6b` as `DrawParcelOrLetter`, followed by `0x00546e6b-0x00546e70` padding.
- Keep `0x00546e70-0x00546e8b` singleton-clear cleanup funclets as non-emitting support, not `FlyingParcelPane` methods.
- Keep `0x00546e8b-0x00546ea1` as `FlyingParcelPane` adjustor thunks inside [UID:0001EM], non-reconstructable/compiler glue.
- Keep `0x00546ed0-0x00546f37` as scalar deleting destructor wrapper, followed by `0x00546f37-0x00546f40` padding.
- Keep the parcel aggregate ending at `0x005470ad`; do not merge `PatchPane` at `0x005470b0`.

### Open-Question Closure

- Original source spelling of `StartAnimation`: no safe proof. Best report-level action is to use `StartAnimation` as the primary source-facing name, preserve `StartDeliveryAnimation` as descriptive alias, and document the negative direct-edge evidence. This is not generic future work; it is the exact reason no formal C++ should be emitted from the class page yet.
- Exact helper type name for `+0x100`: no safe final spelling beyond `Layer`/screen-layer entry. The highest-probability direction is `Layer *m_animationLayer`; exact node/list internals belong to [UID:00018W] `Layer`, not this class.
- Public vs private class declaration: no safe proof of a public header route. Highest-probability direction is implementation-private helper class in `ParcelPane.cpp`; do not leave as an open placeholder.
- `+0xac` field name: resolved away from FlyingParcelPane. [UID:0001VH] `PaneLayout` documents it as inherited pane origin point. Do not create a derived field.
- Formal first-draft C++: defer with target-specific proof below. This is not because behavior is unknown; it is because class-level C++ would currently overclaim declaration visibility and raw-entry methods.

## First-Draft C++ Recommendation / No-Code Proof

Do not emit formal C++ in [UID:000058] `by-class/FlyingParcelPane.md` in this pass.

Exact no-code/defer proof:

- The target is a class page. Its formal C++ would have to define declaration visibility, member signatures, destructor placement, and method bodies across several child pages.
- The class is reconstructable and has a valid emitter route, but source declaration exposure is still only high-probability private/file-local, not proven by a recovered source/header route.
- The constructor has no direct absolute VA, RVA, or rel32 edge in the local PE scan.
- The raw ordinary destructor body `0x00546b80` has no IDA function object and no direct absolute VA, RVA, or rel32 edge.
- The raw start body `0x00546bc0` has no IDA function object and no direct absolute VA, RVA, or rel32 edge.
- The scalar deleting destructor `0x00546ed0` is compiler ABI output and must not be hand-authored as source.
- `AnimateStep` and `DrawParcelOrLetter` are exact virtual methods, but their final source declarations still depend on the shared timer-handler signature, inherited Pane virtual declarations, render helper declarations, and `Layer`/screen-layer entry type spelling.
- Active generated `class_FlyingParcelPane.cpp` is demonstrably stale: it omits `0x00546b80` and `0x00546bc0`, uses rejected names/types (`RenderBuffer`, `SpriteFrame`, `ObjectPane`, `AssetManager`), and emits scalar deleting wrapper source that should be compiler generated.

Source-facing sketch for future implementation guidance only, not for the target formal block now:

```cpp
// Likely implementation-private helper in ParcelPane.cpp.
class FlyingParcelPane : public Pane {
public:
    FlyingParcelPane();
    virtual ~FlyingParcelPane();

    void StartAnimation(
        unsigned char parcelCountOrState,
        unsigned char leftSlot,
        unsigned char rightSlot,
        bool isParcel);

private:
    bool AnimateStep(int eventId, int value1, int value2);
    int DrawParcelOrLetter();

    unsigned char m_animationFrame;       // +0xf8
    unsigned char m_parcelCountOrState;   // +0xf9
    unsigned char m_rightSlot;            // +0xfa
    unsigned char m_leftSlot;             // +0xfb
    unsigned char m_isParcel;             // +0xfc
    Layer *m_animationLayer;              // +0x100, exact typedef/name still shared with Layer/ScreenPane docs
};
```

The sketch is intentionally not a formal reconstruction because it would still overclaim visibility, exact callback signature, return type, and `Layer` alias spelling.

## Target Implementation Checklist

For later supervisor/implementation callback, update only after acceptance:

1. `by-class/FlyingParcelPane.md`
   - Set `COMPLETION:87`, `CONFIDENCE:90`.
   - Keep `CANONICAL_OWNER:0000MF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MF`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
   - Replace stale "exact high-score DrawParcel page remains open" wording. [UID:0002KL] is exact and strong; the remaining issue is final render-helper declaration spelling.
   - Add a 2026-06-19 B012 class source-quality section with:
     - implementation-private / file-local `ParcelPane.cpp` helper direction
     - ordinary destructor body vs scalar deleting wrapper policy
     - raw cleanup/start no-entry/no-pointer-route evidence
     - field table `+0xf8..+0x100`
     - inherited `+0xac` origin usage
     - vtable slots and callback normalization
     - `AnimateStep` completion handoff to `g_pParcelPane`
     - `DrawParcelOrLetter` resource branch
     - formal C++ no-code proof
   - Preferred names to record: `StartAnimation`, `DrawParcelOrLetter`, `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, `m_animationLayer` / `m_screenLayerEntry`.

2. `by-file/ParcelPane.md`
   - Update the [UID:000058] row/migration notes to say private/helper class exposure is now high-probability implementation-private in `ParcelPane.cpp`, not a generic open blocker.
   - Keep final header spelling caveat. Do not invent a public `ParcelPane.h` exposure.
   - Note that active `class_FlyingParcelPane.cpp` is stale and that the eventual emitter route is `NexusTK/ui/panels/ParcelPane.cpp`.

3. `by-type/by-struct/ParcelNotificationPaneLayouts.md`
   - Already carries the core field table. Add only a short sync if needed:
     - `+0x100` is `Layer *m_animationLayer` / `m_screenLayerEntry`, not `RenderBuffer`.
     - `+0xac` remains inherited Pane origin and should not be listed as derived FlyingParcelPane state.

4. `by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md`
   - Existing B002-applied content is mostly current. Add a class-level cross-link only if needed:
     - ordinary source destructor body for `FlyingParcelPane::~FlyingParcelPane()`
     - formal C++ remains blank until destructor/source route is coordinated
     - no direct PE edge to raw start

5. `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`
   - Existing B002-applied content is mostly current. Add PE-scan specifics if not already present:
     - no VA/RVA/rel32 edge to raw start
     - `StartAnimation` primary name, `StartDeliveryAnimation` descriptive alias
     - `+0xac` is inherited Pane origin point, not a derived field

6. `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`
   - Preserve callback offset normalization from `this == owner +0xa4`.
   - Ensure `+0xac` wording is inherited Pane origin coordinate and `+0x100` removal is `ScreenPane::RemoveLayer`.
   - No score change required.

7. `by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md`
   - No structural change required. It already closes the draw branch strongly.
   - If updating target wording, cross-link this as the exact draw child and use `DrawParcelOrLetter`.

8. `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md`
   - Preserve wrapper/no-formal-C++ policy.
   - Do not emit source-level `ScalarDeletingDestructor`.

9. `by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md`
   - No target-driven change required. Existing non-reconstructable compiler-thunk classification is correct.

10. `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md` and `by-type/by-vtable/ParcelNotificationVtableFamily.md`
    - No structural change required. Optional wording can note that `0x00621d10` and `0x00621d4c` close the class draw/timer dispatch route, and `0x00621d50` remains string data.

11. Generated docs / output
    - Do not edit `simroot_v2/class_FlyingParcelPane.cpp`; it is generated/stale evidence.
    - Do not manually edit `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` from this class report.
    - If formal C++ is later accepted through child pages, generated output should appear through [UID:0000MF] `ParcelPane.cpp`, not a standalone `class_FlyingParcelPane.cpp` route.

12. `by-memory/-coverage-report.md`
    - Do not edit directly as B012. Supervisor-owned row text is below.

## Exact Supervisor-Owned Coverage Row Text

Target coverage row for `by-class/-coverage-report.md`:

```markdown
- [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md) : reconstructable : 87% : strong : B012 2026-06-19 class source-quality reanalysis confirms `FlyingParcelPane` as the implementation-private ParcelPane.cpp transient parcel/letter animation helper under [UID:0000MF], keeps owner/emitter [UID:0000MF], closes stale draw-helper and helper-name caveats with exact `DrawParcelOrLetter`, `AnimateStep`, ordinary-destructor-body, and scalar-deleting-wrapper roles, resolves the derived payload fields as `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, and `Layer`/screen-layer `m_animationLayer` at `+0x100`, records secondary/tertiary callback offset normalization and inherited Pane origin use at `+0xac`, rejects active generated `RenderBuffer`/`SpriteFrame`/`AssetManager`/`ObjectPane` names, and keeps formal C++ blank because local PE evidence still shows no modeled function or direct VA/RVA/rel32 route to the raw cleanup/start bodies and the exact private class declaration/signature shape remains inferred rather than proven.
```

No B012 edit to `by-memory/-coverage-report.md` was made. The target is a `by-class` page, so the exact target coverage row belongs to `by-class/-coverage-report.md`. Existing supervisor-owned by-memory rows for the raw child pages should be left to their prior accepted B002 implementation unless a later callback asks for a consolidated memory-row sync.

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000058-FlyingParcelPane-class-source-quality-removed.md](000058-FlyingParcelPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Target ok line: `ok           000058 by-class/FlyingParcelPane.md UID header exists`
- Dry-run note: `stats_incremental_skip 000058 project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows`

Recommended scoped validators after accepted implementation, only for changed by-* files:

> Executable block R002 was removed from this report and preserved verbatim in [000058-FlyingParcelPane-class-source-quality-removed.md](000058-FlyingParcelPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the support validators for files actually changed. Do not validate or edit `by-memory/-coverage-report.md` unless the supervisor explicitly applies coverage.

## Report-Only Change Record

- Created this report file.
- Planned `Agent-B012/notes.md` update to record this completion.
- Did not edit any `by-*` documentation page.
- Did not edit `by-memory/-coverage-report.md`.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000058-FlyingParcelPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"000058"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000058-FlyingParcelPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/000058-FlyingParcelPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000058"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
