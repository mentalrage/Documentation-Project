*** UID:00007P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapNamePane

## Status

- Confidence: strong for behavior, vtable identity, construction sites, singleton lifecycle, map-name update packet handling, and map folder ownership; medium-high for final source split.
- Likely source file: [UID:0000L2][MapNamePane](by-file/MapNamePane.md), or private code in [UID:0000L3][MapPane](by-file/MapPane.md)
- Address range: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- Reconstruction staging: attached to [UID:0000L2][MapNamePane](by-file/MapNamePane.md); final C++ remains blank until source names and field layout reach the final reconstruction bar.

## Class Purpose

`MapNamePane` is a small UI pane that displays the current map name. It initializes map-name archive/font resources, draws centered map-name text, and releases those resources during pane teardown.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapNamePane` | `0x005031f0-0x005032c2` | Initializes pane state, map-name archive storage, and optional font resources. |
| `~MapNamePane` | `0x005032d0-0x0050334c` | Releases resources and clears global pane state. |
| `RenderMapName` | `0x00503350-0x0050349e` | Builds and draws centered map-name text using resource-backed or fallback rendering. |
| map-name update handler | `0x005034a0-0x00503573` | Secondary-vtable packet/update method; handles opcode `0x15`, copies the incoming map-name bytes, converts to UTF-16, ellipsizes/clamps the 128-wchar display buffer, and invalidates/redraws the pane. |
| singleton clear helper | `0x005037f0-0x005037fa` | Small cleanup helper that clears `g_pMapNamePane`; keep as compiler/helper glue rather than a user-authored virtual method. |
| adjustor thunks | `0x0050380b`, `0x00503816` | Compiler/vtable thunks; not source-level logic. |
| `ScalarDeletingDestructor` | `0x00503840-0x005038fd` | Runs destructor logic and conditionally frees storage. |

## Live IDA Evidence

Checked on 2026-06-05 with live IDA MCP/disassembly:

- `lookup_funcs` confirms `0x005031f0` size `0xd3`, `0x005032d0` size `0x7d`, `0x00503350` size `0x14f`, `0x005034a0` size `0xd4`, `0x005037f0` size `0xb`, adjustor thunks at `0x0050380b` and `0x00503816` size `0xb`, scalar deleting destructor `0x00503840` size `0xbe`, and [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) beginning at `0x00503580`.
- The constructor has direct callers at `0x004f8051` and `0x004f8695` inside the main UI initialization function. Both call the constructor and then add the resulting pane with different layout rectangles.
- Decorated RTTI/vtable names exist for `MapNamePane` at primary vtable `0x0061e5b4`, secondary vtable `0x0061e600`, and tertiary vtable `0x0061e630`. Constructor, destructor, and scalar deleting destructor store all three vtable pointers.
- Vtable slots anchor the source methods: primary slot `0x0061e5b4 -> 0x00503840`, render slot `0x0061e5f8 -> 0x00503350`, secondary thunk slot `0x0061e600 -> 0x0050380b`, and update-handler slot `0x0061e610 -> 0x005034a0`.
- `xrefs_to 0x0069b4b4` confirms the constructor writes `g_pMapNamePane`, destructor and scalar deleting destructor clear it, `0x005037f0` is a singleton-clear helper, and `0x00504a43` is an external map-path reader of the live pane/global.
- Constructor decompilation shows base pane initialization, `g_pMapNamePane` assignment, three `MapNamePane` vtable stores, map-name resource setup at `this + 0x1f8`, the display buffer cleared at `this + 0xf8`, and optional resource/font setup gated by [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`.
- Destructor and scalar deleting destructor decompilation show resource cleanup for the pointer at `+0x220`, singleton clear, base pane teardown, and conditional storage free in the deleting destructor.
- The render method draws the centered map-name buffer using the resource-backed path when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`; otherwise it uses the fallback text-render path and palette/color `143`.
- The `0x005034a0` update handler reads an event/packet object at `a2 + 12`, handles opcode `0x15`, copies the supplied byte string into a 256-byte temporary buffer, converts it to UTF-16 into the object buffer at `+0xf8`, clamps/ellipsizes it with width `173`, then requests a pane update through the base vtable.
- Internal padding around the newly confirmed methods is `0xcc`: `0x0050349f-0x005034a0`, `0x00503574-0x00503580`, `0x005037fb-0x00503800`, `0x005038fe-0x00503900`, and `0x0050395f-0x00503960`.
- The local address island is interleaved with [UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md), so source migration must stay per-method and must not migrate the older MapName-only aggregate span as a contiguous class range.
- Do not treat the adjustor thunks as separate original methods.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md)
- [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md)
- [UID:0001AK][0x005031f0-0x005038fd.MapNamePane](by-memory/0x005031f0-0x005038fd.MapNamePane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-07 A008 alias cleanup: normalized the constructor/render `byte_66DA97` resource-mode branches to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-05-28: Updated the shared memory-island reference from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the interleaved `MiniMapButtonPane` destructor ending at `0x0050395f`; the previous boundary omitted the final `retn 4` immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `76/78`. Summary: the small map-name UI pane has clear behavior, constructor/destructor/render method coverage, shared island caveat, and thunk exclusion notes, but final file split and exhaustive field/resource details remain incomplete. Evidence: linked `MapNameAndMiniMapButtonPanes` and `MapNamePane` memory pages, IDA-confirmed starts, UI setup caller, and documented interleaving with `MiniMapButtonPane`.
- 2026-06-05 live IDA rescore:
  - Changed from: `COMPLETION:76`, `CONFIDENCE:78`, reconstructable/parent unset.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000L2`.
  - Reason for score increase: live IDA MCP confirmed exact function sizes, two constructor callers, three decorated `MapNamePane` vtables, constructor/destructor/scalar-destructor vtable stores, render and update-handler vtable slots, singleton lifecycle refs, resource pointer cleanup, map-name buffer offsets, the previously omitted `0x005034a0` opcode-`0x15` update handler, the `0x005037f0` singleton-clear helper, and internal padding around the interleaved MiniMap island. The score remains below final reconstruction because source-level field names, helper names, and standalone-vs-file-local placement are still not proven.
