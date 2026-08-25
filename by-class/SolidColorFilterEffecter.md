*** UID:0000DE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SolidColorFilterEffecter : public FilterEffecter
{
public:
    SolidColorFilterEffecter(unsigned char red,
                             unsigned char green,
                             unsigned char blue,
                             float alpha);
    virtual ~SolidColorFilterEffecter();

    virtual void FillBuffer();

private:
    unsigned short m_fillColor;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SolidColorFilterEffecter

## Status

- Confidence: strong for role, method boundaries, vtable evidence, and ownership; strong that generated `g_pScreenEffecterList` is only a stale alias for shared UI layer storage.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_SolidColorFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`SolidColorFilterEffecter` is a [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass that fills its filter buffer with one converted 16-bit RGB color. It writes opacity into the inherited Pane/GrafPort alpha field at complete `+0x94` and writes inherited Pane flag state at complete `+0xf9` before concrete layer registration. These offsets are not SolidColor-private or FilterEffecter-private fields.

The class attaches pane state through the Main UI layer/context slot at `dword_69B364`, documented by [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md). The old [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) name is a stale generated alias and should be retained only for search/history.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055ae00-0x0055aec2` | constructor | IDA confirms the filter-base construction, RGB-to-16-bit conversion, opacity clamp path, and pane setup call that pushes `dword_69B364` at `0x0055ae9a`. |
| `0x0055aed0-0x0055af5e` | destructor | Tears down solid-color pane state, filter base, and screen-effect base vtable state. |
| `0x0055af60-0x0055afa4` | `FillBuffer` | Fills the effect pixel buffer with the cached 16-bit color. |
| `0x0055c000-0x0055c0bd` | scalar deleting destructor | Destructor path with delete-flag handling. |

## 2026-06-16 C001 Live Evidence Refresh

- Live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed function records for constructor `0x0055ae00-0x0055aec3`, destructor/reset body `0x0055aed0-0x0055af5f`, fill/update body `0x0055af60-0x0055afa5`, and scalar deleting destructor `0x0055c000-0x0055c0be`.
- `analyze_function 0x0055ae00` confirms the constructor calls the `FilterEffecter` base at `0x0055ad00`, installs the four `SolidColorFilterEffecter` vtable views at `0x006239ec`, `0x00623a0c`, `0x00623a58`, and `0x00623a88`, clamps/stores opacity into inherited Pane/GrafPort alpha at complete `+0x94`, converts RGB through callback/global slot `0x0069b404`, writes inherited Pane flag state at complete `+0xf9`, and registers pane state through `0x00544c70` with shared layer slot `0x0069b364`.
- `analyze_function 0x0055af60` confirms `FillBuffer` computes the rectangle width/height from offsets `+0x44/+0x4c` and `+0x48/+0x50`, then writes the cached 16-bit color at `+0x108` across the effect buffer pointer at `+0x20`.
- `xrefs_to` reconfirmed the constructor callers at `0x00504067` and `0x0050a6d4`, `FillBuffer` as a vtable-only target at `0x00623a50`, the scalar deleting destructor reached from destructor strip `0x0055ba22` and vtable slot `0x00623a04`, and three vtable-store/reset refs for each of the four SolidColor views.
- `xrefs_to 0x0069b364` still reports 35 broad UI-layer consumers. The SolidColor constructor reference at `0x0055ae9a` is only one pane-registration user, so the stale `g_pScreenEffecterList` alias remains rejected as a source-owned effecter list.
- IDA DB source-quality update applied and saved: `sub_55AE00 -> SolidColorFilterEffecter_Constructor` and `sub_55AF60 -> SolidColorFilterEffecter_FillBuffer`.
- IDA DB candidates skipped: no rename was made for `0x0069b364` because the final layer-slot source name remains unresolved in [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md); no type/member/prototype edits were applied because the `FilterEffecter` layout and callback signatures are still source-quality blockers.

## Remaining Source-Quality Blockers

- Formal C++ now emits the class declaration and cached fill-color field. Constructor and fill method bodies still need final names for the filter-buffer bounds, RGB conversion callback, and pane/layer registration helper. Do not block on invented `m_opacity`/`m_active` member names for complete `+0x94/+0xf9`: B013 resolves those as inherited Pane/GrafPort alpha and inherited Pane flag state.
- The current source placement stays [UID:0000IZ][Effects](by-file/Effects.md). No split to a standalone one-class file is supported; the exact file parent and vtable family show this class belongs with the runtime effecter cluster.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the class declaration with constructor parameters, virtual destructor, `FillBuffer()`, and cached `m_fillColor`. The accepted declaration preserves B013's correction that complete `+0x94` is inherited Pane/GrafPort alpha and complete `+0xf9` is inherited Pane flag state, not SolidColor-private opacity/active fields. Exact constructor/fill method bodies remain deferred because filter-buffer bounds, RGB conversion callback, and pane/layer registration helper names are not final-source quality, while the stale `g_pScreenEffecterList` alias remains rejected in favor of broad UI layer/context storage.

## Changes

- 2026-06-19 B013 FilterEffecter support incorporation:
  - Score unchanged at `85/88`.
  - Summary/evidence: updated subclass field wording to follow the accepted [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) layout. The constructor still clamps an opacity value and writes complete `+0x94`, but that storage is inherited Pane/GrafPort alpha. The `+0xf9` write is inherited Pane flag state. `dword_69B364` remains a [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) context slot, not a `g_pScreenEffecterList` effecter-owned list.
- 2026-06-16 C001 class-completion refresh:
  - Before: `82/86`, with method roles and stale-global-alias evidence but limited current body/vtable refresh.
  - Changed to: `85/88`; owner/emitter remain [UID:0000IZ][Effects](by-file/Effects.md), and formal output was withheld at that time. B006 2026-06-30 now emits the declaration.
  - Summary/evidence: live IDA MCP reconfirmed constructor/fill/destructor boundaries, constructor callers, four SolidColor vtable views/stores, fill-buffer loop behavior, and the broad `0x0069b364` layer-slot xref set that rejects the stale `g_pScreenEffecterList` alias. IDA DB names were updated for the constructor and fill-buffer body; the shared layer slot, field layout, and helper prototypes remain unresolved.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `86`.
- Evidence: the page documents effect role, ownership, constructor/destructor/fill/scalar-destructor ranges, base-class relationship, and stale global-alias handling; remaining completion gap is source-ready reconstruction detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the documented NexusTK-owned method anchors at `0x0055ae00`, `0x0055aed0`, `0x0055af60`, and `0x0055c000`; both this class and the parent file meet the parent gate. Formal output was withheld under the then-active final-code threshold; B006 2026-06-30 now emits the declaration while method bodies remain deferred.
