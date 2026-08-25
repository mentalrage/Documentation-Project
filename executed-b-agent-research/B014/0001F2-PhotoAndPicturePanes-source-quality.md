** TARGET-REPORT-UID:0001F2 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001F2 PhotoAndPicturePanes Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](../../../by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md) routed through [UID:0000MK][PhotoPane](../../../by-file/PhotoPane.md), raise it to `COMPLETION:87`, `CONFIDENCE:89`, and replace the stale "field/helper/close owner unresolved" blocker with resolved source-quality notes.
- Final disposition: source-bearing mixed executable cluster, but not a safe formal method-body emitter. Keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000MK`, `EMITTER_UIDS:0000MK` for now, with a Rule 28 comment-only C++ marker or blank block explicitly justified. Exact method children should carry first-draft C++ after split.
- Required action: update target/support docs with the source split, parameter names, global/helper names, `Pane::MarkForDeletion` close route, raw cleanup ownership, generated/thunk policy, and pending coverage rows below. Do not update `by-memory/-coverage-report.md` from a B-agent implementation callback.
- Confidence: high for behavior, function ranges, owner route, close helper, globals, constructor argument roles, and aggregate no-code policy; medium-high for exact original file split and final source spelling of two event-handler method names.

## Target

- Target UID: `0001F2`
- Target path: `source-3/project-documentation/by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0001F2-PhotoAndPicturePanes-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000MK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MK`.
- Primary support docs checked: `by-file/PhotoPane.md`, `by-class/PhotoPane.md`, `by-class/PictureViewPane.md`, exact children `0002R8`, `0001F3`, `0003OU`, `0003OV`, `0003OW`, the `000265` read-only aggregate, `PaneCore`, `PaneVtableData`, `MapPaneInputPacketRenderCore`, and `MapServerPacketOpcode`.

## Supervisor Active Recheck

- The corrected supervisor assignment supersedes the earlier `00016F` task. I did not create or modify a `00016F` report.
- This is a report-only B pass. I did not edit by-* docs and did not edit `by-memory/-coverage-report.md`.
- The active question is source quality and first-draft readiness for the existing mixed `PhotoPane` / `PictureViewPane` executable cluster, not a direct implementation split.

## Evidence Checked

- Existing IDA-backed documentation:
  - Target [UID:0001F2] executable aggregate.
  - [UID:0000MK] file root and [UID:0000AG]/[UID:0000AH] class roots.
  - [UID:0002R8] raw `PhotoPane` cleanup body.
  - [UID:0001F3] `PictureViewPane` close handlers and thunks.
  - [UID:0003OU]/[UID:0003OV]/[UID:0003OW] exact vtable/string data.
  - [UID:000265] read-only data aggregate.
  - [UID:0001EA] `PaneCore`, which resolves `0x00544690` as `Pane::MarkForDeletion`.
  - [UID:0001OW] `g_activeMapPane` at `0x0067a764`.
  - [UID:00029M] `MainUiLayerSlotsHead` at `0x0069b364`.
- Current-session direct binary scan:
  - Raw PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MD5 `4247E04E20B65D6414C7238AA8FF5515`.
  - SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
  - Image base `0x400000`; sections `.text`, `.rdata`, `.data`, `.rsrc`.
  - Capstone disassembly and rel32/dword pattern scans were run read-only.
- Prior B reports checked:
  - B001 executed `0001AW-mappane-packet-source-split-audit.md` records `0x005143c0-0x0051447c` as `PhotoPaneFactoryHelper`, likely PhotoPane-owned, modeled but no direct callers.
  - No prior B014/B001/B002 report for `0001F2` itself was found.
- IDA MCP availability:
  - No IDA MCP tool is exposed in this Codex session (`tool_search` returned no matching tools). Current-session "live IDA" claims below are therefore direct PE/Capstone facts, while IDA MCP facts are from current by-* docs.

## Direct PE / Capstone Facts

### Constructor and caller route

- `0x00549620` has exactly two direct rel32 call refs:
  - `0x00508bc1` inside the primary `MapPane::HandlePacket` dispatcher range.
  - `0x00514461` inside `0x005143c0-0x0051447c`, the no-direct-caller `PhotoPaneFactoryHelper` / opcode `0x5a` companion route.
- Both callers allocate `0x198` bytes before the constructor call.
- Both caller shapes parse two 16-bit fields through `0x00575730` and three byte fields through `0x00575710`, then pass:
  - arg1: first word, used by the constructor as `mapId`.
  - arg2: second word's low byte, copied into the temporary avatar descriptor.
  - arg3: second byte after the words, used as tile X and multiplied by `g_mapTilePixelWidth`.
  - arg4: third byte after the words, used as tile Y and multiplied by `g_mapTilePixelHeight`.
  - arg5: first byte after the words, forwarded to `NewHumanImageLib::CalculateBounds` / `Draw`, best named `avatarDirection`.

### Important disassembly confirmations

- `PhotoPane::PhotoPane` starts at `0x00549620`, calls `PictureViewPane::PictureViewPane` at `0x0054965d`, writes `PhotoPane` vtables at `0x0054966f`, `0x00549675`, `0x0054967f`, constructs the embedded `GrafPort` at `this+0xf8`, formats `C%04d.MAP`, opens the DAT entry, renders 17 x 15 terrain/static-object rows, draws an avatar through `g_pNewHumanImageLib`, and returns with `ret 0x14`.
- Raw `0x00549920-0x00549950` has no rel32 refs to the start and disassembles as:
  - save `esi`, treat `ecx` as `PhotoPane*`;
  - load `ecx = this + 0xf8`;
  - write the three `PhotoPane` vtables `0x00622034`, `0x00622080`, `0x006220b0`;
  - call `0x004b8d20` (`GrafPort` cleanup/destructor);
  - tail jump to `0x00549ae0`.
- `PhotoPane::OnPaint` at `0x00549950` calls `GrafPort`/surface helpers around `0x004b8e00`, `0x004b98c0`, and `0x004ba250` to blit the cached surface.
- `PictureViewPane::PictureViewPane` at `0x00549a30` calls `Pane::Pane(0)`, writes `PictureViewPane` vtables, reads `0x0067a764`, asks that pane for bounds through `0x004b8e00`, then calls shared Pane attach/order helpers with `0x0069b364`.
- `0x00549b00-0x00549b22`:
  - reads `message[4]`;
  - if the code is `3` or `6`, adjusts `ecx` by `-0xa0` and calls `0x00544690`;
  - returns `true` unconditionally.
- `0x00549b30-0x00549b4d`:
  - reads `message[4]`;
  - if the code is `8`, adjusts `ecx` by `-0xa0` and calls `0x00544690`;
  - returns `true` unconditionally.
- `0x00549b4d` and `0x00549b58` subtract `0xa0`/`0xa4` and jump to `0x00549b70`, so they are compiler-generated destructor adjustor thunks.

### Rel32 and dword scan summary

- Direct rel32 refs:
  - `0x00549620`: 2 refs, `0x00508bc1`, `0x00514461`.
  - `0x00549920`: 0 refs.
  - `0x00549950`: 0 rel32 refs; vtable only.
  - `0x005499c0`: refs from the two `PhotoPane` adjustor thunks.
  - `0x00549a30`: one ref from `PhotoPane::PhotoPane`.
  - `0x00549ae0`: raw cleanup tail jump, scalar deleting destructor call, and one constructor EH cleanup-table route.
  - `0x00549b00` / `0x00549b30`: 0 rel32 refs; vtable slots only.
  - `0x00549b70`: refs from the two `PictureViewPane` adjustor thunks.
  - `0x00544690`: 89 direct rel32 refs across broad pane/dialog code, supporting `Pane::MarkForDeletion` infrastructure ownership.
- Dword absolute hits:
  - `0x00622034`, `0x00622080`, `0x006220b0`: three immediate stores each from constructor, raw cleanup, and scalar deleting destructor.
  - `0x006220d0`, `0x0062211c`, `0x0062214c`: three immediate stores each from constructor, ordinary/non-deleting destructor, and scalar deleting destructor.
  - `0x00549b00` and `0x00549b30`: two `.rdata` vtable hits each, one in `PhotoPane` adjusted view and one in `PictureViewPane` adjusted view.
  - `0x006220b8`: one constructor immediate xref to `C%04d.MAP`.
  - `0x0067a764`: 360 absolute `.text` refs; direct support doc name is `g_activeMapPane`.
  - `0x0069b364`: 35 absolute `.text` refs; direct support doc name is `MainUiLayerSlotsHead` / main UI layer-context head.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported direction | Rejected alternatives / residual uncertainty |
| --- | --- | --- | --- |
| Photo/Picture source split | Contiguous executable island, two class RTTI/vtable families, `PhotoPane` derives through `PictureViewPane`, only confirmed `PictureViewPane` constructor caller is `PhotoPane`, `PhotoPane.cpp` source root already exists, no embedded source filename strings. | Keep `PictureViewPane` in `map/PhotoPane.cpp` or adjacent private `PictureViewPane.cpp` under the same map photo/viewer module. Best current route remains [UID:0000MK] `PhotoPane`. | A standalone generic viewer file is plausible but weaker until another derived `PictureViewPane` user appears. Bulletin ownership is rejected. |
| Constructor signature | Both call sites parse two u16 fields plus three bytes; constructor uses `[ebp+8]` as map id, `[ebp+0xc]` as low byte copied into avatar descriptor, `[ebp+0x10]/[0x14]` as tile coordinates, `[ebp+0x18]` in NewHumanImageLib calls. | Use `PhotoPane::PhotoPane(unsigned short mapId, unsigned char avatarShape, int avatarTileX, int avatarTileY, unsigned char avatarDirection)`. In packet-order notes: `mapId`, shape/body byte from second word, direction byte, tileX byte, tileY byte. | Exact original field names inside the human-image descriptor are still role-based. `avatarShape` could be `bodyShape`, `headId`, or another appearance byte; "shape/body byte" is the safest by-* wording. |
| Cached field name | Constructor constructs at `this+0xf8`, paint blits from it, raw cleanup and scalar destructor destroy it through `0x004b8d20`; support docs identify `GrafPort`. | Name as `m_snapshotPort`, `m_cachedPhotoPort`, or `m_photoGrafPort`; recommended first choice is `m_snapshotPort` because it is an off-screen render target/cache. | Do not name it generic `surface` only; the destructor callee is the `GrafPort` cleanup family. |
| Map/static/avatar dependencies | Constructor reads `g_pMapTileImageLib` (`0x0067a75c`), `g_pStaticObjImageLib` (`0x0069b448`), `g_pNewHumanImageLib` (`0x0067a760`), tile size globals `0x0066da9c/0x0066daa0`, and format `C%04d.MAP`. | Document these as dependencies, not owners. PhotoPane owns the map-photo composition. | Do not move implementation to `MapTileImageLib`, `StaticObjImageLib`, `NewHumanImageLib`, or `DATArchive`; they are service dependencies. |
| `0x005143c0` route | B001 report named it `PhotoPaneFactoryHelper`, likely PhotoPane-owned, modeled/no direct callers. Current PE confirms it parses the same payload shape and calls `PhotoPane::PhotoPane`. Existing opcode docs tie opcode `0x5a` to this allocation. | Treat as a no-direct-caller packet/factory duplicate or companion body for PhotoPane construction; it strengthens PhotoPane source placement but should not make MapPane the implementation owner. | Do not leave it as "nearby UI path" only. Do not claim direct live reachability without a caller/table route; note no direct caller evidence remains. |
| `PictureViewPane` constructor globals | Current docs for `0x0067a764` and `0x0069b364` are stronger than the target text. PE scan confirms direct reads. | Replace `dword_67A764`/`dword_69B364` prose with `g_activeMapPane` and `MainUiLayerSlots` / main UI layer-context head. | Exact original C++ variable name for `0x0069b364` remains inferred; use existing support-page name rather than old `unk_69B364`. |
| Close helper `0x00544690` | `PaneCore` resolves it as `Pane::MarkForDeletion`; direct PE scan finds broad 89-call fanout across panes/dialogs; handlers adjust from the secondary subobject to the complete object before calling it. | Close handlers call `Pane::MarkForDeletion()` on the complete `PictureViewPane`/derived pane object. This resolves the old `BulletinSession::MarkForDeletion` pollution. | No bulletin/session/article state is accessed. Do not keep `BulletinSession` or generic unresolved-owner wording. |
| Close handler method names | Vtable positions are secondary handler slots; bodies accept message byte codes and always return handled. Code `3`/`6` likely mouse/pointer close events; code `8` likely keyboard/cancel close event. | Use descriptive source names until Pane event slot names are globally standardized: `PictureViewPane::OnMouseEvent` for codes `3`/`6` and `PictureViewPane::OnKeyEvent` or `OnDismissKeyEvent` for code `8`. In memory docs, `HandleCloseMouseEvent` and `HandleCloseKeyEvent` are defensible descriptive names. | Exact original slot names need a Pane/EventHandler vtable naming pass. This does not block behavior or ownership, but it does block final method names in emitted C++ if no local naming convention is accepted. |
| Raw cleanup ownership | Raw body writes only `PhotoPane` vtables, destroys `this+0xf8`, jumps to `PhotoPane::~PhotoPane`, no direct start refs. | Direct class owner [UID:0000AG]. Treat as `PhotoPane` destructor-family / constructor-unwind cleanup support. | Do not emit as an independent source method unless a future split proves it is the ordinary destructor body. |
| Aggregate C++ policy | Target covers multiple complete methods, compiler thunks, scalar deleting wrappers, raw body, exact nested child pages, and padding. By-structure says parent aggregate C++ must not paste child range method bodies. | [UID:0001F2] should not emit formal method bodies. Keep or add a comment-only `//` marker explaining exact children own source bodies. Create/split exact method pages for first-draft C++ emission. | A one-block multi-method draft in the aggregate would duplicate current/future children and mix source-authored methods with compiler ABI glue. |

## Source-Authored Versus Compiler / Generated Split

| Range | Classification | Owner / emission recommendation |
| --- | --- | --- |
| `0x00549620-0x00549911` | Source-authored `PhotoPane` constructor | Split to exact child owned/emitted by [UID:0000AG]. First-draft C++ is plausible once helper names are accepted. |
| `0x00549911-0x00549920` | Padding | Ignored. |
| `0x00549920-0x00549950` | Raw destructor-family cleanup body | Keep direct owner [UID:0000AG]; no independent formal C++ body unless split policy models it as destructor/unwind support. |
| `0x00549950-0x005499a2` | Source-authored `PhotoPane` paint method | Split to exact child owned/emitted by [UID:0000AG]. First-draft C++ is ready at behavior level. |
| `0x005499a2-0x005499b8` | Compiler adjustor thunks | Ignored/no-code. |
| `0x005499c0-0x00549a22` | MSVC scalar deleting destructor wrapper with duplicated cleanup | Non-emitting compiler wrapper; source destructor emission belongs to the ordinary destructor/destructor-family child. |
| `0x00549a30-0x00549ad6` | Source-authored `PictureViewPane` constructor | Split to exact child owned/emitted by [UID:0000AH]. First-draft C++ plausible. |
| `0x00549ae0-0x00549aff` | Ordinary/non-deleting destructor transition to base | Source destructor support for `PhotoPane`/`PictureViewPane`; likely empty or implicit source destructor once member cleanup is represented. |
| `0x00549b00-0x00549b22` | Source-authored close-event handler | Split to exact child under [UID:0000AH]. First-draft C++ ready except exact event type name. |
| `0x00549b30-0x00549b4d` | Source-authored close/dismiss event handler | Split to exact child under [UID:0000AH]. First-draft C++ ready except exact event type name. |
| `0x00549b4d-0x00549b63` | Compiler destructor adjustor thunks | Ignored/no-code. |
| `0x00549b70-0x00549bc5` | MSVC scalar deleting destructor wrapper | Non-emitting compiler wrapper; generated from `virtual ~PictureViewPane()`. |

## First-Draft C++ Recommendation

Do not populate [UID:0001F2]'s formal C++ block with method bodies. The target meets the current combined-score/emitter gate numerically, but it is a mixed aggregate with nested exact children and compiler-generated material. Pasting all method bodies here would violate by-structure's child-range rule and later duplicate the exact method pages.

Recommended target formal C++ if the supervisor wants a Rule 28 emitter marker:

```cpp
// PhotoPane/PictureViewPane executable cluster.
// Source method bodies should be emitted from exact child by-memory pages, not this aggregate.
```

Method-level first drafts below are ready as implementation guidance for future exact children. They are not recommended for direct insertion into [UID:0001F2].

```cpp
PhotoPane::PhotoPane(unsigned short mapId,
                     unsigned char avatarShape,
                     int avatarTileX,
                     int avatarTileY,
                     unsigned char avatarDirection)
    : PictureViewPane()
{
    // Build the map filename from C%04d.MAP, open the DAT entry, render the
    // 17x15 terrain/static-object snapshot into m_snapshotPort, then draw the
    // avatar descriptor at tile coordinates using NewHumanImageLib.
}

void PhotoPane::OnPaint()
{
    // Begin paint on the pane, blit m_snapshotPort to the visible surface, end paint.
}

PictureViewPane::PictureViewPane()
    : Pane(0)
{
    RectBounds bounds;
    g_activeMapPane->GetBounds(&bounds);
    SetPaneOrder(0, g_activeMapPane);
    AddToLayer(bounds, 0, g_activeMapPane, g_mainUiLayerSlotsHead);
}

bool PictureViewPane::HandleCloseMouseEvent(PaneMessage *message)
{
    const unsigned char code = message->type;
    if (code == 3 || code == 6)
        MarkForDeletion();
    return true;
}

bool PictureViewPane::HandleCloseKeyEvent(PaneMessage *message)
{
    if (message->type == 8)
        MarkForDeletion();
    return true;
}
```

Notes on draft quality:
- `PaneMessage`, `RectBounds`, `SetPaneOrder`, `AddToLayer`, and `g_mainUiLayerSlotsHead` should be synchronized with existing Pane/EventHandler/MainUiGraph docs before formal insertion.
- The constructor body above is intentionally skeletal. A final `PhotoPane::PhotoPane` draft should be written only in an exact child page after DAT/map-buffer local names and image-library call signatures are settled.
- The two close handlers are behavior-ready; their final names can be `OnMouseEvent`/`OnKeyEvent` if Pane/EventHandler slot naming agrees.

## Recommended Target Changes

Apply these to `by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md` if the report is accepted:

1. Metadata:
   - `COMPLETION:87`
   - `CONFIDENCE:89`
   - Keep `CANONICAL_OWNER:0000MK`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000MK`
2. Replace stale C++ blocker wording:
   - Remove "Field names, helper names, and the PictureViewPane owner-close containment type are not final-source quality" as a passive blocker.
   - Add target-specific no-code proof: aggregate spans multiple source-authored methods, raw cleanup support, scalar deleting wrappers, adjustor thunks, nested child pages, and padding; exact method children must emit future source bodies.
   - Add the Rule 28 comment marker above if accepted.
3. Constructor source shape:
   - Use signature direction `PhotoPane::PhotoPane(unsigned short mapId, unsigned char avatarShape, int avatarTileX, int avatarTileY, unsigned char avatarDirection)`.
   - Record packet parse order: two u16 values then three bytes; callee truncates the second u16 to the low-byte avatar shape/body field; tile coordinates are byte payload fields promoted to ints; direction is the first byte after the words.
   - State that both `0x00508bc1` and `0x00514461` pass the same shape and allocate `0x198`.
4. Field/global names:
   - Name `this+0xf8` as `m_snapshotPort` / cached `GrafPort`.
   - Use `g_mapTilePixelWidth` (`0x0066da9c`) and `g_mapTilePixelHeight` (`0x0066daa0`).
   - Use `g_pMapTileImageLib` (`0x0067a75c`), `g_pNewHumanImageLib` (`0x0067a760`), `g_activeMapPane` (`0x0067a764`), `g_pStaticObjImageLib` (`0x0069b448`), and `MainUiLayerSlotsHead` / `g_mainUiLayerSlotsHead` (`0x0069b364`) per existing support docs.
5. Close handlers:
   - Replace unresolved owner-close wording with `Pane::MarkForDeletion` at `0x00544690`.
   - State handlers adjust from the secondary handler subobject (`this+0xa0`) back to the complete pane object, call `MarkForDeletion` only on accepted message codes, and return handled (`true`) for every message.
   - Keep the stale `BulletinSession::MarkForDeletion` label only as rejected generated-owner pollution.
6. Raw cleanup:
   - Keep [UID:0002R8] as `PhotoPane` destructor-family / constructor-unwind support.
   - Add direct PE confirmation: zero rel32 refs to raw start and only raw/scalar cleanup calls to `GrafPort` cleanup at `0x004b8d20`.
7. Route/split:
   - Keep [UID:0000MK] as current source root.
   - Add a "future exact children" note listing constructor, paint, close handlers, ordinary destructor, and compiler wrappers/thunks as split candidates.

## Recommended Support-Doc Changes

### `by-file/PhotoPane.md`

- Raise from `87/86` to `88/88` if these details are incorporated.
- Replace the "final original file split remains open" caveat with a best-supported direction:
  - Keep `PhotoPane` and `PictureViewPane` together in `NexusTK/map/PhotoPane.cpp` for current reconstruction.
  - A separate adjacent `PictureViewPane.cpp` remains possible but should not be created until another derived viewer or source filename evidence appears.
- Remove or qualify `Current recovered sources: source-3/simroot_v2/...` as generated-output lead only, not source evidence for B-agent work.
- Update function names:
  - `PhotoPane::PhotoPane(unsigned short mapId, unsigned char avatarShape, int avatarTileX, int avatarTileY, unsigned char avatarDirection)`.
  - `PictureViewPane::HandleCloseMouseEvent` / `HandleCloseKeyEvent` as descriptive names, or `OnMouseEvent` / `OnKeyEvent` if the Pane slot naming pass approves.
- Add `0x00544690` as `Pane::MarkForDeletion`, not an unresolved owner-close helper.
- Add `g_activeMapPane` and `MainUiLayerSlotsHead` names instead of `dword_67A764` / `unk_69B364`.

### `by-class/PhotoPane.md`

- Raise from `85/86` to `86/88` after adding the constructor signature, `m_snapshotPort`, caller payload order, and aggregate/child C++ policy.
- Keep formal class C++ blank unless class declarations are being assembled; method bodies belong on exact by-memory method pages.
- Replace old `95/95`/final-name wording with current code-entry policy and the aggregate-specific no-code reason.

### `by-class/PictureViewPane.md`

- Raise from `85/86` to `86/88` after resolving `0x00544690` as `Pane::MarkForDeletion`, naming `g_activeMapPane` and `MainUiLayerSlotsHead`, and clarifying handler semantics.
- Update handler rows to:
  - codes `3`/`6`: call `MarkForDeletion` and return true.
  - code `8`: call `MarkForDeletion` and return true.
- Keep final exact handler names medium-high confidence until Pane/EventHandler slot names are standardized; do not leave behavior/owner open.

### `by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md`

- No score change required (`86/91` is supported).
- Replace "embedded surface type/helper names remain generated/provisional" as a C++ blocker with the stronger source-shape policy:
  - This raw body is destructor-family support; source C++ should be represented by the `PhotoPane` destructor/member cleanup, not a separate raw helper.
  - If it remains a code emitter, add a comment-only marker rather than a method body.

### `by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md`

- Raise from `85/89` to `86/90` if the helper resolution is incorporated.
- Replace owner-close uncertainty with `Pane::MarkForDeletion`.
- Preserve mixed-range no-code policy because the page includes both handwritten handlers and compiler thunks. Best structural repair is to split:
  - `0x00549b00-0x00549b22.PictureViewPaneCloseMouseEvent.md`
  - `0x00549b30-0x00549b4d.PictureViewPaneCloseKeyEvent.md`
  - `0x00549b4d-0x00549b63.PictureViewPaneDestructorAdjustorThunks.md` as ignored/no-code.

### `by-memory/0x00622034-0x00622154.PhotoPictureReadOnlyData.md`

- No content change required for source-quality, but coverage row is stale.
- If touched, add that current B014 raw PE scan reconfirmed vtable immediate stores and direct handler slot dwords.

### `by-type/by-enum/MapServerPacketOpcode.md`

- Update opcode `0x5a` wording from `head/select dialog candidate` to `PhotoPane/map photo viewer packet` or `map photo snapshot packet`.
- Include payload shape: `uint16 mapId`, `uint16/low-byte avatarShape`, `uint8 avatarDirection`, `uint8 avatarTileX`, `uint8 avatarTileY`, allocation size `0x198`, constructor `0x00549620`.
- Note that the instantiated pane remains owned by `PhotoPane.cpp`; MapPane owns only the packet routing.

### `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`

- Strengthen the PhotoPane row:
  - Primary dispatcher call at `0x00508bc1` and helper duplicate at `0x00514461` both instantiate `PhotoPane`.
  - `0x005143c0` remains no-direct-caller/factory-helper evidence, not implementation ownership.

## Ranked Ownership Analysis

### 1. [UID:0000MK] `PhotoPane` file root - accepted

- Evidence for:
  - Constructor is directly called by map packet/UI paths and uses map DAT `C%04d.MAP`.
  - `PhotoPane` and `PictureViewPane` are contiguous and destructor-linked.
  - Exact class pages route through this file.
  - Image libraries are dependencies, not owners.
  - Existing source tree places `PhotoPane` in `NexusTK/map/`.
- Evidence against:
  - A separate `PictureViewPane.cpp` remains possible.
  - Some exact method child pages are missing.
- Decision: accepted current source root and aggregate owner/emitter.

### 2. [UID:0000AG] / [UID:0000AH] class owners - accepted for exact children

- Evidence for:
  - Vtables, constructors, destructor stores, raw cleanup, and close handlers all have direct class-level evidence.
  - Class pages meet 85/85.
- Evidence against:
  - The broad target spans both classes, so neither class is the direct owner of the entire `0001F2` aggregate.
- Decision: use direct class owners for exact future method children.

### 3. [UID:0000L3] `MapPane` / `MapPane` class - rejected as implementation owner

- Evidence for:
  - `MapPane::HandlePacket` creates `PhotoPane`.
  - Opcode docs index the `0x5a` construction route.
- Evidence against:
  - Constructor body is self-contained PhotoPane behavior and uses map/image dependencies.
  - MapPane is caller/router only.
  - B001 packet split already treats `0x005143c0` as likely PhotoPane-owned factory helper.
- Decision: MapPane docs should retain caller evidence, not own the implementation.

### 4. `BulletinSession` / bulletin dialogs - rejected

- Evidence for:
  - Old generated names polluted close-helper output.
- Evidence against:
  - Close handlers do not inspect bulletin, article, board, or session state.
  - `0x00544690` is resolved by PaneCore as `Pane::MarkForDeletion`.
  - Direct PE scan shows broad 89-call pane/dialog fanout.
- Decision: reject completely except as historical generated-owner pollution.

### 5. `NewHumanImageLib`, `StaticObjImageLib`, `MapTileImageLib`, `DATArchive` - rejected as owners

- Evidence for:
  - Constructor calls all of these.
- Evidence against:
  - They provide rendering/resource services; none owns `PhotoPane` state, vtables, constructor, paint, or close handlers.
- Decision: dependencies only.

## Open Questions With Attempted Resolution

- Exact original filename split:
  - Evidence checked: contiguous island, current file/class docs, rdata, B001 packet split, no source filename strings in existing docs.
  - Best inference: combined `PhotoPane.cpp` source root, with `PictureViewPane` as a local/base class or adjacent header declaration.
  - Score impact: prevents final-audit scoring, not owner/emitter route.
- Exact avatar descriptor field names:
  - Evidence checked: constructor argument use, NewHumanImageLib support docs, create-user/group appearance descriptor docs.
  - Best inference: second constructor parameter is shape/body appearance byte; fifth is direction; third/fourth are tile coordinates.
  - Score impact: C++ for exact constructor child should remain first-draft until shared avatar descriptor type is named.
- Exact close-handler public method names:
  - Evidence checked: secondary vtable slots, handler code, Pane/EventHandler support docs.
  - Best inference: mouse/pointer handler for codes `3`/`6`, key/dismiss handler for code `8`; both call `Pane::MarkForDeletion`.
  - Score impact: behavior and owner are resolved; final method names should stay descriptive until a broader Pane vtable naming pass.
- Live reachability of `0x005143c0`:
  - Evidence checked: B001 report and PE scan.
  - Best inference: no-direct-caller duplicate/factory helper tied to opcode `0x5a` / PhotoPane payload shape.
  - Score impact: document as no-route evidence; does not block target ownership or constructor signature.

## Exact Future Implementation Checklist

1. Update target [UID:0001F2] metadata to `87/89`, keep owner/emitter [UID:0000MK].
2. Add the PE/Capstone evidence summary and mention current-session IDA MCP was unavailable.
3. Replace stale passive blockers with resolved helper/global names and no-code aggregate proof.
4. Add constructor signature and packet-order parameter mapping.
5. Add `Pane::MarkForDeletion` close-helper resolution.
6. Update support docs listed above.
7. If implementation scope permits a structural split, create exact source-method child pages before adding method-body C++:
   - `0x00549620-0x00549911.PhotoPaneConstructor`
   - `0x00549950-0x005499a2.PhotoPaneOnPaint`
   - `0x00549a30-0x00549ad6.PictureViewPaneConstructor`
   - `0x00549b00-0x00549b22.PictureViewPaneCloseMouseEvent`
   - `0x00549b30-0x00549b4d.PictureViewPaneCloseKeyEvent`
   - ignored/no-code compiler wrappers for `0x005499a2-0x005499b8`, `0x005499c0-0x00549a22`, `0x00549b4d-0x00549b63`, and `0x00549b70-0x00549bc5`.
8. Do not edit `by-memory/-coverage-report.md`; use pending row text below.

## Exact Pending Coverage Text

Replace line 2806:

```text
    - [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md) 0x00549620-0x00549bc5 | source-cluster / migration index | PhotoAndPicturePanes : reconstructable : 87% : strong : B014 source-quality recheck keeps the cluster routed through [UID:0000MK] `map/PhotoPane.cpp`, resolves the best source split as a combined PhotoPane/PictureViewPane map-photo module, confirms constructor callers at `0x00508bc1` and `0x00514461`, names constructor roles as `mapId`, avatar shape/body byte, tile X, tile Y, and avatar direction, resolves `this+0xf8` as cached `GrafPort`/`m_snapshotPort`, resolves close handlers to `Pane::MarkForDeletion`, preserves raw `PhotoPane` cleanup ownership, and keeps formal C++ comment-only/blank because the range mixes multiple source methods, nested children, compiler thunks, scalar deleting wrappers, and padding.
```

Replace line 2808:

```text
        - [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md) 0x00549920-0x00549950 | raw-method | PhotoPaneCleanupDestructorBodyRaw : reconstructable : 86% : very strong : Non-IDA-modeled `PhotoPane` destructor-family cleanup body; writes all three `PhotoPane` vtables, destroys cached `GrafPort`/`m_snapshotPort` at `this+0xf8` via `0x004b8d20`, tail-jumps to `PhotoPane::~PhotoPane`, has no direct rel32 start refs in the B014 PE scan, and should remain no formal C++ except as destructor/unwind support.
```

Replace line 2813:

```text
        - [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md) 0x00549b00-0x00549b63 | handler/thunk cluster | PictureViewPane close handlers and thunks : reconstructable : 86% : very strong : B014 recheck confirms handler/thunk bounds, secondary vtable refs, message-code tests for `3`, `6`, and `8`, complete-object adjustment by `-0xa0`, `Pane::MarkForDeletion` helper call at `0x00544690`, unconditional handled return, compiler-generated destructor-thunk tail to `0x00549b70`, and support split recommendation for separate handler C++ children.
```

Replace line 3760 if supervisor is also refreshing directly related support coverage:

```text
    - [UID:000265][0x00622034-0x00622154.PhotoPictureReadOnlyData](by-memory/0x00622034-0x00622154.PhotoPictureReadOnlyData.md) 0x00622034-0x00622154 | mixed-rdata index | PhotoPictureReadOnlyData : non-reconstructable : 86% : very strong : Reviewed non-emitting `.rdata` aggregate with exact children for `PhotoPane` vtable data, `C%04d.MAP`, and `PictureViewPane` vtable data; exact child pages carry generated-binary/source-literal ownership, while this aggregate only records boundaries, xrefs, class routes, and the successor `PowerDialogPane` RTTI boundary at `0x00622154`.
```

## Validation Commands Needed

Run after accepted implementation edits, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001F2-PhotoAndPicturePanes-source-quality-removed.md](0001F2-PhotoAndPicturePanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact child pages are created, run validator on each new file, then rerun the target, class/file supports, and autogen.

## IDA Rename / Type / Comment Recommendations

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x00549620` | `PhotoPane::PhotoPane(unsigned short mapId, unsigned char avatarShape, int avatarTileX, int avatarTileY, unsigned char avatarDirection)` | High for roles, medium-high for `avatarShape` exact name |
| `this+0xf8` in `PhotoPane` | `m_snapshotPort` or `m_cachedPhotoPort` (`GrafPort`) | High |
| `0x00549950` | `PhotoPane::OnPaint` | High |
| `0x00549920` | comment as raw `PhotoPane` cleanup/destructor-family body, no modeled source method | Very high |
| `0x00549a30` | `PictureViewPane::PictureViewPane()` | High |
| `0x00549b00` | `PictureViewPane::HandleCloseMouseEvent` / candidate `OnMouseEvent` | Medium-high |
| `0x00549b30` | `PictureViewPane::HandleCloseKeyEvent` / candidate `OnKeyEvent` | Medium-high |
| `0x00544690` | `Pane::MarkForDeletion` | Very high from PaneCore plus broad caller scan |
| `0x0067a764` | use existing `g_activeMapPane` | Very high from support docs |
| `0x0069b364` | use existing `MainUiLayerSlotsHead` / `g_mainUiLayerSlotsHead` | High for role, medium-high for exact original spelling |
| `0x005143c0` | `PhotoPaneFactoryHelper` / no-direct-caller opcode `0x5a` companion body | Medium-high |

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0001F2-PhotoAndPicturePanes-source-quality.md`
- Modified: none
- Renamed: none
- Moved to executed: none

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001F2-PhotoAndPicturePanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001F2"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001F2-PhotoAndPicturePanes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001F2-PhotoAndPicturePanes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001F2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
