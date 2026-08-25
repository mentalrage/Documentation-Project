*** UID:00009W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class OverlayEffecter : public PixelEffecter, public Pane
{
public:
    OverlayEffecter(unsigned char paneMode,
                    unsigned short overlayX,
                    unsigned short overlayY);
    virtual ~OverlayEffecter();

protected:
    unsigned short m_overlayX;
    unsigned short m_overlayY;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Pane-backed base class for overlay screen effects: constructs the inherited Pane view, registers it against the active MapPane bounds inset by map-tile dimensions, stores two overlay placement words, and relies on compiler-generated destructor wrappers/thunks for the Pane/GrafPort views. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# OverlayEffecter

## Status

- Confidence: strong for class identity, Effects ownership, constructor/destructor boundaries, four-view inherited Pane/GrafPort layout, current helper/global names, and compiler-generated deleting-destructor policy; medium-high for exact original field/parameter spelling and final `Effects.cpp` versus private-header/subfolder split.
- Proposed source: [UID:0000IZ][Effects](by-file/Effects.md), emitted under `NexusTK/render/Effects.cpp`.
- Legacy generated-source alias, for searching only: `class_OverlayEffecter.cpp`.
- Current modeled function ranges: constructor `0x0055a2e0-0x0055a3ca`, ordinary destructor `0x0055a560-0x0055a5d5`, and scalar deleting destructor wrapper `0x0055bbf0-0x0055bc8d` (exclusive endpoints).
- Runtime aggregate: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Vtable/layout anchor: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md).
- Generated/source mismatch resolved in favor of this source page: the generated tracker row was stale at `76/82`, while the source page had already reached `86/88` before this B003 pass. Normal validators should refresh generated state from this source page; do not repair generated tracker or manual coverage rows by hand.

## Reconstruction C++ Policy

The target clears the current code-entry gate because it is `RECONSTRUCTABLE:TRUE`, has nonblank emitter route [UID:0000IZ][Effects](by-file/Effects.md), and now scores above the active `(COMPLETION + CONFIDENCE) / 2 > 85` threshold. Older `95/95` or "below final-source gate" wording is stale for code-entry purposes.

This class page should emit only the class declaration shown in the formal `RECONSTRUCTION_CPP CODE` block. Do not add constructor/destructor method bodies here: the method bodies live inside the broad runtime cluster and can be modeled by exact by-memory method pages if those are created later. The scalar deleting destructor and adjusted thunks are MSVC ABI output from the ordinary virtual destructor declaration, not handwritten source methods.

## Responsibility

`OverlayEffecter` is the pane-backed base class for runtime image overlays. The best source-facing class shape is `OverlayEffecter : public PixelEffecter, public Pane`, matching the primary `PixelEffecter` vtable store, inherited Pane construction at complete-object offset `+0x04`, four installed vtable views, and the adjusted Pane/GrafPort thunks. Treating the Pane as a private data member is rejected because the `+0x04`, `+0xa4`, and `+0xa8` views are inherited/adjusted view slots rather than plain fields.

The constructor builds the inherited Pane view, asks the active map pane for the current map rectangle, insets that rectangle by the map-tile pixel globals, stores two 16-bit overlay placement words, then registers the inherited Pane with a Main UI layer slot. The class itself owns the overlay-base setup; [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) are dependencies, not owners.

The subclasses specialize how overlay images are resolved, updated, and rendered:

- [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md): static overlay image/name lookup.
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md): indexed frame overlay.
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md): overlay image drawn at a fixed point.
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md): scrolling/repeating overlay image; B001's 2026-06-20 source-quality pass resolves its adjusted Pane/GrafPort paint slot as `OverlayMovingImageEffecter::OnPaint()` at `0x0055a990`, matching the same adjusted paint-slot source pattern accepted for WaterFilterEffecter.

## Methods And ABI Bodies

| Address | Source-facing role | Notes |
| --- | --- | --- |
| `0x0055a2e0-0x0055a3ca` | `OverlayEffecter::OverlayEffecter(unsigned char paneMode, unsigned short overlayX, unsigned short overlayY)` | Constructs the `PixelEffecter`/Pane-backed overlay base, installs four OverlayEffecter views, queries active MapPane bounds, applies tile-dimension insets, stores two overlay placement words, and registers the Pane view with the Main UI layer slot. |
| `0x0055a560-0x0055a5d5` | `OverlayEffecter::~OverlayEffecter()` | Restores the four OverlayEffecter views during teardown, removes/unregisters the inherited Pane view, calls `Pane::~Pane()`, then resets the primary view to `ScreenEffecter`. |
| `0x0055bbf0-0x0055bc8d` | MSVC scalar deleting destructor wrapper | Compiler-generated wrapper for `virtual ~OverlayEffecter()`: repeats the base teardown and calls `OperatorDeleteWrapper` only when delete flags permit it. Do not emit a handwritten source method with this name. |
| `0x0055ba40`, `0x0055ba48`, `0x0055ba53` | adjusted scalar-deleting-destructor thunks | Compiler-generated thunks for the inherited Pane/GrafPort views: subtract `0x04`, `0xa4`, or `0xa8` from `ecx`, then jump to `0x0055bbf0`. |

## Constructor Data Flow

B003 current IDA MCP session `80de0a67` confirms the constructor at `0x0055a2e0` has size `0xea` / 234 bytes (verified by MCP `int_convert` / `int_convert.py`) and ends at exclusive address `0x0055a3ca`.

Direct constructor facts from MCP lookup/decompile/disasm:

- The constructor first stores the `PixelEffecter` primary vtable at the complete object start, then calls `Pane::Pane(this + 0x04, paneMode)` through helper `0x00544460`.
- It installs four `OverlayEffecter` vtable views: primary `0x006235e8` at offset `+0x00`, view `0x0062360c` at `+0x04`, view `0x00623658` at `+0xa4`, and view `0x00623688` at `+0xa8`.
- It allocates a 16-byte rectangle object with `operator new(0x10)`.
- It reads [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) from `0x0067a764` / `dword_67A764`, calls that object's virtual slot `+0x28` to fill the rectangle, then insets left/right by [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) at `0x0066da9c` and top/bottom by `g_mapTilePixelHeight` at `0x0066daa0`.
- It stores the two 16-bit constructor words at complete offsets `+0xfc` and `+0xfe` (`0xfc` = 252, `0xfe` = 254, verified by MCP `int_convert` / `int_convert.py`). The best class-page field names are `m_overlayX` and `m_overlayY`, but exact original spelling remains unresolved.
- It calls the Pane layer-registration helper at `0x00544c70` on `this + 0x04`, passing the rectangle, `g_activeMapPane`, zero, and the broader Main UI layer slot/global at `0x0069b364`.
- The SEH and security-cookie frame in this range is compiler scaffolding. Do not translate it into source-level class logic.

The constructor has direct code callers at `0x0055a4d3`, `0x0055a651`, `0x0055a803`, and `0x0055ab32`, matching the constructors for the static-image, frame-image, point-image, and moving overlay subclasses. Those callers pass a fixed Pane mode byte plus two 16-bit placement/dimension arguments, supporting the class declaration's `paneMode`, `overlayX`, and `overlayY` names as high-confidence inferred names rather than original symbol proof.

## Destructor And Delete-Flag Policy

B003 current IDA MCP session `80de0a67` confirms the ordinary destructor at `0x0055a560` has size `0x75` / 117 bytes and ends at exclusive address `0x0055a5d5`; the scalar deleting destructor wrapper at `0x0055bbf0` has size `0x9d` / 157 bytes and ends at exclusive address `0x0055bc8d` (sizes verified by MCP `int_convert` / `int_convert.py`).

Ordinary destructor facts:

- `0x0055a560` restores primary `0x006235e8` and the inherited/adjusted views `0x0062360c`, `0x00623658`, and `0x00623688`.
- It calls `0x00544ce0` on `this + 0x04`, best documented as Pane layer cleanup/removal / `Pane::RemoveFromLayer`.
- It calls `Pane::~Pane()` at `0x00544580` on `this + 0x04`.
- It resets the primary view to the `ScreenEffecter` vtable at `0x006235a4`.
- Current `xrefs_to` found no direct code xrefs to this ordinary destructor. Its source identity is still supported by vtable/destructor-wrapper/cleanup evidence, but the lack of a direct callsite remains a confidence cap.

Scalar deleting destructor facts:

- `0x0055bbf0` performs the same OverlayEffecter/Paneside teardown as the ordinary destructor.
- It calls `OperatorDeleteWrapper` at `0x004f4ac0` only when `(flags & 1)` is set and `(flags & 4)` is clear.
- The flag-4 path calls guard/runtime glue with object size `0x100`; this is compiler/runtime support and should not become source-level class logic.
- `callees` in session `80de0a67` show `0x0055bbf0` adds only `OperatorDeleteWrapper` and guard/runtime support beyond the Pane cleanup/destructor helpers.

## Vtable And Adjusted-View Layout

B003 current MCP `get_int` evidence reads the OverlayEffecter vtable groups as:

| View | Object offset | Key slots / route |
| --- | ---: | --- |
| Primary `0x006235e8` | `+0x00` | Primary scalar deleting destructor slot `0x00623600 -> 0x0055bbf0`; surrounding slots include shared boolean/default/no-op targets and inherited helpers. |
| View `0x0062360c` | `+0x04` | First entry `0x0062360c -> 0x0055ba40`; disassembly proves `sub ecx, 0x04; jmp 0x0055bbf0`. |
| View `0x00623658` | `+0xa4` | First entry `0x00623658 -> 0x0055ba48`; disassembly proves `sub ecx, 0xa4; jmp 0x0055bbf0`. |
| View `0x00623688` | `+0xa8` | First entry `0x00623688 -> 0x0055ba53`; disassembly proves `sub ecx, 0xa8; jmp 0x0055bbf0`. |

`xrefs_to` in session `80de0a67` ties the scalar wrapper to vtable data ref `0x00623600` and to the three adjusted thunk jump sites in the destructor thunk island. `lookup_funcs` confirms the surrounding slot targets are short default stubs, no-op slots, inherited helper slots, and the scalar deleting destructor wrapper.

## Helper And Global Naming Decisions

Use the following source-facing names in this page and related support docs:

| IDA/raw label | Source-facing interpretation |
| --- | --- |
| `sub_544460` | `Pane::Pane` |
| `sub_544c70` | Pane layer-registration helper; source-facing `Pane::AddToLayer` unless the broader Pane pass chooses a more exact public name. |
| `sub_544ce0` | Pane layer cleanup/removal helper; source-facing `Pane::RemoveFromLayer`/cleanup with exact final spelling deferred to Pane docs. |
| `sub_544580` | `Pane::~Pane` |
| `sub_4f4ac0` | `OperatorDeleteWrapper` |
| `dword_67a764` | [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) |
| `word_66da9c` | [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) |
| `word_66daa0` | [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) |
| `unk_69b364` / `dword_69B364` | [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) dependency; do not preserve stale `g_pScreenEffecterList` as a final Effects-owned global. |

Current helper decompilation evidence in session `80de0a67` supports these names: `0x00544460` initializes Pane/GrafPort/event/timer state and stores the Pane mode byte; `0x00544c70` attaches the Pane to a layer/list using the supplied slot; `0x00544ce0` unregisters/removes layer state; and `0x00544580` restores Pane vtables, unregisters, frees subobjects, and runs GrafPort cleanup.

## Source Ownership And Rejected Alternatives

`OverlayEffecter` remains canonically owned and emitted by [UID:0000IZ][Effects](by-file/Effects.md). It is part of the ScreenEffecter/PixelEffecter overlay effect family and is consumed by the derived overlay classes in that family.

Rejected alternatives and corrected stale assumptions:

- Reject MapPane ownership. `OverlayEffecter` consumes `g_activeMapPane` for bounds, but MapPane owns the active-map singleton and map/layout services, not this effect class.
- Reject MainUiLayerSlots ownership. `dword_69B364` is a Main UI layer/context slot consumed by effecter Pane registration, not an Effects-owned screen-effecter list.
- Reject Pane/GrafPort ownership. The class inherits/constructs a Pane view, but the semantic class family is Effects.
- Reject the vtable data page and runtime cluster as direct class owners. They are evidence/aggregate pages; the source route is the Effects file page.
- Reject one-class generated source placement as final source evidence. `class_OverlayEffecter.cpp` is a recovered-output/staging alias only.
- Reject preserving raw placeholders where support names exist. Raw labels such as `sub_544460`, `sub_544580`, `dword_67a764`, `word_66da9c`, and `word_66daa0` should appear only as evidence aliases.
- Reject handwritten source logic for security-cookie, SEH cleanup, scalar deleting destructor flags, and adjusted thunk subtraction. Those are compiler ABI/frame-protection artifacts emitted from the class declaration and ordinary virtual destructor.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Current MCP evidence resolves class identity, Effects ownership/emitter route, constructor flow, Pane base helper names, active MapPane/tile/global dependencies, destructor flow, delete-flag behavior, four-view vtable layout, adjusted thunks, and declaration-level C++ readiness. It remains below final audit because exact original field/parameter spelling and source split/header placement are still inferred. |
| Confidence | 91 | Session `80de0a67` directly confirms boundaries, bytes, decompilation, disassembly, xrefs, callees, vtable dwords, thunk routes, helper behavior, and converted layout constants. Confidence remains below final-audit level because original names are not symbol-proven, Pane helper public spelling is owned by support docs, and the ordinary destructor lacks direct code xrefs in the current query. |

## Residual Caveats

- `m_overlayX` and `m_overlayY` are high-confidence descriptive names for complete offsets `+0xfc` and `+0xfe`, not original symbol-proof. Sibling reports leave `paneWidth`/`paneHeight`, `overlayWidth`/`overlayHeight`, or `originX`/`originY` as spelling variants.
- The first constructor byte is best described as a Pane mode/type argument; exact original parameter name is not proven.
- The layer slot/global at `0x0069b364` has support-level naming through [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md); final per-slot public name remains open.
- The exact original file split between `Effects.cpp`, a private header, or a `render/effects/` subfolder remains open. Current ownership/emission stays with [UID:0000IZ][Effects](by-file/Effects.md).
- The final public names/signatures for Pane layer helpers belong to Pane/support docs. This page uses `Pane::AddToLayer` and `Pane::RemoveFromLayer` as source-facing interpretations with that caveat.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md)
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md)
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md)
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000OC][Surface](by-file/Surface.md)

## Changes

- 2026-06-25 B003 OverlayEffecter source-quality implementation:
  - Changed metadata from `86/88` to `90/91`; owner/emitter/reconstructable fields remain [UID:0000IZ][Effects](by-file/Effects.md), `RECONSTRUCTABLE:TRUE`, and blank optional emitter position.
  - Added declaration-level formal C++ for `class OverlayEffecter : public PixelEffecter, public Pane`; constructor/destructor bodies stay out of this class page because exact method bodies belong to method/range pages and the deleting destructor/thunks are compiler-generated.
  - Replaced stale generated/source mismatch and old blank-C++ gate wording. The source page is authoritative over the stale generated `76/82` tracker row, and the active code-entry gate is clear for declaration-level C++.
  - Incorporated current MCP session `80de0a67` evidence for constructor/destructor boundaries, function sizes, bytes/prologues, decompile/disasm, xrefs/callees, vtable dwords, adjusted thunks, Pane helper identities, and `int_convert` layout constants.
  - Documented constructor data flow: `Pane::Pane(this + 0x04, paneMode)`, four vtable stores, active MapPane rectangle query through `g_activeMapPane`, map-tile insets via `g_mapTilePixelWidth`/`g_mapTilePixelHeight`, word stores at `+0xfc/+0xfe`, and Pane layer registration through `MainUiLayerSlots`.
  - Documented ordinary destructor and scalar deleting destructor policy: Pane cleanup/removal, `Pane::~Pane`, primary reset to `ScreenEffecter`, optional `OperatorDeleteWrapper` only for `(flags & 1) && !(flags & 4)`, and flag-4 runtime glue as non-source.
  - Added vtable/thunk details: primary `0x006235e8`, views `0x0062360c`, `0x00623658`, `0x00623688`, primary slot `0x00623600 -> 0x0055bbf0`, and adjusted thunks subtracting `0x04`, `0xa4`, and `0xa8`.
- 2026-06-20 B001 OverlayMovingImageEffecter support sync:
  - Score unchanged.
  - Summary/evidence: added the moving-overlay subclass paint-slot note. [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) now treats `0x0055a990` as `OnPaint()` because the method is installed through the adjusted `+0x04` Pane/GrafPort view slot, matching the source pattern used by other pane-backed effecters.
- Before: completion/confidence metadata were `0/0` even though the page already documented base-class responsibility, subclass relationships, method ranges, and render-layer construction behavior.
- Changed to: `COMPLETION:70` and `CONFIDENCE:76`.
- Evidence: constructor/destructor/deleting-destructor roles and the overlay subclass family are documented; completion stays moderate because exact field layout, detailed render-layer data flow, caller inventory, and original file split remain incomplete.
- 2026-06-03 parent attachment pass:
  - What existed before: the page had strong role/subclass evidence but remained unattached and below the parent-attachment confidence gate.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime effecter aggregate, vtable-family doc, and subclass pages all support `render/Effects.cpp` ownership. C++ remains blank because exact fields, final source split, and final method names remain below the then-current reconstruction gate.
- 2026-06-13 A002 Goal 2 refresh:
  - Before: `COMPLETION:76`, `CONFIDENCE:82`; constructor behavior was summarized, but the page still used stale parcel/render-layer wording and did not carry direct current IDA evidence for all three methods.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent remains [UID:0000IZ][Effects](by-file/Effects.md), and reconstruction C++ remained blank under the old final-source gate.
  - Summary/evidence: live IDA MCP confirmed modeled function sizes and exclusive endpoints, constructor vtable stores, active MapPane/tile-dimension/layer-slot data flow, four subclass constructor callers, destructor pane teardown, scalar-delete flag behavior, and vtable/jump-strip references. Remaining gaps were final field names, final method names for the pane helpers, exact source header split, and complete caller/creator reconstruction above the subclass constructors.
